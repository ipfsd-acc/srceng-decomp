// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmpi/vmpi_distribute_work.cpp
// Functions: 21
// ============================================================

#include "utils\vmpi\vmpi_distribute_work.h"

//------------------------------------------------------------------------------
// Address: 0x100229C0
// Name: void PrepareDistributeWorkHeader(class MessageBuffer __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrepareDistributeWorkHeader(MessageBuffer *pBuf, unsigned __int8 cSubpacketID)
{
  char cPacketID[4]; // [esp+4h] [ebp-4h] BYREF

  cPacketID[1] = cSubpacketID;
  cPacketID[0] = g_DSInfo.m_cPacketID;
  MessageBuffer::write(this: pBuf, p: (unsigned __int8 *)cPacketID, bytes: 2u);
  MessageBuffer::write(this: pBuf, p: (unsigned __int8 *)&g_iCurDSInfo, bytes: 2u);
}

//------------------------------------------------------------------------------
// Address: 0x10022A00
// Name: void VMPI_DistributeWork_DisconnectHandler(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_DistributeWork_DisconnectHandler(int procID)
{
  bool v1; // bl

  if ( g_bMasterDistributingWork )
  {
    v1 = g_bSuppressPrintfOutput;
    g_bSuppressPrintfOutput = true;
    _Msg(a1: "VMPI_DistributeWork_DisconnectHandler( %d )\n", procID);
    g_bSuppressPrintfOutput = v1;
    g_pCurDistributorMaster->DisconnectHandler(this: g_pCurDistributorMaster, a2: procID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022A50
// Name: enum EWorkUnitDistributor VMPI_GetActiveWorkUnitDistributor(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VMPI_GetActiveWorkUnitDistributor()
{
  const char *ParamString; // eax
  const char *v2; // eax

  if ( VMPI_IsParamUsed(eParam: mpi_UseSDKDistributor) )
  {
    ParamString = VMPI_GetParamString(eParam: mpi_UseSDKDistributor);
    _Msg(a1: "Found %s.\n", ParamString);
    return true;
  }
  else if ( VMPI_IsParamUsed(eParam: mpi_UseDefaultDistributor) )
  {
    v2 = VMPI_GetParamString(eParam: mpi_UseDefaultDistributor);
    _Msg(a1: "Found %s.\n", v2);
    return false;
  }
  else
  {
    return VMPI_IsSDKMode();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022AB0
// Name: void PreDistributeWorkSync(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PreDistributeWorkSync()
{
  int Name; // eax
  int v1; // eax
  MessageBuffer mb; // [esp+0h] [ebp-14h] BYREF
  char p; // [esp+10h] [ebp-4h] BYREF
  char v4; // [esp+11h] [ebp-3h]

  if ( g_bMPIMaster )
  {
    MessageBuffer::MessageBuffer(this: &mb);
    p = g_DSInfo.m_cPacketID;
    v4 = 0;
    MessageBuffer::write(this: &mb, (unsigned __int8 *)&p, bytes: 2u);
    MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&g_iCurDSInfo, bytes: 2u);
    Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
    VMPI_SendData(pData: mb.data, nBytes: Name, iDest: -3, fVMPISendFlags: 0);
    MessageBuffer::~MessageBuffer(this: &mb);
  }
  else
  {
    if ( g_iVMPIVerboseLevel >= 1 )
      _Msg(a1: "PreDistributeWorkSync: waiting for master\n");
    while ( g_iMasterReadyForDistributeWorkCall < g_iCurDSInfo )
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xFFFFFFFF);
    if ( g_iVMPIVerboseLevel >= 1 )
      _Msg(a1: "PreDistributeWorkSync: master ready\n");
    MessageBuffer::MessageBuffer(this: &mb);
    p = g_DSInfo.m_cPacketID;
    v4 = 1;
    MessageBuffer::write(this: &mb, (unsigned __int8 *)&p, bytes: 2u);
    MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&g_iCurDSInfo, bytes: 2u);
    v1 = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
    VMPI_SendData(pData: mb.data, nBytes: v1, iDest: 0, fVMPISendFlags: 0);
    MessageBuffer::~MessageBuffer(this: &mb);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022BD0
// Name: void DistributeWork_Cancel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DistributeWork_Cancel()
{
  if ( g_pCurWorkerThreadsInfo != nullptr )
  {
    _Msg(a1: "\nDistributeWork_Cancel saves the day!\n");
    g_pCurWorkerThreadsInfo->m_bMasterFinished = true;
    g_bVMPIEarlyExit = true;
    RunThreads_End();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022C00
// Name: int SortByWUCount(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortByWUCount(_DWORD *elem1, _DWORD *elem2)
{
  unsigned int v2; // esi
  unsigned int v3; // ecx
  unsigned int v4; // edi
  unsigned int v5; // eax
  bool v6; // zf

  v2 = g_wuCountByProcess.m_Memory.m_pMemory[*elem1];
  v3 = HIDWORD(g_wuCountByProcess.m_Memory.m_pMemory[*elem1]);
  v4 = g_wuCountByProcess.m_Memory.m_pMemory[*elem2];
  v5 = HIDWORD(g_wuCountByProcess.m_Memory.m_pMemory[*elem2]);
  if ( v3 > v5 )
  {
    v6 = v2 == v4;
  }
  else
  {
    if ( v3 < v5 )
      return 1;
    v6 = v2 == v4;
    if ( v2 < v4 )
      return 1;
  }
  if ( v6 && v3 == v5 )
    return 0;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10022C50
// Name: void HandleWorkUnitCompleted(class CDSInfo __near *,int,unsigned __int64,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HandleWorkUnitCompleted(CDSInfo *pInfo, int iSource, unsigned __int64 iWorkUnit, MessageBuffer *pBuf)
{
  unsigned __int64 *m_pMemory; // ecx
  bool v5; // cf
  float flPercent; // [esp+8h] [ebp-10h]

  VMPITracker_WorkUnitCompleted(iWorkUnit, iWorker: iSource);
  if ( ((unsigned __int8 (__thiscall *)(IWorkUnitDistributorMaster *, _DWORD, _DWORD))g_pCurDistributorMaster->HandleWorkUnitResults)(
         a1: g_pCurDistributorMaster,
         a2: iWorkUnit,
         a3: HIDWORD(iWorkUnit)) != 0 )
  {
    if ( g_iVMPIVerboseLevel >= 1 )
      _Msg(a1: "-");
    ++g_nCompletedWUs;
    m_pMemory = g_wuCountByProcess.m_Memory.m_pMemory;
    v5 = __CFADD__(LODWORD(g_wuCountByProcess.m_Memory.m_pMemory[iSource])++, 1);
    HIDWORD(m_pMemory[iSource]) += v5;
    v5 = __CFADD__(LODWORD(g_totalWUCountByProcess[iSource])++, 1);
    HIDWORD(g_totalWUCountByProcess[iSource]) += v5;
    if ( pBuf != nullptr )
      ((void (__cdecl *)(_DWORD, _DWORD, MessageBuffer *, int))pInfo->m_MasterInfo.m_ReceiveFn)(
        a1: iWorkUnit,
        a2: HIDWORD(iWorkUnit),
        a3: pBuf,
        a4: iSource);
    flPercent = (double)g_nCompletedWUs / (double)pInfo->m_nWorkUnits;
    UpdatePacifier(flPercent);
  }
  else
  {
    ++g_nDuplicatedWUs;
    if ( g_iVMPIVerboseLevel >= 1 )
      _Msg(a1: "*");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022D80
// Name: bool DistributeWorkDispatch(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl DistributeWorkDispatch(MessageBuffer *pBuf, int iSource)
{
  int v2; // esi
  bool result; // al
  char *MachineName; // eax
  unsigned int v5; // eax
  unsigned __int64 iWorkUnit; // [esp+Ch] [ebp-8h] BYREF

  v2 = *((unsigned __int16 *)pBuf->data + 1);
  if ( (unsigned __int16)v2 >= 0xFFu )
    _Error(
      a1: "Got an invalid DistributeWork packet (id: %d, sub: %d) (iCurDW: %d).",
      *pBuf->data,
      pBuf->data[1],
      *((unsigned __int16 *)pBuf->data + 1));
  MessageBuffer::setOffset(this: pBuf, noffset: 4);
  switch ( pBuf->data[1] )
  {
    case 0:
      g_iMasterReadyForDistributeWorkCall = v2;
      goto LABEL_5;
    case 1:
      if ( (unsigned __int16)v2 > g_iCurDSInfo || !g_bMPIMaster )
      {
        MachineName = VMPI_GetMachineName(iProc: iSource);
        _Error(a1: "State incorrect on master for DW_SUBPACKETID_WORKER_READY packet from %s.", MachineName);
      }
      if ( (_WORD)v2 == g_iCurDSInfo && g_pCurDistributorMaster != nullptr )
        g_pCurDistributorMaster->OnWorkerReady(this: g_pCurDistributorMaster, a2: iSource);
      return true;
    case 2:
      g_iMasterFinishedDistributeWorkCall = v2;
      return true;
    case 4:
      if ( (_WORD)v2 != g_iCurDSInfo )
        goto LABEL_5;
      MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&iWorkUnit, bytes: 8u);
      v5 = HIDWORD(iWorkUnit);
      if ( iWorkUnit >= g_DSInfo.m_nWorkUnits )
      {
        _Error(
          a1: "DistributeWork: got an invalid work unit index (%I64u for WU count of %I64u).",
          iWorkUnit,
          g_DSInfo.m_nWorkUnits);
        v5 = HIDWORD(iWorkUnit);
      }
      HandleWorkUnitCompleted(pInfo: &g_DSInfo, iSource, iWorkUnit: __PAIR64__(v5, iWorkUnit), pBuf);
      result = true;
      break;
    case 6:
      if ( (_WORD)v2 == g_iCurDSInfo )
      {
        MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&iWorkUnit, bytes: 8u);
        VMPITracker_WorkUnitStarted(iWorkUnit, iWorker: iSource);
        result = true;
      }
      else
      {
LABEL_5:
        result = true;
      }
      break;
    default:
      if ( g_pCurDistributorMaster != nullptr )
        result = g_pCurDistributorMaster->HandlePacket(
                   this: g_pCurDistributorMaster,
                   a2: pBuf,
                   a3: iSource,
                   a4: (_WORD)v2 != g_iCurDSInfo);
      else
        result = g_pCurDistributorWorker != nullptr
              && g_pCurDistributorWorker->HandlePacket(
                   this: g_pCurDistributorWorker,
                   a2: pBuf,
                   a3: iSource,
                   a4: (_WORD)v2 != g_iCurDSInfo);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10022F70
// Name: void DistributeWork_Master(class CDSInfo __near *,void (*)(int,unsigned __int64,class MessageBuffer __near *),void (*)(unsigned __int64,class MessageBuffer __near *,int))
// Source: json
//------------------------------------------------------------------------------
void __cdecl DistributeWork_Master(
        CDSInfo *pInfo,
        void (__cdecl *processFn)(int, unsigned __int64, MessageBuffer *),
        void (__cdecl *receiveFn)(unsigned __int64, MessageBuffer *, int))
{
  void (__cdecl *v3)(unsigned __int64, MessageBuffer *, int); // ecx
  CDSInfo *v4; // esi
  void (__thiscall *v5)(IWorkUnitDistributorMaster *, CDSInfo *); // edx
  int Name; // eax
  int m_nWorkUnits; // [esp-4h] [ebp-18h]
  MessageBuffer mb; // [esp+4h] [ebp-10h] BYREF

  v3 = receiveFn;
  v4 = pInfo;
  m_nWorkUnits = pInfo->m_nWorkUnits;
  pInfo->m_WorkerInfo.m_pProcessFn = processFn;
  v4->m_MasterInfo.m_ReceiveFn = v3;
  VMPITracker_Start(nWorkUnits: m_nWorkUnits);
  v5 = g_pCurDistributorMaster->DistributeWork_Master;
  g_bMasterDistributingWork = true;
  v5(this: g_pCurDistributorMaster, a2: v4);
  g_bMasterDistributingWork = false;
  VMPITracker_End();
  MessageBuffer::MessageBuffer(this: &mb);
  LOBYTE(pInfo) = g_DSInfo.m_cPacketID;
  BYTE1(pInfo) = 2;
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&pInfo, bytes: 2u);
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&g_iCurDSInfo, bytes: 2u);
  Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  VMPI_SendData(pData: mb.data, nBytes: Name, iDest: -3, fVMPISendFlags: 0);
  CCriticalSection::Lock(this: &g_MasterWorkUnitCompletedList);
  g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size = 0;
  CCriticalSection::Unlock(this: &g_MasterWorkUnitCompletedList);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x10023030
// Name: void CheckLocalMasterCompletedWorkUnits(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CheckLocalMasterCompletedWorkUnits()
{
  int v0; // ecx
  int v1; // esi
  int v2; // ebx
  unsigned __int64 v3; // kr00_8
  bool v4; // cf
  float flPercent; // [esp+8h] [ebp-34h]
  int i; // [esp+38h] [ebp-4h]

  CCriticalSection::Lock(this: &g_MasterWorkUnitCompletedList);
  v0 = 0;
  i = 0;
  if ( g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size > 0 )
  {
    while ( 1 )
    {
      v1 = g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Memory.m_pMemory[v0];
      v2 = HIDWORD(g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Memory.m_pMemory[v0]);
      VMPITracker_WorkUnitCompleted(iWorkUnit: v1, iWorker: 0);
      if ( ((unsigned __int8 (__thiscall *)(IWorkUnitDistributorMaster *, int, int))g_pCurDistributorMaster->HandleWorkUnitResults)(
             a1: g_pCurDistributorMaster,
             a2: v1,
             a3: v2) != 0 )
      {
        if ( g_iVMPIVerboseLevel >= 1 )
          _Msg(a1: "-");
        v3 = g_nCompletedWUs + 1;
        v4 = __CFADD__((*(_DWORD *)g_wuCountByProcess.m_Memory.m_pMemory)++, 1);
        *((_DWORD *)g_wuCountByProcess.m_Memory.m_pMemory + 1) += v4;
        ++g_totalWUCountByProcess[0];
        g_nCompletedWUs = v3;
        flPercent = (double)v3 / (double)g_DSInfo.m_nWorkUnits;
        UpdatePacifier(flPercent);
      }
      else
      {
        ++g_nDuplicatedWUs;
        if ( g_iVMPIVerboseLevel >= 1 )
          _Msg(a1: "*");
      }
      if ( ++i >= g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size )
        break;
      v0 = i;
    }
  }
  g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size = 0;
  CCriticalSection::Unlock(this: &g_MasterWorkUnitCompletedList);
}

//------------------------------------------------------------------------------
// Address: 0x10023210
// Name: void NotifyLocalMasterCompletedWorkUnit(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NotifyLocalMasterCompletedWorkUnit(unsigned __int64 iWorkUnit)
{
  CCriticalSection::Lock(this: &g_MasterWorkUnitCompletedList);
  CUtlVector<_D3DXMACRO,CUtlMemory<_D3DXMACRO,int>>::InsertBefore(
    this: &g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs,
    elem: g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size,
    src: &iWorkUnit);
  CCriticalSection::Unlock(this: &g_MasterWorkUnitCompletedList);
}

//------------------------------------------------------------------------------
// Address: 0x10023240
// Name: public: void CVisibleWindowVectorT<unsigned __int64,class CVisibleWindowVector<unsigned __int64>>::ExpandWindow(unsigned __int64,unsigned __int64 const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<unsigned __int64,CVisibleWindowVector<unsigned __int64>>::ExpandWindow(
        CVisibleWindowVectorT<unsigned __int64,CVisibleWindowVector<unsigned __int64> > *this,
        unsigned __int64 idxAccessible,
        const unsigned __int64 *x)
{
  int m_Size; // esi
  int i; // edx

  if ( idxAccessible >= this->m_uiBase + this->m_Size )
  {
    m_Size = this->m_Size;
    CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(
      this,
      elem: m_Size,
      num: idxAccessible - m_Size - LODWORD(this->m_uiBase) + 1);
    for ( i = this->m_Size; m_Size < i; ++m_Size )
      this->m_Memory.m_pMemory[m_Size] = *x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100232A0
// Name: void ShowMPIStats(double,unsigned long,unsigned long,unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMPIStats(
        long double flTimeSpent,
        unsigned int nBytesSent,
        int nBytesReceived,
        unsigned int nMessagesSent,
        unsigned int nMessagesReceived)
{
  bool IsParamUsed; // al
  int CurrentNumberOfConnections; // esi
  signed int i; // esi
  char *MachineName; // ebx
  char formatStr[512]; // [esp+14h] [ebp-224h] BYREF
  double flKSent; // [esp+214h] [ebp-24h]
  double flKRecv; // [esp+21Ch] [ebp-1Ch]
  CUtlVector<int,CUtlMemory<int,int> > sortedProcs; // [esp+224h] [ebp-14h] BYREF
  int i_4; // [esp+244h] [ebp+Ch]
  bool bOldSuppress_3; // [esp+24Bh] [ebp+13h]
  signed int nRealProcs; // [esp+24Ch] [ebp+14h]

  flKSent = (double)((nBytesSent + 511) >> 10);
  flKRecv = (double)((unsigned int)(nBytesReceived + 511) >> 10);
  IsParamUsed = VMPI_IsParamUsed(eParam: mpi_ShowDistributeWorkStats);
  bOldSuppress_3 = g_bSuppressPrintfOutput;
  g_bSuppressPrintfOutput = !IsParamUsed;
  _Msg(a1: "\n\n--------------------------------------------------------------\n");
  _Msg(a1: "Total Time       : %.2f\n", (double)flTimeSpent);
  _Msg(
    a1: "Total Bytes Sent : %dk (%.2fk/sec, %d messages)\n",
    (int)flKSent,
    (double)(1.0 / flTimeSpent * flKSent),
    nMessagesSent);
  _Msg(
    a1: "Total Bytes Recv : %dk (%.2fk/sec, %d messages)\n",
    (int)flKRecv,
    (double)(1.0 / flTimeSpent * flKRecv),
    nMessagesReceived);
  if ( g_bMPIMaster )
  {
    i_4 = 0;
    _Msg(a1: "Duplicated WUs   : %I64u (%.1f%%)\n", g_nDuplicatedWUs, (double)g_nDuplicatedWUs * 100.0 / (double)g_nWUs);
    _Msg(a1: "\nWU count by proc:\n");
    CurrentNumberOfConnections = VMPI_GetCurrentNumberOfConnections();
    memset(&sortedProcs, 0, sizeof(sortedProcs));
    CUtlVector<char *,CUtlMemory<char *,int>>::InsertMultipleBefore(
      this: &sortedProcs,
      elem: 0,
      num: CurrentNumberOfConnections);
    nRealProcs = 0;
    if ( CurrentNumberOfConnections > 0 )
    {
      do
      {
        if ( VMPI_IsProcValid(procID: i_4) )
          sortedProcs.m_Memory.m_pMemory[nRealProcs++] = i_4;
        ++i_4;
      }
      while ( i_4 < CurrentNumberOfConnections );
    }
    qsort(
      base: (char *)sortedProcs.m_Memory.m_pMemory,
      num: nRealProcs,
      width: 4u,
      comp: (int (__cdecl *)(const void *, const void *))SortByWUCount);
    for ( i = 0; i < nRealProcs; ++i )
    {
      MachineName = VMPI_GetMachineName(iProc: sortedProcs.m_Memory.m_pMemory[i]);
      _Msg(a1: "%s", MachineName);
      V_snprintf(
        pDest: formatStr,
        maxLen: 0x200u,
        pFormat: "%%%ds %I64u\n",
        30 - strlen(MachineName),
        g_wuCountByProcess.m_Memory.m_pMemory[sortedProcs.m_Memory.m_pMemory[i]]);
      _Msg(a1: formatStr, ":");
    }
    if ( sortedProcs.m_Memory.m_nGrowSize >= 0 && sortedProcs.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sortedProcs.m_Memory.m_pMemory);
  }
  _Msg(a1: "--------------------------------------------------------------\n\n ");
  g_bSuppressPrintfOutput = bOldSuppress_3;
}

//------------------------------------------------------------------------------
// Address: 0x10023540
// Name: void VMPI_WorkerThread(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_WorkerThread(int iThread, char *pUserData)
{
  unsigned int v2; // ebx
  unsigned __int64 v3; // rdi
  _QWORD *v4; // eax
  _QWORD *v5; // ecx
  unsigned int v6; // ecx
  unsigned __int64 *v7; // eax
  int v8; // eax
  int v9; // ecx
  int Name; // eax
  int v11; // eax
  MessageBuffer mbStartedWorkUnit; // [esp+Ch] [ebp-40h] BYREF
  MessageBuffer mb; // [esp+1Ch] [ebp-30h] BYREF
  _DWORD p[2]; // [esp+2Ch] [ebp-20h] BYREF
  CCriticalSectionLock csLock; // [esp+34h] [ebp-18h] BYREF
  unsigned __int64 idxRunningWorkUnit; // [esp+3Ch] [ebp-10h]
  unsigned __int64 iWU; // [esp+44h] [ebp-8h] BYREF

  v2 = iThread;
  v3 = __PAIR64__((unsigned int)pUserData, iThread);
  idxRunningWorkUnit = iThread;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: (CCriticalSection *)(pUserData + 48));
  CCriticalSectionLock::Lock(this: &csLock);
  iWU = -1;
  CVisibleWindowVectorT<unsigned __int64,CVisibleWindowVector<unsigned __int64>>::ExpandWindow(
    this: (CVisibleWindowVectorT<unsigned __int64,CVisibleWindowVector<unsigned __int64> > *)(HIDWORD(v3) + 8),
    idxAccessible: __PAIR64__(HIDWORD(idxRunningWorkUnit), v3),
    x: &iWU);
  CCriticalSectionLock::Unlock(this: &csLock);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  MessageBuffer::MessageBuffer(this: &mb);
  LOBYTE(iThread) = g_DSInfo.m_cPacketID;
  BYTE1(iThread) = 4;
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&iThread, bytes: 2u);
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&g_iCurDSInfo, bytes: 2u);
  MessageBuffer::MessageBuffer(this: &mbStartedWorkUnit);
  while ( g_iMasterFinishedDistributeWorkCall < g_iCurDSInfo )
  {
    if ( g_bVMPIEarlyExit )
      break;
    if ( g_pCurDistributorWorker->GetNextWorkUnit(this: g_pCurDistributorWorker, a2: &iWU) )
    {
      CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: (CCriticalSection *)(HIDWORD(v3) + 48));
      CCriticalSectionLock::Lock(this: &csLock);
      if ( *(_QWORD *)(HIDWORD(v3) + 32) != 0 || *(_DWORD *)(HIDWORD(v3) + 20) == 0 )
        v4 = nullptr;
      else
        v4 = *(_QWORD **)(HIDWORD(v3) + 8);
      v5 = &v4[*(_DWORD *)(HIDWORD(v3) + 20) + *(_DWORD *)(HIDWORD(v3) + 32)];
      if ( v4 == v5 )
        goto LABEL_14;
      while ( *v4 != iWU )
      {
        if ( ++v4 == v5 )
          goto LABEL_14;
      }
      if ( v4 == v5 )
      {
LABEL_14:
        v6 = *(_DWORD *)(HIDWORD(v3) + 36);
        LODWORD(v3) = *(_DWORD *)(HIDWORD(v3) + 32);
        if ( idxRunningWorkUnit < __PAIR64__(v6, v3)
          || idxRunningWorkUnit >= __PAIR64__(v6, v3) + *(int *)(HIDWORD(v3) + 20) )
        {
          v7 = nullptr;
        }
        else
        {
          v7 = (unsigned __int64 *)(*(_DWORD *)(HIDWORD(v3) + 8) + 8 * (idxRunningWorkUnit - v3));
        }
        *v7 = iWU;
        CCriticalSectionLock::Unlock(this: &csLock);
        MessageBuffer::setLen(this: &mb, nlen: 4);
        MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&iWU, bytes: 8u);
        v8 = HIDWORD(iWU);
        v9 = iWU;
        if ( v2 <= 3 )
        {
          LODWORD(g_ThreadWUs[v2]) = iWU;
          dword_10061544[2 * v2] = v8;
        }
        p[0] = v9;
        p[1] = v8;
        MessageBuffer::setLen(this: &mbStartedWorkUnit, nlen: 0);
        LOBYTE(iThread) = g_DSInfo.m_cPacketID;
        BYTE1(iThread) = 6;
        MessageBuffer::write(this: &mbStartedWorkUnit, p: (unsigned __int8 *)&iThread, bytes: 2u);
        MessageBuffer::write(this: &mbStartedWorkUnit, p: (unsigned __int8 *)&g_iCurDSInfo, bytes: 2u);
        MessageBuffer::write(this: &mbStartedWorkUnit, (unsigned __int8 *)p, bytes: 8u);
        Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mbStartedWorkUnit);
        VMPI_SendData(pData: mbStartedWorkUnit.data, nBytes: Name, iDest: 0, fVMPISendFlags: 1);
        (*(void (__cdecl **)(unsigned int, _DWORD, _DWORD, MessageBuffer *))HIDWORD(v3))(
          a1: v2,
          a2: iWU,
          a3: HIDWORD(iWU),
          a4: &mb);
        ((void (__thiscall *)(IWorkUnitDistributorWorker *, _DWORD, _DWORD))g_pCurDistributorWorker->NoteLocalWorkUnitCompleted)(
          a1: g_pCurDistributorWorker,
          a2: iWU,
          a3: HIDWORD(iWU));
        v11 = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
        VMPI_SendData(pData: mb.data, nBytes: v11, iDest: 0, fVMPISendFlags: 0);
      }
      CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    }
    else
    {
      VMPI_Sleep(ms: 0xAu);
    }
  }
  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "Worker thread exiting.\n");
  MessageBuffer::~MessageBuffer(this: &mbStartedWorkUnit);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x10023800
// Name: void DistributeWork_Worker(class CDSInfo __near *,void (*)(int,unsigned __int64,class MessageBuffer __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl DistributeWork_Worker(CDSInfo *pInfo, void (__cdecl *processFn)(int, unsigned __int64, MessageBuffer *))
{
  void (__thiscall *Init)(IWorkUnitDistributorWorker *, CDSInfo *); // eax
  unsigned int i; // esi

  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "VMPI_DistributeWork call %d started.\n", g_iCurDSInfo + 1);
  pInfo->m_WorkerInfo.m_pProcessFn = processFn;
  Init = g_pCurDistributorWorker->Init;
  g_pCurWorkerThreadsInfo = pInfo;
  Init(this: g_pCurDistributorWorker, a2: pInfo);
  RunThreads_Start(
    fn: (void (__cdecl *)(int, void *))VMPI_WorkerThread,
    pUserData: pInfo,
    ePriority: g_bSetThreadPriorities ? k_eRunThreadsPriority_Idle : k_eRunThreadsPriority_UseGlobalState);
  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "RunThreads_Start finished successfully.\n");
  if ( VMPI_IsSDKMode() )
  {
    _Msg(a1: "\n");
    while ( g_iMasterFinishedDistributeWorkCall < g_iCurDSInfo )
    {
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0x12C);
      _Msg(a1: "\rThreads status: ");
      for ( i = 0; i < 4; ++i )
      {
        if ( (dword_10061544[2 * i] & g_ThreadWUs[i]) != 0xFFFFFFFF )
          _Msg(a1: "%d: WU %5d  ", i, LODWORD(g_ThreadWUs[i]));
      }
      VMPI_FlushGroupedPackets(msInterval: 0);
    }
    _Msg(a1: "\n");
  }
  else
  {
    while ( g_iMasterFinishedDistributeWorkCall < g_iCurDSInfo )
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xFFFFFFFF);
  }
  g_pCurWorkerThreadsInfo = nullptr;
  RunThreads_End();
  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "VMPI_DistributeWork call %d finished.\n", g_iCurDSInfo + 1);
}

//------------------------------------------------------------------------------
// Address: 0x10023970
// Name: double DistributeWork(unsigned __int64,void (*)(int,unsigned __int64,class MessageBuffer __near *),void (*)(unsigned __int64,class MessageBuffer __near *,int))
// Source: json
//------------------------------------------------------------------------------
long double __usercall DistributeWork@<st0>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        unsigned __int64 nWorkUnits,
        void (__cdecl *processFn)(int, unsigned __int64, MessageBuffer *),
        void (__cdecl *receiveFn)(unsigned __int64, MessageBuffer *, int))
{
  unsigned __int64 *m_pMemory; // eax
  int v7; // esi
  int v8; // edi
  int v9; // ebx
  BOOL ActiveWorkUnitDistributor; // eax
  IWorkUnitDistributorMaster *WUDistributor_SDKMaster; // eax
  IWorkUnitDistributorWorker *WUDistributor_SDKWorker; // eax
  double v13; // st7
  double flTimeSpent; // [esp+24h] [ebp-8h]
  long double flTimeSpenta; // [esp+24h] [ebp-8h]
  int v18; // [esp+38h] [ebp+Ch]

  if ( ++g_iCurDSInfo != 0 )
  {
    if ( g_iCurDSInfo >= 0xFFu )
      _Error(a1: "DistributeWork: called more than %d times.\n", 255);
  }
  else if ( g_bMPIMaster )
  {
    VMPI_AddDisconnectHandler(handler: (void (__cdecl *)(int, const char *))VMPI_DistributeWork_DisconnectHandler);
  }
  g_DSInfo.m_cPacketID = 2;
  g_DSInfo.m_nWorkUnits = nWorkUnits;
  PreDistributeWorkSync();
  g_nCompletedWUs = 0;
  g_nWUs = nWorkUnits;
  g_nDuplicatedWUs = 0;
  flTimeSpent = _Plat_FloatTime(a1: a2, a2: a3);
  g_wuCountByProcess.m_Size = 0;
  if ( g_wuCountByProcess.m_Memory.m_nAllocationCount < 512 )
    CUtlMemory<CTransmitRateMgr::CMachineRecord,int>::Grow(
      this: (CUtlMemory<CTransmitRateMgr::CMachineRecord,int> *)&g_wuCountByProcess,
      num: 512 - g_wuCountByProcess.m_Memory.m_nAllocationCount);
  m_pMemory = g_wuCountByProcess.m_Memory.m_pMemory;
  g_wuCountByProcess.m_Size += 512;
  g_wuCountByProcess.m_pElements = g_wuCountByProcess.m_Memory.m_pMemory;
  if ( g_wuCountByProcess.m_Size - 512 > 0 )
  {
    _V_memmove(
      dest: (unsigned __int8 *)g_wuCountByProcess.m_Memory.m_pMemory + 4096,
      src: (unsigned __int8 *)g_wuCountByProcess.m_Memory.m_pMemory,
      count: 8 * (g_wuCountByProcess.m_Size - 512));
    m_pMemory = g_wuCountByProcess.m_Memory.m_pMemory;
  }
  memset(dst: (int)m_pMemory, value: nullptr, count: 4 * g_wuCountByProcess.m_Size);
  v7 = g_nBytesSent;
  v8 = g_nBytesReceived;
  v9 = g_nMessagesSent;
  v18 = g_nMessagesReceived;
  ActiveWorkUnitDistributor = VMPI_GetActiveWorkUnitDistributor();
  if ( g_bMPIMaster )
  {
    if ( ActiveWorkUnitDistributor )
      WUDistributor_SDKMaster = CreateWUDistributor_SDKMaster();
    else
      WUDistributor_SDKMaster = CreateWUDistributor_DefaultMaster();
    g_pCurDistributorMaster = WUDistributor_SDKMaster;
    DistributeWork_Master(pInfo: &g_DSInfo, processFn, receiveFn);
    g_pCurDistributorMaster->Release(this: g_pCurDistributorMaster);
    g_pCurDistributorMaster = nullptr;
  }
  else
  {
    if ( ActiveWorkUnitDistributor )
      WUDistributor_SDKWorker = CreateWUDistributor_SDKWorker();
    else
      WUDistributor_SDKWorker = CreateWUDistributor_DefaultWorker();
    g_pCurDistributorWorker = WUDistributor_SDKWorker;
    DistributeWork_Worker(pInfo: &g_DSInfo, processFn);
    g_pCurDistributorWorker->Release(this: g_pCurDistributorWorker);
    g_pCurDistributorWorker = nullptr;
  }
  v13 = _Plat_FloatTime(a1, a2: LODWORD(flTimeSpent));
  flTimeSpenta = v13 - flTimeSpent;
  ShowMPIStats(
    flTimeSpent: flTimeSpenta,
    nBytesSent: g_nBytesSent - v7,
    nBytesReceived: g_nBytesReceived - v8,
    nMessagesSent: g_nMessagesSent - v9,
    nMessagesReceived: g_nMessagesReceived - v18);
  LODWORD(g_ThreadWUs[0]) = -1;
  dword_10061544[0] = -1;
  dword_10061548 = -1;
  dword_1006154C = -1;
  dword_10061550 = -1;
  dword_10061554 = -1;
  dword_10061558 = -1;
  dword_1006155C = -1;
  return flTimeSpenta;
}

//------------------------------------------------------------------------------
// Address: 0x10023BC0
// Name: public: void CVisibleWindowVectorT<unsigned char,class CVisibleWindowVector<unsigned char>>::ShrinkWindow(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ShrinkWindow(
        CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char> > *this,
        unsigned __int64 idxDrop)
{
  unsigned int m_uiBase; // ebx
  int m_Size; // ecx
  int v5; // edi
  signed int v6; // ecx

  m_uiBase = this->m_uiBase;
  if ( idxDrop >= this->m_uiBase )
  {
    m_Size = this->m_Size;
    if ( idxDrop <= __PAIR64__(HIDWORD(this->m_uiBase), m_uiBase) + this->m_Size )
    {
      v5 = idxDrop - LODWORD(this->m_uiBase) + 1;
      this->m_uiBase += v5;
      if ( v5 >= m_Size )
        v5 = m_Size;
      v6 = m_Size - v5;
      if ( v6 > 0 && v5 > 0 )
        _V_memmove(dest: this->m_Memory.m_pMemory, src: &this->m_Memory.m_pMemory[v5], count: v6);
      this->m_Size -= v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023C30
// Name: public: void CVisibleWindowVectorT<unsigned char,class CVisibleWindowVector<unsigned char>>::Reset(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::Reset(
        CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char> > *this,
        unsigned __int64 uiTotal)
{
  int v3; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // ecx

  this->m_Size = 0;
  if ( uiTotal <= 0x64 )
    v3 = uiTotal;
  else
    v3 = 100;
  if ( this->m_Memory.m_nAllocationCount < v3 && this->m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = v3;
    if ( m_pMemory != nullptr )
      v5 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v3);
    else
      v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v3);
    this->m_Memory.m_pMemory = v5;
  }
  v6 = this->m_Memory.m_pMemory;
  LODWORD(this->m_uiTotal) = uiTotal;
  LODWORD(this->m_uiBase) = 0;
  HIDWORD(this->m_uiBase) = 0;
  this->m_pElements = v6;
  HIDWORD(this->m_uiTotal) = HIDWORD(uiTotal);
}

//------------------------------------------------------------------------------
// Address: 0x10023EA0
// Name: public: void CVisibleWindowVectorT<unsigned char,class CVisibleWindowVector<unsigned char>>::ExpandWindow(unsigned __int64,unsigned char const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ExpandWindow(
        CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char> > *this,
        unsigned __int64 idxAccessible,
        const unsigned __int8 *x)
{
  int m_Size; // ebx
  int v5; // edi
  int v6; // ecx
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // edx
  signed int v9; // eax
  int i; // eax

  m_Size = this->m_Size;
  if ( idxAccessible >= this->m_uiBase + m_Size )
  {
    v5 = idxAccessible - m_Size - LODWORD(this->m_uiBase) + 1;
    v6 = this->m_Size;
    if ( (_DWORD)idxAccessible - m_Size - LODWORD(this->m_uiBase) != -1 )
    {
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( (int)idxAccessible - LODWORD(this->m_uiBase) + 1 > m_nAllocationCount )
      {
        CUtlMemory<bool,int>::Grow(
          (CUtlMemory<char,int> *)this,
          num: idxAccessible - LODWORD(this->m_uiBase) + 1 - m_nAllocationCount);
        v6 = m_Size;
      }
      this->m_Size += v5;
      m_pMemory = this->m_Memory.m_pMemory;
      v9 = this->m_Size - v6 - v5;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v9 > 0 && v5 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + v5], src: &m_pMemory[v6], count: v9);
    }
    for ( i = this->m_Size; m_Size < i; ++m_Size )
      this->m_Memory.m_pMemory[m_Size] = *x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024C40
// Name: public: void CVisibleWindowVectorT<class CWULookupInfo,class CVisibleWindowVector<class CWULookupInfo>>::Reset(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo>>::Reset(
        CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo> > *this,
        unsigned __int64 uiTotal)
{
  int v3; // eax
  CWULookupInfo *m_pMemory; // edx
  CWULookupInfo *v5; // eax
  CWULookupInfo *v6; // ecx
  unsigned int v7; // [esp-4h] [ebp-10h]

  this->m_Size = 0;
  if ( uiTotal <= 0x64 )
    v3 = uiTotal;
  else
    v3 = 100;
  if ( this->m_Memory.m_nAllocationCount < v3 && this->m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = v3;
    v7 = 12 * v3;
    if ( m_pMemory != nullptr )
      v5 = (CWULookupInfo *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      v5 = (CWULookupInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
    this->m_Memory.m_pMemory = v5;
  }
  v6 = this->m_Memory.m_pMemory;
  LODWORD(this->m_uiTotal) = uiTotal;
  LODWORD(this->m_uiBase) = 0;
  HIDWORD(this->m_uiBase) = 0;
  this->m_pElements = v6;
  HIDWORD(this->m_uiTotal) = HIDWORD(uiTotal);
}

//------------------------------------------------------------------------------
// Address: 0x10024CC0
// Name: public: void CVisibleWindowVectorT<class CWULookupInfo,class CVisibleWindowVector<class CWULookupInfo>>::ShrinkWindow(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo>>::ShrinkWindow(
        CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo> > *this,
        unsigned __int64 idxDrop)
{
  unsigned int m_uiBase; // ebx
  int m_Size; // ecx
  int v5; // edi
  int v6; // ecx

  m_uiBase = this->m_uiBase;
  if ( idxDrop >= this->m_uiBase )
  {
    m_Size = this->m_Size;
    if ( idxDrop <= __PAIR64__(HIDWORD(this->m_uiBase), m_uiBase) + this->m_Size )
    {
      v5 = idxDrop - LODWORD(this->m_uiBase) + 1;
      this->m_uiBase += v5;
      if ( v5 >= m_Size )
        v5 = m_Size;
      v6 = m_Size - v5;
      if ( v6 > 0 && v5 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)this->m_Memory.m_pMemory,
          src: (unsigned __int8 *)&this->m_Memory.m_pMemory[v5],
          count: 12 * v6);
      this->m_Size -= v5;
    }
  }
}

// ============================================================
// Overlay from texturecompile_dll (Missing functions)
// ============================================================
namespace texturecompile_dll {

//------------------------------------------------------------------------------
// Address: 0x1000CB10
// Name: void PrepareDistributeWorkHeader(class MessageBuffer __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrepareDistributeWorkHeader(MessageBuffer *pBuf, unsigned __int8 cSubpacketID)
{
  char cPacketID[4]; // [esp+4h] [ebp-4h] BYREF

  cPacketID[1] = cSubpacketID;
  cPacketID[0] = g_DSInfo.m_cPacketID;
  MessageBuffer::write(this: pBuf, p: (unsigned __int8 *)cPacketID, bytes: 2u);
  MessageBuffer::write(this: pBuf, p: (unsigned __int8 *)&g_iCurDSInfo, bytes: 2u);
}

//------------------------------------------------------------------------------
// Address: 0x1000CB50
// Name: void VMPI_DistributeWork_DisconnectHandler(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_DistributeWork_DisconnectHandler(int procID)
{
  bool v1; // bl

  if ( g_bMasterDistributingWork )
  {
    v1 = g_bSuppressPrintfOutput;
    g_bSuppressPrintfOutput = true;
    _Msg(a1: "VMPI_DistributeWork_DisconnectHandler( %d )\n", procID);
    g_bSuppressPrintfOutput = v1;
    g_pCurDistributorMaster->DisconnectHandler(this: g_pCurDistributorMaster, a2: procID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CBA0
// Name: enum EWorkUnitDistributor VMPI_GetActiveWorkUnitDistributor(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VMPI_GetActiveWorkUnitDistributor()
{
  const char *ParamString; // eax
  const char *v2; // eax

  if ( VMPI_IsParamUsed(eParam: mpi_UseSDKDistributor) )
  {
    ParamString = VMPI_GetParamString(eParam: mpi_UseSDKDistributor);
    _Msg(a1: "Found %s.\n", ParamString);
    return true;
  }
  else if ( VMPI_IsParamUsed(eParam: mpi_UseDefaultDistributor) )
  {
    v2 = VMPI_GetParamString(eParam: mpi_UseDefaultDistributor);
    _Msg(a1: "Found %s.\n", v2);
    return false;
  }
  else
  {
    return VMPI_IsSDKMode();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CC00
// Name: void PreDistributeWorkSync(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PreDistributeWorkSync()
{
  int Name; // eax
  int v1; // eax
  MessageBuffer mb; // [esp+0h] [ebp-14h] BYREF
  char p; // [esp+10h] [ebp-4h] BYREF
  char v4; // [esp+11h] [ebp-3h]

  if ( g_bMPIMaster )
  {
    MessageBuffer::MessageBuffer(this: &mb);
    p = g_DSInfo.m_cPacketID;
    v4 = 0;
    MessageBuffer::write(this: &mb, (unsigned __int8 *)&p, bytes: 2u);
    MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&g_iCurDSInfo, bytes: 2u);
    Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
    VMPI_SendData(pData: mb.data, nBytes: Name, iDest: -3, fVMPISendFlags: 0);
    MessageBuffer::~MessageBuffer(this: &mb);
  }
  else
  {
    if ( g_iVMPIVerboseLevel >= 1 )
      _Msg(a1: "PreDistributeWorkSync: waiting for master\n");
    while ( g_iMasterReadyForDistributeWorkCall < g_iCurDSInfo )
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xFFFFFFFF);
    if ( g_iVMPIVerboseLevel >= 1 )
      _Msg(a1: "PreDistributeWorkSync: master ready\n");
    MessageBuffer::MessageBuffer(this: &mb);
    p = g_DSInfo.m_cPacketID;
    v4 = 1;
    MessageBuffer::write(this: &mb, (unsigned __int8 *)&p, bytes: 2u);
    MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&g_iCurDSInfo, bytes: 2u);
    v1 = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
    VMPI_SendData(pData: mb.data, nBytes: v1, iDest: 0, fVMPISendFlags: 0);
    MessageBuffer::~MessageBuffer(this: &mb);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CD20
// Name: void DistributeWork_Cancel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DistributeWork_Cancel()
{
  if ( g_pCurWorkerThreadsInfo != nullptr )
  {
    _Msg(a1: "\nDistributeWork_Cancel saves the day!\n");
    g_pCurWorkerThreadsInfo->m_bMasterFinished = true;
    g_bVMPIEarlyExit = true;
    RunThreads_End();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CD50
// Name: int SortByWUCount(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortByWUCount(_DWORD *elem1, _DWORD *elem2)
{
  unsigned int v2; // esi
  unsigned int v3; // ecx
  unsigned int v4; // edi
  unsigned int v5; // eax
  bool v6; // zf

  v2 = g_wuCountByProcess.m_Memory.m_pMemory[*elem1];
  v3 = HIDWORD(g_wuCountByProcess.m_Memory.m_pMemory[*elem1]);
  v4 = g_wuCountByProcess.m_Memory.m_pMemory[*elem2];
  v5 = HIDWORD(g_wuCountByProcess.m_Memory.m_pMemory[*elem2]);
  if ( v3 > v5 )
  {
    v6 = v2 == v4;
  }
  else
  {
    if ( v3 < v5 )
      return 1;
    v6 = v2 == v4;
    if ( v2 < v4 )
      return 1;
  }
  if ( v6 && v3 == v5 )
    return 0;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1000CDA0
// Name: void HandleWorkUnitCompleted(class CDSInfo __near *,int,unsigned __int64,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HandleWorkUnitCompleted(CDSInfo *pInfo, int iSource, unsigned __int64 iWorkUnit, MessageBuffer *pBuf)
{
  unsigned __int64 *m_pMemory; // ecx
  bool v5; // cf
  float flPercent; // [esp+8h] [ebp-10h]

  VMPITracker_WorkUnitCompleted(iWorkUnit, iWorker: iSource);
  if ( ((unsigned __int8 (__thiscall *)(IWorkUnitDistributorMaster *, _DWORD, _DWORD))g_pCurDistributorMaster->HandleWorkUnitResults)(
         a1: g_pCurDistributorMaster,
         a2: iWorkUnit,
         a3: HIDWORD(iWorkUnit)) != 0 )
  {
    if ( g_iVMPIVerboseLevel >= 1 )
      _Msg(a1: "-");
    ++g_nCompletedWUs;
    m_pMemory = g_wuCountByProcess.m_Memory.m_pMemory;
    v5 = __CFADD__(LODWORD(g_wuCountByProcess.m_Memory.m_pMemory[iSource])++, 1);
    HIDWORD(m_pMemory[iSource]) += v5;
    v5 = __CFADD__(LODWORD(g_totalWUCountByProcess[iSource])++, 1);
    HIDWORD(g_totalWUCountByProcess[iSource]) += v5;
    if ( pBuf != nullptr )
      ((void (__cdecl *)(_DWORD, _DWORD, MessageBuffer *, int))pInfo->m_MasterInfo.m_ReceiveFn)(
        a1: iWorkUnit,
        a2: HIDWORD(iWorkUnit),
        a3: pBuf,
        a4: iSource);
    flPercent = (double)g_nCompletedWUs / (double)pInfo->m_nWorkUnits;
    UpdatePacifier(flPercent);
  }
  else
  {
    ++g_nDuplicatedWUs;
    if ( g_iVMPIVerboseLevel >= 1 )
      _Msg(a1: "*");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CED0
// Name: bool DistributeWorkDispatch(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl DistributeWorkDispatch(MessageBuffer *pBuf, int iSource)
{
  int v2; // esi
  bool result; // al
  char *MachineName; // eax
  unsigned int v5; // eax
  unsigned __int64 iWorkUnit; // [esp+Ch] [ebp-8h] BYREF

  v2 = *((unsigned __int16 *)pBuf->data + 1);
  if ( (unsigned __int16)v2 >= 0xFFu )
    _Error(
      a1: "Got an invalid DistributeWork packet (id: %d, sub: %d) (iCurDW: %d).",
      *pBuf->data,
      pBuf->data[1],
      *((unsigned __int16 *)pBuf->data + 1));
  MessageBuffer::setOffset(this: pBuf, noffset: 4);
  switch ( pBuf->data[1] )
  {
    case 0:
      g_iMasterReadyForDistributeWorkCall = v2;
      goto LABEL_5;
    case 1:
      if ( (unsigned __int16)v2 > g_iCurDSInfo || !g_bMPIMaster )
      {
        MachineName = VMPI_GetMachineName(iProc: iSource);
        _Error(a1: "State incorrect on master for DW_SUBPACKETID_WORKER_READY packet from %s.", MachineName);
      }
      if ( (_WORD)v2 == g_iCurDSInfo && g_pCurDistributorMaster != nullptr )
        g_pCurDistributorMaster->OnWorkerReady(this: g_pCurDistributorMaster, a2: iSource);
      return true;
    case 2:
      g_iMasterFinishedDistributeWorkCall = v2;
      return true;
    case 4:
      if ( (_WORD)v2 != g_iCurDSInfo )
        goto LABEL_5;
      MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&iWorkUnit, bytes: 8u);
      v5 = HIDWORD(iWorkUnit);
      if ( iWorkUnit >= g_DSInfo.m_nWorkUnits )
      {
        _Error(
          a1: "DistributeWork: got an invalid work unit index (%I64u for WU count of %I64u).",
          iWorkUnit,
          g_DSInfo.m_nWorkUnits);
        v5 = HIDWORD(iWorkUnit);
      }
      HandleWorkUnitCompleted(pInfo: &g_DSInfo, iSource, iWorkUnit: __PAIR64__(v5, iWorkUnit), pBuf);
      result = true;
      break;
    case 6:
      if ( (_WORD)v2 == g_iCurDSInfo )
      {
        MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&iWorkUnit, bytes: 8u);
        VMPITracker_WorkUnitStarted(iWorkUnit, iWorker: iSource);
        result = true;
      }
      else
      {
LABEL_5:
        result = true;
      }
      break;
    default:
      if ( g_pCurDistributorMaster != nullptr )
        result = g_pCurDistributorMaster->HandlePacket(
                   this: g_pCurDistributorMaster,
                   a2: pBuf,
                   a3: iSource,
                   a4: (_WORD)v2 != g_iCurDSInfo);
      else
        result = g_pCurDistributorWorker != nullptr
              && g_pCurDistributorWorker->HandlePacket(
                   this: g_pCurDistributorWorker,
                   a2: pBuf,
                   a3: iSource,
                   a4: (_WORD)v2 != g_iCurDSInfo);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D0B0
// Name: void DistributeWork_Master(class CDSInfo __near *,void (*)(int,unsigned __int64,class MessageBuffer __near *),void (*)(unsigned __int64,class MessageBuffer __near *,int))
// Source: json
//------------------------------------------------------------------------------
void __cdecl DistributeWork_Master(
        CDSInfo *pInfo,
        void (__cdecl *processFn)(int, unsigned __int64, MessageBuffer *),
        void (__cdecl *receiveFn)(unsigned __int64, MessageBuffer *, int))
{
  void (__cdecl *v3)(unsigned __int64, MessageBuffer *, int); // ecx
  CDSInfo *v4; // esi
  void (__thiscall *v5)(IWorkUnitDistributorMaster *, CDSInfo *); // edx
  int Name; // eax
  int m_nWorkUnits; // [esp-4h] [ebp-18h]
  MessageBuffer mb; // [esp+4h] [ebp-10h] BYREF

  v3 = receiveFn;
  v4 = pInfo;
  m_nWorkUnits = pInfo->m_nWorkUnits;
  pInfo->m_WorkerInfo.m_pProcessFn = processFn;
  v4->m_MasterInfo.m_ReceiveFn = v3;
  VMPITracker_Start(nWorkUnits: m_nWorkUnits);
  v5 = g_pCurDistributorMaster->DistributeWork_Master;
  g_bMasterDistributingWork = true;
  v5(this: g_pCurDistributorMaster, a2: v4);
  g_bMasterDistributingWork = false;
  VMPITracker_End();
  MessageBuffer::MessageBuffer(this: &mb);
  LOBYTE(pInfo) = g_DSInfo.m_cPacketID;
  BYTE1(pInfo) = 2;
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&pInfo, bytes: 2u);
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&g_iCurDSInfo, bytes: 2u);
  Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  VMPI_SendData(pData: mb.data, nBytes: Name, iDest: -3, fVMPISendFlags: 0);
  CCriticalSection::Lock(this: &g_MasterWorkUnitCompletedList);
  g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size = 0;
  CCriticalSection::Unlock(this: &g_MasterWorkUnitCompletedList);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x1000D170
// Name: void CheckLocalMasterCompletedWorkUnits(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CheckLocalMasterCompletedWorkUnits()
{
  int v0; // ecx
  int v1; // esi
  int v2; // ebx
  unsigned __int64 v3; // kr00_8
  bool v4; // cf
  float flPercent; // [esp+8h] [ebp-34h]
  int i; // [esp+38h] [ebp-4h]

  CCriticalSection::Lock(this: &g_MasterWorkUnitCompletedList);
  v0 = 0;
  i = 0;
  if ( g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size > 0 )
  {
    while ( 1 )
    {
      v1 = g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Memory.m_pMemory[v0];
      v2 = HIDWORD(g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Memory.m_pMemory[v0]);
      VMPITracker_WorkUnitCompleted(iWorkUnit: v1, iWorker: 0);
      if ( ((unsigned __int8 (__thiscall *)(IWorkUnitDistributorMaster *, int, int))g_pCurDistributorMaster->HandleWorkUnitResults)(
             a1: g_pCurDistributorMaster,
             a2: v1,
             a3: v2) != 0 )
      {
        if ( g_iVMPIVerboseLevel >= 1 )
          _Msg(a1: "-");
        v3 = g_nCompletedWUs + 1;
        v4 = __CFADD__((*(_DWORD *)g_wuCountByProcess.m_Memory.m_pMemory)++, 1);
        *((_DWORD *)g_wuCountByProcess.m_Memory.m_pMemory + 1) += v4;
        ++g_totalWUCountByProcess[0];
        g_nCompletedWUs = v3;
        flPercent = (double)v3 / (double)g_DSInfo.m_nWorkUnits;
        UpdatePacifier(flPercent);
      }
      else
      {
        ++g_nDuplicatedWUs;
        if ( g_iVMPIVerboseLevel >= 1 )
          _Msg(a1: "*");
      }
      if ( ++i >= g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size )
        break;
      v0 = i;
    }
  }
  g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size = 0;
  CCriticalSection::Unlock(this: &g_MasterWorkUnitCompletedList);
}

//------------------------------------------------------------------------------
// Address: 0x1000D3C0
// Name: void NotifyLocalMasterCompletedWorkUnit(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NotifyLocalMasterCompletedWorkUnit(unsigned __int64 iWorkUnit)
{
  CCriticalSection::Lock(this: &g_MasterWorkUnitCompletedList);
  CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertBefore(
    this: &g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs,
    elem: g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size,
    src: &iWorkUnit);
  CCriticalSection::Unlock(this: &g_MasterWorkUnitCompletedList);
}

//------------------------------------------------------------------------------
// Address: 0x1000D3F0
// Name: public: void CVisibleWindowVectorT<unsigned __int64,class CVisibleWindowVector<unsigned __int64>>::ExpandWindow(unsigned __int64,unsigned __int64 const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<unsigned __int64,CVisibleWindowVector<unsigned __int64>>::ExpandWindow(
        CVisibleWindowVectorT<unsigned __int64,CVisibleWindowVector<unsigned __int64> > *this,
        unsigned __int64 idxAccessible,
        const unsigned __int64 *x)
{
  int m_Size; // esi
  int i; // edx

  if ( idxAccessible >= this->m_uiBase + this->m_Size )
  {
    m_Size = this->m_Size;
    CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(
      this,
      elem: m_Size,
      num: idxAccessible - m_Size - LODWORD(this->m_uiBase) + 1);
    for ( i = this->m_Size; m_Size < i; ++m_Size )
      this->m_Memory.m_pMemory[m_Size] = *x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D450
// Name: void ShowMPIStats(double,unsigned long,unsigned long,unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMPIStats(
        long double flTimeSpent,
        unsigned int nBytesSent,
        int nBytesReceived,
        unsigned int nMessagesSent,
        unsigned int nMessagesReceived)
{
  bool IsParamUsed; // al
  int CurrentNumberOfConnections; // esi
  signed int i; // esi
  char *MachineName; // ebx
  char formatStr[512]; // [esp+14h] [ebp-224h] BYREF
  double flKSent; // [esp+214h] [ebp-24h]
  double flKRecv; // [esp+21Ch] [ebp-1Ch]
  CUtlVector<int,CUtlMemory<int,int> > sortedProcs; // [esp+224h] [ebp-14h] BYREF
  int i_4; // [esp+244h] [ebp+Ch]
  bool bOldSuppress_3; // [esp+24Bh] [ebp+13h]
  signed int nRealProcs; // [esp+24Ch] [ebp+14h]

  flKSent = (double)((nBytesSent + 511) >> 10);
  flKRecv = (double)((unsigned int)(nBytesReceived + 511) >> 10);
  IsParamUsed = VMPI_IsParamUsed(eParam: mpi_ShowDistributeWorkStats);
  bOldSuppress_3 = g_bSuppressPrintfOutput;
  g_bSuppressPrintfOutput = !IsParamUsed;
  _Msg(a1: "\n\n--------------------------------------------------------------\n");
  _Msg(a1: "Total Time       : %.2f\n", (double)flTimeSpent);
  _Msg(
    a1: "Total Bytes Sent : %dk (%.2fk/sec, %d messages)\n",
    (int)flKSent,
    (double)(1.0 / flTimeSpent * flKSent),
    nMessagesSent);
  _Msg(
    a1: "Total Bytes Recv : %dk (%.2fk/sec, %d messages)\n",
    (int)flKRecv,
    (double)(1.0 / flTimeSpent * flKRecv),
    nMessagesReceived);
  if ( g_bMPIMaster )
  {
    i_4 = 0;
    _Msg(a1: "Duplicated WUs   : %I64u (%.1f%%)\n", g_nDuplicatedWUs, (double)g_nDuplicatedWUs * 100.0 / (double)g_nWUs);
    _Msg(a1: "\nWU count by proc:\n");
    CurrentNumberOfConnections = VMPI_GetCurrentNumberOfConnections();
    memset(&sortedProcs, 0, sizeof(sortedProcs));
    CUtlVector<char *,CUtlMemory<char *,int>>::InsertMultipleBefore(
      this: &sortedProcs,
      elem: 0,
      num: CurrentNumberOfConnections);
    nRealProcs = 0;
    if ( CurrentNumberOfConnections > 0 )
    {
      do
      {
        if ( VMPI_IsProcValid(procID: i_4) )
          sortedProcs.m_Memory.m_pMemory[nRealProcs++] = i_4;
        ++i_4;
      }
      while ( i_4 < CurrentNumberOfConnections );
    }
    qsort(
      base: sortedProcs.m_Memory.m_pMemory,
      num: nRealProcs,
      width: 4u,
      comp: (int (__cdecl *)(const void *, const void *))SortByWUCount);
    for ( i = 0; i < nRealProcs; ++i )
    {
      MachineName = VMPI_GetMachineName(iProc: sortedProcs.m_Memory.m_pMemory[i]);
      _Msg(a1: "%s", MachineName);
      V_snprintf(
        pDest: formatStr,
        maxLen: 0x200u,
        pFormat: "%%%ds %I64u\n",
        30 - strlen(MachineName),
        g_wuCountByProcess.m_Memory.m_pMemory[sortedProcs.m_Memory.m_pMemory[i]]);
      _Msg(a1: formatStr, ":");
    }
    if ( sortedProcs.m_Memory.m_nGrowSize >= 0 && sortedProcs.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sortedProcs.m_Memory.m_pMemory);
  }
  _Msg(a1: "--------------------------------------------------------------\n\n ");
  g_bSuppressPrintfOutput = bOldSuppress_3;
}

//------------------------------------------------------------------------------
// Address: 0x1000D6F0
// Name: void VMPI_WorkerThread(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_WorkerThread(int iThread, char *pUserData)
{
  unsigned int v2; // ebx
  unsigned __int64 v3; // rdi
  _QWORD *v4; // eax
  _QWORD *v5; // ecx
  unsigned int v6; // ecx
  unsigned __int64 *v7; // eax
  int v8; // eax
  int v9; // ecx
  int Name; // eax
  int v11; // eax
  MessageBuffer mbStartedWorkUnit; // [esp+Ch] [ebp-40h] BYREF
  MessageBuffer mb; // [esp+1Ch] [ebp-30h] BYREF
  _DWORD p[2]; // [esp+2Ch] [ebp-20h] BYREF
  CCriticalSectionLock csLock; // [esp+34h] [ebp-18h] BYREF
  unsigned __int64 idxRunningWorkUnit; // [esp+3Ch] [ebp-10h]
  unsigned __int64 iWU; // [esp+44h] [ebp-8h] BYREF

  v2 = iThread;
  v3 = __PAIR64__((unsigned int)pUserData, iThread);
  idxRunningWorkUnit = iThread;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: (CCriticalSection *)(pUserData + 48));
  CCriticalSectionLock::Lock(this: &csLock);
  iWU = -1;
  CVisibleWindowVectorT<unsigned __int64,CVisibleWindowVector<unsigned __int64>>::ExpandWindow(
    this: (CVisibleWindowVectorT<unsigned __int64,CVisibleWindowVector<unsigned __int64> > *)(HIDWORD(v3) + 8),
    idxAccessible: __PAIR64__(HIDWORD(idxRunningWorkUnit), v3),
    x: &iWU);
  CCriticalSectionLock::Unlock(this: &csLock);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  MessageBuffer::MessageBuffer(this: &mb);
  LOBYTE(iThread) = g_DSInfo.m_cPacketID;
  BYTE1(iThread) = 4;
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&iThread, bytes: 2u);
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&g_iCurDSInfo, bytes: 2u);
  MessageBuffer::MessageBuffer(this: &mbStartedWorkUnit);
  while ( g_iMasterFinishedDistributeWorkCall < g_iCurDSInfo )
  {
    if ( g_bVMPIEarlyExit )
      break;
    if ( g_pCurDistributorWorker->GetNextWorkUnit(this: g_pCurDistributorWorker, a2: &iWU) )
    {
      CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: (CCriticalSection *)(HIDWORD(v3) + 48));
      CCriticalSectionLock::Lock(this: &csLock);
      if ( *(_QWORD *)(HIDWORD(v3) + 32) != 0 || *(_DWORD *)(HIDWORD(v3) + 20) == 0 )
        v4 = nullptr;
      else
        v4 = *(_QWORD **)(HIDWORD(v3) + 8);
      v5 = &v4[*(_DWORD *)(HIDWORD(v3) + 20) + *(_DWORD *)(HIDWORD(v3) + 32)];
      if ( v4 == v5 )
        goto LABEL_14;
      while ( *v4 != iWU )
      {
        if ( ++v4 == v5 )
          goto LABEL_14;
      }
      if ( v4 == v5 )
      {
LABEL_14:
        v6 = *(_DWORD *)(HIDWORD(v3) + 36);
        LODWORD(v3) = *(_DWORD *)(HIDWORD(v3) + 32);
        if ( idxRunningWorkUnit < __PAIR64__(v6, v3)
          || idxRunningWorkUnit >= __PAIR64__(v6, v3) + *(int *)(HIDWORD(v3) + 20) )
        {
          v7 = nullptr;
        }
        else
        {
          v7 = (unsigned __int64 *)(*(_DWORD *)(HIDWORD(v3) + 8) + 8 * (idxRunningWorkUnit - v3));
        }
        *v7 = iWU;
        CCriticalSectionLock::Unlock(this: &csLock);
        MessageBuffer::setLen(this: &mb, nlen: 4);
        MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&iWU, bytes: 8u);
        v8 = HIDWORD(iWU);
        v9 = iWU;
        if ( v2 <= 3 )
        {
          LODWORD(g_ThreadWUs[v2]) = iWU;
          dword_10045B24[2 * v2] = v8;
        }
        p[0] = v9;
        p[1] = v8;
        MessageBuffer::setLen(this: &mbStartedWorkUnit, nlen: 0);
        LOBYTE(iThread) = g_DSInfo.m_cPacketID;
        BYTE1(iThread) = 6;
        MessageBuffer::write(this: &mbStartedWorkUnit, p: (unsigned __int8 *)&iThread, bytes: 2u);
        MessageBuffer::write(this: &mbStartedWorkUnit, p: (unsigned __int8 *)&g_iCurDSInfo, bytes: 2u);
        MessageBuffer::write(this: &mbStartedWorkUnit, (unsigned __int8 *)p, bytes: 8u);
        Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mbStartedWorkUnit);
        VMPI_SendData(pData: mbStartedWorkUnit.data, nBytes: Name, iDest: 0, fVMPISendFlags: 1);
        (*(void (__cdecl **)(unsigned int, _DWORD, _DWORD, MessageBuffer *))HIDWORD(v3))(
          a1: v2,
          a2: iWU,
          a3: HIDWORD(iWU),
          a4: &mb);
        ((void (__thiscall *)(IWorkUnitDistributorWorker *, _DWORD, _DWORD))g_pCurDistributorWorker->NoteLocalWorkUnitCompleted)(
          a1: g_pCurDistributorWorker,
          a2: iWU,
          a3: HIDWORD(iWU));
        v11 = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
        VMPI_SendData(pData: mb.data, nBytes: v11, iDest: 0, fVMPISendFlags: 0);
      }
      CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    }
    else
    {
      VMPI_Sleep(ms: 0xAu);
    }
  }
  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "Worker thread exiting.\n");
  MessageBuffer::~MessageBuffer(this: &mbStartedWorkUnit);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x1000D9B0
// Name: void DistributeWork_Worker(class CDSInfo __near *,void (*)(int,unsigned __int64,class MessageBuffer __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl DistributeWork_Worker(CDSInfo *pInfo, void (__cdecl *processFn)(int, unsigned __int64, MessageBuffer *))
{
  void (__thiscall *Init)(IWorkUnitDistributorWorker *, CDSInfo *); // eax
  unsigned int i; // esi

  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "VMPI_DistributeWork call %d started.\n", g_iCurDSInfo + 1);
  pInfo->m_WorkerInfo.m_pProcessFn = processFn;
  Init = g_pCurDistributorWorker->Init;
  g_pCurWorkerThreadsInfo = pInfo;
  Init(this: g_pCurDistributorWorker, a2: pInfo);
  RunThreads_Start(
    fn: (void (__cdecl *)(int, void *))VMPI_WorkerThread,
    pUserData: pInfo,
    ePriority: g_bSetThreadPriorities ? k_eRunThreadsPriority_Idle : k_eRunThreadsPriority_UseGlobalState);
  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "RunThreads_Start finished successfully.\n");
  if ( VMPI_IsSDKMode() )
  {
    _Msg(a1: "\n");
    while ( g_iMasterFinishedDistributeWorkCall < g_iCurDSInfo )
    {
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0x12C);
      _Msg(a1: "\rThreads status: ");
      for ( i = 0; i < 4; ++i )
      {
        if ( (dword_10045B24[2 * i] & g_ThreadWUs[i]) != 0xFFFFFFFF )
          _Msg(a1: "%d: WU %5d  ", i, LODWORD(g_ThreadWUs[i]));
      }
      VMPI_FlushGroupedPackets(msInterval: 0);
    }
    _Msg(a1: "\n");
  }
  else
  {
    while ( g_iMasterFinishedDistributeWorkCall < g_iCurDSInfo )
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xFFFFFFFF);
  }
  g_pCurWorkerThreadsInfo = nullptr;
  RunThreads_End();
  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "VMPI_DistributeWork call %d finished.\n", g_iCurDSInfo + 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000DB20
// Name: double DistributeWork(unsigned __int64,void (*)(int,unsigned __int64,class MessageBuffer __near *),void (*)(unsigned __int64,class MessageBuffer __near *,int))
// Source: json
//------------------------------------------------------------------------------
long double __usercall DistributeWork@<st0>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        unsigned __int64 nWorkUnits,
        void (__cdecl *processFn)(int, unsigned __int64, MessageBuffer *),
        void (__cdecl *receiveFn)(unsigned __int64, MessageBuffer *, int))
{
  unsigned __int8 *m_pMemory; // eax
  int v7; // esi
  int v8; // edi
  int v9; // ebx
  BOOL ActiveWorkUnitDistributor; // eax
  IWorkUnitDistributorMaster *WUDistributor_SDKMaster; // eax
  IWorkUnitDistributorWorker *WUDistributor_SDKWorker; // eax
  double v13; // st7
  double flTimeSpent; // [esp+24h] [ebp-8h]
  long double flTimeSpenta; // [esp+24h] [ebp-8h]
  int v18; // [esp+38h] [ebp+Ch]

  if ( ++g_iCurDSInfo != 0 )
  {
    if ( g_iCurDSInfo >= 0xFFu )
      _Error(a1: "DistributeWork: called more than %d times.\n", 255);
  }
  else if ( g_bMPIMaster )
  {
    VMPI_AddDisconnectHandler(handler: (void (__cdecl *)(int, const char *))VMPI_DistributeWork_DisconnectHandler);
  }
  g_DSInfo.m_cPacketID = 2;
  g_DSInfo.m_nWorkUnits = nWorkUnits;
  PreDistributeWorkSync();
  g_nCompletedWUs = 0;
  g_nWUs = nWorkUnits;
  g_nDuplicatedWUs = 0;
  flTimeSpent = _Plat_FloatTime(a1: a2, a2: a3);
  g_wuCountByProcess.m_Size = 0;
  if ( g_wuCountByProcess.m_Memory.m_nAllocationCount < 512 )
    CUtlMemory<CTransmitRateMgr::CMachineRecord,int>::Grow(
      this: (CUtlMemory<CTransmitRateMgr::CMachineRecord,int> *)&g_wuCountByProcess,
      num: 512 - g_wuCountByProcess.m_Memory.m_nAllocationCount);
  m_pMemory = (unsigned __int8 *)g_wuCountByProcess.m_Memory.m_pMemory;
  g_wuCountByProcess.m_Size += 512;
  g_wuCountByProcess.m_pElements = g_wuCountByProcess.m_Memory.m_pMemory;
  if ( g_wuCountByProcess.m_Size - 512 > 0 )
  {
    _V_memmove(
      dest: (unsigned __int8 *)g_wuCountByProcess.m_Memory.m_pMemory + 4096,
      src: (unsigned __int8 *)g_wuCountByProcess.m_Memory.m_pMemory,
      count: 8 * (g_wuCountByProcess.m_Size - 512));
    m_pMemory = (unsigned __int8 *)g_wuCountByProcess.m_Memory.m_pMemory;
  }
  memset(dst: m_pMemory, value: 0, count: 4 * g_wuCountByProcess.m_Size);
  v7 = g_nBytesSent;
  v8 = g_nBytesReceived;
  v9 = g_nMessagesSent;
  v18 = g_nMessagesReceived;
  ActiveWorkUnitDistributor = VMPI_GetActiveWorkUnitDistributor();
  if ( g_bMPIMaster )
  {
    if ( ActiveWorkUnitDistributor )
      WUDistributor_SDKMaster = CreateWUDistributor_SDKMaster();
    else
      WUDistributor_SDKMaster = CreateWUDistributor_DefaultMaster();
    g_pCurDistributorMaster = WUDistributor_SDKMaster;
    DistributeWork_Master(pInfo: &g_DSInfo, processFn, receiveFn);
    g_pCurDistributorMaster->Release(this: g_pCurDistributorMaster);
    g_pCurDistributorMaster = nullptr;
  }
  else
  {
    if ( ActiveWorkUnitDistributor )
      WUDistributor_SDKWorker = CreateWUDistributor_SDKWorker();
    else
      WUDistributor_SDKWorker = CreateWUDistributor_DefaultWorker();
    g_pCurDistributorWorker = WUDistributor_SDKWorker;
    DistributeWork_Worker(pInfo: &g_DSInfo, processFn);
    g_pCurDistributorWorker->Release(this: g_pCurDistributorWorker);
    g_pCurDistributorWorker = nullptr;
  }
  v13 = _Plat_FloatTime(a1, a2: LODWORD(flTimeSpent));
  flTimeSpenta = v13 - flTimeSpent;
  ShowMPIStats(
    flTimeSpent: flTimeSpenta,
    nBytesSent: g_nBytesSent - v7,
    nBytesReceived: g_nBytesReceived - v8,
    nMessagesSent: g_nMessagesSent - v9,
    nMessagesReceived: g_nMessagesReceived - v18);
  LODWORD(g_ThreadWUs[0]) = -1;
  dword_10045B24[0] = -1;
  dword_10045B28 = -1;
  dword_10045B2C = -1;
  dword_10045B30 = -1;
  dword_10045B34 = -1;
  dword_10045B38 = -1;
  dword_10045B3C = -1;
  return flTimeSpenta;
}

//------------------------------------------------------------------------------
// Address: 0x100170D0
// Name: public: void CVisibleWindowVectorT<unsigned char,class CVisibleWindowVector<unsigned char>>::ShrinkWindow(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ShrinkWindow(
        CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char> > *this,
        unsigned __int64 idxDrop)
{
  unsigned int m_uiBase; // ebx
  int m_Size; // ecx
  int v5; // edi
  signed int v6; // ecx

  m_uiBase = this->m_uiBase;
  if ( idxDrop >= this->m_uiBase )
  {
    m_Size = this->m_Size;
    if ( idxDrop <= __PAIR64__(HIDWORD(this->m_uiBase), m_uiBase) + this->m_Size )
    {
      v5 = idxDrop - LODWORD(this->m_uiBase) + 1;
      this->m_uiBase += v5;
      if ( v5 >= m_Size )
        v5 = m_Size;
      v6 = m_Size - v5;
      if ( v6 > 0 && v5 > 0 )
        _V_memmove(dest: this->m_Memory.m_pMemory, src: &this->m_Memory.m_pMemory[v5], count: v6);
      this->m_Size -= v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100171A0
// Name: public: void CVisibleWindowVectorT<unsigned char,class CVisibleWindowVector<unsigned char>>::Reset(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::Reset(
        CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char> > *this,
        unsigned __int64 uiTotal)
{
  int v3; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // ecx

  this->m_Size = 0;
  if ( uiTotal <= 0x64 )
    v3 = uiTotal;
  else
    v3 = 100;
  if ( this->m_Memory.m_nAllocationCount < v3 && this->m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = v3;
    if ( m_pMemory != nullptr )
      v5 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v3);
    else
      v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v3);
    this->m_Memory.m_pMemory = v5;
  }
  v6 = this->m_Memory.m_pMemory;
  LODWORD(this->m_uiTotal) = uiTotal;
  LODWORD(this->m_uiBase) = 0;
  HIDWORD(this->m_uiBase) = 0;
  this->m_pElements = v6;
  HIDWORD(this->m_uiTotal) = HIDWORD(uiTotal);
}

//------------------------------------------------------------------------------
// Address: 0x100173B0
// Name: public: void CVisibleWindowVectorT<unsigned char,class CVisibleWindowVector<unsigned char>>::ExpandWindow(unsigned __int64,unsigned char const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ExpandWindow(
        CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char> > *this,
        unsigned __int64 idxAccessible,
        const unsigned __int8 *x)
{
  int m_Size; // ebx
  int v5; // edi
  int v6; // ecx
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // edx
  signed int v9; // eax
  int i; // eax

  m_Size = this->m_Size;
  if ( idxAccessible >= this->m_uiBase + m_Size )
  {
    v5 = idxAccessible - m_Size - LODWORD(this->m_uiBase) + 1;
    v6 = this->m_Size;
    if ( (_DWORD)idxAccessible - m_Size - LODWORD(this->m_uiBase) != -1 )
    {
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( (int)idxAccessible - LODWORD(this->m_uiBase) + 1 > m_nAllocationCount )
      {
        CUtlMemory<bool,int>::Grow(
          this: &this->m_Memory,
          num: idxAccessible - LODWORD(this->m_uiBase) + 1 - m_nAllocationCount);
        v6 = m_Size;
      }
      this->m_Size += v5;
      m_pMemory = this->m_Memory.m_pMemory;
      v9 = this->m_Size - v6 - v5;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v9 > 0 && v5 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + v5], src: &m_pMemory[v6], count: v9);
    }
    for ( i = this->m_Size; m_Size < i; ++m_Size )
      this->m_Memory.m_pMemory[m_Size] = *x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018150
// Name: public: void CVisibleWindowVectorT<class CWULookupInfo,class CVisibleWindowVector<class CWULookupInfo>>::Reset(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo>>::Reset(
        CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo> > *this,
        unsigned __int64 uiTotal)
{
  int v3; // eax
  CWULookupInfo *m_pMemory; // edx
  CWULookupInfo *v5; // eax
  CWULookupInfo *v6; // ecx
  unsigned int v7; // [esp-4h] [ebp-10h]

  this->m_Size = 0;
  if ( uiTotal <= 0x64 )
    v3 = uiTotal;
  else
    v3 = 100;
  if ( this->m_Memory.m_nAllocationCount < v3 && this->m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = v3;
    v7 = 12 * v3;
    if ( m_pMemory != nullptr )
      v5 = (CWULookupInfo *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      v5 = (CWULookupInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
    this->m_Memory.m_pMemory = v5;
  }
  v6 = this->m_Memory.m_pMemory;
  LODWORD(this->m_uiTotal) = uiTotal;
  LODWORD(this->m_uiBase) = 0;
  HIDWORD(this->m_uiBase) = 0;
  this->m_pElements = v6;
  HIDWORD(this->m_uiTotal) = HIDWORD(uiTotal);
}

//------------------------------------------------------------------------------
// Address: 0x100181D0
// Name: public: void CVisibleWindowVectorT<class CWULookupInfo,class CVisibleWindowVector<class CWULookupInfo>>::ShrinkWindow(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo>>::ShrinkWindow(
        CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo> > *this,
        unsigned __int64 idxDrop)
{
  unsigned int m_uiBase; // ebx
  int m_Size; // ecx
  int v5; // edi
  int v6; // ecx

  m_uiBase = this->m_uiBase;
  if ( idxDrop >= this->m_uiBase )
  {
    m_Size = this->m_Size;
    if ( idxDrop <= __PAIR64__(HIDWORD(this->m_uiBase), m_uiBase) + this->m_Size )
    {
      v5 = idxDrop - LODWORD(this->m_uiBase) + 1;
      this->m_uiBase += v5;
      if ( v5 >= m_Size )
        v5 = m_Size;
      v6 = m_Size - v5;
      if ( v6 > 0 && v5 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)this->m_Memory.m_pMemory,
          src: (unsigned __int8 *)&this->m_Memory.m_pMemory[v5],
          count: 12 * v6);
      this->m_Size -= v5;
    }
  }
}

} // namespace texturecompile_dll

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10088A80
// Name: void PrepareDistributeWorkHeader(class MessageBuffer __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrepareDistributeWorkHeader(MessageBuffer *pBuf, unsigned __int8 cSubpacketID)
{
  char cPacketID[4]; // [esp+4h] [ebp-4h] BYREF

  cPacketID[1] = cSubpacketID;
  cPacketID[0] = g_DSInfo.m_cPacketID;
  MessageBuffer::write(this: pBuf, p: (unsigned __int8 *)cPacketID, bytes: 2u);
  MessageBuffer::write(this: pBuf, p: (unsigned __int8 *)&g_iCurDSInfo, bytes: 2u);
}

//------------------------------------------------------------------------------
// Address: 0x10088AC0
// Name: void VMPI_DistributeWork_DisconnectHandler(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_DistributeWork_DisconnectHandler(int procID)
{
  bool v1; // bl

  if ( g_bMasterDistributingWork )
  {
    v1 = g_bSuppressPrintfOutput;
    g_bSuppressPrintfOutput = true;
    _Msg(a1: "VMPI_DistributeWork_DisconnectHandler( %d )\n", procID);
    g_bSuppressPrintfOutput = v1;
    g_pCurDistributorMaster->DisconnectHandler(this: g_pCurDistributorMaster, a2: procID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088B10
// Name: unsigned __int64 VMPI_GetNumWorkUnitsCompleted(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VMPI_GetNumWorkUnitsCompleted(int iProc)
{
  return g_totalWUCountByProcess[iProc];
}

//------------------------------------------------------------------------------
// Address: 0x10088B30
// Name: enum EWorkUnitDistributor VMPI_GetActiveWorkUnitDistributor(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __fastcall VMPI_GetActiveWorkUnitDistributor(int a1, int a2)
{
  int v2; // edx
  int v3; // ecx
  const char *ParamString; // eax
  const char *v6; // eax

  if ( VMPI_IsParamUsed(a1, a2, eParam: mpi_UseSDKDistributor) )
  {
    ParamString = VMPI_GetParamString(eParam: mpi_UseSDKDistributor);
    _Msg(a1: "Found %s.\n", ParamString);
    return true;
  }
  else if ( VMPI_IsParamUsed(a1: v3, a2: v2, eParam: mpi_UseDefaultDistributor) )
  {
    v6 = VMPI_GetParamString(eParam: mpi_UseDefaultDistributor);
    _Msg(a1: "Found %s.\n", v6);
    return false;
  }
  else
  {
    return VMPI_IsSDKMode();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088B90
// Name: void PreDistributeWorkSync(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PreDistributeWorkSync()
{
  int Name; // eax
  int v1; // eax
  MessageBuffer mb; // [esp+0h] [ebp-14h] BYREF
  char p; // [esp+10h] [ebp-4h] BYREF
  char v4; // [esp+11h] [ebp-3h]

  if ( g_bMPIMaster )
  {
    MessageBuffer::MessageBuffer(this: &mb);
    p = g_DSInfo.m_cPacketID;
    v4 = 0;
    MessageBuffer::write(this: &mb, (unsigned __int8 *)&p, bytes: 2u);
    MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&g_iCurDSInfo, bytes: 2u);
    Name = ConCommandBase::GetName(this: (CVTFTexture *)&mb);
    VMPI_SendData(pData: mb.data, nBytes: Name, iDest: -3, fVMPISendFlags: 0);
    MessageBuffer::~MessageBuffer(this: &mb);
  }
  else
  {
    if ( g_iVMPIVerboseLevel >= 1 )
      _Msg(a1: "PreDistributeWorkSync: waiting for master\n");
    while ( g_iMasterReadyForDistributeWorkCall < g_iCurDSInfo )
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xFFFFFFFF);
    if ( g_iVMPIVerboseLevel >= 1 )
      _Msg(a1: "PreDistributeWorkSync: master ready\n");
    MessageBuffer::MessageBuffer(this: &mb);
    p = g_DSInfo.m_cPacketID;
    v4 = 1;
    MessageBuffer::write(this: &mb, (unsigned __int8 *)&p, bytes: 2u);
    MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&g_iCurDSInfo, bytes: 2u);
    v1 = ConCommandBase::GetName(this: (CVTFTexture *)&mb);
    VMPI_SendData(pData: mb.data, nBytes: v1, iDest: 0, fVMPISendFlags: 0);
    MessageBuffer::~MessageBuffer(this: &mb);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088CB0
// Name: void DistributeWork_Cancel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DistributeWork_Cancel()
{
  if ( g_pCurWorkerThreadsInfo != nullptr )
  {
    _Msg(a1: "\nDistributeWork_Cancel saves the day!\n");
    g_pCurWorkerThreadsInfo->m_bMasterFinished = true;
    g_bVMPIEarlyExit = true;
    RunThreads_End();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088CE0
// Name: int SortByWUCount(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortByWUCount(_DWORD *elem1, _DWORD *elem2)
{
  unsigned int v2; // esi
  unsigned int v3; // ecx
  unsigned int v4; // edi
  unsigned int v5; // eax
  bool v6; // zf

  v2 = g_wuCountByProcess.m_Memory.m_pMemory[*elem1];
  v3 = HIDWORD(g_wuCountByProcess.m_Memory.m_pMemory[*elem1]);
  v4 = g_wuCountByProcess.m_Memory.m_pMemory[*elem2];
  v5 = HIDWORD(g_wuCountByProcess.m_Memory.m_pMemory[*elem2]);
  if ( v3 > v5 )
  {
    v6 = v2 == v4;
  }
  else
  {
    if ( v3 < v5 )
      return 1;
    v6 = v2 == v4;
    if ( v2 < v4 )
      return 1;
  }
  if ( v6 && v3 == v5 )
    return 0;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10088D30
// Name: void HandleWorkUnitCompleted(class CDSInfo __near *,int,unsigned __int64,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HandleWorkUnitCompleted(CDSInfo *pInfo, int iSource, unsigned __int64 iWorkUnit, MessageBuffer *pBuf)
{
  unsigned __int64 *m_pMemory; // ecx
  bool v5; // cf
  float flPercent; // [esp+8h] [ebp-10h]

  VMPITracker_WorkUnitCompleted(iWorkUnit, iWorker: iSource);
  if ( ((unsigned __int8 (__thiscall *)(IWorkUnitDistributorMaster *, _DWORD, _DWORD))g_pCurDistributorMaster->HandleWorkUnitResults)(
         a1: g_pCurDistributorMaster,
         a2: iWorkUnit,
         a3: HIDWORD(iWorkUnit)) != 0 )
  {
    if ( g_iVMPIVerboseLevel >= 1 )
      _Msg(a1: "-");
    ++g_nCompletedWUs;
    m_pMemory = g_wuCountByProcess.m_Memory.m_pMemory;
    v5 = __CFADD__(LODWORD(g_wuCountByProcess.m_Memory.m_pMemory[iSource])++, 1);
    HIDWORD(m_pMemory[iSource]) += v5;
    v5 = __CFADD__(LODWORD(g_totalWUCountByProcess[iSource])++, 1);
    HIDWORD(g_totalWUCountByProcess[iSource]) += v5;
    if ( pBuf != nullptr )
      ((void (__cdecl *)(_DWORD, _DWORD, MessageBuffer *, int))pInfo->m_MasterInfo.m_ReceiveFn)(
        a1: iWorkUnit,
        a2: HIDWORD(iWorkUnit),
        a3: pBuf,
        a4: iSource);
    flPercent = (double)g_nCompletedWUs / (double)pInfo->m_nWorkUnits;
    UpdatePacifier(flPercent);
  }
  else
  {
    ++g_nDuplicatedWUs;
    if ( g_iVMPIVerboseLevel >= 1 )
      _Msg(a1: "*");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088E60
// Name: bool DistributeWorkDispatch(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl DistributeWorkDispatch(MessageBuffer *pBuf, int iSource)
{
  int v2; // esi
  bool result; // al
  char *MachineName; // eax
  unsigned int v5; // eax
  unsigned __int64 iWorkUnit; // [esp+Ch] [ebp-8h] BYREF

  v2 = *((unsigned __int16 *)pBuf->data + 1);
  if ( (unsigned __int16)v2 >= 0xFFu )
    _Error(
      a1: "Got an invalid DistributeWork packet (id: %d, sub: %d) (iCurDW: %d).",
      *pBuf->data,
      pBuf->data[1],
      *((unsigned __int16 *)pBuf->data + 1));
  MessageBuffer::setOffset(this: pBuf, noffset: 4);
  switch ( pBuf->data[1] )
  {
    case 0:
      g_iMasterReadyForDistributeWorkCall = v2;
      goto LABEL_5;
    case 1:
      if ( (unsigned __int16)v2 > g_iCurDSInfo || !g_bMPIMaster )
      {
        MachineName = VMPI_GetMachineName(iProc: iSource);
        _Error(a1: "State incorrect on master for DW_SUBPACKETID_WORKER_READY packet from %s.", MachineName);
      }
      if ( (_WORD)v2 == g_iCurDSInfo && g_pCurDistributorMaster != nullptr )
        g_pCurDistributorMaster->OnWorkerReady(this: g_pCurDistributorMaster, a2: iSource);
      return true;
    case 2:
      g_iMasterFinishedDistributeWorkCall = v2;
      return true;
    case 4:
      if ( (_WORD)v2 != g_iCurDSInfo )
        goto LABEL_5;
      MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&iWorkUnit, bytes: 8u);
      v5 = HIDWORD(iWorkUnit);
      if ( iWorkUnit >= g_DSInfo.m_nWorkUnits )
      {
        _Error(
          a1: "DistributeWork: got an invalid work unit index (%I64u for WU count of %I64u).",
          iWorkUnit,
          g_DSInfo.m_nWorkUnits);
        v5 = HIDWORD(iWorkUnit);
      }
      HandleWorkUnitCompleted(pInfo: &g_DSInfo, iSource, iWorkUnit: __PAIR64__(v5, iWorkUnit), pBuf);
      result = true;
      break;
    case 6:
      if ( (_WORD)v2 == g_iCurDSInfo )
      {
        MessageBuffer::read(this: pBuf, p: (unsigned __int8 *)&iWorkUnit, bytes: 8u);
        VMPITracker_WorkUnitStarted(iWorkUnit, iWorker: iSource);
        result = true;
      }
      else
      {
LABEL_5:
        result = true;
      }
      break;
    default:
      if ( g_pCurDistributorMaster != nullptr )
        result = g_pCurDistributorMaster->HandlePacket(
                   this: g_pCurDistributorMaster,
                   a2: pBuf,
                   a3: iSource,
                   a4: (_WORD)v2 != g_iCurDSInfo);
      else
        result = g_pCurDistributorWorker != nullptr
              && g_pCurDistributorWorker->HandlePacket(
                   this: g_pCurDistributorWorker,
                   a2: pBuf,
                   a3: iSource,
                   a4: (_WORD)v2 != g_iCurDSInfo);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10089040
// Name: void DistributeWork_Master(class CDSInfo __near *,void (*)(int,unsigned __int64,class MessageBuffer __near *),void (*)(unsigned __int64,class MessageBuffer __near *,int))
// Source: json
//------------------------------------------------------------------------------
void __cdecl DistributeWork_Master(
        CDSInfo *pInfo,
        void (__cdecl *processFn)(int, unsigned __int64, MessageBuffer *),
        void (__cdecl *receiveFn)(unsigned __int64, MessageBuffer *, int))
{
  void (__cdecl *v3)(unsigned __int64, MessageBuffer *, int); // ecx
  CDSInfo *v4; // esi
  void (__thiscall *v5)(IWorkUnitDistributorMaster *, CDSInfo *); // edx
  int Name; // eax
  int m_nWorkUnits; // [esp-4h] [ebp-18h]
  MessageBuffer mb; // [esp+4h] [ebp-10h] BYREF

  v3 = receiveFn;
  v4 = pInfo;
  m_nWorkUnits = pInfo->m_nWorkUnits;
  pInfo->m_WorkerInfo.m_pProcessFn = processFn;
  v4->m_MasterInfo.m_ReceiveFn = v3;
  VMPITracker_Start(nWorkUnits: m_nWorkUnits);
  v5 = g_pCurDistributorMaster->DistributeWork_Master;
  g_bMasterDistributingWork = true;
  v5(this: g_pCurDistributorMaster, a2: v4);
  g_bMasterDistributingWork = false;
  VMPITracker_End();
  MessageBuffer::MessageBuffer(this: &mb);
  LOBYTE(pInfo) = g_DSInfo.m_cPacketID;
  BYTE1(pInfo) = 2;
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&pInfo, bytes: 2u);
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&g_iCurDSInfo, bytes: 2u);
  Name = ConCommandBase::GetName(this: (CVTFTexture *)&mb);
  VMPI_SendData(pData: mb.data, nBytes: Name, iDest: -3, fVMPISendFlags: 0);
  CCriticalSection::Lock(this: &g_MasterWorkUnitCompletedList);
  g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size = 0;
  CCriticalSection::Unlock(this: &g_MasterWorkUnitCompletedList);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x10089100
// Name: void CheckLocalMasterCompletedWorkUnits(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CheckLocalMasterCompletedWorkUnits()
{
  int v0; // ecx
  int v1; // esi
  int v2; // ebx
  unsigned __int64 v3; // kr00_8
  bool v4; // cf
  float flPercent; // [esp+8h] [ebp-34h]
  int i; // [esp+38h] [ebp-4h]

  CCriticalSection::Lock(this: &g_MasterWorkUnitCompletedList);
  v0 = 0;
  i = 0;
  if ( g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size > 0 )
  {
    while ( 1 )
    {
      v1 = g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Memory.m_pMemory[v0];
      v2 = HIDWORD(g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Memory.m_pMemory[v0]);
      VMPITracker_WorkUnitCompleted(iWorkUnit: v1, iWorker: 0);
      if ( ((unsigned __int8 (__thiscall *)(IWorkUnitDistributorMaster *, int, int))g_pCurDistributorMaster->HandleWorkUnitResults)(
             a1: g_pCurDistributorMaster,
             a2: v1,
             a3: v2) != 0 )
      {
        if ( g_iVMPIVerboseLevel >= 1 )
          _Msg(a1: "-");
        v3 = g_nCompletedWUs + 1;
        v4 = __CFADD__((*(_DWORD *)g_wuCountByProcess.m_Memory.m_pMemory)++, 1);
        *((_DWORD *)g_wuCountByProcess.m_Memory.m_pMemory + 1) += v4;
        ++g_totalWUCountByProcess[0];
        g_nCompletedWUs = v3;
        flPercent = (double)v3 / (double)g_DSInfo.m_nWorkUnits;
        UpdatePacifier(flPercent);
      }
      else
      {
        ++g_nDuplicatedWUs;
        if ( g_iVMPIVerboseLevel >= 1 )
          _Msg(a1: "*");
      }
      if ( ++i >= g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size )
        break;
      v0 = i;
    }
  }
  g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size = 0;
  CCriticalSection::Unlock(this: &g_MasterWorkUnitCompletedList);
}

//------------------------------------------------------------------------------
// Address: 0x10089270
// Name: void NotifyLocalMasterCompletedWorkUnit(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NotifyLocalMasterCompletedWorkUnit(unsigned __int64 iWorkUnit)
{
  CCriticalSection::Lock(this: &g_MasterWorkUnitCompletedList);
  CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
    this: &g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs,
    elem: g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size,
    src: &iWorkUnit);
  CCriticalSection::Unlock(this: &g_MasterWorkUnitCompletedList);
}

//------------------------------------------------------------------------------
// Address: 0x100892A0
// Name: public: void CVisibleWindowVectorT<unsigned __int64,class CVisibleWindowVector<unsigned __int64>>::ExpandWindow(unsigned __int64,unsigned __int64 const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<unsigned __int64,CVisibleWindowVector<unsigned __int64>>::ExpandWindow(
        CVisibleWindowVectorT<unsigned __int64,CVisibleWindowVector<unsigned __int64> > *this,
        unsigned __int64 idxAccessible,
        const unsigned __int64 *x)
{
  int m_Size; // esi
  int i; // edx

  if ( idxAccessible >= this->m_uiBase + this->m_Size )
  {
    m_Size = this->m_Size;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertMultipleBefore(
      (CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *)this,
      elem: m_Size,
      num: idxAccessible - m_Size - LODWORD(this->m_uiBase) + 1);
    for ( i = this->m_Size; m_Size < i; ++m_Size )
      this->m_Memory.m_pMemory[m_Size] = *x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089300
// Name: void ShowMPIStats(double,unsigned long,unsigned long,unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __usercall ShowMPIStats(
        int a1@<edx>,
        long double flTimeSpent,
        unsigned int nBytesSent,
        int nBytesReceived,
        unsigned int nMessagesSent,
        unsigned int nMessagesReceived)
{
  bool IsParamUsed; // al
  int CurrentNumberOfConnections; // esi
  signed int i; // esi
  char *MachineName; // ebx
  char formatStr[512]; // [esp+14h] [ebp-224h] BYREF
  double flKSent; // [esp+214h] [ebp-24h]
  double flKRecv; // [esp+21Ch] [ebp-1Ch]
  CUtlVector<int,CUtlMemory<int,int> > sortedProcs; // [esp+224h] [ebp-14h] BYREF
  int i_4; // [esp+244h] [ebp+Ch]
  signed int bOldSuppress; // [esp+248h] [ebp+10h]
  bool bOldSuppress_3; // [esp+24Bh] [ebp+13h]
  signed int nRealProcs; // [esp+24Ch] [ebp+14h]

  flKSent = (double)((nBytesSent + 511) >> 10);
  bOldSuppress = (unsigned int)(nBytesReceived + 511) >> 10;
  flKRecv = (double)bOldSuppress;
  IsParamUsed = VMPI_IsParamUsed(a1: bOldSuppress, a2: a1, eParam: mpi_ShowDistributeWorkStats);
  bOldSuppress_3 = g_bSuppressPrintfOutput;
  g_bSuppressPrintfOutput = !IsParamUsed;
  _Msg(a1: "\n\n--------------------------------------------------------------\n");
  _Msg(a1: "Total Time       : %.2f\n", (double)flTimeSpent);
  _Msg(
    a1: "Total Bytes Sent : %dk (%.2fk/sec, %d messages)\n",
    (int)flKSent,
    (double)(1.0 / flTimeSpent * flKSent),
    nMessagesSent);
  _Msg(
    a1: "Total Bytes Recv : %dk (%.2fk/sec, %d messages)\n",
    (int)flKRecv,
    (double)(1.0 / flTimeSpent * flKRecv),
    nMessagesReceived);
  if ( g_bMPIMaster )
  {
    i_4 = 0;
    _Msg(a1: "Duplicated WUs   : %I64u (%.1f%%)\n", g_nDuplicatedWUs, (double)g_nDuplicatedWUs * 100.0 / (double)g_nWUs);
    _Msg(a1: "\nWU count by proc:\n");
    CurrentNumberOfConnections = VMPI_GetCurrentNumberOfConnections();
    memset(&sortedProcs, 0, sizeof(sortedProcs));
    CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
      this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&sortedProcs,
      elem: 0,
      num: CurrentNumberOfConnections);
    nRealProcs = 0;
    if ( CurrentNumberOfConnections > 0 )
    {
      do
      {
        if ( VMPI_IsProcValid(procID: i_4) )
          sortedProcs.m_Memory.m_pMemory[nRealProcs++] = i_4;
        ++i_4;
      }
      while ( i_4 < CurrentNumberOfConnections );
    }
    qsort(
      base: sortedProcs.m_Memory.m_pMemory,
      num: nRealProcs,
      width: 4u,
      comp: (int (__cdecl *)(const void *, const void *))SortByWUCount);
    for ( i = 0; i < nRealProcs; ++i )
    {
      MachineName = VMPI_GetMachineName(iProc: sortedProcs.m_Memory.m_pMemory[i]);
      _Msg(a1: "%s", MachineName);
      V_snprintf(
        pDest: formatStr,
        maxLen: 0x200u,
        pFormat: "%%%ds %I64u\n",
        30 - strlen(MachineName),
        g_wuCountByProcess.m_Memory.m_pMemory[sortedProcs.m_Memory.m_pMemory[i]]);
      _Msg(a1: formatStr, ":");
    }
    if ( sortedProcs.m_Memory.m_nGrowSize >= 0 && sortedProcs.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sortedProcs.m_Memory.m_pMemory);
  }
  _Msg(a1: "--------------------------------------------------------------\n\n ");
  g_bSuppressPrintfOutput = bOldSuppress_3;
}

//------------------------------------------------------------------------------
// Address: 0x100895A0
// Name: void VMPI_WorkerThread(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_WorkerThread(int iThread, char *pUserData)
{
  unsigned int v2; // ebx
  unsigned __int64 v3; // rdi
  _QWORD *v4; // eax
  _QWORD *v5; // ecx
  unsigned int v6; // ecx
  unsigned __int64 *v7; // eax
  int v8; // eax
  int v9; // ecx
  int Name; // eax
  int v11; // eax
  MessageBuffer mbStartedWorkUnit; // [esp+Ch] [ebp-40h] BYREF
  MessageBuffer mb; // [esp+1Ch] [ebp-30h] BYREF
  _DWORD p[2]; // [esp+2Ch] [ebp-20h] BYREF
  CCriticalSectionLock csLock; // [esp+34h] [ebp-18h] BYREF
  unsigned __int64 idxRunningWorkUnit; // [esp+3Ch] [ebp-10h]
  unsigned __int64 iWU; // [esp+44h] [ebp-8h] BYREF

  v2 = iThread;
  v3 = __PAIR64__((unsigned int)pUserData, iThread);
  idxRunningWorkUnit = iThread;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: (CCriticalSection *)(pUserData + 48));
  CCriticalSectionLock::Lock(this: &csLock);
  iWU = -1;
  CVisibleWindowVectorT<unsigned __int64,CVisibleWindowVector<unsigned __int64>>::ExpandWindow(
    this: (CVisibleWindowVectorT<unsigned __int64,CVisibleWindowVector<unsigned __int64> > *)(HIDWORD(v3) + 8),
    idxAccessible: __PAIR64__(HIDWORD(idxRunningWorkUnit), v3),
    x: &iWU);
  CCriticalSectionLock::Unlock(this: &csLock);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  MessageBuffer::MessageBuffer(this: &mb);
  LOBYTE(iThread) = g_DSInfo.m_cPacketID;
  BYTE1(iThread) = 4;
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&iThread, bytes: 2u);
  MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&g_iCurDSInfo, bytes: 2u);
  MessageBuffer::MessageBuffer(this: &mbStartedWorkUnit);
  while ( g_iMasterFinishedDistributeWorkCall < g_iCurDSInfo )
  {
    if ( g_bVMPIEarlyExit )
      break;
    if ( g_pCurDistributorWorker->GetNextWorkUnit(this: g_pCurDistributorWorker, a2: &iWU) )
    {
      CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: (CCriticalSection *)(HIDWORD(v3) + 48));
      CCriticalSectionLock::Lock(this: &csLock);
      if ( *(_QWORD *)(HIDWORD(v3) + 32) != 0 || *(_DWORD *)(HIDWORD(v3) + 20) == 0 )
        v4 = nullptr;
      else
        v4 = *(_QWORD **)(HIDWORD(v3) + 8);
      v5 = &v4[*(_DWORD *)(HIDWORD(v3) + 20) + *(_DWORD *)(HIDWORD(v3) + 32)];
      if ( v4 == v5 )
        goto LABEL_14;
      while ( *v4 != iWU )
      {
        if ( ++v4 == v5 )
          goto LABEL_14;
      }
      if ( v4 == v5 )
      {
LABEL_14:
        v6 = *(_DWORD *)(HIDWORD(v3) + 36);
        LODWORD(v3) = *(_DWORD *)(HIDWORD(v3) + 32);
        if ( idxRunningWorkUnit < __PAIR64__(v6, v3)
          || idxRunningWorkUnit >= __PAIR64__(v6, v3) + *(int *)(HIDWORD(v3) + 20) )
        {
          v7 = nullptr;
        }
        else
        {
          v7 = (unsigned __int64 *)(*(_DWORD *)(HIDWORD(v3) + 8) + 8 * (idxRunningWorkUnit - v3));
        }
        *v7 = iWU;
        CCriticalSectionLock::Unlock(this: &csLock);
        MessageBuffer::setLen(this: &mb, nlen: 4);
        MessageBuffer::write(this: &mb, p: (unsigned __int8 *)&iWU, bytes: 8u);
        v8 = HIDWORD(iWU);
        v9 = iWU;
        if ( v2 <= 3 )
        {
          LODWORD(g_ThreadWUs[v2]) = iWU;
          dword_1013735C[2 * v2] = v8;
        }
        p[0] = v9;
        p[1] = v8;
        MessageBuffer::setLen(this: &mbStartedWorkUnit, nlen: 0);
        LOBYTE(iThread) = g_DSInfo.m_cPacketID;
        BYTE1(iThread) = 6;
        MessageBuffer::write(this: &mbStartedWorkUnit, p: (unsigned __int8 *)&iThread, bytes: 2u);
        MessageBuffer::write(this: &mbStartedWorkUnit, p: (unsigned __int8 *)&g_iCurDSInfo, bytes: 2u);
        MessageBuffer::write(this: &mbStartedWorkUnit, (unsigned __int8 *)p, bytes: 8u);
        Name = ConCommandBase::GetName(this: (CVTFTexture *)&mbStartedWorkUnit);
        VMPI_SendData(pData: mbStartedWorkUnit.data, nBytes: Name, iDest: 0, fVMPISendFlags: 1);
        (*(void (__cdecl **)(unsigned int, _DWORD, _DWORD, MessageBuffer *))HIDWORD(v3))(
          a1: v2,
          a2: iWU,
          a3: HIDWORD(iWU),
          a4: &mb);
        ((void (__thiscall *)(IWorkUnitDistributorWorker *, _DWORD, _DWORD))g_pCurDistributorWorker->NoteLocalWorkUnitCompleted)(
          a1: g_pCurDistributorWorker,
          a2: iWU,
          a3: HIDWORD(iWU));
        v11 = ConCommandBase::GetName(this: (CVTFTexture *)&mb);
        VMPI_SendData(pData: mb.data, nBytes: v11, iDest: 0, fVMPISendFlags: 0);
      }
      CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    }
    else
    {
      VMPI_Sleep(ms: 0xAu);
    }
  }
  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "Worker thread exiting.\n");
  MessageBuffer::~MessageBuffer(this: &mbStartedWorkUnit);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x10089860
// Name: void DistributeWork_Worker(class CDSInfo __near *,void (*)(int,unsigned __int64,class MessageBuffer __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl DistributeWork_Worker(CDSInfo *pInfo, void (__cdecl *processFn)(int, unsigned __int64, MessageBuffer *))
{
  void (__thiscall *Init)(IWorkUnitDistributorWorker *, CDSInfo *); // eax
  unsigned int i; // esi

  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "VMPI_DistributeWork call %d started.\n", g_iCurDSInfo + 1);
  pInfo->m_WorkerInfo.m_pProcessFn = processFn;
  Init = g_pCurDistributorWorker->Init;
  g_pCurWorkerThreadsInfo = pInfo;
  Init(this: g_pCurDistributorWorker, a2: pInfo);
  RunThreads_Start(
    fn: (void (__cdecl *)(int, void *))VMPI_WorkerThread,
    pUserData: pInfo,
    ePriority: g_bSetThreadPriorities ? k_eRunThreadsPriority_Idle : k_eRunThreadsPriority_UseGlobalState);
  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "RunThreads_Start finished successfully.\n");
  if ( VMPI_IsSDKMode() )
  {
    _Msg(a1: "\n");
    while ( g_iMasterFinishedDistributeWorkCall < g_iCurDSInfo )
    {
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0x12C);
      _Msg(a1: "\rThreads status: ");
      for ( i = 0; i < 4; ++i )
      {
        if ( (dword_1013735C[2 * i] & g_ThreadWUs[i]) != 0xFFFFFFFF )
          _Msg(a1: "%d: WU %5d  ", i, LODWORD(g_ThreadWUs[i]));
      }
      VMPI_FlushGroupedPackets(msInterval: 0);
    }
    _Msg(a1: "\n");
  }
  else
  {
    while ( g_iMasterFinishedDistributeWorkCall < g_iCurDSInfo )
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xFFFFFFFF);
  }
  g_pCurWorkerThreadsInfo = nullptr;
  RunThreads_End();
  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "VMPI_DistributeWork call %d finished.\n", g_iCurDSInfo + 1);
}

//------------------------------------------------------------------------------
// Address: 0x100899D0
// Name: double DistributeWork(unsigned __int64,void (*)(int,unsigned __int64,class MessageBuffer __near *),void (*)(unsigned __int64,class MessageBuffer __near *,int))
// Source: json
//------------------------------------------------------------------------------
long double __usercall DistributeWork@<st0>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        unsigned __int64 nWorkUnits,
        void (__cdecl *processFn)(int, unsigned __int64, MessageBuffer *),
        void (__cdecl *receiveFn)(unsigned __int64, MessageBuffer *, int))
{
  unsigned __int8 *m_pMemory; // eax
  int v7; // esi
  int v8; // edi
  int v9; // ebx
  int v10; // edx
  int v11; // ecx
  BOOL ActiveWorkUnitDistributor; // eax
  CDistributor_DefaultMaster *WUDistributor_SDKMaster; // eax
  IWorkUnitDistributorWorker *WUDistributor_SDKWorker; // eax
  double v15; // st7
  double flTimeSpent; // [esp+24h] [ebp-8h]
  long double flTimeSpenta; // [esp+24h] [ebp-8h]
  int v20; // [esp+38h] [ebp+Ch]

  if ( ++g_iCurDSInfo != 0 )
  {
    if ( g_iCurDSInfo >= 0xFFu )
      _Error(a1: "DistributeWork: called more than %d times.\n", 255);
  }
  else if ( g_bMPIMaster )
  {
    VMPI_AddDisconnectHandler(handler: (void (__cdecl *)(int, const char *))VMPI_DistributeWork_DisconnectHandler);
  }
  g_DSInfo.m_cPacketID = 2;
  g_DSInfo.m_nWorkUnits = nWorkUnits;
  PreDistributeWorkSync();
  g_nCompletedWUs = 0;
  g_nWUs = nWorkUnits;
  g_nDuplicatedWUs = 0;
  flTimeSpent = _Plat_FloatTime(a1: a2, a2: a3);
  g_wuCountByProcess.m_Size = 0;
  if ( g_wuCountByProcess.m_Memory.m_nAllocationCount < 512 )
    CUtlMemory<CacheOptimizedKDNode,int>::Grow(
      this: (CUtlMemory<ResourceEntryInfo,int> *)&g_wuCountByProcess,
      num: 512 - g_wuCountByProcess.m_Memory.m_nAllocationCount);
  m_pMemory = (unsigned __int8 *)g_wuCountByProcess.m_Memory.m_pMemory;
  g_wuCountByProcess.m_Size += 512;
  g_wuCountByProcess.m_pElements = g_wuCountByProcess.m_Memory.m_pMemory;
  if ( g_wuCountByProcess.m_Size - 512 > 0 )
  {
    _V_memmove(
      dest: (unsigned __int8 *)g_wuCountByProcess.m_Memory.m_pMemory + 4096,
      src: (unsigned __int8 *)g_wuCountByProcess.m_Memory.m_pMemory,
      count: 8 * (g_wuCountByProcess.m_Size - 512));
    m_pMemory = (unsigned __int8 *)g_wuCountByProcess.m_Memory.m_pMemory;
  }
  memset(dst: m_pMemory, value: 0, count: 4 * g_wuCountByProcess.m_Size);
  v7 = g_nBytesSent;
  v8 = g_nBytesReceived;
  v9 = g_nMessagesSent;
  v20 = g_nMessagesReceived;
  ActiveWorkUnitDistributor = VMPI_GetActiveWorkUnitDistributor(a1: v11, a2: v10);
  if ( g_bMPIMaster )
  {
    if ( ActiveWorkUnitDistributor )
      WUDistributor_SDKMaster = (CDistributor_DefaultMaster *)CreateWUDistributor_SDKMaster();
    else
      WUDistributor_SDKMaster = CreateWUDistributor_DefaultMaster();
    g_pCurDistributorMaster = WUDistributor_SDKMaster;
    DistributeWork_Master(pInfo: &g_DSInfo, processFn, receiveFn);
    g_pCurDistributorMaster->Release(this: g_pCurDistributorMaster);
    g_pCurDistributorMaster = nullptr;
  }
  else
  {
    if ( ActiveWorkUnitDistributor )
      WUDistributor_SDKWorker = CreateWUDistributor_SDKWorker();
    else
      WUDistributor_SDKWorker = CreateWUDistributor_DefaultWorker();
    g_pCurDistributorWorker = WUDistributor_SDKWorker;
    DistributeWork_Worker(pInfo: &g_DSInfo, processFn);
    g_pCurDistributorWorker->Release(this: g_pCurDistributorWorker);
    g_pCurDistributorWorker = nullptr;
  }
  v15 = _Plat_FloatTime(a1, a2: LODWORD(flTimeSpent));
  flTimeSpenta = v15 - flTimeSpent;
  ShowMPIStats(
    a1: g_nMessagesSent - v9,
    flTimeSpent: flTimeSpenta,
    nBytesSent: g_nBytesSent - v7,
    nBytesReceived: g_nBytesReceived - v8,
    nMessagesSent: g_nMessagesSent - v9,
    nMessagesReceived: g_nMessagesReceived - v20);
  LODWORD(g_ThreadWUs[0]) = -1;
  dword_1013735C[0] = -1;
  dword_10137360 = -1;
  dword_10137364 = -1;
  dword_10137368 = -1;
  dword_1013736C = -1;
  dword_10137370 = -1;
  dword_10137374 = -1;
  return flTimeSpenta;
}

//------------------------------------------------------------------------------
// Address: 0x10092AA0
// Name: public: void CVisibleWindowVectorT<unsigned char,class CVisibleWindowVector<unsigned char>>::ShrinkWindow(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ShrinkWindow(
        CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char> > *this,
        unsigned __int64 idxDrop)
{
  unsigned int m_uiBase; // ebx
  int m_Size; // ecx
  int v5; // edi
  signed int v6; // ecx

  m_uiBase = this->m_uiBase;
  if ( idxDrop >= this->m_uiBase )
  {
    m_Size = this->m_Size;
    if ( idxDrop <= __PAIR64__(HIDWORD(this->m_uiBase), m_uiBase) + this->m_Size )
    {
      v5 = idxDrop - LODWORD(this->m_uiBase) + 1;
      this->m_uiBase += v5;
      if ( v5 >= m_Size )
        v5 = m_Size;
      v6 = m_Size - v5;
      if ( v6 > 0 && v5 > 0 )
        _V_memmove(dest: this->m_Memory.m_pMemory, src: &this->m_Memory.m_pMemory[v5], count: v6);
      this->m_Size -= v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092B70
// Name: public: void CVisibleWindowVectorT<unsigned char,class CVisibleWindowVector<unsigned char>>::Reset(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::Reset(
        CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char> > *this,
        unsigned __int64 uiTotal)
{
  int v3; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // ecx

  this->m_Size = 0;
  if ( uiTotal <= 0x64 )
    v3 = uiTotal;
  else
    v3 = 100;
  if ( this->m_Memory.m_nAllocationCount < v3 && this->m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = v3;
    if ( m_pMemory != nullptr )
      v5 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v3);
    else
      v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v3);
    this->m_Memory.m_pMemory = v5;
  }
  v6 = this->m_Memory.m_pMemory;
  LODWORD(this->m_uiTotal) = uiTotal;
  LODWORD(this->m_uiBase) = 0;
  HIDWORD(this->m_uiBase) = 0;
  this->m_pElements = v6;
  HIDWORD(this->m_uiTotal) = HIDWORD(uiTotal);
}

//------------------------------------------------------------------------------
// Address: 0x10092D80
// Name: public: void CVisibleWindowVectorT<unsigned char,class CVisibleWindowVector<unsigned char>>::ExpandWindow(unsigned __int64,unsigned char const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ExpandWindow(
        CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char> > *this,
        unsigned __int64 idxAccessible,
        const unsigned __int8 *x)
{
  int m_Size; // ebx
  int v5; // edi
  int v6; // ecx
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // edx
  signed int v9; // eax
  int i; // eax

  m_Size = this->m_Size;
  if ( idxAccessible >= this->m_uiBase + m_Size )
  {
    v5 = idxAccessible - m_Size - LODWORD(this->m_uiBase) + 1;
    v6 = this->m_Size;
    if ( (_DWORD)idxAccessible - m_Size - LODWORD(this->m_uiBase) != -1 )
    {
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( (int)idxAccessible - LODWORD(this->m_uiBase) + 1 > m_nAllocationCount )
      {
        CUtlMemory<char,int>::Grow(
          this: &this->m_Memory,
          num: idxAccessible - LODWORD(this->m_uiBase) + 1 - m_nAllocationCount);
        v6 = m_Size;
      }
      this->m_Size += v5;
      m_pMemory = this->m_Memory.m_pMemory;
      v9 = this->m_Size - v6 - v5;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v9 > 0 && v5 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + v5], src: &m_pMemory[v6], count: v9);
    }
    for ( i = this->m_Size; m_Size < i; ++m_Size )
      this->m_Memory.m_pMemory[m_Size] = *x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093B20
// Name: public: void CVisibleWindowVectorT<class CWULookupInfo,class CVisibleWindowVector<class CWULookupInfo>>::Reset(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo>>::Reset(
        CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo> > *this,
        unsigned __int64 uiTotal)
{
  int v3; // eax
  CWULookupInfo *m_pMemory; // edx
  CWULookupInfo *v5; // eax
  CWULookupInfo *v6; // ecx
  unsigned int v7; // [esp-4h] [ebp-10h]

  this->m_Size = 0;
  if ( uiTotal <= 0x64 )
    v3 = uiTotal;
  else
    v3 = 100;
  if ( this->m_Memory.m_nAllocationCount < v3 && this->m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = v3;
    v7 = 12 * v3;
    if ( m_pMemory != nullptr )
      v5 = (CWULookupInfo *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      v5 = (CWULookupInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
    this->m_Memory.m_pMemory = v5;
  }
  v6 = this->m_Memory.m_pMemory;
  LODWORD(this->m_uiTotal) = uiTotal;
  LODWORD(this->m_uiBase) = 0;
  HIDWORD(this->m_uiBase) = 0;
  this->m_pElements = v6;
  HIDWORD(this->m_uiTotal) = HIDWORD(uiTotal);
}

//------------------------------------------------------------------------------
// Address: 0x10093BA0
// Name: public: void CVisibleWindowVectorT<class CWULookupInfo,class CVisibleWindowVector<class CWULookupInfo>>::ShrinkWindow(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo>>::ShrinkWindow(
        CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo> > *this,
        unsigned __int64 idxDrop)
{
  unsigned int m_uiBase; // ebx
  int m_Size; // ecx
  int v5; // edi
  int v6; // ecx

  m_uiBase = this->m_uiBase;
  if ( idxDrop >= this->m_uiBase )
  {
    m_Size = this->m_Size;
    if ( idxDrop <= __PAIR64__(HIDWORD(this->m_uiBase), m_uiBase) + this->m_Size )
    {
      v5 = idxDrop - LODWORD(this->m_uiBase) + 1;
      this->m_uiBase += v5;
      if ( v5 >= m_Size )
        v5 = m_Size;
      v6 = m_Size - v5;
      if ( v6 > 0 && v5 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)this->m_Memory.m_pMemory,
          src: (unsigned __int8 *)&this->m_Memory.m_pMemory[v5],
          count: 12 * v6);
      this->m_Size -= v5;
    }
  }
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x10027140
// Name: void PrepareDistributeWorkHeader(class MessageBuffer __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrepareDistributeWorkHeader(MessageBuffer *pBuf, unsigned __int8 cSubpacketID)
{
  char cPacketID[4]; // [esp+4h] [ebp-4h] BYREF

  cPacketID[1] = cSubpacketID;
  cPacketID[0] = g_DSInfo.m_cPacketID;
  MessageBuffer::write(this: pBuf, p: cPacketID, bytes: 2);
  MessageBuffer::write(this: pBuf, p: &g_iCurDSInfo, bytes: 2);
}

//------------------------------------------------------------------------------
// Address: 0x10027180
// Name: void VMPI_DistributeWork_DisconnectHandler(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_DistributeWork_DisconnectHandler(int procID)
{
  bool v1; // bl

  if ( g_bMasterDistributingWork )
  {
    v1 = g_bSuppressPrintfOutput;
    g_bSuppressPrintfOutput = true;
    _Msg(a1: "VMPI_DistributeWork_DisconnectHandler( %d )\n", procID);
    g_bSuppressPrintfOutput = v1;
    g_pCurDistributorMaster->DisconnectHandler(this: g_pCurDistributorMaster, a2: procID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100271D0
// Name: unsigned __int64 VMPI_GetNumWorkUnitsCompleted(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl VMPI_GetNumWorkUnitsCompleted(int iProc)
{
  return g_totalWUCountByProcess[iProc];
}

//------------------------------------------------------------------------------
// Address: 0x100271F0
// Name: enum EWorkUnitDistributor VMPI_GetActiveWorkUnitDistributor(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl VMPI_GetActiveWorkUnitDistributor()
{
  const char *ParamString; // eax
  const char *v2; // eax

  if ( VMPI_IsParamUsed(eParam: mpi_UseSDKDistributor) )
  {
    ParamString = VMPI_GetParamString(eParam: mpi_UseSDKDistributor);
    _Msg(a1: "Found %s.\n", ParamString);
    return true;
  }
  else if ( VMPI_IsParamUsed(eParam: mpi_UseDefaultDistributor) )
  {
    v2 = VMPI_GetParamString(eParam: mpi_UseDefaultDistributor);
    _Msg(a1: "Found %s.\n", v2);
    return false;
  }
  else
  {
    return VMPI_IsSDKMode();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027250
// Name: void PreDistributeWorkSync(class CDSInfo __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PreDistributeWorkSync()
{
  int Name; // eax
  int v1; // eax
  MessageBuffer mb; // [esp+0h] [ebp-14h] BYREF
  char p; // [esp+10h] [ebp-4h] BYREF
  char v4; // [esp+11h] [ebp-3h]

  if ( g_bMPIMaster )
  {
    MessageBuffer::MessageBuffer(this: &mb);
    p = g_DSInfo.m_cPacketID;
    v4 = 0;
    MessageBuffer::write(this: &mb, &p, bytes: 2);
    MessageBuffer::write(this: &mb, p: &g_iCurDSInfo, bytes: 2);
    Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
    VMPI_SendData(pData: mb.data, nBytes: Name, iDest: -3, fVMPISendFlags: 0);
    MessageBuffer::~MessageBuffer(this: &mb);
  }
  else
  {
    if ( g_iVMPIVerboseLevel >= 1 )
      _Msg(a1: "PreDistributeWorkSync: waiting for master\n");
    while ( g_iMasterReadyForDistributeWorkCall < g_iCurDSInfo )
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xFFFFFFFF);
    if ( g_iVMPIVerboseLevel >= 1 )
      _Msg(a1: "PreDistributeWorkSync: master ready\n");
    MessageBuffer::MessageBuffer(this: &mb);
    p = g_DSInfo.m_cPacketID;
    v4 = 1;
    MessageBuffer::write(this: &mb, &p, bytes: 2);
    MessageBuffer::write(this: &mb, p: &g_iCurDSInfo, bytes: 2);
    v1 = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
    VMPI_SendData(pData: mb.data, nBytes: v1, iDest: 0, fVMPISendFlags: 0);
    MessageBuffer::~MessageBuffer(this: &mb);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027370
// Name: void DistributeWork_Cancel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DistributeWork_Cancel()
{
  if ( g_pCurWorkerThreadsInfo != nullptr )
  {
    _Msg(a1: "\nDistributeWork_Cancel saves the day!\n");
    g_pCurWorkerThreadsInfo->m_bMasterFinished = true;
    g_bVMPIEarlyExit = true;
    RunThreads_End();
  }
}

//------------------------------------------------------------------------------
// Address: 0x100273A0
// Name: int SortByWUCount(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortByWUCount(_DWORD *elem1, _DWORD *elem2)
{
  unsigned int v2; // esi
  unsigned int v3; // ecx
  unsigned int v4; // edi
  unsigned int v5; // eax
  bool v6; // zf

  v2 = g_wuCountByProcess.m_Memory.m_pMemory[*elem1];
  v3 = HIDWORD(g_wuCountByProcess.m_Memory.m_pMemory[*elem1]);
  v4 = g_wuCountByProcess.m_Memory.m_pMemory[*elem2];
  v5 = HIDWORD(g_wuCountByProcess.m_Memory.m_pMemory[*elem2]);
  if ( v3 > v5 )
  {
    v6 = v2 == v4;
  }
  else
  {
    if ( v3 < v5 )
      return 1;
    v6 = v2 == v4;
    if ( v2 < v4 )
      return 1;
  }
  if ( v6 && v3 == v5 )
    return 0;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100273F0
// Name: void HandleWorkUnitCompleted(class CDSInfo __near *,int,unsigned __int64,class MessageBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HandleWorkUnitCompleted(CDSInfo *pInfo, int iSource, unsigned __int64 iWorkUnit, MessageBuffer *pBuf)
{
  unsigned __int64 *m_pMemory; // ecx
  bool v5; // cf
  float flPercent; // [esp+8h] [ebp-10h]

  VMPITracker_WorkUnitCompleted(iWorkUnit, iWorker: iSource);
  if ( ((unsigned __int8 (__thiscall *)(IWorkUnitDistributorMaster *, _DWORD, _DWORD))g_pCurDistributorMaster->HandleWorkUnitResults)(
         a1: g_pCurDistributorMaster,
         a2: iWorkUnit,
         a3: HIDWORD(iWorkUnit)) != 0 )
  {
    if ( g_iVMPIVerboseLevel >= 1 )
      _Msg(a1: "-");
    ++g_nCompletedWUs;
    m_pMemory = g_wuCountByProcess.m_Memory.m_pMemory;
    v5 = __CFADD__(LODWORD(g_wuCountByProcess.m_Memory.m_pMemory[iSource])++, 1);
    HIDWORD(m_pMemory[iSource]) += v5;
    v5 = __CFADD__(LODWORD(g_totalWUCountByProcess[iSource])++, 1);
    HIDWORD(g_totalWUCountByProcess[iSource]) += v5;
    if ( pBuf != nullptr )
      ((void (__cdecl *)(_DWORD, _DWORD, MessageBuffer *, int))pInfo->m_MasterInfo.m_ReceiveFn)(
        a1: iWorkUnit,
        a2: HIDWORD(iWorkUnit),
        a3: pBuf,
        a4: iSource);
    flPercent = (double)g_nCompletedWUs / (double)pInfo->m_nWorkUnits;
    UpdatePacifier(flPercent);
  }
  else
  {
    ++g_nDuplicatedWUs;
    if ( g_iVMPIVerboseLevel >= 1 )
      _Msg(a1: "*");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027520
// Name: bool DistributeWorkDispatch(class MessageBuffer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl DistributeWorkDispatch(MessageBuffer *pBuf, int iSource)
{
  int v2; // esi
  bool result; // al
  char *MachineName; // eax
  unsigned int v5; // eax
  unsigned __int64 iWorkUnit; // [esp+Ch] [ebp-8h] BYREF

  v2 = *((unsigned __int16 *)pBuf->data + 1);
  if ( (unsigned __int16)v2 >= 0xFFu )
    _Error(
      a1: "Got an invalid DistributeWork packet (id: %d, sub: %d) (iCurDW: %d).",
      *pBuf->data,
      pBuf->data[1],
      *((unsigned __int16 *)pBuf->data + 1));
  MessageBuffer::setOffset(this: pBuf, noffset: 4);
  switch ( pBuf->data[1] )
  {
    case 0:
      g_iMasterReadyForDistributeWorkCall = v2;
      goto LABEL_5;
    case 1:
      if ( (unsigned __int16)v2 > g_iCurDSInfo || !g_bMPIMaster )
      {
        MachineName = VMPI_GetMachineName(iProc: iSource);
        _Error(a1: "State incorrect on master for DW_SUBPACKETID_WORKER_READY packet from %s.", MachineName);
      }
      if ( (_WORD)v2 == g_iCurDSInfo && g_pCurDistributorMaster != nullptr )
        g_pCurDistributorMaster->OnWorkerReady(this: g_pCurDistributorMaster, a2: iSource);
      return true;
    case 2:
      g_iMasterFinishedDistributeWorkCall = v2;
      return true;
    case 4:
      if ( (_WORD)v2 != g_iCurDSInfo )
        goto LABEL_5;
      MessageBuffer::read(this: pBuf, p: &iWorkUnit, bytes: 8);
      v5 = HIDWORD(iWorkUnit);
      if ( iWorkUnit >= g_DSInfo.m_nWorkUnits )
      {
        _Error(
          a1: "DistributeWork: got an invalid work unit index (%I64u for WU count of %I64u).",
          iWorkUnit,
          g_DSInfo.m_nWorkUnits);
        v5 = HIDWORD(iWorkUnit);
      }
      HandleWorkUnitCompleted(pInfo: &g_DSInfo, iSource, iWorkUnit: __PAIR64__(v5, iWorkUnit), pBuf);
      result = true;
      break;
    case 6:
      if ( (_WORD)v2 == g_iCurDSInfo )
      {
        MessageBuffer::read(this: pBuf, p: &iWorkUnit, bytes: 8);
        VMPITracker_WorkUnitStarted(iWorkUnit, iWorker: iSource);
        result = true;
      }
      else
      {
LABEL_5:
        result = true;
      }
      break;
    default:
      if ( g_pCurDistributorMaster != nullptr )
        result = g_pCurDistributorMaster->HandlePacket(
                   this: g_pCurDistributorMaster,
                   a2: pBuf,
                   a3: iSource,
                   a4: (_WORD)v2 != g_iCurDSInfo);
      else
        result = g_pCurDistributorWorker != nullptr
              && g_pCurDistributorWorker->HandlePacket(
                   this: g_pCurDistributorWorker,
                   a2: pBuf,
                   a3: iSource,
                   a4: (_WORD)v2 != g_iCurDSInfo);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10027700
// Name: void DistributeWork_Master(class CDSInfo __near *,void (*)(int,unsigned __int64,class MessageBuffer __near *),void (*)(unsigned __int64,class MessageBuffer __near *,int))
// Source: json
//------------------------------------------------------------------------------
void __cdecl DistributeWork_Master(
        CDSInfo *pInfo,
        void (__cdecl *processFn)(int, unsigned __int64, MessageBuffer *),
        void (__cdecl *receiveFn)(unsigned __int64, MessageBuffer *, int))
{
  void (__cdecl *v3)(unsigned __int64, MessageBuffer *, int); // ecx
  CDSInfo *v4; // esi
  void (__thiscall *v5)(IWorkUnitDistributorMaster *, CDSInfo *); // edx
  int Name; // eax
  int m_nWorkUnits; // [esp-4h] [ebp-18h]
  MessageBuffer mb; // [esp+4h] [ebp-10h] BYREF

  v3 = receiveFn;
  v4 = pInfo;
  m_nWorkUnits = pInfo->m_nWorkUnits;
  pInfo->m_WorkerInfo.m_pProcessFn = processFn;
  v4->m_MasterInfo.m_ReceiveFn = v3;
  VMPITracker_Start(nWorkUnits: m_nWorkUnits);
  v5 = g_pCurDistributorMaster->DistributeWork_Master;
  g_bMasterDistributingWork = true;
  v5(this: g_pCurDistributorMaster, a2: v4);
  g_bMasterDistributingWork = false;
  VMPITracker_End();
  MessageBuffer::MessageBuffer(this: &mb);
  LOBYTE(pInfo) = g_DSInfo.m_cPacketID;
  BYTE1(pInfo) = 2;
  MessageBuffer::write(this: &mb, p: &pInfo, bytes: 2);
  MessageBuffer::write(this: &mb, p: &g_iCurDSInfo, bytes: 2);
  Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
  VMPI_SendData(pData: mb.data, nBytes: Name, iDest: -3, fVMPISendFlags: 0);
  CCriticalSection::Lock(this: &g_MasterWorkUnitCompletedList);
  g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size = 0;
  CCriticalSection::Unlock(this: &g_MasterWorkUnitCompletedList);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x100277C0
// Name: void CheckLocalMasterCompletedWorkUnits(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CheckLocalMasterCompletedWorkUnits()
{
  int v0; // ecx
  int v1; // esi
  int v2; // ebx
  unsigned __int64 v3; // kr00_8
  bool v4; // cf
  float flPercent; // [esp+8h] [ebp-34h]
  int i; // [esp+38h] [ebp-4h]

  CCriticalSection::Lock(this: &g_MasterWorkUnitCompletedList);
  v0 = 0;
  i = 0;
  if ( g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size > 0 )
  {
    while ( 1 )
    {
      v1 = g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Memory.m_pMemory[v0];
      v2 = HIDWORD(g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Memory.m_pMemory[v0]);
      VMPITracker_WorkUnitCompleted(iWorkUnit: v1, iWorker: 0);
      if ( ((unsigned __int8 (__thiscall *)(IWorkUnitDistributorMaster *, int, int))g_pCurDistributorMaster->HandleWorkUnitResults)(
             a1: g_pCurDistributorMaster,
             a2: v1,
             a3: v2) != 0 )
      {
        if ( g_iVMPIVerboseLevel >= 1 )
          _Msg(a1: "-");
        v3 = g_nCompletedWUs + 1;
        v4 = __CFADD__((*(_DWORD *)g_wuCountByProcess.m_Memory.m_pMemory)++, 1);
        *((_DWORD *)g_wuCountByProcess.m_Memory.m_pMemory + 1) += v4;
        ++g_totalWUCountByProcess[0];
        g_nCompletedWUs = v3;
        flPercent = (double)v3 / (double)g_DSInfo.m_nWorkUnits;
        UpdatePacifier(flPercent);
      }
      else
      {
        ++g_nDuplicatedWUs;
        if ( g_iVMPIVerboseLevel >= 1 )
          _Msg(a1: "*");
      }
      if ( ++i >= g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size )
        break;
      v0 = i;
    }
  }
  g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size = 0;
  CCriticalSection::Unlock(this: &g_MasterWorkUnitCompletedList);
}

//------------------------------------------------------------------------------
// Address: 0x10027A10
// Name: void NotifyLocalMasterCompletedWorkUnit(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NotifyLocalMasterCompletedWorkUnit(unsigned __int64 iWorkUnit)
{
  CCriticalSection::Lock(this: &g_MasterWorkUnitCompletedList);
  CUtlVector<variable_t,CUtlMemory<variable_t,int>>::InsertBefore(
    this: &g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs,
    elem: g_MasterWorkUnitCompletedList.m_Data.m_CompletedWUs.m_Size,
    src: &iWorkUnit);
  CCriticalSection::Unlock(this: &g_MasterWorkUnitCompletedList);
}

//------------------------------------------------------------------------------
// Address: 0x10027A40
// Name: public: void CVisibleWindowVectorT<unsigned __int64,class CVisibleWindowVector<unsigned __int64>>::ExpandWindow(unsigned __int64,unsigned __int64 const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<unsigned __int64,CVisibleWindowVector<unsigned __int64>>::ExpandWindow(
        CVisibleWindowVectorT<unsigned __int64,CVisibleWindowVector<unsigned __int64> > *this,
        unsigned __int64 idxAccessible,
        const unsigned __int64 *x)
{
  int m_Size; // esi
  int i; // edx

  if ( idxAccessible >= this->m_uiBase + this->m_Size )
  {
    m_Size = this->m_Size;
    CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertMultipleBefore(
      this,
      elem: m_Size,
      num: idxAccessible - m_Size - LODWORD(this->m_uiBase) + 1);
    for ( i = this->m_Size; m_Size < i; ++m_Size )
      this->m_Memory.m_pMemory[m_Size] = *x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027AA0
// Name: void ShowMPIStats(double,unsigned long,unsigned long,unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowMPIStats(
        long double flTimeSpent,
        unsigned int nBytesSent,
        int nBytesReceived,
        unsigned int nMessagesSent,
        unsigned int nMessagesReceived)
{
  bool IsParamUsed; // al
  int CurrentNumberOfConnections; // esi
  signed int i; // esi
  char *MachineName; // ebx
  char formatStr[512]; // [esp+14h] [ebp-224h] BYREF
  double flKSent; // [esp+214h] [ebp-24h]
  double flKRecv; // [esp+21Ch] [ebp-1Ch]
  CUtlVector<int,CUtlMemory<int,int> > sortedProcs; // [esp+224h] [ebp-14h] BYREF
  int i_4; // [esp+244h] [ebp+Ch]
  bool bOldSuppress_3; // [esp+24Bh] [ebp+13h]
  signed int nRealProcs; // [esp+24Ch] [ebp+14h]

  flKSent = (double)((nBytesSent + 511) >> 10);
  flKRecv = (double)((unsigned int)(nBytesReceived + 511) >> 10);
  IsParamUsed = VMPI_IsParamUsed(eParam: mpi_ShowDistributeWorkStats);
  bOldSuppress_3 = g_bSuppressPrintfOutput;
  g_bSuppressPrintfOutput = !IsParamUsed;
  _Msg(a1: "\n\n--------------------------------------------------------------\n");
  _Msg(a1: "Total Time       : %.2f\n", (double)flTimeSpent);
  _Msg(
    a1: "Total Bytes Sent : %dk (%.2fk/sec, %d messages)\n",
    (int)flKSent,
    (double)(1.0 / flTimeSpent * flKSent),
    nMessagesSent);
  _Msg(
    a1: "Total Bytes Recv : %dk (%.2fk/sec, %d messages)\n",
    (int)flKRecv,
    (double)(1.0 / flTimeSpent * flKRecv),
    nMessagesReceived);
  if ( g_bMPIMaster )
  {
    i_4 = 0;
    _Msg(a1: "Duplicated WUs   : %I64u (%.1f%%)\n", g_nDuplicatedWUs, (double)g_nDuplicatedWUs * 100.0 / (double)g_nWUs);
    _Msg(a1: "\nWU count by proc:\n");
    CurrentNumberOfConnections = VMPI_GetCurrentNumberOfConnections();
    memset(&sortedProcs, 0, sizeof(sortedProcs));
    CUtlVector<dfacebrushlist_t,CUtlMemory<dfacebrushlist_t,int>>::InsertMultipleBefore(
      this: (CUtlVector<CVMPIConnection *,CUtlMemory<CVMPIConnection *,int> > *)&sortedProcs,
      elem: 0,
      num: CurrentNumberOfConnections);
    nRealProcs = 0;
    if ( CurrentNumberOfConnections > 0 )
    {
      do
      {
        if ( VMPI_IsProcValid(procID: i_4) )
          sortedProcs.m_Memory.m_pMemory[nRealProcs++] = i_4;
        ++i_4;
      }
      while ( i_4 < CurrentNumberOfConnections );
    }
    qsort(
      base: sortedProcs.m_Memory.m_pMemory,
      num: nRealProcs,
      width: 4u,
      comp: (int (__cdecl *)(const void *, const void *))SortByWUCount);
    for ( i = 0; i < nRealProcs; ++i )
    {
      MachineName = VMPI_GetMachineName(iProc: sortedProcs.m_Memory.m_pMemory[i]);
      _Msg(a1: "%s", MachineName);
      V_snprintf(
        pDest: formatStr,
        maxLen: 0x200u,
        pFormat: "%%%ds %I64u\n",
        30 - strlen(MachineName),
        g_wuCountByProcess.m_Memory.m_pMemory[sortedProcs.m_Memory.m_pMemory[i]]);
      _Msg(a1: formatStr, ":");
    }
    if ( sortedProcs.m_Memory.m_nGrowSize >= 0 && sortedProcs.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sortedProcs.m_Memory.m_pMemory);
  }
  _Msg(a1: "--------------------------------------------------------------\n\n ");
  g_bSuppressPrintfOutput = bOldSuppress_3;
}

//------------------------------------------------------------------------------
// Address: 0x10027D40
// Name: void VMPI_WorkerThread(int,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VMPI_WorkerThread(int iThread, char *pUserData)
{
  unsigned int v2; // ebx
  unsigned __int64 v3; // rdi
  _QWORD *v4; // eax
  _QWORD *v5; // ecx
  unsigned int v6; // ecx
  unsigned __int64 *v7; // eax
  int v8; // eax
  int v9; // ecx
  int Name; // eax
  int v11; // eax
  MessageBuffer mbStartedWorkUnit; // [esp+Ch] [ebp-40h] BYREF
  MessageBuffer mb; // [esp+1Ch] [ebp-30h] BYREF
  _DWORD p[2]; // [esp+2Ch] [ebp-20h] BYREF
  CCriticalSectionLock csLock; // [esp+34h] [ebp-18h] BYREF
  unsigned __int64 idxRunningWorkUnit; // [esp+3Ch] [ebp-10h]
  unsigned __int64 iWU; // [esp+44h] [ebp-8h] BYREF

  v2 = iThread;
  v3 = __PAIR64__((unsigned int)pUserData, iThread);
  idxRunningWorkUnit = iThread;
  CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: (CCriticalSection *)(pUserData + 48));
  CCriticalSectionLock::Lock(this: &csLock);
  iWU = -1;
  CVisibleWindowVectorT<unsigned __int64,CVisibleWindowVector<unsigned __int64>>::ExpandWindow(
    this: (CVisibleWindowVectorT<unsigned __int64,CVisibleWindowVector<unsigned __int64> > *)(HIDWORD(v3) + 8),
    idxAccessible: __PAIR64__(HIDWORD(idxRunningWorkUnit), v3),
    x: &iWU);
  CCriticalSectionLock::Unlock(this: &csLock);
  CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
  MessageBuffer::MessageBuffer(this: &mb);
  LOBYTE(iThread) = g_DSInfo.m_cPacketID;
  BYTE1(iThread) = 4;
  MessageBuffer::write(this: &mb, p: &iThread, bytes: 2);
  MessageBuffer::write(this: &mb, p: &g_iCurDSInfo, bytes: 2);
  MessageBuffer::MessageBuffer(this: &mbStartedWorkUnit);
  while ( g_iMasterFinishedDistributeWorkCall < g_iCurDSInfo )
  {
    if ( g_bVMPIEarlyExit )
      break;
    if ( g_pCurDistributorWorker->GetNextWorkUnit(this: g_pCurDistributorWorker, a2: &iWU) )
    {
      CCriticalSectionLock::CCriticalSectionLock(this: &csLock, pCS: (CCriticalSection *)(HIDWORD(v3) + 48));
      CCriticalSectionLock::Lock(this: &csLock);
      if ( *(_QWORD *)(HIDWORD(v3) + 32) != 0 || *(_DWORD *)(HIDWORD(v3) + 20) == 0 )
        v4 = nullptr;
      else
        v4 = *(_QWORD **)(HIDWORD(v3) + 8);
      v5 = &v4[*(_DWORD *)(HIDWORD(v3) + 20) + *(_DWORD *)(HIDWORD(v3) + 32)];
      if ( v4 == v5 )
        goto LABEL_14;
      while ( *v4 != iWU )
      {
        if ( ++v4 == v5 )
          goto LABEL_14;
      }
      if ( v4 == v5 )
      {
LABEL_14:
        v6 = *(_DWORD *)(HIDWORD(v3) + 36);
        LODWORD(v3) = *(_DWORD *)(HIDWORD(v3) + 32);
        if ( idxRunningWorkUnit < __PAIR64__(v6, v3)
          || idxRunningWorkUnit >= __PAIR64__(v6, v3) + *(int *)(HIDWORD(v3) + 20) )
        {
          v7 = nullptr;
        }
        else
        {
          v7 = (unsigned __int64 *)(*(_DWORD *)(HIDWORD(v3) + 8) + 8 * (idxRunningWorkUnit - v3));
        }
        *v7 = iWU;
        CCriticalSectionLock::Unlock(this: &csLock);
        MessageBuffer::setLen(this: &mb, nlen: 4);
        MessageBuffer::write(this: &mb, p: &iWU, bytes: 8);
        v8 = HIDWORD(iWU);
        v9 = iWU;
        if ( v2 <= 3 )
        {
          LODWORD(g_ThreadWUs[v2]) = iWU;
          dword_10088324[2 * v2] = v8;
        }
        p[0] = v9;
        p[1] = v8;
        MessageBuffer::setLen(this: &mbStartedWorkUnit, nlen: 0);
        LOBYTE(iThread) = g_DSInfo.m_cPacketID;
        BYTE1(iThread) = 6;
        MessageBuffer::write(this: &mbStartedWorkUnit, p: &iThread, bytes: 2);
        MessageBuffer::write(this: &mbStartedWorkUnit, p: &g_iCurDSInfo, bytes: 2);
        MessageBuffer::write(this: &mbStartedWorkUnit, p, bytes: 8);
        Name = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mbStartedWorkUnit);
        VMPI_SendData(pData: mbStartedWorkUnit.data, nBytes: Name, iDest: 0, fVMPISendFlags: 1);
        (*(void (__cdecl **)(unsigned int, _DWORD, _DWORD, MessageBuffer *))HIDWORD(v3))(
          a1: v2,
          a2: iWU,
          a3: HIDWORD(iWU),
          a4: &mb);
        ((void (__thiscall *)(IWorkUnitDistributorWorker *, _DWORD, _DWORD))g_pCurDistributorWorker->NoteLocalWorkUnitCompleted)(
          a1: g_pCurDistributorWorker,
          a2: iWU,
          a3: HIDWORD(iWU));
        v11 = ConCommandBase::GetName(this: (CVMPIFile_Memory *)&mb);
        VMPI_SendData(pData: mb.data, nBytes: v11, iDest: 0, fVMPISendFlags: 0);
      }
      CCriticalSectionLock::~CCriticalSectionLock(this: &csLock);
    }
    else
    {
      VMPI_Sleep(ms: 0xAu);
    }
  }
  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "Worker thread exiting.\n");
  MessageBuffer::~MessageBuffer(this: &mbStartedWorkUnit);
  MessageBuffer::~MessageBuffer(this: &mb);
}

//------------------------------------------------------------------------------
// Address: 0x10028000
// Name: void DistributeWork_Worker(class CDSInfo __near *,void (*)(int,unsigned __int64,class MessageBuffer __near *))
// Source: json
//------------------------------------------------------------------------------
void __cdecl DistributeWork_Worker(CDSInfo *pInfo, void (__cdecl *processFn)(int, unsigned __int64, MessageBuffer *))
{
  void (__thiscall *Init)(IWorkUnitDistributorWorker *, CDSInfo *); // eax
  unsigned int i; // esi

  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "VMPI_DistributeWork call %d started.\n", g_iCurDSInfo + 1);
  pInfo->m_WorkerInfo.m_pProcessFn = processFn;
  Init = g_pCurDistributorWorker->Init;
  g_pCurWorkerThreadsInfo = pInfo;
  Init(this: g_pCurDistributorWorker, a2: pInfo);
  RunThreads_Start(
    fn: (void (__cdecl *)(int, void *))VMPI_WorkerThread,
    pUserData: pInfo,
    ePriority: g_bSetThreadPriorities ? k_eRunThreadsPriority_Idle : k_eRunThreadsPriority_UseGlobalState);
  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "RunThreads_Start finished successfully.\n");
  if ( VMPI_IsSDKMode() )
  {
    _Msg(a1: "\n");
    while ( g_iMasterFinishedDistributeWorkCall < g_iCurDSInfo )
    {
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0x12C);
      _Msg(a1: "\rThreads status: ");
      for ( i = 0; i < 4; ++i )
      {
        if ( (dword_10088324[2 * i] & g_ThreadWUs[i]) != 0xFFFFFFFF )
          _Msg(a1: "%d: WU %5d  ", i, LODWORD(g_ThreadWUs[i]));
      }
      VMPI_FlushGroupedPackets(msInterval: 0);
    }
    _Msg(a1: "\n");
  }
  else
  {
    while ( g_iMasterFinishedDistributeWorkCall < g_iCurDSInfo )
      VMPI_DispatchNextMessage(timeout: (CTCPPacket *)0xFFFFFFFF);
  }
  g_pCurWorkerThreadsInfo = nullptr;
  RunThreads_End();
  if ( g_iVMPIVerboseLevel >= 1 )
    _Msg(a1: "VMPI_DistributeWork call %d finished.\n", g_iCurDSInfo + 1);
}

//------------------------------------------------------------------------------
// Address: 0x10028170
// Name: double DistributeWork(unsigned __int64,void (*)(int,unsigned __int64,class MessageBuffer __near *),void (*)(unsigned __int64,class MessageBuffer __near *,int))
// Source: json
//------------------------------------------------------------------------------
long double __usercall DistributeWork@<st0>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        unsigned __int64 nWorkUnits,
        void (__cdecl *processFn)(int, unsigned __int64, MessageBuffer *),
        void (__cdecl *receiveFn)(unsigned __int64, MessageBuffer *, int))
{
  unsigned __int8 *m_pMemory; // eax
  int v7; // esi
  int v8; // edi
  int v9; // ebx
  BOOL ActiveWorkUnitDistributor; // eax
  IWorkUnitDistributorMaster *WUDistributor_SDKMaster; // eax
  IWorkUnitDistributorWorker *WUDistributor_SDKWorker; // eax
  double v13; // st7
  double flTimeSpent; // [esp+24h] [ebp-8h]
  long double flTimeSpenta; // [esp+24h] [ebp-8h]
  int v18; // [esp+38h] [ebp+Ch]

  if ( ++g_iCurDSInfo != 0 )
  {
    if ( g_iCurDSInfo >= 0xFFu )
      _Error(a1: "DistributeWork: called more than %d times.\n", 255);
  }
  else if ( g_bMPIMaster )
  {
    VMPI_AddDisconnectHandler(handler: (void (__cdecl *)(int, const char *))VMPI_DistributeWork_DisconnectHandler);
  }
  g_DSInfo.m_cPacketID = 2;
  g_DSInfo.m_nWorkUnits = nWorkUnits;
  PreDistributeWorkSync();
  g_nCompletedWUs = 0;
  g_nWUs = nWorkUnits;
  g_nDuplicatedWUs = 0;
  flTimeSpent = _Plat_FloatTime(a1: a2, a2: a3);
  g_wuCountByProcess.m_Size = 0;
  if ( g_wuCountByProcess.m_Memory.m_nAllocationCount < 512 )
    CUtlMemory<CTransmitRateMgr::CMachineRecord,int>::Grow(
      this: (CUtlMemory<CTransmitRateMgr::CMachineRecord,int> *)&g_wuCountByProcess,
      num: 512 - g_wuCountByProcess.m_Memory.m_nAllocationCount);
  m_pMemory = (unsigned __int8 *)g_wuCountByProcess.m_Memory.m_pMemory;
  g_wuCountByProcess.m_Size += 512;
  g_wuCountByProcess.m_pElements = g_wuCountByProcess.m_Memory.m_pMemory;
  if ( g_wuCountByProcess.m_Size - 512 > 0 )
  {
    _V_memmove(
      dest: (unsigned __int8 *)g_wuCountByProcess.m_Memory.m_pMemory + 4096,
      src: (unsigned __int8 *)g_wuCountByProcess.m_Memory.m_pMemory,
      count: 8 * (g_wuCountByProcess.m_Size - 512));
    m_pMemory = (unsigned __int8 *)g_wuCountByProcess.m_Memory.m_pMemory;
  }
  memset(dst: m_pMemory, value: 0, count: 4 * g_wuCountByProcess.m_Size);
  v7 = g_nBytesSent;
  v8 = g_nBytesReceived;
  v9 = g_nMessagesSent;
  v18 = g_nMessagesReceived;
  ActiveWorkUnitDistributor = VMPI_GetActiveWorkUnitDistributor();
  if ( g_bMPIMaster )
  {
    if ( ActiveWorkUnitDistributor )
      WUDistributor_SDKMaster = CreateWUDistributor_SDKMaster();
    else
      WUDistributor_SDKMaster = CreateWUDistributor_DefaultMaster();
    g_pCurDistributorMaster = WUDistributor_SDKMaster;
    DistributeWork_Master(pInfo: &g_DSInfo, processFn, receiveFn);
    g_pCurDistributorMaster->Release(this: g_pCurDistributorMaster);
    g_pCurDistributorMaster = nullptr;
  }
  else
  {
    if ( ActiveWorkUnitDistributor )
      WUDistributor_SDKWorker = CreateWUDistributor_SDKWorker();
    else
      WUDistributor_SDKWorker = CreateWUDistributor_DefaultWorker();
    g_pCurDistributorWorker = WUDistributor_SDKWorker;
    DistributeWork_Worker(pInfo: &g_DSInfo, processFn);
    g_pCurDistributorWorker->Release(this: g_pCurDistributorWorker);
    g_pCurDistributorWorker = nullptr;
  }
  v13 = _Plat_FloatTime(a1, a2: LODWORD(flTimeSpent));
  flTimeSpenta = v13 - flTimeSpent;
  ShowMPIStats(
    flTimeSpent: flTimeSpenta,
    nBytesSent: g_nBytesSent - v7,
    nBytesReceived: g_nBytesReceived - v8,
    nMessagesSent: g_nMessagesSent - v9,
    nMessagesReceived: g_nMessagesReceived - v18);
  LODWORD(g_ThreadWUs[0]) = -1;
  dword_10088324[0] = -1;
  dword_10088328 = -1;
  dword_1008832C = -1;
  dword_10088330 = -1;
  dword_10088334 = -1;
  dword_10088338 = -1;
  dword_1008833C = -1;
  return flTimeSpenta;
}

//------------------------------------------------------------------------------
// Address: 0x10031450
// Name: public: void CVisibleWindowVectorT<unsigned char,class CVisibleWindowVector<unsigned char>>::ShrinkWindow(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ShrinkWindow(
        CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char> > *this,
        unsigned __int64 idxDrop)
{
  unsigned int m_uiBase; // ebx
  int m_Size; // ecx
  int v5; // edi
  signed int v6; // ecx

  m_uiBase = this->m_uiBase;
  if ( idxDrop >= this->m_uiBase )
  {
    m_Size = this->m_Size;
    if ( idxDrop <= __PAIR64__(HIDWORD(this->m_uiBase), m_uiBase) + this->m_Size )
    {
      v5 = idxDrop - LODWORD(this->m_uiBase) + 1;
      this->m_uiBase += v5;
      if ( v5 >= m_Size )
        v5 = m_Size;
      v6 = m_Size - v5;
      if ( v6 > 0 && v5 > 0 )
        _V_memmove(dest: this->m_Memory.m_pMemory, src: &this->m_Memory.m_pMemory[v5], count: v6);
      this->m_Size -= v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100314C0
// Name: public: void CVisibleWindowVectorT<unsigned char,class CVisibleWindowVector<unsigned char>>::Reset(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::Reset(
        CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char> > *this,
        unsigned __int64 uiTotal)
{
  int v3; // eax
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // ecx

  this->m_Size = 0;
  if ( uiTotal <= 0x64 )
    v3 = uiTotal;
  else
    v3 = 100;
  if ( this->m_Memory.m_nAllocationCount < v3 && this->m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = v3;
    if ( m_pMemory != nullptr )
      v5 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v3);
    else
      v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v3);
    this->m_Memory.m_pMemory = v5;
  }
  v6 = this->m_Memory.m_pMemory;
  LODWORD(this->m_uiTotal) = uiTotal;
  LODWORD(this->m_uiBase) = 0;
  HIDWORD(this->m_uiBase) = 0;
  this->m_pElements = v6;
  HIDWORD(this->m_uiTotal) = HIDWORD(uiTotal);
}

//------------------------------------------------------------------------------
// Address: 0x100317C0
// Name: public: void CVisibleWindowVectorT<unsigned char,class CVisibleWindowVector<unsigned char>>::ExpandWindow(unsigned __int64,unsigned char const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char>>::ExpandWindow(
        CVisibleWindowVectorT<unsigned char,CVisibleWindowVector<unsigned char> > *this,
        unsigned __int64 idxAccessible,
        const unsigned __int8 *x)
{
  int m_Size; // ebx
  int v5; // edi
  int v6; // ecx
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // edx
  signed int v9; // eax
  int i; // eax

  m_Size = this->m_Size;
  if ( idxAccessible >= this->m_uiBase + m_Size )
  {
    v5 = idxAccessible - m_Size - LODWORD(this->m_uiBase) + 1;
    v6 = this->m_Size;
    if ( (_DWORD)idxAccessible - m_Size - LODWORD(this->m_uiBase) != -1 )
    {
      m_nAllocationCount = this->m_Memory.m_nAllocationCount;
      if ( (int)idxAccessible - LODWORD(this->m_uiBase) + 1 > m_nAllocationCount )
      {
        CUtlMemory<char,int>::Grow(
          this: &this->m_Memory,
          num: idxAccessible - LODWORD(this->m_uiBase) + 1 - m_nAllocationCount);
        v6 = m_Size;
      }
      this->m_Size += v5;
      m_pMemory = this->m_Memory.m_pMemory;
      v9 = this->m_Size - v6 - v5;
      this->m_pElements = this->m_Memory.m_pMemory;
      if ( v9 > 0 && v5 > 0 )
        _V_memmove(dest: &m_pMemory[v6 + v5], src: &m_pMemory[v6], count: v9);
    }
    for ( i = this->m_Size; m_Size < i; ++m_Size )
      this->m_Memory.m_pMemory[m_Size] = *x;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10032560
// Name: public: void CVisibleWindowVectorT<class CWULookupInfo,class CVisibleWindowVector<class CWULookupInfo>>::Reset(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo>>::Reset(
        CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo> > *this,
        unsigned __int64 uiTotal)
{
  int v3; // eax
  CWULookupInfo *m_pMemory; // edx
  CWULookupInfo *v5; // eax
  CWULookupInfo *v6; // ecx
  unsigned int v7; // [esp-4h] [ebp-10h]

  this->m_Size = 0;
  if ( uiTotal <= 0x64 )
    v3 = uiTotal;
  else
    v3 = 100;
  if ( this->m_Memory.m_nAllocationCount < v3 && this->m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = v3;
    v7 = 12 * v3;
    if ( m_pMemory != nullptr )
      v5 = (CWULookupInfo *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      v5 = (CWULookupInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
    this->m_Memory.m_pMemory = v5;
  }
  v6 = this->m_Memory.m_pMemory;
  LODWORD(this->m_uiTotal) = uiTotal;
  LODWORD(this->m_uiBase) = 0;
  HIDWORD(this->m_uiBase) = 0;
  this->m_pElements = v6;
  HIDWORD(this->m_uiTotal) = HIDWORD(uiTotal);
}

//------------------------------------------------------------------------------
// Address: 0x100325E0
// Name: public: void CVisibleWindowVectorT<class CWULookupInfo,class CVisibleWindowVector<class CWULookupInfo>>::ShrinkWindow(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo>>::ShrinkWindow(
        CVisibleWindowVectorT<CWULookupInfo,CVisibleWindowVector<CWULookupInfo> > *this,
        unsigned __int64 idxDrop)
{
  unsigned int m_uiBase; // ebx
  int m_Size; // ecx
  int v5; // edi
  int v6; // ecx

  m_uiBase = this->m_uiBase;
  if ( idxDrop >= this->m_uiBase )
  {
    m_Size = this->m_Size;
    if ( idxDrop <= __PAIR64__(HIDWORD(this->m_uiBase), m_uiBase) + this->m_Size )
    {
      v5 = idxDrop - LODWORD(this->m_uiBase) + 1;
      this->m_uiBase += v5;
      if ( v5 >= m_Size )
        v5 = m_Size;
      v6 = m_Size - v5;
      if ( v6 > 0 && v5 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)this->m_Memory.m_pMemory,
          src: (unsigned __int8 *)&this->m_Memory.m_pMemory[v5],
          count: 12 * v6);
      this->m_Size -= v5;
    }
  }
}

} // namespace vvis_dll
