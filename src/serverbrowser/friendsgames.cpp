// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: serverbrowser/friendsgames.cpp
// Functions: 8
// ============================================================

#include "serverbrowser\friendsgames.h"

//------------------------------------------------------------------------------
// Address: 0x10012410
// Name: public: static char const __near * CFriendsGames::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CFriendsGames::GetPanelClassName()
{
  return "CFriendsGames";
}

//------------------------------------------------------------------------------
// Address: 0x10012420
// Name: public: virtual void CFriendsGames::RefreshComplete(void __near *,enum EMatchMakingServerResponse)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFriendsGames::RefreshComplete(CFriendsGames *this, void *hReq, EMatchMakingServerResponse response)
{
  (*(void (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 99) + 964))(a1: (char *)this - 396, a2: 0);
  (*(void (__thiscall **)(int))(*(_DWORD *)this->m_lLastDoublePressTime + 900))(a1: this->m_lLastDoublePressTime);
  this->m_pAddToFavoritesButton = nullptr;
  if ( IsSteamGameServerBrowsingEnabled() )
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)this->m_lLastDoublePressTime + 1064))(
      a1: this->m_lLastDoublePressTime,
      a2: "#ServerBrowser_NoFriendsServers");
  CBaseGamesPage::RefreshComplete(this, hReq, response);
}

//------------------------------------------------------------------------------
// Address: 0x10012490
// Name: public: virtual struct vgui::PanelMessageMap __near * CFriendsGames::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CFriendsGames::GetMessageMap(CFriendsGames *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CFriendsGames::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CFriendsGames::GetMessageMap'::`2'::s_pMap;
  `CFriendsGames::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CFriendsGames");
  `CFriendsGames::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100124C0
// Name: public: virtual struct PanelAnimationMap __near * CFriendsGames::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CFriendsGames::GetAnimMap(CFriendsGames *this)
{
  return FindOrAddPanelAnimationMap(className: "CFriendsGames");
}

//------------------------------------------------------------------------------
// Address: 0x100124D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CFriendsGames::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CFriendsGames::GetKBMap(CFriendsGames *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CFriendsGames::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CFriendsGames::GetKBMap'::`2'::s_pMap;
  `CFriendsGames::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CFriendsGames");
  `CFriendsGames::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012550
// Name: public: static void CFriendsGames::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFriendsGames::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CFriendsGames::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CFriendsGames::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CFavoriteGames::`vcall'{1056,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CFriendsGames");
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
// Address: 0x100125F0
// Name: public: CFriendsGames::CFriendsGames(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CFriendsGames *__thiscall CFriendsGames::CFriendsGames(CFriendsGames *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CBaseGamesPage::CBaseGamesPage(this, parent, name: "FriendsGames", eType: eFriendsServer, pCustomResFilename: nullptr);
  this->CBaseGamesPage::vgui::PropertyPage::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CFriendsGames_vtbl *)&CFriendsGames::`vftable'{for `vgui::PropertyPage'};
  this->CBaseGamesPage::IGameList::__vftable = (IGameList_vtbl *)&CFriendsGames::`vftable'{for `IGameList'};
  this->CBaseGamesPage::ISteamMatchmakingServerListResponse::__vftable = (ISteamMatchmakingServerListResponse_vtbl *)&CFriendsGames::`vftable'{for `ISteamMatchmakingServerListResponse'};
  this->CBaseGamesPage::ISteamMatchmakingPingResponse::__vftable = (ISteamMatchmakingPingResponse_vtbl *)&CFriendsGames::`vftable'{for `ISteamMatchmakingPingResponse'};
  if ( `CFriendsGames::ChainToMap'::`2'::chained == 0 )
  {
    `CFriendsGames::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CFriendsGames");
    v3->pfnClassName = CFriendsGames::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseGamesPage");
  }
  if ( `CFriendsGames::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CFriendsGames::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CFriendsGames");
    v4->pfnClassName = CFriendsGames::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CBaseGamesPage");
  }
  if ( `CFriendsGames::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CFriendsGames::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CFriendsGames");
    v5->pfnClassName = CFriendsGames::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseGamesPage");
  }
  CFriendsGames::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  this->m_iServerRefreshCount = 0;
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

//------------------------------------------------------------------------------
// Address: 0x100130B0
// Name: private: virtual void CFriendsGames::OnOpenContextMenu(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFriendsGames::OnOpenContextMenu(CFriendsGames *this, int itemID)
{
  unsigned int SelectedServerID; // edi
  CServerBrowserDialog *v4; // eax
  CServerContextMenu *ContextMenu; // eax
  CGameListPanel *ActiveList; // [esp-4h] [ebp-Ch]

  SelectedServerID = CBaseGamesPage::GetSelectedServerID(this);
  if ( SelectedServerID != -1 )
  {
    ActiveList = CBaseGamesPage::GetActiveList(this);
    v4 = ServerBrowserDialog();
    ContextMenu = CServerBrowserDialog::GetContextMenu(this: v4, pPanel: ActiveList);
    CServerContextMenu::ShowMenu(
      this: ContextMenu,
      target: this,
      serverID: SelectedServerID,
      showConnect: true,
      showViewGameInfo: true,
      showRefresh: true,
      showAddToFavorites: true);
  }
}
