// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/mm_session_offline_custom.cpp
// Functions: 10
// ============================================================

#include "matchmaking\mm_session_offline_custom.h"

//------------------------------------------------------------------------------
// Address: 0x10020B70
// Name: public: virtual void CMatchSessionOfflineCustom::UpdateSessionSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOfflineCustom::UpdateSessionSettings(
        CMatchSessionOfflineCustom *this,
        KeyValues *pSettings)
{
  IMatchTitleGameSettingsMgr *v3; // eax

  v3 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
  v3->ExtendGameSettingsUpdateKeys(this: v3, a2: this->m_pSettings, a3: pSettings);
  KeyValues::MergeFrom(this: this->m_pSettings, kvMerge: pSettings, eOp: MERGE_KV_ALL);
  MatchSession_BroadcastSessionSettingsUpdate(pUpdateDeletePackage: pSettings);
}

//------------------------------------------------------------------------------
// Address: 0x10020BB0
// Name: public: virtual void CMatchSessionOfflineCustom::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOfflineCustom::Update(CMatchSessionOfflineCustom *this)
{
  KeyValues *v1; // eax
  KeyValues *v2; // eax

  if ( this->m_eState == 0 )
  {
    this->m_eState = STATE_CONFIG;
    v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v1 != nullptr )
    {
      v2 = KeyValues::KeyValues(this: v1, setName: "OnMatchSessionUpdate", firstKey: "state", firstValue: "ready");
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v2);
    }
    else
    {
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020C10
// Name: public: virtual void CMatchSessionOfflineCustom::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOfflineCustom::OnEvent(CMatchSessionOfflineCustom *this, KeyValues *pEvent)
{
  const char *Name; // edi
  int Int; // edi
  int v5; // eax
  char *String; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: "OnEngineClientSignonStateChange", s2: Name) == 0 )
  {
    Int = KeyValues::GetInt(this: pEvent, keyName: "old", defaultValue: 0);
    v5 = KeyValues::GetInt(this: pEvent, keyName: "new", defaultValue: 0);
    if ( Int < 2 || v5 >= 2 )
      return;
    DevMsg(a1: "OnEngineClientSignonStateChange\n");
    if ( LOBYTE(this->m_eState) != 0 )
    {
      LOBYTE(this->m_eState) = 0;
      DevMsg(a1: " session was expecting server reload...\n");
      return;
    }
    goto LABEL_11;
  }
  if ( _V_stricmp(s1: "OnEngineClientSignonStatePrepareChange", s2: Name) != 0 )
  {
    if ( _V_stricmp(s1: "OnEngineEndGame", s2: Name) != 0 )
      return;
    DevMsg(a1: "OnEngineEndGame\n");
    g_pMatchExtensions->m_exts.m_pIVEngineClient->ExecuteClientCmd(
      this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
      a2: "disconnect");
LABEL_11:
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "mmF->CloseSession");
    else
      v8 = nullptr;
    g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v8);
    return;
  }
  String = KeyValues::GetString(this: pEvent, keyName: "reason", defaultValue: defaultValue);
  if ( _V_stricmp(s1: "reload", s2: String) == 0 )
    LOBYTE(this->m_eState) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10020D40
// Name: public: virtual void CMatchSessionOfflineCustom::DebugPrint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOfflineCustom::DebugPrint(CMatchSessionOfflineCustom *this)
{
  KeyValues *m_pSettings; // ecx
  IKeyValuesDumpContext pDump; // [esp+4h] [ebp-8h] BYREF
  int v4; // [esp+8h] [ebp-4h]

  DevMsg(a1: "CMatchSessionOfflineCustom [ state=%d ]\n", this->m_eState);
  m_pSettings = this->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v4 = 1;
  KeyValues::Dump(this: m_pSettings, &pDump, nIndentLevel: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10020D80
// Name: protected: void CMatchSessionOfflineCustom::InitializeGameSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOfflineCustom::InitializeGameSettings(CMatchSessionOfflineCustom *this)
{
  KeyValues *Key; // eax
  KeyValues *v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  KeyValues *v7; // esi
  IPlayerLocal *v8; // eax
  unsigned __int64 v9; // rax
  unsigned __int64 MachineFlags; // rax
  IMatchSystem *v11; // eax
  int v12; // eax
  KeyValues *v13; // eax
  unsigned __int64 Uint64; // rax
  const char *TuInstalledString; // eax
  CFmtStrN<256> *v16; // eax
  KeyValues *v17; // esi
  IPlayerLocal *v18; // eax
  IPlayerLocal *v19; // edi
  unsigned __int64 v20; // rax
  const char *v21; // eax
  IMatchTitleGameSettingsMgr *v22; // eax
  KeyValues *m_pSettings; // ecx
  CFmtStrN<256> v24; // [esp+8h] [ebp-114h] BYREF
  IKeyValuesDumpContext pDump[2]; // [esp+114h] [ebp-8h] BYREF

  Key = KeyValues::FindKey(this: this->m_pSettings, keyName: "system", bCreate: true);
  v3 = Key;
  if ( Key != nullptr )
  {
    KeyValues::SetString(this: Key, keyName: "network", value: "offline");
    KeyValues::SetString(this: v3, keyName: "access", value: "public");
  }
  v4 = KeyValues::FindKey(this: this->m_pSettings, keyName: "options", bCreate: true);
  if ( v4 != nullptr )
    KeyValues::SetString(this: v4, keyName: "server", value: "listen");
  v5 = KeyValues::FindKey(this: this->m_pSettings, keyName: "members", bCreate: true);
  v6 = v5;
  if ( v5 != nullptr )
  {
    KeyValues::SetInt(this: v5, keyName: "numMachines", value: 1);
    KeyValues::SetInt(this: v6, keyName: "numPlayers", value: 1);
    KeyValues::SetInt(this: v6, keyName: "numSlots", value: 1);
    v7 = KeyValues::FindKey(this: v6, keyName: "machine0", bCreate: true);
    if ( v7 != nullptr )
    {
      v8 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
      if ( v8 != nullptr )
      {
        LODWORD(v9) = v8->GetXUID(this: v8);
      }
      else
      {
        *(_QWORD *)&pDump[0].__vftable = 0;
        v9 = 0;
      }
      KeyValues::SetUint64(this: v7, keyName: "id", value: v9);
      MachineFlags = MatchSession_GetMachineFlags();
      KeyValues::SetUint64(this: v7, keyName: "flags", value: MachineFlags);
      KeyValues::SetInt(this: v7, keyName: "numPlayers", value: 1);
      v11 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
      v12 = (int)v11->GetDlcManager(this: v11);
      v13 = (KeyValues *)(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 8))(a1: v12);
      Uint64 = KeyValues::GetUint64(this: v13, keyName: "@info/installed", defaultValue: 0);
      KeyValues::SetUint64(this: v7, keyName: "dlcmask", value: Uint64);
      TuInstalledString = MatchSession_GetTuInstalledString();
      KeyValues::SetString(this: v7, keyName: "tuver", value: TuInstalledString);
      KeyValues::SetInt(this: v7, keyName: "ping", value: 0);
      v16 = CFmtStrN<256>::CFmtStrN<256>(this: &v24, pszFormat: "player%d", 0);
      v17 = KeyValues::FindKey(this: v7, keyName: v16->m_szBuf, bCreate: true);
      if ( v17 != nullptr )
      {
        v18 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
        v19 = v18;
        if ( v18 != nullptr )
        {
          v20 = v18->GetXUID(this: v18);
          KeyValues::SetUint64(this: v17, keyName: "xuid", value: v20);
          v21 = v19->GetName(this: v19);
          KeyValues::SetString(this: v17, keyName: "name", value: v21);
        }
      }
    }
  }
  v22 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
  v22->InitializeGameSettings(this: v22, a2: this->m_pSettings, a3: "host");
  DevMsg(a1: "CMatchSessionOfflineCustom::InitializeGameSettings adjusted settings:\n");
  m_pSettings = this->m_pSettings;
  pDump[0].__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  pDump[1].__vftable = (IKeyValuesDumpContext_vtbl *)1;
  KeyValues::Dump(this: m_pSettings, pDump, nIndentLevel: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10020FC0
// Name: public: CMatchSessionOfflineCustom::CMatchSessionOfflineCustom(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CMatchSessionOfflineCustom *__thiscall CMatchSessionOfflineCustom::CMatchSessionOfflineCustom(
        CMatchSessionOfflineCustom *this,
        KeyValues *pSettings)
{
  KeyValues *Copy; // eax
  KeyValues *m_pSettings; // ecx
  IKeyValuesDumpContext pDump; // [esp+4h] [ebp-8h] BYREF
  int v7; // [esp+8h] [ebp-4h]

  this->IMatchSessionInternal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  this->IMatchSessionInternal::IMatchSession::__vftable = (CMatchSessionOfflineCustom_vtbl *)&CMatchSessionOfflineCustom::`vftable'{for `IMatchSession'};
  this->IMatchSessionInternal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CMatchSessionOfflineCustom::`vftable'{for `IMatchEventsSink'};
  Copy = KeyValues::MakeCopy(this: pSettings);
  this->m_pSettings = Copy;
  this->m_autodelete_pSettings.m_pKeyValues = Copy;
  this->m_eState = 0;
  this->m_bExpectingServerReload = false;
  DevMsg(a1: "Created CMatchSessionOfflineCustom:\n");
  m_pSettings = this->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v7 = 1;
  KeyValues::Dump(this: m_pSettings, &pDump, nIndentLevel: 1);
  CMatchSessionOfflineCustom::InitializeGameSettings(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10021030
// Name: public: virtual void CMatchSessionOfflineCustom::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMatchSessionOfflineCustom::Destroy(CMatchSessionOfflineCustom *this@<ecx>, int a2@<edi>)
{
  KeyValues *v3; // eax
  IMatchEventsSubscription *v4; // eax
  KeyValues *m_pSettings; // ecx
  KeyValues *m_pKeyValues; // ecx
  IKeyValuesDumpContext pDump; // [esp+4h] [ebp-8h] BYREF
  int v8; // [esp+8h] [ebp-4h]

  if ( this->m_eState == STATE_RUNNING )
  {
    ((void (__thiscall *)(IVEngineClient *, const char *, int))g_pMatchExtensions->m_exts.m_pIVEngineClient->ExecuteClientCmd)(
      a1: g_pMatchExtensions->m_exts.m_pIVEngineClient,
      a2: "disconnect",
      a3: a2);
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      KeyValues::KeyValues(
        this: v3,
        setName: "OnProfilesWriteOpportunity",
        firstKey: "reason",
        firstValue: "sessionend");
    v4 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    ((void (__thiscall *)(IMatchEventsSubscription *))v4->BroadcastEvent)(a1: v4);
  }
  this->IMatchSessionInternal::IMatchSession::__vftable = (CMatchSessionOfflineCustom_vtbl *)&CMatchSessionOfflineCustom::`vftable'{for `IMatchSession'};
  this->IMatchSessionInternal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CMatchSessionOfflineCustom::`vftable'{for `IMatchEventsSink'};
  DevMsg(a1: "Destroying CMatchSessionOfflineCustom:\n");
  m_pSettings = this->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v8 = 1;
  KeyValues::Dump(this: m_pSettings, &pDump, nIndentLevel: 1);
  m_pKeyValues = this->m_autodelete_pSettings.m_pKeyValues;
  if ( m_pKeyValues != nullptr )
    KeyValues::deleteThis(this: m_pKeyValues);
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x100210F0
// Name: protected: void CMatchSessionOfflineCustom::OnGamePrepareLobbyForGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOfflineCustom::OnGamePrepareLobbyForGame(CMatchSessionOfflineCustom *this)
{
  KeyValues *v1; // edi
  KeyValues *m_pSettings; // ecx
  int Int; // eax
  KeyValues **m_pMemory; // ebx
  IMatchTitleGameSettingsMgr *v6; // eax
  int i; // esi
  KeyValues *v8; // eax
  unsigned __int64 Uint64; // rax
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > arrPlayersUpdated; // [esp+Ch] [ebp-18h] BYREF
  CMatchSessionOfflineCustom *v11; // [esp+20h] [ebp-4h]

  v1 = nullptr;
  m_pSettings = this->m_pSettings;
  v11 = this;
  memset(&arrPlayersUpdated, 0, sizeof(arrPlayersUpdated));
  Int = KeyValues::GetInt(this: m_pSettings, keyName: "members/numPlayers", defaultValue: 0);
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int>>::InsertMultipleBefore(
    this: (CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)&arrPlayersUpdated,
    elem: 0,
    num: Int);
  m_pMemory = arrPlayersUpdated.m_Memory.m_pMemory;
  memset(dst: (unsigned __int8 *)arrPlayersUpdated.m_Memory.m_pMemory, value: 0, count: 4 * arrPlayersUpdated.m_Size);
  v6 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
  v6->PrepareLobbyForGame(this: v6, a2: this->m_pSettings, a3: m_pMemory);
  for ( i = 0; i < arrPlayersUpdated.m_Size; v1 = nullptr )
  {
    if ( m_pMemory[i] == nullptr )
      break;
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
      v1 = KeyValues::KeyValues(this: v8, setName: "OnPlayerUpdated");
    Uint64 = KeyValues::GetUint64(this: m_pMemory[i], keyName: "xuid", defaultValue: 0);
    KeyValues::SetUint64(this: v1, keyName: "xuid", value: Uint64);
    g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v1);
    ++i;
  }
  MatchSession_PrepareClientForConnect(pSettings: v11->m_pSettings);
  if ( arrPlayersUpdated.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100211F0
// Name: public: virtual void CMatchSessionOfflineCustom::Command(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMatchSessionOfflineCustom::Command(
        CMatchSessionOfflineCustom *this@<ecx>,
        int a2@<ebx>,
        KeyValues *pCommand)
{
  const char *Name; // eax
  KeyValues *v5; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  IMatchEventsSubscription *v8; // eax
  IMatchTitle *v9; // eax
  KeyValues *v10; // ecx
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *m_pSettings; // ecx
  int Int; // eax
  KeyValues **m_pMemory; // ebx
  int *v16; // eax
  KeyValues *(__thiscall *GetSessionSystemData)(struct CMatchSessionOfflineCustom *); // edx
  int *v18; // edi
  int v19; // eax
  int i; // esi
  KeyValues *v21; // eax
  KeyValues *v22; // edi
  unsigned __int64 Uint64; // rax
  KeyValues *Copy; // esi
  const char *v25; // eax
  CFmtStrN<256> *v26; // eax
  KeyValues *v27; // [esp-8h] [ebp-138h]
  CFmtStrN<256> v29; // [esp+8h] [ebp-128h] BYREF
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > arrPlayersUpdated; // [esp+114h] [ebp-1Ch] BYREF
  IKeyValuesDumpContext pDump; // [esp+128h] [ebp-8h] BYREF
  int v32; // [esp+12Ch] [ebp-4h]

  Name = KeyValues::GetName(this: pCommand);
  if ( _V_stricmp(s1: "Start", s2: Name) != 0 || this->m_eState >= STATE_RUNNING )
  {
    m_pSettings = this->m_pSettings;
    memset(&arrPlayersUpdated, 0, sizeof(arrPlayersUpdated));
    Int = KeyValues::GetInt(this: m_pSettings, keyName: "members/numPlayers", defaultValue: 0);
    CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int>>::InsertMultipleBefore(
      this: (CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)&arrPlayersUpdated,
      elem: 0,
      num: Int);
    m_pMemory = arrPlayersUpdated.m_Memory.m_pMemory;
    memset(dst: (unsigned __int8 *)arrPlayersUpdated.m_Memory.m_pMemory, value: 0, count: 4 * arrPlayersUpdated.m_Size);
    v16 = (int *)((int (__thiscall *)(CMatchFramework *, int))g_pMMF->GetMatchTitleGameSettingsMgr)(a1: g_pMMF, a2);
    GetSessionSystemData = this->GetSessionSystemData;
    v18 = v16;
    v27 = this->m_pSettings;
    v32 = *v16;
    v19 = ((int (__thiscall *)(CMatchSessionOfflineCustom *, KeyValues *, KeyValues **))GetSessionSystemData)(
            a1: this,
            a2: v27,
            a3: m_pMemory);
    (*(void (__thiscall **)(int *, KeyValues *, int))(v32 + 40))(a1: v18, a2: pCommand, a3: v19);
    for ( i = 0; i < arrPlayersUpdated.m_Size; ++i )
    {
      if ( m_pMemory[i] == nullptr )
        break;
      v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      v22 = v21 != nullptr ? KeyValues::KeyValues(this: v21, setName: "OnPlayerUpdated") : nullptr;
      Uint64 = KeyValues::GetUint64(this: m_pMemory[i], keyName: "xuid", defaultValue: 0);
      KeyValues::SetUint64(this: v22, keyName: "xuid", value: Uint64);
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v22);
    }
    Copy = KeyValues::MakeCopy(this: pCommand);
    v25 = KeyValues::GetName(this: pCommand);
    v26 = CFmtStrN<256>::CFmtStrN<256>(this: &v29, pszFormat: "Command::%s", v25);
    KeyValues::SetName(this: Copy, setName: v26->m_szBuf);
    g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: Copy);
    if ( arrPlayersUpdated.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
  else
  {
    this->m_eState = STATE_RUNNING;
    CMatchSessionOfflineCustom::OnGamePrepareLobbyForGame(this);
    v5 = KeyValues::FromString(
           szName: "update",
           szStringVal: (KeyValues *)" update {  server {  server listen  }  } ",
           ppEndOfParse: nullptr);
    this->UpdateSessionSettings(this, a2: v5);
    if ( v5 != nullptr )
      KeyValues::deleteThis(this: v5);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(
             this: v6,
             setName: "OnProfilesWriteOpportunity",
             firstKey: "reason",
             firstValue: "sessionstart");
    else
      v7 = nullptr;
    v8 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    v8->BroadcastEvent(this: v8, a2: v7);
    v9 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
    if ( !v9->StartServerMap(this: v9, a2: this->m_pSettings) )
    {
      _Warning(a1: "Failed to start server map!\n");
      v10 = this->m_pSettings;
      pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
      v32 = 1;
      KeyValues::Dump(this: v10, &pDump, nIndentLevel: 1);
      v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v11 != nullptr )
        v12 = KeyValues::KeyValues(
                this: v11,
                setName: "OnMatchSessionUpdate",
                firstKey: "state",
                firstValue: "error",
                secondKey: "error",
                secondValue: "nomap");
      else
        v12 = nullptr;
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v12);
    }
    _Msg(a1: "Succeeded in starting server map!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023F90
// Name: public: virtual bool CMatchSessionOfflineCustom::IsAnotherSessionJoinable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatchSessionOfflineCustom::IsAnotherSessionJoinable(GCSDK::CJob *this, GCSDK::CNetPacket *pNetPacket)
{
  return 1;
}
