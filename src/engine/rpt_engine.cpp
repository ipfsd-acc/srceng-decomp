// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/rpt_engine.cpp
// Functions: 11
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101066C0
// Name: rpt_password
// Source: json
//------------------------------------------------------------------------------
void __cdecl rpt_password(const CCommand *args)
{
  int v1; // eax
  CRConServer *v2; // eax
  bool HasPassword; // bl
  CRConServer *v4; // eax
  CRConServer *v5; // eax
  const char *v6; // esi
  const char *v7; // [esp-Ch] [ebp-614h]
  CCommand argsClient; // [esp+0h] [ebp-608h] BYREF
  char buf[256]; // [esp+508h] [ebp-100h] BYREF

  v1 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-rpt") == 0 )
  {
    ConMsg(a1: "This command will not work unless the game is launched with -rpt\n");
    return;
  }
  if ( args->m_nArgc > 2 )
  {
    ConMsg(a1: "Incorrect # of arguments.\n");
    return;
  }
  if ( NET_IsDedicated() || !NET_IsMultiplayer() || args->m_nArgc > 2 )
  {
    ConMsg(a1: "Failed!\n");
    return;
  }
  v2 = RPTServer();
  HasPassword = CRConServer::HasPassword(this: v2);
  if ( args->m_nArgc == 1 )
  {
    if ( !HasPassword )
      return;
    v4 = RPTServer();
    CRConServer::SetPassword(this: v4, pPassword: nullptr);
    ConMsg(a1: "Disabling...\n");
    V_snprintf(pDest: buf, maxLen: 255, pFormat: "rpt_client_enable 0");
    goto LABEL_17;
  }
  if ( args->m_nArgc != 2 )
  {
LABEL_17:
    CCommand::CCommand(this: &argsClient);
    CCommand::Tokenize(this: &argsClient, pCommand: buf, pBreakSet: nullptr);
    Cmd_ForwardToServer(args: &argsClient, bReliable: true);
    return;
  }
  v7 = args->m_ppArgv[1];
  v5 = RPTServer();
  CRConServer::SetPassword(this: v5, pPassword: v7);
  if ( args->m_nArgc > 1 )
    v6 = args->m_ppArgv[1];
  else
    v6 = defaultValue;
  ConMsg(a1: "New password : %s\n", v6);
  if ( !HasPassword )
  {
    ConMsg(a1: "Enabling...\n");
    V_snprintf(pDest: buf, maxLen: 255, pFormat: "rpt_client_enable 1");
    goto LABEL_17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106830
// Name: void SV_NotifyRPTOfDisconnect(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_NotifyRPTOfDisconnect(int nClientSlot)
{
  CRConServer *v1; // eax
  CRPTClient *v2; // eax
  CRPTClient *v3; // eax

  if ( nClientSlot == g_nRptClientSlot )
    g_nRptClientSlot = -1;
  if ( nClientSlot == g_nRptServerSlot )
    g_nRptServerSlot = -1;
  v1 = RPTServer();
  CRConServer::SetPassword(this: v1, pPassword: nullptr);
  v2 = RPTClient();
  CRConClient::SetPassword(this: v2, pPassword: nullptr);
  v3 = RPTClient();
  CRConClient::CloseListenSocket(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10106880
// Name: void CL_NotifyRPTOfDisconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_NotifyRPTOfDisconnect()
{
  CRConServer *v0; // eax
  CRPTClient *v1; // eax
  CRPTClient *v2; // eax

  v0 = RPTServer();
  CRConServer::SetPassword(this: v0, pPassword: nullptr);
  v1 = RPTClient();
  CRConClient::SetPassword(this: v1, pPassword: nullptr);
  v2 = RPTClient();
  CRConClient::CloseListenSocket(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101068B0
// Name: rpt_start
// Source: json
//------------------------------------------------------------------------------
void __cdecl rpt_start(const CCommand *args)
{
  const CCommand *v1; // esi
  int m_nArgc; // eax
  const char *v3; // eax
  CRPTClient *v4; // eax
  CRPTClient *v5; // eax
  CRPTClient *v6; // eax
  char *v7; // eax
  unsigned __int16 v8; // [esp-4h] [ebp-728h]
  const char *v9; // [esp-4h] [ebp-728h]
  CCommand argsClient; // [esp+4h] [ebp-720h] BYREF
  char pDir[260]; // [esp+50Ch] [ebp-218h] BYREF
  char pBuf[256]; // [esp+610h] [ebp-114h] BYREF
  int nDay; // [esp+710h] [ebp-14h] BYREF
  int nMonth; // [esp+714h] [ebp-10h] BYREF
  netadr_s rptAddr; // [esp+718h] [ebp-Ch] BYREF

  v1 = args;
  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc < 2 || m_nArgc > 3 )
  {
    ConMsg(a1: "Incorrect # of arguments.\n");
  }
  else
  {
    rptAddr = net_local_adr;
    if ( m_nArgc == 3 )
    {
      v8 = atoi(nptr: args->m_ppArgv[2]);
      netadr_s::SetPort(this: &rptAddr, newport: v8);
    }
    else
    {
      netadr_s::SetPort(this: &rptAddr, newport: 0x699Cu);
    }
    v3 = defaultValue;
    if ( v1->m_nArgc > 1 )
      v3 = v1->m_ppArgv[1];
    v9 = v3;
    v4 = RPTClient();
    CRConClient::SetPassword(this: v4, pPassword: v9);
    v5 = RPTClient();
    CRConClient::CreateListenSocket(this: v5, netAdr: &rptAddr);
    _GetCurrentDate(a1: &nDay, a2: &nMonth, a3: &args);
    V_snprintf(pDest: pDir, maxLen: 260, pFormat: "rpt/%d_%d_%d", nMonth, nDay, args);
    v6 = RPTClient();
    CRConClient::SetRemoteFileDirectory(this: v6, pDir);
    v7 = netadr_s::ToString(this: &rptAddr, baseOnly: false);
    V_snprintf(pDest: pBuf, maxLen: 256, pFormat: "rpt_server_enable 1 %s\n", v7);
    CCommand::CCommand(this: &argsClient);
    CCommand::Tokenize(this: &argsClient, pCommand: pBuf, pBreakSet: nullptr);
    Cmd_ForwardToServer(args: &argsClient, bReliable: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101069F0
// Name: rpt_end
// Source: json
//------------------------------------------------------------------------------
void __cdecl rpt_end(const CCommand *args)
{
  CRPTClient *v1; // eax
  CRPTClient *v2; // eax
  CCommand argsClient; // [esp+0h] [ebp-608h] BYREF
  char pBuf[256]; // [esp+508h] [ebp-100h] BYREF

  if ( args->m_nArgc == 1 )
  {
    v1 = RPTClient();
    CRConClient::SetPassword(this: v1, pPassword: nullptr);
    v2 = RPTClient();
    CRConClient::CloseListenSocket(this: v2);
    V_snprintf(pDest: pBuf, maxLen: 256, pFormat: "rpt_server_enable 0\n");
    CCommand::CCommand(this: &argsClient);
    CCommand::Tokenize(this: &argsClient, pCommand: pBuf, pBreakSet: nullptr);
    Cmd_ForwardToServer(args: &argsClient, bReliable: true);
  }
  else
  {
    ConMsg(a1: "Incorrect # of arguments.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106A80
// Name: IsValveIPAddress
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall IsValveIPAddress@<eax>(netadr_s *adr@<esi>)
{
  netadr_s valveIP2; // [esp+0h] [ebp-18h] BYREF
  netadr_s valveIP1; // [esp+Ch] [ebp-Ch] BYREF

  netadr_s::SetIP(this: &valveIP1, unIP: 0);
  netadr_s::SetPort(this: &valveIP1, newport: 0);
  netadr_s::SetType(this: &valveIP1, newtype: NA_IP);
  netadr_s::SetIP(this: &valveIP2, unIP: 0);
  netadr_s::SetPort(this: &valveIP2, newport: 0);
  netadr_s::SetType(this: &valveIP2, newtype: NA_IP);
  netadr_s::SetIP(this: &valveIP1, b1: 0xCFu, b2: 0xADu, b3: 0xB2u, b4: 0xFFu);
  netadr_s::SetIP(this: &valveIP2, b1: 0xCFu, b2: 0xADu, b3: 0xB3u, b4: 0xFFu);
  return netadr_s::CompareClassCAdr(this: adr, a: &valveIP1)
      || netadr_s::CompareClassCAdr(this: adr, a: &valveIP2)
      || netadr_s::IsLoopback(this: adr);
}

//------------------------------------------------------------------------------
// Address: 0x10106B40
// Name: rpt_connect
// Source: json
//------------------------------------------------------------------------------
void __cdecl rpt_connect(const CCommand *args)
{
  int v1; // eax
  const char *v2; // esi
  unsigned __int16 v3; // ax
  CRConServer *v4; // eax
  netadr_s adr; // [esp+0h] [ebp-Ch] BYREF

  v1 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-rpt") != 0 && args->m_nArgc == 4 )
  {
    netadr_s::SetFromString(this: &adr, pch: (char *)args->m_ppArgv[1], bUseDNS: 0);
    if ( args->m_nArgc > 3 )
      v2 = args->m_ppArgv[3];
    else
      v2 = defaultValue;
    v3 = atoi(nptr: v2);
    netadr_s::SetPort(this: &adr, newport: v3);
    if ( IsValveIPAddress(&adr) )
    {
      v4 = RPTServer();
      CRConServer::ConnectToListeningClient(this: v4, &adr, bSingleSocket: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106BC0
// Name: rpt
// Source: json
//------------------------------------------------------------------------------
void __cdecl rpt(const CCommand *args)
{
  int m_nArgc; // eax
  int v3; // edi
  unsigned __int8 *v4; // esi
  int v5; // eax
  CRPTClient *v6; // eax
  char message[1024]; // [esp+8h] [ebp-500h] BYREF
  char szParam[256]; // [esp+408h] [ebp-100h] BYREF
  const CCommand *argsa; // [esp+510h] [ebp+8h]

  m_nArgc = args->m_nArgc;
  v3 = 1;
  message[0] = 0;
  if ( m_nArgc > 1 )
  {
    argsa = (const CCommand *)&args->m_ppArgv[1];
    do
    {
      if ( v3 < 0 || v3 >= m_nArgc )
        v4 = (unsigned __int8 *)defaultValue;
      else
        v4 = (unsigned __int8 *)argsa->m_nArgc;
      strchr(string: v4, chr: 0x20u);
      if ( v5 != 0 || _V_strlen(str: (const char *)v4) == 0 )
      {
        V_snprintf(pDest: szParam, maxLen: 256, pFormat: "\"%s\"", (const char *)v4);
        V_strncat(pDest: message, pSrc: szParam, destBufferSize: 0x400u, max_chars_to_copy: -1);
      }
      else
      {
        V_strncat(pDest: message, pSrc: (const char *)v4, destBufferSize: 0x400u, max_chars_to_copy: -1);
      }
      if ( v3 != args->m_nArgc - 1 )
        V_strncat(pDest: message, pSrc: " ", destBufferSize: 0x400u, max_chars_to_copy: -1);
      m_nArgc = args->m_nArgc;
      argsa = (const CCommand *)((char *)argsa + 4);
      ++v3;
    }
    while ( v3 < args->m_nArgc );
  }
  v6 = RPTClient();
  CRConClient::SendCmd(this: v6, msg: message);
}

//------------------------------------------------------------------------------
// Address: 0x10106CC0
// Name: rpt_client_enable
// Source: json
//------------------------------------------------------------------------------
void __cdecl rpt_client_enable(const CCommand *args)
{
  if ( args->m_nArgc == 2 && cmd_clientslot >= 0 && sv.m_Clients.m_Memory.m_pMemory[cmd_clientslot] != nullptr )
  {
    if ( atoi(nptr: args->m_ppArgv[1]) != 0 )
      g_nRptClientSlot = cmd_clientslot;
    else
      g_nRptClientSlot = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106D10
// Name: PlayerIsValveEmployee
// Source: json
//------------------------------------------------------------------------------
char __cdecl PlayerIsValveEmployee(int nClientSlot)
{
  CBaseClient *v1; // edi
  netadr_s *v3; // eax
  int v4; // edx
  player_info_s pi; // [esp+8h] [ebp-90h] BYREF

  v1 = sv.m_Clients.m_Memory.m_pMemory[nClientSlot];
  if ( v1 == nullptr )
    return 0;
  v3 = (netadr_s *)v1->m_NetChannel->GetRemoteAddress(this: v1->m_NetChannel);
  if ( !IsValveIPAddress(adr: v3) )
    return 0;
  if ( GetSteamUniverse() != k_EUniverseBeta )
  {
    if ( v1->m_bFullyAuthenticated
      && CBaseServer::GetPlayerInfo(this: &sv, nClientIndex: nClientSlot, pinfo: (unsigned int)&pi) != 0
      && pi.friendsID != 0 )
    {
      v4 = 0;
      while ( pi.friendsID != ((unsigned int)s_ValveMask ^ LODWORD(s_pValveIDs[v4]))
           || (dword_10416E4C ^ HIDWORD(s_pValveIDs[v4])) != 0x1100001 )
      {
        if ( (unsigned int)++v4 >= 1 )
          return 0;
      }
      return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10106DD0
// Name: rpt_server_enable
// Source: json
//------------------------------------------------------------------------------
void __cdecl rpt_server_enable(const CCommand *args)
{
  const char *v1; // eax
  CBaseClient *v2; // esi
  char *v3; // eax
  const char *v4; // eax
  unsigned __int16 v5; // ax
  char *v6; // eax
  char pBuf[256]; // [esp+4h] [ebp-118h] BYREF
  netadr_s adr; // [esp+104h] [ebp-18h] BYREF
  netadr_s adrClient; // [esp+110h] [ebp-Ch] BYREF

  if ( (args->m_nArgc == 5 || args->m_nArgc == 2)
    && cmd_clientslot >= 0
    && (g_nRptServerSlot < 0 || g_nRptServerSlot == cmd_clientslot)
    && PlayerIsValveEmployee(nClientSlot: cmd_clientslot) != 0 )
  {
    if ( g_nRptClientSlot < 0 )
    {
      ConMsg(a1: "No valid clients.\n");
LABEL_9:
      g_nRptServerSlot = -1;
      return;
    }
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    if ( atoi(nptr: v1) == 0 )
      goto LABEL_9;
    v2 = sv.m_Clients.m_Memory.m_pMemory[cmd_clientslot];
    v3 = (char *)defaultValue;
    if ( args->m_nArgc > 2 )
      v3 = (char *)args->m_ppArgv[2];
    netadr_s::SetFromString(this: &adr, pch: v3, bUseDNS: 0);
    adrClient = *v2->m_NetChannel->GetRemoteAddress(this: v2->m_NetChannel);
    if ( netadr_s::IsLoopback(this: &adrClient) || netadr_s::CompareAdr(this: &adr, a: &adrClient, onlyBase: true) )
    {
      v4 = defaultValue;
      if ( args->m_nArgc > 4 )
        v4 = args->m_ppArgv[4];
      v5 = atoi(nptr: v4);
      netadr_s::SetPort(this: &adr, newport: v5);
      if ( g_nRptServerSlot < 0 )
        g_nRptServerSlot = cmd_clientslot;
      v6 = netadr_s::ToString(this: &adr, baseOnly: false);
      V_snprintf(pDest: pBuf, maxLen: 256, pFormat: "rpt_connect %s\n", v6);
      SV_ExecuteRemoteCommand(pCommand: pBuf, nClientSlot: g_nRptClientSlot);
    }
    else
    {
      ConMsg(a1: "Invalid server IP address.\n");
    }
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101066B0
// Name: rpt_password
// Source: json
//------------------------------------------------------------------------------
void __cdecl rpt_password(const CCommand *args)
{
  int v1; // eax
  CRPTServer *v2; // eax
  bool HasPassword; // bl
  CRPTServer *v4; // eax
  CRPTServer *v5; // eax
  const char *v6; // esi
  const char *v7; // [esp-Ch] [ebp-614h]
  CCommand argsClient; // [esp+0h] [ebp-608h] BYREF
  char buf[256]; // [esp+508h] [ebp-100h] BYREF

  v1 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-rpt") == 0 )
  {
    ConMsg(a1: "This command will not work unless the game is launched with -rpt\n");
    return;
  }
  if ( args->m_nArgc > 2 )
  {
    ConMsg(a1: "Incorrect # of arguments.\n");
    return;
  }
  if ( NET_IsDedicated() || !NET_IsMultiplayer() || args->m_nArgc > 2 )
  {
    ConMsg(a1: "Failed!\n");
    return;
  }
  v2 = RPTServer();
  HasPassword = CRConServer::HasPassword(this: v2);
  if ( args->m_nArgc == 1 )
  {
    if ( !HasPassword )
      return;
    v4 = RPTServer();
    CRConServer::SetPassword(this: v4, pPassword: nullptr);
    ConMsg(a1: "Disabling...\n");
    V_snprintf(pDest: buf, maxLen: 255, pFormat: "rpt_client_enable 0");
    goto LABEL_17;
  }
  if ( args->m_nArgc != 2 )
  {
LABEL_17:
    CCommand::CCommand(this: &argsClient);
    CCommand::Tokenize(this: &argsClient, pCommand: buf, pBreakSet: nullptr);
    Cmd_ForwardToServer(args: &argsClient, bReliable: true);
    return;
  }
  v7 = args->m_ppArgv[1];
  v5 = RPTServer();
  CRConServer::SetPassword(this: v5, pPassword: v7);
  if ( args->m_nArgc > 1 )
    v6 = args->m_ppArgv[1];
  else
    v6 = defaultValue;
  ConMsg(a1: "New password : %s\n", v6);
  if ( !HasPassword )
  {
    ConMsg(a1: "Enabling...\n");
    V_snprintf(pDest: buf, maxLen: 255, pFormat: "rpt_client_enable 1");
    goto LABEL_17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106820
// Name: void SV_NotifyRPTOfDisconnect(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SV_NotifyRPTOfDisconnect(int nClientSlot)
{
  CRPTServer *v1; // eax
  CRPTClient *v2; // eax
  CRPTClient *v3; // eax

  if ( nClientSlot == g_nRptClientSlot )
    g_nRptClientSlot = -1;
  if ( nClientSlot == g_nRptServerSlot )
    g_nRptServerSlot = -1;
  v1 = RPTServer();
  CRConServer::SetPassword(this: v1, pPassword: nullptr);
  v2 = RPTClient();
  CRConClient::SetPassword(this: v2, pPassword: nullptr);
  v3 = RPTClient();
  CRConClient::CloseListenSocket(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10106870
// Name: void CL_NotifyRPTOfDisconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_NotifyRPTOfDisconnect()
{
  CRPTServer *v0; // eax
  CRPTClient *v1; // eax
  CRPTClient *v2; // eax

  v0 = RPTServer();
  CRConServer::SetPassword(this: v0, pPassword: nullptr);
  v1 = RPTClient();
  CRConClient::SetPassword(this: v1, pPassword: nullptr);
  v2 = RPTClient();
  CRConClient::CloseListenSocket(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101068A0
// Name: rpt_start
// Source: json
//------------------------------------------------------------------------------
void __cdecl rpt_start(const CCommand *args)
{
  const CCommand *v1; // esi
  int m_nArgc; // eax
  const char *v3; // eax
  CRPTClient *v4; // eax
  CRPTClient *v5; // eax
  CRPTClient *v6; // eax
  const char *v7; // eax
  unsigned __int16 v8; // [esp-4h] [ebp-728h]
  const char *v9; // [esp-4h] [ebp-728h]
  CCommand argsClient; // [esp+4h] [ebp-720h] BYREF
  char pDir[260]; // [esp+50Ch] [ebp-218h] BYREF
  char pBuf[256]; // [esp+610h] [ebp-114h] BYREF
  int nDay; // [esp+710h] [ebp-14h] BYREF
  int nMonth; // [esp+714h] [ebp-10h] BYREF
  netadr_s rptAddr; // [esp+718h] [ebp-Ch] BYREF

  v1 = args;
  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc < 2 || m_nArgc > 3 )
  {
    ConMsg(a1: "Incorrect # of arguments.\n");
  }
  else
  {
    rptAddr = net_local_adr;
    if ( m_nArgc == 3 )
    {
      v8 = atoi(nptr: args->m_ppArgv[2]);
      netadr_s::SetPort(this: &rptAddr, newport: v8);
    }
    else
    {
      netadr_s::SetPort(this: &rptAddr, newport: 0x699Cu);
    }
    v3 = defaultValue;
    if ( v1->m_nArgc > 1 )
      v3 = v1->m_ppArgv[1];
    v9 = v3;
    v4 = RPTClient();
    CRConClient::SetPassword(this: v4, pPassword: v9);
    v5 = RPTClient();
    CRConClient::CreateListenSocket(this: v5, netAdr: &rptAddr);
    _GetCurrentDate(a1: &nDay, a2: &nMonth, a3: &args);
    V_snprintf(pDest: pDir, maxLen: 260, pFormat: "rpt/%d_%d_%d", nMonth, nDay, args);
    v6 = RPTClient();
    CRConClient::SetRemoteFileDirectory(this: v6, pDir);
    v7 = netadr_s::ToString(this: &rptAddr, baseOnly: false);
    V_snprintf(pDest: pBuf, maxLen: 256, pFormat: "rpt_server_enable 1 %s\n", v7);
    CCommand::CCommand(this: &argsClient);
    CCommand::Tokenize(this: &argsClient, pCommand: pBuf, pBreakSet: nullptr);
    Cmd_ForwardToServer(args: &argsClient, bReliable: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101069E0
// Name: rpt_end
// Source: json
//------------------------------------------------------------------------------
void __cdecl rpt_end(const CCommand *args)
{
  CRPTClient *v1; // eax
  CRPTClient *v2; // eax
  CCommand argsClient; // [esp+0h] [ebp-608h] BYREF
  char pBuf[256]; // [esp+508h] [ebp-100h] BYREF

  if ( args->m_nArgc == 1 )
  {
    v1 = RPTClient();
    CRConClient::SetPassword(this: v1, pPassword: nullptr);
    v2 = RPTClient();
    CRConClient::CloseListenSocket(this: v2);
    V_snprintf(pDest: pBuf, maxLen: 256, pFormat: "rpt_server_enable 0\n");
    CCommand::CCommand(this: &argsClient);
    CCommand::Tokenize(this: &argsClient, pCommand: pBuf, pBreakSet: nullptr);
    Cmd_ForwardToServer(args: &argsClient, bReliable: true);
  }
  else
  {
    ConMsg(a1: "Incorrect # of arguments.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106A70
// Name: IsValveIPAddress
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall IsValveIPAddress@<eax>(netadr_s *adr@<esi>)
{
  netadr_s valveIP2; // [esp+0h] [ebp-18h] BYREF
  netadr_s valveIP1; // [esp+Ch] [ebp-Ch] BYREF

  netadr_s::SetIP(this: &valveIP1, unIP: 0);
  netadr_s::SetPort(this: &valveIP1, newport: 0);
  netadr_s::SetType(this: &valveIP1, newtype: NA_IP);
  netadr_s::SetIP(this: &valveIP2, unIP: 0);
  netadr_s::SetPort(this: &valveIP2, newport: 0);
  netadr_s::SetType(this: &valveIP2, newtype: NA_IP);
  netadr_s::SetIP(this: &valveIP1, b1: 0xCFu, b2: 0xADu, b3: 0xB2u, b4: 0xFFu);
  netadr_s::SetIP(this: &valveIP2, b1: 0xCFu, b2: 0xADu, b3: 0xB3u, b4: 0xFFu);
  return netadr_s::CompareClassCAdr(this: adr, a: &valveIP1)
      || netadr_s::CompareClassCAdr(this: adr, a: &valveIP2)
      || netadr_s::IsLoopback(this: adr);
}

//------------------------------------------------------------------------------
// Address: 0x10106B30
// Name: rpt_connect
// Source: json
//------------------------------------------------------------------------------
void __cdecl rpt_connect(const CCommand *args)
{
  int v1; // eax
  const char *v2; // esi
  unsigned __int16 v3; // ax
  CRPTServer *v4; // eax
  netadr_s adr; // [esp+0h] [ebp-Ch] BYREF

  v1 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-rpt") != 0 && args->m_nArgc == 4 )
  {
    netadr_s::SetFromString(this: &adr, pch: args->m_ppArgv[1], bUseDNS: false);
    if ( args->m_nArgc > 3 )
      v2 = args->m_ppArgv[3];
    else
      v2 = defaultValue;
    v3 = atoi(nptr: v2);
    netadr_s::SetPort(this: &adr, newport: v3);
    if ( IsValveIPAddress(&adr) )
    {
      v4 = RPTServer();
      CRConServer::ConnectToListeningClient(this: v4, &adr, bSingleSocket: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106BB0
// Name: rpt
// Source: json
//------------------------------------------------------------------------------
void __cdecl rpt(const CCommand *args)
{
  int m_nArgc; // eax
  int v3; // edi
  char *v4; // esi
  int v5; // eax
  CRPTClient *v6; // eax
  char message[1024]; // [esp+8h] [ebp-500h] BYREF
  char szParam[256]; // [esp+408h] [ebp-100h] BYREF
  const CCommand *argsa; // [esp+510h] [ebp+8h]

  m_nArgc = args->m_nArgc;
  v3 = 1;
  message[0] = 0;
  if ( m_nArgc > 1 )
  {
    argsa = (const CCommand *)&args->m_ppArgv[1];
    do
    {
      if ( v3 < 0 || v3 >= m_nArgc )
        v4 = (char *)defaultValue;
      else
        v4 = (char *)argsa->m_nArgc;
      strchr(string: v4, chr: 0x20u);
      if ( v5 != 0 || _V_strlen(str: v4) == 0 )
      {
        V_snprintf(pDest: szParam, maxLen: 256, pFormat: "\"%s\"", v4);
        V_strncat(pDest: message, pSrc: szParam, destBufferSize: 0x400u, max_chars_to_copy: -1);
      }
      else
      {
        V_strncat(pDest: message, pSrc: v4, destBufferSize: 0x400u, max_chars_to_copy: -1);
      }
      if ( v3 != args->m_nArgc - 1 )
        V_strncat(pDest: message, pSrc: " ", destBufferSize: 0x400u, max_chars_to_copy: -1);
      m_nArgc = args->m_nArgc;
      argsa = (const CCommand *)((char *)argsa + 4);
      ++v3;
    }
    while ( v3 < args->m_nArgc );
  }
  v6 = RPTClient();
  CRConClient::SendCmd(this: v6, msg: message);
}

//------------------------------------------------------------------------------
// Address: 0x10106CB0
// Name: rpt_client_enable
// Source: json
//------------------------------------------------------------------------------
void __cdecl rpt_client_enable(const CCommand *args)
{
  if ( args->m_nArgc == 2 && cmd_clientslot >= 0 && sv.m_Clients.m_Memory.m_pMemory[cmd_clientslot] != nullptr )
  {
    if ( atoi(nptr: args->m_ppArgv[1]) != 0 )
      g_nRptClientSlot = cmd_clientslot;
    else
      g_nRptClientSlot = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106D00
// Name: PlayerIsValveEmployee
// Source: json
//------------------------------------------------------------------------------
char __cdecl PlayerIsValveEmployee(int nClientSlot)
{
  CBaseClient *v1; // edi
  netadr_s *v3; // eax
  int v4; // edx
  player_info_s pi; // [esp+8h] [ebp-90h] BYREF

  v1 = sv.m_Clients.m_Memory.m_pMemory[nClientSlot];
  if ( v1 == nullptr )
    return 0;
  v3 = (netadr_s *)v1->m_NetChannel->GetRemoteAddress(this: v1->m_NetChannel);
  if ( !IsValveIPAddress(adr: v3) )
    return 0;
  if ( GetSteamUniverse() != k_EUniverseBeta )
  {
    if ( v1->m_bFullyAuthenticated
      && CBaseServer::GetPlayerInfo(this: &sv, nClientIndex: nClientSlot, pinfo: (unsigned int)&pi) != 0
      && pi.friendsID != 0 )
    {
      v4 = 0;
      while ( pi.friendsID != ((unsigned int)s_ValveMask ^ LODWORD(s_pValveIDs[v4]))
           || (dword_10416E4C ^ HIDWORD(s_pValveIDs[v4])) != 0x1100001 )
      {
        if ( (unsigned int)++v4 >= 1 )
          return 0;
      }
      return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10106DC0
// Name: rpt_server_enable
// Source: json
//------------------------------------------------------------------------------
void __cdecl rpt_server_enable(const CCommand *args)
{
  const char *v1; // eax
  CBaseClient *v2; // esi
  const char *v3; // eax
  const char *v4; // eax
  unsigned __int16 v5; // ax
  const char *v6; // eax
  char pBuf[256]; // [esp+4h] [ebp-118h] BYREF
  netadr_s adr; // [esp+104h] [ebp-18h] BYREF
  netadr_s adrClient; // [esp+110h] [ebp-Ch] BYREF

  if ( (args->m_nArgc == 5 || args->m_nArgc == 2)
    && cmd_clientslot >= 0
    && (g_nRptServerSlot < 0 || g_nRptServerSlot == cmd_clientslot)
    && PlayerIsValveEmployee(nClientSlot: cmd_clientslot) != 0 )
  {
    if ( g_nRptClientSlot < 0 )
    {
      ConMsg(a1: "No valid clients.\n");
LABEL_9:
      g_nRptServerSlot = -1;
      return;
    }
    v1 = defaultValue;
    if ( args->m_nArgc > 1 )
      v1 = args->m_ppArgv[1];
    if ( atoi(nptr: v1) == 0 )
      goto LABEL_9;
    v2 = sv.m_Clients.m_Memory.m_pMemory[cmd_clientslot];
    v3 = defaultValue;
    if ( args->m_nArgc > 2 )
      v3 = args->m_ppArgv[2];
    netadr_s::SetFromString(this: &adr, pch: v3, bUseDNS: false);
    adrClient = *v2->m_NetChannel->GetRemoteAddress(this: v2->m_NetChannel);
    if ( netadr_s::IsLoopback(this: &adrClient) || netadr_s::CompareAdr(this: &adr, a: &adrClient, onlyBase: true) )
    {
      v4 = defaultValue;
      if ( args->m_nArgc > 4 )
        v4 = args->m_ppArgv[4];
      v5 = atoi(nptr: v4);
      netadr_s::SetPort(this: &adr, newport: v5);
      if ( g_nRptServerSlot < 0 )
        g_nRptServerSlot = cmd_clientslot;
      v6 = netadr_s::ToString(this: &adr, baseOnly: false);
      V_snprintf(pDest: pBuf, maxLen: 256, pFormat: "rpt_connect %s\n", v6);
      SV_ExecuteRemoteCommand(pCommand: pBuf, nClientSlot: g_nRptClientSlot);
    }
    else
    {
      ConMsg(a1: "Invalid server IP address.\n");
    }
  }
}

} // namespace engine_xlsp
