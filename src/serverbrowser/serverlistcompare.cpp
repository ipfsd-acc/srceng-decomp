// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: serverbrowser/serverlistcompare.cpp
// Functions: 11
// ============================================================

#include "serverbrowser\serverlistcompare.h"

//------------------------------------------------------------------------------
// Address: 0x10016F10
// Name: int PasswordCompare(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PasswordCompare(vgui::ListPanel *pPanel, const vgui::ListPanelItem *p1, const vgui::ListPanelItem *p2)
{
  CServerBrowserDialog *v3; // eax
  gameserveritem_t *Server; // esi
  CServerBrowserDialog *v5; // eax
  gameserveritem_t *v6; // eax
  bool m_bPassword; // cl
  bool v9; // al
  unsigned int userData; // [esp-4h] [ebp-8h]
  unsigned int v11; // [esp-4h] [ebp-8h]

  userData = p1->userData;
  v3 = ServerBrowserDialog();
  Server = CServerBrowserDialog::GetServer(this: v3, serverID: userData);
  v11 = p2->userData;
  v5 = ServerBrowserDialog();
  v6 = CServerBrowserDialog::GetServer(this: v5, serverID: v11);
  if ( Server != nullptr )
  {
    if ( v6 != nullptr
      && (m_bPassword = Server->m_bPassword, (unsigned __int8)(v9 = v6->m_bPassword) <= (unsigned __int8)m_bPassword) )
    {
      return -((unsigned __int8)v9 < (unsigned __int8)m_bPassword);
    }
    else
    {
      return 1;
    }
  }
  else if ( v6 != nullptr )
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016F70
// Name: int BotsCompare(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl BotsCompare(vgui::ListPanel *pPanel, const vgui::ListPanelItem *p1, const vgui::ListPanelItem *p2)
{
  CServerBrowserDialog *v3; // eax
  gameserveritem_t *Server; // esi
  CServerBrowserDialog *v5; // eax
  gameserveritem_t *v6; // eax
  int m_nBotPlayers; // ecx
  int v9; // eax
  unsigned int userData; // [esp-4h] [ebp-8h]
  unsigned int v11; // [esp-4h] [ebp-8h]

  userData = p1->userData;
  v3 = ServerBrowserDialog();
  Server = CServerBrowserDialog::GetServer(this: v3, serverID: userData);
  v11 = p2->userData;
  v5 = ServerBrowserDialog();
  v6 = CServerBrowserDialog::GetServer(this: v5, serverID: v11);
  if ( Server != nullptr )
  {
    if ( v6 != nullptr && (m_nBotPlayers = Server->m_nBotPlayers, v9 = v6->m_nBotPlayers, m_nBotPlayers >= v9) )
      return (m_nBotPlayers <= v9) - 1;
    else
      return 1;
  }
  else if ( v6 != nullptr )
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016FE0
// Name: int SecureCompare(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SecureCompare(vgui::ListPanel *pPanel, const vgui::ListPanelItem *p1, const vgui::ListPanelItem *p2)
{
  CServerBrowserDialog *v3; // eax
  gameserveritem_t *Server; // esi
  CServerBrowserDialog *v5; // eax
  gameserveritem_t *v6; // eax
  bool m_bSecure; // cl
  bool v9; // al
  unsigned int userData; // [esp-4h] [ebp-8h]
  unsigned int v11; // [esp-4h] [ebp-8h]

  userData = p1->userData;
  v3 = ServerBrowserDialog();
  Server = CServerBrowserDialog::GetServer(this: v3, serverID: userData);
  v11 = p2->userData;
  v5 = ServerBrowserDialog();
  v6 = CServerBrowserDialog::GetServer(this: v5, serverID: v11);
  if ( Server != nullptr )
  {
    if ( v6 != nullptr
      && (m_bSecure = Server->m_bSecure, (unsigned __int8)(v9 = v6->m_bSecure) <= (unsigned __int8)m_bSecure) )
    {
      return -((unsigned __int8)v9 < (unsigned __int8)m_bSecure);
    }
    else
    {
      return 1;
    }
  }
  else if ( v6 != nullptr )
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017040
// Name: int IPAddressCompare(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl IPAddressCompare(vgui::ListPanel *pPanel, const vgui::ListPanelItem *p1, const vgui::ListPanelItem *p2)
{
  CServerBrowserDialog *v3; // eax
  gameserveritem_t *Server; // esi
  CServerBrowserDialog *v5; // eax
  gameserveritem_t *v6; // eax
  unsigned int m_unIP; // ecx
  unsigned int v9; // edx
  unsigned int userData; // [esp-4h] [ebp-8h]
  unsigned int v11; // [esp-4h] [ebp-8h]

  userData = p1->userData;
  v3 = ServerBrowserDialog();
  Server = CServerBrowserDialog::GetServer(this: v3, serverID: userData);
  v11 = p2->userData;
  v5 = ServerBrowserDialog();
  v6 = CServerBrowserDialog::GetServer(this: v5, serverID: v11);
  if ( Server != nullptr )
  {
    if ( v6 == nullptr )
      return 1;
    m_unIP = Server->m_NetAdr.m_unIP;
    v9 = v6->m_NetAdr.m_unIP;
    if ( m_unIP < v9 || m_unIP == v9 && Server->m_NetAdr.m_usQueryPort < v6->m_NetAdr.m_usQueryPort )
      return -1;
    if ( v9 < m_unIP || v9 == m_unIP && v6->m_NetAdr.m_usQueryPort < Server->m_NetAdr.m_usQueryPort )
      return 1;
  }
  else if ( v6 != nullptr )
  {
    return -1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100170C0
// Name: int PingCompare(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PingCompare(vgui::ListPanel *pPanel, const vgui::ListPanelItem *p1, const vgui::ListPanelItem *p2)
{
  CServerBrowserDialog *v3; // eax
  gameserveritem_t *Server; // esi
  CServerBrowserDialog *v5; // eax
  gameserveritem_t *v6; // eax
  int m_nPing; // ecx
  int v9; // eax
  unsigned int userData; // [esp-4h] [ebp-8h]
  unsigned int v11; // [esp-4h] [ebp-8h]

  userData = p1->userData;
  v3 = ServerBrowserDialog();
  Server = CServerBrowserDialog::GetServer(this: v3, serverID: userData);
  v11 = p2->userData;
  v5 = ServerBrowserDialog();
  v6 = CServerBrowserDialog::GetServer(this: v5, serverID: v11);
  if ( Server != nullptr )
  {
    if ( v6 != nullptr )
    {
      m_nPing = Server->m_nPing;
      v9 = v6->m_nPing;
      if ( m_nPing < v9 )
        return -1;
      return m_nPing > v9;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    if ( v6 != nullptr )
      return -1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017130
// Name: int MapCompare(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl MapCompare(vgui::ListPanel *pPanel, const vgui::ListPanelItem *p1, const vgui::ListPanelItem *p2)
{
  CServerBrowserDialog *v3; // eax
  gameserveritem_t *Server; // esi
  CServerBrowserDialog *v5; // eax
  gameserveritem_t *v6; // eax
  unsigned int userData; // [esp-4h] [ebp-8h]
  unsigned int v9; // [esp-4h] [ebp-8h]

  userData = p1->userData;
  v3 = ServerBrowserDialog();
  Server = CServerBrowserDialog::GetServer(this: v3, serverID: userData);
  v9 = p2->userData;
  v5 = ServerBrowserDialog();
  v6 = CServerBrowserDialog::GetServer(this: v5, serverID: v9);
  if ( Server != nullptr )
  {
    if ( v6 != nullptr )
      return _V_stricmp(s1: Server->m_szMap, s2: v6->m_szMap);
    else
      return 1;
  }
  else if ( v6 != nullptr )
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017190
// Name: int GameCompare(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GameCompare(vgui::ListPanel *pPanel, const vgui::ListPanelItem *p1, const vgui::ListPanelItem *p2)
{
  CServerBrowserDialog *v3; // eax
  gameserveritem_t *Server; // esi
  CServerBrowserDialog *v5; // eax
  gameserveritem_t *v6; // eax
  unsigned int userData; // [esp-4h] [ebp-8h]
  unsigned int v9; // [esp-4h] [ebp-8h]

  userData = p1->userData;
  v3 = ServerBrowserDialog();
  Server = CServerBrowserDialog::GetServer(this: v3, serverID: userData);
  v9 = p2->userData;
  v5 = ServerBrowserDialog();
  v6 = CServerBrowserDialog::GetServer(this: v5, serverID: v9);
  if ( Server != nullptr )
  {
    if ( v6 != nullptr )
      return _V_stricmp(s1: Server->m_szGameDescription, s2: v6->m_szGameDescription);
    else
      return 1;
  }
  else if ( v6 != nullptr )
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100171F0
// Name: int ServerNameCompare(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ServerNameCompare(vgui::ListPanel *pPanel, const vgui::ListPanelItem *p1, const vgui::ListPanelItem *p2)
{
  CServerBrowserDialog *v3; // eax
  gameserveritem_t *Server; // esi
  CServerBrowserDialog *v5; // eax
  gameserveritem_t *v6; // eax
  char *m_szServerName; // edi
  char *ConnectionAddressString; // eax
  unsigned int userData; // [esp-4h] [ebp-8h]
  unsigned int v11; // [esp-4h] [ebp-8h]

  userData = p1->userData;
  v3 = ServerBrowserDialog();
  Server = CServerBrowserDialog::GetServer(this: v3, serverID: userData);
  v11 = p2->userData;
  v5 = ServerBrowserDialog();
  v6 = CServerBrowserDialog::GetServer(this: v5, serverID: v11);
  if ( Server != nullptr )
  {
    if ( v6 != nullptr )
    {
      if ( v6->m_szServerName[0] != 0 )
        m_szServerName = v6->m_szServerName;
      else
        m_szServerName = servernetadr_t::GetConnectionAddressString(this: &v6->m_NetAdr);
      ConnectionAddressString = Server->m_szServerName;
      if ( Server->m_szServerName[0] == 0 )
        ConnectionAddressString = servernetadr_t::GetConnectionAddressString(this: &Server->m_NetAdr);
      return _V_stricmp(s1: ConnectionAddressString, s2: m_szServerName);
    }
    else
    {
      return 1;
    }
  }
  else if ( v6 != nullptr )
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017280
// Name: int PlayersCompare(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PlayersCompare(vgui::ListPanel *pPanel, const vgui::ListPanelItem *p1, const vgui::ListPanelItem *p2)
{
  CServerBrowserDialog *v3; // eax
  gameserveritem_t *Server; // esi
  CServerBrowserDialog *v5; // eax
  gameserveritem_t *v6; // eax
  int m_nBotPlayers; // ecx
  int m_nPlayers; // edi
  int m_nMaxPlayers; // esi
  int v11; // edi
  bool v12; // sf
  int v13; // esi
  int v14; // ecx
  int v15; // ebx
  int v16; // edx
  int v17; // eax
  unsigned int userData; // [esp-4h] [ebp-8h]
  unsigned int v19; // [esp-4h] [ebp-8h]

  userData = p1->userData;
  v3 = ServerBrowserDialog();
  Server = CServerBrowserDialog::GetServer(this: v3, serverID: userData);
  v19 = p2->userData;
  v5 = ServerBrowserDialog();
  v6 = CServerBrowserDialog::GetServer(this: v5, serverID: v19);
  if ( Server != nullptr )
  {
    if ( v6 == nullptr )
      return 1;
    m_nBotPlayers = Server->m_nBotPlayers;
    m_nPlayers = Server->m_nPlayers;
    m_nMaxPlayers = Server->m_nMaxPlayers;
    v11 = m_nPlayers - m_nBotPlayers < 0 ? 0 : m_nPlayers - m_nBotPlayers;
    v12 = m_nMaxPlayers - m_nBotPlayers < 0;
    v13 = m_nMaxPlayers - m_nBotPlayers;
    v14 = v6->m_nBotPlayers;
    v15 = v12 ? 0 : v13;
    v16 = (v6->m_nPlayers - v14) & ((v6->m_nPlayers - v14 < 0) - 1);
    v17 = v6->m_nMaxPlayers - v14 < 0 ? 0 : v6->m_nMaxPlayers - v14;
    if ( v11 > v16 )
      return -1;
    if ( v11 < v16 )
      return 1;
    if ( v15 <= v17 )
      return v15 < v17;
    else
      return -1;
  }
  else if ( v6 != nullptr )
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017350
// Name: int LastPlayedCompare(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LastPlayedCompare(vgui::ListPanel *pPanel, const vgui::ListPanelItem *p1, const vgui::ListPanelItem *p2)
{
  CServerBrowserDialog *v3; // eax
  gameserveritem_t *Server; // esi
  CServerBrowserDialog *v5; // eax
  gameserveritem_t *v6; // eax
  unsigned int m_ulTimeLastPlayed; // ecx
  unsigned int v9; // eax
  unsigned int userData; // [esp-4h] [ebp-8h]
  unsigned int v11; // [esp-4h] [ebp-8h]

  userData = p1->userData;
  v3 = ServerBrowserDialog();
  Server = CServerBrowserDialog::GetServer(this: v3, serverID: userData);
  v11 = p2->userData;
  v5 = ServerBrowserDialog();
  v6 = CServerBrowserDialog::GetServer(this: v5, serverID: v11);
  if ( Server != nullptr )
  {
    if ( v6 != nullptr )
    {
      m_ulTimeLastPlayed = Server->m_ulTimeLastPlayed;
      v9 = v6->m_ulTimeLastPlayed;
      if ( m_ulTimeLastPlayed > v9 )
        return -1;
      return m_ulTimeLastPlayed < v9;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    if ( v6 != nullptr )
      return -1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100173C0
// Name: int TagsCompare(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TagsCompare(vgui::ListPanel *pPanel, const vgui::ListPanelItem *p1, const vgui::ListPanelItem *p2)
{
  CServerBrowserDialog *v3; // eax
  gameserveritem_t *Server; // esi
  CServerBrowserDialog *v5; // eax
  gameserveritem_t *v6; // eax
  unsigned int userData; // [esp-4h] [ebp-8h]
  unsigned int v9; // [esp-4h] [ebp-8h]

  userData = p1->userData;
  v3 = ServerBrowserDialog();
  Server = CServerBrowserDialog::GetServer(this: v3, serverID: userData);
  v9 = p2->userData;
  v5 = ServerBrowserDialog();
  v6 = CServerBrowserDialog::GetServer(this: v5, serverID: v9);
  if ( Server != nullptr )
  {
    if ( v6 != nullptr )
      return _V_stricmp(s1: Server->m_szGameTags, s2: v6->m_szGameTags);
    else
      return 1;
  }
  else if ( v6 != nullptr )
  {
    return -1;
  }
  else
  {
    return 0;
  }
}
