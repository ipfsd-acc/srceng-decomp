// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_main.cpp
// Functions: 212
// ============================================================

#include "engine\cl_main.h"

//------------------------------------------------------------------------------
// Address: 0x100878B0
// Name: void CL_HandlePureServerWhitelist(class CPureServerWhitelist __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CL_HandlePureServerWhitelist(int a1@<edi>, CPureServerWhitelist *pWhitelist)
{
  CClientState *BaseLocalClient; // eax
  CPureServerWhitelist::CForceMatchList *ForceMatchList; // edi
  CPureServerWhitelist::CAllowFromDiskList *AllowFromDiskList; // ebx
  IFileList *pFilesToReload; // [esp+0h] [ebp-4h] BYREF

  if ( GetBaseLocalClient()->m_pPureServerWhitelist != nullptr )
  {
    BaseLocalClient = GetBaseLocalClient();
    CPureServerWhitelist::Release(this: BaseLocalClient->m_pPureServerWhitelist);
  }
  ForceMatchList = nullptr;
  AllowFromDiskList = nullptr;
  GetBaseLocalClient()->m_pPureServerWhitelist = pWhitelist;
  if ( pWhitelist != nullptr )
  {
    ForceMatchList = CPureServerWhitelist::GetForceMatchList(this: pWhitelist);
    AllowFromDiskList = CPureServerWhitelist::GetAllowFromDiskList(this: pWhitelist);
  }
  ((void (__thiscall *)(IFileSystem *, CPureServerWhitelist::CForceMatchList *, CPureServerWhitelist::CAllowFromDiskList *, IFileList **, int))g_pFileSystem->RegisterFileWhitelist)(
    a1: g_pFileSystem,
    a2: ForceMatchList,
    a3: AllowFromDiskList,
    a4: &pFilesToReload,
    a5: a1);
  if ( pFilesToReload != nullptr )
  {
    materials->ReloadFilesInList(this: materials, a2: pFilesToReload);
    pFilesToReload->Release(this: pFilesToReload);
  }
  GetBaseLocalClient()->m_bCheckCRCsWithServer = ForceMatchList != nullptr && AllowFromDiskList != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10087970
// Name: void CL_PrintWhitelistInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_PrintWhitelistInfo()
{
  CClientState *BaseLocalClient; // eax
  CClientState *v1; // eax

  if ( GetBaseLocalClient()->m_pPureServerWhitelist != nullptr )
  {
    BaseLocalClient = GetBaseLocalClient();
    if ( CPureServerWhitelist::IsInFullyPureMode(this: BaseLocalClient->m_pPureServerWhitelist) )
    {
      _Msg(a1: "The server is using sv_pure = 2.\n");
    }
    else
    {
      _Msg(a1: "The server is using sv_pure = 1.\n");
      v1 = GetBaseLocalClient();
      CPureServerWhitelist::PrintWhitelistContents(this: v1->m_pPureServerWhitelist);
    }
  }
  else
  {
    _Msg(a1: "The server is using sv_pure = 0 (no whitelist).\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100879D0
// Name: struct CPrecacheUserData const __near * CL_GetPrecacheUserData(class INetworkStringTable __near *,int)
// Source: json
//------------------------------------------------------------------------------
const CPrecacheUserData *__cdecl CL_GetPrecacheUserData(INetworkStringTable *table, int index)
{
  int v2; // ebx
  INetworkStringTable *v3; // esi
  const CPrecacheUserData *result; // eax
  const CPrecacheUserData *v5; // edi
  int v6; // eax
  int v7; // [esp-8h] [ebp-14h]
  int v8; // [esp-4h] [ebp-10h]

  v2 = index;
  v3 = table;
  result = (const CPrecacheUserData *)table->GetStringUserData(this: table, a2: index, a3: &table);
  v5 = result;
  if ( result != nullptr )
  {
    if ( table != (INetworkStringTable *)1 )
    {
      v6 = ((int (__thiscall *)(INetworkStringTable *, int, INetworkStringTable *))v3->GetTableId)(
             a1: v3,
             a2: v2,
             a3: table);
      _Error(a1: "CL_GetPrecacheUserData(%d,%d) - length (%d) invalid.", v6, v7, v8);
    }
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10087A20
// Name: void CL_InitHL2DemoFlag(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_InitHL2DemoFlag()
{
  const char *ModDirectory; // eax
  ISteamApps *m_pSteamApps; // edi
  ISteamApps_vtbl *v2; // esi
  int AppSteamAppId; // eax
  const char *v4; // eax
  int v5; // eax

  if ( !initialized )
  {
    if ( Steam3Client()->m_pSteamApps != nullptr )
    {
      ModDirectory = COM_GetModDirectory();
      if ( _V_stricmp(s1: ModDirectory, s2: "hl2") == 0 && g_pFileSystem->IsSteam(this: g_pFileSystem) )
      {
        initialized = true;
        m_pSteamApps = Steam3Client()->m_pSteamApps;
        v2 = m_pSteamApps->__vftable;
        AppSteamAppId = GetAppSteamAppId(eSourceApp: k_App_HL2);
        s_bIsHL2Demo = !v2->BIsSubscribedApp(this: m_pSteamApps, a2: AppSteamAppId);
      }
    }
    v4 = COM_GetModDirectory();
    if ( _V_stricmp(s1: v4, s2: "hl2") == 0 )
    {
      v5 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 12))(a1: v5, a2: "-demo", a3: 0) != 0 )
        s_bIsHL2Demo = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087AD0
// Name: bool CL_IsHL2Demo(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CL_IsHL2Demo()
{
  CL_InitHL2DemoFlag();
  return s_bIsHL2Demo;
}

//------------------------------------------------------------------------------
// Address: 0x10087AE0
// Name: void CL_InitPortalDemoFlag(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_InitPortalDemoFlag()
{
  const char *ModDirectory; // eax
  ISteamApps *m_pSteamApps; // edi
  ISteamApps_vtbl *v2; // esi
  int AppSteamAppId; // eax
  const char *v4; // eax
  int v5; // eax

  if ( !initialized_0 )
  {
    if ( Steam3Client()->m_pSteamApps != nullptr )
    {
      ModDirectory = COM_GetModDirectory();
      if ( _V_stricmp(s1: ModDirectory, s2: "portal") == 0 && g_pFileSystem->IsSteam(this: g_pFileSystem) )
      {
        initialized_0 = true;
        m_pSteamApps = Steam3Client()->m_pSteamApps;
        v2 = m_pSteamApps->__vftable;
        AppSteamAppId = GetAppSteamAppId(eSourceApp: k_App_PORTAL);
        s_bIsPortalDemo = !v2->BIsSubscribedApp(this: m_pSteamApps, a2: AppSteamAppId);
      }
    }
    v4 = COM_GetModDirectory();
    if ( _V_stricmp(s1: v4, s2: "portal") == 0 )
    {
      v5 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 12))(a1: v5, a2: "-demo", a3: 0) != 0 )
        s_bIsPortalDemo = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087B90
// Name: bool CL_IsPortalDemo(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CL_IsPortalDemo()
{
  CL_InitPortalDemoFlag();
  return s_bIsPortalDemo;
}

//------------------------------------------------------------------------------
// Address: 0x10087BA0
// Name: bool CL_CheckCRCs(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CL_CheckCRCs(const char *pszMap)
{
  int v2; // edi
  char szDllName[96]; // [esp+0h] [ebp-6Ch] BYREF
  unsigned int clientDllCRC; // [esp+60h] [ebp-Ch] BYREF
  unsigned int mapCRC; // [esp+64h] [ebp-8h] BYREF
  void *fp; // [esp+68h] [ebp-4h] BYREF

  if ( GetBaseLocalClient()->serverCRC == 0 && GetBaseLocalClient()->serverClientSideDllCRC == 0 )
    return 1;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CL_CheckCRCs",
    a3: 0,
    a4: "Steam",
    a5: false,
    a6: 4);
  if ( sv.m_State >= ss_active )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  CRC32_Init(pulCRC: &mapCRC);
  if ( CRC_MapFile(crcvalue: &mapCRC, pszFileName: pszMap) )
  {
    if ( GetBaseLocalClient()->serverCRC == mapCRC || demoplayer->IsPlayingBack(this: demoplayer) )
    {
      V_snprintf(pDest: szDllName, maxLen: 96, pFormat: "bin\\client.dll");
      if ( CRC_File(crcvalue: &clientDllCRC, pszFileName: szDllName) || demoplayer->IsPlayingBack(this: demoplayer) )
      {
        if ( GetBaseLocalClient()->serverClientSideDllCRC != -1
          && GetBaseLocalClient()->serverClientSideDllCRC != clientDllCRC
          && !demoplayer->IsPlayingBack(this: demoplayer) )
        {
          _Warning(a1: "Your .dll [%s] differs from the server's.\n", szDllName);
        }
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        return 1;
      }
      else
      {
        COM_ExplainDisconnection(bPrint: true, fmt: "Couldn't CRC client side dll %s.\n", szDllName);
        Host_Error(error: "Disconnected");
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        return 0;
      }
    }
    else
    {
      COM_ExplainDisconnection(bPrint: true, fmt: "Your map [%s] differs from the server's.\n", pszMap);
      Host_Error(error: "Disconnected");
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return 0;
    }
  }
  else
  {
    fp = nullptr;
    v2 = COM_OpenFile(filename: pszMap, file: &fp);
    if ( fp != nullptr )
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: fp);
    if ( v2 == -1 )
      COM_ExplainDisconnection(bPrint: true, fmt: "Missing map %s, disconnecting\n", pszMap);
    else
      COM_ExplainDisconnection(bPrint: true, fmt: "Couldn't CRC map %s, disconnecting\n", pszMap);
    Host_Error(error: "Disconnected");
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087D90
// Name: void CL_ReallocateDynamicData(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_ReallocateDynamicData()
{
  if ( entitylist != nullptr )
    entitylist->SetMaxEntities(this: entitylist, a2: 2048);
}

//------------------------------------------------------------------------------
// Address: 0x10087DB0
// Name: CL_SoundMessageLessFunc
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CL_SoundMessageLessFunc(const SoundInfo_t *sound1, const SoundInfo_t *sound2)
{
  return sound1->nSequenceNumber < sound2->nSequenceNumber;
}

//------------------------------------------------------------------------------
// Address: 0x10087DD0
// Name: void CL_SetupMapName(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_SetupMapName(char *pName, char *pFixedName, int maxlen)
{
  unsigned int v3; // eax
  unsigned int v4; // esi
  unsigned int v5; // eax
  const char *v6; // esi
  _BYTE *v7; // eax

  strrchr(string: (unsigned __int8 *)pName, chr: 0x5Cu);
  v4 = v3;
  strrchr(string: (unsigned __int8 *)pName, chr: 0x2Fu);
  if ( v5 > v4 )
    v4 = v5;
  if ( v4 != 0 )
    v6 = (const char *)(v4 + 1);
  else
    v6 = pName;
  V_strncpy(pDest: pFixedName, pSrc: v6, maxLen: maxlen);
  strchr(string: (unsigned __int8 *)pFixedName, chr: 0x2Eu);
  if ( v7 != nullptr )
    *v7 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10087E20
// Name: int CL_GetServerQueryPort(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CL_GetServerQueryPort@<eax>(int a1@<esi>)
{
  CClientState *BaseLocalClient; // eax
  int v3; // esi
  CClientState *v4; // eax
  int v5; // eax
  int dataLen; // [esp+0h] [ebp-4h] BYREF

  if ( GetBaseLocalClient()->m_pServerStartupTable == nullptr )
    return 0;
  BaseLocalClient = GetBaseLocalClient();
  v3 = ((int (__thiscall *)(INetworkStringTable *, const char *, int))BaseLocalClient->m_pServerStartupTable->FindStringIndex)(
         a1: BaseLocalClient->m_pServerStartupTable,
         a2: "QueryPort",
         a3: a1);
  if ( v3 != 0xFFFF
    && (v4 = GetBaseLocalClient(),
        (v5 = (int)v4->m_pServerStartupTable->GetStringUserData(this: v4->m_pServerStartupTable, a2: v3, a3: &dataLen)) != 0)
    && dataLen == 4 )
  {
    return *(_DWORD *)v5;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087E90
// Name: void CL_RegisterResources(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CL_RegisterResources(int a1@<ebx>, int a2@<edi>)
{
  CClientState *BaseLocalClient; // eax
  model_t *Model; // eax

  BaseLocalClient = GetBaseLocalClient();
  Model = CClientState::GetModel(this: BaseLocalClient, a2: a1, a3: a2, index: 1);
  CCommonHostState::SetWorldModel(this: &host_state, pModel: Model);
  if ( host_state.worldmodel == nullptr )
    Host_Error(error: "CL_RegisterResources:  host_state.worldmodel/GetBaseLocalClient().GetModel( 1 )==NULL\n");
  videomode->InvalidateWindow(this: videomode);
}

//------------------------------------------------------------------------------
// Address: 0x10087ED0
// Name: void CL_NextDemo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_NextDemo()
{
  int demonum; // esi
  int v1; // esi
  int v2; // esi
  CClientState *BaseLocalClient; // eax
  vgui::CTreeViewListControl *v4; // ecx
  ECommandTarget_t TraceType; // eax
  CClientState *v6; // eax
  char str[1024]; // [esp+0h] [ebp-400h] BYREF

  if ( GetBaseLocalClient()->demonum != -1 )
  {
    SCR_BeginLoadingPlaque(levelName: nullptr);
    demonum = GetBaseLocalClient()->demonum;
    if ( GetBaseLocalClient()->demos[demonum][0] != 0 && GetBaseLocalClient()->demonum != 32
      || (GetBaseLocalClient()->demonum = 0, v1 = GetBaseLocalClient()->demonum, GetBaseLocalClient()->demos[v1][0] != 0) )
    {
      v2 = GetBaseLocalClient()->demonum;
      BaseLocalClient = GetBaseLocalClient();
      V_snprintf(pDest: str, maxLen: 1024, pFormat: "playdemo %s", BaseLocalClient->demos[v2]);
      TraceType = CTraceFilter::GetTraceType(this: v4);
      Cbuf_AddText(eTarget: TraceType, pText: str, nTickDelay: 0);
      v6 = GetBaseLocalClient();
      ++v6->demonum;
    }
    else
    {
      scr_disabled_for_loading = false;
      ConMsg(a1: "No demos listed with startdemos\n");
      GetBaseLocalClient()->demonum = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087FE0
// Name: void CL_HudMessage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_HudMessage(const char *pMessage)
{
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->HudText(this: g_ClientDLL, a2: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x10088000
// Name: cl_showents
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_showents()
{
  int i; // esi
  int v1; // eax
  int v2; // eax
  char entStr[256]; // [esp+4h] [ebp-200h] BYREF
  char classStr[256]; // [esp+104h] [ebp-100h] BYREF

  for ( i = 0; i < entitylist->GetMaxEntities(this: entitylist); ++i )
  {
    v1 = entitylist->GetClientNetworkable(this: entitylist, a2: i);
    if ( v1 != 0 )
    {
      entStr[0] = 0;
      v2 = (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1);
      V_snprintf(pDest: classStr, maxLen: 256, pFormat: "'%s'", *(const char **)(v2 + 8));
      ConMsg(a1: "Ent %3d: %s class %s\n", i, entStr, classStr);
    }
    else
    {
      V_snprintf(pDest: entStr, maxLen: 256, pFormat: "(missing), ");
      V_snprintf(pDest: classStr, maxLen: 256, pFormat: "(missing)");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100880D0
// Name: void CL_GetStartupImage(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_GetStartupImage(char *pOutBuffer, int nOutBufferSize)
{
  bool v2; // zf
  const char *v3; // eax

  v2 = !materials->GetAspectRatioInfo(this: materials)->m_bIsWidescreen;
  v3 = "_widescreen";
  if ( v2 )
    v3 = defaultValue;
  V_snprintf(pDest: pOutBuffer, maxLen: nOutBufferSize, pFormat: "console/background01%s", v3);
}

//------------------------------------------------------------------------------
// Address: 0x10088110
// Name: void CL_DemoTransitionFromTrainstation(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl CL_DemoTransitionFromTrainstation()
{
  vgui::CTreeViewListControl *v0; // ecx
  ECommandTarget_t TraceType; // eax
  CStatTime *v2; // ecx
  double v3; // st7
  unsigned int v4; // [esp-8h] [ebp-8h]
  int v5; // [esp-4h] [ebp-4h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&sv_unlockedchapters.IConVar, value: 6, a2: v4, a3: v5);
  TraceType = CTraceFilter::GetTraceType(this: v0);
  Cbuf_AddText(eTarget: TraceType, pText: "sv_cheats 1; fadeout 1.5; sv_cheats 0;", nTickDelay: 0);
  Cbuf_Execute();
  v3 = _Plat_FloatTime(this: v2);
  s_bIsRavenHolmn = false;
  s_fDemoRevealGameUITime = v3 + 1.5;
}

//------------------------------------------------------------------------------
// Address: 0x10088150
// Name: void CL_DemoTransitionFromRavenholm(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CL_DemoTransitionFromRavenholm(vgui::CTreeViewListControl *this)
{
  ECommandTarget_t TraceType; // eax
  CStatTime *v2; // ecx
  double v3; // st7

  TraceType = CTraceFilter::GetTraceType(this);
  Cbuf_AddText(eTarget: TraceType, pText: "sv_cheats 1; fadeout 2; sv_cheats 0;", nTickDelay: 0);
  Cbuf_Execute();
  v3 = _Plat_FloatTime(this: v2);
  s_bIsRavenHolmn = true;
  s_fDemoRevealGameUITime = v3 + 1.9;
}

//------------------------------------------------------------------------------
// Address: 0x10088190
// Name: void CL_DemoTransitionFromTestChmb(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CL_DemoTransitionFromTestChmb(vgui::CTreeViewListControl *this)
{
  ECommandTarget_t TraceType; // eax
  CStatTime *v2; // ecx

  TraceType = CTraceFilter::GetTraceType(this);
  Cbuf_AddText(eTarget: TraceType, pText: "sv_cheats 1; fadeout 2; sv_cheats 0;", nTickDelay: 0);
  Cbuf_Execute();
  s_fDemoRevealGameUITime = _Plat_FloatTime(this: v2) + 1.9;
}

//------------------------------------------------------------------------------
// Address: 0x100881C0
// Name: void CL_SetPagedPoolInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_SetPagedPoolInfo()
{
  _Plat_GetPagedPoolInfo(a1: &g_pagedpoolinfo);
}

//------------------------------------------------------------------------------
// Address: 0x100881D0
// Name: cl_fullupdate
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_fullupdate()
{
  CClientState *LocalClient; // eax

  LocalClient = GetLocalClient(nSlot: -1);
  CBaseClientState::ForceFullUpdate(this: LocalClient, pchReason: "cl_fullupdate command");
}

//------------------------------------------------------------------------------
// Address: 0x100881F0
// Name: void Callback_ModelChanged(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Callback_ModelChanged(void *object, INetworkStringTable *stringTable, int stringNumber)
{
  CClientState *BaseLocalClient; // eax

  if ( stringTable == GetBaseLocalClient()->m_pModelPrecacheTable && stringNumber >= 1 )
  {
    BaseLocalClient = GetBaseLocalClient();
    CClientState::SetModel(this: BaseLocalClient, tableIndex: stringNumber);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088220
// Name: void Callback_GenericChanged(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Callback_GenericChanged(void *object, INetworkStringTable *stringTable, int stringNumber)
{
  CClientState *BaseLocalClient; // eax

  if ( stringTable == GetBaseLocalClient()->m_pGenericPrecacheTable && stringNumber >= 1 )
  {
    BaseLocalClient = GetBaseLocalClient();
    CClientState::SetGeneric(this: BaseLocalClient, tableIndex: stringNumber);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088250
// Name: void Callback_SoundChanged(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Callback_SoundChanged(void *object, INetworkStringTable *stringTable, int stringNumber)
{
  CClientState *BaseLocalClient; // eax

  if ( stringTable == GetBaseLocalClient()->m_pSoundPrecacheTable && stringNumber >= 1 )
  {
    BaseLocalClient = GetBaseLocalClient();
    CClientState::SetSound(this: BaseLocalClient, tableIndex: stringNumber);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088280
// Name: void Callback_DecalChanged(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Callback_DecalChanged(void *object, INetworkStringTable *stringTable, int stringNumber)
{
  CClientState *BaseLocalClient; // eax

  if ( stringTable == GetBaseLocalClient()->m_pDecalPrecacheTable )
  {
    BaseLocalClient = GetBaseLocalClient();
    CClientState::SetDecal(this: BaseLocalClient, tableIndex: stringNumber);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100882B0
// Name: void Callback_UserInfoChanged(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Callback_UserInfoChanged(
        void *object,
        INetworkStringTable *stringTable,
        int stringNumber,
        const char *newString,
        _DWORD *newData)
{
  unsigned int *v5; // esi
  int i; // ebx
  CClientState *BaseLocalClient; // eax
  IGameEvent *v8; // esi
  unsigned int v9; // [esp-Ch] [ebp-10h]

  if ( newData != nullptr )
  {
    v5 = newData + 30;
    for ( i = 4; i != 0; --i )
    {
      v9 = *v5;
      BaseLocalClient = GetBaseLocalClient();
      CClientState::CheckOthersCustomFile(this: BaseLocalClient, crcValue: v9);
      ++v5;
    }
    v8 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "player_info", a3: 0, a4: 0);
    if ( v8 != nullptr )
    {
      v8->SetInt(this: v8, a2: "userid", a3: newData[10]);
      v8->SetInt(this: v8, a2: "friendsid", a3: newData[20]);
      ((void (__thiscall *)(IGameEvent *, const char *, _DWORD, _DWORD))v8->SetUint64)(
        a1: v8,
        a2: "xuid",
        a3: *newData,
        a4: newData[1]);
      v8->SetInt(this: v8, a2: "index", a3: stringNumber);
      v8->SetString(this: v8, a2: "name", a3: (const char *)newData + 8);
      v8->SetString(this: v8, a2: "networkid", a3: (const char *)newData + 44);
      v8->SetBool(this: v8, a2: "bot", a3: *((_BYTE *)newData + 116));
      g_GameEventManager->FireEventClientSide(this: g_GameEventManager, a2: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100883A0
// Name: void CL_InstallAndInvokeClientStringTableCallbacks(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_InstallAndInvokeClientStringTableCallbacks()
{
  CClientState *BaseLocalClient; // eax
  int v1; // esi
  CClientState *v2; // eax
  CVTFTexture *v3; // eax
  CVTFTexture *v4; // esi
  CClientState *v5; // ebx
  CClientState_vtbl *v6; // edi
  int v7; // eax
  void (__cdecl *Callback)(void *, INetworkStringTable *, int, const char *, const void *); // eax
  void (__cdecl *v9)(void *, INetworkStringTable *, int, const char *, const void *); // ebx
  const char *v10; // eax
  int v11; // edi
  IEngineVGuiInternal *v12; // eax
  int v13; // eax
  int v14; // eax
  const char *v15; // eax
  int v16; // [esp-Ch] [ebp-20h]
  int userDataSize; // [esp+4h] [ebp-10h] BYREF
  int numTables; // [esp+8h] [ebp-Ch]
  void (__cdecl *pOldFunction)(void *, INetworkStringTable *, int, const char *, const void *); // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CL_InstallAndInvokeClientStringTableCallbacks",
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 4);
  BaseLocalClient = GetBaseLocalClient();
  v1 = 0;
  numTables = BaseLocalClient->m_StringTableContainer->GetNumTables(this: BaseLocalClient->m_StringTableContainer);
  i = 0;
  if ( numTables > 0 )
  {
    do
    {
      v2 = GetBaseLocalClient();
      v3 = (CVTFTexture *)v2->m_StringTableContainer->GetTable(this: v2->m_StringTableContainer, a2: v1);
      v4 = v3;
      if ( v3 != nullptr )
      {
        pOldFunction = (void (__cdecl *)(void *, INetworkStringTable *, int, const char *, const void *))CNetworkStringTable::GetCallback(this: v3);
        v5 = GetBaseLocalClient();
        v6 = v5->CBaseClientState::INetChannelHandler::__vftable;
        v7 = ((int (__thiscall *)(CVTFTexture *))v4->Init)(a1: v4);
        v6->InstallStringTableCallback(this: v5, a2: (const char *)v7);
        Callback = (void (__cdecl *)(void *, INetworkStringTable *, int, const char *, const void *))CNetworkStringTable::GetCallback(this: v4);
        v9 = Callback;
        if ( Callback != nullptr && Callback != pOldFunction )
        {
          v10 = (const char *)((int (__thiscall *)(CVTFTexture *))v4->Init)(a1: v4);
          _COM_TimestampedLog(a1: "String Table Callbacks %s - Start", v10);
          v11 = 0;
          if ( ((int (__thiscall *)(CVTFTexture *))v4->SetReflectivity)(a1: v4) > 0 )
          {
            do
            {
              if ( v11 % 25 == 0 )
              {
                v12 = EngineVGui();
                v12->UpdateProgressBar(this: v12, a2: PROGRESS_DEFAULT, a3: true);
              }
              v13 = ((int (__thiscall *)(CVTFTexture *, int, int *))v4->LowResFileInfo)(
                      a1: v4,
                      a2: v11,
                      a3: &userDataSize);
              v14 = ((int (__thiscall *)(CVTFTexture *, int, int))v4->Unserialize)(a1: v4, a2: v11, a3: v13);
              ((void (__cdecl *)(_DWORD, CVTFTexture *, int, int))v9)(a1: 0, a2: v4, a3: v11++, a4: v14);
            }
            while ( v11 < ((int (__thiscall *)(CVTFTexture *, int))v4->SetReflectivity)(a1: v4, a2: v16) );
          }
          v15 = (const char *)((int (__thiscall *)(CVTFTexture *))v4->Init)(a1: v4);
          _COM_TimestampedLog(a1: "String Table Callbacks %s - Finish", v15);
        }
      }
      v1 = i + 1;
      i = v1;
    }
    while ( v1 < numTables );
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10088510
// Name: double clamp<double,float,float>(double const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl clamp<double,float,float>(const long double *val, const float *minVal, const float *maxVal)
{
  long double result; // st7

  result = *minVal;
  if ( result <= *(double *)val )
  {
    result = *maxVal;
    if ( *(double *)val <= result )
      return *(double *)val;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10088540
// Name: void CL_CheckClientState(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_CheckClientState()
{
  CClientState *BaseLocalClient; // eax
  bool useBackdoor; // [esp+0h] [ebp-4h]

  if ( cl_LocalNetworkBackdoor.m_pParent == nullptr
    || cl_LocalNetworkBackdoor.m_pParent->m_Value.m_nValue == 0
    || GetBaseLocalClient()->m_NetChannel == nullptr
    || (BaseLocalClient = GetBaseLocalClient(),
        !BaseLocalClient->m_NetChannel->IsLoopback(this: BaseLocalClient->m_NetChannel))
    || sv.m_State < ss_active
    || demorecorder->IsRecording(this: demorecorder)
    || demoplayer->IsPlayingBack(this: demoplayer)
    || (useBackdoor = true, !Host_IsSinglePlayerGame()) )
  {
    useBackdoor = false;
  }
  CL_SetupLocalNetworkBackDoor(bUseBackDoor: useBackdoor);
}

//------------------------------------------------------------------------------
// Address: 0x100885C0
// Name: void CL_ClearState(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CL_ClearState(int a1@<edi>)
{
  IStaticPropMgrEngine *v1; // eax
  char *v2; // eax
  CFastPointLeafNum *v3; // esi
  CFastPointLeafNum *v4; // esi
  CClientState *BaseLocalClient; // eax
  model_t *Model; // eax
  CClientState *v7; // eax
  char *worldmodel; // [esp-Ch] [ebp-110h]
  char mapname[256]; // [esp+4h] [ebp-100h] BYREF

  CL_HandlePureServerWhitelist(a1, pWhitelist: nullptr);
  CL_TextureListPanel_ClearState();
  CL_ResetEntityBits();
  R_UnloadSkys();
  Decal_Init();
  v1 = StaticPropMgr();
  v1->LevelShutdownClient(this: v1);
  if ( g_ClientDLL != nullptr )
  {
    if ( host_state.worldmodel != nullptr )
    {
      worldmodel = (char *)host_state.worldmodel;
      v2 = (char *)((int (__thiscall *)(IModelLoader *))modelloader->GetName)(a1: modelloader);
      CL_SetupMapName(pName: v2, pFixedName: worldmodel, maxlen: (int)mapname);
      ((void (__thiscall *)(IPhoneHome *, int, char *, int))phonehome->Message)(
        a1: phonehome,
        a2: 4,
        a3: mapname,
        a4: 256);
    }
    audiosourcecache->LevelShutdown(this: audiosourcecache);
    g_ClientDLL->LevelShutdown(this: g_ClientDLL);
  }
  R_LevelShutdown();
  if ( g_pLocalNetworkBackdoor != nullptr )
    CLocalNetworkBackdoor::ClearState(this: g_pLocalNetworkBackdoor);
  memset(dst: (unsigned __int8 *)cl_dlights, value: 0, count: sizeof(cl_dlights));
  memset(dst: (unsigned __int8 *)cl_elights, value: 0, count: sizeof(cl_elights));
  g_bActiveDlights = false;
  g_bActiveElights = false;
  r_dlightchanged = 0;
  r_dlightactive = 0;
  v3 = g_DLightLeafAccessors;
  do
    CFastPointLeafNum::Reset(this: v3++);
  while ( (int)v3 < (int)g_ELightLeafAccessors );
  v4 = g_ELightLeafAccessors;
  do
    CFastPointLeafNum::Reset(this: v4++);
  while ( (int)v4 < (int)&jpeg_quality );
  g_bClearingClientState = true;
  BaseLocalClient = GetBaseLocalClient();
  Model = CClientState::GetModel(this: BaseLocalClient, a2: 0, a3: a1, index: 1);
  if ( Model != nullptr && host_state.worldmodel == nullptr )
    CCommonHostState::SetWorldModel(this: &host_state, pModel: Model);
  g_bClearingClientState = false;
  Host_FreeStateAndWorld(server: false);
  Host_FreeToLowMark(server: false);
  v7 = GetBaseLocalClient();
  v7->Clear(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10088730
// Name: void CL_SndShow(char const __near *,struct SoundInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_SndShow(const char *pName, const SoundInfo_t *pSound)
{
  CClientState *BaseLocalClient; // eax
  double Time; // [esp-2Ch] [ebp-2Ch]
  double fDelay; // [esp-24h] [ebp-24h]
  double x; // [esp-1Ch] [ebp-1Ch]
  double y; // [esp-14h] [ebp-14h]
  double z; // [esp-Ch] [ebp-Ch]

  if ( snd_show.m_pParent != nullptr && snd_show.m_pParent->m_Value.m_nValue >= 2 )
  {
    z = pSound->vOrigin.z;
    y = pSound->vOrigin.y;
    x = pSound->vOrigin.x;
    fDelay = pSound->fDelay;
    BaseLocalClient = GetBaseLocalClient();
    Time = CClientState::GetTime(this: BaseLocalClient);
    DevMsg(
      a1: "%i (seq %i) %s : src %d : ch %d : %d dB : vol %.2f : time %.3f (%.4f delay) @%.1f %.1f %.1f\n",
      host_framecount,
      pSound->nSequenceNumber,
      pName,
      pSound->nEntityIndex,
      pSound->nChannel,
      pSound->Soundlevel,
      pSound->fVolume,
      Time,
      fDelay,
      x,
      y,
      z);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100887B0
// Name: void CL_DispatchSound(struct SoundInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl CL_DispatchSound(const SoundInfo_t *sound)
{
  char v1; // cl
  bool v2; // zf
  CClientState *BaseLocalClient; // eax
  int nChannel; // edi
  char v5; // cl
  unsigned int nFlags; // edi
  float x; // xmm0_4
  soundlevel_t Soundlevel; // edx
  float fVolume; // xmm0_4
  int nSpeakerEntity; // edx
  float fDelay; // xmm0_4
  int nSoundNum; // ecx
  char *v13; // eax
  CDummySfx *v14; // edi
  CClientState *v15; // eax
  CSfxTable *v16; // eax
  CClientState *v17; // eax
  const char *SoundName; // eax
  int v19; // [esp+0h] [ebp-D8h]
  int nRandomSeed; // [esp+4h] [ebp-D4h]
  int v21; // [esp+4h] [ebp-D4h]
  char soundtime[20]; // [esp+14h] [ebp-C4h] BYREF
  char name[96]; // [esp+28h] [ebp-B0h] BYREF
  _BYTE params[77]; // [esp+88h] [ebp-50h] OVERLAPPED BYREF

  v1 = params[76] & 0xC0 | 2;
  v2 = (sound->nFlags & 0x10) == 0;
  *(_DWORD *)&params[20] = 1065353216;
  memset(&name[76], 0, 20);
  *(_DWORD *)&params[24] = 75;
  *(_DWORD *)&params[28] = 0;
  *(_DWORD *)&params[32] = 100;
  *(_DWORD *)&params[36] = 0;
  *(_DWORD *)&params[40] = -1;
  *(_DWORD *)&params[44] = 0;
  *(_DWORD *)&params[48] = 0;
  *(_DWORD *)&params[52] = -1;
  *(_WORD *)&params[56] = -1;
  memset(&params[60], 0, 16);
  params[76] = v1;
  memset(params, 0, 20);
  if ( !v2 && fabs(sound->fDelay) < 0.1 )
  {
    BaseLocalClient = GetBaseLocalClient();
    S_ComputeDelayForSoundtime(
      soundtime: (float)(BaseLocalClient->m_flLastServerTickTime + sound->fDelay)
    - (float)((float)(g_ClientGlobalVariables.simTicksThisFrame - 1) * host_state.interval_per_tick),
      syncIndex: CLOCK_SYNC_SERVER);
    v1 = params[76];
  }
  nChannel = sound->nChannel;
  v5 = (v1 ^ (nChannel == 6)) & 1 ^ v1;
  *(_DWORD *)&name[80] = sound->nEntityIndex;
  *(_DWORD *)&name[84] = 6;
  if ( (v5 & 1) == 0 )
    *(_DWORD *)&name[84] = nChannel;
  nFlags = sound->nFlags;
  x = sound->vOrigin.x;
  Soundlevel = sound->Soundlevel;
  *(_DWORD *)&params[32] = sound->nPitch;
  *(float *)&name[92] = x;
  *(float *)params = sound->vOrigin.y;
  *(float *)&params[4] = sound->vOrigin.z;
  fVolume = sound->fVolume;
  *(_DWORD *)&params[24] = Soundlevel;
  nSpeakerEntity = sound->nSpeakerEntity;
  *(float *)&params[20] = fVolume;
  fDelay = sound->fDelay;
  *(_DWORD *)&params[28] = nFlags;
  *(float *)&params[36] = fDelay;
  *(_DWORD *)&params[40] = nSpeakerEntity;
  params[76] = ((v5 | 4) ^ (16 * (nFlags >> 10))) & 0x10 ^ (v5 | 4);
  if ( (params[76] & 0x10) != 0 )
  {
    nRandomSeed = sound->nRandomSeed;
    *(_WORD *)&params[56] = sound->nSoundNum;
    S_StartSoundEntry(
      a1: 0,
      a2: nFlags,
      a3: (int)sound,
      pStartParams: (StartSoundParams_t *)&name[76],
      nSeed: nRandomSeed);
  }
  else
  {
    nSoundNum = sound->nSoundNum;
    soundtime[0] = 0;
    v21 = nSoundNum;
    if ( sound->bIsSentence )
    {
      v13 = VOX_SentenceNameFromIndex(sentencenum: nSoundNum);
      if ( v13 == nullptr )
        v13 = (char *)defaultValue;
      V_snprintf(pDest: soundtime, maxLen: 96, pFormat: "%c%s", 33, v13);
      v14 = S_DummySfx(name: soundtime);
    }
    else
    {
      v15 = GetBaseLocalClient();
      v16 = CClientState::GetSound(this: v15, index: v21);
      v14 = (CDummySfx *)v16;
      if ( v16 != nullptr && (*((_BYTE *)v16 + 12) & 4) != 0 )
        DevMsg(a1: "    Entity '%d' created the late load.\n", sound->nEntityIndex);
      v19 = sound->nSoundNum;
      v17 = GetBaseLocalClient();
      SoundName = CClientState::GetSoundName(this: v17, index: v19);
      V_strncpy(pDest: soundtime, pSrc: SoundName, maxLen: 96);
    }
    *(_DWORD *)&name[88] = v14;
    CL_SndShow(pName: soundtime, pSound: sound);
    if ( (params[76] & 1) != 0 )
    {
      S_StartSound(params: (StartSoundParams_t *)&name[76]);
    }
    else if ( !demoplayer->IsSkipping(this: demoplayer) || (sound->nFlags & 4) != 0 )
    {
      S_StartSound(params: (StartSoundParams_t *)&name[76]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088A30
// Name: void CL_FullyConnected(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_FullyConnected()
{
  IEngineVGuiInternal *v0; // eax
  IStaticPropMgrEngine *v1; // eax
  CClientState *BaseLocalClient; // eax
  vgui::Tooltip *v3; // eax
  char *v4; // edi
  CClientState *v5; // eax
  netadr_s *v6; // eax
  unsigned __int16 Port; // ax
  int v8; // esi
  int ServerQueryPort; // ebx
  IEngineVGuiInternal *v10; // eax
  IEngineVGuiInternal *v11; // eax
  CClientState *v12; // esi
  CClientState *v13; // eax
  ConVar *m_NetChannel; // ecx
  INetChannel *v15; // edi
  bool (__thiscall *ClampValue)(ConVar *, float *); // edx
  ConVar *v17; // esi
  int v18; // eax
  char *v19; // eax
  float v20; // xmm0_4
  char *v21; // eax
  const char *v22; // eax
  vgui::PropertyPage *v23; // ecx
  int v24; // eax
  vgui::CTreeViewListControl *v25; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v27; // [esp+8h] [ebp-24h]
  int v28; // [esp+10h] [ebp-1Ch]
  const char *v29; // [esp+10h] [ebp-1Ch]
  int v30; // [esp+14h] [ebp-18h]
  ConVarRef v31; // [esp+24h] [ebp-8h] BYREF

  v0 = EngineVGui();
  v0->UpdateProgressBar(this: v0, a2: PROGRESS_FULLYCONNECTED, a3: true);
  v1 = StaticPropMgr();
  v1->LevelInitClient(this: v1);
  modelloader->PurgeUnusedModels(this: modelloader);
  g_pMDLCache->ShutdownPreloadData(this: g_pMDLCache);
  g_ClientDLL->LevelInitPostEntity(this: g_ClientDLL);
  BaseLocalClient = GetBaseLocalClient();
  v3 = (vgui::Tooltip *)BaseLocalClient->m_NetChannel->GetRemoteAddress(this: BaseLocalClient->m_NetChannel);
  v4 = CWaveDataStreamAsync::Source(this: v3);
  v5 = GetBaseLocalClient();
  v6 = (netadr_s *)v5->m_NetChannel->GetRemoteAddress(this: v5->m_NetChannel);
  Port = netadr_s::GetPort(this: v6);
  v8 = Port;
  if ( Port == 0 )
  {
    v4 = CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)&net_local_adr);
    v8 = netadr_s::GetPort(this: &net_local_adr);
  }
  ServerQueryPort = CL_GetServerQueryPort(a1: v8);
  v10 = EngineVGui();
  v10->NotifyOfServerConnect(this: v10, a2: com_gamedir, a3: (int)v4, a4: (__int16)v8, a5: ServerQueryPort);
  CTestScriptMgr::CheckPoint(this: &g_TestScriptMgr, pName: "FinishedMapLoad");
  v11 = EngineVGui();
  v11->UpdateProgressBar(this: v11, a2: PROGRESS_READYTOPLAY, a3: true);
  CM_DiscardEntityString();
  g_pMDLCache->EndMapLoad(this: g_pMDLCache);
  if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue > 0 )
  {
    v12 = GetBaseLocalClient();
    v13 = GetBaseLocalClient();
    m_NetChannel = (ConVar *)v12->m_NetChannel;
    v15 = v13->m_NetChannel;
    ClampValue = m_NetChannel->ClampValue;
    v31.m_pConVarState = m_NetChannel;
    v17 = m_NetChannel;
    v28 = ((int (__cdecl *)(_DWORD))ClampValue)(a1: 0);
    v18 = ((int (__thiscall *)(ConVar *))v31.m_pConVarState->InternalSetColorValue)(a1: v31.m_pConVarState);
    v19 = V_pretifymem(value: (float)v18, digitsafterdecimal: 0, usebinaryonek: 3);
    v29 = (const char *)((int (__thiscall *)(ConVar *, int, char *, _DWORD, int))v17->ClampValue)(
                          a1: v17,
                          a2: 1,
                          a3: v19,
                          a4: 0,
                          a5: v28);
    v20 = (float)((int (__thiscall *)(ConVar *))v17->InternalSetColorValue)(a1: v17);
    v21 = V_pretifymem(value: v20, digitsafterdecimal: 1, usebinaryonek: 3);
    v22 = (const char *)((int (__thiscall *)(INetChannel *, char *))v15->GetName)(a1: v15, a2: v21);
    _ConDMsg(a1: "Signon traffic \"%s\":  incoming %s [%d pkts], outgoing %s [%d pkts]\n", v22, v27, 0, v29, v30);
  }
  SCR_EndLoadingPlaque();
  CColorBalanceUIPanel::Init(this: v23);
  if ( !engineClient->IsLevelMainMenuBackground(this: engineClient) )
  {
    ConVarRef::ConVarRef(this: &v31, pName: "mat_queue_mode");
    if ( v31.m_pConVarState->m_Value.m_nValue != 0 )
      Host_AllowQueuedMaterialSystem(bAllow: true);
  }
  if ( GetBaseLocalClient()->m_nMaxClients == 1 && !demoplayer->IsPlayingBack(this: demoplayer) )
    scr_nextdrawtick = host_tickcount + (int)(float)((float)(0.25 / host_state.interval_per_tick) + 0.5);
  _g_pMemAlloc->CompactHeap(this: _g_pMemAlloc);
  _COM_TimestampedLog(a1: "Sound Loading time %.4f", (double)g_flAccumulatedSoundLoadTime);
  _COM_TimestampedLog(a1: "Model Loading time %.4f", (double)g_flAccumulatedModelLoadTime);
  _COM_TimestampedLog(a1: "  Model Loading time studio %.4f", (double)g_flAccumulatedModelLoadTimeStudio);
  _COM_TimestampedLog(
    a1: "    Model Loading time GetVCollide %.4f -sync",
    (double)g_flAccumulatedModelLoadTimeVCollideSync);
  _COM_TimestampedLog(
    a1: "    Model Loading time GetVCollide %.4f -async",
    (double)g_flAccumulatedModelLoadTimeVCollideAsync);
  _COM_TimestampedLog(
    a1: "    Model Loading time GetVirtualModel %.4f",
    (double)g_flAccumulatedModelLoadTimeVirtualModel);
  _COM_TimestampedLog(
    a1: "    Model loading time Mod_GetModelMaterials only %.4f",
    (double)g_flAccumulatedModelLoadTimeMaterialNamesOnly);
  _COM_TimestampedLog(a1: "  Model Loading time world %.4f", (double)g_flAccumulatedModelLoadTimeBrush);
  _COM_TimestampedLog(a1: "  Model Loading time sprites %.4f", (double)g_flAccumulatedModelLoadTimeSprite);
  _COM_TimestampedLog(a1: "  Model Loading time meshes %.4f", (double)g_flAccumulatedModelLoadTimeStaticMesh);
  _COM_TimestampedLog(a1: "*** Map Load Complete");
  v24 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v24 + 40))(a1: v24, a2: "-profilemapload") != 0 )
  {
    TraceType = CTraceFilter::GetTraceType(this: v25);
    Cbuf_AddText(eTarget: TraceType, pText: "quit\n", nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088D70
// Name: void CL_TakeScreenshot(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_TakeScreenshot(const char *name)
{
  char *m_pszString; // eax
  char *v2; // eax

  cl_takesnapshot = true;
  cl_snapshot_fullpathname[0] = 0;
  cl_takejpeg = false;
  if ( name != nullptr )
  {
    V_strncpy(pDest: cl_snapshotname, pSrc: name, maxLen: 260);
    cl_snapshot_subdirname[0] = 0;
  }
  else
  {
    cl_snapshotname[0] = 0;
    if ( (cl_screenshotname.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = cl_screenshotname.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    if ( _V_strlen(str: m_pszString) > 0 )
    {
      if ( (cl_screenshotname.m_nFlags & 0x1000) != 0 )
      {
        v2 = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        v2 = cl_screenshotname.m_pParent->m_Value.m_pszString;
        if ( v2 == nullptr )
          v2 = (char *)defaultValue;
      }
      V_snprintf(pDest: cl_snapshotname, maxLen: 260, pFormat: "%s", v2);
    }
    cl_snapshot_subdirname[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088E30
// Name: devshots_screenshot
// Source: json
//------------------------------------------------------------------------------
void __cdecl devshots_screenshot(const CCommand *args)
{
  CL_TakeScreenshot(name: nullptr);
  if ( args->m_nArgc == 2 )
  {
    V_strncpy(pDest: cl_snapshot_subdirname, pSrc: args->m_ppArgv[1], maxLen: 260);
    cl_snapshotnum = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088E70
// Name: void CL_StartMovie(char const __near *,int,int,int,float,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl CL_StartMovie(
        const char *filename,
        int flags,
        int nWidth,
        const char *nHeight,
        float flFrameRate,
        int jpeg_quality)
{
  char value[12]; // [esp+Ch] [ebp-220h] BYREF
  _BYTE params_244[285]; // [esp+10Ch] [ebp-120h] OVERLAPPED BYREF

  s_flPreviousHostFramerate = host_framerate.m_pParent->m_Value.m_fValue;
  ConVar::SetValue(this: (ConVar *)&host_framerate.IConVar, value: flFrameRate);
  cl_movieinfo.moviename[0] = 0;
  cl_movieinfo.movieframe = 0;
  cl_movieinfo.type = 5;
  cl_movieinfo.jpeg_quality = 50;
  V_strncpy(pDest: cl_movieinfo.moviename, pSrc: filename, maxLen: 256);
  cl_movieinfo.type = flags;
  cl_movieinfo.jpeg_quality = jpeg_quality;
  if ( (flags & 2) != 0 || (flags & 8) != 0 )
  {
    *(_DWORD *)&params_244[256] = 0;
    *(_DWORD *)&params_244[260] = 1;
    memset(&params_244[264], 0, 20);
    params_244[284] = 1;
    value[0] = 0;
    V_strncpy(pDest: value, pSrc: filename, maxLen: 256);
    V_strncpy(pDest: params_244, pSrc: "MOD", maxLen: 256);
    *(_DWORD *)&params_244[280] = 2;
    *(_DWORD *)&params_244[276] = 16;
    *(_DWORD *)&params_244[272] = 44100;
    *(_DWORD *)&params_244[264] = nWidth;
    *(_DWORD *)&params_244[268] = nHeight;
    if ( fabs((double)(int)flFrameRate - flFrameRate) >= 0.001 )
    {
      if ( fabs(
             (double)(int)(float)((float)(flFrameRate * 1001.0) * 0.001)
           - (float)((float)(flFrameRate * 1001.0) * 0.001)) >= 0.001 )
      {
        *(_DWORD *)&params_244[256] = (int)(float)(flFrameRate * 1000.0);
        *(_DWORD *)&params_244[260] = 1000;
      }
      else
      {
        *(_DWORD *)&params_244[256] = (int)(float)(flFrameRate * 1001.0);
        *(_DWORD *)&params_244[260] = 1001;
      }
    }
    else
    {
      *(_DWORD *)&params_244[256] = (int)flFrameRate;
      *(_DWORD *)&params_244[260] = 1;
    }
    g_hCurrentAVI = avi->StartAVI(this: avi, a2: (const AVIParams_t *)value);
  }
  SND_MovieStart();
}

//------------------------------------------------------------------------------
// Address: 0x10089040
// Name: bool CL_IsRecordingMovie(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CL_IsRecordingMovie()
{
  return cl_movieinfo.moviename[0] != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10089050
// Name: startmovie
// Source: json
//------------------------------------------------------------------------------
void __cdecl startmovie(const CCommand *args)
{
  int m_nArgc; // eax
  int v2; // edi
  int v3; // esi
  const char **v4; // edi
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  int v12; // eax
  const char *v13; // eax
  const char *v14; // esi
  int v15; // eax
  const char *v16; // [esp-18h] [ebp-20h]
  int flFrameRate; // [esp+0h] [ebp-8h]
  unsigned int v18; // [esp+4h] [ebp-4h]
  float m_fValue; // [esp+4h] [ebp-4h]

  if ( cmd_source == src_command )
  {
    m_nArgc = args->m_nArgc;
    if ( args->m_nArgc < 2 )
    {
      ConMsg(a1: "startmovie <filename>\n [\n");
      ConMsg(a1: " (default = TGAs + .wav file)\n");
      ConMsg(a1: " avi = AVI + AVISOUND\n");
      ConMsg(a1: " raw = TGAs + .wav file, same as default\n");
      ConMsg(a1: " tga = TGAs\n");
      ConMsg(a1: " jpg/jpeg = JPegs\n");
      ConMsg(a1: " wav = Write .wav audio file\n");
      ConMsg(a1: " jpeg_quality nnn = set jpeq quality to nnn (range 1 to 100), default %d\n", 50);
      ConMsg(a1: " ]\n");
      ConMsg(a1: "e.g.:  startmovie testmovie jpg wav jpeg_qality 75\n");
      ConMsg(
        a1: "Using AVI will bring up a dialog for choosing the codec, which may not show if you are running the engine in fullscreen mode!\n");
      return;
    }
    if ( cl_movieinfo.moviename[0] != 0 )
    {
      ConMsg(a1: "Already recording movie!\n");
      return;
    }
    v2 = 5;
    flFrameRate = 50;
    if ( m_nArgc > 2 )
    {
      v18 = 0;
      v3 = 2;
      v4 = &args->m_ppArgv[2];
      do
      {
        if ( v3 < 0 || v3 >= m_nArgc )
          v5 = defaultValue;
        else
          v5 = *v4;
        if ( _V_stricmp(s1: v5, s2: "avi") == 0 )
          v18 |= 0xAu;
        if ( v3 < 0 || v3 >= args->m_nArgc )
          v6 = defaultValue;
        else
          v6 = *v4;
        if ( _V_stricmp(s1: v6, s2: "raw") == 0 )
          v18 |= 5u;
        if ( v3 < 0 || v3 >= args->m_nArgc )
          v7 = defaultValue;
        else
          v7 = *v4;
        if ( _V_stricmp(s1: v7, s2: "tga") == 0 )
          v18 |= 1u;
        if ( v3 < 0 || v3 >= args->m_nArgc )
          v8 = defaultValue;
        else
          v8 = *v4;
        if ( _V_stricmp(s1: v8, s2: "jpeg") == 0
          || (v3 < 0 || v3 >= args->m_nArgc ? (v9 = defaultValue) : (v9 = *v4), _V_stricmp(s1: v9, s2: "jpg") == 0) )
        {
          v18 = v18 & 0xFFFFFFEE | 0x10;
        }
        if ( v3 < 0 || v3 >= args->m_nArgc )
          v10 = defaultValue;
        else
          v10 = *v4;
        if ( _V_stricmp(s1: v10, s2: "jpeg_quality") == 0 )
        {
          ++v4;
          if ( ++v3 < 0 || v3 >= args->m_nArgc )
            v11 = defaultValue;
          else
            v11 = *v4;
          v12 = V_atoi(str: v11);
          if ( v12 >= 1 )
          {
            flFrameRate = 100;
            if ( v12 <= 100 )
              flFrameRate = v12;
          }
          else
          {
            flFrameRate = 1;
          }
        }
        if ( v3 < 0 || v3 >= args->m_nArgc )
          v13 = defaultValue;
        else
          v13 = *v4;
        if ( _V_stricmp(s1: v13, s2: "wav") == 0 )
          v18 |= 4u;
        m_nArgc = args->m_nArgc;
        ++v3;
        ++v4;
      }
      while ( v3 < args->m_nArgc );
      if ( v18 == 0 )
      {
        _Warning(a1: "Missing or unknown recording types, must specify one or both of 'avi' or 'raw'\n");
        return;
      }
      v2 = v18;
    }
    m_fValue = host_framerate.m_pParent->m_Value.m_fValue;
    if ( m_fValue == 0.0 )
      m_fValue = 30.0;
    v14 = defaultValue;
    if ( args->m_nArgc > 1 )
      v14 = args->m_ppArgv[1];
    v16 = (const char *)videomode->GetModeHeight(this: videomode);
    v15 = videomode->GetModeWidth(this: videomode);
    CL_StartMovie(filename: v14, flags: v2, nWidth: v15, nHeight: v16, flFrameRate: m_fValue, jpeg_quality: flFrameRate);
    ConMsg(a1: "Started recording movie, frames will record after console is cleared...\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089310
// Name: rcon
// Source: json
//------------------------------------------------------------------------------
void __cdecl rcon(const CCommand *args)
{
  int m_nArgc; // eax
  int v3; // edi
  unsigned __int8 *v4; // esi
  int v5; // eax
  CRConClient *v6; // eax
  char message[1024]; // [esp+8h] [ebp-500h] BYREF
  char szParam[256]; // [esp+408h] [ebp-100h] BYREF
  const CCommand *argsa; // [esp+510h] [ebp+8h]

  m_nArgc = args->m_nArgc;
  v3 = 1;
  message[0] = 0;
  if ( m_nArgc > 1 )
  {
    argsa = (const CCommand *)&args->m_ppArgv[1];
    do
    {
      if ( v3 < 0 || v3 >= m_nArgc )
        v4 = (unsigned __int8 *)defaultValue;
      else
        v4 = (unsigned __int8 *)argsa->m_nArgc;
      strchr(string: v4, chr: 0x20u);
      if ( v5 != 0 || _V_strlen(str: (const char *)v4) == 0 )
      {
        V_snprintf(pDest: szParam, maxLen: 256, pFormat: "\"%s\"", (const char *)v4);
        V_strncat(pDest: message, pSrc: szParam, destBufferSize: 0x400u, max_chars_to_copy: -1);
      }
      else
      {
        V_strncat(pDest: message, pSrc: (const char *)v4, destBufferSize: 0x400u, max_chars_to_copy: -1);
      }
      if ( v3 != args->m_nArgc - 1 )
        V_strncat(pDest: message, pSrc: " ", destBufferSize: 0x400u, max_chars_to_copy: -1);
      m_nArgc = args->m_nArgc;
      argsa = (const CCommand *)((char *)argsa + 4);
      ++v3;
    }
    while ( v3 < args->m_nArgc );
  }
  v6 = RCONClient();
  CRConClient::SendCmd(this: v6, msg: message);
}

//------------------------------------------------------------------------------
// Address: 0x10089410
// Name: box
// Source: json
//------------------------------------------------------------------------------
void __cdecl box(const CCommand *args)
{
  const CCommand *v1; // ecx
  int v2; // esi
  const char **v3; // ebx
  int v4; // edi
  const char *v5; // eax
  const char *v6; // eax
  Vector flDuration; // [esp+0h] [ebp-1Ch] BYREF
  Vector v8; // [esp+Ch] [ebp-10h] BYREF
  int v9; // [esp+18h] [ebp-4h]

  v1 = args;
  if ( args->m_nArgc == 7 )
  {
    v2 = 4;
    v3 = &args->m_ppArgv[4];
    v4 = 0;
    v9 = 3;
    while ( 1 )
    {
      v5 = v2 - 3 < 0 || v2 - 3 >= v1->m_nArgc ? defaultValue : *(v3 - 3);
      *(float *)((char *)&flDuration.x + v4) = atof(nptr: v5);
      if ( v2 < 0 || v2 >= args->m_nArgc )
        v6 = defaultValue;
      else
        v6 = *v3;
      *(float *)((char *)&v8.x + v4) = atof(nptr: v6);
      ++v2;
      ++v3;
      v4 += 4;
      if ( --v9 == 0 )
        break;
      v1 = args;
    }
    CDebugOverlay::AddBoxOverlay(
      origin: &vec3_origin,
      mins: &flDuration,
      maxs: &v8,
      angles: &vec3_angle,
      r: 255,
      g: 0,
      b: nullptr,
      a: nullptr,
      flDuration: 100.0);
  }
  else
  {
    ConMsg(a1: "box x1 y1 z1 x2 y2 z2\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100894E0
// Name: cl_view
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_view(const CCommand *args)
{
  CClientState *LocalClient; // eax
  int ViewEntity; // eax
  const char *v3; // eax
  int v4; // esi

  if ( args->m_nArgc == 2 )
  {
    if ( GetBaseLocalClient()->m_nMaxClients <= 1 )
    {
      v3 = defaultValue;
      if ( args->m_nArgc > 1 )
        v3 = args->m_ppArgv[1];
      v4 = atoi(nptr: v3);
      if ( v4 != 0 && v4 <= entitylist->GetHighestEntityIndex(this: entitylist) )
      {
        GetLocalClient(nSlot: -1)->m_nViewEntity = v4;
        videomode->MarkClientViewRectDirty(this: videomode);
        ConMsg(a1: "View entity set to %i\n", v4);
      }
    }
  }
  else
  {
    LocalClient = GetLocalClient(nSlot: -1);
    ViewEntity = CBaseClientState::GetViewEntity(this: LocalClient);
    ConMsg(a1: "cl_view entity#\nCurrent %i\n", ViewEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089580
// Name: void CL_UpdateDAndELights(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_UpdateDAndELights(bool bUpdateDecay)
{
  CClientState *BaseLocalClient; // eax
  int v2; // ebx
  int v3; // esi
  float *p_radius; // edi
  CClientState *v5; // eax
  int v6; // eax
  int v7; // eax
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // edi
  float *v12; // esi
  CClientState *v13; // eax
  int v14; // eax
  int v15; // eax
  float time; // [esp+Ch] [ebp-4h]

  BaseLocalClient = GetBaseLocalClient();
  time = CClientState::GetFrameTime(this: BaseLocalClient);
  v2 = 0;
  g_bActiveDlights = false;
  g_bActiveElights = false;
  r_dlightchanged = 0;
  r_dlightactive = 0;
  g_nNumActiveDLights = 0;
  v3 = 1;
  p_radius = &cl_dlights[0].radius;
  do
  {
    if ( (float)(*p_radius > 0.0) == 0.0 )
      goto LABEL_14;
    v5 = GetBaseLocalClient();
    if ( CClientState::GetTime(this: v5) > p_radius[2] )
    {
      r_dlightchanged |= v3;
LABEL_5:
      *p_radius = 0.0;
LABEL_6:
      v6 = 0;
      goto LABEL_7;
    }
    v8 = p_radius[3];
    if ( v8 != 0.0 && bUpdateDecay )
    {
      v9 = *p_radius;
      r_dlightchanged |= v3;
      v10 = v9 - (float)(v8 * time);
      *p_radius = v10;
      if ( v10 < 0.0 )
        goto LABEL_5;
    }
    if ( *p_radius <= 0.0 )
      goto LABEL_6;
    v6 = 1;
LABEL_7:
    if ( (float)v6 != 0.0 )
    {
      v7 = g_nNumActiveDLights;
      r_dlightactive |= v3;
      g_ActiveDLightIndex[g_nNumActiveDLights] = v2;
      g_bActiveDlights = true;
      g_nNumActiveDLights = v7 + 1;
      goto LABEL_15;
    }
LABEL_14:
    R_MarkDLightNotVisible(dlight: v2);
LABEL_15:
    ++v2;
    v3 = __ROL4__(v3, 1);
    p_radius += 17;
  }
  while ( v2 < 32 );
  g_nNumActiveELights = 0;
  v11 = 0;
  v12 = &cl_elights[0].radius;
  do
  {
    if ( (float)(*v12 > 0.0) == 0.0 )
      goto LABEL_27;
    v13 = GetBaseLocalClient();
    if ( CClientState::GetTime(this: v13) > v12[2] )
    {
      *v12 = 0.0;
      goto LABEL_27;
    }
    if ( bUpdateDecay )
      *v12 = *v12 - (float)(v12[3] * time);
    if ( *v12 < 0.0 )
    {
      *v12 = 0.0;
LABEL_24:
      v14 = 0;
      goto LABEL_25;
    }
    if ( *v12 <= 0.0 )
      goto LABEL_24;
    v14 = 1;
LABEL_25:
    if ( (float)v14 != 0.0 )
    {
      v15 = g_nNumActiveELights;
      g_ActiveELightIndex[g_nNumActiveELights] = v11;
      g_bActiveElights = true;
      g_nNumActiveELights = v15 + 1;
    }
LABEL_27:
    ++v11;
    v12 += 17;
  }
  while ( v11 < 64 );
}

//------------------------------------------------------------------------------
// Address: 0x10089770
// Name: void CL_ExtraMouseUpdate(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_ExtraMouseUpdate(float frametime)
{
  IBaseClientDLL_vtbl *v1; // esi
  CClientState *LocalClient; // eax

  if ( Host_ShouldRun()
    && GetLocalClient(nSlot: -1)->m_nSignonState == 6
    && (!demoplayer->IsPlayingBack(this: demoplayer) || GetLocalClient(nSlot: -1)->ishltv) )
  {
    v1 = g_ClientDLL->__vftable;
    LocalClient = GetLocalClient(nSlot: -1);
    ((void (__thiscall *)(IBaseClientDLL *, _DWORD, bool))v1->ExtraMouseSample)(
      a1: g_ClientDLL,
      a2: LODWORD(frametime),
      a3: !LocalClient->m_bPaused);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100897F0
// Name: void CL_LatchInterpolationAmount(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_LatchInterpolationAmount()
{
  CClientState *BaseLocalClient; // eax
  CClientState *v1; // esi
  int v2; // xmm1_4
  double v3; // st7
  float v4; // [esp+8h] [ebp-Ch]
  float flClientInterpolationAmount; // [esp+Ch] [ebp-8h]
  float dt; // [esp+10h] [ebp-4h]

  BaseLocalClient = GetBaseLocalClient();
  v1 = BaseLocalClient;
  if ( BaseLocalClient->m_nSignonState >= 2 )
  {
    flClientInterpolationAmount = BaseLocalClient->m_NetChannel->GetTimeSinceLastReceived(this: BaseLocalClient->m_NetChannel);
    v2 = 0;
    v3 = host_state.interval_per_tick
       * (double)(int)(CClientState::GetClientInterpAmount(this: v1) / host_state.interval_per_tick + 0.5);
    dt = 0.0;
    v4 = v3;
    if ( v3 > 0.001 )
    {
      if ( (float)(flClientInterpolationAmount / v4) < 0.0
        || (v2 = 1077936128, (float)(flClientInterpolationAmount / v4) > 3.0) )
      {
        dt = *(float *)&v2;
      }
      else
      {
        dt = flClientInterpolationAmount / v4;
      }
    }
    ((void (__stdcall *)(float))v1->m_NetChannel->SetInterpolationAmount)(a1: COERCE_FLOAT(LODWORD(dt)));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100898A0
// Name: void CL_GetBackgroundLevelName(char __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_GetBackgroundLevelName(char *pszBackgroundName, int bufSize, bool bMapName)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  IBaseFileSystem *v5; // eax
  int v6; // edi
  KeyValues *NextKey; // eax
  KeyValues *v8; // esi
  const char *v9; // eax
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  int v12; // eax
  int m_nValue; // eax
  KeyValues *Key; // eax
  char *String; // eax
  char buf[4]; // [esp+8h] [ebp-8h] BYREF
  KeyValues *pChapterRoot; // [esp+Ch] [ebp-4h]

  V_strncpy(pDest: pszBackgroundName, pSrc: "background01", maxLen: bufSize);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: pszBackgroundName);
  else
    v4 = nullptr;
  if ( g_pFileSystem != nullptr )
    v5 = &g_pFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v4,
         filesystem: v5,
         resourceName: "scripts/ChapterBackgrounds.txt",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    pChapterRoot = v4;
    v6 = 1;
    NextKey = KeyValues::GetNextKey(this: v4);
    v8 = NextKey;
    if ( bMapName
      && NextKey != nullptr
      && (v9 = KeyValues::GetName(this: NextKey)) != nullptr
      && *v9 != 0
      && V_strncmp(s1: "BackgroundMaps", s2: v9, count: 14) == 0
      && (pChapterRoot = v8, (FirstSubKey = KeyValues::GetFirstSubKey(this: v8)) != nullptr)
      || (FirstSubKey = KeyValues::GetFirstSubKey(this: v4)) != nullptr )
    {
      do
      {
        Name = KeyValues::GetName(this: FirstSubKey);
        if ( Name != nullptr )
        {
          v12 = atoi(nptr: Name);
          if ( v12 > v6 )
            v6 = v12;
        }
        FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      }
      while ( FirstSubKey != nullptr );
    }
    if ( sv_unlockedchapters.m_pParent != nullptr )
      m_nValue = sv_unlockedchapters.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( m_nValue >= v6 )
      m_nValue = v6;
    if ( m_nValue <= 0 )
      m_nValue = 1;
    V_snprintf(pDest: buf, maxLen: 4, pFormat: "%d", m_nValue);
    Key = KeyValues::FindKey(this: pChapterRoot, keyName: buf, bCreate: false);
    if ( Key != nullptr )
    {
      String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: defaultValue);
      V_strncpy(pDest: pszBackgroundName, pSrc: String, maxLen: bufSize);
    }
  }
  KeyValues::deleteThis(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10089A00
// Name: void CL_DemoCheckGameUIRevealTime(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CL_DemoCheckGameUIRevealTime(CStatTime *this)
{
  vgui::CTreeViewListControl *v1; // ecx
  ECommandTarget_t TraceType; // eax
  CStatTime *v3; // ecx
  CStatTime *v4; // ecx
  double v5; // st6
  IEngineVGuiInternal *v6; // eax
  vgui::CTreeViewListControl *v7; // ecx
  ECommandTarget_t v8; // eax
  CCommand args; // [esp+0h] [ebp-510h] BYREF
  double v10; // [esp+508h] [ebp-8h]

  if ( s_fDemoRevealGameUITime > 0.0 )
  {
    v10 = s_fDemoRevealGameUITime;
    if ( _Plat_FloatTime(this) > v10 )
    {
      s_fDemoRevealGameUITime = -1.0;
      SCR_BeginLoadingPlaque(levelName: nullptr);
      TraceType = CTraceFilter::GetTraceType(this: v1);
      Cbuf_AddText(eTarget: TraceType, pText: "disconnect;", nTickDelay: 0);
      CCommand::CCommand(this: &args);
      s_fDemoPlayMusicTime = _Plat_FloatTime(this: v3) + 1.0;
    }
  }
  if ( s_fDemoPlayMusicTime > 0.0 )
  {
    V_CheckGamma();
    V_RenderVGuiOnly();
    v10 = s_fDemoPlayMusicTime;
    v5 = _Plat_FloatTime(this: v4);
    if ( v5 > v10 )
    {
      s_fDemoPlayMusicTime = -1.0;
      v6 = EngineVGui();
      v6->ActivateGameUI(this: v6);
      CL_InitHL2DemoFlag();
      if ( s_bIsHL2Demo && s_bIsRavenHolmn )
      {
        v8 = CTraceFilter::GetTraceType(this: v7);
        Cbuf_AddText(eTarget: v8, pText: "play music/ravenholm_1.mp3;", nTickDelay: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089B10
// Name: void CL_SetSteamCrashComment(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_SetSteamCrashComment()
{
  char *v0; // eax
  IMaterialSystem_vtbl *v1; // esi
  int v2; // eax
  const char *v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // esi
  CClientState *BaseLocalClient; // eax
  int m_nValue; // edi
  double v10; // st7
  double v11; // st7
  int v12; // eax
  char *v13; // esi
  CClientState *v14; // eax
  netadr_s *v15; // eax
  int v16; // eax
  int v17; // eax
  bool v18; // zf
  char *v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // [esp-10h] [ebp-25DCh]
  int v23; // [esp-Ch] [ebp-25D8h]
  const char *v24; // [esp-Ch] [ebp-25D8h]
  int v25; // [esp-8h] [ebp-25D4h]
  const char *v26; // [esp-8h] [ebp-25D4h]
  int v27; // [esp-4h] [ebp-25D0h]
  const char *v28; // [esp-4h] [ebp-25D0h]
  char v29[4096]; // [esp+8h] [ebp-25C4h] BYREF
  char v30[2048]; // [esp+1008h] [ebp-15C4h] BYREF
  char v31[2048]; // [esp+1808h] [ebp-DC4h] BYREF
  char v32[256]; // [esp+2008h] [ebp-5C4h] BYREF
  char osversion[256]; // [esp+2108h] [ebp-4C4h] BYREF
  char v34[512]; // [esp+2208h] [ebp-3C4h] BYREF
  int v35; // [esp+2408h] [ebp-1C4h]
  int v36; // [esp+240Ch] [ebp-1C0h]
  int v37; // [esp+2410h] [ebp-1BCh]
  int v38; // [esp+2414h] [ebp-1B8h]
  unsigned int v39; // [esp+2424h] [ebp-1A8h]
  unsigned int v40; // [esp+2428h] [ebp-1A4h]
  char pDest[64]; // [esp+242Ch] [ebp-1A0h] BYREF
  char str[128]; // [esp+246Ch] [ebp-160h] BYREF
  char pFixedName[80]; // [esp+24ECh] [ebp-E0h] BYREF
  _BYTE v44[8]; // [esp+253Ch] [ebp-90h] BYREF
  int v45; // [esp+2544h] [ebp-88h]
  ConVarRef v46; // [esp+2560h] [ebp-6Ch] BYREF
  ConVarRef v47; // [esp+2568h] [ebp-64h] BYREF
  ConVarRef v48; // [esp+2570h] [ebp-5Ch] BYREF
  ConVarRef v49; // [esp+2578h] [ebp-54h] BYREF
  ConVarRef v50; // [esp+2580h] [ebp-4Ch] BYREF
  ConVarRef v51; // [esp+2588h] [ebp-44h] BYREF
  ConVarRef v52; // [esp+2590h] [ebp-3Ch] BYREF
  ConVarRef v53; // [esp+2598h] [ebp-34h] BYREF
  ConVarRef v54; // [esp+25A0h] [ebp-2Ch] BYREF
  ConVarRef v55; // [esp+25A8h] [ebp-24h] BYREF
  ConVarRef v56; // [esp+25B0h] [ebp-1Ch] BYREF
  ConVarRef v57; // [esp+25B8h] [ebp-14h] BYREF
  ConVarRef v58; // [esp+25C0h] [ebp-Ch] BYREF
  char v59[4]; // [esp+25C8h] [ebp-4h] BYREF

  pFixedName[0] = 0;
  v30[0] = 0;
  v31[0] = 0;
  v32[0] = 0;
  osversion[0] = 0;
  if ( host_state.worldmodel != nullptr )
  {
    v0 = (char *)modelloader->GetName(this: modelloader, a2: host_state.worldmodel);
    CL_SetupMapName(pName: v0, pFixedName, maxlen: 80);
  }
  DisplaySystemVersion(osversion, maxlen: 256);
  v1 = materials->__vftable;
  v2 = ((int (__thiscall *)(IMaterialSystem *, char *))materials->GetCurrentAdapter)(a1: materials, a2: v34);
  ((void (__thiscall *)(IMaterialSystem *, int))v1->GetDisplayAdapterInfo)(a1: materials, a2: v2);
  v3 = "Unk";
  if ( g_pMaterialSystemHardwareConfig != nullptr )
  {
    v4 = g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig);
    v3 = COM_DXLevelToString(dxlevel: v4);
  }
  V_snprintf(
    pDest,
    maxLen: 64,
    pFormat: "%ld.%ld.%ld.%ld",
    HIWORD(v39),
    (unsigned __int16)v39,
    HIWORD(v40),
    (unsigned __int16)v40);
  if ( v3 == nullptr )
    v3 = "Unk";
  v5 = videomode->GetModeHeight(this: videomode);
  v6 = ((int (__thiscall *)(IVideoMode *, int))videomode->GetModeWidth)(a1: videomode, a2: v5);
  V_snprintf(
    pDest: v30,
    maxLen: 2048,
    pFormat: "Driver Name:  %s\n"
    "Driver Version: %s\n"
    "VendorId / DeviceId:  0x%x / 0x%x\n"
    "SubSystem / Rev:  0x%x / 0x%x\n"
    "DXLevel:  %s\n"
    "Vid:  %i x %i",
    v34,
    pDest,
    v35,
    v36,
    v37,
    v38,
    v3,
    v6,
    v27);
  ConVarRef::ConVarRef(this: &v56, pName: "mat_picmip");
  ConVarRef::ConVarRef(this: &v57, pName: "mat_forceaniso");
  ConVarRef::ConVarRef(this: &v58, pName: "mat_antialias");
  ConVarRef::ConVarRef(this: &v52, pName: "mat_aaquality");
  ConVarRef::ConVarRef(this: &v51, pName: "r_shadowrendertotexture");
  ConVarRef::ConVarRef(this: &v49, pName: "r_flashlightdepthtexture");
  ConVarRef::ConVarRef(this: &v53, pName: "r_waterforceexpensive");
  ConVarRef::ConVarRef(this: &v46, pName: "r_waterforcereflectentities");
  ConVarRef::ConVarRef(this: &v54, pName: "mat_vsync");
  ConVarRef::ConVarRef(this: &v47, pName: "r_rootlod");
  ConVarRef::ConVarRef(this: &v55, pName: "mat_motion_blur_enabled");
  ConVarRef::ConVarRef(this: &v48, pName: "mat_queue_mode");
  ConVarRef::ConVarRef(this: &v50, pName: "mat_triplebuffered");
  V_snprintf(
    pDest: v31,
    maxLen: 2048,
    pFormat: "picmip: %i\n"
    "forceansio: %i\n"
    "antialias: %i (%i)\n"
    "vsync: %i\n"
    "rootlod: %i\n"
    "shadowrendertotexture: %i\n"
    "r_flashlightdepthtexture %i\n"
    "waterforceexpensive: %i\n"
    "waterforcereflectentities: %i\n"
    "mat_motion_blur_enabled: %i\n"
    "mat_queue_mode %i\n"
    "mat_triplebuffered: %i\n",
    v56.m_pConVarState->m_Value.m_nValue,
    v57.m_pConVarState->m_Value.m_nValue,
    v58.m_pConVarState->m_Value.m_nValue,
    v52.m_pConVarState->m_Value.m_nValue,
    v54.m_pConVarState->m_Value.m_nValue,
    v47.m_pConVarState->m_Value.m_nValue,
    v51.m_pConVarState->m_Value.m_nValue,
    v49.m_pConVarState->m_Value.m_nValue,
    v53.m_pConVarState->m_Value.m_nValue,
    v46.m_pConVarState->m_Value.m_nValue,
    v55.m_pConVarState->m_Value.m_nValue,
    v48.m_pConVarState->m_Value.m_nValue,
    v50.m_pConVarState->m_Value.m_nValue);
  v7 = 0;
  if ( GetBaseLocalClient()->m_NetChannel != nullptr )
  {
    BaseLocalClient = GetBaseLocalClient();
    v7 = (int)(((double (__thiscall *)(INetChannel *, _DWORD))BaseLocalClient->m_NetChannel->GetAvgLatency)(
                 a1: BaseLocalClient->m_NetChannel,
                 a2: 0)
             * 1000.0);
  }
  if ( skill.m_pParent != nullptr )
    m_nValue = skill.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v10 = ((double (__thiscall *)(ConVar_ServerBounded *, int))cl_cmdrate->GetFloat)(a1: cl_cmdrate, a2: v7);
  v11 = ((double (__thiscall *)(ConVar_ServerBounded *, int))cl_updaterate->GetFloat)(a1: cl_updaterate, a2: (int)v10);
  v12 = ((int (__thiscall *)(ConVar_ServerBounded *, int))cl_rate->GetInt)(a1: cl_rate, a2: (int)v11);
  V_snprintf(
    pDest: v32,
    maxLen: 256,
    pFormat: "skill:%i rate %i update %i cmd %i latency %i msec",
    m_nValue,
    v12,
    v22,
    v23,
    v25);
  v13 = "Not Connected";
  if ( GetBaseLocalClient()->m_NetChannel != nullptr )
  {
    v14 = GetBaseLocalClient();
    v15 = (netadr_s *)v14->m_NetChannel->GetRemoteAddress(this: v14->m_NetChannel);
    v13 = netadr_s::ToString(this: v15, baseOnly: false);
  }
  _Plat_GetPagedPoolInfo(a1: &g_pagedpoolinfo);
  strcpy(v59, "AM");
  _Plat_GetLocalTime(a1: v44);
  v16 = v45;
  if ( v45 > 12 )
  {
    V_strncpy(pDest: v59, pSrc: "PM", maxLen: 3);
    v16 = v45;
    if ( v45 > 12 )
    {
      v16 = v45 - 12;
      v45 -= 12;
    }
  }
  if ( v16 == 0 )
    v45 = 12;
  _Plat_GetTimeString(a1: v44, a2: str, a3: 128);
  v17 = _V_strlen(str);
  if ( v17 > 0 )
  {
    v18 = pDest[v17 + 63] == 10;
    v19 = &pDest[v17 + 63];
    if ( v18 )
      *v19 = 0;
  }
  v20 = _CommandLine();
  v24 = (const char *)(*(int (__thiscall **)(int, char *, char *))(*(_DWORD *)v20 + 8))(a1: v20, a2: v30, a3: v31);
  v21 = build_number();
  V_snprintf(
    pDest: g_minidumpinfo,
    maxLen: 4096,
    pFormat: "Map: %s\nGame: %s\nBuild: %i\nOS: %s\nMisc: %s\nNet: %s\nTime: %s\ncmdline:%s\ndriver: %s\nvideo: %s\n",
    pFixedName,
    com_gamedir,
    v21,
    osversion,
    v32,
    v13,
    str,
    v24,
    v26,
    v28);
  V_snprintf(
    pDest: v29,
    maxLen: 4096,
    pFormat: "%sPP PAGES: used: %d, free %d\n",
    g_minidumpinfo,
    g_pagedpoolinfo.numPagesUsed,
    g_pagedpoolinfo.numPagesFree);
  _SteamAPI_SetMiniDumpComment(a1: v29);
}

//------------------------------------------------------------------------------
// Address: 0x10089F90
// Name: void CL_InitLanguageCvar(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_InitLanguageCvar()
{
  int v0; // eax
  int v1; // eax
  const char *v2; // [esp-Ch] [ebp-50h]
  int v3; // [esp-4h] [ebp-48h]
  char language[64]; // [esp+4h] [ebp-40h] BYREF

  V_strncpy(pDest: language, pSrc: "english", maxLen: 64);
  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v0 + 12))(a1: v0, a2: "-language", a3: 0) != 0 )
  {
    v1 = _CommandLine();
    v3 = (int)"english";
    v2 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v1 + 32))(a1: v1);
    V_strncpy(pDest: language, pSrc: v2, maxLen: (int)"-language");
  }
  else
  {
    memset(dst: (unsigned __int8 *)language, value: 0, count: sizeof(language));
    v3 = 63;
    ((void (__thiscall *)(vgui::ISystem *, const char *, char *))g_pVGuiSystem->GetRegistryString)(
      a1: g_pVGuiSystem,
      a2: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Language",
      a3: language);
    if ( _V_strlen(str: language) == 0 || _V_stricmp(s1: language, s2: "unknown") == 0 )
      V_strncpy(pDest: language, pSrc: "english", maxLen: 64);
  }
  CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&cl_language.IConVar, value: language, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1008A060
// Name: void CL_ChangeCloudSettingsCvar(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_ChangeCloudSettingsCvar(IConVar *var)
{
  CSteam3Client *v1; // eax
  int v2; // eax
  const char *v3; // eax
  char szRegistryKeyLocation[256]; // [esp+0h] [ebp-108h] BYREF
  ConVarRef ref; // [esp+100h] [ebp-8h] BYREF

  if ( Steam3Client()->m_pSteamUtils != nullptr )
  {
    v1 = Steam3Client();
    v2 = v1->m_pSteamUtils->GetAppID(this: v1->m_pSteamUtils);
    V_snprintf(
      pDest: szRegistryKeyLocation,
      maxLen: 256,
      pFormat: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Apps\\%d\\Cloud",
      v2);
    v3 = var->GetName(this: var);
    ConVarRef::ConVarRef(this: &ref, pName: v3);
    g_pVGuiSystem->SetRegistryInteger(
      this: g_pVGuiSystem,
      a2: szRegistryKeyLocation,
      a3: ref.m_pConVarState->m_Value.m_nValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A0D0
// Name: void CL_InitCloudSettingsCvar(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_InitCloudSettingsCvar()
{
  CSteam3Client *v0; // eax
  int v1; // eax
  char szRegistryKeyLocation[256]; // [esp+0h] [ebp-104h] BYREF
  int iCloudSettings; // [esp+100h] [ebp-4h] BYREF

  if ( Steam3Client()->m_pSteamUtils != nullptr )
  {
    iCloudSettings = -1;
    v0 = Steam3Client();
    v1 = v0->m_pSteamUtils->GetAppID(this: v0->m_pSteamUtils);
    V_snprintf(
      pDest: szRegistryKeyLocation,
      maxLen: 256,
      pFormat: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Apps\\%d\\Cloud",
      v1);
    if ( !g_pVGuiSystem->GetRegistryInteger(this: g_pVGuiSystem, a2: szRegistryKeyLocation, a3: &iCloudSettings) )
      iCloudSettings = -1;
    CLoaderMemAlloc::CrtIsValidPointer(
      this: (ConVar *)&cl_cloud_settings.IConVar,
      value: iCloudSettings,
      a2: *(unsigned int *)szRegistryKeyLocation,
      a3: *(int *)&szRegistryKeyLocation[4]);
  }
  else
  {
    CLoaderMemAlloc::CrtIsValidPointer(
      this: (ConVar *)&cl_cloud_settings.IConVar,
      value: 0,
      a2: *(unsigned int *)szRegistryKeyLocation,
      a3: *(int *)&szRegistryKeyLocation[4]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A160
// Name: void CL_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_Init()
{
  int i; // esi
  CClientState *LocalClient; // eax
  int v2; // eax
  char szRate[128]; // [esp+4h] [ebp-80h] BYREF

  for ( i = 0; i < host_state.max_splitscreen_players; ++i )
  {
    LocalClient = GetLocalClient(nSlot: -1);
    LocalClient->Clear(this: LocalClient);
  }
  szRate[0] = 0;
  Sys_GetRegKeyValue(
    pszSubKey: "Software\\Valve\\Steam",
    pszElement: "Rate",
    pszReturnString: szRate,
    nReturnLength: 128,
    pszDefaultValue: "10000");
  if ( _V_strlen(str: szRate) > 0 )
  {
    v2 = V_atoi(str: szRate);
    if ( v2 >= 1000 )
    {
      if ( v2 > 30000 )
        v2 = 30000;
    }
    else
    {
      v2 = 1000;
    }
    cl_rate->SetValue_2(this: &cl_rate->IConVar, a2: v2);
  }
  CL_InitLanguageCvar();
  CL_InitCloudSettingsCvar();
}

//------------------------------------------------------------------------------
// Address: 0x1008A210
// Name: cl_precacheinfo
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_precacheinfo(const CCommand *args)
{
  CClientState *BaseLocalClient; // eax
  CClientState *v2; // eax
  CClientState *v3; // eax
  CClientState *v4; // eax
  CClientState *v5; // eax
  char *v6; // [esp-4h] [ebp-4h]

  if ( args->m_nArgc == 2 )
  {
    v6 = (char *)args->m_ppArgv[1];
    BaseLocalClient = GetBaseLocalClient();
    CClientState::DumpPrecacheStats(this: BaseLocalClient, name: v6);
  }
  else
  {
    v2 = GetBaseLocalClient();
    CClientState::DumpPrecacheStats(this: v2, name: "modelprecache");
    v3 = GetBaseLocalClient();
    CClientState::DumpPrecacheStats(this: v3, name: "decalprecache");
    v4 = GetBaseLocalClient();
    CClientState::DumpPrecacheStats(this: v4, name: "soundprecache");
    v5 = GetBaseLocalClient();
    CClientState::DumpPrecacheStats(this: v5, name: "genericprecache");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A310
// Name: public: virtual char const __near * CLC_Move::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_Move::GetName(CLC_Move *this)
{
  return "clc_Move";
}

//------------------------------------------------------------------------------
// Address: 0x1008A320
// Name: public: virtual bool CLC_Move::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_Move::Process(SVC_ServerInfo *this)
{
  return this->m_pMessageHandler->ProcessServerInfo(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1008A3E0
// Name: void CL_ReadPackets(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_ReadPackets(bool bFinalTick)
{
  CClientState *BaseLocalClient; // esi
  IEngineVGuiInternal *v2; // eax
  INetChannel *m_NetChannel; // ecx
  INetChannel *v4; // ecx
  IEngineVGuiInternal *v5; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CL_ReadPackets",
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 4);
  splitscreen->SetActiveSplitScreenPlayerSlot(this: splitscreen, a2: 0);
  splitscreen->SetLocalPlayerIsResolvable(this: splitscreen, a2: "cl_main.cpp", a3: 518, a4: false);
  if ( !Host_ShouldRun() )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  splitscreen->SetLocalPlayerIsResolvable(this: splitscreen, a2: "cl_main.cpp", a3: 523, a4: true);
  BaseLocalClient = GetBaseLocalClient();
  if ( BaseLocalClient->m_nSignonState == 6 && scr_drawloading )
  {
    v2 = EngineVGui();
    v2->UpdateProgressBar(this: v2, a2: PROGRESS_DEFAULT, a3: true);
  }
  BaseLocalClient->oldtickcount = BaseLocalClient->m_ClockDriftMgr.m_nServerTick;
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    ++BaseLocalClient->m_ClockDriftMgr.m_nClientTick;
    if ( !CClockDriftMgr::IsClockCorrectionEnabled() )
      BaseLocalClient->m_ClockDriftMgr.m_nServerTick = BaseLocalClient->m_ClockDriftMgr.m_nClientTick;
    g_ClientGlobalVariables.tickcount = BaseLocalClient->m_ClockDriftMgr.m_nClientTick;
    g_ClientGlobalVariables.curtime = CClientState::GetTime(this: BaseLocalClient);
  }
  g_ClientGlobalVariables.frametime = CClientState::GetFrameTime(this: BaseLocalClient);
  if ( demoplayer->IsPlayingBack(this: demoplayer) && (m_NetChannel = BaseLocalClient->m_NetChannel) != nullptr )
  {
    m_NetChannel->ProcessPlayback(this: m_NetChannel);
  }
  else if ( cl_ignorepackets.m_pParent == nullptr || cl_ignorepackets.m_pParent->m_Value.m_nValue == 0 )
  {
    NET_ProcessSocket(sock: 0, handler: &BaseLocalClient->IConnectionlessPacketHandler);
    if ( net_earliertempents.m_pParent != nullptr && net_earliertempents.m_pParent->m_Value.m_nValue != 0 )
      CL_FireEvents();
  }
  if ( bFinalTick && !demoplayer->IsPlayingBack(this: demoplayer) && BaseLocalClient->m_nSignonState >= 2 )
  {
    v4 = BaseLocalClient->m_NetChannel;
    if ( v4 != nullptr )
    {
      if ( v4->IsTimedOut(this: v4) )
      {
        ConMsg(a1: "\nServer connection timed out.\n");
        COM_ExplainDisconnection(bPrint: false, fmt: "Connection to server timed out.");
LABEL_26:
        v5 = EngineVGui();
        v5->ShowErrorMessage(this: v5);
        Host_Disconnect(bShowMainMenu: true);
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        return;
      }
      if ( BaseLocalClient->m_NetChannel->IsRemoteDisconnected(this: BaseLocalClient->m_NetChannel) )
      {
        ConMsg(a1: "\nServer shutting down\n");
        COM_ExplainDisconnection(bPrint: false, fmt: "Server shutting down");
        goto LABEL_26;
      }
    }
  }
  splitscreen->SetLocalPlayerIsResolvable(this: splitscreen, a2: "cl_main.cpp", a3: 617, a4: false);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1008A5F0
// Name: screenshot
// Source: json
//------------------------------------------------------------------------------
void __cdecl screenshot(const CCommand *args)
{
  CTestScriptMgr::SetWaitCheckPoint(this: &g_TestScriptMgr, pCheckPointName: "screenshot", bOnce: false);
  if ( !demoplayer->IsPlayingBack(this: demoplayer)
    || cl_playback_screenshots.m_pParent != nullptr && cl_playback_screenshots.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( args->m_nArgc == 2 )
      CL_TakeScreenshot(name: args->m_ppArgv[1]);
    else
      CL_TakeScreenshot(name: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A650
// Name: void CL_TakeJpeg(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_TakeJpeg(const char *name, int quality)
{
  if ( !demoplayer->IsPlayingBack(this: demoplayer)
    || cl_playback_screenshots.m_pParent != nullptr && cl_playback_screenshots.m_pParent->m_Value.m_nValue != 0 )
  {
    cl_takesnapshot = true;
    cl_snapshot_fullpathname[0] = 0;
    cl_takejpeg = true;
    if ( quality >= 1 )
    {
      cl_jpegquality = 100;
      if ( quality <= 100 )
        cl_jpegquality = quality;
    }
    else
    {
      cl_jpegquality = 1;
    }
    if ( name != nullptr )
      V_strncpy(pDest: cl_snapshotname, pSrc: name, maxLen: 260);
    else
      cl_snapshotname[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A6E0
// Name: jpeg
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg(const CCommand *args)
{
  int m_nArgc; // edx
  const char *v2; // esi
  int v3; // eax
  int v4; // eax
  int m_nValue; // esi

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc < 2 )
  {
    if ( jpeg_quality.m_pParent != nullptr )
      m_nValue = jpeg_quality.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( !demoplayer->IsPlayingBack(this: demoplayer)
      || cl_playback_screenshots.m_pParent != nullptr && cl_playback_screenshots.m_pParent->m_Value.m_nValue != 0 )
    {
      cl_takesnapshot = true;
      cl_snapshot_fullpathname[0] = 0;
      cl_takejpeg = true;
      if ( m_nValue >= 1 )
      {
        cl_jpegquality = 100;
        if ( m_nValue <= 100 )
          cl_jpegquality = m_nValue;
        cl_snapshotname[0] = 0;
      }
      else
      {
        cl_jpegquality = 1;
        cl_snapshotname[0] = 0;
      }
    }
  }
  else if ( m_nArgc == 3 )
  {
    v2 = args->m_ppArgv[1];
    v3 = V_atoi(str: args->m_ppArgv[2]);
    CL_TakeJpeg(name: v2, quality: v3);
  }
  else
  {
    if ( jpeg_quality.m_pParent != nullptr )
      v4 = jpeg_quality.m_pParent->m_Value.m_nValue;
    else
      v4 = 0;
    if ( m_nArgc > 1 )
      CL_TakeJpeg(name: args->m_ppArgv[1], quality: v4);
    else
      CL_TakeJpeg(name: defaultValue, quality: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A7D0
// Name: void CL_TakeSnapshotAndSwap(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall CL_TakeSnapshotAndSwap(int a1@<edi>, int a2@<esi>)
{
  ConVar *m_pParent; // ecx
  float v3; // xmm1_4
  float v4; // xmm0_4
  IClientEntity *v5; // esi
  IClientRenderable *v6; // edi
  IModelLoader_vtbl *v7; // esi
  const char *v8; // eax
  const char *v9; // eax
  int v10; // esi
  int v11; // ecx
  IVideoMode_vtbl *v12; // edx
  char v13; // bl
  long double v14; // st7
  long double v15; // st6
  char *v16; // [esp-40h] [ebp-458h]
  char *v17; // [esp-30h] [ebp-448h]
  char renamedfile[260]; // [esp+0h] [ebp-418h] BYREF
  char extension[260]; // [esp+104h] [ebp-314h] BYREF
  char base[260]; // [esp+208h] [ebp-210h] BYREF
  char filename[263]; // [esp+30Ch] [ebp-10Ch] BYREF
  int bEnabled; // [esp+413h] [ebp-5h]
  bool bReadPixelsFromFrontBuffer; // [esp+417h] [ebp-1h]

  bReadPixelsFromFrontBuffer = g_pMaterialSystemHardwareConfig->ReadPixelsFromFrontBuffer(this: g_pMaterialSystemHardwareConfig);
  if ( bReadPixelsFromFrontBuffer )
    Shader_SwapBuffers();
  if ( fps_screenshot_threshold.m_pParent != nullptr && fps_screenshot_threshold.m_pParent->m_Value.m_nValue > 0 )
  {
    v3 = realtime - sLastRealTime;
    sLastRealTime = realtime;
    if ( v3 <= (float)(1.0 / fps_screenshot_threshold.m_pParent->m_Value.m_fValue) || v3 >= 10.0 )
    {
      v4 = timer;
    }
    else
    {
      v4 = timer;
      if ( timer >= 0.0 )
      {
        cl_takesnapshot = true;
        v4 = timer - fps_screenshot_frequency.m_pParent->m_Value.m_fValue;
        timer = v4;
      }
    }
    if ( v4 < 0.0 )
      timer = v4 + v3;
  }
  if ( cl_takesnapshot )
  {
    LOBYTE(bEnabled) = ((int (__thiscall *)(IMaterialSystem *, _DWORD, int, int))materials->AllowThreading)(
                         a1: materials,
                         a2: 0,
                         a3: g_nMaterialSystemThread,
                         a4: a2);
    v5 = entitylist->GetClientEntity(this: entitylist, a2: 0);
    g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: "screenshots", a3: "DEFAULT_WRITE_PATH");
    if ( cl_snapshot_fullpathname[0] != 0 )
    {
      V_ExtractFilePath(path: cl_snapshot_fullpathname, dest: renamedfile, destSize: 260);
      g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: renamedfile, a3: nullptr);
    }
    if ( v5 != nullptr
      && (v6 = &v5->IClientRenderable,
          ((int (__thiscall *)(IClientRenderable *, int))v5->GetModel)(a1: &v5->IClientRenderable, a2: a1) != 0) )
    {
      v7 = modelloader->__vftable;
      v17 = (char *)v6->GetModel(this: v6);
      v8 = (const char *)((int (__thiscall *)(IModelLoader *))v7->GetName)(a1: modelloader);
      V_FileBase(in: v8, out: v17, maxlen: (int)base);
    }
    else
    {
      V_strncpy(pDest: base, pSrc: "Snapshot", maxLen: 260);
    }
    v9 = "jpg";
    if ( !cl_takejpeg )
      v9 = "tga";
    V_snprintf(pDest: extension, maxLen: 260, pFormat: "%s.%s", defaultValue, v9);
    if ( cl_snapshot_subdirname[0] != 0 )
    {
      V_snprintf(pDest: filename, maxLen: 260, pFormat: "screenshots/%s/%s", base, cl_snapshot_subdirname);
      g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: filename, a3: "DEFAULT_WRITE_PATH");
    }
    if ( cl_snapshotname[0] != 0 )
    {
      V_strncpy(pDest: base, pSrc: cl_snapshotname, maxLen: 260);
      V_snprintf(pDest: filename, maxLen: 260, pFormat: "screenshots/%s%s", base, extension);
      v10 = 0;
      do
        V_snprintf(pDest: renamedfile, maxLen: 260, pFormat: "screenshots/%s_%04d%s", base, v10++, extension);
      while ( g_pFileSystem->GetFileTime(this: &g_pFileSystem->IBaseFileSystem, a2: renamedfile, a3: nullptr) != 0 );
      if ( v10 > 0 )
      {
        v16 = filename;
        ((void (__thiscall *)(IFileSystem *))g_pFileSystem->RenameFile)(a1: g_pFileSystem);
      }
      CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&cl_screenshotname.IConVar, value: defaultValue, a2: (int)v16);
    }
    else
    {
      do
      {
        v11 = cl_snapshotnum++;
        if ( cl_snapshot_subdirname[0] != 0 )
          V_snprintf(
            pDest: filename,
            maxLen: 260,
            pFormat: "screenshots/%s/%s/%s%04d%s",
            base,
            cl_snapshot_subdirname,
            base,
            v11,
            extension);
        else
          V_snprintf(pDest: filename, maxLen: 260, pFormat: "screenshots/%s%04d%s", base, v11, extension);
      }
      while ( g_pFileSystem->GetFileTime(this: &g_pFileSystem->IBaseFileSystem, a2: filename, a3: "DEFAULT_WRITE_PATH") != 0 );
    }
    if ( cl_snapshot_fullpathname[0] != 0 )
    {
      V_strncpy(pDest: filename, pSrc: cl_snapshot_fullpathname, maxLen: 260);
      cl_snapshot_fullpathname[0] = 0;
    }
    v12 = videomode->__vftable;
    if ( cl_takejpeg )
    {
      ((void (__cdecl *)(char *, int))v12->TakeSnapshotJPEG)(a1: filename, a2: cl_jpegquality);
      CServerRemoteAccess::UploadScreenshot(this: &g_ServerRemoteAccess, pFileName: filename);
    }
    else
    {
      ((void (__cdecl *)(char *))v12->TakeSnapshotTGA)(a1: filename);
    }
    cl_takesnapshot = false;
    CTestScriptMgr::CheckPoint(this: &g_TestScriptMgr, pName: "screenshot");
    materials->AllowThreading(this: materials, a2: bEnabled, a3: g_nMaterialSystemThread);
  }
  if ( cl_movieinfo.moviename[0] != 0 && !Con_IsVisible() && !scr_drawloading )
  {
    videomode->WriteMovieFrame(this: videomode, a2: &cl_movieinfo);
    ++cl_movieinfo.movieframe;
  }
  v13 = 0;
  if ( host_syncfps.m_pParent != nullptr && host_syncfps.m_pParent->m_Value.m_nValue != 0 )
  {
    m_pParent = host_framerate.m_pParent;
    if ( host_framerate.m_pParent->m_Value.m_fValue != 0.0 )
    {
      v13 = 1;
      v14 = _Plat_FloatTime(this: (CStatTime *)host_framerate.m_pParent) - flLastTime;
      if ( v14 >= 0.1 )
        v14 = 0.1;
      v15 = 1.0 / fabs(host_framerate.m_pParent->m_Value.m_fValue) - v14;
      if ( v15 > 0.0 )
        Sys_Sleep(msec: (int)(v15 * 1000.0));
    }
  }
  if ( !bReadPixelsFromFrontBuffer )
    Shader_SwapBuffers();
  if ( v13 != 0 )
    flLastTime = _Plat_FloatTime(this: (CStatTime *)m_pParent);
  saverestore->UpdateSaveGameScreenshots(this: saverestore);
  EngineTool_UpdateScreenshot();
}

//------------------------------------------------------------------------------
// Address: 0x1008ACD0
// Name: void CL_EndMovie(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_EndMovie()
{
  if ( cl_movieinfo.moviename[0] != 0 )
  {
    ConVar::SetValue(this: (ConVar *)&host_framerate.IConVar, value: s_flPreviousHostFramerate);
    s_flPreviousHostFramerate = 0.0;
    SND_MovieEnd();
    if ( (cl_movieinfo.type & 2) != 0 || (cl_movieinfo.type & 8) != 0 )
    {
      avi->FinishAVI(this: avi, a2: g_hCurrentAVI);
      g_hCurrentAVI = -1;
    }
    cl_movieinfo.moviename[0] = 0;
    cl_movieinfo.movieframe = 0;
    cl_movieinfo.type = 5;
    cl_movieinfo.jpeg_quality = 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008AD60
// Name: endmovie
// Source: json
//------------------------------------------------------------------------------
void __cdecl endmovie()
{
  if ( cl_movieinfo.moviename[0] != 0 )
  {
    CL_EndMovie();
    ConMsg(a1: "Stopped recording movie...\n");
  }
  else
  {
    ConMsg(a1: "No movie started.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008AD90
// Name: struct dlight_t __near * CL_AllocDlight(int)
// Source: json
//------------------------------------------------------------------------------
dlight_t *__cdecl CL_AllocDlight(int key)
{
  int v2; // esi
  int *p_key; // eax
  float *p_die; // edi
  CClientState *BaseLocalClient; // eax
  float v6; // xmm0_4
  int v7; // edx
  float *p_radius; // ecx
  float *v9; // ecx
  float keya; // [esp+14h] [ebp+8h]

  if ( key != 0 )
  {
    v2 = 0;
    p_key = &cl_dlights[0].key;
    while ( *p_key != key )
    {
      p_key += 17;
      ++v2;
      if ( (int)p_key >= (int)&cl_elights[0].key )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v2 = 0;
    p_die = &cl_dlights[0].die;
    while ( 1 )
    {
      keya = *p_die;
      BaseLocalClient = GetBaseLocalClient();
      if ( CClientState::GetTime(this: BaseLocalClient) > keya )
        break;
      p_die += 17;
      ++v2;
      if ( (int)p_die >= (int)&cl_elights[0].die )
      {
        if ( cl_retire_low_priority_lights.m_pParent == nullptr
          || cl_retire_low_priority_lights.m_pParent->m_Value.m_nValue == 0
          || key >= 1677721600 )
        {
          goto LABEL_53;
        }
        v2 = -1;
        v6 = 0.0;
        v7 = 1;
        p_radius = &cl_dlights[1].radius;
        do
        {
          if ( *((int *)p_radius + 5) >= 1677721600 && (v6 == 0.0 || v6 > *p_radius) )
          {
            v6 = *p_radius;
            v2 = v7;
          }
          if ( *((int *)p_radius + 22) >= 1677721600 && (v6 == 0.0 || v6 > p_radius[17]) )
          {
            v6 = p_radius[17];
            v2 = v7 + 1;
          }
          if ( *((int *)p_radius + 39) >= 1677721600 && (v6 == 0.0 || v6 > p_radius[34]) )
          {
            v6 = p_radius[34];
            v2 = v7 + 2;
          }
          if ( *((int *)p_radius + 56) >= 1677721600 && (v6 == 0.0 || v6 > p_radius[51]) )
          {
            v6 = p_radius[51];
            v2 = v7 + 3;
          }
          if ( *((int *)p_radius + 73) >= 1677721600 && (v6 == 0.0 || v6 > p_radius[68]) )
          {
            v6 = p_radius[68];
            v2 = v7 + 4;
          }
          if ( *((int *)p_radius + 90) >= 1677721600 && (v6 == 0.0 || v6 > p_radius[85]) )
          {
            v6 = p_radius[85];
            v2 = v7 + 5;
          }
          if ( *((int *)p_radius + 107) >= 1677721600 && (v6 == 0.0 || v6 > p_radius[102]) )
          {
            v6 = p_radius[102];
            v2 = v7 + 6;
          }
          if ( *((int *)p_radius + 124) >= 1677721600 && (v6 == 0.0 || v6 > p_radius[119]) )
          {
            v6 = p_radius[119];
            v2 = v7 + 7;
          }
          p_radius += 136;
          v7 += 8;
        }
        while ( (int)p_radius < (int)&cl_dlights[25].radius );
        if ( v7 < 32 )
        {
          v9 = &cl_dlights[v7].radius;
          do
          {
            if ( *((int *)v9 + 5) >= 1677721600 && (v6 == 0.0 || v6 > *v9) )
            {
              v6 = *v9;
              v2 = v7;
            }
            v9 += 17;
            ++v7;
          }
          while ( (int)v9 < (int)&cl_elights[0].radius );
        }
        if ( v2 == -1 )
LABEL_53:
          v2 = 0;
        break;
      }
    }
  }
  R_MarkDLightNotVisible(dlight: v2);
  memset(dst: (unsigned __int8 *)&cl_dlights[v2], value: 0, count: sizeof(dlight_t));
  cl_dlights[v2].key = key;
  g_bActiveDlights = true;
  r_dlightchanged |= 1 << v2;
  r_dlightactive |= 1 << v2;
  return &cl_dlights[v2];
}

//------------------------------------------------------------------------------
// Address: 0x1008AFE0
// Name: struct dlight_t __near * CL_AllocElight(int)
// Source: json
//------------------------------------------------------------------------------
dlight_t *__cdecl CL_AllocElight(int key)
{
  int v2; // ecx
  int *p_key; // eax
  int v4; // edi
  float *p_die; // esi
  CClientState *BaseLocalClient; // eax
  int v7; // esi
  float v8; // xmm0_4
  int v9; // edx
  float *p_radius; // ecx
  int v11; // eax
  dlight_t *v12; // esi
  float keya; // [esp+10h] [ebp+8h]

  if ( key != 0 )
  {
    v2 = 0;
    p_key = &cl_elights[0].key;
    while ( *p_key != key )
    {
      p_key += 17;
      ++v2;
      if ( (int)p_key >= (int)&g_DLightLeafAccessors[1].m_flDistToExitLeafSqr )
        goto LABEL_5;
    }
    v11 = v2;
  }
  else
  {
LABEL_5:
    v4 = 0;
    p_die = &cl_elights[0].die;
    do
    {
      keya = *p_die;
      BaseLocalClient = GetBaseLocalClient();
      if ( CClientState::GetTime(this: BaseLocalClient) > keya )
      {
        v11 = v4;
        goto LABEL_30;
      }
      p_die += 17;
      ++v4;
    }
    while ( (int)p_die < (int)&g_DLightLeafAccessors[1].m_vCachedPos.x );
    if ( cl_retire_low_priority_lights.m_pParent == nullptr
      || cl_retire_low_priority_lights.m_pParent->m_Value.m_nValue == 0
      || key >= 1677721600 )
    {
      goto LABEL_29;
    }
    v7 = -1;
    v8 = 0.0;
    v9 = 1;
    p_radius = &cl_elights[1].radius;
    do
    {
      if ( *((int *)p_radius + 5) >= 1677721600 && (v8 == 0.0 || v8 > *p_radius) )
      {
        v8 = *p_radius;
        v7 = v9;
      }
      if ( *((int *)p_radius + 22) >= 1677721600 && (v8 == 0.0 || v8 > p_radius[17]) )
      {
        v8 = p_radius[17];
        v7 = v9 + 1;
      }
      if ( *((int *)p_radius + 39) >= 1677721600 && (v8 == 0.0 || v8 > p_radius[34]) )
      {
        v8 = p_radius[34];
        v7 = v9 + 2;
      }
      p_radius += 51;
      v9 += 3;
    }
    while ( (int)p_radius < (int)&g_DLightLeafAccessors[0].m_flDistToExitLeafSqr );
    if ( v7 != -1 )
      v11 = v7;
    else
LABEL_29:
      v11 = 0;
  }
LABEL_30:
  v12 = &cl_elights[v11];
  memset(dst: (unsigned __int8 *)v12, value: 0, count: sizeof(dlight_t));
  v12->key = key;
  g_bActiveElights = true;
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1008B120
// Name: void CL_DecayLights(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_DecayLights()
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  if ( CClientState::GetFrameTime(this: BaseLocalClient) > 0.0 )
    CL_UpdateDAndELights(bUpdateDecay: true);
}

//------------------------------------------------------------------------------
// Address: 0x1008B140
// Name: void CL_SendMove(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_SendMove()
{
  int *p_chokedcommands; // esi
  int v1; // edi
  int chokedcommands; // esi
  int v3; // ecx
  int v4; // esi
  int v5; // edx
  bool v6; // al
  CClientState *LocalClient; // eax
  unsigned __int8 data[4000]; // [esp+8h] [ebp-FFCh] BYREF
  CLC_Move moveMsg; // [esp+FA8h] [ebp-5Ch] BYREF
  BOOL isnewcmd; // [esp+1000h] [ebp-4h]

  p_chokedcommands = &GetBaseLocalClient()->chokedcommands;
  v1 = GetBaseLocalClient()->lastoutgoingcommand + *p_chokedcommands + 1;
  chokedcommands = GetBaseLocalClient()->chokedcommands;
  if ( !splitscreen->IsDisconnecting(this: splitscreen, a2: 0) )
  {
    moveMsg.m_NetChannel = nullptr;
    moveMsg.__vftable = (CLC_Move_vtbl *)&CLC_Move::`vftable';
    moveMsg.m_DataIn.m_bOverflow = false;
    moveMsg.m_DataIn.m_pDebugName = nullptr;
    moveMsg.m_DataIn.m_nDataBits = -1;
    moveMsg.m_DataIn.m_nDataBytes = 0;
    bf_write::bf_write(this: &moveMsg.m_DataOut);
    moveMsg.m_bReliable = false;
    bf_write::StartWriting(this: &moveMsg.m_DataOut, pData: data, nBytes: 4000, iStartBit: 0, nBits: -1);
    v3 = chokedcommands + 1;
    moveMsg.m_nBackupCommands = 2;
    if ( chokedcommands + 1 >= 0 )
    {
      if ( v3 > 15 )
        v3 = 15;
    }
    else
    {
      v3 = 0;
    }
    v4 = v1 - v3 - 1;
    v5 = -1;
    moveMsg.m_nNewCommands = v3;
    v6 = true;
    if ( v4 > v1 )
      goto LABEL_13;
    do
    {
      LOBYTE(isnewcmd) = v4 >= v1 - moveMsg.m_nNewCommands + 1;
      v6 = v6
        && g_ClientDLL->WriteUsercmdDeltaToBuffer(
             this: g_ClientDLL,
             a2: 0,
             a3: &moveMsg.m_DataOut,
             a4: v5,
             a5: v4,
             a6: isnewcmd);
      v5 = v4++;
    }
    while ( v4 <= v1 );
    if ( v6 )
    {
LABEL_13:
      LocalClient = GetLocalClient(nSlot: -1);
      LocalClient->m_NetChannel->SendNetMsg(this: LocalClient->m_NetChannel, a2: &moveMsg, a3: false, a4: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008B270
// Name: void CL_Move(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall CL_Move(int a1@<edi>, float accumulated_extra_samples, bool bFinalTick)
{
  CClientState *BaseLocalClient; // esi
  bool (__thiscall *IsPlayingBack)(IDemoPlayer *); // edx
  int v5; // ebx
  IBaseClientDLL_vtbl *v6; // edi
  bool IsPaused; // al
  double v8; // st7
  double v9; // st7
  double v10; // st7
  IEngineVGuiInternal *v11; // eax
  INetChannel *m_NetChannel; // ecx
  double v13; // st7
  float interval_per_tick; // xmm0_4
  long double v15; // st5
  long double v16; // st4
  void **v18; // [esp+14h] [ebp-24h] BYREF
  con_nprint_s info; // [esp+18h] [ebp-20h] BYREF
  float v20; // [esp+30h] [ebp-8h]
  int v21; // [esp+34h] [ebp-4h]

  BaseLocalClient = GetBaseLocalClient();
  if ( BaseLocalClient->m_nSignonState < 2 || !Host_ShouldRun() )
    return;
  IsPlayingBack = demoplayer->IsPlayingBack;
  HIBYTE(v21) = 1;
  if ( IsPlayingBack(this: demoplayer) )
  {
    if ( !BaseLocalClient->ishltv )
      return;
    HIBYTE(v21) = 0;
  }
  if ( (!BaseLocalClient->m_NetChannel->IsLoopback(this: BaseLocalClient->m_NetChannel)
     || host_limitlocal.m_pParent != nullptr && host_limitlocal.m_pParent->m_Value.m_nValue != 0)
    && (BaseLocalClient->m_flNextCmdTime > net_time
     || !BaseLocalClient->m_NetChannel->CanPacket(this: BaseLocalClient->m_NetChannel)
     || !bFinalTick) )
  {
    HIBYTE(v21) = 0;
  }
  if ( BaseLocalClient->m_nSignonState == 6 )
  {
    v5 = BaseLocalClient->lastoutgoingcommand + BaseLocalClient->chokedcommands + 1;
    if ( !splitscreen->IsDisconnecting(this: splitscreen, a2: 0) )
    {
      v6 = g_ClientDLL->__vftable;
      IsPaused = CClientState::IsPaused(this: BaseLocalClient);
      ((void (__thiscall *)(IBaseClientDLL *, int, _DWORD, bool))v6->CreateMove)(
        a1: g_ClientDLL,
        a2: v5,
        a3: host_state.interval_per_tick - accumulated_extra_samples,
        a4: !IsPaused);
      if ( demorecorder->IsRecording(this: demorecorder) )
        demorecorder->RecordUserInput(this: demorecorder, a2: v5);
    }
    if ( HIBYTE(v21) == 0 )
    {
      BaseLocalClient->m_NetChannel->SetChoked(this: BaseLocalClient->m_NetChannel);
      ++BaseLocalClient->chokedcommands;
      return;
    }
    CL_SendMove();
  }
  if ( HIBYTE(v21) == 0 )
    return;
  if ( ((unsigned __int8 (__thiscall *)(INetChannel *, int))BaseLocalClient->m_NetChannel->IsTimingOut)(
         a1: BaseLocalClient->m_NetChannel,
         a2: a1) == 0
    || demoplayer->IsPlayingBack(this: demoplayer) )
  {
    goto LABEL_28;
  }
  if ( BaseLocalClient->m_nSignonState == 6 )
  {
    info.fixed_width_font = false;
    info.time_to_live = 1.0;
    info.color[0] = 1.0;
    info.index = 2;
    info.color[1] = 0.2;
    info.color[2] = 0.2;
    Con_NXPrintf(&info, fmt: "WARNING:  Connection Problem");
    v20 = BaseLocalClient->m_NetChannel->GetTimeoutSeconds(this: BaseLocalClient->m_NetChannel);
    v8 = ((double (__thiscall *)(INetChannel *))BaseLocalClient->m_NetChannel->GetTimeSinceLastReceived)(a1: BaseLocalClient->m_NetChannel);
    if ( v20 - v8 <= 0.0 )
    {
      v20 = 0.0;
      v10 = 0.0;
    }
    else
    {
      v9 = ((double (__thiscall *)(INetChannel *))BaseLocalClient->m_NetChannel->GetTimeSinceLastReceived)(a1: BaseLocalClient->m_NetChannel);
      v10 = v20 - v9;
    }
    info.index = 3;
    Con_NXPrintf(&info, fmt: "Auto-disconnect in %.1f seconds", v10);
    v11 = EngineVGui();
    v11->NeedConnectionProblemWaitScreen(this: v11);
    CBaseClientState::ForceFullUpdate(this: BaseLocalClient, pchReason: "connection problem");
LABEL_28:
    if ( BaseLocalClient->m_nSignonState == 6 )
    {
      LODWORD(info.color[1]) = BaseLocalClient->m_nDeltaTick;
      m_NetChannel = BaseLocalClient->m_NetChannel;
      info.color[2] = host_frametime_unbounded;
      info.time_to_live = 0.0;
      v18 = &NET_Tick::`vftable';
      LOBYTE(info.index) = 0;
      *(float *)&info.fixed_width_font = host_frametime_stddeviation;
      m_NetChannel->SendNetMsg(this: m_NetChannel, a2: (INetMessage *)&v18, a3: false, a4: false);
    }
  }
  BaseLocalClient->lastoutgoingcommand = BaseLocalClient->m_NetChannel->SendDatagram(
                                           this: BaseLocalClient->m_NetChannel,
                                           a2: nullptr);
  BaseLocalClient->chokedcommands = 0;
  if ( BaseLocalClient->m_nSignonState == 6 )
  {
    v13 = 1.0 / ((double (__thiscall *)(ConVar_ServerBounded *))cl_cmdrate->GetFloat)(a1: cl_cmdrate);
    v20 = v13;
    if ( v13 <= host_state.interval_per_tick )
      interval_per_tick = v20;
    else
      interval_per_tick = host_state.interval_per_tick;
    v20 = interval_per_tick;
    v15 = net_time - BaseLocalClient->m_flNextCmdTime;
    v16 = 0.0;
    if ( v15 < 0.0 || (v16 = v15, v15 <= v20) )
      BaseLocalClient->m_flNextCmdTime = net_time + v13 - v16;
    else
      BaseLocalClient->m_flNextCmdTime = net_time + v13 - v20;
  }
  else
  {
    BaseLocalClient->m_flNextCmdTime = net_time + 0.2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C580
// Name: void CL_DispatchSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_DispatchSounds()
{
  int i; // esi

  for ( i = CUtlRBTree<SoundInfo_t,int,bool (__cdecl *)(SoundInfo_t const &,SoundInfo_t const &),CUtlMemory<UtlRBTreeNode_t<SoundInfo_t,int>,int>>::FirstInorder(this: &g_SoundMessages);
        i != -1;
        i = CUtlRBTree<SoundInfo_t,int,bool (__cdecl *)(SoundInfo_t const &,SoundInfo_t const &),CUtlMemory<UtlRBTreeNode_t<SoundInfo_t,int>,int>>::NextInorder(
              this: &g_SoundMessages,
              i) )
  {
    if ( &g_SoundMessages.m_Elements.m_pMemory[i] != (UtlRBTreeNode_t<SoundInfo_t,int> *)-16 )
      CL_DispatchSound(sound: &g_SoundMessages.m_Elements.m_pMemory[i].m_Data);
  }
  CUtlRBTree<SoundInfo_t,int,bool (__cdecl *)(SoundInfo_t const &,SoundInfo_t const &),CUtlMemory<UtlRBTreeNode_t<SoundInfo_t,int>,int>>::RemoveAll(this: &g_SoundMessages);
}

//------------------------------------------------------------------------------
// Address: 0x1008C5D0
// Name: void CL_Retry(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_Retry()
{
  CVTFTexture *p_m_Remote; // edi
  int v1; // esi
  Remote_t *v2; // edi
  const char *v3; // eax
  const char *v4; // eax
  char *v5; // eax
  const char *v6; // eax
  vgui::CTreeViewListControl *v7; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v9; // [esp-Ch] [ebp-24h]
  const char *v10; // [esp-Ch] [ebp-24h]
  CUtlString cnx; // [esp+4h] [ebp-14h] BYREF
  CVTFTexture *v12; // [esp+14h] [ebp-4h]

  p_m_Remote = (CVTFTexture *)&GetBaseLocalClient()->m_Remote;
  v12 = p_m_Remote;
  if ( vgui::Image::GetWide(this: p_m_Remote) > 0 )
  {
    ConMsg(a1: "Commencing connection retry to ");
    CUtlString::CUtlString(this: &cnx);
    v1 = 0;
    if ( vgui::Image::GetWide(this: p_m_Remote) > 0 )
    {
      while ( 1 )
      {
        v2 = CAddressList::Get(this: (CAddressList *)p_m_Remote, index: v1);
        v9 = CUtlString::operator char const *(this: &v2->m_szRetryAddress);
        v3 = CUtlString::operator char const *(this: &v2->m_szAlias);
        ConMsg(a1: "%s(%s)", v3, v9);
        v4 = CUtlString::operator char const *(this: &v2->m_szRetryAddress);
        v5 = va(format: "\"%s\" ", v4);
        CUtlString::operator+=(this: &cnx, rhs: v5);
        if ( ++v1 >= vgui::Image::GetWide(this: v12) )
          break;
        p_m_Remote = v12;
      }
    }
    ConMsg(a1: "\n");
    v6 = CUtlString::operator char const *(this: &cnx);
    v10 = va(format: "connect %s\n", v6);
    TraceType = CTraceFilter::GetTraceType(this: v7);
    Cbuf_AddText(eTarget: TraceType, pText: v10, nTickDelay: 0);
    cnx.m_Storage.m_nActualLength = 0;
    if ( cnx.m_Storage.m_Memory.m_nGrowSize >= 0 && cnx.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cnx.m_Storage.m_Memory.m_pMemory);
  }
  else
  {
    ConMsg(a1: "Can't retry, no previous connection\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C6E0
// Name: retry
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl retry()
{
  CL_Retry();
}

//------------------------------------------------------------------------------
// Address: 0x1008C6F0
// Name: class CPureServerWhitelist __near * CL_LoadWhitelist(class INetworkStringTable __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPureServerWhitelist *__cdecl CL_LoadWhitelist(INetworkStringTable *pTable, const char *pName)
{
  INetworkStringTable *v2; // esi
  int v3; // eax
  unsigned __int8 *v4; // eax
  CPureServerWhitelist *v5; // esi
  CUtlBuffer buf; // [esp+4h] [ebp-30h] BYREF

  v2 = pTable;
  v3 = pTable->FindStringIndex(this: pTable, a2: pName);
  if ( v3 == 0xFFFF )
    return nullptr;
  v4 = (unsigned __int8 *)v2->GetStringUserData(this: v2, a2: v3, a3: (int *)&pTable);
  if ( v4 == nullptr )
    return nullptr;
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v4, nSize: (int)pTable, nFlags: 8u);
  v5 = CPureServerWhitelist::Create(pFileSystem: g_pFullFileSystem);
  CPureServerWhitelist::Decode(this: v5, &buf);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1008C780
// Name: void CL_CheckForPureServerWhitelist(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CL_CheckForPureServerWhitelist(int a1@<edi>)
{
  CClientState *BaseLocalClient; // eax
  CPureServerWhitelist *Whitelist; // eax
  CPureServerWhitelist *v3; // esi

  if ( GetBaseLocalClient()->m_nMaxClients > 1 && !GetBaseLocalClient()->ishltv )
  {
    if ( GetBaseLocalClient()->m_pServerStartupTable != nullptr
      && (BaseLocalClient = GetBaseLocalClient(),
          Whitelist = CL_LoadWhitelist(pTable: BaseLocalClient->m_pServerStartupTable, pName: "PureServerWhitelist"),
          v3 = Whitelist,
          Whitelist != nullptr) )
    {
      if ( CPureServerWhitelist::IsInFullyPureMode(this: Whitelist) )
        _Msg(a1: "Got pure server whitelist: sv_pure = 2.\n");
      else
        _Msg(a1: "Got pure server whitelist: sv_pure = 1.\n");
      CL_HandlePureServerWhitelist(a1, pWhitelist: v3);
    }
    else
    {
      _Msg(a1: "No pure server whitelist. sv_pure = 0\n");
      CL_HandlePureServerWhitelist(a1, pWhitelist: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C870
// Name: void SplitString(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SplitString(const char *pchString, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *list)
{
  const char *v2; // edx
  char *v3; // eax
  CUtlString *v4; // eax
  int m_Size; // edi
  const CUtlString *v6; // ebx
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v9; // eax
  CUtlString *v10; // ecx
  CUtlString *v11; // eax
  char token[1024]; // [esp+4h] [ebp-510h] BYREF
  characterset_t breakOnSpaces; // [esp+404h] [ebp-110h] BYREF
  CUtlString v14; // [esp+504h] [ebp-10h] BYREF

  CharacterSetBuild(pSetBuffer: &breakOnSpaces, pszSetString: " ");
  memset(token, 0, sizeof(token));
  v2 = pchString;
  v3 = token;
  while ( *v2 != 0 )
  {
    if ( (unsigned int)(v3 - token) >= 0x3FF )
      break;
    if ( breakOnSpaces.set[*v2] != 0 )
    {
      *v3 = 0;
      v4 = CUtlString::CUtlString(this: &v14, pString: token);
      m_Size = list->m_Size;
      v6 = v4;
      m_nAllocationCount = list->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CPortalRect,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)list,
          num: m_Size - m_nAllocationCount + 1);
      ++list->m_Size;
      m_pMemory = list->m_Memory.m_pMemory;
      v9 = list->m_Size - m_Size - 1;
      list->m_pElements = list->m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v9);
      v10 = &list->m_Memory.m_pMemory[m_Size];
      if ( v10 != nullptr )
        CUtlString::CUtlString(this: v10, string: v6);
      v14.m_Storage.m_nActualLength = 0;
      if ( v14.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v14.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14.m_Storage.m_Memory.m_pMemory);
          v14.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v14.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v2 = ++pchString;
      v3 = token;
    }
    else
    {
      *v3++ = *v2;
      pchString = ++v2;
    }
  }
  *v3 = 0;
  if ( _V_strlen(str: token) > 0 )
  {
    v11 = CUtlString::CUtlString(this: &v14, pString: token);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: list, elem: list->m_Size, src: v11);
    v14.m_Storage.m_nActualLength = 0;
    if ( v14.m_Storage.m_Memory.m_nGrowSize >= 0 && v14.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14.m_Storage.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008CA00
// Name: public: NET_SetConVar::NET_SetConVar(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
NET_SetConVar *__thiscall NET_SetConVar::NET_SetConVar(NET_SetConVar *this, const char *name, const char *value)
{
  NetMessageCvar_t cvar; // [esp+8h] [ebp-208h] BYREF

  this->m_NetChannel = nullptr;
  this->m_bReliable = true;
  this->__vftable = (NET_SetConVar_vtbl *)&NET_SetConVar::`vftable';
  this->m_ConVars.m_Memory.m_pMemory = nullptr;
  this->m_ConVars.m_Memory.m_nAllocationCount = 0;
  this->m_ConVars.m_Memory.m_nGrowSize = 0;
  this->m_ConVars.m_Size = 0;
  this->m_ConVars.m_pElements = nullptr;
  V_strncpy(pDest: cvar.name, pSrc: name, maxLen: 260);
  V_strncpy(pDest: cvar.value, pSrc: value, maxLen: 260);
  CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int>>::InsertBefore(
    this: &this->m_ConVars,
    elem: this->m_ConVars.m_Size,
    src: &cvar);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008CA80
// Name: setinfo
// Source: json
//------------------------------------------------------------------------------
void __usercall setinfo(int a1@<ebx>, int a2@<edi>, int a3@<esi>, const CCommand *args)
{
  const char *v4; // ebx
  const char *v5; // edi
  ConVar *v6; // esi
  EUniverse SteamUniverse; // eax
  int v8; // eax
  char *v9; // esi
  ConVar *v10; // eax
  CClientState *BaseLocalClient; // eax
  NET_SetConVar convar; // [esp+0h] [ebp-2Ch] BYREF
  ConVarRef sv_cheats; // [esp+24h] [ebp-8h] BYREF

  if ( args->m_nArgc != 3 )
  {
    _Msg(a1: "Syntax: setinfo <key> <value>\n");
    return;
  }
  v4 = args->m_ppArgv[2];
  v5 = args->m_ppArgv[1];
  v6 = (ConVar *)((int (__thiscall *)(ICvar *, const char *, int, int, int))g_pCVar->FindCommandBase_2)(
                   a1: g_pCVar,
                   a2: v5,
                   a3: a2,
                   a4: a3,
                   a5: a1);
  ConVarRef::ConVarRef(this: &sv_cheats, pName: "sv_cheats");
  if ( v6 == nullptr )
  {
    v8 = _V_strlen(str: v5);
    v9 = (char *)MemAlloc_Alloc(nSize: v8 + 1);
    _V_strcpy(dest: v9, src: v5);
    v10 = (ConVar *)MemAlloc_Alloc(nSize: 0x58u);
    if ( v10 != nullptr )
      v6 = ConVar::ConVar(
             this: v10,
             pName: v9,
             pDefaultValue: defaultValue,
             flags: 512,
             pHelpString: "Custom user info value");
    else
      v6 = nullptr;
LABEL_17:
    v6->SetValue_4(this: &v6->IConVar, a2: v4);
    if ( GetBaseLocalClient()->m_nSignonState >= 2 )
    {
      NET_SetConVar::NET_SetConVar(this: &convar, name: v5, value: v4);
      BaseLocalClient = GetBaseLocalClient();
      BaseLocalClient->m_NetChannel->SendNetMsg(this: BaseLocalClient->m_NetChannel, a2: &convar, a3: false, a4: false);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&convar.m_ConVars);
    }
    return;
  }
  if ( v6->IsCommand(this: v6) )
  {
    _Msg(a1: "Name %s is already registered as console command\n", v5);
    return;
  }
  if ( !v6->IsFlagSet(this: v6, a2: 512) )
  {
    _Msg(a1: "Convar %s is already registered but not as user info value\n", v5);
    return;
  }
  SteamUniverse = GetSteamUniverse();
  if ( SteamUniverse == k_EUniverseBeta || SteamUniverse == k_EUniverseDev || !v6->IsFlagSet(this: v6, a2: 2) )
  {
    if ( v6->IsFlagSet(this: v6, a2: 0x4000) && sv_cheats.m_pConVarState->m_Value.m_nValue == 0 )
    {
      _Msg(a1: "Convar %s is marked as cheat and cheats are off\n", v5);
      return;
    }
    goto LABEL_17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008CC00
// Name: void CL_AddSound(struct SoundInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_AddSound(const SoundInfo_t *sound)
{
  int v1; // eax
  int v2; // edx
  int v3; // edi
  UtlRBTreeNode_t<SoundInfo_t,int> *v4; // ecx
  int v5; // edx
  SoundInfo_t *p_m_Data; // edi
  int parent; // [esp+8h] [ebp-8h] BYREF
  bool leftchild; // [esp+Fh] [ebp-1h] BYREF

  parent = -1;
  leftchild = false;
  CUtlRBTree<SoundInfo_t,int,bool (__cdecl *)(SoundInfo_t const &,SoundInfo_t const &),CUtlMemory<UtlRBTreeNode_t<SoundInfo_t,int>,int>>::FindInsertionPosition(
    this: &g_SoundMessages,
    insert: sound,
    &parent,
    &leftchild);
  v1 = CUtlRBTree<SoundInfo_t,int,bool (__cdecl *)(SoundInfo_t const &,SoundInfo_t const &),CUtlMemory<UtlRBTreeNode_t<SoundInfo_t,int>,int>>::NewNode(this: &g_SoundMessages);
  v2 = parent;
  v3 = v1;
  v4 = &g_SoundMessages.m_Elements.m_pMemory[v1];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( v2 == -1 )
  {
    g_SoundMessages.m_Root = v1;
  }
  else
  {
    v5 = v2;
    if ( leftchild )
      g_SoundMessages.m_Elements.m_pMemory[v5].m_Left = v1;
    else
      g_SoundMessages.m_Elements.m_pMemory[v5].m_Right = v1;
  }
  CUtlRBTree<SoundInfo_t,int,bool (__cdecl *)(SoundInfo_t const &,SoundInfo_t const &),CUtlMemory<UtlRBTreeNode_t<SoundInfo_t,int>,int>>::InsertRebalance(
    this: &g_SoundMessages,
    elem: v1);
  ++g_SoundMessages.m_NumElements;
  p_m_Data = &g_SoundMessages.m_Elements.m_pMemory[v3].m_Data;
  if ( p_m_Data != nullptr )
    qmemcpy(p_m_Data, sound, sizeof(SoundInfo_t));
}

//------------------------------------------------------------------------------
// Address: 0x1008CCB0
// Name: connect_0
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall connect_0(int a1@<ebx>, const CCommand *args)
{
  int m_nArgv0Size; // eax
  const char *v3; // esi
  CUtlString *m_pMemory; // ebx
  const char *v5; // eax
  IEngineVGuiInternal *v6; // eax
  IEngineVGuiInternal *v7; // eax
  CClientState *LocalClient; // eax
  CUtlString *v9; // ecx
  const char *v10; // edi
  CClientState *BaseLocalClient; // esi
  const char *v12; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > argValues; // [esp+0h] [ebp-14h] BYREF

  if ( args->m_nArgc >= 2 )
  {
    m_nArgv0Size = args->m_nArgv0Size;
    v3 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( m_nArgv0Size == 0 )
      v3 = defaultValue;
    memset(&argValues, 0, sizeof(argValues));
    SplitString(pchString: v3, list: &argValues);
    if ( argValues.m_Size == 1 || argValues.m_Size == 2 )
    {
      m_pMemory = argValues.m_Memory.m_pMemory;
      v5 = CUtlString::operator char const *(this: argValues.m_Memory.m_pMemory);
      if ( V_strncmp(s1: v5, s2: "localhost", count: 9) != 0 )
      {
        Host_Disconnect(bShowMainMenu: false);
        NET_SetMultiplayer(multiplayer: true);
        v6 = EngineVGui();
        ((void (__thiscall *)(IEngineVGuiInternal *, int))v6->EnabledProgressBarForNextLoad)(a1: v6, a2: a1);
        SCR_BeginLoadingPlaque(levelName: nullptr);
        v7 = EngineVGui();
        v7->UpdateProgressBar(this: v7, a2: PROGRESS_BEGINCONNECT, a3: true);
      }
      else
      {
        LocalClient = GetLocalClient(nSlot: -1);
        ((void (__thiscall *)(CClientState *, _DWORD, int))LocalClient->Disconnect)(a1: LocalClient, a2: 0, a3: a1);
      }
      v9 = m_pMemory + 1;
      if ( argValues.m_Size != 2 )
        v9 = m_pMemory;
      v10 = CUtlString::operator char const *(this: v9);
      BaseLocalClient = GetBaseLocalClient();
      v12 = CUtlString::operator char const *(this: m_pMemory);
      ((void (__thiscall *)(CClientState *, const char *, const char *, CUtlString *, int))BaseLocalClient->Connect)(
        a1: BaseLocalClient,
        a2: v12,
        a3: v10,
        a4: argValues.m_Memory.m_pMemory,
        a5: argValues.m_Memory.m_nAllocationCount);
      gfExtendedError = false;
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&argValues);
    }
    else
    {
      ConMsg(a1: "connect:  can't parse '%s'\n", v3);
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&argValues);
    }
  }
  else
  {
    ConMsg(a1: "Usage:  connect <server>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008CDE0
// Name: connect_splitscreen
// Source: json
//------------------------------------------------------------------------------
void __usercall connect_splitscreen(int a1@<ebx>, int a2@<edi>, int a3@<esi>, const CCommand *args)
{
  int m_nArgv0Size; // eax
  const char *v5; // edi
  int m_Size; // esi
  CUtlString *m_pMemory; // edi
  const char *v8; // eax
  int v9; // eax
  int v10; // ebx
  const char *v11; // eax
  CClientState *LocalClient; // eax
  CUtlString *v13; // ecx
  CClientState *BaseLocalClient; // esi
  const char *v15; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > argValues; // [esp+0h] [ebp-14h] BYREF
  const CCommand *argsa; // [esp+1Ch] [ebp+8h]

  if ( args->m_nArgc >= 3 )
  {
    m_nArgv0Size = args->m_nArgv0Size;
    v5 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( m_nArgv0Size == 0 )
      v5 = defaultValue;
    memset(&argValues, 0, sizeof(argValues));
    SplitString(pchString: v5, list: &argValues);
    m_Size = argValues.m_Size;
    if ( argValues.m_Size == 2 || argValues.m_Size == 3 )
    {
      m_pMemory = argValues.m_Memory.m_pMemory;
      v8 = CUtlString::operator char const *(this: &argValues.m_Memory.m_pMemory[argValues.m_Size - 1]);
      v9 = V_atoi(str: v8);
      v10 = v9;
      if ( v9 > 0 )
      {
        if ( v9 <= host_state.max_splitscreen_players )
        {
          v11 = CUtlString::operator char const *(this: m_pMemory);
          if ( V_strncmp(s1: v11, s2: "localhost", count: 9) == 0 )
          {
            LocalClient = GetLocalClient(nSlot: -1);
            ((void (__thiscall *)(CClientState *, _DWORD, int, int, int))LocalClient->Disconnect)(
              a1: LocalClient,
              a2: 0,
              a3: a1,
              a4: a3,
              a5: a2);
            v13 = m_pMemory + 1;
            if ( m_Size != 3 )
              v13 = m_pMemory;
            argsa = (const CCommand *)CUtlString::operator char const *(this: v13);
            BaseLocalClient = GetBaseLocalClient();
            v15 = CUtlString::operator char const *(this: m_pMemory);
            BaseLocalClient->ConnectSplitScreen(this: BaseLocalClient, a2: v15, a3: (const char *)argsa, a4: v10);
            gfExtendedError = false;
          }
          CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&argValues);
        }
        else
        {
          ConMsg(a1: "Too many players\n");
          CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&argValues);
        }
      }
      else
      {
        ConMsg(a1: "Must have at least one player.\n");
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&argValues);
      }
    }
    else
    {
      ConMsg(a1: "connect_splitscreen:  can't parse '%s'\n", v5);
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&argValues);
    }
  }
  else
  {
    ConMsg(a1: "Usage:  connect <server> <# of players>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10211E4A
// Name: connect(x,x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall connect(SOCKET s, const struct sockaddr *name, int namelen)
{
  return __imp__connect@12(s, name, namelen);
}

//------------------------------------------------------------------------------
// Address: 0x103125F0
// Name: _dynamic_initializer_for__cl_resend__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_resend__()
{
  ConVar::ConVar(
    this: &cl_resend,
    pName: "cl_resend",
    pDefaultValue: "6",
    flags: 0x80000,
    pHelpString: "Delay in seconds before the client will resend the 'connect' attempt",
    bMin: true,
    fMin: 1.5,
    bMax: true,
    fMax: 20.0);
  return atexit(func: dynamic_atexit_destructor_for__cl_resend__);
}

//------------------------------------------------------------------------------
// Address: 0x10312640
// Name: _dynamic_initializer_for__cl_resend_timeout__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_resend_timeout__()
{
  ConVar::ConVar(
    this: &cl_resend_timeout,
    pName: "cl_resend_timeout",
    pDefaultValue: "60",
    flags: 0x80000,
    pHelpString: "Total time allowed for the client to resend the 'connect' attempt",
    bMin: true,
    fMin: 1.5,
    bMax: true,
    fMax: 20000.0);
  return atexit(func: dynamic_atexit_destructor_for__cl_resend_timeout__);
}

//------------------------------------------------------------------------------
// Address: 0x10312690
// Name: _dynamic_initializer_for__cl_name__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_name__()
{
  ConVar::ConVar(
    this: &cl_name,
    pName: "name",
    pDefaultValue: "unnamed",
    flags: (int)&loc_1000867F + 1,
    pHelpString: "Current user name",
    callback: (void (__cdecl *)(IConVar *, const char *, float))CL_NameCvarChanged);
  return atexit(func: dynamic_atexit_destructor_for__cl_name__);
}

//------------------------------------------------------------------------------
// Address: 0x103126F0
// Name: _dynamic_initializer_for__cl_interpolate__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_interpolate__()
{
  ConVar::ConVar(
    this: &cl_interpolate,
    pName: "cl_interpolate",
    pDefaultValue: "1.0",
    flags: 514,
    pHelpString: "Interpolate entities on the client.");
  return atexit(func: dynamic_atexit_destructor_for__cl_interpolate__);
}

//------------------------------------------------------------------------------
// Address: 0x10312720
// Name: _dynamic_initializer_for__cl_failremoteconnections__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_failremoteconnections__()
{
  ConVar::ConVar(
    this: &cl_failremoteconnections,
    pName: "cl_failremoteconnections",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Force connection attempts to time out");
  return atexit(func: dynamic_atexit_destructor_for__cl_failremoteconnections__);
}

//------------------------------------------------------------------------------
// Address: 0x10312CD0
// Name: _dynamic_initializer_for__cl_showdemooverlay__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_showdemooverlay__()
{
  ConVar::ConVar(
    this: &cl_showdemooverlay,
    pName: "cl_showdemooverlay",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "How often to flash demo recording/playback overlay (0 - disable overlay, -1 - show always)");
  return atexit(func: dynamic_atexit_destructor_for__cl_showdemooverlay__);
}

//------------------------------------------------------------------------------
// Address: 0x10313250
// Name: _dynamic_initializer_for__cl_entityreport__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_entityreport__()
{
  ConVar::ConVar(
    this: &cl_entityreport,
    pName: "cl_entityreport",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "For debugging, draw entity states to console");
  return atexit(func: dynamic_atexit_destructor_for__cl_entityreport__);
}

//------------------------------------------------------------------------------
// Address: 0x10313320
// Name: _dynamic_initializer_for__cl_flushentitypacket__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_flushentitypacket__()
{
  ConVar::ConVar(
    this: &cl_flushentitypacket,
    pName: "cl_flushentitypacket",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "For debugging. Force the engine to flush an entity packet.");
  return atexit(func: dynamic_atexit_destructor_for__cl_flushentitypacket__);
}

//------------------------------------------------------------------------------
// Address: 0x10313400
// Name: _dynamic_initializer_for__cl_LocalNetworkBackdoor__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_LocalNetworkBackdoor__()
{
  ConVar::ConVar(
    this: &cl_LocalNetworkBackdoor,
    pName: "cl_localnetworkbackdoor",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable network optimizations for single player games.");
  return atexit(func: dynamic_atexit_destructor_for__cl_LocalNetworkBackdoor__);
}

//------------------------------------------------------------------------------
// Address: 0x10313430
// Name: _dynamic_initializer_for__cl_ignorepackets__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_ignorepackets__()
{
  ConVar::ConVar(
    this: &cl_ignorepackets,
    pName: "cl_ignorepackets",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Force client to ignore packets (for debugging).");
  return atexit(func: dynamic_atexit_destructor_for__cl_ignorepackets__);
}

//------------------------------------------------------------------------------
// Address: 0x10313460
// Name: _dynamic_initializer_for__cl_playback_screenshots__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_playback_screenshots__()
{
  ConVar::ConVar(
    this: &cl_playback_screenshots,
    pName: "cl_playback_screenshots",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Allows the client to playback screenshot and jpeg commands in demos.");
  return atexit(func: dynamic_atexit_destructor_for__cl_playback_screenshots__);
}

//------------------------------------------------------------------------------
// Address: 0x10313490
// Name: _dynamic_initializer_for__cl_dlights__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
const IClientRenderable **dynamic_initializer_for__cl_dlights__()
{
  int v0; // ecx
  const IClientRenderable **result; // eax

  v0 = 31;
  result = &cl_dlights[0].m_pExclusiveLightReceiver;
  do
  {
    *result = nullptr;
    result += 17;
    --v0;
  }
  while ( v0 >= 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103134B0
// Name: _dynamic_initializer_for__cl_elights__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
const IClientRenderable **dynamic_initializer_for__cl_elights__()
{
  int v0; // ecx
  const IClientRenderable **result; // eax

  v0 = 63;
  result = &cl_elights[0].m_pExclusiveLightReceiver;
  do
  {
    *result = nullptr;
    result += 17;
    --v0;
  }
  while ( v0 >= 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10313540
// Name: _dynamic_initializer_for__cl_retire_low_priority_lights__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_retire_low_priority_lights__()
{
  ConVar::ConVar(
    this: &cl_retire_low_priority_lights,
    pName: "cl_retire_low_priority_lights",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Low priority dlights are replaced by high priority ones");
  return atexit(func: dynamic_atexit_destructor_for__cl_retire_low_priority_lights__);
}

//------------------------------------------------------------------------------
// Address: 0x10313640
// Name: _dynamic_initializer_for__cl_screenshotname__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_screenshotname__()
{
  ConVar::ConVar(
    this: &cl_screenshotname,
    pName: "cl_screenshotname",
    pDefaultValue: defaultValue,
    flags: 0,
    pHelpString: "Custom Screenshot name");
  return atexit(func: dynamic_atexit_destructor_for__cl_screenshotname__);
}

//------------------------------------------------------------------------------
// Address: 0x10313850
// Name: _dynamic_initializer_for__cl_view_command__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_view_command__()
{
  ConCommand::ConCommand(
    this: &cl_view_command,
    pName: "cl_view",
    callback: (void (__cdecl *)())cl_view,
    pHelpString: "Set the view entity index.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_view_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313880
// Name: _dynamic_initializer_for__cl_showents_command__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_showents_command__()
{
  ConCommand::ConCommand(
    this: &cl_showents_command,
    pName: "cl_showents",
    callback: cl_showents,
    pHelpString: "Dump entity list to console.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_showents_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103138E0
// Name: _dynamic_initializer_for__cl_language__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_language__()
{
  ConVar::ConVar(
    this: &cl_language,
    pName: "cl_language",
    pDefaultValue: "english",
    flags: 512,
    pHelpString: "Language (from Steam API)");
  return atexit(func: dynamic_atexit_destructor_for__cl_language__);
}

//------------------------------------------------------------------------------
// Address: 0x10313910
// Name: _dynamic_initializer_for__cl_cloud_settings__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_cloud_settings__()
{
  ConVar::ConVar(
    this: &cl_cloud_settings,
    pName: "cl_cloud_settings",
    pDefaultValue: "-1",
    flags: 16,
    pHelpString: "Cloud enabled from (from HKCU\\Software\\Valve\\Steam\\Apps\\appid\\Cloud)",
    callback: (void (__cdecl *)(IConVar *, const char *, float))CL_ChangeCloudSettingsCvar);
  return atexit(func: dynamic_atexit_destructor_for__cl_cloud_settings__);
}

//------------------------------------------------------------------------------
// Address: 0x10313940
// Name: _dynamic_initializer_for__cl_fullupdate_command__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_fullupdate_command__()
{
  ConCommand::ConCommand(
    this: &cl_fullupdate_command,
    pName: "cl_fullupdate",
    callback: cl_fullupdate,
    pHelpString: "Forces the server to send a full update packet",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_fullupdate_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103139A0
// Name: _dynamic_initializer_for__cl_precacheinfo_command__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_precacheinfo_command__()
{
  ConCommand::ConCommand(
    this: &cl_precacheinfo_command,
    pName: "cl_precacheinfo",
    callback: (void (__cdecl *)())cl_precacheinfo,
    pHelpString: "Show precache info (client).",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_precacheinfo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103139D0
// Name: _dynamic_initializer_for__cl_showevents__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_showevents__()
{
  ConVar::ConVar(
    this: &cl_showevents,
    pName: "cl_showevents",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Print event firing info in the console");
  return atexit(func: dynamic_atexit_destructor_for__cl_showevents__);
}

//------------------------------------------------------------------------------
// Address: 0x10313A00
// Name: _dynamic_initializer_for__cl_showpluginmessages__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_showpluginmessages__()
{
  ConVar::ConVar(
    this: &cl_showpluginmessages,
    pName: "cl_showpluginmessages",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Allow plugins to display messages to you");
  return atexit(func: dynamic_atexit_destructor_for__cl_showpluginmessages__);
}

//------------------------------------------------------------------------------
// Address: 0x10313DA0
// Name: _dynamic_initializer_for__cl_timeout__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_timeout__()
{
  ConVar::ConVar(
    this: &cl_timeout,
    pName: "cl_timeout",
    pDefaultValue: "30",
    flags: 128,
    pHelpString: "After this many seconds without receiving a packet from the server, the client will disconnect itself");
  return atexit(func: dynamic_atexit_destructor_for__cl_timeout__);
}

//------------------------------------------------------------------------------
// Address: 0x10313DD0
// Name: _dynamic_initializer_for__cl_logofile__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_logofile__()
{
  ConVar::ConVar(
    this: &cl_logofile,
    pName: "cl_logofile",
    pDefaultValue: "materials/vgui/logos/spray_bullseye.vtf",
    flags: 128,
    pHelpString: "Spraypoint logo decal.");
  return atexit(func: dynamic_atexit_destructor_for__cl_logofile__);
}

//------------------------------------------------------------------------------
// Address: 0x10313E00
// Name: _dynamic_initializer_for__cl_soundfile__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_soundfile__()
{
  ConVar::ConVar(
    this: &cl_soundfile,
    pName: "cl_soundfile",
    pDefaultValue: defaultValue,
    flags: 128,
    pHelpString: "Jingle sound file.");
  return atexit(func: dynamic_atexit_destructor_for__cl_soundfile__);
}

//------------------------------------------------------------------------------
// Address: 0x10313E30
// Name: _dynamic_initializer_for__cl_forcepreload__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_forcepreload__()
{
  ConVar::ConVar(
    this: &cl_forcepreload,
    pName: "cl_forcepreload",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "Whether we should force preloading.");
  return atexit(func: dynamic_atexit_destructor_for__cl_forcepreload__);
}

//------------------------------------------------------------------------------
// Address: 0x10313E60
// Name: _dynamic_initializer_for__cl_allowdownload__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_allowdownload__()
{
  ConVar::ConVar(
    this: &cl_allowdownload,
    pName: "cl_allowdownload",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Client downloads customization files");
  return atexit(func: dynamic_atexit_destructor_for__cl_allowdownload__);
}

//------------------------------------------------------------------------------
// Address: 0x10313E90
// Name: _dynamic_initializer_for__cl_downloadfilter__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_downloadfilter__()
{
  ConVar::ConVar(
    this: &cl_downloadfilter,
    pName: "cl_downloadfilter",
    pDefaultValue: "all",
    flags: 128,
    pHelpString: "Determines which files can be downloaded from the server (all, none, nosounds)");
  return atexit(func: dynamic_atexit_destructor_for__cl_downloadfilter__);
}

//------------------------------------------------------------------------------
// Address: 0x10318F40
// Name: _dynamic_initializer_for__cl_rate_var__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_rate_var__()
{
  ConVar::ConVar(
    this: &cl_rate_var,
    pName: "rate",
    pDefaultValue: "10000",
    flags: 512,
    pHelpString: "Max bytes/sec the host can receive data",
    callback: (void (__cdecl *)(IConVar *, const char *, float))CL_RateCvarChanged);
  cl_rate_var.ConVar_ServerBounded::ConVar::ConCommandBase::__vftable = (CBoundedCvar_Rate_vtbl *)&CBoundedCvar_Rate::`vftable'{for `ConCommandBase'};
  cl_rate_var.ConVar_ServerBounded::ConVar::IConVar::__vftable = (IConVar_vtbl *)&CBoundedCvar_Rate::`vftable'{for `IConVar'};
  return atexit(func: dynamic_atexit_destructor_for__cl_rate_var__);
}

//------------------------------------------------------------------------------
// Address: 0x10318F90
// Name: _dynamic_initializer_for__cl_cmdrate_var__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_cmdrate_var__()
{
  ConVar::ConVar(
    this: &cl_cmdrate_var,
    pName: "cl_cmdrate",
    pDefaultValue: "30",
    flags: 640,
    pHelpString: "Max number of command packets sent to server per second",
    bMin: true,
    fMin: 10.0,
    bMax: true,
    fMax: 100.0);
  cl_cmdrate_var.ConVar_ServerBounded::ConVar::ConCommandBase::__vftable = (CBoundedCvar_CmdRate_vtbl *)&CBoundedCvar_CmdRate::`vftable'{for `ConCommandBase'};
  cl_cmdrate_var.ConVar_ServerBounded::ConVar::IConVar::__vftable = (IConVar_vtbl *)&CBoundedCvar_CmdRate::`vftable'{for `IConVar'};
  return atexit(func: dynamic_atexit_destructor_for__cl_cmdrate_var__);
}

//------------------------------------------------------------------------------
// Address: 0x10318FF0
// Name: _dynamic_initializer_for__cl_updaterate_var__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_updaterate_var__()
{
  ConVar::ConVar(
    this: &cl_updaterate_var,
    pName: "cl_updaterate",
    pDefaultValue: "20",
    flags: 640,
    pHelpString: "Number of packets per second of updates you are requesting from the server");
  cl_updaterate_var.ConVar_ServerBounded::ConVar::ConCommandBase::__vftable = (CBoundedCvar_UpdateRate_vtbl *)&CBoundedCvar_UpdateRate::`vftable'{for `ConCommandBase'};
  cl_updaterate_var.ConVar_ServerBounded::ConVar::IConVar::__vftable = (IConVar_vtbl *)&CBoundedCvar_UpdateRate::`vftable'{for `IConVar'};
  return atexit(func: dynamic_atexit_destructor_for__cl_updaterate_var__);
}

//------------------------------------------------------------------------------
// Address: 0x10319030
// Name: _dynamic_initializer_for__cl_clock_correction__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_clock_correction__()
{
  ConVar::ConVar(
    this: &cl_clock_correction,
    pName: "cl_clock_correction",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Enable/disable clock correction on the client.");
  return atexit(func: dynamic_atexit_destructor_for__cl_clock_correction__);
}

//------------------------------------------------------------------------------
// Address: 0x10319060
// Name: _dynamic_initializer_for__cl_clockdrift_max_ms__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_clockdrift_max_ms__()
{
  ConVar::ConVar(
    this: &cl_clockdrift_max_ms,
    pName: "cl_clockdrift_max_ms",
    pDefaultValue: "150",
    flags: 0x4000,
    pHelpString: "Maximum number of milliseconds the clock is allowed to drift before the client snaps its clock to the server's.");
  return atexit(func: dynamic_atexit_destructor_for__cl_clockdrift_max_ms__);
}

//------------------------------------------------------------------------------
// Address: 0x10319090
// Name: _dynamic_initializer_for__cl_clockdrift_max_ms_threadmode__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_clockdrift_max_ms_threadmode__()
{
  ConVar::ConVar(
    this: &cl_clockdrift_max_ms_threadmode,
    pName: "cl_clockdrift_max_ms_threadmode",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Maximum number of milliseconds the clock is allowed to drift before the client snaps its clock to the server's.");
  return atexit(func: dynamic_atexit_destructor_for__cl_clockdrift_max_ms_threadmode__);
}

//------------------------------------------------------------------------------
// Address: 0x103190C0
// Name: _dynamic_initializer_for__cl_clock_showdebuginfo__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_clock_showdebuginfo__()
{
  ConVar::ConVar(
    this: &cl_clock_showdebuginfo,
    pName: "cl_clock_showdebuginfo",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Show debugging info about the clock drift. ");
  return atexit(func: dynamic_atexit_destructor_for__cl_clock_showdebuginfo__);
}

//------------------------------------------------------------------------------
// Address: 0x103190F0
// Name: _dynamic_initializer_for__cl_clock_correction_force_server_tick__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_clock_correction_force_server_tick__()
{
  ConVar::ConVar(
    this: &cl_clock_correction_force_server_tick,
    pName: "cl_clock_correction_force_server_tick",
    pDefaultValue: "999",
    flags: 0x4000,
    pHelpString: "Force clock correction to match the server tick + this offset (-999 disables it).");
  return atexit(func: dynamic_atexit_destructor_for__cl_clock_correction_force_server_tick__);
}

//------------------------------------------------------------------------------
// Address: 0x10319120
// Name: _dynamic_initializer_for__cl_clock_correction_adjustment_max_amount__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_clock_correction_adjustment_max_amount__()
{
  ConVar::ConVar(
    this: &cl_clock_correction_adjustment_max_amount,
    pName: "cl_clock_correction_adjustment_max_amount",
    pDefaultValue: "200",
    flags: 0x4000,
    pHelpString: "Sets the maximum number of milliseconds per second it is allowed to correct the client clock. It will only correct t"
    "his amount if the difference between the client and server clock is equal to or larger than cl_clock_correction_adju"
    "stment_max_offset.");
  return atexit(func: dynamic_atexit_destructor_for__cl_clock_correction_adjustment_max_amount__);
}

//------------------------------------------------------------------------------
// Address: 0x10319150
// Name: _dynamic_initializer_for__cl_clock_correction_adjustment_min_offset__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_clock_correction_adjustment_min_offset__()
{
  ConVar::ConVar(
    this: &cl_clock_correction_adjustment_min_offset,
    pName: "cl_clock_correction_adjustment_min_offset",
    pDefaultValue: "10",
    flags: 0x4000,
    pHelpString: "If the clock offset is less than this amount (in milliseconds), then no clock correction is applied.");
  return atexit(func: dynamic_atexit_destructor_for__cl_clock_correction_adjustment_min_offset__);
}

//------------------------------------------------------------------------------
// Address: 0x10319180
// Name: _dynamic_initializer_for__cl_clock_correction_adjustment_max_offset__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_clock_correction_adjustment_max_offset__()
{
  ConVar::ConVar(
    this: &cl_clock_correction_adjustment_max_offset,
    pName: "cl_clock_correction_adjustment_max_offset",
    pDefaultValue: "90",
    flags: 0x4000,
    pHelpString: "As the clock offset goes from cl_clock_correction_adjustment_min_offset to this value (in milliseconds), it moves to"
    "wards applying cl_clock_correction_adjustment_max_amount of adjustment. That way, the response is small when the offset is small.");
  return atexit(func: dynamic_atexit_destructor_for__cl_clock_correction_adjustment_max_offset__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A500
// Name: _dynamic_initializer_for__cl_configversion__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_configversion__()
{
  ConVar::ConVar(
    this: &cl_configversion,
    pName: "cl_configversion",
    pDefaultValue: "2",
    flags: 2,
    pHelpString: "Configuration layout version.");
  return atexit(func: dynamic_atexit_destructor_for__cl_configversion__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A530
// Name: _dynamic_initializer_for__cl_configversion_dummy__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_configversion_dummy__()
{
  ConVar::ConVar(
    this: &cl_configversion_dummy,
    pName: "cl_configversion_dummy",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Configuration layout version dummy.");
  return atexit(func: dynamic_atexit_destructor_for__cl_configversion_dummy__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D4D0
// Name: _dynamic_initializer_for__cl_allowupload__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_allowupload__()
{
  ConVar::ConVar(
    this: &cl_allowupload,
    pName: "cl_allowupload",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Client uploads customization files");
  return atexit(func: dynamic_atexit_destructor_for__cl_allowupload__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D500
// Name: _dynamic_initializer_for__cl_voice_filter__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_voice_filter__()
{
  ConVar::ConVar(
    this: &cl_voice_filter,
    pName: "cl_voice_filter",
    pDefaultValue: defaultValue,
    flags: 0,
    pHelpString: "Filter voice by name substring");
  return atexit(func: dynamic_atexit_destructor_for__cl_voice_filter__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D970
// Name: _dynamic_initializer_for__cl_skipslowpath__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_skipslowpath__()
{
  ConVar::ConVar(
    this: &cl_skipslowpath,
    pName: "cl_skipslowpath",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Set to 1 to skip any models that don't go through the model fast path");
  return atexit(func: dynamic_atexit_destructor_for__cl_skipslowpath__);
}

//------------------------------------------------------------------------------
// Address: 0x103221B0
// Name: _dynamic_atexit_destructor_for__cl_resend__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_resend__()
{
  ConVar::~ConVar(this: &cl_resend);
}

//------------------------------------------------------------------------------
// Address: 0x103221C0
// Name: _dynamic_atexit_destructor_for__cl_resend_timeout__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_resend_timeout__()
{
  ConVar::~ConVar(this: &cl_resend_timeout);
}

//------------------------------------------------------------------------------
// Address: 0x103221D0
// Name: _dynamic_atexit_destructor_for__cl_name__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_name__()
{
  ConVar::~ConVar(this: &cl_name);
}

//------------------------------------------------------------------------------
// Address: 0x103221F0
// Name: _dynamic_atexit_destructor_for__cl_interpolate__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_interpolate__()
{
  ConVar::~ConVar(this: &cl_interpolate);
}

//------------------------------------------------------------------------------
// Address: 0x10322200
// Name: _dynamic_atexit_destructor_for__cl_failremoteconnections__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_failremoteconnections__()
{
  ConVar::~ConVar(this: &cl_failremoteconnections);
}

//------------------------------------------------------------------------------
// Address: 0x103223F0
// Name: _dynamic_atexit_destructor_for__cl_showdemooverlay__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_showdemooverlay__()
{
  ConVar::~ConVar(this: &cl_showdemooverlay);
}

//------------------------------------------------------------------------------
// Address: 0x10322620
// Name: _dynamic_atexit_destructor_for__cl_entityreport__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_entityreport__()
{
  ConVar::~ConVar(this: &cl_entityreport);
}

//------------------------------------------------------------------------------
// Address: 0x10322670
// Name: _dynamic_atexit_destructor_for__cl_flushentitypacket__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_flushentitypacket__()
{
  ConVar::~ConVar(this: &cl_flushentitypacket);
}

//------------------------------------------------------------------------------
// Address: 0x10322700
// Name: _dynamic_atexit_destructor_for__cl_LocalNetworkBackdoor__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_LocalNetworkBackdoor__()
{
  ConVar::~ConVar(this: &cl_LocalNetworkBackdoor);
}

//------------------------------------------------------------------------------
// Address: 0x10322710
// Name: _dynamic_atexit_destructor_for__cl_ignorepackets__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_ignorepackets__()
{
  ConVar::~ConVar(this: &cl_ignorepackets);
}

//------------------------------------------------------------------------------
// Address: 0x10322720
// Name: _dynamic_atexit_destructor_for__cl_playback_screenshots__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_playback_screenshots__()
{
  ConVar::~ConVar(this: &cl_playback_screenshots);
}

//------------------------------------------------------------------------------
// Address: 0x10322740
// Name: _dynamic_atexit_destructor_for__cl_retire_low_priority_lights__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_retire_low_priority_lights__()
{
  ConVar::~ConVar(this: &cl_retire_low_priority_lights);
}

//------------------------------------------------------------------------------
// Address: 0x10322790
// Name: _dynamic_atexit_destructor_for__cl_screenshotname__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_screenshotname__()
{
  ConVar::~ConVar(this: &cl_screenshotname);
}

//------------------------------------------------------------------------------
// Address: 0x10322840
// Name: _dynamic_atexit_destructor_for__cl_view_command__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_view_command__()
{
  ConCommand::~ConCommand(this: &cl_view_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322850
// Name: _dynamic_atexit_destructor_for__cl_showents_command__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_showents_command__()
{
  ConCommand::~ConCommand(this: &cl_showents_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322870
// Name: _dynamic_atexit_destructor_for__cl_language__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_language__()
{
  ConVar::~ConVar(this: &cl_language);
}

//------------------------------------------------------------------------------
// Address: 0x10322880
// Name: _dynamic_atexit_destructor_for__cl_cloud_settings__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_cloud_settings__()
{
  ConVar::~ConVar(this: &cl_cloud_settings);
}

//------------------------------------------------------------------------------
// Address: 0x10322890
// Name: _dynamic_atexit_destructor_for__cl_fullupdate_command__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_fullupdate_command__()
{
  ConCommand::~ConCommand(this: &cl_fullupdate_command);
}

//------------------------------------------------------------------------------
// Address: 0x103228B0
// Name: _dynamic_atexit_destructor_for__cl_precacheinfo_command__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_precacheinfo_command__()
{
  ConCommand::~ConCommand(this: &cl_precacheinfo_command);
}

//------------------------------------------------------------------------------
// Address: 0x103228D0
// Name: _dynamic_atexit_destructor_for__cl_showevents__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_showevents__()
{
  ConVar::~ConVar(this: &cl_showevents);
}

//------------------------------------------------------------------------------
// Address: 0x103228E0
// Name: _dynamic_atexit_destructor_for__cl_showpluginmessages__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_showpluginmessages__()
{
  ConVar::~ConVar(this: &cl_showpluginmessages);
}

//------------------------------------------------------------------------------
// Address: 0x10322A40
// Name: _dynamic_atexit_destructor_for__cl_timeout__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_timeout__()
{
  ConVar::~ConVar(this: &cl_timeout);
}

//------------------------------------------------------------------------------
// Address: 0x10322A50
// Name: _dynamic_atexit_destructor_for__cl_logofile__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_logofile__()
{
  ConVar::~ConVar(this: &cl_logofile);
}

//------------------------------------------------------------------------------
// Address: 0x10322A60
// Name: _dynamic_atexit_destructor_for__cl_soundfile__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_soundfile__()
{
  ConVar::~ConVar(this: &cl_soundfile);
}

//------------------------------------------------------------------------------
// Address: 0x10322A70
// Name: _dynamic_atexit_destructor_for__cl_forcepreload__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_forcepreload__()
{
  ConVar::~ConVar(this: &cl_forcepreload);
}

//------------------------------------------------------------------------------
// Address: 0x10322A80
// Name: _dynamic_atexit_destructor_for__cl_allowdownload__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_allowdownload__()
{
  ConVar::~ConVar(this: &cl_allowdownload);
}

//------------------------------------------------------------------------------
// Address: 0x10322A90
// Name: _dynamic_atexit_destructor_for__cl_downloadfilter__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_downloadfilter__()
{
  ConVar::~ConVar(this: &cl_downloadfilter);
}

//------------------------------------------------------------------------------
// Address: 0x10324B40
// Name: _dynamic_atexit_destructor_for__cl_rate_var__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_rate_var__()
{
  ConVar::~ConVar(this: &cl_rate_var);
}

//------------------------------------------------------------------------------
// Address: 0x10324B50
// Name: _dynamic_atexit_destructor_for__cl_cmdrate_var__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_cmdrate_var__()
{
  ConVar::~ConVar(this: &cl_cmdrate_var);
}

//------------------------------------------------------------------------------
// Address: 0x10324B60
// Name: _dynamic_atexit_destructor_for__cl_updaterate_var__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_updaterate_var__()
{
  ConVar::~ConVar(this: &cl_updaterate_var);
}

//------------------------------------------------------------------------------
// Address: 0x10324B70
// Name: _dynamic_atexit_destructor_for__cl_clock_correction__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_clock_correction__()
{
  ConVar::~ConVar(this: &cl_clock_correction);
}

//------------------------------------------------------------------------------
// Address: 0x10324B80
// Name: _dynamic_atexit_destructor_for__cl_clockdrift_max_ms__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_clockdrift_max_ms__()
{
  ConVar::~ConVar(this: &cl_clockdrift_max_ms);
}

//------------------------------------------------------------------------------
// Address: 0x10324B90
// Name: _dynamic_atexit_destructor_for__cl_clockdrift_max_ms_threadmode__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_clockdrift_max_ms_threadmode__()
{
  ConVar::~ConVar(this: &cl_clockdrift_max_ms_threadmode);
}

//------------------------------------------------------------------------------
// Address: 0x10324BA0
// Name: _dynamic_atexit_destructor_for__cl_clock_showdebuginfo__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_clock_showdebuginfo__()
{
  ConVar::~ConVar(this: &cl_clock_showdebuginfo);
}

//------------------------------------------------------------------------------
// Address: 0x10324BB0
// Name: _dynamic_atexit_destructor_for__cl_clock_correction_force_server_tick__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_clock_correction_force_server_tick__()
{
  ConVar::~ConVar(this: &cl_clock_correction_force_server_tick);
}

//------------------------------------------------------------------------------
// Address: 0x10324BC0
// Name: _dynamic_atexit_destructor_for__cl_clock_correction_adjustment_max_amount__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_clock_correction_adjustment_max_amount__()
{
  ConVar::~ConVar(this: &cl_clock_correction_adjustment_max_amount);
}

//------------------------------------------------------------------------------
// Address: 0x10324BD0
// Name: _dynamic_atexit_destructor_for__cl_clock_correction_adjustment_min_offset__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_clock_correction_adjustment_min_offset__()
{
  ConVar::~ConVar(this: &cl_clock_correction_adjustment_min_offset);
}

//------------------------------------------------------------------------------
// Address: 0x10324BE0
// Name: _dynamic_atexit_destructor_for__cl_clock_correction_adjustment_max_offset__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_clock_correction_adjustment_max_offset__()
{
  ConVar::~ConVar(this: &cl_clock_correction_adjustment_max_offset);
}

//------------------------------------------------------------------------------
// Address: 0x10325470
// Name: _dynamic_atexit_destructor_for__cl_configversion__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_configversion__()
{
  ConVar::~ConVar(this: &cl_configversion);
}

//------------------------------------------------------------------------------
// Address: 0x10325480
// Name: _dynamic_atexit_destructor_for__cl_configversion_dummy__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_configversion_dummy__()
{
  ConVar::~ConVar(this: &cl_configversion_dummy);
}

//------------------------------------------------------------------------------
// Address: 0x10326690
// Name: _dynamic_atexit_destructor_for__cl_allowupload__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_allowupload__()
{
  ConVar::~ConVar(this: &cl_allowupload);
}

//------------------------------------------------------------------------------
// Address: 0x103266A0
// Name: _dynamic_atexit_destructor_for__cl_voice_filter__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_voice_filter__()
{
  ConVar::~ConVar(this: &cl_voice_filter);
}

//------------------------------------------------------------------------------
// Address: 0x103267F0
// Name: _dynamic_atexit_destructor_for__cl_skipslowpath__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_skipslowpath__()
{
  ConVar::~ConVar(this: &cl_skipslowpath);
}

//------------------------------------------------------------------------------
// Address: 0x103126C0
// Name: _dynamic_initializer_for__password__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__password__()
{
  ConVar::ConVar(
    this: &password,
    pName: "password",
    pDefaultValue: defaultValue,
    flags: 537002112,
    pHelpString: "Current server access password");
  return atexit(func: dynamic_atexit_destructor_for__password__);
}

//------------------------------------------------------------------------------
// Address: 0x10312750
// Name: _dynamic_initializer_for__g_BrushBatchRenderer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BrushBatchRenderer__()
{
  g_BrushBatchRenderer.m_Mutex.m_ownerID = 0;
  g_BrushBatchRenderer.m_Mutex.m_depth = 0;
  g_BrushBatchRenderer.m_renderList.m_Memory.m_pMemory = nullptr;
  g_BrushBatchRenderer.m_renderList.m_Memory.m_nAllocationCount = 0;
  g_BrushBatchRenderer.m_renderList.m_Memory.m_nGrowSize = 0;
  g_BrushBatchRenderer.m_renderList.m_LastAlloc.index = -1;
  *(_DWORD *)&g_BrushBatchRenderer.m_renderList.m_Head = -1;
  *(_DWORD *)&g_BrushBatchRenderer.m_renderList.m_FirstFree = 0xFFFF;
  g_BrushBatchRenderer.m_renderList.m_NumAlloced = 0;
  g_BrushBatchRenderer.m_renderList.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_BrushBatchRenderer__);
}

//------------------------------------------------------------------------------
// Address: 0x103127B0
// Name: _dynamic_initializer_for__dynamic_tonemap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dynamic_tonemap__()
{
  ConVar::ConVar(this: &dynamic_tonemap, pName: "mat_dynamic_tonemapping", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__dynamic_tonemap__);
}

//------------------------------------------------------------------------------
// Address: 0x103127E0
// Name: _dynamic_initializer_for__building_cubemaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__building_cubemaps__()
{
  ConVar::ConVar(this: &building_cubemaps, pName: "building_cubemaps", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__building_cubemaps__);
}

//------------------------------------------------------------------------------
// Address: 0x10312810
// Name: _dynamic_initializer_for__reload_materials__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__reload_materials__()
{
  ConVar::ConVar(this: &reload_materials, pName: "reload_materials", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__reload_materials__);
}

//------------------------------------------------------------------------------
// Address: 0x10312D00
// Name: _dynamic_initializer_for__g_DemoOverlay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DemoOverlay__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DemoOverlay__);
}

//------------------------------------------------------------------------------
// Address: 0x10313280
// Name: _dynamic_initializer_for__er_colwidth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__er_colwidth__()
{
  ConVar::ConVar(this: &er_colwidth, pName: "er_colwidth", pDefaultValue: "100", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__er_colwidth__);
}

//------------------------------------------------------------------------------
// Address: 0x103132B0
// Name: _dynamic_initializer_for__er_maxname__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__er_maxname__()
{
  ConVar::ConVar(this: &er_maxname, pName: "er_maxname", pDefaultValue: "14", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__er_maxname__);
}

//------------------------------------------------------------------------------
// Address: 0x103132E0
// Name: _dynamic_initializer_for__er_graphwidthfrac__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__er_graphwidthfrac__()
{
  ConVar::ConVar(this: &er_graphwidthfrac, pName: "er_graphwidthfrac", pDefaultValue: "0.2", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__er_graphwidthfrac__);
}

//------------------------------------------------------------------------------
// Address: 0x10313310
// Name: _dynamic_initializer_for__g_EntityReportMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EntityReportMgr__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_EntityReportMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x103134D0
// Name: _dynamic_initializer_for__g_DLightLeafAccessors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFastPointLeafNum *dynamic_initializer_for__g_DLightLeafAccessors__()
{
  CFastPointLeafNum *v0; // esi
  int i; // edi
  CFastPointLeafNum *result; // eax

  v0 = g_DLightLeafAccessors;
  for ( i = 31; i >= 0; --i )
    result = CFastPointLeafNum::CFastPointLeafNum(this: v0++);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103134F0
// Name: _dynamic_initializer_for__g_ELightLeafAccessors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFastPointLeafNum *dynamic_initializer_for__g_ELightLeafAccessors__()
{
  CFastPointLeafNum *v0; // esi
  int i; // edi
  CFastPointLeafNum *result; // eax

  v0 = g_ELightLeafAccessors;
  for ( i = 63; i >= 0; --i )
    result = CFastPointLeafNum::CFastPointLeafNum(this: v0++);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10313510
// Name: _dynamic_initializer_for__jpeg_quality__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__jpeg_quality__()
{
  ConVar::ConVar(
    this: &jpeg_quality,
    pName: "jpeg_quality",
    pDefaultValue: "90",
    flags: 0,
    pHelpString: "jpeg screenshot quality.");
  return atexit(func: dynamic_atexit_destructor_for__jpeg_quality__);
}

//------------------------------------------------------------------------------
// Address: 0x10313670
// Name: _dynamic_initializer_for__screenshot_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__screenshot_command__()
{
  ConCommand::ConCommand(
    this: &screenshot_command,
    pName: "screenshot",
    callback: (void (__cdecl *)())screenshot,
    pHelpString: "Take a screenshot.",
    flags: 0x40000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__screenshot_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103136A0
// Name: _dynamic_initializer_for__devshots_screenshot_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__devshots_screenshot_command__()
{
  ConCommand::ConCommand(
    this: &devshots_screenshot_command,
    pName: "devshots_screenshot",
    callback: (void (__cdecl *)())devshots_screenshot,
    pHelpString: "Used by the -makedevshots system to take a screenshot. For taking your own screenshots, use the 'screenshot' command instead.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__devshots_screenshot_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103136D0
// Name: _dynamic_initializer_for__jpeg_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__jpeg_command__()
{
  ConCommand::ConCommand(
    this: &jpeg_command,
    pName: "jpeg",
    callback: (void (__cdecl *)())jpeg,
    pHelpString: "Take a jpeg screenshot:  jpeg <filename> <quality 1-100>.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__jpeg_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103138B0
// Name: _dynamic_initializer_for__startupmenu__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startupmenu__()
{
  ConCommand::ConCommand(
    this: &startupmenu,
    pName: "startupmenu",
    callback: (void (__cdecl *)())CColorBalanceUIPanel::Init,
    pHelpString: "Opens initial menu screen and loads the background bsp, but only if no other level is being loaded, and we're not in"
    " developer mode.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startupmenu__);
}

//------------------------------------------------------------------------------
// Address: 0x10313970
// Name: _dynamic_initializer_for__setinfo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__setinfo_command__()
{
  ConCommand::ConCommand(
    this: &setinfo_command,
    pName: "setinfo",
    callback: (void (__cdecl *)())setinfo,
    pHelpString: "Adds a new user info value",
    flags: 0x40000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__setinfo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313A30
// Name: _dynamic_initializer_for__g_RCONClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RCONClient__()
{
  CRConClient::CRConClient(this: &g_RCONClient);
  return atexit(func: dynamic_atexit_destructor_for__g_RCONClient__);
}

//------------------------------------------------------------------------------
// Address: 0x10313A50
// Name: _dynamic_initializer_for__g_RPTClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RPTClient__()
{
  CRConClient::CRConClient(this: &g_RPTClient);
  g_RPTClient.__vftable = (CRPTClient_vtbl *)&CRPTClient::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_RPTClient__);
}

//------------------------------------------------------------------------------
// Address: 0x10313EC0
// Name: _dynamic_initializer_for__asw_engine_finished_building_map_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__asw_engine_finished_building_map_command__()
{
  ConCommand::ConCommand(
    this: &asw_engine_finished_building_map_command,
    pName: "asw_engine_finished_building_map",
    callback: asw_engine_finished_building_map,
    pHelpString: "Notify engine that we've finished building a map",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__asw_engine_finished_building_map_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103221E0
// Name: _dynamic_atexit_destructor_for__password__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__password__()
{
  ConVar::~ConVar(this: &password);
}

//------------------------------------------------------------------------------
// Address: 0x10322210
// Name: _dynamic_atexit_destructor_for__g_BrushBatchRenderer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BrushBatchRenderer__()
{
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_BrushBatchRenderer.m_renderList);
  if ( g_BrushBatchRenderer.m_renderList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_BrushBatchRenderer.m_renderList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_BrushBatchRenderer.m_renderList.m_Memory.m_pMemory);
      g_BrushBatchRenderer.m_renderList.m_Memory.m_pMemory = nullptr;
    }
    g_BrushBatchRenderer.m_renderList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10322260
// Name: _dynamic_atexit_destructor_for__dynamic_tonemap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dynamic_tonemap__()
{
  ConVar::~ConVar(this: &dynamic_tonemap);
}

//------------------------------------------------------------------------------
// Address: 0x10322270
// Name: _dynamic_atexit_destructor_for__building_cubemaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__building_cubemaps__()
{
  ConVar::~ConVar(this: &building_cubemaps);
}

//------------------------------------------------------------------------------
// Address: 0x10322280
// Name: _dynamic_atexit_destructor_for__reload_materials__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__reload_materials__()
{
  ConVar::~ConVar(this: &reload_materials);
}

//------------------------------------------------------------------------------
// Address: 0x10322630
// Name: _dynamic_atexit_destructor_for__er_colwidth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__er_colwidth__()
{
  ConVar::~ConVar(this: &er_colwidth);
}

//------------------------------------------------------------------------------
// Address: 0x10322640
// Name: _dynamic_atexit_destructor_for__er_maxname__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__er_maxname__()
{
  ConVar::~ConVar(this: &er_maxname);
}

//------------------------------------------------------------------------------
// Address: 0x10322650
// Name: _dynamic_atexit_destructor_for__er_graphwidthfrac__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__er_graphwidthfrac__()
{
  ConVar::~ConVar(this: &er_graphwidthfrac);
}

//------------------------------------------------------------------------------
// Address: 0x10322660
// Name: _dynamic_atexit_destructor_for__g_EntityReportMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EntityReportMgr__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_EntityReportMgr);
}

//------------------------------------------------------------------------------
// Address: 0x10322730
// Name: _dynamic_atexit_destructor_for__jpeg_quality__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__jpeg_quality__()
{
  ConVar::~ConVar(this: &jpeg_quality);
}

//------------------------------------------------------------------------------
// Address: 0x103227A0
// Name: _dynamic_atexit_destructor_for__screenshot_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__screenshot_command__()
{
  ConCommand::~ConCommand(this: &screenshot_command);
}

//------------------------------------------------------------------------------
// Address: 0x103227B0
// Name: _dynamic_atexit_destructor_for__devshots_screenshot_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__devshots_screenshot_command__()
{
  ConCommand::~ConCommand(this: &devshots_screenshot_command);
}

//------------------------------------------------------------------------------
// Address: 0x103227C0
// Name: _dynamic_atexit_destructor_for__jpeg_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__jpeg_command__()
{
  ConCommand::~ConCommand(this: &jpeg_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322860
// Name: _dynamic_atexit_destructor_for__startupmenu__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startupmenu__()
{
  ConCommand::~ConCommand(this: &startupmenu);
}

//------------------------------------------------------------------------------
// Address: 0x103228A0
// Name: _dynamic_atexit_destructor_for__setinfo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__setinfo_command__()
{
  ConCommand::~ConCommand(this: &setinfo_command);
}

//------------------------------------------------------------------------------
// Address: 0x103228C0
// Name: _dynamic_atexit_destructor_for__g_SoundMessages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SoundMessages__()
{
  CUtlRBTree<SoundInfo_t,int,bool (__cdecl *)(SoundInfo_t const &,SoundInfo_t const &),CUtlMemory<UtlRBTreeNode_t<SoundInfo_t,int>,int>>::~CUtlRBTree<SoundInfo_t,int,bool (__cdecl *)(SoundInfo_t const &,SoundInfo_t const &),CUtlMemory<UtlRBTreeNode_t<SoundInfo_t,int>,int>>(this: &g_SoundMessages);
}

//------------------------------------------------------------------------------
// Address: 0x10322AA0
// Name: _dynamic_atexit_destructor_for__asw_engine_finished_building_map_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__asw_engine_finished_building_map_command__()
{
  ConCommand::~ConCommand(this: &asw_engine_finished_building_map_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324BF0
// Name: _dynamic_atexit_destructor_for__BindToggle_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__BindToggle_command__()
{
  ConCommand::~ConCommand(this: &BindToggle_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324C00
// Name: _dynamic_atexit_destructor_for__stuffcmds_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stuffcmds_command__()
{
  ConCommand::~ConCommand(this: &stuffcmds_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324C10
// Name: _dynamic_atexit_destructor_for__echo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__echo_command__()
{
  ConCommand::~ConCommand(this: &echo_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324C20
// Name: _dynamic_atexit_destructor_for__alias_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__alias_command__()
{
  ConCommand::~ConCommand(this: &alias_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324C30
// Name: _dynamic_atexit_destructor_for__cmd_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cmd_command__()
{
  ConCommand::~ConCommand(this: &cmd_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324C40
// Name: _dynamic_atexit_destructor_for__exec_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__exec_command__()
{
  ConCommand::~ConCommand(this: &exec_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324C50
// Name: _dynamic_atexit_destructor_for__execifexists_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__execifexists_command__()
{
  ConCommand::~ConCommand(this: &execifexists_command);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1005E5E0
// Name: public: virtual bool CLC_Move::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLC_Move::Process(SVC_ServerInfo *this)
{
  return this->m_pMessageHandler->ProcessServerInfo(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100875D0
// Name: void CL_HandlePureServerWhitelist(class CPureServerWhitelist __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CL_HandlePureServerWhitelist(int a1@<edi>, CPureServerWhitelist *pWhitelist)
{
  CClientState *BaseLocalClient; // eax
  CPureServerWhitelist::CForceMatchList *ForceMatchList; // edi
  CPureServerWhitelist::CAllowFromDiskList *AllowFromDiskList; // ebx
  IFileList *pFilesToReload; // [esp+0h] [ebp-4h] BYREF

  if ( GetBaseLocalClient()->m_pPureServerWhitelist != nullptr )
  {
    BaseLocalClient = GetBaseLocalClient();
    CPureServerWhitelist::Release(this: BaseLocalClient->m_pPureServerWhitelist);
  }
  ForceMatchList = nullptr;
  AllowFromDiskList = nullptr;
  GetBaseLocalClient()->m_pPureServerWhitelist = pWhitelist;
  if ( pWhitelist != nullptr )
  {
    ForceMatchList = CPureServerWhitelist::GetForceMatchList(this: pWhitelist);
    AllowFromDiskList = CPureServerWhitelist::GetAllowFromDiskList(this: pWhitelist);
  }
  ((void (__thiscall *)(IFileSystem *, CPureServerWhitelist::CForceMatchList *, CPureServerWhitelist::CAllowFromDiskList *, IFileList **, int))g_pFileSystem->RegisterFileWhitelist)(
    a1: g_pFileSystem,
    a2: ForceMatchList,
    a3: AllowFromDiskList,
    a4: &pFilesToReload,
    a5: a1);
  if ( pFilesToReload != nullptr )
  {
    materials->ReloadFilesInList(this: materials, a2: pFilesToReload);
    pFilesToReload->Release(this: pFilesToReload);
  }
  GetBaseLocalClient()->m_bCheckCRCsWithServer = ForceMatchList != nullptr && AllowFromDiskList != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10087690
// Name: void CL_PrintWhitelistInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_PrintWhitelistInfo()
{
  CClientState *BaseLocalClient; // eax
  CClientState *v1; // eax

  if ( GetBaseLocalClient()->m_pPureServerWhitelist != nullptr )
  {
    BaseLocalClient = GetBaseLocalClient();
    if ( CPureServerWhitelist::IsInFullyPureMode(this: BaseLocalClient->m_pPureServerWhitelist) )
    {
      _Msg(a1: "The server is using sv_pure = 2.\n");
    }
    else
    {
      _Msg(a1: "The server is using sv_pure = 1.\n");
      v1 = GetBaseLocalClient();
      CPureServerWhitelist::PrintWhitelistContents(this: v1->m_pPureServerWhitelist);
    }
  }
  else
  {
    _Msg(a1: "The server is using sv_pure = 0 (no whitelist).\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100876F0
// Name: struct CPrecacheUserData const __near * CL_GetPrecacheUserData(class INetworkStringTable __near *,int)
// Source: json
//------------------------------------------------------------------------------
const CPrecacheUserData *__cdecl CL_GetPrecacheUserData(INetworkStringTable *table, int index)
{
  int v2; // ebx
  INetworkStringTable *v3; // esi
  const CPrecacheUserData *result; // eax
  const CPrecacheUserData *v5; // edi
  int v6; // eax
  int v7; // [esp-8h] [ebp-14h]
  int v8; // [esp-4h] [ebp-10h]

  v2 = index;
  v3 = table;
  result = (const CPrecacheUserData *)table->GetStringUserData(this: table, a2: index, a3: &table);
  v5 = result;
  if ( result != nullptr )
  {
    if ( table != (INetworkStringTable *)1 )
    {
      v6 = ((int (__thiscall *)(INetworkStringTable *, int, INetworkStringTable *))v3->GetTableId)(
             a1: v3,
             a2: v2,
             a3: table);
      _Error(a1: "CL_GetPrecacheUserData(%d,%d) - length (%d) invalid.", v6, v7, v8);
    }
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10087740
// Name: void CL_InitHL2DemoFlag(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_InitHL2DemoFlag()
{
  const char *ModDirectory; // eax
  ISteamApps *m_pSteamApps; // edi
  ISteamApps_vtbl *v2; // esi
  int AppSteamAppId; // eax
  const char *v4; // eax
  int v5; // eax

  if ( !initialized )
  {
    if ( Steam3Client()->m_pSteamApps != nullptr )
    {
      ModDirectory = COM_GetModDirectory();
      if ( _V_stricmp(s1: ModDirectory, s2: "hl2") == 0 && g_pFileSystem->IsSteam(this: g_pFileSystem) )
      {
        initialized = true;
        m_pSteamApps = Steam3Client()->m_pSteamApps;
        v2 = m_pSteamApps->__vftable;
        AppSteamAppId = GetAppSteamAppId(eSourceApp: k_App_HL2);
        s_bIsHL2Demo = !v2->BIsSubscribedApp(this: m_pSteamApps, a2: AppSteamAppId);
      }
    }
    v4 = COM_GetModDirectory();
    if ( _V_stricmp(s1: v4, s2: "hl2") == 0 )
    {
      v5 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 12))(a1: v5, a2: "-demo", a3: 0) != 0 )
        s_bIsHL2Demo = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100877F0
// Name: bool CL_IsHL2Demo(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CL_IsHL2Demo()
{
  CL_InitHL2DemoFlag();
  return s_bIsHL2Demo;
}

//------------------------------------------------------------------------------
// Address: 0x10087800
// Name: void CL_InitPortalDemoFlag(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_InitPortalDemoFlag()
{
  const char *ModDirectory; // eax
  ISteamApps *m_pSteamApps; // edi
  ISteamApps_vtbl *v2; // esi
  int AppSteamAppId; // eax
  const char *v4; // eax
  int v5; // eax

  if ( !initialized_0 )
  {
    if ( Steam3Client()->m_pSteamApps != nullptr )
    {
      ModDirectory = COM_GetModDirectory();
      if ( _V_stricmp(s1: ModDirectory, s2: "portal") == 0 && g_pFileSystem->IsSteam(this: g_pFileSystem) )
      {
        initialized_0 = true;
        m_pSteamApps = Steam3Client()->m_pSteamApps;
        v2 = m_pSteamApps->__vftable;
        AppSteamAppId = GetAppSteamAppId(eSourceApp: k_App_PORTAL);
        s_bIsPortalDemo = !v2->BIsSubscribedApp(this: m_pSteamApps, a2: AppSteamAppId);
      }
    }
    v4 = COM_GetModDirectory();
    if ( _V_stricmp(s1: v4, s2: "portal") == 0 )
    {
      v5 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v5 + 12))(a1: v5, a2: "-demo", a3: 0) != 0 )
        s_bIsPortalDemo = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100878C0
// Name: bool CL_CheckCRCs(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CL_CheckCRCs(const char *pszMap)
{
  int v2; // edi
  char szDllName[96]; // [esp+0h] [ebp-6Ch] BYREF
  unsigned int clientDllCRC; // [esp+60h] [ebp-Ch] BYREF
  unsigned int mapCRC; // [esp+64h] [ebp-8h] BYREF
  void *fp; // [esp+68h] [ebp-4h] BYREF

  if ( GetBaseLocalClient()->serverCRC == 0 && GetBaseLocalClient()->serverClientSideDllCRC == 0 )
    return 1;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CL_CheckCRCs",
    a3: 0,
    a4: "Steam",
    a5: false,
    a6: 4);
  if ( sv.m_State >= ss_active )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  CRC32_Init(pulCRC: &mapCRC);
  if ( CRC_MapFile(crcvalue: &mapCRC, pszFileName: pszMap) )
  {
    if ( GetBaseLocalClient()->serverCRC == mapCRC || demoplayer->IsPlayingBack(this: demoplayer) )
    {
      V_snprintf(pDest: szDllName, maxLen: 96, pFormat: "bin\\client.dll");
      if ( CRC_File(crcvalue: &clientDllCRC, pszFileName: szDllName) || demoplayer->IsPlayingBack(this: demoplayer) )
      {
        if ( GetBaseLocalClient()->serverClientSideDllCRC != -1
          && GetBaseLocalClient()->serverClientSideDllCRC != clientDllCRC
          && !demoplayer->IsPlayingBack(this: demoplayer) )
        {
          _Warning(a1: "Your .dll [%s] differs from the server's.\n", szDllName);
        }
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        return 1;
      }
      else
      {
        COM_ExplainDisconnection(bPrint: true, fmt: "Couldn't CRC client side dll %s.\n", szDllName);
        Host_Error(error: "Disconnected");
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        return 0;
      }
    }
    else
    {
      COM_ExplainDisconnection(bPrint: true, fmt: "Your map [%s] differs from the server's.\n", pszMap);
      Host_Error(error: "Disconnected");
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return 0;
    }
  }
  else
  {
    fp = nullptr;
    v2 = COM_OpenFile(filename: pszMap, file: &fp);
    if ( fp != nullptr )
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: fp);
    if ( v2 == -1 )
      COM_ExplainDisconnection(bPrint: true, fmt: "Missing map %s, disconnecting\n", pszMap);
    else
      COM_ExplainDisconnection(bPrint: true, fmt: "Couldn't CRC map %s, disconnecting\n", pszMap);
    Host_Error(error: "Disconnected");
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087AB0
// Name: void CL_ReallocateDynamicData(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_ReallocateDynamicData()
{
  if ( entitylist != nullptr )
    entitylist->SetMaxEntities(this: entitylist, a2: 2048);
}

//------------------------------------------------------------------------------
// Address: 0x10087AF0
// Name: void CL_SetupMapName(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_SetupMapName(char *pName, char *pFixedName, int maxlen)
{
  unsigned int v3; // eax
  unsigned int v4; // esi
  unsigned int v5; // eax
  const char *v6; // esi
  _BYTE *v7; // eax

  strrchr(string: (unsigned __int8 *)pName, chr: 0x5Cu);
  v4 = v3;
  strrchr(string: (unsigned __int8 *)pName, chr: 0x2Fu);
  if ( v5 > v4 )
    v4 = v5;
  if ( v4 != 0 )
    v6 = (const char *)(v4 + 1);
  else
    v6 = pName;
  V_strncpy(pDest: pFixedName, pSrc: v6, maxLen: maxlen);
  strchr(string: pFixedName, chr: 0x2Eu);
  if ( v7 != nullptr )
    *v7 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10087B40
// Name: int CL_GetServerQueryPort(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CL_GetServerQueryPort@<eax>(int a1@<esi>)
{
  CClientState *BaseLocalClient; // eax
  int v3; // esi
  CClientState *v4; // eax
  int v5; // eax
  int dataLen; // [esp+0h] [ebp-4h] BYREF

  if ( GetBaseLocalClient()->m_pServerStartupTable == nullptr )
    return 0;
  BaseLocalClient = GetBaseLocalClient();
  v3 = ((int (__thiscall *)(INetworkStringTable *, const char *, int))BaseLocalClient->m_pServerStartupTable->FindStringIndex)(
         a1: BaseLocalClient->m_pServerStartupTable,
         a2: "QueryPort",
         a3: a1);
  if ( v3 != 0xFFFF
    && (v4 = GetBaseLocalClient(),
        (v5 = (int)v4->m_pServerStartupTable->GetStringUserData(this: v4->m_pServerStartupTable, a2: v3, a3: &dataLen)) != 0)
    && dataLen == 4 )
  {
    return *(_DWORD *)v5;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087BB0
// Name: void CL_RegisterResources(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_RegisterResources()
{
  CClientState *BaseLocalClient; // eax
  model_t *Model; // eax

  BaseLocalClient = GetBaseLocalClient();
  Model = CClientState::GetModel(this: BaseLocalClient, index: 1);
  CCommonHostState::SetWorldModel(this: &host_state, pModel: Model);
  if ( host_state.worldmodel == nullptr )
    Host_Error(error: "CL_RegisterResources:  host_state.worldmodel/GetBaseLocalClient().GetModel( 1 )==NULL\n");
  videomode->InvalidateWindow(this: videomode);
}

//------------------------------------------------------------------------------
// Address: 0x10087BF0
// Name: void CL_NextDemo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_NextDemo()
{
  int demonum; // esi
  int v1; // esi
  int v2; // esi
  CClientState *BaseLocalClient; // eax
  vgui::CTreeViewListControl *v4; // ecx
  ECommandTarget_t TraceType; // eax
  CClientState *v6; // eax
  char str[1024]; // [esp+0h] [ebp-400h] BYREF

  if ( GetBaseLocalClient()->demonum != -1 )
  {
    SCR_BeginLoadingPlaque(levelName: nullptr);
    demonum = GetBaseLocalClient()->demonum;
    if ( GetBaseLocalClient()->demos[demonum][0] != 0 && GetBaseLocalClient()->demonum != 32
      || (GetBaseLocalClient()->demonum = 0, v1 = GetBaseLocalClient()->demonum, GetBaseLocalClient()->demos[v1][0] != 0) )
    {
      v2 = GetBaseLocalClient()->demonum;
      BaseLocalClient = GetBaseLocalClient();
      V_snprintf(pDest: str, maxLen: 1024, pFormat: "playdemo %s", BaseLocalClient->demos[v2]);
      TraceType = CTraceFilter::GetTraceType(this: v4);
      Cbuf_AddText(eTarget: TraceType, pText: str, nTickDelay: 0);
      v6 = GetBaseLocalClient();
      ++v6->demonum;
    }
    else
    {
      scr_disabled_for_loading = false;
      ConMsg(a1: "No demos listed with startdemos\n");
      GetBaseLocalClient()->demonum = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087D00
// Name: void CL_HudMessage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_HudMessage(const char *pMessage)
{
  if ( g_ClientDLL != nullptr )
    g_ClientDLL->HudText(this: g_ClientDLL, a2: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x10087D20
// Name: cl_showents
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_showents()
{
  int i; // esi
  int v1; // eax
  int v2; // eax
  char entStr[256]; // [esp+4h] [ebp-200h] BYREF
  char classStr[256]; // [esp+104h] [ebp-100h] BYREF

  for ( i = 0; i < entitylist->GetMaxEntities(this: entitylist); ++i )
  {
    v1 = entitylist->GetClientNetworkable(this: entitylist, a2: i);
    if ( v1 != 0 )
    {
      entStr[0] = 0;
      v2 = (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 8))(a1: v1);
      V_snprintf(pDest: classStr, maxLen: 256, pFormat: "'%s'", *(const char **)(v2 + 8));
      ConMsg(a1: "Ent %3d: %s class %s\n", i, entStr, classStr);
    }
    else
    {
      V_snprintf(pDest: entStr, maxLen: 256, pFormat: "(missing), ");
      V_snprintf(pDest: classStr, maxLen: 256, pFormat: "(missing)");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087DF0
// Name: void CL_GetStartupImage(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_GetStartupImage(char *pOutBuffer, int nOutBufferSize)
{
  bool v2; // zf
  const char *v3; // eax

  v2 = !materials->GetAspectRatioInfo(this: materials)->m_bIsWidescreen;
  v3 = "_widescreen";
  if ( v2 )
    v3 = defaultValue;
  V_snprintf(pDest: pOutBuffer, maxLen: nOutBufferSize, pFormat: "console/background01%s", v3);
}

//------------------------------------------------------------------------------
// Address: 0x10087E30
// Name: void CL_DemoTransitionFromTrainstation(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl CL_DemoTransitionFromTrainstation()
{
  vgui::CTreeViewListControl *v0; // ecx
  ECommandTarget_t TraceType; // eax
  int v2; // ecx
  double v3; // st7

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&sv_unlockedchapters.IConVar, value: 6);
  TraceType = CTraceFilter::GetTraceType(this: v0);
  Cbuf_AddText(eTarget: TraceType, pText: "sv_cheats 1; fadeout 1.5; sv_cheats 0;", nTickDelay: 0);
  Cbuf_Execute();
  v3 = _Plat_FloatTime(a1: v2);
  s_bIsRavenHolmn = false;
  s_fDemoRevealGameUITime = v3 + 1.5;
}

//------------------------------------------------------------------------------
// Address: 0x10087E70
// Name: void CL_DemoTransitionFromRavenholm(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CL_DemoTransitionFromRavenholm(vgui::CTreeViewListControl *this)
{
  ECommandTarget_t TraceType; // eax
  int v2; // ecx
  double v3; // st7

  TraceType = CTraceFilter::GetTraceType(this);
  Cbuf_AddText(eTarget: TraceType, pText: "sv_cheats 1; fadeout 2; sv_cheats 0;", nTickDelay: 0);
  Cbuf_Execute();
  v3 = _Plat_FloatTime(a1: v2);
  s_bIsRavenHolmn = true;
  s_fDemoRevealGameUITime = v3 + 1.9;
}

//------------------------------------------------------------------------------
// Address: 0x10087EB0
// Name: void CL_DemoTransitionFromTestChmb(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CL_DemoTransitionFromTestChmb(vgui::CTreeViewListControl *this)
{
  ECommandTarget_t TraceType; // eax
  int v2; // ecx

  TraceType = CTraceFilter::GetTraceType(this);
  Cbuf_AddText(eTarget: TraceType, pText: "sv_cheats 1; fadeout 2; sv_cheats 0;", nTickDelay: 0);
  Cbuf_Execute();
  s_fDemoRevealGameUITime = _Plat_FloatTime(a1: v2) + 1.9;
}

//------------------------------------------------------------------------------
// Address: 0x10087EE0
// Name: void CL_SetPagedPoolInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_SetPagedPoolInfo()
{
  _Plat_GetPagedPoolInfo(a1: &g_pagedpoolinfo);
}

//------------------------------------------------------------------------------
// Address: 0x10087EF0
// Name: cl_fullupdate
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_fullupdate()
{
  CClientState *LocalClient; // eax

  LocalClient = GetLocalClient(nSlot: -1);
  CBaseClientState::ForceFullUpdate(this: LocalClient, pchReason: "cl_fullupdate command");
}

//------------------------------------------------------------------------------
// Address: 0x10087F10
// Name: void Callback_ModelChanged(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Callback_ModelChanged(void *object, INetworkStringTable *stringTable, int stringNumber)
{
  CClientState *BaseLocalClient; // eax

  if ( stringTable == GetBaseLocalClient()->m_pModelPrecacheTable && stringNumber >= 1 )
  {
    BaseLocalClient = GetBaseLocalClient();
    CClientState::SetModel(this: BaseLocalClient, tableIndex: stringNumber);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087F40
// Name: void Callback_GenericChanged(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Callback_GenericChanged(void *object, INetworkStringTable *stringTable, int stringNumber)
{
  CClientState *BaseLocalClient; // eax

  if ( stringTable == GetBaseLocalClient()->m_pGenericPrecacheTable && stringNumber >= 1 )
  {
    BaseLocalClient = GetBaseLocalClient();
    CClientState::SetGeneric(this: BaseLocalClient, tableIndex: stringNumber);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087F70
// Name: void Callback_SoundChanged(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Callback_SoundChanged(void *object, INetworkStringTable *stringTable, int stringNumber)
{
  CClientState *BaseLocalClient; // eax

  if ( stringTable == GetBaseLocalClient()->m_pSoundPrecacheTable && stringNumber >= 1 )
  {
    BaseLocalClient = GetBaseLocalClient();
    CClientState::SetSound(this: BaseLocalClient, tableIndex: stringNumber);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087FA0
// Name: void Callback_DecalChanged(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Callback_DecalChanged(void *object, INetworkStringTable *stringTable, int stringNumber)
{
  CClientState *BaseLocalClient; // eax

  if ( stringTable == GetBaseLocalClient()->m_pDecalPrecacheTable )
  {
    BaseLocalClient = GetBaseLocalClient();
    CClientState::SetDecal(this: BaseLocalClient, tableIndex: stringNumber);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087FD0
// Name: void Callback_UserInfoChanged(void __near *,class INetworkStringTable __near *,int,char const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Callback_UserInfoChanged(
        void *object,
        INetworkStringTable *stringTable,
        int stringNumber,
        const char *newString,
        _DWORD *newData)
{
  unsigned int *v5; // esi
  int i; // ebx
  CClientState *BaseLocalClient; // eax
  IGameEvent *v8; // esi
  unsigned int v9; // [esp-Ch] [ebp-10h]

  if ( newData != nullptr )
  {
    v5 = newData + 30;
    for ( i = 4; i != 0; --i )
    {
      v9 = *v5;
      BaseLocalClient = GetBaseLocalClient();
      CClientState::CheckOthersCustomFile(this: BaseLocalClient, crcValue: v9);
      ++v5;
    }
    v8 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "player_info", a3: 0, a4: 0);
    if ( v8 != nullptr )
    {
      v8->SetInt(this: v8, a2: "userid", a3: newData[10]);
      v8->SetInt(this: v8, a2: "friendsid", a3: newData[20]);
      ((void (__thiscall *)(IGameEvent *, const char *, _DWORD, _DWORD))v8->SetUint64)(
        a1: v8,
        a2: "xuid",
        a3: *newData,
        a4: newData[1]);
      v8->SetInt(this: v8, a2: "index", a3: stringNumber);
      v8->SetString(this: v8, a2: "name", a3: (const char *)newData + 8);
      v8->SetString(this: v8, a2: "networkid", a3: (const char *)newData + 44);
      v8->SetBool(this: v8, a2: "bot", a3: *((_BYTE *)newData + 116));
      g_GameEventManager->FireEventClientSide(this: g_GameEventManager, a2: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100880C0
// Name: void CL_InstallAndInvokeClientStringTableCallbacks(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_InstallAndInvokeClientStringTableCallbacks()
{
  CClientState *BaseLocalClient; // eax
  int v1; // esi
  CClientState *v2; // eax
  CVTFTexture *v3; // eax
  CVTFTexture *v4; // esi
  CClientState *v5; // ebx
  CClientState_vtbl *v6; // edi
  int v7; // eax
  void (__cdecl *Callback)(void *, INetworkStringTable *, int, const char *, const void *); // eax
  void (__cdecl *v9)(void *, INetworkStringTable *, int, const char *, const void *); // ebx
  const char *v10; // eax
  int v11; // edi
  IEngineVGuiInternal *v12; // eax
  int v13; // eax
  int v14; // eax
  const char *v15; // eax
  int v16; // [esp-Ch] [ebp-20h]
  int userDataSize; // [esp+4h] [ebp-10h] BYREF
  int numTables; // [esp+8h] [ebp-Ch]
  void (__cdecl *pOldFunction)(void *, INetworkStringTable *, int, const char *, const void *); // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CL_InstallAndInvokeClientStringTableCallbacks",
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 4);
  BaseLocalClient = GetBaseLocalClient();
  v1 = 0;
  numTables = BaseLocalClient->m_StringTableContainer->GetNumTables(this: BaseLocalClient->m_StringTableContainer);
  i = 0;
  if ( numTables > 0 )
  {
    do
    {
      v2 = GetBaseLocalClient();
      v3 = (CVTFTexture *)v2->m_StringTableContainer->GetTable(this: v2->m_StringTableContainer, a2: v1);
      v4 = v3;
      if ( v3 != nullptr )
      {
        pOldFunction = (void (__cdecl *)(void *, INetworkStringTable *, int, const char *, const void *))CNetworkStringTable::GetCallback(this: v3);
        v5 = GetBaseLocalClient();
        v6 = v5->CBaseClientState::INetChannelHandler::__vftable;
        v7 = ((int (__thiscall *)(CVTFTexture *))v4->Init)(a1: v4);
        v6->InstallStringTableCallback(this: v5, a2: (const char *)v7);
        Callback = (void (__cdecl *)(void *, INetworkStringTable *, int, const char *, const void *))CNetworkStringTable::GetCallback(this: v4);
        v9 = Callback;
        if ( Callback != nullptr && Callback != pOldFunction )
        {
          v10 = (const char *)((int (__thiscall *)(CVTFTexture *))v4->Init)(a1: v4);
          _COM_TimestampedLog(a1: "String Table Callbacks %s - Start", v10);
          v11 = 0;
          if ( ((int (__thiscall *)(CVTFTexture *))v4->SetReflectivity)(a1: v4) > 0 )
          {
            do
            {
              if ( v11 % 25 == 0 )
              {
                v12 = EngineVGui();
                v12->UpdateProgressBar(this: v12, a2: PROGRESS_DEFAULT, a3: true);
              }
              v13 = ((int (__thiscall *)(CVTFTexture *, int, int *))v4->LowResFileInfo)(
                      a1: v4,
                      a2: v11,
                      a3: &userDataSize);
              v14 = ((int (__thiscall *)(CVTFTexture *, int, int))v4->Unserialize)(a1: v4, a2: v11, a3: v13);
              ((void (__cdecl *)(_DWORD, CVTFTexture *, int, int))v9)(a1: 0, a2: v4, a3: v11++, a4: v14);
            }
            while ( v11 < ((int (__thiscall *)(CVTFTexture *, int))v4->SetReflectivity)(a1: v4, a2: v16) );
          }
          v15 = (const char *)((int (__thiscall *)(CVTFTexture *))v4->Init)(a1: v4);
          _COM_TimestampedLog(a1: "String Table Callbacks %s - Finish", v15);
        }
      }
      v1 = i + 1;
      i = v1;
    }
    while ( v1 < numTables );
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10088230
// Name: double clamp<double,float,float>(double const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl clamp<double,float,float>(const long double *val, const float *minVal, const float *maxVal)
{
  long double result; // st7

  result = *minVal;
  if ( result <= *(double *)val )
  {
    result = *maxVal;
    if ( *(double *)val <= result )
      return *(double *)val;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10088260
// Name: void CL_CheckClientState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CL_CheckClientState(void *this)
{
  CClientState *BaseLocalClient; // eax
  bool useBackdoora; // [esp+0h] [ebp-4h]

  if ( cl_LocalNetworkBackdoor.m_pParent == nullptr
    || cl_LocalNetworkBackdoor.m_pParent->m_Value.m_nValue == 0
    || GetBaseLocalClient()->m_NetChannel == nullptr
    || (BaseLocalClient = GetBaseLocalClient(),
        ((unsigned __int8 (__thiscall *)(INetChannel *, void *))BaseLocalClient->m_NetChannel->IsLoopback)(
          a1: BaseLocalClient->m_NetChannel,
          a2: this) == 0)
    || sv.m_State < ss_active
    || demorecorder->IsRecording(this: demorecorder)
    || demoplayer->IsPlayingBack(this: demoplayer)
    || (useBackdoora = true, !Host_IsSinglePlayerGame()) )
  {
    useBackdoora = false;
  }
  CL_SetupLocalNetworkBackDoor(bUseBackDoor: useBackdoora);
}

//------------------------------------------------------------------------------
// Address: 0x100882E0
// Name: void CL_ClearState(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CL_ClearState(int a1@<edi>)
{
  void *v1; // ecx
  IStaticPropMgrEngine *v2; // eax
  char *v3; // eax
  CFastPointLeafNum *v4; // esi
  CFastPointLeafNum *v5; // esi
  CClientState *BaseLocalClient; // eax
  model_t *Model; // eax
  CClientState *v8; // eax
  char *worldmodel; // [esp-Ch] [ebp-110h]
  char mapname[256]; // [esp+4h] [ebp-100h] BYREF

  CL_HandlePureServerWhitelist(a1, pWhitelist: nullptr);
  CL_TextureListPanel_ClearState(ecx0: v1);
  CL_ResetEntityBits();
  R_UnloadSkys();
  Decal_Init();
  v2 = StaticPropMgr();
  v2->LevelShutdownClient(this: v2);
  if ( g_ClientDLL != nullptr )
  {
    if ( host_state.worldmodel != nullptr )
    {
      worldmodel = (char *)host_state.worldmodel;
      v3 = (char *)((int (__thiscall *)(IModelLoader *))modelloader->GetName)(a1: modelloader);
      CL_SetupMapName(pName: v3, pFixedName: worldmodel, maxlen: (int)mapname);
      ((void (__thiscall *)(IPhoneHome *, int, char *, int))phonehome->Message)(
        a1: phonehome,
        a2: 4,
        a3: mapname,
        a4: 256);
    }
    audiosourcecache->LevelShutdown(this: audiosourcecache);
    g_ClientDLL->LevelShutdown(this: g_ClientDLL);
  }
  R_LevelShutdown();
  if ( g_pLocalNetworkBackdoor != nullptr )
    CLocalNetworkBackdoor::ClearState(this: g_pLocalNetworkBackdoor);
  memset(dst: (unsigned __int8 *)cl_dlights, value: 0, count: sizeof(cl_dlights));
  memset(dst: (unsigned __int8 *)cl_elights, value: 0, count: sizeof(cl_elights));
  g_bActiveDlights = false;
  g_bActiveElights = false;
  r_dlightchanged = 0;
  r_dlightactive = 0;
  v4 = g_DLightLeafAccessors;
  do
    CFastPointLeafNum::Reset(this: v4++);
  while ( (int)v4 < (int)g_ELightLeafAccessors );
  v5 = g_ELightLeafAccessors;
  do
    CFastPointLeafNum::Reset(this: v5++);
  while ( (int)v5 < (int)&jpeg_quality );
  g_bClearingClientState = true;
  BaseLocalClient = GetBaseLocalClient();
  Model = CClientState::GetModel(this: BaseLocalClient, index: 1);
  if ( Model != nullptr && host_state.worldmodel == nullptr )
    CCommonHostState::SetWorldModel(this: &host_state, pModel: Model);
  g_bClearingClientState = false;
  Host_FreeStateAndWorld(server: false);
  Host_FreeToLowMark(server: false);
  v8 = GetBaseLocalClient();
  v8->Clear(this: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10088450
// Name: void CL_SndShow(char const __near *,struct SoundInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_SndShow(const char *pName, const SoundInfo_t *pSound)
{
  CClientState *BaseLocalClient; // eax
  double Time; // [esp+8h] [ebp-2Ch]
  double fDelay; // [esp+10h] [ebp-24h]
  double x; // [esp+18h] [ebp-1Ch]
  double y; // [esp+20h] [ebp-14h]
  double z; // [esp+28h] [ebp-Ch]

  if ( snd_show.m_pParent != nullptr && snd_show.m_pParent->m_Value.m_nValue >= 2 )
  {
    z = pSound->vOrigin.z;
    y = pSound->vOrigin.y;
    x = pSound->vOrigin.x;
    fDelay = pSound->fDelay;
    BaseLocalClient = GetBaseLocalClient();
    Time = CClientState::GetTime(this: BaseLocalClient);
    DevMsg(
      a1: "%i (seq %i) %s : src %d : ch %d : %d dB : vol %.2f : time %.3f (%.4f delay) @%.1f %.1f %.1f\n",
      host_framecount,
      pSound->nSequenceNumber,
      pName,
      pSound->nEntityIndex,
      pSound->nChannel,
      pSound->Soundlevel,
      pSound->fVolume,
      Time,
      fDelay,
      x,
      y,
      z);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100884D0
// Name: void CL_DispatchSound(struct SoundInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_DispatchSound(const SoundInfo_t *sound)
{
  char v1; // cl
  bool v2; // zf
  CClientState *BaseLocalClient; // eax
  int nChannel; // edi
  char v5; // cl
  unsigned int nFlags; // edi
  float x; // xmm0_4
  soundlevel_t Soundlevel; // edx
  float fVolume; // xmm0_4
  int nSpeakerEntity; // edx
  float fDelay; // xmm0_4
  int nSoundNum; // ecx
  char *v13; // eax
  CDummySfx *v14; // edi
  CClientState *v15; // eax
  CSfxTable *v16; // eax
  CClientState *v17; // eax
  const char *SoundName; // eax
  int soundtime; // [esp+0h] [ebp-D8h]
  int nRandomSeed; // [esp+4h] [ebp-D4h]
  int v21; // [esp+4h] [ebp-D4h]
  char name[96]; // [esp+14h] [ebp-C4h] BYREF
  StartSoundParams_t params; // [esp+74h] [ebp-64h] BYREF

  v1 = *((_BYTE *)&params + 96) & 0xC0 | 2;
  v2 = (sound->nFlags & 0x10) == 0;
  params.fvol = 1.0;
  memset(&params, 0, 40);
  params.soundlevel = SNDLVL_NORM;
  params.flags = 0;
  params.pitch = 100;
  params.delay = 0.0;
  params.speakerentity = -1;
  params.initialStreamPosition = 0;
  params.skipInitialSamples = 0;
  params.m_nQueuedGUID = -1;
  params.m_nSoundScriptHandle = -1;
  memset(&params.m_pSoundEntryName, 0, 16);
  *((_BYTE *)&params + 96) = v1;
  if ( !v2 && fabs(sound->fDelay) < 0.1 )
  {
    BaseLocalClient = GetBaseLocalClient();
    S_ComputeDelayForSoundtime(
      soundtime: (float)(BaseLocalClient->m_flLastServerTickTime + sound->fDelay)
    - (float)((float)(g_ClientGlobalVariables.simTicksThisFrame - 1) * host_state.interval_per_tick),
      syncIndex: CLOCK_SYNC_SERVER);
    v1 = *((_BYTE *)&params + 96);
  }
  nChannel = sound->nChannel;
  v5 = (v1 ^ (nChannel == 6)) & 1 ^ v1;
  params.soundsource = sound->nEntityIndex;
  params.entchannel = 6;
  if ( (v5 & 1) == 0 )
    params.entchannel = nChannel;
  nFlags = sound->nFlags;
  x = sound->vOrigin.x;
  Soundlevel = sound->Soundlevel;
  params.pitch = sound->nPitch;
  params.origin.x = x;
  params.origin.y = sound->vOrigin.y;
  params.origin.z = sound->vOrigin.z;
  fVolume = sound->fVolume;
  params.soundlevel = Soundlevel;
  nSpeakerEntity = sound->nSpeakerEntity;
  params.fvol = fVolume;
  fDelay = sound->fDelay;
  params.flags = nFlags;
  params.delay = fDelay;
  params.speakerentity = nSpeakerEntity;
  *((_BYTE *)&params + 96) = ((v5 | 4) ^ (16 * (nFlags >> 10))) & 0x10 ^ (v5 | 4);
  if ( (*((_BYTE *)&params + 96) & 0x10) != 0 )
  {
    nRandomSeed = sound->nRandomSeed;
    params.m_nSoundScriptHandle = sound->nSoundNum;
    S_StartSoundEntry(a1: 0, a2: nFlags, a3: (int)sound, pStartParams: &params, nSeed: nRandomSeed);
  }
  else
  {
    nSoundNum = sound->nSoundNum;
    name[0] = 0;
    v21 = nSoundNum;
    if ( sound->bIsSentence )
    {
      v13 = VOX_SentenceNameFromIndex(sentencenum: nSoundNum);
      if ( v13 == nullptr )
        v13 = (char *)defaultValue;
      V_snprintf(pDest: name, maxLen: 96, pFormat: "%c%s", 33, v13);
      v14 = S_DummySfx(name);
    }
    else
    {
      v15 = GetBaseLocalClient();
      v16 = CClientState::GetSound(this: v15, index: v21);
      v14 = (CDummySfx *)v16;
      if ( v16 != nullptr && (*((_BYTE *)v16 + 12) & 4) != 0 )
        DevMsg(a1: "    Entity '%d' created the late load.\n", sound->nEntityIndex);
      soundtime = sound->nSoundNum;
      v17 = GetBaseLocalClient();
      SoundName = CClientState::GetSoundName(this: v17, index: soundtime);
      V_strncpy(pDest: name, pSrc: SoundName, maxLen: 96);
    }
    params.pSfx = v14;
    CL_SndShow(pName: name, pSound: sound);
    if ( (*((_BYTE *)&params + 96) & 1) != 0 )
    {
      S_StartSound(&params);
    }
    else if ( !demoplayer->IsSkipping(this: demoplayer) || (sound->nFlags & 4) != 0 )
    {
      S_StartSound(&params);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088750
// Name: void CL_FullyConnected(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_FullyConnected()
{
  IEngineVGuiInternal *v0; // eax
  IStaticPropMgrEngine *v1; // eax
  CClientState *BaseLocalClient; // eax
  vgui::Tooltip *v3; // eax
  char *v4; // edi
  CClientState *v5; // eax
  netadr_s *v6; // eax
  unsigned __int16 Port; // ax
  int v8; // esi
  int ServerQueryPort; // ebx
  IEngineVGuiInternal *v10; // eax
  IEngineVGuiInternal *v11; // eax
  CClientState *v12; // esi
  CClientState *v13; // eax
  ConVar *m_NetChannel; // ecx
  INetChannel *v15; // edi
  bool (__thiscall *ClampValue)(ConVar *, float *); // edx
  ConVar *v17; // esi
  int v18; // eax
  char *v19; // eax
  float value; // xmm0_4
  char *v21; // eax
  const char *v22; // eax
  vgui::PropertyPage *v23; // ecx
  int v24; // eax
  vgui::CTreeViewListControl *v25; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v27; // [esp+38h] [ebp-24h]
  int v28; // [esp+40h] [ebp-1Ch]
  const char *v29; // [esp+40h] [ebp-1Ch]
  int v30; // [esp+44h] [ebp-18h]
  ConVarRef mat_queue_mode; // [esp+54h] [ebp-8h] BYREF

  v0 = EngineVGui();
  v0->UpdateProgressBar(this: v0, a2: PROGRESS_FULLYCONNECTED, a3: true);
  v1 = StaticPropMgr();
  v1->LevelInitClient(this: v1);
  modelloader->PurgeUnusedModels(this: modelloader);
  g_pMDLCache->ShutdownPreloadData(this: g_pMDLCache);
  g_ClientDLL->LevelInitPostEntity(this: g_ClientDLL);
  BaseLocalClient = GetBaseLocalClient();
  v3 = (vgui::Tooltip *)BaseLocalClient->m_NetChannel->GetRemoteAddress(this: BaseLocalClient->m_NetChannel);
  v4 = CWaveDataStreamAsync::Source(this: v3);
  v5 = GetBaseLocalClient();
  v6 = (netadr_s *)v5->m_NetChannel->GetRemoteAddress(this: v5->m_NetChannel);
  Port = netadr_s::GetPort(this: v6);
  v8 = Port;
  if ( Port == 0 )
  {
    v4 = CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)&net_local_adr);
    v8 = netadr_s::GetPort(this: &net_local_adr);
  }
  ServerQueryPort = CL_GetServerQueryPort(a1: v8);
  v10 = EngineVGui();
  v10->NotifyOfServerConnect(this: v10, a2: com_gamedir, a3: (int)v4, a4: (__int16)v8, a5: ServerQueryPort);
  CTestScriptMgr::CheckPoint(this: &g_TestScriptMgr, pName: "FinishedMapLoad");
  v11 = EngineVGui();
  v11->UpdateProgressBar(this: v11, a2: PROGRESS_READYTOPLAY, a3: true);
  CM_DiscardEntityString();
  g_pMDLCache->EndMapLoad(this: g_pMDLCache);
  if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue > 0 )
  {
    v12 = GetBaseLocalClient();
    v13 = GetBaseLocalClient();
    m_NetChannel = (ConVar *)v12->m_NetChannel;
    v15 = v13->m_NetChannel;
    ClampValue = m_NetChannel->ClampValue;
    mat_queue_mode.m_pConVarState = m_NetChannel;
    v17 = m_NetChannel;
    v28 = ((int (__cdecl *)(_DWORD))ClampValue)(a1: 0);
    v18 = ((int (__thiscall *)(ConVar *))mat_queue_mode.m_pConVarState->InternalSetColorValue)(a1: mat_queue_mode.m_pConVarState);
    v19 = V_pretifymem(value: (float)v18, digitsafterdecimal: 0, usebinaryonek: 3);
    v29 = (const char *)((int (__thiscall *)(ConVar *, int, char *, _DWORD, int))v17->ClampValue)(
                          a1: v17,
                          a2: 1,
                          a3: v19,
                          a4: 0,
                          a5: v28);
    value = (float)((int (__thiscall *)(ConVar *))v17->InternalSetColorValue)(a1: v17);
    v21 = V_pretifymem(value, digitsafterdecimal: 1, usebinaryonek: 3);
    v22 = (const char *)((int (__thiscall *)(INetChannel *, char *))v15->GetName)(a1: v15, a2: v21);
    _ConDMsg(a1: "Signon traffic \"%s\":  incoming %s [%d pkts], outgoing %s [%d pkts]\n", v22, v27, 0, v29, v30);
  }
  SCR_EndLoadingPlaque();
  CColorBalanceUIPanel::Init(this: v23);
  if ( !engineClient->IsLevelMainMenuBackground(this: engineClient) )
  {
    ConVarRef::ConVarRef(this: &mat_queue_mode, pName: "mat_queue_mode");
    if ( mat_queue_mode.m_pConVarState->m_Value.m_nValue != 0 )
      Host_AllowQueuedMaterialSystem(bAllow: true);
  }
  if ( GetBaseLocalClient()->m_nMaxClients == 1 && !demoplayer->IsPlayingBack(this: demoplayer) )
    scr_nextdrawtick = host_tickcount + (int)(float)((float)(0.25 / host_state.interval_per_tick) + 0.5);
  _g_pMemAlloc->CompactHeap(this: _g_pMemAlloc);
  _COM_TimestampedLog(a1: "Sound Loading time %.4f", (double)g_flAccumulatedSoundLoadTime);
  _COM_TimestampedLog(a1: "Model Loading time %.4f", (double)g_flAccumulatedModelLoadTime);
  _COM_TimestampedLog(a1: "  Model Loading time studio %.4f", (double)g_flAccumulatedModelLoadTimeStudio);
  _COM_TimestampedLog(
    a1: "    Model Loading time GetVCollide %.4f -sync",
    (double)g_flAccumulatedModelLoadTimeVCollideSync);
  _COM_TimestampedLog(
    a1: "    Model Loading time GetVCollide %.4f -async",
    (double)g_flAccumulatedModelLoadTimeVCollideAsync);
  _COM_TimestampedLog(
    a1: "    Model Loading time GetVirtualModel %.4f",
    (double)g_flAccumulatedModelLoadTimeVirtualModel);
  _COM_TimestampedLog(
    a1: "    Model loading time Mod_GetModelMaterials only %.4f",
    (double)g_flAccumulatedModelLoadTimeMaterialNamesOnly);
  _COM_TimestampedLog(a1: "  Model Loading time world %.4f", (double)g_flAccumulatedModelLoadTimeBrush);
  _COM_TimestampedLog(a1: "  Model Loading time sprites %.4f", (double)g_flAccumulatedModelLoadTimeSprite);
  _COM_TimestampedLog(a1: "  Model Loading time meshes %.4f", (double)g_flAccumulatedModelLoadTimeStaticMesh);
  _COM_TimestampedLog(a1: "*** Map Load Complete");
  v24 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v24 + 40))(a1: v24, a2: "-profilemapload") != 0 )
  {
    TraceType = CTraceFilter::GetTraceType(this: v25);
    Cbuf_AddText(eTarget: TraceType, pText: "quit\n", nTickDelay: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088A90
// Name: void CL_TakeScreenshot(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_TakeScreenshot(const char *name)
{
  char *m_pszString; // eax
  char *v2; // eax

  cl_takesnapshot = true;
  cl_snapshot_fullpathname[0] = 0;
  cl_takejpeg = false;
  if ( name != nullptr )
  {
    V_strncpy(pDest: cl_snapshotname, pSrc: name, maxLen: 260);
    cl_snapshot_subdirname[0] = 0;
  }
  else
  {
    cl_snapshotname[0] = 0;
    if ( (cl_screenshotname.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = cl_screenshotname.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    if ( _V_strlen(str: m_pszString) > 0 )
    {
      if ( (cl_screenshotname.m_nFlags & 0x1000) != 0 )
      {
        v2 = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        v2 = cl_screenshotname.m_pParent->m_Value.m_pszString;
        if ( v2 == nullptr )
          v2 = (char *)defaultValue;
      }
      V_snprintf(pDest: cl_snapshotname, maxLen: 260, pFormat: "%s", v2);
    }
    cl_snapshot_subdirname[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088B50
// Name: devshots_screenshot
// Source: json
//------------------------------------------------------------------------------
void __cdecl devshots_screenshot(const CCommand *args)
{
  CL_TakeScreenshot(name: nullptr);
  if ( args->m_nArgc == 2 )
  {
    V_strncpy(pDest: cl_snapshot_subdirname, pSrc: args->m_ppArgv[1], maxLen: 260);
    cl_snapshotnum = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088B90
// Name: void CL_StartMovie(char const __near *,int,int,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_StartMovie(
        const char *filename,
        int flags,
        int nWidth,
        int nHeight,
        float flFrameRate,
        int jpeg_quality)
{
  AVIParams_t params; // [esp+Ch] [ebp-220h] BYREF

  s_flPreviousHostFramerate = host_framerate.m_pParent->m_Value.m_fValue;
  ConVar::SetValue(this: (ConVar *)&host_framerate.IConVar, value: flFrameRate);
  cl_movieinfo.moviename[0] = 0;
  cl_movieinfo.movieframe = 0;
  cl_movieinfo.type = 5;
  cl_movieinfo.jpeg_quality = 50;
  V_strncpy(pDest: cl_movieinfo.moviename, pSrc: filename, maxLen: 256);
  cl_movieinfo.type = flags;
  cl_movieinfo.jpeg_quality = jpeg_quality;
  if ( (flags & 2) != 0 || (flags & 8) != 0 )
  {
    params.m_nFrameRate = 0;
    params.m_nFrameScale = 1;
    memset(&params.m_nWidth, 0, 20);
    params.m_bGetCodecFromUser = true;
    params.m_pFileName[0] = 0;
    V_strncpy(pDest: params.m_pFileName, pSrc: filename, maxLen: 256);
    V_strncpy(pDest: params.m_pPathID, pSrc: "MOD", maxLen: 256);
    params.m_nNumChannels = 2;
    params.m_nSampleBits = 16;
    params.m_nSampleRate = 44100;
    params.m_nWidth = nWidth;
    params.m_nHeight = nHeight;
    if ( fabs((double)(int)flFrameRate - flFrameRate) >= 0.001 )
    {
      if ( fabs(
             (double)(int)(float)((float)(flFrameRate * 1001.0) * 0.001)
           - (float)((float)(flFrameRate * 1001.0) * 0.001)) >= 0.001 )
      {
        params.m_nFrameRate = (int)(float)(flFrameRate * 1000.0);
        params.m_nFrameScale = 1000;
      }
      else
      {
        params.m_nFrameRate = (int)(float)(flFrameRate * 1001.0);
        params.m_nFrameScale = 1001;
      }
    }
    else
    {
      params.m_nFrameRate = (int)flFrameRate;
      params.m_nFrameScale = 1;
    }
    g_hCurrentAVI = avi->StartAVI(this: avi, a2: &params);
  }
  SND_MovieStart();
}

//------------------------------------------------------------------------------
// Address: 0x10088D60
// Name: bool CL_IsRecordingMovie(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CL_IsRecordingMovie()
{
  return cl_movieinfo.moviename[0] != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10089030
// Name: rcon
// Source: json
//------------------------------------------------------------------------------
void __cdecl rcon(const CCommand *args)
{
  int m_nArgc; // eax
  int v3; // edi
  char *v4; // esi
  int v5; // eax
  CRConClient *v6; // eax
  char message[1024]; // [esp+8h] [ebp-500h] BYREF
  char szParam[256]; // [esp+408h] [ebp-100h] BYREF
  const CCommand *argsa; // [esp+510h] [ebp+8h]

  m_nArgc = args->m_nArgc;
  v3 = 1;
  message[0] = 0;
  if ( m_nArgc > 1 )
  {
    argsa = (const CCommand *)&args->m_ppArgv[1];
    do
    {
      if ( v3 < 0 || v3 >= m_nArgc )
        v4 = (char *)defaultValue;
      else
        v4 = (char *)argsa->m_nArgc;
      strchr(string: v4, chr: 0x20u);
      if ( v5 != 0 || _V_strlen(str: v4) == 0 )
      {
        V_snprintf(pDest: szParam, maxLen: 256, pFormat: "\"%s\"", v4);
        V_strncat(pDest: message, pSrc: szParam, destBufferSize: 0x400u, max_chars_to_copy: -1);
      }
      else
      {
        V_strncat(pDest: message, pSrc: v4, destBufferSize: 0x400u, max_chars_to_copy: -1);
      }
      if ( v3 != args->m_nArgc - 1 )
        V_strncat(pDest: message, pSrc: " ", destBufferSize: 0x400u, max_chars_to_copy: -1);
      m_nArgc = args->m_nArgc;
      argsa = (const CCommand *)((char *)argsa + 4);
      ++v3;
    }
    while ( v3 < args->m_nArgc );
  }
  v6 = RCONClient();
  CRConClient::SendCmd(this: v6, msg: message);
}

//------------------------------------------------------------------------------
// Address: 0x10089130
// Name: box
// Source: json
//------------------------------------------------------------------------------
void __cdecl box(const CCommand *args)
{
  const CCommand *v1; // ecx
  int v2; // esi
  const char **v3; // ebx
  int v4; // edi
  const char *v5; // eax
  const char *v6; // eax
  Vector mins; // [esp+10h] [ebp-1Ch] BYREF
  Vector maxs; // [esp+1Ch] [ebp-10h] BYREF
  int v9; // [esp+28h] [ebp-4h]

  v1 = args;
  if ( args->m_nArgc == 7 )
  {
    v2 = 4;
    v3 = &args->m_ppArgv[4];
    v4 = 0;
    v9 = 3;
    while ( 1 )
    {
      v5 = v2 - 3 < 0 || v2 - 3 >= v1->m_nArgc ? defaultValue : *(v3 - 3);
      *(float *)((char *)&mins.x + v4) = atof(nptr: v5);
      if ( v2 < 0 || v2 >= args->m_nArgc )
        v6 = defaultValue;
      else
        v6 = *v3;
      *(float *)((char *)&maxs.x + v4) = atof(nptr: v6);
      ++v2;
      ++v3;
      v4 += 4;
      if ( --v9 == 0 )
        break;
      v1 = args;
    }
    CDebugOverlay::AddBoxOverlay(
      origin: &vec3_origin,
      &mins,
      &maxs,
      angles: &vec3_angle,
      r: 255,
      g: 0,
      b: 0,
      a: 0,
      flDuration: 100.0);
  }
  else
  {
    ConMsg(a1: "box x1 y1 z1 x2 y2 z2\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089200
// Name: cl_view
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_view(const CCommand *args)
{
  CClientState *LocalClient; // eax
  int ViewEntity; // eax
  const char *v3; // eax
  int v4; // esi

  if ( args->m_nArgc == 2 )
  {
    if ( GetBaseLocalClient()->m_nMaxClients <= 1 )
    {
      v3 = defaultValue;
      if ( args->m_nArgc > 1 )
        v3 = args->m_ppArgv[1];
      v4 = atoi(nptr: v3);
      if ( v4 != 0 && v4 <= entitylist->GetHighestEntityIndex(this: entitylist) )
      {
        GetLocalClient(nSlot: -1)->m_nViewEntity = v4;
        videomode->MarkClientViewRectDirty(this: videomode);
        ConMsg(a1: "View entity set to %i\n", v4);
      }
    }
  }
  else
  {
    LocalClient = GetLocalClient(nSlot: -1);
    ViewEntity = CBaseClientState::GetViewEntity(this: LocalClient);
    ConMsg(a1: "cl_view entity#\nCurrent %i\n", ViewEntity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100892A0
// Name: void CL_UpdateDAndELights(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_UpdateDAndELights(bool bUpdateDecay)
{
  CClientState *BaseLocalClient; // eax
  int v2; // ebx
  int v3; // esi
  float *p_radius; // edi
  CClientState *v5; // eax
  int v6; // eax
  int v7; // eax
  float v8; // xmm2_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // edi
  float *v12; // esi
  CClientState *v13; // eax
  int v14; // eax
  int v15; // eax
  float time; // [esp+Ch] [ebp-4h]

  BaseLocalClient = GetBaseLocalClient();
  time = CClientState::GetFrameTime(this: BaseLocalClient);
  v2 = 0;
  g_bActiveDlights = false;
  g_bActiveElights = false;
  r_dlightchanged = 0;
  r_dlightactive = 0;
  g_nNumActiveDLights = 0;
  v3 = 1;
  p_radius = &cl_dlights[0].radius;
  do
  {
    if ( (float)(*p_radius > 0.0) == 0.0 )
      goto LABEL_14;
    v5 = GetBaseLocalClient();
    if ( CClientState::GetTime(this: v5) > (double)p_radius[2] )
    {
      r_dlightchanged |= v3;
LABEL_5:
      *p_radius = 0.0;
LABEL_6:
      v6 = 0;
      goto LABEL_7;
    }
    v8 = p_radius[3];
    if ( v8 != 0.0 && bUpdateDecay )
    {
      v9 = *p_radius;
      r_dlightchanged |= v3;
      v10 = v9 - (float)(v8 * time);
      *p_radius = v10;
      if ( v10 < 0.0 )
        goto LABEL_5;
    }
    if ( *p_radius <= 0.0 )
      goto LABEL_6;
    v6 = 1;
LABEL_7:
    if ( (float)v6 != 0.0 )
    {
      v7 = g_nNumActiveDLights;
      r_dlightactive |= v3;
      g_ActiveDLightIndex[g_nNumActiveDLights] = v2;
      g_bActiveDlights = true;
      g_nNumActiveDLights = v7 + 1;
      goto LABEL_15;
    }
LABEL_14:
    R_MarkDLightNotVisible(dlight: v2);
LABEL_15:
    ++v2;
    v3 = __ROL4__(v3, 1);
    p_radius += 17;
  }
  while ( v2 < 32 );
  g_nNumActiveELights = 0;
  v11 = 0;
  v12 = &cl_elights[0].radius;
  do
  {
    if ( (float)(*v12 > 0.0) == 0.0 )
      goto LABEL_27;
    v13 = GetBaseLocalClient();
    if ( CClientState::GetTime(this: v13) > (double)v12[2] )
    {
      *v12 = 0.0;
      goto LABEL_27;
    }
    if ( bUpdateDecay )
      *v12 = *v12 - (float)(v12[3] * time);
    if ( *v12 < 0.0 )
    {
      *v12 = 0.0;
LABEL_24:
      v14 = 0;
      goto LABEL_25;
    }
    if ( *v12 <= 0.0 )
      goto LABEL_24;
    v14 = 1;
LABEL_25:
    if ( (float)v14 != 0.0 )
    {
      v15 = g_nNumActiveELights;
      g_ActiveELightIndex[g_nNumActiveELights] = v11;
      g_bActiveElights = true;
      g_nNumActiveELights = v15 + 1;
    }
LABEL_27:
    ++v11;
    v12 += 17;
  }
  while ( v11 < 64 );
}

//------------------------------------------------------------------------------
// Address: 0x10089490
// Name: void CL_ExtraMouseUpdate(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_ExtraMouseUpdate(float frametime)
{
  IBaseClientDLL_vtbl *v1; // esi
  CClientState *LocalClient; // eax

  if ( Host_ShouldRun() != 0
    && GetLocalClient(nSlot: -1)->m_nSignonState == 6
    && (!demoplayer->IsPlayingBack(this: demoplayer) || GetLocalClient(nSlot: -1)->ishltv) )
  {
    v1 = g_ClientDLL->__vftable;
    LocalClient = GetLocalClient(nSlot: -1);
    ((void (__thiscall *)(IBaseClientDLL *, _DWORD, bool))v1->ExtraMouseSample)(
      a1: g_ClientDLL,
      a2: LODWORD(frametime),
      a3: !LocalClient->m_bPaused);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089510
// Name: void CL_LatchInterpolationAmount(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_LatchInterpolationAmount()
{
  CClientState *BaseLocalClient; // eax
  CClientState *v1; // esi
  int v2; // xmm1_4
  double v3; // st7
  float flClientInterpolationAmount; // [esp+8h] [ebp-Ch]
  float dt; // [esp+Ch] [ebp-8h]
  float flInterp; // [esp+10h] [ebp-4h]

  BaseLocalClient = GetBaseLocalClient();
  v1 = BaseLocalClient;
  if ( BaseLocalClient->m_nSignonState >= 2 )
  {
    dt = BaseLocalClient->m_NetChannel->GetTimeSinceLastReceived(this: BaseLocalClient->m_NetChannel);
    v2 = 0;
    v3 = host_state.interval_per_tick
       * (double)(int)(CClientState::GetClientInterpAmount(this: v1) / host_state.interval_per_tick + 0.5);
    flInterp = 0.0;
    flClientInterpolationAmount = v3;
    if ( v3 > 0.001 )
    {
      if ( (float)(dt / flClientInterpolationAmount) < 0.0
        || (v2 = 1077936128, (float)(dt / flClientInterpolationAmount) > 3.0) )
      {
        flInterp = *(float *)&v2;
      }
      else
      {
        flInterp = dt / flClientInterpolationAmount;
      }
    }
    ((void (__stdcall *)(float))v1->m_NetChannel->SetInterpolationAmount)(a1: COERCE_FLOAT(LODWORD(flInterp)));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100895C0
// Name: void CL_GetBackgroundLevelName(char __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_GetBackgroundLevelName(char *pszBackgroundName, int bufSize, bool bMapName)
{
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  IBaseFileSystem *v5; // eax
  int v6; // edi
  KeyValues *NextKey; // eax
  KeyValues *v8; // esi
  const char *v9; // eax
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  int v12; // eax
  int m_nValue; // eax
  KeyValues *Key; // eax
  const char *String; // eax
  char buf[4]; // [esp+8h] [ebp-8h] BYREF
  KeyValues *pChapterRoot; // [esp+Ch] [ebp-4h]

  V_strncpy(pDest: pszBackgroundName, pSrc: "background01", maxLen: bufSize);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: pszBackgroundName);
  else
    v4 = nullptr;
  if ( g_pFileSystem != nullptr )
    v5 = &g_pFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v4,
         filesystem: v5,
         resourceName: "scripts/ChapterBackgrounds.txt",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    pChapterRoot = v4;
    v6 = 1;
    NextKey = KeyValues::GetNextKey(this: v4);
    v8 = NextKey;
    if ( bMapName
      && NextKey != nullptr
      && (v9 = KeyValues::GetName(this: NextKey)) != nullptr
      && *v9 != 0
      && V_strncmp(s1: "BackgroundMaps", s2: v9, count: 14) == 0
      && (pChapterRoot = v8, (FirstSubKey = KeyValues::GetFirstSubKey(this: v8)) != nullptr)
      || (FirstSubKey = KeyValues::GetFirstSubKey(this: v4)) != nullptr )
    {
      do
      {
        Name = KeyValues::GetName(this: FirstSubKey);
        if ( Name != nullptr )
        {
          v12 = atoi(nptr: Name);
          if ( v12 > v6 )
            v6 = v12;
        }
        FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
      }
      while ( FirstSubKey != nullptr );
    }
    if ( sv_unlockedchapters.m_pParent != nullptr )
      m_nValue = sv_unlockedchapters.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( m_nValue >= v6 )
      m_nValue = v6;
    if ( m_nValue <= 0 )
      m_nValue = 1;
    V_snprintf(pDest: buf, maxLen: 4, pFormat: "%d", m_nValue);
    Key = KeyValues::FindKey(this: pChapterRoot, keyName: buf, bCreate: false);
    if ( Key != nullptr )
    {
      String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: defaultValue);
      V_strncpy(pDest: pszBackgroundName, pSrc: String, maxLen: bufSize);
    }
  }
  KeyValues::deleteThis(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10089720
// Name: void CL_DemoCheckGameUIRevealTime(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CL_DemoCheckGameUIRevealTime(void *this)
{
  vgui::CTreeViewListControl *v1; // ecx
  ECommandTarget_t TraceType; // eax
  int v3; // ecx
  int v4; // ecx
  double v5; // st6
  IEngineVGuiInternal *v6; // eax
  vgui::CTreeViewListControl *v7; // ecx
  ECommandTarget_t v8; // eax
  CCommand args; // [esp+0h] [ebp-510h] BYREF
  double v10; // [esp+508h] [ebp-8h]

  if ( s_fDemoRevealGameUITime > 0.0 )
  {
    v10 = s_fDemoRevealGameUITime;
    if ( _Plat_FloatTime(a1: this) > v10 )
    {
      s_fDemoRevealGameUITime = -1.0;
      SCR_BeginLoadingPlaque(levelName: nullptr);
      TraceType = CTraceFilter::GetTraceType(this: v1);
      Cbuf_AddText(eTarget: TraceType, pText: "disconnect;", nTickDelay: 0);
      CCommand::CCommand(this: &args);
      s_fDemoPlayMusicTime = _Plat_FloatTime(a1: v3) + 1.0;
    }
  }
  if ( s_fDemoPlayMusicTime > 0.0 )
  {
    V_CheckGamma();
    V_RenderVGuiOnly();
    v10 = s_fDemoPlayMusicTime;
    v5 = _Plat_FloatTime(a1: v4);
    if ( v5 > v10 )
    {
      s_fDemoPlayMusicTime = -1.0;
      v6 = EngineVGui();
      v6->ActivateGameUI(this: v6);
      CL_InitHL2DemoFlag();
      if ( s_bIsHL2Demo && s_bIsRavenHolmn )
      {
        v8 = CTraceFilter::GetTraceType(this: v7);
        Cbuf_AddText(eTarget: v8, pText: "play music/ravenholm_1.mp3;", nTickDelay: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089830
// Name: void CL_SetSteamCrashComment(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_SetSteamCrashComment()
{
  char *v0; // eax
  IMaterialSystem_vtbl *v1; // esi
  int v2; // eax
  const char *v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // esi
  CClientState *BaseLocalClient; // eax
  int m_nValue; // edi
  double v10; // st7
  double v11; // st7
  int v12; // eax
  const char *v13; // esi
  CClientState *v14; // eax
  netadr_s *v15; // eax
  int v16; // eax
  int v17; // eax
  bool v18; // zf
  char *v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // [esp-10h] [ebp-25DCh]
  int v23; // [esp-Ch] [ebp-25D8h]
  const char *v24; // [esp-Ch] [ebp-25D8h]
  int v25; // [esp-8h] [ebp-25D4h]
  const char *v26; // [esp-8h] [ebp-25D4h]
  int v27; // [esp-4h] [ebp-25D0h]
  const char *v28; // [esp-4h] [ebp-25D0h]
  char v29[4096]; // [esp+8h] [ebp-25C4h] BYREF
  char v30[2048]; // [esp+1008h] [ebp-15C4h] BYREF
  char v31[2048]; // [esp+1808h] [ebp-DC4h] BYREF
  char v32[256]; // [esp+2008h] [ebp-5C4h] BYREF
  char osversion[256]; // [esp+2108h] [ebp-4C4h] BYREF
  char v34[512]; // [esp+2208h] [ebp-3C4h] BYREF
  int v35; // [esp+2408h] [ebp-1C4h]
  int v36; // [esp+240Ch] [ebp-1C0h]
  int v37; // [esp+2410h] [ebp-1BCh]
  int v38; // [esp+2414h] [ebp-1B8h]
  unsigned int v39; // [esp+2424h] [ebp-1A8h]
  unsigned int v40; // [esp+2428h] [ebp-1A4h]
  char pDest[64]; // [esp+242Ch] [ebp-1A0h] BYREF
  char str[128]; // [esp+246Ch] [ebp-160h] BYREF
  char pFixedName[80]; // [esp+24ECh] [ebp-E0h] BYREF
  _BYTE v44[8]; // [esp+253Ch] [ebp-90h] BYREF
  int v45; // [esp+2544h] [ebp-88h]
  ConVarRef v46; // [esp+2560h] [ebp-6Ch] BYREF
  ConVarRef v47; // [esp+2568h] [ebp-64h] BYREF
  ConVarRef v48; // [esp+2570h] [ebp-5Ch] BYREF
  ConVarRef v49; // [esp+2578h] [ebp-54h] BYREF
  ConVarRef v50; // [esp+2580h] [ebp-4Ch] BYREF
  ConVarRef v51; // [esp+2588h] [ebp-44h] BYREF
  ConVarRef v52; // [esp+2590h] [ebp-3Ch] BYREF
  ConVarRef v53; // [esp+2598h] [ebp-34h] BYREF
  ConVarRef v54; // [esp+25A0h] [ebp-2Ch] BYREF
  ConVarRef v55; // [esp+25A8h] [ebp-24h] BYREF
  ConVarRef v56; // [esp+25B0h] [ebp-1Ch] BYREF
  ConVarRef v57; // [esp+25B8h] [ebp-14h] BYREF
  ConVarRef v58; // [esp+25C0h] [ebp-Ch] BYREF
  char v59[4]; // [esp+25C8h] [ebp-4h] BYREF

  pFixedName[0] = 0;
  v30[0] = 0;
  v31[0] = 0;
  v32[0] = 0;
  osversion[0] = 0;
  if ( host_state.worldmodel != nullptr )
  {
    v0 = (char *)modelloader->GetName(this: modelloader, a2: host_state.worldmodel);
    CL_SetupMapName(pName: v0, pFixedName, maxlen: 80);
  }
  DisplaySystemVersion(osversion, maxlen: 256);
  v1 = materials->__vftable;
  v2 = ((int (__thiscall *)(IMaterialSystem *, char *))materials->GetCurrentAdapter)(a1: materials, a2: v34);
  ((void (__thiscall *)(IMaterialSystem *, int))v1->GetDisplayAdapterInfo)(a1: materials, a2: v2);
  v3 = "Unk";
  if ( g_pMaterialSystemHardwareConfig != nullptr )
  {
    v4 = g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig);
    v3 = COM_DXLevelToString(dxlevel: v4);
  }
  V_snprintf(
    pDest,
    maxLen: 64,
    pFormat: "%ld.%ld.%ld.%ld",
    HIWORD(v39),
    (unsigned __int16)v39,
    HIWORD(v40),
    (unsigned __int16)v40);
  if ( v3 == nullptr )
    v3 = "Unk";
  v5 = videomode->GetModeHeight(this: videomode);
  v6 = ((int (__thiscall *)(IVideoMode *, int))videomode->GetModeWidth)(a1: videomode, a2: v5);
  V_snprintf(
    pDest: v30,
    maxLen: 2048,
    pFormat: "Driver Name:  %s\n"
    "Driver Version: %s\n"
    "VendorId / DeviceId:  0x%x / 0x%x\n"
    "SubSystem / Rev:  0x%x / 0x%x\n"
    "DXLevel:  %s\n"
    "Vid:  %i x %i",
    v34,
    pDest,
    v35,
    v36,
    v37,
    v38,
    v3,
    v6,
    v27);
  ConVarRef::ConVarRef(this: &v56, pName: "mat_picmip");
  ConVarRef::ConVarRef(this: &v57, pName: "mat_forceaniso");
  ConVarRef::ConVarRef(this: &v58, pName: "mat_antialias");
  ConVarRef::ConVarRef(this: &v52, pName: "mat_aaquality");
  ConVarRef::ConVarRef(this: &v51, pName: "r_shadowrendertotexture");
  ConVarRef::ConVarRef(this: &v49, pName: "r_flashlightdepthtexture");
  ConVarRef::ConVarRef(this: &v53, pName: "r_waterforceexpensive");
  ConVarRef::ConVarRef(this: &v46, pName: "r_waterforcereflectentities");
  ConVarRef::ConVarRef(this: &v54, pName: "mat_vsync");
  ConVarRef::ConVarRef(this: &v47, pName: "r_rootlod");
  ConVarRef::ConVarRef(this: &v55, pName: "mat_motion_blur_enabled");
  ConVarRef::ConVarRef(this: &v48, pName: "mat_queue_mode");
  ConVarRef::ConVarRef(this: &v50, pName: "mat_triplebuffered");
  V_snprintf(
    pDest: v31,
    maxLen: 2048,
    pFormat: "picmip: %i\n"
    "forceansio: %i\n"
    "antialias: %i (%i)\n"
    "vsync: %i\n"
    "rootlod: %i\n"
    "shadowrendertotexture: %i\n"
    "r_flashlightdepthtexture %i\n"
    "waterforceexpensive: %i\n"
    "waterforcereflectentities: %i\n"
    "mat_motion_blur_enabled: %i\n"
    "mat_queue_mode %i\n"
    "mat_triplebuffered: %i\n",
    v56.m_pConVarState->m_Value.m_nValue,
    v57.m_pConVarState->m_Value.m_nValue,
    v58.m_pConVarState->m_Value.m_nValue,
    v52.m_pConVarState->m_Value.m_nValue,
    v54.m_pConVarState->m_Value.m_nValue,
    v47.m_pConVarState->m_Value.m_nValue,
    v51.m_pConVarState->m_Value.m_nValue,
    v49.m_pConVarState->m_Value.m_nValue,
    v53.m_pConVarState->m_Value.m_nValue,
    v46.m_pConVarState->m_Value.m_nValue,
    v55.m_pConVarState->m_Value.m_nValue,
    v48.m_pConVarState->m_Value.m_nValue,
    v50.m_pConVarState->m_Value.m_nValue);
  v7 = 0;
  if ( GetBaseLocalClient()->m_NetChannel != nullptr )
  {
    BaseLocalClient = GetBaseLocalClient();
    v7 = (int)(((double (__thiscall *)(INetChannel *, _DWORD))BaseLocalClient->m_NetChannel->GetAvgLatency)(
                 a1: BaseLocalClient->m_NetChannel,
                 a2: 0)
             * 1000.0);
  }
  if ( skill.m_pParent != nullptr )
    m_nValue = skill.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v10 = ((double (__thiscall *)(ConVar_ServerBounded *, int))cl_cmdrate->GetFloat)(a1: cl_cmdrate, a2: v7);
  v11 = ((double (__thiscall *)(ConVar_ServerBounded *, int))cl_updaterate->GetFloat)(a1: cl_updaterate, a2: (int)v10);
  v12 = ((int (__thiscall *)(ConVar_ServerBounded *, int))cl_rate->GetInt)(a1: cl_rate, a2: (int)v11);
  V_snprintf(
    pDest: v32,
    maxLen: 256,
    pFormat: "skill:%i rate %i update %i cmd %i latency %i msec",
    m_nValue,
    v12,
    v22,
    v23,
    v25);
  v13 = "Not Connected";
  if ( GetBaseLocalClient()->m_NetChannel != nullptr )
  {
    v14 = GetBaseLocalClient();
    v15 = (netadr_s *)v14->m_NetChannel->GetRemoteAddress(this: v14->m_NetChannel);
    v13 = netadr_s::ToString(this: v15, baseOnly: false);
  }
  _Plat_GetPagedPoolInfo(a1: &g_pagedpoolinfo);
  strcpy(v59, "AM");
  _Plat_GetLocalTime(a1: v44);
  v16 = v45;
  if ( v45 > 12 )
  {
    V_strncpy(pDest: v59, pSrc: "PM", maxLen: 3);
    v16 = v45;
    if ( v45 > 12 )
    {
      v16 = v45 - 12;
      v45 -= 12;
    }
  }
  if ( v16 == 0 )
    v45 = 12;
  _Plat_GetTimeString(a1: v44, a2: str, a3: 128);
  v17 = _V_strlen(str);
  if ( v17 > 0 )
  {
    v18 = pDest[v17 + 63] == 10;
    v19 = &pDest[v17 + 63];
    if ( v18 )
      *v19 = 0;
  }
  v20 = _CommandLine();
  v24 = (const char *)(*(int (__thiscall **)(int, char *, char *))(*(_DWORD *)v20 + 8))(a1: v20, a2: v30, a3: v31);
  v21 = build_number();
  V_snprintf(
    pDest: g_minidumpinfo,
    maxLen: 4096,
    pFormat: "Map: %s\nGame: %s\nBuild: %i\nOS: %s\nMisc: %s\nNet: %s\nTime: %s\ncmdline:%s\ndriver: %s\nvideo: %s\n",
    pFixedName,
    com_gamedir,
    v21,
    osversion,
    v32,
    v13,
    str,
    v24,
    v26,
    v28);
  V_snprintf(
    pDest: v29,
    maxLen: 4096,
    pFormat: "%sPP PAGES: used: %d, free %d\n",
    g_minidumpinfo,
    g_pagedpoolinfo.numPagesUsed,
    g_pagedpoolinfo.numPagesFree);
  _SteamAPI_SetMiniDumpComment(a1: v29);
}

//------------------------------------------------------------------------------
// Address: 0x10089CB0
// Name: void CL_InitLanguageCvar(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_InitLanguageCvar()
{
  int v0; // eax
  int v1; // eax
  const char *v2; // [esp-Ch] [ebp-50h]
  char language[64]; // [esp+4h] [ebp-40h] BYREF

  V_strncpy(pDest: language, pSrc: "english", maxLen: 64);
  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v0 + 12))(a1: v0, a2: "-language", a3: 0) != 0 )
  {
    v1 = _CommandLine();
    v2 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v1 + 32))(a1: v1);
    V_strncpy(pDest: language, pSrc: v2, maxLen: (int)"-language");
  }
  else
  {
    memset(dst: (unsigned __int8 *)language, value: 0, count: sizeof(language));
    ((void (__thiscall *)(vgui::ISystem *, const char *, char *))g_pVGuiSystem->GetRegistryString)(
      a1: g_pVGuiSystem,
      a2: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Language",
      a3: language);
    if ( _V_strlen(str: language) == 0 || _V_stricmp(s1: language, s2: "unknown") == 0 )
      V_strncpy(pDest: language, pSrc: "english", maxLen: 64);
  }
  CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&cl_language.IConVar, value: language);
}

//------------------------------------------------------------------------------
// Address: 0x10089D80
// Name: void CL_ChangeCloudSettingsCvar(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_ChangeCloudSettingsCvar(IConVar *var)
{
  CSteam3Client *v1; // eax
  int v2; // eax
  const char *v3; // eax
  char szRegistryKeyLocation[256]; // [esp+0h] [ebp-108h] BYREF
  ConVarRef ref; // [esp+100h] [ebp-8h] BYREF

  if ( Steam3Client()->m_pSteamUtils != nullptr )
  {
    v1 = Steam3Client();
    v2 = v1->m_pSteamUtils->GetAppID(this: v1->m_pSteamUtils);
    V_snprintf(
      pDest: szRegistryKeyLocation,
      maxLen: 256,
      pFormat: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Apps\\%d\\Cloud",
      v2);
    v3 = var->GetName(this: var);
    ConVarRef::ConVarRef(this: &ref, pName: v3);
    g_pVGuiSystem->SetRegistryInteger(
      this: g_pVGuiSystem,
      a2: szRegistryKeyLocation,
      a3: ref.m_pConVarState->m_Value.m_nValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089DF0
// Name: void CL_InitCloudSettingsCvar(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_InitCloudSettingsCvar()
{
  CSteam3Client *v0; // eax
  int v1; // eax
  char szRegistryKeyLocation[256]; // [esp+0h] [ebp-104h] BYREF
  int iCloudSettings; // [esp+100h] [ebp-4h] BYREF

  if ( Steam3Client()->m_pSteamUtils != nullptr )
  {
    iCloudSettings = -1;
    v0 = Steam3Client();
    v1 = v0->m_pSteamUtils->GetAppID(this: v0->m_pSteamUtils);
    V_snprintf(
      pDest: szRegistryKeyLocation,
      maxLen: 256,
      pFormat: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Apps\\%d\\Cloud",
      v1);
    if ( !g_pVGuiSystem->GetRegistryInteger(this: g_pVGuiSystem, a2: szRegistryKeyLocation, a3: &iCloudSettings) )
      iCloudSettings = -1;
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&cl_cloud_settings.IConVar, value: iCloudSettings);
  }
  else
  {
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&cl_cloud_settings.IConVar, value: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089E80
// Name: void CL_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_Init()
{
  int i; // esi
  CClientState *LocalClient; // eax
  int v2; // eax
  char szRate[128]; // [esp+4h] [ebp-80h] BYREF

  for ( i = 0; i < host_state.max_splitscreen_players; ++i )
  {
    LocalClient = GetLocalClient(nSlot: -1);
    LocalClient->Clear(this: LocalClient);
  }
  szRate[0] = 0;
  Sys_GetRegKeyValue(
    pszSubKey: "Software\\Valve\\Steam",
    pszElement: "Rate",
    pszReturnString: szRate,
    nReturnLength: 128,
    pszDefaultValue: "10000");
  if ( _V_strlen(str: szRate) > 0 )
  {
    v2 = V_atoi(str: szRate);
    if ( v2 >= 1000 )
    {
      if ( v2 > 30000 )
        v2 = 30000;
    }
    else
    {
      v2 = 1000;
    }
    cl_rate->SetValue_2(this: &cl_rate->IConVar, a2: v2);
  }
  CL_InitLanguageCvar();
  CL_InitCloudSettingsCvar();
}

//------------------------------------------------------------------------------
// Address: 0x10089F30
// Name: cl_precacheinfo
// Source: json
//------------------------------------------------------------------------------
void __cdecl cl_precacheinfo(const CCommand *args)
{
  CClientState *BaseLocalClient; // eax
  CClientState *v2; // eax
  CClientState *v3; // eax
  CClientState *v4; // eax
  CClientState *v5; // eax
  const char *v6; // [esp-4h] [ebp-4h]

  if ( args->m_nArgc == 2 )
  {
    v6 = args->m_ppArgv[1];
    BaseLocalClient = GetBaseLocalClient();
    CClientState::DumpPrecacheStats(this: BaseLocalClient, name: v6);
  }
  else
  {
    v2 = GetBaseLocalClient();
    CClientState::DumpPrecacheStats(this: v2, name: "modelprecache");
    v3 = GetBaseLocalClient();
    CClientState::DumpPrecacheStats(this: v3, name: "decalprecache");
    v4 = GetBaseLocalClient();
    CClientState::DumpPrecacheStats(this: v4, name: "soundprecache");
    v5 = GetBaseLocalClient();
    CClientState::DumpPrecacheStats(this: v5, name: "genericprecache");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A030
// Name: public: virtual char const __near * CLC_Move::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_Move::GetName(CLC_Move *this)
{
  return "clc_Move";
}

//------------------------------------------------------------------------------
// Address: 0x1008A0F0
// Name: void CL_ReadPackets(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_ReadPackets(bool bFinalTick)
{
  CClientState *BaseLocalClient; // esi
  IEngineVGuiInternal *v2; // eax
  INetChannel *m_NetChannel; // ecx
  INetChannel *v4; // ecx
  IEngineVGuiInternal *v5; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CL_ReadPackets",
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 4);
  splitscreen->SetActiveSplitScreenPlayerSlot(this: splitscreen, a2: 0);
  splitscreen->SetLocalPlayerIsResolvable(this: splitscreen, a2: "..\\engine\\cl_main.cpp", a3: 518, a4: false);
  if ( Host_ShouldRun() == 0 )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  splitscreen->SetLocalPlayerIsResolvable(this: splitscreen, a2: "..\\engine\\cl_main.cpp", a3: 523, a4: true);
  BaseLocalClient = GetBaseLocalClient();
  if ( BaseLocalClient->m_nSignonState == 6 && scr_drawloading )
  {
    v2 = EngineVGui();
    v2->UpdateProgressBar(this: v2, a2: PROGRESS_DEFAULT, a3: true);
  }
  BaseLocalClient->oldtickcount = BaseLocalClient->m_ClockDriftMgr.m_nServerTick;
  if ( !CClientState::IsPaused(this: BaseLocalClient) )
  {
    ++BaseLocalClient->m_ClockDriftMgr.m_nClientTick;
    if ( !CClockDriftMgr::IsClockCorrectionEnabled() )
      BaseLocalClient->m_ClockDriftMgr.m_nServerTick = BaseLocalClient->m_ClockDriftMgr.m_nClientTick;
    g_ClientGlobalVariables.tickcount = BaseLocalClient->m_ClockDriftMgr.m_nClientTick;
    g_ClientGlobalVariables.curtime = CClientState::GetTime(this: BaseLocalClient);
  }
  g_ClientGlobalVariables.frametime = CClientState::GetFrameTime(this: BaseLocalClient);
  if ( demoplayer->IsPlayingBack(this: demoplayer) && (m_NetChannel = BaseLocalClient->m_NetChannel) != nullptr )
  {
    m_NetChannel->ProcessPlayback(this: m_NetChannel);
  }
  else if ( cl_ignorepackets.m_pParent == nullptr || cl_ignorepackets.m_pParent->m_Value.m_nValue == 0 )
  {
    NET_ProcessSocket(sock: 0, handler: &BaseLocalClient->IConnectionlessPacketHandler);
    if ( net_earliertempents.m_pParent != nullptr && net_earliertempents.m_pParent->m_Value.m_nValue != 0 )
      CL_FireEvents();
  }
  if ( bFinalTick && !demoplayer->IsPlayingBack(this: demoplayer) && BaseLocalClient->m_nSignonState >= 2 )
  {
    v4 = BaseLocalClient->m_NetChannel;
    if ( v4 != nullptr )
    {
      if ( v4->IsTimedOut(this: v4) )
      {
        ConMsg(a1: "\nServer connection timed out.\n");
        COM_ExplainDisconnection(bPrint: false, fmt: "Connection to server timed out.");
LABEL_26:
        v5 = EngineVGui();
        v5->ShowErrorMessage(this: v5);
        Host_Disconnect(bShowMainMenu: true);
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        return;
      }
      if ( BaseLocalClient->m_NetChannel->IsRemoteDisconnected(this: BaseLocalClient->m_NetChannel) )
      {
        ConMsg(a1: "\nServer shutting down\n");
        COM_ExplainDisconnection(bPrint: false, fmt: "Server shutting down");
        goto LABEL_26;
      }
    }
  }
  splitscreen->SetLocalPlayerIsResolvable(this: splitscreen, a2: "..\\engine\\cl_main.cpp", a3: 617, a4: false);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1008A300
// Name: screenshot
// Source: json
//------------------------------------------------------------------------------
void __cdecl screenshot(const CCommand *args)
{
  CTestScriptMgr::SetWaitCheckPoint(this: &g_TestScriptMgr, pCheckPointName: "screenshot", bOnce: false);
  if ( !demoplayer->IsPlayingBack(this: demoplayer)
    || cl_playback_screenshots.m_pParent != nullptr && cl_playback_screenshots.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( args->m_nArgc == 2 )
      CL_TakeScreenshot(name: args->m_ppArgv[1]);
    else
      CL_TakeScreenshot(name: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A360
// Name: void CL_TakeJpeg(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_TakeJpeg(const char *name, int quality)
{
  if ( !demoplayer->IsPlayingBack(this: demoplayer)
    || cl_playback_screenshots.m_pParent != nullptr && cl_playback_screenshots.m_pParent->m_Value.m_nValue != 0 )
  {
    cl_takesnapshot = true;
    cl_snapshot_fullpathname[0] = 0;
    cl_takejpeg = true;
    if ( quality >= 1 )
    {
      cl_jpegquality = 100;
      if ( quality <= 100 )
        cl_jpegquality = quality;
    }
    else
    {
      cl_jpegquality = 1;
    }
    if ( name != nullptr )
      V_strncpy(pDest: cl_snapshotname, pSrc: name, maxLen: 260);
    else
      cl_snapshotname[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A3F0
// Name: jpeg
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg(const CCommand *args)
{
  int m_nArgc; // edx
  const char *v2; // esi
  int v3; // eax
  int v4; // eax
  int m_nValue; // esi

  m_nArgc = args->m_nArgc;
  if ( args->m_nArgc < 2 )
  {
    if ( jpeg_quality.m_pParent != nullptr )
      m_nValue = jpeg_quality.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( !demoplayer->IsPlayingBack(this: demoplayer)
      || cl_playback_screenshots.m_pParent != nullptr && cl_playback_screenshots.m_pParent->m_Value.m_nValue != 0 )
    {
      cl_takesnapshot = true;
      cl_snapshot_fullpathname[0] = 0;
      cl_takejpeg = true;
      if ( m_nValue >= 1 )
      {
        cl_jpegquality = 100;
        if ( m_nValue <= 100 )
          cl_jpegquality = m_nValue;
        cl_snapshotname[0] = 0;
      }
      else
      {
        cl_jpegquality = 1;
        cl_snapshotname[0] = 0;
      }
    }
  }
  else if ( m_nArgc == 3 )
  {
    v2 = args->m_ppArgv[1];
    v3 = V_atoi(str: args->m_ppArgv[2]);
    CL_TakeJpeg(name: v2, quality: v3);
  }
  else
  {
    if ( jpeg_quality.m_pParent != nullptr )
      v4 = jpeg_quality.m_pParent->m_Value.m_nValue;
    else
      v4 = 0;
    if ( m_nArgc > 1 )
      CL_TakeJpeg(name: args->m_ppArgv[1], quality: v4);
    else
      CL_TakeJpeg(name: defaultValue, quality: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008A4E0
// Name: void CL_TakeSnapshotAndSwap(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall CL_TakeSnapshotAndSwap(int a1@<edi>, int a2@<esi>)
{
  ConVar *m_pParent; // ecx
  float v3; // xmm1_4
  float v4; // xmm0_4
  IClientEntity *v5; // esi
  IClientRenderable *v6; // edi
  IModelLoader_vtbl *v7; // esi
  const char *v8; // eax
  const char *v9; // eax
  int v10; // esi
  int v11; // ecx
  IVideoMode_vtbl *v12; // edx
  char v13; // bl
  long double v14; // st7
  long double v15; // st6
  char *v16; // [esp-30h] [ebp-448h]
  char renamedfile[260]; // [esp+0h] [ebp-418h] BYREF
  char extension[260]; // [esp+104h] [ebp-314h] BYREF
  char base[260]; // [esp+208h] [ebp-210h] BYREF
  char filename[263]; // [esp+30Ch] [ebp-10Ch] BYREF
  int bEnabled; // [esp+413h] [ebp-5h]
  bool bReadPixelsFromFrontBuffer; // [esp+417h] [ebp-1h]

  bReadPixelsFromFrontBuffer = g_pMaterialSystemHardwareConfig->ReadPixelsFromFrontBuffer(this: g_pMaterialSystemHardwareConfig);
  if ( bReadPixelsFromFrontBuffer )
    Shader_SwapBuffers();
  if ( fps_screenshot_threshold.m_pParent != nullptr && fps_screenshot_threshold.m_pParent->m_Value.m_nValue > 0 )
  {
    v3 = realtime - sLastRealTime;
    sLastRealTime = realtime;
    if ( v3 <= (float)(1.0 / fps_screenshot_threshold.m_pParent->m_Value.m_fValue) || v3 >= 10.0 )
    {
      v4 = timer;
    }
    else
    {
      v4 = timer;
      if ( timer >= 0.0 )
      {
        cl_takesnapshot = true;
        v4 = timer - fps_screenshot_frequency.m_pParent->m_Value.m_fValue;
        timer = v4;
      }
    }
    if ( v4 < 0.0 )
      timer = v4 + v3;
  }
  if ( cl_takesnapshot )
  {
    LOBYTE(bEnabled) = ((int (__thiscall *)(IMaterialSystem *, _DWORD, int, int))materials->AllowThreading)(
                         a1: materials,
                         a2: 0,
                         a3: g_nMaterialSystemThread,
                         a4: a2);
    v5 = entitylist->GetClientEntity(this: entitylist, a2: 0);
    g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: "screenshots", a3: "DEFAULT_WRITE_PATH");
    if ( cl_snapshot_fullpathname[0] != 0 )
    {
      V_ExtractFilePath(path: cl_snapshot_fullpathname, dest: renamedfile, destSize: 260);
      g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: renamedfile, a3: nullptr);
    }
    if ( v5 != nullptr
      && (v6 = &v5->IClientRenderable,
          ((int (__thiscall *)(IClientRenderable *, int))v5->GetModel)(a1: &v5->IClientRenderable, a2: a1) != 0) )
    {
      v7 = modelloader->__vftable;
      v16 = (char *)v6->GetModel(this: v6);
      v8 = (const char *)((int (__thiscall *)(IModelLoader *))v7->GetName)(a1: modelloader);
      V_FileBase(in: v8, out: v16, maxlen: (int)base);
    }
    else
    {
      V_strncpy(pDest: base, pSrc: "Snapshot", maxLen: 260);
    }
    v9 = "jpg";
    if ( !cl_takejpeg )
      v9 = "tga";
    V_snprintf(pDest: extension, maxLen: 260, pFormat: "%s.%s", defaultValue, v9);
    if ( cl_snapshot_subdirname[0] != 0 )
    {
      V_snprintf(pDest: filename, maxLen: 260, pFormat: "screenshots/%s/%s", base, cl_snapshot_subdirname);
      g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: filename, a3: "DEFAULT_WRITE_PATH");
    }
    if ( cl_snapshotname[0] != 0 )
    {
      V_strncpy(pDest: base, pSrc: cl_snapshotname, maxLen: 260);
      V_snprintf(pDest: filename, maxLen: 260, pFormat: "screenshots/%s%s", base, extension);
      v10 = 0;
      do
        V_snprintf(pDest: renamedfile, maxLen: 260, pFormat: "screenshots/%s_%04d%s", base, v10++, extension);
      while ( g_pFileSystem->GetFileTime(this: &g_pFileSystem->IBaseFileSystem, a2: renamedfile, a3: nullptr) != 0 );
      if ( v10 > 0 )
        g_pFileSystem->RenameFile(this: g_pFileSystem, a2: filename, a3: renamedfile, a4: "DEFAULT_WRITE_PATH");
      CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&cl_screenshotname.IConVar, value: defaultValue);
    }
    else
    {
      do
      {
        v11 = cl_snapshotnum++;
        if ( cl_snapshot_subdirname[0] != 0 )
          V_snprintf(
            pDest: filename,
            maxLen: 260,
            pFormat: "screenshots/%s/%s/%s%04d%s",
            base,
            cl_snapshot_subdirname,
            base,
            v11,
            extension);
        else
          V_snprintf(pDest: filename, maxLen: 260, pFormat: "screenshots/%s%04d%s", base, v11, extension);
      }
      while ( g_pFileSystem->GetFileTime(this: &g_pFileSystem->IBaseFileSystem, a2: filename, a3: "DEFAULT_WRITE_PATH") != 0 );
    }
    if ( cl_snapshot_fullpathname[0] != 0 )
    {
      V_strncpy(pDest: filename, pSrc: cl_snapshot_fullpathname, maxLen: 260);
      cl_snapshot_fullpathname[0] = 0;
    }
    v12 = videomode->__vftable;
    if ( cl_takejpeg )
    {
      ((void (__cdecl *)(char *, int))v12->TakeSnapshotJPEG)(a1: filename, a2: cl_jpegquality);
      CServerRemoteAccess::UploadScreenshot(this: &g_ServerRemoteAccess, pFileName: filename);
    }
    else
    {
      ((void (__cdecl *)(char *))v12->TakeSnapshotTGA)(a1: filename);
    }
    cl_takesnapshot = false;
    CTestScriptMgr::CheckPoint(this: &g_TestScriptMgr, pName: "screenshot");
    materials->AllowThreading(this: materials, a2: bEnabled, a3: g_nMaterialSystemThread);
  }
  if ( cl_movieinfo.moviename[0] != 0 && !Con_IsVisible() && !scr_drawloading )
  {
    videomode->WriteMovieFrame(this: videomode, a2: &cl_movieinfo);
    ++cl_movieinfo.movieframe;
  }
  v13 = 0;
  if ( host_syncfps.m_pParent != nullptr && host_syncfps.m_pParent->m_Value.m_nValue != 0 )
  {
    m_pParent = host_framerate.m_pParent;
    if ( host_framerate.m_pParent->m_Value.m_fValue != 0.0 )
    {
      v13 = 1;
      v14 = _Plat_FloatTime(a1: host_framerate.m_pParent) - flLastTime;
      if ( v14 >= 0.1 )
        v14 = 0.1;
      v15 = 1.0 / fabs(host_framerate.m_pParent->m_Value.m_fValue) - v14;
      if ( v15 > 0.0 )
        Sys_Sleep(msec: (int)(v15 * 1000.0));
    }
  }
  if ( !bReadPixelsFromFrontBuffer )
    Shader_SwapBuffers();
  if ( v13 != 0 )
    flLastTime = _Plat_FloatTime(a1: m_pParent);
  saverestore->UpdateSaveGameScreenshots(this: saverestore);
  EngineTool_UpdateScreenshot();
}

//------------------------------------------------------------------------------
// Address: 0x1008A9E0
// Name: void CL_EndMovie(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_EndMovie()
{
  if ( cl_movieinfo.moviename[0] != 0 )
  {
    ConVar::SetValue(this: (ConVar *)&host_framerate.IConVar, value: s_flPreviousHostFramerate);
    s_flPreviousHostFramerate = 0.0;
    SND_MovieEnd();
    if ( (cl_movieinfo.type & 2) != 0 || (cl_movieinfo.type & 8) != 0 )
    {
      avi->FinishAVI(this: avi, a2: g_hCurrentAVI);
      g_hCurrentAVI = -1;
    }
    cl_movieinfo.moviename[0] = 0;
    cl_movieinfo.movieframe = 0;
    cl_movieinfo.type = 5;
    cl_movieinfo.jpeg_quality = 50;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008AA70
// Name: endmovie
// Source: json
//------------------------------------------------------------------------------
void __cdecl endmovie()
{
  if ( cl_movieinfo.moviename[0] != 0 )
  {
    CL_EndMovie();
    ConMsg(a1: "Stopped recording movie...\n");
  }
  else
  {
    ConMsg(a1: "No movie started.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008AAA0
// Name: struct dlight_t __near * CL_AllocDlight(int)
// Source: json
//------------------------------------------------------------------------------
dlight_t *__cdecl CL_AllocDlight(int key)
{
  int v2; // esi
  int *p_key; // eax
  float *p_die; // edi
  CClientState *BaseLocalClient; // eax
  float v6; // xmm0_4
  int v7; // edx
  float *p_radius; // ecx
  float *v9; // ecx
  float keya; // [esp+14h] [ebp+8h]

  if ( key != 0 )
  {
    v2 = 0;
    p_key = &cl_dlights[0].key;
    while ( *p_key != key )
    {
      p_key += 17;
      ++v2;
      if ( (int)p_key >= (int)&cl_elights[0].key )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v2 = 0;
    p_die = &cl_dlights[0].die;
    while ( 1 )
    {
      keya = *p_die;
      BaseLocalClient = GetBaseLocalClient();
      if ( CClientState::GetTime(this: BaseLocalClient) > (double)keya )
        break;
      p_die += 17;
      ++v2;
      if ( (int)p_die >= (int)&cl_elights[0].die )
      {
        if ( cl_retire_low_priority_lights.m_pParent == nullptr
          || cl_retire_low_priority_lights.m_pParent->m_Value.m_nValue == 0
          || key >= 1677721600 )
        {
          goto LABEL_53;
        }
        v2 = -1;
        v6 = 0.0;
        v7 = 1;
        p_radius = &cl_dlights[1].radius;
        do
        {
          if ( *((int *)p_radius + 5) >= 1677721600 && (v6 == 0.0 || v6 > *p_radius) )
          {
            v6 = *p_radius;
            v2 = v7;
          }
          if ( *((int *)p_radius + 22) >= 1677721600 && (v6 == 0.0 || v6 > p_radius[17]) )
          {
            v6 = p_radius[17];
            v2 = v7 + 1;
          }
          if ( *((int *)p_radius + 39) >= 1677721600 && (v6 == 0.0 || v6 > p_radius[34]) )
          {
            v6 = p_radius[34];
            v2 = v7 + 2;
          }
          if ( *((int *)p_radius + 56) >= 1677721600 && (v6 == 0.0 || v6 > p_radius[51]) )
          {
            v6 = p_radius[51];
            v2 = v7 + 3;
          }
          if ( *((int *)p_radius + 73) >= 1677721600 && (v6 == 0.0 || v6 > p_radius[68]) )
          {
            v6 = p_radius[68];
            v2 = v7 + 4;
          }
          if ( *((int *)p_radius + 90) >= 1677721600 && (v6 == 0.0 || v6 > p_radius[85]) )
          {
            v6 = p_radius[85];
            v2 = v7 + 5;
          }
          if ( *((int *)p_radius + 107) >= 1677721600 && (v6 == 0.0 || v6 > p_radius[102]) )
          {
            v6 = p_radius[102];
            v2 = v7 + 6;
          }
          if ( *((int *)p_radius + 124) >= 1677721600 && (v6 == 0.0 || v6 > p_radius[119]) )
          {
            v6 = p_radius[119];
            v2 = v7 + 7;
          }
          p_radius += 136;
          v7 += 8;
        }
        while ( (int)p_radius < (int)&cl_dlights[25].radius );
        if ( v7 < 32 )
        {
          v9 = &cl_dlights[v7].radius;
          do
          {
            if ( *((int *)v9 + 5) >= 1677721600 && (v6 == 0.0 || v6 > *v9) )
            {
              v6 = *v9;
              v2 = v7;
            }
            v9 += 17;
            ++v7;
          }
          while ( (int)v9 < (int)&cl_elights[0].radius );
        }
        if ( v2 == -1 )
LABEL_53:
          v2 = 0;
        break;
      }
    }
  }
  R_MarkDLightNotVisible(dlight: v2);
  memset(dst: (unsigned __int8 *)&cl_dlights[v2], value: 0, count: sizeof(dlight_t));
  cl_dlights[v2].key = key;
  g_bActiveDlights = true;
  r_dlightchanged |= 1 << v2;
  r_dlightactive |= 1 << v2;
  return &cl_dlights[v2];
}

//------------------------------------------------------------------------------
// Address: 0x1008ACF0
// Name: struct dlight_t __near * CL_AllocElight(int)
// Source: json
//------------------------------------------------------------------------------
dlight_t *__cdecl CL_AllocElight(int key)
{
  int v2; // ecx
  int *p_key; // eax
  int v4; // edi
  float *p_die; // esi
  CClientState *BaseLocalClient; // eax
  int v7; // esi
  float v8; // xmm0_4
  int v9; // edx
  float *p_radius; // ecx
  int v11; // eax
  dlight_t *v12; // esi
  float keya; // [esp+10h] [ebp+8h]

  if ( key != 0 )
  {
    v2 = 0;
    p_key = &cl_elights[0].key;
    while ( *p_key != key )
    {
      p_key += 17;
      ++v2;
      if ( (int)p_key >= (int)&g_DLightLeafAccessors[1].m_flDistToExitLeafSqr )
        goto LABEL_5;
    }
    v11 = v2;
  }
  else
  {
LABEL_5:
    v4 = 0;
    p_die = &cl_elights[0].die;
    do
    {
      keya = *p_die;
      BaseLocalClient = GetBaseLocalClient();
      if ( CClientState::GetTime(this: BaseLocalClient) > (double)keya )
      {
        v11 = v4;
        goto LABEL_30;
      }
      p_die += 17;
      ++v4;
    }
    while ( (int)p_die < (int)&g_DLightLeafAccessors[1].m_vCachedPos.x );
    if ( cl_retire_low_priority_lights.m_pParent == nullptr
      || cl_retire_low_priority_lights.m_pParent->m_Value.m_nValue == 0
      || key >= 1677721600 )
    {
      goto LABEL_29;
    }
    v7 = -1;
    v8 = 0.0;
    v9 = 1;
    p_radius = &cl_elights[1].radius;
    do
    {
      if ( *((int *)p_radius + 5) >= 1677721600 && (v8 == 0.0 || v8 > *p_radius) )
      {
        v8 = *p_radius;
        v7 = v9;
      }
      if ( *((int *)p_radius + 22) >= 1677721600 && (v8 == 0.0 || v8 > p_radius[17]) )
      {
        v8 = p_radius[17];
        v7 = v9 + 1;
      }
      if ( *((int *)p_radius + 39) >= 1677721600 && (v8 == 0.0 || v8 > p_radius[34]) )
      {
        v8 = p_radius[34];
        v7 = v9 + 2;
      }
      p_radius += 51;
      v9 += 3;
    }
    while ( (int)p_radius < (int)&g_DLightLeafAccessors[0].m_flDistToExitLeafSqr );
    if ( v7 != -1 )
      v11 = v7;
    else
LABEL_29:
      v11 = 0;
  }
LABEL_30:
  v12 = &cl_elights[v11];
  memset(dst: (unsigned __int8 *)v12, value: 0, count: sizeof(dlight_t));
  v12->key = key;
  g_bActiveElights = true;
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1008AE30
// Name: void CL_DecayLights(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_DecayLights()
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  if ( CClientState::GetFrameTime(this: BaseLocalClient) > 0.0 )
    CL_UpdateDAndELights(bUpdateDecay: true);
}

//------------------------------------------------------------------------------
// Address: 0x1008AE50
// Name: void CL_SendMove(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_SendMove()
{
  int *p_chokedcommands; // esi
  int v1; // edi
  int chokedcommands; // esi
  int v3; // ecx
  int v4; // esi
  int v5; // edx
  bool v6; // al
  CClientState *LocalClient; // eax
  unsigned __int8 data[4000]; // [esp+8h] [ebp-FFCh] BYREF
  CLC_Move moveMsg; // [esp+FA8h] [ebp-5Ch] BYREF
  BOOL isnewcmd; // [esp+1000h] [ebp-4h]

  p_chokedcommands = &GetBaseLocalClient()->chokedcommands;
  v1 = GetBaseLocalClient()->lastoutgoingcommand + *p_chokedcommands + 1;
  chokedcommands = GetBaseLocalClient()->chokedcommands;
  if ( !splitscreen->IsDisconnecting(this: splitscreen, a2: 0) )
  {
    moveMsg.m_NetChannel = nullptr;
    moveMsg.__vftable = (CLC_Move_vtbl *)&CLC_Move::`vftable';
    moveMsg.m_DataIn.m_bOverflow = false;
    moveMsg.m_DataIn.m_pDebugName = nullptr;
    moveMsg.m_DataIn.m_nDataBits = -1;
    moveMsg.m_DataIn.m_nDataBytes = 0;
    bf_write::bf_write(this: &moveMsg.m_DataOut);
    moveMsg.m_bReliable = false;
    bf_write::StartWriting(this: &moveMsg.m_DataOut, pData: data, nBytes: 4000, iStartBit: 0, nBits: -1);
    v3 = chokedcommands + 1;
    moveMsg.m_nBackupCommands = 2;
    if ( chokedcommands + 1 >= 0 )
    {
      if ( v3 > 15 )
        v3 = 15;
    }
    else
    {
      v3 = 0;
    }
    v4 = v1 - v3 - 1;
    v5 = -1;
    moveMsg.m_nNewCommands = v3;
    v6 = true;
    if ( v4 > v1 )
      goto LABEL_13;
    do
    {
      LOBYTE(isnewcmd) = v4 >= v1 - moveMsg.m_nNewCommands + 1;
      v6 = v6
        && g_ClientDLL->WriteUsercmdDeltaToBuffer(
             this: g_ClientDLL,
             a2: 0,
             a3: &moveMsg.m_DataOut,
             a4: v5,
             a5: v4,
             a6: isnewcmd);
      v5 = v4++;
    }
    while ( v4 <= v1 );
    if ( v6 )
    {
LABEL_13:
      LocalClient = GetLocalClient(nSlot: -1);
      LocalClient->m_NetChannel->SendNetMsg(this: LocalClient->m_NetChannel, a2: &moveMsg, a3: false, a4: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008AF80
// Name: void CL_Move(float,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall CL_Move(int a1@<edi>, float accumulated_extra_samples, bool bFinalTick)
{
  CClientState *BaseLocalClient; // esi
  bool (__thiscall *IsPlayingBack)(IDemoPlayer *); // edx
  int v5; // ebx
  IBaseClientDLL_vtbl *v6; // edi
  bool IsPaused; // al
  double v8; // st7
  double v9; // st7
  double v10; // st7
  IEngineVGuiInternal *v11; // eax
  INetChannel *m_NetChannel; // ecx
  double v13; // st7
  float interval_per_tick; // xmm0_4
  long double v15; // st5
  long double v16; // st4
  void **v18; // [esp+24h] [ebp-24h] BYREF
  con_nprint_s np; // [esp+28h] [ebp-20h] BYREF
  float maxDelta; // [esp+40h] [ebp-8h]
  bool bSendPacket; // [esp+47h] [ebp-1h]

  BaseLocalClient = GetBaseLocalClient();
  if ( BaseLocalClient->m_nSignonState < 2 || Host_ShouldRun() == 0 )
    return;
  IsPlayingBack = demoplayer->IsPlayingBack;
  bSendPacket = true;
  if ( IsPlayingBack(this: demoplayer) )
  {
    if ( !BaseLocalClient->ishltv )
      return;
    bSendPacket = false;
  }
  if ( (!BaseLocalClient->m_NetChannel->IsLoopback(this: BaseLocalClient->m_NetChannel)
     || host_limitlocal.m_pParent != nullptr && host_limitlocal.m_pParent->m_Value.m_nValue != 0)
    && (BaseLocalClient->m_flNextCmdTime > net_time
     || !BaseLocalClient->m_NetChannel->CanPacket(this: BaseLocalClient->m_NetChannel)
     || !bFinalTick) )
  {
    bSendPacket = false;
  }
  if ( BaseLocalClient->m_nSignonState == 6 )
  {
    v5 = BaseLocalClient->lastoutgoingcommand + BaseLocalClient->chokedcommands + 1;
    if ( !splitscreen->IsDisconnecting(this: splitscreen, a2: 0) )
    {
      v6 = g_ClientDLL->__vftable;
      IsPaused = CClientState::IsPaused(this: BaseLocalClient);
      ((void (__thiscall *)(IBaseClientDLL *, int, _DWORD, bool))v6->CreateMove)(
        a1: g_ClientDLL,
        a2: v5,
        a3: host_state.interval_per_tick - accumulated_extra_samples,
        a4: !IsPaused);
      if ( demorecorder->IsRecording(this: demorecorder) )
        demorecorder->RecordUserInput(this: demorecorder, a2: v5);
    }
    if ( !bSendPacket )
    {
      BaseLocalClient->m_NetChannel->SetChoked(this: BaseLocalClient->m_NetChannel);
      ++BaseLocalClient->chokedcommands;
      return;
    }
    CL_SendMove();
  }
  if ( !bSendPacket )
    return;
  if ( ((unsigned __int8 (__thiscall *)(INetChannel *, int))BaseLocalClient->m_NetChannel->IsTimingOut)(
         a1: BaseLocalClient->m_NetChannel,
         a2: a1) == 0
    || demoplayer->IsPlayingBack(this: demoplayer) )
  {
    goto LABEL_28;
  }
  if ( BaseLocalClient->m_nSignonState == 6 )
  {
    np.fixed_width_font = false;
    np.time_to_live = 1.0;
    np.color[0] = 1.0;
    np.index = 2;
    np.color[1] = 0.2;
    np.color[2] = 0.2;
    Con_NXPrintf(info: &np, fmt: "WARNING:  Connection Problem");
    maxDelta = BaseLocalClient->m_NetChannel->GetTimeoutSeconds(this: BaseLocalClient->m_NetChannel);
    v8 = ((double (__thiscall *)(INetChannel *))BaseLocalClient->m_NetChannel->GetTimeSinceLastReceived)(a1: BaseLocalClient->m_NetChannel);
    if ( maxDelta - v8 <= 0.0 )
    {
      maxDelta = 0.0;
      v10 = 0.0;
    }
    else
    {
      v9 = ((double (__thiscall *)(INetChannel *))BaseLocalClient->m_NetChannel->GetTimeSinceLastReceived)(a1: BaseLocalClient->m_NetChannel);
      v10 = maxDelta - v9;
    }
    np.index = 3;
    Con_NXPrintf(info: &np, fmt: "Auto-disconnect in %.1f seconds", v10);
    v11 = EngineVGui();
    v11->NeedConnectionProblemWaitScreen(this: v11);
    CBaseClientState::ForceFullUpdate(this: BaseLocalClient, pchReason: "connection problem");
LABEL_28:
    if ( BaseLocalClient->m_nSignonState == 6 )
    {
      LODWORD(np.color[1]) = BaseLocalClient->m_nDeltaTick;
      m_NetChannel = BaseLocalClient->m_NetChannel;
      np.color[2] = host_frametime_unbounded;
      np.time_to_live = 0.0;
      v18 = &NET_Tick::`vftable';
      LOBYTE(np.index) = 0;
      *(float *)&np.fixed_width_font = host_frametime_stddeviation;
      m_NetChannel->SendNetMsg(this: m_NetChannel, a2: (INetMessage *)&v18, a3: false, a4: false);
    }
  }
  BaseLocalClient->lastoutgoingcommand = BaseLocalClient->m_NetChannel->SendDatagram(
                                           this: BaseLocalClient->m_NetChannel,
                                           a2: nullptr);
  BaseLocalClient->chokedcommands = 0;
  if ( BaseLocalClient->m_nSignonState == 6 )
  {
    v13 = 1.0 / ((double (__thiscall *)(ConVar_ServerBounded *))cl_cmdrate->GetFloat)(a1: cl_cmdrate);
    maxDelta = v13;
    if ( v13 <= host_state.interval_per_tick )
      interval_per_tick = maxDelta;
    else
      interval_per_tick = host_state.interval_per_tick;
    maxDelta = interval_per_tick;
    v15 = net_time - BaseLocalClient->m_flNextCmdTime;
    v16 = 0.0;
    if ( v15 < 0.0 || (v16 = v15, v15 <= maxDelta) )
      BaseLocalClient->m_flNextCmdTime = net_time + v13 - v16;
    else
      BaseLocalClient->m_flNextCmdTime = net_time + v13 - maxDelta;
  }
  else
  {
    BaseLocalClient->m_flNextCmdTime = net_time + 0.2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C2B0
// Name: void CL_DispatchSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_DispatchSounds()
{
  int i; // esi

  for ( i = CUtlRBTree<SoundInfo_t,int,bool (__cdecl *)(SoundInfo_t const &,SoundInfo_t const &),CUtlMemory<UtlRBTreeNode_t<SoundInfo_t,int>,int>>::FirstInorder(this: &g_SoundMessages);
        i != -1;
        i = CUtlRBTree<SoundInfo_t,int,bool (__cdecl *)(SoundInfo_t const &,SoundInfo_t const &),CUtlMemory<UtlRBTreeNode_t<SoundInfo_t,int>,int>>::NextInorder(
              this: &g_SoundMessages,
              i) )
  {
    if ( &g_SoundMessages.m_Elements.m_pMemory[i] != (UtlRBTreeNode_t<SoundInfo_t,int> *)-16 )
      CL_DispatchSound(sound: &g_SoundMessages.m_Elements.m_pMemory[i].m_Data);
  }
  CUtlRBTree<SoundInfo_t,int,bool (__cdecl *)(SoundInfo_t const &,SoundInfo_t const &),CUtlMemory<UtlRBTreeNode_t<SoundInfo_t,int>,int>>::RemoveAll(this: &g_SoundMessages);
}

//------------------------------------------------------------------------------
// Address: 0x1008C300
// Name: void CL_Retry(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_Retry()
{
  CVTFTexture *p_m_Remote; // edi
  int v1; // esi
  Remote_t *v2; // edi
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  vgui::CTreeViewListControl *v7; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v9; // [esp-Ch] [ebp-24h]
  const char *v10; // [esp-Ch] [ebp-24h]
  CUtlString cnx; // [esp+4h] [ebp-14h] BYREF
  CVTFTexture *v12; // [esp+14h] [ebp-4h]

  p_m_Remote = (CVTFTexture *)&GetBaseLocalClient()->m_Remote;
  v12 = p_m_Remote;
  if ( vgui::Image::GetWide(this: p_m_Remote) > 0 )
  {
    ConMsg(a1: "Commencing connection retry to ");
    CUtlString::CUtlString(this: &cnx);
    v1 = 0;
    if ( vgui::Image::GetWide(this: p_m_Remote) > 0 )
    {
      while ( 1 )
      {
        v2 = CAddressList::Get(this: (CAddressList *)p_m_Remote, index: v1);
        v9 = CUtlString::operator char const *(this: &v2->m_szRetryAddress);
        v3 = CUtlString::operator char const *(this: &v2->m_szAlias);
        ConMsg(a1: "%s(%s)", v3, v9);
        v4 = CUtlString::operator char const *(this: &v2->m_szRetryAddress);
        v5 = va(format: "\"%s\" ", v4);
        CUtlString::operator+=(this: &cnx, rhs: v5);
        if ( ++v1 >= vgui::Image::GetWide(this: v12) )
          break;
        p_m_Remote = v12;
      }
    }
    ConMsg(a1: "\n");
    v6 = CUtlString::operator char const *(this: &cnx);
    v10 = va(format: "connect %s\n", v6);
    TraceType = CTraceFilter::GetTraceType(this: v7);
    Cbuf_AddText(eTarget: TraceType, pText: v10, nTickDelay: 0);
    cnx.m_Storage.m_nActualLength = 0;
    if ( cnx.m_Storage.m_Memory.m_nGrowSize >= 0 && cnx.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: cnx.m_Storage.m_Memory.m_pMemory);
  }
  else
  {
    ConMsg(a1: "Can't retry, no previous connection\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C410
// Name: retry
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl retry()
{
  CL_Retry();
}

//------------------------------------------------------------------------------
// Address: 0x1008C420
// Name: class CPureServerWhitelist __near * CL_LoadWhitelist(class INetworkStringTable __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPureServerWhitelist *__cdecl CL_LoadWhitelist(INetworkStringTable *pTable, const char *pName)
{
  INetworkStringTable *v2; // esi
  int v3; // eax
  const void *v4; // eax
  CPureServerWhitelist *v5; // esi
  CUtlBuffer buf; // [esp+4h] [ebp-30h] BYREF

  v2 = pTable;
  v3 = pTable->FindStringIndex(this: pTable, a2: pName);
  if ( v3 == 0xFFFF )
    return nullptr;
  v4 = v2->GetStringUserData(this: v2, a2: v3, a3: (int *)&pTable);
  if ( v4 == nullptr )
    return nullptr;
  CUtlBuffer::CUtlBuffer(this: &buf, pBuffer: v4, nSize: (int)pTable, nFlags: 8);
  v5 = CPureServerWhitelist::Create(pFileSystem: g_pFullFileSystem);
  CPureServerWhitelist::Decode(this: v5, &buf);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1008C4B0
// Name: void CL_CheckForPureServerWhitelist(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CL_CheckForPureServerWhitelist(int a1@<edi>)
{
  CClientState *BaseLocalClient; // eax
  CPureServerWhitelist *Whitelist; // eax
  CPureServerWhitelist *v3; // esi

  if ( GetBaseLocalClient()->m_nMaxClients > 1 && !GetBaseLocalClient()->ishltv )
  {
    if ( GetBaseLocalClient()->m_pServerStartupTable != nullptr
      && (BaseLocalClient = GetBaseLocalClient(),
          Whitelist = CL_LoadWhitelist(pTable: BaseLocalClient->m_pServerStartupTable, pName: "PureServerWhitelist"),
          v3 = Whitelist,
          Whitelist != nullptr) )
    {
      if ( CPureServerWhitelist::IsInFullyPureMode(this: Whitelist) )
        _Msg(a1: "Got pure server whitelist: sv_pure = 2.\n");
      else
        _Msg(a1: "Got pure server whitelist: sv_pure = 1.\n");
      CL_HandlePureServerWhitelist(a1, pWhitelist: v3);
    }
    else
    {
      _Msg(a1: "No pure server whitelist. sv_pure = 0\n");
      CL_HandlePureServerWhitelist(a1, pWhitelist: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C5A0
// Name: void SplitString(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SplitString(const char *pchString, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *list)
{
  const char *v2; // edx
  char *v3; // eax
  CUtlString *v4; // eax
  int m_Size; // edi
  const CUtlString *v6; // ebx
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v9; // eax
  CUtlString *v10; // ecx
  const CUtlString *v11; // eax
  char token[1024]; // [esp+4h] [ebp-510h] BYREF
  characterset_t breakOnSpaces; // [esp+404h] [ebp-110h] BYREF
  CUtlString v14; // [esp+504h] [ebp-10h] BYREF

  CharacterSetBuild(pSetBuffer: &breakOnSpaces, pszSetString: " ");
  memset(token, 0, sizeof(token));
  v2 = pchString;
  v3 = token;
  while ( *v2 != 0 )
  {
    if ( (unsigned int)(v3 - token) >= 0x3FF )
      break;
    if ( breakOnSpaces.set[*v2] != 0 )
    {
      *v3 = 0;
      v4 = CUtlString::CUtlString(this: &v14, pString: token);
      m_Size = list->m_Size;
      v6 = v4;
      m_nAllocationCount = list->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CPortalRect,int>::Grow(
          this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)list,
          num: m_Size - m_nAllocationCount + 1);
      ++list->m_Size;
      m_pMemory = list->m_Memory.m_pMemory;
      v9 = list->m_Size - m_Size - 1;
      list->m_pElements = list->m_Memory.m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v9);
      v10 = &list->m_Memory.m_pMemory[m_Size];
      if ( v10 != nullptr )
        CUtlString::CUtlString(this: v10, string: v6);
      v14.m_Storage.m_nActualLength = 0;
      if ( v14.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v14.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14.m_Storage.m_Memory.m_pMemory);
          v14.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v14.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v2 = ++pchString;
      v3 = token;
    }
    else
    {
      *v3++ = *v2;
      pchString = ++v2;
    }
  }
  *v3 = 0;
  if ( _V_strlen(str: token) > 0 )
  {
    v11 = CUtlString::CUtlString(this: &v14, pString: token);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: list, elem: list->m_Size, src: v11);
    v14.m_Storage.m_nActualLength = 0;
    if ( v14.m_Storage.m_Memory.m_nGrowSize >= 0 && v14.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14.m_Storage.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C730
// Name: public: NET_SetConVar::NET_SetConVar(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
NET_SetConVar *__thiscall NET_SetConVar::NET_SetConVar(NET_SetConVar *this, const char *name, const char *value)
{
  NetMessageCvar_t cvar; // [esp+8h] [ebp-208h] BYREF

  this->m_NetChannel = nullptr;
  this->m_bReliable = true;
  this->__vftable = (NET_SetConVar_vtbl *)&NET_SetConVar::`vftable';
  this->m_ConVars.m_Memory.m_pMemory = nullptr;
  this->m_ConVars.m_Memory.m_nAllocationCount = 0;
  this->m_ConVars.m_Memory.m_nGrowSize = 0;
  this->m_ConVars.m_Size = 0;
  this->m_ConVars.m_pElements = nullptr;
  V_strncpy(pDest: cvar.name, pSrc: name, maxLen: 260);
  V_strncpy(pDest: cvar.value, pSrc: value, maxLen: 260);
  CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int>>::InsertBefore(
    this: &this->m_ConVars,
    elem: this->m_ConVars.m_Size,
    src: &cvar);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008C7B0
// Name: setinfo
// Source: json
//------------------------------------------------------------------------------
void __usercall setinfo(int a1@<ebx>, int a2@<edi>, int a3@<esi>, const CCommand *args)
{
  const char *v4; // ebx
  const char *v5; // edi
  ConVar *v6; // esi
  EUniverse SteamUniverse; // eax
  int v8; // eax
  char *v9; // esi
  ConVar *v10; // eax
  CClientState *BaseLocalClient; // eax
  NET_SetConVar convar; // [esp+0h] [ebp-2Ch] BYREF
  ConVarRef sv_cheats; // [esp+24h] [ebp-8h] BYREF

  if ( args->m_nArgc != 3 )
  {
    _Msg(a1: "Syntax: setinfo <key> <value>\n");
    return;
  }
  v4 = args->m_ppArgv[2];
  v5 = args->m_ppArgv[1];
  v6 = (ConVar *)((int (__thiscall *)(ICvar *, const char *, int, int, int))g_pCVar->FindCommandBase_2)(
                   a1: g_pCVar,
                   a2: v5,
                   a3: a2,
                   a4: a3,
                   a5: a1);
  ConVarRef::ConVarRef(this: &sv_cheats, pName: "sv_cheats");
  if ( v6 == nullptr )
  {
    v8 = _V_strlen(str: v5);
    v9 = (char *)MemAlloc_Alloc(nSize: v8 + 1);
    _V_strcpy(dest: v9, src: v5);
    v10 = (ConVar *)MemAlloc_Alloc(nSize: 0x58u);
    if ( v10 != nullptr )
      v6 = ConVar::ConVar(
             this: v10,
             pName: v9,
             pDefaultValue: defaultValue,
             flags: 512,
             pHelpString: "Custom user info value");
    else
      v6 = nullptr;
LABEL_17:
    v6->SetValue_4(this: &v6->IConVar, a2: v4);
    if ( GetBaseLocalClient()->m_nSignonState >= 2 )
    {
      NET_SetConVar::NET_SetConVar(this: &convar, name: v5, value: v4);
      BaseLocalClient = GetBaseLocalClient();
      BaseLocalClient->m_NetChannel->SendNetMsg(this: BaseLocalClient->m_NetChannel, a2: &convar, a3: false, a4: false);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&convar.m_ConVars);
    }
    return;
  }
  if ( v6->IsCommand(this: v6) )
  {
    _Msg(a1: "Name %s is already registered as console command\n", v5);
    return;
  }
  if ( !v6->IsFlagSet(this: v6, a2: 512) )
  {
    _Msg(a1: "Convar %s is already registered but not as user info value\n", v5);
    return;
  }
  SteamUniverse = GetSteamUniverse();
  if ( SteamUniverse == k_EUniverseBeta || SteamUniverse == k_EUniverseDev || !v6->IsFlagSet(this: v6, a2: 2) )
  {
    if ( v6->IsFlagSet(this: v6, a2: 0x4000) && sv_cheats.m_pConVarState->m_Value.m_nValue == 0 )
    {
      _Msg(a1: "Convar %s is marked as cheat and cheats are off\n", v5);
      return;
    }
    goto LABEL_17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C930
// Name: void CL_AddSound(struct SoundInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_AddSound(const SoundInfo_t *sound)
{
  int v1; // eax
  int v2; // edx
  int v3; // edi
  UtlRBTreeNode_t<SoundInfo_t,int> *v4; // ecx
  int v5; // edx
  SoundInfo_t *p_m_Data; // edi
  int parent; // [esp+8h] [ebp-8h] BYREF
  bool leftchild; // [esp+Fh] [ebp-1h] BYREF

  parent = -1;
  leftchild = false;
  CUtlRBTree<SoundInfo_t,int,bool (__cdecl *)(SoundInfo_t const &,SoundInfo_t const &),CUtlMemory<UtlRBTreeNode_t<SoundInfo_t,int>,int>>::FindInsertionPosition(
    this: &g_SoundMessages,
    insert: sound,
    &parent,
    &leftchild);
  v1 = CUtlRBTree<SoundInfo_t,int,bool (__cdecl *)(SoundInfo_t const &,SoundInfo_t const &),CUtlMemory<UtlRBTreeNode_t<SoundInfo_t,int>,int>>::NewNode(this: &g_SoundMessages);
  v2 = parent;
  v3 = v1;
  v4 = &g_SoundMessages.m_Elements.m_pMemory[v1];
  v4->m_Parent = parent;
  v4->m_Right = -1;
  v4->m_Left = -1;
  v4->m_Tag = 0;
  if ( v2 == -1 )
  {
    g_SoundMessages.m_Root = v1;
  }
  else
  {
    v5 = v2;
    if ( leftchild )
      g_SoundMessages.m_Elements.m_pMemory[v5].m_Left = v1;
    else
      g_SoundMessages.m_Elements.m_pMemory[v5].m_Right = v1;
  }
  CUtlRBTree<SoundInfo_t,int,bool (__cdecl *)(SoundInfo_t const &,SoundInfo_t const &),CUtlMemory<UtlRBTreeNode_t<SoundInfo_t,int>,int>>::InsertRebalance(
    this: &g_SoundMessages,
    elem: v1);
  ++g_SoundMessages.m_NumElements;
  p_m_Data = &g_SoundMessages.m_Elements.m_pMemory[v3].m_Data;
  if ( p_m_Data != nullptr )
    qmemcpy(p_m_Data, sound, sizeof(SoundInfo_t));
}

//------------------------------------------------------------------------------
// Address: 0x1008C9E0
// Name: connect_0
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall connect_0(int a1@<ebx>, const CCommand *args)
{
  int m_nArgv0Size; // eax
  const char *v3; // esi
  CUtlString *m_pMemory; // ebx
  const char *v5; // eax
  IEngineVGuiInternal *v6; // eax
  IEngineVGuiInternal *v7; // eax
  CClientState *LocalClient; // eax
  CUtlString *v9; // ecx
  const char *v10; // edi
  CClientState *BaseLocalClient; // esi
  const char *v12; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > argValues; // [esp+0h] [ebp-14h] BYREF

  if ( args->m_nArgc >= 2 )
  {
    m_nArgv0Size = args->m_nArgv0Size;
    v3 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( m_nArgv0Size == 0 )
      v3 = defaultValue;
    memset(&argValues, 0, sizeof(argValues));
    SplitString(pchString: v3, list: &argValues);
    if ( argValues.m_Size == 1 || argValues.m_Size == 2 )
    {
      m_pMemory = argValues.m_Memory.m_pMemory;
      v5 = CUtlString::operator char const *(this: argValues.m_Memory.m_pMemory);
      if ( V_strncmp(s1: v5, s2: "localhost", count: 9) != 0 )
      {
        Host_Disconnect(bShowMainMenu: false);
        NET_SetMultiplayer(multiplayer: true);
        v6 = EngineVGui();
        ((void (__thiscall *)(IEngineVGuiInternal *, int))v6->EnabledProgressBarForNextLoad)(a1: v6, a2: a1);
        SCR_BeginLoadingPlaque(levelName: nullptr);
        v7 = EngineVGui();
        v7->UpdateProgressBar(this: v7, a2: PROGRESS_BEGINCONNECT, a3: true);
      }
      else
      {
        LocalClient = GetLocalClient(nSlot: -1);
        ((void (__thiscall *)(CClientState *, _DWORD, int))LocalClient->Disconnect)(a1: LocalClient, a2: 0, a3: a1);
      }
      v9 = m_pMemory + 1;
      if ( argValues.m_Size != 2 )
        v9 = m_pMemory;
      v10 = CUtlString::operator char const *(this: v9);
      BaseLocalClient = GetBaseLocalClient();
      v12 = CUtlString::operator char const *(this: m_pMemory);
      ((void (__thiscall *)(CClientState *, const char *, const char *, CUtlString *, int))BaseLocalClient->Connect)(
        a1: BaseLocalClient,
        a2: v12,
        a3: v10,
        a4: argValues.m_Memory.m_pMemory,
        a5: argValues.m_Memory.m_nAllocationCount);
      gfExtendedError = false;
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&argValues);
    }
    else
    {
      ConMsg(a1: "connect:  can't parse '%s'\n", v3);
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&argValues);
    }
  }
  else
  {
    ConMsg(a1: "Usage:  connect <server>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008CB10
// Name: connect_splitscreen
// Source: json
//------------------------------------------------------------------------------
void __usercall connect_splitscreen(int a1@<ebx>, int a2@<edi>, int a3@<esi>, const CCommand *args)
{
  int m_nArgv0Size; // eax
  const char *v5; // edi
  int m_Size; // esi
  CUtlString *m_pMemory; // edi
  const char *v8; // eax
  int v9; // eax
  int v10; // ebx
  const char *v11; // eax
  CClientState *LocalClient; // eax
  CUtlString *v13; // ecx
  CClientState *BaseLocalClient; // esi
  const char *v15; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > argValues; // [esp+0h] [ebp-14h] BYREF
  const CCommand *argsa; // [esp+1Ch] [ebp+8h]

  if ( args->m_nArgc >= 3 )
  {
    m_nArgv0Size = args->m_nArgv0Size;
    v5 = &args->m_pArgSBuffer[m_nArgv0Size];
    if ( m_nArgv0Size == 0 )
      v5 = defaultValue;
    memset(&argValues, 0, sizeof(argValues));
    SplitString(pchString: v5, list: &argValues);
    m_Size = argValues.m_Size;
    if ( argValues.m_Size == 2 || argValues.m_Size == 3 )
    {
      m_pMemory = argValues.m_Memory.m_pMemory;
      v8 = CUtlString::operator char const *(this: &argValues.m_Memory.m_pMemory[argValues.m_Size - 1]);
      v9 = V_atoi(str: v8);
      v10 = v9;
      if ( v9 > 0 )
      {
        if ( v9 <= host_state.max_splitscreen_players )
        {
          v11 = CUtlString::operator char const *(this: m_pMemory);
          if ( V_strncmp(s1: v11, s2: "localhost", count: 9) == 0 )
          {
            LocalClient = GetLocalClient(nSlot: -1);
            ((void (__thiscall *)(CClientState *, _DWORD, int, int, int))LocalClient->Disconnect)(
              a1: LocalClient,
              a2: 0,
              a3: a1,
              a4: a3,
              a5: a2);
            v13 = m_pMemory + 1;
            if ( m_Size != 3 )
              v13 = m_pMemory;
            argsa = (const CCommand *)CUtlString::operator char const *(this: v13);
            BaseLocalClient = GetBaseLocalClient();
            v15 = CUtlString::operator char const *(this: m_pMemory);
            BaseLocalClient->ConnectSplitScreen(this: BaseLocalClient, a2: v15, a3: (const char *)argsa, a4: v10);
            gfExtendedError = false;
          }
          CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&argValues);
        }
        else
        {
          ConMsg(a1: "Too many players\n");
          CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&argValues);
        }
      }
      else
      {
        ConMsg(a1: "Must have at least one player.\n");
        CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&argValues);
      }
    }
    else
    {
      ConMsg(a1: "connect_splitscreen:  can't parse '%s'\n", v5);
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&argValues);
    }
  }
  else
  {
    ConMsg(a1: "Usage:  connect <server> <# of players>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021201C
// Name: connect(x,x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall connect(SOCKET s, const struct sockaddr *name, int namelen)
{
  return __imp__connect@12(s, name, namelen);
}

//------------------------------------------------------------------------------
// Address: 0x103127D0
// Name: _dynamic_initializer_for__cl_resend__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_resend__()
{
  ConVar::ConVar(
    this: &cl_resend,
    pName: "cl_resend",
    pDefaultValue: "6",
    flags: 0x80000,
    pHelpString: "Delay in seconds before the client will resend the 'connect' attempt",
    bMin: true,
    fMin: 1.5,
    bMax: true,
    fMax: 20.0);
  return atexit(func: dynamic_atexit_destructor_for__cl_resend__);
}

//------------------------------------------------------------------------------
// Address: 0x10312820
// Name: _dynamic_initializer_for__cl_resend_timeout__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_resend_timeout__()
{
  ConVar::ConVar(
    this: &cl_resend_timeout,
    pName: "cl_resend_timeout",
    pDefaultValue: "60",
    flags: 0x80000,
    pHelpString: "Total time allowed for the client to resend the 'connect' attempt",
    bMin: true,
    fMin: 1.5,
    bMax: true,
    fMax: 20000.0);
  return atexit(func: dynamic_atexit_destructor_for__cl_resend_timeout__);
}

//------------------------------------------------------------------------------
// Address: 0x10312870
// Name: _dynamic_initializer_for__cl_name__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_name__()
{
  ConVar::ConVar(
    this: &cl_name,
    pName: "name",
    pDefaultValue: "unnamed",
    flags: (int)&loc_1000867F + 1,
    pHelpString: "Current user name",
    callback: (void (__cdecl *)(IConVar *, const char *, float))CL_NameCvarChanged);
  return atexit(func: dynamic_atexit_destructor_for__cl_name__);
}

//------------------------------------------------------------------------------
// Address: 0x103128D0
// Name: _dynamic_initializer_for__cl_interpolate__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_interpolate__()
{
  ConVar::ConVar(
    this: &cl_interpolate,
    pName: "cl_interpolate",
    pDefaultValue: "1.0",
    flags: 514,
    pHelpString: "Interpolate entities on the client.");
  return atexit(func: dynamic_atexit_destructor_for__cl_interpolate__);
}

//------------------------------------------------------------------------------
// Address: 0x10312900
// Name: _dynamic_initializer_for__cl_failremoteconnections__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_failremoteconnections__()
{
  ConVar::ConVar(
    this: &cl_failremoteconnections,
    pName: "cl_failremoteconnections",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Force connection attempts to time out");
  return atexit(func: dynamic_atexit_destructor_for__cl_failremoteconnections__);
}

//------------------------------------------------------------------------------
// Address: 0x10312EB0
// Name: _dynamic_initializer_for__cl_showdemooverlay__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_showdemooverlay__()
{
  ConVar::ConVar(
    this: &cl_showdemooverlay,
    pName: "cl_showdemooverlay",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "How often to flash demo recording/playback overlay (0 - disable overlay, -1 - show always)");
  return atexit(func: dynamic_atexit_destructor_for__cl_showdemooverlay__);
}

//------------------------------------------------------------------------------
// Address: 0x10313410
// Name: _dynamic_initializer_for__cl_entityreport__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_entityreport__()
{
  ConVar::ConVar(
    this: &cl_entityreport,
    pName: "cl_entityreport",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "For debugging, draw entity states to console");
  return atexit(func: dynamic_atexit_destructor_for__cl_entityreport__);
}

//------------------------------------------------------------------------------
// Address: 0x103134E0
// Name: _dynamic_initializer_for__cl_flushentitypacket__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_flushentitypacket__()
{
  ConVar::ConVar(
    this: &cl_flushentitypacket,
    pName: "cl_flushentitypacket",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "For debugging. Force the engine to flush an entity packet.");
  return atexit(func: dynamic_atexit_destructor_for__cl_flushentitypacket__);
}

//------------------------------------------------------------------------------
// Address: 0x103135C0
// Name: _dynamic_initializer_for__cl_LocalNetworkBackdoor__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_LocalNetworkBackdoor__()
{
  ConVar::ConVar(
    this: &cl_LocalNetworkBackdoor,
    pName: "cl_localnetworkbackdoor",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable network optimizations for single player games.");
  return atexit(func: dynamic_atexit_destructor_for__cl_LocalNetworkBackdoor__);
}

//------------------------------------------------------------------------------
// Address: 0x103135F0
// Name: _dynamic_initializer_for__cl_ignorepackets__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_ignorepackets__()
{
  ConVar::ConVar(
    this: &cl_ignorepackets,
    pName: "cl_ignorepackets",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Force client to ignore packets (for debugging).");
  return atexit(func: dynamic_atexit_destructor_for__cl_ignorepackets__);
}

//------------------------------------------------------------------------------
// Address: 0x10313620
// Name: _dynamic_initializer_for__cl_playback_screenshots__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_playback_screenshots__()
{
  ConVar::ConVar(
    this: &cl_playback_screenshots,
    pName: "cl_playback_screenshots",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Allows the client to playback screenshot and jpeg commands in demos.");
  return atexit(func: dynamic_atexit_destructor_for__cl_playback_screenshots__);
}

//------------------------------------------------------------------------------
// Address: 0x10313650
// Name: _dynamic_initializer_for__cl_dlights__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
const IClientRenderable **dynamic_initializer_for__cl_dlights__()
{
  int v0; // ecx
  const IClientRenderable **result; // eax

  v0 = 31;
  result = &cl_dlights[0].m_pExclusiveLightReceiver;
  do
  {
    *result = nullptr;
    result += 17;
    --v0;
  }
  while ( v0 >= 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10313700
// Name: _dynamic_initializer_for__cl_retire_low_priority_lights__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_retire_low_priority_lights__()
{
  ConVar::ConVar(
    this: &cl_retire_low_priority_lights,
    pName: "cl_retire_low_priority_lights",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Low priority dlights are replaced by high priority ones");
  return atexit(func: dynamic_atexit_destructor_for__cl_retire_low_priority_lights__);
}

//------------------------------------------------------------------------------
// Address: 0x10313800
// Name: _dynamic_initializer_for__cl_screenshotname__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_screenshotname__()
{
  ConVar::ConVar(
    this: &cl_screenshotname,
    pName: "cl_screenshotname",
    pDefaultValue: defaultValue,
    flags: 0,
    pHelpString: "Custom Screenshot name");
  return atexit(func: dynamic_atexit_destructor_for__cl_screenshotname__);
}

//------------------------------------------------------------------------------
// Address: 0x10313A10
// Name: _dynamic_initializer_for__cl_view_command__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_view_command__()
{
  ConCommand::ConCommand(
    this: &cl_view_command,
    pName: "cl_view",
    callback: cl_view,
    pHelpString: "Set the view entity index.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_view_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313A40
// Name: _dynamic_initializer_for__cl_showents_command__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_showents_command__()
{
  ConCommand::ConCommand(
    this: &cl_showents_command,
    pName: "cl_showents",
    callback: (void (__cdecl *)(const CCommand *))cl_showents,
    pHelpString: "Dump entity list to console.",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_showents_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313AA0
// Name: _dynamic_initializer_for__cl_language__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_language__()
{
  ConVar::ConVar(
    this: &cl_language,
    pName: "cl_language",
    pDefaultValue: "english",
    flags: 512,
    pHelpString: "Language (from Steam API)");
  return atexit(func: dynamic_atexit_destructor_for__cl_language__);
}

//------------------------------------------------------------------------------
// Address: 0x10313AD0
// Name: _dynamic_initializer_for__cl_cloud_settings__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_cloud_settings__()
{
  ConVar::ConVar(
    this: &cl_cloud_settings,
    pName: "cl_cloud_settings",
    pDefaultValue: "-1",
    flags: 16,
    pHelpString: "Cloud enabled from (from HKCU\\Software\\Valve\\Steam\\Apps\\appid\\Cloud)",
    callback: (void (__cdecl *)(IConVar *, const char *, float))CL_ChangeCloudSettingsCvar);
  return atexit(func: dynamic_atexit_destructor_for__cl_cloud_settings__);
}

//------------------------------------------------------------------------------
// Address: 0x10313B00
// Name: _dynamic_initializer_for__cl_fullupdate_command__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_fullupdate_command__()
{
  ConCommand::ConCommand(
    this: &cl_fullupdate_command,
    pName: "cl_fullupdate",
    callback: (void (__cdecl *)(const CCommand *))cl_fullupdate,
    pHelpString: "Forces the server to send a full update packet",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_fullupdate_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313B60
// Name: _dynamic_initializer_for__cl_precacheinfo_command__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_precacheinfo_command__()
{
  ConCommand::ConCommand(
    this: &cl_precacheinfo_command,
    pName: "cl_precacheinfo",
    callback: cl_precacheinfo,
    pHelpString: "Show precache info (client).",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_precacheinfo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313B90
// Name: _dynamic_initializer_for__cl_showevents__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_showevents__()
{
  ConVar::ConVar(
    this: &cl_showevents,
    pName: "cl_showevents",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Print event firing info in the console");
  return atexit(func: dynamic_atexit_destructor_for__cl_showevents__);
}

//------------------------------------------------------------------------------
// Address: 0x10313BC0
// Name: _dynamic_initializer_for__cl_showpluginmessages__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_showpluginmessages__()
{
  ConVar::ConVar(
    this: &cl_showpluginmessages,
    pName: "cl_showpluginmessages",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Allow plugins to display messages to you");
  return atexit(func: dynamic_atexit_destructor_for__cl_showpluginmessages__);
}

//------------------------------------------------------------------------------
// Address: 0x10313F60
// Name: _dynamic_initializer_for__cl_timeout__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_timeout__()
{
  ConVar::ConVar(
    this: &cl_timeout,
    pName: "cl_timeout",
    pDefaultValue: "30",
    flags: 128,
    pHelpString: "After this many seconds without receiving a packet from the server, the client will disconnect itself");
  return atexit(func: dynamic_atexit_destructor_for__cl_timeout__);
}

//------------------------------------------------------------------------------
// Address: 0x10313F90
// Name: _dynamic_initializer_for__cl_logofile__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_logofile__()
{
  ConVar::ConVar(
    this: &cl_logofile,
    pName: "cl_logofile",
    pDefaultValue: "materials/vgui/logos/spray_bullseye.vtf",
    flags: 128,
    pHelpString: "Spraypoint logo decal.");
  return atexit(func: dynamic_atexit_destructor_for__cl_logofile__);
}

//------------------------------------------------------------------------------
// Address: 0x10313FC0
// Name: _dynamic_initializer_for__cl_soundfile__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_soundfile__()
{
  ConVar::ConVar(
    this: &cl_soundfile,
    pName: "cl_soundfile",
    pDefaultValue: defaultValue,
    flags: 128,
    pHelpString: "Jingle sound file.");
  return atexit(func: dynamic_atexit_destructor_for__cl_soundfile__);
}

//------------------------------------------------------------------------------
// Address: 0x10313FF0
// Name: _dynamic_initializer_for__cl_forcepreload__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_forcepreload__()
{
  ConVar::ConVar(
    this: &cl_forcepreload,
    pName: "cl_forcepreload",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "Whether we should force preloading.");
  return atexit(func: dynamic_atexit_destructor_for__cl_forcepreload__);
}

//------------------------------------------------------------------------------
// Address: 0x10314020
// Name: _dynamic_initializer_for__cl_allowdownload__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_allowdownload__()
{
  ConVar::ConVar(
    this: &cl_allowdownload,
    pName: "cl_allowdownload",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Client downloads customization files");
  return atexit(func: dynamic_atexit_destructor_for__cl_allowdownload__);
}

//------------------------------------------------------------------------------
// Address: 0x10314050
// Name: _dynamic_initializer_for__cl_downloadfilter__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_downloadfilter__()
{
  ConVar::ConVar(
    this: &cl_downloadfilter,
    pName: "cl_downloadfilter",
    pDefaultValue: "all",
    flags: 128,
    pHelpString: "Determines which files can be downloaded from the server (all, none, nosounds)");
  return atexit(func: dynamic_atexit_destructor_for__cl_downloadfilter__);
}

//------------------------------------------------------------------------------
// Address: 0x10319170
// Name: _dynamic_initializer_for__cl_cmdrate_var__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_cmdrate_var__()
{
  ConVar::ConVar(
    this: &cl_cmdrate_var,
    pName: "cl_cmdrate",
    pDefaultValue: "30",
    flags: 640,
    pHelpString: "Max number of command packets sent to server per second",
    bMin: true,
    fMin: 10.0,
    bMax: true,
    fMax: 100.0);
  cl_cmdrate_var.ConVar_ServerBounded::ConVar::ConCommandBase::__vftable = (CBoundedCvar_CmdRate_vtbl *)&CBoundedCvar_CmdRate::`vftable'{for `ConCommandBase'};
  cl_cmdrate_var.ConVar_ServerBounded::ConVar::IConVar::__vftable = (IConVar_vtbl *)&CBoundedCvar_CmdRate::`vftable'{for `IConVar'};
  return atexit(func: dynamic_atexit_destructor_for__cl_cmdrate_var__);
}

//------------------------------------------------------------------------------
// Address: 0x103191D0
// Name: _dynamic_initializer_for__cl_updaterate_var__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_updaterate_var__()
{
  ConVar::ConVar(
    this: &cl_updaterate_var,
    pName: "cl_updaterate",
    pDefaultValue: "20",
    flags: 640,
    pHelpString: "Number of packets per second of updates you are requesting from the server");
  cl_updaterate_var.ConVar_ServerBounded::ConVar::ConCommandBase::__vftable = (CBoundedCvar_UpdateRate_vtbl *)&CBoundedCvar_UpdateRate::`vftable'{for `ConCommandBase'};
  cl_updaterate_var.ConVar_ServerBounded::ConVar::IConVar::__vftable = (IConVar_vtbl *)&CBoundedCvar_UpdateRate::`vftable'{for `IConVar'};
  return atexit(func: dynamic_atexit_destructor_for__cl_updaterate_var__);
}

//------------------------------------------------------------------------------
// Address: 0x10319210
// Name: _dynamic_initializer_for__cl_clock_correction__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_clock_correction__()
{
  ConVar::ConVar(
    this: &cl_clock_correction,
    pName: "cl_clock_correction",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Enable/disable clock correction on the client.");
  return atexit(func: dynamic_atexit_destructor_for__cl_clock_correction__);
}

//------------------------------------------------------------------------------
// Address: 0x10319240
// Name: _dynamic_initializer_for__cl_clockdrift_max_ms__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_clockdrift_max_ms__()
{
  ConVar::ConVar(
    this: &cl_clockdrift_max_ms,
    pName: "cl_clockdrift_max_ms",
    pDefaultValue: "150",
    flags: 0x4000,
    pHelpString: "Maximum number of milliseconds the clock is allowed to drift before the client snaps its clock to the server's.");
  return atexit(func: dynamic_atexit_destructor_for__cl_clockdrift_max_ms__);
}

//------------------------------------------------------------------------------
// Address: 0x10319270
// Name: _dynamic_initializer_for__cl_clockdrift_max_ms_threadmode__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_clockdrift_max_ms_threadmode__()
{
  ConVar::ConVar(
    this: &cl_clockdrift_max_ms_threadmode,
    pName: "cl_clockdrift_max_ms_threadmode",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Maximum number of milliseconds the clock is allowed to drift before the client snaps its clock to the server's.");
  return atexit(func: dynamic_atexit_destructor_for__cl_clockdrift_max_ms_threadmode__);
}

//------------------------------------------------------------------------------
// Address: 0x103192A0
// Name: _dynamic_initializer_for__cl_clock_showdebuginfo__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_clock_showdebuginfo__()
{
  ConVar::ConVar(
    this: &cl_clock_showdebuginfo,
    pName: "cl_clock_showdebuginfo",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Show debugging info about the clock drift. ");
  return atexit(func: dynamic_atexit_destructor_for__cl_clock_showdebuginfo__);
}

//------------------------------------------------------------------------------
// Address: 0x103192D0
// Name: _dynamic_initializer_for__cl_clock_correction_force_server_tick__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_clock_correction_force_server_tick__()
{
  ConVar::ConVar(
    this: &cl_clock_correction_force_server_tick,
    pName: "cl_clock_correction_force_server_tick",
    pDefaultValue: "999",
    flags: 0x4000,
    pHelpString: "Force clock correction to match the server tick + this offset (-999 disables it).");
  return atexit(func: dynamic_atexit_destructor_for__cl_clock_correction_force_server_tick__);
}

//------------------------------------------------------------------------------
// Address: 0x10319300
// Name: _dynamic_initializer_for__cl_clock_correction_adjustment_max_amount__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_clock_correction_adjustment_max_amount__()
{
  ConVar::ConVar(
    this: &cl_clock_correction_adjustment_max_amount,
    pName: "cl_clock_correction_adjustment_max_amount",
    pDefaultValue: "200",
    flags: 0x4000,
    pHelpString: "Sets the maximum number of milliseconds per second it is allowed to correct the client clock. It will only correct t"
    "his amount if the difference between the client and server clock is equal to or larger than cl_clock_correction_adju"
    "stment_max_offset.");
  return atexit(func: dynamic_atexit_destructor_for__cl_clock_correction_adjustment_max_amount__);
}

//------------------------------------------------------------------------------
// Address: 0x10319330
// Name: _dynamic_initializer_for__cl_clock_correction_adjustment_min_offset__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_clock_correction_adjustment_min_offset__()
{
  ConVar::ConVar(
    this: &cl_clock_correction_adjustment_min_offset,
    pName: "cl_clock_correction_adjustment_min_offset",
    pDefaultValue: "10",
    flags: 0x4000,
    pHelpString: "If the clock offset is less than this amount (in milliseconds), then no clock correction is applied.");
  return atexit(func: dynamic_atexit_destructor_for__cl_clock_correction_adjustment_min_offset__);
}

//------------------------------------------------------------------------------
// Address: 0x10319360
// Name: _dynamic_initializer_for__cl_clock_correction_adjustment_max_offset__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_clock_correction_adjustment_max_offset__()
{
  ConVar::ConVar(
    this: &cl_clock_correction_adjustment_max_offset,
    pName: "cl_clock_correction_adjustment_max_offset",
    pDefaultValue: "90",
    flags: 0x4000,
    pHelpString: "As the clock offset goes from cl_clock_correction_adjustment_min_offset to this value (in milliseconds), it moves to"
    "wards applying cl_clock_correction_adjustment_max_amount of adjustment. That way, the response is small when the offset is small.");
  return atexit(func: dynamic_atexit_destructor_for__cl_clock_correction_adjustment_max_offset__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A6F0
// Name: _dynamic_initializer_for__cl_configversion__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_configversion__()
{
  ConVar::ConVar(
    this: &cl_configversion,
    pName: "cl_configversion",
    pDefaultValue: "2",
    flags: 2,
    pHelpString: "Configuration layout version.");
  return atexit(func: dynamic_atexit_destructor_for__cl_configversion__);
}

//------------------------------------------------------------------------------
// Address: 0x1031A720
// Name: _dynamic_initializer_for__cl_configversion_dummy__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_configversion_dummy__()
{
  ConVar::ConVar(
    this: &cl_configversion_dummy,
    pName: "cl_configversion_dummy",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Configuration layout version dummy.");
  return atexit(func: dynamic_atexit_destructor_for__cl_configversion_dummy__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D6C0
// Name: _dynamic_initializer_for__cl_allowupload__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_allowupload__()
{
  ConVar::ConVar(
    this: &cl_allowupload,
    pName: "cl_allowupload",
    pDefaultValue: "1",
    flags: 128,
    pHelpString: "Client uploads customization files");
  return atexit(func: dynamic_atexit_destructor_for__cl_allowupload__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D6F0
// Name: _dynamic_initializer_for__cl_voice_filter__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_voice_filter__()
{
  ConVar::ConVar(
    this: &cl_voice_filter,
    pName: "cl_voice_filter",
    pDefaultValue: defaultValue,
    flags: 0,
    pHelpString: "Filter voice by name substring");
  return atexit(func: dynamic_atexit_destructor_for__cl_voice_filter__);
}

//------------------------------------------------------------------------------
// Address: 0x1031DB60
// Name: _dynamic_initializer_for__cl_skipslowpath__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_skipslowpath__()
{
  ConVar::ConVar(
    this: &cl_skipslowpath,
    pName: "cl_skipslowpath",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Set to 1 to skip any models that don't go through the model fast path");
  return atexit(func: dynamic_atexit_destructor_for__cl_skipslowpath__);
}

//------------------------------------------------------------------------------
// Address: 0x10322380
// Name: _dynamic_atexit_destructor_for__cl_resend__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_resend__()
{
  ConVar::~ConVar(this: &cl_resend);
}

//------------------------------------------------------------------------------
// Address: 0x10322390
// Name: _dynamic_atexit_destructor_for__cl_resend_timeout__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_resend_timeout__()
{
  ConVar::~ConVar(this: &cl_resend_timeout);
}

//------------------------------------------------------------------------------
// Address: 0x103223A0
// Name: _dynamic_atexit_destructor_for__cl_name__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_name__()
{
  ConVar::~ConVar(this: &cl_name);
}

//------------------------------------------------------------------------------
// Address: 0x103223C0
// Name: _dynamic_atexit_destructor_for__cl_interpolate__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_interpolate__()
{
  ConVar::~ConVar(this: &cl_interpolate);
}

//------------------------------------------------------------------------------
// Address: 0x103223D0
// Name: _dynamic_atexit_destructor_for__cl_failremoteconnections__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_failremoteconnections__()
{
  ConVar::~ConVar(this: &cl_failremoteconnections);
}

//------------------------------------------------------------------------------
// Address: 0x103225C0
// Name: _dynamic_atexit_destructor_for__cl_showdemooverlay__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_showdemooverlay__()
{
  ConVar::~ConVar(this: &cl_showdemooverlay);
}

//------------------------------------------------------------------------------
// Address: 0x103227F0
// Name: _dynamic_atexit_destructor_for__cl_entityreport__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_entityreport__()
{
  ConVar::~ConVar(this: &cl_entityreport);
}

//------------------------------------------------------------------------------
// Address: 0x103228F0
// Name: _dynamic_atexit_destructor_for__cl_playback_screenshots__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_playback_screenshots__()
{
  ConVar::~ConVar(this: &cl_playback_screenshots);
}

//------------------------------------------------------------------------------
// Address: 0x10322910
// Name: _dynamic_atexit_destructor_for__cl_retire_low_priority_lights__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_retire_low_priority_lights__()
{
  ConVar::~ConVar(this: &cl_retire_low_priority_lights);
}

//------------------------------------------------------------------------------
// Address: 0x10322960
// Name: _dynamic_atexit_destructor_for__cl_screenshotname__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_screenshotname__()
{
  ConVar::~ConVar(this: &cl_screenshotname);
}

//------------------------------------------------------------------------------
// Address: 0x10322A10
// Name: _dynamic_atexit_destructor_for__cl_view_command__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_view_command__()
{
  ConCommand::~ConCommand(this: &cl_view_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322A20
// Name: _dynamic_atexit_destructor_for__cl_showents_command__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_showents_command__()
{
  ConCommand::~ConCommand(this: &cl_showents_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322AB0
// Name: _dynamic_atexit_destructor_for__cl_showpluginmessages__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_showpluginmessages__()
{
  ConVar::~ConVar(this: &cl_showpluginmessages);
}

//------------------------------------------------------------------------------
// Address: 0x10322C10
// Name: _dynamic_atexit_destructor_for__cl_timeout__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_timeout__()
{
  ConVar::~ConVar(this: &cl_timeout);
}

//------------------------------------------------------------------------------
// Address: 0x10322C20
// Name: _dynamic_atexit_destructor_for__cl_logofile__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_logofile__()
{
  ConVar::~ConVar(this: &cl_logofile);
}

//------------------------------------------------------------------------------
// Address: 0x10322C30
// Name: _dynamic_atexit_destructor_for__cl_soundfile__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_soundfile__()
{
  ConVar::~ConVar(this: &cl_soundfile);
}

//------------------------------------------------------------------------------
// Address: 0x10322C40
// Name: _dynamic_atexit_destructor_for__cl_forcepreload__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_forcepreload__()
{
  ConVar::~ConVar(this: &cl_forcepreload);
}

//------------------------------------------------------------------------------
// Address: 0x10322C50
// Name: _dynamic_atexit_destructor_for__cl_allowdownload__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_allowdownload__()
{
  ConVar::~ConVar(this: &cl_allowdownload);
}

//------------------------------------------------------------------------------
// Address: 0x10322C60
// Name: _dynamic_atexit_destructor_for__cl_downloadfilter__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_downloadfilter__()
{
  ConVar::~ConVar(this: &cl_downloadfilter);
}

//------------------------------------------------------------------------------
// Address: 0x10324D20
// Name: _dynamic_atexit_destructor_for__cl_rate_var__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_rate_var__()
{
  ConVar::~ConVar(this: &cl_rate_var);
}

//------------------------------------------------------------------------------
// Address: 0x10324D30
// Name: _dynamic_atexit_destructor_for__cl_cmdrate_var__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_cmdrate_var__()
{
  ConVar::~ConVar(this: &cl_cmdrate_var);
}

//------------------------------------------------------------------------------
// Address: 0x10324D40
// Name: _dynamic_atexit_destructor_for__cl_updaterate_var__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_updaterate_var__()
{
  ConVar::~ConVar(this: &cl_updaterate_var);
}

//------------------------------------------------------------------------------
// Address: 0x10324D50
// Name: _dynamic_atexit_destructor_for__cl_clock_correction__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_clock_correction__()
{
  ConVar::~ConVar(this: &cl_clock_correction);
}

//------------------------------------------------------------------------------
// Address: 0x10324D60
// Name: _dynamic_atexit_destructor_for__cl_clockdrift_max_ms__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_clockdrift_max_ms__()
{
  ConVar::~ConVar(this: &cl_clockdrift_max_ms);
}

//------------------------------------------------------------------------------
// Address: 0x10324D70
// Name: _dynamic_atexit_destructor_for__cl_clockdrift_max_ms_threadmode__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_clockdrift_max_ms_threadmode__()
{
  ConVar::~ConVar(this: &cl_clockdrift_max_ms_threadmode);
}

//------------------------------------------------------------------------------
// Address: 0x10324D80
// Name: _dynamic_atexit_destructor_for__cl_clock_showdebuginfo__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_clock_showdebuginfo__()
{
  ConVar::~ConVar(this: &cl_clock_showdebuginfo);
}

//------------------------------------------------------------------------------
// Address: 0x10324D90
// Name: _dynamic_atexit_destructor_for__cl_clock_correction_force_server_tick__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_clock_correction_force_server_tick__()
{
  ConVar::~ConVar(this: &cl_clock_correction_force_server_tick);
}

//------------------------------------------------------------------------------
// Address: 0x10324DA0
// Name: _dynamic_atexit_destructor_for__cl_clock_correction_adjustment_max_amount__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_clock_correction_adjustment_max_amount__()
{
  ConVar::~ConVar(this: &cl_clock_correction_adjustment_max_amount);
}

//------------------------------------------------------------------------------
// Address: 0x10324DB0
// Name: _dynamic_atexit_destructor_for__cl_clock_correction_adjustment_min_offset__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_clock_correction_adjustment_min_offset__()
{
  ConVar::~ConVar(this: &cl_clock_correction_adjustment_min_offset);
}

//------------------------------------------------------------------------------
// Address: 0x10324DC0
// Name: _dynamic_atexit_destructor_for__cl_clock_correction_adjustment_max_offset__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_clock_correction_adjustment_max_offset__()
{
  ConVar::~ConVar(this: &cl_clock_correction_adjustment_max_offset);
}

//------------------------------------------------------------------------------
// Address: 0x10325660
// Name: _dynamic_atexit_destructor_for__cl_configversion__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_configversion__()
{
  ConVar::~ConVar(this: &cl_configversion);
}

//------------------------------------------------------------------------------
// Address: 0x10325670
// Name: _dynamic_atexit_destructor_for__cl_configversion_dummy__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_configversion_dummy__()
{
  ConVar::~ConVar(this: &cl_configversion_dummy);
}

//------------------------------------------------------------------------------
// Address: 0x10326880
// Name: _dynamic_atexit_destructor_for__cl_allowupload__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_allowupload__()
{
  ConVar::~ConVar(this: &cl_allowupload);
}

//------------------------------------------------------------------------------
// Address: 0x10326890
// Name: _dynamic_atexit_destructor_for__cl_voice_filter__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_voice_filter__()
{
  ConVar::~ConVar(this: &cl_voice_filter);
}

//------------------------------------------------------------------------------
// Address: 0x103269E0
// Name: _dynamic_atexit_destructor_for__cl_skipslowpath__
// Source: semantic_dyn_pfx_cl
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_skipslowpath__()
{
  ConVar::~ConVar(this: &cl_skipslowpath);
}

//------------------------------------------------------------------------------
// Address: 0x10212022
// Name: closesocket(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall closesocket(SOCKET s)
{
  return __imp__closesocket@4(s);
}

//------------------------------------------------------------------------------
// Address: 0x10212028
// Name: htons(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
u_short __stdcall htons(u_short hostshort)
{
  return __imp__htons@4(hostshort);
}

//------------------------------------------------------------------------------
// Address: 0x103128A0
// Name: _dynamic_initializer_for__password__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__password__()
{
  ConVar::ConVar(
    this: &password,
    pName: "password",
    pDefaultValue: defaultValue,
    flags: 537002112,
    pHelpString: "Current server access password");
  return atexit(func: dynamic_atexit_destructor_for__password__);
}

//------------------------------------------------------------------------------
// Address: 0x10312930
// Name: _dynamic_initializer_for__g_BrushBatchRenderer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BrushBatchRenderer__()
{
  g_BrushBatchRenderer.m_Mutex.m_ownerID = 0;
  g_BrushBatchRenderer.m_Mutex.m_depth = 0;
  g_BrushBatchRenderer.m_renderList.m_Memory.m_pMemory = nullptr;
  g_BrushBatchRenderer.m_renderList.m_Memory.m_nAllocationCount = 0;
  g_BrushBatchRenderer.m_renderList.m_Memory.m_nGrowSize = 0;
  g_BrushBatchRenderer.m_renderList.m_LastAlloc.index = -1;
  *(_DWORD *)&g_BrushBatchRenderer.m_renderList.m_Head = -1;
  *(_DWORD *)&g_BrushBatchRenderer.m_renderList.m_FirstFree = 0xFFFF;
  g_BrushBatchRenderer.m_renderList.m_NumAlloced = 0;
  g_BrushBatchRenderer.m_renderList.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_BrushBatchRenderer__);
}

//------------------------------------------------------------------------------
// Address: 0x10312990
// Name: _dynamic_initializer_for__dynamic_tonemap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dynamic_tonemap__()
{
  ConVar::ConVar(this: &dynamic_tonemap, pName: "mat_dynamic_tonemapping", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__dynamic_tonemap__);
}

//------------------------------------------------------------------------------
// Address: 0x103129C0
// Name: _dynamic_initializer_for__building_cubemaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__building_cubemaps__()
{
  ConVar::ConVar(this: &building_cubemaps, pName: "building_cubemaps", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__building_cubemaps__);
}

//------------------------------------------------------------------------------
// Address: 0x103129F0
// Name: _dynamic_initializer_for__reload_materials__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__reload_materials__()
{
  ConVar::ConVar(this: &reload_materials, pName: "reload_materials", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__reload_materials__);
}

//------------------------------------------------------------------------------
// Address: 0x10312EE0
// Name: _dynamic_initializer_for__g_DemoOverlay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DemoOverlay__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_DemoOverlay__);
}

//------------------------------------------------------------------------------
// Address: 0x10313440
// Name: _dynamic_initializer_for__er_colwidth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__er_colwidth__()
{
  ConVar::ConVar(this: &er_colwidth, pName: "er_colwidth", pDefaultValue: "100", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__er_colwidth__);
}

//------------------------------------------------------------------------------
// Address: 0x10313470
// Name: _dynamic_initializer_for__er_maxname__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__er_maxname__()
{
  ConVar::ConVar(this: &er_maxname, pName: "er_maxname", pDefaultValue: "14", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__er_maxname__);
}

//------------------------------------------------------------------------------
// Address: 0x103134A0
// Name: _dynamic_initializer_for__er_graphwidthfrac__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__er_graphwidthfrac__()
{
  ConVar::ConVar(this: &er_graphwidthfrac, pName: "er_graphwidthfrac", pDefaultValue: "0.2", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__er_graphwidthfrac__);
}

//------------------------------------------------------------------------------
// Address: 0x10313690
// Name: _dynamic_initializer_for__g_DLightLeafAccessors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFastPointLeafNum *dynamic_initializer_for__g_DLightLeafAccessors__()
{
  CFastPointLeafNum *v0; // esi
  int i; // edi
  CFastPointLeafNum *result; // eax

  v0 = g_DLightLeafAccessors;
  for ( i = 31; i >= 0; --i )
    result = CFastPointLeafNum::CFastPointLeafNum(this: v0++);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103136B0
// Name: _dynamic_initializer_for__g_ELightLeafAccessors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFastPointLeafNum *dynamic_initializer_for__g_ELightLeafAccessors__()
{
  CFastPointLeafNum *v0; // esi
  int i; // edi
  CFastPointLeafNum *result; // eax

  v0 = g_ELightLeafAccessors;
  for ( i = 63; i >= 0; --i )
    result = CFastPointLeafNum::CFastPointLeafNum(this: v0++);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10313830
// Name: _dynamic_initializer_for__screenshot_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__screenshot_command__()
{
  ConCommand::ConCommand(
    this: &screenshot_command,
    pName: "screenshot",
    callback: screenshot,
    pHelpString: "Take a screenshot.",
    flags: 0x40000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__screenshot_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313860
// Name: _dynamic_initializer_for__devshots_screenshot_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__devshots_screenshot_command__()
{
  ConCommand::ConCommand(
    this: &devshots_screenshot_command,
    pName: "devshots_screenshot",
    callback: devshots_screenshot,
    pHelpString: "Used by the -makedevshots system to take a screenshot. For taking your own screenshots, use the 'screenshot' command instead.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__devshots_screenshot_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313890
// Name: _dynamic_initializer_for__jpeg_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__jpeg_command__()
{
  ConCommand::ConCommand(
    this: &jpeg_command,
    pName: "jpeg",
    callback: jpeg,
    pHelpString: "Take a jpeg screenshot:  jpeg <filename> <quality 1-100>.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__jpeg_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313A70
// Name: _dynamic_initializer_for__startupmenu__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startupmenu__()
{
  ConCommand::ConCommand(
    this: &startupmenu,
    pName: "startupmenu",
    callback: (void (__cdecl *)(const CCommand *))CColorBalanceUIPanel::Init,
    pHelpString: "Opens initial menu screen and loads the background bsp, but only if no other level is being loaded, and we're not in"
    " developer mode.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startupmenu__);
}

//------------------------------------------------------------------------------
// Address: 0x10313B30
// Name: _dynamic_initializer_for__setinfo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__setinfo_command__()
{
  ConCommand::ConCommand(
    this: &setinfo_command,
    pName: "setinfo",
    callback: (void (__cdecl *)(const CCommand *))setinfo,
    pHelpString: "Adds a new user info value",
    flags: 0x40000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__setinfo_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10313BF0
// Name: _dynamic_initializer_for__g_RCONClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RCONClient__()
{
  CRConClient::CRConClient(this: &g_RCONClient);
  return atexit(func: dynamic_atexit_destructor_for__g_RCONClient__);
}

//------------------------------------------------------------------------------
// Address: 0x10313C10
// Name: _dynamic_initializer_for__g_RPTClient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_RPTClient__()
{
  CRConClient::CRConClient(this: &g_RPTClient);
  g_RPTClient.__vftable = (CRPTClient_vtbl *)&CRPTClient::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_RPTClient__);
}

//------------------------------------------------------------------------------
// Address: 0x10314080
// Name: _dynamic_initializer_for__asw_engine_finished_building_map_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__asw_engine_finished_building_map_command__()
{
  ConCommand::ConCommand(
    this: &asw_engine_finished_building_map_command,
    pName: "asw_engine_finished_building_map",
    callback: asw_engine_finished_building_map,
    pHelpString: "Notify engine that we've finished building a map",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__asw_engine_finished_building_map_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103223B0
// Name: _dynamic_atexit_destructor_for__password__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__password__()
{
  ConVar::~ConVar(this: &password);
}

//------------------------------------------------------------------------------
// Address: 0x103223E0
// Name: _dynamic_atexit_destructor_for__g_BrushBatchRenderer__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BrushBatchRenderer__()
{
  CUtlLinkedList<CFrameSnapshot *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CFrameSnapshot *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&g_BrushBatchRenderer.m_renderList);
  if ( g_BrushBatchRenderer.m_renderList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_BrushBatchRenderer.m_renderList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_BrushBatchRenderer.m_renderList.m_Memory.m_pMemory);
      g_BrushBatchRenderer.m_renderList.m_Memory.m_pMemory = nullptr;
    }
    g_BrushBatchRenderer.m_renderList.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10322430
// Name: _dynamic_atexit_destructor_for__dynamic_tonemap__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__dynamic_tonemap__()
{
  ConVar::~ConVar(this: &dynamic_tonemap);
}

//------------------------------------------------------------------------------
// Address: 0x10322440
// Name: _dynamic_atexit_destructor_for__building_cubemaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__building_cubemaps__()
{
  ConVar::~ConVar(this: &building_cubemaps);
}

//------------------------------------------------------------------------------
// Address: 0x10322450
// Name: _dynamic_atexit_destructor_for__reload_materials__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__reload_materials__()
{
  ConVar::~ConVar(this: &reload_materials);
}

//------------------------------------------------------------------------------
// Address: 0x10322800
// Name: _dynamic_atexit_destructor_for__er_colwidth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__er_colwidth__()
{
  ConVar::~ConVar(this: &er_colwidth);
}

//------------------------------------------------------------------------------
// Address: 0x10322810
// Name: _dynamic_atexit_destructor_for__er_maxname__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__er_maxname__()
{
  ConVar::~ConVar(this: &er_maxname);
}

//------------------------------------------------------------------------------
// Address: 0x10322820
// Name: _dynamic_atexit_destructor_for__er_graphwidthfrac__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__er_graphwidthfrac__()
{
  ConVar::~ConVar(this: &er_graphwidthfrac);
}

//------------------------------------------------------------------------------
// Address: 0x10322830
// Name: _dynamic_atexit_destructor_for__g_EntityReportMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EntityReportMgr__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_EntityReportMgr);
}

//------------------------------------------------------------------------------
// Address: 0x10322900
// Name: _dynamic_atexit_destructor_for__jpeg_quality__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__jpeg_quality__()
{
  ConVar::~ConVar(this: &jpeg_quality);
}

//------------------------------------------------------------------------------
// Address: 0x10322970
// Name: _dynamic_atexit_destructor_for__screenshot_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__screenshot_command__()
{
  ConCommand::~ConCommand(this: &screenshot_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322980
// Name: _dynamic_atexit_destructor_for__devshots_screenshot_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__devshots_screenshot_command__()
{
  ConCommand::~ConCommand(this: &devshots_screenshot_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322990
// Name: _dynamic_atexit_destructor_for__jpeg_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__jpeg_command__()
{
  ConCommand::~ConCommand(this: &jpeg_command);
}

//------------------------------------------------------------------------------
// Address: 0x10322A30
// Name: _dynamic_atexit_destructor_for__startupmenu__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startupmenu__()
{
  ConCommand::~ConCommand(this: &startupmenu);
}

//------------------------------------------------------------------------------
// Address: 0x10322C70
// Name: _dynamic_atexit_destructor_for__asw_engine_finished_building_map_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__asw_engine_finished_building_map_command__()
{
  ConCommand::~ConCommand(this: &asw_engine_finished_building_map_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324DD0
// Name: _dynamic_atexit_destructor_for__BindToggle_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__BindToggle_command__()
{
  ConCommand::~ConCommand(this: &BindToggle_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324DE0
// Name: _dynamic_atexit_destructor_for__stuffcmds_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__stuffcmds_command__()
{
  ConCommand::~ConCommand(this: &stuffcmds_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324DF0
// Name: _dynamic_atexit_destructor_for__echo_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__echo_command__()
{
  ConCommand::~ConCommand(this: &echo_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324E00
// Name: _dynamic_atexit_destructor_for__alias_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__alias_command__()
{
  ConCommand::~ConCommand(this: &alias_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324E10
// Name: _dynamic_atexit_destructor_for__cmd_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cmd_command__()
{
  ConCommand::~ConCommand(this: &cmd_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324E20
// Name: _dynamic_atexit_destructor_for__exec_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__exec_command__()
{
  ConCommand::~ConCommand(this: &exec_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324E30
// Name: _dynamic_atexit_destructor_for__execifexists_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__execifexists_command__()
{
  ConCommand::~ConCommand(this: &execifexists_command);
}

} // namespace engine_xlsp
