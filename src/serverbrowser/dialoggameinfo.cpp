// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: serverbrowser/dialoggameinfo.cpp
// Functions: 47
// ============================================================

#include "serverbrowser\dialoggameinfo.h"

//------------------------------------------------------------------------------
// Address: 0x10002990
// Name: private: virtual void CCallback<class CDialogGameInfo,struct PersonaStateChange_t,0>::Run(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CDialogGameInfo,PersonaStateChange_t,0>::Run(
        CCallback<CBaseGamesPage,FavoritesListChanged_t,0> *this,
        void *pvParam)
{
  ((void (__thiscall *)(char *, void *))LODWORD(this->m_Func))(
    a1: (char *)this->m_pObj + DWORD1(this->m_Func),
    a2: pvParam);
}

//------------------------------------------------------------------------------
// Address: 0x100029B0
// Name: private: virtual void CCallback<class CBaseGamesPage,struct FavoritesListChanged_t,0>::Run(void __near *,bool,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CBaseGamesPage,FavoritesListChanged_t,0>::Run(
        CCallback<CBaseGamesPage,FavoritesListChanged_t,0> *this,
        void *pvParam,
        bool __formal,
        unsigned __int64 a4)
{
  ((void (__thiscall *)(char *, void *))LODWORD(this->m_Func))(
    a1: (char *)this->m_pObj + DWORD1(this->m_Func),
    a2: pvParam);
}

//------------------------------------------------------------------------------
// Address: 0x100029D0
// Name: private: virtual int CCallback<class CBaseGamesPage,struct FavoritesListChanged_t,0>::GetCallbackSizeBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCallback<CBaseGamesPage,FavoritesListChanged_t,0>::GetCallbackSizeBytes(
        CCallback<CBaseGamesPage,FavoritesListChanged_t,0> *this)
{
  return 24;
}

//------------------------------------------------------------------------------
// Address: 0x100029E0
// Name: public: void CCallback<class CBaseGamesPage,struct FavoritesListChanged_t,0>::Register(class CBaseGamesPage __near *,void (CBaseGamesPage::*)(struct FavoritesListChanged_t __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CBaseGamesPage,FavoritesListChanged_t,0>::Register(
        CCallback<CBaseGamesPage,FavoritesListChanged_t,0> *this,
        CBaseGamesPage *pObj,
        __int128 func)
{
  __int64 v4; // xmm0_8

  if ( pObj != nullptr && (_DWORD)func != 0 )
  {
    if ( (this->m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: this);
    *(_QWORD *)&this->m_Func = func;
    v4 = *((_QWORD *)&func + 1);
    this->m_pObj = pObj;
    *((_QWORD *)&this->m_Func + 1) = v4;
    _SteamAPI_RegisterCallback(a1: this, a2: 502);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FE80
// Name: public: static char const __near * CDialogGameInfo::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDialogGameInfo::GetPanelClassName()
{
  return "CDialogGameInfo";
}

//------------------------------------------------------------------------------
// Address: 0x1000FEA0
// Name: public: virtual void CDialogGameInfo::SendPlayerQuery(unsigned int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::SendPlayerQuery(CDialogGameInfo *this, unsigned int unIP, int usQueryPort)
{
  ISteamMatchmakingServers *m_pSteamMatchmakingServers; // ecx

  m_pSteamMatchmakingServers = steamapicontext->m_pSteamMatchmakingServers;
  if ( m_pSteamMatchmakingServers != nullptr )
  {
    if ( this->m_hPlayersQuery != -1 )
      m_pSteamMatchmakingServers->CancelServerQuery(this: m_pSteamMatchmakingServers, a2: this->m_hPlayersQuery);
    this->m_hPlayersQuery = steamapicontext->m_pSteamMatchmakingServers->PlayerDetails(
                              this: steamapicontext->m_pSteamMatchmakingServers,
                              a2: unIP,
                              a3: usQueryPort,
                              a4: &this->ISteamMatchmakingPlayersResponse);
    this->m_bPlayerListUpdatePending = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FF00
// Name: public: unsigned __int64 CDialogGameInfo::GetAssociatedFriend(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CDialogGameInfo::GetAssociatedFriend(CDialogGameInfo *this)
{
  return this->m_SteamIDFriend;
}

//------------------------------------------------------------------------------
// Address: 0x1000FF10
// Name: protected: virtual void CDialogGameInfo::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::PerformLayout(CDialogGameInfo *this)
{
  char *m_szServerName; // eax
  CDialogGameInfo_vtbl *v3; // edi
  char *ConnectionAddressString; // eax
  bool v5; // zf
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // eax
  void (__thiscall *SetEnabled)(vgui::Panel *, bool); // eax
  void (__thiscall *SetText_2)(vgui::Label *, const char *); // eax
  const char *v9; // [esp-4h] [ebp-8Ch]
  char buf[128]; // [esp+8h] [ebp-80h] BYREF

  vgui::Frame::PerformLayout(this);
  m_szServerName = this->m_Server.m_szServerName;
  if ( this->m_Server.m_szServerName[0] == 0 )
    m_szServerName = servernetadr_t::GetConnectionAddressString(this: &this->m_Server.m_NetAdr);
  this->SetControlString_2(this, a2: "ServerText", a3: m_szServerName);
  this->SetControlString_2(this, a2: "GameText", a3: this->m_Server.m_szGameDescription);
  this->SetControlString_2(this, a2: "MapText", a3: this->m_Server.m_szMap);
  this->SetControlString_2(this, a2: "GameTags", a3: this->m_Server.m_szGameTags);
  if ( this->m_Server.m_bHadSuccessfulResponse )
  {
    if ( this->m_Server.m_bSecure )
      this->SetControlString_2(this, a2: "SecureText", a3: "#ServerBrowser_Secure");
    else
      this->SetControlString_2(this, a2: "SecureText", a3: "#ServerBrowser_NotSecure");
  }
  else
  {
    this->SetControlString_2(this, a2: "SecureText", a3: defaultValue);
  }
  if ( this->m_Server.m_nMaxPlayers <= 0 )
    buf[0] = 0;
  else
    V_snprintf(pDest: buf, maxLen: 128, pFormat: "%d / %d", this->m_Server.m_nPlayers, this->m_Server.m_nMaxPlayers);
  this->SetControlString_2(this, a2: "PlayersText", a3: buf);
  if ( this->m_Server.m_NetAdr.m_unIP != 0 && this->m_Server.m_NetAdr.m_usQueryPort != 0 )
  {
    v3 = this->vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable;
    ConnectionAddressString = servernetadr_t::GetConnectionAddressString(this: &this->m_Server.m_NetAdr);
    v3->SetControlString_2(this, a2: "ServerIPText", a3: ConnectionAddressString);
    this->m_pConnectButton->SetEnabled(this: this->m_pConnectButton, a2: true);
    v5 = !this->m_pAutoRetry->IsSelected(this: this->m_pAutoRetry);
    SetVisible = this->m_pAutoRetryAlert->SetVisible;
    if ( !v5 )
    {
      ((void (__stdcall *)(int))SetVisible)(a1: 1);
      ((void (__stdcall *)(int))this->m_pAutoRetryJoin->SetVisible)(a1: 1);
      goto LABEL_18;
    }
    ((void (__stdcall *)(_DWORD))SetVisible)(a1: 0);
    SetEnabled = this->m_pAutoRetryJoin->SetVisible;
  }
  else
  {
    this->SetControlString_2(this, a2: "ServerIPText", a3: defaultValue);
    SetEnabled = this->m_pConnectButton->SetEnabled;
  }
  ((void (__stdcall *)(_DWORD))SetEnabled)(a1: 0);
LABEL_18:
  if ( this->m_Server.m_bHadSuccessfulResponse )
  {
    V_snprintf(pDest: buf, maxLen: 128, pFormat: "%d", this->m_Server.m_nPing);
    this->SetControlString_2(this, a2: "PingText", a3: buf);
  }
  else
  {
    this->SetControlString_2(this, a2: "PingText", a3: defaultValue);
  }
  if ( !this->m_pAutoRetry->IsSelected(this: this->m_pAutoRetry) )
  {
    if ( this->m_bServerFull )
    {
      v9 = "#ServerBrowser_CouldNotConnectServerFull";
    }
    else if ( this->m_bServerNotResponding )
    {
      v9 = "#ServerBrowser_ServerNotResponding";
    }
    else
    {
      v9 = defaultValue;
    }
    goto LABEL_32;
  }
  if ( this->m_Server.m_nPlayers < this->m_Server.m_nMaxPlayers )
  {
    v9 = "#ServerBrowser_PressJoinToConnect";
LABEL_32:
    ((void (__stdcall *)(const char *))this->m_pInfoLabel->SetText_2)(a1: v9);
    goto LABEL_33;
  }
  v5 = !this->m_pAutoRetryJoin->IsSelected(this: this->m_pAutoRetryJoin);
  SetText_2 = this->m_pInfoLabel->SetText_2;
  if ( v5 )
    ((void (__stdcall *)(const char *))SetText_2)(a1: "#ServerBrowser_AlertWhenSlotIsFree");
  else
    ((void (__stdcall *)(const char *))SetText_2)(a1: "#ServerBrowser_JoinWhenSlotIsFree");
LABEL_33:
  if ( !this->m_Server.m_bHadSuccessfulResponse || this->m_Server.m_nPlayers + this->m_Server.m_nBotPlayers != 0 )
    this->m_pPlayerList->SetEmptyListText_2(this: this->m_pPlayerList, a2: "#ServerBrowser_ServerNotResponding");
  else
    this->m_pPlayerList->SetEmptyListText_2(this: this->m_pPlayerList, a2: "#ServerBrowser_ServerHasNoPlayers");
  this->m_pAutoRetry->SetVisible(this: this->m_pAutoRetry, a2: this->m_bShowAutoRetryToggle);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10010200
// Name: public: void CDialogGameInfo::Connect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::Connect(CDialogGameInfo *this)
{
  this->OnConnect(this);
}

//------------------------------------------------------------------------------
// Address: 0x10010210
// Name: protected: virtual void CDialogGameInfo::OnConnectToGame(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::OnConnectToGame(CDialogGameInfo *this, int ip, __int16 port)
{
  if ( this->m_Server.m_NetAdr.m_unIP == ip && this->m_Server.m_NetAdr.m_usConnectionPort == port )
    this->Close(this);
}

//------------------------------------------------------------------------------
// Address: 0x10010240
// Name: private: void CDialogGameInfo::ShowAutoRetryOptions(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::ShowAutoRetryOptions(CDialogGameInfo *this, int state)
{
  char v2; // bl
  int v4; // edi
  void (__thiscall *LoadControlSettings)(vgui::EditablePanel *, const char *, const char *, KeyValues *, KeyValues *); // eax
  int x; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  v2 = state;
  v4 = 60;
  if ( (_BYTE)state == 0 )
    v4 = -60;
  vgui::Panel::GetBounds(this, &x, &y, &wide, tall: &state);
  vgui::Panel::SetMinimumSize(this, wide: 416, tall: 340);
  LoadControlSettings = this->LoadControlSettings;
  if ( v2 != 0 )
    ((void (__stdcall *)(const char *, _DWORD, _DWORD, _DWORD))LoadControlSettings)(
      a1: "Servers/DialogGameInfo_AutoRetry.res",
      a2: 0,
      a3: 0,
      a4: 0);
  else
    ((void (__stdcall *)(const char *, _DWORD, _DWORD, _DWORD))LoadControlSettings)(
      a1: "Servers/DialogGameInfo.res",
      a2: 0,
      a3: 0,
      a4: 0);
  vgui::Panel::SetBounds(this, x, y, wide, tall: v4 + state);
  this->PerformLayout(this);
  this->m_pAutoRetryAlert->SetSelected(this: this->m_pAutoRetryAlert, a2: true);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10010300
// Name: private: void CDialogGameInfo::RequestInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::RequestInfo(CDialogGameInfo *this)
{
  if ( steamapicontext->m_pSteamMatchmakingServers != nullptr && this->m_iRequestRetry == 0 )
  {
    this->m_iRequestRetry = g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) + 10000;
    if ( this->m_hPingQuery != -1 )
      steamapicontext->m_pSteamMatchmakingServers->CancelServerQuery(
        this: steamapicontext->m_pSteamMatchmakingServers,
        a2: this->m_hPingQuery);
    this->m_hPingQuery = steamapicontext->m_pSteamMatchmakingServers->PingServer(
                           this: steamapicontext->m_pSteamMatchmakingServers,
                           a2: this->m_Server.m_NetAdr.m_unIP,
                           a3: this->m_Server.m_NetAdr.m_usQueryPort,
                           a4: &this->ISteamMatchmakingPingResponse);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010380
// Name: protected: virtual void CDialogGameInfo::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::OnTick(CDialogGameInfo *this)
{
  if ( this->m_iRequestRetry != 0 && this->m_iRequestRetry < g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) )
  {
    this->m_iRequestRetry = 0;
    CDialogGameInfo::RequestInfo(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100103C0
// Name: public: class gameserveritem_t __near & gameserveritem_t::operator=(class gameserveritem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
gameserveritem_t *__thiscall gameserveritem_t::operator=(gameserveritem_t *this, const gameserveritem_t *__that)
{
  gameserveritem_t *result; // eax
  char *m_szGameDir; // edi
  int v4; // esi
  int i; // edx
  char *m_szMap; // edi
  int j; // edx
  char *m_szGameDescription; // edi
  int k; // edx
  char *m_szServerName; // edi
  int m; // edx
  char *m_szGameTags; // edi
  int n; // edx

  result = this;
  this->m_NetAdr = __that->m_NetAdr;
  this->m_nPing = __that->m_nPing;
  this->m_bHadSuccessfulResponse = __that->m_bHadSuccessfulResponse;
  this->m_bDoNotRefresh = __that->m_bDoNotRefresh;
  m_szGameDir = this->m_szGameDir;
  v4 = (char *)__that - (char *)this;
  for ( i = 32; i != 0; --i )
  {
    *m_szGameDir = m_szGameDir[v4];
    ++m_szGameDir;
  }
  m_szMap = this->m_szMap;
  for ( j = 32; j != 0; --j )
  {
    *m_szMap = m_szMap[v4];
    ++m_szMap;
  }
  m_szGameDescription = this->m_szGameDescription;
  for ( k = 64; k != 0; --k )
  {
    *m_szGameDescription = m_szGameDescription[v4];
    ++m_szGameDescription;
  }
  this->m_nAppID = __that->m_nAppID;
  this->m_nPlayers = __that->m_nPlayers;
  this->m_nMaxPlayers = __that->m_nMaxPlayers;
  this->m_nBotPlayers = __that->m_nBotPlayers;
  this->m_bPassword = __that->m_bPassword;
  this->m_bSecure = __that->m_bSecure;
  this->m_ulTimeLastPlayed = __that->m_ulTimeLastPlayed;
  this->m_nServerVersion = __that->m_nServerVersion;
  m_szServerName = this->m_szServerName;
  for ( m = 64; m != 0; --m )
  {
    *m_szServerName = m_szServerName[v4];
    ++m_szServerName;
  }
  m_szGameTags = this->m_szGameTags;
  for ( n = 128; n != 0; --n )
  {
    *m_szGameTags = m_szGameTags[v4];
    ++m_szGameTags;
  }
  this->m_steamID.m_steamid.m_unAll64Bits = __that->m_steamID.m_steamid.m_unAll64Bits;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100104E0
// Name: public: virtual void CDialogGameInfo::ServerFailedToRespond(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::ServerFailedToRespond(CDialogGameInfo *this)
{
  char *v1; // esi

  if ( LOBYTE(this->m_pinSibling.m_iPanelID) == 0 )
    HIBYTE(this->m_nPinDeltaX) = 1;
  v1 = (char *)this - 532;
  (*(void (__thiscall **)(char *, _DWORD, _DWORD))(*((_DWORD *)this - 133) + 264))(a1: (char *)this - 532, a2: 0, a3: 0);
  (*(void (__thiscall **)(char *))(*(_DWORD *)v1 + 16))(a1: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10010520
// Name: private: void CDialogGameInfo::ApplyConnectCommand(class gameserveritem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::ApplyConnectCommand(CDialogGameInfo *this, const gameserveritem_t *server)
{
  char *ConnectionAddressString; // eax
  char command[256]; // [esp+0h] [ebp-100h] BYREF

  if ( this->m_szPassword[0] != 0 )
  {
    V_snprintf(pDest: command, maxLen: 256, pFormat: "password \"%s\"\n", this->m_szPassword);
    g_pRunGameEngine->AddTextCommand(this: g_pRunGameEngine, a2: command);
  }
  ConnectionAddressString = servernetadr_t::GetConnectionAddressString(this: &server->m_NetAdr);
  V_snprintf(pDest: command, maxLen: 256, pFormat: "connect %s\n", ConnectionAddressString);
  g_pRunGameEngine->AddTextCommand(this: g_pRunGameEngine, a2: command);
}

//------------------------------------------------------------------------------
// Address: 0x100105A0
// Name: private: void CDialogGameInfo::ConstructConnectArgs(char __near *,int,class gameserveritem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::ConstructConnectArgs(
        CDialogGameInfo *this,
        char *pchOptions,
        int cchOptions,
        const gameserveritem_t *server)
{
  char *ConnectionAddressString; // eax
  char *m_szPassword; // ebx

  ConnectionAddressString = servernetadr_t::GetConnectionAddressString(this: &server->m_NetAdr);
  V_snprintf(pDest: pchOptions, maxLen: cchOptions, pFormat: " +connect %s", ConnectionAddressString);
  m_szPassword = this->m_szPassword;
  if ( *m_szPassword != 0 )
  {
    V_strncat(pDest: pchOptions, pSrc: " +password \"", destBufferSize: cchOptions, max_chars_to_copy: -1);
    V_strncat(pDest: pchOptions, pSrc: m_szPassword, destBufferSize: cchOptions, max_chars_to_copy: -1);
    V_strncat(pDest: pchOptions, pSrc: "\"", destBufferSize: cchOptions, max_chars_to_copy: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010610
// Name: private: void CDialogGameInfo::ConnectToServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::ConnectToServer(CDialogGameInfo *this)
{
  bool v2; // zf
  vgui::Panel *v3; // eax
  CVACBannedConnRefusedDialog *v4; // edi
  unsigned int v5; // eax
  CVACBannedConnRefusedDialog *v6; // eax
  CDialogServerPassword *v7; // eax
  CDialogServerPassword *v8; // edi
  char *m_szServerName; // eax
  void (__thiscall *InvalidateLayout)(vgui::Panel *, bool, bool); // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  __int32 v13; // eax
  __int32 v14; // eax
  vgui::MessageBox *v15; // eax
  vgui::MessageBox *v16; // eax
  vgui::MessageBox *v17; // eax
  vgui::MessageBox *v18; // eax
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *m_nAppID; // [esp+0h] [ebp-10Ch]
  gameserveritem_t *p_m_Server; // [esp+0h] [ebp-10Ch]
  char connectArgs[256]; // [esp+Ch] [ebp-100h] BYREF

  v2 = !this->m_Server.m_bSecure;
  this->m_bConnecting = false;
  if ( !v2 )
  {
    m_nAppID = (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)this->m_Server.m_nAppID;
    v3 = (vgui::Panel *)ServerBrowser();
    if ( CUtlBuffer::GetOverflow(this: v3, msglist: m_nAppID) )
    {
      v4 = (CVACBannedConnRefusedDialog *)operator new(nSize: 0x214u);
      if ( v4 != nullptr )
      {
        v5 = this->GetVParent(this);
        v6 = CVACBannedConnRefusedDialog::CVACBannedConnRefusedDialog(
               this: v4,
               hVParent: v5,
               name: "VACBannedConnRefusedDialog");
      }
      else
      {
        v6 = nullptr;
      }
      v6->Activate(this: v6);
      this->Close(this);
      return;
    }
  }
  if ( !this->m_Server.m_bPassword || this->m_szPassword[0] != 0 )
  {
    if ( this->m_Server.m_nPlayers >= this->m_Server.m_nMaxPlayers )
    {
      InvalidateLayout = this->InvalidateLayout;
      *(_WORD *)&this->m_bServerFull = 257;
      InvalidateLayout(this, a2: false, a3: false);
      return;
    }
    p_m_Server = &this->m_Server;
    if ( g_pRunGameEngine->IsRunning(this: g_pRunGameEngine) )
    {
      CDialogGameInfo::ApplyConnectCommand(this, server: p_m_Server);
LABEL_19:
      v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v11 != nullptr )
        v12 = KeyValues::KeyValues(this: v11, setName: "Close");
      else
        v12 = nullptr;
      ((void (__thiscall *)(CDialogGameInfo *, CDialogGameInfo *, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: this,
        a3: v12,
        a4: 0);
      return;
    }
    CDialogGameInfo::ConstructConnectArgs(this, pchOptions: connectArgs, cchOptions: 256, server: p_m_Server);
    v13 = g_pRunGameEngine->RunEngine(
            this: g_pRunGameEngine,
            a2: this->m_Server.m_nAppID,
            a3: this->m_Server.m_szGameDir,
            a4: connectArgs)
        - 1;
    if ( v13 != 0 )
    {
      v14 = v13 - 1;
      if ( v14 != 0 )
      {
        if ( v14 != 1 )
          goto LABEL_19;
        v15 = (vgui::MessageBox *)operator new(nSize: 0x234u);
        if ( v15 != nullptr )
        {
          v16 = vgui::MessageBox::MessageBox(
                  this: v15,
                  title: "#ServerBrowser_GameInfoTitle",
                  text: "#ServerBrowser_NotInitialized",
                  parent: nullptr);
LABEL_31:
          v16->DoModal_2(this: v16, a2: nullptr);
          this->SetVisible(this, a2: false);
          return;
        }
      }
      else
      {
        v17 = (vgui::MessageBox *)operator new(nSize: 0x234u);
        if ( v17 != nullptr )
        {
          v16 = vgui::MessageBox::MessageBox(
                  this: v17,
                  title: "#ServerBrowser_GameInfoTitle",
                  text: "#ServerBrowser_AppNotFound",
                  parent: nullptr);
          goto LABEL_31;
        }
      }
    }
    else
    {
      v18 = (vgui::MessageBox *)operator new(nSize: 0x234u);
      if ( v18 != nullptr )
      {
        v16 = vgui::MessageBox::MessageBox(
                this: v18,
                title: "#ServerBrowser_GameInfoTitle",
                text: "#ServerBrowser_ModNotInstalled",
                parent: nullptr);
        goto LABEL_31;
      }
    }
    v16 = nullptr;
    goto LABEL_31;
  }
  v7 = (CDialogServerPassword *)operator new(nSize: 0x224u);
  if ( v7 != nullptr )
    v8 = CDialogServerPassword::CDialogServerPassword(this: v7, parent: this);
  else
    v8 = nullptr;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  m_szServerName = this->m_Server.m_szServerName;
  if ( this->m_Server.m_szServerName[0] == 0 )
    m_szServerName = servernetadr_t::GetConnectionAddressString(this: &this->m_Server.m_NetAdr);
  CDialogServerPassword::Activate(this: v8, serverName: m_szServerName, serverID: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10010860
// Name: protected: virtual void CDialogGameInfo::OnJoinServerWithPassword(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::OnJoinServerWithPassword(CDialogGameInfo *this, const char *password)
{
  V_strncpy(pDest: this->m_szPassword, pSrc: password, maxLen: 64);
  this->OnConnect(this);
}

//------------------------------------------------------------------------------
// Address: 0x10010890
// Name: public: virtual void CDialogGameInfo::ClearPlayerList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::ClearPlayerList(CDialogGameInfo *this)
{
  this->m_pPlayerList->DeleteAllItems(this: this->m_pPlayerList);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100108B0
// Name: public: virtual void CDialogGameInfo::AddPlayerToList(char const __near *,int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::AddPlayerToList(
        CDialogGameInfo *this,
        const char *playerName,
        int score,
        float timePlayedSeconds)
{
  bool v4; // zf
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  int v7; // eax
  int v8; // ecx
  int v9; // [esp-8h] [ebp-4Ch]
  char buf[64]; // [esp+0h] [ebp-44h] BYREF
  CDialogGameInfo *v11; // [esp+40h] [ebp-4h]

  v4 = this->m_CallbackPersonaStateChange.m_nCallbackFlags == 0;
  v11 = this;
  if ( !v4 )
  {
    this->m_CallbackPersonaStateChange.m_nCallbackFlags = 0;
    (*(void (__thiscall **)(int))(*(_DWORD *)this->_panelName.m_Storage.m_nActualLength + 968))(a1: this->_panelName.m_Storage.m_nActualLength);
  }
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "player");
  else
    v6 = nullptr;
  KeyValues::SetString(this: v6, keyName: "PlayerName", value: playerName);
  KeyValues::SetInt(this: v6, keyName: "Score", value: score);
  KeyValues::SetInt(this: v6, keyName: "TimeSec", value: (int)timePlayedSeconds);
  v7 = (int)timePlayedSeconds / 60 / 60;
  v8 = (int)timePlayedSeconds / 60 % 60;
  buf[0] = 0;
  v9 = (int)timePlayedSeconds % 60;
  if ( v7 != 0 )
  {
    V_snprintf(pDest: buf, maxLen: 64, pFormat: "%dh %dm %ds", v7, v8, v9);
  }
  else if ( v8 != 0 )
  {
    V_snprintf(pDest: buf, maxLen: 64, pFormat: "%dm %ds", v8, v9);
  }
  else
  {
    V_snprintf(pDest: buf, maxLen: 64, pFormat: "%ds", v9);
  }
  KeyValues::SetString(this: v6, keyName: "Time", value: buf);
  (*(void (__thiscall **)(int, KeyValues *, _DWORD, _DWORD, int))(*(_DWORD *)v11->_panelName.m_Storage.m_nActualLength
                                                                + 916))(
    a1: v11->_panelName.m_Storage.m_nActualLength,
    a2: v6,
    a3: 0,
    a4: 0,
    a5: 1);
  KeyValues::deleteThis(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100109F0
// Name: private: static int CDialogGameInfo::PlayerTimeColumnSortFunc(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CDialogGameInfo::PlayerTimeColumnSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *p1,
        const vgui::ListPanelItem *p2)
{
  int Int; // esi
  int v4; // eax

  Int = KeyValues::GetInt(this: p1->kv, keyName: "TimeSec", defaultValue: 0);
  v4 = KeyValues::GetInt(this: p2->kv, keyName: "TimeSec", defaultValue: 0);
  if ( Int <= v4 )
    return Int < v4;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10010A60
// Name: public: void CDialogGameInfo::Run(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::Run(CDialogGameInfo *this, const char *titleName)
{
  this->SetTitle_2(this, a2: "#ServerBrowser_GameInfoWithNameTitle", a3: true);
  this->SetDialogVariable_4(this, a2: "game", a3: titleName);
  CDialogGameInfo::RequestInfo(this);
  this->Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x10010AB0
// Name: public: void CDialogGameInfo::ChangeGame(int,int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::ChangeGame(
        CDialogGameInfo *this,
        int serverIP,
        unsigned __int16 queryPort,
        int connectionPort)
{
  gameserveritem_t *p_m_Server; // edi
  unsigned __int16 v6; // cx
  unsigned __int16 v7; // dx
  int savedregs; // [esp+8h] [ebp+0h]
  int savedregsa; // [esp+8h] [ebp+0h]

  p_m_Server = &this->m_Server;
  memset(dst: (int)&this->m_Server, value: nullptr, count: sizeof(this->m_Server));
  v6 = queryPort;
  v7 = connectionPort;
  p_m_Server->m_NetAdr.m_unIP = serverIP;
  p_m_Server->m_NetAdr.m_usQueryPort = v6;
  p_m_Server->m_NetAdr.m_usConnectionPort = v7;
  vgui::Panel::GetPos(this, x: &serverIP, y: &connectionPort);
  if ( this->m_Server.m_NetAdr.m_unIP != 0 && this->m_Server.m_NetAdr.m_usQueryPort != 0 )
  {
    vgui::Panel::SetMinimumSize(this, wide: 416, tall: 340);
    this->SetSizeable(this, a2: true);
    savedregs = 0;
    ((void (__thiscall *)(CDialogGameInfo *, const char *))this->LoadControlSettings)(
      a1: this,
      a2: "Servers/DialogGameInfo.res");
  }
  else
  {
    vgui::Panel::SetMinimumSize(this, wide: 0, tall: 0);
    this->SetSizeable(this, a2: false);
    savedregsa = 0;
    ((void (__thiscall *)(CDialogGameInfo *, const char *))this->LoadControlSettings)(
      a1: this,
      a2: "Servers/DialogGameInfo_SinglePlayer.res");
  }
  vgui::Panel::SetPos(this, x: serverIP, y: connectionPort);
  this->m_iRequestRetry = 0;
  CDialogGameInfo::RequestInfo(this);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10010BA0
// Name: public: void CDialogGameInfo::SetFriend(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::SetFriend(CDialogGameInfo *this, unsigned __int64 ulSteamIDFriend)
{
  const char *v3; // eax
  const char *v4; // eax
  unsigned __int16 m_usGamePort; // ax
  FriendGameInfo_t friendGameInfo; // [esp+Ch] [ebp-18h] BYREF

  this->SetTitle_2(this, a2: "#ServerBrowser_GameInfoWithNameTitle", a3: true);
  v3 = (const char *)((int (__thiscall *)(ISteamFriends *, _DWORD, _DWORD))steamapicontext->m_pSteamFriends->GetFriendPersonaName)(
                       a1: steamapicontext->m_pSteamFriends,
                       a2: ulSteamIDFriend,
                       a3: HIDWORD(ulSteamIDFriend));
  this->SetDialogVariable_4(this, a2: "game", a3: v3);
  v4 = (const char *)((int (__thiscall *)(ISteamFriends *, _DWORD, _DWORD))steamapicontext->m_pSteamFriends->GetFriendPersonaName)(
                       a1: steamapicontext->m_pSteamFriends,
                       a2: ulSteamIDFriend,
                       a3: HIDWORD(ulSteamIDFriend));
  this->SetDialogVariable_4(this, a2: "friend", a3: v4);
  BYTE6(friendGameInfo.m_steamIDLobby.m_steamid.m_unAll64Bits) &= 0xFu;
  this->m_SteamIDFriend = ulSteamIDFriend;
  HIBYTE(friendGameInfo.m_steamIDLobby.m_steamid.m_unAll64Bits) = 0;
  friendGameInfo.m_steamIDLobby.m_steamid.m_unAll64Bits &= 0xFFF0000000000000uLL;
  friendGameInfo.m_gameID.m_ulGameID = 0;
  if ( ((unsigned __int8 (__thiscall *)(ISteamFriends *, _DWORD, _DWORD, FriendGameInfo_t *))steamapicontext->m_pSteamFriends->GetFriendGamePlayed)(
         a1: steamapicontext->m_pSteamFriends,
         a2: ulSteamIDFriend,
         a3: HIDWORD(ulSteamIDFriend),
         a4: &friendGameInfo) != 0 )
  {
    m_usGamePort = friendGameInfo.m_usGamePort;
    if ( friendGameInfo.m_usQueryPort < 0xFFFEu )
      m_usGamePort = friendGameInfo.m_usQueryPort;
    CDialogGameInfo::ChangeGame(
      this,
      serverIP: friendGameInfo.m_unGameIP,
      queryPort: m_usGamePort,
      connectionPort: *(int *)&friendGameInfo.m_usGamePort);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010CA0
// Name: protected: virtual void CDialogGameInfo::OnConnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::OnConnect(CDialogGameInfo *this)
{
  void (__thiscall *InvalidateLayout)(vgui::Panel *, bool, bool); // edx

  InvalidateLayout = this->InvalidateLayout;
  this->m_bConnecting = true;
  *(_WORD *)&this->m_bServerNotResponding = 0;
  ((void (__stdcall *)(_DWORD, _DWORD))InvalidateLayout)(a1: 0, a2: 0);
  this->m_iRequestRetry = 0;
  CDialogGameInfo::RequestInfo(this);
}

//------------------------------------------------------------------------------
// Address: 0x10010CE0
// Name: protected: virtual void CDialogGameInfo::OnRefresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::OnRefresh(CDialogGameInfo *this)
{
  this->m_iRequestRetry = 0;
  CDialogGameInfo::RequestInfo(this);
}

//------------------------------------------------------------------------------
// Address: 0x10010CF0
// Name: protected: virtual void CDialogGameInfo::OnButtonToggled(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::OnButtonToggled(CDialogGameInfo *this, vgui::ToggleButton *panel)
{
  bool v3; // al

  if ( panel == this->m_pAutoRetry )
  {
    v3 = this->m_pAutoRetry->IsSelected(this: this->m_pAutoRetry);
    CDialogGameInfo::ShowAutoRetryOptions(this, state: v3);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10010D40
// Name: public: virtual void CDialogGameInfo::ServerResponded(class gameserveritem_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDialogGameInfo::ServerResponded(CDialogGameInfo *this@<ecx>, int a2@<esi>, gameserveritem_t *server)
{
  __int16 v4; // ax
  gameserveritem_t *v5; // ecx
  char *v6; // esi
  void (__thiscall *v7)(char *, _DWORD, _DWORD); // edx

  v4 = *((_WORD *)&this->vgui::Panel + 86);
  v5 = (gameserveritem_t *)((char *)&this->vgui::Panel + 172);
  if ( v4 == 0 || v4 == server->m_NetAdr.m_usConnectionPort )
  {
    *(_DWORD *)&this->m_OnConnectToGame_register = -1;
    gameserveritem_t::operator=(this: v5, __that: server);
    if ( LOBYTE(this->_panelName.m_Storage.m_nActualLength) != 0 )
    {
      v6 = (char *)this - 532;
      CDialogGameInfo::ConnectToServer(this: (CDialogGameInfo *)((char *)this - 532));
    }
    else if ( (*(unsigned __int8 (__thiscall **)(unsigned int, int))(*(_DWORD *)this->_vpanel + 1024))(
                a1: this->_vpanel,
                a2) != 0
           && server->m_nPlayers < server->m_nMaxPlayers )
    {
      g_pVGuiSurface->PlaySound(this: g_pVGuiSurface, a2: "Servers/game_ready.wav");
      v6 = (char *)this - 532;
      (*(void (__thiscall **)(char *))(*((_DWORD *)this - 133) + 1016))(a1: (char *)this - 532);
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)this->_panelName.m_Storage.m_Memory.m_nAllocationCount
                                                  + 1024))(a1: this->_panelName.m_Storage.m_Memory.m_nAllocationCount) != 0 )
        CDialogGameInfo::ConnectToServer(this: (CDialogGameInfo *)((char *)this - 532));
    }
    else
    {
      v6 = (char *)this - 532;
      (*(void (__thiscall **)(char *, unsigned int))(*((_DWORD *)this - 133) + 1124))(
        a1: (char *)this - 532,
        a2: server->m_NetAdr.m_unIP);
    }
    v7 = *(void (__thiscall **)(char *, _DWORD, _DWORD))(*(_DWORD *)v6 + 264);
    HIBYTE(this->m_nPinDeltaX) = 0;
    v7(a1: v6, a2: 0, a3: 0);
    (*(void (__thiscall **)(char *))(*(_DWORD *)v6 + 16))(a1: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010E40
// Name: private: virtual int CCallback<class CDialogGameInfo,struct PersonaStateChange_t,0>::GetCallbackSizeBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCallback<CDialogGameInfo,PersonaStateChange_t,0>::GetCallbackSizeBytes(
        CCallback<CDialogGameInfo,PersonaStateChange_t,0> *this)
{
  return 16;
}

//------------------------------------------------------------------------------
// Address: 0x10010E50
// Name: public: void CCallback<class CDialogGameInfo,struct PersonaStateChange_t,0>::Register(class CDialogGameInfo __near *,void (CDialogGameInfo::*)(struct PersonaStateChange_t __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CDialogGameInfo,PersonaStateChange_t,0>::Register(
        CCallback<CDialogGameInfo,PersonaStateChange_t,0> *this,
        CDialogGameInfo *pObj,
        __int128 func)
{
  __int64 v4; // xmm0_8

  if ( pObj != nullptr && (_DWORD)func != 0 )
  {
    if ( (this->m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: this);
    *(_QWORD *)&this->m_Func = func;
    v4 = *((_QWORD *)&func + 1);
    this->m_pObj = pObj;
    *((_QWORD *)&this->m_Func + 1) = v4;
    _SteamAPI_RegisterCallback(a1: this, a2: 304);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010EA0
// Name: public: virtual CDialogGameInfo::~CDialogGameInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::~CDialogGameInfo(CDialogGameInfo *this)
{
  ISteamMatchmakingServers *m_pSteamMatchmakingServers; // ecx
  bool v3; // zf

  this->vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CDialogGameInfo_vtbl *)&CDialogGameInfo::`vftable'{for `vgui::Frame'};
  this->ISteamMatchmakingPlayersResponse::__vftable = (ISteamMatchmakingPlayersResponse_vtbl *)&CDialogGameInfo::`vftable'{for `ISteamMatchmakingPlayersResponse'};
  this->ISteamMatchmakingPingResponse::__vftable = (ISteamMatchmakingPingResponse_vtbl *)&CDialogGameInfo::`vftable'{for `ISteamMatchmakingPingResponse'};
  m_pSteamMatchmakingServers = steamapicontext->m_pSteamMatchmakingServers;
  if ( m_pSteamMatchmakingServers != nullptr )
  {
    if ( this->m_hPingQuery != -1 )
      m_pSteamMatchmakingServers->CancelServerQuery(this: m_pSteamMatchmakingServers, a2: this->m_hPingQuery);
    if ( this->m_hPlayersQuery != -1 )
      steamapicontext->m_pSteamMatchmakingServers->CancelServerQuery(
        this: steamapicontext->m_pSteamMatchmakingServers,
        a2: this->m_hPlayersQuery);
  }
  v3 = (this->m_CallbackPersonaStateChange.m_nCallbackFlags & 1) == 0;
  this->m_CallbackPersonaStateChange.__vftable = (CCallback<CDialogGameInfo,PersonaStateChange_t,0>_vtbl *)&CCallback<CDialogGameInfo,PersonaStateChange_t,0>::`vftable';
  if ( !v3 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackPersonaStateChange);
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x10010F30
// Name: protected: virtual void CDialogGameInfo::OnRadioButtonChecked(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogGameInfo::OnRadioButtonChecked(CDialogGameInfo *this, vgui::Panel *panel)
{
  this->OnButtonToggled(this, a2: panel);
}

//------------------------------------------------------------------------------
// Address: 0x10010F40
// Name: public: virtual struct vgui::PanelMessageMap __near * CDialogGameInfo::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDialogGameInfo::GetMessageMap(CDialogGameInfo *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDialogGameInfo::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDialogGameInfo::GetMessageMap'::`2'::s_pMap;
  `CDialogGameInfo::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDialogGameInfo");
  `CDialogGameInfo::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010F70
// Name: public: virtual struct PanelAnimationMap __near * CDialogGameInfo::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDialogGameInfo::GetAnimMap(CDialogGameInfo *this)
{
  return FindOrAddPanelAnimationMap(className: "CDialogGameInfo");
}

//------------------------------------------------------------------------------
// Address: 0x10010F80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDialogGameInfo::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDialogGameInfo::GetKBMap(CDialogGameInfo *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDialogGameInfo::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDialogGameInfo::GetKBMap'::`2'::s_pMap;
  `CDialogGameInfo::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDialogGameInfo");
  `CDialogGameInfo::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010FF0
// Name: public: static void CDialogGameInfo::PanelMessageFunc_OnConnect::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDialogGameInfo::PanelMessageFunc_OnConnect::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDialogGameInfo::PanelMessageFunc_OnConnect::InitVar'::`2'::bAdded )
  {
    `CDialogGameInfo::PanelMessageFunc_OnConnect::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CDialogGameInfo");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "Connect";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011080
// Name: public: static void CDialogGameInfo::PanelMessageFunc_OnRefresh::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDialogGameInfo::PanelMessageFunc_OnRefresh::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDialogGameInfo::PanelMessageFunc_OnRefresh::InitVar'::`2'::bAdded )
  {
    `CDialogGameInfo::PanelMessageFunc_OnRefresh::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1132,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CDialogGameInfo");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "Refresh";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011110
// Name: public: static void CDialogGameInfo::PanelMessageFunc_OnButtonToggled::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDialogGameInfo::PanelMessageFunc_OnButtonToggled::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDialogGameInfo::PanelMessageFunc_OnButtonToggled::InitVar'::`2'::bAdded )
  {
    `CDialogGameInfo::PanelMessageFunc_OnButtonToggled::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::TextEntry::`vcall'{1136,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CDialogGameInfo");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ButtonToggled";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100111B0
// Name: public: static void CDialogGameInfo::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDialogGameInfo::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDialogGameInfo::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `CDialogGameInfo::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Button::`vcall'{1140,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CDialogGameInfo");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "RadioButtonChecked";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011250
// Name: public: static void CDialogGameInfo::PanelMessageFunc_OnJoinServerWithPassword::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDialogGameInfo::PanelMessageFunc_OnJoinServerWithPassword::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDialogGameInfo::PanelMessageFunc_OnJoinServerWithPassword::InitVar'::`2'::bAdded )
  {
    `CDialogGameInfo::PanelMessageFunc_OnJoinServerWithPassword::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CDialogGameInfo");
    v2 = (__int128)_mm_load_si128(&v5);
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTCHARPTR;
    memset(&v4.secondParamType, 0, 20);
    m_Size = v1->entries.m_Size;
    v4.name = "JoinServerWithPassword";
    v4.func = v2;
    v4.firstParamName = "password";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100112F0
// Name: public: static void CDialogGameInfo::PanelMessageFunc_OnConnectToGame::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDialogGameInfo::PanelMessageFunc_OnConnectToGame::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CDialogGameInfo::PanelMessageFunc_OnConnectToGame::InitVar'::`2'::bAdded )
  {
    `CDialogGameInfo::PanelMessageFunc_OnConnectToGame::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CDialogGameInfo");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    v4.numParams = 2;
    v4.firstParamType = DATATYPE_INT;
    v4.secondParamType = DATATYPE_INT;
    memset(&v4.nameSymbol, 0, 12);
    v4.name = "ConnectedToGame";
    v4.func = v3;
    v4.firstParamName = "ip";
    v4.secondParamName = "port";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011390
// Name: public: CDialogGameInfo::CDialogGameInfo(class vgui::Panel __near *,int,int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
CDialogGameInfo *__thiscall CDialogGameInfo::CDialogGameInfo(
        CDialogGameInfo *this,
        vgui::Panel *parent,
        unsigned int serverIP,
        unsigned __int16 queryPort,
        unsigned __int16 connectionPort)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Label *v15; // eax
  vgui::Label *v16; // eax
  vgui::ToggleButton *v17; // eax
  vgui::ToggleButton *v18; // eax
  vgui::RadioButton *v19; // eax
  vgui::RadioButton *v20; // eax
  vgui::RadioButton *v21; // eax
  vgui::RadioButton *v22; // eax
  vgui::ListPanel *v23; // eax
  vgui::ListPanel *v24; // eax
  KeyValues *v25; // eax
  KeyValues *v26; // eax
  KeyValues *v27; // eax
  KeyValues *v28; // eax
  KeyValues *v29; // eax
  KeyValues *v30; // eax
  KeyValues *v31; // eax
  KeyValues *v32; // eax
  KeyValues *v33; // eax
  KeyValues *v34; // eax
  KeyValues *v35; // eax
  KeyValues *v36; // eax
  __int128 v38; // [esp+3Ch] [ebp-2Ch]
  __int64 v39; // [esp+58h] [ebp-10h]
  int savedregs; // [esp+68h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: "DialogGameInfo", showTaskbarIcon: true, bPopup: true);
  this->ISteamMatchmakingPlayersResponse::__vftable = (ISteamMatchmakingPlayersResponse_vtbl *)&ISteamMatchmakingPlayersResponse::`vftable';
  this->ISteamMatchmakingPingResponse::__vftable = (ISteamMatchmakingPingResponse_vtbl *)&ISteamMatchmakingPingResponse::`vftable';
  this->vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CDialogGameInfo_vtbl *)&CDialogGameInfo::`vftable'{for `vgui::Frame'};
  this->ISteamMatchmakingPlayersResponse::__vftable = (ISteamMatchmakingPlayersResponse_vtbl *)&CDialogGameInfo::`vftable'{for `ISteamMatchmakingPlayersResponse'};
  this->ISteamMatchmakingPingResponse::__vftable = (ISteamMatchmakingPingResponse_vtbl *)&CDialogGameInfo::`vftable'{for `ISteamMatchmakingPingResponse'};
  if ( `CDialogGameInfo::ChainToMap'::`2'::chained == 0 )
  {
    `CDialogGameInfo::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CDialogGameInfo");
    v6->pfnClassName = CDialogGameInfo::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CDialogGameInfo::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDialogGameInfo::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CDialogGameInfo");
    v7->pfnClassName = CDialogGameInfo::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CDialogGameInfo::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDialogGameInfo::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CDialogGameInfo");
    v8->pfnClassName = CDialogGameInfo::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CDialogGameInfo::PanelMessageFunc_OnConnect::InitVar(a1: (int)&savedregs);
  CDialogGameInfo::PanelMessageFunc_OnRefresh::InitVar(a1: (int)&savedregs);
  CDialogGameInfo::PanelMessageFunc_OnButtonToggled::InitVar(a1: (int)&savedregs);
  CDialogGameInfo::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  CDialogGameInfo::PanelMessageFunc_OnJoinServerWithPassword::InitVar(a1: (int)&savedregs);
  CDialogGameInfo::PanelMessageFunc_OnConnectToGame::InitVar(a1: (int)&savedregs);
  LODWORD(v39) = vgui::Panel::OnMousePressed;
  HIDWORD(v39) = 0;
  *(_QWORD *)&this->m_CallbackPersonaStateChange.m_Func = v39;
  this->m_CallbackPersonaStateChange.m_nCallbackFlags = 0;
  this->m_CallbackPersonaStateChange.m_iCallback = 0;
  this->m_CallbackPersonaStateChange.__vftable = (CCallback<CDialogGameInfo,PersonaStateChange_t,0>_vtbl *)&CCallback<CDialogGameInfo,PersonaStateChange_t,0>::`vftable';
  this->m_CallbackPersonaStateChange.m_pObj = this;
  *((_QWORD *)&this->m_CallbackPersonaStateChange.m_Func + 1) = 0;
  if ( vgui::Panel::OnMousePressed != nullptr )
  {
    *(_QWORD *)&v38 = v39;
    *((_QWORD *)&v38 + 1) = 0;
    CCallback<CDialogGameInfo,PersonaStateChange_t,0>::Register(
      this: &this->m_CallbackPersonaStateChange,
      pObj: this,
      func: v38);
  }
  gameserveritem_t::gameserveritem_t(this: &this->m_Server);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 512, tall: 512);
  vgui::Panel::SetMinimumSize(this, wide: 416, tall: 340);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  *(_WORD *)&this->m_bServerFull = 0;
  this->m_bServerNotResponding = false;
  this->m_bShowingExtendedOptions = false;
  LODWORD(this->m_SteamIDFriend) = 0;
  HIDWORD(this->m_SteamIDFriend) = 0;
  this->m_hPingQuery = -1;
  this->m_hPlayersQuery = -1;
  this->m_bPlayerListUpdatePending = false;
  *(_WORD *)&this->m_bConnecting = 0;
  v9 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "Connect",
            text: "#ServerBrowser_JoinGame",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  this->m_pConnectButton = v10;
  v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "Close",
            text: "#ServerBrowser_Close",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v12 = nullptr;
  this->m_pCloseButton = v12;
  v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "Refresh",
            text: "#ServerBrowser_Refresh",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v14 = nullptr;
  this->m_pRefreshButton = v14;
  v15 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v15 != nullptr )
    v16 = vgui::Label::Label(this: v15, parent: this, panelName: "InfoLabel", text: defaultValue);
  else
    v16 = nullptr;
  this->m_pInfoLabel = v16;
  v17 = (vgui::ToggleButton *)operator new(nSize: 0x1FCu);
  if ( v17 != nullptr )
    v18 = vgui::ToggleButton::ToggleButton(
            this: v17,
            parent: this,
            panelName: "AutoRetry",
            text: "#ServerBrowser_AutoRetry");
  else
    v18 = nullptr;
  this->m_pAutoRetry = v18;
  v18->AddActionSignalTarget_2(this: v18, a2: this);
  v19 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v19 != nullptr )
    v20 = vgui::RadioButton::RadioButton(
            this: v19,
            parent: this,
            panelName: "AutoRetryAlert",
            text: "#ServerBrowser_AlertMeWhenSlotOpens");
  else
    v20 = nullptr;
  this->m_pAutoRetryAlert = v20;
  v21 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v21 != nullptr )
    v22 = vgui::RadioButton::RadioButton(
            this: v21,
            parent: this,
            panelName: "AutoRetryJoin",
            text: "#ServerBrowser_JoinWhenSlotOpens");
  else
    v22 = nullptr;
  this->m_pAutoRetryJoin = v22;
  v23 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v23 != nullptr )
    v24 = vgui::ListPanel::ListPanel(this: v23, parent: this, panelName: "PlayerList");
  else
    v24 = nullptr;
  this->m_pPlayerList = v24;
  v24->AddColumnHeader(this: v24, a2: 0, a3: "PlayerName", a4: "#ServerBrowser_PlayerName", a5: 156, a6: 0);
  this->m_pPlayerList->AddColumnHeader(
    this: this->m_pPlayerList,
    a2: 1,
    a3: "Score",
    a4: "#ServerBrowser_Score",
    a5: 64,
    a6: 0);
  this->m_pPlayerList->AddColumnHeader(
    this: this->m_pPlayerList,
    a2: 2,
    a3: "Time",
    a4: "#ServerBrowser_Time",
    a5: 64,
    a6: 0);
  this->m_pPlayerList->SetSortFunc(this: this->m_pPlayerList, a2: 2, a3: CDialogGameInfo::PlayerTimeColumnSortFunc);
  v25 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v25 != nullptr )
    v26 = KeyValues::KeyValues(this: v25, setName: "SetSortColumn", firstKey: "column", firstValue: 2);
  else
    v26 = nullptr;
  vgui::Panel::PostMessage(this, target: this->m_pPlayerList, message: v26, delay: 0.0);
  v27 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v27 != nullptr )
    v28 = KeyValues::KeyValues(this: v27, setName: "SetSortColumn", firstKey: "column", firstValue: 1);
  else
    v28 = nullptr;
  vgui::Panel::PostMessage(this, target: this->m_pPlayerList, message: v28, delay: 0.0);
  v29 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v29 != nullptr )
    v30 = KeyValues::KeyValues(this: v29, setName: "SetSortColumn", firstKey: "column", firstValue: 1);
  else
    v30 = nullptr;
  vgui::Panel::PostMessage(this, target: this->m_pPlayerList, message: v30, delay: 0.0);
  this->m_pAutoRetryAlert->SetSelected(this: this->m_pAutoRetryAlert, a2: true);
  v31 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v31 != nullptr )
    v32 = KeyValues::KeyValues(this: v31, setName: "Connect");
  else
    v32 = nullptr;
  this->m_pConnectButton->SetCommand(this: this->m_pConnectButton, a2: v32);
  v33 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v33 != nullptr )
    v34 = KeyValues::KeyValues(this: v33, setName: "Close");
  else
    v34 = nullptr;
  this->m_pCloseButton->SetCommand(this: this->m_pCloseButton, a2: v34);
  v35 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v35 != nullptr )
    v36 = KeyValues::KeyValues(this: v35, setName: "Refresh");
  else
    v36 = nullptr;
  this->m_pRefreshButton->SetCommand(this: this->m_pRefreshButton, a2: v36);
  this->m_iRequestRetry = 0;
  memset(dst: (int)&this->m_Server, value: nullptr, count: sizeof(this->m_Server));
  this->m_Server.m_NetAdr.m_unIP = serverIP;
  this->m_Server.m_NetAdr.m_usQueryPort = queryPort;
  this->m_Server.m_NetAdr.m_usConnectionPort = connectionPort;
  CDialogGameInfo::RequestInfo(this);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Servers/DialogGameInfo.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::EditablePanel::RegisterControlSettingsFile(
    this,
    resourceName: "Servers/DialogGameInfo_SinglePlayer.res",
    pathID: nullptr);
  vgui::EditablePanel::RegisterControlSettingsFile(
    this,
    resourceName: "Servers/DialogGameInfo_AutoRetry.res",
    pathID: nullptr);
  vgui::Frame::MoveToCenterOfScreen(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10078A90
// Name: private: class vgui::Panel __near * vgui::BuildModeDialog::OnNewControl(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::BuildModeDialog::OnNewControl(
        vgui::BuildModeDialog *this,
        const char *name,
        int x,
        int y)
{
  vgui::Panel *v5; // edi

  v5 = vgui::BuildGroup::NewControl(this: this->m_pBuildGroup, name, x, y);
  if ( v5 != nullptr )
  {
    this->m_pBuildGroup->MousePressed(this: this->m_pBuildGroup, a2: KEY_COUNT, a3: v5);
    this->m_pBuildGroup->MouseReleased(this: this->m_pBuildGroup, a2: KEY_COUNT, a3: v5);
  }
  this->m_pSaveButton->SetEnabled(this: this->m_pSaveButton, a2: true);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1007AAC0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::BuildModeDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::BuildModeDialog::GetMessageMap(vgui::BuildModeDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::BuildModeDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::BuildModeDialog::GetMessageMap'::`2'::s_pMap;
  `vgui::BuildModeDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "BuildModeDialog");
  `vgui::BuildModeDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007AAF0
// Name: public: virtual struct PanelAnimationMap __near * vgui::BuildModeDialog::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::BuildModeDialog::GetAnimMap(vgui::BuildModeDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "BuildModeDialog");
}

//------------------------------------------------------------------------------
// Address: 0x1007AB00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::BuildModeDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::BuildModeDialog::GetKBMap(vgui::BuildModeDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::BuildModeDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::BuildModeDialog::GetKBMap'::`2'::s_pMap;
  `vgui::BuildModeDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "BuildModeDialog");
  `vgui::BuildModeDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}
