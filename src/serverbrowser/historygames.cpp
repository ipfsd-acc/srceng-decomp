// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: serverbrowser/historygames.cpp
// Functions: 11
// ============================================================

#include "serverbrowser\historygames.h"

//------------------------------------------------------------------------------
// Address: 0x10012760
// Name: public: static char const __near * CHistoryGames::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHistoryGames::GetPanelClassName()
{
  return "CHistoryGames";
}

//------------------------------------------------------------------------------
// Address: 0x10012770
// Name: public: void CHistoryGames::LoadHistoryList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistoryGames::LoadHistoryList(CHistoryGames *this)
{
  void (__thiscall *StartRefresh)(IGameList *); // edx

  if ( IsSteamGameServerBrowsingEnabled() )
    this->m_pGameList->SetEmptyListText_2(this: this->m_pGameList, a2: "#ServerBrowser_NoServersPlayed");
  if ( this->m_bRefreshOnListReload )
  {
    StartRefresh = this->StartRefresh;
    this->m_bRefreshOnListReload = false;
    StartRefresh(this: &this->IGameList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100127D0
// Name: public: virtual void CHistoryGames::RefreshComplete(void __near *,enum EMatchMakingServerResponse)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistoryGames::RefreshComplete(CHistoryGames *this, void *hReq, EMatchMakingServerResponse response)
{
  (*(void (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 99) + 964))(a1: (char *)this - 396, a2: 0);
  (*(void (__thiscall **)(int, const char *))(*(_DWORD *)this->m_lLastDoublePressTime + 1064))(
    a1: this->m_lLastDoublePressTime,
    a2: "#ServerBrowser_NoServersPlayed");
  (*(void (__thiscall **)(int))(*(_DWORD *)this->m_lLastDoublePressTime + 900))(a1: this->m_lLastDoublePressTime);
  CBaseGamesPage::RefreshComplete(this, hReq, response);
}

//------------------------------------------------------------------------------
// Address: 0x10012820
// Name: private: virtual void CHistoryGames::OnOpenContextMenu(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHistoryGames::OnOpenContextMenu(CHistoryGames *this, int itemID)
{
  CServerBrowserDialog *v3; // eax
  CServerContextMenu *ContextMenu; // edi
  unsigned int SelectedServerID; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
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
      showAddToFavorites: true);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "RemoveFromHistory");
    else
      v7 = nullptr;
    ContextMenu->AddMenuItem(
      this: ContextMenu,
      a2: "RemoveServer",
      a3: "#ServerBrowser_RemoveServerFromHistory",
      a4: v7,
      a5: this,
      a6: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100128B0
// Name: private: virtual void CHistoryGames::OnRemoveFromHistory(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHistoryGames::OnRemoveFromHistory(CHistoryGames *this@<ecx>, int a2@<edi>)
{
  int i; // edi
  int v4; // eax
  vgui::ListPanelItem *v5; // eax
  gameserveritem_t *v6; // eax

  if ( steamapicontext->m_pSteamMatchmakingServers != nullptr && steamapicontext->m_pSteamMatchmaking != nullptr )
  {
    for ( i = ((int (__thiscall *)(CGameListPanel *, int))this->m_pGameList->GetSelectedItemsCount)(
                a1: this->m_pGameList,
                a2)
            - 1; i >= 0; --i )
    {
      v4 = this->m_pGameList->GetSelectedItem(this: this->m_pGameList, a2: i);
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
          a6: 2u);
    }
    CBaseGamesPage::UpdateStatus(this);
    ((void (__thiscall *)(CHistoryGames *, _DWORD))this->InvalidateLayout)(a1: this, a2: 0);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012980
// Name: public: virtual struct vgui::PanelMessageMap __near * CHistoryGames::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHistoryGames::GetMessageMap(CHistoryGames *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHistoryGames::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHistoryGames::GetMessageMap'::`2'::s_pMap;
  `CHistoryGames::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHistoryGames");
  `CHistoryGames::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100129B0
// Name: public: virtual struct PanelAnimationMap __near * CHistoryGames::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHistoryGames::GetAnimMap(CHistoryGames *this)
{
  return FindOrAddPanelAnimationMap(className: "CHistoryGames");
}

//------------------------------------------------------------------------------
// Address: 0x100129C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHistoryGames::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHistoryGames::GetKBMap(CHistoryGames *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHistoryGames::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHistoryGames::GetKBMap'::`2'::s_pMap;
  `CHistoryGames::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHistoryGames");
  `CHistoryGames::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012A40
// Name: public: static void CHistoryGames::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CHistoryGames::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CHistoryGames::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CHistoryGames::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CFavoriteGames::`vcall'{1056,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CHistoryGames");
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
// Address: 0x10012AE0
// Name: public: static void CHistoryGames::PanelMessageFunc_OnRemoveFromHistory::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CHistoryGames::PanelMessageFunc_OnRemoveFromHistory::InitVar(int a1@<ebp>)
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
  if ( !`CHistoryGames::PanelMessageFunc_OnRemoveFromHistory::InitVar'::`2'::bAdded )
  {
    `CHistoryGames::PanelMessageFunc_OnRemoveFromHistory::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Menu::`vcall'{1060,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CHistoryGames");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "RemoveFromHistory";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012B70
// Name: public: CHistoryGames::CHistoryGames(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CHistoryGames *__thiscall CHistoryGames::CHistoryGames(CHistoryGames *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  CGameListPanel *m_pGameList; // ecx
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CBaseGamesPage::CBaseGamesPage(this, parent, name: "HistoryGames", eType: eHistoryServer, pCustomResFilename: nullptr);
  this->CBaseGamesPage::vgui::PropertyPage::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CHistoryGames_vtbl *)&CHistoryGames::`vftable'{for `vgui::PropertyPage'};
  this->CBaseGamesPage::IGameList::__vftable = (IGameList_vtbl *)&CHistoryGames::`vftable'{for `IGameList'};
  this->CBaseGamesPage::ISteamMatchmakingServerListResponse::__vftable = (ISteamMatchmakingServerListResponse_vtbl *)&CHistoryGames::`vftable'{for `ISteamMatchmakingServerListResponse'};
  this->CBaseGamesPage::ISteamMatchmakingPingResponse::__vftable = (ISteamMatchmakingPingResponse_vtbl *)&CHistoryGames::`vftable'{for `ISteamMatchmakingPingResponse'};
  if ( `CHistoryGames::ChainToMap'::`2'::chained == 0 )
  {
    `CHistoryGames::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHistoryGames");
    v3->pfnClassName = CHistoryGames::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseGamesPage");
  }
  if ( `CHistoryGames::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHistoryGames::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHistoryGames");
    v4->pfnClassName = CHistoryGames::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CBaseGamesPage");
  }
  if ( `CHistoryGames::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHistoryGames::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHistoryGames");
    v5->pfnClassName = CHistoryGames::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseGamesPage");
  }
  CHistoryGames::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  CHistoryGames::PanelMessageFunc_OnRemoveFromHistory::InitVar(a1: (int)&savedregs);
  m_pGameList = this->m_pGameList;
  this->m_bRefreshOnListReload = false;
  m_pGameList->AddColumnHeader(
    this: m_pGameList,
    a2: 9,
    a3: "LastPlayed",
    a4: "#ServerBrowser_LastPlayed",
    a5: 100,
    a6: 0);
  this->m_pGameList->SetSortFunc(this: this->m_pGameList, a2: 9, a3: LastPlayedCompare);
  this->m_pGameList->SetSortColumn(this: this->m_pGameList, a2: 9);
  if ( !IsSteamGameServerBrowsingEnabled() )
  {
    this->m_pGameList->SetEmptyListText_2(this: this->m_pGameList, a2: "#ServerBrowser_OfflineMode");
    this->m_pConnect->SetEnabled(this: this->m_pConnect, a2: false);
    this->m_pRefreshAll->SetEnabled(this: this->m_pRefreshAll, a2: false);
    this->m_pRefreshQuick->SetEnabled(this: this->m_pRefreshQuick, a2: false);
    this->m_pAddServer->SetEnabled(this: this->m_pAddServer, a2: false);
    this->m_pFilter->SetEnabled(this: this->m_pFilter, a2: false);
  }
  return this;
}
