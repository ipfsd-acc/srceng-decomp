// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/engsoundservice.cpp
// Functions: 35
// ============================================================

#include "engine\engsoundservice.h"

//------------------------------------------------------------------------------
// Address: 0x100023D0
// Name: public: virtual bool CBaseServer::IsActive(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseServer::IsActive(CBaseServer *this)
{
  return this->m_State >= ss_active;
}

//------------------------------------------------------------------------------
// Address: 0x100023E0
// Name: public: virtual void __near * CEngineSoundServices::LevelAlloc(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CEngineSoundServices::LevelAlloc(CEngineSoundServices *this, int nBytes, const char *pszTag)
{
  return Hunk_AllocName(size: nBytes, name: pszTag, bClear: true);
}

//------------------------------------------------------------------------------
// Address: 0x10002400
// Name: public: virtual void CEngineSoundServices::OnExtraUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::OnExtraUpdate(CEngineSoundServices *this)
{
  if ( g_ClientDLL != nullptr && game != nullptr && game->IsActiveApp(this: game) )
    g_ClientDLL->IN_Accumulate(this: g_ClientDLL);
}

//------------------------------------------------------------------------------
// Address: 0x10002430
// Name: public: virtual bool CEngineSoundServices::GetSoundSpatialization(int,struct SpatializationInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundServices::GetSoundSpatialization(
        CEngineSoundServices *this,
        int entIndex,
        SpatializationInfo_t *info)
{
  IClientEntity *v4; // edi
  IMDLCache *v5; // esi
  bool v6; // bl

  if ( entitylist == nullptr )
    return false;
  v4 = entitylist->GetClientEntity(this: entitylist, a2: entIndex);
  if ( v4 == nullptr )
    return false;
  v5 = g_pMDLCache;
  g_pMDLCache->BeginLock(this: g_pMDLCache);
  v6 = v4->GetSoundSpatialization(this: v4, a2: info);
  v5->EndLock(this: v5);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10002490
// Name: public: virtual bool CEngineSoundServices::GetToolSpatialization(int,int,struct SpatializationInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundServices::GetToolSpatialization(
        CEngineSoundServices *this,
        int iUserData,
        int guid,
        SpatializationInfo_t *info)
{
  return toolframework->GetSoundSpatialization(this: toolframework, a2: iUserData, a3: guid, a4: info);
}

//------------------------------------------------------------------------------
// Address: 0x100024B0
// Name: public: virtual float CEngineSoundServices::GetClientTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineSoundServices::GetClientTime(CEngineSoundServices *this)
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  return CClientState::GetTime(this: BaseLocalClient);
}

//------------------------------------------------------------------------------
// Address: 0x100024C0
// Name: public: virtual float CEngineSoundServices::GetHostTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineSoundServices::GetHostTime(CEngineSoundServices *this)
{
  return host_time;
}

//------------------------------------------------------------------------------
// Address: 0x100024D0
// Name: public: virtual int CEngineSoundServices::GetViewEntity(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineSoundServices::GetViewEntity(CEngineSoundServices *this, int nSlot)
{
  CClientState *LocalClient; // eax

  LocalClient = GetLocalClient(nSlot);
  return CBaseClientState::GetViewEntity(this: LocalClient);
}

//------------------------------------------------------------------------------
// Address: 0x100024F0
// Name: public: virtual void CEngineSoundServices::SetSoundFrametime(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::SetSoundFrametime(CEngineSoundServices *this, float realDt, float hostDt)
{
  if ( cl_movieinfo.moviename[0] != 0 )
    this->m_frameTime = hostDt;
  else
    this->m_frameTime = realDt;
}

//------------------------------------------------------------------------------
// Address: 0x10002520
// Name: public: virtual int CEngineSoundServices::GetServerCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineSoundServices::GetServerCount(CEngineSoundServices *this)
{
  return GetBaseLocalClient()->m_nServerCount;
}

//------------------------------------------------------------------------------
// Address: 0x10002530
// Name: public: virtual bool CEngineSoundServices::IsPlayer(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundServices::IsPlayer(CEngineSoundServices *this, int source)
{
  int v3; // esi

  if ( splitscreen->IsLocalPlayerResolvable(this: splitscreen) )
    return source == GetLocalClient(nSlot: -1)->m_nPlayerSlot + 1;
  v3 = 0;
  while ( GetLocalClient(nSlot: v3)->m_nPlayerSlot + 1 != source )
  {
    if ( ++v3 != 0 )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10002590
// Name: public: virtual int CEngineSoundServices::GetSpectatorTarget(enum ClientDLLObserverMode_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineSoundServices::GetSpectatorTarget(
        CEngineSoundServices *this,
        ClientDLLObserverMode_t *pObserverMode)
{
  return ClientDLL_GetSpectatorTarget(pObserverMode);
}

//------------------------------------------------------------------------------
// Address: 0x100025B0
// Name: public: virtual void CEngineSoundServices::OnChangeVoiceStatus(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::OnChangeVoiceStatus(
        CEngineSoundServices *this,
        int entity,
        int iSsSlot,
        BOOL status)
{
  ISteamUser *m_pSteamUser; // edi
  ISteamFriends *m_pSteamFriends; // ebx
  ISteamFriends_vtbl *v6; // esi
  CSteamID *v7; // eax
  CSteamID v8; // [esp+0h] [ebp-8h] BYREF

  if ( iSsSlot >= 0 && Steam3Client()->m_pSteamFriends != nullptr && Steam3Client()->m_pSteamUser != nullptr )
  {
    m_pSteamUser = Steam3Client()->m_pSteamUser;
    m_pSteamFriends = Steam3Client()->m_pSteamFriends;
    v6 = m_pSteamFriends->__vftable;
    v7 = m_pSteamUser->GetSteamID(this: m_pSteamUser, result: &v8);
    ((void (__thiscall *)(ISteamFriends *, _DWORD, _DWORD, BOOL))v6->SetInGameVoiceSpeaking)(
      a1: m_pSteamFriends,
      a2: *(_DWORD *)&v7->m_steamid.m_comp,
      a3: *((_DWORD *)&v7->m_steamid.m_comp + 1),
      a4: status);
  }
  ClientDLL_VoiceStatus(entindex: entity, iSsSlot, bTalking: status);
}

//------------------------------------------------------------------------------
// Address: 0x10002630
// Name: public: virtual bool CEngineSoundServices::GetPlayerAudible(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundServices::GetPlayerAudible(CEngineSoundServices *this, int iPlayerIndex)
{
  return ClientDLL_IsPlayerAudible(iPlayerIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10002650
// Name: public: virtual bool CEngineSoundServices::IsConnected(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundServices::IsConnected(CEngineSoundServices *this)
{
  return GetBaseLocalClient()->m_nSignonState >= 2;
}

//------------------------------------------------------------------------------
// Address: 0x10002660
// Name: public: virtual void CEngineSoundServices::EmitSentenceCloseCaption(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::EmitSentenceCloseCaption(CEngineSoundServices *this, const char *tokenstream)
{
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->EmitSentenceCloseCaption(this: g_ClientDLL, a2: tokenstream);
}

//------------------------------------------------------------------------------
// Address: 0x10002680
// Name: public: virtual void CEngineSoundServices::EmitCloseCaption(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::EmitCloseCaption(
        CEngineSoundServices *this,
        const char *captionname,
        float duration)
{
  if ( g_ClientDLL != nullptr )
    ((void (__stdcall *)(const char *, _DWORD))g_ClientDLL->EmitCloseCaption)(a1: captionname, a2: LODWORD(duration));
}

//------------------------------------------------------------------------------
// Address: 0x100026B0
// Name: public: virtual char const __near * CEngineSoundServices::GetGameDir(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CEngineSoundServices::GetGameDir(CEngineSoundServices *this)
{
  return com_gamedir;
}

//------------------------------------------------------------------------------
// Address: 0x100026C0
// Name: public: virtual bool CEngineSoundServices::IsGamePaused(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundServices::IsGamePaused(CEngineSoundServices *this)
{
  return engineClient != nullptr && engineClient->IsPaused(this: engineClient);
}

//------------------------------------------------------------------------------
// Address: 0x100026E0
// Name: public: virtual void CEngineSoundServices::RestartSoundSystem(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CEngineSoundServices::RestartSoundSystem(CEngineSoundServices *this)
{
  Snd_Restart_f();
}

//------------------------------------------------------------------------------
// Address: 0x100026F0
// Name: public: virtual void CEngineSoundServices::CacheBuildingStart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::CacheBuildingStart(CEngineSoundServices *this)
{
  IEngineVGuiInternal *v1; // eax
  IEngineVGuiInternal *v2; // eax
  wchar_t *v3; // esi
  IEngineVGuiInternal *v4; // eax

  v1 = EngineVGui();
  v1->ActivateGameUI(this: v1);
  v2 = EngineVGui();
  v2->StartCustomProgress(this: v2);
  v3 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#Valve_CreatingCache");
  if ( v3 != nullptr )
  {
    v4 = EngineVGui();
    ((void (__thiscall *)(IEngineVGuiInternal *, _DWORD, wchar_t *))v4->UpdateCustomProgressBar)(
      a1: v4,
      a2: 0.0,
      a3: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002740
// Name: public: virtual void CEngineSoundServices::CacheBuildingUpdateProgress(float,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::CacheBuildingUpdateProgress(
        CEngineSoundServices *this,
        float percent,
        const char *cachefile)
{
  const wchar_t *v3; // esi
  IEngineVGuiInternal *v4; // eax
  _BYTE v5[24]; // [esp+Ch] [ebp-A00h] BYREF
  wchar_t constructed[1024]; // [esp+24h] [ebp-9E8h] BYREF

  v3 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "Valve_CreatingSpecificSoundCache");
  if ( v3 != nullptr )
  {
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: cachefile, a3: &constructed[1012], a4: 512);
    g_pVGuiLocalize->ConstructString_3(
      this: g_pVGuiLocalize,
      a2: (wchar_t *)v5,
      a3: 2048,
      a4: v3,
      a5: 1,
      &constructed[1012]);
    v4 = EngineVGui();
    ((void (__thiscall *)(IEngineVGuiInternal *, _DWORD, _BYTE *))v4->UpdateCustomProgressBar)(
      a1: v4,
      a2: LODWORD(percent),
      a3: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100027D0
// Name: public: virtual void CEngineSoundServices::CacheBuildingFinish(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::CacheBuildingFinish(CEngineSoundServices *this)
{
  IEngineVGuiInternal *v1; // eax
  IEngineVGuiInternal *v2; // eax

  v1 = EngineVGui();
  v1->FinishCustomProgress(this: v1);
  v2 = EngineVGui();
  v2->HideGameUI(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100027F0
// Name: public: virtual int CEngineSoundServices::GetPrecachedSoundCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEngineSoundServices::GetPrecachedSoundCount(CEngineSoundServices *this)
{
  INetworkStringTable *SoundPrecacheTable; // eax

  if ( sv.m_State >= ss_active && (SoundPrecacheTable = CGameServer::GetSoundPrecacheTable(this: &sv)) != nullptr )
    return SoundPrecacheTable->GetNumStrings(this: SoundPrecacheTable);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002820
// Name: public: virtual char const __near * CEngineSoundServices::GetPrecachedSound(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEngineSoundServices::GetPrecachedSound(CEngineSoundServices *this, int index)
{
  INetworkStringTable *SoundPrecacheTable; // eax

  SoundPrecacheTable = CGameServer::GetSoundPrecacheTable(this: &sv);
  if ( SoundPrecacheTable != nullptr )
    return SoundPrecacheTable->GetString(this: SoundPrecacheTable, a2: index);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x10002850
// Name: public: virtual bool CEngineSoundServices::ShouldSuppressNonUISounds(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEngineSoundServices::ShouldSuppressNonUISounds(CEngineSoundServices *this)
{
  IEngineVGuiInternal *v2; // eax

  v2 = EngineVGui();
  return v2->IsGameUIVisible(this: v2) || this->IsGamePaused(this);
}

//------------------------------------------------------------------------------
// Address: 0x10002880
// Name: public: virtual char const __near * CEngineSoundServices::GetUILanguage(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CEngineSoundServices::GetUILanguage(CEngineSoundServices *this)
{
  char *result; // eax

  if ( (cl_language.m_nFlags & 0x1000) != 0 )
    return "FCVAR_NEVER_AS_STRING";
  result = cl_language.m_pParent->m_Value.m_pszString;
  if ( result == nullptr )
    return (char *)defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100028B0
// Name: private: virtual void CEngineSoundServices::OnSoundStarted(int,struct StartSoundParams_t __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::OnSoundStarted(
        CEngineSoundServices *this,
        int guid,
        StartSoundParams_t *params,
        const char *soundname)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  CClientState *BaseLocalClient; // eax
  float Time; // [esp+0h] [ebp-Ch]

  if ( toolframework->IsToolRecording(this: toolframework) && (*((_BYTE *)params + 96) & 8) == 0 )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "StartSound");
    else
      v5 = nullptr;
    KeyValues::SetInt(this: v5, keyName: "guid", value: guid);
    BaseLocalClient = GetBaseLocalClient();
    Time = CClientState::GetTime(this: BaseLocalClient);
    KeyValues::SetFloat(this: v5, keyName: "time", value: Time);
    KeyValues::SetInt(this: v5, keyName: "staticsound", value: *((_BYTE *)params + 96) & 1);
    KeyValues::SetInt(this: v5, keyName: "soundsource", value: params->soundsource);
    KeyValues::SetInt(this: v5, keyName: "entchannel", value: params->entchannel);
    KeyValues::SetString(this: v5, keyName: "soundname", value: soundname);
    KeyValues::SetFloat(this: v5, keyName: "originx", value: params->origin.x);
    KeyValues::SetFloat(this: v5, keyName: "originy", value: params->origin.y);
    KeyValues::SetFloat(this: v5, keyName: "originz", value: params->origin.z);
    KeyValues::SetFloat(this: v5, keyName: "directionx", value: params->direction.x);
    KeyValues::SetFloat(this: v5, keyName: "directiony", value: params->direction.y);
    KeyValues::SetFloat(this: v5, keyName: "directionz", value: params->direction.z);
    KeyValues::SetInt(this: v5, keyName: "updatepositions", value: (*((_BYTE *)params + 96) & 2) != 0);
    KeyValues::SetFloat(this: v5, keyName: "fvol", value: params->fvol);
    KeyValues::SetInt(this: v5, keyName: "soundlevel", value: params->soundlevel);
    KeyValues::SetInt(this: v5, keyName: "flags", value: params->flags);
    KeyValues::SetInt(this: v5, keyName: "pitch", value: params->pitch);
    KeyValues::SetInt(this: v5, keyName: "fromserver", value: (*((_BYTE *)params + 96) & 4) != 0);
    KeyValues::SetFloat(this: v5, keyName: "delay", value: params->delay);
    KeyValues::SetInt(this: v5, keyName: "speakerentity", value: params->speakerentity);
    toolframework->PostMessageA(this: toolframework, a2: v5);
    KeyValues::deleteThis(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002A90
// Name: private: virtual void CEngineSoundServices::OnSoundStopped(int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::OnSoundStopped(
        CEngineSoundServices *this,
        int guid,
        int soundsource,
        int channel,
        const char *soundname)
{
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  CClientState *BaseLocalClient; // eax
  float Time; // [esp+0h] [ebp-8h]

  if ( toolframework->IsToolRecording(this: toolframework) )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "StopSound");
    else
      v6 = nullptr;
    KeyValues::SetInt(this: v6, keyName: "guid", value: guid);
    BaseLocalClient = GetBaseLocalClient();
    Time = CClientState::GetTime(this: BaseLocalClient);
    KeyValues::SetFloat(this: v6, keyName: "time", value: Time);
    KeyValues::SetInt(this: v6, keyName: "soundsource", value: soundsource);
    KeyValues::SetInt(this: v6, keyName: "entchannel", value: channel);
    KeyValues::SetString(this: v6, keyName: "soundname", value: soundname);
    toolframework->PostMessageA(this: toolframework, a2: v6);
    KeyValues::deleteThis(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002B50
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 255, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100038E0
// Name: public: virtual void CEngineSoundServices::GetAllManifestFiles(class CUtlRBTree<void __near *,int,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEngineSoundServices::GetAllManifestFiles(
        CEngineSoundServices *this@<ecx>,
        int a2@<esi>,
        CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *list)
{
  void *v3; // ebx
  int v4; // esi
  char *v5; // edi
  const char *i; // esi
  char manifest_file[516]; // [esp+4h] [ebp-208h] BYREF
  void *handle; // [esp+208h] [ebp-4h] BYREF

  CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::RemoveAll(this: list);
  v3 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: "maplist.txt", a3: "rb", a4: "MOD");
  if ( v3 != nullptr )
  {
    v4 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))g_pFileSystem->Size_2)(
           a1: &g_pFileSystem->IBaseFileSystem,
           a2: v3,
           a3: a2);
    if ( v4 > 0 )
    {
      v5 = (char *)MemAlloc_Alloc(nSize: v4 + 1);
      if ( v5 != nullptr && v4 == g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v5, a3: v4, a4: v3) )
      {
        v5[v4] = 0;
        for ( i = COM_Parse(data: v5); strlen(com_token) != 0; i = COM_Parse(data: i) )
        {
          V_snprintf(pDest: manifest_file, maxLen: 512, pFormat: "%s/%s.manifest", "maps/soundcache", com_token);
          if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: manifest_file, a3: "MOD") )
          {
            handle = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: manifest_file);
            if ( CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::Find(
                   this: list,
                   search: &handle) == -1 )
              CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::Insert(
                this: list,
                insert: &handle);
          }
          for ( ; COM_TokenWaiting(buffer: i) != 0; i = COM_Parse(data: i) )
            ;
        }
      }
      free(pMem: v5);
    }
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
  }
  else
  {
    _Warning(a1: "GetAllManifestFiles:  Unable to load %s\n", "maplist.txt");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003AA0
// Name: private: void CEngineSoundServices::CacheSoundsFromResFile(bool,class CUtlRBTree<void __near *,int,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,int>,int>> __near &,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEngineSoundServices::CacheSoundsFromResFile(
        CEngineSoundServices *this@<ecx>,
        int a2@<edi>,
        bool quiet,
        CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *list,
        const char *resfile,
        bool checkandcleanname)
{
  const char *v6; // esi
  CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *v7; // edi
  void *v8; // ebx
  int v9; // eax
  int v10; // esi
  char *v11; // ebx
  const char *i; // esi
  char v13; // cl
  char *j; // eax
  int oldCount; // [esp+4h] [ebp-10h]
  void *resfilehandle; // [esp+Ch] [ebp-8h]
  void *search; // [esp+10h] [ebp-4h] BYREF

  v6 = resfile;
  if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: resfile, a3: "MOD") )
  {
    v7 = list;
    oldCount = list->m_NumElements;
    v8 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: v6, a3: "rb", a4: "MOD");
    resfilehandle = v8;
    if ( v8 != nullptr )
    {
      v9 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))g_pFileSystem->Size_2)(
             a1: &g_pFileSystem->IBaseFileSystem,
             a2: v8,
             a3: a2);
      v10 = v9;
      if ( v9 > 0 )
      {
        v11 = (char *)MemAlloc_Alloc(nSize: v9 + 1);
        if ( v11 != nullptr
          && v10 == g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v11, a3: v10, a4: resfilehandle) )
        {
          v11[v10] = 0;
          for ( i = COM_Parse(data: v11); strlen(com_token) != 0; i = COM_Parse(data: i) )
          {
            if ( checkandcleanname )
            {
              if ( V_stristr(pStr: com_token, pSearch: ".wav") != nullptr
                || V_stristr(pStr: com_token, pSearch: ".mp3") != nullptr )
              {
                V_FixSlashes(pname: com_token, separator: 92);
                v13 = com_token[0];
                for ( j = com_token; v13 != 0; v13 = *++j )
                {
                  if ( v13 == 92 )
                    break;
                }
                list = (CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *)g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: j + 1);
                if ( CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::Find(
                       this: v7,
                       search: (void *const *)&list) == -1 )
                  CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::Insert(
                    this: v7,
                    insert: (void *const *)&list);
              }
            }
            else
            {
              search = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: com_token);
              if ( CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::Find(
                     this: v7,
                     &search) == -1 )
                CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::Insert(
                  this: v7,
                  insert: &search);
            }
          }
        }
        free(pMem: v11);
        v8 = resfilehandle;
      }
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v8);
      v6 = resfile;
    }
    if ( !quiet )
      _Msg(a1: "Processing (%i new) from %s\n", v7->m_NumElements - oldCount, v6);
  }
  else
  {
    _Warning(a1: "CacheSoundsFromResFile:  Unable to find '%s'\n", v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003CC0
// Name: public: virtual void CEngineSoundServices::GetAllSoundFilesInManifest(class CUtlRBTree<void __near *,int,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,int>,int>> __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::GetAllSoundFilesInManifest(
        CEngineSoundServices *this,
        CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *list,
        const char *manifestfile)
{
  CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::RemoveAll(this: list);
  CEngineSoundServices::CacheSoundsFromResFile(this, quiet: true, list, resfile: manifestfile, checkandcleanname: false);
}

//------------------------------------------------------------------------------
// Address: 0x10003CF0
// Name: public: virtual void CEngineSoundServices::GetAllSoundFilesReferencedInReslists(class CUtlRBTree<void __near *,int,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEngineSoundServices::GetAllSoundFilesReferencedInReslists(
        CEngineSoundServices *this@<ecx>,
        int a2@<esi>,
        CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *list)
{
  CMapReslistGenerator *v4; // eax
  const char *ResListDirectory; // eax
  void *v7; // eax
  int v8; // eax
  int v9; // esi
  const char *i; // esi
  CFmtStrN<256> *v11; // eax
  CFmtStrN<256> *v12; // eax
  char resfile[512]; // [esp+8h] [ebp-30Ch] BYREF
  char reslistdir[264]; // [esp+208h] [ebp-10Ch] BYREF
  void *resfilehandle; // [esp+310h] [ebp-4h]
  char *pStart; // [esp+31Ch] [ebp+8h]

  v4 = MapReslistGenerator();
  ResListDirectory = CMapReslistGenerator::GetResListDirectory(this: v4);
  V_strncpy(pDest: reslistdir, pSrc: ResListDirectory, maxLen: 260);
  CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::RemoveAll(this: list);
  v7 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: "maplist.txt", a3: "rb", a4: "MOD");
  resfilehandle = v7;
  if ( v7 != nullptr )
  {
    v8 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))g_pFileSystem->Size_2)(
           a1: &g_pFileSystem->IBaseFileSystem,
           a2: v7,
           a3: a2);
    v9 = v8;
    if ( v8 > 0 )
    {
      pStart = (char *)MemAlloc_Alloc(nSize: v8 + 1);
      if ( pStart != nullptr
        && v9 == g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: pStart, a3: v9, a4: resfilehandle) )
      {
        pStart[v9] = 0;
        for ( i = COM_Parse(data: pStart); strlen(com_token) != 0; i = COM_Parse(data: i) )
        {
          V_snprintf(pDest: resfile, maxLen: 512, pFormat: "%s\\%s.lst", reslistdir, com_token);
          CEngineSoundServices::CacheSoundsFromResFile(this, quiet: false, list, resfile, checkandcleanname: true);
          for ( ; COM_TokenWaiting(buffer: i) != 0; i = COM_Parse(data: i) )
            ;
        }
      }
      free(pMem: pStart);
    }
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: resfilehandle);
    v11 = CFmtStrN<256>::CFmtStrN<256>(this: (CFmtStrN<256> *)&resfile[244], pszFormat: "%s\\engine.lst", reslistdir);
    CEngineSoundServices::CacheSoundsFromResFile(
      this,
      quiet: false,
      list,
      resfile: v11->m_szBuf,
      checkandcleanname: true);
    v12 = CFmtStrN<256>::CFmtStrN<256>(this: (CFmtStrN<256> *)&resfile[244], pszFormat: "%s\\all.lst", reslistdir);
    CEngineSoundServices::CacheSoundsFromResFile(
      this,
      quiet: false,
      list,
      resfile: v12->m_szBuf,
      checkandcleanname: true);
  }
  else
  {
    _Warning(a1: "GetAllSoundFilesReferencedInReslists:  Unable to load file %s\n", "maplist.txt");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100CDF20
// Name: public: virtual float CEngineSoundServices::GetHostFrametime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineSoundServices::GetHostFrametime(CEngineSoundServices *this)
{
  return this->m_frameTime;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100023C0
// Name: public: virtual bool CBaseServer::IsActive(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseServer::IsActive(CBaseServer *this)
{
  return this->m_State >= ss_active;
}

//------------------------------------------------------------------------------
// Address: 0x100023F0
// Name: public: virtual void CEngineSoundServices::OnExtraUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::OnExtraUpdate(CEngineSoundServices *this)
{
  if ( g_ClientDLL != nullptr && game != nullptr && game->IsActiveApp(this: game) )
    g_ClientDLL->IN_Accumulate(this: g_ClientDLL);
}

//------------------------------------------------------------------------------
// Address: 0x10002420
// Name: public: virtual bool CEngineSoundServices::GetSoundSpatialization(int,struct SpatializationInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundServices::GetSoundSpatialization(
        CEngineSoundServices *this,
        int entIndex,
        SpatializationInfo_t *info)
{
  IClientEntity *v4; // edi
  IMDLCache *v5; // esi
  bool v6; // bl

  if ( entitylist == nullptr )
    return false;
  v4 = entitylist->GetClientEntity(this: entitylist, a2: entIndex);
  if ( v4 == nullptr )
    return false;
  v5 = g_pMDLCache;
  g_pMDLCache->BeginLock(this: g_pMDLCache);
  v6 = v4->GetSoundSpatialization(this: v4, a2: info);
  v5->EndLock(this: v5);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10002480
// Name: public: virtual bool CEngineSoundServices::GetToolSpatialization(int,int,struct SpatializationInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundServices::GetToolSpatialization(
        CEngineSoundServices *this,
        int iUserData,
        int guid,
        SpatializationInfo_t *info)
{
  return toolframework->GetSoundSpatialization(this: toolframework, a2: iUserData, a3: guid, a4: info);
}

//------------------------------------------------------------------------------
// Address: 0x100024A0
// Name: public: virtual float CEngineSoundServices::GetClientTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineSoundServices::GetClientTime(CEngineSoundServices *this)
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  return CClientState::GetTime(this: BaseLocalClient);
}

//------------------------------------------------------------------------------
// Address: 0x100024E0
// Name: public: virtual void CEngineSoundServices::SetSoundFrametime(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::SetSoundFrametime(CEngineSoundServices *this, float realDt, float hostDt)
{
  if ( cl_movieinfo.moviename[0] != 0 )
    this->m_frameTime = hostDt;
  else
    this->m_frameTime = realDt;
}

//------------------------------------------------------------------------------
// Address: 0x10002510
// Name: public: virtual float CEngineSoundServices::GetHostFrametime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CEngineSoundServices::GetHostFrametime(CEngineSoundServices *this)
{
  return this->m_frameTime;
}

//------------------------------------------------------------------------------
// Address: 0x10002670
// Name: public: virtual void CEngineSoundServices::EmitCloseCaption(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::EmitCloseCaption(
        CEngineSoundServices *this,
        const char *captionname,
        float duration)
{
  if ( g_ClientDLL != nullptr )
    ((void (__stdcall *)(const char *, _DWORD))g_ClientDLL->EmitCloseCaption)(a1: captionname, a2: LODWORD(duration));
}

//------------------------------------------------------------------------------
// Address: 0x100026A0
// Name: public: virtual bool CEngineSoundServices::IsGamePaused(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundServices::IsGamePaused(CEngineSoundServices *this)
{
  return engineClient != nullptr && engineClient->IsPaused(this: engineClient);
}

//------------------------------------------------------------------------------
// Address: 0x100026D0
// Name: public: virtual void CEngineSoundServices::CacheBuildingStart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::CacheBuildingStart(CEngineSoundServices *this)
{
  IEngineVGuiInternal *v1; // eax
  IEngineVGuiInternal *v2; // eax
  wchar_t *v3; // esi
  IEngineVGuiInternal *v4; // eax

  v1 = EngineVGui();
  v1->ActivateGameUI(this: v1);
  v2 = EngineVGui();
  v2->StartCustomProgress(this: v2);
  v3 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#Valve_CreatingCache");
  if ( v3 != nullptr )
  {
    v4 = EngineVGui();
    ((void (__thiscall *)(IEngineVGuiInternal *, _DWORD, wchar_t *))v4->UpdateCustomProgressBar)(
      a1: v4,
      a2: 0.0,
      a3: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002720
// Name: public: virtual void CEngineSoundServices::CacheBuildingUpdateProgress(float,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::CacheBuildingUpdateProgress(
        CEngineSoundServices *this,
        float percent,
        const char *cachefile)
{
  const wchar_t *v3; // esi
  IEngineVGuiInternal *v4; // eax
  wchar_t constructed[1024]; // [esp+1Ch] [ebp-A00h] BYREF
  wchar_t file[256]; // [esp+81Ch] [ebp-200h] BYREF

  v3 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "Valve_CreatingSpecificSoundCache");
  if ( v3 != nullptr )
  {
    g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: cachefile, a3: file, a4: 512);
    g_pVGuiLocalize->ConstructString_3(this: g_pVGuiLocalize, a2: constructed, a3: 2048, a4: v3, a5: 1, file);
    v4 = EngineVGui();
    ((void (__thiscall *)(IEngineVGuiInternal *, _DWORD, wchar_t *))v4->UpdateCustomProgressBar)(
      a1: v4,
      a2: LODWORD(percent),
      a3: constructed);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100027B0
// Name: public: virtual void CEngineSoundServices::CacheBuildingFinish(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::CacheBuildingFinish(CEngineSoundServices *this)
{
  IEngineVGuiInternal *v1; // eax
  IEngineVGuiInternal *v2; // eax

  v1 = EngineVGui();
  v1->FinishCustomProgress(this: v1);
  v2 = EngineVGui();
  v2->HideGameUI(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10002800
// Name: public: virtual char const __near * CEngineSoundServices::GetPrecachedSound(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CEngineSoundServices::GetPrecachedSound(CEngineSoundServices *this, int index)
{
  INetworkStringTable *SoundPrecacheTable; // eax

  SoundPrecacheTable = CGameServer::GetSoundPrecacheTable(this: &sv);
  if ( SoundPrecacheTable != nullptr )
    return SoundPrecacheTable->GetString(this: SoundPrecacheTable, a2: index);
  else
    return defaultValue;
}

//------------------------------------------------------------------------------
// Address: 0x10002830
// Name: public: virtual bool CEngineSoundServices::ShouldSuppressNonUISounds(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CEngineSoundServices::ShouldSuppressNonUISounds(CEngineSoundServices *this)
{
  IEngineVGuiInternal *v2; // eax

  v2 = EngineVGui();
  return v2->IsGameUIVisible(this: v2) || this->IsGamePaused(this);
}

//------------------------------------------------------------------------------
// Address: 0x10002860
// Name: public: virtual char const __near * CEngineSoundServices::GetUILanguage(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CEngineSoundServices::GetUILanguage(CEngineSoundServices *this)
{
  char *result; // eax

  if ( (cl_language.m_nFlags & 0x1000) != 0 )
    return "FCVAR_NEVER_AS_STRING";
  result = cl_language.m_pParent->m_Value.m_pszString;
  if ( result == nullptr )
    return (char *)defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002890
// Name: private: virtual void CEngineSoundServices::OnSoundStarted(int,struct StartSoundParams_t __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::OnSoundStarted(
        CEngineSoundServices *this,
        int guid,
        StartSoundParams_t *params,
        const char *soundname)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  CClientState *BaseLocalClient; // eax
  float value; // [esp+0h] [ebp-Ch]

  if ( toolframework->IsToolRecording(this: toolframework) && (*((_BYTE *)params + 96) & 8) == 0 )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "StartSound");
    else
      v5 = nullptr;
    KeyValues::SetInt(this: v5, keyName: "guid", value: guid);
    BaseLocalClient = GetBaseLocalClient();
    value = CClientState::GetTime(this: BaseLocalClient);
    KeyValues::SetFloat(this: v5, keyName: "time", value);
    KeyValues::SetInt(this: v5, keyName: "staticsound", value: *((_BYTE *)params + 96) & 1);
    KeyValues::SetInt(this: v5, keyName: "soundsource", value: params->soundsource);
    KeyValues::SetInt(this: v5, keyName: "entchannel", value: params->entchannel);
    KeyValues::SetString(this: v5, keyName: "soundname", value: soundname);
    KeyValues::SetFloat(this: v5, keyName: "originx", value: params->origin.x);
    KeyValues::SetFloat(this: v5, keyName: "originy", value: params->origin.y);
    KeyValues::SetFloat(this: v5, keyName: "originz", value: params->origin.z);
    KeyValues::SetFloat(this: v5, keyName: "directionx", value: params->direction.x);
    KeyValues::SetFloat(this: v5, keyName: "directiony", value: params->direction.y);
    KeyValues::SetFloat(this: v5, keyName: "directionz", value: params->direction.z);
    KeyValues::SetInt(this: v5, keyName: "updatepositions", value: (*((_BYTE *)params + 96) & 2) != 0);
    KeyValues::SetFloat(this: v5, keyName: "fvol", value: params->fvol);
    KeyValues::SetInt(this: v5, keyName: "soundlevel", value: params->soundlevel);
    KeyValues::SetInt(this: v5, keyName: "flags", value: params->flags);
    KeyValues::SetInt(this: v5, keyName: "pitch", value: params->pitch);
    KeyValues::SetInt(this: v5, keyName: "fromserver", value: (*((_BYTE *)params + 96) & 4) != 0);
    KeyValues::SetFloat(this: v5, keyName: "delay", value: params->delay);
    KeyValues::SetInt(this: v5, keyName: "speakerentity", value: params->speakerentity);
    toolframework->PostMessageA(this: toolframework, a2: v5);
    KeyValues::deleteThis(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002A70
// Name: private: virtual void CEngineSoundServices::OnSoundStopped(int,int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::OnSoundStopped(
        CEngineSoundServices *this,
        int guid,
        int soundsource,
        int channel,
        const char *soundname)
{
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  CClientState *BaseLocalClient; // eax
  float value; // [esp+0h] [ebp-8h]

  if ( toolframework->IsToolRecording(this: toolframework) )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "StopSound");
    else
      v6 = nullptr;
    KeyValues::SetInt(this: v6, keyName: "guid", value: guid);
    BaseLocalClient = GetBaseLocalClient();
    value = CClientState::GetTime(this: BaseLocalClient);
    KeyValues::SetFloat(this: v6, keyName: "time", value);
    KeyValues::SetInt(this: v6, keyName: "soundsource", value: soundsource);
    KeyValues::SetInt(this: v6, keyName: "entchannel", value: channel);
    KeyValues::SetString(this: v6, keyName: "soundname", value: soundname);
    toolframework->PostMessageA(this: toolframework, a2: v6);
    KeyValues::deleteThis(this: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002B20
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 255, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100038B0
// Name: public: virtual void CEngineSoundServices::GetAllManifestFiles(class CUtlRBTree<void __near *,int,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,int>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEngineSoundServices::GetAllManifestFiles(
        CEngineSoundServices *this@<ecx>,
        int a2@<esi>,
        CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *list)
{
  void *v3; // ebx
  int v4; // esi
  char *v5; // edi
  const char *i; // esi
  char manifest_file[516]; // [esp+4h] [ebp-208h] BYREF
  void *handle; // [esp+208h] [ebp-4h] BYREF

  CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::RemoveAll(this: list);
  v3 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: "maplist.txt", a3: "rb", a4: "MOD");
  if ( v3 != nullptr )
  {
    v4 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))g_pFileSystem->Size_2)(
           a1: &g_pFileSystem->IBaseFileSystem,
           a2: v3,
           a3: a2);
    if ( v4 > 0 )
    {
      v5 = (char *)MemAlloc_Alloc(nSize: v4 + 1);
      if ( v5 != nullptr && v4 == g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v5, a3: v4, a4: v3) )
      {
        v5[v4] = 0;
        for ( i = COM_Parse(data: v5); strlen(com_token) != 0; i = COM_Parse(data: i) )
        {
          V_snprintf(pDest: manifest_file, maxLen: 512, pFormat: "%s/%s.manifest", "maps/soundcache", com_token);
          if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: manifest_file, a3: "MOD") )
          {
            handle = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: manifest_file);
            if ( CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::Find(
                   this: list,
                   search: &handle) == -1 )
              CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::Insert(
                this: list,
                insert: &handle);
          }
          for ( ; COM_TokenWaiting(buffer: i) != 0; i = COM_Parse(data: i) )
            ;
        }
      }
      free(pMem: v5);
    }
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
  }
  else
  {
    _Warning(a1: "GetAllManifestFiles:  Unable to load %s\n", "maplist.txt");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003A70
// Name: private: void CEngineSoundServices::CacheSoundsFromResFile(bool,class CUtlRBTree<void __near *,int,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,int>,int>> __near &,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CEngineSoundServices::CacheSoundsFromResFile(
        CEngineSoundServices *this@<ecx>,
        int a2@<edi>,
        bool quiet,
        CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *list,
        const char *resfile,
        bool checkandcleanname)
{
  const char *v6; // esi
  CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *v7; // edi
  void *v8; // ebx
  int v9; // eax
  int v10; // esi
  char *v11; // ebx
  const char *i; // esi
  char v13; // cl
  char *j; // eax
  int oldCount; // [esp+4h] [ebp-10h]
  void *resfilehandle; // [esp+Ch] [ebp-8h]
  void *search; // [esp+10h] [ebp-4h] BYREF

  v6 = resfile;
  if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: resfile, a3: "MOD") )
  {
    v7 = list;
    oldCount = list->m_NumElements;
    v8 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: v6, a3: "rb", a4: "MOD");
    resfilehandle = v8;
    if ( v8 != nullptr )
    {
      v9 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))g_pFileSystem->Size_2)(
             a1: &g_pFileSystem->IBaseFileSystem,
             a2: v8,
             a3: a2);
      v10 = v9;
      if ( v9 > 0 )
      {
        v11 = (char *)MemAlloc_Alloc(nSize: v9 + 1);
        if ( v11 != nullptr
          && v10 == g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v11, a3: v10, a4: resfilehandle) )
        {
          v11[v10] = 0;
          for ( i = COM_Parse(data: v11); strlen(com_token) != 0; i = COM_Parse(data: i) )
          {
            if ( checkandcleanname )
            {
              if ( V_stristr(pStr: com_token, pSearch: ".wav") != nullptr
                || V_stristr(pStr: com_token, pSearch: ".mp3") != nullptr )
              {
                V_FixSlashes(pname: com_token, separator: 92);
                v13 = com_token[0];
                for ( j = com_token; v13 != 0; v13 = *++j )
                {
                  if ( v13 == 92 )
                    break;
                }
                list = (CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *)g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: j + 1);
                if ( CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::Find(
                       this: v7,
                       search: (void *const *)&list) == -1 )
                  CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::Insert(
                    this: v7,
                    insert: (void *const *)&list);
              }
            }
            else
            {
              search = g_pFileSystem->FindOrAddFileName(this: g_pFileSystem, a2: com_token);
              if ( CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::Find(
                     this: v7,
                     &search) == -1 )
                CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::Insert(
                  this: v7,
                  insert: &search);
            }
          }
        }
        free(pMem: v11);
        v8 = resfilehandle;
      }
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v8);
      v6 = resfile;
    }
    if ( !quiet )
      _Msg(a1: "Processing (%i new) from %s\n", v7->m_NumElements - oldCount, v6);
  }
  else
  {
    _Warning(a1: "CacheSoundsFromResFile:  Unable to find '%s'\n", v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003C90
// Name: public: virtual void CEngineSoundServices::GetAllSoundFilesInManifest(class CUtlRBTree<void __near *,int,bool (*)(void __near * const __near &,void __near * const __near &),class CUtlMemory<struct UtlRBTreeNode_t<void __near *,int>,int>> __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEngineSoundServices::GetAllSoundFilesInManifest(
        CEngineSoundServices *this,
        CUtlRBTree<void *,int,bool (__cdecl*)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int> > *list,
        const char *manifestfile)
{
  CUtlRBTree<void *,int,bool (__cdecl *)(void * const &,void * const &),CUtlMemory<UtlRBTreeNode_t<void *,int>,int>>::RemoveAll(this: list);
  CEngineSoundServices::CacheSoundsFromResFile(
    this,
    a2: (int)list,
    quiet: true,
    list,
    resfile: manifestfile,
    checkandcleanname: false);
}

//------------------------------------------------------------------------------
// Address: 0x1006E930
// Name: public: virtual char const __near * CEngineSoundServices::GetGameDir(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CEngineSoundServices::GetGameDir(CEngineSoundServices *this)
{
  return com_gamedir;
}

//------------------------------------------------------------------------------
// Address: 0x10070400
// Name: public: virtual bool CEngineSoundServices::IsConnected(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CEngineSoundServices::IsConnected(CEngineSoundServices *this)
{
  return GetBaseLocalClient()->m_nSignonState >= 2;
}

} // namespace engine_xlsp
