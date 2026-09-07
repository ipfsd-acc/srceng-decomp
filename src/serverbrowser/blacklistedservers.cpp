// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: serverbrowser/blacklistedservers.cpp
// Functions: 39
// ============================================================

#include "serverbrowser\blacklistedservers.h"

//------------------------------------------------------------------------------
// Address: 0x1000BC20
// Name: public: static char const __near * CDialogAddBlacklistedServer::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDialogAddBlacklistedServer::GetPanelClassName()
{
  return "CDialogAddBlacklistedServer";
}

//------------------------------------------------------------------------------
// Address: 0x1000BC30
// Name: public: static char const __near * CBlacklistedServers::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBlacklistedServers::GetPanelClassName()
{
  return "CBlacklistedServers";
}

//------------------------------------------------------------------------------
// Address: 0x1000BC40
// Name: public: virtual void CBlacklistedServers::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlacklistedServers::ApplySchemeSettings(CBlacklistedServers *this, vgui::IScheme *pScheme)
{
  const char *v3; // ebx
  vgui::IScheme_vtbl *v4; // ebx
  bool v5; // al
  unsigned int v6; // eax
  vgui::IScheme_vtbl *v7; // ebx
  bool v8; // al

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v3 = "PLATFORM";
  if ( g_pFullFileSystem->FileExists(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: "servers/BlacklistedServersPage.res",
         a3: "MOD") )
  {
    v3 = "MOD";
  }
  this->LoadControlSettings(this, a2: "servers/BlacklistedServersPage.res", a3: v3, a4: nullptr, a5: nullptr);
  v4 = pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = v4->GetFont(this: pScheme, a2: "ListSmall", a3: v5);
  if ( v6 == 0 )
  {
    v7 = pScheme->__vftable;
    v8 = this->IsProportional(this);
    v6 = v7->GetFont(this: pScheme, a2: "DefaultSmall", a3: v8);
  }
  this->m_pGameList->SetFont(this: this->m_pGameList, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1000BCF0
// Name: private: virtual void CBlacklistedServers::OnPageShow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlacklistedServers::OnPageShow(CBlacklistedServers *this)
{
  this->m_pGameList->SetEmptyListText_2(this: this->m_pGameList, a2: "#ServerBrowser_NoBlacklistedServers");
  this->m_pGameList->SortList(this: this->m_pGameList);
  vgui::PropertyPage::OnPageHide(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000BD20
// Name: private: virtual void CBlacklistedServers::OnOpenContextMenu(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlacklistedServers::OnOpenContextMenu(CBlacklistedServers *this, int itemID)
{
  CServerBrowserDialog *v3; // eax
  CServerContextMenu *ContextMenu; // edi
  int v5; // ebx
  vgui::ListPanel *v6; // ecx
  vgui::ListPanel_vtbl *v7; // ebx
  int v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  vgui::ListPanel *m_pGameList; // [esp-4h] [ebp-10h]

  m_pGameList = this->m_pGameList;
  v3 = ServerBrowserDialog();
  ContextMenu = CServerBrowserDialog::GetContextMenu(this: v3, pPanel: m_pGameList);
  v5 = -1;
  if ( this->m_pGameList->GetSelectedItemsCount(this: this->m_pGameList) != 0 )
  {
    v6 = this->m_pGameList;
    v7 = v6->__vftable;
    v8 = ((int (__stdcall *)(_DWORD))v6->GetSelectedItem)(a1: 0);
    v5 = v7->GetItemUserData(this: this->m_pGameList, a2: v8);
  }
  CServerContextMenu::ShowMenu(
    this: ContextMenu,
    target: this,
    serverID: 0xFFFFFFFF,
    showConnect: false,
    showViewGameInfo: false,
    showRefresh: false,
    showAddToFavorites: false);
  if ( v5 != -1 )
  {
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
      v10 = KeyValues::KeyValues(this: v9, setName: "RemoveFromBlacklist");
    else
      v10 = nullptr;
    ContextMenu->AddMenuItem(
      this: ContextMenu,
      a2: "RemoveServer",
      a3: "#ServerBrowser_RemoveServerFromBlacklist",
      a4: v10,
      a5: this,
      a6: nullptr);
  }
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "AddServerByName");
  else
    v12 = nullptr;
  ContextMenu->AddMenuItem(
    this: ContextMenu,
    a2: "AddServerByName",
    a3: "#ServerBrowser_AddServerByIP",
    a4: v12,
    a5: this,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000BE10
// Name: public: void CBlacklistedServers::OnConnectToGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlacklistedServers::OnConnectToGame(CBlacklistedServers *this)
{
  this->m_pAddCurrentServer->SetEnabled(this: this->m_pAddCurrentServer, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x1000BE30
// Name: public: void CBlacklistedServers::OnDisconnectFromGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlacklistedServers::OnDisconnectFromGame(CBlacklistedServers *this)
{
  this->m_pAddCurrentServer->SetEnabled(this: this->m_pAddCurrentServer, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1000BE70
// Name: public: CDialogAddBlacklistedServer::CDialogAddBlacklistedServer(class vgui::Panel __near *,class IGameList __near *)
// Source: json
//------------------------------------------------------------------------------
CDialogAddBlacklistedServer *__thiscall CDialogAddBlacklistedServer::CDialogAddBlacklistedServer(
        CDialogAddBlacklistedServer *this,
        vgui::Panel *parent,
        IGameList *gameList)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CDialogAddServer::CDialogAddServer(this, parent, gameList);
  this->CDialogAddServer::vgui::Frame::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CDialogAddBlacklistedServer_vtbl *)&CDialogAddBlacklistedServer::`vftable'{for `vgui::Frame'};
  this->CDialogAddServer::ISteamMatchmakingPingResponse::__vftable = (ISteamMatchmakingPingResponse_vtbl *)&CDialogAddBlacklistedServer::`vftable'{for `ISteamMatchmakingPingResponse'};
  if ( `CDialogAddBlacklistedServer::ChainToMap'::`2'::chained == 0 )
  {
    `CDialogAddBlacklistedServer::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDialogAddBlacklistedServer");
    v4->pfnClassName = CDialogAddBlacklistedServer::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CDialogAddServer");
  }
  if ( `CDialogAddBlacklistedServer::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDialogAddBlacklistedServer::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDialogAddBlacklistedServer");
    v5->pfnClassName = CDialogAddBlacklistedServer::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CDialogAddServer");
  }
  if ( `CDialogAddBlacklistedServer::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDialogAddBlacklistedServer::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDialogAddBlacklistedServer");
    v6->pfnClassName = CDialogAddBlacklistedServer::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CDialogAddServer");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000BF40
// Name: public: virtual struct vgui::PanelMessageMap __near * CDialogAddBlacklistedServer::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDialogAddBlacklistedServer::GetMessageMap(CDialogAddBlacklistedServer *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDialogAddBlacklistedServer::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDialogAddBlacklistedServer::GetMessageMap'::`2'::s_pMap;
  `CDialogAddBlacklistedServer::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDialogAddBlacklistedServer");
  `CDialogAddBlacklistedServer::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000BF70
// Name: public: virtual struct PanelAnimationMap __near * CDialogAddBlacklistedServer::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDialogAddBlacklistedServer::GetAnimMap(CDialogAddBlacklistedServer *this)
{
  return FindOrAddPanelAnimationMap(className: "CDialogAddBlacklistedServer");
}

//------------------------------------------------------------------------------
// Address: 0x1000BF80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDialogAddBlacklistedServer::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDialogAddBlacklistedServer::GetKBMap(CDialogAddBlacklistedServer *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDialogAddBlacklistedServer::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDialogAddBlacklistedServer::GetKBMap'::`2'::s_pMap;
  `CDialogAddBlacklistedServer::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDialogAddBlacklistedServer");
  `CDialogAddBlacklistedServer::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000BFE0
// Name: private: virtual void CBlacklistedServers::OnAddServerByName(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlacklistedServers::OnAddServerByName(CBlacklistedServers *this)
{
  CDialogAddBlacklistedServer *v1; // esi
  CServerBrowserDialog *v2; // eax
  CDialogAddBlacklistedServer *v3; // esi

  v1 = (CDialogAddBlacklistedServer *)operator new(nSize: 0x268u);
  if ( v1 != nullptr )
  {
    v2 = ServerBrowserDialog();
    v3 = CDialogAddBlacklistedServer::CDialogAddBlacklistedServer(this: v1, parent: v2, gameList: nullptr);
  }
  else
  {
    v3 = nullptr;
  }
  v3->MoveToCenterOfScreen(this: v3);
  v3->DoModal(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1000C030
// Name: private: void CBlacklistedServers::OnImportBlacklist(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlacklistedServers::OnImportBlacklist(CBlacklistedServers *this)
{
  vgui::Panel *v2; // eax
  vgui::FileOpenDialog *v3; // eax
  CDragDropHelperPanel *v4; // eax
  vgui::FileOpenDialog *v5; // eax
  vgui::FileOpenDialog *v6; // eax
  vgui::FileOpenDialog *v7; // eax

  if ( vgui::PHandle::Get(this: &this->m_hImportDialog) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hImportDialog);
    v2->MarkForDeletion(this: v2);
  }
  v3 = (vgui::FileOpenDialog *)operator new(nSize: 0x6B0u);
  if ( v3 != nullptr )
    v4 = (CDragDropHelperPanel *)vgui::FileOpenDialog::FileOpenDialog(
                                   this: v3,
                                   parent: this,
                                   title: "#ServerBrowser_ImportBlacklistTitle",
                                   bOpenOnly: true,
                                   pContextKeyValues: nullptr);
  else
    v4 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hImportDialog,
    pPanel: v4);
  if ( vgui::PHandle::Get(this: &this->m_hImportDialog) != nullptr )
  {
    v5 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hImportDialog);
    vgui::FileOpenDialog::SetStartDirectory(this: v5, dir: "cfg/");
    v6 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hImportDialog);
    vgui::FileOpenDialog::AddFilter(
      this: v6,
      filter: "*.txt",
      filterName: "#ServerBrowser_BlacklistFiles",
      bActive: true,
      pFilterInfo: nullptr);
    v7 = (vgui::FileOpenDialog *)vgui::PHandle::Get(this: &this->m_hImportDialog);
    vgui::FileOpenDialog::DoModal(this: v7, bUnused: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C0F0
// Name: public: void CBlacklistedServers::SaveBlacklistedList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlacklistedServers::SaveBlacklistedList(CBlacklistedServers *this)
{
  KeyValues *v2; // eax
  int v3; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  const char *v6; // eax
  IBaseFileSystem *v7; // eax
  int i; // [esp+Ch] [ebp-8h]
  KeyValues *pKV; // [esp+10h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v3 = 0;
  if ( v2 != nullptr )
    pKV = KeyValues::KeyValues(this: v2, setName: "serverblacklist");
  else
    pKV = nullptr;
  for ( i = 0; i < this->m_Blacklist.m_Size; ++i )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "server");
    else
      v5 = nullptr;
    KeyValues::SetString(this: v5, keyName: "name", value: this->m_Blacklist.m_Memory.m_pMemory[v3].m_szServerName);
    KeyValues::SetInt(this: v5, keyName: "date", value: this->m_Blacklist.m_Memory.m_pMemory[v3].m_ulTimeBlacklistedAt);
    v6 = netadr_s::ToString(this: &this->m_Blacklist.m_Memory.m_pMemory[v3].m_NetAdr, baseOnly: false);
    KeyValues::SetString(this: v5, keyName: "addr", value: v6);
    KeyValues::AddSubKey(this: pKV, pSubkey: v5);
    ++v3;
  }
  if ( g_pFullFileSystem != nullptr )
    v7 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v7 = nullptr;
  KeyValues::SaveToFile(this: pKV, filesystem: v7, resourceName: "cfg/server_blacklist.txt", pathID: "GAME");
  KeyValues::deleteThis(this: pKV);
}

//------------------------------------------------------------------------------
// Address: 0x1000C1F0
// Name: private: void CBlacklistedServers::AddBlacklistedServer(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBlacklistedServers::AddBlacklistedServer(CBlacklistedServers *this@<ecx>, int a2@<ebx>, int iIdx)
{
  int v4; // edi
  int v5; // ebx
  KeyValues *v6; // ebx
  KeyValues *v7; // eax
  const tm *v8; // eax
  const char *v9; // eax
  bool v10; // al
  vgui::ListPanel *m_pGameList; // ecx
  char start[4]; // [esp+4h] [ebp-44h] BYREF
  char buf[64]; // [esp+8h] [ebp-40h] BYREF
  int iItemId; // [esp+50h] [ebp+8h]

  if ( iIdx >= 0 && iIdx < this->m_Blacklist.m_Size )
  {
    v4 = iIdx;
    v5 = ((int (__thiscall *)(vgui::ListPanel *, int, int))this->m_pGameList->GetItemIDFromUserData)(
           a1: this->m_pGameList,
           a2: this->m_Blacklist.m_Memory.m_pMemory[iIdx].m_nServerID,
           a3: a2);
    iItemId = v5;
    if ( this->m_pGameList->IsValidItemID(this: this->m_pGameList, a2: v5) )
    {
      v6 = this->m_pGameList->GetItem(this: this->m_pGameList, a2: v5);
      this->m_pGameList->SetUserData(
        this: this->m_pGameList,
        a2: iItemId,
        a3: this->m_Blacklist.m_Memory.m_pMemory[v4].m_nServerID);
    }
    else
    {
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
        v6 = KeyValues::KeyValues(this: v7, setName: "Server");
      else
        v6 = nullptr;
    }
    KeyValues::SetString(this: v6, keyName: "name", value: this->m_Blacklist.m_Memory.m_pMemory[v4].m_szServerName);
    v8 = _localtime32(ptime: (const int *)&this->m_Blacklist.m_Memory.m_pMemory[v4].m_ulTimeBlacklistedAt);
    if ( v8 != nullptr )
    {
      strftime(string: buf, maxsize: 0x40u, format: "%a %d %b %I:%M%p", timeptr: v8);
      _V_strlower(start: &start[strlen(buf)]);
      KeyValues::SetString(this: v6, keyName: "BlacklistedAt", value: buf);
    }
    v9 = netadr_s::ToString(this: &this->m_Blacklist.m_Memory.m_pMemory[v4].m_NetAdr, baseOnly: false);
    KeyValues::SetString(this: v6, keyName: "IPAddr", value: v9);
    v10 = this->m_pGameList->IsValidItemID(this: this->m_pGameList, a2: iItemId);
    m_pGameList = this->m_pGameList;
    if ( v10 )
    {
      m_pGameList->ApplyItemChanges(this: m_pGameList, a2: iItemId);
    }
    else
    {
      ((void (__thiscall *)(vgui::ListPanel *, KeyValues *, int, _DWORD))m_pGameList->AddItem)(
        a1: m_pGameList,
        a2: v6,
        a3: this->m_Blacklist.m_Memory.m_pMemory[v4].m_nServerID,
        a4: 0);
      KeyValues::deleteThis(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C390
// Name: public: bool CBlacklistedServers::IsServerBlacklisted(class gameserveritem_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBlacklistedServers::IsServerBlacklisted(CBlacklistedServers *this, gameserveritem_t *server)
{
  unsigned __int16 m_usConnectionPort; // si
  int v4; // esi
  int i; // ebx
  blacklisted_server_t *m_pMemory; // ecx
  blacklisted_server_t *v7; // esi
  char *m_szServerName; // ebx
  unsigned __int16 Port; // ax
  char *ConnectionAddressString; // eax
  blacklisted_server_t *v12; // esi
  char *v13; // ebx
  char *v14; // eax
  const char *v15; // [esp-4h] [ebp-20h]
  const char *v16; // [esp-4h] [ebp-20h]
  netadr_s netAdr; // [esp+Ch] [ebp-10h] BYREF
  netadr_s *v18; // [esp+18h] [ebp-4h]

  m_usConnectionPort = server->m_NetAdr.m_usConnectionPort;
  netadr_s::SetIP(this: &netAdr, unIP: server->m_NetAdr.m_unIP);
  netadr_s::SetPort(this: &netAdr, newport: m_usConnectionPort);
  netadr_s::SetType(this: &netAdr, newtype: NA_IP);
  v4 = 0;
  if ( this->m_Blacklist.m_Size <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    m_pMemory = this->m_Blacklist.m_Memory.m_pMemory;
    if ( m_pMemory[i].m_NetAdr.ip[3] != 0 )
      break;
    if ( netadr_s::CompareClassCAdr(this: &m_pMemory[i].m_NetAdr, a: &netAdr) )
    {
      if ( sb_showblacklists.m_pParent != nullptr && sb_showblacklists.m_pParent->m_Value.m_nValue != 0 )
      {
        v7 = &this->m_Blacklist.m_Memory.m_pMemory[v4];
        if ( server->m_szServerName[0] != 0 )
          m_szServerName = server->m_szServerName;
        else
          m_szServerName = servernetadr_t::GetConnectionAddressString(this: &server->m_NetAdr);
        v15 = netadr_s::ToString(this: &v7->m_NetAdr, baseOnly: false);
        ConnectionAddressString = servernetadr_t::GetConnectionAddressString(this: &server->m_NetAdr);
        _Msg(a1: "Blacklisted '%s' (%s), due to rule '%s' (Class C).\n", m_szServerName, ConnectionAddressString, v15);
      }
      return 1;
    }
LABEL_10:
    if ( ++v4 >= this->m_Blacklist.m_Size )
      return 0;
  }
  v18 = (netadr_s *)&m_pMemory[i];
  Port = netadr_s::GetPort(this: &m_pMemory[i].m_NetAdr);
  if ( !netadr_s::CompareAdr(this: v18 + 6, a: &netAdr, onlyBase: Port == 0) )
    goto LABEL_10;
  if ( sb_showblacklists.m_pParent == nullptr || sb_showblacklists.m_pParent->m_Value.m_nValue == 0 )
    return 1;
  v12 = &this->m_Blacklist.m_Memory.m_pMemory[v4];
  if ( server->m_szServerName[0] != 0 )
    v13 = server->m_szServerName;
  else
    v13 = servernetadr_t::GetConnectionAddressString(this: &server->m_NetAdr);
  v16 = netadr_s::ToString(this: &v12->m_NetAdr, baseOnly: false);
  v14 = servernetadr_t::GetConnectionAddressString(this: &server->m_NetAdr);
  _Msg(a1: "Blacklisted '%s' (%s), due to rule '%s'.\n", v13, v14, v16);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000C510
// Name: int BlacklistedServerNameCompare(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl BlacklistedServerNameCompare(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *p1,
        const vgui::ListPanelItem *p2)
{
  CBlacklistedServers *m_pBlacklist; // edx
  int m_Size; // ecx
  int v5; // eax
  blacklisted_server_t *m_pMemory; // esi
  blacklisted_server_t *v7; // edx
  blacklisted_server_t *v8; // ebx
  CBlacklistedServers *v9; // ecx
  int v10; // edx
  int v11; // eax
  blacklisted_server_t *v12; // esi
  blacklisted_server_t *v13; // ecx
  blacklisted_server_t *v14; // eax

  m_pBlacklist = ServerBrowserDialog()->m_pBlacklist;
  m_Size = m_pBlacklist->m_Blacklist.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    m_pMemory = m_pBlacklist->m_Blacklist.m_Memory.m_pMemory;
    v7 = m_pMemory;
    while ( v7->m_nServerID != p1->userData )
    {
      ++v5;
      ++v7;
      if ( v5 >= m_Size )
        goto LABEL_5;
    }
    v8 = &m_pMemory[v5];
  }
  v9 = ServerBrowserDialog()->m_pBlacklist;
  v10 = v9->m_Blacklist.m_Size;
  v11 = 0;
  if ( v10 <= 0 )
  {
LABEL_10:
    v14 = nullptr;
  }
  else
  {
    v12 = v9->m_Blacklist.m_Memory.m_pMemory;
    v13 = v12;
    while ( v13->m_nServerID != p2->userData )
    {
      ++v11;
      ++v13;
      if ( v11 >= v10 )
        goto LABEL_10;
    }
    v14 = &v12[v11];
  }
  if ( v8 != nullptr )
  {
    if ( v14 != nullptr )
      return _V_stricmp(s1: v8->m_szServerName, s2: v14->m_szServerName);
    else
      return 1;
  }
  else if ( v14 != nullptr )
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C5D0
// Name: int BlacklistedIPAddressCompare(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl BlacklistedIPAddressCompare(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *p1,
        const vgui::ListPanelItem *p2)
{
  CBlacklistedServers *m_pBlacklist; // edx
  int m_Size; // ecx
  int v5; // eax
  blacklisted_server_t *m_pMemory; // esi
  blacklisted_server_t *v7; // edx
  const netadr_s *v8; // ebx
  CBlacklistedServers *v9; // ecx
  int v10; // edx
  int v11; // eax
  blacklisted_server_t *v12; // esi
  blacklisted_server_t *v13; // ecx
  const netadr_s *v14; // eax
  netadr_s *v16; // esi

  m_pBlacklist = ServerBrowserDialog()->m_pBlacklist;
  m_Size = m_pBlacklist->m_Blacklist.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    m_pMemory = m_pBlacklist->m_Blacklist.m_Memory.m_pMemory;
    v7 = m_pMemory;
    while ( v7->m_nServerID != p1->userData )
    {
      ++v5;
      ++v7;
      if ( v5 >= m_Size )
        goto LABEL_5;
    }
    v8 = (const netadr_s *)&m_pMemory[v5];
  }
  v9 = ServerBrowserDialog()->m_pBlacklist;
  v10 = v9->m_Blacklist.m_Size;
  v11 = 0;
  if ( v10 <= 0 )
  {
LABEL_10:
    v14 = nullptr;
  }
  else
  {
    v12 = v9->m_Blacklist.m_Memory.m_pMemory;
    v13 = v12;
    while ( v13->m_nServerID != p2->userData )
    {
      ++v11;
      ++v13;
      if ( v11 >= v10 )
        goto LABEL_10;
    }
    v14 = (const netadr_s *)&v12[v11];
  }
  if ( v8 != nullptr )
  {
    if ( v14 != nullptr )
    {
      v16 = (netadr_s *)&v14[6];
      if ( netadr_s::operator<(this: (netadr_s *)&v8[6], netadr: v14 + 6) )
        return -1;
      return netadr_s::operator<(this: v16, netadr: v8 + 6);
    }
    else
    {
      return 1;
    }
  }
  else
  {
    if ( v14 != nullptr )
      return -1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C6A0
// Name: int BlacklistedAtCompare(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl BlacklistedAtCompare(vgui::ListPanel *pPanel, const vgui::ListPanelItem *p1, const vgui::ListPanelItem *p2)
{
  CBlacklistedServers *m_pBlacklist; // edx
  int m_Size; // ecx
  int v5; // eax
  blacklisted_server_t *m_pMemory; // esi
  blacklisted_server_t *v7; // edx
  blacklisted_server_t *v8; // ebx
  CBlacklistedServers *v9; // ecx
  int v10; // edx
  int v11; // eax
  blacklisted_server_t *v12; // esi
  blacklisted_server_t *v13; // ecx
  blacklisted_server_t *v14; // eax
  unsigned int m_ulTimeBlacklistedAt; // ecx
  unsigned int v17; // eax

  m_pBlacklist = ServerBrowserDialog()->m_pBlacklist;
  m_Size = m_pBlacklist->m_Blacklist.m_Size;
  v5 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v8 = nullptr;
  }
  else
  {
    m_pMemory = m_pBlacklist->m_Blacklist.m_Memory.m_pMemory;
    v7 = m_pMemory;
    while ( v7->m_nServerID != p1->userData )
    {
      ++v5;
      ++v7;
      if ( v5 >= m_Size )
        goto LABEL_5;
    }
    v8 = &m_pMemory[v5];
  }
  v9 = ServerBrowserDialog()->m_pBlacklist;
  v10 = v9->m_Blacklist.m_Size;
  v11 = 0;
  if ( v10 <= 0 )
  {
LABEL_10:
    v14 = nullptr;
  }
  else
  {
    v12 = v9->m_Blacklist.m_Memory.m_pMemory;
    v13 = v12;
    while ( v13->m_nServerID != p2->userData )
    {
      ++v11;
      ++v13;
      if ( v11 >= v10 )
        goto LABEL_10;
    }
    v14 = &v12[v11];
  }
  if ( v8 != nullptr )
  {
    if ( v14 != nullptr )
    {
      m_ulTimeBlacklistedAt = v8->m_ulTimeBlacklistedAt;
      v17 = v14->m_ulTimeBlacklistedAt;
      if ( m_ulTimeBlacklistedAt > v17 )
        return -1;
      return m_ulTimeBlacklistedAt < v17;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    if ( v14 != nullptr )
      return -1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C760
// Name: private: virtual void CBlacklistedServers::OnRemoveFromBlacklist(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBlacklistedServers::OnRemoveFromBlacklist(CBlacklistedServers *this@<ecx>, serverdisplay_t *a2@<edi>)
{
  int v3; // eax
  int v4; // ebx
  vgui::ListPanelItem *v5; // eax
  int m_Size; // ecx
  unsigned int userData; // eax
  int v8; // edi
  blacklisted_server_t *m_pMemory; // edx
  CServerBrowserDialog *v10; // eax
  serverdisplay_t *v11; // [esp-8h] [ebp-10h]
  int iGame; // [esp+4h] [ebp-4h]

  v3 = this->m_pGameList->GetSelectedItemsCount(this: this->m_pGameList) - 1;
  iGame = v3;
  if ( v3 >= 0 )
  {
    v11 = a2;
    while ( 1 )
    {
      v4 = this->m_pGameList->GetSelectedItem(this: this->m_pGameList, a2: v3);
      v5 = this->m_pGameList->GetItemData(this: this->m_pGameList, a2: v4);
      m_Size = this->m_Blacklist.m_Size;
      userData = v5->userData;
      v8 = 0;
      if ( m_Size > 0 )
      {
        m_pMemory = this->m_Blacklist.m_Memory.m_pMemory;
        while ( m_pMemory->m_nServerID != userData )
        {
          ++v8;
          ++m_pMemory;
          if ( v8 >= m_Size )
            goto LABEL_12;
        }
        this->m_pGameList->RemoveItem(this: this->m_pGameList, a2: v4);
        if ( this->m_Blacklist.m_Size - v8 - 1 > 0 )
          _V_memmove(
            dest: &this->m_Blacklist.m_Memory.m_pMemory[v8],
            src: &this->m_Blacklist.m_Memory.m_pMemory[v8 + 1],
            count: 84 * (this->m_Blacklist.m_Size - v8 - 1));
        --this->m_Blacklist.m_Size;
      }
LABEL_12:
      if ( --iGame < 0 )
        break;
      v3 = iGame;
    }
    a2 = v11;
  }
  this->InvalidateLayout(this, a2: false, a3: false);
  this->Repaint(this);
  v10 = ServerBrowserDialog();
  CServerBrowserDialog::BlacklistsChanged(this: v10, a2);
}

//------------------------------------------------------------------------------
// Address: 0x1000C8D0
// Name: private: void CBlacklistedServers::ClearServerList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlacklistedServers::ClearServerList(CBlacklistedServers *this)
{
  bool v2; // sf

  this->m_pGameList->RemoveAll(this: this->m_pGameList);
  v2 = this->m_Blacklist.m_Memory.m_nGrowSize < 0;
  this->m_Blacklist.m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Blacklist.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Blacklist.m_Memory.m_pMemory);
      this->m_Blacklist.m_Memory.m_pMemory = nullptr;
    }
    this->m_Blacklist.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Blacklist.m_pElements = this->m_Blacklist.m_Memory.m_pMemory;
  this->m_iNextServerID = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000C940
// Name: public: static void CBlacklistedServers::PanelMessageFunc_OnPageShow::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBlacklistedServers::PanelMessageFunc_OnPageShow::InitVar(int a1@<ebp>)
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
  if ( !`CBlacklistedServers::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded )
  {
    `CBlacklistedServers::PanelMessageFunc_OnPageShow::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CBlacklistedServers");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "PageShow";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C9D0
// Name: public: static void CBlacklistedServers::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBlacklistedServers::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CBlacklistedServers::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CBlacklistedServers::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Frame::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CBlacklistedServers");
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
// Address: 0x1000CA70
// Name: public: static void CBlacklistedServers::PanelMessageFunc_OnAddServerByName::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBlacklistedServers::PanelMessageFunc_OnAddServerByName::InitVar(int a1@<ebp>)
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
  if ( !`CBlacklistedServers::PanelMessageFunc_OnAddServerByName::InitVar'::`2'::bAdded )
  {
    `CBlacklistedServers::PanelMessageFunc_OnAddServerByName::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::TextEntry::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CBlacklistedServers");
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
// Address: 0x1000CB00
// Name: public: static void CBlacklistedServers::PanelMessageFunc_OnRemoveFromBlacklist::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBlacklistedServers::PanelMessageFunc_OnRemoveFromBlacklist::InitVar(int a1@<ebp>)
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
  if ( !`CBlacklistedServers::PanelMessageFunc_OnRemoveFromBlacklist::InitVar'::`2'::bAdded )
  {
    `CBlacklistedServers::PanelMessageFunc_OnRemoveFromBlacklist::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::TextEntry::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CBlacklistedServers");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "RemoveFromBlacklist";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CB90
// Name: public: static void CBlacklistedServers::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBlacklistedServers::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBlacklistedServers::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CBlacklistedServers::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Label::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CBlacklistedServers");
    v2 = (__int128)_mm_load_si128(&v5);
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTCHARPTR;
    memset(&v4.secondParamType, 0, 20);
    m_Size = v1->entries.m_Size;
    v4.name = "FileSelected";
    v4.func = v2;
    v4.firstParamName = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CC30
// Name: public: CBlacklistedServers::CBlacklistedServers(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CBlacklistedServers *__thiscall CBlacklistedServers::CBlacklistedServers(
        CBlacklistedServers *this,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::ListPanel *v10; // eax
  vgui::ListPanel *v11; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::PropertyPage::PropertyPage(this, parent, panelName: "BlacklistedGames");
  this->__vftable = (CBlacklistedServers_vtbl *)&CBlacklistedServers::`vftable';
  if ( `CBlacklistedServers::ChainToMap'::`2'::chained == 0 )
  {
    `CBlacklistedServers::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CBlacklistedServers");
    v3->pfnClassName = CBlacklistedServers::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyPage");
  }
  if ( `CBlacklistedServers::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBlacklistedServers::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CBlacklistedServers");
    v4->pfnClassName = CBlacklistedServers::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyPage");
  }
  if ( `CBlacklistedServers::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBlacklistedServers::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CBlacklistedServers");
    v5->pfnClassName = CBlacklistedServers::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyPage");
  }
  CBlacklistedServers::PanelMessageFunc_OnPageShow::InitVar(a1: (int)&savedregs);
  CBlacklistedServers::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  CBlacklistedServers::PanelMessageFunc_OnAddServerByName::InitVar(a1: (int)&savedregs);
  CBlacklistedServers::PanelMessageFunc_OnRemoveFromBlacklist::InitVar(a1: (int)&savedregs);
  CBlacklistedServers::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  this->m_hImportDialog.m_iPanelID = -1;
  this->m_Blacklist.m_Memory.m_pMemory = nullptr;
  this->m_Blacklist.m_Memory.m_nAllocationCount = 0;
  this->m_Blacklist.m_Memory.m_nGrowSize = 0;
  this->m_Blacklist.m_Size = 0;
  this->m_Blacklist.m_pElements = nullptr;
  vgui::Panel::SetSize(this, wide: 624, tall: 278);
  v6 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v6 != nullptr )
    v7 = vgui::Button::Button(
           this: v6,
           parent: this,
           panelName: "AddServerButton",
           text: "#ServerBrowser_AddServer",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v7 = nullptr;
  this->m_pAddServer = v7;
  v8 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "AddCurrentServerButton",
           text: "#ServerBrowser_AddCurrentServer",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v9 = nullptr;
  this->m_pAddCurrentServer = v9;
  v10 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v10 != nullptr )
    v11 = vgui::ListPanel::ListPanel(this: v10, parent: this, panelName: "gamelist");
  else
    v11 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v11);
  this->m_pGameList = v11;
  v11->SetAllowUserModificationOfColumns(this: v11, a2: true);
  this->m_pGameList->AddColumnHeader(
    this: this->m_pGameList,
    a2: 0,
    a3: "Name",
    a4: "#ServerBrowser_BlacklistedServers",
    a5: 50,
    a6: 18);
  this->m_pGameList->AddColumnHeader(
    this: this->m_pGameList,
    a2: 1,
    a3: "IPAddr",
    a4: "#ServerBrowser_IPAddress",
    a5: 64,
    a6: 8);
  this->m_pGameList->AddColumnHeader(
    this: this->m_pGameList,
    a2: 2,
    a3: "BlacklistedAt",
    a4: "#ServerBrowser_BlacklistedDate",
    a5: 100,
    a6: 0);
  this->m_pGameList->SetSortFunc(this: this->m_pGameList, a2: 0, a3: BlacklistedServerNameCompare);
  this->m_pGameList->SetSortFunc(this: this->m_pGameList, a2: 1, a3: BlacklistedIPAddressCompare);
  this->m_pGameList->SetSortFunc(this: this->m_pGameList, a2: 2, a3: BlacklistedAtCompare);
  this->m_pGameList->SetSortColumn(this: this->m_pGameList, a2: 0);
  this->m_iNextServerID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000CEA0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBlacklistedServers::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBlacklistedServers::GetMessageMap(CBlacklistedServers *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBlacklistedServers::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBlacklistedServers::GetMessageMap'::`2'::s_pMap;
  `CBlacklistedServers::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBlacklistedServers");
  `CBlacklistedServers::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000CED0
// Name: public: virtual struct PanelAnimationMap __near * CBlacklistedServers::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBlacklistedServers::GetAnimMap(CBlacklistedServers *this)
{
  return FindOrAddPanelAnimationMap(className: "CBlacklistedServers");
}

//------------------------------------------------------------------------------
// Address: 0x1000CEE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBlacklistedServers::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBlacklistedServers::GetKBMap(CBlacklistedServers *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBlacklistedServers::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBlacklistedServers::GetKBMap'::`2'::s_pMap;
  `CBlacklistedServers::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBlacklistedServers");
  `CBlacklistedServers::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000CF10
// Name: private: bool CBlacklistedServers::AddServersFromFile(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBlacklistedServers::AddServersFromFile(
        CBlacklistedServers *this,
        KeyValues *pszFilename,
        bool bResetTimes)
{
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  IBaseFileSystem *v6; // eax
  bool result; // al
  KeyValues *FirstSubKey; // esi
  const char *String; // edi
  const char *v10; // eax
  int v11; // eax
  int v12; // edi
  blacklisted_server_t *m_pMemory; // edx
  int iIdx; // [esp+8h] [ebp-18h]
  const char *pszNetAddr; // [esp+Ch] [ebp-14h]
  unsigned __int8 *pszName; // [esp+10h] [ebp-10h]
  int today; // [esp+14h] [ebp-Ch] BYREF
  unsigned int ulDate; // [esp+18h] [ebp-8h]
  KeyValues *pKV; // [esp+1Ch] [ebp-4h]
  KeyValues *pData; // [esp+28h] [ebp+8h]

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "serverblacklist");
    pKV = v5;
  }
  else
  {
    pKV = nullptr;
    v5 = nullptr;
  }
  if ( g_pFullFileSystem != nullptr )
    v6 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v6 = nullptr;
  result = KeyValues::LoadFromFile(
             this: v5,
             filesystem: v6,
             resourceName: (const char *)pszFilename,
             pathID: "GAME",
             pfnEvaluateSymbolProc: nullptr);
  if ( result )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: v5);
    pData = FirstSubKey;
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        String = KeyValues::GetString(this: FirstSubKey, keyName: "name", defaultValue: defaultValue);
        pszName = (unsigned __int8 *)String;
        ulDate = KeyValues::GetInt(this: FirstSubKey, keyName: "date", defaultValue: 0);
        if ( bResetTimes )
        {
          _time32(timeptr: &today);
          ulDate = today;
        }
        v10 = KeyValues::GetString(this: FirstSubKey, keyName: "addr", defaultValue: defaultValue);
        pszNetAddr = v10;
        if ( v10 != nullptr && *v10 != 0 && String != nullptr && *String != 0 )
        {
          v11 = CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>::InsertBefore(
                  this: &this->m_Blacklist,
                  elem: this->m_Blacklist.m_Size);
          v12 = v11;
          iIdx = v11;
          this->m_Blacklist.m_Memory.m_pMemory[v11].m_nServerID = this->m_iNextServerID;
          m_pMemory = this->m_Blacklist.m_Memory.m_pMemory;
          ++this->m_iNextServerID;
          strncpy(dest: (unsigned __int8 *)m_pMemory[v11].m_szServerName, source: pszName, count: 0x40u);
          this->m_Blacklist.m_Memory.m_pMemory[v12].m_ulTimeBlacklistedAt = ulDate;
          netadr_s::SetFromString(
            this: &this->m_Blacklist.m_Memory.m_pMemory[v12].m_NetAdr,
            pch: pszNetAddr,
            bUseDNS: false);
          CBlacklistedServers::AddBlacklistedServer(this, a2: (int)this, iIdx);
          FirstSubKey = pData;
        }
        pData = KeyValues::GetNextKey(this: FirstSubKey);
        if ( pData == nullptr )
          break;
        FirstSubKey = pData;
      }
      v5 = pKV;
    }
    KeyValues::deleteThis(this: v5);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D0B0
// Name: public: void CBlacklistedServers::AddServer(class gameserveritem_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlacklistedServers::AddServer(CBlacklistedServers *this, gameserveritem_t *server)
{
  unsigned __int16 m_usConnectionPort; // di
  unsigned __int8 *m_szServerName; // eax
  int v6; // esi
  netadr_s netAdr; // [esp+Ch] [ebp-10h] BYREF
  int today; // [esp+18h] [ebp-4h] BYREF
  int iIdx; // [esp+24h] [ebp+8h]

  m_usConnectionPort = server->m_NetAdr.m_usConnectionPort;
  netadr_s::SetIP(this: &netAdr, unIP: server->m_NetAdr.m_unIP);
  netadr_s::SetPort(this: &netAdr, newport: m_usConnectionPort);
  netadr_s::SetType(this: &netAdr, newtype: NA_IP);
  if ( !netadr_s::IsReservedAdr(this: &netAdr) )
  {
    iIdx = CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>::InsertBefore(
             this: &this->m_Blacklist,
             elem: this->m_Blacklist.m_Size);
    m_szServerName = (unsigned __int8 *)server->m_szServerName;
    if ( server->m_szServerName[0] == 0 )
      m_szServerName = (unsigned __int8 *)servernetadr_t::GetConnectionAddressString(this: &server->m_NetAdr);
    v6 = iIdx;
    strncpy(
      dest: (unsigned __int8 *)this->m_Blacklist.m_Memory.m_pMemory[iIdx].m_szServerName,
      source: m_szServerName,
      count: 0x40u);
    _time32(timeptr: &today);
    this->m_Blacklist.m_Memory.m_pMemory[v6].m_ulTimeBlacklistedAt = today;
    this->m_Blacklist.m_Memory.m_pMemory[iIdx].m_NetAdr = netAdr;
    this->m_Blacklist.m_Memory.m_pMemory[v6].m_nServerID = this->m_iNextServerID++;
    CBlacklistedServers::AddBlacklistedServer(this, a2: (int)this, iIdx);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D190
// Name: private: virtual void CBlacklistedServers::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlacklistedServers::OnFileSelected(CBlacklistedServers *this, KeyValues *fullpath)
{
  vgui::Panel *v3; // eax

  CBlacklistedServers::AddServersFromFile(this, pszFilename: fullpath, bResetTimes: true);
  if ( vgui::PHandle::Get(this: &this->m_hImportDialog) != nullptr )
  {
    v3 = vgui::PHandle::Get(this: &this->m_hImportDialog);
    v3->MarkForDeletion(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D1D0
// Name: private: virtual void CBlacklistedServers::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlacklistedServers::OnCommand(CBlacklistedServers *this, char *command)
{
  CServerBrowserDialog *v3; // eax
  gameserveritem_t *v4; // eax
  CServerBrowserDialog *v5; // eax

  if ( _V_stricmp(s1: command, s2: "AddServerByName") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "AddCurrentServer") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "ImportBlacklist") != 0 )
        vgui::Panel::OnCommand(this, command);
      else
        CBlacklistedServers::OnImportBlacklist(this);
    }
    else
    {
      v3 = ServerBrowserDialog();
      v4 = v3->GetCurrentConnectedServer(this: v3);
      if ( v4 != nullptr )
      {
        CBlacklistedServers::AddServer(this, server: v4);
        v5 = ServerBrowserDialog();
        CServerBrowserDialog::BlacklistsChanged(this: v5, a2: (serverdisplay_t *)command);
      }
    }
  }
  else
  {
    this->OnAddServerByName(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D2B0
// Name: public: void CBlacklistedServers::LoadBlacklistedList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBlacklistedServers::LoadBlacklistedList(CBlacklistedServers *this)
{
  this->m_pGameList->SetEmptyListText_2(this: this->m_pGameList, a2: "#ServerBrowser_NoBlacklistedServers");
  CBlacklistedServers::ClearServerList(this);
  CBlacklistedServers::AddServersFromFile(
    this,
    pszFilename: (KeyValues *)"cfg/server_blacklist.txt",
    bResetTimes: false);
}

//------------------------------------------------------------------------------
// Address: 0x10043350
// Name: public: virtual class vgui::Panel __near * vgui::TextEntry::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::TextEntry::GetDragPanel(vgui::TextEntry *this)
{
  int v2; // edi
  int cx1; // [esp+4h] [ebp-10h] BYREF
  int cx0; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
    return vgui::Panel::GetDragPanel(this);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  v2 = this->PixelToCursorSpace(this, a2: x, a3: y);
  if ( this->GetSelectedRange(this, a2: &cx0, a3: &cx1) && v2 >= cx0 && v2 < cx1 )
    return vgui::Panel::GetDragPanel(this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10046BD0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TextEntry::GetMessageMap(vgui::TextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetMessageMap'::`2'::s_pMap;
  `vgui::TextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  `vgui::TextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10046C00
// Name: public: virtual struct PanelAnimationMap __near * vgui::TextEntry::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TextEntry::GetAnimMap(vgui::TextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "TextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x10046C10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TextEntry::GetKBMap(vgui::TextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetKBMap'::`2'::s_pMap;
  `vgui::TextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  `vgui::TextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}
