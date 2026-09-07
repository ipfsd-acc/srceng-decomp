// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/uigamedata.cpp
// Functions: 13
// ============================================================

#include "game\client\cstrike15\gameui\uigamedata.h"

//------------------------------------------------------------------------------
// Address: 0x10001380
// Name: public: void CCallback<class CAchievementMgr,struct UserStatsStored_t,0>::Register(class CAchievementMgr __near *,void (CAchievementMgr::*)(struct UserStatsStored_t __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CAchievementMgr,UserStatsStored_t,0>::Register(
        CCallback<CAchievementMgr,UserStatsStored_t,0> *this,
        CAchievementMgr *pObj,
        __int128 func)
{
  __int64 v4; // xmm0_8

  if ( pObj != nullptr && (_DWORD)func != 0 )
  {
    if ( (this->m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: this);
    *(_QWORD *)&this->m_Func = func;
    v4 = *((_QWORD *)&func + 1);
    this->m_pObj = pObj;
    *((_QWORD *)&this->m_Func + 1) = v4;
    _SteamAPI_RegisterCallback(a1: this, a2: 1102);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10172680
// Name: private: virtual void CCallback<class CAchievementMgr,struct UserStatsStored_t,0>::Run(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CAchievementMgr,UserStatsStored_t,0>::Run(
        CCallback<CAchievementMgr,UserStatsStored_t,0> *this,
        void *pvParam)
{
  ((void (__thiscall *)(char *, void *))LODWORD(this->m_Func))(
    a1: (char *)this->m_pObj + DWORD1(this->m_Func),
    a2: pvParam);
}

//------------------------------------------------------------------------------
// Address: 0x101726A0
// Name: private: virtual void CCallback<class CSteamWorksGameStatsUploader,struct GameStatsSessionClosed_t,0>::Run(void __near *,bool,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CSteamWorksGameStatsUploader,GameStatsSessionClosed_t,0>::Run(
        CCallback<CAchievementMgr,UserStatsStored_t,0> *this,
        void *pvParam,
        bool __formal,
        unsigned __int64 a4)
{
  ((void (__thiscall *)(char *, void *))LODWORD(this->m_Func))(
    a1: (char *)this->m_pObj + DWORD1(this->m_Func),
    a2: pvParam);
}

//------------------------------------------------------------------------------
// Address: 0x101AE9A0
// Name: private: virtual int CCallback<class CAchievement_Meta,struct UserAchievementStored_t,0>::GetCallbackSizeBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCallback<CAchievement_Meta,UserAchievementStored_t,0>::GetCallbackSizeBytes(
        CCallback<CAchievement_Meta,UserAchievementStored_t,0> *this)
{
  return 152;
}

//------------------------------------------------------------------------------
// Address: 0x101AE9B0
// Name: public: void CCallback<class CAchievement_Meta,struct UserAchievementStored_t,0>::Register(class CAchievement_Meta __near *,void (CAchievement_Meta::*)(struct UserAchievementStored_t __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CAchievement_Meta,UserAchievementStored_t,0>::Register(
        CCallback<CAchievement_Meta,UserAchievementStored_t,0> *this,
        CAchievement_Meta *pObj,
        __int128 func)
{
  __int64 v4; // xmm0_8

  if ( pObj != nullptr && (_DWORD)func != 0 )
  {
    if ( (this->m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: this);
    *(_QWORD *)&this->m_Func = func;
    v4 = *((_QWORD *)&func + 1);
    this->m_pObj = pObj;
    *((_QWORD *)&this->m_Func + 1) = v4;
    _SteamAPI_RegisterCallback(a1: this, a2: 1103);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E85D0
// Name: public: static bool CDefOps<unsigned __int64>::LessFunc(unsigned __int64 const __near &,unsigned __int64 const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<unsigned __int64>::LessFunc(const unsigned __int64 *lhs, const unsigned __int64 *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x101E8600
// Name: public: void CCallback<class BaseModUI::CUIGameData,struct PersonaStateChange_t,0>::Register(class BaseModUI::CUIGameData __near *,void (BaseModUI::CUIGameData::*)(struct PersonaStateChange_t __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<BaseModUI::CUIGameData,PersonaStateChange_t,0>::Register(
        CCallback<BaseModUI::CUIGameData,PersonaStateChange_t,0> *this,
        BaseModUI::CUIGameData *pObj,
        __int128 func)
{
  __int64 v4; // xmm0_8

  if ( pObj != nullptr && (_DWORD)func != 0 )
  {
    if ( (this->m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: this);
    *(_QWORD *)&this->m_Func = func;
    v4 = *((_QWORD *)&func + 1);
    this->m_pObj = pObj;
    *((_QWORD *)&this->m_Func + 1) = v4;
    _SteamAPI_RegisterCallback(a1: this, a2: 304);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E8760
// Name: public: virtual void BaseModUI::CUIGameData::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall BaseModUI::CUIGameData::OnEvent(BaseModUI::CUIGameData *this, KeyValues *pEvent)
{
  const char *Name; // edi
  char *String; // eax
  char *v6; // eax
  _DWORD *Ptr; // eax
  char *v8; // eax
  char *v9; // eax
  char *v10; // eax
  int v11; // edi
  char *v12; // eax
  char *v13; // eax
  char *v14; // edi
  char *v15; // eax
  char *v16; // eax
  const char *v17; // edi
  char *v18; // eax
  int v19; // edi
  KeyValues *v20; // eax
  KeyValues *v21; // edi
  IBaseFileSystem *v22; // eax
  CFmtStrN<256> *v23; // eax
  char *v24; // eax
  char *v25; // eax
  bool v26; // zf
  const char *v27; // eax
  CFmtStrN<256> *v28; // eax
  const wchar_t *v29; // edi
  const char *v30; // eax
  CFmtStrN<256> *v31; // eax
  const wchar_t *v32; // esi
  unsigned int v33; // eax
  void *v34; // esp
  CFmtStrN<256> *v35; // eax
  wchar_t v36[6]; // [esp+0h] [ebp-44Ch] BYREF
  CFmtStrN<256> v37; // [esp+Ch] [ebp-440h] BYREF
  CFmtStrN<256> v38; // [esp+118h] [ebp-334h] BYREF
  char chErrorTitleBuffer[128]; // [esp+224h] [ebp-228h] BYREF
  CFmtStrN<256> strLocKey; // [esp+2A4h] [ebp-1A8h] BYREF
  _BYTE pDest[128]; // [esp+3B0h] [ebp-9Ch] OVERLAPPED BYREF
  unsigned int v42; // [esp+430h] [ebp-1Ch]
  const wchar_t *wszLine1; // [esp+434h] [ebp-18h]
  unsigned __int64 autodelete_kvDlcDetails; // [esp+438h] [ebp-14h] OVERLAPPED
  unsigned __int64 uiDlcOfferID; // [esp+440h] [ebp-Ch] BYREF
  KeyValues *kvDlcDetails; // [esp+448h] [ebp-4h]
  char iDlcRequireda; // [esp+454h] [ebp+8h]
  int iDlcRequired; // [esp+454h] [ebp+8h]

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: "OnSysXUIEvent", s2: Name) == 0 )
  {
    String = KeyValues::GetString(this: pEvent, keyName: "action", defaultValue: prType);
    this->m_bXUIOpen = _V_stricmp(s1: "opening", s2: String) == 0;
    return;
  }
  if ( _V_stricmp(s1: "OnProfileUnavailable", s2: Name) != 0 )
  {
    if ( _V_stricmp(s1: "OnInvite", s2: Name) == 0 )
    {
      v6 = KeyValues::GetString(this: pEvent, keyName: "action", defaultValue: prType);
      if ( _V_stricmp(s1: "accepted", s2: v6) != 0 )
      {
        v8 = KeyValues::GetString(this: pEvent, keyName: "action", defaultValue: prType);
        if ( _V_stricmp(s1: "storage", s2: v8) != 0 )
        {
          v9 = KeyValues::GetString(this: pEvent, keyName: "action", defaultValue: prType);
          if ( _V_stricmp(s1: "error", s2: v9) == 0 )
          {
            v10 = KeyValues::GetString(this: pEvent, keyName: "error", defaultValue: prType);
            *(_DWORD *)&pDest[68] = prType;
            *(_DWORD *)&pDest[72] = "#InviteError_Unknown";
            *(_DWORD *)&pDest[76] = 0;
            *(_DWORD *)&pDest[80] = "NotOnline";
            *(_DWORD *)&pDest[84] = "#InviteError_NotOnline1";
            *(_DWORD *)&pDest[88] = 0;
            *(_DWORD *)&pDest[92] = "NoMultiplayer";
            *(_DWORD *)&pDest[96] = "#InviteError_NoMultiplayer1";
            *(_DWORD *)&pDest[100] = 0;
            *(_DWORD *)&pDest[104] = "SameConsole";
            *(_DWORD *)&pDest[108] = "#InviteError_SameConsole1";
            memset(&pDest[112], 0, 16);
            RemapText_t::RemapRawText(a1: nullptr, pRemapTable: (RemapText_t *)&pDest[68], szRawText: v10);
          }
        }
      }
      else if ( g_pMatchFramework->GetMatchSession(this: g_pMatchFramework) != nullptr )
      {
        Ptr = KeyValues::GetPtr(this: pEvent, keyName: "confirmed", defaultValue: nullptr);
        if ( Ptr != nullptr )
          *Ptr = 0;
      }
      return;
    }
    if ( _V_stricmp(s1: "OnSysStorageDevicesChanged", s2: Name) == 0 )
    {
      if ( this->m_pSelectStorageClient != nullptr )
        DevWarning(a1: "Ignored OnSysStorageDevicesChanged while the storage selection was in progress...\n");
      return;
    }
    if ( _V_stricmp(s1: "OnSysInputDevicesChanged", s2: Name) == 0 )
    {
      v11 = engine->GetActiveSplitScreenPlayerSlot(this: engine);
      iDlcRequireda = KeyValues::GetInt(this: pEvent, keyName: "mask", defaultValue: 0);
      engine->SetActiveSplitScreenPlayerSlot(this: engine, a2: 0);
      if ( (iDlcRequireda & 1) != 0 )
        engine->ClientCmd(this: engine, a2: "go_away_from_keyboard");
      engine->SetActiveSplitScreenPlayerSlot(this: engine, a2: v11);
      return;
    }
    if ( _V_stricmp(s1: "OnMatchPlayerMgrReset", s2: Name) == 0 )
    {
      v12 = KeyValues::GetString(this: pEvent, keyName: "reason", defaultValue: prType);
      if ( _V_stricmp(s1: v12, s2: "GuestSignedIn") == 0 )
      {
        v13 = KeyValues::GetString(this: pEvent, keyName: "settings/game/state", defaultValue: "lobby");
        _V_stricmp(s1: "lobby", s2: v13);
      }
LABEL_25:
      engine->HideLoadingPlaque(this: engine);
      return;
    }
    if ( _V_stricmp(s1: "OnEngineDisconnectReason", s2: Name) == 0 )
    {
      v14 = KeyValues::GetString(this: pEvent, keyName: "reason", defaultValue: prType);
      if ( KeyValues::GetString(this: pEvent, keyName: "disconnecthdlr", defaultValue: nullptr) != nullptr )
        return;
      *(_DWORD *)&pDest[72] = "#SessionError_Kicked";
      *(_DWORD *)&pDest[84] = "#SessionError_Kicked";
      *(_DWORD *)&pDest[96] = "#SessionError_Kicked";
      *(_DWORD *)&pDest[20] = prType;
      *(_DWORD *)&pDest[24] = "#DisconnectReason_Unknown";
      *(_DWORD *)&pDest[28] = 0;
      *(_DWORD *)&pDest[32] = "Lost connection to LIVE";
      *(_DWORD *)&pDest[36] = "#DisconnectReason_LostConnectionToLIVE";
      *(_DWORD *)&pDest[40] = 0;
      *(_DWORD *)&pDest[44] = "Player removed from host session";
      *(_DWORD *)&pDest[48] = "#DisconnectReason_PlayerRemovedFromSession";
      *(_DWORD *)&pDest[52] = 1;
      *(_DWORD *)&pDest[56] = "Connection to server timed out";
      *(_DWORD *)&pDest[60] = "#L4D360UI_MsgBx_DisconnectedFromServer";
      *(_DWORD *)&pDest[64] = 1;
      *(_DWORD *)&pDest[68] = "Added to banned list";
      *(_DWORD *)&pDest[76] = 1;
      *(_DWORD *)&pDest[80] = "Kicked and banned";
      *(_DWORD *)&pDest[88] = 1;
      *(_DWORD *)&pDest[92] = "You have been voted off";
      *(_DWORD *)&pDest[100] = 1;
      *(_DWORD *)&pDest[104] = "All players idle";
      *(_DWORD *)&pDest[108] = "#L4D_ServerShutdownIdle";
      *(_DWORD *)&pDest[112] = 1;
      memset(&pDest[116], 0, 12);
      RemapText_t::RemapRawText(a1: nullptr, pRemapTable: (RemapText_t *)&pDest[20], szRawText: v14);
      goto LABEL_25;
    }
    if ( _V_stricmp(s1: "OnEngineEndGame", s2: Name) != 0 )
    {
      if ( _V_stricmp(s1: "OnMatchSessionUpdate", s2: Name) == 0 )
      {
        v15 = KeyValues::GetString(this: pEvent, keyName: "state", defaultValue: prType);
        if ( _V_stricmp(s1: "error", s2: v15) == 0 )
        {
          g_pMatchFramework->CloseSession(this: g_pMatchFramework);
          memset(pDest, 0, sizeof(pDest));
          memset(chErrorTitleBuffer, 0, sizeof(chErrorTitleBuffer));
          v16 = KeyValues::GetString(this: pEvent, keyName: "error", defaultValue: prType);
          *(_DWORD *)&strLocKey.m_szBuf[119] = prType;
          *(_DWORD *)&strLocKey.m_szBuf[123] = "#SessionError_Unknown";
          *(_DWORD *)&strLocKey.m_szBuf[127] = 0;
          *(_DWORD *)&strLocKey.m_szBuf[131] = "n/a";
          *(_DWORD *)&strLocKey.m_szBuf[135] = "#SessionError_NotAvailable";
          *(_DWORD *)&strLocKey.m_szBuf[139] = 0;
          *(_DWORD *)&strLocKey.m_szBuf[143] = "create";
          *(_DWORD *)&strLocKey.m_szBuf[147] = "#SessionError_Create";
          *(_DWORD *)&strLocKey.m_szBuf[151] = 0;
          *(_DWORD *)&strLocKey.m_szBuf[155] = "createclient";
          *(_DWORD *)&strLocKey.m_szBuf[159] = "#SessionError_NotAvailable";
          *(_DWORD *)&strLocKey.m_szBuf[163] = 0;
          *(_DWORD *)&strLocKey.m_szBuf[167] = "connect";
          *(_DWORD *)&strLocKey.m_szBuf[171] = "#SessionError_Connect";
          *(_DWORD *)&strLocKey.m_szBuf[175] = 0;
          *(_DWORD *)&strLocKey.m_szBuf[179] = "full";
          *(_DWORD *)&strLocKey.m_szBuf[183] = "#SessionError_Full";
          *(_DWORD *)&strLocKey.m_szBuf[187] = 0;
          *(_DWORD *)&strLocKey.m_szBuf[191] = "lock";
          *(_DWORD *)&strLocKey.m_szBuf[195] = "#SessionError_Lock";
          *(_DWORD *)&strLocKey.m_szBuf[199] = 0;
          *(_DWORD *)&strLocKey.m_szBuf[203] = "kicked";
          *(_DWORD *)&strLocKey.m_szBuf[207] = "#SessionError_Kicked";
          *(_DWORD *)&strLocKey.m_szBuf[211] = 0;
          *(_DWORD *)&strLocKey.m_szBuf[215] = "migrate";
          *(_DWORD *)&strLocKey.m_szBuf[219] = "#SessionError_Migrate";
          *(_DWORD *)&strLocKey.m_szBuf[223] = 0;
          *(_DWORD *)&strLocKey.m_szBuf[227] = "nomap";
          *(_DWORD *)&strLocKey.m_szBuf[231] = "#SessionError_NoMap";
          *(_DWORD *)&strLocKey.m_szBuf[235] = 0;
          *(_DWORD *)&strLocKey.m_szBuf[239] = "SteamServersDisconnected";
          *(_DWORD *)&strLocKey.m_szBuf[243] = "#SessionError_SteamServersDisconnected";
          memset(&strLocKey.m_szBuf[247], 0, 16);
          v17 = RemapText_t::RemapRawText(
                  a1: nullptr,
                  pRemapTable: (RemapText_t *)&strLocKey.m_szBuf[119],
                  szRawText: v16);
          if ( _V_stricmp(s1: "turequired", s2: v17) == 0 )
          {
            v18 = KeyValues::GetString(this: pEvent, keyName: "turequired", defaultValue: prType);
            CFmtStrN<256>::CFmtStrN<256>(this: &strLocKey, pszFormat: "#SessionError_TU_Required_%s", v18);
            if ( g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: strLocKey.m_szBuf) != nullptr )
            {
              V_strncpy(pDest, pSrc: strLocKey.m_szBuf, maxLen: 128);
              v17 = pDest;
            }
            else
            {
              v17 = "#SessionError_TU_RequiredMessage";
            }
          }
          if ( _V_stricmp(s1: "dlcrequired", s2: v17) == 0 )
          {
            autodelete_kvDlcDetails = KeyValues::GetUint64(this: pEvent, keyName: "dlcrequired", defaultValue: 0);
            iDlcRequired = 0;
            v19 = 1;
            while ( (autodelete_kvDlcDetails & (1LL << v19)) == 0 )
            {
              if ( (unsigned int)++v19 >= 8 )
                goto LABEL_41;
            }
            iDlcRequired = v19;
LABEL_41:
            CFmtStrN<256>::CFmtStrN<256>(
              this: &strLocKey,
              pszFormat: "#SessionError_DLC_RequiredTitle_%d",
              iDlcRequired);
            if ( g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: strLocKey.m_szBuf) == nullptr )
              iDlcRequired = 0;
            v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v20 != nullptr )
            {
              v21 = KeyValues::KeyValues(this: v20, setName: prType);
              kvDlcDetails = v21;
            }
            else
            {
              v21 = nullptr;
              kvDlcDetails = nullptr;
            }
            HIDWORD(autodelete_kvDlcDetails) = v21;
            if ( g_pFullFileSystem != nullptr )
              v22 = &g_pFullFileSystem->IBaseFileSystem;
            else
              v22 = nullptr;
            if ( !KeyValues::LoadFromFile(
                    this: v21,
                    filesystem: v22,
                    resourceName: "resource/UI/BaseModUI/dlcdetailsinfo.res",
                    pathID: "MOD",
                    pfnEvaluateSymbolProc: nullptr) )
            {
              v21 = nullptr;
              kvDlcDetails = nullptr;
            }
            uiDlcOfferID = 0;
            v23 = CFmtStrN<256>::CFmtStrN<256>(this: &v38, pszFormat: "dlc%d/offerid", iDlcRequired);
            v24 = KeyValues::GetString(this: v21, keyName: v23->m_szBuf, defaultValue: prType);
            if ( sscanf(string: v24, format: "0x%llx", &uiDlcOfferID) != 1 )
              uiDlcOfferID = 0;
            v25 = KeyValues::GetString(this: pEvent, keyName: "action", defaultValue: prType);
            v26 = _V_stricmp(s1: v25, s2: "kicked") == 0;
            v27 = "Kicked";
            if ( !v26 )
              v27 = "Join";
            v28 = CFmtStrN<256>::CFmtStrN<256>(
                    this: &v38,
                    pszFormat: "#SessionError_DLC_Required%s_%d",
                    v27,
                    iDlcRequired);
            v29 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v28->m_szBuf);
            wszLine1 = v29;
            v30 = "Offer";
            if ( uiDlcOfferID == 0 )
              v30 = "Message";
            v31 = CFmtStrN<256>::CFmtStrN<256>(
                    this: &v37,
                    pszFormat: "#SessionError_DLC_Required%s_%d",
                    v30,
                    iDlcRequired);
            v32 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v31->m_szBuf);
            v42 = _V_wcslen(pwch: v32);
            v33 = _V_wcslen(pwch: v29);
            v34 = alloca(2 * (v33 + v42) + 8);
            V_snwprintf(pDest: v36, maxLen: 2 * (v33 + v42) + 8, pFormat: L"%s%s", wszLine1, v32);
            V_snprintf(
              pDest: chErrorTitleBuffer,
              maxLen: 0x80u,
              pFormat: "#SessionError_DLC_RequiredTitle_%d",
              iDlcRequired);
            if ( uiDlcOfferID != 0 )
            {
              g_MarketplaceEntryPoint.uiOfferID = uiDlcOfferID;
              v35 = CFmtStrN<256>::CFmtStrN<256>(this: &v37, pszFormat: "dlc%d/type", iDlcRequired);
              g_MarketplaceEntryPoint.dwEntryPoint = KeyValues::GetInt(
                                                       this: kvDlcDetails,
                                                       keyName: v35->m_szBuf,
                                                       defaultValue: 0);
            }
            if ( HIDWORD(autodelete_kvDlcDetails) != 0 )
              KeyValues::deleteThis(this: (KeyValues *)HIDWORD(autodelete_kvDlcDetails));
          }
        }
      }
    }
    else if ( g_pMatchFramework->GetMatchSession(this: g_pMatchFramework) == nullptr )
    {
      engine->ExecuteClientCmd(this: engine, a2: "disconnect");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EAC00
// Name: public: char const __near * BaseModUI::CUIGameData::GetPlayerName(unsigned __int64,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall BaseModUI::CUIGameData::GetPlayerName(
        BaseModUI::CUIGameData *this,
        unsigned __int64 playerID,
        const char *szPlayerNameSpeculative)
{
  int v5; // esi
  const char *v6; // eax
  CUtlString insert; // [esp+Ch] [ebp-10h] BYREF

  if ( (_S3 & 1) == 0 )
  {
    _S3 |= 1u;
    CGameUIConVarRef::CGameUIConVarRef(this: &cl_names_debug, pName: "cl_names_debug");
  }
  if ( cl_names_debug.m_Info[GetGameUIActiveSplitScreenPlayerSlot()].m_pConVarState->m_Value.m_nValue != 0 )
    return "WWWWWWWWWWWWWWW";
  if ( steamapicontext != nullptr
    && steamapicontext->m_pSteamUtils != nullptr
    && steamapicontext->m_pSteamFriends != nullptr
    && steamapicontext->m_pSteamUser != nullptr )
  {
    v5 = CUtlMap<unsigned __int64,CUtlString,unsigned short>::Find(this: &this->m_mapUserXuidToName, key: &playerID);
    if ( v5 != 0xFFFF )
      return CUtlString::Get(this: &this->m_mapUserXuidToName.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v5].m_Data.elem);
    v6 = (const char *)((int (__thiscall *)(ISteamFriends *, _DWORD, _DWORD))steamapicontext->m_pSteamFriends->GetFriendPersonaName)(
                         a1: steamapicontext->m_pSteamFriends,
                         a2: playerID,
                         a3: HIDWORD(playerID));
    if ( v6 != nullptr && *v6 != 0 )
    {
      CUtlString::CUtlString(this: &insert, pString: v6);
      v5 = CUtlMap<unsigned __int64,CUtlString,unsigned short>::Insert(
             this: &this->m_mapUserXuidToName,
             key: &playerID,
             &insert);
      CUtlString::~CUtlString(this: &insert);
      if ( v5 != 0xFFFF )
        return CUtlString::Get(this: &this->m_mapUserXuidToName.m_Tree.m_Elements.m_pMemory[(unsigned __int16)v5].m_Data.elem);
    }
  }
  return szPlayerNameSpeculative;
}

//------------------------------------------------------------------------------
// Address: 0x101EAD10
// Name: public: void BaseModUI::CUIGameData::Steam_OnPersonaStateChanged(struct PersonaStateChange_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BaseModUI::CUIGameData::Steam_OnPersonaStateChanged(
        BaseModUI::CUIGameData *this,
        PersonaStateChange_t *pParam)
{
  bool v2; // zf
  CUtlMap<unsigned __int64,CUtlString,unsigned short> *p_m_mapUserXuidToName; // edi
  int v4; // esi
  const char *v5; // eax
  CUtlString utlName; // [esp+4h] [ebp-14h] BYREF
  BaseModUI::CUIGameData *v7; // [esp+14h] [ebp-4h]

  v2 = pParam->m_ulSteamID == 0;
  v7 = this;
  if ( !v2 && (pParam->m_nChangeFlags & 1) != 0 )
  {
    p_m_mapUserXuidToName = &this->m_mapUserXuidToName;
    v4 = CUtlMap<unsigned __int64,CUtlString,unsigned short>::Find(
           this: &this->m_mapUserXuidToName,
           key: &pParam->m_ulSteamID);
    if ( v4 != 0xFFFF )
    {
      CUtlString::CUtlString(
        this: &utlName,
        string: &v7->m_mapUserXuidToName.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem);
      CUtlRBTree<CUtlMap<unsigned __int64,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned __int64,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
        this: &p_m_mapUserXuidToName->m_Tree,
        elem: v4);
      CUtlRBTree<CUtlMap<unsigned __int64,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned __int64,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned __int64,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::FreeNode(
        this: &p_m_mapUserXuidToName->m_Tree,
        i: v4);
      --p_m_mapUserXuidToName->m_Tree.m_NumElements;
      v5 = CUtlString::Get(this: &utlName);
      BaseModUI::CUIGameData::GetPlayerName(this: v7, playerID: pParam->m_ulSteamID, szPlayerNameSpeculative: v5);
      CUtlString::~CUtlString(this: &utlName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EADB0
// Name: public: BaseModUI::CUIGameData::CUIGameData(void)
// Source: json
//------------------------------------------------------------------------------
BaseModUI::CUIGameData *__thiscall BaseModUI::CUIGameData::CUIGameData(BaseModUI::CUIGameData *this)
{
  CCallback<BaseModUI::CUIGameData,PersonaStateChange_t,0> *p_m_CallbackPersonaStateChanged; // ecx
  UtlRBTreeNode_t<CUtlMap<unsigned __int64,BaseModUI::CAvatarImage *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned __int64,CUtlString,unsigned short>::Node_t,unsigned short> *v4; // ecx
  IMatchEventsSubscription *v5; // eax
  __int128 v7; // [esp-10h] [ebp-28h]
  int v8; // [esp+0h] [ebp-18h]

  p_m_CallbackPersonaStateChanged = &this->m_CallbackPersonaStateChanged;
  this->__vftable = (BaseModUI::CUIGameData_vtbl *)&BaseModUI::CUIGameData::`vftable';
  *(_QWORD *)&p_m_CallbackPersonaStateChanged->m_Func = (unsigned int)BaseModUI::CUIGameData::Steam_OnPersonaStateChanged;
  p_m_CallbackPersonaStateChanged->m_nCallbackFlags = 0;
  p_m_CallbackPersonaStateChanged->m_iCallback = 0;
  p_m_CallbackPersonaStateChanged->__vftable = (CCallback<BaseModUI::CUIGameData,PersonaStateChange_t,0>_vtbl *)&CCallback<BaseModUI::CUIGameData,PersonaStateChange_t,0>::`vftable';
  p_m_CallbackPersonaStateChanged->m_pObj = this;
  *((_QWORD *)&p_m_CallbackPersonaStateChanged->m_Func + 1) = 0;
  if ( BaseModUI::CUIGameData::Steam_OnPersonaStateChanged != nullptr )
  {
    *(_QWORD *)&v7 = (unsigned int)BaseModUI::CUIGameData::Steam_OnPersonaStateChanged;
    *((_QWORD *)&v7 + 1) = 0;
    CCallback<BaseModUI::CUIGameData,PersonaStateChange_t,0>::Register(
      this: p_m_CallbackPersonaStateChanged,
      pObj: this,
      func: v7);
  }
  this->m_CGameUIPostInit = false;
  this->m_mapUserXuidToAvatar.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_mapUserXuidToAvatar.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_mapUserXuidToAvatar.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_mapUserXuidToAvatar.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_mapUserXuidToAvatar.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_mapUserXuidToAvatar.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_mapUserXuidToAvatar.m_Tree.m_FirstFree = -1;
  this->m_mapUserXuidToAvatar.m_Tree.m_pElements = m_pMemory;
  this->m_mapUserXuidToName.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_mapUserXuidToName.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_mapUserXuidToName.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_mapUserXuidToName.m_Tree.m_Elements.m_nGrowSize = 0;
  v4 = this->m_mapUserXuidToName.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_mapUserXuidToName.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_mapUserXuidToName.m_Tree.m_FirstFree = -1;
  this->m_mapUserXuidToName.m_Tree.m_pElements = v4;
  this->m_LookSensitivity = 1.0;
  this->m_flShowConnectionProblemTimer = 0.0;
  this->m_flTimeLastFrame = _Plat_FloatTime(a1: v8);
  this->m_bShowConnectionProblemActive = false;
  v5 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v5->Subscribe(this: v5, a2: this);
  *(_WORD *)&this->m_bXUIOpen = 0;
  this->m_iStorageID = -1;
  this->m_pAsyncJob = nullptr;
  this->m_pSelectStorageClient = nullptr;
  if ( this->m_mapUserXuidToAvatar.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_mapUserXuidToAvatar.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned __int64 *, const unsigned __int64 *))CDefOps<unsigned __int64>::LessFunc;
  if ( this->m_mapUserXuidToName.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_mapUserXuidToName.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned __int64 *, const unsigned __int64 *))CDefOps<unsigned __int64>::LessFunc;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101EAED0
// Name: ui_reloadscheme
// Source: json
//------------------------------------------------------------------------------
void __cdecl ui_reloadscheme()
{
  BaseModUI::CUIGameData *v0; // eax

  g_pFullFileSystem->SyncDvdDevCache(this: g_pFullFileSystem);
  if ( BaseModUI::CUIGameData::m_Instance == nullptr && !BaseModUI::CUIGameData::m_bModuleShutDown )
  {
    v0 = (BaseModUI::CUIGameData *)MemAlloc_Alloc(nSize: 0x90u);
    if ( v0 != nullptr )
      BaseModUI::CUIGameData::m_Instance = BaseModUI::CUIGameData::CUIGameData(this: v0);
    else
      BaseModUI::CUIGameData::m_Instance = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103512D0
// Name: private: virtual int CCallback<class CAchievementMgr,struct UserStatsStored_t,0>::GetCallbackSizeBytes(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CCallback<CAchievementMgr,UserStatsStored_t,0>::GetCallbackSizeBytes(
        C_OP_RenderScreenVelocityRotate *this)
{
  return 16;
}
