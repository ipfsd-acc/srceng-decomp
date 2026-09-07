// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/datacenter.cpp
// Functions: 8
// ============================================================

#include "matchmaking\datacenter.h"

//------------------------------------------------------------------------------
// Address: 0x100025C0
// Name: public: virtual class KeyValues __near * CDatacenter::GetDataInfo(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CDatacenter::GetDataInfo(CDatacenter *this)
{
  return this->m_pDataInfo;
}

//------------------------------------------------------------------------------
// Address: 0x100025D0
// Name: public: virtual class KeyValues __near * CDatacenter::GetStats(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CDatacenter::GetStats(CDatacenter *this)
{
  KeyValues *m_pInfoChunks; // ecx

  m_pInfoChunks = this->m_pInfoChunks;
  if ( m_pInfoChunks != nullptr )
    return KeyValues::FindKey(this: m_pInfoChunks, keyName: "stat", bCreate: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100025F0
// Name: protected: void CDatacenter::OnDatacenterInfoUpdated(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenter::OnDatacenterInfoUpdated(CDatacenter *this)
{
  CDatacenter *v1; // edi
  KeyValues *m_pInfoChunks; // ecx
  KeyValues *Key; // eax
  KeyValues *FirstValue; // esi
  const char *Name; // eax
  const char *v6; // eax
  char *m_pszString; // edi
  const char *v8; // eax
  const char *v9; // eax
  KeyValues *v10; // esi
  int Int; // eax
  KeyValues *v12; // esi
  IMatchEventsSubscription *v13; // eax
  const char *v14; // [esp-4h] [ebp-24h]
  const char *String; // [esp-4h] [ebp-24h]
  CDatacenter *v16; // [esp+14h] [ebp-Ch]
  ConVarRef cvRef; // [esp+18h] [ebp-8h] BYREF

  v1 = this;
  m_pInfoChunks = this->m_pInfoChunks;
  v16 = v1;
  if ( m_pInfoChunks != nullptr )
  {
    Key = KeyValues::FindKey(this: m_pInfoChunks, keyName: "cvar", bCreate: false);
    if ( Key != nullptr )
    {
      FirstValue = KeyValues::GetFirstValue(this: Key);
      if ( FirstValue != nullptr )
      {
        do
        {
          Name = KeyValues::GetName(this: FirstValue);
          ConVarRef::ConVarRef(this: &cvRef, pName: Name, bIgnoreMissing: true);
          if ( ConVarRef::IsValid(this: &cvRef) )
          {
            m_pszString = cvRef.m_pConVarState->m_Value.m_pszString;
            String = KeyValues::GetString(this: FirstValue, keyName: nullptr, defaultValue: str);
            v8 = KeyValues::GetName(this: FirstValue);
            DevMsg(
              a1: "CDatacenter::OnDatacenterInfoUpdated updating cvar '%s' = '%s' -> '%s'\n",
              v8,
              m_pszString,
              String);
            v9 = KeyValues::GetString(this: FirstValue, keyName: nullptr, defaultValue: str);
            cvRef.m_pConVar->SetValue_4(this: cvRef.m_pConVar, a2: v9);
          }
          else
          {
            v14 = KeyValues::GetString(this: FirstValue, keyName: nullptr, defaultValue: str);
            v6 = KeyValues::GetName(this: FirstValue);
            DevWarning(a1: "CDatacenter::OnDatacenterInfoUpdated failed to update cvar '%s' = '%s'\n", v6, v14);
          }
          FirstValue = KeyValues::GetNextValue(this: FirstValue);
        }
        while ( FirstValue != nullptr );
        v1 = v16;
      }
    }
  }
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
  {
    Int = KeyValues::GetInt(this: v1->m_pInfoChunks, keyName: "version", defaultValue: 0);
    v12 = KeyValues::KeyValues(this: v10, setName: "OnDatacenterUpdate", firstKey: "version", firstValue: Int);
  }
  else
  {
    v12 = nullptr;
  }
  v13 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v13->BroadcastEvent(this: v13, a2: v12);
}

//------------------------------------------------------------------------------
// Address: 0x10002780
// Name: public: virtual void CDatacenter::EnableUpdate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenter::EnableUpdate(CDatacenter *this, bool bEnable)
{
  double v3; // st7
  double v4; // st7
  CDatacenter::State_t m_eState; // [esp+8h] [ebp-10h]
  float flNextUpdateTime; // [esp+1Ch] [ebp+4h]
  float flNextUpdateTimea; // [esp+1Ch] [ebp+4h]

  DevMsg(a1: "Datacenter::EnableUpdate( %d ), current state = %d\n", bEnable, this->m_eState);
  if ( bEnable )
  {
    if ( this->m_eState == STATE_PAUSED )
    {
      this->m_eState = STATE_IDLE;
      flNextUpdateTime = mm_datacenter_query_delay.m_pParent->m_Value.m_fValue;
      v3 = _Plat_FloatTime() + flNextUpdateTime;
      if ( v3 > this->m_flNextSearchTime )
      {
        flNextUpdateTimea = v3;
        this->m_flNextSearchTime = flNextUpdateTimea;
      }
    }
  }
  else
  {
    m_eState = this->m_eState;
    v4 = _Plat_FloatTime();
    DevMsg(a1: "Datacenter::RequestStop, time %.2f, state %d\n", v4, m_eState);
    this->m_eState = STATE_PAUSED;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002810
// Name: public: virtual void CDatacenter::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenter::OnEvent(CDatacenter *this, KeyValues *pEvent)
{
  const char *Name; // eax

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: Name, s2: "OnProfileStorageAvailable") == 0 )
    KeyValues::GetInt(this: pEvent, keyName: "iController", defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10002840
// Name: protected: void CDatacenter::RequestUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenter::RequestUpdate(CDatacenter *this)
{
  double v2; // st7
  CDatacenter::State_t m_eState; // [esp+8h] [ebp-10h]
  float m_fValue; // [esp+14h] [ebp-4h]

  m_eState = this->m_eState;
  v2 = _Plat_FloatTime();
  DevMsg(a1: "Datacenter::RequestStop, time %.2f, state %d\n", v2, m_eState);
  this->m_eState = STATE_IDLE;
  DevMsg(a1: "Datacenter::RequestUpdate %s\n", "successful");
  m_fValue = mm_datacenter_update_interval.m_pParent->m_Value.m_fValue;
  this->m_flNextSearchTime = _Plat_FloatTime() + m_fValue;
  CDatacenter::OnDatacenterInfoUpdated(this);
}

//------------------------------------------------------------------------------
// Address: 0x100028A0
// Name: mm_datacenter_debugprint
// Source: json
//------------------------------------------------------------------------------
void __cdecl mm_datacenter_debugprint()
{
  KeyValues *v0; // eax
  KeyValues *v1; // eax
  IKeyValuesDumpContext pDump; // [esp+0h] [ebp-8h] BYREF
  int v3; // [esp+4h] [ebp-4h]

  v0 = g_pDatacenter->GetDataInfo(this: g_pDatacenter);
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v3 = 1;
  KeyValues::Dump(this: v0, &pDump, nIndentLevel: 1);
  v1 = (KeyValues *)g_pDatacenter->GetStats(this: g_pDatacenter);
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v3 = 1;
  KeyValues::Dump(this: v1, &pDump, nIndentLevel: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10002900
// Name: public: void CDatacenter::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenter::Update(CDatacenter *this)
{
  CDatacenter::State_t m_eState; // eax
  double v3; // st7

  m_eState = this->m_eState;
  if ( m_eState != STATE_IDLE )
  {
    if ( (unsigned int)(m_eState - 1) <= 1 )
      CDatacenter::RequestUpdate(this);
  }
  else if ( _Plat_FloatTime() > this->m_flNextSearchTime && !IsLocalClientConnectedToServer() )
  {
    v3 = _Plat_FloatTime();
    DevMsg(a1: "Datacenter::RequestStart, time %.2f\n", v3);
    this->m_eState = STATE_REQUESTING_DATA;
  }
}

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x1001C480
// Name: public: virtual class KeyValues __near * CDatacenter::GetDataInfo(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDatacenter::GetDataInfo(ConCommandBase *this)
{
  return this->m_pszName;
}

//------------------------------------------------------------------------------
// Address: 0x1001C490
// Name: public: virtual class KeyValues __near * CDatacenter::GetStats(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CDatacenter::GetStats(CDatacenter *this)
{
  KeyValues *m_pInfoChunks; // ecx

  m_pInfoChunks = this->m_pInfoChunks;
  if ( m_pInfoChunks != nullptr )
    return KeyValues::FindKey(this: m_pInfoChunks, keyName: "stat", bCreate: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001C4B0
// Name: public: virtual bool CDatacenter::CanReachDatacenter(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDatacenter::CanReachDatacenter(CDatacenter *this)
{
  return this->m_bCanReachDatacenter;
}

//------------------------------------------------------------------------------
// Address: 0x1001C4C0
// Name: protected: void CDatacenter::RequestStart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenter::RequestStart(CDatacenter *this)
{
  GCSDK::CGCClient *v2; // eax
  CGCClientJobDataRequest *v3; // eax
  CGCClientJobDataRequest *v4; // eax
  double v5; // st7

  if ( GGCClient() != nullptr )
  {
    v2 = GGCClient();
    if ( !GCSDK::CJobMgr::BJobExists(this: &v2->m_JobMgr, jobID: this->m_JobIDDataRequest) )
    {
      v3 = (CGCClientJobDataRequest *)operator new(nSize: 0xA0u);
      if ( v3 != nullptr )
        v4 = CGCClientJobDataRequest::CGCClientJobDataRequest(this: v3);
      else
        v4 = nullptr;
      LODWORD(this->m_JobIDDataRequest) = v4->m_JobID;
      HIDWORD(this->m_JobIDDataRequest) = HIDWORD(v4->m_JobID);
      GCSDK::CJob::StartJob(this: v4, pvStartParam: nullptr);
      v5 = _Plat_FloatTime();
      DevMsg(a1: "Datacenter::RequestStart, time %.2f\n", v5);
      this->m_eState = STATE_REQUESTING_DATA;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C540
// Name: protected: void CDatacenter::RequestStop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenter::RequestStop(CDatacenter *this)
{
  double v2; // st7
  bool v3; // bl
  GCSDK::CGCClient *v4; // eax
  CDatacenter::State_t m_eState; // [esp+8h] [ebp-10h]
  float m_fValue; // [esp+14h] [ebp-4h]

  m_eState = this->m_eState;
  v2 = _Plat_FloatTime();
  DevMsg(a1: "Datacenter::RequestStop, time %.2f, state %d\n", v2, m_eState);
  v3 = false;
  if ( GGCClient() != nullptr )
  {
    v4 = GGCClient();
    v3 = GCSDK::CJobMgr::BJobExists(this: &v4->m_JobMgr, jobID: this->m_JobIDDataRequest);
  }
  LODWORD(this->m_JobIDDataRequest) = -1;
  HIDWORD(this->m_JobIDDataRequest) = -1;
  if ( v3 )
  {
    m_fValue = mm_datacenter_retry_interval.m_pParent->m_Value.m_fValue;
    this->m_flNextSearchTime = _Plat_FloatTime() + m_fValue;
  }
  this->m_eState = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001C5C0
// Name: protected: void CDatacenter::OnDatacenterInfoUpdated(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenter::OnDatacenterInfoUpdated(CDatacenter *this)
{
  int Int; // esi
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMatchEventsSubscription *v4; // eax

  Int = KeyValues::GetInt(this: this->m_pInfoChunks, keyName: "version", defaultValue: 0);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "OnDatacenterUpdate", firstKey: "version", firstValue: Int);
    if ( v3 != nullptr )
    {
      v4 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
      v4->BroadcastEvent(this: v4, a2: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C620
// Name: public: virtual class KeyValues __near * CDatacenterCmdBatchImpl::GetResult(int)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CDatacenterCmdBatchImpl::GetResult(CDatacenterCmdBatchImpl *this, int idx)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001C630
// Name: public: virtual void CDatacenterCmdBatchImpl::SetDestroyWhenFinished(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenterCmdBatchImpl::SetDestroyWhenFinished(
        CDatacenterCmdBatchImpl *this,
        bool bDestroyWhenFinished)
{
  this->m_bDestroyWhenFinished = bDestroyWhenFinished;
}

//------------------------------------------------------------------------------
// Address: 0x1001C640
// Name: public: virtual void CDatacenterCmdBatchImpl::SetNumRetriesAllowedPerCmd(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenterCmdBatchImpl::SetNumRetriesAllowedPerCmd(
        CDatacenterCmdBatchImpl *this,
        int numRetriesAllowed)
{
  this->m_numRetriesAllowedPerCmd = numRetriesAllowed;
}

//------------------------------------------------------------------------------
// Address: 0x1001C650
// Name: public: virtual void CDatacenterCmdBatchImpl::SetRetryCmdTimeout(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenterCmdBatchImpl::SetRetryCmdTimeout(CDatacenterCmdBatchImpl *this, float flRetryCmdTimeout)
{
  this->m_flRetryCmdTimeout = flRetryCmdTimeout;
}

//------------------------------------------------------------------------------
// Address: 0x1001C670
// Name: public: virtual void CDatacenterCmdBatchImpl::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenterCmdBatchImpl::Update(CDatacenterCmdBatchImpl *this)
{
  if ( this->m_bDestroyWhenFinished )
    this->Destroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001C680
// Name: public: virtual void CDatacenter::EnableUpdate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenter::EnableUpdate(CDatacenter *this, bool bEnable)
{
  double v3; // st7
  float bEnablea; // [esp+10h] [ebp+8h]
  float bEnableb; // [esp+10h] [ebp+8h]

  DevMsg(a1: "Datacenter::EnableUpdate( %d ), current state = %d\n", bEnable, this->m_eState);
  if ( bEnable )
  {
    if ( this->m_eState == (STATE_REQUESTING_DATA|STATE_REQUESTING_CHUNKS) )
    {
      this->m_eState = 0;
      bEnablea = mm_datacenter_query_delay.m_pParent->m_Value.m_fValue;
      v3 = _Plat_FloatTime() + bEnablea;
      if ( v3 > this->m_flNextSearchTime )
      {
        bEnableb = v3;
        this->m_flNextSearchTime = bEnableb;
      }
    }
  }
  else
  {
    CDatacenter::RequestStop(this);
    this->m_eState = STATE_REQUESTING_DATA|STATE_REQUESTING_CHUNKS;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C700
// Name: public: virtual void CDatacenter::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenter::OnEvent(CDatacenter *this, KeyValues *pEvent)
{
  const char *Name; // eax

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: Name, s2: "OnProfileStorageAvailable") == 0 )
    KeyValues::GetInt(this: pEvent, keyName: "iController", defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001C740
// Name: protected: void CDatacenter::RequestUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenter::RequestUpdate(CDatacenter *this)
{
  char v2; // bl
  GCSDK::CGCClient *v3; // eax
  GCSDK::CJob *PJob; // eax
  GCSDK::CJob *v5; // edi
  KeyValues *m_pDataInfo; // ecx
  KeyValues *m_pInfoChunks; // ecx
  const char *v8; // eax
  float m_fValue; // [esp+Ch] [ebp-4h]

  v2 = 0;
  if ( GGCClient() != nullptr )
  {
    v3 = GGCClient();
    PJob = GCSDK::CJobMgr::GetPJob(this: &v3->m_JobMgr, jobID: this->m_JobIDDataRequest);
    v5 = PJob;
    if ( PJob != nullptr )
    {
      if ( LOBYTE(PJob[1].m_JobID) == 0 )
        return;
      v2 = BYTE1(PJob[1].m_JobID);
      if ( v2 != 0 )
      {
        m_pDataInfo = this->m_pDataInfo;
        if ( m_pDataInfo != nullptr )
          KeyValues::deleteThis(this: m_pDataInfo);
        m_pInfoChunks = this->m_pInfoChunks;
        if ( m_pInfoChunks != nullptr )
          KeyValues::deleteThis(this: m_pInfoChunks);
        this->m_pDataInfo = KeyValues::MakeCopy(this: *((KeyValues **)&v5[1] + 3));
        this->m_pInfoChunks = KeyValues::MakeCopy(this: *((KeyValues **)&v5[1] + 3));
      }
      BYTE2(v5[1].m_JobID) = 0;
    }
  }
  CDatacenter::RequestStop(this);
  v8 = "successful";
  if ( v2 == 0 )
    v8 = "failed";
  DevMsg(a1: "Datacenter::RequestUpdate %s\n", v8);
  this->m_bCanReachDatacenter = v2;
  if ( v2 != 0 )
  {
    m_fValue = mm_datacenter_update_interval.m_pParent->m_Value.m_fValue;
    this->m_flNextSearchTime = _Plat_FloatTime() + m_fValue;
    CDatacenter::OnDatacenterInfoUpdated(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C810
// Name: mm_datacenter_debugprint
// Source: json
//------------------------------------------------------------------------------
void __cdecl mm_datacenter_debugprint()
{
  KeyValues *v0; // eax
  KeyValues *v1; // eax
  IKeyValuesDumpContext pDump; // [esp+0h] [ebp-8h] BYREF
  int v3; // [esp+4h] [ebp-4h]

  v0 = g_pDatacenter->GetDataInfo(this: g_pDatacenter);
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v3 = 1;
  KeyValues::Dump(this: v0, &pDump, nIndentLevel: 1);
  v1 = (KeyValues *)g_pDatacenter->GetStats(this: g_pDatacenter);
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v3 = 1;
  KeyValues::Dump(this: v1, &pDump, nIndentLevel: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1001C870
// Name: public: void CDatacenter::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenter::Update(CDatacenter *this)
{
  GCSDK::CGCClient *v2; // eax
  CDatacenter::State_t m_eState; // eax
  int i; // esi
  CDatacenterCmdBatchImpl *v5; // ecx

  if ( GGCClient() != nullptr && !IsLocalClientConnectedToServer() )
  {
    v2 = GGCClient();
    GCSDK::CGCClient::BMainLoop(this: v2, ulLimitMicroseconds: 0x3E8u);
  }
  m_eState = this->m_eState;
  if ( m_eState != 0 )
  {
    if ( (unsigned int)(m_eState - 1) <= 1 )
      CDatacenter::RequestUpdate(this);
  }
  else if ( _Plat_FloatTime() > this->m_flNextSearchTime && !IsLocalClientConnectedToServer() )
  {
    CDatacenter::RequestStart(this);
  }
  for ( i = 0; i < this->m_arrCmdBatchObjects.m_Size; ++i )
  {
    v5 = this->m_arrCmdBatchObjects.m_Memory.m_pMemory[i];
    v5->Update(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C8F0
// Name: public: virtual CDatacenter::~CDatacenter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenter::~CDatacenter(CDatacenter *this)
{
  KeyValues *m_pInfoChunks; // ecx
  KeyValues *m_pDataInfo; // ecx
  GCSDK::CGCClient *v4; // eax
  GCSDK::CJob *PJob; // eax

  m_pInfoChunks = this->m_pInfoChunks;
  this->IDatacenter::__vftable = (CDatacenter_vtbl *)&CDatacenter::`vftable'{for `IDatacenter'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CDatacenter::`vftable'{for `IMatchEventsSink'};
  if ( m_pInfoChunks != nullptr )
    KeyValues::deleteThis(this: m_pInfoChunks);
  m_pDataInfo = this->m_pDataInfo;
  this->m_pInfoChunks = nullptr;
  if ( m_pDataInfo != nullptr )
    KeyValues::deleteThis(this: m_pDataInfo);
  this->m_pDataInfo = nullptr;
  if ( GGCClient() != nullptr )
  {
    v4 = GGCClient();
    PJob = GCSDK::CJobMgr::GetPJob(this: &v4->m_JobMgr, jobID: this->m_JobIDDataRequest);
    if ( PJob != nullptr )
      ((void (__thiscall *)(GCSDK::CJob *, int))PJob->dtr_CJob)(a1: PJob, a2: 1);
  }
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_arrCmdBatchObjects);
}

//------------------------------------------------------------------------------
// Address: 0x1001C990
// Name: public: virtual void CDatacenterCmdBatchImpl::AddCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenterCmdBatchImpl::AddCommand(CDatacenterCmdBatchImpl *this, KeyValues *pCommand)
{
  KeyValues *Copy; // eax
  int m_Size; // edi
  KeyValues *v5; // ebx
  int m_nAllocationCount; // eax
  KeyValues **m_pMemory; // ecx
  int v8; // eax
  KeyValues **v9; // eax

  if ( pCommand != nullptr )
  {
    Copy = KeyValues::MakeCopy(this: pCommand);
    m_Size = this->m_arrCommands.m_Size;
    v5 = Copy;
    m_nAllocationCount = this->m_arrCommands.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<GCSDK::CLock *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_arrCommands,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_arrCommands.m_Size;
    m_pMemory = this->m_arrCommands.m_Memory.m_pMemory;
    v8 = this->m_arrCommands.m_Size - m_Size - 1;
    this->m_arrCommands.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = &this->m_arrCommands.m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CA00
// Name: public: virtual class IDatacenterCmdBatch __near * CDatacenter::CreateCmdBatch(void)
// Source: json
//------------------------------------------------------------------------------
CDatacenterCmdBatchImpl *__thiscall CDatacenter::CreateCmdBatch(CDatacenter *this)
{
  CDatacenterCmdBatchImpl *v2; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDatacenterCmdBatchImpl **m_pMemory; // ecx
  int v6; // eax
  CDatacenterCmdBatchImpl **v7; // eax
  CDatacenterCmdBatchImpl *pBatch; // [esp+Ch] [ebp-4h]

  v2 = (CDatacenterCmdBatchImpl *)operator new(nSize: 0x28u);
  if ( v2 != nullptr )
  {
    v2->__vftable = (CDatacenterCmdBatchImpl_vtbl *)&CDatacenterCmdBatchImpl::`vftable';
    v2->m_pParent = this;
    v2->m_arrCommands.m_Memory.m_pMemory = nullptr;
    v2->m_arrCommands.m_Memory.m_nAllocationCount = 0;
    v2->m_arrCommands.m_Memory.m_nGrowSize = 0;
    v2->m_arrCommands.m_Size = 0;
    v2->m_arrCommands.m_pElements = nullptr;
    v2->m_numRetriesAllowedPerCmd = 0;
    v2->m_flRetryCmdTimeout = 0.0;
    v2->m_bDestroyWhenFinished = true;
    pBatch = v2;
  }
  else
  {
    pBatch = nullptr;
  }
  m_Size = this->m_arrCmdBatchObjects.m_Size;
  m_nAllocationCount = this->m_arrCmdBatchObjects.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<GCSDK::CLock *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_arrCmdBatchObjects,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_arrCmdBatchObjects.m_Size;
  m_pMemory = this->m_arrCmdBatchObjects.m_Memory.m_pMemory;
  v6 = this->m_arrCmdBatchObjects.m_Size - m_Size - 1;
  this->m_arrCmdBatchObjects.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_arrCmdBatchObjects.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pBatch;
  return pBatch;
}

//------------------------------------------------------------------------------
// Address: 0x1001CAB0
// Name: public: virtual void CDatacenterCmdBatchImpl::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenterCmdBatchImpl::Destroy(CDatacenterCmdBatchImpl *this)
{
  CDatacenter *m_pParent; // eax
  int i; // edi
  KeyValues **m_pMemory; // eax
  GCSDK::CLock *src; // [esp+8h] [ebp-4h] BYREF

  m_pParent = this->m_pParent;
  if ( m_pParent != nullptr )
  {
    src = (GCSDK::CLock *)this;
    CUtlVector<GCSDK::CLock *,CUtlMemory<GCSDK::CLock *,int>>::FindAndRemove(
      this: (CUtlVector<GCSDK::CLock *,CUtlMemory<GCSDK::CLock *,int> > *)&m_pParent->m_arrCmdBatchObjects,
      &src);
  }
  for ( i = 0; i < this->m_arrCommands.m_Size; ++i )
    KeyValues::deleteThis(this: this->m_arrCommands.m_Memory.m_pMemory[i]);
  this->m_arrCommands.m_Size = 0;
  if ( this->m_arrCommands.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_arrCommands.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_arrCommands.m_Memory.m_pMemory);
      this->m_arrCommands.m_Memory.m_pMemory = nullptr;
    }
    this->m_arrCommands.m_Memory.m_nAllocationCount = 0;
  }
  this->m_arrCommands.m_pElements = this->m_arrCommands.m_Memory.m_pMemory;
  this->m_arrCommands.m_Size = 0;
  if ( this->m_arrCommands.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_arrCommands.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_arrCommands.m_Memory.m_pMemory);
      this->m_arrCommands.m_Memory.m_pMemory = nullptr;
    }
    this->m_arrCommands.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_arrCommands.m_Memory.m_pMemory;
  this->m_arrCommands.m_pElements = m_pMemory;
  if ( this->m_arrCommands.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_arrCommands.m_Memory.m_pMemory = nullptr;
    }
    this->m_arrCommands.m_Memory.m_nAllocationCount = 0;
  }
  free(pMem: this);
}

} // namespace matchmaking

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x10005BB0
// Name: public: virtual class KeyValues __near * CDlcManager::GetDataInfo(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CDlcManager::GetDataInfo(CDlcManager *this)
{
  return this->m_pDataInfo;
}

//------------------------------------------------------------------------------
// Address: 0x10005EE0
// Name: public: virtual class KeyValues __near * CDatacenter::GetDataInfo(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDatacenter::GetDataInfo(ConCommandBase *this)
{
  return this->m_pszName;
}

//------------------------------------------------------------------------------
// Address: 0x10005EF0
// Name: public: virtual class KeyValues __near * CDatacenter::GetStats(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CDatacenter::GetStats(CDatacenter *this)
{
  KeyValues *m_pInfoChunks; // ecx

  m_pInfoChunks = this->m_pInfoChunks;
  if ( m_pInfoChunks != nullptr )
    return KeyValues::FindKey(this: m_pInfoChunks, keyName: "stat", bCreate: false);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10005F10
// Name: public: virtual bool CDatacenter::CanReachDatacenter(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDatacenter::CanReachDatacenter(CDatacenter *this)
{
  return this->m_bCanReachDatacenter;
}

//------------------------------------------------------------------------------
// Address: 0x10005F80
// Name: public: virtual void CDatacenter::EnableUpdate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenter::EnableUpdate(CDatacenter *this, bool bEnable)
{
  double v3; // st7
  double v4; // st7
  CDatacenter::State_t m_eState; // [esp+8h] [ebp-10h]
  float bEnablea; // [esp+20h] [ebp+8h]
  float bEnableb; // [esp+20h] [ebp+8h]

  DevMsg(a1: "Datacenter::EnableUpdate( %d ), current state = %d\n", bEnable, this->m_eState);
  if ( bEnable )
  {
    if ( this->m_eState == STATE_PAUSED )
    {
      this->m_eState = STATE_IDLE;
      bEnablea = mm_datacenter_query_delay.m_pParent->m_Value.m_fValue;
      v3 = _Plat_FloatTime() + bEnablea;
      if ( v3 > this->m_flNextSearchTime )
      {
        bEnableb = v3;
        this->m_flNextSearchTime = bEnableb;
      }
    }
  }
  else
  {
    m_eState = this->m_eState;
    v4 = _Plat_FloatTime();
    DevMsg(a1: "Datacenter::RequestStop, time %.2f, state %d\n", v4, m_eState);
    this->m_eState = STATE_PAUSED;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006010
// Name: public: virtual void CDatacenter::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenter::OnEvent(CDatacenter *this, KeyValues *pEvent)
{
  const char *Name; // eax

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: Name, s2: "OnProfileStorageAvailable") == 0 )
    KeyValues::GetInt(this: pEvent, keyName: "iController", defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10006050
// Name: protected: void CDatacenter::RequestUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenter::RequestUpdate(CDatacenter *this)
{
  double v2; // st7
  CDatacenter::State_t m_eState; // [esp+8h] [ebp-Ch]

  m_eState = this->m_eState;
  v2 = _Plat_FloatTime();
  DevMsg(a1: "Datacenter::RequestStop, time %.2f, state %d\n", v2, m_eState);
  this->m_eState = STATE_IDLE;
  DevMsg(a1: "Datacenter::RequestUpdate %s\n", "failed");
  this->m_bCanReachDatacenter = false;
}

//------------------------------------------------------------------------------
// Address: 0x10006090
// Name: mm_datacenter_debugprint
// Source: json
//------------------------------------------------------------------------------
void __cdecl mm_datacenter_debugprint()
{
  KeyValues *v0; // eax
  KeyValues *v1; // eax
  IKeyValuesDumpContext pDump; // [esp+0h] [ebp-8h] BYREF
  int v3; // [esp+4h] [ebp-4h]

  v0 = g_pDatacenter->GetDataInfo(this: g_pDatacenter);
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v3 = 1;
  KeyValues::Dump(this: v0, &pDump, nIndentLevel: 1);
  v1 = (KeyValues *)g_pDatacenter->GetStats(this: g_pDatacenter);
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v3 = 1;
  KeyValues::Dump(this: v1, &pDump, nIndentLevel: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100060F0
// Name: public: void CDatacenter::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatacenter::Update(CDatacenter *this)
{
  CDatacenter::State_t m_eState; // eax
  double v3; // st7
  int i; // edi
  CDatacenterCmdBatchImpl *v5; // ecx

  m_eState = this->m_eState;
  if ( m_eState != STATE_IDLE )
  {
    if ( (unsigned int)(m_eState - 1) <= 1 )
      CDatacenter::RequestUpdate(this);
  }
  else if ( _Plat_FloatTime() > this->m_flNextSearchTime && !IsLocalClientConnectedToServer() )
  {
    v3 = _Plat_FloatTime();
    DevMsg(a1: "Datacenter::RequestStart, time %.2f\n", v3);
    this->m_eState = STATE_REQUESTING_DATA;
  }
  for ( i = 0; i < this->m_arrCmdBatchObjects.m_Size; ++i )
  {
    v5 = this->m_arrCmdBatchObjects.m_Memory.m_pMemory[i];
    v5->Update(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100062B0
// Name: public: virtual class IDatacenterCmdBatch __near * CDatacenter::CreateCmdBatch(void)
// Source: json
//------------------------------------------------------------------------------
CDatacenterCmdBatchImpl *__thiscall CDatacenter::CreateCmdBatch(CDatacenter *this)
{
  CDatacenterCmdBatchImpl *v2; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDatacenterCmdBatchImpl **m_pMemory; // ecx
  int v6; // eax
  CDatacenterCmdBatchImpl **v7; // eax
  CDatacenterCmdBatchImpl *pBatch; // [esp+Ch] [ebp-4h]

  v2 = (CDatacenterCmdBatchImpl *)operator new(nSize: 0x28u);
  if ( v2 != nullptr )
  {
    v2->__vftable = (CDatacenterCmdBatchImpl_vtbl *)&CDatacenterCmdBatchImpl::`vftable';
    v2->m_pParent = this;
    v2->m_arrCommands.m_Memory.m_pMemory = nullptr;
    v2->m_arrCommands.m_Memory.m_nAllocationCount = 0;
    v2->m_arrCommands.m_Memory.m_nGrowSize = 0;
    v2->m_arrCommands.m_Size = 0;
    v2->m_arrCommands.m_pElements = nullptr;
    v2->m_numRetriesAllowedPerCmd = 0;
    v2->m_flRetryCmdTimeout = 0.0;
    v2->m_bDestroyWhenFinished = true;
    pBatch = v2;
  }
  else
  {
    pBatch = nullptr;
  }
  m_Size = this->m_arrCmdBatchObjects.m_Size;
  m_nAllocationCount = this->m_arrCmdBatchObjects.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_arrCmdBatchObjects,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_arrCmdBatchObjects.m_Size;
  m_pMemory = this->m_arrCmdBatchObjects.m_Memory.m_pMemory;
  v6 = this->m_arrCmdBatchObjects.m_Size - m_Size - 1;
  this->m_arrCmdBatchObjects.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_arrCmdBatchObjects.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pBatch;
  return pBatch;
}

//------------------------------------------------------------------------------
// Address: 0x10006360
// Name: public: virtual void CDatacenterCmdBatchImpl::Destroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDatacenterCmdBatchImpl::Destroy(CDatacenterCmdBatchImpl *this)
{
  CDatacenter *m_pParent; // eax
  int i; // edi
  KeyValues **m_pMemory; // eax
  CDatacenterCmdBatchImpl *src; // [esp+8h] [ebp-4h] BYREF

  m_pParent = this->m_pParent;
  if ( m_pParent != nullptr )
  {
    src = this;
    CUtlVector<CDatacenterCmdBatchImpl *,CUtlMemory<CDatacenterCmdBatchImpl *,int>>::FindAndRemove(
      this: &m_pParent->m_arrCmdBatchObjects,
      &src);
  }
  for ( i = 0; i < this->m_arrCommands.m_Size; ++i )
    KeyValues::deleteThis(this: this->m_arrCommands.m_Memory.m_pMemory[i]);
  this->m_arrCommands.m_Size = 0;
  if ( this->m_arrCommands.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_arrCommands.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_arrCommands.m_Memory.m_pMemory);
      this->m_arrCommands.m_Memory.m_pMemory = nullptr;
    }
    this->m_arrCommands.m_Memory.m_nAllocationCount = 0;
  }
  this->m_arrCommands.m_pElements = this->m_arrCommands.m_Memory.m_pMemory;
  this->m_arrCommands.m_Size = 0;
  if ( this->m_arrCommands.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_arrCommands.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_arrCommands.m_Memory.m_pMemory);
      this->m_arrCommands.m_Memory.m_pMemory = nullptr;
    }
    this->m_arrCommands.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_arrCommands.m_Memory.m_pMemory;
  this->m_arrCommands.m_pElements = m_pMemory;
  if ( this->m_arrCommands.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_arrCommands.m_Memory.m_pMemory = nullptr;
    }
    this->m_arrCommands.m_Memory.m_nAllocationCount = 0;
  }
  free(pMem: this);
}

} // namespace matchmaking_ds
