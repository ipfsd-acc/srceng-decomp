// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/leaderboards.cpp
// Functions: 9
// ============================================================

#include "matchmaking\leaderboards.h"

//------------------------------------------------------------------------------
// Address: 0x1001BAA0
// Name: protected: void CLeaderboardRequestQueue::OnQueryFinished(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLeaderboardRequestQueue::OnQueryFinished(CLeaderboardRequestQueue *this)
{
  KeyValues *m_pFinishedRequest; // ecx
  IPlayerLocal *v3; // eax
  __int64 v4; // rax
  CFmtStrN<256> *v5; // eax
  KeyValues *Key; // esi
  PlayerLocal *v7; // eax
  CFmtStrN<256> v8; // [esp+4h] [ebp-114h] BYREF
  IKeyValuesDumpContext pDump; // [esp+110h] [ebp-8h] BYREF
  int v10; // [esp+114h] [ebp-4h]

  this->m_bQueryRunning = false;
  DevMsg(a1: "CLeaderboardRequestQueue::OnQueryFinished\n");
  m_pFinishedRequest = this->m_pFinishedRequest;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v10 = 1;
  KeyValues::Dump(this: m_pFinishedRequest, &pDump, nIndentLevel: 1);
  v3 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
  v4 = v3->GetXUID(this: v3);
  if ( v4 != 0 )
  {
    v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v8, pszFormat: "%llx", v4);
    Key = KeyValues::FindKey(this: this->m_pFinishedRequest, keyName: v5->m_szBuf, bCreate: false);
    if ( Key != nullptr )
    {
      v7 = (PlayerLocal *)g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
      if ( v7 != nullptr )
        PlayerLocal::OnLeaderboardRequestFinished(this: v7, pLeaderboardData: Key);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BB50
// Name: protected: void CLeaderboardRequestQueue::ProcessResults(struct LeaderboardEntry_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLeaderboardRequestQueue::ProcessResults(CLeaderboardRequestQueue *this, const LeaderboardEntry_t *lbe)
{
  KeyValues *m_pViewDescription; // ecx
  const char *String; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  IPlayerLocal *v7; // eax
  __int64 v8; // rax
  CFmtStrN<256> *v9; // eax
  KeyValues *Key; // esi
  const char *v11; // eax
  unsigned __int64 m_nScore; // [esp-10h] [ebp-124h]
  const char *v13; // [esp-Ch] [ebp-120h]
  CFmtStrN<256> v14; // [esp+4h] [ebp-110h] BYREF
  KeyValues *pViewDesc; // [esp+110h] [ebp-4h]

  m_pViewDescription = this->m_pViewDescription;
  pViewDesc = m_pViewDescription;
  if ( m_pViewDescription != nullptr )
  {
    String = KeyValues::GetString(this: m_pViewDescription, keyName: ":name", defaultValue: defaultValue);
    DevMsg(a1: "    Processing view %s\n", String);
    DevMsg(a1: "        Gamer data loaded: rank=%d, score=%d\n", lbe->m_nGlobalRank, lbe->m_nScore);
    if ( this->m_pFinishedRequest == nullptr )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "Leaderboard");
      else
        v6 = nullptr;
      this->m_pFinishedRequest = v6;
    }
    v7 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
    v8 = ((__int64 (__thiscall *)(IPlayerLocal *, const char *))v7->GetXUID)(a1: v7, a2: String);
    v9 = CFmtStrN<256>::CFmtStrN<256>(this: &v14, pszFormat: "%llx/%s", v8, v13);
    Key = KeyValues::FindKey(this: this->m_pFinishedRequest, keyName: v9->m_szBuf, bCreate: true);
    m_nScore = lbe->m_nScore;
    v11 = KeyValues::GetString(this: pViewDesc, keyName: ":score", defaultValue: defaultValue);
    KeyValues::SetUint64(this: Key, keyName: v11, value: m_nScore);
    DevMsg(a1: "LeaderboardRequestQueue: ProcessResults finished.\n");
  }
  else
  {
    _Warning(a1: "LeaderboardRequestQueue: ProcessResults has no view description for view!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BC50
// Name: protected: void CLeaderboardRequestQueue::Steam_OnLeaderboardScoresDownloaded(struct LeaderboardScoresDownloaded_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLeaderboardRequestQueue::Steam_OnLeaderboardScoresDownloaded(
        CLeaderboardRequestQueue *this,
        LeaderboardScoresDownloaded_t *p,
        bool bError)
{
  LeaderboardEntry_t lbe; // [esp+4h] [ebp-20h] BYREF

  lbe.m_steamIDUser.m_steamid.m_unAll64Bits = 0;
  if ( !bError
    && p->m_cEntryCount == 1
    && ((unsigned __int8 (__thiscall *)(ISteamUserStats *, _DWORD, _DWORD, _DWORD, LeaderboardEntry_t *, _DWORD, _DWORD))steamapicontext->m_pSteamUserStats->GetDownloadedLeaderboardEntry)(
         a1: steamapicontext->m_pSteamUserStats,
         a2: p->m_hSteamLeaderboardEntries,
         a3: HIDWORD(p->m_hSteamLeaderboardEntries),
         a4: 0,
         a5: &lbe,
         a6: 0,
         a7: 0) != 0 )
  {
    CLeaderboardRequestQueue::ProcessResults(this, &lbe);
  }
  CLeaderboardRequestQueue::OnQueryFinished(this);
}

//------------------------------------------------------------------------------
// Address: 0x1001BCB0
// Name: protected: void CLeaderboardRequestQueue::Steam_OnLeaderboardFindResult(struct LeaderboardFindResult_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLeaderboardRequestQueue::Steam_OnLeaderboardFindResult(
        CLeaderboardRequestQueue *this,
        LeaderboardFindResult_t *p,
        bool bError)
{
  __int64 v4; // rax
  int m_hAPICall_high; // ecx
  CCallResult<CLeaderboardRequestQueue,LeaderboardScoresDownloaded_t> *p_m_CallbackOnLeaderboardScoresDownloaded; // esi
  unsigned __int64 v7; // kr00_8

  if ( bError || p->m_bLeaderboardFound == 0 )
  {
    DevMsg(a1: "Steam leaderboard was not found.\n");
    CLeaderboardRequestQueue::OnQueryFinished(this);
  }
  else
  {
    v4 = ((__int64 (__thiscall *)(ISteamUserStats *, _DWORD, _DWORD, int, _DWORD, _DWORD))steamapicontext->m_pSteamUserStats->DownloadLeaderboardEntries)(
           a1: steamapicontext->m_pSteamUserStats,
           a2: p->m_hSteamLeaderboard,
           a3: HIDWORD(p->m_hSteamLeaderboard),
           a4: 1,
           a5: 0,
           a6: 0);
    m_hAPICall_high = HIDWORD(this->m_CallbackOnLeaderboardScoresDownloaded.m_hAPICall);
    p_m_CallbackOnLeaderboardScoresDownloaded = &this->m_CallbackOnLeaderboardScoresDownloaded;
    v7 = v4;
    if ( (m_hAPICall_high | LODWORD(p_m_CallbackOnLeaderboardScoresDownloaded->m_hAPICall)) != 0 )
      _SteamAPI_UnregisterCallResult(
        a1: p_m_CallbackOnLeaderboardScoresDownloaded,
        a2: p_m_CallbackOnLeaderboardScoresDownloaded->m_hAPICall,
        a3: m_hAPICall_high);
    p_m_CallbackOnLeaderboardScoresDownloaded->m_hAPICall = v7;
    p_m_CallbackOnLeaderboardScoresDownloaded->m_pObj = this;
    p_m_CallbackOnLeaderboardScoresDownloaded->m_Func = CLeaderboardRequestQueue::Steam_OnLeaderboardScoresDownloaded;
    if ( v7 != 0 )
      _SteamAPI_RegisterCallResult(a1: p_m_CallbackOnLeaderboardScoresDownloaded, a2: v7, a3: HIDWORD(v7));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BD60
// Name: protected: void CLeaderboardRequestQueue::Cleanup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLeaderboardRequestQueue::Cleanup(CLeaderboardRequestQueue *this)
{
  KeyValues *m_pViewDescription; // ecx
  int m_Size; // eax
  KeyValues *m_pFinishedRequest; // ecx

  m_pViewDescription = this->m_pViewDescription;
  if ( m_pViewDescription != nullptr )
    KeyValues::deleteThis(this: m_pViewDescription);
  this->m_pViewDescription = nullptr;
  while ( this->m_arrRequests.m_Size != 0 )
  {
    KeyValues::deleteThis(this: *this->m_arrRequests.m_Memory.m_pMemory);
    m_Size = this->m_arrRequests.m_Size;
    if ( m_Size > 0 )
    {
      if ( m_Size != 1 )
        *this->m_arrRequests.m_Memory.m_pMemory = this->m_arrRequests.m_Memory.m_pMemory[m_Size - 1];
      --this->m_arrRequests.m_Size;
    }
  }
  this->m_arrRequests.m_Size = 0;
  if ( this->m_arrRequests.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_arrRequests.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_arrRequests.m_Memory.m_pMemory);
      this->m_arrRequests.m_Memory.m_pMemory = nullptr;
    }
    this->m_arrRequests.m_Memory.m_nAllocationCount = 0;
  }
  this->m_arrRequests.m_pElements = this->m_arrRequests.m_Memory.m_pMemory;
  m_pFinishedRequest = this->m_pFinishedRequest;
  if ( m_pFinishedRequest != nullptr )
    KeyValues::deleteThis(this: m_pFinishedRequest);
  this->m_pFinishedRequest = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001BDF0
// Name: protected: void CLeaderboardRequestQueue::OnStartNewQuery(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLeaderboardRequestQueue::OnStartNewQuery(CLeaderboardRequestQueue *this)
{
  KeyValues *m_pFinishedRequest; // ecx
  KeyValues *m_pViewDescription; // ecx
  KeyValues *v4; // edi
  int v5; // eax
  const char *Name; // edi
  IMatchTitle *v7; // eax
  KeyValues *v8; // eax
  unsigned __int64 v9; // kr00_8
  KeyValues *pRequest; // [esp+10h] [ebp-4h]

  m_pFinishedRequest = this->m_pFinishedRequest;
  if ( m_pFinishedRequest != nullptr )
    KeyValues::deleteThis(this: m_pFinishedRequest);
  this->m_pFinishedRequest = nullptr;
  DevMsg(a1: "CLeaderboardRequestQueue::OnStartNewQuery preparing request...\n");
  m_pViewDescription = this->m_pViewDescription;
  if ( m_pViewDescription != nullptr )
    KeyValues::deleteThis(this: m_pViewDescription);
  this->m_pViewDescription = nullptr;
  if ( this->m_arrRequests.m_Size > 0 )
  {
    while ( 1 )
    {
      v4 = *this->m_arrRequests.m_Memory.m_pMemory;
      v5 = this->m_arrRequests.m_Size - 1;
      pRequest = v4;
      if ( v5 > 0 )
        _V_memmove(
          dest: this->m_arrRequests.m_Memory.m_pMemory,
          src: this->m_arrRequests.m_Memory.m_pMemory + 1,
          count: 4 * v5);
      --this->m_arrRequests.m_Size;
      Name = KeyValues::GetName(this: v4);
      v7 = g_pMMF->GetMatchTitle(this: g_pMMF);
      v8 = v7->DescribeTitleLeaderboard(this: v7, a2: Name);
      this->m_pViewDescription = v8;
      if ( v8 != nullptr )
        break;
      DevWarning(a1: "   View %s failed to allocate description!\n", Name);
      if ( pRequest != nullptr )
        KeyValues::deleteThis(this: pRequest);
      if ( this->m_arrRequests.m_Size <= 0 )
        goto LABEL_19;
    }
    KeyValues::SetString(this: v8, keyName: ":name", value: Name);
    v9 = steamapicontext->m_pSteamUserStats->FindLeaderboard(this: steamapicontext->m_pSteamUserStats, a2: Name);
    if ( this->m_CallbackOnLeaderboardFindResult.m_hAPICall != 0 )
      _SteamAPI_UnregisterCallResult(
        a1: &this->m_CallbackOnLeaderboardFindResult,
        a2: this->m_CallbackOnLeaderboardFindResult.m_hAPICall,
        a3: HIDWORD(this->m_CallbackOnLeaderboardFindResult.m_hAPICall));
    this->m_CallbackOnLeaderboardFindResult.m_hAPICall = v9;
    this->m_CallbackOnLeaderboardFindResult.m_pObj = this;
    this->m_CallbackOnLeaderboardFindResult.m_Func = CLeaderboardRequestQueue::Steam_OnLeaderboardFindResult;
    if ( v9 != 0 )
      _SteamAPI_RegisterCallResult(a1: &this->m_CallbackOnLeaderboardFindResult, a2: v9, a3: HIDWORD(v9));
    this->m_bQueryRunning = true;
    if ( pRequest != nullptr )
      KeyValues::deleteThis(this: pRequest);
  }
LABEL_19:
  DevMsg(a1: "CLeaderboardRequestQueue::OnStartNewQuery - request prepared.\n");
}

//------------------------------------------------------------------------------
// Address: 0x1001BF40
// Name: public: CLeaderboardRequestQueue::~CLeaderboardRequestQueue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLeaderboardRequestQueue::~CLeaderboardRequestQueue(CLeaderboardRequestQueue *this)
{
  int m_hAPICall; // eax
  int m_hAPICall_high; // ecx
  bool v4; // zf
  int v5; // eax
  int v6; // ecx

  this->__vftable = (CLeaderboardRequestQueue_vtbl *)&CLeaderboardRequestQueue::`vftable';
  CLeaderboardRequestQueue::Cleanup(this);
  m_hAPICall = this->m_CallbackOnLeaderboardScoresDownloaded.m_hAPICall;
  m_hAPICall_high = HIDWORD(this->m_CallbackOnLeaderboardScoresDownloaded.m_hAPICall);
  v4 = this->m_CallbackOnLeaderboardScoresDownloaded.m_hAPICall == 0;
  this->m_CallbackOnLeaderboardScoresDownloaded.__vftable = (CCallResult<CLeaderboardRequestQueue,LeaderboardScoresDownloaded_t>_vtbl *)&CCallResult<CLeaderboardRequestQueue,LeaderboardScoresDownloaded_t>::`vftable';
  if ( !v4 )
  {
    _SteamAPI_UnregisterCallResult(
      a1: &this->m_CallbackOnLeaderboardScoresDownloaded,
      a2: m_hAPICall,
      a3: m_hAPICall_high);
    LODWORD(this->m_CallbackOnLeaderboardScoresDownloaded.m_hAPICall) = 0;
    HIDWORD(this->m_CallbackOnLeaderboardScoresDownloaded.m_hAPICall) = 0;
  }
  v5 = this->m_CallbackOnLeaderboardFindResult.m_hAPICall;
  v6 = HIDWORD(this->m_CallbackOnLeaderboardFindResult.m_hAPICall);
  v4 = this->m_CallbackOnLeaderboardFindResult.m_hAPICall == 0;
  this->m_CallbackOnLeaderboardFindResult.__vftable = (CCallResult<CLeaderboardRequestQueue,LeaderboardFindResult_t>_vtbl *)&CCallResult<CLeaderboardRequestQueue,LeaderboardFindResult_t>::`vftable';
  if ( !v4 )
  {
    _SteamAPI_UnregisterCallResult(a1: &this->m_CallbackOnLeaderboardFindResult, a2: v5, a3: v6);
    LODWORD(this->m_CallbackOnLeaderboardFindResult.m_hAPICall) = 0;
    HIDWORD(this->m_CallbackOnLeaderboardFindResult.m_hAPICall) = 0;
  }
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_arrRequests);
}

//------------------------------------------------------------------------------
// Address: 0x1001BFB0
// Name: public: virtual void CLeaderboardRequestQueue::Request(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLeaderboardRequestQueue::Request(CLeaderboardRequestQueue *this, KeyValues *pRequest)
{
  KeyValues *Copy; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_arrRequests; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v8; // eax
  KeyValues **v9; // eax
  IKeyValuesDumpContext pDump; // [esp+8h] [ebp-8h] BYREF
  int v11; // [esp+Ch] [ebp-4h]
  KeyValues *pRequesta; // [esp+18h] [ebp+8h]

  if ( pRequest != nullptr )
  {
    DevMsg(a1: "CLeaderboardRequestQueue::Request\n");
    pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
    v11 = 1;
    KeyValues::Dump(this: pRequest, &pDump, nIndentLevel: 1);
    Copy = KeyValues::MakeCopy(this: pRequest);
    p_m_arrRequests = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_arrRequests;
    m_Size = this->m_arrRequests.m_Size;
    pRequesta = Copy;
    m_nAllocationCount = p_m_arrRequests->m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<GCSDK::CLock *,int>::Grow(this: p_m_arrRequests, num: m_Size - m_nAllocationCount + 1);
    ++p_m_arrRequests[1].m_pMemory;
    m_pMemory = p_m_arrRequests->m_pMemory;
    v8 = (int)p_m_arrRequests[1].m_pMemory - m_Size - 1;
    p_m_arrRequests[1].m_nAllocationCount = (int)p_m_arrRequests->m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = (KeyValues **)&p_m_arrRequests->m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = pRequesta;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001C060
// Name: public: virtual void CLeaderboardRequestQueue::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLeaderboardRequestQueue::Update(CLeaderboardRequestQueue *this)
{
  if ( !this->m_bQueryRunning )
  {
    if ( this->m_arrRequests.m_Size != 0 )
    {
      CLeaderboardRequestQueue::OnStartNewQuery(this);
    }
    else if ( this->m_arrRequests.m_Memory.m_nAllocationCount != 0 )
    {
      CLeaderboardRequestQueue::Cleanup(this);
    }
  }
}
