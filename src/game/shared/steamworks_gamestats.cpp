// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/steamworks_gamestats.cpp
// Functions: 47
// ============================================================

#include "game\shared\steamworks_gamestats.h"

//------------------------------------------------------------------------------
// Address: 0x10171B70
// Name: public: __int64 CSteamWorksGameStatsUploader::GetTimeSinceEpoch(void)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall CSteamWorksGameStatsUploader::GetTimeSinceEpoch(CSteamWorksGameStatsUploader *this)
{
  ISteamUtils *m_pSteamUtils; // ecx
  __int64 aclock; // [esp+0h] [ebp-8h] BYREF

  if ( steamapicontext != nullptr )
  {
    m_pSteamUtils = steamapicontext->m_pSteamUtils;
    if ( m_pSteamUtils != nullptr )
      return m_pSteamUtils->GetServerRealTime(this: m_pSteamUtils);
  }
  _time64(timeptr: &aclock);
  return aclock;
}

//------------------------------------------------------------------------------
// Address: 0x10171BB0
// Name: class CSteamWorksGameStatsUploader __near & GetSteamWorksSGameStatsUploader(void)
// Source: json
//------------------------------------------------------------------------------
CSteamWorksGameStatsUploader *__cdecl GetSteamWorksSGameStatsUploader()
{
  return &g_SteamWorksGameStats;
}

//------------------------------------------------------------------------------
// Address: 0x10171BC0
// Name: public: void CSteamWorksGameStatsUploader::Steam_OnSteamSessionInfoClosed(struct GameStatsSessionClosed_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamWorksGameStatsUploader::Steam_OnSteamSessionInfoClosed(
        CSteamWorksGameStatsUploader *this,
        GameStatsSessionClosed_t *pGameStatsSessionInfo)
{
  if ( this->m_UploadedStats )
    this->m_UploadedStats = false;
}

//------------------------------------------------------------------------------
// Address: 0x10171BE0
// Name: private: bool CSteamWorksGameStatsUploader::AccessToSteamAPI(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteamWorksGameStatsUploader::AccessToSteamAPI(CSteamWorksGameStatsUploader *this)
{
  return steamapicontext != nullptr
      && steamapicontext->m_pSteamUser != nullptr
      && steamapicontext->m_pSteamUser->BLoggedOn(this: steamapicontext->m_pSteamUser)
      && steamapicontext->m_pSteamFriends != nullptr
      && steamapicontext->m_pSteamMatchmaking != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10171C20
// Name: private: class ISteamGameStats __near * CSteamWorksGameStatsUploader::GetInterface(void)
// Source: json
//------------------------------------------------------------------------------
ISteamGameStats *__thiscall CSteamWorksGameStatsUploader::GetInterface(CSteamWorksGameStatsUploader *this)
{
  int v1; // edi
  int HSteamPipe; // ebx
  CSteamID *v4; // eax
  int v5; // eax
  _BYTE v7[8]; // [esp+Ch] [ebp-8h] BYREF

  v1 = 0;
  HSteamPipe = 0;
  if ( steamapicontext != nullptr
    && steamapicontext->m_pSteamUser != nullptr
    && steamapicontext->m_pSteamUtils != nullptr )
  {
    v4 = steamapicontext->m_pSteamUser->GetSteamID(this: steamapicontext->m_pSteamUser, result: v7);
    LODWORD(this->m_UserID) = v4->m_steamid.m_comp;
    HIDWORD(this->m_UserID) = *((_DWORD *)&v4->m_steamid.m_comp + 1);
    this->m_iAppID = steamapicontext->m_pSteamUtils->GetAppID(this: steamapicontext->m_pSteamUtils);
    v1 = steamapicontext->m_pSteamUser->GetHSteamUser(this: steamapicontext->m_pSteamUser);
    HSteamPipe = _GetHSteamPipe();
  }
  if ( _SteamClient() == 0 )
    return nullptr;
  v5 = _SteamClient();
  return (*(ISteamGameStats *(__thiscall **)(int, int, int, const char *))(*(_DWORD *)v5 + 52))(
           a1: v5,
           a2: v1,
           a3: HSteamPipe,
           a4: "SteamGameStats001");
}

//------------------------------------------------------------------------------
// Address: 0x10171CC0
// Name: void Show_Steam_Stats_Session_ID(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Show_Steam_Stats_Session_ID()
{
  int m_nValue; // eax

  if ( steamworks_sessionid_client.m_pParent != nullptr )
    m_nValue = steamworks_sessionid_client.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  DevMsg(a1: "Client session ID (%d).\n", m_nValue);
  if ( steamworks_sessionid_server.m_pParent != nullptr )
    DevMsg(a1: "Server session ID (%d).\n", steamworks_sessionid_server.m_pParent->m_Value.m_nValue);
  else
    DevMsg(a1: "Server session ID (%d).\n", 0);
}

//------------------------------------------------------------------------------
// Address: 0x10171D10
// Name: private: enum EResult CSteamWorksGameStatsUploader::RequestSessionID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamWorksGameStatsUploader::RequestSessionID(CSteamWorksGameStatsUploader *this)
{
  ISteamGameStats *Interface; // eax
  ISteamGameStats *m_SteamWorksInterface; // edi
  int TimeSinceEpoch; // eax
  ISteamGameStats_vtbl *v6; // [esp+4h] [ebp-4h]

  if ( this->m_SessionID == 0 )
  {
    if ( this->m_SessionIDRequestPending != (BYTE4(this->m_SessionID) | LOBYTE(this->m_SessionID)) )
      return 22;
    this->m_SessionIDRequestUnsent = true;
    this->m_ServiceTicking = true;
    if ( !CSteamWorksGameStatsUploader::AccessToSteamAPI(this) )
      return 3;
    Interface = CSteamWorksGameStatsUploader::GetInterface(this);
    this->m_SteamWorksInterface = Interface;
    if ( Interface != nullptr )
    {
      DevMsg(a1: "Steamworks Stats: Requesting CLIENT session id.\n");
      m_SteamWorksInterface = this->m_SteamWorksInterface;
      *(_WORD *)&this->m_SessionIDRequestUnsent = 256;
      v6 = m_SteamWorksInterface->__vftable;
      TimeSinceEpoch = CSteamWorksGameStatsUploader::GetTimeSinceEpoch(this);
      ((void (__thiscall *)(ISteamGameStats *, int, _DWORD, _DWORD, unsigned int, int))v6->GetNewSession)(
        a1: m_SteamWorksInterface,
        a2: 1,
        a3: this->m_UserID,
        a4: HIDWORD(this->m_UserID),
        a5: this->m_iAppID,
        a6: TimeSinceEpoch);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10171DC0
// Name: public: virtual void CSteamWorksGameStatsUploader::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamWorksGameStatsUploader::FrameUpdatePostEntityThink(CSteamWorksGameStatsUploader *this)
{
  if ( this->m_ServiceTicking && (float)(*(float *)gpGlobals.m_Index - this->m_LastServiceTick) >= 3.0 )
  {
    this->m_LastServiceTick = *(float *)gpGlobals.m_Index;
    if ( steamapicontext != nullptr
      && steamapicontext->m_pSteamUser != nullptr
      && steamapicontext->m_pSteamUser->BLoggedOn(this: steamapicontext->m_pSteamUser)
      && steamapicontext->m_pSteamFriends != nullptr
      && steamapicontext->m_pSteamMatchmaking != nullptr )
    {
      if ( this->m_SessionIDRequestUnsent )
        CSteamWorksGameStatsUploader::RequestSessionID(this);
      else
        this->m_ServiceTicking = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10171E40
// Name: private: enum EResult CSteamWorksGameStatsUploader::WriteIntToTable(int,unsigned __int64,char const __near *)
// Source: json
//------------------------------------------------------------------------------
EResult __thiscall CSteamWorksGameStatsUploader::WriteIntToTable(
        CSteamWorksGameStatsUploader *this,
        int value,
        unsigned __int64 iTableID,
        const char *pzRow)
{
  ISteamGameStats *Interface; // eax

  if ( this->m_SteamWorksInterface != nullptr )
    return ((EResult (__thiscall *)(ISteamGameStats *, _DWORD, _DWORD, const char *, int))this->m_SteamWorksInterface->AddRowAttributeInt)(
             a1: this->m_SteamWorksInterface,
             a2: iTableID,
             a3: HIDWORD(iTableID),
             a4: pzRow,
             a5: value);
  Interface = CSteamWorksGameStatsUploader::GetInterface(this);
  this->m_SteamWorksInterface = Interface;
  if ( Interface != nullptr )
    return ((EResult (__thiscall *)(ISteamGameStats *, _DWORD, _DWORD, const char *, int))this->m_SteamWorksInterface->AddRowAttributeInt)(
             a1: this->m_SteamWorksInterface,
             a2: iTableID,
             a3: HIDWORD(iTableID),
             a4: pzRow,
             a5: value);
  else
    return k_EResultNoConnection;
}

//------------------------------------------------------------------------------
// Address: 0x10171E90
// Name: private: enum EResult CSteamWorksGameStatsUploader::WriteInt64ToTable(unsigned __int64,unsigned __int64,char const __near *)
// Source: json
//------------------------------------------------------------------------------
EResult __thiscall CSteamWorksGameStatsUploader::WriteInt64ToTable(
        CSteamWorksGameStatsUploader *this,
        unsigned __int64 value,
        unsigned __int64 iTableID,
        const char *pzRow)
{
  ISteamGameStats *Interface; // eax

  if ( this->m_SteamWorksInterface != nullptr )
    return ((EResult (__thiscall *)(ISteamGameStats *, _DWORD, _DWORD, const char *, _DWORD, _DWORD))this->m_SteamWorksInterface->AddRowAttributeInt64)(
             a1: this->m_SteamWorksInterface,
             a2: iTableID,
             a3: HIDWORD(iTableID),
             a4: pzRow,
             a5: value,
             a6: HIDWORD(value));
  Interface = CSteamWorksGameStatsUploader::GetInterface(this);
  this->m_SteamWorksInterface = Interface;
  if ( Interface != nullptr )
    return ((EResult (__thiscall *)(ISteamGameStats *, _DWORD, _DWORD, const char *, _DWORD, _DWORD))this->m_SteamWorksInterface->AddRowAttributeInt64)(
             a1: this->m_SteamWorksInterface,
             a2: iTableID,
             a3: HIDWORD(iTableID),
             a4: pzRow,
             a5: value,
             a6: HIDWORD(value));
  else
    return k_EResultNoConnection;
}

//------------------------------------------------------------------------------
// Address: 0x10171EE0
// Name: private: enum EResult CSteamWorksGameStatsUploader::WriteFloatToTable(float,unsigned __int64,char const __near *)
// Source: json
//------------------------------------------------------------------------------
EResult __thiscall CSteamWorksGameStatsUploader::WriteFloatToTable(
        CSteamWorksGameStatsUploader *this,
        float value,
        unsigned __int64 iTableID,
        const char *pzRow)
{
  ISteamGameStats *Interface; // eax

  if ( this->m_SteamWorksInterface != nullptr )
    return ((EResult (__stdcall *)(_DWORD, _DWORD, const char *, _DWORD))this->m_SteamWorksInterface->AddRowAttributeFloat)(
             a1: iTableID,
             a2: HIDWORD(iTableID),
             a3: pzRow,
             a4: LODWORD(value));
  Interface = CSteamWorksGameStatsUploader::GetInterface(this);
  this->m_SteamWorksInterface = Interface;
  if ( Interface != nullptr )
    return ((EResult (__stdcall *)(_DWORD, _DWORD, const char *, _DWORD))this->m_SteamWorksInterface->AddRowAttributeFloat)(
             a1: iTableID,
             a2: HIDWORD(iTableID),
             a3: pzRow,
             a4: LODWORD(value));
  else
    return k_EResultNoConnection;
}

//------------------------------------------------------------------------------
// Address: 0x10171F30
// Name: private: enum EResult CSteamWorksGameStatsUploader::WriteStringToTable(char const __near *,unsigned __int64,char const __near *)
// Source: json
//------------------------------------------------------------------------------
EResult __thiscall CSteamWorksGameStatsUploader::WriteStringToTable(
        CSteamWorksGameStatsUploader *this,
        const char *value,
        unsigned __int64 iTableID,
        const char *pzRow)
{
  ISteamGameStats *Interface; // eax

  if ( this->m_SteamWorksInterface != nullptr )
    return ((EResult (__thiscall *)(ISteamGameStats *, _DWORD, _DWORD, const char *, const char *))this->m_SteamWorksInterface->AddRowAtributeString)(
             a1: this->m_SteamWorksInterface,
             a2: iTableID,
             a3: HIDWORD(iTableID),
             a4: pzRow,
             a5: value);
  Interface = CSteamWorksGameStatsUploader::GetInterface(this);
  this->m_SteamWorksInterface = Interface;
  if ( Interface != nullptr )
    return ((EResult (__thiscall *)(ISteamGameStats *, _DWORD, _DWORD, const char *, const char *))this->m_SteamWorksInterface->AddRowAtributeString)(
             a1: this->m_SteamWorksInterface,
             a2: iTableID,
             a3: HIDWORD(iTableID),
             a4: pzRow,
             a5: value);
  else
    return k_EResultNoConnection;
}

//------------------------------------------------------------------------------
// Address: 0x10171F80
// Name: public: void CSteamWorksGameStatsUploader::AddClientPerfData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamWorksGameStatsUploader::AddClientPerfData(CSteamWorksGameStatsUploader *this, KeyValues *pKV)
{
  ISteamGameStats *Interface; // eax
  ISteamUtils *m_pSteamUtils; // ecx
  int v5; // edi
  ISteamGameStats *m_SteamWorksInterface; // ecx
  char *String; // eax
  int Int; // eax
  char *v9; // eax
  int v10; // eax
  char *v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  char *v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  float defaultValue; // [esp+10h] [ebp-28h]
  float defaultValuea; // [esp+10h] [ebp-28h]
  float defaultValueb; // [esp+10h] [ebp-28h]
  float defaultValuec; // [esp+10h] [ebp-28h]
  float defaultValued; // [esp+10h] [ebp-28h]
  float defaultValuee; // [esp+10h] [ebp-28h]
  int m_SessionID; // [esp+14h] [ebp-24h]
  unsigned __int64 v34; // [esp+14h] [ebp-24h]
  unsigned __int64 v35; // [esp+14h] [ebp-24h]
  unsigned __int64 v36; // [esp+14h] [ebp-24h]
  unsigned __int64 v37; // [esp+14h] [ebp-24h]
  unsigned __int64 v38; // [esp+14h] [ebp-24h]
  unsigned __int64 v39; // [esp+14h] [ebp-24h]
  unsigned __int64 v40; // [esp+14h] [ebp-24h]
  unsigned __int64 v41; // [esp+14h] [ebp-24h]
  unsigned __int64 v42; // [esp+14h] [ebp-24h]
  unsigned __int64 v43; // [esp+14h] [ebp-24h]
  unsigned __int64 v44; // [esp+14h] [ebp-24h]
  unsigned __int64 v45; // [esp+14h] [ebp-24h]
  unsigned __int64 v46; // [esp+14h] [ebp-24h]
  unsigned __int64 v47; // [esp+14h] [ebp-24h]
  unsigned __int64 v48; // [esp+14h] [ebp-24h]
  unsigned __int64 v49; // [esp+14h] [ebp-24h]
  unsigned __int64 v50; // [esp+14h] [ebp-24h]
  unsigned __int64 v51; // [esp+14h] [ebp-24h]
  unsigned __int64 v52; // [esp+14h] [ebp-24h]
  unsigned __int64 v53; // [esp+14h] [ebp-24h]
  unsigned __int64 v54; // [esp+14h] [ebp-24h]
  unsigned __int64 v55; // [esp+14h] [ebp-24h]
  unsigned __int64 v56; // [esp+14h] [ebp-24h]
  unsigned __int64 v57; // [esp+14h] [ebp-24h]
  int m_SessionID_high; // [esp+18h] [ebp-20h]
  __int64 timeptr; // [esp+28h] [ebp-10h] BYREF
  unsigned __int64 ulRowID; // [esp+30h] [ebp-8h] BYREF

  Interface = CSteamWorksGameStatsUploader::GetInterface(this);
  this->m_SteamWorksInterface = Interface;
  if ( Interface != nullptr && this->m_bCollectingAny )
  {
    if ( steamapicontext != nullptr && (m_pSteamUtils = steamapicontext->m_pSteamUtils) != nullptr )
    {
      v5 = m_pSteamUtils->GetServerRealTime(this: m_pSteamUtils);
      HIDWORD(timeptr) = 0;
    }
    else
    {
      _time64(&timeptr);
      v5 = timeptr;
    }
    m_SteamWorksInterface = this->m_SteamWorksInterface;
    m_SessionID_high = HIDWORD(this->m_SessionID);
    m_SessionID = this->m_SessionID;
    ulRowID = 0;
    ((void (__thiscall *)(ISteamGameStats *, unsigned __int64 *, int, int, const char *))m_SteamWorksInterface->AddNewRow)(
      a1: m_SteamWorksInterface,
      a2: &ulRowID,
      a3: m_SessionID,
      a4: m_SessionID_high,
      a5: "ClientPerfData");
    if ( ulRowID != 0 )
    {
      CSteamWorksGameStatsUploader::WriteInt64ToTable(
        this,
        value: this->m_SessionID,
        iTableID: ulRowID,
        pzRow: "SessionID");
      CSteamWorksGameStatsUploader::WriteIntToTable(this, value: v5, iTableID: ulRowID, pzRow: "TimeSubmitted");
      v34 = ulRowID;
      String = KeyValues::GetString(this: pKV, keyName: "Map/mapname", defaultValue: prType);
      CSteamWorksGameStatsUploader::WriteStringToTable(this, value: String, iTableID: v34, pzRow: "MapID");
      v35 = ulRowID;
      Int = KeyValues::GetInt(this: pKV, keyName: "appid", defaultValue: 0);
      CSteamWorksGameStatsUploader::WriteIntToTable(this, value: Int, iTableID: v35, pzRow: "AppID");
      v36 = ulRowID;
      defaultValue = KeyValues::GetFloat(this: pKV, keyName: "Map/perfdata/AvgFPS", defaultValue: 0.0);
      CSteamWorksGameStatsUploader::WriteFloatToTable(this, value: defaultValue, iTableID: v36, pzRow: "AvgFPS");
      v37 = ulRowID;
      defaultValuea = KeyValues::GetFloat(this: pKV, keyName: "map/perfdata/MinFPS", defaultValue: 0.0);
      CSteamWorksGameStatsUploader::WriteFloatToTable(this, value: defaultValuea, iTableID: v37, pzRow: "MinFPS");
      v38 = ulRowID;
      defaultValueb = KeyValues::GetFloat(this: pKV, keyName: "Map/perfdata/MaxFPS", defaultValue: 0.0);
      CSteamWorksGameStatsUploader::WriteFloatToTable(this, value: defaultValueb, iTableID: v38, pzRow: "MaxFPS");
      v39 = ulRowID;
      defaultValuec = KeyValues::GetFloat(this: pKV, keyName: "Map/perfdata/StdDevFPS", defaultValue: 0.0);
      CSteamWorksGameStatsUploader::WriteFloatToTable(this, value: defaultValuec, iTableID: v39, pzRow: "StdDevFPS");
      v40 = ulRowID;
      v9 = KeyValues::GetString(this: pKV, keyName: "CPUID", defaultValue: prType);
      CSteamWorksGameStatsUploader::WriteStringToTable(this, value: v9, iTableID: v40, pzRow: "CPUID");
      v41 = ulRowID;
      defaultValued = KeyValues::GetFloat(this: pKV, keyName: "CPUGhz", defaultValue: 0.0);
      CSteamWorksGameStatsUploader::WriteFloatToTable(this, value: defaultValued, iTableID: v41, pzRow: "CPUGhz");
      v42 = ulRowID;
      v10 = KeyValues::GetInt(this: pKV, keyName: "NumCores", defaultValue: 0);
      CSteamWorksGameStatsUploader::WriteIntToTable(this, value: v10, iTableID: v42, pzRow: "NumCores");
      v43 = ulRowID;
      v11 = KeyValues::GetString(this: pKV, keyName: "GPUDrv", defaultValue: prType);
      CSteamWorksGameStatsUploader::WriteStringToTable(this, value: v11, iTableID: v43, pzRow: "GPUDrv");
      v44 = ulRowID;
      v12 = KeyValues::GetInt(this: pKV, keyName: "GPUVendor", defaultValue: 0);
      CSteamWorksGameStatsUploader::WriteIntToTable(this, value: v12, iTableID: v44, pzRow: "GPUVendor");
      v45 = ulRowID;
      v13 = KeyValues::GetInt(this: pKV, keyName: "GPUDeviceID", defaultValue: 0);
      CSteamWorksGameStatsUploader::WriteIntToTable(this, value: v13, iTableID: v45, pzRow: "GPUDeviceID");
      v46 = ulRowID;
      v14 = KeyValues::GetInt(this: pKV, keyName: "GPUDriverVersion", defaultValue: 0);
      CSteamWorksGameStatsUploader::WriteIntToTable(this, value: v14, iTableID: v46, pzRow: "GPUDriverVersion");
      v47 = ulRowID;
      v15 = KeyValues::GetInt(this: pKV, keyName: "DxLvl", defaultValue: 0);
      CSteamWorksGameStatsUploader::WriteIntToTable(this, value: v15, iTableID: v47, pzRow: "DxLvl");
      v48 = ulRowID;
      v16 = KeyValues::GetInt(this: pKV, keyName: "IsSplitScreen", defaultValue: 0);
      CSteamWorksGameStatsUploader::WriteIntToTable(this, value: v16, iTableID: v48, pzRow: "IsSplitScreen");
      v17 = KeyValues::GetInt(this: pKV, keyName: "Map/Windowed", defaultValue: 0);
      CSteamWorksGameStatsUploader::WriteIntToTable(this, value: v17 != 0, iTableID: ulRowID, pzRow: "Windowed");
      v18 = KeyValues::GetInt(this: pKV, keyName: "Map/WindowedNoBorder", defaultValue: 0);
      CSteamWorksGameStatsUploader::WriteIntToTable(this, value: v18 != 0, iTableID: ulRowID, pzRow: "WindowedNoBorder");
      v49 = ulRowID;
      v19 = KeyValues::GetInt(this: pKV, keyName: "width", defaultValue: 0);
      CSteamWorksGameStatsUploader::WriteIntToTable(this, value: v19, iTableID: v49, pzRow: "Width");
      v50 = ulRowID;
      v20 = KeyValues::GetInt(this: pKV, keyName: "height", defaultValue: 0);
      CSteamWorksGameStatsUploader::WriteIntToTable(this, value: v20, iTableID: v50, pzRow: "Height");
      v51 = ulRowID;
      v21 = KeyValues::GetInt(this: pKV, keyName: "Map/UsedVoice", defaultValue: 0);
      CSteamWorksGameStatsUploader::WriteIntToTable(this, value: v21, iTableID: v51, pzRow: "Usedvoiced");
      v52 = ulRowID;
      v22 = KeyValues::GetString(this: pKV, keyName: "Map/Language", defaultValue: prType);
      CSteamWorksGameStatsUploader::WriteStringToTable(this, value: v22, iTableID: v52, pzRow: "Language");
      v53 = ulRowID;
      defaultValuee = KeyValues::GetFloat(this: pKV, keyName: "Map/perfdata/AvgServerPing", defaultValue: 0.0);
      CSteamWorksGameStatsUploader::WriteFloatToTable(this, value: defaultValuee, iTableID: v53, pzRow: "AvgServerPing");
      v54 = ulRowID;
      v23 = KeyValues::GetInt(this: pKV, keyName: "Map/Caption", defaultValue: 0);
      CSteamWorksGameStatsUploader::WriteIntToTable(this, value: v23, iTableID: v54, pzRow: "IsCaptioned");
      v55 = ulRowID;
      v24 = KeyValues::GetInt(this: pKV, keyName: "IsPC", defaultValue: 0);
      CSteamWorksGameStatsUploader::WriteIntToTable(this, value: v24, iTableID: v55, pzRow: "IsPC");
      v56 = ulRowID;
      v25 = KeyValues::GetInt(this: pKV, keyName: "Map/Cheats", defaultValue: 0);
      CSteamWorksGameStatsUploader::WriteIntToTable(this, value: v25, iTableID: v56, pzRow: "Cheats");
      v57 = ulRowID;
      v26 = KeyValues::GetInt(this: pKV, keyName: "Map/MapTime", defaultValue: 0);
      CSteamWorksGameStatsUploader::WriteIntToTable(this, value: v26, iTableID: v57, pzRow: "MapTime");
      ((void (__thiscall *)(ISteamGameStats *, _DWORD, _DWORD))this->m_SteamWorksInterface->CommitRow)(
        a1: this->m_SteamWorksInterface,
        a2: ulRowID,
        a3: HIDWORD(ulRowID));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172450
// Name: public: int CSteamWorksGameStatsUploader::GetFriendCountInGame(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamWorksGameStatsUploader::GetFriendCountInGame(CSteamWorksGameStatsUploader *this)
{
  int v1; // edi
  int v2; // esi
  bool v3; // al
  unsigned int v4; // eax
  FriendGameInfo_t myGameInfo; // [esp+8h] [ebp-58h] BYREF
  FriendGameInfo_t friendInfo; // [esp+20h] [ebp-40h] BYREF
  CSteamID myLobby; // [esp+38h] [ebp-28h] BYREF
  CSteamID friendLobby; // [esp+40h] [ebp-20h] BYREF
  CSteamID friendID; // [esp+48h] [ebp-18h] BYREF
  CSteamID m_SteamID; // [esp+50h] [ebp-10h] BYREF
  int activeFriendCnt; // [esp+58h] [ebp-8h]
  int friendsInOurGame; // [esp+5Ch] [ebp-4h]

  v1 = 0;
  friendsInOurGame = 0;
  if ( steamapicontext == nullptr
    || steamapicontext->m_pSteamUser == nullptr
    || !steamapicontext->m_pSteamUser->BLoggedOn(this: steamapicontext->m_pSteamUser)
    || steamapicontext->m_pSteamFriends == nullptr
    || steamapicontext->m_pSteamMatchmaking == nullptr )
  {
    return 0;
  }
  steamapicontext->m_pSteamUser->GetSteamID(this: steamapicontext->m_pSteamUser, result: &m_SteamID);
  HIWORD(myGameInfo.m_steamIDLobby.m_steamid.m_unAll64Bits) = BYTE6(myGameInfo.m_steamIDLobby.m_steamid.m_unAll64Bits)
                                                            & 0xF;
  myGameInfo.m_steamIDLobby.m_steamid.m_unAll64Bits &= 0xFFF0000000000000uLL;
  myGameInfo.m_gameID.m_ulGameID = 0;
  ((void (__thiscall *)(ISteamFriends *, _DWORD, _DWORD, FriendGameInfo_t *))steamapicontext->m_pSteamFriends->GetFriendGamePlayed)(
    a1: steamapicontext->m_pSteamFriends,
    a2: *(_DWORD *)&m_SteamID.m_steamid.m_comp,
    a3: *((_DWORD *)&m_SteamID.m_steamid.m_comp + 1),
    a4: &myGameInfo);
  ((void (__thiscall *)(ISteamMatchmaking *, CSteamID *, _DWORD, _DWORD))steamapicontext->m_pSteamMatchmaking->GetLobbyOwner)(
    a1: steamapicontext->m_pSteamMatchmaking,
    a2: &myLobby,
    a3: *(_DWORD *)&myGameInfo.m_steamIDLobby.m_steamid.m_comp,
    a4: *((_DWORD *)&myGameInfo.m_steamIDLobby.m_steamid.m_comp + 1));
  v2 = 0;
  activeFriendCnt = steamapicontext->m_pSteamFriends->GetFriendCount(this: steamapicontext->m_pSteamFriends, a2: 4);
  if ( activeFriendCnt > 0 )
  {
    do
    {
      HIWORD(friendInfo.m_steamIDLobby.m_steamid.m_unAll64Bits) = BYTE6(friendInfo.m_steamIDLobby.m_steamid.m_unAll64Bits)
                                                                & 0xF;
      friendInfo.m_steamIDLobby.m_steamid.m_unAll64Bits &= 0xFFF0000000000000uLL;
      friendInfo.m_gameID.m_ulGameID = 0;
      steamapicontext->m_pSteamFriends->GetFriendByIndex(
        this: steamapicontext->m_pSteamFriends,
        result: &friendID,
        a3: v2,
        a4: 4);
      if ( ((unsigned __int8 (__thiscall *)(ISteamFriends *, _DWORD, _DWORD, FriendGameInfo_t *))steamapicontext->m_pSteamFriends->GetFriendGamePlayed)(
             a1: steamapicontext->m_pSteamFriends,
             a2: *(_DWORD *)&friendID.m_steamid.m_comp,
             a3: *((_DWORD *)&friendID.m_steamid.m_comp + 1),
             a4: &friendInfo) != 0 )
      {
        switch ( *((_BYTE *)&friendInfo.m_gameID.m_gameID + 3) )
        {
          case 0:
            v3 = (friendInfo.m_gameID.m_ulGameID & 0xFFFFFF) != 0;
            goto LABEL_10;
          case 1:
            if ( (friendInfo.m_gameID.m_ulGameID & 0xFFFFFF) == 0 || *((int *)&friendInfo.m_gameID.m_gameID + 1) >= 0 )
              break;
            goto LABEL_11;
          case 2:
            v3 = *((int *)&friendInfo.m_gameID.m_gameID + 1) < 0;
LABEL_10:
            if ( v3 )
              goto LABEL_11;
            break;
          case 3:
            if ( (friendInfo.m_gameID.m_ulGameID & 0xFFFFFF) != 0 || *((int *)&friendInfo.m_gameID.m_gameID + 1) >= 0 )
              break;
LABEL_11:
            ((void (__thiscall *)(ISteamMatchmaking *, CSteamID *, _DWORD, _DWORD))steamapicontext->m_pSteamMatchmaking->GetLobbyOwner)(
              a1: steamapicontext->m_pSteamMatchmaking,
              a2: &friendLobby,
              a3: *(_DWORD *)&friendInfo.m_steamIDLobby.m_steamid.m_comp,
              a4: *((_DWORD *)&friendInfo.m_steamIDLobby.m_steamid.m_comp + 1));
            v4 = (*((_DWORD *)&friendLobby.m_steamid.m_comp + 1) >> 20) & 0xF;
            if ( v4 != 0
              && v4 < 0xB
              && SHIBYTE(friendLobby.m_steamid.m_unAll64Bits) > 0
              && SHIBYTE(friendLobby.m_steamid.m_unAll64Bits) < 6 )
            {
              if ( v4 != 1
                || friendLobby.m_steamid.m_comp != 0
                && (v1 = friendsInOurGame, (*((_DWORD *)&friendLobby.m_steamid.m_comp + 1) & 0xFFFFF) == 1) )
              {
                if ( (v4 != 7
                   || friendLobby.m_steamid.m_comp != 0
                   && (*((_DWORD *)&friendLobby.m_steamid.m_comp + 1) & 0xFFFFF) == 0)
                  && myLobby.m_steamid.m_comp == friendLobby.m_steamid.m_comp )
                {
                  friendsInOurGame = ++v1;
                }
              }
            }
            break;
          default:
            break;
        }
      }
      ++v2;
    }
    while ( v2 < activeFriendCnt );
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101726C0
// Name: public: void CSteamWorksGameStatsUploader::ClientDisconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamWorksGameStatsUploader::ClientDisconnect(CSteamWorksGameStatsUploader *this)
{
  int m_Size; // eax
  int v3; // edi
  ISteamUtils *m_pSteamUtils; // ecx
  unsigned int v5; // eax
  __int64 timeptr; // [esp+4h] [ebp-8h] BYREF

  m_Size = this->m_ServerSessions.m_Size;
  if ( m_Size != 0 )
  {
    v3 = m_Size - 1;
    if ( this->m_ServerSessions.m_Memory.m_pMemory[v3].m_DisconnectTime == 0 )
    {
      if ( steamapicontext != nullptr && (m_pSteamUtils = steamapicontext->m_pSteamUtils) != nullptr )
      {
        v5 = m_pSteamUtils->GetServerRealTime(this: m_pSteamUtils);
        HIDWORD(timeptr) = 0;
      }
      else
      {
        _time64(&timeptr);
        v5 = timeptr;
      }
      this->m_ServerSessions.m_Memory.m_pMemory[v3].m_DisconnectTime = v5;
    }
    LODWORD(this->m_ServerSessionID) = 0;
    HIDWORD(this->m_ServerSessionID) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172740
// Name: public: void CSteamWorksGameStatsUploader::Steam_OnSteamSessionInfoIssued(struct GameStatsSessionIssued_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamWorksGameStatsUploader::Steam_OnSteamSessionInfoIssued(
        CSteamWorksGameStatsUploader *this,
        GameStatsSessionIssued_t *pGameStatsSessionInfo)
{
  ISteamUtils *m_pSteamUtils; // ecx
  unsigned int v4; // eax
  int m_SessionID; // ecx
  __int64 timeptr; // [esp+4h] [ebp-8h] BYREF

  if ( this->m_SessionIDRequestPending )
  {
    this->m_SessionIDRequestPending = false;
    if ( pGameStatsSessionInfo != nullptr )
    {
      if ( pGameStatsSessionInfo->m_eResult == k_EResultOK )
      {
        DevMsg(a1: "Steamworks Stats: Received CLIENT session id: %lli\n", pGameStatsSessionInfo->m_ulSessionID);
        if ( steamapicontext != nullptr && (m_pSteamUtils = steamapicontext->m_pSteamUtils) != nullptr )
        {
          v4 = m_pSteamUtils->GetServerRealTime(this: m_pSteamUtils);
          HIDWORD(timeptr) = 0;
        }
        else
        {
          _time64(&timeptr);
          v4 = timeptr;
        }
        this->m_StartTime = v4;
        this->m_SessionID = pGameStatsSessionInfo->m_ulSessionID;
        m_SessionID = this->m_SessionID;
        this->m_bCollectingAny = pGameStatsSessionInfo->m_bCollectingAny;
        this->m_bCollectingDetails = pGameStatsSessionInfo->m_bCollectingDetails;
        ConVar::SetValue(this: (ConVar *)&steamworks_sessionid_client.IConVar, value: m_SessionID);
        this->m_FriendCntInGame = CSteamWorksGameStatsUploader::GetFriendCountInGame(this);
        this->m_HumanCntInGame = 0;
      }
      else
      {
        DevMsg(a1: "Steamworks Stats: CLIENT session id not available.\n");
        this->m_SessionIDRequestUnsent = true;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172830
// Name: private: void CSteamWorksGameStatsUploader::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamWorksGameStatsUploader::Reset(CSteamWorksGameStatsUploader *this)
{
  int v2; // edi

  ConVar::SetValue(this: (ConVar *)&steamworks_sessionid_server.IConVar, value: 0);
  ConVar::SetValue(this: (ConVar *)&steamworks_sessionid_client.IConVar, value: 0);
  this->m_ServerSessionID = 0;
  this->m_ServiceTicking = false;
  this->m_LastServiceTick = 0.0;
  this->m_SessionID = 0;
  this->m_UploadedStats = false;
  *(_DWORD *)&this->m_SessionIDRequestUnsent = 0;
  this->m_UserID = 0;
  this->m_iAppID = 0;
  this->m_iServerIP = 0;
  memset(dst: (int)this->m_pzServerIP, value: nullptr, count: sizeof(this->m_pzServerIP));
  memset(dst: (int)this->m_pzMapStart, value: nullptr, count: sizeof(this->m_pzMapStart));
  memset(dst: (int)this->m_pzHostName, value: nullptr, count: sizeof(this->m_pzHostName));
  v2 = 0;
  this->m_StartTime = 0;
  this->m_EndTime = 0;
  this->m_HumanCntInGame = 0;
  for ( this->m_FriendCntInGame = 0; v2 < this->m_StatsToSend.m_Size; ++v2 )
    KeyValues::deleteThis(this: this->m_StatsToSend.m_Memory.m_pMemory[v2]);
  this->m_StatsToSend.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10172920
// Name: private: void CSteamWorksGameStatsUploader::ServerAddressToInt(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamWorksGameStatsUploader::ServerAddressToInt(CSteamWorksGameStatsUploader *this)
{
  int m_Size; // eax
  int v3; // esi
  char **m_pMemory; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > IPs; // [esp+8h] [ebp-18h] BYREF
  unsigned __int8 v6[4]; // [esp+1Ch] [ebp-4h]

  memset(&IPs, 0, sizeof(IPs));
  V_SplitString(pString: this->m_pzServerIP, pSeparator: ".", outStrings: &IPs);
  m_Size = IPs.m_Size;
  this->m_iServerIP = 0;
  if ( m_Size >= 4 )
  {
    v3 = 0;
    do
    {
      if ( v3 >= 4 )
        break;
      v6[v3] = V_atoi(str: IPs.m_Memory.m_pMemory[v3]);
      ++v3;
    }
    while ( v3 < IPs.m_Size );
    m_pMemory = IPs.m_Memory.m_pMemory;
    this->m_iServerIP = v6[3] + ((v6[2] + ((v6[1] + (v6[0] << 8)) << 8)) << 8);
    IPs.m_Size = 0;
    if ( IPs.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        m_pMemory = nullptr;
        IPs.m_Memory.m_pMemory = nullptr;
      }
      IPs.m_Memory.m_nAllocationCount = 0;
    }
    IPs.m_pElements = m_pMemory;
    if ( IPs.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
  else
  {
    CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&IPs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172A00
// Name: public: virtual CSteamWorksGameStatsUploader::~CSteamWorksGameStatsUploader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamWorksGameStatsUploader::~CSteamWorksGameStatsUploader(CSteamWorksGameStatsUploader *this)
{
  bool v2; // zf

  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_StatsToSend);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ServerSessions);
  v2 = (this->m_CallbackSteamSessionInfoClosed.m_nCallbackFlags & 1) == 0;
  this->m_CallbackSteamSessionInfoClosed.__vftable = (CCallbackManual<CSteamWorksGameStatsUploader,GameStatsSessionClosed_t,0>_vtbl *)&CCallback<CSteamWorksGameStatsUploader,GameStatsSessionClosed_t,0>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackSteamSessionInfoClosed);
  v2 = (this->m_CallbackSteamSessionInfoIssued.m_nCallbackFlags & 1) == 0;
  this->m_CallbackSteamSessionInfoIssued.__vftable = (CCallbackManual<CSteamWorksGameStatsUploader,GameStatsSessionIssued_t,0>_vtbl *)&CCallback<CSteamWorksGameStatsUploader,GameStatsSessionIssued_t,0>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackSteamSessionInfoIssued);
  v2 = !this->m_bRegisteredForEvents;
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 13;
  if ( !v2 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->CGameEventListener);
    this->m_bRegisteredForEvents = false;
  }
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&IGameEventListener2::`vftable';
  IGameSystemPerFrame::~IGameSystemPerFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x10172A90
// Name: public: CSteamWorksGameStatsUploader::CSteamWorksGameStatsUploader(void)
// Source: json
//------------------------------------------------------------------------------
CSteamWorksGameStatsUploader *__thiscall CSteamWorksGameStatsUploader::CSteamWorksGameStatsUploader(
        CSteamWorksGameStatsUploader *this)
{
  __int64 v2; // xmm0_8
  __int64 v3; // xmm0_8
  __int64 v5; // [esp+Ch] [ebp-10h]
  __int64 v6; // [esp+Ch] [ebp-10h]
  __int64 v7; // [esp+14h] [ebp-8h]

  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this, name: "CSteamWorksGameStatsUploader");
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->CAutoGameSystemPerFrame::CBaseGameSystemPerFrame::IGameSystemPerFrame::IGameSystem::__vftable = (CSteamWorksGameStatsUploader_vtbl *)&CSteamWorksGameStatsUploader::`vftable'{for `CAutoGameSystemPerFrame'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CSteamWorksGameStatsUploader::`vftable'{for `CGameEventListener'};
  this->m_CallbackSteamSessionInfoIssued.m_nCallbackFlags = 0;
  this->m_CallbackSteamSessionInfoIssued.m_iCallback = 0;
  this->m_CallbackSteamSessionInfoIssued.m_pObj = nullptr;
  this->m_CallbackSteamSessionInfoIssued.__vftable = (CCallbackManual<CSteamWorksGameStatsUploader,GameStatsSessionIssued_t,0>_vtbl *)&CCallbackManual<CSteamWorksGameStatsUploader,GameStatsSessionIssued_t,0>::`vftable';
  *(_QWORD *)&this->m_CallbackSteamSessionInfoIssued.m_Func = 0;
  *((_QWORD *)&this->m_CallbackSteamSessionInfoIssued.m_Func + 1) = 0xFFFFFFFF00000000uLL;
  this->m_CallbackSteamSessionInfoClosed.m_nCallbackFlags = 0;
  this->m_CallbackSteamSessionInfoClosed.m_iCallback = 0;
  this->m_CallbackSteamSessionInfoClosed.m_pObj = nullptr;
  this->m_CallbackSteamSessionInfoClosed.__vftable = (CCallbackManual<CSteamWorksGameStatsUploader,GameStatsSessionClosed_t,0>_vtbl *)&CCallbackManual<CSteamWorksGameStatsUploader,GameStatsSessionClosed_t,0>::`vftable';
  *(_QWORD *)&this->m_CallbackSteamSessionInfoClosed.m_Func = 0;
  *((_QWORD *)&this->m_CallbackSteamSessionInfoClosed.m_Func + 1) = 0xFFFFFFFF00000000uLL;
  this->m_ServerSessions.m_Memory.m_pMemory = nullptr;
  this->m_ServerSessions.m_Memory.m_nAllocationCount = 0;
  this->m_ServerSessions.m_Memory.m_nGrowSize = 0;
  this->m_ServerSessions.m_Size = 0;
  this->m_ServerSessions.m_pElements = nullptr;
  this->m_StatsToSend.m_Memory.m_pMemory = nullptr;
  this->m_StatsToSend.m_Memory.m_nAllocationCount = 0;
  this->m_StatsToSend.m_Memory.m_nGrowSize = 0;
  this->m_StatsToSend.m_Size = 0;
  this->m_StatsToSend.m_pElements = nullptr;
  LODWORD(v5) = CSteamWorksGameStatsUploader::Steam_OnSteamSessionInfoIssued;
  HIDWORD(v5) = 0;
  v7 = 0;
  if ( CSteamWorksGameStatsUploader::Steam_OnSteamSessionInfoIssued != nullptr )
  {
    if ( (this->m_CallbackSteamSessionInfoIssued.m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: &this->m_CallbackSteamSessionInfoIssued);
    *(_QWORD *)&this->m_CallbackSteamSessionInfoIssued.m_Func = v5;
    v2 = v7;
    this->m_CallbackSteamSessionInfoIssued.m_pObj = this;
    *((_QWORD *)&this->m_CallbackSteamSessionInfoIssued.m_Func + 1) = v2;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackSteamSessionInfoIssued, a2: 2001);
  }
  LODWORD(v6) = CSteamWorksGameStatsUploader::Steam_OnSteamSessionInfoClosed;
  HIDWORD(v6) = 0;
  v7 = 0;
  if ( CSteamWorksGameStatsUploader::Steam_OnSteamSessionInfoClosed != nullptr )
  {
    if ( (this->m_CallbackSteamSessionInfoClosed.m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: &this->m_CallbackSteamSessionInfoClosed);
    *(_QWORD *)&this->m_CallbackSteamSessionInfoClosed.m_Func = v6;
    v3 = v7;
    this->m_CallbackSteamSessionInfoClosed.m_pObj = this;
    *((_QWORD *)&this->m_CallbackSteamSessionInfoClosed.m_Func + 1) = v3;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackSteamSessionInfoClosed, a2: 2002);
  }
  CSteamWorksGameStatsUploader::Reset(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10172C60
// Name: public: virtual void CSteamWorksGameStatsUploader::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSteamWorksGameStatsUploader::FireGameEvent(
        CSteamWorksGameStatsUploader *this@<ecx>,
        int a2@<ebx>,
        IGameEvent *event)
{
  const char *v4; // ebx
  char *v5; // eax
  char *v6; // edi
  const char *v7; // ebx
  int v8; // eax
  char *v9; // eax
  char *v10; // eax

  if ( event != nullptr )
  {
    v4 = event->GetName(this: event);
    if ( _V_stricmp(s1: "hostname_changed", s2: v4) != 0 )
    {
      if ( _V_stricmp(s1: "server_spawn", s2: v4) != 0 )
      {
        if ( _V_stricmp(s1: "client_disconnect", s2: v4) == 0 )
          CSteamWorksGameStatsUploader::ClientDisconnect(this: (CSteamWorksGameStatsUploader *)((char *)this - 12));
      }
      else
      {
        v7 = (const char *)((int (__thiscall *)(IGameEvent *, const char *, const char *, int))event->GetString)(
                             a1: event,
                             a2: "address",
                             a3: prType,
                             a4: a2);
        if ( v7 != nullptr )
        {
          v8 = event->GetInt(this: event, a2: "port", a3: 0);
          V_snprintf(pDest: (char *)&this->m_UserID + 4, maxLen: 0x104u, pFormat: "%s:%d", v7, v8);
          CSteamWorksGameStatsUploader::ServerAddressToInt(this: (CSteamWorksGameStatsUploader *)((char *)this - 12));
        }
        else
        {
          V_strncpy(pDest: (char *)&this->m_UserID + 4, pSrc: "No Server Address", maxLen: 260);
          LODWORD(this->m_UserID) = 0;
        }
        v9 = (char *)event->GetString(this: event, a2: "hostname", a3: prType);
        if ( v9 != nullptr )
          V_strncpy(pDest: &this->m_pzMapStart[248], pSrc: v9, maxLen: 260);
        else
          V_strncpy(pDest: &this->m_pzMapStart[248], pSrc: "No Host Name", maxLen: 260);
        v10 = (char *)event->GetString(this: event, a2: "mapname", a3: prType);
        if ( v10 != nullptr )
          V_strncpy(pDest: &this->m_pzServerIP[248], pSrc: v10, maxLen: 260);
        else
          V_strncpy(pDest: &this->m_pzServerIP[248], pSrc: "No Map Name", maxLen: 260);
        LOBYTE(this->m_EndTime) = event->GetBool(this: event, a2: "password", a3: false);
      }
    }
    else
    {
      v5 = (char *)event->GetString(this: event, a2: "hostname", a3: prType);
      v6 = &this->m_pzMapStart[248];
      if ( v5 != nullptr )
        V_strncpy(pDest: v6, pSrc: v5, maxLen: 260);
      else
        V_strncpy(pDest: v6, pSrc: "No Host Name", maxLen: 260);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172E10
// Name: public: void CSteamWorksGameStatsUploader::SetServerSessionID(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamWorksGameStatsUploader::SetServerSessionID(
        CSteamWorksGameStatsUploader *this,
        unsigned __int64 serverSessionID)
{
  int v2; // ebx
  int v3; // edi
  ISteamUtils *m_pSteamUtils; // ecx
  unsigned int v6; // eax
  int m_Size; // edx
  ClientServerSession_t newSession; // [esp+Ch] [ebp-10h] BYREF

  v2 = HIDWORD(serverSessionID);
  v3 = serverSessionID;
  if ( serverSessionID != 0 && serverSessionID != this->m_ServerSessionID )
  {
    newSession.m_ServerSessionID = serverSessionID;
    if ( steamapicontext != nullptr && (m_pSteamUtils = steamapicontext->m_pSteamUtils) != nullptr )
    {
      v6 = m_pSteamUtils->GetServerRealTime(this: m_pSteamUtils);
      HIDWORD(serverSessionID) = 0;
    }
    else
    {
      _time64(timeptr: (__int64 *)&serverSessionID);
      v6 = serverSessionID;
    }
    m_Size = this->m_ServerSessions.m_Size;
    newSession.m_ConnectTime = v6;
    newSession.m_DisconnectTime = 0;
    CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>::InsertBefore(
      this: (CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)&this->m_ServerSessions,
      elem: m_Size,
      src: (const Quaternion *)&newSession);
    LODWORD(this->m_ServerSessionID) = v3;
    HIDWORD(this->m_ServerSessionID) = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172EB0
// Name: void ServerSessionIDChangeCallback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ServerSessionIDChangeCallback(IConVar *pConVar)
{
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&var) )
    CSteamWorksGameStatsUploader::SetServerSessionID(
      this: &g_SteamWorksGameStats,
      serverSessionID: var.m_pConVarState->m_Value.m_nValue);
}

//------------------------------------------------------------------------------
// Address: 0x10172EF0
// Name: public: virtual bool CSteamWorksGameStatsUploader::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamWorksGameStatsUploader::Init(CSteamWorksGameStatsUploader *this)
{
  CGameEventListener *v1; // esi

  v1 = &this->CGameEventListener;
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "server_spawn", a4: false);
  v1->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v1, a3: "client_disconnect", a4: false);
  ConVar::InstallChangeCallback(
    this: &steamworks_sessionid_server,
    callback: (void (__cdecl *)(IConVar *, const char *, float))ServerSessionIDChangeCallback,
    bInvoke: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1041C8B0
// Name: _dynamic_initializer_for__steamworks_sessionid_client__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__steamworks_sessionid_client__()
{
  ConVar::ConVar(
    this: &steamworks_sessionid_client,
    pName: "steamworks_sessionid_client",
    pDefaultValue: "0",
    flags: 16,
    pHelpString: "The client session ID for the new steamworks gamestats.");
  return atexit(func: dynamic_atexit_destructor_for__steamworks_sessionid_client__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C8E0
// Name: _dynamic_initializer_for__steamworks_sessionid_server__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__steamworks_sessionid_server__()
{
  ConVar::ConVar(
    this: &steamworks_sessionid_server,
    pName: "steamworks_sessionid_server",
    pDefaultValue: "0",
    flags: 8208,
    pHelpString: "The server session ID for the new steamworks gamestats.");
  return atexit(func: dynamic_atexit_destructor_for__steamworks_sessionid_server__);
}

//------------------------------------------------------------------------------
// Address: 0x10433B80
// Name: _dynamic_atexit_destructor_for__steamworks_sessionid_client__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__steamworks_sessionid_client__()
{
  ConVar::~ConVar(this: &steamworks_sessionid_client);
}

//------------------------------------------------------------------------------
// Address: 0x10433B90
// Name: _dynamic_atexit_destructor_for__steamworks_sessionid_server__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__steamworks_sessionid_server__()
{
  ConVar::~ConVar(this: &steamworks_sessionid_server);
}

//------------------------------------------------------------------------------
// Address: 0x1041C910
// Name: _dynamic_initializer_for__g_SteamWorksGameStats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SteamWorksGameStats__()
{
  CSteamWorksGameStatsUploader::CSteamWorksGameStatsUploader(this: &g_SteamWorksGameStats);
  return atexit(func: dynamic_atexit_destructor_for__g_SteamWorksGameStats__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C930
// Name: _dynamic_initializer_for__ShowSteamStatsSessionID__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ShowSteamStatsSessionID__()
{
  ConCommand::ConCommand(
    this: &ShowSteamStatsSessionID,
    pName: "ShowSteamStatsSessionID",
    callback: Show_Steam_Stats_Session_ID,
    pHelpString: "Prints out the game stats session ID's (developer convar must be set to non-zero).",
    flags: 2,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__ShowSteamStatsSessionID__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C960
// Name: _dynamic_initializer_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_preload__()
{
  ConVar::ConVar(
    this: &mod_load_preload,
    pName: "mod_load_preload",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Indicates how far ahead in seconds to preload animations.");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_preload__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C990
// Name: _dynamic_initializer_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_showstall__()
{
  ConVar::ConVar(
    this: &mod_load_showstall,
    pName: "mod_load_showstall",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "1 - show hitches , 2 - show stalls");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_showstall__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C9C0
// Name: _dynamic_initializer_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ActivityModifiersTable, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ActivityModifiersTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C9E0
// Name: _dynamic_initializer_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall dynamic_initializer_for__emptyMapping__(char a1)
{
  int v2; // [esp-4h] [ebp-Ch] BYREF
  CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs v3; // [esp+0h] [ebp-8h]
  int *v4; // [esp+4h] [ebp-4h]

  v4 = &v2;
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>(
    this: &emptyMapping.m_ActToSeqHash,
    bucketCount: 8,
    growCount: 0,
    initCount: 0,
    compareFunc: (CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs)a1,
    keyFunc: v3);
  emptyMapping.m_pStudioHdr = nullptr;
  emptyMapping.m_expectedVModel = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__emptyMapping__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CA30
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMaps__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CA40
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMapsLock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMapsLock__()
{
  g_StudioHdrToActivityMapsLock.m_ownerID = 0;
  g_StudioHdrToActivityMapsLock.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1041CA50
// Name: _dynamic_initializer_for__cheap_captions_test__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cheap_captions_test__()
{
  ConVar::ConVar(this: &cheap_captions_test, pName: "cheap_captions_test", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cheap_captions_test__);
}

//------------------------------------------------------------------------------
// Address: 0x1041CA80
// Name: _dynamic_initializer_for__cheap_captions_fadetime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cheap_captions_fadetime__()
{
  ConVar::ConVar(this: &cheap_captions_fadetime, pName: "cheap_captions_fadetime", pDefaultValue: "0.5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cheap_captions_fadetime__);
}

//------------------------------------------------------------------------------
// Address: 0x10433BA0
// Name: _dynamic_atexit_destructor_for__ShowSteamStatsSessionID__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ShowSteamStatsSessionID__()
{
  ConCommand::~ConCommand(this: &ShowSteamStatsSessionID);
}

//------------------------------------------------------------------------------
// Address: 0x10433BB0
// Name: _dynamic_atexit_destructor_for__g_SteamWorksGameStats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SteamWorksGameStats__()
{
  CSteamWorksGameStatsUploader::~CSteamWorksGameStatsUploader(this: &g_SteamWorksGameStats);
}

//------------------------------------------------------------------------------
// Address: 0x10433BC0
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x10433BD0
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x10433BE0
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x10433BF0
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10433C00
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      C_BaseEntity::operator delete(pMem: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    C_BaseEntity::operator delete(pMem: m_pSequenceTuples);
  }
  CUtlHash<CEntityDataInstantiator<physicspushlist_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<physicspushlist_t>::HashEntry const &,CEntityDataInstantiator<physicspushlist_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<physicspushlist_t>::HashEntry const &)>::Purge(this: (CUtlHash<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,bool (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &,CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &),unsigned int (__cdecl*)(CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry const &)> *)&emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>::~CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>(this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&emptyMapping.m_ActToSeqHash);
}

//------------------------------------------------------------------------------
// Address: 0x10433C40
// Name: _dynamic_atexit_destructor_for__cheap_captions_test__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cheap_captions_test__()
{
  ConVar::~ConVar(this: &cheap_captions_test);
}

//------------------------------------------------------------------------------
// Address: 0x10433C50
// Name: _dynamic_atexit_destructor_for__cheap_captions_fadetime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cheap_captions_fadetime__()
{
  ConVar::~ConVar(this: &cheap_captions_fadetime);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10224F20
// Name: class CSteamWorksGameStatsUploader __near & GetSteamWorksSGameStatsUploader(void)
// Source: json
//------------------------------------------------------------------------------
CSteamWorksGameStatsUploader *__cdecl GetSteamWorksSGameStatsUploader()
{
  return &g_SteamWorksGameStats;
}

//------------------------------------------------------------------------------
// Address: 0x10224F30
// Name: public: void CSteamWorksGameStatsUploader::Steam_OnSteamSessionInfoClosed(struct GameStatsSessionClosed_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamWorksGameStatsUploader::Steam_OnSteamSessionInfoClosed(
        CSteamWorksGameStatsUploader *this,
        GameStatsSessionClosed_t *pGameStatsSessionInfo)
{
  if ( this->m_bPassword )
    this->m_bPassword = false;
}

//------------------------------------------------------------------------------
// Address: 0x10224F50
// Name: void AddDataToKV(class KeyValues __near *,char const __near *,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddDataToKV(KeyValues *pKV, const char *name, unsigned __int64 data)
{
  KeyValues::SetUint64(this: pKV, keyName: name, value: data);
}

//------------------------------------------------------------------------------
// Address: 0x10224F70
// Name: void AddDataToKV(class KeyValues __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddDataToKV(KeyValues *pKV, const char *name, unsigned int data)
{
  KeyValues::SetInt(this: pKV, keyName: name, value: data);
}

//------------------------------------------------------------------------------
// Address: 0x10224F90
// Name: public: __int64 CSteamWorksGameStatsUploader::GetTimeSinceEpoch(void)
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall CSteamWorksGameStatsUploader::GetTimeSinceEpoch(CSteamWorksGameStatsUploader *this)
{
  ISteamUtils *m_pSteamUtils; // ecx
  __int64 aclock; // [esp+0h] [ebp-8h] BYREF

  if ( steamapicontext != nullptr )
  {
    m_pSteamUtils = steamapicontext->m_pSteamUtils;
    if ( m_pSteamUtils != nullptr )
      return m_pSteamUtils->GetServerRealTime(this: m_pSteamUtils);
  }
  _time64(timeptr: &aclock);
  return aclock;
}

//------------------------------------------------------------------------------
// Address: 0x10224FD0
// Name: public: virtual bool CSteamWorksGameStatsUploader::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamWorksGameStatsUploader::Init(CSteamWorksGameStatsUploader *this)
{
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "server_spawn", a4: true);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10224FF0
// Name: public: void CSteamWorksGameStatsUploader::Steam_OnSteamSessionInfoIssued(struct GameStatsSessionIssued_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamWorksGameStatsUploader::Steam_OnSteamSessionInfoIssued(
        CSteamWorksGameStatsUploader *this,
        GameStatsSessionIssued_t *pGameStatsSessionInfo)
{
  ISteamUtils *m_pSteamUtils; // ecx
  int v4; // eax
  int v5; // ecx
  unsigned int v6; // [esp-4h] [ebp-10h]
  CGameTrace *v7; // [esp+0h] [ebp-Ch]
  __int64 timeptr; // [esp+4h] [ebp-8h] BYREF

  if ( BYTE1(this->m_EndTime) != 0 )
  {
    BYTE1(this->m_EndTime) = 0;
    if ( pGameStatsSessionInfo != nullptr )
    {
      if ( pGameStatsSessionInfo->m_eResult == k_EResultOK )
      {
        DevMsg(a1: "Steamworks Stats: Received SERVER session id: %lli\n", pGameStatsSessionInfo->m_ulSessionID);
        if ( steamapicontext != nullptr && (m_pSteamUtils = steamapicontext->m_pSteamUtils) != nullptr )
        {
          v4 = m_pSteamUtils->GetServerRealTime(this: m_pSteamUtils);
          HIDWORD(timeptr) = 0;
        }
        else
        {
          _time64(&timeptr);
          v4 = timeptr;
        }
        *(_DWORD *)&this->m_pzHostName[236] = v4;
        *(_QWORD *)&this->m_pzHostName[256] = pGameStatsSessionInfo->m_ulSessionID;
        v5 = *(_DWORD *)&this->m_pzHostName[256];
        BYTE2(this->m_EndTime) = pGameStatsSessionInfo->m_bCollectingAny;
        HIBYTE(this->m_EndTime) = pGameStatsSessionInfo->m_bCollectingDetails;
        CCollisionProperty::TestCollision(
          this: (ConVar *)&steamworks_sessionid_server.IConVar,
          value: v5,
          fContentsMask: v6,
          tr: v7);
      }
      else
      {
        DevMsg(a1: "Steamworks Stats: SERVER session id not available.\n");
        LOBYTE(this->m_EndTime) = 1;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102250D0
// Name: private: class ISteamGameStats __near * CSteamWorksGameStatsUploader::GetInterface(void)
// Source: json
//------------------------------------------------------------------------------
ISteamGameStats *__thiscall CSteamWorksGameStatsUploader::GetInterface(CSteamWorksGameStatsUploader *this)
{
  int HSteamUser; // edi
  int HSteamPipe; // ebx
  CSteamID *v4; // eax
  int v6; // eax
  _BYTE v7[8]; // [esp+Ch] [ebp-8h] BYREF

  HSteamUser = 0;
  HSteamPipe = 0;
  if ( steamgameserverapicontext != nullptr
    && steamgameserverapicontext->m_pSteamGameServer != nullptr
    && steamgameserverapicontext->m_pSteamGameServerUtils != nullptr )
  {
    v4 = steamgameserverapicontext->m_pSteamGameServer->GetSteamID(
           this: steamgameserverapicontext->m_pSteamGameServer,
           result: v7);
    LODWORD(this->m_CallbackSteamSessionInfoClosed.m_Func) = v4->m_steamid.m_comp;
    DWORD1(this->m_CallbackSteamSessionInfoClosed.m_Func) = *((_DWORD *)&v4->m_steamid.m_comp + 1);
    DWORD2(this->m_CallbackSteamSessionInfoClosed.m_Func) = steamgameserverapicontext->m_pSteamGameServerUtils->GetAppID(this: steamgameserverapicontext->m_pSteamGameServerUtils);
    HSteamUser = _SteamGameServer_GetHSteamUser();
    HSteamPipe = _SteamGameServer_GetHSteamPipe();
  }
  if ( _g_pSteamClientGameServer != nullptr && engine != nullptr && engine->IsDedicatedServer(this: engine) )
    return (ISteamGameStats *)_g_pSteamClientGameServer->GetISteamGenericInterface(
                                this: _g_pSteamClientGameServer,
                                a2: HSteamUser,
                                a3: HSteamPipe,
                                a4: "SteamGameStats001");
  if ( _SteamClient() == 0 )
    return nullptr;
  v6 = _SteamClient();
  return (*(ISteamGameStats *(__thiscall **)(int, int, int, const char *))(*(_DWORD *)v6 + 52))(
           a1: v6,
           a2: HSteamUser,
           a3: HSteamPipe,
           a4: "SteamGameStats001");
}

//------------------------------------------------------------------------------
// Address: 0x102251A0
// Name: private: virtual int CCallback<class CSteamWorksGameStatsUploader,struct GameStatsSessionClosed_t,1>::GetCallbackSizeBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCallback<CSteamWorksGameStatsUploader,GameStatsSessionClosed_t,1>::GetCallbackSizeBytes(
        CCallback<CSteamWorksGameStatsUploader,GameStatsSessionClosed_t,1> *this)
{
  return 16;
}

//------------------------------------------------------------------------------
// Address: 0x102251B0
// Name: private: virtual void CCallback<class CSteamWorksGameStatsUploader,struct GameStatsSessionIssued_t,1>::Run(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CSteamWorksGameStatsUploader,GameStatsSessionIssued_t,1>::Run(
        CCallback<CSteamWorksGameStatsUploader,GameStatsSessionClosed_t,1> *this,
        void *pvParam)
{
  ((void (__thiscall *)(char *, void *))LODWORD(this->m_Func))(
    a1: (char *)this->m_pObj + DWORD1(this->m_Func),
    a2: pvParam);
}

//------------------------------------------------------------------------------
// Address: 0x102251D0
// Name: private: virtual void CCallback<class CSteamWorksGameStatsUploader,struct GameStatsSessionIssued_t,1>::Run(void __near *,bool,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CSteamWorksGameStatsUploader,GameStatsSessionIssued_t,1>::Run(
        CCallback<CSteamWorksGameStatsUploader,GameStatsSessionClosed_t,1> *this,
        void *pvParam,
        bool __formal,
        unsigned __int64 a4)
{
  ((void (__thiscall *)(char *, void *))LODWORD(this->m_Func))(
    a1: (char *)this->m_pObj + DWORD1(this->m_Func),
    a2: pvParam);
}

//------------------------------------------------------------------------------
// Address: 0x102251F0
// Name: private: enum EResult CSteamWorksGameStatsUploader::RequestSessionID(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CSteamWorksGameStatsUploader::RequestSessionID@<eax>(
        CSteamWorksGameStatsUploader *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>)
{
  ISteamGameStats *Interface; // eax
  int v6; // ebx
  void (__thiscall ***m_iCallback)(int, int, _DWORD, _DWORD); // ecx
  void (__thiscall **v8)(int, int, _DWORD, _DWORD); // edi

  if ( *(_QWORD *)&this->m_pzHostName[256] == 0 )
  {
    if ( BYTE1(this->m_EndTime) != (LOBYTE(this->m_StartTime) | this->m_pzHostName[256]) )
      return 22;
    LOBYTE(this->m_EndTime) = 1;
    LOBYTE(this->m_HumanCntInGame) = 1;
    if ( steamgameserverapicontext == nullptr
      || steamgameserverapicontext->m_pSteamGameServer == nullptr
      || _g_pSteamClientGameServer == nullptr
      || steamgameserverapicontext->m_pSteamGameServerUtils == nullptr )
    {
      return 3;
    }
    Interface = CSteamWorksGameStatsUploader::GetInterface(this);
    this->m_CallbackSteamSessionInfoClosed.m_iCallback = (int)Interface;
    if ( Interface != nullptr )
    {
      v6 = 1;
      if ( ((unsigned __int8 (__thiscall *)(IVEngineServer *, int, int))engine->IsDedicatedServer)(
             a1: engine,
             a2: a3,
             a3: a2) != 0 )
        v6 = 3;
      DevMsg(a1: "Steamworks Stats: Requesting SERVER session id.\n");
      m_iCallback = (void (__thiscall ***)(int, int, _DWORD, _DWORD))this->m_CallbackSteamSessionInfoClosed.m_iCallback;
      LOWORD(this->m_EndTime) = 256;
      v8 = *m_iCallback;
      CSteamWorksGameStatsUploader::GetTimeSinceEpoch(this);
      (*v8)(
        a1: this->m_CallbackSteamSessionInfoClosed.m_iCallback,
        a2: v6,
        a3: this->m_CallbackSteamSessionInfoClosed.m_Func,
        a4: DWORD1(this->m_CallbackSteamSessionInfoClosed.m_Func));
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102252C0
// Name: public: virtual void CSteamWorksGameStatsUploader::FrameUpdatePostEntityThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSteamWorksGameStatsUploader::FrameUpdatePostEntityThink(
        CSteamWorksGameStatsUploader *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>)
{
  if ( LOBYTE(this->m_HumanCntInGame) != 0 && (float)(gpGlobals->realtime - *(float *)&this->m_FriendCntInGame) >= 3.0 )
  {
    this->m_FriendCntInGame = LODWORD(gpGlobals->realtime);
    if ( steamgameserverapicontext != nullptr
      && steamgameserverapicontext->m_pSteamGameServer != nullptr
      && _g_pSteamClientGameServer != nullptr
      && steamgameserverapicontext->m_pSteamGameServerUtils != nullptr )
    {
      if ( LOBYTE(this->m_EndTime) != 0 )
        CSteamWorksGameStatsUploader::RequestSessionID(this, a2, a3);
      else
        LOBYTE(this->m_HumanCntInGame) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10225330
// Name: public: void CSteamWorksGameStatsUploader::StartSession(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __usercall CSteamWorksGameStatsUploader::StartSession(
        CSteamWorksGameStatsUploader *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>)
{
  CSteamWorksGameStatsUploader::RequestSessionID(this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x10225340
// Name: public: void CSteamWorksGameStatsUploader::WriteSessionRow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamWorksGameStatsUploader::WriteSessionRow(CSteamWorksGameStatsUploader *this)
{
  ISteamGameStats *Interface; // eax

  Interface = CSteamWorksGameStatsUploader::GetInterface(this);
  this->m_CallbackSteamSessionInfoClosed.m_iCallback = (int)Interface;
  if ( Interface != nullptr )
  {
    ((void (__thiscall *)(ISteamGameStats *, _DWORD, unsigned int, const char *, _DWORD))Interface->AddSessionAttributeInt)(
      a1: Interface,
      a2: *(_DWORD *)&this->m_pzHostName[256],
      a3: this->m_StartTime,
      a4: "AppID",
      a5: DWORD2(this->m_CallbackSteamSessionInfoClosed.m_Func));
    (*(void (__thiscall **)(int, _DWORD, unsigned int, const char *, _DWORD))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                                            + 8))(
      a1: this->m_CallbackSteamSessionInfoClosed.m_iCallback,
      a2: *(_DWORD *)&this->m_pzHostName[256],
      a3: this->m_StartTime,
      a4: "StartTime",
      a5: *(_DWORD *)&this->m_pzHostName[236]);
    (*(void (__thiscall **)(int, _DWORD, unsigned int, const char *, _DWORD))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                                            + 8))(
      a1: this->m_CallbackSteamSessionInfoClosed.m_iCallback,
      a2: *(_DWORD *)&this->m_pzHostName[256],
      a3: this->m_StartTime,
      a4: "EndTime",
      a5: *(_DWORD *)&this->m_pzHostName[240]);
    (*(void (__thiscall **)(int, _DWORD, unsigned int, const char *, ISteamGameStats **))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                                                        + 12))(
      a1: this->m_CallbackSteamSessionInfoClosed.m_iCallback,
      a2: *(_DWORD *)&this->m_pzHostName[256],
      a3: this->m_StartTime,
      a4: "ServerIP",
      a5: &this->m_SteamWorksInterface);
    (*(void (__thiscall **)(int, _DWORD, unsigned int, const char *, char *))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                                            + 12))(
      a1: this->m_CallbackSteamSessionInfoClosed.m_iCallback,
      a2: *(_DWORD *)&this->m_pzHostName[256],
      a3: this->m_StartTime,
      a4: "ServerName",
      a5: &this->m_pzMapStart[236]);
    (*(void (__thiscall **)(int, _DWORD, unsigned int, const char *, char *))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                                            + 12))(
      a1: this->m_CallbackSteamSessionInfoClosed.m_iCallback,
      a2: *(_DWORD *)&this->m_pzHostName[256],
      a3: this->m_StartTime,
      a4: "StartMap",
      a5: &this->m_pzServerIP[236]);
    (*(void (__thiscall **)(int, _DWORD, unsigned int, const char *, _DWORD))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                                            + 8))(
      a1: this->m_CallbackSteamSessionInfoClosed.m_iCallback,
      a2: *(_DWORD *)&this->m_pzHostName[256],
      a3: this->m_StartTime,
      a4: "PlayersInGame",
      a5: *(_DWORD *)&this->m_pzHostName[244]);
    (*(void (__thiscall **)(int, _DWORD, unsigned int, const char *, _DWORD))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                                            + 8))(
      a1: this->m_CallbackSteamSessionInfoClosed.m_iCallback,
      a2: *(_DWORD *)&this->m_pzHostName[256],
      a3: this->m_StartTime,
      a4: "FriendsInGame",
      a5: *(_DWORD *)&this->m_pzHostName[248]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10225470
// Name: private: enum EResult CSteamWorksGameStatsUploader::WriteIntToTable(int,unsigned __int64,char const __near *)
// Source: json
//------------------------------------------------------------------------------
EResult __thiscall CSteamWorksGameStatsUploader::WriteIntToTable(
        CSteamWorksGameStatsUploader *this,
        int value,
        unsigned __int64 iTableID,
        const char *pzRow)
{
  ISteamGameStats *Interface; // eax

  if ( this->m_CallbackSteamSessionInfoClosed.m_iCallback != 0 )
    return (*(EResult (__thiscall **)(int, _DWORD, _DWORD, const char *, int))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                                             + 32))(
             a1: this->m_CallbackSteamSessionInfoClosed.m_iCallback,
             a2: iTableID,
             a3: HIDWORD(iTableID),
             a4: pzRow,
             a5: value);
  Interface = CSteamWorksGameStatsUploader::GetInterface(this);
  this->m_CallbackSteamSessionInfoClosed.m_iCallback = (int)Interface;
  if ( Interface != nullptr )
    return (*(EResult (__thiscall **)(int, _DWORD, _DWORD, const char *, int))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                                             + 32))(
             a1: this->m_CallbackSteamSessionInfoClosed.m_iCallback,
             a2: iTableID,
             a3: HIDWORD(iTableID),
             a4: pzRow,
             a5: value);
  else
    return k_EResultNoConnection;
}

//------------------------------------------------------------------------------
// Address: 0x102254C0
// Name: private: enum EResult CSteamWorksGameStatsUploader::WriteInt64ToTable(unsigned __int64,unsigned __int64,char const __near *)
// Source: json
//------------------------------------------------------------------------------
EResult __thiscall CSteamWorksGameStatsUploader::WriteInt64ToTable(
        CSteamWorksGameStatsUploader *this,
        unsigned __int64 value,
        unsigned __int64 iTableID,
        const char *pzRow)
{
  ISteamGameStats *Interface; // eax

  if ( this->m_CallbackSteamSessionInfoClosed.m_iCallback != 0 )
    return (*(EResult (__thiscall **)(int, _DWORD, _DWORD, const char *, _DWORD, _DWORD))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                                                        + 48))(
             a1: this->m_CallbackSteamSessionInfoClosed.m_iCallback,
             a2: iTableID,
             a3: HIDWORD(iTableID),
             a4: pzRow,
             a5: value,
             a6: HIDWORD(value));
  Interface = CSteamWorksGameStatsUploader::GetInterface(this);
  this->m_CallbackSteamSessionInfoClosed.m_iCallback = (int)Interface;
  if ( Interface != nullptr )
    return (*(EResult (__thiscall **)(int, _DWORD, _DWORD, const char *, _DWORD, _DWORD))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                                                        + 48))(
             a1: this->m_CallbackSteamSessionInfoClosed.m_iCallback,
             a2: iTableID,
             a3: HIDWORD(iTableID),
             a4: pzRow,
             a5: value,
             a6: HIDWORD(value));
  else
    return k_EResultNoConnection;
}

//------------------------------------------------------------------------------
// Address: 0x10225510
// Name: private: enum EResult CSteamWorksGameStatsUploader::WriteFloatToTable(float,unsigned __int64,char const __near *)
// Source: json
//------------------------------------------------------------------------------
EResult __thiscall CSteamWorksGameStatsUploader::WriteFloatToTable(
        CSteamWorksGameStatsUploader *this,
        float value,
        unsigned __int64 iTableID,
        const char *pzRow)
{
  ISteamGameStats *Interface; // eax

  if ( this->m_CallbackSteamSessionInfoClosed.m_iCallback != 0 )
    return (*(EResult (__stdcall **)(_DWORD, _DWORD, const char *, _DWORD))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                                          + 40))(
             a1: iTableID,
             a2: HIDWORD(iTableID),
             a3: pzRow,
             a4: LODWORD(value));
  Interface = CSteamWorksGameStatsUploader::GetInterface(this);
  this->m_CallbackSteamSessionInfoClosed.m_iCallback = (int)Interface;
  if ( Interface != nullptr )
    return (*(EResult (__stdcall **)(_DWORD, _DWORD, const char *, _DWORD))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                                          + 40))(
             a1: iTableID,
             a2: HIDWORD(iTableID),
             a3: pzRow,
             a4: LODWORD(value));
  else
    return k_EResultNoConnection;
}

//------------------------------------------------------------------------------
// Address: 0x10225560
// Name: private: enum EResult CSteamWorksGameStatsUploader::WriteStringToTable(char const __near *,unsigned __int64,char const __near *)
// Source: json
//------------------------------------------------------------------------------
EResult __thiscall CSteamWorksGameStatsUploader::WriteStringToTable(
        CSteamWorksGameStatsUploader *this,
        const char *value,
        unsigned __int64 iTableID,
        const char *pzRow)
{
  ISteamGameStats *Interface; // eax

  if ( this->m_CallbackSteamSessionInfoClosed.m_iCallback != 0 )
    return (*(EResult (__thiscall **)(int, _DWORD, _DWORD, const char *, const char *))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                                                      + 36))(
             a1: this->m_CallbackSteamSessionInfoClosed.m_iCallback,
             a2: iTableID,
             a3: HIDWORD(iTableID),
             a4: pzRow,
             a5: value);
  Interface = CSteamWorksGameStatsUploader::GetInterface(this);
  this->m_CallbackSteamSessionInfoClosed.m_iCallback = (int)Interface;
  if ( Interface != nullptr )
    return (*(EResult (__thiscall **)(int, _DWORD, _DWORD, const char *, const char *))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                                                      + 36))(
             a1: this->m_CallbackSteamSessionInfoClosed.m_iCallback,
             a2: iTableID,
             a3: HIDWORD(iTableID),
             a4: pzRow,
             a5: value);
  else
    return k_EResultNoConnection;
}

//------------------------------------------------------------------------------
// Address: 0x102255B0
// Name: private: void CSteamWorksGameStatsUploader::Reset(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CSteamWorksGameStatsUploader::Reset(CSteamWorksGameStatsUploader *this)
{
  int v2; // edi
  unsigned int v3; // [esp-8h] [ebp-14h]
  CGameTrace *v4; // [esp-4h] [ebp-10h]

  CCollisionProperty::TestCollision(
    this: (ConVar *)&steamworks_sessionid_server.IConVar,
    value: 0,
    fContentsMask: v3,
    tr: v4);
  LOBYTE(this->m_HumanCntInGame) = 0;
  this->m_FriendCntInGame = 0;
  *(_DWORD *)&this->m_pzHostName[256] = 0;
  this->m_StartTime = 0;
  this->m_bPassword = false;
  this->m_EndTime = 0;
  this->m_CallbackSteamSessionInfoClosed.m_Func = 0u;
  memset(dst: (int)&this->m_SteamWorksInterface, value: nullptr, count: 0x104u);
  memset(dst: (int)&this->m_pzServerIP[236], value: nullptr, count: 0x104u);
  memset(dst: (int)&this->m_pzMapStart[236], value: nullptr, count: 0x104u);
  v2 = 0;
  *(_DWORD *)&this->m_pzHostName[236] = 0;
  *(_DWORD *)&this->m_pzHostName[240] = 0;
  *(_DWORD *)&this->m_pzHostName[244] = 0;
  for ( *(_DWORD *)&this->m_pzHostName[248] = 0; v2 < *(_DWORD *)&this->m_ServiceTicking; ++v2 )
    KeyValues::deleteThis(this: *(KeyValues **)(LODWORD(this->m_SessionID) + 4 * v2));
  *(_DWORD *)&this->m_ServiceTicking = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10225680
// Name: private: enum EResult CSteamWorksGameStatsUploader::ParseKeyValuesAndSendStats(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamWorksGameStatsUploader::ParseKeyValuesAndSendStats(
        CSteamWorksGameStatsUploader *this,
        KeyValues *pKV)
{
  ISteamGameStats *Interface; // eax
  const char *Name; // eax
  int m_iCallback; // ecx
  const char *v8; // edi
  void (__thiscall *v9)(int, unsigned __int64 *, int, unsigned int, const char *); // eax
  KeyValues *FirstSubKey; // eax
  const char *v11; // edi
  const char *String; // eax
  int Int; // eax
  unsigned __int64 Uint64; // rax
  int v15; // esi
  float defaultValue; // [esp+10h] [ebp-12Ch]
  int v17; // [esp+14h] [ebp-128h]
  unsigned __int64 v18; // [esp+14h] [ebp-128h]
  unsigned __int64 v19; // [esp+14h] [ebp-128h]
  unsigned __int64 v20; // [esp+14h] [ebp-128h]
  unsigned __int64 v21; // [esp+14h] [ebp-128h]
  unsigned int m_StartTime; // [esp+18h] [ebp-124h]
  const char *v23; // [esp+1Ch] [ebp-120h]
  char pzMessage[260]; // [esp+2Ch] [ebp-110h] BYREF
  const char *pzTable; // [esp+130h] [ebp-Ch]
  unsigned __int64 iTableID; // [esp+134h] [ebp-8h] BYREF
  KeyValues *pData; // [esp+144h] [ebp+8h]

  if ( pKV == nullptr || BYTE2(this->m_EndTime) == 0 )
    return 2;
  Interface = CSteamWorksGameStatsUploader::GetInterface(this);
  this->m_CallbackSteamSessionInfoClosed.m_iCallback = (int)Interface;
  if ( Interface != nullptr )
  {
    Name = KeyValues::GetName(this: pKV);
    m_iCallback = this->m_CallbackSteamSessionInfoClosed.m_iCallback;
    v8 = Name;
    v23 = Name;
    m_StartTime = this->m_StartTime;
    v17 = *(_DWORD *)&this->m_pzHostName[256];
    iTableID = 0;
    v9 = *(void (__thiscall **)(int, unsigned __int64 *, int, unsigned int, const char *))(*(_DWORD *)m_iCallback + 20);
    pzTable = v23;
    v9(a1: m_iCallback, a2: &iTableID, a3: v17, a4: m_StartTime, a5: v23);
    if ( iTableID != 0 )
    {
      CSteamWorksGameStatsUploader::WriteInt64ToTable(
        this,
        value: *(_QWORD *)&this->m_pzHostName[256],
        iTableID,
        pzRow: "SessionID");
      FirstSubKey = KeyValues::GetFirstSubKey(this: pKV);
      pData = FirstSubKey;
      if ( FirstSubKey != nullptr )
      {
        while ( 1 )
        {
          v11 = KeyValues::GetName(this: FirstSubKey);
          switch ( KeyValues::GetDataType(this: pData, keyName: nullptr) )
          {
            case 1:
              v18 = iTableID;
              String = KeyValues::GetString(this: pKV, keyName: v11, defaultValue: locale);
              CSteamWorksGameStatsUploader::WriteStringToTable(this, value: String, iTableID: v18, pzRow: v11);
              break;
            case 2:
              v19 = iTableID;
              Int = KeyValues::GetInt(this: pKV, keyName: v11, defaultValue: 0);
              CSteamWorksGameStatsUploader::WriteIntToTable(this, value: Int, iTableID: v19, pzRow: v11);
              break;
            case 3:
              v20 = iTableID;
              defaultValue = KeyValues::GetFloat(this: pKV, keyName: v11, defaultValue: 0.0);
              CSteamWorksGameStatsUploader::WriteFloatToTable(this, value: defaultValue, iTableID: v20, pzRow: v11);
              break;
            case 7:
              v21 = iTableID;
              Uint64 = KeyValues::GetUint64(this: pKV, keyName: v11, defaultValue: 0);
              CSteamWorksGameStatsUploader::WriteInt64ToTable(this, value: Uint64, iTableID: v21, pzRow: v11);
              break;
            default:
              break;
          }
          pData = KeyValues::GetNextKey(this: pData);
          if ( pData == nullptr )
            break;
          FirstSubKey = pData;
        }
        v8 = pzTable;
      }
      v15 = (*(int (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                       + 24))(
              a1: this->m_CallbackSteamSessionInfoClosed.m_iCallback,
              a2: iTableID,
              a3: HIDWORD(iTableID));
      if ( v15 != 1 )
      {
        memset(pzMessage, 0, sizeof(pzMessage));
        V_snprintf(pDest: pzMessage, maxLen: 260, pFormat: "Failed To Submit table %s", v8);
      }
      return v15;
    }
    else
    {
      return 2;
    }
  }
  else
  {
    DevMsg(a1: "WARNING: Attempted to send a steamworks gamestats row when the steamworks interface was not available!");
    return 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10225890
// Name: public: virtual CSteamWorksGameStatsUploader::~CSteamWorksGameStatsUploader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamWorksGameStatsUploader::~CSteamWorksGameStatsUploader(CSteamWorksGameStatsUploader *this)
{
  bool v2; // zf

  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_SessionID);
  v2 = (BYTE4(this->m_CallbackSteamSessionInfoIssued.m_Func) & 1) == 0;
  LODWORD(this->m_CallbackSteamSessionInfoIssued.m_Func) = &CCallback<CSteamWorksGameStatsUploader,GameStatsSessionClosed_t,1>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackSteamSessionInfoIssued.m_Func);
  v2 = (*((_BYTE *)&this->CGameEventListener + 16) & 1) == 0;
  *((_DWORD *)&this->CGameEventListener + 3) = &CCallback<CSteamWorksGameStatsUploader,GameStatsSessionIssued_t,1>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->CGameEventListener + 1);
  v2 = !this->m_bRegisteredForEvents;
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 13;
  if ( !v2 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->CGameEventListener);
    this->m_bRegisteredForEvents = false;
  }
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&IGameEventListener2::`vftable';
  IGameSystemPerFrame::~IGameSystemPerFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x10225910
// Name: public: CSteamWorksGameStatsUploader::CSteamWorksGameStatsUploader(void)
// Source: json
//------------------------------------------------------------------------------
CSteamWorksGameStatsUploader *__thiscall CSteamWorksGameStatsUploader::CSteamWorksGameStatsUploader(
        CSteamWorksGameStatsUploader *this)
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this, name: "CSteamWorksGameStatsUploader");
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 42;
  this->m_bRegisteredForEvents = false;
  this->CAutoGameSystemPerFrame::CBaseGameSystemPerFrame::IGameSystemPerFrame::IGameSystem::__vftable = (CSteamWorksGameStatsUploader_vtbl *)&CSteamWorksGameStatsUploader::`vftable'{for `CAutoGameSystemPerFrame'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CSteamWorksGameStatsUploader::`vftable'{for `CGameEventListener'};
  *((_BYTE *)&this->CGameEventListener + 16) = 0;
  this->m_CallbackSteamSessionInfoIssued.__vftable = nullptr;
  *((_DWORD *)&this->CGameEventListener + 3) = &CCallback<CSteamWorksGameStatsUploader,GameStatsSessionIssued_t,1>::`vftable';
  *(_DWORD *)&this->m_CallbackSteamSessionInfoIssued.m_nCallbackFlags = this;
  this->m_CallbackSteamSessionInfoIssued.m_iCallback = (int)CSteamWorksGameStatsUploader::Steam_OnSteamSessionInfoIssued;
  this->m_CallbackSteamSessionInfoIssued.m_pObj = nullptr;
  if ( CSteamWorksGameStatsUploader::Steam_OnSteamSessionInfoIssued != nullptr )
  {
    *((_BYTE *)&this->CGameEventListener + 16) = 2;
    *(_DWORD *)&this->m_CallbackSteamSessionInfoIssued.m_nCallbackFlags = this;
    this->m_CallbackSteamSessionInfoIssued.m_iCallback = (int)CSteamWorksGameStatsUploader::Steam_OnSteamSessionInfoIssued;
    this->m_CallbackSteamSessionInfoIssued.m_pObj = nullptr;
    _SteamAPI_RegisterCallback(a1: &this->CGameEventListener + 1, a2: 2001);
  }
  BYTE4(this->m_CallbackSteamSessionInfoIssued.m_Func) = 0;
  DWORD2(this->m_CallbackSteamSessionInfoIssued.m_Func) = 0;
  LODWORD(this->m_CallbackSteamSessionInfoIssued.m_Func) = &CCallback<CSteamWorksGameStatsUploader,GameStatsSessionClosed_t,1>::`vftable';
  HIDWORD(this->m_CallbackSteamSessionInfoIssued.m_Func) = this;
  this->m_CallbackSteamSessionInfoClosed.__vftable = (CCallback<CSteamWorksGameStatsUploader,GameStatsSessionClosed_t,1>_vtbl *)CSteamWorksGameStatsUploader::Steam_OnSteamSessionInfoClosed;
  *(_DWORD *)&this->m_CallbackSteamSessionInfoClosed.m_nCallbackFlags = 0;
  if ( CSteamWorksGameStatsUploader::Steam_OnSteamSessionInfoClosed != nullptr )
  {
    BYTE4(this->m_CallbackSteamSessionInfoIssued.m_Func) = 2;
    HIDWORD(this->m_CallbackSteamSessionInfoIssued.m_Func) = this;
    this->m_CallbackSteamSessionInfoClosed.__vftable = (CCallback<CSteamWorksGameStatsUploader,GameStatsSessionClosed_t,1>_vtbl *)CSteamWorksGameStatsUploader::Steam_OnSteamSessionInfoClosed;
    *(_DWORD *)&this->m_CallbackSteamSessionInfoClosed.m_nCallbackFlags = 0;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackSteamSessionInfoIssued.m_Func, a2: 2002);
  }
  LODWORD(this->m_SessionID) = 0;
  HIDWORD(this->m_SessionID) = 0;
  *(_DWORD *)&this->m_SessionIDRequestUnsent = 0;
  *(_DWORD *)&this->m_ServiceTicking = 0;
  this->m_LastServiceTick = 0.0;
  CSteamWorksGameStatsUploader::Reset(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10225A40
// Name: public: void CSteamWorksGameStatsUploader::FlushStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamWorksGameStatsUploader::FlushStats(CSteamWorksGameStatsUploader *this)
{
  int v1; // edi
  KeyValues *v3; // ebx
  ISteamGameStats *Interface; // eax
  const char *Name; // eax
  int m_iCallback; // ecx
  bool v7; // zf
  int v8; // edi
  int v9; // eax
  unsigned int v10; // ecx
  ISteamGameStats *v11; // eax
  KeyValues *FirstSubKey; // eax
  const char *v13; // edi
  const char *String; // eax
  int Int; // eax
  ISteamGameStats *v16; // eax
  unsigned __int64 Uint64; // rax
  int v18; // [esp+1Ch] [ebp-14Ch]
  unsigned __int64 v19; // [esp+1Ch] [ebp-14Ch]
  unsigned __int64 v20; // [esp+1Ch] [ebp-14Ch]
  unsigned __int64 v21; // [esp+1Ch] [ebp-14Ch]
  unsigned int m_StartTime; // [esp+20h] [ebp-148h]
  char pDest[264]; // [esp+34h] [ebp-134h] BYREF
  int v24; // [esp+13Ch] [ebp-2Ch]
  float Float; // [esp+140h] [ebp-28h]
  const char *v26; // [esp+144h] [ebp-24h]
  unsigned __int64 v27; // [esp+148h] [ebp-20h]
  int v28; // [esp+150h] [ebp-18h]
  unsigned int v29; // [esp+154h] [ebp-14h]
  int i; // [esp+158h] [ebp-10h]
  KeyValues *NextKey; // [esp+15Ch] [ebp-Ch]
  unsigned __int64 iTableID; // [esp+160h] [ebp-8h] BYREF

  v1 = 0;
  i = 0;
  if ( *(int *)&this->m_ServiceTicking <= 0 )
  {
    *(_DWORD *)&this->m_ServiceTicking = 0;
  }
  else
  {
    do
    {
      v3 = *(KeyValues **)(LODWORD(this->m_SessionID) + 4 * v1);
      if ( v3 != nullptr && BYTE2(this->m_EndTime) != 0 )
      {
        Interface = CSteamWorksGameStatsUploader::GetInterface(this);
        this->m_CallbackSteamSessionInfoClosed.m_iCallback = (int)Interface;
        if ( Interface != nullptr )
        {
          Name = KeyValues::GetName(this: v3);
          m_iCallback = this->m_CallbackSteamSessionInfoClosed.m_iCallback;
          v26 = Name;
          m_StartTime = this->m_StartTime;
          v18 = *(_DWORD *)&this->m_pzHostName[256];
          iTableID = 0;
          (*(void (__thiscall **)(int, unsigned __int64 *, int, unsigned int, const char *))(*(_DWORD *)m_iCallback + 20))(
            a1: m_iCallback,
            a2: &iTableID,
            a3: v18,
            a4: m_StartTime,
            a5: Name);
          if ( iTableID != 0 )
          {
            v7 = this->m_CallbackSteamSessionInfoClosed.m_iCallback == 0;
            v8 = iTableID;
            v9 = *(_DWORD *)&this->m_pzHostName[256];
            v24 = HIDWORD(iTableID);
            v10 = this->m_StartTime;
            v28 = v9;
            v29 = v10;
            if ( !v7
              || (v11 = CSteamWorksGameStatsUploader::GetInterface(this),
                  this->m_CallbackSteamSessionInfoClosed.m_iCallback = (int)v11,
                  v11 != nullptr) )
            {
              (*(void (__thiscall **)(int, int, int, const char *, int, unsigned int))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                                                     + 48))(
                a1: this->m_CallbackSteamSessionInfoClosed.m_iCallback,
                a2: v8,
                a3: v24,
                a4: "SessionID",
                a5: v28,
                a6: v29);
            }
            FirstSubKey = KeyValues::GetFirstSubKey(this: v3);
            NextKey = FirstSubKey;
            if ( FirstSubKey != nullptr )
            {
              while ( 1 )
              {
                v13 = KeyValues::GetName(this: FirstSubKey);
                switch ( KeyValues::GetDataType(this: NextKey, keyName: nullptr) )
                {
                  case 1:
                    v19 = iTableID;
                    String = KeyValues::GetString(this: v3, keyName: v13, defaultValue: locale);
                    CSteamWorksGameStatsUploader::WriteStringToTable(this, value: String, iTableID: v19, pzRow: v13);
                    break;
                  case 2:
                    v20 = iTableID;
                    Int = KeyValues::GetInt(this: v3, keyName: v13, defaultValue: 0);
                    CSteamWorksGameStatsUploader::WriteIntToTable(this, value: Int, iTableID: v20, pzRow: v13);
                    break;
                  case 3:
                    v27 = iTableID;
                    Float = KeyValues::GetFloat(this: v3, keyName: v13, defaultValue: 0.0);
                    if ( this->m_CallbackSteamSessionInfoClosed.m_iCallback != 0
                      || (v16 = CSteamWorksGameStatsUploader::GetInterface(this),
                          this->m_CallbackSteamSessionInfoClosed.m_iCallback = (int)v16,
                          v16 != nullptr) )
                    {
                      (*(void (__stdcall **)(_DWORD, _DWORD, const char *, float))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                                                 + 40))(
                        a1: v27,
                        a2: HIDWORD(v27),
                        a3: v13,
                        a4: COERCE_FLOAT(LODWORD(Float)));
                    }
                    break;
                  case 7:
                    v21 = iTableID;
                    Uint64 = KeyValues::GetUint64(this: v3, keyName: v13, defaultValue: 0);
                    CSteamWorksGameStatsUploader::WriteInt64ToTable(this, value: Uint64, iTableID: v21, pzRow: v13);
                    break;
                  default:
                    break;
                }
                NextKey = KeyValues::GetNextKey(this: NextKey);
                if ( NextKey == nullptr )
                  break;
                FirstSubKey = NextKey;
              }
            }
            if ( (*(int (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                            + 24))(
                   a1: this->m_CallbackSteamSessionInfoClosed.m_iCallback,
                   a2: iTableID,
                   a3: HIDWORD(iTableID)) != 1 )
            {
              memset(pDest, 0, 260);
              V_snprintf(pDest, maxLen: 260, pFormat: "Failed To Submit table %s", v26);
            }
            v1 = i;
          }
        }
        else
        {
          DevMsg(a1: "WARNING: Attempted to send a steamworks gamestats row when the steamworks interface was not available!");
        }
      }
      KeyValues::deleteThis(this: *(KeyValues **)(LODWORD(this->m_SessionID) + 4 * v1++));
      i = v1;
    }
    while ( v1 < *(_DWORD *)&this->m_ServiceTicking );
    *(_DWORD *)&this->m_ServiceTicking = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10225CE0
// Name: private: void CSteamWorksGameStatsUploader::ServerAddressToInt(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamWorksGameStatsUploader::ServerAddressToInt(CSteamWorksGameStatsUploader *this)
{
  int m_Size; // eax
  int v3; // esi
  char **m_pMemory; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > IPs; // [esp+8h] [ebp-18h] BYREF
  unsigned __int8 v6[4]; // [esp+1Ch] [ebp-4h]

  memset(&IPs, 0, sizeof(IPs));
  V_SplitString(pString: (const char *)&this->m_SteamWorksInterface, pSeparator: ".", outStrings: &IPs);
  m_Size = IPs.m_Size;
  HIDWORD(this->m_CallbackSteamSessionInfoClosed.m_Func) = 0;
  if ( m_Size >= 4 )
  {
    v3 = 0;
    do
    {
      if ( v3 >= 4 )
        break;
      v6[v3] = V_atoi(str: IPs.m_Memory.m_pMemory[v3]);
      ++v3;
    }
    while ( v3 < IPs.m_Size );
    m_pMemory = IPs.m_Memory.m_pMemory;
    HIDWORD(this->m_CallbackSteamSessionInfoClosed.m_Func) = v6[3] + ((v6[2] + ((v6[1] + (v6[0] << 8)) << 8)) << 8);
    IPs.m_Size = 0;
    if ( IPs.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        m_pMemory = nullptr;
        IPs.m_Memory.m_pMemory = nullptr;
      }
      IPs.m_Memory.m_nAllocationCount = 0;
    }
    IPs.m_pElements = m_pMemory;
    if ( IPs.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
  else
  {
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&IPs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10225DC0
// Name: public: virtual void CSteamWorksGameStatsUploader::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSteamWorksGameStatsUploader::FireGameEvent(
        CSteamWorksGameStatsUploader *this@<ecx>,
        int a2@<ebx>,
        IGameEvent *event)
{
  const char *v4; // eax
  const char *v5; // ebx
  const char *v6; // eax
  char *v7; // edi
  const char *v8; // ebx
  int v9; // eax
  const char *v10; // eax
  const char *v11; // eax

  if ( event != nullptr )
  {
    v4 = event->GetName(this: event);
    v5 = v4;
    if ( v4 != "hostname_changed" && _V_stricmp(s1: "hostname_changed", s2: v4) != 0 )
    {
      if ( v5 == "server_spawn" || _V_stricmp(s1: "server_spawn", s2: v5) == 0 )
      {
        v8 = (const char *)((int (__thiscall *)(IGameEvent *, const char *, const char *, int))event->GetString)(
                             a1: event,
                             a2: "address",
                             a3: locale,
                             a4: a2);
        if ( v8 != nullptr )
        {
          v9 = event->GetInt(this: event, a2: "port", a3: 0);
          V_snprintf(
            pDest: (char *)&this->m_CallbackSteamSessionInfoClosed.m_Func + 4,
            maxLen: 260,
            pFormat: "%s:%d",
            v8,
            v9);
          CSteamWorksGameStatsUploader::ServerAddressToInt(this: (CSteamWorksGameStatsUploader *)((char *)this - 12));
        }
        else
        {
          V_strncpy(
            pDest: (char *)&this->m_CallbackSteamSessionInfoClosed.m_Func + 4,
            pSrc: "No Server Address",
            maxLen: 260);
          LODWORD(this->m_CallbackSteamSessionInfoClosed.m_Func) = 0;
        }
        v10 = event->GetString(this: event, a2: "hostname", a3: locale);
        if ( v10 != nullptr )
          V_strncpy(pDest: &this->m_pzMapStart[224], pSrc: v10, maxLen: 260);
        else
          V_strncpy(pDest: &this->m_pzMapStart[224], pSrc: "No Host Name", maxLen: 260);
        v11 = event->GetString(this: event, a2: "mapname", a3: locale);
        if ( v11 != nullptr )
          V_strncpy(pDest: &this->m_pzServerIP[224], pSrc: v11, maxLen: 260);
        else
          V_strncpy(pDest: &this->m_pzServerIP[224], pSrc: "No Map Name", maxLen: 260);
        this->m_pzHostName[240] = event->GetBool(this: event, a2: "password", a3: false);
      }
    }
    else
    {
      v6 = event->GetString(this: event, a2: "hostname", a3: locale);
      v7 = &this->m_pzMapStart[224];
      if ( v6 != nullptr )
        V_strncpy(pDest: v7, pSrc: v6, maxLen: 260);
      else
        V_strncpy(pDest: v7, pSrc: "No Host Name", maxLen: 260);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10225F60
// Name: public: void CSteamWorksGameStatsUploader::EndSession(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamWorksGameStatsUploader::EndSession(CSteamWorksGameStatsUploader *this)
{
  ISteamUtils *m_pSteamUtils; // ecx
  int v3; // eax
  bool v4; // zf
  ISteamGameStats *Interface; // eax
  __int64 timeptr; // [esp+4h] [ebp-8h] BYREF

  if ( steamapicontext != nullptr && (m_pSteamUtils = steamapicontext->m_pSteamUtils) != nullptr )
  {
    v3 = m_pSteamUtils->GetServerRealTime(this: m_pSteamUtils);
    HIDWORD(timeptr) = 0;
  }
  else
  {
    _time64(&timeptr);
    v3 = timeptr;
  }
  v4 = *(_QWORD *)&this->m_pzHostName[256] == 0;
  *(_DWORD *)&this->m_pzHostName[240] = v3;
  if ( !v4 )
  {
    Interface = CSteamWorksGameStatsUploader::GetInterface(this);
    this->m_CallbackSteamSessionInfoClosed.m_iCallback = (int)Interface;
    if ( Interface != nullptr )
    {
      DevMsg(a1: "Steamworks Stats: Ending SERVER session id: %lli\n", *(_QWORD *)&this->m_pzHostName[256]);
      CSteamWorksGameStatsUploader::FlushStats(this);
      CSteamWorksGameStatsUploader::WriteSessionRow(this);
      (*(void (__thiscall **)(int, _DWORD, unsigned int, _DWORD, _DWORD))(*(_DWORD *)this->m_CallbackSteamSessionInfoClosed.m_iCallback
                                                                        + 4))(
        a1: this->m_CallbackSteamSessionInfoClosed.m_iCallback,
        a2: *(_DWORD *)&this->m_pzHostName[256],
        a3: this->m_StartTime,
        a4: *(_DWORD *)&this->m_pzHostName[240],
        a5: 0);
      *(_DWORD *)&this->m_pzHostName[256] = 0;
      this->m_StartTime = 0;
      CSteamWorksGameStatsUploader::Reset(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10226030
// Name: public: enum EResult CSteamWorksGameStatsUploader::AddStatsForUpload(class KeyValues __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamWorksGameStatsUploader::AddStatsForUpload(
        CSteamWorksGameStatsUploader *this,
        KeyValues *pKV,
        bool bSendImmediately)
{
  int m_SessionID_high; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_SessionID; // esi
  int v6; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v8; // eax
  vgui::TreeNode **v9; // eax

  if ( pKV == nullptr )
    return 2;
  if ( bSendImmediately )
  {
    CSteamWorksGameStatsUploader::ParseKeyValuesAndSendStats(this, pKV);
    KeyValues::deleteThis(this: pKV);
    return 1;
  }
  else
  {
    m_SessionID_high = HIDWORD(this->m_SessionID);
    p_m_SessionID = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_SessionID;
    v6 = *(_DWORD *)&this->m_ServiceTicking;
    if ( v6 + 1 > m_SessionID_high )
      CUtlMemory<CNavLadder *,int>::Grow(this: p_m_SessionID, num: v6 - m_SessionID_high + 1);
    ++p_m_SessionID[1].m_pMemory;
    m_pMemory = p_m_SessionID->m_pMemory;
    v8 = (int)p_m_SessionID[1].m_pMemory - v6 - 1;
    p_m_SessionID[1].m_nAllocationCount = (int)p_m_SessionID->m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v8);
    v9 = &p_m_SessionID->m_pMemory[v6];
    if ( v9 != nullptr )
      *v9 = (vgui::TreeNode *)pKV;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040A770
// Name: _dynamic_initializer_for__steamworks_sessionid_server__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__steamworks_sessionid_server__()
{
  ConVar::ConVar(
    this: &steamworks_sessionid_server,
    pName: "steamworks_sessionid_server",
    pDefaultValue: "0",
    flags: 8208,
    pHelpString: "The server session ID for the new steamworks gamestats.");
  return atexit(func: dynamic_atexit_destructor_for__steamworks_sessionid_server__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E240
// Name: _dynamic_atexit_destructor_for__steamworks_sessionid_server__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__steamworks_sessionid_server__()
{
  ConVar::~ConVar(this: &steamworks_sessionid_server);
}

//------------------------------------------------------------------------------
// Address: 0x1040A7A0
// Name: _dynamic_initializer_for__g_SteamWorksGameStats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SteamWorksGameStats__()
{
  CSteamWorksGameStatsUploader::CSteamWorksGameStatsUploader(this: &g_SteamWorksGameStats);
  return atexit(func: dynamic_atexit_destructor_for__g_SteamWorksGameStats__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A7C0
// Name: _dynamic_initializer_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_preload__()
{
  ConVar::ConVar(
    this: &mod_load_preload,
    pName: "mod_load_preload",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Indicates how far ahead in seconds to preload animations.");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_preload__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A7F0
// Name: _dynamic_initializer_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_showstall__()
{
  ConVar::ConVar(
    this: &mod_load_showstall,
    pName: "mod_load_showstall",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "1 - show hitches , 2 - show stalls");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_showstall__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A820
// Name: _dynamic_initializer_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ActivityModifiersTable, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ActivityModifiersTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A840
// Name: _dynamic_initializer_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall dynamic_initializer_for__emptyMapping__(char a1)
{
  int v2; // [esp-4h] [ebp-Ch] BYREF
  CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs v3; // [esp+0h] [ebp-8h]
  int *v4; // [esp+4h] [ebp-4h]

  v4 = &v2;
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>(
    this: &emptyMapping.m_ActToSeqHash,
    bucketCount: 8,
    growCount: 0,
    initCount: 0,
    compareFunc: (CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs)a1,
    keyFunc: v3);
  emptyMapping.m_pStudioHdr = nullptr;
  emptyMapping.m_expectedVModel = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__emptyMapping__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A890
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMaps__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__);
}

//------------------------------------------------------------------------------
// Address: 0x1040A8A0
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMapsLock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMapsLock__()
{
  g_StudioHdrToActivityMapsLock.m_ownerID = 0;
  g_StudioHdrToActivityMapsLock.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1041E250
// Name: _dynamic_atexit_destructor_for__g_SteamWorksGameStats__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SteamWorksGameStats__()
{
  CSteamWorksGameStatsUploader::~CSteamWorksGameStatsUploader(this: &g_SteamWorksGameStats);
}

//------------------------------------------------------------------------------
// Address: 0x1041E260
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x1041E270
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x1041E280
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041E290
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1041E2A0
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      free(pMem: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    free(pMem: m_pSequenceTuples);
  }
  CUtlHash<CEntityDataInstantiator<physicspushlist_t>::HashEntry,bool (__cdecl *)(CEntityDataInstantiator<physicspushlist_t>::HashEntry const &,CEntityDataInstantiator<physicspushlist_t>::HashEntry const &),unsigned int (__cdecl *)(CEntityDataInstantiator<physicspushlist_t>::HashEntry const &)>::Purge(this: (CUtlHash<EntsByStringList_t,CEntsByStringHashFuncs,CEntsByStringHashFuncs> *)&emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>::~CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>(this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&emptyMapping.m_ActToSeqHash);
}

} // namespace server
