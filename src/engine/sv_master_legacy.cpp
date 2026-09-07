// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sv_master_legacy.cpp
// Functions: 30
// ============================================================

#include "engine\sv_master_legacy.h"

//------------------------------------------------------------------------------
// Address: 0x101E26F0
// Name: void Info_RemoveKey(char __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Info_RemoveKey(char *s, const char *key)
{
  char *v3; // edi
  char v4; // al
  char *v5; // ecx
  char v6; // al
  char *i; // ecx
  char value[512]; // [esp+4h] [ebp-400h] BYREF
  char pkey[512]; // [esp+204h] [ebp-200h] BYREF

  if ( _V_strstr(s1: key, search: "\\") != nullptr )
  {
    _Msg(a1: "Can't use a key with a \\\n");
  }
  else
  {
    while ( 1 )
    {
      v3 = s;
      if ( *s == 92 )
        ++s;
      v4 = *s;
      v5 = pkey;
      if ( *s != 92 )
        break;
LABEL_8:
      v6 = *++s;
      *v5 = 0;
      for ( i = value; v6 != 92; ++i )
      {
        if ( v6 == 0 )
          break;
        v6 = *++s;
      }
      *i = 0;
      if ( _V_strcmp(s1: key, s2: pkey) == 0 )
      {
        _V_memmove(dest: v3, src: s, count: strlen(s) + 1);
        return;
      }
      if ( *s == 0 )
        return;
    }
    while ( v4 != 0 )
    {
      ++s;
      *v5 = v4;
      v4 = *s;
      ++v5;
      if ( *s == 92 )
        goto LABEL_8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E27C0
// Name: bool Info_IsKeyImportant(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Info_IsKeyImportant(const char *key)
{
  return *key == 42
      || _V_strcmp(s1: key, s2: "name") == 0
      || _V_strcmp(s1: key, s2: "model") == 0
      || _V_strcmp(s1: key, s2: "rate") == 0
      || _V_strcmp(s1: key, s2: "cl_updaterate") == 0
      || _V_strcmp(s1: key, s2: "cl_lw") == 0
      || _V_strcmp(s1: key, s2: "cl_lc") == 0
      || _V_strcmp(s1: key, s2: "tracker") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E2860
// Name: char __near * Info_FindLargestKey(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Info_FindLargestKey(char *s)
{
  char *v1; // esi
  int v2; // ebx
  char i; // al
  char *v4; // ecx
  int v5; // edi
  char v6; // al
  char *v7; // ecx
  bool v8; // zf
  int v9; // edi
  char value[256]; // [esp+Ch] [ebp-200h] BYREF
  char key[256]; // [esp+10Ch] [ebp-100h] BYREF

  v1 = s;
  v2 = 0;
  largest_key[0] = 0;
  if ( *s == 92 )
    v1 = s + 1;
  for ( i = *v1; *v1 != 0; i = *v1 )
  {
    v4 = key;
    if ( i != 0 )
    {
      do
      {
        if ( i == 92 )
          break;
        ++v1;
        *v4 = i;
        i = *v1;
        ++v4;
      }
      while ( *v1 != 0 );
    }
    *v4 = 0;
    v5 = _V_strlen(str: key);
    if ( *v1 == 0 )
      break;
    v6 = *++v1;
    v7 = value;
    if ( v6 != 0 )
    {
      do
      {
        if ( v6 == 92 )
          break;
        ++v1;
        *v7 = v6;
        v6 = *v1;
        ++v7;
      }
      while ( *v1 != 0 );
    }
    v8 = *v1 == 0;
    *v7 = 0;
    if ( !v8 )
      ++v1;
    v9 = _V_strlen(str: value) + v5;
    if ( v9 > v2
      && key[0] != 42
      && _V_strcmp(s1: key, s2: "name") != 0
      && _V_strcmp(s1: key, s2: "model") != 0
      && _V_strcmp(s1: key, s2: "rate") != 0
      && _V_strcmp(s1: key, s2: "cl_updaterate") != 0
      && _V_strcmp(s1: key, s2: "cl_lw") != 0
      && _V_strcmp(s1: key, s2: "cl_lc") != 0
      && _V_strcmp(s1: key, s2: "tracker") != 0 )
    {
      v2 = v9;
      V_strncpy(pDest: largest_key, pSrc: key, maxLen: 256);
    }
  }
  return largest_key;
}

//------------------------------------------------------------------------------
// Address: 0x101E2A00
// Name: void Info_SetValueForStarKey(char __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Info_SetValueForStarKey(char *s, const char *key, const char *value, int maxsize)
{
  int v4; // eax
  char *LargestKey; // ebx
  int v6; // eax
  char *v7; // esi
  char *v8; // edi
  int v9; // ebx
  char newArray[1024]; // [esp+8h] [ebp-404h] BYREF
  int v11; // [esp+408h] [ebp-4h]

  if ( _V_strstr(s1: key, search: "\\") != nullptr || _V_strstr(s1: value, search: "\\") != nullptr )
  {
    _Msg(a1: "Can't use keys or values with a \\\n");
    return;
  }
  if ( _V_strstr(s1: key, search: "\"") != nullptr || _V_strstr(s1: value, search: "\"") != nullptr )
  {
    _Msg(a1: "Can't use keys or values with a \"\n");
    return;
  }
  if ( _V_strlen(str: key) > 127 || _V_strlen(str: value) > 127 )
  {
    _Msg(a1: "Keys and values must be < %i characters.\n", 128);
    return;
  }
  Info_RemoveKey(s, key);
  if ( value != nullptr && _V_strlen(str: value) != 0 )
  {
    V_snprintf(pDest: newArray, maxLen: 1024, pFormat: "\\%s\\%s", key, value);
    v11 = _V_strlen(str: s);
    v4 = _V_strlen(str: newArray);
    if ( v4 + v11 >= maxsize )
    {
      if ( !Info_IsKeyImportant(key) )
        goto LABEL_15;
      while ( 1 )
      {
        LargestKey = Info_FindLargestKey(s);
        Info_RemoveKey(s, key: LargestKey);
        v11 = _V_strlen(str: s);
        v6 = _V_strlen(str: newArray);
        if ( v6 + v11 < maxsize )
          break;
        if ( *LargestKey == 0 )
          goto LABEL_15;
      }
      if ( *LargestKey == 0 )
      {
LABEL_15:
        _Msg(a1: "Info string length exceeded\n");
        return;
      }
    }
    v7 = &s[_V_strlen(str: s)];
    v8 = newArray;
    if ( newArray[0] == 0 )
    {
LABEL_25:
      *v7 = 0;
      return;
    }
    while ( 1 )
    {
      v9 = (unsigned __int8)*v8++;
      if ( _V_stricmp(s1: key, s2: "name") == 0 )
        goto LABEL_22;
      v9 &= 0x7Fu;
      if ( (unsigned int)(v9 - 32) <= 0x5F )
        break;
LABEL_24:
      if ( *v8 == 0 )
        goto LABEL_25;
    }
    if ( _V_stricmp(s1: key, s2: "team") == 0 )
      v9 = tolower(c: v9);
LABEL_22:
    if ( v9 > 13 )
      *v7++ = v9;
    goto LABEL_24;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E2C10
// Name: void Info_SetValueForKey(char __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Info_SetValueForKey(char *s, const char *key, const char *value, int maxsize)
{
  if ( *key == 42 )
    _Msg(a1: "Can't set * keys\n");
  else
    Info_SetValueForStarKey(s, key, value, maxsize);
}

//------------------------------------------------------------------------------
// Address: 0x101E2C50
// Name: public: virtual void CMaster::Init(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CMaster::Init(CMaster *this)
{
  int m_nValue; // eax
  unsigned int v3; // [esp-8h] [ebp-Ch]
  int v4; // [esp-4h] [ebp-8h]

  if ( mm_heartbeat_seconds.m_pParent != nullptr )
    m_nValue = mm_heartbeat_seconds.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  this->m_iHeartBeatTimeout = m_nValue;
  if ( sv.m_bIsDedicatedForXbox )
  {
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&sv_master_legacy_mode.IConVar, value: 1, a2: v3, a3: v4);
    if ( mm_heartbeat_seconds_xlsp.m_pParent != nullptr )
      this->m_iHeartBeatTimeout = mm_heartbeat_seconds_xlsp.m_pParent->m_Value.m_nValue;
    else
      this->m_iHeartBeatTimeout = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E2CA0
// Name: private: void CMaster::RebuildInfo(class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMaster::RebuildInfo(CMaster *this@<ecx>, int a2@<edi>, int a3@<esi>, CBaseServer *pServer)
{
  bf_write *p_m_Buffer; // esi
  unsigned int HostVersion; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  int SteamAppID; // eax
  const char *v12; // eax
  ISteamGameServer *m_pSteamGameServer; // ecx
  bool v14; // al
  const char *VersionString; // eax
  char v16; // bl
  const char *GameType; // eax
  unsigned __int16 UDPPort; // ax
  unsigned __int16 v19; // ax
  CBaseServer_vtbl *v20; // edx
  CBaseServer *v21; // ecx
  const char *v22; // eax
  char gd[260]; // [esp+0h] [ebp-138h] BYREF
  char verString[40]; // [esp+104h] [ebp-34h] BYREF
  int nMaxHumans; // [esp+12Ch] [ebp-Ch] BYREF
  int nHumans; // [esp+130h] [ebp-8h] BYREF
  int nBots; // [esp+134h] [ebp-4h] BYREF
  const char *pchGameType; // [esp+140h] [ebp+8h]

  this->m_InfoCache.m_flLastUpdateTime = realtime;
  bf_write::Reset(this: &this->m_InfoCache.m_Buffer);
  p_m_Buffer = &this->m_InfoCache.m_Buffer;
  bf_write::Reset(this: p_m_Buffer);
  bf_write::WriteLong(this: p_m_Buffer, val: -1);
  bf_write::WriteByte(this: p_m_Buffer, val: 0x49u);
  HostVersion = GetHostVersion();
  bf_write::WriteByte(this: p_m_Buffer, val: HostVersion);
  v8 = (const char *)((int (__thiscall *)(CBaseServer *, int, int))pServer->GetName)(a1: pServer, a2, a3);
  bf_write::WriteString(this: p_m_Buffer, pStr: v8);
  v9 = pServer->GetMapName(this: pServer);
  bf_write::WriteString(this: p_m_Buffer, pStr: v9);
  V_FileBase(in: com_gamedir, out: gd, maxlen: 260);
  bf_write::WriteString(this: p_m_Buffer, pStr: gd);
  v10 = serverGameDLL->GetGameDescription(this: serverGameDLL);
  bf_write::WriteString(this: p_m_Buffer, pStr: v10);
  SteamAppID = GetSteamAppID();
  bf_write::WriteShort(this: p_m_Buffer, val: SteamAppID);
  CBaseServer::GetMasterServerPlayerCounts(this: &sv, &nHumans, nMaxHumanSlots: &nMaxHumans, &nBots);
  bf_write::WriteByte(this: p_m_Buffer, val: nHumans);
  bf_write::WriteByte(this: p_m_Buffer, val: nMaxHumans);
  bf_write::WriteByte(this: p_m_Buffer, val: nBots);
  if ( pServer->IsHLTV(this: pServer) || pServer->IsReplay(this: pServer) )
  {
    bf_write::WriteByte(this: p_m_Buffer, val: 0x70u);
  }
  else if ( pServer->IsDedicated(this: pServer) )
  {
    bf_write::WriteByte(this: p_m_Buffer, val: 0x64u);
  }
  else
  {
    bf_write::WriteByte(this: p_m_Buffer, val: 0x6Cu);
  }
  bf_write::WriteByte(this: p_m_Buffer, val: 0x77u);
  v12 = pServer->GetPassword(this: pServer);
  bf_write::WriteByte(this: p_m_Buffer, val: v12 != nullptr);
  m_pSteamGameServer = Steam3Server()->m_pSteamGameServer;
  v14 = m_pSteamGameServer != nullptr
     && m_pSteamGameServer->BSecure(this: m_pSteamGameServer)
     && !pServer->IsHLTV(this: pServer);
  bf_write::WriteByte(this: p_m_Buffer, val: v14);
  VersionString = Sys_GetVersionString();
  V_snprintf(pDest: verString, maxLen: 40, pFormat: "%s", VersionString);
  bf_write::WriteString(this: p_m_Buffer, pStr: verString);
  v16 = 0;
  if ( sv.m_State > ss_dead )
    v16 = 0x80;
  if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
    v16 |= 0x40u;
  GameType = CBaseServer::GetGameType(this: &sv, eResultType: EGAMETYPE_RESULTS_INCLUDE_PUBLIC_ONLY);
  pchGameType = GameType;
  if ( GameType != nullptr && _V_strlen(str: GameType) > 0 )
    v16 |= 0x20u;
  bf_write::WriteByte(this: p_m_Buffer, val: (unsigned __int8)v16);
  if ( v16 < 0 )
  {
    UDPPort = NET_GetUDPPort(socket: 1);
    bf_write::WriteShort(this: p_m_Buffer, val: UDPPort);
  }
  if ( (v16 & 0x40) != 0 )
  {
    v19 = NET_GetUDPPort(socket: 2);
    bf_write::WriteShort(this: p_m_Buffer, val: v19);
    if ( hltv != nullptr )
    {
      v20 = hltv->CBaseServer::IServer::IConnectionlessPacketHandler::__vftable;
      v21 = &hltv->CBaseServer;
    }
    else
    {
      v20 = pServer->__vftable;
      v21 = pServer;
    }
    v22 = v20->GetName(this: v21);
    bf_write::WriteString(this: p_m_Buffer, pStr: v22);
  }
  if ( (v16 & 0x20) != 0 )
    bf_write::WriteString(this: p_m_Buffer, pStr: pchGameType);
}

//------------------------------------------------------------------------------
// Address: 0x101E2F20
// Name: private: void CMaster::RebuildRules(class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::RebuildRules(CMaster *this, CBaseServer *pServer)
{
  bf_write *p_m_Buffer; // ebx
  int v4; // esi
  ICvar::ICVarIteratorInternal *m_pIter; // edi
  ConCommandBase *v6; // esi
  const char *v7; // eax
  const char *m_pszName; // eax
  const char *v9; // eax
  const char *v10; // eax
  ICvar::Iterator iter; // [esp+0h] [ebp-4h]

  this->m_RulesCache.m_flLastUpdateTime = realtime;
  bf_write::Reset(this: &this->m_RulesCache.m_Buffer);
  p_m_Buffer = &this->m_RulesCache.m_Buffer;
  bf_write::Reset(this: &this->m_RulesCache.m_Buffer);
  v4 = CCvarUtilities::CountVariablesWithFlags(this: cv, flags: 256);
  if ( v4 > 0 )
  {
    bf_write::WriteLong(this: p_m_Buffer, val: -1);
    bf_write::WriteByte(this: p_m_Buffer, val: 0x45u);
    bf_write::WriteShort(this: p_m_Buffer, val: v4);
    m_pIter = g_pCVar->FactoryInternalIterator(this: g_pCVar);
    iter.m_pIter = m_pIter;
    m_pIter->SetFirst(this: m_pIter);
    while ( m_pIter->IsValid(this: m_pIter) )
    {
      v6 = m_pIter->Get(this: m_pIter);
      if ( !v6->IsCommand(this: v6) && v6->IsFlagSet(this: v6, a2: 256) )
      {
        v7 = v6->GetName(this: v6);
        bf_write::WriteString(this: p_m_Buffer, pStr: v7);
        if ( v6->IsFlagSet(this: v6, a2: 32) )
        {
          if ( (v6->m_nFlags & 0x1000) != 0 )
          {
            m_pszName = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            m_pszName = v6[1].m_pNext[1].m_pszName;
            if ( m_pszName == nullptr )
              m_pszName = defaultValue;
          }
          if ( strlen(m_pszName) == 0 )
            goto LABEL_17;
          if ( (v6->m_nFlags & 0x1000) != 0 )
          {
            v9 = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            v9 = v6[1].m_pNext[1].m_pszName;
            if ( v9 == nullptr )
              v9 = defaultValue;
          }
          if ( _V_stricmp(s1: v9, s2: "none") != 0 )
          {
            bf_write::WriteString(this: p_m_Buffer, pStr: "1");
            m_pIter = iter.m_pIter;
          }
          else
          {
LABEL_17:
            bf_write::WriteString(this: p_m_Buffer, pStr: "0");
            m_pIter = iter.m_pIter;
          }
        }
        else
        {
          if ( (v6->m_nFlags & 0x1000) != 0 )
          {
            v10 = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            v10 = v6[1].m_pNext[1].m_pszName;
            if ( v10 == nullptr )
              v10 = defaultValue;
          }
          bf_write::WriteString(this: p_m_Buffer, pStr: v10);
        }
      }
      m_pIter->Next(this: m_pIter);
    }
    free(pMem: m_pIter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E30E0
// Name: public: void CMaster::ReplyInfo(struct netadr_s __near &,class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::ReplyInfo(CMaster *this, netadr_s *adr, CBaseServer *pServer)
{
  if ( !CBaseServer::ShouldHideServer(this: pServer) )
  {
    if ( (float)(realtime - this->m_InfoCache.m_flLastUpdateTime) >= 0.25 )
      CMaster::RebuildInfo(this, a2: (int)pServer, a3: (int)this, pServer);
    if ( this->m_InfoCache.m_Buffer.m_iCurBit > 0 )
      NET_SendPacket(
        chan: nullptr,
        sock: pServer->m_Socket,
        to: adr,
        data: this->m_InfoCache.m_Buffer.m_pData,
        length: (this->m_InfoCache.m_Buffer.m_iCurBit + 7) >> 3,
        pVoicePayload: nullptr,
        bUseCompression: false,
        unMillisecondsDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E3150
// Name: public: void CMaster::ReplyRules(struct netadr_s __near &,class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::ReplyRules(CMaster *this, netadr_s *from, CBaseServer *pServer)
{
  if ( !CBaseServer::ShouldHideServer(this: pServer) )
  {
    if ( (float)(realtime - this->m_RulesCache.m_flLastUpdateTime) >= 0.25 )
      CMaster::RebuildRules(this, pServer);
    if ( this->m_RulesCache.m_Buffer.m_iCurBit > 0 )
      NET_SendPacket(
        chan: nullptr,
        sock: pServer->m_Socket,
        to: from,
        data: this->m_RulesCache.m_Buffer.m_pData,
        length: (this->m_RulesCache.m_Buffer.m_iCurBit + 7) >> 3,
        pVoicePayload: nullptr,
        bUseCompression: false,
        unMillisecondsDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E31D0
// Name: bool IsUsingMasterLegacyMode(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsUsingMasterLegacyMode()
{
  return sv_master_legacy_mode.m_pParent != nullptr && sv_master_legacy_mode.m_pParent->m_Value.m_nValue != 0
      || Steam3Server()->m_pSteamMasterServerUpdater == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101E3200
// Name: public: virtual void CMaster::InitConnection(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMaster::InitConnection(CMaster *this@<ecx>, int a2@<ebx>)
{
  int v3; // eax
  int v4; // eax
  const char *v5; // ebx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  IBaseFileSystem *v8; // eax
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // ebx
  const char *String; // edi
  const char *v12; // eax
  const char *SteamInstallPath; // eax
  HMODULE m_hSteamDLL; // eax
  FARPROC SteamFindServersNumServers; // edi
  unsigned int v16; // eax
  unsigned int v17; // ebx
  unsigned int v18; // edi
  const char *v19; // eax
  netadr_s *p_adr; // [esp-10h] [ebp-14Ch]
  int v21; // [esp-Ch] [ebp-148h]
  char szSteamDLLPath[260]; // [esp+4h] [ebp-138h] BYREF
  char szAdr[32]; // [esp+108h] [ebp-34h] BYREF
  int nCount; // [esp+128h] [ebp-14h]
  netadr_s adr; // [esp+12Ch] [ebp-10h] BYREF
  KeyValues *pKV; // [esp+138h] [ebp-4h]

  if ( bInitialized
    || (sv_master_legacy_mode.m_pParent == nullptr || sv_master_legacy_mode.m_pParent->m_Value.m_nValue == 0)
    && Steam3Server()->m_pSteamMasterServerUpdater != nullptr
    || this->m_bNoMasters )
  {
    return;
  }
  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-nomaster") != 0 )
  {
    ConMsg(a1: "Master server communication disabled.\n");
    this->m_bNoMasters = true;
    bInitialized = true;
    return;
  }
  v21 = a2;
  if ( sv.m_bIsDedicatedForXbox )
  {
    this->m_bNoMasters = true;
    bInitialized = true;
    v4 = _CommandLine();
    v5 = (const char *)(*(int (__thiscall **)(int, const char *, const char *, int))(*(_DWORD *)v4 + 32))(
                         a1: v4,
                         a2: "-xlsp",
                         a3: "UNKNOWN",
                         a4: a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
    {
      v7 = KeyValues::KeyValues(this: v6, setName: "TitleServers");
      pKV = v7;
    }
    else
    {
      pKV = nullptr;
      v7 = nullptr;
    }
    if ( g_pFileSystem != nullptr )
      v8 = &g_pFileSystem->IBaseFileSystem;
    else
      v8 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v7,
           filesystem: v8,
           resourceName: v5,
           pathID: "GAME",
           pfnEvaluateSymbolProc: nullptr) )
    {
      Key = KeyValues::FindKey(this: v7, keyName: "MasterServers", bCreate: false);
      if ( Key != nullptr )
      {
        FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
        if ( FirstSubKey != nullptr )
        {
          do
          {
            String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
            netadr_s::SetIP(this: &adr, unIP: 0);
            netadr_s::SetPort(this: &adr, newport: 0);
            netadr_s::SetType(this: &adr, newtype: NA_IP);
            if ( NET_StringToAdr(s: String, a: &adr) )
            {
              if ( netadr_s::GetPort(this: &adr) == 0 )
                netadr_s::SetPort(this: &adr, newport: 0x6983u);
              if ( this->AddServer(this, a2: &adr) )
              {
                v12 = netadr_s::ToString(this: &adr, baseOnly: false);
                ConMsg(a1: "Adding XLSP Master Server: %s\n", v12);
                this->m_bNoMasters = false;
              }
            }
            FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
          }
          while ( FirstSubKey != nullptr );
          KeyValues::deleteThis(this: pKV);
          return;
        }
      }
    }
    else
    {
      _Warning(a1: "**********************************************\n");
      _Warning(a1: "ERROR! XLSP config %s not found!\n", v5);
      _Warning(a1: "**********************************************\n");
    }
    KeyValues::deleteThis(this: v7);
    return;
  }
  if ( this->m_hSteamDLL == nullptr )
  {
    SteamInstallPath = (const char *)_SteamAPI_GetSteamInstallPath(a1: a2);
    if ( SteamInstallPath != nullptr )
    {
      V_ComposeFileName(path: SteamInstallPath, filename: "steam.dll", dest: szSteamDLLPath, destSize: 260);
      this->m_hSteamDLL = Sys_LoadModule(pModuleName: szSteamDLLPath);
    }
    if ( this->m_hSteamDLL == nullptr )
      this->m_hSteamDLL = Sys_LoadModule(pModuleName: "steam.dll");
  }
  m_hSteamDLL = (HMODULE)this->m_hSteamDLL;
  SteamFindServersNumServers = nullptr;
  pKV = nullptr;
  if ( m_hSteamDLL != nullptr )
  {
    SteamFindServersNumServers = GetProcAddress(hModule: m_hSteamDLL, lpProcName: "SteamFindServersNumServers");
    pKV = (KeyValues *)GetProcAddress(hModule: (HMODULE)this->m_hSteamDLL, lpProcName: "SteamFindServersIterateServer");
  }
  if ( this->m_hSteamDLL != nullptr && SteamFindServersNumServers != nullptr && pKV != nullptr )
  {
    v16 = ((int (__cdecl *)(int))SteamFindServersNumServers)(a1: 4);
    v17 = v16;
    v18 = 0;
    nCount = 0;
    if ( v16 != -1 && v16 != -2 )
    {
      bInitialized = true;
      if ( v16 >= 2 )
        v17 = 2;
      if ( v17 != 0 )
      {
        do
        {
          netadr_s::netadr_s(this: &adr);
          ((void (__cdecl *)(int, unsigned int, char *, int))pKV)(a1: 4, a2: v18, a3: szAdr, a4: 32);
          if ( NET_StringToAdr(s: szAdr, a: &adr) )
          {
            v19 = netadr_s::ToString(this: &adr, baseOnly: false);
            ConMsg(a1: "Adding master server %s\n", v19);
            p_adr = &adr;
            ((void (__thiscall *)(CMaster *))this->AddServer)(a1: this);
            ++nCount;
          }
          ++v18;
        }
        while ( v18 < v17 );
      }
      if ( NET_IsDedicated() && sv_region.m_pParent != nullptr && sv_region.m_pParent->m_Value.m_nValue == -1 )
        CLoaderMemAlloc::CrtIsValidPointer(
          this: (ConVar *)&sv_region.IConVar,
          value: 255,
          a2: (unsigned int)p_adr,
          a3: v21);
      bInitialized = true;
      if ( nCount == 0 )
      {
        ConMsg(a1: "No masters loaded\nUsing default master\n");
        this->UseDefault(this);
      }
    }
  }
  else
  {
    ConMsg(a1: "Unable to load Steam library.\n");
    this->m_bNoMasters = true;
    bInitialized = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E3590
// Name: public: virtual void CMaster::SetMaster_Legacy_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::SetMaster_Legacy_f(CMaster *this, const CCommand *args)
{
  int m_nArgc; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // esi
  const char *v7; // eax
  char *v8; // esi
  int v9; // esi
  const char *v10; // eax
  char *v11; // esi
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  char szMasterAddress[128]; // [esp+Ch] [ebp-94h] BYREF
  char *s1; // [esp+8Ch] [ebp-14h]
  const char **v17; // [esp+90h] [ebp-10h]
  netadr_s adr; // [esp+94h] [ebp-Ch] BYREF

  netadr_s::SetIP(this: &adr, unIP: 0);
  netadr_s::SetPort(this: &adr, newport: 0);
  netadr_s::SetType(this: &adr, newtype: NA_IP);
  m_nArgc = args->m_nArgc;
  this->InitConnection(this);
  if ( m_nArgc < 2 )
  {
    ConMsg(a1: "Usage:\nsetmaster <add | remove | enable | disable> <IP:port>\n");
    if ( this->m_MasterServers.m_Size != 0 )
    {
      ConMsg(a1: "Current:\n");
      v4 = 0;
      if ( this->m_MasterServers.m_Size > 0 )
      {
        v5 = 0;
        do
        {
          v6 = v4 + 1;
          v7 = netadr_s::ToString(this: &this->m_MasterServers.m_Memory.m_pMemory[v5].addr, baseOnly: false);
          ConMsg(a1: "  %i:  %s\n", v6, v7);
          v4 = v6;
          ++v5;
        }
        while ( v6 < this->m_MasterServers.m_Size );
      }
    }
    else
    {
      ConMsg(a1: "Current:  None\n");
    }
    return;
  }
  if ( args->m_nArgc <= 1 )
    return;
  v8 = (char *)args->m_ppArgv[1];
  s1 = v8;
  if ( v8 == nullptr || *v8 == 0 )
    return;
  szMasterAddress[0] = 0;
  netadr_s::Clear(this: &adr);
  v9 = 2;
  if ( m_nArgc > 2 )
  {
    v17 = &args->m_ppArgv[2];
    do
    {
      if ( v9 < 0 || v9 >= args->m_nArgc )
        v10 = defaultValue;
      else
        v10 = *v17;
      V_strncat(pDest: szMasterAddress, pSrc: v10, destBufferSize: 0x80u, max_chars_to_copy: -1);
      ++v17;
      ++v9;
    }
    while ( v9 < m_nArgc );
  }
  if ( _V_strlen(str: szMasterAddress) > 0 )
  {
    if ( !NET_StringToAdr(s: szMasterAddress, a: &adr) )
    {
      ConMsg(a1: " Invalid address \"%s\", setmaster command ignored\n", szMasterAddress);
      return;
    }
    if ( netadr_s::GetPort(this: &adr) == 0 )
      netadr_s::SetPort(this: &adr, newport: 0x6983u);
  }
  v11 = s1;
  if ( _V_stricmp(s1, s2: "disable") == 0 )
  {
    this->m_bNoMasters = true;
    return;
  }
  if ( _V_stricmp(s1: v11, s2: "enable") == 0 )
  {
LABEL_30:
    this->m_bNoMasters = false;
    return;
  }
  if ( _V_stricmp(s1: v11, s2: "add") == 0 )
  {
    if ( this->AddServer(this, a2: &adr) )
    {
      v12 = netadr_s::ToString(this: &adr, baseOnly: false);
      ConMsg(a1: "Adding master at %s\n", v12);
      this->m_bNoMasters = false;
      return;
    }
    v13 = netadr_s::ToString(this: &adr, baseOnly: false);
    ConMsg(a1: "Master at %s already in list\n", v13);
    goto LABEL_30;
  }
  if ( _V_stricmp(s1: v11, s2: "remove") != 0 )
  {
    ConMsg(a1: "Invalid setmaster command\n");
  }
  else if ( !this->RemoveServer(this, a2: &adr) )
  {
    v14 = netadr_s::ToString(this: &adr, baseOnly: false);
    ConMsg(a1: "Can't remove master %s, not in list\n", v14);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E3820
// Name: public: virtual void CMaster::Heartbeat_Legacy_f(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::Heartbeat_Legacy_f(CMaster *this)
{
  int v1; // ebx
  CMasterserver *m_pMemory; // esi
  int v3; // edi
  CMasterserver *v4; // eax
  int v5; // edx
  int i; // [esp+4h] [ebp-4h]

  v1 = 0;
  i = 0;
  if ( this->m_MasterServers.m_Size > 0 )
  {
    m_pMemory = this->m_MasterServers.m_Memory.m_pMemory;
    do
    {
      v3 = 0;
      v4 = &m_pMemory[v1];
      if ( m_pMemory[v1].heartbeats.m_Size > 0 )
      {
        v5 = 0;
        do
        {
          v4->heartbeats.m_Memory.m_pMemory[v5].last_heartbeat = -9999.0;
          m_pMemory = this->m_MasterServers.m_Memory.m_pMemory;
          ++v3;
          v4 = &m_pMemory[v1];
          ++v5;
        }
        while ( v3 < m_pMemory[v1].heartbeats.m_Size );
      }
      ++v1;
      ++i;
    }
    while ( i < this->m_MasterServers.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E3880
// Name: public: virtual bool CMaster::IsMasterServerAddress(struct netadr_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMaster::IsMasterServerAddress(CMaster *this, netadr_s *from)
{
  int v3; // ebx
  int i; // edi

  v3 = 0;
  if ( this->m_MasterServers.m_Size <= 0 )
    return 0;
  for ( i = 0; !netadr_s::CompareAdr(this: from, a: &this->m_MasterServers.m_Memory.m_pMemory[i].addr, onlyBase: false); ++i )
  {
    if ( ++v3 >= this->m_MasterServers.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E38C0
// Name: public: virtual bool CMaster::IsCorrectMasterChallenge(struct netadr_s __near *,int,class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMaster::IsCorrectMasterChallenge(
        CMaster *this,
        netadr_s *from,
        CBaseServer *challenge,
        CBaseServer *pServer)
{
  int v4; // edi
  CMasterserver *m_pMemory; // eax
  int m_Size; // edx
  int v8; // ecx
  CBaseServer **p_pServer; // eax
  int i; // [esp+Ch] [ebp-4h]

  v4 = 0;
  i = 0;
  if ( this->m_MasterServers.m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    if ( netadr_s::CompareAdr(this: &this->m_MasterServers.m_Memory.m_pMemory[v4].addr, a: from, onlyBase: false) )
    {
      m_pMemory = this->m_MasterServers.m_Memory.m_pMemory;
      m_Size = m_pMemory[v4].heartbeats.m_Size;
      v8 = 0;
      if ( m_Size > 0 )
        break;
    }
LABEL_8:
    ++v4;
    if ( ++i >= this->m_MasterServers.m_Size )
      return 0;
  }
  p_pServer = &m_pMemory[v4].heartbeats.m_Memory.m_pMemory->pServer;
  while ( *(p_pServer - 2) != challenge || *p_pServer != pServer )
  {
    ++v8;
    p_pServer += 4;
    if ( v8 >= m_Size )
      goto LABEL_8;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E3940
// Name: public: virtual void CMaster::ShutdownConnection(class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::ShutdownConnection(CMaster *this, CBaseServer *pServer)
{
  CMasterserver *v4; // esi
  int v5; // eax
  CMasterserver *v6; // esi
  int m_Size; // ecx
  int v8; // eax
  CBaseServer **p_pServer; // edx
  int v10; // ecx
  int i; // [esp+4h] [ebp-8h]
  char message[4]; // [esp+8h] [ebp-4h] BYREF
  CBaseServer *pServera; // [esp+14h] [ebp+8h]

  if ( host_initialized
    && !this->m_bNoMasters
    && pServer->IsMultiplayer(this: pServer)
    && !CBaseServer::ShouldHideFromMasterServer(this: pServer) )
  {
    this->InitConnection(this);
    V_snprintf(pDest: message, maxLen: 4, pFormat: "%c\n", 98);
    i = 0;
    if ( this->m_MasterServers.m_Size > 0 )
    {
      pServera = nullptr;
      do
      {
        v4 = (CMasterserver *)((char *)pServera + (unsigned int)this->m_MasterServers.m_Memory.m_pMemory);
        v5 = _V_strlen(str: message);
        NET_SendPacket(
          chan: nullptr,
          sock: pServer->m_Socket,
          to: &v4->addr,
          data: (const unsigned __int8 *)message,
          length: v5 + 1,
          pVoicePayload: nullptr,
          bUseCompression: false,
          unMillisecondsDelay: 0);
        v6 = (CMasterserver *)((char *)pServera + (unsigned int)this->m_MasterServers.m_Memory.m_pMemory);
        m_Size = v6->heartbeats.m_Size;
        v8 = 0;
        if ( m_Size > 0 )
        {
          p_pServer = &v6->heartbeats.m_Memory.m_pMemory->pServer;
          while ( *p_pServer != pServer )
          {
            ++v8;
            p_pServer += 4;
            if ( v8 >= m_Size )
              goto LABEL_15;
          }
          v10 = m_Size - v8 - 1;
          if ( v10 > 0 )
            _V_memmove(
              dest: &v6->heartbeats.m_Memory.m_pMemory[v8],
              src: &v6->heartbeats.m_Memory.m_pMemory[v8 + 1],
              count: 16 * v10);
          --v6->heartbeats.m_Size;
        }
LABEL_15:
        pServera = (CBaseServer *)((char *)pServera + 32);
        ++i;
      }
      while ( i < this->m_MasterServers.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E3A50
// Name: pingserver
// Source: json
//------------------------------------------------------------------------------
void __cdecl pingserver(const CCommand *args)
{
  int m_nArgv0Size; // eax
  char *v2; // esi
  char *v3; // eax
  CUtlBuffer msg; // [esp+0h] [ebp-3Ch] BYREF
  netadr_s adr; // [esp+30h] [ebp-Ch] BYREF

  if ( args->m_nArgc >= 2 )
  {
    m_nArgv0Size = args->m_nArgv0Size;
    v2 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( m_nArgv0Size == 0 )
      v2 = (char *)defaultValue;
    netadr_s::SetIP(this: &adr, unIP: 0);
    netadr_s::SetPort(this: &adr, newport: 0);
    netadr_s::SetType(this: &adr, newtype: NA_IP);
    netadr_s::SetFromString(this: &adr, pch: v2, bUseDNS: 0);
    v3 = netadr_s::ToString(this: &adr, baseOnly: false);
    _Msg(a1: "pinging %s\n", v3);
    CUtlBuffer::CUtlBuffer(this: &msg, growSize: 0, initSize: 0, nFlags: 0);
    if ( (msg.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &msg, pFmt: "%d", -1);
    else
      CUtlBuffer::PutTypeBin<int>(this: &msg, src: -1);
    if ( (msg.m_Flags & 1) != 0 && msg.m_Put != 0 && msg.m_Memory.m_pMemory[msg.m_Put - msg.m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: &msg);
    if ( CUtlBuffer::CheckPut(this: &msg, nSize: 1) != 0 )
    {
      msg.m_Memory.m_pMemory[msg.m_Put++ - msg.m_nOffset] = 84;
      CUtlBuffer::AddNullTermination(this: &msg, nPut: msg.m_Put);
    }
    CUtlBuffer::PutString(this: &msg, pString: "Source Engine Query");
    NET_SendPacket(
      chan: nullptr,
      sock: 0,
      to: &adr,
      data: msg.m_Memory.m_pMemory,
      length: msg.m_Put,
      pVoicePayload: nullptr,
      bUseCompression: false,
      unMillisecondsDelay: 0);
    if ( msg.m_Memory.m_nGrowSize >= 0 && msg.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: msg.m_Memory.m_pMemory);
  }
  else
  {
    ConMsg(a1: "Usage:  pingserver <server:ip>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E3BA0
// Name: private: void CMaster::RebuildPlayers(class CGameServer __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CMaster::RebuildPlayers(
        CMaster *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CGameServer *pServer)
{
  CGameServer *v6; // edi
  int (__thiscall *GetClientCount)(struct CGameServer *); // edx
  S3RGBA *m_pMemory; // esi
  signed int v9; // ebx
  float v10; // eax
  int v11; // edx
  signed int v12; // edi
  float *v13; // edi
  int (__thiscall *v14)(struct CGameServer *); // eax
  int v15; // eax
  signed int v16; // edi
  S3RGBA v17; // esi
  CPlayerState *v18; // ebx
  int (__thiscall *v19)(int); // edx
  int v20; // esi
  const char *v21; // eax
  int frags; // eax
  bf_write *v23; // ebx
  double v24; // st7
  int v25; // eax
  float v29; // [esp+0h] [ebp-24h]
  CUtlMemory<S3RGBA,int> v30; // [esp+4h] [ebp-20h] BYREF
  signed int v31; // [esp+10h] [ebp-14h]
  S3RGBA *v32; // [esp+14h] [ebp-10h]
  float val; // [esp+18h] [ebp-Ch]
  __int64 vecHumans; // [esp+1Ch] [ebp-8h] OVERLAPPED

  this->m_PlayersCache.m_flLastUpdateTime = realtime;
  bf_write::Reset(this: &this->m_PlayersCache.m_Buffer);
  vecHumans = (unsigned int)&this->m_PlayersCache.m_Buffer;
  bf_write::WriteLong(this: &this->m_PlayersCache.m_Buffer, val: -1);
  bf_write::WriteByte(this: &this->m_PlayersCache.m_Buffer, val: 0x44u);
  v6 = pServer;
  GetClientCount = pServer->GetClientCount;
  m_pMemory = nullptr;
  v9 = 0;
  memset(&v30, 0, sizeof(v30));
  v31 = 0;
  v32 = nullptr;
  if ( ((int (__thiscall *)(CGameServer *, int, int, int))GetClientCount)(a1: pServer, a2: a3, a3: a4, a4: a2) > 0 )
  {
    do
    {
      v10 = *(float *)&v6->m_Clients.m_Memory.m_pMemory[HIDWORD(vecHumans)];
      v11 = *(_DWORD *)(LODWORD(v10) + 4);
      val = v10;
      if ( (*(unsigned __int8 (__thiscall **)(int))(v11 + 124))(a1: LODWORD(v10) + 4) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)(LODWORD(val) + 4) + 176))(a1: LODWORD(val) + 4) != 0
        && serverGameClients->GetPlayerState(this: serverGameClients, a2: *(_DWORD *)(LODWORD(val) + 120660)) != nullptr )
      {
        v12 = v9;
        if ( v9 + 1 > v30.m_nAllocationCount )
        {
          CUtlMemory<INetMessage *,int>::Grow(this: &v30, num: v9 - v30.m_nAllocationCount + 1);
          v9 = v31;
          m_pMemory = v30.m_pMemory;
        }
        v31 = ++v9;
        v32 = m_pMemory;
        if ( v9 - v12 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * (v9 - v12 - 1));
        v13 = (float *)&m_pMemory[v12];
        if ( v13 != nullptr )
          *v13 = val;
        v6 = pServer;
      }
      v14 = v6->GetClientCount;
      ++HIDWORD(vecHumans);
      v15 = v14(this: v6);
    }
    while ( SHIDWORD(vecHumans) < v15 );
  }
  bf_write::WriteByte(this: (bf_write *)vecHumans, val: v9);
  v16 = 0;
  if ( v9 > 0 )
  {
    do
    {
      v17 = m_pMemory[v16];
      v18 = serverGameClients->GetPlayerState(this: serverGameClients, a2: *(_DWORD *)(*(_DWORD *)&v17 + 120660));
      if ( v18 != nullptr )
      {
        bf_write::WriteByte(this: (bf_write *)vecHumans, val: v16);
        v19 = *(int (__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)&v17 + 4) + 68);
        v20 = *(_DWORD *)&v17 + 4;
        v21 = (const char *)v19(a1: v20);
        bf_write::WriteString(this: (bf_write *)vecHumans, pStr: v21);
        frags = v18->frags;
        v23 = (bf_write *)vecHumans;
        bf_write::WriteLong(this: (bf_write *)vecHumans, val: frags);
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v20 + 136))(a1: v20) != 0 )
        {
          v24 = -1.0;
        }
        else
        {
          v25 = (*(int (__thiscall **)(int))(*(_DWORD *)v20 + 72))(a1: v20);
          v24 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v25 + 12))(a1: v25);
        }
        v29 = v24;
        bf_write::WriteFloat(this: v23, val: v29);
      }
      m_pMemory = v30.m_pMemory;
      ++v16;
    }
    while ( v16 < v31 );
  }
  if ( v30.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101E3D90
// Name: public: void CMaster::ReplyPlayers(struct netadr_s __near &,class CGameServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMaster::ReplyPlayers(CMaster *this@<ecx>, int a2@<ebx>, netadr_s *adr, CGameServer *pServer)
{
  if ( !CBaseServer::ShouldHideServer(this: pServer) )
  {
    if ( (float)(realtime - this->m_PlayersCache.m_flLastUpdateTime) >= 0.25 )
      CMaster::RebuildPlayers(this, a2, a3: (int)pServer, a4: (int)this, pServer);
    if ( this->m_PlayersCache.m_Buffer.m_iCurBit > 0 )
      NET_SendPacket(
        chan: nullptr,
        sock: pServer->m_Socket,
        to: adr,
        data: this->m_PlayersCache.m_Buffer.m_pData,
        length: (this->m_PlayersCache.m_Buffer.m_iCurBit + 7) >> 3,
        pVoicePayload: nullptr,
        bUseCompression: false,
        unMillisecondsDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E3E10
// Name: public: class CHeartbeat __near * CMaster::GetHeartbeat(class CMasterserver __near *,class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
CHeartbeat *__thiscall CMaster::GetHeartbeat(CMaster *this, CMasterserver *pMasterServer, CBaseServer *pServer)
{
  int m_Size; // ecx
  int v4; // eax
  CHeartbeat *v5; // edi
  CBaseServer **p_pServer; // edx
  int m_nAllocationCount; // eax
  int v8; // edi
  CHeartbeat *m_pMemory; // ecx
  int v10; // eax
  CHeartbeat *result; // eax

  m_Size = pMasterServer->heartbeats.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    m_nAllocationCount = pMasterServer->heartbeats.m_Memory.m_nAllocationCount;
    v8 = pMasterServer->heartbeats.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CPortalRect,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&pMasterServer->heartbeats,
        num: v8 - m_nAllocationCount + 1);
    ++pMasterServer->heartbeats.m_Size;
    m_pMemory = pMasterServer->heartbeats.m_Memory.m_pMemory;
    v10 = pMasterServer->heartbeats.m_Size - v8 - 1;
    pMasterServer->heartbeats.m_pElements = m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 16 * v10);
    result = &pMasterServer->heartbeats.m_Memory.m_pMemory[v8];
    result->last_heartbeat = -9999.0;
    result->pServer = pServer;
    result->challangenr = -1;
    result->challengetime = 0.0;
  }
  else
  {
    v5 = pMasterServer->heartbeats.m_Memory.m_pMemory;
    p_pServer = &v5->pServer;
    while ( *p_pServer != pServer )
    {
      ++v4;
      p_pServer += 4;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    return &v5[v4];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E3EC0
// Name: public: virtual void CMaster::CheckHeartbeat(class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::CheckHeartbeat(CMaster *this, CBaseServer *pServer)
{
  int v2; // edi
  CHeartbeat *Heartbeat; // eax
  int i; // [esp+Ch] [ebp-Ch]
  int m_nValue; // [esp+10h] [ebp-8h]
  unsigned __int8 c; // [esp+17h] [ebp-1h] BYREF
  char bPrintedMessage_3; // [esp+23h] [ebp+Bh]

  v2 = 0;
  if ( (sv_master_legacy_mode.m_pParent != nullptr && sv_master_legacy_mode.m_pParent->m_Value.m_nValue != 0
     || Steam3Server()->m_pSteamMasterServerUpdater == nullptr)
    && !this->m_bNoMasters
    && pServer->IsActive(this: pServer)
    && pServer->IsMultiplayer(this: pServer)
    && !CBaseServer::ShouldHideFromMasterServer(this: pServer) )
  {
    this->InitConnection(this);
    c = 113;
    bPrintedMessage_3 = 0;
    for ( i = 0; i < this->m_MasterServers.m_Size; ++i )
    {
      Heartbeat = CMaster::GetHeartbeat(this, pMasterServer: &this->m_MasterServers.m_Memory.m_pMemory[v2], pServer);
      if ( Heartbeat != nullptr && (double)this->m_iHeartBeatTimeout <= net_time - Heartbeat->last_heartbeat )
      {
        if ( Heartbeat->challengetime <= 0.0
          || (mm_heartbeat_timeout.m_pParent == nullptr
            ? (m_nValue = 0)
            : (m_nValue = mm_heartbeat_timeout.m_pParent->m_Value.m_nValue),
              (double)m_nValue <= net_time - Heartbeat->challengetime) )
        {
          Heartbeat->challengetime = net_time;
          Heartbeat->last_heartbeat = net_time;
          if ( bPrintedMessage_3 == 0 )
          {
            bPrintedMessage_3 = 1;
            _Msg(a1: "Sending heartbeat to master server...\n");
          }
          NET_SendPacket(
            chan: nullptr,
            sock: pServer->m_Socket,
            to: &this->m_MasterServers.m_Memory.m_pMemory[v2].addr,
            data: &c,
            length: 1,
            pVoicePayload: nullptr,
            bUseCompression: false,
            unMillisecondsDelay: 0);
        }
      }
      ++v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E4020
// Name: public: virtual void CMaster::HandleUnknown(struct netpacket_s __near *,class CBaseServer __near *,class CGameServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::HandleUnknown(
        CMaster *this,
        netpacket_s *packet,
        CBaseServer *pServer,
        CGameServer *pGameServer)
{
  int m_nBitsAvail; // edx
  const unsigned int *m_pDataIn; // eax
  int v6; // ecx
  unsigned int v7; // esi
  unsigned int m_nInBufWord; // ebx
  int v9; // edi
  int v10; // esi
  const unsigned int *m_pBufferEnd; // ebx
  const unsigned int *v12; // eax
  unsigned int v13; // edx
  int v14; // edi
  unsigned int v15; // ebx
  int v16; // eax
  int v17; // edi
  unsigned int v18; // ecx
  unsigned int v19; // edx
  unsigned int v20; // eax
  unsigned int v21; // edi
  int v22; // eax
  unsigned int v23; // esi
  int m_nDataBits; // eax
  int v25; // ecx
  int v26; // edi
  unsigned int v27; // ebx
  unsigned int v28; // eax
  int v29; // ecx
  int v30; // edi
  unsigned int v31; // ebx
  unsigned int v32; // eax
  char nugget[64]; // [esp+Ch] [ebp-6Ch] BYREF
  bf_read msg; // [esp+4Ch] [ebp-2Ch] BYREF
  int challengeNr; // [esp+70h] [ebp-8h]
  CMaster *v36; // [esp+74h] [ebp-4h]
  int pGameServera; // [esp+88h] [ebp+10h]

  v36 = this;
  msg = packet->message;
  m_nBitsAvail = msg.m_nBitsAvail;
  m_pDataIn = msg.m_pDataIn;
  if ( msg.m_nBitsAvail >= 8 )
  {
    LOBYTE(v6) = msg.m_nInBufWord;
    m_nBitsAvail = msg.m_nBitsAvail - 8;
    msg.m_nBitsAvail = m_nBitsAvail;
    if ( m_nBitsAvail != 0 )
    {
      v7 = msg.m_nInBufWord >> 8;
    }
    else
    {
      m_nBitsAvail = 32;
      msg.m_nBitsAvail = 32;
      if ( msg.m_pDataIn == msg.m_pBufferEnd )
      {
        v7 = 0;
        m_nBitsAvail = 1;
        m_pDataIn = msg.m_pDataIn + 1;
        msg.m_nBitsAvail = 1;
        ++msg.m_pDataIn;
      }
      else if ( msg.m_pDataIn <= msg.m_pBufferEnd )
      {
        v7 = *msg.m_pDataIn;
        m_pDataIn = ++msg.m_pDataIn;
      }
      else
      {
        msg.m_bOverflow = true;
        v7 = 0;
      }
    }
    goto LABEL_16;
  }
  m_nInBufWord = msg.m_nInBufWord;
  v9 = 8 - msg.m_nBitsAvail;
  if ( msg.m_pDataIn == msg.m_pBufferEnd )
  {
    m_nBitsAvail = 1;
    v7 = 0;
    m_pDataIn = msg.m_pDataIn + 1;
    LOBYTE(v6) = 0;
    msg.m_nBitsAvail = 1;
    msg.m_nInBufWord = 0;
    ++msg.m_pDataIn;
    msg.m_bOverflow = true;
  }
  else if ( msg.m_pDataIn <= msg.m_pBufferEnd )
  {
    v7 = *msg.m_pDataIn;
    m_pDataIn = msg.m_pDataIn + 1;
    msg.m_nInBufWord = *msg.m_pDataIn++;
    if ( !msg.m_bOverflow )
    {
      challengeNr = v7 & CBitBuffer::s_nMaskTable[v9];
      v7 >>= v9;
      m_nBitsAvail = 32 - v9;
      v6 = (challengeNr << SLOBYTE(msg.m_nBitsAvail)) | m_nInBufWord;
      msg.m_nBitsAvail = 32 - v9;
LABEL_16:
      msg.m_nInBufWord = v7;
      goto LABEL_17;
    }
    LOBYTE(v6) = 0;
  }
  else
  {
    v7 = 0;
    LOBYTE(v6) = 0;
    msg.m_bOverflow = true;
    msg.m_nInBufWord = 0;
  }
LABEL_17:
  switch ( (char)v6 )
  {
    case 'O':
      if ( !v36->IsMasterServerAddress(this: v36, a2: (netadr_s *)packet) )
        return;
      v21 = msg.m_nInBufWord;
      if ( msg.m_nBitsAvail < 32 )
      {
        v22 = 32 - msg.m_nBitsAvail;
        if ( msg.m_pDataIn == msg.m_pBufferEnd )
        {
          msg.m_nBitsAvail = 1;
          msg.m_nInBufWord = 0;
          ++msg.m_pDataIn;
          msg.m_bOverflow = true;
          v21 = 0;
        }
        else if ( msg.m_pDataIn <= msg.m_pBufferEnd )
        {
          v23 = *msg.m_pDataIn;
          msg.m_nInBufWord = *msg.m_pDataIn++;
          if ( !msg.m_bOverflow )
          {
            v21 |= (v23 & CBitBuffer::s_nMaskTable[v22]) << SLOBYTE(msg.m_nBitsAvail);
            msg.m_nInBufWord = v23 >> v22;
            goto LABEL_59;
          }
          v21 = 0;
        }
        else
        {
          msg.m_bOverflow = true;
          msg.m_nInBufWord = 0;
          v21 = 0;
        }
      }
      else
      {
        msg.m_nBitsAvail -= 32;
        if ( msg.m_nBitsAvail != 0 )
        {
LABEL_57:
          msg.m_nInBufWord = 0;
          goto LABEL_58;
        }
        msg.m_nBitsAvail = 32;
        if ( msg.m_pDataIn == msg.m_pBufferEnd )
        {
          msg.m_nBitsAvail = 1;
          msg.m_nInBufWord = 0;
          ++msg.m_pDataIn;
          goto LABEL_58;
        }
        if ( msg.m_pDataIn > msg.m_pBufferEnd )
        {
          msg.m_bOverflow = true;
          goto LABEL_57;
        }
        msg.m_nInBufWord = *msg.m_pDataIn++;
      }
LABEL_58:
      if ( msg.m_bOverflow )
        return;
LABEL_59:
      if ( v36->IsCorrectMasterChallenge(this: v36, a2: (netadr_s *)packet, a3: v21, a4: pServer) )
      {
        _Msg(a1: "%cMasterRequestRestart\n", 3);
        if ( g_pFileSystem->IsSteam(this: g_pFileSystem) )
        {
          _Msg(a1: "Your server needs to be restarted in order to receive the latest update.\n");
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SERVER_LOG, a2: 0) != 0 )
            _LoggingSystem_Log(
              a1: LOG_SERVER_LOG,
              a2: 0,
              a3: "Your server needs to be restarted in order to receive the latest update.\n");
        }
        else
        {
          _Msg(a1: "Your server is out of date.  Please update and restart.\n");
        }
      }
      return;
    case 'T':
      nugget[0] = 0;
      if ( msg.m_pData != nullptr )
      {
        m_nDataBits = 8 * (msg.m_nDataBytes & 3) + 32 * (m_pDataIn - msg.m_pData) - m_nBitsAvail;
        if ( m_nDataBits >= msg.m_nDataBits )
          m_nDataBits = msg.m_nDataBits;
      }
      else
      {
        m_nDataBits = 0;
      }
      if ( (msg.m_nDataBits - m_nDataBits) >> 3 >= _V_strlen(str: "Source Engine Query") )
      {
        CBitRead::ReadString(this: &msg, pStr: nugget, maxLen: 62, bLine: false, pOutNumChars: nullptr);
        nugget[63] = 0;
      }
      if ( CBaseServer::ValidInfoChallenge(this: pServer, adr: &packet->from, nugget) )
        CMaster::ReplyInfo(this: v36, adr: &packet->from, pServer);
      return;
    case 'U':
      challengeNr = -1;
      if ( msg.m_pData != nullptr )
      {
        v25 = 32 * (m_pDataIn - msg.m_pData) - m_nBitsAvail + 8 * (msg.m_nDataBytes & 3);
        if ( v25 >= msg.m_nDataBits )
          v25 = msg.m_nDataBits;
      }
      else
      {
        v25 = 0;
      }
      if ( (int)((msg.m_nDataBits - v25) & 0xFFFFFFF8) >= 32 )
      {
        if ( m_nBitsAvail < 32 )
        {
          v26 = 32 - m_nBitsAvail;
          if ( m_pDataIn == msg.m_pBufferEnd )
          {
            msg.m_nBitsAvail = 1;
            msg.m_nInBufWord = 0;
            msg.m_pDataIn = m_pDataIn + 1;
            msg.m_bOverflow = true;
            v7 = 0;
          }
          else if ( m_pDataIn <= msg.m_pBufferEnd )
          {
            v27 = *m_pDataIn;
            msg.m_nInBufWord = *m_pDataIn;
            msg.m_pDataIn = m_pDataIn + 1;
            if ( msg.m_bOverflow )
            {
              v7 = 0;
            }
            else
            {
              v28 = (v27 & CBitBuffer::s_nMaskTable[v26]) << m_nBitsAvail;
              msg.m_nBitsAvail = m_nBitsAvail;
              v7 |= v28;
              msg.m_nInBufWord = v27 >> v26;
            }
          }
          else
          {
            msg.m_bOverflow = true;
            msg.m_nInBufWord = 0;
            v7 = 0;
          }
        }
        else
        {
          msg.m_nBitsAvail = m_nBitsAvail - 32;
          if ( m_nBitsAvail == 32 )
          {
            msg.m_nBitsAvail = 32;
            if ( m_pDataIn == msg.m_pBufferEnd )
            {
              msg.m_nBitsAvail = 1;
              msg.m_nInBufWord = 0;
              msg.m_pDataIn = m_pDataIn + 1;
            }
            else if ( m_pDataIn <= msg.m_pBufferEnd )
            {
              msg.m_nInBufWord = *m_pDataIn;
              msg.m_pDataIn = m_pDataIn + 1;
            }
            else
            {
              msg.m_bOverflow = true;
              msg.m_nInBufWord = 0;
            }
          }
          else
          {
            msg.m_nInBufWord = 0;
          }
        }
        challengeNr = v7;
      }
      if ( CBaseServer::ValidChallenge(this: pServer, adr: &packet->from, challengeNr) != 0 && pGameServer != nullptr )
        CMaster::ReplyPlayers(this: v36, adr: &packet->from, pServer: pGameServer);
      return;
    case 'V':
      pGameServera = -1;
      if ( msg.m_pData != nullptr )
      {
        v29 = 32 * (m_pDataIn - msg.m_pData) - m_nBitsAvail + 8 * (msg.m_nDataBytes & 3);
        if ( v29 >= msg.m_nDataBits )
          v29 = msg.m_nDataBits;
      }
      else
      {
        v29 = 0;
      }
      if ( (int)((msg.m_nDataBits - v29) & 0xFFFFFFF8) >= 32 )
      {
        if ( m_nBitsAvail < 32 )
        {
          v30 = 32 - m_nBitsAvail;
          if ( m_pDataIn == msg.m_pBufferEnd )
          {
            msg.m_nBitsAvail = 1;
            msg.m_nInBufWord = 0;
            msg.m_pDataIn = m_pDataIn + 1;
            msg.m_bOverflow = true;
            v7 = 0;
          }
          else if ( m_pDataIn <= msg.m_pBufferEnd )
          {
            v31 = *m_pDataIn;
            msg.m_nInBufWord = *m_pDataIn;
            msg.m_pDataIn = m_pDataIn + 1;
            if ( msg.m_bOverflow )
            {
              v7 = 0;
            }
            else
            {
              v32 = (v31 & CBitBuffer::s_nMaskTable[v30]) << m_nBitsAvail;
              msg.m_nBitsAvail = m_nBitsAvail;
              v7 |= v32;
              msg.m_nInBufWord = v31 >> v30;
            }
          }
          else
          {
            msg.m_bOverflow = true;
            msg.m_nInBufWord = 0;
            v7 = 0;
          }
        }
        else
        {
          msg.m_nBitsAvail = m_nBitsAvail - 32;
          if ( m_nBitsAvail == 32 )
          {
            msg.m_nBitsAvail = 32;
            if ( m_pDataIn == msg.m_pBufferEnd )
            {
              msg.m_nBitsAvail = 1;
              msg.m_nInBufWord = 0;
              msg.m_pDataIn = m_pDataIn + 1;
            }
            else if ( m_pDataIn <= msg.m_pBufferEnd )
            {
              msg.m_nInBufWord = *m_pDataIn;
              msg.m_pDataIn = m_pDataIn + 1;
            }
            else
            {
              msg.m_bOverflow = true;
              msg.m_nInBufWord = 0;
            }
          }
          else
          {
            msg.m_nInBufWord = 0;
          }
        }
        pGameServera = v7;
      }
      if ( CBaseServer::ValidChallenge(this: pServer, adr: &packet->from, challengeNr: pGameServera) != 0 )
        CMaster::ReplyRules(this: v36, from: &packet->from, pServer);
      return;
    case 's':
      if ( !v36->IsMasterServerAddress(this: v36, a2: (netadr_s *)packet) )
        return;
      v10 = msg.m_nBitsAvail;
      m_pBufferEnd = msg.m_pBufferEnd;
      v12 = msg.m_pDataIn;
      if ( msg.m_nBitsAvail < 8 )
      {
        v17 = 8 - msg.m_nBitsAvail;
        if ( msg.m_pDataIn == msg.m_pBufferEnd )
        {
          v13 = 0;
          v10 = 1;
          v12 = msg.m_pDataIn + 1;
          msg.m_nBitsAvail = 1;
          msg.m_nInBufWord = 0;
          ++msg.m_pDataIn;
          msg.m_bOverflow = true;
          goto LABEL_24;
        }
        if ( msg.m_pDataIn <= msg.m_pBufferEnd )
        {
          v13 = *msg.m_pDataIn;
          v12 = msg.m_pDataIn + 1;
          msg.m_nInBufWord = *msg.m_pDataIn++;
          if ( msg.m_bOverflow )
            goto LABEL_36;
          v10 = 32 - v17;
          msg.m_nBitsAvail = 32 - v17;
          v13 >>= v17;
        }
        else
        {
          msg.m_bOverflow = true;
          v13 = 0;
        }
      }
      else
      {
        v10 = msg.m_nBitsAvail - 8;
        msg.m_nBitsAvail = v10;
        if ( v10 == 0 )
        {
          m_pBufferEnd = msg.m_pBufferEnd;
          v10 = 32;
          msg.m_nBitsAvail = 32;
          if ( msg.m_pDataIn != msg.m_pBufferEnd )
          {
            if ( msg.m_pDataIn <= msg.m_pBufferEnd )
            {
              v13 = *msg.m_pDataIn;
              v12 = msg.m_pDataIn + 1;
              msg.m_nInBufWord = *msg.m_pDataIn++;
            }
            else
            {
              v13 = 0;
              msg.m_bOverflow = true;
              msg.m_nInBufWord = 0;
            }
LABEL_37:
            msg.m_nBitsAvail = v10 - 32;
            if ( v10 == 32 )
            {
              msg.m_nBitsAvail = 32;
              if ( v12 == m_pBufferEnd )
              {
                msg.m_pDataIn = v12 + 1;
                msg.m_nBitsAvail = 1;
                msg.m_nInBufWord = 0;
                v16 = v13;
LABEL_49:
                v36->SendHeartbeat(this: v36, a2: (netadr_s *)packet, a3: v16, a4: pServer);
                return;
              }
              if ( v12 <= m_pBufferEnd )
              {
                v18 = *v12;
                msg.m_pDataIn = v12 + 1;
                msg.m_nInBufWord = v18;
                v16 = v13;
                goto LABEL_49;
              }
              msg.m_bOverflow = true;
            }
            msg.m_nInBufWord = 0;
            v16 = v13;
            goto LABEL_49;
          }
          v13 = 0;
          v10 = 1;
          v12 = msg.m_pDataIn + 1;
          msg.m_nBitsAvail = 1;
          msg.m_nInBufWord = 0;
          ++msg.m_pDataIn;
LABEL_24:
          v14 = 32 - v10;
          v15 = v13;
          if ( v12 == msg.m_pBufferEnd )
          {
            msg.m_pDataIn = v12 + 1;
            msg.m_nBitsAvail = 1;
            msg.m_nInBufWord = 0;
            msg.m_bOverflow = true;
            v16 = 0;
          }
          else if ( v12 <= msg.m_pBufferEnd )
          {
            v19 = *v12;
            msg.m_nInBufWord = *v12;
            msg.m_pDataIn = v12 + 1;
            if ( msg.m_bOverflow )
            {
              v16 = 0;
            }
            else
            {
              v20 = (v19 & CBitBuffer::s_nMaskTable[v14]) << v10;
              msg.m_nBitsAvail = v10;
              v16 = v15 | v20;
              msg.m_nInBufWord = v19 >> v14;
            }
          }
          else
          {
            msg.m_bOverflow = true;
            msg.m_nInBufWord = 0;
            v16 = 0;
          }
          goto LABEL_49;
        }
        v13 = msg.m_nInBufWord >> 8;
      }
      msg.m_nInBufWord = v13;
LABEL_36:
      if ( v10 >= 32 )
        goto LABEL_37;
      goto LABEL_24;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E4860
// Name: public: virtual void CMaster::SendHeartbeat(struct netadr_s __near &,int,class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::SendHeartbeat(CMaster *this, netadr_s *adr, int challangenr, CBaseServer *pServer)
{
  int v5; // edi
  int i; // ebx
  CMasterserver *v7; // edi
  CHeartbeat *Heartbeat; // ecx
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  int v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  bool v18; // zf
  const char *v19; // eax
  char *m_pszString; // eax
  const char *GameType; // esi
  const char *v22; // eax
  CSteam3Server *v23; // eax
  const char *v24; // eax
  const char *VersionString; // eax
  const char *ProductString; // eax
  const char *v27; // eax
  char *v28; // eax
  int v29; // eax
  const char *v30; // [esp-10h] [ebp-928h]
  const char *v31; // [esp-10h] [ebp-928h]
  char szGD[260]; // [esp+4h] [ebp-914h] BYREF
  char info[2048]; // [esp+108h] [ebp-810h] BYREF
  int nBots; // [esp+908h] [ebp-10h] BYREF
  int nHumans; // [esp+90Ch] [ebp-Ch] BYREF
  int nMaxHumans; // [esp+910h] [ebp-8h] BYREF
  char szOS[4]; // [esp+914h] [ebp-4h] BYREF
  int bHasPW; // [esp+928h] [ebp+10h]
  bool bHasPW_3; // [esp+92Bh] [ebp+13h]

  if ( (sv_master_legacy_mode.m_pParent != nullptr && sv_master_legacy_mode.m_pParent->m_Value.m_nValue != 0
     || Steam3Server()->m_pSteamMasterServerUpdater == nullptr)
    && pServer->IsMultiplayer(this: pServer)
    && !CBaseServer::IsSinglePlayerGame(this: pServer)
    && !CBaseServer::ShouldHideFromMasterServer(this: pServer) )
  {
    v5 = 0;
    if ( this->m_MasterServers.m_Size > 0 )
    {
      for ( i = 0;
            !netadr_s::CompareAdr(this: adr, a: &this->m_MasterServers.m_Memory.m_pMemory[i].addr, onlyBase: false);
            ++i )
      {
        if ( ++v5 >= this->m_MasterServers.m_Size )
          return;
      }
      v7 = &this->m_MasterServers.m_Memory.m_pMemory[v5];
      if ( v7 != nullptr )
      {
        Heartbeat = CMaster::GetHeartbeat(this, pMasterServer: v7, pServer);
        if ( Heartbeat != nullptr )
        {
          bHasPW = mm_heartbeat_timeout_legacy.m_pParent != nullptr
                 ? mm_heartbeat_timeout_legacy.m_pParent->m_Value.m_nValue
                 : 0;
          if ( net_time - Heartbeat->challengetime < (double)bHasPW )
          {
            Heartbeat->challengetime = 0.0;
            Heartbeat->challangenr = challangenr;
            this->InitConnection(this);
            _V_memset(dest: message, fill: 0, count: 2053);
            CBaseServer::GetMasterServerPlayerCounts(this: &sv, &nHumans, nMaxHumanSlots: &nMaxHumans, &nBots);
            V_FileBase(in: com_gamedir, out: szGD, maxlen: 260);
            bHasPW_3 = pServer->GetPassword(this: pServer) != nullptr;
            _V_strcpy(dest: szOS, src: "w");
            info[0] = 0;
            CBaseServer::UpdateGameType(this: &sv);
            v10 = va(format: "%i", 7);
            Info_SetValueForKey(s: info, key: "protocol", value: v10, maxsize: 2048);
            v11 = va(format: "%i", challangenr);
            Info_SetValueForKey(s: info, key: "challenge", value: v11, maxsize: 2048);
            v12 = va(format: "%i", nBots);
            Info_SetValueForKey(s: info, key: "bots", value: v12, maxsize: 2048);
            if ( tv_enable.m_pParent != nullptr && tv_enable.m_pParent->m_Value.m_nValue != 0 )
            {
              if ( nHumans <= 0 )
                v13 = 0;
              else
                v13 = nHumans - 1;
              v14 = va(format: "%i", v13);
              Info_SetValueForKey(s: info, key: "players", value: v14, maxsize: 2048);
              v30 = va(format: "%i", nMaxHumans - 1);
              Info_SetValueForKey(s: info, key: "max", value: v30, maxsize: 2048);
            }
            else
            {
              v15 = va(format: "%i", nHumans);
              Info_SetValueForKey(s: info, key: "players", value: v15, maxsize: 2048);
              v31 = va(format: "%i", nMaxHumans);
              Info_SetValueForKey(s: info, key: "max", value: v31, maxsize: 2048);
            }
            Info_SetValueForStarKey(s: info, key: "gamedir", value: szGD, maxsize: 2048);
            v16 = pServer->GetMapName(this: pServer);
            Info_SetValueForKey(s: info, key: "map", value: v16, maxsize: 2048);
            v17 = "1";
            if ( !bHasPW_3 )
              v17 = "0";
            Info_SetValueForKey(s: info, key: "password", value: v17, maxsize: 2048);
            Info_SetValueForStarKey(s: info, key: "os", value: szOS, maxsize: 2048);
            v18 = Steam3Server()->m_eServerMode == eServerModeNoAuthentication;
            v19 = "1";
            if ( !v18 )
              v19 = "0";
            Info_SetValueForKey(s: info, key: "lan", value: v19, maxsize: 2048);
            if ( (sv_region.m_nFlags & 0x1000) != 0 )
            {
              m_pszString = "FCVAR_NEVER_AS_STRING";
            }
            else
            {
              m_pszString = sv_region.m_pParent->m_Value.m_pszString;
              if ( m_pszString == nullptr )
                m_pszString = (char *)defaultValue;
            }
            Info_SetValueForKey(s: info, key: "region", value: m_pszString, maxsize: 2048);
            GameType = CBaseServer::GetGameType(this: &sv, eResultType: EGAMETYPE_RESULTS_INCLUDE_PRIVATE);
            if ( pServer->IsHLTV(this: pServer) )
              GameType = defaultValue;
            Info_SetValueForKey(s: info, key: "gametype", value: GameType, maxsize: 2048);
            if ( pServer->IsHLTV(this: pServer) )
            {
              Info_SetValueForKey(s: info, key: "type", value: "p", maxsize: 2048);
              Info_SetValueForKey(s: info, key: "secure", value: "0", maxsize: 2048);
              Info_SetValueForKey(s: info, key: "version", value: "1.0.0.0", maxsize: 2048);
              Info_SetValueForKey(s: info, key: "product", value: "srctv", maxsize: 2048);
            }
            else
            {
              v18 = !pServer->IsDedicated(this: pServer);
              v22 = "d";
              if ( v18 )
                v22 = "l";
              Info_SetValueForKey(s: info, key: "type", value: v22, maxsize: 2048);
              v23 = Steam3Server();
              v18 = !CSteam3Server::BSecure(this: v23);
              v24 = "1";
              if ( v18 )
                v24 = "0";
              Info_SetValueForKey(s: info, key: "secure", value: v24, maxsize: 2048);
              VersionString = Sys_GetVersionString();
              Info_SetValueForKey(s: info, key: "version", value: VersionString, maxsize: 2048);
              ProductString = Sys_GetProductString();
              Info_SetValueForKey(s: info, key: "product", value: ProductString, maxsize: 2048);
            }
            if ( pServer->m_bIsDedicatedForXbox )
            {
              v18 = !CBaseServer::IsReserved(this: pServer);
              v27 = "1";
              if ( v18 )
                v27 = "0";
              Info_SetValueForKey(s: info, key: "reserved", value: v27, maxsize: 2048);
              if ( (sv_search_key.m_nFlags & 0x1000) != 0 )
              {
                v28 = "FCVAR_NEVER_AS_STRING";
              }
              else
              {
                v28 = sv_search_key.m_pParent->m_Value.m_pszString;
                if ( v28 == nullptr )
                  v28 = (char *)defaultValue;
              }
              Info_SetValueForKey(s: info, key: "private", value: v28, maxsize: 2048);
            }
            V_snprintf(pDest: message, maxLen: 2053, pFormat: "%c\n%s\n", 48, info);
            v29 = _V_strlen(str: message);
            NET_SendPacket(
              chan: nullptr,
              sock: pServer->m_Socket,
              to: adr,
              data: (const unsigned __int8 *)message,
              length: v29,
              pVoicePayload: nullptr,
              bUseCompression: false,
              unMillisecondsDelay: 0);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E4ED0
// Name: public: virtual bool CMaster::AddServer(struct netadr_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMaster::AddServer(CMaster *this, netadr_s *adr)
{
  if ( this->IsMasterServerAddress(this, a2: adr) )
    return 0;
  this->m_MasterServers.m_Memory.m_pMemory[CUtlVector<CMasterserver,CUtlMemory<CMasterserver,int>>::InsertBefore(
                                             this: &this->m_MasterServers,
                                             elem: this->m_MasterServers.m_Size)].addr = *adr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E4F20
// Name: public: virtual bool CMaster::RemoveServer(struct netadr_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMaster::RemoveServer(CMaster *this, netadr_s *adr)
{
  int v3; // ebx
  int i; // esi
  int v6; // ecx
  CMasterserver *v7; // esi
  bool v8; // sf
  CHeartbeat *m_pMemory; // eax

  v3 = 0;
  if ( this->m_MasterServers.m_Size <= 0 )
    return 0;
  for ( i = 0; !netadr_s::CompareAdr(this: &this->m_MasterServers.m_Memory.m_pMemory[i].addr, a: adr, onlyBase: false); ++i )
  {
    if ( ++v3 >= this->m_MasterServers.m_Size )
      return 0;
  }
  v6 = v3;
  v7 = &this->m_MasterServers.m_Memory.m_pMemory[v3];
  v8 = v7->heartbeats.m_Memory.m_nGrowSize < 0;
  v7->heartbeats.m_Size = 0;
  if ( !v8 )
  {
    if ( v7->heartbeats.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7->heartbeats.m_Memory.m_pMemory);
      v6 = v3;
      v7->heartbeats.m_Memory.m_pMemory = nullptr;
    }
    v7->heartbeats.m_Memory.m_nAllocationCount = 0;
  }
  v8 = v7->heartbeats.m_Memory.m_nGrowSize < 0;
  m_pMemory = v7->heartbeats.m_Memory.m_pMemory;
  v7->heartbeats.m_pElements = m_pMemory;
  if ( !v8 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      v6 = v3;
      v7->heartbeats.m_Memory.m_pMemory = nullptr;
    }
    v7->heartbeats.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_MasterServers.m_Size - v3 - 1 > 0 )
    _V_memmove(
      dest: &this->m_MasterServers.m_Memory.m_pMemory[v6],
      src: &this->m_MasterServers.m_Memory.m_pMemory[v6 + 1],
      count: 32 * (this->m_MasterServers.m_Size - v3 - 1));
  --this->m_MasterServers.m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E5000
// Name: public: virtual void CMaster::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::Shutdown(CMaster *this)
{
  CUtlVector<CMasterserver,CUtlMemory<CMasterserver,int> > *p_m_MasterServers; // esi
  CMasterserver *m_pMemory; // ecx

  p_m_MasterServers = &this->m_MasterServers;
  CUtlVector<CMasterserver,CUtlMemory<CMasterserver,int>>::RemoveAll(this: &this->m_MasterServers);
  if ( p_m_MasterServers->m_Memory.m_nGrowSize < 0 )
  {
    p_m_MasterServers->m_pElements = p_m_MasterServers->m_Memory.m_pMemory;
  }
  else
  {
    if ( p_m_MasterServers->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_MasterServers->m_Memory.m_pMemory);
      p_m_MasterServers->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = p_m_MasterServers->m_Memory.m_pMemory;
    p_m_MasterServers->m_Memory.m_nAllocationCount = 0;
    p_m_MasterServers->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E50B0
// Name: public: CMaster::CMaster(void)
// Source: json
//------------------------------------------------------------------------------
CMaster *__thiscall CMaster::CMaster(CMaster *this)
{
  unsigned __int8 *m_Data; // edi

  this->__vftable = (CMaster_vtbl *)&CMaster::`vftable';
  m_Data = this->m_InfoCache.m_Data;
  this->m_MasterServers.m_Memory.m_pMemory = nullptr;
  this->m_MasterServers.m_Memory.m_nAllocationCount = 0;
  this->m_MasterServers.m_Memory.m_nGrowSize = 0;
  this->m_MasterServers.m_Size = 0;
  this->m_MasterServers.m_pElements = nullptr;
  this->m_InfoCache.m_flLastUpdateTime = 0.0;
  bf_write::bf_write(
    this: &this->m_InfoCache.m_Buffer,
    pDebugName: "SVC_Info",
    pData: this->m_InfoCache.m_Data,
    nBytes: 1200,
    nBits: -1);
  _V_memset(dest: m_Data, fill: 0, count: 1200);
  this->m_RulesCache.m_flLastUpdateTime = 0.0;
  bf_write::bf_write(
    this: &this->m_RulesCache.m_Buffer,
    pDebugName: "SVC_Rules",
    pData: this->m_RulesCache.m_Data,
    nBytes: 1200,
    nBits: -1);
  _V_memset(dest: this->m_RulesCache.m_Data, fill: 0, count: 1200);
  this->m_PlayersCache.m_flLastUpdateTime = 0.0;
  bf_write::bf_write(
    this: &this->m_PlayersCache.m_Buffer,
    pDebugName: "SVC_Players",
    pData: this->m_PlayersCache.m_Data,
    nBytes: 1200,
    nBits: -1);
  _V_memset(dest: this->m_PlayersCache.m_Data, fill: 0, count: 1200);
  this->m_bNoMasters = false;
  this->m_bRestartOnLevelChange = false;
  this->m_hSteamDLL = nullptr;
  this->m_iHeartBeatTimeout = 300;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E5190
// Name: public: virtual bool CMaster::RestartOnLevelChange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaster::RestartOnLevelChange(CMaster *this)
{
  return this->m_bRestartOnLevelChange;
}

//------------------------------------------------------------------------------
// Address: 0x101E51A0
// Name: public: virtual void CMaster::SetRestartOnLevelChange(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::SetRestartOnLevelChange(CMaster *this, bool state)
{
  this->m_bRestartOnLevelChange = state;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101E2A10
// Name: void Info_RemoveKey(char __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Info_RemoveKey(char *s, const char *key)
{
  char *v3; // edi
  char v4; // al
  char *v5; // ecx
  char v6; // al
  char *i; // ecx
  char value[512]; // [esp+4h] [ebp-400h] BYREF
  char pkey[512]; // [esp+204h] [ebp-200h] BYREF

  if ( _V_strstr(s1: key, search: "\\") != nullptr )
  {
    _Msg(a1: "Can't use a key with a \\\n");
  }
  else
  {
    while ( 1 )
    {
      v3 = s;
      if ( *s == 92 )
        ++s;
      v4 = *s;
      v5 = pkey;
      if ( *s != 92 )
        break;
LABEL_8:
      v6 = *++s;
      *v5 = 0;
      for ( i = value; v6 != 92; ++i )
      {
        if ( v6 == 0 )
          break;
        v6 = *++s;
      }
      *i = 0;
      if ( _V_strcmp(s1: key, s2: pkey) == 0 )
      {
        _V_memmove(dest: v3, src: s, count: strlen(s) + 1);
        return;
      }
      if ( *s == 0 )
        return;
    }
    while ( v4 != 0 )
    {
      ++s;
      *v5 = v4;
      v4 = *s;
      ++v5;
      if ( *s == 92 )
        goto LABEL_8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E2AE0
// Name: bool Info_IsKeyImportant(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Info_IsKeyImportant(const char *key)
{
  return *key == 42
      || _V_strcmp(s1: key, s2: "name") == 0
      || _V_strcmp(s1: key, s2: "model") == 0
      || _V_strcmp(s1: key, s2: "rate") == 0
      || _V_strcmp(s1: key, s2: "cl_updaterate") == 0
      || _V_strcmp(s1: key, s2: "cl_lw") == 0
      || _V_strcmp(s1: key, s2: "cl_lc") == 0
      || _V_strcmp(s1: key, s2: "tracker") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E2B80
// Name: char __near * Info_FindLargestKey(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Info_FindLargestKey(char *s)
{
  char *v1; // esi
  int v2; // ebx
  char i; // al
  char *v4; // ecx
  int v5; // edi
  char v6; // al
  char *v7; // ecx
  bool v8; // zf
  int v9; // edi
  char value[256]; // [esp+Ch] [ebp-200h] BYREF
  char key[256]; // [esp+10Ch] [ebp-100h] BYREF

  v1 = s;
  v2 = 0;
  largest_key[0] = 0;
  if ( *s == 92 )
    v1 = s + 1;
  for ( i = *v1; *v1 != 0; i = *v1 )
  {
    v4 = key;
    if ( i != 0 )
    {
      do
      {
        if ( i == 92 )
          break;
        ++v1;
        *v4 = i;
        i = *v1;
        ++v4;
      }
      while ( *v1 != 0 );
    }
    *v4 = 0;
    v5 = _V_strlen(str: key);
    if ( *v1 == 0 )
      break;
    v6 = *++v1;
    v7 = value;
    if ( v6 != 0 )
    {
      do
      {
        if ( v6 == 92 )
          break;
        ++v1;
        *v7 = v6;
        v6 = *v1;
        ++v7;
      }
      while ( *v1 != 0 );
    }
    v8 = *v1 == 0;
    *v7 = 0;
    if ( !v8 )
      ++v1;
    v9 = _V_strlen(str: value) + v5;
    if ( v9 > v2
      && key[0] != 42
      && _V_strcmp(s1: key, s2: "name") != 0
      && _V_strcmp(s1: key, s2: "model") != 0
      && _V_strcmp(s1: key, s2: "rate") != 0
      && _V_strcmp(s1: key, s2: "cl_updaterate") != 0
      && _V_strcmp(s1: key, s2: "cl_lw") != 0
      && _V_strcmp(s1: key, s2: "cl_lc") != 0
      && _V_strcmp(s1: key, s2: "tracker") != 0 )
    {
      v2 = v9;
      V_strncpy(pDest: largest_key, pSrc: key, maxLen: 256);
    }
  }
  return largest_key;
}

//------------------------------------------------------------------------------
// Address: 0x101E2D20
// Name: void Info_SetValueForStarKey(char __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Info_SetValueForStarKey(char *s, const char *key, const char *value, int maxsize)
{
  int v4; // eax
  char *LargestKey; // ebx
  int v6; // eax
  char *v7; // esi
  char *v8; // edi
  int v9; // ebx
  char newArray[1024]; // [esp+8h] [ebp-404h] BYREF
  int v11; // [esp+408h] [ebp-4h]

  if ( _V_strstr(s1: key, search: "\\") != nullptr || _V_strstr(s1: value, search: "\\") != nullptr )
  {
    _Msg(a1: "Can't use keys or values with a \\\n");
    return;
  }
  if ( _V_strstr(s1: key, search: "\"") != nullptr || _V_strstr(s1: value, search: "\"") != nullptr )
  {
    _Msg(a1: "Can't use keys or values with a \"\n");
    return;
  }
  if ( _V_strlen(str: key) > 127 || _V_strlen(str: value) > 127 )
  {
    _Msg(a1: "Keys and values must be < %i characters.\n", 128);
    return;
  }
  Info_RemoveKey(s, key);
  if ( value != nullptr && _V_strlen(str: value) != 0 )
  {
    V_snprintf(pDest: newArray, maxLen: 1024, pFormat: "\\%s\\%s", key, value);
    v11 = _V_strlen(str: s);
    v4 = _V_strlen(str: newArray);
    if ( v4 + v11 >= maxsize )
    {
      if ( !Info_IsKeyImportant(key) )
        goto LABEL_15;
      while ( 1 )
      {
        LargestKey = Info_FindLargestKey(s);
        Info_RemoveKey(s, key: LargestKey);
        v11 = _V_strlen(str: s);
        v6 = _V_strlen(str: newArray);
        if ( v6 + v11 < maxsize )
          break;
        if ( *LargestKey == 0 )
          goto LABEL_15;
      }
      if ( *LargestKey == 0 )
      {
LABEL_15:
        _Msg(a1: "Info string length exceeded\n");
        return;
      }
    }
    v7 = &s[_V_strlen(str: s)];
    v8 = newArray;
    if ( newArray[0] == 0 )
    {
LABEL_25:
      *v7 = 0;
      return;
    }
    while ( 1 )
    {
      v9 = (unsigned __int8)*v8++;
      if ( _V_stricmp(s1: key, s2: "name") == 0 )
        goto LABEL_22;
      v9 &= 0x7Fu;
      if ( (unsigned int)(v9 - 32) <= 0x5F )
        break;
LABEL_24:
      if ( *v8 == 0 )
        goto LABEL_25;
    }
    if ( _V_stricmp(s1: key, s2: "team") == 0 )
      v9 = tolower(c: v9);
LABEL_22:
    if ( v9 > 13 )
      *v7++ = v9;
    goto LABEL_24;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E2F30
// Name: void Info_SetValueForKey(char __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Info_SetValueForKey(char *s, const char *key, const char *value, int maxsize)
{
  if ( *key == 42 )
    _Msg(a1: "Can't set * keys\n");
  else
    Info_SetValueForStarKey(s, key, value, maxsize);
}

//------------------------------------------------------------------------------
// Address: 0x101E2F70
// Name: public: virtual void CMaster::Init(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CMaster::Init(CMaster *this)
{
  int m_nValue; // eax
  unsigned int v3; // [esp-8h] [ebp-Ch]
  int v4; // [esp-4h] [ebp-8h]

  if ( mm_heartbeat_seconds.m_pParent != nullptr )
    m_nValue = mm_heartbeat_seconds.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  this->m_iHeartBeatTimeout = m_nValue;
  if ( sv.m_bIsDedicatedForXbox )
  {
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&sv_master_legacy_mode.IConVar, value: 1, a2: v3, a3: v4);
    if ( mm_heartbeat_seconds_xlsp.m_pParent != nullptr )
      this->m_iHeartBeatTimeout = mm_heartbeat_seconds_xlsp.m_pParent->m_Value.m_nValue;
    else
      this->m_iHeartBeatTimeout = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E2FC0
// Name: private: void CMaster::RebuildInfo(class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMaster::RebuildInfo(CMaster *this@<ecx>, int a2@<edi>, int a3@<esi>, CBaseServer *pServer)
{
  bf_write *p_m_Buffer; // esi
  unsigned int HostVersion; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  int SteamAppID; // eax
  const char *v12; // eax
  ISteamGameServer *m_pSteamGameServer; // ecx
  bool v14; // al
  const char *VersionString; // eax
  char v16; // bl
  const char *GameType; // eax
  unsigned __int16 UDPPort; // ax
  unsigned __int16 v19; // ax
  CBaseServer_vtbl *v20; // edx
  CBaseServer *v21; // ecx
  const char *v22; // eax
  char gd[260]; // [esp+0h] [ebp-138h] BYREF
  char verString[40]; // [esp+104h] [ebp-34h] BYREF
  int nMaxHumans; // [esp+12Ch] [ebp-Ch] BYREF
  int nHumans; // [esp+130h] [ebp-8h] BYREF
  int nBots; // [esp+134h] [ebp-4h] BYREF
  const char *pchGameType; // [esp+140h] [ebp+8h]

  this->m_InfoCache.m_flLastUpdateTime = realtime;
  bf_write::Reset(this: &this->m_InfoCache.m_Buffer);
  p_m_Buffer = &this->m_InfoCache.m_Buffer;
  bf_write::Reset(this: p_m_Buffer);
  bf_write::WriteLong(this: p_m_Buffer, val: -1);
  bf_write::WriteByte(this: p_m_Buffer, val: 0x49u);
  HostVersion = GetHostVersion();
  bf_write::WriteByte(this: p_m_Buffer, val: HostVersion);
  v8 = (const char *)((int (__thiscall *)(CBaseServer *, int, int))pServer->GetName)(a1: pServer, a2, a3);
  bf_write::WriteString(this: p_m_Buffer, pStr: v8);
  v9 = pServer->GetMapName(this: pServer);
  bf_write::WriteString(this: p_m_Buffer, pStr: v9);
  V_FileBase(in: com_gamedir, out: gd, maxlen: 260);
  bf_write::WriteString(this: p_m_Buffer, pStr: gd);
  v10 = serverGameDLL->GetGameDescription(this: serverGameDLL);
  bf_write::WriteString(this: p_m_Buffer, pStr: v10);
  SteamAppID = GetSteamAppID();
  bf_write::WriteShort(this: p_m_Buffer, val: SteamAppID);
  CBaseServer::GetMasterServerPlayerCounts(this: &sv, &nHumans, nMaxHumanSlots: &nMaxHumans, &nBots);
  bf_write::WriteByte(this: p_m_Buffer, val: nHumans);
  bf_write::WriteByte(this: p_m_Buffer, val: nMaxHumans);
  bf_write::WriteByte(this: p_m_Buffer, val: nBots);
  if ( pServer->IsHLTV(this: pServer) || pServer->IsReplay(this: pServer) )
  {
    bf_write::WriteByte(this: p_m_Buffer, val: 0x70u);
  }
  else if ( pServer->IsDedicated(this: pServer) )
  {
    bf_write::WriteByte(this: p_m_Buffer, val: 0x64u);
  }
  else
  {
    bf_write::WriteByte(this: p_m_Buffer, val: 0x6Cu);
  }
  bf_write::WriteByte(this: p_m_Buffer, val: 0x77u);
  v12 = pServer->GetPassword(this: pServer);
  bf_write::WriteByte(this: p_m_Buffer, val: v12 != nullptr);
  m_pSteamGameServer = Steam3Server()->m_pSteamGameServer;
  v14 = m_pSteamGameServer != nullptr
     && m_pSteamGameServer->BSecure(this: m_pSteamGameServer)
     && !pServer->IsHLTV(this: pServer);
  bf_write::WriteByte(this: p_m_Buffer, val: v14);
  VersionString = Sys_GetVersionString();
  V_snprintf(pDest: verString, maxLen: 40, pFormat: "%s", VersionString);
  bf_write::WriteString(this: p_m_Buffer, pStr: verString);
  v16 = 0;
  if ( sv.m_State > ss_dead )
    v16 = 0x80;
  if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
    v16 |= 0x40u;
  GameType = CBaseServer::GetGameType(this: &sv, eResultType: EGAMETYPE_RESULTS_INCLUDE_PUBLIC_ONLY);
  pchGameType = GameType;
  if ( GameType != nullptr && _V_strlen(str: GameType) > 0 )
    v16 |= 0x20u;
  bf_write::WriteByte(this: p_m_Buffer, val: (unsigned __int8)v16);
  if ( v16 < 0 )
  {
    UDPPort = NET_GetUDPPort(socket: 1);
    bf_write::WriteShort(this: p_m_Buffer, val: UDPPort);
  }
  if ( (v16 & 0x40) != 0 )
  {
    v19 = NET_GetUDPPort(socket: 2);
    bf_write::WriteShort(this: p_m_Buffer, val: v19);
    if ( hltv != nullptr )
    {
      v20 = hltv->CBaseServer::IServer::IConnectionlessPacketHandler::__vftable;
      v21 = &hltv->CBaseServer;
    }
    else
    {
      v20 = pServer->__vftable;
      v21 = pServer;
    }
    v22 = v20->GetName(this: v21);
    bf_write::WriteString(this: p_m_Buffer, pStr: v22);
  }
  if ( (v16 & 0x20) != 0 )
    bf_write::WriteString(this: p_m_Buffer, pStr: pchGameType);
}

//------------------------------------------------------------------------------
// Address: 0x101E3240
// Name: private: void CMaster::RebuildRules(class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::RebuildRules(CMaster *this, CBaseServer *pServer)
{
  bf_write *p_m_Buffer; // ebx
  int v4; // esi
  ICvar::ICVarIteratorInternal *m_pIter; // edi
  ConCommandBase *v6; // esi
  const char *v7; // eax
  const char *m_pszName; // eax
  const char *v9; // eax
  const char *v10; // eax
  ICvar::Iterator iter; // [esp+0h] [ebp-4h]

  this->m_RulesCache.m_flLastUpdateTime = realtime;
  bf_write::Reset(this: &this->m_RulesCache.m_Buffer);
  p_m_Buffer = &this->m_RulesCache.m_Buffer;
  bf_write::Reset(this: &this->m_RulesCache.m_Buffer);
  v4 = CCvarUtilities::CountVariablesWithFlags(this: cv, flags: 256);
  if ( v4 > 0 )
  {
    bf_write::WriteLong(this: p_m_Buffer, val: -1);
    bf_write::WriteByte(this: p_m_Buffer, val: 0x45u);
    bf_write::WriteShort(this: p_m_Buffer, val: v4);
    m_pIter = g_pCVar->FactoryInternalIterator(this: g_pCVar);
    iter.m_pIter = m_pIter;
    m_pIter->SetFirst(this: m_pIter);
    while ( m_pIter->IsValid(this: m_pIter) )
    {
      v6 = m_pIter->Get(this: m_pIter);
      if ( !v6->IsCommand(this: v6) && v6->IsFlagSet(this: v6, a2: 256) )
      {
        v7 = v6->GetName(this: v6);
        bf_write::WriteString(this: p_m_Buffer, pStr: v7);
        if ( v6->IsFlagSet(this: v6, a2: 32) )
        {
          if ( (v6->m_nFlags & 0x1000) != 0 )
          {
            m_pszName = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            m_pszName = v6[1].m_pNext[1].m_pszName;
            if ( m_pszName == nullptr )
              m_pszName = defaultValue;
          }
          if ( strlen(m_pszName) == 0 )
            goto LABEL_17;
          if ( (v6->m_nFlags & 0x1000) != 0 )
          {
            v9 = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            v9 = v6[1].m_pNext[1].m_pszName;
            if ( v9 == nullptr )
              v9 = defaultValue;
          }
          if ( _V_stricmp(s1: v9, s2: "none") != 0 )
          {
            bf_write::WriteString(this: p_m_Buffer, pStr: "1");
            m_pIter = iter.m_pIter;
          }
          else
          {
LABEL_17:
            bf_write::WriteString(this: p_m_Buffer, pStr: "0");
            m_pIter = iter.m_pIter;
          }
        }
        else
        {
          if ( (v6->m_nFlags & 0x1000) != 0 )
          {
            v10 = "FCVAR_NEVER_AS_STRING";
          }
          else
          {
            v10 = v6[1].m_pNext[1].m_pszName;
            if ( v10 == nullptr )
              v10 = defaultValue;
          }
          bf_write::WriteString(this: p_m_Buffer, pStr: v10);
        }
      }
      m_pIter->Next(this: m_pIter);
    }
    free(pMem: m_pIter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E3400
// Name: public: void CMaster::ReplyInfo(struct netadr_s __near &,class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::ReplyInfo(CMaster *this, netadr_s *adr, CBaseServer *pServer)
{
  if ( !CBaseServer::ShouldHideServer(this: pServer) )
  {
    if ( (float)(realtime - this->m_InfoCache.m_flLastUpdateTime) >= 0.25 )
      CMaster::RebuildInfo(this, a2: (int)pServer, a3: (int)this, pServer);
    if ( this->m_InfoCache.m_Buffer.m_iCurBit > 0 )
      NET_SendPacket(
        chan: nullptr,
        sock: pServer->m_Socket,
        to: adr,
        data: this->m_InfoCache.m_Buffer.m_pData,
        length: (this->m_InfoCache.m_Buffer.m_iCurBit + 7) >> 3,
        pVoicePayload: nullptr,
        bUseCompression: false,
        unMillisecondsDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E3470
// Name: public: void CMaster::ReplyRules(struct netadr_s __near &,class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::ReplyRules(CMaster *this, netadr_s *from, CBaseServer *pServer)
{
  if ( !CBaseServer::ShouldHideServer(this: pServer) )
  {
    if ( (float)(realtime - this->m_RulesCache.m_flLastUpdateTime) >= 0.25 )
      CMaster::RebuildRules(this, pServer);
    if ( this->m_RulesCache.m_Buffer.m_iCurBit > 0 )
      NET_SendPacket(
        chan: nullptr,
        sock: pServer->m_Socket,
        to: from,
        data: this->m_RulesCache.m_Buffer.m_pData,
        length: (this->m_RulesCache.m_Buffer.m_iCurBit + 7) >> 3,
        pVoicePayload: nullptr,
        bUseCompression: false,
        unMillisecondsDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E34F0
// Name: bool IsUsingMasterLegacyMode(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsUsingMasterLegacyMode()
{
  return NET_IsDedicatedForXbox()
      || sv_master_legacy_mode.m_pParent != nullptr && sv_master_legacy_mode.m_pParent->m_Value.m_nValue != 0
      || Steam3Server()->m_pSteamMasterServerUpdater == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101E3520
// Name: public: virtual void CMaster::InitConnection(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMaster::InitConnection(CMaster *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // eax
  int v5; // eax
  const char *v6; // ebx
  KeyValues *v7; // eax
  KeyValues *v8; // edi
  IBaseFileSystem *v9; // eax
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // ebx
  const char *String; // edi
  const char *v13; // eax
  const char *SteamInstallPath; // eax
  HMODULE m_hSteamDLL; // eax
  FARPROC SteamFindServersNumServers; // edi
  unsigned int v17; // eax
  unsigned int v18; // ebx
  unsigned int v19; // edi
  const char *v20; // eax
  netadr_s *p_adr; // [esp-10h] [ebp-14Ch]
  int v22; // [esp-Ch] [ebp-148h]
  char szSteamDLLPath[260]; // [esp+4h] [ebp-138h] BYREF
  char szAdr[32]; // [esp+108h] [ebp-34h] BYREF
  int nCount; // [esp+128h] [ebp-14h]
  netadr_s adr; // [esp+12Ch] [ebp-10h] BYREF
  KeyValues *pKV; // [esp+138h] [ebp-4h]

  if ( bInitialized
    || !NET_IsDedicatedForXbox()
    && (sv_master_legacy_mode.m_pParent == nullptr || sv_master_legacy_mode.m_pParent->m_Value.m_nValue == 0)
    && Steam3Server()->m_pSteamMasterServerUpdater != nullptr
    || this->m_bNoMasters )
  {
    return;
  }
  v4 = _CommandLine(a1: a3);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-nomaster") != 0 )
  {
    ConMsg(a1: "Master server communication disabled.\n");
    this->m_bNoMasters = true;
    bInitialized = true;
    return;
  }
  v22 = a2;
  if ( sv.m_bIsDedicatedForXbox )
  {
    this->m_bNoMasters = true;
    bInitialized = true;
    v5 = _CommandLine(a1: a2);
    v6 = (const char *)(*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v5 + 32))(
                         a1: v5,
                         a2: "-xlsp",
                         a3: "UNKNOWN");
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
    {
      v8 = KeyValues::KeyValues(this: v7, setName: "TitleServers");
      pKV = v8;
    }
    else
    {
      pKV = nullptr;
      v8 = nullptr;
    }
    if ( g_pFileSystem != nullptr )
      v9 = &g_pFileSystem->IBaseFileSystem;
    else
      v9 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v8,
           filesystem: v9,
           resourceName: v6,
           pathID: "GAME",
           pfnEvaluateSymbolProc: nullptr) )
    {
      Key = KeyValues::FindKey(this: v8, keyName: "MasterServers", bCreate: false);
      if ( Key != nullptr )
      {
        FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
        if ( FirstSubKey != nullptr )
        {
          do
          {
            String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
            netadr_s::SetIP(this: &adr, unIP: 0);
            netadr_s::SetPort(this: &adr, newport: 0);
            netadr_s::SetType(this: &adr, newtype: NA_IP);
            if ( NET_StringToAdr(s: String, a: &adr) != 0 )
            {
              if ( netadr_s::GetPort(this: &adr) == 0 )
                netadr_s::SetPort(this: &adr, newport: 0x6983u);
              if ( this->AddServer(this, a2: &adr) )
              {
                v13 = netadr_s::ToString(this: &adr, baseOnly: false);
                ConMsg(a1: "Adding XLSP Master Server: %s\n", v13);
                this->m_bNoMasters = false;
              }
            }
            FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
          }
          while ( FirstSubKey != nullptr );
          KeyValues::deleteThis(this: pKV);
          return;
        }
      }
    }
    else
    {
      _Warning(a1: "**********************************************\n");
      _Warning(a1: "ERROR! XLSP config %s not found!\n", v6);
      _Warning(a1: "**********************************************\n");
    }
    KeyValues::deleteThis(this: v8);
    return;
  }
  if ( this->m_hSteamDLL == nullptr )
  {
    SteamInstallPath = (const char *)_SteamAPI_GetSteamInstallPath(a1: a2);
    if ( SteamInstallPath != nullptr )
    {
      V_ComposeFileName(path: SteamInstallPath, filename: "steam.dll", dest: szSteamDLLPath, destSize: 260);
      this->m_hSteamDLL = Sys_LoadModule(pModuleName: szSteamDLLPath);
    }
    if ( this->m_hSteamDLL == nullptr )
      this->m_hSteamDLL = Sys_LoadModule(pModuleName: "steam.dll");
  }
  m_hSteamDLL = (HMODULE)this->m_hSteamDLL;
  SteamFindServersNumServers = nullptr;
  pKV = nullptr;
  if ( m_hSteamDLL != nullptr )
  {
    SteamFindServersNumServers = GetProcAddress(hModule: m_hSteamDLL, lpProcName: "SteamFindServersNumServers");
    pKV = (KeyValues *)GetProcAddress(hModule: (HMODULE)this->m_hSteamDLL, lpProcName: "SteamFindServersIterateServer");
  }
  if ( this->m_hSteamDLL != nullptr && SteamFindServersNumServers != nullptr && pKV != nullptr )
  {
    v17 = ((int (__cdecl *)(int))SteamFindServersNumServers)(a1: 4);
    v18 = v17;
    v19 = 0;
    nCount = 0;
    if ( v17 != -1 && v17 != -2 )
    {
      bInitialized = true;
      if ( v17 >= 2 )
        v18 = 2;
      if ( v18 != 0 )
      {
        do
        {
          netadr_s::netadr_s(this: &adr);
          ((void (__cdecl *)(int, unsigned int, char *, int))pKV)(a1: 4, a2: v19, a3: szAdr, a4: 32);
          if ( NET_StringToAdr(s: szAdr, a: &adr) != 0 )
          {
            v20 = netadr_s::ToString(this: &adr, baseOnly: false);
            ConMsg(a1: "Adding master server %s\n", v20);
            p_adr = &adr;
            ((void (__thiscall *)(CMaster *))this->AddServer)(a1: this);
            ++nCount;
          }
          ++v19;
        }
        while ( v19 < v18 );
      }
      if ( NET_IsDedicated() && sv_region.m_pParent != nullptr && sv_region.m_pParent->m_Value.m_nValue == -1 )
        CLoaderMemAlloc::CrtIsValidPointer(
          this: (ConVar *)&sv_region.IConVar,
          value: 255,
          a2: (unsigned int)p_adr,
          a3: v22);
      bInitialized = true;
      if ( nCount == 0 )
      {
        ConMsg(a1: "No masters loaded\nUsing default master\n");
        this->UseDefault(this);
      }
    }
  }
  else
  {
    ConMsg(a1: "Unable to load Steam library.\n");
    this->m_bNoMasters = true;
    bInitialized = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E3B50
// Name: public: virtual void CMaster::Heartbeat_Legacy_f(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::Heartbeat_Legacy_f(CMaster *this)
{
  int v1; // ebx
  CMasterserver *m_pMemory; // esi
  int v3; // edi
  CMasterserver *v4; // eax
  int v5; // edx
  int i; // [esp+4h] [ebp-4h]

  v1 = 0;
  i = 0;
  if ( this->m_MasterServers.m_Size > 0 )
  {
    m_pMemory = this->m_MasterServers.m_Memory.m_pMemory;
    do
    {
      v3 = 0;
      v4 = &m_pMemory[v1];
      if ( m_pMemory[v1].heartbeats.m_Size > 0 )
      {
        v5 = 0;
        do
        {
          v4->heartbeats.m_Memory.m_pMemory[v5].last_heartbeat = -9999.0;
          m_pMemory = this->m_MasterServers.m_Memory.m_pMemory;
          ++v3;
          v4 = &m_pMemory[v1];
          ++v5;
        }
        while ( v3 < m_pMemory[v1].heartbeats.m_Size );
      }
      ++v1;
      ++i;
    }
    while ( i < this->m_MasterServers.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E3BB0
// Name: public: virtual bool CMaster::IsMasterServerAddress(struct netadr_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMaster::IsMasterServerAddress(CMaster *this, netadr_s *from)
{
  int v3; // ebx
  int i; // edi

  v3 = 0;
  if ( this->m_MasterServers.m_Size <= 0 )
    return 0;
  for ( i = 0; !netadr_s::CompareAdr(this: from, a: &this->m_MasterServers.m_Memory.m_pMemory[i].addr, onlyBase: false); ++i )
  {
    if ( ++v3 >= this->m_MasterServers.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E3BF0
// Name: public: virtual bool CMaster::IsCorrectMasterChallenge(struct netadr_s __near *,int,class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMaster::IsCorrectMasterChallenge(
        CMaster *this,
        netadr_s *from,
        CBaseServer *challenge,
        CBaseServer *pServer)
{
  int v4; // edi
  CMasterserver *m_pMemory; // eax
  int m_Size; // edx
  int v8; // ecx
  CBaseServer **p_pServer; // eax
  int i; // [esp+Ch] [ebp-4h]

  v4 = 0;
  i = 0;
  if ( this->m_MasterServers.m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    if ( netadr_s::CompareAdr(this: &this->m_MasterServers.m_Memory.m_pMemory[v4].addr, a: from, onlyBase: false) )
    {
      m_pMemory = this->m_MasterServers.m_Memory.m_pMemory;
      m_Size = m_pMemory[v4].heartbeats.m_Size;
      v8 = 0;
      if ( m_Size > 0 )
        break;
    }
LABEL_8:
    ++v4;
    if ( ++i >= this->m_MasterServers.m_Size )
      return 0;
  }
  p_pServer = &m_pMemory[v4].heartbeats.m_Memory.m_pMemory->pServer;
  while ( *(p_pServer - 2) != challenge || *p_pServer != pServer )
  {
    ++v8;
    p_pServer += 4;
    if ( v8 >= m_Size )
      goto LABEL_8;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E3C70
// Name: public: virtual void CMaster::ShutdownConnection(class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::ShutdownConnection(CMaster *this, CBaseServer *pServer)
{
  CMasterserver *v4; // esi
  int v5; // eax
  CMasterserver *v6; // esi
  int m_Size; // ecx
  int v8; // eax
  CBaseServer **p_pServer; // edx
  int v10; // ecx
  int i; // [esp+4h] [ebp-8h]
  char message[4]; // [esp+8h] [ebp-4h] BYREF
  CBaseServer *pServera; // [esp+14h] [ebp+8h]

  if ( host_initialized
    && !this->m_bNoMasters
    && pServer->IsMultiplayer(this: pServer)
    && !CBaseServer::ShouldHideFromMasterServer(this: pServer) )
  {
    this->InitConnection(this);
    V_snprintf(pDest: message, maxLen: 4, pFormat: "%c\n", 98);
    i = 0;
    if ( this->m_MasterServers.m_Size > 0 )
    {
      pServera = nullptr;
      do
      {
        v4 = (CMasterserver *)((char *)pServera + (unsigned int)this->m_MasterServers.m_Memory.m_pMemory);
        v5 = _V_strlen(str: message);
        NET_SendPacket(
          chan: nullptr,
          sock: pServer->m_Socket,
          to: &v4->addr,
          data: (unsigned __int8 *)message,
          length: v5 + 1,
          pVoicePayload: nullptr,
          bUseCompression: false,
          unMillisecondsDelay: 0);
        v6 = (CMasterserver *)((char *)pServera + (unsigned int)this->m_MasterServers.m_Memory.m_pMemory);
        m_Size = v6->heartbeats.m_Size;
        v8 = 0;
        if ( m_Size > 0 )
        {
          p_pServer = &v6->heartbeats.m_Memory.m_pMemory->pServer;
          while ( *p_pServer != pServer )
          {
            ++v8;
            p_pServer += 4;
            if ( v8 >= m_Size )
              goto LABEL_15;
          }
          v10 = m_Size - v8 - 1;
          if ( v10 > 0 )
            _V_memmove(
              dest: &v6->heartbeats.m_Memory.m_pMemory[v8],
              src: &v6->heartbeats.m_Memory.m_pMemory[v8 + 1],
              count: 16 * v10);
          --v6->heartbeats.m_Size;
        }
LABEL_15:
        pServera = (CBaseServer *)((char *)pServera + 32);
        ++i;
      }
      while ( i < this->m_MasterServers.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E3D80
// Name: pingserver
// Source: json
//------------------------------------------------------------------------------
void __cdecl pingserver(const CCommand *args)
{
  int m_nArgv0Size; // eax
  const char *v2; // esi
  const char *v3; // eax
  CUtlBuffer msg; // [esp+0h] [ebp-3Ch] BYREF
  netadr_s adr; // [esp+30h] [ebp-Ch] BYREF

  if ( args->m_nArgc >= 2 )
  {
    m_nArgv0Size = args->m_nArgv0Size;
    v2 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( m_nArgv0Size == 0 )
      v2 = defaultValue;
    netadr_s::SetIP(this: &adr, unIP: 0);
    netadr_s::SetPort(this: &adr, newport: 0);
    netadr_s::SetType(this: &adr, newtype: NA_IP);
    netadr_s::SetFromString(this: &adr, pch: v2, bUseDNS: false);
    v3 = netadr_s::ToString(this: &adr, baseOnly: false);
    _Msg(a1: "pinging %s\n", v3);
    CUtlBuffer::CUtlBuffer(this: &msg, growSize: 0, initSize: 0, nFlags: 0);
    if ( (msg.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &msg, pFmt: "%d", -1);
    else
      CUtlBuffer::PutTypeBin<int>(this: &msg, src: -1);
    if ( (msg.m_Flags & 1) != 0 && msg.m_Put != 0 && msg.m_Memory.m_pMemory[msg.m_Put - msg.m_nOffset - 1] == 10 )
      CUtlBuffer::PutTabs(this: &msg);
    if ( CUtlBuffer::CheckPut(this: &msg, nSize: 1) )
    {
      msg.m_Memory.m_pMemory[msg.m_Put++ - msg.m_nOffset] = 84;
      CUtlBuffer::AddNullTermination(this: &msg, nPut: msg.m_Put);
    }
    CUtlBuffer::PutString(this: &msg, pString: "Source Engine Query");
    NET_SendPacket(
      chan: nullptr,
      sock: 0,
      to: &adr,
      data: msg.m_Memory.m_pMemory,
      length: msg.m_Put,
      pVoicePayload: nullptr,
      bUseCompression: false,
      unMillisecondsDelay: 0);
    if ( msg.m_Memory.m_nGrowSize >= 0 && msg.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: msg.m_Memory.m_pMemory);
  }
  else
  {
    ConMsg(a1: "Usage:  pingserver <server:ip>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E3ED0
// Name: private: void CMaster::RebuildPlayers(class CGameServer __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CMaster::RebuildPlayers(
        CMaster *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CGameServer *pServer)
{
  CGameServer *v6; // edi
  int (__thiscall *GetClientCount)(struct CGameServer *); // edx
  S3RGBA *m_pMemory; // esi
  signed int v9; // ebx
  float v10; // eax
  int v11; // edx
  signed int v12; // edi
  float *v13; // edi
  int (__thiscall *v14)(struct CGameServer *); // eax
  int v15; // eax
  signed int v16; // edi
  S3RGBA v17; // esi
  CPlayerState *v18; // ebx
  int (__thiscall *v19)(int); // edx
  int v20; // esi
  const char *v21; // eax
  int frags; // eax
  bf_write *v23; // ebx
  double v24; // st7
  int v25; // eax
  float v29; // [esp+0h] [ebp-24h]
  CUtlMemory<S3RGBA,int> v30; // [esp+4h] [ebp-20h] BYREF
  signed int v31; // [esp+10h] [ebp-14h]
  S3RGBA *v32; // [esp+14h] [ebp-10h]
  float val; // [esp+18h] [ebp-Ch]
  __int64 vecHumans; // [esp+1Ch] [ebp-8h] OVERLAPPED

  this->m_PlayersCache.m_flLastUpdateTime = realtime;
  bf_write::Reset(this: &this->m_PlayersCache.m_Buffer);
  vecHumans = (unsigned int)&this->m_PlayersCache.m_Buffer;
  bf_write::WriteLong(this: &this->m_PlayersCache.m_Buffer, val: -1);
  bf_write::WriteByte(this: &this->m_PlayersCache.m_Buffer, val: 0x44u);
  v6 = pServer;
  GetClientCount = pServer->GetClientCount;
  m_pMemory = nullptr;
  v9 = 0;
  memset(&v30, 0, sizeof(v30));
  v31 = 0;
  v32 = nullptr;
  if ( ((int (__thiscall *)(CGameServer *, int, int, int))GetClientCount)(a1: pServer, a2: a3, a3: a4, a4: a2) > 0 )
  {
    do
    {
      v10 = *(float *)&v6->m_Clients.m_Memory.m_pMemory[HIDWORD(vecHumans)];
      v11 = *(_DWORD *)(LODWORD(v10) + 4);
      val = v10;
      if ( (*(unsigned __int8 (__thiscall **)(int))(v11 + 124))(a1: LODWORD(v10) + 4) != 0
        && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)(LODWORD(val) + 4) + 176))(a1: LODWORD(val) + 4) != 0
        && serverGameClients->GetPlayerState(this: serverGameClients, a2: *(_DWORD *)(LODWORD(val) + 120660)) != nullptr )
      {
        v12 = v9;
        if ( v9 + 1 > v30.m_nAllocationCount )
        {
          CUtlMemory<INetMessage *,int>::Grow(this: &v30, num: v9 - v30.m_nAllocationCount + 1);
          v9 = v31;
          m_pMemory = v30.m_pMemory;
        }
        v31 = ++v9;
        v32 = m_pMemory;
        if ( v9 - v12 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 4 * (v9 - v12 - 1));
        v13 = (float *)&m_pMemory[v12];
        if ( v13 != nullptr )
          *v13 = val;
        v6 = pServer;
      }
      v14 = v6->GetClientCount;
      ++HIDWORD(vecHumans);
      v15 = v14(this: v6);
    }
    while ( SHIDWORD(vecHumans) < v15 );
  }
  bf_write::WriteByte(this: (bf_write *)vecHumans, val: v9);
  v16 = 0;
  if ( v9 > 0 )
  {
    do
    {
      v17 = m_pMemory[v16];
      v18 = serverGameClients->GetPlayerState(this: serverGameClients, a2: *(_DWORD *)(*(_DWORD *)&v17 + 120660));
      if ( v18 != nullptr )
      {
        bf_write::WriteByte(this: (bf_write *)vecHumans, val: v16);
        v19 = *(int (__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)&v17 + 4) + 68);
        v20 = *(_DWORD *)&v17 + 4;
        v21 = (const char *)v19(a1: v20);
        bf_write::WriteString(this: (bf_write *)vecHumans, pStr: v21);
        frags = v18->frags;
        v23 = (bf_write *)vecHumans;
        bf_write::WriteLong(this: (bf_write *)vecHumans, val: frags);
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v20 + 136))(a1: v20) != 0 )
        {
          v24 = -1.0;
        }
        else
        {
          v25 = (*(int (__thiscall **)(int))(*(_DWORD *)v20 + 72))(a1: v20);
          v24 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v25 + 12))(a1: v25);
        }
        v29 = v24;
        bf_write::WriteFloat(this: v23, val: v29);
      }
      m_pMemory = v30.m_pMemory;
      ++v16;
    }
    while ( v16 < v31 );
  }
  if ( v30.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x101E40C0
// Name: public: void CMaster::ReplyPlayers(struct netadr_s __near &,class CGameServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMaster::ReplyPlayers(CMaster *this@<ecx>, int a2@<ebx>, netadr_s *adr, CGameServer *pServer)
{
  if ( !CBaseServer::ShouldHideServer(this: pServer) )
  {
    if ( (float)(realtime - this->m_PlayersCache.m_flLastUpdateTime) >= 0.25 )
      CMaster::RebuildPlayers(this, a2, a3: (int)pServer, a4: (int)this, pServer);
    if ( this->m_PlayersCache.m_Buffer.m_iCurBit > 0 )
      NET_SendPacket(
        chan: nullptr,
        sock: pServer->m_Socket,
        to: adr,
        data: this->m_PlayersCache.m_Buffer.m_pData,
        length: (this->m_PlayersCache.m_Buffer.m_iCurBit + 7) >> 3,
        pVoicePayload: nullptr,
        bUseCompression: false,
        unMillisecondsDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E4140
// Name: public: class CHeartbeat __near * CMaster::GetHeartbeat(class CMasterserver __near *,class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
CHeartbeat *__thiscall CMaster::GetHeartbeat(CMaster *this, CMasterserver *pMasterServer, CBaseServer *pServer)
{
  int m_Size; // ecx
  int v4; // eax
  CHeartbeat *v5; // edi
  CBaseServer **p_pServer; // edx
  int m_nAllocationCount; // eax
  int v8; // edi
  CHeartbeat *m_pMemory; // ecx
  int v10; // eax
  CHeartbeat *result; // eax

  m_Size = pMasterServer->heartbeats.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    m_nAllocationCount = pMasterServer->heartbeats.m_Memory.m_nAllocationCount;
    v8 = pMasterServer->heartbeats.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CPortalRect,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&pMasterServer->heartbeats,
        num: v8 - m_nAllocationCount + 1);
    ++pMasterServer->heartbeats.m_Size;
    m_pMemory = pMasterServer->heartbeats.m_Memory.m_pMemory;
    v10 = pMasterServer->heartbeats.m_Size - v8 - 1;
    pMasterServer->heartbeats.m_pElements = m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 16 * v10);
    result = &pMasterServer->heartbeats.m_Memory.m_pMemory[v8];
    result->last_heartbeat = -9999.0;
    result->pServer = pServer;
    result->challangenr = -1;
    result->challengetime = 0.0;
  }
  else
  {
    v5 = pMasterServer->heartbeats.m_Memory.m_pMemory;
    p_pServer = &v5->pServer;
    while ( *p_pServer != pServer )
    {
      ++v4;
      p_pServer += 4;
      if ( v4 >= m_Size )
        goto LABEL_5;
    }
    return &v5[v4];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E41F0
// Name: public: virtual void CMaster::CheckHeartbeat(class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::CheckHeartbeat(CMaster *this, CBaseServer *pServer)
{
  int v4; // edi
  CHeartbeat *Heartbeat; // eax
  int i; // [esp+8h] [ebp-Ch]
  int m_nValue; // [esp+Ch] [ebp-8h]
  unsigned __int8 c; // [esp+13h] [ebp-1h] BYREF
  char bPrintedMessage_3; // [esp+1Fh] [ebp+Bh]

  if ( (NET_IsDedicatedForXbox()
     || sv_master_legacy_mode.m_pParent != nullptr && sv_master_legacy_mode.m_pParent->m_Value.m_nValue != 0
     || Steam3Server()->m_pSteamMasterServerUpdater == nullptr)
    && !this->m_bNoMasters
    && pServer->IsActive(this: pServer)
    && pServer->IsMultiplayer(this: pServer)
    && !CBaseServer::ShouldHideFromMasterServer(this: pServer) )
  {
    this->InitConnection(this);
    v4 = 0;
    c = 113;
    bPrintedMessage_3 = 0;
    for ( i = 0; i < this->m_MasterServers.m_Size; ++i )
    {
      Heartbeat = CMaster::GetHeartbeat(this, pMasterServer: &this->m_MasterServers.m_Memory.m_pMemory[v4], pServer);
      if ( Heartbeat != nullptr && (double)this->m_iHeartBeatTimeout <= net_time - Heartbeat->last_heartbeat )
      {
        if ( Heartbeat->challengetime <= 0.0
          || (mm_heartbeat_timeout.m_pParent == nullptr
            ? (m_nValue = 0)
            : (m_nValue = mm_heartbeat_timeout.m_pParent->m_Value.m_nValue),
              (double)m_nValue <= net_time - Heartbeat->challengetime) )
        {
          Heartbeat->challengetime = net_time;
          Heartbeat->last_heartbeat = net_time;
          if ( bPrintedMessage_3 == 0 )
          {
            bPrintedMessage_3 = 1;
            _Msg(a1: "Sending heartbeat to master server...\n");
          }
          NET_SendPacket(
            chan: nullptr,
            sock: pServer->m_Socket,
            to: &this->m_MasterServers.m_Memory.m_pMemory[v4].addr,
            data: &c,
            length: 1,
            pVoicePayload: nullptr,
            bUseCompression: false,
            unMillisecondsDelay: 0);
        }
      }
      ++v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E4350
// Name: public: virtual void CMaster::HandleUnknown(struct netpacket_s __near *,class CBaseServer __near *,class CGameServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::HandleUnknown(
        CMaster *this,
        netpacket_s *packet,
        CBaseServer *pServer,
        CGameServer *pGameServer)
{
  int m_nBitsAvail; // edx
  const unsigned int *m_pDataIn; // eax
  int v6; // ecx
  unsigned int v7; // esi
  unsigned int m_nInBufWord; // ebx
  int v9; // edi
  int v10; // esi
  const unsigned int *m_pBufferEnd; // ebx
  const unsigned int *v12; // eax
  unsigned int v13; // edx
  int v14; // edi
  unsigned int v15; // ebx
  int v16; // eax
  int v17; // edi
  unsigned int v18; // ecx
  unsigned int v19; // edx
  unsigned int v20; // eax
  unsigned int v21; // edi
  int v22; // eax
  unsigned int v23; // esi
  int m_nDataBits; // eax
  int v25; // ecx
  int v26; // ebx
  int v27; // edi
  unsigned int v28; // eax
  int v29; // ecx
  int v30; // edi
  unsigned int v31; // ebx
  unsigned int v32; // eax
  char nugget[64]; // [esp+Ch] [ebp-6Ch] BYREF
  bf_read msg; // [esp+4Ch] [ebp-2Ch] BYREF
  int challengeNr; // [esp+70h] [ebp-8h]
  CMaster *v36; // [esp+74h] [ebp-4h]
  int pGameServera; // [esp+88h] [ebp+10h]

  v36 = this;
  msg = packet->message;
  m_nBitsAvail = msg.m_nBitsAvail;
  m_pDataIn = msg.m_pDataIn;
  if ( msg.m_nBitsAvail >= 8 )
  {
    LOBYTE(v6) = msg.m_nInBufWord;
    m_nBitsAvail = msg.m_nBitsAvail - 8;
    msg.m_nBitsAvail = m_nBitsAvail;
    if ( m_nBitsAvail != 0 )
    {
      v7 = msg.m_nInBufWord >> 8;
    }
    else
    {
      m_nBitsAvail = 32;
      msg.m_nBitsAvail = 32;
      if ( msg.m_pDataIn == msg.m_pBufferEnd )
      {
        v7 = 0;
        m_nBitsAvail = 1;
        m_pDataIn = msg.m_pDataIn + 1;
        msg.m_nBitsAvail = 1;
        ++msg.m_pDataIn;
      }
      else if ( msg.m_pDataIn <= msg.m_pBufferEnd )
      {
        v7 = *msg.m_pDataIn;
        m_pDataIn = ++msg.m_pDataIn;
      }
      else
      {
        msg.m_bOverflow = true;
        v7 = 0;
      }
    }
    goto LABEL_16;
  }
  m_nInBufWord = msg.m_nInBufWord;
  v9 = 8 - msg.m_nBitsAvail;
  if ( msg.m_pDataIn == msg.m_pBufferEnd )
  {
    m_nBitsAvail = 1;
    v7 = 0;
    m_pDataIn = msg.m_pDataIn + 1;
    LOBYTE(v6) = 0;
    msg.m_nBitsAvail = 1;
    msg.m_nInBufWord = 0;
    ++msg.m_pDataIn;
    msg.m_bOverflow = true;
  }
  else if ( msg.m_pDataIn <= msg.m_pBufferEnd )
  {
    v7 = *msg.m_pDataIn;
    m_pDataIn = msg.m_pDataIn + 1;
    msg.m_nInBufWord = *msg.m_pDataIn++;
    if ( !msg.m_bOverflow )
    {
      challengeNr = v7 & CBitBuffer::s_nMaskTable[v9];
      v7 >>= v9;
      m_nBitsAvail = 32 - v9;
      v6 = (challengeNr << SLOBYTE(msg.m_nBitsAvail)) | m_nInBufWord;
      msg.m_nBitsAvail = 32 - v9;
LABEL_16:
      msg.m_nInBufWord = v7;
      goto LABEL_17;
    }
    LOBYTE(v6) = 0;
  }
  else
  {
    v7 = 0;
    LOBYTE(v6) = 0;
    msg.m_bOverflow = true;
    msg.m_nInBufWord = 0;
  }
LABEL_17:
  switch ( (char)v6 )
  {
    case 'O':
      if ( !v36->IsMasterServerAddress(this: v36, a2: (netadr_s *)packet) )
        return;
      v21 = msg.m_nInBufWord;
      if ( msg.m_nBitsAvail < 32 )
      {
        v22 = 32 - msg.m_nBitsAvail;
        if ( msg.m_pDataIn == msg.m_pBufferEnd )
        {
          msg.m_nBitsAvail = 1;
          msg.m_nInBufWord = 0;
          ++msg.m_pDataIn;
          msg.m_bOverflow = true;
          v21 = 0;
        }
        else if ( msg.m_pDataIn <= msg.m_pBufferEnd )
        {
          v23 = *msg.m_pDataIn;
          msg.m_nInBufWord = *msg.m_pDataIn++;
          if ( !msg.m_bOverflow )
          {
            v21 |= (v23 & CBitBuffer::s_nMaskTable[v22]) << SLOBYTE(msg.m_nBitsAvail);
            msg.m_nInBufWord = v23 >> v22;
            goto LABEL_59;
          }
          v21 = 0;
        }
        else
        {
          msg.m_bOverflow = true;
          msg.m_nInBufWord = 0;
          v21 = 0;
        }
      }
      else
      {
        msg.m_nBitsAvail -= 32;
        if ( msg.m_nBitsAvail != 0 )
        {
LABEL_57:
          msg.m_nInBufWord = 0;
          goto LABEL_58;
        }
        msg.m_nBitsAvail = 32;
        if ( msg.m_pDataIn == msg.m_pBufferEnd )
        {
          msg.m_nBitsAvail = 1;
          msg.m_nInBufWord = 0;
          ++msg.m_pDataIn;
          goto LABEL_58;
        }
        if ( msg.m_pDataIn > msg.m_pBufferEnd )
        {
          msg.m_bOverflow = true;
          goto LABEL_57;
        }
        msg.m_nInBufWord = *msg.m_pDataIn++;
      }
LABEL_58:
      if ( msg.m_bOverflow )
        return;
LABEL_59:
      if ( v36->IsCorrectMasterChallenge(this: v36, a2: (netadr_s *)packet, a3: v21, a4: pServer) )
      {
        _Msg(a1: "%cMasterRequestRestart\n", 3);
        if ( g_pFileSystem->IsSteam(this: g_pFileSystem) )
        {
          _Msg(a1: "Your server needs to be restarted in order to receive the latest update.\n");
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SERVER_LOG, a2: 0) != 0 )
            _LoggingSystem_Log(
              a1: LOG_SERVER_LOG,
              a2: 0,
              a3: "Your server needs to be restarted in order to receive the latest update.\n");
        }
        else
        {
          _Msg(a1: "Your server is out of date.  Please update and restart.\n");
        }
      }
      return;
    case 'T':
      nugget[0] = 0;
      if ( msg.m_pData != nullptr )
      {
        m_nDataBits = 8 * (msg.m_nDataBytes & 3) + 32 * (m_pDataIn - msg.m_pData) - m_nBitsAvail;
        if ( m_nDataBits >= msg.m_nDataBits )
          m_nDataBits = msg.m_nDataBits;
      }
      else
      {
        m_nDataBits = 0;
      }
      if ( (msg.m_nDataBits - m_nDataBits) >> 3 >= _V_strlen(str: "Source Engine Query") )
      {
        CBitRead::ReadString(this: &msg, pStr: nugget, maxLen: 62, bLine: false, pOutNumChars: nullptr);
        nugget[63] = 0;
      }
      if ( CBaseServer::ValidInfoChallenge(this: pServer, adr: &packet->from, nugget) )
        CMaster::ReplyInfo(this: v36, adr: &packet->from, pServer);
      return;
    case 'U':
      challengeNr = -1;
      if ( msg.m_pData != nullptr )
      {
        v25 = 32 * (m_pDataIn - msg.m_pData) - m_nBitsAvail + 8 * (msg.m_nDataBytes & 3);
        if ( v25 >= msg.m_nDataBits )
          v25 = msg.m_nDataBits;
      }
      else
      {
        v25 = 0;
      }
      v26 = (msg.m_nDataBits - v25) & 0xFFFFFFF8;
      if ( v26 >= 32 )
      {
        if ( m_nBitsAvail < 32 )
        {
          v27 = 32 - m_nBitsAvail;
          if ( m_pDataIn == msg.m_pBufferEnd )
          {
            msg.m_nBitsAvail = 1;
            msg.m_nInBufWord = 0;
            msg.m_pDataIn = m_pDataIn + 1;
            msg.m_bOverflow = true;
            v7 = 0;
          }
          else if ( m_pDataIn <= msg.m_pBufferEnd )
          {
            v26 = *m_pDataIn;
            msg.m_nInBufWord = *m_pDataIn;
            msg.m_pDataIn = m_pDataIn + 1;
            if ( msg.m_bOverflow )
            {
              v7 = 0;
            }
            else
            {
              v28 = (v26 & CBitBuffer::s_nMaskTable[v27]) << m_nBitsAvail;
              msg.m_nBitsAvail = m_nBitsAvail;
              v7 |= v28;
              v26 = (unsigned int)v26 >> v27;
              msg.m_nInBufWord = v26;
            }
          }
          else
          {
            msg.m_bOverflow = true;
            msg.m_nInBufWord = 0;
            v7 = 0;
          }
        }
        else
        {
          msg.m_nBitsAvail = m_nBitsAvail - 32;
          if ( m_nBitsAvail == 32 )
          {
            msg.m_nBitsAvail = 32;
            if ( m_pDataIn == msg.m_pBufferEnd )
            {
              msg.m_nBitsAvail = 1;
              msg.m_nInBufWord = 0;
              msg.m_pDataIn = m_pDataIn + 1;
            }
            else if ( m_pDataIn <= msg.m_pBufferEnd )
            {
              msg.m_nInBufWord = *m_pDataIn;
              msg.m_pDataIn = m_pDataIn + 1;
            }
            else
            {
              msg.m_bOverflow = true;
              msg.m_nInBufWord = 0;
            }
          }
          else
          {
            msg.m_nInBufWord = 0;
          }
        }
        challengeNr = v7;
      }
      if ( CBaseServer::ValidChallenge(this: pServer, adr: &packet->from, challengeNr) != 0 && pGameServer != nullptr )
        CMaster::ReplyPlayers(this: v36, a2: v26, adr: &packet->from, pServer: pGameServer);
      return;
    case 'V':
      pGameServera = -1;
      if ( msg.m_pData != nullptr )
      {
        v29 = 32 * (m_pDataIn - msg.m_pData) - m_nBitsAvail + 8 * (msg.m_nDataBytes & 3);
        if ( v29 >= msg.m_nDataBits )
          v29 = msg.m_nDataBits;
      }
      else
      {
        v29 = 0;
      }
      if ( (int)((msg.m_nDataBits - v29) & 0xFFFFFFF8) >= 32 )
      {
        if ( m_nBitsAvail < 32 )
        {
          v30 = 32 - m_nBitsAvail;
          if ( m_pDataIn == msg.m_pBufferEnd )
          {
            msg.m_nBitsAvail = 1;
            msg.m_nInBufWord = 0;
            msg.m_pDataIn = m_pDataIn + 1;
            msg.m_bOverflow = true;
            v7 = 0;
          }
          else if ( m_pDataIn <= msg.m_pBufferEnd )
          {
            v31 = *m_pDataIn;
            msg.m_nInBufWord = *m_pDataIn;
            msg.m_pDataIn = m_pDataIn + 1;
            if ( msg.m_bOverflow )
            {
              v7 = 0;
            }
            else
            {
              v32 = (v31 & CBitBuffer::s_nMaskTable[v30]) << m_nBitsAvail;
              msg.m_nBitsAvail = m_nBitsAvail;
              v7 |= v32;
              msg.m_nInBufWord = v31 >> v30;
            }
          }
          else
          {
            msg.m_bOverflow = true;
            msg.m_nInBufWord = 0;
            v7 = 0;
          }
        }
        else
        {
          msg.m_nBitsAvail = m_nBitsAvail - 32;
          if ( m_nBitsAvail == 32 )
          {
            msg.m_nBitsAvail = 32;
            if ( m_pDataIn == msg.m_pBufferEnd )
            {
              msg.m_nBitsAvail = 1;
              msg.m_nInBufWord = 0;
              msg.m_pDataIn = m_pDataIn + 1;
            }
            else if ( m_pDataIn <= msg.m_pBufferEnd )
            {
              msg.m_nInBufWord = *m_pDataIn;
              msg.m_pDataIn = m_pDataIn + 1;
            }
            else
            {
              msg.m_bOverflow = true;
              msg.m_nInBufWord = 0;
            }
          }
          else
          {
            msg.m_nInBufWord = 0;
          }
        }
        pGameServera = v7;
      }
      if ( CBaseServer::ValidChallenge(this: pServer, adr: &packet->from, challengeNr: pGameServera) != 0 )
        CMaster::ReplyRules(this: v36, from: &packet->from, pServer);
      return;
    case 's':
      if ( !v36->IsMasterServerAddress(this: v36, a2: (netadr_s *)packet) )
        return;
      v10 = msg.m_nBitsAvail;
      m_pBufferEnd = msg.m_pBufferEnd;
      v12 = msg.m_pDataIn;
      if ( msg.m_nBitsAvail < 8 )
      {
        v17 = 8 - msg.m_nBitsAvail;
        if ( msg.m_pDataIn == msg.m_pBufferEnd )
        {
          v13 = 0;
          v10 = 1;
          v12 = msg.m_pDataIn + 1;
          msg.m_nBitsAvail = 1;
          msg.m_nInBufWord = 0;
          ++msg.m_pDataIn;
          msg.m_bOverflow = true;
          goto LABEL_24;
        }
        if ( msg.m_pDataIn <= msg.m_pBufferEnd )
        {
          v13 = *msg.m_pDataIn;
          v12 = msg.m_pDataIn + 1;
          msg.m_nInBufWord = *msg.m_pDataIn++;
          if ( msg.m_bOverflow )
            goto LABEL_36;
          v10 = 32 - v17;
          msg.m_nBitsAvail = 32 - v17;
          v13 >>= v17;
        }
        else
        {
          msg.m_bOverflow = true;
          v13 = 0;
        }
      }
      else
      {
        v10 = msg.m_nBitsAvail - 8;
        msg.m_nBitsAvail = v10;
        if ( v10 == 0 )
        {
          m_pBufferEnd = msg.m_pBufferEnd;
          v10 = 32;
          msg.m_nBitsAvail = 32;
          if ( msg.m_pDataIn != msg.m_pBufferEnd )
          {
            if ( msg.m_pDataIn <= msg.m_pBufferEnd )
            {
              v13 = *msg.m_pDataIn;
              v12 = msg.m_pDataIn + 1;
              msg.m_nInBufWord = *msg.m_pDataIn++;
            }
            else
            {
              v13 = 0;
              msg.m_bOverflow = true;
              msg.m_nInBufWord = 0;
            }
LABEL_37:
            msg.m_nBitsAvail = v10 - 32;
            if ( v10 == 32 )
            {
              msg.m_nBitsAvail = 32;
              if ( v12 == m_pBufferEnd )
              {
                msg.m_pDataIn = v12 + 1;
                msg.m_nBitsAvail = 1;
                msg.m_nInBufWord = 0;
                v16 = v13;
LABEL_49:
                v36->SendHeartbeat(this: v36, a2: (netadr_s *)packet, a3: v16, a4: pServer);
                return;
              }
              if ( v12 <= m_pBufferEnd )
              {
                v18 = *v12;
                msg.m_pDataIn = v12 + 1;
                msg.m_nInBufWord = v18;
                v16 = v13;
                goto LABEL_49;
              }
              msg.m_bOverflow = true;
            }
            msg.m_nInBufWord = 0;
            v16 = v13;
            goto LABEL_49;
          }
          v13 = 0;
          v10 = 1;
          v12 = msg.m_pDataIn + 1;
          msg.m_nBitsAvail = 1;
          msg.m_nInBufWord = 0;
          ++msg.m_pDataIn;
LABEL_24:
          v14 = 32 - v10;
          v15 = v13;
          if ( v12 == msg.m_pBufferEnd )
          {
            msg.m_pDataIn = v12 + 1;
            msg.m_nBitsAvail = 1;
            msg.m_nInBufWord = 0;
            msg.m_bOverflow = true;
            v16 = 0;
          }
          else if ( v12 <= msg.m_pBufferEnd )
          {
            v19 = *v12;
            msg.m_nInBufWord = *v12;
            msg.m_pDataIn = v12 + 1;
            if ( msg.m_bOverflow )
            {
              v16 = 0;
            }
            else
            {
              v20 = (v19 & CBitBuffer::s_nMaskTable[v14]) << v10;
              msg.m_nBitsAvail = v10;
              v16 = v15 | v20;
              msg.m_nInBufWord = v19 >> v14;
            }
          }
          else
          {
            msg.m_bOverflow = true;
            msg.m_nInBufWord = 0;
            v16 = 0;
          }
          goto LABEL_49;
        }
        v13 = msg.m_nInBufWord >> 8;
      }
      msg.m_nInBufWord = v13;
LABEL_36:
      if ( v10 >= 32 )
        goto LABEL_37;
      goto LABEL_24;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E4B90
// Name: public: virtual void CMaster::SendHeartbeat(struct netadr_s __near &,int,class CBaseServer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::SendHeartbeat(CMaster *this, netadr_s *adr, int challangenr, CBaseServer *pServer)
{
  int v5; // edi
  int i; // ebx
  CMasterserver *v7; // edi
  CHeartbeat *Heartbeat; // ecx
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  int v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  bool v18; // zf
  const char *v19; // eax
  char *m_pszString; // eax
  const char *GameType; // esi
  const char *v22; // eax
  CSteam3Server *v23; // eax
  const char *v24; // eax
  const char *VersionString; // eax
  const char *ProductString; // eax
  const char *v27; // eax
  char *v28; // eax
  int v29; // eax
  const char *v30; // [esp-10h] [ebp-928h]
  const char *v31; // [esp-10h] [ebp-928h]
  char szGD[260]; // [esp+4h] [ebp-914h] BYREF
  char info[2048]; // [esp+108h] [ebp-810h] BYREF
  int nBots; // [esp+908h] [ebp-10h] BYREF
  int nHumans; // [esp+90Ch] [ebp-Ch] BYREF
  int nMaxHumans; // [esp+910h] [ebp-8h] BYREF
  char szOS[4]; // [esp+914h] [ebp-4h] BYREF
  int bHasPW; // [esp+928h] [ebp+10h]
  bool bHasPW_3; // [esp+92Bh] [ebp+13h]

  if ( (NET_IsDedicatedForXbox()
     || sv_master_legacy_mode.m_pParent != nullptr && sv_master_legacy_mode.m_pParent->m_Value.m_nValue != 0
     || Steam3Server()->m_pSteamMasterServerUpdater == nullptr)
    && pServer->IsMultiplayer(this: pServer)
    && !CBaseServer::IsSinglePlayerGame(this: pServer)
    && !CBaseServer::ShouldHideFromMasterServer(this: pServer) )
  {
    v5 = 0;
    if ( this->m_MasterServers.m_Size > 0 )
    {
      for ( i = 0;
            !netadr_s::CompareAdr(this: adr, a: &this->m_MasterServers.m_Memory.m_pMemory[i].addr, onlyBase: false);
            ++i )
      {
        if ( ++v5 >= this->m_MasterServers.m_Size )
          return;
      }
      v7 = &this->m_MasterServers.m_Memory.m_pMemory[v5];
      if ( v7 != nullptr )
      {
        Heartbeat = CMaster::GetHeartbeat(this, pMasterServer: v7, pServer);
        if ( Heartbeat != nullptr )
        {
          bHasPW = mm_heartbeat_timeout_legacy.m_pParent != nullptr
                 ? mm_heartbeat_timeout_legacy.m_pParent->m_Value.m_nValue
                 : 0;
          if ( net_time - Heartbeat->challengetime < (double)bHasPW )
          {
            Heartbeat->challengetime = 0.0;
            Heartbeat->challangenr = challangenr;
            this->InitConnection(this);
            _V_memset(dest: message, fill: 0, count: 2053);
            CBaseServer::GetMasterServerPlayerCounts(this: &sv, &nHumans, nMaxHumanSlots: &nMaxHumans, &nBots);
            V_FileBase(in: com_gamedir, out: szGD, maxlen: 260);
            bHasPW_3 = pServer->GetPassword(this: pServer) != nullptr;
            _V_strcpy(dest: szOS, src: "w");
            info[0] = 0;
            CBaseServer::UpdateGameType(this: &sv);
            v10 = va(format: "%i", 7);
            Info_SetValueForKey(s: info, key: "protocol", value: v10, maxsize: 2048);
            v11 = va(format: "%i", challangenr);
            Info_SetValueForKey(s: info, key: "challenge", value: v11, maxsize: 2048);
            v12 = va(format: "%i", nBots);
            Info_SetValueForKey(s: info, key: "bots", value: v12, maxsize: 2048);
            if ( tv_enable.m_pParent != nullptr && tv_enable.m_pParent->m_Value.m_nValue != 0 )
            {
              if ( nHumans <= 0 )
                v13 = 0;
              else
                v13 = nHumans - 1;
              v14 = va(format: "%i", v13);
              Info_SetValueForKey(s: info, key: "players", value: v14, maxsize: 2048);
              v30 = va(format: "%i", nMaxHumans - 1);
              Info_SetValueForKey(s: info, key: "max", value: v30, maxsize: 2048);
            }
            else
            {
              v15 = va(format: "%i", nHumans);
              Info_SetValueForKey(s: info, key: "players", value: v15, maxsize: 2048);
              v31 = va(format: "%i", nMaxHumans);
              Info_SetValueForKey(s: info, key: "max", value: v31, maxsize: 2048);
            }
            Info_SetValueForStarKey(s: info, key: "gamedir", value: szGD, maxsize: 2048);
            v16 = pServer->GetMapName(this: pServer);
            Info_SetValueForKey(s: info, key: "map", value: v16, maxsize: 2048);
            v17 = "1";
            if ( !bHasPW_3 )
              v17 = "0";
            Info_SetValueForKey(s: info, key: "password", value: v17, maxsize: 2048);
            Info_SetValueForStarKey(s: info, key: "os", value: szOS, maxsize: 2048);
            v18 = Steam3Server()->m_eServerMode == eServerModeNoAuthentication;
            v19 = "1";
            if ( !v18 )
              v19 = "0";
            Info_SetValueForKey(s: info, key: "lan", value: v19, maxsize: 2048);
            if ( (sv_region.m_nFlags & 0x1000) != 0 )
            {
              m_pszString = "FCVAR_NEVER_AS_STRING";
            }
            else
            {
              m_pszString = sv_region.m_pParent->m_Value.m_pszString;
              if ( m_pszString == nullptr )
                m_pszString = (char *)defaultValue;
            }
            Info_SetValueForKey(s: info, key: "region", value: m_pszString, maxsize: 2048);
            GameType = CBaseServer::GetGameType(this: &sv, eResultType: EGAMETYPE_RESULTS_INCLUDE_PRIVATE);
            if ( pServer->IsHLTV(this: pServer) )
              GameType = defaultValue;
            Info_SetValueForKey(s: info, key: "gametype", value: GameType, maxsize: 2048);
            if ( pServer->IsHLTV(this: pServer) )
            {
              Info_SetValueForKey(s: info, key: "type", value: "p", maxsize: 2048);
              Info_SetValueForKey(s: info, key: "secure", value: "0", maxsize: 2048);
              Info_SetValueForKey(s: info, key: "version", value: "1.0.0.0", maxsize: 2048);
              Info_SetValueForKey(s: info, key: "product", value: "srctv", maxsize: 2048);
            }
            else
            {
              v18 = !pServer->IsDedicated(this: pServer);
              v22 = "d";
              if ( v18 )
                v22 = "l";
              Info_SetValueForKey(s: info, key: "type", value: v22, maxsize: 2048);
              v23 = Steam3Server();
              v18 = !CSteam3Server::BSecure(this: v23);
              v24 = "1";
              if ( v18 )
                v24 = "0";
              Info_SetValueForKey(s: info, key: "secure", value: v24, maxsize: 2048);
              VersionString = Sys_GetVersionString();
              Info_SetValueForKey(s: info, key: "version", value: VersionString, maxsize: 2048);
              ProductString = Sys_GetProductString();
              Info_SetValueForKey(s: info, key: "product", value: ProductString, maxsize: 2048);
            }
            if ( pServer->m_bIsDedicatedForXbox )
            {
              v18 = !CBaseServer::IsReserved(this: pServer);
              v27 = "1";
              if ( v18 )
                v27 = "0";
              Info_SetValueForKey(s: info, key: "reserved", value: v27, maxsize: 2048);
              if ( (sv_search_key.m_nFlags & 0x1000) != 0 )
              {
                v28 = "FCVAR_NEVER_AS_STRING";
              }
              else
              {
                v28 = sv_search_key.m_pParent->m_Value.m_pszString;
                if ( v28 == nullptr )
                  v28 = (char *)defaultValue;
              }
              Info_SetValueForKey(s: info, key: "private", value: v28, maxsize: 2048);
            }
            V_snprintf(pDest: message, maxLen: 2053, pFormat: "%c\n%s\n", 48, info);
            v29 = _V_strlen(str: message);
            NET_SendPacket(
              chan: nullptr,
              sock: pServer->m_Socket,
              to: adr,
              data: (unsigned __int8 *)message,
              length: v29,
              pVoicePayload: nullptr,
              bUseCompression: false,
              unMillisecondsDelay: 0);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E5200
// Name: public: virtual bool CMaster::AddServer(struct netadr_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMaster::AddServer(CMaster *this, netadr_s *adr)
{
  if ( this->IsMasterServerAddress(this, a2: adr) )
    return 0;
  this->m_MasterServers.m_Memory.m_pMemory[CUtlVector<CMasterserver,CUtlMemory<CMasterserver,int>>::InsertBefore(
                                             this: &this->m_MasterServers,
                                             elem: this->m_MasterServers.m_Size)].addr = *adr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E5250
// Name: public: virtual bool CMaster::RemoveServer(struct netadr_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMaster::RemoveServer(CMaster *this, netadr_s *adr)
{
  int v3; // ebx
  int i; // esi
  int v6; // ecx
  CMasterserver *v7; // esi
  bool v8; // sf
  CHeartbeat *m_pMemory; // eax

  v3 = 0;
  if ( this->m_MasterServers.m_Size <= 0 )
    return 0;
  for ( i = 0; !netadr_s::CompareAdr(this: &this->m_MasterServers.m_Memory.m_pMemory[i].addr, a: adr, onlyBase: false); ++i )
  {
    if ( ++v3 >= this->m_MasterServers.m_Size )
      return 0;
  }
  v6 = v3;
  v7 = &this->m_MasterServers.m_Memory.m_pMemory[v3];
  v8 = v7->heartbeats.m_Memory.m_nGrowSize < 0;
  v7->heartbeats.m_Size = 0;
  if ( !v8 )
  {
    if ( v7->heartbeats.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7->heartbeats.m_Memory.m_pMemory);
      v6 = v3;
      v7->heartbeats.m_Memory.m_pMemory = nullptr;
    }
    v7->heartbeats.m_Memory.m_nAllocationCount = 0;
  }
  v8 = v7->heartbeats.m_Memory.m_nGrowSize < 0;
  m_pMemory = v7->heartbeats.m_Memory.m_pMemory;
  v7->heartbeats.m_pElements = m_pMemory;
  if ( !v8 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      v6 = v3;
      v7->heartbeats.m_Memory.m_pMemory = nullptr;
    }
    v7->heartbeats.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_MasterServers.m_Size - v3 - 1 > 0 )
    _V_memmove(
      dest: &this->m_MasterServers.m_Memory.m_pMemory[v6],
      src: &this->m_MasterServers.m_Memory.m_pMemory[v6 + 1],
      count: 32 * (this->m_MasterServers.m_Size - v3 - 1));
  --this->m_MasterServers.m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E5330
// Name: public: virtual void CMaster::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::Shutdown(CMaster *this)
{
  CUtlVector<CMasterserver,CUtlMemory<CMasterserver,int> > *p_m_MasterServers; // esi
  CMasterserver *m_pMemory; // ecx

  p_m_MasterServers = &this->m_MasterServers;
  CUtlVector<CMasterserver,CUtlMemory<CMasterserver,int>>::RemoveAll(this: &this->m_MasterServers);
  if ( p_m_MasterServers->m_Memory.m_nGrowSize < 0 )
  {
    p_m_MasterServers->m_pElements = p_m_MasterServers->m_Memory.m_pMemory;
  }
  else
  {
    if ( p_m_MasterServers->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_MasterServers->m_Memory.m_pMemory);
      p_m_MasterServers->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = p_m_MasterServers->m_Memory.m_pMemory;
    p_m_MasterServers->m_Memory.m_nAllocationCount = 0;
    p_m_MasterServers->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E53E0
// Name: public: CMaster::CMaster(void)
// Source: json
//------------------------------------------------------------------------------
CMaster *__thiscall CMaster::CMaster(CMaster *this)
{
  unsigned __int8 *m_Data; // edi

  this->__vftable = (CMaster_vtbl *)&CMaster::`vftable';
  m_Data = this->m_InfoCache.m_Data;
  this->m_MasterServers.m_Memory.m_pMemory = nullptr;
  this->m_MasterServers.m_Memory.m_nAllocationCount = 0;
  this->m_MasterServers.m_Memory.m_nGrowSize = 0;
  this->m_MasterServers.m_Size = 0;
  this->m_MasterServers.m_pElements = nullptr;
  this->m_InfoCache.m_flLastUpdateTime = 0.0;
  bf_write::bf_write(
    this: &this->m_InfoCache.m_Buffer,
    pDebugName: "SVC_Info",
    pData: this->m_InfoCache.m_Data,
    nBytes: 1200,
    nBits: -1);
  _V_memset(dest: m_Data, fill: 0, count: 1200);
  this->m_RulesCache.m_flLastUpdateTime = 0.0;
  bf_write::bf_write(
    this: &this->m_RulesCache.m_Buffer,
    pDebugName: "SVC_Rules",
    pData: this->m_RulesCache.m_Data,
    nBytes: 1200,
    nBits: -1);
  _V_memset(dest: this->m_RulesCache.m_Data, fill: 0, count: 1200);
  this->m_PlayersCache.m_flLastUpdateTime = 0.0;
  bf_write::bf_write(
    this: &this->m_PlayersCache.m_Buffer,
    pDebugName: "SVC_Players",
    pData: this->m_PlayersCache.m_Data,
    nBytes: 1200,
    nBits: -1);
  _V_memset(dest: this->m_PlayersCache.m_Data, fill: 0, count: 1200);
  this->m_bNoMasters = false;
  this->m_bRestartOnLevelChange = false;
  this->m_hSteamDLL = nullptr;
  this->m_iHeartBeatTimeout = 300;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E54C0
// Name: public: virtual bool CMaster::RestartOnLevelChange(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMaster::RestartOnLevelChange(CMaster *this)
{
  return this->m_bRestartOnLevelChange;
}

//------------------------------------------------------------------------------
// Address: 0x101E54D0
// Name: public: virtual void CMaster::SetRestartOnLevelChange(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaster::SetRestartOnLevelChange(CMaster *this, bool state)
{
  this->m_bRestartOnLevelChange = state;
}

} // namespace engine_xlsp
