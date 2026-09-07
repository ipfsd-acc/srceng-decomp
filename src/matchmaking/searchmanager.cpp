// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/searchmanager.cpp
// Functions: 18
// ============================================================

#include "matchmaking\searchmanager.h"

//------------------------------------------------------------------------------
// Address: 0x10029230
// Name: public: virtual void CSearchManager::EnableResultsUpdate(bool,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSearchManager::EnableResultsUpdate(CSearchManager *this, bool bEnable, KeyValues *pSearchParams)
{
  KeyValues *m_pSettings; // ecx
  KeyValues *v5; // ecx

  if ( bEnable )
  {
    if ( pSearchParams != nullptr )
    {
      m_pSettings = this->m_pSettings;
      if ( m_pSettings != nullptr )
        KeyValues::deleteThis(this: m_pSettings);
      this->m_pSettings = KeyValues::MakeCopy(this: pSearchParams);
    }
  }
  else
  {
    v5 = this->m_pSettings;
    if ( v5 != nullptr )
      KeyValues::deleteThis(this: v5);
  }
  if ( this->m_eState == STATE_SEARCHING )
  {
    this->m_eState = STATE_SEARCHING_CRITERIA_UPDATED;
  }
  else if ( this->m_eState == STATE_PAUSED )
  {
    this->m_eState = STATE_IDLE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029290
// Name: public: virtual void CSearchManager::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSearchManager::Destroy(CSearchManager *this)
{
  CMatchSearcher *m_pSearcher; // ecx

  m_pSearcher = this->m_pSearcher;
  if ( m_pSearcher != nullptr )
    m_pSearcher->Destroy(this: m_pSearcher);
  this->m_pSearcher = nullptr;
  ((void (__thiscall *)(CSearchManager *, int))this->dtr_CSearchManager)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100292C0
// Name: public: virtual void CMatchSearcher_SearchMgr::StartSearchPass(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSearcher_SearchMgr::StartSearchPass(CMatchSearcher_SearchMgr *this, KeyValues *pSearchPass)
{
  CMatchSearcher::StartSearchPass(this, pSearchPass);
}

//------------------------------------------------------------------------------
// Address: 0x100292D0
// Name: public: virtual void CMatchSearcher_SearchMgr::OnSearchEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSearcher_SearchMgr::OnSearchEvent(CMatchSearcher_SearchMgr *this, KeyValues *pNotify)
{
  KeyValues::deleteThis(this: pNotify);
}

//------------------------------------------------------------------------------
// Address: 0x100292F0
// Name: public: virtual void CMatchSearchResultItem::Join(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSearchResultItem::Join(CMatchSearchResultItem *this)
{
  KeyValues *m_pDetails; // esi

  m_pDetails = this->m_pDetails;
  if ( m_pDetails != nullptr )
  {
    this->m_pDetails = nullptr;
    g_pMatchFramework->MatchSession(this: g_pMatchFramework, a2: m_pDetails);
    KeyValues::deleteThis(this: m_pDetails);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029320
// Name: public: virtual int CSearchManager::GetNumResults(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSearchManager::GetNumResults(CSearchManager *this)
{
  return this->m_arrResults.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100293C0
// Name: public: virtual class IMatchSearchResult __near * CSearchManager::GetResultByIndex(int)
// Source: json
//------------------------------------------------------------------------------
IMatchSearchResult *__thiscall CSearchManager::GetResultByIndex(CSearchManager *this, int iResultIdx)
{
  if ( iResultIdx < 0 || iResultIdx >= this->m_arrResults.m_Size )
    return nullptr;
  else
    return this->m_arrResults.m_Memory.m_pMemory[iResultIdx];
}

//------------------------------------------------------------------------------
// Address: 0x100293E0
// Name: protected: class IMatchSearchResult __near * CSearchManager::GetResultById(class CUtlVector<class IMatchSearchResult __near *,class CUtlMemory<class IMatchSearchResult __near *,int>> __near &,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
CServer *__thiscall CSearchManager::GetResultById(
        CServerManager *this,
        CUtlVector<CServer *,CUtlMemory<CServer *,int> > *arr,
        unsigned __int64 xuidServerOnline)
{
  int v3; // edi
  CServer *v4; // esi
  __int64 v5; // rax

  v3 = 0;
  if ( arr->m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = arr->m_Memory.m_pMemory[v3];
    if ( v4 != nullptr )
    {
      LODWORD(v5) = v4->GetOnlineId(this: arr->m_Memory.m_pMemory[v3]);
      if ( v5 == xuidServerOnline )
        break;
    }
    if ( ++v3 >= arr->m_Size )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10029430
// Name: public: CMatchSearcher_SearchMgr::CMatchSearcher_SearchMgr(class CSearchManager __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CMatchSearcher_SearchMgr *__thiscall CMatchSearcher_SearchMgr::CMatchSearcher_SearchMgr(
        CMatchSearcher_SearchMgr *this,
        CSearchManager *pMgr,
        KeyValues *pSettings)
{
  IMatchTitleGameSettingsMgr *v4; // eax
  KeyValues *m_pSettings; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  IMatchEventsSubscription *v8; // eax
  IKeyValuesDumpContext pDump; // [esp+8h] [ebp-8h] BYREF
  int v11; // [esp+Ch] [ebp-4h]

  CMatchSearcher::CMatchSearcher(this, pSettings);
  this->__vftable = (CMatchSearcher_SearchMgr_vtbl *)&CMatchSearcher_SearchMgr::`vftable';
  this->m_pMgr = pMgr;
  v4 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
  v4->InitializeGameSettings(this: v4, a2: this->m_pSettings, a3: "search_rollup");
  DevMsg(a1: "CMatchSearcher_SearchMgr title adjusted settings:\n");
  m_pSettings = this->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v11 = 1;
  KeyValues::Dump(this: m_pSettings, &pDump, nIndentLevel: 1);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(
           this: v6,
           setName: "OnMatchSearchMgrUpdate",
           firstKey: "update",
           firstValue: "searchstarted");
  else
    v7 = nullptr;
  KeyValues::SetPtr(this: v7, keyName: "mgr", value: this->m_pMgr);
  v8 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v8->BroadcastEvent(this: v8, a2: v7);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10029530
// Name: protected: void CSearchManager::ClearResults(class CUtlVector<class IMatchSearchResult __near *,class CUtlMemory<class IMatchSearchResult __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSearchManager::ClearResults(
        CSearchManager *this,
        CUtlVector<IMatchSearchResult *,CUtlMemory<IMatchSearchResult *,int> > *arr)
{
  int v2; // edi
  IMatchSearchResult *v3; // esi
  KeyValues *v4; // ecx

  v2 = 0;
  if ( arr->m_Size <= 0 )
  {
    arr->m_Size = 0;
  }
  else
  {
    do
    {
      v3 = arr->m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v4 = (KeyValues *)v3[4].__vftable;
        v3->__vftable = (IMatchSearchResult_vtbl *)&CMatchSearchResultItem::`vftable';
        if ( v4 != nullptr )
          KeyValues::deleteThis(this: v4);
        v3[4].__vftable = nullptr;
        free(pMem: v3);
      }
      ++v2;
    }
    while ( v2 < arr->m_Size );
    arr->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029590
// Name: public: virtual class IMatchSearchResult __near * CSearchManager::GetResultByOnlineId(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
CServer *__thiscall CSearchManager::GetResultByOnlineId(CSearchManager *this, unsigned __int64 xuidResultOnline)
{
  return CSearchManager::GetResultById(
           (CServerManager *)this,
           arr: (CUtlVector<CServer *,CUtlMemory<CServer *,int> > *)&this->m_arrResults,
           xuidServerOnline: xuidResultOnline);
}

//------------------------------------------------------------------------------
// Address: 0x100295B0
// Name: public: void CSearchManager::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSearchManager::Update(CSearchManager *this)
{
  CMatchSearcher *m_pSearcher; // ecx
  CMatchSearcher_SearchMgr *v3; // edi
  KeyValues *Copy; // eax

  switch ( this->m_eState )
  {
    case STATE_IDLE:
      if ( this->m_pSettings != nullptr )
      {
        m_pSearcher = this->m_pSearcher;
        this->m_eState = STATE_SEARCHING;
        if ( m_pSearcher != nullptr )
          m_pSearcher->Destroy(this: m_pSearcher);
        v3 = (CMatchSearcher_SearchMgr *)operator new(nSize: 0x70u);
        if ( v3 != nullptr )
        {
          Copy = KeyValues::MakeCopy(this: this->m_pSettings);
          this->m_pSearcher = CMatchSearcher_SearchMgr::CMatchSearcher_SearchMgr(this: v3, pMgr: this, pSettings: Copy);
        }
        else
        {
          this->m_pSearcher = nullptr;
        }
      }
      break;
    case STATE_SEARCHING:
    case STATE_SEARCHING_CRITERIA_UPDATED:
      this->m_pSearcher->Update(this: this->m_pSearcher);
      break;
    case STATE_PAUSED:
      if ( _Plat_FloatTime() > this->m_flNextSearchTime && !IsLocalClientConnectedToServer() )
        this->m_eState = STATE_IDLE;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100296C0
// Name: public: static void CSearchManager::UpdateAll(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CSearchManager::UpdateAll()
{
  int v0; // esi
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax
  CSearchManager *v2; // edi

  if ( (_S1_5 & 1) == 0 )
  {
    _S1_5 |= 1u;
    stru_10083464.m_pMemory = nullptr;
    stru_10083464.m_nAllocationCount = 0;
    stru_10083464.m_nGrowSize = 0;
    dword_10083470 = 0;
    dword_10083474 = 0;
    atexit(func: GetSearchManagerPool_::_2_::_dynamic_atexit_destructor_for__s_smp__);
  }
  v0 = 0;
  if ( dword_10083470 > 0 )
  {
    m_pMemory = stru_10083464.m_pMemory;
    do
    {
      v2 = (CSearchManager *)m_pMemory[v0];
      CSearchManager::Update(this: v2);
      m_pMemory = stru_10083464.m_pMemory;
      if ( v0 >= 0 )
      {
        if ( v0 >= dword_10083470 )
          return;
        if ( (CSearchManager *)stru_10083464.m_pMemory[v0] == v2 )
          ++v0;
      }
    }
    while ( v0 < dword_10083470 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029740
// Name: public: CSearchManager::CSearchManager(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CSearchManager *__thiscall CSearchManager::CSearchManager(CSearchManager *this, KeyValues *pSearchParams)
{
  KeyValues *Copy; // eax
  bool v4; // zf
  int v5; // eax
  int v6; // ebx
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v8; // eax
  CSearchManager **v9; // eax
  KeyValues *m_pSettings; // ecx
  IKeyValuesDumpContext pDump; // [esp+8h] [ebp-8h] BYREF
  int v13; // [esp+Ch] [ebp-4h]

  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  this->ISearchManager::__vftable = (CSearchManager_vtbl *)&CSearchManager::`vftable'{for `ISearchManager'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CSearchManager::`vftable'{for `IMatchEventsSink'};
  if ( pSearchParams != nullptr )
    Copy = KeyValues::MakeCopy(this: pSearchParams);
  else
    Copy = nullptr;
  v4 = (_S1_5 & 1) == 0;
  this->m_pSettings = Copy;
  this->m_pSearcher = nullptr;
  this->m_arrResults.m_Memory.m_pMemory = nullptr;
  this->m_arrResults.m_Memory.m_nAllocationCount = 0;
  this->m_arrResults.m_Memory.m_nGrowSize = 0;
  this->m_arrResults.m_Size = 0;
  this->m_arrResults.m_pElements = nullptr;
  this->m_eState = STATE_IDLE;
  if ( v4 )
  {
    _S1_5 |= 1u;
    stru_10083464.m_pMemory = nullptr;
    stru_10083464.m_nAllocationCount = 0;
    stru_10083464.m_nGrowSize = 0;
    dword_10083470 = 0;
    dword_10083474 = 0;
    atexit(func: GetSearchManagerPool_::_2_::_dynamic_atexit_destructor_for__s_smp__);
  }
  v5 = dword_10083470;
  v6 = dword_10083470;
  if ( dword_10083470 + 1 > stru_10083464.m_nAllocationCount )
  {
    CUtlMemory<GCSDK::CLock *,int>::Grow(
      this: &stru_10083464,
      num: dword_10083470 - stru_10083464.m_nAllocationCount + 1);
    v5 = dword_10083470;
  }
  m_pMemory = stru_10083464.m_pMemory;
  dword_10083470 = v5 + 1;
  v8 = v5 - v6;
  dword_10083474 = (int)stru_10083464.m_pMemory;
  if ( v8 > 0 )
  {
    _V_memmove(dest: &stru_10083464.m_pMemory[v6 + 1], src: &stru_10083464.m_pMemory[v6], count: 4 * v8);
    m_pMemory = stru_10083464.m_pMemory;
  }
  v9 = (CSearchManager **)&m_pMemory[v6];
  if ( v9 != nullptr )
    *v9 = this;
  DevMsg(a1: "Created CSearchManager(%p):\n", this);
  m_pSettings = this->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v13 = 1;
  KeyValues::Dump(this: m_pSettings, &pDump, nIndentLevel: 1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10029860
// Name: public: virtual CSearchManager::~CSearchManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSearchManager::~CSearchManager(CSearchManager *this)
{
  bool v2; // zf
  KeyValues *m_pSettings; // ecx
  CMatchSearcher *m_pSearcher; // ecx
  KeyValues *v5; // ecx
  IKeyValuesDumpContext pDump; // [esp+8h] [ebp-8h] BYREF
  GCSDK::CLock *src; // [esp+Ch] [ebp-4h] BYREF

  v2 = (_S1_5 & 1) == 0;
  this->ISearchManager::__vftable = (CSearchManager_vtbl *)&CSearchManager::`vftable'{for `ISearchManager'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CSearchManager::`vftable'{for `IMatchEventsSink'};
  src = (GCSDK::CLock *)this;
  if ( v2 )
  {
    _S1_5 |= 1u;
    stru_10083464.m_pMemory = nullptr;
    stru_10083464.m_nAllocationCount = 0;
    stru_10083464.m_nGrowSize = 0;
    dword_10083470 = 0;
    dword_10083474 = 0;
    atexit(func: GetSearchManagerPool_::_2_::_dynamic_atexit_destructor_for__s_smp__);
  }
  CUtlVector<GCSDK::CLock *,CUtlMemory<GCSDK::CLock *,int>>::FindAndRemove(
    this: (CUtlVector<GCSDK::CLock *,CUtlMemory<GCSDK::CLock *,int> > *)&stru_10083464,
    &src);
  DevMsg(a1: "Destroying CSearchManager(%p):\n", this);
  m_pSettings = this->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  src = (GCSDK::CLock *)1;
  KeyValues::Dump(this: m_pSettings, &pDump, nIndentLevel: 1);
  m_pSearcher = this->m_pSearcher;
  if ( m_pSearcher != nullptr )
    m_pSearcher->Destroy(this: m_pSearcher);
  v5 = this->m_pSettings;
  this->m_pSearcher = nullptr;
  if ( v5 != nullptr )
    KeyValues::deleteThis(this: v5);
  this->m_pSettings = nullptr;
  CSearchManager::ClearResults(this, arr: &this->m_arrResults);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_arrResults);
}

//------------------------------------------------------------------------------
// Address: 0x10029930
// Name: public: void CSearchManager::OnSearchDone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSearchManager::OnSearchDone(CSearchManager *this)
{
  IMatchSearchResult *v2; // esi
  IMatchTitleGameSettingsMgr *v3; // eax
  CMatchSearcher *m_pSearcher; // ecx
  CMatchSearcher_vtbl *v5; // edx
  int (__thiscall *GetNumSearchResults)(CMatchSearcher *); // eax
  int m_Size; // edi
  CMatchSearcher::SearchResult_t *v8; // eax
  IMatchTitleGameSettingsMgr_vtbl *v9; // esi
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  unsigned __int64 Uint64; // rax
  CServer *ResultById; // esi
  int v15; // eax
  KeyValues *v16; // ecx
  int v17; // ecx
  IMatchSearchResult **m_pMemory; // edx
  int v19; // edi
  CServer **v20; // ecx
  IMatchTitleGameSettingsMgr_vtbl *v21; // edi
  KeyValues *v22; // eax
  int v23; // eax
  bool v24; // cc
  __int64 (*GetOnlineId)(void); // eax
  int v26; // esi
  IMatchSearchResult *v27; // ecx
  __int64 v28; // rax
  IMatchTitleGameSettingsMgr_vtbl *v29; // esi
  KeyValues *v30; // eax
  int v31; // eax
  int v32; // esi
  IMatchSearchResult **v33; // ecx
  float *v34; // esi
  int v35; // ecx
  int m_nGrowSize; // eax
  IMatchSearchResult **v37; // ecx
  IMatchSearchResult **v38; // edx
  IMatchSearchResult **m_pElements; // ecx
  CUtlVector<IMatchSearchResult *,CUtlMemory<IMatchSearchResult *,int> > arrResults; // [esp+Ch] [ebp-34h] BYREF
  unsigned __int64 uidKey; // [esp+20h] [ebp-20h]
  int kNum; // [esp+28h] [ebp-18h]
  IMatchSearchResult *pOldResult; // [esp+2Ch] [ebp-14h]
  KeyValues *pRollupKey; // [esp+30h] [ebp-10h]
  KeyValues *pDetails; // [esp+34h] [ebp-Ch]
  int v46; // [esp+38h] [ebp-8h]
  IMatchTitleGameSettingsMgr *mgr; // [esp+3Ch] [ebp-4h]

  if ( this->m_eState == STATE_SEARCHING_CRITERIA_UPDATED )
  {
    v2 = nullptr;
    this->m_eState = STATE_IDLE;
  }
  else
  {
    this->m_eState = STATE_PAUSED;
    pOldResult = (IMatchSearchResult *)LODWORD(mm_match_search_update_interval.m_pParent->m_Value.m_fValue);
    v2 = nullptr;
    this->m_flNextSearchTime = _Plat_FloatTime() + *(float *)&pOldResult;
  }
  v3 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
  m_pSearcher = this->m_pSearcher;
  v5 = m_pSearcher->__vftable;
  mgr = v3;
  GetNumSearchResults = v5->GetNumSearchResults;
  m_Size = 0;
  memset(&arrResults, 0, sizeof(arrResults));
  *(float *)&pOldResult = 0.0;
  kNum = GetNumSearchResults(this: m_pSearcher);
  if ( kNum > 0 )
  {
    do
    {
      v8 = this->m_pSearcher->GetSearchResult(this: this->m_pSearcher, a2: v2);
      pDetails = CMatchSearcher::SearchResult_t::GetGameDetails(this: v8);
      if ( pDetails != nullptr )
      {
        v9 = mgr->__vftable;
        v10 = this->m_pSearcher->GetSearchSettings(this: this->m_pSearcher);
        v11 = v9->RollupGameDetails(this: mgr, a2: pDetails, a3: nullptr, a4: v10);
        v12 = v11;
        pRollupKey = v11;
        if ( v11 != nullptr )
        {
          Uint64 = KeyValues::GetUint64(this: v11, keyName: "rollupkey", defaultValue: 0);
          uidKey = Uint64;
          if ( Uint64 != 0 )
          {
            ResultById = CSearchManager::GetResultById(
                           (CServerManager *)this,
                           arr: (CUtlVector<CServer *,CUtlMemory<CServer *,int> > *)&arrResults,
                           xuidServerOnline: Uint64);
            if ( ResultById == nullptr )
            {
              ResultById = (CServer *)operator new(nSize: 0x18u);
              if ( ResultById != nullptr )
              {
                v15 = uidKey;
                HIDWORD(ResultById->m_xuid) = HIDWORD(uidKey);
                v16 = pRollupKey;
                ResultById->__vftable = (CServer_vtbl *)&CMatchSearchResultItem::`vftable';
                LODWORD(ResultById->m_xuid) = v15;
                ResultById->m_pGameDetails = KeyValues::MakeCopy(this: v16);
              }
              else
              {
                ResultById = nullptr;
              }
              v17 = m_Size;
              v46 = m_Size;
              if ( m_Size + 1 > arrResults.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<GCSDK::CLock *,int>::Grow(
                  this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&arrResults,
                  num: m_Size - arrResults.m_Memory.m_nAllocationCount + 1);
                m_Size = arrResults.m_Size;
                v17 = v46;
              }
              m_pMemory = arrResults.m_Memory.m_pMemory;
              v19 = m_Size + 1;
              arrResults.m_Size = v19;
              arrResults.m_pElements = arrResults.m_Memory.m_pMemory;
              if ( v19 - v17 - 1 > 0 )
              {
                _V_memmove(
                  dest: &arrResults.m_Memory.m_pMemory[v17 + 1],
                  src: &arrResults.m_Memory.m_pMemory[v17],
                  count: 4 * (v19 - v17 - 1));
                m_pMemory = arrResults.m_Memory.m_pMemory;
                v17 = v46;
              }
              v20 = (CServer **)&m_pMemory[v17];
              if ( v20 != nullptr )
                *v20 = ResultById;
            }
            v21 = mgr->__vftable;
            v22 = this->m_pSearcher->GetSearchSettings(this: this->m_pSearcher);
            v23 = ((int (__thiscall *)(CServer *, KeyValues *))ResultById->GetGameDetails)(a1: ResultById, a2: v22);
            ((void (__thiscall *)(IMatchTitleGameSettingsMgr *, KeyValues *, int))v21->RollupGameDetails)(
              a1: mgr,
              a2: pDetails,
              a3: v23);
            KeyValues::deleteThis(this: pRollupKey);
            m_Size = arrResults.m_Size;
          }
          else
          {
            KeyValues::deleteThis(this: v12);
          }
        }
      }
      v2 = (IMatchSearchResult *)((char *)&pOldResult->__vftable + 1);
      pOldResult = v2;
    }
    while ( (int)v2 < kNum );
  }
  v24 = this->m_arrResults.m_Size <= 0;
  v46 = 0;
  if ( !v24 )
  {
    do
    {
      GetOnlineId = (__int64 (*)(void))this->m_arrResults.m_Memory.m_pMemory[v46]->GetOnlineId;
      pOldResult = this->m_arrResults.m_Memory.m_pMemory[v46];
      v26 = 0;
      uidKey = GetOnlineId();
      if ( m_Size <= 0 )
      {
LABEL_26:
        v29 = mgr->__vftable;
        v30 = this->m_pSearcher->GetSearchSettings(this: this->m_pSearcher);
        v31 = ((int (__thiscall *)(IMatchSearchResult *, KeyValues *))pOldResult->GetGameDetails)(
                a1: pOldResult,
                a2: v30);
        if ( ((int (__thiscall *)(IMatchTitleGameSettingsMgr *, _DWORD, int))v29->RollupGameDetails)(
               a1: mgr,
               a2: 0,
               a3: v31) != 0 )
        {
          v32 = m_Size;
          if ( m_Size + 1 > arrResults.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<GCSDK::CLock *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&arrResults,
              num: m_Size - arrResults.m_Memory.m_nAllocationCount + 1);
            m_Size = arrResults.m_Size;
          }
          v33 = arrResults.m_Memory.m_pMemory;
          arrResults.m_Size = ++m_Size;
          arrResults.m_pElements = arrResults.m_Memory.m_pMemory;
          if ( m_Size - v32 - 1 > 0 )
          {
            _V_memmove(
              dest: &arrResults.m_Memory.m_pMemory[v32 + 1],
              src: &arrResults.m_Memory.m_pMemory[v32],
              count: 4 * (m_Size - v32 - 1));
            v33 = arrResults.m_Memory.m_pMemory;
          }
          v34 = (float *)&v33[v32];
          if ( v34 != nullptr )
            *v34 = *(float *)&pOldResult;
          v35 = this->m_arrResults.m_Size;
          if ( v35 > 0 )
          {
            if ( v46 != v35 - 1 )
              this->m_arrResults.m_Memory.m_pMemory[v46] = this->m_arrResults.m_Memory.m_pMemory[v35 - 1];
            --this->m_arrResults.m_Size;
          }
          --v46;
        }
      }
      else
      {
        while ( 1 )
        {
          v27 = arrResults.m_Memory.m_pMemory[v26];
          if ( v27 != nullptr )
          {
            LODWORD(v28) = v27->GetOnlineId(this: v27);
            if ( v28 == uidKey )
              break;
          }
          if ( ++v26 >= m_Size )
            goto LABEL_26;
        }
      }
      ++v46;
    }
    while ( v46 < this->m_arrResults.m_Size );
  }
  CSearchManager::ClearResults(this, arr: &this->m_arrResults);
  m_nGrowSize = this->m_arrResults.m_Memory.m_nGrowSize;
  v37 = arrResults.m_Memory.m_pMemory;
  this->m_arrResults.m_Memory.m_nGrowSize = arrResults.m_Memory.m_nGrowSize;
  v38 = this->m_arrResults.m_Memory.m_pMemory;
  this->m_arrResults.m_Memory.m_pMemory = v37;
  this->m_arrResults.m_Memory.m_nAllocationCount = arrResults.m_Memory.m_nAllocationCount;
  m_pElements = arrResults.m_pElements;
  this->m_arrResults.m_Size = m_Size;
  this->m_arrResults.m_pElements = m_pElements;
  if ( m_nGrowSize >= 0 && v38 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v38);
}

//------------------------------------------------------------------------------
// Address: 0x10029C40
// Name: public: virtual void CMatchSearcher_SearchMgr::OnSearchDone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSearcher_SearchMgr::OnSearchDone(CMatchSearcher_SearchMgr *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IMatchEventsSubscription *v4; // eax

  CMatchSearcher::OnSearchDone(this);
  CSearchManager::OnSearchDone(this: this->m_pMgr);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(
           this: v2,
           setName: "OnMatchSearchMgrUpdate",
           firstKey: "update",
           firstValue: "searchfinished");
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "mgr", value: this->m_pMgr);
  v4 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v4->BroadcastEvent(this: v4, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10038120
// Name: public: virtual class KeyValues __near * CMatchSearchResultItem::GetGameDetails(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMatchSearchResultItem::GetGameDetails(ConCommandBase *this)
{
  return this->m_pszHelpString;
}
