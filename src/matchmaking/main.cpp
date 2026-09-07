// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/main.cpp
// Functions: 9
// ============================================================

#include "matchmaking\main.h"

//------------------------------------------------------------------------------
// Address: 0x10002000
// Name: public: class IEngineVoice __near * CMatchExtensions::GetIEngineVoice(void)
// Source: json
//------------------------------------------------------------------------------
IEngineVoice *__thiscall CMatchExtensions::GetIEngineVoice(CMatchExtensions *this)
{
  return this->m_exts.m_pIEngineVoice;
}

//------------------------------------------------------------------------------
// Address: 0x10002010
// Name: public: class IVEngineClient __near * CMatchExtensions::GetIVEngineClient(void)
// Source: json
//------------------------------------------------------------------------------
IVEngineClient *__thiscall CMatchExtensions::GetIVEngineClient(CMatchExtensions *this)
{
  return this->m_exts.m_pIVEngineClient;
}

//------------------------------------------------------------------------------
// Address: 0x10002030
// Name: InternalFactory
// Source: json
//------------------------------------------------------------------------------
void *__cdecl InternalFactory(const char *pName, int *pReturnCode)
{
  void *result; // eax
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  if ( pReturnCode != nullptr )
    *pReturnCode = 0;
  if ( s_pfnDelegateFactory == nullptr || (result = s_pfnDelegateFactory(a1: pName, a2: pReturnCode)) == nullptr )
  {
    FactoryThis = Sys_GetFactoryThis();
    result = FactoryThis(a1: pName, a2: pReturnCode);
    if ( result == nullptr )
    {
      if ( pReturnCode != nullptr )
        *pReturnCode = 1;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002080
// Name: public: virtual bool CMatchFramework::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatchFramework::Connect(CMatchFramework *this, void *(__cdecl *factory)(const char *, int *))
{
  MatchExtInterface_t *i; // esi
  void *v3; // eax
  CServerManager *v4; // ecx

  s_pfnDelegateFactory = factory;
  factory = InternalFactory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  for ( i = s_table_0; i->m_szName != nullptr; ++i )
  {
    if ( !i->m_bConnected )
    {
      v3 = factory(a1: i->m_szName, a2: nullptr);
      if ( v3 != nullptr )
      {
        g_pMatchExtensions->RegisterExtensionInterface(this: g_pMatchExtensions, a2: i->m_szName, a3: v3);
        i->m_bConnected = true;
      }
    }
  }
  s_pfnDelegateFactory = nullptr;
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: true,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  SteamApiContext_Shutdown(this: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002140
// Name: public: virtual void CMatchFramework::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::Disconnect(CMatchFramework *this)
{
  bool *p_m_bConnected; // esi
  void *v2; // eax

  SteamApiContext_Shutdown((CServerManager *)this);
  if ( s_table_0[0].m_szName != nullptr )
  {
    p_m_bConnected = &s_table_0[0].m_bConnected;
    do
    {
      if ( *p_m_bConnected )
      {
        v2 = (void *)(*((int (__thiscall **)(CMatchExtensions *))p_m_bConnected - 1))(a1: g_pMatchExtensions);
        g_pMatchExtensions->UnregisterExtensionInterface(
          this: g_pMatchExtensions,
          a2: *((const char **)p_m_bConnected - 2),
          a3: v2);
        *p_m_bConnected = false;
      }
      p_m_bConnected += 12;
    }
    while ( *((_DWORD *)p_m_bConnected - 2) != 0 );
  }
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x100021A0
// Name: public: virtual void __near * CMatchFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMatchFramework *__thiscall CMatchFramework::QueryInterface(CMatchFramework *this, const char *pInterfaceName)
{
  return _V_stricmp(s1: pInterfaceName, s2: "MATCHFRAMEWORK_001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100021D0
// Name: char const __near * COM_GetModDirectory(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl COM_GetModDirectory()
{
  int v0; // edi
  _DWORD *v1; // ebx
  int (__thiscall **v2)(_DWORD *, const char *, int); // esi
  int v3; // eax
  const char *v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax

  if ( _V_strlen(str: modDir) != 0 )
    return modDir;
  v0 = _CommandLine();
  v1 = (_DWORD *)_CommandLine();
  v2 = (int (__thiscall **)(_DWORD *, const char *, int))(*v1 + 32);
  v3 = (*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v0 + 32))(
         a1: v0,
         a2: "-defaultgamedir",
         a3: "hl2");
  v4 = (const char *)(*v2)(a1: v1, a2: "-game", a3: v3);
  V_strncpy(pDest: modDir, pSrc: v4, maxLen: 260);
  strchr(string: (unsigned __int8 *)modDir, chr: 0x2Fu);
  if ( v5 != 0 || (strchr(string: (unsigned __int8 *)modDir, chr: 0x5Cu), v6 != 0) )
  {
    V_StripLastDir(dirName: modDir, maxlen: 260);
    v7 = _V_strlen(str: modDir);
    V_strncpy(pDest: modDir, pSrc: &v4[v7], maxLen: 260 - v7);
  }
  return modDir;
}

//------------------------------------------------------------------------------
// Address: 0x100022A0
// Name: bool IsLocalClientConnectedToServer(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsLocalClientConnectedToServer()
{
  IVEngineClient *m_pIVEngineClient; // ecx
  BOOL result; // eax

  result = false;
  if ( g_pMatchExtensions != nullptr )
  {
    m_pIVEngineClient = g_pMatchExtensions->m_exts.m_pIVEngineClient;
    if ( m_pIVEngineClient != nullptr
      && (m_pIVEngineClient->IsConnected(this: m_pIVEngineClient)
       || g_pMatchExtensions->m_exts.m_pIVEngineClient->IsDrawingLoadingImage(this: g_pMatchExtensions->m_exts.m_pIVEngineClient)
       || g_pMatchExtensions->m_exts.m_pIVEngineClient->IsTransitioningToLoad(this: g_pMatchExtensions->m_exts.m_pIVEngineClient)) )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002020
// Name: __CreateCMatchFrameworkIMatchFramework_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMatchFramework *__cdecl _CreateCMatchFrameworkIMatchFramework_interface()
{
  return &g_MatchFramework;
}

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x10006C70
// Name: public: class IEngineVoice __near * CMatchExtensions::GetIEngineVoice(void)
// Source: json
//------------------------------------------------------------------------------
IEngineVoice *__thiscall CMatchExtensions::GetIEngineVoice(CMatchExtensions *this)
{
  return this->m_exts.m_pIEngineVoice;
}

//------------------------------------------------------------------------------
// Address: 0x10006CA0
// Name: InternalFactory
// Source: json
//------------------------------------------------------------------------------
void *__cdecl InternalFactory(const char *pName, int *pReturnCode)
{
  void *result; // eax
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  if ( pReturnCode != nullptr )
    *pReturnCode = 0;
  if ( s_pfnDelegateFactory == nullptr || (result = s_pfnDelegateFactory(a1: pName, a2: pReturnCode)) == nullptr )
  {
    FactoryThis = Sys_GetFactoryThis();
    result = FactoryThis(a1: pName, a2: pReturnCode);
    if ( result == nullptr )
    {
      if ( pReturnCode != nullptr )
        *pReturnCode = 1;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006CF0
// Name: public: virtual bool CMatchFramework::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatchFramework::Connect(CMatchFramework *this, void *(__cdecl *factory)(const char *, int *))
{
  MatchExtInterface_t *i; // esi
  void *v3; // eax

  s_pfnDelegateFactory = factory;
  factory = InternalFactory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  for ( i = s_table_0; i->m_szName != nullptr; ++i )
  {
    if ( !i->m_bConnected )
    {
      v3 = factory(a1: i->m_szName, a2: nullptr);
      if ( v3 != nullptr )
      {
        g_pMatchExtensions->RegisterExtensionInterface(this: g_pMatchExtensions, a2: i->m_szName, a3: v3);
        i->m_bConnected = true;
      }
    }
  }
  s_pfnDelegateFactory = nullptr;
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: true,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  SteamApiContext_Init();
  if ( g_pPlayerManager != nullptr )
    PlayerManager::OnGameUsersChanged(this: g_pPlayerManager);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10006DC0
// Name: public: virtual void CMatchFramework::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10006E20
// Name: public: virtual void __near * CMatchFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMatchFramework *__thiscall CMatchFramework::QueryInterface(CMatchFramework *this, const char *pInterfaceName)
{
  return _V_stricmp(s1: pInterfaceName, s2: "MATCHFRAMEWORK_001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10006E50
// Name: char const __near * COM_GetModDirectory(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl COM_GetModDirectory()
{
  int v0; // edi
  int *v1; // ebx
  int v2; // esi
  int v3; // eax
  const char *v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax

  if ( _V_strlen(str: modDir) != 0 )
    return modDir;
  v0 = _CommandLine();
  v1 = (int *)_CommandLine();
  v2 = *v1;
  v3 = (*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v0 + 32))(
         a1: v0,
         a2: "-defaultgamedir",
         a3: "hl2");
  v4 = (const char *)(*(int (__thiscall **)(int *, const char *, int))(v2 + 32))(a1: v1, a2: "-game", a3: v3);
  V_strncpy(pDest: modDir, pSrc: v4, maxLen: 260);
  strchr(string: (unsigned __int8 *)modDir, chr: 0x2Fu);
  if ( v5 != 0 || (strchr(string: (unsigned __int8 *)modDir, chr: 0x5Cu), v6 != 0) )
  {
    V_StripLastDir(dirName: modDir, maxlen: 260);
    v7 = _V_strlen(str: modDir);
    V_strncpy(pDest: modDir, pSrc: &v4[v7], maxLen: 260 - v7);
  }
  return modDir;
}

//------------------------------------------------------------------------------
// Address: 0x10006F10
// Name: bool IsLocalClientConnectedToServer(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsLocalClientConnectedToServer()
{
  IVEngineClient *m_pIVEngineClient; // ecx
  BOOL result; // eax

  result = false;
  if ( g_pMatchExtensions != nullptr )
  {
    m_pIVEngineClient = g_pMatchExtensions->m_exts.m_pIVEngineClient;
    if ( m_pIVEngineClient != nullptr
      && (m_pIVEngineClient->IsConnected(this: m_pIVEngineClient)
       || g_pMatchExtensions->m_exts.m_pIVEngineClient->IsDrawingLoadingImage(this: g_pMatchExtensions->m_exts.m_pIVEngineClient)
       || g_pMatchExtensions->m_exts.m_pIVEngineClient->IsTransitioningToLoad(this: g_pMatchExtensions->m_exts.m_pIVEngineClient)) )
    {
      return true;
    }
  }
  return result;
}

} // namespace matchmaking

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

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
// Address: 0x100056B0
// Name: public: class IEngineVoice __near * CMatchExtensions::GetIEngineVoice(void)
// Source: json
//------------------------------------------------------------------------------
IEngineVoice *__thiscall CMatchExtensions::GetIEngineVoice(CMatchExtensions *this)
{
  return this->m_exts.m_pIEngineVoice;
}

//------------------------------------------------------------------------------
// Address: 0x100056D0
// Name: InternalFactory
// Source: json
//------------------------------------------------------------------------------
void *__cdecl InternalFactory(const char *pName, int *pReturnCode)
{
  void *result; // eax
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  if ( pReturnCode != nullptr )
    *pReturnCode = 0;
  if ( s_pfnDelegateFactory == nullptr || (result = s_pfnDelegateFactory(a1: pName, a2: pReturnCode)) == nullptr )
  {
    FactoryThis = Sys_GetFactoryThis();
    result = FactoryThis(a1: pName, a2: pReturnCode);
    if ( result == nullptr )
    {
      if ( pReturnCode != nullptr )
        *pReturnCode = 1;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005720
// Name: public: virtual bool CMatchFramework::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatchFramework::Connect(CMatchFramework *this, void *(__cdecl *factory)(const char *, int *))
{
  MatchExtInterface_t *i; // esi
  void *v3; // eax
  CServerManager *v4; // ecx

  s_pfnDelegateFactory = factory;
  factory = InternalFactory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  for ( i = s_table_0; i->m_szName != nullptr; ++i )
  {
    if ( !i->m_bConnected )
    {
      v3 = factory(a1: i->m_szName, a2: nullptr);
      if ( v3 != nullptr )
      {
        g_pMatchExtensions->RegisterExtensionInterface(this: g_pMatchExtensions, a2: i->m_szName, a3: v3);
        i->m_bConnected = true;
      }
    }
  }
  s_pfnDelegateFactory = nullptr;
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: true,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  SteamApiContext_Shutdown(this: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100057E0
// Name: public: virtual void CMatchFramework::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::Disconnect(CMatchFramework *this)
{
  bool *p_m_bConnected; // esi
  void *v2; // eax

  SteamApiContext_Shutdown((CServerManager *)this);
  if ( s_table_0[0].m_szName != nullptr )
  {
    p_m_bConnected = &s_table_0[0].m_bConnected;
    do
    {
      if ( *p_m_bConnected )
      {
        v2 = (void *)(*((int (__thiscall **)(CMatchExtensions *))p_m_bConnected - 1))(a1: g_pMatchExtensions);
        g_pMatchExtensions->UnregisterExtensionInterface(
          this: g_pMatchExtensions,
          a2: *((const char **)p_m_bConnected - 2),
          a3: v2);
        *p_m_bConnected = false;
      }
      p_m_bConnected += 12;
    }
    while ( *((_DWORD *)p_m_bConnected - 2) != 0 );
  }
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x10005840
// Name: public: virtual void __near * CMatchFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMatchFramework *__thiscall CMatchFramework::QueryInterface(CMatchFramework *this, const char *pInterfaceName)
{
  return _V_stricmp(s1: pInterfaceName, s2: "MATCHFRAMEWORK_001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10005870
// Name: char const __near * COM_GetModDirectory(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl COM_GetModDirectory()
{
  int v0; // edi
  int *v1; // ebx
  int v2; // esi
  int v3; // eax
  const char *v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax

  if ( _V_strlen(str: modDir) != 0 )
    return modDir;
  v0 = _CommandLine();
  v1 = (int *)_CommandLine();
  v2 = *v1;
  v3 = (*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v0 + 32))(
         a1: v0,
         a2: "-defaultgamedir",
         a3: "hl2");
  v4 = (const char *)(*(int (__thiscall **)(int *, const char *, int))(v2 + 32))(a1: v1, a2: "-game", a3: v3);
  V_strncpy(pDest: modDir, pSrc: v4, maxLen: 260);
  strchr(string: (unsigned __int8 *)modDir, chr: 0x2Fu);
  if ( v5 != 0 || (strchr(string: (unsigned __int8 *)modDir, chr: 0x5Cu), v6 != 0) )
  {
    V_StripLastDir(dirName: modDir, maxlen: 260);
    v7 = _V_strlen(str: modDir);
    V_strncpy(pDest: modDir, pSrc: &v4[v7], maxLen: 260 - v7);
  }
  return modDir;
}

//------------------------------------------------------------------------------
// Address: 0x10005930
// Name: bool IsLocalClientConnectedToServer(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsLocalClientConnectedToServer()
{
  IVEngineClient *m_pIVEngineClient; // ecx
  BOOL result; // eax

  result = false;
  if ( g_pMatchExtensions != nullptr )
  {
    m_pIVEngineClient = g_pMatchExtensions->m_exts.m_pIVEngineClient;
    if ( m_pIVEngineClient != nullptr
      && (m_pIVEngineClient->IsConnected(this: m_pIVEngineClient)
       || g_pMatchExtensions->m_exts.m_pIVEngineClient->IsDrawingLoadingImage(this: g_pMatchExtensions->m_exts.m_pIVEngineClient)
       || g_pMatchExtensions->m_exts.m_pIVEngineClient->IsTransitioningToLoad(this: g_pMatchExtensions->m_exts.m_pIVEngineClient)) )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005A30
// Name: public: virtual void CMatchFramework::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::ApplySettings(CMatchFramework *this, KeyValues *keyValues)
{
  g_pMatchExtensions->m_exts.m_pIServerGameDLL->ApplyGameSettings(
    this: g_pMatchExtensions->m_exts.m_pIServerGameDLL,
    a2: keyValues);
}

//------------------------------------------------------------------------------
// Address: 0x10005C20
// Name: public: virtual bool CMatchFramework::IsOnlineGame(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatchFramework::IsOnlineGame(CMatchFramework *this)
{
  IMatchSession *v1; // esi
  KeyValues *v2; // eax
  const char *String; // eax
  bool result; // al

  v1 = this->GetMatchSession(this);
  result = false;
  if ( v1 != nullptr && v1->GetSessionSystemData(this: v1) != 0 )
  {
    v2 = v1->GetSessionSettings(this: v1);
    if ( v2 != nullptr )
    {
      String = KeyValues::GetString(this: v2, keyName: "system/network", defaultValue: nullptr);
      if ( String != nullptr && _V_stricmp(s1: "LIVE", s2: String) == 0 )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005C80
// Name: public: virtual void CMatchFramework::UpdateTeamProperties(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::UpdateTeamProperties(CMatchFramework *this, KeyValues *pTeamProperties)
{
  IMatchSession *v3; // edi
  IMatchTitleGameSettingsMgr *v4; // eax
  IMatchTitleGameSettingsMgr *v5; // esi
  int v6; // eax

  v3 = this->GetMatchSession(this);
  v4 = this->GetMatchTitleGameSettingsMgr(this);
  v5 = v4;
  if ( v3 != nullptr && v4 != nullptr )
  {
    v6 = (int)v3->GetSessionSettings(this: v3);
    v5->UpdateTeamProperties(this: v5, a2: (KeyValues *)v6, a3: pTeamProperties);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100056C0
// Name: __CreateCMatchFrameworkIMatchFramework_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMatchFramework *__cdecl _CreateCMatchFrameworkIMatchFramework_interface()
{
  return &g_MatchFramework;
}

//------------------------------------------------------------------------------
// Address: 0x10005A50
// Name: JoinInviteSession
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void JoinInviteSession()
{
  KeyValues *v0; // eax
  KeyValues *v1; // esi
  KeyValues *v2; // esi

  s_bInviteSessionDelayedJoin = false;
  if ( s_InviteInfo != 0 )
  {
    if ( g_pMatchExtensions->m_exts.m_pIVEngineClient->IsDrawingLoadingImage(this: g_pMatchExtensions->m_exts.m_pIVEngineClient)
      || g_pMatchEventsSubscription != nullptr && g_pMatchEventsSubscription->m_bBroadcasting )
    {
      s_bInviteSessionDelayedJoin = true;
    }
    else
    {
      DevMsg(a1: "JoinInviteSession: sessionid = %llx\n", s_InviteInfo);
      s_nInviteConfirmed = -1;
      v0 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v0 != nullptr
        && (v1 = KeyValues::KeyValues(this: v0, setName: "OnInvite")) != nullptr
        && (KeyValues::SetUint64(this: v1, keyName: "sessionid", value: s_InviteInfo),
            KeyValues::SetString(this: v1, keyName: "action", value: "storage"),
            KeyValues::SetPtr(this: v1, keyName: "confirmed", value: &s_nInviteConfirmed),
            g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v1),
            s_nInviteConfirmed != -1) )
      {
        DevMsg(a1: "JoinInviteSession: waiting for storage device selection...\n");
      }
      else
      {
        DevMsg(a1: "JoinInviteSession: verifying eligibility...\n");
        DevMsg(a1: "JoinInviteSession: connecting...\n");
        v2 = KeyValues::FromString(
               szName: "settings",
               szStringVal: " system {  network LIVE  }  options {  action joinsession  } ",
               ppEndOfParse: nullptr);
        KeyValues::SetUint64(this: v2, keyName: "options/sessionid", value: s_InviteInfo);
        _V_memset(dest: &s_InviteInfo, fill: 0, count: 8);
        g_pMatchFramework->MatchSession(this: g_pMatchFramework, a2: v2);
        if ( v2 != nullptr )
          KeyValues::deleteThis(this: v2);
      }
    }
  }
}

} // namespace matchmaking_ds
