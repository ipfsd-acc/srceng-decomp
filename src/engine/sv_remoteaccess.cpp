// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sv_remoteaccess.cpp
// Functions: 34
// ============================================================

#include "engine\sv_remoteaccess.h"

//------------------------------------------------------------------------------
// Address: 0x1012CE50
// Name: private: void CServerRemoteAccess::ExecCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::ExecCommand(CServerRemoteAccess *this, const char *cmdString)
{
  Cbuf_AddText(eTarget: CBUF_SERVER, pText: cmdString, nTickDelay: 0);
  Cbuf_AddText(eTarget: CBUF_SERVER, pText: "\n", nTickDelay: 0);
  Cbuf_Execute();
}

//------------------------------------------------------------------------------
// Address: 0x1012CE80
// Name: private: void CServerRemoteAccess::SetValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::SetValue(CServerRemoteAccess *this, const char *variable, const char *value)
{
  const char *v3; // eax
  void *v4; // esi
  IBaseFileSystem_vtbl *v5; // edi
  int v6; // eax
  const char *v7; // eax
  ConVarRef mapcycle; // [esp+4h] [ebp-8h] BYREF

  if ( _V_stricmp(s1: variable, s2: "map") != 0 )
  {
    if ( _V_stricmp(s1: variable, s2: "mapcycle") != 0 )
    {
      v7 = va(format: "%s %s", variable, value);
      Cbuf_AddText(eTarget: CBUF_SERVER, pText: v7, nTickDelay: 0);
      Cbuf_AddText(eTarget: CBUF_SERVER, pText: "\n", nTickDelay: 0);
      Cbuf_Execute();
    }
    else
    {
      ConVarRef::ConVarRef(this: &mapcycle, pName: "mapcyclefile");
      if ( ConVarRef::IsValid(this: &mapcycle) )
      {
        v4 = g_pFileSystem->Open(
               this: &g_pFileSystem->IBaseFileSystem,
               a2: mapcycle.m_pConVarState->m_Value.m_pszString,
               a3: "wt",
               a4: 0);
        if ( v4 != nullptr
          || (_Msg(
                a1: "Couldn't write to read-only file %s, using file _temp_mapcycle.txt instead.\n",
                mapcycle.m_pConVarState->m_Value.m_pszString),
              mapcycle.m_pConVar->SetValue_4(this: mapcycle.m_pConVar, a2: "_temp_mapcycle.txt"),
              (v4 = g_pFileSystem->Open(
                      this: &g_pFileSystem->IBaseFileSystem,
                      a2: mapcycle.m_pConVarState->m_Value.m_pszString,
                      a3: "wt",
                      a4: 0)) != nullptr) )
        {
          v5 = g_pFileSystem->IBaseFileSystem::__vftable;
          v6 = _V_strlen(str: value);
          v5->Write(this: &g_pFileSystem->IBaseFileSystem, a2: value, a3: v6 + 1, a4: v4);
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
        }
      }
    }
  }
  else
  {
    v3 = va(format: "changelevel %s\n", value);
    Cbuf_AddText(eTarget: CBUF_SERVER, pText: v3, nTickDelay: 0);
    Cbuf_Execute();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012CFF0
// Name: private: char const __near * CServerRemoteAccess::LookupStringValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CServerRemoteAccess::LookupStringValue(CServerRemoteAccess *this, const char *variable)
{
  ConVar *v2; // eax
  IConVar *v3; // eax
  int NumClients; // esi
  int NumProxies; // eax
  int MaxClients; // eax
  ConVarRef var; // [esp+4h] [ebp-8h] BYREF

  v2 = g_pCVar->FindVar_2(this: g_pCVar, a2: variable);
  if ( v2 != nullptr )
  {
    v3 = &v2->IConVar;
    if ( v3 != nullptr )
    {
      ConVarRef::ConVarRef(this: &var, pConVar: v3);
      if ( ConVarRef::IsValid(this: &var) )
        return var.m_pConVarState->m_Value.m_pszString;
    }
  }
  if ( _V_stricmp(s1: variable, s2: "map") == 0 )
    return sv.m_szMapname;
  if ( _V_stricmp(s1: variable, s2: "playercount") != 0 )
  {
    if ( _V_stricmp(s1: variable, s2: "maxplayers") != 0 )
    {
      if ( _V_stricmp(s1: variable, s2: "gamedescription") != 0 || serverGameDLL == nullptr )
        return nullptr;
      else
        return serverGameDLL->GetGameDescription(this: serverGameDLL);
    }
    else
    {
      MaxClients = CBaseServer::GetMaxClients(this: &sv);
      V_snprintf(pDest: s_ReturnBuf, maxLen: 31, pFormat: "%d", MaxClients);
      return s_ReturnBuf;
    }
  }
  else
  {
    NumClients = CBaseServer::GetNumClients(this: &sv);
    NumProxies = CBaseServer::GetNumProxies(this: &sv);
    V_snprintf(pDest: s_ReturnBuf, maxLen: 31, pFormat: "%d", NumClients - NumProxies);
    return s_ReturnBuf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D110
// Name: public: void CServerRemoteAccess::GetStatsString(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::GetStatsString(CServerRemoteAccess *this, char *buf, int bufSize)
{
  int m_nSpawnCount; // esi
  int NumClients; // edi
  CStatTime *v5; // ecx
  int v6; // eax
  double v7; // [esp-Ch] [ebp-20h]
  int v8; // [esp-4h] [ebp-18h]
  float v9[2]; // [esp+8h] [ebp-Ch] BYREF
  float var30[2]; // [esp+10h] [ebp-4h] BYREF

  v9[1] = 0.0;
  var30[0] = 0.0;
  CBaseServer::GetNetStats(this: &sv, avgIn: &v9[1], avgOut: var30);
  m_nSpawnCount = sv.m_nSpawnCount;
  v9[0] = sv.m_fCPUPercent;
  NumClients = CBaseServer::GetNumClients(this: &sv);
  v8 = NumClients - CBaseServer::GetNumProxies(this: &sv);
  v7 = 1.0 / host_frametime;
  v6 = (int)_Plat_FloatTime(this: v5);
  _snprintf(
    string: buf,
    count: bufSize - 1,
    format: "%5.2f %5.2f %5.2f %7i %5i %7.2f %7i",
    v9[0] * 100.0,
    v9[1],
    var30[0],
    v6 / 60,
    m_nSpawnCount - 1,
    v7,
    v8);
  buf[bufSize - 1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012D280
// Name: void Host_Stats_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_Stats_f()
{
  char stats[512]; // [esp+0h] [ebp-200h] BYREF

  CServerRemoteAccess::GetStatsString(this: &g_ServerRemoteAccess, buf: stats, bufSize: 512);
  ConMsg(a1: "CPU   In    Out   Uptime  Users   FPS    Players\n%s\n", stats);
}

//------------------------------------------------------------------------------
// Address: 0x1012D2C0
// Name: private: void CServerRemoteAccess::LogCommand(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::LogCommand(CServerRemoteAccess *this, unsigned int listener, const char *msg)
{
  const char *v4; // eax

  if ( sv_rcon_log.m_pParent != nullptr && sv_rcon_log.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( listener < this->m_ListenerIDs.m_ElementCount
      && this->m_ListenerIDs.m_Memory.m_pMemory[listener].m_Element.m_bHasAddress )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SERVER_LOG, a2: 0) != 0 )
      {
        v4 = netadr_s::ToString(this: &this->m_ListenerIDs.m_Memory.m_pMemory[listener].m_Element.adr, baseOnly: false);
        _LoggingSystem_Log(a1: LOG_SERVER_LOG, a2: 0, a3: "rcon from \"%s\": %s\n", v4, msg);
      }
    }
    else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SERVER_LOG, a2: 0) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_SERVER_LOG, a2: 0, a3: "rcon from \"unknown\": %s\n", msg);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D5E0
// Name: bool GetStringHelper(class CUtlBuffer __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetStringHelper(CUtlBuffer *cmd, char *outBuf, int bufSize)
{
  *outBuf = 0;
  CUtlBuffer::GetString(this: cmd, pString: outBuf, nMaxChars: bufSize);
  if ( cmd->m_Error == 0 )
    return 1;
  cmd->m_Get = 0;
  cmd->m_Put = 0;
  cmd->m_nOffset = 0;
  cmd->m_nMaxPut = 0;
  cmd->m_Error = 0;
  if ( cmd->m_Memory.m_nGrowSize >= 0 )
  {
    if ( cmd->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cmd->m_Memory.m_pMemory);
      cmd->m_Memory.m_pMemory = nullptr;
    }
    cmd->m_Memory.m_nAllocationCount = 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012D640
// Name: public: int CServerRemoteAccess::GetDataResponseSize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CServerRemoteAccess::GetDataResponseSize(CServerRemoteAccess *this, unsigned int listener)
{
  int i; // eax
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *m_pMemory; // edi
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v4; // edx

  for ( i = this->m_ResponsePackets.m_Head; i >= 0; i = v4->m_Next )
  {
    if ( i >= this->m_ResponsePackets.m_Memory.m_nAllocationCount )
      break;
    if ( i > this->m_ResponsePackets.m_LastAlloc.index )
      break;
    m_pMemory = this->m_ResponsePackets.m_Memory.m_pMemory;
    v4 = &m_pMemory[i];
    if ( v4->m_Previous == i && v4->m_Next != i )
      break;
    if ( v4->m_Element.responderID == listener )
      return m_pMemory[i].m_Element.packet.m_Put;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012D820
// Name: private: void CServerRemoteAccess::GetUserBanList(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::GetUserBanList(CServerRemoteAccess *this, CUtlBuffer *value)
{
  int v2; // eax
  int v3; // ebx
  int v4; // edi
  const char *UserIDString; // eax
  int v6; // edi
  int v7; // ebx
  unsigned __int8 m_Flags; // cl
  int m_Put; // eax
  int v10; // eax
  int i; // edi
  double banTime; // [esp-8h] [ebp-14h]

  v2 = 0;
  if ( g_UserFilters.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      banTime = g_UserFilters.m_Memory.m_pMemory[v3].banTime;
      v4 = v2 + 1;
      UserIDString = GetUserIDString(id: &g_UserFilters.m_Memory.m_pMemory[v3].userid);
      CUtlBuffer::Printf(this: value, pFmt: "%i %s : %.3f min\n", v4, UserIDString, banTime);
      v2 = v4;
      ++v3;
    }
    while ( v4 < g_UserFilters.m_Size );
  }
  v6 = 0;
  if ( g_IPFilters.m_Size > 0 )
  {
    v7 = 0;
    do
    {
      CUtlBuffer::Printf(
        this: value,
        pFmt: "%i %i.%i.%i.%i : %.3f min\n",
        g_UserFilters.m_Size + v6++ + 1,
        (unsigned __int8)g_IPFilters.m_Memory.m_pMemory[v7].compare,
        BYTE1(g_IPFilters.m_Memory.m_pMemory[v7].compare),
        (unsigned __int8)BYTE2(g_IPFilters.m_Memory.m_pMemory[v7].compare),
        HIBYTE(g_IPFilters.m_Memory.m_pMemory[v7].compare),
        g_IPFilters.m_Memory.m_pMemory[v7].banTime);
      ++v7;
    }
    while ( v6 < g_IPFilters.m_Size );
  }
  m_Flags = value->m_Flags;
  if ( (m_Flags & 1) != 0 )
  {
    m_Put = value->m_Put;
    if ( m_Put != 0 && value->m_Memory.m_pMemory[m_Put - value->m_nOffset - 1] == 10 )
    {
      v10 = (m_Flags & 0x10) != 0 ? 0 : value->m_nTab;
      for ( i = v10 - 1; i >= 0; --i )
      {
        if ( CUtlBuffer::CheckPut(this: value, nSize: 1) )
        {
          value->m_Memory.m_pMemory[value->m_Put - value->m_nOffset] = 9;
          CUtlBuffer::AddNullTermination(this: value, nPut: ++value->m_Put);
        }
      }
    }
  }
  if ( CUtlBuffer::CheckPut(this: value, nSize: 1) )
  {
    value->m_Memory.m_pMemory[value->m_Put - value->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: value, nPut: ++value->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D980
// Name: private: void CServerRemoteAccess::GetPlayerList(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::GetPlayerList(CServerRemoteAccess *this, CUtlBuffer *value)
{
  int v2; // ebx
  CBaseClient *v3; // edi
  IClient *v4; // esi
  CPlayerState *v5; // edi
  bool v6; // al
  IClient_vtbl *v7; // edx
  int v8; // eax
  const char *v9; // eax
  int v10; // edi
  int v11; // ebx
  double v12; // st7
  double v13; // st7
  double v14; // st7
  int v15; // eax
  int v16; // eax
  const char *v17; // eax
  int m_Put; // eax
  const char *v19; // [esp-24h] [ebp-34h]
  const char *v20; // [esp-20h] [ebp-30h]
  int v21; // [esp-1Ch] [ebp-2Ch]
  int v22; // [esp-18h] [ebp-28h]
  const char *v23; // [esp-14h] [ebp-24h]
  int v24; // [esp-14h] [ebp-24h]
  int v25; // [esp-10h] [ebp-20h]
  int v26; // [esp-10h] [ebp-20h]
  int v27; // [esp+0h] [ebp-10h]
  int v28; // [esp+4h] [ebp-Ch]
  CPlayerState *pl; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( serverGameClients != nullptr )
  {
    v2 = 0;
    for ( i = 0; v2 < sv.m_Clients.m_Size; i = v2 )
    {
      v3 = sv.m_Clients.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v4 = &v3->IClient;
        if ( v3->IsActive(this: &v3->IClient) )
        {
          v5 = serverGameClients->GetPlayerState(this: serverGameClients, a2: *(_DWORD *)v3[1].m_GUID);
          pl = v5;
          if ( v5 != nullptr )
          {
            v6 = v4->IsFakeClient(this: v4);
            v7 = v4->__vftable;
            if ( v6 )
            {
              v8 = ((int (__thiscall *)(IClient *, int))v7->GetNetworkIDString)(a1: v4, a2: v5->frags);
              v9 = (const char *)((int (__thiscall *)(IClient *, int))v4->GetClientName)(a1: v4, a2: v8);
              CUtlBuffer::Printf(this: value, pFmt: "\"%s\" %s 0 0 0 %d 0\n", v9, v23, v25);
            }
            else
            {
              v10 = (int)v7->GetNetChannel(this: v4);
              v11 = (int)v4->GetNetChannel(this: v4);
              v28 = (int)v4->GetNetChannel(this: v4);
              v27 = (int)v4->GetNetChannel(this: v4);
              v12 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v10 + 12))(a1: v10);
              v13 = ((double (__thiscall *)(int, int, int, int))*(_DWORD *)(*(_DWORD *)v11 + 44))(
                      a1: v11,
                      a2: 1,
                      a3: pl->frags,
                      a4: (int)v12);
              v14 = ((double (__thiscall *)(int, _DWORD, int))*(_DWORD *)(*(_DWORD *)v28 + 40))(
                      a1: v28,
                      a2: 0,
                      a3: (int)v13)
                  * 1000.0;
              v15 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v27 + 4))(a1: v27, a2: (int)v14);
              v16 = ((int (__thiscall *)(IClient *, int))v4->GetNetworkIDString)(a1: v4, a2: v15);
              v17 = (const char *)((int (__thiscall *)(IClient *, int))v4->GetClientName)(a1: v4, a2: v16);
              CUtlBuffer::Printf(this: value, pFmt: "\"%s\" %s %s %d %d %d %d\n", v17, v19, v20, v21, v22, v24, v26);
              v2 = i;
            }
          }
        }
      }
      ++v2;
    }
    if ( (value->m_Flags & 1) != 0 )
    {
      m_Put = value->m_Put;
      if ( m_Put != 0 && value->m_Memory.m_pMemory[m_Put - value->m_nOffset - 1] == 10 )
        CUtlBuffer::PutTabs(this: value);
    }
    if ( CUtlBuffer::CheckPut(this: value, nSize: 1) )
    {
      value->m_Memory.m_pMemory[value->m_Put - value->m_nOffset] = 0;
      CUtlBuffer::AddNullTermination(this: value, nPut: ++value->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012DB40
// Name: private: void CServerRemoteAccess::GetMapList(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::GetMapList(CServerRemoteAccess *this, CUtlBuffer *value)
{
  const char *i; // esi
  int v3; // eax
  _BYTE *v4; // eax
  int m_Put; // eax
  char mapName[260]; // [esp+8h] [ebp-36Ch] BYREF
  char friendly_com_gamedir[260]; // [esp+10Ch] [ebp-268h] BYREF
  char curDir[260]; // [esp+210h] [ebp-164h] BYREF
  char mapwild[96]; // [esp+314h] [ebp-60h] BYREF

  strcpy(mapwild, "maps/*.bsp");
  V_strncpy(pDest: friendly_com_gamedir, pSrc: com_gamedir, maxLen: 260);
  _V_strlower(start: friendly_com_gamedir);
  for ( i = Sys_FindFirst(path: mapwild, basename: nullptr, namelength: 0);
        i != nullptr;
        i = Sys_FindNext(basename: nullptr, namelength: 0) )
  {
    _snprintf(string: curDir, count: 0x104u, format: "maps/%s", i);
    g_pFileSystem->GetLocalPath(this: g_pFileSystem, a2: curDir, a3: curDir, a4: 260);
    strstr(str1: (unsigned __int8 *)curDir, str2: (unsigned __int8 *)friendly_com_gamedir);
    if ( v3 != 0 )
    {
      strcpy(mapName, i);
      strstr(str1: (unsigned __int8 *)mapName, str2: ".bsp");
      if ( v4 != nullptr )
        *v4 = 0;
      CUtlBuffer::PutString(this: value, pString: mapName);
      CUtlBuffer::PutString(this: value, pString: "\n");
    }
  }
  Sys_FindClose();
  if ( (value->m_Flags & 1) != 0 )
  {
    m_Put = value->m_Put;
    if ( m_Put != 0 && value->m_Memory.m_pMemory[m_Put - value->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: value);
  }
  if ( CUtlBuffer::CheckPut(this: value, nSize: 1) )
  {
    value->m_Memory.m_pMemory[value->m_Put - value->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: value, nPut: ++value->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012DCC0
// Name: private: bool CServerRemoteAccess::LookupValue(char const __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerRemoteAccess::LookupValue(CServerRemoteAccess *this, const char *variable, CUtlBuffer *value)
{
  const char *v4; // eax
  CStatTime *v6; // ecx
  double v7; // st7
  const char *v8; // eax
  void *v9; // edi
  int v10; // esi
  void *v11; // esp
  char *v12; // [esp-4h] [ebp-234h]
  int UDPPort; // [esp-4h] [ebp-234h]
  const char *v14; // [esp-4h] [ebp-234h]
  _BYTE v15[12]; // [esp+0h] [ebp-230h] BYREF
  char stats[512]; // [esp+Ch] [ebp-224h] BYREF
  char addr[28]; // [esp+20Ch] [ebp-24h] BYREF
  ConVarRef mapcycle; // [esp+228h] [ebp-8h] BYREF

  v4 = CServerRemoteAccess::LookupStringValue(this, variable);
  if ( v4 != nullptr )
  {
    v12 = (char *)v4;
LABEL_15:
    CUtlBuffer::PutString(this: value, pString: v12);
    CUtlBuffer::PutChar(this: value, c: 0);
    return 1;
  }
  if ( _V_stricmp(s1: variable, s2: "stats") == 0 )
  {
    CServerRemoteAccess::GetStatsString(this, buf: stats, bufSize: 512);
    CUtlBuffer::PutString(this: value, pString: stats);
    CUtlBuffer::PutChar(this: value, c: 0);
    return 1;
  }
  if ( _V_stricmp(s1: variable, s2: "banlist") == 0 )
  {
    CServerRemoteAccess::GetUserBanList(this, value);
    return 1;
  }
  if ( _V_stricmp(s1: variable, s2: "playerlist") == 0 )
  {
    CServerRemoteAccess::GetPlayerList(this, value);
    return 1;
  }
  if ( _V_stricmp(s1: variable, s2: "maplist") == 0 )
  {
    CServerRemoteAccess::GetMapList(this, value);
    return 1;
  }
  if ( _V_stricmp(s1: variable, s2: "uptime") == 0 )
  {
    v7 = _Plat_FloatTime(this: v6);
    CUtlBuffer::PutInt(this: value, i: (int)v7);
    CUtlBuffer::PutChar(this: value, c: 0);
    return 1;
  }
  if ( _V_stricmp(s1: variable, s2: "ipaddress") == 0 )
  {
    UDPPort = NET_GetUDPPort(socket: sv.m_Socket);
    v8 = netadr_s::ToString(this: &net_local_adr, baseOnly: true);
    V_snprintf(pDest: addr, maxLen: 25, pFormat: "%s:%i", v8, UDPPort);
    v12 = addr;
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: variable, s2: "mapcycle") != 0 )
  {
    CUtlBuffer::PutChar(this: value, c: 0);
    return 0;
  }
  else
  {
    ConVarRef::ConVarRef(this: &mapcycle, pName: "mapcyclefile");
    if ( ConVarRef::IsValid(this: &mapcycle) )
    {
      v9 = g_pFileSystem->Open(
             this: &g_pFileSystem->IBaseFileSystem,
             a2: mapcycle.m_pConVarState->m_Value.m_pszString,
             a3: "rb",
             a4: 0);
      if ( v9 != nullptr )
      {
        v10 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v9);
        v11 = alloca(v10 + 1);
        if ( v10 != 0 && g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v15, a3: v10, a4: v9) != 0 )
        {
          v15[v10] = 0;
          v14 = v15;
        }
        else
        {
          v14 = defaultValue;
        }
        CUtlBuffer::PutString(this: value, pString: v14);
        CUtlBuffer::PutChar(this: value, c: 0);
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v9);
      }
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012E100
// Name: public: virtual unsigned int CServerRemoteAccess::GetNextListenerID(bool,struct netadr_s const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CServerRemoteAccess::GetNextListenerID(
        CServerRemoteAccess *this,
        bool authConnection,
        const netadr_s *adr)
{
  CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int> > *p_m_ListenerIDs; // esi
  int result; // eax
  unsigned int v5; // ecx

  p_m_ListenerIDs = &this->m_ListenerIDs;
  result = CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::AddToTail(this: &this->m_ListenerIDs);
  v5 = result;
  p_m_ListenerIDs->m_Memory.m_pMemory[v5].m_Element.listenerID = result;
  p_m_ListenerIDs->m_Memory.m_pMemory[v5].m_Element.authenticated = !authConnection;
  p_m_ListenerIDs->m_Memory.m_pMemory[v5].m_Element.m_bHasAddress = adr != nullptr;
  if ( adr != nullptr )
    p_m_ListenerIDs->m_Memory.m_pMemory[v5].m_Element.adr = *adr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012E160
// Name: public: void CServerRemoteAccess::RemoteBug(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::RemoteBug(CServerRemoteAccess *this, const char *pBugPath)
{
  int v3; // eax
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v4; // esi

  if ( this->m_nBugListener >= 0 )
  {
    v3 = CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AddToTail(this: &this->m_ResponsePackets);
    this->m_ResponsePackets.m_Memory.m_pMemory[v3].m_Element.responderID = this->m_nBugListener;
    v4 = &this->m_ResponsePackets.m_Memory.m_pMemory[v3];
    if ( (v4->m_Element.packet.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &v4->m_Element.packet, pFmt: "%d", 0);
    else
      CUtlBuffer::PutTypeBin<int>(this: &v4->m_Element.packet, src: 0);
    if ( (v4->m_Element.packet.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &v4->m_Element.packet, pFmt: "%d", 8);
    else
      CUtlBuffer::PutTypeBin<int>(this: &v4->m_Element.packet, src: 8);
    CUtlBuffer::PutString(this: &v4->m_Element.packet, pString: pBugPath);
    this->m_nBugListener = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012E1F0
// Name: private: void CServerRemoteAccess::BadPassword(class CRConServer __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::BadPassword(
        CServerRemoteAccess *this,
        CRConServer *pNetworkListener,
        unsigned int listener)
{
  UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int> *v4; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v6; // esi

  v4 = &this->m_ListenerIDs.m_Memory.m_pMemory[listener];
  v4->m_Element.authenticated = false;
  if ( CRConServer::HandleFailedRconAuth(this: pNetworkListener, adr: &v4->m_Element.adr) != 0 )
  {
    CRConServer::BCloseAcceptedSocket(this: pNetworkListener, listener);
  }
  else
  {
    v5 = CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AddToTail(this: &this->m_ResponsePackets);
    this->m_ResponsePackets.m_Memory.m_pMemory[v5].m_Element.responderID = listener;
    v6 = &this->m_ResponsePackets.m_Memory.m_pMemory[v5];
    if ( (v6->m_Element.packet.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &v6->m_Element.packet, pFmt: "%d", -1);
    else
      CUtlBuffer::PutTypeBin<int>(this: &v6->m_Element.packet, src: -1);
    if ( (v6->m_Element.packet.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &v6->m_Element.packet, pFmt: "%d", 2);
    else
      CUtlBuffer::PutTypeBin<int>(this: &v6->m_Element.packet, src: 2);
    CUtlBuffer::PutString(this: &v6->m_Element.packet, pString: defaultValue);
    CUtlBuffer::PutString(this: &v6->m_Element.packet, pString: defaultValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012E2B0
// Name: private: void CServerRemoteAccess::RequestValue(unsigned int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::RequestValue(
        CServerRemoteAccess *this,
        unsigned int listener,
        int requestID,
        const char *variable)
{
  int v5; // ecx
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v6; // esi
  CUtlBuffer value; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &value, growSize: 0, initSize: 256, nFlags: 1);
  CServerRemoteAccess::LookupValue(this, variable, &value);
  v5 = CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AddToTail(this: &this->m_ResponsePackets);
  this->m_ResponsePackets.m_Memory.m_pMemory[v5].m_Element.responderID = listener;
  v6 = &this->m_ResponsePackets.m_Memory.m_pMemory[v5];
  if ( (v6->m_Element.packet.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &v6->m_Element.packet, pFmt: "%d", requestID);
  else
    CUtlBuffer::PutTypeBin<int>(this: &v6->m_Element.packet, src: requestID);
  if ( (v6->m_Element.packet.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &v6->m_Element.packet, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: &v6->m_Element.packet, src: 0);
  CUtlBuffer::PutString(this: &v6->m_Element.packet, pString: variable);
  if ( (v6->m_Element.packet.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &v6->m_Element.packet, pFmt: "%d", value.m_Put);
  else
    CUtlBuffer::PutTypeBin<int>(this: &v6->m_Element.packet, src: value.m_Put);
  if ( value.m_Put != 0 )
    CUtlBuffer::Put(this: &v6->m_Element.packet, pMem: value.m_Memory.m_pMemory, size: value.m_Put);
  if ( value.m_Memory.m_nGrowSize >= 0 && value.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: value.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1012E3B0
// Name: private: void CServerRemoteAccess::RespondString(unsigned int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::RespondString(
        CServerRemoteAccess *this,
        unsigned int listener,
        int requestID,
        const char *pString)
{
  CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int> > *p_m_ResponsePackets; // esi
  int v5; // ecx
  CUtlBuffer *p_packet; // esi

  p_m_ResponsePackets = &this->m_ResponsePackets;
  v5 = CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AddToTail(this: &this->m_ResponsePackets);
  p_m_ResponsePackets->m_Memory.m_pMemory[v5].m_Element.responderID = listener;
  p_packet = &p_m_ResponsePackets->m_Memory.m_pMemory[v5].m_Element.packet;
  if ( (p_packet->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: p_packet, pFmt: "%d", requestID);
  else
    CUtlBuffer::PutTypeBin<int>(this: p_packet, src: requestID);
  if ( (p_packet->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: p_packet, pFmt: "%d", 7);
  else
    CUtlBuffer::PutTypeBin<int>(this: p_packet, src: 7);
  CUtlBuffer::PutString(this: p_packet, pString);
}

//------------------------------------------------------------------------------
// Address: 0x1012E440
// Name: public: void CServerRemoteAccess::SendMessageToAdminUI(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::SendMessageToAdminUI(
        CServerRemoteAccess *this,
        unsigned int listenerID,
        const char *message)
{
  int v4; // eax
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v5; // esi

  if ( listenerID != this->m_AdminUIID )
    _Warning(a1: "ServerRemoteAccess: Sending AdminUI message to non-AdminUI listener\n");
  v4 = CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AddToTail(this: &this->m_ResponsePackets);
  this->m_ResponsePackets.m_Memory.m_pMemory[v4].m_Element.responderID = listenerID;
  v5 = &this->m_ResponsePackets.m_Memory.m_pMemory[v4];
  if ( (v5->m_Element.packet.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &v5->m_Element.packet, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: &v5->m_Element.packet, src: 0);
  if ( (v5->m_Element.packet.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &v5->m_Element.packet, pFmt: "%d", 1);
  else
    CUtlBuffer::PutTypeBin<int>(this: &v5->m_Element.packet, src: 1);
  CUtlBuffer::PutString(this: &v5->m_Element.packet, pString: message);
}

//------------------------------------------------------------------------------
// Address: 0x1012E4E0
// Name: private: void CServerRemoteAccess::SendResponseToClient(unsigned int,enum ServerDataResponseType_t,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::SendResponseToClient(
        CServerRemoteAccess *this,
        unsigned int listenerID,
        ServerDataResponseType_t type,
        void *pData,
        int nDataLen)
{
  CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int> > *p_m_ResponsePackets; // esi
  int v6; // ecx
  CUtlBuffer *p_packet; // esi

  p_m_ResponsePackets = &this->m_ResponsePackets;
  v6 = CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AddToTail(this: &this->m_ResponsePackets);
  p_m_ResponsePackets->m_Memory.m_pMemory[v6].m_Element.responderID = listenerID;
  p_packet = &p_m_ResponsePackets->m_Memory.m_pMemory[v6].m_Element.packet;
  if ( (p_packet->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: p_packet, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: p_packet, src: 0);
  if ( (p_packet->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: p_packet, pFmt: "%d", type);
  else
    CUtlBuffer::PutTypeBin<int>(this: p_packet, src: type);
  if ( (p_packet->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: p_packet, pFmt: "%d", nDataLen);
  else
    CUtlBuffer::PutTypeBin<int>(this: p_packet, src: nDataLen);
  CUtlBuffer::Put(this: p_packet, pMem: pData, size: nDataLen);
}

//------------------------------------------------------------------------------
// Address: 0x1012E590
// Name: public: void CServerRemoteAccess::SendVProfData(unsigned int,bool,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::SendVProfData(
        CServerRemoteAccess *this,
        unsigned int listenerID,
        bool bGroupData,
        void *data,
        int len)
{
  CServerRemoteAccess::SendResponseToClient(
    this,
    listenerID,
    type: (ServerDataResponseType_t)(bGroupData + 3),
    pData: data,
    nDataLen: len);
}

//------------------------------------------------------------------------------
// Address: 0x1012E5C0
// Name: _NotifyDedicatedServerUI
// Source: json
//------------------------------------------------------------------------------
void __cdecl NotifyDedicatedServerUI(const char *message)
{
  if ( g_ServerRemoteAccess.m_AdminUIID != -1 )
    CServerRemoteAccess::SendMessageToAdminUI(
      this: &g_ServerRemoteAccess,
      listenerID: g_ServerRemoteAccess.m_AdminUIID,
      message);
}

//------------------------------------------------------------------------------
// Address: 0x1012E5E0
// Name: public: virtual CServerRemoteAccess::~CServerRemoteAccess(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::~CServerRemoteAccess(CServerRemoteAccess *this)
{
  CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::RemoveAll(this: &this->m_ListenerIDs);
  if ( this->m_ListenerIDs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ListenerIDs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ListenerIDs.m_Memory.m_pMemory);
      this->m_ListenerIDs.m_Memory.m_pMemory = nullptr;
    }
    this->m_ListenerIDs.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::RemoveAll(this: &this->m_ResponsePackets);
  if ( this->m_ResponsePackets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ResponsePackets.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ResponsePackets.m_Memory.m_pMemory);
      this->m_ResponsePackets.m_Memory.m_pMemory = nullptr;
    }
    this->m_ResponsePackets.m_Memory.m_nAllocationCount = 0;
  }
  this->__vftable = (CServerRemoteAccess_vtbl *)&IBaseInterface::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1012E660
// Name: public: virtual void CServerRemoteAccess::RegisterAdminUIID(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::RegisterAdminUIID(CServerRemoteAccess *this, unsigned int listener)
{
  this->m_AdminUIID = listener;
}

//------------------------------------------------------------------------------
// Address: 0x1012E6A0
// Name: public: void CServerRemoteAccess::UploadScreenshot(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::UploadScreenshot(CServerRemoteAccess *this, const char *pFileName)
{
  HZIP__ *ZipZ; // edi
  bool v4; // sf
  CUtlBuffer buf; // [esp+4h] [ebp-34h] BYREF
  void *pMem; // [esp+34h] [ebp-4h] BYREF

  if ( this->m_nScreenshotListener >= 0 )
  {
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0x20000, initSize: 0, nFlags: 0);
    if ( g_pFullFileSystem->ReadFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pFileName,
           a3: "MOD",
           a4: &buf,
           a5: 0,
           a6: 0,
           a7: nullptr) )
    {
      ZipZ = CreateZipZ(z: nullptr, len: 0x100000u, flags: 3u);
      ZipAdd(hz: ZipZ, dstzn: "screenshot.jpg", src: buf.m_Memory.m_pMemory, len: buf.m_nMaxPut, flags: 3u);
      ZipGetMemory(hz: ZipZ, buf: &pMem, len: (unsigned int *)&pFileName);
      CServerRemoteAccess::SendResponseToClient(
        this,
        listenerID: this->m_nScreenshotListener,
        type: SERVERDATA_SCREENSHOT_RESPONSE,
        pData: pMem,
        nDataLen: (int)pFileName);
      CloseZipZ(hz: ZipZ);
    }
    else
    {
      CServerRemoteAccess::LogCommand(this, listener: this->m_nScreenshotListener, msg: "Failed to read screenshot!\n");
      CServerRemoteAccess::RespondString(
        this,
        listener: this->m_nScreenshotListener,
        requestID: 0,
        pString: "Failed to read screenshot!\n");
    }
    v4 = buf.m_Memory.m_nGrowSize < 0;
    this->m_nScreenshotListener = -1;
    if ( !v4 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012E7A0
// Name: private: void CServerRemoteAccess::CheckPassword(class CRConServer __near *,unsigned int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::CheckPassword(
        CServerRemoteAccess *this,
        CRConServer *pNetworkListener,
        unsigned int listener,
        int requestID,
        const char *password)
{
  int v6; // eax
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v7; // esi

  if ( CRConServer::IsPassword(this: pNetworkListener, pPassword: password) )
  {
    v6 = CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AddToTail(this: &this->m_ResponsePackets);
    this->m_ResponsePackets.m_Memory.m_pMemory[v6].m_Element.responderID = listener;
    v7 = &this->m_ResponsePackets.m_Memory.m_pMemory[v6];
    if ( (v7->m_Element.packet.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &v7->m_Element.packet, pFmt: "%d", requestID);
    else
      CUtlBuffer::PutTypeBin<int>(this: &v7->m_Element.packet, src: requestID);
    if ( (v7->m_Element.packet.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &v7->m_Element.packet, pFmt: "%d", 2);
    else
      CUtlBuffer::PutTypeBin<int>(this: &v7->m_Element.packet, src: 2);
    CUtlBuffer::PutString(this: &v7->m_Element.packet, pString: defaultValue);
    CUtlBuffer::PutString(this: &v7->m_Element.packet, pString: defaultValue);
    this->m_ListenerIDs.m_Memory.m_pMemory[listener].m_Element.authenticated = true;
  }
  else
  {
    CServerRemoteAccess::BadPassword(this, pNetworkListener, listener);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012E870
// Name: public: virtual int CServerRemoteAccess::ReadDataResponse(unsigned int,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CServerRemoteAccess::ReadDataResponse(
        CServerRemoteAccess *this,
        int listener,
        unsigned __int8 *buffer,
        int bufferSize)
{
  CServerRemoteAccess *v4; // edx
  int m_Head; // esi
  CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int> > *p_m_ResponsePackets; // ebx
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *m_pMemory; // ecx
  int v8; // eax
  signed int m_Put; // edi
  int v10; // edi
  int bytesToCopy; // [esp+1Ch] [ebp+8h]

  v4 = this;
  m_Head = this->m_ResponsePackets.m_Head;
  p_m_ResponsePackets = &this->m_ResponsePackets;
  while ( 1 )
  {
    if ( m_Head < 0 )
      return 0;
    if ( m_Head >= p_m_ResponsePackets->m_Memory.m_nAllocationCount )
      return 0;
    if ( m_Head > p_m_ResponsePackets->m_LastAlloc.index )
      return 0;
    m_pMemory = p_m_ResponsePackets->m_Memory.m_pMemory;
    v8 = m_Head;
    if ( p_m_ResponsePackets->m_Memory.m_pMemory[m_Head].m_Previous == m_Head && m_pMemory[v8].m_Next != m_Head )
      return 0;
    if ( m_pMemory[v8].m_Element.responderID == listener )
      break;
    m_Head = m_pMemory[v8].m_Next;
  }
  m_Put = m_pMemory[m_Head].m_Element.packet.m_Put;
  bytesToCopy = m_Put;
  if ( m_Put > bufferSize )
  {
    bytesToCopy = 0;
    m_Put = 0;
  }
  else
  {
    memcpy(dst: buffer, src: m_pMemory[m_Head].m_Element.packet.m_Memory.m_pMemory, count: m_Put);
    v4 = this;
  }
  v4->m_iBytesSent += m_Put;
  CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::Unlink(
    this: p_m_ResponsePackets,
    elem: m_Head);
  v10 = (int)&p_m_ResponsePackets->m_Memory.m_pMemory[m_Head];
  if ( *(int *)(v10 + 8) >= 0 )
  {
    if ( *(_DWORD *)v10 != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v10);
      *(_DWORD *)v10 = 0;
    }
    *(_DWORD *)(v10 + 4) = 0;
  }
  *(_DWORD *)(v10 + 56) = p_m_ResponsePackets->m_FirstFree;
  p_m_ResponsePackets->m_FirstFree = m_Head;
  return bytesToCopy;
}

//------------------------------------------------------------------------------
// Address: 0x1012E960
// Name: public: void CServerRemoteAccess::WriteDataRequest(class CRConServer __near *,unsigned int,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::WriteDataRequest(
        CServerRemoteAccess *this,
        CRConServer *pNetworkListener,
        void *listener,
        const void *buffer,
        const char *bufferSize)
{
  unsigned int v5; // eax
  unsigned int v7; // esi
  int Int; // ebx
  char *v9; // ecx
  bool StringHelper; // al
  unsigned __int8 *m_pMemory; // eax
  const char *v12; // eax
  int v13; // ebx
  const char *v14; // eax
  HZIP__ *ZipZ; // ebx
  int v16; // eax
  int v17; // [esp-Ch] [ebp-370h]
  char password[512]; // [esp+4h] [ebp-360h] BYREF
  char value[256]; // [esp+204h] [ebp-160h] BYREF
  CUtlBuffer buf; // [esp+304h] [ebp-60h] BYREF
  CUtlBuffer cmd; // [esp+334h] [ebp-30h] BYREF

  v5 = (unsigned int)bufferSize;
  this->m_iBytesReceived += (int)bufferSize;
  if ( v5 < 8 )
    return;
  CUtlBuffer::CUtlBuffer(this: &cmd, pBuffer: buffer, nSize: v5, nFlags: 8);
  v7 = (unsigned int)listener;
  while ( 2 )
  {
    if ( cmd.m_Get >= cmd.m_Memory.m_nAllocationCount - 8 )
      goto LABEL_10;
    Int = CUtlBuffer::GetInt(this: &cmd);
    CRConServer::SetRequestID(this: pNetworkListener, listener: v7, iRequestID: Int);
    switch ( CUtlBuffer::GetInt(this: &cmd) )
    {
      case 0:
        if ( this->m_ListenerIDs.m_Memory.m_pMemory[v7].m_Element.authenticated )
        {
          if ( !GetStringHelper(&cmd, outBuf: value, bufSize: 256) )
            goto LABEL_10;
          CServerRemoteAccess::RequestValue(this, listener: v7, requestID: Int, variable: value);
          v17 = 256;
          v9 = value;
          goto LABEL_8;
        }
        if ( !GetStringHelper(&cmd, outBuf: value, bufSize: 256) )
          goto LABEL_10;
        StringHelper = GetStringHelper(&cmd, outBuf: value, bufSize: 256);
        goto LABEL_9;
      case 1:
        if ( !this->m_ListenerIDs.m_Memory.m_pMemory[v7].m_Element.authenticated )
        {
          if ( !GetStringHelper(&cmd, outBuf: password, bufSize: 512) )
            goto LABEL_10;
          StringHelper = GetStringHelper(&cmd, outBuf: password, bufSize: 512);
          goto LABEL_9;
        }
        if ( !GetStringHelper(&cmd, outBuf: &password[256], bufSize: 256)
          || !GetStringHelper(&cmd, outBuf: value, bufSize: 256) )
        {
          goto LABEL_10;
        }
        CServerRemoteAccess::SetValue(this, variable: &password[256], value);
        continue;
      case 2:
        if ( this->m_ListenerIDs.m_Memory.m_pMemory[v7].m_Element.authenticated )
        {
          if ( !GetStringHelper(&cmd, outBuf: password, bufSize: 512) )
            goto LABEL_10;
          CServerRemoteAccess::ExecCommand(this, cmdString: password);
          if ( v7 != this->m_AdminUIID )
          {
            v12 = va(format: "command \"%s\"", password);
            CServerRemoteAccess::LogCommand(this, listener: v7, msg: v12);
          }
          v17 = 512;
          v9 = password;
LABEL_8:
          StringHelper = GetStringHelper(&cmd, outBuf: v9, bufSize: v17);
LABEL_9:
          if ( !StringHelper )
            goto LABEL_10;
        }
        else
        {
          if ( !GetStringHelper(&cmd, outBuf: password, bufSize: 512)
            || !GetStringHelper(&cmd, outBuf: password, bufSize: 512) )
          {
            goto LABEL_10;
          }
          CServerRemoteAccess::LogCommand(this, listener: v7, msg: "Bad Password");
        }
        continue;
      case 3:
        if ( !GetStringHelper(&cmd, outBuf: password, bufSize: 512) )
          goto LABEL_10;
        CServerRemoteAccess::CheckPassword(this, pNetworkListener, listener: v7, requestID: Int, password);
        if ( !GetStringHelper(&cmd, outBuf: password, bufSize: 512) )
          goto LABEL_10;
        if ( this->m_ListenerIDs.m_Memory.m_pMemory[v7].m_Element.authenticated )
        {
          v13 = atoi(nptr: password);
          if ( g_pCVar->FindCommand_2(this: g_pCVar, a2: "mp_disable_autokick") != nullptr )
          {
            v14 = va(format: "mp_disable_autokick %d\n", v13);
            Cbuf_AddText(eTarget: CBUF_SERVER, pText: v14, nTickDelay: 0);
            Cbuf_Execute();
          }
        }
        continue;
      case 4:
        if ( !GetStringHelper(&cmd, outBuf: (char *)&buf.m_Error, bufSize: 25)
          || !GetStringHelper(&cmd, outBuf: (char *)&buf.m_Error, bufSize: 25) )
        {
          goto LABEL_10;
        }
        if ( this->m_ListenerIDs.m_Memory.m_pMemory[v7].m_Element.authenticated )
        {
          RegisterVProfDataListener(listenerID: v7);
          CServerRemoteAccess::LogCommand(this, listener: v7, msg: "Remote VProf started!\n");
          CServerRemoteAccess::RespondString(this, listener: v7, requestID: Int, pString: "Remote VProf started!\n");
        }
        continue;
      case 5:
        if ( !GetStringHelper(&cmd, outBuf: (char *)&buf.m_Error, bufSize: 25)
          || !GetStringHelper(&cmd, outBuf: (char *)&buf.m_Error, bufSize: 25) )
        {
          goto LABEL_10;
        }
        if ( this->m_ListenerIDs.m_Memory.m_pMemory[v7].m_Element.authenticated )
        {
          RemoveVProfDataListener(listenerID: v7);
          CServerRemoteAccess::LogCommand(this, listener: v7, msg: "Remote VProf finished!\n");
          CServerRemoteAccess::RespondString(this, listener: v7, requestID: Int, pString: "Remote VProf finished!\n");
        }
        continue;
      case 6:
        this->m_nScreenshotListener = v7;
        CL_TakeJpeg(name: nullptr, quality: 50);
        continue;
      case 7:
        bufferSize = GetConsoleLogFilename();
        CUtlBuffer::CUtlBuffer(this: &buf, growSize: 1024, initSize: 0, nFlags: 1);
        if ( g_pFullFileSystem->ReadFile(
               this: &g_pFullFileSystem->IBaseFileSystem,
               a2: bufferSize,
               a3: "GAME",
               a4: &buf,
               a5: 0,
               a6: 0,
               a7: nullptr) )
        {
          ZipZ = CreateZipZ(z: nullptr, len: 0x100000u, flags: 3u);
          ZipAdd(hz: ZipZ, dstzn: "console.log", src: buf.m_Memory.m_pMemory, len: buf.m_nMaxPut, flags: 3u);
          ZipGetMemory(hz: ZipZ, buf: &listener, len: (unsigned int *)&buffer);
          CServerRemoteAccess::SendResponseToClient(
            this,
            listenerID: v7,
            type: SERVERDATA_CONSOLE_LOG_RESPONSE,
            pData: listener,
            nDataLen: (int)buffer);
          CloseZipZ(hz: ZipZ);
        }
        else
        {
          CServerRemoteAccess::LogCommand(this, listener: v7, msg: "Failed to read console log!\n");
          CServerRemoteAccess::RespondString(
            this,
            listener: v7,
            requestID: Int,
            pString: "Failed to read console log!\n");
        }
        if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        continue;
      case 8:
        v16 = _CommandLine();
        if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v16 + 12))(a1: v16, a2: "-remotebug", a3: 0) != 0 )
        {
          if ( this->m_ListenerIDs.m_Memory.m_pMemory[v7].m_Element.authenticated )
          {
            CServerRemoteAccess::ExecCommand(this, cmdString: "bug -auto");
            CServerRemoteAccess::LogCommand(this, listener: v7, msg: "Remote bug submission\n");
            this->m_nBugListener = v7;
          }
          continue;
        }
        _Warning(a1: "Received a remote bug request from rcon client, but not running with '-remotebug'. Ignoring.\n");
        CServerRemoteAccess::RespondString(
          this,
          listener: v7,
          requestID: 0,
          pString: "Remote machine using wrong bugreporter dll. Try running with '-remotebug'\n");
LABEL_10:
        m_pMemory = cmd.m_Memory.m_pMemory;
LABEL_11:
        if ( cmd.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        return;
      default:
        memset(&cmd.m_Get, 0, 9);
        cmd.m_nOffset = 0;
        cmd.m_nMaxPut = 0;
        if ( cmd.m_Memory.m_nGrowSize < 0 )
          return;
        m_pMemory = cmd.m_Memory.m_pMemory;
        if ( cmd.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cmd.m_Memory.m_pMemory);
          m_pMemory = nullptr;
          cmd.m_Memory.m_pMemory = nullptr;
        }
        cmd.m_Memory.m_nAllocationCount = 0;
        goto LABEL_11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012EF30
// Name: public: virtual void CServerRemoteAccess::WriteDataRequest(unsigned int,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::WriteDataRequest(
        CServerRemoteAccess *this,
        unsigned int listener,
        const void *buffer,
        int bufferSize)
{
  CRConServer *v5; // eax

  v5 = RCONServer();
  CServerRemoteAccess::WriteDataRequest(this, pNetworkListener: v5, listener, buffer, bufferSize);
}

//------------------------------------------------------------------------------
// Address: 0x10313B60
// Name: _dynamic_initializer_for__remote_bug_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__remote_bug_command__()
{
  ConCommand::ConCommand(
    this: &remote_bug_command,
    pName: "remote_bug",
    callback: remote_bug,
    pHelpString: "Starts a bug report with data from the currently connected rcon machine",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__remote_bug_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10322940
// Name: _dynamic_atexit_destructor_for__remote_bug_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__remote_bug_command__()
{
  ConCommand::~ConCommand(this: &remote_bug_command);
}

//------------------------------------------------------------------------------
// Address: 0x10313B90
// Name: _dynamic_initializer_for__g_SplitScreenMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SplitScreenMgr__()
{
  GenericThreadLocals::CThreadLocalBase::CThreadLocalBase(this: &g_SplitScreenMgr.m_SplitSlot);
  g_SplitScreenMgr.m_bInitialized = false;
  return atexit(func: dynamic_atexit_destructor_for__g_SplitScreenMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x10322950
// Name: _dynamic_atexit_destructor_for__g_RCONClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RCONClient__()
{
  CRConClient::~CRConClient(this: &g_RCONClient);
}

//------------------------------------------------------------------------------
// Address: 0x10322960
// Name: _dynamic_atexit_destructor_for__g_RPTClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RPTClient__()
{
  CRConClient::~CRConClient(this: &g_RPTClient);
}

//------------------------------------------------------------------------------
// Address: 0x10322970
// Name: _dynamic_atexit_destructor_for__g_SplitScreenMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SplitScreenMgr__()
{
  GenericThreadLocals::CThreadLocalBase::~CThreadLocalBase(this: &g_SplitScreenMgr.m_SplitSlot);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1012CFC0
// Name: private: void CServerRemoteAccess::ExecCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::ExecCommand(CServerRemoteAccess *this, const char *cmdString)
{
  Cbuf_AddText(eTarget: CBUF_SERVER, pText: cmdString, nTickDelay: 0);
  Cbuf_AddText(eTarget: CBUF_SERVER, pText: "\n", nTickDelay: 0);
  Cbuf_Execute();
}

//------------------------------------------------------------------------------
// Address: 0x1012D160
// Name: private: char const __near * CServerRemoteAccess::LookupStringValue(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CServerRemoteAccess::LookupStringValue(CServerRemoteAccess *this, const char *variable)
{
  ConVar *v2; // eax
  IConVar *v3; // eax
  int NumClients; // esi
  int NumProxies; // eax
  int MaxClients; // eax
  ConVarRef var; // [esp+4h] [ebp-8h] BYREF

  v2 = g_pCVar->FindVar_2(this: g_pCVar, a2: variable);
  if ( v2 != nullptr )
  {
    v3 = &v2->IConVar;
    if ( v3 != nullptr )
    {
      ConVarRef::ConVarRef(this: &var, pConVar: v3);
      if ( ConVarRef::IsValid(this: &var) )
        return var.m_pConVarState->m_Value.m_pszString;
    }
  }
  if ( _V_stricmp(s1: variable, s2: "map") == 0 )
    return sv.m_szMapname;
  if ( _V_stricmp(s1: variable, s2: "playercount") != 0 )
  {
    if ( _V_stricmp(s1: variable, s2: "maxplayers") != 0 )
    {
      if ( _V_stricmp(s1: variable, s2: "gamedescription") != 0 || serverGameDLL == nullptr )
        return nullptr;
      else
        return serverGameDLL->GetGameDescription(this: serverGameDLL);
    }
    else
    {
      MaxClients = CBaseServer::GetMaxClients(this: &sv);
      V_snprintf(pDest: s_ReturnBuf, maxLen: 31, pFormat: "%d", MaxClients);
      return s_ReturnBuf;
    }
  }
  else
  {
    NumClients = CBaseServer::GetNumClients(this: &sv);
    NumProxies = CBaseServer::GetNumProxies(this: &sv);
    V_snprintf(pDest: s_ReturnBuf, maxLen: 31, pFormat: "%d", NumClients - NumProxies);
    return s_ReturnBuf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D340
// Name: void Host_Stats_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Host_Stats_f()
{
  char stats[512]; // [esp+0h] [ebp-200h] BYREF

  CServerRemoteAccess::GetStatsString(this: &g_ServerRemoteAccess, buf: stats, bufSize: 512);
  ConMsg(a1: "CPU   In    Out   Uptime  Users   FPS    Players\n%s\n", stats);
}

//------------------------------------------------------------------------------
// Address: 0x1012D380
// Name: private: void CServerRemoteAccess::LogCommand(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::LogCommand(CServerRemoteAccess *this, unsigned int listener, const char *msg)
{
  const char *v4; // eax

  if ( sv_rcon_log.m_pParent != nullptr && sv_rcon_log.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( listener < this->m_ListenerIDs.m_ElementCount
      && this->m_ListenerIDs.m_Memory.m_pMemory[listener].m_Element.m_bHasAddress )
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SERVER_LOG, a2: 0) != 0 )
      {
        v4 = netadr_s::ToString(this: &this->m_ListenerIDs.m_Memory.m_pMemory[listener].m_Element.adr, baseOnly: false);
        _LoggingSystem_Log(a1: LOG_SERVER_LOG, a2: 0, a3: "rcon from \"%s\": %s\n", v4, msg);
      }
    }
    else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SERVER_LOG, a2: 0) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_SERVER_LOG, a2: 0, a3: "rcon from \"unknown\": %s\n", msg);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012D6A0
// Name: bool GetStringHelper(class CUtlBuffer __near &,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetStringHelper(CUtlBuffer *cmd, char *outBuf, int bufSize)
{
  *outBuf = 0;
  CUtlBuffer::GetString(this: cmd, pString: outBuf, nMaxChars: bufSize);
  if ( cmd->m_Error == 0 )
    return 1;
  cmd->m_Get = 0;
  cmd->m_Put = 0;
  cmd->m_nOffset = 0;
  cmd->m_nMaxPut = 0;
  cmd->m_Error = 0;
  if ( cmd->m_Memory.m_nGrowSize >= 0 )
  {
    if ( cmd->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cmd->m_Memory.m_pMemory);
      cmd->m_Memory.m_pMemory = nullptr;
    }
    cmd->m_Memory.m_nAllocationCount = 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012D700
// Name: public: int CServerRemoteAccess::GetDataResponseSize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CServerRemoteAccess::GetDataResponseSize(CServerRemoteAccess *this, unsigned int listener)
{
  int i; // eax
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *m_pMemory; // edi
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v4; // edx

  for ( i = this->m_ResponsePackets.m_Head; i >= 0; i = v4->m_Next )
  {
    if ( i >= this->m_ResponsePackets.m_Memory.m_nAllocationCount )
      break;
    if ( i > this->m_ResponsePackets.m_LastAlloc.index )
      break;
    m_pMemory = this->m_ResponsePackets.m_Memory.m_pMemory;
    v4 = &m_pMemory[i];
    if ( v4->m_Previous == i && v4->m_Next != i )
      break;
    if ( v4->m_Element.responderID == listener )
      return m_pMemory[i].m_Element.packet.m_Put;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012D8E0
// Name: private: void CServerRemoteAccess::GetUserBanList(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::GetUserBanList(CServerRemoteAccess *this, CUtlBuffer *value)
{
  int v2; // eax
  int v3; // ebx
  int v4; // edi
  char *UserIDString; // eax
  int v6; // edi
  int v7; // ebx
  unsigned __int8 m_Flags; // cl
  int m_Put; // eax
  int v10; // eax
  int i; // edi
  double banTime; // [esp+0h] [ebp-14h]

  v2 = 0;
  if ( g_UserFilters.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      banTime = g_UserFilters.m_Memory.m_pMemory[v3].banTime;
      v4 = v2 + 1;
      UserIDString = GetUserIDString(id: &g_UserFilters.m_Memory.m_pMemory[v3].userid);
      CUtlBuffer::Printf(this: value, pFmt: "%i %s : %.3f min\n", v4, UserIDString, banTime);
      v2 = v4;
      ++v3;
    }
    while ( v4 < g_UserFilters.m_Size );
  }
  v6 = 0;
  if ( g_IPFilters.m_Size > 0 )
  {
    v7 = 0;
    do
    {
      CUtlBuffer::Printf(
        this: value,
        pFmt: "%i %i.%i.%i.%i : %.3f min\n",
        g_UserFilters.m_Size + v6++ + 1,
        (unsigned __int8)g_IPFilters.m_Memory.m_pMemory[v7].compare,
        BYTE1(g_IPFilters.m_Memory.m_pMemory[v7].compare),
        (unsigned __int8)BYTE2(g_IPFilters.m_Memory.m_pMemory[v7].compare),
        HIBYTE(g_IPFilters.m_Memory.m_pMemory[v7].compare),
        g_IPFilters.m_Memory.m_pMemory[v7].banTime);
      ++v7;
    }
    while ( v6 < g_IPFilters.m_Size );
  }
  m_Flags = value->m_Flags;
  if ( (m_Flags & 1) != 0 )
  {
    m_Put = value->m_Put;
    if ( m_Put != 0 && value->m_Memory.m_pMemory[m_Put - value->m_nOffset - 1] == 10 )
    {
      v10 = (m_Flags & 0x10) != 0 ? 0 : value->m_nTab;
      for ( i = v10 - 1; i >= 0; --i )
      {
        if ( CUtlBuffer::CheckPut(this: value, nSize: 1) )
        {
          value->m_Memory.m_pMemory[value->m_Put - value->m_nOffset] = 9;
          CUtlBuffer::AddNullTermination(this: value, nPut: ++value->m_Put);
        }
      }
    }
  }
  if ( CUtlBuffer::CheckPut(this: value, nSize: 1) )
  {
    value->m_Memory.m_pMemory[value->m_Put - value->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: value, nPut: ++value->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012DA40
// Name: private: void CServerRemoteAccess::GetPlayerList(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::GetPlayerList(CServerRemoteAccess *this, CUtlBuffer *value)
{
  int v2; // ebx
  CBaseClient *v3; // edi
  IClient *v4; // esi
  CPlayerState *v5; // edi
  bool v6; // al
  IClient_vtbl *v7; // edx
  int v8; // eax
  const char *v9; // eax
  int v10; // edi
  int v11; // ebx
  double v12; // st7
  double v13; // st7
  double v14; // st7
  int v15; // eax
  int v16; // eax
  const char *v17; // eax
  int m_Put; // eax
  const char *v19; // [esp-24h] [ebp-34h]
  const char *v20; // [esp-20h] [ebp-30h]
  int v21; // [esp-1Ch] [ebp-2Ch]
  int v22; // [esp-18h] [ebp-28h]
  const char *v23; // [esp-14h] [ebp-24h]
  int v24; // [esp-14h] [ebp-24h]
  int v25; // [esp-10h] [ebp-20h]
  int v26; // [esp-10h] [ebp-20h]
  int v27; // [esp+0h] [ebp-10h]
  int v28; // [esp+4h] [ebp-Ch]
  CPlayerState *pl; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( serverGameClients != nullptr )
  {
    v2 = 0;
    for ( i = 0; v2 < sv.m_Clients.m_Size; i = v2 )
    {
      v3 = sv.m_Clients.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        v4 = &v3->IClient;
        if ( v3->IsActive(this: &v3->IClient) )
        {
          v5 = serverGameClients->GetPlayerState(this: serverGameClients, a2: *(_DWORD *)v3[1].m_GUID);
          pl = v5;
          if ( v5 != nullptr )
          {
            v6 = v4->IsFakeClient(this: v4);
            v7 = v4->__vftable;
            if ( v6 )
            {
              v8 = ((int (__thiscall *)(IClient *, int))v7->GetNetworkIDString)(a1: v4, a2: v5->frags);
              v9 = (const char *)((int (__thiscall *)(IClient *, int))v4->GetClientName)(a1: v4, a2: v8);
              CUtlBuffer::Printf(this: value, pFmt: "\"%s\" %s 0 0 0 %d 0\n", v9, v23, v25);
            }
            else
            {
              v10 = (int)v7->GetNetChannel(this: v4);
              v11 = (int)v4->GetNetChannel(this: v4);
              v28 = (int)v4->GetNetChannel(this: v4);
              v27 = (int)v4->GetNetChannel(this: v4);
              v12 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v10 + 12))(a1: v10);
              v13 = ((double (__thiscall *)(int, int, int, int))*(_DWORD *)(*(_DWORD *)v11 + 44))(
                      a1: v11,
                      a2: 1,
                      a3: pl->frags,
                      a4: (int)v12);
              v14 = ((double (__thiscall *)(int, _DWORD, int))*(_DWORD *)(*(_DWORD *)v28 + 40))(
                      a1: v28,
                      a2: 0,
                      a3: (int)v13)
                  * 1000.0;
              v15 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v27 + 4))(a1: v27, a2: (int)v14);
              v16 = ((int (__thiscall *)(IClient *, int))v4->GetNetworkIDString)(a1: v4, a2: v15);
              v17 = (const char *)((int (__thiscall *)(IClient *, int))v4->GetClientName)(a1: v4, a2: v16);
              CUtlBuffer::Printf(this: value, pFmt: "\"%s\" %s %s %d %d %d %d\n", v17, v19, v20, v21, v22, v24, v26);
              v2 = i;
            }
          }
        }
      }
      ++v2;
    }
    if ( (value->m_Flags & 1) != 0 )
    {
      m_Put = value->m_Put;
      if ( m_Put != 0 && value->m_Memory.m_pMemory[m_Put - value->m_nOffset - 1] == 10 )
        CUtlBuffer::PutTabs(this: value);
    }
    if ( CUtlBuffer::CheckPut(this: value, nSize: 1) )
    {
      value->m_Memory.m_pMemory[value->m_Put - value->m_nOffset] = 0;
      CUtlBuffer::AddNullTermination(this: value, nPut: ++value->m_Put);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012DC00
// Name: private: void CServerRemoteAccess::GetMapList(class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::GetMapList(CServerRemoteAccess *this, CUtlBuffer *value)
{
  const char *i; // esi
  int v3; // eax
  _BYTE *v4; // eax
  int m_Put; // eax
  char mapName[260]; // [esp+8h] [ebp-36Ch] BYREF
  char friendly_com_gamedir[260]; // [esp+10Ch] [ebp-268h] BYREF
  char curDir[260]; // [esp+210h] [ebp-164h] BYREF
  char mapwild[96]; // [esp+314h] [ebp-60h] BYREF

  strcpy(mapwild, "maps/*.bsp");
  V_strncpy(pDest: friendly_com_gamedir, pSrc: com_gamedir, maxLen: 260);
  _V_strlower(start: friendly_com_gamedir);
  for ( i = Sys_FindFirst(path: mapwild, basename: nullptr, namelength: 0);
        i != nullptr;
        i = Sys_FindNext(basename: nullptr, namelength: 0) )
  {
    _snprintf(string: curDir, count: 0x104u, format: "maps/%s", i);
    g_pFileSystem->GetLocalPath(this: g_pFileSystem, a2: curDir, a3: curDir, a4: 260);
    strstr(str1: (unsigned __int8 *)curDir, str2: (unsigned __int8 *)friendly_com_gamedir);
    if ( v3 != 0 )
    {
      strcpy(mapName, i);
      strstr(str1: (unsigned __int8 *)mapName, str2: ".bsp");
      if ( v4 != nullptr )
        *v4 = 0;
      CUtlBuffer::PutString(this: value, pString: mapName);
      CUtlBuffer::PutString(this: value, pString: "\n");
    }
  }
  Sys_FindClose();
  if ( (value->m_Flags & 1) != 0 )
  {
    m_Put = value->m_Put;
    if ( m_Put != 0 && value->m_Memory.m_pMemory[m_Put - value->m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: value);
  }
  if ( CUtlBuffer::CheckPut(this: value, nSize: 1) )
  {
    value->m_Memory.m_pMemory[value->m_Put - value->m_nOffset] = 0;
    CUtlBuffer::AddNullTermination(this: value, nPut: ++value->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012DD80
// Name: private: bool CServerRemoteAccess::LookupValue(char const __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerRemoteAccess::LookupValue(CServerRemoteAccess *this, const char *variable, CUtlBuffer *value)
{
  const char *v4; // eax
  int v6; // ecx
  double v7; // st7
  const char *v8; // eax
  void *v9; // edi
  int v10; // esi
  void *v11; // esp
  char *v12; // [esp-4h] [ebp-234h]
  int UDPPort; // [esp-4h] [ebp-234h]
  const char *v14; // [esp-4h] [ebp-234h]
  _BYTE v15[12]; // [esp+0h] [ebp-230h] BYREF
  char stats[512]; // [esp+Ch] [ebp-224h] BYREF
  char addr[28]; // [esp+20Ch] [ebp-24h] BYREF
  ConVarRef mapcycle; // [esp+228h] [ebp-8h] BYREF

  v4 = CServerRemoteAccess::LookupStringValue(this, variable);
  if ( v4 != nullptr )
  {
    v12 = (char *)v4;
LABEL_15:
    CUtlBuffer::PutString(this: value, pString: v12);
    CUtlBuffer::PutChar(this: value, c: 0);
    return 1;
  }
  if ( _V_stricmp(s1: variable, s2: "stats") == 0 )
  {
    CServerRemoteAccess::GetStatsString(this, buf: stats, bufSize: 512);
    CUtlBuffer::PutString(this: value, pString: stats);
    CUtlBuffer::PutChar(this: value, c: 0);
    return 1;
  }
  if ( _V_stricmp(s1: variable, s2: "banlist") == 0 )
  {
    CServerRemoteAccess::GetUserBanList(this, value);
    return 1;
  }
  if ( _V_stricmp(s1: variable, s2: "playerlist") == 0 )
  {
    CServerRemoteAccess::GetPlayerList(this, value);
    return 1;
  }
  if ( _V_stricmp(s1: variable, s2: "maplist") == 0 )
  {
    CServerRemoteAccess::GetMapList(this, value);
    return 1;
  }
  if ( _V_stricmp(s1: variable, s2: "uptime") == 0 )
  {
    v7 = _Plat_FloatTime(a1: v6);
    CUtlBuffer::PutInt(this: value, i: (int)v7);
    CUtlBuffer::PutChar(this: value, c: 0);
    return 1;
  }
  if ( _V_stricmp(s1: variable, s2: "ipaddress") == 0 )
  {
    UDPPort = NET_GetUDPPort(socket: sv.m_Socket);
    v8 = netadr_s::ToString(this: &net_local_adr, baseOnly: true);
    V_snprintf(pDest: addr, maxLen: 25, pFormat: "%s:%i", v8, UDPPort);
    v12 = addr;
    goto LABEL_15;
  }
  if ( _V_stricmp(s1: variable, s2: "mapcycle") != 0 )
  {
    CUtlBuffer::PutChar(this: value, c: 0);
    return 0;
  }
  else
  {
    ConVarRef::ConVarRef(this: &mapcycle, pName: "mapcyclefile");
    if ( ConVarRef::IsValid(this: &mapcycle) )
    {
      v9 = g_pFileSystem->Open(
             this: &g_pFileSystem->IBaseFileSystem,
             a2: mapcycle.m_pConVarState->m_Value.m_pszString,
             a3: "rb",
             a4: 0);
      if ( v9 != nullptr )
      {
        v10 = g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v9);
        v11 = alloca(v10 + 1);
        if ( v10 != 0 && g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v15, a3: v10, a4: v9) != 0 )
        {
          v15[v10] = 0;
          v14 = v15;
        }
        else
        {
          v14 = defaultValue;
        }
        CUtlBuffer::PutString(this: value, pString: v14);
        CUtlBuffer::PutChar(this: value, c: 0);
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v9);
      }
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012E1C0
// Name: public: virtual unsigned int CServerRemoteAccess::GetNextListenerID(bool,struct netadr_s const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CServerRemoteAccess::GetNextListenerID(
        CServerRemoteAccess *this,
        bool authConnection,
        const netadr_s *adr)
{
  CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int> > *p_m_ListenerIDs; // esi
  int result; // eax
  unsigned int v5; // ecx

  p_m_ListenerIDs = &this->m_ListenerIDs;
  result = CUtlLinkedList<CServerRemoteAccess::ListenerStore_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::ListenerStore_t,int>,int>>::AddToTail(this: &this->m_ListenerIDs);
  v5 = result;
  p_m_ListenerIDs->m_Memory.m_pMemory[v5].m_Element.listenerID = result;
  p_m_ListenerIDs->m_Memory.m_pMemory[v5].m_Element.authenticated = !authConnection;
  p_m_ListenerIDs->m_Memory.m_pMemory[v5].m_Element.m_bHasAddress = adr != nullptr;
  if ( adr != nullptr )
    p_m_ListenerIDs->m_Memory.m_pMemory[v5].m_Element.adr = *adr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012E220
// Name: public: void CServerRemoteAccess::RemoteBug(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::RemoteBug(CServerRemoteAccess *this, const char *pBugPath)
{
  int v3; // eax
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v4; // esi

  if ( this->m_nBugListener >= 0 )
  {
    v3 = CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AddToTail(this: &this->m_ResponsePackets);
    this->m_ResponsePackets.m_Memory.m_pMemory[v3].m_Element.responderID = this->m_nBugListener;
    v4 = &this->m_ResponsePackets.m_Memory.m_pMemory[v3];
    if ( (v4->m_Element.packet.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &v4->m_Element.packet, pFmt: "%d", 0);
    else
      CUtlBuffer::PutTypeBin<int>(this: &v4->m_Element.packet, src: 0);
    if ( (v4->m_Element.packet.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &v4->m_Element.packet, pFmt: "%d", 8);
    else
      CUtlBuffer::PutTypeBin<int>(this: &v4->m_Element.packet, src: 8);
    CUtlBuffer::PutString(this: &v4->m_Element.packet, pString: pBugPath);
    this->m_nBugListener = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012E370
// Name: private: void CServerRemoteAccess::RequestValue(unsigned int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::RequestValue(
        CServerRemoteAccess *this,
        unsigned int listener,
        int requestID,
        const char *variable)
{
  int v5; // ecx
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v6; // esi
  CUtlBuffer value; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &value, growSize: 0, initSize: 256, nFlags: 1);
  CServerRemoteAccess::LookupValue(this, variable, &value);
  v5 = CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AddToTail(this: &this->m_ResponsePackets);
  this->m_ResponsePackets.m_Memory.m_pMemory[v5].m_Element.responderID = listener;
  v6 = &this->m_ResponsePackets.m_Memory.m_pMemory[v5];
  if ( (v6->m_Element.packet.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &v6->m_Element.packet, pFmt: "%d", requestID);
  else
    CUtlBuffer::PutTypeBin<int>(this: &v6->m_Element.packet, src: requestID);
  if ( (v6->m_Element.packet.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &v6->m_Element.packet, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: &v6->m_Element.packet, src: 0);
  CUtlBuffer::PutString(this: &v6->m_Element.packet, pString: variable);
  if ( (v6->m_Element.packet.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &v6->m_Element.packet, pFmt: "%d", value.m_Put);
  else
    CUtlBuffer::PutTypeBin<int>(this: &v6->m_Element.packet, src: value.m_Put);
  if ( value.m_Put != 0 )
    CUtlBuffer::Put(this: &v6->m_Element.packet, pMem: value.m_Memory.m_pMemory, size: value.m_Put);
  if ( value.m_Memory.m_nGrowSize >= 0 && value.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: value.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1012E470
// Name: private: void CServerRemoteAccess::RespondString(unsigned int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::RespondString(
        CServerRemoteAccess *this,
        unsigned int listener,
        int requestID,
        const char *pString)
{
  CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int> > *p_m_ResponsePackets; // esi
  int v5; // ecx
  CUtlBuffer *p_packet; // esi

  p_m_ResponsePackets = &this->m_ResponsePackets;
  v5 = CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AddToTail(this: &this->m_ResponsePackets);
  p_m_ResponsePackets->m_Memory.m_pMemory[v5].m_Element.responderID = listener;
  p_packet = &p_m_ResponsePackets->m_Memory.m_pMemory[v5].m_Element.packet;
  if ( (p_packet->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: p_packet, pFmt: "%d", requestID);
  else
    CUtlBuffer::PutTypeBin<int>(this: p_packet, src: requestID);
  if ( (p_packet->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: p_packet, pFmt: "%d", 7);
  else
    CUtlBuffer::PutTypeBin<int>(this: p_packet, src: 7);
  CUtlBuffer::PutString(this: p_packet, pString);
}

//------------------------------------------------------------------------------
// Address: 0x1012E500
// Name: public: void CServerRemoteAccess::SendMessageToAdminUI(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::SendMessageToAdminUI(
        CServerRemoteAccess *this,
        unsigned int listenerID,
        const char *message)
{
  int v4; // eax
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v5; // esi

  if ( listenerID != this->m_AdminUIID )
    _Warning(a1: "ServerRemoteAccess: Sending AdminUI message to non-AdminUI listener\n");
  v4 = CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AddToTail(this: &this->m_ResponsePackets);
  this->m_ResponsePackets.m_Memory.m_pMemory[v4].m_Element.responderID = listenerID;
  v5 = &this->m_ResponsePackets.m_Memory.m_pMemory[v4];
  if ( (v5->m_Element.packet.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &v5->m_Element.packet, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: &v5->m_Element.packet, src: 0);
  if ( (v5->m_Element.packet.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &v5->m_Element.packet, pFmt: "%d", 1);
  else
    CUtlBuffer::PutTypeBin<int>(this: &v5->m_Element.packet, src: 1);
  CUtlBuffer::PutString(this: &v5->m_Element.packet, pString: message);
}

//------------------------------------------------------------------------------
// Address: 0x1012E5A0
// Name: private: void CServerRemoteAccess::SendResponseToClient(unsigned int,enum ServerDataResponseType_t,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::SendResponseToClient(
        CServerRemoteAccess *this,
        unsigned int listenerID,
        ServerDataResponseType_t type,
        void *pData,
        int nDataLen)
{
  CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int> > *p_m_ResponsePackets; // esi
  int v6; // ecx
  CUtlBuffer *p_packet; // esi

  p_m_ResponsePackets = &this->m_ResponsePackets;
  v6 = CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AddToTail(this: &this->m_ResponsePackets);
  p_m_ResponsePackets->m_Memory.m_pMemory[v6].m_Element.responderID = listenerID;
  p_packet = &p_m_ResponsePackets->m_Memory.m_pMemory[v6].m_Element.packet;
  if ( (p_packet->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: p_packet, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: p_packet, src: 0);
  if ( (p_packet->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: p_packet, pFmt: "%d", type);
  else
    CUtlBuffer::PutTypeBin<int>(this: p_packet, src: type);
  if ( (p_packet->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: p_packet, pFmt: "%d", nDataLen);
  else
    CUtlBuffer::PutTypeBin<int>(this: p_packet, src: nDataLen);
  CUtlBuffer::Put(this: p_packet, pMem: pData, size: nDataLen);
}

//------------------------------------------------------------------------------
// Address: 0x1012E650
// Name: public: void CServerRemoteAccess::SendVProfData(unsigned int,bool,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::SendVProfData(
        CServerRemoteAccess *this,
        unsigned int listenerID,
        bool bGroupData,
        void *data,
        int len)
{
  CServerRemoteAccess::SendResponseToClient(
    this,
    listenerID,
    type: (ServerDataResponseType_t)(bGroupData + 3),
    pData: data,
    nDataLen: len);
}

//------------------------------------------------------------------------------
// Address: 0x1012E680
// Name: _NotifyDedicatedServerUI
// Source: json
//------------------------------------------------------------------------------
void __cdecl NotifyDedicatedServerUI(const char *message)
{
  if ( g_ServerRemoteAccess.m_AdminUIID != -1 )
    CServerRemoteAccess::SendMessageToAdminUI(
      this: &g_ServerRemoteAccess,
      listenerID: g_ServerRemoteAccess.m_AdminUIID,
      message);
}

//------------------------------------------------------------------------------
// Address: 0x1012E720
// Name: public: virtual void CServerRemoteAccess::RegisterAdminUIID(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::RegisterAdminUIID(CServerRemoteAccess *this, unsigned int listener)
{
  this->m_AdminUIID = listener;
}

//------------------------------------------------------------------------------
// Address: 0x1012E760
// Name: public: void CServerRemoteAccess::UploadScreenshot(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::UploadScreenshot(CServerRemoteAccess *this, const char *pFileName)
{
  HZIP__ *ZipZ; // edi
  bool v4; // sf
  CUtlBuffer buf; // [esp+4h] [ebp-34h] BYREF
  void *pMem; // [esp+34h] [ebp-4h] BYREF

  if ( this->m_nScreenshotListener >= 0 )
  {
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0x20000, initSize: 0, nFlags: 0);
    if ( g_pFullFileSystem->ReadFile(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: pFileName,
           a3: "MOD",
           a4: &buf,
           a5: 0,
           a6: 0,
           a7: nullptr) )
    {
      ZipZ = CreateZipZ(z: nullptr, len: 0x100000u, flags: 3u);
      ZipAdd(hz: ZipZ, dstzn: "screenshot.jpg", src: buf.m_Memory.m_pMemory, len: buf.m_nMaxPut, flags: 3u);
      ZipGetMemory(hz: ZipZ, buf: &pMem, len: (unsigned int *)&pFileName);
      CServerRemoteAccess::SendResponseToClient(
        this,
        listenerID: this->m_nScreenshotListener,
        type: SERVERDATA_SCREENSHOT_RESPONSE,
        pData: pMem,
        nDataLen: (int)pFileName);
      CloseZipZ(hz: ZipZ);
    }
    else
    {
      CServerRemoteAccess::LogCommand(this, listener: this->m_nScreenshotListener, msg: "Failed to read screenshot!\n");
      CServerRemoteAccess::RespondString(
        this,
        listener: this->m_nScreenshotListener,
        requestID: 0,
        pString: "Failed to read screenshot!\n");
    }
    v4 = buf.m_Memory.m_nGrowSize < 0;
    this->m_nScreenshotListener = -1;
    if ( !v4 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012E860
// Name: private: void CServerRemoteAccess::CheckPassword(class CRConServer __near *,unsigned int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::CheckPassword(
        CServerRemoteAccess *this,
        CRConServer *pNetworkListener,
        unsigned int listener,
        int requestID,
        const char *password)
{
  int v6; // eax
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *v7; // esi

  if ( CRConServer::IsPassword(this: pNetworkListener, pPassword: password) )
  {
    v6 = CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::AddToTail(this: &this->m_ResponsePackets);
    this->m_ResponsePackets.m_Memory.m_pMemory[v6].m_Element.responderID = listener;
    v7 = &this->m_ResponsePackets.m_Memory.m_pMemory[v6];
    if ( (v7->m_Element.packet.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &v7->m_Element.packet, pFmt: "%d", requestID);
    else
      CUtlBuffer::PutTypeBin<int>(this: &v7->m_Element.packet, src: requestID);
    if ( (v7->m_Element.packet.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &v7->m_Element.packet, pFmt: "%d", 2);
    else
      CUtlBuffer::PutTypeBin<int>(this: &v7->m_Element.packet, src: 2);
    CUtlBuffer::PutString(this: &v7->m_Element.packet, pString: defaultValue);
    CUtlBuffer::PutString(this: &v7->m_Element.packet, pString: defaultValue);
    this->m_ListenerIDs.m_Memory.m_pMemory[listener].m_Element.authenticated = true;
  }
  else
  {
    CServerRemoteAccess::BadPassword(this, pNetworkListener, listener);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012E930
// Name: public: virtual int CServerRemoteAccess::ReadDataResponse(unsigned int,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CServerRemoteAccess::ReadDataResponse(
        CServerRemoteAccess *this,
        int listener,
        unsigned __int8 *buffer,
        int bufferSize)
{
  CServerRemoteAccess *v4; // edx
  int m_Head; // esi
  CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int> > *p_m_ResponsePackets; // ebx
  UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int> *m_pMemory; // ecx
  int v8; // eax
  signed int m_Put; // edi
  int v10; // edi
  int bytesToCopy; // [esp+1Ch] [ebp+8h]

  v4 = this;
  m_Head = this->m_ResponsePackets.m_Head;
  p_m_ResponsePackets = &this->m_ResponsePackets;
  while ( 1 )
  {
    if ( m_Head < 0 )
      return 0;
    if ( m_Head >= p_m_ResponsePackets->m_Memory.m_nAllocationCount )
      return 0;
    if ( m_Head > p_m_ResponsePackets->m_LastAlloc.index )
      return 0;
    m_pMemory = p_m_ResponsePackets->m_Memory.m_pMemory;
    v8 = m_Head;
    if ( p_m_ResponsePackets->m_Memory.m_pMemory[m_Head].m_Previous == m_Head && m_pMemory[v8].m_Next != m_Head )
      return 0;
    if ( m_pMemory[v8].m_Element.responderID == listener )
      break;
    m_Head = m_pMemory[v8].m_Next;
  }
  m_Put = m_pMemory[m_Head].m_Element.packet.m_Put;
  bytesToCopy = m_Put;
  if ( m_Put > bufferSize )
  {
    bytesToCopy = 0;
    m_Put = 0;
  }
  else
  {
    memcpy(dst: buffer, src: m_pMemory[m_Head].m_Element.packet.m_Memory.m_pMemory, count: m_Put);
    v4 = this;
  }
  v4->m_iBytesSent += m_Put;
  CUtlLinkedList<CServerRemoteAccess::DataResponse_t,int,0,int,CUtlMemory<UtlLinkedListElem_t<CServerRemoteAccess::DataResponse_t,int>,int>>::Unlink(
    this: p_m_ResponsePackets,
    elem: m_Head);
  v10 = (int)&p_m_ResponsePackets->m_Memory.m_pMemory[m_Head];
  if ( *(int *)(v10 + 8) >= 0 )
  {
    if ( *(_DWORD *)v10 != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v10);
      *(_DWORD *)v10 = 0;
    }
    *(_DWORD *)(v10 + 4) = 0;
  }
  *(_DWORD *)(v10 + 56) = p_m_ResponsePackets->m_FirstFree;
  p_m_ResponsePackets->m_FirstFree = m_Head;
  return bytesToCopy;
}

//------------------------------------------------------------------------------
// Address: 0x1012EA20
// Name: public: void CServerRemoteAccess::WriteDataRequest(class CRConServer __near *,unsigned int,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::WriteDataRequest(
        CServerRemoteAccess *this,
        CRConServer *pNetworkListener,
        void *listener,
        const void *buffer,
        char *bufferSize)
{
  unsigned int v5; // eax
  unsigned int v7; // esi
  int Int; // ebx
  char *v9; // ecx
  char StringHelper; // al
  unsigned __int8 *m_pMemory; // eax
  const char *v12; // eax
  int v13; // ebx
  const char *v14; // eax
  HZIP__ *ZipZ; // ebx
  int v16; // eax
  int v17; // [esp-Ch] [ebp-370h]
  char password[512]; // [esp+4h] [ebp-360h] BYREF
  char value[256]; // [esp+204h] [ebp-160h] BYREF
  CUtlBuffer buf; // [esp+304h] [ebp-60h] BYREF
  CUtlBuffer cmd; // [esp+334h] [ebp-30h] BYREF

  v5 = (unsigned int)bufferSize;
  this->m_iBytesReceived += (int)bufferSize;
  if ( v5 < 8 )
    return;
  CUtlBuffer::CUtlBuffer(this: &cmd, pBuffer: buffer, nSize: v5, nFlags: 8);
  v7 = (unsigned int)listener;
  while ( 2 )
  {
    if ( cmd.m_Get >= cmd.m_Memory.m_nAllocationCount - 8 )
      goto LABEL_10;
    Int = CUtlBuffer::GetInt(this: &cmd);
    CRConServer::SetRequestID(this: pNetworkListener, listener: v7, iRequestID: Int);
    switch ( CUtlBuffer::GetInt(this: &cmd) )
    {
      case 0:
        if ( this->m_ListenerIDs.m_Memory.m_pMemory[v7].m_Element.authenticated )
        {
          if ( GetStringHelper(&cmd, outBuf: value, bufSize: 256) == 0 )
            goto LABEL_10;
          CServerRemoteAccess::RequestValue(this, listener: v7, requestID: Int, variable: value);
          v17 = 256;
          v9 = value;
          goto LABEL_8;
        }
        if ( GetStringHelper(&cmd, outBuf: value, bufSize: 256) == 0 )
          goto LABEL_10;
        StringHelper = GetStringHelper(&cmd, outBuf: value, bufSize: 256);
        goto LABEL_9;
      case 1:
        if ( !this->m_ListenerIDs.m_Memory.m_pMemory[v7].m_Element.authenticated )
        {
          if ( GetStringHelper(&cmd, outBuf: password, bufSize: 512) == 0 )
            goto LABEL_10;
          StringHelper = GetStringHelper(&cmd, outBuf: password, bufSize: 512);
          goto LABEL_9;
        }
        if ( GetStringHelper(&cmd, outBuf: &password[256], bufSize: 256) == 0
          || GetStringHelper(&cmd, outBuf: value, bufSize: 256) == 0 )
        {
          goto LABEL_10;
        }
        CServerRemoteAccess::SetValue(this, variable: &password[256], value);
        continue;
      case 2:
        if ( this->m_ListenerIDs.m_Memory.m_pMemory[v7].m_Element.authenticated )
        {
          if ( GetStringHelper(&cmd, outBuf: password, bufSize: 512) == 0 )
            goto LABEL_10;
          CServerRemoteAccess::ExecCommand(this, cmdString: password);
          if ( v7 != this->m_AdminUIID )
          {
            v12 = va(format: "command \"%s\"", password);
            CServerRemoteAccess::LogCommand(this, listener: v7, msg: v12);
          }
          v17 = 512;
          v9 = password;
LABEL_8:
          StringHelper = GetStringHelper(&cmd, outBuf: v9, bufSize: v17);
LABEL_9:
          if ( StringHelper == 0 )
            goto LABEL_10;
        }
        else
        {
          if ( GetStringHelper(&cmd, outBuf: password, bufSize: 512) == 0
            || GetStringHelper(&cmd, outBuf: password, bufSize: 512) == 0 )
          {
            goto LABEL_10;
          }
          CServerRemoteAccess::LogCommand(this, listener: v7, msg: "Bad Password");
        }
        continue;
      case 3:
        if ( GetStringHelper(&cmd, outBuf: password, bufSize: 512) == 0 )
          goto LABEL_10;
        CServerRemoteAccess::CheckPassword(this, pNetworkListener, listener: v7, requestID: Int, password);
        if ( GetStringHelper(&cmd, outBuf: password, bufSize: 512) == 0 )
          goto LABEL_10;
        if ( this->m_ListenerIDs.m_Memory.m_pMemory[v7].m_Element.authenticated )
        {
          v13 = atoi(nptr: password);
          if ( g_pCVar->FindCommand_2(this: g_pCVar, a2: "mp_disable_autokick") != nullptr )
          {
            v14 = va(format: "mp_disable_autokick %d\n", v13);
            Cbuf_AddText(eTarget: CBUF_SERVER, pText: v14, nTickDelay: 0);
            Cbuf_Execute();
          }
        }
        continue;
      case 4:
        if ( GetStringHelper(&cmd, outBuf: (char *)&buf.m_Error, bufSize: 25) == 0
          || GetStringHelper(&cmd, outBuf: (char *)&buf.m_Error, bufSize: 25) == 0 )
        {
          goto LABEL_10;
        }
        if ( this->m_ListenerIDs.m_Memory.m_pMemory[v7].m_Element.authenticated )
        {
          RegisterVProfDataListener(listenerID: v7);
          CServerRemoteAccess::LogCommand(this, listener: v7, msg: "Remote VProf started!\n");
          CServerRemoteAccess::RespondString(this, listener: v7, requestID: Int, pString: "Remote VProf started!\n");
        }
        continue;
      case 5:
        if ( GetStringHelper(&cmd, outBuf: (char *)&buf.m_Error, bufSize: 25) == 0
          || GetStringHelper(&cmd, outBuf: (char *)&buf.m_Error, bufSize: 25) == 0 )
        {
          goto LABEL_10;
        }
        if ( this->m_ListenerIDs.m_Memory.m_pMemory[v7].m_Element.authenticated )
        {
          RemoveVProfDataListener(listenerID: v7);
          CServerRemoteAccess::LogCommand(this, listener: v7, msg: "Remote VProf finished!\n");
          CServerRemoteAccess::RespondString(this, listener: v7, requestID: Int, pString: "Remote VProf finished!\n");
        }
        continue;
      case 6:
        this->m_nScreenshotListener = v7;
        CL_TakeJpeg(name: nullptr, quality: 50);
        continue;
      case 7:
        bufferSize = GetConsoleLogFilename();
        CUtlBuffer::CUtlBuffer(this: &buf, growSize: 1024, initSize: 0, nFlags: 1);
        if ( g_pFullFileSystem->ReadFile(
               this: &g_pFullFileSystem->IBaseFileSystem,
               a2: bufferSize,
               a3: "GAME",
               a4: &buf,
               a5: 0,
               a6: 0,
               a7: nullptr) )
        {
          ZipZ = CreateZipZ(z: nullptr, len: 0x100000u, flags: 3u);
          ZipAdd(hz: ZipZ, dstzn: "console.log", src: buf.m_Memory.m_pMemory, len: buf.m_nMaxPut, flags: 3u);
          ZipGetMemory(hz: ZipZ, buf: &listener, len: (unsigned int *)&buffer);
          CServerRemoteAccess::SendResponseToClient(
            this,
            listenerID: v7,
            type: SERVERDATA_CONSOLE_LOG_RESPONSE,
            pData: listener,
            nDataLen: (int)buffer);
          CloseZipZ(hz: ZipZ);
        }
        else
        {
          CServerRemoteAccess::LogCommand(this, listener: v7, msg: "Failed to read console log!\n");
          CServerRemoteAccess::RespondString(
            this,
            listener: v7,
            requestID: Int,
            pString: "Failed to read console log!\n");
        }
        if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        continue;
      case 8:
        v16 = _CommandLine();
        if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v16 + 12))(a1: v16, a2: "-remotebug", a3: 0) != 0 )
        {
          if ( this->m_ListenerIDs.m_Memory.m_pMemory[v7].m_Element.authenticated )
          {
            CServerRemoteAccess::ExecCommand(this, cmdString: "bug -auto");
            CServerRemoteAccess::LogCommand(this, listener: v7, msg: "Remote bug submission\n");
            this->m_nBugListener = v7;
          }
          continue;
        }
        _Warning(a1: "Received a remote bug request from rcon client, but not running with '-remotebug'. Ignoring.\n");
        CServerRemoteAccess::RespondString(
          this,
          listener: v7,
          requestID: 0,
          pString: "Remote machine using wrong bugreporter dll. Try running with '-remotebug'\n");
LABEL_10:
        m_pMemory = cmd.m_Memory.m_pMemory;
LABEL_11:
        if ( cmd.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        return;
      default:
        memset(&cmd.m_Get, 0, 9);
        cmd.m_nOffset = 0;
        cmd.m_nMaxPut = 0;
        if ( cmd.m_Memory.m_nGrowSize < 0 )
          return;
        m_pMemory = cmd.m_Memory.m_pMemory;
        if ( cmd.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cmd.m_Memory.m_pMemory);
          m_pMemory = nullptr;
          cmd.m_Memory.m_pMemory = nullptr;
        }
        cmd.m_Memory.m_nAllocationCount = 0;
        goto LABEL_11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012EFF0
// Name: public: virtual void CServerRemoteAccess::WriteDataRequest(unsigned int,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerRemoteAccess::WriteDataRequest(
        CServerRemoteAccess *this,
        void *listener,
        const void *buffer,
        char *bufferSize)
{
  CRConServer *v5; // eax

  v5 = RCONServer();
  CServerRemoteAccess::WriteDataRequest(this, pNetworkListener: v5, listener, buffer, bufferSize);
}

//------------------------------------------------------------------------------
// Address: 0x10313D20
// Name: _dynamic_initializer_for__remote_bug_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__remote_bug_command__()
{
  ConCommand::ConCommand(
    this: &remote_bug_command,
    pName: "remote_bug",
    callback: remote_bug,
    pHelpString: "Starts a bug report with data from the currently connected rcon machine",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__remote_bug_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10322B10
// Name: _dynamic_atexit_destructor_for__remote_bug_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__remote_bug_command__()
{
  ConCommand::~ConCommand(this: &remote_bug_command);
}

//------------------------------------------------------------------------------
// Address: 0x10313D50
// Name: _dynamic_initializer_for__g_SplitScreenMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SplitScreenMgr__()
{
  GenericThreadLocals::CThreadLocalBase::CThreadLocalBase(this: &g_SplitScreenMgr.m_SplitSlot);
  g_SplitScreenMgr.m_bInitialized = false;
  return atexit(func: dynamic_atexit_destructor_for__g_SplitScreenMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x10322B20
// Name: _dynamic_atexit_destructor_for__g_RCONClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RCONClient__()
{
  CRConClient::~CRConClient(this: &g_RCONClient);
}

//------------------------------------------------------------------------------
// Address: 0x10322B30
// Name: _dynamic_atexit_destructor_for__g_RPTClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_RPTClient__()
{
  CRConClient::~CRConClient(this: &g_RPTClient);
}

//------------------------------------------------------------------------------
// Address: 0x10322B40
// Name: _dynamic_atexit_destructor_for__g_SplitScreenMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SplitScreenMgr__()
{
  GenericThreadLocals::CThreadLocalBase::~CThreadLocalBase(this: &g_SplitScreenMgr.m_SplitSlot);
}

} // namespace engine_xlsp
