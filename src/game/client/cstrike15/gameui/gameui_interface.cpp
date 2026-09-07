// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/gameui_interface.cpp
// Functions: 46
// ============================================================

#include "game\client\cstrike15\gameui\gameui_interface.h"

//------------------------------------------------------------------------------
// Address: 0x101D5690
// Name: class IScaleformUI __near * ScaleformUI(void)
// Source: json
//------------------------------------------------------------------------------
IScaleformUI *__cdecl ScaleformUI()
{
  return g_pScaleformUI;
}

//------------------------------------------------------------------------------
// Address: 0x101D56A0
// Name: class IGameClientExports __near * GameClientExports(void)
// Source: json
//------------------------------------------------------------------------------
IGameClientExports *__cdecl GameClientExports()
{
  return g_pGameClientExports;
}

//------------------------------------------------------------------------------
// Address: 0x101D56B0
// Name: unsigned int GetGameUIBasePanel(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl GetGameUIBasePanel()
{
  CBaseModPanel *v0; // eax

  v0 = BasePanel();
  return v0->GetVPanel(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x101D56C0
// Name: class CGameUI __near & GameUI(void)
// Source: json
//------------------------------------------------------------------------------
CGameUI *__cdecl GameUI()
{
  return &g_GameUI;
}

//------------------------------------------------------------------------------
// Address: 0x101D56D0
// Name: public: virtual void CGameUI::OnDisconnectFromServer_OLD(unsigned char,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::OnDisconnectFromServer_OLD(CGameUI *this, int eSteamLoginFailure, const char *username)
{
  this->OnDisconnectFromServer(this, a2: eSteamLoginFailure);
}

//------------------------------------------------------------------------------
// Address: 0x101D56F0
// Name: public: virtual void CGameUI::SetLoadingBackgroundDialog(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::SetLoadingBackgroundDialog(CGameUI *this, unsigned int panel)
{
  g_hLoadingBackgroundDialog = panel;
}

//------------------------------------------------------------------------------
// Address: 0x101D5700
// Name: public: virtual void CGameUI::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::Connect(CGameUI *this, void *(__cdecl *gameFactory)(const char *, int *))
{
  const char *v3; // [esp+0h] [ebp-8h]

  g_pGameClientExports = (IGameClientExports *)gameFactory(a1: "GameClientExports001", a2: nullptr);
  g_pScaleformUI = (IScaleformUI *)gameFactory(a1: "ScaleformUI001", a2: nullptr);
  achievementmgr = engine->GetAchievementMgr(this: engine);
  if ( g_pGameClientExports == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_104AD038, a2: v3);
  this->m_GameFactory = gameFactory;
}

//------------------------------------------------------------------------------
// Address: 0x101D5760
// Name: int SendShutdownMsgFunc(int,int)
// Source: json
//------------------------------------------------------------------------------
int __stdcall SendShutdownMsgFunc(int hwnd, int lparam)
{
  unsigned int v2; // eax

  v2 = Sys_RegisterWindowMessage(msgName: "ShutdownValvePlatform");
  Sys_PostMessage(wnd: hwnd, msg: v2, wParam: 0, lParam: 1u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D5790
// Name: public: virtual void CGameUI::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::Shutdown(CGameUI *this)
{
  CModInfo *v1; // eax
  CSteamAPIContext *v2; // eax
  vgui::PropertyPage *v3; // ecx

  CVGuiSystemModuleLoader::ShutdownPlatformModules(this: &g_VModuleLoader);
  CVGuiSystemModuleLoader::UnloadPlatformModules(this: &g_VModuleLoader);
  v1 = ModInfo();
  CModInfo::~CModInfo(this: v1);
  if ( g_hMutex != 0 )
    Sys_ReleaseMutex(mutexHandle: (void *)g_hMutex);
  if ( g_hWaitMutex != 0 )
    Sys_ReleaseMutex(mutexHandle: (void *)g_hWaitMutex);
  v2 = steamapicontext;
  steamapicontext->m_pSteamUser = nullptr;
  v2->m_pSteamFriends = nullptr;
  v2->m_pSteamUtils = nullptr;
  v2->m_pSteamMatchmaking = nullptr;
  v2->m_pSteamUserStats = nullptr;
  v2->m_pSteamApps = nullptr;
  v2->m_pSteamMatchmakingServers = nullptr;
  v2->m_pSteamNetworking = nullptr;
  v2->m_pSteamRemoteStorage = nullptr;
  ConVar_Unregister();
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v3);
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x101D5810
// Name: public: void CGameUI::ActivateGameUI(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::ActivateGameUI(CGameUI *this)
{
  int v1; // eax

  engine->ExecuteClientCmd(this: engine, a2: "gameui_activate");
  v1 = engine->GetActiveSplitScreenPlayerSlot(this: engine);
  SetGameUIActiveSplitScreenPlayerSlot(nSlot: v1);
}

//------------------------------------------------------------------------------
// Address: 0x101D5840
// Name: public: void CGameUI::HideGameUI(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::HideGameUI(CGameUI *this)
{
  engine->ExecuteClientCmd(this: engine, a2: "gameui_hide");
}

//------------------------------------------------------------------------------
// Address: 0x101D5860
// Name: public: void CGameUI::PreventEngineHideGameUI(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::PreventEngineHideGameUI(CGameUI *this)
{
  engine->ExecuteClientCmd(this: engine, a2: "gameui_preventescape");
}

//------------------------------------------------------------------------------
// Address: 0x101D5880
// Name: public: void CGameUI::AllowEngineHideGameUI(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::AllowEngineHideGameUI(CGameUI *this)
{
  engine->ExecuteClientCmd(this: engine, a2: "gameui_allowescape");
}

//------------------------------------------------------------------------------
// Address: 0x101D58A0
// Name: public: virtual void CGameUI::OnGameUIHidden(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::OnGameUIHidden(CGameUI *this)
{
  char v1; // bl
  CCStrike15BasePanel *v2; // eax

  v1 = *((_BYTE *)this + 8);
  *((_BYTE *)this + 8) = v1 & 0xFD;
  engine->ClientCmd_Unrestricted(this: engine, a2: "unpause nomsg");
  v2 = BasePanel();
  CBaseModPanel::OnGameUIHidden(this: v2);
  if ( (v1 & 2) != 0 )
    SetGameUIActiveSplitScreenPlayerSlot(nSlot: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101D58E0
// Name: public: virtual void CGameUI::OLD_OnConnectToServer(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::OLD_OnConnectToServer(CGameUI *this, const char *game, int IP, int port)
{
  this->OnConnectToServer2(this, a2: game, a3: IP, a4: port, a5: port);
}

//------------------------------------------------------------------------------
// Address: 0x101D5900
// Name: private: void CGameUI::SendConnectedToGameMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::SendConnectedToGameMessage(CGameUI *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "ConnectedToGame");
  else
    v3 = nullptr;
  KeyValues::SetInt(this: v3, keyName: "ip", value: this->m_iGameIP);
  KeyValues::SetInt(this: v3, keyName: "connectionport", value: this->m_iGameConnectionPort);
  KeyValues::SetInt(this: v3, keyName: "queryport", value: this->m_iGameQueryPort);
  CVGuiSystemModuleLoader::PostMessageToAllModules(this: &g_VModuleLoader, message: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101D5970
// Name: public: virtual void CGameUI::OnDisconnectFromServer(unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::OnDisconnectFromServer(CGameUI *this, unsigned __int8 eSteamLoginFailure)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  this->m_iGameIP = 0;
  this->m_iGameConnectionPort = 0;
  this->m_iGameQueryPort = 0;
  if ( g_hLoadingBackgroundDialog != 0 )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "DisconnectedFromGame");
    else
      v3 = nullptr;
    ((void (__stdcall *)(unsigned int, KeyValues *, _DWORD, _DWORD))g_pVGui->PostMessage)(
      a1: g_hLoadingBackgroundDialog,
      a2: v3,
      a3: 0,
      a4: 0);
  }
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "DisconnectedFromGame");
  else
    v5 = nullptr;
  CVGuiSystemModuleLoader::PostMessageToAllModules(this: &g_VModuleLoader, message: v5);
  switch ( eSteamLoginFailure )
  {
    case 2u:
      CLoadingScreenScaleform::DisplayNoSteamConnectionError();
      break;
    case 3u:
      CLoadingScreenScaleform::DisplayVACBannedError();
      break;
    case 4u:
      CLoadingScreenScaleform::DisplayLoggedInElsewhereError();
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D5A30
// Name: public: virtual void CGameUI::OnLevelLoadingStarted(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::OnLevelLoadingStarted(CGameUI *this, const char *levelName, BOOL bShowProgressDialog)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  CCStrike15BasePanel *v6; // eax

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "LoadingStarted");
  else
    v5 = nullptr;
  CVGuiSystemModuleLoader::PostMessageToAllModules(this: &g_VModuleLoader, message: v5);
  v6 = BasePanel();
  v6->OnLevelLoadingStarted(this: v6, a2: levelName, a3: bShowProgressDialog);
  if ( bShowProgressDialog )
    this->StartProgressBar(this);
  this->m_iPlayGameStartupSound = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D5AA0
// Name: public: virtual bool CGameUI::UpdateProgressBar(float,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CGameUI::UpdateProgressBar@<al>(
        CGameUI *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        float progress,
        const char *statusText,
        BOOL showDialog)
{
  bool v7; // bl
  bool v8; // zf
  bool result; // al

  v7 = ((unsigned __int8 (__stdcall *)(_DWORD, BOOL, int, int))this->ContinueProgressBar)(
         a1: LODWORD(progress),
         a2: showDialog,
         a3: a2,
         a4: a3) != 0;
  v8 = !this->SetProgressBarStatusText(this, a2: statusText, a3: showDialog);
  result = true;
  if ( v8 )
    return v7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D5AF0
// Name: public: virtual void CGameUI::SetProgressLevelName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::SetProgressLevelName(CGameUI *this, char *levelName)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi

  if ( g_hLoadingBackgroundDialog != 0 )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "ProgressLevelName");
    else
      v3 = nullptr;
    KeyValues::SetString(this: v3, keyName: "levelName", value: levelName);
    ((void (__stdcall *)(unsigned int, KeyValues *, _DWORD, _DWORD))g_pVGui->PostMessage)(
      a1: g_hLoadingBackgroundDialog,
      a2: v3,
      a3: 0,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D5B60
// Name: private: virtual void CGameUI::StartProgressBar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::StartProgressBar(CGameUI *this)
{
  this->m_szPreviousStatusText[0] = 0;
  CLoadingScreenScaleform::SetProgressPoint(fraction: 0.0, showDialog: true);
}

//------------------------------------------------------------------------------
// Address: 0x101D5B80
// Name: private: virtual bool CGameUI::ContinueProgressBar(float,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameUI::ContinueProgressBar(CGameUI *this, float progressFraction, bool showDialog)
{
  return CLoadingScreenScaleform::SetProgressPoint(fraction: progressFraction, showDialog);
}

//------------------------------------------------------------------------------
// Address: 0x101D5BA0
// Name: private: virtual void CGameUI::StopProgressBar(bool,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::StopProgressBar(
        CGameUI *this,
        bool bError,
        const char *failureReason,
        const char *extendedReason)
{
  CLoadingScreenScaleform::Close();
  if ( bError )
    this->ShowMessageDialog(this, a2: extendedReason, a3: failureReason);
}

//------------------------------------------------------------------------------
// Address: 0x101D5BD0
// Name: private: virtual bool CGameUI::SetProgressBarStatusText(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CGameUI::SetProgressBarStatusText(CGameUI *this, char *statusText, bool showDialog)
{
  char *m_szPreviousStatusText; // esi

  if ( statusText == nullptr )
    return 0;
  m_szPreviousStatusText = this->m_szPreviousStatusText;
  if ( _V_stricmp(s1: statusText, s2: this->m_szPreviousStatusText) == 0 )
    return 0;
  V_strncpy(pDest: m_szPreviousStatusText, pSrc: statusText, maxLen: 128);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D5C20
// Name: public: virtual bool CGameUI::IsInLevel(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameUI::IsInLevel(CGameUI *this)
{
  const char *v1; // eax

  v1 = engine->GetLevelName(this: engine);
  return v1 != nullptr && *v1 != 0 && !engine->IsLevelMainMenuBackground(this: engine);
}

//------------------------------------------------------------------------------
// Address: 0x101D5C60
// Name: public: bool CGameUI::IsInBackgroundLevel(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameUI::IsInBackgroundLevel(CGameUI *this)
{
  const char *v1; // eax

  v1 = engine->GetLevelName(this: engine);
  return v1 != nullptr && *v1 != 0 && engine->IsLevelMainMenuBackground(this: engine);
}

//------------------------------------------------------------------------------
// Address: 0x101D5CA0
// Name: public: bool CGameUI::IsInMultiplayer(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGameUI::IsInMultiplayer(CGameUI *this)
{
  return this->IsInLevel(this) && engine->GetMaxClients(this: engine) > 1;
}

//------------------------------------------------------------------------------
// Address: 0x101D5CD0
// Name: public: bool CGameUI::IsConsoleUI(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameUI::IsConsoleUI(CGameUI *this)
{
  return (*((_BYTE *)this + 8) & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D5CE0
// Name: public: bool CGameUI::HasSavedThisMenuSession(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameUI::HasSavedThisMenuSession(CGameUI *this)
{
  return (*((_BYTE *)this + 8) & 8) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D5CF0
// Name: public: void CGameUI::SetSavedThisMenuSession(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::SetSavedThisMenuSession(CGameUI *this, bool bState)
{
  *((_BYTE *)this + 8) ^= (*((_BYTE *)this + 8) ^ (8 * bState)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x101D5D10
// Name: public: void CGameUI::HideLoadingBackgroundDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::HideLoadingBackgroundDialog(CGameUI *this)
{
  KeyValues *v1; // eax
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( g_hLoadingBackgroundDialog != 0 )
  {
    if ( engine->IsInGame(this: engine) )
    {
      v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v1 != nullptr )
        v2 = KeyValues::KeyValues(this: v1, setName: "LoadedIntoGame");
      else
        v2 = nullptr;
      ((void (__stdcall *)(unsigned int, KeyValues *, _DWORD, _DWORD))g_pVGui->PostMessage)(
        a1: g_hLoadingBackgroundDialog,
        a2: v2,
        a3: 0,
        a4: 0);
    }
    else
    {
      g_pVGuiPanel->SetVisible(this: g_pVGuiPanel, a2: g_hLoadingBackgroundDialog, a3: false);
      g_pVGuiPanel->MoveToBack(this: g_pVGuiPanel, a2: g_hLoadingBackgroundDialog);
    }
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "HideAsLoadingPanel");
    else
      v4 = nullptr;
    ((void (__stdcall *)(unsigned int, KeyValues *, _DWORD, _DWORD))g_pVGui->PostMessage)(
      a1: g_hLoadingBackgroundDialog,
      a2: v4,
      a3: 0,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D5DE0
// Name: public: virtual void CGameUI::ShowMessageDialog(unsigned int,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::ShowMessageDialog(CGameUI *this, unsigned int nType, vgui::Panel *pOwner)
{
  CCStrike15BasePanel *v3; // eax

  v3 = BasePanel();
  CBaseModPanel::ShowMessageDialog(this: v3, nType, pOwner);
}

//------------------------------------------------------------------------------
// Address: 0x101D5E00
// Name: public: virtual void CGameUI::ShowMessageDialog(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::ShowMessageDialog(CGameUI *this, const char *messageID, const char *titleID)
{
  CCStrike15BasePanel *v3; // eax

  v3 = BasePanel();
  v3->OnOpenMessageBox(this: v3, a2: titleID, a3: messageID, a4: "#SFUI_Legend_Ok", a5: 1u, a6: nullptr, a7: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101D5E30
// Name: public: virtual void CGameUI::CreateCommandMsgBox(char const __near *,char const __near *,bool,bool,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::CreateCommandMsgBox(
        CGameUI *this,
        const char *pszTitle,
        const char *pszMessage,
        BOOL showOk,
        BOOL showCancel,
        const char *okCommand,
        const char *cancelCommand,
        const char *closedCommand,
        const char *pszLegend)
{
  CCStrike15BasePanel *v9; // eax

  v9 = BasePanel();
  v9->CreateCommandMsgBox(
    this: v9,
    a2: pszTitle,
    a3: pszMessage,
    a4: showOk,
    a5: showCancel,
    a6: okCommand,
    a7: cancelCommand,
    a8: closedCommand,
    a9: pszLegend);
}

//------------------------------------------------------------------------------
// Address: 0x101D5E50
// Name: public: virtual void CGameUI::CreateCommandMsgBoxInSlot(enum ECommandMsgBoxSlot,char const __near *,char const __near *,bool,bool,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::CreateCommandMsgBoxInSlot(
        CGameUI *this,
        ECommandMsgBoxSlot slot,
        const char *pszTitle,
        const char *pszMessage,
        BOOL showOk,
        BOOL showCancel,
        const char *okCommand,
        const char *cancelCommand,
        const char *closedCommand,
        const char *pszLegend)
{
  CCStrike15BasePanel *v10; // eax

  v10 = BasePanel();
  v10->CreateCommandMsgBoxInSlot(
    this: v10,
    a2: slot,
    a3: pszTitle,
    a4: pszMessage,
    a5: showOk,
    a6: showCancel,
    a7: okCommand,
    a8: cancelCommand,
    a9: closedCommand,
    a10: pszLegend);
}

//------------------------------------------------------------------------------
// Address: 0x101D5E70
// Name: public: virtual void CGameUI::SetProgressOnStart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::SetProgressOnStart(CGameUI *this)
{
  *((_BYTE *)this + 8) |= 0x10u;
}

//------------------------------------------------------------------------------
// Address: 0x101D5E80
// Name: public: virtual void CGameUI::StartLoadingScreenForCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::StartLoadingScreenForCommand(CGameUI *this, const char *command)
{
  CLoadingScreenScaleform::LoadDialogForCommand(command);
}

//------------------------------------------------------------------------------
// Address: 0x101D5EA0
// Name: public: virtual void CGameUI::StartLoadingScreenForKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::StartLoadingScreenForKeyValues(CGameUI *this, KeyValues *keyValues)
{
  CLoadingScreenScaleform::LoadDialogForKeyValues(keyValues);
}

//------------------------------------------------------------------------------
// Address: 0x101D5EC0
// Name: private: void CGameUI::UpdateBackgroundMusic(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::UpdateBackgroundMusic(CGameUI *this)
{
  int m_nBackgroundMusicGUID; // eax

  m_nBackgroundMusicGUID = this->m_nBackgroundMusicGUID;
  if ( this->m_bBackgroundMusicDesired )
  {
    if ( m_nBackgroundMusicGUID == 0 || !enginesound->IsSoundStillPlaying(this: enginesound, a2: m_nBackgroundMusicGUID) )
      this->m_nBackgroundMusicGUID = ((int (__stdcall *)(const char *, int, int, _DWORD, _DWORD))enginesound->EmitAmbientSound)(
                                       a1: "UI/gamestartup1.mp3",
                                       a2: 1065353216,
                                       a3: 100,
                                       a4: 0,
                                       a5: 0);
  }
  else if ( m_nBackgroundMusicGUID != 0 )
  {
    enginesound->StopSoundByGuid(this: enginesound, a2: m_nBackgroundMusicGUID, a3: true);
    this->m_nBackgroundMusicGUID = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D5F40
// Name: public: void CGameUI::SetBackgroundMusicDesired(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::SetBackgroundMusicDesired(CGameUI *this, bool bPlayMusic)
{
  this->m_bBackgroundMusicDesired = bPlayMusic;
}

//------------------------------------------------------------------------------
// Address: 0x101D5F50
// Name: public: virtual void CGameUI::Initialize(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::Initialize(CGameUI *this, void *(__cdecl *factory)(const char *, int *))
{
  vgui::PropertyPage *v3; // ecx
  bool v4; // al
  CModInfo *v5; // eax
  IXboxSystem *v6; // eax
  CCStrike15BasePanel *v7; // esi
  unsigned int v8; // eax
  const char *v9; // [esp+0h] [ebp-14h]
  CGameUIConVarRef var; // [esp+4h] [ebp-10h] BYREF

  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries();
  ConVar_Register(nCVarFlag: 8, pAccessor: nullptr);
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v3);
  enginesound = (IEngineSound *)((int (__cdecl *)(const char *, _DWORD, void *(__cdecl **)(const char *, int *), int))factory)(
                                  a1: "IEngineSoundClient003",
                                  a2: 0,
                                  a3: &factory,
                                  a4: 1);
  engine = (IVEngineClient *)factory(a1: "VEngineClient013", a2: nullptr);
  bik = (IBik *)factory(a1: "VBik001", a2: nullptr);
  _SteamAPI_InitSafe();
  CSteamAPIContext::Init(this: steamapicontext);
  CGameUIConVarRef::CGameUIConVarRef(this: &var, pName: "gameui_xbox");
  v4 = CGameUIConVarRef::IsValid(this: &var)
    && var.m_Info[GetGameUIActiveSplitScreenPlayerSlot()].m_pConVarState->m_Value.m_nValue != 0;
  *((_BYTE *)this + 8) ^= (*((_BYTE *)this + 8) ^ (4 * v4)) & 4;
  vgui::VGui_InitInterfacesList(moduleName: "GameUI");
  vgui::VGui_InitMatSysInterfacesList(moduleName: "GameUI", factoryList: &factory, numFactories: 1);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Resource/gameui_%language%.txt", a3: "GAME", a4: true);
  v5 = ModInfo();
  CModInfo::LoadCurrentGameInfo(this: v5);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Resource/valve_%language%.txt", a3: "GAME", a4: true);
  enginevguifuncs = (IEngineVGui *)factory(a1: "VEngineVGui001", a2: nullptr);
  enginesurfacefuncs = (vgui::ISurface *)factory(a1: "VGUI_Surface031", a2: nullptr);
  gameuifuncs = (IGameUIFuncs *)factory(a1: "VENGINE_GAMEUIFUNCS_VERSION005", a2: nullptr);
  v6 = (IXboxSystem *)factory(a1: "XboxSystemInterface002", a2: nullptr);
  xboxsystem = v6;
  if ( enginesurfacefuncs == nullptr
    || gameuifuncs == nullptr
    || enginevguifuncs == nullptr
    || v6 == nullptr
    || g_pMatchFramework == nullptr )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_104AD038, a2: v9);
  }
  v7 = BasePanelSingleton();
  vgui::Panel::SetBounds(this: v7, x: 0, y: 0, wide: 640, tall: 480);
  v7->SetPaintBorderEnabled(this: v7, a2: false);
  v7->SetPaintBackgroundEnabled(this: v7, a2: true);
  v7->SetPaintEnabled(this: v7, a2: true);
  v7->SetVisible(this: v7, a2: true);
  v7->SetMouseInputEnabled(this: v7, a2: true);
  v7->SetKeyBoardInputEnabled(this: v7, a2: true);
  v8 = enginevguifuncs->GetPanel(this: enginevguifuncs, a2: PANEL_GAMEUIDLL);
  v7->SetParent(this: v7, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x101D6170
// Name: public: virtual void CGameUI::Start(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::Start(CGameUI *this)
{
  unsigned __int8 *m_szPlatformDir; // edi
  HMODULE ModuleHandleA; // eax
  _BYTE *v4; // eax
  HANDLE Mutex; // eax
  void *v6; // ecx
  DWORD v7; // eax
  DWORD v8; // eax
  char *v9; // [esp-8h] [ebp-210h]
  const char *v10; // [esp+0h] [ebp-208h]
  char szConfigDir[512]; // [esp+8h] [ebp-200h] BYREF

  m_szPlatformDir = (unsigned __int8 *)this->m_szPlatformDir;
  v9 = this->m_szPlatformDir;
  this->m_szPlatformDir[0] = 0;
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  if ( GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: v9, nSize: 0x104u) == 0
    || (strrchr(string: m_szPlatformDir, chr: 0x5Cu), v4 == nullptr) )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_104AD08C, a2: v10);
    return;
  }
  *v4 = 0;
  V_strncat(pDest: (char *)m_szPlatformDir, pSrc: "\\platform\\", destBufferSize: 0x104u, max_chars_to_copy: -1);
  V_strncpy(pDest: szConfigDir, pSrc: (char *)m_szPlatformDir, maxLen: 512);
  V_strncat(pDest: szConfigDir, pSrc: "config", destBufferSize: 0x200u, max_chars_to_copy: -1);
  _Msg(a1: "Steam config directory: %s\n", szConfigDir);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: szConfigDir, a3: "CONFIG", a4: PATH_ADD_TO_TAIL);
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: prType, a3: "CONFIG");
  g_pVGuiSystem->SetUserConfigFile(this: g_pVGuiSystem, a2: "InGameDialogConfig.vdf", a3: "CONFIG");
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: "platform", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Resource/platform_%language%.txt", a3: nullptr, a4: false);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Resource/vgui_%language%.txt", a3: nullptr, a4: false);
  Sys_SetLastError(error: 0);
  this->m_iPlayGameStartupSound = 2;
  this->m_bBackgroundMusicDesired = true;
  g_hMutex = (int)Sys_CreateMutex(mutexName: "ValvePlatformUIMutex");
  Mutex = Sys_CreateMutex(mutexName: "ValvePlatformWaitMutex");
  v6 = (void *)g_hMutex;
  g_hWaitMutex = (int)Mutex;
  if ( g_hMutex != 0 )
  {
    if ( Mutex != nullptr )
    {
      if ( Sys_GetLastError() != 6 )
      {
        v7 = Sys_WaitForSingleObject(mutexHandle: (void *)g_hMutex, milliseconds: 0);
        if ( v7 != 0 && v7 != 128 )
        {
          v8 = Sys_WaitForSingleObject(mutexHandle: (void *)g_hWaitMutex, milliseconds: 0);
          if ( v8 == 0 || v8 == 128 )
            Sys_EnumWindows(callbackFunction: (int (__stdcall *)(HWND__ *, int))SendShutdownMsgFunc, lparam: 1);
        }
        *((_BYTE *)this + 8) |= 1u;
        this->m_iFriendsLoadPauseFrames = 1;
        return;
      }
      v6 = (void *)g_hMutex;
      Mutex = (HANDLE)g_hWaitMutex;
    }
    if ( v6 != nullptr )
    {
      Sys_ReleaseMutex(mutexHandle: v6);
      Mutex = (HANDLE)g_hWaitMutex;
    }
  }
  if ( Mutex != nullptr )
    Sys_ReleaseMutex(mutexHandle: Mutex);
  g_hMutex = 0;
  g_hWaitMutex = 0;
  _Error(this: (ISceneTokenProcessor *)&stru_104AD23C, a2: v10);
}

//------------------------------------------------------------------------------
// Address: 0x101D63C0
// Name: public: virtual void CGameUI::OnGameUIActivated(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::OnGameUIActivated(CGameUI *this)
{
  char v2; // al
  bool v3; // cl
  int v4; // eax
  CCStrike15BasePanel *v5; // eax
  const char *v6; // eax
  CCStrike15BasePanel *v7; // eax

  v2 = *((_BYTE *)this + 8) | 2;
  v3 = (*((_BYTE *)this + 8) & 2) != 0;
  *((_BYTE *)this + 8) = v2;
  if ( !v3 )
  {
    v4 = engine->GetActiveSplitScreenPlayerSlot(this: engine);
    SetGameUIActiveSplitScreenPlayerSlot(nSlot: v4);
  }
  engine->ClientCmd_Unrestricted(this: engine, a2: "setpause nomsg");
  *((_BYTE *)this + 8) &= ~8u;
  v5 = BasePanel();
  if ( !v5->IsVisible(this: v5)
    || this->IsInLevel(this)
    || (v6 = engine->GetLevelName(this: engine)) == nullptr
    || *v6 == 0
    || !engine->IsLevelMainMenuBackground(this: engine) )
  {
    v7 = BasePanel();
    v7->OnGameUIActivated(this: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6470
// Name: public: virtual void CGameUI::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::RunFrame(CGameUI *this)
{
  CCStrike15BasePanel *v2; // eax
  CCStrike15BasePanel *v3; // eax
  int m_iPlayGameStartupSound; // eax
  int m_iFriendsLoadPauseFrames; // eax
  DWORD v6; // eax
  unsigned __int8 *v7; // ebx
  int v8; // eax
  int v9; // edi
  int v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // ebx
  int v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // edi
  IBaseFileSystem *v16; // eax
  char *String; // eax
  int wide; // [esp+4h] [ebp-8h] BYREF
  int tall; // [esp+8h] [ebp-4h] BYREF

  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &wide, a3: &tall);
  v2 = BasePanel();
  vgui::Panel::SetSize(this: v2, wide, tall);
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&g_VModuleLoader);
  v3 = BasePanel();
  v3->RunFrame(this: v3);
  m_iPlayGameStartupSound = this->m_iPlayGameStartupSound;
  if ( m_iPlayGameStartupSound <= 0 )
    CGameUI::UpdateBackgroundMusic(this);
  else
    this->m_iPlayGameStartupSound = m_iPlayGameStartupSound - 1;
  if ( (*((_BYTE *)this + 8) & 1) != 0 )
  {
    m_iFriendsLoadPauseFrames = this->m_iFriendsLoadPauseFrames;
    this->m_iFriendsLoadPauseFrames = m_iFriendsLoadPauseFrames - 1;
    if ( m_iFriendsLoadPauseFrames < 1 && g_hMutex != 0 && g_hWaitMutex != 0 )
    {
      v6 = Sys_WaitForSingleObject(mutexHandle: (void *)g_hMutex, milliseconds: 0);
      if ( v6 == 0 || v6 == 128 )
      {
        *((_BYTE *)this + 8) &= ~1u;
        CVGuiSystemModuleLoader::LoadPlatformModules(
          this: &g_VModuleLoader,
          factorylist: &this->m_GameFactory,
          factorycount: 1,
          useSteamModules: false);
        Sys_ReleaseMutex(mutexHandle: (void *)g_hWaitMutex);
        v7 = (unsigned __int8 *)engine->GetGameDirectory(this: engine);
        strrchr(string: v7, chr: 0x2Fu);
        v9 = v8;
        if ( v8 != 0 || (strrchr(string: v7, chr: 0x5Cu), v9 = v10, v10 != 0) )
        {
          v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v11 != nullptr )
            v12 = KeyValues::KeyValues(this: v11, setName: "ActiveGameName");
          else
            v12 = nullptr;
          KeyValues::SetString(this: v12, keyName: "name", value: (char *)(v9 + 1));
          v13 = engine->GetAppID(this: engine);
          KeyValues::SetInt(this: v12, keyName: "appid", value: v13);
          v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v14 != nullptr )
            v15 = KeyValues::KeyValues(this: v14, setName: "ModInfo");
          else
            v15 = nullptr;
          if ( g_pFullFileSystem != nullptr )
            v16 = &g_pFullFileSystem->IBaseFileSystem;
          else
            v16 = nullptr;
          if ( KeyValues::LoadFromFile(
                 this: v15,
                 filesystem: v16,
                 resourceName: "gameinfo.txt",
                 pathID: nullptr,
                 pfnEvaluateSymbolProc: nullptr) )
          {
            String = KeyValues::GetString(this: v15, keyName: "game", defaultValue: prType);
            KeyValues::SetString(this: v12, keyName: "game", value: String);
          }
          KeyValues::deleteThis(this: v15);
          CVGuiSystemModuleLoader::PostMessageToAllModules(this: &g_VModuleLoader, message: v12);
        }
        if ( this->m_iGameIP != 0 )
          CGameUI::SendConnectedToGameMessage(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D6660
// Name: public: virtual void CGameUI::OnConnectToServer2(char const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::OnConnectToServer2(CGameUI *this, const char *game, int IP, int connectionPort, int queryPort)
{
  this->m_iGameIP = IP;
  this->m_iGameConnectionPort = connectionPort;
  this->m_iGameQueryPort = queryPort;
  CGameUI::SendConnectedToGameMessage(this);
}

//------------------------------------------------------------------------------
// Address: 0x101D6680
// Name: public: virtual void CGameUI::OnLevelLoadingFinished(bool,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameUI::OnLevelLoadingFinished(
        CGameUI *this,
        BOOL bError,
        const char *failureReason,
        const char *extendedReason)
{
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  CCStrike15BasePanel *v7; // eax

  this->StopProgressBar(this, a2: bError, a3: failureReason, a4: extendedReason);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "LoadingFinished");
  else
    v6 = nullptr;
  CVGuiSystemModuleLoader::PostMessageToAllModules(this: &g_VModuleLoader, message: v6);
  v7 = BasePanel();
  v7->OnLevelLoadingFinished(this: v7);
  CGameUI::HideLoadingBackgroundDialog(this);
  engine->ExecuteClientCmd(this: engine, a2: "gameui_hide");
}
