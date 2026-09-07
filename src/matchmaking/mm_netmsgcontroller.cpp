// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/mm_netmsgcontroller.cpp
// Functions: 9
// ============================================================

#include "matchmaking\mm_netmsgcontroller.h"

//------------------------------------------------------------------------------
// Address: 0x100037D0
// Name: public: virtual struct MM_QOS_t CMatchNetworkMsgControllerBase::GetQOS(void)
// Source: json
//------------------------------------------------------------------------------
MM_QOS_t *__thiscall CMatchNetworkMsgControllerBase::GetQOS(CMatchNetworkMsgControllerBase *this, MM_QOS_t *result)
{
  MM_QOS_t *Qos; // eax
  float flLoss; // edx
  MM_QOS_t v5; // [esp+0h] [ebp-14h] BYREF

  Qos = MM_GetQos(result: &v5);
  flLoss = Qos->flLoss;
  *(_QWORD *)&result->nPingMsMin = *(_QWORD *)&Qos->nPingMsMin;
  *(_QWORD *)&result->flBwUpKbs = *(_QWORD *)&Qos->flBwUpKbs;
  result->flLoss = flLoss;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003810
// Name: public: virtual class KeyValues __near * CMatchNetworkMsgControllerBase::PackageGameDetailsForReservation(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchNetworkMsgControllerBase::PackageGameDetailsForReservation(
        CMatchNetworkMsgControllerBase *this,
        KeyValues *pSettings)
{
  KeyValues *v2; // esi
  IMatchTitleGameSettingsMgr *v3; // eax
  char *ModDirectory; // eax

  v2 = KeyValues::FromString(
         szName: "Settings",
         szStringVal: " System {  network #empty#  access #empty#  }  Options {  server #empty#  }  Members {  numSlots #int#0  numPlayers #int#0  } ",
         ppEndOfParse: nullptr);
  v3 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
  v3->ExtendLobbyDetailsTemplate(this: v3, a2: v2, a3: "reserve", a4: pSettings);
  ModDirectory = COM_GetModDirectory();
  KeyValues::SetName(this: v2, setName: ModDirectory);
  KeyValues::MergeFrom(this: v2, kvMerge: pSettings, eOp: MERGE_KV_BORROW);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10003870
// Name: public: virtual class KeyValues __near * CMatchNetworkMsgControllerBase::GetActiveServerGameDetails(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchNetworkMsgControllerBase::GetActiveServerGameDetails(
        CMatchNetworkMsgControllerBase *this,
        KeyValues *pRequest)
{
  KeyValues *v2; // esi
  IMatchSession *v3; // eax
  KeyValues *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  IMatchTitle *v8; // eax
  unsigned int v9; // eax
  IVEngineClient *m_pIVEngineClient; // esi
  const char *v12; // eax
  KeyValues *v13; // eax
  IMatchTitleGameSettingsMgr *v14; // eax
  INetSupport::ServerInfo_t v15; // [esp+0h] [ebp-34h] BYREF
  unsigned int v16; // [esp+30h] [ebp-4h]

  netadr_s::SetIP(this: (netadr_s *)v15.m_netAdr.ip, unIP: 0);
  netadr_s::SetPort(this: (netadr_s *)v15.m_netAdr.ip, newport: 0);
  netadr_s::SetType(this: (netadr_s *)v15.m_netAdr.ip, newtype: NA_IP);
  netadr_s::SetIP(this: (netadr_s *)v15.m_netAdrOnline.ip, unIP: 0);
  netadr_s::SetPort(this: (netadr_s *)v15.m_netAdrOnline.ip, newport: 0);
  netadr_s::SetType(this: (netadr_s *)v15.m_netAdrOnline.ip, newtype: NA_IP);
  g_pMatchExtensions->m_exts.m_pINetSupport->GetServerInfo(
    this: g_pMatchExtensions->m_exts.m_pINetSupport,
    a2: (INetSupport::ServerInfo_t *)v15.m_netAdr.ip);
  if ( v15.m_bInMainMenuBkgnd )
  {
    v2 = KeyValues::FromString(
           szName: "GameDetailsServer",
           szStringVal: " System {  network LIVE  access public  }  Server {  name =  server =  adronline =  adrlocal =  }  Members { "
           " numSlots #int#0  numPlayers #int#0  } ",
           ppEndOfParse: nullptr);
    if ( !*(&v15.m_bInMainMenuBkgnd + 1) && g_pMatchFramework->GetMatchSession(this: g_pMatchFramework) != nullptr )
    {
      v3 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
      v4 = v3->GetSessionSettings(this: v3);
      KeyValues::MergeFrom(this: v2, kvMerge: v4, eOp: MERGE_KV_BORROW);
    }
    KeyValues::SetString(this: v2, keyName: "Server/name", value: v15.m_szMapName);
    v5 = "dedicated";
    if ( !*(&v15.m_bInMainMenuBkgnd + 1) )
      v5 = "listen";
    KeyValues::SetString(this: v2, keyName: "Server/server", value: v5);
    v6 = netadr_s::ToString(this: (netadr_s *)v15.m_netAdrOnline.ip, baseOnly: false);
    KeyValues::SetString(this: v2, keyName: "Server/adronline", value: v6);
    v7 = netadr_s::ToString(this: (netadr_s *)v15.m_netAdr.ip, baseOnly: false);
    KeyValues::SetString(this: v2, keyName: "Server/adrlocal", value: v7);
    if ( *(&v15.m_bInMainMenuBkgnd + 1) && LOBYTE(v15.m_szServerName) != 0 && BYTE1(v15.m_szServerName) != 0 )
      KeyValues::SetString(this: v2, keyName: "System/access", value: "friends");
    v8 = g_pMMF->GetMatchTitle(this: g_pMMF);
    v9 = v8->GetTotalNumPlayersSupported(this: v8);
    v15.m_numHumanPlayers = (v9 < v15.m_numHumanPlayers ? 0 : v15.m_numHumanPlayers)
                          | v9 & ~((v9 < v15.m_numHumanPlayers) - 1) & ~((v15.m_numHumanPlayers >= 0) - 1);
    KeyValues::SetInt(this: v2, keyName: "Members/numSlots", value: v15.m_numHumanPlayers);
    v16 = v15.m_numHumanPlayers & ~((v15.m_numHumanPlayers < v16) - 1) & ~(((v16 & 0x80000000) == 0) - 1)
        | (v15.m_numHumanPlayers < v16 ? 0 : v16);
    KeyValues::SetInt(this: v2, keyName: "Members/numPlayers", value: v16);
  }
  else
  {
    m_pIVEngineClient = g_pMatchExtensions->m_exts.m_pIVEngineClient;
    if ( m_pIVEngineClient == nullptr )
      return nullptr;
    if ( m_pIVEngineClient->IsLevelMainMenuBackground(this: g_pMatchExtensions->m_exts.m_pIVEngineClient) )
      return nullptr;
    v12 = m_pIVEngineClient->GetLevelNameShort(this: m_pIVEngineClient);
    if ( v12 == nullptr )
      return nullptr;
    if ( *v12 == 0 )
      return nullptr;
    v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v13 == nullptr )
      return nullptr;
    v2 = KeyValues::KeyValues(this: v13, setName: "GameDetailsClient");
  }
  if ( v2 == nullptr )
    return nullptr;
  v14 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
  v14->ExtendServerDetails(this: v14, a2: v2, a3: pRequest);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10003AC0
// Name: protected: void CUtlBuffer::PutTypeBin<int>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<int>(CUtlBuffer *this, unsigned int src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<unsigned int>(
        this: &this->m_Byteswap,
        outputBuffer: (unsigned int *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_DWORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003B20
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003B50
// Name: public: int CUtlBuffer::GetInt(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CUtlBuffer::GetInt(CUtlBuffer *this)
{
  unsigned int dest; // [esp+4h] [ebp-4h] BYREF

  dest = (unsigned int)this;
  if ( (this->m_Flags & 1) != 0 )
  {
    dest = 0;
    CUtlBuffer::Scanf(this, pFmt: "%d", &dest);
  }
  else
  {
    CUtlBuffer::GetTypeBin<unsigned int>(this, &dest);
  }
  return dest;
}

//------------------------------------------------------------------------------
// Address: 0x10003B90
// Name: public: void CUtlBuffer::PutInt(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutInt(CUtlBuffer *this, unsigned int i)
{
  if ( (this->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this, pFmt: "%d", i);
  else
    CUtlBuffer::PutTypeBin<int>(this, src: i);
}

//------------------------------------------------------------------------------
// Address: 0x10003BC0
// Name: public: virtual class KeyValues __near * CMatchNetworkMsgControllerBase::UnpackGameDetailsFromQOS(struct MM_GameDetails_QOS_t const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchNetworkMsgControllerBase::UnpackGameDetailsFromQOS(
        CMatchNetworkMsgControllerBase *this,
        const MM_GameDetails_QOS_t *pvQosReply)
{
  KeyValues *v2; // esi
  const MM_GameDetails_QOS_t *v3; // eax
  KeyValues *v5; // eax
  CUtlBuffer bufQos; // [esp+4h] [ebp-34h] BYREF

  CUtlBuffer::CUtlBuffer(
    this: (CUtlBuffer *)&bufQos.m_Memory.m_nAllocationCount,
    pBuffer: pvQosReply->m_pvData,
    nSize: pvQosReply->m_numDataBytes,
    nFlags: 8);
  CUtlBuffer::ActivateByteSwapping(this: (CUtlBuffer *)&bufQos.m_Memory.m_nAllocationCount, bActivate: true);
  v2 = nullptr;
  if ( (bufQos.m_nTab & 0x100) != 0 )
  {
    pvQosReply = nullptr;
    CUtlBuffer::Scanf(this: (CUtlBuffer *)&bufQos.m_Memory.m_nAllocationCount, pFmt: "%d", &pvQosReply);
  }
  else
  {
    CUtlBuffer::GetTypeBin<unsigned int>(
      this: (CUtlBuffer *)&bufQos.m_Memory.m_nAllocationCount,
      dest: (unsigned int *)&pvQosReply);
  }
  if ( (bufQos.m_nTab & 0x100) != 0 )
  {
    bufQos.m_Memory.m_pMemory = nullptr;
    CUtlBuffer::Scanf(this: (CUtlBuffer *)&bufQos.m_Memory.m_nAllocationCount, pFmt: "%d", &bufQos);
  }
  else
  {
    CUtlBuffer::GetTypeBin<unsigned int>(
      this: (CUtlBuffer *)&bufQos.m_Memory.m_nAllocationCount,
      dest: (unsigned int *)&bufQos);
  }
  v3 = (const MM_GameDetails_QOS_t *)g_pMatchExtensions->m_exts.m_pINetSupport->GetEngineBuildNumber(this: g_pMatchExtensions->m_exts.m_pINetSupport);
  if ( pvQosReply != v3 || bufQos.m_Memory.m_pMemory != nullptr )
  {
    if ( bufQos.m_Get >= 0 && bufQos.m_Memory.m_nAllocationCount != 0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)bufQos.m_Memory.m_nAllocationCount);
    return nullptr;
  }
  else
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v2 = KeyValues::KeyValues(this: v5, setName: str);
    if ( KeyValues::ReadAsBinary(this: v2, buffer: (CUtlBuffer *)&bufQos.m_Memory.m_nAllocationCount) )
    {
      if ( CUtlBuffer::GetInt(this: (CUtlBuffer *)&bufQos.m_Memory.m_nAllocationCount) != 0 )
        DevWarning(a1: "UnpackGameDetailsFromQOS found bad QOS block terminator!\n");
      CUtlBuffer::~CUtlBuffer(this: (CUtlBuffer *)&bufQos.m_Memory.m_nAllocationCount);
      return v2;
    }
    else
    {
      KeyValues::deleteThis(this: v2);
      CUtlBuffer::~CUtlBuffer(this: (CUtlBuffer *)&bufQos.m_Memory.m_nAllocationCount);
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003D00
// Name: public: virtual void CMatchNetworkMsgControllerBase::PackageGameDetailsForQOS(class KeyValues __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchNetworkMsgControllerBase::PackageGameDetailsForQOS(
        CMatchNetworkMsgControllerBase *this,
        KeyValues *pSettings,
        CUtlBuffer *buf)
{
  KeyValues *v3; // edi
  IMatchTitleGameSettingsMgr *v4; // eax
  unsigned int v5; // [esp-4h] [ebp-Ch]

  v3 = KeyValues::FromString(
         szName: "Settings",
         szStringVal: " System {  network #empty#  access #empty#  }  Options {  server #empty#  }  Members {  numSlots #int#0  numPlayers #int#0  } ",
         ppEndOfParse: nullptr);
  v4 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
  v4->ExtendLobbyDetailsTemplate(this: v4, a2: v3, a3: "qos", a4: pSettings);
  KeyValues::MergeFrom(this: v3, kvMerge: pSettings, eOp: MERGE_KV_BORROW);
  v5 = g_pMatchExtensions->m_exts.m_pINetSupport->GetEngineBuildNumber(this: g_pMatchExtensions->m_exts.m_pINetSupport);
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", v5);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: v5);
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: 0);
  KeyValues::WriteAsBinary(this: v3, buffer: buf);
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: 0);
  if ( v3 != nullptr )
    KeyValues::deleteThis(this: v3);
}

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x1001E270
// Name: public: virtual struct MM_QOS_t CMatchNetworkMsgControllerBase::GetQOS(void)
// Source: json
//------------------------------------------------------------------------------
MM_QOS_t *__thiscall CMatchNetworkMsgControllerBase::GetQOS(CMatchNetworkMsgControllerBase *this, MM_QOS_t *result)
{
  MM_QOS_t *Qos; // eax
  float flLoss; // edx
  MM_QOS_t v5; // [esp+0h] [ebp-14h] BYREF

  Qos = MM_GetQos(result: &v5);
  flLoss = Qos->flLoss;
  *(_QWORD *)&result->nPingMsMin = *(_QWORD *)&Qos->nPingMsMin;
  *(_QWORD *)&result->flBwUpKbs = *(_QWORD *)&Qos->flBwUpKbs;
  result->flLoss = flLoss;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001E2B0
// Name: public: virtual class KeyValues __near * CMatchNetworkMsgControllerBase::PackageGameDetailsForReservation(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchNetworkMsgControllerBase::PackageGameDetailsForReservation(
        CMatchNetworkMsgControllerBase *this,
        KeyValues *pSettings)
{
  KeyValues *v2; // esi
  IMatchTitleGameSettingsMgr *v3; // eax
  char *ModDirectory; // eax

  v2 = KeyValues::FromString(
         szName: "settings",
         szStringVal: " system {  network #empty#  access #empty#  netflag #empty#  }  options {  server #empty#  }  members {  numSlo"
         "ts #int#0  numPlayers #int#0  } ",
         ppEndOfParse: nullptr);
  v3 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
  v3->ExtendLobbyDetailsTemplate(this: v3, a2: v2, a3: "reserve", a4: pSettings);
  ModDirectory = COM_GetModDirectory();
  KeyValues::SetName(this: v2, setName: ModDirectory);
  KeyValues::MergeFrom(this: v2, kvMerge: pSettings, eOp: MERGE_KV_BORROW);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1001E310
// Name: public: virtual class KeyValues __near * CMatchNetworkMsgControllerBase::GetActiveServerGameDetails(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchNetworkMsgControllerBase::GetActiveServerGameDetails(
        CMatchNetworkMsgControllerBase *this,
        KeyValues *pRequest)
{
  KeyValues *v2; // esi
  IMatchSession *v3; // eax
  KeyValues *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  IMatchTitle *v8; // eax
  unsigned int v9; // eax
  IVEngineClient *m_pIVEngineClient; // esi
  const char *v12; // eax
  KeyValues *v13; // eax
  IMatchTitleGameSettingsMgr *v14; // eax
  INetSupport::ServerInfo_t v15; // [esp+4h] [ebp-30h] BYREF

  netadr_s::SetIP(this: &v15.m_netAdr, unIP: 0);
  netadr_s::SetPort(this: &v15.m_netAdr, newport: 0);
  netadr_s::SetType(this: &v15.m_netAdr, newtype: NA_IP);
  netadr_s::SetIP(this: &v15.m_netAdrOnline, unIP: 0);
  netadr_s::SetPort(this: &v15.m_netAdrOnline, newport: 0);
  netadr_s::SetType(this: &v15.m_netAdrOnline, newtype: NA_IP);
  g_pMatchExtensions->m_exts.m_pINetSupport->GetServerInfo(this: g_pMatchExtensions->m_exts.m_pINetSupport, a2: &v15);
  if ( v15.m_bActive )
  {
    v2 = KeyValues::FromString(
           szName: "GameDetailsServer",
           szStringVal: " system {  network LIVE  access public  }  server {  name =  server =  adronline =  adrlocal =  }  members { "
           " numSlots #int#0  numPlayers #int#0  } ",
           ppEndOfParse: nullptr);
    if ( !v15.m_bDedicated && g_pMatchFramework->GetMatchSession(this: g_pMatchFramework) != nullptr )
    {
      v3 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
      v4 = v3->GetSessionSettings(this: v3);
      KeyValues::MergeFrom(this: v2, kvMerge: v4, eOp: MERGE_KV_BORROW);
    }
    KeyValues::SetString(this: v2, keyName: "server/name", value: v15.m_szServerName);
    v5 = "dedicated";
    if ( !v15.m_bDedicated )
      v5 = "listen";
    KeyValues::SetString(this: v2, keyName: "server/server", value: v5);
    v6 = netadr_s::ToString(this: &v15.m_netAdrOnline, baseOnly: false);
    KeyValues::SetString(this: v2, keyName: "server/adronline", value: v6);
    v7 = netadr_s::ToString(this: &v15.m_netAdr, baseOnly: false);
    KeyValues::SetString(this: v2, keyName: "server/adrlocal", value: v7);
    if ( v15.m_bDedicated && v15.m_bLobbyExclusive && v15.m_bGroupExclusive )
      KeyValues::SetString(this: v2, keyName: "system/access", value: "friends");
    v8 = g_pMMF->GetMatchTitle(this: g_pMMF);
    v9 = v8->GetTotalNumPlayersSupported(this: v8);
    v15.m_numMaxHumanPlayers = (v9 < v15.m_numMaxHumanPlayers ? 0 : v15.m_numMaxHumanPlayers)
                             | ~((v9 < v15.m_numMaxHumanPlayers) - 1) & ~((v15.m_numMaxHumanPlayers >= 0) - 1) & v9;
    KeyValues::SetInt(this: v2, keyName: "members/numSlots", value: v15.m_numMaxHumanPlayers);
    v15.m_numHumanPlayers = v15.m_numMaxHumanPlayers
                          & ~((v15.m_numMaxHumanPlayers < (unsigned int)v15.m_numHumanPlayers) - 1)
                          & ~((v15.m_numHumanPlayers >= 0) - 1)
                          | (v15.m_numMaxHumanPlayers < (unsigned int)v15.m_numHumanPlayers ? 0 : v15.m_numHumanPlayers);
    KeyValues::SetInt(this: v2, keyName: "members/numPlayers", value: v15.m_numHumanPlayers);
  }
  else
  {
    m_pIVEngineClient = g_pMatchExtensions->m_exts.m_pIVEngineClient;
    if ( m_pIVEngineClient == nullptr )
      return nullptr;
    if ( m_pIVEngineClient->IsLevelMainMenuBackground(this: g_pMatchExtensions->m_exts.m_pIVEngineClient) )
      return nullptr;
    v12 = m_pIVEngineClient->GetLevelNameShort(this: m_pIVEngineClient);
    if ( v12 == nullptr )
      return nullptr;
    if ( *v12 == 0 )
      return nullptr;
    v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v13 == nullptr )
      return nullptr;
    v2 = KeyValues::KeyValues(this: v13, setName: "GameDetailsClient");
  }
  if ( v2 == nullptr )
    return nullptr;
  v14 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
  v14->ExtendServerDetails(this: v14, a2: v2, a3: pRequest);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1001E5D0
// Name: UnpackGameDetailsFromSteamLobbyInKey
// Source: json
//------------------------------------------------------------------------------
void __cdecl UnpackGameDetailsFromSteamLobbyInKey(unsigned __int64 uiLobbyID, const char *szPath, KeyValues *pKey)
{
  KeyValues *i; // esi
  ISteamMatchmaking *m_pSteamMatchmaking; // edi
  const char *Name; // eax
  CFmtStrN<256> *v6; // eax
  const char *v7; // edi
  __int32 v8; // eax
  int v9; // eax
  KeyValues *j; // esi
  const char *v11; // eax
  CFmtStrN<256> *v12; // eax
  CFmtStrN<256> v13; // [esp+Ch] [ebp-10Ch] BYREF

  for ( i = KeyValues::GetFirstValue(this: pKey); i != nullptr; i = KeyValues::GetNextValue(this: i) )
  {
    m_pSteamMatchmaking = steamapicontext->m_pSteamMatchmaking;
    Name = KeyValues::GetName(this: i);
    v6 = CFmtStrN<256>::CFmtStrN<256>(this: &v13, pszFormat: "%s%s", szPath, Name);
    v7 = (const char *)((int (__thiscall *)(ISteamMatchmaking *, _DWORD, _DWORD, char *))m_pSteamMatchmaking->GetLobbyData)(
                         a1: m_pSteamMatchmaking,
                         a2: uiLobbyID,
                         a3: HIDWORD(uiLobbyID),
                         a4: v6->m_szBuf);
    v8 = KeyValues::GetDataType(this: i, keyName: nullptr) - 1;
    if ( v8 != 0 )
    {
      if ( v8 == 1 )
      {
        v9 = atoi(nptr: v7);
        KeyValues::SetInt(this: i, keyName: defaultValue, value: v9);
      }
      else
      {
        DevWarning(a1: "UnpackGameDetailsFromSteamLobby defined unknown type in schema!\n");
      }
    }
    else
    {
      KeyValues::SetString(this: i, keyName: defaultValue, value: v7);
    }
  }
  for ( j = KeyValues::GetFirstTrueSubKey(this: pKey); j != nullptr; j = KeyValues::GetNextTrueSubKey(this: j) )
  {
    v11 = KeyValues::GetName(this: j);
    v12 = CFmtStrN<256>::CFmtStrN<256>(this: &v13, pszFormat: "%s%s:", szPath, v11);
    UnpackGameDetailsFromSteamLobbyInKey(uiLobbyID, szPath: v12->m_szBuf, pKey: j);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E6E0
// Name: public: virtual class KeyValues __near * CMatchNetworkMsgControllerBase::UnpackGameDetailsFromSteamLobby(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchNetworkMsgControllerBase::UnpackGameDetailsFromSteamLobby(
        CMatchNetworkMsgControllerBase *this,
        unsigned __int64 uiLobbyID)
{
  unsigned int i; // ebx
  _BYTE *v3; // eax
  char *v4; // ebx
  IMatchTitleGameSettingsMgr *(__thiscall *GetMatchTitleGameSettingsMgr)(CMatchFramework *); // edx
  int v6; // eax
  KeyValues *Key; // ebx
  unsigned int v8; // esi
  IMatchTitle *v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // esi
  unsigned int v12; // eax
  const char *arrRequiredMetadata[2]; // [esp+Ch] [ebp-8h]

  arrRequiredMetadata[0] = "system:network";
  arrRequiredMetadata[1] = "system:access";
  for ( i = 0; i < 2; ++i )
  {
    v3 = (_BYTE *)((int (__thiscall *)(ISteamMatchmaking *, _DWORD, _DWORD, const char *))steamapicontext->m_pSteamMatchmaking->GetLobbyData)(
                    a1: steamapicontext->m_pSteamMatchmaking,
                    a2: uiLobbyID,
                    a3: HIDWORD(uiLobbyID),
                    a4: arrRequiredMetadata[i]);
    if ( v3 == nullptr || *v3 == 0 )
      return nullptr;
  }
  v4 = (char *)KeyValues::FromString(
                 szName: "settings",
                 szStringVal: " system {  network #empty#  access #empty#  netflag #empty#  }  options {  server #empty#  }  members {"
                 "  numSlots #int#0  numPlayers #int#0  } ",
                 ppEndOfParse: nullptr);
  GetMatchTitleGameSettingsMgr = g_pMMF->GetMatchTitleGameSettingsMgr;
  arrRequiredMetadata[1] = v4;
  v6 = (int)GetMatchTitleGameSettingsMgr(this: g_pMMF);
  (*(void (__thiscall **)(int, char *, const char *, _DWORD))(*(_DWORD *)v6 + 4))(
    a1: v6,
    a2: v4,
    a3: defaultValue,
    a4: 0);
  UnpackGameDetailsFromSteamLobbyInKey(uiLobbyID, szPath: defaultValue, pKey: (KeyValues *)v4);
  Key = KeyValues::FindKey(this: (KeyValues *)v4, keyName: "members", bCreate: true);
  if ( Key != nullptr )
  {
    v8 = ((int (__thiscall *)(ISteamMatchmaking *, _DWORD, _DWORD))steamapicontext->m_pSteamMatchmaking->GetLobbyMemberLimit)(
           a1: steamapicontext->m_pSteamMatchmaking,
           a2: uiLobbyID,
           a3: HIDWORD(uiLobbyID));
    v9 = g_pMMF->GetMatchTitle(this: g_pMMF);
    v10 = v9->GetTotalNumPlayersSupported(this: v9);
    v11 = v10 & ~((v10 < v8) - 1) & ~(((v8 & 0x80000000) == 0) - 1) | (v10 < v8 ? 0 : v8);
    KeyValues::SetInt(this: Key, keyName: "numSlots", value: v11);
    v12 = ((int (__thiscall *)(ISteamMatchmaking *, _DWORD, _DWORD))steamapicontext->m_pSteamMatchmaking->GetNumLobbyMembers)(
            a1: steamapicontext->m_pSteamMatchmaking,
            a2: uiLobbyID,
            a3: HIDWORD(uiLobbyID));
    KeyValues::SetInt(
      this: Key,
      keyName: "numPlayers",
      value: (v11 < v12 ? 0 : v12) | v11 & ~((v11 < v12) - 1) & ~(((v12 & 0x80000000) == 0) - 1));
  }
  return (KeyValues *)arrRequiredMetadata[1];
}

//------------------------------------------------------------------------------
// Address: 0x1001E860
// Name: protected: void CUtlBuffer::PutTypeBin<int>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<int>(CUtlBuffer *this, unsigned int src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) != 0 )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<unsigned int>(
        this: &this->m_Byteswap,
        outputBuffer: (unsigned int *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_DWORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E8D0
// Name: public: int CUtlBuffer::GetInt(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned int *)&i,
          inputBuffer: (unsigned int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtol(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001E970
// Name: public: virtual class KeyValues __near * CMatchNetworkMsgControllerBase::UnpackGameDetailsFromQOS(struct MM_GameDetails_QOS_t const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchNetworkMsgControllerBase::UnpackGameDetailsFromQOS(
        CMatchNetworkMsgControllerBase *this,
        const MM_GameDetails_QOS_t *pvQosReply)
{
  int Int; // esi
  int v3; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  CUtlBuffer bufQos; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(
    this: &bufQos,
    pBuffer: (unsigned __int8 *)pvQosReply->m_pvData,
    nSize: pvQosReply->m_numDataBytes,
    nFlags: 8u);
  CUtlBuffer::ActivateByteSwapping(this: &bufQos, bActivate: true);
  Int = CUtlBuffer::GetInt(this: &bufQos);
  v3 = CUtlBuffer::GetInt(this: &bufQos);
  if ( Int != g_pMatchExtensions->m_exts.m_pINetSupport->GetEngineBuildNumber(this: g_pMatchExtensions->m_exts.m_pINetSupport)
    || v3 != 0 )
  {
    if ( bufQos.m_Memory.m_nGrowSize >= 0 && bufQos.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufQos.m_Memory.m_pMemory);
    return nullptr;
  }
  else
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: defaultValue);
    else
      v6 = nullptr;
    if ( KeyValues::ReadAsBinary(this: v6, buffer: &bufQos) )
    {
      if ( CUtlBuffer::GetInt(this: &bufQos) != 0 )
        DevWarning(a1: "UnpackGameDetailsFromQOS found bad QOS block terminator!\n");
      if ( bufQos.m_Memory.m_nGrowSize >= 0 && bufQos.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufQos.m_Memory.m_pMemory);
      return v6;
    }
    else
    {
      KeyValues::deleteThis(this: v6);
      if ( bufQos.m_Memory.m_nGrowSize >= 0 && bufQos.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufQos.m_Memory.m_pMemory);
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001EA90
// Name: public: virtual void CMatchNetworkMsgControllerBase::PackageGameDetailsForQOS(class KeyValues __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchNetworkMsgControllerBase::PackageGameDetailsForQOS(
        CMatchNetworkMsgControllerBase *this,
        KeyValues *pSettings,
        CUtlBuffer *buf)
{
  KeyValues *v3; // edi
  IMatchTitleGameSettingsMgr *v4; // eax
  unsigned int v5; // [esp-4h] [ebp-Ch]

  v3 = KeyValues::FromString(
         szName: "settings",
         szStringVal: " system {  network #empty#  access #empty#  netflag #empty#  }  options {  server #empty#  }  members {  numSlo"
         "ts #int#0  numPlayers #int#0  } ",
         ppEndOfParse: nullptr);
  v4 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
  v4->ExtendLobbyDetailsTemplate(this: v4, a2: v3, a3: "qos", a4: pSettings);
  KeyValues::MergeFrom(this: v3, kvMerge: pSettings, eOp: MERGE_KV_BORROW);
  v5 = g_pMatchExtensions->m_exts.m_pINetSupport->GetEngineBuildNumber(this: g_pMatchExtensions->m_exts.m_pINetSupport);
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", v5);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: v5);
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: 0);
  KeyValues::WriteAsBinary(this: v3, buffer: buf);
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: 0);
  if ( v3 != nullptr )
    KeyValues::deleteThis(this: v3);
}

} // namespace matchmaking

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x10007430
// Name: public: virtual struct MM_QOS_t CMatchNetworkMsgControllerBase::GetQOS(void)
// Source: json
//------------------------------------------------------------------------------
MM_QOS_t *__thiscall CMatchNetworkMsgControllerBase::GetQOS(CMatchNetworkMsgControllerBase *this, MM_QOS_t *result)
{
  MM_QOS_t *Qos; // eax
  float flLoss; // edx
  MM_QOS_t v5; // [esp+0h] [ebp-14h] BYREF

  Qos = MM_GetQos(result: &v5);
  flLoss = Qos->flLoss;
  *(_QWORD *)&result->nPingMsMin = *(_QWORD *)&Qos->nPingMsMin;
  *(_QWORD *)&result->flBwUpKbs = *(_QWORD *)&Qos->flBwUpKbs;
  result->flLoss = flLoss;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007470
// Name: public: virtual class KeyValues __near * CMatchNetworkMsgControllerBase::PackageGameDetailsForReservation(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchNetworkMsgControllerBase::PackageGameDetailsForReservation(
        CMatchNetworkMsgControllerBase *this,
        KeyValues *pSettings)
{
  KeyValues *v2; // esi
  IMatchTitleGameSettingsMgr *v3; // eax
  char *ModDirectory; // eax

  v2 = KeyValues::FromString(
         szName: "settings",
         szStringVal: " system {  network #empty#  access #empty#  netflag #empty#  }  options {  server #empty#  }  members {  numSlo"
         "ts #int#0  numPlayers #int#0  } ",
         ppEndOfParse: nullptr);
  v3 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
  v3->ExtendLobbyDetailsTemplate(this: v3, a2: v2, a3: "reserve", a4: pSettings);
  ModDirectory = COM_GetModDirectory();
  KeyValues::SetName(this: v2, setName: ModDirectory);
  KeyValues::MergeFrom(this: v2, kvMerge: pSettings, eOp: MERGE_KV_BORROW);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100074D0
// Name: public: virtual class KeyValues __near * CMatchNetworkMsgControllerBase::GetActiveServerGameDetails(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchNetworkMsgControllerBase::GetActiveServerGameDetails(
        CMatchNetworkMsgControllerBase *this,
        KeyValues *pRequest)
{
  KeyValues *v2; // esi
  IMatchSession *v3; // eax
  KeyValues *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  IMatchTitle *v8; // eax
  unsigned int v9; // eax
  IVEngineClient *m_pIVEngineClient; // esi
  const char *v12; // eax
  KeyValues *v13; // eax
  IMatchTitleGameSettingsMgr *v14; // eax
  INetSupport::ServerInfo_t v15; // [esp+4h] [ebp-30h] BYREF

  netadr_s::SetIP(this: &v15.m_netAdr, unIP: 0);
  netadr_s::SetPort(this: &v15.m_netAdr, newport: 0);
  netadr_s::SetType(this: &v15.m_netAdr, newtype: NA_IP);
  netadr_s::SetIP(this: &v15.m_netAdrOnline, unIP: 0);
  netadr_s::SetPort(this: &v15.m_netAdrOnline, newport: 0);
  netadr_s::SetType(this: &v15.m_netAdrOnline, newtype: NA_IP);
  g_pMatchExtensions->m_exts.m_pINetSupport->GetServerInfo(this: g_pMatchExtensions->m_exts.m_pINetSupport, a2: &v15);
  if ( v15.m_bActive )
  {
    v2 = KeyValues::FromString(
           szName: "GameDetailsServer",
           szStringVal: " system {  network LIVE  access public  }  server {  name =  server =  adronline =  adrlocal =  }  members { "
           " numSlots #int#0  numPlayers #int#0  } ",
           ppEndOfParse: nullptr);
    if ( !v15.m_bDedicated && g_pMatchFramework->GetMatchSession(this: g_pMatchFramework) != nullptr )
    {
      v3 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
      v4 = v3->GetSessionSettings(this: v3);
      KeyValues::MergeFrom(this: v2, kvMerge: v4, eOp: MERGE_KV_BORROW);
    }
    KeyValues::SetString(this: v2, keyName: "server/name", value: v15.m_szServerName);
    v5 = "dedicated";
    if ( !v15.m_bDedicated )
      v5 = "listen";
    KeyValues::SetString(this: v2, keyName: "server/server", value: v5);
    v6 = netadr_s::ToString(this: &v15.m_netAdrOnline, baseOnly: false);
    KeyValues::SetString(this: v2, keyName: "server/adronline", value: v6);
    v7 = netadr_s::ToString(this: &v15.m_netAdr, baseOnly: false);
    KeyValues::SetString(this: v2, keyName: "server/adrlocal", value: v7);
    if ( v15.m_bDedicated && v15.m_bLobbyExclusive && v15.m_bGroupExclusive )
      KeyValues::SetString(this: v2, keyName: "system/access", value: "friends");
    v8 = g_pMMF->GetMatchTitle(this: g_pMMF);
    v9 = v8->GetTotalNumPlayersSupported(this: v8);
    v15.m_numMaxHumanPlayers = (v9 < v15.m_numMaxHumanPlayers ? 0 : v15.m_numMaxHumanPlayers)
                             | ~((v9 < v15.m_numMaxHumanPlayers) - 1) & ~((v15.m_numMaxHumanPlayers >= 0) - 1) & v9;
    KeyValues::SetInt(this: v2, keyName: "members/numSlots", value: v15.m_numMaxHumanPlayers);
    v15.m_numHumanPlayers = v15.m_numMaxHumanPlayers
                          & ~((v15.m_numMaxHumanPlayers < (unsigned int)v15.m_numHumanPlayers) - 1)
                          & ~((v15.m_numHumanPlayers >= 0) - 1)
                          | (v15.m_numMaxHumanPlayers < (unsigned int)v15.m_numHumanPlayers ? 0 : v15.m_numHumanPlayers);
    KeyValues::SetInt(this: v2, keyName: "members/numPlayers", value: v15.m_numHumanPlayers);
  }
  else
  {
    m_pIVEngineClient = g_pMatchExtensions->m_exts.m_pIVEngineClient;
    if ( m_pIVEngineClient == nullptr )
      return nullptr;
    if ( m_pIVEngineClient->IsLevelMainMenuBackground(this: g_pMatchExtensions->m_exts.m_pIVEngineClient) )
      return nullptr;
    v12 = m_pIVEngineClient->GetLevelNameShort(this: m_pIVEngineClient);
    if ( v12 == nullptr )
      return nullptr;
    if ( *v12 == 0 )
      return nullptr;
    v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v13 == nullptr )
      return nullptr;
    v2 = KeyValues::KeyValues(this: v13, setName: "GameDetailsClient");
  }
  if ( v2 == nullptr )
    return nullptr;
  v14 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
  v14->ExtendServerDetails(this: v14, a2: v2, a3: pRequest);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10007790
// Name: protected: void CUtlBuffer::PutTypeBin<int>(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::PutTypeBin<int>(CUtlBuffer *this, unsigned int src)
{
  if ( CUtlBuffer::CheckPut(this, nSize: 4) )
  {
    if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      CByteswap::SwapBufferToTargetEndian<unsigned int>(
        this: &this->m_Byteswap,
        outputBuffer: (unsigned int *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset],
        inputBuffer: &src,
        count: 1);
    else
      *(_DWORD *)&this->m_Memory.m_pMemory[this->m_Put - this->m_nOffset] = src;
    this->m_Put += 4;
    CUtlBuffer::AddNullTermination(this, nPut: this->m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007800
// Name: public: CUtlBuffer::~CUtlBuffer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::~CUtlBuffer(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10007830
// Name: public: int CUtlBuffer::GetInt(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetInt(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 4) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned int>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned int *)&i,
          inputBuffer: (unsigned int *)&v2[this->m_Get],
          count: 1);
        this->m_Get += 4;
        return i;
      }
      else
      {
        result = *(_DWORD *)&v2[this->m_Get];
        this->m_Get += 4;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = strtol(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100078D0
// Name: public: virtual class KeyValues __near * CMatchNetworkMsgControllerBase::UnpackGameDetailsFromQOS(struct MM_GameDetails_QOS_t const __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchNetworkMsgControllerBase::UnpackGameDetailsFromQOS(
        CMatchNetworkMsgControllerBase *this,
        const MM_GameDetails_QOS_t *pvQosReply)
{
  int Int; // esi
  int v3; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  CUtlBuffer bufQos; // [esp+8h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &bufQos, pBuffer: pvQosReply->m_pvData, nSize: pvQosReply->m_numDataBytes, nFlags: 8);
  CUtlBuffer::ActivateByteSwapping(this: &bufQos, bActivate: true);
  Int = CUtlBuffer::GetInt(this: &bufQos);
  v3 = CUtlBuffer::GetInt(this: &bufQos);
  if ( Int != g_pMatchExtensions->m_exts.m_pINetSupport->GetEngineBuildNumber(this: g_pMatchExtensions->m_exts.m_pINetSupport)
    || v3 != 0 )
  {
    if ( bufQos.m_Memory.m_nGrowSize >= 0 && bufQos.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufQos.m_Memory.m_pMemory);
    return nullptr;
  }
  else
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: str);
    else
      v6 = nullptr;
    if ( KeyValues::ReadAsBinary(this: v6, buffer: &bufQos) )
    {
      if ( CUtlBuffer::GetInt(this: &bufQos) != 0 )
        DevWarning(a1: "UnpackGameDetailsFromQOS found bad QOS block terminator!\n");
      if ( bufQos.m_Memory.m_nGrowSize >= 0 && bufQos.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufQos.m_Memory.m_pMemory);
      return v6;
    }
    else
    {
      KeyValues::deleteThis(this: v6);
      if ( bufQos.m_Memory.m_nGrowSize >= 0 && bufQos.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufQos.m_Memory.m_pMemory);
      return nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100079F0
// Name: public: virtual void CMatchNetworkMsgControllerBase::PackageGameDetailsForQOS(class KeyValues __near *,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchNetworkMsgControllerBase::PackageGameDetailsForQOS(
        CMatchNetworkMsgControllerBase *this,
        KeyValues *pSettings,
        CUtlBuffer *buf)
{
  KeyValues *v3; // edi
  IMatchTitleGameSettingsMgr *v4; // eax
  unsigned int v5; // [esp-4h] [ebp-Ch]

  v3 = KeyValues::FromString(
         szName: "settings",
         szStringVal: " system {  network #empty#  access #empty#  netflag #empty#  }  options {  server #empty#  }  members {  numSlo"
         "ts #int#0  numPlayers #int#0  } ",
         ppEndOfParse: nullptr);
  v4 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
  v4->ExtendLobbyDetailsTemplate(this: v4, a2: v3, a3: "qos", a4: pSettings);
  KeyValues::MergeFrom(this: v3, kvMerge: pSettings, eOp: MERGE_KV_BORROW);
  v5 = g_pMatchExtensions->m_exts.m_pINetSupport->GetEngineBuildNumber(this: g_pMatchExtensions->m_exts.m_pINetSupport);
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", v5);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: v5);
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: 0);
  KeyValues::WriteAsBinary(this: v3, buffer: buf);
  if ( (buf->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: buf, pFmt: "%d", 0);
  else
    CUtlBuffer::PutTypeBin<int>(this: buf, src: 0);
  if ( v3 != nullptr )
    KeyValues::deleteThis(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1000A950
// Name: protected: bool CUtlBuffer::GetTypeText<__int64>(__int64 __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::GetTypeText<__int64>(CUtlBuffer *this, __int64 *value, int nRadix)
{
  char *v5; // esi
  __int64 v6; // rax
  bool v7; // zf
  char *v8; // eax
  int nLength; // [esp+4h] [ebp-8h] BYREF
  char *pEnd; // [esp+8h] [ebp-4h] BYREF

  nLength = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &nLength) )
  {
    *value = 0;
    return 0;
  }
  pEnd = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v5 = pEnd;
  v6 = _strtoi64(nptr: pEnd, endptr: &pEnd, ibase: nRadix);
  *(_DWORD *)value = v6;
  v8 = (char *)(pEnd - v5);
  v7 = pEnd == v5;
  *((_DWORD *)value + 1) = HIDWORD(v6);
  if ( v7 )
    return 0;
  this->m_Get += (int)v8;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000AA40
// Name: public: void CByteswap::SwapBufferToTargetEndian<unsigned short>(unsigned short __near *,unsigned short __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CByteswap::SwapBufferToTargetEndian<unsigned short>(
        CByteswap *this,
        unsigned __int8 *outputBuffer,
        unsigned __int8 *inputBuffer,
        int count)
{
  int v4; // ebx
  unsigned __int8 *v5; // esi
  int v6; // edi
  unsigned __int8 v7; // dl
  unsigned __int8 v8; // cl

  v4 = count;
  if ( count > 0 && outputBuffer != nullptr )
  {
    v5 = inputBuffer;
    if ( inputBuffer == nullptr )
      v5 = outputBuffer;
    if ( (*(_BYTE *)this & 1) != 0 )
    {
      v6 = outputBuffer - v5;
      do
      {
        v7 = v5[1];
        count = *(unsigned __int16 *)&v5[v6];
        v8 = *v5;
        LOBYTE(count) = v7;
        BYTE1(count) = v8;
        _V_memcpy(dest: &v5[v6], src: &count, count: 2);
        v5 += 2;
        --v4;
      }
      while ( v4 != 0 );
    }
    else if ( v5 != nullptr && outputBuffer != v5 )
    {
      memcpy(dst: outputBuffer, src: v5, count: 2 * count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B6D0
// Name: protected: void CUtlBuffer::GetTypeBin<char>(char __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetTypeBin<char>(CUtlBuffer *this, char *dest)
{
  if ( CUtlBuffer::CheckGet(this, nSize: 1) )
  {
    *dest = this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
    ++this->m_Get;
  }
  else
  {
    *dest = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BAD0
// Name: public: unsigned short CUtlBuffer::GetUnsignedShort(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlBuffer::GetUnsignedShort(CUtlBuffer *this)
{
  unsigned __int8 *v2; // eax
  int result; // eax
  char *v4; // edi
  int nIncrement; // [esp+4h] [ebp-Ch] BYREF
  int s; // [esp+8h] [ebp-8h] BYREF
  char *endptr; // [esp+Ch] [ebp-4h] BYREF

  if ( (this->m_Flags & 1) == 0 )
  {
    if ( CUtlBuffer::CheckGet(this, nSize: 2) )
    {
      v2 = &this->m_Memory.m_pMemory[-this->m_nOffset];
      if ( (*(_BYTE *)&this->m_Byteswap & 1) != 0 )
      {
        CByteswap::SwapBufferToTargetEndian<unsigned short>(
          this: &this->m_Byteswap,
          outputBuffer: (unsigned __int8 *)&s,
          inputBuffer: &v2[this->m_Get],
          count: 1);
        this->m_Get += 2;
        return s;
      }
      else
      {
        result = *(unsigned __int16 *)&v2[this->m_Get];
        this->m_Get += 2;
      }
      return result;
    }
    return 0;
  }
  nIncrement = 128;
  if ( !CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, &nIncrement) )
    return 0;
  endptr = (char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  v4 = endptr;
  result = (unsigned __int16)strtoul(nptr: endptr, &endptr, ibase: 10);
  if ( endptr != v4 )
    this->m_Get += endptr - v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F9D0
// Name: public: void const __near * CUtlBuffer::PeekGet(int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CUtlBuffer::PeekGet(CUtlBuffer *this, int nMaxSize, int nOffset)
{
  bool v4; // al

  if ( (this->m_Error & 2) == 0
    && (v4 = CUtlBuffer::CheckGet(this, nSize: nOffset + nMaxSize), this->m_Error &= ~2u, v4) )
  {
    return &this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset + nOffset];
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FA10
// Name: public: void CUtlBuffer::SeekGet(enum CUtlBuffer::SeekType_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::SeekGet(CUtlBuffer *this, CUtlBuffer::SeekType_t type, int offset)
{
  int v3; // eax
  int m_Get; // eax
  int m_nOffset; // edx

  if ( type != SEEK_HEAD )
  {
    if ( type == SEEK_CURRENT )
    {
      this->m_Get += offset;
      goto LABEL_8;
    }
    if ( type != SEEK_TAIL )
      goto LABEL_8;
    v3 = this->m_nMaxPut - offset;
  }
  else
  {
    v3 = offset;
  }
  this->m_Get = v3;
LABEL_8:
  m_Get = this->m_Get;
  if ( m_Get <= this->m_nMaxPut )
  {
    m_nOffset = this->m_nOffset;
    this->m_Error &= ~2u;
    if ( m_Get < m_nOffset || m_Get >= m_nOffset + this->m_Memory.m_nAllocationCount )
      ((void (__stdcall *)(int))this->m_GetOverflowFunc)(a1: -1);
  }
  else
  {
    this->m_Error |= 2u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FE20
// Name: protected: bool CUtlBuffer::PeekStringMatch(int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlBuffer::PeekStringMatch(CUtlBuffer *this, int nOffset, const char *pString, int nLen)
{
  bool v5; // al
  bool result; // al

  result = (this->m_Error & 2) == 0
        && (v5 = CUtlBuffer::CheckGet(this, nSize: nOffset + nLen), this->m_Error &= ~2u, v5)
        && V_strncmp(
             s1: (const char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset + nOffset],
             s2: pString,
             count: nLen) == 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010270
// Name: public: void CUtlBuffer::SetExternalBuffer(void __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::SetExternalBuffer(
        CUtlBuffer *this,
        unsigned __int8 *pMemory,
        int nSize,
        int nInitialPut,
        unsigned __int8 nFlags)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  this->m_Memory.m_pMemory = pMemory;
  this->m_Memory.m_nAllocationCount = nSize;
  this->m_Memory.m_nGrowSize = -1;
  this->m_Get = 0;
  this->m_Put = nInitialPut;
  this->m_nTab = 0;
  this->m_Error = 0;
  this->m_nOffset = 0;
  this->m_Flags = nFlags;
  this->m_nMaxPut = -1;
  if ( nInitialPut > -1 )
  {
    if ( (nFlags & 8) == 0 )
    {
      if ( CUtlBuffer::CheckPut(this, nSize: 1) )
      {
        this->m_Memory.m_pMemory[nInitialPut - this->m_nOffset] = 0;
        this->m_nMaxPut = nInitialPut;
        return;
      }
      this->m_Error &= ~1u;
    }
    this->m_nMaxPut = nInitialPut;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010300
// Name: public: bool CUtlBuffer::EatCPPComment(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlBuffer::EatCPPComment(CUtlBuffer *this)
{
  bool v2; // al
  unsigned __int8 *v3; // eax
  char i; // al
  char dest; // [esp+7h] [ebp-1h] BYREF

  if ( (this->m_Flags & 1) == 0 )
    return 0;
  if ( this->m_Error != 0 )
    return 0;
  v2 = CUtlBuffer::CheckGet(this, nSize: 2);
  this->m_Error &= ~2u;
  if ( !v2 )
    return 0;
  v3 = &this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset];
  if ( v3 == nullptr || *v3 != 47 || v3[1] != 47 )
    return 0;
  this->m_Get += 2;
  CUtlBuffer::GetTypeBin<char>(this, &dest);
  for ( i = dest; this->m_Error == 0; i = dest )
  {
    if ( i == 10 )
      break;
    CUtlBuffer::GetTypeBin<char>(this, &dest);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10010490
// Name: protected: char CUtlBuffer::GetDelimitedCharInternal(class CUtlCharConversion __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CUtlBuffer::GetDelimitedCharInternal(CUtlBuffer *this, int pConv)
{
  CUtlCharConversion *v3; // edi
  char v4; // bl
  bool result; // al
  int m_Get; // eax
  int m_nOffset; // ecx
  char dest; // [esp+Fh] [ebp-1h] BYREF

  CUtlBuffer::GetTypeBin<char>(this, &dest);
  v3 = (CUtlCharConversion *)pConv;
  v4 = dest;
  if ( dest == *(_BYTE *)(pConv + 4) )
  {
    pConv = *(_DWORD *)(pConv + 20);
    result = CUtlBuffer::CheckArbitraryPeekGet(this, nOffset: 0, nIncrement: &pConv);
    if ( !result )
      return result;
    v4 = v3->FindConversion(
           this: v3,
           a2: (const char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset],
           a3: &pConv);
    this->m_Get += pConv;
    m_Get = this->m_Get;
    if ( m_Get > this->m_nMaxPut )
    {
      this->m_Error |= 2u;
      return v4;
    }
    m_nOffset = this->m_nOffset;
    this->m_Error &= ~2u;
    if ( m_Get < m_nOffset || m_Get >= m_nOffset + this->m_Memory.m_nAllocationCount )
      this->m_GetOverflowFunc(this, a2: -1);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10010530
// Name: public: void CUtlBuffer::GetDelimitedString(class CUtlCharConversion __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBuffer::GetDelimitedString(
        CUtlBuffer *this,
        CUtlCharConversion *pConv,
        char *pString,
        int nMaxChars)
{
  int m_Get; // eax
  int m_nOffset; // ecx
  int m_nDelimiterLength; // edi
  bool v9; // al
  bool DelimitedCharInternal; // al
  int v11; // eax
  int v12; // ecx
  char *s2; // [esp+8h] [ebp-4h]
  int nRead; // [esp+14h] [ebp+8h]

  if ( (this->m_Flags & 1) != 0 && pConv != nullptr )
  {
    if ( this->m_Error != 0 )
    {
      *pString = 0;
    }
    else
    {
      if ( nMaxChars == 0 )
        nMaxChars = 0x7FFFFFFF;
      CUtlBuffer::EatWhiteSpace(this);
      if ( CUtlBuffer::PeekStringMatch(this, nOffset: 0, pString: pConv->m_pDelimiter, nLen: pConv->m_nDelimiterLength) )
      {
        this->m_Get += pConv->m_nDelimiterLength;
        m_Get = this->m_Get;
        if ( m_Get <= this->m_nMaxPut )
        {
          m_nOffset = this->m_nOffset;
          this->m_Error &= ~2u;
          if ( m_Get < m_nOffset || m_Get >= m_nOffset + this->m_Memory.m_nAllocationCount )
            this->m_GetOverflowFunc(this, a2: -1);
        }
        else
        {
          this->m_Error |= 2u;
        }
        nRead = 0;
        if ( this->m_Error == 0 )
        {
          while ( 1 )
          {
            m_nDelimiterLength = pConv->m_nDelimiterLength;
            s2 = (char *)pConv->m_pDelimiter;
            if ( (this->m_Error & 2) == 0 )
            {
              v9 = CUtlBuffer::CheckGet(this, nSize: m_nDelimiterLength);
              this->m_Error &= ~2u;
              if ( v9
                && V_strncmp(
                     s1: (const char *)&this->m_Memory.m_pMemory[this->m_Get - this->m_nOffset],
                     s2,
                     count: m_nDelimiterLength) == 0 )
              {
                break;
              }
            }
            DelimitedCharInternal = CUtlBuffer::GetDelimitedCharInternal(this, (int)pConv);
            if ( nRead < nMaxChars )
              pString[nRead++] = DelimitedCharInternal;
            if ( this->m_Error != 0 )
              goto LABEL_26;
          }
          this->m_Get += pConv->m_nDelimiterLength;
          v11 = this->m_Get;
          if ( v11 <= this->m_nMaxPut )
          {
            v12 = this->m_nOffset;
            this->m_Error &= ~2u;
            if ( v11 < v12 || v11 >= v12 + this->m_Memory.m_nAllocationCount )
              this->m_GetOverflowFunc(this, a2: -1);
          }
          else
          {
            this->m_Error |= 2u;
          }
        }
LABEL_26:
        if ( nRead >= nMaxChars )
          nRead = nMaxChars - 1;
        pString[nRead] = 0;
      }
    }
  }
  else
  {
    CUtlBuffer::GetString(this, pString, nMaxChars);
  }
}

} // namespace matchmaking_ds
