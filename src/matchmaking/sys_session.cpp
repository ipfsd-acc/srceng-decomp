// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/sys_session.cpp
// Functions: 65
// ============================================================

#include "matchmaking\sys_session.h"

//------------------------------------------------------------------------------
// Address: 0x10029CE0
// Name: SysSession_AllowCreate
// Source: json
//------------------------------------------------------------------------------
char __cdecl SysSession_AllowCreate()
{
  float flDelay; // [esp+0h] [ebp-4h]

  if ( mm_session_sys_delay_create.m_pParent->m_Value.m_fValue <= 0.0 )
  {
    s_fAllowCreateTime = 0.0;
    return 1;
  }
  if ( s_fAllowCreateTime <= 0.0 )
  {
    flDelay = mm_session_sys_delay_create.m_pParent->m_Value.m_fValue;
    s_fAllowCreateTime = _Plat_FloatTime() + flDelay;
  }
  else if ( s_fAllowCreateTime <= _Plat_FloatTime() )
  {
    s_fAllowCreateTime = 0.0;
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10029D50
// Name: protected: virtual bool CSysSessionBase::IsServiceSession(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSysSessionBase::IsServiceSession(CSysSessionBase *this)
{
  KeyValues *m_pSettings; // ecx
  bool result; // al
  char *String; // eax

  m_pSettings = this->m_pSettings;
  result = true;
  if ( m_pSettings != nullptr )
  {
    String = KeyValues::GetString(this: m_pSettings, keyName: "system/netflag", defaultValue: nullptr);
    if ( String == nullptr || _V_stricmp(s1: "teamlink", s2: String) != 0 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10029DB0
// Name: protected: virtual void CSysSessionBase::ReceiveMessage(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::ReceiveMessage(CSysSessionBase *this, KeyValues *msg)
{
  const char *Name; // ebx
  unsigned __int64 Uint64; // rax
  KeyValues *FirstTrueSubKey; // eax
  KeyValues *v6; // ebx
  char *String; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // edi

  Name = KeyValues::GetName(this: msg);
  if ( _V_stricmp(s1: "SysSession::Quit", s2: Name) != 0 )
  {
    if ( _V_stricmp(s1: "SysSession::Command", s2: Name) != 0 )
    {
      if ( _V_stricmp(s1: "SysSession::Voice", s2: Name) == 0 )
        this->Voice_Playback(this, a2: msg);
    }
    else
    {
      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: msg);
      v6 = FirstTrueSubKey;
      if ( FirstTrueSubKey != nullptr )
      {
        if ( (String = KeyValues::GetString(this: FirstTrueSubKey, keyName: "run", defaultValue: defaultValue),
              _V_stricmp(s1: String, s2: "all") == 0)
          || _V_stricmp(s1: String, s2: "host") == 0
          && __RTDynamicCast(
               inptr: this,
               VfDelta: 0,
               SrcType: &CSysSessionBase `RTTI Type Descriptor',
               TargetType: &CSysSessionHost `RTTI Type Descriptor',
               isReference: 0) != nullptr
          || _V_stricmp(s1: String, s2: "clients") == 0
          && __RTDynamicCast(
               inptr: this,
               VfDelta: 0,
               SrcType: &CSysSessionBase `RTTI Type Descriptor',
               TargetType: &CSysSessionClient `RTTI Type Descriptor',
               isReference: 0) != nullptr
          || _V_stricmp(s1: String, s2: "xuid") == 0
          && this->m_xuidMachineId == KeyValues::GetUint64(this: v6, keyName: "runxuid", defaultValue: 0) )
        {
          v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v8 != nullptr )
            v9 = KeyValues::KeyValues(this: v8, setName: "mmF->SysSessionCommand");
          else
            v9 = nullptr;
          KeyValues::SetPtr(this: v9, keyName: "syssession", value: this);
          KeyValues::RemoveSubKey(this: msg, subKey: v6);
          KeyValues::AddSubKey(this: v9, pSubkey: v6);
          this->OnSessionEvent(this, a2: v9);
        }
      }
    }
  }
  else
  {
    Uint64 = KeyValues::GetUint64(this: msg, keyName: "id", defaultValue: 0);
    ((void (__thiscall *)(CSysSessionBase *, _DWORD, _DWORD))this->OnPlayerLeave)(
      a1: this,
      a2: Uint64,
      a3: HIDWORD(Uint64));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029F50
// Name: public: void CSysSessionBase::Steam_OnLobbyChatUpdate(struct LobbyChatUpdate_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::Steam_OnLobbyChatUpdate(CSysSessionBase *this, LobbyChatUpdate_t *pLobbyChatUpdate)
{
  IPlayerLocal *v3; // eax
  int v4; // eax
  int v5; // edx
  int m_ulSteamIDUserChanged; // ecx
  KeyValues *v7; // eax
  KeyValues *v8; // esi

  if ( LODWORD(pLobbyChatUpdate->m_ulSteamIDLobby) == LODWORD(this->m_lobby.m_uiLobbyID)
    && HIDWORD(pLobbyChatUpdate->m_ulSteamIDLobby) == HIDWORD(this->m_lobby.m_uiLobbyID)
    && (pLobbyChatUpdate->m_rgfChatMemberStateChange & 0x1E) != 0 )
  {
    v3 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
    v4 = v3->GetXUID(this: v3);
    m_ulSteamIDUserChanged = pLobbyChatUpdate->m_ulSteamIDUserChanged;
    if ( m_ulSteamIDUserChanged == v4 && HIDWORD(pLobbyChatUpdate->m_ulSteamIDUserChanged) == v5 )
    {
      if ( LODWORD(pLobbyChatUpdate->m_ulSteamIDMakingChange) != v4
        || HIDWORD(pLobbyChatUpdate->m_ulSteamIDMakingChange) != v5 )
      {
        v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v7 != nullptr )
          v8 = KeyValues::KeyValues(this: v7, setName: "mmF->SysSessionUpdate");
        else
          v8 = nullptr;
        KeyValues::SetPtr(this: v8, keyName: "syssession", value: this);
        KeyValues::SetString(this: v8, keyName: "error", value: "kicked");
        this->OnSessionEvent(this, a2: v8);
      }
    }
    else
    {
      ((void (__thiscall *)(CSysSessionBase *, int, _DWORD))this->OnPlayerLeave)(
        a1: this,
        a2: m_ulSteamIDUserChanged,
        a3: HIDWORD(pLobbyChatUpdate->m_ulSteamIDUserChanged));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A010
// Name: protected: void CSysSessionBase::PrintValue(class KeyValues __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::PrintValue(CSysSessionBase *this, KeyValues *val, char *chBuffer, int numBytesBuffer)
{
  unsigned __int64 Uint64; // rax
  double Float; // st7
  const char *Name; // eax
  int defaultValue; // [esp+4h] [ebp-8h]
  char *defaultValuea; // [esp+4h] [ebp-8h]

  switch ( KeyValues::GetDataType(this: val, keyName: nullptr) )
  {
    case TYPE_STRING:
      defaultValuea = KeyValues::GetString(this: val, keyName: nullptr, defaultValue: ::defaultValue);
      V_snprintf(pDest: chBuffer, maxLen: numBytesBuffer, pFormat: "%s", defaultValuea);
      break;
    case TYPE_INT:
      defaultValue = KeyValues::GetInt(this: val, keyName: nullptr, defaultValue: 0);
      V_snprintf(pDest: chBuffer, maxLen: numBytesBuffer, pFormat: "%d", defaultValue);
      break;
    case TYPE_FLOAT:
      Float = KeyValues::GetFloat(this: val, keyName: nullptr, defaultValue: 0.0);
      V_snprintf(pDest: chBuffer, maxLen: numBytesBuffer, pFormat: "%f", Float);
      break;
    case TYPE_UINT64:
      Uint64 = KeyValues::GetUint64(this: val, keyName: nullptr, defaultValue: 0);
      V_snprintf(pDest: chBuffer, maxLen: numBytesBuffer, pFormat: "%llX", Uint64);
      break;
    default:
      Name = KeyValues::GetName(this: val);
      _Warning(a1: "Unknown type in CSysSessionHost::PrintValue ( %s )\n", Name);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A110
// Name: protected: bool CSysSessionHost::GetLobbyType(class KeyValues __near *,enum ELobbyType __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSysSessionHost::GetLobbyType(
        CSysSessionHost *this,
        KeyValues *kv,
        ELobbyType *peType,
        bool *pbJoinable)
{
  char *String; // edi
  char *v6; // esi

  if ( peType == nullptr || pbJoinable == nullptr )
    return 0;
  String = KeyValues::GetString(this: kv, keyName: "system/lock", defaultValue: nullptr);
  v6 = KeyValues::GetString(this: kv, keyName: "system/access", defaultValue: nullptr);
  if ( v6 != nullptr )
  {
    if ( String == nullptr )
      String = KeyValues::GetString(this: this->m_pSettings, keyName: "system/lock", defaultValue: defaultValue);
  }
  else
  {
    if ( String == nullptr )
      return 0;
    v6 = KeyValues::GetString(this: this->m_pSettings, keyName: "system/access", defaultValue: "public");
  }
  *pbJoinable = *String == 0;
  if ( _V_stricmp(s1: "public", s2: v6) != 0 )
  {
    if ( _V_stricmp(s1: "friends", s2: v6) != 0 )
    {
      if ( _V_stricmp(s1: "private", s2: v6) != 0 )
        return 0;
      *peType = k_ELobbyTypePrivate;
      return 1;
    }
    else
    {
      *peType = k_ELobbyTypeFriendsOnly;
      return 1;
    }
  }
  else
  {
    *peType = k_ELobbyTypePublic;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A220
// Name: protected: void CSysSessionClient::Process_Kicked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionClient::Process_Kicked(CSysSessionClient *this, KeyValues *msg)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi

  this->m_eState = STATE_FAIL;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "mmF->SysSessionUpdate");
  else
    v4 = nullptr;
  KeyValues::SetPtr(this: v4, keyName: "syssession", value: this);
  KeyValues::SetString(this: v4, keyName: "error", value: "kicked");
  this->OnSessionEvent(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1002A280
// Name: public: virtual void CSysSessionBase::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::Destroy(CSysSessionBase *this)
{
  int v2; // edi
  CSteamID idRemote; // [esp+Ch] [ebp-Ch] BYREF
  int v4; // [esp+14h] [ebp-4h]

  this->Voice_ProcessTalkers(this, a2: nullptr, a3: false);
  if ( this->m_lobby.m_uiLobbyID != 0 )
  {
    if ( !this->IsServiceSession(this) )
    {
      v2 = 0;
      v4 = ((int (__thiscall *)(ISteamMatchmaking *, _DWORD, _DWORD))steamapicontext->m_pSteamMatchmaking->GetNumLobbyMembers)(
             a1: steamapicontext->m_pSteamMatchmaking,
             a2: this->m_lobby.m_uiLobbyID,
             a3: HIDWORD(this->m_lobby.m_uiLobbyID));
      if ( v4 > 0 )
      {
        do
        {
          ((void (__thiscall *)(ISteamMatchmaking *, CSteamID *, _DWORD, _DWORD, int))steamapicontext->m_pSteamMatchmaking->GetLobbyMemberByIndex)(
            a1: steamapicontext->m_pSteamMatchmaking,
            a2: &idRemote,
            a3: this->m_lobby.m_uiLobbyID,
            a4: HIDWORD(this->m_lobby.m_uiLobbyID),
            a5: v2);
          ((void (__thiscall *)(ISteamNetworking *, _DWORD, _DWORD, int))steamapicontext->m_pSteamNetworking->CloseP2PChannelWithUser)(
            a1: steamapicontext->m_pSteamNetworking,
            a2: *(_DWORD *)&idRemote.m_steamid.m_comp,
            a3: *((_DWORD *)&idRemote.m_steamid.m_comp + 1),
            a4: 2);
          ++v2;
        }
        while ( v2 < v4 );
      }
    }
    ((void (__thiscall *)(ISteamMatchmaking *, _DWORD, _DWORD))steamapicontext->m_pSteamMatchmaking->LeaveLobby)(
      a1: steamapicontext->m_pSteamMatchmaking,
      a2: this->m_lobby.m_uiLobbyID,
      a3: HIDWORD(this->m_lobby.m_uiLobbyID));
  }
  this->m_lobby.m_uiLobbyID = 0;
  *(_QWORD *)&this->m_lobby.m_eLobbyState = 0;
  ((void (__thiscall *)(CSysSessionBase *, int))this->dtr_CSysSessionBase)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1002A370
// Name: public: virtual void CSysSessionBase::DebugPrint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::DebugPrint(CSysSessionBase *this)
{
  int v2; // eax
  int m_uiLobbyID; // edx
  ISteamMatchmaking *m_pSteamMatchmaking; // ecx
  int v5; // ebx
  _QWORD *v6; // eax
  int v7; // edx
  ISteamMatchmaking *v8; // ecx
  int v9; // eax
  int i; // edi
  ISteamMatchmaking *v11; // ecx
  int v12; // edx
  _QWORD *v13; // eax
  const char *v14; // eax
  _BYTE v15[12]; // [esp+Ch] [ebp-10h] BYREF
  int m_uiLobbyID_high; // [esp+18h] [ebp-4h]

  DevMsg(a1: "CSysSessionBase\n");
  DevMsg(a1: "    machineid: %llx\n", this->m_xuidMachineId);
  DevMsg(a1: "    lobby id:  %llx\n", this->m_lobby.m_uiLobbyID);
  DevMsg(a1: "    lbystate:  %d\n", this->m_lobby.m_eLobbyState);
  if ( this->m_lobby.m_uiLobbyID != 0 )
  {
    v2 = ((int (__thiscall *)(ISteamMatchmaking *, _DWORD, _DWORD))steamapicontext->m_pSteamMatchmaking->GetNumLobbyMembers)(
           a1: steamapicontext->m_pSteamMatchmaking,
           a2: this->m_lobby.m_uiLobbyID,
           a3: HIDWORD(this->m_lobby.m_uiLobbyID));
    m_uiLobbyID = this->m_lobby.m_uiLobbyID;
    m_pSteamMatchmaking = steamapicontext->m_pSteamMatchmaking;
    v5 = v2;
    m_uiLobbyID_high = HIDWORD(this->m_lobby.m_uiLobbyID);
    v6 = (_QWORD *)((int (__thiscall *)(ISteamMatchmaking *, _BYTE *, int, int))m_pSteamMatchmaking->GetLobbyOwner)(
                     a1: m_pSteamMatchmaking,
                     a2: v15,
                     a3: m_uiLobbyID,
                     a4: m_uiLobbyID_high);
    DevMsg(a1: "    owner:     %llx\n", *v6);
    v7 = this->m_lobby.m_uiLobbyID;
    v8 = steamapicontext->m_pSteamMatchmaking;
    m_uiLobbyID_high = HIDWORD(this->m_lobby.m_uiLobbyID);
    v9 = ((int (__thiscall *)(ISteamMatchmaking *, int, int))v8->GetLobbyMemberLimit)(
           a1: v8,
           a2: v7,
           a3: m_uiLobbyID_high);
    DevMsg(a1: "    members:   %d/%d\n", v5, v9);
    for ( i = 0; i < v5; ++i )
    {
      v11 = steamapicontext->m_pSteamMatchmaking;
      v12 = this->m_lobby.m_uiLobbyID;
      m_uiLobbyID_high = HIDWORD(this->m_lobby.m_uiLobbyID);
      v13 = (_QWORD *)((int (__thiscall *)(ISteamMatchmaking *, _BYTE *, int, int, int))v11->GetLobbyMemberByIndex)(
                        a1: v11,
                        a2: v15,
                        a3: v12,
                        a4: m_uiLobbyID_high,
                        a5: i);
      DevMsg(a1: "    member%02d:  %llx\n", i, *v13);
    }
    v14 = (const char *)((int (__thiscall *)(ISteamMatchmaking *, _DWORD, _DWORD, const char *))steamapicontext->m_pSteamMatchmaking->GetLobbyData)(
                          a1: steamapicontext->m_pSteamMatchmaking,
                          a2: this->m_lobby.m_uiLobbyID,
                          a3: HIDWORD(this->m_lobby.m_uiLobbyID),
                          a4: "system:network");
    DevMsg(a1: "    ldata:net: %s\n", v14);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A4E0
// Name: public: unsigned __int64 CSysSessionBase::GetReservationCookie(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CSysSessionBase::GetReservationCookie(CSysSessionBase *this)
{
  unsigned __int64 result; // rax

  result = KeyValues::GetUint64(this: this->m_pSettings, keyName: "server/reservationid", defaultValue: 0);
  if ( result == 0 )
    return this->m_lobby.m_uiLobbyID;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002A510
// Name: protected: void CSysSessionBase::LobbySetDataFromKeyValues(char const __near *,class KeyValues __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::LobbySetDataFromKeyValues(
        CSysSessionBase *this,
        const char *szPath,
        KeyValues *key,
        bool bRecurse)
{
  KeyValues *i; // esi
  const char *Name; // eax
  char chKey[256]; // [esp+Ch] [ebp-200h] BYREF
  char chValue[256]; // [esp+10Ch] [ebp-100h] BYREF

  if ( key != nullptr && szPath != nullptr )
  {
    if ( KeyValues::GetDataType(this: key, keyName: nullptr) != TYPE_NONE )
    {
      CSysSessionBase::PrintValue(this, val: key, chBuffer: chValue, numBytesBuffer: 256);
      DevMsg(a1: "LobbySetData: '%s' = '%s'\n", szPath, chValue);
      ((void (__thiscall *)(ISteamMatchmaking *, _DWORD, _DWORD, const char *, char *))steamapicontext->m_pSteamMatchmaking->SetLobbyData)(
        a1: steamapicontext->m_pSteamMatchmaking,
        a2: this->m_lobby.m_uiLobbyID,
        a3: HIDWORD(this->m_lobby.m_uiLobbyID),
        a4: szPath,
        a5: chValue);
    }
    else
    {
      for ( i = KeyValues::GetFirstSubKey(this: key); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      {
        if ( bRecurse || KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
        {
          Name = KeyValues::GetName(this: i);
          V_snprintf(pDest: chKey, maxLen: 256, pFormat: "%s:%s", szPath, Name);
          CSysSessionBase::LobbySetDataFromKeyValues(this, szPath: chKey, key: i, bRecurse);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A610
// Name: protected: virtual void CSysSessionBase::Voice_Playback(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::Voice_Playback(CSysSessionBase *this, KeyValues *msg)
{
  unsigned __int64 Uint64; // kr00_8
  void *Ptr; // edi
  int Int; // eax
  int v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // esi

  Uint64 = KeyValues::GetUint64(this: msg, keyName: "xuid", defaultValue: 0);
  Ptr = KeyValues::GetPtr(this: msg, keyName: "binary/ptr", defaultValue: nullptr);
  Int = KeyValues::GetInt(this: msg, keyName: "binary/size", defaultValue: 0);
  v5 = Int;
  if ( Ptr != nullptr
    && Int != 0
    && (mm_session_voice_loading.m_pParent != nullptr && mm_session_voice_loading.m_pParent->m_Value.m_nValue != 0
     || !g_pMatchExtensions->m_exts.m_pIVEngineClient->IsDrawingLoadingImage(this: g_pMatchExtensions->m_exts.m_pIVEngineClient)
     && !g_pMatchExtensions->m_exts.m_pIVEngineClient->IsTransitioningToLoad(this: g_pMatchExtensions->m_exts.m_pIVEngineClient)) )
  {
    ((void (__thiscall *)(IEngineVoice *, _DWORD, _DWORD, void *, int, _DWORD))g_pMatchExtensions->m_exts.m_pIEngineVoice->PlayIncomingVoiceData)(
      a1: g_pMatchExtensions->m_exts.m_pIEngineVoice,
      a2: Uint64,
      a3: HIDWORD(Uint64),
      a4: Ptr,
      a5: v5,
      a6: 0);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
    {
      v7 = KeyValues::KeyValues(this: v6, setName: "OnPlayerActivity", firstKey: "act", firstValue: "voice");
      v8 = v7;
      if ( v7 != nullptr )
      {
        KeyValues::SetUint64(this: v7, keyName: "xuid", value: Uint64);
        this->OnSessionEvent(this, a2: v8);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A710
// Name: public: virtual void CSysSessionHost::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionHost::Destroy(CSysSessionHost *this)
{
  if ( this->m_eState == STATE_FAIL )
    ((void (__thiscall *)(CSysSessionHost *, int))this->dtr_CSysSessionBase)(a1: this, a2: 1);
  else
    CSysSessionBase::Destroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002A730
// Name: public: virtual void CSysSessionHost::DebugPrint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionHost::DebugPrint(CSysSessionHost *this)
{
  DevMsg(a1: "CSysSessionHost [ state=%d ]\n", this->m_eState);
  CSysSessionBase::DebugPrint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002A750
// Name: public: virtual unsigned __int64 CSysSessionClient::GetHostXuid(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CSysSessionClient::GetHostXuid(CSysSessionClient *this, unsigned __int64 xuidValidResult)
{
  _BYTE v3[8]; // [esp+4h] [ebp-8h] BYREF

  if ( this->m_lobby.m_uiLobbyID != 0 )
    return *(_QWORD *)((int (__thiscall *)(ISteamMatchmaking *, _BYTE *, _DWORD, _DWORD))steamapicontext->m_pSteamMatchmaking->GetLobbyOwner)(
                        a1: steamapicontext->m_pSteamMatchmaking,
                        a2: v3,
                        a3: this->m_lobby.m_uiLobbyID,
                        a4: HIDWORD(this->m_lobby.m_uiLobbyID));
  else
    return this->m_xuidMachineId;
}

//------------------------------------------------------------------------------
// Address: 0x1002A7B0
// Name: public: void CSysSessionHost::Migrate(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionHost::Migrate(CSysSessionHost *this, KeyValues *pCommand)
{
  char *String; // eax
  ISteamMatchmaking *m_pSteamMatchmaking; // esi
  unsigned __int64 Uint64; // rax
  KeyValues *v6; // eax
  KeyValues *v7; // esi

  String = KeyValues::GetString(this: pCommand, keyName: "migrate", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: "host>client") == 0 )
  {
    m_pSteamMatchmaking = steamapicontext->m_pSteamMatchmaking;
    Uint64 = KeyValues::GetUint64(this: pCommand, keyName: "xuid", defaultValue: 0);
    ((void (__thiscall *)(ISteamMatchmaking *, _DWORD, _DWORD, _DWORD, _DWORD))m_pSteamMatchmaking->SetLobbyOwner)(
      a1: m_pSteamMatchmaking,
      a2: this->m_lobby.m_uiLobbyID,
      a3: HIDWORD(this->m_lobby.m_uiLobbyID),
      a4: Uint64,
      a5: HIDWORD(Uint64));
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "mmF->SysSessionUpdate");
    else
      v7 = nullptr;
    KeyValues::SetPtr(this: v7, keyName: "syssession", value: this);
    this->m_eState = STATE_FAIL;
    KeyValues::SetString(this: v7, keyName: "action", value: "client");
    this->OnSessionEvent(this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A880
// Name: protected: void CSysSessionHost::UpdateSessionProperties(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionHost::UpdateSessionProperties(CSysSessionHost *this, ELobbyType kv)
{
  KeyValues *v2; // edi
  KeyValues *Key; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  int bJoinable; // [esp+8h] [ebp-4h] BYREF

  v2 = (KeyValues *)kv;
  if ( kv != k_ELobbyTypePrivate )
  {
    if ( this->m_lobby.m_uiLobbyID != 0 )
    {
      Key = KeyValues::FindKey(this: (KeyValues *)kv, keyName: "system", bCreate: false);
      CSysSessionBase::LobbySetDataFromKeyValues(this, szPath: "system", key: Key, bRecurse: true);
      v5 = KeyValues::FindKey(this: v2, keyName: "game", bCreate: false);
      CSysSessionBase::LobbySetDataFromKeyValues(this, szPath: "game", key: v5, bRecurse: true);
      v6 = KeyValues::FindKey(this: v2, keyName: "options", bCreate: false);
      CSysSessionBase::LobbySetDataFromKeyValues(this, szPath: "options", key: v6, bRecurse: true);
    }
    kv = k_ELobbyTypePublic;
    LOBYTE(bJoinable) = 1;
    if ( CSysSessionHost::GetLobbyType(this, kv: v2, peType: &kv, pbJoinable: (bool *)&bJoinable) != 0
      && this->m_lobby.m_uiLobbyID != 0 )
    {
      ((void (__thiscall *)(ISteamMatchmaking *, _DWORD, _DWORD, ELobbyType))steamapicontext->m_pSteamMatchmaking->SetLobbyType)(
        a1: steamapicontext->m_pSteamMatchmaking,
        a2: this->m_lobby.m_uiLobbyID,
        a3: HIDWORD(this->m_lobby.m_uiLobbyID),
        a4: kv);
      ((void (__thiscall *)(ISteamMatchmaking *, _DWORD, _DWORD, int))steamapicontext->m_pSteamMatchmaking->SetLobbyJoinable)(
        a1: steamapicontext->m_pSteamMatchmaking,
        a2: this->m_lobby.m_uiLobbyID,
        a3: HIDWORD(this->m_lobby.m_uiLobbyID),
        a4: bJoinable);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A970
// Name: public: virtual void CSysSessionClient::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionClient::Destroy(CSysSessionClient *this)
{
  if ( this->m_eState == 5 )
    ((void (__thiscall *)(CSysSessionClient *, int))this->dtr_CSysSessionBase)(a1: this, a2: 1);
  else
    CSysSessionBase::Destroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002A990
// Name: public: virtual void CSysSessionClient::DebugPrint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionClient::DebugPrint(CSysSessionClient *this)
{
  double v2; // st7
  unsigned __int64 m_xuidLeader; // [esp+8h] [ebp-10h]

  DevMsg(a1: "CSysSessionClient [ state=%d ]\n", this->m_eState);
  if ( this->m_eState == STATE_REQUESTING_JOIN_DATA )
  {
    m_xuidLeader = this->m_RequestJoinDataInfo.m_xuidLeader;
    v2 = _Plat_FloatTime();
    DevMsg(
      a1: "Requested join data %.3f sec ago from xuid = %llx\n",
      v2 - this->m_RequestJoinDataInfo.m_fTimeSent,
      m_xuidLeader);
  }
  CSysSessionBase::DebugPrint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002A9F0
// Name: public: void CSysSessionClient::Migrate(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionClient::Migrate(CSysSessionClient *this, KeyValues *pCommand)
{
  char *String; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  _BYTE v6[8]; // [esp+8h] [ebp-8h] BYREF

  String = KeyValues::GetString(this: pCommand, keyName: "migrate", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: "client>host") == 0 )
  {
    ((void (__thiscall *)(ISteamMatchmaking *, _BYTE *, _DWORD, _DWORD))steamapicontext->m_pSteamMatchmaking->GetLobbyOwner)(
      a1: steamapicontext->m_pSteamMatchmaking,
      a2: v6,
      a3: this->m_lobby.m_uiLobbyID,
      a4: HIDWORD(this->m_lobby.m_uiLobbyID));
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "mmF->SysSessionUpdate");
    else
      v5 = nullptr;
    KeyValues::SetPtr(this: v5, keyName: "syssession", value: this);
    this->m_eState = 5;
    KeyValues::SetString(this: v5, keyName: "action", value: "host");
    this->OnSessionEvent(this, a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AAD0
// Name: protected: virtual CSysSessionBase::~CSysSessionBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::~CSysSessionBase(CSysSessionBase *this)
{
  this->__vftable = (CSysSessionBase_vtbl *)&CSysSessionBase::`vftable';
  this->m_CallbackOnP2PSessionRequest.__vftable = (CCallback<CSysSessionBase,P2PSessionRequest_t,0>_vtbl *)&CCallback<CSysSessionBase,P2PSessionRequest_t,0>::`vftable';
  if ( (this->m_CallbackOnP2PSessionRequest.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnP2PSessionRequest);
  this->m_CallbackOnServersDisconnected.__vftable = (CCallback<CSysSessionBase,SteamServersDisconnected_t,0>_vtbl *)&CCallback<CSysSessionBase,SteamServersDisconnected_t,0>::`vftable';
  if ( (this->m_CallbackOnServersDisconnected.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnServersDisconnected);
  this->m_CallbackOnServersConnected.__vftable = (CCallback<CSysSessionBase,SteamServersConnected_t,0>_vtbl *)&CCallback<CSysSessionBase,SteamServersConnected_t,0>::`vftable';
  if ( (this->m_CallbackOnServersConnected.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnServersConnected);
  this->m_CallbackOnLobbyChatUpdate.__vftable = (CCallbackManual<CSysSessionBase,LobbyChatUpdate_t,0>_vtbl *)&CCallback<CSysSessionBase,LobbyChatUpdate_t,0>::`vftable';
  if ( (this->m_CallbackOnLobbyChatUpdate.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnLobbyChatUpdate);
  this->m_CallbackOnLobbyChatMsg.__vftable = (CCallbackManual<CSysSessionBase,LobbyChatMsg_t,0>_vtbl *)&CCallback<CSysSessionBase,LobbyChatMsg_t,0>::`vftable';
  if ( (this->m_CallbackOnLobbyChatMsg.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnLobbyChatMsg);
}

//------------------------------------------------------------------------------
// Address: 0x1002AB50
// Name: public: void CSysSessionBase::Steam_OnP2PSessionRequest(struct P2PSessionRequest_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::Steam_OnP2PSessionRequest(CSysSessionBase *this, P2PSessionRequest_t *pParam)
{
  unsigned int m_unAll64Bits; // esi
  unsigned int m_unAll64Bits_high; // edi

  m_unAll64Bits = pParam->m_steamIDRemote.m_steamid.m_unAll64Bits;
  m_unAll64Bits_high = HIDWORD(pParam->m_steamIDRemote.m_steamid.m_unAll64Bits);
  if ( this->m_lobby.m_uiLobbyID != 0
    && SessionMembersFindPlayer(
         pSessionSettings: this->m_pSettings,
         xuidPlayer: __PAIR64__(m_unAll64Bits_high, m_unAll64Bits),
         ppMachine: nullptr) != nullptr )
  {
    ((void (__thiscall *)(ISteamNetworking *, unsigned int, unsigned int))steamapicontext->m_pSteamNetworking->AcceptP2PSessionWithUser)(
      a1: steamapicontext->m_pSteamNetworking,
      a2: m_unAll64Bits,
      a3: m_unAll64Bits_high);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002ABA0
// Name: public: void CSysSessionBase::Steam_OnServersDisconnected(struct SteamServersDisconnected_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::Steam_OnServersDisconnected(CSysSessionBase *this, SteamServersDisconnected_t *pParam)
{
  CSteamLobbyObject::LobbyState_t m_eLobbyState; // eax
  int v4; // ebx
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  int m_uiLobbyID; // edx
  KeyValues *m_pSettings; // ecx
  IPlayerLocal *v9; // eax
  unsigned __int64 v10; // rax
  KeyValues *v11; // ecx
  KeyValues *Key; // eax
  KeyValues *v13; // edi
  CFmtStrN<256> *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // esi
  unsigned __int64 Uint64; // rax
  int Int; // eax
  int v19; // eax
  CFmtStrN<256> v20; // [esp+Ch] [ebp-118h] BYREF
  int numMachines; // [esp+118h] [ebp-Ch]
  unsigned __int64 xuidLocal; // [esp+11Ch] [ebp-8h]

  m_eLobbyState = this->m_lobby.m_eLobbyState;
  v4 = 0;
  if ( m_eLobbyState != STATE_DEFAULT )
  {
    if ( m_eLobbyState != STATE_DISCONNECTED_FROM_STEAM )
    {
      m_uiLobbyID = this->m_lobby.m_uiLobbyID;
      this->m_lobby.m_eLobbyState = STATE_DISCONNECTED_FROM_STEAM;
      ((void (__thiscall *)(ISteamMatchmaking *, int, _DWORD))steamapicontext->m_pSteamMatchmaking->LeaveLobby)(
        a1: steamapicontext->m_pSteamMatchmaking,
        a2: m_uiLobbyID,
        a3: HIDWORD(this->m_lobby.m_uiLobbyID));
      m_pSettings = this->m_pSettings;
      LODWORD(this->m_lobby.m_uiLobbyID) = 0;
      HIDWORD(this->m_lobby.m_uiLobbyID) = 0;
      KeyValues::SetString(this: m_pSettings, keyName: "system/lock", value: "SteamServersDisconnected");
      v9 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
      v10 = v9->GetXUID(this: v9);
      v11 = this->m_pSettings;
      xuidLocal = v10;
      Key = KeyValues::FindKey(this: v11, keyName: "members", bCreate: false);
      v13 = Key;
      if ( Key != nullptr )
      {
        numMachines = KeyValues::GetInt(this: Key, keyName: "numMachines", defaultValue: 0);
        if ( numMachines > 0 )
        {
          do
          {
            v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v20, pszFormat: "machine%d", v4);
            v15 = KeyValues::FindKey(this: v13, keyName: v14->m_szBuf, bCreate: false);
            v16 = v15;
            if ( v15 != nullptr )
            {
              Uint64 = KeyValues::GetUint64(this: v15, keyName: "id", defaultValue: 0);
              if ( Uint64 == xuidLocal )
              {
                KeyValues::SetName(this: v16, setName: "machine0");
                Int = KeyValues::GetInt(this: v16, keyName: "numPlayers", defaultValue: 1);
                KeyValues::SetInt(this: v13, keyName: "numPlayers", value: Int);
                v19 = KeyValues::GetInt(this: v16, keyName: "numPlayers", defaultValue: 1);
                KeyValues::SetInt(this: v13, keyName: "numSlots", value: v19);
              }
              else
              {
                KeyValues::RemoveSubKey(this: v13, subKey: v16);
                KeyValues::deleteThis(this: v16);
              }
            }
            ++v4;
          }
          while ( v4 < numMachines );
        }
        KeyValues::SetInt(this: v13, keyName: "numMachines", value: 1);
      }
    }
  }
  else
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "mmF->SysSessionUpdate");
    else
      v6 = nullptr;
    KeyValues::SetPtr(this: v6, keyName: "syssession", value: this);
    KeyValues::SetString(this: v6, keyName: "error", value: "SteamServersDisconnected");
    this->OnSessionEvent(this, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AD60
// Name: protected: virtual void CSysSessionBase::Voice_ProcessTalkers(class KeyValues __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::Voice_ProcessTalkers(CSysSessionBase *this, KeyValues *pMachine, BOOL bAdd)
{
  bool (__thiscall *IsServiceSession)(CSysSessionBase *); // edx
  KeyValues *v5; // esi
  int Int; // ebx
  CFmtStrN<256> *v7; // eax
  KeyValues *Key; // eax
  int v9; // ebx
  CFmtStrN<256> *v10; // eax
  unsigned __int64 Uint64; // rdi
  IEngineVoice *m_pIEngineVoice; // ecx
  CFmtStrN<256> v13; // [esp+4h] [ebp-134h] BYREF
  unsigned __int64 uiMachineFlags; // [esp+110h] [ebp-28h]
  unsigned __int64 xuid; // [esp+118h] [ebp-20h]
  unsigned __int64 xuidMachine; // [esp+120h] [ebp-18h]
  CSysSessionBase *v17; // [esp+128h] [ebp-10h]
  int numPlayers; // [esp+12Ch] [ebp-Ch]
  int k; // [esp+130h] [ebp-8h]
  int iCtrlr; // [esp+134h] [ebp-4h]

  IsServiceSession = this->IsServiceSession;
  v17 = this;
  if ( ((unsigned __int8 (__fastcall *)(CSysSessionBase *))IsServiceSession)(a1: this) == 0 )
  {
    v5 = pMachine;
    if ( pMachine != nullptr )
    {
      xuidMachine = KeyValues::GetUint64(this: pMachine, keyName: "id", defaultValue: 0);
      if ( xuidMachine != 0 )
      {
        numPlayers = KeyValues::GetInt(this: pMachine, keyName: "numPlayers", defaultValue: 0);
        v9 = 0;
        uiMachineFlags = KeyValues::GetUint64(this: pMachine, keyName: "flags", defaultValue: 0);
        k = 0;
        if ( numPlayers > 0 )
        {
          while ( 1 )
          {
            v10 = CFmtStrN<256>::CFmtStrN<256>(this: &v13, pszFormat: "player%d/xuid", v9);
            Uint64 = KeyValues::GetUint64(this: v5, keyName: v10->m_szBuf, defaultValue: 0);
            if ( Uint64 != 0 )
            {
              iCtrlr = -1;
              if ( xuidMachine == v17->m_xuidMachineId )
              {
                xuid = 0;
                Uint64 = 0;
                iCtrlr = v9;
              }
              m_pIEngineVoice = g_pMatchExtensions->m_exts.m_pIEngineVoice;
              if ( m_pIEngineVoice != nullptr )
              {
                if ( bAdd )
                {
                  ((void (__thiscall *)(IEngineVoice *, _DWORD, _DWORD, int, bool, _DWORD))g_pMatchExtensions->m_exts.m_pIEngineVoice->AddPlayerToVoiceList)(
                    a1: g_pMatchExtensions->m_exts.m_pIEngineVoice,
                    a2: Uint64,
                    a3: HIDWORD(Uint64),
                    a4: iCtrlr,
                    a5: (uiMachineFlags & 1) != 0,
                    a6: 0);
                  v9 = k;
                }
                else
                {
                  ((void (__thiscall *)(IEngineVoice *, _DWORD, _DWORD, int))m_pIEngineVoice->RemovePlayerFromVoiceList)(
                    a1: m_pIEngineVoice,
                    a2: Uint64,
                    a3: HIDWORD(Uint64),
                    a4: iCtrlr);
                }
              }
            }
            k = ++v9;
            if ( v9 >= numPlayers )
              break;
            v5 = pMachine;
          }
        }
      }
    }
    else
    {
      Int = KeyValues::GetInt(this: this->m_pSettings, keyName: "members/numMachines", defaultValue: 0);
      if ( Int > 0 )
      {
        do
        {
          v7 = CFmtStrN<256>::CFmtStrN<256>(this: &v13, pszFormat: "members/machine%d", v5);
          Key = KeyValues::FindKey(this: this->m_pSettings, keyName: v7->m_szBuf, bCreate: false);
          if ( Key != nullptr )
            this->Voice_ProcessTalkers(this, a2: Key, a3: bAdd);
          v5 = (KeyValues *)((char *)v5 + 1);
        }
        while ( (int)v5 < Int );
      }
      if ( bAdd && this->m_Voice_flLastHeadsetStatusCheck < 0.0 )
        this->m_Voice_flLastHeadsetStatusCheck = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AF20
// Name: protected: bool CSysSessionBase::FindAndRemovePlayerFromMembers(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSysSessionBase::FindAndRemovePlayerFromMembers(CSysSessionBase *this, unsigned __int64 xuid)
{
  KeyValues *Key; // eax
  KeyValues *v3; // ebx
  int v5; // edi
  CFmtStrN<256> *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  int v9; // edi
  CFmtStrN<256> *v10; // eax
  int i; // edi
  CFmtStrN<256> *v12; // eax
  CFmtStrN<256> *v13; // eax
  CFmtStrN<256> *v14; // eax
  KeyValues *v15; // ebx
  KeyValues *v16; // eax
  KeyValues *v17; // edi
  KeyValues *Copy; // ebx
  KeyValues *v19; // ebx
  CSysSessionBase *v20; // edi
  KeyValues *v21; // eax
  CFmtStrN<256> v22; // [esp+4h] [ebp-33Ch] BYREF
  CFmtStrN<256> v23; // [esp+110h] [ebp-230h] BYREF
  CFmtStrN<256> v24; // [esp+21Ch] [ebp-124h] BYREF
  unsigned __int64 value; // [esp+328h] [ebp-18h]
  int k; // [esp+330h] [ebp-10h]
  int numOtherPlayers; // [esp+334h] [ebp-Ch]
  void *inptr; // [esp+338h] [ebp-8h]
  int numMachines; // [esp+33Ch] [ebp-4h]
  KeyValues *pNextMachine; // [esp+34Ch] [ebp+Ch]
  KeyValues *pNextMachinea; // [esp+34Ch] [ebp+Ch]

  inptr = this;
  Key = KeyValues::FindKey(this: this->m_pSettings, keyName: "members", bCreate: false);
  v3 = Key;
  if ( Key == nullptr )
    return 0;
  numMachines = KeyValues::GetInt(this: Key, keyName: "numMachines", defaultValue: 0);
  v5 = 0;
  HIDWORD(value) = KeyValues::GetInt(this: v3, keyName: "numPlayers", defaultValue: 0);
  k = 0;
  if ( numMachines <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = CFmtStrN<256>::CFmtStrN<256>(this: &v22, pszFormat: "machine%d", v5);
    v7 = KeyValues::FindKey(this: v3, keyName: v6->m_szBuf, bCreate: false);
    v8 = v7;
    if ( v7 != nullptr )
      break;
LABEL_9:
    k = ++v5;
    if ( v5 >= numMachines )
      return 0;
  }
  v9 = 0;
  numOtherPlayers = KeyValues::GetInt(this: v7, keyName: "numPlayers", defaultValue: 0);
  if ( numOtherPlayers <= 0 )
  {
LABEL_8:
    v5 = k;
    goto LABEL_9;
  }
  while ( 1 )
  {
    v10 = CFmtStrN<256>::CFmtStrN<256>(this: &v24, pszFormat: "player%d/xuid", v9);
    if ( KeyValues::GetUint64(this: v8, keyName: v10->m_szBuf, defaultValue: 0) == xuid )
      break;
    if ( ++v9 >= numOtherPlayers )
      goto LABEL_8;
  }
  (*(void (__thiscall **)(void *, KeyValues *, _DWORD))(*(_DWORD *)inptr + 40))(a1: inptr, a2: v8, a3: 0);
  KeyValues::RemoveSubKey(this: v3, subKey: v8);
  for ( i = k + 1; i < numMachines; ++i )
  {
    v12 = CFmtStrN<256>::CFmtStrN<256>(this: &v24, pszFormat: "machine%d", i);
    pNextMachine = KeyValues::FindKey(this: v3, keyName: v12->m_szBuf, bCreate: false);
    if ( pNextMachine != nullptr )
    {
      v13 = CFmtStrN<256>::CFmtStrN<256>(this: &v23, pszFormat: "machine%d", i - 1);
      KeyValues::SetName(this: pNextMachine, setName: v13->m_szBuf);
    }
  }
  KeyValues::SetInt(this: v3, keyName: "numMachines", value: numMachines - 1 < 0 ? 0 : numMachines - 1);
  KeyValues::SetInt(
    this: v3,
    keyName: "numPlayers",
    value: HIDWORD(value) - numOtherPlayers < 0 ? 0 : HIDWORD(value) - numOtherPlayers);
  pNextMachinea = nullptr;
  do
  {
    v14 = CFmtStrN<256>::CFmtStrN<256>(this: &v23, pszFormat: "player%d", pNextMachinea);
    v15 = KeyValues::FindKey(this: v8, keyName: v14->m_szBuf, bCreate: false);
    value = KeyValues::GetUint64(this: v15, keyName: "xuid", defaultValue: 0);
    v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v16 != nullptr )
      v17 = KeyValues::KeyValues(this: v16, setName: "OnPlayerRemoved");
    else
      v17 = nullptr;
    KeyValues::SetUint64(this: v17, keyName: "xuid", value);
    if ( v15 != nullptr )
    {
      Copy = KeyValues::MakeCopy(this: v15);
      KeyValues::SetName(this: Copy, setName: "player");
      KeyValues::AddSubKey(this: v17, pSubkey: Copy);
    }
    v19 = KeyValues::MakeCopy(this: v8);
    KeyValues::SetName(this: v19, setName: "machine");
    KeyValues::AddSubKey(this: v17, pSubkey: v19);
    (*(void (__thiscall **)(void *, KeyValues *))(*(_DWORD *)inptr + 36))(a1: inptr, a2: v17);
    pNextMachinea = (KeyValues *)((char *)pNextMachinea + 1);
  }
  while ( (int)pNextMachinea < numOtherPlayers );
  v20 = (CSysSessionBase *)inptr;
  if ( __RTDynamicCast(
         inptr,
         VfDelta: 0,
         SrcType: &CSysSessionBase `RTTI Type Descriptor',
         TargetType: &CSysSessionHost `RTTI Type Descriptor',
         isReference: 0) != nullptr )
  {
    v21 = KeyValues::FindKey(this: v20->m_pSettings, keyName: "Members", bCreate: false);
    CSysSessionBase::LobbySetDataFromKeyValues(this: v20, szPath: "members", key: v21, bRecurse: false);
  }
  KeyValues::deleteThis(this: v8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002B1E0
// Name: public: void CSysSessionBase::SetSessionActiveGameplayState(bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::SetSessionActiveGameplayState(
        CSysSessionBase *this,
        bool bActive,
        const char *szSecureServerAddress)
{
  CSteamLobbyObject::LobbyState_t m_eLobbyState; // eax
  __int32 v4; // eax

  m_eLobbyState = this->m_lobby.m_eLobbyState;
  if ( m_eLobbyState != STATE_DEFAULT )
  {
    v4 = m_eLobbyState - 1;
    if ( v4 != 0 )
    {
      if ( v4 == 1 && !bActive )
      {
        this->m_lobby.m_eLobbyState = STATE_DEFAULT;
        CSysSessionBase::Steam_OnServersDisconnected(this, pParam: nullptr);
      }
    }
    else if ( !bActive )
    {
      this->m_lobby.m_eLobbyState = STATE_DEFAULT;
    }
  }
  else if ( bActive )
  {
    this->m_lobby.m_eLobbyState = STATE_ACTIVE_GAME;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B220
// Name: public: virtual CSysSessionHost::~CSysSessionHost(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionHost::~CSysSessionHost(CSysSessionHost *this)
{
  bool v2; // zf
  int m_hAPICall; // eax
  int m_hAPICall_high; // ecx

  this->__vftable = (CSysSessionHost_vtbl *)&CSysSessionHost::`vftable';
  v2 = (this->m_CallbackOnLobbyEntered.m_nCallbackFlags & 1) == 0;
  this->m_CallbackOnLobbyEntered.__vftable = (CCallbackManual<CSysSessionHost,LobbyEnter_t,0>_vtbl *)&CCallback<CSysSessionHost,LobbyEnter_t,0>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnLobbyEntered);
  m_hAPICall = this->m_CallbackOnLobbyCreated.m_hAPICall;
  m_hAPICall_high = HIDWORD(this->m_CallbackOnLobbyCreated.m_hAPICall);
  v2 = this->m_CallbackOnLobbyCreated.m_hAPICall == 0;
  this->m_CallbackOnLobbyCreated.__vftable = (CCallResult<CSysSessionHost,LobbyCreated_t>_vtbl *)&CCallResult<CSysSessionHost,LobbyCreated_t>::`vftable';
  if ( !v2 )
  {
    _SteamAPI_UnregisterCallResult(a1: &this->m_CallbackOnLobbyCreated, a2: m_hAPICall, a3: m_hAPICall_high);
    LODWORD(this->m_CallbackOnLobbyCreated.m_hAPICall) = 0;
    HIDWORD(this->m_CallbackOnLobbyCreated.m_hAPICall) = 0;
  }
  CSysSessionBase::~CSysSessionBase(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002B290
// Name: protected: void CSysSessionHost::InitSessionProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionHost::InitSessionProperties(CSysSessionHost *this)
{
  ISteamMatchmaking *m_pSteamMatchmaking; // edi
  int Int; // eax
  KeyValues *Key; // eax

  if ( this->m_lobby.m_uiLobbyID != 0 )
  {
    m_pSteamMatchmaking = steamapicontext->m_pSteamMatchmaking;
    Int = KeyValues::GetInt(this: this->m_pSettings, keyName: "members/numSlots", defaultValue: 1);
    ((void (__thiscall *)(ISteamMatchmaking *, _DWORD, _DWORD, int))m_pSteamMatchmaking->SetLobbyMemberLimit)(
      a1: m_pSteamMatchmaking,
      a2: this->m_lobby.m_uiLobbyID,
      a3: HIDWORD(this->m_lobby.m_uiLobbyID),
      a4: Int);
  }
  Key = KeyValues::FindKey(this: this->m_pSettings, keyName: "members", bCreate: false);
  CSysSessionBase::LobbySetDataFromKeyValues(this, szPath: "members", key: Key, bRecurse: false);
  CSysSessionHost::UpdateSessionProperties(this, kv: (ELobbyType)this->m_pSettings);
}

//------------------------------------------------------------------------------
// Address: 0x1002B310
// Name: public: virtual CSysSessionClient::~CSysSessionClient(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionClient::~CSysSessionClient(CSysSessionClient *this)
{
  bool v2; // zf

  this->__vftable = (CSysSessionClient_vtbl *)&CSysSessionClient::`vftable';
  v2 = (this->m_CallbackOnLobbyEntered.m_nCallbackFlags & 1) == 0;
  this->m_CallbackOnLobbyEntered.__vftable = (CCallbackManual<CSysSessionClient,LobbyEnter_t,0>_vtbl *)&CCallback<CSysSessionClient,LobbyEnter_t,0>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnLobbyEntered);
  CSysSessionBase::~CSysSessionBase(this);
}

//------------------------------------------------------------------------------
// Address: 0x1002B340
// Name: protected: void CSysSessionClient::Process_ReplyJoinData_Our(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionClient::Process_ReplyJoinData_Our(CSysSessionClient *this, KeyValues *msg)
{
  KeyValues *Key; // edi
  char *String; // eax
  KeyValues *m_pSettings; // ecx
  const char *Name; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  KeyValues *Copy; // edi
  const char *szError; // [esp+14h] [ebp+8h]

  Key = KeyValues::FindKey(this: msg, keyName: "settings", bCreate: false);
  String = KeyValues::GetString(this: msg, keyName: "error", defaultValue: nullptr);
  szError = String;
  if ( Key == nullptr || String != nullptr )
  {
    this->m_eState = STATE_FAIL;
    Copy = KeyValues::MakeCopy(this: msg);
    KeyValues::SetName(this: Copy, setName: "mmF->SysSessionUpdate");
    KeyValues::SetPtr(this: Copy, keyName: "syssession", value: this);
    if ( szError == nullptr )
      KeyValues::SetString(this: Copy, keyName: "error", value: "n/a");
    this->OnSessionEvent(this, a2: Copy);
  }
  else
  {
    m_pSettings = this->m_pSettings;
    this->m_eState = 3;
    KeyValues::Clear(this: m_pSettings);
    Name = KeyValues::GetName(this: Key);
    KeyValues::SetName(this: this->m_pSettings, setName: Name);
    KeyValues::MergeFrom(this: this->m_pSettings, kvMerge: Key, eOp: MERGE_KV_UPDATE);
    this->Voice_ProcessTalkers(this, a2: nullptr, a3: true);
    this->Voice_UpdateMutelist(this);
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
    {
      v9 = KeyValues::KeyValues(this: v8, setName: "mmF->SysSessionUpdate");
      KeyValues::SetPtr(this: v9, keyName: "syssession", value: this);
      this->OnSessionEvent(this, a2: v9);
    }
    else
    {
      KeyValues::SetPtr(this: nullptr, keyName: "syssession", value: this);
      this->OnSessionEvent(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B480
// Name: protected: void CSysSessionClient::Process_ReplyJoinData_Other(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionClient::Process_ReplyJoinData_Other(CSysSessionClient *this, KeyValues *msg)
{
  CSysSessionClient *v2; // edi
  char *String; // ebx
  KeyValues *Key; // eax
  KeyValues *v5; // esi
  int Int; // ebx
  const char *Name; // eax
  CFmtStrN<256> *v8; // eax
  KeyValues *v9; // esi
  CFmtStrN<256> *v10; // eax
  KeyValues *v11; // edi
  unsigned __int64 Uint64; // kr00_8
  KeyValues *v13; // eax
  KeyValues *v14; // esi
  CFmtStrN<256> v15; // [esp+Ch] [ebp-238h] BYREF
  CFmtStrN<256> v16; // [esp+118h] [ebp-12Ch] BYREF
  unsigned __int64 xuid; // [esp+224h] [ebp-20h]
  KeyValues *kvMachine; // [esp+22Ch] [ebp-18h]
  KeyValues *pMembers; // [esp+230h] [ebp-14h]
  int numMachinesNew; // [esp+234h] [ebp-10h]
  int numPlayers; // [esp+238h] [ebp-Ch]
  int k; // [esp+23Ch] [ebp-8h]
  CSysSessionClient *v23; // [esp+240h] [ebp-4h]
  int j; // [esp+24Ch] [ebp+8h]

  v2 = this;
  v23 = this;
  String = KeyValues::GetString(this: msg, keyName: "error", defaultValue: nullptr);
  Key = KeyValues::FindKey(this: msg, keyName: "settings", bCreate: false);
  v5 = Key;
  if ( Key != nullptr && String == nullptr )
  {
    pMembers = KeyValues::FindKey(this: Key, keyName: "members", bCreate: false);
    if ( pMembers != nullptr )
    {
      Int = KeyValues::GetInt(this: v2->m_pSettings, keyName: "members/numMachines", defaultValue: 0);
      KeyValues::Clear(this: v2->m_pSettings);
      Name = KeyValues::GetName(this: v5);
      KeyValues::SetName(this: v2->m_pSettings, setName: Name);
      KeyValues::MergeFrom(this: v2->m_pSettings, kvMerge: v5, eOp: MERGE_KV_UPDATE);
      numMachinesNew = KeyValues::GetInt(this: v2->m_pSettings, keyName: "members/numMachines", defaultValue: 0);
      for ( k = Int; Int < numMachinesNew; k = Int )
      {
        v8 = CFmtStrN<256>::CFmtStrN<256>(this: &v16, pszFormat: "machine%d", Int);
        v9 = KeyValues::FindKey(this: pMembers, keyName: v8->m_szBuf, bCreate: false);
        kvMachine = v9;
        if ( v9 != nullptr )
        {
          v2->Voice_ProcessTalkers(this: v2, a2: v9, a3: true);
          numPlayers = KeyValues::GetInt(this: v9, keyName: "numPlayers", defaultValue: 0);
          j = 0;
          if ( numPlayers > 0 )
          {
            do
            {
              v10 = CFmtStrN<256>::CFmtStrN<256>(this: &v15, pszFormat: "player%d", j);
              v11 = KeyValues::FindKey(this: v9, keyName: v10->m_szBuf, bCreate: false);
              Uint64 = KeyValues::GetUint64(this: v11, keyName: "xuid", defaultValue: 0);
              HIDWORD(xuid) = HIDWORD(Uint64);
              if ( Uint64 != 0 )
              {
                v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
                if ( v13 != nullptr )
                  v14 = KeyValues::KeyValues(this: v13, setName: "OnPlayerUpdated");
                else
                  v14 = nullptr;
                KeyValues::SetString(this: v14, keyName: "state", value: "joined");
                KeyValues::SetUint64(this: v14, keyName: "xuid", value: __PAIR64__(HIDWORD(xuid), Uint64));
                KeyValues::SetPtr(this: v14, keyName: "player", value: v11);
                v23->OnSessionEvent(this: v23, a2: v14);
                v9 = kvMachine;
              }
              ++j;
            }
            while ( j < numPlayers );
            v2 = v23;
            Int = k;
          }
        }
        ++Int;
      }
      v2->Voice_UpdateMutelist(this: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B680
// Name: protected: void CSysSessionClient::Process_OnPlayerUpdated(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionClient::Process_OnPlayerUpdated(CSysSessionClient *this, KeyValues *msg)
{
  unsigned __int64 Uint64; // rax
  KeyValues *Player; // eax
  KeyValues *v5; // esi
  const char *Name; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // edi
  unsigned __int64 v9; // rax
  char chNameBuffer[64]; // [esp+Ch] [ebp-40h] BYREF

  Uint64 = KeyValues::GetUint64(this: msg, keyName: "xuid", defaultValue: 0);
  Player = SessionMembersFindPlayer(pSessionSettings: this->m_pSettings, xuidPlayer: Uint64, ppMachine: nullptr);
  v5 = Player;
  if ( Player != nullptr )
  {
    Name = KeyValues::GetName(this: Player);
    V_snprintf(pDest: chNameBuffer, maxLen: 64, pFormat: Name);
    KeyValues::Clear(this: v5);
    KeyValues::SetName(this: v5, setName: chNameBuffer);
    KeyValues::MergeFrom(this: v5, kvMerge: msg, eOp: MERGE_KV_UPDATE);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "OnPlayerUpdated");
    else
      v8 = nullptr;
    v9 = KeyValues::GetUint64(this: v5, keyName: "xuid", defaultValue: 0);
    KeyValues::SetUint64(this: v8, keyName: "xuid", value: v9);
    KeyValues::SetPtr(this: v8, keyName: "player", value: v5);
    this->OnSessionEvent(this, a2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B750
// Name: protected: void CSysSessionClient::Process_OnMachineUpdated(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionClient::Process_OnMachineUpdated(CSysSessionClient *this, KeyValues *msg)
{
  unsigned __int64 Uint64; // rax
  KeyValues *v4; // esi
  const char *Name; // eax
  char chNameBuffer[64]; // [esp+8h] [ebp-44h] BYREF
  KeyValues *pMachine; // [esp+48h] [ebp-4h] BYREF

  pMachine = nullptr;
  Uint64 = KeyValues::GetUint64(this: msg, keyName: "id", defaultValue: 0);
  SessionMembersFindPlayer(pSessionSettings: this->m_pSettings, xuidPlayer: Uint64, ppMachine: &pMachine);
  v4 = pMachine;
  if ( pMachine != nullptr )
  {
    Name = KeyValues::GetName(this: pMachine);
    V_snprintf(pDest: chNameBuffer, maxLen: 64, pFormat: Name);
    KeyValues::Clear(this: v4);
    KeyValues::SetName(this: v4, setName: chNameBuffer);
    KeyValues::MergeFrom(this: v4, kvMerge: msg, eOp: MERGE_KV_UPDATE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002B7D0
// Name: protected: CSysSessionBase::CSysSessionBase(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CSysSessionBase *__thiscall CSysSessionBase::CSysSessionBase(CSysSessionBase *this, KeyValues *pSettings)
{
  IPlayerLocal *v3; // eax

  this->__vftable = (CSysSessionBase_vtbl *)&CSysSessionBase::`vftable';
  this->m_CallbackOnLobbyChatMsg.m_nCallbackFlags = 0;
  this->m_CallbackOnLobbyChatMsg.m_iCallback = 0;
  this->m_CallbackOnLobbyChatMsg.m_pObj = nullptr;
  this->m_CallbackOnLobbyChatMsg.m_Func = nullptr;
  this->m_CallbackOnLobbyChatMsg.__vftable = (CCallbackManual<CSysSessionBase,LobbyChatMsg_t,0>_vtbl *)&CCallbackManual<CSysSessionBase,LobbyChatMsg_t,0>::`vftable';
  this->m_CallbackOnLobbyChatUpdate.m_nCallbackFlags = 0;
  this->m_CallbackOnLobbyChatUpdate.m_iCallback = 0;
  this->m_CallbackOnLobbyChatUpdate.m_pObj = nullptr;
  this->m_CallbackOnLobbyChatUpdate.m_Func = nullptr;
  this->m_CallbackOnLobbyChatUpdate.__vftable = (CCallbackManual<CSysSessionBase,LobbyChatUpdate_t,0>_vtbl *)&CCallbackManual<CSysSessionBase,LobbyChatUpdate_t,0>::`vftable';
  this->m_CallbackOnServersConnected.m_nCallbackFlags = 0;
  this->m_CallbackOnServersConnected.m_iCallback = 0;
  this->m_CallbackOnServersConnected.__vftable = (CCallback<CSysSessionBase,SteamServersConnected_t,0>_vtbl *)&CCallback<CSysSessionBase,SteamServersConnected_t,0>::`vftable';
  this->m_CallbackOnServersConnected.m_pObj = this;
  this->m_CallbackOnServersConnected.m_Func = (void (__thiscall *)(CSysSessionBase *, SteamServersConnected_t *))PlayerLocal::RecomputeXUID;
  if ( PlayerLocal::RecomputeXUID != nullptr )
  {
    this->m_CallbackOnServersConnected.m_pObj = this;
    this->m_CallbackOnServersConnected.m_Func = (void (__thiscall *)(CSysSessionBase *, SteamServersConnected_t *))PlayerLocal::RecomputeXUID;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackOnServersConnected, a2: 101);
  }
  this->m_CallbackOnServersDisconnected.m_nCallbackFlags = 0;
  this->m_CallbackOnServersDisconnected.m_iCallback = 0;
  this->m_CallbackOnServersDisconnected.__vftable = (CCallback<CSysSessionBase,SteamServersDisconnected_t,0>_vtbl *)&CCallback<CSysSessionBase,SteamServersDisconnected_t,0>::`vftable';
  this->m_CallbackOnServersDisconnected.m_pObj = this;
  this->m_CallbackOnServersDisconnected.m_Func = CSysSessionBase::Steam_OnServersDisconnected;
  if ( CSysSessionBase::Steam_OnServersDisconnected != nullptr )
  {
    this->m_CallbackOnServersDisconnected.m_pObj = this;
    this->m_CallbackOnServersDisconnected.m_Func = CSysSessionBase::Steam_OnServersDisconnected;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackOnServersDisconnected, a2: 103);
  }
  this->m_CallbackOnP2PSessionRequest.m_nCallbackFlags = 0;
  this->m_CallbackOnP2PSessionRequest.m_iCallback = 0;
  this->m_CallbackOnP2PSessionRequest.__vftable = (CCallback<CSysSessionBase,P2PSessionRequest_t,0>_vtbl *)&CCallback<CSysSessionBase,P2PSessionRequest_t,0>::`vftable';
  this->m_CallbackOnP2PSessionRequest.m_pObj = this;
  this->m_CallbackOnP2PSessionRequest.m_Func = CSysSessionBase::Steam_OnP2PSessionRequest;
  if ( CSysSessionBase::Steam_OnP2PSessionRequest != nullptr )
  {
    this->m_CallbackOnP2PSessionRequest.m_pObj = this;
    this->m_CallbackOnP2PSessionRequest.m_Func = CSysSessionBase::Steam_OnP2PSessionRequest;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackOnP2PSessionRequest, a2: 1202);
  }
  this->m_lobby.m_uiLobbyID = 0;
  *(_QWORD *)&this->m_lobby.m_eLobbyState = 0;
  this->m_pSettings = pSettings;
  this->m_Voice_flLastHeadsetStatusCheck = -1.0;
  v3 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
  this->m_xuidMachineId = v3->GetXUID(this: v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002B920
// Name: public: CSysSessionHost::CSysSessionHost(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CSysSessionHost *__thiscall CSysSessionHost::CSysSessionHost(CSysSessionHost *this, KeyValues *pSettings)
{
  CSysSessionBase::CSysSessionBase(this, pSettings);
  this->__vftable = (CSysSessionHost_vtbl *)&CSysSessionHost::`vftable';
  this->m_CallbackOnLobbyCreated.m_nCallbackFlags = 0;
  this->m_CallbackOnLobbyCreated.m_hAPICall = 0;
  this->m_CallbackOnLobbyCreated.m_pObj = nullptr;
  this->m_CallbackOnLobbyCreated.m_Func = nullptr;
  this->m_CallbackOnLobbyCreated.__vftable = (CCallResult<CSysSessionHost,LobbyCreated_t>_vtbl *)&CCallResult<CSysSessionHost,LobbyCreated_t>::`vftable';
  this->m_CallbackOnLobbyCreated.m_iCallback = 513;
  this->m_CallbackOnLobbyEntered.m_nCallbackFlags = 0;
  this->m_CallbackOnLobbyEntered.m_iCallback = 0;
  this->m_CallbackOnLobbyEntered.m_pObj = nullptr;
  this->m_CallbackOnLobbyEntered.m_Func = nullptr;
  this->m_CallbackOnLobbyEntered.__vftable = (CCallbackManual<CSysSessionHost,LobbyEnter_t,0>_vtbl *)&CCallbackManual<CSysSessionHost,LobbyEnter_t,0>::`vftable';
  this->m_eState = 0;
  this->m_flTimeOperationStarted = 0.0;
  this->m_flInitializeTimestamp = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002B9B0
// Name: public: CSysSessionClient::CSysSessionClient(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CSysSessionClient *__thiscall CSysSessionClient::CSysSessionClient(CSysSessionClient *this, KeyValues *pSettings)
{
  CSysSessionBase::CSysSessionBase(this, pSettings);
  this->__vftable = (CSysSessionClient_vtbl *)&CSysSessionClient::`vftable';
  this->m_CallbackOnLobbyEntered.m_nCallbackFlags = 0;
  this->m_CallbackOnLobbyEntered.m_iCallback = 0;
  this->m_CallbackOnLobbyEntered.m_pObj = nullptr;
  this->m_CallbackOnLobbyEntered.m_Func = nullptr;
  this->m_CallbackOnLobbyEntered.__vftable = (CCallbackManual<CSysSessionClient,LobbyEnter_t,0>_vtbl *)&CCallbackManual<CSysSessionClient,LobbyEnter_t,0>::`vftable';
  this->m_eState = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002BA50
// Name: protected: virtual void CSysSessionClient::ReceiveMessage(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionClient::ReceiveMessage(CSysSessionClient *this, KeyValues *msg)
{
  const char *Name; // ebx
  unsigned __int64 Uint64; // rax

  Name = KeyValues::GetName(this: msg);
  if ( this->m_eState == STATE_REQUESTING_JOIN_DATA )
  {
    if ( _V_stricmp(s1: Name, s2: "SysSession::ReplyJoinData") == 0
      && KeyValues::GetUint64(this: msg, keyName: "id", defaultValue: 0) == this->m_xuidMachineId )
    {
      CSysSessionClient::Process_ReplyJoinData_Our(this, msg);
    }
  }
  else
  {
    if ( this->m_eState != 3 )
      return;
    if ( _V_stricmp(s1: Name, s2: "SysSession::ReplyJoinData") == 0 )
    {
      CSysSessionClient::Process_ReplyJoinData_Other(this, msg);
      return;
    }
    if ( _V_stricmp(s1: Name, s2: "SysSession::OnPlayerRemoved") == 0 )
    {
      Uint64 = KeyValues::GetUint64(this: msg, keyName: "xuid", defaultValue: 0);
LABEL_7:
      CSysSessionBase::FindAndRemovePlayerFromMembers(this, xuid: Uint64);
      return;
    }
    if ( _V_stricmp(s1: Name, s2: "SysSession::OnPlayerKicked") != 0 )
    {
      if ( _V_stricmp(s1: Name, s2: "SysSession::OnPlayerUpdated") != 0 )
      {
        if ( _V_stricmp(s1: Name, s2: "SysSession::OnMachineUpdated") != 0 )
        {
          if ( _V_stricmp(s1: Name, s2: "SysSession::OnUpdate") != 0 )
          {
            CSysSessionBase::ReceiveMessage(this, msg);
          }
          else
          {
            KeyValues::MergeFrom(this: this->m_pSettings, kvMerge: msg, eOp: MERGE_KV_ALL);
            KeyValues::FindKey(this: msg, keyName: "update", bCreate: false);
            MatchSession_BroadcastSessionSettingsUpdate(pUpdateDeletePackage: msg);
          }
        }
        else
        {
          CSysSessionClient::Process_OnMachineUpdated(this, msg);
        }
      }
      else
      {
        CSysSessionClient::Process_OnPlayerUpdated(this, msg);
      }
    }
    else
    {
      Uint64 = KeyValues::GetUint64(this: msg, keyName: "xuid", defaultValue: 0);
      if ( Uint64 != this->m_xuidMachineId )
        goto LABEL_7;
      CSysSessionClient::Process_Kicked(this, msg);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002BBE0
// Name: public: void CSysSessionBase::ReplyLanSearch(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::ReplyLanSearch(CSysSessionBase *this, KeyValues *msg)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  IPlayerLocal *v5; // eax
  IPlayerLocal *v6; // edi
  const char *v7; // eax
  unsigned __int64 v8; // rax
  IMatchNetworkMsgController *v9; // eax
  char *String; // eax
  CUtlBuffer bufGameDetails; // [esp+Ch] [ebp-30h] BYREF

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "GameDetailsPlayer");
  else
    v4 = nullptr;
  KeyValues::SetUint64(this: v4, keyName: "options/sessionid", value: this->m_lobby.m_uiLobbyID);
  v5 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
  v6 = v5;
  if ( v5 != nullptr )
  {
    v7 = v5->GetName(this: v5);
    KeyValues::SetString(this: v4, keyName: "player/name", value: v7);
    v8 = v6->GetXUID(this: v6);
    KeyValues::SetUint64(this: v4, keyName: "player/xuid", value: v8);
  }
  CUtlBuffer::CUtlBuffer(this: &bufGameDetails, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::ActivateByteSwapping(this: &bufGameDetails, bActivate: true);
  v9 = g_pMatchFramework->GetMatchNetworkMsgController(this: g_pMatchFramework);
  v9->PackageGameDetailsForQOS(this: v9, a2: this->m_pSettings, a3: &bufGameDetails);
  KeyValues::SetPtr(this: v4, keyName: "binary/ptr", value: bufGameDetails.m_Memory.m_pMemory);
  KeyValues::SetInt(this: v4, keyName: "binary/size", value: bufGameDetails.m_nMaxPut);
  if ( msg != nullptr )
    String = KeyValues::GetString(this: msg, keyName: "from", defaultValue: nullptr);
  else
    String = nullptr;
  CConnectionlessLanMgr::SendPacket(this: g_pConnectionlessLanMgr, pMsg: v4, szAddress: String, eSock: NS_SOCK_CLIENT);
  if ( bufGameDetails.m_Memory.m_nGrowSize >= 0 )
  {
    if ( bufGameDetails.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufGameDetails.m_Memory.m_pMemory);
      bufGameDetails.m_Memory.m_pMemory = nullptr;
    }
    bufGameDetails.m_Memory.m_nAllocationCount = 0;
  }
  if ( v4 != nullptr )
    KeyValues::deleteThis(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1002BD20
// Name: protected: void CSysSessionBase::SendMessage(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::SendMessage(CSysSessionBase *this, KeyValues *msg)
{
  KeyValues *Key; // edi
  KeyValues *v4; // eax
  unsigned __int8 *Ptr; // edi
  int Int; // eax
  char *String; // eax
  const char *v8; // edi
  int v9; // edi
  int v10; // ebx
  unsigned int v11; // [esp-4h] [ebp-50h]
  CUtlBuffer buf; // [esp+Ch] [ebp-40h] BYREF
  CSteamID idRemote; // [esp+3Ch] [ebp-10h] BYREF
  int v14; // [esp+44h] [ebp-8h]
  EP2PSend eSendType; // [esp+48h] [ebp-4h]

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  CUtlBuffer::ActivateByteSwapping(this: &buf, bActivate: true);
  v11 = g_pMatchExtensions->m_exts.m_pINetSupport->GetEngineBuildNumber(this: g_pMatchExtensions->m_exts.m_pINetSupport);
  if ( (buf.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &buf, pFmt: "%d", v11);
  else
    CUtlBuffer::PutTypeBin<int>(this: &buf, src: v11);
  KeyValues::WriteAsBinary(this: msg, buffer: &buf);
  Key = KeyValues::FindKey(this: msg, keyName: "binary/ptr", bCreate: false);
  v4 = KeyValues::FindKey(this: msg, keyName: "binary/size", bCreate: false);
  eSendType = (EP2PSend)v4;
  if ( Key != nullptr && v4 != nullptr )
  {
    Ptr = (unsigned __int8 *)KeyValues::GetPtr(this: Key, keyName: nullptr, defaultValue: nullptr);
    Int = KeyValues::GetInt(this: (KeyValues *)eSendType, keyName: nullptr, defaultValue: 0);
    if ( Ptr != nullptr && Int != 0 )
      CUtlBuffer::Put(this: &buf, pMem: Ptr, size: Int);
  }
  if ( this->m_lobby.m_uiLobbyID != 0 )
  {
    String = KeyValues::GetString(this: msg, keyName: "p2p", defaultValue: nullptr);
    v8 = String;
    if ( String == nullptr )
    {
      ((void (__thiscall *)(ISteamMatchmaking *, _DWORD, _DWORD, unsigned __int8 *, int))steamapicontext->m_pSteamMatchmaking->SendLobbyChatMsg)(
        a1: steamapicontext->m_pSteamMatchmaking,
        a2: this->m_lobby.m_uiLobbyID,
        a3: HIDWORD(this->m_lobby.m_uiLobbyID),
        a4: buf.m_Memory.m_pMemory,
        a5: buf.m_nMaxPut);
      goto LABEL_23;
    }
    eSendType = k_EP2PSendUnreliableNoDelay;
    if ( _V_stricmp(s1: String, s2: "reliable") != 0 )
    {
      if ( _V_stricmp(s1: v8, s2: "buffer") != 0 )
      {
        if ( _V_stricmp(s1: v8, s2: "unreliable") == 0 )
          eSendType = k_EP2PSendUnreliable;
      }
      else
      {
        eSendType = k_EP2PSendReliableWithBuffering;
      }
    }
    else
    {
      eSendType = k_EP2PSendReliable;
    }
    v9 = 0;
    v10 = ((int (__thiscall *)(ISteamMatchmaking *, _DWORD, _DWORD))steamapicontext->m_pSteamMatchmaking->GetNumLobbyMembers)(
            a1: steamapicontext->m_pSteamMatchmaking,
            a2: this->m_lobby.m_uiLobbyID,
            a3: HIDWORD(this->m_lobby.m_uiLobbyID));
    v14 = v10;
    if ( v10 > 0 )
    {
      do
      {
        ((void (__thiscall *)(ISteamMatchmaking *, CSteamID *, _DWORD, _DWORD, int))steamapicontext->m_pSteamMatchmaking->GetLobbyMemberByIndex)(
          a1: steamapicontext->m_pSteamMatchmaking,
          a2: &idRemote,
          a3: this->m_lobby.m_uiLobbyID,
          a4: HIDWORD(this->m_lobby.m_uiLobbyID),
          a5: v9);
        if ( idRemote.m_steamid.m_comp != this->m_xuidMachineId )
        {
          ((void (__thiscall *)(ISteamNetworking *, _DWORD, _DWORD, unsigned __int8 *, int, EP2PSend, int))steamapicontext->m_pSteamNetworking->SendP2PPacket)(
            a1: steamapicontext->m_pSteamNetworking,
            a2: *(_DWORD *)&idRemote.m_steamid.m_comp,
            a3: *((_DWORD *)&idRemote.m_steamid.m_comp + 1),
            a4: buf.m_Memory.m_pMemory,
            a5: buf.m_nMaxPut,
            a6: eSendType,
            a7: 2);
          v10 = v14;
        }
        ++v9;
      }
      while ( v9 < v10 );
    }
  }
  this->ReceiveMessage(this, a2: msg);
LABEL_23:
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1002BF40
// Name: protected: void CSysSessionBase::UnpackAndReceiveMessage(void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::UnpackAndReceiveMessage(
        CSysSessionBase *this,
        unsigned __int8 *pvBuffer,
        void *numBytes)
{
  int v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  KeyValues *Key; // edi
  KeyValues *v7; // eax
  KeyValues *v8; // ebx
  int Int; // eax
  CUtlBuffer buf; // [esp+0h] [ebp-34h] BYREF
  CSysSessionBase *v11; // [esp+30h] [ebp-4h]
  void *pvData; // [esp+40h] [ebp+Ch]

  v11 = this;
  if ( (int)numBytes <= 0 )
    return;
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: pvBuffer, nSize: (int)numBytes, nFlags: 8u);
  CUtlBuffer::ActivateByteSwapping(this: &buf, bActivate: true);
  v3 = g_pMatchExtensions->m_exts.m_pINetSupport->GetEngineBuildNumber(this: g_pMatchExtensions->m_exts.m_pINetSupport);
  if ( CUtlBuffer::GetInt(this: &buf) == v3 )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: defaultValue);
    else
      v5 = nullptr;
    if ( !KeyValues::ReadAsBinary(this: v5, buffer: (int)&buf) )
    {
      if ( v5 != nullptr )
        KeyValues::deleteThis(this: v5);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        goto LABEL_21;
      return;
    }
    Key = KeyValues::FindKey(this: v5, keyName: "binary/ptr", bCreate: false);
    v7 = KeyValues::FindKey(this: v5, keyName: "binary/size", bCreate: false);
    v8 = v7;
    if ( Key != nullptr && v7 != nullptr )
    {
      pvData = KeyValues::GetPtr(this: Key, keyName: nullptr, defaultValue: nullptr);
      Int = KeyValues::GetInt(this: v8, keyName: nullptr, defaultValue: 0);
      if ( pvData != nullptr && Int != 0 )
      {
        CUtlBuffer::Get(this: &buf, pMem: chBuffer2, size: Int);
        KeyValues::SetPtr(this: Key, keyName: nullptr, value: chBuffer2);
      }
    }
    v11->ReceiveMessage(this: v11, a2: v5);
    if ( v5 != nullptr )
      KeyValues::deleteThis(this: v5);
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
LABEL_21:
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1002C0A0
// Name: public: void CSysSessionBase::Steam_OnLobbyChatMsg(struct LobbyChatMsg_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::Steam_OnLobbyChatMsg(CSysSessionBase *this, LobbyChatMsg_t *pLobbyChatMsg)
{
  int m_uiLobbyID; // edx
  int m_uiLobbyID_high; // edi
  unsigned int m_iChatID; // eax
  void *v6; // eax
  CSteamID steamIDSender; // [esp+Ch] [ebp-8h] BYREF

  m_uiLobbyID = this->m_lobby.m_uiLobbyID;
  m_uiLobbyID_high = HIDWORD(this->m_lobby.m_uiLobbyID);
  if ( LODWORD(pLobbyChatMsg->m_ulSteamIDLobby) == m_uiLobbyID
    && HIDWORD(pLobbyChatMsg->m_ulSteamIDLobby) == m_uiLobbyID_high )
  {
    m_iChatID = pLobbyChatMsg->m_iChatID;
    steamIDSender.m_steamid.m_comp = 0;
    v6 = (void *)((int (__thiscall *)(ISteamMatchmaking *, int, int, unsigned int, CSteamID *, unsigned __int8 *, int, LobbyChatMsg_t **))steamapicontext->m_pSteamMatchmaking->GetLobbyChatEntry)(
                   a1: steamapicontext->m_pSteamMatchmaking,
                   a2: m_uiLobbyID,
                   a3: m_uiLobbyID_high,
                   a4: m_iChatID,
                   a5: &steamIDSender,
                   a6: chBuffer,
                   a7: 4096,
                   a8: &pLobbyChatMsg);
    CSysSessionBase::UnpackAndReceiveMessage(this, pvBuffer: chBuffer, numBytes: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C110
// Name: protected: virtual void CSysSessionBase::Voice_CaptureAndTransmitLocalVoiceData(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSysSessionBase::Voice_CaptureAndTransmitLocalVoiceData(CSysSessionBase *this@<ecx>, int a2@<esi>)
{
  IEngineVoice *m_pIEngineVoice; // esi
  int v4; // ebx
  IMatchTitle *v5; // eax
  void (__thiscall *GetVoiceData)(IEngineVoice *, int, const unsigned __int8 **, unsigned int *); // edx
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  IPlayerLocal *v9; // eax
  unsigned __int64 v10; // rax
  unsigned int v11; // edi
  IEngineVoice *v; // [esp+8h] [ebp-Ch]
  const unsigned __int8 *pbVoiceData; // [esp+Ch] [ebp-8h] BYREF
  unsigned int numBytes; // [esp+10h] [ebp-4h] BYREF

  if ( ((unsigned __int8 (__fastcall *)(CSysSessionBase *))this->IsServiceSession)(a1: this) == 0 )
  {
    m_pIEngineVoice = g_pMatchExtensions->m_exts.m_pIEngineVoice;
    v4 = 0;
    v = m_pIEngineVoice;
    if ( m_pIEngineVoice != nullptr )
    {
      v5 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
      if ( ((v5->GetTitleSettingsFlags(this: v5) & 0x20) == 0 || this->m_lobby.m_eLobbyState == STATE_DEFAULT)
        && m_pIEngineVoice->VoiceUpdateData(this: m_pIEngineVoice, a2: 0) )
      {
        GetVoiceData = m_pIEngineVoice->GetVoiceData;
        pbVoiceData = nullptr;
        numBytes = 0;
        ((void (__thiscall *)(IEngineVoice *, _DWORD, const unsigned __int8 **, unsigned int *, int))GetVoiceData)(
          a1: m_pIEngineVoice,
          a2: 0,
          a3: &pbVoiceData,
          a4: &numBytes,
          a5: a2);
        if ( mm_session_voice_loading.m_pParent != nullptr && mm_session_voice_loading.m_pParent->m_Value.m_nValue != 0
          || !g_pMatchExtensions->m_exts.m_pIVEngineClient->IsDrawingLoadingImage(this: g_pMatchExtensions->m_exts.m_pIVEngineClient)
          && !g_pMatchExtensions->m_exts.m_pIVEngineClient->IsTransitioningToLoad(this: g_pMatchExtensions->m_exts.m_pIVEngineClient) )
        {
          v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v7 != nullptr )
            v8 = KeyValues::KeyValues(this: v7, setName: "SysSession::Voice");
          else
            v8 = nullptr;
          KeyValues::SetString(this: v8, keyName: "p2p", value: "nodelay");
          v9 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
          v10 = v9->GetXUID(this: v9);
          KeyValues::SetUint64(this: v8, keyName: "xuid", value: v10);
          v11 = numBytes;
          while ( v11 != 0 )
          {
            numBytes = 1024;
            if ( v11 <= 0x400 )
              numBytes = v11;
            KeyValues::SetPtr(this: v8, keyName: "binary/ptr", value: (void *)&pbVoiceData[v4]);
            KeyValues::SetInt(this: v8, keyName: "binary/size", value: numBytes);
            v11 -= numBytes;
            v4 += numBytes;
            CSysSessionBase::SendMessage(this, msg: v8);
          }
          if ( v8 != nullptr )
            KeyValues::deleteThis(this: v8);
          m_pIEngineVoice = v;
        }
        m_pIEngineVoice->VoiceResetLocalData(this: m_pIEngineVoice, a2: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C2A0
// Name: protected: virtual void CSysSessionBase::Voice_UpdateLocalHeadsetsStatus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::Voice_UpdateLocalHeadsetsStatus(CSysSessionBase *this)
{
  KeyValues *v2; // esi
  bool v3; // bl
  CFmtStrN<256> *v4; // eax
  char *String; // eax
  bool v6; // zf
  const char *v7; // ebx
  KeyValues *v8; // eax
  KeyValues *v9; // esi
  CFmtStrN<256> *v10; // eax
  unsigned __int64 Uint64; // rax
  KeyValues *m_pSettings; // [esp-14h] [ebp-128h]
  unsigned __int64 m_xuidMachineId; // [esp-10h] [ebp-124h]
  CFmtStrN<256> v14; // [esp+4h] [ebp-110h] BYREF
  KeyValues *pMachine; // [esp+110h] [ebp-4h] BYREF

  if ( !this->IsServiceSession(this)
    && this->m_Voice_flLastHeadsetStatusCheck >= 0.0
    && _Plat_FloatTime() - this->m_Voice_flLastHeadsetStatusCheck >= 1.0 )
  {
    this->m_Voice_flLastHeadsetStatusCheck = _Plat_FloatTime();
    m_xuidMachineId = this->m_xuidMachineId;
    m_pSettings = this->m_pSettings;
    pMachine = nullptr;
    SessionMembersFindPlayer(pSessionSettings: m_pSettings, xuidPlayer: m_xuidMachineId, ppMachine: &pMachine);
    v2 = pMachine;
    if ( pMachine != nullptr )
    {
      v3 = g_pMatchExtensions->m_exts.m_pIEngineVoice->IsHeadsetPresent(
             this: g_pMatchExtensions->m_exts.m_pIEngineVoice,
             a2: 0);
      v4 = CFmtStrN<256>::CFmtStrN<256>(this: &v14, pszFormat: "player%d/voice", 0);
      String = KeyValues::GetString(this: v2, keyName: v4->m_szBuf, defaultValue: defaultValue);
      v6 = !v3;
      v7 = "headset";
      if ( v6 )
        v7 = defaultValue;
      if ( *String != *v7 )
      {
        v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v8 != nullptr )
          v9 = KeyValues::KeyValues(this: v8, setName: "SysSession::VoiceStatus");
        else
          v9 = nullptr;
        v10 = CFmtStrN<256>::CFmtStrN<256>(this: &v14, pszFormat: "player%d/xuid", 0);
        Uint64 = KeyValues::GetUint64(this: pMachine, keyName: v10->m_szBuf, defaultValue: 0);
        KeyValues::SetUint64(this: v9, keyName: "xuid", value: Uint64);
        KeyValues::SetString(this: v9, keyName: "voice", value: v7);
        CSysSessionBase::SendMessage(this, msg: v9);
        if ( v9 != nullptr )
          KeyValues::deleteThis(this: v9);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C3F0
// Name: public: virtual void CSysSessionBase::Voice_UpdateMutelist(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::Voice_UpdateMutelist(CSysSessionBase *this)
{
  CSysSessionBase *v1; // ebx
  bool (__thiscall *IsServiceSession)(CSysSessionBase *); // edx
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  KeyValues *m_pSettings; // ecx
  KeyValues *Key; // eax
  KeyValues *v7; // esi
  int v8; // ebx
  CFmtStrN<256> *v9; // eax
  unsigned __int64 Uint64; // rax
  unsigned int v11; // edi
  unsigned int v12; // esi
  CFmtStrN<256> *v13; // eax
  KeyValues *v14; // esi
  KeyValues *v15; // eax
  KeyValues *v16; // edi
  KeyValues *FirstValue; // esi
  unsigned __int64 v18; // kr00_8
  unsigned __int64 v19; // rax
  KeyValues *NextValue; // eax
  KeyValues *v21; // [esp-18h] [ebp-13Ch]
  unsigned __int64 m_xuidMachineId; // [esp-14h] [ebp-138h]
  CFmtStrN<256> v23; // [esp+4h] [ebp-120h] BYREF
  int numMachines; // [esp+114h] [ebp-10h]
  KeyValues *pMembers; // [esp+118h] [ebp-Ch] BYREF
  CSysSessionBase *v26; // [esp+11Ch] [ebp-8h]
  KeyValues *msg; // [esp+120h] [ebp-4h]

  v1 = this;
  IsServiceSession = this->IsServiceSession;
  v26 = this;
  if ( ((unsigned __int8 (__fastcall *)(CSysSessionBase *))IsServiceSession)(a1: this) != 0 )
    return;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "SysSession::VoiceMutelist");
    msg = v4;
  }
  else
  {
    msg = nullptr;
    v4 = nullptr;
  }
  KeyValues::SetUint64(this: v4, keyName: "xuid", value: v1->m_xuidMachineId);
  m_pSettings = v1->m_pSettings;
  if ( m_pSettings != nullptr )
  {
    Key = KeyValues::FindKey(this: m_pSettings, keyName: "members", bCreate: false);
    v7 = Key;
    pMembers = Key;
    if ( Key != nullptr )
    {
      v8 = 0;
      numMachines = KeyValues::GetInt(this: Key, keyName: "numMachines", defaultValue: 0);
      if ( numMachines > 0 )
      {
        while ( 1 )
        {
          v9 = CFmtStrN<256>::CFmtStrN<256>(this: &v23, pszFormat: "machine%d/id", v8);
          Uint64 = KeyValues::GetUint64(this: v7, keyName: v9->m_szBuf, defaultValue: 0);
          v11 = HIDWORD(Uint64);
          v12 = Uint64;
          if ( ((unsigned __int8 (__thiscall *)(CMatchVoice *, _DWORD, _DWORD))g_pMatchVoice->IsMachineMuted)(
                 a1: g_pMatchVoice,
                 a2: Uint64,
                 a3: HIDWORD(Uint64)) != 0 )
          {
            v13 = CFmtStrN<256>::CFmtStrN<256>(this: &v23, pszFormat: "Mutelist/%d", v8);
            KeyValues::SetUint64(this: msg, keyName: v13->m_szBuf, value: __PAIR64__(v11, v12));
          }
          if ( ++v8 >= numMachines )
            break;
          v7 = pMembers;
        }
      }
      v4 = msg;
      v1 = v26;
    }
  }
  m_xuidMachineId = v1->m_xuidMachineId;
  v21 = v1->m_pSettings;
  pMembers = nullptr;
  SessionMembersFindPlayer(pSessionSettings: v21, xuidPlayer: m_xuidMachineId, ppMachine: &pMembers);
  if ( pMembers != nullptr )
  {
    v14 = KeyValues::FindKey(this: pMembers, keyName: "Mutelist", bCreate: false);
    v15 = KeyValues::FindKey(this: v4, keyName: "Mutelist", bCreate: false);
    v16 = v15;
    if ( v14 != nullptr )
    {
      if ( v15 == nullptr )
      {
LABEL_27:
        v4 = msg;
        goto LABEL_28;
      }
      FirstValue = KeyValues::GetFirstValue(this: v14);
      v16 = KeyValues::GetFirstValue(this: v16);
      if ( FirstValue != nullptr )
      {
        while ( v16 != nullptr )
        {
          v18 = KeyValues::GetUint64(this: v16, keyName: nullptr, defaultValue: 0);
          numMachines = HIDWORD(v18);
          v19 = KeyValues::GetUint64(this: FirstValue, keyName: nullptr, defaultValue: 0);
          if ( v19 != __PAIR64__(numMachines, v18) )
          {
            v1 = v26;
            goto LABEL_27;
          }
          FirstValue = KeyValues::GetNextValue(this: FirstValue);
          NextValue = KeyValues::GetNextValue(this: v16);
          v1 = v26;
          v16 = NextValue;
          if ( FirstValue == nullptr )
            goto LABEL_24;
        }
        goto LABEL_27;
      }
    }
LABEL_24:
    if ( v16 == nullptr )
    {
      if ( msg != nullptr )
        KeyValues::deleteThis(this: msg);
      return;
    }
    goto LABEL_27;
  }
LABEL_28:
  CSysSessionBase::SendMessage(this: v1, msg: v4);
  if ( v4 != nullptr )
    KeyValues::deleteThis(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1002C600
// Name: public: CSysSessionHost::CSysSessionHost(class CSysSessionClient __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CSysSessionHost *__thiscall CSysSessionHost::CSysSessionHost(
        CSysSessionHost *this,
        CSysSessionClient *pClient,
        KeyValues *pSettings)
{
  KeyValues *v4; // ebx
  KeyValues *Key; // eax
  KeyValues *v6; // eax

  CSysSessionBase::CSysSessionBase(this, pSettings);
  this->__vftable = (CSysSessionHost_vtbl *)&CSysSessionHost::`vftable';
  this->m_CallbackOnLobbyCreated.__vftable = (CCallResult<CSysSessionHost,LobbyCreated_t>_vtbl *)&CCallResult<CSysSessionHost,LobbyCreated_t>::`vftable';
  this->m_CallbackOnLobbyCreated.m_iCallback = 513;
  v4 = nullptr;
  this->m_CallbackOnLobbyCreated.m_nCallbackFlags = 0;
  this->m_CallbackOnLobbyCreated.m_hAPICall = 0;
  this->m_CallbackOnLobbyCreated.m_pObj = nullptr;
  this->m_CallbackOnLobbyCreated.m_Func = nullptr;
  this->m_CallbackOnLobbyEntered.m_nCallbackFlags = 0;
  this->m_CallbackOnLobbyEntered.m_iCallback = 0;
  this->m_CallbackOnLobbyEntered.m_pObj = nullptr;
  this->m_CallbackOnLobbyEntered.m_Func = nullptr;
  this->m_CallbackOnLobbyEntered.__vftable = (CCallbackManual<CSysSessionHost,LobbyEnter_t,0>_vtbl *)&CCallbackManual<CSysSessionHost,LobbyEnter_t,0>::`vftable';
  this->m_eState = STATE_REQUESTING_JOIN_DATA;
  this->m_flTimeOperationStarted = 0.0;
  this->m_flInitializeTimestamp = 0.0;
  this->m_lobby = pClient->m_lobby;
  this->m_Voice_flLastHeadsetStatusCheck = pClient->m_Voice_flLastHeadsetStatusCheck;
  if ( CSysSessionBase::Steam_OnLobbyChatMsg != nullptr )
  {
    if ( (this->m_CallbackOnLobbyChatMsg.m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnLobbyChatMsg);
    this->m_CallbackOnLobbyChatMsg.m_pObj = this;
    this->m_CallbackOnLobbyChatMsg.m_Func = CSysSessionBase::Steam_OnLobbyChatMsg;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackOnLobbyChatMsg, a2: 507);
  }
  if ( CSysSessionBase::Steam_OnLobbyChatUpdate != nullptr )
  {
    if ( (this->m_CallbackOnLobbyChatUpdate.m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnLobbyChatUpdate);
    this->m_CallbackOnLobbyChatUpdate.m_pObj = this;
    this->m_CallbackOnLobbyChatUpdate.m_Func = CSysSessionBase::Steam_OnLobbyChatUpdate;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackOnLobbyChatUpdate, a2: 506);
  }
  Key = KeyValues::FindKey(this: this->m_pSettings, keyName: "members", bCreate: false);
  CSysSessionBase::LobbySetDataFromKeyValues(this, szPath: "members", key: Key, bRecurse: false);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v4 = KeyValues::KeyValues(this: v6, setName: "OnPlayerLeaderChanged");
  KeyValues::SetString(this: v4, keyName: "state", value: "host");
  KeyValues::SetUint64(this: v4, keyName: "xuid", value: this->m_xuidMachineId);
  this->OnSessionEvent(this, a2: v4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002C790
// Name: public: void CSysSessionHost::KickPlayer(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionHost::KickPlayer(CSysSessionHost *this, KeyValues *pCommand)
{
  unsigned __int64 Uint64; // rax
  unsigned __int64 v4; // kr00_8
  int v5; // edx
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  KeyValues *m_pSettings; // [esp-10h] [ebp-1Ch]

  Uint64 = KeyValues::GetUint64(this: pCommand, keyName: "xuid", defaultValue: 0);
  m_pSettings = this->m_pSettings;
  pCommand = nullptr;
  SessionMembersFindPlayer(pSessionSettings: m_pSettings, xuidPlayer: Uint64, ppMachine: &pCommand);
  if ( pCommand != nullptr )
  {
    v4 = KeyValues::GetUint64(this: pCommand, keyName: "id", defaultValue: 0);
    if ( (_DWORD)v4 == ((int (__thiscall *)(CSysSessionHost *, _DWORD, _DWORD))this->GetHostXuid)(
                         a1: this,
                         a2: 0,
                         a3: 0)
      && HIDWORD(v4) == v5 )
    {
      DevWarning(a1: "CSysSessionHost::Kick unsupported for host xuid!\n");
    }
    else
    {
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "SysSession::OnPlayerKicked");
      else
        v7 = nullptr;
      KeyValues::SetUint64(this: v7, keyName: "xuid", value: v4);
      CSysSessionBase::SendMessage(this, msg: v7);
      CSysSessionBase::FindAndRemovePlayerFromMembers(this, xuid: v4);
      if ( v7 != nullptr )
        KeyValues::deleteThis(this: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C870
// Name: public: void CSysSessionHost::OnUpdateSessionSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionHost::OnUpdateSessionSettings(CSysSessionHost *this, KeyValues *kv)
{
  KeyValues *Key; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  KeyValues *v6; // eax
  KeyValues *Copy; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // eax

  Key = KeyValues::FindKey(this: kv, keyName: "update", bCreate: false);
  CSysSessionHost::UpdateSessionProperties(this, kv: (ELobbyType)Key);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SysSession::OnUpdate");
  else
    v5 = nullptr;
  v6 = KeyValues::FindKey(this: kv, keyName: "update", bCreate: false);
  if ( v6 != nullptr )
  {
    Copy = KeyValues::MakeCopy(this: v6);
    KeyValues::AddSubKey(this: v5, pSubkey: Copy);
  }
  v8 = KeyValues::FindKey(this: kv, keyName: "delete", bCreate: false);
  if ( v8 != nullptr )
  {
    v9 = KeyValues::MakeCopy(this: v8);
    KeyValues::AddSubKey(this: v5, pSubkey: v9);
  }
  CSysSessionBase::SendMessage(this, msg: v5);
  if ( v5 != nullptr )
    KeyValues::deleteThis(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1002C910
// Name: public: void CSysSessionHost::OnPlayerUpdated(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionHost::OnPlayerUpdated(CSysSessionHost *this, KeyValues *pPlayer)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  unsigned __int64 Uint64; // rax
  KeyValues *v6; // eax
  KeyValues *v7; // esi

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "OnPlayerUpdated");
  else
    v4 = nullptr;
  Uint64 = KeyValues::GetUint64(this: pPlayer, keyName: "xuid", defaultValue: 0);
  KeyValues::SetUint64(this: v4, keyName: "xuid", value: Uint64);
  KeyValues::SetPtr(this: v4, keyName: "player", value: pPlayer);
  this->OnSessionEvent(this, a2: v4);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "SysSession::OnPlayerUpdated");
  else
    v7 = nullptr;
  KeyValues::MergeFrom(this: v7, kvMerge: pPlayer, eOp: MERGE_KV_UPDATE);
  CSysSessionBase::SendMessage(this, msg: v7);
  if ( v7 != nullptr )
    KeyValues::deleteThis(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1002C9C0
// Name: protected: virtual void CSysSessionHost::OnPlayerLeave(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionHost::OnPlayerLeave(CSysSessionHost *this, unsigned __int64 xuid)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // esi

  if ( CSysSessionBase::FindAndRemovePlayerFromMembers(this, xuid) != 0 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "SysSession::OnPlayerRemoved");
    else
      v4 = nullptr;
    KeyValues::SetUint64(this: v4, keyName: "xuid", value: xuid);
    CSysSessionBase::SendMessage(this, msg: v4);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
    {
      v6 = KeyValues::KeyValues(this: v5, setName: "OnPlayerMachinesDisconnected");
      v7 = v6;
      if ( v6 != nullptr )
      {
        KeyValues::SetInt(this: v6, keyName: "numMachines", value: 1);
        KeyValues::SetUint64(this: v7, keyName: "id", value: xuid);
        this->OnSessionEvent(this, a2: v7);
      }
    }
    if ( v4 != nullptr )
      KeyValues::deleteThis(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CA80
// Name: protected: void CSysSessionHost::Steam_OnLobbyEntered(struct LobbyEnter_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionHost::Steam_OnLobbyEntered(CSysSessionHost *this, LobbyEnter_t *pLobbyEnter)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  const char *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // edi

  if ( LODWORD(pLobbyEnter->m_ulSteamIDLobby) == LODWORD(this->m_lobby.m_uiLobbyID)
    && HIDWORD(pLobbyEnter->m_ulSteamIDLobby) == HIDWORD(this->m_lobby.m_uiLobbyID) )
  {
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnLobbyEntered);
    if ( pLobbyEnter->m_EChatRoomEnterResponse == 1 )
    {
      CSysSessionHost::InitSessionProperties(this);
      if ( CSysSessionBase::Steam_OnLobbyChatMsg != nullptr )
      {
        if ( (this->m_CallbackOnLobbyChatMsg.m_nCallbackFlags & 1) != 0 )
          _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnLobbyChatMsg);
        this->m_CallbackOnLobbyChatMsg.m_pObj = this;
        this->m_CallbackOnLobbyChatMsg.m_Func = CSysSessionBase::Steam_OnLobbyChatMsg;
        _SteamAPI_RegisterCallback(a1: &this->m_CallbackOnLobbyChatMsg, a2: 507);
      }
      if ( CSysSessionBase::Steam_OnLobbyChatUpdate != nullptr )
      {
        if ( (this->m_CallbackOnLobbyChatUpdate.m_nCallbackFlags & 1) != 0 )
          _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnLobbyChatUpdate);
        this->m_CallbackOnLobbyChatUpdate.m_pObj = this;
        this->m_CallbackOnLobbyChatUpdate.m_Func = CSysSessionBase::Steam_OnLobbyChatUpdate;
        _SteamAPI_RegisterCallback(a1: &this->m_CallbackOnLobbyChatUpdate, a2: 506);
      }
      this->Voice_ProcessTalkers(this, a2: nullptr, a3: true);
      this->m_eState = STATE_REQUESTING_JOIN_DATA;
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "mmF->SysSessionUpdate");
      else
        v7 = nullptr;
      KeyValues::SetPtr(this: v7, keyName: "syssession", value: this);
      ((void (__thiscall *)(CSysSessionHost *))this->OnSessionEvent)(a1: this);
    }
    else
    {
      _Warning(a1: "Matchmaking: lobby response %d!\n", pLobbyEnter->m_EChatRoomEnterResponse);
      this->m_eState = 3;
      v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v3 != nullptr )
        v4 = KeyValues::KeyValues(this: v3, setName: "mmF->SysSessionUpdate");
      else
        v4 = nullptr;
      KeyValues::SetPtr(this: v4, keyName: "syssession", value: this);
      switch ( pLobbyEnter->m_EChatRoomEnterResponse )
      {
        case 2u:
        case 3u:
        case 6u:
          v5 = "n/a";
          break;
        case 4u:
          v5 = "full";
          break;
        default:
          v5 = "create";
          break;
      }
      KeyValues::SetString(this: v4, keyName: "error", value: v5);
      ((void (__thiscall *)(CSysSessionHost *))this->OnSessionEvent)(a1: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002CC20
// Name: protected: bool CSysSessionHost::Process_RequestJoinData(unsigned __int64,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSysSessionHost::Process_RequestJoinData(
        CSysSessionHost *this,
        unsigned __int64 xuidClient,
        KeyValues *pSettings)
{
  KeyValues *v3; // esi
  KeyValues *Int; // eax
  KeyValues *m_pSettings; // ecx
  int v9; // eax
  KeyValues *v10; // ecx
  char *String; // eax
  KeyValues *v12; // eax
  int m_numHumanPlayers; // eax
  KeyValues *Key; // ebx
  int v15; // esi
  CFmtStrN<256> *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // ebx
  unsigned __int64 Uint64; // kr00_8
  char *v20; // eax
  KeyValues *v21; // ecx
  int i; // esi
  CFmtStrN<256> *v23; // eax
  KeyValues *v24; // eax
  KeyValues *Copy; // ebx
  CFmtStrN<256> *v26; // eax
  KeyValues *v27; // esi
  unsigned __int64 v28; // rax
  KeyValues *v29; // eax
  KeyValues *v30; // eax
  KeyValues *v31; // esi
  CFmtStrN<256> *v32; // eax
  KeyValues *v33; // eax
  KeyValues *v34; // esi
  int v35; // eax
  int v36; // ecx
  CFmtStrN<256> *v37; // eax
  KeyValues *v38; // ebx
  KeyValues *v39; // eax
  KeyValues *v40; // eax
  KeyValues *v41; // esi
  KeyValues *v42; // eax
  KeyValues *v43; // esi
  KeyValues *v44; // eax
  const char *v45; // [esp-8h] [ebp-264h]
  CFmtStrN<256> v46; // [esp+8h] [ebp-254h] BYREF
  CFmtStrN<256> v47; // [esp+114h] [ebp-148h] BYREF
  INetSupport::ClientInfo_t nsci; // [esp+220h] [ebp-3Ch] BYREF
  int numMachinesCurrent; // [esp+230h] [ebp-2Ch]
  int numUsersConnecting; // [esp+234h] [ebp-28h]
  int numUsersCurrent; // [esp+238h] [ebp-24h]
  KeyValues *kvConnecting; // [esp+23Ch] [ebp-20h]
  KeyValues *pMembersConnecting; // [esp+240h] [ebp-1Ch]
  int numPlayers; // [esp+244h] [ebp-18h]
  int j; // [esp+248h] [ebp-14h]
  unsigned __int64 xuid; // [esp+24Ch] [ebp-10h]
  KeyValues *reply; // [esp+254h] [ebp-8h]
  KeyValues *pMembers; // [esp+258h] [ebp-4h]
  int xuidClient_4; // [esp+268h] [ebp+Ch]
  int numMachinesConnecting; // [esp+26Ch] [ebp+10h]

  v3 = nullptr;
  if ( SessionMembersFindPlayer(pSessionSettings: this->m_pSettings, xuidPlayer: xuidClient, ppMachine: nullptr) != nullptr )
    return 1;
  numUsersConnecting = KeyValues::GetInt(this: pSettings, keyName: "members/numPlayers", defaultValue: 0);
  numMachinesConnecting = KeyValues::GetInt(this: pSettings, keyName: "members/numMachines", defaultValue: 0);
  Int = (KeyValues *)KeyValues::GetInt(this: this->m_pSettings, keyName: "members/numSlots", defaultValue: 0);
  m_pSettings = this->m_pSettings;
  pMembers = Int;
  v9 = KeyValues::GetInt(this: m_pSettings, keyName: "members/numPlayers", defaultValue: 0);
  v10 = this->m_pSettings;
  numUsersCurrent = v9;
  numMachinesCurrent = KeyValues::GetInt(this: v10, keyName: "members/numMachines", defaultValue: 0);
  memset(&nsci, 0, sizeof(nsci));
  g_pMatchExtensions->m_exts.m_pINetSupport->GetClientInfo(this: g_pMatchExtensions->m_exts.m_pINetSupport, a2: &nsci);
  if ( nsci.m_numHumanPlayers != 0 )
  {
    String = KeyValues::GetString(this: this->m_pSettings, keyName: "system/netflag", defaultValue: defaultValue);
    if ( _V_stricmp(s1: String, s2: "teamlobby") == 0 )
      nsci.m_numHumanPlayers = 0;
  }
  v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v12 != nullptr )
    v3 = KeyValues::KeyValues(this: v12, setName: "SysSession::ReplyJoinData");
  reply = v3;
  KeyValues::SetUint64(this: v3, keyName: "id", value: xuidClient);
  if ( numUsersConnecting == 0
    || numMachinesConnecting == 0
    || pMembers == nullptr
    || numUsersCurrent == 0
    || numMachinesCurrent == 0 )
  {
    v45 = "n/a";
LABEL_52:
    KeyValues::SetString(this: v3, keyName: "error", value: v45);
LABEL_53:
    CSysSessionBase::SendMessage(this, msg: v3);
    goto LABEL_54;
  }
  if ( *KeyValues::GetString(this: this->m_pSettings, keyName: "system/lock", defaultValue: defaultValue) != 0 )
  {
    v45 = "lock";
    goto LABEL_52;
  }
  m_numHumanPlayers = nsci.m_numHumanPlayers;
  if ( numUsersCurrent > nsci.m_numHumanPlayers )
    m_numHumanPlayers = numUsersCurrent;
  if ( numUsersConnecting + m_numHumanPlayers > (int)pMembers )
  {
    v45 = "full";
    goto LABEL_52;
  }
  pMembers = KeyValues::FindKey(this: this->m_pSettings, keyName: "members", bCreate: false);
  if ( pMembers == nullptr
    || (Key = KeyValues::FindKey(this: pSettings, keyName: "members", bCreate: false),
        pMembersConnecting = Key,
        Key == nullptr) )
  {
LABEL_54:
    if ( v3 != nullptr )
      KeyValues::deleteThis(this: v3);
    return 0;
  }
  v15 = 0;
  for ( numPlayers = 0; v15 < numMachinesConnecting; numPlayers = ++v15 )
  {
    v16 = CFmtStrN<256>::CFmtStrN<256>(this: &v47, pszFormat: "machine%d", v15);
    v17 = KeyValues::FindKey(this: Key, keyName: v16->m_szBuf, bCreate: false);
    v18 = v17;
    if ( v17 != nullptr )
    {
      kvConnecting = (KeyValues *)KeyValues::GetString(this: v17, keyName: "tuver", defaultValue: defaultValue);
      Uint64 = KeyValues::GetUint64(this: v18, keyName: "dlcmask", defaultValue: 0);
      v20 = KeyValues::GetString(this: pMembers, keyName: "machine0/tuver", defaultValue: defaultValue);
      v21 = this->m_pSettings;
      j = (int)v20;
      xuid = KeyValues::GetUint64(this: v21, keyName: "game/dlcrequired", defaultValue: 0);
      if ( _V_strcmp(s1: (const char *)kvConnecting, s2: (const char *)j) != 0 )
      {
        v3 = reply;
        KeyValues::SetString(this: reply, keyName: "error", value: "turequired");
        KeyValues::SetString(this: v3, keyName: "turequired", value: (const char *)j);
        goto LABEL_53;
      }
      if ( (Uint64 & xuid) != xuid )
      {
        KeyValues::SetString(this: reply, keyName: "error", value: "dlcrequired");
        v3 = reply;
        KeyValues::SetUint64(this: reply, keyName: "dlcrequired", value: xuid & ~Uint64);
        KeyValues::SetUint64(this: v3, keyName: "dlcmask", value: xuid);
        goto LABEL_53;
      }
      v15 = numPlayers;
    }
    Key = pMembersConnecting;
  }
  for ( i = 0; i < numMachinesConnecting; ++i )
  {
    v23 = CFmtStrN<256>::CFmtStrN<256>(this: &v47, pszFormat: "machine%d", i);
    v24 = KeyValues::FindKey(this: Key, keyName: v23->m_szBuf, bCreate: false);
    if ( v24 != nullptr )
    {
      Copy = KeyValues::MakeCopy(this: v24);
      v26 = CFmtStrN<256>::CFmtStrN<256>(this: &v47, pszFormat: "machine%d", i + numMachinesCurrent);
      KeyValues::SetName(this: Copy, setName: v26->m_szBuf);
      KeyValues::AddSubKey(this: pMembers, pSubkey: Copy);
      this->Voice_ProcessTalkers(this, a2: Copy, a3: true);
      Key = pMembersConnecting;
    }
  }
  v27 = pMembers;
  KeyValues::SetInt(this: pMembers, keyName: "numMachines", value: numMachinesConnecting + numMachinesCurrent);
  KeyValues::SetInt(this: v27, keyName: "numPlayers", value: numUsersConnecting + numUsersCurrent);
  v28 = KeyValues::GetUint64(this: Key, keyName: "joinflags", defaultValue: 0);
  KeyValues::SetUint64(this: v27, keyName: "joinflags", value: v28);
  v29 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v29 != nullptr )
  {
    v30 = KeyValues::KeyValues(this: v29, setName: "OnPlayerMachinesConnected");
    v31 = v30;
    if ( v30 != nullptr )
    {
      KeyValues::SetInt(this: v30, keyName: "numMachines", value: numMachinesConnecting);
      KeyValues::SetUint64(this: v31, keyName: "id", value: xuidClient);
      this->OnSessionEvent(this, a2: v31);
    }
  }
  for ( xuidClient_4 = 0; xuidClient_4 < numMachinesConnecting; ++xuidClient_4 )
  {
    v32 = CFmtStrN<256>::CFmtStrN<256>(this: &v47, pszFormat: "machine%d", xuidClient_4);
    v33 = KeyValues::FindKey(this: Key, keyName: v32->m_szBuf, bCreate: false);
    v34 = v33;
    kvConnecting = v33;
    if ( v33 != nullptr )
    {
      v35 = KeyValues::GetInt(this: v33, keyName: "numPlayers", defaultValue: 0);
      v36 = 0;
      numPlayers = v35;
      j = 0;
      if ( v35 > 0 )
      {
        while ( 1 )
        {
          v37 = CFmtStrN<256>::CFmtStrN<256>(this: &v46, pszFormat: "player%d", v36);
          v38 = KeyValues::FindKey(this: v34, keyName: v37->m_szBuf, bCreate: false);
          xuid = KeyValues::GetUint64(this: v38, keyName: "xuid", defaultValue: 0);
          if ( xuid != 0 )
          {
            v39 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v39 != nullptr )
            {
              v40 = KeyValues::KeyValues(this: v39, setName: "OnPlayerUpdated");
              v41 = v40;
              if ( v40 != nullptr )
              {
                KeyValues::SetUint64(this: v40, keyName: "xuid", value: xuid);
                KeyValues::SetString(this: v41, keyName: "state", value: "joined");
                KeyValues::SetPtr(this: v41, keyName: "player", value: v38);
                this->OnSessionEvent(this, a2: v41);
              }
            }
          }
          v36 = j + 1;
          j = v36;
          if ( v36 >= numPlayers )
            break;
          v34 = kvConnecting;
        }
        Key = pMembersConnecting;
      }
    }
  }
  v42 = KeyValues::MakeCopy(this: this->m_pSettings);
  v43 = reply;
  KeyValues::AddSubKey(this: reply, pSubkey: v42);
  CSysSessionBase::SendMessage(this, msg: v43);
  this->Voice_UpdateMutelist(this);
  v44 = KeyValues::FindKey(this: this->m_pSettings, keyName: "members", bCreate: false);
  CSysSessionBase::LobbySetDataFromKeyValues(this, szPath: "members", key: v44, bRecurse: false);
  if ( v43 != nullptr )
    KeyValues::deleteThis(this: v43);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002D200
// Name: protected: void CSysSessionHost::Process_VoiceStatus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionHost::Process_VoiceStatus(CSysSessionHost *this, KeyValues *msg)
{
  unsigned __int64 Uint64; // rax
  KeyValues *Player; // esi
  char *String; // eax

  Uint64 = KeyValues::GetUint64(this: msg, keyName: "xuid", defaultValue: 0);
  Player = SessionMembersFindPlayer(pSessionSettings: this->m_pSettings, xuidPlayer: Uint64, ppMachine: nullptr);
  if ( Player != nullptr )
  {
    String = KeyValues::GetString(this: msg, keyName: "voice", defaultValue: defaultValue);
    KeyValues::SetString(this: Player, keyName: "voice", value: String);
    CSysSessionHost::OnPlayerUpdated(this, pPlayer: Player);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D270
// Name: protected: void CSysSessionHost::Process_VoiceMutelist(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionHost::Process_VoiceMutelist(CSysSessionHost *this, KeyValues *msg)
{
  KeyValues *v2; // ebx
  unsigned __int64 Uint64; // rax
  KeyValues *v5; // edi
  KeyValues *Key; // eax
  KeyValues *v7; // esi
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  KeyValues *m_pSettings; // [esp-10h] [ebp-20h]
  KeyValues *v13; // [esp-8h] [ebp-18h]

  v2 = msg;
  Uint64 = KeyValues::GetUint64(this: msg, keyName: "xuid", defaultValue: 0);
  m_pSettings = this->m_pSettings;
  msg = nullptr;
  SessionMembersFindPlayer(pSessionSettings: m_pSettings, xuidPlayer: Uint64, ppMachine: &msg);
  v5 = msg;
  if ( msg != nullptr )
  {
    Key = KeyValues::FindKey(this: msg, keyName: "Mutelist", bCreate: false);
    v7 = Key;
    if ( Key != nullptr )
    {
      KeyValues::RemoveSubKey(this: v5, subKey: Key);
      KeyValues::deleteThis(this: v7);
    }
    v8 = KeyValues::FindKey(this: v2, keyName: "Mutelist", bCreate: false);
    if ( v8 != nullptr )
    {
      v13 = v8;
      v9 = KeyValues::FindKey(this: v5, keyName: "Mutelist", bCreate: true);
      KeyValues::MergeFrom(this: v9, kvMerge: v13, eOp: MERGE_KV_UPDATE);
    }
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "SysSession::OnMachineUpdated");
    else
      v11 = nullptr;
    KeyValues::MergeFrom(this: v11, kvMerge: v5, eOp: MERGE_KV_UPDATE);
    CSysSessionBase::SendMessage(this, msg: v11);
    if ( v11 != nullptr )
      KeyValues::deleteThis(this: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D350
// Name: public: CSysSessionClient::CSysSessionClient(class CSysSessionHost __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CSysSessionClient *__thiscall CSysSessionClient::CSysSessionClient(
        CSysSessionClient *this,
        CSysSessionHost *pHost,
        KeyValues *pSettings)
{
  CSysSessionBase::CSysSessionBase(this, pSettings);
  this->__vftable = (CSysSessionClient_vtbl *)&CSysSessionClient::`vftable';
  this->m_CallbackOnLobbyEntered.m_nCallbackFlags = 0;
  this->m_CallbackOnLobbyEntered.m_iCallback = 0;
  this->m_CallbackOnLobbyEntered.m_pObj = nullptr;
  this->m_CallbackOnLobbyEntered.m_Func = nullptr;
  this->m_CallbackOnLobbyEntered.__vftable = (CCallbackManual<CSysSessionClient,LobbyEnter_t,0>_vtbl *)&CCallbackManual<CSysSessionClient,LobbyEnter_t,0>::`vftable';
  this->m_eState = 3;
  this->m_lobby = pHost->m_lobby;
  this->m_Voice_flLastHeadsetStatusCheck = pHost->m_Voice_flLastHeadsetStatusCheck;
  if ( CSysSessionBase::Steam_OnLobbyChatMsg != nullptr )
  {
    if ( (this->m_CallbackOnLobbyChatMsg.m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnLobbyChatMsg);
    this->m_CallbackOnLobbyChatMsg.m_pObj = this;
    this->m_CallbackOnLobbyChatMsg.m_Func = CSysSessionBase::Steam_OnLobbyChatMsg;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackOnLobbyChatMsg, a2: 507);
  }
  if ( CSysSessionBase::Steam_OnLobbyChatUpdate != nullptr )
  {
    if ( (this->m_CallbackOnLobbyChatUpdate.m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnLobbyChatUpdate);
    this->m_CallbackOnLobbyChatUpdate.m_pObj = this;
    this->m_CallbackOnLobbyChatUpdate.m_Func = CSysSessionBase::Steam_OnLobbyChatUpdate;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackOnLobbyChatUpdate, a2: 506);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002D430
// Name: protected: void CSysSessionClient::Send_RequestJoinData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionClient::Send_RequestJoinData(CSysSessionClient *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // ebx
  KeyValues *Key; // eax
  KeyValues *v5; // eax
  KeyValues *Copy; // [esp-8h] [ebp-10h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "SysSession::RequestJoinData");
  else
    v3 = nullptr;
  KeyValues::SetUint64(this: v3, keyName: "id", value: this->m_xuidMachineId);
  Key = KeyValues::FindKey(this: this->m_pSettings, keyName: "members", bCreate: false);
  Copy = KeyValues::MakeCopy(this: Key);
  v5 = KeyValues::FindKey(this: v3, keyName: "settings", bCreate: true);
  KeyValues::AddSubKey(this: v5, pSubkey: Copy);
  if ( CSysSessionBase::Steam_OnLobbyChatMsg != nullptr )
  {
    if ( (this->m_CallbackOnLobbyChatMsg.m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnLobbyChatMsg);
    this->m_CallbackOnLobbyChatMsg.m_pObj = this;
    this->m_CallbackOnLobbyChatMsg.m_Func = CSysSessionBase::Steam_OnLobbyChatMsg;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackOnLobbyChatMsg, a2: 507);
  }
  if ( CSysSessionBase::Steam_OnLobbyChatUpdate != nullptr )
  {
    if ( (this->m_CallbackOnLobbyChatUpdate.m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnLobbyChatUpdate);
    this->m_CallbackOnLobbyChatUpdate.m_pObj = this;
    this->m_CallbackOnLobbyChatUpdate.m_Func = CSysSessionBase::Steam_OnLobbyChatUpdate;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackOnLobbyChatUpdate, a2: 506);
  }
  CSysSessionBase::SendMessage(this, msg: v3);
  if ( v3 != nullptr )
    KeyValues::deleteThis(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1002D520
// Name: protected: virtual void CSysSessionClient::OnPlayerLeave(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionClient::OnPlayerLeave(CSysSessionClient *this, unsigned __int64 xuid)
{
  CSysSessionClient::State_t m_eState; // eax
  const char *v4; // ebx
  unsigned int *v5; // eax
  unsigned int v6; // edi
  unsigned int v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // ebx
  KeyValues *v10; // eax
  KeyValues *v11; // edi
  char *String; // eax
  IMatchTitleGameSettingsMgr *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // ebx
  char *v16; // eax
  unsigned __int64 xuidNewHost; // [esp+Ch] [ebp-10h] BYREF
  unsigned __int64 xuidCurrentHost; // [esp+14h] [ebp-8h]

  xuidCurrentHost = ((__int64 (__thiscall *)(CSysSessionClient *, _DWORD, _DWORD))this->GetHostXuid)(
                      a1: this,
                      a2: xuid,
                      a3: HIDWORD(xuid));
  m_eState = this->m_eState;
  if ( m_eState == 3 || m_eState == 5 )
    CSysSessionBase::FindAndRemovePlayerFromMembers(this, xuid);
  v4 = nullptr;
  v5 = (unsigned int *)((int (__thiscall *)(ISteamMatchmaking *, unsigned __int64 *, _DWORD, _DWORD))steamapicontext->m_pSteamMatchmaking->GetLobbyOwner)(
                         a1: steamapicontext->m_pSteamMatchmaking,
                         a2: &xuidNewHost,
                         a3: this->m_lobby.m_uiLobbyID,
                         a4: HIDWORD(this->m_lobby.m_uiLobbyID));
  v6 = *v5;
  v7 = v5[1];
  HIDWORD(xuidNewHost) = v7;
  if ( v6 == LODWORD(this->m_xuidMachineId) && v7 == HIDWORD(this->m_xuidMachineId) )
  {
    if ( this->m_eState != 3 )
      v4 = "n/a";
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "mmF->SysSessionUpdate");
    else
      v11 = nullptr;
    KeyValues::SetPtr(this: v11, keyName: "syssession", value: this);
    if ( v4 != nullptr )
    {
      this->m_eState = STATE_FAIL;
      KeyValues::SetString(this: v11, keyName: "error", value: v4);
    }
    else
    {
      String = KeyValues::GetString(this: this->m_pSettings, keyName: "system/netflag", defaultValue: defaultValue);
      if ( _V_stricmp(s1: "teamlink", s2: String) != 0 )
      {
        v13 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
        v14 = v13->PrepareClientLobbyForMigration(this: v13, a2: this->m_pSettings, a3: nullptr);
        v15 = v14;
        if ( v14 != nullptr )
        {
          v16 = KeyValues::GetString(this: v14, keyName: "error", defaultValue: nullptr);
          if ( v16 != nullptr )
          {
            this->m_eState = STATE_FAIL;
            KeyValues::SetString(this: v11, keyName: "error", value: v16);
            g_pMatchExtensions->m_exts.m_pIVEngineClient->ClientCmd(
              this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
              a2: "disconnect");
          }
          KeyValues::deleteThis(this: v15);
        }
        if ( this->m_eState != STATE_FAIL )
        {
          this->m_eState = 5;
          KeyValues::SetString(this: v11, keyName: "action", value: "host");
        }
      }
      else
      {
        this->m_eState = STATE_FAIL;
        KeyValues::SetString(this: v11, keyName: "error", value: "migrate");
      }
    }
    this->OnSessionEvent(this, a2: v11);
  }
  else if ( this->m_eState == STATE_REQUESTING_JOIN_DATA && xuid == this->m_RequestJoinDataInfo.m_xuidLeader )
  {
    LODWORD(this->m_RequestJoinDataInfo.m_xuidLeader) = v6;
    HIDWORD(this->m_RequestJoinDataInfo.m_xuidLeader) = v7;
    CSysSessionClient::Send_RequestJoinData(this);
  }
  else if ( __PAIR64__(v7, v6) != xuidCurrentHost )
  {
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
      v9 = KeyValues::KeyValues(this: v8, setName: "OnPlayerLeaderChanged");
    else
      v9 = nullptr;
    KeyValues::SetString(this: v9, keyName: "state", value: "client");
    KeyValues::SetUint64(this: v9, keyName: "xuid", value: __PAIR64__(HIDWORD(xuidNewHost), v6));
    this->OnSessionEvent(this, a2: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D770
// Name: public: virtual bool CSysSessionBase::Update(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CSysSessionBase::Update@<al>(
        CSysSessionBase *this@<ecx>,
        unsigned int *p_uiSteamMsgSize@<edi>,
        int a3@<esi>)
{
  CSysSessionBase *v3; // ebx
  bool (__thiscall *IsServiceSession)(CSysSessionBase *); // edx
  unsigned __int8 *v5; // esi
  signed int v6; // edi
  unsigned int v7; // eax
  IMemAlloc_vtbl *v8; // edx
  int v9; // eax
  char v10; // al
  CSteamID idRemote; // [esp+4h] [ebp-10h] BYREF
  CSysSessionBase *v15; // [esp+Ch] [ebp-8h]
  unsigned int uiSteamMsgSize; // [esp+10h] [ebp-4h] BYREF

  v3 = this;
  IsServiceSession = this->IsServiceSession;
  v15 = this;
  if ( ((unsigned __int8 (__fastcall *)(CSysSessionBase *))IsServiceSession)(a1: this) == 0 )
  {
    v5 = nullptr;
    uiSteamMsgSize = 0;
    idRemote.m_steamid.m_comp = 0;
    v6 = 0;
    if ( steamapicontext->m_pSteamNetworking->IsP2PPacketAvailable(
           this: steamapicontext->m_pSteamNetworking,
           a2: &uiSteamMsgSize,
           a3: 2) )
    {
      do
      {
        v7 = uiSteamMsgSize;
        if ( v6 < (int)uiSteamMsgSize )
        {
          v8 = _g_pMemAlloc->__vftable;
          v6 = uiSteamMsgSize;
          if ( v5 != nullptr )
            v9 = ((int (__stdcall *)(unsigned __int8 *, unsigned int))v8->Realloc_2)(a1: v5, a2: uiSteamMsgSize);
          else
            v9 = ((int (__stdcall *)(unsigned int))v8->Alloc_2)(a1: uiSteamMsgSize);
          v5 = (unsigned __int8 *)v9;
          v7 = uiSteamMsgSize;
        }
        v10 = ((int (__thiscall *)(ISteamNetworking *, unsigned __int8 *, unsigned int, unsigned int *, CSteamID *, int, unsigned int *, int))steamapicontext->m_pSteamNetworking->ReadP2PPacket)(
                a1: steamapicontext->m_pSteamNetworking,
                a2: v5,
                a3: v7,
                a4: &uiSteamMsgSize,
                a5: &idRemote,
                a6: 2,
                a7: p_uiSteamMsgSize,
                a8: a3);
        v3 = v15;
        if ( v10 != 0 )
          CSysSessionBase::UnpackAndReceiveMessage(this: v15, pvBuffer: v5, numBytes: (void *)uiSteamMsgSize);
        a3 = 2;
        p_uiSteamMsgSize = &uiSteamMsgSize;
      }
      while ( ((unsigned __int8 (__thiscall *)(ISteamNetworking *))steamapicontext->m_pSteamNetworking->IsP2PPacketAvailable)(a1: steamapicontext->m_pSteamNetworking) != 0 );
      if ( v5 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
    }
  }
  v3->Voice_UpdateLocalHeadsetsStatus(this: v3);
  v3->Voice_CaptureAndTransmitLocalVoiceData(this: v3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002D860
// Name: public: virtual void CSysSessionBase::Command(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionBase::Command(CSysSessionBase *this, KeyValues *pCommand)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  KeyValues *Copy; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "SysSession::Command");
  else
    v4 = nullptr;
  Copy = KeyValues::MakeCopy(this: pCommand);
  KeyValues::AddSubKey(this: v4, pSubkey: Copy);
  CSysSessionBase::SendMessage(this, msg: v4);
  if ( v4 != nullptr )
    KeyValues::deleteThis(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1002D8B0
// Name: protected: virtual void CSysSessionHost::ReceiveMessage(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionHost::ReceiveMessage(CSysSessionHost *this, KeyValues *msg)
{
  const char *Name; // ebx
  unsigned __int64 Uint64; // kr00_8
  KeyValues *Key; // eax

  Name = KeyValues::GetName(this: msg);
  if ( this->m_eState == STATE_REQUESTING_JOIN_DATA )
  {
    if ( _V_stricmp(s1: "SysSession::RequestJoinData", s2: Name) != 0 )
    {
      if ( _V_stricmp(s1: "SysSession::VoiceStatus", s2: Name) != 0 )
      {
        if ( _V_stricmp(s1: "SysSession::VoiceMutelist", s2: Name) != 0 )
          CSysSessionBase::ReceiveMessage(this, msg);
        else
          CSysSessionHost::Process_VoiceMutelist(this, msg);
      }
      else
      {
        CSysSessionHost::Process_VoiceStatus(this, msg);
      }
    }
    else
    {
      Uint64 = KeyValues::GetUint64(this: msg, keyName: "id", defaultValue: 0);
      Key = KeyValues::FindKey(this: msg, keyName: "settings", bCreate: false);
      CSysSessionHost::Process_RequestJoinData(this, xuidClient: Uint64, pSettings: Key);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002D980
// Name: protected: void CSysSessionHost::Steam_OnLobbyCreated(struct LobbyCreated_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionHost::Steam_OnLobbyCreated(CSysSessionHost *this, LobbyCreated_t *pLobbyCreate, bool bError)
{
  EResult m_eResult; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // edi

  if ( bError )
  {
    m_eResult = -1;
    goto LABEL_8;
  }
  m_eResult = pLobbyCreate->m_eResult;
  if ( pLobbyCreate->m_eResult != k_EResultOK )
  {
LABEL_8:
    _Warning(a1: "CSysSessionHost: CreateSession failed. Error %d\n", m_eResult);
    this->m_eState = 3;
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "mmF->SysSessionUpdate");
    else
      v6 = nullptr;
    KeyValues::SetPtr(this: v6, keyName: "syssession", value: this);
    KeyValues::SetString(this: v6, keyName: "error", value: "create");
    this->OnSessionEvent(this, a2: v6);
    return;
  }
  this->m_lobby.m_uiLobbyID = pLobbyCreate->m_ulSteamIDLobby;
  if ( CSysSessionHost::Steam_OnLobbyEntered != nullptr )
  {
    if ( (this->m_CallbackOnLobbyEntered.m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnLobbyEntered);
    this->m_CallbackOnLobbyEntered.m_pObj = this;
    this->m_CallbackOnLobbyEntered.m_Func = CSysSessionHost::Steam_OnLobbyEntered;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackOnLobbyEntered, a2: 504);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DA50
// Name: protected: void CSysSessionClient::Steam_OnLobbyEntered(struct LobbyEnter_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionClient::Steam_OnLobbyEntered(CSysSessionClient *this, LobbyEnter_t *pLobbyEnter)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  const char *v5; // eax
  int *v6; // eax
  int v7; // edi
  int v8; // ebx
  KeyValues *v9; // eax
  KeyValues *v10; // edi
  _BYTE v11[8]; // [esp+Ch] [ebp-8h] BYREF

  if ( LODWORD(pLobbyEnter->m_ulSteamIDLobby) == LODWORD(this->m_lobby.m_uiLobbyID)
    && HIDWORD(pLobbyEnter->m_ulSteamIDLobby) == HIDWORD(this->m_lobby.m_uiLobbyID) )
  {
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnLobbyEntered);
    if ( pLobbyEnter->m_EChatRoomEnterResponse == 1 )
    {
      v6 = (int *)((int (__thiscall *)(ISteamMatchmaking *, _BYTE *, _DWORD, _DWORD))steamapicontext->m_pSteamMatchmaking->GetLobbyOwner)(
                    a1: steamapicontext->m_pSteamMatchmaking,
                    a2: v11,
                    a3: this->m_lobby.m_uiLobbyID,
                    a4: HIDWORD(this->m_lobby.m_uiLobbyID));
      v7 = *v6;
      v8 = v6[1];
      if ( LODWORD(this->m_xuidMachineId) == *v6 && HIDWORD(this->m_xuidMachineId) == v8 )
      {
        v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v9 != nullptr )
          v10 = KeyValues::KeyValues(this: v9, setName: "mmF->SysSessionUpdate");
        else
          v10 = nullptr;
        KeyValues::SetPtr(this: v10, keyName: "syssession", value: this);
        KeyValues::SetString(this: v10, keyName: "error", value: "n/a");
        this->OnSessionEvent(this, a2: v10);
      }
      else
      {
        this->m_eState = STATE_REQUESTING_JOIN_DATA;
        this->m_RequestJoinDataInfo.m_fTimeSent = _Plat_FloatTime();
        LODWORD(this->m_RequestJoinDataInfo.m_xuidLeader) = v7;
        HIDWORD(this->m_RequestJoinDataInfo.m_xuidLeader) = v8;
        CSysSessionClient::Send_RequestJoinData(this);
      }
    }
    else
    {
      _Warning(a1: "CSysSessionClient: lobby response %d!\n", pLobbyEnter->m_EChatRoomEnterResponse);
      this->m_eState = STATE_FAIL;
      v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v3 != nullptr )
        v4 = KeyValues::KeyValues(this: v3, setName: "mmF->SysSessionUpdate");
      else
        v4 = nullptr;
      KeyValues::SetPtr(this: v4, keyName: "syssession", value: this);
      switch ( pLobbyEnter->m_EChatRoomEnterResponse )
      {
        case 2u:
        case 3u:
        case 6u:
          v5 = "n/a";
          break;
        case 4u:
          v5 = "full";
          break;
        default:
          v5 = "create";
          break;
      }
      KeyValues::SetString(this: v4, keyName: "error", value: v5);
      this->OnSessionEvent(this, a2: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002DBF0
// Name: protected: void CSysSessionHost::UpdateStateInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionHost::UpdateStateInit(CSysSessionHost *this)
{
  int Int; // eax
  unsigned __int64 v3; // kr00_8

  Int = KeyValues::GetInt(this: this->m_pSettings, keyName: "members/numSlots", defaultValue: 1);
  v3 = steamapicontext->m_pSteamMatchmaking->CreateLobby(
         this: steamapicontext->m_pSteamMatchmaking,
         a2: k_ELobbyTypeFriendsOnly,
         a3: Int);
  if ( this->m_CallbackOnLobbyCreated.m_hAPICall != 0 )
    _SteamAPI_UnregisterCallResult(
      a1: &this->m_CallbackOnLobbyCreated,
      a2: this->m_CallbackOnLobbyCreated.m_hAPICall,
      a3: HIDWORD(this->m_CallbackOnLobbyCreated.m_hAPICall));
  this->m_CallbackOnLobbyCreated.m_hAPICall = v3;
  this->m_CallbackOnLobbyCreated.m_pObj = this;
  this->m_CallbackOnLobbyCreated.m_Func = CSysSessionHost::Steam_OnLobbyCreated;
  if ( v3 != 0 )
    _SteamAPI_RegisterCallResult(a1: &this->m_CallbackOnLobbyCreated, a2: v3, a3: HIDWORD(v3));
  this->m_eState = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002DC80
// Name: protected: void CSysSessionClient::UpdateStateInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSysSessionClient::UpdateStateInit(CSysSessionClient *this)
{
  this->m_lobby.m_uiLobbyID = KeyValues::GetUint64(
                                this: this->m_pSettings,
                                keyName: "options/sessionid",
                                defaultValue: 0);
  if ( CSysSessionClient::Steam_OnLobbyEntered != nullptr )
  {
    if ( (this->m_CallbackOnLobbyEntered.m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnLobbyEntered);
    this->m_CallbackOnLobbyEntered.m_pObj = this;
    this->m_CallbackOnLobbyEntered.m_Func = CSysSessionClient::Steam_OnLobbyEntered;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackOnLobbyEntered, a2: 504);
  }
  ((void (__thiscall *)(ISteamMatchmaking *, _DWORD, _DWORD))steamapicontext->m_pSteamMatchmaking->JoinLobby)(
    a1: steamapicontext->m_pSteamMatchmaking,
    a2: this->m_lobby.m_uiLobbyID,
    a3: HIDWORD(this->m_lobby.m_uiLobbyID));
  this->m_eState = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002DD10
// Name: public: virtual bool CSysSessionHost::Update(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CSysSessionHost::Update@<al>(CSysSessionHost *this@<ecx>, unsigned int *a2@<edi>)
{
  char result; // al
  float m_fValue; // [esp+4h] [ebp-4h]

  result = CSysSessionBase::Update(this, p_uiSteamMsgSize: a2, a3: (int)this);
  if ( result != 0 )
  {
    if ( this->m_eState == 0 )
    {
      if ( this->m_flInitializeTimestamp == 0.0 )
        this->m_flInitializeTimestamp = _Plat_FloatTime();
      m_fValue = mm_session_sys_delay_create_host.m_pParent->m_Value.m_fValue;
      if ( _Plat_FloatTime() >= this->m_flInitializeTimestamp + m_fValue && SysSession_AllowCreate() != 0 )
        CSysSessionHost::UpdateStateInit(this);
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002DD90
// Name: public: virtual bool CSysSessionClient::Update(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CSysSessionClient::Update@<al>(CSysSessionClient *this@<ecx>, unsigned int *a2@<edi>)
{
  char result; // al
  CSysSessionClient::State_t m_eState; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  float m_fValue; // [esp+4h] [ebp-4h]

  result = CSysSessionBase::Update(this, p_uiSteamMsgSize: a2, a3: (int)this);
  if ( result == 0 )
    return result;
  m_eState = this->m_eState;
  if ( m_eState == 0 )
  {
    if ( SysSession_AllowCreate() != 0 )
      CSysSessionClient::UpdateStateInit(this);
  }
  else if ( m_eState == STATE_REQUESTING_JOIN_DATA )
  {
    m_fValue = mm_session_sys_connect_timeout.m_pParent->m_Value.m_fValue;
    if ( _Plat_FloatTime() > this->m_RequestJoinDataInfo.m_fTimeSent + m_fValue )
    {
      this->m_eState = STATE_FAIL;
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "mmF->SysSessionUpdate");
      else
        v6 = nullptr;
      KeyValues::SetPtr(this: v6, keyName: "syssession", value: this);
      KeyValues::SetString(this: v6, keyName: "error", value: "n/a");
      this->OnSessionEvent(this, a2: v6);
      return 1;
    }
  }
  return 1;
}
