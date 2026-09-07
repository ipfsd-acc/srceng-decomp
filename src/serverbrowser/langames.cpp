// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: serverbrowser/langames.cpp
// Functions: 17
// ============================================================

#include "serverbrowser\langames.h"

//------------------------------------------------------------------------------
// Address: 0x100127C0
// Name: public: virtual bool CLanGames::SupportsItem(enum IGameList::InterfaceItem_e)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLanGames::SupportsItem(CFriendsGames *this, IGameList::InterfaceItem_e item)
{
  return item == FILTERS;
}

//------------------------------------------------------------------------------
// Address: 0x10013830
// Name: public: static char const __near * CLanGames::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CLanGames::GetPanelClassName()
{
  return "CLanGames";
}

//------------------------------------------------------------------------------
// Address: 0x10013840
// Name: public: virtual void CLanGames::OnPageShow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLanGames::OnPageShow(CLanGames *this)
{
  if ( this->m_bAutoRefresh )
    this->StartRefresh(this: &this->IGameList);
}

//------------------------------------------------------------------------------
// Address: 0x10013860
// Name: private: virtual void CLanGames::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLanGames::OnTick(CLanGames *this)
{
  vgui::PropertyPage::OnPageHide(this);
  this->CheckRetryRequest(this);
}

//------------------------------------------------------------------------------
// Address: 0x10013880
// Name: public: virtual void CLanGames::StartRefresh(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CLanGames::StartRefresh(CLanGames *this@<ecx>, int a2@<edi>)
{
  CBaseGamesPage::StartRefresh(this, a2);
  *(double *)&this->m_mapGamesFilterItem.m_Tree.m_Elements.m_nAllocationCount = _Plat_FloatTime();
}

//------------------------------------------------------------------------------
// Address: 0x100138A0
// Name: public: virtual void CLanGames::StopRefresh(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CLanGames::StopRefresh(CLanGames *this@<ecx>, serverdisplay_t *a2@<edi>)
{
  CBaseGamesPage::StopRefresh(this, a2);
  LOBYTE(this->m_mapGamesFilterItem.m_Tree.m_LessFunc.m_LessFunc) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100138C0
// Name: private: virtual void CLanGames::CheckRetryRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLanGames::CheckRetryRequest(CLanGames *this)
{
  if ( this->m_bRequesting && _Plat_FloatTime() - this->m_fRequestTime > 0.4000000059604645 )
    this->m_bRequesting = false;
}

//------------------------------------------------------------------------------
// Address: 0x100138F0
// Name: public: virtual void CLanGames::RefreshComplete(void __near *,enum EMatchMakingServerResponse)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLanGames::RefreshComplete(CLanGames *this, void *hReq, EMatchMakingServerResponse response)
{
  int m_lLastDoublePressTime; // ecx

  (*(void (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 99) + 964))(a1: (char *)this - 396, a2: 0);
  (*(void (__thiscall **)(int))(*(_DWORD *)this->m_lLastDoublePressTime + 900))(a1: this->m_lLastDoublePressTime);
  m_lLastDoublePressTime = this->m_lLastDoublePressTime;
  this->m_pAddToFavoritesButton = nullptr;
  (*(void (__thiscall **)(int, const char *))(*(_DWORD *)m_lLastDoublePressTime + 1064))(
    a1: m_lLastDoublePressTime,
    a2: "#ServerBrowser_NoLanServers");
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 99) + 1056))(a1: (char *)this - 396);
  CBaseGamesPage::RefreshComplete(this, hReq, response);
}

//------------------------------------------------------------------------------
// Address: 0x10013960
// Name: public: virtual void CLanGames::SetEmptyListText(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLanGames::SetEmptyListText(CLanGames *this)
{
  this->m_pGameList->SetEmptyListText_2(this: this->m_pGameList, a2: "#ServerBrowser_NoLanServers");
}

//------------------------------------------------------------------------------
// Address: 0x10013980
// Name: private: virtual void CLanGames::OnOpenContextMenu(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLanGames::OnOpenContextMenu(CLanGames *this, int row)
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
      showAddToFavorites: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100139C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CLanGames::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CLanGames::GetMessageMap(CLanGames *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CLanGames::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CLanGames::GetMessageMap'::`2'::s_pMap;
  `CLanGames::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CLanGames");
  `CLanGames::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100139F0
// Name: public: virtual struct PanelAnimationMap __near * CLanGames::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CLanGames::GetAnimMap(CLanGames *this)
{
  return FindOrAddPanelAnimationMap(className: "CLanGames");
}

//------------------------------------------------------------------------------
// Address: 0x10013A00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CLanGames::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CLanGames::GetKBMap(CLanGames *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CLanGames::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CLanGames::GetKBMap'::`2'::s_pMap;
  `CLanGames::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CLanGames");
  `CLanGames::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10013A80
// Name: public: static void CLanGames::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CLanGames::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CLanGames::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CLanGames::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Menu::`vcall'{1064,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CLanGames");
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
// Address: 0x10013B20
// Name: public: CLanGames::CLanGames(class vgui::Panel __near *,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CLanGames *__thiscall CLanGames::CLanGames(
        CLanGames *this,
        vgui::Panel *parent,
        bool bAutoRefresh,
        const char *pCustomResFilename)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CBaseGamesPage::CBaseGamesPage(this, parent, name: "LanGames", eType: eLANServer, pCustomResFilename);
  this->CBaseGamesPage::vgui::PropertyPage::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CLanGames_vtbl *)&CLanGames::`vftable'{for `vgui::PropertyPage'};
  this->CBaseGamesPage::IGameList::__vftable = (IGameList_vtbl *)&CLanGames::`vftable'{for `IGameList'};
  this->CBaseGamesPage::ISteamMatchmakingServerListResponse::__vftable = (ISteamMatchmakingServerListResponse_vtbl *)&CLanGames::`vftable'{for `ISteamMatchmakingServerListResponse'};
  this->CBaseGamesPage::ISteamMatchmakingPingResponse::__vftable = (ISteamMatchmakingPingResponse_vtbl *)&CLanGames::`vftable'{for `ISteamMatchmakingPingResponse'};
  if ( `CLanGames::ChainToMap'::`2'::chained == 0 )
  {
    `CLanGames::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CLanGames");
    v5->pfnClassName = CLanGames::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseGamesPage");
  }
  if ( `CLanGames::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CLanGames::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CLanGames");
    v6->pfnClassName = CLanGames::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseGamesPage");
  }
  if ( `CLanGames::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CLanGames::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CLanGames");
    v7->pfnClassName = CLanGames::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseGamesPage");
  }
  CLanGames::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  this->m_iServerRefreshCount = 0;
  this->m_bRequesting = false;
  this->m_bAutoRefresh = bAutoRefresh;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10013C30
// Name: public: virtual void CLanGames::ServerFailedToRespond(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLanGames::ServerFailedToRespond(CLanGames *this, void *hReq, int iServer)
{
  unsigned __int16 v4; // ax
  CUtlMap<int,serverdisplay_t,unsigned short>::Node_t search; // [esp+4h] [ebp-10h] BYREF

  search.elem.m_iListID = -1;
  search.elem.m_iServerID = -1;
  search.elem.m_bDoNotRefresh = true;
  search.key = iServer;
  v4 = CUtlRBTree<CUtlMap<int,serverdisplay_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,serverdisplay_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,serverdisplay_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: (CUtlRBTree<CUtlMap<int,serverdisplay_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,serverdisplay_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,serverdisplay_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_OverridableColorEntries.m_Memory.m_nGrowSize,
         &search);
  if ( v4 != 0xFFFF )
    CBaseGamesPage::RemoveServer(
      this: (CLanGames *)((char *)this - 396),
      server: (serverdisplay_t *)(this->m_OverridableColorEntries.m_Size + 24 * v4 + 12));
}

//------------------------------------------------------------------------------
// Address: 0x10013C90
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}
