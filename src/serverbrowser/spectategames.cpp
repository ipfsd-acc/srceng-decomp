// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: serverbrowser/spectategames.cpp
// Functions: 2
// ============================================================

#include "serverbrowser\spectategames.h"

//------------------------------------------------------------------------------
// Address: 0x10017430
// Name: public: CSpectateGames::CSpectateGames(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CSpectateGames *__thiscall CSpectateGames::CSpectateGames(CSpectateGames *this, KeyValues *parent)
{
  CInternetGames::CInternetGames(this, parent, panelName: "SpectateGames", eType: eSpectatorServer);
  this->CInternetGames::CBaseGamesPage::vgui::PropertyPage::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CSpectateGames_vtbl *)&CSpectateGames::`vftable'{for `vgui::PropertyPage'};
  this->CInternetGames::CBaseGamesPage::IGameList::__vftable = (IGameList_vtbl *)&CSpectateGames::`vftable'{for `IGameList'};
  this->CInternetGames::CBaseGamesPage::ISteamMatchmakingServerListResponse::__vftable = (ISteamMatchmakingServerListResponse_vtbl *)&CSpectateGames::`vftable'{for `ISteamMatchmakingServerListResponse'};
  this->CInternetGames::CBaseGamesPage::ISteamMatchmakingPingResponse::__vftable = (ISteamMatchmakingPingResponse_vtbl *)&CSpectateGames::`vftable'{for `ISteamMatchmakingPingResponse'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100174B0
// Name: protected: virtual void CSpectateGames::GetNewServerList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSpectateGames::GetNewServerList(CSpectateGames *this)
{
  MatchMakingKeyValuePair_t dest; // [esp+4h] [ebp-200h] BYREF

  strncpy((unsigned __int8 *)&dest, source: "proxy", count: 0x100u);
  strncpy(dest: (unsigned __int8 *)dest.m_szValue, source: "1", count: 0x100u);
  CUtlVector<MatchMakingKeyValuePair_t,CUtlMemory<MatchMakingKeyValuePair_t,int>>::InsertBefore(
    this: (CUtlVector<MatchMakingKeyValuePair_t,CUtlMemory<MatchMakingKeyValuePair_t,int> > *)&this->m_hMouseEventHandler,
    elem: this->m_sNavUpName.m_Storage.m_Memory.m_nAllocationCount,
    src: &dest);
  CInternetGames::GetNewServerList(this);
}
