// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: serverbrowser/internetgames.cpp
// Functions: 21
// ============================================================

#include "serverbrowser\internetgames.h"

//------------------------------------------------------------------------------
// Address: 0x10012D20
// Name: public: static char const __near * CInternetGames::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CInternetGames::GetPanelClassName()
{
  return "CInternetGames";
}

//------------------------------------------------------------------------------
// Address: 0x10012D30
// Name: protected: virtual void CInternetGames::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CInternetGames::PerformLayout(CInternetGames *this@<ecx>, int a2@<edi>)
{
  CServerBrowserDialog *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  if ( this->m_bOfflineMode )
    goto LABEL_9;
  if ( this->m_bRequireUpdate )
  {
    v3 = ServerBrowserDialog();
    if ( v3->IsVisible(this: v3) )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "GetNewServerList");
      else
        v5 = nullptr;
      ((void (__thiscall *)(CInternetGames *, CInternetGames *, KeyValues *, int))this->PostMessage)(
        a1: this,
        a2: this,
        a3: v5,
        a4: 1036831949);
      this->m_bRequireUpdate = false;
    }
  }
  if ( this->m_bOfflineMode )
  {
LABEL_9:
    this->m_pGameList->SetEmptyListText_2(this: this->m_pGameList, a2: "#ServerBrowser_OfflineMode");
    this->m_pConnect->SetEnabled(this: this->m_pConnect, a2: false);
    this->m_pRefreshAll->SetEnabled(this: this->m_pRefreshAll, a2: false);
    this->m_pRefreshQuick->SetEnabled(this: this->m_pRefreshQuick, a2: false);
    this->m_pAddServer->SetEnabled(this: this->m_pAddServer, a2: false);
    this->m_pFilter->SetEnabled(this: this->m_pFilter, a2: false);
  }
  CBaseGamesPage::PerformLayout(this, a2);
  this->m_pLocationFilter->SetEnabled(this: this->m_pLocationFilter, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10012E30
// Name: public: virtual void CInternetGames::OnPageShow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInternetGames::OnPageShow(CInternetGames *this)
{
  CServerBrowserDialog *v2; // eax

  if ( this->m_pGameList->GetItemCount(this: this->m_pGameList) == 0 )
  {
    v2 = ServerBrowserDialog();
    if ( v2->IsVisible(this: v2) )
      CBaseGamesPage::OnPageShow(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012E70
// Name: public: virtual void CInternetGames::ServerResponded(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInternetGames::ServerResponded(CInternetGames *this, void *hReq, int iServer)
{
  LOBYTE(this->m_mapGamesFilterItem.m_Tree.m_FirstFree) = 1;
  CBaseGamesPage::ServerResponded(this, hReq, iServer);
  this->m_mapGamesFilterItem.m_Tree.m_LastAlloc.index = 257;
}

//------------------------------------------------------------------------------
// Address: 0x10012EA0
// Name: public: virtual void CInternetGames::RefreshComplete(void __near *,enum EMatchMakingServerResponse)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInternetGames::RefreshComplete(CInternetGames *this, void *hReq, EMatchMakingServerResponse response)
{
  int v4; // edx
  char *v5; // ecx
  int v6; // ebx
  int v7; // eax
  int v8; // ebx
  int v9; // eax

  (*(void (__thiscall **)(char *, _DWORD))(*((_DWORD *)this - 99) + 964))(a1: (char *)this - 396, a2: 0);
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 99) + 1028))(a1: (char *)this - 396);
  if ( response == eServerFailedToRespond )
  {
    (*(void (__stdcall **)(const char *))(*(_DWORD *)this->m_lLastDoublePressTime + 1064))(a1: "#ServerBrowser_MasterServerNotResponsive");
  }
  else
  {
    v4 = *((_DWORD *)this - 99);
    v5 = (char *)this - 396;
    if ( HIBYTE(this->m_mapGamesFilterItem.m_Tree.m_LastAlloc.index) != 0 )
    {
      v6 = *(_DWORD *)this->m_lLastDoublePressTime;
      v7 = (*(int (__thiscall **)(char *))(v4 + 1056))(a1: v5);
      (*(void (__stdcall **)(int))(v6 + 1064))(a1: v7);
    }
    else
    {
      v8 = *(_DWORD *)this->m_lLastDoublePressTime;
      if ( response == eNoServersListedOnMasterServer )
        v9 = (*(int (__fastcall **)(char *))(v4 + 1060))(a1: v5);
      else
        v9 = (*(int (__fastcall **)(char *))(v4 + 1064))(a1: v5);
      (*(void (__stdcall **)(int))(v8 + 1064))(a1: v9);
    }
  }
  LOBYTE(this->m_mapGamesFilterItem.m_Tree.m_FirstFree) = 0;
  *(float *)&this->m_mapGamesFilterItem.m_Tree.m_Root = _Plat_FloatTime();
  if ( (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 99) + 136))(a1: (char *)this - 396) != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)this->m_lLastDoublePressTime + 900))(a1: this->m_lLastDoublePressTime);
  CBaseGamesPage::UpdateStatus(this: (CInternetGames *)((char *)this - 396));
  CBaseGamesPage::RefreshComplete(this, hReq, response);
}

//------------------------------------------------------------------------------
// Address: 0x10012FB0
// Name: public: virtual void CInternetGames::GetNewServerList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInternetGames::GetNewServerList(CInternetGames *this)
{
  unsigned int m_infoFont; // ecx

  CBaseGamesPage::GetNewServerList(this);
  CBaseGamesPage::UpdateStatus(this: (CInternetGames *)((char *)this - 392));
  m_infoFont = this->m_infoFont;
  *(_WORD *)((char *)&this->m_mapGamesFilterItem.m_Tree.m_pElements + 1) = 0;
  HIBYTE(this->m_mapGamesFilterItem.m_Tree.m_pElements) = 0;
  (*(void (__thiscall **)(unsigned int))(*(_DWORD *)m_infoFont + 972))(a1: m_infoFont);
}

//------------------------------------------------------------------------------
// Address: 0x10012FF0
// Name: public: virtual bool CInternetGames::SupportsItem(enum IGameList::InterfaceItem_e)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInternetGames::SupportsItem(CInternetGames *this, IGameList::InterfaceItem_e item)
{
  return (unsigned int)item <= GETNEWLIST;
}

//------------------------------------------------------------------------------
// Address: 0x10013010
// Name: private: void CInternetGames::CheckRedoSort(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInternetGames::CheckRedoSort(CInternetGames *this)
{
  double v2; // st7
  CGameListPanel *m_pGameList; // ecx
  float fCurTime; // [esp+4h] [ebp-4h]

  if ( this->m_bDirty )
  {
    v2 = _Plat_FloatTime();
    fCurTime = v2;
    if ( v2 - this->m_fLastSort >= 1.5 )
    {
      if ( g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT)
        || g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: MOUSE_RIGHT) )
      {
        this->m_fLastSort = (float)(fCurTime - 1.5) + 1.0;
      }
      else
      {
        m_pGameList = this->m_pGameList;
        this->m_bDirty = false;
        this->m_fLastSort = fCurTime;
        m_pGameList->SortList(this: m_pGameList);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100130F0
// Name: public: virtual void CInternetGames::OnRefreshServer(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CInternetGames::OnRefreshServer(CInternetGames *this@<ecx>, int a2@<edi>, int serverID)
{
  CServerBrowserDialog *v3; // eax

  CBaseGamesPage::OnRefreshServer(this, a2, serverID);
  v3 = ServerBrowserDialog();
  CServerBrowserDialog::UpdateStatusText(this: v3, fmt: "#ServerBrowser_GettingNewServerList");
}

//------------------------------------------------------------------------------
// Address: 0x10013120
// Name: public: virtual int CInternetGames::GetRegionCodeToFilter(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CInternetGames::GetRegionCodeToFilter(CInternetGames *this)
{
  KeyValues *ActiveItemUserData; // eax

  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pLocationFilter);
  if ( ActiveItemUserData != nullptr )
    return KeyValues::GetInt(this: ActiveItemUserData, keyName: "code", defaultValue: 0);
  else
    return 255;
}

//------------------------------------------------------------------------------
// Address: 0x10013150
// Name: public: virtual bool CInternetGames::CheckTagFilter(class gameserveritem_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CInternetGames::CheckTagFilter(CInternetGames *this, gameserveritem_t *server)
{
  return server == (gameserveritem_t *)-236 || server->m_szGameTags[0] == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10013190
// Name: protected: virtual void CInternetGames::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInternetGames::OnTick(CInternetGames *this)
{
  if ( this->m_bOfflineMode )
  {
    vgui::PropertyPage::OnPageHide(this);
  }
  else
  {
    vgui::PropertyPage::OnPageHide(this);
    CInternetGames::CheckRedoSort(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100131B0
// Name: public: virtual CInternetGames::~CInternetGames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInternetGames::~CInternetGames(CInternetGames *this)
{
  this->CBaseGamesPage::vgui::PropertyPage::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CInternetGames_vtbl *)&CInternetGames::`vftable'{for `vgui::PropertyPage'};
  this->CBaseGamesPage::IGameList::__vftable = (IGameList_vtbl *)&CInternetGames::`vftable'{for `IGameList'};
  this->CBaseGamesPage::ISteamMatchmakingServerListResponse::__vftable = (ISteamMatchmakingServerListResponse_vtbl *)&CInternetGames::`vftable'{for `ISteamMatchmakingServerListResponse'};
  this->CBaseGamesPage::ISteamMatchmakingPingResponse::__vftable = (ISteamMatchmakingPingResponse_vtbl *)&CInternetGames::`vftable'{for `ISteamMatchmakingPingResponse'};
  CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>::~CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Regions);
  CBaseGamesPage::~CBaseGamesPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x100131F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CInternetGames::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CInternetGames::GetMessageMap(CInternetGames *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CInternetGames::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CInternetGames::GetMessageMap'::`2'::s_pMap;
  `CInternetGames::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CInternetGames");
  `CInternetGames::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10013220
// Name: public: virtual struct PanelAnimationMap __near * CInternetGames::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CInternetGames::GetAnimMap(CInternetGames *this)
{
  return FindOrAddPanelAnimationMap(className: "CInternetGames");
}

//------------------------------------------------------------------------------
// Address: 0x10013230
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CInternetGames::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CInternetGames::GetKBMap(CInternetGames *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CInternetGames::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CInternetGames::GetKBMap'::`2'::s_pMap;
  `CInternetGames::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CInternetGames");
  `CInternetGames::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10013260
// Name: public: static void CInternetGames::PanelMessageFunc_GetNewServerList::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CInternetGames::PanelMessageFunc_GetNewServerList::InitVar(int a1@<ebp>)
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
  if ( !`CInternetGames::PanelMessageFunc_GetNewServerList::InitVar'::`2'::bAdded )
  {
    `CInternetGames::PanelMessageFunc_GetNewServerList::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CInternetGames::`vcall'{8,{flat}};
    *(__int64 *)((char *)v5.m128i_i64 + 4) = 392;
    v5.m128i_i32[3] = 0;
    v1 = vgui::FindOrAddPanelMessageMap(className: "CInternetGames");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "GetNewServerList";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100132F0
// Name: public: static void CInternetGames::PanelMessageFunc_OnRefreshServer::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CInternetGames::PanelMessageFunc_OnRefreshServer::InitVar(int a1@<ebp>)
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
  if ( !`CInternetGames::PanelMessageFunc_OnRefreshServer::InitVar'::`2'::bAdded )
  {
    `CInternetGames::PanelMessageFunc_OnRefreshServer::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseGamesPage::`vcall'{1036,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CInternetGames");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "RefreshServer";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "serverID";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013390
// Name: public: static void CInternetGames::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CInternetGames::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CInternetGames::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CInternetGames::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Menu::`vcall'{1068,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CInternetGames");
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
// Address: 0x10013430
// Name: public: CInternetGames::CInternetGames(class vgui::Panel __near *,char const __near *,enum CBaseGamesPage::EPageType)
// Source: json
//------------------------------------------------------------------------------
CInternetGames *__thiscall CInternetGames::CInternetGames(
        CInternetGames *this,
        KeyValues *parent,
        const char *panelName,
        CBaseGamesPage::EPageType eType)
{
  vgui::PanelMessageMap *v5; // esi
  PanelAnimationMap *v6; // esi
  vgui::PanelKeyBindingMap *v7; // esi
  bool v8; // al
  vgui::ComboBox *m_pLocationFilter; // ecx
  KeyValues *v10; // eax
  IBaseFileSystem *v11; // eax
  KeyValues *FirstSubKey; // ebx
  const char *String; // eax
  KeyValues *v14; // eax
  vgui::ComboBox_vtbl *v15; // ebx
  const char *v16; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CInternetGames::regions_s *m_pMemory; // ecx
  int v20; // eax
  CInternetGames::regions_s *v21; // ebx
  KeyValues *srv; // [esp+Ch] [ebp-8h]
  KeyValues *regionKV; // [esp+10h] [ebp-4h]
  int savedregs; // [esp+14h] [ebp+0h] BYREF
  KeyValues *kv; // [esp+1Ch] [ebp+8h]

  CBaseGamesPage::CBaseGamesPage(this, (vgui::Panel *)parent, name: panelName, eType, pCustomResFilename: nullptr);
  this->CBaseGamesPage::vgui::PropertyPage::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CInternetGames_vtbl *)&CInternetGames::`vftable'{for `vgui::PropertyPage'};
  this->CBaseGamesPage::IGameList::__vftable = (IGameList_vtbl *)&CInternetGames::`vftable'{for `IGameList'};
  this->CBaseGamesPage::ISteamMatchmakingServerListResponse::__vftable = (ISteamMatchmakingServerListResponse_vtbl *)&CInternetGames::`vftable'{for `ISteamMatchmakingServerListResponse'};
  this->CBaseGamesPage::ISteamMatchmakingPingResponse::__vftable = (ISteamMatchmakingPingResponse_vtbl *)&CInternetGames::`vftable'{for `ISteamMatchmakingPingResponse'};
  if ( `CInternetGames::ChainToMap'::`2'::chained == 0 )
  {
    `CInternetGames::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CInternetGames");
    v5->pfnClassName = CInternetGames::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseGamesPage");
  }
  if ( `CInternetGames::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CInternetGames::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CInternetGames");
    v6->pfnClassName = CInternetGames::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseGamesPage");
  }
  if ( `CInternetGames::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CInternetGames::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CInternetGames");
    v7->pfnClassName = CInternetGames::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseGamesPage");
  }
  CInternetGames::PanelMessageFunc_GetNewServerList::InitVar(a1: (int)&savedregs);
  CInternetGames::PanelMessageFunc_OnRefreshServer::InitVar(a1: (int)&savedregs);
  CInternetGames::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  this->m_Regions.m_Memory.m_pMemory = nullptr;
  this->m_Regions.m_Memory.m_nAllocationCount = 0;
  this->m_Regions.m_Memory.m_nGrowSize = 0;
  this->m_Regions.m_Size = 0;
  this->m_Regions.m_pElements = nullptr;
  this->m_fLastSort = 0.0;
  *(_WORD *)&this->m_bDirty = 256;
  v8 = IsSteamGameServerBrowsingEnabled();
  m_pLocationFilter = this->m_pLocationFilter;
  this->m_bOfflineMode = !v8;
  this->m_bAnyServersRetrievedFromMaster = false;
  *(_WORD *)&this->m_bAnyServersRespondedToQuery = 0;
  vgui::ComboBox::RemoveAll(this: m_pLocationFilter);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    kv = KeyValues::KeyValues(this: v10, setName: "Regions");
  else
    kv = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v11 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v11 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: kv,
         filesystem: v11,
         resourceName: "servers/Regions.vdf",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: kv);
    srv = FirstSubKey;
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        LOWORD(panelName) = -1;
        String = KeyValues::GetString(this: FirstSubKey, keyName: "text", defaultValue: defaultValue);
        CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&eType + 1, pStr: String);
        LOWORD(panelName) = HIWORD(eType);
        BYTE2(panelName) = KeyValues::GetInt(this: FirstSubKey, keyName: "code", defaultValue: 0);
        v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v14 != nullptr )
          regionKV = KeyValues::KeyValues(this: v14, setName: "region", firstKey: "code", firstValue: BYTE2(panelName));
        else
          regionKV = nullptr;
        v15 = this->m_pLocationFilter->CBaseGamesPage::__vftable;
        v16 = CUtlSymbol::String(this: (CUtlSymbol *)&panelName);
        v15->AddItem_2(this: this->m_pLocationFilter, a2: v16, a3: regionKV);
        KeyValues::deleteThis(this: regionKV);
        m_Size = this->m_Regions.m_Size;
        m_nAllocationCount = this->m_Regions.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<unsigned long,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Regions,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_Regions.m_Size;
        m_pMemory = this->m_Regions.m_Memory.m_pMemory;
        v20 = this->m_Regions.m_Size - m_Size - 1;
        this->m_Regions.m_pElements = m_pMemory;
        if ( v20 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v20);
        v21 = &this->m_Regions.m_Memory.m_pMemory[m_Size];
        if ( v21 != nullptr )
        {
          v21->name.m_Id = (unsigned __int16)panelName;
          v21->code = BYTE2(panelName);
        }
        srv = KeyValues::GetNextKey(this: srv);
        if ( srv == nullptr )
          break;
        FirstSubKey = srv;
      }
    }
  }
  KeyValues::deleteThis(this: kv);
  CBaseGamesPage::LoadFilterSettings(this);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 250);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10013790
// Name: public: virtual void CInternetGames::ServerFailedToRespond(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInternetGames::ServerFailedToRespond(CInternetGames *this, void *hReq, int iServer)
{
  unsigned __int16 v4; // ax
  CUtlMap<int,serverdisplay_t,unsigned short>::Node_t search; // [esp+Ch] [ebp-10h] BYREF

  LOBYTE(this->m_mapGamesFilterItem.m_Tree.m_FirstFree) = 1;
  if ( steamapicontext->m_pSteamMatchmakingServers->GetServerDetails(
         this: steamapicontext->m_pSteamMatchmakingServers,
         a2: hReq,
         a3: iServer)->m_bHadSuccessfulResponse )
  {
    ((void (__thiscall *)(CInternetGames *, void *, int))this->GetVPanel)(a1: this, a2: hReq, a3: iServer);
  }
  else
  {
    search.elem.m_iListID = -1;
    search.elem.m_iServerID = -1;
    search.elem.m_bDoNotRefresh = true;
    search.key = iServer;
    v4 = CUtlRBTree<CUtlMap<int,serverdisplay_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,serverdisplay_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,serverdisplay_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
           this: (CUtlRBTree<CUtlMap<int,serverdisplay_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,serverdisplay_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,serverdisplay_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&this->m_OverridableColorEntries.m_Memory.m_nGrowSize,
           &search);
    if ( v4 != 0xFFFF )
      CBaseGamesPage::RemoveServer(
        this: (CInternetGames *)((char *)this - 396),
        server: (serverdisplay_t *)(this->m_OverridableColorEntries.m_Size + 24 * v4 + 12));
    ++this->m_sNavLeftName.m_Storage.m_Memory.m_nAllocationCount;
  }
}
