// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: serverbrowser/dialogaddserver.cpp
// Functions: 20
// ============================================================

#include "serverbrowser\dialogaddserver.h"

//------------------------------------------------------------------------------
// Address: 0x1000E9B0
// Name: public: gameserveritem_t::gameserveritem_t(void)
// Source: json
//------------------------------------------------------------------------------
gameserveritem_t *__thiscall gameserveritem_t::gameserveritem_t(gameserveritem_t *this)
{
  *((_DWORD *)&this->m_steamID.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  HIBYTE(this->m_steamID.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&this->m_steamID.m_steamid.m_comp + 1) &= 0xFFF00000;
  *(_DWORD *)&this->m_steamID.m_steamid.m_comp = 0;
  this->m_szServerName[0] = 0;
  this->m_szGameDescription[0] = 0;
  this->m_szMap[0] = 0;
  *(_WORD *)&this->m_bPassword = 0;
  *(_WORD *)&this->m_bDoNotRefresh = 0;
  this->m_bHadSuccessfulResponse = false;
  this->m_nServerVersion = 0;
  this->m_ulTimeLastPlayed = 0;
  this->m_nBotPlayers = 0;
  this->m_nMaxPlayers = 0;
  this->m_nPlayers = 0;
  this->m_nAppID = 0;
  this->m_nPing = 0;
  this->m_szGameTags[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000EA20
// Name: public: static char const __near * CDialogAddServer::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDialogAddServer::GetPanelClassName()
{
  return "CDialogAddServer";
}

//------------------------------------------------------------------------------
// Address: 0x1000EA30
// Name: private: virtual void CDialogAddServer::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogAddServer::OnTextChanged(CDialogAddServer *this)
{
  bool bAnyText; // [esp+8h] [ebp-4h]

  bAnyText = this->m_pTextEntry->GetTextLength(this: this->m_pTextEntry) > 0;
  this->m_pAddServerButton->SetEnabled(this: this->m_pAddServerButton, a2: bAnyText);
  this->m_pTestServersButton->SetEnabled(this: this->m_pTestServersButton, a2: bAnyText);
}

//------------------------------------------------------------------------------
// Address: 0x1000EA80
// Name: private: void CDialogAddServer::OnOK(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogAddServer::OnOK(CDialogAddServer *this)
{
  char *v2; // edi
  vgui::MessageBox *v3; // eax
  vgui::MessageBox *v4; // eax
  unsigned __int16 Port; // di
  unsigned __int16 v6; // bx
  void (__thiscall *FinishAddServer)(CDialogAddServer *, gameserveritem_t *); // edx
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  gameserveritem_t server; // [esp+18h] [ebp-180h] BYREF
  netadr_s netaddr; // [esp+18Ch] [ebp-Ch] BYREF

  v2 = (char *)this->GetControlString_2(this, a2: "ServerNameText", a3: defaultValue);
  netadr_s::SetIP(this: &netaddr, unIP: 0);
  netadr_s::SetPort(this: &netaddr, newport: 0);
  netadr_s::SetType(this: &netaddr, newtype: NA_IP);
  netadr_s::SetFromString(this: &netaddr, pch: v2, bUseDNS: true);
  if ( netadr_s::GetPort(this: &netaddr) == 0 && !this->AllowInvalidIPs(this) )
    netadr_s::SetPort(this: &netaddr, newport: 0x6987u);
  if ( this->AllowInvalidIPs(this) || netadr_s::IsValid(this: &netaddr) )
  {
    gameserveritem_t::gameserveritem_t(this: &server);
    memset(dst: (int)&server, value: nullptr, count: sizeof(server));
    strncpy(dest: (unsigned __int8 *)server.m_szServerName, source: (unsigned __int8 *)v2, count: 0x40u);
    Port = netadr_s::GetPort(this: &netaddr);
    v6 = netadr_s::GetPort(this: &netaddr);
    server.m_NetAdr.m_unIP = netadr_s::addr_ntohl(this: &netaddr);
    FinishAddServer = this->FinishAddServer;
    server.m_NetAdr.m_usQueryPort = v6;
    server.m_NetAdr.m_usConnectionPort = Port;
    server.m_nAppID = 0;
    FinishAddServer(this, a2: &server);
  }
  else
  {
    v3 = (vgui::MessageBox *)operator new(nSize: 0x234u);
    if ( v3 != nullptr )
    {
      v4 = vgui::MessageBox::MessageBox(
             this: v3,
             title: "#ServerBrowser_AddServerErrorTitle",
             text: "#ServerBrowser_AddServerError",
             parent: nullptr);
      v4->DoModal_2(this: v4, a2: nullptr);
    }
    else
    {
      (*(void (__thiscall **)(_DWORD, _DWORD))(MEMORY[0] + 1116))(a1: 0, a2: 0);
    }
  }
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v9 = KeyValues::KeyValues(this: v8, setName: "Close");
  else
    v9 = nullptr;
  ((void (__thiscall *)(CDialogAddServer *, CDialogAddServer *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v9,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000EC20
// Name: public: virtual void CDialogAddServer::ServerFailedToRespond(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogAddServer::ServerFailedToRespond(CDialogAddServer *this)
{
  (*(void (__thiscall **)(_DWORD, const char *))(**(_DWORD **)&this->m_InternalKeyFocusTicked_register + 1064))(
    a1: *(_DWORD *)&this->m_InternalKeyFocusTicked_register,
    a2: "#ServerBrowser_ServerNotResponding");
}

//------------------------------------------------------------------------------
// Address: 0x1000EC40
// Name: public: virtual void CDialogAddServer::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogAddServer::ApplySchemeSettings(CDialogAddServer *this, vgui::IScheme *pScheme)
{
  vgui::ImageList *v4; // eax
  vgui::Dar<unsigned long> *v5; // esi
  vgui::IImage *v6; // eax
  vgui::IImage *v7; // eax
  vgui::IImage *v8; // eax
  vgui::IImage *v9; // eax
  vgui::IImage *v10; // eax
  vgui::IImage *v11; // eax
  vgui::IImage *v12; // eax
  vgui::IScheme_vtbl *v13; // esi
  bool v14; // al
  unsigned int v15; // eax
  vgui::IScheme_vtbl *v16; // esi
  bool v17; // al
  int secureColumnImage; // [esp+Ch] [ebp-8h]
  int botColumnImage; // [esp+10h] [ebp-4h]
  int passwordColumnImage; // [esp+1Ch] [ebp+8h]

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  v4 = (vgui::ImageList *)operator new(nSize: 0x18u);
  if ( v4 != nullptr )
    v5 = (vgui::Dar<unsigned long> *)vgui::ImageList::ImageList(this: v4, deleteImagesWhenDone: false);
  else
    v5 = nullptr;
  v6 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "servers/icon_password", a3: 0);
  vgui::Dar<unsigned long>::AddElement(this: v5, elem: (unsigned int)v6);
  v7 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "servers/icon_bots", a3: 0);
  vgui::Dar<unsigned long>::AddElement(this: v5, elem: (unsigned int)v7);
  v8 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "servers/icon_robotron", a3: 0);
  vgui::Dar<unsigned long>::AddElement(this: v5, elem: (unsigned int)v8);
  v9 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "servers/icon_secure_deny", a3: 0);
  vgui::Dar<unsigned long>::AddElement(this: v5, elem: (unsigned int)v9);
  v10 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "servers/icon_password_column", a3: 0);
  passwordColumnImage = vgui::Dar<unsigned long>::AddElement(this: v5, elem: (unsigned int)v10);
  v11 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "servers/icon_bots_column", a3: 0);
  botColumnImage = vgui::Dar<unsigned long>::AddElement(this: v5, elem: (unsigned int)v11);
  v12 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "servers/icon_robotron_column", a3: 0);
  secureColumnImage = vgui::Dar<unsigned long>::AddElement(this: v5, elem: (unsigned int)v12);
  this->m_pDiscoveredGames->SetImageList(this: this->m_pDiscoveredGames, a2: (vgui::ImageList *)v5, a3: true);
  v13 = pScheme->__vftable;
  v14 = this->IsProportional(this);
  v15 = v13->GetFont(this: pScheme, a2: "ListSmall", a3: v14);
  if ( v15 == 0 )
  {
    v16 = pScheme->__vftable;
    v17 = this->IsProportional(this);
    v15 = v16->GetFont(this: pScheme, a2: "DefaultSmall", a3: v17);
  }
  this->m_pDiscoveredGames->SetFont(this: this->m_pDiscoveredGames, a2: v15);
  this->m_pDiscoveredGames->SetColumnHeaderImage(this: this->m_pDiscoveredGames, a2: 0, a3: passwordColumnImage);
  this->m_pDiscoveredGames->SetColumnHeaderImage(this: this->m_pDiscoveredGames, a2: 1, a3: botColumnImage);
  this->m_pDiscoveredGames->SetColumnHeaderImage(this: this->m_pDiscoveredGames, a2: 2, a3: secureColumnImage);
}

//------------------------------------------------------------------------------
// Address: 0x1000EDF0
// Name: public: virtual void CDialogAddServer::OnItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogAddServer::OnItemSelected(CDialogAddServer *this)
{
  int v2; // eax
  void (__thiscall *SetEnabled)(vgui::Panel *, bool); // edx

  v2 = this->m_pDiscoveredGames->GetSelectedItem(this: this->m_pDiscoveredGames, a2: 0);
  SetEnabled = this->m_pAddSelectedServerButton->SetEnabled;
  if ( v2 == -1 )
    ((void (__stdcall *)(_DWORD))SetEnabled)(a1: 0);
  else
    ((void (__stdcall *)(int))SetEnabled)(a1: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000EE30
// Name: private: virtual void CDialogAddServer::FinishAddServer(class gameserveritem_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogAddServer::FinishAddServer(CDialogAddServer *this, gameserveritem_t *pServer)
{
  CServerBrowserDialog *v2; // eax

  v2 = ServerBrowserDialog();
  CServerBrowserDialog::AddServerToFavorites(this: v2, server: pServer);
}

//------------------------------------------------------------------------------
// Address: 0x1000EE50
// Name: public: virtual void CDialogAddBlacklistedServer::FinishAddServer(class gameserveritem_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDialogAddBlacklistedServer::FinishAddServer(
        CDialogAddBlacklistedServer *this@<ecx>,
        serverdisplay_t *a2@<edi>,
        gameserveritem_t *pServer)
{
  CServerBrowserDialog *v3; // eax
  CServerBrowserDialog *v4; // eax

  v3 = ServerBrowserDialog();
  CServerBrowserDialog::AddServerToBlacklist(this: v3, server: pServer);
  v4 = ServerBrowserDialog();
  CServerBrowserDialog::BlacklistsChanged(this: v4, a2);
}

//------------------------------------------------------------------------------
// Address: 0x1000EE80
// Name: public: virtual void CDialogAddBlacklistedServer::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogAddBlacklistedServer::ApplySchemeSettings(
        CDialogAddBlacklistedServer *this,
        vgui::IScheme *pScheme)
{
  CDialogAddServer::ApplySchemeSettings(this, pScheme);
  this->m_pAddServerButton->SetText_2(this: this->m_pAddServerButton, a2: "#ServerBrowser_AddAddressToBlacklist");
  this->m_pAddSelectedServerButton->SetText_2(
    this: this->m_pAddSelectedServerButton,
    a2: "#ServerBrowser_AddSelectedToBlacklist");
}

//------------------------------------------------------------------------------
// Address: 0x1000F060
// Name: public: virtual CDialogAddServer::~CDialogAddServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogAddServer::~CDialogAddServer(CDialogAddServer *this)
{
  int v2; // edi
  ISteamMatchmakingServers *m_pSteamMatchmakingServers; // ecx
  int *m_pMemory; // eax
  gameserveritem_t *v5; // eax

  v2 = 0;
  this->vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CDialogAddServer_vtbl *)&CDialogAddServer::`vftable'{for `vgui::Frame'};
  for ( this->ISteamMatchmakingPingResponse::__vftable = (ISteamMatchmakingPingResponse_vtbl *)&CDialogAddServer::`vftable'{for `ISteamMatchmakingPingResponse'};
        v2 < this->m_Queries.m_Size;
        ++v2 )
  {
    m_pSteamMatchmakingServers = steamapicontext->m_pSteamMatchmakingServers;
    if ( m_pSteamMatchmakingServers != nullptr )
      m_pSteamMatchmakingServers->CancelServerQuery(
        this: m_pSteamMatchmakingServers,
        a2: this->m_Queries.m_Memory.m_pMemory[v2]);
  }
  this->m_Queries.m_Size = 0;
  if ( this->m_Queries.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Queries.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Queries.m_Memory.m_pMemory);
      this->m_Queries.m_Memory.m_pMemory = nullptr;
    }
    this->m_Queries.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Queries.m_Memory.m_pMemory;
  this->m_Queries.m_pElements = m_pMemory;
  if ( this->m_Queries.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Queries.m_Memory.m_pMemory = nullptr;
    }
    this->m_Queries.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Servers.m_Size = 0;
  if ( this->m_Servers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Servers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Servers.m_Memory.m_pMemory);
      this->m_Servers.m_Memory.m_pMemory = nullptr;
    }
    this->m_Servers.m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_Servers.m_Memory.m_pMemory;
  this->m_Servers.m_pElements = v5;
  if ( this->m_Servers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      this->m_Servers.m_Memory.m_pMemory = nullptr;
    }
    this->m_Servers.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000F190
// Name: public: virtual struct vgui::PanelMessageMap __near * CDialogAddServer::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDialogAddServer::GetMessageMap(CDialogAddServer *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDialogAddServer::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDialogAddServer::GetMessageMap'::`2'::s_pMap;
  `CDialogAddServer::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDialogAddServer");
  `CDialogAddServer::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F1C0
// Name: public: virtual struct PanelAnimationMap __near * CDialogAddServer::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDialogAddServer::GetAnimMap(CDialogAddServer *this)
{
  return FindOrAddPanelAnimationMap(className: "CDialogAddServer");
}

//------------------------------------------------------------------------------
// Address: 0x1000F1D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDialogAddServer::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDialogAddServer::GetKBMap(CDialogAddServer *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDialogAddServer::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDialogAddServer::GetKBMap'::`2'::s_pMap;
  `CDialogAddServer::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDialogAddServer");
  `CDialogAddServer::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F200
// Name: public: static void CDialogAddServer::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDialogAddServer::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CDialogAddServer::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CDialogAddServer::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CDialogAddServer");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ItemSelected";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F290
// Name: public: static void CDialogAddServer::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDialogAddServer::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDialogAddServer::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CDialogAddServer::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CDialogAddServer");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "TextChanged";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F320
// Name: public: CDialogAddServer::CDialogAddServer(class vgui::Panel __near *,class IGameList __near *)
// Source: json
//------------------------------------------------------------------------------
CDialogAddServer *__thiscall CDialogAddServer::CDialogAddServer(
        CDialogAddServer *this,
        vgui::Panel *parent,
        IGameList *gameList)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::PropertySheet *v7; // eax
  vgui::PropertySheet *v8; // eax
  vgui::ListPanel *v9; // eax
  vgui::ListPanel *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  vgui::PropertySheet *m_pTabPanel; // ecx
  int Tall; // eax
  vgui::Panel *v22; // [esp-4h] [ebp-14h]
  int x; // [esp+Ch] [ebp-4h] BYREF
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: "DialogAddServer", showTaskbarIcon: true, bPopup: true);
  this->ISteamMatchmakingPingResponse::__vftable = (ISteamMatchmakingPingResponse_vtbl *)&ISteamMatchmakingPingResponse::`vftable';
  this->vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CDialogAddServer_vtbl *)&CDialogAddServer::`vftable'{for `vgui::Frame'};
  this->ISteamMatchmakingPingResponse::__vftable = (ISteamMatchmakingPingResponse_vtbl *)&CDialogAddServer::`vftable'{for `ISteamMatchmakingPingResponse'};
  if ( `CDialogAddServer::ChainToMap'::`2'::chained == 0 )
  {
    `CDialogAddServer::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDialogAddServer");
    v4->pfnClassName = CDialogAddServer::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CDialogAddServer::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDialogAddServer::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDialogAddServer");
    v5->pfnClassName = CDialogAddServer::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CDialogAddServer::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDialogAddServer::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDialogAddServer");
    v6->pfnClassName = CDialogAddServer::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CDialogAddServer::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CDialogAddServer::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  this->m_Servers.m_Memory.m_pMemory = nullptr;
  this->m_Servers.m_Memory.m_nAllocationCount = 0;
  this->m_Servers.m_Memory.m_nGrowSize = 0;
  this->m_Servers.m_Size = 0;
  this->m_Servers.m_pElements = nullptr;
  this->m_Queries.m_Memory.m_pMemory = nullptr;
  this->m_Queries.m_Memory.m_nAllocationCount = 0;
  this->m_Queries.m_Memory.m_nGrowSize = 0;
  this->m_Queries.m_Size = 0;
  this->m_Queries.m_pElements = nullptr;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  this->m_pGameList = gameList;
  vgui::Frame::SetTitle(this, title: "#ServerBrowser_AddServersTitle", surfaceTitle: true);
  vgui::Frame::SetSizeable(this, state: false);
  v7 = (vgui::PropertySheet *)operator new(nSize: 0x210u);
  if ( v7 != nullptr )
    v8 = vgui::PropertySheet::PropertySheet(this: v7, parent: this, panelName: "GameTabs", draggableTabs: false);
  else
    v8 = nullptr;
  this->m_pTabPanel = v8;
  v8->SetTabWidth(this: v8, a2: 72);
  v9 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v9 != nullptr )
    v10 = vgui::ListPanel::ListPanel(this: v9, parent: this, panelName: "Servers");
  else
    v10 = nullptr;
  this->m_pDiscoveredGames = v10;
  v10->AddColumnHeader(this: v10, a2: 0, a3: "Password", a4: "#ServerBrowser_Password", a5: 16, a6: 5);
  this->m_pDiscoveredGames->AddColumnHeader(
    this: this->m_pDiscoveredGames,
    a2: 1,
    a3: "Bots",
    a4: "#ServerBrowser_Bots",
    a5: 16,
    a6: 13);
  this->m_pDiscoveredGames->AddColumnHeader(
    this: this->m_pDiscoveredGames,
    a2: 2,
    a3: "Secure",
    a4: "#ServerBrowser_Secure",
    a5: 16,
    a6: 5);
  this->m_pDiscoveredGames->AddColumnHeader(
    this: this->m_pDiscoveredGames,
    a2: 3,
    a3: "Name",
    a4: "#ServerBrowser_Servers",
    a5: 20,
    a6: 18);
  this->m_pDiscoveredGames->AddColumnHeader(
    this: this->m_pDiscoveredGames,
    a2: 4,
    a3: "IPAddr",
    a4: "#ServerBrowser_IPAddress",
    a5: 60,
    a6: 8);
  this->m_pDiscoveredGames->AddColumnHeader(
    this: this->m_pDiscoveredGames,
    a2: 5,
    a3: "GameDesc",
    a4: "#ServerBrowser_Game",
    a5: 150,
    a6: 0);
  this->m_pDiscoveredGames->AddColumnHeader(
    this: this->m_pDiscoveredGames,
    a2: 6,
    a3: "Players",
    a4: "#ServerBrowser_Players",
    a5: 60,
    a6: 0);
  this->m_pDiscoveredGames->AddColumnHeader(
    this: this->m_pDiscoveredGames,
    a2: 7,
    a3: "Map",
    a4: "#ServerBrowser_Map",
    a5: 80,
    a6: 0);
  this->m_pDiscoveredGames->AddColumnHeader(
    this: this->m_pDiscoveredGames,
    a2: 8,
    a3: "Ping",
    a4: "#ServerBrowser_Latency",
    a5: 60,
    a6: 0);
  this->m_pDiscoveredGames->SetColumnHeaderTooltip(
    this: this->m_pDiscoveredGames,
    a2: 0,
    a3: "#ServerBrowser_PasswordColumn_Tooltip");
  this->m_pDiscoveredGames->SetColumnHeaderTooltip(
    this: this->m_pDiscoveredGames,
    a2: 1,
    a3: "#ServerBrowser_BotColumn_Tooltip");
  this->m_pDiscoveredGames->SetColumnHeaderTooltip(
    this: this->m_pDiscoveredGames,
    a2: 2,
    a3: "#ServerBrowser_SecureColumn_Tooltip");
  this->m_pDiscoveredGames->SetSortFunc(this: this->m_pDiscoveredGames, a2: 0, a3: PasswordCompare);
  this->m_pDiscoveredGames->SetSortFunc(this: this->m_pDiscoveredGames, a2: 1, a3: BotsCompare);
  this->m_pDiscoveredGames->SetSortFunc(this: this->m_pDiscoveredGames, a2: 2, a3: SecureCompare);
  this->m_pDiscoveredGames->SetSortFunc(this: this->m_pDiscoveredGames, a2: 3, a3: ServerNameCompare);
  this->m_pDiscoveredGames->SetSortFunc(this: this->m_pDiscoveredGames, a2: 4, a3: IPAddressCompare);
  this->m_pDiscoveredGames->SetSortFunc(this: this->m_pDiscoveredGames, a2: 5, a3: GameCompare);
  this->m_pDiscoveredGames->SetSortFunc(this: this->m_pDiscoveredGames, a2: 6, a3: PlayersCompare);
  this->m_pDiscoveredGames->SetSortFunc(this: this->m_pDiscoveredGames, a2: 7, a3: MapCompare);
  this->m_pDiscoveredGames->SetSortFunc(this: this->m_pDiscoveredGames, a2: 8, a3: PingCompare);
  this->m_pDiscoveredGames->SetSortColumn(this: this->m_pDiscoveredGames, a2: 8);
  v11 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: "ServerNameText");
  else
    v12 = nullptr;
  this->m_pTextEntry = v12;
  v12->AddActionSignalTarget_2(this: v12, a2: this);
  v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "TestServersButton",
            text: defaultValue,
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v14 = nullptr;
  this->m_pTestServersButton = v14;
  v15 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v15 != nullptr )
    v16 = vgui::Button::Button(
            this: v15,
            parent: this,
            panelName: "OKButton",
            text: defaultValue,
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v16 = nullptr;
  this->m_pAddServerButton = v16;
  v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v17 != nullptr )
    v18 = vgui::Button::Button(
            this: v17,
            parent: this,
            panelName: "SelectedOKButton",
            text: defaultValue,
            pActionSignalTarget: this,
            pCmd: "addselected");
  else
    v18 = nullptr;
  m_pTabPanel = this->m_pTabPanel;
  this->m_pAddSelectedServerButton = v18;
  m_pTabPanel->AddPage(
    this: m_pTabPanel,
    a2: this->m_pDiscoveredGames,
    a3: "#ServerBrowser_Servers",
    a4: nullptr,
    a5: false,
    a6: -1);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Servers/DialogAddServer.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  this->m_pAddServerButton->SetEnabled(this: this->m_pAddServerButton, a2: false);
  this->m_pTestServersButton->SetEnabled(this: this->m_pTestServersButton, a2: false);
  this->m_pAddSelectedServerButton->SetEnabled(this: this->m_pAddSelectedServerButton, a2: false);
  this->m_pAddSelectedServerButton->SetVisible(this: this->m_pAddSelectedServerButton, a2: false);
  this->m_pTabPanel->SetVisible(this: this->m_pTabPanel, a2: false);
  this->m_pTextEntry->RequestFocus(this: this->m_pTextEntry, a2: 0);
  vgui::Panel::GetPos(this: this->m_pTabPanel, &x, y: (int *)&parent);
  Tall = vgui::Panel::GetTall(this: this->m_pTabPanel);
  v22 = parent;
  this->m_OriginalHeight = (int)&parent->m_clrDropFrame + Tall + 2;
  vgui::Panel::SetTall(this, tall: (int)v22);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000F890
// Name: private: void CDialogAddServer::TestServers(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDialogAddServer::TestServers(CDialogAddServer *this@<ecx>, int a2@<ebx>)
{
  int v2; // edi
  const char *v4; // ebx
  const wchar_t *v5; // eax
  vgui::ILocalize_vtbl *v6; // ebx
  int v7; // eax
  netadr_s *m_pMemory; // ecx
  ISteamMatchmakingServers *m_pSteamMatchmakingServers; // edi
  ISteamMatchmakingServers_vtbl *v10; // ebx
  unsigned int v11; // eax
  int v12; // eax
  int v13; // edi
  int v14; // ebx
  int m_nAllocationCount; // eax
  int *v16; // ecx
  int v17; // eax
  int *v18; // edi
  bool v19; // zf
  int Port; // [esp-Ch] [ebp-A60h]
  ISteamMatchmakingPingResponse *v21; // [esp-8h] [ebp-A5Ch]
  wchar_t waddress[512]; // [esp+8h] [ebp-A4Ch] BYREF
  wchar_t wstr[512]; // [esp+408h] [ebp-64Ch] BYREF
  char str[512]; // [esp+808h] [ebp-24Ch] BYREF
  netadr_s newAddr; // [esp+A08h] [ebp-4Ch] BYREF
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > portsToTry; // [esp+A14h] [ebp-40h] BYREF
  ISteamMatchmakingPingResponse *v27; // [esp+A28h] [ebp-2Ch]
  CUtlVector<netadr_s,CUtlMemory<netadr_s,int> > vecAdress; // [esp+A2Ch] [ebp-28h] BYREF
  netadr_s netaddr; // [esp+A40h] [ebp-14h] BYREF
  int m_Size; // [esp+A4Ch] [ebp-8h]
  netadr_s *v31; // [esp+A50h] [ebp-4h]

  v2 = 0;
  if ( steamapicontext->m_pSteamMatchmakingServers != nullptr )
  {
    ((void (__thiscall *)(vgui::ListPanel *, const char *, int))this->m_pDiscoveredGames->SetEmptyListText_2)(
      a1: this->m_pDiscoveredGames,
      a2: defaultValue,
      a3: a2);
    v4 = this->GetControlString_2(this, a2: "ServerNameText", a3: defaultValue);
    netadr_s::SetIP(this: &netaddr, unIP: 0);
    netadr_s::SetPort(this: &netaddr, newport: 0);
    netadr_s::SetType(this: &netaddr, newtype: NA_IP);
    netadr_s::SetFromString(this: &netaddr, pch: v4, bUseDNS: true);
    this->m_Servers.m_Size = 0;
    memset(&vecAdress, 0, sizeof(vecAdress));
    if ( netadr_s::GetPort(this: &netaddr) != 0 )
    {
      CUtlVector<netadr_s,CUtlMemory<netadr_s,int>>::InsertBefore(this: &vecAdress, elem: 0, src: &netaddr);
    }
    else
    {
      memset(&portsToTry, 0, sizeof(portsToTry));
      GetMostCommonQueryPorts(ports: (CUtlMemory<wchar_t,int> *)&portsToTry);
      if ( portsToTry.m_Size > 0 )
      {
        do
        {
          newAddr = netaddr;
          netadr_s::SetPort(this: &newAddr, newport: portsToTry.m_Memory.m_pMemory[v2]);
          CUtlVector<netadr_s,CUtlMemory<netadr_s,int>>::InsertBefore(
            this: &vecAdress,
            elem: vecAdress.m_Size,
            src: &newAddr);
          ++v2;
        }
        while ( v2 < portsToTry.m_Size );
      }
      CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>::~CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&portsToTry);
    }
    this->m_pTabPanel->RemoveAllPages(this: this->m_pTabPanel);
    if ( *v4 != 0 )
    {
      _V_UTF8ToUnicode(a1: v4, a2: waddress, a3: 1024);
      v6 = g_pVGuiLocalize->__vftable;
      v7 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, wchar_t *))g_pVGuiLocalize->Find)(
             a1: g_pVGuiLocalize,
             a2: "#ServerBrowser_ServersResponding",
             a3: 1,
             a4: waddress);
      ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v6->ConstructString_3)(
        a1: g_pVGuiLocalize,
        a2: wstr,
        a3: 1024,
        a4: v7);
    }
    else
    {
      v5 = (const wchar_t *)((int (__thiscall *)(vgui::ILocalize *))g_pVGuiLocalize->Find)(a1: g_pVGuiLocalize);
      V_wcsncpy(pDest: wstr, pSrc: v5, maxLenInBytes: (int)"#ServerBrowser_ServersRespondingLocal");
    }
    _V_UnicodeToUTF8(a1: wstr, a2: str, a3: 512);
    ((void (__thiscall *)(vgui::PropertySheet *, vgui::ListPanel *, char *, _DWORD, _DWORD))this->m_pTabPanel->AddPage)(
      a1: this->m_pTabPanel,
      a2: this->m_pDiscoveredGames,
      a3: str,
      a4: 0,
      a5: 0);
    this->m_pTabPanel->InvalidateLayout(this: this->m_pTabPanel, a2: false, a3: false);
    if ( vecAdress.m_Size > 0 )
    {
      v27 = &this->ISteamMatchmakingPingResponse;
      m_pMemory = vecAdress.m_Memory.m_pMemory;
      v31 = vecAdress.m_Memory.m_pMemory;
      m_Size = vecAdress.m_Size;
      do
      {
        m_pSteamMatchmakingServers = steamapicontext->m_pSteamMatchmakingServers;
        v10 = m_pSteamMatchmakingServers->__vftable;
        v21 = v27;
        Port = netadr_s::GetPort(this: m_pMemory);
        v11 = netadr_s::addr_htonl(this: v31);
        v12 = v10->PingServer(this: m_pSteamMatchmakingServers, a2: v11, a3: Port, a4: v21);
        v13 = this->m_Queries.m_Size;
        v14 = v12;
        m_nAllocationCount = this->m_Queries.m_Memory.m_nAllocationCount;
        if ( v13 + 1 > m_nAllocationCount )
          CUtlMemory<unsigned long,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Queries,
            num: v13 - m_nAllocationCount + 1);
        ++this->m_Queries.m_Size;
        v16 = this->m_Queries.m_Memory.m_pMemory;
        v17 = this->m_Queries.m_Size - v13 - 1;
        this->m_Queries.m_pElements = v16;
        if ( v17 > 0 )
          _V_memmove(dest: &v16[v13 + 1], src: &v16[v13], count: 4 * v17);
        v18 = &this->m_Queries.m_Memory.m_pMemory[v13];
        if ( v18 != nullptr )
          *v18 = v14;
        m_pMemory = v31 + 1;
        v19 = m_Size-- == 1;
        ++v31;
      }
      while ( !v19 );
    }
    if ( vecAdress.m_Memory.m_nGrowSize >= 0 && vecAdress.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vecAdress.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FB60
// Name: public: virtual void CDialogAddServer::ServerResponded(class gameserveritem_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogAddServer::ServerResponded(CDialogAddServer *this, gameserveritem_t *server)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  char *m_szServerName; // eax
  vgui::Panel *v6; // eax
  const char *v7; // eax
  int v8; // eax
  int v9; // esi
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *m_nAppID; // [esp-4h] [ebp-3Ch]
  int v11; // [esp-4h] [ebp-3Ch]
  char buf[32]; // [esp+Ch] [ebp-2Ch] BYREF
  netadr_s reportedIPAddr; // [esp+2Ch] [ebp-Ch] BYREF

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "Server");
  else
    v4 = nullptr;
  m_szServerName = server->m_szServerName;
  if ( server->m_szServerName[0] == 0 )
    m_szServerName = servernetadr_t::GetConnectionAddressString(this: &server->m_NetAdr);
  KeyValues::SetString(this: v4, keyName: "name", value: m_szServerName);
  KeyValues::SetString(this: v4, keyName: "map", value: server->m_szMap);
  KeyValues::SetString(this: v4, keyName: "GameDir", value: server->m_szGameDir);
  KeyValues::SetString(this: v4, keyName: "GameDesc", value: server->m_szGameDescription);
  KeyValues::SetString(this: v4, keyName: "GameTags", value: server->m_szGameTags);
  KeyValues::SetInt(this: v4, keyName: "password", value: server->m_bPassword);
  KeyValues::SetInt(this: v4, keyName: "bots", value: server->m_nBotPlayers != 0 ? 2 : 0);
  if ( server->m_bSecure )
  {
    m_nAppID = (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)server->m_nAppID;
    v6 = (vgui::Panel *)ServerBrowser();
    v11 = CUtlBuffer::GetOverflow(this: v6, msglist: m_nAppID) + 3;
    KeyValues::SetInt(this: v4, keyName: "secure", value: v11);
  }
  else
  {
    KeyValues::SetInt(this: v4, keyName: "secure", value: 0);
  }
  netadr_s::SetIP(this: &reportedIPAddr, unIP: 0);
  netadr_s::SetPort(this: &reportedIPAddr, newport: 0);
  netadr_s::SetType(this: &reportedIPAddr, newtype: NA_IP);
  netadr_s::SetIP(this: &reportedIPAddr, unIP: server->m_NetAdr.m_unIP);
  netadr_s::SetPort(this: &reportedIPAddr, newport: server->m_NetAdr.m_usConnectionPort);
  v7 = netadr_s::ToString(this: &reportedIPAddr, baseOnly: false);
  KeyValues::SetString(this: v4, keyName: "IPAddr", value: v7);
  V_snprintf(pDest: buf, maxLen: 32, pFormat: "%d / %d", server->m_nPlayers, server->m_nMaxPlayers);
  KeyValues::SetString(this: v4, keyName: "Players", value: buf);
  KeyValues::SetInt(this: v4, keyName: "Ping", value: server->m_nPing);
  v8 = CUtlVector<gameserveritem_t,CUtlMemory<gameserveritem_t,int>>::InsertBefore(
         this: (CUtlVector<gameserveritem_t,CUtlMemory<gameserveritem_t,int> > *)&this->m_clrDragFrame,
         elem: this->m_SkipChild.m_iPanelID,
         src: server);
  v9 = (*(int (__thiscall **)(_DWORD, KeyValues *, int, _DWORD, _DWORD))(**(_DWORD **)&this->m_InternalKeyFocusTicked_register
                                                                       + 916))(
         a1: *(_DWORD *)&this->m_InternalKeyFocusTicked_register,
         a2: v4,
         a3: v8,
         a4: 0,
         a5: 0);
  if ( (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&this->m_InternalKeyFocusTicked_register + 920))(a1: *(_DWORD *)&this->m_InternalKeyFocusTicked_register) == 1 )
    (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)&this->m_InternalKeyFocusTicked_register + 1032))(
      a1: *(_DWORD *)&this->m_InternalKeyFocusTicked_register,
      a2: v9);
  KeyValues::deleteThis(this: v4);
  (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)&this->m_InternalKeyFocusTicked_register + 264))(
    a1: *(_DWORD *)&this->m_InternalKeyFocusTicked_register,
    a2: 0,
    a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000FD50
// Name: private: virtual void CDialogAddServer::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDialogAddServer::OnCommand(CDialogAddServer *this@<ecx>, int a2@<ebx>, const char *command)
{
  vgui::ListPanel *m_pDiscoveredGames; // ecx
  vgui::ListPanel_vtbl *v5; // edi
  int v6; // eax
  int v7; // eax
  vgui::ListPanel *v8; // ecx
  vgui::ListPanel_vtbl *v9; // edi
  int v10; // eax

  if ( _V_stricmp(s1: command, s2: "OK") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "TestServers") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "addselected") != 0 )
      {
        vgui::Frame::OnCommand(this, command);
      }
      else if ( this->m_pDiscoveredGames->GetSelectedItemsCount(this: this->m_pDiscoveredGames) != 0 )
      {
        m_pDiscoveredGames = this->m_pDiscoveredGames;
        v5 = m_pDiscoveredGames->__vftable;
        v6 = ((int (__stdcall *)(_DWORD))m_pDiscoveredGames->GetSelectedItem)(a1: 0);
        v7 = v5->GetItemUserData(this: this->m_pDiscoveredGames, a2: v6);
        this->FinishAddServer(this, a2: &this->m_Servers.m_Memory.m_pMemory[v7]);
        v8 = this->m_pDiscoveredGames;
        v9 = v8->__vftable;
        v10 = ((int (__stdcall *)(_DWORD))v8->GetSelectedItem)(a1: 0);
        v9->RemoveItem(this: this->m_pDiscoveredGames, a2: v10);
        this->m_pDiscoveredGames->SetEmptyListText_2(this: this->m_pDiscoveredGames, a2: defaultValue);
      }
    }
    else
    {
      vgui::Panel::SetTall(this, tall: this->m_OriginalHeight);
      this->m_pTabPanel->SetVisible(this: this->m_pTabPanel, a2: true);
      this->m_pAddSelectedServerButton->SetVisible(this: this->m_pAddSelectedServerButton, a2: true);
      CDialogAddServer::TestServers(this, a2);
    }
  }
  else
  {
    CDialogAddServer::OnOK(this);
  }
}
