// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sv_filter.cpp
// Functions: 13
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1011DF00
// Name: void Filter_SendBan(struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Filter_SendBan(const netadr_s *adr)
{
  NET_OutOfBandPrintf(sock: 1, adr, format: "%cBanned by server\n", 108);
}

//------------------------------------------------------------------------------
// Address: 0x1011DF20
// Name: bool Filter_ConvertString(char const __near *,struct ipfilter_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Filter_ConvertString(char *s, ipfilter_t *f)
{
  int v3; // edi
  char v4; // al
  int v5; // ecx
  int v6; // edx
  unsigned __int8 v7; // al
  unsigned int v8; // edx
  char num[128]; // [esp+Ch] [ebp-88h] BYREF
  unsigned __int8 m[4]; // [esp+8Ch] [ebp-8h]
  unsigned __int8 b[4]; // [esp+90h] [ebp-4h]

  *(_DWORD *)m = 0;
  *(_DWORD *)b = 0;
  v3 = 0;
  while ( 1 )
  {
    v4 = *s;
    if ( *s < 48 || v4 > 57 )
      break;
    v5 = 0;
    v6 = num - s;
    do
    {
      if ( v4 > 57 )
        break;
      s[v6] = v4;
      v4 = *++s;
      ++v5;
    }
    while ( v4 >= 48 );
    num[v5] = 0;
    v7 = atoi(nptr: num);
    b[v3] = v7;
    if ( v7 != 0 )
      m[v3] = -1;
    if ( *s != 0 )
    {
      ++v3;
      ++s;
      if ( v3 < 4 )
        continue;
    }
    v8 = *(_DWORD *)b;
    f->mask = *(_DWORD *)m;
    f->compare = v8;
    return 1;
  }
  ConMsg(a1: "Bad filter address: %s\n", s);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1011DFD0
// Name: struct USERID_s __near * Filter_StringToUserID(char const __near *)
// Source: json
//------------------------------------------------------------------------------
USERID_s *__cdecl Filter_StringToUserID(const char *str)
{
  int v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  CCommand args; // [esp+4h] [ebp-588h] BYREF
  char szTemp[128]; // [esp+50Ch] [ebp-80h] BYREF

  _V_memset(dest: (void *)&id, fill: 0, count: 24);
  if ( str != nullptr && *str != 0 )
  {
    if ( V_strnicmp(s1: str, s2: "STEAM_", n: 6) == 0 )
    {
      v1 = _V_strlen(str: "STEAM_");
      V_strncpy(pDest: szTemp, pSrc: &str[v1], maxLen: 127);
      id.idtype = 1;
    }
    szTemp[127] = 0;
    CCommand::CCommand(this: &args);
    CCommand::Tokenize(this: &args, pCommand: szTemp, pBreakSet: nullptr);
    if ( args.m_nArgc >= 5 )
    {
      id.uid.steamid.m_SteamInstanceID = atoi(nptr: args.m_ppArgv[0]);
      v2 = defaultValue;
      if ( args.m_nArgc > 2 )
        v2 = args.m_ppArgv[2];
      id.uid.steamid.m_SteamLocalUserID.Split.High32bits = atoi(nptr: v2);
      v3 = defaultValue;
      if ( args.m_nArgc > 4 )
        v3 = args.m_ppArgv[4];
      id.uid.steamid.m_SteamLocalUserID.Split.Low32bits = atoi(nptr: v3);
    }
  }
  return &id;
}

//------------------------------------------------------------------------------
// Address: 0x1011E0E0
// Name: listip
// Source: json
//------------------------------------------------------------------------------
void __cdecl listip()
{
  int m_Size; // ebx
  int v1; // esi
  int v2; // edi
  unsigned int compare; // ecx

  m_Size = g_IPFilters.m_Size;
  if ( g_IPFilters.m_Size != 0 )
  {
    if ( g_IPFilters.m_Size == 1 )
      ConMsg(a1: "IP filter list: %i entry\n", 1);
    else
      ConMsg(a1: "IP filter list: %i entries\n", g_IPFilters.m_Size);
    if ( m_Size > 0 )
    {
      v1 = 1;
      v2 = 0;
      do
      {
        compare = g_IPFilters.m_Memory.m_pMemory[v2].compare;
        if ( g_IPFilters.m_Memory.m_pMemory[v2].banTime == 0.0 )
          ConMsg(
            a1: "%i %3i.%3i.%3i.%3i : permanent\n",
            v1,
            (unsigned __int8)compare,
            BYTE1(compare),
            BYTE2(compare),
            HIBYTE(compare));
        else
          ConMsg(
            a1: "%i %3i.%3i.%3i.%3i : %.3f min\n",
            v1,
            (unsigned __int8)compare,
            BYTE1(compare),
            BYTE2(compare),
            HIBYTE(compare),
            g_IPFilters.m_Memory.m_pMemory[v2].banTime);
        ++v2;
        ++v1;
        --m_Size;
      }
      while ( m_Size != 0 );
    }
  }
  else
  {
    ConMsg(a1: "IP filter list: empty\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E1C0
// Name: writeip
// Source: json
//------------------------------------------------------------------------------
void __cdecl writeip()
{
  void *v0; // edi
  ipfilter_t *m_pMemory; // edx
  int v2; // esi
  char name[260]; // [esp+8h] [ebp-108h] BYREF
  int i; // [esp+10Ch] [ebp-4h]

  V_strncpy(pDest: name, pSrc: "cfg/banned_ip.cfg", maxLen: 260);
  ConMsg(a1: "Writing %s.\n", name);
  v0 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: name, a3: "wb", a4: 0);
  if ( v0 != nullptr )
  {
    i = 0;
    if ( g_IPFilters.m_Size > 0 )
    {
      m_pMemory = g_IPFilters.m_Memory.m_pMemory;
      v2 = 0;
      do
      {
        if ( m_pMemory[v2].banTime == 0.0 )
        {
          g_pFileSystem->FPrintf(
            this: g_pFileSystem,
            a2: v0,
            a3: "addip 0 %i.%i.%i.%i\r\n",
            (unsigned __int8)m_pMemory[v2].compare,
            BYTE1(m_pMemory[v2].compare),
            (unsigned __int8)BYTE2(m_pMemory[v2].compare),
            HIBYTE(m_pMemory[v2].compare));
          m_pMemory = g_IPFilters.m_Memory.m_pMemory;
        }
        ++v2;
        ++i;
      }
      while ( i < g_IPFilters.m_Size );
    }
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v0);
  }
  else
  {
    ConMsg(a1: "Couldn't open %s\n", name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E2D0
// Name: writeid
// Source: json
//------------------------------------------------------------------------------
void __cdecl writeid()
{
  int v0; // ebx
  void *v1; // edi
  IFileSystem_vtbl *v2; // esi
  const char *UserIDString; // eax
  char name[260]; // [esp+Ch] [ebp-108h] BYREF
  int i; // [esp+110h] [ebp-4h]

  V_strncpy(pDest: name, pSrc: "cfg/banned_user.cfg", maxLen: 260);
  ConMsg(a1: "Writing %s.\n", name);
  v0 = 0;
  v1 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: name, a3: "wb", a4: 0);
  if ( v1 != nullptr )
  {
    for ( i = 0; i < g_UserFilters.m_Size; ++i )
    {
      if ( g_UserFilters.m_Memory.m_pMemory[v0].banTime == 0.0 )
      {
        v2 = g_pFileSystem->IAppSystem::__vftable;
        UserIDString = GetUserIDString(id: &g_UserFilters.m_Memory.m_pMemory[v0].userid);
        v2->FPrintf(this: g_pFileSystem, a2: v1, a3: "banid 0 %s\r\n", UserIDString);
      }
      ++v0;
    }
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v1);
  }
  else
  {
    ConMsg(a1: "Couldn't open %s\n", name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E3C0
// Name: listid
// Source: json
//------------------------------------------------------------------------------
void __cdecl listid()
{
  int m_Size; // edi
  int v1; // esi
  int v2; // ebx
  char *v3; // eax
  char *UserIDString; // eax
  double banTime; // [esp-10h] [ebp-14h]

  m_Size = g_UserFilters.m_Size;
  if ( g_UserFilters.m_Size != 0 )
  {
    if ( g_UserFilters.m_Size == 1 )
      ConMsg(a1: "ID filter list: %i entry\n", 1);
    else
      ConMsg(a1: "ID filter list: %i entries\n", g_UserFilters.m_Size);
    if ( m_Size > 0 )
    {
      v1 = 1;
      v2 = 0;
      do
      {
        if ( g_UserFilters.m_Memory.m_pMemory[v2].banTime == 0.0 )
        {
          UserIDString = GetUserIDString(id: &g_UserFilters.m_Memory.m_pMemory[v2].userid);
          ConMsg(a1: "%i %s : permanent\n", v1, UserIDString);
        }
        else
        {
          banTime = g_UserFilters.m_Memory.m_pMemory[v2].banTime;
          v3 = GetUserIDString(id: &g_UserFilters.m_Memory.m_pMemory[v2].userid);
          ConMsg(a1: "%i %s : %.3f min\n", v1, v3, banTime);
        }
        ++v2;
        ++v1;
        --m_Size;
      }
      while ( m_Size != 0 );
    }
  }
  else
  {
    ConMsg(a1: "ID filter list: empty\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E4F0
// Name: bool Filter_ShouldDiscard(struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Filter_ShouldDiscard(const netadr_s *adr)
{
  int m_nValue; // eax
  int v3; // ebx
  int v4; // esi
  int i; // edi
  ipfilter_t *v6; // ecx
  float banEndTime; // xmm0_4
  bool v8; // [esp+3h] [ebp-1h]

  if ( sv_filterban.m_pParent == nullptr )
    return false;
  m_nValue = sv_filterban.m_pParent->m_Value.m_nValue;
  if ( m_nValue == 0 )
    return false;
  v3 = *(_DWORD *)adr->ip;
  v8 = m_nValue == 1;
  v4 = g_IPFilters.m_Size - 1;
  if ( g_IPFilters.m_Size - 1 < 0 )
    return !v8;
  for ( i = v4; ; --i )
  {
    v6 = &g_IPFilters.m_Memory.m_pMemory[i];
    if ( g_IPFilters.m_Memory.m_pMemory[i].compare != -1 )
    {
      banEndTime = v6->banEndTime;
      if ( banEndTime != 0.0 && realtime >= banEndTime )
      {
        if ( g_IPFilters.m_Size - v4 - 1 > 0 )
          _V_memmove(dest: &g_IPFilters.m_Memory.m_pMemory[i], src: &v6[1], count: 16 * (g_IPFilters.m_Size - v4 - 1));
        --g_IPFilters.m_Size;
        goto LABEL_13;
      }
    }
    if ( (v3 & v6->mask) == v6->compare )
      break;
LABEL_13:
    if ( --v4 < 0 )
      return !v8;
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1011E5B0
// Name: removeip
// Source: json
//------------------------------------------------------------------------------
void __usercall removeip(int a1@<ebx>, int a2@<esi>, const CCommand *args)
{
  const char *v3; // eax
  bool v4; // zf
  char *v5; // eax
  int v6; // eax
  int v7; // esi
  const char *v8; // eax
  IGameEvent *v9; // esi
  int m_Size; // edx
  int v11; // ecx
  ipfilter_t *m_pMemory; // eax
  const char *v13; // edi
  const char *v14; // eax
  IGameEvent *v15; // eax
  IGameEvent *v16; // esi
  const char *v17; // eax
  char *m_Name; // eax
  char pDest[16]; // [esp+4h] [ebp-20h] BYREF
  ipfilter_t f; // [esp+14h] [ebp-10h] BYREF

  if ( args->m_nArgc >= 1 )
  {
    v3 = defaultValue;
    if ( args->m_nArgc > 1 )
      v3 = args->m_ppArgv[1];
    v4 = _V_strstr(s1: v3, search: ".") == nullptr;
    v5 = (char *)defaultValue;
    if ( v4 )
    {
      if ( args->m_nArgc > 1 )
        v5 = (char *)args->m_ppArgv[1];
      v6 = V_atoi(str: v5);
      if ( v6 <= 0 || v6 > g_IPFilters.m_Size )
      {
        ConMsg(a1: "removeip:  invalid slot %i\n", v6);
      }
      else
      {
        v7 = v6 - 1;
        V_snprintf(
          pDest,
          maxLen: 32,
          pFormat: "%3i.%3i.%3i.%3i",
          (unsigned __int8)g_IPFilters.m_Memory.m_pMemory[v7].compare,
          BYTE1(g_IPFilters.m_Memory.m_pMemory[v7].compare),
          (unsigned __int8)BYTE2(g_IPFilters.m_Memory.m_pMemory[v7].compare),
          HIBYTE(g_IPFilters.m_Memory.m_pMemory[v7].compare));
        CUtlVector<ipfilter_t,CUtlMemory<ipfilter_t,int>>::Remove(this: &g_IPFilters, elem: v7);
        v8 = defaultValue;
        if ( args->m_nArgc > 1 )
          v8 = args->m_ppArgv[1];
        ConMsg(a1: "removeip:  filter removed for %s, IP %s\n", v8, pDest);
        v9 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_removeban", a3: 0, a4: 0);
        if ( v9 != nullptr )
        {
          ((void (__thiscall *)(IGameEvent *, const char *, const char *, int))v9->SetString)(
            a1: v9,
            a2: "networkid",
            a3: defaultValue,
            a4: a2);
          v9->SetString(this: v9, a2: "ip", a3: pDest);
          ((void (__thiscall *)(IGameEvent *, const char *))v9->SetString)(a1: v9, a2: "by");
          g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v9, a3: false);
        }
      }
    }
    else
    {
      if ( args->m_nArgc > 1 )
        v5 = (char *)args->m_ppArgv[1];
      if ( Filter_ConvertString(s: v5, &f) != 0 )
      {
        m_Size = g_IPFilters.m_Size;
        v11 = 0;
        if ( g_IPFilters.m_Size <= 0 )
        {
LABEL_23:
          if ( args->m_nArgc > 1 )
            v13 = args->m_ppArgv[1];
          else
            v13 = defaultValue;
          ConMsg(a1: "removeip:  couldn't find %s\n", v13);
        }
        else
        {
          m_pMemory = g_IPFilters.m_Memory.m_pMemory;
          while ( m_pMemory->mask != f.mask || m_pMemory->compare != f.compare )
          {
            ++v11;
            ++m_pMemory;
            if ( v11 >= g_IPFilters.m_Size )
              goto LABEL_23;
          }
          if ( g_IPFilters.m_Size - v11 - 1 > 0 )
          {
            _V_memmove(
              dest: &g_IPFilters.m_Memory.m_pMemory[v11],
              src: &g_IPFilters.m_Memory.m_pMemory[v11 + 1],
              count: 16 * (g_IPFilters.m_Size - v11 - 1));
            m_Size = g_IPFilters.m_Size;
          }
          g_IPFilters.m_Size = m_Size - 1;
          v14 = defaultValue;
          if ( args->m_nArgc > 1 )
            v14 = args->m_ppArgv[1];
          ConMsg(a1: "removeip:  filter removed for %s\n", v14);
          v15 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_removeban", a3: 0, a4: 0);
          v16 = v15;
          if ( v15 != nullptr )
          {
            ((void (__thiscall *)(IGameEvent *, const char *, const char *, int, int))v15->SetString)(
              a1: v15,
              a2: "networkid",
              a3: defaultValue,
              a4: a1,
              a5: a2);
            v17 = defaultValue;
            if ( args->m_nArgc > 1 )
              v17 = args->m_ppArgv[1];
            v16->SetString(this: v16, a2: "ip", a3: v17);
            if ( cmd_source == src_command )
              m_Name = "Console";
            else
              m_Name = host_client->m_Name;
            v16->SetString(this: v16, a2: "by", a3: m_Name);
            g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v16, a3: false);
          }
        }
      }
    }
  }
  else
  {
    ConMsg(a1: "Usage:  removeip < slot | ipaddress >\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E890
// Name: bool Filter_IsUserBanned(struct USERID_s const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Filter_IsUserBanned(const USERID_s *userid)
{
  int m_nValue; // eax
  int v3; // esi
  int i; // edi
  float banEndTime; // xmm0_4
  CSteam3Server *v6; // eax
  userfilter_t *v7; // [esp-10h] [ebp-14h]
  bool v8; // [esp+3h] [ebp-1h]

  if ( sv_filterban.m_pParent == nullptr )
    return false;
  m_nValue = sv_filterban.m_pParent->m_Value.m_nValue;
  if ( m_nValue == 0 )
    return false;
  v8 = m_nValue == 1;
  v3 = g_UserFilters.m_Size - 1;
  if ( g_UserFilters.m_Size - 1 < 0 )
    return !v8;
  for ( i = v3; ; --i )
  {
    banEndTime = g_UserFilters.m_Memory.m_pMemory[i].banEndTime;
    if ( banEndTime != 0.0 && realtime >= banEndTime )
    {
      if ( g_UserFilters.m_Size - v3 - 1 > 0 )
        _V_memmove(
          dest: &g_UserFilters.m_Memory.m_pMemory[i],
          src: &g_UserFilters.m_Memory.m_pMemory[i + 1],
          count: 32 * (g_UserFilters.m_Size - v3 - 1));
      --g_UserFilters.m_Size;
      goto LABEL_12;
    }
    v7 = &g_UserFilters.m_Memory.m_pMemory[i];
    v6 = Steam3Server();
    if ( CSteam3Server::CompareUserID(this: v6, id1: userid, id2: &v7->userid) )
      break;
LABEL_12:
    if ( --v3 < 0 )
      return !v8;
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1011E950
// Name: removeid
// Source: json
//------------------------------------------------------------------------------
void __usercall removeid(int a1@<esi>, const CCommand *args)
{
  int m_nArgc; // eax
  const char *v3; // esi
  int v4; // eax
  int v5; // eax
  char *UserIDString; // eax
  IGameEvent *v7; // eax
  IGameEvent *v8; // esi
  IGameEvent_vtbl *v9; // edi
  char *v10; // eax
  int v11; // eax
  const char *v12; // eax
  const char *v13; // ecx
  const char *v14; // eax
  int v15; // esi
  int v16; // edi
  char *v17; // eax
  IGameEvent *v18; // eax
  char szSearchString[64]; // [esp+4h] [ebp-58h] BYREF
  USERID_s id; // [esp+44h] [ebp-18h] BYREF

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc != 2 && m_nArgc != 6 )
  {
    ConMsg(a1: "Usage:  removeid < slot | uniqueid >\n");
    return;
  }
  v3 = defaultValue;
  if ( m_nArgc > 1 )
    v3 = args->m_ppArgv[1];
  if ( V_strncmp(s1: v3, s2: "#", count: 1) == 0 )
  {
    ConMsg(a1: "Usage:  removeid < userid | uniqueid >\n");
    ConMsg(a1: "No # necessary\n");
    return;
  }
  if ( *v3 >= 48 && *v3 <= 57 )
  {
    v4 = V_atoi(str: v3);
    if ( v4 <= 0 || v4 > g_UserFilters.m_Size )
    {
      ConMsg(a1: "removeid:  invalid slot %i\n", v4);
      return;
    }
    v5 = v4 - 1;
    id = g_UserFilters.m_Memory.m_pMemory[v5].userid;
    CUtlVector<userfilter_t,CUtlMemory<userfilter_t,int>>::Remove(this: &g_UserFilters, elem: v5);
    UserIDString = GetUserIDString(&id);
    ConMsg(a1: "removeid:  filter removed for %s, ID %s\n", v3, UserIDString);
    v7 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_removeban", a3: 0, a4: 0);
    v8 = v7;
    if ( v7 == nullptr )
      return;
    v9 = v7->__vftable;
    v10 = GetUserIDString(&id);
    ((void (__thiscall *)(IGameEvent *, const char *, char *, int))v9->SetString)(
      a1: v8,
      a2: "networkid",
      a3: v10,
      a4: a1);
    goto LABEL_32;
  }
  v11 = _V_strlen(str: "STEAM_");
  if ( V_strnicmp(s1: v3, s2: "STEAM_", n: v11) != 0 )
    goto LABEL_33;
  v12 = defaultValue;
  if ( args->m_nArgc > 2 )
    v12 = args->m_ppArgv[2];
  if ( _V_strstr(s1: v12, search: ":") == nullptr )
  {
LABEL_33:
    ConMsg(a1: "removeid:  invalid ban ID \"%s\"\n", v3);
  }
  else
  {
    v13 = defaultValue;
    if ( args->m_nArgc > 5 )
      v13 = args->m_ppArgv[5];
    v14 = defaultValue;
    if ( args->m_nArgc > 3 )
      v14 = args->m_ppArgv[3];
    V_snprintf(pDest: szSearchString, maxLen: 64, pFormat: "%s:%s:%s", v3, v14, v13);
    v15 = 0;
    if ( g_UserFilters.m_Size <= 0 )
    {
LABEL_27:
      ConMsg(a1: "removeid:  couldn't find %s\n", szSearchString);
      return;
    }
    v16 = 0;
    while ( 1 )
    {
      v17 = GetUserIDString(id: &g_UserFilters.m_Memory.m_pMemory[v16].userid);
      if ( _V_stricmp(s1: v17, s2: szSearchString) == 0 )
        break;
      ++v15;
      ++v16;
      if ( v15 >= g_UserFilters.m_Size )
        goto LABEL_27;
    }
    if ( g_UserFilters.m_Size - v15 - 1 > 0 )
      _V_memmove(
        dest: &g_UserFilters.m_Memory.m_pMemory[v15],
        src: &g_UserFilters.m_Memory.m_pMemory[v15 + 1],
        count: 32 * (g_UserFilters.m_Size - v15 - 1));
    --g_UserFilters.m_Size;
    ConMsg(a1: "removeid:  filter removed for %s\n", szSearchString);
    v18 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_removeban", a3: 0, a4: 0);
    v8 = v18;
    if ( v18 != nullptr )
    {
      ((void (__thiscall *)(IGameEvent *, const char *, char *, int))v18->SetString)(
        a1: v18,
        a2: "networkid",
        a3: szSearchString,
        a4: a1);
LABEL_32:
      v8->SetString(this: v8, a2: "ip", a3: defaultValue);
      ((void (__thiscall *)(IGameEvent *, const char *))v8->SetString)(a1: v8, a2: "by");
      g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v8, a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011ECA0
// Name: Filter_Add_f
// Source: json
//------------------------------------------------------------------------------
void __usercall Filter_Add_f(int a1@<ebx>, const CCommand *args)
{
  float banEndTime; // edi
  const char *v3; // eax
  int m_Size; // eax
  int v5; // esi
  ipfilter_t *m_pMemory; // ebx
  unsigned int *p_compare; // ecx
  int v8; // eax
  const CCommand *v9; // ebx
  const char *v10; // eax
  long double v11; // st7
  float v12; // xmm0_4
  int v13; // esi
  long double v14; // st7
  char *v15; // eax
  int v16; // ebx
  CBaseClient *v17; // esi
  bool (__thiscall *IsActive)(IClient *); // eax
  IClient *v19; // esi
  int v20; // eax
  const netadr_s *v21; // eax
  IGameEvent *v22; // esi
  IGameEvent_vtbl *v23; // ebx
  int v24; // eax
  IGameEvent_vtbl *v25; // ebx
  int v26; // eax
  const char *v27; // eax
  char *m_Name; // eax
  char pDest[12]; // [esp+14h] [ebp-11Ch] BYREF
  char szDuration[256]; // [esp+20h] [ebp-110h] BYREF
  ipfilter_t f; // [esp+120h] [ebp-10h]

  banEndTime = 0.0;
  HIWORD(f.banTime) = 256;
  f.banEndTime = 0.0;
  v3 = defaultValue;
  if ( args->m_nArgc > 0 )
    v3 = args->m_ppArgv[0];
  if ( _V_stricmp(s1: v3, s2: "banip") == 0 )
    ConMsg(a1: "Note: should use \"addip\" instead of \"banip\".\n");
  if ( args->m_nArgc != 3 )
  {
    ConMsg(a1: "Usage:  addip < minutes > < ipaddress >\nUse 0 minutes for permanent\n");
    return;
  }
  if ( Filter_ConvertString(s: (char *)args->m_ppArgv[2], f: (ipfilter_t *)&szDuration[244]) != 0 )
  {
    m_Size = g_IPFilters.m_Size;
    v5 = 0;
    m_pMemory = g_IPFilters.m_Memory.m_pMemory;
    if ( g_IPFilters.m_Size > 0 )
    {
      p_compare = &g_IPFilters.m_Memory.m_pMemory->compare;
      do
      {
        if ( *p_compare == -1
          || *p_compare == *(_DWORD *)&szDuration[248] && *(p_compare - 1) == *(_DWORD *)&szDuration[244] )
        {
          break;
        }
        ++v5;
        p_compare += 4;
      }
      while ( v5 < g_IPFilters.m_Size );
      banEndTime = f.banEndTime;
    }
    if ( v5 == g_IPFilters.m_Size )
    {
      if ( g_IPFilters.m_Size == 0x8000 )
      {
        ConMsg(a1: "addip:  IP filter list is full\n");
        return;
      }
      v5 = g_IPFilters.m_Size;
      if ( g_IPFilters.m_Size + 1 > g_IPFilters.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CPortalRect,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&g_IPFilters,
          num: g_IPFilters.m_Size - g_IPFilters.m_Memory.m_nAllocationCount + 1);
        m_Size = g_IPFilters.m_Size;
        m_pMemory = g_IPFilters.m_Memory.m_pMemory;
      }
      g_IPFilters.m_Size = m_Size + 1;
      v8 = m_Size - v5;
      g_IPFilters.m_pElements = m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 16 * v8);
    }
    else
    {
      HIBYTE(f.banTime) = 0;
    }
    v9 = args;
    v10 = defaultValue;
    if ( args->m_nArgc > 1 )
      v10 = args->m_ppArgv[1];
    v11 = atof(nptr: v10);
    *(float *)&f.compare = v11;
    if ( v11 >= 0.0099999998 )
    {
      v12 = *(float *)&f.compare;
    }
    else
    {
      v12 = 0.0;
      f.compare = 0;
      v11 = 0.0;
    }
    v13 = v5;
    g_IPFilters.m_Memory.m_pMemory[v13].banTime = v12;
    if ( v12 == 0.0 )
      v14 = 0.0;
    else
      v14 = v11 * 60.0 + realtime;
    g_IPFilters.m_Memory.m_pMemory[v13].banEndTime = v14;
    v15 = (char *)defaultValue;
    if ( args->m_nArgc > 2 )
      v15 = (char *)args->m_ppArgv[2];
    if ( Filter_ConvertString(s: v15, f: &g_IPFilters.m_Memory.m_pMemory[v13]) == 0 )
      g_IPFilters.m_Memory.m_pMemory[v13].compare = -1;
    if ( HIBYTE(f.banTime) != 0 )
    {
      v16 = 0;
      if ( sv.m_Clients.m_Size > 0 )
      {
        while ( 1 )
        {
          v17 = sv.m_Clients.m_Memory.m_pMemory[v16];
          LODWORD(f.banEndTime) = v17;
          if ( v17 != nullptr )
          {
            IsActive = v17->IsActive;
            v19 = &v17->IClient;
            if ( IsActive(this: v19)
              && v19->IsConnected(this: v19)
              && v19->IsSpawned(this: v19)
              && !v19->IsFakeClient(this: v19) )
            {
              v20 = (int)v19->GetNetChannel(this: v19);
              v21 = (const netadr_s *)(*(int (__thiscall **)(int))(*(_DWORD *)v20 + 196))(a1: v20);
              if ( Filter_ShouldDiscard(adr: v21) )
                break;
            }
          }
          if ( ++v16 >= sv.m_Clients.m_Size )
            goto LABEL_46;
        }
        BYTE2(f.banTime) = 1;
LABEL_46:
        banEndTime = f.banEndTime;
      }
      v9 = args;
    }
    if ( *(float *)&f.compare == 0.0 )
      V_snprintf(pDest, maxLen: 256, pFormat: "permanently");
    else
      V_snprintf(pDest, maxLen: 256, pFormat: "for %.2f minutes", *(float *)&f.compare);
    v22 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_addban", a3: 0, a4: 0);
    if ( v22 != nullptr )
    {
      if ( BYTE2(f.banTime) == 0 || banEndTime == 0.0 )
      {
        ((void (__thiscall *)(IGameEvent *, const char *, const char *, int))v22->SetString)(
          a1: v22,
          a2: "name",
          a3: defaultValue,
          a4: a1);
        v22->SetInt(this: v22, a2: "userid", a3: 0);
        v22->SetString(this: v22, a2: "networkid", a3: defaultValue);
      }
      else
      {
        ((void (__thiscall *)(IGameEvent *, const char *, int, int))v22->SetString)(
          a1: v22,
          a2: "name",
          a3: LODWORD(banEndTime) + 52,
          a4: a1);
        v23 = v22->__vftable;
        v24 = (*(int (__thiscall **)(int))(*(_DWORD *)(LODWORD(banEndTime) + 4) + 60))(a1: LODWORD(banEndTime) + 4);
        v23->SetInt(this: v22, a2: "userid", a3: v24);
        v25 = v22->__vftable;
        v26 = (*(int (__thiscall **)(int))(*(_DWORD *)(LODWORD(banEndTime) + 4) + 84))(a1: LODWORD(banEndTime) + 4);
        v25->SetString(this: v22, a2: "networkid", a3: (const char *)v26);
        banEndTime = f.banEndTime;
        v9 = args;
      }
      v27 = defaultValue;
      if ( v9->m_nArgc > 2 )
        v27 = v9->m_ppArgv[2];
      v22->SetString(this: v22, a2: "ip", a3: v27);
      v22->SetString(this: v22, a2: "duration", a3: pDest);
      if ( cmd_source == src_command )
        m_Name = "Console";
      else
        m_Name = host_client->m_Name;
      v22->SetString(this: v22, a2: "by", a3: m_Name);
      ((void (__thiscall *)(IGameEvent *, const char *))v22->SetBool)(a1: v22, a2: "kicked");
      g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v22, a3: false);
    }
    if ( HIBYTE(f.banTime) != 0 && BYTE2(f.banTime) != 0 && banEndTime != 0.0 )
    {
      (*(void (__cdecl **)(int, const char *))(*(_DWORD *)(LODWORD(banEndTime) + 4) + 120))(
        a1: LODWORD(banEndTime) + 4,
        a2: "The server operator has added you to the banned list.\n");
      (*(void (__cdecl **)(int, const char *))(*(_DWORD *)(LODWORD(banEndTime) + 4) + 52))(
        a1: LODWORD(banEndTime) + 4,
        a2: "Added to banned list");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F0E0
// Name: banid
// Source: json
//------------------------------------------------------------------------------
void __usercall banid(int a1@<ebx>, int a2@<esi>, const CCommand *args)
{
  unsigned __int16 *Low32bits; // edi
  int m_nArgc; // eax
  bool v5; // cc
  const char *v6; // eax
  double v7; // st7
  const char *v8; // ebx
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // ecx
  const char *v12; // esi
  int v13; // ebx
  CBaseClient *v14; // edi
  IClient_vtbl *v15; // edx
  int v16; // eax
  int v17; // eax
  const char *v18; // eax
  int v19; // eax
  int m_Size; // ecx
  int v21; // esi
  int v22; // edi
  CSteam3Server *v23; // eax
  bool v24; // al
  float v25; // xmm0_4
  int v26; // esi
  bool v27; // zf
  double v28; // st7
  userfilter_t *v29; // eax
  IGameEvent *v30; // eax
  IGameEvent *v31; // esi
  int v32; // edi
  IGameEvent_vtbl *v33; // ebx
  int v34; // eax
  IGameEvent_vtbl *v35; // ebx
  int v36; // eax
  IGameEvent_vtbl *v37; // edi
  char *UserIDString; // eax
  char *m_Name; // eax
  BOOL v40; // eax
  int v41; // esi
  userfilter_t *v42; // [esp+0h] [ebp-1A0h]
  const USERID_s *v43; // [esp+4h] [ebp-19Ch]
  char pDest[24]; // [esp+10h] [ebp-190h] BYREF
  char szDuration[256]; // [esp+28h] [ebp-178h] BYREF
  char szSearchString[64]; // [esp+128h] [ebp-78h] BYREF
  userfilter_t nullUser; // [esp+168h] [ebp-38h] BYREF
  USERID_s localId; // [esp+188h] [ebp-18h]

  Low32bits = nullptr;
  *(_DWORD *)&localId.uid.steamid.m_SteamInstanceID = -1;
  HIBYTE(localId.uid.steamid.m_SteamLocalUserID.Split.High32bits) = 0;
  *(_QWORD *)(&localId.uid.steamid.m_SteamInstanceID + 2) = 0;
  if ( Steam3Server()->m_eServerMode == eServerModeNoAuthentication )
  {
    ConMsg(a1: "Can't ban users on a LAN\n");
    return;
  }
  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc < 3 || m_nArgc > 8 )
  {
    ConMsg(a1: "Usage:  banid < minutes > < userid | uniqueid > { kick }\n");
    ConMsg(a1: "Use 0 minutes for permanent\n");
  }
  else
  {
    v5 = m_nArgc <= 1;
    v6 = defaultValue;
    if ( !v5 )
      v6 = args->m_ppArgv[1];
    v7 = V_atof(str: v6);
    *((float *)&localId.idtype + 1) = v7;
    if ( v7 < 0.01 )
      *(&localId.idtype + 1) = 0;
    v8 = defaultValue;
    if ( args->m_nArgc > 2 )
      v8 = args->m_ppArgv[2];
    if ( V_strncmp(s1: v8, s2: "#", count: 1) == 0 )
    {
      ConMsg(a1: "Usage:  banid < minutes > < userid | uniqueid > { kick }\n");
      ConMsg(a1: "No # necessary\n");
      return;
    }
    if ( args->m_nArgc < 4
      || (v9 = CCommand::operator[](this: args, nIndex: args->m_nArgc - 1),
          BYTE2(localId.uid.steamid.m_SteamLocalUserID.Split.High32bits) = 1,
          V_strcasecmp(s1: v9, s2: "kick") != 0) )
    {
      BYTE2(localId.uid.steamid.m_SteamLocalUserID.Split.High32bits) = 0;
    }
    if ( *v8 < 48 || *v8 > 57 )
    {
      if ( V_strnicmp(s1: v8, s2: "STEAM_", n: 6) != 0 )
        goto LABEL_84;
      v10 = defaultValue;
      if ( args->m_nArgc > 3 )
        v10 = args->m_ppArgv[3];
      if ( _V_strstr(s1: v10, search: ":") == nullptr )
      {
LABEL_84:
        ConMsg(a1: "Can't ban users with ID \"%s\"\n", v8);
        return;
      }
      v11 = defaultValue;
      if ( args->m_nArgc > 6 )
        v11 = args->m_ppArgv[6];
      if ( args->m_nArgc > 4 )
        v12 = args->m_ppArgv[4];
      else
        v12 = defaultValue;
      V_snprintf(pDest: &szDuration[236], maxLen: 64, pFormat: "%s:%s:%s", v8, v12, v11);
    }
    else
    {
      *(_DWORD *)&localId.uid.steamid.m_SteamInstanceID = V_atoi(str: v8);
    }
    v13 = 0;
    if ( sv.m_Clients.m_Size > 0 )
    {
      while ( 1 )
      {
        v14 = sv.m_Clients.m_Memory.m_pMemory[v13];
        *((_DWORD *)&localId.uid.steamid.m_SteamInstanceID + 1) = v14;
        if ( v14 != nullptr
          && v14->IsActive(this: &v14->IClient)
          && v14->IsConnected(this: &v14->IClient)
          && v14->IsSpawned(this: &v14->IClient)
          && !v14->IsFakeClient(this: &v14->IClient) )
        {
          v15 = v14->IClient::INetChannelHandler::__vftable;
          if ( *(_DWORD *)&localId.uid.steamid.m_SteamInstanceID == -1 )
          {
            v18 = v15->GetNetworkIDString(this: &v14->IClient);
            if ( _V_stricmp(s1: v18, s2: &szDuration[236]) == 0 )
            {
              v19 = (int)v14->GetNetworkID(this: &v14->IClient, result: (const USERID_s *)&szSearchString[52]);
              *(_QWORD *)(&nullUser.userid.uid.steamid.m_SteamInstanceID + 2) = *(_QWORD *)v19;
              nullUser.userid.uid.steamid.m_SteamLocalUserID.Split.High32bits = *(_DWORD *)(v19 + 8);
              nullUser.banEndTime = *(float *)(v19 + 12);
              nullUser.banTime = *(float *)(v19 + 16);
              localId.idtype = *(_DWORD *)(v19 + 20);
              localId.uid.steamid.m_SteamLocalUserID.Split.Low32bits = (unsigned int)(&nullUser.userid.uid.steamid.m_SteamInstanceID
                                                                                    + 2);
              HIBYTE(localId.uid.steamid.m_SteamLocalUserID.Split.High32bits) = 1;
              Low32bits = &nullUser.userid.uid.steamid.m_SteamInstanceID + 2;
              goto LABEL_50;
            }
          }
          else
          {
            v16 = v15->GetUserID(this: &v14->IClient);
            if ( v16 == *(_DWORD *)&localId.uid.steamid.m_SteamInstanceID )
            {
              v17 = (int)v14->GetNetworkID(this: &v14->IClient, result: (const USERID_s *)&szSearchString[52]);
              *(_QWORD *)(&nullUser.userid.uid.steamid.m_SteamInstanceID + 2) = *(_QWORD *)v17;
              nullUser.userid.uid.steamid.m_SteamLocalUserID.Split.High32bits = *(_DWORD *)(v17 + 8);
              nullUser.banEndTime = *(float *)(v17 + 12);
              nullUser.banTime = *(float *)(v17 + 16);
              localId.idtype = *(_DWORD *)(v17 + 20);
              localId.uid.steamid.m_SteamLocalUserID.Split.Low32bits = (unsigned int)(&nullUser.userid.uid.steamid.m_SteamInstanceID
                                                                                    + 2);
              HIBYTE(localId.uid.steamid.m_SteamLocalUserID.Split.High32bits) = 1;
              Low32bits = &nullUser.userid.uid.steamid.m_SteamInstanceID + 2;
              break;
            }
          }
        }
        if ( ++v13 >= sv.m_Clients.m_Size )
        {
          Low32bits = (unsigned __int16 *)localId.uid.steamid.m_SteamLocalUserID.Split.Low32bits;
          break;
        }
      }
    }
    if ( *(_DWORD *)&localId.uid.steamid.m_SteamInstanceID == -1 )
    {
      if ( Low32bits == nullptr )
      {
        localId.uid.steamid.m_SteamLocalUserID.Split.Low32bits = (unsigned int)Filter_StringToUserID(str: &szDuration[236]);
        if ( localId.uid.steamid.m_SteamLocalUserID.Split.Low32bits == 0 )
        {
          ConMsg(a1: "banid:  Couldn't resolve uniqueid \"%s\".\n", &szDuration[236]);
          ConMsg(a1: "Usage:  banid < minutes > < userid | uniqueid > { kick }\n");
          ConMsg(a1: "Use 0 minutes for permanent\n");
          return;
        }
        Low32bits = (unsigned __int16 *)localId.uid.steamid.m_SteamLocalUserID.Split.Low32bits;
      }
LABEL_50:
      m_Size = g_UserFilters.m_Size;
      v21 = 0;
      if ( g_UserFilters.m_Size <= 0 )
      {
LABEL_57:
        if ( m_Size >= 0x8000 )
        {
          ConMsg(a1: "banid:  user filter list is full\n");
          return;
        }
        memset(&szSearchString[44], 0, 20);
        memset(&nullUser, 0, 12);
        v21 = CUtlVector<userfilter_t,CUtlMemory<userfilter_t,int>>::InsertBefore(
                this: &g_UserFilters,
                elem: m_Size,
                src: (const userfilter_t *)&szSearchString[44]);
      }
      else
      {
        v22 = 0;
        while ( 1 )
        {
          v43 = (const USERID_s *)localId.uid.steamid.m_SteamLocalUserID.Split.Low32bits;
          v42 = &g_UserFilters.m_Memory.m_pMemory[v22];
          v23 = Steam3Server();
          v24 = CSteam3Server::CompareUserID(this: v23, id1: &v42->userid, id2: v43);
          m_Size = g_UserFilters.m_Size;
          if ( v24 )
            break;
          ++v21;
          ++v22;
          if ( v21 >= g_UserFilters.m_Size )
            goto LABEL_56;
        }
        if ( v21 >= g_UserFilters.m_Size )
        {
LABEL_56:
          Low32bits = (unsigned __int16 *)localId.uid.steamid.m_SteamLocalUserID.Split.Low32bits;
          goto LABEL_57;
        }
        Low32bits = (unsigned __int16 *)localId.uid.steamid.m_SteamLocalUserID.Split.Low32bits;
      }
      v25 = *((float *)&localId.idtype + 1);
      v26 = v21;
      v27 = *((float *)&localId.idtype + 1) == 0.0;
      g_UserFilters.m_Memory.m_pMemory[v26].banTime = *((float *)&localId.idtype + 1);
      if ( v27 )
        v28 = 0.0;
      else
        v28 = *((float *)&localId.idtype + 1) * 60.0 + realtime;
      g_UserFilters.m_Memory.m_pMemory[v26].banEndTime = v28;
      v29 = &g_UserFilters.m_Memory.m_pMemory[v26];
      v29->userid.idtype = *(_DWORD *)Low32bits;
      *(&v29->userid.idtype + 1) = *((_DWORD *)Low32bits + 1);
      *(_DWORD *)&v29->userid.uid.steamid.m_SteamInstanceID = *((_DWORD *)Low32bits + 2);
      *((_DWORD *)&v29->userid.uid.steamid.m_SteamInstanceID + 1) = *((_DWORD *)Low32bits + 3);
      v29->userid.uid.steamid.m_SteamLocalUserID.Split.Low32bits = *((_DWORD *)Low32bits + 4);
      v29->userid.uid.steamid.m_SteamLocalUserID.Split.High32bits = *((_DWORD *)Low32bits + 5);
      if ( v25 == 0.0 )
        V_snprintf(pDest: &pDest[4], maxLen: 256, pFormat: "permanently");
      else
        V_snprintf(pDest: &pDest[4], maxLen: 256, pFormat: "for %.2f minutes", *((float *)&localId.idtype + 1));
      v30 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_addban", a3: 0, a4: 0);
      v31 = v30;
      if ( v30 != nullptr )
      {
        if ( HIBYTE(localId.uid.steamid.m_SteamLocalUserID.Split.High32bits) != 0 )
        {
          ((void (__thiscall *)(IGameEvent *, const char *, int, int, int))v30->SetString)(
            a1: v30,
            a2: "name",
            a3: *((_DWORD *)&localId.uid.steamid.m_SteamInstanceID + 1) + 52,
            a4: a1,
            a5: a2);
          v32 = *((_DWORD *)&localId.uid.steamid.m_SteamInstanceID + 1);
          v33 = v31->__vftable;
          v34 = (*(int (__thiscall **)(int))(*(_DWORD *)(*((_DWORD *)&localId.uid.steamid.m_SteamInstanceID + 1) + 4)
                                           + 60))(a1: *((_DWORD *)&localId.uid.steamid.m_SteamInstanceID + 1) + 4);
          v33->SetInt(this: v31, a2: "userid", a3: v34);
          v35 = v31->__vftable;
          v36 = (*(int (__thiscall **)(int))(*(_DWORD *)(v32 + 4) + 84))(a1: v32 + 4);
          v35->SetString(this: v31, a2: "networkid", a3: (const char *)v36);
        }
        else
        {
          ((void (__thiscall *)(IGameEvent *, const char *, const char *, int, int))v30->SetString)(
            a1: v30,
            a2: "name",
            a3: defaultValue,
            a4: a1,
            a5: a2);
          v31->SetInt(this: v31, a2: "userid", a3: 0);
          v37 = v31->__vftable;
          UserIDString = GetUserIDString(id: (const USERID_s *)localId.uid.steamid.m_SteamLocalUserID.Split.Low32bits);
          v37->SetString(this: v31, a2: "networkid", a3: UserIDString);
        }
        v31->SetString(this: v31, a2: "ip", a3: defaultValue);
        v31->SetString(this: v31, a2: "duration", a3: &pDest[4]);
        if ( cmd_source == src_command )
          m_Name = "Console";
        else
          m_Name = host_client->m_Name;
        v31->SetString(this: v31, a2: "by", a3: m_Name);
        v40 = BYTE2(localId.uid.steamid.m_SteamLocalUserID.Split.High32bits) != 0
           && HIBYTE(localId.uid.steamid.m_SteamLocalUserID.Split.High32bits) != 0
           && *((_DWORD *)&localId.uid.steamid.m_SteamInstanceID + 1) != 0;
        v31->SetInt(this: v31, a2: "kicked", a3: v40);
        g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v31, a3: false);
      }
      if ( BYTE2(localId.uid.steamid.m_SteamLocalUserID.Split.High32bits) != 0
        && HIBYTE(localId.uid.steamid.m_SteamLocalUserID.Split.High32bits) != 0
        && *((_DWORD *)&localId.uid.steamid.m_SteamInstanceID + 1) != 0 )
      {
        v41 = *((_DWORD *)&localId.uid.steamid.m_SteamInstanceID + 1) + 4;
        (*(void (**)(int, const char *, ...))(*(_DWORD *)(*((_DWORD *)&localId.uid.steamid.m_SteamInstanceID + 1) + 4)
                                            + 120))(
          a1: *((_DWORD *)&localId.uid.steamid.m_SteamInstanceID + 1) + 4,
          a2: "You have been kicked and banned %s by the server.\n",
          &pDest[4]);
        (*(void (__cdecl **)(int, const char *))(*(_DWORD *)v41 + 52))(a1: v41, a2: "Kicked and banned");
      }
    }
    else
    {
      if ( Low32bits != nullptr )
        goto LABEL_50;
      ConMsg(a1: "banid:  couldn't find userid %d\n", *(_DWORD *)&localId.uid.steamid.m_SteamInstanceID);
    }
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1011E0B0
// Name: void Filter_SendBan(struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Filter_SendBan(netadr_s *adr)
{
  NET_OutOfBandPrintf(sock: 1, adr, format: "%cBanned by server\n", 108);
}

//------------------------------------------------------------------------------
// Address: 0x1011E0D0
// Name: bool Filter_ConvertString(char const __near *,struct ipfilter_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Filter_ConvertString(char *s, ipfilter_t *f)
{
  int v3; // edi
  char v4; // al
  int v5; // ecx
  int v6; // edx
  unsigned __int8 v7; // al
  unsigned int v8; // edx
  char num[128]; // [esp+Ch] [ebp-88h] BYREF
  unsigned __int8 m[4]; // [esp+8Ch] [ebp-8h]
  unsigned __int8 b[4]; // [esp+90h] [ebp-4h]

  *(_DWORD *)m = 0;
  *(_DWORD *)b = 0;
  v3 = 0;
  while ( 1 )
  {
    v4 = *s;
    if ( *s < 48 || v4 > 57 )
      break;
    v5 = 0;
    v6 = num - s;
    do
    {
      if ( v4 > 57 )
        break;
      s[v6] = v4;
      v4 = *++s;
      ++v5;
    }
    while ( v4 >= 48 );
    num[v5] = 0;
    v7 = atoi(nptr: num);
    b[v3] = v7;
    if ( v7 != 0 )
      m[v3] = -1;
    if ( *s != 0 )
    {
      ++v3;
      ++s;
      if ( v3 < 4 )
        continue;
    }
    v8 = *(_DWORD *)b;
    f->mask = *(_DWORD *)m;
    f->compare = v8;
    return 1;
  }
  ConMsg(a1: "Bad filter address: %s\n", s);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1011E180
// Name: struct USERID_s __near * Filter_StringToUserID(char const __near *)
// Source: json
//------------------------------------------------------------------------------
USERID_s *__cdecl Filter_StringToUserID(const char *str)
{
  int v1; // eax
  const char *v2; // eax
  const char *v3; // eax
  CCommand args; // [esp+4h] [ebp-588h] BYREF
  char szTemp[128]; // [esp+50Ch] [ebp-80h] BYREF

  _V_memset(dest: (void *)&id, fill: 0, count: 24);
  if ( str != nullptr && *str != 0 )
  {
    if ( V_strnicmp(s1: str, s2: "STEAM_", n: 6) == 0 )
    {
      v1 = _V_strlen(str: "STEAM_");
      V_strncpy(pDest: szTemp, pSrc: &str[v1], maxLen: 127);
      id.idtype = 1;
    }
    szTemp[127] = 0;
    CCommand::CCommand(this: &args);
    CCommand::Tokenize(this: &args, pCommand: szTemp, pBreakSet: nullptr);
    if ( args.m_nArgc >= 5 )
    {
      id.uid.steamid.m_SteamInstanceID = atoi(nptr: args.m_ppArgv[0]);
      v2 = defaultValue;
      if ( args.m_nArgc > 2 )
        v2 = args.m_ppArgv[2];
      id.uid.steamid.m_SteamLocalUserID.Split.High32bits = atoi(nptr: v2);
      v3 = defaultValue;
      if ( args.m_nArgc > 4 )
        v3 = args.m_ppArgv[4];
      id.uid.steamid.m_SteamLocalUserID.Split.Low32bits = atoi(nptr: v3);
    }
  }
  return &id;
}

//------------------------------------------------------------------------------
// Address: 0x1011E290
// Name: listip
// Source: json
//------------------------------------------------------------------------------
void __cdecl listip()
{
  int m_Size; // ebx
  int v1; // esi
  int v2; // edi
  unsigned int compare; // ecx

  m_Size = g_IPFilters.m_Size;
  if ( g_IPFilters.m_Size != 0 )
  {
    if ( g_IPFilters.m_Size == 1 )
      ConMsg(a1: "IP filter list: %i entry\n", 1);
    else
      ConMsg(a1: "IP filter list: %i entries\n", g_IPFilters.m_Size);
    if ( m_Size > 0 )
    {
      v1 = 1;
      v2 = 0;
      do
      {
        compare = g_IPFilters.m_Memory.m_pMemory[v2].compare;
        if ( g_IPFilters.m_Memory.m_pMemory[v2].banTime == 0.0 )
          ConMsg(
            a1: "%i %3i.%3i.%3i.%3i : permanent\n",
            v1,
            (unsigned __int8)compare,
            BYTE1(compare),
            BYTE2(compare),
            HIBYTE(compare));
        else
          ConMsg(
            a1: "%i %3i.%3i.%3i.%3i : %.3f min\n",
            v1,
            (unsigned __int8)compare,
            BYTE1(compare),
            BYTE2(compare),
            HIBYTE(compare),
            g_IPFilters.m_Memory.m_pMemory[v2].banTime);
        ++v2;
        ++v1;
        --m_Size;
      }
      while ( m_Size != 0 );
    }
  }
  else
  {
    ConMsg(a1: "IP filter list: empty\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E370
// Name: writeip
// Source: json
//------------------------------------------------------------------------------
void __cdecl writeip()
{
  void *v0; // edi
  ipfilter_t *m_pMemory; // edx
  int v2; // esi
  char name[260]; // [esp+8h] [ebp-108h] BYREF
  int i; // [esp+10Ch] [ebp-4h]

  V_strncpy(pDest: name, pSrc: "cfg/banned_ip.cfg", maxLen: 260);
  ConMsg(a1: "Writing %s.\n", name);
  v0 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: name, a3: "wb", a4: 0);
  if ( v0 != nullptr )
  {
    i = 0;
    if ( g_IPFilters.m_Size > 0 )
    {
      m_pMemory = g_IPFilters.m_Memory.m_pMemory;
      v2 = 0;
      do
      {
        if ( m_pMemory[v2].banTime == 0.0 )
        {
          g_pFileSystem->FPrintf(
            this: g_pFileSystem,
            a2: v0,
            a3: "addip 0 %i.%i.%i.%i\r\n",
            (unsigned __int8)m_pMemory[v2].compare,
            BYTE1(m_pMemory[v2].compare),
            (unsigned __int8)BYTE2(m_pMemory[v2].compare),
            HIBYTE(m_pMemory[v2].compare));
          m_pMemory = g_IPFilters.m_Memory.m_pMemory;
        }
        ++v2;
        ++i;
      }
      while ( i < g_IPFilters.m_Size );
    }
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v0);
  }
  else
  {
    ConMsg(a1: "Couldn't open %s\n", name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E480
// Name: writeid
// Source: json
//------------------------------------------------------------------------------
void __cdecl writeid()
{
  int v0; // ebx
  void *v1; // edi
  IFileSystem_vtbl *v2; // esi
  char *UserIDString; // eax
  char name[260]; // [esp+Ch] [ebp-108h] BYREF
  int i; // [esp+110h] [ebp-4h]

  V_strncpy(pDest: name, pSrc: "cfg/banned_user.cfg", maxLen: 260);
  ConMsg(a1: "Writing %s.\n", name);
  v0 = 0;
  v1 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: name, a3: "wb", a4: 0);
  if ( v1 != nullptr )
  {
    for ( i = 0; i < g_UserFilters.m_Size; ++i )
    {
      if ( g_UserFilters.m_Memory.m_pMemory[v0].banTime == 0.0 )
      {
        v2 = g_pFileSystem->IAppSystem::__vftable;
        UserIDString = GetUserIDString(id: &g_UserFilters.m_Memory.m_pMemory[v0].userid);
        v2->FPrintf(this: g_pFileSystem, a2: v1, a3: "banid 0 %s\r\n", UserIDString);
      }
      ++v0;
    }
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v1);
  }
  else
  {
    ConMsg(a1: "Couldn't open %s\n", name);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E570
// Name: listid
// Source: json
//------------------------------------------------------------------------------
void __cdecl listid()
{
  int m_Size; // edi
  int v1; // esi
  int v2; // ebx
  char *v3; // eax
  char *UserIDString; // eax
  double banTime; // [esp+0h] [ebp-14h]

  m_Size = g_UserFilters.m_Size;
  if ( g_UserFilters.m_Size != 0 )
  {
    if ( g_UserFilters.m_Size == 1 )
      ConMsg(a1: "ID filter list: %i entry\n", 1);
    else
      ConMsg(a1: "ID filter list: %i entries\n", g_UserFilters.m_Size);
    if ( m_Size > 0 )
    {
      v1 = 1;
      v2 = 0;
      do
      {
        if ( g_UserFilters.m_Memory.m_pMemory[v2].banTime == 0.0 )
        {
          UserIDString = GetUserIDString(id: &g_UserFilters.m_Memory.m_pMemory[v2].userid);
          ConMsg(a1: "%i %s : permanent\n", v1, UserIDString);
        }
        else
        {
          banTime = g_UserFilters.m_Memory.m_pMemory[v2].banTime;
          v3 = GetUserIDString(id: &g_UserFilters.m_Memory.m_pMemory[v2].userid);
          ConMsg(a1: "%i %s : %.3f min\n", v1, v3, banTime);
        }
        ++v2;
        ++v1;
        --m_Size;
      }
      while ( m_Size != 0 );
    }
  }
  else
  {
    ConMsg(a1: "ID filter list: empty\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011E6A0
// Name: bool Filter_ShouldDiscard(struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Filter_ShouldDiscard(const netadr_s *adr)
{
  int m_nValue; // eax
  int v3; // ebx
  int v4; // esi
  int i; // edi
  ipfilter_t *v6; // ecx
  float banEndTime; // xmm0_4
  bool bNegativeFilter; // [esp+3h] [ebp-1h]

  if ( sv_filterban.m_pParent == nullptr )
    return false;
  m_nValue = sv_filterban.m_pParent->m_Value.m_nValue;
  if ( m_nValue == 0 )
    return false;
  v3 = *(_DWORD *)adr->ip;
  bNegativeFilter = m_nValue == 1;
  v4 = g_IPFilters.m_Size - 1;
  if ( g_IPFilters.m_Size - 1 < 0 )
    return !bNegativeFilter;
  for ( i = v4; ; --i )
  {
    v6 = &g_IPFilters.m_Memory.m_pMemory[i];
    if ( g_IPFilters.m_Memory.m_pMemory[i].compare != -1 )
    {
      banEndTime = v6->banEndTime;
      if ( banEndTime != 0.0 && realtime >= banEndTime )
      {
        if ( g_IPFilters.m_Size - v4 - 1 > 0 )
          _V_memmove(dest: &g_IPFilters.m_Memory.m_pMemory[i], src: &v6[1], count: 16 * (g_IPFilters.m_Size - v4 - 1));
        --g_IPFilters.m_Size;
        goto LABEL_13;
      }
    }
    if ( (v3 & v6->mask) == v6->compare )
      break;
LABEL_13:
    if ( --v4 < 0 )
      return !bNegativeFilter;
  }
  return bNegativeFilter;
}

//------------------------------------------------------------------------------
// Address: 0x1011E760
// Name: removeip
// Source: json
//------------------------------------------------------------------------------
void __usercall removeip(int a1@<ebx>, int a2@<esi>, const CCommand *args)
{
  const char *v3; // eax
  bool v4; // zf
  char *v5; // eax
  int v6; // eax
  int v7; // esi
  const char *v8; // eax
  IGameEvent *v9; // esi
  int m_Size; // edx
  int v11; // ecx
  ipfilter_t *m_pMemory; // eax
  const char *v13; // edi
  const char *v14; // eax
  IGameEvent *v15; // eax
  IGameEvent *v16; // esi
  const char *v17; // eax
  char *m_Name; // eax
  char pDest[16]; // [esp+4h] [ebp-20h] BYREF
  ipfilter_t f; // [esp+14h] [ebp-10h] BYREF

  if ( args->m_nArgc >= 1 )
  {
    v3 = defaultValue;
    if ( args->m_nArgc > 1 )
      v3 = args->m_ppArgv[1];
    v4 = _V_strstr(s1: v3, search: ".") == nullptr;
    v5 = (char *)defaultValue;
    if ( v4 )
    {
      if ( args->m_nArgc > 1 )
        v5 = (char *)args->m_ppArgv[1];
      v6 = V_atoi(str: v5);
      if ( v6 <= 0 || v6 > g_IPFilters.m_Size )
      {
        ConMsg(a1: "removeip:  invalid slot %i\n", v6);
      }
      else
      {
        v7 = v6 - 1;
        V_snprintf(
          pDest,
          maxLen: 32,
          pFormat: "%3i.%3i.%3i.%3i",
          (unsigned __int8)g_IPFilters.m_Memory.m_pMemory[v7].compare,
          BYTE1(g_IPFilters.m_Memory.m_pMemory[v7].compare),
          (unsigned __int8)BYTE2(g_IPFilters.m_Memory.m_pMemory[v7].compare),
          HIBYTE(g_IPFilters.m_Memory.m_pMemory[v7].compare));
        CUtlVector<ipfilter_t,CUtlMemory<ipfilter_t,int>>::Remove(this: &g_IPFilters, elem: v7);
        v8 = defaultValue;
        if ( args->m_nArgc > 1 )
          v8 = args->m_ppArgv[1];
        ConMsg(a1: "removeip:  filter removed for %s, IP %s\n", v8, pDest);
        v9 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_removeban", a3: 0, a4: 0);
        if ( v9 != nullptr )
        {
          ((void (__thiscall *)(IGameEvent *, const char *, const char *, int))v9->SetString)(
            a1: v9,
            a2: "networkid",
            a3: defaultValue,
            a4: a2);
          v9->SetString(this: v9, a2: "ip", a3: pDest);
          ((void (__thiscall *)(IGameEvent *, const char *))v9->SetString)(a1: v9, a2: "by");
          g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v9, a3: false);
        }
      }
    }
    else
    {
      if ( args->m_nArgc > 1 )
        v5 = (char *)args->m_ppArgv[1];
      if ( Filter_ConvertString(s: v5, &f) != 0 )
      {
        m_Size = g_IPFilters.m_Size;
        v11 = 0;
        if ( g_IPFilters.m_Size <= 0 )
        {
LABEL_23:
          if ( args->m_nArgc > 1 )
            v13 = args->m_ppArgv[1];
          else
            v13 = defaultValue;
          ConMsg(a1: "removeip:  couldn't find %s\n", v13);
        }
        else
        {
          m_pMemory = g_IPFilters.m_Memory.m_pMemory;
          while ( m_pMemory->mask != f.mask || m_pMemory->compare != f.compare )
          {
            ++v11;
            ++m_pMemory;
            if ( v11 >= g_IPFilters.m_Size )
              goto LABEL_23;
          }
          if ( g_IPFilters.m_Size - v11 - 1 > 0 )
          {
            _V_memmove(
              dest: &g_IPFilters.m_Memory.m_pMemory[v11],
              src: &g_IPFilters.m_Memory.m_pMemory[v11 + 1],
              count: 16 * (g_IPFilters.m_Size - v11 - 1));
            m_Size = g_IPFilters.m_Size;
          }
          g_IPFilters.m_Size = m_Size - 1;
          v14 = defaultValue;
          if ( args->m_nArgc > 1 )
            v14 = args->m_ppArgv[1];
          ConMsg(a1: "removeip:  filter removed for %s\n", v14);
          v15 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_removeban", a3: 0, a4: 0);
          v16 = v15;
          if ( v15 != nullptr )
          {
            ((void (__thiscall *)(IGameEvent *, const char *, const char *, int, int))v15->SetString)(
              a1: v15,
              a2: "networkid",
              a3: defaultValue,
              a4: a1,
              a5: a2);
            v17 = defaultValue;
            if ( args->m_nArgc > 1 )
              v17 = args->m_ppArgv[1];
            v16->SetString(this: v16, a2: "ip", a3: v17);
            if ( cmd_source == src_command )
              m_Name = "Console";
            else
              m_Name = host_client->m_Name;
            v16->SetString(this: v16, a2: "by", a3: m_Name);
            g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v16, a3: false);
          }
        }
      }
    }
  }
  else
  {
    ConMsg(a1: "Usage:  removeip < slot | ipaddress >\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EA40
// Name: bool Filter_IsUserBanned(struct USERID_s const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Filter_IsUserBanned(const USERID_s *userid)
{
  int m_nValue; // eax
  int v3; // esi
  int i; // edi
  float banEndTime; // xmm0_4
  CSteam3Server *v6; // eax
  userfilter_t *v7; // [esp-10h] [ebp-14h]
  bool bNegativeFilter; // [esp+3h] [ebp-1h]

  if ( sv_filterban.m_pParent == nullptr )
    return false;
  m_nValue = sv_filterban.m_pParent->m_Value.m_nValue;
  if ( m_nValue == 0 )
    return false;
  bNegativeFilter = m_nValue == 1;
  v3 = g_UserFilters.m_Size - 1;
  if ( g_UserFilters.m_Size - 1 < 0 )
    return !bNegativeFilter;
  for ( i = v3; ; --i )
  {
    banEndTime = g_UserFilters.m_Memory.m_pMemory[i].banEndTime;
    if ( banEndTime != 0.0 && realtime >= banEndTime )
    {
      if ( g_UserFilters.m_Size - v3 - 1 > 0 )
        _V_memmove(
          dest: &g_UserFilters.m_Memory.m_pMemory[i],
          src: &g_UserFilters.m_Memory.m_pMemory[i + 1],
          count: 32 * (g_UserFilters.m_Size - v3 - 1));
      --g_UserFilters.m_Size;
      goto LABEL_12;
    }
    v7 = &g_UserFilters.m_Memory.m_pMemory[i];
    v6 = Steam3Server();
    if ( CSteam3Server::CompareUserID(this: v6, id1: userid, id2: &v7->userid) )
      break;
LABEL_12:
    if ( --v3 < 0 )
      return !bNegativeFilter;
  }
  return bNegativeFilter;
}

//------------------------------------------------------------------------------
// Address: 0x1011EB00
// Name: removeid
// Source: json
//------------------------------------------------------------------------------
void __usercall removeid(int a1@<esi>, const CCommand *args)
{
  int m_nArgc; // eax
  const char *v3; // esi
  int v4; // eax
  int v5; // eax
  char *UserIDString; // eax
  IGameEvent *v7; // eax
  IGameEvent *v8; // esi
  IGameEvent_vtbl *v9; // edi
  char *v10; // eax
  int v11; // eax
  const char *v12; // eax
  const char *v13; // ecx
  const char *v14; // eax
  int v15; // esi
  int v16; // edi
  char *v17; // eax
  IGameEvent *v18; // eax
  char szSearchString[64]; // [esp+4h] [ebp-58h] BYREF
  USERID_s id; // [esp+44h] [ebp-18h] BYREF

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc != 2 && m_nArgc != 6 )
  {
    ConMsg(a1: "Usage:  removeid < slot | uniqueid >\n");
    return;
  }
  v3 = defaultValue;
  if ( m_nArgc > 1 )
    v3 = args->m_ppArgv[1];
  if ( V_strncmp(s1: v3, s2: "#", count: 1) == 0 )
  {
    ConMsg(a1: "Usage:  removeid < userid | uniqueid >\n");
    ConMsg(a1: "No # necessary\n");
    return;
  }
  if ( *v3 >= 48 && *v3 <= 57 )
  {
    v4 = V_atoi(str: v3);
    if ( v4 <= 0 || v4 > g_UserFilters.m_Size )
    {
      ConMsg(a1: "removeid:  invalid slot %i\n", v4);
      return;
    }
    v5 = v4 - 1;
    id = g_UserFilters.m_Memory.m_pMemory[v5].userid;
    CUtlVector<userfilter_t,CUtlMemory<userfilter_t,int>>::Remove(this: &g_UserFilters, elem: v5);
    UserIDString = GetUserIDString(&id);
    ConMsg(a1: "removeid:  filter removed for %s, ID %s\n", v3, UserIDString);
    v7 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_removeban", a3: 0, a4: 0);
    v8 = v7;
    if ( v7 == nullptr )
      return;
    v9 = v7->__vftable;
    v10 = GetUserIDString(&id);
    ((void (__thiscall *)(IGameEvent *, const char *, char *, int))v9->SetString)(
      a1: v8,
      a2: "networkid",
      a3: v10,
      a4: a1);
    goto LABEL_32;
  }
  v11 = _V_strlen(str: "STEAM_");
  if ( V_strnicmp(s1: v3, s2: "STEAM_", n: v11) != 0 )
    goto LABEL_33;
  v12 = defaultValue;
  if ( args->m_nArgc > 2 )
    v12 = args->m_ppArgv[2];
  if ( _V_strstr(s1: v12, search: ":") == nullptr )
  {
LABEL_33:
    ConMsg(a1: "removeid:  invalid ban ID \"%s\"\n", v3);
  }
  else
  {
    v13 = defaultValue;
    if ( args->m_nArgc > 5 )
      v13 = args->m_ppArgv[5];
    v14 = defaultValue;
    if ( args->m_nArgc > 3 )
      v14 = args->m_ppArgv[3];
    V_snprintf(pDest: szSearchString, maxLen: 64, pFormat: "%s:%s:%s", v3, v14, v13);
    v15 = 0;
    if ( g_UserFilters.m_Size <= 0 )
    {
LABEL_27:
      ConMsg(a1: "removeid:  couldn't find %s\n", szSearchString);
      return;
    }
    v16 = 0;
    while ( 1 )
    {
      v17 = GetUserIDString(id: &g_UserFilters.m_Memory.m_pMemory[v16].userid);
      if ( _V_stricmp(s1: v17, s2: szSearchString) == 0 )
        break;
      ++v15;
      ++v16;
      if ( v15 >= g_UserFilters.m_Size )
        goto LABEL_27;
    }
    if ( g_UserFilters.m_Size - v15 - 1 > 0 )
      _V_memmove(
        dest: &g_UserFilters.m_Memory.m_pMemory[v15],
        src: &g_UserFilters.m_Memory.m_pMemory[v15 + 1],
        count: 32 * (g_UserFilters.m_Size - v15 - 1));
    --g_UserFilters.m_Size;
    ConMsg(a1: "removeid:  filter removed for %s\n", szSearchString);
    v18 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_removeban", a3: 0, a4: 0);
    v8 = v18;
    if ( v18 != nullptr )
    {
      ((void (__thiscall *)(IGameEvent *, const char *, char *, int))v18->SetString)(
        a1: v18,
        a2: "networkid",
        a3: szSearchString,
        a4: a1);
LABEL_32:
      v8->SetString(this: v8, a2: "ip", a3: defaultValue);
      ((void (__thiscall *)(IGameEvent *, const char *))v8->SetString)(a1: v8, a2: "by");
      g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v8, a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011EE50
// Name: Filter_Add_f
// Source: json
//------------------------------------------------------------------------------
void __usercall Filter_Add_f(int a1@<ebx>, const CCommand *args)
{
  CGameClient *v2; // edi
  const char *v3; // eax
  int m_Size; // eax
  int v5; // esi
  ipfilter_t *m_pMemory; // ebx
  unsigned int *p_compare; // ecx
  int v8; // eax
  const CCommand *v9; // ebx
  const char *v10; // eax
  long double v11; // st7
  float v12; // xmm0_4
  int v13; // esi
  long double v14; // st7
  char *v15; // eax
  int v16; // ebx
  CGameClient *v17; // esi
  bool (__thiscall *IsActive)(IClient *); // eax
  IClient *v19; // esi
  int v20; // eax
  const netadr_s *v21; // eax
  IGameEvent *v22; // esi
  IGameEvent_vtbl *v23; // ebx
  int v24; // eax
  IGameEvent_vtbl *v25; // ebx
  int v26; // eax
  const char *v27; // eax
  char *m_Name; // eax
  char szDuration[256]; // [esp+14h] [ebp-11Ch] BYREF
  ipfilter_t f; // [esp+114h] [ebp-1Ch] BYREF
  float banTime; // [esp+124h] [ebp-Ch]
  CGameClient *client; // [esp+128h] [ebp-8h]
  bool bFound; // [esp+12Eh] [ebp-2h]
  bool bKick; // [esp+12Fh] [ebp-1h]

  v2 = nullptr;
  bKick = true;
  bFound = false;
  client = nullptr;
  v3 = defaultValue;
  if ( args->m_nArgc > 0 )
    v3 = args->m_ppArgv[0];
  if ( _V_stricmp(s1: v3, s2: "banip") == 0 )
    ConMsg(a1: "Note: should use \"addip\" instead of \"banip\".\n");
  if ( args->m_nArgc != 3 )
  {
    ConMsg(a1: "Usage:  addip < minutes > < ipaddress >\nUse 0 minutes for permanent\n");
    return;
  }
  if ( Filter_ConvertString(s: (char *)args->m_ppArgv[2], &f) != 0 )
  {
    m_Size = g_IPFilters.m_Size;
    v5 = 0;
    m_pMemory = g_IPFilters.m_Memory.m_pMemory;
    if ( g_IPFilters.m_Size > 0 )
    {
      p_compare = &g_IPFilters.m_Memory.m_pMemory->compare;
      do
      {
        if ( *p_compare == -1 || *p_compare == f.compare && *(p_compare - 1) == f.mask )
          break;
        ++v5;
        p_compare += 4;
      }
      while ( v5 < g_IPFilters.m_Size );
      v2 = client;
    }
    if ( v5 == g_IPFilters.m_Size )
    {
      if ( g_IPFilters.m_Size == 0x8000 )
      {
        ConMsg(a1: "addip:  IP filter list is full\n");
        return;
      }
      v5 = g_IPFilters.m_Size;
      if ( g_IPFilters.m_Size + 1 > g_IPFilters.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CPortalRect,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&g_IPFilters,
          num: g_IPFilters.m_Size - g_IPFilters.m_Memory.m_nAllocationCount + 1);
        m_Size = g_IPFilters.m_Size;
        m_pMemory = g_IPFilters.m_Memory.m_pMemory;
      }
      g_IPFilters.m_Size = m_Size + 1;
      v8 = m_Size - v5;
      g_IPFilters.m_pElements = m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 16 * v8);
    }
    else
    {
      bKick = false;
    }
    v9 = args;
    v10 = defaultValue;
    if ( args->m_nArgc > 1 )
      v10 = args->m_ppArgv[1];
    v11 = atof(nptr: v10);
    banTime = v11;
    if ( v11 >= 0.0099999998 )
    {
      v12 = banTime;
    }
    else
    {
      v12 = 0.0;
      banTime = 0.0;
      v11 = 0.0;
    }
    v13 = v5;
    g_IPFilters.m_Memory.m_pMemory[v13].banTime = v12;
    if ( v12 == 0.0 )
      v14 = 0.0;
    else
      v14 = v11 * 60.0 + realtime;
    g_IPFilters.m_Memory.m_pMemory[v13].banEndTime = v14;
    v15 = (char *)defaultValue;
    if ( args->m_nArgc > 2 )
      v15 = (char *)args->m_ppArgv[2];
    if ( Filter_ConvertString(s: v15, f: &g_IPFilters.m_Memory.m_pMemory[v13]) == 0 )
      g_IPFilters.m_Memory.m_pMemory[v13].compare = -1;
    if ( bKick )
    {
      v16 = 0;
      if ( sv.m_Clients.m_Size > 0 )
      {
        while ( 1 )
        {
          v17 = (CGameClient *)sv.m_Clients.m_Memory.m_pMemory[v16];
          client = v17;
          if ( v17 != nullptr )
          {
            IsActive = v17->IsActive;
            v19 = &v17->IClient;
            if ( IsActive(this: v19)
              && v19->IsConnected(this: v19)
              && v19->IsSpawned(this: v19)
              && !v19->IsFakeClient(this: v19) )
            {
              v20 = (int)v19->GetNetChannel(this: v19);
              v21 = (const netadr_s *)(*(int (__thiscall **)(int))(*(_DWORD *)v20 + 196))(a1: v20);
              if ( Filter_ShouldDiscard(adr: v21) )
                break;
            }
          }
          if ( ++v16 >= sv.m_Clients.m_Size )
            goto LABEL_46;
        }
        bFound = true;
LABEL_46:
        v2 = client;
      }
      v9 = args;
    }
    if ( banTime == 0.0 )
      V_snprintf(pDest: szDuration, maxLen: 256, pFormat: "permanently");
    else
      V_snprintf(pDest: szDuration, maxLen: 256, pFormat: "for %.2f minutes", banTime);
    v22 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_addban", a3: 0, a4: 0);
    if ( v22 != nullptr )
    {
      if ( bFound && v2 != nullptr )
      {
        ((void (__thiscall *)(IGameEvent *, const char *, char *, int))v22->SetString)(
          a1: v22,
          a2: "name",
          a3: v2->m_Name,
          a4: a1);
        v23 = v22->__vftable;
        v24 = v2->GetUserID(this: &v2->IClient);
        v23->SetInt(this: v22, a2: "userid", a3: v24);
        v25 = v22->__vftable;
        v26 = (int)v2->GetNetworkIDString(this: &v2->IClient);
        v25->SetString(this: v22, a2: "networkid", a3: (const char *)v26);
        v2 = client;
        v9 = args;
      }
      else
      {
        ((void (__thiscall *)(IGameEvent *, const char *, const char *, int))v22->SetString)(
          a1: v22,
          a2: "name",
          a3: defaultValue,
          a4: a1);
        v22->SetInt(this: v22, a2: "userid", a3: 0);
        v22->SetString(this: v22, a2: "networkid", a3: defaultValue);
      }
      v27 = defaultValue;
      if ( v9->m_nArgc > 2 )
        v27 = v9->m_ppArgv[2];
      v22->SetString(this: v22, a2: "ip", a3: v27);
      v22->SetString(this: v22, a2: "duration", a3: szDuration);
      if ( cmd_source == src_command )
        m_Name = "Console";
      else
        m_Name = host_client->m_Name;
      v22->SetString(this: v22, a2: "by", a3: m_Name);
      ((void (__thiscall *)(IGameEvent *, const char *))v22->SetBool)(a1: v22, a2: "kicked");
      g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v22, a3: false);
    }
    if ( bKick && bFound && v2 != nullptr )
    {
      v2->ClientPrintf(this: &v2->IClient, a2: "The server operator has added you to the banned list.\n");
      v2->Disconnect(this: &v2->IClient, a2: "Added to banned list");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1011F290
// Name: banid
// Source: json
//------------------------------------------------------------------------------
void __usercall banid(int a1@<ebx>, int a2@<esi>, const CCommand *args)
{
  USERID_s *p_localId; // edi
  int m_nArgc; // eax
  bool v5; // cc
  const char *v6; // eax
  double v7; // st7
  const char *v8; // ebx
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // ecx
  const char *v12; // esi
  int v13; // ebx
  CGameClient *v14; // edi
  IClient_vtbl *v15; // edx
  int v16; // eax
  const char *v17; // eax
  int m_Size; // ecx
  int v19; // esi
  int v20; // edi
  CSteam3Server *v21; // eax
  bool v22; // al
  float v23; // xmm0_4
  int v24; // esi
  bool v25; // zf
  double v26; // st7
  userfilter_t *v27; // eax
  IGameEvent *v28; // eax
  IGameEvent *v29; // esi
  CGameClient *v30; // edi
  IGameEvent_vtbl *v31; // ebx
  int v32; // eax
  IGameEvent_vtbl *v33; // ebx
  int v34; // eax
  IGameEvent_vtbl *v35; // edi
  char *UserIDString; // eax
  char *m_Name; // eax
  BOOL v38; // eax
  IClient *v39; // esi
  userfilter_t *v40; // [esp+4h] [ebp-1A0h]
  USERID_s *v41; // [esp+8h] [ebp-19Ch]
  char szDuration[256]; // [esp+18h] [ebp-18Ch] BYREF
  char szSearchString[64]; // [esp+118h] [ebp-8Ch] BYREF
  userfilter_t nullUser; // [esp+158h] [ebp-4Ch] BYREF
  USERID_s localId; // [esp+178h] [ebp-2Ch] BYREF
  float banTime; // [esp+190h] [ebp-14h]
  int iSearchIndex; // [esp+194h] [ebp-10h]
  CGameClient *client; // [esp+198h] [ebp-Ch]
  USERID_s *id; // [esp+19Ch] [ebp-8h]
  bool bKick; // [esp+1A2h] [ebp-2h]
  bool bPlaying; // [esp+1A3h] [ebp-1h]

  p_localId = nullptr;
  id = nullptr;
  iSearchIndex = -1;
  bPlaying = false;
  client = nullptr;
  if ( Steam3Server()->m_eServerMode == eServerModeNoAuthentication )
  {
    ConMsg(a1: "Can't ban users on a LAN\n");
    return;
  }
  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc < 3 || m_nArgc > 8 )
  {
    ConMsg(a1: "Usage:  banid < minutes > < userid | uniqueid > { kick }\n");
    ConMsg(a1: "Use 0 minutes for permanent\n");
  }
  else
  {
    v5 = m_nArgc <= 1;
    v6 = defaultValue;
    if ( !v5 )
      v6 = args->m_ppArgv[1];
    v7 = V_atof(str: v6);
    banTime = v7;
    if ( v7 < 0.01 )
      banTime = 0.0;
    v8 = defaultValue;
    if ( args->m_nArgc > 2 )
      v8 = args->m_ppArgv[2];
    if ( V_strncmp(s1: v8, s2: "#", count: 1) == 0 )
    {
      ConMsg(a1: "Usage:  banid < minutes > < userid | uniqueid > { kick }\n");
      ConMsg(a1: "No # necessary\n");
      return;
    }
    if ( args->m_nArgc < 4
      || (v9 = CCommand::operator[](this: args, nIndex: args->m_nArgc - 1),
          bKick = true,
          V_strcasecmp(s1: v9, s2: "kick") != 0) )
    {
      bKick = false;
    }
    if ( *v8 < 48 || *v8 > 57 )
    {
      if ( V_strnicmp(s1: v8, s2: "STEAM_", n: 6) != 0 )
        goto LABEL_84;
      v10 = defaultValue;
      if ( args->m_nArgc > 3 )
        v10 = args->m_ppArgv[3];
      if ( _V_strstr(s1: v10, search: ":") == nullptr )
      {
LABEL_84:
        ConMsg(a1: "Can't ban users with ID \"%s\"\n", v8);
        return;
      }
      v11 = defaultValue;
      if ( args->m_nArgc > 6 )
        v11 = args->m_ppArgv[6];
      if ( args->m_nArgc > 4 )
        v12 = args->m_ppArgv[4];
      else
        v12 = defaultValue;
      V_snprintf(pDest: szSearchString, maxLen: 64, pFormat: "%s:%s:%s", v8, v12, v11);
    }
    else
    {
      iSearchIndex = V_atoi(str: v8);
    }
    v13 = 0;
    if ( sv.m_Clients.m_Size > 0 )
    {
      while ( 1 )
      {
        v14 = (CGameClient *)sv.m_Clients.m_Memory.m_pMemory[v13];
        client = v14;
        if ( v14 != nullptr
          && v14->IsActive(this: &v14->IClient)
          && v14->IsConnected(this: &v14->IClient)
          && v14->IsSpawned(this: &v14->IClient)
          && !v14->IsFakeClient(this: &v14->IClient) )
        {
          v15 = v14->CBaseClient::IClient::INetChannelHandler::__vftable;
          if ( iSearchIndex == -1 )
          {
            v17 = v15->GetNetworkIDString(this: &v14->IClient);
            if ( _V_stricmp(s1: v17, s2: szSearchString) == 0 )
            {
              localId = *v14->GetNetworkID(this: &v14->IClient, result: (const USERID_s *)&nullUser.userid.uid);
              id = &localId;
              bPlaying = true;
              p_localId = &localId;
              goto LABEL_50;
            }
          }
          else
          {
            v16 = v15->GetUserID(this: &v14->IClient);
            if ( v16 == iSearchIndex )
            {
              localId = *v14->GetNetworkID(this: &v14->IClient, result: (const USERID_s *)&nullUser.userid.uid);
              id = &localId;
              bPlaying = true;
              p_localId = &localId;
              break;
            }
          }
        }
        if ( ++v13 >= sv.m_Clients.m_Size )
        {
          p_localId = id;
          break;
        }
      }
    }
    if ( iSearchIndex == -1 )
    {
      if ( p_localId == nullptr )
      {
        id = Filter_StringToUserID(str: szSearchString);
        if ( id == nullptr )
        {
          ConMsg(a1: "banid:  Couldn't resolve uniqueid \"%s\".\n", szSearchString);
          ConMsg(a1: "Usage:  banid < minutes > < userid | uniqueid > { kick }\n");
          ConMsg(a1: "Use 0 minutes for permanent\n");
          return;
        }
        p_localId = id;
      }
LABEL_50:
      m_Size = g_UserFilters.m_Size;
      v19 = 0;
      if ( g_UserFilters.m_Size <= 0 )
      {
LABEL_57:
        if ( m_Size >= 0x8000 )
        {
          ConMsg(a1: "banid:  user filter list is full\n");
          return;
        }
        memset(&nullUser, 0, sizeof(nullUser));
        v19 = CUtlVector<userfilter_t,CUtlMemory<userfilter_t,int>>::InsertBefore(
                this: &g_UserFilters,
                elem: m_Size,
                src: &nullUser);
      }
      else
      {
        v20 = 0;
        while ( 1 )
        {
          v41 = id;
          v40 = &g_UserFilters.m_Memory.m_pMemory[v20];
          v21 = Steam3Server();
          v22 = CSteam3Server::CompareUserID(this: v21, id1: &v40->userid, id2: v41);
          m_Size = g_UserFilters.m_Size;
          if ( v22 )
            break;
          ++v19;
          ++v20;
          if ( v19 >= g_UserFilters.m_Size )
            goto LABEL_56;
        }
        if ( v19 >= g_UserFilters.m_Size )
        {
LABEL_56:
          p_localId = id;
          goto LABEL_57;
        }
        p_localId = id;
      }
      v23 = banTime;
      v24 = v19;
      v25 = banTime == 0.0;
      g_UserFilters.m_Memory.m_pMemory[v24].banTime = banTime;
      if ( v25 )
        v26 = 0.0;
      else
        v26 = banTime * 60.0 + realtime;
      g_UserFilters.m_Memory.m_pMemory[v24].banEndTime = v26;
      v27 = &g_UserFilters.m_Memory.m_pMemory[v24];
      v27->userid.idtype = p_localId->idtype;
      *(&v27->userid.idtype + 1) = *(&p_localId->idtype + 1);
      *(_DWORD *)&v27->userid.uid.steamid.m_SteamInstanceID = *(_DWORD *)&p_localId->uid.steamid.m_SteamInstanceID;
      *((_DWORD *)&v27->userid.uid.steamid.m_SteamInstanceID + 1) = *((_DWORD *)&p_localId->uid.steamid.m_SteamInstanceID
                                                                    + 1);
      v27->userid.uid.steamid.m_SteamLocalUserID.Split.Low32bits = p_localId->uid.steamid.m_SteamLocalUserID.Split.Low32bits;
      v27->userid.uid.steamid.m_SteamLocalUserID.Split.High32bits = p_localId->uid.steamid.m_SteamLocalUserID.Split.High32bits;
      if ( v23 == 0.0 )
        V_snprintf(pDest: szDuration, maxLen: 256, pFormat: "permanently");
      else
        V_snprintf(pDest: szDuration, maxLen: 256, pFormat: "for %.2f minutes", banTime);
      v28 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "server_addban", a3: 0, a4: 0);
      v29 = v28;
      if ( v28 != nullptr )
      {
        if ( bPlaying )
        {
          ((void (__thiscall *)(IGameEvent *, const char *, char *, int, int))v28->SetString)(
            a1: v28,
            a2: "name",
            a3: client->m_Name,
            a4: a1,
            a5: a2);
          v30 = client;
          v31 = v29->__vftable;
          v32 = client->GetUserID(this: &client->IClient);
          v31->SetInt(this: v29, a2: "userid", a3: v32);
          v33 = v29->__vftable;
          v34 = (int)v30->GetNetworkIDString(this: &v30->IClient);
          v33->SetString(this: v29, a2: "networkid", a3: (const char *)v34);
        }
        else
        {
          ((void (__thiscall *)(IGameEvent *, const char *, const char *, int, int))v28->SetString)(
            a1: v28,
            a2: "name",
            a3: defaultValue,
            a4: a1,
            a5: a2);
          v29->SetInt(this: v29, a2: "userid", a3: 0);
          v35 = v29->__vftable;
          UserIDString = GetUserIDString(id);
          v35->SetString(this: v29, a2: "networkid", a3: UserIDString);
        }
        v29->SetString(this: v29, a2: "ip", a3: defaultValue);
        v29->SetString(this: v29, a2: "duration", a3: szDuration);
        if ( cmd_source == src_command )
          m_Name = "Console";
        else
          m_Name = host_client->m_Name;
        v29->SetString(this: v29, a2: "by", a3: m_Name);
        v38 = bKick && bPlaying && client != nullptr;
        v29->SetInt(this: v29, a2: "kicked", a3: v38);
        g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v29, a3: false);
      }
      if ( bKick && bPlaying && client != nullptr )
      {
        v39 = &client->IClient;
        client->ClientPrintf(
          this: &client->IClient,
          a2: "You have been kicked and banned %s by the server.\n",
          szDuration);
        v39->Disconnect(this: v39, a2: "Kicked and banned");
      }
    }
    else
    {
      if ( p_localId != nullptr )
        goto LABEL_50;
      ConMsg(a1: "banid:  couldn't find userid %d\n", iSearchIndex);
    }
  }
}

} // namespace engine_xlsp
