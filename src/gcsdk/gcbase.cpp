// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: gcsdk/gcbase.cpp
// Functions: 42
// ============================================================

#include "gcsdk\gcbase.h"

//------------------------------------------------------------------------------
// Address: 0x10006F70
// Name: public: virtual unsigned int GCSDK::CGCJob::CHeartbeatsBeforeTimeout(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GCSDK::CGCJob::CHeartbeatsBeforeTimeout(GCSDK::CGCJob *this)
{
  return this->m_cHeartbeatsBeforeTimeout;
}

//------------------------------------------------------------------------------
// Address: 0x10025D10
// Name: class GCSDK::CGCBase __near * GCSDK::GGCBase(void)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CGCBase *__cdecl GCSDK::GGCBase()
{
  return GCSDK::g_pGCBase;
}

//------------------------------------------------------------------------------
// Address: 0x10025D20
// Name: public: unsigned int PearsonsHashFunctor<class CSteamID>::operator()(class CSteamID const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall PearsonsHashFunctor<CSteamID>::operator()(PearsonsHashFunctor<CSteamID> *this, const CSteamID *unKey)
{
  unsigned int v3; // ebx
  int v4; // edi
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  unsigned int byte_one; // [esp+Ch] [ebp-4h]
  unsigned int byte_two; // [esp+18h] [ebp+8h]

  v3 = 0;
  v4 = 0;
  v5 = 8;
  byte_two = 0;
  v6 = 0;
  while ( 1 )
  {
    v7 = v5 - 1;
    byte_one = g_CTHashRandomValues[v3 ^ LOBYTE(unKey->m_steamid.m_unAll64Bits)];
    if ( v7 == 0 )
      break;
    v8 = v7 - 1;
    byte_two = g_CTHashRandomValues[byte_two ^ *((unsigned __int8 *)&unKey->m_steamid.m_comp + 1)];
    if ( v8 == 0 )
      break;
    v9 = v8 - 1;
    v4 = g_CTHashRandomValues[v4 ^ BYTE2(unKey->m_steamid.m_unAll64Bits)];
    if ( v9 == 0 )
      break;
    v6 = g_CTHashRandomValues[v6 ^ BYTE3(unKey->m_steamid.m_unAll64Bits)];
    unKey = (const CSteamID *)((char *)unKey + 4);
    v5 = v9 - 1;
    if ( v5 == 0 )
      break;
    v3 = byte_one;
  }
  return byte_one | ((byte_two | ((v4 | (v6 << 8)) << 8)) << 8);
}

//------------------------------------------------------------------------------
// Address: 0x10025DB0
// Name: private: int CTHash<class GCSDK::CGCUserSession __near *,unsigned __int64>::IBucket(unsigned __int64)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTHash<GCSDK::CGCUserSession *,unsigned __int64>::IBucket(
        CTHash<GCSDK::CGCUserSession *,unsigned __int64> *this,
        unsigned __int64 unKey)
{
  unsigned int v2; // ebx
  int v3; // edi
  int v4; // ecx
  unsigned __int8 *p_unKey; // edx
  int v6; // eax
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  unsigned int byte_one; // [esp+10h] [ebp-8h]
  unsigned int byte_two; // [esp+14h] [ebp-4h]

  v2 = 0;
  if ( this->m_cBucket <= 0
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/thash.h",
         542,
         "Assertion Failed: m_cBucket > 0") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/thash.h",
                            a2: 542,
                            a3: "Assertion Failed: m_cBucket > 0") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/thash.h",
      a2: 542);
  }
  v3 = 0;
  v4 = 8;
  p_unKey = (unsigned __int8 *)&unKey;
  byte_two = 0;
  v6 = 0;
  while ( 1 )
  {
    v7 = v4 - 1;
    byte_one = g_CTHashRandomValues[v2 ^ *p_unKey];
    if ( v7 == 0 )
      break;
    v8 = v7 - 1;
    byte_two = g_CTHashRandomValues[byte_two ^ p_unKey[1]];
    if ( v8 == 0 )
      break;
    v9 = v8 - 1;
    v3 = g_CTHashRandomValues[v3 ^ p_unKey[2]];
    if ( v9 == 0 )
      break;
    v6 = g_CTHashRandomValues[v6 ^ p_unKey[3]];
    p_unKey += 4;
    v4 = v9 - 1;
    if ( v4 == 0 )
      break;
    v2 = byte_one;
  }
  return (byte_one | (unsigned __int64)((byte_two | ((v3 | (v6 << 8)) << 8)) << 8)) % (unsigned int)this->m_cBucket;
}

//------------------------------------------------------------------------------
// Address: 0x10025EA0
// Name: private: void CTHash<class GCSDK::CGCGSSession __near *,unsigned __int64>::InsertIntoHash(struct CTHash<class GCSDK::CGCGSSession __near *,unsigned __int64>::RecHdr_t __near *,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTHash<GCSDK::CGCGSSession *,unsigned __int64>::InsertIntoHash(
        CTHash<GCSDK::CGCUserSession *,unsigned __int64> *this,
        CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *pRecHdr,
        unsigned __int64 unKey)
{
  int v4; // eax
  CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *p_m_RecHdrTail; // ebx
  int v6; // ecx
  CTHash<GCSDK::CGCUserSession *,unsigned __int64>::Bucket_t *v7; // edx

  ++this->m_cRecordInUse;
  pRecHdr->m_unKey = unKey;
  pRecHdr->m_nRunRatio = 1;
  v4 = CTHash<GCSDK::CGCUserSession *,unsigned __int64>::IBucket(this, unKey);
  pRecHdr->m_iBucket = v4;
  p_m_RecHdrTail = &this->m_RecHdrTail;
  v6 = v4;
  if ( v4 < this->m_cBucket )
  {
    v7 = &this->m_pBucket[v4];
    while ( v7->m_pRecHdrFirst == nullptr )
    {
      ++v6;
      ++v7;
      if ( v6 >= this->m_cBucket )
        goto LABEL_7;
    }
    p_m_RecHdrTail = this->m_pBucket[v6].m_pRecHdrFirst;
  }
LABEL_7:
  pRecHdr->m_pRecHdrNext = p_m_RecHdrTail;
  pRecHdr->m_pRecHdrPrev = p_m_RecHdrTail->m_pRecHdrPrev;
  p_m_RecHdrTail->m_pRecHdrPrev = pRecHdr;
  pRecHdr->m_pRecHdrPrev->m_pRecHdrNext = pRecHdr;
  this->m_pBucket[v4].m_pRecHdrFirst = pRecHdr;
}

//------------------------------------------------------------------------------
// Address: 0x10025F20
// Name: public: virtual enum GCSDK::EServerType GCSDK::CGCJob::GetServerType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GCSDK::CGCJob::GetServerType(GCSDK::CGCJob *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025F30
// Name: private: virtual bool GCSDK::CGCJob::BYieldingRunJobFromMsg(class GCSDK::CNetPacket __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GCSDK::CGCJob::BYieldingRunJobFromMsg(GCSDK::CGCJob *this, GCSDK::CNetPacket *pNetPacket)
{
  return this->BYieldingRunGCJob_2(this, a2: pNetPacket);
}

//------------------------------------------------------------------------------
// Address: 0x10025F40
// Name: private: virtual bool GCSDK::CGCJob::BYieldingRunJob(void __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GCSDK::CGCJob::BYieldingRunJob(GCSDK::CGCJob *this, void *pvStartParam)
{
  return this->BYieldingRunGCJob(this);
}

//------------------------------------------------------------------------------
// Address: 0x10025F50
// Name: public: THashBase<struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::KeyAccessor<class CSteamID>,struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::HashAccessor,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::Iter::Iter(class THashBase<struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::KeyAccessor<class CSteamID>,struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::HashAccessor,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy> const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::Iter *__thiscall THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::Iter::Iter(
        THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::Iter *this,
        const THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy> *parent,
        bool fEnd)
{
  THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::Iter *result; // eax
  unsigned int m_cActiveBuckets; // edx
  HashBucket_t *m_rgBuckets; // edi
  HashBucket_t *v6; // esi
  HashLink_t *v7; // edi

  result = this;
  this->m_Container = parent;
  m_cActiveBuckets = parent->m_cActiveBuckets;
  m_rgBuckets = parent->m_rgBuckets;
  v6 = &m_rgBuckets[m_cActiveBuckets];
  while ( 1 )
  {
    --v6;
    --m_cActiveBuckets;
    if ( v6->m_pList != nullptr )
      break;
    if ( m_cActiveBuckets == 0 )
    {
      this->m_ppCurrent = &m_rgBuckets->m_pList;
      this->m_ChangeNumber = parent->m_ChangeNumber;
      return result;
    }
  }
  v7 = (HashLink_t *)&m_rgBuckets[m_cActiveBuckets];
  do
    v7 = v7->m_pNext;
  while ( v7->m_pNext != nullptr );
  this->m_ppCurrent = &v7->m_pNext;
  this->m_ChangeNumber = parent->m_ChangeNumber;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10025FA0
// Name: public: struct HashBucket_t __near * BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
HashBucket_t *__thiscall BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>::allocate(
        BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock> *this,
        unsigned int count)
{
  void *v2; // edx

  v2 = operator new(nSize: 4 * count);
  if ( v2 == nullptr )
    return nullptr;
  if ( (int)(count - 1) >= 0 )
    memset(v2, 0, 4 * count);
  return (HashBucket_t *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x10025FF0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<class GCSDK::CSharedObjectCache __near *,unsigned int>,unsigned int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int>,unsigned int>::Grow(
        CUtlMemory<UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int>,unsigned int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int> *m_pMemory; // edx
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
        m_nAllocationCount = 3;
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
    v7 = 12 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int> *)_g_pMemAlloc->Realloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: m_pMemory,
                                                                                           a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int> *)_g_pMemAlloc->Alloc_2(
                                                                                           this: _g_pMemAlloc,
                                                                                           a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026090
// Name: class GCSDK::CJob __near * GCSDK::CreateJob_CPreTestSetupJob(class GCSDK::CGCBase __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CJob *__cdecl GCSDK::CreateJob_CPreTestSetupJob(GCSDK::CJob_vtbl *pParent, void *pvStartParam)
{
  GCSDK::CJob *v2; // esi
  GCSDK::CJob *result; // eax

  v2 = (GCSDK::CJob *)operator new(nSize: 0x90u);
  if ( v2 != nullptr )
  {
    GCSDK::CJob::CJob(this: v2, jobMgr: (GCSDK::CJobMgr *)&pParent->BYieldingRunJobFromMsg);
    v2[1].__vftable = pParent;
    v2->__vftable = (GCSDK::CJob_vtbl *)&GCSDK::CPreTestSetupJob::`vftable';
    result = v2;
  }
  else
  {
    result = nullptr;
  }
  result->m_pJobType = &g_JobType_CPreTestSetupJob;
  if ( pvStartParam != nullptr )
    result->m_pvStartParam = pvStartParam;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100260E0
// Name: class GCSDK::CJob __near * GCSDK::CreateJob_CStartPlayingJob(class GCSDK::CGCBase __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CJob *__cdecl GCSDK::CreateJob_CStartPlayingJob(GCSDK::CJob_vtbl *pParent, void *pvStartParam)
{
  GCSDK::CJob *v2; // esi
  GCSDK::CJob *result; // eax

  v2 = (GCSDK::CJob *)operator new(nSize: 0x90u);
  if ( v2 != nullptr )
  {
    GCSDK::CJob::CJob(this: v2, jobMgr: (GCSDK::CJobMgr *)&pParent->BYieldingRunJobFromMsg);
    v2[1].__vftable = pParent;
    v2->__vftable = (GCSDK::CJob_vtbl *)&GCSDK::CStartPlayingJob::`vftable';
    result = v2;
  }
  else
  {
    result = nullptr;
  }
  result->m_pJobType = &g_JobType_CStartPlayingJob;
  if ( pvStartParam != nullptr )
    result->m_pvStartParam = pvStartParam;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10026160
// Name: class GCSDK::CJob __near * GCSDK::CreateJob_CStopPlayingJob(class GCSDK::CGCBase __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CJob *__cdecl GCSDK::CreateJob_CStopPlayingJob(GCSDK::CJob_vtbl *pParent, void *pvStartParam)
{
  GCSDK::CJob *v2; // esi
  GCSDK::CJob *result; // eax

  v2 = (GCSDK::CJob *)operator new(nSize: 0x90u);
  if ( v2 != nullptr )
  {
    GCSDK::CJob::CJob(this: v2, jobMgr: (GCSDK::CJobMgr *)&pParent->BYieldingRunJobFromMsg);
    v2[1].__vftable = pParent;
    v2->__vftable = (GCSDK::CJob_vtbl *)&GCSDK::CStopPlayingJob::`vftable';
    result = v2;
  }
  else
  {
    result = nullptr;
  }
  result->m_pJobType = &g_JobType_CStopPlayingJob;
  if ( pvStartParam != nullptr )
    result->m_pvStartParam = pvStartParam;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100261B0
// Name: class GCSDK::CJob __near * GCSDK::CreateJob_CStartGameserverJob(class GCSDK::CGCBase __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CJob *__cdecl GCSDK::CreateJob_CStartGameserverJob(GCSDK::CJob_vtbl *pParent, void *pvStartParam)
{
  GCSDK::CJob *v2; // esi
  GCSDK::CJob *result; // eax

  v2 = (GCSDK::CJob *)operator new(nSize: 0x90u);
  if ( v2 != nullptr )
  {
    GCSDK::CJob::CJob(this: v2, jobMgr: (GCSDK::CJobMgr *)&pParent->BYieldingRunJobFromMsg);
    v2[1].__vftable = pParent;
    v2->__vftable = (GCSDK::CJob_vtbl *)&GCSDK::CStartGameserverJob::`vftable';
    result = v2;
  }
  else
  {
    result = nullptr;
  }
  result->m_pJobType = &g_JobType_CStartGameserverJob;
  if ( pvStartParam != nullptr )
    result->m_pvStartParam = pvStartParam;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10026200
// Name: class GCSDK::CJob __near * GCSDK::CreateJob_CStopGameserverJob(class GCSDK::CGCBase __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CJob *__cdecl GCSDK::CreateJob_CStopGameserverJob(GCSDK::CJob_vtbl *pParent, void *pvStartParam)
{
  GCSDK::CJob *v2; // esi
  GCSDK::CJob *result; // eax

  v2 = (GCSDK::CJob *)operator new(nSize: 0x90u);
  if ( v2 != nullptr )
  {
    GCSDK::CJob::CJob(this: v2, jobMgr: (GCSDK::CJobMgr *)&pParent->BYieldingRunJobFromMsg);
    v2[1].__vftable = pParent;
    v2->__vftable = (GCSDK::CJob_vtbl *)&GCSDK::CStopGameserverJob::`vftable';
    result = v2;
  }
  else
  {
    result = nullptr;
  }
  result->m_pJobType = &g_JobType_CStopGameserverJob;
  if ( pvStartParam != nullptr )
    result->m_pvStartParam = pvStartParam;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10026250
// Name: public: class GCSDK::CGCUserSession __near * GCSDK::CGCBase::FindUserSession(class CSteamID const __near &)const
// Source: json
//------------------------------------------------------------------------------
CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *__thiscall GCSDK::CGCBase::FindUserSession(
        GCSDK::CGCBase *this,
        const CSteamID *steamID)
{
  int m_unAll64Bits_high; // ebx
  int m_comp; // edi
  CTHash<GCSDK::CGCUserSession *,unsigned __int64> *p_m_hashUserSessions; // esi
  int v5; // eax
  CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *m_pRecHdrFirst; // ecx
  CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *v8; // esi

  m_unAll64Bits_high = HIDWORD(steamID->m_steamid.m_unAll64Bits);
  m_comp = (int)steamID->m_steamid.m_comp;
  p_m_hashUserSessions = &this->m_hashUserSessions;
  v5 = CTHash<GCSDK::CGCUserSession *,unsigned __int64>::IBucket(
         this: &this->m_hashUserSessions,
         unKey: steamID->m_steamid.m_unAll64Bits);
  m_pRecHdrFirst = p_m_hashUserSessions->m_pBucket[v5].m_pRecHdrFirst;
  if ( m_pRecHdrFirst != nullptr )
  {
    while ( m_pRecHdrFirst->m_iBucket == v5 )
    {
      if ( m_comp == LODWORD(m_pRecHdrFirst->m_unKey) && m_unAll64Bits_high == HIDWORD(m_pRecHdrFirst->m_unKey) )
      {
        v8 = m_pRecHdrFirst + 1;
        if ( m_pRecHdrFirst == (CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *)-24 )
          return nullptr;
        ((void (__thiscall *)(CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *))LODWORD(v8->m_pRecHdrNext->m_pRecHdrNext->m_unKey))(a1: v8->m_pRecHdrNext);
        return v8->m_pRecHdrNext;
      }
      m_pRecHdrFirst = m_pRecHdrFirst->m_pRecHdrNext;
      if ( m_pRecHdrFirst == nullptr )
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100262B0
// Name: public: class GCSDK::CGCGSSession __near * GCSDK::CGCBase::FindGSSession(class CSteamID const __near &)const
// Source: json
//------------------------------------------------------------------------------
CTHash<GCSDK::CGCGSSession *,unsigned __int64>::RecHdr_t *__thiscall GCSDK::CGCBase::FindGSSession(
        GCSDK::CGCBase *this,
        const CSteamID *steamID)
{
  int m_unAll64Bits_high; // ebx
  int m_comp; // edi
  CTHash<GCSDK::CGCGSSession *,unsigned __int64> *p_m_hashGSSessions; // esi
  int v5; // eax
  CTHash<GCSDK::CGCGSSession *,unsigned __int64>::RecHdr_t *m_pRecHdrFirst; // ecx
  CTHash<GCSDK::CGCGSSession *,unsigned __int64>::RecHdr_t *v8; // esi

  m_unAll64Bits_high = HIDWORD(steamID->m_steamid.m_unAll64Bits);
  m_comp = (int)steamID->m_steamid.m_comp;
  p_m_hashGSSessions = &this->m_hashGSSessions;
  v5 = CTHash<GCSDK::CGCUserSession *,unsigned __int64>::IBucket(
         this: (CTHash<GCSDK::CGCUserSession *,unsigned __int64> *)&this->m_hashGSSessions,
         unKey: steamID->m_steamid.m_unAll64Bits);
  m_pRecHdrFirst = p_m_hashGSSessions->m_pBucket[v5].m_pRecHdrFirst;
  if ( m_pRecHdrFirst != nullptr )
  {
    while ( m_pRecHdrFirst->m_iBucket == v5 )
    {
      if ( m_comp == LODWORD(m_pRecHdrFirst->m_unKey) && m_unAll64Bits_high == HIDWORD(m_pRecHdrFirst->m_unKey) )
      {
        v8 = m_pRecHdrFirst + 1;
        if ( m_pRecHdrFirst == (CTHash<GCSDK::CGCGSSession *,unsigned __int64>::RecHdr_t *)-24 )
          return nullptr;
        ((void (__thiscall *)(CTHash<GCSDK::CGCGSSession *,unsigned __int64>::RecHdr_t *))LODWORD(v8->m_pRecHdrNext->m_pRecHdrNext->m_unKey))(a1: v8->m_pRecHdrNext);
        return v8->m_pRecHdrNext;
      }
      m_pRecHdrFirst = m_pRecHdrFirst->m_pRecHdrNext;
      if ( m_pRecHdrFirst == nullptr )
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10026310
// Name: private: struct HashLink_t __near * __near * THashBase<struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::KeyAccessor<class CSteamID>,struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::HashAccessor,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::SearchBucketForKey(struct HashBucket_t __near &,unsigned int,class CSteamID const __near &,bool __near &)const
// Source: json
//------------------------------------------------------------------------------
HashBucket_t *__thiscall THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::SearchBucketForKey(
        THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy> *this,
        HashBucket_t *bucket,
        HashLink_t *h,
        const CSteamID *k,
        bool *fExactMatch)
{
  HashBucket_t *result; // eax
  HashLink_t *m_pList; // ecx
  unsigned int i; // edi
  HashLink_t *v8; // ecx
  int v9; // edx
  HashLink_t *m_unAll64Bits_high; // edi
  HashLink_t *m_pNext; // esi
  HashLink_t *v12; // ebx

  result = bucket;
  m_pList = bucket->m_pList;
  for ( i = (unsigned int)h; m_pList != nullptr; m_pList = m_pList->m_pNext )
  {
    if ( h <= m_pList[1].m_pNext )
      break;
    result = (HashBucket_t *)m_pList;
  }
  v8 = result->m_pList;
  v9 = -1;
  if ( result->m_pList != nullptr )
  {
    while ( (HashLink_t *)i == v8[1].m_pNext )
    {
      m_unAll64Bits_high = (HashLink_t *)HIDWORD(k->m_steamid.m_unAll64Bits);
      m_pNext = v8[2].m_pNext;
      v12 = v8[3].m_pNext;
      if ( (HashLink_t *)k->m_steamid.m_comp == m_pNext && m_unAll64Bits_high == v12 )
      {
        *fExactMatch = true;
        return result;
      }
      if ( m_unAll64Bits_high > v12
        || m_unAll64Bits_high >= v12 && *(_DWORD *)&k->m_steamid.m_comp >= (unsigned int)m_pNext )
      {
        v9 = 1;
        break;
      }
      result = (HashBucket_t *)v8;
      v8 = v8->m_pNext;
      v9 = -1;
      if ( v8 == nullptr )
        break;
      i = (unsigned int)h;
    }
  }
  *fExactMatch = v9 == 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100263A0
// Name: private: void THashBase<struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::KeyAccessor<class CSteamID>,struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::HashAccessor,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::ShrinkTo(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::ShrinkTo(
        THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy> *this,
        unsigned int target)
{
  unsigned int v2; // eax
  unsigned int m_cActiveBuckets; // ebx
  unsigned int m_cTheoreticalBuckets; // edi
  unsigned int v6; // ecx
  unsigned int v7; // edx
  HashBucket_t *m_rgBuckets; // ebx
  unsigned int v9; // edi
  int v10; // edx
  HashLink_t *m_pList; // eax
  HashBucket_t *v12; // ecx
  HashLink_t *v13; // edx
  unsigned int v14; // ebx
  HashBucket_t *v15; // edi
  unsigned int i; // eax
  THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy> *v17; // eax
  unsigned int v18; // [esp+Ch] [ebp-4h]

  v2 = target;
  if ( this->m_cActiveBuckets > target )
  {
    do
    {
      m_cActiveBuckets = this->m_cActiveBuckets;
      m_cTheoreticalBuckets = this->m_cTheoreticalBuckets;
      v6 = m_cActiveBuckets - 1;
      v7 = (m_cActiveBuckets - 1) % m_cTheoreticalBuckets;
      v18 = v7;
      if ( v7 >= m_cActiveBuckets )
        v18 = v7 - (m_cTheoreticalBuckets >> 1);
      m_rgBuckets = this->m_rgBuckets;
      this->m_cActiveBuckets = v6;
      if ( v6 < m_cTheoreticalBuckets >> 1 )
        this->m_cTheoreticalBuckets = m_cTheoreticalBuckets >> 1;
      v9 = this->m_cTheoreticalBuckets;
      v10 = v6 % v9;
      if ( v6 % v9 >= v6 )
        v10 -= v9 >> 1;
      m_pList = m_rgBuckets[v10].m_pList;
      v12 = &m_rgBuckets[v10];
      v13 = m_rgBuckets[v18].m_pList;
      if ( m_pList != nullptr )
      {
        while ( v13 != nullptr )
        {
          if ( m_pList[1].m_pNext >= v13[1].m_pNext )
          {
            v12->m_pList = v13;
            v13 = v13->m_pNext;
          }
          else
          {
            v12->m_pList = m_pList;
            m_pList = m_pList->m_pNext;
          }
          v12 = (HashBucket_t *)v12->m_pList;
          if ( m_pList == nullptr )
            goto LABEL_14;
        }
        v12->m_pList = m_pList;
      }
      else
      {
LABEL_14:
        v12->m_pList = v13;
      }
      m_rgBuckets[v18].m_pList = nullptr;
    }
    while ( this->m_cActiveBuckets > target );
    v2 = target;
  }
  v14 = v2 + 50;
  if ( v2 + 50 < v2 )
    v14 = v2;
  if ( this->m_cAvailableBuckets > v14 )
  {
    v15 = v14 <= 1
        ? &this->m_BucketWorstCase
        : BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>::allocate(this, count: v14);
    if ( v15 != nullptr )
    {
      for ( i = 0; i < this->m_cActiveBuckets; ++i )
        v15[i] = this->m_rgBuckets[i];
      v17 = (THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy> *)this->m_rgBuckets;
      if ( v17 != (THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy> *)&this->m_BucketWorstCase )
        free(pMem: v17);
      this->m_rgBuckets = v15;
      this->m_cAvailableBuckets = v14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100264B0
// Name: private: void THashBase<struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::KeyAccessor<class CSteamID>,struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::HashAccessor,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::GrowTo(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::GrowTo(
        THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy> *this,
        unsigned int target)
{
  unsigned int v3; // ecx
  unsigned int v4; // edi
  HashBucket_t *v5; // ebx
  unsigned int i; // eax
  unsigned int m_cActiveBuckets; // edi
  unsigned int m_cTheoreticalBuckets; // ecx
  int v9; // edx
  HashBucket_t *v10; // eax
  HashLink_t *m_pList; // ecx
  HashLink_t *m_pNext; // ebx
  HashLink_t **v13; // edx
  unsigned int v14; // ecx
  int v15; // edx
  unsigned int v16; // eax
  HashLink_t *v17; // [esp+Ch] [ebp-Ch] BYREF
  HashLink_t **p_m_pNext; // [esp+10h] [ebp-8h]
  unsigned int allocTarget; // [esp+14h] [ebp-4h]

  v3 = target;
  if ( this->m_cAvailableBuckets < target )
  {
    v4 = target + 50;
    allocTarget = target + 50;
    if ( target + 50 < target )
    {
      allocTarget = target;
      v4 = target;
    }
    v5 = (HashBucket_t *)operator new(nSize: 4 * v4);
    if ( v5 != nullptr )
    {
      if ( (int)(v4 - 1) >= 0 )
      {
        memset(v5, 0, 4 * v4);
        v4 = allocTarget;
      }
      for ( i = 0; i < this->m_cActiveBuckets; ++i )
        v5[i] = this->m_rgBuckets[i];
      if ( this->m_rgBuckets == &this->m_BucketWorstCase )
        this->m_BucketWorstCase.m_pList = nullptr;
      else
        free(pMem: this->m_rgBuckets);
      this->m_rgBuckets = v5;
      this->m_cAvailableBuckets = v4;
    }
    v3 = target;
  }
  if ( v3 > this->m_cAvailableBuckets )
    target = this->m_cAvailableBuckets;
  m_cActiveBuckets = this->m_cActiveBuckets;
  while ( m_cActiveBuckets < target )
  {
    m_cTheoreticalBuckets = this->m_cTheoreticalBuckets;
    v9 = m_cActiveBuckets % m_cTheoreticalBuckets;
    if ( m_cActiveBuckets % m_cTheoreticalBuckets >= m_cActiveBuckets )
      v9 -= m_cTheoreticalBuckets >> 1;
    v10 = &this->m_rgBuckets[v9];
    p_m_pNext = &v17;
    m_pList = v10->m_pList;
    allocTarget = (unsigned int)v10;
    if ( m_pList != nullptr )
    {
      do
      {
        m_pNext = m_pList->m_pNext;
        if ( (unsigned int)m_pList[1].m_pNext % this->m_cTheoreticalBuckets == m_cActiveBuckets )
        {
          *p_m_pNext = m_pList;
          p_m_pNext = &m_pList->m_pNext;
        }
        else
        {
          *(_DWORD *)allocTarget = m_pList;
          allocTarget = (unsigned int)m_pList;
        }
        m_pList = m_pNext;
      }
      while ( m_pNext != nullptr );
    }
    v13 = p_m_pNext;
    *(_DWORD *)allocTarget = 0;
    *v13 = nullptr;
    v14 = this->m_cTheoreticalBuckets;
    v15 = m_cActiveBuckets % v14;
    if ( m_cActiveBuckets % v14 >= ++this->m_cActiveBuckets )
      v15 -= v14 >> 1;
    this->m_rgBuckets[v15].m_pList = v17;
    m_cActiveBuckets = this->m_cActiveBuckets;
    v16 = this->m_cTheoreticalBuckets;
    if ( m_cActiveBuckets == v16 )
      this->m_cTheoreticalBuckets = 2 * v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026600
// Name: public: class GCSDK::CGCGSSession __near * __near * CTHash<class GCSDK::CGCGSSession __near *,unsigned __int64>::PvRecordInsert(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CGCGSSession **__thiscall CTHash<GCSDK::CGCGSSession *,unsigned __int64>::PvRecordInsert(
        CTHash<GCSDK::CGCGSSession *,unsigned __int64> *this,
        unsigned __int64 unKey)
{
  CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *v3; // edi
  const char *v4; // eax
  int m_cRecordInUse; // [esp-8h] [ebp-10h]
  int m_cBucket; // [esp-4h] [ebp-Ch]

  v3 = (CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *)CUtlMemoryPool::Alloc(this: this->m_pMemoryPoolRecord);
  CTHash<GCSDK::CGCGSSession *,unsigned __int64>::InsertIntoHash(
    (CTHash<GCSDK::CGCUserSession *,unsigned __int64> *)this,
    pRecHdr: v3,
    unKey);
  if ( `CTHash<GCSDK::CGCGSSession *,unsigned __int64>::PvRecordInsertInternal'::`2'::s_bPerfWarning == 0
    && this->m_cRecordInUse >= 5 * this->m_cBucket )
  {
    `CTHash<GCSDK::CGCGSSession *,unsigned __int64>::PvRecordInsertInternal'::`2'::s_bPerfWarning = 1;
    m_cBucket = this->m_cBucket;
    m_cRecordInUse = this->m_cRecordInUse;
    v4 = type_info::raw_name(this: &CTHash<GCSDK::CGCGSSession *,unsigned __int64> `RTTI Type Descriptor');
    _Msg(a1: "not enough buckets in thash class %s (%d records, %d buckets)\n", v4, m_cRecordInUse, m_cBucket);
  }
  return (GCSDK::CGCGSSession **)&v3[1];
}

//------------------------------------------------------------------------------
// Address: 0x10026670
// Name: public: class GCSDK::CGCUserSession __near * __near * CTHash<class GCSDK::CGCUserSession __near *,unsigned __int64>::PvRecordInsert(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CGCUserSession **__thiscall CTHash<GCSDK::CGCUserSession *,unsigned __int64>::PvRecordInsert(
        CTHash<GCSDK::CGCUserSession *,unsigned __int64> *this,
        unsigned __int64 unKey)
{
  CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *v3; // edi
  const char *v4; // eax
  int m_cRecordInUse; // [esp-8h] [ebp-10h]
  int m_cBucket; // [esp-4h] [ebp-Ch]

  v3 = (CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *)CUtlMemoryPool::Alloc(this: this->m_pMemoryPoolRecord);
  CTHash<GCSDK::CGCGSSession *,unsigned __int64>::InsertIntoHash(this, pRecHdr: v3, unKey);
  if ( `CTHash<GCSDK::CGCUserSession *,unsigned __int64>::PvRecordInsertInternal'::`2'::s_bPerfWarning == 0
    && this->m_cRecordInUse >= 5 * this->m_cBucket )
  {
    `CTHash<GCSDK::CGCUserSession *,unsigned __int64>::PvRecordInsertInternal'::`2'::s_bPerfWarning = 1;
    m_cBucket = this->m_cBucket;
    m_cRecordInUse = this->m_cRecordInUse;
    v4 = type_info::raw_name(this: &CTHash<GCSDK::CGCUserSession *,unsigned __int64> `RTTI Type Descriptor');
    _Msg(a1: "not enough buckets in thash class %s (%d records, %d buckets)\n", v4, m_cRecordInUse, m_cBucket);
  }
  return (GCSDK::CGCUserSession **)&v3[1];
}

//------------------------------------------------------------------------------
// Address: 0x100266E0
// Name: public: void CTHash<class GCSDK::CGCUserSession __near *,unsigned __int64>::Remove(class GCSDK::CGCUserSession __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTHash<GCSDK::CGCUserSession *,unsigned __int64>::Remove(
        CTHash<GCSDK::CGCUserSession *,unsigned __int64> *this,
        GCSDK::CGCUserSession **pvRemove)
{
  CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *v2; // esi
  int v4; // eax
  CTHash<GCSDK::CGCUserSession *,unsigned __int64>::Bucket_t *v5; // ecx
  CUtlMemoryPool *m_pMemoryPoolRecord; // ecx

  v2 = (CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *)(pvRemove - 6);
  v4 = CTHash<GCSDK::CGCUserSession *,unsigned __int64>::IBucket(this, unKey: *((_QWORD *)pvRemove - 2));
  v5 = &this->m_pBucket[v4];
  if ( pvRemove - 6 == (GCSDK::CGCUserSession **)v5->m_pRecHdrFirst )
    v5->m_pRecHdrFirst = v2->m_pRecHdrNext->m_iBucket != v4 ? nullptr : v2->m_pRecHdrNext;
  v2->m_pRecHdrPrev->m_pRecHdrNext = v2->m_pRecHdrNext;
  v2->m_pRecHdrNext->m_pRecHdrPrev = v2->m_pRecHdrPrev;
  if ( v2 == this->m_pRecHdrRunNext )
    this->m_pRecHdrRunNext = v2->m_pRecHdrNext;
  m_pMemoryPoolRecord = this->m_pMemoryPoolRecord;
  --this->m_cRecordInUse;
  CUtlMemoryPool::Free(this: m_pMemoryPoolRecord, memBlock: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10027540
// Name: public: virtual bool GCSDK::CPreTestSetupJob::BYieldingRunGCJob(class GCSDK::CNetPacket __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CPreTestSetupJob::BYieldingRunGCJob(
        GCSDK::CPreTestSetupJob *this,
        GCSDK::CNetPacket *pNetPacket)
{
  this->m_pGC->YieldingPreTestSetup(this: this->m_pGC);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027560
// Name: private: bool THashBase<struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::KeyAccessor<class CSteamID>,struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::HashAccessor,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::EvaluatePolicyAndPreservePointer(struct HashLink_t __near * __near * __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::EvaluatePolicyAndPreservePointer(
        THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy> *this,
        HashLink_t ***ppCurrent,
        unsigned int h)
{
  unsigned int m_cTheoreticalBuckets; // edi
  unsigned int v5; // edx
  unsigned int m_cActiveBuckets; // ebx
  unsigned int m_cItems; // eax
  unsigned int v8; // edx
  unsigned int v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // edx
  HashBucket_t *m_rgBuckets; // ecx
  HashLink_t *m_pList; // eax
  HashLink_t **i; // ecx
  HashLink_t *p; // [esp+Ch] [ebp-Ch]
  bool fSitsOnBucket; // [esp+17h] [ebp-1h]

  p = **ppCurrent;
  m_cTheoreticalBuckets = this->m_cTheoreticalBuckets;
  v5 = h % m_cTheoreticalBuckets;
  m_cActiveBuckets = this->m_cActiveBuckets;
  if ( h % m_cTheoreticalBuckets >= m_cActiveBuckets )
    v5 -= m_cTheoreticalBuckets >> 1;
  m_cItems = this->m_cItems;
  fSitsOnBucket = *ppCurrent == &this->m_rgBuckets[v5].m_pList;
  _BitScanReverse(&v8, m_cItems + ((m_cItems + 1) >> 1));
  v9 = v8;
  if ( v8 == 0 )
    v9 = 1;
  v10 = 3 * m_cItems / (8 * v9);
  if ( v10 == 0 )
    v10 = 1;
  if ( v10 >= m_cActiveBuckets )
  {
    if ( v10 <= m_cActiveBuckets )
      return 0;
    THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::GrowTo(
      this,
      target: v10);
  }
  else
  {
    THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::ShrinkTo(
      this,
      target: v10);
  }
  if ( fSitsOnBucket || **ppCurrent != p )
  {
    v11 = this->m_cTheoreticalBuckets;
    v12 = h % v11;
    if ( h % v11 >= this->m_cActiveBuckets )
      v12 -= v11 >> 1;
    m_rgBuckets = this->m_rgBuckets;
    m_pList = m_rgBuckets[v12].m_pList;
    for ( i = &m_rgBuckets[v12].m_pList; m_pList != nullptr; m_pList = m_pList->m_pNext )
    {
      if ( m_pList == p )
        break;
      i = &m_pList->m_pNext;
    }
    *ppCurrent = i;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10027650
// Name: public: class THashBase<struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::KeyAccessor<class CSteamID>,struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::HashAccessor,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::Iter THashBase<struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::KeyAccessor<class CSteamID>,struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::HashAccessor,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::FindFirst(class CSteamID const __near &)const
// Source: json
//------------------------------------------------------------------------------
THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::Iter *__thiscall THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::FindFirst(
        THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy> *this,
        THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::Iter *result,
        const CSteamID *k)
{
  const CSteamID *v3; // ebx
  unsigned int v5; // eax
  unsigned int m_cTheoreticalBuckets; // ecx
  int v7; // edx
  HashBucket_t *v8; // ecx

  v3 = k;
  v5 = PearsonsHashFunctor<CSteamID>::operator()(this: &this->m_HashMechanism, unKey: k);
  m_cTheoreticalBuckets = this->m_cTheoreticalBuckets;
  v7 = v5 % m_cTheoreticalBuckets;
  if ( v5 % m_cTheoreticalBuckets >= this->m_cActiveBuckets )
    v7 -= m_cTheoreticalBuckets >> 1;
  v8 = THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::SearchBucketForKey(
         this,
         bucket: &this->m_rgBuckets[v7],
         h: (HashLink_t *)v5,
         k: v3,
         fExactMatch: (bool *)&k + 3);
  if ( HIBYTE(k) != 0 )
  {
    result->m_Container = this;
    result->m_ppCurrent = &v8->m_pList;
    result->m_ChangeNumber = this->m_ChangeNumber;
  }
  else
  {
    THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::Iter::Iter(
      this: result,
      parent: this,
      fEnd: false);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100276C0
// Name: public: void CTHash<class GCSDK::CGCUserSession __near *,unsigned __int64>::Remove(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTHash<GCSDK::CGCUserSession *,unsigned __int64>::Remove(
        CTHash<GCSDK::CGCUserSession *,unsigned __int64> *this,
        unsigned __int64 unKey)
{
  int v3; // eax
  CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *m_pRecHdrFirst; // ecx

  v3 = CTHash<GCSDK::CGCUserSession *,unsigned __int64>::IBucket(this, unKey);
  m_pRecHdrFirst = this->m_pBucket[v3].m_pRecHdrFirst;
  if ( m_pRecHdrFirst != nullptr )
  {
    while ( m_pRecHdrFirst->m_iBucket == v3 )
    {
      if ( unKey == m_pRecHdrFirst->m_unKey )
      {
        if ( m_pRecHdrFirst != (CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *)-24 )
          CTHash<GCSDK::CGCUserSession *,unsigned __int64>::Remove(
            this,
            pvRemove: (GCSDK::CGCUserSession **)&m_pRecHdrFirst[1]);
        return;
      }
      m_pRecHdrFirst = m_pRecHdrFirst->m_pRecHdrNext;
      if ( m_pRecHdrFirst == nullptr )
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027920
// Name: public: class THashBase<struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::KeyAccessor<class CSteamID>,struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::HashAccessor,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::Iter THashBase<struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::KeyAccessor<class CSteamID>,struct TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::HashAccessor,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::FindOrInsert(struct HashLink_t __near *,struct HashLink_t __near * __near &)
// Source: json
//------------------------------------------------------------------------------
THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::Iter *__thiscall THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::FindOrInsert(
        THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy> *this,
        THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::Iter *result,
        HashLink_t *p,
        HashLink_t **pOut)
{
  HashLink_t *v4; // ebx
  unsigned int v6; // eax
  unsigned int m_cTheoreticalBuckets; // ecx
  unsigned int v8; // edi
  int v9; // edx
  HashBucket_t *v10; // eax
  HashLink_t *m_pList; // edx
  unsigned int m_ChangeNumber; // edx
  HashLink_t **pp; // [esp+Ch] [ebp-4h] BYREF

  v4 = p;
  v6 = PearsonsHashFunctor<CSteamID>::operator()(this: &this->m_HashMechanism, unKey: (const CSteamID *)&p[2]);
  m_cTheoreticalBuckets = this->m_cTheoreticalBuckets;
  v8 = v6;
  v9 = v6 % m_cTheoreticalBuckets;
  if ( v6 % m_cTheoreticalBuckets >= this->m_cActiveBuckets )
    v9 -= m_cTheoreticalBuckets >> 1;
  v10 = THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::SearchBucketForKey(
          this,
          bucket: &this->m_rgBuckets[v9],
          h: (HashLink_t *)v6,
          k: (const CSteamID *)&v4[2],
          fExactMatch: (bool *)&p + 3);
  m_pList = v10->m_pList;
  pp = &v10->m_pList;
  if ( HIBYTE(p) != 0 )
  {
    *pOut = m_pList;
  }
  else
  {
    v4->m_pNext = m_pList;
    v10->m_pList = v4;
    ++this->m_ChangeNumber;
    ++this->m_cItems;
    THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::EvaluatePolicyAndPreservePointer(
      this,
      ppCurrent: &pp,
      h: v8);
    v10 = (HashBucket_t *)pp;
    *pOut = v4;
  }
  m_ChangeNumber = this->m_ChangeNumber;
  result->m_Container = this;
  result->m_ppCurrent = &v10->m_pList;
  result->m_ChangeNumber = m_ChangeNumber;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100279B0
// Name: protected: class GCSDK::CSharedObjectCache __near * GCSDK::CGCBase::FindSOCache(class CSteamID const __near &)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CSharedObjectCache *__thiscall GCSDK::CGCBase::FindSOCache(GCSDK::CGCBase *this, const CSteamID *steamID)
{
  int m_unAll64Bits_high; // edx
  int v4; // eax
  int v5; // esi
  CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,int>::Node_t search; // [esp+Ch] [ebp-Ch] BYREF

  m_unAll64Bits_high = HIDWORD(steamID->m_steamid.m_unAll64Bits);
  *(_DWORD *)&search.key.m_steamid.m_comp = steamID->m_steamid.m_comp;
  *((_DWORD *)&search.key.m_steamid.m_comp + 1) = m_unAll64Bits_high;
  v4 = CUtlRBTree<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,int>::Node_t,int,CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,int>::Node_t,int>,int>>::Find(
         this: &this->m_mapSOCache.m_Tree,
         &search);
  v5 = v4;
  if ( v4 < 0
    || v4 >= this->m_mapSOCache.m_Tree.m_Elements.m_nAllocationCount
    || v4 > this->m_mapSOCache.m_Tree.m_LastAlloc.index
    || CUtlRBTree<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,int>::Node_t,int,CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,int>::Node_t,int>,int>>::LeftChild(
         this: &this->m_mapSOCache.m_Tree,
         i: v4) == v4 )
  {
    return nullptr;
  }
  else
  {
    return this->m_mapSOCache.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027A30
// Name: public: class TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::Iterator TStandardHash<class CSteamID,class GCSDK::CLock,struct PearsonsHashFunctor<class CSteamID>,struct ComparisonFunctor<class CSteamID>,class BaseAlloc<struct HashBucket_t,class CSteamID,class GCSDK::CLock>,struct InverseLogPolicy>::FindOrInsert(class CSteamID const __near &)
// Source: json
//------------------------------------------------------------------------------
TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::Iterator *__thiscall TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::FindOrInsert(
        TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy> *this,
        TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::Iterator *result,
        HashLink_t *k)
{
  char *v4; // eax
  CSteamID *v5; // esi
  const CSteamID *v6; // edi
  THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::Iter *v7; // eax
  const THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy> *m_Container; // edi
  HashLink_t **m_ppCurrent; // ebx
  unsigned int m_ChangeNumber; // edx
  THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::Iter *First; // eax
  HashLink_t **v13; // edx
  TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::Iterator iter; // [esp+8h] [ebp-Ch] BYREF

  v4 = (char *)operator new(nSize: 0x40u);
  v5 = (CSteamID *)v4;
  if ( v4 != nullptr )
  {
    v6 = (const CSteamID *)k;
    *(_DWORD *)v4 = 0;
    *((CSteamID *)v4 + 1) = (CSteamID)v6->m_steamid.m_comp;
    GCSDK::CLock::CLock(this: (GCSDK::CLock *)(v4 + 16));
    *((_DWORD *)&v5->m_steamid.m_comp + 1) = PearsonsHashFunctor<CSteamID>::operator()(
                                               this: &this->m_Implementation.m_HashMechanism,
                                               unKey: v6);
    v7 = THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::FindOrInsert(
           this: &this->m_Implementation,
           result: &iter,
           p: (HashLink_t *)v5,
           pOut: &k);
    m_Container = v7->m_Container;
    m_ppCurrent = v7->m_ppCurrent;
    iter.m_ChangeNumber = v7->m_ChangeNumber;
    if ( k != (HashLink_t *)v5 )
    {
      GCSDK::CLock::~CLock(this: (GCSDK::CLock *)&v5[2]);
      free(pMem: v5);
    }
    m_ChangeNumber = iter.m_ChangeNumber;
    result->m_Container = m_Container;
    result->m_ppCurrent = m_ppCurrent;
    result->m_ChangeNumber = m_ChangeNumber;
    return result;
  }
  else
  {
    First = THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::FindFirst(
              this: &this->m_Implementation,
              result: &iter,
              (const CSteamID *)k);
    result->m_Container = First->m_Container;
    v13 = First->m_ppCurrent;
    result->m_ChangeNumber = First->m_ChangeNumber;
    result->m_ppCurrent = v13;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027B70
// Name: protected: void GCSDK::CGCBase::RemoveCacheFromLRU(class GCSDK::CSharedObjectCache __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CGCBase::RemoveCacheFromLRU(GCSDK::CGCBase *this, GCSDK::CSharedObjectCache *pSOCache)
{
  signed int m_unLRUHandle; // esi
  CUtlLinkedList<GCSDK::CSharedObjectCache *,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int>,unsigned int> > *p_m_listCachesToUnload; // edi
  UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int> *m_pMemory; // ecx
  const char *v5; // eax
  const char *v6; // [esp-4h] [ebp-10h]

  m_unLRUHandle = pSOCache->m_unLRUHandle;
  p_m_listCachesToUnload = &this->m_listCachesToUnload;
  if ( m_unLRUHandle >= 0
    && m_unLRUHandle < this->m_listCachesToUnload.m_Memory.m_nAllocationCount
    && m_unLRUHandle <= this->m_listCachesToUnload.m_LastAlloc.index )
  {
    m_pMemory = p_m_listCachesToUnload->m_Memory.m_pMemory;
    if ( p_m_listCachesToUnload->m_Memory.m_pMemory[m_unLRUHandle].m_Previous != m_unLRUHandle
      || p_m_listCachesToUnload->m_Memory.m_pMemory[m_unLRUHandle].m_Next == m_unLRUHandle )
    {
      if ( m_pMemory[m_unLRUHandle].m_Element != pSOCache )
      {
        v6 = CSteamID::Render(this: &m_pMemory[m_unLRUHandle].m_Element->m_context.m_steamIDOwner);
        v5 = CSteamID::Render(this: &pSOCache->m_context.m_steamIDOwner);
        GCSDK::EmitError(
          pchGroupName: SPEW_GC_25,
          pchMsg: "Attempting to remove SOCache LRU index %d for %s, which really holds %s\n",
          m_unLRUHandle,
          v5,
          v6);
        pSOCache->m_unLRUHandle = -1;
        return;
      }
      CUtlLinkedList<GCSDK::CSharedObjectCache *,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int>,unsigned int>>::Unlink(
        this: p_m_listCachesToUnload,
        elem: pSOCache->m_unLRUHandle);
      p_m_listCachesToUnload->m_Memory.m_pMemory[m_unLRUHandle].m_Next = p_m_listCachesToUnload->m_FirstFree;
      p_m_listCachesToUnload->m_FirstFree = m_unLRUHandle;
    }
  }
  pSOCache->m_unLRUHandle = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10027C90
// Name: public: class GCSDK::CSharedObjectCache __near * GCSDK::CGCBase::YieldingFindOrLoadSOCache(class CSteamID const __near &)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CSharedObjectCache *__thiscall GCSDK::CGCBase::YieldingFindOrLoadSOCache(
        GCSDK::CGCBase *this,
        const CSteamID *steamID)
{
  const CSteamID *v2; // ebx
  GCSDK::CSharedObjectCache *SOCache; // eax
  GCSDK::CSharedObjectCache *v5; // esi
  GCSDK::CSharedObjectCache *v6; // eax
  int m_comp; // eax
  int m_unLRUHandle; // eax
  UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int> *m_pMemory; // edx
  CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,int>::Node_t insert; // [esp+Ch] [ebp-Ch] BYREF

  v2 = steamID;
  SOCache = GCSDK::CGCBase::FindSOCache(this, steamID);
  v5 = SOCache;
  if ( SOCache != nullptr )
  {
    m_unLRUHandle = SOCache->m_unLRUHandle;
    if ( m_unLRUHandle < 0 )
      return v5;
    if ( m_unLRUHandle >= this->m_listCachesToUnload.m_Memory.m_nAllocationCount )
      return v5;
    if ( m_unLRUHandle > this->m_listCachesToUnload.m_LastAlloc.index )
      return v5;
    m_pMemory = this->m_listCachesToUnload.m_Memory.m_pMemory;
    if ( m_pMemory[m_unLRUHandle].m_Previous == m_unLRUHandle && m_pMemory[m_unLRUHandle].m_Next != m_unLRUHandle )
      return v5;
    GCSDK::CGCBase::RemoveCacheFromLRU(this, pSOCache: v5);
LABEL_16:
    steamID = (const CSteamID *)v5;
    GCSDK::CGCBase::RemoveCacheFromLRU(this, pSOCache: v5);
    v5->m_unLRUHandle = CUtlLinkedList<GCSDK::CSharedObjectCache *,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int>,unsigned int>>::AddToTail(
                          this: &this->m_listCachesToUnload,
                          src: (GCSDK::CSharedObjectCache *const *)&steamID);
    return v5;
  }
  v6 = (GCSDK::CSharedObjectCache *)operator new(nSize: 0x84u);
  if ( v6 != nullptr )
    v5 = GCSDK::CSharedObjectCache::CSharedObjectCache(this: v6, steamIDOwner: v2);
  else
    v5 = nullptr;
  if ( this->BYieldingLoadSOCache(this, a2: v5) )
  {
    m_comp = (int)v2->m_steamid.m_comp;
    *((_DWORD *)&insert.key.m_steamid.m_comp + 1) = *((_DWORD *)&v2->m_steamid.m_comp + 1);
    *(_DWORD *)&insert.key.m_steamid.m_comp = m_comp;
    insert.elem = v5;
    CUtlRBTree<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,int>::Node_t,int,CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<CSteamID,GCSDK::CSharedObjectCache *,int>::Node_t,int>,int>>::Insert(
      this: &this->m_mapSOCache.m_Tree,
      &insert);
    this->YieldingSOCacheLoaded(this, a2: v5);
    goto LABEL_16;
  }
  GCSDK::EmitError(pchGroupName: SPEW_GC_25, pchMsg: "Unable to load SO cache for %llu\n", v2->m_steamid.m_unAll64Bits);
  if ( v5 != nullptr )
    ((void (__thiscall *)(GCSDK::CSharedObjectCache *, int))v5->dtr_CSharedObjectCache)(a1: v5, a2: 1);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10027DA0
// Name: public: bool GCSDK::CGCBase::BYieldingLockSteamID(class CSteamID const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GCSDK::CGCBase::BYieldingLockSteamID(GCSDK::CGCBase *this, CSteamID *steamID)
{
  CSteamID *v2; // ebx
  TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy> *p_m_hashSteamIDLocks; // esi
  unsigned int v4; // eax
  unsigned int m_cTheoreticalBuckets; // edi
  int v6; // edx
  HashBucket_t *v7; // eax
  HashLink_t *m_pList; // eax
  GCSDK::CLock *v9; // edi
  HashLink_t *v10; // esi
  const char *v11; // eax
  const char *v12; // eax
  TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::Iterator v14; // [esp+Ch] [ebp-Ch] BYREF

  v2 = steamID;
  p_m_hashSteamIDLocks = &this->m_hashSteamIDLocks;
  v4 = PearsonsHashFunctor<CSteamID>::operator()(
         this: &this->m_hashSteamIDLocks.m_Implementation.m_HashMechanism,
         unKey: steamID);
  m_cTheoreticalBuckets = p_m_hashSteamIDLocks->m_Implementation.m_cTheoreticalBuckets;
  v6 = v4 % m_cTheoreticalBuckets;
  if ( v4 % m_cTheoreticalBuckets >= p_m_hashSteamIDLocks->m_Implementation.m_cActiveBuckets )
    v6 -= m_cTheoreticalBuckets >> 1;
  v7 = THashBase<TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::KeyAccessor<CSteamID>,TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::HashAccessor,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::SearchBucketForKey(
         this: &p_m_hashSteamIDLocks->m_Implementation,
         bucket: &p_m_hashSteamIDLocks->m_Implementation.m_rgBuckets[v6],
         h: (HashLink_t *)v4,
         k: v2,
         fExactMatch: (bool *)&steamID + 3);
  if ( HIBYTE(steamID) != 0 && (m_pList = v7->m_pList) != nullptr )
    v9 = (GCSDK::CLock *)&m_pList[4];
  else
    v9 = nullptr;
  if ( v9 != nullptr )
    return v9->m_pJob == GCSDK::g_pJobCur || GCSDK::CJob::BYieldingAcquireLock(this: GCSDK::g_pJobCur, pLock: v9);
  TStandardHash<CSteamID,GCSDK::CLock,PearsonsHashFunctor<CSteamID>,ComparisonFunctor<CSteamID>,BaseAlloc<HashBucket_t,CSteamID,GCSDK::CLock>,InverseLogPolicy>::FindOrInsert(
    this: p_m_hashSteamIDLocks,
    result: &v14,
    k: (HashLink_t *)v2);
  if ( v14.m_ChangeNumber == v14.m_Container->m_ChangeNumber && *v14.m_ppCurrent != nullptr )
    v10 = *v14.m_ppCurrent + 4;
  else
    v10 = nullptr;
  v9 = (GCSDK::CLock *)v10;
  v11 = CSteamID::Render(this: v2);
  CUtlString::operator=(this: (CUtlString *)&v10[7], src: v11);
  if ( v10 != nullptr )
    return v9->m_pJob == GCSDK::g_pJobCur || GCSDK::CJob::BYieldingAcquireLock(this: GCSDK::g_pJobCur, pLock: v9);
  v12 = CSteamID::Render(this: v2);
  GCSDK::EmitInfo(pchGroupName: SPEW_GC_25, iSpewLevel: 1, iLevelLog: 1, pchMsg: "Unable to create lock for %s\n", v12);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10027E90
// Name: public: void GCSDK::CGCBase::YieldingStopPlaying(class CSteamID const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GCSDK::CGCBase::YieldingStopPlaying(
        GCSDK::CGCBase *this@<ecx>,
        int a2@<esi>,
        GCSDK::CSharedObjectCache *steamID)
{
  CSteamID *v3; // ebx
  const char *v5; // eax
  CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *UserSession; // eax
  GCSDK::CGCUserSession *v7; // esi
  unsigned int v8; // eax

  v3 = (CSteamID *)steamID;
  if ( GCSDK::CGCBase::BYieldingLockSteamID(this, (CSteamID *)steamID) )
  {
    UserSession = GCSDK::CGCBase::FindUserSession(this, steamID: v3);
    v7 = (GCSDK::CGCUserSession *)UserSession;
    if ( UserSession != nullptr )
    {
      ((void (__thiscall *)(CTHash<GCSDK::CGCUserSession *,unsigned __int64>::RecHdr_t *, int))UserSession->m_pRecHdrNext->m_nRunRatio)(
        a1: UserSession,
        a2);
      this->YieldingSessionStopPlaying(this, a2: v7);
      if ( v7->m_pSOCache != nullptr )
      {
        steamID = v7->m_pSOCache;
        GCSDK::CGCBase::RemoveCacheFromLRU(this, pSOCache: steamID);
        v8 = CUtlLinkedList<GCSDK::CSharedObjectCache *,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int>,unsigned int>>::AddToTail(
               this: &this->m_listCachesToUnload,
               src: &steamID);
        steamID->m_unLRUHandle = v8;
      }
      CTHash<GCSDK::CGCUserSession *,unsigned __int64>::Remove(
        this: &this->m_hashUserSessions,
        unKey: v3->m_steamid.m_unAll64Bits);
      ((void (__thiscall *)(GCSDK::CGCUserSession *, int))v7->dtr_CGCSession)(a1: v7, a2: 1);
    }
  }
  else
  {
    v5 = CSteamID::Render(this: v3);
    GCSDK::EmitError(pchGroupName: SPEW_GC_25, pchMsg: "Unable to lock steamID %s in YieldingStopPlaying\n", v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027F40
// Name: public: void GCSDK::CGCBase::YieldingStopGameserver(class CSteamID const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GCSDK::CGCBase::YieldingStopGameserver(
        GCSDK::CGCBase *this@<ecx>,
        int a2@<edi>,
        GCSDK::CSharedObjectCache *steamID)
{
  CSteamID *v3; // ebx
  const char *v5; // eax
  GCSDK::CGCGSSession *GSSession; // eax
  GCSDK::CGCGSSession *v7; // edi
  unsigned int v8; // eax

  v3 = (CSteamID *)steamID;
  if ( GCSDK::CGCBase::BYieldingLockSteamID(this, (CSteamID *)steamID) )
  {
    GSSession = (GCSDK::CGCGSSession *)GCSDK::CGCBase::FindGSSession(this, steamID: v3);
    v7 = GSSession;
    if ( GSSession != nullptr )
    {
      GCSDK::CGCGSSession::RemoveAllUsers(this: GSSession);
      ((void (__thiscall *)(GCSDK::CGCBase *, GCSDK::CGCGSSession *, int))this->YieldingSessionStopServer)(
        a1: this,
        a2: v7,
        a3: a2);
      if ( v7->m_pSOCache != nullptr )
      {
        steamID = v7->m_pSOCache;
        GCSDK::CGCBase::RemoveCacheFromLRU(this, pSOCache: steamID);
        v8 = CUtlLinkedList<GCSDK::CSharedObjectCache *,unsigned int,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<GCSDK::CSharedObjectCache *,unsigned int>,unsigned int>>::AddToTail(
               this: &this->m_listCachesToUnload,
               src: &steamID);
        steamID->m_unLRUHandle = v8;
      }
      CTHash<GCSDK::CGCUserSession *,unsigned __int64>::Remove(
        this: (CTHash<GCSDK::CGCUserSession *,unsigned __int64> *)&this->m_hashGSSessions,
        unKey: v3->m_steamid.m_unAll64Bits);
      ((void (__thiscall *)(GCSDK::CGCGSSession *, int))v7->dtr_CGCSession)(a1: v7, a2: 1);
    }
  }
  else
  {
    v5 = CSteamID::Render(this: v3);
    GCSDK::EmitError(pchGroupName: SPEW_GC_25, pchMsg: "Unable to lock steamID %s in YieldingStopGameserver\n", v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027FF0
// Name: public: class GCSDK::CGCGSSession __near * GCSDK::CGCBase::YieldingFindOrCreateGSSession(class CSteamID const __near &,unsigned int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
GCSDK::CGCGSSession *__thiscall GCSDK::CGCBase::YieldingFindOrCreateGSSession(
        GCSDK::CGCBase *this,
        GCSDK::CSharedObjectCache *steamID,
        unsigned int unServerAddr,
        int usServerPort)
{
  int v5; // eax
  GCSDK::CGCGSSession *result; // eax
  GCSDK::CGCGSSession *v8; // edi
  GCSDK::CSharedObjectCache *pSOCache; // [esp+10h] [ebp+8h]

  v5 = ((unsigned int)steamID->m_context.m_vecSubscribers.m_Memory.m_pMemory >> 20) & 0xF;
  if ( v5 != 3 && v5 != 4 )
    return nullptr;
  result = (GCSDK::CGCGSSession *)GCSDK::CGCBase::FindGSSession(this, (const CSteamID *)steamID);
  if ( result != nullptr )
  {
    result->m_unServerAddr = unServerAddr;
    result->m_usServerPort = usServerPort;
  }
  else
  {
    pSOCache = GCSDK::CGCBase::YieldingFindOrLoadSOCache(this, (const CSteamID *)steamID);
    result = this->CreateGSSession(this, a2: steamID, a3: pSOCache, a4: unServerAddr, a5: usServerPort);
    v8 = result;
    if ( result != nullptr )
    {
      GCSDK::CGCBase::RemoveCacheFromLRU(this, pSOCache);
      *CTHash<GCSDK::CGCGSSession *,unsigned __int64>::PvRecordInsert(
         this: &this->m_hashGSSessions,
         unKey: *(_QWORD *)&steamID->__vftable) = v8;
      this->YieldingSessionStartServer(this, a2: v8);
      return v8;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100280A0
// Name: public: virtual bool GCSDK::CStopPlayingJob::BYieldingRunGCJob(class GCSDK::CNetPacket __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GCSDK::CStopPlayingJob::BYieldingRunGCJob@<al>(
        GCSDK::CStopPlayingJob *this@<ecx>,
        int a2@<esi>,
        GCSDK::CNetPacket *pNetPacket)
{
  GCSDK::CGCBase::YieldingStopPlaying(
    this: this->m_pGC,
    a2,
    steamID: (GCSDK::CSharedObjectCache *)(pNetPacket->m_pubData + 30));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100280C0
// Name: public: virtual bool GCSDK::CStopGameserverJob::BYieldingRunGCJob(class GCSDK::CNetPacket __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GCSDK::CStopGameserverJob::BYieldingRunGCJob@<al>(
        GCSDK::CStopGameserverJob *this@<ecx>,
        int a2@<edi>,
        GCSDK::CNetPacket *pNetPacket)
{
  GCSDK::CGCBase::YieldingStopGameserver(
    this: this->m_pGC,
    a2,
    steamID: (GCSDK::CSharedObjectCache *)(pNetPacket->m_pubData + 30));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100280E0
// Name: public: void GCSDK::CGCBase::YieldingStartPlaying(class CSteamID const __near &,class CSteamID const __near &,unsigned int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCSDK::CGCBase::YieldingStartPlaying(
        GCSDK::CGCBase *this,
        CSteamID *steamID,
        GCSDK::CSharedObjectCache *gsSteamID,
        unsigned int unServerAddr,
        int usServerPort)
{
  const char *v7; // eax
  GCSDK::CGCUserSession *UserSession; // edi
  GCSDK::CSharedObjectCache *SOCache; // eax
  const char *v10; // eax
  const char *v11; // eax
  GCSDK::CSharedObjectCache *pSOCache; // [esp+10h] [ebp+8h]

  if ( !GCSDK::CGCBase::BYieldingLockSteamID(this, steamID) )
  {
    v7 = CSteamID::Render(this: steamID);
    GCSDK::EmitError(pchGroupName: SPEW_GC_25, pchMsg: "Failed to lock steamID %s in YieldingStartPlaying\n", v7);
    return;
  }
  UserSession = (GCSDK::CGCUserSession *)GCSDK::CGCBase::FindUserSession(this, steamID);
  if ( UserSession == nullptr )
  {
    if ( !GCSDK::CGCBase::BYieldingLockSteamID(this, steamID)
      || (SOCache = GCSDK::CGCBase::YieldingFindOrLoadSOCache(this, steamID), pSOCache = SOCache, SOCache == nullptr) )
    {
      v10 = CSteamID::Render(this: steamID);
      GCSDK::EmitError(pchGroupName: SPEW_GC_25, pchMsg: "Failed to get cache for user %s\n", v10);
      return;
    }
    UserSession = this->CreateUserSession(this, a2: steamID, a3: SOCache);
    if ( UserSession == nullptr )
    {
      v11 = CSteamID::Render(this: steamID);
      GCSDK::EmitError(pchGroupName: SPEW_GC_25, pchMsg: "Failed to create user session for %s\n", v11);
      return;
    }
    GCSDK::CGCBase::RemoveCacheFromLRU(this, pSOCache);
    *CTHash<GCSDK::CGCUserSession *,unsigned __int64>::PvRecordInsert(
       this: &this->m_hashUserSessions,
       unKey: steamID->m_steamid.m_unAll64Bits) = UserSession;
    this->YieldingSessionStartPlaying(this, a2: UserSession);
  }
  GCSDK::CGCBase::YieldingFindOrCreateGSSession(this, steamID: gsSteamID, unServerAddr, usServerPort);
  UserSession->BSetServer(this: UserSession, a2: (const CSteamID *)gsSteamID);
}

//------------------------------------------------------------------------------
// Address: 0x100281F0
// Name: public: virtual bool GCSDK::CStartPlayingJob::BYieldingRunGCJob(class GCSDK::CNetPacket __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CStartPlayingJob::BYieldingRunGCJob(
        GCSDK::CStartPlayingJob *this,
        GCSDK::CNetPacket *pNetPacket)
{
  GCSDK::CGCBase::YieldingStartPlaying(
    this: this->m_pGC,
    steamID: (CSteamID *)(pNetPacket->m_pubData + 30),
    gsSteamID: (GCSDK::CSharedObjectCache *)(pNetPacket->m_pubData + 38),
    unServerAddr: *(_DWORD *)(pNetPacket->m_pubData + 46),
    usServerPort: *((unsigned __int16 *)pNetPacket->m_pubData + 25));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10028220
// Name: public: virtual bool GCSDK::CStartGameserverJob::BYieldingRunGCJob(class GCSDK::CNetPacket __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GCSDK::CStartGameserverJob::BYieldingRunGCJob(
        GCSDK::CStartGameserverJob *this,
        GCSDK::CNetPacket *pNetPacket)
{
  int v2; // ebx
  GCSDK::CGCBase *m_pGC; // edi
  GCSDK::CSharedObjectCache *v4; // esi
  const char *v5; // eax
  GCSDK::CNetPacket *pNetPacketa; // [esp+14h] [ebp+8h]

  v2 = *((unsigned __int16 *)pNetPacket->m_pubData + 21);
  m_pGC = this->m_pGC;
  v4 = (GCSDK::CSharedObjectCache *)(pNetPacket->m_pubData + 30);
  pNetPacketa = *(GCSDK::CNetPacket **)(pNetPacket->m_pubData + 38);
  if ( GCSDK::CGCBase::BYieldingLockSteamID(this: m_pGC, steamID: (CSteamID *)v4) )
  {
    GCSDK::CGCBase::YieldingFindOrCreateGSSession(
      this: m_pGC,
      steamID: v4,
      unServerAddr: (unsigned int)pNetPacketa,
      usServerPort: v2);
  }
  else
  {
    v5 = CSteamID::Render(this: (CSteamID *)v4);
    GCSDK::EmitError(pchGroupName: SPEW_GC_25, pchMsg: "Failed to lock steamID %s in YieldingStartGameserver\n", v5);
  }
  return 1;
}
