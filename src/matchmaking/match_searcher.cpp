// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/match_searcher.cpp
// Functions: 14
// ============================================================

#include "matchmaking\match_searcher.h"

//------------------------------------------------------------------------------
// Address: 0x10030530
// Name: public: virtual class KeyValues __near * CMatchSearcher::GetSearchSettings(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatchSearcher::GetSearchSettings(CServerManager *this)
{
  return this->m_Servers.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10030540
// Name: public: virtual void CMatchSearcher::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSearcher::Destroy(CMatchSearcher *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CMatchSearcher *, int))this->dtr_CMatchSearcher)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10030550
// Name: protected: virtual void CMatchSearcher::OnSearchDone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSearcher::OnSearchDone(CMatchSearcher *this)
{
  this->m_eState = STATE_DONE;
}

//------------------------------------------------------------------------------
// Address: 0x10030590
// Name: public: virtual bool CMatchSearcher::IsSearchFinished(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMatchSearcher::IsSearchFinished(CMatchSearcher *this)
{
  return this->m_eState == STATE_DONE;
}

//------------------------------------------------------------------------------
// Address: 0x100305C0
// Name: public: void CUtlMemory<struct CMatchSearcher::SearchResult_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CMatchSearcher::SearchResult_t,int>::Grow(
        CUtlMemory<CMatchSearcher::SearchResult_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CMatchSearcher::SearchResult_t *m_pMemory; // edx
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
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CMatchSearcher::SearchResult_t *)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CMatchSearcher::SearchResult_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030650
// Name: public: virtual void CMatchSearcher::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSearcher::Update(CMatchSearcher *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  IMatchTitleGameSettingsMgr *v4; // eax
  KeyValues *v5; // eax

  if ( this->m_eState == 0 )
  {
    this->m_eState = 1;
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(
             this: v2,
             setName: "OnMatchSessionUpdate",
             firstKey: "state",
             firstValue: "progress",
             secondKey: "progress",
             secondValue: "searching");
    else
      v3 = nullptr;
    this->OnSearchEvent(this, a2: v3);
    v4 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
    v5 = v4->DefineSessionSearchKeys(this: v4, a2: this->m_pSettings);
    this->m_pSessionSearchTree = v5;
    this->m_autodelete_pSessionSearchTree.m_pKeyValues = v5;
    if ( v5 != nullptr )
    {
      this->StartSearchPass(this, a2: v5);
    }
    else
    {
      DevWarning(a1: "OnlineSearch::StartSearch failed to build filter list!\n");
      this->OnSearchDone(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100306F0
// Name: protected: virtual void CMatchSearcher::OnSearchPassDone(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSearcher::OnSearchPassDone(CMatchSearcher *this, KeyValues *pSearchPass)
{
  int m_Size; // ecx
  int m_nValue; // eax
  KeyValues *Key; // eax
  CMatchSearcher_vtbl *v6; // edx

  m_Size = this->m_arrSearchResultsAggregate.m_Size;
  if ( mm_session_search_num_results.m_pParent != nullptr )
    m_nValue = mm_session_search_num_results.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( m_Size < m_nValue )
  {
    KeyValues::FindKey(this: pSearchPass, keyName: "nextpass?", bCreate: false);
    Key = KeyValues::FindKey(this: pSearchPass, keyName: "nextpass", bCreate: false);
    v6 = this->__vftable;
    if ( Key != nullptr )
      v6->StartSearchPass(this, a2: Key);
    else
      v6->OnSearchDone(this);
  }
  else
  {
    this->OnSearchDone(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030760
// Name: public: virtual int CMatchSearcher::GetNumSearchResults(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatchSearcher::GetNumSearchResults(CMatchSearcher *this)
{
  if ( this->IsSearchFinished(this) )
    return this->m_arrSearchResultsAggregate.m_Size;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10030780
// Name: protected: void CMatchSearcher::InitializeSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSearcher::InitializeSettings(CMatchSearcher *this)
{
  KeyValues *Key; // eax
  KeyValues *v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  KeyValues *v6; // esi
  IPlayerLocal *v7; // eax
  unsigned __int64 v8; // rax
  unsigned __int64 MachineFlags; // rax
  IMatchSystem *v10; // eax
  int v11; // eax
  KeyValues *v12; // eax
  unsigned __int64 Uint64; // rax
  char *TuInstalledString; // eax
  CFmtStrN<256> *v15; // eax
  KeyValues *v16; // esi
  IPlayerLocal *v17; // edi
  unsigned __int64 v18; // rax
  const char *v19; // eax
  KeyValues *m_pSettings; // ecx
  CFmtStrN<256> v21; // [esp+8h] [ebp-114h] BYREF
  IKeyValuesDumpContext pDump; // [esp+114h] [ebp-8h] BYREF
  int v23; // [esp+118h] [ebp-4h]

  Key = KeyValues::FindKey(this: this->m_pSettings, keyName: "system", bCreate: true);
  v3 = Key;
  if ( Key != nullptr )
  {
    if ( KeyValues::FindKey(this: Key, keyName: "network", bCreate: false) == nullptr )
      KeyValues::SetString(this: v3, keyName: "network", value: "LIVE");
    if ( KeyValues::FindKey(this: v3, keyName: "access", bCreate: false) == nullptr )
      KeyValues::SetString(this: v3, keyName: "access", value: "public");
  }
  v4 = KeyValues::FindKey(this: this->m_pSettings, keyName: "members", bCreate: true);
  v5 = v4;
  if ( v4 != nullptr )
  {
    KeyValues::SetInt(this: v4, keyName: "numMachines", value: 1);
    KeyValues::SetInt(this: v5, keyName: "numPlayers", value: 1);
    KeyValues::SetInt(this: v5, keyName: "numSlots", value: 1);
    v6 = KeyValues::FindKey(this: v5, keyName: "machine0", bCreate: true);
    if ( v6 != nullptr )
    {
      v7 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
      v8 = v7->GetXUID(this: v7);
      KeyValues::SetUint64(this: v6, keyName: "id", value: v8);
      MachineFlags = MatchSession_GetMachineFlags();
      KeyValues::SetUint64(this: v6, keyName: "flags", value: MachineFlags);
      KeyValues::SetInt(this: v6, keyName: "numPlayers", value: 1);
      v10 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
      v11 = (int)v10->GetDlcManager(this: v10);
      v12 = (KeyValues *)(*(int (__thiscall **)(int))(*(_DWORD *)v11 + 8))(a1: v11);
      Uint64 = KeyValues::GetUint64(this: v12, keyName: "@info/installed", defaultValue: 0);
      KeyValues::SetUint64(this: v6, keyName: "dlcmask", value: Uint64);
      TuInstalledString = MatchSession_GetTuInstalledString();
      KeyValues::SetString(this: v6, keyName: "tuver", value: TuInstalledString);
      KeyValues::SetInt(this: v6, keyName: "ping", value: 0);
      v15 = CFmtStrN<256>::CFmtStrN<256>(this: &v21, pszFormat: "player%d", 0);
      v16 = KeyValues::FindKey(this: v6, keyName: v15->m_szBuf, bCreate: true);
      if ( v16 != nullptr )
      {
        v17 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
        v18 = v17->GetXUID(this: v17);
        KeyValues::SetUint64(this: v16, keyName: "xuid", value: v18);
        v19 = v17->GetName(this: v17);
        KeyValues::SetString(this: v16, keyName: "name", value: v19);
      }
    }
  }
  DevMsg(a1: "CMatchSearcher::InitializeGameSettings adjusted settings:\n");
  m_pSettings = this->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v23 = 1;
  KeyValues::Dump(this: m_pSettings, &pDump, nIndentLevel: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10030980
// Name: public: virtual struct CMatchSearcher::SearchResult_t const __near & CMatchSearcher::GetSearchResult(int)const
// Source: json
//------------------------------------------------------------------------------
const CMatchSearcher::SearchResult_t *__thiscall CMatchSearcher::GetSearchResult(CMatchSearcher *this, int idx)
{
  if ( this->IsSearchFinished(this) && idx >= 0 && idx < this->m_arrSearchResultsAggregate.m_Size )
    return &this->m_arrSearchResultsAggregate.m_Memory.m_pMemory[idx];
  else
    return &s_empty;
}

//------------------------------------------------------------------------------
// Address: 0x10030A70
// Name: public: CMatchSearcher::CMatchSearcher(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CMatchSearcher *__thiscall CMatchSearcher::CMatchSearcher(CMatchSearcher *this, KeyValues *pSettings)
{
  KeyValues *m_pSettings; // ecx
  IKeyValuesDumpContext pDump; // [esp+4h] [ebp-8h] BYREF
  int v6; // [esp+8h] [ebp-4h]

  this->__vftable = (CMatchSearcher_vtbl *)&CMatchSearcher::`vftable';
  this->m_CallbackOnLobbyMatchListReceived.m_nCallbackFlags = 0;
  this->m_CallbackOnLobbyMatchListReceived.__vftable = (CCallResult<CMatchSearcher,LobbyMatchList_t>_vtbl *)&CCallResult<CMatchSearcher,LobbyMatchList_t>::`vftable';
  this->m_CallbackOnLobbyMatchListReceived.m_hAPICall = 0;
  this->m_CallbackOnLobbyMatchListReceived.m_pObj = nullptr;
  this->m_CallbackOnLobbyMatchListReceived.m_Func = nullptr;
  this->m_CallbackOnLobbyMatchListReceived.m_iCallback = 510;
  this->m_pSettings = pSettings;
  this->m_autodelete_pSettings.m_pKeyValues = pSettings;
  this->m_pSessionSearchTree = nullptr;
  this->m_autodelete_pSessionSearchTree.m_pKeyValues = nullptr;
  this->m_pSearchPass = nullptr;
  this->m_eState = 0;
  this->m_arrSearchResults.m_Memory.m_pMemory = nullptr;
  this->m_arrSearchResults.m_Memory.m_nAllocationCount = 0;
  this->m_arrSearchResults.m_Memory.m_nGrowSize = 0;
  this->m_arrSearchResults.m_Size = 0;
  this->m_arrSearchResults.m_pElements = nullptr;
  this->m_arrSearchResultsAggregate.m_Memory.m_pMemory = nullptr;
  this->m_arrSearchResultsAggregate.m_Memory.m_nAllocationCount = 0;
  this->m_arrSearchResultsAggregate.m_Memory.m_nGrowSize = 0;
  this->m_arrSearchResultsAggregate.m_Size = 0;
  this->m_arrSearchResultsAggregate.m_pElements = nullptr;
  DevMsg(a1: "Created CMatchSearcher:\n");
  m_pSettings = this->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v6 = 1;
  KeyValues::Dump(this: m_pSettings, &pDump, nIndentLevel: 1);
  CMatchSearcher::InitializeSettings(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10030B10
// Name: public: virtual CMatchSearcher::~CMatchSearcher(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSearcher::~CMatchSearcher(CMatchSearcher *this)
{
  CMatchSearcher *v1; // esi
  KeyValues *m_pSettings; // ecx
  unsigned int v3; // eax
  CUtlVector<CMatchSearcher::SearchResult_t,CUtlMemory<CMatchSearcher::SearchResult_t,int> > *v4; // edi
  int v5; // ebx
  CMatchSearcher::SearchResult_t *m_pMemory; // esi
  KeyValues *m_pGameDetails; // ecx
  CMatchSearcher::SearchResult_t *v8; // eax
  CMatchSearcher::SearchResult_t *v9; // eax
  KeyValues *m_pKeyValues; // ecx
  KeyValues *v11; // ecx
  int m_hAPICall; // eax
  int m_hAPICall_high; // ecx
  _DWORD *v14; // esi
  CUtlVector<CMatchSearcher::SearchResult_t,CUtlMemory<CMatchSearcher::SearchResult_t,int> > *arrResults[2]; // [esp+4h] [ebp-18h]
  CMatchSearcher *v16; // [esp+Ch] [ebp-10h]
  IKeyValuesDumpContext pDump; // [esp+10h] [ebp-Ch] BYREF
  int ia; // [esp+14h] [ebp-8h]
  int k; // [esp+18h] [ebp-4h]

  v1 = this;
  v16 = this;
  this->__vftable = (CMatchSearcher_vtbl *)&CMatchSearcher::`vftable';
  DevMsg(a1: "Destroying CMatchSearcher:\n");
  m_pSettings = v1->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  ia = 1;
  KeyValues::Dump(this: m_pSettings, &pDump, nIndentLevel: 1);
  arrResults[0] = &v1->m_arrSearchResults;
  arrResults[1] = &v1->m_arrSearchResultsAggregate;
  v3 = 0;
  ia = 0;
  do
  {
    v4 = arrResults[v3];
    v5 = 0;
    k = 0;
    if ( v4->m_Size > 0 )
    {
      do
      {
        m_pMemory = v4->m_Memory.m_pMemory;
        m_pGameDetails = v4->m_Memory.m_pMemory[v5].m_pGameDetails;
        if ( m_pGameDetails != nullptr )
        {
          KeyValues::deleteThis(this: m_pGameDetails);
          m_pMemory[v5].m_pGameDetails = nullptr;
        }
        ++v5;
        ++k;
      }
      while ( k < v4->m_Size );
      v1 = v16;
      v3 = ia;
    }
    ia = ++v3;
  }
  while ( v3 < 2 );
  v1->m_arrSearchResultsAggregate.m_Size = 0;
  if ( v1->m_arrSearchResultsAggregate.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v1->m_arrSearchResultsAggregate.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v1->m_arrSearchResultsAggregate.m_Memory.m_pMemory);
      v1->m_arrSearchResultsAggregate.m_Memory.m_pMemory = nullptr;
    }
    v1->m_arrSearchResultsAggregate.m_Memory.m_nAllocationCount = 0;
  }
  v8 = v1->m_arrSearchResultsAggregate.m_Memory.m_pMemory;
  v1->m_arrSearchResultsAggregate.m_pElements = v8;
  if ( v1->m_arrSearchResultsAggregate.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v8);
      v1->m_arrSearchResultsAggregate.m_Memory.m_pMemory = nullptr;
    }
    v1->m_arrSearchResultsAggregate.m_Memory.m_nAllocationCount = 0;
  }
  v1->m_arrSearchResults.m_Size = 0;
  if ( v1->m_arrSearchResults.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v1->m_arrSearchResults.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v1->m_arrSearchResults.m_Memory.m_pMemory);
      v1->m_arrSearchResults.m_Memory.m_pMemory = nullptr;
    }
    v1->m_arrSearchResults.m_Memory.m_nAllocationCount = 0;
  }
  v9 = v1->m_arrSearchResults.m_Memory.m_pMemory;
  v1->m_arrSearchResults.m_pElements = v9;
  if ( v1->m_arrSearchResults.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v9 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v9);
      v1->m_arrSearchResults.m_Memory.m_pMemory = nullptr;
    }
    v1->m_arrSearchResults.m_Memory.m_nAllocationCount = 0;
  }
  m_pKeyValues = v1->m_autodelete_pSessionSearchTree.m_pKeyValues;
  if ( m_pKeyValues != nullptr )
    KeyValues::deleteThis(this: m_pKeyValues);
  v11 = v1->m_autodelete_pSettings.m_pKeyValues;
  if ( v11 != nullptr )
    KeyValues::deleteThis(this: v11);
  m_hAPICall = v1->m_CallbackOnLobbyMatchListReceived.m_hAPICall;
  m_hAPICall_high = HIDWORD(v1->m_CallbackOnLobbyMatchListReceived.m_hAPICall);
  v14 = &v1->m_CallbackOnLobbyMatchListReceived.__vftable;
  *v14 = &CCallResult<CMatchSearcher,LobbyMatchList_t>::`vftable';
  if ( (m_hAPICall_high | m_hAPICall) != 0 )
  {
    _SteamAPI_UnregisterCallResult(a1: v14, a2: m_hAPICall, a3: m_hAPICall_high);
    v14[4] = 0;
    v14[5] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030CA0
// Name: protected: void CMatchSearcher::Steam_OnLobbyMatchListReceived(struct LobbyMatchList_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSearcher::Steam_OnLobbyMatchListReceived(
        CMatchSearcher *this,
        LobbyMatchList_t *pLobbyMatchList,
        bool bError)
{
  unsigned int m_nLobbiesMatching; // eax
  int v5; // eax
  signed int v6; // ecx
  CSteamID *v7; // eax
  unsigned int m_unAll64Bits; // ecx
  unsigned int m_unAll64Bits_high; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CMatchSearcher::SearchResult_t *m_pMemory; // ecx
  int v13; // eax
  CMatchSearcher::SearchResult_t *v14; // edi
  unsigned __int64 sr; // [esp+8h] [ebp-1Ch]
  _BYTE v16[8]; // [esp+18h] [ebp-Ch] BYREF
  int iLobby; // [esp+20h] [ebp-4h]

  if ( bError )
    m_nLobbiesMatching = 0;
  else
    m_nLobbiesMatching = pLobbyMatchList->m_nLobbiesMatching;
  DevMsg(a1: "Received %d search results.\n", m_nLobbiesMatching);
  v5 = 0;
  for ( iLobby = 0; ; v5 = iLobby )
  {
    v6 = bError ? 0 : pLobbyMatchList->m_nLobbiesMatching;
    if ( v5 >= v6 )
      break;
    v7 = steamapicontext->m_pSteamMatchmaking->GetLobbyByIndex(
           this: steamapicontext->m_pSteamMatchmaking,
           result: v16,
           a3: v5);
    m_unAll64Bits = v7->m_steamid.m_unAll64Bits;
    m_unAll64Bits_high = HIDWORD(v7->m_steamid.m_unAll64Bits);
    m_Size = this->m_arrSearchResults.m_Size;
    m_nAllocationCount = this->m_arrSearchResults.m_Memory.m_nAllocationCount;
    sr = __PAIR64__(m_unAll64Bits_high, m_unAll64Bits);
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CMatchSearcher::SearchResult_t,int>::Grow(
        this: &this->m_arrSearchResults.m_Memory,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_arrSearchResults.m_Size;
    m_pMemory = this->m_arrSearchResults.m_Memory.m_pMemory;
    v13 = this->m_arrSearchResults.m_Size - m_Size - 1;
    this->m_arrSearchResults.m_pElements = m_pMemory;
    if ( v13 > 0 )
      _V_memmove(dest: (void *)&m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v13);
    v14 = &this->m_arrSearchResults.m_Memory.m_pMemory[m_Size];
    if ( v14 != nullptr )
    {
      v14->m_uiLobbyId = sr;
      *(_QWORD *)&v14->m_pGameDetails = 0;
    }
    ++iLobby;
  }
  CUtlVector<CMatchSearcher::SearchResult_t,CUtlMemory<CMatchSearcher::SearchResult_t,int>>::InsertMultipleBefore(
    this: &this->m_arrSearchResultsAggregate,
    elem: this->m_arrSearchResultsAggregate.m_Size,
    num: this->m_arrSearchResults.m_Size,
    pToInsert: this->m_arrSearchResults.m_Memory.m_pMemory);
  this->m_arrSearchResults.m_Size = 0;
  if ( this->m_arrSearchResults.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_arrSearchResults.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_arrSearchResults.m_Memory.m_pMemory);
      this->m_arrSearchResults.m_Memory.m_pMemory = nullptr;
    }
    this->m_arrSearchResults.m_Memory.m_nAllocationCount = 0;
  }
  this->m_arrSearchResults.m_pElements = this->m_arrSearchResults.m_Memory.m_pMemory;
  this->OnSearchPassDone(this, a2: this->m_pSearchPass);
}

//------------------------------------------------------------------------------
// Address: 0x10030DE0
// Name: protected: virtual void CMatchSearcher::StartSearchPass(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSearcher::StartSearchPass(CMatchSearcher *this, KeyValues *pSearchPass)
{
  KeyValues *v2; // esi
  CMatchSearcher *v3; // ebx
  ISteamMatchmaking *m_pSteamMatchmaking; // edi
  int Int; // eax
  KeyValues *Key; // eax
  KeyValues *FirstValue; // esi
  ISteamMatchmaking_vtbl *v8; // ebx
  const char *v9; // eax
  ISteamMatchmaking_vtbl *v10; // ebx
  const char *Name; // eax
  KeyValues *v12; // eax
  KeyValues *j; // esi
  ISteamMatchmaking_vtbl *v14; // ebx
  const char *v15; // eax
  __int64 v16; // rax
  int m_hAPICall_high; // ecx
  int v18; // edi
  int m_hAPICall; // eax
  int v20; // eax
  bool v21; // zf
  char *String; // [esp-8h] [ebp-54h]
  int v23; // [esp-8h] [ebp-54h]
  ELobbyComparison v24; // [esp-4h] [ebp-50h]
  ELobbyComparison v25; // [esp-4h] [ebp-50h]
  int v26; // [esp-4h] [ebp-50h]
  const char *arrKeys[6]; // [esp+Ch] [ebp-40h]
  ELobbyComparison nValueCmp[6]; // [esp+24h] [ebp-28h]
  unsigned __int64 hCall; // [esp+3Ch] [ebp-10h]
  IKeyValuesDumpContext pDump; // [esp+44h] [ebp-8h] BYREF
  unsigned int i; // [esp+48h] [ebp-4h]

  v2 = pSearchPass;
  v3 = this;
  this->m_pSearchPass = pSearchPass;
  HIDWORD(hCall) = this;
  this->m_arrSearchResults.m_Size = 0;
  if ( this->m_arrSearchResults.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_arrSearchResults.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_arrSearchResults.m_Memory.m_pMemory);
      v3->m_arrSearchResults.m_Memory.m_pMemory = nullptr;
    }
    v3->m_arrSearchResults.m_Memory.m_nAllocationCount = 0;
  }
  v3->m_arrSearchResults.m_pElements = v3->m_arrSearchResults.m_Memory.m_pMemory;
  v3->m_eState = 1;
  DevMsg(a1: "OnlineSearch::StartSearchPass:\n");
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  i = 1;
  KeyValues::Dump(this: pSearchPass, &pDump, nIndentLevel: 1);
  m_pSteamMatchmaking = steamapicontext->m_pSteamMatchmaking;
  Int = KeyValues::GetInt(this: pSearchPass, keyName: "numPlayers", defaultValue: 0);
  m_pSteamMatchmaking->AddRequestLobbyListFilterSlotsAvailable(this: m_pSteamMatchmaking, a2: Int);
  arrKeys[0] = "Filter<";
  arrKeys[1] = "Filter<=";
  arrKeys[2] = "Filter=";
  arrKeys[3] = "Filter<>";
  arrKeys[4] = "Filter>=";
  arrKeys[5] = "Filter>";
  nValueCmp[0] = k_ELobbyComparisonLessThan;
  nValueCmp[1] = k_ELobbyComparisonEqualToOrLessThan;
  nValueCmp[2] = k_ELobbyComparisonEqual;
  nValueCmp[3] = k_ELobbyComparisonNotEqual;
  nValueCmp[4] = k_ELobbyComparisonEqualToOrGreaterThan;
  nValueCmp[5] = k_ELobbyComparisonGreaterThan;
  for ( i = 0; i < 0x18; i += 4 )
  {
    Key = KeyValues::FindKey(this: v2, keyName: *(char **)((char *)arrKeys + i), bCreate: false);
    if ( Key != nullptr )
    {
      FirstValue = KeyValues::GetFirstValue(this: Key);
      if ( FirstValue != nullptr )
      {
        while ( KeyValues::GetDataType(this: FirstValue, keyName: nullptr) != TYPE_STRING )
        {
          if ( KeyValues::GetDataType(this: FirstValue, keyName: nullptr) == TYPE_INT )
          {
            v10 = m_pSteamMatchmaking->__vftable;
            v25 = *(ELobbyComparison *)((char *)nValueCmp + i);
            v23 = KeyValues::GetInt(this: FirstValue, keyName: nullptr, defaultValue: 0);
            Name = KeyValues::GetName(this: FirstValue);
            v10->AddRequestLobbyListNumericalFilter(this: m_pSteamMatchmaking, a2: Name, a3: v23, a4: v25);
            goto LABEL_12;
          }
LABEL_13:
          FirstValue = KeyValues::GetNextValue(this: FirstValue);
          if ( FirstValue == nullptr )
            goto LABEL_14;
        }
        v8 = m_pSteamMatchmaking->__vftable;
        v24 = *(ELobbyComparison *)((char *)nValueCmp + i);
        String = KeyValues::GetString(this: FirstValue, keyName: nullptr, defaultValue: defaultValue);
        v9 = KeyValues::GetName(this: FirstValue);
        v8->AddRequestLobbyListStringFilter(this: m_pSteamMatchmaking, a2: v9, a3: String, a4: v24);
LABEL_12:
        v3 = (CMatchSearcher *)HIDWORD(hCall);
        goto LABEL_13;
      }
LABEL_14:
      v2 = pSearchPass;
    }
  }
  v12 = KeyValues::FindKey(this: v2, keyName: "Near", bCreate: false);
  if ( v12 != nullptr )
  {
    for ( j = KeyValues::GetFirstValue(this: v12); j != nullptr; j = KeyValues::GetNextValue(this: j) )
    {
      if ( KeyValues::GetDataType(this: j, keyName: nullptr) == TYPE_INT )
      {
        v14 = m_pSteamMatchmaking->__vftable;
        v26 = KeyValues::GetInt(this: j, keyName: nullptr, defaultValue: 0);
        v15 = KeyValues::GetName(this: j);
        v14->AddRequestLobbyListNearValueFilter(this: m_pSteamMatchmaking, a2: v15, a3: v26);
        v3 = (CMatchSearcher *)HIDWORD(hCall);
      }
    }
  }
  DevMsg(a1: "Searching...\n");
  v16 = m_pSteamMatchmaking->RequestLobbyList(this: m_pSteamMatchmaking);
  m_hAPICall_high = HIDWORD(v3->m_CallbackOnLobbyMatchListReceived.m_hAPICall);
  v18 = v16;
  m_hAPICall = v3->m_CallbackOnLobbyMatchListReceived.m_hAPICall;
  HIDWORD(hCall) = HIDWORD(v16);
  if ( (m_hAPICall_high | m_hAPICall) != 0 )
    _SteamAPI_UnregisterCallResult(a1: &v3->m_CallbackOnLobbyMatchListReceived, a2: m_hAPICall, a3: m_hAPICall_high);
  v20 = HIDWORD(hCall);
  v21 = (HIDWORD(hCall) | v18) == 0;
  LODWORD(v3->m_CallbackOnLobbyMatchListReceived.m_hAPICall) = v18;
  HIDWORD(v3->m_CallbackOnLobbyMatchListReceived.m_hAPICall) = v20;
  v3->m_CallbackOnLobbyMatchListReceived.m_pObj = v3;
  v3->m_CallbackOnLobbyMatchListReceived.m_Func = CMatchSearcher::Steam_OnLobbyMatchListReceived;
  if ( !v21 )
    _SteamAPI_RegisterCallResult(a1: &v3->m_CallbackOnLobbyMatchListReceived, a2: v18, a3: v20);
}
