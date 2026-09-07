// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: serverbrowser/serverbrowser.cpp
// Functions: 19
// ============================================================

#include "serverbrowser\serverbrowser.h"

//------------------------------------------------------------------------------
// Address: 0x10014BF0
// Name: public: bool CSteamAPIContext::Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSteamAPIContext::Init(CSteamAPIContext *this)
{
  int HSteamPipe; // esi
  int v4; // eax
  ISteamUser *v5; // eax
  int v6; // eax
  ISteamFriends *v7; // eax
  int v8; // eax
  ISteamUtils *v9; // eax
  int v10; // eax
  ISteamMatchmaking *v11; // eax
  int v12; // eax
  ISteamMatchmakingServers *v13; // eax
  int v14; // eax
  ISteamUserStats *v15; // eax
  int v16; // eax
  ISteamApps *v17; // eax
  int v18; // eax
  ISteamNetworking *v19; // eax
  int v20; // eax
  ISteamRemoteStorage *v21; // eax
  int hSteamUser; // [esp+8h] [ebp-4h]

  if ( _SteamClient() == 0 )
    return false;
  hSteamUser = _SteamAPI_GetHSteamUser();
  HSteamPipe = _SteamAPI_GetHSteamPipe();
  v4 = _SteamClient();
  v5 = (ISteamUser *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v4 + 20))(
                       a1: v4,
                       a2: hSteamUser,
                       a3: HSteamPipe,
                       a4: "SteamUser014");
  this->m_pSteamUser = v5;
  if ( v5 == nullptr )
    return false;
  v6 = _SteamClient();
  v7 = (ISteamFriends *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v6 + 32))(
                          a1: v6,
                          a2: hSteamUser,
                          a3: HSteamPipe,
                          a4: "SteamFriends008");
  this->m_pSteamFriends = v7;
  if ( v7 == nullptr )
    return false;
  v8 = _SteamClient();
  v9 = (ISteamUtils *)(*(int (__thiscall **)(int, int, const char *))(*(_DWORD *)v8 + 36))(
                        a1: v8,
                        a2: HSteamPipe,
                        a3: "SteamUtils005");
  this->m_pSteamUtils = v9;
  if ( v9 == nullptr )
    return false;
  v10 = _SteamClient();
  v11 = (ISteamMatchmaking *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v10 + 40))(
                               a1: v10,
                               a2: hSteamUser,
                               a3: HSteamPipe,
                               a4: "SteamMatchMaking008");
  this->m_pSteamMatchmaking = v11;
  if ( v11 == nullptr )
    return false;
  v12 = _SteamClient();
  v13 = (ISteamMatchmakingServers *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v12 + 48))(
                                      a1: v12,
                                      a2: hSteamUser,
                                      a3: HSteamPipe,
                                      a4: "SteamMatchMakingServers002");
  this->m_pSteamMatchmakingServers = v13;
  if ( v13 == nullptr )
    return false;
  v14 = _SteamClient();
  v15 = (ISteamUserStats *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v14 + 56))(
                             a1: v14,
                             a2: hSteamUser,
                             a3: HSteamPipe,
                             a4: "STEAMUSERSTATS_INTERFACE_VERSION009");
  this->m_pSteamUserStats = v15;
  if ( v15 == nullptr )
    return false;
  v16 = _SteamClient();
  v17 = (ISteamApps *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v16 + 64))(
                        a1: v16,
                        a2: hSteamUser,
                        a3: HSteamPipe,
                        a4: "STEAMAPPS_INTERFACE_VERSION004");
  this->m_pSteamApps = v17;
  if ( v17 == nullptr )
    return false;
  v18 = _SteamClient();
  v19 = (ISteamNetworking *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v18 + 68))(
                              a1: v18,
                              a2: hSteamUser,
                              a3: HSteamPipe,
                              a4: "SteamNetworking005");
  this->m_pSteamNetworking = v19;
  if ( v19 == nullptr )
    return false;
  v20 = _SteamClient();
  v21 = (ISteamRemoteStorage *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v20 + 72))(
                                 a1: v20,
                                 a2: hSteamUser,
                                 a3: HSteamPipe,
                                 a4: "STEAMREMOTESTORAGE_INTERFACE_VERSION004");
  this->m_pSteamRemoteStorage = v21;
  return v21 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10014D50
// Name: class CServerBrowser __near & ServerBrowser(void)
// Source: json
//------------------------------------------------------------------------------
CServerBrowser *__cdecl ServerBrowser()
{
  return &g_ServerBrowserSingleton;
}

//------------------------------------------------------------------------------
// Address: 0x10014D60
// Name: public: virtual bool CServerBrowser::Initialize(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerBrowser::Initialize(
        CServerBrowser *this,
        void *(__cdecl **factorylist)(const char *, int *),
        int factoryCount)
{
  int v3; // esi
  vgui::PropertyPage *v4; // ecx
  IRunGameEngine *v5; // eax
  bool result; // al

  ConnectTier1Libraries(pFactoryList: factorylist, nFactoryCount: factoryCount);
  v3 = 0;
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(pFactoryList: factorylist, nFactoryCount: factoryCount);
  vgui::PropertyPage::OnPageHide(this: v4);
  g_pRunGameEngine = nullptr;
  _SteamAPI_InitSafe(a1: factorylist, a2: factoryCount);
  _SteamAPI_SetTryCatchCallbacks(a1: 0);
  CSteamAPIContext::Init(this: steamapicontext);
  if ( factoryCount > 0 )
  {
    v5 = g_pRunGameEngine;
    do
    {
      if ( v5 == nullptr )
      {
        v5 = (IRunGameEngine *)factorylist[v3](a1: "RunGameEngine005", a2: nullptr);
        g_pRunGameEngine = v5;
      }
      ++v3;
    }
    while ( v3 < factoryCount );
  }
  result = vgui::VGui_InitInterfacesList(
             moduleName: "ServerBrowser",
             factoryList: factorylist,
             numFactories: factoryCount);
  if ( result )
  {
    g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "servers/serverbrowser_%language%.txt", a3: nullptr, a4: false);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014E10
// Name: public: virtual bool CServerBrowser::IsValid(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerBrowser::IsValid(CServerBrowser *this)
{
  return g_pRunGameEngine != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10014E20
// Name: public: virtual void CServerBrowser::CreateDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowser::CreateDialog(CServerBrowser *this)
{
  vgui::DHANDLE<CServerBrowserDialog> *p_m_hInternetDlg; // esi
  CServerBrowserDialog *v2; // eax
  CDragDropHelperPanel *v3; // eax
  CServerBrowserDialog *v4; // eax

  p_m_hInternetDlg = &this->m_hInternetDlg;
  if ( vgui::PHandle::Get(this: &this->m_hInternetDlg) == nullptr )
  {
    v2 = (CServerBrowserDialog *)operator new(nSize: 0x4E4u);
    if ( v2 != nullptr )
      v3 = (CDragDropHelperPanel *)CServerBrowserDialog::CServerBrowserDialog(this: v2, parent: nullptr);
    else
      v3 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)p_m_hInternetDlg,
      pPanel: v3);
    v4 = (CServerBrowserDialog *)vgui::PHandle::Get(this: p_m_hInternetDlg);
    CServerBrowserDialog::Initialize(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014E70
// Name: public: virtual bool CServerBrowser::PostInitialize(void __near * (*__near *)(char const __near *,int __near *),int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerBrowser::PostInitialize(
        CServerBrowser *this,
        void *(__cdecl **modules)(const char *, int *),
        int factoryCount)
{
  CServerBrowser *v3; // edi
  int v4; // esi
  IRunGameEngine *v5; // eax
  vgui::Panel *v6; // eax

  v3 = this;
  v4 = 0;
  if ( factoryCount > 0 )
  {
    v5 = g_pRunGameEngine;
    do
    {
      if ( v5 == nullptr )
      {
        v5 = (IRunGameEngine *)modules[v4](a1: "RunGameEngine005", a2: nullptr);
        g_pRunGameEngine = v5;
      }
      ++v4;
    }
    while ( v4 < factoryCount );
    v3 = this;
  }
  (*(void (__thiscall **)(vgui::DHANDLE<CServerBrowserDialog> *))(v3[-1].m_hInternetDlg.m_iPanelID + 24))(a1: &v3[-1].m_hInternetDlg);
  v6 = vgui::PHandle::Get(this: (vgui::PHandle *)&v3->IVGuiModule);
  v6->SetVisible(this: v6, a2: false);
  return g_pRunGameEngine != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10014EF0
// Name: public: virtual bool CServerBrowser::Activate(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerBrowser::Activate(CServerBrowser *this)
{
  CServerBrowserDialog *v2; // eax
  int m_nValue; // eax
  int v4; // esi
  int aclock; // [esp+4h] [ebp-4h] BYREF

  if ( firstTimeOpening )
  {
    v2 = (CServerBrowserDialog *)vgui::PHandle::Get(this: &this->m_hInternetDlg);
    CServerBrowserDialog::LoadUserData(this: v2);
    firstTimeOpening = false;
  }
  if ( sb_numtimesopened.m_pParent != nullptr )
    m_nValue = sb_numtimesopened.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v4 = m_nValue + 1;
  ConVar::SetValue(this: (ConVar *)&sb_numtimesopened.IConVar, value: m_nValue + 1);
  if ( v4 == 1 )
  {
    _time32(timeptr: &aclock);
    ConVar::SetValue(this: (ConVar *)&sb_firstopentime.IConVar, value: aclock);
  }
  this->Open(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10014F70
// Name: public: virtual void CServerBrowser::Deactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowser::Deactivate(CServerBrowser *this)
{
  vgui::PHandle *v1; // esi
  CServerBrowserDialog *v2; // eax

  v1 = (vgui::PHandle *)&this->IVGuiModule;
  if ( vgui::PHandle::Get(this: (vgui::PHandle *)&this->IVGuiModule) != nullptr )
  {
    v2 = (CServerBrowserDialog *)vgui::PHandle::Get(this: v1);
    CServerBrowserDialog::SaveUserData(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014F90
// Name: public: virtual void CServerBrowser::Reactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowser::Reactivate(CServerBrowser *this)
{
  vgui::PHandle *v1; // esi
  CServerBrowserDialog *v2; // eax
  vgui::Panel *v3; // eax
  CServerBrowserDialog *v4; // eax

  v1 = (vgui::PHandle *)&this->IVGuiModule;
  if ( vgui::PHandle::Get(this: (vgui::PHandle *)&this->IVGuiModule) != nullptr )
  {
    v2 = (CServerBrowserDialog *)vgui::PHandle::Get(this: v1);
    CServerBrowserDialog::LoadUserData(this: v2);
    v3 = vgui::PHandle::Get(this: v1);
    if ( v3->IsVisible(this: v3) )
    {
      v4 = (CServerBrowserDialog *)vgui::PHandle::Get(this: v1);
      CServerBrowserDialog::RefreshCurrentPage(this: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014FE0
// Name: public: virtual void CServerBrowser::Open(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowser::Open(CServerBrowser *this)
{
  CServerBrowserDialog *v1; // eax

  v1 = (CServerBrowserDialog *)vgui::PHandle::Get(this: &this->m_hInternetDlg);
  CServerBrowserDialog::Open(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10014FF0
// Name: public: virtual unsigned int CServerBrowser::GetPanel(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CServerBrowser::GetPanel(CServerBrowser *this)
{
  vgui::PHandle *v1; // esi
  vgui::Panel *v2; // eax

  v1 = (vgui::PHandle *)&this->IVGuiModule;
  if ( vgui::PHandle::Get(this: (vgui::PHandle *)&this->IVGuiModule) == nullptr )
    return 0;
  v2 = vgui::PHandle::Get(this: v1);
  return v2->GetVPanel(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10015020
// Name: public: virtual void CServerBrowser::SetParent(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowser::SetParent(CServerBrowser *this, unsigned int parent)
{
  vgui::PHandle *v2; // esi
  vgui::Panel *v3; // eax

  v2 = (vgui::PHandle *)&this->IVGuiModule;
  if ( vgui::PHandle::Get(this: (vgui::PHandle *)&this->IVGuiModule) != nullptr )
  {
    v3 = vgui::PHandle::Get(this: v2);
    v3->SetParent(this: v3, a2: parent);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015050
// Name: public: virtual void CServerBrowser::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowser::Shutdown(CServerBrowser *this)
{
  vgui::PHandle *v1; // esi
  vgui::PropertyPage *v2; // ecx
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax

  v1 = (vgui::PHandle *)&this->IVGuiModule;
  if ( vgui::PHandle::Get(this: (vgui::PHandle *)&this->IVGuiModule) != nullptr )
  {
    v3 = vgui::PHandle::Get(this: v1);
    v3->__vftable[1].GetAnimMap(this: v3);
    v4 = vgui::PHandle::Get(this: v1);
    v4->MarkForDeletion(this: v4);
  }
  vgui::PropertyPage::OnPageHide(this: v2);
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x100150A0
// Name: public: virtual bool CServerBrowser::OpenGameInfoDialog(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerBrowser::OpenGameInfoDialog(CServerBrowser *this, unsigned __int64 ulSteamIDFriend)
{
  vgui::DHANDLE<CServerBrowserDialog> *p_m_hInternetDlg; // esi
  CServerBrowserDialog *v3; // eax
  CDialogGameInfo *DialogGameInfoForFriend; // eax
  unsigned __int16 m_usGamePort; // bx
  CServerBrowserDialog *v7; // eax
  CDialogGameInfo *v8; // eax
  FriendGameInfo_t friendGameInfo; // [esp+Ch] [ebp-1Ch] BYREF
  vgui::PHandle *v10; // [esp+24h] [ebp-4h]

  p_m_hInternetDlg = &this->m_hInternetDlg;
  v10 = &this->m_hInternetDlg;
  if ( vgui::PHandle::Get(this: &this->m_hInternetDlg) == nullptr )
    return 0;
  v3 = (CServerBrowserDialog *)vgui::PHandle::Get(this: p_m_hInternetDlg);
  DialogGameInfoForFriend = CServerBrowserDialog::GetDialogGameInfoForFriend(this: v3, ulSteamIDFriend);
  if ( DialogGameInfoForFriend != nullptr )
  {
    DialogGameInfoForFriend->Activate(this: DialogGameInfoForFriend);
    return 1;
  }
  HIWORD(friendGameInfo.m_steamIDLobby.m_steamid.m_unAll64Bits) = BYTE6(friendGameInfo.m_steamIDLobby.m_steamid.m_unAll64Bits)
                                                                & 0xF;
  friendGameInfo.m_steamIDLobby.m_steamid.m_unAll64Bits &= 0xFFF0000000000000uLL;
  friendGameInfo.m_gameID.m_ulGameID = 0;
  if ( ((unsigned __int8 (__thiscall *)(ISteamFriends *, _DWORD, _DWORD, FriendGameInfo_t *))steamapicontext->m_pSteamFriends->GetFriendGamePlayed)(
         a1: steamapicontext->m_pSteamFriends,
         a2: ulSteamIDFriend,
         a3: HIDWORD(ulSteamIDFriend),
         a4: &friendGameInfo) == 0 )
    return 0;
  m_usGamePort = friendGameInfo.m_usGamePort;
  if ( friendGameInfo.m_usQueryPort < 0xFFFEu )
    m_usGamePort = friendGameInfo.m_usQueryPort;
  v7 = (CServerBrowserDialog *)vgui::PHandle::Get(this: v10);
  v8 = CServerBrowserDialog::OpenGameInfoDialog(
         this: v7,
         serverIP: friendGameInfo.m_unGameIP,
         connPort: friendGameInfo.m_usGamePort,
         queryPort: m_usGamePort);
  CDialogGameInfo::SetFriend(this: v8, ulSteamIDFriend);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10015180
// Name: public: virtual bool CServerBrowser::JoinGame(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CServerBrowser::JoinGame(CServerBrowser *this, unsigned __int64 ulSteamIDFriend)
{
  CServerBrowserDialog *v3; // eax
  CDialogGameInfo *DialogGameInfoForFriend; // eax

  if ( ((unsigned __int8 (__thiscall *)(CServerBrowser *, _DWORD, _DWORD))this->OpenGameInfoDialog)(
         a1: this,
         a2: ulSteamIDFriend,
         a3: HIDWORD(ulSteamIDFriend)) != 0 )
  {
    v3 = (CServerBrowserDialog *)vgui::PHandle::Get(this: &this->m_hInternetDlg);
    DialogGameInfoForFriend = CServerBrowserDialog::GetDialogGameInfoForFriend(this: v3, ulSteamIDFriend);
    CDialogGameInfo::Connect(this: DialogGameInfoForFriend);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100151C0
// Name: public: virtual bool CServerBrowser::JoinGame(unsigned int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerBrowser::JoinGame(CServerBrowser *this, unsigned int unGameIP, unsigned __int16 usGamePort)
{
  CServerBrowserDialog *v3; // eax

  v3 = (CServerBrowserDialog *)vgui::PHandle::Get(this: &this->m_hInternetDlg);
  CServerBrowserDialog::JoinGame(this: v3, serverIP: unGameIP, serverPort: usGamePort);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100151F0
// Name: public: virtual void CServerBrowser::CloseGameInfoDialog(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowser::CloseGameInfoDialog(CServerBrowser *this, unsigned __int64 ulSteamIDFriend)
{
  CServerBrowserDialog *v2; // eax
  CDialogGameInfo *DialogGameInfoForFriend; // eax

  v2 = (CServerBrowserDialog *)vgui::PHandle::Get(this: &this->m_hInternetDlg);
  DialogGameInfoForFriend = CServerBrowserDialog::GetDialogGameInfoForFriend(this: v2, ulSteamIDFriend);
  if ( DialogGameInfoForFriend != nullptr )
    DialogGameInfoForFriend->Close(this: DialogGameInfoForFriend);
}

//------------------------------------------------------------------------------
// Address: 0x10015220
// Name: public: virtual void CServerBrowser::CloseAllGameInfoDialogs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerBrowser::CloseAllGameInfoDialogs(CServerBrowser *this)
{
  vgui::DHANDLE<CServerBrowserDialog> *p_m_hInternetDlg; // esi
  CServerBrowserDialog *v2; // eax

  p_m_hInternetDlg = &this->m_hInternetDlg;
  if ( vgui::PHandle::Get(this: &this->m_hInternetDlg) != nullptr )
  {
    v2 = (CServerBrowserDialog *)vgui::PHandle::Get(this: p_m_hInternetDlg);
    CServerBrowserDialog::CloseAllGameInfoDialogs(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014D40
// Name: __CreateCServerBrowserIVGuiModule_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IVGuiModule *__cdecl _CreateCServerBrowserIVGuiModule_interface()
{
  return &g_ServerBrowserSingleton.IVGuiModule;
}
