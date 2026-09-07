// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/cstrike15/mm_title.cpp
// Functions: 19
// ============================================================

#include "matchmaking\cstrike15\mm_title.h"

//------------------------------------------------------------------------------
// Address: 0x10001030
// Name: public: class vgui::ILocalize __near * CMatchExtensions::GetILocalize(void)
// Source: json
//------------------------------------------------------------------------------
vgui::ILocalize *__thiscall CMatchExtensions::GetILocalize(CMatchExtensions *this)
{
  return this->m_exts.m_pILocalize;
}

//------------------------------------------------------------------------------
// Address: 0x10001040
// Name: public: class IVEngineClient __near * CMatchExtensions::GetIVEngineClient(void)
// Source: json
//------------------------------------------------------------------------------
IVEngineClient *__thiscall CMatchExtensions::GetIVEngineClient(CMatchExtensions *this)
{
  return this->m_exts.m_pIVEngineClient;
}

//------------------------------------------------------------------------------
// Address: 0x10001050
// Name: public: class IVEngineServer __near * CMatchExtensions::GetIVEngineServer(void)
// Source: json
//------------------------------------------------------------------------------
IVEngineServer *__thiscall CMatchExtensions::GetIVEngineServer(CMatchExtensions *this)
{
  return this->m_exts.m_pIVEngineServer;
}

//------------------------------------------------------------------------------
// Address: 0x10001060
// Name: public: class IGameEventManager2 __near * CMatchExtensions::GetIGameEventManager2(void)
// Source: json
//------------------------------------------------------------------------------
IGameEventManager2 *__thiscall CMatchExtensions::GetIGameEventManager2(CMatchExtensions *this)
{
  return this->m_exts.m_pIGameEventManager2;
}

//------------------------------------------------------------------------------
// Address: 0x10001070
// Name: public: virtual CMatchTitle::~CMatchTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchTitle::~CMatchTitle(CMatchTitle *this)
{
  this->IMatchTitle::__vftable = (CMatchTitle_vtbl *)&CMatchTitle::`vftable'{for `IMatchTitle'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CMatchTitle::`vftable'{for `IMatchEventsSink'};
  this->IGameEventListener2::__vftable = (IGameEventListener2_vtbl *)&IGameEventListener2::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10001090
// Name: public: virtual enum InitReturnVal_t CMatchTitle::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatchTitle::Init(CMatchTitle *this)
{
  IGameEventManager2 *m_pIGameEventManager2; // esi
  IGameEventListener2 *v3; // eax
  IGameEventListener2 *v4; // eax
  IGameEventListener2 *v5; // eax
  IGameEventListener2 *v6; // eax
  IGameEventListener2 *v7; // eax
  IGameEventListener2 *v8; // eax

  m_pIGameEventManager2 = g_pMatchExtensions->m_exts.m_pIGameEventManager2;
  if ( m_pIGameEventManager2 != nullptr )
  {
    if ( this != nullptr )
      v3 = &this->IGameEventListener2;
    else
      v3 = nullptr;
    m_pIGameEventManager2->AddListener(this: m_pIGameEventManager2, a2: v3, a3: "server_pre_shutdown", a4: false);
    if ( this != nullptr )
      v4 = &this->IGameEventListener2;
    else
      v4 = nullptr;
    m_pIGameEventManager2->AddListener(this: m_pIGameEventManager2, a2: v4, a3: "game_newmap", a4: false);
    if ( this != nullptr )
      v5 = &this->IGameEventListener2;
    else
      v5 = nullptr;
    m_pIGameEventManager2->AddListener(this: m_pIGameEventManager2, a2: v5, a3: "finale_start", a4: false);
    if ( this != nullptr )
      v6 = &this->IGameEventListener2;
    else
      v6 = nullptr;
    m_pIGameEventManager2->AddListener(this: m_pIGameEventManager2, a2: v6, a3: "round_start", a4: false);
    if ( this != nullptr )
      v7 = &this->IGameEventListener2;
    else
      v7 = nullptr;
    m_pIGameEventManager2->AddListener(this: m_pIGameEventManager2, a2: v7, a3: "round_end", a4: false);
    if ( this != nullptr )
      v8 = &this->IGameEventListener2;
    else
      v8 = nullptr;
    m_pIGameEventManager2->AddListener(this: m_pIGameEventManager2, a2: v8, a3: "difficulty_changed", a4: false);
  }
  g_pGameTypes->Initialize(this: g_pGameTypes, a2: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001170
// Name: public: virtual void CMatchTitle::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchTitle::Shutdown(CMatchTitle *this)
{
  IGameEventManager2 *m_pIGameEventManager2; // ecx

  m_pIGameEventManager2 = g_pMatchExtensions->m_exts.m_pIGameEventManager2;
  if ( m_pIGameEventManager2 != nullptr )
  {
    if ( this != nullptr )
      m_pIGameEventManager2->RemoveListener(this: m_pIGameEventManager2, a2: &this->IGameEventListener2);
    else
      m_pIGameEventManager2->RemoveListener(this: m_pIGameEventManager2, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100011A0
// Name: public: virtual unsigned __int64 CMatchTitle::GetTitleID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatchTitle::GetTitleID(CMatchTitle *this)
{
  int result; // eax
  ISteamUtils *m_pSteamUtils; // ecx

  result = uiAppID;
  if ( uiAppID == 0 && steamapicontext != nullptr )
  {
    m_pSteamUtils = steamapicontext->m_pSteamUtils;
    if ( m_pSteamUtils != nullptr )
    {
      result = m_pSteamUtils->GetAppID(this: m_pSteamUtils);
      uiAppID = (unsigned int)result;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100011E0
// Name: public: virtual unsigned __int64 CMatchTitle::GetTitleSettingsFlags(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CMatchTitle::GetTitleSettingsFlags(CMatchTitle *this)
{
  return 33;
}

//------------------------------------------------------------------------------
// Address: 0x100011F0
// Name: public: virtual char const __near * CMatchTitle::GetGuestPlayerName(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CMatchTitle::GetGuestPlayerName(CMatchTitle *this, int iUserIndex)
{
  vgui::ILocalize *m_pILocalize; // esi
  int v3; // eax

  m_pILocalize = g_pMatchExtensions->m_exts.m_pILocalize;
  if ( m_pILocalize == nullptr )
    return (char *)defaultValue;
  v3 = (int)m_pILocalize->Find(this: m_pILocalize, a2: "#L4D360UI_Character_Guest");
  if ( v3 == 0 )
    return (char *)defaultValue;
  m_pILocalize->ConvertUnicodeToANSI(this: m_pILocalize, a2: (const wchar_t *)v3, a3: szName, a4: 32);
  return szName;
}

//------------------------------------------------------------------------------
// Address: 0x10001240
// Name: public: virtual bool CMatchTitle::StartServerMap(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CMatchTitle::StartServerMap@<al>(CMatchTitle *this@<ecx>, int a2@<esi>, KeyValues *pSettings)
{
  const char *String; // eax
  IVEngineServer *m_pIVEngineServer; // ecx
  int v6; // eax
  KeyValues *v7; // esi
  const char *v8; // eax

  String = KeyValues::GetString(this: pSettings, keyName: "game/bspname", defaultValue: nullptr);
  if ( String == nullptr )
    return 0;
  m_pIVEngineServer = g_pMatchExtensions->m_exts.m_pIVEngineServer;
  if ( m_pIVEngineServer == nullptr || m_pIVEngineServer->IsMapValid(this: m_pIVEngineServer, a2: String) == 0 )
    return 0;
  v6 = ((int (__thiscall *)(IMatchFramework *, int))g_pMatchFramework->GetMatchNetworkMsgController)(
         a1: g_pMatchFramework,
         a2);
  v7 = (KeyValues *)(*(int (__thiscall **)(int, KeyValues *))(*(_DWORD *)v6 + 20))(a1: v6, a2: pSettings);
  KeyValues::SetString(this: v7, keyName: "map/mapcommand", value: "map");
  v8 = KeyValues::GetString(this: pSettings, keyName: "options/play", defaultValue: defaultValue);
  if ( _V_stricmp(s1: "commentary", s2: v8) == 0 )
    KeyValues::SetString(this: v7, keyName: "map/mapcommand", value: "map_commentary");
  ((void (__thiscall *)(IVEngineClient *))g_pMatchExtensions->m_exts.m_pIVEngineClient->StartLoadingScreenForKeyValues)(a1: g_pMatchExtensions->m_exts.m_pIVEngineClient);
  if ( v7 != nullptr )
    KeyValues::deleteThis(this: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001300
// Name: GetCurrentMatchSessionSettings
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl GetCurrentMatchSessionSettings()
{
  IMatchSession *v0; // eax

  v0 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
  if ( v0 != nullptr )
    return v0->GetSessionSettings(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001320
// Name: public: virtual void CMatchTitle::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchTitle::OnEvent(CMatchTitle *this, KeyValues *pEvent)
{
  const char *Name; // edi
  const char *String; // eax
  CSysSessionStubForTeamSearch<CSysSessionHost> *v4; // ecx
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  CSysSessionStubForTeamSearch<CSysSessionHost> *v8; // ecx
  IMatchSession *v9; // eax

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: "OnPlayerRemoved", s2: Name) == 0 || _V_stricmp(s1: "OnPlayerUpdated", s2: Name) == 0 )
  {
    v9 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
    if ( v9 != nullptr )
      v9->GetSessionSettings(this: v9);
LABEL_10:
    CSysSessionStubForTeamSearch<CSysSessionHost>::Voice_CaptureAndTransmitLocalVoiceData(this: v8);
    return;
  }
  if ( _V_stricmp(s1: "OnMatchSessionUpdate", s2: Name) != 0 )
    return;
  String = KeyValues::GetString(this: pEvent, keyName: "state", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: "updated") == 0 )
  {
    if ( KeyValues::FindKey(this: pEvent, keyName: "update", bCreate: false) == nullptr )
      return;
    goto LABEL_6;
  }
  v5 = KeyValues::GetString(this: pEvent, keyName: "state", defaultValue: defaultValue);
  if ( _V_stricmp(s1: v5, s2: "created") == 0
    || (v6 = KeyValues::GetString(this: pEvent, keyName: "state", defaultValue: defaultValue),
        _V_stricmp(s1: v6, s2: "ready") == 0) )
  {
LABEL_6:
    GetCurrentMatchSessionSettings();
    CSysSessionStubForTeamSearch<CSysSessionHost>::Voice_CaptureAndTransmitLocalVoiceData(this: v4);
    return;
  }
  v7 = KeyValues::GetString(this: pEvent, keyName: "state", defaultValue: defaultValue);
  if ( _V_stricmp(s1: v7, s2: "closed") == 0 )
    goto LABEL_10;
}

//------------------------------------------------------------------------------
// Address: 0x10001490
// Name: public: virtual int CMatchTitle::GetEventDebugID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatchTitle::GetEventDebugID(CMatchTitle *this)
{
  return 42;
}

//------------------------------------------------------------------------------
// Address: 0x100014A0
// Name: protected: virtual void CFmtStrN<256>::InitQuietTruncation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFmtStrN<256>::InitQuietTruncation(CFmtStrN<256> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x100014B0
// Name: public: CMatchTitle::CMatchTitle(void)
// Source: json
//------------------------------------------------------------------------------
CMatchTitle *__thiscall CMatchTitle::CMatchTitle(CMatchTitle *this)
{
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  this->IGameEventListener2::__vftable = (IGameEventListener2_vtbl *)&IGameEventListener2::`vftable';
  this->IMatchTitle::__vftable = (CMatchTitle_vtbl *)&CMatchTitle::`vftable'{for `IMatchTitle'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CMatchTitle::`vftable'{for `IMatchEventsSink'};
  this->IGameEventListener2::__vftable = (IGameEventListener2_vtbl *)&CMatchTitle::`vftable'{for `IGameEventListener2'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001520
// Name: public: virtual void CMatchTitle::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMatchTitle::FireGameEvent(
        CMatchTitle *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        IGameEvent *pIGameEvent)
{
  IMatchSession *v4; // esi
  KeyValues *v5; // edi
  const char *v6; // ebx
  const char *v7; // eax
  KeyValues *v8; // eax
  const char *String; // eax
  const char *v10; // eax
  const char *v11; // ebx
  KeyValues *v12; // edi
  KeyValues *v13; // eax
  KeyValues *v14; // esi
  IMatchEventsSubscription *v15; // eax
  IMatchEventsSubscription *v16; // eax
  const char *v17; // edi
  KeyValues *v18; // eax
  KeyValues *v19; // ebx
  KeyValues *v20; // eax
  KeyValues *v21; // esi
  IMatchEventsSubscription *v22; // eax
  const char *v23; // eax
  KeyValues *v24; // eax
  KeyValues *v25; // esi
  IMatchEventsSubscription *v26; // eax

  v4 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
  if ( v4 != nullptr )
  {
    if ( (v5 = v4->GetSessionSettings(this: v4),
          v6 = KeyValues::GetString(this: v5, keyName: "server/server", defaultValue: defaultValue),
          v7 = KeyValues::GetString(this: v5, keyName: "system/lock", defaultValue: defaultValue),
          v6 != nullptr)
      && *v6 != 0
      || v7 != nullptr && *v7 != 0 )
    {
      v8 = (KeyValues *)v4->GetSessionSystemData(this: v4);
      String = KeyValues::GetString(this: v8, keyName: "type", defaultValue: nullptr);
      if ( String == nullptr || _V_stricmp(s1: String, s2: "client") != 0 )
      {
        v10 = pIGameEvent->GetName(this: pIGameEvent);
        v11 = v10;
        if ( v10 != nullptr && *v10 != 0 )
        {
          if ( _V_stricmp(s1: "round_start", s2: v10) == 0 )
          {
            v12 = KeyValues::FromString(
                    szName: "update",
                    szStringVal: " update {  game {  state game  }  } ",
                    ppEndOfParse: nullptr);
            v4->UpdateSessionSettings(this: v4, a2: v12);
            if ( v12 == nullptr )
              return;
            goto LABEL_12;
          }
          if ( _V_stricmp(s1: "round_end", s2: v11) != 0 )
          {
            if ( _V_stricmp(s1: "finale_start", s2: v11) != 0 )
            {
              if ( _V_stricmp(s1: "game_newmap", s2: v11) != 0 )
              {
                if ( _V_stricmp(s1: "server_pre_shutdown", s2: v11) == 0 )
                {
                  v23 = pIGameEvent->GetString(this: pIGameEvent, a2: "reason", a3: "quit");
                  if ( _V_stricmp(s1: v23, s2: "quit") == 0 )
                  {
                    DevMsg(a1: "Received server_pre_shutdown notification - server is shutting down...\n");
                    v24 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
                    if ( v24 != nullptr )
                      v25 = KeyValues::KeyValues(
                              this: v24,
                              setName: "OnEngineDisconnectReason",
                              firstKey: "reason",
                              firstValue: "Server shutting down");
                    else
                      v25 = nullptr;
                    v26 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
                    v26->BroadcastEvent(this: v26, a2: v25);
                  }
                }
              }
              else
              {
                v17 = (const char *)((int (__thiscall *)(IGameEvent *, const char *, const char *, int, int))pIGameEvent->GetString)(
                                      a1: pIGameEvent,
                                      a2: "mapname",
                                      a3: defaultValue,
                                      a4: a3,
                                      a5: a2);
                v18 = KeyValues::FromString(
                        szName: "update",
                        szStringVal: " update {  game {  state game  }  } ",
                        ppEndOfParse: nullptr);
                v19 = v18;
                if ( v17 != nullptr && *v17 != 0 )
                  KeyValues::SetString(this: v18, keyName: "update/game/map", value: v17);
                ((void (__thiscall *)(IMatchSession *))v4->UpdateSessionSettings)(a1: v4);
                v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
                if ( v20 != nullptr )
                  v21 = KeyValues::KeyValues(
                          this: v20,
                          setName: "OnProfilesWriteOpportunity",
                          firstKey: "reason",
                          firstValue: "checkpoint");
                else
                  v21 = nullptr;
                v22 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
                v22->BroadcastEvent(this: v22, a2: v21);
                if ( v19 != nullptr )
                  KeyValues::deleteThis(this: v19);
              }
            }
            else
            {
              v12 = KeyValues::FromString(
                      szName: "update",
                      szStringVal: " update {  game {  state finale  }  } ",
                      ppEndOfParse: nullptr);
              v4->UpdateSessionSettings(this: v4, a2: v12);
              if ( v12 != nullptr )
LABEL_12:
                KeyValues::deleteThis(this: v12);
            }
          }
          else
          {
            v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v13 != nullptr )
            {
              v14 = KeyValues::KeyValues(
                      this: v13,
                      setName: "OnProfilesWriteOpportunity",
                      firstKey: "reason",
                      firstValue: "checkpoint");
              v15 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
              v15->BroadcastEvent(this: v15, a2: v14);
            }
            else
            {
              v16 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
              v16->BroadcastEvent(this: v16, a2: nullptr);
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001820
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 255, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10001890
// Name: public: virtual void CMatchTitle::PrepareClientForConnect(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchTitle::PrepareClientForConnect(CMatchTitle *this, KeyValues *pSettings)
{
  IPlayerLocal *v2; // esi
  const char *v3; // eax

  v2 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
  if ( v2 != nullptr )
  {
    if ( (_S1 & 1) == 0 )
    {
      _S1 |= 1u;
      SplitScreenConVarRef::SplitScreenConVarRef(this: &s_cl_name, pName: "name");
    }
    v3 = v2->GetName(this: v2);
    s_cl_name.m_Info[0].m_pConVar->SetValue_4(this: s_cl_name.m_Info[0].m_pConVar, a2: v3);
  }
}
