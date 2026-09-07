// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: serverbrowser/favoritegames.cpp
// Functions: 18
// ============================================================

#include "serverbrowser\favoritegames.h"

//------------------------------------------------------------------------------
// Address: 0x10011C50
// Name: public: static char const __near * CFavoriteGames::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CFavoriteGames::GetPanelClassName()
{
  return "CFavoriteGames";
}

//------------------------------------------------------------------------------
// Address: 0x10011C60
// Name: public: void CFavoriteGames::LoadFavoritesList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFavoriteGames::LoadFavoritesList(CFavoriteGames *this)
{
  ISteamMatchmaking *m_pSteamMatchmaking; // ecx
  void (__thiscall *StartRefresh)(IGameList *); // eax

  m_pSteamMatchmaking = steamapicontext->m_pSteamMatchmaking;
  if ( m_pSteamMatchmaking == nullptr || m_pSteamMatchmaking->GetFavoriteGameCount(this: m_pSteamMatchmaking) != 0 )
    this->m_pGameList->SetEmptyListText_2(this: this->m_pGameList, a2: "#ServerBrowser_NoInternetGamesResponded");
  else
    this->m_pGameList->SetEmptyListText_2(this: this->m_pGameList, a2: "#ServerBrowser_NoFavoriteServers");
  if ( this->m_bRefreshOnListReload )
  {
    StartRefresh = this->StartRefresh;
    this->m_bRefreshOnListReload = false;
    StartRefresh(this: &this->IGameList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011CC0
// Name: public: virtual bool CFavoriteGames::SupportsItem(enum IGameList::InterfaceItem_e)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CFavoriteGames::SupportsItem(CFavoriteGames *this, IGameList::InterfaceItem_e item)
{
  return item == FILTERS || item == ADDSERVER || item == ADDCURRENTSERVER;
}

//------------------------------------------------------------------------------
// Address: 0x10011CE0
// Name: public: virtual void CFavoriteGames::RefreshComplete(void __near *,enum EMatchMakingServerResponse)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFavoriteGames::RefreshComplete(CFavoriteGames *this, void *hReq, EMatchMakingServerResponse response)
{
  ISteamMatchmaking *m_pSteamMatchmaking; // ecx

  (*(void (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 99) + 964))(a1: (char *)this - 396, a2: 0);
  m_pSteamMatchmaking = steamapicontext->m_pSteamMatchmaking;
  if ( m_pSteamMatchmaking == nullptr || m_pSteamMatchmaking->GetFavoriteGameCount(this: m_pSteamMatchmaking) != 0 )
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)this->m_lLastDoublePressTime + 1064))(
      a1: this->m_lLastDoublePressTime,
      a2: "#ServerBrowser_NoInternetGamesResponded");
  else
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)this->m_lLastDoublePressTime + 1064))(
      a1: this->m_lLastDoublePressTime,
      a2: "#ServerBrowser_NoFavoriteServers");
  (*(void (__thiscall **)(int))(*(_DWORD *)this->m_lLastDoublePressTime + 900))(a1: this->m_lLastDoublePressTime);
  CBaseGamesPage::RefreshComplete(this, hReq, response);
}

//------------------------------------------------------------------------------
// Address: 0x10011D50
// Name: private: virtual void CFavoriteGames::OnOpenContextMenu(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFavoriteGames::OnOpenContextMenu(CFavoriteGames *this, int itemID)
{
  CServerBrowserDialog *v3; // eax
  CServerContextMenu *ContextMenu; // edi
  unsigned int SelectedServerID; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  CGameListPanel *ActiveList; // [esp-4h] [ebp-Ch]

  ActiveList = CBaseGamesPage::GetActiveList(this);
  v3 = ServerBrowserDialog();
  ContextMenu = CServerBrowserDialog::GetContextMenu(this: v3, pPanel: ActiveList);
  SelectedServerID = CBaseGamesPage::GetSelectedServerID(this);
  if ( SelectedServerID == -1 )
  {
    CServerContextMenu::ShowMenu(
      this: ContextMenu,
      target: this,
      serverID: 0xFFFFFFFF,
      showConnect: false,
      showViewGameInfo: false,
      showRefresh: false,
      showAddToFavorites: false);
  }
  else
  {
    CServerContextMenu::ShowMenu(
      this: ContextMenu,
      target: this,
      serverID: SelectedServerID,
      showConnect: true,
      showViewGameInfo: true,
      showRefresh: true,
      showAddToFavorites: false);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "RemoveFromFavorites");
    else
      v7 = nullptr;
    ContextMenu->AddMenuItem(
      this: ContextMenu,
      a2: "RemoveServer",
      a3: "#ServerBrowser_RemoveServerFromFavorites",
      a4: v7,
      a5: this,
      a6: nullptr);
  }
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v9 = KeyValues::KeyValues(this: v8, setName: "AddServerByName");
  else
    v9 = nullptr;
  ContextMenu->AddMenuItem(
    this: ContextMenu,
    a2: "AddServerByName",
    a3: "#ServerBrowser_AddServerByIP",
    a4: v9,
    a5: this,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10011E10
// Name: private: virtual void CFavoriteGames::OnRemoveFromFavorites(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFavoriteGames::OnRemoveFromFavorites(CFavoriteGames *this@<ecx>, int a2@<edi>)
{
  int v3; // edi
  int v4; // eax
  vgui::ListPanelItem *v5; // eax
  gameserveritem_t *v6; // eax

  if ( steamapicontext->m_pSteamMatchmakingServers != nullptr && steamapicontext->m_pSteamMatchmaking != nullptr )
  {
    v3 = 0;
    if ( ((int (__thiscall *)(CGameListPanel *, int))this->m_pGameList->GetSelectedItemsCount)(
           a1: this->m_pGameList,
           a2) > 0 )
    {
      do
      {
        v4 = this->m_pGameList->GetSelectedItem(this: this->m_pGameList, a2: v3);
        v5 = this->m_pGameList->GetItemData(this: this->m_pGameList, a2: v4);
        v6 = steamapicontext->m_pSteamMatchmakingServers->GetServerDetails(
               this: steamapicontext->m_pSteamMatchmakingServers,
               a2: this->m_hRequest,
               a3: v5->userData);
        if ( v6 != nullptr )
          steamapicontext->m_pSteamMatchmaking->RemoveFavoriteGame(
            this: steamapicontext->m_pSteamMatchmaking,
            a2: v6->m_nAppID,
            a3: v6->m_NetAdr.m_unIP,
            a4: v6->m_NetAdr.m_usConnectionPort,
            a5: v6->m_NetAdr.m_usQueryPort,
            a6: 1u);
        ++v3;
      }
      while ( v3 < this->m_pGameList->GetSelectedItemsCount(this: this->m_pGameList) );
    }
    CBaseGamesPage::UpdateStatus(this);
    ((void (__thiscall *)(CFavoriteGames *, _DWORD))this->InvalidateLayout)(a1: this, a2: 0);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011F00
// Name: private: virtual void CFavoriteGames::OnAddServerByName(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFavoriteGames::OnAddServerByName(CFavoriteGames *this)
{
  CDialogAddServer *v2; // edi
  IGameList *v3; // eax
  CServerBrowserDialog *v4; // eax
  CDialogAddServer *v5; // esi
  IGameList *v6; // [esp-4h] [ebp-Ch]

  v2 = (CDialogAddServer *)operator new(nSize: 0x264u);
  if ( v2 != nullptr )
  {
    if ( this != nullptr )
      v3 = &this->IGameList;
    else
      v3 = nullptr;
    v6 = v3;
    v4 = ServerBrowserDialog();
    v5 = CDialogAddServer::CDialogAddServer(this: v2, parent: v4, gameList: v6);
  }
  else
  {
    v5 = nullptr;
  }
  v5->MoveToCenterOfScreen(this: v5);
  v5->DoModal(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10011F60
// Name: private: void CFavoriteGames::OnAddCurrentServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFavoriteGames::OnAddCurrentServer(CFavoriteGames *this)
{
  CServerBrowserDialog *v2; // eax
  gameserveritem_t *v3; // esi
  ISteamMatchmaking *m_pSteamMatchmaking; // edi
  int v5; // eax

  v2 = ServerBrowserDialog();
  v3 = v2->GetCurrentConnectedServer(this: v2);
  if ( v3 != nullptr )
  {
    m_pSteamMatchmaking = steamapicontext->m_pSteamMatchmaking;
    if ( m_pSteamMatchmaking != nullptr )
    {
      v5 = _time32(timeptr: nullptr);
      m_pSteamMatchmaking->AddFavoriteGame(
        this: m_pSteamMatchmaking,
        a2: v3->m_nAppID,
        a3: v3->m_NetAdr.m_unIP,
        a4: v3->m_NetAdr.m_usConnectionPort,
        a5: v3->m_NetAdr.m_usQueryPort,
        a6: 1u,
        a7: v5);
      this->m_bRefreshOnListReload = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011FC0
// Name: private: virtual void CFavoriteGames::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFavoriteGames::OnCommand(CFavoriteGames *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "AddServerByName") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "AddCurrentServer") != 0 )
      CBaseGamesPage::OnCommand(this, command);
    else
      CFavoriteGames::OnAddCurrentServer(this);
  }
  else
  {
    this->OnAddServerByName(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012020
// Name: public: void CFavoriteGames::OnConnectToGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFavoriteGames::OnConnectToGame(CFavoriteGames *this)
{
  this->m_pAddCurrentServer->SetEnabled(this: this->m_pAddCurrentServer, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10012040
// Name: public: void CFavoriteGames::OnDisconnectFromGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFavoriteGames::OnDisconnectFromGame(CFavoriteGames *this)
{
  this->m_pAddCurrentServer->SetEnabled(this: this->m_pAddCurrentServer, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10012090
// Name: public: virtual struct vgui::PanelMessageMap __near * CFavoriteGames::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CFavoriteGames::GetMessageMap(CFavoriteGames *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CFavoriteGames::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CFavoriteGames::GetMessageMap'::`2'::s_pMap;
  `CFavoriteGames::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CFavoriteGames");
  `CFavoriteGames::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100120C0
// Name: public: virtual struct PanelAnimationMap __near * CFavoriteGames::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CFavoriteGames::GetAnimMap(CFavoriteGames *this)
{
  return FindOrAddPanelAnimationMap(className: "CFavoriteGames");
}

//------------------------------------------------------------------------------
// Address: 0x100120D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CFavoriteGames::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CFavoriteGames::GetKBMap(CFavoriteGames *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CFavoriteGames::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CFavoriteGames::GetKBMap'::`2'::s_pMap;
  `CFavoriteGames::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CFavoriteGames");
  `CFavoriteGames::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012150
// Name: public: static void CFavoriteGames::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFavoriteGames::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CFavoriteGames::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CFavoriteGames::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CFavoriteGames::`vcall'{1056,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CFavoriteGames");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "OpenContextMenu";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "itemID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100121F0
// Name: public: static void CFavoriteGames::PanelMessageFunc_OnRemoveFromFavorites::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFavoriteGames::PanelMessageFunc_OnRemoveFromFavorites::InitVar(int a1@<ebp>)
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
  if ( !`CFavoriteGames::PanelMessageFunc_OnRemoveFromFavorites::InitVar'::`2'::bAdded )
  {
    `CFavoriteGames::PanelMessageFunc_OnRemoveFromFavorites::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Menu::`vcall'{1060,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CFavoriteGames");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "RemoveFromFavorites";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012280
// Name: public: static void CFavoriteGames::PanelMessageFunc_OnAddServerByName::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFavoriteGames::PanelMessageFunc_OnAddServerByName::InitVar(int a1@<ebp>)
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
  if ( !`CFavoriteGames::PanelMessageFunc_OnAddServerByName::InitVar'::`2'::bAdded )
  {
    `CFavoriteGames::PanelMessageFunc_OnAddServerByName::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Menu::`vcall'{1064,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CFavoriteGames");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "AddServerByName";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012310
// Name: public: CFavoriteGames::CFavoriteGames(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CFavoriteGames *__thiscall CFavoriteGames::CFavoriteGames(CFavoriteGames *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CBaseGamesPage::CBaseGamesPage(
    this,
    parent,
    name: "FavoriteGames",
    eType: eFavoritesServer,
    pCustomResFilename: nullptr);
  this->CBaseGamesPage::vgui::PropertyPage::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CFavoriteGames_vtbl *)&CFavoriteGames::`vftable'{for `vgui::PropertyPage'};
  this->CBaseGamesPage::IGameList::__vftable = (IGameList_vtbl *)&CFavoriteGames::`vftable'{for `IGameList'};
  this->CBaseGamesPage::ISteamMatchmakingServerListResponse::__vftable = (ISteamMatchmakingServerListResponse_vtbl *)&CFavoriteGames::`vftable'{for `ISteamMatchmakingServerListResponse'};
  this->CBaseGamesPage::ISteamMatchmakingPingResponse::__vftable = (ISteamMatchmakingPingResponse_vtbl *)&CFavoriteGames::`vftable'{for `ISteamMatchmakingPingResponse'};
  if ( `CFavoriteGames::ChainToMap'::`2'::chained == 0 )
  {
    `CFavoriteGames::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CFavoriteGames");
    v3->pfnClassName = CFavoriteGames::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseGamesPage");
  }
  if ( `CFavoriteGames::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CFavoriteGames::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CFavoriteGames");
    v4->pfnClassName = CFavoriteGames::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CBaseGamesPage");
  }
  if ( `CFavoriteGames::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CFavoriteGames::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CFavoriteGames");
    v5->pfnClassName = CFavoriteGames::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseGamesPage");
  }
  CFavoriteGames::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  CFavoriteGames::PanelMessageFunc_OnRemoveFromFavorites::InitVar(a1: (int)&savedregs);
  CFavoriteGames::PanelMessageFunc_OnAddServerByName::InitVar(a1: (int)&savedregs);
  this->m_bRefreshOnListReload = false;
  return this;
}
