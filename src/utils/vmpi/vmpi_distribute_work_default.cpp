// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi_distribute_work_default.cpp
// Functions: 24
// ============================================================

#include "utils\vmpi\vmpi_distribute_work_default.h"

//------------------------------------------------------------------------------
// Address: 0x10023BB0
// Name: void VMPI_SetWorkUnitsPartitionSize(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_SetWorkUnitsPartitionSize(int numWusToDeal)
{
  s_numWusToDeal = numWusToDeal;
}

//------------------------------------------------------------------------------
// Address: 0x10023D10
// Name: public: virtual void CDistributor_DefaultWorker::NoteLocalWorkUnitCompleted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultWorker::NoteLocalWorkUnitCompleted(
        CDistributor_DefaultWorker *this,
        unsigned __int64 iWU)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10023F30
// Name: public: void CWorkUnitsTracker::PrepareForWorkUnits(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkUnitsTracker::PrepareForWorkUnits(CWorkUnitsTracker *this, unsigned __int64 numUnits)
{
  int v2; // ebx

  v2 = HIDWORD(numUnits);
  CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::Reset(
    this: &this->m_arrInfo,
    uiTotal: numUnits + 1);
  if ( (v2 | (unsigned int)numUnits) != 0 )
  {
    HIBYTE(numUnits) = 0;
    CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ExpandWindow(
      this: &this->m_arrInfo,
      idxAccessible: 2u,
      x: (const unsigned __int8 *)&numUnits + 7);
    if ( HIDWORD(this->m_arrInfo.m_uiBase) != 0 || LODWORD(this->m_arrInfo.m_uiBase) != 0 || this->m_arrInfo.m_Size == 0 )
      MEMORY[0] = 1;
    else
      *this->m_arrInfo.m_Memory.m_pMemory = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023FB0
// Name: public: unsigned __int64 CWorkUnitsTracker::WorkUnitFinished(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWorkUnitsTracker::WorkUnitFinished(CWorkUnitsTracker *this, unsigned __int64 iWorkUnit)
{
  __int64 v2; // rcx
  unsigned int v4; // esi
  unsigned __int8 *v5; // eax
  unsigned __int8 v6; // cl
  unsigned __int64 v7; // rax
  unsigned int v8; // kr00_4
  unsigned __int8 *v9; // eax
  bool v10; // zf
  unsigned __int8 *v11; // eax
  unsigned int v13; // kr10_4
  unsigned __int8 *v14; // eax
  unsigned __int64 v15; // [esp-Ch] [ebp-1Ch]

  HIDWORD(v2) = HIDWORD(iWorkUnit);
  if ( HIDWORD(iWorkUnit) < HIDWORD(this->m_arrInfo.m_uiBase) )
    return 0;
  v4 = iWorkUnit;
  if ( HIDWORD(iWorkUnit) <= HIDWORD(this->m_arrInfo.m_uiBase)
    && (unsigned int)iWorkUnit < LODWORD(this->m_arrInfo.m_uiBase) )
  {
    return 0;
  }
  if ( iWorkUnit >= this->m_arrInfo.m_uiTotal )
    return 0;
  LODWORD(v2) = iWorkUnit;
  HIBYTE(iWorkUnit) = 0;
  CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ExpandWindow(
    this: &this->m_arrInfo,
    idxAccessible: v2 + 1,
    x: (const unsigned __int8 *)&iWorkUnit + 7);
  if ( __PAIR64__(HIDWORD(v2), iWorkUnit) < this->m_arrInfo.m_uiBase
    || __PAIR64__(HIDWORD(v2), iWorkUnit) >= this->m_arrInfo.m_uiBase + this->m_arrInfo.m_Size )
  {
    v5 = nullptr;
  }
  else
  {
    v5 = &this->m_arrInfo.m_Memory.m_pMemory[iWorkUnit - LODWORD(this->m_arrInfo.m_uiBase)];
  }
  v6 = *v5;
  *v5 = 2;
  if ( v6 != 1 )
  {
    if ( __PAIR64__(HIDWORD(v2), iWorkUnit) == this->m_arrInfo.m_uiBase )
    {
      do
      {
        v13 = v4 + 1;
        HIDWORD(v2) = (__PAIR64__(HIDWORD(v2), v4) + 1) >> 32;
        v4 = v13;
        if ( __PAIR64__(HIDWORD(v2), v13) >= this->m_arrInfo.m_uiBase + this->m_arrInfo.m_Size )
          break;
        v14 = __PAIR64__(HIDWORD(v2), v13) < this->m_arrInfo.m_uiBase
            ? nullptr
            : &this->m_arrInfo.m_Memory.m_pMemory[v13 - LODWORD(this->m_arrInfo.m_uiBase)];
      }
      while ( *v14 == 2 );
      CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ShrinkWindow(
        this: &this->m_arrInfo,
        idxDrop: __PAIR64__(HIDWORD(v2), v13) - 1);
    }
    return 0;
  }
  LODWORD(v2) = HIDWORD(this->m_arrInfo.m_uiBase);
  v7 = this->m_arrInfo.m_uiBase + this->m_arrInfo.m_Size;
  do
  {
    v8 = v4 + 1;
    HIDWORD(v2) = (__PAIR64__(HIDWORD(v2), v4) + 1) >> 32;
    v4 = v8;
    if ( __PAIR64__(HIDWORD(v2), v8) >= v7 )
      break;
    v9 = __PAIR64__(HIDWORD(v2), v8) < this->m_arrInfo.m_uiBase
       ? nullptr
       : &this->m_arrInfo.m_Memory.m_pMemory[v8 - LODWORD(this->m_arrInfo.m_uiBase)];
    v10 = *v9 == 2;
    LODWORD(v7) = LODWORD(this->m_arrInfo.m_uiBase) + this->m_arrInfo.m_Size;
  }
  while ( v10 );
  if ( HIDWORD(v2) < (unsigned int)v2
    || HIDWORD(v2) <= (unsigned int)v2 && v8 < LODWORD(this->m_arrInfo.m_uiBase)
    || __PAIR64__(HIDWORD(v2), v8) >= v7 )
  {
    v11 = nullptr;
  }
  else
  {
    v11 = &this->m_arrInfo.m_Memory.m_pMemory[v8 - LODWORD(this->m_arrInfo.m_uiBase)];
  }
  *v11 = 1;
  HIDWORD(v15) = (v8 != 0) + HIDWORD(v2) - 1;
  LODWORD(v15) = v8 - 1;
  CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ShrinkWindow(
    this: &this->m_arrInfo,
    idxDrop: v15);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10024130
// Name: class IWorkUnitDistributorWorker __near * CreateWUDistributor_DefaultWorker(void)
// Source: json
//------------------------------------------------------------------------------
IWorkUnitDistributorWorker *__cdecl CreateWUDistributor_DefaultWorker()
{
  char *v0; // eax
  _DWORD *v1; // esi
  int v2; // eax

  v0 = (char *)operator new(nSize: 0x84u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *(_DWORD *)v0 = &CDistributor_DefaultWorker::`vftable';
  CCriticalSection::CCriticalSection(this: (CCriticalSection *)(v0 + 4));
  v1[23] = 0;
  v1[24] = 0;
  v1[25] = 0;
  v1[31] = -1;
  v1[26] = -1;
  v1[27] = -1;
  v1[28] = -1;
  v2 = v1[23];
  v1[29] = 0;
  v1[30] = 0;
  v1[32] = v2;
  return (IWorkUnitDistributorWorker *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10024190
// Name: public: virtual void CDistributor_DefaultWorker::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultWorker::Release(CDistributor_DefaultWorker *this)
{
  if ( this != nullptr )
  {
    CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::RemoveAll(this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&this->m_WorkUnits);
    if ( this->m_WorkUnits.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_WorkUnits.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WorkUnits.m_Memory.m_pMemory);
        this->m_WorkUnits.m_Memory.m_pMemory = nullptr;
      }
      this->m_WorkUnits.m_Memory.m_nAllocationCount = 0;
    }
    CCriticalSection::~CCriticalSection(this: &this->m_CS);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100241E0
// Name: public: virtual bool CDistributor_DefaultWorker::GetNextWorkUnit(unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_DefaultWorker::GetNextWorkUnit(
        CDistributor_DefaultWorker *this,
        unsigned __int64 *pWUIndex)
{
  UtlLinkedListElem_t<unsigned __int64,int> *m_pMemory; // ecx
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *p_m_WorkUnits; // esi
  int m_Head; // eax
  int v7; // edi
  CCriticalSectionLock csLock; // [esp+4h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  if ( this->m_WorkUnits.m_ElementCount != 0 )
  {
    m_pMemory = this->m_WorkUnits.m_Memory.m_pMemory;
    p_m_WorkUnits = (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&this->m_WorkUnits;
    m_Head = this->m_WorkUnits.m_Head;
    *(_DWORD *)pWUIndex = m_pMemory[this->m_WorkUnits.m_Head].m_Element;
    *((_DWORD *)pWUIndex + 1) = HIDWORD(m_pMemory[m_Head].m_Element);
    v7 = this->m_WorkUnits.m_Head;
    CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
      this: p_m_WorkUnits,
      elem: v7);
    p_m_WorkUnits->m_Memory.m_pMemory[v7].m_Next = p_m_WorkUnits->m_FirstFree;
    p_m_WorkUnits->m_FirstFree = v7;
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 1;
  }
  else
  {
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024260
// Name: public: CDistributor_DefaultMaster::CDistributor_DefaultMaster(void)
// Source: json
//------------------------------------------------------------------------------
CDistributor_DefaultMaster *__thiscall CDistributor_DefaultMaster::CDistributor_DefaultMaster(
        CDistributor_DefaultMaster *this)
{
  CDistributor_DefaultMaster *result; // eax
  UtlLinkedListElem_t<CWorkUnitInfo,int> *m_pMemory; // ecx

  result = this;
  this->__vftable = (CDistributor_DefaultMaster_vtbl *)&CDistributor_DefaultMaster::`vftable';
  this->m_Partitions.m_Memory.m_pMemory = nullptr;
  this->m_Partitions.m_Memory.m_nAllocationCount = 0;
  this->m_Partitions.m_Memory.m_nGrowSize = 0;
  this->m_Partitions.m_LastAlloc.index = -1;
  this->m_Partitions.m_Head = -1;
  this->m_Partitions.m_Tail = -1;
  this->m_Partitions.m_FirstFree = -1;
  this->m_Partitions.m_ElementCount = 0;
  this->m_Partitions.m_NumAlloced = 0;
  this->m_Partitions.m_pElements = this->m_Partitions.m_Memory.m_pMemory;
  this->m_WULookup.m_Memory.m_pMemory = nullptr;
  this->m_WULookup.m_Memory.m_nAllocationCount = 0;
  this->m_WULookup.m_Memory.m_nGrowSize = 0;
  this->m_WULookup.m_Size = 0;
  this->m_WULookup.m_pElements = nullptr;
  this->m_WULookup.m_uiBase = 0;
  this->m_WULookup.m_uiTotal = 0;
  this->m_WUInfo.m_Memory.m_pMemory = nullptr;
  this->m_WUInfo.m_Memory.m_nAllocationCount = 0;
  this->m_WUInfo.m_Memory.m_nGrowSize = 0;
  this->m_WUInfo.m_LastAlloc.index = -1;
  this->m_WUInfo.m_ElementCount = 0;
  this->m_WUInfo.m_NumAlloced = 0;
  m_pMemory = this->m_WUInfo.m_Memory.m_pMemory;
  result->m_WUInfo.m_Head = -1;
  result->m_WUInfo.m_Tail = -1;
  result->m_WUInfo.m_FirstFree = -1;
  result->m_WUInfo.m_pElements = m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100242D0
// Name: public: virtual bool CDistributor_DefaultMaster::HandlePacket(class MessageBuffer __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDistributor_DefaultMaster::HandlePacket(
        CDistributor_DefaultMaster *this,
        MessageBuffer *pBuf,
        MessageBuffer *iSource,
        bool bIgnoreContents)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100242E0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024AA0
// Name: CompareSoonestWorkUnitSets
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CompareSoonestWorkUnitSets(
        CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *const *x,
        CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *const *y)
{
  int *v2; // edx
  int m_Head; // eax
  unsigned int v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // ebx
  int v7; // ecx
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  unsigned __int64 jobsX[4]; // [esp+Ch] [ebp-40h] BYREF
  unsigned __int64 jobsY[4]; // [esp+2Ch] [ebp-20h] BYREF

  v2 = (int *)*x;
  m_Head = (*x)->m_Head;
  v4 = -1;
  v5 = -1;
  v6 = -1;
  v7 = 0;
  memset(jobsX, 255, 16);
  jobsX[3] = -1;
  memset(jobsY, 255, 16);
  jobsY[3] = -1;
  if ( m_Head != -1 )
  {
    v8 = *v2;
    do
    {
      v9 = 2 * m_Head;
      LODWORD(jobsX[v7]) = *(_DWORD *)(v8 + 8 * v9);
      HIDWORD(jobsX[v7++]) = *(_DWORD *)(v8 + 8 * v9 + 4);
      if ( v7 >= 4 )
        break;
      m_Head = *(_DWORD *)(v8 + 8 * v9 + 12);
    }
    while ( m_Head != -1 );
    v5 = HIDWORD(jobsX[3]);
  }
  v10 = (*y)->m_Head;
  v11 = 0;
  if ( v10 != -1 )
  {
    v12 = **(_DWORD **)y;
    do
    {
      v13 = 2 * v10;
      LODWORD(jobsY[v11]) = *(_DWORD *)(v12 + 8 * v13);
      HIDWORD(jobsY[v11++]) = *(_DWORD *)(v12 + 8 * v13 + 4);
      if ( v11 >= 4 )
        break;
      v10 = *(_DWORD *)(v12 + 8 * v13 + 12);
    }
    while ( v10 != -1 );
    v4 = HIDWORD(jobsY[3]);
    v6 = jobsY[3];
  }
  if ( LODWORD(jobsX[3]) != v6 || v5 != v4 )
  {
    if ( v5 > v4 )
      return false;
    if ( v5 >= v4 )
      return LODWORD(jobsX[3]) < v6;
    return true;
  }
  if ( jobsX[1] == jobsY[1] )
  {
    if ( HIDWORD(jobsX[0]) > HIDWORD(jobsY[0]) )
      return false;
    if ( HIDWORD(jobsX[0]) < HIDWORD(jobsY[0]) )
      return true;
    return LODWORD(jobsX[0]) < LODWORD(jobsY[0]);
  }
  else
  {
    if ( HIDWORD(jobsX[1]) > HIDWORD(jobsY[1]) )
      return false;
    if ( HIDWORD(jobsX[1]) < HIDWORD(jobsY[1]) )
      return true;
    return LODWORD(jobsX[1]) < LODWORD(jobsY[1]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024BB0
// Name: public: void CDistributor_DefaultMaster::SendPartitionToWorker(class CPartitionInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::SendPartitionToWorker(
        CDistributor_DefaultMaster *this,
        CPartitionInfo *pPartition,
        int iWorker)
{
  int m_Head; // esi
  UtlLinkedListElem_t<unsigned __int64,int> *m_pMemory; // eax
  int v5; // esi
  int Name; // eax
  MessageBuffer mb; // [esp+Ch] [ebp-18h] BYREF
  unsigned __int64 iWU; // [esp+1Ch] [ebp-8h] BYREF

  MessageBuffer::MessageBuffer(this: &mb);
  PrepareDistributeWorkHeader(pBuf: &mb, cSubpacketID: 0x32u);
  m_Head = pPartition->m_WUs.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = pPartition->m_WUs.m_Memory.m_pMemory;
    do
    {
      v5 = m_Head;
      iWU = m_pMemory[v5].m_Element;
      MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&iWU, bytes: 8u);
      VMPITracker_WorkUnitSentToWorker(iWorkUnit: iWU, iWorker);
      m_pMemory = pPartition->m_WUs.m_Memory.m_pMemory;
      m_Head = m_pMemory[v5].m_Next;
    }
    while ( m_Head != -1 );
  }
  Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  VMPI_SendData(pData: mb.data, nBytes: Name, iDest: iWorker, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x10025620
// Name: public: virtual void CDistributor_DefaultMaster::DisconnectHandler(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::DisconnectHandler(CDistributor_DefaultMaster *this, int workerID)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CPartitionInfo *,int> *m_pMemory; // edx

  m_Head = this->m_Partitions.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_Partitions.m_Memory.m_pMemory;
    while ( m_pMemory[m_Head].m_Element->m_iWorker != workerID )
    {
      m_Head = m_pMemory[m_Head].m_Next;
      if ( m_Head == -1 )
        return;
    }
    m_pMemory[m_Head].m_Element->m_iWorker = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025670
// Name: public: virtual void CDistributor_DefaultMaster::DistributeWork_Master(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::DistributeWork_Master(CDistributor_DefaultMaster *this, CDSInfo *pInfo)
{
  this->m_pInfo = pInfo;
  CWorkUnitsTracker::PrepareForWorkUnits(this: &g_MasterWorkUnitsTracker, numUnits: pInfo->m_nWorkUnits);
  CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo>>::Reset(
    this: &this->m_WULookup,
    uiTotal: pInfo->m_nWorkUnits);
  if ( this->m_WULookup.m_uiBase < this->m_WULookup.m_uiTotal )
  {
    do
    {
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xC8);
      VMPITracker_HandleDebugKeypresses();
    }
    while ( (g_pDistributeWorkCallbacks == nullptr
          || g_pDistributeWorkCallbacks->Update(this: g_pDistributeWorkCallbacks) == 0)
         && this->m_WULookup.m_uiBase < this->m_WULookup.m_uiTotal );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025790
// Name: public: CDistributor_DefaultMaster::~CDistributor_DefaultMaster(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::~CDistributor_DefaultMaster(CDistributor_DefaultMaster *this)
{
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::RemoveAll(this: &this->m_WUInfo);
  if ( this->m_WUInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_WUInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WUInfo.m_Memory.m_pMemory);
      this->m_WUInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_WUInfo.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_WULookup);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_Partitions);
  if ( this->m_Partitions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Partitions.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Partitions.m_Memory.m_pMemory);
      this->m_Partitions.m_Memory.m_pMemory = nullptr;
    }
    this->m_Partitions.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100258F0
// Name: public: class CPartitionInfo __near * CDistributor_DefaultMaster::AddPartition(int)
// Source: json
//------------------------------------------------------------------------------
CPartitionInfo *__thiscall CDistributor_DefaultMaster::AddPartition(CDistributor_DefaultMaster *this, int iWorker)
{
  CPartitionInfo *v3; // eax
  CPartitionInfo *v4; // esi
  UtlLinkedListElem_t<unsigned __int64,int> *m_pMemory; // ecx
  CPartitionInfo *pNew; // [esp+8h] [ebp-4h] BYREF

  v3 = (CPartitionInfo *)operator new(nSize: 0x30u);
  v4 = nullptr;
  if ( v3 != nullptr )
  {
    v3->m_WUs.m_Memory.m_pMemory = nullptr;
    v3->m_WUs.m_Memory.m_nAllocationCount = 0;
    v3->m_WUs.m_Memory.m_nGrowSize = 0;
    v3->m_WUs.m_LastAlloc.index = -1;
    v3->m_WUs.m_Head = -1;
    v3->m_WUs.m_Tail = -1;
    v3->m_WUs.m_FirstFree = -1;
    m_pMemory = v3->m_WUs.m_Memory.m_pMemory;
    v3->m_WUs.m_ElementCount = 0;
    v3->m_WUs.m_NumAlloced = 0;
    v3->m_WUs.m_pElements = m_pMemory;
    v4 = v3;
  }
  pNew = v4;
  v4->m_iPartition = CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::AddToTail(
                       this: &this->m_Partitions,
                       src: &pNew);
  v4->m_iWorker = iWorker;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10025950
// Name: public: bool CDistributor_DefaultMaster::SplitWUsPartition(class CPartitionInfo __near *,class CPartitionInfo __near * __near *,class CPartitionInfo __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_DefaultMaster::SplitWUsPartition(
        CDistributor_DefaultMaster *this,
        CPartitionInfo *pPartitionLarge,
        CPartitionInfo **ppFirstHalf,
        CPartitionInfo **ppSecondHalf,
        CPartitionInfo *iFirstHalfWorker,
        int iSecondHalfWorker)
{
  int m_ElementCount; // eax
  CDistributor_DefaultMaster *v8; // ebx
  CPartitionInfo *v9; // eax
  int m_Head; // esi
  UtlLinkedListElem_t<unsigned __int64,int> *m_pMemory; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  unsigned int m_uiBase_high; // ecx
  unsigned int m_uiBase; // esi
  int v16; // eax
  int v17; // ebx
  UtlLinkedListElem_t<unsigned __int64,int> *v18; // eax
  int v19; // edx
  int m_Tail; // ecx
  UtlLinkedListElem_t<unsigned __int64,int> *v21; // esi
  CPartitionInfo *arrNewParts[2]; // [esp+Ch] [ebp-14h]
  unsigned __int64 iWU; // [esp+14h] [ebp-Ch]
  CDistributor_DefaultMaster *v25; // [esp+1Ch] [ebp-4h]
  int nCount; // [esp+28h] [ebp+8h]
  int iHead; // [esp+2Ch] [ebp+Ch]
  CPartitionInfo *pTo; // [esp+34h] [ebp+14h]
  int k; // [esp+38h] [ebp+18h]

  m_ElementCount = pPartitionLarge->m_WUs.m_ElementCount;
  v8 = this;
  v25 = this;
  nCount = m_ElementCount;
  if ( m_ElementCount <= 1 )
  {
    *ppFirstHalf = nullptr;
    v9 = CDistributor_DefaultMaster::AddPartition(this, iWorker: iSecondHalfWorker);
  }
  else
  {
    *ppFirstHalf = CDistributor_DefaultMaster::AddPartition(this, iWorker: (int)iFirstHalfWorker);
    v9 = CDistributor_DefaultMaster::AddPartition(this: v8, iWorker: iSecondHalfWorker);
  }
  *ppSecondHalf = v9;
  if ( *ppFirstHalf != nullptr )
    arrNewParts[0] = *ppFirstHalf;
  else
    arrNewParts[0] = *ppSecondHalf;
  arrNewParts[1] = *ppSecondHalf;
  k = 0;
  if ( nCount > 0 )
  {
    while ( 1 )
    {
      m_Head = pPartitionLarge->m_WUs.m_Head;
      iWU = pPartitionLarge->m_WUs.m_Memory.m_pMemory[m_Head].m_Element;
      if ( m_Head >= 0
        && m_Head < pPartitionLarge->m_WUs.m_Memory.m_nAllocationCount
        && m_Head <= pPartitionLarge->m_WUs.m_LastAlloc.index )
      {
        m_pMemory = pPartitionLarge->m_WUs.m_Memory.m_pMemory;
        if ( m_pMemory[m_Head].m_Previous != m_Head )
        {
          m_Previous = m_pMemory[m_Head].m_Previous;
          if ( m_Previous == -1 )
          {
            pPartitionLarge->m_WUs.m_Head = m_pMemory[m_Head].m_Next;
          }
          else
          {
            m_pMemory[m_Previous].m_Next = m_pMemory[m_Head].m_Next;
            v8 = v25;
          }
          m_Next = m_pMemory[m_Head].m_Next;
          if ( m_Next == -1 )
          {
            pPartitionLarge->m_WUs.m_Tail = m_pMemory[m_Head].m_Previous;
          }
          else
          {
            pPartitionLarge->m_WUs.m_Memory.m_pMemory[m_Next].m_Previous = m_pMemory[m_Head].m_Previous;
            v8 = v25;
          }
          m_pMemory[m_Head].m_Next = m_Head;
          m_pMemory[m_Head].m_Previous = m_Head;
          --pPartitionLarge->m_WUs.m_ElementCount;
        }
      }
      pPartitionLarge->m_WUs.m_Memory.m_pMemory[m_Head].m_Next = pPartitionLarge->m_WUs.m_FirstFree;
      pPartitionLarge->m_WUs.m_FirstFree = m_Head;
      m_uiBase_high = HIDWORD(v8->m_WULookup.m_uiBase);
      m_uiBase = v8->m_WULookup.m_uiBase;
      pTo = arrNewParts[k >= nCount / 2];
      if ( iWU < __PAIR64__(m_uiBase_high, m_uiBase)
        || iWU >= __PAIR64__(m_uiBase_high, m_uiBase) + v8->m_WULookup.m_Size )
      {
        iHead = 0;
      }
      else
      {
        iHead = (int)&v8->m_WULookup.m_Memory.m_pMemory[iWU - m_uiBase];
      }
      *(_DWORD *)(iHead + 4) = pTo->m_iPartition;
      v16 = CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::AllocInternal(
              this: &pTo->m_WUs,
              multilist: false);
      v17 = v16;
      if ( v16 == -1 )
      {
        v17 = -1;
      }
      else
      {
        CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
          this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&pTo->m_WUs,
          elem: v16);
        v18 = pTo->m_WUs.m_Memory.m_pMemory;
        v19 = v17;
        v18[v19].m_Next = -1;
        m_Tail = pTo->m_WUs.m_Tail;
        v18[v19].m_Previous = m_Tail;
        pTo->m_WUs.m_Tail = v17;
        if ( m_Tail == -1 )
          pTo->m_WUs.m_Head = v17;
        else
          pTo->m_WUs.m_Memory.m_pMemory[m_Tail].m_Next = v17;
        ++pTo->m_WUs.m_ElementCount;
        v21 = &pTo->m_WUs.m_Memory.m_pMemory[v19];
        if ( v21 != nullptr )
          v21->m_Element = iWU;
      }
      *(_DWORD *)(iHead + 8) = v17;
      if ( ++k >= nCount )
        break;
      v8 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025B50
// Name: public: virtual bool CDistributor_DefaultWorker::HandlePacket(class MessageBuffer __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_DefaultWorker::HandlePacket(
        CDistributor_DefaultWorker *this,
        MessageBuffer *pBuf,
        int iSource,
        bool bIgnoreContents)
{
  char Name; // bl
  CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *p_m_WorkUnits; // ebx
  int v8; // esi
  unsigned int i; // esi
  unsigned __int64 iWU; // [esp+8h] [ebp-10h] BYREF
  CCriticalSectionLock csLock; // [esp+10h] [ebp-8h] BYREF

  if ( pBuf->data[1] != 50 )
    return 0;
  if ( bIgnoreContents )
    return 1;
  Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)pBuf);
  if ( ((Name - (unsigned __int8)MessageBuffer::getOffset(this: (CVMPIFile_Memory *)pBuf)) & 7) != 0 )
    _Error(a1: "DistributeWork: invalid work units packet from master");
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  p_m_WorkUnits = &this->m_WorkUnits;
  CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::Purge(this: &this->m_WorkUnits);
  v8 = ConCommandBase::GetName(this: (CVMPIFile_Memory *)pBuf);
  for ( i = (unsigned int)(v8 - MessageBuffer::getOffset(this: (CVMPIFile_Memory *)pBuf)) >> 3; i != 0; --i )
  {
    MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&iWU, bytes: 8u);
    CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::AddToTail(
      this: p_m_WorkUnits,
      src: &iWU);
  }
  CCriticalSectionLock::Unlock(this: &csLock);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025C20
// Name: class IWorkUnitDistributorMaster __near * CreateWUDistributor_DefaultMaster(void)
// Source: json
//------------------------------------------------------------------------------
CDistributor_DefaultMaster *__cdecl CreateWUDistributor_DefaultMaster()
{
  CDistributor_DefaultMaster *v0; // eax

  v0 = (CDistributor_DefaultMaster *)operator new(nSize: 0x80u);
  if ( v0 != nullptr )
    return CDistributor_DefaultMaster::CDistributor_DefaultMaster(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10025C40
// Name: public: virtual void CDistributor_DefaultMaster::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::Release(CDistributor_DefaultMaster *this)
{
  if ( this != nullptr )
  {
    CDistributor_DefaultMaster::~CDistributor_DefaultMaster(this);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025C60
// Name: public: int CDistributor_DefaultMaster::FindSoonestPartition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDistributor_DefaultMaster::FindSoonestPartition(CDistributor_DefaultMaster *this)
{
  int m_ElementCount; // eax
  IMemAlloc_vtbl *v3; // edx
  int m_Head; // eax
  int v5; // edi
  CPartitionInfo *m_Element; // edx
  int v7; // ecx
  UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int v9; // esi
  CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t *p_m_Data; // esi
  unsigned __int16 Inorder; // ax
  int elem; // esi
  int v14; // ebx
  CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short> sortedPartitions; // [esp+8h] [ebp-2Ch] BYREF
  CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t insert; // [esp+24h] [ebp-10h] BYREF
  unsigned __int16 parent[3]; // [esp+2Ch] [ebp-8h] BYREF
  bool leftchild; // [esp+33h] [ebp-1h] BYREF

  m_ElementCount = this->m_Partitions.m_ElementCount;
  sortedPartitions.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *const *, CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *const *))CompareSoonestWorkUnitSets;
  memset(&sortedPartitions.m_Tree.m_Elements, 0, sizeof(sortedPartitions.m_Tree.m_Elements));
  *(_DWORD *)&sortedPartitions.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&sortedPartitions.m_Tree.m_FirstFree = -1;
  sortedPartitions.m_Tree.m_pElements = nullptr;
  if ( m_ElementCount > 0 )
  {
    v3 = _g_pMemAlloc->__vftable;
    sortedPartitions.m_Tree.m_Elements.m_nAllocationCount = m_ElementCount;
    sortedPartitions.m_Tree.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *)v3->Alloc_2(this: _g_pMemAlloc, a2: 16 * m_ElementCount);
  }
  m_Head = this->m_Partitions.m_Head;
  if ( m_Head == -1 )
    goto LABEL_17;
  do
  {
    v5 = m_Head;
    m_Element = this->m_Partitions.m_Memory.m_pMemory[m_Head].m_Element;
    insert.elem = m_Head;
    insert.key = &m_Element->m_WUs;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &sortedPartitions.m_Tree,
      &insert,
      parent,
      &leftchild);
    v7 = (unsigned __int16)CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &sortedPartitions.m_Tree);
    m_pMemory = sortedPartitions.m_Tree.m_Elements.m_pMemory;
    v9 = v7;
    sortedPartitions.m_Tree.m_Elements.m_pMemory[v9].m_Parent = parent[0];
    m_pMemory[v9].m_Right = -1;
    m_pMemory[v9].m_Left = -1;
    m_pMemory[v9].m_Tag = 0;
    if ( parent[0] == 0xFFFF )
    {
      sortedPartitions.m_Tree.m_Root = v7;
    }
    else if ( leftchild )
    {
      m_pMemory[parent[0]].m_Left = v7;
    }
    else
    {
      m_pMemory[parent[0]].m_Right = v7;
    }
    CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &sortedPartitions.m_Tree,
      elem: v7);
    ++sortedPartitions.m_Tree.m_NumElements;
    p_m_Data = &sortedPartitions.m_Tree.m_Elements.m_pMemory[v9].m_Data;
    if ( p_m_Data != nullptr )
      *p_m_Data = insert;
    m_Head = this->m_Partitions.m_Memory.m_pMemory[v5].m_Next;
  }
  while ( m_Head != -1 );
  if ( sortedPartitions.m_Tree.m_NumElements == 0 )
  {
LABEL_17:
    v14 = this->m_Partitions.m_Head;
    CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &sortedPartitions.m_Tree);
    if ( sortedPartitions.m_Tree.m_Elements.m_nGrowSize >= 0 && sortedPartitions.m_Tree.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sortedPartitions.m_Tree.m_Elements.m_pMemory);
    return v14;
  }
  else
  {
    Inorder = CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &sortedPartitions.m_Tree);
    elem = sortedPartitions.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
    CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &sortedPartitions.m_Tree);
    if ( sortedPartitions.m_Tree.m_Elements.m_nGrowSize >= 0 && sortedPartitions.m_Tree.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sortedPartitions.m_Tree.m_Elements.m_pMemory);
    return elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025E30
// Name: public: void CDistributor_DefaultMaster::AssignWUsToWorker(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::AssignWUsToWorker(CDistributor_DefaultMaster *this, int iWorker)
{
  int m_pMemory; // edx
  CDistributor_DefaultMaster *v3; // edi
  int m_Head; // esi
  int v5; // ecx
  int v6; // edi
  int v7; // eax
  unsigned __int64 m_nWorkUnits; // rcx
  CPartitionInfo *v9; // eax
  CDSInfo *m_pInfo; // edi
  bool v11; // zf
  unsigned __int64 v12; // kr08_8
  unsigned int m_uiBase; // edi
  CWULookupInfo *v14; // ebx
  CPartitionInfo *v15; // edi
  CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *p_m_WUs; // ecx
  int v17; // eax
  int v18; // esi
  UtlLinkedListElem_t<unsigned __int64,int> *v19; // eax
  int v20; // edx
  int m_Tail; // ecx
  UtlLinkedListElem_t<unsigned __int64,int> *v22; // edi
  CDistributor_DefaultMaster *v23; // edi
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *p_m_WUInfo; // ecx
  int v25; // eax
  int v26; // esi
  UtlLinkedListElem_t<CWorkUnitInfo,int> *v27; // eax
  int v28; // edx
  int v29; // ecx
  UtlLinkedListElem_t<CWorkUnitInfo,int> *v30; // edi
  unsigned __int64 v31; // rax
  int m_Next; // eax
  UtlLinkedListElem_t<CPartitionInfo *,int> *v33; // edx
  unsigned __int64 m_uiTotal; // rcx
  unsigned int v35; // esi
  unsigned __int64 v36; // rax
  unsigned int v37; // ebx
  unsigned int v38; // esi
  unsigned int v39; // ebx
  CPartitionInfo *v40; // eax
  CDistributor_DefaultMaster *v41; // esi
  unsigned int v42; // edi
  CPartitionInfo *v43; // eax
  UtlLinkedListElem_t<unsigned __int64,int> *v44; // ecx
  CPartitionInfo *v45; // esi
  int v46; // eax
  __int64 v47; // rcx
  int v48; // esi
  unsigned int v49; // edi
  int v50; // eax
  int v51; // edi
  int v52; // eax
  int v53; // edx
  int v54; // ecx
  int *v55; // esi
  CDistributor_DefaultMaster *v56; // edi
  int v57; // eax
  int v58; // esi
  UtlLinkedListElem_t<CWorkUnitInfo,int> *v59; // eax
  int v60; // edx
  int v61; // ecx
  UtlLinkedListElem_t<CWorkUnitInfo,int> *v62; // edi
  int v63; // kr04_4
  void *v64; // esi
  CDistributor_DefaultMaster *v65; // esi
  int SoonestPartition; // eax
  int v67; // ebx
  UtlLinkedListElem_t<CPartitionInfo *,int> *v68; // edx
  CPartitionInfo *m_Element; // edi
  unsigned int iEnd; // [esp+Ch] [ebp-30h]
  unsigned __int64 iEnda; // [esp+Ch] [ebp-30h]
  int i; // [esp+14h] [ebp-28h]
  unsigned __int64 iBegin; // [esp+1Ch] [ebp-20h]
  CPartitionInfo *pOldHalf; // [esp+28h] [ebp-14h] BYREF
  CPartitionInfo *pNewHalf; // [esp+2Ch] [ebp-10h] BYREF
  int iOldWorker; // [esp+30h] [ebp-Ch]
  CPartitionInfo *pPartition; // [esp+34h] [ebp-8h]
  CDistributor_DefaultMaster *v78; // [esp+38h] [ebp-4h]

  m_pMemory = iWorker;
  v3 = this;
  m_Head = this->m_Partitions.m_Head;
  v78 = this;
  if ( m_Head != -1 )
  {
    this = (CDistributor_DefaultMaster *)this->m_Partitions.m_Memory.m_pMemory;
    while ( *(_DWORD *)(*((_DWORD *)&this->__vftable + 3 * m_Head) + 4) != iWorker )
    {
      m_Head = (int)(&this->m_Partitions.m_Memory.m_pMemory)[3 * m_Head];
      if ( m_Head == -1 )
        goto LABEL_13;
    }
    v5 = *((_DWORD *)&this->__vftable + 3 * m_Head);
    iOldWorker = v5;
    if ( v5 != 0 )
    {
      v6 = v5;
      CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::RemoveAll(this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)(v5 + 8));
      if ( *(int *)(v6 + 16) >= 0 )
      {
        if ( *(_DWORD *)(v6 + 8) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v6 + 8));
          *(_DWORD *)(v6 + 8) = 0;
        }
        *(_DWORD *)(v6 + 12) = 0;
      }
      free(pMem: (void *)iOldWorker);
      v3 = v78;
    }
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&v3->m_Partitions,
      elem: m_Head);
    m_pMemory = (int)v3->m_Partitions.m_Memory.m_pMemory;
    *(_DWORD *)(12 * m_Head + m_pMemory + 8) = v3->m_Partitions.m_FirstFree;
    v3->m_Partitions.m_FirstFree = m_Head;
  }
LABEL_13:
  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "A");
  v7 = _CommandLine(a1: this, a2: m_pMemory);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-mpi_NoScheduler") != 0 )
  {
    _Warning(a1: "\n\n-mpi_NoScheduler found: Warning - this should only be used for testing and with 1 worker!\n\n");
    m_nWorkUnits = v3->m_pInfo->m_nWorkUnits;
    if ( m_nWorkUnits >= v3->m_WULookup.m_uiBase + v3->m_WULookup.m_Size )
      CUtlVector<CWULookupInfo,CUtlMemory<CWULookupInfo,int>>::InsertMultipleBefore(
        this: &v3->m_WULookup,
        elem: v3->m_WULookup.m_Size,
        num: m_nWorkUnits - LODWORD(v3->m_WULookup.m_uiBase) - v3->m_WULookup.m_Size + 1);
    v9 = CDistributor_DefaultMaster::AddPartition(this: v3, iWorker);
    m_pInfo = v3->m_pInfo;
    v11 = HIDWORD(m_pInfo->m_nWorkUnits) == 0;
    pPartition = v9;
    iOldWorker = 0;
    if ( !v11 || LODWORD(m_pInfo->m_nWorkUnits) != 0 )
    {
      v12 = 0;
      do
      {
        m_uiBase = v78->m_WULookup.m_uiBase;
        pOldHalf = (CPartitionInfo *)HIDWORD(v78->m_WULookup.m_uiBase);
        if ( v12 < __PAIR64__((unsigned int)pOldHalf, m_uiBase)
          || v12 >= __PAIR64__((unsigned int)pOldHalf, m_uiBase) + v78->m_WULookup.m_Size )
        {
          v14 = nullptr;
        }
        else
        {
          v14 = &v78->m_WULookup.m_Memory.m_pMemory[v12 - LODWORD(v78->m_WULookup.m_uiBase)];
        }
        v15 = pPartition;
        p_m_WUs = &pPartition->m_WUs;
        v14->m_iPartition = pPartition->m_iPartition;
        v17 = CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::AllocInternal(
                this: p_m_WUs,
                multilist: false);
        v18 = v17;
        if ( v17 == -1 )
        {
          v18 = -1;
        }
        else
        {
          CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
            this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&v15->m_WUs,
            elem: v17);
          v19 = v15->m_WUs.m_Memory.m_pMemory;
          v20 = v18;
          v19[v20].m_Next = -1;
          m_Tail = v15->m_WUs.m_Tail;
          v19[v20].m_Previous = m_Tail;
          v15->m_WUs.m_Tail = v18;
          if ( m_Tail == -1 )
            v15->m_WUs.m_Head = v18;
          else
            v15->m_WUs.m_Memory.m_pMemory[m_Tail].m_Next = v18;
          ++v15->m_WUs.m_ElementCount;
          v22 = &v15->m_WUs.m_Memory.m_pMemory[v20];
          if ( v22 != nullptr )
            v22->m_Element = v12;
        }
        v23 = v78;
        p_m_WUInfo = &v78->m_WUInfo;
        v14->m_iPartitionListIndex = v18;
        v25 = CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::AllocInternal(
                this: p_m_WUInfo,
                multilist: false);
        v26 = v25;
        if ( v25 == -1 )
        {
          v26 = -1;
        }
        else
        {
          CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
            this: &v23->m_WUInfo,
            elem: v25);
          v27 = v23->m_WUInfo.m_Memory.m_pMemory;
          v28 = v26;
          v27[v28].m_Next = -1;
          v29 = v23->m_WUInfo.m_Tail;
          v27[v28].m_Previous = v29;
          v23->m_WUInfo.m_Tail = v26;
          if ( v29 == -1 )
            v23->m_WUInfo.m_Head = v26;
          else
            v23->m_WUInfo.m_Memory.m_pMemory[v29].m_Next = v26;
          ++v23->m_WUInfo.m_ElementCount;
          v30 = &v23->m_WUInfo.m_Memory.m_pMemory[v28];
          if ( v30 != nullptr )
            v30->m_Element.m_iWorkUnit = v12;
        }
        v31 = ++iOldWorker;
        v14->m_iWUInfo = v26;
        v12 = v31;
      }
      while ( v31 < v78->m_pInfo->m_nWorkUnits );
    }
    CDistributor_DefaultMaster::SendPartitionToWorker(this: v78, pPartition, iWorker);
  }
  else
  {
    m_Next = v3->m_Partitions.m_Head;
    if ( m_Next == -1 )
    {
LABEL_45:
      m_uiTotal = v78->m_WULookup.m_uiTotal;
      v35 = (v78->m_WULookup.m_uiBase + v78->m_WULookup.m_Size) >> 32;
      i = LODWORD(v78->m_WULookup.m_uiBase) + v78->m_WULookup.m_Size;
      iEnd = v78->m_WULookup.m_uiTotal;
      if ( v78->m_WULookup.m_uiBase + v78->m_WULookup.m_Size >= m_uiTotal )
      {
        v65 = v78;
        SoonestPartition = CDistributor_DefaultMaster::FindSoonestPartition(this: v78);
        v67 = SoonestPartition;
        if ( SoonestPartition >= 0 )
        {
          v68 = v78->m_Partitions.m_Memory.m_pMemory;
          pPartition = (CPartitionInfo *)&v78->m_Partitions;
          m_Element = v68[SoonestPartition].m_Element;
          pOldHalf = nullptr;
          pNewHalf = nullptr;
          iOldWorker = m_Element->m_iWorker;
          if ( CDistributor_DefaultMaster::SplitWUsPartition(
                 this: v78,
                 pPartitionLarge: m_Element,
                 ppFirstHalf: &pOldHalf,
                 ppSecondHalf: &pNewHalf,
                 iFirstHalfWorker: (CPartitionInfo *)iOldWorker,
                 iSecondHalfWorker: iWorker) != 0 )
          {
            if ( pOldHalf != nullptr )
              CDistributor_DefaultMaster::SendPartitionToWorker(this: v65, pPartition: pOldHalf, iWorker: iOldWorker);
            if ( pNewHalf != nullptr )
              CDistributor_DefaultMaster::SendPartitionToWorker(this: v65, pPartition: pNewHalf, iWorker);
            CPartitionInfo::`scalar deleting destructor'(this: m_Element, a2: 1u);
            CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::Remove(
              this: (CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int> > *)pPartition,
              elem: v67);
          }
        }
      }
      else
      {
        LODWORD(m_uiTotal) = s_numWusToDeal;
        if ( s_numWusToDeal <= 0 )
        {
          LODWORD(m_uiTotal) = __PAIR64__(HIDWORD(m_uiTotal), iEnd) / g_nMaxWorkerCount;
          if ( (int)m_uiTotal <= 0 )
            LODWORD(m_uiTotal) = 8;
        }
        iBegin = v78->m_WULookup.m_uiBase + v78->m_WULookup.m_Size;
        v36 = __PAIR64__(v35, i) + (int)m_uiTotal * g_nMaxWorkerCount;
        if ( v36 >= __PAIR64__(HIDWORD(m_uiTotal), iEnd) )
          v36 = v78->m_WULookup.m_uiTotal;
        v37 = v36;
        iEnda = v36;
        if ( v36 - 1 >= __PAIR64__(v35, i) )
          CUtlVector<CWULookupInfo,CUtlMemory<CWULookupInfo,int>>::InsertMultipleBefore(
            this: &v78->m_WULookup,
            elem: v78->m_WULookup.m_Size,
            num: v36 - v78->m_WULookup.m_Size - LODWORD(v78->m_WULookup.m_uiBase));
        v38 = v37;
        v39 = g_nMaxWorkerCount;
        if ( __PAIR64__(HIDWORD(iEnda), v38) - iBegin >= g_nMaxWorkerCount )
        {
          pOldHalf = (CPartitionInfo *)g_nMaxWorkerCount;
        }
        else
        {
          v39 = v38 - iBegin;
          pOldHalf = (CPartitionInfo *)(v38 - iBegin);
        }
        v41 = v78;
        iOldWorker = (int)operator new(nSize: 4 * v39);
        *(_DWORD *)iOldWorker = CDistributor_DefaultMaster::AddPartition(this: v78, iWorker);
        v42 = 1;
        if ( v39 > 1 )
        {
          pPartition = (CPartitionInfo *)&v41->m_Partitions;
          do
          {
            v43 = (CPartitionInfo *)operator new(nSize: 0x30u);
            if ( v43 != nullptr )
            {
              v43->m_WUs.m_Memory.m_pMemory = nullptr;
              v43->m_WUs.m_Memory.m_nAllocationCount = 0;
              v43->m_WUs.m_Memory.m_nGrowSize = 0;
              v43->m_WUs.m_LastAlloc.index = -1;
              v43->m_WUs.m_ElementCount = 0;
              v43->m_WUs.m_NumAlloced = 0;
              v44 = v43->m_WUs.m_Memory.m_pMemory;
              v43->m_WUs.m_Head = -1;
              v43->m_WUs.m_Tail = -1;
              v43->m_WUs.m_FirstFree = -1;
              v43->m_WUs.m_pElements = v44;
              v45 = v43;
            }
            else
            {
              v45 = nullptr;
            }
            pNewHalf = v45;
            v45->m_iPartition = CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::AddToTail(
                                  this: (CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int> > *)pPartition,
                                  src: &pNewHalf);
            v46 = iOldWorker;
            v45->m_iWorker = -1;
            *(_DWORD *)(v46 + 4 * v42++) = v45;
          }
          while ( v42 < v39 );
        }
        HIDWORD(v47) = HIDWORD(iBegin);
        if ( iBegin < iEnda )
        {
          do
          {
            LODWORD(v47) = i;
            v48 = *(_DWORD *)(iOldWorker + 4 * ((v47 - iBegin) % (unsigned int)pOldHalf));
            LODWORD(v47) = HIDWORD(v78->m_WULookup.m_uiBase);
            v49 = v78->m_WULookup.m_uiBase;
            pNewHalf = (CPartitionInfo *)&v78->m_WULookup;
            if ( __PAIR64__(HIDWORD(v47), i) < __PAIR64__(v47, v49)
              || __PAIR64__(HIDWORD(v47), i) >= __PAIR64__(v47, v49) + v78->m_WULookup.m_Size )
            {
              pPartition = nullptr;
            }
            else
            {
              pPartition = (CPartitionInfo *)(pNewHalf->m_iPartition + 12 * (i - pNewHalf->m_WUs.m_Tail));
            }
            pPartition->m_iWorker = *(_DWORD *)v48;
            v50 = CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::AllocInternal(
                    this: (CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *)(v48 + 8),
                    multilist: false);
            v51 = v50;
            if ( v50 == -1 )
            {
              v51 = -1;
            }
            else
            {
              CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
                this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)(v48 + 8),
                elem: v50);
              v52 = *(_DWORD *)(v48 + 8);
              v53 = 16 * v51;
              *(_DWORD *)(v52 + v53 + 12) = -1;
              v54 = *(_DWORD *)(v48 + 24);
              *(_DWORD *)(v52 + v53 + 8) = v54;
              *(_DWORD *)(v48 + 24) = v51;
              if ( v54 == -1 )
                *(_DWORD *)(v48 + 20) = v51;
              else
                *(_DWORD *)(*(_DWORD *)(v48 + 8) + 16 * v54 + 12) = v51;
              ++*(_DWORD *)(v48 + 32);
              v55 = (int *)(v53 + *(_DWORD *)(v48 + 8));
              if ( v55 != nullptr )
              {
                *v55 = i;
                v55[1] = HIDWORD(v47);
              }
            }
            pPartition->m_WUs.m_Memory.m_pMemory = (UtlLinkedListElem_t<unsigned __int64,int> *)v51;
            v56 = v78;
            v57 = CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::AllocInternal(
                    this: &v78->m_WUInfo,
                    multilist: false);
            v58 = v57;
            if ( v57 == -1 )
            {
              v58 = -1;
            }
            else
            {
              CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
                this: &v56->m_WUInfo,
                elem: v57);
              v59 = v56->m_WUInfo.m_Memory.m_pMemory;
              v60 = v58;
              v59[v60].m_Next = -1;
              v61 = v56->m_WUInfo.m_Tail;
              v59[v60].m_Previous = v61;
              v56->m_WUInfo.m_Tail = v58;
              if ( v61 == -1 )
                v56->m_WUInfo.m_Head = v58;
              else
                v56->m_WUInfo.m_Memory.m_pMemory[v61].m_Next = v58;
              ++v56->m_WUInfo.m_ElementCount;
              v62 = &v56->m_WUInfo.m_Memory.m_pMemory[v60];
              if ( v62 != nullptr )
              {
                LODWORD(v62->m_Element.m_iWorkUnit) = i;
                HIDWORD(v62->m_Element.m_iWorkUnit) = HIDWORD(v47);
              }
            }
            v63 = i++;
            pPartition->m_iPartition = v58;
            HIDWORD(v47) = (__PAIR64__(HIDWORD(v47), v63) + 1) >> 32;
          }
          while ( __PAIR64__(HIDWORD(v47), i) < iEnda );
        }
        v64 = (void *)iOldWorker;
        CDistributor_DefaultMaster::SendPartitionToWorker(
          this: v78,
          pPartition: *(CPartitionInfo **)iOldWorker,
          iWorker);
        free(pMem: v64);
        free(pMem: nullptr);
      }
    }
    else
    {
      v33 = v3->m_Partitions.m_Memory.m_pMemory;
      while ( v33[m_Next].m_Element->m_iWorker != -1 )
      {
        m_Next = v33[m_Next].m_Next;
        if ( m_Next == -1 )
          goto LABEL_45;
      }
      v40 = v33[m_Next].m_Element;
      v40->m_iWorker = iWorker;
      CDistributor_DefaultMaster::SendPartitionToWorker(this: v3, pPartition: v40, iWorker);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100264E0
// Name: public: virtual void CDistributor_DefaultMaster::OnWorkerReady(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::OnWorkerReady(CDistributor_DefaultMaster *this, int iSource)
{
  CDistributor_DefaultMaster::AssignWUsToWorker(this, iWorker: iSource);
}

//------------------------------------------------------------------------------
// Address: 0x100264F0
// Name: public: virtual bool CDistributor_DefaultMaster::HandleWorkUnitResults(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_DefaultMaster::HandleWorkUnitResults(
        CDistributor_DefaultMaster *this,
        unsigned __int64 iWorkUnit)
{
  CVisibleWindowVector<CWULookupInfo> *p_m_WULookup; // edi
  int *p_m_iWUInfo; // ebx
  UtlLinkedListElem_t<CPartitionInfo *,int> *m_pMemory; // edx
  int v6; // esi
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *p_m_WUs; // ebx
  unsigned int v8; // ecx
  CDistributor_DefaultMaster *v9; // esi
  unsigned int v10; // eax
  unsigned int v11; // edx
  CWULookupInfo *v12; // esi
  void *v13; // edi
  __int64 v14; // rax
  unsigned __int64 v16; // [esp+14h] [ebp-18h]
  int iPartition; // [esp+20h] [ebp-Ch]
  int iPartitionWorker; // [esp+24h] [ebp-8h]
  int iPartitionWorkera; // [esp+24h] [ebp-8h]
  int iPartitionWorkerb; // [esp+24h] [ebp-8h]

  if ( iWorkUnit < this->m_WULookup.m_uiBase )
    return 0;
  p_m_WULookup = &this->m_WULookup;
  if ( iWorkUnit >= this->m_WULookup.m_uiBase + this->m_WULookup.m_Size )
    return 0;
  if ( iWorkUnit < this->m_WULookup.m_uiBase )
    return 0;
  p_m_iWUInfo = &p_m_WULookup->m_Memory.m_pMemory[iWorkUnit - LODWORD(this->m_WULookup.m_uiBase)].m_iWUInfo;
  if ( p_m_iWUInfo == nullptr )
    return 0;
  iPartitionWorker = *p_m_iWUInfo;
  if ( *p_m_iWUInfo == -1 )
    return 0;
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
    this: &this->m_WUInfo,
    elem: *p_m_iWUInfo);
  this->m_WUInfo.m_Memory.m_pMemory[iPartitionWorker].m_Next = this->m_WUInfo.m_FirstFree;
  this->m_WUInfo.m_FirstFree = iPartitionWorker;
  iPartition = p_m_iWUInfo[1];
  *p_m_iWUInfo = -1;
  m_pMemory = this->m_Partitions.m_Memory.m_pMemory;
  v6 = p_m_iWUInfo[2];
  p_m_WUs = (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&m_pMemory[iPartition].m_Element->m_WUs;
  iPartitionWorkera = (int)m_pMemory[iPartition].m_Element;
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
    this: p_m_WUs,
    elem: v6);
  p_m_WUs->m_Memory.m_pMemory[v6].m_Next = p_m_WUs->m_FirstFree;
  v8 = iWorkUnit;
  p_m_WUs->m_FirstFree = v6;
  v9 = this;
  if ( iWorkUnit == this->m_WULookup.m_uiBase )
  {
    v16 = p_m_WULookup->m_uiBase + p_m_WULookup->m_Size;
    v10 = HIDWORD(v16);
    if ( iWorkUnit >= v16 )
    {
      v11 = HIDWORD(iWorkUnit);
    }
    else
    {
      v11 = HIDWORD(iWorkUnit);
      do
      {
        if ( __PAIR64__(v11, v8) < p_m_WULookup->m_uiBase || v11 > v10 || v11 >= v10 && v8 >= (unsigned int)v16 )
        {
          v12 = nullptr;
        }
        else
        {
          v12 = &p_m_WULookup->m_Memory.m_pMemory[v8 - LODWORD(p_m_WULookup->m_uiBase)];
          v10 = HIDWORD(v16);
        }
        if ( v12->m_iWUInfo != -1 && __PAIR64__(v11, v8) > iWorkUnit )
          break;
        v11 = (__PAIR64__(v11, v8++) + 1) >> 32;
      }
      while ( __PAIR64__(v11, v8) < __PAIR64__(v10, v16) );
    }
    CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo>>::ShrinkWindow(
      this: p_m_WULookup,
      idxDrop: __PAIR64__(v11, v8) - 1);
    v9 = this;
  }
  v13 = (void *)iPartitionWorkera;
  if ( *(_DWORD *)(iPartitionWorkera + 32) == 0 )
  {
    iPartitionWorkerb = *(_DWORD *)(iPartitionWorkera + 4);
    CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::RemoveAll(this: p_m_WUs);
    if ( p_m_WUs->m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_WUs->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_WUs->m_Memory.m_pMemory);
        p_m_WUs->m_Memory.m_pMemory = nullptr;
      }
      p_m_WUs->m_Memory.m_nAllocationCount = 0;
    }
    free(pMem: v13);
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&v9->m_Partitions,
      elem: iPartition);
    v9->m_Partitions.m_Memory.m_pMemory[iPartition].m_Next = v9->m_Partitions.m_FirstFree;
    v9->m_Partitions.m_FirstFree = iPartition;
    if ( v9->m_WULookup.m_uiBase < v9->m_WULookup.m_uiTotal )
      CDistributor_DefaultMaster::AssignWUsToWorker(this: v9, iWorker: iPartitionWorkerb);
  }
  LODWORD(v14) = CWorkUnitsTracker::WorkUnitFinished(this: &g_MasterWorkUnitsTracker, iWorkUnit);
  if ( v14 != 0 && g_pDistributeWorkCallbacks != nullptr )
    ((void (__thiscall *)(IWorkUnitDistributorCallbacks *, _DWORD, _DWORD))g_pDistributeWorkCallbacks->OnWorkUnitsCompleted)(
      a1: g_pDistributeWorkCallbacks,
      a2: v14,
      a3: HIDWORD(v14));
  return 1;
}

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10017220
// Name: public: virtual void CDistributor_DefaultWorker::NoteLocalWorkUnitCompleted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultWorker::NoteLocalWorkUnitCompleted(
        CDistributor_DefaultWorker *this,
        unsigned __int64 iWU)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10017440
// Name: public: void CWorkUnitsTracker::PrepareForWorkUnits(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkUnitsTracker::PrepareForWorkUnits(CWorkUnitsTracker *this, unsigned __int64 numUnits)
{
  int v2; // ebx

  v2 = HIDWORD(numUnits);
  CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::Reset(
    this: &this->m_arrInfo,
    uiTotal: numUnits + 1);
  if ( (v2 | (unsigned int)numUnits) != 0 )
  {
    HIBYTE(numUnits) = 0;
    CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ExpandWindow(
      this: &this->m_arrInfo,
      idxAccessible: 2u,
      x: (const unsigned __int8 *)&numUnits + 7);
    if ( HIDWORD(this->m_arrInfo.m_uiBase) != 0 || LODWORD(this->m_arrInfo.m_uiBase) != 0 || this->m_arrInfo.m_Size == 0 )
      MEMORY[0] = 1;
    else
      *this->m_arrInfo.m_Memory.m_pMemory = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100174C0
// Name: public: unsigned __int64 CWorkUnitsTracker::WorkUnitFinished(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWorkUnitsTracker::WorkUnitFinished(CWorkUnitsTracker *this, unsigned __int64 iWorkUnit)
{
  __int64 v2; // rcx
  unsigned int v4; // esi
  unsigned __int8 *v5; // eax
  unsigned __int8 v6; // cl
  unsigned __int64 v7; // rax
  unsigned int v8; // kr00_4
  unsigned __int8 *v9; // eax
  bool v10; // zf
  unsigned __int8 *v11; // eax
  unsigned int v13; // kr10_4
  unsigned __int8 *v14; // eax
  unsigned __int64 v15; // [esp-Ch] [ebp-1Ch]

  HIDWORD(v2) = HIDWORD(iWorkUnit);
  if ( HIDWORD(iWorkUnit) < HIDWORD(this->m_arrInfo.m_uiBase) )
    return 0;
  v4 = iWorkUnit;
  if ( HIDWORD(iWorkUnit) <= HIDWORD(this->m_arrInfo.m_uiBase)
    && (unsigned int)iWorkUnit < LODWORD(this->m_arrInfo.m_uiBase) )
  {
    return 0;
  }
  if ( iWorkUnit >= this->m_arrInfo.m_uiTotal )
    return 0;
  LODWORD(v2) = iWorkUnit;
  HIBYTE(iWorkUnit) = 0;
  CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ExpandWindow(
    this: &this->m_arrInfo,
    idxAccessible: v2 + 1,
    x: (const unsigned __int8 *)&iWorkUnit + 7);
  if ( __PAIR64__(HIDWORD(v2), iWorkUnit) < this->m_arrInfo.m_uiBase
    || __PAIR64__(HIDWORD(v2), iWorkUnit) >= this->m_arrInfo.m_uiBase + this->m_arrInfo.m_Size )
  {
    v5 = nullptr;
  }
  else
  {
    v5 = &this->m_arrInfo.m_Memory.m_pMemory[iWorkUnit - LODWORD(this->m_arrInfo.m_uiBase)];
  }
  v6 = *v5;
  *v5 = 2;
  if ( v6 != 1 )
  {
    if ( __PAIR64__(HIDWORD(v2), iWorkUnit) == this->m_arrInfo.m_uiBase )
    {
      do
      {
        v13 = v4 + 1;
        HIDWORD(v2) = (__PAIR64__(HIDWORD(v2), v4) + 1) >> 32;
        v4 = v13;
        if ( __PAIR64__(HIDWORD(v2), v13) >= this->m_arrInfo.m_uiBase + this->m_arrInfo.m_Size )
          break;
        v14 = __PAIR64__(HIDWORD(v2), v13) < this->m_arrInfo.m_uiBase
            ? nullptr
            : &this->m_arrInfo.m_Memory.m_pMemory[v13 - LODWORD(this->m_arrInfo.m_uiBase)];
      }
      while ( *v14 == 2 );
      CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ShrinkWindow(
        this: &this->m_arrInfo,
        idxDrop: __PAIR64__(HIDWORD(v2), v13) - 1);
    }
    return 0;
  }
  LODWORD(v2) = HIDWORD(this->m_arrInfo.m_uiBase);
  v7 = this->m_arrInfo.m_uiBase + this->m_arrInfo.m_Size;
  do
  {
    v8 = v4 + 1;
    HIDWORD(v2) = (__PAIR64__(HIDWORD(v2), v4) + 1) >> 32;
    v4 = v8;
    if ( __PAIR64__(HIDWORD(v2), v8) >= v7 )
      break;
    v9 = __PAIR64__(HIDWORD(v2), v8) < this->m_arrInfo.m_uiBase
       ? nullptr
       : &this->m_arrInfo.m_Memory.m_pMemory[v8 - LODWORD(this->m_arrInfo.m_uiBase)];
    v10 = *v9 == 2;
    LODWORD(v7) = LODWORD(this->m_arrInfo.m_uiBase) + this->m_arrInfo.m_Size;
  }
  while ( v10 );
  if ( HIDWORD(v2) < (unsigned int)v2
    || HIDWORD(v2) <= (unsigned int)v2 && v8 < LODWORD(this->m_arrInfo.m_uiBase)
    || __PAIR64__(HIDWORD(v2), v8) >= v7 )
  {
    v11 = nullptr;
  }
  else
  {
    v11 = &this->m_arrInfo.m_Memory.m_pMemory[v8 - LODWORD(this->m_arrInfo.m_uiBase)];
  }
  *v11 = 1;
  HIDWORD(v15) = (v8 != 0) + HIDWORD(v2) - 1;
  LODWORD(v15) = v8 - 1;
  CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ShrinkWindow(
    this: &this->m_arrInfo,
    idxDrop: v15);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10017640
// Name: class IWorkUnitDistributorWorker __near * CreateWUDistributor_DefaultWorker(void)
// Source: json
//------------------------------------------------------------------------------
IWorkUnitDistributorWorker *__cdecl CreateWUDistributor_DefaultWorker()
{
  char *v0; // eax
  _DWORD *v1; // esi
  int v2; // eax

  v0 = (char *)operator new(nSize: 0x84u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *(_DWORD *)v0 = &CDistributor_DefaultWorker::`vftable';
  CCriticalSection::CCriticalSection(this: (CCriticalSection *)(v0 + 4));
  v1[23] = 0;
  v1[24] = 0;
  v1[25] = 0;
  v1[31] = -1;
  v1[26] = -1;
  v1[27] = -1;
  v1[28] = -1;
  v2 = v1[23];
  v1[29] = 0;
  v1[30] = 0;
  v1[32] = v2;
  return (IWorkUnitDistributorWorker *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x100176A0
// Name: public: virtual void CDistributor_DefaultWorker::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultWorker::Release(CDistributor_DefaultWorker *this)
{
  if ( this != nullptr )
  {
    CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::RemoveAll(this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&this->m_WorkUnits);
    if ( this->m_WorkUnits.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_WorkUnits.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WorkUnits.m_Memory.m_pMemory);
        this->m_WorkUnits.m_Memory.m_pMemory = nullptr;
      }
      this->m_WorkUnits.m_Memory.m_nAllocationCount = 0;
    }
    CCriticalSection::~CCriticalSection(this: &this->m_CS);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100176F0
// Name: public: virtual bool CDistributor_DefaultWorker::GetNextWorkUnit(unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_DefaultWorker::GetNextWorkUnit(
        CDistributor_DefaultWorker *this,
        unsigned __int64 *pWUIndex)
{
  UtlLinkedListElem_t<unsigned __int64,int> *m_pMemory; // ecx
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *p_m_WorkUnits; // esi
  int m_Head; // eax
  int v7; // edi
  CCriticalSectionLock csLock; // [esp+4h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  if ( this->m_WorkUnits.m_ElementCount != 0 )
  {
    m_pMemory = this->m_WorkUnits.m_Memory.m_pMemory;
    p_m_WorkUnits = (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&this->m_WorkUnits;
    m_Head = this->m_WorkUnits.m_Head;
    *(_DWORD *)pWUIndex = m_pMemory[this->m_WorkUnits.m_Head].m_Element;
    *((_DWORD *)pWUIndex + 1) = HIDWORD(m_pMemory[m_Head].m_Element);
    v7 = this->m_WorkUnits.m_Head;
    CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
      this: p_m_WorkUnits,
      elem: v7);
    p_m_WorkUnits->m_Memory.m_pMemory[v7].m_Next = p_m_WorkUnits->m_FirstFree;
    p_m_WorkUnits->m_FirstFree = v7;
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 1;
  }
  else
  {
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017770
// Name: public: CDistributor_DefaultMaster::CDistributor_DefaultMaster(void)
// Source: json
//------------------------------------------------------------------------------
CDistributor_DefaultMaster *__thiscall CDistributor_DefaultMaster::CDistributor_DefaultMaster(
        CDistributor_DefaultMaster *this)
{
  CDistributor_DefaultMaster *result; // eax
  UtlLinkedListElem_t<CWorkUnitInfo,int> *m_pMemory; // ecx

  result = this;
  this->__vftable = (CDistributor_DefaultMaster_vtbl *)&CDistributor_DefaultMaster::`vftable';
  this->m_Partitions.m_Memory.m_pMemory = nullptr;
  this->m_Partitions.m_Memory.m_nAllocationCount = 0;
  this->m_Partitions.m_Memory.m_nGrowSize = 0;
  this->m_Partitions.m_LastAlloc.index = -1;
  this->m_Partitions.m_Head = -1;
  this->m_Partitions.m_Tail = -1;
  this->m_Partitions.m_FirstFree = -1;
  this->m_Partitions.m_ElementCount = 0;
  this->m_Partitions.m_NumAlloced = 0;
  this->m_Partitions.m_pElements = this->m_Partitions.m_Memory.m_pMemory;
  this->m_WULookup.m_Memory.m_pMemory = nullptr;
  this->m_WULookup.m_Memory.m_nAllocationCount = 0;
  this->m_WULookup.m_Memory.m_nGrowSize = 0;
  this->m_WULookup.m_Size = 0;
  this->m_WULookup.m_pElements = nullptr;
  this->m_WULookup.m_uiBase = 0;
  this->m_WULookup.m_uiTotal = 0;
  this->m_WUInfo.m_Memory.m_pMemory = nullptr;
  this->m_WUInfo.m_Memory.m_nAllocationCount = 0;
  this->m_WUInfo.m_Memory.m_nGrowSize = 0;
  this->m_WUInfo.m_LastAlloc.index = -1;
  this->m_WUInfo.m_ElementCount = 0;
  this->m_WUInfo.m_NumAlloced = 0;
  m_pMemory = this->m_WUInfo.m_Memory.m_pMemory;
  result->m_WUInfo.m_Head = -1;
  result->m_WUInfo.m_Tail = -1;
  result->m_WUInfo.m_FirstFree = -1;
  result->m_WUInfo.m_pElements = m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100177E0
// Name: public: virtual bool CDistributor_DefaultMaster::HandlePacket(class MessageBuffer __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDistributor_DefaultMaster::HandlePacket(
        CDistributor_DefaultMaster *this,
        MessageBuffer *pBuf,
        MessageBuffer *iSource,
        bool bIgnoreContents)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100177F0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017FB0
// Name: CompareSoonestWorkUnitSets
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CompareSoonestWorkUnitSets(
        CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *const *x,
        CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *const *y)
{
  int *v2; // edx
  int m_Head; // eax
  unsigned int v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // ebx
  int v7; // ecx
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  unsigned __int64 jobsX[4]; // [esp+Ch] [ebp-40h] BYREF
  unsigned __int64 jobsY[4]; // [esp+2Ch] [ebp-20h] BYREF

  v2 = (int *)*x;
  m_Head = (*x)->m_Head;
  v4 = -1;
  v5 = -1;
  v6 = -1;
  v7 = 0;
  memset(jobsX, 255, 16);
  jobsX[3] = -1;
  memset(jobsY, 255, 16);
  jobsY[3] = -1;
  if ( m_Head != -1 )
  {
    v8 = *v2;
    do
    {
      v9 = 2 * m_Head;
      LODWORD(jobsX[v7]) = *(_DWORD *)(v8 + 8 * v9);
      HIDWORD(jobsX[v7++]) = *(_DWORD *)(v8 + 8 * v9 + 4);
      if ( v7 >= 4 )
        break;
      m_Head = *(_DWORD *)(v8 + 8 * v9 + 12);
    }
    while ( m_Head != -1 );
    v5 = HIDWORD(jobsX[3]);
  }
  v10 = (*y)->m_Head;
  v11 = 0;
  if ( v10 != -1 )
  {
    v12 = **(_DWORD **)y;
    do
    {
      v13 = 2 * v10;
      LODWORD(jobsY[v11]) = *(_DWORD *)(v12 + 8 * v13);
      HIDWORD(jobsY[v11++]) = *(_DWORD *)(v12 + 8 * v13 + 4);
      if ( v11 >= 4 )
        break;
      v10 = *(_DWORD *)(v12 + 8 * v13 + 12);
    }
    while ( v10 != -1 );
    v4 = HIDWORD(jobsY[3]);
    v6 = jobsY[3];
  }
  if ( LODWORD(jobsX[3]) != v6 || v5 != v4 )
  {
    if ( v5 > v4 )
      return false;
    if ( v5 >= v4 )
      return LODWORD(jobsX[3]) < v6;
    return true;
  }
  if ( jobsX[1] == jobsY[1] )
  {
    if ( HIDWORD(jobsX[0]) > HIDWORD(jobsY[0]) )
      return false;
    if ( HIDWORD(jobsX[0]) < HIDWORD(jobsY[0]) )
      return true;
    return LODWORD(jobsX[0]) < LODWORD(jobsY[0]);
  }
  else
  {
    if ( HIDWORD(jobsX[1]) > HIDWORD(jobsY[1]) )
      return false;
    if ( HIDWORD(jobsX[1]) < HIDWORD(jobsY[1]) )
      return true;
    return LODWORD(jobsX[1]) < LODWORD(jobsY[1]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100180C0
// Name: public: void CDistributor_DefaultMaster::SendPartitionToWorker(class CPartitionInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::SendPartitionToWorker(
        CDistributor_DefaultMaster *this,
        CPartitionInfo *pPartition,
        int iWorker)
{
  int m_Head; // esi
  UtlLinkedListElem_t<unsigned __int64,int> *m_pMemory; // eax
  int v5; // esi
  int Name; // eax
  MessageBuffer mb; // [esp+Ch] [ebp-18h] BYREF
  unsigned __int64 iWU; // [esp+1Ch] [ebp-8h] BYREF

  MessageBuffer::MessageBuffer(this: &mb);
  PrepareDistributeWorkHeader(pBuf: &mb, cSubpacketID: 0x32u);
  m_Head = pPartition->m_WUs.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = pPartition->m_WUs.m_Memory.m_pMemory;
    do
    {
      v5 = m_Head;
      iWU = m_pMemory[v5].m_Element;
      MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&iWU, bytes: 8u);
      VMPITracker_WorkUnitSentToWorker(iWorkUnit: iWU, iWorker);
      m_pMemory = pPartition->m_WUs.m_Memory.m_pMemory;
      m_Head = m_pMemory[v5].m_Next;
    }
    while ( m_Head != -1 );
  }
  Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  VMPI_SendData(pData: mb.data, nBytes: Name, iDest: iWorker, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x10018B30
// Name: public: virtual void CDistributor_DefaultMaster::DisconnectHandler(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::DisconnectHandler(CDistributor_DefaultMaster *this, int workerID)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CPartitionInfo *,int> *m_pMemory; // edx

  m_Head = this->m_Partitions.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_Partitions.m_Memory.m_pMemory;
    while ( m_pMemory[m_Head].m_Element->m_iWorker != workerID )
    {
      m_Head = m_pMemory[m_Head].m_Next;
      if ( m_Head == -1 )
        return;
    }
    m_pMemory[m_Head].m_Element->m_iWorker = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018B80
// Name: public: virtual void CDistributor_DefaultMaster::DistributeWork_Master(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::DistributeWork_Master(CDistributor_DefaultMaster *this, CDSInfo *pInfo)
{
  this->m_pInfo = pInfo;
  CWorkUnitsTracker::PrepareForWorkUnits(this: &g_MasterWorkUnitsTracker, numUnits: pInfo->m_nWorkUnits);
  CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo>>::Reset(
    this: &this->m_WULookup,
    uiTotal: pInfo->m_nWorkUnits);
  if ( this->m_WULookup.m_uiBase < this->m_WULookup.m_uiTotal )
  {
    do
    {
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xC8);
      VMPITracker_HandleDebugKeypresses();
    }
    while ( (g_pDistributeWorkCallbacks == nullptr
          || g_pDistributeWorkCallbacks->Update(this: g_pDistributeWorkCallbacks) == 0)
         && this->m_WULookup.m_uiBase < this->m_WULookup.m_uiTotal );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018CA0
// Name: public: CDistributor_DefaultMaster::~CDistributor_DefaultMaster(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::~CDistributor_DefaultMaster(CDistributor_DefaultMaster *this)
{
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::RemoveAll(this: &this->m_WUInfo);
  if ( this->m_WUInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_WUInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WUInfo.m_Memory.m_pMemory);
      this->m_WUInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_WUInfo.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>::~CUtlVector<CMasterMulticastThread::CChunkInfo,CUtlMemory<CMasterMulticastThread::CChunkInfo,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_WULookup);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_Partitions);
  if ( this->m_Partitions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Partitions.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Partitions.m_Memory.m_pMemory);
      this->m_Partitions.m_Memory.m_pMemory = nullptr;
    }
    this->m_Partitions.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018E00
// Name: public: class CPartitionInfo __near * CDistributor_DefaultMaster::AddPartition(int)
// Source: json
//------------------------------------------------------------------------------
CPartitionInfo *__thiscall CDistributor_DefaultMaster::AddPartition(CDistributor_DefaultMaster *this, int iWorker)
{
  CPartitionInfo *v3; // eax
  CPartitionInfo *v4; // esi
  UtlLinkedListElem_t<unsigned __int64,int> *m_pMemory; // ecx
  CPartitionInfo *pNew; // [esp+8h] [ebp-4h] BYREF

  v3 = (CPartitionInfo *)operator new(nSize: 0x30u);
  v4 = nullptr;
  if ( v3 != nullptr )
  {
    v3->m_WUs.m_Memory.m_pMemory = nullptr;
    v3->m_WUs.m_Memory.m_nAllocationCount = 0;
    v3->m_WUs.m_Memory.m_nGrowSize = 0;
    v3->m_WUs.m_LastAlloc.index = -1;
    v3->m_WUs.m_Head = -1;
    v3->m_WUs.m_Tail = -1;
    v3->m_WUs.m_FirstFree = -1;
    m_pMemory = v3->m_WUs.m_Memory.m_pMemory;
    v3->m_WUs.m_ElementCount = 0;
    v3->m_WUs.m_NumAlloced = 0;
    v3->m_WUs.m_pElements = m_pMemory;
    v4 = v3;
  }
  pNew = v4;
  v4->m_iPartition = CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::AddToTail(
                       this: &this->m_Partitions,
                       src: &pNew);
  v4->m_iWorker = iWorker;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10018E60
// Name: public: bool CDistributor_DefaultMaster::SplitWUsPartition(class CPartitionInfo __near *,class CPartitionInfo __near * __near *,class CPartitionInfo __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_DefaultMaster::SplitWUsPartition(
        CDistributor_DefaultMaster *this,
        CPartitionInfo *pPartitionLarge,
        CPartitionInfo **ppFirstHalf,
        CPartitionInfo **ppSecondHalf,
        CPartitionInfo *iFirstHalfWorker,
        int iSecondHalfWorker)
{
  int m_ElementCount; // eax
  CDistributor_DefaultMaster *v8; // ebx
  CPartitionInfo *v9; // eax
  int m_Head; // esi
  UtlLinkedListElem_t<unsigned __int64,int> *m_pMemory; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  unsigned int m_uiBase_high; // ecx
  unsigned int m_uiBase; // esi
  int v16; // eax
  int v17; // ebx
  UtlLinkedListElem_t<unsigned __int64,int> *v18; // eax
  int v19; // edx
  int m_Tail; // ecx
  UtlLinkedListElem_t<unsigned __int64,int> *v21; // esi
  CPartitionInfo *arrNewParts[2]; // [esp+Ch] [ebp-14h]
  unsigned __int64 iWU; // [esp+14h] [ebp-Ch]
  CDistributor_DefaultMaster *v25; // [esp+1Ch] [ebp-4h]
  int nCount; // [esp+28h] [ebp+8h]
  int iHead; // [esp+2Ch] [ebp+Ch]
  CPartitionInfo *pTo; // [esp+34h] [ebp+14h]
  int k; // [esp+38h] [ebp+18h]

  m_ElementCount = pPartitionLarge->m_WUs.m_ElementCount;
  v8 = this;
  v25 = this;
  nCount = m_ElementCount;
  if ( m_ElementCount <= 1 )
  {
    *ppFirstHalf = nullptr;
    v9 = CDistributor_DefaultMaster::AddPartition(this, iWorker: iSecondHalfWorker);
  }
  else
  {
    *ppFirstHalf = CDistributor_DefaultMaster::AddPartition(this, iWorker: (int)iFirstHalfWorker);
    v9 = CDistributor_DefaultMaster::AddPartition(this: v8, iWorker: iSecondHalfWorker);
  }
  *ppSecondHalf = v9;
  if ( *ppFirstHalf != nullptr )
    arrNewParts[0] = *ppFirstHalf;
  else
    arrNewParts[0] = *ppSecondHalf;
  arrNewParts[1] = *ppSecondHalf;
  k = 0;
  if ( nCount > 0 )
  {
    while ( 1 )
    {
      m_Head = pPartitionLarge->m_WUs.m_Head;
      iWU = pPartitionLarge->m_WUs.m_Memory.m_pMemory[m_Head].m_Element;
      if ( m_Head >= 0
        && m_Head < pPartitionLarge->m_WUs.m_Memory.m_nAllocationCount
        && m_Head <= pPartitionLarge->m_WUs.m_LastAlloc.index )
      {
        m_pMemory = pPartitionLarge->m_WUs.m_Memory.m_pMemory;
        if ( m_pMemory[m_Head].m_Previous != m_Head )
        {
          m_Previous = m_pMemory[m_Head].m_Previous;
          if ( m_Previous == -1 )
          {
            pPartitionLarge->m_WUs.m_Head = m_pMemory[m_Head].m_Next;
          }
          else
          {
            m_pMemory[m_Previous].m_Next = m_pMemory[m_Head].m_Next;
            v8 = v25;
          }
          m_Next = m_pMemory[m_Head].m_Next;
          if ( m_Next == -1 )
          {
            pPartitionLarge->m_WUs.m_Tail = m_pMemory[m_Head].m_Previous;
          }
          else
          {
            pPartitionLarge->m_WUs.m_Memory.m_pMemory[m_Next].m_Previous = m_pMemory[m_Head].m_Previous;
            v8 = v25;
          }
          m_pMemory[m_Head].m_Next = m_Head;
          m_pMemory[m_Head].m_Previous = m_Head;
          --pPartitionLarge->m_WUs.m_ElementCount;
        }
      }
      pPartitionLarge->m_WUs.m_Memory.m_pMemory[m_Head].m_Next = pPartitionLarge->m_WUs.m_FirstFree;
      pPartitionLarge->m_WUs.m_FirstFree = m_Head;
      m_uiBase_high = HIDWORD(v8->m_WULookup.m_uiBase);
      m_uiBase = v8->m_WULookup.m_uiBase;
      pTo = arrNewParts[k >= nCount / 2];
      if ( iWU < __PAIR64__(m_uiBase_high, m_uiBase)
        || iWU >= __PAIR64__(m_uiBase_high, m_uiBase) + v8->m_WULookup.m_Size )
      {
        iHead = 0;
      }
      else
      {
        iHead = (int)&v8->m_WULookup.m_Memory.m_pMemory[iWU - m_uiBase];
      }
      *(_DWORD *)(iHead + 4) = pTo->m_iPartition;
      v16 = CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::AllocInternal(
              this: &pTo->m_WUs,
              multilist: false);
      v17 = v16;
      if ( v16 == -1 )
      {
        v17 = -1;
      }
      else
      {
        CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
          this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&pTo->m_WUs,
          elem: v16);
        v18 = pTo->m_WUs.m_Memory.m_pMemory;
        v19 = v17;
        v18[v19].m_Next = -1;
        m_Tail = pTo->m_WUs.m_Tail;
        v18[v19].m_Previous = m_Tail;
        pTo->m_WUs.m_Tail = v17;
        if ( m_Tail == -1 )
          pTo->m_WUs.m_Head = v17;
        else
          pTo->m_WUs.m_Memory.m_pMemory[m_Tail].m_Next = v17;
        ++pTo->m_WUs.m_ElementCount;
        v21 = &pTo->m_WUs.m_Memory.m_pMemory[v19];
        if ( v21 != nullptr )
          v21->m_Element = iWU;
      }
      *(_DWORD *)(iHead + 8) = v17;
      if ( ++k >= nCount )
        break;
      v8 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10019060
// Name: public: virtual bool CDistributor_DefaultWorker::HandlePacket(class MessageBuffer __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_DefaultWorker::HandlePacket(
        CDistributor_DefaultWorker *this,
        MessageBuffer *pBuf,
        int iSource,
        bool bIgnoreContents)
{
  char Name; // bl
  CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *p_m_WorkUnits; // ebx
  int v8; // esi
  unsigned int i; // esi
  unsigned __int64 iWU; // [esp+8h] [ebp-10h] BYREF
  CCriticalSectionLock csLock; // [esp+10h] [ebp-8h] BYREF

  if ( pBuf->data[1] != 50 )
    return 0;
  if ( bIgnoreContents )
    return 1;
  Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)pBuf);
  if ( ((Name - (unsigned __int8)MessageBuffer::getOffset(this: (CVMPIFile_Memory *)pBuf)) & 7) != 0 )
    _Error(a1: "DistributeWork: invalid work units packet from master");
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  p_m_WorkUnits = &this->m_WorkUnits;
  CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::Purge(this: &this->m_WorkUnits);
  v8 = ConCommandBase::GetName(this: (CVMPIFile_Memory *)pBuf);
  for ( i = (unsigned int)(v8 - MessageBuffer::getOffset(this: (CVMPIFile_Memory *)pBuf)) >> 3; i != 0; --i )
  {
    MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&iWU, bytes: 8u);
    CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::AddToTail(
      this: p_m_WorkUnits,
      src: &iWU);
  }
  CCriticalSectionLock::Unlock(this: &csLock);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10019130
// Name: class IWorkUnitDistributorMaster __near * CreateWUDistributor_DefaultMaster(void)
// Source: json
//------------------------------------------------------------------------------
CDistributor_DefaultMaster *__cdecl CreateWUDistributor_DefaultMaster()
{
  CDistributor_DefaultMaster *v0; // eax

  v0 = (CDistributor_DefaultMaster *)operator new(nSize: 0x80u);
  if ( v0 != nullptr )
    return CDistributor_DefaultMaster::CDistributor_DefaultMaster(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10019150
// Name: public: virtual void CDistributor_DefaultMaster::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::Release(CDistributor_DefaultMaster *this)
{
  if ( this != nullptr )
  {
    CDistributor_DefaultMaster::~CDistributor_DefaultMaster(this);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019170
// Name: public: int CDistributor_DefaultMaster::FindSoonestPartition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDistributor_DefaultMaster::FindSoonestPartition(CDistributor_DefaultMaster *this)
{
  int m_ElementCount; // eax
  IMemAlloc_vtbl *v3; // edx
  int m_Head; // eax
  int v5; // edi
  CPartitionInfo *m_Element; // edx
  int v7; // ecx
  UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int v9; // esi
  CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t *p_m_Data; // esi
  unsigned __int16 Inorder; // ax
  int elem; // esi
  int v14; // ebx
  CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short> sortedPartitions; // [esp+8h] [ebp-2Ch] BYREF
  CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t insert; // [esp+24h] [ebp-10h] BYREF
  unsigned __int16 parent[3]; // [esp+2Ch] [ebp-8h] BYREF
  bool leftchild; // [esp+33h] [ebp-1h] BYREF

  m_ElementCount = this->m_Partitions.m_ElementCount;
  sortedPartitions.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *const *, CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *const *))CompareSoonestWorkUnitSets;
  memset(&sortedPartitions.m_Tree.m_Elements, 0, sizeof(sortedPartitions.m_Tree.m_Elements));
  *(_DWORD *)&sortedPartitions.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&sortedPartitions.m_Tree.m_FirstFree = -1;
  sortedPartitions.m_Tree.m_pElements = nullptr;
  if ( m_ElementCount > 0 )
  {
    v3 = _g_pMemAlloc->__vftable;
    sortedPartitions.m_Tree.m_Elements.m_nAllocationCount = m_ElementCount;
    sortedPartitions.m_Tree.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *)v3->Alloc_2(this: _g_pMemAlloc, a2: 16 * m_ElementCount);
  }
  m_Head = this->m_Partitions.m_Head;
  if ( m_Head == -1 )
    goto LABEL_17;
  do
  {
    v5 = m_Head;
    m_Element = this->m_Partitions.m_Memory.m_pMemory[m_Head].m_Element;
    insert.elem = m_Head;
    insert.key = &m_Element->m_WUs;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &sortedPartitions.m_Tree,
      &insert,
      parent,
      &leftchild);
    v7 = (unsigned __int16)CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &sortedPartitions.m_Tree);
    m_pMemory = sortedPartitions.m_Tree.m_Elements.m_pMemory;
    v9 = v7;
    sortedPartitions.m_Tree.m_Elements.m_pMemory[v9].m_Parent = parent[0];
    m_pMemory[v9].m_Right = -1;
    m_pMemory[v9].m_Left = -1;
    m_pMemory[v9].m_Tag = 0;
    if ( parent[0] == 0xFFFF )
    {
      sortedPartitions.m_Tree.m_Root = v7;
    }
    else if ( leftchild )
    {
      m_pMemory[parent[0]].m_Left = v7;
    }
    else
    {
      m_pMemory[parent[0]].m_Right = v7;
    }
    CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &sortedPartitions.m_Tree,
      elem: v7);
    ++sortedPartitions.m_Tree.m_NumElements;
    p_m_Data = &sortedPartitions.m_Tree.m_Elements.m_pMemory[v9].m_Data;
    if ( p_m_Data != nullptr )
      *p_m_Data = insert;
    m_Head = this->m_Partitions.m_Memory.m_pMemory[v5].m_Next;
  }
  while ( m_Head != -1 );
  if ( sortedPartitions.m_Tree.m_NumElements == 0 )
  {
LABEL_17:
    v14 = this->m_Partitions.m_Head;
    CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &sortedPartitions.m_Tree);
    if ( sortedPartitions.m_Tree.m_Elements.m_nGrowSize >= 0 && sortedPartitions.m_Tree.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sortedPartitions.m_Tree.m_Elements.m_pMemory);
    return v14;
  }
  else
  {
    Inorder = CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &sortedPartitions.m_Tree);
    elem = sortedPartitions.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
    CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &sortedPartitions.m_Tree);
    if ( sortedPartitions.m_Tree.m_Elements.m_nGrowSize >= 0 && sortedPartitions.m_Tree.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sortedPartitions.m_Tree.m_Elements.m_pMemory);
    return elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019340
// Name: public: void CDistributor_DefaultMaster::AssignWUsToWorker(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::AssignWUsToWorker(CDistributor_DefaultMaster *this, int iWorker)
{
  int m_pMemory; // edx
  CDistributor_DefaultMaster *v3; // edi
  int m_Head; // esi
  int v5; // ecx
  int v6; // edi
  int v7; // eax
  unsigned __int64 m_nWorkUnits; // rcx
  CPartitionInfo *v9; // eax
  CDSInfo *m_pInfo; // edi
  bool v11; // zf
  unsigned __int64 v12; // kr08_8
  unsigned int m_uiBase; // edi
  CWULookupInfo *v14; // ebx
  CPartitionInfo *v15; // edi
  CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *p_m_WUs; // ecx
  int v17; // eax
  int v18; // esi
  UtlLinkedListElem_t<unsigned __int64,int> *v19; // eax
  int v20; // edx
  int m_Tail; // ecx
  UtlLinkedListElem_t<unsigned __int64,int> *v22; // edi
  CDistributor_DefaultMaster *v23; // edi
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *p_m_WUInfo; // ecx
  int v25; // eax
  int v26; // esi
  UtlLinkedListElem_t<CWorkUnitInfo,int> *v27; // eax
  int v28; // edx
  int v29; // ecx
  UtlLinkedListElem_t<CWorkUnitInfo,int> *v30; // edi
  unsigned __int64 v31; // rax
  int m_Next; // eax
  UtlLinkedListElem_t<CPartitionInfo *,int> *v33; // edx
  unsigned __int64 m_uiTotal; // rcx
  unsigned int v35; // esi
  unsigned __int64 v36; // rax
  unsigned int v37; // ebx
  unsigned int v38; // esi
  unsigned int v39; // ebx
  CPartitionInfo *v40; // eax
  CDistributor_DefaultMaster *v41; // esi
  unsigned int v42; // edi
  CPartitionInfo *v43; // eax
  UtlLinkedListElem_t<unsigned __int64,int> *v44; // ecx
  CPartitionInfo *v45; // esi
  int v46; // eax
  __int64 v47; // rcx
  int v48; // esi
  unsigned int v49; // edi
  int v50; // eax
  int v51; // edi
  int v52; // eax
  int v53; // edx
  int v54; // ecx
  int *v55; // esi
  CDistributor_DefaultMaster *v56; // edi
  int v57; // eax
  int v58; // esi
  UtlLinkedListElem_t<CWorkUnitInfo,int> *v59; // eax
  int v60; // edx
  int v61; // ecx
  UtlLinkedListElem_t<CWorkUnitInfo,int> *v62; // edi
  int v63; // kr04_4
  void *v64; // esi
  CDistributor_DefaultMaster *v65; // esi
  int SoonestPartition; // eax
  int v67; // ebx
  UtlLinkedListElem_t<CPartitionInfo *,int> *v68; // edx
  CPartitionInfo *m_Element; // edi
  unsigned int iEnd; // [esp+Ch] [ebp-30h]
  unsigned __int64 iEnda; // [esp+Ch] [ebp-30h]
  int i; // [esp+14h] [ebp-28h]
  unsigned __int64 iBegin; // [esp+1Ch] [ebp-20h]
  CPartitionInfo *pOldHalf; // [esp+28h] [ebp-14h] BYREF
  CPartitionInfo *pNewHalf; // [esp+2Ch] [ebp-10h] BYREF
  int iOldWorker; // [esp+30h] [ebp-Ch]
  CPartitionInfo *pPartition; // [esp+34h] [ebp-8h]
  CDistributor_DefaultMaster *v78; // [esp+38h] [ebp-4h]

  m_pMemory = iWorker;
  v3 = this;
  m_Head = this->m_Partitions.m_Head;
  v78 = this;
  if ( m_Head != -1 )
  {
    this = (CDistributor_DefaultMaster *)this->m_Partitions.m_Memory.m_pMemory;
    while ( *(_DWORD *)(*((_DWORD *)&this->__vftable + 3 * m_Head) + 4) != iWorker )
    {
      m_Head = (int)(&this->m_Partitions.m_Memory.m_pMemory)[3 * m_Head];
      if ( m_Head == -1 )
        goto LABEL_13;
    }
    v5 = *((_DWORD *)&this->__vftable + 3 * m_Head);
    iOldWorker = v5;
    if ( v5 != 0 )
    {
      v6 = v5;
      CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::RemoveAll(this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)(v5 + 8));
      if ( *(int *)(v6 + 16) >= 0 )
      {
        if ( *(_DWORD *)(v6 + 8) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v6 + 8));
          *(_DWORD *)(v6 + 8) = 0;
        }
        *(_DWORD *)(v6 + 12) = 0;
      }
      free(pMem: (void *)iOldWorker);
      v3 = v78;
    }
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&v3->m_Partitions,
      elem: m_Head);
    m_pMemory = (int)v3->m_Partitions.m_Memory.m_pMemory;
    *(_DWORD *)(12 * m_Head + m_pMemory + 8) = v3->m_Partitions.m_FirstFree;
    v3->m_Partitions.m_FirstFree = m_Head;
  }
LABEL_13:
  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "A");
  v7 = _CommandLine(a1: this, a2: m_pMemory);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-mpi_NoScheduler") != 0 )
  {
    _Warning(a1: "\n\n-mpi_NoScheduler found: Warning - this should only be used for testing and with 1 worker!\n\n");
    m_nWorkUnits = v3->m_pInfo->m_nWorkUnits;
    if ( m_nWorkUnits >= v3->m_WULookup.m_uiBase + v3->m_WULookup.m_Size )
      CUtlVector<CWULookupInfo,CUtlMemory<CWULookupInfo,int>>::InsertMultipleBefore(
        this: &v3->m_WULookup,
        elem: v3->m_WULookup.m_Size,
        num: m_nWorkUnits - LODWORD(v3->m_WULookup.m_uiBase) - v3->m_WULookup.m_Size + 1);
    v9 = CDistributor_DefaultMaster::AddPartition(this: v3, iWorker);
    m_pInfo = v3->m_pInfo;
    v11 = HIDWORD(m_pInfo->m_nWorkUnits) == 0;
    pPartition = v9;
    iOldWorker = 0;
    if ( !v11 || LODWORD(m_pInfo->m_nWorkUnits) != 0 )
    {
      v12 = 0;
      do
      {
        m_uiBase = v78->m_WULookup.m_uiBase;
        pOldHalf = (CPartitionInfo *)HIDWORD(v78->m_WULookup.m_uiBase);
        if ( v12 < __PAIR64__((unsigned int)pOldHalf, m_uiBase)
          || v12 >= __PAIR64__((unsigned int)pOldHalf, m_uiBase) + v78->m_WULookup.m_Size )
        {
          v14 = nullptr;
        }
        else
        {
          v14 = &v78->m_WULookup.m_Memory.m_pMemory[v12 - LODWORD(v78->m_WULookup.m_uiBase)];
        }
        v15 = pPartition;
        p_m_WUs = &pPartition->m_WUs;
        v14->m_iPartition = pPartition->m_iPartition;
        v17 = CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::AllocInternal(
                this: p_m_WUs,
                multilist: false);
        v18 = v17;
        if ( v17 == -1 )
        {
          v18 = -1;
        }
        else
        {
          CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
            this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&v15->m_WUs,
            elem: v17);
          v19 = v15->m_WUs.m_Memory.m_pMemory;
          v20 = v18;
          v19[v20].m_Next = -1;
          m_Tail = v15->m_WUs.m_Tail;
          v19[v20].m_Previous = m_Tail;
          v15->m_WUs.m_Tail = v18;
          if ( m_Tail == -1 )
            v15->m_WUs.m_Head = v18;
          else
            v15->m_WUs.m_Memory.m_pMemory[m_Tail].m_Next = v18;
          ++v15->m_WUs.m_ElementCount;
          v22 = &v15->m_WUs.m_Memory.m_pMemory[v20];
          if ( v22 != nullptr )
            v22->m_Element = v12;
        }
        v23 = v78;
        p_m_WUInfo = &v78->m_WUInfo;
        v14->m_iPartitionListIndex = v18;
        v25 = CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::AllocInternal(
                this: p_m_WUInfo,
                multilist: false);
        v26 = v25;
        if ( v25 == -1 )
        {
          v26 = -1;
        }
        else
        {
          CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
            this: &v23->m_WUInfo,
            elem: v25);
          v27 = v23->m_WUInfo.m_Memory.m_pMemory;
          v28 = v26;
          v27[v28].m_Next = -1;
          v29 = v23->m_WUInfo.m_Tail;
          v27[v28].m_Previous = v29;
          v23->m_WUInfo.m_Tail = v26;
          if ( v29 == -1 )
            v23->m_WUInfo.m_Head = v26;
          else
            v23->m_WUInfo.m_Memory.m_pMemory[v29].m_Next = v26;
          ++v23->m_WUInfo.m_ElementCount;
          v30 = &v23->m_WUInfo.m_Memory.m_pMemory[v28];
          if ( v30 != nullptr )
            v30->m_Element.m_iWorkUnit = v12;
        }
        v31 = ++iOldWorker;
        v14->m_iWUInfo = v26;
        v12 = v31;
      }
      while ( v31 < v78->m_pInfo->m_nWorkUnits );
    }
    CDistributor_DefaultMaster::SendPartitionToWorker(this: v78, pPartition, iWorker);
  }
  else
  {
    m_Next = v3->m_Partitions.m_Head;
    if ( m_Next == -1 )
    {
LABEL_45:
      m_uiTotal = v78->m_WULookup.m_uiTotal;
      v35 = (v78->m_WULookup.m_uiBase + v78->m_WULookup.m_Size) >> 32;
      i = LODWORD(v78->m_WULookup.m_uiBase) + v78->m_WULookup.m_Size;
      iEnd = v78->m_WULookup.m_uiTotal;
      if ( v78->m_WULookup.m_uiBase + v78->m_WULookup.m_Size >= m_uiTotal )
      {
        v65 = v78;
        SoonestPartition = CDistributor_DefaultMaster::FindSoonestPartition(this: v78);
        v67 = SoonestPartition;
        if ( SoonestPartition >= 0 )
        {
          v68 = v78->m_Partitions.m_Memory.m_pMemory;
          pPartition = (CPartitionInfo *)&v78->m_Partitions;
          m_Element = v68[SoonestPartition].m_Element;
          pOldHalf = nullptr;
          pNewHalf = nullptr;
          iOldWorker = m_Element->m_iWorker;
          if ( CDistributor_DefaultMaster::SplitWUsPartition(
                 this: v78,
                 pPartitionLarge: m_Element,
                 ppFirstHalf: &pOldHalf,
                 ppSecondHalf: &pNewHalf,
                 iFirstHalfWorker: (CPartitionInfo *)iOldWorker,
                 iSecondHalfWorker: iWorker) != 0 )
          {
            if ( pOldHalf != nullptr )
              CDistributor_DefaultMaster::SendPartitionToWorker(this: v65, pPartition: pOldHalf, iWorker: iOldWorker);
            if ( pNewHalf != nullptr )
              CDistributor_DefaultMaster::SendPartitionToWorker(this: v65, pPartition: pNewHalf, iWorker);
            CPartitionInfo::`scalar deleting destructor'(this: m_Element, a2: 1u);
            CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::Remove(
              this: (CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int> > *)pPartition,
              elem: v67);
          }
        }
      }
      else
      {
        LODWORD(m_uiTotal) = s_numWusToDeal;
        if ( s_numWusToDeal <= 0 )
        {
          LODWORD(m_uiTotal) = __PAIR64__(HIDWORD(m_uiTotal), iEnd) / g_nMaxWorkerCount;
          if ( (int)m_uiTotal <= 0 )
            LODWORD(m_uiTotal) = 8;
        }
        iBegin = v78->m_WULookup.m_uiBase + v78->m_WULookup.m_Size;
        v36 = __PAIR64__(v35, i) + (int)m_uiTotal * g_nMaxWorkerCount;
        if ( v36 >= __PAIR64__(HIDWORD(m_uiTotal), iEnd) )
          v36 = v78->m_WULookup.m_uiTotal;
        v37 = v36;
        iEnda = v36;
        if ( v36 - 1 >= __PAIR64__(v35, i) )
          CUtlVector<CWULookupInfo,CUtlMemory<CWULookupInfo,int>>::InsertMultipleBefore(
            this: &v78->m_WULookup,
            elem: v78->m_WULookup.m_Size,
            num: v36 - v78->m_WULookup.m_Size - LODWORD(v78->m_WULookup.m_uiBase));
        v38 = v37;
        v39 = g_nMaxWorkerCount;
        if ( __PAIR64__(HIDWORD(iEnda), v38) - iBegin >= g_nMaxWorkerCount )
        {
          pOldHalf = (CPartitionInfo *)g_nMaxWorkerCount;
        }
        else
        {
          v39 = v38 - iBegin;
          pOldHalf = (CPartitionInfo *)(v38 - iBegin);
        }
        v41 = v78;
        iOldWorker = (int)operator new(nSize: 4 * v39);
        *(_DWORD *)iOldWorker = CDistributor_DefaultMaster::AddPartition(this: v78, iWorker);
        v42 = 1;
        if ( v39 > 1 )
        {
          pPartition = (CPartitionInfo *)&v41->m_Partitions;
          do
          {
            v43 = (CPartitionInfo *)operator new(nSize: 0x30u);
            if ( v43 != nullptr )
            {
              v43->m_WUs.m_Memory.m_pMemory = nullptr;
              v43->m_WUs.m_Memory.m_nAllocationCount = 0;
              v43->m_WUs.m_Memory.m_nGrowSize = 0;
              v43->m_WUs.m_LastAlloc.index = -1;
              v43->m_WUs.m_ElementCount = 0;
              v43->m_WUs.m_NumAlloced = 0;
              v44 = v43->m_WUs.m_Memory.m_pMemory;
              v43->m_WUs.m_Head = -1;
              v43->m_WUs.m_Tail = -1;
              v43->m_WUs.m_FirstFree = -1;
              v43->m_WUs.m_pElements = v44;
              v45 = v43;
            }
            else
            {
              v45 = nullptr;
            }
            pNewHalf = v45;
            v45->m_iPartition = CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::AddToTail(
                                  this: (CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int> > *)pPartition,
                                  src: &pNewHalf);
            v46 = iOldWorker;
            v45->m_iWorker = -1;
            *(_DWORD *)(v46 + 4 * v42++) = v45;
          }
          while ( v42 < v39 );
        }
        HIDWORD(v47) = HIDWORD(iBegin);
        if ( iBegin < iEnda )
        {
          do
          {
            LODWORD(v47) = i;
            v48 = *(_DWORD *)(iOldWorker + 4 * ((v47 - iBegin) % (unsigned int)pOldHalf));
            LODWORD(v47) = HIDWORD(v78->m_WULookup.m_uiBase);
            v49 = v78->m_WULookup.m_uiBase;
            pNewHalf = (CPartitionInfo *)&v78->m_WULookup;
            if ( __PAIR64__(HIDWORD(v47), i) < __PAIR64__(v47, v49)
              || __PAIR64__(HIDWORD(v47), i) >= __PAIR64__(v47, v49) + v78->m_WULookup.m_Size )
            {
              pPartition = nullptr;
            }
            else
            {
              pPartition = (CPartitionInfo *)(pNewHalf->m_iPartition + 12 * (i - pNewHalf->m_WUs.m_Tail));
            }
            pPartition->m_iWorker = *(_DWORD *)v48;
            v50 = CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::AllocInternal(
                    this: (CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *)(v48 + 8),
                    multilist: false);
            v51 = v50;
            if ( v50 == -1 )
            {
              v51 = -1;
            }
            else
            {
              CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
                this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)(v48 + 8),
                elem: v50);
              v52 = *(_DWORD *)(v48 + 8);
              v53 = 16 * v51;
              *(_DWORD *)(v52 + v53 + 12) = -1;
              v54 = *(_DWORD *)(v48 + 24);
              *(_DWORD *)(v52 + v53 + 8) = v54;
              *(_DWORD *)(v48 + 24) = v51;
              if ( v54 == -1 )
                *(_DWORD *)(v48 + 20) = v51;
              else
                *(_DWORD *)(*(_DWORD *)(v48 + 8) + 16 * v54 + 12) = v51;
              ++*(_DWORD *)(v48 + 32);
              v55 = (int *)(v53 + *(_DWORD *)(v48 + 8));
              if ( v55 != nullptr )
              {
                *v55 = i;
                v55[1] = HIDWORD(v47);
              }
            }
            pPartition->m_WUs.m_Memory.m_pMemory = (UtlLinkedListElem_t<unsigned __int64,int> *)v51;
            v56 = v78;
            v57 = CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::AllocInternal(
                    this: &v78->m_WUInfo,
                    multilist: false);
            v58 = v57;
            if ( v57 == -1 )
            {
              v58 = -1;
            }
            else
            {
              CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
                this: &v56->m_WUInfo,
                elem: v57);
              v59 = v56->m_WUInfo.m_Memory.m_pMemory;
              v60 = v58;
              v59[v60].m_Next = -1;
              v61 = v56->m_WUInfo.m_Tail;
              v59[v60].m_Previous = v61;
              v56->m_WUInfo.m_Tail = v58;
              if ( v61 == -1 )
                v56->m_WUInfo.m_Head = v58;
              else
                v56->m_WUInfo.m_Memory.m_pMemory[v61].m_Next = v58;
              ++v56->m_WUInfo.m_ElementCount;
              v62 = &v56->m_WUInfo.m_Memory.m_pMemory[v60];
              if ( v62 != nullptr )
              {
                LODWORD(v62->m_Element.m_iWorkUnit) = i;
                HIDWORD(v62->m_Element.m_iWorkUnit) = HIDWORD(v47);
              }
            }
            v63 = i++;
            pPartition->m_iPartition = v58;
            HIDWORD(v47) = (__PAIR64__(HIDWORD(v47), v63) + 1) >> 32;
          }
          while ( __PAIR64__(HIDWORD(v47), i) < iEnda );
        }
        v64 = (void *)iOldWorker;
        CDistributor_DefaultMaster::SendPartitionToWorker(
          this: v78,
          pPartition: *(CPartitionInfo **)iOldWorker,
          iWorker);
        free(pMem: v64);
        free(pMem: nullptr);
      }
    }
    else
    {
      v33 = v3->m_Partitions.m_Memory.m_pMemory;
      while ( v33[m_Next].m_Element->m_iWorker != -1 )
      {
        m_Next = v33[m_Next].m_Next;
        if ( m_Next == -1 )
          goto LABEL_45;
      }
      v40 = v33[m_Next].m_Element;
      v40->m_iWorker = iWorker;
      CDistributor_DefaultMaster::SendPartitionToWorker(this: v3, pPartition: v40, iWorker);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100199F0
// Name: public: virtual void CDistributor_DefaultMaster::OnWorkerReady(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::OnWorkerReady(CDistributor_DefaultMaster *this, int iSource)
{
  CDistributor_DefaultMaster::AssignWUsToWorker(this, iWorker: iSource);
}

//------------------------------------------------------------------------------
// Address: 0x10019A00
// Name: public: virtual bool CDistributor_DefaultMaster::HandleWorkUnitResults(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_DefaultMaster::HandleWorkUnitResults(
        CDistributor_DefaultMaster *this,
        unsigned __int64 iWorkUnit)
{
  CVisibleWindowVector<CWULookupInfo> *p_m_WULookup; // edi
  int *p_m_iWUInfo; // ebx
  UtlLinkedListElem_t<CPartitionInfo *,int> *m_pMemory; // edx
  int v6; // esi
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *p_m_WUs; // ebx
  unsigned int v8; // ecx
  CDistributor_DefaultMaster *v9; // esi
  unsigned int v10; // eax
  unsigned int v11; // edx
  CWULookupInfo *v12; // esi
  void *v13; // edi
  __int64 v14; // rax
  unsigned __int64 v16; // [esp+14h] [ebp-18h]
  int iPartition; // [esp+20h] [ebp-Ch]
  int iPartitionWorker; // [esp+24h] [ebp-8h]
  int iPartitionWorkera; // [esp+24h] [ebp-8h]
  int iPartitionWorkerb; // [esp+24h] [ebp-8h]

  if ( iWorkUnit < this->m_WULookup.m_uiBase )
    return 0;
  p_m_WULookup = &this->m_WULookup;
  if ( iWorkUnit >= this->m_WULookup.m_uiBase + this->m_WULookup.m_Size )
    return 0;
  if ( iWorkUnit < this->m_WULookup.m_uiBase )
    return 0;
  p_m_iWUInfo = &p_m_WULookup->m_Memory.m_pMemory[iWorkUnit - LODWORD(this->m_WULookup.m_uiBase)].m_iWUInfo;
  if ( p_m_iWUInfo == nullptr )
    return 0;
  iPartitionWorker = *p_m_iWUInfo;
  if ( *p_m_iWUInfo == -1 )
    return 0;
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
    this: &this->m_WUInfo,
    elem: *p_m_iWUInfo);
  this->m_WUInfo.m_Memory.m_pMemory[iPartitionWorker].m_Next = this->m_WUInfo.m_FirstFree;
  this->m_WUInfo.m_FirstFree = iPartitionWorker;
  iPartition = p_m_iWUInfo[1];
  *p_m_iWUInfo = -1;
  m_pMemory = this->m_Partitions.m_Memory.m_pMemory;
  v6 = p_m_iWUInfo[2];
  p_m_WUs = (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&m_pMemory[iPartition].m_Element->m_WUs;
  iPartitionWorkera = (int)m_pMemory[iPartition].m_Element;
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
    this: p_m_WUs,
    elem: v6);
  p_m_WUs->m_Memory.m_pMemory[v6].m_Next = p_m_WUs->m_FirstFree;
  v8 = iWorkUnit;
  p_m_WUs->m_FirstFree = v6;
  v9 = this;
  if ( iWorkUnit == this->m_WULookup.m_uiBase )
  {
    v16 = p_m_WULookup->m_uiBase + p_m_WULookup->m_Size;
    v10 = HIDWORD(v16);
    if ( iWorkUnit >= v16 )
    {
      v11 = HIDWORD(iWorkUnit);
    }
    else
    {
      v11 = HIDWORD(iWorkUnit);
      do
      {
        if ( __PAIR64__(v11, v8) < p_m_WULookup->m_uiBase || v11 > v10 || v11 >= v10 && v8 >= (unsigned int)v16 )
        {
          v12 = nullptr;
        }
        else
        {
          v12 = &p_m_WULookup->m_Memory.m_pMemory[v8 - LODWORD(p_m_WULookup->m_uiBase)];
          v10 = HIDWORD(v16);
        }
        if ( v12->m_iWUInfo != -1 && __PAIR64__(v11, v8) > iWorkUnit )
          break;
        v11 = (__PAIR64__(v11, v8++) + 1) >> 32;
      }
      while ( __PAIR64__(v11, v8) < __PAIR64__(v10, v16) );
    }
    CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo>>::ShrinkWindow(
      this: p_m_WULookup,
      idxDrop: __PAIR64__(v11, v8) - 1);
    v9 = this;
  }
  v13 = (void *)iPartitionWorkera;
  if ( *(_DWORD *)(iPartitionWorkera + 32) == 0 )
  {
    iPartitionWorkerb = *(_DWORD *)(iPartitionWorkera + 4);
    CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::RemoveAll(this: p_m_WUs);
    if ( p_m_WUs->m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_WUs->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_WUs->m_Memory.m_pMemory);
        p_m_WUs->m_Memory.m_pMemory = nullptr;
      }
      p_m_WUs->m_Memory.m_nAllocationCount = 0;
    }
    free(pMem: v13);
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&v9->m_Partitions,
      elem: iPartition);
    v9->m_Partitions.m_Memory.m_pMemory[iPartition].m_Next = v9->m_Partitions.m_FirstFree;
    v9->m_Partitions.m_FirstFree = iPartition;
    if ( v9->m_WULookup.m_uiBase < v9->m_WULookup.m_uiTotal )
      CDistributor_DefaultMaster::AssignWUsToWorker(this: v9, iWorker: iPartitionWorkerb);
  }
  LODWORD(v14) = CWorkUnitsTracker::WorkUnitFinished(this: &g_MasterWorkUnitsTracker, iWorkUnit);
  if ( v14 != 0 && g_pDistributeWorkCallbacks != nullptr )
    ((void (__thiscall *)(IWorkUnitDistributorCallbacks *, _DWORD, _DWORD))g_pDistributeWorkCallbacks->OnWorkUnitsCompleted)(
      a1: g_pDistributeWorkCallbacks,
      a2: v14,
      a3: HIDWORD(v14));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100380B0
// Name: public: virtual void CDistributor_DefaultWorker::Init(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultWorker::Init(CDistributor_DefaultWorker *this, CDSInfo *pInfo)
{
  ;
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10082BB0
// Name: public: virtual void CDistributor_DefaultWorker::Init(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultWorker::Init(CDistributor_DefaultWorker *this, CDSInfo *pInfo)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10092BF0
// Name: public: virtual void CDistributor_DefaultWorker::NoteLocalWorkUnitCompleted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultWorker::NoteLocalWorkUnitCompleted(
        CDistributor_DefaultWorker *this,
        unsigned __int64 iWU)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10092E10
// Name: public: void CWorkUnitsTracker::PrepareForWorkUnits(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkUnitsTracker::PrepareForWorkUnits(CWorkUnitsTracker *this, unsigned __int64 numUnits)
{
  int v2; // ebx

  v2 = HIDWORD(numUnits);
  CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::Reset(
    this: &this->m_arrInfo,
    uiTotal: numUnits + 1);
  if ( (v2 | (unsigned int)numUnits) != 0 )
  {
    HIBYTE(numUnits) = 0;
    CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ExpandWindow(
      this: &this->m_arrInfo,
      idxAccessible: 2u,
      x: (const unsigned __int8 *)&numUnits + 7);
    if ( HIDWORD(this->m_arrInfo.m_uiBase) != 0 || LODWORD(this->m_arrInfo.m_uiBase) != 0 || this->m_arrInfo.m_Size == 0 )
      MEMORY[0] = 1;
    else
      *this->m_arrInfo.m_Memory.m_pMemory = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092E90
// Name: public: unsigned __int64 CWorkUnitsTracker::WorkUnitFinished(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWorkUnitsTracker::WorkUnitFinished(CWorkUnitsTracker *this, unsigned __int64 iWorkUnit)
{
  __int64 v2; // rcx
  unsigned int v4; // esi
  unsigned __int8 *v5; // eax
  unsigned __int8 v6; // cl
  unsigned __int64 v7; // rax
  unsigned int v8; // kr00_4
  unsigned __int8 *v9; // eax
  bool v10; // zf
  unsigned __int8 *v11; // eax
  unsigned int v13; // kr10_4
  unsigned __int8 *v14; // eax
  unsigned __int64 v15; // [esp-Ch] [ebp-1Ch]

  HIDWORD(v2) = HIDWORD(iWorkUnit);
  if ( HIDWORD(iWorkUnit) < HIDWORD(this->m_arrInfo.m_uiBase) )
    return 0;
  v4 = iWorkUnit;
  if ( HIDWORD(iWorkUnit) <= HIDWORD(this->m_arrInfo.m_uiBase)
    && (unsigned int)iWorkUnit < LODWORD(this->m_arrInfo.m_uiBase) )
  {
    return 0;
  }
  if ( iWorkUnit >= this->m_arrInfo.m_uiTotal )
    return 0;
  LODWORD(v2) = iWorkUnit;
  HIBYTE(iWorkUnit) = 0;
  CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ExpandWindow(
    this: &this->m_arrInfo,
    idxAccessible: v2 + 1,
    x: (const unsigned __int8 *)&iWorkUnit + 7);
  if ( __PAIR64__(HIDWORD(v2), iWorkUnit) < this->m_arrInfo.m_uiBase
    || __PAIR64__(HIDWORD(v2), iWorkUnit) >= this->m_arrInfo.m_uiBase + this->m_arrInfo.m_Size )
  {
    v5 = nullptr;
  }
  else
  {
    v5 = &this->m_arrInfo.m_Memory.m_pMemory[iWorkUnit - LODWORD(this->m_arrInfo.m_uiBase)];
  }
  v6 = *v5;
  *v5 = 2;
  if ( v6 != 1 )
  {
    if ( __PAIR64__(HIDWORD(v2), iWorkUnit) == this->m_arrInfo.m_uiBase )
    {
      do
      {
        v13 = v4 + 1;
        HIDWORD(v2) = (__PAIR64__(HIDWORD(v2), v4) + 1) >> 32;
        v4 = v13;
        if ( __PAIR64__(HIDWORD(v2), v13) >= this->m_arrInfo.m_uiBase + this->m_arrInfo.m_Size )
          break;
        v14 = __PAIR64__(HIDWORD(v2), v13) < this->m_arrInfo.m_uiBase
            ? nullptr
            : &this->m_arrInfo.m_Memory.m_pMemory[v13 - LODWORD(this->m_arrInfo.m_uiBase)];
      }
      while ( *v14 == 2 );
      CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ShrinkWindow(
        this: &this->m_arrInfo,
        idxDrop: __PAIR64__(HIDWORD(v2), v13) - 1);
    }
    return 0;
  }
  LODWORD(v2) = HIDWORD(this->m_arrInfo.m_uiBase);
  v7 = this->m_arrInfo.m_uiBase + this->m_arrInfo.m_Size;
  do
  {
    v8 = v4 + 1;
    HIDWORD(v2) = (__PAIR64__(HIDWORD(v2), v4) + 1) >> 32;
    v4 = v8;
    if ( __PAIR64__(HIDWORD(v2), v8) >= v7 )
      break;
    v9 = __PAIR64__(HIDWORD(v2), v8) < this->m_arrInfo.m_uiBase
       ? nullptr
       : &this->m_arrInfo.m_Memory.m_pMemory[v8 - LODWORD(this->m_arrInfo.m_uiBase)];
    v10 = *v9 == 2;
    LODWORD(v7) = LODWORD(this->m_arrInfo.m_uiBase) + this->m_arrInfo.m_Size;
  }
  while ( v10 );
  if ( HIDWORD(v2) < (unsigned int)v2
    || HIDWORD(v2) <= (unsigned int)v2 && v8 < LODWORD(this->m_arrInfo.m_uiBase)
    || __PAIR64__(HIDWORD(v2), v8) >= v7 )
  {
    v11 = nullptr;
  }
  else
  {
    v11 = &this->m_arrInfo.m_Memory.m_pMemory[v8 - LODWORD(this->m_arrInfo.m_uiBase)];
  }
  *v11 = 1;
  HIDWORD(v15) = (v8 != 0) + HIDWORD(v2) - 1;
  LODWORD(v15) = v8 - 1;
  CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ShrinkWindow(
    this: &this->m_arrInfo,
    idxDrop: v15);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10093010
// Name: class IWorkUnitDistributorWorker __near * CreateWUDistributor_DefaultWorker(void)
// Source: json
//------------------------------------------------------------------------------
IWorkUnitDistributorWorker *__cdecl CreateWUDistributor_DefaultWorker()
{
  char *v0; // eax
  _DWORD *v1; // esi
  int v2; // eax

  v0 = (char *)MemAlloc_Alloc(nSize: 0x84u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *(_DWORD *)v0 = &CDistributor_DefaultWorker::`vftable';
  CCriticalSection::CCriticalSection(this: (CCriticalSection *)(v0 + 4));
  v1[23] = 0;
  v1[24] = 0;
  v1[25] = 0;
  v1[31] = -1;
  v1[26] = -1;
  v1[27] = -1;
  v1[28] = -1;
  v2 = v1[23];
  v1[29] = 0;
  v1[30] = 0;
  v1[32] = v2;
  return (IWorkUnitDistributorWorker *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10093070
// Name: public: virtual void CDistributor_DefaultWorker::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultWorker::Release(CDistributor_DefaultWorker *this)
{
  if ( this != nullptr )
  {
    CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::RemoveAll(this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&this->m_WorkUnits);
    if ( this->m_WorkUnits.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_WorkUnits.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WorkUnits.m_Memory.m_pMemory);
        this->m_WorkUnits.m_Memory.m_pMemory = nullptr;
      }
      this->m_WorkUnits.m_Memory.m_nAllocationCount = 0;
    }
    CCriticalSection::~CCriticalSection(this: &this->m_CS);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100930C0
// Name: public: virtual bool CDistributor_DefaultWorker::GetNextWorkUnit(unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_DefaultWorker::GetNextWorkUnit(
        CDistributor_DefaultWorker *this,
        unsigned __int64 *pWUIndex)
{
  UtlLinkedListElem_t<unsigned __int64,int> *m_pMemory; // ecx
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *p_m_WorkUnits; // esi
  int m_Head; // eax
  int v7; // edi
  CCriticalSectionLock csLock; // [esp+4h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  if ( this->m_WorkUnits.m_ElementCount != 0 )
  {
    m_pMemory = this->m_WorkUnits.m_Memory.m_pMemory;
    p_m_WorkUnits = (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&this->m_WorkUnits;
    m_Head = this->m_WorkUnits.m_Head;
    *(_DWORD *)pWUIndex = m_pMemory[this->m_WorkUnits.m_Head].m_Element;
    *((_DWORD *)pWUIndex + 1) = HIDWORD(m_pMemory[m_Head].m_Element);
    v7 = this->m_WorkUnits.m_Head;
    CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
      this: p_m_WorkUnits,
      elem: v7);
    p_m_WorkUnits->m_Memory.m_pMemory[v7].m_Next = p_m_WorkUnits->m_FirstFree;
    p_m_WorkUnits->m_FirstFree = v7;
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 1;
  }
  else
  {
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093140
// Name: public: CDistributor_DefaultMaster::CDistributor_DefaultMaster(void)
// Source: json
//------------------------------------------------------------------------------
CDistributor_DefaultMaster *__thiscall CDistributor_DefaultMaster::CDistributor_DefaultMaster(
        CDistributor_DefaultMaster *this)
{
  CDistributor_DefaultMaster *result; // eax
  UtlLinkedListElem_t<CWorkUnitInfo,int> *m_pMemory; // ecx

  result = this;
  this->__vftable = (CDistributor_DefaultMaster_vtbl *)&CDistributor_DefaultMaster::`vftable';
  this->m_Partitions.m_Memory.m_pMemory = nullptr;
  this->m_Partitions.m_Memory.m_nAllocationCount = 0;
  this->m_Partitions.m_Memory.m_nGrowSize = 0;
  this->m_Partitions.m_LastAlloc.index = -1;
  this->m_Partitions.m_Head = -1;
  this->m_Partitions.m_Tail = -1;
  this->m_Partitions.m_FirstFree = -1;
  this->m_Partitions.m_ElementCount = 0;
  this->m_Partitions.m_NumAlloced = 0;
  this->m_Partitions.m_pElements = this->m_Partitions.m_Memory.m_pMemory;
  this->m_WULookup.m_Memory.m_pMemory = nullptr;
  this->m_WULookup.m_Memory.m_nAllocationCount = 0;
  this->m_WULookup.m_Memory.m_nGrowSize = 0;
  this->m_WULookup.m_Size = 0;
  this->m_WULookup.m_pElements = nullptr;
  this->m_WULookup.m_uiBase = 0;
  this->m_WULookup.m_uiTotal = 0;
  this->m_WUInfo.m_Memory.m_pMemory = nullptr;
  this->m_WUInfo.m_Memory.m_nAllocationCount = 0;
  this->m_WUInfo.m_Memory.m_nGrowSize = 0;
  this->m_WUInfo.m_LastAlloc.index = -1;
  this->m_WUInfo.m_ElementCount = 0;
  this->m_WUInfo.m_NumAlloced = 0;
  m_pMemory = this->m_WUInfo.m_Memory.m_pMemory;
  result->m_WUInfo.m_Head = -1;
  result->m_WUInfo.m_Tail = -1;
  result->m_WUInfo.m_FirstFree = -1;
  result->m_WUInfo.m_pElements = m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100931B0
// Name: public: virtual bool CDistributor_DefaultMaster::HandlePacket(class MessageBuffer __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDistributor_DefaultMaster::HandlePacket(
        CDistributor_DefaultMaster *this,
        MessageBuffer *pBuf,
        MessageBuffer *iSource,
        bool bIgnoreContents)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10093980
// Name: CompareSoonestWorkUnitSets
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CompareSoonestWorkUnitSets(
        CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *const *x,
        CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *const *y)
{
  int *v2; // edx
  int m_Head; // eax
  unsigned int v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // ebx
  int v7; // ecx
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  unsigned __int64 jobsX[4]; // [esp+Ch] [ebp-40h] BYREF
  unsigned __int64 jobsY[4]; // [esp+2Ch] [ebp-20h] BYREF

  v2 = (int *)*x;
  m_Head = (*x)->m_Head;
  v4 = -1;
  v5 = -1;
  v6 = -1;
  v7 = 0;
  memset(jobsX, 255, 16);
  jobsX[3] = -1;
  memset(jobsY, 255, 16);
  jobsY[3] = -1;
  if ( m_Head != -1 )
  {
    v8 = *v2;
    do
    {
      v9 = 2 * m_Head;
      LODWORD(jobsX[v7]) = *(_DWORD *)(v8 + 8 * v9);
      HIDWORD(jobsX[v7++]) = *(_DWORD *)(v8 + 8 * v9 + 4);
      if ( v7 >= 4 )
        break;
      m_Head = *(_DWORD *)(v8 + 8 * v9 + 12);
    }
    while ( m_Head != -1 );
    v5 = HIDWORD(jobsX[3]);
  }
  v10 = (*y)->m_Head;
  v11 = 0;
  if ( v10 != -1 )
  {
    v12 = **(_DWORD **)y;
    do
    {
      v13 = 2 * v10;
      LODWORD(jobsY[v11]) = *(_DWORD *)(v12 + 8 * v13);
      HIDWORD(jobsY[v11++]) = *(_DWORD *)(v12 + 8 * v13 + 4);
      if ( v11 >= 4 )
        break;
      v10 = *(_DWORD *)(v12 + 8 * v13 + 12);
    }
    while ( v10 != -1 );
    v4 = HIDWORD(jobsY[3]);
    v6 = jobsY[3];
  }
  if ( LODWORD(jobsX[3]) != v6 || v5 != v4 )
  {
    if ( v5 > v4 )
      return false;
    if ( v5 >= v4 )
      return LODWORD(jobsX[3]) < v6;
    return true;
  }
  if ( jobsX[1] == jobsY[1] )
  {
    if ( HIDWORD(jobsX[0]) > HIDWORD(jobsY[0]) )
      return false;
    if ( HIDWORD(jobsX[0]) < HIDWORD(jobsY[0]) )
      return true;
    return LODWORD(jobsX[0]) < LODWORD(jobsY[0]);
  }
  else
  {
    if ( HIDWORD(jobsX[1]) > HIDWORD(jobsY[1]) )
      return false;
    if ( HIDWORD(jobsX[1]) < HIDWORD(jobsY[1]) )
      return true;
    return LODWORD(jobsX[1]) < LODWORD(jobsY[1]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093A90
// Name: public: void CDistributor_DefaultMaster::SendPartitionToWorker(class CPartitionInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::SendPartitionToWorker(
        CDistributor_DefaultMaster *this,
        CPartitionInfo *pPartition,
        int iWorker)
{
  int m_Head; // esi
  UtlLinkedListElem_t<unsigned __int64,int> *m_pMemory; // eax
  int v5; // esi
  int Name; // eax
  MessageBuffer mb; // [esp+Ch] [ebp-18h] BYREF
  unsigned __int64 iWU; // [esp+1Ch] [ebp-8h] BYREF

  MessageBuffer::MessageBuffer(this: &mb);
  PrepareDistributeWorkHeader(pBuf: &mb, cSubpacketID: 0x32u);
  m_Head = pPartition->m_WUs.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = pPartition->m_WUs.m_Memory.m_pMemory;
    do
    {
      v5 = m_Head;
      iWU = m_pMemory[v5].m_Element;
      MessageBuffer::write(this: &mb, p: &iWU, bytes: 8);
      VMPITracker_WorkUnitSentToWorker(iWorkUnit: iWU, iWorker);
      m_pMemory = pPartition->m_WUs.m_Memory.m_pMemory;
      m_Head = m_pMemory[v5].m_Next;
    }
    while ( m_Head != -1 );
  }
  Name = ConCommandBase::GetName(this: (CVTFTexture *)&mb);
  VMPI_SendData(pData: mb.data, nBytes: Name, iDest: iWorker, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x10094500
// Name: public: virtual void CDistributor_DefaultMaster::DisconnectHandler(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::DisconnectHandler(CDistributor_DefaultMaster *this, int workerID)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CPartitionInfo *,int> *m_pMemory; // edx

  m_Head = this->m_Partitions.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_Partitions.m_Memory.m_pMemory;
    while ( m_pMemory[m_Head].m_Element->m_iWorker != workerID )
    {
      m_Head = m_pMemory[m_Head].m_Next;
      if ( m_Head == -1 )
        return;
    }
    m_pMemory[m_Head].m_Element->m_iWorker = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094550
// Name: public: virtual void CDistributor_DefaultMaster::DistributeWork_Master(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::DistributeWork_Master(CDistributor_DefaultMaster *this, CDSInfo *pInfo)
{
  this->m_pInfo = pInfo;
  CWorkUnitsTracker::PrepareForWorkUnits(this: &g_MasterWorkUnitsTracker, numUnits: pInfo->m_nWorkUnits);
  CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo>>::Reset(
    this: &this->m_WULookup,
    uiTotal: pInfo->m_nWorkUnits);
  if ( this->m_WULookup.m_uiBase < this->m_WULookup.m_uiTotal )
  {
    do
    {
      VMPI_DispatchNextMessage(timeout: 0xC8u);
      VMPITracker_HandleDebugKeypresses();
    }
    while ( (g_pDistributeWorkCallbacks == nullptr
          || g_pDistributeWorkCallbacks->Update(this: g_pDistributeWorkCallbacks) == 0)
         && this->m_WULookup.m_uiBase < this->m_WULookup.m_uiTotal );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094670
// Name: public: CDistributor_DefaultMaster::~CDistributor_DefaultMaster(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::~CDistributor_DefaultMaster(CDistributor_DefaultMaster *this)
{
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::RemoveAll(this: &this->m_WUInfo);
  if ( this->m_WUInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_WUInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WUInfo.m_Memory.m_pMemory);
      this->m_WUInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_WUInfo.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_WULookup);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_Partitions);
  if ( this->m_Partitions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Partitions.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Partitions.m_Memory.m_pMemory);
      this->m_Partitions.m_Memory.m_pMemory = nullptr;
    }
    this->m_Partitions.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100947D0
// Name: public: class CPartitionInfo __near * CDistributor_DefaultMaster::AddPartition(int)
// Source: json
//------------------------------------------------------------------------------
CPartitionInfo *__thiscall CDistributor_DefaultMaster::AddPartition(CDistributor_DefaultMaster *this, int iWorker)
{
  CPartitionInfo *v3; // eax
  CPartitionInfo *v4; // esi
  UtlLinkedListElem_t<unsigned __int64,int> *m_pMemory; // ecx
  CPartitionInfo *pNew; // [esp+8h] [ebp-4h] BYREF

  v3 = (CPartitionInfo *)MemAlloc_Alloc(nSize: 0x30u);
  v4 = nullptr;
  if ( v3 != nullptr )
  {
    v3->m_WUs.m_Memory.m_pMemory = nullptr;
    v3->m_WUs.m_Memory.m_nAllocationCount = 0;
    v3->m_WUs.m_Memory.m_nGrowSize = 0;
    v3->m_WUs.m_LastAlloc.index = -1;
    v3->m_WUs.m_Head = -1;
    v3->m_WUs.m_Tail = -1;
    v3->m_WUs.m_FirstFree = -1;
    m_pMemory = v3->m_WUs.m_Memory.m_pMemory;
    v3->m_WUs.m_ElementCount = 0;
    v3->m_WUs.m_NumAlloced = 0;
    v3->m_WUs.m_pElements = m_pMemory;
    v4 = v3;
  }
  pNew = v4;
  v4->m_iPartition = CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::AddToTail(
                       this: &this->m_Partitions,
                       src: &pNew);
  v4->m_iWorker = iWorker;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10094830
// Name: public: bool CDistributor_DefaultMaster::SplitWUsPartition(class CPartitionInfo __near *,class CPartitionInfo __near * __near *,class CPartitionInfo __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_DefaultMaster::SplitWUsPartition(
        CDistributor_DefaultMaster *this,
        CPartitionInfo *pPartitionLarge,
        CPartitionInfo **ppFirstHalf,
        CPartitionInfo **ppSecondHalf,
        CPartitionInfo *iFirstHalfWorker,
        int iSecondHalfWorker)
{
  int m_ElementCount; // eax
  CDistributor_DefaultMaster *v8; // ebx
  CPartitionInfo *v9; // eax
  int m_Head; // esi
  UtlLinkedListElem_t<unsigned __int64,int> *m_pMemory; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  unsigned int m_uiBase_high; // ecx
  unsigned int m_uiBase; // esi
  int v16; // eax
  int v17; // ebx
  UtlLinkedListElem_t<unsigned __int64,int> *v18; // eax
  int v19; // edx
  int m_Tail; // ecx
  UtlLinkedListElem_t<unsigned __int64,int> *v21; // esi
  CPartitionInfo *arrNewParts[2]; // [esp+Ch] [ebp-14h]
  unsigned __int64 iWU; // [esp+14h] [ebp-Ch]
  CDistributor_DefaultMaster *v25; // [esp+1Ch] [ebp-4h]
  int nCount; // [esp+28h] [ebp+8h]
  int iHead; // [esp+2Ch] [ebp+Ch]
  CPartitionInfo *pTo; // [esp+34h] [ebp+14h]
  int k; // [esp+38h] [ebp+18h]

  m_ElementCount = pPartitionLarge->m_WUs.m_ElementCount;
  v8 = this;
  v25 = this;
  nCount = m_ElementCount;
  if ( m_ElementCount <= 1 )
  {
    *ppFirstHalf = nullptr;
    v9 = CDistributor_DefaultMaster::AddPartition(this, iWorker: iSecondHalfWorker);
  }
  else
  {
    *ppFirstHalf = CDistributor_DefaultMaster::AddPartition(this, iWorker: (int)iFirstHalfWorker);
    v9 = CDistributor_DefaultMaster::AddPartition(this: v8, iWorker: iSecondHalfWorker);
  }
  *ppSecondHalf = v9;
  if ( *ppFirstHalf != nullptr )
    arrNewParts[0] = *ppFirstHalf;
  else
    arrNewParts[0] = *ppSecondHalf;
  arrNewParts[1] = *ppSecondHalf;
  k = 0;
  if ( nCount > 0 )
  {
    while ( 1 )
    {
      m_Head = pPartitionLarge->m_WUs.m_Head;
      iWU = pPartitionLarge->m_WUs.m_Memory.m_pMemory[m_Head].m_Element;
      if ( m_Head >= 0
        && m_Head < pPartitionLarge->m_WUs.m_Memory.m_nAllocationCount
        && m_Head <= pPartitionLarge->m_WUs.m_LastAlloc.index )
      {
        m_pMemory = pPartitionLarge->m_WUs.m_Memory.m_pMemory;
        if ( m_pMemory[m_Head].m_Previous != m_Head )
        {
          m_Previous = m_pMemory[m_Head].m_Previous;
          if ( m_Previous == -1 )
          {
            pPartitionLarge->m_WUs.m_Head = m_pMemory[m_Head].m_Next;
          }
          else
          {
            m_pMemory[m_Previous].m_Next = m_pMemory[m_Head].m_Next;
            v8 = v25;
          }
          m_Next = m_pMemory[m_Head].m_Next;
          if ( m_Next == -1 )
          {
            pPartitionLarge->m_WUs.m_Tail = m_pMemory[m_Head].m_Previous;
          }
          else
          {
            pPartitionLarge->m_WUs.m_Memory.m_pMemory[m_Next].m_Previous = m_pMemory[m_Head].m_Previous;
            v8 = v25;
          }
          m_pMemory[m_Head].m_Next = m_Head;
          m_pMemory[m_Head].m_Previous = m_Head;
          --pPartitionLarge->m_WUs.m_ElementCount;
        }
      }
      pPartitionLarge->m_WUs.m_Memory.m_pMemory[m_Head].m_Next = pPartitionLarge->m_WUs.m_FirstFree;
      pPartitionLarge->m_WUs.m_FirstFree = m_Head;
      m_uiBase_high = HIDWORD(v8->m_WULookup.m_uiBase);
      m_uiBase = v8->m_WULookup.m_uiBase;
      pTo = arrNewParts[k >= nCount / 2];
      if ( iWU < __PAIR64__(m_uiBase_high, m_uiBase)
        || iWU >= __PAIR64__(m_uiBase_high, m_uiBase) + v8->m_WULookup.m_Size )
      {
        iHead = 0;
      }
      else
      {
        iHead = (int)&v8->m_WULookup.m_Memory.m_pMemory[iWU - m_uiBase];
      }
      *(_DWORD *)(iHead + 4) = pTo->m_iPartition;
      v16 = CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::AllocInternal(
              this: &pTo->m_WUs,
              multilist: false);
      v17 = v16;
      if ( v16 == -1 )
      {
        v17 = -1;
      }
      else
      {
        CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
          this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&pTo->m_WUs,
          elem: v16);
        v18 = pTo->m_WUs.m_Memory.m_pMemory;
        v19 = v17;
        v18[v19].m_Next = -1;
        m_Tail = pTo->m_WUs.m_Tail;
        v18[v19].m_Previous = m_Tail;
        pTo->m_WUs.m_Tail = v17;
        if ( m_Tail == -1 )
          pTo->m_WUs.m_Head = v17;
        else
          pTo->m_WUs.m_Memory.m_pMemory[m_Tail].m_Next = v17;
        ++pTo->m_WUs.m_ElementCount;
        v21 = &pTo->m_WUs.m_Memory.m_pMemory[v19];
        if ( v21 != nullptr )
          v21->m_Element = iWU;
      }
      *(_DWORD *)(iHead + 8) = v17;
      if ( ++k >= nCount )
        break;
      v8 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10094A30
// Name: public: virtual bool CDistributor_DefaultWorker::HandlePacket(class MessageBuffer __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_DefaultWorker::HandlePacket(
        CDistributor_DefaultWorker *this,
        MessageBuffer *pBuf,
        int iSource,
        bool bIgnoreContents)
{
  char Name; // bl
  CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *p_m_WorkUnits; // ebx
  int v8; // esi
  unsigned int i; // esi
  unsigned __int64 iWU; // [esp+8h] [ebp-10h] BYREF
  CCriticalSectionLock csLock; // [esp+10h] [ebp-8h] BYREF

  if ( pBuf->data[1] != 50 )
    return 0;
  if ( bIgnoreContents )
    return 1;
  Name = ConCommandBase::GetName(this: (CVTFTexture *)pBuf);
  if ( ((Name - (unsigned __int8)MessageBuffer::getOffset(this: (CVMPIFile_Memory *)pBuf)) & 7) != 0 )
    _Error(a1: "DistributeWork: invalid work units packet from master");
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  p_m_WorkUnits = &this->m_WorkUnits;
  CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::Purge(this: &this->m_WorkUnits);
  v8 = ConCommandBase::GetName(this: (CVTFTexture *)pBuf);
  for ( i = (v8 - MessageBuffer::getOffset(this: (CVMPIFile_Memory *)pBuf)) >> 3; i != 0; --i )
  {
    MessageBuffer::read(this: pBuf, p: &iWU, bytes: 8);
    CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::AddToTail(
      this: p_m_WorkUnits,
      src: &iWU);
  }
  CCriticalSectionLock::Unlock(this: &csLock);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10094B00
// Name: class IWorkUnitDistributorMaster __near * CreateWUDistributor_DefaultMaster(void)
// Source: json
//------------------------------------------------------------------------------
CDistributor_DefaultMaster *__cdecl CreateWUDistributor_DefaultMaster()
{
  CDistributor_DefaultMaster *v0; // eax

  v0 = (CDistributor_DefaultMaster *)MemAlloc_Alloc(nSize: 0x80u);
  if ( v0 != nullptr )
    return CDistributor_DefaultMaster::CDistributor_DefaultMaster(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10094B20
// Name: public: virtual void CDistributor_DefaultMaster::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::Release(CDistributor_DefaultMaster *this)
{
  if ( this != nullptr )
  {
    CDistributor_DefaultMaster::~CDistributor_DefaultMaster(this);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094B40
// Name: public: int CDistributor_DefaultMaster::FindSoonestPartition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDistributor_DefaultMaster::FindSoonestPartition(CDistributor_DefaultMaster *this)
{
  int m_ElementCount; // eax
  IMemAlloc_vtbl *v3; // edx
  int m_Head; // eax
  int v5; // edi
  CPartitionInfo *m_Element; // edx
  int v7; // ecx
  UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int v9; // esi
  CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t *p_m_Data; // esi
  unsigned __int16 Inorder; // ax
  int elem; // esi
  int v14; // ebx
  CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short> sortedPartitions; // [esp+8h] [ebp-2Ch] BYREF
  CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t insert; // [esp+24h] [ebp-10h] BYREF
  unsigned __int16 parent[3]; // [esp+2Ch] [ebp-8h] BYREF
  bool leftchild; // [esp+33h] [ebp-1h] BYREF

  m_ElementCount = this->m_Partitions.m_ElementCount;
  sortedPartitions.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *const *, CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *const *))CompareSoonestWorkUnitSets;
  memset(&sortedPartitions.m_Tree.m_Elements, 0, sizeof(sortedPartitions.m_Tree.m_Elements));
  *(_DWORD *)&sortedPartitions.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&sortedPartitions.m_Tree.m_FirstFree = -1;
  sortedPartitions.m_Tree.m_pElements = nullptr;
  if ( m_ElementCount > 0 )
  {
    v3 = _g_pMemAlloc->__vftable;
    sortedPartitions.m_Tree.m_Elements.m_nAllocationCount = m_ElementCount;
    sortedPartitions.m_Tree.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *)v3->Alloc_2(this: _g_pMemAlloc, a2: 16 * m_ElementCount);
  }
  m_Head = this->m_Partitions.m_Head;
  if ( m_Head == -1 )
    goto LABEL_17;
  do
  {
    v5 = m_Head;
    m_Element = this->m_Partitions.m_Memory.m_pMemory[m_Head].m_Element;
    insert.elem = m_Head;
    insert.key = &m_Element->m_WUs;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &sortedPartitions.m_Tree,
      &insert,
      parent,
      &leftchild);
    v7 = CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &sortedPartitions.m_Tree);
    m_pMemory = sortedPartitions.m_Tree.m_Elements.m_pMemory;
    v9 = v7;
    sortedPartitions.m_Tree.m_Elements.m_pMemory[v9].m_Parent = parent[0];
    m_pMemory[v9].m_Right = -1;
    m_pMemory[v9].m_Left = -1;
    m_pMemory[v9].m_Tag = 0;
    if ( parent[0] == 0xFFFF )
    {
      sortedPartitions.m_Tree.m_Root = v7;
    }
    else if ( leftchild )
    {
      m_pMemory[parent[0]].m_Left = v7;
    }
    else
    {
      m_pMemory[parent[0]].m_Right = v7;
    }
    CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &sortedPartitions.m_Tree,
      elem: v7);
    ++sortedPartitions.m_Tree.m_NumElements;
    p_m_Data = &sortedPartitions.m_Tree.m_Elements.m_pMemory[v9].m_Data;
    if ( p_m_Data != nullptr )
      *p_m_Data = insert;
    m_Head = this->m_Partitions.m_Memory.m_pMemory[v5].m_Next;
  }
  while ( m_Head != -1 );
  if ( sortedPartitions.m_Tree.m_NumElements == 0 )
  {
LABEL_17:
    v14 = this->m_Partitions.m_Head;
    CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &sortedPartitions.m_Tree);
    if ( sortedPartitions.m_Tree.m_Elements.m_nGrowSize >= 0 && sortedPartitions.m_Tree.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sortedPartitions.m_Tree.m_Elements.m_pMemory);
    return v14;
  }
  else
  {
    Inorder = CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &sortedPartitions.m_Tree);
    elem = sortedPartitions.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
    CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &sortedPartitions.m_Tree);
    if ( sortedPartitions.m_Tree.m_Elements.m_nGrowSize >= 0 && sortedPartitions.m_Tree.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sortedPartitions.m_Tree.m_Elements.m_pMemory);
    return elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094D10
// Name: public: void CDistributor_DefaultMaster::AssignWUsToWorker(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::AssignWUsToWorker(CDistributor_DefaultMaster *this, int iWorker)
{
  int m_pMemory; // edx
  CDistributor_DefaultMaster *v3; // edi
  int m_Head; // esi
  int v5; // ecx
  int v6; // edi
  int v7; // eax
  unsigned __int64 m_nWorkUnits; // rcx
  CPartitionInfo *v9; // eax
  CDSInfo *m_pInfo; // edi
  bool v11; // zf
  unsigned __int64 v12; // kr08_8
  unsigned int m_uiBase; // edi
  CWULookupInfo *v14; // ebx
  CPartitionInfo *v15; // edi
  CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *p_m_WUs; // ecx
  int v17; // eax
  int v18; // esi
  UtlLinkedListElem_t<unsigned __int64,int> *v19; // eax
  int v20; // edx
  int m_Tail; // ecx
  UtlLinkedListElem_t<unsigned __int64,int> *v22; // edi
  CDistributor_DefaultMaster *v23; // edi
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *p_m_WUInfo; // ecx
  int v25; // eax
  int v26; // esi
  UtlLinkedListElem_t<CWorkUnitInfo,int> *v27; // eax
  int v28; // edx
  int v29; // ecx
  UtlLinkedListElem_t<CWorkUnitInfo,int> *v30; // edi
  unsigned __int64 v31; // rax
  int m_Next; // eax
  UtlLinkedListElem_t<CPartitionInfo *,int> *v33; // edx
  unsigned __int64 m_uiTotal; // rcx
  unsigned int v35; // esi
  unsigned __int64 v36; // rax
  unsigned int v37; // ebx
  unsigned int v38; // esi
  unsigned int v39; // ebx
  CPartitionInfo *v40; // eax
  CDistributor_DefaultMaster *v41; // esi
  unsigned int v42; // edi
  CPartitionInfo *v43; // eax
  UtlLinkedListElem_t<unsigned __int64,int> *v44; // ecx
  CPartitionInfo *v45; // esi
  int v46; // eax
  __int64 v47; // rcx
  int v48; // esi
  unsigned int v49; // edi
  int v50; // eax
  int v51; // edi
  int v52; // eax
  int v53; // edx
  int v54; // ecx
  int *v55; // esi
  CDistributor_DefaultMaster *v56; // edi
  int v57; // eax
  int v58; // esi
  UtlLinkedListElem_t<CWorkUnitInfo,int> *v59; // eax
  int v60; // edx
  int v61; // ecx
  UtlLinkedListElem_t<CWorkUnitInfo,int> *v62; // edi
  int v63; // kr04_4
  void *v64; // esi
  CDistributor_DefaultMaster *v65; // esi
  int SoonestPartition; // eax
  int v67; // ebx
  UtlLinkedListElem_t<CPartitionInfo *,int> *v68; // edx
  CPartitionInfo *m_Element; // edi
  unsigned int iEnd; // [esp+Ch] [ebp-30h]
  unsigned __int64 iEnda; // [esp+Ch] [ebp-30h]
  int i; // [esp+14h] [ebp-28h]
  unsigned __int64 iBegin; // [esp+1Ch] [ebp-20h]
  CPartitionInfo *pOldHalf; // [esp+28h] [ebp-14h] BYREF
  CPartitionInfo *pNewHalf; // [esp+2Ch] [ebp-10h] BYREF
  int iOldWorker; // [esp+30h] [ebp-Ch]
  CPartitionInfo *pPartition; // [esp+34h] [ebp-8h]
  CDistributor_DefaultMaster *v78; // [esp+38h] [ebp-4h]

  m_pMemory = iWorker;
  v3 = this;
  m_Head = this->m_Partitions.m_Head;
  v78 = this;
  if ( m_Head != -1 )
  {
    this = (CDistributor_DefaultMaster *)this->m_Partitions.m_Memory.m_pMemory;
    while ( *(_DWORD *)(*((_DWORD *)&this->__vftable + 3 * m_Head) + 4) != iWorker )
    {
      m_Head = (int)(&this->m_Partitions.m_Memory.m_pMemory)[3 * m_Head];
      if ( m_Head == -1 )
        goto LABEL_13;
    }
    v5 = *((_DWORD *)&this->__vftable + 3 * m_Head);
    iOldWorker = v5;
    if ( v5 != 0 )
    {
      v6 = v5;
      CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::RemoveAll(this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)(v5 + 8));
      if ( *(int *)(v6 + 16) >= 0 )
      {
        if ( *(_DWORD *)(v6 + 8) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v6 + 8));
          *(_DWORD *)(v6 + 8) = 0;
        }
        *(_DWORD *)(v6 + 12) = 0;
      }
      free(pMem: (void *)iOldWorker);
      v3 = v78;
    }
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&v3->m_Partitions,
      elem: m_Head);
    m_pMemory = (int)v3->m_Partitions.m_Memory.m_pMemory;
    *(_DWORD *)(12 * m_Head + m_pMemory + 8) = v3->m_Partitions.m_FirstFree;
    v3->m_Partitions.m_FirstFree = m_Head;
  }
LABEL_13:
  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "A");
  v7 = _CommandLine(a1: this, a2: m_pMemory);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-mpi_NoScheduler") != 0 )
  {
    _Warning(a1: "\n\n-mpi_NoScheduler found: Warning - this should only be used for testing and with 1 worker!\n\n");
    m_nWorkUnits = v3->m_pInfo->m_nWorkUnits;
    if ( m_nWorkUnits >= v3->m_WULookup.m_uiBase + v3->m_WULookup.m_Size )
      CUtlVector<CWULookupInfo,CUtlMemory<CWULookupInfo,int>>::InsertMultipleBefore(
        this: &v3->m_WULookup,
        elem: v3->m_WULookup.m_Size,
        num: m_nWorkUnits - LODWORD(v3->m_WULookup.m_uiBase) - v3->m_WULookup.m_Size + 1);
    v9 = CDistributor_DefaultMaster::AddPartition(this: v3, iWorker);
    m_pInfo = v3->m_pInfo;
    v11 = HIDWORD(m_pInfo->m_nWorkUnits) == 0;
    pPartition = v9;
    iOldWorker = 0;
    if ( !v11 || LODWORD(m_pInfo->m_nWorkUnits) != 0 )
    {
      v12 = 0;
      do
      {
        m_uiBase = v78->m_WULookup.m_uiBase;
        pOldHalf = (CPartitionInfo *)HIDWORD(v78->m_WULookup.m_uiBase);
        if ( v12 < __PAIR64__((unsigned int)pOldHalf, m_uiBase)
          || v12 >= __PAIR64__((unsigned int)pOldHalf, m_uiBase) + v78->m_WULookup.m_Size )
        {
          v14 = nullptr;
        }
        else
        {
          v14 = &v78->m_WULookup.m_Memory.m_pMemory[v12 - LODWORD(v78->m_WULookup.m_uiBase)];
        }
        v15 = pPartition;
        p_m_WUs = &pPartition->m_WUs;
        v14->m_iPartition = pPartition->m_iPartition;
        v17 = CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::AllocInternal(
                this: p_m_WUs,
                multilist: false);
        v18 = v17;
        if ( v17 == -1 )
        {
          v18 = -1;
        }
        else
        {
          CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
            this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&v15->m_WUs,
            elem: v17);
          v19 = v15->m_WUs.m_Memory.m_pMemory;
          v20 = v18;
          v19[v20].m_Next = -1;
          m_Tail = v15->m_WUs.m_Tail;
          v19[v20].m_Previous = m_Tail;
          v15->m_WUs.m_Tail = v18;
          if ( m_Tail == -1 )
            v15->m_WUs.m_Head = v18;
          else
            v15->m_WUs.m_Memory.m_pMemory[m_Tail].m_Next = v18;
          ++v15->m_WUs.m_ElementCount;
          v22 = &v15->m_WUs.m_Memory.m_pMemory[v20];
          if ( v22 != nullptr )
            v22->m_Element = v12;
        }
        v23 = v78;
        p_m_WUInfo = &v78->m_WUInfo;
        v14->m_iPartitionListIndex = v18;
        v25 = CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::AllocInternal(
                this: p_m_WUInfo,
                multilist: false);
        v26 = v25;
        if ( v25 == -1 )
        {
          v26 = -1;
        }
        else
        {
          CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
            this: &v23->m_WUInfo,
            elem: v25);
          v27 = v23->m_WUInfo.m_Memory.m_pMemory;
          v28 = v26;
          v27[v28].m_Next = -1;
          v29 = v23->m_WUInfo.m_Tail;
          v27[v28].m_Previous = v29;
          v23->m_WUInfo.m_Tail = v26;
          if ( v29 == -1 )
            v23->m_WUInfo.m_Head = v26;
          else
            v23->m_WUInfo.m_Memory.m_pMemory[v29].m_Next = v26;
          ++v23->m_WUInfo.m_ElementCount;
          v30 = &v23->m_WUInfo.m_Memory.m_pMemory[v28];
          if ( v30 != nullptr )
            v30->m_Element.m_iWorkUnit = v12;
        }
        v31 = ++iOldWorker;
        v14->m_iWUInfo = v26;
        v12 = v31;
      }
      while ( v31 < v78->m_pInfo->m_nWorkUnits );
    }
    CDistributor_DefaultMaster::SendPartitionToWorker(this: v78, pPartition, iWorker);
  }
  else
  {
    m_Next = v3->m_Partitions.m_Head;
    if ( m_Next == -1 )
    {
LABEL_45:
      m_uiTotal = v78->m_WULookup.m_uiTotal;
      v35 = (v78->m_WULookup.m_uiBase + v78->m_WULookup.m_Size) >> 32;
      i = LODWORD(v78->m_WULookup.m_uiBase) + v78->m_WULookup.m_Size;
      iEnd = v78->m_WULookup.m_uiTotal;
      if ( v78->m_WULookup.m_uiBase + v78->m_WULookup.m_Size >= m_uiTotal )
      {
        v65 = v78;
        SoonestPartition = CDistributor_DefaultMaster::FindSoonestPartition(this: v78);
        v67 = SoonestPartition;
        if ( SoonestPartition >= 0 )
        {
          v68 = v78->m_Partitions.m_Memory.m_pMemory;
          pPartition = (CPartitionInfo *)&v78->m_Partitions;
          m_Element = v68[SoonestPartition].m_Element;
          pOldHalf = nullptr;
          pNewHalf = nullptr;
          iOldWorker = m_Element->m_iWorker;
          if ( CDistributor_DefaultMaster::SplitWUsPartition(
                 this: v78,
                 pPartitionLarge: m_Element,
                 ppFirstHalf: &pOldHalf,
                 ppSecondHalf: &pNewHalf,
                 iFirstHalfWorker: (CPartitionInfo *)iOldWorker,
                 iSecondHalfWorker: iWorker) != 0 )
          {
            if ( pOldHalf != nullptr )
              CDistributor_DefaultMaster::SendPartitionToWorker(this: v65, pPartition: pOldHalf, iWorker: iOldWorker);
            if ( pNewHalf != nullptr )
              CDistributor_DefaultMaster::SendPartitionToWorker(this: v65, pPartition: pNewHalf, iWorker);
            CPartitionInfo::`scalar deleting destructor'(this: m_Element, a2: 1u);
            CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::Remove(
              this: (CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int> > *)pPartition,
              elem: v67);
          }
        }
      }
      else
      {
        LODWORD(m_uiTotal) = s_numWusToDeal;
        if ( s_numWusToDeal <= 0 )
        {
          LODWORD(m_uiTotal) = __PAIR64__(HIDWORD(m_uiTotal), iEnd) / g_nMaxWorkerCount;
          if ( (int)m_uiTotal <= 0 )
            LODWORD(m_uiTotal) = 8;
        }
        iBegin = v78->m_WULookup.m_uiBase + v78->m_WULookup.m_Size;
        v36 = __PAIR64__(v35, i) + (int)m_uiTotal * g_nMaxWorkerCount;
        if ( v36 >= __PAIR64__(HIDWORD(m_uiTotal), iEnd) )
          v36 = v78->m_WULookup.m_uiTotal;
        v37 = v36;
        iEnda = v36;
        if ( v36 - 1 >= __PAIR64__(v35, i) )
          CUtlVector<CWULookupInfo,CUtlMemory<CWULookupInfo,int>>::InsertMultipleBefore(
            this: &v78->m_WULookup,
            elem: v78->m_WULookup.m_Size,
            num: v36 - v78->m_WULookup.m_Size - LODWORD(v78->m_WULookup.m_uiBase));
        v38 = v37;
        v39 = g_nMaxWorkerCount;
        if ( __PAIR64__(HIDWORD(iEnda), v38) - iBegin >= g_nMaxWorkerCount )
        {
          pOldHalf = (CPartitionInfo *)g_nMaxWorkerCount;
        }
        else
        {
          v39 = v38 - iBegin;
          pOldHalf = (CPartitionInfo *)(v38 - iBegin);
        }
        v41 = v78;
        iOldWorker = (int)MemAlloc_Alloc(nSize: (unsigned __int64)v39 >> 30 != 0 ? -1 : 4 * v39);
        *(_DWORD *)iOldWorker = CDistributor_DefaultMaster::AddPartition(this: v78, iWorker);
        v42 = 1;
        if ( v39 > 1 )
        {
          pPartition = (CPartitionInfo *)&v41->m_Partitions;
          do
          {
            v43 = (CPartitionInfo *)MemAlloc_Alloc(nSize: 0x30u);
            if ( v43 != nullptr )
            {
              v43->m_WUs.m_Memory.m_pMemory = nullptr;
              v43->m_WUs.m_Memory.m_nAllocationCount = 0;
              v43->m_WUs.m_Memory.m_nGrowSize = 0;
              v43->m_WUs.m_LastAlloc.index = -1;
              v43->m_WUs.m_ElementCount = 0;
              v43->m_WUs.m_NumAlloced = 0;
              v44 = v43->m_WUs.m_Memory.m_pMemory;
              v43->m_WUs.m_Head = -1;
              v43->m_WUs.m_Tail = -1;
              v43->m_WUs.m_FirstFree = -1;
              v43->m_WUs.m_pElements = v44;
              v45 = v43;
            }
            else
            {
              v45 = nullptr;
            }
            pNewHalf = v45;
            v45->m_iPartition = CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::AddToTail(
                                  this: (CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int> > *)pPartition,
                                  src: &pNewHalf);
            v46 = iOldWorker;
            v45->m_iWorker = -1;
            *(_DWORD *)(v46 + 4 * v42++) = v45;
          }
          while ( v42 < v39 );
        }
        HIDWORD(v47) = HIDWORD(iBegin);
        if ( iBegin < iEnda )
        {
          do
          {
            LODWORD(v47) = i;
            v48 = *(_DWORD *)(iOldWorker + 4 * ((v47 - iBegin) % (unsigned int)pOldHalf));
            LODWORD(v47) = HIDWORD(v78->m_WULookup.m_uiBase);
            v49 = v78->m_WULookup.m_uiBase;
            pNewHalf = (CPartitionInfo *)&v78->m_WULookup;
            if ( __PAIR64__(HIDWORD(v47), i) < __PAIR64__(v47, v49)
              || __PAIR64__(HIDWORD(v47), i) >= __PAIR64__(v47, v49) + v78->m_WULookup.m_Size )
            {
              pPartition = nullptr;
            }
            else
            {
              pPartition = (CPartitionInfo *)(pNewHalf->m_iPartition + 12 * (i - pNewHalf->m_WUs.m_Tail));
            }
            pPartition->m_iWorker = *(_DWORD *)v48;
            v50 = CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::AllocInternal(
                    this: (CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *)(v48 + 8),
                    multilist: false);
            v51 = v50;
            if ( v50 == -1 )
            {
              v51 = -1;
            }
            else
            {
              CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
                this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)(v48 + 8),
                elem: v50);
              v52 = *(_DWORD *)(v48 + 8);
              v53 = 16 * v51;
              *(_DWORD *)(v52 + v53 + 12) = -1;
              v54 = *(_DWORD *)(v48 + 24);
              *(_DWORD *)(v52 + v53 + 8) = v54;
              *(_DWORD *)(v48 + 24) = v51;
              if ( v54 == -1 )
                *(_DWORD *)(v48 + 20) = v51;
              else
                *(_DWORD *)(*(_DWORD *)(v48 + 8) + 16 * v54 + 12) = v51;
              ++*(_DWORD *)(v48 + 32);
              v55 = (int *)(v53 + *(_DWORD *)(v48 + 8));
              if ( v55 != nullptr )
              {
                *v55 = i;
                v55[1] = HIDWORD(v47);
              }
            }
            pPartition->m_WUs.m_Memory.m_pMemory = (UtlLinkedListElem_t<unsigned __int64,int> *)v51;
            v56 = v78;
            v57 = CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::AllocInternal(
                    this: &v78->m_WUInfo,
                    multilist: false);
            v58 = v57;
            if ( v57 == -1 )
            {
              v58 = -1;
            }
            else
            {
              CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
                this: &v56->m_WUInfo,
                elem: v57);
              v59 = v56->m_WUInfo.m_Memory.m_pMemory;
              v60 = v58;
              v59[v60].m_Next = -1;
              v61 = v56->m_WUInfo.m_Tail;
              v59[v60].m_Previous = v61;
              v56->m_WUInfo.m_Tail = v58;
              if ( v61 == -1 )
                v56->m_WUInfo.m_Head = v58;
              else
                v56->m_WUInfo.m_Memory.m_pMemory[v61].m_Next = v58;
              ++v56->m_WUInfo.m_ElementCount;
              v62 = &v56->m_WUInfo.m_Memory.m_pMemory[v60];
              if ( v62 != nullptr )
              {
                LODWORD(v62->m_Element.m_iWorkUnit) = i;
                HIDWORD(v62->m_Element.m_iWorkUnit) = HIDWORD(v47);
              }
            }
            v63 = i++;
            pPartition->m_iPartition = v58;
            HIDWORD(v47) = (__PAIR64__(HIDWORD(v47), v63) + 1) >> 32;
          }
          while ( __PAIR64__(HIDWORD(v47), i) < iEnda );
        }
        v64 = (void *)iOldWorker;
        CDistributor_DefaultMaster::SendPartitionToWorker(
          this: v78,
          pPartition: *(CPartitionInfo **)iOldWorker,
          iWorker);
        free(pMem: v64);
        free(pMem: nullptr);
      }
    }
    else
    {
      v33 = v3->m_Partitions.m_Memory.m_pMemory;
      while ( v33[m_Next].m_Element->m_iWorker != -1 )
      {
        m_Next = v33[m_Next].m_Next;
        if ( m_Next == -1 )
          goto LABEL_45;
      }
      v40 = v33[m_Next].m_Element;
      v40->m_iWorker = iWorker;
      CDistributor_DefaultMaster::SendPartitionToWorker(this: v3, pPartition: v40, iWorker);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100953C0
// Name: public: virtual void CDistributor_DefaultMaster::OnWorkerReady(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::OnWorkerReady(CDistributor_DefaultMaster *this, int iSource)
{
  CDistributor_DefaultMaster::AssignWUsToWorker(this, iWorker: iSource);
}

//------------------------------------------------------------------------------
// Address: 0x100953D0
// Name: public: virtual bool CDistributor_DefaultMaster::HandleWorkUnitResults(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_DefaultMaster::HandleWorkUnitResults(
        CDistributor_DefaultMaster *this,
        unsigned __int64 iWorkUnit)
{
  CVisibleWindowVector<CWULookupInfo> *p_m_WULookup; // edi
  int *p_m_iWUInfo; // ebx
  UtlLinkedListElem_t<CPartitionInfo *,int> *m_pMemory; // edx
  int v6; // esi
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *p_m_WUs; // ebx
  unsigned int v8; // ecx
  CDistributor_DefaultMaster *v9; // esi
  unsigned int v10; // eax
  unsigned int v11; // edx
  CWULookupInfo *v12; // esi
  void *v13; // edi
  __int64 v14; // rax
  unsigned __int64 v16; // [esp+14h] [ebp-18h]
  int iPartition; // [esp+20h] [ebp-Ch]
  int iPartitionWorker; // [esp+24h] [ebp-8h]
  int iPartitionWorkera; // [esp+24h] [ebp-8h]
  int iPartitionWorkerb; // [esp+24h] [ebp-8h]

  if ( iWorkUnit < this->m_WULookup.m_uiBase )
    return 0;
  p_m_WULookup = &this->m_WULookup;
  if ( iWorkUnit >= this->m_WULookup.m_uiBase + this->m_WULookup.m_Size )
    return 0;
  if ( iWorkUnit < this->m_WULookup.m_uiBase )
    return 0;
  p_m_iWUInfo = &p_m_WULookup->m_Memory.m_pMemory[iWorkUnit - LODWORD(this->m_WULookup.m_uiBase)].m_iWUInfo;
  if ( p_m_iWUInfo == nullptr )
    return 0;
  iPartitionWorker = *p_m_iWUInfo;
  if ( *p_m_iWUInfo == -1 )
    return 0;
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
    this: &this->m_WUInfo,
    elem: *p_m_iWUInfo);
  this->m_WUInfo.m_Memory.m_pMemory[iPartitionWorker].m_Next = this->m_WUInfo.m_FirstFree;
  this->m_WUInfo.m_FirstFree = iPartitionWorker;
  iPartition = p_m_iWUInfo[1];
  *p_m_iWUInfo = -1;
  m_pMemory = this->m_Partitions.m_Memory.m_pMemory;
  v6 = p_m_iWUInfo[2];
  p_m_WUs = (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&m_pMemory[iPartition].m_Element->m_WUs;
  iPartitionWorkera = (int)m_pMemory[iPartition].m_Element;
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
    this: p_m_WUs,
    elem: v6);
  p_m_WUs->m_Memory.m_pMemory[v6].m_Next = p_m_WUs->m_FirstFree;
  v8 = iWorkUnit;
  p_m_WUs->m_FirstFree = v6;
  v9 = this;
  if ( iWorkUnit == this->m_WULookup.m_uiBase )
  {
    v16 = p_m_WULookup->m_uiBase + p_m_WULookup->m_Size;
    v10 = HIDWORD(v16);
    if ( iWorkUnit >= v16 )
    {
      v11 = HIDWORD(iWorkUnit);
    }
    else
    {
      v11 = HIDWORD(iWorkUnit);
      do
      {
        if ( __PAIR64__(v11, v8) < p_m_WULookup->m_uiBase || v11 > v10 || v11 >= v10 && v8 >= (unsigned int)v16 )
        {
          v12 = nullptr;
        }
        else
        {
          v12 = &p_m_WULookup->m_Memory.m_pMemory[v8 - LODWORD(p_m_WULookup->m_uiBase)];
          v10 = HIDWORD(v16);
        }
        if ( v12->m_iWUInfo != -1 && __PAIR64__(v11, v8) > iWorkUnit )
          break;
        v11 = (__PAIR64__(v11, v8++) + 1) >> 32;
      }
      while ( __PAIR64__(v11, v8) < __PAIR64__(v10, v16) );
    }
    CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo>>::ShrinkWindow(
      this: p_m_WULookup,
      idxDrop: __PAIR64__(v11, v8) - 1);
    v9 = this;
  }
  v13 = (void *)iPartitionWorkera;
  if ( *(_DWORD *)(iPartitionWorkera + 32) == 0 )
  {
    iPartitionWorkerb = *(_DWORD *)(iPartitionWorkera + 4);
    CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::RemoveAll(this: p_m_WUs);
    if ( p_m_WUs->m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_WUs->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_WUs->m_Memory.m_pMemory);
        p_m_WUs->m_Memory.m_pMemory = nullptr;
      }
      p_m_WUs->m_Memory.m_nAllocationCount = 0;
    }
    free(pMem: v13);
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&v9->m_Partitions,
      elem: iPartition);
    v9->m_Partitions.m_Memory.m_pMemory[iPartition].m_Next = v9->m_Partitions.m_FirstFree;
    v9->m_Partitions.m_FirstFree = iPartition;
    if ( v9->m_WULookup.m_uiBase < v9->m_WULookup.m_uiTotal )
      CDistributor_DefaultMaster::AssignWUsToWorker(this: v9, iWorker: iPartitionWorkerb);
  }
  LODWORD(v14) = CWorkUnitsTracker::WorkUnitFinished(this: &g_MasterWorkUnitsTracker, iWorkUnit);
  if ( v14 != 0 && g_pDistributeWorkCallbacks != nullptr )
    ((void (__thiscall *)(IWorkUnitDistributorCallbacks *, _DWORD, _DWORD))g_pDistributeWorkCallbacks->OnWorkUnitsCompleted)(
      a1: g_pDistributeWorkCallbacks,
      a2: v14,
      a3: HIDWORD(v14));
  return 1;
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x100315A0
// Name: public: virtual void CDistributor_DefaultWorker::Init(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultWorker::Init(CDistributor_DefaultWorker *this, CDSInfo *pInfo)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10031850
// Name: public: void CWorkUnitsTracker::PrepareForWorkUnits(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkUnitsTracker::PrepareForWorkUnits(CWorkUnitsTracker *this, unsigned __int64 numUnits)
{
  int v2; // ebx

  v2 = HIDWORD(numUnits);
  CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::Reset(
    this: &this->m_arrInfo,
    uiTotal: numUnits + 1);
  if ( (v2 | (unsigned int)numUnits) != 0 )
  {
    HIBYTE(numUnits) = 0;
    CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ExpandWindow(
      this: &this->m_arrInfo,
      idxAccessible: 2u,
      x: (const unsigned __int8 *)&numUnits + 7);
    if ( HIDWORD(this->m_arrInfo.m_uiBase) != 0 || LODWORD(this->m_arrInfo.m_uiBase) != 0 || this->m_arrInfo.m_Size == 0 )
      MEMORY[0] = 1;
    else
      *this->m_arrInfo.m_Memory.m_pMemory = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100318D0
// Name: public: unsigned __int64 CWorkUnitsTracker::WorkUnitFinished(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWorkUnitsTracker::WorkUnitFinished(CWorkUnitsTracker *this, unsigned __int64 iWorkUnit)
{
  __int64 v2; // rcx
  unsigned int v4; // esi
  unsigned __int8 *v5; // eax
  unsigned __int8 v6; // cl
  unsigned __int64 v7; // rax
  unsigned int v8; // kr00_4
  unsigned __int8 *v9; // eax
  bool v10; // zf
  unsigned __int8 *v11; // eax
  unsigned int v13; // kr10_4
  unsigned __int8 *v14; // eax
  unsigned __int64 v15; // [esp-Ch] [ebp-1Ch]

  HIDWORD(v2) = HIDWORD(iWorkUnit);
  if ( HIDWORD(iWorkUnit) < HIDWORD(this->m_arrInfo.m_uiBase) )
    return 0;
  v4 = iWorkUnit;
  if ( HIDWORD(iWorkUnit) <= HIDWORD(this->m_arrInfo.m_uiBase)
    && (unsigned int)iWorkUnit < LODWORD(this->m_arrInfo.m_uiBase) )
  {
    return 0;
  }
  if ( iWorkUnit >= this->m_arrInfo.m_uiTotal )
    return 0;
  LODWORD(v2) = iWorkUnit;
  HIBYTE(iWorkUnit) = 0;
  CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ExpandWindow(
    this: &this->m_arrInfo,
    idxAccessible: v2 + 1,
    x: (const unsigned __int8 *)&iWorkUnit + 7);
  if ( __PAIR64__(HIDWORD(v2), iWorkUnit) < this->m_arrInfo.m_uiBase
    || __PAIR64__(HIDWORD(v2), iWorkUnit) >= this->m_arrInfo.m_uiBase + this->m_arrInfo.m_Size )
  {
    v5 = nullptr;
  }
  else
  {
    v5 = &this->m_arrInfo.m_Memory.m_pMemory[iWorkUnit - LODWORD(this->m_arrInfo.m_uiBase)];
  }
  v6 = *v5;
  *v5 = 2;
  if ( v6 != 1 )
  {
    if ( __PAIR64__(HIDWORD(v2), iWorkUnit) == this->m_arrInfo.m_uiBase )
    {
      do
      {
        v13 = v4 + 1;
        HIDWORD(v2) = (__PAIR64__(HIDWORD(v2), v4) + 1) >> 32;
        v4 = v13;
        if ( __PAIR64__(HIDWORD(v2), v13) >= this->m_arrInfo.m_uiBase + this->m_arrInfo.m_Size )
          break;
        v14 = __PAIR64__(HIDWORD(v2), v13) < this->m_arrInfo.m_uiBase
            ? nullptr
            : &this->m_arrInfo.m_Memory.m_pMemory[v13 - LODWORD(this->m_arrInfo.m_uiBase)];
      }
      while ( *v14 == 2 );
      CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ShrinkWindow(
        this: &this->m_arrInfo,
        idxDrop: __PAIR64__(HIDWORD(v2), v13) - 1);
    }
    return 0;
  }
  LODWORD(v2) = HIDWORD(this->m_arrInfo.m_uiBase);
  v7 = this->m_arrInfo.m_uiBase + this->m_arrInfo.m_Size;
  do
  {
    v8 = v4 + 1;
    HIDWORD(v2) = (__PAIR64__(HIDWORD(v2), v4) + 1) >> 32;
    v4 = v8;
    if ( __PAIR64__(HIDWORD(v2), v8) >= v7 )
      break;
    v9 = __PAIR64__(HIDWORD(v2), v8) < this->m_arrInfo.m_uiBase
       ? nullptr
       : &this->m_arrInfo.m_Memory.m_pMemory[v8 - LODWORD(this->m_arrInfo.m_uiBase)];
    v10 = *v9 == 2;
    LODWORD(v7) = LODWORD(this->m_arrInfo.m_uiBase) + this->m_arrInfo.m_Size;
  }
  while ( v10 );
  if ( HIDWORD(v2) < (unsigned int)v2
    || HIDWORD(v2) <= (unsigned int)v2 && v8 < LODWORD(this->m_arrInfo.m_uiBase)
    || __PAIR64__(HIDWORD(v2), v8) >= v7 )
  {
    v11 = nullptr;
  }
  else
  {
    v11 = &this->m_arrInfo.m_Memory.m_pMemory[v8 - LODWORD(this->m_arrInfo.m_uiBase)];
  }
  *v11 = 1;
  HIDWORD(v15) = (v8 != 0) + HIDWORD(v2) - 1;
  LODWORD(v15) = v8 - 1;
  CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ShrinkWindow(
    this: &this->m_arrInfo,
    idxDrop: v15);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10031A50
// Name: class IWorkUnitDistributorWorker __near * CreateWUDistributor_DefaultWorker(void)
// Source: json
//------------------------------------------------------------------------------
IWorkUnitDistributorWorker *__cdecl CreateWUDistributor_DefaultWorker()
{
  char *v0; // eax
  _DWORD *v1; // esi
  int v2; // eax

  v0 = (char *)operator new(size: 0x84u);
  v1 = v0;
  if ( v0 == nullptr )
    return nullptr;
  *(_DWORD *)v0 = &CDistributor_DefaultWorker::`vftable';
  CCriticalSection::CCriticalSection(this: (CCriticalSection *)(v0 + 4));
  v1[23] = 0;
  v1[24] = 0;
  v1[25] = 0;
  v1[31] = -1;
  v1[26] = -1;
  v1[27] = -1;
  v1[28] = -1;
  v2 = v1[23];
  v1[29] = 0;
  v1[30] = 0;
  v1[32] = v2;
  return (IWorkUnitDistributorWorker *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x10031AB0
// Name: public: virtual void CDistributor_DefaultWorker::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultWorker::Release(CDistributor_DefaultWorker *this)
{
  if ( this != nullptr )
  {
    CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::RemoveAll(this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&this->m_WorkUnits);
    if ( this->m_WorkUnits.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_WorkUnits.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WorkUnits.m_Memory.m_pMemory);
        this->m_WorkUnits.m_Memory.m_pMemory = nullptr;
      }
      this->m_WorkUnits.m_Memory.m_nAllocationCount = 0;
    }
    CCriticalSection::~CCriticalSection(this: &this->m_CS);
    operator delete(p: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031B00
// Name: public: virtual bool CDistributor_DefaultWorker::GetNextWorkUnit(unsigned __int64 __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_DefaultWorker::GetNextWorkUnit(
        CDistributor_DefaultWorker *this,
        unsigned __int64 *pWUIndex)
{
  UtlLinkedListElem_t<unsigned __int64,int> *m_pMemory; // ecx
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *p_m_WorkUnits; // esi
  int m_Head; // eax
  int v7; // edi
  CCriticalSectionLock csLock; // [esp+4h] [ebp-8h] BYREF

  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  if ( this->m_WorkUnits.m_ElementCount != 0 )
  {
    m_pMemory = this->m_WorkUnits.m_Memory.m_pMemory;
    p_m_WorkUnits = (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&this->m_WorkUnits;
    m_Head = this->m_WorkUnits.m_Head;
    *(_DWORD *)pWUIndex = m_pMemory[this->m_WorkUnits.m_Head].m_Element;
    *((_DWORD *)pWUIndex + 1) = HIDWORD(m_pMemory[m_Head].m_Element);
    v7 = this->m_WorkUnits.m_Head;
    CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
      this: p_m_WorkUnits,
      elem: v7);
    p_m_WorkUnits->m_Memory.m_pMemory[v7].m_Next = p_m_WorkUnits->m_FirstFree;
    p_m_WorkUnits->m_FirstFree = v7;
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 1;
  }
  else
  {
    CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031B80
// Name: public: CDistributor_DefaultMaster::CDistributor_DefaultMaster(void)
// Source: json
//------------------------------------------------------------------------------
CDistributor_DefaultMaster *__thiscall CDistributor_DefaultMaster::CDistributor_DefaultMaster(
        CDistributor_DefaultMaster *this)
{
  CDistributor_DefaultMaster *result; // eax
  UtlLinkedListElem_t<CWorkUnitInfo,int> *m_pMemory; // ecx

  result = this;
  this->__vftable = (CDistributor_DefaultMaster_vtbl *)&CDistributor_DefaultMaster::`vftable';
  this->m_Partitions.m_Memory.m_pMemory = nullptr;
  this->m_Partitions.m_Memory.m_nAllocationCount = 0;
  this->m_Partitions.m_Memory.m_nGrowSize = 0;
  this->m_Partitions.m_LastAlloc.index = -1;
  this->m_Partitions.m_Head = -1;
  this->m_Partitions.m_Tail = -1;
  this->m_Partitions.m_FirstFree = -1;
  this->m_Partitions.m_ElementCount = 0;
  this->m_Partitions.m_NumAlloced = 0;
  this->m_Partitions.m_pElements = this->m_Partitions.m_Memory.m_pMemory;
  this->m_WULookup.m_Memory.m_pMemory = nullptr;
  this->m_WULookup.m_Memory.m_nAllocationCount = 0;
  this->m_WULookup.m_Memory.m_nGrowSize = 0;
  this->m_WULookup.m_Size = 0;
  this->m_WULookup.m_pElements = nullptr;
  this->m_WULookup.m_uiBase = 0;
  this->m_WULookup.m_uiTotal = 0;
  this->m_WUInfo.m_Memory.m_pMemory = nullptr;
  this->m_WUInfo.m_Memory.m_nAllocationCount = 0;
  this->m_WUInfo.m_Memory.m_nGrowSize = 0;
  this->m_WUInfo.m_LastAlloc.index = -1;
  this->m_WUInfo.m_ElementCount = 0;
  this->m_WUInfo.m_NumAlloced = 0;
  m_pMemory = this->m_WUInfo.m_Memory.m_pMemory;
  result->m_WUInfo.m_Head = -1;
  result->m_WUInfo.m_Tail = -1;
  result->m_WUInfo.m_FirstFree = -1;
  result->m_WUInfo.m_pElements = m_pMemory;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10031BF0
// Name: public: virtual bool CDistributor_DefaultMaster::HandlePacket(class MessageBuffer __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDistributor_DefaultMaster::HandlePacket(
        CDistributor_DefaultMaster *this,
        MessageBuffer *pBuf,
        MessageBuffer *iSource,
        bool bIgnoreContents)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10031C00
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlLinkedList<unsigned __int64,int,0,int,class CUtlMemory<struct UtlLinkedListElem_t<unsigned __int64,int>,int>> __near *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100323C0
// Name: CompareSoonestWorkUnitSets
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CompareSoonestWorkUnitSets(
        CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *const *x,
        CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *const *y)
{
  int *v2; // edx
  int m_Head; // eax
  unsigned int v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // ebx
  int v7; // ecx
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  unsigned __int64 jobsX[4]; // [esp+Ch] [ebp-40h] BYREF
  unsigned __int64 jobsY[4]; // [esp+2Ch] [ebp-20h] BYREF

  v2 = (int *)*x;
  m_Head = (*x)->m_Head;
  v4 = -1;
  v5 = -1;
  v6 = -1;
  v7 = 0;
  memset(jobsX, 255, 16);
  jobsX[3] = -1;
  memset(jobsY, 255, 16);
  jobsY[3] = -1;
  if ( m_Head != -1 )
  {
    v8 = *v2;
    do
    {
      v9 = 2 * m_Head;
      LODWORD(jobsX[v7]) = *(_DWORD *)(v8 + 8 * v9);
      HIDWORD(jobsX[v7++]) = *(_DWORD *)(v8 + 8 * v9 + 4);
      if ( v7 >= 4 )
        break;
      m_Head = *(_DWORD *)(v8 + 8 * v9 + 12);
    }
    while ( m_Head != -1 );
    v5 = HIDWORD(jobsX[3]);
  }
  v10 = (*y)->m_Head;
  v11 = 0;
  if ( v10 != -1 )
  {
    v12 = **(_DWORD **)y;
    do
    {
      v13 = 2 * v10;
      LODWORD(jobsY[v11]) = *(_DWORD *)(v12 + 8 * v13);
      HIDWORD(jobsY[v11++]) = *(_DWORD *)(v12 + 8 * v13 + 4);
      if ( v11 >= 4 )
        break;
      v10 = *(_DWORD *)(v12 + 8 * v13 + 12);
    }
    while ( v10 != -1 );
    v4 = HIDWORD(jobsY[3]);
    v6 = jobsY[3];
  }
  if ( LODWORD(jobsX[3]) != v6 || v5 != v4 )
  {
    if ( v5 > v4 )
      return false;
    if ( v5 >= v4 )
      return LODWORD(jobsX[3]) < v6;
    return true;
  }
  if ( jobsX[1] == jobsY[1] )
  {
    if ( HIDWORD(jobsX[0]) > HIDWORD(jobsY[0]) )
      return false;
    if ( HIDWORD(jobsX[0]) < HIDWORD(jobsY[0]) )
      return true;
    return LODWORD(jobsX[0]) < LODWORD(jobsY[0]);
  }
  else
  {
    if ( HIDWORD(jobsX[1]) > HIDWORD(jobsY[1]) )
      return false;
    if ( HIDWORD(jobsX[1]) < HIDWORD(jobsY[1]) )
      return true;
    return LODWORD(jobsX[1]) < LODWORD(jobsY[1]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100324D0
// Name: public: void CDistributor_DefaultMaster::SendPartitionToWorker(class CPartitionInfo __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::SendPartitionToWorker(
        CDistributor_DefaultMaster *this,
        CPartitionInfo *pPartition,
        int iWorker)
{
  int m_Head; // esi
  UtlLinkedListElem_t<unsigned __int64,int> *m_pMemory; // eax
  int v5; // esi
  int Name; // eax
  MessageBuffer mb; // [esp+Ch] [ebp-18h] BYREF
  unsigned __int64 iWU; // [esp+1Ch] [ebp-8h] BYREF

  MessageBuffer::MessageBuffer(this: &mb);
  PrepareDistributeWorkHeader(pBuf: &mb, cSubpacketID: 0x32u);
  m_Head = pPartition->m_WUs.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = pPartition->m_WUs.m_Memory.m_pMemory;
    do
    {
      v5 = m_Head;
      iWU = m_pMemory[v5].m_Element;
      MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&iWU, bytes: 8u);
      VMPITracker_WorkUnitSentToWorker(iWorkUnit: iWU, iWorker);
      m_pMemory = pPartition->m_WUs.m_Memory.m_pMemory;
      m_Head = m_pMemory[v5].m_Next;
    }
    while ( m_Head != -1 );
  }
  Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  VMPI_SendData(pData: mb.data, nBytes: Name, iDest: iWorker, fVMPISendFlags: 0);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x10032EC0
// Name: public: virtual void CDistributor_DefaultMaster::DisconnectHandler(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::DisconnectHandler(CDistributor_DefaultMaster *this, int workerID)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CPartitionInfo *,int> *m_pMemory; // edx

  m_Head = this->m_Partitions.m_Head;
  if ( m_Head != -1 )
  {
    m_pMemory = this->m_Partitions.m_Memory.m_pMemory;
    while ( m_pMemory[m_Head].m_Element->m_iWorker != workerID )
    {
      m_Head = m_pMemory[m_Head].m_Next;
      if ( m_Head == -1 )
        return;
    }
    m_pMemory[m_Head].m_Element->m_iWorker = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032F10
// Name: public: virtual void CDistributor_DefaultMaster::DistributeWork_Master(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::DistributeWork_Master(CDistributor_DefaultMaster *this, CDSInfo *pInfo)
{
  this->m_pInfo = pInfo;
  CWorkUnitsTracker::PrepareForWorkUnits(this: &g_MasterWorkUnitsTracker, numUnits: pInfo->m_nWorkUnits);
  CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo>>::Reset(
    this: &this->m_WULookup,
    uiTotal: pInfo->m_nWorkUnits);
  if ( this->m_WULookup.m_uiBase < this->m_WULookup.m_uiTotal )
  {
    do
    {
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xC8);
      VMPITracker_HandleDebugKeypresses();
    }
    while ( (g_pDistributeWorkCallbacks == nullptr
          || g_pDistributeWorkCallbacks->Update(this: g_pDistributeWorkCallbacks) == 0)
         && this->m_WULookup.m_uiBase < this->m_WULookup.m_uiTotal );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033030
// Name: public: CDistributor_DefaultMaster::~CDistributor_DefaultMaster(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::~CDistributor_DefaultMaster(CDistributor_DefaultMaster *this)
{
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::RemoveAll(this: &this->m_WUInfo);
  if ( this->m_WUInfo.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_WUInfo.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_WUInfo.m_Memory.m_pMemory);
      this->m_WUInfo.m_Memory.m_pMemory = nullptr;
    }
    this->m_WUInfo.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&this->m_WULookup);
  CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::RemoveAll(this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&this->m_Partitions);
  if ( this->m_Partitions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Partitions.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Partitions.m_Memory.m_pMemory);
      this->m_Partitions.m_Memory.m_pMemory = nullptr;
    }
    this->m_Partitions.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033190
// Name: public: class CPartitionInfo __near * CDistributor_DefaultMaster::AddPartition(int)
// Source: json
//------------------------------------------------------------------------------
CPartitionInfo *__thiscall CDistributor_DefaultMaster::AddPartition(CDistributor_DefaultMaster *this, int iWorker)
{
  CPartitionInfo *v3; // eax
  CPartitionInfo *v4; // esi
  UtlLinkedListElem_t<unsigned __int64,int> *m_pMemory; // ecx
  CPartitionInfo *pNew; // [esp+8h] [ebp-4h] BYREF

  v3 = (CPartitionInfo *)operator new(size: 0x30u);
  v4 = nullptr;
  if ( v3 != nullptr )
  {
    v3->m_WUs.m_Memory.m_pMemory = nullptr;
    v3->m_WUs.m_Memory.m_nAllocationCount = 0;
    v3->m_WUs.m_Memory.m_nGrowSize = 0;
    v3->m_WUs.m_LastAlloc.index = -1;
    v3->m_WUs.m_Head = -1;
    v3->m_WUs.m_Tail = -1;
    v3->m_WUs.m_FirstFree = -1;
    m_pMemory = v3->m_WUs.m_Memory.m_pMemory;
    v3->m_WUs.m_ElementCount = 0;
    v3->m_WUs.m_NumAlloced = 0;
    v3->m_WUs.m_pElements = m_pMemory;
    v4 = v3;
  }
  pNew = v4;
  v4->m_iPartition = CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::AddToTail(
                       this: &this->m_Partitions,
                       src: &pNew);
  v4->m_iWorker = iWorker;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100331F0
// Name: public: bool CDistributor_DefaultMaster::SplitWUsPartition(class CPartitionInfo __near *,class CPartitionInfo __near * __near *,class CPartitionInfo __near * __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_DefaultMaster::SplitWUsPartition(
        CDistributor_DefaultMaster *this,
        CPartitionInfo *pPartitionLarge,
        CPartitionInfo **ppFirstHalf,
        CPartitionInfo **ppSecondHalf,
        CPartitionInfo *iFirstHalfWorker,
        int iSecondHalfWorker)
{
  int m_ElementCount; // eax
  CDistributor_DefaultMaster *v8; // ebx
  CPartitionInfo *v9; // eax
  int m_Head; // esi
  UtlLinkedListElem_t<unsigned __int64,int> *m_pMemory; // ecx
  int m_Previous; // edx
  int m_Next; // edx
  unsigned int m_uiBase_high; // ecx
  unsigned int m_uiBase; // esi
  int v16; // eax
  int v17; // ebx
  UtlLinkedListElem_t<unsigned __int64,int> *v18; // eax
  int v19; // edx
  int m_Tail; // ecx
  UtlLinkedListElem_t<unsigned __int64,int> *v21; // esi
  CPartitionInfo *arrNewParts[2]; // [esp+Ch] [ebp-14h]
  unsigned __int64 iWU; // [esp+14h] [ebp-Ch]
  CDistributor_DefaultMaster *v25; // [esp+1Ch] [ebp-4h]
  int nCount; // [esp+28h] [ebp+8h]
  int iHead; // [esp+2Ch] [ebp+Ch]
  CPartitionInfo *pTo; // [esp+34h] [ebp+14h]
  int k; // [esp+38h] [ebp+18h]

  m_ElementCount = pPartitionLarge->m_WUs.m_ElementCount;
  v8 = this;
  v25 = this;
  nCount = m_ElementCount;
  if ( m_ElementCount <= 1 )
  {
    *ppFirstHalf = nullptr;
    v9 = CDistributor_DefaultMaster::AddPartition(this, iWorker: iSecondHalfWorker);
  }
  else
  {
    *ppFirstHalf = CDistributor_DefaultMaster::AddPartition(this, iWorker: (int)iFirstHalfWorker);
    v9 = CDistributor_DefaultMaster::AddPartition(this: v8, iWorker: iSecondHalfWorker);
  }
  *ppSecondHalf = v9;
  if ( *ppFirstHalf != nullptr )
    arrNewParts[0] = *ppFirstHalf;
  else
    arrNewParts[0] = *ppSecondHalf;
  arrNewParts[1] = *ppSecondHalf;
  k = 0;
  if ( nCount > 0 )
  {
    while ( 1 )
    {
      m_Head = pPartitionLarge->m_WUs.m_Head;
      iWU = pPartitionLarge->m_WUs.m_Memory.m_pMemory[m_Head].m_Element;
      if ( m_Head >= 0
        && m_Head < pPartitionLarge->m_WUs.m_Memory.m_nAllocationCount
        && m_Head <= pPartitionLarge->m_WUs.m_LastAlloc.index )
      {
        m_pMemory = pPartitionLarge->m_WUs.m_Memory.m_pMemory;
        if ( m_pMemory[m_Head].m_Previous != m_Head )
        {
          m_Previous = m_pMemory[m_Head].m_Previous;
          if ( m_Previous == -1 )
          {
            pPartitionLarge->m_WUs.m_Head = m_pMemory[m_Head].m_Next;
          }
          else
          {
            m_pMemory[m_Previous].m_Next = m_pMemory[m_Head].m_Next;
            v8 = v25;
          }
          m_Next = m_pMemory[m_Head].m_Next;
          if ( m_Next == -1 )
          {
            pPartitionLarge->m_WUs.m_Tail = m_pMemory[m_Head].m_Previous;
          }
          else
          {
            pPartitionLarge->m_WUs.m_Memory.m_pMemory[m_Next].m_Previous = m_pMemory[m_Head].m_Previous;
            v8 = v25;
          }
          m_pMemory[m_Head].m_Next = m_Head;
          m_pMemory[m_Head].m_Previous = m_Head;
          --pPartitionLarge->m_WUs.m_ElementCount;
        }
      }
      pPartitionLarge->m_WUs.m_Memory.m_pMemory[m_Head].m_Next = pPartitionLarge->m_WUs.m_FirstFree;
      pPartitionLarge->m_WUs.m_FirstFree = m_Head;
      m_uiBase_high = HIDWORD(v8->m_WULookup.m_uiBase);
      m_uiBase = v8->m_WULookup.m_uiBase;
      pTo = arrNewParts[k >= nCount / 2];
      if ( iWU < __PAIR64__(m_uiBase_high, m_uiBase)
        || iWU >= __PAIR64__(m_uiBase_high, m_uiBase) + v8->m_WULookup.m_Size )
      {
        iHead = 0;
      }
      else
      {
        iHead = (int)&v8->m_WULookup.m_Memory.m_pMemory[iWU - m_uiBase];
      }
      *(_DWORD *)(iHead + 4) = pTo->m_iPartition;
      v16 = CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::AllocInternal(
              this: &pTo->m_WUs,
              multilist: false);
      v17 = v16;
      if ( v16 == -1 )
      {
        v17 = -1;
      }
      else
      {
        CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
          this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&pTo->m_WUs,
          elem: v16);
        v18 = pTo->m_WUs.m_Memory.m_pMemory;
        v19 = v17;
        v18[v19].m_Next = -1;
        m_Tail = pTo->m_WUs.m_Tail;
        v18[v19].m_Previous = m_Tail;
        pTo->m_WUs.m_Tail = v17;
        if ( m_Tail == -1 )
          pTo->m_WUs.m_Head = v17;
        else
          pTo->m_WUs.m_Memory.m_pMemory[m_Tail].m_Next = v17;
        ++pTo->m_WUs.m_ElementCount;
        v21 = &pTo->m_WUs.m_Memory.m_pMemory[v19];
        if ( v21 != nullptr )
          v21->m_Element = iWU;
      }
      *(_DWORD *)(iHead + 8) = v17;
      if ( ++k >= nCount )
        break;
      v8 = v25;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100333F0
// Name: public: virtual bool CDistributor_DefaultWorker::HandlePacket(class MessageBuffer __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_DefaultWorker::HandlePacket(
        CDistributor_DefaultWorker *this,
        MessageBuffer *pBuf,
        int iSource,
        bool bIgnoreContents)
{
  char Name; // bl
  CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *p_m_WorkUnits; // ebx
  int v8; // esi
  unsigned int i; // esi
  unsigned __int64 iWU; // [esp+8h] [ebp-10h] BYREF
  CCriticalSectionLock csLock; // [esp+10h] [ebp-8h] BYREF

  if ( pBuf->data[1] != 50 )
    return 0;
  if ( bIgnoreContents )
    return 1;
  Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)pBuf);
  if ( ((Name - (unsigned __int8)MessageBuffer::getOffset(this: (CVMPIFile_Memory *)pBuf)) & 7) != 0 )
    _Error(a1: "DistributeWork: invalid work units packet from master");
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: &this->m_CS);
  CCriticalSectionLock::Lock(this: &csLock);
  p_m_WorkUnits = &this->m_WorkUnits;
  CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::Purge(this: &this->m_WorkUnits);
  v8 = ConCommandBase::GetName(this: (CVMPIFile_Memory *)pBuf);
  for ( i = (unsigned int)(v8 - MessageBuffer::getOffset(this: (CVMPIFile_Memory *)pBuf)) >> 3; i != 0; --i )
  {
    MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&iWU, bytes: 8u);
    CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::AddToTail(
      this: p_m_WorkUnits,
      src: &iWU);
  }
  CCriticalSectionLock::Unlock(this: &csLock);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100334C0
// Name: class IWorkUnitDistributorMaster __near * CreateWUDistributor_DefaultMaster(void)
// Source: json
//------------------------------------------------------------------------------
CDistributor_DefaultMaster *__cdecl CreateWUDistributor_DefaultMaster()
{
  CDistributor_DefaultMaster *v0; // eax

  v0 = (CDistributor_DefaultMaster *)operator new(size: 0x80u);
  if ( v0 != nullptr )
    return CDistributor_DefaultMaster::CDistributor_DefaultMaster(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100334E0
// Name: public: virtual void CDistributor_DefaultMaster::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::Release(CDistributor_DefaultMaster *this)
{
  if ( this != nullptr )
  {
    CDistributor_DefaultMaster::~CDistributor_DefaultMaster(this);
    operator delete(p: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033500
// Name: public: int CDistributor_DefaultMaster::FindSoonestPartition(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDistributor_DefaultMaster::FindSoonestPartition(CDistributor_DefaultMaster *this)
{
  int m_ElementCount; // eax
  IMemAlloc_vtbl *v3; // edx
  int m_Head; // eax
  int v5; // edi
  CPartitionInfo *m_Element; // edx
  int v7; // ecx
  UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int v9; // esi
  CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t *p_m_Data; // esi
  unsigned __int16 Inorder; // ax
  int elem; // esi
  int v14; // ebx
  CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short> sortedPartitions; // [esp+8h] [ebp-2Ch] BYREF
  CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t insert; // [esp+24h] [ebp-10h] BYREF
  unsigned __int16 parent[3]; // [esp+2Ch] [ebp-8h] BYREF
  bool leftchild; // [esp+33h] [ebp-1h] BYREF

  m_ElementCount = this->m_Partitions.m_ElementCount;
  sortedPartitions.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *const *, CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *const *))CompareSoonestWorkUnitSets;
  memset(&sortedPartitions.m_Tree.m_Elements, 0, sizeof(sortedPartitions.m_Tree.m_Elements));
  *(_DWORD *)&sortedPartitions.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&sortedPartitions.m_Tree.m_FirstFree = -1;
  sortedPartitions.m_Tree.m_pElements = nullptr;
  if ( m_ElementCount > 0 )
  {
    v3 = _g_pMemAlloc->__vftable;
    sortedPartitions.m_Tree.m_Elements.m_nAllocationCount = m_ElementCount;
    sortedPartitions.m_Tree.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *,int,unsigned short>::Node_t,unsigned short> *)v3->Alloc_2(this: _g_pMemAlloc, a2: 16 * m_ElementCount);
  }
  m_Head = this->m_Partitions.m_Head;
  if ( m_Head == -1 )
    goto LABEL_17;
  do
  {
    v5 = m_Head;
    m_Element = this->m_Partitions.m_Memory.m_pMemory[m_Head].m_Element;
    insert.elem = m_Head;
    insert.key = &m_Element->m_WUs;
    *(_DWORD *)parent = 0xFFFF;
    leftchild = false;
    CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &sortedPartitions.m_Tree,
      &insert,
      parent,
      &leftchild);
    v7 = (unsigned __int16)CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &sortedPartitions.m_Tree);
    m_pMemory = sortedPartitions.m_Tree.m_Elements.m_pMemory;
    v9 = v7;
    sortedPartitions.m_Tree.m_Elements.m_pMemory[v9].m_Parent = parent[0];
    m_pMemory[v9].m_Right = -1;
    m_pMemory[v9].m_Left = -1;
    m_pMemory[v9].m_Tag = 0;
    if ( parent[0] == 0xFFFF )
    {
      sortedPartitions.m_Tree.m_Root = v7;
    }
    else if ( leftchild )
    {
      m_pMemory[parent[0]].m_Left = v7;
    }
    else
    {
      m_pMemory[parent[0]].m_Right = v7;
    }
    CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
      this: &sortedPartitions.m_Tree,
      elem: v7);
    ++sortedPartitions.m_Tree.m_NumElements;
    p_m_Data = &sortedPartitions.m_Tree.m_Elements.m_pMemory[v9].m_Data;
    if ( p_m_Data != nullptr )
      *p_m_Data = insert;
    m_Head = this->m_Partitions.m_Memory.m_pMemory[v5].m_Next;
  }
  while ( m_Head != -1 );
  if ( sortedPartitions.m_Tree.m_NumElements == 0 )
  {
LABEL_17:
    v14 = this->m_Partitions.m_Head;
    CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &sortedPartitions.m_Tree);
    if ( sortedPartitions.m_Tree.m_Elements.m_nGrowSize >= 0 && sortedPartitions.m_Tree.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sortedPartitions.m_Tree.m_Elements.m_pMemory);
    return v14;
  }
  else
  {
    Inorder = CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &sortedPartitions.m_Tree);
    elem = sortedPartitions.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
    CUtlRBTree<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short,CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>> *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &sortedPartitions.m_Tree);
    if ( sortedPartitions.m_Tree.m_Elements.m_nGrowSize >= 0 && sortedPartitions.m_Tree.m_Elements.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sortedPartitions.m_Tree.m_Elements.m_pMemory);
    return elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100336D0
// Name: public: void CDistributor_DefaultMaster::AssignWUsToWorker(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::AssignWUsToWorker(CDistributor_DefaultMaster *this, int iWorker)
{
  int m_pMemory; // edx
  CDistributor_DefaultMaster *v3; // edi
  int m_Head; // esi
  int v5; // ecx
  int v6; // edi
  int v7; // eax
  unsigned __int64 m_nWorkUnits; // rcx
  CPartitionInfo *v9; // eax
  CDSInfo *m_pInfo; // edi
  bool v11; // zf
  unsigned __int64 v12; // kr08_8
  unsigned int m_uiBase; // edi
  CWULookupInfo *v14; // ebx
  CPartitionInfo *v15; // edi
  CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *p_m_WUs; // ecx
  int v17; // eax
  int v18; // esi
  UtlLinkedListElem_t<unsigned __int64,int> *v19; // eax
  int v20; // edx
  int m_Tail; // ecx
  UtlLinkedListElem_t<unsigned __int64,int> *v22; // edi
  CDistributor_DefaultMaster *v23; // edi
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *p_m_WUInfo; // ecx
  int v25; // eax
  int v26; // esi
  UtlLinkedListElem_t<CWorkUnitInfo,int> *v27; // eax
  int v28; // edx
  int v29; // ecx
  UtlLinkedListElem_t<CWorkUnitInfo,int> *v30; // edi
  unsigned __int64 v31; // rax
  int m_Next; // eax
  UtlLinkedListElem_t<CPartitionInfo *,int> *v33; // edx
  unsigned __int64 m_uiTotal; // rcx
  unsigned int v35; // esi
  unsigned __int64 v36; // rax
  unsigned int v37; // ebx
  unsigned int v38; // esi
  unsigned int v39; // ebx
  CPartitionInfo *v40; // eax
  CDistributor_DefaultMaster *v41; // esi
  unsigned int v42; // edi
  CPartitionInfo *v43; // eax
  UtlLinkedListElem_t<unsigned __int64,int> *v44; // ecx
  CPartitionInfo *v45; // esi
  int v46; // eax
  __int64 v47; // rcx
  int v48; // esi
  unsigned int v49; // edi
  int v50; // eax
  int v51; // edi
  int v52; // eax
  int v53; // edx
  int v54; // ecx
  int *v55; // esi
  CDistributor_DefaultMaster *v56; // edi
  int v57; // eax
  int v58; // esi
  UtlLinkedListElem_t<CWorkUnitInfo,int> *v59; // eax
  int v60; // edx
  int v61; // ecx
  UtlLinkedListElem_t<CWorkUnitInfo,int> *v62; // edi
  int v63; // kr04_4
  void *v64; // esi
  CDistributor_DefaultMaster *v65; // esi
  int SoonestPartition; // eax
  int v67; // ebx
  UtlLinkedListElem_t<CPartitionInfo *,int> *v68; // edx
  CPartitionInfo *m_Element; // edi
  unsigned int iEnd; // [esp+Ch] [ebp-30h]
  unsigned __int64 iEnda; // [esp+Ch] [ebp-30h]
  int i; // [esp+14h] [ebp-28h]
  unsigned __int64 iBegin; // [esp+1Ch] [ebp-20h]
  CPartitionInfo *pOldHalf; // [esp+28h] [ebp-14h] BYREF
  CPartitionInfo *pNewHalf; // [esp+2Ch] [ebp-10h] BYREF
  int iOldWorker; // [esp+30h] [ebp-Ch]
  CPartitionInfo *pPartition; // [esp+34h] [ebp-8h]
  CDistributor_DefaultMaster *v78; // [esp+38h] [ebp-4h]

  m_pMemory = iWorker;
  v3 = this;
  m_Head = this->m_Partitions.m_Head;
  v78 = this;
  if ( m_Head != -1 )
  {
    this = (CDistributor_DefaultMaster *)this->m_Partitions.m_Memory.m_pMemory;
    while ( *(_DWORD *)(*((_DWORD *)&this->__vftable + 3 * m_Head) + 4) != iWorker )
    {
      m_Head = (int)(&this->m_Partitions.m_Memory.m_pMemory)[3 * m_Head];
      if ( m_Head == -1 )
        goto LABEL_13;
    }
    v5 = *((_DWORD *)&this->__vftable + 3 * m_Head);
    iOldWorker = v5;
    if ( v5 != 0 )
    {
      v6 = v5;
      CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::RemoveAll(this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)(v5 + 8));
      if ( *(int *)(v6 + 16) >= 0 )
      {
        if ( *(_DWORD *)(v6 + 8) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v6 + 8));
          *(_DWORD *)(v6 + 8) = 0;
        }
        *(_DWORD *)(v6 + 12) = 0;
      }
      operator delete(p: (void *)iOldWorker);
      v3 = v78;
    }
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&v3->m_Partitions,
      elem: m_Head);
    m_pMemory = (int)v3->m_Partitions.m_Memory.m_pMemory;
    *(_DWORD *)(12 * m_Head + m_pMemory + 8) = v3->m_Partitions.m_FirstFree;
    v3->m_Partitions.m_FirstFree = m_Head;
  }
LABEL_13:
  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "A");
  v7 = _CommandLine(a1: this, a2: m_pMemory);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-mpi_NoScheduler") != 0 )
  {
    _Warning(a1: "\n\n-mpi_NoScheduler found: Warning - this should only be used for testing and with 1 worker!\n\n");
    m_nWorkUnits = v3->m_pInfo->m_nWorkUnits;
    if ( m_nWorkUnits >= v3->m_WULookup.m_uiBase + v3->m_WULookup.m_Size )
      CUtlVector<CWULookupInfo,CUtlMemory<CWULookupInfo,int>>::InsertMultipleBefore(
        this: &v3->m_WULookup,
        elem: v3->m_WULookup.m_Size,
        num: m_nWorkUnits - LODWORD(v3->m_WULookup.m_uiBase) - v3->m_WULookup.m_Size + 1);
    v9 = CDistributor_DefaultMaster::AddPartition(this: v3, iWorker);
    m_pInfo = v3->m_pInfo;
    v11 = HIDWORD(m_pInfo->m_nWorkUnits) == 0;
    pPartition = v9;
    iOldWorker = 0;
    if ( !v11 || LODWORD(m_pInfo->m_nWorkUnits) != 0 )
    {
      v12 = 0;
      do
      {
        m_uiBase = v78->m_WULookup.m_uiBase;
        pOldHalf = (CPartitionInfo *)HIDWORD(v78->m_WULookup.m_uiBase);
        if ( v12 < __PAIR64__((unsigned int)pOldHalf, m_uiBase)
          || v12 >= __PAIR64__((unsigned int)pOldHalf, m_uiBase) + v78->m_WULookup.m_Size )
        {
          v14 = nullptr;
        }
        else
        {
          v14 = &v78->m_WULookup.m_Memory.m_pMemory[v12 - LODWORD(v78->m_WULookup.m_uiBase)];
        }
        v15 = pPartition;
        p_m_WUs = &pPartition->m_WUs;
        v14->m_iPartition = pPartition->m_iPartition;
        v17 = CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::AllocInternal(
                this: p_m_WUs,
                multilist: false);
        v18 = v17;
        if ( v17 == -1 )
        {
          v18 = -1;
        }
        else
        {
          CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
            this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&v15->m_WUs,
            elem: v17);
          v19 = v15->m_WUs.m_Memory.m_pMemory;
          v20 = v18;
          v19[v20].m_Next = -1;
          m_Tail = v15->m_WUs.m_Tail;
          v19[v20].m_Previous = m_Tail;
          v15->m_WUs.m_Tail = v18;
          if ( m_Tail == -1 )
            v15->m_WUs.m_Head = v18;
          else
            v15->m_WUs.m_Memory.m_pMemory[m_Tail].m_Next = v18;
          ++v15->m_WUs.m_ElementCount;
          v22 = &v15->m_WUs.m_Memory.m_pMemory[v20];
          if ( v22 != nullptr )
            v22->m_Element = v12;
        }
        v23 = v78;
        p_m_WUInfo = &v78->m_WUInfo;
        v14->m_iPartitionListIndex = v18;
        v25 = CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::AllocInternal(
                this: p_m_WUInfo,
                multilist: false);
        v26 = v25;
        if ( v25 == -1 )
        {
          v26 = -1;
        }
        else
        {
          CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
            this: &v23->m_WUInfo,
            elem: v25);
          v27 = v23->m_WUInfo.m_Memory.m_pMemory;
          v28 = v26;
          v27[v28].m_Next = -1;
          v29 = v23->m_WUInfo.m_Tail;
          v27[v28].m_Previous = v29;
          v23->m_WUInfo.m_Tail = v26;
          if ( v29 == -1 )
            v23->m_WUInfo.m_Head = v26;
          else
            v23->m_WUInfo.m_Memory.m_pMemory[v29].m_Next = v26;
          ++v23->m_WUInfo.m_ElementCount;
          v30 = &v23->m_WUInfo.m_Memory.m_pMemory[v28];
          if ( v30 != nullptr )
            v30->m_Element.m_iWorkUnit = v12;
        }
        v31 = ++iOldWorker;
        v14->m_iWUInfo = v26;
        v12 = v31;
      }
      while ( v31 < v78->m_pInfo->m_nWorkUnits );
    }
    CDistributor_DefaultMaster::SendPartitionToWorker(this: v78, pPartition, iWorker);
  }
  else
  {
    m_Next = v3->m_Partitions.m_Head;
    if ( m_Next == -1 )
    {
LABEL_45:
      m_uiTotal = v78->m_WULookup.m_uiTotal;
      v35 = (v78->m_WULookup.m_uiBase + v78->m_WULookup.m_Size) >> 32;
      i = LODWORD(v78->m_WULookup.m_uiBase) + v78->m_WULookup.m_Size;
      iEnd = v78->m_WULookup.m_uiTotal;
      if ( v78->m_WULookup.m_uiBase + v78->m_WULookup.m_Size >= m_uiTotal )
      {
        v65 = v78;
        SoonestPartition = CDistributor_DefaultMaster::FindSoonestPartition(this: v78);
        v67 = SoonestPartition;
        if ( SoonestPartition >= 0 )
        {
          v68 = v78->m_Partitions.m_Memory.m_pMemory;
          pPartition = (CPartitionInfo *)&v78->m_Partitions;
          m_Element = v68[SoonestPartition].m_Element;
          pOldHalf = nullptr;
          pNewHalf = nullptr;
          iOldWorker = m_Element->m_iWorker;
          if ( CDistributor_DefaultMaster::SplitWUsPartition(
                 this: v78,
                 pPartitionLarge: m_Element,
                 ppFirstHalf: &pOldHalf,
                 ppSecondHalf: &pNewHalf,
                 iFirstHalfWorker: (CPartitionInfo *)iOldWorker,
                 iSecondHalfWorker: iWorker) != 0 )
          {
            if ( pOldHalf != nullptr )
              CDistributor_DefaultMaster::SendPartitionToWorker(this: v65, pPartition: pOldHalf, iWorker: iOldWorker);
            if ( pNewHalf != nullptr )
              CDistributor_DefaultMaster::SendPartitionToWorker(this: v65, pPartition: pNewHalf, iWorker);
            CPartitionInfo::`scalar deleting destructor'(this: m_Element, a2: 1u);
            CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::Remove(
              this: (CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int> > *)pPartition,
              elem: v67);
          }
        }
      }
      else
      {
        LODWORD(m_uiTotal) = s_numWusToDeal;
        if ( s_numWusToDeal <= 0 )
        {
          LODWORD(m_uiTotal) = __PAIR64__(HIDWORD(m_uiTotal), iEnd) / g_nMaxWorkerCount;
          if ( (int)m_uiTotal <= 0 )
            LODWORD(m_uiTotal) = 8;
        }
        iBegin = v78->m_WULookup.m_uiBase + v78->m_WULookup.m_Size;
        v36 = __PAIR64__(v35, i) + (int)m_uiTotal * g_nMaxWorkerCount;
        if ( v36 >= __PAIR64__(HIDWORD(m_uiTotal), iEnd) )
          v36 = v78->m_WULookup.m_uiTotal;
        v37 = v36;
        iEnda = v36;
        if ( v36 - 1 >= __PAIR64__(v35, i) )
          CUtlVector<CWULookupInfo,CUtlMemory<CWULookupInfo,int>>::InsertMultipleBefore(
            this: &v78->m_WULookup,
            elem: v78->m_WULookup.m_Size,
            num: v36 - v78->m_WULookup.m_Size - LODWORD(v78->m_WULookup.m_uiBase));
        v38 = v37;
        v39 = g_nMaxWorkerCount;
        if ( __PAIR64__(HIDWORD(iEnda), v38) - iBegin >= g_nMaxWorkerCount )
        {
          pOldHalf = (CPartitionInfo *)g_nMaxWorkerCount;
        }
        else
        {
          v39 = v38 - iBegin;
          pOldHalf = (CPartitionInfo *)(v38 - iBegin);
        }
        v41 = v78;
        iOldWorker = (int)operator new(size: 4 * v39);
        *(_DWORD *)iOldWorker = CDistributor_DefaultMaster::AddPartition(this: v78, iWorker);
        v42 = 1;
        if ( v39 > 1 )
        {
          pPartition = (CPartitionInfo *)&v41->m_Partitions;
          do
          {
            v43 = (CPartitionInfo *)operator new(size: 0x30u);
            if ( v43 != nullptr )
            {
              v43->m_WUs.m_Memory.m_pMemory = nullptr;
              v43->m_WUs.m_Memory.m_nAllocationCount = 0;
              v43->m_WUs.m_Memory.m_nGrowSize = 0;
              v43->m_WUs.m_LastAlloc.index = -1;
              v43->m_WUs.m_ElementCount = 0;
              v43->m_WUs.m_NumAlloced = 0;
              v44 = v43->m_WUs.m_Memory.m_pMemory;
              v43->m_WUs.m_Head = -1;
              v43->m_WUs.m_Tail = -1;
              v43->m_WUs.m_FirstFree = -1;
              v43->m_WUs.m_pElements = v44;
              v45 = v43;
            }
            else
            {
              v45 = nullptr;
            }
            pNewHalf = v45;
            v45->m_iPartition = CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int>>::AddToTail(
                                  this: (CUtlLinkedList<CPartitionInfo *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CPartitionInfo *,int>,int> > *)pPartition,
                                  src: &pNewHalf);
            v46 = iOldWorker;
            v45->m_iWorker = -1;
            *(_DWORD *)(v46 + 4 * v42++) = v45;
          }
          while ( v42 < v39 );
        }
        HIDWORD(v47) = HIDWORD(iBegin);
        if ( iBegin < iEnda )
        {
          do
          {
            LODWORD(v47) = i;
            v48 = *(_DWORD *)(iOldWorker + 4 * ((v47 - iBegin) % (unsigned int)pOldHalf));
            LODWORD(v47) = HIDWORD(v78->m_WULookup.m_uiBase);
            v49 = v78->m_WULookup.m_uiBase;
            pNewHalf = (CPartitionInfo *)&v78->m_WULookup;
            if ( __PAIR64__(HIDWORD(v47), i) < __PAIR64__(v47, v49)
              || __PAIR64__(HIDWORD(v47), i) >= __PAIR64__(v47, v49) + v78->m_WULookup.m_Size )
            {
              pPartition = nullptr;
            }
            else
            {
              pPartition = (CPartitionInfo *)(pNewHalf->m_iPartition + 12 * (i - pNewHalf->m_WUs.m_Tail));
            }
            pPartition->m_iWorker = *(_DWORD *)v48;
            v50 = CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int>>::AllocInternal(
                    this: (CUtlLinkedList<unsigned __int64,int,0,int,CUtlMemory<UtlLinkedListElem_t<unsigned __int64,int>,int> > *)(v48 + 8),
                    multilist: false);
            v51 = v50;
            if ( v50 == -1 )
            {
              v51 = -1;
            }
            else
            {
              CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
                this: (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)(v48 + 8),
                elem: v50);
              v52 = *(_DWORD *)(v48 + 8);
              v53 = 16 * v51;
              *(_DWORD *)(v52 + v53 + 12) = -1;
              v54 = *(_DWORD *)(v48 + 24);
              *(_DWORD *)(v52 + v53 + 8) = v54;
              *(_DWORD *)(v48 + 24) = v51;
              if ( v54 == -1 )
                *(_DWORD *)(v48 + 20) = v51;
              else
                *(_DWORD *)(*(_DWORD *)(v48 + 8) + 16 * v54 + 12) = v51;
              ++*(_DWORD *)(v48 + 32);
              v55 = (int *)(v53 + *(_DWORD *)(v48 + 8));
              if ( v55 != nullptr )
              {
                *v55 = i;
                v55[1] = HIDWORD(v47);
              }
            }
            pPartition->m_WUs.m_Memory.m_pMemory = (UtlLinkedListElem_t<unsigned __int64,int> *)v51;
            v56 = v78;
            v57 = CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::AllocInternal(
                    this: &v78->m_WUInfo,
                    multilist: false);
            v58 = v57;
            if ( v57 == -1 )
            {
              v58 = -1;
            }
            else
            {
              CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
                this: &v56->m_WUInfo,
                elem: v57);
              v59 = v56->m_WUInfo.m_Memory.m_pMemory;
              v60 = v58;
              v59[v60].m_Next = -1;
              v61 = v56->m_WUInfo.m_Tail;
              v59[v60].m_Previous = v61;
              v56->m_WUInfo.m_Tail = v58;
              if ( v61 == -1 )
                v56->m_WUInfo.m_Head = v58;
              else
                v56->m_WUInfo.m_Memory.m_pMemory[v61].m_Next = v58;
              ++v56->m_WUInfo.m_ElementCount;
              v62 = &v56->m_WUInfo.m_Memory.m_pMemory[v60];
              if ( v62 != nullptr )
              {
                LODWORD(v62->m_Element.m_iWorkUnit) = i;
                HIDWORD(v62->m_Element.m_iWorkUnit) = HIDWORD(v47);
              }
            }
            v63 = i++;
            pPartition->m_iPartition = v58;
            HIDWORD(v47) = (__PAIR64__(HIDWORD(v47), v63) + 1) >> 32;
          }
          while ( __PAIR64__(HIDWORD(v47), i) < iEnda );
        }
        v64 = (void *)iOldWorker;
        CDistributor_DefaultMaster::SendPartitionToWorker(
          this: v78,
          pPartition: *(CPartitionInfo **)iOldWorker,
          iWorker);
        operator delete(p: v64);
        operator delete(p: nullptr);
      }
    }
    else
    {
      v33 = v3->m_Partitions.m_Memory.m_pMemory;
      while ( v33[m_Next].m_Element->m_iWorker != -1 )
      {
        m_Next = v33[m_Next].m_Next;
        if ( m_Next == -1 )
          goto LABEL_45;
      }
      v40 = v33[m_Next].m_Element;
      v40->m_iWorker = iWorker;
      CDistributor_DefaultMaster::SendPartitionToWorker(this: v3, pPartition: v40, iWorker);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033D80
// Name: public: virtual void CDistributor_DefaultMaster::OnWorkerReady(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDistributor_DefaultMaster::OnWorkerReady(CDistributor_DefaultMaster *this, int iSource)
{
  CDistributor_DefaultMaster::AssignWUsToWorker(this, iWorker: iSource);
}

//------------------------------------------------------------------------------
// Address: 0x10033D90
// Name: public: virtual bool CDistributor_DefaultMaster::HandleWorkUnitResults(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDistributor_DefaultMaster::HandleWorkUnitResults(
        CDistributor_DefaultMaster *this,
        unsigned __int64 iWorkUnit)
{
  CVisibleWindowVector<CWULookupInfo> *p_m_WULookup; // edi
  int *p_m_iWUInfo; // ebx
  UtlLinkedListElem_t<CPartitionInfo *,int> *m_pMemory; // edx
  int v6; // esi
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *p_m_WUs; // ebx
  unsigned int v8; // ecx
  CDistributor_DefaultMaster *v9; // esi
  unsigned int v10; // eax
  unsigned int v11; // edx
  CWULookupInfo *v12; // esi
  void *v13; // edi
  __int64 v14; // rax
  unsigned __int64 v16; // [esp+14h] [ebp-18h]
  int iPartition; // [esp+20h] [ebp-Ch]
  int iPartitionWorker; // [esp+24h] [ebp-8h]
  int iPartitionWorkera; // [esp+24h] [ebp-8h]
  int iPartitionWorkerb; // [esp+24h] [ebp-8h]

  if ( iWorkUnit < this->m_WULookup.m_uiBase )
    return 0;
  p_m_WULookup = &this->m_WULookup;
  if ( iWorkUnit >= this->m_WULookup.m_uiBase + this->m_WULookup.m_Size )
    return 0;
  if ( iWorkUnit < this->m_WULookup.m_uiBase )
    return 0;
  p_m_iWUInfo = &p_m_WULookup->m_Memory.m_pMemory[iWorkUnit - LODWORD(this->m_WULookup.m_uiBase)].m_iWUInfo;
  if ( p_m_iWUInfo == nullptr )
    return 0;
  iPartitionWorker = *p_m_iWUInfo;
  if ( *p_m_iWUInfo == -1 )
    return 0;
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
    this: &this->m_WUInfo,
    elem: *p_m_iWUInfo);
  this->m_WUInfo.m_Memory.m_pMemory[iPartitionWorker].m_Next = this->m_WUInfo.m_FirstFree;
  this->m_WUInfo.m_FirstFree = iPartitionWorker;
  iPartition = p_m_iWUInfo[1];
  *p_m_iWUInfo = -1;
  m_pMemory = this->m_Partitions.m_Memory.m_pMemory;
  v6 = p_m_iWUInfo[2];
  p_m_WUs = (CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int> > *)&m_pMemory[iPartition].m_Element->m_WUs;
  iPartitionWorkera = (int)m_pMemory[iPartition].m_Element;
  CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::Unlink(
    this: p_m_WUs,
    elem: v6);
  p_m_WUs->m_Memory.m_pMemory[v6].m_Next = p_m_WUs->m_FirstFree;
  v8 = iWorkUnit;
  p_m_WUs->m_FirstFree = v6;
  v9 = this;
  if ( iWorkUnit == this->m_WULookup.m_uiBase )
  {
    v16 = p_m_WULookup->m_uiBase + p_m_WULookup->m_Size;
    v10 = HIDWORD(v16);
    if ( iWorkUnit >= v16 )
    {
      v11 = HIDWORD(iWorkUnit);
    }
    else
    {
      v11 = HIDWORD(iWorkUnit);
      do
      {
        if ( __PAIR64__(v11, v8) < p_m_WULookup->m_uiBase || v11 > v10 || v11 >= v10 && v8 >= (unsigned int)v16 )
        {
          v12 = nullptr;
        }
        else
        {
          v12 = &p_m_WULookup->m_Memory.m_pMemory[v8 - LODWORD(p_m_WULookup->m_uiBase)];
          v10 = HIDWORD(v16);
        }
        if ( v12->m_iWUInfo != -1 && __PAIR64__(v11, v8) > iWorkUnit )
          break;
        v11 = (__PAIR64__(v11, v8++) + 1) >> 32;
      }
      while ( __PAIR64__(v11, v8) < __PAIR64__(v10, v16) );
    }
    CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo>>::ShrinkWindow(
      this: p_m_WULookup,
      idxDrop: __PAIR64__(v11, v8) - 1);
    v9 = this;
  }
  v13 = (void *)iPartitionWorkera;
  if ( *(_DWORD *)(iPartitionWorkera + 32) == 0 )
  {
    iPartitionWorkerb = *(_DWORD *)(iPartitionWorkera + 4);
    CUtlLinkedList<CWorkUnitInfo,int,0,int,CUtlMemory<UtlLinkedListElem_t<CWorkUnitInfo,int>,int>>::RemoveAll(this: p_m_WUs);
    if ( p_m_WUs->m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_WUs->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_WUs->m_Memory.m_pMemory);
        p_m_WUs->m_Memory.m_pMemory = nullptr;
      }
      p_m_WUs->m_Memory.m_nAllocationCount = 0;
    }
    operator delete(p: v13);
    CUtlLinkedList<CThreadedTCPSocket::SendData_t *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CThreadedTCPSocket::SendData_t *,int>,int>>::Unlink(
      this: (CUtlLinkedList<CFileChunkPacket *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CFileChunkPacket *,int>,int> > *)&v9->m_Partitions,
      elem: iPartition);
    v9->m_Partitions.m_Memory.m_pMemory[iPartition].m_Next = v9->m_Partitions.m_FirstFree;
    v9->m_Partitions.m_FirstFree = iPartition;
    if ( v9->m_WULookup.m_uiBase < v9->m_WULookup.m_uiTotal )
      CDistributor_DefaultMaster::AssignWUsToWorker(this: v9, iWorker: iPartitionWorkerb);
  }
  LODWORD(v14) = CWorkUnitsTracker::WorkUnitFinished(this: &g_MasterWorkUnitsTracker, iWorkUnit);
  if ( v14 != 0 && g_pDistributeWorkCallbacks != nullptr )
    ((void (__thiscall *)(IWorkUnitDistributorCallbacks *, _DWORD, _DWORD))g_pDistributeWorkCallbacks->OnWorkUnitsCompleted)(
      a1: g_pDistributeWorkCallbacks,
      a2: v14,
      a3: HIDWORD(v14));
  return 1;
}

} // namespace vvis_dll
