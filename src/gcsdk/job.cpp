// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/job.cpp
// Functions: 26
// ============================================================

#include "gcsdk\job.h"

//------------------------------------------------------------------------------
// Address: 0x1000E510
// Name: protected: virtual unsigned int GCSDK::CJob::CHeartbeatsBeforeTimeout(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GCSDK::CJob::CHeartbeatsBeforeTimeout(GCSDK::CGCClientJob *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10016790
// Name: public: char const __near * GCSDK::CJob::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall GCSDK::CJob::GetName(GCSDK::CJob *this)
{
  const GCSDK::JobType_t *m_pJobType; // eax
  const char *result; // eax
  type_info *v3; // eax

  m_pJobType = this->m_pJobType;
  if ( m_pJobType != nullptr )
    return m_pJobType->m_pchName;
  v3 = (type_info *)__RTtypeid(inptr: this);
  result = type_info::raw_name(this: v3);
  if ( *result == 46 && result[1] == 63 && result[2] == 65 )
    result += 4;
  if ( *result == 63 && result[1] == 36 )
    result += 2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100167D0
// Name: private: static void GCSDK::CJob::BRunProxy(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GCSDK::CJob::BRunProxy(_DWORD *pvThis)
{
  void (__thiscall **v1)(_DWORD *, int); // eax
  char v2; // al

  v1 = (void (__thiscall **)(_DWORD *, int))*pvThis;
  if ( (pvThis[2] & 1) != 0 )
    v2 = ((int (__thiscall *)(_DWORD *, _DWORD))v1[2])(a1: pvThis, a2: pvThis[31]);
  else
    v2 = ((int (__thiscall *)(_DWORD *, _DWORD))v1[1])(a1: pvThis, a2: pvThis[7]);
  pvThis[8] ^= (pvThis[8] ^ (v2 != 1)) & 1;
  (*(void (__thiscall **)(_DWORD *, int))*pvThis)(a1: pvThis, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10016810
// Name: public: bool GCSDK::CJob::BYieldingWaitForMsg(class GCSDK::CNetPacket __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CJob::BYieldingWaitForMsg(GCSDK::CJob *this, GCSDK::CNetPacket **ppNetPacket)
{
  *ppNetPacket = nullptr;
  if ( !GCSDK::CJobMgr::BYieldingWaitForMsg(this: this->m_JobMgr, job: this) )
    return 0;
  *ppNetPacket = this->m_pNetPackets;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10016850
// Name: public: void GCSDK::CJob::EndPause(enum GCSDK::EJobPauseReason)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJob::EndPause(GCSDK::CJob *this, GCSDK::EJobPauseReason eExpectedState)
{
  if ( this->m_ePauseReason == eExpectedState )
    this->m_ePauseReason = k_EJobPauseReasonYield;
}

//------------------------------------------------------------------------------
// Address: 0x10016870
// Name: protected: void GCSDK::CJob::Heartbeat(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJob::Heartbeat(GCSDK::CJob *this)
{
  GCSDK::CJobTime::SetFromJobTime(this: &this->m_STimeNextHeartbeat, dMicroSecOffset: 10000000);
}

//------------------------------------------------------------------------------
// Address: 0x10016880
// Name: public: bool GCSDK::CJob::BYieldingWaitOneFrame(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GCSDK::CJob::BYieldingWaitOneFrame(GCSDK::CJob *this)
{
  return GCSDK::CJobMgr::BYieldingWaitTime(this: this->m_JobMgr, job: this, cMicrosecondsToSleep: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x10016890
// Name: private: void GCSDK::CJob::AddJobToNotifyOnLockRelease(class GCSDK::CJob __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJob::AddJobToNotifyOnLockRelease(GCSDK::CJob *this, GCSDK::CJob *pJob)
{
  GCSDK::CJob **p_m_pJobToNotifyOnLockRelease; // eax
  GCSDK::CJob *v3; // ecx
  bool v4; // zf

  p_m_pJobToNotifyOnLockRelease = &this->m_pJobToNotifyOnLockRelease;
  if ( this->m_pJobToNotifyOnLockRelease != nullptr )
  {
    do
    {
      v3 = *p_m_pJobToNotifyOnLockRelease;
      v4 = (*p_m_pJobToNotifyOnLockRelease)->m_pJobToNotifyOnLockRelease == nullptr;
      p_m_pJobToNotifyOnLockRelease = &(*p_m_pJobToNotifyOnLockRelease)->m_pJobToNotifyOnLockRelease;
    }
    while ( !v4 );
    v3->m_pJobToNotifyOnLockRelease = pJob;
  }
  else
  {
    this->m_pJobToNotifyOnLockRelease = pJob;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100168C0
// Name: public: void GCSDK::CLock::AddToWaitingQueue(class GCSDK::CJob __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CLock::AddToWaitingQueue(GCSDK::CLock *this, GCSDK::CJob *pJob)
{
  GCSDK::CJob *m_pJobWaitingQueueTail; // eax
  GCSDK::CJob *m_pJobToNotifyOnLockRelease; // ecx

  m_pJobWaitingQueueTail = this->m_pJobWaitingQueueTail;
  if ( m_pJobWaitingQueueTail != nullptr )
  {
    m_pJobToNotifyOnLockRelease = m_pJobWaitingQueueTail->m_pJobToNotifyOnLockRelease;
    if ( m_pJobToNotifyOnLockRelease != nullptr )
      GCSDK::CJob::AddJobToNotifyOnLockRelease(this: m_pJobToNotifyOnLockRelease, pJob);
    else
      m_pJobWaitingQueueTail->m_pJobToNotifyOnLockRelease = pJob;
    ++this->m_unWaitingCount;
    this->m_pJobWaitingQueueTail = pJob;
  }
  else
  {
    ++this->m_unWaitingCount;
    this->m_pJobToNotifyOnLockRelease = pJob;
    this->m_pJobWaitingQueueTail = pJob;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016910
// Name: public: char const __near * GCSDK::CJob::GetPauseReasonDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall GCSDK::CJob::GetPauseReasonDescription(GCSDK::CJob *this)
{
  GCSDK::EJobPauseReason m_ePauseReason; // eax
  GCSDK::CLock *m_pWaitingOnLock; // eax
  const char *v4; // eax

  m_ePauseReason = this->m_ePauseReason;
  if ( (unsigned int)m_ePauseReason >= 0xA )
    return "undefined";
  if ( m_ePauseReason != k_EJobPauseReasonWaitingForLock )
    return k_prgchJobPauseReason[m_ePauseReason];
  m_pWaitingOnLock = this->m_pWaitingOnLock;
  if ( m_pWaitingOnLock != nullptr )
    v4 = CUtlString::operator char const *(this: &m_pWaitingOnLock->m_sName);
  else
    v4 = "null";
  V_snprintf(pDest: srgchPauseReason, maxLen: 255, pFormat: "WOL: 0x%x (%s)", this->m_pWaitingOnLock, v4);
  return srgchPauseReason;
}

//------------------------------------------------------------------------------
// Address: 0x10016970
// Name: public: void GCSDK::CJob::AddPacketToList(class GCSDK::CNetPacket __near *,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJob::AddPacketToList(
        GCSDK::CJob *this,
        GCSDK::CNetPacket *pNetPacket,
        unsigned __int64 gidJobIDSrc)
{
  GCSDK::CNetPacket *m_pNetPackets; // eax

  GCSDK::CNetPacket::AddRef(this: pNetPacket);
  m_pNetPackets = this->m_pNetPackets;
  if ( m_pNetPackets != nullptr )
    pNetPacket->m_pNext = m_pNetPackets;
  this->m_pNetPackets = pNetPacket;
}

//------------------------------------------------------------------------------
// Address: 0x100169A0
// Name: private: void GCSDK::CJob::Continue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJob::Continue(GCSDK::CJob *this)
{
  const GCSDK::JobType_t *m_pJobType; // eax

  this->m_pJobPrev = GCSDK::g_pJobCur;
  GCSDK::g_pJobCur = this;
  this->m_FastTimerDelta.m_Duration.m_Int64 = __rdtsc();
  GCSDK::CJobTime::SetToJobTime(this: &this->m_STimeSwitched);
  if ( (((unsigned __int64)GCSDK::CJobTime::CServerMicroSecsPassed(this: &this->m_STimeNextHeartbeat) >> 32) & 0x80000000) == 0LL )
    GCSDK::CJobTime::SetFromJobTime(this: &this->m_STimeNextHeartbeat, dMicroSecOffset: 10000000);
  ++this->m_JobMgr->m_JobStats.m_cTimeslices;
  m_pJobType = this->m_pJobType;
  this->m_ePauseReason = k_EJobPauseReasonNone;
  if ( m_pJobType != nullptr && m_pJobType->m_pchName != nullptr && !s_bCurrentlyProfilingJob )
  {
    s_bCurrentlyProfilingJob = true;
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: m_pJobType->m_pchName,
      a3: 0,
      a4: "Jobs/Coroutines",
      a5: false);
    _Coroutine_Continue(a1: this->m_hCoroutine, a2: defaultValue);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    s_bCurrentlyProfilingJob = false;
  }
  else
  {
    _Coroutine_Continue(a1: this->m_hCoroutine, a2: defaultValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016A80
// Name: private: void GCSDK::CJob::Pause(enum GCSDK::EJobPauseReason)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJob::Pause(GCSDK::CJob *this, GCSDK::EJobPauseReason eReason)
{
  unsigned __int64 v2; // kr00_8
  bool v3; // cf
  unsigned __int64 v4; // [esp-Ch] [ebp-1Ch]
  unsigned __int64 v5; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int64 *v6; // [esp+Ch] [ebp-4h]

  GCSDK::g_pJobCur = this->m_pJobPrev;
  v6 = &v5;
  v5 = __rdtsc();
  v2 = v5 - this->m_FastTimerDelta.m_Duration.m_Int64;
  this->m_FastTimerDelta.m_Duration.m_Int64 = v2;
  v3 = __CFADD__((_DWORD)v2, this->m_cyclecountTotal.m_Int64);
  LODWORD(this->m_cyclecountTotal.m_Int64) += v2;
  HIDWORD(this->m_cyclecountTotal.m_Int64) += HIDWORD(this->m_FastTimerDelta.m_Duration.m_Int64) + v3;
  HIDWORD(v4) = HIDWORD(_g_ClockSpeed);
  LODWORD(v4) = _g_ClockSpeed;
  if ( (unsigned int)(1000000 * this->m_FastTimerDelta.m_Duration.m_Int64 / v4) > 0xC350 )
    this->m_flags.m_uFlags |= 0x20u;
  this->m_ePauseReason = eReason;
  _Coroutine_YieldToMain();
}

//------------------------------------------------------------------------------
// Address: 0x10016B10
// Name: public: void GCSDK::CJob::StartJobFromNetworkMsg(class GCSDK::CNetPacket __near *,unsigned __int64 const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJob::StartJobFromNetworkMsg(
        GCSDK::CJob *this,
        GCSDK::CNetPacket *pNetPacket,
        const unsigned __int64 *gidJobIDSrc)
{
  GCSDK::CNetPacket *m_pNetPackets; // eax

  GCSDK::CNetPacket::AddRef(this: pNetPacket);
  m_pNetPackets = this->m_pNetPackets;
  if ( m_pNetPackets != nullptr )
    pNetPacket->m_pNext = m_pNetPackets;
  *((_DWORD *)this + 2) |= 1u;
  this->m_pNetPackets = pNetPacket;
  GCSDK::CJob::Continue(this);
}

//------------------------------------------------------------------------------
// Address: 0x10016B40
// Name: public: void GCSDK::CJob::StartJob(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJob::StartJob(GCSDK::CJob *this, void *pvStartParam)
{
  GCSDK::CJobMgr *m_JobMgr; // ecx

  m_JobMgr = this->m_JobMgr;
  this->m_pvStartParam = pvStartParam;
  GCSDK::CJobMgr::CheckThreadID(this: m_JobMgr);
  GCSDK::CJob::Continue(this);
}

//------------------------------------------------------------------------------
// Address: 0x10016B60
// Name: public: GCSDK::CJob::CJob(class GCSDK::CJobMgr __near &)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CJob *__thiscall GCSDK::CJob::CJob(GCSDK::CJob *this, GCSDK::CJobMgr *jobMgr)
{
  unsigned __int64 NewJobID; // rax
  int v4; // eax
  GCSDK::CJobMgr *m_JobMgr; // ecx

  this->__vftable = (GCSDK::CJob_vtbl *)&GCSDK::CJob::`vftable';
  GCSDK::CJobTime::CJobTime(this: &this->m_STimeStarted);
  GCSDK::CJobTime::CJobTime(this: &this->m_STimeSwitched);
  GCSDK::CJobTime::CJobTime(this: &this->m_STimeNextHeartbeat);
  this->m_FastTimerDelta.m_Duration.m_Int64 = 0;
  this->m_cyclecountTotal.m_Int64 = 0;
  this->m_vecLocks.m_Memory.m_pMemory = nullptr;
  this->m_vecLocks.m_Memory.m_nAllocationCount = 0;
  this->m_vecLocks.m_Memory.m_nGrowSize = 0;
  this->m_vecLocks.m_Size = 0;
  this->m_vecLocks.m_pElements = nullptr;
  this->m_JobMgr = jobMgr;
  this->m_ePauseReason = k_EJobPauseReasonNotStarted;
  NewJobID = GCSDK::CJobMgr::GetNewJobID(this: jobMgr);
  *((_DWORD *)this + 2) &= ~2u;
  this->m_JobID = NewJobID;
  this->m_pJobType = nullptr;
  this->m_pNetPackets = nullptr;
  v4 = _Coroutine_Create(a1: GCSDK::CJob::BRunProxy, a2: this);
  *((_DWORD *)this + 2) &= ~1u;
  this->m_hCoroutine = v4;
  this->m_pvStartParam = nullptr;
  this->m_pJobPrev = nullptr;
  this->m_pWaitingOnLock = nullptr;
  this->m_pJobToNotifyOnLockRelease = nullptr;
  GCSDK::CJobTime::SetToJobTime(this: &this->m_STimeStarted);
  GCSDK::CJobTime::SetToJobTime(this: &this->m_STimeSwitched);
  GCSDK::CJobTime::SetFromJobTime(this: &this->m_STimeNextHeartbeat, dMicroSecOffset: 10000000);
  m_JobMgr = this->m_JobMgr;
  *((_DWORD *)this + 2) &= ~8u;
  this->m_cLocksAttempted = 0;
  this->m_cLocksWaitedFor = 0;
  this->m_flags.m_uFlags = 0;
  this->m_cyclecountTotal.m_Int64 = 0;
  GCSDK::CJobMgr::InsertJob(this: m_JobMgr, job: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10016C30
// Name: private: void GCSDK::CJob::UnsetLock(class GCSDK::CLock __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJob::UnsetLock(GCSDK::CJob *this, GCSDK::CLock *pLock)
{
  GCSDK::CLock *v2; // esi
  GCSDK::CJobTime *p_m_sTimeAcquired; // ecx
  const char *v5; // eax
  const char *v6; // eax
  double v7; // [esp+0h] [ebp-20h]
  double v8; // [esp+4h] [ebp-1Ch]
  const char *Name; // [esp+8h] [ebp-18h]

  v2 = pLock;
  p_m_sTimeAcquired = &pLock->m_sTimeAcquired;
  pLock->m_pJob = nullptr;
  if ( GCSDK::CJobTime::CServerMicroSecsPassed(this: p_m_sTimeAcquired) >= 10000000 )
  {
    this->m_flags.m_uFlags |= 4u;
    if ( v2->m_pJobToNotifyOnLockRelease != nullptr )
    {
      v2->m_pJobToNotifyOnLockRelease->m_flags.m_uFlags |= 8u;
      Name = GCSDK::CJob::GetName(this: v2->m_pJobToNotifyOnLockRelease);
      v7 = (double)GCSDK::CJobTime::CServerMicroSecsPassed(this: &v2->m_sTimeAcquired) * 0.000001;
      v5 = GCSDK::CJob::GetName(this);
      GCSDK::EmitWarning(
        pchGroupName: SPEW_JOB_13,
        iLevel: 4,
        pchMsg: "Job of type %s held lock for %.2f seconds while job of type %s was waiting\n",
        v5,
        v7,
        Name);
    }
    else
    {
      v8 = (double)GCSDK::CJobTime::CServerMicroSecsPassed(this: &v2->m_sTimeAcquired) * 0.000001;
      v6 = GCSDK::CJob::GetName(this);
      GCSDK::EmitWarning(
        pchGroupName: SPEW_JOB_13,
        iLevel: 4,
        pchMsg: "Job of type %s held lock for %.2f seconds\n",
        v6,
        v8);
    }
  }
  CUtlVector<GCSDK::CLock *,CUtlMemory<GCSDK::CLock *,int>>::FindAndRemove(this: &this->m_vecLocks, src: &pLock);
}

//------------------------------------------------------------------------------
// Address: 0x10016D10
// Name: private: void GCSDK::CJob::OnLockDeleted(class GCSDK::CLock __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJob::OnLockDeleted(GCSDK::CJob *this, GCSDK::CLock *pLock)
{
  const GCSDK::JobType_t *m_pJobType; // eax
  const char *m_pchName; // eax
  type_info *v5; // eax
  GCSDK::CJob *i; // esi
  GCSDK::CJob **p_m_pJobToNotifyOnLockRelease; // eax

  m_pJobType = this->m_pJobType;
  if ( m_pJobType != nullptr )
  {
    m_pchName = m_pJobType->m_pchName;
  }
  else
  {
    v5 = (type_info *)__RTtypeid(inptr: this);
    m_pchName = type_info::raw_name(this: v5);
    if ( *m_pchName == 46 && m_pchName[1] == 63 && m_pchName[2] == 65 )
      m_pchName += 4;
    if ( *m_pchName == 63 && m_pchName[1] == 36 )
      m_pchName += 2;
  }
  GCSDK::EmitWarning(pchGroupName: SPEW_JOB_13, iLevel: 1, pchMsg: "Deleting lock %s\n", m_pchName);
  for ( i = pLock->m_pJobToNotifyOnLockRelease; i != nullptr; *p_m_pJobToNotifyOnLockRelease = nullptr )
  {
    GCSDK::CJobMgr::WakeupLockedJob(this: i->m_JobMgr, job: i);
    p_m_pJobToNotifyOnLockRelease = &i->m_pJobToNotifyOnLockRelease;
    i = i->m_pJobToNotifyOnLockRelease;
  }
  this->m_pJobToNotifyOnLockRelease = nullptr;
  pLock->m_pJobToNotifyOnLockRelease = nullptr;
  pLock->m_pJobWaitingQueueTail = nullptr;
  GCSDK::CJob::UnsetLock(this, pLock);
}

//------------------------------------------------------------------------------
// Address: 0x10016DC0
// Name: public: GCSDK::CLock::CLock(void)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CLock *__thiscall GCSDK::CLock::CLock(GCSDK::CLock *this)
{
  this->m_pJob = nullptr;
  this->m_pJobToNotifyOnLockRelease = nullptr;
  this->m_pJobWaitingQueueTail = nullptr;
  GCSDK::CJobTime::CJobTime(this: &this->m_sTimeAcquired);
  this->m_unWaitingCount = 0;
  CUtlString::CUtlString(this: &this->m_sName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10016E00
// Name: public: GCSDK::CLock::~CLock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CLock::~CLock(GCSDK::CLock *this)
{
  GCSDK::CJob *m_pJob; // ecx
  bool v3; // sf

  m_pJob = this->m_pJob;
  if ( m_pJob != nullptr )
    GCSDK::CJob::OnLockDeleted(this: m_pJob, pLock: this);
  v3 = this->m_sName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_sName.m_Storage.m_nActualLength = 0;
  if ( !v3 )
  {
    if ( this->m_sName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sName.m_Storage.m_Memory.m_pMemory);
      this->m_sName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016E50
// Name: private: void GCSDK::CJob::SetLock(class GCSDK::CLock __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJob::SetLock(GCSDK::CJob *this, GCSDK::CLock *pLock)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  GCSDK::CLock **m_pMemory; // ecx
  int v6; // eax
  GCSDK::CLock **v7; // eax

  pLock->m_pJob = this;
  GCSDK::CJobTime::SetToJobTime(this: &pLock->m_sTimeAcquired);
  m_Size = this->m_vecLocks.m_Size;
  m_nAllocationCount = this->m_vecLocks.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<GCSDK::CLock *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_vecLocks,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_vecLocks.m_Size;
  m_pMemory = this->m_vecLocks.m_Memory.m_pMemory;
  v6 = this->m_vecLocks.m_Size - m_Size - 1;
  this->m_vecLocks.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_vecLocks.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pLock;
}

//------------------------------------------------------------------------------
// Address: 0x10016EC0
// Name: private: void GCSDK::CJob::PassLockToJob(class GCSDK::CJob __near *,class GCSDK::CLock __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJob::PassLockToJob(GCSDK::CJob *this, GCSDK::CJob *pNewJob, GCSDK::CLock *pLock)
{
  GCSDK::CJob *m_pJobToNotifyOnLockRelease; // eax
  GCSDK::CLock *m_pWaitingOnLock; // ebx
  const char *v7; // ebx
  const GCSDK::JobType_t *m_pJobType; // eax
  const char *m_pchName; // esi
  type_info *v10; // eax
  const char *v11; // eax
  const char *PauseReasonDescription; // eax
  const char *pNewJoba; // [esp+14h] [ebp+8h]

  m_pJobToNotifyOnLockRelease = pNewJob->m_pJobToNotifyOnLockRelease;
  pLock->m_pJobToNotifyOnLockRelease = m_pJobToNotifyOnLockRelease;
  if ( m_pJobToNotifyOnLockRelease == nullptr )
    pLock->m_pJobWaitingQueueTail = nullptr;
  pNewJob->m_pJobToNotifyOnLockRelease = nullptr;
  --pLock->m_unWaitingCount;
  GCSDK::CJob::UnsetLock(this, pLock);
  if ( pNewJob->m_ePauseReason == k_EJobPauseReasonWaitingForLock && pNewJob->m_pWaitingOnLock == pLock )
  {
    GCSDK::CJob::SetLock(this: pNewJob, pLock);
    GCSDK::CJobMgr::WakeupLockedJob(this: pNewJob->m_JobMgr, job: pNewJob);
  }
  else
  {
    m_pWaitingOnLock = this->m_pWaitingOnLock;
    if ( m_pWaitingOnLock != nullptr )
      pNewJoba = CUtlString::operator char const *(this: &m_pWaitingOnLock->m_sName);
    else
      pNewJoba = "none";
    v7 = CUtlString::operator char const *(this: &pLock->m_sName);
    m_pJobType = pNewJob->m_pJobType;
    if ( m_pJobType != nullptr )
    {
      m_pchName = m_pJobType->m_pchName;
    }
    else
    {
      v10 = (type_info *)__RTtypeid(inptr: pNewJob);
      v11 = type_info::raw_name(this: v10);
      if ( *v11 == 46 && v11[1] == 63 && v11[2] == 65 )
        v11 += 4;
      if ( *v11 == 63 && v11[1] == 36 )
        v11 += 2;
      m_pchName = v11;
    }
    PauseReasonDescription = GCSDK::CJob::GetPauseReasonDescription(this: pNewJob);
    GCSDK::EmitError(
      pchGroupName: SPEW_JOB_13,
      pchMsg: "Job passed lock it wasn't waiting for. Job: %s, Lock: %s, Paused for %s, Waiting on %s\n",
      m_pchName,
      v7,
      PauseReasonDescription,
      pNewJoba);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016FB0
// Name: public: bool GCSDK::CJob::BYieldingAcquireLock(class GCSDK::CLock __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CJob::BYieldingAcquireLock(GCSDK::CJob *this, GCSDK::CLock *pLock)
{
  const char *v3; // edi
  const GCSDK::JobType_t *m_pJobType; // eax
  const char *m_pchName; // eax
  type_info *v6; // eax
  GCSDK::CLock *m_pWaitingOnLock; // eax
  const char *v9; // edi
  const char *Name; // eax
  const char *v11; // ebx
  const char *v12; // eax
  GCSDK::CJob *m_pJob; // ecx
  const char *v14; // eax
  const char *v15; // ebx
  GCSDK::CLock **m_pMemory; // eax
  const char *v17; // eax
  const char *v18; // [esp-8h] [ebp-10h]

  if ( this->m_vecLocks.m_Size <= 0 )
  {
    m_pWaitingOnLock = this->m_pWaitingOnLock;
    if ( m_pWaitingOnLock != nullptr )
    {
      v9 = CUtlString::operator char const *(this: &m_pWaitingOnLock->m_sName);
      v18 = CUtlString::operator char const *(this: &pLock->m_sName);
      Name = GCSDK::CJob::GetName(this);
      GCSDK::EmitInfo(
        pchGroupName: SPEW_GC_13,
        iSpewLevel: 1,
        iLevelLog: 1,
        pchMsg: "Job (%s) trying to wait on a second lock %s when they are already waiting on %s.\n",
        Name,
        v18,
        v9);
      return 0;
    }
    ++this->m_cLocksAttempted;
    if ( pLock->m_pJob != nullptr )
    {
      GCSDK::CLock::AddToWaitingQueue(this: pLock, pJob: this);
      ++this->m_cLocksWaitedFor;
      this->m_pWaitingOnLock = pLock;
      GCSDK::CJob::Pause(this, eReason: k_EJobPauseReasonWaitingForLock);
      this->m_pWaitingOnLock = nullptr;
      if ( this->m_vecLocks.m_Size != 1 || *this->m_vecLocks.m_Memory.m_pMemory != pLock || this != pLock->m_pJob )
      {
        this->m_flags.m_uFlags |= 2u;
        v11 = CUtlString::operator char const *(this: &pLock->m_sName);
        v12 = GCSDK::CJob::GetName(this);
        GCSDK::EmitWarning(
          pchGroupName: SPEW_JOB_13,
          iLevel: 1,
          pchMsg: "Failed to get lock %s after waiting in %s\n",
          v11,
          v12);
        m_pJob = pLock->m_pJob;
        if ( this->m_vecLocks.m_Size != 0 )
        {
          if ( m_pJob != nullptr )
            v15 = GCSDK::CJob::GetName(this: m_pJob);
          else
            v15 = "(null)";
          m_pMemory = this->m_vecLocks.m_Memory.m_pMemory;
          if ( *m_pMemory != nullptr )
            v17 = CUtlString::operator char const *(this: &(*m_pMemory)->m_sName);
          else
            v17 = "(null)";
          GCSDK::EmitWarning(
            pchGroupName: SPEW_JOB_13,
            iLevel: 1,
            pchMsg: "m_vecLocks.Count(): %d, m_vecLocks[0]: %s (0x%x), pLock: 0x%x, this: 0x%x, pLock->GetJobLocking(): %s (0x%x)\n",
            this->m_vecLocks.m_Size,
            v17,
            *this->m_vecLocks.m_Memory.m_pMemory,
            pLock,
            this,
            v15,
            pLock->m_pJob);
          return 0;
        }
        else
        {
          if ( m_pJob != nullptr )
            v14 = GCSDK::CJob::GetName(this: m_pJob);
          else
            v14 = "(null)";
          GCSDK::EmitWarning(
            pchGroupName: SPEW_JOB_13,
            iLevel: 1,
            pchMsg: "m_vecLocks.Count(): %d, this: 0x%x, pLock->GetJobLocking(): %s (0x%x)\n",
            this->m_vecLocks.m_Size,
            this,
            v14,
            pLock->m_pJob);
          return 0;
        }
      }
    }
    else
    {
      GCSDK::CJob::SetLock(this, pLock);
    }
    return 1;
  }
  v3 = CUtlString::operator char const *(this: &pLock->m_sName);
  m_pJobType = this->m_pJobType;
  if ( m_pJobType != nullptr )
  {
    m_pchName = m_pJobType->m_pchName;
  }
  else
  {
    v6 = (type_info *)__RTtypeid(inptr: this);
    m_pchName = type_info::raw_name(this: v6);
    if ( *m_pchName == 46 && m_pchName[1] == 63 && m_pchName[2] == 65 )
      m_pchName += 4;
    if ( *m_pchName == 63 && m_pchName[1] == 36 )
      m_pchName += 2;
  }
  GCSDK::EmitInfo(
    pchGroupName: SPEW_GC_13,
    iSpewLevel: 1,
    iLevelLog: 1,
    pchMsg: "Job (%s) trying to take a second lock %s (with yielding)\n",
    m_pchName,
    v3);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10017190
// Name: public: void GCSDK::CJob::ReleaseLock(class GCSDK::CLock __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJob::ReleaseLock(GCSDK::CJob *this, GCSDK::CLock *pLock)
{
  int m_Size; // edx
  int v4; // eax
  GCSDK::CLock **m_pMemory; // ecx
  const char *v6; // eax
  GCSDK::CJob *m_pJob; // ebx
  const char *v8; // esi
  const char *Name; // eax
  GCSDK::CJob *m_pJobToNotifyOnLockRelease; // eax
  const char *v11; // [esp-4h] [ebp-Ch]

  if ( pLock != nullptr )
  {
    m_Size = this->m_vecLocks.m_Size;
    v4 = 0;
    if ( m_Size <= 0 )
      goto LABEL_8;
    m_pMemory = this->m_vecLocks.m_Memory.m_pMemory;
    while ( *m_pMemory != pLock )
    {
      ++v4;
      ++m_pMemory;
      if ( v4 >= m_Size )
        goto LABEL_8;
    }
    if ( v4 >= 0 )
    {
      m_pJob = pLock->m_pJob;
      if ( pLock->m_pJob == this )
      {
        m_pJobToNotifyOnLockRelease = pLock->m_pJobToNotifyOnLockRelease;
        if ( m_pJobToNotifyOnLockRelease != nullptr )
        {
          GCSDK::CJob::PassLockToJob(this, pNewJob: m_pJobToNotifyOnLockRelease, pLock);
          this->m_pJobToNotifyOnLockRelease = nullptr;
        }
        else
        {
          GCSDK::CJob::UnsetLock(this, pLock);
          pLock->m_pJobWaitingQueueTail = nullptr;
        }
      }
      else
      {
        v8 = CUtlString::operator char const *(this: &pLock->m_sName);
        GCSDK::CJob::GetName(this: m_pJob);
        Name = GCSDK::CJob::GetName(this);
        GCSDK::EmitError(
          pchGroupName: SPEW_JOB_13,
          pchMsg: "Job %s trying to release lock %s though the lock is held by\n",
          Name,
          v8);
      }
    }
    else
    {
LABEL_8:
      v11 = CUtlString::operator char const *(this: &pLock->m_sName);
      v6 = GCSDK::CJob::GetName(this);
      GCSDK::EmitError(
        pchGroupName: SPEW_JOB_13,
        pchMsg: "Job %s trying to release lock %s it's not holding\n",
        v6,
        v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017260
// Name: public: virtual GCSDK::CJob::~CJob(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CJob::~CJob(GCSDK::CJob *this)
{
  int i; // edi
  GCSDK::CNetPacket *m_pNetPackets; // edi
  GCSDK::CNetPacket *v4; // ecx
  GCSDK::CLock **m_pMemory; // eax

  this->__vftable = (GCSDK::CJob_vtbl *)&GCSDK::CJob::`vftable';
  GCSDK::g_pJobCur = nullptr;
  GCSDK::g_pJobCur = this->m_pJobPrev;
  GCSDK::CJobMgr::RemoveJob(this: this->m_JobMgr, job: this);
  for ( i = 0; i < this->m_vecLocks.m_Size; ++i )
    GCSDK::CJob::ReleaseLock(this, pLock: this->m_vecLocks.m_Memory.m_pMemory[i]);
  m_pNetPackets = this->m_pNetPackets;
  while ( m_pNetPackets != nullptr )
  {
    v4 = m_pNetPackets;
    m_pNetPackets = m_pNetPackets->m_pNext;
    GCSDK::CNetPacket::Release(this: v4);
  }
  this->m_vecLocks.m_Size = 0;
  if ( this->m_vecLocks.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vecLocks.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecLocks.m_Memory.m_pMemory);
      this->m_vecLocks.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecLocks.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_vecLocks.m_Memory.m_pMemory;
  this->m_vecLocks.m_pElements = m_pMemory;
  if ( this->m_vecLocks.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_vecLocks.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecLocks.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029330
// Name: public: void CUtlMemory<class GCSDK::CLock __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<GCSDK::CLock *,int>::Grow(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable::StringPool_t **m_pMemory; // edx
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
        m_nAllocationCount = 8;
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
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CUtlSymbolTable::StringPool_t **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}
