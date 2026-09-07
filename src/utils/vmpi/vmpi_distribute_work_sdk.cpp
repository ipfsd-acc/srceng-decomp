// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi_distribute_work_sdk.cpp
// Functions: 89
// ============================================================

#include "utils\vmpi\vmpi_distribute_work_sdk.h"

//------------------------------------------------------------------------------
// Address: 0x1002F9B0
// Name: public: CShuffledWorkUnitWalker::CShuffledWorkUnitWalker(void)
// Source: json
//------------------------------------------------------------------------------
CShuffledWorkUnitWalker *__thiscall CShuffledWorkUnitWalker::CShuffledWorkUnitWalker(CShuffledWorkUnitWalker *this)
{
  this->m_CompletedWUBits.m_Memory.m_pMemory = nullptr;
  this->m_CompletedWUBits.m_Memory.m_nAllocationCount = 0;
  this->m_CompletedWUBits.m_Memory.m_nGrowSize = 0;
  this->m_CompletedWUBits.m_Size = 0;
  this->m_CompletedWUBits.m_pElements = nullptr;
  this->m_WorkUnitsRemaining.m_Memory.m_pMemory = nullptr;
  this->m_WorkUnitsRemaining.m_Memory.m_nAllocationCount = 0;
  this->m_WorkUnitsRemaining.m_Memory.m_nGrowSize = 0;
  this->m_WorkUnitsRemaining.m_LastAlloc.index = -1;
  this->m_WorkUnitsRemaining.m_Head = -1;
  this->m_WorkUnitsRemaining.m_Tail = -1;
  this->m_WorkUnitsRemaining.m_FirstFree = -1;
  this->m_WorkUnitsRemaining.m_pElements = this->m_WorkUnitsRemaining.m_Memory.m_pMemory;
  this->m_WorkUnitsRemaining.m_ElementCount = 0;
  this->m_WorkUnitsRemaining.m_NumAlloced = 0;
  this->m_WorkUnitsMap.m_Memory.m_pMemory = nullptr;
  this->m_WorkUnitsMap.m_Memory.m_nAllocationCount = 0;
  this->m_WorkUnitsMap.m_Memory.m_nGrowSize = 0;
  this->m_WorkUnitsMap.m_Size = 0;
  this->m_WorkUnitsMap.m_pElements = nullptr;
  this->m_LocalCompletedWUBits.m_Memory.m_pMemory = nullptr;
  this->m_LocalCompletedWUBits.m_Memory.m_nAllocationCount = 0;
  this->m_LocalCompletedWUBits.m_Memory.m_nGrowSize = 0;
  this->m_LocalCompletedWUBits.m_Size = 0;
  this->m_LocalCompletedWUBits.m_pElements = nullptr;
  this->m_Walker.m_WorkerInfos.m_Memory.m_pMemory = nullptr;
  this->m_Walker.m_WorkerInfos.m_Memory.m_nAllocationCount = 0;
  this->m_Walker.m_WorkerInfos.m_Memory.m_nGrowSize = 0;
  this->m_Walker.m_WorkerInfos.m_Size = 0;
  this->m_Walker.m_WorkerInfos.m_pElements = nullptr;
  this->m_Walker.m_nWorkUnits = 0;
  CCriticalSection::CCriticalSection(this: &this->m_CS);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002FA60
// Name: public: CShuffledWorkUnitWalker::~CShuffledWorkUnitWalker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShuffledWorkUnitWalker::~CShuffledWorkUnitWalker(CShuffledWorkUnitWalker *this)
{
  CCriticalSection::~CCriticalSection(this: &this->m_CS);
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_Walker.m_WorkerInfos);
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_LocalCompletedWUBits);
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_WorkUnitsMap);
  CUtlLinkedList<unsigned __int64,unsigned __int64,0,unsigned __int64,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>>::RemoveAll(this: &this->m_WorkUnitsRemaining);
  if ( this->m_WorkUnitsRemaining.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_WorkUnitsRemaining.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WorkUnitsRemaining.m_Memory.m_pMemory);
      this->m_WorkUnitsRemaining.m_Memory.m_pMemory = nullptr;
    }
    this->m_WorkUnitsRemaining.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>((CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1002FAD0
// Name: public: void CDSInfo::ReadWUIndex(unsigned __int64 __near *,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDSInfo::ReadWUIndex(CDSInfo *this, unsigned __int8 *pWU, MessageBuffer *pBuf)
{
  if ( HIDWORD(this->m_nWorkUnits) != 0 )
  {
    MessageBuffer::read(this: pBuf, p: pWU, bytes: 8u);
  }
  else if ( LODWORD(this->m_nWorkUnits) > 0xFFFF )
  {
    MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&pBuf, bytes: 4u);
    *(_QWORD *)pWU = (unsigned int)pBuf;
  }
  else
  {
    MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&pBuf, bytes: 2u);
    *(_QWORD *)pWU = (unsigned __int16)pBuf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FB50
// Name: public: virtual void CDistributor_SDKWorker::RequestShuffle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKWorker::RequestShuffle(CDistributor_SDKWorker *this)
{
  int Name; // eax
  MessageBuffer mb; // [esp+0h] [ebp-10h] BYREF

  MessageBuffer::MessageBuffer(this: &mb);
  PrepareDistributeWorkHeader(pBuf: &mb, cSubpacketID: 0x33u);
  Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  VMPI_SendData(pData: mb.data, nBytes: Name, iDest: 0, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x1002FC30
// Name: public: virtual void CDistributor_SDKWorker::NoteLocalWorkUnitCompleted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKWorker::NoteLocalWorkUnitCompleted(CDistributor_SDKWorker *this, unsigned __int64 iWU)
{
  unsigned __int8 *v3; // eax
  CCriticalSectionLock v4; // [esp+4h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &v4, pCS: &this->m_WorkUnitWalker.m_CS);
  CCriticalSectionLock::Lock(this: &v4);
  v3 = &this->m_WorkUnitWalker.m_LocalCompletedWUBits.m_Memory.m_pMemory[iWU >> 3];
  *v3 |= 1 << (iWU & 7);
  CCriticalSectionLock::~CCriticalSectionLock(this: &v4);
}

//------------------------------------------------------------------------------
// Address: 0x1002FD20
// Name: public: bool CWorkUnitWalker::GetNextWorkUnit(int,unsigned __int64 __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWorkUnitWalker::GetNextWorkUnit(
        CWorkUnitWalker *this,
        int iWorker,
        unsigned __int64 *pWUIndex,
        bool *bWorkerFinishedHisColumn)
{
  CWorkUnitWalker::CWorkerInfo *v5; // edi
  unsigned int m_iWorkUnitOffset_high; // eax
  unsigned int m_iWorkUnitOffset; // ecx
  unsigned __int64 v8; // rax
  bool v9; // cf

  if ( iWorker < 0 )
    return 0;
  if ( iWorker >= this->m_WorkerInfos.m_Size )
    return 0;
  v5 = &this->m_WorkerInfos.m_Memory.m_pMemory[iWorker];
  m_iWorkUnitOffset_high = HIDWORD(v5->m_iWorkUnitOffset);
  m_iWorkUnitOffset = v5->m_iWorkUnitOffset;
  if ( __PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) >= this->m_nWorkUnits )
    return 0;
  if ( __PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) < this->m_MatrixWidth )
  {
    *bWorkerFinishedHisColumn = false;
  }
  else
  {
    v8 = (__PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) / this->m_MatrixWidth + 1) * this->m_MatrixWidth
       - __PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) % this->m_MatrixWidth
       - 1;
    m_iWorkUnitOffset = v8;
    m_iWorkUnitOffset_high = HIDWORD(v8);
    *bWorkerFinishedHisColumn = true;
  }
  *pWUIndex = (__PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) + v5->m_iStartWorkUnit) % this->m_nWorkUnits;
  v9 = __CFADD__(LODWORD(v5->m_iWorkUnitOffset)++, 1);
  HIDWORD(v5->m_iWorkUnitOffset) += v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002FDF0
// Name: public: bool CShuffledWorkUnitWalker::Thread_GetNextWorkUnit(int,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShuffledWorkUnitWalker::Thread_GetNextWorkUnit(
        CShuffledWorkUnitWalker *this,
        int iWorker,
        unsigned __int64 *pWUIndex)
{
  unsigned __int64 *m_pMemory; // eax
  int v5; // ecx
  int v6; // edx
  unsigned __int8 v7; // al
  int v8; // ecx
  unsigned __int64 v9; // rt0
  unsigned __int64 iUnmappedWorkUnit; // [esp+Ch] [ebp-14h] BYREF
  CCriticalSectionLock csLock; // [esp+14h] [ebp-Ch] BYREF
  bool bWorkerFinishedHisColumn; // [esp+1Fh] [ebp-1h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  if ( CWorkUnitWalker::GetNextWorkUnit(
         this: &this->m_Walker,
         iWorker,
         pWUIndex: &iUnmappedWorkUnit,
         &bWorkerFinishedHisColumn) != 0 )
  {
    while ( 1 )
    {
      if ( bWorkerFinishedHisColumn
        && this->m_iLastShuffleRequest != this->m_iCurShuffle
        && _Plat_FloatTime() - this->m_flLastShuffleTime > 2.0 )
      {
        this->m_pShuffleRequester->RequestShuffle(this: this->m_pShuffleRequester);
        this->m_iLastShuffleRequest = this->m_iCurShuffle;
      }
      m_pMemory = this->m_WorkUnitsMap.m_Memory.m_pMemory;
      v5 = iUnmappedWorkUnit;
      v6 = m_pMemory[iUnmappedWorkUnit];
      *(_DWORD *)pWUIndex = v6;
      *((_DWORD *)pWUIndex + 1) = HIDWORD(m_pMemory[v5]);
      v7 = 1 << (v6 & 7);
      LODWORD(v9) = v6;
      HIDWORD(v9) = *((_DWORD *)pWUIndex + 1);
      v8 = v9 >> 3;
      if ( (v7 & this->m_CompletedWUBits.m_Memory.m_pMemory[v8]) == 0
        && (v7 & this->m_LocalCompletedWUBits.m_Memory.m_pMemory[v8]) == 0 )
      {
        break;
      }
      if ( CWorkUnitWalker::GetNextWorkUnit(
             this: &this->m_Walker,
             iWorker,
             pWUIndex: &iUnmappedWorkUnit,
             &bWorkerFinishedHisColumn) == 0 )
        goto LABEL_9;
    }
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 1;
  }
  else
  {
LABEL_9:
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FF00
// Name: public: virtual bool CDistributor_SDKWorker::GetNextWorkUnit(unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_SDKWorker::GetNextWorkUnit(CDistributor_SDKWorker *this, unsigned __int64 *pWUIndex)
{
  int m_iMyWorkUnitWalkerID; // eax

  m_iMyWorkUnitWalkerID = this->m_iMyWorkUnitWalkerID;
  if ( m_iMyWorkUnitWalkerID == -1 )
    return 0;
  else
    return CShuffledWorkUnitWalker::Thread_GetNextWorkUnit(
             this: &this->m_WorkUnitWalker,
             iWorker: m_iMyWorkUnitWalkerID,
             pWUIndex);
}

//------------------------------------------------------------------------------
// Address: 0x100300D0
// Name: public: unsigned long CShuffledWorkUnitWalker::GetShuffleCRC(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CShuffledWorkUnitWalker::GetShuffleCRC(CShuffledWorkUnitWalker *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<unsigned __int64,unsigned __int64> *m_pMemory; // eax
  int v4; // esi
  int i; // esi
  unsigned int v6; // esi
  CCriticalSectionLock csLock; // [esp+4h] [ebp-14h] BYREF
  unsigned __int64 iWorkUnit; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int ret; // [esp+14h] [ebp-4h] BYREF

  if ( (`CShuffledWorkUnitWalker::GetShuffleCRC'::`2'::`local static guard' & 1) == 0 )
  {
    `CShuffledWorkUnitWalker::GetShuffleCRC'::`2'::`local static guard' |= 1u;
    `CShuffledWorkUnitWalker::GetShuffleCRC'::`2'::bCalcShuffleCRC = VMPI_IsParamUsed(eParam: mpi_CalcShuffleCRC);
  }
  if ( !`CShuffledWorkUnitWalker::GetShuffleCRC'::`2'::bCalcShuffleCRC )
    return 0;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  CRC32_Init(pulCRC: &ret);
  m_Head = this->m_WorkUnitsRemaining.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_WorkUnitsRemaining.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      iWorkUnit = m_pMemory[v4].m_Element;
      CRC32_ProcessBuffer(pulCRC: &ret, pBuffer: &iWorkUnit, nBuffer: 8);
      m_pMemory = this->m_WorkUnitsRemaining.m_Memory.m_pMemory;
      m_Head = m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  for ( i = 0; i < this->m_WorkUnitsMap.m_Size; ++i )
  {
    iWorkUnit = this->m_WorkUnitsMap.m_Memory.m_pMemory[i];
    CRC32_ProcessBuffer(pulCRC: &ret, pBuffer: &iWorkUnit, nBuffer: 8);
  }
  CRC32_Final(pulCRC: &ret);
  v6 = ret;
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100302F0
// Name: public: void CWorkUnitWalker::Init(unsigned __int64,unsigned __int64,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkUnitWalker::Init(
        CWorkUnitWalker *this,
        unsigned __int64 matrixWidth,
        unsigned __int64 matrixHeight,
        unsigned __int64 nWorkUnits)
{
  int v5; // esi
  __int64 v6; // rax
  CWorkUnitWalker::CWorkerInfo *m_pMemory; // eax
  int v8; // [esp+28h] [ebp+1Ch]

  this->m_nWorkUnits = nWorkUnits;
  this->m_MatrixWidth = matrixWidth;
  v5 = 0;
  this->m_MatrixHeight = matrixHeight;
  this->m_WorkerInfos.m_Size = 0;
  if ( SLODWORD(this->m_MatrixHeight) > 0 )
    CUtlVector<CWorkUnitWalker::CWorkerInfo,CUtlMemory<CWorkUnitWalker::CWorkerInfo,int>>::InsertMultipleBefore(
      this: &this->m_WorkerInfos,
      elem: 0,
      num: this->m_MatrixHeight);
  v8 = 0;
  if ( HIDWORD(this->m_MatrixHeight) != 0 || LODWORD(this->m_MatrixHeight) != 0 )
  {
    v6 = 0;
    do
    {
      this->m_WorkerInfos.m_Memory.m_pMemory[v5].m_iStartWorkUnit = v6 * matrixWidth;
      m_pMemory = this->m_WorkerInfos.m_Memory.m_pMemory;
      LODWORD(m_pMemory[v5].m_iWorkUnitOffset) = 0;
      HIDWORD(m_pMemory[v5].m_iWorkUnitOffset) = 0;
      v6 = ++v8;
      ++v5;
    }
    while ( v8 < this->m_MatrixHeight );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100303A0
// Name: public: void CShuffledWorkUnitWalker::Shuffle(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShuffledWorkUnitWalker::Shuffle(CShuffledWorkUnitWalker *this, int nWorkers)
{
  CShuffledWorkUnitWalker *v2; // edi
  int m_ElementCount; // eax
  int m_Head; // esi
  UtlLinkedListElem_t<unsigned __int64,unsigned __int64> *m_pMemory; // edi
  int v6; // esi
  int v7; // ecx
  unsigned __int64 *v8; // eax
  unsigned int v9; // kr00_4
  int m_Element; // edx
  unsigned __int64 m_ElementCount_low; // [esp-14h] [ebp-48h]
  CCriticalSectionLock csLock; // [esp+10h] [ebp-24h] BYREF
  unsigned __int64 matrixHeight; // [esp+18h] [ebp-1Ch]
  unsigned __int64 iWorkUnit; // [esp+20h] [ebp-14h]
  unsigned __int64 matrixWidth; // [esp+28h] [ebp-Ch]
  CShuffledWorkUnitWalker *v16; // [esp+30h] [ebp-4h]

  v2 = this;
  v16 = this;
  if ( nWorkers != 0 )
  {
    ++this->m_iCurShuffle;
    this->m_flLastShuffleTime = _Plat_FloatTime();
    CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &v2->m_CS);
    CCriticalSectionLock::Lock(this: &csLock);
    v2->m_WorkUnitsMap.m_Size = 0;
    m_ElementCount = v2->m_WorkUnitsRemaining.m_ElementCount;
    if ( v2->m_WorkUnitsMap.m_Size < m_ElementCount )
      CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(
        this: &v2->m_WorkUnitsMap,
        elem: v2->m_WorkUnitsMap.m_Size,
        num: m_ElementCount - v2->m_WorkUnitsMap.m_Size);
    m_ElementCount_low = SLODWORD(v2->m_WorkUnitsRemaining.m_ElementCount);
    matrixHeight = nWorkers;
    matrixWidth = m_ElementCount_low / nWorkers;
    if ( m_ElementCount_low % nWorkers != 0 )
      ++matrixWidth;
    m_Head = v2->m_WorkUnitsRemaining.m_Head;
    iWorkUnit = 0;
    if ( m_Head != -1 )
    {
      m_pMemory = v2->m_WorkUnitsRemaining.m_Memory.m_pMemory;
      do
      {
        v6 = m_Head;
        v7 = iWorkUnit / matrixHeight + matrixWidth * (iWorkUnit % matrixHeight);
        v8 = v16->m_WorkUnitsMap.m_Memory.m_pMemory;
        v9 = iWorkUnit;
        LODWORD(iWorkUnit) = iWorkUnit + 1;
        m_Element = m_pMemory[v6].m_Element;
        iWorkUnit = __PAIR64__(HIDWORD(iWorkUnit), v9) + 1;
        LODWORD(v8[v7]) = m_Element;
        HIDWORD(v8[v7]) = HIDWORD(m_pMemory[v6].m_Element);
        m_pMemory = v16->m_WorkUnitsRemaining.m_Memory.m_pMemory;
        m_Head = m_pMemory[v6].m_Next;
      }
      while ( m_Head != -1 );
      v2 = v16;
    }
    CWorkUnitWalker::Init(
      this: &v2->m_Walker,
      matrixWidth,
      matrixHeight,
      nWorkUnits: SLODWORD(v2->m_WorkUnitsRemaining.m_ElementCount));
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100304D0
// Name: public: void CShuffledWorkUnitWalker::Thread_NoteWorkUnitCompleted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShuffledWorkUnitWalker::Thread_NoteWorkUnitCompleted(
        CShuffledWorkUnitWalker *this,
        unsigned __int64 iWU)
{
  unsigned __int8 *m_pMemory; // esi
  UtlLinkedListElem_t<unsigned __int64,unsigned __int64> *v4; // eax
  int v5; // ecx
  int v6; // eax
  CCriticalSectionLock csLock; // [esp+Ch] [ebp-10h] BYREF
  int v8; // [esp+14h] [ebp-8h]
  unsigned __int8 v9; // [esp+1Bh] [ebp-1h]

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  m_pMemory = this->m_CompletedWUBits.m_Memory.m_pMemory;
  v9 = 1 << (iWU & 7);
  v8 = iWU >> 3;
  if ( (v9 & m_pMemory[v8]) == 0 )
  {
    CUtlLinkedList<unsigned __int64,unsigned __int64,0,unsigned __int64,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>>::Unlink(
      this: &this->m_WorkUnitsRemaining,
      elem: iWU);
    v4 = this->m_WorkUnitsRemaining.m_Memory.m_pMemory;
    v5 = 3 * iWU;
    *((_DWORD *)&v4->m_Next + 2 * v5) = this->m_WorkUnitsRemaining.m_FirstFree;
    *((_DWORD *)&v4->m_Next + 2 * v5 + 1) = HIDWORD(this->m_WorkUnitsRemaining.m_FirstFree);
    LOBYTE(v5) = v9;
    HIDWORD(this->m_WorkUnitsRemaining.m_FirstFree) = HIDWORD(iWU);
    v6 = v8;
    LODWORD(this->m_WorkUnitsRemaining.m_FirstFree) = iWU;
    this->m_CompletedWUBits.m_Memory.m_pMemory[v6] |= v5;
  }
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x10030560
// Name: public: virtual bool CDistributor_SDKWorker::HandlePacket(class MessageBuffer __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CDistributor_SDKWorker::HandlePacket(
        CDistributor_SDKWorker *this,
        MessageBuffer *pBuf,
        int iSource,
        unsigned __int16 bIgnoreContents)
{
  MessageBuffer *v4; // esi
  char v5; // al
  int v7; // edx
  unsigned int ShuffleCRC; // eax
  unsigned int v10; // ebx
  unsigned __int64 iWU; // [esp+8h] [ebp-18h] BYREF
  unsigned __int64 nCompleted; // [esp+10h] [ebp-10h] BYREF
  __int64 v13; // [esp+18h] [ebp-8h] OVERLAPPED BYREF

  v4 = pBuf;
  v5 = pBuf->data[1];
  if ( v5 == 50 )
  {
    if ( (_BYTE)bIgnoreContents == 0 )
    {
      MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&pBuf, bytes: 2u);
      MessageBuffer::read(this: v4, p: (unsigned __int8 *)&v13 + 4, bytes: 4u);
      MessageBuffer::read(this: v4, p: (unsigned __int8 *)&bIgnoreContents, bytes: 2u);
      v7 = (unsigned __int16)pBuf;
      this->m_iMyWorkUnitWalkerID = bIgnoreContents;
      CShuffledWorkUnitWalker::Shuffle(this: &this->m_WorkUnitWalker, nWorkers: v7);
      ShuffleCRC = CShuffledWorkUnitWalker::GetShuffleCRC(this: &this->m_WorkUnitWalker);
      if ( ShuffleCRC != HIDWORD(v13) && ++`CDistributor_SDKWorker::HandlePacket'::`10'::nWarnings <= 2 )
        _Warning(a1: "\nShuffle CRC mismatch\n");
    }
    return 1;
  }
  if ( v5 != 52 )
    return 0;
  if ( (_BYTE)bIgnoreContents != 0 )
    return 1;
  CDSInfo::ReadWUIndex(this: this->m_pInfo, pWU: (unsigned __int8 *)&nCompleted, pBuf);
  v13 = 0;
  if ( nCompleted != 0 )
  {
    v10 = HIDWORD(v13);
    do
    {
      CDSInfo::ReadWUIndex(this: this->m_pInfo, pWU: (unsigned __int8 *)&iWU, pBuf: v4);
      CShuffledWorkUnitWalker::Thread_NoteWorkUnitCompleted(this: &this->m_WorkUnitWalker, iWU);
      v10 = (__PAIR64__(v10, v13) + 1) >> 32;
      LODWORD(v13) = v13 + 1;
    }
    while ( __PAIR64__(v10, v13) < nCompleted );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10030670
// Name: public: CDistributor_SDKMaster::CDistributor_SDKMaster(void)
// Source: json
//------------------------------------------------------------------------------
CDistributor_SDKMaster *__thiscall CDistributor_SDKMaster::CDistributor_SDKMaster(CDistributor_SDKMaster *this)
{
  this->IShuffleRequester::__vftable = (IShuffleRequester_vtbl *)&IShuffleRequester::`vftable';
  this->IWorkUnitDistributorMaster::__vftable = (CDistributor_SDKMaster_vtbl *)&CDistributor_SDKMaster::`vftable'{for `IWorkUnitDistributorMaster'};
  this->IShuffleRequester::__vftable = (IShuffleRequester_vtbl *)&CDistributor_SDKMaster::`vftable'{for `IShuffleRequester'};
  CCriticalSection::CCriticalSection(this: &this->m_WorkersReadyCS);
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Memory.m_pMemory = nullptr;
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Memory.m_nAllocationCount = 0;
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Memory.m_nGrowSize = 0;
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Size = 0;
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_pElements = nullptr;
  CCriticalSection::CCriticalSection(this: &this->m_WUsCompletedCS);
  this->m_WUsCompletedCS.m_Data.m_Completed.m_Memory.m_pMemory = nullptr;
  this->m_WUsCompletedCS.m_Data.m_Completed.m_Memory.m_nAllocationCount = 0;
  this->m_WUsCompletedCS.m_Data.m_Completed.m_Memory.m_nGrowSize = 0;
  this->m_WUsCompletedCS.m_Data.m_Completed.m_Size = 0;
  this->m_WUsCompletedCS.m_Data.m_Completed.m_pElements = nullptr;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_Memory.m_pMemory = nullptr;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_Memory.m_nAllocationCount = 0;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_Memory.m_nGrowSize = 0;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_Size = 0;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_pElements = nullptr;
  MessageBuffer::MessageBuffer(this: &this->m_WUSCompletedMessageBuffer);
  CShuffledWorkUnitWalker::CShuffledWorkUnitWalker(this: &this->m_WorkUnitWalker);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10030710
// Name: public: void CDSInfo::WriteWUIndex(unsigned __int64,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDSInfo::WriteWUIndex(CDSInfo *this, unsigned __int64 iWU, MessageBuffer *pBuf)
{
  unsigned int val; // [esp+0h] [ebp-4h] BYREF

  val = (unsigned int)this;
  if ( HIDWORD(this->m_nWorkUnits) != 0 )
  {
    MessageBuffer::write(this: pBuf, p: (unsigned __int8 *)&iWU, bytes: 8u);
  }
  else if ( LODWORD(this->m_nWorkUnits) > 0xFFFF )
  {
    val = iWU;
    MessageBuffer::write(this: pBuf, p: (unsigned __int8 *)&val, bytes: 4u);
  }
  else
  {
    val = (unsigned __int16)iWU;
    MessageBuffer::write(this: pBuf, p: (unsigned __int8 *)&val, bytes: 2u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030790
// Name: public: virtual void CDistributor_SDKMaster::RequestShuffle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::RequestShuffle(CDistributor_SDKMaster *this)
{
  BYTE1(this->m_bUsingMasterLocalThreads) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100307A0
// Name: public: virtual bool CDistributor_SDKMaster::HandlePacket(class MessageBuffer __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_SDKMaster::HandlePacket(
        CDistributor_SDKMaster *this,
        MessageBuffer *pBuf,
        int iSource,
        bool bIgnoreContents)
{
  if ( pBuf->data[1] == 51 )
  {
    if ( bIgnoreContents )
      return 1;
    this->m_bShuffleRequested = true;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100307D0
// Name: public: void CDistributor_SDKMaster::Master_WorkerThread(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::Master_WorkerThread(CDistributor_SDKMaster *this, int iThread)
{
  CShuffledWorkUnitWalker *p_m_WorkUnitWalker; // ebx
  CCriticalSection *p_m_CS; // esi
  int v4; // edi
  unsigned __int64 v5; // kr08_8
  unsigned __int8 *v6; // eax
  int v7; // edi
  CCriticalSectionLock v8; // [esp+Ch] [ebp-24h] BYREF
  unsigned __int64 iWU; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int m_ElementCount; // [esp+1Ch] [ebp-14h]
  CCriticalSectionLock v11; // [esp+24h] [ebp-Ch] BYREF
  CDistributor_SDKMaster *v12; // [esp+2Ch] [ebp-4h]

  p_m_WorkUnitWalker = &this->m_WorkUnitWalker;
  v12 = this;
  p_m_CS = &this->m_WorkUnitWalker.m_CS;
  CCriticalSectionLock::CCriticalSectionLock(this: &v11, pCS: &this->m_WorkUnitWalker.m_CS);
  CCriticalSectionLock::Lock(this: &v11);
  v4 = SLODWORD(p_m_WorkUnitWalker->m_WorkUnitsRemaining.m_ElementCount) >> 31;
  m_ElementCount = p_m_WorkUnitWalker->m_WorkUnitsRemaining.m_ElementCount;
  CCriticalSectionLock::~CCriticalSectionLock(this: &v11);
  if ( __PAIR64__(v4, m_ElementCount) != 0 )
  {
    while ( !g_bVMPIEarlyExit )
    {
      if ( CShuffledWorkUnitWalker::Thread_GetNextWorkUnit(this: p_m_WorkUnitWalker, iWorker: 0, pWUIndex: &iWU) != 0 )
      {
        CCriticalSectionLock::CCriticalSectionLock(this: &v8, pCS: p_m_CS);
        CCriticalSectionLock::Lock(this: &v8);
        v5 = iWU;
        v6 = &p_m_WorkUnitWalker->m_LocalCompletedWUBits.m_Memory.m_pMemory[iWU >> 3];
        *v6 |= 1 << (iWU & 7);
        CCriticalSectionLock::~CCriticalSectionLock(this: &v8);
        ((void (__cdecl *)(int, _DWORD, _DWORD, _DWORD))v12->m_pInfo->m_WorkerInfo.m_pProcessFn)(
          a1: iThread,
          a2: v5,
          a3: HIDWORD(v5),
          a4: 0);
        NotifyLocalMasterCompletedWorkUnit(iWorkUnit: v5);
      }
      else
      {
        VMPI_Sleep(ms: 0xAu);
      }
      p_m_CS = &p_m_WorkUnitWalker->m_CS;
      CCriticalSectionLock::CCriticalSectionLock(this: &v11, pCS: &p_m_WorkUnitWalker->m_CS);
      CCriticalSectionLock::Lock(this: &v11);
      v7 = SLODWORD(p_m_WorkUnitWalker->m_WorkUnitsRemaining.m_ElementCount) >> 31;
      m_ElementCount = p_m_WorkUnitWalker->m_WorkUnitsRemaining.m_ElementCount;
      CCriticalSectionLock::~CCriticalSectionLock(this: &v11);
      if ( v7 == 0 && m_ElementCount == 0 )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100308F0
// Name: public: int CDistributor_SDKMaster::BuildWUsCompletedMessage(class CUtlVector<unsigned __int64,class CUtlMemory<unsigned __int64,int>> __near &,class MessageBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDistributor_SDKMaster::BuildWUsCompletedMessage(
        CDistributor_SDKMaster *this,
        CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *wusCompleted,
        MessageBuffer *mb)
{
  MessageBuffer *v3; // esi
  CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *v5; // edi
  int i; // esi
  unsigned __int64 *m_pMemory; // eax
  CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *v8; // ecx
  CDSInfo *m_pInfo; // eax
  _DWORD p[2]; // [esp+Ch] [ebp-8h] BYREF

  v3 = mb;
  PrepareDistributeWorkHeader(pBuf: mb, cSubpacketID: 0x34u);
  v5 = wusCompleted;
  CDSInfo::WriteWUIndex(this: this->m_pInfo, iWU: wusCompleted->m_Size, pBuf: v3);
  for ( i = 0; i < v5->m_Size; ++i )
  {
    m_pMemory = v5->m_Memory.m_pMemory;
    v8 = (CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *)v5->m_Memory.m_pMemory[i];
    p[0] = v8;
    p[1] = HIDWORD(m_pMemory[i]);
    m_pInfo = this->m_pInfo;
    if ( HIDWORD(m_pInfo->m_nWorkUnits) != 0 )
    {
      MessageBuffer::write(this: mb, (unsigned __int8 *)p, bytes: 8u);
    }
    else if ( LODWORD(m_pInfo->m_nWorkUnits) > 0xFFFF )
    {
      wusCompleted = v8;
      MessageBuffer::write(this: mb, p: (unsigned __int8 *)&wusCompleted, bytes: 4u);
    }
    else
    {
      wusCompleted = (CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *)(unsigned __int16)v8;
      MessageBuffer::write(this: mb, p: (unsigned __int8 *)&wusCompleted, bytes: 2u);
    }
  }
  return v5->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100309A0
// Name: public: static void CDistributor_SDKMaster::Master_WorkerThread_Static(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDistributor_SDKMaster::Master_WorkerThread_Static(int iThread, CDistributor_SDKMaster *pUserData)
{
  CDistributor_SDKMaster::Master_WorkerThread(this: pUserData, iThread);
}

//------------------------------------------------------------------------------
// Address: 0x100309C0
// Name: public: virtual void CDistributor_SDKMaster::DisconnectHandler(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::DisconnectHandler(CDistributor_SDKMaster *this, int workerID)
{
  int m_Size; // ecx
  int v4; // eax
  int *m_pMemory; // edx

  CCriticalSection::Lock(this: &this->m_WorkersReadyCS);
  m_Size = this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Memory.m_pMemory;
    while ( *m_pMemory != workerID )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_8;
    }
    if ( v4 != -1 )
      this->m_bForceShuffle = true;
  }
LABEL_8:
  CCriticalSection::Unlock(this: &this->m_WorkersReadyCS);
}

//------------------------------------------------------------------------------
// Address: 0x10030AD0
// Name: public: virtual void CDistributor_SDKMaster::OnWorkerReady(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::OnWorkerReady(CDistributor_SDKMaster *this, int iSource)
{
  CCriticalSectionData<CDistributor_SDKMaster::CWorkersReady> *p_m_WorkersReadyCS; // esi
  int m_Size; // edi
  int v5; // eax
  int *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  int *v8; // ecx
  int v9; // eax
  int *v10; // edi
  int Name; // eax
  CCriticalSectionData<CDistributor_SDKMaster::CWorkersReady> *v12; // [esp+Ch] [ebp-4h]

  p_m_WorkersReadyCS = &this->m_WorkersReadyCS;
  v12 = &this->m_WorkersReadyCS;
  CCriticalSection::Lock(this: &this->m_WorkersReadyCS);
  m_Size = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_pMemory;
  while ( *m_pMemory != iSource )
  {
    ++v5;
    ++m_pMemory;
    if ( v5 >= m_Size )
      goto LABEL_7;
  }
  if ( v5 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<CTCPPacket *,int> *)&p_m_WorkersReadyCS->m_Data,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Size;
    v8 = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_pMemory;
    v9 = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Size - m_Size - 1;
    p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_pElements = v8;
    if ( v9 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v8[m_Size + 1], src: (unsigned __int8 *)&v8[m_Size], count: 4 * v9);
    v10 = &p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = iSource;
    CCriticalSection::Lock(this: &this->m_WUsCompletedCS);
    MessageBuffer::setLen(this: &this->m_WUSCompletedMessageBuffer, nlen: 0);
    CDistributor_SDKMaster::BuildWUsCompletedMessage(
      this,
      wusCompleted: &this->m_WUsCompletedCS.m_Data.m_Completed,
      mb: &this->m_WUSCompletedMessageBuffer);
    CCriticalSection::Unlock(this: &this->m_WUsCompletedCS);
    Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&this->m_WUSCompletedMessageBuffer);
    VMPI_SendData(pData: this->m_WUSCompletedMessageBuffer.data, nBytes: Name, iDest: iSource, fVMPISendFlags: 0);
    this->m_bForceShuffle = true;
  }
  CCriticalSection::Unlock(this: v12);
}

//------------------------------------------------------------------------------
// Address: 0x10030BC0
// Name: public: void CDistributor_SDKMaster::Shuffle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::Shuffle(CDistributor_SDKMaster *this)
{
  int m_Size; // esi
  unsigned __int16 *m_pMemory; // ebx
  int v4; // eax
  CCriticalSectionData<CDistributor_SDKMaster::CWorkersReady> *p_m_WorkersReadyCS; // edi
  bool v6; // cc
  int v7; // edi
  unsigned __int16 *v8; // edi
  CDistributor_SDKMaster *v9; // edi
  MessageBuffer *p_m_WUSCompletedMessageBuffer; // edi
  int m_bUsingMasterLocalThreads; // eax
  int Name; // eax
  int v13; // edi
  CCriticalSectionData<CDistributor_SDKMaster::CWUsCompleted> *p_m_WUsCompletedCS; // ecx
  CDistributor_SDKMaster *v15; // edi
  int j; // edi
  int v17; // eax
  int v18; // [esp-8h] [ebp-50h]
  int v19; // [esp-8h] [ebp-50h]
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > whosWorking; // [esp+Ch] [ebp-3Ch] BYREF
  MessageBuffer mb; // [esp+20h] [ebp-28h] BYREF
  unsigned int shuffleCRC; // [esp+30h] [ebp-18h] BYREF
  int nWorkers; // [esp+34h] [ebp-14h] BYREF
  int iWorker; // [esp+38h] [ebp-10h]
  int id; // [esp+3Ch] [ebp-Ch] BYREF
  int i; // [esp+40h] [ebp-8h]
  CDistributor_SDKMaster *v27; // [esp+44h] [ebp-4h]

  m_Size = 0;
  m_pMemory = nullptr;
  v27 = this;
  memset(&whosWorking, 0, sizeof(whosWorking));
  if ( this->m_bUsingMasterLocalThreads != 0 )
  {
    CUtlMemory<unsigned short,int>::Grow(this: &whosWorking.m_Memory, num: 1);
    m_pMemory = whosWorking.m_Memory.m_pMemory;
    m_Size = whosWorking.m_Size + 1;
    v4 = whosWorking.m_Size++;
    whosWorking.m_pElements = whosWorking.m_Memory.m_pMemory;
    if ( v4 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)whosWorking.m_Memory.m_pMemory + 2,
        src: (unsigned __int8 *)whosWorking.m_Memory.m_pMemory,
        count: 2 * v4);
    if ( m_pMemory != nullptr )
      *m_pMemory = 0;
  }
  p_m_WorkersReadyCS = &this->m_WorkersReadyCS;
  CCriticalSection::Lock(this: p_m_WorkersReadyCS);
  v6 = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Size <= 0;
  i = 0;
  if ( !v6 )
  {
    do
    {
      iWorker = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_pMemory[i];
      if ( VMPI_IsProcConnected(procID: iWorker) )
      {
        v7 = m_Size;
        if ( m_Size + 1 > whosWorking.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<unsigned short,int>::Grow(
            this: &whosWorking.m_Memory,
            num: m_Size - whosWorking.m_Memory.m_nAllocationCount + 1);
          m_Size = whosWorking.m_Size;
          m_pMemory = whosWorking.m_Memory.m_pMemory;
        }
        whosWorking.m_Size = ++m_Size;
        whosWorking.m_pElements = m_pMemory;
        if ( m_Size - v7 - 1 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[v7 + 1],
            src: (unsigned __int8 *)&m_pMemory[v7],
            count: 2 * (m_Size - v7 - 1));
        v8 = &m_pMemory[v7];
        if ( v8 != nullptr )
          *v8 = iWorker;
      }
      p_m_WorkersReadyCS = &v27->m_WorkersReadyCS;
      ++i;
    }
    while ( i < v27->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Size );
  }
  CCriticalSection::Unlock(this: p_m_WorkersReadyCS);
  v9 = v27;
  CCriticalSection::Lock(this: &v27->m_WUsCompletedCS);
  p_m_WUSCompletedMessageBuffer = &v9->m_WUSCompletedMessageBuffer;
  MessageBuffer::setLen(this: p_m_WUSCompletedMessageBuffer, nlen: 0);
  iWorker = (int)&v27->m_WUsCompletedCS.m_Data.m_Pending;
  if ( CDistributor_SDKMaster::BuildWUsCompletedMessage(
         this: v27,
         wusCompleted: &v27->m_WUsCompletedCS.m_Data.m_Pending,
         mb: p_m_WUSCompletedMessageBuffer) > 0 )
  {
    m_bUsingMasterLocalThreads = v27->m_bUsingMasterLocalThreads;
    i = m_bUsingMasterLocalThreads;
    if ( m_bUsingMasterLocalThreads < m_Size )
    {
      while ( 1 )
      {
        v18 = m_pMemory[m_bUsingMasterLocalThreads];
        Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)p_m_WUSCompletedMessageBuffer);
        VMPI_SendData(pData: p_m_WUSCompletedMessageBuffer->data, nBytes: Name, iDest: v18, fVMPISendFlags: 0);
        if ( ++i >= m_Size )
          break;
        m_bUsingMasterLocalThreads = i;
      }
    }
  }
  v13 = iWorker;
  CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(
    this: &v27->m_WUsCompletedCS.m_Data.m_Completed,
    elem: v27->m_WUsCompletedCS.m_Data.m_Completed.m_Size,
    num: v27->m_WUsCompletedCS.m_Data.m_Pending.m_Size,
    pToInsert: *(const unsigned __int64 **)iWorker);
  p_m_WUsCompletedCS = &v27->m_WUsCompletedCS;
  *(_DWORD *)(v13 + 12) = 0;
  CCriticalSection::Unlock(this: p_m_WUsCompletedCS);
  v15 = v27;
  CShuffledWorkUnitWalker::Shuffle(this: &v27->m_WorkUnitWalker, nWorkers: m_Size);
  MessageBuffer::MessageBuffer(this: &mb);
  PrepareDistributeWorkHeader(pBuf: &mb, cSubpacketID: 0x32u);
  nWorkers = (unsigned __int16)m_Size;
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&nWorkers, bytes: 2u);
  shuffleCRC = CShuffledWorkUnitWalker::GetShuffleCRC(this: &v15->m_WorkUnitWalker);
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&shuffleCRC, bytes: 4u);
  iWorker = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  id = 0;
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&id, bytes: 2u);
  for ( j = v15->m_bUsingMasterLocalThreads; j < m_Size; ++j )
  {
    id = (unsigned __int16)j;
    MessageBuffer::update(this: &mb, loc: iWorker, p: (unsigned __int8 *)&id, bytes: 2u);
    v19 = m_pMemory[j];
    v17 = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
    VMPI_SendData(pData: mb.data, nBytes: v17, iDest: v19, fVMPISendFlags: 0);
  }
  MessageBuffer::~MessageBuffer(this: &mb);
  if ( whosWorking.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10030E50
// Name: public: bool CDistributor_SDKMaster::Thread_HandleWorkUnitResults(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_SDKMaster::Thread_HandleWorkUnitResults(
        CDistributor_SDKMaster *this,
        unsigned __int64 iWorkUnit)
{
  unsigned int v3; // ebx
  CCriticalSectionLock v5; // [esp+Ch] [ebp-Ch] BYREF
  bool v6; // [esp+17h] [ebp-1h]

  CCriticalSectionLock::CCriticalSectionLock(this: &v5, pCS: &this->m_WorkUnitWalker.m_CS);
  CCriticalSectionLock::Lock(this: &v5);
  v3 = iWorkUnit;
  v6 = ((unsigned __int8)(1 << (iWorkUnit & 7))
      & this->m_WorkUnitWalker.m_CompletedWUBits.m_Memory.m_pMemory[iWorkUnit >> 3]) != 0;
  CCriticalSectionLock::~CCriticalSectionLock(this: &v5);
  if ( v6 )
    return 0;
  CShuffledWorkUnitWalker::Thread_NoteWorkUnitCompleted(
    this: &this->m_WorkUnitWalker,
    iWU: __PAIR64__(HIDWORD(iWorkUnit), v3));
  CCriticalSection::Lock(this: &this->m_WUsCompletedCS);
  CUtlVector<_D3DXMACRO,CUtlMemory<_D3DXMACRO,int>>::InsertBefore(
    this: &this->m_WUsCompletedCS.m_Data.m_Pending,
    elem: this->m_WUsCompletedCS.m_Data.m_Pending.m_Size,
    src: &iWorkUnit);
  CCriticalSection::Unlock(this: &this->m_WUsCompletedCS);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10030F00
// Name: class IWorkUnitDistributorWorker __near * CreateWUDistributor_SDKWorker(void)
// Source: json
//------------------------------------------------------------------------------
IWorkUnitDistributorWorker *__cdecl CreateWUDistributor_SDKWorker()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x140u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = &IShuffleRequester::`vftable';
  *(_DWORD *)v0 = &CDistributor_SDKWorker::`vftable'{for `IWorkUnitDistributorWorker'};
  *((_DWORD *)v0 + 1) = &CDistributor_SDKWorker::`vftable'{for `IShuffleRequester'};
  CShuffledWorkUnitWalker::CShuffledWorkUnitWalker(this: (CShuffledWorkUnitWalker *)(v0 + 16));
  return (IWorkUnitDistributorWorker *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10031000
// Name: public: void CShuffledWorkUnitWalker::Init(unsigned __int64,class IShuffleRequester __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShuffledWorkUnitWalker::Init(
        CShuffledWorkUnitWalker *this,
        unsigned __int64 nWorkUnits,
        IShuffleRequester *pRequester)
{
  __int64 v4; // rcx
  int v5; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  signed int v8; // eax
  int v9; // eax
  unsigned __int8 *v10; // ecx
  signed int v11; // eax
  unsigned int v12; // edi
  unsigned __int64 i; // kr08_8
  int v14; // edx
  unsigned __int64 iWU; // [esp+Ch] [ebp-8h] BYREF

  HIDWORD(v4) = 0;
  this->m_iLastShuffleRequest = 0;
  this->m_iCurShuffle = 1;
  this->m_flLastShuffleTime = _Plat_FloatTime();
  v5 = (nWorkUnits + 7) >> 3;
  this->m_pShuffleRequester = pRequester;
  this->m_CompletedWUBits.m_Size = 0;
  if ( v5 != 0 )
  {
    m_nAllocationCount = this->m_CompletedWUBits.m_Memory.m_nAllocationCount;
    if ( v5 > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow((CUtlMemory<char,int> *)this, num: v5 - m_nAllocationCount);
    this->m_CompletedWUBits.m_Size += v5;
    m_pMemory = this->m_CompletedWUBits.m_Memory.m_pMemory;
    v8 = this->m_CompletedWUBits.m_Size - v5;
    this->m_CompletedWUBits.m_pElements = this->m_CompletedWUBits.m_Memory.m_pMemory;
    if ( v8 > 0 && v5 > 0 )
      _V_memmove(dest: &m_pMemory[v5], src: m_pMemory, count: v8);
  }
  this->m_LocalCompletedWUBits.m_Size = 0;
  if ( v5 != 0 )
  {
    v9 = this->m_LocalCompletedWUBits.m_Memory.m_nAllocationCount;
    if ( v5 > v9 )
      CUtlMemory<bool,int>::Grow(this: (CUtlMemory<char,int> *)&this->m_LocalCompletedWUBits, num: v5 - v9);
    this->m_LocalCompletedWUBits.m_Size += v5;
    v10 = this->m_LocalCompletedWUBits.m_Memory.m_pMemory;
    v11 = this->m_LocalCompletedWUBits.m_Size - v5;
    this->m_LocalCompletedWUBits.m_pElements = v10;
    if ( v11 > 0 && v5 > 0 )
      _V_memmove(dest: &v10[v5], src: v10, count: v11);
  }
  iWU = 0;
  if ( this->m_CompletedWUBits.m_Size != 0 )
  {
    v12 = HIDWORD(iWU);
    LODWORD(v4) = iWU;
    do
    {
      this->m_CompletedWUBits.m_Memory.m_pMemory[v4] = 0;
      this->m_LocalCompletedWUBits.m_Memory.m_pMemory[v4] = 0;
      v12 = (v4 + __PAIR64__(v12, 1)) >> 32;
      LODWORD(v4) = v4 + 1;
    }
    while ( __PAIR64__(v12, v4) < this->m_CompletedWUBits.m_Size );
  }
  iWU = 0;
  if ( nWorkUnits != 0 )
  {
    for ( i = iWU; i < nWorkUnits; iWU = i )
    {
      if ( CUtlLinkedList<unsigned __int64,unsigned __int64,0,unsigned __int64,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>>::AddToTail(
             this: &this->m_WorkUnitsRemaining,
             src: &iWU) != (_DWORD)i
        || v14 != HIDWORD(i) )
      {
        _Error(a1: "CShuffledWorkUnitWalker: assumption on CUtlLinkedList indexing failed.\n");
      }
      ++i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031180
// Name: public: virtual void CDistributor_SDKMaster::DistributeWork_Master(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::DistributeWork_Master(CDistributor_SDKMaster *this, CDSInfo *pInfo)
{
  const char *ParamString; // eax
  CCriticalSection *p_m_CS; // edi
  __int64 m_ElementCount_low; // kr00_8
  __int64 v6; // kr08_8
  double v7; // [esp+Ch] [ebp-10h]
  CCriticalSectionLock v8; // [esp+14h] [ebp-8h] BYREF

  this->m_pInfo = pInfo;
  *(_WORD *)&this->m_bForceShuffle = 0;
  this->m_flLastShuffleRequestServiceTime = _Plat_FloatTime();
  this->m_bUsingMasterLocalThreads = pInfo->m_WorkerInfo.m_pProcessFn != nullptr;
  if ( VMPI_IsParamUsed(eParam: mpi_NoMasterWorkerThreads) )
  {
    ParamString = VMPI_GetParamString(eParam: mpi_NoMasterWorkerThreads);
    _Msg(a1: "%s found. No worker threads will be created.\n", ParamString);
    this->m_bUsingMasterLocalThreads = 0;
  }
  CShuffledWorkUnitWalker::Init(
    this: &this->m_WorkUnitWalker,
    nWorkUnits: pInfo->m_nWorkUnits,
    pRequester: &this->IShuffleRequester);
  CDistributor_SDKMaster::Shuffle(this);
  if ( this->m_bUsingMasterLocalThreads != 0 )
    RunThreads_Start(
      fn: (void (__cdecl *)(int, void *))CDistributor_SDKMaster::Master_WorkerThread_Static,
      pUserData: this,
      ePriority: k_eRunThreadsPriority_Idle);
  _Plat_MSTime();
  p_m_CS = &this->m_WorkUnitWalker.m_CS;
  CCriticalSectionLock::CCriticalSectionLock(this: &v8, pCS: &this->m_WorkUnitWalker.m_CS);
  CCriticalSectionLock::Lock(this: &v8);
  m_ElementCount_low = SLODWORD(this->m_WorkUnitWalker.m_WorkUnitsRemaining.m_ElementCount);
  CCriticalSectionLock::~CCriticalSectionLock(this: &v8);
  if ( m_ElementCount_low != 0 )
  {
    while ( 1 )
    {
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xC8);
      CheckLocalMasterCompletedWorkUnits();
      VMPITracker_HandleDebugKeypresses();
      if ( g_pDistributeWorkCallbacks != nullptr
        && g_pDistributeWorkCallbacks->Update(this: g_pDistributeWorkCallbacks) != 0 )
      {
        goto LABEL_16;
      }
      if ( this->m_bForceShuffle )
        goto LABEL_14;
      if ( this->m_bShuffleRequested )
      {
        v7 = _Plat_FloatTime();
        if ( v7 - this->m_flLastShuffleRequestServiceTime > 2.0 )
          break;
      }
LABEL_15:
      CCriticalSectionLock::CCriticalSectionLock(this: &v8, pCS: p_m_CS);
      CCriticalSectionLock::Lock(this: &v8);
      v6 = SLODWORD(this->m_WorkUnitWalker.m_WorkUnitsRemaining.m_ElementCount);
      CCriticalSectionLock::~CCriticalSectionLock(this: &v8);
      if ( v6 == 0 )
        goto LABEL_16;
      p_m_CS = &this->m_WorkUnitWalker.m_CS;
    }
    this->m_flLastShuffleRequestServiceTime = v7;
    this->m_bShuffleRequested = false;
LABEL_14:
    CDistributor_SDKMaster::Shuffle(this);
    _Plat_MSTime();
    this->m_bForceShuffle = false;
    goto LABEL_15;
  }
LABEL_16:
  RunThreads_End();
}

//------------------------------------------------------------------------------
// Address: 0x10031330
// Name: public: virtual bool CDistributor_SDKMaster::HandleWorkUnitResults(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_SDKMaster::HandleWorkUnitResults(CDistributor_SDKMaster *this, unsigned __int64 iWorkUnit)
{
  return CDistributor_SDKMaster::Thread_HandleWorkUnitResults(this, iWorkUnit);
}

//------------------------------------------------------------------------------
// Address: 0x10031350
// Name: public: virtual void CDistributor_SDKWorker::Init(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKWorker::Init(CDistributor_SDKWorker *this, CDSInfo *pInfo)
{
  this->m_iMyWorkUnitWalkerID = -1;
  this->m_pInfo = pInfo;
  CShuffledWorkUnitWalker::Init(
    this: &this->m_WorkUnitWalker,
    nWorkUnits: pInfo->m_nWorkUnits,
    pRequester: &this->IShuffleRequester);
}

//------------------------------------------------------------------------------
// Address: 0x10031390
// Name: public: virtual void CDistributor_SDKWorker::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKWorker::Release(CDistributor_SDKWorker *this)
{
  if ( this != nullptr )
  {
    CShuffledWorkUnitWalker::~CShuffledWorkUnitWalker(this: &this->m_WorkUnitWalker);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100313B0
// Name: class IWorkUnitDistributorMaster __near * CreateWUDistributor_SDKMaster(void)
// Source: json
//------------------------------------------------------------------------------
CDistributor_SDKMaster *__cdecl CreateWUDistributor_SDKMaster()
{
  CDistributor_SDKMaster *v0; // eax

  v0 = (CDistributor_SDKMaster *)operator new(nSize: 0x240u);
  if ( v0 != nullptr )
    return CDistributor_SDKMaster::CDistributor_SDKMaster(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100313D0
// Name: public: virtual void CDistributor_SDKMaster::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::Release(CDistributor_SDKMaster *this)
{
  if ( this != nullptr )
  {
    CShuffledWorkUnitWalker::~CShuffledWorkUnitWalker(this: &this->m_WorkUnitWalker);
    MessageBuffer::~MessageBuffer(this: &this->m_WUSCompletedMessageBuffer);
    CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_WUsCompletedCS.m_Data.m_Pending);
    CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_WUsCompletedCS.m_Data);
    CCriticalSection::~CCriticalSection(this: &this->m_WUsCompletedCS);
    CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_WorkersReadyCS.m_Data);
    CCriticalSection::~CCriticalSection(this: &this->m_WorkersReadyCS);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031430
// Name: _deflateInit_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl deflateInit_(int a1, int a2, int a3, int a4)
{
  return deflateInit2_(a1, a2, a3: 8, a4: 15, a5: 8, a6: 0, a7: a3, a8: a4);
}

//------------------------------------------------------------------------------
// Address: 0x10031460
// Name: _deflateInit2_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl deflateInit2_(_DWORD *a1, int a2, int a3, int a4, int a5, unsigned int a6, _BYTE *a7, int a8)
{
  int v8; // ebp
  int v10; // eax
  unsigned int v11; // ecx
  int v12; // ebx
  _DWORD *v13; // eax
  _DWORD *v14; // esi
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  unsigned int v21; // ecx

  v8 = 0;
  if ( a7 == nullptr || *a7 != *off_100618D8 || a8 != 56 )
    return -6;
  if ( a1 == nullptr )
    return -2;
  v10 = a1[8];
  a1[6] = 0;
  if ( v10 == 0 )
  {
    a1[8] = zcalloc;
    a1[10] = 0;
  }
  if ( a1[9] == 0 )
    a1[9] = zcfree;
  v11 = a2;
  if ( a2 == -1 )
  {
    a2 = 6;
    v11 = 6;
  }
  v12 = a4;
  if ( a4 < 0 )
  {
    v8 = 1;
    v12 = -a4;
  }
  if ( a5 < 1 || a5 > 9 || a3 != 8 || v12 < 8 || v12 > 15 || v11 > 9 || a6 > 2 )
    return -2;
  v13 = (_DWORD *)((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: 1, a3: 5816);
  v14 = v13;
  if ( v13 == nullptr )
    return -4;
  a1[7] = v13;
  v13[6] = v8;
  v13[10] = v12;
  *v13 = a1;
  v13[18] = a5 + 7;
  v13[9] = 1 << v12;
  v13[11] = (1 << v12) - 1;
  v15 = 1 << (a5 + 7);
  v14[17] = v15;
  v14[19] = v15 - 1;
  v14[20] = (a5 + 9) / 3u;
  v16 = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: 1 << v12, a3: 2);
  v17 = v14[9];
  v14[12] = v16;
  v18 = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: v17, a3: 2);
  v19 = v14[17];
  v14[14] = v18;
  v14[15] = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: v19, a3: 2);
  v14[1445] = 1 << (a5 + 6);
  v20 = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: 1 << (a5 + 6), a3: 4);
  v21 = v14[1445];
  v14[2] = v20;
  v14[3] = 4 * v21;
  if ( v14[12] != 0 && v14[14] != 0 && v14[15] != 0 && v20 != 0 )
  {
    *((_BYTE *)v14 + 29) = 8;
    v14[1447] = v20 + 2 * (v21 >> 1);
    v14[1444] = v20 + 2 * v21 + v21;
    v14[32] = a6;
    v14[31] = a2;
    return deflateReset(a1);
  }
  else
  {
    a1[6] = off_1006196C[0];
    deflateEnd(a1);
    return -4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031660
// Name: _deflateReset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl deflateReset(_DWORD *a1)
{
  _DWORD *v1; // esi
  int v2; // edx

  if ( a1 == nullptr )
    return -2;
  v1 = (_DWORD *)a1[7];
  if ( v1 == nullptr || a1[8] == 0 || a1[9] == 0 )
    return -2;
  a1[5] = 0;
  a1[2] = 0;
  a1[6] = 0;
  a1[11] = 2;
  v2 = v1[2];
  v1[5] = 0;
  v1[4] = v2;
  if ( (int)v1[6] < 0 )
    v1[6] = 0;
  v1[1] = v1[6] != 0 ? 113 : 42;
  a1[12] = 1;
  v1[8] = 0;
  _tr_init(a1: v1);
  sub_10031AF0(a1: v1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100316E0
// Name: _deflate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl deflate(int a1, int a2)
{
  int v3; // esi
  int v4; // eax
  int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // [esp+14h] [ebp+4h]

  if ( a1 == 0 )
    return -2;
  v3 = *(_DWORD *)(a1 + 28);
  if ( v3 == 0 || (unsigned int)a2 > 4 )
    return -2;
  if ( *(_DWORD *)(a1 + 12) == 0
    || *(_DWORD *)a1 == 0 && *(_DWORD *)(a1 + 4) != 0
    || (v4 = *(_DWORD *)(v3 + 4)) == 666 && a2 != 4 )
  {
    *(char **)(a1 + 24) = off_10061964[0];
    return -2;
  }
  if ( *(_DWORD *)(a1 + 16) == 0 )
  {
    *(char **)(a1 + 24) = off_10061970[0];
    return -5;
  }
  v6 = *(_DWORD *)(v3 + 32);
  *(_DWORD *)v3 = a1;
  v13 = v6;
  *(_DWORD *)(v3 + 32) = a2;
  if ( v4 == 42 )
  {
    v7 = (*(_DWORD *)(v3 + 124) - 1) >> 1;
    if ( v7 > 3 )
      v7 = 3;
    v8 = (v7 << 6) | ((*(_DWORD *)(v3 + 40) << 12) - 30720);
    if ( *(_DWORD *)(v3 + 100) != 0 )
      v8 |= 0x20u;
    *(_DWORD *)(v3 + 4) = 113;
    sub_10031990(a1: v3, a2: v8 - v8 % 0x1F + 31);
    if ( *(_DWORD *)(v3 + 100) != 0 )
    {
      sub_10031990(a1: v3, a2: *(unsigned __int16 *)(a1 + 50));
      sub_10031990(a1: v3, a2: (unsigned __int16)*(_DWORD *)(a1 + 48));
    }
    *(_DWORD *)(a1 + 48) = 1;
  }
  if ( *(_DWORD *)(v3 + 20) != 0 )
  {
    sub_100319C0(a1);
    if ( *(_DWORD *)(a1 + 16) == 0 )
    {
      *(_DWORD *)(v3 + 32) = -1;
      return 0;
    }
  }
  else if ( *(_DWORD *)(a1 + 4) == 0 && a2 <= v13 && a2 != 4 )
  {
    *(char **)(a1 + 24) = off_10061970[0];
    return -5;
  }
  v9 = *(_DWORD *)(v3 + 4);
  v10 = *(_DWORD *)(a1 + 4);
  if ( v9 == 666 )
  {
    if ( v10 != 0 )
    {
      *(char **)(a1 + 24) = off_10061970[0];
      return -5;
    }
  }
  else if ( v10 != 0 )
  {
    goto LABEL_33;
  }
  if ( *(_DWORD *)(v3 + 108) == 0 && (a2 == 0 || v9 == 666) )
  {
LABEL_45:
    if ( a2 != 4 )
      return 0;
    if ( *(_DWORD *)(v3 + 24) != 0 )
      return 1;
    sub_10031990(a1: v3, a2: *(unsigned __int16 *)(a1 + 50));
    sub_10031990(a1: v3, a2: (unsigned __int16)*(_DWORD *)(a1 + 48));
    sub_100319C0(a1);
    v12 = *(_DWORD *)(v3 + 20);
    *(_DWORD *)(v3 + 24) = -1;
    return v12 == 0;
  }
LABEL_33:
  v11 = funcs_10031874[3 * *(_DWORD *)(v3 + 124)](a1: v3, a2);
  if ( v11 == 2 || v11 == 3 )
    *(_DWORD *)(v3 + 4) = 666;
  if ( v11 != 0 && v11 != 2 )
  {
    if ( v11 == 1 )
    {
      if ( a2 == 1 )
      {
        _tr_align(a1: v3);
      }
      else
      {
        _tr_stored_block(a1: v3, a2: 0, a3: 0, a4: 0);
        if ( a2 == 3 )
        {
          *(_WORD *)(*(_DWORD *)(v3 + 60) + 2 * *(_DWORD *)(v3 + 68) - 2) = 0;
          memset(*(void **)(v3 + 60), 0, 2 * *(_DWORD *)(v3 + 68) - 2);
        }
      }
      sub_100319C0(a1);
      if ( *(_DWORD *)(a1 + 16) == 0 )
      {
        *(_DWORD *)(v3 + 32) = -1;
        return 0;
      }
    }
    goto LABEL_45;
  }
  if ( *(_DWORD *)(a1 + 16) == 0 )
    *(_DWORD *)(v3 + 32) = -1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10031990
// Name: sub_10031990
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10031990(int a1, __int16 a2)
{
  int v3; // esi
  int v4; // edx

  *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = HIBYTE(a2);
  v3 = *(_DWORD *)(a1 + 8);
  v4 = *(_DWORD *)(a1 + 20) + 1;
  *(_DWORD *)(a1 + 20) = v4;
  *(_BYTE *)(v4 + v3) = a2;
  ++*(_DWORD *)(a1 + 20);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x100319C0
// Name: sub_100319C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl sub_100319C0(int a1)
{
  _DWORD *result; // eax
  int v2; // esi
  unsigned int v3; // edx
  int v4; // ecx
  int v5; // ecx
  unsigned int v6; // edi

  result = (_DWORD *)a1;
  v2 = *(_DWORD *)(a1 + 28);
  v3 = *(_DWORD *)(v2 + 20);
  if ( v3 > *(_DWORD *)(a1 + 16) )
    v3 = *(_DWORD *)(a1 + 16);
  if ( v3 != 0 )
  {
    qmemcpy(*(void **)(a1 + 12), *(const void **)(v2 + 16), v3);
    v4 = *(_DWORD *)(a1 + 28);
    *(_DWORD *)(a1 + 12) += v3;
    *(_DWORD *)(v4 + 16) += v3;
    v5 = *(_DWORD *)(a1 + 28);
    v6 = *(_DWORD *)(a1 + 16) - v3;
    *(_DWORD *)(a1 + 20) += v3;
    *(_DWORD *)(a1 + 16) = v6;
    *(_DWORD *)(v5 + 20) -= v3;
    result = *(_DWORD **)(a1 + 28);
    if ( result[5] == 0 )
      result[4] = result[2];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10031A40
// Name: _deflateEnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl deflateEnd(int a1)
{
  int v1; // eax
  int v2; // edi
  int v3; // eax
  int v4; // ecx
  int v5; // edx

  if ( a1 == 0 )
    return -2;
  v1 = *(_DWORD *)(a1 + 28);
  if ( v1 == 0 )
    return -2;
  v2 = *(_DWORD *)(v1 + 4);
  if ( v2 != 42 && v2 != 113 && v2 != 666 )
    return -2;
  v3 = *(_DWORD *)(v1 + 8);
  if ( v3 != 0 )
    (*(void (__cdecl **)(_DWORD, int))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: v3);
  v4 = *(_DWORD *)(a1 + 28);
  if ( *(_DWORD *)(v4 + 60) != 0 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: *(_DWORD *)(v4 + 60));
  if ( *(_DWORD *)(*(_DWORD *)(a1 + 28) + 56) != 0 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(
      a1: *(_DWORD *)(a1 + 40),
      a2: *(_DWORD *)(*(_DWORD *)(a1 + 28) + 56));
  v5 = *(_DWORD *)(a1 + 28);
  if ( *(_DWORD *)(v5 + 48) != 0 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: *(_DWORD *)(v5 + 48));
  (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: *(_DWORD *)(a1 + 28));
  *(_DWORD *)(a1 + 28) = 0;
  return v2 != 113 ? 0 : 0xFD;
}

//------------------------------------------------------------------------------
// Address: 0x10031AF0
// Name: sub_10031AF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10031AF0(int a1)
{
  int v1; // ecx
  int v2; // eax
  int v3; // ecx

  v1 = *(_DWORD *)(a1 + 68);
  *(_DWORD *)(a1 + 52) = 2 * *(_DWORD *)(a1 + 36);
  *(_WORD *)(*(_DWORD *)(a1 + 60) + 2 * v1 - 2) = 0;
  memset(*(void **)(a1 + 60), 0, 2 * *(_DWORD *)(a1 + 68) - 2);
  v2 = 6 * *(_DWORD *)(a1 + 124);
  *(_DWORD *)(a1 + 120) = (unsigned __int16)word_100582AA[v2];
  *(_DWORD *)(a1 + 132) = (unsigned __int16)word_100582A8[v2];
  *(_DWORD *)(a1 + 136) = (unsigned __int16)word_100582AC[v2];
  v3 = (unsigned __int16)word_100582AE[v2];
  *(_DWORD *)(a1 + 100) = 0;
  *(_DWORD *)(a1 + 84) = 0;
  *(_DWORD *)(a1 + 108) = 0;
  *(_DWORD *)(a1 + 96) = 0;
  *(_DWORD *)(a1 + 64) = 0;
  *(_DWORD *)(a1 + 116) = v3;
  *(_DWORD *)(a1 + 112) = 2;
  *(_DWORD *)(a1 + 88) = 2;
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10031B90
// Name: sub_10031B90
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10031B90(int *a1, int a2)
{
  int v2; // edi
  unsigned int v3; // eax
  int v4; // ecx
  bool v5; // zf
  int v6; // ecx
  unsigned int v7; // edx
  unsigned int v8; // eax
  int v9; // edx
  int v10; // ecx
  unsigned int v11; // edx
  int v12; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // [esp-14h] [ebp-1Ch]
  int v17; // [esp-14h] [ebp-1Ch]
  int v18; // [esp-14h] [ebp-1Ch]

  v2 = 0xFFFF;
  if ( (unsigned int)(a1[3] - 5) < 0xFFFF )
    v2 = a1[3] - 5;
  while ( 1 )
  {
    v3 = a1[27];
    if ( v3 <= 1 )
    {
      sub_10031CE0(a1);
      v3 = a1[27];
      if ( v3 == 0 )
        break;
    }
    v4 = a1[25];
    a1[27] = 0;
    v5 = v3 + v4 == 0;
    a1[25] = v3 + v4;
    v6 = a1[21];
    v7 = a1[25];
    v8 = v6 + v2;
    if ( !v5 && v7 < v8
      || ((a1[25] = v8, a1[27] = v7 - v8, v6 < 0) ? (v9 = 0) : (v9 = v6 + a1[12]),
          _tr_flush_block(a1, a2: v9, a3: v2, a4: 0),
          v16 = *a1,
          a1[21] = a1[25],
          sub_100319C0(a1: v16),
          *(_DWORD *)(*a1 + 16) != 0) )
    {
      v10 = a1[21];
      v11 = a1[25] - v10;
      if ( v11 < a1[9] - 262 )
        continue;
      v12 = v10 < 0 ? 0 : v10 + a1[12];
      _tr_flush_block(a1, a2: v12, a3: v11, a4: 0);
      v17 = *a1;
      a1[21] = a1[25];
      sub_100319C0(a1: v17);
      if ( *(_DWORD *)(*a1 + 16) != 0 )
        continue;
    }
    return 0;
  }
  if ( a2 == 0 )
    return 0;
  v14 = a1[21];
  if ( v14 < 0 )
    v15 = 0;
  else
    v15 = v14 + a1[12];
  _tr_flush_block(a1, a2: v15, a3: a1[25] - v14, a4: a2 == 4);
  v18 = *a1;
  a1[21] = a1[25];
  sub_100319C0(a1: v18);
  if ( *(_DWORD *)(*a1 + 16) != 0 )
    return 2 * (a2 == 4) + 1;
  else
    return a2 != 4 ? 0 : 2;
}

//------------------------------------------------------------------------------
// Address: 0x10031CE0
// Name: sub_10031CE0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10031CE0(int a1)
{
  unsigned int v1; // ebp
  unsigned int v2; // eax
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  unsigned int v6; // ecx
  int v7; // esi
  int v8; // ecx
  _WORD *v9; // ecx
  __int16 v10; // ax
  unsigned int v11; // esi
  _WORD *v12; // ecx
  __int16 v13; // ax
  int result; // eax
  unsigned int v15; // esi
  int v16; // ecx
  unsigned __int8 *v17; // edi
  int v18; // eax

  v1 = *(_DWORD *)(a1 + 36);
  do
  {
    v2 = *(_DWORD *)(a1 + 100);
    v3 = *(_DWORD *)(a1 + 108);
    v4 = *(_DWORD *)(a1 + 52) - v2 - v3;
    if ( v4 != 0 )
    {
      if ( v4 == -1 )
      {
        v4 = -2;
        goto LABEL_20;
      }
    }
    else if ( v2 == 0 && v3 == 0 )
    {
      v4 = v1;
      goto LABEL_20;
    }
    if ( v2 >= *(_DWORD *)(a1 + 36) + v1 - 262 )
    {
      qmemcpy(*(void **)(a1 + 48), (const void *)(*(_DWORD *)(a1 + 48) + v1), v1);
      v5 = *(_DWORD *)(a1 + 84);
      v6 = *(_DWORD *)(a1 + 100) - v1;
      *(_DWORD *)(a1 + 104) -= v1;
      v7 = *(_DWORD *)(a1 + 68);
      *(_DWORD *)(a1 + 100) = v6;
      v8 = *(_DWORD *)(a1 + 60);
      *(_DWORD *)(a1 + 84) = v5 - v1;
      v9 = (_WORD *)(v8 + 2 * v7);
      do
      {
        if ( (unsigned __int16)*--v9 < v1 )
          v10 = 0;
        else
          v10 = *v9 - v1;
        --v7;
        *v9 = v10;
      }
      while ( v7 != 0 );
      v11 = v1;
      v12 = (_WORD *)(*(_DWORD *)(a1 + 56) + 2 * v1);
      do
      {
        if ( (unsigned __int16)*--v12 < v1 )
          v13 = 0;
        else
          v13 = *v12 - v1;
        --v11;
        *v12 = v13;
      }
      while ( v11 != 0 );
      v4 += v1;
    }
LABEL_20:
    result = *(_DWORD *)a1;
    if ( *(_DWORD *)(*(_DWORD *)a1 + 4) == 0 )
      break;
    result = sub_10031E10(a1: result, a2: *(_DWORD *)(a1 + 48) + *(_DWORD *)(a1 + 100) + *(_DWORD *)(a1 + 108), a3: v4);
    v15 = result + *(_DWORD *)(a1 + 108);
    *(_DWORD *)(a1 + 108) = v15;
    if ( v15 >= 3 )
    {
      v16 = *(_DWORD *)(a1 + 80);
      v17 = (unsigned __int8 *)(*(_DWORD *)(a1 + 100) + *(_DWORD *)(a1 + 48));
      v18 = *v17;
      *(_DWORD *)(a1 + 64) = v18;
      result = *(_DWORD *)(a1 + 76) & (v17[1] ^ (v18 << v16));
      *(_DWORD *)(a1 + 64) = result;
    }
    if ( v15 >= 0x106 )
      break;
    result = *(_DWORD *)(*(_DWORD *)a1 + 4);
  }
  while ( result != 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10031E10
// Name: sub_10031E10
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_10031E10(_DWORD *a1, void *a2, unsigned int a3)
{
  unsigned int v3; // ebx
  int v5; // eax

  v3 = a1[1];
  if ( v3 > a3 )
    v3 = a3;
  if ( v3 == 0 )
    return 0;
  a1[1] -= v3;
  if ( *(_DWORD *)(a1[7] + 24) == 0 )
    a1[12] = adler32(a1: a1[12], a2: *a1, a3: v3);
  qmemcpy(a2, (const void *)*a1, v3);
  v5 = a1[2];
  *a1 += v3;
  a1[2] = v3 + v5;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10031E90
// Name: sub_10031E90
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10031E90(int a1, int a2)
{
  int v2; // edi
  unsigned int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  char v7; // cl
  __int16 v8; // ax
  unsigned __int16 v9; // ax
  int v10; // edx
  int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // edx
  BOOL v14; // ebp
  unsigned int v15; // ecx
  int v16; // eax
  int v17; // edi
  int v18; // edx
  int v19; // ecx
  int v20; // eax
  int v21; // eax
  unsigned int v22; // ecx
  unsigned __int8 *v23; // edx
  int v24; // ecx
  int v25; // eax
  unsigned __int8 v26; // al
  int v27; // ecx
  int v28; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // [esp-14h] [ebp-2Ch]
  int v33; // [esp-14h] [ebp-2Ch]

  v2 = 0;
  while ( 1 )
  {
    v3 = *(_DWORD *)(a1 + 108);
    if ( v3 < 0x106 )
    {
      sub_10031CE0(a1);
      v3 = *(_DWORD *)(a1 + 108);
      if ( v3 < 0x106 && a2 == 0 )
        return 0;
      if ( v3 == 0 )
        break;
    }
    if ( v3 >= 3 )
    {
      v4 = *(_DWORD *)(a1 + 100);
      v5 = *(_DWORD *)(a1 + 60);
      v6 = *(_DWORD *)(a1 + 76)
         & (*(unsigned __int8 *)(*(_DWORD *)(a1 + 48) + v4 + 2)
          ^ (*(_DWORD *)(a1 + 64) << *(_DWORD *)(a1 + 80)));
      HIWORD(v2) = 0;
      *(_DWORD *)(a1 + 64) = v6;
      LOWORD(v2) = *(_WORD *)(v5 + 2 * v6);
      *(_WORD *)(*(_DWORD *)(a1 + 56) + 2 * (v4 & *(_DWORD *)(a1 + 44))) = v2;
      *(_WORD *)(*(_DWORD *)(a1 + 60) + 2 * *(_DWORD *)(a1 + 64)) = *(_WORD *)(a1 + 100);
    }
    if ( v2 != 0
      && *(_DWORD *)(a1 + 100) - v2 <= (unsigned int)(*(_DWORD *)(a1 + 36) - 262)
      && *(_DWORD *)(a1 + 128) != 2 )
    {
      *(_DWORD *)(a1 + 88) = sub_100321D0(a1, a2: v2);
    }
    if ( *(_DWORD *)(a1 + 88) < 3u )
    {
      v26 = *(_BYTE *)(*(_DWORD *)(a1 + 100) + *(_DWORD *)(a1 + 48));
      *(_WORD *)(*(_DWORD *)(a1 + 5788) + 2 * *(_DWORD *)(a1 + 5784)) = 0;
      *(_BYTE *)(*(_DWORD *)(a1 + 5776) + (*(_DWORD *)(a1 + 5784))++) = v26;
      ++*(_WORD *)(a1 + 4 * v26 + 140);
      v14 = *(_DWORD *)(a1 + 5784) == *(_DWORD *)(a1 + 5780) - 1;
      --*(_DWORD *)(a1 + 108);
    }
    else
    {
      v7 = *(_DWORD *)(a1 + 88);
      v8 = *(_WORD *)(a1 + 100) - *(_WORD *)(a1 + 104);
      *(_WORD *)(*(_DWORD *)(a1 + 5788) + 2 * *(_DWORD *)(a1 + 5784)) = v8;
      v9 = v8 - 1;
      *(_BYTE *)(*(_DWORD *)(a1 + 5776) + (*(_DWORD *)(a1 + 5784))++) = v7 - 3;
      v10 = (unsigned __int8)_length_code[(unsigned __int8)(v7 - 3)];
      ++*(_WORD *)(a1 + 4 * v10 + 1168);
      if ( v9 >= 0x100u )
        v11 = (unsigned __int8)byte_10058A70[v9 >> 7];
      else
        v11 = (unsigned __int8)_dist_code[v9];
      ++*(_WORD *)(a1 + 4 * v11 + 2432);
      v12 = *(_DWORD *)(a1 + 88);
      v13 = *(_DWORD *)(a1 + 120);
      v14 = *(_DWORD *)(a1 + 5784) == *(_DWORD *)(a1 + 5780) - 1;
      v15 = *(_DWORD *)(a1 + 108) - v12;
      *(_DWORD *)(a1 + 108) = v15;
      if ( v12 > v13 || v15 < 3 )
      {
        v22 = v12 + *(_DWORD *)(a1 + 100);
        v23 = (unsigned __int8 *)(v22 + *(_DWORD *)(a1 + 48));
        *(_DWORD *)(a1 + 100) = v22;
        v24 = *(_DWORD *)(a1 + 80);
        *(_DWORD *)(a1 + 88) = 0;
        v25 = *v23;
        *(_DWORD *)(a1 + 64) = v25;
        *(_DWORD *)(a1 + 64) = *(_DWORD *)(a1 + 76) & (v23[1] ^ (v25 << v24));
        goto LABEL_24;
      }
      *(_DWORD *)(a1 + 88) = v12 - 1;
      do
      {
        v16 = *(_DWORD *)(a1 + 48);
        v17 = *(_DWORD *)(a1 + 64);
        v18 = *(_DWORD *)(a1 + 100) + 1;
        *(_DWORD *)(a1 + 100) = v18;
        v19 = *(_DWORD *)(a1 + 60);
        v20 = *(_DWORD *)(a1 + 76) & ((v17 << *(_DWORD *)(a1 + 80)) ^ *(unsigned __int8 *)(v18 + v16 + 2));
        HIWORD(v2) = 0;
        *(_DWORD *)(a1 + 64) = v20;
        LOWORD(v2) = *(_WORD *)(v19 + 2 * v20);
        *(_WORD *)(*(_DWORD *)(a1 + 56) + 2 * (*(_DWORD *)(a1 + 44) & v18)) = v2;
        *(_WORD *)(*(_DWORD *)(a1 + 60) + 2 * *(_DWORD *)(a1 + 64)) = *(_WORD *)(a1 + 100);
        v21 = *(_DWORD *)(a1 + 88) - 1;
        *(_DWORD *)(a1 + 88) = v21;
      }
      while ( v21 != 0 );
    }
    ++*(_DWORD *)(a1 + 100);
LABEL_24:
    if ( v14 )
    {
      v27 = *(_DWORD *)(a1 + 84);
      v28 = v27 < 0 ? 0 : v27 + *(_DWORD *)(a1 + 48);
      _tr_flush_block(a1, a2: v28, a3: *(_DWORD *)(a1 + 100) - v27, a4: 0);
      v32 = *(_DWORD *)a1;
      *(_DWORD *)(a1 + 84) = *(_DWORD *)(a1 + 100);
      sub_100319C0(a1: v32);
      if ( *(_DWORD *)(*(_DWORD *)a1 + 16) == 0 )
        return 0;
    }
  }
  v30 = *(_DWORD *)(a1 + 84);
  if ( v30 < 0 )
    v31 = 0;
  else
    v31 = v30 + *(_DWORD *)(a1 + 48);
  _tr_flush_block(a1, a2: v31, a3: *(_DWORD *)(a1 + 100) - v30, a4: a2 == 4);
  v33 = *(_DWORD *)a1;
  *(_DWORD *)(a1 + 84) = *(_DWORD *)(a1 + 100);
  sub_100319C0(a1: v33);
  if ( *(_DWORD *)(*(_DWORD *)a1 + 16) != 0 )
    return 2 * (a2 == 4) + 1;
  else
    return a2 != 4 ? 0 : 2;
}

//------------------------------------------------------------------------------
// Address: 0x100321D0
// Name: sub_100321D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_100321D0(_DWORD *a1, int a2)
{
  int v3; // esi
  unsigned int v4; // edx
  unsigned int v5; // ebp
  unsigned int v6; // eax
  _BYTE *v7; // ecx
  _BYTE *v8; // ebx
  _BYTE *v10; // edx
  char v11; // al
  _BYTE *v12; // edx
  _BYTE *v13; // ecx
  _BYTE *v14; // edx
  char v15; // al
  _BYTE *v16; // edx
  char v17; // al
  _BYTE *v18; // edx
  char v19; // al
  _BYTE *v20; // edx
  char v21; // al
  _BYTE *v22; // edx
  char v23; // al
  _BYTE *v24; // edx
  char v25; // al
  _BYTE *v26; // edx
  char v27; // al
  _BYTE *v28; // edx
  char v29; // al
  _BYTE *v30; // edx
  int v31; // edx
  unsigned int result; // eax
  char v33; // [esp+13h] [ebp-11h]
  unsigned int v34; // [esp+14h] [ebp-10h]
  int v35; // [esp+18h] [ebp-Ch]
  unsigned int v36; // [esp+1Ch] [ebp-8h]
  unsigned int v37; // [esp+20h] [ebp-4h]
  char v38; // [esp+28h] [ebp+4h]

  v3 = a1[9];
  v4 = a1[25];
  v5 = a1[28];
  v34 = a1[29];
  v6 = a1[34];
  v7 = (_BYTE *)(v4 + a1[12]);
  v35 = v6;
  if ( v4 <= v3 - 262 )
    v36 = 0;
  else
    v36 = v4 - v3 + 262;
  v8 = v7 + 258;
  v38 = v7[v5 - 1];
  v33 = v7[v5];
  if ( v5 >= a1[33] )
    v34 >>= 2;
  v37 = a1[27];
  if ( v6 > v37 )
    v35 = a1[27];
  do
  {
    v10 = (_BYTE *)(a2 + a1[12]);
    if ( v10[v5] == v33 && v10[v5 - 1] == v38 && *v10 == *v7 )
    {
      v11 = v10[1];
      v12 = v10 + 1;
      if ( v11 == v7[1] )
      {
        v13 = v7 + 2;
        v14 = v12 + 1;
        do
        {
          v15 = *++v13;
          v16 = v14 + 1;
          if ( v15 != *v16 )
            break;
          v17 = *++v13;
          v18 = v16 + 1;
          if ( v17 != *v18 )
            break;
          v19 = *++v13;
          v20 = v18 + 1;
          if ( v19 != *v20 )
            break;
          v21 = *++v13;
          v22 = v20 + 1;
          if ( v21 != *v22 )
            break;
          v23 = *++v13;
          v24 = v22 + 1;
          if ( v23 != *v24 )
            break;
          v25 = *++v13;
          v26 = v24 + 1;
          if ( v25 != *v26 )
            break;
          v27 = *++v13;
          v28 = v26 + 1;
          if ( v27 != *v28 )
            break;
          v29 = *++v13;
          v14 = v28 + 1;
          if ( v29 != *v14 )
            break;
        }
        while ( v13 < v8 );
        v30 = v13;
        v7 = v8 - 258;
        v31 = v30 - v8 + 258;
        if ( v31 > (int)v5 )
        {
          a1[26] = a2;
          v5 = v31;
          if ( v31 >= v35 )
            break;
          v38 = v7[v31 - 1];
          v33 = v7[v31];
        }
      }
    }
    a2 = *(unsigned __int16 *)(a1[14] + 2 * (a2 & a1[11]));
    if ( (unsigned __int16)a2 <= v36 )
      break;
    --v34;
  }
  while ( v34 != 0 );
  result = v37;
  if ( v5 <= v37 )
    return v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10032340
// Name: sub_10032340
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10032340(_DWORD *a1, int a2)
{
  int v3; // edi
  unsigned int v4; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  unsigned int v9; // edx
  int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ebp
  __int16 v14; // ax
  unsigned __int16 v15; // ax
  int v16; // eax
  int v17; // eax
  BOOL v18; // ebx
  unsigned int v19; // edx
  int v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // ecx
  int v24; // edx
  int v25; // eax
  int v26; // eax
  unsigned __int8 v28; // al
  int v29; // ecx
  int v30; // eax
  int v31; // ecx
  int v32; // edx
  int v33; // ecx
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  int v37; // [esp-14h] [ebp-2Ch]
  int v38; // [esp-14h] [ebp-2Ch]
  int v39; // [esp-14h] [ebp-2Ch]
  unsigned __int8 v40; // [esp+1Ch] [ebp+4h]
  unsigned __int8 v41; // [esp+20h] [ebp+8h]

  v3 = 0;
  while ( 1 )
  {
    v4 = a1[27];
    if ( v4 < 0x106 )
    {
      sub_10031CE0((int)a1);
      v4 = a1[27];
      if ( v4 < 0x106 && a2 == 0 )
        return 0;
      if ( v4 == 0 )
        break;
    }
    if ( v4 >= 3 )
    {
      v6 = a1[25];
      v7 = a1[15];
      v8 = a1[19] & (*(unsigned __int8 *)(a1[12] + v6 + 2) ^ (a1[16] << a1[20]));
      HIWORD(v3) = 0;
      a1[16] = v8;
      LOWORD(v3) = *(_WORD *)(v7 + 2 * v8);
      *(_WORD *)(a1[14] + 2 * (v6 & a1[11])) = v3;
      *(_WORD *)(a1[15] + 2 * a1[16]) = *((_WORD *)a1 + 50);
    }
    v9 = a1[22];
    v10 = a1[26];
    a1[28] = v9;
    a1[23] = v10;
    a1[22] = 2;
    if ( v3 != 0 && v9 < a1[30] && a1[25] - v3 <= (unsigned int)(a1[9] - 262) )
    {
      if ( a1[32] != 2 )
        a1[22] = sub_100321D0(a1, a2: v3);
      v11 = a1[22];
      if ( v11 <= 5 && (a1[32] == 1 || v11 == 3 && (unsigned int)(a1[25] - a1[26]) > 0x1000) )
        a1[22] = 2;
    }
    v12 = a1[28];
    if ( v12 < 3 || a1[22] > v12 )
    {
      if ( a1[24] != 0 )
      {
        v28 = *(_BYTE *)(a1[25] + a1[12] - 1);
        *(_WORD *)(a1[1447] + 2 * a1[1446]) = 0;
        *(_BYTE *)(a1[1444] + a1[1446]++) = v28;
        ++LOWORD(a1[v28 + 35]);
        if ( a1[1446] == a1[1445] - 1 )
        {
          v29 = a1[21];
          if ( v29 < 0 )
            v30 = 0;
          else
            v30 = v29 + a1[12];
          _tr_flush_block(a1, a2: v30, a3: a1[25] - v29, a4: 0);
          v38 = *a1;
          a1[21] = a1[25];
          sub_100319C0(a1: v38);
        }
        v31 = a1[27] - 1;
        ++a1[25];
        v32 = *a1;
        a1[27] = v31;
        v26 = *(_DWORD *)(v32 + 16);
        goto LABEL_32;
      }
      v33 = a1[25] + 1;
      v34 = a1[27] - 1;
      a1[24] = 1;
      a1[25] = v33;
      a1[27] = v34;
    }
    else
    {
      v13 = a1[25] + a1[27] - 3;
      v14 = a1[25] - *((_WORD *)a1 + 46) - 1;
      v40 = *((_BYTE *)a1 + 112) - 3;
      *(_WORD *)(a1[1447] + 2 * a1[1446]) = v14;
      v15 = v14 - 1;
      *(_BYTE *)(a1[1444] + a1[1446]++) = v40;
      ++LOWORD(a1[(unsigned __int8)_length_code[v40] + 292]);
      if ( v15 >= 0x100u )
        v16 = (unsigned __int8)byte_10058A70[v15 >> 7];
      else
        v16 = (unsigned __int8)_dist_code[v15];
      ++LOWORD(a1[v16 + 608]);
      v17 = a1[28];
      v18 = a1[1446] == a1[1445] - 1;
      a1[27] += 1 - v17;
      a1[28] = v17 - 2;
      do
      {
        v19 = a1[25] + 1;
        a1[25] = v19;
        if ( v19 <= v13 )
        {
          v20 = a1[15];
          v21 = a1[19] & (*(unsigned __int8 *)(a1[12] + v19 + 2) ^ (a1[16] << a1[20]));
          HIWORD(v3) = 0;
          a1[16] = v21;
          LOWORD(v3) = *(_WORD *)(v20 + 2 * v21);
          *(_WORD *)(a1[14] + 2 * (v19 & a1[11])) = v3;
          *(_WORD *)(a1[15] + 2 * a1[16]) = *((_WORD *)a1 + 50);
        }
        v22 = a1[28] - 1;
        a1[28] = v22;
      }
      while ( v22 != 0 );
      v23 = a1[25] + 1;
      a1[24] = 0;
      a1[22] = 2;
      a1[25] = v23;
      if ( v18 )
      {
        v24 = a1[21];
        if ( v24 < 0 )
          v25 = 0;
        else
          v25 = v24 + a1[12];
        _tr_flush_block(a1, a2: v25, a3: v23 - v24, a4: 0);
        v37 = *a1;
        a1[21] = a1[25];
        sub_100319C0(a1: v37);
        v26 = *(_DWORD *)(*a1 + 16);
LABEL_32:
        if ( v26 == 0 )
          return 0;
      }
    }
  }
  if ( a1[24] != 0 )
  {
    v41 = *(_BYTE *)(a1[25] + a1[12] - 1);
    *(_WORD *)(a1[1447] + 2 * a1[1446]) = 0;
    *(_BYTE *)(a1[1444] + a1[1446]++) = v41;
    ++LOWORD(a1[v41 + 35]);
    a1[24] = 0;
  }
  v35 = a1[21];
  if ( v35 < 0 )
    v36 = 0;
  else
    v36 = v35 + a1[12];
  _tr_flush_block(a1, a2: v36, a3: a1[25] - v35, a4: a2 == 4);
  v39 = *a1;
  a1[21] = a1[25];
  sub_100319C0(a1: v39);
  if ( *(_DWORD *)(*a1 + 16) != 0 )
    return 2 * (a2 == 4) + 1;
  else
    return a2 != 4 ? 0 : 2;
}

//------------------------------------------------------------------------------
// Address: 0x10032770
// Name: _inflateReset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateReset(_DWORD *a1)
{
  _DWORD *v1; // ecx

  if ( a1 == nullptr )
    return -2;
  v1 = (_DWORD *)a1[7];
  if ( v1 == nullptr )
    return -2;
  a1[5] = 0;
  a1[2] = 0;
  a1[6] = 0;
  *v1 = v1[3] != 0 ? 7 : 0;
  inflate_blocks_reset(a1: *(_DWORD *)(a1[7] + 20), a2: a1, a3: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100327C0
// Name: _inflateEnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateEnd(_DWORD *a1)
{
  int v1; // eax
  int v2; // eax

  if ( a1 == nullptr )
    return -2;
  v1 = a1[7];
  if ( v1 == 0 || a1[9] == 0 )
    return -2;
  v2 = *(_DWORD *)(v1 + 20);
  if ( v2 != 0 )
    inflate_blocks_free(a1: v2, a2: a1);
  ((void (__cdecl *)(_DWORD, _DWORD))a1[9])(a1: a1[10], a2: a1[7]);
  a1[7] = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10032810
// Name: _inflateInit2_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateInit2_(_DWORD *a1, int a2, _BYTE *a3, int a4)
{
  int v5; // eax
  int v6; // eax
  int v7; // ecx

  if ( a3 == nullptr || *a3 != a113_0[0] || a4 != 56 )
    return -6;
  if ( a1 == nullptr )
    return -2;
  v5 = a1[8];
  a1[6] = 0;
  if ( v5 == 0 )
  {
    a1[8] = zcalloc;
    a1[10] = 0;
  }
  if ( a1[9] == 0 )
    a1[9] = zcfree;
  v6 = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: 1, a3: 24);
  a1[7] = v6;
  if ( v6 == 0 )
    return -4;
  v7 = a2;
  *(_DWORD *)(v6 + 20) = 0;
  *(_DWORD *)(a1[7] + 12) = 0;
  if ( a2 < 0 )
  {
    v7 = -a2;
    *(_DWORD *)(a1[7] + 12) = 1;
  }
  if ( v7 < 8 || v7 > 15 )
  {
    inflateEnd(a1);
    return -2;
  }
  else
  {
    *(_DWORD *)(a1[7] + 16) = v7;
    *(_DWORD *)(a1[7] + 20) = inflate_blocks_new(a1, a2: *(_DWORD *)(a1[7] + 12) == 0 ? adler32 : nullptr, a3: 1 << v7);
    if ( *(_DWORD *)(a1[7] + 20) != 0 )
    {
      inflateReset(a1);
      return 0;
    }
    else
    {
      inflateEnd(a1);
      return -4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032920
// Name: _inflateInit_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateInit_(_DWORD *a1, _BYTE *a2, int a3)
{
  return inflateInit2_(a1, a2: 15, a3: a2, a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10032940
// Name: _inflate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate(unsigned __int8 **a1, int a2)
{
  int v2; // edi
  unsigned int v3; // ebx
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // eax
  int v7; // ecx
  unsigned __int8 *v8; // edx
  unsigned __int8 *v9; // edx
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // ebx
  int v12; // ecx
  unsigned __int8 *v13; // eax
  int v14; // eax
  unsigned __int8 *v15; // eax
  unsigned __int8 *v16; // eax
  unsigned __int8 *v17; // edx
  unsigned __int8 *v18; // eax
  unsigned __int8 *v19; // ecx
  unsigned __int8 *v20; // eax
  unsigned __int8 *v21; // ecx
  unsigned __int8 *v22; // eax
  unsigned __int8 *v23; // ecx
  int v24; // edx
  unsigned __int8 *v25; // eax
  unsigned __int8 *v26; // eax
  unsigned __int8 *v27; // edx
  unsigned __int8 *v28; // eax
  unsigned __int8 *v30; // ecx
  unsigned __int8 *v31; // ecx
  unsigned __int8 *v32; // eax
  unsigned __int8 *v33; // edx
  unsigned __int8 *v34; // edx
  unsigned __int8 *v35; // eax
  unsigned __int8 *v36; // ecx
  unsigned __int8 *v37; // eax
  unsigned __int8 *v38; // ecx
  int v39; // edx
  unsigned __int8 *v40; // eax
  unsigned __int8 *v41; // eax
  unsigned __int8 *v42; // eax
  unsigned int v43; // [esp+18h] [ebp+8h]

  if ( a1 == nullptr || a1[7] == nullptr || *a1 == nullptr )
    return -2;
  v2 = -5;
  v3 = a2 != 4 ? 0 : 0xFFFFFFFB;
  v43 = v3;
  while ( 2 )
  {
    v4 = a1[7];
    switch ( *(_DWORD *)v4 )
    {
      case 0:
        v5 = a1[1];
        if ( v5 == nullptr )
          return v2;
        a1[1] = v5 - 1;
        v2 = v3;
        ++a1[2];
        *((_DWORD *)v4 + 1) = **a1;
        v6 = a1[7];
        v7 = *((_DWORD *)v6 + 1) & 0xF;
        ++*a1;
        if ( (_BYTE)v7 != 8 )
        {
          *(_DWORD *)v6 = 13;
          v8 = a1[7];
          a1[6] = (unsigned __int8 *)aUnknownCompres;
          *((_DWORD *)v8 + 1) = 5;
          continue;
        }
        if ( (unsigned int)((*((_DWORD *)v6 + 1) >> 4) + 8) > *((_DWORD *)v6 + 4) )
        {
          *(_DWORD *)v6 = 13;
          v9 = a1[7];
          a1[6] = (unsigned __int8 *)aInvalidWindowS;
          *((_DWORD *)v9 + 1) = 5;
          continue;
        }
        *(_DWORD *)v6 = 1;
LABEL_12:
        v10 = a1[1];
        if ( v10 == nullptr )
          return v2;
        a1[1] = v10 - 1;
        v2 = v3;
        v11 = a1[7];
        ++a1[2];
        v12 = *(*a1)++;
        if ( (v12 + (*((_DWORD *)v11 + 1) << 8)) % 0x1Fu != 0 )
        {
          *(_DWORD *)v11 = 13;
          v13 = a1[7];
          v3 = v43;
          a1[6] = (unsigned __int8 *)aIncorrectHeade;
          *((_DWORD *)v13 + 1) = 5;
          continue;
        }
        if ( (v12 & 0x20) == 0 )
        {
          *(_DWORD *)v11 = 7;
          v3 = v43;
          continue;
        }
        v3 = v43;
        *(_DWORD *)a1[7] = 2;
LABEL_35:
        v28 = a1[1];
        if ( v28 == nullptr )
          return v2;
        v30 = *a1;
        ++a1[2];
        a1[1] = v28 - 1;
        v2 = v3;
        *((_DWORD *)a1[7] + 2) = *v30 << 24;
        v31 = a1[7];
        ++*a1;
        *(_DWORD *)v31 = 3;
LABEL_38:
        v32 = a1[1];
        if ( v32 == nullptr )
          return v2;
        v33 = *a1;
        a1[1] = v32 - 1;
        ++a1[2];
        v2 = v3;
        *((_DWORD *)a1[7] + 2) += *v33 << 16;
        v34 = a1[7];
        ++*a1;
        *(_DWORD *)v34 = 4;
LABEL_41:
        v35 = a1[1];
        if ( v35 == nullptr )
          return v2;
        v36 = *a1;
        a1[1] = v35 - 1;
        ++a1[2];
        v2 = v3;
        *((_DWORD *)a1[7] + 2) += *v36 << 8;
        ++*a1;
        *(_DWORD *)a1[7] = 5;
LABEL_44:
        v37 = a1[1];
        if ( v37 == nullptr )
          return v2;
        v38 = *a1;
        v39 = (int)(a1[2] + 1);
        a1[1] = v37 - 1;
        v40 = a1[7];
        a1[2] = (unsigned __int8 *)v39;
        *((_DWORD *)v40 + 2) += *v38;
        ++*a1;
        v41 = a1[7];
        a1[12] = *((unsigned __int8 **)v41 + 2);
        *(_DWORD *)v41 = 6;
        return 2;
      case 1:
        goto LABEL_12;
      case 2:
        goto LABEL_35;
      case 3:
        goto LABEL_38;
      case 4:
        goto LABEL_41;
      case 5:
        goto LABEL_44;
      case 6:
        *(_DWORD *)a1[7] = 13;
        v42 = a1[7];
        a1[6] = (unsigned __int8 *)aNeedDictionary;
        *((_DWORD *)v42 + 1) = 0;
        return -2;
      case 7:
        v14 = inflate_blocks(a1: *((_DWORD *)v4 + 5), a2: a1, a3: v2);
        v2 = v14;
        if ( v14 == -3 )
        {
          *(_DWORD *)a1[7] = 13;
          *((_DWORD *)a1[7] + 1) = 0;
        }
        else
        {
          if ( v14 == 0 )
            v2 = v3;
          if ( v2 != 1 )
            return v2;
          v2 = v3;
          inflate_blocks_reset(a1: *((_DWORD *)a1[7] + 5), a2: a1, a3: a1[7] + 4);
          v15 = a1[7];
          if ( *((_DWORD *)v15 + 3) != 0 )
          {
            *(_DWORD *)v15 = 12;
          }
          else
          {
            *(_DWORD *)v15 = 8;
LABEL_25:
            v16 = a1[1];
            if ( v16 == nullptr )
              return v2;
            v17 = a1[7];
            a1[1] = v16 - 1;
            ++a1[2];
            v2 = v3;
            *((_DWORD *)v17 + 2) = *(*a1)++ << 24;
            *(_DWORD *)a1[7] = 9;
LABEL_27:
            v18 = a1[1];
            if ( v18 == nullptr )
              return v2;
            v19 = *a1;
            ++a1[2];
            a1[1] = v18 - 1;
            v2 = v3;
            *((_DWORD *)a1[7] + 2) += *v19 << 16;
            ++*a1;
            *(_DWORD *)a1[7] = 10;
LABEL_29:
            v20 = a1[1];
            if ( v20 == nullptr )
              return v2;
            v21 = *a1;
            ++a1[2];
            a1[1] = v20 - 1;
            v2 = v3;
            *((_DWORD *)a1[7] + 2) += *v21 << 8;
            ++*a1;
            *(_DWORD *)a1[7] = 11;
LABEL_31:
            v22 = a1[1];
            if ( v22 == nullptr )
              return v2;
            v23 = *a1;
            v24 = (int)(a1[2] + 1);
            a1[1] = v22 - 1;
            v25 = a1[7];
            a1[2] = (unsigned __int8 *)v24;
            v2 = v3;
            *((_DWORD *)v25 + 2) += *v23;
            ++*a1;
            v26 = a1[7];
            if ( *((_DWORD *)v26 + 1) == *((_DWORD *)v26 + 2) )
            {
              *(_DWORD *)a1[7] = 12;
              return 1;
            }
            *(_DWORD *)v26 = 13;
            v27 = a1[7];
            a1[6] = (unsigned __int8 *)aIncorrectDataC;
            *((_DWORD *)v27 + 1) = 5;
          }
        }
        continue;
      case 8:
        goto LABEL_25;
      case 9:
        goto LABEL_27;
      case 0xA:
        goto LABEL_29;
      case 0xB:
        goto LABEL_31;
      case 0xC:
        return 1;
      case 0xD:
        return -3;
      default:
        return -2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032D70
// Name: _zcalloc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl zcalloc(int a1, unsigned int count, unsigned int size)
{
  return calloc(count, size);
}

//------------------------------------------------------------------------------
// Address: 0x10032D90
// Name: _zcfree
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl zcfree(int a1, void *pMem)
{
  free(pMem);
}

//------------------------------------------------------------------------------
// Address: 0x10032DA0
// Name: _adler32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl adler32(unsigned int a1, unsigned __int8 *a2, unsigned int a3)
{
  unsigned __int8 *v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // edi
  unsigned int i; // ebx
  int v8; // eax
  unsigned int v9; // ebp
  int v10; // edx
  int v11; // ecx
  int v12; // edi
  int v13; // ecx
  int v14; // edi
  int v15; // ecx
  int v16; // edi
  int v17; // ecx
  int v18; // edi
  int v19; // ecx
  int v20; // edi
  int v21; // ecx
  int v22; // edi
  int v23; // ecx
  int v24; // edi
  int v25; // ecx
  int v26; // edi
  int v27; // ecx
  int v28; // edi
  int v29; // ecx
  int v30; // edi
  int v31; // ecx
  int v32; // edi
  int v33; // ecx
  int v34; // edi
  int v35; // ecx
  int v36; // edi
  int v37; // ecx
  int v38; // edi
  int v39; // ecx
  int v40; // edi

  v3 = a2;
  v4 = (unsigned __int16)a1;
  v5 = HIWORD(a1);
  if ( a2 == nullptr )
    return 1;
  for ( i = a3; i != 0; v5 %= 0xFFF1u )
  {
    v8 = i;
    if ( i >= 0x15B0 )
      v8 = 5552;
    i -= v8;
    if ( v8 >= 16 )
    {
      v9 = (unsigned int)v8 >> 4;
      v8 += -16 * ((unsigned int)v8 >> 4);
      do
      {
        v10 = *v3;
        v3 += 16;
        v11 = v10 + v4;
        v12 = v11 + v5;
        v13 = *(v3 - 15) + v11;
        v14 = v13 + v12;
        v15 = *(v3 - 14) + v13;
        v16 = v15 + v14;
        v17 = *(v3 - 13) + v15;
        v18 = v17 + v16;
        v19 = *(v3 - 12) + v17;
        v20 = v19 + v18;
        v21 = *(v3 - 11) + v19;
        v22 = v21 + v20;
        v23 = *(v3 - 10) + v21;
        v24 = v23 + v22;
        v25 = *(v3 - 9) + v23;
        v26 = v25 + v24;
        v27 = *(v3 - 8) + v25;
        v28 = v27 + v26;
        v29 = *(v3 - 7) + v27;
        v30 = v29 + v28;
        v31 = *(v3 - 6) + v29;
        v32 = v31 + v30;
        v33 = *(v3 - 5) + v31;
        v34 = v33 + v32;
        v35 = *(v3 - 4) + v33;
        v36 = v35 + v34;
        v37 = *(v3 - 3) + v35;
        v38 = v37 + v36;
        v39 = *(v3 - 2) + v37;
        v40 = v39 + v38;
        v4 = *(v3 - 1) + v39;
        v5 = v4 + v40;
        --v9;
      }
      while ( v9 != 0 );
    }
    for ( ; v8 != 0; --v8 )
    {
      v4 += *v3++;
      v5 += v4;
    }
    v4 %= 0xFFF1u;
  }
  return v4 | (v5 << 16);
}

//------------------------------------------------------------------------------
// Address: 0x10032ED0
// Name: __tr_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tr_init(int a1)
{
  nullsub_4();
  *(_DWORD *)(a1 + 2832) = a1 + 140;
  *(_DWORD *)(a1 + 2856) = a1 + 2676;
  *(_DWORD *)(a1 + 2840) = &off_100619EC;
  *(_DWORD *)(a1 + 2844) = a1 + 2432;
  *(_DWORD *)(a1 + 2852) = &off_10061A00;
  *(_DWORD *)(a1 + 2864) = &unk_10061A14;
  *(_WORD *)(a1 + 5808) = 0;
  *(_DWORD *)(a1 + 5812) = 0;
  *(_DWORD *)(a1 + 5804) = 8;
  return sub_10032F50(a1);
}

//------------------------------------------------------------------------------
// Address: 0x10032F40
// Name: nullsub_4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_4()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10032F50
// Name: sub_10032F50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_WORD *__cdecl sub_10032F50(int a1)
{
  int v1; // ecx
  _WORD *v2; // eax
  _WORD *v3; // eax
  int i; // ecx
  _WORD *result; // eax
  int j; // ecx

  v1 = 286;
  v2 = (_WORD *)(a1 + 140);
  do
  {
    *v2 = 0;
    v2 += 2;
    --v1;
  }
  while ( v1 != 0 );
  v3 = (_WORD *)(a1 + 2432);
  for ( i = 30; i != 0; --i )
  {
    *v3 = 0;
    v3 += 2;
  }
  result = (_WORD *)(a1 + 2676);
  for ( j = 19; j != 0; --j )
  {
    *result = 0;
    result += 2;
  }
  *(_DWORD *)(a1 + 5796) = 0;
  *(_DWORD *)(a1 + 5792) = 0;
  *(_DWORD *)(a1 + 5800) = 0;
  *(_DWORD *)(a1 + 5784) = 0;
  *(_WORD *)(a1 + 1164) = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10032FC0
// Name: __tr_stored_block
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tr_stored_block(int a1, int a2, int a3, int a4)
{
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  char v8; // bl
  int v9; // ecx
  int v10; // edx

  v4 = *(_DWORD *)(a1 + 5812);
  if ( v4 <= 13 )
  {
    *(_WORD *)(a1 + 5808) |= a4 << v4;
    *(_DWORD *)(a1 + 5812) = v4 + 3;
  }
  else
  {
    v5 = a4 << v4;
    v6 = *(_DWORD *)(a1 + 8);
    *(_WORD *)(a1 + 5808) |= v5;
    *(_BYTE *)(v6 + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v7 = *(_DWORD *)(a1 + 8);
    v8 = *(_BYTE *)(a1 + 5809);
    v9 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v9;
    *(_BYTE *)(v9 + v7) = v8;
    v10 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v10 - 13;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)a4 >> (16 - v10);
  }
  return sub_10034880(a1, a2, a3, a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10033060
// Name: __tr_align
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tr_align(int a1)
{
  int v1; // ecx
  char v2; // dl
  int v3; // ecx
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  char v8; // dl
  int v9; // ecx
  int result; // eax
  int v11; // ecx
  char v12; // dl
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  char v18; // dl
  int v19; // ecx

  v1 = *(_DWORD *)(a1 + 5812);
  *(_WORD *)(a1 + 5808) |= 2 << v1;
  if ( v1 <= 13 )
  {
    *(_DWORD *)(a1 + 5812) = v1 + 3;
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v2 = *(_BYTE *)(a1 + 5809);
    v3 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v3;
    *(_BYTE *)(v3 + *(_DWORD *)(a1 + 8)) = v2;
    ++*(_DWORD *)(a1 + 20);
    v4 = *(_DWORD *)(a1 + 5812);
    *(_DWORD *)(a1 + 5812) = v4 - 13;
    *(_WORD *)(a1 + 5808) = 2u >> (16 - v4);
  }
  v5 = *(_DWORD *)(a1 + 5812);
  if ( v5 <= 9 )
  {
    *(_WORD *)(a1 + 5808) = *(_WORD *)(a1 + 5808);
    *(_DWORD *)(a1 + 5812) = v5 + 7;
  }
  else
  {
    v6 = *(_DWORD *)(a1 + 8);
    v7 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) = *(_WORD *)(a1 + 5808);
    *(_BYTE *)(v6 + v7) = *(_BYTE *)(a1 + 5808);
    v8 = *(_BYTE *)(a1 + 5809);
    v9 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v9;
    *(_BYTE *)(v9 + *(_DWORD *)(a1 + 8)) = v8;
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) -= 9;
    *(_WORD *)(a1 + 5808) = 0;
  }
  result = sub_10034770(a1);
  v11 = *(_DWORD *)(a1 + 5812);
  if ( *(_DWORD *)(a1 + 5804) - v11 + 11 < 9 )
  {
    *(_WORD *)(a1 + 5808) |= 2 << v11;
    if ( v11 <= 13 )
    {
      *(_DWORD *)(a1 + 5812) = v11 + 3;
    }
    else
    {
      *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
      v12 = *(_BYTE *)(a1 + 5809);
      v13 = *(_DWORD *)(a1 + 20) + 1;
      *(_DWORD *)(a1 + 20) = v13;
      *(_BYTE *)(v13 + *(_DWORD *)(a1 + 8)) = v12;
      ++*(_DWORD *)(a1 + 20);
      v14 = *(_DWORD *)(a1 + 5812);
      *(_DWORD *)(a1 + 5812) = v14 - 13;
      *(_WORD *)(a1 + 5808) = 2u >> (16 - v14);
    }
    v15 = *(_DWORD *)(a1 + 5812);
    if ( v15 <= 9 )
    {
      *(_WORD *)(a1 + 5808) = *(_WORD *)(a1 + 5808);
      *(_DWORD *)(a1 + 5812) = v15 + 7;
    }
    else
    {
      v16 = *(_DWORD *)(a1 + 8);
      v17 = *(_DWORD *)(a1 + 20);
      *(_WORD *)(a1 + 5808) = *(_WORD *)(a1 + 5808);
      *(_BYTE *)(v16 + v17) = *(_BYTE *)(a1 + 5808);
      v18 = *(_BYTE *)(a1 + 5809);
      v19 = *(_DWORD *)(a1 + 20) + 1;
      *(_DWORD *)(a1 + 20) = v19;
      *(_BYTE *)(v19 + *(_DWORD *)(a1 + 8)) = v18;
      ++*(_DWORD *)(a1 + 20);
      *(_DWORD *)(a1 + 5812) -= 9;
      *(_WORD *)(a1 + 5808) = 0;
    }
    result = sub_10034770(a1);
  }
  *(_DWORD *)(a1 + 5804) = 7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10033270
// Name: __tr_flush_block
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_WORD *__cdecl _tr_flush_block(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // ecx
  int v7; // edi
  bool v8; // zf
  int v9; // ecx
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  char v13; // bl
  int v14; // edx
  int v15; // edx
  int v16; // edx
  int v17; // ebx
  int v18; // ecx
  int v19; // ebx
  char v20; // al
  int v21; // ecx
  int v22; // ebx
  _WORD *result; // eax
  int v24; // [esp+20h] [ebp+10h]

  v4 = 0;
  if ( *(int *)(a1 + 124) <= 0 )
  {
    v6 = a3 + 5;
LABEL_7:
    v5 = v6;
    goto LABEL_8;
  }
  if ( *(_BYTE *)(a1 + 28) == 2 )
    sub_100346D0(a1);
  sub_10033460(a1, a2: a1 + 2832);
  sub_10033460(a1, a2: a1 + 2844);
  v4 = sub_100339F0(a1);
  v5 = (unsigned int)(*(_DWORD *)(a1 + 5792) + 10) >> 3;
  v6 = (unsigned int)(*(_DWORD *)(a1 + 5796) + 10) >> 3;
  if ( v6 <= v5 )
    goto LABEL_7;
LABEL_8:
  if ( a3 + 4 <= v5 && a2 != 0 )
  {
    v7 = a4;
    _tr_stored_block(a1, a2, a3, a4);
  }
  else
  {
    v7 = a4;
    v8 = v6 == v5;
    v9 = *(_DWORD *)(a1 + 5812);
    if ( v8 )
    {
      v10 = a4 + 2;
      if ( v9 <= 13 )
      {
        *(_WORD *)(a1 + 5808) |= v10 << v9;
        *(_DWORD *)(a1 + 5812) = v9 + 3;
      }
      else
      {
        v11 = v10 << v9;
        v12 = *(_DWORD *)(a1 + 8);
        *(_WORD *)(a1 + 5808) |= v11;
        *(_BYTE *)(v12 + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
        v13 = *(_BYTE *)(a1 + 5809);
        v14 = *(_DWORD *)(a1 + 20) + 1;
        *(_DWORD *)(a1 + 20) = v14;
        *(_BYTE *)(v14 + *(_DWORD *)(a1 + 8)) = v13;
        v15 = *(_DWORD *)(a1 + 5812);
        ++*(_DWORD *)(a1 + 20);
        *(_DWORD *)(a1 + 5812) = v15 - 13;
        *(_WORD *)(a1 + 5808) = (unsigned __int16)v10 >> (16 - v15);
      }
      sub_100342C0(a1, a2: &unk_10058478, a3: &unk_100588F8);
    }
    else
    {
      v16 = a4 + 4;
      if ( v9 <= 13 )
      {
        *(_WORD *)(a1 + 5808) |= v16 << v9;
        *(_DWORD *)(a1 + 5812) = v9 + 3;
      }
      else
      {
        v24 = v4;
        v17 = v16 << v9;
        v18 = *(_DWORD *)(a1 + 8);
        *(_WORD *)(a1 + 5808) |= v17;
        *(_BYTE *)(v18 + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
        v19 = *(_DWORD *)(a1 + 8);
        v20 = *(_BYTE *)(a1 + 5809);
        v21 = *(_DWORD *)(a1 + 20) + 1;
        *(_DWORD *)(a1 + 20) = v21;
        *(_BYTE *)(v21 + v19) = v20;
        v22 = *(_DWORD *)(a1 + 5812);
        ++*(_DWORD *)(a1 + 20);
        v4 = v24;
        *(_DWORD *)(a1 + 5812) = v22 - 13;
        *(_WORD *)(a1 + 5808) = (unsigned __int16)v16 >> (16 - v22);
      }
      sub_10033B50(a1, a2: *(_DWORD *)(a1 + 2836) + 1, a3: *(_DWORD *)(a1 + 2848) + 1, a4: v4 + 1);
      sub_100342C0(a1, a2: a1 + 140, a3: a1 + 2432);
    }
  }
  result = sub_10032F50(a1);
  if ( v7 != 0 )
    return (_WORD *)sub_10034800(a1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10033460
// Name: sub_10033460
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10033460(_DWORD *a1, int *a2)
{
  int v3; // edi
  int *v4; // eax
  int v5; // ebp
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int i; // ebx
  int v14; // eax
  int v15; // ebx
  int v16; // ebp
  int v17; // edx
  int v18; // ecx
  char v19; // cl
  int v20; // ecx
  int v21; // edx
  int v23; // [esp+10h] [ebp-8h]
  int v24; // [esp+14h] [ebp-4h]
  int v25; // [esp+1Ch] [ebp+4h]

  v3 = *a2;
  v4 = (int *)a2[2];
  v5 = -1;
  v6 = *v4;
  v7 = v4[3];
  v8 = 0;
  v24 = v7;
  v23 = -1;
  a1[1298] = 0;
  for ( a1[1299] = 573; v8 < v7; ++v8 )
  {
    if ( *(_WORD *)(v3 + 4 * v8) != 0 )
    {
      v23 = v8;
      v9 = a1[1298] + 1;
      v5 = v8;
      a1[1298] = v9;
      a1[v9 + 725] = v8;
      v7 = v24;
      *((_BYTE *)a1 + v8 + 5200) = 0;
    }
    else
    {
      *(_WORD *)(v3 + 4 * v8 + 2) = 0;
    }
  }
  v10 = a1[1298];
  if ( v10 < 2 )
  {
    do
    {
      if ( v5 >= 2 )
        v11 = 0;
      else
        v11 = ++v5;
      v12 = v10 + 1;
      a1[1298] = v12;
      a1[v12 + 725] = v11;
      *(_WORD *)(v3 + 4 * v11) = 1;
      *((_BYTE *)a1 + v11 + 5200) = 0;
      --a1[1448];
      if ( v6 != 0 )
        a1[1449] -= *(unsigned __int16 *)(v6 + 4 * v11 + 2);
      v10 = a1[1298];
    }
    while ( v10 < 2 );
    v23 = v5;
  }
  a2[1] = v5;
  for ( i = a1[1298] / 2; i >= 1; --i )
    sub_10033680(a1, a2: v3, a3: i);
  v25 = v24;
  do
  {
    v14 = a1[1298];
    v15 = a1[726];
    a1[726] = a1[v14 + 725];
    a1[1298] = v14 - 1;
    sub_10033680(a1, a2: v3, a3: 1);
    v16 = a1[726];
    v17 = a1[1299] - 1;
    a1[1299] = v17;
    a1[v17 + 725] = v15;
    v18 = a1[1299] - 1;
    a1[1299] = v18;
    a1[v18 + 725] = v16;
    *(_WORD *)(v3 + 4 * v25) = *(_WORD *)(v3 + 4 * v15) + *(_WORD *)(v3 + 4 * v16);
    if ( *((_BYTE *)a1 + v15 + 5200) < *((_BYTE *)a1 + v16 + 5200) )
      v19 = *((_BYTE *)a1 + v16 + 5200);
    else
      v19 = *((_BYTE *)a1 + v15 + 5200);
    *((_BYTE *)a1 + v25 + 5200) = v19 + 1;
    *(_WORD *)(v3 + 4 * v16 + 2) = v25;
    *(_WORD *)(v3 + 4 * v15 + 2) = v25;
    a1[726] = v25++;
    sub_10033680(a1, a2: v3, a3: 1);
  }
  while ( (int)a1[1298] >= 2 );
  v20 = a1[726];
  v21 = a1[1299] - 1;
  a1[1299] = v21;
  a1[v21 + 725] = v20;
  sub_10033760(a1, a2);
  return sub_10033970(a1: v3, a2: v23, a3: a1 + 717);
}

//------------------------------------------------------------------------------
// Address: 0x10033680
// Name: sub_10033680
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10033680(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // edx
  int v5; // ebp
  int v6; // ecx
  bool v7; // cc
  int v8; // esi
  int v9; // ebp
  unsigned __int16 v10; // dx
  unsigned __int16 v11; // bx
  int v12; // esi
  unsigned __int16 v13; // dx
  unsigned __int16 v14; // bx
  int v15; // edx
  int v16; // edx
  int v17; // [esp+14h] [ebp+4h]

  result = a1;
  v4 = *(_DWORD *)(a1 + 5192);
  v5 = *(_DWORD *)(a1 + 4 * a3 + 2900);
  v6 = 2 * a3;
  v7 = 2 * a3 < v4;
  v17 = v5;
  if ( 2 * a3 > v4 )
  {
    *(_DWORD *)(result + 4 * a3 + 2900) = v5;
  }
  else
  {
    while ( 1 )
    {
      if ( v7 )
      {
        v8 = *(_DWORD *)(result + 4 * v6 + 2904);
        v9 = *(_DWORD *)(result + 4 * v6 + 2900);
        v10 = *(_WORD *)(a2 + 4 * v8);
        v11 = *(_WORD *)(a2 + 4 * v9);
        if ( v10 < v11 || v10 == v11 && *(_BYTE *)(v8 + result + 5200) <= *(_BYTE *)(result + v9 + 5200) )
          ++v6;
        v5 = v17;
      }
      v12 = *(_DWORD *)(result + 4 * v6 + 2900);
      v13 = *(_WORD *)(a2 + 4 * v5);
      v14 = *(_WORD *)(a2 + 4 * v12);
      if ( v13 < v14 )
      {
LABEL_12:
        *(_DWORD *)(result + 4 * a3 + 2900) = v5;
        return result;
      }
      if ( v13 == v14 && *(_BYTE *)(result + v5 + 5200) <= *(_BYTE *)(v12 + result + 5200) )
        break;
      v15 = a3;
      a3 = v6;
      v6 *= 2;
      *(_DWORD *)(result + 4 * v15 + 2900) = v12;
      v16 = *(_DWORD *)(result + 5192);
      v7 = v6 < v16;
      if ( v6 > v16 )
        goto LABEL_12;
    }
    *(_DWORD *)(result + 4 * a3 + 2900) = v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10033760
// Name: sub_10033760
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 __cdecl sub_10033760(_DWORD *a1, int *a2)
{
  int v2; // ebp
  int *v3; // eax
  int v4; // ebx
  int v5; // esi
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ebx
  int v11; // edi
  bool v12; // zf
  _WORD *v13; // edi
  _WORD *i; // ecx
  int v15; // esi
  int v16; // ebx
  int v17; // ecx
  _WORD *v18; // edi
  int v19; // eax
  int v21; // [esp+10h] [ebp-18h]
  int v22; // [esp+14h] [ebp-14h]
  int v23; // [esp+18h] [ebp-10h]
  int v24; // [esp+1Ch] [ebp-Ch]
  int v25; // [esp+20h] [ebp-8h]
  int v26; // [esp+24h] [ebp-4h]
  int *v27; // [esp+2Ch] [ebp+4h]
  int v28; // [esp+2Ch] [ebp+4h]
  int v29; // [esp+30h] [ebp+8h]
  int v30; // [esp+30h] [ebp+8h]

  v2 = *a2;
  v3 = (int *)a2[2];
  v24 = a2[1];
  v4 = 0;
  v5 = *v3;
  v26 = v3[1];
  v25 = v3[2];
  v21 = v3[4];
  v29 = 0;
  memset(a1 + 717, 0, 0x20u);
  *(_WORD *)(v2 + 4 * a1[a1[1299] + 725] + 2) = 0;
  v7 = a1[1299] + 1;
  if ( v7 < 573 )
  {
    v27 = &a1[v7 + 725];
    v23 = 573 - v7;
    v22 = 573;
    do
    {
      v8 = *v27;
      v9 = *(unsigned __int16 *)(v2 + 4 * *(unsigned __int16 *)(v2 + 4 * *v27 + 2) + 2) + 1;
      if ( v9 > v21 )
      {
        ++v4;
        v9 = v21;
        v29 = v4;
      }
      *(_WORD *)(v2 + 4 * v8 + 2) = v9;
      if ( v8 <= v24 )
      {
        ++*((_WORD *)a1 + v9 + 1434);
        v10 = 0;
        if ( v8 >= v25 )
          v10 = *(_DWORD *)(v26 + 4 * (v8 - v25));
        v11 = *(unsigned __int16 *)(v2 + 4 * v8);
        a1[1448] += v11 * (v10 + v9);
        if ( v5 != 0 )
          a1[1449] += v11 * (v10 + *(unsigned __int16 *)(v5 + 4 * v8 + 2));
        v4 = v29;
      }
      LOWORD(v7) = v23 - 1;
      v12 = v23 == 1;
      ++v27;
      --v23;
    }
    while ( !v12 );
    if ( v4 != 0 )
    {
      v13 = (_WORD *)a1 + v21 + 1434;
      do
      {
        v7 = v21 - 1;
        for ( i = (_WORD *)a1 + v21 + 1433; *i == 0; --v7 )
          --i;
        --*((_WORD *)a1 + v7 + 1434);
        *((_WORD *)a1 + v7 + 1435) += 2;
        --*v13;
        v4 -= 2;
      }
      while ( v4 > 0 );
      v15 = v21;
      if ( v21 != 0 )
      {
        v28 = (int)a1 + 2 * v21 + 2868;
        do
        {
          v7 = (unsigned __int16)*v13;
          v30 = v7;
          if ( *v13 != 0 )
          {
            v16 = (int)&a1[v22 + 725];
            do
            {
              v17 = *(_DWORD *)(v16 - 4);
              v16 -= 4;
              --v22;
              if ( v17 <= v24 )
              {
                v18 = (_WORD *)(v2 + 4 * v17 + 2);
                HIWORD(v19) = 0;
                if ( (unsigned __int16)*v18 != v15 )
                {
                  LOWORD(v19) = *v18;
                  a1[1448] += *(unsigned __int16 *)(v2 + 4 * v17) * (v15 - v19);
                  *v18 = v15;
                }
                v7 = --v30;
              }
            }
            while ( v7 != 0 );
          }
          --v15;
          v13 = (_WORD *)(v28 - 2);
          v28 -= 2;
        }
        while ( v15 != 0 );
      }
    }
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10033970
// Name: sub_10033970
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 __cdecl sub_10033970(int a1, int a2, int a3)
{
  __int16 v3; // cx
  int i; // eax
  __int16 v5; // si
  int j; // esi
  unsigned __int16 v7; // dx
  _WORD v9[2]; // [esp+6h] [ebp-22h]
  char v10; // [esp+Ah] [ebp-1Eh] BYREF

  v3 = 0;
  for ( i = 1; i <= 15; v9[i] = 2 * v5 )
  {
    v5 = v3 + *(_WORD *)((char *)&v9[++i] + a3 - (_DWORD)&v10);
    v3 = 2 * v5;
  }
  for ( j = 0; j <= a2; ++j )
  {
    i = *(unsigned __int16 *)(a1 + 4 * j + 2);
    if ( (_WORD)i != 0 )
    {
      v7 = v9[i + 1];
      v9[i + 1] = v7 + 1;
      LOWORD(i) = sub_10034750(a1: v7, a2: i);
      *(_WORD *)(a1 + 4 * j) = i;
    }
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x100339F0
// Name: sub_100339F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_100339F0(_DWORD *a1)
{
  int result; // eax

  sub_10033A60(a1, a2: a1 + 35, a3: a1[709]);
  sub_10033A60(a1, a2: a1 + 608, a3: a1[712]);
  sub_10033460(a1, a2: a1 + 714);
  for ( result = 18; result >= 3; --result )
  {
    if ( HIWORD(a1[(unsigned __int8)byte_10058464[result] + 669]) != 0 )
      break;
  }
  a1[1448] += 3 * result + 17;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10033A60
// Name: sub_10033A60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10033A60(_WORD *a1, int a2, int a3)
{
  int result; // eax
  int v4; // ecx
  int v5; // edi
  int v6; // edx
  int v7; // esi
  unsigned __int16 *v8; // ebp
  int v9; // eax
  int v10; // [esp+Ch] [ebp-4h]
  int v11; // [esp+18h] [ebp+8h]

  result = a2;
  v4 = *(unsigned __int16 *)(a2 + 2);
  v5 = 0;
  v10 = -1;
  v6 = 7;
  v7 = 4;
  if ( (_WORD)v4 == 0 )
  {
    v6 = 138;
    v7 = 3;
  }
  *(_WORD *)(a2 + 4 * a3 + 6) = -1;
  if ( a3 >= 0 )
  {
    v11 = a3 + 1;
    v8 = (unsigned __int16 *)(result + 6);
    do
    {
      v9 = v4;
      v4 = *v8;
      if ( ++v5 >= v6 || v9 != v4 )
      {
        if ( v5 >= v7 )
        {
          if ( v9 != 0 )
          {
            if ( v9 != v10 )
              ++a1[2 * v9 + 1338];
            ++a1[1370];
          }
          else if ( v5 > 10 )
          {
            ++a1[1374];
          }
          else
          {
            ++a1[1372];
          }
        }
        else
        {
          a1[2 * v9 + 1338] += v5;
        }
        v5 = 0;
        v10 = v9;
        if ( v4 != 0 )
        {
          if ( v9 == v4 )
          {
            v6 = 6;
            v7 = 3;
          }
          else
          {
            v6 = 7;
            v7 = 4;
          }
        }
        else
        {
          v6 = 138;
          v7 = 3;
        }
      }
      v8 += 2;
      result = --v11;
    }
    while ( v11 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10033B50
// Name: sub_10033B50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10033B50(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  char v9; // bl
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // edx
  char v16; // bl
  int v17; // ecx
  int v18; // edx
  int v19; // ecx
  int v20; // eax
  int v21; // edx
  int v22; // ecx
  char v23; // bl
  int v24; // edx
  int v25; // edx
  int i; // edi
  int v27; // ecx
  int v28; // eax
  int v29; // edx
  int v30; // ecx
  char v31; // bl
  int v32; // edx
  int v33; // edx

  v4 = a2 - 257;
  v5 = *(_DWORD *)(a1 + 5812);
  if ( v5 <= 11 )
  {
    *(_WORD *)(a1 + 5808) |= v4 << v5;
    *(_DWORD *)(a1 + 5812) = v5 + 5;
  }
  else
  {
    v6 = v4 << v5;
    v7 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) |= v6;
    *(_BYTE *)(v7 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
    v8 = *(_DWORD *)(a1 + 8);
    v9 = *(_BYTE *)(a1 + 5809);
    v10 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v10;
    *(_BYTE *)(v10 + v8) = v9;
    v11 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v11 - 11;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)v4 >> (16 - v11);
  }
  v12 = *(_DWORD *)(a1 + 5812);
  if ( v12 <= 11 )
  {
    *(_WORD *)(a1 + 5808) |= (a3 - 1) << v12;
    *(_DWORD *)(a1 + 5812) = v12 + 5;
  }
  else
  {
    v13 = (a3 - 1) << v12;
    v14 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) |= v13;
    *(_BYTE *)(v14 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
    v15 = *(_DWORD *)(a1 + 8);
    v16 = *(_BYTE *)(a1 + 5809);
    v17 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v17;
    *(_BYTE *)(v17 + v15) = v16;
    v18 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v18 - 11;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)(a3 - 1) >> (16 - v18);
  }
  v19 = *(_DWORD *)(a1 + 5812);
  v20 = a4 - 4;
  if ( v19 <= 12 )
  {
    *(_WORD *)(a1 + 5808) |= v20 << v19;
    *(_DWORD *)(a1 + 5812) = v19 + 4;
  }
  else
  {
    v21 = v20 << v19;
    v22 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) |= v21;
    *(_BYTE *)(v22 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
    v23 = *(_BYTE *)(a1 + 5809);
    v24 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v24;
    *(_BYTE *)(v24 + *(_DWORD *)(a1 + 8)) = v23;
    v25 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v25 - 12;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)v20 >> (16 - v25);
  }
  for ( i = 0; i < a4; ++i )
  {
    v27 = *(_DWORD *)(a1 + 5812);
    v28 = 0;
    if ( v27 <= 13 )
    {
      LOBYTE(v28) = byte_10058464[i];
      *(_WORD *)(a1 + 5808) |= *(_WORD *)(a1 + 4 * v28 + 2678) << v27;
      *(_DWORD *)(a1 + 5812) = v27 + 3;
    }
    else
    {
      LOWORD(v28) = *(_WORD *)(a1 + 4 * (unsigned __int8)byte_10058464[i] + 2678);
      v29 = v28 << v27;
      v30 = *(_DWORD *)(a1 + 20);
      *(_WORD *)(a1 + 5808) |= v29;
      *(_BYTE *)(v30 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
      v31 = *(_BYTE *)(a1 + 5809);
      v32 = *(_DWORD *)(a1 + 20) + 1;
      *(_DWORD *)(a1 + 20) = v32;
      *(_BYTE *)(v32 + *(_DWORD *)(a1 + 8)) = v31;
      v33 = *(_DWORD *)(a1 + 5812);
      ++*(_DWORD *)(a1 + 20);
      *(_DWORD *)(a1 + 5812) = v33 - 13;
      *(_WORD *)(a1 + 5808) = (unsigned __int16)v28 >> (16 - v33);
    }
  }
  sub_10033DA0(a1, a2: a1 + 140, a3: a2 - 1);
  return sub_10033DA0(a1, a2: a1 + 2432, a3: a3 - 1);
}

//------------------------------------------------------------------------------
// Address: 0x10033DA0
// Name: sub_10033DA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10033DA0(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // ebx
  int v5; // esi
  int v6; // ecx
  int v7; // edx
  int v8; // edi
  int v9; // ebp
  int v10; // ecx
  int v11; // edi
  unsigned __int16 v12; // si
  int v13; // edx
  int v14; // ecx
  char v15; // bl
  int v16; // edx
  int v17; // edx
  int v18; // ecx
  int v19; // ecx
  int v20; // edi
  unsigned __int16 v21; // si
  int v22; // edx
  int v23; // ecx
  char v24; // bl
  int v25; // edx
  int v26; // edx
  int v27; // ecx
  int v28; // ecx
  int v29; // edi
  unsigned __int16 v30; // si
  int v31; // edx
  int v32; // ecx
  char v33; // bl
  int v34; // edx
  int v35; // edx
  int v36; // ecx
  int v37; // esi
  int v38; // edx
  int v39; // ecx
  char v40; // bl
  int v41; // edx
  int v42; // edx
  int v43; // ecx
  int v44; // ecx
  int v45; // edi
  unsigned __int16 v46; // si
  int v47; // edx
  int v48; // ecx
  char v49; // bl
  int v50; // edx
  int v51; // edx
  int v52; // ecx
  int v53; // esi
  int v54; // edx
  int v55; // ecx
  char v56; // bl
  int v57; // edx
  int v58; // edx
  unsigned __int16 v59; // si
  int v60; // edx
  int v61; // ecx
  char v62; // bl
  int v63; // edx
  int v64; // edx
  int v65; // ecx
  int v66; // esi
  int v67; // edx
  int v68; // ecx
  char v69; // bl
  int v70; // edx
  int v71; // edx
  bool v72; // zf
  int v73; // [esp+Ch] [ebp-8h]
  int v74; // [esp+10h] [ebp-4h]
  int v75; // [esp+18h] [ebp+4h]
  int v76; // [esp+1Ch] [ebp+8h]
  unsigned __int16 *v77; // [esp+20h] [ebp+Ch]

  result = a2;
  v4 = *(unsigned __int16 *)(a2 + 2);
  v5 = 0;
  v73 = -1;
  v6 = 7;
  v7 = 4;
  if ( (_WORD)v4 == 0 )
  {
    v6 = 138;
    v7 = 3;
  }
  if ( a3 >= 0 )
  {
    v8 = a3 + 1;
    v77 = (unsigned __int16 *)(a2 + 6);
    result = a1;
    v74 = v8;
    do
    {
      v9 = v4;
      ++v5;
      v4 = *v77;
      v75 = v4;
      v76 = v5;
      if ( v5 < v6 && v9 == v4 )
        goto LABEL_44;
      if ( v5 < v7 )
      {
        do
        {
          v10 = *(_DWORD *)(result + 5812);
          v11 = *(unsigned __int16 *)(result + 4 * v9 + 2678);
          if ( v10 <= 16 - (unsigned __int16)v11 )
          {
            *(_WORD *)(result + 5808) |= *(_WORD *)(result + 4 * v9 + 2676) << v10;
            v18 = v11 + v10;
          }
          else
          {
            v12 = *(_WORD *)(result + 4 * v9 + 2676);
            v13 = v12 << v10;
            v14 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v13;
            *(_BYTE *)(v14 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v15 = *(_BYTE *)(result + 5809);
            v16 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v16;
            *(_BYTE *)(v16 + *(_DWORD *)(result + 8)) = v15;
            v17 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v18 = v17 + v11 - 16;
            *(_WORD *)(result + 5808) = v12 >> (16 - v17);
            v5 = v76;
          }
          --v5;
          *(_DWORD *)(result + 5812) = v18;
          v76 = v5;
        }
        while ( v5 != 0 );
        goto LABEL_39;
      }
      if ( v9 != 0 )
      {
        if ( v9 != v73 )
        {
          v19 = *(_DWORD *)(result + 5812);
          v20 = *(unsigned __int16 *)(result + 4 * v9 + 2678);
          if ( v19 <= 16 - (unsigned __int16)v20 )
          {
            *(_WORD *)(result + 5808) |= *(_WORD *)(result + 4 * v9 + 2676) << v19;
            v27 = v20 + v19;
          }
          else
          {
            v21 = *(_WORD *)(result + 4 * v9 + 2676);
            v22 = v21 << v19;
            v23 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v22;
            *(_BYTE *)(v23 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v24 = *(_BYTE *)(result + 5809);
            v25 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v25;
            *(_BYTE *)(v25 + *(_DWORD *)(result + 8)) = v24;
            v26 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v27 = v26 + v20 - 16;
            *(_WORD *)(result + 5808) = v21 >> (16 - v26);
            v5 = v76;
          }
          --v5;
          *(_DWORD *)(result + 5812) = v27;
          v76 = v5;
        }
        v28 = *(_DWORD *)(result + 5812);
        v29 = *(unsigned __int16 *)(result + 2742);
        if ( v28 <= 16 - (unsigned __int16)v29 )
        {
          *(_WORD *)(result + 5808) |= *(_WORD *)(result + 2740) << v28;
          v36 = v29 + v28;
        }
        else
        {
          v30 = *(_WORD *)(result + 2740);
          v31 = v30 << v28;
          v32 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v31;
          *(_BYTE *)(v32 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v33 = *(_BYTE *)(result + 5809);
          v34 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v34;
          *(_BYTE *)(v34 + *(_DWORD *)(result + 8)) = v33;
          v35 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v36 = v35 + v29 - 16;
          *(_WORD *)(result + 5808) = v30 >> (16 - v35);
          v5 = v76;
        }
        v37 = v5 - 3;
        *(_DWORD *)(result + 5812) = v36;
        if ( v36 > 14 )
        {
          v38 = v37 << v36;
          v39 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v38;
          *(_BYTE *)(v39 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v40 = *(_BYTE *)(result + 5809);
          v41 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v41;
          *(_BYTE *)(v41 + *(_DWORD *)(result + 8)) = v40;
          v42 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          *(_DWORD *)(result + 5812) = v42 - 14;
          *(_WORD *)(result + 5808) = (unsigned __int16)v37 >> (16 - v42);
          goto LABEL_39;
        }
        *(_WORD *)(result + 5808) |= v37 << v36;
        v43 = v36 + 2;
      }
      else
      {
        v44 = *(_DWORD *)(result + 5812);
        HIWORD(v45) = 0;
        if ( v5 > 10 )
        {
          LOWORD(v45) = *(_WORD *)(result + 2750);
          if ( v44 <= 16 - v45 )
          {
            *(_WORD *)(result + 5808) |= *(_WORD *)(result + 2748) << v44;
            v65 = v45 + v44;
          }
          else
          {
            v59 = *(_WORD *)(result + 2748);
            v60 = v59 << v44;
            v61 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v60;
            *(_BYTE *)(v61 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v62 = *(_BYTE *)(result + 5809);
            v63 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v63;
            *(_BYTE *)(v63 + *(_DWORD *)(result + 8)) = v62;
            v64 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v65 = v64 + v45 - 16;
            *(_WORD *)(result + 5808) = v59 >> (16 - v64);
            v5 = v76;
          }
          v66 = v5 - 11;
          *(_DWORD *)(result + 5812) = v65;
          if ( v65 > 9 )
          {
            v67 = v66 << v65;
            v68 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v67;
            *(_BYTE *)(v68 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v69 = *(_BYTE *)(result + 5809);
            v70 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v70;
            *(_BYTE *)(v70 + *(_DWORD *)(result + 8)) = v69;
            v71 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            *(_DWORD *)(result + 5812) = v71 - 9;
            *(_WORD *)(result + 5808) = (unsigned __int16)v66 >> (16 - v71);
            goto LABEL_39;
          }
          *(_WORD *)(result + 5808) |= v66 << v65;
          v43 = v65 + 7;
        }
        else
        {
          LOWORD(v45) = *(_WORD *)(result + 2746);
          if ( v44 <= 16 - v45 )
          {
            *(_WORD *)(result + 5808) |= *(_WORD *)(result + 2744) << v44;
            v52 = v45 + v44;
          }
          else
          {
            v46 = *(_WORD *)(result + 2744);
            v47 = v46 << v44;
            v48 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v47;
            *(_BYTE *)(v48 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v49 = *(_BYTE *)(result + 5809);
            v50 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v50;
            *(_BYTE *)(v50 + *(_DWORD *)(result + 8)) = v49;
            v51 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v52 = v51 + v45 - 16;
            *(_WORD *)(result + 5808) = v46 >> (16 - v51);
            v5 = v76;
          }
          v53 = v5 - 3;
          *(_DWORD *)(result + 5812) = v52;
          if ( v52 > 13 )
          {
            v54 = v53 << v52;
            v55 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v54;
            *(_BYTE *)(v55 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v56 = *(_BYTE *)(result + 5809);
            v57 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v57;
            *(_BYTE *)(v57 + *(_DWORD *)(result + 8)) = v56;
            v58 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            *(_DWORD *)(result + 5812) = v58 - 13;
            *(_WORD *)(result + 5808) = (unsigned __int16)v53 >> (16 - v58);
            goto LABEL_39;
          }
          *(_WORD *)(result + 5808) |= v53 << v52;
          v43 = v52 + 3;
        }
      }
      *(_DWORD *)(result + 5812) = v43;
LABEL_39:
      v4 = v75;
      v5 = 0;
      v73 = v9;
      if ( v75 != 0 )
      {
        if ( v9 == v75 )
        {
          v6 = 6;
          v7 = 3;
        }
        else
        {
          v6 = 7;
          v7 = 4;
        }
      }
      else
      {
        v6 = 138;
        v7 = 3;
      }
LABEL_44:
      v72 = v74 == 1;
      v77 += 2;
      --v74;
    }
    while ( !v72 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100342C0
// Name: sub_100342C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_100342C0(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // ebx
  unsigned int v5; // edi
  int v6; // ebp
  int v7; // esi
  int v8; // ecx
  unsigned __int16 v9; // di
  int v10; // edx
  int v11; // ecx
  int v12; // ecx
  int v13; // edx
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  int v17; // edi
  unsigned __int16 v18; // di
  int v19; // edx
  int v20; // ecx
  char v21; // bl
  int v22; // edx
  int v23; // edx
  __int16 v24; // di
  __int16 v25; // bx
  int v26; // ecx
  int v27; // edi
  int v28; // esi
  int v29; // ecx
  int v30; // edx
  int v31; // ecx
  char v32; // bl
  int v33; // edx
  int v34; // edx
  int v35; // ecx
  unsigned int v36; // ebp
  int v37; // edx
  int v38; // ecx
  int v39; // edi
  unsigned __int16 v40; // si
  int v41; // edx
  int v42; // ecx
  char v43; // bl
  int v44; // edx
  int v45; // edx
  __int16 v46; // si
  int v47; // ecx
  int v48; // esi
  unsigned int v49; // ebp
  int v50; // ecx
  unsigned int v51; // edx
  int v52; // ecx
  int v53; // ecx
  int v54; // edx
  int v55; // edx
  int v56; // ecx
  int v57; // edi
  unsigned __int16 v58; // si
  int v59; // edx
  int v60; // ecx
  int v61; // ecx
  int v62; // edx
  int v63; // edx
  int v64; // ecx
  int v65; // [esp+10h] [ebp-8h]
  unsigned int v66; // [esp+14h] [ebp-4h]
  int v67; // [esp+1Ch] [ebp+4h]
  int v68; // [esp+1Ch] [ebp+4h]

  result = a1;
  v4 = a2;
  v5 = 0;
  if ( *(_DWORD *)(a1 + 5784) != 0 )
  {
    do
    {
      v6 = *(unsigned __int16 *)(*(_DWORD *)(result + 5788) + 2 * v5);
      v7 = *(unsigned __int8 *)(v5 + *(_DWORD *)(result + 5776));
      v8 = *(_DWORD *)(result + 5812);
      v66 = v5 + 1;
      if ( (_WORD)v6 != 0 )
      {
        HIWORD(v17) = 0;
        v16 = (unsigned __int8)_length_code[v7];
        v67 = v16;
        LOWORD(v17) = *(_WORD *)(v4 + 4 * v16 + 1030);
        v65 = (unsigned __int16)v17;
        if ( v8 <= 16 - (unsigned __int16)v17 )
        {
          v25 = *(_WORD *)(a2 + 4 * v16 + 1028) << v8;
          v26 = *(_DWORD *)(result + 5812);
          *(_WORD *)(result + 5808) |= v25;
          *(_DWORD *)(result + 5812) = v17 + v26;
        }
        else
        {
          v18 = *(_WORD *)(a2 + 4 * v16 + 1028);
          v19 = v18 << v8;
          v20 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v19;
          *(_BYTE *)(v20 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v21 = *(_BYTE *)(result + 5809);
          v22 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v22;
          *(_BYTE *)(v22 + *(_DWORD *)(result + 8)) = v21;
          v23 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v24 = v18 >> (16 - v23);
          *(_DWORD *)(result + 5812) = v23 + v65 - 16;
          v16 = v67;
          *(_WORD *)(result + 5808) = v24;
        }
        v27 = dword_10058328[v16];
        if ( v27 != 0 )
        {
          v28 = v7 - dword_10058C70[v16];
          v29 = *(_DWORD *)(result + 5812);
          if ( v29 <= 16 - v27 )
          {
            *(_WORD *)(result + 5808) |= v28 << v29;
            v35 = v27 + v29;
          }
          else
          {
            v30 = v28 << v29;
            v31 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v30;
            *(_BYTE *)(v31 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v32 = *(_BYTE *)(result + 5809);
            v33 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v33;
            *(_BYTE *)(v33 + *(_DWORD *)(result + 8)) = v32;
            v34 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v35 = v34 + v27 - 16;
            *(_WORD *)(result + 5808) = (unsigned __int16)v28 >> (16 - v34);
          }
          *(_DWORD *)(result + 5812) = v35;
        }
        v36 = v6 - 1;
        if ( v36 >= 0x100 )
          v37 = (unsigned __int8)byte_10058A70[v36 >> 7];
        else
          v37 = (unsigned __int8)_dist_code[v36];
        v38 = *(_DWORD *)(result + 5812);
        v39 = *(unsigned __int16 *)(a3 + 4 * v37 + 2);
        v68 = v37;
        if ( v38 <= 16 - (unsigned __int16)v39 )
        {
          *(_WORD *)(result + 5808) |= *(_WORD *)(a3 + 4 * v37) << v38;
          v47 = v39 + v38;
        }
        else
        {
          v40 = *(_WORD *)(a3 + 4 * v37);
          v41 = v40 << v38;
          v42 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v41;
          *(_BYTE *)(v42 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v43 = *(_BYTE *)(result + 5809);
          v44 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v44;
          *(_BYTE *)(v44 + *(_DWORD *)(result + 8)) = v43;
          v45 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v46 = v40 >> (16 - v45);
          v47 = v45 + v39 - 16;
          v37 = v68;
          *(_WORD *)(result + 5808) = v46;
        }
        v4 = a2;
        *(_DWORD *)(result + 5812) = v47;
        v48 = dword_100583A0[v37];
        if ( v48 == 0 )
          goto LABEL_25;
        v49 = v36 - dword_10058CE8[v37];
        v50 = *(_DWORD *)(result + 5812);
        if ( v50 <= 16 - v48 )
        {
          *(_WORD *)(result + 5808) |= v49 << v50;
          v15 = v48 + v50;
        }
        else
        {
          v51 = v49 << v50;
          v52 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v51;
          *(_BYTE *)(v52 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v53 = *(_DWORD *)(result + 8);
          v54 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v54;
          *(_BYTE *)(v54 + v53) = *(_BYTE *)(result + 5809);
          v55 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v15 = v55 + v48 - 16;
          *(_WORD *)(result + 5808) = (unsigned __int16)v49 >> (16 - v55);
        }
      }
      else
      {
        LOWORD(v6) = *(_WORD *)(v4 + 4 * v7 + 2);
        if ( v8 <= 16 - (unsigned __int16)v6 )
        {
          *(_WORD *)(result + 5808) |= *(_WORD *)(v4 + 4 * v7) << v8;
          v15 = v6 + v8;
        }
        else
        {
          v9 = *(_WORD *)(v4 + 4 * v7);
          v10 = v9 << v8;
          v11 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v10;
          *(_BYTE *)(v11 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v12 = *(_DWORD *)(result + 8);
          v13 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v13;
          *(_BYTE *)(v13 + v12) = *(_BYTE *)(result + 5809);
          v14 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v15 = v14 + v6 - 16;
          *(_WORD *)(result + 5808) = v9 >> (16 - v14);
        }
      }
      *(_DWORD *)(result + 5812) = v15;
LABEL_25:
      v5 = v66;
    }
    while ( v66 < *(_DWORD *)(result + 5784) );
  }
  v56 = *(_DWORD *)(result + 5812);
  v57 = *(unsigned __int16 *)(v4 + 1026);
  if ( v56 <= 16 - (unsigned __int16)v57 )
  {
    *(_WORD *)(result + 5808) |= *(_WORD *)(v4 + 1024) << v56;
    v64 = v57 + v56;
  }
  else
  {
    v58 = *(_WORD *)(v4 + 1024);
    v59 = v58 << v56;
    v60 = *(_DWORD *)(result + 8);
    *(_WORD *)(result + 5808) |= v59;
    *(_BYTE *)(v60 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
    v61 = *(_DWORD *)(result + 8);
    v62 = *(_DWORD *)(result + 20) + 1;
    *(_DWORD *)(result + 20) = v62;
    *(_BYTE *)(v61 + v62) = *(_BYTE *)(result + 5809);
    v63 = *(_DWORD *)(result + 5812);
    ++*(_DWORD *)(result + 20);
    v64 = v63 + v57 - 16;
    *(_WORD *)(result + 5808) = v58 >> (16 - v63);
  }
  *(_DWORD *)(result + 5812) = v64;
  *(_DWORD *)(result + 5804) = *(unsigned __int16 *)(v4 + 1026);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100346D0
// Name: sub_100346D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl sub_100346D0(int a1)
{
  unsigned int v1; // edi
  unsigned int v2; // edx
  unsigned __int16 *v3; // eax
  int i; // ecx
  unsigned __int16 v5; // si
  unsigned __int16 *v6; // eax
  int j; // ecx
  unsigned __int16 v8; // bp
  unsigned __int16 *v9; // ecx
  int k; // eax
  unsigned __int16 v11; // si
  unsigned int v12; // edi

  v1 = 0;
  v2 = 0;
  v3 = (unsigned __int16 *)(a1 + 140);
  for ( i = 7; i != 0; --i )
  {
    v5 = *v3;
    v3 += 2;
    v2 += v5;
  }
  v6 = (unsigned __int16 *)(a1 + 168);
  for ( j = 121; j != 0; --j )
  {
    v8 = *v6;
    v6 += 2;
    v1 += v8;
  }
  v9 = (unsigned __int16 *)(a1 + 652);
  for ( k = 128; k != 0; --k )
  {
    v11 = *v9;
    v9 += 2;
    v2 += v11;
  }
  v12 = v1 >> 2;
  *(_BYTE *)(a1 + 28) = v2 <= v12;
  return v2 <= v12;
}

//------------------------------------------------------------------------------
// Address: 0x10034750
// Name: sub_10034750
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_10034750(unsigned int a1, int a2)
{
  unsigned int v4; // eax
  int v5; // esi

  v4 = 0;
  do
  {
    v5 = a1 & 1;
    a1 >>= 1;
    v4 = 2 * (v5 | v4);
    --a2;
  }
  while ( a2 > 0 );
  return v4 >> 1;
}

//------------------------------------------------------------------------------
// Address: 0x10034770
// Name: sub_10034770
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10034770(int a1)
{
  int result; // eax
  int v2; // ecx
  char v3; // bl
  int v4; // edx
  int v5; // edx
  int v6; // ecx

  result = a1;
  v2 = *(_DWORD *)(a1 + 5812);
  if ( v2 == 16 )
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v3 = *(_BYTE *)(a1 + 5809);
    v4 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v4;
    *(_BYTE *)(v4 + *(_DWORD *)(a1 + 8)) = v3;
    ++*(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) = 0;
    *(_DWORD *)(a1 + 5812) = 0;
  }
  else if ( v2 >= 8 )
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v5 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) = *(unsigned __int8 *)(a1 + 5809);
    v6 = *(_DWORD *)(a1 + 5812);
    *(_DWORD *)(a1 + 20) = v5 + 1;
    *(_DWORD *)(a1 + 5812) = v6 - 8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10034800
// Name: sub_10034800
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10034800(int a1)
{
  int result; // eax
  int v2; // edx
  char v3; // bl
  int v4; // edx

  result = a1;
  v2 = *(_DWORD *)(a1 + 5812);
  if ( v2 <= 8 )
  {
    if ( v2 > 0 )
      *(_BYTE *)(*(_DWORD *)(a1 + 8) + (*(_DWORD *)(a1 + 20))++) = *(_BYTE *)(a1 + 5808);
    *(_WORD *)(a1 + 5808) = 0;
    *(_DWORD *)(a1 + 5812) = 0;
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v3 = *(_BYTE *)(a1 + 5809);
    v4 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v4;
    *(_BYTE *)(v4 + *(_DWORD *)(a1 + 8)) = v3;
    ++*(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) = 0;
    *(_DWORD *)(a1 + 5812) = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10034880
// Name: sub_10034880
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10034880(_DWORD *a1, _BYTE *a2, int a3, int a4)
{
  int result; // eax
  int v5; // edi
  int v6; // edx
  int v7; // edi
  int v8; // ecx
  int v9; // edi
  int v10; // ecx

  sub_10034800((int)a1);
  result = a3;
  a1[1451] = 8;
  if ( a4 != 0 )
  {
    *(_BYTE *)(a1[5] + a1[2]) = a3;
    v5 = a1[2];
    v6 = a1[5] + 1;
    a1[5] = v6;
    *(_BYTE *)(v6 + v5) = BYTE1(a3);
    v7 = a1[2];
    v8 = a1[5] + 1;
    a1[5] = v8;
    *(_BYTE *)(v8 + v7) = ~(_BYTE)a3;
    v9 = a1[5] + 1;
    v10 = a1[2];
    a1[5] = v9;
    *(_BYTE *)(v9 + v10) = ~BYTE1(a3);
    ++a1[5];
  }
  if ( a3 != 0 )
  {
    do
    {
      *(_BYTE *)(a1[5] + a1[2]) = *a2++;
      --result;
      ++a1[5];
    }
    while ( result != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10034920
// Name: _inflate_blocks_reset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int (__cdecl *__cdecl inflate_blocks_reset(_DWORD *a1, int a2, _DWORD *a3))(_DWORD, _DWORD, _DWORD)
{
  int v3; // eax
  int (__cdecl *result)(_DWORD, _DWORD, _DWORD); // eax

  if ( a3 != nullptr )
    *a3 = a1[15];
  if ( *a1 == 4 || *a1 == 5 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1[3]);
  if ( *a1 == 6 )
    inflate_codes_free(a1: a1[1], a2);
  v3 = a1[10];
  *a1 = 0;
  a1[13] = v3;
  a1[12] = v3;
  result = (int (__cdecl *)(_DWORD, _DWORD, _DWORD))a1[14];
  a1[7] = 0;
  a1[8] = 0;
  if ( result != nullptr )
  {
    result = (int (__cdecl *)(_DWORD, _DWORD, _DWORD))result(a1: 0, a2: 0, a3: 0);
    a1[15] = result;
    *(_DWORD *)(a2 + 48) = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100349A0
// Name: _inflate_blocks_new
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_blocks_new(int a1, int a2, int a3)
{
  int result; // eax
  _DWORD *v4; // esi
  int v5; // eax
  int v6; // eax

  result = (*(int (__cdecl **)(_DWORD, int, int))(a1 + 32))(a1: *(_DWORD *)(a1 + 40), a2: 1, a3: 64);
  v4 = (_DWORD *)result;
  if ( result != 0 )
  {
    v5 = (*(int (__cdecl **)(_DWORD, int, int))(a1 + 32))(a1: *(_DWORD *)(a1 + 40), a2: 8, a3: 1440);
    v4[9] = v5;
    if ( v5 != 0 )
    {
      v6 = (*(int (__cdecl **)(_DWORD, int, int))(a1 + 32))(a1: *(_DWORD *)(a1 + 40), a2: 1, a3);
      v4[10] = v6;
      if ( v6 != 0 )
      {
        v4[11] = a3 + v6;
        v4[14] = a2;
        *v4 = 0;
        inflate_blocks_reset(a1: v4, a2: a1, a3: nullptr);
        return (int)v4;
      }
      else
      {
        (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: v4[9]);
        (*(void (__cdecl **)(_DWORD, _DWORD *))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: v4);
        return 0;
      }
    }
    else
    {
      (*(void (__cdecl **)(_DWORD, _DWORD *))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: v4);
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10034A40
// Name: _inflate_blocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_blocks(_DWORD *a1, int *a2, int a3)
{
  unsigned int v4; // edx
  unsigned int v5; // ebp
  char *v6; // ecx
  unsigned int v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // edi
  unsigned int v10; // esi
  unsigned int v11; // eax
  int v12; // edx
  unsigned int v13; // ebp
  int v14; // ecx
  int v15; // eax
  unsigned __int8 *v16; // eax
  int v17; // edi
  int v18; // esi
  int v19; // edx
  unsigned int v20; // edi
  unsigned int v21; // ecx
  char *v22; // ecx
  char *v23; // edx
  unsigned int v24; // eax
  unsigned int v25; // esi
  int v26; // eax
  char *v27; // edx
  unsigned int v28; // esi
  int v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // edi
  unsigned int v34; // esi
  unsigned __int8 *v35; // eax
  int v36; // edx
  unsigned int v37; // eax
  unsigned int v38; // ecx
  int v39; // eax
  int *v40; // esi
  int v41; // eax
  unsigned int v42; // edi
  unsigned __int8 *v43; // eax
  char v44; // cl
  int v45; // eax
  unsigned int v46; // edx
  unsigned int v47; // ecx
  unsigned __int8 *v48; // eax
  unsigned int v49; // ecx
  char v50; // cl
  int v51; // edx
  int v52; // edx
  unsigned int v53; // ecx
  unsigned int v54; // edx
  char v55; // cl
  unsigned int v56; // edi
  unsigned int v57; // eax
  int v58; // ecx
  int v59; // eax
  unsigned int v60; // eax
  unsigned int v61; // eax
  int v62; // edx
  int v63; // eax
  unsigned __int8 *v64; // edi
  int v65; // edx
  int v66; // eax
  char *v67; // ecx
  unsigned __int8 *v68; // edi
  unsigned int v69; // edx
  unsigned int v70; // eax
  int v71; // eax
  int v72; // ebp
  int result; // eax
  int v74; // ebp
  unsigned __int8 **v75; // eax
  unsigned __int8 *v76; // edx
  unsigned __int8 *v77; // esi
  int v78; // ebp
  int v79; // ebp
  int v80; // ebp
  unsigned __int8 *v81; // edx
  unsigned __int8 *v82; // ebp
  unsigned __int8 *v83; // ebp
  int v84; // esi
  unsigned __int8 *v85; // esi
  int v86; // ebp
  unsigned __int8 *v87; // edi
  int v88; // edx
  int v89; // ecx
  unsigned __int8 *v90; // edx
  bool v91; // zf
  unsigned __int8 *v92; // edi
  int v93; // ecx
  unsigned __int8 *v94; // edi
  int v95; // ecx
  unsigned __int8 *v96; // edi
  char *v97; // ecx
  int v98; // edx
  unsigned __int8 *v99; // ebp
  unsigned __int8 *v100; // ebp
  unsigned __int8 *v101; // esi
  int v102; // [esp-1Ch] [ebp-60h]
  int v103; // [esp-14h] [ebp-58h]
  int v104; // [esp-8h] [ebp-4Ch]
  int v105; // [esp-8h] [ebp-4Ch]
  int v106; // [esp-4h] [ebp-48h]
  unsigned int v107; // [esp-4h] [ebp-48h]
  unsigned __int8 *v108; // [esp+10h] [ebp-34h]
  unsigned int v109; // [esp+14h] [ebp-30h]
  int v110; // [esp+18h] [ebp-2Ch] BYREF
  unsigned int v111; // [esp+1Ch] [ebp-28h]
  int v112; // [esp+20h] [ebp-24h] BYREF
  int v113; // [esp+24h] [ebp-20h] BYREF
  int v114; // [esp+28h] [ebp-1Ch] BYREF
  int v115; // [esp+2Ch] [ebp-18h] BYREF
  int v116; // [esp+30h] [ebp-14h] BYREF
  unsigned int v117; // [esp+34h] [ebp-10h]
  unsigned int v118; // [esp+38h] [ebp-Ch]
  int v119; // [esp+3Ch] [ebp-8h] BYREF
  int v120; // [esp+40h] [ebp-4h] BYREF
  char *v121; // [esp+48h] [ebp+4h]
  int v122; // [esp+50h] [ebp+Ch]

  v4 = a2[1];
  v5 = a1[7];
  v108 = (unsigned __int8 *)*a2;
  v6 = (char *)a1[13];
  v110 = a1[8];
  v7 = a1[12];
  v109 = v4;
  v121 = v6;
  if ( (unsigned int)v6 >= v7 )
    v8 = a1[11] - (_DWORD)v6;
  else
    v8 = v7 - (_DWORD)v6 - 1;
  v111 = v8;
  while ( 2 )
  {
    switch ( *a1 )
    {
      case 0:
        v9 = v108;
        v10 = v110;
        if ( v5 >= 3 )
          goto LABEL_10;
        v11 = v109;
        do
        {
          if ( v11 == 0 )
          {
            a1[8] = v10;
            a1[7] = v5;
            v72 = (int)&v9[a2[2] - *a2];
            a2[1] = 0;
            a2[2] = v72;
            *a2 = (int)v9;
            a1[13] = v121;
            return inflate_flush(a1, a2, a3);
          }
          --v11;
          a3 = 0;
          v12 = *v9 << v5;
          v5 += 8;
          v109 = v11;
          v10 |= v12;
          ++v9;
          v110 = v10;
          v108 = v9;
        }
        while ( v5 < 3 );
LABEL_10:
        a1[6] = v10 & 1;
        switch ( (unsigned __int8)(v10 & 7) >> 1 )
        {
          case 0:
            v13 = v5 - 3;
            *a1 = 1;
            v14 = v13 & 7;
            v5 = v13 - v14;
            v110 = v10 >> 3 >> v14;
            continue;
          case 1:
            inflate_trees_fixed(a1: &v116, a2: &v115, a3: &v114, a4: &v113);
            v15 = inflate_codes_new(a1: v116, a2: v115, a3: v114, a4: v113, a5: a2);
            a1[1] = v15;
            if ( v15 != 0 )
            {
              v110 = v10 >> 3;
              v5 -= 3;
              *a1 = 6;
              continue;
            }
            a1[8] = v10;
            a1[7] = v5;
            v74 = a2[2];
            a2[1] = v109;
            a2[2] = (int)&v9[v74 - *a2];
            *a2 = (int)v9;
            a1[13] = v121;
            result = inflate_flush(a1, a2, a3: -4);
            break;
          case 2:
            v110 = v10 >> 3;
            v5 -= 3;
            *a1 = 3;
            continue;
          case 3:
            v75 = (unsigned __int8 **)a2;
            *a1 = 9;
            a2[6] = (int)aInvalidBlockTy;
            a1[8] = v10 >> 3;
            a1[7] = v5 - 3;
            a2[1] = v109;
            v76 = &v9[-*a2];
            *a2 = (int)v9;
            v106 = -3;
            goto LABEL_129;
          default:
            continue;
        }
        return result;
      case 1:
        v16 = v108;
        v17 = v109;
        v18 = v110;
        if ( v5 >= 0x20 )
          goto LABEL_18;
        do
        {
          if ( v17 == 0 )
          {
            a1[8] = v18;
            a1[7] = v5;
            v77 = (unsigned __int8 *)*a2;
            v78 = a2[2];
            a2[1] = 0;
            *a2 = (int)v16;
            a2[2] = v16 - v77 + v78;
            a1[13] = v121;
            return inflate_flush(a1, a2, a3);
          }
          a3 = 0;
          --v17;
          v19 = *v16 << v5;
          v5 += 8;
          v109 = v17;
          v18 |= v19;
          v108 = ++v16;
        }
        while ( v5 < 0x20 );
LABEL_18:
        if ( (unsigned int)~v18 >> 16 != (unsigned __int16)v18 )
        {
          *a1 = 9;
          a2[6] = (int)aInvalidStoredB;
          a1[8] = v18;
          a1[7] = v5;
          v79 = (int)&v16[a2[2] - *a2];
          *a2 = (int)v16;
          a2[1] = v17;
          a2[2] = v79;
          a1[13] = v121;
          return inflate_flush(a1, a2, a3: -3);
        }
        v5 = 0;
        a1[1] = (unsigned __int16)v18;
        v110 = 0;
        if ( (_WORD)v18 != 0 )
        {
          *a1 = 2;
          continue;
        }
LABEL_45:
        *a1 = a1[6] != 0 ? 7 : 0;
        continue;
      case 2:
        v20 = v109;
        if ( v109 == 0 )
        {
          v75 = (unsigned __int8 **)a2;
          a1[8] = v110;
          a1[7] = v5;
          v80 = a2[2];
          v81 = &v108[-*a2];
          a2[1] = 0;
          v82 = &v81[v80];
          *a2 = (int)v108;
          v106 = a3;
          goto LABEL_130;
        }
        v21 = v111;
        if ( v111 == 0 )
        {
          v22 = (char *)a1[11];
          v23 = v121;
          if ( v121 != v22 )
            goto LABEL_29;
          v24 = a1[12];
          v25 = a1[10];
          if ( v24 == v25 )
            goto LABEL_29;
          v23 = (char *)a1[10];
          v121 = v23;
          v21 = v25 >= v24 ? (unsigned int)&v22[-v25] : v24 - v25 - 1;
          v111 = v21;
          if ( v21 == 0 )
          {
LABEL_29:
            a1[13] = v23;
            v26 = inflate_flush(a1, a2, a3);
            v27 = (char *)a1[13];
            v28 = a1[12];
            v122 = v26;
            v121 = v27;
            if ( (unsigned int)v27 >= v28 )
              v21 = a1[11] - (_DWORD)v27;
            else
              v21 = v28 - (_DWORD)v27 - 1;
            v29 = a1[11];
            v111 = v21;
            v112 = v29;
            if ( v27 == (char *)v29 )
            {
              v30 = a1[10];
              if ( v28 != v30 )
              {
                v27 = (char *)a1[10];
                v121 = v27;
                if ( v30 >= v28 )
                  v21 = v112 - v30;
                else
                  v21 = v28 - v30 - 1;
                v111 = v21;
              }
            }
            if ( v21 == 0 )
            {
              a1[8] = v110;
              a1[7] = v5;
              v83 = (unsigned __int8 *)*a2;
              v84 = a2[2];
              a2[1] = v109;
              *a2 = (int)v108;
              a2[2] = v108 - v83 + v84;
              a1[13] = v27;
              return inflate_flush(a1, a2, a3: v122);
            }
            v20 = v109;
          }
        }
        v31 = a1[1];
        a3 = 0;
        if ( v31 > v20 )
          v31 = v20;
        if ( v31 > v21 )
          v31 = v21;
        qmemcpy(v121, v108, v31);
        v108 += v31;
        v32 = a1[1] - v31;
        v109 -= v31;
        v121 += v31;
        v111 -= v31;
        a1[1] = v32;
        if ( v32 == 0 )
          goto LABEL_45;
        continue;
      case 3:
        v33 = v110;
        if ( v5 >= 0xE )
          goto LABEL_50;
        v34 = v109;
        v35 = v108;
        do
        {
          if ( v34 == 0 )
          {
            v75 = (unsigned __int8 **)a2;
            a1[8] = v33;
            a1[7] = v5;
            v85 = (unsigned __int8 *)*a2;
            v86 = a2[2];
            a2[1] = 0;
            *a2 = (int)v108;
            v82 = (unsigned __int8 *)(v108 - v85 + v86);
            v106 = a3;
            goto LABEL_130;
          }
          --v34;
          a3 = 0;
          v36 = *v35 << v5;
          v5 += 8;
          v109 = v34;
          v33 |= v36;
          v108 = ++v35;
        }
        while ( v5 < 0xE );
LABEL_50:
        v37 = v33 & 0x3FFF;
        a1[1] = v37;
        v38 = v33 & 0x1F;
        if ( v38 > 0x1D || (unsigned int)(v39 = (v37 >> 5) & 0x1F) > 0x1D )
        {
          v75 = (unsigned __int8 **)a2;
          *a1 = 9;
          v106 = -3;
          a2[6] = (int)aTooManyLengthO;
          a1[8] = v33;
LABEL_127:
          a1[7] = v5;
          v75[1] = (unsigned __int8 *)v109;
LABEL_128:
          v101 = *v75;
          *v75 = v108;
          v76 = (unsigned __int8 *)(v108 - v101);
LABEL_129:
          v82 = &v75[2][(_DWORD)v76];
LABEL_130:
          v75[2] = v82;
          a1[13] = v121;
          return inflate_flush(a1, a2: v75, a3: v106);
        }
        v40 = a2;
        v41 = ((int (__cdecl *)(int, unsigned int, int))a2[8])(a1: a2[10], a2: v39 + v38 + 258, a3: 4);
        a1[3] = v41;
        if ( v41 == 0 )
        {
          a1[8] = v33;
          a1[7] = v5;
          v87 = (unsigned __int8 *)*a2;
          v88 = a2[2];
          a2[1] = v109;
          *a2 = (int)v108;
          a2[2] = v108 - v87 + v88;
          a1[13] = v121;
          return inflate_flush(a1, a2, a3: -4);
        }
        v42 = v33 >> 14;
        v5 -= 14;
        a1[2] = 0;
        *a1 = 4;
LABEL_55:
        if ( a1[2] < (unsigned int)((a1[1] >> 10) + 4) )
        {
          while ( v5 >= 3 )
          {
LABEL_60:
            v45 = v42 & 7;
            v5 -= 3;
            v42 >>= 3;
            *(_DWORD *)(a1[3] + 4 * dword_10058D60[a1[2]]) = v45;
            v46 = a1[2] + 1;
            a1[2] = v46;
            if ( v46 >= (a1[1] >> 10) + 4 )
              goto LABEL_61;
          }
          v43 = v108;
          while ( v109 != 0 )
          {
            --v109;
            v44 = v5;
            v5 += 8;
            a3 = 0;
            v42 |= *v43++ << v44;
            v108 = v43;
            if ( v5 >= 3 )
              goto LABEL_60;
          }
          goto LABEL_108;
        }
LABEL_61:
        if ( a1[2] < 0x13u )
        {
          do
          {
            *(_DWORD *)(a1[3] + 4 * dword_10058D60[a1[2]]) = 0;
            v47 = a1[2] + 1;
            a1[2] = v47;
          }
          while ( v47 < 0x13 );
        }
        v104 = a1[9];
        v103 = a1[3];
        a1[4] = 7;
        v111 = inflate_trees_bits(a1: v103, a2: a1 + 4, a3: a1 + 5, a4: v104, a5: v40);
        if ( v111 != 0 )
        {
          ((void (__cdecl *)(int, _DWORD))v40[9])(a1: v40[10], a2: a1[3]);
          v91 = v111 == -3;
LABEL_113:
          if ( v91 )
            *a1 = 9;
          a1[8] = v42;
          a1[7] = v5;
          v94 = (unsigned __int8 *)*v40;
          v40[1] = v109;
          v95 = v40[2];
          *v40 = (int)v108;
          v40[2] = v108 - v94 + v95;
          v107 = v111;
          a1[13] = v121;
          return inflate_flush(a1, a2: v40, a3: v107);
        }
        a1[2] = 0;
        *a1 = 5;
LABEL_66:
        v48 = v108;
        if ( a1[2] < ((a1[1] >> 5) & 0x1F) + (a1[1] & 0x1Fu) + 258 )
        {
          while ( 1 )
          {
            v49 = a1[4];
            if ( v5 < v49 )
              break;
LABEL_72:
            v52 = a1[5] + 8 * (v42 & inflate_mask[v49]);
            v53 = *(unsigned __int8 *)(v52 + 1);
            v54 = *(_DWORD *)(v52 + 4);
            v111 = v53;
            v118 = v54;
            if ( v54 >= 0x10 )
            {
              if ( v54 == 18 )
                v112 = 7;
              else
                v112 = v54 - 14;
              v110 = 8 * (v54 == 18) + 3;
              v117 = v112 + v111;
              if ( v5 < v112 + v111 )
              {
                while ( v109 != 0 )
                {
                  v55 = v5;
                  v5 += 8;
                  --v109;
                  a3 = 0;
                  v42 |= *v48++ << v55;
                  v108 = v48;
                  if ( v5 >= v117 )
                    goto LABEL_80;
                }
                goto LABEL_108;
              }
LABEL_80:
              v56 = v42 >> v111;
              v57 = a1[1];
              v110 += v56 & inflate_mask[v112];
              v42 = v56 >> v112;
              v5 -= v111 + v112;
              v58 = a1[2];
              if ( v58 + v110 > ((v57 >> 5) & 0x1F) + (v57 & 0x1F) + 258 )
                goto LABEL_111;
              if ( v118 == 16 )
              {
                if ( v58 == 0 )
                {
LABEL_111:
                  ((void (__cdecl *)(int, _DWORD))v40[9])(a1: v40[10], a2: a1[3]);
                  *a1 = 9;
                  v40[6] = (int)aInvalidBitLeng;
                  a1[8] = v42;
                  a1[7] = v5;
                  v92 = (unsigned __int8 *)*v40;
                  v40[1] = v109;
                  v93 = v40[2];
                  *v40 = (int)v108;
                  v40[2] = v108 - v92 + v93;
                  a1[13] = v121;
                  return inflate_flush(a1, a2: v40, a3: -3);
                }
                v59 = *(_DWORD *)(a1[3] + 4 * v58 - 4);
              }
              else
              {
                v59 = 0;
              }
              do
              {
                ++v58;
                *(_DWORD *)(a1[3] + 4 * v58 - 4) = v59;
                --v110;
              }
              while ( v110 != 0 );
              a1[2] = v58;
            }
            else
            {
              v5 -= v53;
              v42 >>= v53;
              *(_DWORD *)(a1[3] + 4 * a1[2]++) = v54;
            }
            if ( a1[2] >= ((a1[1] >> 5) & 0x1F) + (a1[1] & 0x1Fu) + 258 )
              goto LABEL_88;
            v48 = v108;
          }
          while ( v109 != 0 )
          {
            v50 = v5;
            v5 += 8;
            --v109;
            a3 = 0;
            v51 = *v48 << v50;
            v49 = a1[4];
            v42 |= v51;
            v108 = ++v48;
            if ( v5 >= v49 )
              goto LABEL_72;
          }
LABEL_108:
          a1[8] = v42;
          a1[7] = v5;
          v89 = v40[2];
          v90 = &v108[-*v40];
          *v40 = (int)v108;
          v40[2] = (int)&v90[v89];
          v40[1] = 0;
          a1[13] = v121;
          return inflate_flush(a1, a2: v40, a3);
        }
LABEL_88:
        v60 = a1[1];
        v105 = a1[9];
        v102 = a1[3];
        a1[5] = 0;
        v110 = 9;
        v112 = 6;
        v61 = inflate_trees_dynamic(
                a1: (v60 & 0x1F) + 257,
                a2: ((v60 >> 5) & 0x1F) + 1,
                a3: v102,
                a4: &v110,
                a5: &v112,
                a6: &v120,
                a7: &v119,
                a8: v105,
                a9: v40);
        v62 = a1[3];
        v111 = v61;
        ((void (__cdecl *)(int, int))v40[9])(a1: v40[10], a2: v62);
        if ( v111 != 0 )
        {
          v91 = v111 == -3;
          goto LABEL_113;
        }
        v63 = inflate_codes_new(a1: v110, a2: v112, a3: v120, a4: v119, a5: v40);
        if ( v63 == 0 )
        {
          a1[8] = v42;
          a1[7] = v5;
          v96 = (unsigned __int8 *)*v40;
          v40[1] = v109;
          v40[2] += v108 - v96;
          *v40 = (int)v108;
          a1[13] = v121;
          return inflate_flush(a1, a2: v40, a3: -4);
        }
        a1[1] = v63;
        *a1 = 6;
LABEL_92:
        a1[8] = v42;
        a1[7] = v5;
        v64 = (unsigned __int8 *)*v40;
        v40[1] = v109;
        v65 = v40[2];
        *v40 = (int)v108;
        v40[2] = v108 - v64 + v65;
        a1[13] = v121;
        v66 = inflate_codes(a1, a2: v40, a3);
        if ( v66 != 1 )
          return inflate_flush(a1, a2: v40, a3: v66);
        a3 = 0;
        inflate_codes_free(a1: a1[1], a2: v40);
        v67 = (char *)a1[13];
        v68 = (unsigned __int8 *)*v40;
        v69 = v40[1];
        v5 = a1[7];
        v110 = a1[8];
        v70 = a1[12];
        v108 = v68;
        v109 = v69;
        v121 = v67;
        if ( (unsigned int)v67 >= v70 )
          v71 = a1[11] - (_DWORD)v67;
        else
          v71 = v70 - (_DWORD)v67 - 1;
        v111 = v71;
        if ( a1[6] == 0 )
        {
          *a1 = 0;
          continue;
        }
        *a1 = 7;
LABEL_119:
        a1[13] = v67;
        v66 = inflate_flush(a1, a2: v40, a3);
        v97 = (char *)a1[13];
        if ( (char *)a1[12] != v97 )
        {
          v98 = v110;
          a1[7] = v5;
          a1[8] = v98;
          v99 = (unsigned __int8 *)*v40;
          v40[1] = v109;
          *v40 = (int)v68;
          v40[2] += v68 - v99;
          a1[13] = v97;
          return inflate_flush(a1, a2: v40, a3: v66);
        }
        *a1 = 8;
LABEL_124:
        a1[8] = v110;
        a1[7] = v5;
        v100 = (unsigned __int8 *)*v40;
        v40[1] = v109;
        v40[2] += v68 - v100;
        *v40 = (int)v68;
        a1[13] = v97;
        return inflate_flush(a1, a2: v40, a3: 1);
      case 4:
        v42 = v110;
        v40 = a2;
        goto LABEL_55;
      case 5:
        v42 = v110;
        v40 = a2;
        goto LABEL_66;
      case 6:
        v42 = v110;
        v40 = a2;
        goto LABEL_92;
      case 7:
        v67 = v121;
        v68 = v108;
        v40 = a2;
        goto LABEL_119;
      case 8:
        v97 = v121;
        v68 = v108;
        v40 = a2;
        goto LABEL_124;
      case 9:
        v75 = (unsigned __int8 **)a2;
        a1[8] = v110;
        a1[7] = v5;
        a2[1] = v109;
        v106 = -3;
        goto LABEL_128;
      default:
        v75 = (unsigned __int8 **)a2;
        a1[8] = v110;
        v106 = -2;
        goto LABEL_127;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035690
// Name: _inflate_blocks_free
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_blocks_free(_DWORD *a1, int a2)
{
  inflate_blocks_reset(a1, a2, a3: nullptr);
  (*(void (__cdecl **)(_DWORD, _DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1[10]);
  (*(void (__cdecl **)(_DWORD, _DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1[9]);
  (*(void (__cdecl **)(_DWORD, _DWORD *))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100356D0
// Name: _inflate_codes_new
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_codes_new(char a1, char a2, int a3, int a4, int a5)
{
  int result; // eax

  result = (*(int (__cdecl **)(_DWORD, int, int))(a5 + 32))(a1: *(_DWORD *)(a5 + 40), a2: 1, a3: 28);
  if ( result != 0 )
  {
    *(_BYTE *)(result + 16) = a1;
    *(_BYTE *)(result + 17) = a2;
    *(_DWORD *)result = 0;
    *(_DWORD *)(result + 20) = a3;
    *(_DWORD *)(result + 24) = a4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10035710
// Name: _inflate_codes
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_codes(_DWORD *a1, unsigned __int8 **a2, int a3)
{
  _DWORD *v5; // eax
  unsigned __int8 *v6; // ebp
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  _BYTE *v9; // edx
  int v10; // ecx
  unsigned __int8 *v11; // ebx
  unsigned __int8 *v12; // ecx
  int v13; // eax
  unsigned int v14; // ecx
  int v15; // ecx
  bool v16; // zf
  int v17; // ecx
  unsigned int v18; // eax
  char v19; // cl
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  unsigned int v24; // eax
  char v25; // cl
  int v26; // ecx
  int v27; // ecx
  unsigned int v28; // eax
  char v29; // cl
  int v30; // ecx
  int v31; // ecx
  int v32; // ecx
  unsigned int v33; // eax
  char v34; // cl
  int v35; // ecx
  unsigned int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // ecx
  int v39; // eax
  int v40; // eax
  unsigned int v41; // eax
  int v42; // ecx
  unsigned int v43; // ecx
  int v44; // eax
  int v45; // ecx
  unsigned int v46; // eax
  unsigned int v47; // ecx
  int v48; // eax
  int v49; // eax
  unsigned int v50; // eax
  int v51; // ecx
  unsigned int v52; // ecx
  int v53; // eax
  unsigned __int8 *v54; // eax
  unsigned __int8 *v55; // ecx
  unsigned __int8 *v57; // ebx
  int v58; // eax
  unsigned __int8 *v59; // ebx
  unsigned __int8 *v60; // ebx
  unsigned __int8 *v61; // ebx
  int v62; // [esp-4h] [ebp-24h]
  _DWORD *v63; // [esp+10h] [ebp-10h]
  unsigned int v64; // [esp+14h] [ebp-Ch]
  unsigned int i; // [esp+18h] [ebp-8h]
  unsigned __int8 *v66; // [esp+18h] [ebp-8h]
  unsigned int j; // [esp+18h] [ebp-8h]
  unsigned int v68; // [esp+18h] [ebp-8h]
  unsigned int k; // [esp+18h] [ebp-8h]
  _BYTE *v70; // [esp+1Ch] [ebp-4h]
  unsigned int v71; // [esp+24h] [ebp+4h]
  unsigned int v72; // [esp+28h] [ebp+8h]
  int v73; // [esp+2Ch] [ebp+Ch]

  v5 = (_DWORD *)a1[1];
  v6 = *a2;
  v7 = a1[7];
  v72 = (unsigned int)a2[1];
  v8 = a1[12];
  v71 = a1[8];
  v9 = (_BYTE *)a1[13];
  v63 = v5;
  if ( (unsigned int)v9 >= v8 )
    v10 = a1[11] - (_DWORD)v9;
  else
    v10 = v8 - (_DWORD)v9 - 1;
LABEL_4:
  v64 = v10;
  while ( 2 )
  {
    switch ( *v5 )
    {
      case 0:
        if ( v64 >= 0x102 && v72 >= 0xA )
        {
          a1[8] = v71;
          a1[7] = v7;
          v11 = *a2;
          a2[1] = (unsigned __int8 *)v72;
          v12 = a2[2];
          *a2 = v6;
          a2[2] = &v12[v6 - v11];
          a1[13] = v9;
          v13 = inflate_fast(
                  a1: *((unsigned __int8 *)v63 + 16),
                  a2: *((unsigned __int8 *)v63 + 17),
                  a3: v63[5],
                  a4: v63[6],
                  a5: a1,
                  a6: a2);
          v6 = *a2;
          v7 = a1[7];
          v72 = (unsigned int)a2[1];
          v14 = a1[12];
          v71 = a1[8];
          v9 = (_BYTE *)a1[13];
          a3 = v13;
          v15 = (unsigned int)v9 >= v14 ? a1[11] - (_DWORD)v9 : v14 - (_DWORD)v9 - 1;
          v64 = v15;
          if ( v13 != 0 )
          {
            v16 = v13 == 1;
            v5 = v63;
            *v63 = 2 * !v16 + 7;
            continue;
          }
        }
        v5 = v63;
        v17 = *((unsigned __int8 *)v63 + 16);
        *v63 = 1;
        v63[3] = v17;
        v63[2] = v63[5];
        goto LABEL_14;
      case 1:
LABEL_14:
        v18 = v5[3];
        for ( i = v18; v7 < i; v71 = v20 )
        {
          if ( v72 == 0 )
            goto LABEL_86;
          v19 = v7;
          --v72;
          v7 += 8;
          a3 = 0;
          v20 = (*v6 << v19) | v71;
          v18 = i;
          ++v6;
        }
        v66 = (unsigned __int8 *)(v63[2] + 8 * (v71 & inflate_mask[v18]));
        v21 = v66[1];
        v71 >>= v21;
        v7 -= v21;
        v22 = *v66;
        if ( *v66 != 0 )
        {
          if ( (v22 & 0x10) != 0 )
          {
            v5 = v63;
            v63[2] = v22 & 0xF;
            v23 = *((_DWORD *)v66 + 1);
            *v63 = 2;
            v63[1] = v23;
          }
          else
          {
            if ( (v22 & 0x40) == 0 )
              goto LABEL_22;
            v5 = v63;
            if ( (v22 & 0x20) == 0 )
            {
              *v63 = 9;
              a2[6] = (unsigned __int8 *)aInvalidLiteral;
              v62 = -3;
LABEL_96:
              a1[7] = v7;
              a1[8] = v71;
              v61 = *a2;
              a2[1] = (unsigned __int8 *)v72;
              a2[2] += v6 - v61;
LABEL_97:
              *a2 = v6;
              a1[13] = v9;
              return inflate_flush(a1, a2, a3: v62);
            }
            *v63 = 7;
          }
        }
        else
        {
          v5 = v63;
          v63[2] = *((_DWORD *)v66 + 1);
          *v63 = 6;
        }
        continue;
      case 2:
        v24 = v5[2];
        for ( j = v24; v7 < j; v71 = v26 )
        {
          if ( v72 == 0 )
            goto LABEL_86;
          v25 = v7;
          --v72;
          v7 += 8;
          a3 = 0;
          v26 = (*v6 << v25) | v71;
          v24 = j;
          ++v6;
        }
        v63[1] += v71 & inflate_mask[v24];
        v71 >>= j;
        v7 -= j;
        v5 = v63;
        v27 = *((unsigned __int8 *)v63 + 17);
        *v63 = 3;
        v63[3] = v27;
        v63[2] = v63[6];
LABEL_29:
        v28 = v5[3];
        v68 = v28;
        if ( v7 >= v28 )
        {
LABEL_32:
          v66 = (unsigned __int8 *)(v63[2] + 8 * (v71 & inflate_mask[v28]));
          v31 = v66[1];
          v7 -= v31;
          v71 >>= v31;
          v22 = *v66;
          if ( (v22 & 0x10) != 0 )
          {
            v5 = v63;
            v63[2] = v22 & 0xF;
            v32 = *((_DWORD *)v66 + 1);
            *v63 = 4;
            v63[3] = v32;
          }
          else
          {
            if ( (v22 & 0x40) != 0 )
            {
              v62 = -3;
              *v63 = 9;
              a2[6] = (unsigned __int8 *)aInvalidDistanc;
              goto LABEL_96;
            }
LABEL_22:
            v63[3] = v22;
            v5 = v63;
            v63[2] = &v66[8 * *((_DWORD *)v66 + 1)];
          }
          continue;
        }
        while ( v72 != 0 )
        {
          v29 = v7;
          --v72;
          v7 += 8;
          a3 = 0;
          v30 = (*v6 << v29) | v71;
          v28 = v68;
          ++v6;
          v71 = v30;
          if ( v7 >= v68 )
            goto LABEL_32;
        }
LABEL_86:
        a1[7] = v7;
        a1[8] = v71;
        v54 = a2[2];
        v55 = (unsigned __int8 *)(v6 - *a2);
        a2[1] = nullptr;
        *a2 = v6;
        a2[2] = &v54[(_DWORD)v55];
        a1[13] = v9;
        return inflate_flush(a1, a2, a3);
      case 3:
        goto LABEL_29;
      case 4:
        v33 = v5[2];
        for ( k = v33; v7 < k; v71 = v35 )
        {
          if ( v72 == 0 )
            goto LABEL_86;
          v34 = v7;
          --v72;
          v7 += 8;
          a3 = 0;
          v35 = (*v6 << v34) | v71;
          v33 = k;
          ++v6;
        }
        v63[3] += v71 & inflate_mask[v33];
        v71 >>= k;
        v7 -= k;
        *v63 = 5;
LABEL_40:
        v36 = v63[3];
        if ( (unsigned int)&v9[-a1[10]] >= v36 )
          v70 = &v9[-v36];
        else
          v70 = &v9[a1[11] - a1[10] - v63[3]];
        v5 = v63;
        if ( v63[1] != 0 )
        {
          do
          {
            if ( v64 == 0 )
            {
              if ( v9 != (_BYTE *)a1[11]
                || (v37 = a1[12], v38 = a1[10], v37 == v38)
                || ((v9 = (_BYTE *)a1[10], v38 >= v37) ? (v39 = a1[11] - v38) : (v39 = v37 - v38 - 1),
                    v64 = v39,
                    v39 == 0) )
              {
                a1[13] = v9;
                v40 = inflate_flush(a1, a2, a3);
                v9 = (_BYTE *)a1[13];
                v73 = v40;
                v41 = a1[12];
                if ( (unsigned int)v9 >= v41 )
                  v42 = a1[11] - (_DWORD)v9;
                else
                  v42 = v41 - (_DWORD)v9 - 1;
                v64 = v42;
                if ( v9 == (_BYTE *)a1[11] )
                {
                  v43 = a1[10];
                  if ( v41 != v43 )
                  {
                    v9 = (_BYTE *)a1[10];
                    if ( v43 >= v41 )
                      v44 = a1[11] - v43;
                    else
                      v44 = v41 - v43 - 1;
                    v64 = v44;
                  }
                }
                if ( v64 == 0 )
                {
LABEL_87:
                  a1[8] = v71;
                  a1[7] = v7;
                  v57 = *a2;
                  a2[1] = (unsigned __int8 *)v72;
                  a2[2] += v6 - v57;
                  v62 = v73;
                  goto LABEL_97;
                }
              }
              v5 = v63;
            }
            ++v9;
            a3 = 0;
            *(v9 - 1) = *v70++;
            --v64;
            if ( v70 == (_BYTE *)a1[11] )
              v70 = (_BYTE *)a1[10];
            v45 = v5[1] - 1;
            v5[1] = v45;
          }
          while ( v45 != 0 );
        }
        *v5 = 0;
        continue;
      case 5:
        goto LABEL_40;
      case 6:
        if ( v64 != 0 )
          goto LABEL_84;
        if ( v9 != (_BYTE *)a1[11]
          || (v46 = a1[12], v47 = a1[10], v46 == v47)
          || ((v9 = (_BYTE *)a1[10], v47 >= v46) ? (v48 = a1[11] - v47) : (v48 = v46 - v47 - 1), v64 = v48, v48 == 0) )
        {
          a1[13] = v9;
          v49 = inflate_flush(a1, a2, a3);
          v9 = (_BYTE *)a1[13];
          v73 = v49;
          v50 = a1[12];
          if ( (unsigned int)v9 >= v50 )
            v51 = a1[11] - (_DWORD)v9;
          else
            v51 = v50 - (_DWORD)v9 - 1;
          v64 = v51;
          if ( v9 == (_BYTE *)a1[11] )
          {
            v52 = a1[10];
            if ( v50 != v52 )
            {
              v9 = (_BYTE *)a1[10];
              if ( v52 >= v50 )
                v53 = a1[11] - v52;
              else
                v53 = v50 - v52 - 1;
              v64 = v53;
            }
          }
          if ( v64 == 0 )
            goto LABEL_87;
        }
        v5 = v63;
LABEL_84:
        a3 = 0;
        *v9++ = *((_BYTE *)v5 + 8);
        v10 = v64 - 1;
        *v5 = 0;
        goto LABEL_4;
      case 7:
        if ( v7 > 7 )
        {
          v7 -= 8;
          --v6;
          ++v72;
        }
        a1[13] = v9;
        v58 = inflate_flush(a1, a2, a3);
        v9 = (_BYTE *)a1[13];
        if ( (_BYTE *)a1[12] != v9 )
        {
          a1[7] = v7;
          a1[8] = v71;
          v59 = *a2;
          a2[1] = (unsigned __int8 *)v72;
          v62 = v58;
          a2[2] += v6 - v59;
          goto LABEL_97;
        }
        *v63 = 8;
LABEL_93:
        v62 = 1;
        goto LABEL_96;
      case 8:
        goto LABEL_93;
      case 9:
        a1[8] = v71;
        a1[7] = v7;
        v60 = *a2;
        a2[1] = (unsigned __int8 *)v72;
        v62 = -3;
        a2[2] += v6 - v60;
        goto LABEL_97;
      default:
        v62 = -2;
        goto LABEL_96;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035E10
// Name: _inflate_codes_free
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_codes_free(int a1, int a2)
{
  return (*(int (__cdecl **)(_DWORD, int))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10035E30
// Name: _inflate_trees_bits
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_trees_bits(int a1, _DWORD *a2, int a3, int a4, int a5)
{
  int v5; // ebx
  int v7; // eax
  int v8; // esi
  int v9; // [esp-10h] [ebp-1Ch]
  int v10; // [esp+8h] [ebp-4h] BYREF

  v10 = 0;
  v5 = (*(int (__cdecl **)(_DWORD, int, int))(a5 + 32))(a1: *(_DWORD *)(a5 + 40), a2: 19, a3: 4);
  if ( v5 == 0 )
    return -4;
  v7 = sub_10035EE0(a1, a2: 19, a3: 19, a4: 0, a5: 0, a6: a3, a7: a2, a8: a4, a9: &v10, a10: v5);
  v8 = v7;
  if ( v7 == -3 )
  {
    v9 = *(_DWORD *)(a5 + 40);
    *(_DWORD *)(a5 + 24) = aOversubscribed_0;
    (*(void (__cdecl **)(int, int))(a5 + 36))(a1: v9, a2: v5);
    return -3;
  }
  else
  {
    if ( v7 == -5 || *a2 == 0 )
    {
      *(_DWORD *)(a5 + 24) = aIncompleteDyna;
      v8 = -3;
    }
    (*(void (__cdecl **)(_DWORD, int))(a5 + 36))(a1: *(_DWORD *)(a5 + 40), a2: v5);
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035EE0
// Name: sub_10035EE0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_10035EE0(
        int *a1,
        unsigned int a2,
        unsigned int a3,
        int a4,
        int a5,
        _DWORD *a6,
        unsigned int *a7,
        int a8,
        unsigned int *a9,
        unsigned int *a10)
{
  unsigned int v10; // ebp
  int *v11; // ecx
  unsigned int v12; // edx
  int v13; // eax
  unsigned int v15; // eax
  unsigned int v16; // ecx
  unsigned int i; // esi
  int j; // edx
  int v19; // edx
  int v20; // ecx
  int v21; // edx
  int v22; // ecx
  unsigned int v23; // esi
  int v24; // edi
  int *v25; // esi
  unsigned int v26; // edi
  int v27; // ecx
  int v28; // esi
  unsigned int v29; // edi
  signed int v30; // ecx
  int v31; // ebx
  unsigned int v32; // esi
  unsigned int m; // ecx
  unsigned int v34; // edx
  unsigned int v35; // ecx
  unsigned int v36; // eax
  _DWORD *v37; // ebp
  unsigned int v38; // eax
  unsigned int v39; // edi
  unsigned int v40; // eax
  unsigned int v41; // edx
  int v42; // ebp
  unsigned int v43; // eax
  int v44; // ecx
  int v45; // esi
  int v46; // edx
  unsigned int v47; // eax
  _DWORD *v48; // ecx
  unsigned int k; // eax
  int v50; // eax
  unsigned int v51; // [esp+10h] [ebp-FCh]
  signed int v52; // [esp+14h] [ebp-F8h]
  int v53; // [esp+18h] [ebp-F4h]
  int v54; // [esp+1Ch] [ebp-F0h]
  int *v55; // [esp+20h] [ebp-ECh]
  unsigned int *v56; // [esp+20h] [ebp-ECh]
  _DWORD *v57; // [esp+24h] [ebp-E8h]
  signed int v58; // [esp+28h] [ebp-E4h]
  unsigned int v59; // [esp+2Ch] [ebp-E0h]
  unsigned int v60; // [esp+30h] [ebp-DCh]
  int v61; // [esp+30h] [ebp-DCh]
  int v62; // [esp+34h] [ebp-D8h]
  unsigned int v63; // [esp+38h] [ebp-D4h]
  signed int v64; // [esp+3Ch] [ebp-D0h]
  char v65; // [esp+40h] [ebp-CCh]
  unsigned int v66; // [esp+44h] [ebp-C8h]
  _DWORD *v67; // [esp+48h] [ebp-C4h]
  int v68; // [esp+4Ch] [ebp-C0h]
  int v69; // [esp+50h] [ebp-BCh] BYREF
  _DWORD v70[15]; // [esp+54h] [ebp-B8h] BYREF
  int v71; // [esp+90h] [ebp-7Ch]
  _DWORD v72[15]; // [esp+94h] [ebp-78h]
  _DWORD v73[15]; // [esp+D0h] [ebp-3Ch] BYREF
  int v74; // [esp+114h] [ebp+8h]

  v10 = 0;
  v69 = 0;
  memset(v70, 0, sizeof(v70));
  v11 = a1;
  v12 = a2;
  do
  {
    v13 = *v11++;
    --v12;
    ++v70[v13 - 1];
  }
  while ( v12 != 0 );
  if ( v69 == a2 )
  {
    *a6 = 0;
    *a7 = 0;
    return 0;
  }
  v15 = *a7;
  v16 = 1;
  v51 = *a7;
  do
  {
    if ( v70[v16 - 1] != 0 )
      break;
    ++v16;
  }
  while ( v16 <= 0xF );
  v52 = v16;
  if ( v15 < v16 )
  {
    v51 = v16;
    v15 = v16;
  }
  for ( i = 15; i != 0; --i )
  {
    if ( v70[i - 1] != 0 )
      break;
  }
  v58 = i;
  if ( v15 > i )
  {
    v51 = i;
    v15 = i;
  }
  *a7 = v15;
  for ( j = 1 << v16; v16 < i; j = 2 * v19 )
  {
    v19 = j - v70[v16 - 1];
    if ( v19 < 0 )
      return -3;
    ++v16;
  }
  v60 = i;
  v20 = v70[i - 1];
  v21 = j - v20;
  v68 = v21;
  if ( v21 < 0 )
    return -3;
  v72[0] = 0;
  v70[i - 1] = v21 + v20;
  v22 = 0;
  v23 = i - 1;
  if ( v23 != 0 )
  {
    v24 = 0;
    do
    {
      v22 += v70[v24++];
      --v23;
      v72[v24] = v22;
    }
    while ( v23 != 0 );
  }
  v25 = a1;
  v26 = 0;
  do
  {
    v27 = *v25++;
    v55 = v25;
    if ( v27 != 0 )
    {
      v28 = v72[v27 - 1];
      a10[v28] = v26;
      v72[v27 - 1] = v28 + 1;
      v25 = v55;
    }
    ++v26;
  }
  while ( v26 < a2 );
  v29 = 0;
  v59 = 0;
  v74 = v72[v60 - 1];
  v56 = a10;
  v30 = v52;
  v31 = -v15;
  v71 = 0;
  v53 = -1;
  v73[0] = 0;
  v61 = 0;
  if ( v52 > v58 )
  {
LABEL_66:
    if ( v21 == 0 || v58 == 1 )
      return 0;
    return -5;
  }
  else
  {
    v32 = v63;
    v65 = v52 - 1;
    v57 = &v70[v52 - 1];
    while ( 1 )
    {
      v54 = *v57;
      if ( *v57 != 0 )
        break;
LABEL_64:
      v52 = ++v30;
      ++v57;
      ++v65;
      if ( v30 > v58 )
      {
        v21 = v68;
        goto LABEL_66;
      }
    }
    while ( 1 )
    {
      --v54;
      if ( v52 > (int)(v31 + v15) )
        break;
LABEL_47:
      if ( v56 < &a10[v74] )
      {
        v32 = *v56;
        if ( *v56 >= a3 )
        {
          v45 = 4 * (v32 - a3);
          LOBYTE(v62) = *(_BYTE *)(v45 + a5) + 80;
          v32 = *(_DWORD *)(v45 + a4);
        }
        else
        {
          LOBYTE(v62) = v32 < 0x100 ? 0 : 96;
        }
        ++v56;
      }
      else
      {
        LOBYTE(v62) = -64;
      }
      v46 = 1 << (v52 - v31);
      v47 = v10 >> v31;
      if ( v10 >> v31 < v29 )
      {
        v48 = (_DWORD *)(v61 + 8 * v47);
        do
        {
          v48[1] = v32;
          BYTE1(v62) = v52 - v31;
          *v48 = v62;
          v47 += v46;
          v48 += 2 * v46;
        }
        while ( v47 < v29 );
        v10 = v59;
      }
      for ( k = 1 << v65; (k & v10) != 0; k >>= 1 )
        v10 ^= k;
      v10 ^= k;
      v50 = v53;
      v59 = v10;
      if ( (v10 & ((1 << v31) - 1)) != v72[v53 - 1] )
      {
        do
        {
          --v50;
          v31 -= v51;
        }
        while ( (v10 & ((1 << v31) - 1)) != v72[v50 - 1] );
        v53 = v50;
      }
      v15 = v51;
      if ( v54 == 0 )
      {
        v30 = v52;
        goto LABEL_64;
      }
    }
    v64 = v31 + v15;
    for ( m = v31 - v15; ; m = v66 )
    {
      v31 += v15;
      ++v53;
      v34 = v58 - v31;
      v66 = v15 + m;
      v64 += v15;
      if ( v58 - v31 > v15 )
        v34 = v15;
      v35 = v52 - v31;
      v36 = 1 << (v52 - v31);
      if ( v36 > v54 + 1 )
      {
        v37 = v57;
        v38 = -1 - v54 + v36;
        if ( v35 < v34 && ++v35 < v34 )
        {
          do
          {
            v39 = v37[1];
            ++v37;
            v40 = 2 * v38;
            if ( v40 <= v39 )
              break;
            v38 = v40 - v39;
            ++v35;
          }
          while ( v35 < v34 );
        }
      }
      v29 = 1 << v35;
      v41 = *a9 + (1 << v35);
      if ( v41 > 0x5A0 )
        break;
      v42 = a8 + 8 * *a9;
      v61 = v42;
      v67 = &v73[v53];
      *v67 = v42;
      *a9 = v41;
      if ( v53 != 0 )
      {
        LOBYTE(v62) = v35;
        v72[v53 - 1] = v59;
        v43 = v59 >> v66;
        BYTE1(v62) = v51;
        v44 = *(v67 - 1);
        v32 = ((v42 - v44) >> 3) - (v59 >> v66);
        *(_DWORD *)(v44 + 8 * v43) = v62;
        *(_DWORD *)(v44 + 8 * v43 + 4) = v32;
      }
      else
      {
        *a6 = v42;
      }
      if ( v52 <= v64 )
      {
        v10 = v59;
        goto LABEL_47;
      }
      v15 = v51;
    }
    return -4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036390
// Name: _inflate_trees_dynamic
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_trees_dynamic(
        unsigned int a1,
        unsigned int a2,
        int *a3,
        unsigned int *a4,
        unsigned int *a5,
        _DWORD *a6,
        _DWORD *a7,
        int a8,
        int a9)
{
  unsigned int *v9; // edi
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // [esp-Ch] [ebp-20h]
  int v15; // [esp-8h] [ebp-1Ch]
  int v16; // [esp-8h] [ebp-1Ch]
  int v17; // [esp-8h] [ebp-1Ch]
  unsigned int v18; // [esp+10h] [ebp-4h] BYREF

  v14 = *(_DWORD *)(a9 + 40);
  v18 = 0;
  v9 = (unsigned int *)(*(int (__cdecl **)(int, int, int))(a9 + 32))(a1: v14, a2: 288, a3: 4);
  if ( v9 == nullptr )
    return -4;
  v11 = sub_10035EE0(
          a1: a3,
          a2: a1,
          a3: 0x101u,
          a4: (int)&unk_10058DE0,
          a5: (int)&unk_10058E60,
          a6,
          a7: a4,
          a8,
          a9: &v18,
          a10: v9);
  v12 = v11;
  if ( v11 != 0 )
  {
    if ( v11 == -3 )
    {
      v17 = *(_DWORD *)(a9 + 40);
      *(_DWORD *)(a9 + 24) = aOversubscribed_1;
      (*(void (__cdecl **)(int, unsigned int *))(a9 + 36))(a1: v17, a2: v9);
      return -3;
    }
    if ( v11 == -4 )
      goto LABEL_20;
LABEL_19:
    *(_DWORD *)(a9 + 24) = aIncompleteLite;
    v12 = -3;
    goto LABEL_20;
  }
  if ( *a4 == 0 )
    goto LABEL_19;
  v13 = sub_10035EE0(
          a1: &a3[a1],
          a2,
          a3: 0,
          a4: (int)&unk_10058EE0,
          a5: (int)&unk_10058F58,
          a6: a7,
          a7: a5,
          a8,
          a9: &v18,
          a10: v9);
  v12 = v13;
  if ( v13 != 0 )
  {
    switch ( v13 )
    {
      case -3:
        v15 = *(_DWORD *)(a9 + 40);
        *(_DWORD *)(a9 + 24) = aOversubscribed;
        (*(void (__cdecl **)(int, unsigned int *))(a9 + 36))(a1: v15, a2: v9);
        return -3;
      case -5:
        v16 = *(_DWORD *)(a9 + 40);
        *(_DWORD *)(a9 + 24) = aIncompleteDist;
        (*(void (__cdecl **)(int, unsigned int *))(a9 + 36))(a1: v16, a2: v9);
        return -3;
      case -4:
        goto LABEL_20;
      default:
        break;
    }
  }
  else if ( *a5 != 0 || a1 <= 0x101 )
  {
    (*(void (__cdecl **)(_DWORD, unsigned int *))(a9 + 36))(a1: *(_DWORD *)(a9 + 40), a2: v9);
    return 0;
  }
  *(_DWORD *)(a9 + 24) = aEmptyDistanceT;
  v12 = -3;
LABEL_20:
  (*(void (__cdecl **)(_DWORD, unsigned int *))(a9 + 36))(a1: *(_DWORD *)(a9 + 40), a2: v9);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x10036520
// Name: _inflate_trees_fixed
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_trees_fixed(_DWORD *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  *a1 = dword_10061AD0;
  *a2 = dword_10061AD4;
  *a3 = &unk_10061AD8;
  *a4 = &unk_10062AD8;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10036550
// Name: _inflate_flush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_flush(_DWORD *a1, _DWORD *a2, int a3)
{
  unsigned int v3; // ebp
  char *v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // ebp
  unsigned int v7; // edx
  int (__cdecl *v8)(_DWORD, char *, unsigned int); // eax
  int v9; // eax
  char *v10; // eax
  char *v11; // ecx
  char *v12; // esi
  unsigned int v13; // ebp
  unsigned int v14; // eax
  unsigned int v15; // edx
  int (__cdecl *v16)(_DWORD, char *, unsigned int); // eax
  int v17; // eax
  char *v18; // edi
  char *v20; // [esp+10h] [ebp-4h]
  char *v21; // [esp+10h] [ebp-4h]

  v3 = a1[13];
  v4 = (char *)a1[12];
  v20 = (char *)a2[3];
  if ( (unsigned int)v4 > v3 )
    v3 = a1[11];
  v5 = a2[4];
  v6 = v3 - (_DWORD)v4;
  if ( v6 > v5 )
    v6 = a2[4];
  if ( v6 != 0 && a3 == -5 )
    a3 = 0;
  v7 = v6 + a2[5];
  a2[4] = v5 - v6;
  a2[5] = v7;
  v8 = (int (__cdecl *)(_DWORD, char *, unsigned int))a1[14];
  if ( v8 != nullptr )
  {
    v9 = v8(a1: a1[15], a2: v4, a3: v6);
    a1[15] = v9;
    a2[12] = v9;
  }
  qmemcpy(v20, v4, v6);
  v10 = &v4[v6];
  v11 = (char *)a1[11];
  v21 = &v20[v6];
  if ( &v4[v6] == v11 )
  {
    v12 = (char *)a1[10];
    if ( (char *)a1[13] == v11 )
      a1[13] = v12;
    v13 = a1[13] - (_DWORD)v12;
    v14 = a2[4];
    if ( v13 > v14 )
      v13 = a2[4];
    if ( v13 != 0 && a3 == -5 )
      a3 = 0;
    v15 = v13 + a2[5];
    a2[4] = v14 - v13;
    a2[5] = v15;
    v16 = (int (__cdecl *)(_DWORD, char *, unsigned int))a1[14];
    if ( v16 != nullptr )
    {
      v17 = v16(a1: a1[15], a2: v12, a3: v13);
      a1[15] = v17;
      a2[12] = v17;
    }
    qmemcpy(v21, v12, 4 * (v13 >> 2));
    v18 = &v21[4 * (v13 >> 2)];
    v21 += v13;
    v10 = &v12[v13];
    qmemcpy(v18, &v12[4 * (v13 >> 2)], v13 & 3);
  }
  a2[3] = v21;
  a1[12] = v10;
  return a3;
}

//------------------------------------------------------------------------------
// Address: 0x10036690
// Name: _inflate_fast
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_fast(int a1, int a2, int a3, unsigned __int8 *a4, _DWORD *a5, unsigned __int8 **a6)
{
  _BYTE *v6; // ebx
  unsigned int v7; // esi
  unsigned int v8; // edx
  unsigned __int8 **v9; // edi
  unsigned __int8 *v10; // ebp
  unsigned int v11; // eax
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx
  int v18; // ebx
  int v19; // esi
  unsigned __int8 *v20; // esi
  int i; // ecx
  int v22; // ecx
  int v23; // ebx
  unsigned int j; // ebx
  char v25; // cl
  unsigned int v26; // edi
  int v27; // esi
  _BYTE *v28; // ecx
  _BYTE *v29; // esi
  unsigned int v30; // edi
  unsigned int v31; // ecx
  unsigned __int8 *v32; // ebp
  unsigned __int8 *v33; // edx
  int v34; // ecx
  unsigned int v36; // ecx
  unsigned __int8 *v37; // ebp
  unsigned __int8 *v38; // edx
  unsigned __int8 *v39; // ecx
  unsigned int v40; // ecx
  unsigned __int8 *v41; // ebp
  unsigned __int8 *v42; // edx
  unsigned __int8 *v43; // ecx
  unsigned int v44; // [esp+10h] [ebp-14h]
  _BYTE *v45; // [esp+14h] [ebp-10h]
  unsigned int v46; // [esp+18h] [ebp-Ch]
  int v47; // [esp+1Ch] [ebp-8h]
  int v48; // [esp+20h] [ebp-4h]
  unsigned int v49; // [esp+28h] [ebp+4h]

  v6 = (_BYTE *)a5[13];
  v7 = a5[12];
  v8 = a5[8];
  v9 = a6;
  v45 = v6;
  v10 = *a6;
  v44 = (unsigned int)a6[1];
  v11 = a5[7];
  if ( (unsigned int)v6 >= v7 )
    v46 = a5[11] - (_DWORD)v6;
  else
    v46 = v7 - (_DWORD)v6 - 1;
  v47 = inflate_mask[a1];
  v48 = inflate_mask[a2];
  do
  {
    for ( ; v11 < 0x14; ++v10 )
    {
      --v44;
      v12 = *v10 << v11;
      v11 += 8;
      v8 |= v12;
    }
    v13 = *(unsigned __int8 *)(a3 + 8 * (v8 & v47));
    v14 = a3 + 8 * (v8 & v47);
    if ( *(_BYTE *)v14 != 0 )
    {
      while ( 1 )
      {
        v15 = *(unsigned __int8 *)(v14 + 1);
        v8 >>= v15;
        v11 -= v15;
        if ( (v13 & 0x10) != 0 )
          break;
        if ( (v13 & 0x40) != 0 )
        {
          if ( (v13 & 0x20) != 0 )
          {
            v36 = (unsigned int)&v9[1][-v44];
            if ( v11 >> 3 < v36 )
              v36 = v11 >> 3;
            v37 = &v10[-v36];
            a5[8] = v8;
            a5[7] = v11 - 8 * v36;
            v38 = *v9;
            v9[1] = (unsigned __int8 *)(v44 + v36);
            v39 = v9[2];
            *v9 = v37;
            v9[2] = &v39[v37 - v38];
            a5[13] = v45;
            return 1;
          }
          else
          {
            v9[6] = (unsigned __int8 *)aInvalidLiteral;
LABEL_40:
            v40 = (unsigned int)&v9[1][-v44];
            if ( v11 >> 3 < v40 )
              v40 = v11 >> 3;
            v41 = &v10[-v40];
            a5[8] = v8;
            a5[7] = v11 - 8 * v40;
            v42 = *v9;
            v9[1] = (unsigned __int8 *)(v44 + v40);
            v43 = v9[2];
            *v9 = v41;
            v9[2] = &v43[v41 - v42];
            a5[13] = v45;
            return -3;
          }
        }
        v16 = *(_DWORD *)(v14 + 4) + (v8 & inflate_mask[v13]);
        v13 = *(unsigned __int8 *)(v14 + 8 * v16);
        v14 += 8 * v16;
        if ( v13 == 0 )
          goto LABEL_11;
      }
      v18 = v13 & 0xF;
      v11 -= v18;
      v49 = *(_DWORD *)(v14 + 4) + (v8 & inflate_mask[v18]);
      for ( v8 >>= v18; v11 < 0xF; ++v10 )
      {
        --v44;
        v19 = *v10 << v11;
        v11 += 8;
        v8 |= v19;
      }
      v20 = a4;
      for ( i = v8 & v48; ; i = *((_DWORD *)v20 + 1) + (v8 & inflate_mask[v23]) )
      {
        v20 += 8 * i;
        v22 = v20[1];
        v23 = *v20;
        v8 >>= v22;
        v11 -= v22;
        if ( (v23 & 0x10) != 0 )
          break;
        if ( (v23 & 0x40) != 0 )
        {
          v9[6] = (unsigned __int8 *)aInvalidDistanc;
          goto LABEL_40;
        }
      }
      for ( j = v23 & 0xF; v11 < j; ++v10 )
      {
        --v44;
        v25 = v11;
        v11 += 8;
        v8 |= *v10 << v25;
      }
      v26 = *((_DWORD *)v20 + 1) + (v8 & inflate_mask[j]);
      v8 >>= j;
      v11 -= j;
      v46 -= v49;
      v27 = a5[10];
      v28 = v45;
      if ( (unsigned int)&v45[-v27] < v26 )
      {
        v30 = v26 + v27 - (_DWORD)v45;
        v29 = (_BYTE *)(a5[11] - v30);
        if ( v49 > v30 )
        {
          v49 -= v30;
          do
          {
            *v28++ = *v29++;
            --v30;
          }
          while ( v30 != 0 );
          v29 = (_BYTE *)a5[10];
        }
      }
      else
      {
        *v45 = v45[-v26];
        v28 = v45 + 2;
        v29 = &v45[-v26 + 2];
        v45[1] = v45[-v26 + 1];
        v49 -= 2;
      }
      do
      {
        *v28++ = *v29++;
        --v49;
      }
      while ( v49 != 0 );
      v9 = a6;
      v45 = v28;
    }
    else
    {
LABEL_11:
      v17 = *(unsigned __int8 *)(v14 + 1);
      v11 -= v17;
      v8 >>= v17;
      *v45++ = *(_BYTE *)(v14 + 4);
      --v46;
    }
  }
  while ( v46 >= 0x102 && v44 >= 0xA );
  v31 = (unsigned int)&v9[1][-v44];
  if ( v11 >> 3 < v31 )
    v31 = v11 >> 3;
  v32 = &v10[-v31];
  a5[8] = v8;
  a5[7] = v11 - 8 * v31;
  v33 = *v9;
  v9[1] = (unsigned __int8 *)(v44 + v31);
  v34 = (int)&v9[2][v32 - v33];
  *v9 = v32;
  v9[2] = (unsigned __int8 *)v34;
  a5[13] = v45;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100369F0
// Name: public: virtual std::length_error::~length_error(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall std::length_error::~length_error(std::out_of_range *this)
{
  std::exception::~exception(this);
}

//------------------------------------------------------------------------------
// Address: 0x100369F5
// Name: public: std::logic_error::logic_error(class std::logic_error const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::logic_error *__thiscall std::logic_error::logic_error(std::logic_error *this, const std::logic_error *__that)
{
  std::exception::exception(this, _That: __that);
  this->__vftable = (std::logic_error_vtbl *)&std::logic_error::`vftable';
  return this;
}

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10019D20
// Name: public: CShuffledWorkUnitWalker::CShuffledWorkUnitWalker(void)
// Source: json
//------------------------------------------------------------------------------
CShuffledWorkUnitWalker *__thiscall CShuffledWorkUnitWalker::CShuffledWorkUnitWalker(CShuffledWorkUnitWalker *this)
{
  this->m_CompletedWUBits.m_Memory.m_pMemory = nullptr;
  this->m_CompletedWUBits.m_Memory.m_nAllocationCount = 0;
  this->m_CompletedWUBits.m_Memory.m_nGrowSize = 0;
  this->m_CompletedWUBits.m_Size = 0;
  this->m_CompletedWUBits.m_pElements = nullptr;
  this->m_WorkUnitsRemaining.m_Memory.m_pMemory = nullptr;
  this->m_WorkUnitsRemaining.m_Memory.m_nAllocationCount = 0;
  this->m_WorkUnitsRemaining.m_Memory.m_nGrowSize = 0;
  this->m_WorkUnitsRemaining.m_LastAlloc.index = -1;
  this->m_WorkUnitsRemaining.m_Head = -1;
  this->m_WorkUnitsRemaining.m_Tail = -1;
  this->m_WorkUnitsRemaining.m_FirstFree = -1;
  this->m_WorkUnitsRemaining.m_pElements = this->m_WorkUnitsRemaining.m_Memory.m_pMemory;
  this->m_WorkUnitsRemaining.m_ElementCount = 0;
  this->m_WorkUnitsRemaining.m_NumAlloced = 0;
  this->m_WorkUnitsMap.m_Memory.m_pMemory = nullptr;
  this->m_WorkUnitsMap.m_Memory.m_nAllocationCount = 0;
  this->m_WorkUnitsMap.m_Memory.m_nGrowSize = 0;
  this->m_WorkUnitsMap.m_Size = 0;
  this->m_WorkUnitsMap.m_pElements = nullptr;
  this->m_LocalCompletedWUBits.m_Memory.m_pMemory = nullptr;
  this->m_LocalCompletedWUBits.m_Memory.m_nAllocationCount = 0;
  this->m_LocalCompletedWUBits.m_Memory.m_nGrowSize = 0;
  this->m_LocalCompletedWUBits.m_Size = 0;
  this->m_LocalCompletedWUBits.m_pElements = nullptr;
  this->m_Walker.m_WorkerInfos.m_Memory.m_pMemory = nullptr;
  this->m_Walker.m_WorkerInfos.m_Memory.m_nAllocationCount = 0;
  this->m_Walker.m_WorkerInfos.m_Memory.m_nGrowSize = 0;
  this->m_Walker.m_WorkerInfos.m_Size = 0;
  this->m_Walker.m_WorkerInfos.m_pElements = nullptr;
  this->m_Walker.m_nWorkUnits = 0;
  CCriticalSection::CCriticalSection(this: &this->m_CS);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10019DD0
// Name: public: CShuffledWorkUnitWalker::~CShuffledWorkUnitWalker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShuffledWorkUnitWalker::~CShuffledWorkUnitWalker(CShuffledWorkUnitWalker *this)
{
  CCriticalSection::~CCriticalSection(this: &this->m_CS);
  CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_Walker.m_WorkerInfos);
  CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_LocalCompletedWUBits);
  CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_WorkUnitsMap);
  CUtlLinkedList<unsigned __int64,unsigned __int64,0,unsigned __int64,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>>::RemoveAll(this: &this->m_WorkUnitsRemaining);
  if ( this->m_WorkUnitsRemaining.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_WorkUnitsRemaining.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WorkUnitsRemaining.m_Memory.m_pMemory);
      this->m_WorkUnitsRemaining.m_Memory.m_pMemory = nullptr;
    }
    this->m_WorkUnitsRemaining.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>((CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10019E40
// Name: public: void CDSInfo::ReadWUIndex(unsigned __int64 __near *,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDSInfo::ReadWUIndex(CDSInfo *this, unsigned __int8 *pWU, MessageBuffer *pBuf)
{
  if ( HIDWORD(this->m_nWorkUnits) != 0 )
  {
    MessageBuffer::read(this: pBuf, p: pWU, bytes: 8u);
  }
  else if ( LODWORD(this->m_nWorkUnits) > 0xFFFF )
  {
    MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&pBuf, bytes: 4u);
    *(_QWORD *)pWU = (unsigned int)pBuf;
  }
  else
  {
    MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&pBuf, bytes: 2u);
    *(_QWORD *)pWU = (unsigned __int16)pBuf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019EC0
// Name: public: virtual void CDistributor_SDKWorker::RequestShuffle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKWorker::RequestShuffle(CDistributor_SDKWorker *this)
{
  int Name; // eax
  MessageBuffer mb; // [esp+0h] [ebp-10h] BYREF

  MessageBuffer::MessageBuffer(this: &mb);
  PrepareDistributeWorkHeader(pBuf: &mb, cSubpacketID: 0x33u);
  Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  VMPI_SendData(pData: mb.data, nBytes: Name, iDest: 0, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x10019FA0
// Name: public: virtual void CDistributor_SDKWorker::NoteLocalWorkUnitCompleted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKWorker::NoteLocalWorkUnitCompleted(CDistributor_SDKWorker *this, unsigned __int64 iWU)
{
  unsigned __int8 *v3; // eax
  CCriticalSectionLock v4; // [esp+4h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &v4, pCS: &this->m_WorkUnitWalker.m_CS);
  CCriticalSectionLock::Lock(this: &v4);
  v3 = &this->m_WorkUnitWalker.m_LocalCompletedWUBits.m_Memory.m_pMemory[iWU >> 3];
  *v3 |= 1 << (iWU & 7);
  CCriticalSectionLock::~CCriticalSectionLock(this: &v4);
}

//------------------------------------------------------------------------------
// Address: 0x10019FF0
// Name: public: bool CWorkUnitWalker::GetNextWorkUnit(int,unsigned __int64 __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWorkUnitWalker::GetNextWorkUnit(
        CWorkUnitWalker *this,
        int iWorker,
        unsigned __int64 *pWUIndex,
        bool *bWorkerFinishedHisColumn)
{
  CWorkUnitWalker::CWorkerInfo *v5; // edi
  unsigned int m_iWorkUnitOffset_high; // eax
  unsigned int m_iWorkUnitOffset; // ecx
  unsigned __int64 v8; // rax
  bool v9; // cf

  if ( iWorker < 0 )
    return 0;
  if ( iWorker >= this->m_WorkerInfos.m_Size )
    return 0;
  v5 = &this->m_WorkerInfos.m_Memory.m_pMemory[iWorker];
  m_iWorkUnitOffset_high = HIDWORD(v5->m_iWorkUnitOffset);
  m_iWorkUnitOffset = v5->m_iWorkUnitOffset;
  if ( __PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) >= this->m_nWorkUnits )
    return 0;
  if ( __PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) < this->m_MatrixWidth )
  {
    *bWorkerFinishedHisColumn = false;
  }
  else
  {
    v8 = (__PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) / this->m_MatrixWidth + 1) * this->m_MatrixWidth
       - __PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) % this->m_MatrixWidth
       - 1;
    m_iWorkUnitOffset = v8;
    m_iWorkUnitOffset_high = HIDWORD(v8);
    *bWorkerFinishedHisColumn = true;
  }
  *pWUIndex = (__PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) + v5->m_iStartWorkUnit) % this->m_nWorkUnits;
  v9 = __CFADD__(LODWORD(v5->m_iWorkUnitOffset)++, 1);
  HIDWORD(v5->m_iWorkUnitOffset) += v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001A0C0
// Name: public: bool CShuffledWorkUnitWalker::Thread_GetNextWorkUnit(int,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShuffledWorkUnitWalker::Thread_GetNextWorkUnit(
        CShuffledWorkUnitWalker *this,
        int iWorker,
        unsigned __int64 *pWUIndex)
{
  unsigned __int64 *m_pMemory; // eax
  int v5; // ecx
  int v6; // edx
  unsigned __int8 v7; // al
  int v8; // ecx
  unsigned __int64 v9; // rt0
  unsigned __int64 iUnmappedWorkUnit; // [esp+Ch] [ebp-14h] BYREF
  CCriticalSectionLock csLock; // [esp+14h] [ebp-Ch] BYREF
  bool bWorkerFinishedHisColumn; // [esp+1Fh] [ebp-1h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  if ( CWorkUnitWalker::GetNextWorkUnit(
         this: &this->m_Walker,
         iWorker,
         pWUIndex: &iUnmappedWorkUnit,
         &bWorkerFinishedHisColumn) != 0 )
  {
    while ( 1 )
    {
      if ( bWorkerFinishedHisColumn
        && this->m_iLastShuffleRequest != this->m_iCurShuffle
        && _Plat_FloatTime() - this->m_flLastShuffleTime > 2.0 )
      {
        this->m_pShuffleRequester->RequestShuffle(this: this->m_pShuffleRequester);
        this->m_iLastShuffleRequest = this->m_iCurShuffle;
      }
      m_pMemory = this->m_WorkUnitsMap.m_Memory.m_pMemory;
      v5 = iUnmappedWorkUnit;
      v6 = m_pMemory[iUnmappedWorkUnit];
      *(_DWORD *)pWUIndex = v6;
      *((_DWORD *)pWUIndex + 1) = HIDWORD(m_pMemory[v5]);
      v7 = 1 << (v6 & 7);
      LODWORD(v9) = v6;
      HIDWORD(v9) = *((_DWORD *)pWUIndex + 1);
      v8 = v9 >> 3;
      if ( (v7 & this->m_CompletedWUBits.m_Memory.m_pMemory[v8]) == 0
        && (v7 & this->m_LocalCompletedWUBits.m_Memory.m_pMemory[v8]) == 0 )
      {
        break;
      }
      if ( CWorkUnitWalker::GetNextWorkUnit(
             this: &this->m_Walker,
             iWorker,
             pWUIndex: &iUnmappedWorkUnit,
             &bWorkerFinishedHisColumn) == 0 )
        goto LABEL_9;
    }
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 1;
  }
  else
  {
LABEL_9:
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A1D0
// Name: public: virtual bool CDistributor_SDKWorker::GetNextWorkUnit(unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_SDKWorker::GetNextWorkUnit(CDistributor_SDKWorker *this, unsigned __int64 *pWUIndex)
{
  int m_iMyWorkUnitWalkerID; // eax

  m_iMyWorkUnitWalkerID = this->m_iMyWorkUnitWalkerID;
  if ( m_iMyWorkUnitWalkerID == -1 )
    return 0;
  else
    return CShuffledWorkUnitWalker::Thread_GetNextWorkUnit(
             this: &this->m_WorkUnitWalker,
             iWorker: m_iMyWorkUnitWalkerID,
             pWUIndex);
}

//------------------------------------------------------------------------------
// Address: 0x1001A3A0
// Name: public: unsigned long CShuffledWorkUnitWalker::GetShuffleCRC(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CShuffledWorkUnitWalker::GetShuffleCRC(CShuffledWorkUnitWalker *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<unsigned __int64,unsigned __int64> *m_pMemory; // eax
  int v4; // esi
  int i; // esi
  unsigned int v6; // esi
  CCriticalSectionLock csLock; // [esp+4h] [ebp-14h] BYREF
  unsigned __int64 iWorkUnit; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int ret; // [esp+14h] [ebp-4h] BYREF

  if ( (`CShuffledWorkUnitWalker::GetShuffleCRC'::`2'::`local static guard' & 1) == 0 )
  {
    `CShuffledWorkUnitWalker::GetShuffleCRC'::`2'::`local static guard' |= 1u;
    `CShuffledWorkUnitWalker::GetShuffleCRC'::`2'::bCalcShuffleCRC = VMPI_IsParamUsed(eParam: mpi_CalcShuffleCRC);
  }
  if ( !`CShuffledWorkUnitWalker::GetShuffleCRC'::`2'::bCalcShuffleCRC )
    return 0;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  CRC32_Init(pulCRC: &ret);
  m_Head = this->m_WorkUnitsRemaining.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_WorkUnitsRemaining.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      iWorkUnit = m_pMemory[v4].m_Element;
      CRC32_ProcessBuffer(pulCRC: &ret, pBuffer: &iWorkUnit, nBuffer: 8);
      m_pMemory = this->m_WorkUnitsRemaining.m_Memory.m_pMemory;
      m_Head = m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  for ( i = 0; i < this->m_WorkUnitsMap.m_Size; ++i )
  {
    iWorkUnit = this->m_WorkUnitsMap.m_Memory.m_pMemory[i];
    CRC32_ProcessBuffer(pulCRC: &ret, pBuffer: &iWorkUnit, nBuffer: 8);
  }
  CRC32_Final(pulCRC: &ret);
  v6 = ret;
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1001A5C0
// Name: public: void CWorkUnitWalker::Init(unsigned __int64,unsigned __int64,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkUnitWalker::Init(
        CWorkUnitWalker *this,
        unsigned __int64 matrixWidth,
        unsigned __int64 matrixHeight,
        unsigned __int64 nWorkUnits)
{
  int v5; // esi
  __int64 v6; // rax
  CWorkUnitWalker::CWorkerInfo *m_pMemory; // eax
  int v8; // [esp+28h] [ebp+1Ch]

  this->m_nWorkUnits = nWorkUnits;
  this->m_MatrixWidth = matrixWidth;
  v5 = 0;
  this->m_MatrixHeight = matrixHeight;
  this->m_WorkerInfos.m_Size = 0;
  if ( SLODWORD(this->m_MatrixHeight) > 0 )
    CUtlVector<CWorkUnitWalker::CWorkerInfo,CUtlMemory<CWorkUnitWalker::CWorkerInfo,int>>::InsertMultipleBefore(
      this: &this->m_WorkerInfos,
      elem: 0,
      num: this->m_MatrixHeight);
  v8 = 0;
  if ( HIDWORD(this->m_MatrixHeight) != 0 || LODWORD(this->m_MatrixHeight) != 0 )
  {
    v6 = 0;
    do
    {
      this->m_WorkerInfos.m_Memory.m_pMemory[v5].m_iStartWorkUnit = v6 * matrixWidth;
      m_pMemory = this->m_WorkerInfos.m_Memory.m_pMemory;
      LODWORD(m_pMemory[v5].m_iWorkUnitOffset) = 0;
      HIDWORD(m_pMemory[v5].m_iWorkUnitOffset) = 0;
      v6 = ++v8;
      ++v5;
    }
    while ( v8 < this->m_MatrixHeight );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A670
// Name: public: void CShuffledWorkUnitWalker::Shuffle(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShuffledWorkUnitWalker::Shuffle(CShuffledWorkUnitWalker *this, int nWorkers)
{
  CShuffledWorkUnitWalker *v2; // edi
  int m_ElementCount; // eax
  int m_Head; // esi
  UtlLinkedListElem_t<unsigned __int64,unsigned __int64> *m_pMemory; // edi
  int v6; // esi
  int v7; // ecx
  unsigned __int64 *v8; // eax
  unsigned int v9; // kr00_4
  int m_Element; // edx
  unsigned __int64 m_ElementCount_low; // [esp-14h] [ebp-48h]
  CCriticalSectionLock csLock; // [esp+10h] [ebp-24h] BYREF
  unsigned __int64 matrixHeight; // [esp+18h] [ebp-1Ch]
  unsigned __int64 iWorkUnit; // [esp+20h] [ebp-14h]
  unsigned __int64 matrixWidth; // [esp+28h] [ebp-Ch]
  CShuffledWorkUnitWalker *v16; // [esp+30h] [ebp-4h]

  v2 = this;
  v16 = this;
  if ( nWorkers != 0 )
  {
    ++this->m_iCurShuffle;
    this->m_flLastShuffleTime = _Plat_FloatTime();
    CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &v2->m_CS);
    CCriticalSectionLock::Lock(this: &csLock);
    v2->m_WorkUnitsMap.m_Size = 0;
    m_ElementCount = v2->m_WorkUnitsRemaining.m_ElementCount;
    if ( v2->m_WorkUnitsMap.m_Size < m_ElementCount )
      CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(
        this: &v2->m_WorkUnitsMap,
        elem: v2->m_WorkUnitsMap.m_Size,
        num: m_ElementCount - v2->m_WorkUnitsMap.m_Size);
    m_ElementCount_low = SLODWORD(v2->m_WorkUnitsRemaining.m_ElementCount);
    matrixHeight = nWorkers;
    matrixWidth = m_ElementCount_low / nWorkers;
    if ( m_ElementCount_low % nWorkers != 0 )
      ++matrixWidth;
    m_Head = v2->m_WorkUnitsRemaining.m_Head;
    iWorkUnit = 0;
    if ( m_Head != -1 )
    {
      m_pMemory = v2->m_WorkUnitsRemaining.m_Memory.m_pMemory;
      do
      {
        v6 = m_Head;
        v7 = iWorkUnit / matrixHeight + matrixWidth * (iWorkUnit % matrixHeight);
        v8 = v16->m_WorkUnitsMap.m_Memory.m_pMemory;
        v9 = iWorkUnit;
        LODWORD(iWorkUnit) = iWorkUnit + 1;
        m_Element = m_pMemory[v6].m_Element;
        iWorkUnit = __PAIR64__(HIDWORD(iWorkUnit), v9) + 1;
        LODWORD(v8[v7]) = m_Element;
        HIDWORD(v8[v7]) = HIDWORD(m_pMemory[v6].m_Element);
        m_pMemory = v16->m_WorkUnitsRemaining.m_Memory.m_pMemory;
        m_Head = m_pMemory[v6].m_Next;
      }
      while ( m_Head != -1 );
      v2 = v16;
    }
    CWorkUnitWalker::Init(
      this: &v2->m_Walker,
      matrixWidth,
      matrixHeight,
      nWorkUnits: SLODWORD(v2->m_WorkUnitsRemaining.m_ElementCount));
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A7A0
// Name: public: void CShuffledWorkUnitWalker::Thread_NoteWorkUnitCompleted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShuffledWorkUnitWalker::Thread_NoteWorkUnitCompleted(
        CShuffledWorkUnitWalker *this,
        unsigned __int64 iWU)
{
  unsigned __int8 *m_pMemory; // esi
  UtlLinkedListElem_t<unsigned __int64,unsigned __int64> *v4; // eax
  int v5; // ecx
  int v6; // eax
  CCriticalSectionLock csLock; // [esp+Ch] [ebp-10h] BYREF
  int v8; // [esp+14h] [ebp-8h]
  unsigned __int8 v9; // [esp+1Bh] [ebp-1h]

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  m_pMemory = this->m_CompletedWUBits.m_Memory.m_pMemory;
  v9 = 1 << (iWU & 7);
  v8 = iWU >> 3;
  if ( (v9 & m_pMemory[v8]) == 0 )
  {
    CUtlLinkedList<unsigned __int64,unsigned __int64,0,unsigned __int64,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>>::Unlink(
      this: &this->m_WorkUnitsRemaining,
      elem: iWU);
    v4 = this->m_WorkUnitsRemaining.m_Memory.m_pMemory;
    v5 = 3 * iWU;
    *((_DWORD *)&v4->m_Next + 2 * v5) = this->m_WorkUnitsRemaining.m_FirstFree;
    *((_DWORD *)&v4->m_Next + 2 * v5 + 1) = HIDWORD(this->m_WorkUnitsRemaining.m_FirstFree);
    LOBYTE(v5) = v9;
    HIDWORD(this->m_WorkUnitsRemaining.m_FirstFree) = HIDWORD(iWU);
    v6 = v8;
    LODWORD(this->m_WorkUnitsRemaining.m_FirstFree) = iWU;
    this->m_CompletedWUBits.m_Memory.m_pMemory[v6] |= v5;
  }
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x1001A830
// Name: public: virtual bool CDistributor_SDKWorker::HandlePacket(class MessageBuffer __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CDistributor_SDKWorker::HandlePacket(
        CDistributor_SDKWorker *this,
        MessageBuffer *pBuf,
        int iSource,
        unsigned __int16 bIgnoreContents)
{
  MessageBuffer *v4; // esi
  char v5; // al
  int v7; // edx
  unsigned int ShuffleCRC; // eax
  unsigned int v10; // ebx
  unsigned __int64 iWU; // [esp+8h] [ebp-18h] BYREF
  unsigned __int64 nCompleted; // [esp+10h] [ebp-10h] BYREF
  __int64 v13; // [esp+18h] [ebp-8h] OVERLAPPED BYREF

  v4 = pBuf;
  v5 = pBuf->data[1];
  if ( v5 == 50 )
  {
    if ( (_BYTE)bIgnoreContents == 0 )
    {
      MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&pBuf, bytes: 2u);
      MessageBuffer::read(this: v4, p: (unsigned __int8 *)&v13 + 4, bytes: 4u);
      MessageBuffer::read(this: v4, p: (unsigned __int8 *)&bIgnoreContents, bytes: 2u);
      v7 = (unsigned __int16)pBuf;
      this->m_iMyWorkUnitWalkerID = bIgnoreContents;
      CShuffledWorkUnitWalker::Shuffle(this: &this->m_WorkUnitWalker, nWorkers: v7);
      ShuffleCRC = CShuffledWorkUnitWalker::GetShuffleCRC(this: &this->m_WorkUnitWalker);
      if ( ShuffleCRC != HIDWORD(v13) && ++`CDistributor_SDKWorker::HandlePacket'::`10'::nWarnings <= 2 )
        _Warning(a1: "\nShuffle CRC mismatch\n");
    }
    return 1;
  }
  if ( v5 != 52 )
    return 0;
  if ( (_BYTE)bIgnoreContents != 0 )
    return 1;
  CDSInfo::ReadWUIndex(this: this->m_pInfo, pWU: (unsigned __int8 *)&nCompleted, pBuf);
  v13 = 0;
  if ( nCompleted != 0 )
  {
    v10 = HIDWORD(v13);
    do
    {
      CDSInfo::ReadWUIndex(this: this->m_pInfo, pWU: (unsigned __int8 *)&iWU, pBuf: v4);
      CShuffledWorkUnitWalker::Thread_NoteWorkUnitCompleted(this: &this->m_WorkUnitWalker, iWU);
      v10 = (__PAIR64__(v10, v13) + 1) >> 32;
      LODWORD(v13) = v13 + 1;
    }
    while ( __PAIR64__(v10, v13) < nCompleted );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001A940
// Name: public: CDistributor_SDKMaster::CDistributor_SDKMaster(void)
// Source: json
//------------------------------------------------------------------------------
CDistributor_SDKMaster *__thiscall CDistributor_SDKMaster::CDistributor_SDKMaster(CDistributor_SDKMaster *this)
{
  this->IShuffleRequester::__vftable = (IShuffleRequester_vtbl *)&IShuffleRequester::`vftable';
  this->IWorkUnitDistributorMaster::__vftable = (CDistributor_SDKMaster_vtbl *)&CDistributor_SDKMaster::`vftable'{for `IWorkUnitDistributorMaster'};
  this->IShuffleRequester::__vftable = (IShuffleRequester_vtbl *)&CDistributor_SDKMaster::`vftable'{for `IShuffleRequester'};
  CCriticalSection::CCriticalSection(this: &this->m_WorkersReadyCS);
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Memory.m_pMemory = nullptr;
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Memory.m_nAllocationCount = 0;
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Memory.m_nGrowSize = 0;
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Size = 0;
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_pElements = nullptr;
  CCriticalSection::CCriticalSection(this: &this->m_WUsCompletedCS);
  this->m_WUsCompletedCS.m_Data.m_Completed.m_Memory.m_pMemory = nullptr;
  this->m_WUsCompletedCS.m_Data.m_Completed.m_Memory.m_nAllocationCount = 0;
  this->m_WUsCompletedCS.m_Data.m_Completed.m_Memory.m_nGrowSize = 0;
  this->m_WUsCompletedCS.m_Data.m_Completed.m_Size = 0;
  this->m_WUsCompletedCS.m_Data.m_Completed.m_pElements = nullptr;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_Memory.m_pMemory = nullptr;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_Memory.m_nAllocationCount = 0;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_Memory.m_nGrowSize = 0;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_Size = 0;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_pElements = nullptr;
  MessageBuffer::MessageBuffer(this: &this->m_WUSCompletedMessageBuffer);
  CShuffledWorkUnitWalker::CShuffledWorkUnitWalker(this: &this->m_WorkUnitWalker);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001A9E0
// Name: public: void CDSInfo::WriteWUIndex(unsigned __int64,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDSInfo::WriteWUIndex(CDSInfo *this, unsigned __int64 iWU, MessageBuffer *pBuf)
{
  unsigned int val; // [esp+0h] [ebp-4h] BYREF

  val = (unsigned int)this;
  if ( HIDWORD(this->m_nWorkUnits) != 0 )
  {
    MessageBuffer::write(this: pBuf, p: (unsigned __int8 *)&iWU, bytes: 8u);
  }
  else if ( LODWORD(this->m_nWorkUnits) > 0xFFFF )
  {
    val = iWU;
    MessageBuffer::write(this: pBuf, p: (unsigned __int8 *)&val, bytes: 4u);
  }
  else
  {
    val = (unsigned __int16)iWU;
    MessageBuffer::write(this: pBuf, p: (unsigned __int8 *)&val, bytes: 2u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001AA60
// Name: public: virtual void CDistributor_SDKMaster::RequestShuffle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::RequestShuffle(CDistributor_SDKMaster *this)
{
  BYTE1(this->m_bUsingMasterLocalThreads) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001AA70
// Name: public: virtual bool CDistributor_SDKMaster::HandlePacket(class MessageBuffer __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_SDKMaster::HandlePacket(
        CDistributor_SDKMaster *this,
        MessageBuffer *pBuf,
        int iSource,
        bool bIgnoreContents)
{
  if ( pBuf->data[1] == 51 )
  {
    if ( bIgnoreContents )
      return 1;
    this->m_bShuffleRequested = true;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001AAA0
// Name: public: void CDistributor_SDKMaster::Master_WorkerThread(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::Master_WorkerThread(CDistributor_SDKMaster *this, int iThread)
{
  CShuffledWorkUnitWalker *p_m_WorkUnitWalker; // ebx
  CCriticalSection *p_m_CS; // esi
  int v4; // edi
  unsigned __int64 v5; // kr08_8
  unsigned __int8 *v6; // eax
  int v7; // edi
  CCriticalSectionLock v8; // [esp+Ch] [ebp-24h] BYREF
  unsigned __int64 iWU; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int m_ElementCount; // [esp+1Ch] [ebp-14h]
  CCriticalSectionLock v11; // [esp+24h] [ebp-Ch] BYREF
  CDistributor_SDKMaster *v12; // [esp+2Ch] [ebp-4h]

  p_m_WorkUnitWalker = &this->m_WorkUnitWalker;
  v12 = this;
  p_m_CS = &this->m_WorkUnitWalker.m_CS;
  CCriticalSectionLock::CCriticalSectionLock(this: &v11, pCS: &this->m_WorkUnitWalker.m_CS);
  CCriticalSectionLock::Lock(this: &v11);
  v4 = SLODWORD(p_m_WorkUnitWalker->m_WorkUnitsRemaining.m_ElementCount) >> 31;
  m_ElementCount = p_m_WorkUnitWalker->m_WorkUnitsRemaining.m_ElementCount;
  CCriticalSectionLock::~CCriticalSectionLock(this: &v11);
  if ( __PAIR64__(v4, m_ElementCount) != 0 )
  {
    while ( !g_bVMPIEarlyExit )
    {
      if ( CShuffledWorkUnitWalker::Thread_GetNextWorkUnit(this: p_m_WorkUnitWalker, iWorker: 0, pWUIndex: &iWU) != 0 )
      {
        CCriticalSectionLock::CCriticalSectionLock(this: &v8, pCS: p_m_CS);
        CCriticalSectionLock::Lock(this: &v8);
        v5 = iWU;
        v6 = &p_m_WorkUnitWalker->m_LocalCompletedWUBits.m_Memory.m_pMemory[iWU >> 3];
        *v6 |= 1 << (iWU & 7);
        CCriticalSectionLock::~CCriticalSectionLock(this: &v8);
        ((void (__cdecl *)(int, _DWORD, _DWORD, _DWORD))v12->m_pInfo->m_WorkerInfo.m_pProcessFn)(
          a1: iThread,
          a2: v5,
          a3: HIDWORD(v5),
          a4: 0);
        NotifyLocalMasterCompletedWorkUnit(iWorkUnit: v5);
      }
      else
      {
        VMPI_Sleep(ms: 0xAu);
      }
      p_m_CS = &p_m_WorkUnitWalker->m_CS;
      CCriticalSectionLock::CCriticalSectionLock(this: &v11, pCS: &p_m_WorkUnitWalker->m_CS);
      CCriticalSectionLock::Lock(this: &v11);
      v7 = SLODWORD(p_m_WorkUnitWalker->m_WorkUnitsRemaining.m_ElementCount) >> 31;
      m_ElementCount = p_m_WorkUnitWalker->m_WorkUnitsRemaining.m_ElementCount;
      CCriticalSectionLock::~CCriticalSectionLock(this: &v11);
      if ( v7 == 0 && m_ElementCount == 0 )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001ABC0
// Name: public: int CDistributor_SDKMaster::BuildWUsCompletedMessage(class CUtlVector<unsigned __int64,class CUtlMemory<unsigned __int64,int>> __near &,class MessageBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDistributor_SDKMaster::BuildWUsCompletedMessage(
        CDistributor_SDKMaster *this,
        CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *wusCompleted,
        MessageBuffer *mb)
{
  MessageBuffer *v3; // esi
  CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *v5; // edi
  int i; // esi
  unsigned __int64 *m_pMemory; // eax
  CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *v8; // ecx
  CDSInfo *m_pInfo; // eax
  _DWORD p[2]; // [esp+Ch] [ebp-8h] BYREF

  v3 = mb;
  PrepareDistributeWorkHeader(pBuf: mb, cSubpacketID: 0x34u);
  v5 = wusCompleted;
  CDSInfo::WriteWUIndex(this: this->m_pInfo, iWU: wusCompleted->m_Size, pBuf: v3);
  for ( i = 0; i < v5->m_Size; ++i )
  {
    m_pMemory = v5->m_Memory.m_pMemory;
    v8 = (CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *)v5->m_Memory.m_pMemory[i];
    p[0] = v8;
    p[1] = HIDWORD(m_pMemory[i]);
    m_pInfo = this->m_pInfo;
    if ( HIDWORD(m_pInfo->m_nWorkUnits) != 0 )
    {
      MessageBuffer::write(this: mb, (unsigned __int8 *)p, bytes: 8u);
    }
    else if ( LODWORD(m_pInfo->m_nWorkUnits) > 0xFFFF )
    {
      wusCompleted = v8;
      MessageBuffer::write(this: mb, p: (unsigned __int8 *)&wusCompleted, bytes: 4u);
    }
    else
    {
      wusCompleted = (CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *)(unsigned __int16)v8;
      MessageBuffer::write(this: mb, p: (unsigned __int8 *)&wusCompleted, bytes: 2u);
    }
  }
  return v5->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1001AC70
// Name: public: static void CDistributor_SDKMaster::Master_WorkerThread_Static(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDistributor_SDKMaster::Master_WorkerThread_Static(int iThread, CDistributor_SDKMaster *pUserData)
{
  CDistributor_SDKMaster::Master_WorkerThread(this: pUserData, iThread);
}

//------------------------------------------------------------------------------
// Address: 0x1001AC90
// Name: public: virtual void CDistributor_SDKMaster::DisconnectHandler(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::DisconnectHandler(CDistributor_SDKMaster *this, int workerID)
{
  int m_Size; // ecx
  int v4; // eax
  int *m_pMemory; // edx

  CCriticalSection::Lock(this: &this->m_WorkersReadyCS);
  m_Size = this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Memory.m_pMemory;
    while ( *m_pMemory != workerID )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_8;
    }
    if ( v4 != -1 )
      this->m_bForceShuffle = true;
  }
LABEL_8:
  CCriticalSection::Unlock(this: &this->m_WorkersReadyCS);
}

//------------------------------------------------------------------------------
// Address: 0x1001ADA0
// Name: public: virtual void CDistributor_SDKMaster::OnWorkerReady(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::OnWorkerReady(CDistributor_SDKMaster *this, int iSource)
{
  CCriticalSectionData<CDistributor_SDKMaster::CWorkersReady> *p_m_WorkersReadyCS; // esi
  int m_Size; // edi
  int v5; // eax
  int *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  int *v8; // ecx
  int v9; // eax
  int *v10; // edi
  int Name; // eax
  CCriticalSectionData<CDistributor_SDKMaster::CWorkersReady> *v12; // [esp+Ch] [ebp-4h]

  p_m_WorkersReadyCS = &this->m_WorkersReadyCS;
  v12 = &this->m_WorkersReadyCS;
  CCriticalSection::Lock(this: &this->m_WorkersReadyCS);
  m_Size = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_pMemory;
  while ( *m_pMemory != iSource )
  {
    ++v5;
    ++m_pMemory;
    if ( v5 >= m_Size )
      goto LABEL_7;
  }
  if ( v5 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<CTCPPacket *,int> *)&p_m_WorkersReadyCS->m_Data,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Size;
    v8 = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_pMemory;
    v9 = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Size - m_Size - 1;
    p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_pElements = v8;
    if ( v9 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v8[m_Size + 1], src: (unsigned __int8 *)&v8[m_Size], count: 4 * v9);
    v10 = &p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = iSource;
    CCriticalSection::Lock(this: &this->m_WUsCompletedCS);
    MessageBuffer::setLen(this: &this->m_WUSCompletedMessageBuffer, nlen: 0);
    CDistributor_SDKMaster::BuildWUsCompletedMessage(
      this,
      wusCompleted: &this->m_WUsCompletedCS.m_Data.m_Completed,
      mb: &this->m_WUSCompletedMessageBuffer);
    CCriticalSection::Unlock(this: &this->m_WUsCompletedCS);
    Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&this->m_WUSCompletedMessageBuffer);
    VMPI_SendData(pData: this->m_WUSCompletedMessageBuffer.data, nBytes: Name, iDest: iSource, fVMPISendFlags: 0);
    this->m_bForceShuffle = true;
  }
  CCriticalSection::Unlock(this: v12);
}

//------------------------------------------------------------------------------
// Address: 0x1001AE90
// Name: public: void CDistributor_SDKMaster::Shuffle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::Shuffle(CDistributor_SDKMaster *this)
{
  int m_Size; // esi
  unsigned __int16 *m_pMemory; // ebx
  int v4; // eax
  CCriticalSectionData<CDistributor_SDKMaster::CWorkersReady> *p_m_WorkersReadyCS; // edi
  bool v6; // cc
  int v7; // edi
  unsigned __int16 *v8; // edi
  CDistributor_SDKMaster *v9; // edi
  MessageBuffer *p_m_WUSCompletedMessageBuffer; // edi
  int m_bUsingMasterLocalThreads; // eax
  int Name; // eax
  int v13; // edi
  CCriticalSectionData<CDistributor_SDKMaster::CWUsCompleted> *p_m_WUsCompletedCS; // ecx
  CDistributor_SDKMaster *v15; // edi
  int j; // edi
  int v17; // eax
  int v18; // [esp-8h] [ebp-50h]
  int v19; // [esp-8h] [ebp-50h]
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > whosWorking; // [esp+Ch] [ebp-3Ch] BYREF
  MessageBuffer mb; // [esp+20h] [ebp-28h] BYREF
  unsigned int shuffleCRC; // [esp+30h] [ebp-18h] BYREF
  int nWorkers; // [esp+34h] [ebp-14h] BYREF
  int iWorker; // [esp+38h] [ebp-10h]
  int id; // [esp+3Ch] [ebp-Ch] BYREF
  int i; // [esp+40h] [ebp-8h]
  CDistributor_SDKMaster *v27; // [esp+44h] [ebp-4h]

  m_Size = 0;
  m_pMemory = nullptr;
  v27 = this;
  memset(&whosWorking, 0, sizeof(whosWorking));
  if ( this->m_bUsingMasterLocalThreads != 0 )
  {
    CUtlMemory<unsigned short,int>::Grow(this: &whosWorking.m_Memory, num: 1);
    m_pMemory = whosWorking.m_Memory.m_pMemory;
    m_Size = whosWorking.m_Size + 1;
    v4 = whosWorking.m_Size++;
    whosWorking.m_pElements = whosWorking.m_Memory.m_pMemory;
    if ( v4 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)whosWorking.m_Memory.m_pMemory + 2,
        src: (unsigned __int8 *)whosWorking.m_Memory.m_pMemory,
        count: 2 * v4);
    if ( m_pMemory != nullptr )
      *m_pMemory = 0;
  }
  p_m_WorkersReadyCS = &this->m_WorkersReadyCS;
  CCriticalSection::Lock(this: p_m_WorkersReadyCS);
  v6 = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Size <= 0;
  i = 0;
  if ( !v6 )
  {
    do
    {
      iWorker = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_pMemory[i];
      if ( VMPI_IsProcConnected(procID: iWorker) )
      {
        v7 = m_Size;
        if ( m_Size + 1 > whosWorking.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<unsigned short,int>::Grow(
            this: &whosWorking.m_Memory,
            num: m_Size - whosWorking.m_Memory.m_nAllocationCount + 1);
          m_Size = whosWorking.m_Size;
          m_pMemory = whosWorking.m_Memory.m_pMemory;
        }
        whosWorking.m_Size = ++m_Size;
        whosWorking.m_pElements = m_pMemory;
        if ( m_Size - v7 - 1 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[v7 + 1],
            src: (unsigned __int8 *)&m_pMemory[v7],
            count: 2 * (m_Size - v7 - 1));
        v8 = &m_pMemory[v7];
        if ( v8 != nullptr )
          *v8 = iWorker;
      }
      p_m_WorkersReadyCS = &v27->m_WorkersReadyCS;
      ++i;
    }
    while ( i < v27->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Size );
  }
  CCriticalSection::Unlock(this: p_m_WorkersReadyCS);
  v9 = v27;
  CCriticalSection::Lock(this: &v27->m_WUsCompletedCS);
  p_m_WUSCompletedMessageBuffer = &v9->m_WUSCompletedMessageBuffer;
  MessageBuffer::setLen(this: p_m_WUSCompletedMessageBuffer, nlen: 0);
  iWorker = (int)&v27->m_WUsCompletedCS.m_Data.m_Pending;
  if ( CDistributor_SDKMaster::BuildWUsCompletedMessage(
         this: v27,
         wusCompleted: &v27->m_WUsCompletedCS.m_Data.m_Pending,
         mb: p_m_WUSCompletedMessageBuffer) > 0 )
  {
    m_bUsingMasterLocalThreads = v27->m_bUsingMasterLocalThreads;
    i = m_bUsingMasterLocalThreads;
    if ( m_bUsingMasterLocalThreads < m_Size )
    {
      while ( 1 )
      {
        v18 = m_pMemory[m_bUsingMasterLocalThreads];
        Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)p_m_WUSCompletedMessageBuffer);
        VMPI_SendData(pData: p_m_WUSCompletedMessageBuffer->data, nBytes: Name, iDest: v18, fVMPISendFlags: 0);
        if ( ++i >= m_Size )
          break;
        m_bUsingMasterLocalThreads = i;
      }
    }
  }
  v13 = iWorker;
  CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(
    this: &v27->m_WUsCompletedCS.m_Data.m_Completed,
    elem: v27->m_WUsCompletedCS.m_Data.m_Completed.m_Size,
    num: v27->m_WUsCompletedCS.m_Data.m_Pending.m_Size,
    pToInsert: *(const unsigned __int64 **)iWorker);
  p_m_WUsCompletedCS = &v27->m_WUsCompletedCS;
  *(_DWORD *)(v13 + 12) = 0;
  CCriticalSection::Unlock(this: p_m_WUsCompletedCS);
  v15 = v27;
  CShuffledWorkUnitWalker::Shuffle(this: &v27->m_WorkUnitWalker, nWorkers: m_Size);
  MessageBuffer::MessageBuffer(this: &mb);
  PrepareDistributeWorkHeader(pBuf: &mb, cSubpacketID: 0x32u);
  nWorkers = (unsigned __int16)m_Size;
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&nWorkers, bytes: 2u);
  shuffleCRC = CShuffledWorkUnitWalker::GetShuffleCRC(this: &v15->m_WorkUnitWalker);
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&shuffleCRC, bytes: 4u);
  iWorker = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  id = 0;
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&id, bytes: 2u);
  for ( j = v15->m_bUsingMasterLocalThreads; j < m_Size; ++j )
  {
    id = (unsigned __int16)j;
    MessageBuffer::update(this: &mb, loc: iWorker, p: (unsigned __int8 *)&id, bytes: 2u);
    v19 = m_pMemory[j];
    v17 = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
    VMPI_SendData(pData: mb.data, nBytes: v17, iDest: v19, fVMPISendFlags: 0);
  }
  MessageBuffer::~MessageBuffer(this: &mb);
  if ( whosWorking.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1001B120
// Name: public: bool CDistributor_SDKMaster::Thread_HandleWorkUnitResults(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_SDKMaster::Thread_HandleWorkUnitResults(
        CDistributor_SDKMaster *this,
        unsigned __int64 iWorkUnit)
{
  unsigned int v3; // ebx
  CCriticalSectionLock v5; // [esp+Ch] [ebp-Ch] BYREF
  bool v6; // [esp+17h] [ebp-1h]

  CCriticalSectionLock::CCriticalSectionLock(this: &v5, pCS: &this->m_WorkUnitWalker.m_CS);
  CCriticalSectionLock::Lock(this: &v5);
  v3 = iWorkUnit;
  v6 = ((unsigned __int8)(1 << (iWorkUnit & 7))
      & this->m_WorkUnitWalker.m_CompletedWUBits.m_Memory.m_pMemory[iWorkUnit >> 3]) != 0;
  CCriticalSectionLock::~CCriticalSectionLock(this: &v5);
  if ( v6 )
    return 0;
  CShuffledWorkUnitWalker::Thread_NoteWorkUnitCompleted(
    this: &this->m_WorkUnitWalker,
    iWU: __PAIR64__(HIDWORD(iWorkUnit), v3));
  CCriticalSection::Lock(this: &this->m_WUsCompletedCS);
  CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertBefore(
    this: &this->m_WUsCompletedCS.m_Data.m_Pending,
    elem: this->m_WUsCompletedCS.m_Data.m_Pending.m_Size,
    src: &iWorkUnit);
  CCriticalSection::Unlock(this: &this->m_WUsCompletedCS);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001B1D0
// Name: class IWorkUnitDistributorWorker __near * CreateWUDistributor_SDKWorker(void)
// Source: json
//------------------------------------------------------------------------------
IWorkUnitDistributorWorker *__cdecl CreateWUDistributor_SDKWorker()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(nSize: 0x140u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = &IShuffleRequester::`vftable';
  *(_DWORD *)v0 = &CDistributor_SDKWorker::`vftable'{for `IWorkUnitDistributorWorker'};
  *((_DWORD *)v0 + 1) = &CDistributor_SDKWorker::`vftable'{for `IShuffleRequester'};
  CShuffledWorkUnitWalker::CShuffledWorkUnitWalker(this: (CShuffledWorkUnitWalker *)(v0 + 16));
  return (IWorkUnitDistributorWorker *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x1001B2D0
// Name: public: void CShuffledWorkUnitWalker::Init(unsigned __int64,class IShuffleRequester __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShuffledWorkUnitWalker::Init(
        CShuffledWorkUnitWalker *this,
        unsigned __int64 nWorkUnits,
        IShuffleRequester *pRequester)
{
  __int64 v4; // rcx
  int v5; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  signed int v8; // eax
  int v9; // eax
  unsigned __int8 *v10; // ecx
  signed int v11; // eax
  unsigned int v12; // edi
  unsigned __int64 i; // kr08_8
  int v14; // edx
  unsigned __int64 iWU; // [esp+Ch] [ebp-8h] BYREF

  HIDWORD(v4) = 0;
  this->m_iLastShuffleRequest = 0;
  this->m_iCurShuffle = 1;
  this->m_flLastShuffleTime = _Plat_FloatTime();
  v5 = (nWorkUnits + 7) >> 3;
  this->m_pShuffleRequester = pRequester;
  this->m_CompletedWUBits.m_Size = 0;
  if ( v5 != 0 )
  {
    m_nAllocationCount = this->m_CompletedWUBits.m_Memory.m_nAllocationCount;
    if ( v5 > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: &this->m_CompletedWUBits.m_Memory, num: v5 - m_nAllocationCount);
    this->m_CompletedWUBits.m_Size += v5;
    m_pMemory = this->m_CompletedWUBits.m_Memory.m_pMemory;
    v8 = this->m_CompletedWUBits.m_Size - v5;
    this->m_CompletedWUBits.m_pElements = this->m_CompletedWUBits.m_Memory.m_pMemory;
    if ( v8 > 0 && v5 > 0 )
      _V_memmove(dest: &m_pMemory[v5], src: m_pMemory, count: v8);
  }
  this->m_LocalCompletedWUBits.m_Size = 0;
  if ( v5 != 0 )
  {
    v9 = this->m_LocalCompletedWUBits.m_Memory.m_nAllocationCount;
    if ( v5 > v9 )
      CUtlMemory<bool,int>::Grow(this: &this->m_LocalCompletedWUBits.m_Memory, num: v5 - v9);
    this->m_LocalCompletedWUBits.m_Size += v5;
    v10 = this->m_LocalCompletedWUBits.m_Memory.m_pMemory;
    v11 = this->m_LocalCompletedWUBits.m_Size - v5;
    this->m_LocalCompletedWUBits.m_pElements = v10;
    if ( v11 > 0 && v5 > 0 )
      _V_memmove(dest: &v10[v5], src: v10, count: v11);
  }
  iWU = 0;
  if ( this->m_CompletedWUBits.m_Size != 0 )
  {
    v12 = HIDWORD(iWU);
    LODWORD(v4) = iWU;
    do
    {
      this->m_CompletedWUBits.m_Memory.m_pMemory[v4] = 0;
      this->m_LocalCompletedWUBits.m_Memory.m_pMemory[v4] = 0;
      v12 = (v4 + __PAIR64__(v12, 1)) >> 32;
      LODWORD(v4) = v4 + 1;
    }
    while ( __PAIR64__(v12, v4) < this->m_CompletedWUBits.m_Size );
  }
  iWU = 0;
  if ( nWorkUnits != 0 )
  {
    for ( i = iWU; i < nWorkUnits; iWU = i )
    {
      if ( CUtlLinkedList<unsigned __int64,unsigned __int64,0,unsigned __int64,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>>::AddToTail(
             this: &this->m_WorkUnitsRemaining,
             src: &iWU) != (_DWORD)i
        || v14 != HIDWORD(i) )
      {
        _Error(a1: "CShuffledWorkUnitWalker: assumption on CUtlLinkedList indexing failed.\n");
      }
      ++i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B450
// Name: public: virtual void CDistributor_SDKMaster::DistributeWork_Master(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::DistributeWork_Master(CDistributor_SDKMaster *this, CDSInfo *pInfo)
{
  const char *ParamString; // eax
  CCriticalSection *p_m_CS; // edi
  __int64 m_ElementCount_low; // kr00_8
  __int64 v6; // kr08_8
  double v7; // [esp+Ch] [ebp-10h]
  CCriticalSectionLock v8; // [esp+14h] [ebp-8h] BYREF

  this->m_pInfo = pInfo;
  *(_WORD *)&this->m_bForceShuffle = 0;
  this->m_flLastShuffleRequestServiceTime = _Plat_FloatTime();
  this->m_bUsingMasterLocalThreads = pInfo->m_WorkerInfo.m_pProcessFn != nullptr;
  if ( VMPI_IsParamUsed(eParam: mpi_NoMasterWorkerThreads) )
  {
    ParamString = VMPI_GetParamString(eParam: mpi_NoMasterWorkerThreads);
    _Msg(a1: "%s found. No worker threads will be created.\n", ParamString);
    this->m_bUsingMasterLocalThreads = 0;
  }
  CShuffledWorkUnitWalker::Init(
    this: &this->m_WorkUnitWalker,
    nWorkUnits: pInfo->m_nWorkUnits,
    pRequester: &this->IShuffleRequester);
  CDistributor_SDKMaster::Shuffle(this);
  if ( this->m_bUsingMasterLocalThreads != 0 )
    RunThreads_Start(
      fn: (void (__cdecl *)(int, void *))CDistributor_SDKMaster::Master_WorkerThread_Static,
      pUserData: this,
      ePriority: k_eRunThreadsPriority_Idle);
  _Plat_MSTime();
  p_m_CS = &this->m_WorkUnitWalker.m_CS;
  CCriticalSectionLock::CCriticalSectionLock(this: &v8, pCS: &this->m_WorkUnitWalker.m_CS);
  CCriticalSectionLock::Lock(this: &v8);
  m_ElementCount_low = SLODWORD(this->m_WorkUnitWalker.m_WorkUnitsRemaining.m_ElementCount);
  CCriticalSectionLock::~CCriticalSectionLock(this: &v8);
  if ( m_ElementCount_low != 0 )
  {
    while ( 1 )
    {
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xC8);
      CheckLocalMasterCompletedWorkUnits();
      VMPITracker_HandleDebugKeypresses();
      if ( g_pDistributeWorkCallbacks != nullptr
        && g_pDistributeWorkCallbacks->Update(this: g_pDistributeWorkCallbacks) != 0 )
      {
        goto LABEL_16;
      }
      if ( this->m_bForceShuffle )
        goto LABEL_14;
      if ( this->m_bShuffleRequested )
      {
        v7 = _Plat_FloatTime();
        if ( v7 - this->m_flLastShuffleRequestServiceTime > 2.0 )
          break;
      }
LABEL_15:
      CCriticalSectionLock::CCriticalSectionLock(this: &v8, pCS: p_m_CS);
      CCriticalSectionLock::Lock(this: &v8);
      v6 = SLODWORD(this->m_WorkUnitWalker.m_WorkUnitsRemaining.m_ElementCount);
      CCriticalSectionLock::~CCriticalSectionLock(this: &v8);
      if ( v6 == 0 )
        goto LABEL_16;
      p_m_CS = &this->m_WorkUnitWalker.m_CS;
    }
    this->m_flLastShuffleRequestServiceTime = v7;
    this->m_bShuffleRequested = false;
LABEL_14:
    CDistributor_SDKMaster::Shuffle(this);
    _Plat_MSTime();
    this->m_bForceShuffle = false;
    goto LABEL_15;
  }
LABEL_16:
  RunThreads_End();
}

//------------------------------------------------------------------------------
// Address: 0x1001B600
// Name: public: virtual bool CDistributor_SDKMaster::HandleWorkUnitResults(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_SDKMaster::HandleWorkUnitResults(CDistributor_SDKMaster *this, unsigned __int64 iWorkUnit)
{
  return CDistributor_SDKMaster::Thread_HandleWorkUnitResults(this, iWorkUnit);
}

//------------------------------------------------------------------------------
// Address: 0x1001B620
// Name: public: virtual void CDistributor_SDKWorker::Init(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKWorker::Init(CDistributor_SDKWorker *this, CDSInfo *pInfo)
{
  this->m_iMyWorkUnitWalkerID = -1;
  this->m_pInfo = pInfo;
  CShuffledWorkUnitWalker::Init(
    this: &this->m_WorkUnitWalker,
    nWorkUnits: pInfo->m_nWorkUnits,
    pRequester: &this->IShuffleRequester);
}

//------------------------------------------------------------------------------
// Address: 0x1001B660
// Name: public: virtual void CDistributor_SDKWorker::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKWorker::Release(CDistributor_SDKWorker *this)
{
  if ( this != nullptr )
  {
    CShuffledWorkUnitWalker::~CShuffledWorkUnitWalker(this: &this->m_WorkUnitWalker);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B680
// Name: class IWorkUnitDistributorMaster __near * CreateWUDistributor_SDKMaster(void)
// Source: json
//------------------------------------------------------------------------------
CDistributor_SDKMaster *__cdecl CreateWUDistributor_SDKMaster()
{
  CDistributor_SDKMaster *v0; // eax

  v0 = (CDistributor_SDKMaster *)operator new(nSize: 0x240u);
  if ( v0 != nullptr )
    return CDistributor_SDKMaster::CDistributor_SDKMaster(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001B6A0
// Name: public: virtual void CDistributor_SDKMaster::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::Release(CDistributor_SDKMaster *this)
{
  if ( this != nullptr )
  {
    CShuffledWorkUnitWalker::~CShuffledWorkUnitWalker(this: &this->m_WorkUnitWalker);
    MessageBuffer::~MessageBuffer(this: &this->m_WUSCompletedMessageBuffer);
    CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_WUsCompletedCS.m_Data.m_Pending);
    CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_WUsCompletedCS.m_Data);
    CCriticalSection::~CCriticalSection(this: &this->m_WUsCompletedCS);
    CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_WorkersReadyCS.m_Data);
    CCriticalSection::~CCriticalSection(this: &this->m_WorkersReadyCS);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B700
// Name: _deflateInit_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl deflateInit_(int a1, int a2, int a3, int a4)
{
  return deflateInit2_(a1, a2, a3: 8, a4: 15, a5: 8, a6: 0, a7: a3, a8: a4);
}

//------------------------------------------------------------------------------
// Address: 0x1001B730
// Name: _deflateInit2_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl deflateInit2_(_DWORD *a1, int a2, int a3, int a4, int a5, unsigned int a6, _BYTE *a7, int a8)
{
  int v8; // ebp
  int v10; // eax
  unsigned int v11; // ecx
  int v12; // ebx
  _DWORD *v13; // eax
  _DWORD *v14; // esi
  int v15; // eax
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  unsigned int v21; // ecx

  v8 = 0;
  if ( a7 == nullptr || *a7 != *off_10045EB8 || a8 != 56 )
    return -6;
  if ( a1 == nullptr )
    return -2;
  v10 = a1[8];
  a1[6] = 0;
  if ( v10 == 0 )
  {
    a1[8] = zcalloc;
    a1[10] = 0;
  }
  if ( a1[9] == 0 )
    a1[9] = zcfree;
  v11 = a2;
  if ( a2 == -1 )
  {
    a2 = 6;
    v11 = 6;
  }
  v12 = a4;
  if ( a4 < 0 )
  {
    v8 = 1;
    v12 = -a4;
  }
  if ( a5 < 1 || a5 > 9 || a3 != 8 || v12 < 8 || v12 > 15 || v11 > 9 || a6 > 2 )
    return -2;
  v13 = (_DWORD *)((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: 1, a3: 5816);
  v14 = v13;
  if ( v13 == nullptr )
    return -4;
  a1[7] = v13;
  v13[6] = v8;
  v13[10] = v12;
  *v13 = a1;
  v13[18] = a5 + 7;
  v13[9] = 1 << v12;
  v13[11] = (1 << v12) - 1;
  v15 = 1 << (a5 + 7);
  v14[17] = v15;
  v14[19] = v15 - 1;
  v14[20] = (a5 + 9) / 3u;
  v16 = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: 1 << v12, a3: 2);
  v17 = v14[9];
  v14[12] = v16;
  v18 = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: v17, a3: 2);
  v19 = v14[17];
  v14[14] = v18;
  v14[15] = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: v19, a3: 2);
  v14[1445] = 1 << (a5 + 6);
  v20 = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: 1 << (a5 + 6), a3: 4);
  v21 = v14[1445];
  v14[2] = v20;
  v14[3] = 4 * v21;
  if ( v14[12] != 0 && v14[14] != 0 && v14[15] != 0 && v20 != 0 )
  {
    *((_BYTE *)v14 + 29) = 8;
    v14[1447] = v20 + 2 * (v21 >> 1);
    v14[1444] = v20 + 2 * v21 + v21;
    v14[32] = a6;
    v14[31] = a2;
    return deflateReset(a1);
  }
  else
  {
    a1[6] = off_10045F4C[0];
    deflateEnd(a1);
    return -4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001B930
// Name: _deflateReset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl deflateReset(_DWORD *a1)
{
  _DWORD *v1; // esi
  int v2; // edx

  if ( a1 == nullptr )
    return -2;
  v1 = (_DWORD *)a1[7];
  if ( v1 == nullptr || a1[8] == 0 || a1[9] == 0 )
    return -2;
  a1[5] = 0;
  a1[2] = 0;
  a1[6] = 0;
  a1[11] = 2;
  v2 = v1[2];
  v1[5] = 0;
  v1[4] = v2;
  if ( (int)v1[6] < 0 )
    v1[6] = 0;
  v1[1] = v1[6] != 0 ? 113 : 42;
  a1[12] = 1;
  v1[8] = 0;
  _tr_init(a1: v1);
  sub_1001BDC0(a1: v1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001B9B0
// Name: _deflate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl deflate(int a1, int a2)
{
  int v3; // esi
  int v4; // eax
  int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // [esp+14h] [ebp+4h]

  if ( a1 == 0 )
    return -2;
  v3 = *(_DWORD *)(a1 + 28);
  if ( v3 == 0 || (unsigned int)a2 > 4 )
    return -2;
  if ( *(_DWORD *)(a1 + 12) == 0
    || *(_DWORD *)a1 == 0 && *(_DWORD *)(a1 + 4) != 0
    || (v4 = *(_DWORD *)(v3 + 4)) == 666 && a2 != 4 )
  {
    *(char **)(a1 + 24) = off_10045F44[0];
    return -2;
  }
  if ( *(_DWORD *)(a1 + 16) == 0 )
  {
    *(char **)(a1 + 24) = off_10045F50[0];
    return -5;
  }
  v6 = *(_DWORD *)(v3 + 32);
  *(_DWORD *)v3 = a1;
  v13 = v6;
  *(_DWORD *)(v3 + 32) = a2;
  if ( v4 == 42 )
  {
    v7 = (*(_DWORD *)(v3 + 124) - 1) >> 1;
    if ( v7 > 3 )
      v7 = 3;
    v8 = (v7 << 6) | ((*(_DWORD *)(v3 + 40) << 12) - 30720);
    if ( *(_DWORD *)(v3 + 100) != 0 )
      v8 |= 0x20u;
    *(_DWORD *)(v3 + 4) = 113;
    sub_1001BC60(a1: v3, a2: v8 - v8 % 0x1F + 31);
    if ( *(_DWORD *)(v3 + 100) != 0 )
    {
      sub_1001BC60(a1: v3, a2: *(unsigned __int16 *)(a1 + 50));
      sub_1001BC60(a1: v3, a2: (unsigned __int16)*(_DWORD *)(a1 + 48));
    }
    *(_DWORD *)(a1 + 48) = 1;
  }
  if ( *(_DWORD *)(v3 + 20) != 0 )
  {
    sub_1001BC90(a1);
    if ( *(_DWORD *)(a1 + 16) == 0 )
    {
      *(_DWORD *)(v3 + 32) = -1;
      return 0;
    }
  }
  else if ( *(_DWORD *)(a1 + 4) == 0 && a2 <= v13 && a2 != 4 )
  {
    *(char **)(a1 + 24) = off_10045F50[0];
    return -5;
  }
  v9 = *(_DWORD *)(v3 + 4);
  v10 = *(_DWORD *)(a1 + 4);
  if ( v9 == 666 )
  {
    if ( v10 != 0 )
    {
      *(char **)(a1 + 24) = off_10045F50[0];
      return -5;
    }
  }
  else if ( v10 != 0 )
  {
    goto LABEL_33;
  }
  if ( *(_DWORD *)(v3 + 108) == 0 && (a2 == 0 || v9 == 666) )
  {
LABEL_45:
    if ( a2 != 4 )
      return 0;
    if ( *(_DWORD *)(v3 + 24) != 0 )
      return 1;
    sub_1001BC60(a1: v3, a2: *(unsigned __int16 *)(a1 + 50));
    sub_1001BC60(a1: v3, a2: (unsigned __int16)*(_DWORD *)(a1 + 48));
    sub_1001BC90(a1);
    v12 = *(_DWORD *)(v3 + 20);
    *(_DWORD *)(v3 + 24) = -1;
    return v12 == 0;
  }
LABEL_33:
  v11 = funcs_1001BB44[3 * *(_DWORD *)(v3 + 124)](a1: v3, a2);
  if ( v11 == 2 || v11 == 3 )
    *(_DWORD *)(v3 + 4) = 666;
  if ( v11 != 0 && v11 != 2 )
  {
    if ( v11 == 1 )
    {
      if ( a2 == 1 )
      {
        _tr_align(a1: v3);
      }
      else
      {
        _tr_stored_block(a1: v3, a2: 0, a3: 0, a4: 0);
        if ( a2 == 3 )
        {
          *(_WORD *)(*(_DWORD *)(v3 + 60) + 2 * *(_DWORD *)(v3 + 68) - 2) = 0;
          memset(*(void **)(v3 + 60), 0, 2 * *(_DWORD *)(v3 + 68) - 2);
        }
      }
      sub_1001BC90(a1);
      if ( *(_DWORD *)(a1 + 16) == 0 )
      {
        *(_DWORD *)(v3 + 32) = -1;
        return 0;
      }
    }
    goto LABEL_45;
  }
  if ( *(_DWORD *)(a1 + 16) == 0 )
    *(_DWORD *)(v3 + 32) = -1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001BC60
// Name: sub_1001BC60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1001BC60(int a1, __int16 a2)
{
  int v3; // esi
  int v4; // edx

  *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = HIBYTE(a2);
  v3 = *(_DWORD *)(a1 + 8);
  v4 = *(_DWORD *)(a1 + 20) + 1;
  *(_DWORD *)(a1 + 20) = v4;
  *(_BYTE *)(v4 + v3) = a2;
  ++*(_DWORD *)(a1 + 20);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x1001BC90
// Name: sub_1001BC90
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl sub_1001BC90(int a1)
{
  _DWORD *result; // eax
  int v2; // esi
  unsigned int v3; // edx
  int v4; // ecx
  int v5; // ecx
  unsigned int v6; // edi

  result = (_DWORD *)a1;
  v2 = *(_DWORD *)(a1 + 28);
  v3 = *(_DWORD *)(v2 + 20);
  if ( v3 > *(_DWORD *)(a1 + 16) )
    v3 = *(_DWORD *)(a1 + 16);
  if ( v3 != 0 )
  {
    qmemcpy(*(void **)(a1 + 12), *(const void **)(v2 + 16), v3);
    v4 = *(_DWORD *)(a1 + 28);
    *(_DWORD *)(a1 + 12) += v3;
    *(_DWORD *)(v4 + 16) += v3;
    v5 = *(_DWORD *)(a1 + 28);
    v6 = *(_DWORD *)(a1 + 16) - v3;
    *(_DWORD *)(a1 + 20) += v3;
    *(_DWORD *)(a1 + 16) = v6;
    *(_DWORD *)(v5 + 20) -= v3;
    result = *(_DWORD **)(a1 + 28);
    if ( result[5] == 0 )
      result[4] = result[2];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001BD10
// Name: _deflateEnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl deflateEnd(int a1)
{
  int v1; // eax
  int v2; // edi
  int v3; // eax
  int v4; // ecx
  int v5; // edx

  if ( a1 == 0 )
    return -2;
  v1 = *(_DWORD *)(a1 + 28);
  if ( v1 == 0 )
    return -2;
  v2 = *(_DWORD *)(v1 + 4);
  if ( v2 != 42 && v2 != 113 && v2 != 666 )
    return -2;
  v3 = *(_DWORD *)(v1 + 8);
  if ( v3 != 0 )
    (*(void (__cdecl **)(_DWORD, int))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: v3);
  v4 = *(_DWORD *)(a1 + 28);
  if ( *(_DWORD *)(v4 + 60) != 0 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: *(_DWORD *)(v4 + 60));
  if ( *(_DWORD *)(*(_DWORD *)(a1 + 28) + 56) != 0 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(
      a1: *(_DWORD *)(a1 + 40),
      a2: *(_DWORD *)(*(_DWORD *)(a1 + 28) + 56));
  v5 = *(_DWORD *)(a1 + 28);
  if ( *(_DWORD *)(v5 + 48) != 0 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: *(_DWORD *)(v5 + 48));
  (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: *(_DWORD *)(a1 + 28));
  *(_DWORD *)(a1 + 28) = 0;
  return v2 != 113 ? 0 : 0xFD;
}

//------------------------------------------------------------------------------
// Address: 0x1001BDC0
// Name: sub_1001BDC0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1001BDC0(int a1)
{
  int v1; // ecx
  int v2; // eax
  int v3; // ecx

  v1 = *(_DWORD *)(a1 + 68);
  *(_DWORD *)(a1 + 52) = 2 * *(_DWORD *)(a1 + 36);
  *(_WORD *)(*(_DWORD *)(a1 + 60) + 2 * v1 - 2) = 0;
  memset(*(void **)(a1 + 60), 0, 2 * *(_DWORD *)(a1 + 68) - 2);
  v2 = 6 * *(_DWORD *)(a1 + 124);
  *(_DWORD *)(a1 + 120) = (unsigned __int16)word_1003E97A[v2];
  *(_DWORD *)(a1 + 132) = (unsigned __int16)word_1003E978[v2];
  *(_DWORD *)(a1 + 136) = (unsigned __int16)word_1003E97C[v2];
  v3 = (unsigned __int16)word_1003E97E[v2];
  *(_DWORD *)(a1 + 100) = 0;
  *(_DWORD *)(a1 + 84) = 0;
  *(_DWORD *)(a1 + 108) = 0;
  *(_DWORD *)(a1 + 96) = 0;
  *(_DWORD *)(a1 + 64) = 0;
  *(_DWORD *)(a1 + 116) = v3;
  *(_DWORD *)(a1 + 112) = 2;
  *(_DWORD *)(a1 + 88) = 2;
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x1001BE60
// Name: sub_1001BE60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1001BE60(int *a1, int a2)
{
  int v2; // edi
  unsigned int v3; // eax
  int v4; // ecx
  bool v5; // zf
  int v6; // ecx
  unsigned int v7; // edx
  unsigned int v8; // eax
  int v9; // edx
  int v10; // ecx
  unsigned int v11; // edx
  int v12; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // [esp-14h] [ebp-1Ch]
  int v17; // [esp-14h] [ebp-1Ch]
  int v18; // [esp-14h] [ebp-1Ch]

  v2 = 0xFFFF;
  if ( (unsigned int)(a1[3] - 5) < 0xFFFF )
    v2 = a1[3] - 5;
  while ( 1 )
  {
    v3 = a1[27];
    if ( v3 <= 1 )
    {
      sub_1001BFB0(a1);
      v3 = a1[27];
      if ( v3 == 0 )
        break;
    }
    v4 = a1[25];
    a1[27] = 0;
    v5 = v3 + v4 == 0;
    a1[25] = v3 + v4;
    v6 = a1[21];
    v7 = a1[25];
    v8 = v6 + v2;
    if ( !v5 && v7 < v8
      || ((a1[25] = v8, a1[27] = v7 - v8, v6 < 0) ? (v9 = 0) : (v9 = v6 + a1[12]),
          _tr_flush_block(a1, a2: v9, a3: v2, a4: 0),
          v16 = *a1,
          a1[21] = a1[25],
          sub_1001BC90(a1: v16),
          *(_DWORD *)(*a1 + 16) != 0) )
    {
      v10 = a1[21];
      v11 = a1[25] - v10;
      if ( v11 < a1[9] - 262 )
        continue;
      v12 = v10 < 0 ? 0 : v10 + a1[12];
      _tr_flush_block(a1, a2: v12, a3: v11, a4: 0);
      v17 = *a1;
      a1[21] = a1[25];
      sub_1001BC90(a1: v17);
      if ( *(_DWORD *)(*a1 + 16) != 0 )
        continue;
    }
    return 0;
  }
  if ( a2 == 0 )
    return 0;
  v14 = a1[21];
  if ( v14 < 0 )
    v15 = 0;
  else
    v15 = v14 + a1[12];
  _tr_flush_block(a1, a2: v15, a3: a1[25] - v14, a4: a2 == 4);
  v18 = *a1;
  a1[21] = a1[25];
  sub_1001BC90(a1: v18);
  if ( *(_DWORD *)(*a1 + 16) != 0 )
    return 2 * (a2 == 4) + 1;
  else
    return a2 != 4 ? 0 : 2;
}

//------------------------------------------------------------------------------
// Address: 0x1001BFB0
// Name: sub_1001BFB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1001BFB0(int a1)
{
  unsigned int v1; // ebp
  unsigned int v2; // eax
  int v3; // ecx
  int v4; // edx
  int v5; // eax
  unsigned int v6; // ecx
  int v7; // esi
  int v8; // ecx
  _WORD *v9; // ecx
  __int16 v10; // ax
  unsigned int v11; // esi
  _WORD *v12; // ecx
  __int16 v13; // ax
  int result; // eax
  unsigned int v15; // esi
  int v16; // ecx
  unsigned __int8 *v17; // edi
  int v18; // eax

  v1 = *(_DWORD *)(a1 + 36);
  do
  {
    v2 = *(_DWORD *)(a1 + 100);
    v3 = *(_DWORD *)(a1 + 108);
    v4 = *(_DWORD *)(a1 + 52) - v2 - v3;
    if ( v4 != 0 )
    {
      if ( v4 == -1 )
      {
        v4 = -2;
        goto LABEL_20;
      }
    }
    else if ( v2 == 0 && v3 == 0 )
    {
      v4 = v1;
      goto LABEL_20;
    }
    if ( v2 >= *(_DWORD *)(a1 + 36) + v1 - 262 )
    {
      qmemcpy(*(void **)(a1 + 48), (const void *)(*(_DWORD *)(a1 + 48) + v1), v1);
      v5 = *(_DWORD *)(a1 + 84);
      v6 = *(_DWORD *)(a1 + 100) - v1;
      *(_DWORD *)(a1 + 104) -= v1;
      v7 = *(_DWORD *)(a1 + 68);
      *(_DWORD *)(a1 + 100) = v6;
      v8 = *(_DWORD *)(a1 + 60);
      *(_DWORD *)(a1 + 84) = v5 - v1;
      v9 = (_WORD *)(v8 + 2 * v7);
      do
      {
        if ( (unsigned __int16)*--v9 < v1 )
          v10 = 0;
        else
          v10 = *v9 - v1;
        --v7;
        *v9 = v10;
      }
      while ( v7 != 0 );
      v11 = v1;
      v12 = (_WORD *)(*(_DWORD *)(a1 + 56) + 2 * v1);
      do
      {
        if ( (unsigned __int16)*--v12 < v1 )
          v13 = 0;
        else
          v13 = *v12 - v1;
        --v11;
        *v12 = v13;
      }
      while ( v11 != 0 );
      v4 += v1;
    }
LABEL_20:
    result = *(_DWORD *)a1;
    if ( *(_DWORD *)(*(_DWORD *)a1 + 4) == 0 )
      break;
    result = sub_1001C0E0(a1: result, a2: *(_DWORD *)(a1 + 48) + *(_DWORD *)(a1 + 100) + *(_DWORD *)(a1 + 108), a3: v4);
    v15 = result + *(_DWORD *)(a1 + 108);
    *(_DWORD *)(a1 + 108) = v15;
    if ( v15 >= 3 )
    {
      v16 = *(_DWORD *)(a1 + 80);
      v17 = (unsigned __int8 *)(*(_DWORD *)(a1 + 100) + *(_DWORD *)(a1 + 48));
      v18 = *v17;
      *(_DWORD *)(a1 + 64) = v18;
      result = *(_DWORD *)(a1 + 76) & (v17[1] ^ (v18 << v16));
      *(_DWORD *)(a1 + 64) = result;
    }
    if ( v15 >= 0x106 )
      break;
    result = *(_DWORD *)(*(_DWORD *)a1 + 4);
  }
  while ( result != 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001C0E0
// Name: sub_1001C0E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_1001C0E0(_DWORD *a1, void *a2, unsigned int a3)
{
  unsigned int v3; // ebx
  int v5; // eax

  v3 = a1[1];
  if ( v3 > a3 )
    v3 = a3;
  if ( v3 == 0 )
    return 0;
  a1[1] -= v3;
  if ( *(_DWORD *)(a1[7] + 24) == 0 )
    a1[12] = adler32(a1: a1[12], a2: *a1, a3: v3);
  qmemcpy(a2, (const void *)*a1, v3);
  v5 = a1[2];
  *a1 += v3;
  a1[2] = v3 + v5;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1001C160
// Name: sub_1001C160
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1001C160(int a1, int a2)
{
  int v2; // edi
  unsigned int v3; // eax
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  char v7; // cl
  __int16 v8; // ax
  unsigned __int16 v9; // ax
  int v10; // edx
  int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // edx
  BOOL v14; // ebp
  unsigned int v15; // ecx
  int v16; // eax
  int v17; // edi
  int v18; // edx
  int v19; // ecx
  int v20; // eax
  int v21; // eax
  unsigned int v22; // ecx
  unsigned __int8 *v23; // edx
  int v24; // ecx
  int v25; // eax
  unsigned __int8 v26; // al
  int v27; // ecx
  int v28; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // [esp-14h] [ebp-2Ch]
  int v33; // [esp-14h] [ebp-2Ch]

  v2 = 0;
  while ( 1 )
  {
    v3 = *(_DWORD *)(a1 + 108);
    if ( v3 < 0x106 )
    {
      sub_1001BFB0(a1);
      v3 = *(_DWORD *)(a1 + 108);
      if ( v3 < 0x106 && a2 == 0 )
        return 0;
      if ( v3 == 0 )
        break;
    }
    if ( v3 >= 3 )
    {
      v4 = *(_DWORD *)(a1 + 100);
      v5 = *(_DWORD *)(a1 + 60);
      v6 = *(_DWORD *)(a1 + 76)
         & (*(unsigned __int8 *)(*(_DWORD *)(a1 + 48) + v4 + 2)
          ^ (*(_DWORD *)(a1 + 64) << *(_DWORD *)(a1 + 80)));
      HIWORD(v2) = 0;
      *(_DWORD *)(a1 + 64) = v6;
      LOWORD(v2) = *(_WORD *)(v5 + 2 * v6);
      *(_WORD *)(*(_DWORD *)(a1 + 56) + 2 * (v4 & *(_DWORD *)(a1 + 44))) = v2;
      *(_WORD *)(*(_DWORD *)(a1 + 60) + 2 * *(_DWORD *)(a1 + 64)) = *(_WORD *)(a1 + 100);
    }
    if ( v2 != 0
      && *(_DWORD *)(a1 + 100) - v2 <= (unsigned int)(*(_DWORD *)(a1 + 36) - 262)
      && *(_DWORD *)(a1 + 128) != 2 )
    {
      *(_DWORD *)(a1 + 88) = sub_1001C4A0(a1, a2: v2);
    }
    if ( *(_DWORD *)(a1 + 88) < 3u )
    {
      v26 = *(_BYTE *)(*(_DWORD *)(a1 + 100) + *(_DWORD *)(a1 + 48));
      *(_WORD *)(*(_DWORD *)(a1 + 5788) + 2 * *(_DWORD *)(a1 + 5784)) = 0;
      *(_BYTE *)(*(_DWORD *)(a1 + 5776) + (*(_DWORD *)(a1 + 5784))++) = v26;
      ++*(_WORD *)(a1 + 4 * v26 + 140);
      v14 = *(_DWORD *)(a1 + 5784) == *(_DWORD *)(a1 + 5780) - 1;
      --*(_DWORD *)(a1 + 108);
    }
    else
    {
      v7 = *(_DWORD *)(a1 + 88);
      v8 = *(_WORD *)(a1 + 100) - *(_WORD *)(a1 + 104);
      *(_WORD *)(*(_DWORD *)(a1 + 5788) + 2 * *(_DWORD *)(a1 + 5784)) = v8;
      v9 = v8 - 1;
      *(_BYTE *)(*(_DWORD *)(a1 + 5776) + (*(_DWORD *)(a1 + 5784))++) = v7 - 3;
      v10 = (unsigned __int8)_length_code[(unsigned __int8)(v7 - 3)];
      ++*(_WORD *)(a1 + 4 * v10 + 1168);
      if ( v9 >= 0x100u )
        v11 = (unsigned __int8)byte_1003F140[v9 >> 7];
      else
        v11 = (unsigned __int8)_dist_code[v9];
      ++*(_WORD *)(a1 + 4 * v11 + 2432);
      v12 = *(_DWORD *)(a1 + 88);
      v13 = *(_DWORD *)(a1 + 120);
      v14 = *(_DWORD *)(a1 + 5784) == *(_DWORD *)(a1 + 5780) - 1;
      v15 = *(_DWORD *)(a1 + 108) - v12;
      *(_DWORD *)(a1 + 108) = v15;
      if ( v12 > v13 || v15 < 3 )
      {
        v22 = v12 + *(_DWORD *)(a1 + 100);
        v23 = (unsigned __int8 *)(v22 + *(_DWORD *)(a1 + 48));
        *(_DWORD *)(a1 + 100) = v22;
        v24 = *(_DWORD *)(a1 + 80);
        *(_DWORD *)(a1 + 88) = 0;
        v25 = *v23;
        *(_DWORD *)(a1 + 64) = v25;
        *(_DWORD *)(a1 + 64) = *(_DWORD *)(a1 + 76) & (v23[1] ^ (v25 << v24));
        goto LABEL_24;
      }
      *(_DWORD *)(a1 + 88) = v12 - 1;
      do
      {
        v16 = *(_DWORD *)(a1 + 48);
        v17 = *(_DWORD *)(a1 + 64);
        v18 = *(_DWORD *)(a1 + 100) + 1;
        *(_DWORD *)(a1 + 100) = v18;
        v19 = *(_DWORD *)(a1 + 60);
        v20 = *(_DWORD *)(a1 + 76) & ((v17 << *(_DWORD *)(a1 + 80)) ^ *(unsigned __int8 *)(v18 + v16 + 2));
        HIWORD(v2) = 0;
        *(_DWORD *)(a1 + 64) = v20;
        LOWORD(v2) = *(_WORD *)(v19 + 2 * v20);
        *(_WORD *)(*(_DWORD *)(a1 + 56) + 2 * (*(_DWORD *)(a1 + 44) & v18)) = v2;
        *(_WORD *)(*(_DWORD *)(a1 + 60) + 2 * *(_DWORD *)(a1 + 64)) = *(_WORD *)(a1 + 100);
        v21 = *(_DWORD *)(a1 + 88) - 1;
        *(_DWORD *)(a1 + 88) = v21;
      }
      while ( v21 != 0 );
    }
    ++*(_DWORD *)(a1 + 100);
LABEL_24:
    if ( v14 )
    {
      v27 = *(_DWORD *)(a1 + 84);
      v28 = v27 < 0 ? 0 : v27 + *(_DWORD *)(a1 + 48);
      _tr_flush_block(a1, a2: v28, a3: *(_DWORD *)(a1 + 100) - v27, a4: 0);
      v32 = *(_DWORD *)a1;
      *(_DWORD *)(a1 + 84) = *(_DWORD *)(a1 + 100);
      sub_1001BC90(a1: v32);
      if ( *(_DWORD *)(*(_DWORD *)a1 + 16) == 0 )
        return 0;
    }
  }
  v30 = *(_DWORD *)(a1 + 84);
  if ( v30 < 0 )
    v31 = 0;
  else
    v31 = v30 + *(_DWORD *)(a1 + 48);
  _tr_flush_block(a1, a2: v31, a3: *(_DWORD *)(a1 + 100) - v30, a4: a2 == 4);
  v33 = *(_DWORD *)a1;
  *(_DWORD *)(a1 + 84) = *(_DWORD *)(a1 + 100);
  sub_1001BC90(a1: v33);
  if ( *(_DWORD *)(*(_DWORD *)a1 + 16) != 0 )
    return 2 * (a2 == 4) + 1;
  else
    return a2 != 4 ? 0 : 2;
}

//------------------------------------------------------------------------------
// Address: 0x1001C4A0
// Name: sub_1001C4A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_1001C4A0(_DWORD *a1, int a2)
{
  int v3; // esi
  unsigned int v4; // edx
  unsigned int v5; // ebp
  unsigned int v6; // eax
  _BYTE *v7; // ecx
  _BYTE *v8; // ebx
  _BYTE *v10; // edx
  char v11; // al
  _BYTE *v12; // edx
  _BYTE *v13; // ecx
  _BYTE *v14; // edx
  char v15; // al
  _BYTE *v16; // edx
  char v17; // al
  _BYTE *v18; // edx
  char v19; // al
  _BYTE *v20; // edx
  char v21; // al
  _BYTE *v22; // edx
  char v23; // al
  _BYTE *v24; // edx
  char v25; // al
  _BYTE *v26; // edx
  char v27; // al
  _BYTE *v28; // edx
  char v29; // al
  _BYTE *v30; // edx
  int v31; // edx
  unsigned int result; // eax
  char v33; // [esp+13h] [ebp-11h]
  unsigned int v34; // [esp+14h] [ebp-10h]
  int v35; // [esp+18h] [ebp-Ch]
  unsigned int v36; // [esp+1Ch] [ebp-8h]
  unsigned int v37; // [esp+20h] [ebp-4h]
  char v38; // [esp+28h] [ebp+4h]

  v3 = a1[9];
  v4 = a1[25];
  v5 = a1[28];
  v34 = a1[29];
  v6 = a1[34];
  v7 = (_BYTE *)(v4 + a1[12]);
  v35 = v6;
  if ( v4 <= v3 - 262 )
    v36 = 0;
  else
    v36 = v4 - v3 + 262;
  v8 = v7 + 258;
  v38 = v7[v5 - 1];
  v33 = v7[v5];
  if ( v5 >= a1[33] )
    v34 >>= 2;
  v37 = a1[27];
  if ( v6 > v37 )
    v35 = a1[27];
  do
  {
    v10 = (_BYTE *)(a2 + a1[12]);
    if ( v10[v5] == v33 && v10[v5 - 1] == v38 && *v10 == *v7 )
    {
      v11 = v10[1];
      v12 = v10 + 1;
      if ( v11 == v7[1] )
      {
        v13 = v7 + 2;
        v14 = v12 + 1;
        do
        {
          v15 = *++v13;
          v16 = v14 + 1;
          if ( v15 != *v16 )
            break;
          v17 = *++v13;
          v18 = v16 + 1;
          if ( v17 != *v18 )
            break;
          v19 = *++v13;
          v20 = v18 + 1;
          if ( v19 != *v20 )
            break;
          v21 = *++v13;
          v22 = v20 + 1;
          if ( v21 != *v22 )
            break;
          v23 = *++v13;
          v24 = v22 + 1;
          if ( v23 != *v24 )
            break;
          v25 = *++v13;
          v26 = v24 + 1;
          if ( v25 != *v26 )
            break;
          v27 = *++v13;
          v28 = v26 + 1;
          if ( v27 != *v28 )
            break;
          v29 = *++v13;
          v14 = v28 + 1;
          if ( v29 != *v14 )
            break;
        }
        while ( v13 < v8 );
        v30 = v13;
        v7 = v8 - 258;
        v31 = v30 - v8 + 258;
        if ( v31 > (int)v5 )
        {
          a1[26] = a2;
          v5 = v31;
          if ( v31 >= v35 )
            break;
          v38 = v7[v31 - 1];
          v33 = v7[v31];
        }
      }
    }
    a2 = *(unsigned __int16 *)(a1[14] + 2 * (a2 & a1[11]));
    if ( (unsigned __int16)a2 <= v36 )
      break;
    --v34;
  }
  while ( v34 != 0 );
  result = v37;
  if ( v5 <= v37 )
    return v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001C610
// Name: sub_1001C610
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1001C610(_DWORD *a1, int a2)
{
  int v3; // edi
  unsigned int v4; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  unsigned int v9; // edx
  int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ebp
  __int16 v14; // ax
  unsigned __int16 v15; // ax
  int v16; // eax
  int v17; // eax
  BOOL v18; // ebx
  unsigned int v19; // edx
  int v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // ecx
  int v24; // edx
  int v25; // eax
  int v26; // eax
  unsigned __int8 v28; // al
  int v29; // ecx
  int v30; // eax
  int v31; // ecx
  int v32; // edx
  int v33; // ecx
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  int v37; // [esp-14h] [ebp-2Ch]
  int v38; // [esp-14h] [ebp-2Ch]
  int v39; // [esp-14h] [ebp-2Ch]
  unsigned __int8 v40; // [esp+1Ch] [ebp+4h]
  unsigned __int8 v41; // [esp+20h] [ebp+8h]

  v3 = 0;
  while ( 1 )
  {
    v4 = a1[27];
    if ( v4 < 0x106 )
    {
      sub_1001BFB0((int)a1);
      v4 = a1[27];
      if ( v4 < 0x106 && a2 == 0 )
        return 0;
      if ( v4 == 0 )
        break;
    }
    if ( v4 >= 3 )
    {
      v6 = a1[25];
      v7 = a1[15];
      v8 = a1[19] & (*(unsigned __int8 *)(a1[12] + v6 + 2) ^ (a1[16] << a1[20]));
      HIWORD(v3) = 0;
      a1[16] = v8;
      LOWORD(v3) = *(_WORD *)(v7 + 2 * v8);
      *(_WORD *)(a1[14] + 2 * (v6 & a1[11])) = v3;
      *(_WORD *)(a1[15] + 2 * a1[16]) = *((_WORD *)a1 + 50);
    }
    v9 = a1[22];
    v10 = a1[26];
    a1[28] = v9;
    a1[23] = v10;
    a1[22] = 2;
    if ( v3 != 0 && v9 < a1[30] && a1[25] - v3 <= (unsigned int)(a1[9] - 262) )
    {
      if ( a1[32] != 2 )
        a1[22] = sub_1001C4A0(a1, a2: v3);
      v11 = a1[22];
      if ( v11 <= 5 && (a1[32] == 1 || v11 == 3 && (unsigned int)(a1[25] - a1[26]) > 0x1000) )
        a1[22] = 2;
    }
    v12 = a1[28];
    if ( v12 < 3 || a1[22] > v12 )
    {
      if ( a1[24] != 0 )
      {
        v28 = *(_BYTE *)(a1[25] + a1[12] - 1);
        *(_WORD *)(a1[1447] + 2 * a1[1446]) = 0;
        *(_BYTE *)(a1[1444] + a1[1446]++) = v28;
        ++LOWORD(a1[v28 + 35]);
        if ( a1[1446] == a1[1445] - 1 )
        {
          v29 = a1[21];
          if ( v29 < 0 )
            v30 = 0;
          else
            v30 = v29 + a1[12];
          _tr_flush_block(a1, a2: v30, a3: a1[25] - v29, a4: 0);
          v38 = *a1;
          a1[21] = a1[25];
          sub_1001BC90(a1: v38);
        }
        v31 = a1[27] - 1;
        ++a1[25];
        v32 = *a1;
        a1[27] = v31;
        v26 = *(_DWORD *)(v32 + 16);
        goto LABEL_32;
      }
      v33 = a1[25] + 1;
      v34 = a1[27] - 1;
      a1[24] = 1;
      a1[25] = v33;
      a1[27] = v34;
    }
    else
    {
      v13 = a1[25] + a1[27] - 3;
      v14 = a1[25] - *((_WORD *)a1 + 46) - 1;
      v40 = *((_BYTE *)a1 + 112) - 3;
      *(_WORD *)(a1[1447] + 2 * a1[1446]) = v14;
      v15 = v14 - 1;
      *(_BYTE *)(a1[1444] + a1[1446]++) = v40;
      ++LOWORD(a1[(unsigned __int8)_length_code[v40] + 292]);
      if ( v15 >= 0x100u )
        v16 = (unsigned __int8)byte_1003F140[v15 >> 7];
      else
        v16 = (unsigned __int8)_dist_code[v15];
      ++LOWORD(a1[v16 + 608]);
      v17 = a1[28];
      v18 = a1[1446] == a1[1445] - 1;
      a1[27] += 1 - v17;
      a1[28] = v17 - 2;
      do
      {
        v19 = a1[25] + 1;
        a1[25] = v19;
        if ( v19 <= v13 )
        {
          v20 = a1[15];
          v21 = a1[19] & (*(unsigned __int8 *)(a1[12] + v19 + 2) ^ (a1[16] << a1[20]));
          HIWORD(v3) = 0;
          a1[16] = v21;
          LOWORD(v3) = *(_WORD *)(v20 + 2 * v21);
          *(_WORD *)(a1[14] + 2 * (v19 & a1[11])) = v3;
          *(_WORD *)(a1[15] + 2 * a1[16]) = *((_WORD *)a1 + 50);
        }
        v22 = a1[28] - 1;
        a1[28] = v22;
      }
      while ( v22 != 0 );
      v23 = a1[25] + 1;
      a1[24] = 0;
      a1[22] = 2;
      a1[25] = v23;
      if ( v18 )
      {
        v24 = a1[21];
        if ( v24 < 0 )
          v25 = 0;
        else
          v25 = v24 + a1[12];
        _tr_flush_block(a1, a2: v25, a3: v23 - v24, a4: 0);
        v37 = *a1;
        a1[21] = a1[25];
        sub_1001BC90(a1: v37);
        v26 = *(_DWORD *)(*a1 + 16);
LABEL_32:
        if ( v26 == 0 )
          return 0;
      }
    }
  }
  if ( a1[24] != 0 )
  {
    v41 = *(_BYTE *)(a1[25] + a1[12] - 1);
    *(_WORD *)(a1[1447] + 2 * a1[1446]) = 0;
    *(_BYTE *)(a1[1444] + a1[1446]++) = v41;
    ++LOWORD(a1[v41 + 35]);
    a1[24] = 0;
  }
  v35 = a1[21];
  if ( v35 < 0 )
    v36 = 0;
  else
    v36 = v35 + a1[12];
  _tr_flush_block(a1, a2: v36, a3: a1[25] - v35, a4: a2 == 4);
  v39 = *a1;
  a1[21] = a1[25];
  sub_1001BC90(a1: v39);
  if ( *(_DWORD *)(*a1 + 16) != 0 )
    return 2 * (a2 == 4) + 1;
  else
    return a2 != 4 ? 0 : 2;
}

//------------------------------------------------------------------------------
// Address: 0x1001CA40
// Name: _inflateReset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateReset(_DWORD *a1)
{
  _DWORD *v1; // ecx

  if ( a1 == nullptr )
    return -2;
  v1 = (_DWORD *)a1[7];
  if ( v1 == nullptr )
    return -2;
  a1[5] = 0;
  a1[2] = 0;
  a1[6] = 0;
  *v1 = v1[3] != 0 ? 7 : 0;
  inflate_blocks_reset(a1: *(_DWORD *)(a1[7] + 20), a2: a1, a3: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001CA90
// Name: _inflateEnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateEnd(_DWORD *a1)
{
  int v1; // eax
  int v2; // eax

  if ( a1 == nullptr )
    return -2;
  v1 = a1[7];
  if ( v1 == 0 || a1[9] == 0 )
    return -2;
  v2 = *(_DWORD *)(v1 + 20);
  if ( v2 != 0 )
    inflate_blocks_free(a1: v2, a2: a1);
  ((void (__cdecl *)(_DWORD, _DWORD))a1[9])(a1: a1[10], a2: a1[7]);
  a1[7] = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001CAE0
// Name: _inflateInit2_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateInit2_(_DWORD *a1, int a2, _BYTE *a3, int a4)
{
  int v5; // eax
  int v6; // eax
  int v7; // ecx

  if ( a3 == nullptr || *a3 != a113_0[0] || a4 != 56 )
    return -6;
  if ( a1 == nullptr )
    return -2;
  v5 = a1[8];
  a1[6] = 0;
  if ( v5 == 0 )
  {
    a1[8] = zcalloc;
    a1[10] = 0;
  }
  if ( a1[9] == 0 )
    a1[9] = zcfree;
  v6 = ((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: 1, a3: 24);
  a1[7] = v6;
  if ( v6 == 0 )
    return -4;
  v7 = a2;
  *(_DWORD *)(v6 + 20) = 0;
  *(_DWORD *)(a1[7] + 12) = 0;
  if ( a2 < 0 )
  {
    v7 = -a2;
    *(_DWORD *)(a1[7] + 12) = 1;
  }
  if ( v7 < 8 || v7 > 15 )
  {
    inflateEnd(a1);
    return -2;
  }
  else
  {
    *(_DWORD *)(a1[7] + 16) = v7;
    *(_DWORD *)(a1[7] + 20) = inflate_blocks_new(a1, a2: *(_DWORD *)(a1[7] + 12) == 0 ? adler32 : nullptr, a3: 1 << v7);
    if ( *(_DWORD *)(a1[7] + 20) != 0 )
    {
      inflateReset(a1);
      return 0;
    }
    else
    {
      inflateEnd(a1);
      return -4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CBF0
// Name: _inflateInit_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateInit_(_DWORD *a1, _BYTE *a2, int a3)
{
  return inflateInit2_(a1, a2: 15, a3: a2, a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x1001CC10
// Name: _inflate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate(unsigned __int8 **a1, int a2)
{
  int v2; // edi
  unsigned int v3; // ebx
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // eax
  int v7; // ecx
  unsigned __int8 *v8; // edx
  unsigned __int8 *v9; // edx
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // ebx
  int v12; // ecx
  unsigned __int8 *v13; // eax
  int v14; // eax
  unsigned __int8 *v15; // eax
  unsigned __int8 *v16; // eax
  unsigned __int8 *v17; // edx
  unsigned __int8 *v18; // eax
  unsigned __int8 *v19; // ecx
  unsigned __int8 *v20; // eax
  unsigned __int8 *v21; // ecx
  unsigned __int8 *v22; // eax
  unsigned __int8 *v23; // ecx
  int v24; // edx
  unsigned __int8 *v25; // eax
  unsigned __int8 *v26; // eax
  unsigned __int8 *v27; // edx
  unsigned __int8 *v28; // eax
  unsigned __int8 *v30; // ecx
  unsigned __int8 *v31; // ecx
  unsigned __int8 *v32; // eax
  unsigned __int8 *v33; // edx
  unsigned __int8 *v34; // edx
  unsigned __int8 *v35; // eax
  unsigned __int8 *v36; // ecx
  unsigned __int8 *v37; // eax
  unsigned __int8 *v38; // ecx
  int v39; // edx
  unsigned __int8 *v40; // eax
  unsigned __int8 *v41; // eax
  unsigned __int8 *v42; // eax
  unsigned int v43; // [esp+18h] [ebp+8h]

  if ( a1 == nullptr || a1[7] == nullptr || *a1 == nullptr )
    return -2;
  v2 = -5;
  v3 = a2 != 4 ? 0 : 0xFFFFFFFB;
  v43 = v3;
  while ( 2 )
  {
    v4 = a1[7];
    switch ( *(_DWORD *)v4 )
    {
      case 0:
        v5 = a1[1];
        if ( v5 == nullptr )
          return v2;
        a1[1] = v5 - 1;
        v2 = v3;
        ++a1[2];
        *((_DWORD *)v4 + 1) = **a1;
        v6 = a1[7];
        v7 = *((_DWORD *)v6 + 1) & 0xF;
        ++*a1;
        if ( (_BYTE)v7 != 8 )
        {
          *(_DWORD *)v6 = 13;
          v8 = a1[7];
          a1[6] = (unsigned __int8 *)aUnknownCompres;
          *((_DWORD *)v8 + 1) = 5;
          continue;
        }
        if ( (unsigned int)((*((_DWORD *)v6 + 1) >> 4) + 8) > *((_DWORD *)v6 + 4) )
        {
          *(_DWORD *)v6 = 13;
          v9 = a1[7];
          a1[6] = (unsigned __int8 *)aInvalidWindowS;
          *((_DWORD *)v9 + 1) = 5;
          continue;
        }
        *(_DWORD *)v6 = 1;
LABEL_12:
        v10 = a1[1];
        if ( v10 == nullptr )
          return v2;
        a1[1] = v10 - 1;
        v2 = v3;
        v11 = a1[7];
        ++a1[2];
        v12 = *(*a1)++;
        if ( (v12 + (*((_DWORD *)v11 + 1) << 8)) % 0x1Fu != 0 )
        {
          *(_DWORD *)v11 = 13;
          v13 = a1[7];
          v3 = v43;
          a1[6] = (unsigned __int8 *)aIncorrectHeade;
          *((_DWORD *)v13 + 1) = 5;
          continue;
        }
        if ( (v12 & 0x20) == 0 )
        {
          *(_DWORD *)v11 = 7;
          v3 = v43;
          continue;
        }
        v3 = v43;
        *(_DWORD *)a1[7] = 2;
LABEL_35:
        v28 = a1[1];
        if ( v28 == nullptr )
          return v2;
        v30 = *a1;
        ++a1[2];
        a1[1] = v28 - 1;
        v2 = v3;
        *((_DWORD *)a1[7] + 2) = *v30 << 24;
        v31 = a1[7];
        ++*a1;
        *(_DWORD *)v31 = 3;
LABEL_38:
        v32 = a1[1];
        if ( v32 == nullptr )
          return v2;
        v33 = *a1;
        a1[1] = v32 - 1;
        ++a1[2];
        v2 = v3;
        *((_DWORD *)a1[7] + 2) += *v33 << 16;
        v34 = a1[7];
        ++*a1;
        *(_DWORD *)v34 = 4;
LABEL_41:
        v35 = a1[1];
        if ( v35 == nullptr )
          return v2;
        v36 = *a1;
        a1[1] = v35 - 1;
        ++a1[2];
        v2 = v3;
        *((_DWORD *)a1[7] + 2) += *v36 << 8;
        ++*a1;
        *(_DWORD *)a1[7] = 5;
LABEL_44:
        v37 = a1[1];
        if ( v37 == nullptr )
          return v2;
        v38 = *a1;
        v39 = (int)(a1[2] + 1);
        a1[1] = v37 - 1;
        v40 = a1[7];
        a1[2] = (unsigned __int8 *)v39;
        *((_DWORD *)v40 + 2) += *v38;
        ++*a1;
        v41 = a1[7];
        a1[12] = *((unsigned __int8 **)v41 + 2);
        *(_DWORD *)v41 = 6;
        return 2;
      case 1:
        goto LABEL_12;
      case 2:
        goto LABEL_35;
      case 3:
        goto LABEL_38;
      case 4:
        goto LABEL_41;
      case 5:
        goto LABEL_44;
      case 6:
        *(_DWORD *)a1[7] = 13;
        v42 = a1[7];
        a1[6] = (unsigned __int8 *)aNeedDictionary;
        *((_DWORD *)v42 + 1) = 0;
        return -2;
      case 7:
        v14 = inflate_blocks(a1: *((_DWORD *)v4 + 5), a2: a1, a3: v2);
        v2 = v14;
        if ( v14 == -3 )
        {
          *(_DWORD *)a1[7] = 13;
          *((_DWORD *)a1[7] + 1) = 0;
        }
        else
        {
          if ( v14 == 0 )
            v2 = v3;
          if ( v2 != 1 )
            return v2;
          v2 = v3;
          inflate_blocks_reset(a1: *((_DWORD *)a1[7] + 5), a2: a1, a3: a1[7] + 4);
          v15 = a1[7];
          if ( *((_DWORD *)v15 + 3) != 0 )
          {
            *(_DWORD *)v15 = 12;
          }
          else
          {
            *(_DWORD *)v15 = 8;
LABEL_25:
            v16 = a1[1];
            if ( v16 == nullptr )
              return v2;
            v17 = a1[7];
            a1[1] = v16 - 1;
            ++a1[2];
            v2 = v3;
            *((_DWORD *)v17 + 2) = *(*a1)++ << 24;
            *(_DWORD *)a1[7] = 9;
LABEL_27:
            v18 = a1[1];
            if ( v18 == nullptr )
              return v2;
            v19 = *a1;
            ++a1[2];
            a1[1] = v18 - 1;
            v2 = v3;
            *((_DWORD *)a1[7] + 2) += *v19 << 16;
            ++*a1;
            *(_DWORD *)a1[7] = 10;
LABEL_29:
            v20 = a1[1];
            if ( v20 == nullptr )
              return v2;
            v21 = *a1;
            ++a1[2];
            a1[1] = v20 - 1;
            v2 = v3;
            *((_DWORD *)a1[7] + 2) += *v21 << 8;
            ++*a1;
            *(_DWORD *)a1[7] = 11;
LABEL_31:
            v22 = a1[1];
            if ( v22 == nullptr )
              return v2;
            v23 = *a1;
            v24 = (int)(a1[2] + 1);
            a1[1] = v22 - 1;
            v25 = a1[7];
            a1[2] = (unsigned __int8 *)v24;
            v2 = v3;
            *((_DWORD *)v25 + 2) += *v23;
            ++*a1;
            v26 = a1[7];
            if ( *((_DWORD *)v26 + 1) == *((_DWORD *)v26 + 2) )
            {
              *(_DWORD *)a1[7] = 12;
              return 1;
            }
            *(_DWORD *)v26 = 13;
            v27 = a1[7];
            a1[6] = (unsigned __int8 *)aIncorrectDataC;
            *((_DWORD *)v27 + 1) = 5;
          }
        }
        continue;
      case 8:
        goto LABEL_25;
      case 9:
        goto LABEL_27;
      case 0xA:
        goto LABEL_29;
      case 0xB:
        goto LABEL_31;
      case 0xC:
        return 1;
      case 0xD:
        return -3;
      default:
        return -2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D040
// Name: _zcalloc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl zcalloc(int a1, unsigned int count, unsigned int size)
{
  return calloc(count, size);
}

//------------------------------------------------------------------------------
// Address: 0x1001D060
// Name: _zcfree
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl zcfree(int a1, void *pMem)
{
  free(pMem);
}

//------------------------------------------------------------------------------
// Address: 0x1001D070
// Name: _adler32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl adler32(unsigned int a1, unsigned __int8 *a2, unsigned int a3)
{
  unsigned __int8 *v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // edi
  unsigned int i; // ebx
  int v8; // eax
  unsigned int v9; // ebp
  int v10; // edx
  int v11; // ecx
  int v12; // edi
  int v13; // ecx
  int v14; // edi
  int v15; // ecx
  int v16; // edi
  int v17; // ecx
  int v18; // edi
  int v19; // ecx
  int v20; // edi
  int v21; // ecx
  int v22; // edi
  int v23; // ecx
  int v24; // edi
  int v25; // ecx
  int v26; // edi
  int v27; // ecx
  int v28; // edi
  int v29; // ecx
  int v30; // edi
  int v31; // ecx
  int v32; // edi
  int v33; // ecx
  int v34; // edi
  int v35; // ecx
  int v36; // edi
  int v37; // ecx
  int v38; // edi
  int v39; // ecx
  int v40; // edi

  v3 = a2;
  v4 = (unsigned __int16)a1;
  v5 = HIWORD(a1);
  if ( a2 == nullptr )
    return 1;
  for ( i = a3; i != 0; v5 %= 0xFFF1u )
  {
    v8 = i;
    if ( i >= 0x15B0 )
      v8 = 5552;
    i -= v8;
    if ( v8 >= 16 )
    {
      v9 = (unsigned int)v8 >> 4;
      v8 += -16 * ((unsigned int)v8 >> 4);
      do
      {
        v10 = *v3;
        v3 += 16;
        v11 = v10 + v4;
        v12 = v11 + v5;
        v13 = *(v3 - 15) + v11;
        v14 = v13 + v12;
        v15 = *(v3 - 14) + v13;
        v16 = v15 + v14;
        v17 = *(v3 - 13) + v15;
        v18 = v17 + v16;
        v19 = *(v3 - 12) + v17;
        v20 = v19 + v18;
        v21 = *(v3 - 11) + v19;
        v22 = v21 + v20;
        v23 = *(v3 - 10) + v21;
        v24 = v23 + v22;
        v25 = *(v3 - 9) + v23;
        v26 = v25 + v24;
        v27 = *(v3 - 8) + v25;
        v28 = v27 + v26;
        v29 = *(v3 - 7) + v27;
        v30 = v29 + v28;
        v31 = *(v3 - 6) + v29;
        v32 = v31 + v30;
        v33 = *(v3 - 5) + v31;
        v34 = v33 + v32;
        v35 = *(v3 - 4) + v33;
        v36 = v35 + v34;
        v37 = *(v3 - 3) + v35;
        v38 = v37 + v36;
        v39 = *(v3 - 2) + v37;
        v40 = v39 + v38;
        v4 = *(v3 - 1) + v39;
        v5 = v4 + v40;
        --v9;
      }
      while ( v9 != 0 );
    }
    for ( ; v8 != 0; --v8 )
    {
      v4 += *v3++;
      v5 += v4;
    }
    v4 %= 0xFFF1u;
  }
  return v4 | (v5 << 16);
}

//------------------------------------------------------------------------------
// Address: 0x1001D1A0
// Name: __tr_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tr_init(int a1)
{
  nullsub_4();
  *(_DWORD *)(a1 + 2832) = a1 + 140;
  *(_DWORD *)(a1 + 2856) = a1 + 2676;
  *(_DWORD *)(a1 + 2840) = &off_10045FCC;
  *(_DWORD *)(a1 + 2844) = a1 + 2432;
  *(_DWORD *)(a1 + 2852) = &off_10045FE0;
  *(_DWORD *)(a1 + 2864) = &unk_10045FF4;
  *(_WORD *)(a1 + 5808) = 0;
  *(_DWORD *)(a1 + 5812) = 0;
  *(_DWORD *)(a1 + 5804) = 8;
  return sub_1001D220(a1);
}

//------------------------------------------------------------------------------
// Address: 0x1001D210
// Name: nullsub_4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_4()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1001D220
// Name: sub_1001D220
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_WORD *__cdecl sub_1001D220(int a1)
{
  int v1; // ecx
  _WORD *v2; // eax
  _WORD *v3; // eax
  int i; // ecx
  _WORD *result; // eax
  int j; // ecx

  v1 = 286;
  v2 = (_WORD *)(a1 + 140);
  do
  {
    *v2 = 0;
    v2 += 2;
    --v1;
  }
  while ( v1 != 0 );
  v3 = (_WORD *)(a1 + 2432);
  for ( i = 30; i != 0; --i )
  {
    *v3 = 0;
    v3 += 2;
  }
  result = (_WORD *)(a1 + 2676);
  for ( j = 19; j != 0; --j )
  {
    *result = 0;
    result += 2;
  }
  *(_DWORD *)(a1 + 5796) = 0;
  *(_DWORD *)(a1 + 5792) = 0;
  *(_DWORD *)(a1 + 5800) = 0;
  *(_DWORD *)(a1 + 5784) = 0;
  *(_WORD *)(a1 + 1164) = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001D290
// Name: __tr_stored_block
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tr_stored_block(int a1, int a2, int a3, int a4)
{
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  char v8; // bl
  int v9; // ecx
  int v10; // edx

  v4 = *(_DWORD *)(a1 + 5812);
  if ( v4 <= 13 )
  {
    *(_WORD *)(a1 + 5808) |= a4 << v4;
    *(_DWORD *)(a1 + 5812) = v4 + 3;
  }
  else
  {
    v5 = a4 << v4;
    v6 = *(_DWORD *)(a1 + 8);
    *(_WORD *)(a1 + 5808) |= v5;
    *(_BYTE *)(v6 + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v7 = *(_DWORD *)(a1 + 8);
    v8 = *(_BYTE *)(a1 + 5809);
    v9 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v9;
    *(_BYTE *)(v9 + v7) = v8;
    v10 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v10 - 13;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)a4 >> (16 - v10);
  }
  return sub_1001EB50(a1, a2, a3, a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1001D330
// Name: __tr_align
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tr_align(int a1)
{
  int v1; // ecx
  char v2; // dl
  int v3; // ecx
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  char v8; // dl
  int v9; // ecx
  int result; // eax
  int v11; // ecx
  char v12; // dl
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  char v18; // dl
  int v19; // ecx

  v1 = *(_DWORD *)(a1 + 5812);
  *(_WORD *)(a1 + 5808) |= 2 << v1;
  if ( v1 <= 13 )
  {
    *(_DWORD *)(a1 + 5812) = v1 + 3;
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v2 = *(_BYTE *)(a1 + 5809);
    v3 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v3;
    *(_BYTE *)(v3 + *(_DWORD *)(a1 + 8)) = v2;
    ++*(_DWORD *)(a1 + 20);
    v4 = *(_DWORD *)(a1 + 5812);
    *(_DWORD *)(a1 + 5812) = v4 - 13;
    *(_WORD *)(a1 + 5808) = 2u >> (16 - v4);
  }
  v5 = *(_DWORD *)(a1 + 5812);
  if ( v5 <= 9 )
  {
    *(_WORD *)(a1 + 5808) = *(_WORD *)(a1 + 5808);
    *(_DWORD *)(a1 + 5812) = v5 + 7;
  }
  else
  {
    v6 = *(_DWORD *)(a1 + 8);
    v7 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) = *(_WORD *)(a1 + 5808);
    *(_BYTE *)(v6 + v7) = *(_BYTE *)(a1 + 5808);
    v8 = *(_BYTE *)(a1 + 5809);
    v9 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v9;
    *(_BYTE *)(v9 + *(_DWORD *)(a1 + 8)) = v8;
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) -= 9;
    *(_WORD *)(a1 + 5808) = 0;
  }
  result = sub_1001EA40(a1);
  v11 = *(_DWORD *)(a1 + 5812);
  if ( *(_DWORD *)(a1 + 5804) - v11 + 11 < 9 )
  {
    *(_WORD *)(a1 + 5808) |= 2 << v11;
    if ( v11 <= 13 )
    {
      *(_DWORD *)(a1 + 5812) = v11 + 3;
    }
    else
    {
      *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
      v12 = *(_BYTE *)(a1 + 5809);
      v13 = *(_DWORD *)(a1 + 20) + 1;
      *(_DWORD *)(a1 + 20) = v13;
      *(_BYTE *)(v13 + *(_DWORD *)(a1 + 8)) = v12;
      ++*(_DWORD *)(a1 + 20);
      v14 = *(_DWORD *)(a1 + 5812);
      *(_DWORD *)(a1 + 5812) = v14 - 13;
      *(_WORD *)(a1 + 5808) = 2u >> (16 - v14);
    }
    v15 = *(_DWORD *)(a1 + 5812);
    if ( v15 <= 9 )
    {
      *(_WORD *)(a1 + 5808) = *(_WORD *)(a1 + 5808);
      *(_DWORD *)(a1 + 5812) = v15 + 7;
    }
    else
    {
      v16 = *(_DWORD *)(a1 + 8);
      v17 = *(_DWORD *)(a1 + 20);
      *(_WORD *)(a1 + 5808) = *(_WORD *)(a1 + 5808);
      *(_BYTE *)(v16 + v17) = *(_BYTE *)(a1 + 5808);
      v18 = *(_BYTE *)(a1 + 5809);
      v19 = *(_DWORD *)(a1 + 20) + 1;
      *(_DWORD *)(a1 + 20) = v19;
      *(_BYTE *)(v19 + *(_DWORD *)(a1 + 8)) = v18;
      ++*(_DWORD *)(a1 + 20);
      *(_DWORD *)(a1 + 5812) -= 9;
      *(_WORD *)(a1 + 5808) = 0;
    }
    result = sub_1001EA40(a1);
  }
  *(_DWORD *)(a1 + 5804) = 7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001D540
// Name: __tr_flush_block
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_WORD *__cdecl _tr_flush_block(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // ecx
  int v7; // edi
  bool v8; // zf
  int v9; // ecx
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  char v13; // bl
  int v14; // edx
  int v15; // edx
  int v16; // edx
  int v17; // ebx
  int v18; // ecx
  int v19; // ebx
  char v20; // al
  int v21; // ecx
  int v22; // ebx
  _WORD *result; // eax
  int v24; // [esp+20h] [ebp+10h]

  v4 = 0;
  if ( *(int *)(a1 + 124) <= 0 )
  {
    v6 = a3 + 5;
LABEL_7:
    v5 = v6;
    goto LABEL_8;
  }
  if ( *(_BYTE *)(a1 + 28) == 2 )
    sub_1001E9A0(a1);
  sub_1001D730(a1, a2: a1 + 2832);
  sub_1001D730(a1, a2: a1 + 2844);
  v4 = sub_1001DCC0(a1);
  v5 = (unsigned int)(*(_DWORD *)(a1 + 5792) + 10) >> 3;
  v6 = (unsigned int)(*(_DWORD *)(a1 + 5796) + 10) >> 3;
  if ( v6 <= v5 )
    goto LABEL_7;
LABEL_8:
  if ( a3 + 4 <= v5 && a2 != 0 )
  {
    v7 = a4;
    _tr_stored_block(a1, a2, a3, a4);
  }
  else
  {
    v7 = a4;
    v8 = v6 == v5;
    v9 = *(_DWORD *)(a1 + 5812);
    if ( v8 )
    {
      v10 = a4 + 2;
      if ( v9 <= 13 )
      {
        *(_WORD *)(a1 + 5808) |= v10 << v9;
        *(_DWORD *)(a1 + 5812) = v9 + 3;
      }
      else
      {
        v11 = v10 << v9;
        v12 = *(_DWORD *)(a1 + 8);
        *(_WORD *)(a1 + 5808) |= v11;
        *(_BYTE *)(v12 + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
        v13 = *(_BYTE *)(a1 + 5809);
        v14 = *(_DWORD *)(a1 + 20) + 1;
        *(_DWORD *)(a1 + 20) = v14;
        *(_BYTE *)(v14 + *(_DWORD *)(a1 + 8)) = v13;
        v15 = *(_DWORD *)(a1 + 5812);
        ++*(_DWORD *)(a1 + 20);
        *(_DWORD *)(a1 + 5812) = v15 - 13;
        *(_WORD *)(a1 + 5808) = (unsigned __int16)v10 >> (16 - v15);
      }
      sub_1001E590(a1, a2: &unk_1003EB48, a3: &unk_1003EFC8);
    }
    else
    {
      v16 = a4 + 4;
      if ( v9 <= 13 )
      {
        *(_WORD *)(a1 + 5808) |= v16 << v9;
        *(_DWORD *)(a1 + 5812) = v9 + 3;
      }
      else
      {
        v24 = v4;
        v17 = v16 << v9;
        v18 = *(_DWORD *)(a1 + 8);
        *(_WORD *)(a1 + 5808) |= v17;
        *(_BYTE *)(v18 + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
        v19 = *(_DWORD *)(a1 + 8);
        v20 = *(_BYTE *)(a1 + 5809);
        v21 = *(_DWORD *)(a1 + 20) + 1;
        *(_DWORD *)(a1 + 20) = v21;
        *(_BYTE *)(v21 + v19) = v20;
        v22 = *(_DWORD *)(a1 + 5812);
        ++*(_DWORD *)(a1 + 20);
        v4 = v24;
        *(_DWORD *)(a1 + 5812) = v22 - 13;
        *(_WORD *)(a1 + 5808) = (unsigned __int16)v16 >> (16 - v22);
      }
      sub_1001DE20(a1, a2: *(_DWORD *)(a1 + 2836) + 1, a3: *(_DWORD *)(a1 + 2848) + 1, a4: v4 + 1);
      sub_1001E590(a1, a2: a1 + 140, a3: a1 + 2432);
    }
  }
  result = sub_1001D220(a1);
  if ( v7 != 0 )
    return (_WORD *)sub_1001EAD0(a1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001D730
// Name: sub_1001D730
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1001D730(_DWORD *a1, int *a2)
{
  int v3; // edi
  int *v4; // eax
  int v5; // ebp
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int i; // ebx
  int v14; // eax
  int v15; // ebx
  int v16; // ebp
  int v17; // edx
  int v18; // ecx
  char v19; // cl
  int v20; // ecx
  int v21; // edx
  int v23; // [esp+10h] [ebp-8h]
  int v24; // [esp+14h] [ebp-4h]
  int v25; // [esp+1Ch] [ebp+4h]

  v3 = *a2;
  v4 = (int *)a2[2];
  v5 = -1;
  v6 = *v4;
  v7 = v4[3];
  v8 = 0;
  v24 = v7;
  v23 = -1;
  a1[1298] = 0;
  for ( a1[1299] = 573; v8 < v7; ++v8 )
  {
    if ( *(_WORD *)(v3 + 4 * v8) != 0 )
    {
      v23 = v8;
      v9 = a1[1298] + 1;
      v5 = v8;
      a1[1298] = v9;
      a1[v9 + 725] = v8;
      v7 = v24;
      *((_BYTE *)a1 + v8 + 5200) = 0;
    }
    else
    {
      *(_WORD *)(v3 + 4 * v8 + 2) = 0;
    }
  }
  v10 = a1[1298];
  if ( v10 < 2 )
  {
    do
    {
      if ( v5 >= 2 )
        v11 = 0;
      else
        v11 = ++v5;
      v12 = v10 + 1;
      a1[1298] = v12;
      a1[v12 + 725] = v11;
      *(_WORD *)(v3 + 4 * v11) = 1;
      *((_BYTE *)a1 + v11 + 5200) = 0;
      --a1[1448];
      if ( v6 != 0 )
        a1[1449] -= *(unsigned __int16 *)(v6 + 4 * v11 + 2);
      v10 = a1[1298];
    }
    while ( v10 < 2 );
    v23 = v5;
  }
  a2[1] = v5;
  for ( i = a1[1298] / 2; i >= 1; --i )
    sub_1001D950(a1, a2: v3, a3: i);
  v25 = v24;
  do
  {
    v14 = a1[1298];
    v15 = a1[726];
    a1[726] = a1[v14 + 725];
    a1[1298] = v14 - 1;
    sub_1001D950(a1, a2: v3, a3: 1);
    v16 = a1[726];
    v17 = a1[1299] - 1;
    a1[1299] = v17;
    a1[v17 + 725] = v15;
    v18 = a1[1299] - 1;
    a1[1299] = v18;
    a1[v18 + 725] = v16;
    *(_WORD *)(v3 + 4 * v25) = *(_WORD *)(v3 + 4 * v15) + *(_WORD *)(v3 + 4 * v16);
    if ( *((_BYTE *)a1 + v15 + 5200) < *((_BYTE *)a1 + v16 + 5200) )
      v19 = *((_BYTE *)a1 + v16 + 5200);
    else
      v19 = *((_BYTE *)a1 + v15 + 5200);
    *((_BYTE *)a1 + v25 + 5200) = v19 + 1;
    *(_WORD *)(v3 + 4 * v16 + 2) = v25;
    *(_WORD *)(v3 + 4 * v15 + 2) = v25;
    a1[726] = v25++;
    sub_1001D950(a1, a2: v3, a3: 1);
  }
  while ( (int)a1[1298] >= 2 );
  v20 = a1[726];
  v21 = a1[1299] - 1;
  a1[1299] = v21;
  a1[v21 + 725] = v20;
  sub_1001DA30(a1, a2);
  return sub_1001DC40(a1: v3, a2: v23, a3: a1 + 717);
}

//------------------------------------------------------------------------------
// Address: 0x1001D950
// Name: sub_1001D950
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1001D950(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // edx
  int v5; // ebp
  int v6; // ecx
  bool v7; // cc
  int v8; // esi
  int v9; // ebp
  unsigned __int16 v10; // dx
  unsigned __int16 v11; // bx
  int v12; // esi
  unsigned __int16 v13; // dx
  unsigned __int16 v14; // bx
  int v15; // edx
  int v16; // edx
  int v17; // [esp+14h] [ebp+4h]

  result = a1;
  v4 = *(_DWORD *)(a1 + 5192);
  v5 = *(_DWORD *)(a1 + 4 * a3 + 2900);
  v6 = 2 * a3;
  v7 = 2 * a3 < v4;
  v17 = v5;
  if ( 2 * a3 > v4 )
  {
    *(_DWORD *)(result + 4 * a3 + 2900) = v5;
  }
  else
  {
    while ( 1 )
    {
      if ( v7 )
      {
        v8 = *(_DWORD *)(result + 4 * v6 + 2904);
        v9 = *(_DWORD *)(result + 4 * v6 + 2900);
        v10 = *(_WORD *)(a2 + 4 * v8);
        v11 = *(_WORD *)(a2 + 4 * v9);
        if ( v10 < v11 || v10 == v11 && *(_BYTE *)(v8 + result + 5200) <= *(_BYTE *)(result + v9 + 5200) )
          ++v6;
        v5 = v17;
      }
      v12 = *(_DWORD *)(result + 4 * v6 + 2900);
      v13 = *(_WORD *)(a2 + 4 * v5);
      v14 = *(_WORD *)(a2 + 4 * v12);
      if ( v13 < v14 )
      {
LABEL_12:
        *(_DWORD *)(result + 4 * a3 + 2900) = v5;
        return result;
      }
      if ( v13 == v14 && *(_BYTE *)(result + v5 + 5200) <= *(_BYTE *)(v12 + result + 5200) )
        break;
      v15 = a3;
      a3 = v6;
      v6 *= 2;
      *(_DWORD *)(result + 4 * v15 + 2900) = v12;
      v16 = *(_DWORD *)(result + 5192);
      v7 = v6 < v16;
      if ( v6 > v16 )
        goto LABEL_12;
    }
    *(_DWORD *)(result + 4 * a3 + 2900) = v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001DA30
// Name: sub_1001DA30
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 __cdecl sub_1001DA30(_DWORD *a1, int *a2)
{
  int v2; // ebp
  int *v3; // eax
  int v4; // ebx
  int v5; // esi
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ebx
  int v11; // edi
  bool v12; // zf
  _WORD *v13; // edi
  _WORD *i; // ecx
  int v15; // esi
  int v16; // ebx
  int v17; // ecx
  _WORD *v18; // edi
  int v19; // eax
  int v21; // [esp+10h] [ebp-18h]
  int v22; // [esp+14h] [ebp-14h]
  int v23; // [esp+18h] [ebp-10h]
  int v24; // [esp+1Ch] [ebp-Ch]
  int v25; // [esp+20h] [ebp-8h]
  int v26; // [esp+24h] [ebp-4h]
  int *v27; // [esp+2Ch] [ebp+4h]
  int v28; // [esp+2Ch] [ebp+4h]
  int v29; // [esp+30h] [ebp+8h]
  int v30; // [esp+30h] [ebp+8h]

  v2 = *a2;
  v3 = (int *)a2[2];
  v24 = a2[1];
  v4 = 0;
  v5 = *v3;
  v26 = v3[1];
  v25 = v3[2];
  v21 = v3[4];
  v29 = 0;
  memset(a1 + 717, 0, 0x20u);
  *(_WORD *)(v2 + 4 * a1[a1[1299] + 725] + 2) = 0;
  v7 = a1[1299] + 1;
  if ( v7 < 573 )
  {
    v27 = &a1[v7 + 725];
    v23 = 573 - v7;
    v22 = 573;
    do
    {
      v8 = *v27;
      v9 = *(unsigned __int16 *)(v2 + 4 * *(unsigned __int16 *)(v2 + 4 * *v27 + 2) + 2) + 1;
      if ( v9 > v21 )
      {
        ++v4;
        v9 = v21;
        v29 = v4;
      }
      *(_WORD *)(v2 + 4 * v8 + 2) = v9;
      if ( v8 <= v24 )
      {
        ++*((_WORD *)a1 + v9 + 1434);
        v10 = 0;
        if ( v8 >= v25 )
          v10 = *(_DWORD *)(v26 + 4 * (v8 - v25));
        v11 = *(unsigned __int16 *)(v2 + 4 * v8);
        a1[1448] += v11 * (v10 + v9);
        if ( v5 != 0 )
          a1[1449] += v11 * (v10 + *(unsigned __int16 *)(v5 + 4 * v8 + 2));
        v4 = v29;
      }
      LOWORD(v7) = v23 - 1;
      v12 = v23 == 1;
      ++v27;
      --v23;
    }
    while ( !v12 );
    if ( v4 != 0 )
    {
      v13 = (_WORD *)a1 + v21 + 1434;
      do
      {
        v7 = v21 - 1;
        for ( i = (_WORD *)a1 + v21 + 1433; *i == 0; --v7 )
          --i;
        --*((_WORD *)a1 + v7 + 1434);
        *((_WORD *)a1 + v7 + 1435) += 2;
        --*v13;
        v4 -= 2;
      }
      while ( v4 > 0 );
      v15 = v21;
      if ( v21 != 0 )
      {
        v28 = (int)a1 + 2 * v21 + 2868;
        do
        {
          v7 = (unsigned __int16)*v13;
          v30 = v7;
          if ( *v13 != 0 )
          {
            v16 = (int)&a1[v22 + 725];
            do
            {
              v17 = *(_DWORD *)(v16 - 4);
              v16 -= 4;
              --v22;
              if ( v17 <= v24 )
              {
                v18 = (_WORD *)(v2 + 4 * v17 + 2);
                HIWORD(v19) = 0;
                if ( (unsigned __int16)*v18 != v15 )
                {
                  LOWORD(v19) = *v18;
                  a1[1448] += *(unsigned __int16 *)(v2 + 4 * v17) * (v15 - v19);
                  *v18 = v15;
                }
                v7 = --v30;
              }
            }
            while ( v7 != 0 );
          }
          --v15;
          v13 = (_WORD *)(v28 - 2);
          v28 -= 2;
        }
        while ( v15 != 0 );
      }
    }
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1001DC40
// Name: sub_1001DC40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 __cdecl sub_1001DC40(int a1, int a2, int a3)
{
  __int16 v3; // cx
  int i; // eax
  __int16 v5; // si
  int j; // esi
  unsigned __int16 v7; // dx
  _WORD v9[2]; // [esp+6h] [ebp-22h]
  char v10; // [esp+Ah] [ebp-1Eh] BYREF

  v3 = 0;
  for ( i = 1; i <= 15; v9[i] = 2 * v5 )
  {
    v5 = v3 + *(_WORD *)((char *)&v9[++i] + a3 - (_DWORD)&v10);
    v3 = 2 * v5;
  }
  for ( j = 0; j <= a2; ++j )
  {
    i = *(unsigned __int16 *)(a1 + 4 * j + 2);
    if ( (_WORD)i != 0 )
    {
      v7 = v9[i + 1];
      v9[i + 1] = v7 + 1;
      LOWORD(i) = sub_1001EA20(a1: v7, a2: i);
      *(_WORD *)(a1 + 4 * j) = i;
    }
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x1001DCC0
// Name: sub_1001DCC0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1001DCC0(_DWORD *a1)
{
  int result; // eax

  sub_1001DD30(a1, a2: a1 + 35, a3: a1[709]);
  sub_1001DD30(a1, a2: a1 + 608, a3: a1[712]);
  sub_1001D730(a1, a2: a1 + 714);
  for ( result = 18; result >= 3; --result )
  {
    if ( HIWORD(a1[(unsigned __int8)byte_1003EB34[result] + 669]) != 0 )
      break;
  }
  a1[1448] += 3 * result + 17;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001DD30
// Name: sub_1001DD30
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1001DD30(_WORD *a1, int a2, int a3)
{
  int result; // eax
  int v4; // ecx
  int v5; // edi
  int v6; // edx
  int v7; // esi
  unsigned __int16 *v8; // ebp
  int v9; // eax
  int v10; // [esp+Ch] [ebp-4h]
  int v11; // [esp+18h] [ebp+8h]

  result = a2;
  v4 = *(unsigned __int16 *)(a2 + 2);
  v5 = 0;
  v10 = -1;
  v6 = 7;
  v7 = 4;
  if ( (_WORD)v4 == 0 )
  {
    v6 = 138;
    v7 = 3;
  }
  *(_WORD *)(a2 + 4 * a3 + 6) = -1;
  if ( a3 >= 0 )
  {
    v11 = a3 + 1;
    v8 = (unsigned __int16 *)(result + 6);
    do
    {
      v9 = v4;
      v4 = *v8;
      if ( ++v5 >= v6 || v9 != v4 )
      {
        if ( v5 >= v7 )
        {
          if ( v9 != 0 )
          {
            if ( v9 != v10 )
              ++a1[2 * v9 + 1338];
            ++a1[1370];
          }
          else if ( v5 > 10 )
          {
            ++a1[1374];
          }
          else
          {
            ++a1[1372];
          }
        }
        else
        {
          a1[2 * v9 + 1338] += v5;
        }
        v5 = 0;
        v10 = v9;
        if ( v4 != 0 )
        {
          if ( v9 == v4 )
          {
            v6 = 6;
            v7 = 3;
          }
          else
          {
            v6 = 7;
            v7 = 4;
          }
        }
        else
        {
          v6 = 138;
          v7 = 3;
        }
      }
      v8 += 2;
      result = --v11;
    }
    while ( v11 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001DE20
// Name: sub_1001DE20
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1001DE20(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  char v9; // bl
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // edx
  char v16; // bl
  int v17; // ecx
  int v18; // edx
  int v19; // ecx
  int v20; // eax
  int v21; // edx
  int v22; // ecx
  char v23; // bl
  int v24; // edx
  int v25; // edx
  int i; // edi
  int v27; // ecx
  int v28; // eax
  int v29; // edx
  int v30; // ecx
  char v31; // bl
  int v32; // edx
  int v33; // edx

  v4 = a2 - 257;
  v5 = *(_DWORD *)(a1 + 5812);
  if ( v5 <= 11 )
  {
    *(_WORD *)(a1 + 5808) |= v4 << v5;
    *(_DWORD *)(a1 + 5812) = v5 + 5;
  }
  else
  {
    v6 = v4 << v5;
    v7 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) |= v6;
    *(_BYTE *)(v7 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
    v8 = *(_DWORD *)(a1 + 8);
    v9 = *(_BYTE *)(a1 + 5809);
    v10 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v10;
    *(_BYTE *)(v10 + v8) = v9;
    v11 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v11 - 11;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)v4 >> (16 - v11);
  }
  v12 = *(_DWORD *)(a1 + 5812);
  if ( v12 <= 11 )
  {
    *(_WORD *)(a1 + 5808) |= (a3 - 1) << v12;
    *(_DWORD *)(a1 + 5812) = v12 + 5;
  }
  else
  {
    v13 = (a3 - 1) << v12;
    v14 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) |= v13;
    *(_BYTE *)(v14 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
    v15 = *(_DWORD *)(a1 + 8);
    v16 = *(_BYTE *)(a1 + 5809);
    v17 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v17;
    *(_BYTE *)(v17 + v15) = v16;
    v18 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v18 - 11;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)(a3 - 1) >> (16 - v18);
  }
  v19 = *(_DWORD *)(a1 + 5812);
  v20 = a4 - 4;
  if ( v19 <= 12 )
  {
    *(_WORD *)(a1 + 5808) |= v20 << v19;
    *(_DWORD *)(a1 + 5812) = v19 + 4;
  }
  else
  {
    v21 = v20 << v19;
    v22 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) |= v21;
    *(_BYTE *)(v22 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
    v23 = *(_BYTE *)(a1 + 5809);
    v24 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v24;
    *(_BYTE *)(v24 + *(_DWORD *)(a1 + 8)) = v23;
    v25 = *(_DWORD *)(a1 + 5812);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5812) = v25 - 12;
    *(_WORD *)(a1 + 5808) = (unsigned __int16)v20 >> (16 - v25);
  }
  for ( i = 0; i < a4; ++i )
  {
    v27 = *(_DWORD *)(a1 + 5812);
    v28 = 0;
    if ( v27 <= 13 )
    {
      LOBYTE(v28) = byte_1003EB34[i];
      *(_WORD *)(a1 + 5808) |= *(_WORD *)(a1 + 4 * v28 + 2678) << v27;
      *(_DWORD *)(a1 + 5812) = v27 + 3;
    }
    else
    {
      LOWORD(v28) = *(_WORD *)(a1 + 4 * (unsigned __int8)byte_1003EB34[i] + 2678);
      v29 = v28 << v27;
      v30 = *(_DWORD *)(a1 + 20);
      *(_WORD *)(a1 + 5808) |= v29;
      *(_BYTE *)(v30 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5808);
      v31 = *(_BYTE *)(a1 + 5809);
      v32 = *(_DWORD *)(a1 + 20) + 1;
      *(_DWORD *)(a1 + 20) = v32;
      *(_BYTE *)(v32 + *(_DWORD *)(a1 + 8)) = v31;
      v33 = *(_DWORD *)(a1 + 5812);
      ++*(_DWORD *)(a1 + 20);
      *(_DWORD *)(a1 + 5812) = v33 - 13;
      *(_WORD *)(a1 + 5808) = (unsigned __int16)v28 >> (16 - v33);
    }
  }
  sub_1001E070(a1, a2: a1 + 140, a3: a2 - 1);
  return sub_1001E070(a1, a2: a1 + 2432, a3: a3 - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1001E070
// Name: sub_1001E070
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1001E070(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // ebx
  int v5; // esi
  int v6; // ecx
  int v7; // edx
  int v8; // edi
  int v9; // ebp
  int v10; // ecx
  int v11; // edi
  unsigned __int16 v12; // si
  int v13; // edx
  int v14; // ecx
  char v15; // bl
  int v16; // edx
  int v17; // edx
  int v18; // ecx
  int v19; // ecx
  int v20; // edi
  unsigned __int16 v21; // si
  int v22; // edx
  int v23; // ecx
  char v24; // bl
  int v25; // edx
  int v26; // edx
  int v27; // ecx
  int v28; // ecx
  int v29; // edi
  unsigned __int16 v30; // si
  int v31; // edx
  int v32; // ecx
  char v33; // bl
  int v34; // edx
  int v35; // edx
  int v36; // ecx
  int v37; // esi
  int v38; // edx
  int v39; // ecx
  char v40; // bl
  int v41; // edx
  int v42; // edx
  int v43; // ecx
  int v44; // ecx
  int v45; // edi
  unsigned __int16 v46; // si
  int v47; // edx
  int v48; // ecx
  char v49; // bl
  int v50; // edx
  int v51; // edx
  int v52; // ecx
  int v53; // esi
  int v54; // edx
  int v55; // ecx
  char v56; // bl
  int v57; // edx
  int v58; // edx
  unsigned __int16 v59; // si
  int v60; // edx
  int v61; // ecx
  char v62; // bl
  int v63; // edx
  int v64; // edx
  int v65; // ecx
  int v66; // esi
  int v67; // edx
  int v68; // ecx
  char v69; // bl
  int v70; // edx
  int v71; // edx
  bool v72; // zf
  int v73; // [esp+Ch] [ebp-8h]
  int v74; // [esp+10h] [ebp-4h]
  int v75; // [esp+18h] [ebp+4h]
  int v76; // [esp+1Ch] [ebp+8h]
  unsigned __int16 *v77; // [esp+20h] [ebp+Ch]

  result = a2;
  v4 = *(unsigned __int16 *)(a2 + 2);
  v5 = 0;
  v73 = -1;
  v6 = 7;
  v7 = 4;
  if ( (_WORD)v4 == 0 )
  {
    v6 = 138;
    v7 = 3;
  }
  if ( a3 >= 0 )
  {
    v8 = a3 + 1;
    v77 = (unsigned __int16 *)(a2 + 6);
    result = a1;
    v74 = v8;
    do
    {
      v9 = v4;
      ++v5;
      v4 = *v77;
      v75 = v4;
      v76 = v5;
      if ( v5 < v6 && v9 == v4 )
        goto LABEL_44;
      if ( v5 < v7 )
      {
        do
        {
          v10 = *(_DWORD *)(result + 5812);
          v11 = *(unsigned __int16 *)(result + 4 * v9 + 2678);
          if ( v10 <= 16 - (unsigned __int16)v11 )
          {
            *(_WORD *)(result + 5808) |= *(_WORD *)(result + 4 * v9 + 2676) << v10;
            v18 = v11 + v10;
          }
          else
          {
            v12 = *(_WORD *)(result + 4 * v9 + 2676);
            v13 = v12 << v10;
            v14 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v13;
            *(_BYTE *)(v14 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v15 = *(_BYTE *)(result + 5809);
            v16 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v16;
            *(_BYTE *)(v16 + *(_DWORD *)(result + 8)) = v15;
            v17 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v18 = v17 + v11 - 16;
            *(_WORD *)(result + 5808) = v12 >> (16 - v17);
            v5 = v76;
          }
          --v5;
          *(_DWORD *)(result + 5812) = v18;
          v76 = v5;
        }
        while ( v5 != 0 );
        goto LABEL_39;
      }
      if ( v9 != 0 )
      {
        if ( v9 != v73 )
        {
          v19 = *(_DWORD *)(result + 5812);
          v20 = *(unsigned __int16 *)(result + 4 * v9 + 2678);
          if ( v19 <= 16 - (unsigned __int16)v20 )
          {
            *(_WORD *)(result + 5808) |= *(_WORD *)(result + 4 * v9 + 2676) << v19;
            v27 = v20 + v19;
          }
          else
          {
            v21 = *(_WORD *)(result + 4 * v9 + 2676);
            v22 = v21 << v19;
            v23 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v22;
            *(_BYTE *)(v23 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v24 = *(_BYTE *)(result + 5809);
            v25 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v25;
            *(_BYTE *)(v25 + *(_DWORD *)(result + 8)) = v24;
            v26 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v27 = v26 + v20 - 16;
            *(_WORD *)(result + 5808) = v21 >> (16 - v26);
            v5 = v76;
          }
          --v5;
          *(_DWORD *)(result + 5812) = v27;
          v76 = v5;
        }
        v28 = *(_DWORD *)(result + 5812);
        v29 = *(unsigned __int16 *)(result + 2742);
        if ( v28 <= 16 - (unsigned __int16)v29 )
        {
          *(_WORD *)(result + 5808) |= *(_WORD *)(result + 2740) << v28;
          v36 = v29 + v28;
        }
        else
        {
          v30 = *(_WORD *)(result + 2740);
          v31 = v30 << v28;
          v32 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v31;
          *(_BYTE *)(v32 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v33 = *(_BYTE *)(result + 5809);
          v34 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v34;
          *(_BYTE *)(v34 + *(_DWORD *)(result + 8)) = v33;
          v35 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v36 = v35 + v29 - 16;
          *(_WORD *)(result + 5808) = v30 >> (16 - v35);
          v5 = v76;
        }
        v37 = v5 - 3;
        *(_DWORD *)(result + 5812) = v36;
        if ( v36 > 14 )
        {
          v38 = v37 << v36;
          v39 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v38;
          *(_BYTE *)(v39 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v40 = *(_BYTE *)(result + 5809);
          v41 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v41;
          *(_BYTE *)(v41 + *(_DWORD *)(result + 8)) = v40;
          v42 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          *(_DWORD *)(result + 5812) = v42 - 14;
          *(_WORD *)(result + 5808) = (unsigned __int16)v37 >> (16 - v42);
          goto LABEL_39;
        }
        *(_WORD *)(result + 5808) |= v37 << v36;
        v43 = v36 + 2;
      }
      else
      {
        v44 = *(_DWORD *)(result + 5812);
        HIWORD(v45) = 0;
        if ( v5 > 10 )
        {
          LOWORD(v45) = *(_WORD *)(result + 2750);
          if ( v44 <= 16 - v45 )
          {
            *(_WORD *)(result + 5808) |= *(_WORD *)(result + 2748) << v44;
            v65 = v45 + v44;
          }
          else
          {
            v59 = *(_WORD *)(result + 2748);
            v60 = v59 << v44;
            v61 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v60;
            *(_BYTE *)(v61 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v62 = *(_BYTE *)(result + 5809);
            v63 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v63;
            *(_BYTE *)(v63 + *(_DWORD *)(result + 8)) = v62;
            v64 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v65 = v64 + v45 - 16;
            *(_WORD *)(result + 5808) = v59 >> (16 - v64);
            v5 = v76;
          }
          v66 = v5 - 11;
          *(_DWORD *)(result + 5812) = v65;
          if ( v65 > 9 )
          {
            v67 = v66 << v65;
            v68 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v67;
            *(_BYTE *)(v68 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v69 = *(_BYTE *)(result + 5809);
            v70 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v70;
            *(_BYTE *)(v70 + *(_DWORD *)(result + 8)) = v69;
            v71 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            *(_DWORD *)(result + 5812) = v71 - 9;
            *(_WORD *)(result + 5808) = (unsigned __int16)v66 >> (16 - v71);
            goto LABEL_39;
          }
          *(_WORD *)(result + 5808) |= v66 << v65;
          v43 = v65 + 7;
        }
        else
        {
          LOWORD(v45) = *(_WORD *)(result + 2746);
          if ( v44 <= 16 - v45 )
          {
            *(_WORD *)(result + 5808) |= *(_WORD *)(result + 2744) << v44;
            v52 = v45 + v44;
          }
          else
          {
            v46 = *(_WORD *)(result + 2744);
            v47 = v46 << v44;
            v48 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v47;
            *(_BYTE *)(v48 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v49 = *(_BYTE *)(result + 5809);
            v50 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v50;
            *(_BYTE *)(v50 + *(_DWORD *)(result + 8)) = v49;
            v51 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v52 = v51 + v45 - 16;
            *(_WORD *)(result + 5808) = v46 >> (16 - v51);
            v5 = v76;
          }
          v53 = v5 - 3;
          *(_DWORD *)(result + 5812) = v52;
          if ( v52 > 13 )
          {
            v54 = v53 << v52;
            v55 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v54;
            *(_BYTE *)(v55 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v56 = *(_BYTE *)(result + 5809);
            v57 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v57;
            *(_BYTE *)(v57 + *(_DWORD *)(result + 8)) = v56;
            v58 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            *(_DWORD *)(result + 5812) = v58 - 13;
            *(_WORD *)(result + 5808) = (unsigned __int16)v53 >> (16 - v58);
            goto LABEL_39;
          }
          *(_WORD *)(result + 5808) |= v53 << v52;
          v43 = v52 + 3;
        }
      }
      *(_DWORD *)(result + 5812) = v43;
LABEL_39:
      v4 = v75;
      v5 = 0;
      v73 = v9;
      if ( v75 != 0 )
      {
        if ( v9 == v75 )
        {
          v6 = 6;
          v7 = 3;
        }
        else
        {
          v6 = 7;
          v7 = 4;
        }
      }
      else
      {
        v6 = 138;
        v7 = 3;
      }
LABEL_44:
      v72 = v74 == 1;
      v77 += 2;
      --v74;
    }
    while ( !v72 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001E590
// Name: sub_1001E590
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1001E590(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // ebx
  unsigned int v5; // edi
  int v6; // ebp
  int v7; // esi
  int v8; // ecx
  unsigned __int16 v9; // di
  int v10; // edx
  int v11; // ecx
  int v12; // ecx
  int v13; // edx
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  int v17; // edi
  unsigned __int16 v18; // di
  int v19; // edx
  int v20; // ecx
  char v21; // bl
  int v22; // edx
  int v23; // edx
  __int16 v24; // di
  __int16 v25; // bx
  int v26; // ecx
  int v27; // edi
  int v28; // esi
  int v29; // ecx
  int v30; // edx
  int v31; // ecx
  char v32; // bl
  int v33; // edx
  int v34; // edx
  int v35; // ecx
  unsigned int v36; // ebp
  int v37; // edx
  int v38; // ecx
  int v39; // edi
  unsigned __int16 v40; // si
  int v41; // edx
  int v42; // ecx
  char v43; // bl
  int v44; // edx
  int v45; // edx
  __int16 v46; // si
  int v47; // ecx
  int v48; // esi
  unsigned int v49; // ebp
  int v50; // ecx
  unsigned int v51; // edx
  int v52; // ecx
  int v53; // ecx
  int v54; // edx
  int v55; // edx
  int v56; // ecx
  int v57; // edi
  unsigned __int16 v58; // si
  int v59; // edx
  int v60; // ecx
  int v61; // ecx
  int v62; // edx
  int v63; // edx
  int v64; // ecx
  int v65; // [esp+10h] [ebp-8h]
  unsigned int v66; // [esp+14h] [ebp-4h]
  int v67; // [esp+1Ch] [ebp+4h]
  int v68; // [esp+1Ch] [ebp+4h]

  result = a1;
  v4 = a2;
  v5 = 0;
  if ( *(_DWORD *)(a1 + 5784) != 0 )
  {
    do
    {
      v6 = *(unsigned __int16 *)(*(_DWORD *)(result + 5788) + 2 * v5);
      v7 = *(unsigned __int8 *)(v5 + *(_DWORD *)(result + 5776));
      v8 = *(_DWORD *)(result + 5812);
      v66 = v5 + 1;
      if ( (_WORD)v6 != 0 )
      {
        HIWORD(v17) = 0;
        v16 = (unsigned __int8)_length_code[v7];
        v67 = v16;
        LOWORD(v17) = *(_WORD *)(v4 + 4 * v16 + 1030);
        v65 = (unsigned __int16)v17;
        if ( v8 <= 16 - (unsigned __int16)v17 )
        {
          v25 = *(_WORD *)(a2 + 4 * v16 + 1028) << v8;
          v26 = *(_DWORD *)(result + 5812);
          *(_WORD *)(result + 5808) |= v25;
          *(_DWORD *)(result + 5812) = v17 + v26;
        }
        else
        {
          v18 = *(_WORD *)(a2 + 4 * v16 + 1028);
          v19 = v18 << v8;
          v20 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v19;
          *(_BYTE *)(v20 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v21 = *(_BYTE *)(result + 5809);
          v22 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v22;
          *(_BYTE *)(v22 + *(_DWORD *)(result + 8)) = v21;
          v23 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v24 = v18 >> (16 - v23);
          *(_DWORD *)(result + 5812) = v23 + v65 - 16;
          v16 = v67;
          *(_WORD *)(result + 5808) = v24;
        }
        v27 = dword_1003E9F8[v16];
        if ( v27 != 0 )
        {
          v28 = v7 - dword_1003F340[v16];
          v29 = *(_DWORD *)(result + 5812);
          if ( v29 <= 16 - v27 )
          {
            *(_WORD *)(result + 5808) |= v28 << v29;
            v35 = v27 + v29;
          }
          else
          {
            v30 = v28 << v29;
            v31 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v30;
            *(_BYTE *)(v31 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
            v32 = *(_BYTE *)(result + 5809);
            v33 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v33;
            *(_BYTE *)(v33 + *(_DWORD *)(result + 8)) = v32;
            v34 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v35 = v34 + v27 - 16;
            *(_WORD *)(result + 5808) = (unsigned __int16)v28 >> (16 - v34);
          }
          *(_DWORD *)(result + 5812) = v35;
        }
        v36 = v6 - 1;
        if ( v36 >= 0x100 )
          v37 = (unsigned __int8)byte_1003F140[v36 >> 7];
        else
          v37 = (unsigned __int8)_dist_code[v36];
        v38 = *(_DWORD *)(result + 5812);
        v39 = *(unsigned __int16 *)(a3 + 4 * v37 + 2);
        v68 = v37;
        if ( v38 <= 16 - (unsigned __int16)v39 )
        {
          *(_WORD *)(result + 5808) |= *(_WORD *)(a3 + 4 * v37) << v38;
          v47 = v39 + v38;
        }
        else
        {
          v40 = *(_WORD *)(a3 + 4 * v37);
          v41 = v40 << v38;
          v42 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v41;
          *(_BYTE *)(v42 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v43 = *(_BYTE *)(result + 5809);
          v44 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v44;
          *(_BYTE *)(v44 + *(_DWORD *)(result + 8)) = v43;
          v45 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v46 = v40 >> (16 - v45);
          v47 = v45 + v39 - 16;
          v37 = v68;
          *(_WORD *)(result + 5808) = v46;
        }
        v4 = a2;
        *(_DWORD *)(result + 5812) = v47;
        v48 = dword_1003EA70[v37];
        if ( v48 == 0 )
          goto LABEL_25;
        v49 = v36 - dword_1003F3B8[v37];
        v50 = *(_DWORD *)(result + 5812);
        if ( v50 <= 16 - v48 )
        {
          *(_WORD *)(result + 5808) |= v49 << v50;
          v15 = v48 + v50;
        }
        else
        {
          v51 = v49 << v50;
          v52 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v51;
          *(_BYTE *)(v52 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v53 = *(_DWORD *)(result + 8);
          v54 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v54;
          *(_BYTE *)(v54 + v53) = *(_BYTE *)(result + 5809);
          v55 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v15 = v55 + v48 - 16;
          *(_WORD *)(result + 5808) = (unsigned __int16)v49 >> (16 - v55);
        }
      }
      else
      {
        LOWORD(v6) = *(_WORD *)(v4 + 4 * v7 + 2);
        if ( v8 <= 16 - (unsigned __int16)v6 )
        {
          *(_WORD *)(result + 5808) |= *(_WORD *)(v4 + 4 * v7) << v8;
          v15 = v6 + v8;
        }
        else
        {
          v9 = *(_WORD *)(v4 + 4 * v7);
          v10 = v9 << v8;
          v11 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v10;
          *(_BYTE *)(v11 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
          v12 = *(_DWORD *)(result + 8);
          v13 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v13;
          *(_BYTE *)(v13 + v12) = *(_BYTE *)(result + 5809);
          v14 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v15 = v14 + v6 - 16;
          *(_WORD *)(result + 5808) = v9 >> (16 - v14);
        }
      }
      *(_DWORD *)(result + 5812) = v15;
LABEL_25:
      v5 = v66;
    }
    while ( v66 < *(_DWORD *)(result + 5784) );
  }
  v56 = *(_DWORD *)(result + 5812);
  v57 = *(unsigned __int16 *)(v4 + 1026);
  if ( v56 <= 16 - (unsigned __int16)v57 )
  {
    *(_WORD *)(result + 5808) |= *(_WORD *)(v4 + 1024) << v56;
    v64 = v57 + v56;
  }
  else
  {
    v58 = *(_WORD *)(v4 + 1024);
    v59 = v58 << v56;
    v60 = *(_DWORD *)(result + 8);
    *(_WORD *)(result + 5808) |= v59;
    *(_BYTE *)(v60 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5808);
    v61 = *(_DWORD *)(result + 8);
    v62 = *(_DWORD *)(result + 20) + 1;
    *(_DWORD *)(result + 20) = v62;
    *(_BYTE *)(v61 + v62) = *(_BYTE *)(result + 5809);
    v63 = *(_DWORD *)(result + 5812);
    ++*(_DWORD *)(result + 20);
    v64 = v63 + v57 - 16;
    *(_WORD *)(result + 5808) = v58 >> (16 - v63);
  }
  *(_DWORD *)(result + 5812) = v64;
  *(_DWORD *)(result + 5804) = *(unsigned __int16 *)(v4 + 1026);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001E9A0
// Name: sub_1001E9A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl sub_1001E9A0(int a1)
{
  unsigned int v1; // edi
  unsigned int v2; // edx
  unsigned __int16 *v3; // eax
  int i; // ecx
  unsigned __int16 v5; // si
  unsigned __int16 *v6; // eax
  int j; // ecx
  unsigned __int16 v8; // bp
  unsigned __int16 *v9; // ecx
  int k; // eax
  unsigned __int16 v11; // si
  unsigned int v12; // edi

  v1 = 0;
  v2 = 0;
  v3 = (unsigned __int16 *)(a1 + 140);
  for ( i = 7; i != 0; --i )
  {
    v5 = *v3;
    v3 += 2;
    v2 += v5;
  }
  v6 = (unsigned __int16 *)(a1 + 168);
  for ( j = 121; j != 0; --j )
  {
    v8 = *v6;
    v6 += 2;
    v1 += v8;
  }
  v9 = (unsigned __int16 *)(a1 + 652);
  for ( k = 128; k != 0; --k )
  {
    v11 = *v9;
    v9 += 2;
    v2 += v11;
  }
  v12 = v1 >> 2;
  *(_BYTE *)(a1 + 28) = v2 <= v12;
  return v2 <= v12;
}

//------------------------------------------------------------------------------
// Address: 0x1001EA20
// Name: sub_1001EA20
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_1001EA20(unsigned int a1, int a2)
{
  unsigned int v4; // eax
  int v5; // esi

  v4 = 0;
  do
  {
    v5 = a1 & 1;
    a1 >>= 1;
    v4 = 2 * (v5 | v4);
    --a2;
  }
  while ( a2 > 0 );
  return v4 >> 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001EA40
// Name: sub_1001EA40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1001EA40(int a1)
{
  int result; // eax
  int v2; // ecx
  char v3; // bl
  int v4; // edx
  int v5; // edx
  int v6; // ecx

  result = a1;
  v2 = *(_DWORD *)(a1 + 5812);
  if ( v2 == 16 )
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v3 = *(_BYTE *)(a1 + 5809);
    v4 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v4;
    *(_BYTE *)(v4 + *(_DWORD *)(a1 + 8)) = v3;
    ++*(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) = 0;
    *(_DWORD *)(a1 + 5812) = 0;
  }
  else if ( v2 >= 8 )
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v5 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) = *(unsigned __int8 *)(a1 + 5809);
    v6 = *(_DWORD *)(a1 + 5812);
    *(_DWORD *)(a1 + 20) = v5 + 1;
    *(_DWORD *)(a1 + 5812) = v6 - 8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001EAD0
// Name: sub_1001EAD0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1001EAD0(int a1)
{
  int result; // eax
  int v2; // edx
  char v3; // bl
  int v4; // edx

  result = a1;
  v2 = *(_DWORD *)(a1 + 5812);
  if ( v2 <= 8 )
  {
    if ( v2 > 0 )
      *(_BYTE *)(*(_DWORD *)(a1 + 8) + (*(_DWORD *)(a1 + 20))++) = *(_BYTE *)(a1 + 5808);
    *(_WORD *)(a1 + 5808) = 0;
    *(_DWORD *)(a1 + 5812) = 0;
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5808);
    v3 = *(_BYTE *)(a1 + 5809);
    v4 = *(_DWORD *)(a1 + 20) + 1;
    *(_DWORD *)(a1 + 20) = v4;
    *(_BYTE *)(v4 + *(_DWORD *)(a1 + 8)) = v3;
    ++*(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5808) = 0;
    *(_DWORD *)(a1 + 5812) = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001EB50
// Name: sub_1001EB50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1001EB50(_DWORD *a1, _BYTE *a2, int a3, int a4)
{
  int result; // eax
  int v5; // edi
  int v6; // edx
  int v7; // edi
  int v8; // ecx
  int v9; // edi
  int v10; // ecx

  sub_1001EAD0((int)a1);
  result = a3;
  a1[1451] = 8;
  if ( a4 != 0 )
  {
    *(_BYTE *)(a1[5] + a1[2]) = a3;
    v5 = a1[2];
    v6 = a1[5] + 1;
    a1[5] = v6;
    *(_BYTE *)(v6 + v5) = BYTE1(a3);
    v7 = a1[2];
    v8 = a1[5] + 1;
    a1[5] = v8;
    *(_BYTE *)(v8 + v7) = ~(_BYTE)a3;
    v9 = a1[5] + 1;
    v10 = a1[2];
    a1[5] = v9;
    *(_BYTE *)(v9 + v10) = ~BYTE1(a3);
    ++a1[5];
  }
  if ( a3 != 0 )
  {
    do
    {
      *(_BYTE *)(a1[5] + a1[2]) = *a2++;
      --result;
      ++a1[5];
    }
    while ( result != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001EBF0
// Name: _inflate_blocks_reset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int (__cdecl *__cdecl inflate_blocks_reset(_DWORD *a1, int a2, _DWORD *a3))(_DWORD, _DWORD, _DWORD)
{
  int v3; // eax
  int (__cdecl *result)(_DWORD, _DWORD, _DWORD); // eax

  if ( a3 != nullptr )
    *a3 = a1[15];
  if ( *a1 == 4 || *a1 == 5 )
    (*(void (__cdecl **)(_DWORD, _DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1[3]);
  if ( *a1 == 6 )
    inflate_codes_free(a1: a1[1], a2);
  v3 = a1[10];
  *a1 = 0;
  a1[13] = v3;
  a1[12] = v3;
  result = (int (__cdecl *)(_DWORD, _DWORD, _DWORD))a1[14];
  a1[7] = 0;
  a1[8] = 0;
  if ( result != nullptr )
  {
    result = (int (__cdecl *)(_DWORD, _DWORD, _DWORD))result(a1: 0, a2: 0, a3: 0);
    a1[15] = result;
    *(_DWORD *)(a2 + 48) = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001EC70
// Name: _inflate_blocks_new
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_blocks_new(int a1, int a2, int a3)
{
  int result; // eax
  _DWORD *v4; // esi
  int v5; // eax
  int v6; // eax

  result = (*(int (__cdecl **)(_DWORD, int, int))(a1 + 32))(a1: *(_DWORD *)(a1 + 40), a2: 1, a3: 64);
  v4 = (_DWORD *)result;
  if ( result != 0 )
  {
    v5 = (*(int (__cdecl **)(_DWORD, int, int))(a1 + 32))(a1: *(_DWORD *)(a1 + 40), a2: 8, a3: 1440);
    v4[9] = v5;
    if ( v5 != 0 )
    {
      v6 = (*(int (__cdecl **)(_DWORD, int, int))(a1 + 32))(a1: *(_DWORD *)(a1 + 40), a2: 1, a3);
      v4[10] = v6;
      if ( v6 != 0 )
      {
        v4[11] = a3 + v6;
        v4[14] = a2;
        *v4 = 0;
        inflate_blocks_reset(a1: v4, a2: a1, a3: nullptr);
        return (int)v4;
      }
      else
      {
        (*(void (__cdecl **)(_DWORD, _DWORD))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: v4[9]);
        (*(void (__cdecl **)(_DWORD, _DWORD *))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: v4);
        return 0;
      }
    }
    else
    {
      (*(void (__cdecl **)(_DWORD, _DWORD *))(a1 + 36))(a1: *(_DWORD *)(a1 + 40), a2: v4);
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001ED10
// Name: _inflate_blocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_blocks(_DWORD *a1, int *a2, int a3)
{
  unsigned int v4; // edx
  unsigned int v5; // ebp
  char *v6; // ecx
  unsigned int v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // edi
  unsigned int v10; // esi
  unsigned int v11; // eax
  int v12; // edx
  unsigned int v13; // ebp
  int v14; // ecx
  int v15; // eax
  unsigned __int8 *v16; // eax
  int v17; // edi
  int v18; // esi
  int v19; // edx
  unsigned int v20; // edi
  unsigned int v21; // ecx
  char *v22; // ecx
  char *v23; // edx
  unsigned int v24; // eax
  unsigned int v25; // esi
  int v26; // eax
  char *v27; // edx
  unsigned int v28; // esi
  int v29; // eax
  unsigned int v30; // eax
  unsigned int v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // edi
  unsigned int v34; // esi
  unsigned __int8 *v35; // eax
  int v36; // edx
  unsigned int v37; // eax
  unsigned int v38; // ecx
  int v39; // eax
  int *v40; // esi
  int v41; // eax
  unsigned int v42; // edi
  unsigned __int8 *v43; // eax
  char v44; // cl
  int v45; // eax
  unsigned int v46; // edx
  unsigned int v47; // ecx
  unsigned __int8 *v48; // eax
  unsigned int v49; // ecx
  char v50; // cl
  int v51; // edx
  int v52; // edx
  unsigned int v53; // ecx
  unsigned int v54; // edx
  char v55; // cl
  unsigned int v56; // edi
  unsigned int v57; // eax
  int v58; // ecx
  int v59; // eax
  unsigned int v60; // eax
  unsigned int v61; // eax
  int v62; // edx
  int v63; // eax
  unsigned __int8 *v64; // edi
  int v65; // edx
  int v66; // eax
  char *v67; // ecx
  unsigned __int8 *v68; // edi
  unsigned int v69; // edx
  unsigned int v70; // eax
  int v71; // eax
  int v72; // ebp
  int result; // eax
  int v74; // ebp
  unsigned __int8 **v75; // eax
  unsigned __int8 *v76; // edx
  unsigned __int8 *v77; // esi
  int v78; // ebp
  int v79; // ebp
  int v80; // ebp
  unsigned __int8 *v81; // edx
  unsigned __int8 *v82; // ebp
  unsigned __int8 *v83; // ebp
  int v84; // esi
  unsigned __int8 *v85; // esi
  int v86; // ebp
  unsigned __int8 *v87; // edi
  int v88; // edx
  int v89; // ecx
  unsigned __int8 *v90; // edx
  bool v91; // zf
  unsigned __int8 *v92; // edi
  int v93; // ecx
  unsigned __int8 *v94; // edi
  int v95; // ecx
  unsigned __int8 *v96; // edi
  char *v97; // ecx
  int v98; // edx
  unsigned __int8 *v99; // ebp
  unsigned __int8 *v100; // ebp
  unsigned __int8 *v101; // esi
  int v102; // [esp-1Ch] [ebp-60h]
  int v103; // [esp-14h] [ebp-58h]
  int v104; // [esp-8h] [ebp-4Ch]
  int v105; // [esp-8h] [ebp-4Ch]
  int v106; // [esp-4h] [ebp-48h]
  unsigned int v107; // [esp-4h] [ebp-48h]
  unsigned __int8 *v108; // [esp+10h] [ebp-34h]
  unsigned int v109; // [esp+14h] [ebp-30h]
  int v110; // [esp+18h] [ebp-2Ch] BYREF
  unsigned int v111; // [esp+1Ch] [ebp-28h]
  int v112; // [esp+20h] [ebp-24h] BYREF
  int v113; // [esp+24h] [ebp-20h] BYREF
  int v114; // [esp+28h] [ebp-1Ch] BYREF
  int v115; // [esp+2Ch] [ebp-18h] BYREF
  int v116; // [esp+30h] [ebp-14h] BYREF
  unsigned int v117; // [esp+34h] [ebp-10h]
  unsigned int v118; // [esp+38h] [ebp-Ch]
  int v119; // [esp+3Ch] [ebp-8h] BYREF
  int v120; // [esp+40h] [ebp-4h] BYREF
  char *v121; // [esp+48h] [ebp+4h]
  int v122; // [esp+50h] [ebp+Ch]

  v4 = a2[1];
  v5 = a1[7];
  v108 = (unsigned __int8 *)*a2;
  v6 = (char *)a1[13];
  v110 = a1[8];
  v7 = a1[12];
  v109 = v4;
  v121 = v6;
  if ( (unsigned int)v6 >= v7 )
    v8 = a1[11] - (_DWORD)v6;
  else
    v8 = v7 - (_DWORD)v6 - 1;
  v111 = v8;
  while ( 2 )
  {
    switch ( *a1 )
    {
      case 0:
        v9 = v108;
        v10 = v110;
        if ( v5 >= 3 )
          goto LABEL_10;
        v11 = v109;
        do
        {
          if ( v11 == 0 )
          {
            a1[8] = v10;
            a1[7] = v5;
            v72 = (int)&v9[a2[2] - *a2];
            a2[1] = 0;
            a2[2] = v72;
            *a2 = (int)v9;
            a1[13] = v121;
            return inflate_flush(a1, a2, a3);
          }
          --v11;
          a3 = 0;
          v12 = *v9 << v5;
          v5 += 8;
          v109 = v11;
          v10 |= v12;
          ++v9;
          v110 = v10;
          v108 = v9;
        }
        while ( v5 < 3 );
LABEL_10:
        a1[6] = v10 & 1;
        switch ( (unsigned __int8)(v10 & 7) >> 1 )
        {
          case 0:
            v13 = v5 - 3;
            *a1 = 1;
            v14 = v13 & 7;
            v5 = v13 - v14;
            v110 = v10 >> 3 >> v14;
            continue;
          case 1:
            inflate_trees_fixed(a1: &v116, a2: &v115, a3: &v114, a4: &v113);
            v15 = inflate_codes_new(a1: v116, a2: v115, a3: v114, a4: v113, a5: a2);
            a1[1] = v15;
            if ( v15 != 0 )
            {
              v110 = v10 >> 3;
              v5 -= 3;
              *a1 = 6;
              continue;
            }
            a1[8] = v10;
            a1[7] = v5;
            v74 = a2[2];
            a2[1] = v109;
            a2[2] = (int)&v9[v74 - *a2];
            *a2 = (int)v9;
            a1[13] = v121;
            result = inflate_flush(a1, a2, a3: -4);
            break;
          case 2:
            v110 = v10 >> 3;
            v5 -= 3;
            *a1 = 3;
            continue;
          case 3:
            v75 = (unsigned __int8 **)a2;
            *a1 = 9;
            a2[6] = (int)aInvalidBlockTy;
            a1[8] = v10 >> 3;
            a1[7] = v5 - 3;
            a2[1] = v109;
            v76 = &v9[-*a2];
            *a2 = (int)v9;
            v106 = -3;
            goto LABEL_129;
          default:
            continue;
        }
        return result;
      case 1:
        v16 = v108;
        v17 = v109;
        v18 = v110;
        if ( v5 >= 0x20 )
          goto LABEL_18;
        do
        {
          if ( v17 == 0 )
          {
            a1[8] = v18;
            a1[7] = v5;
            v77 = (unsigned __int8 *)*a2;
            v78 = a2[2];
            a2[1] = 0;
            *a2 = (int)v16;
            a2[2] = v16 - v77 + v78;
            a1[13] = v121;
            return inflate_flush(a1, a2, a3);
          }
          a3 = 0;
          --v17;
          v19 = *v16 << v5;
          v5 += 8;
          v109 = v17;
          v18 |= v19;
          v108 = ++v16;
        }
        while ( v5 < 0x20 );
LABEL_18:
        if ( (unsigned int)~v18 >> 16 != (unsigned __int16)v18 )
        {
          *a1 = 9;
          a2[6] = (int)aInvalidStoredB;
          a1[8] = v18;
          a1[7] = v5;
          v79 = (int)&v16[a2[2] - *a2];
          *a2 = (int)v16;
          a2[1] = v17;
          a2[2] = v79;
          a1[13] = v121;
          return inflate_flush(a1, a2, a3: -3);
        }
        v5 = 0;
        a1[1] = (unsigned __int16)v18;
        v110 = 0;
        if ( (_WORD)v18 != 0 )
        {
          *a1 = 2;
          continue;
        }
LABEL_45:
        *a1 = a1[6] != 0 ? 7 : 0;
        continue;
      case 2:
        v20 = v109;
        if ( v109 == 0 )
        {
          v75 = (unsigned __int8 **)a2;
          a1[8] = v110;
          a1[7] = v5;
          v80 = a2[2];
          v81 = &v108[-*a2];
          a2[1] = 0;
          v82 = &v81[v80];
          *a2 = (int)v108;
          v106 = a3;
          goto LABEL_130;
        }
        v21 = v111;
        if ( v111 == 0 )
        {
          v22 = (char *)a1[11];
          v23 = v121;
          if ( v121 != v22 )
            goto LABEL_29;
          v24 = a1[12];
          v25 = a1[10];
          if ( v24 == v25 )
            goto LABEL_29;
          v23 = (char *)a1[10];
          v121 = v23;
          v21 = v25 >= v24 ? (unsigned int)&v22[-v25] : v24 - v25 - 1;
          v111 = v21;
          if ( v21 == 0 )
          {
LABEL_29:
            a1[13] = v23;
            v26 = inflate_flush(a1, a2, a3);
            v27 = (char *)a1[13];
            v28 = a1[12];
            v122 = v26;
            v121 = v27;
            if ( (unsigned int)v27 >= v28 )
              v21 = a1[11] - (_DWORD)v27;
            else
              v21 = v28 - (_DWORD)v27 - 1;
            v29 = a1[11];
            v111 = v21;
            v112 = v29;
            if ( v27 == (char *)v29 )
            {
              v30 = a1[10];
              if ( v28 != v30 )
              {
                v27 = (char *)a1[10];
                v121 = v27;
                if ( v30 >= v28 )
                  v21 = v112 - v30;
                else
                  v21 = v28 - v30 - 1;
                v111 = v21;
              }
            }
            if ( v21 == 0 )
            {
              a1[8] = v110;
              a1[7] = v5;
              v83 = (unsigned __int8 *)*a2;
              v84 = a2[2];
              a2[1] = v109;
              *a2 = (int)v108;
              a2[2] = v108 - v83 + v84;
              a1[13] = v27;
              return inflate_flush(a1, a2, a3: v122);
            }
            v20 = v109;
          }
        }
        v31 = a1[1];
        a3 = 0;
        if ( v31 > v20 )
          v31 = v20;
        if ( v31 > v21 )
          v31 = v21;
        qmemcpy(v121, v108, v31);
        v108 += v31;
        v32 = a1[1] - v31;
        v109 -= v31;
        v121 += v31;
        v111 -= v31;
        a1[1] = v32;
        if ( v32 == 0 )
          goto LABEL_45;
        continue;
      case 3:
        v33 = v110;
        if ( v5 >= 0xE )
          goto LABEL_50;
        v34 = v109;
        v35 = v108;
        do
        {
          if ( v34 == 0 )
          {
            v75 = (unsigned __int8 **)a2;
            a1[8] = v33;
            a1[7] = v5;
            v85 = (unsigned __int8 *)*a2;
            v86 = a2[2];
            a2[1] = 0;
            *a2 = (int)v108;
            v82 = (unsigned __int8 *)(v108 - v85 + v86);
            v106 = a3;
            goto LABEL_130;
          }
          --v34;
          a3 = 0;
          v36 = *v35 << v5;
          v5 += 8;
          v109 = v34;
          v33 |= v36;
          v108 = ++v35;
        }
        while ( v5 < 0xE );
LABEL_50:
        v37 = v33 & 0x3FFF;
        a1[1] = v37;
        v38 = v33 & 0x1F;
        if ( v38 > 0x1D || (unsigned int)(v39 = (v37 >> 5) & 0x1F) > 0x1D )
        {
          v75 = (unsigned __int8 **)a2;
          *a1 = 9;
          v106 = -3;
          a2[6] = (int)aTooManyLengthO;
          a1[8] = v33;
LABEL_127:
          a1[7] = v5;
          v75[1] = (unsigned __int8 *)v109;
LABEL_128:
          v101 = *v75;
          *v75 = v108;
          v76 = (unsigned __int8 *)(v108 - v101);
LABEL_129:
          v82 = &v75[2][(_DWORD)v76];
LABEL_130:
          v75[2] = v82;
          a1[13] = v121;
          return inflate_flush(a1, a2: v75, a3: v106);
        }
        v40 = a2;
        v41 = ((int (__cdecl *)(int, unsigned int, int))a2[8])(a1: a2[10], a2: v39 + v38 + 258, a3: 4);
        a1[3] = v41;
        if ( v41 == 0 )
        {
          a1[8] = v33;
          a1[7] = v5;
          v87 = (unsigned __int8 *)*a2;
          v88 = a2[2];
          a2[1] = v109;
          *a2 = (int)v108;
          a2[2] = v108 - v87 + v88;
          a1[13] = v121;
          return inflate_flush(a1, a2, a3: -4);
        }
        v42 = v33 >> 14;
        v5 -= 14;
        a1[2] = 0;
        *a1 = 4;
LABEL_55:
        if ( a1[2] < (unsigned int)((a1[1] >> 10) + 4) )
        {
          while ( v5 >= 3 )
          {
LABEL_60:
            v45 = v42 & 7;
            v5 -= 3;
            v42 >>= 3;
            *(_DWORD *)(a1[3] + 4 * dword_1003F430[a1[2]]) = v45;
            v46 = a1[2] + 1;
            a1[2] = v46;
            if ( v46 >= (a1[1] >> 10) + 4 )
              goto LABEL_61;
          }
          v43 = v108;
          while ( v109 != 0 )
          {
            --v109;
            v44 = v5;
            v5 += 8;
            a3 = 0;
            v42 |= *v43++ << v44;
            v108 = v43;
            if ( v5 >= 3 )
              goto LABEL_60;
          }
          goto LABEL_108;
        }
LABEL_61:
        if ( a1[2] < 0x13u )
        {
          do
          {
            *(_DWORD *)(a1[3] + 4 * dword_1003F430[a1[2]]) = 0;
            v47 = a1[2] + 1;
            a1[2] = v47;
          }
          while ( v47 < 0x13 );
        }
        v104 = a1[9];
        v103 = a1[3];
        a1[4] = 7;
        v111 = inflate_trees_bits(a1: v103, a2: a1 + 4, a3: a1 + 5, a4: v104, a5: v40);
        if ( v111 != 0 )
        {
          ((void (__cdecl *)(int, _DWORD))v40[9])(a1: v40[10], a2: a1[3]);
          v91 = v111 == -3;
LABEL_113:
          if ( v91 )
            *a1 = 9;
          a1[8] = v42;
          a1[7] = v5;
          v94 = (unsigned __int8 *)*v40;
          v40[1] = v109;
          v95 = v40[2];
          *v40 = (int)v108;
          v40[2] = v108 - v94 + v95;
          v107 = v111;
          a1[13] = v121;
          return inflate_flush(a1, a2: v40, a3: v107);
        }
        a1[2] = 0;
        *a1 = 5;
LABEL_66:
        v48 = v108;
        if ( a1[2] < ((a1[1] >> 5) & 0x1F) + (a1[1] & 0x1Fu) + 258 )
        {
          while ( 1 )
          {
            v49 = a1[4];
            if ( v5 < v49 )
              break;
LABEL_72:
            v52 = a1[5] + 8 * (v42 & inflate_mask[v49]);
            v53 = *(unsigned __int8 *)(v52 + 1);
            v54 = *(_DWORD *)(v52 + 4);
            v111 = v53;
            v118 = v54;
            if ( v54 >= 0x10 )
            {
              if ( v54 == 18 )
                v112 = 7;
              else
                v112 = v54 - 14;
              v110 = 8 * (v54 == 18) + 3;
              v117 = v112 + v111;
              if ( v5 < v112 + v111 )
              {
                while ( v109 != 0 )
                {
                  v55 = v5;
                  v5 += 8;
                  --v109;
                  a3 = 0;
                  v42 |= *v48++ << v55;
                  v108 = v48;
                  if ( v5 >= v117 )
                    goto LABEL_80;
                }
                goto LABEL_108;
              }
LABEL_80:
              v56 = v42 >> v111;
              v57 = a1[1];
              v110 += v56 & inflate_mask[v112];
              v42 = v56 >> v112;
              v5 -= v111 + v112;
              v58 = a1[2];
              if ( v58 + v110 > ((v57 >> 5) & 0x1F) + (v57 & 0x1F) + 258 )
                goto LABEL_111;
              if ( v118 == 16 )
              {
                if ( v58 == 0 )
                {
LABEL_111:
                  ((void (__cdecl *)(int, _DWORD))v40[9])(a1: v40[10], a2: a1[3]);
                  *a1 = 9;
                  v40[6] = (int)aInvalidBitLeng;
                  a1[8] = v42;
                  a1[7] = v5;
                  v92 = (unsigned __int8 *)*v40;
                  v40[1] = v109;
                  v93 = v40[2];
                  *v40 = (int)v108;
                  v40[2] = v108 - v92 + v93;
                  a1[13] = v121;
                  return inflate_flush(a1, a2: v40, a3: -3);
                }
                v59 = *(_DWORD *)(a1[3] + 4 * v58 - 4);
              }
              else
              {
                v59 = 0;
              }
              do
              {
                ++v58;
                *(_DWORD *)(a1[3] + 4 * v58 - 4) = v59;
                --v110;
              }
              while ( v110 != 0 );
              a1[2] = v58;
            }
            else
            {
              v5 -= v53;
              v42 >>= v53;
              *(_DWORD *)(a1[3] + 4 * a1[2]++) = v54;
            }
            if ( a1[2] >= ((a1[1] >> 5) & 0x1F) + (a1[1] & 0x1Fu) + 258 )
              goto LABEL_88;
            v48 = v108;
          }
          while ( v109 != 0 )
          {
            v50 = v5;
            v5 += 8;
            --v109;
            a3 = 0;
            v51 = *v48 << v50;
            v49 = a1[4];
            v42 |= v51;
            v108 = ++v48;
            if ( v5 >= v49 )
              goto LABEL_72;
          }
LABEL_108:
          a1[8] = v42;
          a1[7] = v5;
          v89 = v40[2];
          v90 = &v108[-*v40];
          *v40 = (int)v108;
          v40[2] = (int)&v90[v89];
          v40[1] = 0;
          a1[13] = v121;
          return inflate_flush(a1, a2: v40, a3);
        }
LABEL_88:
        v60 = a1[1];
        v105 = a1[9];
        v102 = a1[3];
        a1[5] = 0;
        v110 = 9;
        v112 = 6;
        v61 = inflate_trees_dynamic(
                a1: (v60 & 0x1F) + 257,
                a2: ((v60 >> 5) & 0x1F) + 1,
                a3: v102,
                a4: &v110,
                a5: &v112,
                a6: &v120,
                a7: &v119,
                a8: v105,
                a9: v40);
        v62 = a1[3];
        v111 = v61;
        ((void (__cdecl *)(int, int))v40[9])(a1: v40[10], a2: v62);
        if ( v111 != 0 )
        {
          v91 = v111 == -3;
          goto LABEL_113;
        }
        v63 = inflate_codes_new(a1: v110, a2: v112, a3: v120, a4: v119, a5: v40);
        if ( v63 == 0 )
        {
          a1[8] = v42;
          a1[7] = v5;
          v96 = (unsigned __int8 *)*v40;
          v40[1] = v109;
          v40[2] += v108 - v96;
          *v40 = (int)v108;
          a1[13] = v121;
          return inflate_flush(a1, a2: v40, a3: -4);
        }
        a1[1] = v63;
        *a1 = 6;
LABEL_92:
        a1[8] = v42;
        a1[7] = v5;
        v64 = (unsigned __int8 *)*v40;
        v40[1] = v109;
        v65 = v40[2];
        *v40 = (int)v108;
        v40[2] = v108 - v64 + v65;
        a1[13] = v121;
        v66 = inflate_codes(a1, a2: v40, a3);
        if ( v66 != 1 )
          return inflate_flush(a1, a2: v40, a3: v66);
        a3 = 0;
        inflate_codes_free(a1: a1[1], a2: v40);
        v67 = (char *)a1[13];
        v68 = (unsigned __int8 *)*v40;
        v69 = v40[1];
        v5 = a1[7];
        v110 = a1[8];
        v70 = a1[12];
        v108 = v68;
        v109 = v69;
        v121 = v67;
        if ( (unsigned int)v67 >= v70 )
          v71 = a1[11] - (_DWORD)v67;
        else
          v71 = v70 - (_DWORD)v67 - 1;
        v111 = v71;
        if ( a1[6] == 0 )
        {
          *a1 = 0;
          continue;
        }
        *a1 = 7;
LABEL_119:
        a1[13] = v67;
        v66 = inflate_flush(a1, a2: v40, a3);
        v97 = (char *)a1[13];
        if ( (char *)a1[12] != v97 )
        {
          v98 = v110;
          a1[7] = v5;
          a1[8] = v98;
          v99 = (unsigned __int8 *)*v40;
          v40[1] = v109;
          *v40 = (int)v68;
          v40[2] += v68 - v99;
          a1[13] = v97;
          return inflate_flush(a1, a2: v40, a3: v66);
        }
        *a1 = 8;
LABEL_124:
        a1[8] = v110;
        a1[7] = v5;
        v100 = (unsigned __int8 *)*v40;
        v40[1] = v109;
        v40[2] += v68 - v100;
        *v40 = (int)v68;
        a1[13] = v97;
        return inflate_flush(a1, a2: v40, a3: 1);
      case 4:
        v42 = v110;
        v40 = a2;
        goto LABEL_55;
      case 5:
        v42 = v110;
        v40 = a2;
        goto LABEL_66;
      case 6:
        v42 = v110;
        v40 = a2;
        goto LABEL_92;
      case 7:
        v67 = v121;
        v68 = v108;
        v40 = a2;
        goto LABEL_119;
      case 8:
        v97 = v121;
        v68 = v108;
        v40 = a2;
        goto LABEL_124;
      case 9:
        v75 = (unsigned __int8 **)a2;
        a1[8] = v110;
        a1[7] = v5;
        a2[1] = v109;
        v106 = -3;
        goto LABEL_128;
      default:
        v75 = (unsigned __int8 **)a2;
        a1[8] = v110;
        v106 = -2;
        goto LABEL_127;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F960
// Name: _inflate_blocks_free
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_blocks_free(_DWORD *a1, int a2)
{
  inflate_blocks_reset(a1, a2, a3: nullptr);
  (*(void (__cdecl **)(_DWORD, _DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1[10]);
  (*(void (__cdecl **)(_DWORD, _DWORD))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1[9]);
  (*(void (__cdecl **)(_DWORD, _DWORD *))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001F9A0
// Name: _inflate_codes_new
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_codes_new(char a1, char a2, int a3, int a4, int a5)
{
  int result; // eax

  result = (*(int (__cdecl **)(_DWORD, int, int))(a5 + 32))(a1: *(_DWORD *)(a5 + 40), a2: 1, a3: 28);
  if ( result != 0 )
  {
    *(_BYTE *)(result + 16) = a1;
    *(_BYTE *)(result + 17) = a2;
    *(_DWORD *)result = 0;
    *(_DWORD *)(result + 20) = a3;
    *(_DWORD *)(result + 24) = a4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001F9E0
// Name: _inflate_codes
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_codes(_DWORD *a1, unsigned __int8 **a2, int a3)
{
  _DWORD *v5; // eax
  unsigned __int8 *v6; // ebp
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  _BYTE *v9; // edx
  int v10; // ecx
  unsigned __int8 *v11; // ebx
  unsigned __int8 *v12; // ecx
  int v13; // eax
  unsigned int v14; // ecx
  int v15; // ecx
  bool v16; // zf
  int v17; // ecx
  unsigned int v18; // eax
  char v19; // cl
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  unsigned int v24; // eax
  char v25; // cl
  int v26; // ecx
  int v27; // ecx
  unsigned int v28; // eax
  char v29; // cl
  int v30; // ecx
  int v31; // ecx
  int v32; // ecx
  unsigned int v33; // eax
  char v34; // cl
  int v35; // ecx
  unsigned int v36; // eax
  unsigned int v37; // eax
  unsigned int v38; // ecx
  int v39; // eax
  int v40; // eax
  unsigned int v41; // eax
  int v42; // ecx
  unsigned int v43; // ecx
  int v44; // eax
  int v45; // ecx
  unsigned int v46; // eax
  unsigned int v47; // ecx
  int v48; // eax
  int v49; // eax
  unsigned int v50; // eax
  int v51; // ecx
  unsigned int v52; // ecx
  int v53; // eax
  unsigned __int8 *v54; // eax
  unsigned __int8 *v55; // ecx
  unsigned __int8 *v57; // ebx
  int v58; // eax
  unsigned __int8 *v59; // ebx
  unsigned __int8 *v60; // ebx
  unsigned __int8 *v61; // ebx
  int v62; // [esp-4h] [ebp-24h]
  _DWORD *v63; // [esp+10h] [ebp-10h]
  unsigned int v64; // [esp+14h] [ebp-Ch]
  unsigned int i; // [esp+18h] [ebp-8h]
  unsigned __int8 *v66; // [esp+18h] [ebp-8h]
  unsigned int j; // [esp+18h] [ebp-8h]
  unsigned int v68; // [esp+18h] [ebp-8h]
  unsigned int k; // [esp+18h] [ebp-8h]
  _BYTE *v70; // [esp+1Ch] [ebp-4h]
  unsigned int v71; // [esp+24h] [ebp+4h]
  unsigned int v72; // [esp+28h] [ebp+8h]
  int v73; // [esp+2Ch] [ebp+Ch]

  v5 = (_DWORD *)a1[1];
  v6 = *a2;
  v7 = a1[7];
  v72 = (unsigned int)a2[1];
  v8 = a1[12];
  v71 = a1[8];
  v9 = (_BYTE *)a1[13];
  v63 = v5;
  if ( (unsigned int)v9 >= v8 )
    v10 = a1[11] - (_DWORD)v9;
  else
    v10 = v8 - (_DWORD)v9 - 1;
LABEL_4:
  v64 = v10;
  while ( 2 )
  {
    switch ( *v5 )
    {
      case 0:
        if ( v64 >= 0x102 && v72 >= 0xA )
        {
          a1[8] = v71;
          a1[7] = v7;
          v11 = *a2;
          a2[1] = (unsigned __int8 *)v72;
          v12 = a2[2];
          *a2 = v6;
          a2[2] = &v12[v6 - v11];
          a1[13] = v9;
          v13 = inflate_fast(
                  a1: *((unsigned __int8 *)v63 + 16),
                  a2: *((unsigned __int8 *)v63 + 17),
                  a3: v63[5],
                  a4: v63[6],
                  a5: a1,
                  a6: a2);
          v6 = *a2;
          v7 = a1[7];
          v72 = (unsigned int)a2[1];
          v14 = a1[12];
          v71 = a1[8];
          v9 = (_BYTE *)a1[13];
          a3 = v13;
          v15 = (unsigned int)v9 >= v14 ? a1[11] - (_DWORD)v9 : v14 - (_DWORD)v9 - 1;
          v64 = v15;
          if ( v13 != 0 )
          {
            v16 = v13 == 1;
            v5 = v63;
            *v63 = 2 * !v16 + 7;
            continue;
          }
        }
        v5 = v63;
        v17 = *((unsigned __int8 *)v63 + 16);
        *v63 = 1;
        v63[3] = v17;
        v63[2] = v63[5];
        goto LABEL_14;
      case 1:
LABEL_14:
        v18 = v5[3];
        for ( i = v18; v7 < i; v71 = v20 )
        {
          if ( v72 == 0 )
            goto LABEL_86;
          v19 = v7;
          --v72;
          v7 += 8;
          a3 = 0;
          v20 = (*v6 << v19) | v71;
          v18 = i;
          ++v6;
        }
        v66 = (unsigned __int8 *)(v63[2] + 8 * (v71 & inflate_mask[v18]));
        v21 = v66[1];
        v71 >>= v21;
        v7 -= v21;
        v22 = *v66;
        if ( *v66 != 0 )
        {
          if ( (v22 & 0x10) != 0 )
          {
            v5 = v63;
            v63[2] = v22 & 0xF;
            v23 = *((_DWORD *)v66 + 1);
            *v63 = 2;
            v63[1] = v23;
          }
          else
          {
            if ( (v22 & 0x40) == 0 )
              goto LABEL_22;
            v5 = v63;
            if ( (v22 & 0x20) == 0 )
            {
              *v63 = 9;
              a2[6] = (unsigned __int8 *)aInvalidLiteral;
              v62 = -3;
LABEL_96:
              a1[7] = v7;
              a1[8] = v71;
              v61 = *a2;
              a2[1] = (unsigned __int8 *)v72;
              a2[2] += v6 - v61;
LABEL_97:
              *a2 = v6;
              a1[13] = v9;
              return inflate_flush(a1, a2, a3: v62);
            }
            *v63 = 7;
          }
        }
        else
        {
          v5 = v63;
          v63[2] = *((_DWORD *)v66 + 1);
          *v63 = 6;
        }
        continue;
      case 2:
        v24 = v5[2];
        for ( j = v24; v7 < j; v71 = v26 )
        {
          if ( v72 == 0 )
            goto LABEL_86;
          v25 = v7;
          --v72;
          v7 += 8;
          a3 = 0;
          v26 = (*v6 << v25) | v71;
          v24 = j;
          ++v6;
        }
        v63[1] += v71 & inflate_mask[v24];
        v71 >>= j;
        v7 -= j;
        v5 = v63;
        v27 = *((unsigned __int8 *)v63 + 17);
        *v63 = 3;
        v63[3] = v27;
        v63[2] = v63[6];
LABEL_29:
        v28 = v5[3];
        v68 = v28;
        if ( v7 >= v28 )
        {
LABEL_32:
          v66 = (unsigned __int8 *)(v63[2] + 8 * (v71 & inflate_mask[v28]));
          v31 = v66[1];
          v7 -= v31;
          v71 >>= v31;
          v22 = *v66;
          if ( (v22 & 0x10) != 0 )
          {
            v5 = v63;
            v63[2] = v22 & 0xF;
            v32 = *((_DWORD *)v66 + 1);
            *v63 = 4;
            v63[3] = v32;
          }
          else
          {
            if ( (v22 & 0x40) != 0 )
            {
              v62 = -3;
              *v63 = 9;
              a2[6] = (unsigned __int8 *)aInvalidDistanc;
              goto LABEL_96;
            }
LABEL_22:
            v63[3] = v22;
            v5 = v63;
            v63[2] = &v66[8 * *((_DWORD *)v66 + 1)];
          }
          continue;
        }
        while ( v72 != 0 )
        {
          v29 = v7;
          --v72;
          v7 += 8;
          a3 = 0;
          v30 = (*v6 << v29) | v71;
          v28 = v68;
          ++v6;
          v71 = v30;
          if ( v7 >= v68 )
            goto LABEL_32;
        }
LABEL_86:
        a1[7] = v7;
        a1[8] = v71;
        v54 = a2[2];
        v55 = (unsigned __int8 *)(v6 - *a2);
        a2[1] = nullptr;
        *a2 = v6;
        a2[2] = &v54[(_DWORD)v55];
        a1[13] = v9;
        return inflate_flush(a1, a2, a3);
      case 3:
        goto LABEL_29;
      case 4:
        v33 = v5[2];
        for ( k = v33; v7 < k; v71 = v35 )
        {
          if ( v72 == 0 )
            goto LABEL_86;
          v34 = v7;
          --v72;
          v7 += 8;
          a3 = 0;
          v35 = (*v6 << v34) | v71;
          v33 = k;
          ++v6;
        }
        v63[3] += v71 & inflate_mask[v33];
        v71 >>= k;
        v7 -= k;
        *v63 = 5;
LABEL_40:
        v36 = v63[3];
        if ( (unsigned int)&v9[-a1[10]] >= v36 )
          v70 = &v9[-v36];
        else
          v70 = &v9[a1[11] - a1[10] - v63[3]];
        v5 = v63;
        if ( v63[1] != 0 )
        {
          do
          {
            if ( v64 == 0 )
            {
              if ( v9 != (_BYTE *)a1[11]
                || (v37 = a1[12], v38 = a1[10], v37 == v38)
                || ((v9 = (_BYTE *)a1[10], v38 >= v37) ? (v39 = a1[11] - v38) : (v39 = v37 - v38 - 1),
                    v64 = v39,
                    v39 == 0) )
              {
                a1[13] = v9;
                v40 = inflate_flush(a1, a2, a3);
                v9 = (_BYTE *)a1[13];
                v73 = v40;
                v41 = a1[12];
                if ( (unsigned int)v9 >= v41 )
                  v42 = a1[11] - (_DWORD)v9;
                else
                  v42 = v41 - (_DWORD)v9 - 1;
                v64 = v42;
                if ( v9 == (_BYTE *)a1[11] )
                {
                  v43 = a1[10];
                  if ( v41 != v43 )
                  {
                    v9 = (_BYTE *)a1[10];
                    if ( v43 >= v41 )
                      v44 = a1[11] - v43;
                    else
                      v44 = v41 - v43 - 1;
                    v64 = v44;
                  }
                }
                if ( v64 == 0 )
                {
LABEL_87:
                  a1[8] = v71;
                  a1[7] = v7;
                  v57 = *a2;
                  a2[1] = (unsigned __int8 *)v72;
                  a2[2] += v6 - v57;
                  v62 = v73;
                  goto LABEL_97;
                }
              }
              v5 = v63;
            }
            ++v9;
            a3 = 0;
            *(v9 - 1) = *v70++;
            --v64;
            if ( v70 == (_BYTE *)a1[11] )
              v70 = (_BYTE *)a1[10];
            v45 = v5[1] - 1;
            v5[1] = v45;
          }
          while ( v45 != 0 );
        }
        *v5 = 0;
        continue;
      case 5:
        goto LABEL_40;
      case 6:
        if ( v64 != 0 )
          goto LABEL_84;
        if ( v9 != (_BYTE *)a1[11]
          || (v46 = a1[12], v47 = a1[10], v46 == v47)
          || ((v9 = (_BYTE *)a1[10], v47 >= v46) ? (v48 = a1[11] - v47) : (v48 = v46 - v47 - 1), v64 = v48, v48 == 0) )
        {
          a1[13] = v9;
          v49 = inflate_flush(a1, a2, a3);
          v9 = (_BYTE *)a1[13];
          v73 = v49;
          v50 = a1[12];
          if ( (unsigned int)v9 >= v50 )
            v51 = a1[11] - (_DWORD)v9;
          else
            v51 = v50 - (_DWORD)v9 - 1;
          v64 = v51;
          if ( v9 == (_BYTE *)a1[11] )
          {
            v52 = a1[10];
            if ( v50 != v52 )
            {
              v9 = (_BYTE *)a1[10];
              if ( v52 >= v50 )
                v53 = a1[11] - v52;
              else
                v53 = v50 - v52 - 1;
              v64 = v53;
            }
          }
          if ( v64 == 0 )
            goto LABEL_87;
        }
        v5 = v63;
LABEL_84:
        a3 = 0;
        *v9++ = *((_BYTE *)v5 + 8);
        v10 = v64 - 1;
        *v5 = 0;
        goto LABEL_4;
      case 7:
        if ( v7 > 7 )
        {
          v7 -= 8;
          --v6;
          ++v72;
        }
        a1[13] = v9;
        v58 = inflate_flush(a1, a2, a3);
        v9 = (_BYTE *)a1[13];
        if ( (_BYTE *)a1[12] != v9 )
        {
          a1[7] = v7;
          a1[8] = v71;
          v59 = *a2;
          a2[1] = (unsigned __int8 *)v72;
          v62 = v58;
          a2[2] += v6 - v59;
          goto LABEL_97;
        }
        *v63 = 8;
LABEL_93:
        v62 = 1;
        goto LABEL_96;
      case 8:
        goto LABEL_93;
      case 9:
        a1[8] = v71;
        a1[7] = v7;
        v60 = *a2;
        a2[1] = (unsigned __int8 *)v72;
        v62 = -3;
        a2[2] += v6 - v60;
        goto LABEL_97;
      default:
        v62 = -2;
        goto LABEL_96;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100200E0
// Name: _inflate_codes_free
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_codes_free(int a1, int a2)
{
  return (*(int (__cdecl **)(_DWORD, int))(a2 + 36))(a1: *(_DWORD *)(a2 + 40), a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10020100
// Name: _inflate_trees_bits
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_trees_bits(int a1, _DWORD *a2, int a3, int a4, int a5)
{
  int v5; // ebx
  int v7; // eax
  int v8; // esi
  int v9; // [esp-10h] [ebp-1Ch]
  int v10; // [esp+8h] [ebp-4h] BYREF

  v10 = 0;
  v5 = (*(int (__cdecl **)(_DWORD, int, int))(a5 + 32))(a1: *(_DWORD *)(a5 + 40), a2: 19, a3: 4);
  if ( v5 == 0 )
    return -4;
  v7 = sub_100201B0(a1, a2: 19, a3: 19, a4: 0, a5: 0, a6: a3, a7: a2, a8: a4, a9: &v10, a10: v5);
  v8 = v7;
  if ( v7 == -3 )
  {
    v9 = *(_DWORD *)(a5 + 40);
    *(_DWORD *)(a5 + 24) = aOversubscribed_0;
    (*(void (__cdecl **)(int, int))(a5 + 36))(a1: v9, a2: v5);
    return -3;
  }
  else
  {
    if ( v7 == -5 || *a2 == 0 )
    {
      *(_DWORD *)(a5 + 24) = aIncompleteDyna;
      v8 = -3;
    }
    (*(void (__cdecl **)(_DWORD, int))(a5 + 36))(a1: *(_DWORD *)(a5 + 40), a2: v5);
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100201B0
// Name: sub_100201B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_100201B0(
        int *a1,
        unsigned int a2,
        unsigned int a3,
        int a4,
        int a5,
        _DWORD *a6,
        unsigned int *a7,
        int a8,
        unsigned int *a9,
        unsigned int *a10)
{
  unsigned int v10; // ebp
  int *v11; // ecx
  unsigned int v12; // edx
  int v13; // eax
  unsigned int v15; // eax
  unsigned int v16; // ecx
  unsigned int i; // esi
  int j; // edx
  int v19; // edx
  int v20; // ecx
  int v21; // edx
  int v22; // ecx
  unsigned int v23; // esi
  int v24; // edi
  int *v25; // esi
  unsigned int v26; // edi
  int v27; // ecx
  int v28; // esi
  unsigned int v29; // edi
  signed int v30; // ecx
  int v31; // ebx
  unsigned int v32; // esi
  unsigned int m; // ecx
  unsigned int v34; // edx
  unsigned int v35; // ecx
  unsigned int v36; // eax
  _DWORD *v37; // ebp
  unsigned int v38; // eax
  unsigned int v39; // edi
  unsigned int v40; // eax
  unsigned int v41; // edx
  int v42; // ebp
  unsigned int v43; // eax
  int v44; // ecx
  int v45; // esi
  int v46; // edx
  unsigned int v47; // eax
  _DWORD *v48; // ecx
  unsigned int k; // eax
  int v50; // eax
  unsigned int v51; // [esp+10h] [ebp-FCh]
  signed int v52; // [esp+14h] [ebp-F8h]
  int v53; // [esp+18h] [ebp-F4h]
  int v54; // [esp+1Ch] [ebp-F0h]
  int *v55; // [esp+20h] [ebp-ECh]
  unsigned int *v56; // [esp+20h] [ebp-ECh]
  _DWORD *v57; // [esp+24h] [ebp-E8h]
  signed int v58; // [esp+28h] [ebp-E4h]
  unsigned int v59; // [esp+2Ch] [ebp-E0h]
  unsigned int v60; // [esp+30h] [ebp-DCh]
  int v61; // [esp+30h] [ebp-DCh]
  int v62; // [esp+34h] [ebp-D8h]
  unsigned int v63; // [esp+38h] [ebp-D4h]
  signed int v64; // [esp+3Ch] [ebp-D0h]
  char v65; // [esp+40h] [ebp-CCh]
  unsigned int v66; // [esp+44h] [ebp-C8h]
  _DWORD *v67; // [esp+48h] [ebp-C4h]
  int v68; // [esp+4Ch] [ebp-C0h]
  int v69; // [esp+50h] [ebp-BCh] BYREF
  _DWORD v70[15]; // [esp+54h] [ebp-B8h] BYREF
  int v71; // [esp+90h] [ebp-7Ch]
  _DWORD v72[15]; // [esp+94h] [ebp-78h]
  _DWORD v73[15]; // [esp+D0h] [ebp-3Ch] BYREF
  int v74; // [esp+114h] [ebp+8h]

  v10 = 0;
  v69 = 0;
  memset(v70, 0, sizeof(v70));
  v11 = a1;
  v12 = a2;
  do
  {
    v13 = *v11++;
    --v12;
    ++v70[v13 - 1];
  }
  while ( v12 != 0 );
  if ( v69 == a2 )
  {
    *a6 = 0;
    *a7 = 0;
    return 0;
  }
  v15 = *a7;
  v16 = 1;
  v51 = *a7;
  do
  {
    if ( v70[v16 - 1] != 0 )
      break;
    ++v16;
  }
  while ( v16 <= 0xF );
  v52 = v16;
  if ( v15 < v16 )
  {
    v51 = v16;
    v15 = v16;
  }
  for ( i = 15; i != 0; --i )
  {
    if ( v70[i - 1] != 0 )
      break;
  }
  v58 = i;
  if ( v15 > i )
  {
    v51 = i;
    v15 = i;
  }
  *a7 = v15;
  for ( j = 1 << v16; v16 < i; j = 2 * v19 )
  {
    v19 = j - v70[v16 - 1];
    if ( v19 < 0 )
      return -3;
    ++v16;
  }
  v60 = i;
  v20 = v70[i - 1];
  v21 = j - v20;
  v68 = v21;
  if ( v21 < 0 )
    return -3;
  v72[0] = 0;
  v70[i - 1] = v21 + v20;
  v22 = 0;
  v23 = i - 1;
  if ( v23 != 0 )
  {
    v24 = 0;
    do
    {
      v22 += v70[v24++];
      --v23;
      v72[v24] = v22;
    }
    while ( v23 != 0 );
  }
  v25 = a1;
  v26 = 0;
  do
  {
    v27 = *v25++;
    v55 = v25;
    if ( v27 != 0 )
    {
      v28 = v72[v27 - 1];
      a10[v28] = v26;
      v72[v27 - 1] = v28 + 1;
      v25 = v55;
    }
    ++v26;
  }
  while ( v26 < a2 );
  v29 = 0;
  v59 = 0;
  v74 = v72[v60 - 1];
  v56 = a10;
  v30 = v52;
  v31 = -v15;
  v71 = 0;
  v53 = -1;
  v73[0] = 0;
  v61 = 0;
  if ( v52 > v58 )
  {
LABEL_66:
    if ( v21 == 0 || v58 == 1 )
      return 0;
    return -5;
  }
  else
  {
    v32 = v63;
    v65 = v52 - 1;
    v57 = &v70[v52 - 1];
    while ( 1 )
    {
      v54 = *v57;
      if ( *v57 != 0 )
        break;
LABEL_64:
      v52 = ++v30;
      ++v57;
      ++v65;
      if ( v30 > v58 )
      {
        v21 = v68;
        goto LABEL_66;
      }
    }
    while ( 1 )
    {
      --v54;
      if ( v52 > (int)(v31 + v15) )
        break;
LABEL_47:
      if ( v56 < &a10[v74] )
      {
        v32 = *v56;
        if ( *v56 >= a3 )
        {
          v45 = 4 * (v32 - a3);
          LOBYTE(v62) = *(_BYTE *)(v45 + a5) + 80;
          v32 = *(_DWORD *)(v45 + a4);
        }
        else
        {
          LOBYTE(v62) = v32 < 0x100 ? 0 : 96;
        }
        ++v56;
      }
      else
      {
        LOBYTE(v62) = -64;
      }
      v46 = 1 << (v52 - v31);
      v47 = v10 >> v31;
      if ( v10 >> v31 < v29 )
      {
        v48 = (_DWORD *)(v61 + 8 * v47);
        do
        {
          v48[1] = v32;
          BYTE1(v62) = v52 - v31;
          *v48 = v62;
          v47 += v46;
          v48 += 2 * v46;
        }
        while ( v47 < v29 );
        v10 = v59;
      }
      for ( k = 1 << v65; (k & v10) != 0; k >>= 1 )
        v10 ^= k;
      v10 ^= k;
      v50 = v53;
      v59 = v10;
      if ( (v10 & ((1 << v31) - 1)) != v72[v53 - 1] )
      {
        do
        {
          --v50;
          v31 -= v51;
        }
        while ( (v10 & ((1 << v31) - 1)) != v72[v50 - 1] );
        v53 = v50;
      }
      v15 = v51;
      if ( v54 == 0 )
      {
        v30 = v52;
        goto LABEL_64;
      }
    }
    v64 = v31 + v15;
    for ( m = v31 - v15; ; m = v66 )
    {
      v31 += v15;
      ++v53;
      v34 = v58 - v31;
      v66 = v15 + m;
      v64 += v15;
      if ( v58 - v31 > v15 )
        v34 = v15;
      v35 = v52 - v31;
      v36 = 1 << (v52 - v31);
      if ( v36 > v54 + 1 )
      {
        v37 = v57;
        v38 = -1 - v54 + v36;
        if ( v35 < v34 && ++v35 < v34 )
        {
          do
          {
            v39 = v37[1];
            ++v37;
            v40 = 2 * v38;
            if ( v40 <= v39 )
              break;
            v38 = v40 - v39;
            ++v35;
          }
          while ( v35 < v34 );
        }
      }
      v29 = 1 << v35;
      v41 = *a9 + (1 << v35);
      if ( v41 > 0x5A0 )
        break;
      v42 = a8 + 8 * *a9;
      v61 = v42;
      v67 = &v73[v53];
      *v67 = v42;
      *a9 = v41;
      if ( v53 != 0 )
      {
        LOBYTE(v62) = v35;
        v72[v53 - 1] = v59;
        v43 = v59 >> v66;
        BYTE1(v62) = v51;
        v44 = *(v67 - 1);
        v32 = ((v42 - v44) >> 3) - (v59 >> v66);
        *(_DWORD *)(v44 + 8 * v43) = v62;
        *(_DWORD *)(v44 + 8 * v43 + 4) = v32;
      }
      else
      {
        *a6 = v42;
      }
      if ( v52 <= v64 )
      {
        v10 = v59;
        goto LABEL_47;
      }
      v15 = v51;
    }
    return -4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020660
// Name: _inflate_trees_dynamic
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_trees_dynamic(
        unsigned int a1,
        unsigned int a2,
        int *a3,
        unsigned int *a4,
        unsigned int *a5,
        _DWORD *a6,
        _DWORD *a7,
        int a8,
        int a9)
{
  unsigned int *v9; // edi
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // [esp-Ch] [ebp-20h]
  int v15; // [esp-8h] [ebp-1Ch]
  int v16; // [esp-8h] [ebp-1Ch]
  int v17; // [esp-8h] [ebp-1Ch]
  unsigned int v18; // [esp+10h] [ebp-4h] BYREF

  v14 = *(_DWORD *)(a9 + 40);
  v18 = 0;
  v9 = (unsigned int *)(*(int (__cdecl **)(int, int, int))(a9 + 32))(a1: v14, a2: 288, a3: 4);
  if ( v9 == nullptr )
    return -4;
  v11 = sub_100201B0(
          a1: a3,
          a2: a1,
          a3: 0x101u,
          a4: (int)&unk_1003F4B0,
          a5: (int)&unk_1003F530,
          a6,
          a7: a4,
          a8,
          a9: &v18,
          a10: v9);
  v12 = v11;
  if ( v11 != 0 )
  {
    if ( v11 == -3 )
    {
      v17 = *(_DWORD *)(a9 + 40);
      *(_DWORD *)(a9 + 24) = aOversubscribed_1;
      (*(void (__cdecl **)(int, unsigned int *))(a9 + 36))(a1: v17, a2: v9);
      return -3;
    }
    if ( v11 == -4 )
      goto LABEL_20;
LABEL_19:
    *(_DWORD *)(a9 + 24) = aIncompleteLite;
    v12 = -3;
    goto LABEL_20;
  }
  if ( *a4 == 0 )
    goto LABEL_19;
  v13 = sub_100201B0(
          a1: &a3[a1],
          a2,
          a3: 0,
          a4: (int)&unk_1003F5B0,
          a5: (int)&unk_1003F628,
          a6: a7,
          a7: a5,
          a8,
          a9: &v18,
          a10: v9);
  v12 = v13;
  if ( v13 != 0 )
  {
    switch ( v13 )
    {
      case -3:
        v15 = *(_DWORD *)(a9 + 40);
        *(_DWORD *)(a9 + 24) = aOversubscribed;
        (*(void (__cdecl **)(int, unsigned int *))(a9 + 36))(a1: v15, a2: v9);
        return -3;
      case -5:
        v16 = *(_DWORD *)(a9 + 40);
        *(_DWORD *)(a9 + 24) = aIncompleteDist;
        (*(void (__cdecl **)(int, unsigned int *))(a9 + 36))(a1: v16, a2: v9);
        return -3;
      case -4:
        goto LABEL_20;
      default:
        break;
    }
  }
  else if ( *a5 != 0 || a1 <= 0x101 )
  {
    (*(void (__cdecl **)(_DWORD, unsigned int *))(a9 + 36))(a1: *(_DWORD *)(a9 + 40), a2: v9);
    return 0;
  }
  *(_DWORD *)(a9 + 24) = aEmptyDistanceT;
  v12 = -3;
LABEL_20:
  (*(void (__cdecl **)(_DWORD, unsigned int *))(a9 + 36))(a1: *(_DWORD *)(a9 + 40), a2: v9);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x100207F0
// Name: _inflate_trees_fixed
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_trees_fixed(_DWORD *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  *a1 = dword_100460B0;
  *a2 = dword_100460B4;
  *a3 = &unk_100460B8;
  *a4 = &unk_100470B8;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10020820
// Name: _inflate_flush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_flush(_DWORD *a1, _DWORD *a2, int a3)
{
  unsigned int v3; // ebp
  char *v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // ebp
  unsigned int v7; // edx
  int (__cdecl *v8)(_DWORD, char *, unsigned int); // eax
  int v9; // eax
  char *v10; // eax
  char *v11; // ecx
  char *v12; // esi
  unsigned int v13; // ebp
  unsigned int v14; // eax
  unsigned int v15; // edx
  int (__cdecl *v16)(_DWORD, char *, unsigned int); // eax
  int v17; // eax
  char *v18; // edi
  char *v20; // [esp+10h] [ebp-4h]
  char *v21; // [esp+10h] [ebp-4h]

  v3 = a1[13];
  v4 = (char *)a1[12];
  v20 = (char *)a2[3];
  if ( (unsigned int)v4 > v3 )
    v3 = a1[11];
  v5 = a2[4];
  v6 = v3 - (_DWORD)v4;
  if ( v6 > v5 )
    v6 = a2[4];
  if ( v6 != 0 && a3 == -5 )
    a3 = 0;
  v7 = v6 + a2[5];
  a2[4] = v5 - v6;
  a2[5] = v7;
  v8 = (int (__cdecl *)(_DWORD, char *, unsigned int))a1[14];
  if ( v8 != nullptr )
  {
    v9 = v8(a1: a1[15], a2: v4, a3: v6);
    a1[15] = v9;
    a2[12] = v9;
  }
  qmemcpy(v20, v4, v6);
  v10 = &v4[v6];
  v11 = (char *)a1[11];
  v21 = &v20[v6];
  if ( &v4[v6] == v11 )
  {
    v12 = (char *)a1[10];
    if ( (char *)a1[13] == v11 )
      a1[13] = v12;
    v13 = a1[13] - (_DWORD)v12;
    v14 = a2[4];
    if ( v13 > v14 )
      v13 = a2[4];
    if ( v13 != 0 && a3 == -5 )
      a3 = 0;
    v15 = v13 + a2[5];
    a2[4] = v14 - v13;
    a2[5] = v15;
    v16 = (int (__cdecl *)(_DWORD, char *, unsigned int))a1[14];
    if ( v16 != nullptr )
    {
      v17 = v16(a1: a1[15], a2: v12, a3: v13);
      a1[15] = v17;
      a2[12] = v17;
    }
    qmemcpy(v21, v12, 4 * (v13 >> 2));
    v18 = &v21[4 * (v13 >> 2)];
    v21 += v13;
    v10 = &v12[v13];
    qmemcpy(v18, &v12[4 * (v13 >> 2)], v13 & 3);
  }
  a2[3] = v21;
  a1[12] = v10;
  return a3;
}

//------------------------------------------------------------------------------
// Address: 0x10020960
// Name: _inflate_fast
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_fast(int a1, int a2, int a3, unsigned __int8 *a4, _DWORD *a5, unsigned __int8 **a6)
{
  _BYTE *v6; // ebx
  unsigned int v7; // esi
  unsigned int v8; // edx
  unsigned __int8 **v9; // edi
  unsigned __int8 *v10; // ebp
  unsigned int v11; // eax
  int v12; // esi
  int v13; // ebx
  int v14; // esi
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx
  int v18; // ebx
  int v19; // esi
  unsigned __int8 *v20; // esi
  int i; // ecx
  int v22; // ecx
  int v23; // ebx
  unsigned int j; // ebx
  char v25; // cl
  unsigned int v26; // edi
  int v27; // esi
  _BYTE *v28; // ecx
  _BYTE *v29; // esi
  unsigned int v30; // edi
  unsigned int v31; // ecx
  unsigned __int8 *v32; // ebp
  unsigned __int8 *v33; // edx
  int v34; // ecx
  unsigned int v36; // ecx
  unsigned __int8 *v37; // ebp
  unsigned __int8 *v38; // edx
  unsigned __int8 *v39; // ecx
  unsigned int v40; // ecx
  unsigned __int8 *v41; // ebp
  unsigned __int8 *v42; // edx
  unsigned __int8 *v43; // ecx
  unsigned int v44; // [esp+10h] [ebp-14h]
  _BYTE *v45; // [esp+14h] [ebp-10h]
  unsigned int v46; // [esp+18h] [ebp-Ch]
  int v47; // [esp+1Ch] [ebp-8h]
  int v48; // [esp+20h] [ebp-4h]
  unsigned int v49; // [esp+28h] [ebp+4h]

  v6 = (_BYTE *)a5[13];
  v7 = a5[12];
  v8 = a5[8];
  v9 = a6;
  v45 = v6;
  v10 = *a6;
  v44 = (unsigned int)a6[1];
  v11 = a5[7];
  if ( (unsigned int)v6 >= v7 )
    v46 = a5[11] - (_DWORD)v6;
  else
    v46 = v7 - (_DWORD)v6 - 1;
  v47 = inflate_mask[a1];
  v48 = inflate_mask[a2];
  do
  {
    for ( ; v11 < 0x14; ++v10 )
    {
      --v44;
      v12 = *v10 << v11;
      v11 += 8;
      v8 |= v12;
    }
    v13 = *(unsigned __int8 *)(a3 + 8 * (v8 & v47));
    v14 = a3 + 8 * (v8 & v47);
    if ( *(_BYTE *)v14 != 0 )
    {
      while ( 1 )
      {
        v15 = *(unsigned __int8 *)(v14 + 1);
        v8 >>= v15;
        v11 -= v15;
        if ( (v13 & 0x10) != 0 )
          break;
        if ( (v13 & 0x40) != 0 )
        {
          if ( (v13 & 0x20) != 0 )
          {
            v36 = (unsigned int)&v9[1][-v44];
            if ( v11 >> 3 < v36 )
              v36 = v11 >> 3;
            v37 = &v10[-v36];
            a5[8] = v8;
            a5[7] = v11 - 8 * v36;
            v38 = *v9;
            v9[1] = (unsigned __int8 *)(v44 + v36);
            v39 = v9[2];
            *v9 = v37;
            v9[2] = &v39[v37 - v38];
            a5[13] = v45;
            return 1;
          }
          else
          {
            v9[6] = (unsigned __int8 *)aInvalidLiteral;
LABEL_40:
            v40 = (unsigned int)&v9[1][-v44];
            if ( v11 >> 3 < v40 )
              v40 = v11 >> 3;
            v41 = &v10[-v40];
            a5[8] = v8;
            a5[7] = v11 - 8 * v40;
            v42 = *v9;
            v9[1] = (unsigned __int8 *)(v44 + v40);
            v43 = v9[2];
            *v9 = v41;
            v9[2] = &v43[v41 - v42];
            a5[13] = v45;
            return -3;
          }
        }
        v16 = *(_DWORD *)(v14 + 4) + (v8 & inflate_mask[v13]);
        v13 = *(unsigned __int8 *)(v14 + 8 * v16);
        v14 += 8 * v16;
        if ( v13 == 0 )
          goto LABEL_11;
      }
      v18 = v13 & 0xF;
      v11 -= v18;
      v49 = *(_DWORD *)(v14 + 4) + (v8 & inflate_mask[v18]);
      for ( v8 >>= v18; v11 < 0xF; ++v10 )
      {
        --v44;
        v19 = *v10 << v11;
        v11 += 8;
        v8 |= v19;
      }
      v20 = a4;
      for ( i = v8 & v48; ; i = *((_DWORD *)v20 + 1) + (v8 & inflate_mask[v23]) )
      {
        v20 += 8 * i;
        v22 = v20[1];
        v23 = *v20;
        v8 >>= v22;
        v11 -= v22;
        if ( (v23 & 0x10) != 0 )
          break;
        if ( (v23 & 0x40) != 0 )
        {
          v9[6] = (unsigned __int8 *)aInvalidDistanc;
          goto LABEL_40;
        }
      }
      for ( j = v23 & 0xF; v11 < j; ++v10 )
      {
        --v44;
        v25 = v11;
        v11 += 8;
        v8 |= *v10 << v25;
      }
      v26 = *((_DWORD *)v20 + 1) + (v8 & inflate_mask[j]);
      v8 >>= j;
      v11 -= j;
      v46 -= v49;
      v27 = a5[10];
      v28 = v45;
      if ( (unsigned int)&v45[-v27] < v26 )
      {
        v30 = v26 + v27 - (_DWORD)v45;
        v29 = (_BYTE *)(a5[11] - v30);
        if ( v49 > v30 )
        {
          v49 -= v30;
          do
          {
            *v28++ = *v29++;
            --v30;
          }
          while ( v30 != 0 );
          v29 = (_BYTE *)a5[10];
        }
      }
      else
      {
        *v45 = v45[-v26];
        v28 = v45 + 2;
        v29 = &v45[-v26 + 2];
        v45[1] = v45[-v26 + 1];
        v49 -= 2;
      }
      do
      {
        *v28++ = *v29++;
        --v49;
      }
      while ( v49 != 0 );
      v9 = a6;
      v45 = v28;
    }
    else
    {
LABEL_11:
      v17 = *(unsigned __int8 *)(v14 + 1);
      v11 -= v17;
      v8 >>= v17;
      *v45++ = *(_BYTE *)(v14 + 4);
      --v46;
    }
  }
  while ( v46 >= 0x102 && v44 >= 0xA );
  v31 = (unsigned int)&v9[1][-v44];
  if ( v11 >> 3 < v31 )
    v31 = v11 >> 3;
  v32 = &v10[-v31];
  a5[8] = v8;
  a5[7] = v11 - 8 * v31;
  v33 = *v9;
  v9[1] = (unsigned __int8 *)(v44 + v31);
  v34 = (int)&v9[2][v32 - v33];
  *v9 = v32;
  v9[2] = (unsigned __int8 *)v34;
  a5[13] = v45;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10020CD0
// Name: _strchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strchr(char *string, unsigned __int8 chr)
{
  char *v2; // edx
  char v3; // cl
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax

  v2 = string;
  if ( ((unsigned __int8)string & 3) != 0 )
  {
    while ( 1 )
    {
      v3 = *v2++;
      if ( v3 == chr || v3 == 0 )
        break;
      if ( ((unsigned __int8)v2 & 3) == 0 )
        goto main_loop;
    }
  }
  else
  {
    do
    {
main_loop:
      while ( 1 )
      {
        v4 = ((chr << 8) | chr | (((chr << 8) | chr) << 16)) ^ *(_DWORD *)v2;
        v5 = *(_DWORD *)v2 + 2130640639;
        v6 = v5 ^ ~*(_DWORD *)v2;
        v2 += 4;
        if ( (((v4 + 2130640639) ^ ~v4) & 0x81010100) != 0 )
          break;
        v7 = v6 & 0x81010100;
        if ( v7 != 0 && ((v7 & 0x1010100) != 0 || (v5 & 0x80000000) == 0) )
          return;
      }
      v8 = *((_DWORD *)v2 - 1);
      if ( (_BYTE)v8 == chr )
        break;
      if ( (_BYTE)v8 == 0 )
        break;
      if ( BYTE1(v8) == chr )
        break;
      if ( BYTE1(v8) == 0 )
        break;
      v9 = HIWORD(v8);
      if ( (_BYTE)v9 == chr )
        break;
    }
    while ( (_BYTE)v9 != 0 && BYTE1(v9) != chr && BYTE1(v9) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020D90
// Name: _strstr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strstr(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 v2; // dl
  unsigned __int8 v4; // dh
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // esi
  char v7; // al
  unsigned __int8 v8; // ah
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al

  v2 = *str2;
  if ( *str2 != 0 )
  {
    v4 = str2[1];
    if ( v4 == 0 )
      JUMPOUT(0x10020CD6);
findnext:
    v5 = str2;
    v6 = str1 + 1;
    if ( *str1 == v2 )
      goto first_char_found;
    if ( *str1 != 0 )
    {
      while ( 2 )
      {
        v7 = *v6++;
        while ( v7 == v2 )
        {
first_char_found:
          v7 = *v6++;
          if ( v7 == v4 )
          {
            str1 = v6 - 1;
            while ( 1 )
            {
              v8 = v5[2];
              if ( v8 == 0 )
                break;
              v9 = *v6;
              v6 += 2;
              if ( v9 != v8 )
                goto findnext;
              v10 = v5[3];
              if ( v10 == 0 )
                break;
              v5 += 2;
              if ( v10 != *(v6 - 1) )
                goto findnext;
            }
            return;
          }
        }
        if ( v7 != 0 )
          continue;
        break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020EEA
// Name: IsRootUNCName
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall IsRootUNCName@<eax>(const char *path@<esi>)
{
  unsigned int v1; // eax
  char v2; // al
  char v3; // al
  const char *v4; // eax
  char v5; // cl
  char *v6; // eax
  char v7; // cl
  unsigned __int8 *v9; // [esp+0h] [ebp-4h]

  strlen(buf: v9);
  if ( v1 < 5 || *path != 92 && *path != 47 )
    return false;
  v2 = path[1];
  if ( v2 != 92 && v2 != 47 )
    return false;
  v3 = path[2];
  if ( v3 == 92 )
    return false;
  if ( v3 == 47 )
    return false;
  v4 = path + 3;
  v5 = path[3];
  if ( v5 == 0 )
    return false;
  do
  {
    if ( v5 == 92 )
      break;
    if ( v5 == 47 )
      break;
    v5 = *++v4;
  }
  while ( *v4 != 0 );
  if ( *v4 == 0 )
    return false;
  v6 = (char *)(v4 + 1);
  if ( *v6 == 0 )
    return false;
  v7 = *v6;
  do
  {
    if ( v7 == 92 )
      break;
    if ( v7 == 47 )
      break;
    v7 = *++v6;
  }
  while ( *v6 != 0 );
  return *v6 == 0 || v6[1] == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10020F64
// Name: _fullpath_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl fullpath_helper(char *buf, const char *path, unsigned int sz, char **pBuf)
{
  int v4; // esi
  char *v5; // edi
  int *v6; // eax
  char *result; // eax

  v4 = *_errno();
  *_errno() = 0;
  v5 = _fullpath(UserBuf: buf, path, maxlen: sz);
  v6 = _errno();
  if ( v5 != nullptr )
  {
    *v6 = v4;
    return v5;
  }
  else if ( *v6 == 34 )
  {
    *_errno() = v4;
    result = _fullpath(UserBuf: nullptr, path, maxlen: 0);
    *pBuf = result;
  }
  else
  {
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10020FC4
// Name: __stat64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _stat64i32(const char *name, _stat64i32 *buf)
{
  const char *dwHighDateTime; // esi
  unsigned int v3; // eax
  unsigned __int8 *v4; // eax
  const char *v5; // esi
  int v6; // eax
  __int64 v7; // rax
  int v8; // esi
  DWORD LastError; // eax
  int retval; // [esp+Ch] [ebp-26Ch]
  int drive; // [esp+10h] [ebp-268h]
  _FILETIME LocalFTime; // [esp+14h] [ebp-264h] BYREF
  int fd; // [esp+1Ch] [ebp-25Ch] BYREF
  _WIN32_FIND_DATAA findbuf; // [esp+20h] [ebp-258h] BYREF
  _SYSTEMTIME SystemTime; // [esp+160h] [ebp-118h] BYREF
  char pathbuf[260]; // [esp+170h] [ebp-108h] BYREF

  dwHighDateTime = name;
  LocalFTime.dwHighDateTime = (unsigned int)name;
  retval = 0;
  if ( name == nullptr || buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( _mbspbrk(string: (const unsigned __int8 *)name, charset: "?*") != nullptr )
  {
LABEL_5:
    *_errno() = 2;
    *__doserrno() = 2;
    return -1;
  }
  if ( name[1] == 58 )
  {
    if ( *name != 0 && name[2] == 0 )
      goto LABEL_5;
    v3 = _mbctolower(c: *name) - 96;
  }
  else
  {
    v3 = _getdrive();
  }
  drive = v3;
  fd = (int)FindFirstFileExA(
              lpFileName: name,
              fInfoLevelId: FindExInfoStandard,
              lpFindFileData: &findbuf,
              fSearchOp: FindExSearchNameMatch,
              lpSearchFilter: nullptr,
              dwAdditionalFlags: 0);
  if ( fd != -1 )
  {
    if ( (findbuf.dwFileAttributes & 0x400) != 0 && findbuf.dwReserved0 == -1610612724 )
    {
      fd = -1;
      if ( _sopen_s(pfh: &fd, path: name, oflag: 0, shflag: 64, pmode: 0) == 0 && fd != -1 )
      {
        v8 = _fstat64i32(fildes: fd, buf);
        _close(fh: fd);
        return v8;
      }
      goto LABEL_5;
    }
    if ( findbuf.ftLastWriteTime.dwLowDateTime != 0 || findbuf.ftLastWriteTime.dwHighDateTime != 0 )
    {
      if ( !FileTimeToLocalFileTime(lpFileTime: &findbuf.ftLastWriteTime, lpLocalFileTime: &LocalFTime)
        || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
      {
        goto LABEL_49;
      }
      buf->st_mtime = __loctotime64_t(
                        yr: SystemTime.wYear,
                        mo: SystemTime.wMonth,
                        dy: SystemTime.wDay,
                        hr: SystemTime.wHour,
                        mn: SystemTime.wMinute,
                        sc: SystemTime.wSecond,
                        dstflag: -1);
    }
    else
    {
      buf->st_mtime = 0;
    }
    if ( findbuf.ftLastAccessTime.dwLowDateTime != 0 || findbuf.ftLastAccessTime.dwHighDateTime != 0 )
    {
      if ( !FileTimeToLocalFileTime(lpFileTime: &findbuf.ftLastAccessTime, lpLocalFileTime: &LocalFTime)
        || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
      {
        goto LABEL_49;
      }
      buf->st_atime = __loctotime64_t(
                        yr: SystemTime.wYear,
                        mo: SystemTime.wMonth,
                        dy: SystemTime.wDay,
                        hr: SystemTime.wHour,
                        mn: SystemTime.wMinute,
                        sc: SystemTime.wSecond,
                        dstflag: -1);
    }
    else
    {
      buf->st_atime = buf->st_mtime;
    }
    if ( findbuf.ftCreationTime.dwLowDateTime == 0 && findbuf.ftCreationTime.dwHighDateTime == 0 )
    {
      buf->st_ctime = buf->st_mtime;
LABEL_45:
      FindClose(hFindFile: (HANDLE)fd);
      goto LABEL_46;
    }
    if ( FileTimeToLocalFileTime(lpFileTime: &findbuf.ftCreationTime, lpLocalFileTime: &LocalFTime)
      && FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
    {
      buf->st_ctime = __loctotime64_t(
                        yr: SystemTime.wYear,
                        mo: SystemTime.wMonth,
                        dy: SystemTime.wDay,
                        hr: SystemTime.wHour,
                        mn: SystemTime.wMinute,
                        sc: SystemTime.wSecond,
                        dstflag: -1);
      goto LABEL_45;
    }
LABEL_49:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    FindClose(hFindFile: (HANDLE)fd);
    return -1;
  }
  fd = 0;
  if ( _mbspbrk(string: (const unsigned __int8 *)name, charset: "./\\") == nullptr )
    goto LABEL_5;
  v4 = (unsigned __int8 *)fullpath_helper(buf: pathbuf, path: name, sz: 0x104u, pBuf: (char **)&fd);
  v5 = (const char *)v4;
  if ( v4 == nullptr || (strlen(buf: v4), v6 != 3) && !IsRootUNCName(path: v5) || GetDriveTypeA(lpRootPathName: v5) <= 1 )
  {
    if ( fd != 0 )
      free(pMem: (void *)fd);
    goto LABEL_5;
  }
  if ( fd != 0 )
    free(pMem: (void *)fd);
  findbuf.dwFileAttributes = 16;
  findbuf.nFileSizeHigh = 0;
  findbuf.nFileSizeLow = 0;
  findbuf.cFileName[0] = 0;
  v7 = __loctotime64_t(yr: 1980, mo: 1, dy: 1, hr: 0, mn: 0, sc: 0, dstflag: -1);
  dwHighDateTime = (const char *)LocalFTime.dwHighDateTime;
  buf->st_mtime = v7;
  buf->st_atime = v7;
  buf->st_ctime = v7;
LABEL_46:
  buf->st_mode = __dtoxmode(attr: findbuf.dwFileAttributes, name: dwHighDateTime);
  buf->st_nlink = 1;
  buf->st_size = findbuf.nFileSizeLow;
  if ( findbuf.nFileSizeHigh != 0 )
  {
    retval = -1;
    buf->st_size = 0;
  }
  buf->st_ino = 0;
  buf->st_gid = 0;
  buf->st_uid = 0;
  buf->st_dev = drive - 1;
  buf->st_rdev = drive - 1;
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1002141B
// Name: _setvbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl setvbuf(_iobuf *str, char *buffer, int type, unsigned int size)
{
  unsigned int v5; // edi
  int v6; // edi
  int flag; // ecx
  int v8; // ecx
  char *p_charbuf; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  if ( str == nullptr )
    goto LABEL_2;
  if ( type != 4 )
  {
    if ( type == 0 )
      goto LABEL_7;
    if ( type != 64 )
    {
LABEL_2:
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return -1;
    }
  }
  if ( type != 64 )
  {
    v5 = size;
    goto LABEL_10;
  }
LABEL_7:
  v5 = size;
  if ( size - 2 > 0x7FFFFFFD )
    goto LABEL_2;
LABEL_10:
  v6 = v5 & 0xFFFFFFFE;
  _lock_file(pf: str);
  _flush(str);
  _freebuf(stream: str);
  str->_flag &= 0xFFFFC2F3;
  flag = str->_flag;
  if ( (type & 4) != 0 )
  {
    v8 = flag | 4;
    p_charbuf = (char *)&str->_charbuf;
    v6 = 2;
LABEL_17:
    str->_flag = v8;
    goto LABEL_18;
  }
  p_charbuf = buffer;
  if ( buffer != nullptr )
  {
    v8 = flag | 0x500;
    goto LABEL_17;
  }
  p_charbuf = (char *)operator new(nSize: v6);
  if ( p_charbuf != nullptr )
  {
    str->_flag |= 0x408u;
LABEL_18:
    str->_bufsiz = v6;
    str->_base = p_charbuf;
    str->_ptr = p_charbuf;
    str->_cnt = 0;
    goto done;
  }
  ++_cflush;
  retval = -1;
done:
  _unlock_file(pf: str);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x10021511
// Name: ___iob_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl __iob_func()
{
  return _iob;
}

//------------------------------------------------------------------------------
// Address: 0x10021517
// Name: ___initstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __initstdio()
{
  unsigned int v0; // eax
  void **v1; // eax
  int v3; // edx
  _iobuf *v4; // ecx
  int v5; // edx
  _DWORD *v6; // ecx
  int osfhnd; // eax

  v0 = _nstream;
  if ( _nstream == 0 )
  {
    v0 = 512;
LABEL_5:
    _nstream = v0;
    goto LABEL_6;
  }
  if ( (int)_nstream < 20 )
  {
    v0 = 20;
    goto LABEL_5;
  }
LABEL_6:
  v1 = (void **)calloc(count: v0, size: 4u);
  __piob = v1;
  if ( v1 == nullptr )
  {
    _nstream = 20;
    v1 = (void **)calloc(count: 0x14u, size: 4u);
    __piob = v1;
    if ( v1 == nullptr )
      return 26;
  }
  v3 = 0;
  v4 = _iob;
  while ( 1 )
  {
    v1[v3++] = v4++;
    if ( (int)v4 >= (int)&__abort_behavior )
      break;
    v1 = __piob;
  }
  v5 = 0;
  v6 = &unk_10047320;
  do
  {
    osfhnd = __pioinfo[v5 >> 5][v5 & 0x1F].osfhnd;
    if ( osfhnd == -1 || osfhnd == -2 || osfhnd == 0 )
      *v6 = -2;
    v6 += 8;
    ++v5;
  }
  while ( (int)v6 < (int)dword_10047380 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100215C8
// Name: ___endstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __endstdio()
{
  _flushall();
  if ( _exitflag != 0 )
    _fcloseall();
  free(pMem: __piob);
}

//------------------------------------------------------------------------------
// Address: 0x100215E8
// Name: __lock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_10047570 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    _lock(locknum: pf - _iob + 16);
    pf->_flag |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021629
// Name: __lock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    _lock(locknum: i + 16);
    *((_DWORD *)s + 3) |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002165B
// Name: __unlock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_10047570 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    pf->_flag &= ~0x8000u;
    _unlock(locknum: pf - _iob + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021697
// Name: __unlock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    *((_DWORD *)s + 3) &= ~0x8000u;
    _unlock(locknum: i + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100216C6
// Name: __initp_heap_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_heap_handler(int (__cdecl *enull)(unsigned int))
{
  _pnhHeap = enull;
}

//------------------------------------------------------------------------------
// Address: 0x100216D5
// Name: __validdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _validdrive(unsigned int drive)
{
  BOOL result; // eax
  wchar_t drvstr[4]; // [esp+0h] [ebp-Ch] BYREF

  result = true;
  if ( drive != 0 )
  {
    drvstr[0] = drive + 64;
    wcscpy(&drvstr[1], L":\\");
    if ( GetDriveTypeW(lpRootPathName: drvstr) <= 1 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002172F
// Name: __getdcwd_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getdcwd_nolock(unsigned int drive, char *pnbuf, int maxlen)
{
  int v3; // ebx
  char *v5; // edi
  signed int FullPathNameA; // eax
  unsigned __int8 *v7; // eax
  signed int v8; // eax
  DWORD LastError; // eax
  char *pname; // [esp+4h] [ebp-8h] BYREF
  int count; // [esp+8h] [ebp-4h]

  v3 = drive;
  if ( drive != 0 )
  {
    if ( !_validdrive(drive) )
    {
      *__doserrno() = 15;
      *_errno() = 13;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  else
  {
    v3 = _getdrive();
  }
  v5 = pnbuf;
  if ( pnbuf != nullptr )
  {
    if ( maxlen <= 0 )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
    count = maxlen;
    *pnbuf = 0;
  }
  else
  {
    count = 0;
  }
  if ( v3 != 0 )
  {
    LOBYTE(drive) = v3 + 64;
    strcpy((char *)&drive + 1, ":.");
  }
  else
  {
    strcpy((char *)&drive, ".");
  }
  FullPathNameA = GetFullPathNameA(lpFileName: (LPCSTR)&drive, nBufferLength: count, lpBuffer: v5, lpFilePart: &pname);
  if ( FullPathNameA == 0 )
    goto LABEL_24;
  if ( v5 == nullptr )
  {
    if ( FullPathNameA > maxlen )
      maxlen = FullPathNameA;
    v7 = calloc(count: maxlen, size: 1u);
    v5 = (char *)v7;
    if ( v7 == nullptr )
    {
      *_errno() = 12;
      *__doserrno() = 8;
      return nullptr;
    }
    v8 = GetFullPathNameA(lpFileName: (LPCSTR)&drive, nBufferLength: maxlen, lpBuffer: (LPSTR)v7, lpFilePart: &pname);
    if ( v8 != 0 && v8 < maxlen )
      return v5;
LABEL_24:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return nullptr;
  }
  if ( FullPathNameA < count )
    return v5;
  *_errno() = 34;
  *v5 = 0;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10021853
// Name: __getcwd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getcwd(char *pnbuf, int maxlen)
{
  char *retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  retval = _getdcwd_nolock(drive: 0, pnbuf, maxlen);
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1002189C
// Name: _sprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sprintf(char *string, const char *format, ...)
{
  int v3; // eax
  bool v4; // sf
  int v5; // esi
  _iobuf str; // [esp+8h] [ebp-20h] BYREF
  va_list argptr; // [esp+38h] [ebp+10h] BYREF

  va_start(argptr, format);
  memset(&str, 0, sizeof(str));
  if ( format != nullptr && string != nullptr )
  {
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    str._flag = 66;
    v3 = _output_l(stream: &str, format, plocinfo: nullptr, argptr);
    v4 = --str._cnt < 0;
    v5 = v3;
    if ( v4 )
      _flsbuf(ch: 0, &str);
    else
      *str._ptr = 0;
    return v5;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021920
// Name: _mkdir
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl mkdir(const char *path)
{
  DWORD LastError; // eax

  if ( CreateDirectoryA(lpPathName: path, lpSecurityAttributes: nullptr) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10021960
// Name: __alloca_probe_16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _alloca_probe_16()
{
  return _chkstk();
}

//------------------------------------------------------------------------------
// Address: 0x1002198C
// Name: _atol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atol(const char *nptr)
{
  return strtol(nptr, endptr: nullptr, ibase: 10);
}

//------------------------------------------------------------------------------
// Address: 0x100219A2
// Name: _atoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atoi(const char *nptr)
{
  return atol(nptr);
}

//------------------------------------------------------------------------------
// Address: 0x100219AD
// Name: _printf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int printf(const char *format, ...)
{
  _iobuf *v2; // eax
  _iobuf *v3; // eax
  int v4; // edi
  _iobuf *v5; // eax
  _iobuf *v6; // eax
  _iobuf *v7; // eax
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+38h] [ebp+Ch] BYREF

  va_start(argptr, format);
  if ( format != nullptr )
  {
    v2 = __iob_func();
    _lock_file2(i: 1, s: (char *)&v2[1]);
    v3 = __iob_func();
    v4 = _stbuf(str: v3 + 1);
    v5 = __iob_func();
    retval = _output_l(stream: v5 + 1, format, plocinfo: nullptr, argptr);
    v6 = __iob_func();
    _ftbuf(flag: v4, str: v6 + 1);
    v7 = __iob_func();
    _unlock_file2(i: 1, s: (char *)&v7[1]);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021A54
// Name: __get_printf_count_output
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL _get_printf_count_output()
{
  return _enable_percent_n == (__security_cookie | 1);
}

//------------------------------------------------------------------------------
// Address: 0x10021A6A
// Name: __findclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _findclose(void *hFile)
{
  if ( FindClose(hFindFile: hFile) )
    return 0;
  *_errno() = 22;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10021A90
// Name: ___time64_t_from_ft
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __time64_t_from_ft(_FILETIME *pft)
{
  _FILETIME lft; // [esp+0h] [ebp-1Ch] BYREF
  _SYSTEMTIME st; // [esp+8h] [ebp-14h] BYREF

  if ( (pft->dwLowDateTime != 0 || pft->dwHighDateTime != 0)
    && FileTimeToLocalFileTime(lpFileTime: pft, lpLocalFileTime: &lft)
    && FileTimeToSystemTime(lpFileTime: &lft, lpSystemTime: &st) )
  {
    return __loctotime64_t(
             yr: st.wYear,
             mo: st.wMonth,
             dy: st.wDay,
             hr: st.wHour,
             mn: st.wMinute,
             sc: st.wSecond,
             dstflag: 0);
  }
  else
  {
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021B0C
// Name: __findfirst64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _findfirst64i32(const char *szWild, _finddata64i32_t *pfd)
{
  HANDLE FirstFile; // ebx
  DWORD LastError; // eax
  int v5; // edx
  int v6; // edx
  int v7; // edx
  _WIN32_FIND_DATAA wfd; // [esp+8h] [ebp-144h] BYREF

  if ( pfd == nullptr || szWild == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  FirstFile = FindFirstFileExA(
                lpFileName: szWild,
                fInfoLevelId: FindExInfoStandard,
                lpFindFileData: &wfd,
                fSearchOp: FindExSearchNameMatch,
                lpSearchFilter: nullptr,
                dwAdditionalFlags: 0);
  if ( FirstFile == (HANDLE)-1 )
  {
    LastError = GetLastError();
    if ( LastError >= 2 )
    {
      if ( LastError <= 3 )
        goto LABEL_13;
      if ( LastError == 8 )
      {
        *_errno() = 12;
        return -1;
      }
      if ( LastError == 18 )
      {
LABEL_13:
        *_errno() = 2;
        return -1;
      }
    }
    *_errno() = 22;
    return -1;
  }
  pfd->attrib = wfd.dwFileAttributes != 128 ? wfd.dwFileAttributes : 0;
  LODWORD(pfd->time_create) = __time64_t_from_ft(pft: &wfd.ftCreationTime);
  HIDWORD(pfd->time_create) = v5;
  LODWORD(pfd->time_access) = __time64_t_from_ft(pft: &wfd.ftLastAccessTime);
  HIDWORD(pfd->time_access) = v6;
  LODWORD(pfd->time_write) = __time64_t_from_ft(pft: &wfd.ftLastWriteTime);
  pfd->size = wfd.nFileSizeLow;
  HIDWORD(pfd->time_write) = v7;
  if ( strcpy_s(_Dst: pfd->name, _SizeInBytes: 0x104u, _Src: wfd.cFileName) != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return (int)FirstFile;
}

//------------------------------------------------------------------------------
// Address: 0x10021C33
// Name: __findnext64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _findnext64i32(void *hFile, _finddata64i32_t *pfd)
{
  int result; // eax
  DWORD LastError; // eax
  int v4; // edx
  int v5; // edx
  int v6; // edx
  _WIN32_FIND_DATAA wfd; // [esp+4h] [ebp-144h] BYREF

  if ( hFile == (void *)-1 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( pfd == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( !FindNextFileA(hFindFile: hFile, lpFindFileData: &wfd) )
  {
    LastError = GetLastError();
    if ( LastError >= 2 )
    {
      if ( LastError <= 3 )
        goto LABEL_14;
      if ( LastError == 8 )
      {
        *_errno() = 12;
        return -1;
      }
      if ( LastError == 18 )
      {
LABEL_14:
        *_errno() = 2;
        return -1;
      }
    }
    *_errno() = 22;
    return -1;
  }
  pfd->attrib = wfd.dwFileAttributes != 128 ? wfd.dwFileAttributes : 0;
  LODWORD(pfd->time_create) = __time64_t_from_ft(pft: &wfd.ftCreationTime);
  HIDWORD(pfd->time_create) = v4;
  LODWORD(pfd->time_access) = __time64_t_from_ft(pft: &wfd.ftLastAccessTime);
  HIDWORD(pfd->time_access) = v5;
  LODWORD(pfd->time_write) = __time64_t_from_ft(pft: &wfd.ftLastWriteTime);
  pfd->size = wfd.nFileSizeLow;
  HIDWORD(pfd->time_write) = v6;
  result = strcpy_s(_Dst: pfd->name, _SizeInBytes: 0x104u, _Src: wfd.cFileName);
  if ( result != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021E84
// Name: _atexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atexit(void (__cdecl *func)())
{
  return (_onexit((int (__cdecl *)())func) != nullptr) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10021EA0
// Name: _memset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memset(int dst, unsigned __int8 *value, unsigned int count)
{
  unsigned int v3; // edx
  int v4; // eax
  unsigned __int8 *v5; // edi
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // ecx

  v3 = count;
  if ( count != 0 )
  {
    LOBYTE(v4) = (_BYTE)value;
    if ( (_BYTE)value != 0 || count < 0x80 || __sse2_available == 0 )
    {
      v5 = (unsigned __int8 *)dst;
      if ( count < 4 )
        goto LABEL_15;
      v6 = -dst & 3;
      if ( v6 != 0 )
      {
        v3 = count - v6;
        do
        {
          *v5++ = (unsigned __int8)value;
          --v6;
        }
        while ( v6 != 0 );
      }
      v4 = 16843009 * (unsigned __int8)value;
      v7 = v3;
      v3 &= 3u;
      v8 = v7 >> 2;
      if ( v8 == 0 || (memset32(v5, v4, v8), v5 += 4 * v8, v3 != 0) )
      {
LABEL_15:
        do
        {
          *v5++ = v4;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else
    {
      _VEC_memzero((void *)dst, val: (int)value, len: count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10021F1A
// Name: __vsnprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf_l(char *string, unsigned int count, const char *format, localeinfo_struct *plocinfo, char *ap)
{
  int result; // eax
  int v6; // edi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( format != nullptr && (count == 0 || string != nullptr) )
  {
    str._cnt = 0x7FFFFFFF;
    if ( count <= 0x7FFFFFFF )
      str._cnt = count;
    str._flag = 66;
    str._base = string;
    str._ptr = string;
    result = _output_l(stream: &str, format, plocinfo, argptr: ap);
    v6 = result;
    if ( string != nullptr )
    {
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, &str);
      else
        *str._ptr = 0;
      return v6;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021FC6
// Name: __vsnprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf(char *string, unsigned int count, const char *format, char *ap)
{
  return _vsnprintf_l(string, count, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x10021FF0
// Name: _memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memcpy(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > src && dst < &src[count] )
  {
    v6 = &src[count - 4];
    v7 = &dst[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown+4)[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
    }
  }
  else if ( count >= 0x80
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, len: count);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:(CopyUnwindUp+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0[ecx*4]; jumptable 10022049 case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0;
      case 1u:
        goto UnwindUp1;
      case 2u:
        goto UnwindUp2;
      case 3u:
        goto UnwindUp3;
      case 4u:
        goto UnwindUp4;
      case 5u:
        goto UnwindUp5;
      case 6u:
        goto UnwindUp6;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1;
          case 2u:
            goto TrailUp2;
          case 3u:
            goto TrailUp3;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022351
// Name: __fclose_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fclose_nolock(_iobuf *str)
{
  int v1; // edi
  int v3; // eax

  v1 = -1;
  if ( str != nullptr )
  {
    if ( (str->_flag & 0x83) != 0 )
    {
      v1 = _flush(str);
      _freebuf(stream: str);
      v3 = _fileno(stream: str);
      if ( _close(fh: v3) >= 0 )
      {
        if ( str->_tmpfname != nullptr )
        {
          free(pMem: str->_tmpfname);
          str->_tmpfname = nullptr;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    str->_flag = 0;
    return v1;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100223BE
// Name: _fclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fclose(_iobuf *stream)
{
  int v2; // [esp+10h] [ebp-1Ch]

  v2 = -1;
  if ( stream != nullptr )
  {
    if ( (stream->_flag & 0x40) != 0 )
    {
      stream->_flag = 0;
    }
    else
    {
      _lock_file(pf: stream);
      v2 = _fclose_nolock(str: stream);
      _unlock_file(pf: stream);
    }
    return v2;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022432
// Name: _fprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int fprintf(_iobuf *str, const char *format, ...)
{
  int v3; // eax
  ioinfo *v4; // ecx
  ioinfo *v5; // eax
  int v6; // esi
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+3Ch] [ebp+10h] BYREF

  va_start(argptr, format);
  retval = 0;
  if ( str != nullptr && format != nullptr )
  {
    _lock_file(pf: str);
    if ( (str->_flag & 0x40) == 0 )
    {
      v3 = _fileno(stream: str);
      if ( v3 == -1 || v3 == -2 )
        v4 = &__badioinfo;
      else
        v4 = &__pioinfo[v3 >> 5][v3 & 0x1F];
      if ( (*((_BYTE *)v4 + 36) & 0x7F) != 0
        || (v3 == -1 || v3 == -2 ? (v5 = &__badioinfo) : (v5 = &__pioinfo[v3 >> 5][v3 & 0x1F]), *((char *)v5 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        retval = -1;
      }
    }
    if ( retval == 0 )
    {
      v6 = _stbuf(str);
      retval = _output_l(stream: str, format, plocinfo: nullptr, argptr);
      _ftbuf(flag: v6, str);
    }
    _unlock_file(pf: str);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002253E
// Name: __fsopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _fsopen(_iobuf *file, const char *mode, int shflag)
{
  _iobuf *v5; // eax
  _iobuf *retval; // [esp+10h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+14h] [ebp-18h] BYREF
  _iobuf *stream; // [esp+34h] [ebp+8h]

  if ( file == nullptr || mode == nullptr || *mode == 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  v5 = _getstream();
  stream = v5;
  if ( v5 == nullptr )
  {
    *_errno() = 24;
    return nullptr;
  }
  ms_exc.registration.TryLevel = 0;
  if ( LOBYTE(file->_ptr) == 0 )
  {
    *_errno() = 22;
    _local_unwind4(a1: &__security_cookie, a2: &ms_exc.registration, a3: -2);
    return nullptr;
  }
  retval = _openfile(filename: (const char *)file, mode, shflag, str: v5);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x100225FA
// Name: _fopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl fopen(_iobuf *file, const char *mode)
{
  return _fsopen(file, mode, shflag: 64);
}

//------------------------------------------------------------------------------
// Address: 0x10022611
// Name: _system
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl system(char *command)
{
  int v1; // esi
  int v2; // ebx
  int *v3; // eax
  char *argv[4]; // [esp+8h] [ebp-14h] BYREF
  char *envbuf; // [esp+18h] [ebp-4h] BYREF

  envbuf = nullptr;
  v1 = 0;
  if ( _dupenv_s(pBuffer: &envbuf, pBufferSizeInTChars: nullptr, varname: "COMSPEC") == 22 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  argv[0] = envbuf;
  if ( command == nullptr )
  {
    if ( envbuf != nullptr )
      v1 = _access_s(path: envbuf, amode: 0) == 0;
    goto cleanup;
  }
  argv[1] = "/c";
  argv[2] = command;
  argv[3] = nullptr;
  if ( envbuf == nullptr )
  {
LABEL_12:
    argv[0] = "cmd.exe";
    v1 = _spawnvpe(modeflag: 0, filename: "cmd.exe", (const char *const *)argv, envptr: nullptr);
    goto cleanup;
  }
  v2 = *_errno();
  *_errno() = 0;
  v1 = _spawnve(mode: 0, name: argv[0], (const char *const *)argv, envp: nullptr);
  v3 = _errno();
  if ( v1 != -1 )
  {
    *v3 = v2;
    goto cleanup;
  }
  if ( *v3 == 2 || *_errno() == 13 )
  {
    *_errno() = v2;
    goto LABEL_12;
  }
cleanup:
  free(pMem: envbuf);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100226EE
// Name: __fwrite_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fwrite_nolock(unsigned __int8 *buffer, unsigned int size, unsigned int num, _iobuf *stream)
{
  unsigned int v5; // edi
  unsigned int v6; // ebx
  int cnt; // eax
  unsigned int v8; // edi
  unsigned int v9; // edi
  int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int bufsize; // [esp+10h] [ebp-8h]
  unsigned __int8 *data; // [esp+14h] [ebp-4h]

  if ( size == 0 || num == 0 )
    return 0;
  if ( stream == nullptr || buffer == nullptr || num > 0xFFFFFFFF / size )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  v5 = num * size;
  data = buffer;
  v6 = num * size;
  if ( (stream->_flag & 0x10C) != 0 )
    bufsize = stream->_bufsiz;
  else
    bufsize = 4096;
  if ( v5 == 0 )
    return num;
  while ( 1 )
  {
    if ( (stream->_flag & 0x108) != 0 )
    {
      cnt = stream->_cnt;
      if ( cnt != 0 )
      {
        if ( cnt < 0 )
        {
          stream->_flag |= 0x20u;
LABEL_34:
          v13 = v5;
          return (v13 - v6) / size;
        }
        v8 = v6;
        if ( v6 >= cnt )
          v8 = stream->_cnt;
        memcpy(dst: (unsigned __int8 *)stream->_ptr, src: data, count: v8);
        stream->_cnt -= v8;
        stream->_ptr += v8;
        v6 -= v8;
        data += v8;
        goto LABEL_27;
      }
    }
    if ( v6 >= bufsize )
      break;
    if ( _flsbuf(ch: (char)*data, str: stream) == -1 )
      goto LABEL_34;
    ++data;
    --v6;
    bufsize = stream->_bufsiz;
    if ( (int)bufsize <= 0 )
      bufsize = 1;
LABEL_31:
    if ( v6 == 0 )
      return num;
  }
  if ( (stream->_flag & 0x108) != 0 && _flush(str: stream) != 0 )
    goto LABEL_34;
  v9 = v6;
  if ( bufsize != 0 )
    v9 = v6 - v6 % bufsize;
  v10 = _fileno(stream);
  v11 = _write(fh: v10, buf: data, cnt: v9);
  if ( v11 != -1 )
  {
    v12 = v9;
    if ( v11 <= v9 )
      v12 = v11;
    data += v12;
    v6 -= v12;
    if ( v11 >= v9 )
    {
LABEL_27:
      v5 = num * size;
      goto LABEL_31;
    }
  }
  stream->_flag |= 0x20u;
  v13 = num * size;
  return (v13 - v6) / size;
}

//------------------------------------------------------------------------------
// Address: 0x10022845
// Name: _fwrite
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fwrite(unsigned __int8 *buffer, unsigned int size, unsigned int count, _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( size == 0 || count == 0 )
    return 0;
  if ( stream == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  _lock_file(pf: stream);
  retval = _fwrite_nolock(buffer, size, num: count, stream);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x100228BF
// Name: __fread_nolock_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fread_nolock_s(
        unsigned __int8 *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int num,
        _iobuf *stream)
{
  unsigned int v6; // edi
  unsigned int v7; // ebx
  int cnt; // eax
  unsigned int v9; // edi
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  unsigned __int8 *v16; // ecx
  unsigned int v17; // [esp-4h] [ebp-20h]
  unsigned int streambufsize; // [esp+10h] [ebp-Ch]
  unsigned __int8 *data; // [esp+14h] [ebp-8h]
  unsigned int dataSize; // [esp+18h] [ebp-4h]

  data = buffer;
  dataSize = bufferSize;
  if ( elementSize == 0 || num == 0 )
    return 0;
  if ( buffer != nullptr )
  {
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
      goto LABEL_13;
    if ( bufferSize != -1 )
      memset(dst: (int)buffer, value: nullptr, count: bufferSize);
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
    {
LABEL_13:
      v6 = num * elementSize;
      v7 = num * elementSize;
      if ( (stream->_flag & 0x10C) != 0 )
        streambufsize = stream->_bufsiz;
      else
        streambufsize = 4096;
      if ( v6 == 0 )
        return num;
      while ( 1 )
      {
        if ( (stream->_flag & 0x10C) != 0 )
        {
          cnt = stream->_cnt;
          if ( cnt != 0 )
          {
            if ( cnt < 0 )
              goto LABEL_44;
            v9 = v7;
            if ( v7 >= cnt )
              v9 = stream->_cnt;
            if ( v9 > dataSize )
              goto LABEL_41;
            memcpy_s(dst: data, sizeInBytes: dataSize, src: (unsigned __int8 *)stream->_ptr, count: v9);
            stream->_cnt -= v9;
            stream->_ptr += v9;
            data += v9;
            v7 -= v9;
            dataSize -= v9;
            v6 = num * elementSize;
            goto LABEL_39;
          }
        }
        if ( v7 < streambufsize )
          break;
        if ( streambufsize != 0 )
        {
          if ( v7 <= 0x7FFFFFFF )
          {
            v10 = v7 % streambufsize;
            v11 = v7;
          }
          else
          {
            v10 = 0x7FFFFFFF % streambufsize;
            v11 = 0x7FFFFFFF;
          }
          v12 = v11 - v10;
        }
        else
        {
          v12 = 0x7FFFFFFF;
          if ( v7 <= 0x7FFFFFFF )
            v12 = v7;
        }
        if ( v12 > dataSize )
          goto LABEL_41;
        v17 = v12;
        v13 = _fileno(stream);
        v14 = _read(fh: v13, buf: data, cnt: v17);
        if ( v14 == 0 )
        {
          stream->_flag |= 0x10u;
          return (v6 - v7) / elementSize;
        }
        if ( v14 == -1 )
        {
LABEL_44:
          stream->_flag |= 0x20u;
          return (v6 - v7) / elementSize;
        }
        data += v14;
        v7 -= v14;
        dataSize -= v14;
LABEL_39:
        if ( v7 == 0 )
          return num;
      }
      v15 = _filbuf(str: stream);
      if ( v15 == -1 )
        return (v6 - v7) / elementSize;
      if ( dataSize != 0 )
      {
        v16 = data++;
        *v16 = v15;
        --v7;
        --dataSize;
        streambufsize = stream->_bufsiz;
        goto LABEL_39;
      }
LABEL_41:
      if ( bufferSize != -1 )
        memset(dst: (int)buffer, value: nullptr, count: bufferSize);
      *_errno() = 34;
LABEL_5:
      _invalid_parameter_noinfo();
      return 0;
    }
  }
  *_errno() = 22;
  goto LABEL_5;
}

//------------------------------------------------------------------------------
// Address: 0x10022A7B
// Name: _fread_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fread_s(
        unsigned __int8 *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int count,
        _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( elementSize == 0 || count == 0 )
    return 0;
  if ( stream == nullptr )
  {
    if ( bufferSize != -1 )
      memset(dst: (int)buffer, value: nullptr, count: bufferSize);
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  _lock_file(pf: stream);
  retval = _fread_nolock_s(buffer, bufferSize, elementSize, num: count, stream);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x10022B09
// Name: _fread
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fread(unsigned __int8 *buffer, unsigned int elementSize, unsigned int count, _iobuf *stream)
{
  return fread_s(buffer, bufferSize: 0xFFFFFFFF, elementSize, count, stream);
}

//------------------------------------------------------------------------------
// Address: 0x10022B26
// Name: __ftell_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ftell_nolock(_iobuf *str)
{
  int v3; // eax
  int v4; // esi
  signed int v5; // eax
  int flag; // edx
  char *ptr; // eax
  char *base; // ecx
  char *v9; // ebx
  char *v10; // edx
  int cnt; // edx
  ioinfo **v12; // ebx
  int v13; // esi
  char *v14; // eax
  char *v15; // ecx
  bool v16; // zf
  int bufsiz; // eax
  int v18; // ecx
  unsigned int offset; // [esp+8h] [ebp-Ch]
  int fd; // [esp+Ch] [ebp-8h]
  LONG filepos; // [esp+10h] [ebp-4h]
  unsigned int rdcnt; // [esp+1Ch] [ebp+8h]

  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v3 = _fileno(stream: str);
  v4 = v3;
  fd = v3;
  if ( str->_cnt < 0 )
    str->_cnt = 0;
  v5 = _lseek(fh: v3, pos: 0, mthd: 1u);
  filepos = v5;
  if ( v5 < 0 )
    return -1;
  flag = str->_flag;
  if ( (flag & 0x108) == 0 )
    return v5 - str->_cnt;
  ptr = str->_ptr;
  base = str->_base;
  v9 = (char *)(str->_ptr - base);
  offset = (unsigned int)v9;
  if ( (flag & 3) != 0 )
  {
    if ( __pioinfo[v4 >> 5][v4 & 0x1F].osfile < 0 )
    {
      v10 = str->_base;
      if ( base < ptr )
      {
        do
        {
          if ( *v10 == 10 )
            ++v9;
          ++v10;
        }
        while ( v10 < ptr );
        offset = (unsigned int)v9;
      }
    }
  }
  else if ( (flag & 0x80u) == 0 )
  {
    *_errno() = 22;
    return -1;
  }
  if ( filepos == 0 )
    return (int)v9;
  if ( (str->_flag & 1) == 0 )
    return filepos + offset;
  cnt = str->_cnt;
  if ( cnt != 0 )
  {
    v12 = &__pioinfo[fd >> 5];
    rdcnt = cnt + ptr - base;
    v13 = (fd & 0x1F) << 6;
    if ( *(&(*v12)->osfile + v13) >= 0 )
    {
LABEL_39:
      filepos -= rdcnt;
      return filepos + offset;
    }
    if ( _lseek(fh: fd, pos: 0, mthd: 2u) == filepos )
    {
      v14 = str->_base;
      v15 = &v14[rdcnt];
      while ( v14 < v15 )
      {
        if ( *v14 == 10 )
          ++rdcnt;
        ++v14;
      }
      v16 = (str->_flag & 0x2000) == 0;
LABEL_37:
      if ( !v16 )
        ++rdcnt;
      goto LABEL_39;
    }
    if ( (_lseek(fh: fd, pos: filepos, mthd: 0) & 0x80000000) == 0 )
    {
      bufsiz = 512;
      if ( rdcnt > 0x200 || ((v18 = str->_flag) & 8) == 0 || (v18 & 0x400) != 0 )
        bufsiz = str->_bufsiz;
      rdcnt = bufsiz;
      v16 = (*(&(*v12)->osfile + v13) & 4) == 0;
      goto LABEL_37;
    }
    return -1;
  }
  offset = 0;
  return filepos + offset;
}

//------------------------------------------------------------------------------
// Address: 0x10022CBA
// Name: _ftell
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ftell(_iobuf *stream)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr )
  {
    _lock_file(pf: stream);
    retval = _ftell_nolock(str: stream);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022D1F
// Name: __fseek_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fseek_nolock(_iobuf *str, LONG offset, DWORD whence)
{
  int flag; // eax
  int v5; // eax
  int v6; // eax

  flag = str->_flag;
  if ( (flag & 0x83) != 0 )
  {
    str->_flag = flag & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      offset += _ftell_nolock(str);
      whence = 0;
    }
    _flush(str);
    v5 = str->_flag;
    if ( (v5 & 0x80u) == 0 )
    {
      if ( (v5 & 1) != 0 && (v5 & 8) != 0 && (v5 & 0x400) == 0 )
        str->_bufsiz = 512;
    }
    else
    {
      str->_flag = v5 & 0xFFFFFFFC;
    }
    v6 = _fileno(stream: str);
    return (_lseek(fh: v6, pos: offset, mthd: whence) != -1) - 1;
  }
  else
  {
    *_errno() = 22;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022DA9
// Name: _fseek
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fseek(_iobuf *stream, LONG offset, DWORD whence)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr && whence <= 2 )
  {
    _lock_file(pf: stream);
    retval = _fseek_nolock(str: stream, offset, whence);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022E25
// Name: ___crtCorExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __crtCorExitProcess(int status)
{
  HMODULE ModuleHandleW; // eax
  FARPROC CorExitProcess; // eax

  ModuleHandleW = GetModuleHandleW(lpModuleName: L"mscoree.dll");
  if ( ModuleHandleW != nullptr )
  {
    CorExitProcess = GetProcAddress(hModule: ModuleHandleW, lpProcName: "CorExitProcess");
    if ( CorExitProcess != nullptr )
      ((void (__stdcall *)(int))CorExitProcess)(a1: status);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022E50
// Name: ___crtExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __crtExitProcess(int status)
{
  __crtCorExitProcess(status);
  ExitProcess(uExitCode: status);
}

//------------------------------------------------------------------------------
// Address: 0x10022E68
// Name: __lockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _lockexit()
{
  _lock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x10022E71
// Name: __unlockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _unlockexit()
{
  _unlock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x10022E7A
// Name: __init_pointers
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _init_pointers()
{
  int (__cdecl *v0)(unsigned int); // esi

  v0 = (int (__cdecl *)(unsigned int))_encoded_null();
  _initp_heap_handler(enull: v0);
  _initp_misc_invarg(enull: v0);
  _initp_misc_purevirt(enull: v0);
  _initp_misc_rand_s(enull: (int (__stdcall *)(void *, unsigned int))v0);
  _initp_misc_winsig(enull: v0);
  _initp_eh_hooks();
}

//------------------------------------------------------------------------------
// Address: 0x10022EAD
// Name: __initterm_e
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _initterm_e(int (__cdecl **pfbegin)(), int (__cdecl **pfend)())
{
  int result; // eax

  result = 0;
  while ( pfbegin < pfend && result == 0 )
  {
    if ( *pfbegin != nullptr )
      result = (*pfbegin)();
    ++pfbegin;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022ED1
// Name: __cinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cinit(int initFloatingPrecision)
{
  int result; // eax
  void (**i)(void); // edi

  if ( _fpmath != nullptr && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&_FPinit) )
    _fpmath(initPrecision: initFloatingPrecision);
  _initp_misc_cfltcvt_tab();
  result = _initterm_e(pfbegin: __xi_a, pfend: __xi_z);
  if ( result == 0 )
  {
    atexit(func: _RTC_Terminate);
    for ( i = __xc_a; i < __xc_z; ++i )
    {
      if ( *i != nullptr )
        (*i)();
    }
    if ( __dyn_tls_init_callback != nullptr
      && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&__dyn_tls_init_callback) )
    {
      __dyn_tls_init_callback(a1: nullptr, a2: 2u, a3: nullptr);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022F68
// Name: doexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl doexit(int code, int quick, int retcaller)
{
  PVOID *v3; // ebx
  PVOID *v4; // edi
  void (*v5)(void); // ebx
  void (__cdecl **v6)(); // ebx
  void (__cdecl **v7)(); // eax
  void (__cdecl **onexitbegin)(); // [esp+10h] [ebp-30h]
  void (__cdecl **onexitend_saved)(); // [esp+18h] [ebp-28h]
  void (__cdecl **onexitbegin_saved)(); // [esp+1Ch] [ebp-24h]
  void (**j)(void); // [esp+20h] [ebp-20h]
  void (**i)(void); // [esp+24h] [ebp-1Ch]

  _lock(locknum: 8);
  if ( _C_Exit_Done != 1 )
  {
    _C_Termination_Done = 1;
    _exitflag = retcaller;
    if ( quick == 0 )
    {
      v3 = (PVOID *)DecodePointer(Ptr: __onexitbegin);
      onexitbegin = (void (__cdecl **)())v3;
      if ( v3 != nullptr )
      {
        v4 = (PVOID *)DecodePointer(Ptr: __onexitend);
        onexitbegin_saved = (void (__cdecl **)())v3;
        onexitend_saved = (void (__cdecl **)())v4;
        while ( --v4 >= v3 )
        {
          if ( *v4 != _encoded_null() )
          {
            if ( v4 < v3 )
              break;
            v5 = (void (*)(void))DecodePointer(Ptr: *v4);
            *v4 = _encoded_null();
            v5();
            v6 = (void (__cdecl **)())DecodePointer(Ptr: __onexitbegin);
            v7 = (void (__cdecl **)())DecodePointer(Ptr: __onexitend);
            if ( onexitbegin_saved != v6 || onexitend_saved != v7 )
            {
              onexitbegin_saved = v6;
              onexitbegin = v6;
              onexitend_saved = v7;
              v4 = (PVOID *)v7;
            }
            v3 = (PVOID *)onexitbegin;
          }
        }
      }
      for ( i = __xp_a; i < __xp_z; ++i )
      {
        if ( *i != nullptr )
          (*i)();
      }
    }
    for ( j = __xt_a; j < __xt_z; ++j )
    {
      if ( *j != nullptr )
        (*j)();
    }
  }
  if ( retcaller != 0 )
    _unlock(locknum: 8);
  if ( retcaller == 0 )
  {
    _C_Exit_Done = 1;
    _unlock(locknum: 8);
    __crtExitProcess(status: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100230A8
// Name: _exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn exit(int code)
{
  doexit(code, quick: 0, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100230BE
// Name: __exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _exit(int code)
{
  doexit(code, quick: 1, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100230D4
// Name: __cexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cexit()
{
  doexit(code: 0, quick: 0, retcaller: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100230E3
// Name: __amsg_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _amsg_exit(int rterrnum)
{
  _FF_MSGBANNER();
  _NMSG_WRITE(rterrnum);
  _exit(code: 255);
}

//------------------------------------------------------------------------------
// Address: 0x10023101
// Name: __chdir
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _chdir(const char *path)
{
  char *v1; // esi
  signed int CurrentDirectoryA; // eax
  DWORD v4; // edi
  unsigned __int8 *v5; // eax
  char v6; // al
  DWORD LastError; // eax
  int memfree; // [esp+4h] [ebp-118h]
  int retval; // [esp+8h] [ebp-114h]
  char env_var[4]; // [esp+Ch] [ebp-110h] BYREF
  char abspath[264]; // [esp+10h] [ebp-10Ch] BYREF

  memfree = 0;
  retval = -1;
  v1 = abspath;
  if ( path == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( !SetCurrentDirectoryA(lpPathName: path) )
    goto LABEL_14;
  CurrentDirectoryA = GetCurrentDirectoryA(nBufferLength: 0x105u, lpBuffer: abspath);
  v4 = CurrentDirectoryA;
  if ( CurrentDirectoryA > 260 )
  {
    v5 = calloc(count: CurrentDirectoryA + 1, size: 1u);
    v1 = (char *)v5;
    if ( v5 == nullptr || (memfree = 1, v4 == 0) )
    {
LABEL_14:
      LastError = GetLastError();
      _dosmaperr(oserrno: LastError);
      goto LABEL_15;
    }
    v4 = GetCurrentDirectoryA(nBufferLength: v4 + 1, lpBuffer: (LPSTR)v5);
  }
  if ( v4 == 0 )
    goto LABEL_14;
  if ( (v6 = *v1, *v1 != 92) && v6 != 47 || v6 != v1[1] )
  {
    env_var[0] = 61;
    env_var[1] = _mbctoupper(c: (unsigned __int8)*v1);
    strcpy(&env_var[2], ":");
    if ( !SetEnvironmentVariableA(lpName: env_var, lpValue: v1) )
      goto LABEL_14;
  }
  retval = 0;
LABEL_15:
  if ( memfree != 0 )
    free(pMem: v1);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x10023230
// Name: __ftol2_sse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse@<eax>(double a1@<st0>)
{
  if ( __sse2_available != 0 )
    return _ftol2_pentium4();
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x10023239
// Name: __ftol2_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_pentium4@<eax>(double a1@<st0>)
{
  return (int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x1002324C
// Name: __ftol2_sse_excpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse_excpt@<eax>(double a1@<st0>)
{
  char v2; // [esp+0h] [ebp-4h]

  if ( __sse2_available != 0 && (v2 & 0x7F) == 0x7F )
    return _ftol2_pentium4(a1);
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x10023266
// Name: __ftol2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _ftol2@<eax>(double a1@<st0>)
{
  int v1; // edx
  unsigned int result; // eax
  float v3; // [esp+0h] [ebp-20h]
  int v4; // [esp+18h] [ebp-8h]

  *(float *)&v4 = a1;
  v1 = v4;
  result = (__int64)a1;
  if ( result != 0 || ((v1 = (unsigned __int64)(__int64)a1 >> 32) & 0x7FFFFFFF) != 0 )
  {
    if ( v1 >= 0 )
    {
      v3 = a1 - (double)(__int64)a1;
      result -= __CFADD__(LODWORD(v3), 0x7FFFFFFF);
    }
    else
    {
      return (__PAIR64__(result, -(float)(a1 - (double)(__int64)a1)) + 0x7FFFFFFF) >> 32;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100232E0
// Name: _strrchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strrchr(unsigned __int8 *string, unsigned __int8 chr)
{
  unsigned int v2; // ecx
  unsigned __int8 *v3; // edi
  bool v4; // zf

  v2 = strlen((const char *)string) + 1;
  v3 = &string[v2 - 1];
  do
  {
    if ( v2 == 0 )
      break;
    v4 = *v3-- == chr;
    --v2;
  }
  while ( !v4 );
}

//------------------------------------------------------------------------------
// Address: 0x1002330D
// Name: __getenv_helper_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__cdecl _getenv_helper_nolock(char *option)
{
  unsigned __int8 **v1; // esi
  unsigned int v3; // eax
  unsigned int v4; // edi
  unsigned int v5; // eax

  v1 = (unsigned __int8 **)_environ;
  if ( __env_initialized == 0 )
    return nullptr;
  if ( _environ != nullptr
    || _wenviron != nullptr && __wtomb_environ() == 0 && (v1 = (unsigned __int8 **)_environ, _environ != nullptr) )
  {
    if ( option != nullptr )
    {
      strlen(buf: (unsigned __int8 *)option);
      v4 = v3;
      while ( *v1 != nullptr )
      {
        strlen(buf: *v1);
        if ( v5 > v4 && (*v1)[v4] == 61 && _mbsnbicoll(s1: *v1, s2: (const unsigned __int8 *)option, n: v4) == 0 )
          return (const char *)&(*v1)[v4 + 1];
        ++v1;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10023394
// Name: _getenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl getenv(char *option)
{
  char *retval; // [esp+14h] [ebp-1Ch]

  if ( option != nullptr && strnlen(str: option, maxsize: 0x7FFFu) < 0x7FFF )
  {
    _lock(locknum: 7);
    retval = (char *)_getenv_helper_nolock(option);
    _unlock(locknum: 7);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002340E
// Name: __dupenv_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _dupenv_s(char **pBuffer, unsigned int *pBufferSizeInTChars, char *varname)
{
  int v3; // esi
  unsigned __int8 *v4; // eax
  const char *v5; // ebx
  int v6; // eax
  unsigned int v7; // esi
  unsigned __int8 *v8; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  v3 = 0;
  if ( pBuffer != nullptr )
  {
    *pBuffer = nullptr;
    if ( pBufferSizeInTChars != nullptr )
      *pBufferSizeInTChars = 0;
    if ( varname != nullptr )
    {
      v4 = (unsigned __int8 *)_getenv_helper_nolock(option: varname);
      v5 = (const char *)v4;
      if ( v4 == nullptr )
        goto LABEL_3;
      strlen(buf: v4);
      v7 = v6 + 1;
      v8 = calloc(count: v6 + 1, size: 1u);
      *pBuffer = (char *)v8;
      if ( v8 != nullptr )
      {
        if ( strcpy_s(_Dst: (char *)v8, _SizeInBytes: v7, _Src: v5) != 0 )
          _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
        if ( pBufferSizeInTChars != nullptr )
          *pBufferSizeInTChars = v7;
        retval = 0;
      }
      else
      {
        *_errno() = 12;
        retval = *_errno();
      }
LABEL_14:
      _unlock(locknum: 7);
      return retval;
    }
  }
  v3 = 22;
  *_errno() = 22;
  _invalid_parameter_noinfo();
LABEL_3:
  retval = v3;
  goto LABEL_14;
}

//------------------------------------------------------------------------------
// Address: 0x100234E5
// Name: _CRT_INIT(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _CRT_INIT(void *hDllHandle, unsigned int dwReason, void *lpreserved)
{
  CFileSystemPassThru *v4; // ecx
  CFileSystemPassThru *v5; // ecx
  unsigned __int8 *v6; // eax
  _tiddata *v7; // esi
  int (__stdcall *v8)(unsigned int, unsigned __int8 *); // eax
  unsigned int v9; // [esp-8h] [ebp-30h]
  unsigned __int8 *v10; // [esp-4h] [ebp-2Ch]

  if ( dwReason == 1 )
  {
    if ( !_heap_init() )
      return 0;
    if ( _mtinit() == 0 )
    {
LABEL_5:
      _heap_term(this: v4);
      return 0;
    }
    _RTC_Initialize();
    _acmdln = GetCommandLineA();
    _aenvptr = __crtGetEnvironmentStringsA();
    if ( _ioinit() < 0 )
    {
LABEL_7:
      _mtterm();
      goto LABEL_5;
    }
    if ( _setargv() < 0 || _setenvp() < 0 || _cinit(initFloatingPrecision: 0) != 0 )
    {
      _ioterm();
      goto LABEL_7;
    }
    ++_proc_attached;
  }
  else if ( dwReason != 0 )
  {
    if ( dwReason == 2 )
    {
      __set_flsgetvalue();
      v6 = calloc(count: 1u, size: 0x214u);
      v7 = (_tiddata *)v6;
      if ( v6 == nullptr )
        return 0;
      v10 = v6;
      v9 = __flsindex;
      v8 = (int (__stdcall *)(unsigned int, unsigned __int8 *))DecodePointer(Ptr: gpFlsSetValue);
      if ( v8(a1: v9, a2: v10) == 0 )
      {
        free(pMem: v7);
        return 0;
      }
      _initptd(ptd: v7, ptloci: nullptr);
      v7->_tid = GetCurrentThreadId();
      v7->_thandle = -1;
    }
    else if ( dwReason == 3 )
    {
      _freeptd(ptd: nullptr);
    }
  }
  else
  {
    if ( _proc_attached <= 0 )
      return 0;
    --_proc_attached;
    if ( _C_Termination_Done == 0 )
      _cexit();
    if ( lpreserved == nullptr )
    {
      _ioterm();
      _mtterm();
      _heap_term(this: v5);
      if ( __flsindex != -1 )
        _mtterm();
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10023649
// Name: __DllMainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _DllMainCRTStartup(void *lpreserved, unsigned int dwReason, HINSTANCE hDllHandle)
{
  BOOL v5; // eax
  int retcode; // [esp+10h] [ebp-1Ch]

  if ( dwReason == 0 && _proc_attached == 0
    || (dwReason == 1 || dwReason == 2) && _CRT_INIT(hDllHandle, dwReason, lpreserved) == 0 )
  {
    return 0;
  }
  v5 = DllMain(hinstDLL: hDllHandle, fdwReason: dwReason, lpvReserved: lpreserved);
  retcode = v5;
  if ( dwReason == 1 && !v5 )
  {
    DllMain(hinstDLL: hDllHandle, fdwReason: 0, lpvReserved: lpreserved);
    _CRT_INIT(hDllHandle, dwReason: 0, lpreserved);
  }
  if ( (dwReason == 0 || dwReason == 3) && _CRT_INIT(hDllHandle, dwReason, lpreserved) == 0 )
    return 0;
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x1002373F
// Name: _DllMainCRTStartup(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall _DllMainCRTStartup(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  if ( fdwReason == 1 )
    __security_init_cookie();
  return _DllMainCRTStartup(lpreserved: lpReserved, dwReason: fdwReason, hDllHandle: hinstDLL);
}

//------------------------------------------------------------------------------
// Address: 0x10023762
// Name: __freea
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freea(_DWORD *_Memory)
{
  if ( _Memory != nullptr && *(_Memory - 2) == 56797 )
    free(pMem: _Memory - 2);
}

//------------------------------------------------------------------------------
// Address: 0x10023782
// Name: public: _LocaleUpdate::_LocaleUpdate(struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_LocaleUpdate *__thiscall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this, localeinfo_struct *plocinfo)
{
  _tiddata *v3; // eax
  _tiddata *ptd; // eax

  this->updated = false;
  if ( plocinfo != nullptr )
  {
    this->localeinfo = *plocinfo;
  }
  else
  {
    v3 = _getptd();
    this->ptd = v3;
    this->localeinfo.locinfo = v3->ptlocinfo;
    this->localeinfo.mbcinfo = v3->ptmbcinfo;
    if ( this->localeinfo.locinfo != __ptlocinfo && (__globallocalestatus & v3->_ownlocale) == 0 )
      this->localeinfo.locinfo = __updatetlocinfo();
    if ( this->localeinfo.mbcinfo != __ptmbcinfo && (__globallocalestatus & this->ptd->_ownlocale) == 0 )
      this->localeinfo.mbcinfo = __updatetmbcinfo();
    ptd = this->ptd;
    if ( (ptd->_ownlocale & 2) == 0 )
    {
      ptd->_ownlocale |= 2u;
      this->updated = true;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10023809
// Name: __tolower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _tolower_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  bool v8; // zf
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+18h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+1Ch] [ebp-4h] BYREF
  int ca; // [esp+28h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x100u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      v8 = v7 == 1;
      result = (unsigned __int8)outbuffer[0];
      if ( !v8 )
        result = (unsigned __int8)outbuffer[1] | ((unsigned __int8)outbuffer[0] << 8);
      goto LABEL_17;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 1;
    }
    else
    {
      v4 = _isctype_l(c, mask: 1, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pclmap[c];
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x1002391E
// Name: _tolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl tolower(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed != 0 )
    return _tolower_l(c, plocinfo: nullptr);
  result = c;
  if ( c - 65 <= 0x19 )
    return c + 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10023950
// Name: __allmul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _allmul(__int64 a1, __int64 a2)
{
  if ( (HIDWORD(a1) | HIDWORD(a2)) != 0 )
    return a1 * a2;
  else
    return (unsigned int)a2 * (unsigned __int64)(unsigned int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x10023990
// Name: _strncat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strncat(char *Destination, const char *Source, size_t Count)
{
  size_t v3; // ecx
  char *v4; // edi
  char v5; // al
  int v6; // eax
  int v7; // eax
  char *v8; // edi
  const char *v9; // esi
  char v10; // bl
  size_t v11; // ecx
  int v12; // edx
  char v13; // dl
  int v15; // eax

  v3 = Count;
  if ( Count == 0 )
    return Destination;
  v4 = Destination;
  if ( ((unsigned __int8)Destination & 3) == 0 )
    goto find_end_of_front_string_loop;
  do
  {
    v5 = *v4++;
    if ( v5 == 0 )
    {
start_byte_3:
      v8 = v4 - 1;
      goto copy_start;
    }
  }
  while ( ((unsigned __int8)v4 & 3) != 0 );
  while ( 1 )
  {
    do
    {
find_end_of_front_string_loop:
      v6 = (*(_DWORD *)v4 + 2130640639) ^ ~*(_DWORD *)v4;
      v4 += 4;
    }
    while ( (v6 & 0x81010100) == 0 );
    v7 = *((_DWORD *)v4 - 1);
    if ( (_BYTE)v7 == 0 )
      break;
    if ( BYTE1(v7) == 0 )
    {
      v8 = v4 - 3;
      goto copy_start;
    }
    if ( (v7 & 0xFF0000) == 0 )
    {
      v8 = v4 - 2;
      goto copy_start;
    }
    if ( (v7 & 0xFF000000) == 0 )
      goto start_byte_3;
  }
  v8 = v4 - 4;
copy_start:
  v9 = Source;
  if ( ((unsigned __int8)Source & 3) == 0 )
  {
    v10 = Count;
    v11 = Count >> 2;
    if ( Count >> 2 != 0 )
      goto main_loop_entrance;
tail_loop_start:
    v3 = v10 & 3;
    if ( (v10 & 3) != 0 )
    {
      while ( 1 )
      {
        v13 = *v9++;
        *v8++ = v13;
        if ( v13 == 0 )
          break;
        if ( --v3 == 0 )
          goto empty_counter;
      }
    }
    else
    {
empty_counter:
      *v8 = v3;
    }
    return Destination;
  }
  do
  {
    LOBYTE(v12) = *v9++;
    if ( (_BYTE)v12 == 0 )
    {
LABEL_26:
      *v8 = v12;
      return Destination;
    }
    *v8++ = v12;
    if ( --v3 == 0 )
      goto empty_counter;
  }
  while ( ((unsigned __int8)v9 & 3) != 0 );
  v10 = v3;
  v11 = v3 >> 2;
  if ( v11 == 0 )
    goto tail_loop_start;
  while ( 1 )
  {
main_loop_entrance:
    v15 = (*(_DWORD *)v9 + 2130640639) ^ ~*(_DWORD *)v9;
    v12 = *(_DWORD *)v9;
    v9 += 4;
    if ( (v15 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v12 == 0 )
        goto LABEL_26;
      if ( BYTE1(v12) == 0 )
        break;
      if ( (v12 & 0xFF0000) == 0 )
      {
        *(_WORD *)v8 = v12;
        v8[2] = 0;
        return Destination;
      }
      if ( (v12 & 0xFF000000) == 0 )
      {
        *(_DWORD *)v8 = v12;
        return Destination;
      }
    }
    *(_DWORD *)v8 = v12;
    v8 += 4;
    if ( --v11 == 0 )
      goto tail_loop_start;
  }
  *(_WORD *)v8 = (unsigned __int8)v12;
  return Destination;
}

//------------------------------------------------------------------------------
// Address: 0x10023AD0
// Name: _memmove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memmove(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > src && dst < &src[count] )
  {
    v6 = &src[count - 4];
    v7 = &dst[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1_0:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown_0+4)[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
    }
  }
  else if ( count >= 0x80
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, len: count);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:(CopyUnwindUp_0+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0_0[ecx*4]; jumptable 10023B29 case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0_0;
      case 1u:
        goto UnwindUp1_0;
      case 2u:
        goto UnwindUp2_0;
      case 3u:
        goto UnwindUp3_0;
      case 4u:
        goto UnwindUp4_0;
      case 5u:
        goto UnwindUp5_0;
      case 6u:
        goto UnwindUp6_0;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6_0:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5_0:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4_0:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3_0:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2_0:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1_0:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0_0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1_0;
          case 2u:
            goto TrailUp2_0;
          case 3u:
            goto TrailUp3_0;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1_0:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2_0:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3_0:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023E40
// Name: _strncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strncpy(unsigned __int8 *dest, unsigned __int8 *source, unsigned int count)
{
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned int v7; // ecx
  unsigned __int8 v8; // al
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // edx

  v3 = count;
  if ( count == 0 )
    return;
  v4 = count;
  v5 = source;
  if ( ((unsigned __int8)source & 3) == 0 )
  {
    v7 = count >> 2;
    if ( count >> 2 != 0 )
      goto main_loop_entrance_0;
copy_tail_loop:
    while ( 1 )
    {
      v8 = *v5++;
      *dest++ = v8;
      if ( v8 == 0 )
        break;
      if ( --v4 == 0 )
        return;
    }
    while ( --v4 != 0 )
finish_loop:
      *dest++ = v8;
    return;
  }
  do
  {
    v8 = *v5++;
    *dest++ = v8;
    if ( --v3 == 0 )
      return;
    if ( v8 == 0 )
    {
      while ( ((unsigned __int8)dest & 3) != 0 )
      {
        *dest++ = 0;
        if ( --v3 == 0 )
          return;
      }
      v4 = v3;
      v9 = v3 >> 2;
      if ( v9 == 0 )
        goto finish_loop;
      goto fill_dwords_with_EOS;
    }
  }
  while ( ((unsigned __int8)v5 & 3) != 0 );
  LOBYTE(v4) = v3;
  v7 = v3 >> 2;
  if ( v7 == 0 )
  {
tail_loop_start_0:
    v4 &= 3u;
    if ( v4 != 0 )
      goto copy_tail_loop;
    return;
  }
  while ( 1 )
  {
main_loop_entrance_0:
    v10 = (*(_DWORD *)v5 + 2130640639) ^ ~*(_DWORD *)v5;
    v11 = *(_DWORD *)v5;
    v5 += 4;
    if ( (v10 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v11 == 0 )
        break;
      if ( BYTE1(v11) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int8)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF0000) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int16)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF000000) == 0 )
      {
        *(_DWORD *)dest = v11;
        goto fill_with_EOS_dwords;
      }
    }
    *(_DWORD *)dest = v11;
    dest += 4;
    if ( --v7 == 0 )
      goto tail_loop_start_0;
  }
  *(_DWORD *)dest = 0;
fill_with_EOS_dwords:
  dest += 4;
  v8 = 0;
  v9 = v7 - 1;
  if ( v9 != 0 )
  {
fill_dwords_with_EOS:
    v8 = 0;
    do
    {
      *(_DWORD *)dest = 0;
      dest += 4;
      --v9;
    }
    while ( v9 != 0 );
  }
  v4 &= 3u;
  if ( v4 != 0 )
    goto finish_loop;
}

//------------------------------------------------------------------------------
// Address: 0x10023F70
// Name: __alldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _alldiv(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  __int64 v5; // rax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned int v8; // esi
  unsigned __int64 v9; // rax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    ++v2;
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 != 0 )
  {
    v6 = __PAIR64__(v3, a2);
    v7 = a1;
    do
    {
      v6 >>= 1;
      v7 >>= 1;
    }
    while ( HIDWORD(v6) != 0 );
    v8 = v7 / (unsigned int)v6;
    v9 = v8 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v8, HIDWORD(v9)) || (HIDWORD(v9) = (a2 * (unsigned __int64)v8) >> 32, v9 > a1) )
      --v8;
    v5 = v8;
  }
  else
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    LODWORD(v5) = v4 / (unsigned int)a2;
    HIDWORD(v5) = HIDWORD(a1) / (unsigned int)a2;
  }
  if ( v2 == 1 )
    return -v5;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1002401A
// Name: strtoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoxl(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        unsigned int ibase,
        int flags)
{
  threadlocaleinfostruct *locinfo; // ecx
  unsigned __int8 v7; // bl
  const char *i; // edi
  int v9; // eax
  unsigned int v10; // eax
  const unsigned __int16 *pctype; // esi
  unsigned int v12; // ecx
  int v13; // ecx
  const char *v14; // edi
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-1Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h]
  unsigned int number; // [esp+1Ch] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  number = 0;
  locinfo = _loc_update.localeinfo.locinfo;
  v7 = *nptr;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v9 = locinfo->pctype[v7] & 8;
    }
    else
    {
      v9 = _isctype_l(c: v7, mask: 8, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v9 == 0 )
      break;
    v7 = *i;
  }
  if ( v7 == 45 )
  {
    flags |= 2u;
  }
  else if ( v7 != 43 )
  {
    goto LABEL_20;
  }
  v7 = *i++;
LABEL_20:
  if ( ibase != 0 )
  {
    if ( ibase != 16 || v7 != 48 )
      goto LABEL_32;
  }
  else
  {
    if ( v7 != 48 )
    {
      ibase = 10;
      goto LABEL_32;
    }
    if ( *i != 120 && *i != 88 )
    {
      ibase = 8;
      goto LABEL_32;
    }
    ibase = 16;
  }
  if ( *i == 120 || *i == 88 )
  {
    v7 = i[1];
    i += 2;
  }
LABEL_32:
  v10 = 0xFFFFFFFF / ibase;
  pctype = locinfo->pctype;
  v16 = 0xFFFFFFFF % ibase;
  while ( 1 )
  {
    if ( (pctype[v7] & 4) != 0 )
    {
      v12 = (char)v7 - 48;
    }
    else
    {
      if ( (pctype[v7] & 0x103) == 0 )
        break;
      v13 = (char)v7;
      if ( (unsigned __int8)(v7 - 97) <= 0x19u )
        v13 = (char)v7 - 32;
      v12 = v13 - 55;
    }
    if ( v12 >= ibase )
      break;
    flags |= 8u;
    if ( number < v10 || number == v10 && v12 <= v16 )
    {
      number = v12 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v7 = *i++;
  }
  v14 = i - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && number > 0x80000000 || (flags & 2) == 0 && number > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        number = -1;
      else
        number = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr != nullptr )
      v14 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v14;
  if ( (flags & 2) != 0 )
    number = -number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x10024245
// Name: _strtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtol(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 0);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10024270
// Name: __strtod_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _strtod_l(char *nptr, char **endptr, localeinfo_struct *plocinfo)
{
  const char *v3; // esi
  int v5; // eax
  _flt *v6; // eax
  _flt *v7; // ecx
  int flags; // eax
  long double v9; // st7
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-34h] BYREF
  long double tmp; // [esp+1Ch] [ebp-24h]
  _flt answerstruct; // [esp+24h] [ebp-1Ch] BYREF

  v3 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  while ( 1 )
  {
    v5 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
       ? _loc_update.localeinfo.locinfo->pctype[*(unsigned __int8 *)v3] & 8
       : _isctype_l(c: *(unsigned __int8 *)v3, mask: 8, plocinfo: &_loc_update.localeinfo);
    if ( v5 == 0 )
      break;
    ++v3;
  }
  v6 = _fltin2(flt: &answerstruct, str: v3, _Locale: &_loc_update.localeinfo);
  v7 = v6;
  if ( endptr != nullptr )
    *endptr = (char *)&v3[v6->nbytes];
  flags = v6->flags;
  if ( (v7->flags & 0x240) != 0 )
  {
    tmp = 0.0;
    if ( endptr != nullptr )
      *endptr = nptr;
    goto LABEL_24;
  }
  if ( (flags & 0x81) != 0 )
  {
    v9 = _HUGE;
    if ( *v3 == 45 )
      v9 = -_HUGE;
  }
  else if ( (flags & 0x100) == 0 || (v9 = 0.0, 0.0 != v7->dval) )
  {
    tmp = v7->dval;
    goto LABEL_24;
  }
  tmp = v9;
  *_errno() = 34;
LABEL_24:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return tmp;
}

//------------------------------------------------------------------------------
// Address: 0x10024393
// Name: _strtod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl strtod(char *nptr, char **endptr)
{
  return _strtod_l(nptr, endptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100243AA
// Name: __toupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _toupper_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  bool v8; // zf
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+14h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+18h] [ebp-4h] BYREF
  int ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x200u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      v8 = v7 == 1;
      result = (unsigned __int8)outbuffer[0];
      if ( !v8 )
        result = (unsigned __int8)outbuffer[1] | ((unsigned __int8)outbuffer[0] << 8);
      goto LABEL_17;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 2;
    }
    else
    {
      v4 = _isctype_l(c, mask: 2, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pcumap[c];
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x100244C0
// Name: _toupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl toupper(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed != 0 )
    return _toupper_l(c, plocinfo: nullptr);
  result = c;
  if ( c - 97 <= 0x19 )
    return c - 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100244EC
// Name: __time64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int64 __cdecl _time64(__int64 *timeptr)
{
  __int64 result; // rax
  FT nt_time; // [esp+0h] [ebp-8h] BYREF

  GetSystemTimeAsFileTime(lpSystemTimeAsFileTime: (LPFILETIME)&nt_time);
  result = (nt_time.ft_scalar - 116444736000000000LL) / 0x989680;
  if ( result > 0x793406FFFLL )
    result = -1;
  if ( timeptr != nullptr )
    *timeptr = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10024540
// Name: __aulldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _aulldiv(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v3; // rtt
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char v7; // cf
  unsigned int v8; // esi
  unsigned __int64 v9; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v8 = v6 / v5;
    v9 = v8 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v8, HIDWORD(v9)) || (HIDWORD(v9) = (a2 * (unsigned __int64)v8) >> 32, v9 > a1) )
      --v8;
    return v8;
  }
  else
  {
    LODWORD(v3) = a1;
    HIDWORD(v3) = HIDWORD(a1) % (unsigned int)a2;
    return v3 / (unsigned int)a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100245A8
// Name: _fgets
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl fgets(_iobuf *string, int count, _iobuf *str)
{
  char *v3; // edi
  int v5; // eax
  ioinfo *v6; // ecx
  ioinfo *v7; // eax
  int v9; // eax
  char *retval; // [esp+18h] [ebp-1Ch]

  v3 = (char *)string;
  retval = (char *)string;
  if ( string == nullptr && count != 0 || count < 0 || str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  if ( count == 0 )
    return nullptr;
  _lock_file(pf: str);
  if ( (str->_flag & 0x40) == 0 )
  {
    v5 = _fileno(stream: str);
    if ( v5 == -1 || v5 == -2 )
      v6 = &__badioinfo;
    else
      v6 = &__pioinfo[v5 >> 5][v5 & 0x1F];
    if ( (*((_BYTE *)v6 + 36) & 0x7F) != 0
      || (v5 == -1 || v5 == -2 ? (v7 = &__badioinfo) : (v7 = &__pioinfo[v5 >> 5][v5 & 0x1F]), *((char *)v7 + 36) < 0) )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      retval = nullptr;
    }
  }
  if ( retval != nullptr )
  {
    do
    {
      if ( --count == 0 )
        break;
      if ( --str->_cnt < 0 )
        v9 = _filbuf(str);
      else
        v9 = *(unsigned __int8 *)str->_ptr++;
      if ( v9 == -1 )
      {
        if ( v3 == (char *)string )
        {
          retval = nullptr;
          goto done_0;
        }
        break;
      }
      *v3++ = v9;
    }
    while ( (_BYTE)v9 != 10 );
    *v3 = 0;
  }
done_0:
  _unlock_file(pf: str);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x100246E0
// Name: __access_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _access_s(const char *path, int amode)
{
  DWORD FileAttributesA; // eax
  DWORD LastError; // eax

  if ( path == nullptr || (amode & 0xFFFFFFF9) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  FileAttributesA = GetFileAttributesA(lpFileName: path);
  if ( FileAttributesA == -1 )
  {
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return *_errno();
  }
  if ( (FileAttributesA & 0x10) == 0 && (FileAttributesA & 1) != 0 && (amode & 2) != 0 )
  {
    *__doserrno() = 5;
    *_errno() = 13;
    return *_errno();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002475F
// Name: _access
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl access(const char *path, int amode)
{
  return -(_access_s(path, amode) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10024780
// Name: __chkstk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _chkstk@<eax>(unsigned int a1@<eax>, int a2@<ecx>)
{
  unsigned int v2; // ecx
  unsigned int i; // eax
  int v5; // [esp-4h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  v5 = a2;
  v2 = ~((unsigned int)((unsigned int)&retaddr - (unsigned __int64)a1) >> 32) & ((unsigned int)&retaddr - a1);
  for ( i = (unsigned int)&v5 & 0xFFFFF000; v2 < i; i -= 4096 )
    ;
  return retaddr;
}

//------------------------------------------------------------------------------
// Address: 0x100247AB
// Name: vscan_fn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall vscan_fn@<eax>(
        char *string@<esi>,
        int (__cdecl *inputfn)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *),
        const char *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned int v6; // eax
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( string != nullptr && format != nullptr )
  {
    strlen(buf: (unsigned __int8 *)string);
    str._flag = 73;
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    if ( v6 <= 0x7FFFFFFF )
      str._cnt = v6;
    return inputfn(a1: &str, a2: (const unsigned __int8 *)format, a3: plocinfo, a4: arglist);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024819
// Name: _sscanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sscanf(char *string, const char *format, ...)
{
  va_list arglist; // [esp+14h] [ebp+10h] BYREF

  va_start(arglist, format);
  return vscan_fn(
           string,
           inputfn: (int (__cdecl *)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *))_input_l,
           format,
           plocinfo: nullptr,
           arglist);
}

//------------------------------------------------------------------------------
// Address: 0x1002483B
// Name: __atof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _atof_l(const char *nptr, localeinfo_struct *plocinfo)
{
  const char *v2; // esi
  long double result; // st7
  int v4; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-2Ch] BYREF
  _flt fltstruct; // [esp+14h] [ebp-1Ch] BYREF

  v2 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( nptr != nullptr )
  {
    while ( 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
         ? _loc_update.localeinfo.locinfo->pctype[*(unsigned __int8 *)v2] & 8
         : _isctype_l(c: *(unsigned __int8 *)v2, mask: 8, plocinfo: &_loc_update.localeinfo);
      if ( v4 == 0 )
        break;
      ++v2;
    }
    result = _fltin2(flt: &fltstruct, str: v2, _Locale: &_loc_update.localeinfo)->dval;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100248E6
// Name: _atof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl atof(const char *nptr)
{
  return _atof_l(nptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100248F9
// Name: _srand
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl srand(unsigned int seed)
{
  _getptd()->_holdrand = seed;
}

//------------------------------------------------------------------------------
// Address: 0x10024910
// Name: _memchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memchr(unsigned __int8 *buf, unsigned __int8 chr, unsigned int cnt)
{
  unsigned int v3; // eax
  unsigned __int8 *v4; // edx
  int v5; // ebx
  unsigned __int8 v6; // cl
  bool v7; // cf
  unsigned int v8; // eax
  unsigned int i; // eax
  unsigned __int8 v10; // cl
  int v11; // ecx
  unsigned int v12; // ecx
  unsigned int v13; // ecx

  v3 = cnt;
  if ( cnt != 0 )
  {
    v4 = buf;
    LOBYTE(v5) = chr;
    if ( ((unsigned __int8)buf & 3) != 0 )
    {
      while ( 1 )
      {
        v6 = *v4++;
        if ( chr == v6 )
          break;
        if ( --v3 == 0 )
          break;
        if ( ((unsigned __int8)v4 & 3) == 0 )
          goto main_loop_start_0;
      }
    }
    else
    {
main_loop_start_0:
      v7 = v3 < 4;
      v8 = v3 - 4;
      if ( v7 )
      {
tail_less_then_4:
        for ( i = v8 + 4; i != 0; --i )
        {
          v10 = *v4++;
          if ( (unsigned __int8)v5 == v10 )
            break;
        }
      }
      else
      {
        v5 = 16843009 * chr;
        while ( 1 )
        {
          v11 = v5 ^ *(_DWORD *)v4;
          v4 += 4;
          if ( (((v11 + 2130640639) ^ ~v11) & 0x81010100) != 0 )
          {
            v12 = *((_DWORD *)v4 - 1);
            LOBYTE(v12) = chr ^ v12;
            if ( (_BYTE)v12 == 0 )
              break;
            BYTE1(v12) ^= chr;
            if ( BYTE1(v12) == 0 )
              break;
            v13 = HIWORD(v12);
            if ( chr == (unsigned __int8)v13 || chr == BYTE1(v13) )
              break;
          }
          v7 = v8 < 4;
          v8 -= 4;
          if ( v7 )
            goto tail_less_then_4;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100249C0
// Name: shortsort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shortsort(
        char *hi@<eax>,
        char *lo,
        unsigned int width,
        int (__cdecl *comp)(const void *, const void *))
{
  char *v4; // edx
  char *v5; // edi
  unsigned int v6; // ecx
  char *v7; // esi
  char *v8; // ebx
  unsigned int v9; // esi
  char *v10; // eax
  int v11; // ecx
  char v12; // dl

  v4 = lo;
  v5 = hi;
  if ( hi > lo )
  {
    v6 = width;
    do
    {
      v7 = &lo[width];
      v8 = v4;
      if ( &lo[width] <= v5 )
      {
        do
        {
          if ( comp(a1: v7, a2: v8) > 0 )
            v8 = v7;
          v7 += width;
        }
        while ( v7 <= v5 );
        v6 = width;
        v4 = lo;
      }
      v9 = v6;
      v10 = v5;
      if ( v8 != v5 && v6 != 0 )
      {
        v11 = v8 - v5;
        do
        {
          v12 = v10[v11];
          v10[v11] = *v10;
          *v10++ = v12;
          --v9;
        }
        while ( v9 != 0 );
        v6 = width;
        v4 = lo;
      }
      v5 -= v6;
    }
    while ( v5 > v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024A50
// Name: _qsort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl qsort(char *base, unsigned int num, unsigned int width, int (__cdecl *comp)(const void *, const void *))
{
  char *v4; // edi
  unsigned int v5; // ebx
  char *v6; // esi
  unsigned int v7; // eax
  char *v8; // ebx
  unsigned int v9; // edx
  char *v10; // eax
  int v11; // ecx
  unsigned int v12; // ecx
  char *v13; // eax
  int v14; // edi
  unsigned int v15; // ecx
  char *v16; // eax
  int v17; // edi
  unsigned int v18; // edx
  char *v19; // eax
  int v20; // ecx
  char *v21; // eax
  char *v22; // edx
  int v23; // ecx
  int v24; // ecx
  int v25; // eax
  char *v26; // edx
  char *v27; // eax
  char *histk[30]; // [esp+8h] [ebp-100h]
  char *lostk[30]; // [esp+80h] [ebp-88h]
  unsigned int v30; // [esp+F8h] [ebp-10h]
  int stkptr; // [esp+FCh] [ebp-Ch]
  char *hi; // [esp+100h] [ebp-8h]
  char *lo; // [esp+104h] [ebp-4h]
  char base_3; // [esp+113h] [ebp+Bh]
  char base_3a; // [esp+113h] [ebp+Bh]
  char base_3b; // [esp+113h] [ebp+Bh]
  char base_3c; // [esp+113h] [ebp+Bh]

  v4 = base;
  if ( base == nullptr && num != 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  v5 = width;
  if ( width == 0 || comp == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  if ( num >= 2 )
  {
    v6 = &base[width * (num - 1)];
    stkptr = 0;
    lo = base;
    hi = v6;
    while ( 1 )
    {
      v7 = (v6 - v4) / v5 + 1;
      if ( v7 <= 8 )
      {
        shortsort(hi: v6, lo: v4, width: v5, comp);
        goto LABEL_57;
      }
      v8 = &v4[(v7 >> 1) * v5];
      if ( comp(a1: v4, a2: v8) > 0 )
      {
        v9 = width;
        v10 = v8;
        if ( v4 != v8 )
        {
          v11 = v4 - v8;
          do
          {
            v30 = v9 - 1;
            base_3 = v10[v11];
            v10[v11] = *v10;
            *v10 = base_3;
            v9 = v30;
            ++v10;
          }
          while ( v30 != 0 );
        }
      }
      if ( comp(a1: v4, a2: v6) > 0 )
      {
        v12 = width;
        v13 = v6;
        if ( v4 != v6 )
        {
          v14 = v4 - v6;
          do
          {
            base_3a = v13[v14];
            v13[v14] = *v13;
            *v13++ = base_3a;
            --v12;
          }
          while ( v12 != 0 );
          v4 = lo;
        }
      }
      if ( comp(a1: v8, a2: v6) > 0 )
      {
        v15 = width;
        v16 = v6;
        if ( v8 != v6 )
        {
          v17 = v8 - v6;
          do
          {
            base_3b = v16[v17];
            v16[v17] = *v16;
            *v16++ = base_3b;
            --v15;
          }
          while ( v15 != 0 );
          v4 = lo;
        }
      }
      while ( 1 )
      {
        if ( v8 > v4 )
        {
          while ( 1 )
          {
            v4 += width;
            if ( v4 >= v8 )
              break;
            if ( comp(a1: v4, a2: v8) > 0 )
            {
              if ( v8 > v4 )
                goto LABEL_32;
              goto LABEL_30;
            }
          }
        }
        do
LABEL_30:
          v4 += width;
        while ( v4 <= hi && comp(a1: v4, a2: v8) <= 0 );
        do
LABEL_32:
          v6 -= width;
        while ( v6 > v8 && comp(a1: v6, a2: v8) > 0 );
        if ( v4 > v6 )
          break;
        v18 = width;
        v19 = v6;
        if ( v4 != v6 )
        {
          v20 = v4 - v6;
          do
          {
            v30 = v18 - 1;
            base_3c = v19[v20];
            v19[v20] = *v19;
            *v19 = base_3c;
            v18 = v30;
            ++v19;
          }
          while ( v30 != 0 );
        }
        if ( v8 == v6 )
          v8 = v4;
      }
      v6 += width;
      if ( v8 >= v6 )
        goto LABEL_44;
      do
      {
        v6 -= width;
        if ( v6 <= v8 )
          goto LABEL_44;
      }
      while ( comp(a1: v6, a2: v8) == 0 );
      if ( v8 < v6 )
      {
LABEL_46:
        v21 = lo;
      }
      else
      {
LABEL_44:
        while ( 1 )
        {
          v6 -= width;
          v21 = lo;
          if ( v6 <= lo )
            break;
          if ( comp(a1: v6, a2: v8) != 0 )
            goto LABEL_46;
        }
      }
      v22 = hi;
      if ( v6 - v21 < hi - v4 )
      {
        if ( v4 < hi )
        {
          v24 = stkptr;
          lostk[stkptr] = v4;
          histk[v24] = v22;
          stkptr = v24 + 1;
        }
        if ( v21 >= v6 )
          goto LABEL_56;
        v4 = lo;
        v5 = width;
        hi = v6;
      }
      else
      {
        if ( v21 < v6 )
        {
          v23 = stkptr;
          lostk[stkptr] = v21;
          histk[v23] = v6;
          stkptr = v23 + 1;
        }
        if ( v4 >= v22 )
        {
LABEL_56:
          v5 = width;
LABEL_57:
          v25 = --stkptr;
          if ( stkptr < 0 )
            return;
          v26 = lostk[v25];
          v27 = histk[v25];
          lo = v26;
          hi = v27;
          v6 = v27;
          v4 = v26;
        }
        else
        {
          v6 = hi;
          v5 = width;
          lo = v4;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024CDB
// Name: _putenv_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl putenv_helper(char *name, const char *value)
{
  const CHAR *v3; // edi
  int v4; // eax
  int v5; // eax
  unsigned int v6; // esi
  unsigned __int8 *v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // esi
  unsigned __int8 *v11; // eax
  int v12; // edi
  int v13; // eax
  unsigned __int8 *v14; // eax
  int v15; // eax
  char *newoption; // [esp+4h] [ebp-8h] BYREF
  unsigned __int16 *woption; // [esp+8h] [ebp-4h] BYREF

  newoption = nullptr;
  if ( __env_initialized == 0 )
    return -1;
  v3 = name;
  if ( name == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( value != nullptr )
  {
    v8 = strnlen(str: name, maxsize: 0x7FFFu);
    v9 = strnlen(str: value, maxsize: 0x7FFFu);
    if ( v8 < 0x7FFF && v9 < 0x7FFF )
    {
      v10 = v9 + v8 + 2;
      v11 = calloc(count: v10, size: 1u);
      newoption = (char *)v11;
      if ( v11 != nullptr )
      {
        strcpy_s(_Dst: (char *)v11, _SizeInBytes: v10, _Src: name);
        newoption[v8] = 61;
        strcpy_s(_Dst: &newoption[v8 + 1], _SizeInBytes: v10 - (v8 + 1), _Src: value);
        v3 = name;
        goto LABEL_16;
      }
      return -1;
    }
LABEL_13:
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  _mbschr(string: (unsigned __int8 *)name, c: 0x3Du);
  if ( v4 != 0 && (v4 - (int)name >= 0x7FFF || strnlen(str: (const char *)(v4 + 1), maxsize: 0x7FFFu) >= 0x7FFF) )
    goto LABEL_13;
  strlen(buf: (unsigned __int8 *)name);
  v6 = v5 + 1;
  v7 = calloc(count: v5 + 1, size: 1u);
  newoption = (char *)v7;
  if ( v7 == nullptr )
    return -1;
  strcpy_s(_Dst: (char *)v7, _SizeInBytes: v6, _Src: name);
LABEL_16:
  if ( __crtsetenv(poption: &newoption, primary: 1) != 0 )
  {
    if ( newoption != nullptr )
      free(pMem: newoption);
    return -1;
  }
  if ( _wenviron == nullptr )
    return 0;
  woption = nullptr;
  v12 = MultiByteToWideChar(
          CodePage: 0,
          dwFlags: 0,
          lpMultiByteStr: v3,
          cbMultiByte: -1,
          lpWideCharStr: nullptr,
          cchWideChar: 0);
  if ( v12 == 0 )
    goto LABEL_29;
  if ( value != nullptr )
  {
    v13 = MultiByteToWideChar(
            CodePage: 0,
            dwFlags: 0,
            lpMultiByteStr: value,
            cbMultiByte: -1,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    if ( v13 == 0 )
    {
LABEL_29:
      *_errno() = 42;
      return -1;
    }
    v12 += v13 + 1;
  }
  v14 = calloc(count: v12, size: 2u);
  woption = (unsigned __int16 *)v14;
  if ( v14 == nullptr )
    return -1;
  if ( MultiByteToWideChar(
         CodePage: 0,
         dwFlags: 0,
         lpMultiByteStr: name,
         cbMultiByte: -1,
         lpWideCharStr: (LPWSTR)v14,
         cchWideChar: v12) == 0
    || value != nullptr
    && (v15 = wcslen(wcs: woption),
        woption[v15] = 61,
        MultiByteToWideChar(
          CodePage: 0,
          dwFlags: 0,
          lpMultiByteStr: value,
          cbMultiByte: -1,
          lpWideCharStr: &woption[v15 + 1],
          cchWideChar: v12 - (v15 + 1)) == 0) )
  {
    free(pMem: woption);
    goto LABEL_29;
  }
  if ( __crtwsetenv(poption: &woption, primary: 0) != 0 )
  {
    if ( woption != nullptr )
      free(pMem: woption);
    return -1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10024ED8
// Name: __putenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _putenv(char *option)
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  retval = putenv_helper(name: option, value: nullptr);
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x10024F1D
// Name: __spawnv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _spawnv(int modeflag, const char *pathname, const char *const *argv)
{
  if ( pathname != nullptr && *pathname != 0 && argv != nullptr && *argv != nullptr && **(_BYTE **)argv != 0 )
    return _spawnve(mode: modeflag, name: pathname, argv, envp: nullptr);
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10024F67
// Name: __localtime64_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _localtime64_s(tm *ptm, const __int64 *ptime)
{
  int result; // eax
  int v3; // eax
  __int64 v4; // kr00_8
  __int64 v5; // kr10_8
  __int64 v6; // kr20_8
  __int64 v7; // rax
  int v8; // ecx
  int v9; // edx
  __int64 ltime; // [esp+8h] [ebp-14h] BYREF
  int dstbias; // [esp+10h] [ebp-Ch] BYREF
  int daylight; // [esp+14h] [ebp-8h] BYREF
  int timezone; // [esp+18h] [ebp-4h] BYREF

  daylight = 0;
  dstbias = 0;
  timezone = 0;
  if ( ptm == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  memset(dst: (int)ptm, value: (unsigned __int8 *)0xFF, count: sizeof(tm));
  if ( ptime == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  if ( *((int *)ptime + 1) < 0 || *ptime > 0x793406FFFLL )
  {
    *_errno() = 22;
    return 22;
  }
  __tzset();
  if ( _get_daylight(_Daylight: &daylight) != 0
    || _get_dstbias(_Daylight_savings_bias: &dstbias) != 0
    || _get_timezone(_Timezone: &timezone) != 0 )
  {
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  }
  if ( *ptime <= 259200 )
  {
    result = _gmtime64_s(ptm, timp: ptime);
    if ( result == 0 )
    {
      if ( daylight != 0 && _isindst(tb: ptm) != 0 )
      {
        v3 = dstbias + timezone;
        ptm->tm_isdst = 1;
        v4 = ptm->tm_sec - (__int64)v3;
      }
      else
      {
        v4 = ptm->tm_sec - (__int64)timezone;
      }
      ptm->tm_sec = v4 % 60;
      if ( v4 % 60 < 0 )
      {
        ptm->tm_sec = v4 % 60 + 60;
        v4 = __PAIR64__((unsigned int)__CFADD__((_DWORD)v4, -60) + HIDWORD(v4) - 1, (int)v4 - 60);
      }
      v5 = ptm->tm_min + v4 / 60;
      ptm->tm_min = v5 % 60;
      if ( v5 % 60 < 0 )
      {
        ptm->tm_min = v5 % 60 + 60;
        v5 -= 60;
      }
      v6 = ptm->tm_hour + v5 / 60;
      ptm->tm_hour = v6 % 24;
      if ( v6 % 24 < 0 )
      {
        ptm->tm_hour = v6 % 24 + 24;
        v6 -= 24;
      }
      v7 = v6 / 24;
      v8 = v6 / 24;
      if ( (((unsigned __int64)(v6 / 24) >> 32) & 0x80000000) != 0LL )
      {
        HIDWORD(v7) = ((int)v7 + ptm->tm_wday + 7) % 7;
        ptm->tm_mday += v7;
        LODWORD(v7) = ptm->tm_mday;
        ptm->tm_wday = HIDWORD(v7);
        if ( (int)v7 <= 0 )
        {
          ptm->tm_yday += v8 + 365;
          --ptm->tm_year;
          ptm->tm_mday = v7 + 31;
          ptm->tm_mon = 11;
          return 0;
        }
      }
      else
      {
        if ( v7 <= 0 )
          return 0;
        v9 = (v8 + ptm->tm_wday) % 7;
        ptm->tm_mday += v8;
        ptm->tm_wday = v9;
      }
      ptm->tm_yday += v8;
      return 0;
    }
  }
  else
  {
    ltime = *ptime - timezone;
    result = _gmtime64_s(ptm, timp: &ltime);
    if ( result == 0 )
    {
      if ( daylight == 0 || _isindst(tb: ptm) == 0 )
        return 0;
      ltime -= dstbias;
      result = _gmtime64_s(ptm, timp: &ltime);
      if ( result == 0 )
      {
        ptm->tm_isdst = 1;
        return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100251EF
// Name: __localtime64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
tm *__cdecl _localtime64(const __int64 *ptime)
{
  tm *result; // eax

  result = (tm *)__getgmtimebuf();
  if ( result != nullptr )
    return _localtime64_s(ptm: result, ptime) == 0 ? result : nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10025216
// Name: __flush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flush(_iobuf *str)
{
  int flag; // eax
  int v2; // ebx
  char *base; // eax
  char *v4; // edi
  int v5; // eax
  int v6; // eax
  char *v7; // eax
  char *v9; // [esp-Ch] [ebp-14h]
  char *v10; // [esp-8h] [ebp-10h]

  flag = str->_flag;
  v2 = 0;
  if ( (flag & 3) == 2 && (flag & 0x108) != 0 )
  {
    base = str->_base;
    v4 = (char *)(str->_ptr - base);
    if ( (int)v4 > 0 )
    {
      v10 = (char *)(str->_ptr - base);
      v9 = str->_base;
      v5 = _fileno(stream: str);
      if ( (char *)_write(fh: v5, buf: v9, cnt: (unsigned int)v10) == v4 )
      {
        v6 = str->_flag;
        if ( (v6 & 0x80u) != 0 )
          str->_flag = v6 & 0xFFFFFFFD;
      }
      else
      {
        str->_flag |= 0x20u;
        v2 = -1;
      }
    }
  }
  v7 = str->_base;
  str->_cnt = 0;
  str->_ptr = v7;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1002527E
// Name: __fflush_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fflush_nolock(_iobuf *str)
{
  int v2; // eax

  if ( str == nullptr )
    return flsall(flushflag: 0);
  if ( _flush(str) != 0 )
    return -1;
  if ( (str->_flag & 0x4000) == 0 )
    return 0;
  v2 = _fileno(stream: str);
  return -(_commit(filedes: v2) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x100252C6
// Name: flsall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl flsall(int flushflag)
{
  int i; // esi
  char **v2; // eax
  char *v3; // eax
  int v4; // ecx
  int result; // eax
  int err; // [esp+10h] [ebp-24h]
  int count; // [esp+18h] [ebp-1Ch]

  count = 0;
  err = 0;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v2 = (char **)&__piob[i];
    if ( *v2 != nullptr )
    {
      v3 = *v2;
      if ( (v3[12] & 0x83) != 0 )
      {
        _lock_file2(i, s: v3);
        v4 = *((_DWORD *)__piob[i] + 3);
        if ( (v4 & 0x83) != 0 )
        {
          if ( flushflag == 1 )
          {
            if ( _fflush_nolock(str: (_iobuf *)__piob[i]) != -1 )
              ++count;
          }
          else if ( flushflag == 0 && (v4 & 2) != 0 && _fflush_nolock(str: (_iobuf *)__piob[i]) == -1 )
          {
            err = -1;
          }
        }
        _unlock_file2(i, s: (char *)__piob[i]);
      }
    }
  }
  _unlock(locknum: 1);
  result = count;
  if ( flushflag != 1 )
    return err;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100253A0
// Name: _fflush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fflush(_iobuf *stream)
{
  int rc; // [esp+10h] [ebp-1Ch]

  if ( stream == nullptr )
    return flsall(flushflag: 0);
  _lock_file(pf: stream);
  rc = _fflush_nolock(str: stream);
  _unlock_file(pf: stream);
  return rc;
}

//------------------------------------------------------------------------------
// Address: 0x100253F3
// Name: __flushall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flushall()
{
  return flsall(flushflag: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100253FC
// Name: _vfprintf_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl vfprintf_helper(
        int (__cdecl *outfn)(_iobuf *, const char *, localeinfo_struct *, char *),
        _iobuf *str,
        const char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int v6; // eax
  ioinfo *v7; // ecx
  ioinfo *v8; // eax
  int v9; // esi
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  if ( str != nullptr && format != nullptr )
  {
    _lock_file(pf: str);
    if ( (str->_flag & 0x40) == 0 )
    {
      v6 = _fileno(stream: str);
      if ( v6 == -1 || v6 == -2 )
        v7 = &__badioinfo;
      else
        v7 = &__pioinfo[v6 >> 5][v6 & 0x1F];
      if ( (*((_BYTE *)v7 + 36) & 0x7F) != 0
        || (v6 == -1 || v6 == -2 ? (v8 = &__badioinfo) : (v8 = &__pioinfo[v6 >> 5][v6 & 0x1F]), *((char *)v8 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        retval = -1;
      }
    }
    if ( retval == 0 )
    {
      v9 = _stbuf(str);
      retval = outfn(a1: str, a2: format, a3: plocinfo, a4: ap);
      _ftbuf(flag: v9, str);
    }
    _unlock_file(pf: str);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025507
// Name: _vfprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl vfprintf(_iobuf *str, const char *format, char *ap)
{
  return vfprintf_helper(outfn: _output_l, str, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x10025526
// Name: _asctime
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl asctime(const tm *tb)
{
  char *asctimebuf; // edi
  _tiddata *v2; // eax
  _tiddata *v3; // esi
  unsigned __int8 *v4; // eax
  char *v5; // ecx
  int tm_mon; // edi
  int tm_mday; // edx
  int tm_wday; // eax
  int v10; // edx
  int i; // eax
  char v12; // dl
  char v13; // dl
  char v14; // dl
  char v15; // dl
  char v16; // dl
  int v17; // edx
  char *p; // [esp+10h] [ebp-4h]

  asctimebuf = buf_0;
  p = buf_0;
  v2 = _getptd_noexit();
  v3 = v2;
  if ( v2 != nullptr )
  {
    if ( v2->_asctimebuf != nullptr
      || (v4 = calloc(count: 0x1Au, size: 1u), v3->_asctimebuf = (char *)v4, v4 != nullptr) )
    {
      asctimebuf = v3->_asctimebuf;
      p = asctimebuf;
    }
  }
  v5 = asctimebuf;
  if ( asctimebuf != nullptr
    && (*asctimebuf = 0, tb != nullptr)
    && tb->tm_year >= 0
    && (unsigned int)(tm_mon = tb->tm_mon) < 0xC
    && tb->tm_hour < 0x18u
    && tb->tm_min < 0x3Cu
    && tb->tm_sec < 0x3Cu
    && (tm_mday = tb->tm_mday) >= 1
    && (dword_10048238[tm_mon] - _days[tm_mon] >= tm_mday
     || ((tb->tm_year + 1900) % 4 == 0 && (tb->tm_year + 1900) % 100 != 0 || (tb->tm_year + 1900) % 400 == 0)
     && tm_mon == 1
     && tb->tm_mday <= 29)
    && (unsigned int)(tm_wday = tb->tm_wday) <= 6 )
  {
    v10 = 3 * tm_wday;
    for ( i = 0; i < 3; ++i )
    {
      *v5 = __dnames[v10 + i];
      p[i + 4] = __mnames[3 * tm_mon + i];
      ++v5;
    }
    *v5 = 32;
    v5[4] = 32;
    v12 = tb->tm_mday % 10;
    v5[5] = tb->tm_mday / 10 + 48;
    v5[6] = v12 + 48;
    v5[7] = 32;
    v13 = tb->tm_hour % 10;
    v5[8] = tb->tm_hour / 10 + 48;
    v5[9] = v13 + 48;
    v5[10] = 58;
    v14 = tb->tm_min % 10;
    v5[11] = tb->tm_min / 10 + 48;
    v5[12] = v14 + 48;
    v5[13] = 58;
    v15 = tb->tm_sec % 10;
    v5[14] = tb->tm_sec / 10 + 48;
    v5[15] = v15 + 48;
    v5[16] = 32;
    v16 = (tb->tm_year / 100 + 19) % 10;
    v5[17] = (tb->tm_year / 100 + 19) / 10 + 48;
    v5[18] = v16 + 48;
    v17 = tb->tm_year % 100;
    v5[19] = v17 / 10 + 48;
    v5[20] = v17 % 10 + 48;
    *(_WORD *)(v5 + 21) = 10;
    return p;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025710
// Name: __aullrem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _aullrem(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v2; // rtt
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  bool v7; // cf
  int v8; // ecx
  unsigned __int64 v9; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v8 = HIDWORD(a2) * (v6 / v5);
    v9 = (unsigned int)a2 * (unsigned __int64)(unsigned int)(v6 / v5);
    v7 = __CFADD__(v8, HIDWORD(v9));
    HIDWORD(v9) += v8;
    if ( v7 || v9 > a1 )
      v9 -= a2;
    return a1 - v9;
  }
  else
  {
    LODWORD(v2) = a1;
    HIDWORD(v2) = HIDWORD(a1) % (unsigned int)a2;
    return v2 % (unsigned int)a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025790
// Name: __aulldvrm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _aulldvrm(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v2; // rtt
  unsigned int v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char v7; // cf
  unsigned __int64 v8; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v3 = v6 / v5;
    v8 = v3 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v3, HIDWORD(v8)) || (HIDWORD(v8) = (a2 * (unsigned __int64)v3) >> 32, v8 > a1) )
      --v3;
  }
  else
  {
    LODWORD(v2) = a1;
    HIDWORD(v2) = HIDWORD(a1) % (unsigned int)a2;
    return v2 / (unsigned int)a2;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100258A0
// Name: _strcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcmp(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 *v2; // edx
  unsigned __int8 *v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // eax
  __int16 v6; // ax

  v2 = str1;
  v3 = str2;
  if ( ((unsigned __int8)str1 & 3) != 0 )
  {
    if ( ((unsigned __int8)str1 & 1) == 0 )
      goto doword;
    v2 = str1 + 1;
    if ( *str1 != *str2 )
      return;
    v3 = str2 + 1;
    if ( *str1 == 0 )
      return;
    if ( ((unsigned __int8)v2 & 2) != 0 )
    {
doword:
      v6 = *(_WORD *)v2;
      v2 += 2;
      if ( (_BYTE)v6 != *v3 || (_BYTE)v6 == 0 || HIBYTE(v6) != v3[1] || HIBYTE(v6) == 0 )
        return;
      v3 += 2;
    }
  }
  do
  {
    v4 = *(_DWORD *)v2;
    if ( (unsigned __int8)*(_DWORD *)v2 != *v3 )
      break;
    if ( (_BYTE)v4 == 0 )
      break;
    if ( BYTE1(v4) != v3[1] )
      break;
    if ( BYTE1(v4) == 0 )
      break;
    v5 = HIWORD(v4);
    if ( (_BYTE)v5 != v3[2] )
      break;
    if ( (_BYTE)v5 == 0 )
      break;
    if ( BYTE1(v5) != v3[3] )
      break;
    v3 += 4;
    v2 += 4;
  }
  while ( BYTE1(v5) != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10025928
// Name: _abort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn abort()
{
  if ( __get_sigabrt() != nullptr )
    raise(signum: 22);
  if ( (__abort_behavior & 2) != 0 )
    _call_reportfault(nDbgHookCode: 3, dwExceptionCode: 0x40000015u, dwExceptionFlags: 1u);
  _exit(code: 3);
}

//------------------------------------------------------------------------------
// Address: 0x1002595B
// Name: __set_abort_behavior
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _set_abort_behavior(unsigned int flags, unsigned int mask)
{
  unsigned int result; // eax

  result = __abort_behavior;
  __abort_behavior = mask & flags | __abort_behavior & ~mask;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002597C
// Name: __GET_RTERRMSG
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const wchar_t *__cdecl _GET_RTERRMSG(int rterrnum)
{
  int v1; // eax

  v1 = 0;
  while ( rterrnum != rterrs[v1].rterrno )
  {
    if ( (unsigned int)++v1 >= 0x16 )
      return nullptr;
  }
  return rterrs[v1].rterrtxt;
}

//------------------------------------------------------------------------------
// Address: 0x100259A2
// Name: __NMSG_WRITE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _NMSG_WRITE(int rterrnum)
{
  const wchar_t *v1; // edi
  int v2; // eax
  HANDLE StdHandle; // eax
  void *v4; // esi
  unsigned int i; // eax
  DWORD v6; // eax
  unsigned int bytes_written; // [esp+Ch] [ebp-1FCh] BYREF
  char buffer[500]; // [esp+10h] [ebp-1F8h] BYREF

  v1 = _GET_RTERRMSG(rterrnum);
  bytes_written = (unsigned int)v1;
  if ( v1 != nullptr )
  {
    if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
    {
      StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF4);
      v4 = StdHandle;
      if ( StdHandle != nullptr && StdHandle != (HANDLE)-1 )
      {
        for ( i = 0; i < 0x1F4; ++i )
        {
          buffer[i] = v1[i];
          if ( v1[i] == 0 )
            break;
        }
        buffer[499] = 0;
        strlen(buf: (unsigned __int8 *)buffer);
        WriteFile(
          hFile: v4,
          lpBuffer: buffer,
          nNumberOfBytesToWrite: v6,
          lpNumberOfBytesWritten: &bytes_written,
          lpOverlapped: nullptr);
      }
    }
    else if ( rterrnum != 252 )
    {
      if ( wcscpy_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: L"Runtime Error!\n\nProgram: ") != 0 )
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      outmsg[285] = 0;
      if ( GetModuleFileNameW(hModule: nullptr, lpFilename: &outmsg[25], nSize: 0x104u) == 0
        && wcscpy_s(_Dst: &outmsg[25], _SizeInWords: 0x2FBu, _Src: L"<program name unknown>") != 0
        || (unsigned int)(wcslen(wcs: &outmsg[25]) + 1) > 0x3C
        && (v2 = wcslen(wcs: &outmsg[25]),
            wcsncpy_s(
              _Dst: (unsigned __int16 *)&_exitflag + v2,
              _SizeInWords: 763 - ((&_exitflag + 2 * v2 - (char *)&outmsg[25]) >> 1),
              _Src: L"...",
              _Count: 3u) != 0)
        || wcscat_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: L"\n\n") != 0
        || wcscat_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: (const wchar_t *)bytes_written) != 0 )
      {
        _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      }
      __crtMessageBoxW(lpText: outmsg, lpCaption: L"Microsoft Visual C++ Runtime Library", uType: 0x12010u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025B51
// Name: __FF_MSGBANNER
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _FF_MSGBANNER()
{
  if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
  {
    _NMSG_WRITE(rterrnum: 252);
    _NMSG_WRITE(rterrnum: 255);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025B8A
// Name: __initp_misc_purevirt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_purevirt(void *enull)
{
  __pPurecall = enull;
}

//------------------------------------------------------------------------------
// Address: 0x10025B99
// Name: __forcdecpt_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt_l(char *buffer, localeinfo_struct *_Locale)
{
  char *v2; // esi
  bool i; // zf
  char v4; // al
  char *v5; // esi
  char v6; // cl
  char v7; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: _Locale);
  v2 = buffer;
  for ( i = tolower(c: *buffer) == 101; !i; i = isdigit(c: (unsigned __int8)*v2) == 0 )
    ++v2;
  if ( tolower(c: *v2) == 120 )
    v2 += 2;
  v4 = *v2;
  *v2 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
  v5 = v2 + 1;
  do
  {
    v6 = *v5;
    *v5 = v4;
    v4 = v6;
    v7 = *v5++;
  }
  while ( v7 != 0 );
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x10025C0D
// Name: __cropzeros_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros_l(char *buf, localeinfo_struct *_Locale)
{
  char *v2; // eax
  char i; // cl
  char v4; // cl
  char *v5; // eax
  char v6; // cl
  char *v7; // edx
  char v8; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: _Locale);
  v2 = buf;
  for ( i = *buf; *v2 != 0; i = *++v2 )
  {
    if ( i == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      break;
  }
  v4 = *v2;
  v5 = v2 + 1;
  if ( v4 != 0 )
  {
    while ( 1 )
    {
      v6 = *v5;
      if ( *v5 == 0 || v6 == 101 || v6 == 69 )
        break;
      ++v5;
    }
    v7 = v5;
    do
      --v5;
    while ( *v5 == 48 );
    if ( *v5 == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      --v5;
    do
    {
      v8 = *v7;
      ++v5;
      ++v7;
      *v5 = v8;
    }
    while ( v8 != 0 );
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x10025C8F
// Name: __positive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _positive(long double *arg)
{
  return *arg >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10025CAB
// Name: __fassign_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign_l(_CRT_FLOAT flag, char *argument, char *number, localeinfo_struct *plocinfo)
{
  _CRT_DOUBLE doubletemp; // [esp+0h] [ebp-8h] BYREF

  if ( LODWORD(flag.f) != 0 )
  {
    _atodbl_l(d: &doubletemp, str: number, plocinfo);
    *(_CRT_DOUBLE *)argument = doubletemp;
  }
  else
  {
    _atoflt_l(d: &flag, str: number, plocinfo);
    *(_CRT_FLOAT *)argument = flag;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025CED
// Name: __fassign
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign(int flag, char *argument, char *number)
{
  _fassign_l((_CRT_FLOAT)flag, argument, number, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10025D07
// Name: _shift
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shift(char *s@<eax>, int dist@<edi>)
{
  int v3; // eax

  if ( dist != 0 )
  {
    strlen(buf: (unsigned __int8 *)s);
    memmove(dst: (unsigned __int8 *)&s[dist], src: (unsigned __int8 *)s, count: v3 + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025D26
// Name: __forcdecpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt(char *buffer)
{
  _forcdecpt_l(buffer, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10025D39
// Name: __cropzeros
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros(char *buf)
{
  _cropzeros_l(buf, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10025D4C
// Name: _cftoe2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cftoe2_l@<eax>(
        char *buf@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        _strflt *pflt,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int *v8; // eax
  int v10; // eax
  char *v11; // esi
  threadlocaleinfostruct *locinfo; // eax
  char *v13; // esi
  unsigned int v14; // ebx
  int v15; // eax
  int v16; // [esp-4h] [ebp-1Ch]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v8 = _errno();
    v16 = 22;
LABEL_3:
    *v8 = v16;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v16;
  }
  if ( ndec <= 0 )
    v10 = 0;
  else
    v10 = ndec;
  if ( sizeInBytes <= v10 + 9 )
  {
    v8 = _errno();
    v16 = 34;
    goto LABEL_3;
  }
  if ( g_fmt != 0 )
    shift(s: &buf[pflt->sign == 45], dist: ndec > 0);
  v11 = buf;
  if ( pflt->sign == 45 )
  {
    *buf = 45;
    v11 = buf + 1;
  }
  if ( ndec > 0 )
  {
    locinfo = _loc_update.localeinfo.locinfo;
    *v11 = v11[1];
    *++v11 = *locinfo->lconv->decimal_point;
  }
  v13 = &v11[ndec + (g_fmt == 0)];
  if ( sizeInBytes == -1 )
    v14 = -1;
  else
    v14 = sizeInBytes + buf - v13;
  if ( strcpy_s(_Dst: v13, _SizeInBytes: v14, _Src: "e+000") != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  if ( caps != 0 )
    *v13 = 69;
  if ( *pflt->mantissa != 48 )
  {
    v15 = pflt->decpt - 1;
    if ( v15 < 0 )
    {
      v15 = 1 - pflt->decpt;
      v13[1] = 45;
    }
    if ( v15 >= 100 )
    {
      v13[2] += v15 / 100;
      v15 %= 100;
    }
    if ( v15 >= 10 )
    {
      v13[3] += v15 / 10;
      LOBYTE(v15) = v15 % 10;
    }
    v13[4] += v15;
  }
  if ( (_outputformat & 1) != 0 && v13[2] == 48 )
    memmove(dst: (unsigned __int8 *)v13 + 2, src: (unsigned __int8 *)v13 + 3, count: 3u);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10025EAD
// Name: __cftoe_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoe_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v7; // eax
  _strflt retstrflt; // [esp+Ch] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v7 = sizeInBytes, sizeInBytes != 0) )
  {
    if ( sizeInBytes != -1 )
      v7 = sizeInBytes - (retstrflt.sign == 45) - (ndec > 0);
    result = _fptostr(
               buf: &buf[(retstrflt.sign == 45) + (ndec > 0)],
               sizeInBytes: v7,
               digits: ndec + 1,
               pflt: &retstrflt);
    if ( result != 0 )
      *buf = 0;
    else
      return cftoe2_l(buf, sizeInBytes, ndec, caps, pflt: &retstrflt, g_fmt: 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10025F74
// Name: __cftoe
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoe(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, int caps)
{
  return _cftoe_l(pvalue, buf, sizeInBytes, ndec, caps, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10025F94
// Name: __cftoa_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoa_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  char *v6; // esi
  int *v7; // eax
  int result; // eax
  unsigned int v9; // eax
  bool v10; // zf
  _BYTE *v11; // eax
  char *v12; // esi
  char *v13; // eax
  char *v14; // esi
  int x_low; // eax
  unsigned int v16; // eax
  unsigned int v17; // ecx
  char *i; // eax
  __int64 v19; // rax
  __int64 v20; // rcx
  _BYTE *v21; // esi
  _BYTE *v22; // edi
  __int64 v23; // rax
  __int64 v24; // rcx
  __int64 v25; // rax
  __int64 v26; // rcx
  __int64 v27; // rcx
  __int64 v28; // [esp-Ch] [ebp-38h]
  int v29; // [esp-4h] [ebp-30h]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-24h] BYREF
  __int64 exponent; // [esp+18h] [ebp-14h]
  unsigned __int64 mask; // [esp+20h] [ebp-Ch]
  int maskpos; // [esp+28h] [ebp-4h]
  char *pos; // [esp+38h] [ebp+Ch]

  LODWORD(exponent) = 1023;
  maskpos = 48;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( ndec < 0 )
    ndec = 0;
  v6 = buf;
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v7 = _errno();
    v29 = 22;
LABEL_5:
    *v7 = v29;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v29;
  }
  *buf = 0;
  if ( sizeInBytes <= ndec + 11 )
  {
    v7 = _errno();
    v29 = 34;
    goto LABEL_5;
  }
  LODWORD(mask) = LODWORD(pvalue->x);
  if ( ((HIDWORD(pvalue->x) >> 20) & 0x7FF) == 0x7FF )
  {
    v9 = sizeInBytes;
    if ( sizeInBytes != -1 )
      v9 = sizeInBytes - 2;
    result = _cftoe(pvalue, buf: buf + 2, sizeInBytes: v9, ndec, caps: 0);
    if ( result != 0 )
    {
      v10 = !_loc_update.updated;
      *buf = 0;
      if ( !v10 )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    if ( buf[2] == 45 )
    {
      *buf = 45;
      v6 = buf + 1;
    }
    *v6 = 48;
    v6[1] = caps == 0 ? 120 : 88;
    strrchr(string: (unsigned __int8 *)v6 + 2, chr: 0x65u);
    if ( v11 != nullptr )
    {
      *v11 = caps == 0 ? 112 : 80;
      v11[3] = 0;
    }
  }
  else
  {
    if ( (HIDWORD(pvalue->x) & 0x80000000) != 0 )
    {
      *buf = 45;
      v6 = buf + 1;
    }
    *v6 = 48;
    v6[1] = caps == 0 ? 120 : 88;
    if ( (HIDWORD(pvalue->x) & 0x7FF00000) != 0 )
    {
      v6[2] = 49;
      v12 = v6 + 3;
    }
    else
    {
      v6[2] = 48;
      v12 = v6 + 3;
      if ( (HIDWORD(pvalue->x) & 0xFFFFF | LODWORD(pvalue->x)) != 0 )
        LODWORD(exponent) = 1022;
      else
        LODWORD(exponent) = 0;
    }
    v13 = v12;
    v14 = v12 + 1;
    pos = v13;
    if ( ndec != 0 )
      *v13 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
    else
      *v13 = 0;
    x_low = LODWORD(pvalue->x);
    HIDWORD(mask) = HIDWORD(pvalue->x) & 0xFFFFF;
    if ( HIDWORD(mask) != 0 || x_low != 0 )
    {
      mask = 0xF000000000000LL;
      do
      {
        if ( ndec <= 0 )
          break;
        v16 = (unsigned __int16)(((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) + 48);
        if ( v16 > 0x39 )
          LOBYTE(v16) = (caps != 0 ? 7 : 39) + ((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) + 48;
        v17 = HIDWORD(mask);
        maskpos -= 4;
        *v14++ = v16;
        --ndec;
        mask = __PAIR64__(v17, mask) >> 4;
      }
      while ( (maskpos & 0x8000u) == 0 );
      if ( (maskpos & 0x8000u) == 0
        && (unsigned __int16)((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) > 8u )
      {
        for ( i = v14 - 1; *i == 102 || *i == 70; --i )
          *i = 48;
        if ( i == pos )
        {
          ++*(i - 1);
        }
        else if ( *i == 57 )
        {
          *i = caps != 0 ? 65 : 97;
        }
        else
        {
          ++*i;
        }
      }
    }
    if ( ndec > 0 )
    {
      memset(dst: (int)v14, value: (unsigned __int8 *)0x30, count: ndec);
      v14 += ndec;
    }
    if ( *pos == 0 )
      v14 = pos;
    *v14 = caps == 0 ? 112 : 80;
    HIDWORD(v20) = 0;
    v19 = ((*(_QWORD *)&pvalue->x >> 52) & 0x7FFLL) - (unsigned int)exponent;
    if ( v19 < 0 )
    {
      v14[1] = 45;
      v21 = v14 + 2;
      v19 = -v19;
    }
    else
    {
      v14[1] = 43;
      v21 = v14 + 2;
    }
    v22 = v21;
    *v21 = 48;
    if ( v19 >= 0 )
    {
      LODWORD(v20) = 1000;
      if ( v19 >= 1000 )
      {
        v28 = v20;
        v24 = v19 % v20;
        v23 = v19 / v28;
        *v21++ = v23 + 48;
        HIDWORD(exponent) = HIDWORD(v23);
        v19 = v24;
        if ( v21 != v22 )
          goto LABEL_60;
      }
    }
    if ( v19 >= 100 )
    {
LABEL_60:
      v26 = v19 % 100;
      v25 = v19 / 100;
      *v21 = v25 + 48;
      HIDWORD(exponent) = HIDWORD(v25);
      ++v21;
      v19 = v26;
    }
    if ( v21 != v22 || v19 >= 10 )
    {
      v27 = v19 % 10;
      *v21++ = v19 / 10 + 48;
      LOBYTE(v19) = v19 % 10;
      HIDWORD(exponent) = HIDWORD(v27);
    }
    *v21 = v19 + 48;
    v21[1] = 0;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002630A
// Name: _cftof2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cftof2_l@<eax>(
        char *buf@<ecx>,
        _strflt *pflt@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int v8; // esi
  char *v10; // esi
  int decpt; // eax
  int v12; // eax
  unsigned __int8 *v13; // esi
  int v14; // eax
  int v15; // edi
  int v16; // edi
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  v8 = pflt->decpt - 1;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    if ( g_fmt != 0 && v8 == ndec )
      *(_WORD *)&buf[v8 + (pflt->sign == 45)] = 48;
    v10 = buf;
    if ( pflt->sign == 45 )
    {
      *buf = 45;
      v10 = buf + 1;
    }
    decpt = pflt->decpt;
    if ( decpt > 0 )
    {
      v13 = (unsigned __int8 *)&v10[decpt];
    }
    else
    {
      strlen(buf: (unsigned __int8 *)v10);
      memmove(dst: (unsigned __int8 *)v10 + 1, src: (unsigned __int8 *)v10, count: v12 + 1);
      *v10 = 48;
      v13 = (unsigned __int8 *)(v10 + 1);
    }
    if ( ndec > 0 )
    {
      strlen(buf: v13);
      memmove(dst: v13 + 1, src: v13, count: v14 + 1);
      *v13 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
      v15 = pflt->decpt;
      if ( v15 < 0 )
      {
        v16 = -v15;
        if ( g_fmt != 0 || ndec >= v16 )
          ndec = v16;
        shift(s: (char *)v13 + 1, dist: ndec);
        memset(dst: (int)(v13 + 1), value: (unsigned __int8 *)0x30, count: ndec);
      }
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002640D
// Name: __cftof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftof_l(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v6; // eax
  _strflt retstrflt; // [esp+8h] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+18h] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    v6 = -1;
    if ( sizeInBytes != -1 )
      v6 = sizeInBytes - (retstrflt.sign == 45);
    result = _fptostr(
               buf: &buf[retstrflt.sign == 45],
               sizeInBytes: v6,
               digits: ndec + retstrflt.decpt,
               pflt: &retstrflt);
    if ( result != 0 )
      *buf = 0;
    else
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100264CE
// Name: __cftog_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftog_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  BOOL v9; // eax
  char *v10; // edi
  _strflt retstrflt; // [esp+8h] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+18h] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v7 = sizeInBytes, sizeInBytes != 0) )
  {
    v8 = retstrflt.decpt - 1;
    v9 = retstrflt.sign == 45;
    v10 = &buf[v9];
    if ( sizeInBytes != -1 )
      v7 = sizeInBytes - v9;
    result = _fptostr(buf: v10, sizeInBytes: v7, digits: ndec, pflt: &retstrflt);
    if ( result != 0 )
    {
      *buf = 0;
    }
    else if ( retstrflt.decpt - 1 < -4 || retstrflt.decpt - 1 >= ndec )
    {
      return cftoe2_l(buf, sizeInBytes, ndec, caps, pflt: &retstrflt, g_fmt: 1, plocinfo);
    }
    else
    {
      if ( v8 < retstrflt.decpt - 1 )
        v10[strlen(v10) - 1] = 0;
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 1, plocinfo);
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10026689
// Name: __setdefaultprecision
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _setdefaultprecision()
{
  int result; // eax

  result = _controlfp_s(_CurrentState: nullptr, newctrl: 0x10000u, mask: 0x30000u);
  if ( result != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100266C0
// Name: _strlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strlen(char *buf)
{
  char *v1; // ecx
  char v2; // al
  int v3; // eax
  int v4; // eax

  v1 = buf;
  if ( ((unsigned __int8)buf & 3) != 0 )
  {
    while ( 1 )
    {
      v2 = *v1++;
      if ( v2 == 0 )
        break;
      if ( ((unsigned __int8)v1 & 3) == 0 )
        goto main_loop_3;
    }
  }
  else
  {
    do
    {
      do
      {
main_loop_3:
        v3 = (*(_DWORD *)v1 + 2130640639) ^ ~*(_DWORD *)v1;
        v1 += 4;
      }
      while ( (v3 & 0x81010100) == 0 );
      v4 = *((_DWORD *)v1 - 1);
    }
    while ( (_BYTE)v4 != 0 && BYTE1(v4) != 0 && (v4 & 0xFF0000) != 0 && (v4 & 0xFF000000) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002674B
// Name: __fullpath
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _fullpath(char *UserBuf, const char *path, DWORD maxlen)
{
  DWORD FullPathNameA; // eax
  DWORD LastError; // eax
  unsigned int v6; // edi
  unsigned __int8 *v7; // eax
  char *v8; // ebx
  DWORD v9; // eax
  char *pfname; // [esp+Ch] [ebp-4h] BYREF

  if ( path == nullptr || *path == 0 )
    return _getcwd(pnbuf: UserBuf, maxlen);
  if ( UserBuf != nullptr )
  {
    v6 = maxlen;
    if ( maxlen == 0 )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
    v8 = UserBuf;
  }
  else
  {
    FullPathNameA = GetFullPathNameA(lpFileName: path, nBufferLength: 0, lpBuffer: nullptr, lpFilePart: nullptr);
    if ( FullPathNameA == 0 )
    {
LABEL_5:
      LastError = GetLastError();
      _dosmaperr(oserrno: LastError);
      return nullptr;
    }
    v6 = maxlen;
    if ( maxlen <= FullPathNameA )
      v6 = FullPathNameA;
    v7 = calloc(count: v6, size: 1u);
    v8 = (char *)v7;
    if ( v7 == nullptr )
    {
      *_errno() = 12;
      return nullptr;
    }
  }
  v9 = GetFullPathNameA(lpFileName: path, nBufferLength: v6, lpBuffer: v8, lpFilePart: &pfname);
  if ( v9 >= v6 )
  {
    if ( UserBuf == nullptr )
      free(pMem: v8);
    *_errno() = 34;
    return nullptr;
  }
  if ( v9 == 0 )
  {
    if ( UserBuf == nullptr )
      free(pMem: v8);
    goto LABEL_5;
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10026842
// Name: __get_errno_from_oserr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_errno_from_oserr(unsigned int oserrno)
{
  unsigned int i; // ecx

  for ( i = 0; i < 0x2D; ++i )
  {
    if ( oserrno == errtable[i].oscode )
      return errtable[i].errnocode;
  }
  if ( oserrno - 19 > 0x11 )
    return oserrno - 188 > 0xE ? 22 : 8;
  else
    return 13;
}

//------------------------------------------------------------------------------
// Address: 0x10026884
// Name: __errno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl _errno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_terrno;
  else
    return &ErrnoNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x10026897
// Name: ___doserrno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int *__cdecl __doserrno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_tdoserrno;
  else
    return &DoserrorNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x100268AA
// Name: __dosmaperr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _dosmaperr(unsigned int oserrno)
{
  int errno_from_oserr; // esi

  *__doserrno() = oserrno;
  errno_from_oserr = _get_errno_from_oserr(oserrno);
  *_errno() = errno_from_oserr;
}

//------------------------------------------------------------------------------
// Address: 0x100268CD
// Name: ___dtoxmode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl __dtoxmode(char attr, char *name)
{
  const char *v2; // ecx
  char v3; // dl
  int v4; // edi
  unsigned int v5; // edi
  const unsigned __int8 *v6; // eax
  const unsigned __int8 *v7; // esi

  v2 = name;
  if ( name[1] == 58 )
    v2 = name + 2;
  v3 = *v2;
  if ( (*v2 == 92 || v3 == 47) && v2[1] == 0 || (attr & 0x10) != 0 || (v4 = 0x8000, v3 == 0) )
    v4 = 16448;
  v5 = ~(attr << 7) & 0x80 | 0x100 | v4;
  _mbsrchr(str: (unsigned __int8 *)name, c: 0x2Eu);
  v7 = v6;
  if ( v6 != nullptr
    && (_mbsicmp(s1: v6, s2: ".exe") == 0
     || _mbsicmp(s1: v7, s2: ".cmd") == 0
     || _mbsicmp(s1: v7, s2: ".bat") == 0
     || _mbsicmp(s1: v7, s2: ".com") == 0) )
  {
    v5 |= 0x40u;
  }
  return (v5 >> 3) & 0x38 | v5 | (((v5 >> 3) & 0x38 | v5) >> 6) & 7;
}

//------------------------------------------------------------------------------
// Address: 0x1002698A
// Name: __close_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _close_nolock(int fh)
{
  int osfhandle; // edi
  void *v2; // eax
  DWORD LastError; // edi

  if ( _get_osfhandle(fh) == -1
    || (fh == 1 && (__pioinfo[0][2].osfile & 1) != 0 || fh == 2 && (__pioinfo[0][1].osfile & 1) != 0)
    && (osfhandle = _get_osfhandle(fh: 2), _get_osfhandle(fh: 1) == osfhandle)
    || (v2 = (void *)_get_osfhandle(fh), CloseHandle(hObject: v2)) )
  {
    LastError = 0;
  }
  else
  {
    LastError = GetLastError();
  }
  _free_osfhnd(fh);
  __pioinfo[fh >> 5][fh & 0x1F].osfile = 0;
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10026A26
// Name: __close
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _close(int fh)
{
  ioinfo **v2; // edi
  int v3; // esi
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v2 = &__pioinfo[fh >> 5], v3 = (fh & 0x1F) << 6, (*(&(*v2)->osfile + v3) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v2)->osfile + v3) & 1) != 0 )
  {
    r = _close_nolock(fh);
  }
  else
  {
    *_errno() = 9;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x10026AEA
// Name: __fstat64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fstat64i32(int fildes, _stat64i32 *buf)
{
  int v3; // edi
  DWORD v4; // eax
  DWORD LastError; // eax
  unsigned __int16 v6; // cx
  unsigned int v7; // ecx
  BOOL v8; // eax
  unsigned __int16 st_mode; // ax
  unsigned __int16 v10; // ax
  _FILETIME LocalFileTime; // [esp+14h] [ebp-74h] BYREF
  int fh; // [esp+1Ch] [ebp-6Ch]
  unsigned int TotalBytesAvail; // [esp+20h] [ebp-68h] BYREF
  int v14; // [esp+24h] [ebp-64h]
  _BY_HANDLE_FILE_INFORMATION FileInformation; // [esp+28h] [ebp-60h] BYREF
  _SYSTEMTIME SystemTime; // [esp+5Ch] [ebp-2Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+70h] [ebp-18h]

  fh = fildes;
  v14 = 0;
  if ( buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
LABEL_3:
    _invalid_parameter_noinfo();
    return -1;
  }
  memset(dst: (int)buf, value: nullptr, count: sizeof(_stat64i32));
  if ( fildes == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fildes < 0
    || fildes >= _nhandle
    || (TotalBytesAvail = (unsigned int)&__pioinfo[fildes >> 5],
        v3 = (fildes & 0x1F) << 6,
        (*(_BYTE *)(*(_DWORD *)TotalBytesAvail + v3 + 4) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    goto LABEL_3;
  }
  __lock_fhandle(fh);
  ms_exc.registration.TryLevel = 0;
  if ( (*(_BYTE *)(*(_DWORD *)TotalBytesAvail + v3 + 4) & 1) == 0 )
    goto LABEL_12;
  v4 = GetFileType(hFile: *(HANDLE *)(*(_DWORD *)TotalBytesAvail + ((fildes & 0x1F) << 6))) & 0xFFFF7FFF;
  switch ( v4 )
  {
    case 1u:
      buf->st_mode = 0;
      buf->st_gid = 0;
      buf->st_uid = 0;
      buf->st_ino = 0;
      buf->st_nlink = 1;
      if ( GetFileInformationByHandle(
             hFile: *(HANDLE *)(*(_DWORD *)TotalBytesAvail + ((fildes & 0x1F) << 6)),
             lpFileInformation: &FileInformation) )
      {
        st_mode = buf->st_mode;
        if ( (FileInformation.dwFileAttributes & 1) != 0 )
          v10 = st_mode | 0x124;
        else
          v10 = st_mode | 0x1B6;
        buf->st_mode = v10;
        if ( FileInformation.ftLastWriteTime.dwLowDateTime != 0 || FileInformation.ftLastWriteTime.dwHighDateTime != 0 )
        {
          if ( !FileTimeToLocalFileTime(lpFileTime: &FileInformation.ftLastWriteTime, lpLocalFileTime: &LocalFileTime)
            || !FileTimeToSystemTime(lpFileTime: &LocalFileTime, lpSystemTime: &SystemTime) )
          {
            goto LABEL_13;
          }
          buf->st_mtime = __loctotime64_t(
                            yr: SystemTime.wYear,
                            mo: SystemTime.wMonth,
                            dy: SystemTime.wDay,
                            hr: SystemTime.wHour,
                            mn: SystemTime.wMinute,
                            sc: SystemTime.wSecond,
                            dstflag: -1);
        }
        else
        {
          buf->st_mtime = 0;
        }
        if ( FileInformation.ftLastAccessTime.dwLowDateTime != 0 || FileInformation.ftLastAccessTime.dwHighDateTime != 0 )
        {
          if ( !FileTimeToLocalFileTime(lpFileTime: &FileInformation.ftLastAccessTime, lpLocalFileTime: &LocalFileTime)
            || !FileTimeToSystemTime(lpFileTime: &LocalFileTime, lpSystemTime: &SystemTime) )
          {
            goto LABEL_13;
          }
          buf->st_atime = __loctotime64_t(
                            yr: SystemTime.wYear,
                            mo: SystemTime.wMonth,
                            dy: SystemTime.wDay,
                            hr: SystemTime.wHour,
                            mn: SystemTime.wMinute,
                            sc: SystemTime.wSecond,
                            dstflag: -1);
        }
        else
        {
          buf->st_atime = buf->st_mtime;
        }
        if ( FileInformation.ftCreationTime.dwLowDateTime != 0 || FileInformation.ftCreationTime.dwHighDateTime != 0 )
        {
          if ( !FileTimeToLocalFileTime(lpFileTime: &FileInformation.ftCreationTime, lpLocalFileTime: &LocalFileTime)
            || !FileTimeToSystemTime(lpFileTime: &LocalFileTime, lpSystemTime: &SystemTime) )
          {
            goto LABEL_13;
          }
          buf->st_ctime = __loctotime64_t(
                            yr: SystemTime.wYear,
                            mo: SystemTime.wMonth,
                            dy: SystemTime.wDay,
                            hr: SystemTime.wHour,
                            mn: SystemTime.wMinute,
                            sc: SystemTime.wSecond,
                            dstflag: -1);
        }
        else
        {
          buf->st_ctime = buf->st_mtime;
        }
        buf->st_size = FileInformation.nFileSizeLow;
        buf->st_mode |= 0x8000u;
        buf->st_dev = 0;
        buf->st_rdev = 0;
        goto done_1;
      }
      goto LABEL_19;
    case 2u:
      v6 = 0x2000;
LABEL_22:
      buf->st_mode = v6;
      v7 = fh;
      buf->st_dev = fh;
      buf->st_rdev = v7;
      buf->st_nlink = 1;
      buf->st_ino = 0;
      buf->st_gid = 0;
      buf->st_uid = 0;
      buf->st_ctime = 0;
      buf->st_mtime = 0;
      buf->st_atime = 0;
      if ( v4 == 2 )
      {
        buf->st_size = 0;
      }
      else
      {
        v8 = PeekNamedPipe(
               hNamedPipe: *(HANDLE *)(*(_DWORD *)TotalBytesAvail + ((fildes & 0x1F) << 6)),
               lpBuffer: nullptr,
               nBufferSize: 0,
               lpBytesRead: nullptr,
               lpTotalBytesAvail: &TotalBytesAvail,
               lpBytesLeftThisMessage: nullptr);
        buf->st_size = v8 ? TotalBytesAvail : 0;
      }
      goto done_1;
    case 3u:
      v6 = 4096;
      goto LABEL_22;
    default:
      break;
  }
  if ( v4 != 0 )
  {
LABEL_19:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    goto LABEL_13;
  }
LABEL_12:
  *_errno() = 9;
LABEL_13:
  v14 = -1;
done_1:
  ms_exc.registration.TryLevel = -2;
  _unlock_fhandle(fh);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x10026E3C
// Name: _tsopen_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall tsopen_nolock@<eax>(
        int *pfh@<eax>,
        int *punlock_flag,
        const char *path,
        int oflag,
        int shflag,
        char pmode)
{
  unsigned int v7; // eax
  int v9; // eax
  char *v10; // eax
  DWORD v11; // eax
  DWORD FileType; // eax
  char *p_osfile; // eax
  DWORD LastError; // esi
  char v15; // cl
  _BYTE *v16; // eax
  signed int v17; // edi
  int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  int v21; // edi
  doubleint v22; // rax
  int nolock; // eax
  doubleint v24; // rax
  unsigned int v25; // eax
  int v26; // ebx
  int v27; // eax
  _BYTE *v28; // eax
  _BYTE *v29; // eax
  bool v30; // zf
  char *v31; // eax
  HANDLE v32; // eax
  DWORD v33; // eax
  char *v34; // eax
  int v35; // [esp-10h] [ebp-48h]
  DWORD v36; // [esp-Ch] [ebp-44h]
  int v37; // [esp-8h] [ebp-40h]
  _SECURITY_ATTRIBUTES SecurityAttributes; // [esp+8h] [ebp-30h] BYREF
  int fmode; // [esp+14h] [ebp-24h] BYREF
  void *osfh; // [esp+18h] [ebp-20h]
  int bom; // [esp+1Ch] [ebp-1Ch] BYREF
  unsigned int filecreate; // [esp+20h] [ebp-18h]
  unsigned int fileshare; // [esp+24h] [ebp-14h]
  unsigned int fileattrib; // [esp+28h] [ebp-10h]
  unsigned int fileaccess; // [esp+2Ch] [ebp-Ch]
  int retvalue; // [esp+30h] [ebp-8h]
  char inputbuf; // [esp+34h] [ebp-4h] BYREF
  char v48; // [esp+35h] [ebp-3h]
  char tmode; // [esp+36h] [ebp-2h]
  char fileflags; // [esp+37h] [ebp-1h]

  fmode = 0;
  tmode = 0;
  retvalue = 0;
  SecurityAttributes.nLength = 12;
  SecurityAttributes.lpSecurityDescriptor = nullptr;
  if ( (oflag & 0x80u) == 0 )
  {
    SecurityAttributes.bInheritHandle = 1;
    fileflags = 0;
  }
  else
  {
    SecurityAttributes.bInheritHandle = 0;
    fileflags = 16;
  }
  if ( _get_fmode(pMode: &fmode) != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  if ( (oflag & 0x8000) == 0 && ((oflag & 0x74000) != 0 || fmode != 0x8000) )
    fileflags |= 0x80u;
  if ( (oflag & 3) != 0 )
  {
    if ( (oflag & 3) != 1 )
    {
      if ( (oflag & 3) != 2 )
        goto LABEL_40;
      goto LABEL_13;
    }
    if ( (oflag & 8) != 0 && (oflag & 0x70000) != 0 )
    {
LABEL_13:
      fileaccess = -1073741824;
      goto LABEL_18;
    }
    fileaccess = 0x40000000;
  }
  else
  {
    fileaccess = 0x80000000;
  }
LABEL_18:
  switch ( shflag )
  {
    case 16:
      fileshare = 0;
      break;
    case 32:
      fileshare = 1;
      break;
    case 48:
      fileshare = 2;
      break;
    case 64:
      fileshare = 3;
      break;
    case 128:
      fileshare = fileaccess == 0x80000000;
      break;
    default:
      goto LABEL_40;
  }
  v7 = oflag & 0x700;
  if ( v7 > 0x400 )
  {
    if ( v7 != 1280 )
    {
      if ( v7 == 1536 )
        goto LABEL_41;
      if ( v7 != 1792 )
        goto LABEL_40;
    }
    filecreate = 1;
    goto LABEL_43;
  }
  if ( (oflag & 0x700) == 0x400 || (oflag & 0x700) == 0 )
  {
    filecreate = 3;
    goto LABEL_43;
  }
  if ( v7 == 256 )
  {
    filecreate = 4;
    goto LABEL_43;
  }
  if ( v7 == 512 )
  {
LABEL_41:
    filecreate = 5;
    goto LABEL_43;
  }
  if ( v7 != 768 )
  {
LABEL_40:
    *__doserrno() = 0;
    *pfh = -1;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  filecreate = 2;
LABEL_43:
  fileattrib = 128;
  if ( (oflag & 0x100) != 0 && (pmode & ~(_BYTE)_umaskval & 0x80u) == 0 )
    fileattrib = 1;
  if ( (oflag & 0x40) != 0 )
  {
    fileattrib |= 0x4000000u;
    fileaccess |= 0x10000u;
    fileshare |= 4u;
  }
  if ( (oflag & 0x1000) != 0 )
    fileattrib |= 0x100u;
  if ( (oflag & 0x20) != 0 )
  {
    fileattrib |= 0x8000000u;
  }
  else if ( (oflag & 0x10) != 0 )
  {
    fileattrib |= 0x10000000u;
  }
  v9 = _alloc_osfhnd();
  *pfh = v9;
  if ( v9 == -1 )
  {
    *__doserrno() = 0;
    *pfh = -1;
    *_errno() = 24;
    return *_errno();
  }
  v36 = fileattrib;
  *punlock_flag = 1;
  osfh = CreateFileA(
           lpFileName: path,
           dwDesiredAccess: fileaccess,
           dwShareMode: fileshare,
           lpSecurityAttributes: &SecurityAttributes,
           dwCreationDisposition: filecreate,
           dwFlagsAndAttributes: v36,
           hTemplateFile: nullptr);
  if ( osfh != (void *)-1
    || (fileaccess & 0xC0000000) == 0xC0000000
    && (oflag & 1) != 0
    && (fileaccess &= ~0x80000000,
        (osfh = CreateFileA(
                  lpFileName: path,
                  dwDesiredAccess: fileaccess,
                  dwShareMode: fileshare,
                  lpSecurityAttributes: &SecurityAttributes,
                  dwCreationDisposition: filecreate,
                  dwFlagsAndAttributes: fileattrib,
                  hTemplateFile: nullptr)) != (void *)-1) )
  {
    FileType = GetFileType(hFile: osfh);
    switch ( FileType )
    {
      case 0u:
        p_osfile = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
        *p_osfile &= ~1u;
        LastError = GetLastError();
        _dosmaperr(oserrno: LastError);
        CloseHandle(hObject: osfh);
        if ( LastError == 0 )
          *_errno() = 13;
        return *_errno();
      case 2u:
        fileflags |= 0x40u;
        break;
      case 3u:
        fileflags |= 8u;
        break;
      default:
        break;
    }
    _set_osfhnd(fh: *pfh, value: osfh);
    v15 = fileflags | 1;
    __pioinfo[*pfh >> 5][*pfh & 0x1F].osfile = fileflags | 1;
    v16 = (char *)&__pioinfo[*pfh >> 5][*pfh & 0x1F] + 36;
    *v16 &= 0x80u;
    v48 = v15 & 0x48;
    fileflags = v15;
    if ( (v15 & 0x48) == 0 )
    {
      if ( v15 >= 0 )
        goto LABEL_131;
      if ( (oflag & 2) != 0 )
      {
        v17 = _lseek_nolock(fh: *pfh, pos: -1, mthd: 2u);
        if ( v17 == -1 )
        {
          if ( *__doserrno() != 131 )
          {
LABEL_74:
            _close_nolock(fh: *pfh);
            return *_errno();
          }
        }
        else
        {
          v35 = *pfh;
          inputbuf = 0;
          if ( _read_nolock(fh: v35, &inputbuf, cnt: 1u) == 0
            && inputbuf == 26
            && _chsize_nolock(filedes: *pfh, size: v17) == -1
            || _lseek_nolock(fh: *pfh, pos: 0, mthd: 0) == -1 )
          {
            goto LABEL_74;
          }
        }
      }
    }
    if ( fileflags >= 0 )
    {
LABEL_131:
      v28 = (char *)&__pioinfo[*pfh >> 5][*pfh & 0x1F] + 36;
      *v28 ^= (tmode ^ *v28) & 0x7F;
      v29 = (char *)&__pioinfo[*pfh >> 5][*pfh & 0x1F] + 36;
      v30 = v48 == 0;
      *v29 = *v29 & 0x7F | (BYTE2(oflag) << 7);
      if ( v30 && (oflag & 8) != 0 )
      {
        v31 = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
        *v31 |= 0x20u;
      }
      if ( (fileaccess & 0xC0000000) != 0xC0000000 || (oflag & 1) == 0 )
        return retvalue;
      CloseHandle(hObject: osfh);
      v32 = CreateFileA(
              lpFileName: path,
              dwDesiredAccess: fileaccess & 0x7FFFFFFF,
              dwShareMode: fileshare,
              lpSecurityAttributes: &SecurityAttributes,
              dwCreationDisposition: 3u,
              dwFlagsAndAttributes: fileattrib,
              hTemplateFile: nullptr);
      if ( v32 != (HANDLE)-1 )
      {
        __pioinfo[*pfh >> 5][*pfh & 0x1F].osfhnd = (int)v32;
        return retvalue;
      }
      v33 = GetLastError();
      _dosmaperr(oserrno: v33);
      v34 = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
      *v34 &= ~1u;
      _free_osfhnd(fh: *pfh);
      return *_errno();
    }
    if ( (oflag & 0x74000) == 0 )
    {
      if ( (fmode & 0x74000) != 0 )
        oflag |= fmode & 0x74000;
      else
        oflag |= 0x4000u;
    }
    v18 = oflag & 0x74000;
    if ( (oflag & 0x74000) == 0x4000 )
    {
      tmode = 0;
      goto LABEL_95;
    }
    if ( v18 == 0x10000 || v18 == 81920 )
    {
      if ( (oflag & 0x301) != 0x301 )
        goto LABEL_95;
    }
    else if ( v18 != 0x20000 && v18 != 147456 )
    {
      if ( v18 == 0x40000 || v18 == 278528 )
        tmode = 1;
LABEL_95:
      if ( (oflag & 0x70000) == 0 )
        goto LABEL_131;
      bom = 0;
      if ( (fileflags & 0x40) != 0 )
        goto LABEL_131;
      v19 = fileaccess & 0xC0000000;
      if ( (fileaccess & 0xC0000000) == 0x40000000 )
      {
        v20 = filecreate;
        if ( filecreate == 0 )
          goto LABEL_131;
        if ( filecreate <= 2 )
          goto LABEL_104;
        if ( filecreate > 4 )
          goto LABEL_103;
        if ( _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 2u).bigint != 0 )
        {
          v24.bigint = _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 0).bigint;
          v25 = v24.twoints.upperhalf & v24.twoints.lowerhalf;
          goto LABEL_119;
        }
      }
      else
      {
        if ( v19 == 0x80000000 )
          goto LABEL_109;
        if ( v19 != -1073741824 )
          goto LABEL_131;
        v20 = filecreate;
        if ( filecreate == 0 )
          goto LABEL_131;
        if ( filecreate > 2 )
        {
          if ( filecreate > 4 )
          {
LABEL_103:
            if ( v20 != 5 )
              goto LABEL_131;
            goto LABEL_104;
          }
          if ( _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 2u).bigint != 0 )
          {
            v22.bigint = _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 0).bigint;
            if ( (v22.twoints.upperhalf & v22.twoints.lowerhalf) == -1 )
              goto LABEL_74;
LABEL_109:
            nolock = _read_nolock(fh: *pfh, inputbuf: (char *)&bom, cnt: 3u);
            if ( nolock == -1 )
              goto LABEL_74;
            if ( nolock != 2 )
            {
              if ( nolock != 3 )
              {
LABEL_126:
                v25 = _lseek_nolock(fh: *pfh, pos: 0, mthd: 0);
LABEL_119:
                if ( v25 == -1 )
                  goto LABEL_74;
                goto LABEL_131;
              }
              if ( bom == 12565487 )
              {
                tmode = 1;
                goto LABEL_131;
              }
            }
            if ( (unsigned __int16)bom == 65534 )
            {
              _close_nolock(fh: *pfh);
              *_errno() = 22;
              return 22;
            }
            if ( (unsigned __int16)bom == 65279 )
            {
              if ( _lseek_nolock(fh: *pfh, pos: 2, mthd: 0) == -1 )
                goto LABEL_74;
              tmode = 2;
              goto LABEL_131;
            }
            goto LABEL_126;
          }
        }
      }
LABEL_104:
      v21 = 0;
      if ( tmode == 1 )
      {
        bom = 12565487;
        v37 = 3;
LABEL_128:
        v26 = v37;
        while ( 1 )
        {
          v27 = _write(fh: *pfh, buf: (char *)&bom + v21, cnt: v26 - v21);
          if ( v27 == -1 )
            goto LABEL_74;
          v21 += v27;
          if ( v26 <= v21 )
            goto LABEL_131;
        }
      }
      if ( tmode == 2 )
      {
        bom = 65279;
        v37 = 2;
        goto LABEL_128;
      }
      goto LABEL_131;
    }
    tmode = 2;
    goto LABEL_95;
  }
  v10 = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
  *v10 &= ~1u;
  v11 = GetLastError();
  _dosmaperr(oserrno: v11);
  return *_errno();
}

//------------------------------------------------------------------------------
// Address: 0x10027570
// Name: __sopen_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sopen_helper(const char *path, int oflag, int shflag, int pmode, int *pfh, int bSecure)
{
  int result; // eax
  char *p_osfile; // eax
  int retval; // [esp+14h] [ebp-20h]
  int unlock_flag; // [esp+18h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  unlock_flag = 0;
  if ( pfh == nullptr || (*pfh = -1, path == nullptr) || bSecure != 0 && (pmode & 0xFFFFFE7F) != 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  else
  {
    ms_exc.registration.TryLevel = 0;
    retval = tsopen_nolock(pfh, punlock_flag: &unlock_flag, path, oflag, shflag, pmode);
    ms_exc.registration.TryLevel = -2;
    if ( unlock_flag != 0 )
    {
      if ( retval != 0 )
      {
        p_osfile = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
        *p_osfile &= ~1u;
      }
      _unlock_fhandle(fh: *pfh);
    }
    result = retval;
    if ( retval != 0 )
      *pfh = -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10027634
// Name: __sopen_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sopen_s(int *pfh, const char *path, int oflag, int shflag, int pmode)
{
  return _sopen_helper(path, oflag, shflag, pmode, pfh, bSecure: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10027654
// Name: ___loctotime64_t
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __loctotime64_t(int yr, int mo, int dy, unsigned int hr, unsigned int mn, unsigned int sc, int dstflag)
{
  int v7; // ebx
  int v8; // esi
  int *v9; // eax
  int v10; // ecx
  unsigned int v11; // edi
  int timezone; // [esp+Ch] [ebp-40h] BYREF
  int dstbias; // [esp+10h] [ebp-3Ch] BYREF
  int v15; // [esp+14h] [ebp-38h]
  int daylight; // [esp+18h] [ebp-34h] BYREF
  int v17; // [esp+1Ch] [ebp-30h]
  int tmpdays; // [esp+20h] [ebp-2Ch]
  tm tb; // [esp+24h] [ebp-28h] BYREF

  v7 = mo;
  v8 = yr - 1900;
  v15 = mo;
  daylight = 0;
  dstbias = 0;
  timezone = 0;
  if ( yr - 1900 < 70
    || v8 > 1100
    || (unsigned int)(mo - 1) > 0xB
    || hr > 0x17
    || mn > 0x3B
    || sc > 0x3B
    || dy < 1
    || (v9 = &_days[mo], v10 = *(v9 - 1), *v9 - v10 < dy)
    && ((v8 % 4 != 0 || v8 % 100 == 0) && yr % 400 != 0 || (v7 = v15, v15 != 2) || dy > 29) )
  {
    *_errno() = 22;
    return -1;
  }
  else
  {
    tmpdays = dy + v10;
    if ( (v8 % 4 == 0 && v8 % 100 != 0 || yr % 400 == 0) && v7 > 2 )
      ++tmpdays;
    __tzset();
    if ( _get_daylight(_Daylight: &daylight) != 0
      || _get_dstbias(_Daylight_savings_bias: &dstbias) != 0
      || _get_timezone(_Timezone: &timezone) != 0 )
    {
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    }
    v17 = (unsigned __int64)(365 * (v8 - 70LL) + (yr - 1900 + 299) / 400 - (yr - 1901) / 100 + (yr - 1901) / 4 - 17) >> 32;
    tb.tm_yday = tmpdays;
    v11 = sc
        + timezone
        + 60
        * (mn
         + 60
         * (hr + 24 * (tmpdays + 365 * (yr - 1970) + (yr - 1900 + 299) / 400 - (yr - 1901) / 100 + (yr - 1901) / 4 - 17)));
    tb.tm_year = yr - 1900;
    tb.tm_mon = v15 - 1;
    tb.tm_hour = hr;
    tb.tm_min = mn;
    tb.tm_sec = sc;
    if ( dstflag == 1 || dstflag == -1 && daylight != 0 && _isindst(&tb) != 0 )
      v11 += dstbias;
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100278BB
// Name: __getdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _getdrive()
{
  wchar_t *v0; // ebx
  signed int CurrentDirectoryW; // esi
  unsigned __int8 *v2; // eax
  unsigned int v3; // edi
  unsigned int v4; // eax
  int memfree; // [esp+10h] [ebp-214h]
  wchar_t curdirstr[262]; // [esp+14h] [ebp-210h] BYREF

  memfree = 0;
  v0 = curdirstr;
  CurrentDirectoryW = GetCurrentDirectoryW(nBufferLength: 0x105u, lpBuffer: curdirstr);
  if ( CurrentDirectoryW > 260 )
  {
    v2 = calloc(count: CurrentDirectoryW + 1, size: 2u);
    v0 = (wchar_t *)v2;
    if ( v2 != nullptr )
    {
      memfree = 1;
      CurrentDirectoryW = GetCurrentDirectoryW(nBufferLength: CurrentDirectoryW + 1, lpBuffer: (LPWSTR)v2);
    }
    else
    {
      *_errno() = 12;
      CurrentDirectoryW = 0;
    }
  }
  v3 = 0;
  if ( CurrentDirectoryW != 0 )
  {
    if ( v0[1] == 58 )
    {
      v4 = *v0;
      if ( v4 >= 0x61 && v4 <= 0x7A )
        v4 -= 32;
      v3 = v4 - 64;
    }
  }
  else
  {
    *_errno() = 12;
  }
  if ( memfree != 0 )
    free(pMem: v0);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10027989
// Name: __mbctolower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbctolower_l(unsigned int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  unsigned __int8 ret[4]; // [esp+14h] [ebp-8h] BYREF
  char val[4]; // [esp+18h] [ebp-4h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c <= 0xFF )
  {
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[c + 1] & 0x10) != 0 )
      result = _loc_update.localeinfo.mbcinfo->mbcasemap[c];
    else
      result = c;
LABEL_11:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  val[0] = BYTE1(c);
  val[1] = c;
  if ( (_loc_update.localeinfo.mbcinfo->mbctype[BYTE1(c) + 1] & 4) != 0
    && __crtLCMapStringA(
         plocinfo: &_loc_update.localeinfo,
         Locale: _loc_update.localeinfo.mbcinfo->mblcid,
         dwMapFlags: 0x100u,
         lpSrcStr: val,
         cchSrc: 2,
         lpDestStr: (char *)ret,
         cchDest: 2,
         code_page: _loc_update.localeinfo.mbcinfo->mbcodepage,
         bError: 1) != 0 )
  {
    result = ret[1] + (ret[0] << 8);
    goto LABEL_11;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x10027A2F
// Name: __mbctolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbctolower(unsigned int c)
{
  return _mbctolower_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10027A42
// Name: __mbspbrk_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbspbrk_l(unsigned __int8 *string, unsigned __int8 *charset, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // ecx
  unsigned __int8 *i; // eax
  unsigned __int8 v5; // dl
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    strpbrk(string, control: charset);
LABEL_22:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  v3 = string;
  if ( string != nullptr && charset != nullptr )
  {
    if ( *string != 0 )
    {
      do
      {
        for ( i = charset; *i != 0; ++i )
        {
          v5 = *i;
          if ( (_loc_update.localeinfo.mbcinfo->mbctype[*i + 1] & 4) != 0 )
          {
            if ( v5 == *v3 && i[1] == v3[1] || i[1] == 0 )
              break;
            ++i;
          }
          else if ( v5 == *v3 )
          {
            break;
          }
        }
        if ( *i != 0 )
          break;
        if ( (_loc_update.localeinfo.mbcinfo->mbctype[*v3 + 1] & 4) != 0 && *++v3 == 0 )
          break;
        ++v3;
      }
      while ( *v3 != 0 );
    }
    goto LABEL_22;
  }
  *_errno() = 22;
  _invalid_parameter_noinfo();
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x10027B07
// Name: __mbspbrk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbspbrk(unsigned __int8 *string, unsigned __int8 *charset)
{
  _mbspbrk_l(string, charset, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10027B1E
// Name: __initp_misc_invarg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_invarg(void *enull)
{
  __pInvalidArgHandler = enull;
}

//------------------------------------------------------------------------------
// Address: 0x10027B2D
// Name: __call_reportfault
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _call_reportfault(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        unsigned int nDbgHookCode,
        unsigned int dwExceptionCode,
        unsigned int dwExceptionFlags)
{
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // kr00_4
  BOOL v8; // edi
  _EXCEPTION_POINTERS ExceptionPointers; // [esp+8h] [ebp-328h] BYREF
  _EXCEPTION_RECORD ExceptionRecord; // [esp+10h] [ebp-320h] BYREF
  _CONTEXT ContextRecord; // [esp+60h] [ebp-2D0h] BYREF
  unsigned int savedregs; // [esp+330h] [ebp+0h]
  void *retaddr; // [esp+334h] [ebp+4h] BYREF

  if ( nDbgHookCode != -1 )
    _crt_debugger_hook();
  memset(dst: (int)&ExceptionRecord.ExceptionFlags, value: nullptr, count: 0x4Cu);
  ExceptionPointers.ExceptionRecord = &ExceptionRecord;
  ExceptionPointers.ContextRecord = &ContextRecord;
  ContextRecord.Eax = (unsigned int)&ContextRecord;
  ContextRecord.Ecx = v5;
  ContextRecord.Edx = v6;
  ContextRecord.Ebx = nDbgHookCode;
  ContextRecord.Esi = a2;
  ContextRecord.Edi = a1;
  LOWORD(ContextRecord.SegSs) = __SS__;
  LOWORD(ContextRecord.SegCs) = __CS__;
  LOWORD(ContextRecord.SegDs) = __DS__;
  LOWORD(ContextRecord.SegEs) = __ES__;
  LOWORD(ContextRecord.SegFs) = __FS__;
  LOWORD(ContextRecord.SegGs) = __GS__;
  v7 = __readeflags();
  ContextRecord.EFlags = v7;
  ContextRecord.Esp = (unsigned int)&retaddr;
  ContextRecord.ContextFlags = 65537;
  ContextRecord.Eip = (unsigned int)retaddr;
  ContextRecord.Ebp = savedregs;
  ExceptionRecord.ExceptionCode = dwExceptionCode;
  ExceptionRecord.ExceptionFlags = dwExceptionFlags;
  ExceptionRecord.ExceptionAddress = retaddr;
  v8 = IsDebuggerPresent();
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
  if ( UnhandledExceptionFilter(ExceptionInfo: &ExceptionPointers) == 0 && !v8 && nDbgHookCode != -1 )
    _crt_debugger_hook();
}

//------------------------------------------------------------------------------
// Address: 0x10027C56
// Name: __invoke_watson
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn _invoke_watson(unsigned int a1@<edi>)
{
  HANDLE CurrentProcess; // eax

  _call_reportfault(a1, a2: 0xC0000417, nDbgHookCode: 2u, dwExceptionCode: 0xC0000417, dwExceptionFlags: 1u);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC0000417);
}

//------------------------------------------------------------------------------
// Address: 0x10027C7B
// Name: __invalid_parameter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _invalid_parameter(unsigned int a1@<edi>)
{
  void (*v1)(void); // eax

  v1 = (void (*)(void))DecodePointer(Ptr: __pInvalidArgHandler);
  if ( v1 == nullptr )
    _invoke_watson(a1);
  v1();
}

//------------------------------------------------------------------------------
// Address: 0x10027CA8
// Name: __invalid_parameter_noinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _invalid_parameter_noinfo()
{
  unsigned int v0; // edi

  _invalid_parameter(a1: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10027CB8
// Name: __security_check_cookie(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall __security_check_cookie(unsigned int cookie)
{
  if ( cookie != __security_cookie )
    __report_gsfailure();
}

//------------------------------------------------------------------------------
// Address: 0x10027CC7
// Name: __freebuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freebuf(_iobuf *stream)
{
  int flag; // eax

  flag = stream->_flag;
  if ( (flag & 0x83) != 0 && (flag & 8) != 0 )
  {
    free(pMem: stream->_base);
    stream->_flag &= 0xFFFFFBF7;
    stream->_ptr = nullptr;
    stream->_base = nullptr;
    stream->_cnt = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027D45
// Name: __SEH_epilog4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _SEH_epilog4()
{
  __asm { retn }
}

//------------------------------------------------------------------------------
// Address: 0x10027EEF
// Name: __ioinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ioinit()
{
  unsigned __int8 *v0; // eax
  unsigned __int8 *v2; // eax
  int v3; // ebx
  unsigned __int8 **v4; // edi
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  int i; // edi
  ioinfo *v8; // esi
  int j; // ebx
  ioinfo *v10; // esi
  DWORD v11; // eax
  HANDLE StdHandle; // eax
  int v13; // edi
  DWORD FileType; // eax
  _STARTUPINFOW StartupInfo; // [esp+4h] [ebp-4Ch] BYREF
  int *posfhnd; // [esp+48h] [ebp-8h]
  char *posfile; // [esp+4Ch] [ebp-4h]

  GetStartupInfoW(lpStartupInfo: &StartupInfo);
  v0 = calloc(count: 0x20u, size: 0x40u);
  if ( v0 == nullptr )
    return -1;
  __pioinfo[0] = (ioinfo *)v0;
  _nhandle = 32;
  if ( v0 < v0 + 2048 )
  {
    v2 = v0 + 5;
    do
    {
      *(_DWORD *)(v2 - 5) = -1;
      *(_WORD *)(v2 - 1) = 2560;
      *(_DWORD *)(v2 + 3) = 0;
      *(_WORD *)(v2 + 31) = 2560;
      v2[33] = 10;
      *(_DWORD *)(v2 + 51) = 0;
      v2[47] = 0;
      v2 += 64;
    }
    while ( (ioinfo *)(v2 - 5) < &__pioinfo[0][32] );
  }
  if ( StartupInfo.cbReserved2 != 0 && StartupInfo.lpReserved2 != nullptr )
  {
    v3 = *(_DWORD *)StartupInfo.lpReserved2;
    posfile = (char *)(StartupInfo.lpReserved2 + 4);
    posfhnd = (int *)&StartupInfo.lpReserved2[v3 + 4];
    if ( v3 >= 2048 )
      v3 = 2048;
    if ( (int)_nhandle < v3 )
    {
      v4 = (unsigned __int8 **)&unk_10052884;
      while ( 1 )
      {
        v5 = calloc(count: 0x20u, size: 0x40u);
        if ( v5 == nullptr )
          break;
        _nhandle += 32;
        *v4 = v5;
        if ( v5 < v5 + 2048 )
        {
          v6 = v5 + 5;
          do
          {
            *(_DWORD *)(v6 - 5) = -1;
            *(_DWORD *)(v6 + 3) = 0;
            v6[31] &= 0x80u;
            *(_DWORD *)(v6 + 51) = 0;
            *(_WORD *)(v6 - 1) = 2560;
            *((_WORD *)v6 + 16) = 2570;
            v6[47] = 0;
            v6 += 64;
          }
          while ( v6 - 5 < *v4 + 2048 );
        }
        ++v4;
        if ( (int)_nhandle >= v3 )
          goto LABEL_19;
      }
      v3 = _nhandle;
    }
LABEL_19:
    for ( i = 0; i < v3; ++posfile )
    {
      if ( *posfhnd != -1
        && *posfhnd != -2
        && (*posfile & 1) != 0
        && ((*posfile & 8) != 0 || GetFileType(hFile: (HANDLE)*posfhnd) != 0) )
      {
        v8 = &__pioinfo[i >> 5][i & 0x1F];
        v8->osfhnd = *posfhnd;
        v8->osfile = *posfile;
        if ( !InitializeCriticalSectionAndSpinCount(lpCriticalSection: &v8->lock, dwSpinCount: 0xFA0u) )
          return -1;
        ++v8->lockinitflag;
      }
      ++posfhnd;
      ++i;
    }
  }
  for ( j = 0; j < 3; ++j )
  {
    v10 = &__pioinfo[0][j];
    if ( v10->osfhnd == -1 || v10->osfhnd == -2 )
    {
      v10->osfile = -127;
      if ( j != 0 )
        v11 = -(j != 1) - 11;
      else
        v11 = -10;
      StdHandle = GetStdHandle(nStdHandle: v11);
      v13 = (int)StdHandle;
      if ( StdHandle != (HANDLE)-1 && StdHandle != nullptr && (FileType = GetFileType(hFile: StdHandle)) != 0 )
      {
        v10->osfhnd = v13;
        if ( (unsigned __int8)FileType == 2 )
        {
          v10->osfile |= 0x40u;
        }
        else if ( (unsigned __int8)FileType == 3 )
        {
          v10->osfile |= 8u;
        }
        if ( !InitializeCriticalSectionAndSpinCount(lpCriticalSection: &v10->lock, dwSpinCount: 0xFA0u) )
          return -1;
        ++v10->lockinitflag;
      }
      else
      {
        v10->osfile |= 0x40u;
        v10->osfhnd = -2;
      }
    }
    else
    {
      v10->osfile |= 0x80u;
    }
  }
  SetHandleCount(uNumber: _nhandle);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10028134
// Name: __ioterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _ioterm()
{
  void **v0; // edi
  char *v1; // eax
  _RTL_CRITICAL_SECTION *v2; // esi

  v0 = (void **)__pioinfo;
  do
  {
    v1 = (char *)*v0;
    if ( *v0 != nullptr )
    {
      if ( v1 < v1 + 2048 )
      {
        v2 = (_RTL_CRITICAL_SECTION *)(v1 + 12);
        do
        {
          if ( v2[-1].SpinCount != 0 )
            DeleteCriticalSection(lpCriticalSection: v2);
          v2 = (_RTL_CRITICAL_SECTION *)((char *)v2 + 64);
        }
        while ( &v2[-1].OwningThread < (void **)((char *)*v0 + 2048) );
      }
      free(pMem: *v0);
      *v0 = nullptr;
    }
    ++v0;
  }
  while ( (int)v0 < (int)&_pDestructExceptionObject );
}

//------------------------------------------------------------------------------
// Address: 0x10028187
// Name: __fcloseall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fcloseall()
{
  int i; // edi
  _iobuf *v1; // eax
  int count; // [esp+14h] [ebp-1Ch]

  count = 0;
  _lock(locknum: 1);
  for ( i = 3; i < (int)_nstream; ++i )
  {
    if ( __piob[i] != nullptr )
    {
      v1 = (_iobuf *)__piob[i];
      if ( (v1->_flag & 0x83) != 0 && fclose(stream: v1) != -1 )
        ++count;
      if ( i >= 20 )
      {
        DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[i] + 32));
        free(pMem: __piob[i]);
        __piob[i] = nullptr;
      }
    }
  }
  _unlock(locknum: 1);
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x10028223
// Name: __mtinitlocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinitlocks()
{
  int v0; // esi
  _RTL_CRITICAL_SECTION *v1; // edi
  LPCRITICAL_SECTION *v2; // eax

  v0 = 0;
  v1 = lclcritsects;
  while ( 1 )
  {
    if ( *(&locktable + 2 * v0 + 1) == (LPCRITICAL_SECTION)1 )
    {
      v2 = &locktable + 2 * v0;
      *v2 = v1++;
      if ( !InitializeCriticalSectionAndSpinCount(lpCriticalSection: *v2, dwSpinCount: 0xFA0u) )
        break;
    }
    if ( ++v0 >= 36 )
      return 1;
  }
  *(&locktable + 2 * v0) = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1002826D
// Name: __mtdeletelocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _mtdeletelocks()
{
  LPCRITICAL_SECTION *v0; // esi
  LPCRITICAL_SECTION v1; // edi
  LPCRITICAL_SECTION *v2; // esi

  v0 = &locktable;
  do
  {
    v1 = *v0;
    if ( *v0 != nullptr && v0[1] != (LPCRITICAL_SECTION)1 )
    {
      DeleteCriticalSection(lpCriticalSection: *v0);
      free(pMem: v1);
      *v0 = nullptr;
    }
    v0 += 2;
  }
  while ( (int)v0 < (int)&__nullstring );
  v2 = &locktable;
  do
  {
    if ( *v2 != nullptr && v2[1] == (LPCRITICAL_SECTION)1 )
      DeleteCriticalSection(lpCriticalSection: *v2);
    v2 += 2;
  }
  while ( (int)v2 < (int)&__nullstring );
}

//------------------------------------------------------------------------------
// Address: 0x100282C4
// Name: __unlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock(int locknum)
{
  LeaveCriticalSection(lpCriticalSection: *(&locktable + 2 * locknum));
}

//------------------------------------------------------------------------------
// Address: 0x100282DB
// Name: __mtinitlocknum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinitlocknum(int locknum)
{
  LPCRITICAL_SECTION *v1; // esi
  _RTL_CRITICAL_SECTION *v3; // edi
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 1;
  if ( _crtheap == nullptr )
  {
    _FF_MSGBANNER();
    _NMSG_WRITE(rterrnum: 30);
    __crtExitProcess(status: 255);
  }
  v1 = &locktable + 2 * locknum;
  if ( *v1 != nullptr )
    return 1;
  v3 = (_RTL_CRITICAL_SECTION *)operator new(nSize: 0x18u);
  if ( v3 != nullptr )
  {
    _lock(locknum: 10);
    if ( *v1 != nullptr )
    {
      free(pMem: v3);
    }
    else if ( InitializeCriticalSectionAndSpinCount(lpCriticalSection: v3, dwSpinCount: 0xFA0u) )
    {
      *v1 = v3;
    }
    else
    {
      free(pMem: v3);
      *_errno() = 12;
      retval = 0;
    }
    _unlock(locknum: 10);
    return retval;
  }
  else
  {
    *_errno() = 12;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002839D
// Name: __lock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock(int locknum)
{
  LPCRITICAL_SECTION *v1; // esi

  v1 = &locktable + 2 * locknum;
  if ( *v1 == nullptr && _mtinitlocknum(locknum) == 0 )
    _amsg_exit(rterrnum: 17);
  EnterCriticalSection(lpCriticalSection: *v1);
}

//------------------------------------------------------------------------------
// Address: 0x100283D0
// Name: __flsbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flsbuf(unsigned __int8 ch, int str)
{
  _iobuf *v2; // esi
  int flag; // eax
  unsigned int v5; // eax
  char *base; // eax
  char *ptr; // edi
  signed int v8; // edi
  ioinfo *v9; // eax
  doubleint v10; // rax
  int written; // [esp+4h] [ebp-4h]

  v2 = (_iobuf *)str;
  str = _fileno(stream: (_iobuf *)str);
  flag = v2->_flag;
  if ( (flag & 0x82) == 0 )
  {
    *_errno() = 9;
LABEL_3:
    v2->_flag |= 0x20u;
    return -1;
  }
  if ( (flag & 0x40) != 0 )
  {
    *_errno() = 34;
    goto LABEL_3;
  }
  if ( (flag & 1) != 0 )
  {
    v2->_cnt = 0;
    if ( (flag & 0x10) == 0 )
    {
      v2->_flag = flag | 0x20;
      return -1;
    }
    v2->_ptr = v2->_base;
    v2->_flag = flag & 0xFFFFFFFE;
  }
  v5 = v2->_flag & 0xFFFFFFED | 2;
  v2->_flag = v5;
  v2->_cnt = 0;
  written = 0;
  if ( (v5 & 0x10C) == 0 && (v2 != &__iob_func()[1] && v2 != &__iob_func()[2] || _isatty(fh: str) == 0) )
    _getbuf(str: v2);
  if ( (v2->_flag & 0x108) != 0 )
  {
    base = v2->_base;
    ptr = v2->_ptr;
    v2->_ptr = base + 1;
    v8 = ptr - base;
    v2->_cnt = v2->_bufsiz - 1;
    if ( v8 <= 0 )
    {
      if ( str == -1 || str == -2 )
        v9 = &__badioinfo;
      else
        v9 = &__pioinfo[str >> 5][str & 0x1F];
      if ( (v9->osfile & 0x20) != 0 )
      {
        v10.bigint = _lseeki64(fh: str, pos: 0, mthd: 2u).bigint;
        if ( (v10.twoints.upperhalf & v10.twoints.lowerhalf) == -1 )
          goto LABEL_27;
      }
    }
    else
    {
      written = _write(fh: str, buf: base, cnt: v8);
    }
    *v2->_base = ch;
  }
  else
  {
    v8 = 1;
    written = _write(fh: str, buf: &ch, cnt: 1u);
  }
  if ( written != v8 )
  {
LABEL_27:
    v2->_flag |= 0x20u;
    return -1;
  }
  return ch;
}

//------------------------------------------------------------------------------
// Address: 0x10028534
// Name: write_char
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_char(int ch@<eax>, _iobuf *f@<ecx>, int *pnumwritten@<esi>)
{
  bool v3; // sf

  if ( ((f->_flag & 0x40) == 0 || f->_base != nullptr)
    && ((v3 = f->_cnt - 1 < 0, --f->_cnt, v3)
      ? (ch = _flsbuf(ch, str: (int)f))
      : (*f->_ptr = ch, ++f->_ptr, ch = (unsigned __int8)ch),
        ch == -1) )
  {
    *pnumwritten = -1;
  }
  else
  {
    ++*pnumwritten;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10028567
// Name: write_string
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_string(int len@<ecx>, _iobuf *f@<edi>, int *pnumwritten@<eax>, char *string)
{
  char *v6; // eax
  int *v7; // eax
  int save_errno; // [esp+8h] [ebp-4h]

  save_errno = *_errno();
  if ( (f->_flag & 0x40) == 0 || f->_base != nullptr )
  {
    *_errno() = 0;
    while ( len > 0 )
    {
      v6 = string;
      LOBYTE(v6) = *string;
      --len;
      write_char(ch: (int)v6, f, pnumwritten);
      ++string;
      if ( *pnumwritten == -1 )
      {
        v7 = _errno();
        if ( *v7 != 42 )
          break;
        LOBYTE(v7) = 63;
        write_char(ch: (int)v7, f, pnumwritten);
      }
    }
    if ( *_errno() == 0 )
      *_errno() = save_errno;
  }
  else
  {
    *pnumwritten += len;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100285DB
// Name: __output_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _output_l(_iobuf *stream, const char *format, localeinfo_struct *plocinfo, char *argptr)
{
  int *v4; // ebx
  const char *v5; // edi
  int v7; // eax
  ioinfo *v8; // ecx
  ioinfo *v9; // eax
  char v10; // dl
  STATE v11; // ecx
  char *v12; // edi
  int v13; // eax
  char v14; // al
  bool v15; // zf
  int v16; // eax
  _output_l::__l2::<unnamed_type_buffer> *p_buffer; // edi
  int v18; // ecx
  _output_l::__l2::<unnamed_type_text> v19; // ebx
  char *sz; // eax
  char *v21; // ebx
  __int16 *v22; // eax
  _output_l::__l2::<unnamed_type_text> v23; // ecx
  signed int v24; // eax
  _WORD *v25; // esi
  __int64 v26; // rax
  int *v27; // ebx
  int v28; // esi
  char *v29; // eax
  int v30; // eax
  char *v31; // ebx
  void (__cdecl *v32)(_CRT_DOUBLE *, _output_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *); // eax
  int v33; // ebx
  void (__cdecl *v34)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  void (__cdecl *v35)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  unsigned int v36; // ebx
  unsigned int v37; // edi
  char *j; // esi
  int v39; // eax
  unsigned __int64 v40; // rcx
  int v41; // ecx
  char *v42; // eax
  _BYTE *v43; // esi
  _BYTE *i; // eax
  int v45; // eax
  int v46; // ebx
  int v47; // edi
  _iobuf *v48; // edi
  int v49; // eax
  int v50; // ebx
  wchar_t *v51; // esi
  int v52; // eax
  int v53; // ebx
  char v54; // al
  int v55; // [esp-14h] [ebp-298h]
  int v56; // [esp-10h] [ebp-294h]
  unsigned __int64 v57; // [esp-10h] [ebp-294h]
  int v58; // [esp-Ch] [ebp-290h]
  int v59; // [esp-8h] [ebp-28Ch]
  wchar_t v60; // [esp-4h] [ebp-288h]
  _CRT_DOUBLE tmp; // [esp+Ch] [ebp-278h] BYREF
  int retval; // [esp+14h] [ebp-270h] BYREF
  int capexp; // [esp+18h] [ebp-26Ch]
  int padding; // [esp+20h] [ebp-264h]
  STATE state; // [esp+24h] [ebp-260h]
  _LocaleUpdate _loc_update; // [esp+28h] [ebp-25Ch] BYREF
  char *heapbuf; // [esp+38h] [ebp-24Ch]
  int hexadd; // [esp+3Ch] [ebp-248h]
  int no_output; // [esp+40h] [ebp-244h]
  _iobuf *f; // [esp+44h] [ebp-240h]
  char *v71; // [esp+48h] [ebp-23Ch]
  int bufferiswide; // [esp+4Ch] [ebp-238h]
  int fldwidth; // [esp+50h] [ebp-234h]
  int prefixlen; // [esp+54h] [ebp-230h]
  char prefix[4]; // [esp+58h] [ebp-22Ch] BYREF
  char *v76; // [esp+5Ch] [ebp-228h]
  int charsout; // [esp+60h] [ebp-224h] BYREF
  int radix; // [esp+64h] [ebp-220h] BYREF
  _output_l::__l2::<unnamed_type_text> text; // [esp+68h] [ebp-21Ch]
  int precision; // [esp+6Ch] [ebp-218h]
  char v81; // [esp+73h] [ebp-211h]
  int flags; // [esp+74h] [ebp-210h]
  _output_l::__l2::<unnamed_type_buffer> buffer; // [esp+78h] [ebp-20Ch] BYREF
  char L_buffer[8]; // [esp+278h] [ebp-Ch] BYREF

  v4 = (int *)argptr;
  v5 = format;
  f = stream;
  v76 = argptr;
  hexadd = 0;
  flags = 0;
  fldwidth = 0;
  precision = 0;
  prefixlen = 0;
  no_output = 0;
  bufferiswide = 0;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( stream != nullptr
    && ((stream->_flag & 0x40) != 0
     || ((v7 = _fileno(stream)) == -1 || v7 == -2 ? (v8 = &__badioinfo) : (v8 = &__pioinfo[v7 >> 5][v7 & 0x1F]),
         (*((_BYTE *)v8 + 36) & 0x7F) == 0
      && (v7 == -1 || v7 == -2 ? (v9 = &__badioinfo) : (v9 = &__pioinfo[v7 >> 5][v7 & 0x1F]), *((char *)v9 + 36) >= 0)))
    && format != nullptr )
  {
    v10 = *format;
    v11 = ST_NORMAL;
    charsout = 0;
    radix = 0;
    heapbuf = nullptr;
    v81 = v10;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v12 = (char *)(v5 + 1);
        v71 = v12;
        if ( charsout < 0 )
          break;
        if ( (unsigned __int8)(v10 - 32) > 0x58u )
          v13 = 0;
        else
          v13 = aExe[v10] & 0xF;
        state = __lookuptable[8 * v13 + v11] >> 4;
        switch ( state )
        {
          case ST_NORMAL:
            goto NORMAL_STATE;
          case ST_PERCENT:
            precision = -1;
            capexp = 0;
            no_output = 0;
            fldwidth = 0;
            prefixlen = 0;
            flags = 0;
            bufferiswide = 0;
            goto LABEL_224;
          case ST_FLAG:
            switch ( v10 )
            {
              case ' ':
                flags |= 2u;
                break;
              case '#':
                flags |= 0x80u;
                break;
              case '+':
                flags |= 1u;
                break;
              case '-':
                flags |= 4u;
                break;
              case '0':
                flags |= 8u;
                break;
              default:
                break;
            }
            goto LABEL_224;
          case ST_WIDTH:
            if ( v10 == 42 )
            {
              v76 = (char *)(v4 + 1);
              fldwidth = *v4;
              if ( fldwidth < 0 )
              {
                flags |= 4u;
                fldwidth = -fldwidth;
              }
            }
            else
            {
              fldwidth = 10 * fldwidth + v10 - 48;
            }
            goto LABEL_224;
          case ST_DOT:
            precision = 0;
            goto LABEL_224;
          case ST_PRECIS:
            if ( v10 == 42 )
            {
              v76 = (char *)(v4 + 1);
              precision = *v4;
              if ( precision < 0 )
                precision = -1;
            }
            else
            {
              precision = 10 * precision + v10 - 48;
            }
            goto LABEL_224;
          case ST_SIZE:
            switch ( v10 )
            {
              case 'I':
                v14 = *v12;
                if ( *v12 == 54 && v12[1] == 52 )
                {
                  flags |= 0x8000u;
                  v71 = v12 + 2;
                }
                else if ( v14 == 51 && v12[1] == 50 )
                {
                  flags &= ~0x8000u;
                  v71 = v12 + 2;
                }
                else if ( v14 != 100 && v14 != 105 && v14 != 111 && v14 != 117 && v14 != 120 && v14 != 88 )
                {
                  state = ST_NORMAL;
NORMAL_STATE:
                  bufferiswide = 0;
                  v16 = _isleadbyte_l(c: v10, plocinfo: &_loc_update.localeinfo);
                  v15 = v16 == 0;
                  LOBYTE(v16) = v81;
                  if ( !v15 )
                  {
                    write_char(ch: v16, f, pnumwritten: &charsout);
                    LOBYTE(v16) = *v12;
                    v71 = v12 + 1;
                    if ( (_BYTE)v16 == 0 )
                      goto LABEL_2;
                  }
                  write_char(ch: v16, f, pnumwritten: &charsout);
                }
                break;
              case 'h':
                flags |= 0x20u;
                break;
              case 'l':
                if ( *v12 == 108 )
                {
                  flags |= 0x1000u;
                  v71 = v12 + 1;
                }
                else
                {
                  flags |= 0x10u;
                }
                break;
              case 'w':
                flags |= 0x800u;
                break;
              default:
                break;
            }
            goto LABEL_224;
          case ST_TYPE:
            if ( v10 <= 100 )
            {
              if ( v10 == 100 )
              {
LABEL_118:
                flags |= 0x40u;
                goto LABEL_119;
              }
              if ( v10 > 83 )
              {
                if ( v10 == 88 )
                  goto LABEL_140;
                if ( v10 == 90 )
                {
                  v22 = (__int16 *)*v4;
                  v76 = (char *)(v4 + 1);
                  if ( v22 != nullptr && (v23.sz = *(char **)(v22 + 2), v23.sz != nullptr) )
                  {
                    v24 = *v22;
                    text.sz = v23.sz;
                    if ( (flags & 0x800) != 0 )
                    {
                      v24 /= 2;
                      bufferiswide = 1;
                    }
                    else
                    {
                      bufferiswide = 0;
                    }
                  }
                  else
                  {
                    text.sz = __nullstring;
                    strlen(buf: __nullstring);
                  }
                  goto LABEL_189;
                }
                if ( v10 != 97 )
                {
                  if ( v10 != 99 )
                    goto LABEL_190;
                  goto LABEL_93;
                }
              }
              else
              {
                if ( v10 == 83 )
                {
                  if ( (flags & 0x830) == 0 )
                    flags |= 0x800u;
                  goto LABEL_83;
                }
                if ( v10 != 65 )
                {
                  if ( v10 != 67 )
                  {
                    if ( v10 != 69 && v10 != 71 )
                      goto LABEL_190;
                    goto LABEL_76;
                  }
                  if ( (flags & 0x830) == 0 )
                    flags |= 0x800u;
LABEL_93:
                  v21 = (char *)(v4 + 1);
                  v76 = v21;
                  if ( (flags & 0x810) != 0 )
                  {
                    if ( wctomb_s(pRetValue: &radix, dst: buffer.sz, sizeInBytes: 0x200u, wchar: *((_WORD *)v21 - 2)) != 0 )
                      no_output = 1;
                  }
                  else
                  {
                    buffer.sz[0] = *(v21 - 4);
                    radix = 1;
                  }
                  text.sz = (char *)&buffer;
                  goto LABEL_190;
                }
LABEL_76:
                v10 += 32;
                capexp = 1;
                v81 = v10;
              }
LABEL_77:
              flags |= 0x40u;
              p_buffer = &buffer;
              text.sz = (char *)&buffer;
              padding = 512;
              if ( precision >= 0 )
              {
                if ( precision != 0 )
                {
                  if ( precision > 512 )
                    precision = 512;
                  if ( precision > 163 )
                  {
                    v28 = precision + 349;
                    v29 = (char *)operator new(nSize: precision + 349);
                    v10 = v81;
                    heapbuf = v29;
                    if ( v29 != nullptr )
                    {
                      text.sz = v29;
                      padding = v28;
                      p_buffer = (_output_l::__l2::<unnamed_type_buffer> *)v29;
                    }
                    else
                    {
                      precision = 163;
                    }
                  }
                }
                else
                {
                  precision = v10 == 103;
                }
              }
              else
              {
                precision = 6;
              }
              v30 = *v4;
              v31 = (char *)(v4 + 2);
              LODWORD(tmp.x) = v30;
              HIDWORD(tmp.x) = *((_DWORD *)v31 - 1);
              v59 = capexp;
              v58 = precision;
              v76 = v31;
              v56 = v10;
              v55 = padding;
              v32 = (void (__cdecl *)(_CRT_DOUBLE *, _output_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *))DecodePointer(Ptr: Ptr);
              v32(a1: &tmp, a2: p_buffer, a3: v55, a4: v56, a5: v58, a6: v59, a7: &_loc_update);
              v33 = flags & 0x80;
              if ( (flags & 0x80) != 0 && precision == 0 )
              {
                v34 = (void (__cdecl *)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))DecodePointer(Ptr: off_100475B8);
                v34(a1: p_buffer, a2: &_loc_update);
              }
              if ( v81 == 103 && v33 == 0 )
              {
                v35 = (void (__cdecl *)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))DecodePointer(Ptr: off_100475B4);
                v35(a1: p_buffer, a2: &_loc_update);
              }
              if ( p_buffer->sz[0] == 45 )
              {
                flags |= 0x100u;
                p_buffer = (_output_l::__l2::<unnamed_type_buffer> *)((char *)p_buffer + 1);
                text.sz = (char *)p_buffer;
              }
              strlen(buf: p_buffer->sz);
              goto LABEL_189;
            }
            if ( v10 > 112 )
            {
              if ( v10 != 115 )
              {
                if ( v10 != 117 )
                {
                  if ( v10 != 120 )
                    goto LABEL_190;
                  hexadd = 39;
                  goto COMMON_HEX;
                }
LABEL_119:
                radix = 10;
                goto COMMON_INT;
              }
LABEL_83:
              v18 = precision;
              if ( precision == -1 )
                v18 = 0x7FFFFFFF;
              v76 = (char *)(v4 + 1);
              v19.sz = (char *)*v4;
              text.sz = v19.sz;
              if ( (flags & 0x810) != 0 )
              {
                if ( v19.sz == nullptr )
                  text.sz = (char *)__wnullstring;
                sz = text.sz;
                bufferiswide = 1;
                while ( v18 != 0 )
                {
                  --v18;
                  if ( *(_WORD *)sz == 0 )
                    break;
                  sz += 2;
                }
                v24 = (sz - text.sz) >> 1;
              }
              else
              {
                if ( v19.sz == nullptr )
                  text.sz = __nullstring;
                for ( i = text.sz; v18 != 0; ++i )
                {
                  --v18;
                  if ( *i == 0 )
                    break;
                }
                v24 = i - text.sz;
              }
LABEL_189:
              radix = v24;
              goto LABEL_190;
            }
            if ( v10 == 112 )
            {
              precision = 8;
LABEL_140:
              hexadd = 7;
COMMON_HEX:
              radix = 16;
              if ( (flags & 0x80u) != 0 )
              {
                prefix[0] = 48;
                prefix[1] = hexadd + 81;
                prefixlen = 2;
              }
              goto COMMON_INT;
            }
            if ( v10 < 101 )
              goto LABEL_190;
            if ( v10 <= 103 )
              goto LABEL_77;
            if ( v10 == 105 )
              goto LABEL_118;
            if ( v10 != 110 )
            {
              if ( v10 != 111 )
                goto LABEL_190;
              radix = 8;
              if ( (flags & 0x80u) != 0 )
                flags |= 0x200u;
COMMON_INT:
              if ( (flags & 0x8000) != 0 || (flags & 0x1000) != 0 )
              {
                v26 = *(_QWORD *)v4;
                v27 = v4 + 2;
              }
              else
              {
                v27 = v4 + 1;
                if ( (flags & 0x20) != 0 )
                {
                  v76 = (char *)v27;
                  if ( (flags & 0x40) != 0 )
                    LODWORD(v26) = *((__int16 *)v27 - 2);
                  else
                    LODWORD(v26) = *((unsigned __int16 *)v27 - 2);
                  v26 = (int)v26;
LABEL_157:
                  if ( (flags & 0x40) != 0 && v26 < 0 )
                  {
                    v26 = -v26;
                    flags |= 0x100u;
                  }
                  v36 = HIDWORD(v26);
                  v37 = v26;
                  if ( (flags & 0x9000) == 0 )
                    v36 = 0;
                  if ( precision >= 0 )
                  {
                    flags &= ~8u;
                    if ( precision > 512 )
                      precision = 512;
                  }
                  else
                  {
                    precision = 1;
                  }
                  if ( (v36 | (unsigned int)v26) == 0 )
                    prefixlen = 0;
                  for ( j = &buffer.sz[511]; ; --j )
                  {
                    v39 = precision--;
                    if ( v39 <= 0 && (v36 | v37) == 0 )
                      break;
                    v57 = __PAIR64__(v36, v37);
                    v40 = __PAIR64__(v36, v37) % radix;
                    v41 = v40 + 48;
                    padding = HIDWORD(v40);
                    v36 = (v57 / radix) >> 32;
                    v37 = v57 / radix;
                    if ( v41 > 57 )
                      LOBYTE(v41) = hexadd + v41;
                    *j = v41;
                  }
                  v42 = (char *)(&buffer.sz[511] - j);
                  v43 = j + 1;
                  radix = (int)v42;
                  text.sz = v43;
                  if ( (flags & 0x200) != 0 && (v42 == nullptr || *v43 != 48) )
                  {
                    *--text.sz = 48;
                    v24 = (signed int)(v42 + 1);
                    goto LABEL_189;
                  }
LABEL_190:
                  if ( no_output != 0 )
                    goto LABEL_222;
                  v45 = flags;
                  if ( (flags & 0x40) != 0 )
                  {
                    if ( (flags & 0x100) != 0 )
                    {
                      prefix[0] = 45;
                      goto LABEL_198;
                    }
                    if ( (flags & 1) != 0 )
                    {
                      prefix[0] = 43;
                      goto LABEL_198;
                    }
                    if ( (flags & 2) != 0 )
                    {
                      prefix[0] = 32;
LABEL_198:
                      prefixlen = 1;
                    }
                  }
                  v46 = fldwidth - radix - prefixlen;
                  padding = v46;
                  if ( (flags & 0xC) == 0 )
                  {
                    v47 = fldwidth - radix - prefixlen;
                    if ( v46 > 0 )
                    {
                      do
                      {
                        LOBYTE(v45) = 32;
                        --v47;
                        write_char(ch: v45, f, pnumwritten: &charsout);
                      }
                      while ( charsout != -1 && v47 > 0 );
                    }
                  }
                  v48 = f;
                  write_string(len: prefixlen, f, pnumwritten: &charsout, string: prefix);
                  if ( (flags & 8) != 0 && (flags & 4) == 0 )
                  {
                    do
                    {
                      if ( v46 <= 0 )
                        break;
                      LOBYTE(v49) = 48;
                      --v46;
                      write_char(ch: v49, f: v48, pnumwritten: &charsout);
                    }
                    while ( charsout != -1 );
                  }
                  v50 = radix;
                  if ( bufferiswide != 0 && radix > 0 )
                  {
                    v51 = (wchar_t *)text.sz;
                    while ( 1 )
                    {
                      v60 = *v51;
                      --v50;
                      ++v51;
                      v52 = wctomb_s(pRetValue: &retval, dst: L_buffer, sizeInBytes: 6u, wchar: v60);
                      if ( v52 != 0 || retval == 0 )
                        break;
                      write_string(len: retval, f: v48, pnumwritten: &charsout, string: L_buffer);
                      if ( v50 == 0 )
                        goto LABEL_217;
                    }
                    charsout = -1;
                  }
                  else
                  {
                    write_string(len: radix, f: v48, pnumwritten: &charsout, string: text.sz);
                  }
LABEL_217:
                  if ( charsout >= 0 && (flags & 4) != 0 )
                  {
                    v53 = padding;
                    do
                    {
                      if ( v53 <= 0 )
                        break;
                      LOBYTE(v52) = 32;
                      --v53;
                      write_char(ch: v52, f: v48, pnumwritten: &charsout);
                    }
                    while ( charsout != -1 );
                  }
                  goto LABEL_222;
                }
                LODWORD(v26) = *(v27 - 1);
                if ( (flags & 0x40) != 0 )
                  v26 = (int)v26;
                else
                  HIDWORD(v26) = 0;
              }
              v76 = (char *)v27;
              goto LABEL_157;
            }
            v25 = (_WORD *)*v4;
            v76 = (char *)(v4 + 1);
            if ( !_get_printf_count_output() )
              goto LABEL_2;
            if ( (flags & 0x20) != 0 )
              *v25 = charsout;
            else
              *(_DWORD *)v25 = charsout;
            no_output = 1;
LABEL_222:
            if ( heapbuf != nullptr )
            {
              free(pMem: heapbuf);
              heapbuf = nullptr;
            }
LABEL_224:
            v5 = v71;
            v54 = *v71;
            v81 = v54;
            if ( v54 == 0 )
              goto LABEL_226;
            v11 = state;
            v4 = (int *)v76;
            v10 = v54;
            break;
          default:
            goto LABEL_224;
        }
      }
    }
LABEL_226:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return charsout;
  }
  else
  {
LABEL_2:
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029187
// Name: __stbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _stbuf(_iobuf *str)
{
  int v1; // eax
  int v2; // eax
  char **v3; // edi
  char *v4; // eax
  char *v5; // edi

  v1 = _fileno(stream: str);
  if ( _isatty(fh: v1) == 0 )
    return 0;
  if ( str == &__iob_func()[1] )
  {
    v2 = 0;
  }
  else
  {
    if ( str != &__iob_func()[2] )
      return 0;
    v2 = 1;
  }
  ++_cflush;
  if ( (str->_flag & 0x10C) != 0 )
    return 0;
  v3 = (char **)&_stdbuf[v2];
  if ( *v3 != nullptr || (v4 = (char *)operator new(nSize: 0x1000u), *v3 = v4, v4 != nullptr) )
  {
    v5 = *v3;
    str->_base = v5;
    str->_ptr = v5;
    str->_bufsiz = 4096;
    str->_cnt = 4096;
  }
  else
  {
    str->_base = (char *)&str->_charbuf;
    str->_ptr = (char *)&str->_charbuf;
    str->_bufsiz = 2;
    str->_cnt = 2;
  }
  str->_flag |= 0x1102u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10029223
// Name: __ftbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _ftbuf(int flag, _iobuf *str)
{
  if ( flag != 0 && (str->_flag & 0x1000) != 0 )
  {
    _flush(str);
    str->_flag &= 0xFFFFEEFF;
    str->_bufsiz = 0;
    str->_ptr = nullptr;
    str->_base = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029257
// Name: _strcpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strcpy_s(char *_Dst, unsigned int _SizeInBytes, const char *_Src)
{
  unsigned int v3; // edi
  int v4; // esi
  const char *v6; // eax
  char v7; // cl

  if ( _Dst == nullptr )
    goto LABEL_3;
  v3 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
LABEL_3:
    v4 = 22;
    *_errno() = 22;
LABEL_4:
    _invalid_parameter_noinfo();
    return v4;
  }
  do
  {
    v7 = *v6;
    v6[_Dst - _Src] = *v6;
    ++v6;
    if ( v7 == 0 )
      break;
    --v3;
  }
  while ( v3 != 0 );
  if ( v3 == 0 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100292B6
// Name: __VEC_memzero
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__fastcall _VEC_memzero(_BYTE *a1, unsigned int a2)
{
  int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // edx
  char *result; // eax
  unsigned int v6; // edx
  char v7; // al
  unsigned int k; // edx
  int i; // edx
  unsigned int j; // ebx
  unsigned int v11; // [esp-4h] [ebp-Ch]

  v2 = (unsigned __int8)a1 & 0xF;
  if ( ((unsigned __int8)a1 & 0xF) != 0 )
  {
    v11 = a2 - (16 - v2);
    for ( i = (16 - (_BYTE)v2) & 3; i != 0; --i )
      *a1++ = 0;
    for ( j = (unsigned int)(16 - v2) >> 2; j != 0; --j )
    {
      *(_DWORD *)a1 = 0;
      a1 += 4;
    }
    a2 = v11;
  }
  v3 = a2;
  v4 = a2 & 0x7F;
  for ( result = (char *)(v3 >> 7); result != nullptr; --result )
  {
    *(_OWORD *)a1 = 0;
    *((_OWORD *)a1 + 1) = 0;
    *((_OWORD *)a1 + 2) = 0;
    *((_OWORD *)a1 + 3) = 0;
    *((_OWORD *)a1 + 4) = 0;
    *((_OWORD *)a1 + 5) = 0;
    *((_OWORD *)a1 + 6) = 0;
    *((_OWORD *)a1 + 7) = 0;
    a1 += 128;
  }
  if ( v4 != 0 )
  {
    result = (char *)(v4 >> 4);
    if ( v4 >> 4 != 0 )
    {
      do
      {
        *(_OWORD *)a1 = 0;
        a1 += 16;
        --result;
      }
      while ( result != nullptr );
    }
    v6 = v4 & 0xF;
    if ( v6 != 0 )
    {
      v7 = v6;
      for ( k = v6 >> 2; k != 0; --k )
      {
        *(_DWORD *)a1 = 0;
        a1 += 4;
      }
      for ( result = (char *)(v7 & 3); result != nullptr; --result )
        *a1++ = 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10029370
// Name: ___sse2_available_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __sse2_available_init()
{
  __sse2_available = IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10029380
// Name: __VEC_memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _VEC_memcpy@<eax>(unsigned int a1@<ecx>, __m128i *a2@<edi>, const __m128i *a3@<esi>)
{
  int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // ecx
  unsigned int k; // edx
  __m128i si128; // xmm1
  __m128i v8; // xmm2
  __m128i v9; // xmm3
  __m128i v10; // xmm5
  __m128i v11; // xmm6
  __m128i v12; // xmm7
  unsigned int m; // edx
  unsigned int v14; // ecx
  char v15; // al
  unsigned int n; // ecx
  int ii; // ecx
  unsigned int v19; // eax
  int i; // ecx
  unsigned int j; // eax
  unsigned int v22; // [esp-10h] [ebp-14h]
  int v23; // [esp-Ch] [ebp-10h]

  v3 = (unsigned __int8)a3 & 0xF;
  if ( ((unsigned __int8)a3 & 0xF) != 0 )
  {
    v22 = a1 - (16 - v3);
    v19 = 16 - v3;
    for ( i = v19 & 3; i != 0; --i )
    {
      a2->m128i_i8[0] = a3->m128i_i8[0];
      a3 = (const __m128i *)((char *)a3 + 1);
      a2 = (__m128i *)((char *)a2 + 1);
    }
    for ( j = v19 >> 2; j != 0; --j )
    {
      a2->m128i_i32[0] = a3->m128i_i32[0];
      a3 = (const __m128i *)((char *)a3 + 4);
      a2 = (__m128i *)((char *)a2 + 4);
    }
    a1 = v22;
  }
  v4 = a1;
  v5 = a1 & 0x7F;
  for ( k = v4 >> 7; k != 0; --k )
  {
    si128 = _mm_load_si128(a3 + 1);
    v8 = _mm_load_si128(a3 + 2);
    v9 = _mm_load_si128(a3 + 3);
    *a2 = _mm_load_si128(a3);
    a2[1] = si128;
    a2[2] = v8;
    a2[3] = v9;
    v10 = _mm_load_si128(a3 + 5);
    v11 = _mm_load_si128(a3 + 6);
    v12 = _mm_load_si128(a3 + 7);
    a2[4] = _mm_load_si128(a3 + 4);
    a2[5] = v10;
    a2[6] = v11;
    a2[7] = v12;
    a3 += 8;
    a2 += 8;
  }
  if ( v5 != 0 )
  {
    for ( m = v5 >> 4; m != 0; --m )
      *a2++ = _mm_load_si128(a3++);
    v14 = v5 & 0xF;
    if ( v14 != 0 )
    {
      v15 = v14;
      for ( n = v14 >> 2; n != 0; --n )
      {
        a2->m128i_i32[0] = a3->m128i_i32[0];
        a3 = (const __m128i *)((char *)a3 + 4);
        a2 = (__m128i *)((char *)a2 + 4);
      }
      for ( ii = v15 & 3; ii != 0; --ii )
      {
        a2->m128i_i8[0] = a3->m128i_i8[0];
        a3 = (const __m128i *)((char *)a3 + 1);
        a2 = (__m128i *)((char *)a2 + 1);
      }
    }
  }
  return v23;
}

//------------------------------------------------------------------------------
// Address: 0x10029483
// Name: __fileno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fileno(_iobuf *stream)
{
  if ( stream != nullptr )
    return stream->_file;
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100294A9
// Name: __openfile
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _openfile(const char *filename, const char *mode, int shflag, _iobuf *str)
{
  unsigned int v4; // ebx
  const char *v5; // esi
  char v6; // al
  _iobuf *result; // eax
  int v8; // ecx
  const unsigned __int8 *v9; // esi
  signed __int8 v10; // al
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  const unsigned __int8 *i; // esi
  int encodingFlag; // [esp+8h] [ebp-10h]
  int commodeset; // [esp+Ch] [ebp-Ch]
  int scanset; // [esp+10h] [ebp-8h]
  unsigned int streamflag; // [esp+14h] [ebp-4h]

  v4 = 0;
  v5 = mode;
  commodeset = 0;
  scanset = 0;
  encodingFlag = 0;
  while ( *v5 == 32 )
    ++v5;
  v6 = *v5;
  if ( *v5 == 97 )
  {
    v4 = 265;
  }
  else
  {
    if ( v6 == 114 )
    {
      streamflag = _commode | 1;
      goto LABEL_12;
    }
    if ( v6 != 119 )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
    v4 = 769;
  }
  streamflag = _commode | 2;
LABEL_12:
  v8 = 1;
  v9 = (const unsigned __int8 *)(v5 + 1);
  v10 = *v9;
  if ( *v9 == 0 )
    goto LABEL_66;
  while ( v8 != 0 )
  {
    if ( v10 > 83 )
    {
      v16 = v10 - 84;
      if ( v16 == 0 )
      {
        if ( (v4 & 0x1000) == 0 )
        {
          v4 |= 0x1000u;
          goto LABEL_48;
        }
        goto LABEL_46;
      }
      v17 = v16 - 14;
      if ( v17 != 0 )
      {
        v18 = v17 - 1;
        if ( v18 != 0 )
        {
          v19 = v18 - 11;
          if ( v19 != 0 )
          {
            if ( v19 != 6 )
              goto LABEL_68;
            if ( (v4 & 0xC000) != 0 )
              goto LABEL_46;
            v4 |= 0x4000u;
          }
          else
          {
            if ( commodeset != 0 )
              goto LABEL_46;
            streamflag &= ~0x4000u;
            commodeset = 1;
          }
        }
        else
        {
          if ( commodeset != 0 )
            goto LABEL_46;
          streamflag |= 0x4000u;
          commodeset = 1;
        }
      }
      else
      {
        if ( (v4 & 0xC000) != 0 )
          goto LABEL_46;
        v4 |= 0x8000u;
      }
    }
    else if ( v10 == 83 )
    {
      if ( scanset != 0 )
        goto LABEL_46;
      scanset = 1;
      v4 |= 0x20u;
    }
    else
    {
      v11 = v10 - 32;
      if ( v11 != 0 )
      {
        v12 = v11 - 11;
        if ( v12 != 0 )
        {
          v13 = v12 - 1;
          if ( v13 == 0 )
          {
            encodingFlag = 1;
LABEL_46:
            v8 = 0;
            goto LABEL_48;
          }
          v14 = v13 - 24;
          if ( v14 != 0 )
          {
            v15 = v14 - 10;
            if ( v15 != 0 )
            {
              if ( v15 != 4 )
                goto LABEL_68;
              if ( scanset != 0 )
                goto LABEL_46;
              scanset = 1;
              v4 |= 0x10u;
            }
            else
            {
              v4 |= 0x80u;
            }
          }
          else
          {
            if ( (v4 & 0x40) != 0 )
              goto LABEL_46;
            v4 |= 0x40u;
          }
        }
        else
        {
          if ( (v4 & 2) != 0 )
            goto LABEL_46;
          v4 = v4 & 0xFFFFFFFC | 2;
          streamflag = streamflag & 0xFFFFFF7C | 0x80;
        }
      }
    }
LABEL_48:
    v10 = *++v9;
    if ( *v9 == 0 )
      break;
  }
  if ( encodingFlag == 0 )
    goto LABEL_66;
  while ( *v9 == 32 )
    ++v9;
  if ( _mbsnbcmp(s1: "ccs", s2: v9, n: 3u) != 0 )
    goto LABEL_68;
  for ( i = v9 + 3; *i == 32; ++i )
    ;
  if ( *i != 61 )
    goto LABEL_68;
  do
    ++i;
  while ( *i == 32 );
  if ( _mbsnbicmp(s1: i, s2: "UTF-8", n: 5u) == 0 )
  {
    v9 = i + 5;
    v4 |= 0x40000u;
    goto LABEL_66;
  }
  if ( _mbsnbicmp(s1: i, s2: "UTF-16LE", n: 8u) == 0 )
  {
    v9 = i + 8;
    v4 |= 0x20000u;
    goto LABEL_66;
  }
  if ( _mbsnbicmp(s1: i, s2: "UNICODE", n: 7u) != 0 )
    goto LABEL_68;
  v9 = i + 7;
  v4 |= 0x10000u;
LABEL_66:
  while ( *v9 == 32 )
    ++v9;
  if ( *v9 != 0 )
  {
LABEL_68:
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  if ( _sopen_s(pfh: (int *)&mode, path: filename, oflag: v4, shflag, pmode: 384) != 0 )
    return nullptr;
  ++_cflush;
  result = str;
  str->_flag = streamflag;
  result->_cnt = 0;
  result->_ptr = nullptr;
  result->_base = nullptr;
  result->_tmpfname = nullptr;
  result->_file = (int)mode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10029740
// Name: __getstream
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _getstream()
{
  _DWORD *v0; // edi
  int i; // esi
  void **v2; // eax
  int v3; // eax
  void *v4; // eax

  v0 = nullptr;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v2 = &__piob[i];
    if ( *v2 == nullptr )
    {
      v4 = operator new(nSize: 0x38u);
      __piob[i] = v4;
      if ( v4 != nullptr )
      {
        if ( InitializeCriticalSectionAndSpinCount(
               lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[i] + 32),
               dwSpinCount: 0xFA0u) )
        {
          EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[i] + 32));
          v0 = __piob[i];
          v0[3] = 0;
        }
        else
        {
          free(pMem: __piob[i]);
          __piob[i] = nullptr;
        }
      }
      break;
    }
    v3 = *((_DWORD *)*v2 + 3);
    if ( (v3 & 0x83) == 0 && (v3 & 0x8000) == 0 )
    {
      if ( (unsigned int)(i - 3) <= 0x10 && _mtinitlocknum(locknum: i + 16) == 0 )
        break;
      _lock_file2(i, s: (char *)__piob[i]);
      if ( (*((_BYTE *)__piob[i] + 12) & 0x83) == 0 )
      {
        v0 = __piob[i];
        break;
      }
      _unlock_file2(i, s: (char *)__piob[i]);
    }
  }
  if ( v0 != nullptr )
  {
    v0[3] &= 0x8000u;
    v0[1] = 0;
    v0[2] = 0;
    *v0 = 0;
    v0[7] = 0;
    v0[4] = -1;
  }
  _unlock(locknum: 1);
  return (_iobuf *)v0;
}

//------------------------------------------------------------------------------
// Address: 0x10029880
// Name: __local_unwind4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _local_unwind4@<eax>(unsigned int a1@<ebp>, _DWORD *a2, int a3, unsigned int a4)
{
  int result; // eax
  unsigned int v5; // esi
  int v6; // esi
  int v7; // ebx

  while ( 1 )
  {
    result = a3;
    v5 = *(_DWORD *)(a3 + 12);
    if ( v5 == -2 || a4 != -2 && v5 <= a4 )
      break;
    v6 = 3 * v5;
    v7 = (*a2 ^ *(_DWORD *)(a3 + 8)) + 4 * v6 + 16;
    *(_DWORD *)(a3 + 12) = *(_DWORD *)((*a2 ^ *(_DWORD *)(a3 + 8)) + 4 * v6 + 0x10);
    if ( *(_DWORD *)(v7 + 4) == 0 )
    {
      _NLG_Notify(result: *(_DWORD *)(v7 + 8), a2: a1, a3: 0x101u);
      _NLG_Call(a1: *(int (**)(void))(v7 + 8));
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10029910
// Name: _unwind_handler4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl unwind_handler4(int a1, int a2, int a3, _DWORD *a4)
{
  int result; // eax

  result = 1;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    _local_unwind4(
      a1: *(_DWORD *)(a2 + 24),
      a2: *(_DWORD **)(a2 + 20),
      a3: *(_DWORD *)(a2 + 16),
      a4: *(_DWORD *)(a2 + 12));
    *a4 = a2;
    return 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10029956
// Name: _seh_longjmp_unwind4(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _seh_longjmp_unwind4(unsigned int Dummy)
{
  _local_unwind4(
    a1: *(_DWORD *)Dummy,
    a2: *(_DWORD **)(Dummy + 40),
    a3: *(_DWORD *)(Dummy + 24),
    a4: *(_DWORD *)(Dummy + 28));
}

//------------------------------------------------------------------------------
// Address: 0x10029972
// Name: _EH4_CallFilterFunc(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_CallFilterFunc(int (*this)(void))
{
  return this();
}

//------------------------------------------------------------------------------
// Address: 0x10029989
// Name: _EH4_TransferToHandler(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _EH4_TransferToHandler(int (__fastcall *a1)(_DWORD, _DWORD), unsigned int a2)
{
  _NLG_Notify(result: (unsigned int)a1, a2, a3: 1u);
  return a1(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100299A2
// Name: _EH4_GlobalUnwind2(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall _EH4_GlobalUnwind2(PVOID TargetFrame, PEXCEPTION_RECORD ExceptionRecord)
{
  RtlUnwind(TargetFrame, TargetIp: &ReturnPoint, ExceptionRecord, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100299BB
// Name: _EH4_LocalUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _EH4_LocalUnwind(int a1, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  return _local_unwind4(a1: a3, a2: a4, a3: a1, a4: a2);
}

//------------------------------------------------------------------------------
// Address: 0x100299D2
// Name: __spawnvpe
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _spawnvpe(int modeflag, char *filename, const char *const *argv, const char *const *envptr)
{
  unsigned __int8 *v4; // edi
  unsigned __int8 *v5; // esi
  int v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // eax
  char *v10; // eax
  bool j; // zf
  int v12; // eax
  unsigned __int8 *v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  unsigned __int8 *v17; // eax
  unsigned __int8 *v18; // eax
  unsigned __int8 *v19; // eax
  unsigned __int8 *v20; // eax
  int save_errno; // [esp+8h] [ebp-10h]
  int i; // [esp+Ch] [ebp-Ch]
  char *env; // [esp+10h] [ebp-8h]
  char *envbuf; // [esp+14h] [ebp-4h] BYREF

  v4 = nullptr;
  v5 = nullptr;
  envbuf = nullptr;
  if ( filename != nullptr && *filename != 0 && argv != nullptr && *argv != nullptr && **(_BYTE **)argv != 0 )
  {
    save_errno = *_errno();
    *_errno() = 0;
    i = _spawnve(mode: modeflag, name: filename, argv, envp: envptr);
    if ( i == -1 && *_errno() == 2 )
    {
      _mbschr(string: (unsigned __int8 *)filename, c: 0x2Fu);
      if ( v7 == 0 )
      {
        v8 = _dupenv_s(pBuffer: &envbuf, pBufferSizeInTChars: nullptr, varname: "PATH");
        if ( v8 != 0 )
        {
          if ( v8 == 22 )
LABEL_13:
            _invoke_watson(a1: (unsigned int)v4);
        }
        else if ( envbuf != nullptr )
        {
          v9 = calloc(count: 0x104u, size: 1u);
          v5 = v9;
          if ( v9 != nullptr )
          {
            v10 = _getpath(src: envbuf, dst: (char *)v9, maxlen: 0x103u);
            for ( j = v10 == nullptr; ; j = v10 == nullptr )
            {
              env = v10;
              if ( j || *v5 == 0 )
                break;
              strlen(buf: (char *)v5);
              v4 = &v5[v12 - 1];
              if ( *v4 == 92 )
              {
                _mbsrchr(str: v5, c: 0x5Cu);
                if ( v4 != v13 )
                  strcat_s(_Dst: (char *)v5, _SizeInBytes: 0x104u, _Src: "\\");
              }
              else if ( *v4 != 47 && strcat_s(_Dst: (char *)v5, _SizeInBytes: 0x104u, _Src: "\\") != 0 )
              {
                goto LABEL_13;
              }
              strlen(buf: (char *)v5);
              v15 = v14;
              strlen(buf: filename);
              v4 = (unsigned __int8 *)(v16 + v15);
              if ( (unsigned int)v4 >= 0x104 )
                break;
              if ( strcat_s(_Dst: (char *)v5, _SizeInBytes: 0x104u, _Src: filename) != 0 )
                goto LABEL_13;
              *_errno() = 0;
              i = _spawnve(mode: modeflag, name: (const char *)v5, argv, envp: envptr);
              if ( i != -1 )
                break;
              if ( *_errno() != 2 && *__doserrno() != 21 )
              {
                _mbschr(string: v5, c: 0x5Cu);
                if ( v5 != v17 )
                {
                  _mbschr(string: v5, c: 0x2Fu);
                  if ( v5 != v18 )
                    break;
                }
                _mbschr(string: v5 + 1, c: 0x5Cu);
                if ( v5 + 1 != v19 )
                {
                  _mbschr(string: v5 + 1, c: 0x2Fu);
                  if ( v5 + 1 != v20 )
                    break;
                }
              }
              v10 = _getpath(src: env, dst: (char *)v5, maxlen: 0x103u);
            }
          }
        }
      }
    }
    if ( *_errno() == 0 )
      *_errno() = save_errno;
    if ( v5 != nullptr )
      free(pMem: v5);
    if ( envbuf != nullptr )
      free(pMem: envbuf);
    return i;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029C3E
// Name: $LN43_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _LN43_0(int mode, const char *name, const char **argv, const char **envp)
{
  int v5; // esi
  char *envblk; // [esp+0h] [ebp-8h] BYREF
  char *argblk; // [esp+4h] [ebp-4h] BYREF

  if ( name == nullptr || argv == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( _cenvarg(argv, envp, &argblk, &envblk) == -1 )
    return -1;
  v5 = _dospawn(mode, name, cmdblk: argblk, envblk);
  free(pMem: argblk);
  free(pMem: envblk);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10029CB0
// Name: __spawnve
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _spawnve(int mode, char *name, const char **argv, const char **envp)
{
  char *v4; // edi
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // esi
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // eax
  int v10; // eax
  unsigned int v11; // esi
  unsigned __int8 *v12; // eax
  char *v13; // ebx
  int v14; // eax
  int v15; // eax
  unsigned int v16; // esi
  unsigned __int8 *v17; // eax
  char *v18; // ebx
  int v19; // eax
  unsigned int v20; // esi
  int save_errno; // [esp+4h] [ebp-10h]
  int rc; // [esp+8h] [ebp-Ch]
  const char **v23; // [esp+Ch] [ebp-8h]
  char *pathname; // [esp+10h] [ebp-4h]

  v4 = name;
  pathname = name;
  if ( name == nullptr || *name == 0 || argv == nullptr || *argv == nullptr || **argv == 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  _mbsrchr(str: (unsigned __int8 *)name, c: 0x5Cu);
  v7 = v6;
  _mbsrchr(str: (unsigned __int8 *)name, c: 0x2Fu);
  if ( v8 != nullptr )
  {
    if ( v7 == nullptr || v8 > v7 )
      v7 = v8;
  }
  else if ( v7 == nullptr )
  {
    _mbschr(string: (unsigned __int8 *)name, c: 0x3Au);
    v7 = v9;
    if ( v9 == nullptr )
    {
      strlen(buf: name);
      v11 = v10 + 3;
      v12 = calloc(count: v10 + 3, size: 1u);
      v13 = (char *)v12;
      pathname = (char *)v12;
      if ( v12 == nullptr )
        return -1;
      if ( strcpy_s(_Dst: (char *)v12, _SizeInBytes: v11, _Src: ".\\") != 0
        || strcat_s(_Dst: v13, _SizeInBytes: v11, _Src: name) != 0 )
      {
LABEL_14:
        _invoke_watson(a1: (unsigned int)v4);
      }
      v7 = (unsigned __int8 *)(v13 + 2);
    }
  }
  rc = -1;
  _mbsrchr(str: v7, c: 0x2Eu);
  if ( v14 == 0 )
  {
    strlen(buf: pathname);
    v16 = v15 + 5;
    v17 = calloc(count: v15 + 5, size: 1u);
    v18 = (char *)v17;
    v4 = nullptr;
    if ( v17 == nullptr )
      return -1;
    if ( strcpy_s(_Dst: (char *)v17, _SizeInBytes: v16, _Src: pathname) == 0 )
    {
      strlen(buf: pathname);
      v4 = &v18[v19];
      save_errno = *_errno();
      v20 = (unsigned int)&v18[v16 - (_DWORD)v4];
      v23 = (const char **)&ext_strings[3];
      while ( 1 )
      {
        if ( strcpy_s(_Dst: v4, _SizeInBytes: v20, _Src: *v23) != 0 )
          goto LABEL_14;
        if ( _access_s(path: v18, amode: 0) == 0 )
          break;
        if ( (int)--v23 < (int)ext_strings )
          goto LABEL_30;
      }
      *_errno() = save_errno;
      rc = _LN43_0(mode, name: v18, argv, envp);
LABEL_30:
      free(pMem: v18);
      v4 = name;
      goto LABEL_31;
    }
    goto LABEL_14;
  }
  if ( _access_s(path: pathname, amode: 0) == 0 )
    rc = _LN43_0(mode, name: pathname, argv, envp);
LABEL_31:
  if ( pathname != v4 )
    free(pMem: pathname);
  return rc;
}

//------------------------------------------------------------------------------
// Address: 0x10029E99
// Name: __write_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _write_nolock(int fh, char *buf, unsigned int cnt)
{
  ioinfo **v4; // ebx
  ioinfo *v5; // eax
  int v6; // edi
  char v7; // cl
  BOOL v8; // esi
  UINT ConsoleCP; // eax
  char *v10; // ebx
  unsigned __int8 v11; // cl
  ioinfo **v12; // esi
  int v13; // eax
  int v14; // eax
  DWORD v15; // eax
  signed int v16; // esi
  ioinfo *v17; // eax
  int v18; // esi
  ioinfo *v19; // ecx
  char v20; // dl
  char *v21; // ebx
  unsigned int v22; // esi
  unsigned int v23; // ecx
  char *v24; // eax
  char v25; // dl
  signed int v26; // esi
  char *v27; // ebx
  unsigned int v28; // ecx
  char *v29; // eax
  int v30; // edx
  signed int v31; // esi
  unsigned int v32; // ecx
  WCHAR *v33; // eax
  int v34; // edx
  int v35; // esi
  int v36; // ebx
  BOOL v37; // [esp+8h] [ebp-1AE4h]
  unsigned int Mode; // [esp+Ch] [ebp-1AE0h] BYREF
  ioinfo **v39; // [esp+10h] [ebp-1ADCh]
  unsigned int v40; // [esp+14h] [ebp-1AD8h] BYREF
  unsigned int NumberOfBytesWritten; // [esp+18h] [ebp-1AD4h] BYREF
  int v42; // [esp+1Ch] [ebp-1AD0h]
  char *s; // [esp+20h] [ebp-1ACCh]
  unsigned int v44; // [esp+24h] [ebp-1AC8h]
  char v45; // [esp+2Bh] [ebp-1AC1h]
  unsigned int v46; // [esp+2Ch] [ebp-1AC0h]
  wchar_t pwc[2]; // [esp+30h] [ebp-1ABCh] BYREF
  char Buffer[1704]; // [esp+34h] [ebp-1AB8h] BYREF
  char v49[3416]; // [esp+6DCh] [ebp-1410h] BYREF
  WCHAR WideCharStr[854]; // [esp+1434h] [ebp-6B8h] BYREF
  char MultiByteStr[8]; // [esp+1AE0h] [ebp-Ch] BYREF

  s = buf;
  v44 = 0;
  v42 = 0;
  if ( cnt == 0 )
    return 0;
  if ( buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v4 = &__pioinfo[fh >> 5];
  v5 = *v4;
  v6 = (fh & 0x1F) << 6;
  v7 = (char)(2 * *((_BYTE *)*v4 + v6 + 36)) >> 1;
  v39 = v4;
  v45 = v7;
  if ( (v7 == 2 || v7 == 1) && (cnt & 1) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( (*(&v5->osfile + v6) & 0x20) != 0 )
    _lseeki64_nolock(fh, pos: 0, mthd: 2u);
  if ( _isatty(fh) != 0 && *(&(*v4)->osfile + v6) < 0 )
  {
    v8 = _getptd()->ptlocinfo->lc_handle[2] == 0;
    if ( GetConsoleMode(hConsoleHandle: *(HANDLE *)((char *)&(*v4)->osfhnd + v6), lpMode: &Mode) && (!v8 || v45 != 0) )
    {
      ConsoleCP = GetConsoleCP();
      v10 = s;
      Mode = ConsoleCP;
      NumberOfBytesWritten = 0;
      v46 = 0;
      while ( 1 )
      {
        if ( v45 != 0 )
        {
          if ( v45 == 1 || v45 == 2 )
          {
            v18 = *(unsigned __int16 *)v10;
            v10 += 2;
            v46 += 2;
            *(_DWORD *)pwc = v18;
            v37 = v18 == 10;
          }
          if ( v45 == 1 || v45 == 2 )
          {
            if ( _putwch_nolock(ch: pwc[0]) != pwc[0] )
              goto LABEL_85;
            v44 += 2;
            if ( v37 )
            {
              wcscpy(pwc, L"\r");
              if ( _putwch_nolock(ch: 0xDu) != pwc[0] )
                goto LABEL_85;
              ++v44;
              ++v42;
            }
          }
          goto LABEL_43;
        }
        v11 = *v10;
        v12 = v39;
        v37 = *v10 == 10;
        v13 = (int)*v39 + v6;
        if ( *(_DWORD *)(v13 + 56) != 0 )
        {
          MultiByteStr[0] = *(_BYTE *)(v13 + 52);
          MultiByteStr[1] = v11;
          *(_DWORD *)(v13 + 56) = 0;
          v14 = mbtowc(pwc, s: MultiByteStr, n: 2u);
        }
        else
        {
          if ( isleadbyte(c: v11) != 0 )
          {
            if ( cnt + s - v10 <= 1 )
            {
              v19 = *v12;
              v20 = *v10;
              ++v44;
              *(&v19->dbcsBuffer + v6) = v20;
              *(int *)((char *)&(*v12)->dbcsBufferUsed + v6) = 1;
              goto LABEL_86;
            }
            if ( mbtowc(pwc, s: v10, n: 2u) == -1 )
              goto LABEL_86;
            ++v10;
            ++v46;
            goto LABEL_27;
          }
          v14 = mbtowc(pwc, s: v10, n: 1u);
        }
        if ( v14 == -1 )
          goto LABEL_86;
LABEL_27:
        ++v10;
        ++v46;
        v15 = WideCharToMultiByte(
                CodePage: Mode,
                dwFlags: 0,
                lpWideCharStr: pwc,
                cchWideChar: 1,
                lpMultiByteStr: MultiByteStr,
                cbMultiByte: 5,
                lpDefaultChar: nullptr,
                lpUsedDefaultChar: nullptr);
        v16 = v15;
        if ( v15 == 0 )
          goto LABEL_86;
        if ( !WriteFile(
                hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                lpBuffer: MultiByteStr,
                nNumberOfBytesToWrite: v15,
                lpNumberOfBytesWritten: &NumberOfBytesWritten,
                lpOverlapped: nullptr) )
          goto LABEL_85;
        v44 = v42 + v46;
        if ( (int)NumberOfBytesWritten < v16 )
          goto LABEL_86;
        if ( v37 )
        {
          v17 = *v39;
          MultiByteStr[0] = 13;
          if ( !WriteFile(
                  hFile: *(HANDLE *)((char *)&v17->osfhnd + v6),
                  lpBuffer: MultiByteStr,
                  nNumberOfBytesToWrite: 1u,
                  lpNumberOfBytesWritten: &NumberOfBytesWritten,
                  lpOverlapped: nullptr) )
            goto LABEL_85;
          if ( (int)NumberOfBytesWritten < 1 )
            goto LABEL_86;
          ++v42;
          ++v44;
        }
LABEL_43:
        if ( v46 >= cnt )
          goto LABEL_86;
      }
    }
  }
  if ( *(&(*v4)->osfile + v6) >= 0 )
  {
    if ( WriteFile(
           hFile: (HANDLE)(*v4)[fh & 0x1F].osfhnd,
           lpBuffer: s,
           nNumberOfBytesToWrite: cnt,
           lpNumberOfBytesWritten: &v40,
           lpOverlapped: nullptr) )
    {
      *(_DWORD *)pwc = 0;
      v44 = v40;
      goto LABEL_86;
    }
  }
  else
  {
    *(_DWORD *)pwc = 0;
    if ( v45 != 0 )
    {
      if ( v45 == 2 )
      {
        v27 = s;
        while ( 1 )
        {
          v46 = 0;
          v28 = v27 - s;
          v29 = Buffer;
          do
          {
            if ( v28 >= cnt )
              break;
            v30 = *(unsigned __int16 *)v27;
            v27 += 2;
            v28 += 2;
            Mode = (unsigned int)v27;
            if ( v30 == 10 )
            {
              v42 += 2;
              *(_WORD *)v29 = 13;
              v27 = (char *)Mode;
              v29 += 2;
              v46 += 2;
            }
            v46 += 2;
            *(_WORD *)v29 = v30;
            v29 += 2;
          }
          while ( v46 < 0x13FE );
          v31 = v29 - Buffer;
          if ( !WriteFile(
                  hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                  lpBuffer: Buffer,
                  nNumberOfBytesToWrite: v29 - Buffer,
                  lpNumberOfBytesWritten: &v40,
                  lpOverlapped: nullptr) )
            break;
          v44 += v40;
          if ( (int)v40 < v31 || v27 - s >= cnt )
            goto LABEL_86;
        }
      }
      else
      {
        NumberOfBytesWritten = (unsigned int)s;
        while ( 1 )
        {
          v46 = 0;
          v32 = NumberOfBytesWritten - (_DWORD)s;
          v33 = WideCharStr;
          do
          {
            if ( v32 >= cnt )
              break;
            v34 = *(unsigned __int16 *)NumberOfBytesWritten;
            NumberOfBytesWritten += 2;
            v32 += 2;
            if ( v34 == 10 )
            {
              *v33++ = 13;
              v46 += 2;
            }
            v46 += 2;
            *v33++ = v34;
          }
          while ( v46 < 0x6A8 );
          v35 = 0;
          v36 = WideCharToMultiByte(
                  CodePage: 0xFDE9u,
                  dwFlags: 0,
                  lpWideCharStr: WideCharStr,
                  cchWideChar: v33 - WideCharStr,
                  lpMultiByteStr: v49,
                  cbMultiByte: 3413,
                  lpDefaultChar: nullptr,
                  lpUsedDefaultChar: nullptr);
          if ( v36 == 0 )
            break;
          while ( WriteFile(
                    hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                    lpBuffer: &v49[v35],
                    nNumberOfBytesToWrite: v36 - v35,
                    lpNumberOfBytesWritten: &v40,
                    lpOverlapped: nullptr) )
          {
            v35 += v40;
            if ( v36 <= v35 )
              goto LABEL_80;
          }
          *(_DWORD *)pwc = GetLastError();
LABEL_80:
          if ( v36 <= v35 )
          {
            v44 = NumberOfBytesWritten - (_DWORD)s;
            if ( NumberOfBytesWritten - (unsigned int)s < cnt )
              continue;
          }
          goto LABEL_86;
        }
      }
    }
    else
    {
      v21 = s;
      while ( 1 )
      {
        v22 = 0;
        v23 = v21 - s;
        v24 = Buffer;
        do
        {
          if ( v23 >= cnt )
            break;
          v25 = *v21++;
          ++v23;
          Mode = (unsigned int)v21;
          if ( v25 == 10 )
          {
            ++v42;
            *v24++ = 13;
            ++v22;
          }
          *v24++ = v25;
          ++v22;
        }
        while ( v22 < 0x13FF );
        v26 = v24 - Buffer;
        if ( !WriteFile(
                hFile: *(HANDLE *)((char *)&(*v39)->osfhnd + v6),
                lpBuffer: Buffer,
                nNumberOfBytesToWrite: v24 - Buffer,
                lpNumberOfBytesWritten: &v40,
                lpOverlapped: nullptr) )
          break;
        v44 += v40;
        if ( (int)v40 < v26 || v21 - s >= cnt )
          goto LABEL_86;
      }
    }
  }
LABEL_85:
  *(_DWORD *)pwc = GetLastError();
LABEL_86:
  if ( v44 == 0 )
  {
    if ( *(_DWORD *)pwc != 0 )
    {
      if ( *(_DWORD *)pwc == 5 )
      {
        *_errno() = 9;
        *__doserrno() = 5;
      }
      else
      {
        _dosmaperr(oserrno: *(unsigned int *)pwc);
      }
    }
    else
    {
      if ( (*(&(*v39)->osfile + v6) & 0x40) != 0 && *s == 26 )
        return 0;
      *_errno() = 28;
      *__doserrno() = 0;
    }
    return -1;
  }
  return v44 - v42;
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x100956F0
// Name: public: CShuffledWorkUnitWalker::CShuffledWorkUnitWalker(void)
// Source: json
//------------------------------------------------------------------------------
CShuffledWorkUnitWalker *__thiscall CShuffledWorkUnitWalker::CShuffledWorkUnitWalker(CShuffledWorkUnitWalker *this)
{
  this->m_CompletedWUBits.m_Memory.m_pMemory = nullptr;
  this->m_CompletedWUBits.m_Memory.m_nAllocationCount = 0;
  this->m_CompletedWUBits.m_Memory.m_nGrowSize = 0;
  this->m_CompletedWUBits.m_Size = 0;
  this->m_CompletedWUBits.m_pElements = nullptr;
  this->m_WorkUnitsRemaining.m_Memory.m_pMemory = nullptr;
  this->m_WorkUnitsRemaining.m_Memory.m_nAllocationCount = 0;
  this->m_WorkUnitsRemaining.m_Memory.m_nGrowSize = 0;
  this->m_WorkUnitsRemaining.m_LastAlloc.index = -1;
  this->m_WorkUnitsRemaining.m_Head = -1;
  this->m_WorkUnitsRemaining.m_Tail = -1;
  this->m_WorkUnitsRemaining.m_FirstFree = -1;
  this->m_WorkUnitsRemaining.m_pElements = this->m_WorkUnitsRemaining.m_Memory.m_pMemory;
  this->m_WorkUnitsRemaining.m_ElementCount = 0;
  this->m_WorkUnitsRemaining.m_NumAlloced = 0;
  this->m_WorkUnitsMap.m_Memory.m_pMemory = nullptr;
  this->m_WorkUnitsMap.m_Memory.m_nAllocationCount = 0;
  this->m_WorkUnitsMap.m_Memory.m_nGrowSize = 0;
  this->m_WorkUnitsMap.m_Size = 0;
  this->m_WorkUnitsMap.m_pElements = nullptr;
  this->m_LocalCompletedWUBits.m_Memory.m_pMemory = nullptr;
  this->m_LocalCompletedWUBits.m_Memory.m_nAllocationCount = 0;
  this->m_LocalCompletedWUBits.m_Memory.m_nGrowSize = 0;
  this->m_LocalCompletedWUBits.m_Size = 0;
  this->m_LocalCompletedWUBits.m_pElements = nullptr;
  this->m_Walker.m_WorkerInfos.m_Memory.m_pMemory = nullptr;
  this->m_Walker.m_WorkerInfos.m_Memory.m_nAllocationCount = 0;
  this->m_Walker.m_WorkerInfos.m_Memory.m_nGrowSize = 0;
  this->m_Walker.m_WorkerInfos.m_Size = 0;
  this->m_Walker.m_WorkerInfos.m_pElements = nullptr;
  this->m_Walker.m_nWorkUnits = 0;
  CCriticalSection::CCriticalSection(this: &this->m_CS);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100957A0
// Name: public: CShuffledWorkUnitWalker::~CShuffledWorkUnitWalker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShuffledWorkUnitWalker::~CShuffledWorkUnitWalker(CShuffledWorkUnitWalker *this)
{
  CCriticalSection::~CCriticalSection(this: &this->m_CS);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Walker.m_WorkerInfos);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_LocalCompletedWUBits);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_WorkUnitsMap);
  CUtlLinkedList<unsigned __int64,unsigned __int64,0,unsigned __int64,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>>::RemoveAll(this: &this->m_WorkUnitsRemaining);
  if ( this->m_WorkUnitsRemaining.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_WorkUnitsRemaining.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WorkUnitsRemaining.m_Memory.m_pMemory);
      this->m_WorkUnitsRemaining.m_Memory.m_pMemory = nullptr;
    }
    this->m_WorkUnitsRemaining.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>((CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10095810
// Name: public: void CDSInfo::ReadWUIndex(unsigned __int64 __near *,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDSInfo::ReadWUIndex(CDSInfo *this, unsigned __int8 *pWU, MessageBuffer *pBuf)
{
  if ( HIDWORD(this->m_nWorkUnits) != 0 )
  {
    MessageBuffer::read(this: pBuf, p: pWU, bytes: 8u);
  }
  else if ( LODWORD(this->m_nWorkUnits) > 0xFFFF )
  {
    MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&pBuf, bytes: 4u);
    *(_QWORD *)pWU = (unsigned int)pBuf;
  }
  else
  {
    MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&pBuf, bytes: 2u);
    *(_QWORD *)pWU = (unsigned __int16)pBuf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10095890
// Name: public: virtual void CDistributor_SDKWorker::RequestShuffle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKWorker::RequestShuffle(CDistributor_SDKWorker *this)
{
  int Name; // eax
  MessageBuffer mb; // [esp+0h] [ebp-10h] BYREF

  MessageBuffer::MessageBuffer(this: &mb);
  PrepareDistributeWorkHeader(pBuf: &mb, cSubpacketID: 0x33u);
  Name = ConCommandBase::GetName(this: (CVTFTexture *)&mb);
  VMPI_SendData(pData: mb.data, nBytes: Name, iDest: 0, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x100958E0
// Name: public: virtual void CDistributor_SDKWorker::NoteLocalWorkUnitCompleted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKWorker::NoteLocalWorkUnitCompleted(CDistributor_SDKWorker *this, unsigned __int64 iWU)
{
  unsigned __int8 *v3; // eax
  CCriticalSectionLock v4; // [esp+4h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &v4, pCS: &this->m_WorkUnitWalker.m_CS);
  CCriticalSectionLock::Lock(this: &v4);
  v3 = &this->m_WorkUnitWalker.m_LocalCompletedWUBits.m_Memory.m_pMemory[iWU >> 3];
  *v3 |= 1 << (iWU & 7);
  CCriticalSectionLock::~CCriticalSectionLock(this: &v4);
}

//------------------------------------------------------------------------------
// Address: 0x10095930
// Name: public: bool CWorkUnitWalker::GetNextWorkUnit(int,unsigned __int64 __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWorkUnitWalker::GetNextWorkUnit(
        CWorkUnitWalker *this,
        int iWorker,
        unsigned __int64 *pWUIndex,
        bool *bWorkerFinishedHisColumn)
{
  CWorkUnitWalker::CWorkerInfo *v5; // edi
  unsigned int m_iWorkUnitOffset_high; // eax
  unsigned int m_iWorkUnitOffset; // ecx
  unsigned __int64 v8; // rax
  bool v9; // cf

  if ( iWorker < 0 )
    return 0;
  if ( iWorker >= this->m_WorkerInfos.m_Size )
    return 0;
  v5 = &this->m_WorkerInfos.m_Memory.m_pMemory[iWorker];
  m_iWorkUnitOffset_high = HIDWORD(v5->m_iWorkUnitOffset);
  m_iWorkUnitOffset = v5->m_iWorkUnitOffset;
  if ( __PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) >= this->m_nWorkUnits )
    return 0;
  if ( __PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) < this->m_MatrixWidth )
  {
    *bWorkerFinishedHisColumn = false;
  }
  else
  {
    v8 = (__PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) / this->m_MatrixWidth + 1) * this->m_MatrixWidth
       - __PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) % this->m_MatrixWidth
       - 1;
    m_iWorkUnitOffset = v8;
    m_iWorkUnitOffset_high = HIDWORD(v8);
    *bWorkerFinishedHisColumn = true;
  }
  *pWUIndex = (__PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) + v5->m_iStartWorkUnit) % this->m_nWorkUnits;
  v9 = __CFADD__(LODWORD(v5->m_iWorkUnitOffset)++, 1);
  HIDWORD(v5->m_iWorkUnitOffset) += v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10095A00
// Name: public: bool CShuffledWorkUnitWalker::Thread_GetNextWorkUnit(int,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShuffledWorkUnitWalker::Thread_GetNextWorkUnit(
        CShuffledWorkUnitWalker *this,
        int iWorker,
        unsigned __int64 *pWUIndex)
{
  unsigned __int64 *m_pMemory; // eax
  int v5; // ecx
  int v6; // edx
  unsigned __int8 v7; // al
  int v8; // ecx
  unsigned __int64 v9; // rt0
  int v11; // [esp+0h] [ebp-20h]
  unsigned __int64 iUnmappedWorkUnit; // [esp+Ch] [ebp-14h] BYREF
  CCriticalSectionLock csLock; // [esp+14h] [ebp-Ch] BYREF
  bool bWorkerFinishedHisColumn; // [esp+1Fh] [ebp-1h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  if ( CWorkUnitWalker::GetNextWorkUnit(
         this: &this->m_Walker,
         iWorker,
         pWUIndex: &iUnmappedWorkUnit,
         &bWorkerFinishedHisColumn) != 0 )
  {
    while ( 1 )
    {
      if ( bWorkerFinishedHisColumn
        && this->m_iLastShuffleRequest != this->m_iCurShuffle
        && _Plat_FloatTime(a1: v11) - this->m_flLastShuffleTime > 2.0 )
      {
        this->m_pShuffleRequester->RequestShuffle(this: this->m_pShuffleRequester);
        this->m_iLastShuffleRequest = this->m_iCurShuffle;
      }
      m_pMemory = this->m_WorkUnitsMap.m_Memory.m_pMemory;
      v5 = iUnmappedWorkUnit;
      v6 = m_pMemory[iUnmappedWorkUnit];
      *(_DWORD *)pWUIndex = v6;
      *((_DWORD *)pWUIndex + 1) = HIDWORD(m_pMemory[v5]);
      v7 = 1 << (v6 & 7);
      LODWORD(v9) = v6;
      HIDWORD(v9) = *((_DWORD *)pWUIndex + 1);
      v8 = v9 >> 3;
      if ( (v7 & this->m_CompletedWUBits.m_Memory.m_pMemory[v8]) == 0
        && (v7 & this->m_LocalCompletedWUBits.m_Memory.m_pMemory[v8]) == 0 )
      {
        break;
      }
      if ( CWorkUnitWalker::GetNextWorkUnit(
             this: &this->m_Walker,
             iWorker,
             pWUIndex: &iUnmappedWorkUnit,
             &bWorkerFinishedHisColumn) == 0 )
        goto LABEL_9;
    }
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 1;
  }
  else
  {
LABEL_9:
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10095B10
// Name: public: virtual bool CDistributor_SDKWorker::GetNextWorkUnit(unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_SDKWorker::GetNextWorkUnit(CDistributor_SDKWorker *this, unsigned __int64 *pWUIndex)
{
  int m_iMyWorkUnitWalkerID; // eax

  m_iMyWorkUnitWalkerID = this->m_iMyWorkUnitWalkerID;
  if ( m_iMyWorkUnitWalkerID == -1 )
    return 0;
  else
    return CShuffledWorkUnitWalker::Thread_GetNextWorkUnit(
             this: &this->m_WorkUnitWalker,
             iWorker: m_iMyWorkUnitWalkerID,
             pWUIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10095CE0
// Name: public: unsigned long CShuffledWorkUnitWalker::GetShuffleCRC(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __fastcall CShuffledWorkUnitWalker::GetShuffleCRC(CShuffledWorkUnitWalker *this, int a2)
{
  int m_Head; // esi
  UtlLinkedListElem_t<unsigned __int64,unsigned __int64> *m_pMemory; // eax
  int v5; // esi
  int i; // esi
  unsigned int v7; // esi
  CCriticalSectionLock csLock; // [esp+4h] [ebp-14h] BYREF
  unsigned __int64 iWorkUnit; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int ret; // [esp+14h] [ebp-4h] BYREF

  if ( (`CShuffledWorkUnitWalker::GetShuffleCRC'::`2'::`local static guard' & 1) == 0 )
  {
    `CShuffledWorkUnitWalker::GetShuffleCRC'::`2'::`local static guard' |= 1u;
    `CShuffledWorkUnitWalker::GetShuffleCRC'::`2'::bCalcShuffleCRC = VMPI_IsParamUsed(
                                                                       a1: (int)this,
                                                                       a2,
                                                                       eParam: mpi_CalcShuffleCRC);
  }
  if ( !`CShuffledWorkUnitWalker::GetShuffleCRC'::`2'::bCalcShuffleCRC )
    return 0;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  CRC32_Init(pulCRC: &ret);
  m_Head = this->m_WorkUnitsRemaining.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_WorkUnitsRemaining.m_Memory.m_pMemory;
    do
    {
      v5 = m_Head;
      iWorkUnit = m_pMemory[v5].m_Element;
      CRC32_ProcessBuffer(pulCRC: &ret, pBuffer: &iWorkUnit, nBuffer: 8);
      m_pMemory = this->m_WorkUnitsRemaining.m_Memory.m_pMemory;
      m_Head = m_pMemory[v5].m_Next;
    }
    while ( m_Head != -1 );
  }
  for ( i = 0; i < this->m_WorkUnitsMap.m_Size; ++i )
  {
    iWorkUnit = this->m_WorkUnitsMap.m_Memory.m_pMemory[i];
    CRC32_ProcessBuffer(pulCRC: &ret, pBuffer: &iWorkUnit, nBuffer: 8);
  }
  CRC32_Final(pulCRC: &ret);
  v7 = ret;
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10095F00
// Name: public: void CWorkUnitWalker::Init(unsigned __int64,unsigned __int64,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkUnitWalker::Init(
        CWorkUnitWalker *this,
        unsigned __int64 matrixWidth,
        unsigned __int64 matrixHeight,
        unsigned __int64 nWorkUnits)
{
  int v5; // esi
  __int64 v6; // rax
  CWorkUnitWalker::CWorkerInfo *m_pMemory; // eax
  int v8; // [esp+28h] [ebp+1Ch]

  this->m_nWorkUnits = nWorkUnits;
  this->m_MatrixWidth = matrixWidth;
  v5 = 0;
  this->m_MatrixHeight = matrixHeight;
  this->m_WorkerInfos.m_Size = 0;
  if ( SLODWORD(this->m_MatrixHeight) > 0 )
    CUtlVector<CWorkUnitWalker::CWorkerInfo,CUtlMemory<CWorkUnitWalker::CWorkerInfo,int>>::InsertMultipleBefore(
      this: &this->m_WorkerInfos,
      elem: 0,
      num: this->m_MatrixHeight);
  v8 = 0;
  if ( HIDWORD(this->m_MatrixHeight) != 0 || LODWORD(this->m_MatrixHeight) != 0 )
  {
    v6 = 0;
    do
    {
      this->m_WorkerInfos.m_Memory.m_pMemory[v5].m_iStartWorkUnit = v6 * matrixWidth;
      m_pMemory = this->m_WorkerInfos.m_Memory.m_pMemory;
      LODWORD(m_pMemory[v5].m_iWorkUnitOffset) = 0;
      HIDWORD(m_pMemory[v5].m_iWorkUnitOffset) = 0;
      v6 = ++v8;
      ++v5;
    }
    while ( v8 < this->m_MatrixHeight );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10095FB0
// Name: public: void CShuffledWorkUnitWalker::Shuffle(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShuffledWorkUnitWalker::Shuffle(CShuffledWorkUnitWalker *this, int nWorkers)
{
  CShuffledWorkUnitWalker *v2; // edi
  int m_ElementCount; // eax
  int m_Head; // esi
  UtlLinkedListElem_t<unsigned __int64,unsigned __int64> *m_pMemory; // edi
  int v6; // esi
  int v7; // ecx
  unsigned __int64 *v8; // eax
  unsigned int v9; // kr00_4
  int m_Element; // edx
  unsigned __int64 m_ElementCount_low; // [esp-14h] [ebp-48h]
  int v12; // [esp+0h] [ebp-34h]
  CCriticalSectionLock csLock; // [esp+10h] [ebp-24h] BYREF
  unsigned __int64 matrixHeight; // [esp+18h] [ebp-1Ch]
  unsigned __int64 iWorkUnit; // [esp+20h] [ebp-14h]
  unsigned __int64 matrixWidth; // [esp+28h] [ebp-Ch]
  CShuffledWorkUnitWalker *v17; // [esp+30h] [ebp-4h]

  v2 = this;
  v17 = this;
  if ( nWorkers != 0 )
  {
    ++this->m_iCurShuffle;
    this->m_flLastShuffleTime = _Plat_FloatTime(a1: v12);
    CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &v2->m_CS);
    CCriticalSectionLock::Lock(this: &csLock);
    v2->m_WorkUnitsMap.m_Size = 0;
    m_ElementCount = v2->m_WorkUnitsRemaining.m_ElementCount;
    if ( v2->m_WorkUnitsMap.m_Size < m_ElementCount )
      CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
        this: (CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *)&v2->m_WorkUnitsMap,
        elem: v2->m_WorkUnitsMap.m_Size,
        num: m_ElementCount - v2->m_WorkUnitsMap.m_Size);
    m_ElementCount_low = SLODWORD(v2->m_WorkUnitsRemaining.m_ElementCount);
    matrixHeight = nWorkers;
    matrixWidth = m_ElementCount_low / nWorkers;
    if ( m_ElementCount_low % nWorkers != 0 )
      ++matrixWidth;
    m_Head = v2->m_WorkUnitsRemaining.m_Head;
    iWorkUnit = 0;
    if ( m_Head != -1 )
    {
      m_pMemory = v2->m_WorkUnitsRemaining.m_Memory.m_pMemory;
      do
      {
        v6 = m_Head;
        v7 = iWorkUnit / matrixHeight + matrixWidth * (iWorkUnit % matrixHeight);
        v8 = v17->m_WorkUnitsMap.m_Memory.m_pMemory;
        v9 = iWorkUnit;
        LODWORD(iWorkUnit) = iWorkUnit + 1;
        m_Element = m_pMemory[v6].m_Element;
        iWorkUnit = __PAIR64__(HIDWORD(iWorkUnit), v9) + 1;
        LODWORD(v8[v7]) = m_Element;
        HIDWORD(v8[v7]) = HIDWORD(m_pMemory[v6].m_Element);
        m_pMemory = v17->m_WorkUnitsRemaining.m_Memory.m_pMemory;
        m_Head = m_pMemory[v6].m_Next;
      }
      while ( m_Head != -1 );
      v2 = v17;
    }
    CWorkUnitWalker::Init(
      this: &v2->m_Walker,
      matrixWidth,
      matrixHeight,
      nWorkUnits: SLODWORD(v2->m_WorkUnitsRemaining.m_ElementCount));
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100960E0
// Name: public: void CShuffledWorkUnitWalker::Thread_NoteWorkUnitCompleted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShuffledWorkUnitWalker::Thread_NoteWorkUnitCompleted(
        CShuffledWorkUnitWalker *this,
        unsigned __int64 iWU)
{
  unsigned __int8 *m_pMemory; // esi
  UtlLinkedListElem_t<unsigned __int64,unsigned __int64> *v4; // eax
  int v5; // ecx
  int v6; // eax
  CCriticalSectionLock csLock; // [esp+Ch] [ebp-10h] BYREF
  int v8; // [esp+14h] [ebp-8h]
  unsigned __int8 v9; // [esp+1Bh] [ebp-1h]

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  m_pMemory = this->m_CompletedWUBits.m_Memory.m_pMemory;
  v9 = 1 << (iWU & 7);
  v8 = iWU >> 3;
  if ( (v9 & m_pMemory[v8]) == 0 )
  {
    CUtlLinkedList<unsigned __int64,unsigned __int64,0,unsigned __int64,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>>::Unlink(
      this: &this->m_WorkUnitsRemaining,
      elem: iWU);
    v4 = this->m_WorkUnitsRemaining.m_Memory.m_pMemory;
    v5 = 3 * iWU;
    *((_DWORD *)&v4->m_Next + 2 * v5) = this->m_WorkUnitsRemaining.m_FirstFree;
    *((_DWORD *)&v4->m_Next + 2 * v5 + 1) = HIDWORD(this->m_WorkUnitsRemaining.m_FirstFree);
    LOBYTE(v5) = v9;
    HIDWORD(this->m_WorkUnitsRemaining.m_FirstFree) = HIDWORD(iWU);
    v6 = v8;
    LODWORD(this->m_WorkUnitsRemaining.m_FirstFree) = iWU;
    this->m_CompletedWUBits.m_Memory.m_pMemory[v6] |= v5;
  }
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x10096170
// Name: public: virtual bool CDistributor_SDKWorker::HandlePacket(class MessageBuffer __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CDistributor_SDKWorker::HandlePacket(
        CDistributor_SDKWorker *this,
        MessageBuffer *pBuf,
        int iSource,
        unsigned __int16 bIgnoreContents)
{
  MessageBuffer *v4; // esi
  char v5; // al
  int v7; // edx
  int v8; // edx
  unsigned int ShuffleCRC; // eax
  unsigned int v11; // ebx
  unsigned __int64 iWU; // [esp+8h] [ebp-18h] BYREF
  unsigned __int64 nCompleted; // [esp+10h] [ebp-10h] BYREF
  __int64 v14; // [esp+18h] [ebp-8h] OVERLAPPED BYREF

  v4 = pBuf;
  v5 = pBuf->data[1];
  if ( v5 == 50 )
  {
    if ( (_BYTE)bIgnoreContents == 0 )
    {
      MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&pBuf, bytes: 2u);
      MessageBuffer::read(this: v4, p: (unsigned __int8 *)&v14 + 4, bytes: 4u);
      MessageBuffer::read(this: v4, p: (unsigned __int8 *)&bIgnoreContents, bytes: 2u);
      v7 = (unsigned __int16)pBuf;
      this->m_iMyWorkUnitWalkerID = bIgnoreContents;
      CShuffledWorkUnitWalker::Shuffle(this: &this->m_WorkUnitWalker, nWorkers: v7);
      ShuffleCRC = CShuffledWorkUnitWalker::GetShuffleCRC(this: &this->m_WorkUnitWalker, a2: v8);
      if ( ShuffleCRC != HIDWORD(v14) && ++`CDistributor_SDKWorker::HandlePacket'::`10'::nWarnings <= 2 )
        _Warning(a1: "\nShuffle CRC mismatch\n");
    }
    return 1;
  }
  if ( v5 != 52 )
    return 0;
  if ( (_BYTE)bIgnoreContents != 0 )
    return 1;
  CDSInfo::ReadWUIndex(this: this->m_pInfo, pWU: (unsigned __int8 *)&nCompleted, pBuf);
  v14 = 0;
  if ( nCompleted != 0 )
  {
    v11 = HIDWORD(v14);
    do
    {
      CDSInfo::ReadWUIndex(this: this->m_pInfo, pWU: (unsigned __int8 *)&iWU, pBuf: v4);
      CShuffledWorkUnitWalker::Thread_NoteWorkUnitCompleted(this: &this->m_WorkUnitWalker, iWU);
      v11 = (__PAIR64__(v11, v14) + 1) >> 32;
      LODWORD(v14) = v14 + 1;
    }
    while ( __PAIR64__(v11, v14) < nCompleted );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10096280
// Name: public: CDistributor_SDKMaster::CDistributor_SDKMaster(void)
// Source: json
//------------------------------------------------------------------------------
CDistributor_SDKMaster *__thiscall CDistributor_SDKMaster::CDistributor_SDKMaster(CDistributor_SDKMaster *this)
{
  this->IShuffleRequester::__vftable = (IShuffleRequester_vtbl *)&IShuffleRequester::`vftable';
  this->IWorkUnitDistributorMaster::__vftable = (CDistributor_SDKMaster_vtbl *)&CDistributor_SDKMaster::`vftable'{for `IWorkUnitDistributorMaster'};
  this->IShuffleRequester::__vftable = (IShuffleRequester_vtbl *)&CDistributor_SDKMaster::`vftable'{for `IShuffleRequester'};
  CCriticalSection::CCriticalSection(this: &this->m_WorkersReadyCS);
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Memory.m_pMemory = nullptr;
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Memory.m_nAllocationCount = 0;
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Memory.m_nGrowSize = 0;
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Size = 0;
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_pElements = nullptr;
  CCriticalSection::CCriticalSection(this: &this->m_WUsCompletedCS);
  this->m_WUsCompletedCS.m_Data.m_Completed.m_Memory.m_pMemory = nullptr;
  this->m_WUsCompletedCS.m_Data.m_Completed.m_Memory.m_nAllocationCount = 0;
  this->m_WUsCompletedCS.m_Data.m_Completed.m_Memory.m_nGrowSize = 0;
  this->m_WUsCompletedCS.m_Data.m_Completed.m_Size = 0;
  this->m_WUsCompletedCS.m_Data.m_Completed.m_pElements = nullptr;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_Memory.m_pMemory = nullptr;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_Memory.m_nAllocationCount = 0;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_Memory.m_nGrowSize = 0;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_Size = 0;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_pElements = nullptr;
  MessageBuffer::MessageBuffer(this: &this->m_WUSCompletedMessageBuffer);
  CShuffledWorkUnitWalker::CShuffledWorkUnitWalker(this: &this->m_WorkUnitWalker);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10096320
// Name: public: void CDSInfo::WriteWUIndex(unsigned __int64,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDSInfo::WriteWUIndex(CDSInfo *this, unsigned __int64 iWU, MessageBuffer *pBuf)
{
  unsigned int val; // [esp+0h] [ebp-4h] BYREF

  val = (unsigned int)this;
  if ( HIDWORD(this->m_nWorkUnits) != 0 )
  {
    MessageBuffer::write(this: pBuf, p: (unsigned __int8 *)&iWU, bytes: 8u);
  }
  else if ( LODWORD(this->m_nWorkUnits) > 0xFFFF )
  {
    val = iWU;
    MessageBuffer::write(this: pBuf, p: (unsigned __int8 *)&val, bytes: 4u);
  }
  else
  {
    val = (unsigned __int16)iWU;
    MessageBuffer::write(this: pBuf, p: (unsigned __int8 *)&val, bytes: 2u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100963A0
// Name: public: virtual void CDistributor_SDKMaster::RequestShuffle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::RequestShuffle(CDistributor_SDKMaster *this)
{
  BYTE1(this->m_bUsingMasterLocalThreads) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100963B0
// Name: public: virtual bool CDistributor_SDKMaster::HandlePacket(class MessageBuffer __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_SDKMaster::HandlePacket(
        CDistributor_SDKMaster *this,
        MessageBuffer *pBuf,
        int iSource,
        bool bIgnoreContents)
{
  if ( pBuf->data[1] == 51 )
  {
    if ( bIgnoreContents )
      return 1;
    this->m_bShuffleRequested = true;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100963E0
// Name: public: void CDistributor_SDKMaster::Master_WorkerThread(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::Master_WorkerThread(CDistributor_SDKMaster *this, int iThread)
{
  CShuffledWorkUnitWalker *p_m_WorkUnitWalker; // ebx
  CCriticalSection *p_m_CS; // esi
  int v4; // edi
  unsigned __int64 v5; // kr08_8
  unsigned __int8 *v6; // eax
  int v7; // edi
  CCriticalSectionLock v8; // [esp+Ch] [ebp-24h] BYREF
  unsigned __int64 iWU; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int m_ElementCount; // [esp+1Ch] [ebp-14h]
  CCriticalSectionLock v11; // [esp+24h] [ebp-Ch] BYREF
  CDistributor_SDKMaster *v12; // [esp+2Ch] [ebp-4h]

  p_m_WorkUnitWalker = &this->m_WorkUnitWalker;
  v12 = this;
  p_m_CS = &this->m_WorkUnitWalker.m_CS;
  CCriticalSectionLock::CCriticalSectionLock(this: &v11, pCS: &this->m_WorkUnitWalker.m_CS);
  CCriticalSectionLock::Lock(this: &v11);
  v4 = SLODWORD(p_m_WorkUnitWalker->m_WorkUnitsRemaining.m_ElementCount) >> 31;
  m_ElementCount = p_m_WorkUnitWalker->m_WorkUnitsRemaining.m_ElementCount;
  CCriticalSectionLock::~CCriticalSectionLock(this: &v11);
  if ( __PAIR64__(v4, m_ElementCount) != 0 )
  {
    while ( !g_bVMPIEarlyExit )
    {
      if ( CShuffledWorkUnitWalker::Thread_GetNextWorkUnit(this: p_m_WorkUnitWalker, iWorker: 0, pWUIndex: &iWU) != 0 )
      {
        CCriticalSectionLock::CCriticalSectionLock(this: &v8, pCS: p_m_CS);
        CCriticalSectionLock::Lock(this: &v8);
        v5 = iWU;
        v6 = &p_m_WorkUnitWalker->m_LocalCompletedWUBits.m_Memory.m_pMemory[iWU >> 3];
        *v6 |= 1 << (iWU & 7);
        CCriticalSectionLock::~CCriticalSectionLock(this: &v8);
        ((void (__cdecl *)(int, _DWORD, _DWORD, _DWORD))v12->m_pInfo->m_WorkerInfo.m_pProcessFn)(
          a1: iThread,
          a2: v5,
          a3: HIDWORD(v5),
          a4: 0);
        NotifyLocalMasterCompletedWorkUnit(iWorkUnit: v5);
      }
      else
      {
        VMPI_Sleep(ms: 0xAu);
      }
      p_m_CS = &p_m_WorkUnitWalker->m_CS;
      CCriticalSectionLock::CCriticalSectionLock(this: &v11, pCS: &p_m_WorkUnitWalker->m_CS);
      CCriticalSectionLock::Lock(this: &v11);
      v7 = SLODWORD(p_m_WorkUnitWalker->m_WorkUnitsRemaining.m_ElementCount) >> 31;
      m_ElementCount = p_m_WorkUnitWalker->m_WorkUnitsRemaining.m_ElementCount;
      CCriticalSectionLock::~CCriticalSectionLock(this: &v11);
      if ( v7 == 0 && m_ElementCount == 0 )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096500
// Name: public: int CDistributor_SDKMaster::BuildWUsCompletedMessage(class CUtlVector<unsigned __int64,class CUtlMemory<unsigned __int64,int>> __near &,class MessageBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDistributor_SDKMaster::BuildWUsCompletedMessage(
        CDistributor_SDKMaster *this,
        CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *wusCompleted,
        MessageBuffer *mb)
{
  MessageBuffer *v3; // esi
  CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *v5; // edi
  int i; // esi
  unsigned __int64 *m_pMemory; // eax
  CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *v8; // ecx
  CDSInfo *m_pInfo; // eax
  _DWORD p[2]; // [esp+Ch] [ebp-8h] BYREF

  v3 = mb;
  PrepareDistributeWorkHeader(pBuf: mb, cSubpacketID: 0x34u);
  v5 = wusCompleted;
  CDSInfo::WriteWUIndex(this: this->m_pInfo, iWU: wusCompleted->m_Size, pBuf: v3);
  for ( i = 0; i < v5->m_Size; ++i )
  {
    m_pMemory = v5->m_Memory.m_pMemory;
    v8 = (CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *)v5->m_Memory.m_pMemory[i];
    p[0] = v8;
    p[1] = HIDWORD(m_pMemory[i]);
    m_pInfo = this->m_pInfo;
    if ( HIDWORD(m_pInfo->m_nWorkUnits) != 0 )
    {
      MessageBuffer::write(this: mb, (unsigned __int8 *)p, bytes: 8u);
    }
    else if ( LODWORD(m_pInfo->m_nWorkUnits) > 0xFFFF )
    {
      wusCompleted = v8;
      MessageBuffer::write(this: mb, p: (unsigned __int8 *)&wusCompleted, bytes: 4u);
    }
    else
    {
      wusCompleted = (CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *)(unsigned __int16)v8;
      MessageBuffer::write(this: mb, p: (unsigned __int8 *)&wusCompleted, bytes: 2u);
    }
  }
  return v5->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100965B0
// Name: public: static void CDistributor_SDKMaster::Master_WorkerThread_Static(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDistributor_SDKMaster::Master_WorkerThread_Static(int iThread, CDistributor_SDKMaster *pUserData)
{
  CDistributor_SDKMaster::Master_WorkerThread(this: pUserData, iThread);
}

//------------------------------------------------------------------------------
// Address: 0x100965D0
// Name: public: virtual void CDistributor_SDKMaster::DisconnectHandler(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::DisconnectHandler(CDistributor_SDKMaster *this, int workerID)
{
  int m_Size; // ecx
  int v4; // eax
  int *m_pMemory; // edx

  CCriticalSection::Lock(this: &this->m_WorkersReadyCS);
  m_Size = this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Memory.m_pMemory;
    while ( *m_pMemory != workerID )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_8;
    }
    if ( v4 != -1 )
      this->m_bForceShuffle = true;
  }
LABEL_8:
  CCriticalSection::Unlock(this: &this->m_WorkersReadyCS);
}

//------------------------------------------------------------------------------
// Address: 0x100966E0
// Name: public: virtual void CDistributor_SDKMaster::OnWorkerReady(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::OnWorkerReady(CDistributor_SDKMaster *this, int iSource)
{
  CCriticalSectionData<CDistributor_SDKMaster::CWorkersReady> *p_m_WorkersReadyCS; // esi
  int m_Size; // edi
  int v5; // eax
  int *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  int *v8; // ecx
  int v9; // eax
  int *v10; // edi
  int Name; // eax
  CCriticalSectionData<CDistributor_SDKMaster::CWorkersReady> *v12; // [esp+Ch] [ebp-4h]

  p_m_WorkersReadyCS = &this->m_WorkersReadyCS;
  v12 = &this->m_WorkersReadyCS;
  CCriticalSection::Lock(this: &this->m_WorkersReadyCS);
  m_Size = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_pMemory;
  while ( *m_pMemory != iSource )
  {
    ++v5;
    ++m_pMemory;
    if ( v5 >= m_Size )
      goto LABEL_7;
  }
  if ( v5 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&p_m_WorkersReadyCS->m_Data,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Size;
    v8 = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_pMemory;
    v9 = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Size - m_Size - 1;
    p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_pElements = v8;
    if ( v9 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v8[m_Size + 1], src: (unsigned __int8 *)&v8[m_Size], count: 4 * v9);
    v10 = &p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = iSource;
    CCriticalSection::Lock(this: &this->m_WUsCompletedCS);
    MessageBuffer::setLen(this: &this->m_WUSCompletedMessageBuffer, nlen: 0);
    CDistributor_SDKMaster::BuildWUsCompletedMessage(
      this,
      wusCompleted: &this->m_WUsCompletedCS.m_Data.m_Completed,
      mb: &this->m_WUSCompletedMessageBuffer);
    CCriticalSection::Unlock(this: &this->m_WUsCompletedCS);
    Name = ConCommandBase::GetName(this: (CVTFTexture *)&this->m_WUSCompletedMessageBuffer);
    VMPI_SendData(pData: this->m_WUSCompletedMessageBuffer.data, nBytes: Name, iDest: iSource, fVMPISendFlags: 0);
    this->m_bForceShuffle = true;
  }
  CCriticalSection::Unlock(this: v12);
}

//------------------------------------------------------------------------------
// Address: 0x100967D0
// Name: public: void CDistributor_SDKMaster::Shuffle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::Shuffle(CDistributor_SDKMaster *this)
{
  int m_Size; // esi
  unsigned __int16 *m_pMemory; // ebx
  int v4; // eax
  CCriticalSectionData<CDistributor_SDKMaster::CWorkersReady> *p_m_WorkersReadyCS; // edi
  bool v6; // cc
  int v7; // edi
  unsigned __int16 *v8; // edi
  CDistributor_SDKMaster *v9; // edi
  MessageBuffer *p_m_WUSCompletedMessageBuffer; // edi
  int m_bUsingMasterLocalThreads; // eax
  int Name; // eax
  int v13; // edi
  CCriticalSectionData<CDistributor_SDKMaster::CWUsCompleted> *p_m_WUsCompletedCS; // ecx
  CDistributor_SDKMaster *v15; // edi
  int v16; // edx
  int j; // edi
  int v18; // eax
  int v19; // [esp-8h] [ebp-50h]
  int v20; // [esp-8h] [ebp-50h]
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > whosWorking; // [esp+Ch] [ebp-3Ch] BYREF
  MessageBuffer mb; // [esp+20h] [ebp-28h] BYREF
  unsigned int shuffleCRC; // [esp+30h] [ebp-18h] BYREF
  int nWorkers; // [esp+34h] [ebp-14h] BYREF
  int iWorker; // [esp+38h] [ebp-10h]
  int id; // [esp+3Ch] [ebp-Ch] BYREF
  int i; // [esp+40h] [ebp-8h]
  CDistributor_SDKMaster *v28; // [esp+44h] [ebp-4h]

  m_Size = 0;
  m_pMemory = nullptr;
  v28 = this;
  memset(&whosWorking, 0, sizeof(whosWorking));
  if ( this->m_bUsingMasterLocalThreads != 0 )
  {
    CUtlMemory<CIncrementalHeader::CLMSize,int>::Grow(
      this: (CUtlMemory<CBSPTreeData::Leaf_t,int> *)&whosWorking,
      num: 1);
    m_pMemory = whosWorking.m_Memory.m_pMemory;
    m_Size = whosWorking.m_Size + 1;
    v4 = whosWorking.m_Size++;
    whosWorking.m_pElements = whosWorking.m_Memory.m_pMemory;
    if ( v4 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)whosWorking.m_Memory.m_pMemory + 2,
        src: (unsigned __int8 *)whosWorking.m_Memory.m_pMemory,
        count: 2 * v4);
    if ( m_pMemory != nullptr )
      *m_pMemory = 0;
  }
  p_m_WorkersReadyCS = &this->m_WorkersReadyCS;
  CCriticalSection::Lock(this: p_m_WorkersReadyCS);
  v6 = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Size <= 0;
  i = 0;
  if ( !v6 )
  {
    do
    {
      iWorker = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_pMemory[i];
      if ( VMPI_IsProcConnected(procID: iWorker) )
      {
        v7 = m_Size;
        if ( m_Size + 1 > whosWorking.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CIncrementalHeader::CLMSize,int>::Grow(
            this: (CUtlMemory<CBSPTreeData::Leaf_t,int> *)&whosWorking,
            num: m_Size - whosWorking.m_Memory.m_nAllocationCount + 1);
          m_Size = whosWorking.m_Size;
          m_pMemory = whosWorking.m_Memory.m_pMemory;
        }
        whosWorking.m_Size = ++m_Size;
        whosWorking.m_pElements = m_pMemory;
        if ( m_Size - v7 - 1 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[v7 + 1],
            src: (unsigned __int8 *)&m_pMemory[v7],
            count: 2 * (m_Size - v7 - 1));
        v8 = &m_pMemory[v7];
        if ( v8 != nullptr )
          *v8 = iWorker;
      }
      p_m_WorkersReadyCS = &v28->m_WorkersReadyCS;
      ++i;
    }
    while ( i < v28->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Size );
  }
  CCriticalSection::Unlock(this: p_m_WorkersReadyCS);
  v9 = v28;
  CCriticalSection::Lock(this: &v28->m_WUsCompletedCS);
  p_m_WUSCompletedMessageBuffer = &v9->m_WUSCompletedMessageBuffer;
  MessageBuffer::setLen(this: p_m_WUSCompletedMessageBuffer, nlen: 0);
  iWorker = (int)&v28->m_WUsCompletedCS.m_Data.m_Pending;
  if ( CDistributor_SDKMaster::BuildWUsCompletedMessage(
         this: v28,
         wusCompleted: &v28->m_WUsCompletedCS.m_Data.m_Pending,
         mb: p_m_WUSCompletedMessageBuffer) > 0 )
  {
    m_bUsingMasterLocalThreads = v28->m_bUsingMasterLocalThreads;
    i = m_bUsingMasterLocalThreads;
    if ( m_bUsingMasterLocalThreads < m_Size )
    {
      while ( 1 )
      {
        v19 = m_pMemory[m_bUsingMasterLocalThreads];
        Name = ConCommandBase::GetName(this: (CVTFTexture *)p_m_WUSCompletedMessageBuffer);
        VMPI_SendData(pData: p_m_WUSCompletedMessageBuffer->data, nBytes: Name, iDest: v19, fVMPISendFlags: 0);
        if ( ++i >= m_Size )
          break;
        m_bUsingMasterLocalThreads = i;
      }
    }
  }
  v13 = iWorker;
  CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(
    this: &v28->m_WUsCompletedCS.m_Data.m_Completed,
    elem: v28->m_WUsCompletedCS.m_Data.m_Completed.m_Size,
    num: v28->m_WUsCompletedCS.m_Data.m_Pending.m_Size,
    pToInsert: *(const unsigned __int64 **)iWorker);
  p_m_WUsCompletedCS = &v28->m_WUsCompletedCS;
  *(_DWORD *)(v13 + 12) = 0;
  CCriticalSection::Unlock(this: p_m_WUsCompletedCS);
  v15 = v28;
  CShuffledWorkUnitWalker::Shuffle(this: &v28->m_WorkUnitWalker, nWorkers: m_Size);
  MessageBuffer::MessageBuffer(this: &mb);
  PrepareDistributeWorkHeader(pBuf: &mb, cSubpacketID: 0x32u);
  nWorkers = (unsigned __int16)m_Size;
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&nWorkers, bytes: 2u);
  shuffleCRC = CShuffledWorkUnitWalker::GetShuffleCRC(this: &v15->m_WorkUnitWalker, a2: v16);
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&shuffleCRC, bytes: 4u);
  iWorker = ConCommandBase::GetName(this: (CVTFTexture *)&mb);
  id = 0;
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&id, bytes: 2u);
  for ( j = v15->m_bUsingMasterLocalThreads; j < m_Size; ++j )
  {
    id = (unsigned __int16)j;
    MessageBuffer::update(this: &mb, loc: iWorker, p: (unsigned __int8 *)&id, bytes: 2u);
    v20 = m_pMemory[j];
    v18 = ConCommandBase::GetName(this: (CVTFTexture *)&mb);
    VMPI_SendData(pData: mb.data, nBytes: v18, iDest: v20, fVMPISendFlags: 0);
  }
  MessageBuffer::~MessageBuffer(this: &mb);
  if ( whosWorking.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10096A60
// Name: public: bool CDistributor_SDKMaster::Thread_HandleWorkUnitResults(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_SDKMaster::Thread_HandleWorkUnitResults(
        CDistributor_SDKMaster *this,
        unsigned __int64 iWorkUnit)
{
  unsigned int v3; // ebx
  CCriticalSectionLock v5; // [esp+Ch] [ebp-Ch] BYREF
  bool v6; // [esp+17h] [ebp-1h]

  CCriticalSectionLock::CCriticalSectionLock(this: &v5, pCS: &this->m_WorkUnitWalker.m_CS);
  CCriticalSectionLock::Lock(this: &v5);
  v3 = iWorkUnit;
  v6 = ((unsigned __int8)(1 << (iWorkUnit & 7))
      & this->m_WorkUnitWalker.m_CompletedWUBits.m_Memory.m_pMemory[iWorkUnit >> 3]) != 0;
  CCriticalSectionLock::~CCriticalSectionLock(this: &v5);
  if ( v6 )
    return 0;
  CShuffledWorkUnitWalker::Thread_NoteWorkUnitCompleted(
    this: &this->m_WorkUnitWalker,
    iWU: __PAIR64__(HIDWORD(iWorkUnit), v3));
  CCriticalSection::Lock(this: &this->m_WUsCompletedCS);
  CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
    this: &this->m_WUsCompletedCS.m_Data.m_Pending,
    elem: this->m_WUsCompletedCS.m_Data.m_Pending.m_Size,
    src: &iWorkUnit);
  CCriticalSection::Unlock(this: &this->m_WUsCompletedCS);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10096B10
// Name: class IWorkUnitDistributorWorker __near * CreateWUDistributor_SDKWorker(void)
// Source: json
//------------------------------------------------------------------------------
IWorkUnitDistributorWorker *__cdecl CreateWUDistributor_SDKWorker()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)MemAlloc_Alloc(nSize: 0x140u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = &IShuffleRequester::`vftable';
  *(_DWORD *)v0 = &CDistributor_SDKWorker::`vftable'{for `IWorkUnitDistributorWorker'};
  *((_DWORD *)v0 + 1) = &CDistributor_SDKWorker::`vftable'{for `IShuffleRequester'};
  CShuffledWorkUnitWalker::CShuffledWorkUnitWalker(this: (CShuffledWorkUnitWalker *)(v0 + 16));
  return (IWorkUnitDistributorWorker *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10096C10
// Name: public: void CShuffledWorkUnitWalker::Init(unsigned __int64,class IShuffleRequester __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShuffledWorkUnitWalker::Init(
        CShuffledWorkUnitWalker *this,
        unsigned __int64 nWorkUnits,
        IShuffleRequester *pRequester)
{
  __int64 v4; // rcx
  int v5; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  signed int v8; // eax
  int v9; // eax
  unsigned __int8 *v10; // ecx
  signed int v11; // eax
  unsigned int v12; // edi
  CUtlLinkedList<unsigned __int64,unsigned __int64,0,unsigned __int64,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64> > *p_m_WorkUnitsRemaining; // ebx
  __int64 v14; // rdi
  unsigned __int64 v15; // rax
  int v16; // [esp+0h] [ebp-14h]
  unsigned __int64 iWU; // [esp+Ch] [ebp-8h] BYREF

  HIDWORD(v4) = 0;
  this->m_iLastShuffleRequest = 0;
  this->m_iCurShuffle = 1;
  this->m_flLastShuffleTime = _Plat_FloatTime(a1: v16);
  v5 = (nWorkUnits + 7) >> 3;
  this->m_pShuffleRequester = pRequester;
  this->m_CompletedWUBits.m_Size = 0;
  if ( v5 != 0 )
  {
    m_nAllocationCount = this->m_CompletedWUBits.m_Memory.m_nAllocationCount;
    if ( v5 > m_nAllocationCount )
      CUtlMemory<char,int>::Grow(this: &this->m_CompletedWUBits.m_Memory, num: v5 - m_nAllocationCount);
    this->m_CompletedWUBits.m_Size += v5;
    m_pMemory = this->m_CompletedWUBits.m_Memory.m_pMemory;
    v8 = this->m_CompletedWUBits.m_Size - v5;
    this->m_CompletedWUBits.m_pElements = this->m_CompletedWUBits.m_Memory.m_pMemory;
    if ( v8 > 0 && v5 > 0 )
      _V_memmove(dest: &m_pMemory[v5], src: m_pMemory, count: v8);
  }
  this->m_LocalCompletedWUBits.m_Size = 0;
  if ( v5 != 0 )
  {
    v9 = this->m_LocalCompletedWUBits.m_Memory.m_nAllocationCount;
    if ( v5 > v9 )
      CUtlMemory<char,int>::Grow(this: &this->m_LocalCompletedWUBits.m_Memory, num: v5 - v9);
    this->m_LocalCompletedWUBits.m_Size += v5;
    v10 = this->m_LocalCompletedWUBits.m_Memory.m_pMemory;
    v11 = this->m_LocalCompletedWUBits.m_Size - v5;
    this->m_LocalCompletedWUBits.m_pElements = v10;
    if ( v11 > 0 && v5 > 0 )
      _V_memmove(dest: &v10[v5], src: v10, count: v11);
  }
  iWU = 0;
  if ( this->m_CompletedWUBits.m_Size != 0 )
  {
    v12 = HIDWORD(iWU);
    LODWORD(v4) = iWU;
    do
    {
      this->m_CompletedWUBits.m_Memory.m_pMemory[v4] = 0;
      this->m_LocalCompletedWUBits.m_Memory.m_pMemory[v4] = 0;
      v12 = (v4 + __PAIR64__(v12, 1)) >> 32;
      LODWORD(v4) = v4 + 1;
    }
    while ( __PAIR64__(v12, v4) < this->m_CompletedWUBits.m_Size );
  }
  iWU = 0;
  if ( nWorkUnits != 0 )
  {
    LODWORD(v14) = HIDWORD(iWU);
    p_m_WorkUnitsRemaining = &this->m_WorkUnitsRemaining;
    HIDWORD(v14) = iWU;
    do
    {
      v15 = CUtlLinkedList<unsigned __int64,unsigned __int64,0,unsigned __int64,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>>::AddToTail(
              this: p_m_WorkUnitsRemaining,
              src: &iWU);
      if ( __PAIR64__(v15, HIDWORD(v15)) != v14 )
        _Error(a1: "CShuffledWorkUnitWalker: assumption on CUtlLinkedList indexing failed.\n");
      LODWORD(v14) = (__PAIR64__(v14, HIDWORD(v14)) + 1) >> 32;
      ++HIDWORD(v14);
      iWU = __PAIR64__(v14, HIDWORD(v14));
    }
    while ( __PAIR64__(v14, HIDWORD(v14)) < nWorkUnits );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096D90
// Name: public: virtual void CDistributor_SDKMaster::DistributeWork_Master(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::DistributeWork_Master(CDistributor_SDKMaster *this, CDSInfo *pInfo)
{
  int v3; // edx
  int v4; // ecx
  const char *ParamString; // eax
  CCriticalSection *p_m_CS; // edi
  __int64 m_ElementCount_low; // kr00_8
  __int64 v8; // kr08_8
  int v9; // [esp+0h] [ebp-1Ch]
  int v10; // [esp+0h] [ebp-1Ch]
  double v11; // [esp+Ch] [ebp-10h]
  CCriticalSectionLock v12; // [esp+14h] [ebp-8h] BYREF

  this->m_pInfo = pInfo;
  *(_WORD *)&this->m_bForceShuffle = 0;
  this->m_flLastShuffleRequestServiceTime = _Plat_FloatTime(a1: v9);
  this->m_bUsingMasterLocalThreads = pInfo->m_WorkerInfo.m_pProcessFn != nullptr;
  if ( VMPI_IsParamUsed(a1: v4, a2: v3, eParam: mpi_NoMasterWorkerThreads) )
  {
    ParamString = VMPI_GetParamString(eParam: mpi_NoMasterWorkerThreads);
    _Msg(a1: "%s found. No worker threads will be created.\n", ParamString);
    this->m_bUsingMasterLocalThreads = 0;
  }
  CShuffledWorkUnitWalker::Init(
    this: &this->m_WorkUnitWalker,
    nWorkUnits: pInfo->m_nWorkUnits,
    pRequester: &this->IShuffleRequester);
  CDistributor_SDKMaster::Shuffle(this);
  if ( this->m_bUsingMasterLocalThreads != 0 )
    RunThreads_Start(
      fn: (void (__cdecl *)(int, void *))CDistributor_SDKMaster::Master_WorkerThread_Static,
      pUserData: this,
      ePriority: k_eRunThreadsPriority_Idle);
  _Plat_MSTime();
  p_m_CS = &this->m_WorkUnitWalker.m_CS;
  CCriticalSectionLock::CCriticalSectionLock(this: &v12, pCS: &this->m_WorkUnitWalker.m_CS);
  CCriticalSectionLock::Lock(this: &v12);
  m_ElementCount_low = SLODWORD(this->m_WorkUnitWalker.m_WorkUnitsRemaining.m_ElementCount);
  CCriticalSectionLock::~CCriticalSectionLock(this: &v12);
  if ( m_ElementCount_low != 0 )
  {
    while ( 1 )
    {
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xC8);
      CheckLocalMasterCompletedWorkUnits();
      VMPITracker_HandleDebugKeypresses(a1: (int)this);
      if ( g_pDistributeWorkCallbacks != nullptr
        && g_pDistributeWorkCallbacks->Update(this: g_pDistributeWorkCallbacks) != 0 )
      {
        goto LABEL_16;
      }
      if ( this->m_bForceShuffle )
        goto LABEL_14;
      if ( this->m_bShuffleRequested )
      {
        v11 = _Plat_FloatTime(a1: v10);
        if ( v11 - this->m_flLastShuffleRequestServiceTime > 2.0 )
          break;
      }
LABEL_15:
      CCriticalSectionLock::CCriticalSectionLock(this: &v12, pCS: p_m_CS);
      CCriticalSectionLock::Lock(this: &v12);
      v8 = SLODWORD(this->m_WorkUnitWalker.m_WorkUnitsRemaining.m_ElementCount);
      CCriticalSectionLock::~CCriticalSectionLock(this: &v12);
      if ( v8 == 0 )
        goto LABEL_16;
      p_m_CS = &this->m_WorkUnitWalker.m_CS;
    }
    this->m_flLastShuffleRequestServiceTime = v11;
    this->m_bShuffleRequested = false;
LABEL_14:
    CDistributor_SDKMaster::Shuffle(this);
    _Plat_MSTime();
    this->m_bForceShuffle = false;
    goto LABEL_15;
  }
LABEL_16:
  RunThreads_End();
}

//------------------------------------------------------------------------------
// Address: 0x10096F40
// Name: public: virtual bool CDistributor_SDKMaster::HandleWorkUnitResults(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_SDKMaster::HandleWorkUnitResults(CDistributor_SDKMaster *this, unsigned __int64 iWorkUnit)
{
  return CDistributor_SDKMaster::Thread_HandleWorkUnitResults(this, iWorkUnit);
}

//------------------------------------------------------------------------------
// Address: 0x10096F60
// Name: public: virtual void CDistributor_SDKWorker::Init(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKWorker::Init(CDistributor_SDKWorker *this, CDSInfo *pInfo)
{
  this->m_iMyWorkUnitWalkerID = -1;
  this->m_pInfo = pInfo;
  CShuffledWorkUnitWalker::Init(
    this: &this->m_WorkUnitWalker,
    nWorkUnits: pInfo->m_nWorkUnits,
    pRequester: &this->IShuffleRequester);
}

//------------------------------------------------------------------------------
// Address: 0x10096FA0
// Name: public: virtual void CDistributor_SDKWorker::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKWorker::Release(CDistributor_SDKWorker *this)
{
  if ( this != nullptr )
  {
    CShuffledWorkUnitWalker::~CShuffledWorkUnitWalker(this: &this->m_WorkUnitWalker);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096FC0
// Name: class IWorkUnitDistributorMaster __near * CreateWUDistributor_SDKMaster(void)
// Source: json
//------------------------------------------------------------------------------
CDistributor_SDKMaster *__cdecl CreateWUDistributor_SDKMaster()
{
  CDistributor_SDKMaster *v0; // eax

  v0 = (CDistributor_SDKMaster *)MemAlloc_Alloc(nSize: 0x240u);
  if ( v0 != nullptr )
    return CDistributor_SDKMaster::CDistributor_SDKMaster(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10096FE0
// Name: public: virtual void CDistributor_SDKMaster::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::Release(CDistributor_SDKMaster *this)
{
  if ( this != nullptr )
  {
    CShuffledWorkUnitWalker::~CShuffledWorkUnitWalker(this: &this->m_WorkUnitWalker);
    MessageBuffer::~MessageBuffer(this: &this->m_WUSCompletedMessageBuffer);
    CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_WUsCompletedCS.m_Data.m_Pending);
    CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_WUsCompletedCS.m_Data);
    CCriticalSection::~CCriticalSection(this: &this->m_WUsCompletedCS);
    CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_WorkersReadyCS.m_Data);
    CCriticalSection::~CCriticalSection(this: &this->m_WorkersReadyCS);
    free(pMem: this);
  }
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x100340B0
// Name: public: CShuffledWorkUnitWalker::CShuffledWorkUnitWalker(void)
// Source: json
//------------------------------------------------------------------------------
CShuffledWorkUnitWalker *__thiscall CShuffledWorkUnitWalker::CShuffledWorkUnitWalker(CShuffledWorkUnitWalker *this)
{
  this->m_CompletedWUBits.m_Memory.m_pMemory = nullptr;
  this->m_CompletedWUBits.m_Memory.m_nAllocationCount = 0;
  this->m_CompletedWUBits.m_Memory.m_nGrowSize = 0;
  this->m_CompletedWUBits.m_Size = 0;
  this->m_CompletedWUBits.m_pElements = nullptr;
  this->m_WorkUnitsRemaining.m_Memory.m_pMemory = nullptr;
  this->m_WorkUnitsRemaining.m_Memory.m_nAllocationCount = 0;
  this->m_WorkUnitsRemaining.m_Memory.m_nGrowSize = 0;
  this->m_WorkUnitsRemaining.m_LastAlloc.index = -1;
  this->m_WorkUnitsRemaining.m_Head = -1;
  this->m_WorkUnitsRemaining.m_Tail = -1;
  this->m_WorkUnitsRemaining.m_FirstFree = -1;
  this->m_WorkUnitsRemaining.m_pElements = this->m_WorkUnitsRemaining.m_Memory.m_pMemory;
  this->m_WorkUnitsRemaining.m_ElementCount = 0;
  this->m_WorkUnitsRemaining.m_NumAlloced = 0;
  this->m_WorkUnitsMap.m_Memory.m_pMemory = nullptr;
  this->m_WorkUnitsMap.m_Memory.m_nAllocationCount = 0;
  this->m_WorkUnitsMap.m_Memory.m_nGrowSize = 0;
  this->m_WorkUnitsMap.m_Size = 0;
  this->m_WorkUnitsMap.m_pElements = nullptr;
  this->m_LocalCompletedWUBits.m_Memory.m_pMemory = nullptr;
  this->m_LocalCompletedWUBits.m_Memory.m_nAllocationCount = 0;
  this->m_LocalCompletedWUBits.m_Memory.m_nGrowSize = 0;
  this->m_LocalCompletedWUBits.m_Size = 0;
  this->m_LocalCompletedWUBits.m_pElements = nullptr;
  this->m_Walker.m_WorkerInfos.m_Memory.m_pMemory = nullptr;
  this->m_Walker.m_WorkerInfos.m_Memory.m_nAllocationCount = 0;
  this->m_Walker.m_WorkerInfos.m_Memory.m_nGrowSize = 0;
  this->m_Walker.m_WorkerInfos.m_Size = 0;
  this->m_Walker.m_WorkerInfos.m_pElements = nullptr;
  this->m_Walker.m_nWorkUnits = 0;
  CCriticalSection::CCriticalSection(this: &this->m_CS);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10034160
// Name: public: CShuffledWorkUnitWalker::~CShuffledWorkUnitWalker(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShuffledWorkUnitWalker::~CShuffledWorkUnitWalker(CShuffledWorkUnitWalker *this)
{
  CCriticalSection::~CCriticalSection(this: &this->m_CS);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_Walker.m_WorkerInfos);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_LocalCompletedWUBits);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_WorkUnitsMap);
  CUtlLinkedList<unsigned __int64,unsigned __int64,0,unsigned __int64,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>>::RemoveAll(this: &this->m_WorkUnitsRemaining);
  if ( this->m_WorkUnitsRemaining.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_WorkUnitsRemaining.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WorkUnitsRemaining.m_Memory.m_pMemory);
      this->m_WorkUnitsRemaining.m_Memory.m_pMemory = nullptr;
    }
    this->m_WorkUnitsRemaining.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>((CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x100341D0
// Name: public: void CDSInfo::ReadWUIndex(unsigned __int64 __near *,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDSInfo::ReadWUIndex(CDSInfo *this, unsigned __int8 *pWU, MessageBuffer *pBuf)
{
  if ( HIDWORD(this->m_nWorkUnits) != 0 )
  {
    MessageBuffer::read(this: pBuf, p: pWU, bytes: 8u);
  }
  else if ( LODWORD(this->m_nWorkUnits) > 0xFFFF )
  {
    MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&pBuf, bytes: 4u);
    *(_QWORD *)pWU = (unsigned int)pBuf;
  }
  else
  {
    MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&pBuf, bytes: 2u);
    *(_QWORD *)pWU = (unsigned __int16)pBuf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034250
// Name: public: virtual void CDistributor_SDKWorker::RequestShuffle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKWorker::RequestShuffle(CDistributor_SDKWorker *this)
{
  int Name; // eax
  MessageBuffer mb; // [esp+0h] [ebp-10h] BYREF

  MessageBuffer::MessageBuffer(this: &mb);
  PrepareDistributeWorkHeader(pBuf: &mb, cSubpacketID: 0x33u);
  Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  VMPI_SendData(pData: mb.data, nBytes: Name, iDest: 0, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x10034330
// Name: public: virtual void CDistributor_SDKWorker::NoteLocalWorkUnitCompleted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKWorker::NoteLocalWorkUnitCompleted(CDistributor_SDKWorker *this, unsigned __int64 iWU)
{
  unsigned __int8 *v3; // eax
  CCriticalSectionLock v4; // [esp+4h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &v4, pCS: &this->m_WorkUnitWalker.m_CS);
  CCriticalSectionLock::Lock(this: &v4);
  v3 = &this->m_WorkUnitWalker.m_LocalCompletedWUBits.m_Memory.m_pMemory[iWU >> 3];
  *v3 |= 1 << (iWU & 7);
  CCriticalSectionLock::~CCriticalSectionLock(this: &v4);
}

//------------------------------------------------------------------------------
// Address: 0x10034420
// Name: public: bool CWorkUnitWalker::GetNextWorkUnit(int,unsigned __int64 __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWorkUnitWalker::GetNextWorkUnit(
        CWorkUnitWalker *this,
        int iWorker,
        unsigned __int64 *pWUIndex,
        bool *bWorkerFinishedHisColumn)
{
  CWorkUnitWalker::CWorkerInfo *v5; // edi
  unsigned int m_iWorkUnitOffset_high; // eax
  unsigned int m_iWorkUnitOffset; // ecx
  unsigned __int64 v8; // rax
  bool v9; // cf

  if ( iWorker < 0 )
    return 0;
  if ( iWorker >= this->m_WorkerInfos.m_Size )
    return 0;
  v5 = &this->m_WorkerInfos.m_Memory.m_pMemory[iWorker];
  m_iWorkUnitOffset_high = HIDWORD(v5->m_iWorkUnitOffset);
  m_iWorkUnitOffset = v5->m_iWorkUnitOffset;
  if ( __PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) >= this->m_nWorkUnits )
    return 0;
  if ( __PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) < this->m_MatrixWidth )
  {
    *bWorkerFinishedHisColumn = false;
  }
  else
  {
    v8 = (__PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) / this->m_MatrixWidth + 1) * this->m_MatrixWidth
       - __PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) % this->m_MatrixWidth
       - 1;
    m_iWorkUnitOffset = v8;
    m_iWorkUnitOffset_high = HIDWORD(v8);
    *bWorkerFinishedHisColumn = true;
  }
  *pWUIndex = (__PAIR64__(m_iWorkUnitOffset_high, m_iWorkUnitOffset) + v5->m_iStartWorkUnit) % this->m_nWorkUnits;
  v9 = __CFADD__(LODWORD(v5->m_iWorkUnitOffset)++, 1);
  HIDWORD(v5->m_iWorkUnitOffset) += v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100344F0
// Name: public: bool CShuffledWorkUnitWalker::Thread_GetNextWorkUnit(int,unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShuffledWorkUnitWalker::Thread_GetNextWorkUnit(
        CShuffledWorkUnitWalker *this,
        int iWorker,
        unsigned __int64 *pWUIndex)
{
  unsigned __int64 *m_pMemory; // eax
  int v5; // ecx
  int v6; // edx
  unsigned __int8 v7; // al
  int v8; // ecx
  unsigned __int64 v9; // rt0
  unsigned __int64 iUnmappedWorkUnit; // [esp+Ch] [ebp-14h] BYREF
  CCriticalSectionLock csLock; // [esp+14h] [ebp-Ch] BYREF
  bool bWorkerFinishedHisColumn; // [esp+1Fh] [ebp-1h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  if ( CWorkUnitWalker::GetNextWorkUnit(
         this: &this->m_Walker,
         iWorker,
         pWUIndex: &iUnmappedWorkUnit,
         &bWorkerFinishedHisColumn) != 0 )
  {
    while ( 1 )
    {
      if ( bWorkerFinishedHisColumn
        && this->m_iLastShuffleRequest != this->m_iCurShuffle
        && _Plat_FloatTime() - this->m_flLastShuffleTime > 2.0 )
      {
        this->m_pShuffleRequester->RequestShuffle(this: this->m_pShuffleRequester);
        this->m_iLastShuffleRequest = this->m_iCurShuffle;
      }
      m_pMemory = this->m_WorkUnitsMap.m_Memory.m_pMemory;
      v5 = iUnmappedWorkUnit;
      v6 = m_pMemory[iUnmappedWorkUnit];
      *(_DWORD *)pWUIndex = v6;
      *((_DWORD *)pWUIndex + 1) = HIDWORD(m_pMemory[v5]);
      v7 = 1 << (v6 & 7);
      LODWORD(v9) = v6;
      HIDWORD(v9) = *((_DWORD *)pWUIndex + 1);
      v8 = v9 >> 3;
      if ( (v7 & this->m_CompletedWUBits.m_Memory.m_pMemory[v8]) == 0
        && (v7 & this->m_LocalCompletedWUBits.m_Memory.m_pMemory[v8]) == 0 )
      {
        break;
      }
      if ( CWorkUnitWalker::GetNextWorkUnit(
             this: &this->m_Walker,
             iWorker,
             pWUIndex: &iUnmappedWorkUnit,
             &bWorkerFinishedHisColumn) == 0 )
        goto LABEL_9;
    }
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 1;
  }
  else
  {
LABEL_9:
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034600
// Name: public: virtual bool CDistributor_SDKWorker::GetNextWorkUnit(unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_SDKWorker::GetNextWorkUnit(CDistributor_SDKWorker *this, unsigned __int64 *pWUIndex)
{
  int m_iMyWorkUnitWalkerID; // eax

  m_iMyWorkUnitWalkerID = this->m_iMyWorkUnitWalkerID;
  if ( m_iMyWorkUnitWalkerID == -1 )
    return 0;
  else
    return CShuffledWorkUnitWalker::Thread_GetNextWorkUnit(
             this: &this->m_WorkUnitWalker,
             iWorker: m_iMyWorkUnitWalkerID,
             pWUIndex);
}

//------------------------------------------------------------------------------
// Address: 0x100347D0
// Name: public: unsigned long CShuffledWorkUnitWalker::GetShuffleCRC(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CShuffledWorkUnitWalker::GetShuffleCRC(CShuffledWorkUnitWalker *this)
{
  int m_Head; // esi
  UtlLinkedListElem_t<unsigned __int64,unsigned __int64> *m_pMemory; // eax
  int v4; // esi
  int i; // esi
  unsigned int v6; // esi
  CCriticalSectionLock csLock; // [esp+4h] [ebp-14h] BYREF
  unsigned __int64 iWorkUnit; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int ret; // [esp+14h] [ebp-4h] BYREF

  if ( (`CShuffledWorkUnitWalker::GetShuffleCRC'::`2'::`local static guard' & 1) == 0 )
  {
    `CShuffledWorkUnitWalker::GetShuffleCRC'::`2'::`local static guard' |= 1u;
    `CShuffledWorkUnitWalker::GetShuffleCRC'::`2'::bCalcShuffleCRC = VMPI_IsParamUsed(eParam: mpi_CalcShuffleCRC);
  }
  if ( !`CShuffledWorkUnitWalker::GetShuffleCRC'::`2'::bCalcShuffleCRC )
    return 0;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  CRC32_Init(pulCRC: &ret);
  m_Head = this->m_WorkUnitsRemaining.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_WorkUnitsRemaining.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      iWorkUnit = m_pMemory[v4].m_Element;
      CRC32_ProcessBuffer(pulCRC: &ret, pBuffer: &iWorkUnit, nBuffer: 8);
      m_pMemory = this->m_WorkUnitsRemaining.m_Memory.m_pMemory;
      m_Head = m_pMemory[v4].m_Next;
    }
    while ( m_Head != -1 );
  }
  for ( i = 0; i < this->m_WorkUnitsMap.m_Size; ++i )
  {
    iWorkUnit = this->m_WorkUnitsMap.m_Memory.m_pMemory[i];
    CRC32_ProcessBuffer(pulCRC: &ret, pBuffer: &iWorkUnit, nBuffer: 8);
  }
  CRC32_Final(pulCRC: &ret);
  v6 = ret;
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100349F0
// Name: public: void CWorkUnitWalker::Init(unsigned __int64,unsigned __int64,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkUnitWalker::Init(
        CWorkUnitWalker *this,
        unsigned __int64 matrixWidth,
        unsigned __int64 matrixHeight,
        unsigned __int64 nWorkUnits)
{
  int v5; // esi
  __int64 v6; // rax
  CWorkUnitWalker::CWorkerInfo *m_pMemory; // eax
  int v8; // [esp+28h] [ebp+1Ch]

  this->m_nWorkUnits = nWorkUnits;
  this->m_MatrixWidth = matrixWidth;
  v5 = 0;
  this->m_MatrixHeight = matrixHeight;
  this->m_WorkerInfos.m_Size = 0;
  if ( SLODWORD(this->m_MatrixHeight) > 0 )
    CUtlVector<CWorkUnitWalker::CWorkerInfo,CUtlMemory<CWorkUnitWalker::CWorkerInfo,int>>::InsertMultipleBefore(
      this: &this->m_WorkerInfos,
      elem: 0,
      num: this->m_MatrixHeight);
  v8 = 0;
  if ( HIDWORD(this->m_MatrixHeight) != 0 || LODWORD(this->m_MatrixHeight) != 0 )
  {
    v6 = 0;
    do
    {
      this->m_WorkerInfos.m_Memory.m_pMemory[v5].m_iStartWorkUnit = v6 * matrixWidth;
      m_pMemory = this->m_WorkerInfos.m_Memory.m_pMemory;
      LODWORD(m_pMemory[v5].m_iWorkUnitOffset) = 0;
      HIDWORD(m_pMemory[v5].m_iWorkUnitOffset) = 0;
      v6 = ++v8;
      ++v5;
    }
    while ( v8 < this->m_MatrixHeight );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034AA0
// Name: public: void CShuffledWorkUnitWalker::Shuffle(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShuffledWorkUnitWalker::Shuffle(CShuffledWorkUnitWalker *this, int nWorkers)
{
  CShuffledWorkUnitWalker *v2; // edi
  int m_ElementCount; // eax
  int m_Head; // esi
  UtlLinkedListElem_t<unsigned __int64,unsigned __int64> *m_pMemory; // edi
  int v6; // esi
  int v7; // ecx
  unsigned __int64 *v8; // eax
  unsigned int v9; // kr00_4
  int m_Element; // edx
  unsigned __int64 m_ElementCount_low; // [esp-14h] [ebp-48h]
  CCriticalSectionLock csLock; // [esp+10h] [ebp-24h] BYREF
  unsigned __int64 matrixHeight; // [esp+18h] [ebp-1Ch]
  unsigned __int64 iWorkUnit; // [esp+20h] [ebp-14h]
  unsigned __int64 matrixWidth; // [esp+28h] [ebp-Ch]
  CShuffledWorkUnitWalker *v16; // [esp+30h] [ebp-4h]

  v2 = this;
  v16 = this;
  if ( nWorkers != 0 )
  {
    ++this->m_iCurShuffle;
    this->m_flLastShuffleTime = _Plat_FloatTime();
    CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &v2->m_CS);
    CCriticalSectionLock::Lock(this: &csLock);
    v2->m_WorkUnitsMap.m_Size = 0;
    m_ElementCount = v2->m_WorkUnitsRemaining.m_ElementCount;
    if ( v2->m_WorkUnitsMap.m_Size < m_ElementCount )
      CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(
        this: &v2->m_WorkUnitsMap,
        elem: v2->m_WorkUnitsMap.m_Size,
        num: m_ElementCount - v2->m_WorkUnitsMap.m_Size);
    m_ElementCount_low = SLODWORD(v2->m_WorkUnitsRemaining.m_ElementCount);
    matrixHeight = nWorkers;
    matrixWidth = m_ElementCount_low / nWorkers;
    if ( m_ElementCount_low % nWorkers != 0 )
      ++matrixWidth;
    m_Head = v2->m_WorkUnitsRemaining.m_Head;
    iWorkUnit = 0;
    if ( m_Head != -1 )
    {
      m_pMemory = v2->m_WorkUnitsRemaining.m_Memory.m_pMemory;
      do
      {
        v6 = m_Head;
        v7 = iWorkUnit / matrixHeight + matrixWidth * (iWorkUnit % matrixHeight);
        v8 = v16->m_WorkUnitsMap.m_Memory.m_pMemory;
        v9 = iWorkUnit;
        LODWORD(iWorkUnit) = iWorkUnit + 1;
        m_Element = m_pMemory[v6].m_Element;
        iWorkUnit = __PAIR64__(HIDWORD(iWorkUnit), v9) + 1;
        LODWORD(v8[v7]) = m_Element;
        HIDWORD(v8[v7]) = HIDWORD(m_pMemory[v6].m_Element);
        m_pMemory = v16->m_WorkUnitsRemaining.m_Memory.m_pMemory;
        m_Head = m_pMemory[v6].m_Next;
      }
      while ( m_Head != -1 );
      v2 = v16;
    }
    CWorkUnitWalker::Init(
      this: &v2->m_Walker,
      matrixWidth,
      matrixHeight,
      nWorkUnits: SLODWORD(v2->m_WorkUnitsRemaining.m_ElementCount));
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034BD0
// Name: public: void CShuffledWorkUnitWalker::Thread_NoteWorkUnitCompleted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShuffledWorkUnitWalker::Thread_NoteWorkUnitCompleted(
        CShuffledWorkUnitWalker *this,
        unsigned __int64 iWU)
{
  unsigned __int8 *m_pMemory; // esi
  UtlLinkedListElem_t<unsigned __int64,unsigned __int64> *v4; // eax
  int v5; // ecx
  int v6; // eax
  CCriticalSectionLock csLock; // [esp+Ch] [ebp-10h] BYREF
  int v8; // [esp+14h] [ebp-8h]
  unsigned __int8 v9; // [esp+1Bh] [ebp-1h]

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  m_pMemory = this->m_CompletedWUBits.m_Memory.m_pMemory;
  v9 = 1 << (iWU & 7);
  v8 = iWU >> 3;
  if ( (v9 & m_pMemory[v8]) == 0 )
  {
    CUtlLinkedList<unsigned __int64,unsigned __int64,0,unsigned __int64,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>>::Unlink(
      this: &this->m_WorkUnitsRemaining,
      elem: iWU);
    v4 = this->m_WorkUnitsRemaining.m_Memory.m_pMemory;
    v5 = 3 * iWU;
    *((_DWORD *)&v4->m_Next + 2 * v5) = this->m_WorkUnitsRemaining.m_FirstFree;
    *((_DWORD *)&v4->m_Next + 2 * v5 + 1) = HIDWORD(this->m_WorkUnitsRemaining.m_FirstFree);
    LOBYTE(v5) = v9;
    HIDWORD(this->m_WorkUnitsRemaining.m_FirstFree) = HIDWORD(iWU);
    v6 = v8;
    LODWORD(this->m_WorkUnitsRemaining.m_FirstFree) = iWU;
    this->m_CompletedWUBits.m_Memory.m_pMemory[v6] |= v5;
  }
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
}

//------------------------------------------------------------------------------
// Address: 0x10034C60
// Name: public: virtual bool CDistributor_SDKWorker::HandlePacket(class MessageBuffer __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CDistributor_SDKWorker::HandlePacket(
        CDistributor_SDKWorker *this,
        MessageBuffer *pBuf,
        int iSource,
        unsigned __int16 bIgnoreContents)
{
  MessageBuffer *v4; // esi
  char v5; // al
  int v7; // edx
  unsigned int ShuffleCRC; // eax
  unsigned int v10; // ebx
  unsigned __int64 iWU; // [esp+8h] [ebp-18h] BYREF
  unsigned __int64 nCompleted; // [esp+10h] [ebp-10h] BYREF
  __int64 v13; // [esp+18h] [ebp-8h] OVERLAPPED BYREF

  v4 = pBuf;
  v5 = pBuf->data[1];
  if ( v5 == 50 )
  {
    if ( (_BYTE)bIgnoreContents == 0 )
    {
      MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&pBuf, bytes: 2u);
      MessageBuffer::read(this: v4, p: (unsigned __int8 *)&v13 + 4, bytes: 4u);
      MessageBuffer::read(this: v4, p: (unsigned __int8 *)&bIgnoreContents, bytes: 2u);
      v7 = (unsigned __int16)pBuf;
      this->m_iMyWorkUnitWalkerID = bIgnoreContents;
      CShuffledWorkUnitWalker::Shuffle(this: &this->m_WorkUnitWalker, nWorkers: v7);
      ShuffleCRC = CShuffledWorkUnitWalker::GetShuffleCRC(this: &this->m_WorkUnitWalker);
      if ( ShuffleCRC != HIDWORD(v13) && ++`CDistributor_SDKWorker::HandlePacket'::`10'::nWarnings <= 2 )
        _Warning(a1: "\nShuffle CRC mismatch\n");
    }
    return 1;
  }
  if ( v5 != 52 )
    return 0;
  if ( (_BYTE)bIgnoreContents != 0 )
    return 1;
  CDSInfo::ReadWUIndex(this: this->m_pInfo, pWU: (unsigned __int8 *)&nCompleted, pBuf);
  v13 = 0;
  if ( nCompleted != 0 )
  {
    v10 = HIDWORD(v13);
    do
    {
      CDSInfo::ReadWUIndex(this: this->m_pInfo, pWU: (unsigned __int8 *)&iWU, pBuf: v4);
      CShuffledWorkUnitWalker::Thread_NoteWorkUnitCompleted(this: &this->m_WorkUnitWalker, iWU);
      v10 = (__PAIR64__(v10, v13) + 1) >> 32;
      LODWORD(v13) = v13 + 1;
    }
    while ( __PAIR64__(v10, v13) < nCompleted );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10034D70
// Name: public: CDistributor_SDKMaster::CDistributor_SDKMaster(void)
// Source: json
//------------------------------------------------------------------------------
CDistributor_SDKMaster *__thiscall CDistributor_SDKMaster::CDistributor_SDKMaster(CDistributor_SDKMaster *this)
{
  this->IShuffleRequester::__vftable = (IShuffleRequester_vtbl *)&IShuffleRequester::`vftable';
  this->IWorkUnitDistributorMaster::__vftable = (CDistributor_SDKMaster_vtbl *)&CDistributor_SDKMaster::`vftable'{for `IWorkUnitDistributorMaster'};
  this->IShuffleRequester::__vftable = (IShuffleRequester_vtbl *)&CDistributor_SDKMaster::`vftable'{for `IShuffleRequester'};
  CCriticalSection::CCriticalSection(this: &this->m_WorkersReadyCS);
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Memory.m_pMemory = nullptr;
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Memory.m_nAllocationCount = 0;
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Memory.m_nGrowSize = 0;
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Size = 0;
  this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_pElements = nullptr;
  CCriticalSection::CCriticalSection(this: &this->m_WUsCompletedCS);
  this->m_WUsCompletedCS.m_Data.m_Completed.m_Memory.m_pMemory = nullptr;
  this->m_WUsCompletedCS.m_Data.m_Completed.m_Memory.m_nAllocationCount = 0;
  this->m_WUsCompletedCS.m_Data.m_Completed.m_Memory.m_nGrowSize = 0;
  this->m_WUsCompletedCS.m_Data.m_Completed.m_Size = 0;
  this->m_WUsCompletedCS.m_Data.m_Completed.m_pElements = nullptr;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_Memory.m_pMemory = nullptr;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_Memory.m_nAllocationCount = 0;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_Memory.m_nGrowSize = 0;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_Size = 0;
  this->m_WUsCompletedCS.m_Data.m_Pending.m_pElements = nullptr;
  MessageBuffer::MessageBuffer(this: &this->m_WUSCompletedMessageBuffer);
  CShuffledWorkUnitWalker::CShuffledWorkUnitWalker(this: &this->m_WorkUnitWalker);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10034E10
// Name: public: void CDSInfo::WriteWUIndex(unsigned __int64,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDSInfo::WriteWUIndex(CDSInfo *this, unsigned __int64 iWU, MessageBuffer *pBuf)
{
  unsigned int val; // [esp+0h] [ebp-4h] BYREF

  val = (unsigned int)this;
  if ( HIDWORD(this->m_nWorkUnits) != 0 )
  {
    MessageBuffer::write(this: pBuf, p: (unsigned __int8 *)&iWU, bytes: 8u);
  }
  else if ( LODWORD(this->m_nWorkUnits) > 0xFFFF )
  {
    val = iWU;
    MessageBuffer::write(this: pBuf, p: (unsigned __int8 *)&val, bytes: 4u);
  }
  else
  {
    val = (unsigned __int16)iWU;
    MessageBuffer::write(this: pBuf, p: (unsigned __int8 *)&val, bytes: 2u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034E90
// Name: public: virtual void CDistributor_SDKMaster::RequestShuffle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::RequestShuffle(CDistributor_SDKMaster *this)
{
  BYTE1(this->m_bUsingMasterLocalThreads) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10034EA0
// Name: public: virtual bool CDistributor_SDKMaster::HandlePacket(class MessageBuffer __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_SDKMaster::HandlePacket(
        CDistributor_SDKMaster *this,
        MessageBuffer *pBuf,
        int iSource,
        bool bIgnoreContents)
{
  if ( pBuf->data[1] == 51 )
  {
    if ( bIgnoreContents )
      return 1;
    this->m_bShuffleRequested = true;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10034ED0
// Name: public: void CDistributor_SDKMaster::Master_WorkerThread(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::Master_WorkerThread(CDistributor_SDKMaster *this, int iThread)
{
  CShuffledWorkUnitWalker *p_m_WorkUnitWalker; // ebx
  CCriticalSection *p_m_CS; // esi
  int v4; // edi
  unsigned __int64 v5; // kr08_8
  unsigned __int8 *v6; // eax
  int v7; // edi
  CCriticalSectionLock v8; // [esp+Ch] [ebp-24h] BYREF
  unsigned __int64 iWU; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int m_ElementCount; // [esp+1Ch] [ebp-14h]
  CCriticalSectionLock v11; // [esp+24h] [ebp-Ch] BYREF
  CDistributor_SDKMaster *v12; // [esp+2Ch] [ebp-4h]

  p_m_WorkUnitWalker = &this->m_WorkUnitWalker;
  v12 = this;
  p_m_CS = &this->m_WorkUnitWalker.m_CS;
  CCriticalSectionLock::CCriticalSectionLock(this: &v11, pCS: &this->m_WorkUnitWalker.m_CS);
  CCriticalSectionLock::Lock(this: &v11);
  v4 = SLODWORD(p_m_WorkUnitWalker->m_WorkUnitsRemaining.m_ElementCount) >> 31;
  m_ElementCount = p_m_WorkUnitWalker->m_WorkUnitsRemaining.m_ElementCount;
  CCriticalSectionLock::~CCriticalSectionLock(this: &v11);
  if ( __PAIR64__(v4, m_ElementCount) != 0 )
  {
    while ( !g_bVMPIEarlyExit )
    {
      if ( CShuffledWorkUnitWalker::Thread_GetNextWorkUnit(this: p_m_WorkUnitWalker, iWorker: 0, pWUIndex: &iWU) != 0 )
      {
        CCriticalSectionLock::CCriticalSectionLock(this: &v8, pCS: p_m_CS);
        CCriticalSectionLock::Lock(this: &v8);
        v5 = iWU;
        v6 = &p_m_WorkUnitWalker->m_LocalCompletedWUBits.m_Memory.m_pMemory[iWU >> 3];
        *v6 |= 1 << (iWU & 7);
        CCriticalSectionLock::~CCriticalSectionLock(this: &v8);
        ((void (__cdecl *)(int, _DWORD, _DWORD, _DWORD))v12->m_pInfo->m_WorkerInfo.m_pProcessFn)(
          a1: iThread,
          a2: v5,
          a3: HIDWORD(v5),
          a4: 0);
        NotifyLocalMasterCompletedWorkUnit(iWorkUnit: v5);
      }
      else
      {
        VMPI_Sleep(ms: 0xAu);
      }
      p_m_CS = &p_m_WorkUnitWalker->m_CS;
      CCriticalSectionLock::CCriticalSectionLock(this: &v11, pCS: &p_m_WorkUnitWalker->m_CS);
      CCriticalSectionLock::Lock(this: &v11);
      v7 = SLODWORD(p_m_WorkUnitWalker->m_WorkUnitsRemaining.m_ElementCount) >> 31;
      m_ElementCount = p_m_WorkUnitWalker->m_WorkUnitsRemaining.m_ElementCount;
      CCriticalSectionLock::~CCriticalSectionLock(this: &v11);
      if ( v7 == 0 && m_ElementCount == 0 )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034FF0
// Name: public: int CDistributor_SDKMaster::BuildWUsCompletedMessage(class CUtlVector<unsigned __int64,class CUtlMemory<unsigned __int64,int>> __near &,class MessageBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDistributor_SDKMaster::BuildWUsCompletedMessage(
        CDistributor_SDKMaster *this,
        CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *wusCompleted,
        MessageBuffer *mb)
{
  MessageBuffer *v3; // esi
  CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *v5; // edi
  int i; // esi
  unsigned __int64 *m_pMemory; // eax
  CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *v8; // ecx
  CDSInfo *m_pInfo; // eax
  _DWORD p[2]; // [esp+Ch] [ebp-8h] BYREF

  v3 = mb;
  PrepareDistributeWorkHeader(pBuf: mb, cSubpacketID: 0x34u);
  v5 = wusCompleted;
  CDSInfo::WriteWUIndex(this: this->m_pInfo, iWU: wusCompleted->m_Size, pBuf: v3);
  for ( i = 0; i < v5->m_Size; ++i )
  {
    m_pMemory = v5->m_Memory.m_pMemory;
    v8 = (CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *)v5->m_Memory.m_pMemory[i];
    p[0] = v8;
    p[1] = HIDWORD(m_pMemory[i]);
    m_pInfo = this->m_pInfo;
    if ( HIDWORD(m_pInfo->m_nWorkUnits) != 0 )
    {
      MessageBuffer::write(this: mb, (unsigned __int8 *)p, bytes: 8u);
    }
    else if ( LODWORD(m_pInfo->m_nWorkUnits) > 0xFFFF )
    {
      wusCompleted = v8;
      MessageBuffer::write(this: mb, p: (unsigned __int8 *)&wusCompleted, bytes: 4u);
    }
    else
    {
      wusCompleted = (CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *)(unsigned __int16)v8;
      MessageBuffer::write(this: mb, p: (unsigned __int8 *)&wusCompleted, bytes: 2u);
    }
  }
  return v5->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100350A0
// Name: public: static void CDistributor_SDKMaster::Master_WorkerThread_Static(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CDistributor_SDKMaster::Master_WorkerThread_Static(int iThread, CDistributor_SDKMaster *pUserData)
{
  CDistributor_SDKMaster::Master_WorkerThread(this: pUserData, iThread);
}

//------------------------------------------------------------------------------
// Address: 0x100350C0
// Name: public: virtual void CDistributor_SDKMaster::DisconnectHandler(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::DisconnectHandler(CDistributor_SDKMaster *this, int workerID)
{
  int m_Size; // ecx
  int v4; // eax
  int *m_pMemory; // edx

  CCriticalSection::Lock(this: &this->m_WorkersReadyCS);
  m_Size = this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Memory.m_pMemory;
    while ( *m_pMemory != workerID )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_8;
    }
    if ( v4 != -1 )
      this->m_bForceShuffle = true;
  }
LABEL_8:
  CCriticalSection::Unlock(this: &this->m_WorkersReadyCS);
}

//------------------------------------------------------------------------------
// Address: 0x100351D0
// Name: public: virtual void CDistributor_SDKMaster::OnWorkerReady(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::OnWorkerReady(CDistributor_SDKMaster *this, int iSource)
{
  CCriticalSectionData<CDistributor_SDKMaster::CWorkersReady> *p_m_WorkersReadyCS; // esi
  int m_Size; // edi
  int v5; // eax
  int *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  int *v8; // ecx
  int v9; // eax
  int *v10; // edi
  int Name; // eax
  CCriticalSectionData<CDistributor_SDKMaster::CWorkersReady> *v12; // [esp+Ch] [ebp-4h]

  p_m_WorkersReadyCS = &this->m_WorkersReadyCS;
  v12 = &this->m_WorkersReadyCS;
  CCriticalSection::Lock(this: &this->m_WorkersReadyCS);
  m_Size = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_pMemory;
  while ( *m_pMemory != iSource )
  {
    ++v5;
    ++m_pMemory;
    if ( v5 >= m_Size )
      goto LABEL_7;
  }
  if ( v5 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<int,int>::Grow(
        this: (CUtlMemory<CTCPPacket *,int> *)&p_m_WorkersReadyCS->m_Data,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Size;
    v8 = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_pMemory;
    v9 = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Size - m_Size - 1;
    p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_pElements = v8;
    if ( v9 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v8[m_Size + 1], src: (unsigned __int8 *)&v8[m_Size], count: 4 * v9);
    v10 = &p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = iSource;
    CCriticalSection::Lock(this: &this->m_WUsCompletedCS);
    MessageBuffer::setLen(this: &this->m_WUSCompletedMessageBuffer, nlen: 0);
    CDistributor_SDKMaster::BuildWUsCompletedMessage(
      this,
      wusCompleted: &this->m_WUsCompletedCS.m_Data.m_Completed,
      mb: &this->m_WUSCompletedMessageBuffer);
    CCriticalSection::Unlock(this: &this->m_WUsCompletedCS);
    Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&this->m_WUSCompletedMessageBuffer);
    VMPI_SendData(pData: this->m_WUSCompletedMessageBuffer.data, nBytes: Name, iDest: iSource, fVMPISendFlags: 0);
    this->m_bForceShuffle = true;
  }
  CCriticalSection::Unlock(this: v12);
}

//------------------------------------------------------------------------------
// Address: 0x100352C0
// Name: public: void CDistributor_SDKMaster::Shuffle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::Shuffle(CDistributor_SDKMaster *this)
{
  int m_Size; // esi
  unsigned __int16 *m_pMemory; // ebx
  int v4; // eax
  CCriticalSectionData<CDistributor_SDKMaster::CWorkersReady> *p_m_WorkersReadyCS; // edi
  bool v6; // cc
  int v7; // edi
  unsigned __int16 *v8; // edi
  CDistributor_SDKMaster *v9; // edi
  MessageBuffer *p_m_WUSCompletedMessageBuffer; // edi
  int m_bUsingMasterLocalThreads; // eax
  int Name; // eax
  int v13; // edi
  CCriticalSectionData<CDistributor_SDKMaster::CWUsCompleted> *p_m_WUsCompletedCS; // ecx
  CDistributor_SDKMaster *v15; // edi
  int j; // edi
  int v17; // eax
  int v18; // [esp-8h] [ebp-50h]
  int v19; // [esp-8h] [ebp-50h]
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > whosWorking; // [esp+Ch] [ebp-3Ch] BYREF
  MessageBuffer mb; // [esp+20h] [ebp-28h] BYREF
  unsigned int shuffleCRC; // [esp+30h] [ebp-18h] BYREF
  int nWorkers; // [esp+34h] [ebp-14h] BYREF
  int iWorker; // [esp+38h] [ebp-10h]
  int id; // [esp+3Ch] [ebp-Ch] BYREF
  int i; // [esp+40h] [ebp-8h]
  CDistributor_SDKMaster *v27; // [esp+44h] [ebp-4h]

  m_Size = 0;
  m_pMemory = nullptr;
  v27 = this;
  memset(&whosWorking, 0, sizeof(whosWorking));
  if ( this->m_bUsingMasterLocalThreads != 0 )
  {
    CUtlMemory<CFaceMacroTextureInfo,int>::Grow(this: (CUtlMemory<CFaceMacroTextureInfo,int> *)&whosWorking, num: 1);
    m_pMemory = whosWorking.m_Memory.m_pMemory;
    m_Size = whosWorking.m_Size + 1;
    v4 = whosWorking.m_Size++;
    whosWorking.m_pElements = whosWorking.m_Memory.m_pMemory;
    if ( v4 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)whosWorking.m_Memory.m_pMemory + 2,
        src: (unsigned __int8 *)whosWorking.m_Memory.m_pMemory,
        count: 2 * v4);
    if ( m_pMemory != nullptr )
      *m_pMemory = 0;
  }
  p_m_WorkersReadyCS = &this->m_WorkersReadyCS;
  CCriticalSection::Lock(this: p_m_WorkersReadyCS);
  v6 = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Size <= 0;
  i = 0;
  if ( !v6 )
  {
    do
    {
      iWorker = p_m_WorkersReadyCS->m_Data.m_WorkersReady.m_Memory.m_pMemory[i];
      if ( VMPI_IsProcConnected(procID: iWorker) )
      {
        v7 = m_Size;
        if ( m_Size + 1 > whosWorking.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CFaceMacroTextureInfo,int>::Grow(
            this: (CUtlMemory<CFaceMacroTextureInfo,int> *)&whosWorking,
            num: m_Size - whosWorking.m_Memory.m_nAllocationCount + 1);
          m_Size = whosWorking.m_Size;
          m_pMemory = whosWorking.m_Memory.m_pMemory;
        }
        whosWorking.m_Size = ++m_Size;
        whosWorking.m_pElements = m_pMemory;
        if ( m_Size - v7 - 1 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[v7 + 1],
            src: (unsigned __int8 *)&m_pMemory[v7],
            count: 2 * (m_Size - v7 - 1));
        v8 = &m_pMemory[v7];
        if ( v8 != nullptr )
          *v8 = iWorker;
      }
      p_m_WorkersReadyCS = &v27->m_WorkersReadyCS;
      ++i;
    }
    while ( i < v27->m_WorkersReadyCS.m_Data.m_WorkersReady.m_Size );
  }
  CCriticalSection::Unlock(this: p_m_WorkersReadyCS);
  v9 = v27;
  CCriticalSection::Lock(this: &v27->m_WUsCompletedCS);
  p_m_WUSCompletedMessageBuffer = &v9->m_WUSCompletedMessageBuffer;
  MessageBuffer::setLen(this: p_m_WUSCompletedMessageBuffer, nlen: 0);
  iWorker = (int)&v27->m_WUsCompletedCS.m_Data.m_Pending;
  if ( CDistributor_SDKMaster::BuildWUsCompletedMessage(
         this: v27,
         wusCompleted: &v27->m_WUsCompletedCS.m_Data.m_Pending,
         mb: p_m_WUSCompletedMessageBuffer) > 0 )
  {
    m_bUsingMasterLocalThreads = v27->m_bUsingMasterLocalThreads;
    i = m_bUsingMasterLocalThreads;
    if ( m_bUsingMasterLocalThreads < m_Size )
    {
      while ( 1 )
      {
        v18 = m_pMemory[m_bUsingMasterLocalThreads];
        Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)p_m_WUSCompletedMessageBuffer);
        VMPI_SendData(pData: p_m_WUSCompletedMessageBuffer->data, nBytes: Name, iDest: v18, fVMPISendFlags: 0);
        if ( ++i >= m_Size )
          break;
        m_bUsingMasterLocalThreads = i;
      }
    }
  }
  v13 = iWorker;
  CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(
    this: &v27->m_WUsCompletedCS.m_Data.m_Completed,
    elem: v27->m_WUsCompletedCS.m_Data.m_Completed.m_Size,
    num: v27->m_WUsCompletedCS.m_Data.m_Pending.m_Size,
    pToInsert: *(const unsigned __int64 **)iWorker);
  p_m_WUsCompletedCS = &v27->m_WUsCompletedCS;
  *(_DWORD *)(v13 + 12) = 0;
  CCriticalSection::Unlock(this: p_m_WUsCompletedCS);
  v15 = v27;
  CShuffledWorkUnitWalker::Shuffle(this: &v27->m_WorkUnitWalker, nWorkers: m_Size);
  MessageBuffer::MessageBuffer(this: &mb);
  PrepareDistributeWorkHeader(pBuf: &mb, cSubpacketID: 0x32u);
  nWorkers = (unsigned __int16)m_Size;
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&nWorkers, bytes: 2u);
  shuffleCRC = CShuffledWorkUnitWalker::GetShuffleCRC(this: &v15->m_WorkUnitWalker);
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&shuffleCRC, bytes: 4u);
  iWorker = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  id = 0;
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&id, bytes: 2u);
  for ( j = v15->m_bUsingMasterLocalThreads; j < m_Size; ++j )
  {
    id = (unsigned __int16)j;
    MessageBuffer::update(this: &mb, loc: iWorker, p: (unsigned __int8 *)&id, bytes: 2u);
    v19 = m_pMemory[j];
    v17 = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
    VMPI_SendData(pData: mb.data, nBytes: v17, iDest: v19, fVMPISendFlags: 0);
  }
  MessageBuffer::~MessageBuffer(this: &mb);
  if ( whosWorking.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10035550
// Name: public: bool CDistributor_SDKMaster::Thread_HandleWorkUnitResults(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_SDKMaster::Thread_HandleWorkUnitResults(
        CDistributor_SDKMaster *this,
        unsigned __int64 iWorkUnit)
{
  unsigned int v3; // ebx
  CCriticalSectionLock v5; // [esp+Ch] [ebp-Ch] BYREF
  bool v6; // [esp+17h] [ebp-1h]

  CCriticalSectionLock::CCriticalSectionLock(this: &v5, pCS: &this->m_WorkUnitWalker.m_CS);
  CCriticalSectionLock::Lock(this: &v5);
  v3 = iWorkUnit;
  v6 = ((unsigned __int8)(1 << (iWorkUnit & 7))
      & this->m_WorkUnitWalker.m_CompletedWUBits.m_Memory.m_pMemory[iWorkUnit >> 3]) != 0;
  CCriticalSectionLock::~CCriticalSectionLock(this: &v5);
  if ( v6 )
    return 0;
  CShuffledWorkUnitWalker::Thread_NoteWorkUnitCompleted(
    this: &this->m_WorkUnitWalker,
    iWU: __PAIR64__(HIDWORD(iWorkUnit), v3));
  CCriticalSection::Lock(this: &this->m_WUsCompletedCS);
  CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
    this: &this->m_WUsCompletedCS.m_Data.m_Pending,
    elem: this->m_WUsCompletedCS.m_Data.m_Pending.m_Size,
    src: &iWorkUnit);
  CCriticalSection::Unlock(this: &this->m_WUsCompletedCS);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10035600
// Name: class IWorkUnitDistributorWorker __near * CreateWUDistributor_SDKWorker(void)
// Source: json
//------------------------------------------------------------------------------
IWorkUnitDistributorWorker *__cdecl CreateWUDistributor_SDKWorker()
{
  char *v0; // eax
  char *v1; // esi

  v0 = (char *)operator new(size: 0x140u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *((_DWORD *)v0 + 1) = &IShuffleRequester::`vftable';
  *(_DWORD *)v0 = &CDistributor_SDKWorker::`vftable'{for `IWorkUnitDistributorWorker'};
  *((_DWORD *)v0 + 1) = &CDistributor_SDKWorker::`vftable'{for `IShuffleRequester'};
  CShuffledWorkUnitWalker::CShuffledWorkUnitWalker(this: (CShuffledWorkUnitWalker *)(v0 + 16));
  return (IWorkUnitDistributorWorker *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10035700
// Name: public: void CShuffledWorkUnitWalker::Init(unsigned __int64,class IShuffleRequester __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShuffledWorkUnitWalker::Init(
        CShuffledWorkUnitWalker *this,
        unsigned __int64 nWorkUnits,
        IShuffleRequester *pRequester)
{
  __int64 v4; // rcx
  int v5; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  signed int v8; // eax
  int v9; // eax
  unsigned __int8 *v10; // ecx
  signed int v11; // eax
  unsigned int v12; // edi
  unsigned __int64 i; // kr08_8
  int v14; // edx
  unsigned __int64 iWU; // [esp+Ch] [ebp-8h] BYREF

  HIDWORD(v4) = 0;
  this->m_iLastShuffleRequest = 0;
  this->m_iCurShuffle = 1;
  this->m_flLastShuffleTime = _Plat_FloatTime();
  v5 = (nWorkUnits + 7) >> 3;
  this->m_pShuffleRequester = pRequester;
  this->m_CompletedWUBits.m_Size = 0;
  if ( v5 != 0 )
  {
    m_nAllocationCount = this->m_CompletedWUBits.m_Memory.m_nAllocationCount;
    if ( v5 > m_nAllocationCount )
      CUtlMemory<char,int>::Grow(this: &this->m_CompletedWUBits.m_Memory, num: v5 - m_nAllocationCount);
    this->m_CompletedWUBits.m_Size += v5;
    m_pMemory = this->m_CompletedWUBits.m_Memory.m_pMemory;
    v8 = this->m_CompletedWUBits.m_Size - v5;
    this->m_CompletedWUBits.m_pElements = this->m_CompletedWUBits.m_Memory.m_pMemory;
    if ( v8 > 0 && v5 > 0 )
      _V_memmove(dest: &m_pMemory[v5], src: m_pMemory, count: v8);
  }
  this->m_LocalCompletedWUBits.m_Size = 0;
  if ( v5 != 0 )
  {
    v9 = this->m_LocalCompletedWUBits.m_Memory.m_nAllocationCount;
    if ( v5 > v9 )
      CUtlMemory<char,int>::Grow(this: &this->m_LocalCompletedWUBits.m_Memory, num: v5 - v9);
    this->m_LocalCompletedWUBits.m_Size += v5;
    v10 = this->m_LocalCompletedWUBits.m_Memory.m_pMemory;
    v11 = this->m_LocalCompletedWUBits.m_Size - v5;
    this->m_LocalCompletedWUBits.m_pElements = v10;
    if ( v11 > 0 && v5 > 0 )
      _V_memmove(dest: &v10[v5], src: v10, count: v11);
  }
  iWU = 0;
  if ( this->m_CompletedWUBits.m_Size != 0 )
  {
    v12 = HIDWORD(iWU);
    LODWORD(v4) = iWU;
    do
    {
      this->m_CompletedWUBits.m_Memory.m_pMemory[v4] = 0;
      this->m_LocalCompletedWUBits.m_Memory.m_pMemory[v4] = 0;
      v12 = (v4 + __PAIR64__(v12, 1)) >> 32;
      LODWORD(v4) = v4 + 1;
    }
    while ( __PAIR64__(v12, v4) < this->m_CompletedWUBits.m_Size );
  }
  iWU = 0;
  if ( nWorkUnits != 0 )
  {
    for ( i = iWU; i < nWorkUnits; iWU = i )
    {
      if ( CUtlLinkedList<unsigned __int64,unsigned __int64,0,unsigned __int64,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,unsigned __int64>,unsigned __int64>>::AddToTail(
             this: &this->m_WorkUnitsRemaining,
             src: &iWU) != (_DWORD)i
        || v14 != HIDWORD(i) )
      {
        _Error(a1: "CShuffledWorkUnitWalker: assumption on CUtlLinkedList indexing failed.\n");
      }
      ++i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035880
// Name: public: virtual void CDistributor_SDKMaster::DistributeWork_Master(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::DistributeWork_Master(CDistributor_SDKMaster *this, CDSInfo *pInfo)
{
  const char *ParamString; // eax
  CCriticalSection *p_m_CS; // edi
  __int64 m_ElementCount_low; // kr00_8
  __int64 v6; // kr08_8
  double v7; // [esp+Ch] [ebp-10h]
  CCriticalSectionLock v8; // [esp+14h] [ebp-8h] BYREF

  this->m_pInfo = pInfo;
  *(_WORD *)&this->m_bForceShuffle = 0;
  this->m_flLastShuffleRequestServiceTime = _Plat_FloatTime();
  this->m_bUsingMasterLocalThreads = pInfo->m_WorkerInfo.m_pProcessFn != nullptr;
  if ( VMPI_IsParamUsed(eParam: mpi_NoMasterWorkerThreads) )
  {
    ParamString = VMPI_GetParamString(eParam: mpi_NoMasterWorkerThreads);
    _Msg(a1: "%s found. No worker threads will be created.\n", ParamString);
    this->m_bUsingMasterLocalThreads = 0;
  }
  CShuffledWorkUnitWalker::Init(
    this: &this->m_WorkUnitWalker,
    nWorkUnits: pInfo->m_nWorkUnits,
    pRequester: &this->IShuffleRequester);
  CDistributor_SDKMaster::Shuffle(this);
  if ( this->m_bUsingMasterLocalThreads != 0 )
    RunThreads_Start(
      fn: (void (__cdecl *)(int, void *))CDistributor_SDKMaster::Master_WorkerThread_Static,
      pUserData: this,
      ePriority: k_eRunThreadsPriority_Idle);
  _Plat_MSTime();
  p_m_CS = &this->m_WorkUnitWalker.m_CS;
  CCriticalSectionLock::CCriticalSectionLock(this: &v8, pCS: &this->m_WorkUnitWalker.m_CS);
  CCriticalSectionLock::Lock(this: &v8);
  m_ElementCount_low = SLODWORD(this->m_WorkUnitWalker.m_WorkUnitsRemaining.m_ElementCount);
  CCriticalSectionLock::~CCriticalSectionLock(this: &v8);
  if ( m_ElementCount_low != 0 )
  {
    while ( 1 )
    {
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xC8);
      CheckLocalMasterCompletedWorkUnits();
      VMPITracker_HandleDebugKeypresses();
      if ( g_pDistributeWorkCallbacks != nullptr
        && g_pDistributeWorkCallbacks->Update(this: g_pDistributeWorkCallbacks) != 0 )
      {
        goto LABEL_16;
      }
      if ( this->m_bForceShuffle )
        goto LABEL_14;
      if ( this->m_bShuffleRequested )
      {
        v7 = _Plat_FloatTime();
        if ( v7 - this->m_flLastShuffleRequestServiceTime > 2.0 )
          break;
      }
LABEL_15:
      CCriticalSectionLock::CCriticalSectionLock(this: &v8, pCS: p_m_CS);
      CCriticalSectionLock::Lock(this: &v8);
      v6 = SLODWORD(this->m_WorkUnitWalker.m_WorkUnitsRemaining.m_ElementCount);
      CCriticalSectionLock::~CCriticalSectionLock(this: &v8);
      if ( v6 == 0 )
        goto LABEL_16;
      p_m_CS = &this->m_WorkUnitWalker.m_CS;
    }
    this->m_flLastShuffleRequestServiceTime = v7;
    this->m_bShuffleRequested = false;
LABEL_14:
    CDistributor_SDKMaster::Shuffle(this);
    _Plat_MSTime();
    this->m_bForceShuffle = false;
    goto LABEL_15;
  }
LABEL_16:
  RunThreads_End();
}

//------------------------------------------------------------------------------
// Address: 0x10035A30
// Name: public: virtual bool CDistributor_SDKMaster::HandleWorkUnitResults(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_SDKMaster::HandleWorkUnitResults(CDistributor_SDKMaster *this, unsigned __int64 iWorkUnit)
{
  return CDistributor_SDKMaster::Thread_HandleWorkUnitResults(this, iWorkUnit);
}

//------------------------------------------------------------------------------
// Address: 0x10035A50
// Name: public: virtual void CDistributor_SDKWorker::Init(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKWorker::Init(CDistributor_SDKWorker *this, CDSInfo *pInfo)
{
  this->m_iMyWorkUnitWalkerID = -1;
  this->m_pInfo = pInfo;
  CShuffledWorkUnitWalker::Init(
    this: &this->m_WorkUnitWalker,
    nWorkUnits: pInfo->m_nWorkUnits,
    pRequester: &this->IShuffleRequester);
}

//------------------------------------------------------------------------------
// Address: 0x10035A90
// Name: public: virtual void CDistributor_SDKWorker::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKWorker::Release(CDistributor_SDKWorker *this)
{
  if ( this != nullptr )
  {
    CShuffledWorkUnitWalker::~CShuffledWorkUnitWalker(this: &this->m_WorkUnitWalker);
    operator delete(p: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035AB0
// Name: class IWorkUnitDistributorMaster __near * CreateWUDistributor_SDKMaster(void)
// Source: json
//------------------------------------------------------------------------------
CDistributor_SDKMaster *__cdecl CreateWUDistributor_SDKMaster()
{
  CDistributor_SDKMaster *v0; // eax

  v0 = (CDistributor_SDKMaster *)operator new(size: 0x240u);
  if ( v0 != nullptr )
    return CDistributor_SDKMaster::CDistributor_SDKMaster(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10035AD0
// Name: public: virtual void CDistributor_SDKMaster::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_SDKMaster::Release(CDistributor_SDKMaster *this)
{
  if ( this != nullptr )
  {
    CShuffledWorkUnitWalker::~CShuffledWorkUnitWalker(this: &this->m_WorkUnitWalker);
    MessageBuffer::~MessageBuffer(this: &this->m_WUSCompletedMessageBuffer);
    CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_WUsCompletedCS.m_Data.m_Pending);
    CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_WUsCompletedCS.m_Data);
    CCriticalSection::~CCriticalSection(this: &this->m_WUsCompletedCS);
    CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_WorkersReadyCS.m_Data);
    CCriticalSection::~CCriticalSection(this: &this->m_WorkersReadyCS);
    operator delete(p: this);
  }
}

} // namespace vvis_dll
