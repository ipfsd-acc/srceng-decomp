// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/mm_session_online_teamsearch.cpp
// Functions: 30
// ============================================================

#include "matchmaking\mm_session_online_teamsearch.h"

//------------------------------------------------------------------------------
// Address: 0x10006C80
// Name: protected: virtual void CSysSessionStubForTeamSearch<class CSysSessionHost>::Voice_CaptureAndTransmitLocalVoiceData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionStubForTeamSearch<CSysSessionHost>::Voice_CaptureAndTransmitLocalVoiceData(
        CSysSessionStubForTeamSearch<CSysSessionHost> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1002E0F0
// Name: protected: virtual void CMatchSearcher_OnlineTeamSearch::StartSearchPass(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSearcher_OnlineTeamSearch::StartSearchPass(
        CMatchSearcher_OnlineTeamSearch *this,
        KeyValues *pSearchPass)
{
  char *m_pszString; // eax

  if ( (sv_search_team_key.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = sv_search_team_key.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  KeyValues::SetString(this: pSearchPass, keyName: "Filter=/options:searchteamkey", value: m_pszString);
  CMatchSearcher::StartSearchPass(this, pSearchPass);
}

//------------------------------------------------------------------------------
// Address: 0x1002E140
// Name: protected: virtual void CMatchSessionOnlineTeamSearch::OnSearchEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineTeamSearch::OnSearchEvent(CMatchSessionOnlineTeamSearch *this, KeyValues *pNotify)
{
  if ( pNotify != nullptr )
  {
    if ( this->m_pHostSession != nullptr )
      this->m_pHostSession->OnEvent(this: &this->m_pHostSession->IMatchEventsSink, a2: pNotify);
    KeyValues::deleteThis(this: pNotify);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E170
// Name: protected: void CMatchSessionOnlineTeamSearch::ResetAndRestartTeamSearch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineTeamSearch::ResetAndRestartTeamSearch(CMatchSessionOnlineTeamSearch *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->m_eState = STATE_ERROR;
  this->m_flActionTime = 0.0;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(
           this: v2,
           setName: "OnMatchSessionUpdate",
           firstKey: "state",
           firstValue: "progress",
           secondKey: "progress",
           secondValue: "restart");
    this->OnSearchEvent(this, a2: v3);
  }
  else
  {
    this->OnSearchEvent(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E1D0
// Name: public: class CSysSessionBase __near * CMatchSessionOnlineTeamSearch::LinkSysSession(void)
// Source: json
//------------------------------------------------------------------------------
CSysSessionHost *__thiscall CMatchSessionOnlineTeamSearch::LinkSysSession(CMatchSessionOnlineTeamSearch *this)
{
  CSysSessionHost *result; // eax

  if ( this->m_eState == STATE_LINK_HOST )
    return this->m_pSysSessionHost;
  if ( this->m_eState == STATE_LINK_CLIENT )
    return (CSysSessionHost *)this->m_pSysSessionClient;
  result = this->m_pSysSessionHost;
  if ( result == nullptr )
    return (CSysSessionHost *)this->m_pSysSessionClient;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002E1F0
// Name: public: virtual void CMatchSessionOnlineTeamSearch::DebugPrint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineTeamSearch::DebugPrint(CMatchSessionOnlineTeamSearch *this)
{
  double v2; // xmm0_8
  float m_flActionTime; // [esp+14h] [ebp-4h]

  DevMsg(a1: "CMatchSessionOnlineTeamSearch::CMatchSessionOnlineSearch\n");
  CMatchSessionOnlineSearch::DebugPrint(this);
  DevMsg(a1: "CMatchSessionOnlineTeamSearch [ state=%d ]\n", this->m_eState);
  DevMsg(a1: "    linkstate: %d\n", this->m_iLinkState);
  DevMsg(a1: "    linkpeer:  %llx\n", this->m_xuidLinkPeer);
  if ( this->m_flActionTime == 0.0 )
  {
    v2 = 0.0;
  }
  else
  {
    m_flActionTime = this->m_flActionTime;
    v2 = m_flActionTime - _Plat_FloatTime();
  }
  DevMsg(a1: "    actiontime:%.3f\n", v2);
  if ( this->m_pDsSearcher != nullptr )
    DevMsg(a1: "TeamSearch: Dedicated search in progress\n");
  else
    DevMsg(a1: "TeamSearch: Dedicated search not active\n");
  DevMsg(a1: "TeamSearch: SysSession host state:\n");
  if ( this->m_pSysSessionHost != nullptr )
    this->m_pSysSessionHost->DebugPrint(this: this->m_pSysSessionHost);
  else
    DevMsg(a1: "SysSession is NULL\n");
  DevMsg(a1: "TeamSearch: SysSession client state:\n");
  if ( this->m_pSysSessionClient != nullptr )
    this->m_pSysSessionClient->DebugPrint(this: this->m_pSysSessionClient);
  else
    DevMsg(a1: "SysSession is NULL\n");
}

//------------------------------------------------------------------------------
// Address: 0x1002E2F0
// Name: public: virtual void CMatchSessionOnlineTeamSearch::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineTeamSearch::OnEvent(CMatchSessionOnlineTeamSearch *this, KeyValues *pEvent)
{
  CMatchSessionOnlineSearch::OnEvent(this, pEvent);
  if ( this->m_pSysSessionClient != nullptr )
    (**((void (__thiscall ***)(CSysSessionClient_vtbl **, KeyValues *))&this->m_pSysSessionClient->__vftable + 1))(
      a1: &this->m_pSysSessionClient->__vftable + 1,
      a2: pEvent);
}

//------------------------------------------------------------------------------
// Address: 0x1002E320
// Name: public: virtual void CMatchSessionOnlineTeamSearch::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineTeamSearch::Destroy(CMatchSessionOnlineTeamSearch *this)
{
  CSysSessionHost *m_pSysSessionHost; // ecx
  CSysSessionClient *m_pSysSessionClient; // ecx
  CDsSearcher *m_pDsSearcher; // ecx

  m_pSysSessionHost = this->m_pSysSessionHost;
  if ( m_pSysSessionHost != nullptr )
  {
    m_pSysSessionHost->Destroy(this: m_pSysSessionHost);
    this->m_pSysSessionHost = nullptr;
  }
  m_pSysSessionClient = this->m_pSysSessionClient;
  if ( m_pSysSessionClient != nullptr )
  {
    m_pSysSessionClient->Destroy(this: m_pSysSessionClient);
    this->m_pSysSessionClient = nullptr;
  }
  m_pDsSearcher = this->m_pDsSearcher;
  if ( m_pDsSearcher != nullptr )
  {
    m_pDsSearcher->Destroy(this: m_pDsSearcher);
    this->m_pDsSearcher = nullptr;
  }
  CMatchSessionOnlineSearch::Destroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002E370
// Name: protected: void CMatchSessionOnlineTeamSearchLinkBase::StartWaitingForPeerServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineTeamSearchLinkBase::StartWaitingForPeerServer(
        CMatchSessionOnlineTeamSearchLinkBase *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  this->m_iLinkState = 1;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(
           this: v2,
           setName: "OnMatchSessionUpdate",
           firstKey: "state",
           firstValue: "progress",
           secondKey: "progress",
           secondValue: "peerserver");
    this->OnSearchEvent(this, a2: v3);
  }
  else
  {
    this->OnSearchEvent(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E3D0
// Name: protected: virtual void CSysSessionStubForTeamSearch<class CSysSessionClient>::OnSessionEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionStubForTeamSearch<CSysSessionClient>::OnSessionEvent(
        CSysSessionStubForTeamSearch<CSysSessionClient> *this,
        KeyValues *notify)
{
  if ( notify != nullptr )
  {
    if ( this->m_pMatchSession != nullptr )
      this->m_pMatchSession->OnSessionEvent(this: this->m_pMatchSession, a2: notify);
    KeyValues::deleteThis(this: notify);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E410
// Name: protected: virtual void CSysSessionStubForTeamSearch<class CSysSessionHost>::OnSessionEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionStubForTeamSearch<CSysSessionHost>::OnSessionEvent(
        CSysSessionStubForTeamSearch<CSysSessionHost> *this,
        KeyValues *notify)
{
  if ( notify != nullptr )
  {
    if ( this->m_pMatchSession != nullptr )
      this->m_pMatchSession->OnSessionEvent(this: this->m_pMatchSession, a2: notify);
    KeyValues::deleteThis(this: notify);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E490
// Name: protected: virtual class CSysSessionClient __near * CMatchSessionOnlineTeamSearch::OnBeginJoiningSearchResult(void)
// Source: json
//------------------------------------------------------------------------------
CSysSessionClient *__thiscall CMatchSessionOnlineTeamSearch::OnBeginJoiningSearchResult(
        CMatchSessionOnlineTeamSearch *this)
{
  CSysSessionClient *v2; // esi

  v2 = (CSysSessionClient *)operator new(nSize: 0xC8u);
  if ( v2 == nullptr )
    return nullptr;
  CSysSessionClient::CSysSessionClient(this: v2, pSettings: this->m_pSettings);
  v2[1].__vftable = (CSysSessionClient_vtbl *)this;
  v2->__vftable = (CSysSessionClient_vtbl *)&CSysSessionStubForTeamSearch<CSysSessionClient>::`vftable';
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1002E4D0
// Name: protected: virtual void CMatchSessionOnlineTeamSearch::OnSearchCompletedSuccess(class CSysSessionClient __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineTeamSearch::OnSearchCompletedSuccess(
        CMatchSessionOnlineTeamSearch *this,
        CSysSessionClient *pSysSession,
        KeyValues *pSettings)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  this->m_pSettings = pSettings;
  this->m_autodelete_pSettings.m_pKeyValues = pSettings;
  this->m_pSysSessionClient = pSysSession;
  this->m_eState = STATE_LINK_CLIENT;
  this->m_xuidLinkPeer = ((__int64 (__thiscall *)(CSysSessionClient *, _DWORD, _DWORD))pSysSession->GetHostXuid)(
                           a1: pSysSession,
                           a2: 0,
                           a3: 0);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(
           this: v4,
           setName: "OnMatchSessionUpdate",
           firstKey: "state",
           firstValue: "progress",
           secondKey: "progress",
           secondValue: "searchlinked");
  else
    v5 = nullptr;
  this->OnSearchEvent(this, a2: v5);
  this->m_iLinkState = 5;
}

//------------------------------------------------------------------------------
// Address: 0x1002E550
// Name: protected: virtual void CMatchSessionOnlineTeamSearch::OnSearchCompletedEmpty(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineTeamSearch::OnSearchCompletedEmpty(
        CMatchSessionOnlineTeamSearch *this,
        KeyValues *pSettings)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  CSysSessionHost *v5; // eax
  CSysSessionHost *v6; // edi

  this->m_pSettings = pSettings;
  this->m_autodelete_pSettings.m_pKeyValues = pSettings;
  this->m_eState = 1;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(
           this: v3,
           setName: "OnMatchSessionUpdate",
           firstKey: "state",
           firstValue: "progress",
           secondKey: "progress",
           secondValue: "searchidle");
  else
    v4 = nullptr;
  this->OnSearchEvent(this, a2: v4);
  v5 = (CSysSessionHost *)operator new(nSize: 0xD8u);
  v6 = v5;
  if ( v5 != nullptr )
  {
    CSysSessionHost::CSysSessionHost(this: v5, pSettings: this->m_pSettings);
    v6[1].__vftable = (CSysSessionHost_vtbl *)this;
    v6->__vftable = (CSysSessionHost_vtbl *)&CSysSessionStubForTeamSearch<CSysSessionHost>::`vftable';
    this->m_pSysSessionHost = v6;
  }
  else
  {
    this->m_pSysSessionHost = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E5F0
// Name: protected: void CMatchSessionOnlineTeamSearchLinkBase::StartHostingListenServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineTeamSearchLinkBase::StartHostingListenServer(
        CMatchSessionOnlineTeamSearchLinkBase *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  KeyValues *m_pUpdateHostSessionPacket; // edi
  CMatchSessionOnlineHost *m_pHostSession; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  if ( mm_teamsearch_nostart.m_pParent != nullptr && mm_teamsearch_nostart.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "Cancel");
    else
      v3 = nullptr;
    this->m_pHostSession->Command(this: this->m_pHostSession, a2: v3);
    if ( v3 != nullptr )
      KeyValues::deleteThis(this: v3);
  }
  else
  {
    m_pUpdateHostSessionPacket = this->m_pUpdateHostSessionPacket;
    this->m_iLinkState = 0;
    if ( m_pUpdateHostSessionPacket != nullptr )
    {
      m_pHostSession = this->m_pHostSession;
      this->m_pUpdateHostSessionPacket = nullptr;
      this->m_autodelete_pUpdateHostSessionPacket.m_pKeyValues = nullptr;
      m_pHostSession->UpdateSessionSettings(this: m_pHostSession, a2: m_pUpdateHostSessionPacket);
      KeyValues::deleteThis(this: m_pUpdateHostSessionPacket);
    }
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
    {
      v7 = KeyValues::KeyValues(this: v6, setName: "TeamSearchResult::ListenHost");
      this->OnSearchEvent(this, a2: v7);
    }
    else
    {
      this->OnSearchEvent(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E6A0
// Name: protected: void CMatchSessionOnlineTeamSearchLinkBase::StartDedicatedServerSearch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineTeamSearchLinkBase::StartDedicatedServerSearch(
        CMatchSessionOnlineTeamSearchLinkBase *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  CDsSearcher *v6; // edi
  KeyValues *v7; // eax
  unsigned __int64 Uint64; // rax

  if ( mm_teamsearch_nostart.m_pParent != nullptr && mm_teamsearch_nostart.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "Cancel");
    else
      v3 = nullptr;
    this->m_pHostSession->Command(this: this->m_pHostSession, a2: v3);
    if ( v3 != nullptr )
      KeyValues::deleteThis(this: v3);
  }
  else
  {
    this->m_iLinkState = 2;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(
             this: v4,
             setName: "OnMatchSessionUpdate",
             firstKey: "state",
             firstValue: "progress",
             secondKey: "progress",
             secondValue: "dedicated");
    else
      v5 = nullptr;
    this->OnSearchEvent(this, a2: v5);
    v6 = (CDsSearcher *)operator new(nSize: 0x348u);
    if ( v6 != nullptr )
    {
      v7 = this->m_pHostSession->GetSessionSystemData(this: this->m_pHostSession);
      Uint64 = KeyValues::GetUint64(this: v7, keyName: "xuidReserve", defaultValue: 0);
      this->m_pDsSearcher = CDsSearcher::CDsSearcher(this: v6, pSettings: this->m_pSettings, uiReserveCookie: Uint64);
    }
    else
    {
      this->m_pDsSearcher = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E780
// Name: protected: void CMatchSessionOnlineTeamSearchLinkBase::OnDedicatedSearchFinished(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineTeamSearchLinkBase::OnDedicatedSearchFinished(
        CMatchSessionOnlineTeamSearchLinkBase *this)
{
  const CDsSearcher::DsResult_t *v2; // eax
  CDsSearcher *m_pDsSearcher; // ecx
  bool v4; // zf
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  KeyValues *v7; // eax
  unsigned __int64 Uint64; // rax
  KeyValues *m_pUpdateHostSessionPacket; // esi
  CMatchSessionOnlineHost *m_pHostSession; // ecx
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // esi
  KeyValues *Copy; // eax
  void *m_pSysSessionHost; // ecx
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // esi
  CDsSearcher::DsResult_t dsResult; // [esp+Ch] [ebp-304h] BYREF

  v2 = this->m_pDsSearcher->GetResult(this: this->m_pDsSearcher);
  qmemcpy((void *)&dsResult, v2, 0x300u);
  m_pDsSearcher = this->m_pDsSearcher;
  *(_WORD *)&dsResult.m_szPrivateConnectionString[254] = *(_WORD *)&v2->m_szPrivateConnectionString[254];
  m_pDsSearcher->Destroy(this: m_pDsSearcher);
  v4 = !dsResult.m_bDedicated;
  this->m_pDsSearcher = nullptr;
  if ( v4 )
  {
    CMatchSessionOnlineTeamSearchLinkBase::StartHostingListenServer(this);
  }
  else
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "server");
    else
      v6 = nullptr;
    CDsSearcher::DsResult_t::CopyToServerKey(this: &dsResult, pKvServer: v6);
    v7 = this->m_pHostSession->GetSessionSystemData(this: this->m_pHostSession);
    Uint64 = KeyValues::GetUint64(this: v7, keyName: "xuidReserve", defaultValue: 0);
    KeyValues::SetUint64(this: v6, keyName: "reservationid", value: Uint64);
    m_pUpdateHostSessionPacket = this->m_pUpdateHostSessionPacket;
    if ( m_pUpdateHostSessionPacket != nullptr )
    {
      m_pHostSession = this->m_pHostSession;
      this->m_pUpdateHostSessionPacket = nullptr;
      this->m_autodelete_pUpdateHostSessionPacket.m_pKeyValues = nullptr;
      m_pHostSession->UpdateSessionSettings(this: m_pHostSession, a2: m_pUpdateHostSessionPacket);
      KeyValues::deleteThis(this: m_pUpdateHostSessionPacket);
    }
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
    {
      v12 = KeyValues::KeyValues(this: v11, setName: "TeamSearchLink::Dedicated");
      v13 = v12;
      if ( v12 != nullptr )
      {
        KeyValues::SetString(this: v12, keyName: "run", value: "xuid");
        KeyValues::SetUint64(this: v13, keyName: "runxuid", value: this->m_xuidLinkPeer);
        KeyValues::SetInt(this: v6, keyName: "team", value: 2);
        Copy = KeyValues::MakeCopy(this: v6);
        KeyValues::AddSubKey(this: v13, pSubkey: Copy);
        if ( this->CMatchSessionOnlineTeamSearch::m_eState == STATE_LINK_HOST )
        {
          m_pSysSessionHost = this->m_pSysSessionHost;
        }
        else if ( this->CMatchSessionOnlineTeamSearch::m_eState == STATE_LINK_CLIENT
               || (m_pSysSessionHost = this->m_pSysSessionHost) == nullptr )
        {
          m_pSysSessionHost = this->m_pSysSessionClient;
        }
        (*(void (__thiscall **)(void *, KeyValues *))(*(_DWORD *)m_pSysSessionHost + 12))(
          a1: m_pSysSessionHost,
          a2: v13);
        KeyValues::deleteThis(this: v13);
      }
    }
    v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v16 != nullptr )
    {
      v17 = KeyValues::KeyValues(this: v16, setName: "TeamSearchResult::Dedicated");
      v18 = v17;
      if ( v17 != nullptr )
      {
        KeyValues::SetPtr(this: v17, keyName: "dsresult", value: (void *)&dsResult);
        KeyValues::SetInt(this: v6, keyName: "team", value: 1);
        KeyValues::AddSubKey(this: v18, pSubkey: v6);
        this->OnSearchEvent(this, a2: v18);
      }
    }
    this->m_iLinkState = 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002E9A0
// Name: public: CMatchSessionOnlineTeamSearch::CMatchSessionOnlineTeamSearch(class KeyValues __near *,class CMatchSessionOnlineHost __near *)
// Source: json
//------------------------------------------------------------------------------
CMatchSessionOnlineTeamSearch *__thiscall CMatchSessionOnlineTeamSearch::CMatchSessionOnlineTeamSearch(
        CMatchSessionOnlineTeamSearch *this,
        KeyValues *pSettings,
        CMatchSessionOnlineHost *pHost)
{
  KeyValues *Copy; // eax
  char *m_pszString; // ecx
  const char *String; // eax
  KeyValues *m_pSettings; // ecx
  IKeyValuesDumpContext pDump; // [esp+8h] [ebp-8h] BYREF
  int v10; // [esp+Ch] [ebp-4h]

  CMatchSessionOnlineSearch::CMatchSessionOnlineSearch(this);
  this->CMatchSessionOnlineSearch::IMatchSessionInternal::IMatchSession::__vftable = (CMatchSessionOnlineTeamSearch_vtbl *)&CMatchSessionOnlineTeamSearch::`vftable'{for `IMatchSession'};
  this->CMatchSessionOnlineSearch::IMatchSessionInternal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CMatchSessionOnlineTeamSearch::`vftable'{for `IMatchEventsSink'};
  this->m_eState = 0;
  this->m_iLinkState = 0;
  this->m_xuidLinkPeer = 0;
  this->m_pHostSession = pHost;
  this->m_pSysSessionHost = nullptr;
  this->m_pSysSessionClient = nullptr;
  this->m_pDsSearcher = nullptr;
  this->m_flActionTime = 0.0;
  this->m_pUpdateHostSessionPacket = nullptr;
  this->m_autodelete_pUpdateHostSessionPacket.m_pKeyValues = nullptr;
  this->m_flCreationTime = _Plat_FloatTime();
  Copy = KeyValues::MakeCopy(this: pSettings);
  this->m_pSettings = Copy;
  this->m_autodelete_pSettings.m_pKeyValues = Copy;
  if ( (sv_search_team_key.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = sv_search_team_key.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  KeyValues::SetString(this: Copy, keyName: "options/searchteamkey", value: m_pszString);
  String = KeyValues::GetString(this: this->m_pSettings, keyName: "options/server", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: "listen") != 0 )
    KeyValues::SetString(this: this->m_pSettings, keyName: "options/server", value: "official");
  DevMsg(a1: "Created CMatchSessionOnlineTeamSearch:\n");
  m_pSettings = this->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v10 = 1;
  KeyValues::Dump(this: m_pSettings, &pDump, nIndentLevel: 1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002EAA0
// Name: public: CMatchSearcher_OnlineTeamSearch::CMatchSearcher_OnlineTeamSearch(class CMatchSessionOnlineTeamSearch __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CMatchSearcher_OnlineTeamSearch *__thiscall CMatchSearcher_OnlineTeamSearch::CMatchSearcher_OnlineTeamSearch(
        CMatchSearcher_OnlineTeamSearch *this,
        CMatchSessionOnlineTeamSearch *pSession,
        KeyValues *pSettings)
{
  KeyValues *m_pSettings; // ecx
  IMatchTitle *v5; // eax
  int v6; // eax
  IMatchTitleGameSettingsMgr *v7; // eax
  KeyValues *v8; // ecx
  IKeyValuesDumpContext pDump; // [esp+4h] [ebp-8h] BYREF
  int v11; // [esp+8h] [ebp-4h]

  CMatchSearcher_OnlineSearch::CMatchSearcher_OnlineSearch(this, pSession, pSettings);
  m_pSettings = this->m_pSettings;
  this->__vftable = (CMatchSearcher_OnlineTeamSearch_vtbl *)&CMatchSearcher_OnlineTeamSearch::`vftable';
  KeyValues::SetString(this: m_pSettings, keyName: "system/lock", value: defaultValue);
  KeyValues::SetString(this: this->m_pSettings, keyName: "system/access", value: "public");
  KeyValues::SetString(this: this->m_pSettings, keyName: "system/netflag", value: "teamlink");
  v5 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
  v6 = v5->GetTotalNumPlayersSupported(this: v5);
  KeyValues::SetInt(this: this->m_pSettings, keyName: "Members/numSlots", value: v6);
  v7 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
  v7->InitializeGameSettings(this: v7, a2: this->m_pSettings, a3: "search_onlineteam");
  DevMsg(a1: "CMatchSearcher_OnlineTeamSearch title adjusted settings:\n");
  v8 = this->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v11 = 1;
  KeyValues::Dump(this: v8, &pDump, nIndentLevel: 1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002EB70
// Name: public: void CMatchSessionOnlineTeamSearchLinkBase::LinkUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineTeamSearchLinkBase::LinkUpdate(CMatchSessionOnlineTeamSearchLinkBase *this)
{
  int m_iLinkState; // eax
  CDsSearcher *m_pDsSearcher; // ecx
  KeyValues *v4; // eax
  KeyValues *Key; // ebx
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // edi
  KeyValues *Copy; // eax
  void *m_pSysSessionHost; // ecx

  m_iLinkState = this->m_iLinkState;
  if ( m_iLinkState != 0 )
  {
    if ( m_iLinkState == 2 )
    {
      m_pDsSearcher = this->m_pDsSearcher;
      if ( m_pDsSearcher != nullptr )
      {
        m_pDsSearcher->Update(this: m_pDsSearcher);
        if ( this->m_pDsSearcher->IsFinished(this: this->m_pDsSearcher) )
          CMatchSessionOnlineTeamSearchLinkBase::OnDedicatedSearchFinished(this);
      }
    }
  }
  else
  {
    v4 = this->m_pHostSession->GetSessionSettings(this: this->m_pHostSession);
    Key = KeyValues::FindKey(this: v4, keyName: "server", bCreate: false);
    if ( Key != nullptr )
    {
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "TeamSearchLink::ListenClient");
        v8 = v7;
        if ( v7 != nullptr )
        {
          KeyValues::SetString(this: v7, keyName: "run", value: "xuid");
          KeyValues::SetUint64(this: v8, keyName: "runxuid", value: this->m_xuidLinkPeer);
          Copy = KeyValues::MakeCopy(this: Key);
          KeyValues::AddSubKey(this: v8, pSubkey: Copy);
          KeyValues::SetString(this: v8, keyName: "server/server", value: "externalpeer");
          KeyValues::SetInt(this: v8, keyName: "server/team", value: 2);
          if ( this->CMatchSessionOnlineTeamSearch::m_eState == STATE_LINK_HOST )
          {
            m_pSysSessionHost = this->m_pSysSessionHost;
          }
          else if ( this->CMatchSessionOnlineTeamSearch::m_eState == STATE_LINK_CLIENT
                 || (m_pSysSessionHost = this->m_pSysSessionHost) == nullptr )
          {
            m_pSysSessionHost = this->m_pSysSessionClient;
          }
          (*(void (__thiscall **)(void *, KeyValues *))(*(_DWORD *)m_pSysSessionHost + 12))(
            a1: m_pSysSessionHost,
            a2: v8);
          KeyValues::deleteThis(this: v8);
        }
      }
      this->m_iLinkState = 3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EC80
// Name: public: void CMatchSessionOnlineTeamSearchLinkBase::LinkCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineTeamSearchLinkBase::LinkCommand(
        CMatchSessionOnlineTeamSearchLinkBase *this,
        KeyValues *pCommand)
{
  const char *Name; // ebx
  KeyValues *m_pUpdateHostSessionPacket; // edi
  CMatchSessionOnlineHost *m_pHostSession; // ecx
  KeyValues *v6; // edi
  CFmtStrN<256> *v7; // eax
  KeyValues *v8; // edi
  KeyValues *Copy; // eax
  CFmtStrN<256> v10; // [esp+Ch] [ebp-10Ch] BYREF
  KeyValues *pServerInfo; // [esp+120h] [ebp+8h]

  Name = KeyValues::GetName(this: pCommand);
  if ( _V_stricmp(s1: "TeamSearchLink::Dedicated", s2: Name) == 0
    || _V_stricmp(s1: "TeamSearchLink::ListenClient", s2: Name) == 0 )
  {
    pServerInfo = KeyValues::FindKey(this: pCommand, keyName: "server", bCreate: false);
    if ( pServerInfo != nullptr )
    {
      m_pUpdateHostSessionPacket = this->m_pUpdateHostSessionPacket;
      if ( m_pUpdateHostSessionPacket != nullptr )
      {
        m_pHostSession = this->m_pHostSession;
        this->m_pUpdateHostSessionPacket = nullptr;
        this->m_autodelete_pUpdateHostSessionPacket.m_pKeyValues = nullptr;
        m_pHostSession->UpdateSessionSettings(this: m_pHostSession, a2: m_pUpdateHostSessionPacket);
        KeyValues::deleteThis(this: m_pUpdateHostSessionPacket);
      }
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = CFmtStrN<256>::CFmtStrN<256>(this: &v10, pszFormat: "TeamSearchResult::%s", Name + 16);
        v8 = KeyValues::KeyValues(this: v6, setName: v7->m_szBuf);
        if ( v8 != nullptr )
        {
          Copy = KeyValues::MakeCopy(this: pServerInfo);
          KeyValues::AddSubKey(this: v8, pSubkey: Copy);
          this->OnSearchEvent(this, a2: v8);
        }
      }
    }
    else
    {
      CMatchSessionOnlineTeamSearch::ResetAndRestartTeamSearch(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002ED70
// Name: public: void CMatchSessionOnlineTeamSearchLinkHost::LinkUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineTeamSearchLinkHost::LinkUpdate(CMatchSessionOnlineTeamSearchLinkHost *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  KeyValues *v5; // eax
  KeyValues *Copy; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  unsigned int v9; // eax
  CGCClientJobUpdateStats *v10; // eax
  CGCClientJobUpdateStats *updated; // eax

  if ( this->m_iLinkState == 5 )
  {
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
    {
      v8 = KeyValues::KeyValues(this: v7, setName: "stat_agg");
      if ( v8 != nullptr )
      {
        v9 = (int)(_Plat_FloatTime() + 1.0 - this->m_flCreationTime);
        KeyValues::SetInt(
          this: v8,
          keyName: "search_team_time",
          value: (v9 > 0x708 ? 0 : v9)
        | (unsigned __int16)~((v9 > 0x708) - 1) & (unsigned __int16)~(((v9 & 0x80000000) == 0) - 1) & 0x708);
        v10 = (CGCClientJobUpdateStats *)operator new(nSize: 0x98u);
        if ( v10 != nullptr )
          updated = CGCClientJobUpdateStats::CGCClientJobUpdateStats(this: v10, pKVStats: v8);
        else
          updated = nullptr;
        GCSDK::CJob::StartJob(this: updated, pvStartParam: nullptr);
      }
    }
    this->m_iLinkState = 6;
LABEL_16:
    CMatchSessionOnlineTeamSearchLinkBase::LinkUpdate(this);
    return;
  }
  if ( this->m_iLinkState == 6 )
  {
    this->m_iLinkState = 7;
    CMatchSessionOnlineTeamSearchLinkBase::LinkUpdate(this);
    return;
  }
  if ( this->m_iLinkState != 7 )
    goto LABEL_16;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "TeamSearchLink::HostConfirmJoinReady");
    v4 = v3;
    if ( v3 != nullptr )
    {
      KeyValues::SetString(this: v3, keyName: "run", value: "xuid");
      KeyValues::SetUint64(this: v4, keyName: "runxuid", value: this->m_xuidLinkPeer);
      v5 = this->m_pHostSession->GetSessionSettings(this: this->m_pHostSession);
      Copy = KeyValues::MakeCopy(this: v5);
      KeyValues::AddSubKey(this: v4, pSubkey: Copy);
      this->m_pSysSessionHost->Command(this: this->m_pSysSessionHost, a2: v4);
      KeyValues::deleteThis(this: v4);
    }
  }
  this->m_iLinkState = 8;
  CMatchSessionOnlineTeamSearchLinkBase::LinkUpdate(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002EED0
// Name: public: void CMatchSessionOnlineTeamSearchLinkHost::LinkCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineTeamSearchLinkHost::LinkCommand(
        CMatchSessionOnlineTeamSearchLinkHost *this,
        KeyValues *pCommand)
{
  const char *Name; // edi
  KeyValues *FirstTrueSubKey; // eax
  KeyValues *v5; // edi
  KeyValues *Copy; // eax
  KeyValues *m_pUpdateHostSessionPacket; // ecx
  KeyValues *v8; // edi
  const char *String; // eax

  Name = KeyValues::GetName(this: pCommand);
  if ( _V_stricmp(s1: "TeamSearchLink::TeamLinkSessionUpdate", s2: Name) == 0 )
  {
    FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pCommand);
    v5 = FirstTrueSubKey;
    if ( FirstTrueSubKey != nullptr )
    {
      KeyValues::MergeFrom(this: this->m_pSettings, kvMerge: FirstTrueSubKey, eOp: MERGE_KV_ALL);
      Copy = KeyValues::MakeCopy(this: v5);
      m_pUpdateHostSessionPacket = this->m_pUpdateHostSessionPacket;
      v8 = Copy;
      if ( m_pUpdateHostSessionPacket != nullptr )
        KeyValues::deleteThis(this: m_pUpdateHostSessionPacket);
      this->m_pUpdateHostSessionPacket = v8;
      this->m_autodelete_pUpdateHostSessionPacket.m_pKeyValues = v8;
    }
    goto LABEL_6;
  }
  if ( _V_stricmp(s1: "TeamSearchLink::HostHosting", s2: Name) != 0 )
  {
    if ( _V_stricmp(s1: "TeamSearchLink::ClientHosting", s2: Name) != 0 )
    {
LABEL_6:
      CMatchSessionOnlineTeamSearchLinkBase::LinkCommand(this, pCommand);
      return;
    }
    CMatchSessionOnlineTeamSearchLinkBase::StartWaitingForPeerServer(this);
  }
  else
  {
    String = KeyValues::GetString(this: this->m_pSettings, keyName: "options/server", defaultValue: defaultValue);
    if ( _V_stricmp(s1: String, s2: "listen") != 0 )
      CMatchSessionOnlineTeamSearchLinkBase::StartDedicatedServerSearch(this);
    else
      CMatchSessionOnlineTeamSearchLinkBase::StartHostingListenServer(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002EFB0
// Name: public: void CMatchSessionOnlineTeamSearchLinkClient::LinkUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMatchSessionOnlineTeamSearchLinkClient::LinkUpdate(
        CMatchSessionOnlineTeamSearchLinkClient *this@<ecx>,
        const char *a2@<edi>)
{
  const char *String; // edi
  KeyValues *v4; // eax
  const char *v5; // ebx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // edi

  if ( this->m_iLinkState != 5 )
  {
    if ( this->m_iLinkState == 6 )
    {
      String = KeyValues::GetString(this: this->m_pSettings, keyName: "options/server", defaultValue: defaultValue);
      v4 = (KeyValues *)((int (__thiscall *)(CMatchSessionOnlineHost *, const char *))this->m_pHostSession->GetSessionSettings)(
                          a1: this->m_pHostSession,
                          a2: "options/server");
      v5 = KeyValues::GetString(this: v4, keyName: defaultValue, defaultValue: a2);
      if ( _V_stricmp(s1: String, s2: "listen") == 0 || _V_stricmp(s1: v5, s2: "listen") != 0 )
      {
        v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v8 != nullptr )
          v9 = KeyValues::KeyValues(
                 this: v8,
                 setName: "TeamSearchLink::HostHosting",
                 firstKey: "run",
                 firstValue: "host");
        else
          v9 = nullptr;
        ((void (__thiscall *)(CSysSessionClient *))this->m_pSysSessionClient->Command)(a1: this->m_pSysSessionClient);
        if ( v9 != nullptr )
          KeyValues::deleteThis(this: v9);
        CMatchSessionOnlineTeamSearchLinkBase::StartWaitingForPeerServer(this);
      }
      else
      {
        v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v6 != nullptr )
          v7 = KeyValues::KeyValues(
                 this: v6,
                 setName: "TeamSearchLink::ClientHosting",
                 firstKey: "run",
                 firstValue: "host");
        else
          v7 = nullptr;
        ((void (__thiscall *)(CSysSessionClient *))this->m_pSysSessionClient->Command)(a1: this->m_pSysSessionClient);
        if ( v7 != nullptr )
          KeyValues::deleteThis(this: v7);
        CMatchSessionOnlineTeamSearchLinkBase::StartHostingListenServer(this);
      }
    }
    else
    {
      CMatchSessionOnlineTeamSearchLinkBase::LinkUpdate(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F0C0
// Name: public: void CMatchSessionOnlineTeamSearchLinkClient::LinkCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineTeamSearchLinkClient::LinkCommand(
        CMatchSessionOnlineTeamSearchLinkClient *this,
        KeyValues *pCommand)
{
  const char *Name; // eax
  KeyValues *FirstTrueSubKey; // edi
  KeyValues *v5; // ebx
  IMatchTitleGameSettingsMgr *v6; // eax
  KeyValues *v7; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // ebx
  KeyValues *Copy; // eax
  KeyValues *m_pUpdateHostSessionPacket; // ecx

  Name = KeyValues::GetName(this: pCommand);
  if ( _V_stricmp(s1: "TeamSearchLink::HostConfirmJoinReady", s2: Name) != 0 )
  {
    CMatchSessionOnlineTeamSearchLinkBase::LinkCommand(this, pCommand);
  }
  else
  {
    FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pCommand);
    v5 = this->m_pHostSession->GetSessionSettings(this: this->m_pHostSession);
    v6 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
    v7 = v6->PrepareTeamLinkForGame(this: v6, a2: v5, a3: FirstTrueSubKey);
    if ( v7 != nullptr )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v9 = KeyValues::KeyValues(
               this: v8,
               setName: "TeamSearchLink::TeamLinkSessionUpdate",
               firstKey: "run",
               firstValue: "host");
        if ( v9 != nullptr )
        {
          Copy = KeyValues::MakeCopy(this: v7);
          KeyValues::AddSubKey(this: v9, pSubkey: Copy);
          this->m_pSysSessionClient->Command(this: this->m_pSysSessionClient, a2: v9);
          KeyValues::deleteThis(this: v9);
        }
      }
      KeyValues::MergeFrom(this: this->m_pSettings, kvMerge: v7, eOp: MERGE_KV_ALL);
      m_pUpdateHostSessionPacket = this->m_pUpdateHostSessionPacket;
      if ( m_pUpdateHostSessionPacket != nullptr )
        KeyValues::deleteThis(this: m_pUpdateHostSessionPacket);
      this->m_pUpdateHostSessionPacket = v7;
      this->m_autodelete_pUpdateHostSessionPacket.m_pKeyValues = v7;
    }
    if ( this->m_iLinkState == 5 )
      this->m_iLinkState = 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F1B0
// Name: protected: virtual class CMatchSearcher __near * CMatchSessionOnlineTeamSearch::OnStartSearching(void)
// Source: json
//------------------------------------------------------------------------------
CMatchSearcher_OnlineTeamSearch *__thiscall CMatchSessionOnlineTeamSearch::OnStartSearching(
        CMatchSessionOnlineTeamSearch *this)
{
  CMatchSearcher_OnlineTeamSearch *v2; // edi
  KeyValues *Copy; // eax

  v2 = (CMatchSearcher_OnlineTeamSearch *)operator new(nSize: 0x70u);
  if ( v2 == nullptr )
    return nullptr;
  Copy = KeyValues::MakeCopy(this: this->m_pSettings);
  return CMatchSearcher_OnlineTeamSearch::CMatchSearcher_OnlineTeamSearch(this: v2, pSession: this, pSettings: Copy);
}

//------------------------------------------------------------------------------
// Address: 0x1002F1E0
// Name: protected: void CMatchSessionOnlineTeamSearch::OnRunSessionCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineTeamSearch::OnRunSessionCommand(
        CMatchSessionOnlineTeamSearch *this,
        KeyValues *pCommand)
{
  if ( this->m_eState == STATE_LINK_HOST )
  {
    CMatchSessionOnlineTeamSearchLinkHost::LinkCommand((CMatchSessionOnlineTeamSearchLinkHost *)this, pCommand);
  }
  else if ( this->m_eState == STATE_LINK_CLIENT )
  {
    CMatchSessionOnlineTeamSearchLinkClient::LinkCommand((CMatchSessionOnlineTeamSearchLinkClient *)this, pCommand);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F200
// Name: public: virtual void CMatchSessionOnlineTeamSearch::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMatchSessionOnlineTeamSearch::Update(CMatchSessionOnlineTeamSearch *this@<ecx>, const char *a2@<edi>)
{
  bool v3; // zf
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  void *m_pSysSessionHost; // ecx

  if ( this->m_eState == STATE_LINK_HOST )
  {
    CMatchSessionOnlineTeamSearchLinkHost::LinkUpdate((CMatchSessionOnlineTeamSearchLinkHost *)this);
LABEL_14:
    CMatchSessionOnlineSearch::Update(this);
    if ( this->m_eState == STATE_LINK_HOST )
    {
      m_pSysSessionHost = this->m_pSysSessionHost;
    }
    else if ( this->m_eState == STATE_LINK_CLIENT )
    {
      m_pSysSessionHost = this->m_pSysSessionClient;
    }
    else
    {
      m_pSysSessionHost = this->m_pSysSessionHost;
      if ( m_pSysSessionHost != nullptr )
      {
LABEL_22:
        (*(void (__thiscall **)(void *))(*(_DWORD *)m_pSysSessionHost + 4))(a1: m_pSysSessionHost);
        return;
      }
      m_pSysSessionHost = this->m_pSysSessionClient;
      if ( m_pSysSessionHost == nullptr )
        return;
    }
    if ( m_pSysSessionHost == nullptr )
      return;
    goto LABEL_22;
  }
  if ( this->m_eState == STATE_LINK_CLIENT )
  {
    CMatchSessionOnlineTeamSearchLinkClient::LinkUpdate((CMatchSessionOnlineTeamSearchLinkClient *)this, a2);
    goto LABEL_14;
  }
  if ( this->m_eState != STATE_ERROR )
    goto LABEL_14;
  if ( this->m_flActionTime != 0.0 && _Plat_FloatTime() > this->m_flActionTime )
  {
    v3 = this->m_pHostSession == nullptr;
    this->m_flActionTime = 0.0;
    if ( !v3 )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "Stop");
      else
        v5 = nullptr;
      this->m_pHostSession->Command(this: this->m_pHostSession, a2: v5);
      if ( v5 != nullptr )
        KeyValues::deleteThis(this: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F2D0
// Name: public: virtual void CMatchSessionOnlineTeamSearch::OnSessionEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineTeamSearch::OnSessionEvent(CMatchSessionOnlineTeamSearch *this, KeyValues *pEvent)
{
  const char *Name; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *FirstTrueSubKey; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // edi
  float pEventa; // [esp+10h] [ebp+8h]

  this->OnEvent(this: &this->IMatchEventsSink, a2: pEvent);
  if ( this->m_eState != 0 )
  {
    Name = KeyValues::GetName(this: pEvent);
    if ( _V_stricmp(s1: "mmF->SysSessionUpdate", s2: Name) != 0 )
    {
      if ( _V_stricmp(s1: "mmF->SysSessionCommand", s2: Name) != 0 )
      {
        if ( _V_stricmp(s1: "OnPlayerMachinesConnected", s2: Name) != 0 )
        {
          if ( _V_stricmp(s1: "OnPlayerRemoved", s2: Name) == 0 )
            CMatchSessionOnlineTeamSearch::ResetAndRestartTeamSearch(this);
        }
        else
        {
          this->m_eState = STATE_LINK_HOST;
          this->m_xuidLinkPeer = KeyValues::GetUint64(this: pEvent, keyName: "id", defaultValue: 0);
          v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v10 != nullptr )
            v11 = KeyValues::KeyValues(
                    this: v10,
                    setName: "OnMatchSessionUpdate",
                    firstKey: "state",
                    firstValue: "progress",
                    secondKey: "progress",
                    secondValue: "searchlinked");
          else
            v11 = nullptr;
          this->OnSearchEvent(this, a2: v11);
          KeyValues::SetString(this: this->m_pSettings, keyName: "system/lock", value: "linked");
          v12 = KeyValues::FromString(
                  szName: "update",
                  szStringVal: " update {  system {  lock linked  }  } ",
                  ppEndOfParse: nullptr);
          CSysSessionHost::OnUpdateSessionSettings(this: this->m_pSysSessionHost, kv: v12);
          if ( v12 != nullptr )
            KeyValues::deleteThis(this: v12);
          this->m_iLinkState = 5;
        }
      }
      else
      {
        if ( this->m_pSysSessionHost != nullptr
          && KeyValues::GetPtr(this: pEvent, keyName: "syssession", defaultValue: nullptr) == this->m_pSysSessionHost )
        {
          FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pEvent);
          if ( FirstTrueSubKey != nullptr )
            CMatchSessionOnlineTeamSearch::OnRunSessionCommand(this, pCommand: FirstTrueSubKey);
        }
        if ( this->m_pSysSessionClient != nullptr
          && KeyValues::GetPtr(this: pEvent, keyName: "syssession", defaultValue: nullptr) == this->m_pSysSessionClient )
        {
          v9 = KeyValues::GetFirstTrueSubKey(this: pEvent);
          if ( v9 != nullptr )
            CMatchSessionOnlineTeamSearch::OnRunSessionCommand(this, pCommand: v9);
        }
      }
    }
    else if ( this->m_pSysSessionHost != nullptr
           && KeyValues::GetPtr(this: pEvent, keyName: "syssession", defaultValue: nullptr) == this->m_pSysSessionHost )
    {
      if ( KeyValues::GetString(this: pEvent, keyName: "error", defaultValue: nullptr) != nullptr )
      {
        this->m_pSysSessionHost->Destroy(this: this->m_pSysSessionHost);
        this->m_pSysSessionHost = nullptr;
        this->m_eState = STATE_ERROR;
        pEventa = mm_teamsearch_errortime.m_pParent->m_Value.m_fValue;
        this->m_flActionTime = _Plat_FloatTime() + pEventa;
        v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v4 != nullptr )
        {
          v5 = KeyValues::KeyValues(
                 this: v4,
                 setName: "OnMatchSessionUpdate",
                 firstKey: "state",
                 firstValue: "progress",
                 secondKey: "progress",
                 secondValue: "searcherror");
          this->OnSearchEvent(this, a2: v5);
          return;
        }
      }
      else
      {
        if ( this->m_eState != 1 )
          return;
        this->m_eState = STATE_AWAITING_PEER;
        v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v6 != nullptr )
        {
          v7 = KeyValues::KeyValues(
                 this: v6,
                 setName: "OnMatchSessionUpdate",
                 firstKey: "state",
                 firstValue: "progress",
                 secondKey: "progress",
                 secondValue: "searchawaitingpeer");
          this->OnSearchEvent(this, a2: v7);
          return;
        }
      }
      this->OnSearchEvent(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006C90
// Name: __CreateCMatchFrameworkIMatchFramework_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMatchFramework *__cdecl _CreateCMatchFrameworkIMatchFramework_interface()
{
  return &g_MatchFramework;
}
