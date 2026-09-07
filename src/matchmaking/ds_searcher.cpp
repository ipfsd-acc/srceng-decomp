// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/ds_searcher.cpp
// Functions: 18
// ============================================================

#include "matchmaking\ds_searcher.h"

//------------------------------------------------------------------------------
// Address: 0x1002E400
// Name: public: virtual void CDsSearcher::CServerListListener::ServerFailedToRespond(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDsSearcher::CServerListListener::ServerFailedToRespond(
        CServerManager *this,
        void *hReq,
        void *iServer)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1002F570
// Name: public: virtual void CDsSearcher::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDsSearcher::OnEvent(CDsSearcher *this, KeyValues *pEvent)
{
  KeyValues::GetName(this: pEvent);
}

//------------------------------------------------------------------------------
// Address: 0x1002F580
// Name: public: virtual bool CDsSearcher::IsFinished(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDsSearcher::IsFinished(CDsSearcher *this)
{
  return this->m_eState == STATE_FINISHED;
}

//------------------------------------------------------------------------------
// Address: 0x1002F590
// Name: public: virtual struct CDsSearcher::DsResult_t const __near & CDsSearcher::GetResult(void)
// Source: json
//------------------------------------------------------------------------------
const UserProfileData *__thiscall CDsSearcher::GetResult(PlayerLocal *this)
{
  return &this->m_ProfileData;
}

//------------------------------------------------------------------------------
// Address: 0x1002F5A0
// Name: public: void CDsSearcher::DsResult_t::CopyToServerKey(class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDsSearcher::DsResult_t::CopyToServerKey(CDsSearcher::DsResult_t *this, KeyValues *pKvServer)
{
  KeyValues::SetString(this: pKvServer, keyName: "server", value: "dedicated");
  KeyValues::SetString(this: pKvServer, keyName: "adronline", value: this->m_szPublicConnectionString);
  if ( this->m_szPrivateConnectionString[0] != 0 )
    KeyValues::SetString(this: pKvServer, keyName: "adrlocal", value: this->m_szPrivateConnectionString);
}

//------------------------------------------------------------------------------
// Address: 0x1002F680
// Name: public: virtual void CDsSearcher::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDsSearcher::Destroy(CDsSearcher *this)
{
  IMatchAsyncOperation *m_pAsyncOperation; // ecx
  CDsSearcher::CServerListListener *m_pServerListListener; // esi
  void *m_hRequest; // eax

  m_pAsyncOperation = this->m_pAsyncOperation;
  if ( m_pAsyncOperation != nullptr )
  {
    m_pAsyncOperation->Release(this: m_pAsyncOperation);
    this->m_pAsyncOperation = nullptr;
  }
  m_pServerListListener = this->m_pServerListListener;
  if ( m_pServerListListener != nullptr )
  {
    m_hRequest = m_pServerListListener->m_hRequest;
    m_pServerListListener->m_pOuter = nullptr;
    if ( m_hRequest != nullptr )
      steamapicontext->m_pSteamMatchmakingServers->ReleaseRequest(
        this: steamapicontext->m_pSteamMatchmakingServers,
        a2: m_hRequest);
    m_pServerListListener->m_hRequest = nullptr;
    free(pMem: m_pServerListListener);
    this->m_pServerListListener = nullptr;
  }
  ((void (__thiscall *)(CDsSearcher *, int))this->dtr_CDsSearcher)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1002F6E0
// Name: public: void CUtlMemory<struct CDsSearcher::DsServer_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CDsSearcher::DsServer_t,int>::Grow(CUtlMemory<CDsSearcher::DsServer_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CDsSearcher::DsServer_t *m_pMemory; // edx
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
    v7 = 516 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CDsSearcher::DsServer_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (CDsSearcher::DsServer_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F780
// Name: public: CDsSearcher::CServerListListener::CServerListListener(class CDsSearcher __near *,class CUtlVector<struct MatchMakingKeyValuePair_t,class CUtlMemory<struct MatchMakingKeyValuePair_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
CDsSearcher::CServerListListener *__thiscall CDsSearcher::CServerListListener::CServerListListener(
        CDsSearcher::CServerListListener *this,
        MatchMakingKeyValuePair_t *pDsSearcher,
        CUtlVector<MatchMakingKeyValuePair_t,CUtlMemory<MatchMakingKeyValuePair_t,int> > *filters)
{
  CDsSearcher *v3; // eax
  CUtlVector<MatchMakingKeyValuePair_t,CUtlMemory<MatchMakingKeyValuePair_t,int> > *v4; // ebx
  IMatchTitle *v6; // eax
  ISteamMatchmakingServers *m_pSteamMatchmakingServers; // edi
  int m_Size; // ecx
  ISteamMatchmakingServers_vtbl *v9; // ebx
  int v10; // eax

  v3 = (CDsSearcher *)pDsSearcher;
  v4 = filters;
  this->__vftable = (CDsSearcher::CServerListListener_vtbl *)&CDsSearcher::CServerListListener::`vftable';
  this->m_pOuter = v3;
  this->m_hRequest = nullptr;
  pDsSearcher = v4->m_Memory.m_pMemory;
  _DevMsg(a1: 1, a2: "Requesting dedicated server list...\n");
  v6 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
  m_pSteamMatchmakingServers = steamapicontext->m_pSteamMatchmakingServers;
  m_Size = v4->m_Size;
  v9 = m_pSteamMatchmakingServers->__vftable;
  v10 = ((int (__thiscall *)(IMatchTitle *, MatchMakingKeyValuePair_t **, int, CDsSearcher::CServerListListener *))v6->GetTitleID)(
          a1: v6,
          a2: &pDsSearcher,
          a3: m_Size,
          a4: this);
  this->m_hRequest = (void *)((int (__thiscall *)(ISteamMatchmakingServers *, int))v9->RequestInternetServerList)(
                               a1: m_pSteamMatchmakingServers,
                               a2: v10);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002F860
// Name: protected: void CDsSearcher::ReserveNextServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDsSearcher::ReserveNextServer(CDsSearcher *this)
{
  bool v2; // zf
  int m_Size; // eax
  int v4; // eax
  CDsSearcher::DsServer_t dss; // [esp+4h] [ebp-21Ch] BYREF
  netadr_s addrPublic; // [esp+208h] [ebp-18h] BYREF
  netadr_s addrPrivate; // [esp+214h] [ebp-Ch] BYREF

  v2 = this->m_arrServerList.m_Size == 0;
  this->m_eState = STATE_RESERVING;
  if ( v2 )
  {
    if ( this->m_flTimeout <= _Plat_FloatTime() )
      this->m_eState = STATE_FINISHED;
    else
      this->m_eState = STATE_STEAM_NEXT_SEARCH_PASS;
  }
  else
  {
    m_Size = this->m_arrServerList.m_Size;
    dss = *this->m_arrServerList.m_Memory.m_pMemory;
    v4 = m_Size - 1;
    if ( v4 > 0 )
      _V_memmove(
        dest: this->m_arrServerList.m_Memory.m_pMemory,
        src: &this->m_arrServerList.m_Memory.m_pMemory[1],
        count: 516 * v4);
    --this->m_arrServerList.m_Size;
    V_strncpy(pDest: this->m_Result.m_szPublicConnectionString, pSrc: dss.m_szConnectionString, maxLen: 256);
    V_strncpy(pDest: this->m_Result.m_szPrivateConnectionString, pSrc: dss.m_szPrivateConnectionString, maxLen: 256);
    netadr_s::SetIP(this: &addrPublic, unIP: 0);
    netadr_s::SetPort(this: &addrPublic, newport: 0);
    netadr_s::SetType(this: &addrPublic, newtype: NA_IP);
    netadr_s::SetIP(this: &addrPrivate, unIP: 0);
    netadr_s::SetPort(this: &addrPrivate, newport: 0);
    netadr_s::SetType(this: &addrPrivate, newtype: NA_IP);
    netadr_s::SetFromString(this: &addrPublic, pch: dss.m_szConnectionString, bUseDNS: false);
    if ( dss.m_szPrivateConnectionString[0] != 0 )
      netadr_s::SetFromString(this: &addrPrivate, pch: dss.m_szPrivateConnectionString, bUseDNS: false);
    else
      netadr_s::SetType(this: &addrPrivate, newtype: NA_NULL);
    ((void (__thiscall *)(INetSupport *, netadr_s *, netadr_s *, _DWORD, _DWORD, KeyValues *, CDsSearcher *, IMatchAsyncOperation **))g_pMatchExtensions->m_exts.m_pINetSupport->ReserveServer)(
      a1: g_pMatchExtensions->m_exts.m_pINetSupport,
      a2: &addrPublic,
      a3: &addrPrivate,
      a4: this->m_uiReserveCookie,
      a5: HIDWORD(this->m_uiReserveCookie),
      a6: this->m_pReserveSettings,
      a7: this,
      a8: &this->m_pAsyncOperation);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F9B0
// Name: protected: virtual void CDsSearcher::OnOperationFinished(class IMatchAsyncOperation __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDsSearcher::OnOperationFinished(CDsSearcher *this, IMatchAsyncOperation *pOperation)
{
  unsigned __int64 v3; // kr00_8

  v3 = this->m_pAsyncOperation->GetResult(this: this->m_pAsyncOperation);
  if ( this->m_pAsyncOperation->GetState(this: this->m_pAsyncOperation) == AOS_FAILED || v3 == 0 )
  {
    CDsSearcher::ReserveNextServer(this);
  }
  else
  {
    this->m_Result.m_bDedicated = true;
    V_strncpy(pDest: this->m_Result.m_szConnectionString, pSrc: (const char *)v3, maxLen: 256);
    this->m_eState = STATE_FINISHED;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002FA90
// Name: public: CDsSearcher::CDsSearcher(class KeyValues __near *,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
CDsSearcher *__userpurge CDsSearcher::CDsSearcher@<eax>(
        CDsSearcher *this@<ecx>,
        int a2@<edi>,
        KeyValues *pSettings,
        unsigned __int64 uiReserveCookie)
{
  int v5; // eax
  KeyValues *v6; // eax

  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  this->IMatchAsyncOperationCallback::__vftable = (CDsSearcher_vtbl *)&CDsSearcher::`vftable'{for `IMatchAsyncOperationCallback'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CDsSearcher::`vftable'{for `IMatchEventsSink'};
  this->m_flTimeout = 0.0;
  this->m_pAsyncOperation = nullptr;
  this->m_nSearchPass = 0;
  this->m_pServerListListener = nullptr;
  this->m_arrServerList.m_Memory.m_pMemory = nullptr;
  this->m_arrServerList.m_Memory.m_nAllocationCount = 0;
  this->m_arrServerList.m_Memory.m_nGrowSize = 0;
  this->m_arrServerList.m_Size = 0;
  this->m_arrServerList.m_pElements = nullptr;
  HIDWORD(this->m_uiReserveCookie) = HIDWORD(uiReserveCookie);
  this->m_pSettings = pSettings;
  LODWORD(this->m_uiReserveCookie) = uiReserveCookie;
  v5 = ((int (__thiscall *)(IMatchFramework *, int))g_pMatchFramework->GetMatchNetworkMsgController)(
         a1: g_pMatchFramework,
         a2);
  v6 = (KeyValues *)(*(int (__thiscall **)(int, KeyValues *))(*(_DWORD *)v5 + 20))(a1: v5, a2: this->m_pSettings);
  this->m_pReserveSettings = v6;
  this->m_autodelete_pReserveSettings.m_pKeyValues = v6;
  this->m_eState = 0;
  memset(dst: (unsigned __int8 *)&this->m_Result, value: 0, count: sizeof(this->m_Result));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002FB20
// Name: protected: void CDsSearcher::Steam_OnDedicatedServerListFetched(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDsSearcher::Steam_OnDedicatedServerListFetched(CDsSearcher *this)
{
  CDsSearcher::CServerListListener *m_pServerListListener; // esi
  void *m_hRequest; // eax

  m_pServerListListener = this->m_pServerListListener;
  if ( m_pServerListListener != nullptr )
  {
    m_hRequest = m_pServerListListener->m_hRequest;
    m_pServerListListener->m_pOuter = nullptr;
    if ( m_hRequest != nullptr )
      steamapicontext->m_pSteamMatchmakingServers->ReleaseRequest(
        this: steamapicontext->m_pSteamMatchmakingServers,
        a2: m_hRequest);
    m_pServerListListener->m_hRequest = nullptr;
    free(pMem: m_pServerListListener);
    this->m_pServerListListener = nullptr;
  }
  _DevMsg(a1: 1, a2: "Dedicated server list fetched %d servers.\n", this->m_arrServerList.m_Size);
  CDsSearcher::ReserveNextServer(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002FBC0
// Name: protected: void CDsSearcher::InitWithKnownServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDsSearcher::InitWithKnownServer(CDsSearcher *this)
{
  char *String; // edi
  char *v3; // eax
  CDsSearcher::DsServer_t pDest; // [esp+8h] [ebp-204h] BYREF

  String = KeyValues::GetString(this: this->m_pSettings, keyName: "server/adrlocal", defaultValue: defaultValue);
  v3 = KeyValues::GetString(this: this->m_pSettings, keyName: "server/adronline", defaultValue: defaultValue);
  pDest.m_nPing = 0;
  V_strncpy(pDest: pDest.m_szConnectionString, pSrc: v3, maxLen: 256);
  V_strncpy(pDest: pDest.m_szPrivateConnectionString, pSrc: String, maxLen: 256);
  CUtlVector<CDsSearcher::DsServer_t,CUtlMemory<CDsSearcher::DsServer_t,int>>::InsertBefore(
    this: &this->m_arrServerList,
    elem: this->m_arrServerList.m_Size,
    src: &pDest);
  CDsSearcher::ReserveNextServer(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002FC50
// Name: protected: void CDsSearcher::Steam_SearchPass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDsSearcher::Steam_SearchPass(CDsSearcher *this)
{
  CDsSearcher *v1; // edi
  char *v2; // ecx
  void *(__thiscall *Alloc_2)(IMemAlloc *, unsigned int); // edx
  char *ModDirectory; // esi
  char *v5; // eax
  IMatchTitleGameSettingsMgr *v6; // eax
  KeyValues *v7; // ebx
  char *v8; // eax
  KeyValues *FirstValue; // esi
  char *v10; // eax
  const char *v11; // edi
  const char *Name; // eax
  CDsSearcher::CServerListListener *v13; // eax
  CDsSearcher::CServerListListener *v14; // eax
  char *m_pszString; // eax
  int v16; // eax
  const char *v17; // ebx
  int v18; // eax
  netadr_s *v19; // esi
  int j; // edi
  int v21; // edi
  int v22; // esi
  IMatchServer *v23; // eax
  KeyValues *v24; // ebx
  netadr_s *v25; // esi
  int k; // edi
  char *String; // esi
  char *v28; // edi
  netadr_s *v29; // ebx
  unsigned int v30; // edi
  netadr_s *v31; // esi
  BOOL v32; // esi
  _DWORD *v33; // edi
  int m_Size; // esi
  int m_nAllocationCount; // eax
  int v36; // ecx
  int v37; // eax
  void *v38; // edi
  _DWORD *v39; // esi
  void *v40; // eax
  _DWORD v41[129]; // [esp+Ch] [ebp-270h] BYREF
  netadr_s adrsKnown[2]; // [esp+210h] [ebp-6Ch] BYREF
  CSplitString serverList; // [esp+228h] [ebp-54h] BYREF
  const char *adrsStringsKnown[2]; // [esp+240h] [ebp-3Ch]
  int numServers; // [esp+248h] [ebp-34h]
  int iServer; // [esp+24Ch] [ebp-30h]
  int i; // [esp+250h] [ebp-2Ch]
  netadr_s v48; // [esp+254h] [ebp-28h] BYREF
  netadr_s v49; // [esp+260h] [ebp-1Ch] BYREF
  const char *adrsStrings[2]; // [esp+26Ch] [ebp-10h]
  CDsSearcher *v51; // [esp+274h] [ebp-8h]
  int iAdrForced; // [esp+278h] [ebp-4h]

  v1 = this;
  v51 = this;
  if ( (mm_dedicated_force_servers.m_nFlags & 0x1000) != 0
    || (v2 = mm_dedicated_force_servers.m_pParent->m_Value.m_pszString) != nullptr && *v2 != 0 )
  {
    if ( (mm_dedicated_force_servers.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = mm_dedicated_force_servers.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    CSplitString::CSplitString(this: &serverList, pString: m_pszString, pSeparator: ",");
    v16 = 0;
    i = 0;
    if ( serverList.m_Size > 0 )
    {
      do
      {
        adrsStrings[0] = serverList.m_Memory.m_pMemory[v16];
        v17 = adrsStrings[0];
        adrsStrings[1] = defaultValue;
        strchr(string: (unsigned __int8 *)adrsStrings[0], chr: 0x7Cu);
        if ( v18 != 0 )
        {
          *(_BYTE *)v18 = 0;
          adrsStrings[1] = (const char *)(v18 + 1);
        }
        v19 = &v48;
        for ( j = 1; j >= 0; --j )
        {
          netadr_s::SetIP(this: v19, unIP: 0);
          netadr_s::SetPort(this: v19, newport: 0);
          netadr_s::SetType(this: v19++, newtype: NA_IP);
        }
        netadr_s::SetFromString(this: &v48, pch: v17, bUseDNS: false);
        netadr_s::SetFromString(this: &v49, pch: adrsStrings[1], bUseDNS: false);
        v21 = g_pServerManager->GetNumServers(this: g_pServerManager);
        v22 = 0;
        numServers = v21;
        for ( iServer = 0; v22 < v21; iServer = v22 )
        {
          v23 = g_pServerManager->GetServerByIndex(this: g_pServerManager, a2: v22);
          if ( v23 != nullptr )
          {
            v24 = v23->GetGameDetails(this: v23);
            v25 = adrsKnown;
            for ( k = 1; k >= 0; --k )
            {
              netadr_s::SetIP(this: v25, unIP: 0);
              netadr_s::SetPort(this: v25, newport: 0);
              netadr_s::SetType(this: v25++, newtype: NA_IP);
            }
            String = KeyValues::GetString(this: v24, keyName: "server/adronline", defaultValue: defaultValue);
            adrsStringsKnown[0] = String;
            v28 = KeyValues::GetString(this: v24, keyName: "server/adrlocal", defaultValue: defaultValue);
            adrsStringsKnown[1] = v28;
            netadr_s::SetFromString(this: adrsKnown, pch: String, bUseDNS: false);
            netadr_s::SetFromString(this: &adrsKnown[1], pch: v28, bUseDNS: false);
            iAdrForced = 0;
            v29 = &v48;
            while ( 2 )
            {
              v30 = 0;
              v31 = adrsKnown;
              do
              {
                if ( netadr_s::GetIP(this: v29) != 0
                  && netadr_s::GetIP(this: v31) != 0
                  && netadr_s::CompareAdr(this: v29, a: v31, onlyBase: false) )
                {
                  v32 = iAdrForced == 0;
                  if ( netadr_s::GetIP(this: &v48 + v32) == 0 )
                    adrsStrings[v32] = adrsStringsKnown[v30 == 0];
                  goto finished_server_lookup;
                }
                ++v30;
                ++v31;
              }
              while ( v30 < 2 );
              ++v29;
              if ( (unsigned int)++iAdrForced < 2 )
                continue;
              break;
            }
            v21 = numServers;
            v22 = iServer;
          }
          ++v22;
        }
finished_server_lookup:
        v41[128] = 0;
        V_strncpy(pDest: (char *)v41, pSrc: adrsStrings[0], maxLen: 256);
        V_strncpy(pDest: (char *)&v41[64], pSrc: adrsStrings[1], maxLen: 256);
        v33 = &v51->IMatchAsyncOperationCallback::__vftable;
        m_Size = v51->m_arrServerList.m_Size;
        m_nAllocationCount = v51->m_arrServerList.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CDsSearcher::DsServer_t,int>::Grow(
            this: &v51->m_arrServerList.m_Memory,
            num: m_Size - m_nAllocationCount + 1);
        ++v33[9];
        v36 = v33[6];
        v37 = v33[9] - m_Size - 1;
        v33[10] = v36;
        if ( v37 > 0 )
          _V_memmove(
            dest: (void *)(516 * m_Size + v36 + 516),
            src: (const void *)(516 * m_Size + v36),
            count: 516 * v37);
        v38 = (void *)(v33[6] + 516 * m_Size);
        if ( v38 != nullptr )
          qmemcpy(v38, v41, 516);
        v16 = i + 1;
        i = v16;
      }
      while ( v16 < serverList.m_Size );
      v1 = v51;
    }
    v39 = &v1->m_pServerListListener->__vftable;
    if ( v39 != nullptr )
    {
      v40 = (void *)v39[2];
      v39[1] = 0;
      if ( v40 != nullptr )
        steamapicontext->m_pSteamMatchmakingServers->ReleaseRequest(
          this: steamapicontext->m_pSteamMatchmakingServers,
          a2: v40);
      v39[2] = 0;
      free(pMem: v39);
      v1->m_pServerListListener = nullptr;
    }
    _DevMsg(a1: 1, a2: "Dedicated server list fetched %d servers.\n", v1->m_arrServerList.m_Size);
    CDsSearcher::ReserveNextServer(this: v1);
    CSplitString::~CSplitString(this: &serverList);
  }
  else
  {
    Alloc_2 = _g_pMemAlloc->Alloc_2;
    v49.type = NA_NULL;
    *(_DWORD *)v49.ip = 0;
    *(_DWORD *)&v48.port = 10;
    *(_DWORD *)v48.ip = Alloc_2(this: _g_pMemAlloc, a2: 5120u);
    *(_DWORD *)&v49.port = *(_DWORD *)v48.ip;
    ModDirectory = COM_GetModDirectory();
    V_strncpy(pDest: (char *)&v41[1], pSrc: "gamedir", maxLen: 256);
    V_strncpy(pDest: (char *)&v41[65], pSrc: ModDirectory, maxLen: 256);
    CUtlVector<MatchMakingKeyValuePair_t,CUtlMemory<MatchMakingKeyValuePair_t,int>>::InsertBefore(
      this: (CUtlVector<MatchMakingKeyValuePair_t,CUtlMemory<MatchMakingKeyValuePair_t,int> > *)v48.ip,
      elem: 0,
      src: (const MatchMakingKeyValuePair_t *)&v41[1]);
    V_strncpy(pDest: (char *)&v41[1], pSrc: "noplayers", maxLen: 256);
    V_strncpy(pDest: (char *)&v41[65], pSrc: "1", maxLen: 256);
    CUtlVector<MatchMakingKeyValuePair_t,CUtlMemory<MatchMakingKeyValuePair_t,int>>::InsertBefore(
      this: (CUtlVector<MatchMakingKeyValuePair_t,CUtlMemory<MatchMakingKeyValuePair_t,int> > *)v48.ip,
      elem: *(int *)v49.ip,
      src: (const MatchMakingKeyValuePair_t *)&v41[1]);
    v5 = KeyValues::GetString(this: v1->m_pSettings, keyName: "options/server", defaultValue: nullptr);
    if ( v5 != nullptr && _V_stricmp(s1: v5, s2: "official") == 0 && v1->m_nSearchPass % 2 == 0 )
    {
      V_strncpy(pDest: (char *)&v41[1], pSrc: "white", maxLen: 256);
      V_strncpy(pDest: (char *)&v41[65], pSrc: "1", maxLen: 256);
      CUtlVector<MatchMakingKeyValuePair_t,CUtlMemory<MatchMakingKeyValuePair_t,int>>::InsertBefore(
        this: (CUtlVector<MatchMakingKeyValuePair_t,CUtlMemory<MatchMakingKeyValuePair_t,int> > *)v48.ip,
        elem: *(int *)v49.ip,
        src: (const MatchMakingKeyValuePair_t *)&v41[1]);
    }
    v6 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
    v7 = v6->DefineDedicatedSearchKeys(this: v6, a2: v1->m_pSettings);
    if ( v7 != nullptr )
    {
      if ( (mm_dedicated_ip.m_nFlags & 0x1000) == 0 )
      {
        v8 = mm_dedicated_ip.m_pParent->m_Value.m_pszString;
        if ( v8 == nullptr || *v8 == 0 )
        {
          FirstValue = KeyValues::GetFirstValue(this: v7);
          if ( FirstValue != nullptr )
          {
            do
            {
              v10 = KeyValues::GetString(this: FirstValue, keyName: nullptr, defaultValue: defaultValue);
              v11 = v10;
              if ( v10 != nullptr && *v10 != 0 )
              {
                Name = KeyValues::GetName(this: FirstValue);
                V_strncpy(pDest: (char *)&v41[1], pSrc: Name, maxLen: 256);
                V_strncpy(pDest: (char *)&v41[65], pSrc: v11, maxLen: 256);
                CUtlVector<MatchMakingKeyValuePair_t,CUtlMemory<MatchMakingKeyValuePair_t,int>>::InsertBefore(
                  this: (CUtlVector<MatchMakingKeyValuePair_t,CUtlMemory<MatchMakingKeyValuePair_t,int> > *)v48.ip,
                  elem: *(int *)v49.ip,
                  src: (const MatchMakingKeyValuePair_t *)&v41[1]);
              }
              FirstValue = KeyValues::GetNextValue(this: FirstValue);
            }
            while ( FirstValue != nullptr );
            v1 = v51;
          }
        }
      }
      KeyValues::deleteThis(this: v7);
    }
    v1->m_eState = STATE_STEAM_REQUESTING_SERVERS;
    v13 = (CDsSearcher::CServerListListener *)operator new(nSize: 0xCu);
    if ( v13 != nullptr )
      v14 = CDsSearcher::CServerListListener::CServerListListener(
              this: v13,
              pDsSearcher: (MatchMakingKeyValuePair_t *)v1,
              filters: (CUtlVector<MatchMakingKeyValuePair_t,CUtlMemory<MatchMakingKeyValuePair_t,int> > *)v48.ip);
    else
      v14 = nullptr;
    ++v1->m_nSearchPass;
    v1->m_pServerListListener = v14;
    CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)v48.ip);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100301B0
// Name: public: virtual void CDsSearcher::CServerListListener::ServerResponded(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDsSearcher::CServerListListener::ServerResponded(
        CDsSearcher::CServerListListener *this,
        void *hReq,
        int iServer)
{
  ISteamMatchmakingServers *m_pSteamMatchmakingServers; // ecx
  gameserveritem_t *(__thiscall *GetServerDetails)(ISteamMatchmakingServers *, void *, int); // edx
  int v6; // esi
  char *v7; // edi
  char *m_pszString; // eax
  char *ConnectionAddressString; // eax
  const char *v10; // eax
  char v11; // al
  char *v12; // eax
  int v13; // eax
  char *String; // edi
  char *v15; // eax
  unsigned int IP; // eax
  int v17; // eax
  KeyValues *v18; // eax
  int v19; // ebx
  char *v20; // eax
  CDsSearcher::CServerListListener *v21; // esi
  int m_nValue; // eax
  CDsSearcher::DsServer_t pDest; // [esp+Ch] [ebp-21Ch] BYREF
  int Port; // [esp+214h] [ebp-14h]
  CDsSearcher::CServerListListener *v25; // [esp+218h] [ebp-10h]
  netadr_s adrPublic; // [esp+21Ch] [ebp-Ch] BYREF

  m_pSteamMatchmakingServers = steamapicontext->m_pSteamMatchmakingServers;
  GetServerDetails = m_pSteamMatchmakingServers->GetServerDetails;
  v25 = this;
  v6 = (int)GetServerDetails(this: m_pSteamMatchmakingServers, a2: hReq, a3: iServer);
  if ( (mm_dedicated_ip.m_nFlags & 0x1000) != 0 )
  {
    v7 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = mm_dedicated_ip.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      goto LABEL_9;
    v7 = mm_dedicated_ip.m_pParent->m_Value.m_pszString;
    if ( *m_pszString == 0 )
      goto LABEL_9;
  }
  ConnectionAddressString = servernetadr_t::GetConnectionAddressString(this: (servernetadr_t *)v6);
  v10 = StringAfterPrefix(str: ConnectionAddressString, prefix: v7);
  if ( v10 == nullptr || (v11 = *v10) != 0 && v11 != 58 )
  {
    v12 = servernetadr_t::GetConnectionAddressString(this: (servernetadr_t *)v6);
    DevMsg(a1: "    rejected dedicated server '%s' due to ip filter '%s'\n", v12, v7);
    return;
  }
LABEL_9:
  if ( *(_DWORD *)(v6 + 148) - *(_DWORD *)(v6 + 156) <= 0 )
  {
    v13 = mm_dedicated_search_maxping.m_pParent != nullptr ? mm_dedicated_search_maxping.m_pParent->m_Value.m_nValue : 0;
    if ( *(_DWORD *)(v6 + 8) <= v13 && this->m_pOuter != nullptr )
    {
      String = (char *)defaultValue;
      netadr_s::SetIP(this: &adrPublic, unIP: 0);
      netadr_s::SetPort(this: &adrPublic, newport: 0);
      netadr_s::SetType(this: &adrPublic, newtype: NA_IP);
      v15 = servernetadr_t::GetConnectionAddressString(this: (servernetadr_t *)v6);
      netadr_s::SetFromString(this: &adrPublic, pch: v15, bUseDNS: false);
      Port = netadr_s::GetPort(this: &adrPublic);
      IP = netadr_s::GetIP(this: &adrPublic);
      v17 = ((int (__thiscall *)(CServerManager *, unsigned int, int))g_pServerManager->GetServerByOnlineId)(
              a1: g_pServerManager,
              a2: IP,
              a3: Port);
      if ( v17 != 0 )
      {
        v18 = (KeyValues *)(*(int (__thiscall **)(int))(*(_DWORD *)v17 + 4))(a1: v17);
        String = KeyValues::GetString(this: v18, keyName: "server/adrlocal", defaultValue: defaultValue);
      }
      v19 = *(_DWORD *)(v6 + 8);
      v20 = servernetadr_t::GetConnectionAddressString(this: (servernetadr_t *)v6);
      pDest.m_nPing = v19;
      V_strncpy(pDest: pDest.m_szConnectionString, pSrc: v20, maxLen: 256);
      V_strncpy(pDest: pDest.m_szPrivateConnectionString, pSrc: String, maxLen: 256);
      v21 = v25;
      CUtlVector<CDsSearcher::DsServer_t,CUtlMemory<CDsSearcher::DsServer_t,int>>::InsertBefore(
        this: &v25->m_pOuter->m_arrServerList,
        elem: v25->m_pOuter->m_arrServerList.m_Size,
        src: &pDest);
      if ( mm_dedicated_search_maxresults.m_pParent != nullptr )
        m_nValue = mm_dedicated_search_maxresults.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( v21->m_pOuter->m_arrServerList.m_Size > m_nValue || _Plat_FloatTime() > v21->m_pOuter->m_flTimeout )
        steamapicontext->m_pSteamMatchmakingServers->CancelQuery(
          this: steamapicontext->m_pSteamMatchmakingServers,
          a2: hReq);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030390
// Name: public: virtual void CDsSearcher::CServerListListener::RefreshComplete(void __near *,enum EMatchMakingServerResponse)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDsSearcher::CServerListListener::RefreshComplete(
        CDsSearcher::CServerListListener *this,
        void *hReq,
        EMatchMakingServerResponse response)
{
  CDsSearcher *m_pOuter; // ecx

  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr )
    CDsSearcher::Steam_OnDedicatedServerListFetched(this: m_pOuter);
}

//------------------------------------------------------------------------------
// Address: 0x100303A0
// Name: protected: void CDsSearcher::InitDedicatedSearch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDsSearcher::InitDedicatedSearch(CDsSearcher *this)
{
  double v2; // st7
  float m_fValue; // [esp+4h] [ebp-4h]
  float v4; // [esp+4h] [ebp-4h]

  if ( mm_dedicated_fake.m_pParent != nullptr && mm_dedicated_fake.m_pParent->m_Value.m_nValue != 0 )
  {
    m_fValue = mm_dedicated_timeout_request.m_pParent->m_Value.m_fValue;
    v2 = _Plat_FloatTime();
    this->m_eState = STATE_WAITING;
    this->m_Result.m_bAborted = true;
    this->m_flTimeout = v2 + m_fValue;
  }
  else
  {
    v4 = mm_dedicated_timeout_request.m_pParent->m_Value.m_fValue;
    this->m_flTimeout = _Plat_FloatTime() + v4;
    CDsSearcher::Steam_SearchPass(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030410
// Name: public: virtual void CDsSearcher::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDsSearcher::Update(CDsSearcher *this)
{
  char *String; // ebx
  char *v3; // edi
  IMatchTitle *v4; // eax

  switch ( this->m_eState )
  {
    case 0:
      String = KeyValues::GetString(this: this->m_pSettings, keyName: "system/network", defaultValue: defaultValue);
      v3 = KeyValues::GetString(this: this->m_pSettings, keyName: "options/server", defaultValue: "listen");
      if ( KeyValues::GetString(this: this->m_pSettings, keyName: "server/server", defaultValue: nullptr) != nullptr )
      {
        CDsSearcher::InitWithKnownServer(this);
      }
      else if ( mm_dedicated_allow.m_pParent != nullptr
             && mm_dedicated_allow.m_pParent->m_Value.m_nValue != 0
             && _V_stricmp(s1: "LIVE", s2: String) == 0
             && _V_stricmp(s1: "listen", s2: v3) != 0
             && (v4 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework),
                 (v4->GetTitleSettingsFlags(this: v4) & 2) == 0) )
      {
        CDsSearcher::InitDedicatedSearch(this);
      }
      else
      {
        this->m_eState = STATE_FINISHED;
      }
      break;
    case 1:
      if ( _Plat_FloatTime() > this->m_flTimeout )
        this->m_eState = STATE_FINISHED;
      break;
    case 2:
      if ( _Plat_FloatTime() > this->m_flTimeout )
      {
        DevWarning(a1: "Steam search for dedicated servers timed out.\n");
        CDsSearcher::Steam_OnDedicatedServerListFetched(this);
      }
      break;
    case 3:
      CDsSearcher::Steam_SearchPass(this);
      break;
    default:
      return;
  }
}
