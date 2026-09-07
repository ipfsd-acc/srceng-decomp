// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sv_log.cpp
// Functions: 17
// ============================================================

#include "engine\sv_log.h"

//------------------------------------------------------------------------------
// Address: 0x10122F20
// Name: public: void CLog::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLog::RunFrame(CLog *this)
{
  void *m_hLogFile; // edx

  if ( this->m_bFlushLog )
  {
    m_hLogFile = this->m_hLogFile;
    if ( m_hLogFile != nullptr && realtime - this->m_flLastLogFlush > 1.0 )
    {
      this->m_flLastLogFlush = realtime;
      g_pFileSystem->Flush(this: &g_pFileSystem->IBaseFileSystem, a2: m_hLogFile);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10122F60
// Name: public: void CLog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLog::Init(CLog *this)
{
  int v2; // eax

  this->m_LogAddresses.m_Size = 0;
  this->m_hLogFile = nullptr;
  this->m_bActive = false;
  this->m_flLastLogFlush = realtime;
  this->m_bFlushLog = false;
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-flushlog", a3: 0) != 0 )
    this->m_bFlushLog = true;
  g_GameEventManager->AddListener(this: g_GameEventManager, a2: this, a3: "server_spawn", a4: true);
  g_GameEventManager->AddListener(this: g_GameEventManager, a2: this, a3: "server_shutdown", a4: true);
  g_GameEventManager->AddListener(this: g_GameEventManager, a2: this, a3: "server_cvar", a4: true);
  g_GameEventManager->AddListener(this: g_GameEventManager, a2: this, a3: "server_message", a4: true);
  g_GameEventManager->AddListener(this: g_GameEventManager, a2: this, a3: "server_addban", a4: true);
  g_GameEventManager->AddListener(this: g_GameEventManager, a2: this, a3: "server_removeban", a4: true);
}

//------------------------------------------------------------------------------
// Address: 0x10123020
// Name: public: void CLog::ListLogAddress(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLog::ListLogAddress(CLog *this)
{
  int m_Size; // edi
  int v2; // esi
  const char *v3; // eax

  m_Size = this->m_LogAddresses.m_Size;
  if ( m_Size > 0 )
  {
    if ( m_Size == 1 )
      ConMsg(a1: "logaddress_list: %i entry\n", 1);
    else
      ConMsg(a1: "logaddress_list: %i entries\n", m_Size);
    v2 = 0;
    do
    {
      v3 = netadr_s::ToString(this: &this->m_LogAddresses.m_Memory.m_pMemory[v2], baseOnly: false);
      ConMsg(a1: "%s\n", v3);
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  else
  {
    ConMsg(a1: "logaddress_list:  no addresses in the list\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123090
// Name: public: void CLog::Print(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLog::Print(CLog *this, const char *text)
{
  void *m_hLogFile; // ecx
  int v4; // esi
  int v5; // edi
  tm today; // [esp+4h] [ebp-24h] BYREF

  if ( this->m_bActive && text != nullptr && *text != 0 )
  {
    if ( _V_strlen(str: text) <= 1024 )
    {
      _Plat_GetLocalTime(a1: &today);
      V_snprintf(
        pDest: string_0,
        maxLen: 1100,
        pFormat: "L %02i/%02i/%04i - %02i:%02i:%02i: %s",
        today.tm_mon + 1,
        today.tm_mday,
        today.tm_year + 1900,
        today.tm_hour,
        today.tm_min,
        today.tm_sec,
        text);
      if ( sv_logecho.m_pParent != nullptr && sv_logecho.m_pParent->m_Value.m_nValue != 0 )
        ConMsg(a1: "%s", string_0);
      if ( sv_logfile.m_pParent != nullptr && sv_logfile.m_pParent->m_Value.m_nValue != 0 )
      {
        m_hLogFile = this->m_hLogFile;
        if ( m_hLogFile != nullptr )
        {
          g_pFileSystem->FPrintf(this: g_pFileSystem, a2: m_hLogFile, a3: "%s", string_0);
          if ( sv_logflush.m_pParent != nullptr && sv_logflush.m_pParent->m_Value.m_nValue != 0 )
            g_pFileSystem->Flush(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hLogFile);
        }
      }
      if ( this->m_LogAddresses.m_Size > 0 )
      {
        v4 = 0;
        v5 = 0;
        do
        {
          NET_OutOfBandPrintf(sock: 1, adr: &this->m_LogAddresses.m_Memory.m_pMemory[v5], format: "%c%s", 82, string_0);
          ++v4;
          ++v5;
        }
        while ( v4 < this->m_LogAddresses.m_Size );
      }
    }
    else
    {
      _DevMsg(a1: 1, a2: "CLog::Print: string too long (>1024 bytes).");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101231E0
// Name: logaddress_delall
// Source: json
//------------------------------------------------------------------------------
void __cdecl logaddress_delall()
{
  if ( g_Log.m_LogAddresses.m_Size <= 0 )
  {
    ConMsg(a1: "logaddress_delall:  no addresses in the list\n");
  }
  else
  {
    ConMsg(a1: "logaddress_delall:  all addresses cleared\n");
    g_Log.m_LogAddresses.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123210
// Name: logaddress_list
// Source: json
//------------------------------------------------------------------------------
void __cdecl logaddress_list()
{
  CLog::ListLogAddress(this: &g_Log);
}

//------------------------------------------------------------------------------
// Address: 0x10123220
// Name: public: bool CLog::DelLogAddress(struct netadr_s)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLog::DelLogAddress(CLog *this, netadr_s addr)
{
  int v3; // edi
  int v4; // ebx

  v3 = 0;
  if ( this->m_LogAddresses.m_Size <= 0 )
    return 0;
  v4 = 0;
  do
  {
    if ( netadr_s::CompareAdr(this: &this->m_LogAddresses.m_Memory.m_pMemory[v4], a: &addr, onlyBase: false) )
      break;
    ++v3;
    ++v4;
  }
  while ( v3 < this->m_LogAddresses.m_Size );
  if ( v3 >= this->m_LogAddresses.m_Size )
    return 0;
  if ( this->m_LogAddresses.m_Size - v3 - 1 > 0 )
    _V_memmove(
      dest: &this->m_LogAddresses.m_Memory.m_pMemory[v3],
      src: &this->m_LogAddresses.m_Memory.m_pMemory[v3 + 1],
      count: 12 * (this->m_LogAddresses.m_Size - v3 - 1));
  --this->m_LogAddresses.m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10123290
// Name: public: void CLog::Printf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CLog::Printf(CLog *this, const char *fmt, ...)
{
  va_list params; // [esp+14h] [ebp+10h] BYREF

  va_start(params, fmt);
  if ( this->m_bActive )
  {
    V_vsnprintf(pDest: string_1, maxLen: 1024, pFormat: fmt, params);
    CLog::Print(this, text: string_1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101232D0
// Name: public: virtual void CLog::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CLog::FireGameEvent(CLog *this@<ecx>, int a2@<edi>, int a3@<esi>, IGameEvent *event)
{
  const char *v6; // eax
  const char *v7; // edi
  const char *v8; // eax
  int v9; // eax
  const char *v10; // eax
  const char *v11; // edi
  const char *v12; // ebx
  bool v13; // cc
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // ebx
  const char *v17; // edi
  const char *v18; // esi
  const char *v19; // [esp-Ch] [ebp-20h]
  const char *pszName; // [esp+4h] [ebp-10h]
  int userid; // [esp+8h] [ebp-Ch]
  const char *pszNetworkid; // [esp+Ch] [ebp-8h]
  const char *pszCmdGiver; // [esp+1Ch] [ebp+8h]

  if ( this->m_bActive )
  {
    v6 = event->GetName(this: event);
    v7 = v6;
    if ( v6 != nullptr && *v6 != 0 )
    {
      if ( _V_strcmp(s1: v6, s2: "server_spawn") == 0 )
      {
        CLog::Printf(this, fmt: "Started map \"%s\" (CRC \"%i\")\n", sv.m_szMapname, sv.worldmapCRC);
        return;
      }
      if ( _V_strcmp(s1: v7, s2: "server_shutdown") == 0 )
      {
        v8 = event->GetString(this: event, a2: "reason", a3: defaultValue);
LABEL_12:
        CLog::Printf(this, fmt: "server_message: \"%s\"\n", v8);
        return;
      }
      if ( _V_strcmp(s1: v7, s2: "server_cvar") == 0 )
      {
        v9 = ((int (__thiscall *)(IGameEvent *, const char *, const char *, int, int))event->GetString)(
               a1: event,
               a2: "cvarvalue",
               a3: defaultValue,
               a4: a2,
               a5: a3);
        v10 = (const char *)((int (__thiscall *)(IGameEvent *, const char *, const char *, int))event->GetString)(
                              a1: event,
                              a2: "cvarname",
                              a3: defaultValue,
                              a4: v9);
        CLog::Printf(this, fmt: "server_cvar: \"%s\" \"%s\"\n", v10, v19);
        return;
      }
      if ( _V_strcmp(s1: v7, s2: "server_message") == 0 )
      {
        v8 = event->GetString(this: event, a2: "text", a3: defaultValue);
        goto LABEL_12;
      }
      if ( _V_strcmp(s1: v7, s2: "server_addban") != 0 )
      {
        if ( _V_strcmp(s1: v7, s2: "server_removeban") == 0
          && sv_logbans.m_pParent != nullptr
          && sv_logbans.m_pParent->m_Value.m_nValue > 0 )
        {
          v16 = event->GetString(this: event, a2: "networkid", a3: defaultValue);
          v17 = event->GetString(this: event, a2: "ip", a3: defaultValue);
          v18 = event->GetString(this: event, a2: "by", a3: defaultValue);
          if ( _V_strlen(str: v17) <= 0 )
            CLog::Printf(this, fmt: "Removeid: \"<><%s><>\" was unbanned by \"%s\"\n", v16, v18);
          else
            CLog::Printf(this, fmt: "Removeip: \"<><><>\" was unbanned by \"%s\" (IP \"%s\")\n", v18, v17);
        }
      }
      else if ( sv_logbans.m_pParent != nullptr && sv_logbans.m_pParent->m_Value.m_nValue > 0 )
      {
        userid = ((int (__thiscall *)(IGameEvent *, const char *, _DWORD, int, int))event->GetInt)(
                   a1: event,
                   a2: "userid",
                   a3: 0,
                   a4: a2,
                   a5: a3);
        pszName = event->GetString(this: event, a2: "name", a3: defaultValue);
        pszNetworkid = event->GetString(this: event, a2: "networkid", a3: defaultValue);
        v11 = event->GetString(this: event, a2: "ip", a3: defaultValue);
        v12 = event->GetString(this: event, a2: "duration", a3: defaultValue);
        pszCmdGiver = event->GetString(this: event, a2: "by", a3: defaultValue);
        if ( _V_strlen(str: v11) <= 0 )
        {
          v13 = ((int (__thiscall *)(IGameEvent *))event->GetInt)(a1: event) <= 0;
          v15 = "was kicked and banned";
          if ( v13 )
            v15 = "was banned";
          if ( userid <= 0 )
            CLog::Printf(this, fmt: "Banid: \"<><%s><>\" %s \"%s\" by \"%s\"\n", pszNetworkid, v15, v12, pszCmdGiver);
          else
            CLog::Printf(
              this,
              fmt: "Banid: \"%s<%i><%s><>\" %s \"%s\" by \"%s\"\n",
              pszName,
              userid,
              pszNetworkid,
              v15,
              v12,
              pszCmdGiver);
        }
        else
        {
          v13 = ((int (__thiscall *)(IGameEvent *))event->GetInt)(a1: event) <= 0;
          v14 = "was kicked and banned by IP";
          if ( v13 )
            v14 = "was banned by IP";
          if ( userid <= 0 )
            CLog::Printf(this, fmt: "Addip: \"<><><>\" %s \"%s\" by \"%s\" (IP \"%s\")\n", v14, v12, pszCmdGiver, v11);
          else
            CLog::Printf(
              this,
              fmt: "Addip: \"%s<%i><%s><>\" %s \"%s\" by \"%s\" (IP \"%s\")\n",
              pszName,
              userid,
              pszNetworkid,
              v14,
              v12,
              pszCmdGiver,
              v11);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123630
// Name: public: void CLog::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLog::Close(CLog *this)
{
  if ( this->m_hLogFile != nullptr )
  {
    CLog::Printf(this, fmt: "Log file closed\n");
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hLogFile);
  }
  this->m_hLogFile = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10123670
// Name: public: void CLog::Open(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CLog::Open(CLog *this@<ecx>, void *a2@<edi>)
{
  bool v3; // zf
  ConVar *m_pParent; // eax
  int m_nValue; // eax
  int v6; // esi
  int v7; // edi
  int v8; // ebx
  unsigned __int16 UDPPort; // ax
  int v10; // edi
  void *v11; // esi
  CLog *v12; // edi
  int v13; // eax
  char szFileBase[260]; // [esp+4h] [ebp-244h] BYREF
  char szTestFile[260]; // [esp+108h] [ebp-140h] BYREF
  int ipparts[4]; // [esp+20Ch] [ebp-3Ch]
  tm today; // [esp+21Ch] [ebp-2Ch] BYREF
  CLog *v19; // [esp+240h] [ebp-8h]
  const char *pszLogsDir; // [esp+244h] [ebp-4h]

  v3 = !this->m_bActive;
  v19 = this;
  if ( !v3 && sv_logfile.m_pParent != nullptr && sv_logfile.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( this->m_hLogFile != nullptr )
    {
      if ( sv_log_onefile.m_pParent != nullptr && sv_log_onefile.m_pParent->m_Value.m_nValue != 0 )
        return;
      CLog::Printf(this, fmt: "Log file closed\n");
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hLogFile);
    }
    this->m_hLogFile = nullptr;
    _Plat_GetLocalTime(a1: &today);
    if ( (sv_logsdir.m_nFlags & 0x1000) != 0 )
    {
      pszLogsDir = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      pszLogsDir = sv_logsdir.m_pParent->m_Value.m_pszString;
      if ( pszLogsDir == nullptr )
        pszLogsDir = defaultValue;
    }
    if ( !COM_IsValidPath(pszFilename: pszLogsDir) )
      pszLogsDir = "logs";
    m_pParent = cvar->FindVar_2(this: cvar, a2: "hostip")->m_pParent;
    if ( m_pParent != nullptr )
      m_nValue = m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v6 = HIBYTE(m_nValue);
    v7 = BYTE2(m_nValue);
    v8 = BYTE1(m_nValue);
    ipparts[3] = (unsigned __int8)m_nValue;
    UDPPort = NET_GetUDPPort(socket: 1);
    V_snprintf(
      pDest: szFileBase,
      maxLen: 260,
      pFormat: "%s/L%03i_%03i_%03i_%03i_%i_%04i%02i%02i%02i%02i_",
      pszLogsDir,
      v6,
      v7,
      v8,
      ipparts[3],
      UDPPort,
      today.tm_year + 1900,
      today.tm_mon + 1,
      today.tm_mday,
      today.tm_hour,
      today.tm_min);
    v10 = 0;
    while ( 1 )
    {
      V_snprintf(pDest: szTestFile, maxLen: 260, pFormat: "%s%03i.log", szFileBase, v10);
      V_FixSlashes(pname: szTestFile, separator: 92);
      COM_CreatePath(path: szTestFile);
      v11 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *, const char *, void *))g_pFileSystem->Open)(
                      a1: &g_pFileSystem->IBaseFileSystem,
                      a2: szTestFile,
                      a3: "r",
                      a4: "LOGDIR",
                      a5: a2);
      if ( v11 == nullptr )
        break;
      a2 = v11;
      ((void (__thiscall *)(IBaseFileSystem *))g_pFileSystem->Close)(a1: &g_pFileSystem->IBaseFileSystem);
      if ( ++v10 >= 1000 )
        goto LABEL_23;
    }
    COM_CreatePath(path: szTestFile);
    v11 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *))g_pFileSystem->Open)(
                    a1: &g_pFileSystem->IBaseFileSystem,
                    a2: szTestFile,
                    a3: "wt");
    if ( v11 == nullptr )
      goto LABEL_24;
    ConMsg(a1: "Server logging data to file %s\n", szTestFile);
LABEL_23:
    if ( v10 == 1000 )
    {
LABEL_24:
      ConMsg(a1: "Unable to open logfiles under %s\nLogging disabled\n", szFileBase);
      return;
    }
    v12 = v19;
    v19->m_hLogFile = v11;
    v13 = build_number();
    CLog::Printf(
      this: v12,
      fmt: "Log file started (file \"%s\") (game \"%s\") (version \"%i\")\n",
      szTestFile,
      com_gamedir,
      v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101238F0
// Name: log
// Source: json
//------------------------------------------------------------------------------
void __usercall log(void *a1@<edi>, const CCommand *args)
{
  char v2; // bl
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax

  if ( args->m_nArgc == 2 )
  {
    if ( _V_stricmp(s1: args->m_ppArgv[1], s2: "off") == 0 )
      goto LABEL_33;
    v3 = defaultValue;
    if ( args->m_nArgc > 1 )
      v3 = args->m_ppArgv[1];
    if ( _V_stricmp(s1: v3, s2: "0") != 0 )
    {
      v4 = defaultValue;
      if ( args->m_nArgc > 1 )
        v4 = args->m_ppArgv[1];
      if ( _V_stricmp(s1: v4, s2: "on") == 0 )
        goto LABEL_32;
      v5 = defaultValue;
      if ( args->m_nArgc > 1 )
        v5 = args->m_ppArgv[1];
      if ( _V_stricmp(s1: v5, s2: "1") != 0 )
      {
        if ( args->m_nArgc > 1 )
          ConMsg(a1: "log:  unknown parameter %s, 'on' and 'off' are valid\n", args->m_ppArgv[1]);
        else
          ConMsg(a1: "log:  unknown parameter %s, 'on' and 'off' are valid\n", defaultValue);
      }
      else
      {
LABEL_32:
        g_Log.m_bActive = true;
        ConMsg(a1: "Server logging enabled.\n");
        CLog::Open(this: &g_Log, a2: a1);
      }
    }
    else
    {
LABEL_33:
      if ( g_Log.m_bActive )
      {
        if ( g_Log.m_hLogFile != nullptr )
        {
          CLog::Printf(this: &g_Log, fmt: "Log file closed\n");
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: g_Log.m_hLogFile);
        }
        g_Log.m_hLogFile = nullptr;
        g_Log.m_bActive = false;
        ConMsg(a1: "Server logging disabled.\n");
      }
    }
  }
  else
  {
    ConMsg(a1: "Usage:  log < on | off >\n");
    if ( g_Log.m_bActive )
    {
      v2 = 0;
      ConMsg(a1: "currently logging to: ");
      if ( sv_logfile.m_pParent != nullptr && sv_logfile.m_pParent->m_Value.m_nValue != 0 )
      {
        ConMsg(a1: "file");
        v2 = 1;
      }
      if ( sv_logecho.m_pParent != nullptr && sv_logecho.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( v2 != 0 )
        {
          ConMsg(a1: ", console");
        }
        else
        {
          ConMsg(a1: "console");
          v2 = 1;
        }
      }
      if ( g_Log.m_LogAddresses.m_Size > 0 )
      {
        if ( v2 == 0 )
        {
          ConMsg(a1: "udp");
          ConMsg(a1: "\n");
          return;
        }
        ConMsg(a1: ", udp");
      }
      if ( v2 == 0 )
      {
        ConMsg(a1: "no destinations! (file, console, or udp)\n");
        ConMsg(a1: "check \"sv_logfile\", \"sv_logecho\", and \"logaddress_list\"");
      }
      ConMsg(a1: "\n");
    }
    else
    {
      ConMsg(a1: "not currently logging\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123B10
// Name: logaddress_del
// Source: json
//------------------------------------------------------------------------------
void __cdecl logaddress_del(const CCommand *args)
{
  int m_nArgc; // eax
  const char *v2; // edi
  const char *v3; // esi
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char szAdr[32]; // [esp+8h] [ebp-2Ch] BYREF
  netadr_s adr; // [esp+28h] [ebp-Ch] BYREF

  netadr_s::SetIP(this: &adr, unIP: 0);
  netadr_s::SetPort(this: &adr, newport: 0);
  netadr_s::SetType(this: &adr, newtype: NA_IP);
  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc == 4 || m_nArgc == 2 )
  {
    v2 = defaultValue;
    if ( m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    if ( m_nArgc == 4 )
    {
      v3 = args->m_ppArgv[3];
    }
    else
    {
      v4 = _V_strstr(s1: v2, search: ":");
      if ( v4 != nullptr )
        v3 = v4 + 1;
      else
        v3 = "27015";
    }
    if ( V_atoi(str: v3) != 0 )
    {
      if ( v2 != nullptr && *v2 != 0 )
      {
        V_snprintf(pDest: szAdr, maxLen: 32, pFormat: "%s:%s", v2, v3);
        if ( NET_StringToAdr(s: szAdr, a: &adr) )
        {
          if ( CLog::DelLogAddress(this: &g_Log, addr: adr) != 0 )
          {
            v5 = netadr_s::ToString(this: &adr, baseOnly: false);
            ConMsg(a1: "logaddress_del:  %s\n", v5);
          }
          else
          {
            v6 = netadr_s::ToString(this: &adr, baseOnly: false);
            ConMsg(a1: "logaddress_del:  address %s not found in the list\n", v6);
          }
        }
        else
        {
          ConMsg(a1: "logaddress_del:  unable to resolve %s\n", szAdr);
        }
      }
      else
      {
        ConMsg(a1: "logaddress_del:  unparseable address\n");
      }
    }
    else
    {
      ConMsg(a1: "logaddress_del:  must specify a valid port\n");
    }
  }
  else
  {
    ConMsg(a1: "Usage:  logaddress_del ip:port\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123C80
// Name: public: void CLog::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLog::Shutdown(CLog *this)
{
  int v2; // eax

  if ( this->m_hLogFile != nullptr )
  {
    CLog::Printf(this, fmt: "Log file closed\n");
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hLogFile);
  }
  this->m_LogAddresses.m_Size = 0;
  this->m_hLogFile = nullptr;
  this->m_bActive = false;
  this->m_flLastLogFlush = realtime;
  this->m_bFlushLog = false;
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-flushlog", a3: 0) != 0 )
    this->m_bFlushLog = true;
  g_GameEventManager->RemoveListener(this: g_GameEventManager, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10123D00
// Name: public: void CLog::PrintServerVars(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLog::PrintServerVars(CLog *this)
{
  ICvar::ICVarIteratorInternal *v2; // edi
  ConCommandBase *v3; // esi
  const char *m_pszName; // eax
  const char *v5; // eax
  const char *v6; // [esp-Ch] [ebp-10h]

  if ( this->m_bActive )
  {
    CLog::Printf(this, fmt: "server cvars start\n");
    v2 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
    v2->SetFirst(this: v2);
    while ( v2->IsValid(this: v2) )
    {
      v3 = v2->Get(this: v2);
      if ( !v3->IsCommand(this: v3) && v3->IsFlagSet(this: v3, a2: 256) )
      {
        if ( (v3->m_nFlags & 0x1000) != 0 )
        {
          m_pszName = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pszName = v3[1].m_pNext[1].m_pszName;
          if ( m_pszName == nullptr )
            m_pszName = defaultValue;
        }
        v5 = (const char *)((int (__thiscall *)(ConCommandBase *, const char *))v3->GetName)(a1: v3, a2: m_pszName);
        CLog::Printf(this, fmt: "\"%s\" = \"%s\"\n", v5, v6);
      }
      v2->Next(this: v2);
    }
    CLog::Printf(this, fmt: "server cvars end\n");
    free(pMem: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123E20
// Name: public: bool CLog::AddLogAddress(struct netadr_s)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLog::AddLogAddress(CLog *this, netadr_s addr)
{
  int v3; // edi
  int v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  netadr_s *m_pMemory; // ecx
  int v9; // eax
  netadr_s *v10; // eax

  v3 = 0;
  if ( this->m_LogAddresses.m_Size > 0 )
  {
    v4 = 0;
    do
    {
      if ( netadr_s::CompareAdr(this: &this->m_LogAddresses.m_Memory.m_pMemory[v4], a: &addr, onlyBase: false) )
        break;
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_LogAddresses.m_Size );
    if ( v3 < this->m_LogAddresses.m_Size )
      return 0;
  }
  m_Size = this->m_LogAddresses.m_Size;
  m_nAllocationCount = this->m_LogAddresses.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_LogAddresses,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_LogAddresses.m_Size;
  m_pMemory = this->m_LogAddresses.m_Memory.m_pMemory;
  v9 = this->m_LogAddresses.m_Size - m_Size - 1;
  this->m_LogAddresses.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v9);
  v10 = &this->m_LogAddresses.m_Memory.m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = addr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10123ED0
// Name: logaddress_add
// Source: json
//------------------------------------------------------------------------------
void __cdecl logaddress_add(const CCommand *args)
{
  int m_nArgc; // eax
  const char *v2; // edi
  const char *v3; // esi
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char szAdr[32]; // [esp+8h] [ebp-2Ch] BYREF
  netadr_s adr; // [esp+28h] [ebp-Ch] BYREF

  netadr_s::SetIP(this: &adr, unIP: 0);
  netadr_s::SetPort(this: &adr, newport: 0);
  netadr_s::SetType(this: &adr, newtype: NA_IP);
  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc == 4 || m_nArgc == 2 )
  {
    v2 = defaultValue;
    if ( m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    if ( m_nArgc == 4 )
    {
      v3 = args->m_ppArgv[3];
    }
    else
    {
      v4 = _V_strstr(s1: v2, search: ":");
      if ( v4 != nullptr )
        v3 = v4 + 1;
      else
        v3 = "27015";
    }
    if ( V_atoi(str: v3) != 0 )
    {
      if ( v2 != nullptr && *v2 != 0 )
      {
        V_snprintf(pDest: szAdr, maxLen: 32, pFormat: "%s:%s", v2, v3);
        if ( NET_StringToAdr(s: szAdr, a: &adr) )
        {
          if ( CLog::AddLogAddress(this: &g_Log, addr: adr) != 0 )
          {
            v5 = netadr_s::ToString(this: &adr, baseOnly: false);
            ConMsg(a1: "logaddress_add:  %s\n", v5);
          }
          else
          {
            v6 = netadr_s::ToString(this: &adr, baseOnly: false);
            ConMsg(a1: "logaddress_add:  %s is already in the list\n", v6);
          }
        }
        else
        {
          ConMsg(a1: "logaddress_add:  unable to resolve %s\n", szAdr);
        }
      }
      else
      {
        ConMsg(a1: "logaddress_add:  unparseable address\n");
      }
    }
    else
    {
      ConMsg(a1: "logaddress_add:  must specify a valid port\n");
    }
  }
  else
  {
    ConMsg(a1: "Usage:  logaddress_add ip:port\n");
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10122FC0
// Name: public: void CLog::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLog::RunFrame(CLog *this)
{
  void *m_hLogFile; // edx

  if ( this->m_bFlushLog )
  {
    m_hLogFile = this->m_hLogFile;
    if ( m_hLogFile != nullptr && realtime - this->m_flLastLogFlush > 1.0 )
    {
      this->m_flLastLogFlush = realtime;
      g_pFileSystem->Flush(this: &g_pFileSystem->IBaseFileSystem, a2: m_hLogFile);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123000
// Name: public: void CLog::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLog::Init(CLog *this)
{
  int v2; // eax

  this->m_LogAddresses.m_Size = 0;
  this->m_hLogFile = nullptr;
  this->m_bActive = false;
  this->m_flLastLogFlush = realtime;
  this->m_bFlushLog = false;
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-flushlog", a3: 0) != 0 )
    this->m_bFlushLog = true;
  g_GameEventManager->AddListener(this: g_GameEventManager, a2: this, a3: "server_spawn", a4: true);
  g_GameEventManager->AddListener(this: g_GameEventManager, a2: this, a3: "server_shutdown", a4: true);
  g_GameEventManager->AddListener(this: g_GameEventManager, a2: this, a3: "server_cvar", a4: true);
  g_GameEventManager->AddListener(this: g_GameEventManager, a2: this, a3: "server_message", a4: true);
  g_GameEventManager->AddListener(this: g_GameEventManager, a2: this, a3: "server_addban", a4: true);
  g_GameEventManager->AddListener(this: g_GameEventManager, a2: this, a3: "server_removeban", a4: true);
}

//------------------------------------------------------------------------------
// Address: 0x101230C0
// Name: public: void CLog::ListLogAddress(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLog::ListLogAddress(CLog *this)
{
  int m_Size; // edi
  int v2; // esi
  const char *v3; // eax

  m_Size = this->m_LogAddresses.m_Size;
  if ( m_Size > 0 )
  {
    if ( m_Size == 1 )
      ConMsg(a1: "logaddress_list: %i entry\n", 1);
    else
      ConMsg(a1: "logaddress_list: %i entries\n", m_Size);
    v2 = 0;
    do
    {
      v3 = netadr_s::ToString(this: &this->m_LogAddresses.m_Memory.m_pMemory[v2], baseOnly: false);
      ConMsg(a1: "%s\n", v3);
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  else
  {
    ConMsg(a1: "logaddress_list:  no addresses in the list\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123130
// Name: public: void CLog::Print(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLog::Print(CLog *this, const char *text)
{
  void *m_hLogFile; // ecx
  int v4; // esi
  int v5; // edi
  tm today; // [esp+4h] [ebp-24h] BYREF

  if ( this->m_bActive && text != nullptr && *text != 0 )
  {
    if ( _V_strlen(str: text) <= 1024 )
    {
      _Plat_GetLocalTime(a1: &today);
      V_snprintf(
        pDest: string_0,
        maxLen: 1100,
        pFormat: "L %02i/%02i/%04i - %02i:%02i:%02i: %s",
        today.tm_mon + 1,
        today.tm_mday,
        today.tm_year + 1900,
        today.tm_hour,
        today.tm_min,
        today.tm_sec,
        text);
      if ( sv_logecho.m_pParent != nullptr && sv_logecho.m_pParent->m_Value.m_nValue != 0 )
        ConMsg(a1: "%s", string_0);
      if ( sv_logfile.m_pParent != nullptr && sv_logfile.m_pParent->m_Value.m_nValue != 0 )
      {
        m_hLogFile = this->m_hLogFile;
        if ( m_hLogFile != nullptr )
        {
          g_pFileSystem->FPrintf(this: g_pFileSystem, a2: m_hLogFile, a3: "%s", string_0);
          if ( sv_logflush.m_pParent != nullptr && sv_logflush.m_pParent->m_Value.m_nValue != 0 )
            g_pFileSystem->Flush(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hLogFile);
        }
      }
      if ( this->m_LogAddresses.m_Size > 0 )
      {
        v4 = 0;
        v5 = 0;
        do
        {
          NET_OutOfBandPrintf(sock: 1, adr: &this->m_LogAddresses.m_Memory.m_pMemory[v5], format: "%c%s", 82, string_0);
          ++v4;
          ++v5;
        }
        while ( v4 < this->m_LogAddresses.m_Size );
      }
    }
    else
    {
      _DevMsg(a1: 1, a2: "CLog::Print: string too long (>1024 bytes).");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123280
// Name: logaddress_delall
// Source: json
//------------------------------------------------------------------------------
void __cdecl logaddress_delall()
{
  if ( g_Log.m_LogAddresses.m_Size <= 0 )
  {
    ConMsg(a1: "logaddress_delall:  no addresses in the list\n");
  }
  else
  {
    ConMsg(a1: "logaddress_delall:  all addresses cleared\n");
    g_Log.m_LogAddresses.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101232B0
// Name: logaddress_list
// Source: json
//------------------------------------------------------------------------------
void __cdecl logaddress_list()
{
  CLog::ListLogAddress(this: &g_Log);
}

//------------------------------------------------------------------------------
// Address: 0x101232C0
// Name: public: bool CLog::DelLogAddress(struct netadr_s)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLog::DelLogAddress(CLog *this, netadr_s addr)
{
  int v3; // edi
  int v4; // ebx

  v3 = 0;
  if ( this->m_LogAddresses.m_Size <= 0 )
    return 0;
  v4 = 0;
  do
  {
    if ( netadr_s::CompareAdr(this: &this->m_LogAddresses.m_Memory.m_pMemory[v4], a: &addr, onlyBase: false) )
      break;
    ++v3;
    ++v4;
  }
  while ( v3 < this->m_LogAddresses.m_Size );
  if ( v3 >= this->m_LogAddresses.m_Size )
    return 0;
  if ( this->m_LogAddresses.m_Size - v3 - 1 > 0 )
    _V_memmove(
      dest: &this->m_LogAddresses.m_Memory.m_pMemory[v3],
      src: &this->m_LogAddresses.m_Memory.m_pMemory[v3 + 1],
      count: 12 * (this->m_LogAddresses.m_Size - v3 - 1));
  --this->m_LogAddresses.m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10123330
// Name: public: void CLog::Printf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CLog::Printf(CLog *this, const char *fmt, ...)
{
  va_list params; // [esp+14h] [ebp+10h] BYREF

  va_start(params, fmt);
  if ( this->m_bActive )
  {
    V_vsnprintf(pDest: string_1, maxLen: 1024, pFormat: fmt, params);
    CLog::Print(this, text: string_1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123370
// Name: public: virtual void CLog::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CLog::FireGameEvent(CLog *this@<ecx>, int a2@<edi>, int a3@<esi>, IGameEvent *event)
{
  const char *v6; // eax
  const char *v7; // edi
  const char *v8; // eax
  int v9; // eax
  const char *v10; // eax
  const char *v11; // edi
  const char *v12; // ebx
  bool v13; // cc
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // ebx
  const char *v17; // edi
  const char *v18; // esi
  const char *v19; // [esp-Ch] [ebp-20h]
  const char *pszName; // [esp+4h] [ebp-10h]
  int userid; // [esp+8h] [ebp-Ch]
  const char *pszNetworkid; // [esp+Ch] [ebp-8h]
  const char *pszCmdGiver; // [esp+1Ch] [ebp+8h]

  if ( this->m_bActive )
  {
    v6 = event->GetName(this: event);
    v7 = v6;
    if ( v6 != nullptr && *v6 != 0 )
    {
      if ( _V_strcmp(s1: v6, s2: "server_spawn") == 0 )
      {
        CLog::Printf(this, fmt: "Started map \"%s\" (CRC \"%i\")\n", sv.m_szMapname, sv.worldmapCRC);
        return;
      }
      if ( _V_strcmp(s1: v7, s2: "server_shutdown") == 0 )
      {
        v8 = event->GetString(this: event, a2: "reason", a3: defaultValue);
LABEL_12:
        CLog::Printf(this, fmt: "server_message: \"%s\"\n", v8);
        return;
      }
      if ( _V_strcmp(s1: v7, s2: "server_cvar") == 0 )
      {
        v9 = ((int (__thiscall *)(IGameEvent *, const char *, const char *, int, int))event->GetString)(
               a1: event,
               a2: "cvarvalue",
               a3: defaultValue,
               a4: a2,
               a5: a3);
        v10 = (const char *)((int (__thiscall *)(IGameEvent *, const char *, const char *, int))event->GetString)(
                              a1: event,
                              a2: "cvarname",
                              a3: defaultValue,
                              a4: v9);
        CLog::Printf(this, fmt: "server_cvar: \"%s\" \"%s\"\n", v10, v19);
        return;
      }
      if ( _V_strcmp(s1: v7, s2: "server_message") == 0 )
      {
        v8 = event->GetString(this: event, a2: "text", a3: defaultValue);
        goto LABEL_12;
      }
      if ( _V_strcmp(s1: v7, s2: "server_addban") != 0 )
      {
        if ( _V_strcmp(s1: v7, s2: "server_removeban") == 0
          && sv_logbans.m_pParent != nullptr
          && sv_logbans.m_pParent->m_Value.m_nValue > 0 )
        {
          v16 = event->GetString(this: event, a2: "networkid", a3: defaultValue);
          v17 = event->GetString(this: event, a2: "ip", a3: defaultValue);
          v18 = event->GetString(this: event, a2: "by", a3: defaultValue);
          if ( _V_strlen(str: v17) <= 0 )
            CLog::Printf(this, fmt: "Removeid: \"<><%s><>\" was unbanned by \"%s\"\n", v16, v18);
          else
            CLog::Printf(this, fmt: "Removeip: \"<><><>\" was unbanned by \"%s\" (IP \"%s\")\n", v18, v17);
        }
      }
      else if ( sv_logbans.m_pParent != nullptr && sv_logbans.m_pParent->m_Value.m_nValue > 0 )
      {
        userid = ((int (__thiscall *)(IGameEvent *, const char *, _DWORD, int, int))event->GetInt)(
                   a1: event,
                   a2: "userid",
                   a3: 0,
                   a4: a2,
                   a5: a3);
        pszName = event->GetString(this: event, a2: "name", a3: defaultValue);
        pszNetworkid = event->GetString(this: event, a2: "networkid", a3: defaultValue);
        v11 = event->GetString(this: event, a2: "ip", a3: defaultValue);
        v12 = event->GetString(this: event, a2: "duration", a3: defaultValue);
        pszCmdGiver = event->GetString(this: event, a2: "by", a3: defaultValue);
        if ( _V_strlen(str: v11) <= 0 )
        {
          v13 = ((int (__thiscall *)(IGameEvent *))event->GetInt)(a1: event) <= 0;
          v15 = "was kicked and banned";
          if ( v13 )
            v15 = "was banned";
          if ( userid <= 0 )
            CLog::Printf(this, fmt: "Banid: \"<><%s><>\" %s \"%s\" by \"%s\"\n", pszNetworkid, v15, v12, pszCmdGiver);
          else
            CLog::Printf(
              this,
              fmt: "Banid: \"%s<%i><%s><>\" %s \"%s\" by \"%s\"\n",
              pszName,
              userid,
              pszNetworkid,
              v15,
              v12,
              pszCmdGiver);
        }
        else
        {
          v13 = ((int (__thiscall *)(IGameEvent *))event->GetInt)(a1: event) <= 0;
          v14 = "was kicked and banned by IP";
          if ( v13 )
            v14 = "was banned by IP";
          if ( userid <= 0 )
            CLog::Printf(this, fmt: "Addip: \"<><><>\" %s \"%s\" by \"%s\" (IP \"%s\")\n", v14, v12, pszCmdGiver, v11);
          else
            CLog::Printf(
              this,
              fmt: "Addip: \"%s<%i><%s><>\" %s \"%s\" by \"%s\" (IP \"%s\")\n",
              pszName,
              userid,
              pszNetworkid,
              v14,
              v12,
              pszCmdGiver,
              v11);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101236D0
// Name: public: void CLog::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLog::Close(CLog *this)
{
  if ( this->m_hLogFile != nullptr )
  {
    CLog::Printf(this, fmt: "Log file closed\n");
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hLogFile);
  }
  this->m_hLogFile = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10123710
// Name: public: void CLog::Open(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CLog::Open(CLog *this@<ecx>, void *a2@<edi>)
{
  bool v3; // zf
  ConVar *m_pParent; // eax
  int m_nValue; // eax
  int v6; // esi
  int v7; // edi
  int v8; // ebx
  unsigned __int16 UDPPort; // ax
  int v10; // edi
  void *v11; // esi
  CLog *v12; // edi
  int v13; // eax
  char szFileBase[260]; // [esp+4h] [ebp-244h] BYREF
  char szTestFile[260]; // [esp+108h] [ebp-140h] BYREF
  int ipparts[4]; // [esp+20Ch] [ebp-3Ch]
  tm today; // [esp+21Ch] [ebp-2Ch] BYREF
  CLog *v19; // [esp+240h] [ebp-8h]
  const char *pszLogsDir; // [esp+244h] [ebp-4h]

  v3 = !this->m_bActive;
  v19 = this;
  if ( !v3 && sv_logfile.m_pParent != nullptr && sv_logfile.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( this->m_hLogFile != nullptr )
    {
      if ( sv_log_onefile.m_pParent != nullptr && sv_log_onefile.m_pParent->m_Value.m_nValue != 0 )
        return;
      CLog::Printf(this, fmt: "Log file closed\n");
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hLogFile);
    }
    this->m_hLogFile = nullptr;
    _Plat_GetLocalTime(a1: &today);
    if ( (sv_logsdir.m_nFlags & 0x1000) != 0 )
    {
      pszLogsDir = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      pszLogsDir = sv_logsdir.m_pParent->m_Value.m_pszString;
      if ( pszLogsDir == nullptr )
        pszLogsDir = defaultValue;
    }
    if ( !COM_IsValidPath(pszFilename: pszLogsDir) )
      pszLogsDir = "logs";
    m_pParent = cvar->FindVar_2(this: cvar, a2: "hostip")->m_pParent;
    if ( m_pParent != nullptr )
      m_nValue = m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v6 = HIBYTE(m_nValue);
    v7 = BYTE2(m_nValue);
    v8 = BYTE1(m_nValue);
    ipparts[3] = (unsigned __int8)m_nValue;
    UDPPort = NET_GetUDPPort(socket: 1);
    V_snprintf(
      pDest: szFileBase,
      maxLen: 260,
      pFormat: "%s/L%03i_%03i_%03i_%03i_%i_%04i%02i%02i%02i%02i_",
      pszLogsDir,
      v6,
      v7,
      v8,
      ipparts[3],
      UDPPort,
      today.tm_year + 1900,
      today.tm_mon + 1,
      today.tm_mday,
      today.tm_hour,
      today.tm_min);
    v10 = 0;
    while ( 1 )
    {
      V_snprintf(pDest: szTestFile, maxLen: 260, pFormat: "%s%03i.log", szFileBase, v10);
      V_FixSlashes(pname: szTestFile, separator: 92);
      COM_CreatePath(path: szTestFile);
      v11 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *, const char *, void *))g_pFileSystem->Open)(
                      a1: &g_pFileSystem->IBaseFileSystem,
                      a2: szTestFile,
                      a3: "r",
                      a4: "LOGDIR",
                      a5: a2);
      if ( v11 == nullptr )
        break;
      a2 = v11;
      ((void (__thiscall *)(IBaseFileSystem *))g_pFileSystem->Close)(a1: &g_pFileSystem->IBaseFileSystem);
      if ( ++v10 >= 1000 )
        goto LABEL_23;
    }
    COM_CreatePath(path: szTestFile);
    v11 = (void *)((int (__thiscall *)(IBaseFileSystem *, char *, const char *))g_pFileSystem->Open)(
                    a1: &g_pFileSystem->IBaseFileSystem,
                    a2: szTestFile,
                    a3: "wt");
    if ( v11 == nullptr )
      goto LABEL_24;
    ConMsg(a1: "Server logging data to file %s\n", szTestFile);
LABEL_23:
    if ( v10 == 1000 )
    {
LABEL_24:
      ConMsg(a1: "Unable to open logfiles under %s\nLogging disabled\n", szFileBase);
      return;
    }
    v12 = v19;
    v19->m_hLogFile = v11;
    v13 = build_number();
    CLog::Printf(
      this: v12,
      fmt: "Log file started (file \"%s\") (game \"%s\") (version \"%i\")\n",
      szTestFile,
      com_gamedir,
      v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123990
// Name: log
// Source: json
//------------------------------------------------------------------------------
void __usercall log(void *a1@<edi>, const CCommand *args)
{
  char v2; // bl
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax

  if ( args->m_nArgc == 2 )
  {
    if ( _V_stricmp(s1: args->m_ppArgv[1], s2: "off") == 0 )
      goto LABEL_33;
    v3 = defaultValue;
    if ( args->m_nArgc > 1 )
      v3 = args->m_ppArgv[1];
    if ( _V_stricmp(s1: v3, s2: "0") != 0 )
    {
      v4 = defaultValue;
      if ( args->m_nArgc > 1 )
        v4 = args->m_ppArgv[1];
      if ( _V_stricmp(s1: v4, s2: "on") == 0 )
        goto LABEL_32;
      v5 = defaultValue;
      if ( args->m_nArgc > 1 )
        v5 = args->m_ppArgv[1];
      if ( _V_stricmp(s1: v5, s2: "1") != 0 )
      {
        if ( args->m_nArgc > 1 )
          ConMsg(a1: "log:  unknown parameter %s, 'on' and 'off' are valid\n", args->m_ppArgv[1]);
        else
          ConMsg(a1: "log:  unknown parameter %s, 'on' and 'off' are valid\n", defaultValue);
      }
      else
      {
LABEL_32:
        g_Log.m_bActive = true;
        ConMsg(a1: "Server logging enabled.\n");
        CLog::Open(this: &g_Log, a2: a1);
      }
    }
    else
    {
LABEL_33:
      if ( g_Log.m_bActive )
      {
        if ( g_Log.m_hLogFile != nullptr )
        {
          CLog::Printf(this: &g_Log, fmt: "Log file closed\n");
          g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: g_Log.m_hLogFile);
        }
        g_Log.m_hLogFile = nullptr;
        g_Log.m_bActive = false;
        ConMsg(a1: "Server logging disabled.\n");
      }
    }
  }
  else
  {
    ConMsg(a1: "Usage:  log < on | off >\n");
    if ( g_Log.m_bActive )
    {
      v2 = 0;
      ConMsg(a1: "currently logging to: ");
      if ( sv_logfile.m_pParent != nullptr && sv_logfile.m_pParent->m_Value.m_nValue != 0 )
      {
        ConMsg(a1: "file");
        v2 = 1;
      }
      if ( sv_logecho.m_pParent != nullptr && sv_logecho.m_pParent->m_Value.m_nValue != 0 )
      {
        if ( v2 != 0 )
        {
          ConMsg(a1: ", console");
        }
        else
        {
          ConMsg(a1: "console");
          v2 = 1;
        }
      }
      if ( g_Log.m_LogAddresses.m_Size > 0 )
      {
        if ( v2 == 0 )
        {
          ConMsg(a1: "udp");
          ConMsg(a1: "\n");
          return;
        }
        ConMsg(a1: ", udp");
      }
      if ( v2 == 0 )
      {
        ConMsg(a1: "no destinations! (file, console, or udp)\n");
        ConMsg(a1: "check \"sv_logfile\", \"sv_logecho\", and \"logaddress_list\"");
      }
      ConMsg(a1: "\n");
    }
    else
    {
      ConMsg(a1: "not currently logging\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123BB0
// Name: logaddress_del
// Source: json
//------------------------------------------------------------------------------
void __cdecl logaddress_del(const CCommand *args)
{
  int m_nArgc; // eax
  const char *v2; // edi
  const char *v3; // esi
  char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  char szAdr[32]; // [esp+8h] [ebp-2Ch] BYREF
  netadr_s adr; // [esp+28h] [ebp-Ch] BYREF

  netadr_s::SetIP(this: &adr, unIP: 0);
  netadr_s::SetPort(this: &adr, newport: 0);
  netadr_s::SetType(this: &adr, newtype: NA_IP);
  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc == 4 || m_nArgc == 2 )
  {
    v2 = defaultValue;
    if ( m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    if ( m_nArgc == 4 )
    {
      v3 = args->m_ppArgv[3];
    }
    else
    {
      v4 = _V_strstr(s1: v2, search: ":");
      if ( v4 != nullptr )
        v3 = v4 + 1;
      else
        v3 = "27015";
    }
    if ( V_atoi(str: v3) != 0 )
    {
      if ( v2 != nullptr && *v2 != 0 )
      {
        V_snprintf(pDest: szAdr, maxLen: 32, pFormat: "%s:%s", v2, v3);
        if ( NET_StringToAdr(s: szAdr, a: &adr) != 0 )
        {
          if ( CLog::DelLogAddress(this: &g_Log, addr: adr) != 0 )
          {
            v5 = netadr_s::ToString(this: &adr, baseOnly: false);
            ConMsg(a1: "logaddress_del:  %s\n", v5);
          }
          else
          {
            v6 = netadr_s::ToString(this: &adr, baseOnly: false);
            ConMsg(a1: "logaddress_del:  address %s not found in the list\n", v6);
          }
        }
        else
        {
          ConMsg(a1: "logaddress_del:  unable to resolve %s\n", szAdr);
        }
      }
      else
      {
        ConMsg(a1: "logaddress_del:  unparseable address\n");
      }
    }
    else
    {
      ConMsg(a1: "logaddress_del:  must specify a valid port\n");
    }
  }
  else
  {
    ConMsg(a1: "Usage:  logaddress_del ip:port\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123D20
// Name: public: void CLog::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLog::Shutdown(CLog *this)
{
  int v2; // eax

  if ( this->m_hLogFile != nullptr )
  {
    CLog::Printf(this, fmt: "Log file closed\n");
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: this->m_hLogFile);
  }
  this->m_LogAddresses.m_Size = 0;
  this->m_hLogFile = nullptr;
  this->m_bActive = false;
  this->m_flLastLogFlush = realtime;
  this->m_bFlushLog = false;
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-flushlog", a3: 0) != 0 )
    this->m_bFlushLog = true;
  g_GameEventManager->RemoveListener(this: g_GameEventManager, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10123DA0
// Name: public: void CLog::PrintServerVars(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLog::PrintServerVars(CLog *this)
{
  ICvar::ICVarIteratorInternal *v2; // edi
  ConCommandBase *v3; // esi
  const char *m_pszName; // eax
  const char *v5; // eax
  const char *v6; // [esp-Ch] [ebp-10h]

  if ( this->m_bActive )
  {
    CLog::Printf(this, fmt: "server cvars start\n");
    v2 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
    v2->SetFirst(this: v2);
    while ( v2->IsValid(this: v2) )
    {
      v3 = v2->Get(this: v2);
      if ( !v3->IsCommand(this: v3) && v3->IsFlagSet(this: v3, a2: 256) )
      {
        if ( (v3->m_nFlags & 0x1000) != 0 )
        {
          m_pszName = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          m_pszName = v3[1].m_pNext[1].m_pszName;
          if ( m_pszName == nullptr )
            m_pszName = defaultValue;
        }
        v5 = (const char *)((int (__thiscall *)(ConCommandBase *, const char *))v3->GetName)(a1: v3, a2: m_pszName);
        CLog::Printf(this, fmt: "\"%s\" = \"%s\"\n", v5, v6);
      }
      v2->Next(this: v2);
    }
    CLog::Printf(this, fmt: "server cvars end\n");
    free(pMem: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10123EC0
// Name: public: bool CLog::AddLogAddress(struct netadr_s)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLog::AddLogAddress(CLog *this, netadr_s addr)
{
  int v3; // edi
  int v4; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  netadr_s *m_pMemory; // ecx
  int v9; // eax
  netadr_s *v10; // eax

  v3 = 0;
  if ( this->m_LogAddresses.m_Size > 0 )
  {
    v4 = 0;
    do
    {
      if ( netadr_s::CompareAdr(this: &this->m_LogAddresses.m_Memory.m_pMemory[v4], a: &addr, onlyBase: false) )
        break;
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_LogAddresses.m_Size );
    if ( v3 < this->m_LogAddresses.m_Size )
      return 0;
  }
  m_Size = this->m_LogAddresses.m_Size;
  m_nAllocationCount = this->m_LogAddresses.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&this->m_LogAddresses,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_LogAddresses.m_Size;
  m_pMemory = this->m_LogAddresses.m_Memory.m_pMemory;
  v9 = this->m_LogAddresses.m_Size - m_Size - 1;
  this->m_LogAddresses.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v9);
  v10 = &this->m_LogAddresses.m_Memory.m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = addr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10123F70
// Name: logaddress_add
// Source: json
//------------------------------------------------------------------------------
void __cdecl logaddress_add(const CCommand *args)
{
  int m_nArgc; // eax
  const char *v2; // edi
  const char *v3; // esi
  char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  char szAdr[32]; // [esp+8h] [ebp-2Ch] BYREF
  netadr_s adr; // [esp+28h] [ebp-Ch] BYREF

  netadr_s::SetIP(this: &adr, unIP: 0);
  netadr_s::SetPort(this: &adr, newport: 0);
  netadr_s::SetType(this: &adr, newtype: NA_IP);
  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc == 4 || m_nArgc == 2 )
  {
    v2 = defaultValue;
    if ( m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    if ( m_nArgc == 4 )
    {
      v3 = args->m_ppArgv[3];
    }
    else
    {
      v4 = _V_strstr(s1: v2, search: ":");
      if ( v4 != nullptr )
        v3 = v4 + 1;
      else
        v3 = "27015";
    }
    if ( V_atoi(str: v3) != 0 )
    {
      if ( v2 != nullptr && *v2 != 0 )
      {
        V_snprintf(pDest: szAdr, maxLen: 32, pFormat: "%s:%s", v2, v3);
        if ( NET_StringToAdr(s: szAdr, a: &adr) != 0 )
        {
          if ( CLog::AddLogAddress(this: &g_Log, addr: adr) != 0 )
          {
            v5 = netadr_s::ToString(this: &adr, baseOnly: false);
            ConMsg(a1: "logaddress_add:  %s\n", v5);
          }
          else
          {
            v6 = netadr_s::ToString(this: &adr, baseOnly: false);
            ConMsg(a1: "logaddress_add:  %s is already in the list\n", v6);
          }
        }
        else
        {
          ConMsg(a1: "logaddress_add:  unable to resolve %s\n", szAdr);
        }
      }
      else
      {
        ConMsg(a1: "logaddress_add:  unparseable address\n");
      }
    }
    else
    {
      ConMsg(a1: "logaddress_add:  must specify a valid port\n");
    }
  }
  else
  {
    ConMsg(a1: "Usage:  logaddress_add ip:port\n");
  }
}

} // namespace engine_xlsp
