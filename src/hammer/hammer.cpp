// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/hammer.cpp
// Functions: 344
// ============================================================

#include "hammer\hammer.h"

//------------------------------------------------------------------------------
// Address: 0x1003CC30
// Name: public: bool CSteamAPIContext::Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSteamAPIContext::Init(CSteamAPIContext *this)
{
  int HSteamPipe; // esi
  int v4; // eax
  ISteamUser *v5; // eax
  int v6; // eax
  ISteamFriends *v7; // eax
  int v8; // eax
  ISteamUtils *v9; // eax
  int v10; // eax
  ISteamMatchmaking *v11; // eax
  int v12; // eax
  ISteamMatchmakingServers *v13; // eax
  int v14; // eax
  ISteamUserStats *v15; // eax
  int v16; // eax
  ISteamApps *v17; // eax
  int v18; // eax
  ISteamNetworking *v19; // eax
  int v20; // eax
  ISteamRemoteStorage *v21; // eax
  int hSteamUser; // [esp+8h] [ebp-4h]

  if ( _SteamClient() == 0 )
    return false;
  hSteamUser = _SteamAPI_GetHSteamUser();
  HSteamPipe = _SteamAPI_GetHSteamPipe();
  v4 = _SteamClient();
  v5 = (ISteamUser *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v4 + 20))(
                       a1: v4,
                       a2: hSteamUser,
                       a3: HSteamPipe,
                       a4: "SteamUser014");
  this->m_pSteamUser = v5;
  if ( v5 == nullptr )
    return false;
  v6 = _SteamClient();
  v7 = (ISteamFriends *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v6 + 32))(
                          a1: v6,
                          a2: hSteamUser,
                          a3: HSteamPipe,
                          a4: "SteamFriends008");
  this->m_pSteamFriends = v7;
  if ( v7 == nullptr )
    return false;
  v8 = _SteamClient();
  v9 = (ISteamUtils *)(*(int (__thiscall **)(int, int, const char *))(*(_DWORD *)v8 + 36))(
                        a1: v8,
                        a2: HSteamPipe,
                        a3: "SteamUtils005");
  this->m_pSteamUtils = v9;
  if ( v9 == nullptr )
    return false;
  v10 = _SteamClient();
  v11 = (ISteamMatchmaking *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v10 + 40))(
                               a1: v10,
                               a2: hSteamUser,
                               a3: HSteamPipe,
                               a4: "SteamMatchMaking008");
  this->m_pSteamMatchmaking = v11;
  if ( v11 == nullptr )
    return false;
  v12 = _SteamClient();
  v13 = (ISteamMatchmakingServers *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v12 + 48))(
                                      a1: v12,
                                      a2: hSteamUser,
                                      a3: HSteamPipe,
                                      a4: "SteamMatchMakingServers002");
  this->m_pSteamMatchmakingServers = v13;
  if ( v13 == nullptr )
    return false;
  v14 = _SteamClient();
  v15 = (ISteamUserStats *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v14 + 56))(
                             a1: v14,
                             a2: hSteamUser,
                             a3: HSteamPipe,
                             a4: "STEAMUSERSTATS_INTERFACE_VERSION009");
  this->m_pSteamUserStats = v15;
  if ( v15 == nullptr )
    return false;
  v16 = _SteamClient();
  v17 = (ISteamApps *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v16 + 64))(
                        a1: v16,
                        a2: hSteamUser,
                        a3: HSteamPipe,
                        a4: "STEAMAPPS_INTERFACE_VERSION004");
  this->m_pSteamApps = v17;
  if ( v17 == nullptr )
    return false;
  v18 = _SteamClient();
  v19 = (ISteamNetworking *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v18 + 68))(
                              a1: v18,
                              a2: hSteamUser,
                              a3: HSteamPipe,
                              a4: "SteamNetworking005");
  this->m_pSteamNetworking = v19;
  if ( v19 == nullptr )
    return false;
  v20 = _SteamClient();
  v21 = (ISteamRemoteStorage *)(*(int (__thiscall **)(int, int, int, const char *))(*(_DWORD *)v20 + 72))(
                                 a1: v20,
                                 a2: hSteamUser,
                                 a3: HSteamPipe,
                                 a4: "STEAMREMOTESTORAGE_INTERFACE_VERSION004");
  this->m_pSteamRemoteStorage = v21;
  return v21 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003CDB0
// Name: public: CButton::CButton(void)
// Source: json
//------------------------------------------------------------------------------
CButton *__thiscall CButton::CButton(CButton *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CButton_vtbl *)&CButton::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003CE30
// Name: public: COptionsTextures::~COptionsTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsTextures::~COptionsTextures(COptionsTextures *this)
{
  CStringArray::~CStringArray(this: &this->TextureFiles);
}

//------------------------------------------------------------------------------
// Address: 0x1003CE80
// Name: bool IsRunningInEngine(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsRunningInEngine()
{
  return g_pEngineAPI != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003CE90
// Name: int WrapFunctionWithMinidumpHandler(int (*)(void __near *),void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl WrapFunctionWithMinidumpHandler(int (__cdecl *pfn)(void *), void *pParam)
{
  int v2; // eax
  int result; // eax
  int v4; // [esp+0h] [ebp-20h] BYREF
  int nRetVal; // [esp+Ch] [ebp-14h]
  int *v6; // [esp+10h] [ebp-10h]
  int v7; // [esp+1Ch] [ebp-4h]

  v6 = &v4;
  if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
    return pfn(a1: pParam);
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-nominidumps") != 0 )
    return pfn(a1: pParam);
  _set_se_translator(pNew: _SteamWriteMiniDumpUsingExceptionInfo);
  v7 = 0;
  result = pfn(a1: pParam);
  nRetVal = result;
  v7 = -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003CF50
// Name: void Msg(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Msg(MWMSGTYPE type, const char *fmt, ...)
{
  int v2; // edi
  char v3; // bl
  char *v4; // esi
  char szBuf[512]; // [esp+0h] [ebp-200h] BYREF
  va_list ap; // [esp+210h] [ebp+10h] BYREF

  va_start(ap, fmt);
  if ( g_pwndMessage != nullptr )
  {
    v2 = _vsnprintf(string: szBuf, count: 0x200u, format: fmt, ap);
    if ( type == mwError || type == mwWarning )
      CMessageWnd::ShowMessageWindow(this: g_pwndMessage);
    v3 = 0;
    v4 = &szBuf[149];
    do
    {
      if ( v2 >= 150 )
      {
        v3 = *v4;
        *v4 = 0;
      }
      CMessageWnd::AddMsg(this: g_pwndMessage, type, msg: v4 - 149);
      if ( v2 >= 150 )
      {
        *v4 = v3;
        v4 += 149;
      }
      v2 -= 149;
    }
    while ( v2 > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CFF0
// Name: public: virtual void CHammerDocTemplate::CloseAllDocuments(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammerDocTemplate::CloseAllDocuments(CHammerDocTemplate *this, int bEndSession)
{
  CDocument *v3; // edi
  _DWORD *v4; // eax
  __POSITION *pos; // [esp+8h] [ebp-4h] BYREF

  while ( 1 )
  {
    pos = this->GetFirstDocPosition(this);
    if ( pos == nullptr )
      break;
    while ( 1 )
    {
      v3 = this->GetNextDoc(this, a2: &pos);
      v4 = __RTDynamicCast(
             inptr: v3,
             VfDelta: 0,
             SrcType: &CDocument `RTTI Type Descriptor',
             TargetType: &CMapDoc `RTTI Type Descriptor',
             isReference: 0);
      if ( v4 != nullptr && v4[120] == 0 )
        break;
      if ( pos == nullptr )
        return;
    }
    v3->OnCloseDocument(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D060
// Name: public: void CHammerDocTemplate::UpdateInstanceMap(class CMapDoc __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammerDocTemplate::UpdateInstanceMap(CHammerDocTemplate *this, CMapDoc *pInstanceMapDoc)
{
  CDocument *v3; // eax
  CMapDoc *v4; // eax
  __POSITION *pos; // [esp+4h] [ebp-4h] BYREF

  pos = this->GetFirstDocPosition(this);
  while ( pos != nullptr )
  {
    v3 = this->GetNextDoc(this, a2: &pos);
    v4 = (CMapDoc *)__RTDynamicCast(
                      inptr: v3,
                      VfDelta: 0,
                      SrcType: &CDocument `RTTI Type Descriptor',
                      TargetType: &CMapDoc `RTTI Type Descriptor',
                      isReference: 0);
    if ( v4 != nullptr && v4 != pInstanceMapDoc )
      v4->UpdateInstanceMap(this: v4, a2: pInstanceMapDoc);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D120
// Name: public: virtual int CWinApp::SupportsRestartManager(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::SupportsRestartManager(CWinApp *this)
{
  return this->m_dwRestartManagerSupportFlags & 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003D130
// Name: public: virtual int CWinApp::SupportsApplicationRecovery(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::SupportsApplicationRecovery(CWinApp *this)
{
  return this->m_dwRestartManagerSupportFlags & 2;
}

//------------------------------------------------------------------------------
// Address: 0x1003D140
// Name: public: virtual int CWinApp::SupportsAutosaveAtRestart(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::SupportsAutosaveAtRestart(CWinApp *this)
{
  return this->m_dwRestartManagerSupportFlags & 4;
}

//------------------------------------------------------------------------------
// Address: 0x1003D150
// Name: public: virtual int CWinApp::SupportsAutosaveAtInterval(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::SupportsAutosaveAtInterval(CWinApp *this)
{
  return this->m_dwRestartManagerSupportFlags & 8;
}

//------------------------------------------------------------------------------
// Address: 0x1003D160
// Name: public: virtual int CWinApp::ReopenPreviousFilesAtRestart(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::ReopenPreviousFilesAtRestart(CWinApp *this)
{
  return this->m_dwRestartManagerSupportFlags & 0x10;
}

//------------------------------------------------------------------------------
// Address: 0x1003D170
// Name: public: virtual int CWinApp::RestoreAutosavedFilesAtRestart(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::RestoreAutosavedFilesAtRestart(CWinApp *this)
{
  return this->m_dwRestartManagerSupportFlags & 0x20;
}

//------------------------------------------------------------------------------
// Address: 0x1003D180
// Name: public: virtual unsigned long CWinApp::GetApplicationRecoveryPingInterval(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::GetApplicationRecoveryPingInterval(CWinApp *this)
{
  return 5000;
}

//------------------------------------------------------------------------------
// Address: 0x1003D190
// Name: public: virtual void __near * CHammer::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHammer *__thiscall CHammer::QueryInterface(CHammer *this, const char *pInterfaceName)
{
  unsigned int v3; // eax

  v3 = std::char_traits<char>::length(str: "Hammer001");
  if ( V_strncmp(s1: pInterfaceName, s2: "Hammer001", count: v3 + 1) != 0 )
    return nullptr;
  else
    return this != (CHammer *)184 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003D1D0
// Name: public: virtual void CHammer::NoteEngineGotFocus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::NoteEngineGotFocus(CHammer *this)
{
  CHammerVGui *v1; // eax

  v1 = HammerVGui();
  CHammerVGui::SetFocus(this: v1, pVGuiWnd: nullptr);
  CMapDoc::NoteEngineGotFocus();
}

//------------------------------------------------------------------------------
// Address: 0x1003D1F0
// Name: public: virtual bool CHammer::IsHammerVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHammer::IsHammerVisible(CHammer *this)
{
  int v1; // eax

  v1 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 46) + 116))(a1: (char *)this - 184);
  return v1 != 0 && IsWindowVisible(hWnd: *(HWND *)(v1 + 32));
}

//------------------------------------------------------------------------------
// Address: 0x1003D220
// Name: public: virtual void CHammer::ToggleHammerVisible(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::ToggleHammerVisible(CHammer *this)
{
  CWnd *v1; // esi

  v1 = (CWnd *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 46) + 116))(a1: (char *)this - 184);
  if ( v1 != nullptr )
  {
    if ( IsWindowVisible(hWnd: v1->m_hWnd) )
      CWnd::ShowWindow(this: v1, nCmdShow: 0);
    else
      CWnd::ShowWindow(this: v1, nCmdShow: 5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D260
// Name: public: virtual bool CHammer::HammerPreTranslateMessage(struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHammer::HammerPreTranslateMessage(CHammer *this, tagMSG *pMsg)
{
  AFX_MODULE_STATE *StaticModuleState; // eax
  bool v4; // bl
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+8h] [ebp-14h] BYREF
  int v7; // [esp+18h] [ebp-4h]

  StaticModuleState = AfxGetStaticModuleState();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: StaticModuleState);
  v7 = 0;
  AfxGetThreadState()->m_msgCur = *pMsg;
  v4 = (*(int (__thiscall **)(char *, tagMSG *))(*((_DWORD *)this - 46) + 88))(a1: (char *)this - 184, a2: pMsg) != 0;
  v7 = -1;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1003D300
// Name: public: virtual bool CHammer::HammerIsIdleMessage(struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHammer::HammerIsIdleMessage(CHammer *this, tagMSG *pMsg)
{
  AFX_MODULE_STATE *StaticModuleState; // eax
  bool v5; // bl
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-14h] BYREF
  int v7; // [esp+14h] [ebp-4h]

  StaticModuleState = AfxGetStaticModuleState();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: StaticModuleState);
  v7 = 0;
  if ( pMsg->message == 275 )
  {
    v7 = -1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
    return false;
  }
  else
  {
    v5 = (*(int (__thiscall **)(char *, tagMSG *))(*((_DWORD *)this - 46) + 100))(a1: (char *)this - 184, a2: pMsg) == 1;
    v7 = -1;
    AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
    return v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D3A0
// Name: public: virtual bool CHammer::HammerOnIdle(long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHammer::HammerOnIdle(CHammer *this, int count)
{
  AFX_MODULE_STATE *StaticModuleState; // eax
  bool v4; // bl
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+8h] [ebp-14h] BYREF
  int v7; // [esp+18h] [ebp-4h]

  StaticModuleState = AfxGetStaticModuleState();
  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: StaticModuleState);
  v7 = 0;
  v4 = (*(int (__thiscall **)(char *, int))(*((_DWORD *)this - 46) + 96))(a1: (char *)this - 184, a2: count) != 0;
  v7 = -1;
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1003D420
// Name: EnsureTrailingBackslash
// Source: json
//------------------------------------------------------------------------------
void __usercall EnsureTrailingBackslash(char *psz@<eax>)
{
  if ( *psz != 0 && psz[strlen(psz) - 1] != 92 )
    strcat(psz, "\\");
}

//------------------------------------------------------------------------------
// Address: 0x1003D460
// Name: public: void CHammer::BeginImportWCSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::BeginImportWCSettings(CHammer *this)
{
  s_pszOldAppName = this->m_pszAppName;
  this->m_pszAppName = "Worldcraft";
  CWinApp::SetRegistryKey(this, lpszRegistryKey: "Valve");
}

//------------------------------------------------------------------------------
// Address: 0x1003D480
// Name: public: void CHammer::BeginImportVHESettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::BeginImportVHESettings(CHammer *this)
{
  s_pszOldAppName = this->m_pszAppName;
  this->m_pszAppName = "Valve Hammer Editor";
  CWinApp::SetRegistryKey(this, lpszRegistryKey: "Valve");
}

//------------------------------------------------------------------------------
// Address: 0x1003D4A0
// Name: public: void CHammer::EndImportSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::EndImportSettings(CHammer *this)
{
  this->m_pszAppName = s_pszOldAppName;
  CWinApp::SetRegistryKey(this, lpszRegistryKey: "Valve");
}

//------------------------------------------------------------------------------
// Address: 0x1003D4C0
// Name: public: void CHammer::GetDirectory(enum DirIndex_t,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::GetDirectory(CHammer *this, DirIndex_t dir, char *p)
{
  char *v3; // eax
  char *m_szAppDir; // ecx
  char *v5; // esi
  char v6; // dl
  char *m_szPrefabDir; // edx
  char *v8; // esi
  char v9; // al
  char *v10; // eax
  int v11; // edx
  char v12; // cl
  char *v13; // ecx
  char *v14; // edx
  char v15; // al
  char *m_szGameExeDir; // edx
  char *v17; // esi
  char v18; // cl
  char *m_szModDir; // edx
  char *v20; // esi
  char v21; // cl
  char *v22; // ecx
  char *v23; // edx
  char v24; // al
  char *m_szAutosaveDir; // ecx
  char *v26; // esi
  char v27; // dl

  switch ( dir )
  {
    case DIR_PROGRAM:
      v3 = p;
      m_szAppDir = this->m_szAppDir;
      v5 = (char *)(p - m_szAppDir);
      do
      {
        v6 = *m_szAppDir;
        m_szAppDir[(_DWORD)v5] = *m_szAppDir;
        ++m_szAppDir;
      }
      while ( v6 != 0 );
      goto LABEL_26;
    case DIR_PREFABS:
      m_szPrefabDir = g_pGameConfig->m_szPrefabDir;
      v8 = p;
      do
      {
        v9 = *m_szPrefabDir;
        *v8++ = *m_szPrefabDir++;
      }
      while ( v9 != 0 );
      if ( *p == 0 )
      {
        v10 = this->m_szAppDir;
        v11 = p - this->m_szAppDir;
        do
        {
          v12 = *v10;
          v10[v11] = *v10;
          ++v10;
        }
        while ( v12 != 0 );
        EnsureTrailingBackslash(psz: p);
        strcat(p, "Prefabs");
        v13 = p;
        v14 = g_pGameConfig->m_szPrefabDir;
        do
        {
          v15 = *v13;
          *v14++ = *v13++;
        }
        while ( v15 != 0 );
      }
      if ( access(path: p, amode: 0) == -1 )
        CreateDirectoryA(lpPathName: p, lpSecurityAttributes: nullptr);
      return;
    case DIR_GAME_EXE:
      v3 = p;
      m_szGameExeDir = g_pGameConfig->m_szGameExeDir;
      v17 = p;
      do
      {
        v18 = *m_szGameExeDir;
        *v17++ = *m_szGameExeDir++;
      }
      while ( v18 != 0 );
      goto LABEL_26;
    case DIR_MOD:
      v3 = p;
      m_szModDir = g_pGameConfig->m_szModDir;
      v20 = p;
      do
      {
        v21 = *m_szModDir;
        *v20++ = *m_szModDir++;
      }
      while ( v21 != 0 );
      goto LABEL_26;
    case DIR_MATERIALS:
      v22 = g_pGameConfig->m_szModDir;
      v23 = p;
      do
      {
        v24 = *v22;
        *v23++ = *v22++;
      }
      while ( v24 != 0 );
      EnsureTrailingBackslash(psz: p);
      V_strncat(pDest: p, pSrc: "materials\\", destBufferSize: 0x104u, max_chars_to_copy: -1);
      return;
    case DIR_AUTOSAVE:
      v3 = p;
      m_szAutosaveDir = this->m_szAutosaveDir;
      v26 = (char *)(p - m_szAutosaveDir);
      do
      {
        v27 = *m_szAutosaveDir;
        m_szAutosaveDir[(_DWORD)v26] = *m_szAutosaveDir;
        ++m_szAutosaveDir;
      }
      while ( v27 != 0 );
LABEL_26:
      EnsureTrailingBackslash(psz: v3);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D660
// Name: public: void CHammer::SetDirectory(enum DirIndex_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::SetDirectory(CHammer *this, DirIndex_t dir, const char *p)
{
  const char *v3; // eax
  int v4; // edx
  char v5; // cl

  if ( dir == DIR_AUTOSAVE )
  {
    v3 = p;
    v4 = this->m_szAutosaveDir - p;
    do
    {
      v5 = *v3;
      v3[v4] = *v3;
      ++v3;
    }
    while ( v5 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D690
// Name: public: virtual void CSimpleWindowsLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWindowsLoggingListener::Log(
        CSimpleWindowsLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  int v3; // ecx

  if ( (unsigned __int8)_Plat_IsInDebugSession(a1: this) != 0 )
    _Plat_DebugString(a1: pMessage);
  if ( pContext->m_Severity == LS_ERROR )
  {
    if ( (unsigned __int8)_Plat_IsInDebugSession(a1: v3) != 0 )
      __debugbreak();
    _Plat_MessageBox(a1: "Error", a2: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D6E0
// Name: void UpdatePrefabs_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdatePrefabs_Init()
{
  AFX_MODULE_STATE *ModuleState; // eax
  UINT LastError; // eax
  char szPrefabDir[260]; // [esp+0h] [ebp-104h] BYREF

  if ( dwChangeHandle == nullptr )
  {
    ModuleState = AfxGetModuleState();
    CHammer::GetDirectory(this: (CHammer *)ModuleState->m_pCurrentWinApp, dir: DIR_PREFABS, p: szPrefabDir);
    dwChangeHandle = FindFirstChangeNotificationA(lpPathName: szPrefabDir, bWatchSubtree: true, dwNotifyFilter: 3u);
    if ( dwChangeHandle == (HANDLE)-1 )
    {
      LastError = GetLastError();
      ExitProcess(uExitCode: LastError);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D740
// Name: void UpdatePrefabs(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdatePrefabs()
{
  CToolManager *v0; // eax
  CMainFrame *MainWnd; // eax
  UINT LastError; // eax
  ToolID_t ActiveToolID; // [esp-4h] [ebp-4h]

  if ( WaitForSingleObject(hHandle: dwChangeHandle, dwMilliseconds: 0) == 0 )
  {
    CPrefabLibrary::FreeAllLibraries();
    CPrefabLibrary::LoadAllLibraries();
    v0 = ToolManager();
    ActiveToolID = CToolManager::GetActiveToolID(this: v0);
    MainWnd = GetMainWnd();
    CObjectBar::UpdateListForTool(this: &MainWnd->m_ObjectBar, iTool: ActiveToolID);
    if ( !FindNextChangeNotification(hChangeHandle: dwChangeHandle) )
    {
      LastError = GetLastError();
      ExitProcess(uExitCode: LastError);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003D7A0
// Name: void HammerFileSystem_ReportSearchPath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HammerFileSystem_ReportSearchPath(const char *szPathID)
{
  const char *i; // eax
  char string[4096]; // [esp+4h] [ebp-1000h] BYREF

  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: szPathID, a3: true, a4: string, a5: 4096);
  Msg(type: mwStatus, fmt: "------------------------------------------------------------------");
  for ( i = strtok(string, control: ";"); i != nullptr; i = strtok(string: nullptr, control: ";") )
    Msg(type: mwStatus, fmt: "Search Path (%s): %s", szPathID, i);
}

//------------------------------------------------------------------------------
// Address: 0x1003D820
// Name: public: virtual char const __near * CHammer::GetDefaultMod(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CHammer::GetDefaultMod(CHammer *this)
{
  return CGameConfig::GetMod(this: g_pGameConfig);
}

//------------------------------------------------------------------------------
// Address: 0x1003D830
// Name: public: virtual char const __near * CHammer::GetDefaultGame(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CHammer::GetDefaultGame(CHammer *this)
{
  return CGameConfig::GetGame(this: g_pGameConfig);
}

//------------------------------------------------------------------------------
// Address: 0x1003D840
// Name: public: virtual char const __near * CHammer::GetDefaultModFullPath(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CHammer::GetDefaultModFullPath(CHammer *this)
{
  return g_pGameConfig->m_szModDir;
}

//------------------------------------------------------------------------------
// Address: 0x1003D850
// Name: public: virtual enum RequestRetval_t CHammer::RequestNewConfig(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHammer::RequestNewConfig(CHammer *this)
{
  return !COptions::RunConfigurationDialog(this: &Options);
}

//------------------------------------------------------------------------------
// Address: 0x1003D870
// Name: public: void CHammer::BeginClosing(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::BeginClosing(CHammer *this)
{
  this->m_bClosing = true;
}

//------------------------------------------------------------------------------
// Address: 0x1003D880
// Name: public: virtual int CHammer::ExitInstance(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHammer::ExitInstance(CHammer *this)
{
  CWnd::DestroyWindow(this: &g_ShellMessageWnd);
  FindCloseChangeNotification(hChangeHandle: dwChangeHandle);
  if ( !this->m_bFoundryMode )
    _LoggingSystem_PopLoggingState(a1: 0);
  CWinApp::SaveStdProfileSettings(this);
  return CWinApp::ExitInstance(this);
}

//------------------------------------------------------------------------------
// Address: 0x1003D8C0
// Name: public: static void CHammer::SetIsNewDocumentVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CHammer::SetIsNewDocumentVisible(bool bIsVisible)
{
  CHammer::m_bIsNewDocumentVisible = bIsVisible;
}

//------------------------------------------------------------------------------
// Address: 0x1003D8D0
// Name: public: static bool CHammer::IsNewDocumentVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CHammer::IsNewDocumentVisible()
{
  return CHammer::m_bIsNewDocumentVisible;
}

//------------------------------------------------------------------------------
// Address: 0x1003D8E0
// Name: public: void CHammer::SetCustomAccelerator(struct HWND__ __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::SetCustomAccelerator(CHammer *this, HWND__ *hWnd, unsigned __int16 nID)
{
  AFX_MODULE_STATE *ModuleState; // eax

  this->m_CustomAcceleratorWindow = hWnd;
  ModuleState = AfxGetModuleState();
  this->m_CustomAccelerator = LoadAcceleratorsA(
                                hInstance: ModuleState->m_hCurrentInstanceHandle,
                                lpTableName: (LPCSTR)nID);
}

//------------------------------------------------------------------------------
// Address: 0x1003D910
// Name: public: void CHammer::ClearCustomAccelerator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::ClearCustomAccelerator(CHammer *this)
{
  this->m_CustomAcceleratorWindow = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003D920
// Name: public: virtual CAboutDlg::~CAboutDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAboutDlg::~CAboutDlg(CAboutDlg *this)
{
  CButton::~CButton(this: &this->m_Order);
  CStatic::~CStatic(this: &this->m_cRedHerring);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x1003D980
// Name: protected: virtual void CAboutDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAboutDlg::DoDataExchange(CAboutDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: 1332, rControl: &this->m_cRedHerring);
  DDX_Control(pDX, nIDC: 1206, rControl: &this->m_Order);
}

//------------------------------------------------------------------------------
// Address: 0x1003D9C0
// Name: protected: void CAboutDlg::OnOrder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAboutDlg::OnOrder(CAboutDlg *this)
{
  char *v1; // eax
  char v2; // cl
  char v3; // [esp-1h] [ebp-105h] BYREF
  char szBuf[260]; // [esp+0h] [ebp-104h] BYREF

  GetWindowsDirectoryA(lpBuffer: szBuf, uSize: 0x104u);
  v1 = &v3;
  do
    v2 = *++v1;
  while ( v2 != 0 );
  strcpy(v1, "\\notepad.exe");
  _spawnl(modeflag: 1, pathname: szBuf, arglist: szBuf, "order.txt", 0);
}

//------------------------------------------------------------------------------
// Address: 0x1003DA30
// Name: protected: virtual int CAboutDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAboutDlg::OnInitDialog(CAboutDlg *this)
{
  CWnd *DlgItem; // esi
  int v3; // edi
  char szTemp2[260]; // [esp+4h] [ebp-208h] BYREF
  char szTemp1[260]; // [esp+108h] [ebp-104h] BYREF

  CDialog::OnInitDialog(this);
  SendMessageA(hWnd: this->m_Order.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  DlgItem = CWnd::GetDlgItem(this, nID: 1451);
  if ( DlgItem != nullptr )
  {
    v3 = build_number();
    CWnd::GetWindowTextA(this: DlgItem, lpszString: szTemp1, nMaxCount: 260);
    sprintf(string: szTemp2, format: szTemp1, v3);
    CWnd::SetWindowTextA(this: DlgItem, lpszString: szTemp2);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003DAC0
// Name: public: void CHammer::OnAppAbout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::OnAppAbout(CHammer *this)
{
  CAboutDlg aboutDlg; // [esp+0h] [ebp-18Ch] BYREF
  void *p_m_cRedHerring; // [esp+17Ch] [ebp-10h]
  int v3; // [esp+188h] [ebp-4h]

  CDialog::CDialog(this: &aboutDlg, nIDTemplate: 0x64u, pParentWnd: nullptr);
  v3 = 0;
  aboutDlg.__vftable = (CAboutDlg_vtbl *)&CAboutDlg::`vftable';
  p_m_cRedHerring = &aboutDlg.m_cRedHerring;
  CWnd::CWnd(this: &aboutDlg.m_cRedHerring);
  aboutDlg.m_cRedHerring.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  LOBYTE(v3) = 2;
  p_m_cRedHerring = &aboutDlg.m_Order;
  CWnd::CWnd(this: &aboutDlg.m_Order);
  aboutDlg.m_Order.__vftable = (CButton_vtbl *)&CButton::`vftable';
  v3 = 5;
  CDialog::DoModal(this: &aboutDlg);
  v3 = 7;
  CButton::~CButton(this: &aboutDlg.m_Order);
  LOBYTE(v3) = 6;
  CStatic::~CStatic(this: &aboutDlg.m_cRedHerring);
  v3 = -1;
  CDialog::~CDialog(this: &aboutDlg);
}

//------------------------------------------------------------------------------
// Address: 0x1003DB90
// Name: public: void CHammer::OnFileNew(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::OnFileNew(CHammer *this)
{
  CMainFrame *MainWnd; // eax

  this->pMapDocTemplate->OpenDocumentFile(this: this->pMapDocTemplate, a2: nullptr, a3: 1);
  if ( Options.general.bLoadwinpos != 0 && Options.general.bIndependentwin != 0 )
  {
    MainWnd = GetMainWnd();
    CMainFrame::LoadWindowStates(this: MainWnd, pFile: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DBD0
// Name: public: virtual class CDocument __near * CHammer::OpenDocumentFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDocument *__thiscall CHammer::OpenDocumentFile(CHammer *this, const char *lpszFileName)
{
  return this->OpenDocumentOrInstanceFile(this, a2: lpszFileName);
}

//------------------------------------------------------------------------------
// Address: 0x1003DBE0
// Name: public: virtual int CHammer::PreTranslateMessage(struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHammer::PreTranslateMessage(CHammer *this, tagMSG *pMsg)
{
  unsigned int message; // eax
  unsigned int wParam; // eax
  HWND__ *m_CustomAcceleratorWindow; // eax
  char className[80]; // [esp+8h] [ebp-50h] BYREF

  if ( CSplashWnd::PreTranslateAppMessage(pMsg) != 0 )
    return 1;
  message = pMsg->message;
  if ( message == 256 || message == 258 )
  {
    wParam = pMsg->wParam;
    if ( wParam != 27 && wParam != 13 && wParam != 9 && wParam != 38 && wParam != 40 && wParam != 37 && wParam != 39 )
    {
      GetClassNameA(hWnd: pMsg->hwnd, lpClassName: className, nMaxCount: 80);
      if ( _V_stricmp(s1: className, s2: "edit") == 0 || V_strnicmp(s1: className, s2: "afxwnd", n: 6) == 0 )
        return 0;
      m_CustomAcceleratorWindow = this->m_CustomAcceleratorWindow;
      if ( m_CustomAcceleratorWindow != nullptr
        && TranslateAcceleratorA(hWnd: m_CustomAcceleratorWindow, hAccTable: this->m_CustomAccelerator, lpMsg: pMsg) != 0 )
      {
        return 1;
      }
    }
  }
  return CWinThread::PreTranslateMessage(this, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x1003DCD0
// Name: public: void CHammer::SetForceRenderNextFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::SetForceRenderNextFrame(CHammer *this)
{
  this->m_bForceRenderNextFrame = true;
}

//------------------------------------------------------------------------------
// Address: 0x1003DCE0
// Name: protected: void CHammer::UpdateLighting(class CMapDoc __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::UpdateLighting(CHammer *this, CMapDoc *pDoc)
{
  IBSPLighting *m_pBSPLighting; // esi
  int v4; // edi
  char string[8]; // [esp+14h] [ebp-104h] BYREF
  char str[256]; // [esp+1Ch] [ebp-FCh]

  m_pBSPLighting = pDoc->m_pBSPLighting;
  v4 = -10000;
  if ( m_pBSPLighting == nullptr )
    goto LABEL_8;
  *(_DWORD *)&str[248] = GetTickCount();
  if ( *(_DWORD *)&str[248] - lastTime >= 0xC8 )
  {
    v4 = (int)(((double (__thiscall *)(IBSPLighting *))m_pBSPLighting->GetPercentComplete)(a1: m_pBSPLighting) * 10000.0);
    lastTime = *(_DWORD *)&str[248];
  }
  else
  {
    v4 = lastPercent;
  }
  if ( m_pBSPLighting->CheckForNewLightmaps(this: m_pBSPLighting) )
  {
    this->m_bForceRenderNextFrame = true;
    CMapDoc::UpdateAllViews(this: pDoc, nFlags: 64, ub: nullptr);
  }
  if ( v4 != -10000 )
  {
    if ( v4 != lastPercent )
    {
      sprintf(string, format: "%.2f%%", (float)((float)v4 * 0.0099999998));
      SetStatusText(nIndex: 6, pszText: string);
    }
    lastPercent = v4;
  }
  else
  {
LABEL_8:
    SetStatusText(nIndex: 6, pszText: "<->");
    lastPercent = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DDE0
// Name: public: virtual int CHammer::OnIdle(long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHammer::OnIdle(CHammer *this, int lCount)
{
  UpdatePrefabs();
  if ( CMapDoc::m_pMapDoc != nullptr )
    CHammer::UpdateLighting(this, pDoc: CMapDoc::m_pMapDoc);
  CTextureSystem::UpdateFileChangeWatchers(this: &g_Textures);
  UpdateStudioFileChangeWatcher();
  return CWinApp::OnIdle(this, lCount);
}

//------------------------------------------------------------------------------
// Address: 0x1003DE20
// Name: public: bool CHammer::IsActiveApp(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHammer::IsActiveApp(CHammer *this)
{
  return this->m_bActiveApp;
}

//------------------------------------------------------------------------------
// Address: 0x1003DE30
// Name: public: void CHammer::OnActivateApp(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::OnActivateApp(CHammer *this, bool bActive)
{
  this->m_bActiveApp = bActive;
}

//------------------------------------------------------------------------------
// Address: 0x1003DE40
// Name: public: void CHammer::ReleaseVideoMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::ReleaseVideoMemory(CHammer *this)
{
  CDocTemplate *NextDocTemplate; // esi
  CMapDoc *v3; // eax
  __POSITION *pos; // [esp+4h] [ebp-8h] BYREF
  __POSITION *pos2; // [esp+8h] [ebp-4h] BYREF

  pos = CWinApp::GetFirstDocTemplatePosition(this);
  while ( pos != nullptr )
  {
    NextDocTemplate = CWinApp::GetNextDocTemplate(this, rPosition: &pos);
    pos2 = NextDocTemplate->GetFirstDocPosition(this: NextDocTemplate);
    while ( pos2 != nullptr )
    {
      v3 = (CMapDoc *)NextDocTemplate->GetNextDoc(this: NextDocTemplate, a2: &pos2);
      if ( v3 != nullptr )
        CMapDoc::ReleaseVideoMemory(this: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DEA0
// Name: public: void CHammer::SuppressVideoAllocation(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::SuppressVideoAllocation(CHammer *this, bool bSuppress)
{
  this->m_SuppressVideoAllocation = bSuppress;
}

//------------------------------------------------------------------------------
// Address: 0x1003DEB0
// Name: LessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl LessFunc(const _FILETIME *lhs, const _FILETIME *rhs)
{
  return CompareFileTime(lpFileTime1: lhs, lpFileTime2: rhs) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003DED0
// Name: public: void CHammer::ResetAutosaveTimer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::ResetAutosaveTimer(CHammer *this)
{
  CMainFrame *MainWnd; // eax

  Options.general.bEnableAutosave = 1;
  MainWnd = GetMainWnd();
  if ( MainWnd != nullptr )
    CMainFrame::ResetAutosaveTimer(this: MainWnd);
}

//------------------------------------------------------------------------------
// Address: 0x1003DEF0
// Name: public: struct MessageToLPreview __near & MessageToLPreview::operator=(struct MessageToLPreview const __near &)
// Source: json
//------------------------------------------------------------------------------
MessageToLPreview *__thiscall MessageToLPreview::operator=(MessageToLPreview *this, const MessageToLPreview *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003E220
// Name: public: virtual void CHammerMessageLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammerMessageLoggingListener::Log(
        CHammerMessageLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  LoggingSeverity_t m_Severity; // eax

  m_Severity = pContext->m_Severity;
  if ( m_Severity == LS_ERROR )
  {
    Msg(type: mwError, fmt: pMessage);
  }
  else if ( m_Severity == LS_WARNING )
  {
    Msg(type: mwWarning, fmt: pMessage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E260
// Name: public: virtual class CDocument __near * CHammerDocTemplate::OpenDocumentFile(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CDocument *__thiscall CHammerDocTemplate::OpenDocumentFile(
        CHammerDocTemplate *this,
        const char *lpszPathName,
        int bMakeVisible)
{
  return CMultiDocTemplate::OpenDocumentFile(this, lpszPathName, bMakeVisible: CHammer::m_bIsNewDocumentVisible);
}

//------------------------------------------------------------------------------
// Address: 0x1003E280
// Name: public: virtual void CHammerDocTemplate::InitialUpdateFrame(class CFrameWnd __near *,class CDocument __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammerDocTemplate::InitialUpdateFrame(
        CHammerDocTemplate *this,
        CFrameWnd *pFrame,
        CDocument *pDoc,
        int bMakeVisible)
{
  BOOL v4; // esi
  _BYTE *v5; // eax

  v4 = CHammer::m_bIsNewDocumentVisible;
  CDocTemplate::InitialUpdateFrame(this, pFrame, pDoc, bMakeVisible: CHammer::m_bIsNewDocumentVisible);
  if ( v4 )
  {
    v5 = __RTDynamicCast(
           inptr: pDoc,
           VfDelta: 0,
           SrcType: &CDocument `RTTI Type Descriptor',
           TargetType: &CMapDoc `RTTI Type Descriptor',
           isReference: 0);
    if ( v5 != nullptr )
      v5[361] = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E350
// Name: public: class CGameConfig __near * CHammer::PromptForGameConfig(void)
// Source: json
//------------------------------------------------------------------------------
CGameConfig *__thiscall CHammer::PromptForGameConfig(CHammer *this)
{
  CWnd *v1; // eax
  CGameConfig *m_pSelectedGame; // esi
  CEditGameConfigs dlg; // [esp+0h] [ebp-11Ch] BYREF
  int v5; // [esp+118h] [ebp-4h]

  v1 = this->GetMainWnd(this);
  CEditGameConfigs::CEditGameConfigs(this: &dlg, bSelectOnly: 1, pParent: v1);
  v5 = 0;
  if ( CDialog::DoModal(this: &dlg) == 1 )
  {
    m_pSelectedGame = dlg.m_pSelectedGame;
    v5 = 3;
    CListBox::~CListBox(this: &dlg.m_cConfigs);
    v5 = -1;
    CDialog::~CDialog(this: &dlg);
    return m_pSelectedGame;
  }
  else
  {
    v5 = 1;
    CListBox::~CListBox(this: &dlg.m_cConfigs);
    v5 = -1;
    CDialog::~CDialog(this: &dlg);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E410
// Name: public: virtual bool CHammer::InitSessionGameConfig(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHammer::InitSessionGameConfig(CHammer *this, const char *szGame)
{
  int v3; // eax
  CGameConfig *ConfigForGame; // eax
  const char *v5; // eax
  const char *v6; // esi

  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-chooseconfig") != 0 )
  {
    ConfigForGame = CHammer::PromptForGameConfig(this: (CHammer *)((char *)this - 184));
    if ( ConfigForGame == nullptr )
      goto LABEL_3;
LABEL_16:
    CGameConfig::SetActiveGame(pGame: ConfigForGame);
    return 1;
  }
  if ( szGame != nullptr && *szGame != 0 )
  {
    ConfigForGame = COptionsConfigs::FindConfigForGame(this: &Options.configs, szGame);
    if ( ConfigForGame != nullptr )
      goto LABEL_16;
    Msg(type: mwError, fmt: "Invalid game \"%s\" specified on the command-line, ignoring.", szGame);
  }
  else
  {
    v5 = getenv(option: "vproject");
    v6 = v5;
    if ( v5 != nullptr )
    {
      ConfigForGame = COptionsConfigs::FindConfigForGame(this: &Options.configs, szGame: v5);
      if ( ConfigForGame != nullptr )
        goto LABEL_16;
      Msg(type: mwError, fmt: "Invalid game \"%s\" found in VPROJECT environment variable, ignoring.", v6);
    }
  }
LABEL_3:
  if ( Options.configs.nConfigs == 1 )
  {
    if ( Options.configs.Configs.m_nSize <= 0 )
      AfxThrowInvalidArgException();
    ConfigForGame = (CGameConfig *)*Options.configs.Configs.m_pData;
  }
  else
  {
    ConfigForGame = CHammer::PromptForGameConfig(this: (CHammer *)((char *)this - 184));
  }
  if ( ConfigForGame != nullptr )
    goto LABEL_16;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003E560
// Name: protected: virtual struct AFX_MSGMAP const __near * CAboutDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CAboutDlg::GetMessageMap(CAboutDlg *this)
{
  return (const AFX_MSGMAP *)&off_105DAC08;
}

//------------------------------------------------------------------------------
// Address: 0x1003E570
// Name: public: virtual void CHammer::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::RunFrame(CHammer *this)
{
  CHammer *v1; // edi
  void (__thiscall *HandleDeviceLost)(IMaterialSystem *); // edx
  CHammerVGui *v3; // eax
  CMapDoc *v4; // esi
  CGridNav *m_pGridNav; // ebx
  CMapView3D *First3DView; // eax
  CCamera *m_pCamera; // edi
  Vector vViewPos; // [esp+4h] [ebp-1Ch] BYREF
  Vector vViewDir; // [esp+10h] [ebp-10h] BYREF
  CHammer *v10; // [esp+1Ch] [ebp-4h]

  v1 = this;
  HandleDeviceLost = materials->HandleDeviceLost;
  v10 = this;
  HandleDeviceLost(this: materials);
  if ( BYTE1(v1->m_pMainWnd) == 0 )
    Sleep(dwMilliseconds: 0x32u);
  v3 = HammerVGui();
  CHammerVGui::Simulate(this: v3);
  if ( CMapDoc::m_pMapDoc != nullptr && LOBYTE(v1->m_pMainWnd) == 0 || HIBYTE(v1->m_pMainWnd) != 0 )
    HandleLightingPreview();
  if ( CMapDoc::m_pMapDoc != nullptr
    && LOBYTE(v1->m_pMainWnd) == 0
    && (!IsRunningCommands() && BYTE1(v1->m_pMainWnd) != 0 || HIBYTE(v1->m_pMainWnd) != 0) )
  {
    v4 = CMapDoc::m_pMapDoc;
    if ( CMapDoc::m_pMapDoc->m_bHasInitialUpdate )
    {
      CMapDoc::UpdateCurrentTime(this: CMapDoc::m_pMapDoc);
      CMapDoc::UpdateAnimation(this: v4);
      CMapDoc::RenderAllViews(this: v4, a2: (int)v4);
      m_pGridNav = v4->m_pGridNav;
      if ( m_pGridNav != nullptr && CGridNav::sm_bEnabled && m_pGridNav->m_bPreviewActive )
      {
        First3DView = CMapDoc::GetFirst3DView(this: v4);
        if ( First3DView != nullptr )
        {
          m_pCamera = First3DView->m_pCamera;
          CCamera::GetViewPoint(this: m_pCamera, ViewPoint: &vViewPos);
          CCamera::GetViewForward(this: m_pCamera, ViewForward: &vViewDir);
          CGridNav::Update(this: m_pGridNav, pMapDoc: v4, &vViewPos, &vViewDir);
          v1 = v10;
        }
      }
    }
  }
  if ( BYTE1(v1->m_pMainWnd) != 0 )
    CTextureSystem::LazyLoadTextures(this: &g_Textures);
  HIBYTE(v1->m_pMainWnd) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003E6E0
// Name: public: virtual bool CTier1AppSystem<class IHammer,0>::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTier1AppSystem<IHammer,0>::Connect(
        CTier1AppSystem<IHammer,0> *this,
        void *(__cdecl *factory)(const char *, int *))
{
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003E700
// Name: public: virtual void CTier1AppSystem<class IHammer,0>::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CTier1AppSystem<IHammer,0>::Disconnect(CTier1AppSystem<IHammer,0> *this)
{
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x1003EA50
// Name: public: virtual bool CTier2AppSystem<class IHammer,0>::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTier2AppSystem<IHammer,0>::Connect(
        CTier2AppSystem<IHammer,0> *this,
        void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *v3)(const char *, int *); // [esp+0h] [ebp-4h] BYREF

  v3 = factory;
  ConnectTier1Libraries(pFactoryList: &v3, nFactoryCount: 1);
  ConnectTier2Libraries(pFactoryList: &factory, nFactoryCount: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003EA80
// Name: public: virtual enum InitReturnVal_t CTier2AppSystem<class IHammer,0>::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier2AppSystem<IHammer,0>::Init(CTier2AppSystem<IHammer,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003EAA0
// Name: public: virtual void CTier2AppSystem<class IHammer,0>::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2AppSystem<IHammer,0>::Shutdown(CTier2AppSystem<IHammer,0> *this)
{
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x1003EAB0
// Name: public: virtual void CTier2AppSystem<class IHammer,0>::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier2AppSystem<IHammer,0>::Disconnect(CTier2AppSystem<IHammer,0> *this)
{
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x1003EF80
// Name: public: CUtlBinaryBlock::~CUtlBinaryBlock(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlBinaryBlock::~CUtlBinaryBlock(CUtlBinaryBlock *this)
{
  this->m_nActualLength = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003EFF0
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CUtlString *this)
{
  this->m_Storage.m_nActualLength = 0;
  if ( this->m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Storage.m_Memory.m_pMemory);
      this->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F060
// Name: public: CHammerCmdLine::CHammerCmdLine(void)
// Source: json
//------------------------------------------------------------------------------
CHammerCmdLine *__thiscall CHammerCmdLine::CHammerCmdLine(CHammerCmdLine *this)
{
  ATL::IAtlStringMgr *StringManager; // eax

  CCommandLineInfo::CCommandLineInfo(this);
  this->__vftable = (CHammerCmdLine_vtbl *)&CHammerCmdLine::`vftable';
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strGame.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  *(_WORD *)&this->m_bShowLogo = 1;
  this->m_bConfigDir = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003F0F0
// Name: public: virtual CHammerCmdLine::~CHammerCmdLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammerCmdLine::~CHammerCmdLine(CHammerCmdLine *this)
{
  volatile signed __int32 *v2; // eax

  v2 = (volatile signed __int32 *)(this->m_strGame.m_pszData - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(a1: v2);
  CCommandLineInfo::~CCommandLineInfo(this);
}

//------------------------------------------------------------------------------
// Address: 0x1003F2C0
// Name: public: virtual bool CTier3AppSystem<class IHammer,0>::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTier3AppSystem<IHammer,0>::Connect(
        CTier3AppSystem<IHammer,0> *this,
        void *(__cdecl *factory)(const char *, int *))
{
  vgui::ToolWindow *v2; // ecx
  void *(__cdecl *v4)(const char *, int *); // [esp+0h] [ebp-8h] BYREF
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+4h] [ebp-4h] BYREF

  v4 = factory;
  pFactoryList = factory;
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConnectTier2Libraries(pFactoryList: &v4, nFactoryCount: 1);
  CDmeFXClip::OnDestruction(this: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003F300
// Name: public: virtual void CTier3AppSystem<class IHammer,0>::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTier3AppSystem<IHammer,0>::Disconnect(CTier3AppSystem<IHammer,0> *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x1003FE30
// Name: public: virtual void CHammer::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::Disconnect(CHammer *this)
{
  g_pStudioRender = nullptr;
  g_pFileSystem = nullptr;
  g_pEngineAPI = nullptr;
  g_pMDLCache = nullptr;
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x10040B70
// Name: public: void CHammer::OpenURL(unsigned int,struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CHammer::OpenURL(CHammer *this@<ecx>, int a2@<edi>, unsigned int nID, HWND__ *hwnd)
{
  ATL::IAtlStringMgr *StringManager; // eax
  char *m_pszData; // esi
  HINSTANCE__ *StringResourceHandle; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+0h] [ebp-10h] BYREF
  int v8; // [esp+Ch] [ebp-4h]

  str.m_pszData = (char *)this;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  m_pszData = (char *)(((int (__thiscall *)(ATL::IAtlStringMgr *, int))StringManager->GetNilString)(
                         a1: StringManager,
                         a2)
                     + 16);
  str.m_pszData = m_pszData;
  v8 = 1;
  StringResourceHandle = AfxFindStringResourceHandle(__formal: nID);
  if ( StringResourceHandle != nullptr )
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
      this: &str,
      hInstance: StringResourceHandle,
      nID);
    m_pszData = str.m_pszData;
  }
  if ( (unsigned int)ShellExecuteA(
                       hwnd,
                       lpOperation: "open",
                       lpFile: m_pszData,
                       lpParameters: nullptr,
                       lpDirectory: nullptr,
                       nShowCmd: 0) < 0x20 )
    AfxMessageBox(lpszText: "The website couldn't be opened.", nType: 0, nIDHelp: 0);
  v8 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**((_DWORD **)m_pszData - 4) + 4))(a1: m_pszData - 16);
}

//------------------------------------------------------------------------------
// Address: 0x10041050
// Name: void AppRegisterPostInitFn(void (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __cdecl AppRegisterPostInitFn(void (__cdecl *fn)())
{
  int m_Size; // eax
  int v2; // esi
  void (__cdecl **m_pMemory)(); // ecx
  int v4; // eax
  void (__cdecl **v5)(); // eax

  if ( (_S3 & 1) == 0 )
  {
    _S3 |= 1u;
    storage.m_Memory.m_pMemory = nullptr;
    storage.m_Memory.m_nAllocationCount = 0;
    storage.m_Memory.m_nGrowSize = 0;
    storage.m_Size = 0;
    storage.m_pElements = nullptr;
    atexit(func: ReliableStaticStorage_CUtlVector_void____cdecl___void__CUtlMemory_void____cdecl___void__int____0__::_2_::_dynamic_atexit_destructor_for__storage__);
  }
  m_Size = storage.m_Size;
  v2 = storage.m_Size;
  if ( storage.m_Size + 1 > storage.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&storage,
      num: storage.m_Size - storage.m_Memory.m_nAllocationCount + 1);
    m_Size = storage.m_Size;
  }
  storage.m_Size = m_Size + 1;
  m_pMemory = storage.m_Memory.m_pMemory;
  v4 = m_Size - v2;
  storage.m_pElements = storage.m_Memory.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(dest: &storage.m_Memory.m_pMemory[v2 + 1], src: &storage.m_Memory.m_pMemory[v2], count: 4 * v4);
    m_pMemory = storage.m_Memory.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = fn;
}

//------------------------------------------------------------------------------
// Address: 0x10041140
// Name: void AppRegisterMessageLoopFn(void (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __cdecl AppRegisterMessageLoopFn(void (__cdecl *fn)())
{
  int v1; // eax
  int v2; // esi
  CCullTreeNode **m_pMemory; // ecx
  int v4; // eax
  CCullTreeNode **v5; // eax

  if ( (_S4 & 1) == 0 )
  {
    _S4 |= 1u;
    stru_10791020.m_pMemory = nullptr;
    stru_10791020.m_nAllocationCount = 0;
    stru_10791020.m_nGrowSize = 0;
    dword_1079102C = 0;
    dword_10791030 = 0;
    atexit(func: ReliableStaticStorage_CUtlVector_void____cdecl___void__CUtlMemory_void____cdecl___void__int____2__::_2_::_dynamic_atexit_destructor_for__storage__);
  }
  v1 = dword_1079102C;
  v2 = dword_1079102C;
  if ( dword_1079102C + 1 > stru_10791020.m_nAllocationCount )
  {
    CUtlMemory<CVisGroup *,int>::Grow(this: &stru_10791020, num: dword_1079102C - stru_10791020.m_nAllocationCount + 1);
    v1 = dword_1079102C;
  }
  dword_1079102C = v1 + 1;
  m_pMemory = stru_10791020.m_pMemory;
  v4 = v1 - v2;
  dword_10791030 = (int)stru_10791020.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(dest: &stru_10791020.m_pMemory[v2 + 1], src: &stru_10791020.m_pMemory[v2], count: 4 * v4);
    m_pMemory = stru_10791020.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = (CCullTreeNode *)fn;
}

//------------------------------------------------------------------------------
// Address: 0x10041230
// Name: void AppRegisterPreShutdownFn(void (*)(void))
// Source: json
//------------------------------------------------------------------------------
void __cdecl AppRegisterPreShutdownFn(void (__cdecl *fn)())
{
  int v1; // eax
  int v2; // esi
  CCullTreeNode **m_pMemory; // ecx
  int v4; // eax
  CCullTreeNode **v5; // eax

  if ( (_S6 & 1) == 0 )
  {
    _S6 |= 1u;
    stru_10791050.m_pMemory = nullptr;
    stru_10791050.m_nAllocationCount = 0;
    stru_10791050.m_nGrowSize = 0;
    dword_1079105C = 0;
    dword_10791060 = 0;
    atexit(func: ReliableStaticStorage_CUtlVector_void____cdecl___void__CUtlMemory_void____cdecl___void__int____1__::_2_::_dynamic_atexit_destructor_for__storage__);
  }
  v1 = dword_1079105C;
  v2 = dword_1079105C;
  if ( dword_1079105C + 1 > stru_10791050.m_nAllocationCount )
  {
    CUtlMemory<CVisGroup *,int>::Grow(this: &stru_10791050, num: dword_1079105C - stru_10791050.m_nAllocationCount + 1);
    v1 = dword_1079105C;
  }
  dword_1079105C = v1 + 1;
  m_pMemory = stru_10791050.m_pMemory;
  v4 = v1 - v2;
  dword_10791060 = (int)stru_10791050.m_pMemory;
  if ( v4 > 0 )
  {
    _V_memmove(dest: &stru_10791050.m_pMemory[v2 + 1], src: &stru_10791050.m_pMemory[v2], count: 4 * v4);
    m_pMemory = stru_10791050.m_pMemory;
  }
  v5 = &m_pMemory[v2];
  if ( v5 != nullptr )
    *v5 = (CCullTreeNode *)fn;
}

//------------------------------------------------------------------------------
// Address: 0x10041320
// Name: protected: int CHammer::InternalMainLoop(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHammer::InternalMainLoop(CHammer *this)
{
  void (__thiscall *EnableMessagePump)(IInputSystem *, bool); // edx
  CTier3AppSystem<IHammer,0> *v3; // edi
  int j; // edi
  int k; // edi
  tagMSG msg; // [esp+Ch] [ebp-34h] BYREF
  CTier3AppSystem<IHammer,0> *i; // [esp+28h] [ebp-18h]
  int lIdleCount; // [esp+2Ch] [ebp-14h]
  bool bIdle; // [esp+33h] [ebp-Dh]
  int v12; // [esp+3Ch] [ebp-4h]

  g_pDataCache->SetSize(this: g_pDataCache, a2: 0x8000000);
  EnableMessagePump = g_pInputSystem->EnableMessagePump;
  bIdle = true;
  lIdleCount = 0;
  EnableMessagePump(this: g_pInputSystem, a2: false);
  v3 = &this->CTier3AppSystem<IHammer,0>;
  for ( i = v3; ; v3 = i )
  {
LABEL_3:
    v3->RunFrame(this: v3);
    if ( bIdle && !v3->HammerOnIdle(this: v3, a2: lIdleCount++) )
      bIdle = false;
    for ( j = 0; ; ++j )
    {
      if ( (_S4 & 1) == 0 )
      {
        _S4 |= 1u;
        v12 = 0;
        stru_10791020.m_pMemory = nullptr;
        stru_10791020.m_nAllocationCount = 0;
        stru_10791020.m_nGrowSize = 0;
        dword_1079102C = 0;
        dword_10791030 = 0;
        atexit(func: ReliableStaticStorage_CUtlVector_void____cdecl___void__CUtlMemory_void____cdecl___void__int____2__::_2_::_dynamic_atexit_destructor_for__storage__);
        v12 = -1;
      }
      if ( j >= dword_1079102C )
        break;
      if ( (_S4 & 1) == 0 )
      {
        _S4 |= 1u;
        v12 = 2;
        stru_10791020.m_pMemory = nullptr;
        stru_10791020.m_nAllocationCount = 0;
        stru_10791020.m_nGrowSize = 0;
        dword_1079102C = 0;
        dword_10791030 = 0;
        atexit(func: ReliableStaticStorage_CUtlVector_void____cdecl___void__CUtlMemory_void____cdecl___void__int____2__::_2_::_dynamic_atexit_destructor_for__storage__);
        v12 = -1;
      }
      ((void (*)(void))stru_10791020.m_pMemory[j])();
    }
    if ( PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
      break;
  }
  while ( msg.message != 18 )
  {
    for ( k = 0; ; ++k )
    {
      if ( (_S5 & 1) == 0 )
      {
        _S5 |= 1u;
        v12 = 4;
        dword_10791038 = nullptr;
        dword_1079103C = 0;
        dword_10791040 = 0;
        dword_10791044 = 0;
        dword_10791048 = 0;
        atexit(func: ReliableStaticStorage_CUtlVector_void____cdecl___tagMSG____CUtlMemory_void____cdecl___tagMSG____int____3__::_2_::_dynamic_atexit_destructor_for__storage__);
        v12 = -1;
      }
      if ( k >= dword_10791044 )
        break;
      if ( (_S5 & 1) == 0 )
      {
        _S5 |= 1u;
        v12 = 6;
        dword_10791038 = nullptr;
        dword_1079103C = 0;
        dword_10791040 = 0;
        dword_10791044 = 0;
        dword_10791048 = 0;
        atexit(func: ReliableStaticStorage_CUtlVector_void____cdecl___tagMSG____CUtlMemory_void____cdecl___tagMSG____int____3__::_2_::_dynamic_atexit_destructor_for__storage__);
        v12 = -1;
      }
      (*((void (__cdecl **)(tagMSG *))dword_10791038 + k))(a1: &msg);
    }
    v3 = i;
    if ( !i->HammerPreTranslateMessage(this: i, a2: &msg) )
    {
      TranslateMessage(lpMsg: &msg);
      DispatchMessageA(lpMsg: &msg);
    }
    if ( v3->HammerIsIdleMessage(this: v3, a2: &msg) )
    {
      bIdle = true;
      lIdleCount = 0;
    }
    if ( !PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
      goto LABEL_3;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100415C0
// Name: public: virtual void CHammer::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::Shutdown(CHammer *this)
{
  CHammer *v1; // esi
  int i; // edi
  CHammerVGui *v3; // eax
  int m_xInnerUnknown; // edx
  int v5; // edi
  IUnknown *m_pOuterUnknown; // eax
  IUnknown_vtbl *v7; // esi
  unsigned int (__stdcall *AddRef)(IUnknown *); // eax
  MessageToLPreview StopMsg; // [esp+Ch] [ebp-44h] BYREF
  IUnknown_vtbl *v10; // [esp+38h] [ebp-18h]
  int nSequenceCount; // [esp+3Ch] [ebp-14h]
  CHammer *v12; // [esp+40h] [ebp-10h]
  int v13; // [esp+4Ch] [ebp-4h]

  v1 = this;
  v12 = this;
  if ( g_LPreviewThread != nullptr )
  {
    StopMsg.m_LightList.m_pHead = nullptr;
    StopMsg.m_MsgType = LPREVIEW_MSG_EXIT;
    CMessageQueue<MessageToLPreview>::QueueMessage(this: &g_HammerToLPreviewMsgQueue, Msg: &StopMsg);
    _ThreadJoin(a1: g_LPreviewThread, a2: -1);
    g_LPreviewThread = nullptr;
  }
  if ( (_S6 & 1) == 0 )
  {
    _S6 |= 1u;
    v13 = 0;
    stru_10791050.m_pMemory = nullptr;
    stru_10791050.m_nAllocationCount = 0;
    stru_10791050.m_nGrowSize = 0;
    dword_1079105C = 0;
    dword_10791060 = 0;
    atexit(func: ReliableStaticStorage_CUtlVector_void____cdecl___void__CUtlMemory_void____cdecl___void__int____1__::_2_::_dynamic_atexit_destructor_for__storage__);
    v13 = -1;
  }
  for ( i = dword_1079105C; i > 0; ((void (*)(void))stru_10791050.m_pMemory[i])() )
  {
    --i;
    if ( (_S6 & 1) == 0 )
    {
      _S6 |= 1u;
      v13 = 2;
      stru_10791050.m_pMemory = nullptr;
      stru_10791050.m_nAllocationCount = 0;
      stru_10791050.m_nGrowSize = 0;
      dword_1079105C = 0;
      dword_10791060 = 0;
      atexit(func: ReliableStaticStorage_CUtlVector_void____cdecl___void__CUtlMemory_void____cdecl___void__int____1__::_2_::_dynamic_atexit_destructor_for__storage__);
      v13 = -1;
    }
  }
  v3 = HammerVGui();
  CHammerVGui::Shutdown(this: v3);
  UnloadFileSystemDialogModule();
  m_xInnerUnknown = v1->m_xInnerUnknown;
  v5 = 0;
  nSequenceCount = m_xInnerUnknown;
  if ( m_xInnerUnknown > 0 )
  {
    while ( v5 >= 0 && v5 < (signed int)v1->m_xInnerUnknown )
    {
      m_pOuterUnknown = v1->m_pOuterUnknown;
      v7 = m_pOuterUnknown[v5].__vftable;
      if ( v7 != nullptr )
      {
        v10 = m_pOuterUnknown[v5].__vftable;
        v13 = -1;
        AddRef = v7->AddRef;
        v7->QueryInterface = (HRESULT (__stdcall *)(IUnknown *, const _GUID *, void **))&CArray<CCOMMAND,CCOMMAND &>::`vftable';
        if ( AddRef != nullptr )
          operator delete(p: AddRef);
        operator delete(p: v7);
        if ( v5 >= (signed int)v12->m_xInnerUnknown )
          break;
        v12->m_pOuterUnknown[v5].__vftable = nullptr;
        m_xInnerUnknown = nSequenceCount;
      }
      if ( ++v5 >= m_xInnerUnknown )
        goto LABEL_10;
      v1 = v12;
    }
    AfxThrowInvalidArgException();
  }
LABEL_10:
  CTextureSystem::ShutDown(this: &g_Textures);
  CSoundSystem::ShutDown(this: &g_Sounds);
  materials->ModShutdown(this: materials);
  if ( g_pCVar != nullptr )
    ConVar_Unregister();
}

//------------------------------------------------------------------------------
// Address: 0x10041860
// Name: public: virtual void CHammerCmdLine::ParseParam(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammerCmdLine::ParseParam(CHammerCmdLine *this, const char *lpszParam, int bFlag, int bLast)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_strGame; // ecx

  if ( this->m_bGame )
    goto LABEL_6;
  if ( bFlag != 0 && _V_stricmp(s1: lpszParam, s2: "game") == 0 )
  {
    this->m_bGame = true;
    return;
  }
  if ( this->m_bGame )
  {
LABEL_6:
    if ( bFlag == 0 )
    {
      p_m_strGame = &this->m_strGame;
      if ( lpszParam == nullptr )
      {
        ATL::CSimpleStringT<char,0>::SetString(this: p_m_strGame, pszSrc: nullptr, nLength: 0);
        this->m_bGame = false;
        return;
      }
      ATL::CSimpleStringT<char,0>::SetString(this: p_m_strGame, pszSrc: lpszParam, nLength: strlen(lpszParam));
    }
    this->m_bGame = false;
  }
  else
  {
    if ( bFlag != 0 )
    {
      if ( _V_stricmp(s1: lpszParam, s2: "nologo") == 0 )
      {
        this->m_bShowLogo = false;
        return;
      }
      if ( _V_stricmp(s1: lpszParam, s2: "makelib") == 0 )
      {
        bMakeLib = true;
        return;
      }
    }
    else if ( bMakeLib )
    {
      MakePrefabLibrary(pszName: lpszParam);
      return;
    }
    if ( this->m_bConfigDir )
      goto LABEL_23;
    if ( bFlag != 0 && _V_stricmp(s1: lpszParam, s2: "configdir") == 0 )
    {
      this->m_bConfigDir = true;
      return;
    }
    if ( this->m_bConfigDir )
    {
LABEL_23:
      if ( bFlag == 0 )
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::operator=(
          this: &Options.configs.m_strConfigDir,
          pszSrc: lpszParam);
      this->m_bConfigDir = false;
    }
    else
    {
      CCommandLineInfo::ParseParam(this, pszParam: lpszParam, bFlag, bLast);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041990
// Name: public: virtual bool CHammer::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHammer::Connect(CHammer *this, void *(__cdecl *factory)(const char *, int *))
{
  void *(__cdecl *v2)(const char *, int *); // esi
  vgui::ToolWindow *v4; // ecx
  _BYTE *v5; // eax
  char *v6; // esi
  char v7; // al
  CWnd **p_m_pActiveWnd; // eax
  char *v9; // edx
  char v10; // cl
  char szGameConfigDir[260]; // [esp+8h] [ebp-260h] BYREF
  ThreadPoolStartParams_t startParams; // [esp+10Ch] [ebp-15Ch] BYREF
  CHammerCmdLine cmdInfo; // [esp+220h] [ebp-48h] BYREF
  void *(__cdecl *v15)(const char *, int *); // [esp+254h] [ebp-14h] BYREF
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+258h] [ebp-10h] BYREF
  int v17; // [esp+264h] [ebp-4h]

  v2 = factory;
  v15 = factory;
  pFactoryList = factory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  CDmeFXClip::OnDestruction(this: v4);
  g_pFileSystem = (IBaseFileSystem *)((int (__cdecl *)(const char *, _DWORD, void *(__cdecl **)(const char *, int *), int))v2)(
                                       a1: "VBaseFileSystem011",
                                       a2: 0,
                                       a3: &v15,
                                       a4: 1);
  g_pStudioRender = (IStudioRender *)v2(a1: "VStudioRender026", a2: nullptr);
  g_pEngineAPI = (IEngineAPI *)v2(a1: "VENGINE_LAUNCHER_API_VERSION004", a2: nullptr);
  g_pMDLCache = (IMDLCache *)v2(a1: "MDLCache004", a2: nullptr);
  p4 = (IP4 *)v2(a1: "VP4002", a2: nullptr);
  g_Factory = v2;
  if ( g_pMDLCache == nullptr
    || g_pFileSystem == nullptr
    || g_pFullFileSystem == nullptr
    || materials == nullptr
    || g_pMaterialSystemHardwareConfig == nullptr
    || g_pStudioRender == nullptr )
  {
    return 0;
  }
  WinTab_Init();
  GetModuleFileNameA(hModule: nullptr, lpFilename: (LPSTR)&this->m_pActiveWnd, nSize: 0x104u);
  strrchr(string: (unsigned __int8 *)&this->m_pActiveWnd, chr: 0x5Cu);
  if ( v5 != nullptr )
    *v5 = 0;
  if ( g_pEngineAPI != nullptr )
  {
    v6 = (char *)&this->m_pMainWnd + 3;
    do
      v7 = *++v6;
    while ( v7 != 0 );
    strcpy(v6, "\\bin");
  }
  g_pwndMessage = CMessageWnd::CreateMessageWndObject();
  p_m_pActiveWnd = &AfxGetModuleState()->m_pCurrentWinApp[1].m_pActiveWnd;
  v9 = (char *)(szGameConfigDir - (char *)p_m_pActiveWnd);
  do
  {
    v10 = *(_BYTE *)p_m_pActiveWnd;
    *((_BYTE *)p_m_pActiveWnd + (_DWORD)v9) = *(_BYTE *)p_m_pActiveWnd;
    p_m_pActiveWnd = (CWnd **)((char *)p_m_pActiveWnd + 1);
  }
  while ( v10 != 0 );
  EnsureTrailingBackslash(psz: szGameConfigDir);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::operator=(
    this: &Options.configs.m_strConfigDir,
    pszSrc: szGameConfigDir);
  CHammerCmdLine::CHammerCmdLine(this: &cmdInfo);
  v17 = 0;
  CWinApp::ParseCommandLine(this: (CHammer *)((char *)this - 184), rCmdInfo: &cmdInfo);
  _SteamAPI_InitSafe();
  CSteamAPIContext::Init(this: &g_SteamAPIContext);
  CWinApp::SetRegistryKey(this: (CHammer *)((char *)this - 184), lpszRegistryKey: "Valve");
  COptions::Init(this: &Options);
  if ( _g_pThreadPool != nullptr )
  {
    startParams.nThreads = -1;
    startParams.nStackSize = -1;
    startParams.iThreadPriority = -32768;
    *((_BYTE *)&startParams + 272) &= 0xFCu;
    if ( (*((_BYTE *)&startParams + 272) & 2) != 0 )
      qmemcpy(startParams.iAffinityTable, nullptr, sizeof(startParams.iAffinityTable));
    startParams.fDistribute = TRS_TRUE;
    _g_pThreadPool->Start_2(this: _g_pThreadPool, a2: &startParams);
  }
  v17 = -1;
  CHammerCmdLine::~CHammerCmdLine(this: &cmdInfo);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10041BF0
// Name: public: unsigned long CHammer::GetProfileColor(char const __near *,char const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHammer::GetProfileColor(CHammer *this, const char *pszSection, const char *pszKey, int r, int g, int b)
{
  ATL::IAtlStringMgr *StringManager; // eax
  ATL::IAtlStringMgr *v8; // eax
  ATL::CStringData *v9; // eax
  int v10; // eax
  char *m_pszData; // edi
  char *v12; // eax
  char *v13; // eax
  char *v15; // esi
  const char *v16; // esi
  int v17; // eax
  bool v18; // zf
  const char *v19; // eax
  const char *v20; // esi
  unsigned __int8 v21; // bl
  const char *i; // eax
  unsigned __int8 v23; // al
  int v24; // esi
  char *v25; // eax
  char szBuff[128]; // [esp+Ch] [ebp-94h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strReturn; // [esp+8Ch] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strDefault; // [esp+90h] [ebp-10h] BYREF
  int v29; // [esp+9Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  strDefault.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v29 = 1;
  v8 = AfxGetStringManager();
  if ( v8 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  strReturn.m_pszData = (char *)&v8->GetNilString(this: v8)[1];
  LOBYTE(v29) = 3;
  sprintf(string: szBuff, format: "%i %i %i", r, g, b);
  ATL::CSimpleStringT<char,0>::SetString(this: &strDefault, pszSrc: szBuff, nLength: strlen(szBuff));
  v9 = (ATL::CStringData *)this->GetProfileStringA(
                             this,
                             result: &b,
                             a3: pszSection,
                             a4: pszKey,
                             a5: strDefault.m_pszData);
  LOBYTE(v29) = 4;
  ATL::CSimpleStringT<char,0>::operator=(this: &strReturn, strSrc: v9);
  LOBYTE(v29) = 3;
  v10 = b - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)(b - 16 + 12)) <= 0 )
    (*(void (__stdcall **)(int))(**(_DWORD **)v10 + 4))(a1: v10);
  m_pszData = strReturn.m_pszData;
  if ( *((_DWORD *)strReturn.m_pszData - 3) != 0 )
  {
    v15 = strcpy(szBuff, strReturn.m_pszData);
    if ( szBuff[0] != 0 )
    {
      do
      {
        if ( *v15 == 32 )
          break;
        ++v15;
      }
      while ( *v15 != 0 );
    }
    *v15 = 0;
    v16 = v15 + 1;
    v17 = atoi(nptr: szBuff);
    v18 = *v16 == 0;
    b = v17;
    v19 = v16;
    if ( !v18 )
    {
      do
      {
        if ( *v16 == 32 )
          break;
        ++v16;
      }
      while ( *v16 != 0 );
    }
    *v16 = 0;
    v20 = v16 + 1;
    v21 = atoi(nptr: v19);
    for ( i = v20; *v20 != 0; ++v20 )
      ;
    *v20 = 0;
    v23 = atoi(nptr: i);
    v24 = (unsigned __int8)b | ((v21 | (v23 << 8)) << 8);
    LOBYTE(v29) = 1;
    if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
      (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
        a1: *((_DWORD *)m_pszData - 4),
        a2: m_pszData - 16);
    v29 = -1;
    v25 = strDefault.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)strDefault.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v25 + 4))(a1: v25);
    return v24;
  }
  else
  {
    LOBYTE(v29) = 1;
    v12 = strReturn.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)strReturn.m_pszData - 1) <= 0 )
      (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)v12 + 4))(a1: *(_DWORD *)v12, a2: m_pszData - 16);
    v29 = -1;
    v13 = strDefault.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)strDefault.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v13 + 4))(a1: v13);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10041E60
// Name: protected: static int CHammer::StaticInternalMainLoop(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CHammer::StaticInternalMainLoop(CHammer *pParam)
{
  return CHammer::InternalMainLoop(this: pParam);
}

//------------------------------------------------------------------------------
// Address: 0x10041E70
// Name: public: std::basic_ofstream<char,struct std::char_traits<char>>::basic_ofstream<char,struct std::char_traits<char>>(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
std::ofstream *__thiscall std::ofstream::ofstream(
        std::ofstream *this,
        const char *_Filename,
        int _Mode,
        int _Prot,
        int a5)
{
  std::ios *v6; // esi
  char v7; // al
  bool v8; // zf
  int v9; // ecx
  int v10; // eax
  std::ios_base *v11; // ecx
  char v12; // al

  if ( a5 != 0 )
  {
    *(_DWORD *)this->gap0 = &std::fstream::`vbtable'{for `std::ostream'};
    *(_DWORD *)&this->gap5C[4] = &std::ios_base::`vftable';
    *(_DWORD *)&this->gap5C[4] = &std::ios::`vftable';
  }
  *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)] = &std::ostream::`vftable';
  v6 = (std::ios *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)];
  std::ios_base::_Init(this: v6);
  v6->_Mystrbuf = (std::streambuf *)&this->gap0[4];
  v6->_Tiestr = nullptr;
  v7 = std::ios::widen(this: v6, _Byte: 32);
  v8 = v6->_Mystrbuf == nullptr;
  v6->_Fillch = v7;
  if ( v8 )
    std::ios_base::clear(this: v6, _State: LOBYTE(v6->_Mystate) | 4, _Reraise: false);
  *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)] = &std::ofstream::`vftable';
  std::streambuf::streambuf(this: (std::streambuf *)&this->gap0[4]);
  *(_DWORD *)&this->gap0[20] = &this->gap0[12];
  *(_DWORD *)&this->gap0[36] = &this->gap0[28];
  *(_DWORD *)&this->gap0[4] = &std::filebuf::`vftable';
  this->_Filebuffer[4] = 0;
  this->gap0[77] = 0;
  *(_DWORD *)&this->gap0[40] = &this->gap0[32];
  *(_DWORD *)&this->gap0[52] = &this->gap0[44];
  *(_DWORD *)&this->gap0[24] = &this->gap0[16];
  *(_DWORD *)&this->gap0[56] = &this->gap0[48];
  *(_DWORD *)&this->gap0[16] = 0;
  **(_DWORD **)&this->gap0[40] = 0;
  **(_DWORD **)&this->gap0[56] = 0;
  **(_DWORD **)&this->gap0[20] = 0;
  **(_DWORD **)&this->gap0[36] = 0;
  **(_DWORD **)&this->gap0[52] = 0;
  *(_DWORD *)&this->_Filebuffer[8] = 0;
  *(_DWORD *)this->_Filebuffer = `std::filebuf::_Init'::`2'::_Stinit;
  *(_DWORD *)&this->gap0[72] = 0;
  if ( std::filebuf::open(this: (std::filebuf *)&this->gap0[4], _Filename, _Mode: _Mode | 2, _Prot) == nullptr )
  {
    v9 = *(_DWORD *)(*(_DWORD *)this->gap0 + 4);
    v10 = *(_DWORD *)&this->gap0[v9 + 12];
    v11 = (std::ios_base *)&this->gap0[v9];
    v12 = v10 | 2;
    if ( v11[1].__vftable == nullptr )
      v12 |= 4u;
    std::ios_base::clear(this: v11, _State: v12, _Reraise: false);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10041FF0
// Name: public: virtual std::basic_ofstream<char,struct std::char_traits<char>>::~basic_ofstream<char,struct std::char_traits<char>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::ofstream::~ofstream<char,std::char_traits<char>>(std::ofstream *this)
{
  char *v2; // esi
  char **v3; // ecx
  int v4; // eax

  *(_DWORD *)((char *)this + *(_DWORD *)(*((_DWORD *)this - 24) + 4) - 96) = &std::ofstream::`vftable';
  v2 = (char *)this - 92;
  *((_DWORD *)this - 23) = &std::filebuf::`vftable';
  if ( *(_DWORD *)&this->_Filebuffer[-88] != 0 )
  {
    v3 = *((char ***)v2 + 4);
    if ( *v3 == v2 + 72 )
    {
      v4 = *((_DWORD *)v2 + 16);
      *v3 = *((char **)v2 + 15);
      **((_DWORD **)v2 + 8) = v4;
      **((_DWORD **)v2 + 12) = 0;
    }
  }
  if ( v2[80] != 0 )
    std::filebuf::close(this: (std::filebuf *)((char *)this - 92));
  std::streambuf::~streambuf<char,std::char_traits<char>>(this: (std::streambuf *)((char *)this - 92));
  *(_DWORD *)((char *)this + *(_DWORD *)(*((_DWORD *)this - 24) + 4) - 96) = &std::ostream::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100420A0
// Name: public: virtual int CHammer::MainLoop(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHammer::MainLoop(CHammer *this)
{
  return WrapFunctionWithMinidumpHandler(
           pfn: (int (__cdecl *)(void *))CHammer::StaticInternalMainLoop,
           pParam: (char *)this - 184);
}

//------------------------------------------------------------------------------
// Address: 0x100420C0
// Name: public: void CHammer::OnFileOpen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::OnFileOpen(CHammer *this)
{
  char *szMapDir; // eax
  int v3; // edx
  char v4; // cl
  CWinThread *Thread; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v9; // eax
  char *m_pszData; // ecx
  char *v11; // edx
  char v12; // al
  char *v13; // eax
  int v14; // eax
  char *v15; // eax
  char szFileNameBuffer[260]; // [esp+8h] [ebp-170h] BYREF
  tagOFNA ofn; // [esp+10Ch] [ebp-6Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+164h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+168h] [ebp-10h] BYREF
  int v20; // [esp+174h] [ebp-4h]

  if ( szInitialDir_3[0] == 0 )
  {
    szMapDir = g_pGameConfig->szMapDir;
    v3 = szInitialDir_3 - g_pGameConfig->szMapDir;
    do
    {
      v4 = *szMapDir;
      szMapDir[v3] = *szMapDir;
      ++szMapDir;
    }
    while ( v4 != 0 );
  }
  memset(dst: (unsigned __int8 *)&ofn, value: 0, count: sizeof(ofn));
  ofn.lStructSize = 88;
  Thread = AfxGetThread();
  if ( Thread != nullptr && (v6 = (int)Thread->GetMainWnd(this: Thread)) != 0 )
    ofn.hwndOwner = *(HWND__ **)(v6 + 32);
  else
    ofn.hwndOwner = nullptr;
  ofn.lpstrFile = szFileNameBuffer;
  szFileNameBuffer[0] = 0;
  ofn.nMaxFile = 260;
  ofn.lpstrFilter = "Valve Map Files (*.vmf;*.vmm)";
  ofn.nFilterIndex = 1;
  ofn.lpstrFileTitle = nullptr;
  ofn.nMaxFileTitle = 0;
  ofn.lpstrInitialDir = szInitialDir_3;
  ofn.Flags = 2097164;
  if ( GetOpenFileNameA(a1: &ofn) )
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &str,
      pszSrc: ofn.lpstrFile);
    v20 = 0;
    _mbsrchr(str: (unsigned __int8 *)str.m_pszData, c: 0x5Cu);
    if ( v7 != 0 )
    {
      v8 = v7 - (unsigned int)str.m_pszData;
      if ( v8 != -1 )
      {
        v9 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(this: &str, &result, nCount: v8);
        LOBYTE(v20) = 1;
        m_pszData = v9->m_pszData;
        v11 = szInitialDir_3;
        do
        {
          v12 = *m_pszData;
          *v11++ = *m_pszData++;
        }
        while ( v12 != 0 );
        LOBYTE(v20) = 0;
        v13 = result.m_pszData - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)result.m_pszData - 1) <= 0 )
          (*(void (__stdcall **)(char *))(**(_DWORD **)v13 + 4))(a1: v13);
      }
    }
    if ( *((int *)str.m_pszData - 3) <= 0
      || (_mbschr(string: str.m_pszData, c: 0x2Eu), v14 == 0)
      || v14 - (unsigned int)str.m_pszData == -1 )
    {
      switch ( ofn.nFilterIndex )
      {
        case 1u:
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::operator+=(this: &str, pszSrc: ".vmf");
          break;
        case 2u:
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::operator+=(this: &str, pszSrc: ".vmf_autosave");
          break;
        case 3u:
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::operator+=(this: &str, pszSrc: ".rmf");
          break;
        case 4u:
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::operator+=(this: &str, pszSrc: ".map");
          break;
        default:
          break;
      }
    }
    this->OpenDocumentFile(this, a2: str.m_pszData);
    v20 = -1;
    v15 = str.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v15 + 4))(a1: v15);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100422B0
// Name: public: virtual class CDocument __near * CHammer::OpenDocumentOrInstanceFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMapDoc *__userpurge CHammer::OpenDocumentOrInstanceFile@<eax>(
        CHammer *this@<ecx>,
        int a2@<edi>,
        const char *lpszFileName)
{
  ATL::IAtlStringMgr *StringManager; // eax
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v5; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v6; // eax
  char *v7; // eax
  char *v8; // eax
  char *m_pszData; // esi
  const char *v10; // eax
  CMapDoc *v12; // edi
  CMapDoc *v13; // eax
  CMapDoc *v14; // esi
  CMainFrame *MainWnd; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v16; // eax
  char *v17; // esi
  const char *v18; // eax
  const char *v19; // eax
  bool v20; // [esp-Ch] [ebp-340h]
  char szMessage[776]; // [esp+4h] [ebp-330h] BYREF
  CUtlString dialogText; // [esp+30Ch] [ebp-28h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v23; // [esp+31Ch] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > Message; // [esp+320h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > newMapPath; // [esp+324h] [ebp-10h] BYREF
  int v26; // [esp+330h] [ebp-4h]

  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszFileName,
    pszSrc: lpszFileName);
  v26 = 0;
  if ( GetFileAttributesA(lpFileName: lpszFileName) == -1 )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    Message.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    LOBYTE(v26) = 2;
    v5 = ATL::operator+(
           result: &newMapPath,
           psz1: "The file ",
           str2: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszFileName);
    LOBYTE(v26) = 3;
    v6 = ATL::operator+(a1: a2, a2: (int)this, result: &v23, str1: v5, psz2: " does not exist.");
    LOBYTE(v26) = 4;
    ATL::CSimpleStringT<char,0>::operator=(this: &Message, strSrc: (ATL::CStringData *)v6);
    LOBYTE(v26) = 3;
    v7 = v23.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)v23.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v7 + 4))(a1: v7);
    LOBYTE(v26) = 2;
    v8 = newMapPath.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)newMapPath.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v8 + 4))(a1: v8);
    m_pszData = Message.m_pszData;
    AfxMessageBox(lpszText: Message.m_pszData, nType: 0, nIDHelp: 0);
    LOBYTE(v26) = 0;
    if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
      (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
        a1: *((_DWORD *)m_pszData - 4),
        a2: m_pszData - 16);
    v26 = -1;
    v10 = lpszFileName - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)lpszFileName - 1) <= 0 )
      (*(void (__stdcall **)(const char *))(**(_DWORD **)v10 + 4))(a1: v10);
    return nullptr;
  }
  else
  {
    CheckForFileSync(pszFileName: lpszFileName, bClearRepeat: CHammer::m_bIsNewDocumentVisible);
    v12 = (CMapDoc *)this->m_pDocManager->OpenDocumentFile_2(this: this->m_pDocManager, a2: lpszFileName);
    v13 = (CMapDoc *)__RTDynamicCast(
                       inptr: v12,
                       VfDelta: 0,
                       SrcType: &CDocument `RTTI Type Descriptor',
                       TargetType: &CMapDoc `RTTI Type Descriptor',
                       isReference: 0);
    v14 = v13;
    if ( v13 != nullptr )
    {
      CMapDoc::SetActiveMapDoc(pDoc: v13);
      CMapDoc::CheckFileStatus(this: v14);
    }
    if ( v12 != nullptr && Options.general.bLoadwinpos != 0 && Options.general.bIndependentwin != 0 )
    {
      MainWnd = GetMainWnd();
      CMainFrame::LoadWindowStates(this: MainWnd, pFile: nullptr);
    }
    if ( v14 == nullptr || CHammer::m_bIsNewDocumentVisible )
      CMapDoc::ShowWindow(this: v14, bIsVisible: true);
    else
      CMapDoc::ShowWindow(this: v14, bIsVisible: false);
    if ( v12 != nullptr && vgui::TreeView::GetSelectedItemCount(this: (vgui::TreeView *)v12) != 0 )
    {
      v16 = CMapDoc::AutosavedFrom(this: v12);
      v17 = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)v16->m_pszData - 1)[1];
      newMapPath.m_pszData = v17;
      LOBYTE(v26) = 10;
      sprintf(
        string: szMessage,
        format: "This map was loaded from an autosave file.\n"
        "Would you like to rename it from \"%s\" to \"%s\"?\n"
        "NOTE: This will not save the file with the new name; it will only rename it.",
        lpszFileName,
        v17);
      if ( AfxMessageBox(lpszText: szMessage, nType: 0x14u, nIDHelp: 0) == 6 )
        v12->SetPathName(this: v12, a2: v17, a3: 1);
      LOBYTE(v26) = 0;
      if ( _InterlockedDecrement((volatile signed __int32 *)v17 - 1) <= 0 )
        (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)v17 - 4) + 4))(a1: *((_DWORD *)v17 - 4), a2: v17 - 16);
    }
    else if ( CHammer::m_bIsNewDocumentVisible )
    {
      CMapDoc::CheckFileStatus(this: v14);
      if ( v14->m_bReadOnly && !v14->m_bCheckedOut )
      {
        if ( v14->m_bIsVersionControlled )
        {
          CUtlString::CUtlString(this: &dialogText);
          LOBYTE(v26) = 12;
          CUtlString::Format(
            this: &dialogText,
            pFormat: "This map is not checked out.  Would you like to check it out?\n\n%s",
            lpszFileName);
          v20 = !CMapDoc::BspOkToCheckOut(this: v14);
          v18 = CUtlString::operator char const *(this: &dialogText);
          CDialogWithCheckbox::CDialogWithCheckbox(
            this: (CDialogWithCheckbox *)&szMessage[260],
            pszTitleText: "Checkout File",
            pszDialogText: v18,
            pszCheckboxText: "Check out BSP.",
            bCheckState: false,
            bDisabled: v20,
            pParent: nullptr);
          LOBYTE(v26) = 13;
          if ( CDialog::DoModal(this: (CDialog *)&szMessage[260]) == 1 )
          {
            CMapDoc::CheckOut(this: v14);
            if ( v14->m_bReadOnly )
              AfxMessageBox(lpszText: "Checkout was NOT successful!", nType: 0, nIDHelp: 0);
          }
          if ( CDialogWithCheckbox::IsCheckboxChecked(this: (CDialogWithCheckbox *)&szMessage[260]) )
            CMapDoc::CheckOutBsp(this: v14);
          LOBYTE(v26) = 12;
          CDialogWithCheckbox::~CDialogWithCheckbox(this: (CDialogWithCheckbox *)&szMessage[260]);
          LOBYTE(v26) = 0;
          CUtlString::~CUtlString(this: &dialogText);
        }
        else
        {
          sprintf(
            string: szMessage,
            format: "This map is marked as READ ONLY.  You will not be able to save this file.\n\n%s",
            lpszFileName);
          AfxMessageBox(lpszText: szMessage, nType: 0, nIDHelp: 0);
        }
      }
    }
    v26 = -1;
    v19 = lpszFileName - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)lpszFileName - 1) <= 0 )
      (*(void (__stdcall **)(const char *))(**(_DWORD **)v19 + 4))(a1: v19);
    return v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100426E0
// Name: public: int CHammer::GetNextAutosaveNumber(class CUtlMap<struct _FILETIME,struct _WIN32_FIND_DATAA,int> __near *,unsigned long __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __userpurge CHammer::GetNextAutosaveNumber@<eax>(
        CHammer *this@<ecx>,
        int a2@<edi>,
        CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int> *pFileMap,
        unsigned int *pdwTotalDirSize,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *pstrMapTitle)
{
  unsigned int v5; // ebx
  AFX_HELP_TYPE *p_m_eHelpType; // eax
  char *v7; // edx
  char v8; // cl
  int v9; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v10; // eax
  HANDLE FirstFileA; // edi
  char *v12; // eax
  char *m_pszData; // eax
  int v14; // esi
  char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax
  char szRootDir[260]; // [esp+8h] [ebp-3D4h] BYREF
  CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t insert; // [esp+10Ch] [ebp-2D0h] BYREF
  _WIN32_FIND_DATAA fileData; // [esp+254h] [ebp-188h] BYREF
  int nMaxAutosavesPerMap; // [esp+394h] [ebp-48h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v24; // [esp+398h] [ebp-44h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strAutosaveDirectory; // [esp+39Ch] [ebp-40h] BYREF
  int nLastHole; // [esp+3A0h] [ebp-3Ch]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strMapName; // [esp+3A4h] [ebp-38h] BYREF
  void *hFile; // [esp+3A8h] [ebp-34h]
  int nOldestAutosaveNumber; // [esp+3ACh] [ebp-30h]
  _FILETIME fileAccessTime; // [esp+3B0h] [ebp-2Ch] BYREF
  _FILETIME oldestAutosaveTime; // [esp+3B8h] [ebp-24h] BYREF
  int nNumberActualAutosaves; // [esp+3C0h] [ebp-1Ch]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strCurrentNumber; // [esp+3C4h] [ebp-18h] BYREF
  int nExpectedNextAutosaveNumber; // [esp+3C8h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > currentFilename; // [esp+3CCh] [ebp-10h] BYREF
  int v36; // [esp+3D8h] [ebp-4h]

  v5 = 0;
  oldestAutosaveTime.dwHighDateTime = 0;
  oldestAutosaveTime.dwLowDateTime = 0;
  p_m_eHelpType = &AfxGetModuleState()->m_pCurrentWinApp[2].m_eHelpType;
  v7 = (char *)(szRootDir - (char *)p_m_eHelpType);
  do
  {
    v8 = *(_BYTE *)p_m_eHelpType;
    *((_BYTE *)p_m_eHelpType + (_DWORD)v7) = *(_BYTE *)p_m_eHelpType;
    p_m_eHelpType = (AFX_HELP_TYPE *)((char *)p_m_eHelpType + 1);
  }
  while ( v8 != 0 );
  EnsureTrailingBackslash(psz: szRootDir);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &strAutosaveDirectory,
    pszSrc: szRootDir);
  v36 = 0;
  v9 = 1;
  nNumberActualAutosaves = 0;
  nOldestAutosaveNumber = 1;
  nExpectedNextAutosaveNumber = 1;
  nLastHole = 0;
  nMaxAutosavesPerMap = Options.general.iMaxAutosavesPerMap;
  v10 = ATL::operator+(a1: a2, a2: 1, result: &v24, str1: &strAutosaveDirectory, psz2: "*.vmf_autosave");
  LOBYTE(v36) = 1;
  FirstFileA = FindFirstFileA(lpFileName: v10->m_pszData, lpFindFileData: &fileData);
  hFile = FirstFileA;
  LOBYTE(v36) = 0;
  v12 = v24.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)v24.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v12 + 4))(a1: v12);
  if ( FirstFileA != (HANDLE)-1 )
  {
    if ( GetLastError() != 18 )
    {
      do
      {
        insert.key = fileData.ftLastAccessTime;
        insert.elem = fileData;
        CUtlRBTree<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int,CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int>,int>>::Insert(
          this: &pFileMap->m_Tree,
          &insert);
        v5 += fileData.nFileSizeLow;
        fileAccessTime = fileData.ftLastAccessTime;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
          this: &currentFilename,
          pszSrc: fileData.cFileName);
        LOBYTE(v36) = 3;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
          this: &currentFilename,
          result: &strMapName,
          nCount: *((_DWORD *)currentFilename.m_pszData - 3) - 17);
        LOBYTE(v36) = 4;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Mid(
          this: &currentFilename,
          result: &strCurrentNumber,
          iFirst: *((_DWORD *)currentFilename.m_pszData - 3) - 16,
          nCount: 3);
        LOBYTE(v36) = 5;
        m_pszData = strCurrentNumber.m_pszData;
        if ( *((int *)strCurrentNumber.m_pszData - 1) > 1 )
        {
          ATL::CSimpleStringT<char,0>::Fork(
            this: &strCurrentNumber,
            nLength: *((_DWORD *)strCurrentNumber.m_pszData - 3));
          m_pszData = strCurrentNumber.m_pszData;
        }
        v14 = atoi(nptr: m_pszData);
        if ( pstrMapTitle->m_pszData == nullptr )
          ATL::AtlThrowImpl(hr: -2147467259);
        if ( _mbsicmp(
               s1: (const unsigned __int8 *)strMapName.m_pszData,
               s2: (const unsigned __int8 *)pstrMapTitle->m_pszData) == 0 )
        {
          ++nNumberActualAutosaves;
          if ( oldestAutosaveTime.dwLowDateTime == 0 )
            oldestAutosaveTime = fileAccessTime;
          if ( v14 != nExpectedNextAutosaveNumber )
            nLastHole = v14;
          nExpectedNextAutosaveNumber = v14 + 1;
          if ( v14 + 1 > 999 )
            nExpectedNextAutosaveNumber = 1;
          if ( CompareFileTime(lpFileTime1: &fileAccessTime, lpFileTime2: &oldestAutosaveTime) == -1 )
          {
            oldestAutosaveTime = fileAccessTime;
            nOldestAutosaveNumber = v14;
          }
        }
        FindNextFileA(hFindFile: hFile, lpFindFileData: &fileData);
        LOBYTE(v36) = 4;
        v15 = strCurrentNumber.m_pszData - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)strCurrentNumber.m_pszData - 1) <= 0 )
          (*(void (__stdcall **)(char *))(**(_DWORD **)v15 + 4))(a1: v15);
        LOBYTE(v36) = 3;
        v16 = strMapName.m_pszData - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)strMapName.m_pszData - 1) <= 0 )
          (*(void (__stdcall **)(char *))(**(_DWORD **)v16 + 4))(a1: v16);
        LOBYTE(v36) = 0;
        v17 = currentFilename.m_pszData - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)currentFilename.m_pszData - 1) <= 0 )
          (*(void (__stdcall **)(char *))(**(_DWORD **)v17 + 4))(a1: v17);
      }
      while ( GetLastError() != 18 );
      v9 = nExpectedNextAutosaveNumber;
      FirstFileA = hFile;
    }
    FindClose(hFindFile: FirstFileA);
  }
  if ( nNumberActualAutosaves >= nMaxAutosavesPerMap )
  {
    v9 = nOldestAutosaveNumber;
  }
  else if ( v9 <= nLastHole )
  {
    v9 = nLastHole;
  }
  *pdwTotalDirSize = v5;
  v36 = -1;
  v18 = strAutosaveDirectory.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strAutosaveDirectory.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v18 + 4))(a1: v18);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10042A00
// Name: public: bool CHammer::VerifyAutosaveDirectory(char __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHammer::VerifyAutosaveDirectory(CHammer *this, char *szAutosaveDirectory)
{
  char *v2; // eax
  int v3; // edx
  char v4; // cl
  char *v5; // edi
  char v6; // al
  AFX_HELP_TYPE *p_m_eHelpType; // eax
  char *v8; // edx
  char v9; // cl
  const char *v11; // eax
  int v12; // ecx
  char *v13; // eax
  HANDLE FileA; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v15; // eax
  HANDLE v16; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v17; // eax
  char v18; // [esp+3h] [ebp-115h] BYREF
  char szRootDir[260]; // [esp+4h] [ebp-114h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v20; // [esp+108h] [ebp-10h] BYREF
  int v21; // [esp+114h] [ebp-4h]

  v2 = szAutosaveDirectory;
  if ( szAutosaveDirectory != nullptr )
  {
    v3 = szRootDir - szAutosaveDirectory;
    do
    {
      v4 = *v2;
      v2[v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
    if ( szRootDir[0] == 0 )
      goto LABEL_13;
    if ( szRootDir[strlen(szRootDir) - 1] != 92 )
    {
      v5 = &v18;
      do
        v6 = *++v5;
      while ( v6 != 0 );
      strcpy(v5, "\\");
    }
  }
  else
  {
    p_m_eHelpType = &AfxGetModuleState()->m_pCurrentWinApp[2].m_eHelpType;
    v8 = (char *)(szRootDir - (char *)p_m_eHelpType);
    do
    {
      v9 = *(_BYTE *)p_m_eHelpType;
      *((_BYTE *)p_m_eHelpType + (_DWORD)v8) = *(_BYTE *)p_m_eHelpType;
      p_m_eHelpType = (AFX_HELP_TYPE *)((char *)p_m_eHelpType + 1);
    }
    while ( v9 != 0 );
    EnsureTrailingBackslash(psz: szRootDir);
  }
  if ( szRootDir[0] == 0 )
  {
LABEL_13:
    AfxMessageBox(
      lpszText: "No autosave directory has been selected.\nThe autosave feature will be disabled until a directory is entered.",
      nType: 0,
      nIDHelp: 0);
    return 0;
  }
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&szAutosaveDirectory,
    pszSrc: szRootDir);
  v21 = 0;
  if ( g_pFullFileSystem->IsSteam(this: g_pFullFileSystem) )
  {
    EditorUtil_ConvertPath(
      str: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&szAutosaveDirectory,
      bExpand: true);
    v11 = szAutosaveDirectory;
    v12 = *((_DWORD *)szAutosaveDirectory - 3);
    if ( v12 < 1 )
      ATL::AtlThrowImpl(hr: -2147024809);
    if ( szAutosaveDirectory[1] != 58 )
      goto LABEL_21;
    if ( v12 < 2 )
      ATL::AtlThrowImpl(hr: -2147024809);
    if ( szAutosaveDirectory[2] != 92 )
      goto LABEL_21;
LABEL_27:
    FileA = CreateFileA(
              lpFileName: v11,
              dwDesiredAccess: 0x80000000,
              dwShareMode: 7u,
              lpSecurityAttributes: nullptr,
              dwCreationDisposition: 3u,
              dwFlagsAndAttributes: 0x2000000u,
              hTemplateFile: nullptr);
    if ( FileA == (HANDLE)-1 )
    {
      if ( !CreateDirectoryA(lpPathName: szAutosaveDirectory, lpSecurityAttributes: nullptr) )
      {
        AfxMessageBox(
          lpszText: "The current autosave directory does not exist and could not be created.  \n"
          "The autosave feature will be disabled until a new directory is entered.",
          nType: 0,
          nIDHelp: 0);
LABEL_30:
        v21 = -1;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&szAutosaveDirectory);
        return 0;
      }
    }
    else
    {
      CloseHandle(hObject: FileA);
      v15 = ATL::operator+(
              a1: (int)CloseHandle,
              a2: (int)CreateFileA,
              result: &v20,
              str1: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&szAutosaveDirectory,
              psz2: "test.txt");
      LOBYTE(v21) = 3;
      v16 = CreateFileA(
              lpFileName: v15->m_pszData,
              dwDesiredAccess: 0x80000000,
              dwShareMode: 7u,
              lpSecurityAttributes: nullptr,
              dwCreationDisposition: 1u,
              dwFlagsAndAttributes: 0x2000000u,
              hTemplateFile: nullptr);
      LOBYTE(v21) = 0;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &v20);
      if ( v16 == (HANDLE)-1 )
      {
        if ( GetLastError() == 5 )
          AfxMessageBox(
            lpszText: "The autosave directory is marked as read only.  Please remove the read only attribute or select a new direct"
            "ory in Tools->Options->General.\n"
            "The autosave feature will be disabled.",
            nType: 0,
            nIDHelp: 0);
        else
          AfxMessageBox(
            lpszText: "There is a problem with the autosave directory.  Please select a new directory in Tools->Options->General.\n"
            "The autosave feature will be disabled.",
            nType: 0,
            nIDHelp: 0);
        goto LABEL_30;
      }
      CloseHandle(hObject: v16);
      v17 = ATL::operator+(
              a1: (int)CloseHandle,
              a2: (int)v16,
              result: &v20,
              str1: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&szAutosaveDirectory,
              psz2: "test.txt");
      LOBYTE(v21) = 4;
      DeleteFileA(lpFileName: v17->m_pszData);
      LOBYTE(v21) = 0;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &v20);
    }
    v21 = -1;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&szAutosaveDirectory);
    return 1;
  }
  if ( szRootDir[1] == 58 && szRootDir[2] == 92 )
  {
    v11 = szAutosaveDirectory;
    goto LABEL_27;
  }
LABEL_21:
  AfxMessageBox(
    lpszText: "The current autosave directory does not have an absolute path.\n"
    "The autosave feature will be disabled until a new directory is entered.",
    nType: 0,
    nIDHelp: 0);
  v21 = -1;
  v13 = szAutosaveDirectory - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)szAutosaveDirectory - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v13 + 4))(a1: v13);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10042D00
// Name: public: void CHammer::LoadLastGoodSave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::LoadLastGoodSave(CHammer *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  char *v2; // eax
  int v3; // edx
  char v4; // cl
  AFX_MODULE_STATE *v5; // eax
  int v6; // edi
  AFX_HELP_TYPE *p_m_eHelpType; // eax
  char *v8; // edx
  char v9; // cl
  char *v10; // esi
  char *v11; // eax
  char *v12; // eax
  char szRenameMessage[776]; // [esp+0h] [ebp-628h] BYREF
  char szMapDir[260]; // [esp+308h] [ebp-320h] BYREF
  char szLastSaveCopy[260]; // [esp+40Ch] [ebp-21Ch] BYREF
  char szAutoSaveDir[260]; // [esp+510h] [ebp-118h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > newMapPath; // [esp+614h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strLastGoodSave; // [esp+618h] [ebp-10h] BYREF
  int v19; // [esp+624h] [ebp-4h]

  ModuleState = AfxGetModuleState();
  ModuleState->m_pCurrentWinApp->GetProfileStringA(
    this: ModuleState->m_pCurrentWinApp,
    result: &strLastGoodSave,
    a3: "General",
    a4: "Last Good Save",
    a5: &var);
  v19 = 0;
  v2 = g_pGameConfig->szMapDir;
  v3 = szMapDir - g_pGameConfig->szMapDir;
  do
  {
    v4 = *v2;
    v2[v3] = *v2;
    ++v2;
  }
  while ( v4 != 0 );
  if ( *((_DWORD *)strLastGoodSave.m_pszData - 3) != 0 )
  {
    v5 = AfxGetModuleState();
    v6 = (int)v5->m_pCurrentWinApp->OpenDocumentFile(this: v5->m_pCurrentWinApp, a2: strLastGoodSave.m_pszData);
    if ( v6 != 0 )
    {
      p_m_eHelpType = &AfxGetModuleState()->m_pCurrentWinApp[2].m_eHelpType;
      v8 = (char *)(szAutoSaveDir - (char *)p_m_eHelpType);
      do
      {
        v9 = *(_BYTE *)p_m_eHelpType;
        *((_BYTE *)p_m_eHelpType + (_DWORD)v8) = *(_BYTE *)p_m_eHelpType;
        p_m_eHelpType = (AFX_HELP_TYPE *)((char *)p_m_eHelpType + 1);
      }
      while ( v9 != 0 );
      EnsureTrailingBackslash(psz: szAutoSaveDir);
      if ( vgui::TreeView::GetSelectedItemCount(this: (vgui::TreeView *)v6) == 0
        && V_stristr(pStr: *(const char **)(v6 + 36), pSearch: szAutoSaveDir) != nullptr )
      {
        _V_strcpy(dest: szLastSaveCopy, src: strLastGoodSave.m_pszData);
        v10 = _V_strrchr(s: strLastGoodSave.m_pszData, c: 92) + 1;
        v11 = _V_strrchr(s: strLastGoodSave.m_pszData, c: 95);
        if ( v11 == nullptr )
          v11 = _V_strrchr(s: strLastGoodSave.m_pszData, c: 46);
        strcpy(v11, ".vmf");
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
          this: &newMapPath,
          pszSrc: szMapDir);
        LOBYTE(v19) = 2;
        ATL::CSimpleStringT<char,0>::Append(this: &newMapPath, pszSrc: "\\");
        ATL::CSimpleStringT<char,0>::Append(this: &newMapPath, pszSrc: v10);
        sprintf(
          string: szRenameMessage,
          format: "The last saved map was found in the autosave directory.\n"
          "Would you like to rename it from \"%s\" to \"%s\"?\n"
          "NOTE: This will not save the file with the new name; it will only rename it.",
          szLastSaveCopy,
          newMapPath.m_pszData);
        if ( AfxMessageBox(lpszText: szRenameMessage, nType: 4u, nIDHelp: 0) == 6 )
          (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v6 + 88))(a1: v6, a2: newMapPath.m_pszData, a3: 1);
        LOBYTE(v19) = 0;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &newMapPath);
      }
    }
    else
    {
      AfxMessageBox(lpszText: "There was an error loading the last saved file.", nType: 0, nIDHelp: 0);
    }
  }
  v19 = -1;
  v12 = strLastGoodSave.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strLastGoodSave.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v12 + 4))(a1: v12);
}

//------------------------------------------------------------------------------
// Address: 0x10042F70
// Name: public: bool CHammer::LoadSequences(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHammer::LoadSequences(CHammer *this, const char *szSeqFileName)
{
  CWnd **p_m_pActiveWnd; // eax
  char *v3; // edx
  char v4; // cl
  char *v6; // eax
  char *v7; // ebx
  int v8; // edi
  std::fpos<int> v9; // [esp-18h] [ebp-624h] BYREF
  CCOMMAND cmd; // [esp+Ch] [ebp-600h] BYREF
  char szFullPath[260]; // [esp+330h] [ebp-2DCh] BYREF
  char szRootDir[260]; // [esp+434h] [ebp-1D8h] BYREF
  std::ifstream file; // [esp+538h] [ebp-D4h] BYREF
  int nSeq; // [esp+5E8h] [ebp-24h]
  int nCmd; // [esp+5ECh] [ebp-20h]
  float fThisVersion; // [esp+5F0h] [ebp-1Ch] BYREF
  CHammer *v17; // [esp+5F4h] [ebp-18h]
  int i; // [esp+5F8h] [ebp-14h]
  unsigned int dwSize; // [esp+5FCh] [ebp-10h] BYREF
  int v20; // [esp+608h] [ebp-4h]
  int iCmd; // [esp+614h] [ebp+8h]

  v17 = this;
  p_m_pActiveWnd = &AfxGetModuleState()->m_pCurrentWinApp[1].m_pActiveWnd;
  v3 = (char *)(szRootDir - (char *)p_m_pActiveWnd);
  do
  {
    v4 = *(_BYTE *)p_m_pActiveWnd;
    *((_BYTE *)p_m_pActiveWnd + (_DWORD)v3) = *(_BYTE *)p_m_pActiveWnd;
    p_m_pActiveWnd = (CWnd **)((char *)p_m_pActiveWnd + 1);
  }
  while ( v4 != 0 );
  EnsureTrailingBackslash(psz: szRootDir);
  V_MakeAbsolutePath(pOut: szFullPath, outLen: 260, pPath: szSeqFileName, pStartingDir: szRootDir);
  std::ifstream::ifstream(this: &file, _Filename: szFullPath, _Mode: 33, _Prot: 64, a5: 1);
  v20 = 0;
  if ( *(_DWORD *)&file._Filebuffer[12] != 0 )
  {
    memset(&v9._Fpos, 0, 12);
    v9._Myoff = strlen(pszSequenceHdr);
    std::istream::seekg(this: &file, _Pos: v9);
    std::istream::read(this: &file, _Str: (char *)&fThisVersion, _Count: 4);
    std::istream::read(this: &file, _Str: (char *)&dwSize, _Count: 4);
    nSeq = dwSize;
    for ( i = 0; i < nSeq; ++i )
    {
      v6 = (char *)operator new(nSize: 0x94u);
      LOBYTE(v20) = 2;
      if ( v6 != nullptr )
      {
        *(_DWORD *)v6 = &CArray<CCOMMAND,CCOMMAND &>::`vftable';
        *((_DWORD *)v6 + 1) = 0;
        *((_DWORD *)v6 + 4) = 0;
        *((_DWORD *)v6 + 3) = 0;
        *((_DWORD *)v6 + 2) = 0;
        LOBYTE(v20) = 2;
        v7 = v6;
      }
      else
      {
        v7 = nullptr;
      }
      LOBYTE(v20) = 0;
      std::istream::read(this: &file, _Str: v7 + 20, _Count: 128);
      std::istream::read(this: &file, _Str: (char *)&dwSize, _Count: 4);
      nCmd = dwSize;
      for ( iCmd = 0; iCmd < nCmd; ++iCmd )
      {
        if ( fThisVersion >= 0.2 )
        {
          std::istream::read(this: &file, _Str: (char *)&cmd, _Count: 804);
        }
        else
        {
          std::istream::read(this: &file, _Str: (char *)&cmd, _Count: 803);
          cmd.bNoWait = 0;
        }
        v8 = *((_DWORD *)v7 + 2);
        if ( v8 < 0 )
          AfxThrowInvalidArgException();
        CArray<CCOMMAND,CCOMMAND &>::SetSize(this: (CArray<CCOMMAND,CCOMMAND &> *)v7, nNewSize: v8 + 1, nGrowBy: -1);
        *(CCOMMAND *)(*((_DWORD *)v7 + 1) + 804 * v8) = cmd;
      }
      CUIntArray::SetAtGrow(this: &v17->m_CmdSequences, nIndex: v17->m_CmdSequences.m_nSize, newElement: v7);
    }
    v20 = -1;
    std::ifstream::~ifstream<char,std::char_traits<char>>(this: (std::ifstream *)file.gap68);
    v20 = -1;
    *(_DWORD *)file.gap68 = &std::ios_base::`vftable';
    std::ios_base::_Ios_base_dtor(_This: (std::ios_base *)file.gap68);
    return 1;
  }
  else
  {
    v20 = -1;
    std::ifstream::~ifstream<char,std::char_traits<char>>(this: (std::ifstream *)file.gap68);
    v20 = -1;
    *(_DWORD *)file.gap68 = &std::ios_base::`vftable';
    std::ios_base::_Ios_base_dtor(_This: (std::ios_base *)file.gap68);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043230
// Name: public: void CHammer::SaveSequences(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::SaveSequences(CHammer *this)
{
  CHammer *v1; // esi
  CWnd **p_m_pActiveWnd; // eax
  char *v3; // edx
  char v4; // cl
  signed int v5; // eax
  int m_nSize; // edi
  int v7; // eax
  void *v8; // edi
  signed int v9; // ebx
  int v10; // esi
  int v11; // eax
  int v12; // eax
  char szFullPath[260]; // [esp+4h] [ebp-2D0h] BYREF
  char szRootDir[260]; // [esp+108h] [ebp-1CCh] BYREF
  std::ofstream file; // [esp+20Ch] [ebp-C8h] BYREF
  CHammer *v16; // [esp+2B4h] [ebp-20h]
  unsigned int dwSize; // [esp+2B8h] [ebp-1Ch] BYREF
  int nSeq; // [esp+2BCh] [ebp-18h]
  int i; // [esp+2C0h] [ebp-14h]
  int v20; // [esp+2C4h] [ebp-10h]
  int v21; // [esp+2D0h] [ebp-4h]

  v1 = this;
  v16 = this;
  p_m_pActiveWnd = &AfxGetModuleState()->m_pCurrentWinApp[1].m_pActiveWnd;
  v3 = (char *)(szRootDir - (char *)p_m_pActiveWnd);
  do
  {
    v4 = *(_BYTE *)p_m_pActiveWnd;
    *((_BYTE *)p_m_pActiveWnd + (_DWORD)v3) = *(_BYTE *)p_m_pActiveWnd;
    p_m_pActiveWnd = (CWnd **)((char *)p_m_pActiveWnd + 1);
  }
  while ( v4 != 0 );
  EnsureTrailingBackslash(psz: szRootDir);
  V_MakeAbsolutePath(pOut: szFullPath, outLen: 260, pPath: "CmdSeq.wc", pStartingDir: szRootDir);
  std::ofstream::ofstream(this: &file, _Filename: szFullPath, _Mode: 34, _Prot: 64, a5: 1);
  v21 = 0;
  v5 = std::char_traits<char>::length(str: pszSequenceHdr);
  std::ostream::write(this: &file, _Str: pszSequenceHdr, _Count: v5);
  std::ostream::write(this: &file, _Str: (const char *)&fSequenceVersion, _Count: 4);
  m_nSize = v1->m_CmdSequences.m_nSize;
  nSeq = m_nSize;
  dwSize = m_nSize;
  std::ostream::write(this: &file, _Str: (const char *)&dwSize, _Count: 4);
  v7 = 0;
  i = 0;
  if ( m_nSize > 0 )
  {
    while ( 1 )
    {
      if ( v7 < 0 || v7 >= v1->m_CmdSequences.m_nSize )
        goto LABEL_20;
      v8 = v1->m_CmdSequences.m_pData[v7];
      std::ostream::write(this: &file, _Str: (const char *)v8 + 20, _Count: 128);
      dwSize = *((_DWORD *)v8 + 2);
      v9 = dwSize;
      std::ostream::write(this: &file, _Str: (const char *)&dwSize, _Count: 4);
      v10 = 0;
      if ( v9 > 0 )
        break;
LABEL_13:
      if ( ++i >= nSeq )
        goto LABEL_14;
      v7 = i;
      v1 = v16;
    }
    v20 = 0;
    while ( v10 >= 0 && v10 < *((_DWORD *)v8 + 2) )
    {
      std::ostream::write(this: &file, _Str: (const char *)(v20 + *((_DWORD *)v8 + 1)), _Count: 804);
      v20 += 804;
      if ( ++v10 >= v9 )
        goto LABEL_13;
    }
LABEL_20:
    AfxThrowInvalidArgException();
  }
LABEL_14:
  v21 = -1;
  v11 = *(_DWORD *)(*(_DWORD *)file.gap0 + 4);
  nSeq = (int)&file.gap5C[4];
  *(_DWORD *)&file.gap0[v11] = &std::ofstream::`vftable';
  v21 = 3;
  v16 = (CHammer *)&file.gap0[4];
  *(_DWORD *)&file.gap0[4] = &std::filebuf::`vftable';
  if ( *(_DWORD *)&file._Filebuffer[8] != 0 && **(std::ofstream ***)&file.gap0[20] == (std::ofstream *)&file.gap0[76] )
  {
    v12 = *(_DWORD *)&file.gap0[68];
    **(_DWORD **)&file.gap0[20] = *(_DWORD *)&file.gap0[64];
    **(_DWORD **)&file.gap0[36] = v12;
    **(_DWORD **)&file.gap0[52] = 0;
  }
  if ( file._Filebuffer[4] != 0 )
    std::filebuf::close(this: (std::filebuf *)&file.gap0[4]);
  LOBYTE(v21) = 1;
  std::streambuf::~streambuf<char,std::char_traits<char>>(this: (std::streambuf *)&file.gap0[4]);
  v21 = -1;
  *(_DWORD *)&file.gap0[*(_DWORD *)(*(_DWORD *)file.gap0 + 4)] = &std::ostream::`vftable';
  nSeq = (int)&file.gap5C[4];
  v21 = -1;
  *(_DWORD *)&file.gap5C[4] = &std::ios_base::`vftable';
  std::ios_base::_Ios_base_dtor(_This: (std::ios_base *)&file.gap5C[4]);
}

//------------------------------------------------------------------------------
// Address: 0x100434C0
// Name: public: void CHammer::Autosave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::Autosave(CHammer *this)
{
  CMapDoc *v1; // ebx
  unsigned int v2; // esi
  AFX_HELP_TYPE *p_m_eHelpType; // eax
  char *v4; // edx
  char v5; // cl
  ATL::CStringData *v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  ATL::CStringData *v10; // eax
  int NextAutosaveNumber; // eax
  const char *v12; // eax
  ATL::CStringData *v13; // eax
  ATL::CStringData *v14; // eax
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v15; // eax
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v16; // eax
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v17; // eax
  char *m_pszData; // eax
  int Inorder; // eax
  int v20; // ebx
  UtlRBTreeNode_t<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int> *v21; // esi
  int v22; // eax
  char v23; // cl
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v24; // eax
  char *v25; // eax
  unsigned int v26; // esi
  char *v27; // ecx
  UtlRBTreeNode_t<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int> *m_pMemory; // eax
  int m_FirstFree; // edx
  int m_nGrowSize; // esi
  UtlRBTreeNode_t<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int> *v31; // eax
  char filename[260]; // [esp+4h] [ebp-3ACh] BYREF
  _WIN32_FIND_DATAA fileData; // [esp+108h] [ebp-2A8h]
  char szRootDir[260]; // [esp+248h] [ebp-168h] BYREF
  char szNumberChars[4]; // [esp+34Ch] [ebp-64h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strAutosaveString; // [esp+350h] [ebp-60h] BYREF
  unsigned int dwMaxAutosaveSpace; // [esp+354h] [ebp-5Ch]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strExtension; // [esp+358h] [ebp-58h] BYREF
  CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int> autosaveFiles; // [esp+35Ch] [ebp-54h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v40; // [esp+380h] [ebp-30h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+384h] [ebp-2Ch] BYREF
  unsigned int dwTotalAutosaveDirectorySize; // [esp+388h] [ebp-28h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strAutosaveDirectory; // [esp+38Ch] [ebp-24h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strSaveName; // [esp+390h] [ebp-20h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strMapTitle; // [esp+394h] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strMapFilename; // [esp+398h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strAutosaveNumber; // [esp+39Ch] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v48; // [esp+3A0h] [ebp-10h] BYREF
  int v49; // [esp+3ACh] [ebp-4h]

  v48.m_pszData = (char *)this;
  if ( Options.general.bEnableAutosave != 0 )
  {
    if ( CHammer::VerifyAutosaveDirectory(this, szAutosaveDirectory: nullptr) == 1 )
    {
      v1 = CMapDoc::m_pMapDoc;
      v2 = Options.general.iMaxAutosaveSpace << 20;
      dwMaxAutosaveSpace = Options.general.iMaxAutosaveSpace << 20;
      memset(&autosaveFiles.m_Tree.m_Elements, 0, sizeof(autosaveFiles.m_Tree.m_Elements));
      autosaveFiles.m_Tree.m_Root = -1;
      autosaveFiles.m_Tree.m_NumElements = 0;
      autosaveFiles.m_Tree.m_FirstFree = -1;
      autosaveFiles.m_Tree.m_LastAlloc.index = -1;
      autosaveFiles.m_Tree.m_pElements = nullptr;
      v49 = 2;
      autosaveFiles.m_Tree.m_LessFunc.m_LessFunc = LessFunc;
      if ( CMapDoc::m_pMapDoc != nullptr && CMapDoc::NeedsAutosave(this: (CVMTPreviewPanel *)CMapDoc::m_pMapDoc) != 0 )
      {
        p_m_eHelpType = &AfxGetModuleState()->m_pCurrentWinApp[2].m_eHelpType;
        v4 = (char *)(szRootDir - (char *)p_m_eHelpType);
        do
        {
          v5 = *(_BYTE *)p_m_eHelpType;
          v4[(_DWORD)p_m_eHelpType] = *(_BYTE *)p_m_eHelpType;
          p_m_eHelpType = (AFX_HELP_TYPE *)((char *)p_m_eHelpType + 1);
        }
        while ( v5 != 0 );
        EnsureTrailingBackslash(psz: szRootDir);
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
          this: &strAutosaveDirectory,
          pszSrc: szRootDir);
        LOBYTE(v49) = 3;
        if ( g_pFullFileSystem->IsSteam(this: g_pFullFileSystem) )
          EditorUtil_ConvertPath(str: &strAutosaveDirectory, bExpand: true);
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
          this: &strExtension,
          pszSrc: ".vmf");
        LOBYTE(v49) = 4;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &strMapTitle);
        LOBYTE(v49) = 5;
        v6 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)v1->m_strPathName.m_pszData - 1);
        strMapFilename.m_pszData = (char *)&v6[1];
        LOBYTE(v49) = 7;
        dwTotalAutosaveDirectorySize = 0;
        if ( v6->nDataLength != 0 )
        {
          v7 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::ReverseFind(
                 this: &strMapFilename,
                 ch: 0x5Cu)
             + 1;
          if ( *((int *)strMapFilename.m_pszData - 3) > 0 )
          {
            _mbschr(string: strMapFilename.m_pszData, c: 0x2Eu);
            if ( v9 != 0 )
              v8 = v9 - (unsigned int)strMapFilename.m_pszData;
            else
              v8 = -1;
          }
          else
          {
            v8 = -1;
          }
          v10 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Mid(
                                      this: &strMapFilename,
                                      &result,
                                      iFirst: v7,
                                      nCount: v8 - v7);
          LOBYTE(v49) = 8;
          ATL::CSimpleStringT<char,0>::operator=(this: &strMapTitle, strSrc: v10);
          LOBYTE(v49) = 7;
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &result);
          v2 = dwMaxAutosaveSpace;
        }
        else
        {
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::operator=(
            this: &strMapTitle,
            pszSrc: "autosave");
        }
        NextAutosaveNumber = CHammer::GetNextAutosaveNumber(
                               this: (CHammer *)v48.m_pszData,
                               a2: 0,
                               pFileMap: &autosaveFiles,
                               pdwTotalDirSize: &dwTotalAutosaveDirectorySize,
                               pstrMapTitle: &strMapTitle);
        v12 = itoa(val: NextAutosaveNumber, buf: szNumberChars, radix: 10);
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
          this: &strAutosaveString,
          pszSrc: v12);
        LOBYTE(v49) = 9;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
          this: &strAutosaveNumber,
          pszSrc: "000");
        LOBYTE(v49) = 10;
        ATL::CSimpleStringT<char,0>::Append(
          this: &strAutosaveNumber,
          pszSrc: strAutosaveString.m_pszData,
          nLength: *((_DWORD *)strAutosaveString.m_pszData - 3));
        v13 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Right(
                                    this: &strAutosaveNumber,
                                    result: &v48,
                                    nCount: 3);
        LOBYTE(v49) = 11;
        ATL::CSimpleStringT<char,0>::operator=(this: &strAutosaveNumber, strSrc: v13);
        LOBYTE(v49) = 10;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &v48);
        v14 = (ATL::CStringData *)ATL::operator+(result: &v48, psz1: "_", str2: &strAutosaveNumber);
        LOBYTE(v49) = 12;
        ATL::CSimpleStringT<char,0>::operator=(this: &strAutosaveNumber, strSrc: v14);
        LOBYTE(v49) = 10;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &v48);
        v15 = ATL::operator+(result: &v40, str1: &strAutosaveDirectory, str2: &strMapTitle);
        LOBYTE(v49) = 13;
        v16 = ATL::operator+(&result, str1: v15, str2: &strAutosaveNumber);
        LOBYTE(v49) = 14;
        v17 = ATL::operator+(result: &v48, str1: v16, str2: &strExtension);
        LOBYTE(v49) = 15;
        ATL::operator+(a1: 0, a2: v2, result: &strSaveName, str1: v17, psz2: "_autosave");
        LOBYTE(v49) = 17;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &v48);
        LOBYTE(v49) = 18;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &result);
        LOBYTE(v49) = 19;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &v40);
        m_pszData = strSaveName.m_pszData;
        if ( *((int *)strSaveName.m_pszData - 1) > 1 )
        {
          ATL::CSimpleStringT<char,0>::Fork(this: &strSaveName, nLength: *((_DWORD *)strSaveName.m_pszData - 3));
          m_pszData = strSaveName.m_pszData;
        }
        CMapDoc::SaveVMF(this: v1, pszFileName: m_pszData, saveFlags: 2);
        CMapDoc::SetAutosaveFlag(this: (vgui::Slider *)v1, ticks: 0);
        if ( dwTotalAutosaveDirectorySize > v2 )
        {
          do
          {
            Inorder = CUtlRBTree<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int,CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int>,int>>::FirstInorder(this: &autosaveFiles.m_Tree);
            v20 = Inorder;
            if ( Inorder < 0
              || Inorder >= autosaveFiles.m_Tree.m_Elements.m_nAllocationCount
              || Inorder > autosaveFiles.m_Tree.m_LastAlloc.index
              || CUtlRBTree<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int,CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int>,int>>::LeftChild(
                   this: &autosaveFiles.m_Tree,
                   i: Inorder) == Inorder )
            {
              break;
            }
            v48.m_pszData = (char *)(344 * v20);
            fileData = autosaveFiles.m_Tree.m_Elements.m_pMemory[v20].m_Data.elem;
            v21 = &autosaveFiles.m_Tree.m_Elements.m_pMemory[v20 + 1];
            v22 = 0;
            do
            {
              v23 = fileData.cFileName[v22];
              filename[v22++] = v23;
            }
            while ( v23 != 0 );
            v24 = ATL::operator+(
                    a1: (int)szRootDir,
                    a2: (int)v21,
                    result: &v40,
                    str1: &strAutosaveDirectory,
                    psz2: filename);
            LOBYTE(v49) = 20;
            DeleteFileA(lpFileName: v24->m_pszData);
            LOBYTE(v49) = 19;
            v25 = v40.m_pszData - 16;
            if ( _InterlockedDecrement((volatile signed __int32 *)v40.m_pszData - 1) <= 0 )
              (*(void (__stdcall **)(char *))(**(_DWORD **)v25 + 4))(a1: v25);
            v26 = dwTotalAutosaveDirectorySize - fileData.nFileSizeLow;
            dwTotalAutosaveDirectorySize -= fileData.nFileSizeLow;
            if ( v20 != -1 )
            {
              CUtlRBTree<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int,CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int>,int>>::Unlink(
                this: &autosaveFiles.m_Tree,
                elem: v20);
              v27 = v48.m_pszData;
              m_pMemory = autosaveFiles.m_Tree.m_Elements.m_pMemory;
              m_FirstFree = autosaveFiles.m_Tree.m_FirstFree;
              --autosaveFiles.m_Tree.m_NumElements;
              *(_DWORD *)&v48.m_pszData[(unsigned int)autosaveFiles.m_Tree.m_Elements.m_pMemory] = v20;
              *(int *)((char *)&m_pMemory->m_Right + (_DWORD)v27) = m_FirstFree;
              autosaveFiles.m_Tree.m_FirstFree = v20;
            }
          }
          while ( v26 > dwMaxAutosaveSpace );
        }
        CUtlRBTree<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int,CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int>,int>>::RemoveAll(this: &autosaveFiles.m_Tree);
        LOBYTE(v49) = 10;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &strSaveName);
        LOBYTE(v49) = 9;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &strAutosaveNumber);
        LOBYTE(v49) = 7;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &strAutosaveString);
        LOBYTE(v49) = 5;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &strMapFilename);
        LOBYTE(v49) = 4;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &strMapTitle);
        LOBYTE(v49) = 3;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &strExtension);
        LOBYTE(v49) = 2;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &strAutosaveDirectory);
      }
      v49 = 23;
      CUtlRBTree<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int,CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<_FILETIME,_WIN32_FIND_DATAA,int>::Node_t,int>,int>>::RemoveAll(this: &autosaveFiles.m_Tree);
      m_nGrowSize = autosaveFiles.m_Tree.m_Elements.m_nGrowSize;
      v31 = autosaveFiles.m_Tree.m_Elements.m_pMemory;
      autosaveFiles.m_Tree.m_FirstFree = -1;
      if ( autosaveFiles.m_Tree.m_Elements.m_nGrowSize >= 0 )
      {
        if ( autosaveFiles.m_Tree.m_Elements.m_pMemory != nullptr )
        {
          free(pMem: autosaveFiles.m_Tree.m_Elements.m_pMemory);
          v31 = nullptr;
          autosaveFiles.m_Tree.m_Elements.m_pMemory = nullptr;
        }
        autosaveFiles.m_Tree.m_Elements.m_nAllocationCount = 0;
      }
      autosaveFiles.m_Tree.m_LastAlloc.index = -1;
      v49 = -1;
      if ( m_nGrowSize >= 0 && v31 != nullptr )
        free(pMem: v31);
    }
    else
    {
      Options.general.bEnableAutosave = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043980
// Name: protected: virtual struct AFX_MSGMAP const __near * CHammer::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CHammer::GetMessageMap(CHammer *this)
{
  return (const AFX_MSGMAP *)&off_105DB664;
}

//------------------------------------------------------------------------------
// Address: 0x10043990
// Name: protected: enum InitReturnVal_t CHammer::HammerInternalInit(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __thiscall CHammer::HammerInternalInit(CHammer *this)
{
  HDC CompatibleDC; // eax
  HDC v3; // esi
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v6; // eax
  unsigned int v7; // eax
  CMultiDocTemplate *v8; // eax
  CHammerDocTemplate *v9; // esi
  CMultiDocTemplate *v10; // eax
  CHammerDocTemplate *v11; // esi
  AFX_MODULE_STATE *v12; // eax
  AFX_MODULE_STATE *v13; // eax
  CMainFrame *v14; // eax
  CMainFrame *v15; // esi
  CHammerVGui *v16; // eax
  HWND DesktopWindow; // eax
  HWND v18; // ebx
  char *v19; // esi
  char *v20; // eax
  int left; // ebx
  CWnd **p_m_pActiveWnd; // eax
  char *v23; // edx
  char v24; // cl
  vgui::Splitter *v25; // ecx
  char *m_szModDir; // eax
  int v27; // edx
  char v28; // cl
  AFX_MODULE_STATE *v29; // eax
  int i; // esi
  CUtlVector<void (__cdecl*)(void),CUtlMemory<void (__cdecl*)(void),int> > *v31; // eax
  HWND__ *m_hWnd; // [esp+1Ch] [ebp-5A4h]
  const char *gamma; // [esp+20h] [ebp-5A0h]
  char szText[32]; // [esp+2Ch] [ebp-594h] BYREF
  CFSSearchPathsInit initInfo; // [esp+220h] [ebp-3A0h] BYREF
  char psz[32]; // [esp+42Ch] [ebp-194h] BYREF
  char szGameDir[260]; // [esp+44Ch] [ebp-174h] BYREF
  _BYTE cmdInfo_12[44]; // [esp+55Ch] [ebp-64h] OVERLAPPED BYREF
  tagWNDCLASSA wndcls; // [esp+588h] [ebp-38h] BYREF
  CRect rcDesktop; // [esp+5B0h] [ebp-10h] BYREF

  if ( !this->m_bFoundryMode )
  {
    _LoggingSystem_PushLoggingState(a1: 0, a2: 1);
    _LoggingSystem_RegisterLoggingListener(a1: &s_SimpleWindowsLoggingListener);
    _LoggingSystem_RegisterLoggingListener(a1: &s_HammerMessageLoggingListener);
    MathLib_Init(
      gamma: 2.2,
      texGamma: 2.2,
      brightness: 0.0,
      overbright: 2,
      bAllow3DNow: false,
      bAllowSSE: false,
      bAllowSSE2: false,
      bAllowMMX: false);
  }
  if ( g_pCVar != nullptr )
    ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  CompatibleDC = CreateCompatibleDC(hdc: nullptr);
  v3 = CompatibleDC;
  if ( CompatibleDC != nullptr )
  {
    if ( GetDeviceCaps(hdc: CompatibleDC, index: 12) < 15 )
    {
      AfxMessageBox(lpszText: "Your screen must be in 16-bit color or higher to run Hammer.", nType: 0, nIDHelp: 0);
      return 0;
    }
    DeleteDC(hdc: v3);
  }
  memset(&cmdInfo_12[20], 0, 24);
  *(_QWORD *)&wndcls.style = 0;
  *(_DWORD *)&cmdInfo_12[12] = 11;
  *(_DWORD *)&cmdInfo_12[16] = AfxGetAfxWndProc();
  *(_DWORD *)&cmdInfo_12[28] = AfxGetModuleState()->m_hCurrentInstanceHandle;
  ModuleState = AfxGetModuleState();
  *(_DWORD *)&cmdInfo_12[32] = LoadIconW(hInstance: ModuleState->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)0x80);
  v6 = AfxGetModuleState();
  *(_DWORD *)&cmdInfo_12[36] = LoadCursorA(hInstance: v6->m_hCurrentResourceHandle, lpCursorName: (LPCSTR)0x7F00);
  wndcls.style = (unsigned int)"IDR_MAINFRAME";
  wndcls.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))"VALVEWORLDCRAFT";
  if ( AfxRegisterClass(lpWndClass: (tagWNDCLASSA *)&cmdInfo_12[12]) == 0 )
  {
    AfxMessageBox(lpszText: "Could not register Hammer's main window class", nType: 0, nIDHelp: 0);
    return 0;
  }
  v7 = _time64(timeptr: nullptr);
  srand(seed: v7);
  this->WriteProfileStringA(this, a2: "General", a3: "Directory", a4: this->m_szAppDir);
  CShellMessageWnd::Create(this: &g_ShellMessageWnd);
  CAutoSelComboBox::SetTextColor(this: (CAutoSelComboBox *)&g_ShellMessageWnd, dwColor: (unsigned int)&g_Shell);
  if ( bMakeLib )
    return 0;
  CHammerCmdLine::CHammerCmdLine(this: (CHammerCmdLine *)&szGameDir[228]);
  rcDesktop.bottom = 0;
  CWinApp::ParseCommandLine(this, rCmdInfo: (CCommandLineInfo *)&szGameDir[228]);
  CSplashWnd::EnableSplashScreen(bEnable: cmdInfo_12[0]);
  if ( CHammer::LoadSequences(this, szSeqFileName: "CmdSeq.wc") == 0 )
    CHammer::LoadSequences(this, szSeqFileName: "CmdSeqDefault.wc");
  randomize();
  CWinApp::LoadStdProfileSettings(this, nMaxMRU: 4u);
  v8 = (CMultiDocTemplate *)operator new(nSize: 0xB0u);
  v9 = (CHammerDocTemplate *)v8;
  rcDesktop.left = (int)v8;
  LOBYTE(rcDesktop.bottom) = 1;
  if ( v8 != nullptr )
  {
    CMultiDocTemplate::CMultiDocTemplate(
      this: v8,
      nIDResource: 0x81u,
      pDocClass: &CMapDoc::classCMapDoc,
      pFrameClass: &CChildFrame::classCChildFrame,
      pViewClass: &CMapView2D::classCMapView2D);
    v9->__vftable = (CHammerDocTemplate_vtbl *)&CHammerDocTemplate::`vftable';
    LOBYTE(rcDesktop.bottom) = 1;
  }
  else
  {
    v9 = nullptr;
  }
  LOBYTE(rcDesktop.bottom) = 0;
  this->pMapDocTemplate = v9;
  CWinApp::AddDocTemplate(this, pTemplate: v9);
  v10 = (CMultiDocTemplate *)operator new(nSize: 0xB0u);
  v11 = (CHammerDocTemplate *)v10;
  rcDesktop.left = (int)v10;
  LOBYTE(rcDesktop.bottom) = 3;
  if ( v10 != nullptr )
  {
    CMultiDocTemplate::CMultiDocTemplate(
      this: v10,
      nIDResource: 0x84u,
      pDocClass: &CManifest::classCManifest,
      pFrameClass: &CChildFrame::classCChildFrame,
      pViewClass: &CMapView2D::classCMapView2D);
    v11->__vftable = (CHammerDocTemplate_vtbl *)&CHammerDocTemplate::`vftable';
    LOBYTE(rcDesktop.bottom) = 3;
  }
  else
  {
    v11 = nullptr;
  }
  LOBYTE(rcDesktop.bottom) = 0;
  this->pManifestDocTemplate = v11;
  v12 = AfxGetModuleState();
  this->pManifestDocTemplate->m_hMenuShared = LoadMenuA(
                                                hInstance: v12->m_hCurrentResourceHandle,
                                                lpMenuName: (LPCSTR)0x81);
  v13 = AfxGetModuleState();
  this->pManifestDocTemplate->m_hAccelTable = LoadAcceleratorsA(
                                                hInstance: v13->m_hCurrentResourceHandle,
                                                lpTableName: (LPCSTR)0x81);
  CWinApp::AddDocTemplate(this, pTemplate: this->pManifestDocTemplate);
  CWinApp::RegisterShellFileTypes(this, bCompat: 0);
  AfxInitRichEdit();
  v14 = (CMainFrame *)operator new(nSize: 0x13E4u);
  *(_DWORD *)&cmdInfo_12[8] = v14;
  LOBYTE(rcDesktop.bottom) = 5;
  if ( v14 != nullptr )
  {
    v15 = CMainFrame::CMainFrame(this: v14);
    rcDesktop.left = (int)v15;
  }
  else
  {
    rcDesktop.left = 0;
    v15 = nullptr;
  }
  LOBYTE(rcDesktop.bottom) = 0;
  if ( v15->LoadFrame(this: v15, a2: 128u, a3: 13598720u, a4: nullptr, a5: nullptr) == 0 )
    goto LABEL_25;
  this->m_pMainWnd = v15;
  m_hWnd = v15->m_hWnd;
  v16 = HammerVGui();
  CHammerVGui::Init(this: v16, hWindow: m_hWnd);
  if ( this->m_bFoundryMode )
  {
    this->m_nCmdShow = 5;
    memset(&wndcls.cbClsExtra, 0, 16);
    DesktopWindow = GetDesktopWindow();
    GetWindowRect(hWnd: DesktopWindow, lpRect: (LPRECT)&wndcls.cbClsExtra);
    memset(&wndcls.hCursor, 0, 16);
    v18 = (HWND)enginetools->GetEngineHwnd(this: enginetools);
    GetWindowRect(hWnd: v18, lpRect: (LPRECT)&wndcls.hCursor);
    v19 = (char *)wndcls.hCursor + (char *)wndcls.hInstance - wndcls.lpszMenuName - wndcls.cbClsExtra;
    SetWindowPos(hWnd: v18, hWndInsertAfter: nullptr, X: (int)v19, Y: 0, cx: 0, cy: 0, uFlags: 0x45u);
    v20 = (char *)wndcls.hIcon - wndcls.cbWndExtra - 100;
    if ( (int)v19 < (int)v20 )
      v20 = v19;
    left = rcDesktop.left;
    CWnd::SetWindowPos(
      this: (CWnd *)rcDesktop.left,
      pWndInsertAfter: nullptr,
      x: 0,
      y: 0,
      cx: (int)v19,
      cy: (int)v20,
      nFlags: 0x44u);
    CWnd::SetWindowPos(
      this: *(CWnd **)(left + 280),
      pWndInsertAfter: nullptr,
      x: (int)v19,
      y: wndcls.lpszClassName - (const char *)wndcls.hbrBackground,
      cx: 0,
      cy: 0,
      nFlags: 0x45u);
    v15 = (CMainFrame *)left;
  }
  else
  {
    this->m_nCmdShow = 3;
    CWnd::ShowWindow(this: v15, nCmdShow: 3);
  }
  UpdateWindow(hWnd: v15->m_hWnd);
  if ( !this->m_bFoundryMode )
  {
    CFSSearchPathsInit::CFSSearchPathsInit(this: &initInfo);
    initInfo.m_pFileSystem = g_pFullFileSystem;
    initInfo.m_pDirectoryName = g_pGameConfig->m_szModDir;
    if ( g_pGameConfig->m_szModDir[0] == 0 )
    {
      p_m_pActiveWnd = &AfxGetModuleState()->m_pCurrentWinApp[1].m_pActiveWnd;
      v23 = (char *)(pTempBuf - (char *)p_m_pActiveWnd);
      do
      {
        v24 = *(_BYTE *)p_m_pActiveWnd;
        v23[(_DWORD)p_m_pActiveWnd] = *(_BYTE *)p_m_pActiveWnd;
        p_m_pActiveWnd = (CWnd **)((char *)p_m_pActiveWnd + 1);
      }
      while ( v24 != 0 );
      EnsureTrailingBackslash(psz: pTempBuf);
      strcat(pTempBuf, "..\\hl2");
      initInfo.m_pDirectoryName = pTempBuf;
    }
    CSplashWnd::ShowSplashScreen(pParentWnd: v15);
    if ( FileSystem_LoadSearchPaths((KeyValues *)&initInfo) != FS_OK )
      _Error(this: (ISceneTokenProcessor *)&stru_105DB7C8, a2: gamma);
    HammerFileSystem_ReportSearchPath(szPathID: "GAME");
  }
  CGameConfig::ParseGameInfo(this: g_pGameConfig);
  if ( !this->m_bFoundryMode )
    materials->ModInit(this: materials);
  if ( CTextureSystem::Initialize(this: &g_Textures, hwnd: this->m_pMainWnd->m_hWnd) )
  {
    CDmSerializerBinary::IsBinaryFormat(this: v25);
    CTextureSystem::LoadAllGraphicsFiles(this: &g_Textures);
    CTextureSystem::SetActiveConfig(this: &g_Textures, pConfig: g_pGameConfig);
  }
  else
  {
    Msg(type: mwError, fmt: "Failed to initialize texture system.");
  }
  CParticleSystemMgr::Init(this: g_pParticleSystemMgr, pQuery: nullptr, bAllowPrecache: true);
  CParticleSystemMgr::AddBuiltinSimulationOperators(this: g_pParticleSystemMgr);
  CParticleSystemMgr::AddBuiltinRenderingOperators(this: g_pParticleSystemMgr);
  InitStudioFileChangeWatcher();
  LoadFileSystemDialogModule();
  AfxGetModuleState();
  m_szModDir = g_pGameConfig->m_szModDir;
  v27 = psz - g_pGameConfig->m_szModDir;
  do
  {
    v28 = *m_szModDir;
    m_szModDir[v27] = *m_szModDir;
    ++m_szModDir;
  }
  while ( v28 != 0 );
  EnsureTrailingBackslash(psz);
  DetailObjects::LoadEmitDetailObjectDictionary();
  CSoundSystem::Initialize(this: &g_Sounds);
  UpdatePrefabs_Init();
  FlashWindow(hWnd: this->m_pMainWnd->m_hWnd, bInvert: true);
  if ( g_pEngineAPI != nullptr
    || V_stristr(pStr: *(const char **)&szGameDir[252], pSearch: ".vmf") == nullptr
    || CWinApp::ProcessShellCommand(this, rCmdInfo: (CCommandLineInfo *)&szGameDir[228]) != 0 )
  {
    if ( !this->m_bFoundryMode && Options.general.bClosedCorrectly == 0 )
    {
      v29 = AfxGetModuleState();
      v29->m_pCurrentWinApp->GetProfileStringA(
        this: v29->m_pCurrentWinApp,
        result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&rcDesktop,
        a3: "General",
        a4: "Last Good Save",
        a5: &var);
      LOBYTE(rcDesktop.bottom) = 6;
      if ( *(_DWORD *)(rcDesktop.left - 12) != 0 )
      {
        V_snprintf(
          pDest: szText,
          maxLen: 1024,
          pFormat: "Hammer did not shut down correctly the last time it was used.\n"
          "Would you like to load the last saved file?\n"
          "(%s)",
          (const char *)rcDesktop.left);
        if ( AfxMessageBox(lpszText: szText, nType: 4u, nIDHelp: 0) == 6 )
          CHammer::LoadLastGoodSave(this);
      }
      LOBYTE(rcDesktop.bottom) = 0;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::~CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&rcDesktop);
    }
    for ( i = 0;
          i < ReliableStaticStorage_CUtlVector_void____cdecl___void__CUtlMemory_void____cdecl___void__int____0_()->m_Size;
          ++i )
    {
      v31 = ReliableStaticStorage_CUtlVector_void____cdecl___void__CUtlMemory_void____cdecl___void__int____0_();
      v31->m_Memory.m_pMemory[i]();
    }
    WinTab_Open(hWnd: this->m_pMainWnd->m_hWnd);
    CSplashWnd::HideSplashScreen();
    g_LPreviewThread = (ThreadHandle_t__ *)_CreateSimpleThread(a1: LightingPreviewThreadFN, a2: 0, a3: 0);
    rcDesktop.bottom = -1;
    CHammerCmdLine::~CHammerCmdLine(this: (CHammerCmdLine *)&szGameDir[228]);
    return 1;
  }
  else
  {
LABEL_25:
    rcDesktop.bottom = -1;
    CHammerCmdLine::~CHammerCmdLine(this: (CHammerCmdLine *)&szGameDir[228]);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100440F0
// Name: public: virtual void CHammer::InitFoundryMode(void __near * (*)(char const __near *,int __near *),void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammer::InitFoundryMode(
        CHammer *this,
        void *(__cdecl *factory)(const char *, int *),
        void *hGameWnd,
        const char *szGameDir)
{
  int v5; // eax
  const char *v6; // [esp+0h] [ebp-8h]

  this->m_szAutosaveDir[76] = 1;
  v5 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-foundrymode") == 0 )
    _Error(this: (ISceneTokenProcessor *)&stru_105DB8B4, a2: v6);
  if ( ((int (__thiscall *)(CHammer *, void *(__cdecl *)(const char *, int *)))this->GetRuntimeClass)(
         a1: this,
         a2: factory) == 0 )
    _Error(this: (ISceneTokenProcessor *)&stru_105DB89C, a2: v6);
  if ( ((unsigned __int8 (__thiscall *)(CHammer *, const char *))this->GetInterfaceMap)(a1: this, a2: szGameDir) == 0 )
    _Error(this: (ISceneTokenProcessor *)&stru_105DB87C, a2: v6);
  if ( CHammer::HammerInternalInit(this: (CHammer *)((char *)this - 184)) != 1 )
    _Error(this: (ISceneTokenProcessor *)&stru_105DB860, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10044180
// Name: protected: static int CHammer::StaticHammerInternalInit(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CHammer::StaticHammerInternalInit(CHammer *pParam)
{
  return CHammer::HammerInternalInit(this: pParam);
}

//------------------------------------------------------------------------------
// Address: 0x10044190
// Name: public: virtual enum InitReturnVal_t CHammer::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CHammer::Init(CHammer *this)
{
  return WrapFunctionWithMinidumpHandler(
           pfn: (int (__cdecl *)(void *))CHammer::StaticHammerInternalInit,
           pParam: (char *)this - 184);
}

//------------------------------------------------------------------------------
// Address: 0x102BBB30
// Name: public: virtual void CBaseAppSystem<class IParticleSystemQuery>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IParticleSystemQuery>::Reconnect(
        CBaseAppSystem<IToolDictionary> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x1033926F
// Name: int ATL::AtlCrtErrorCheck(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ATL::AtlCrtErrorCheck(int nError)
{
  int result; // eax

  result = nError;
  if ( nError != 0 )
  {
    if ( nError == 12 )
      ATL::AtlThrowImpl(hr: -2147024882);
    if ( nError == 22 || nError == 34 )
      ATL::AtlThrowImpl(hr: -2147024809);
    if ( nError != 80 )
      ATL::AtlThrowImpl(hr: -2147467259);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103392A9
// Name: long ATL::AtlIAccessibleInvokeHelper(struct IAccessible __near *,long,struct _GUID const __near &,unsigned long,unsigned short,struct tagDISPPARAMS __near *,struct tagVARIANT __near *,struct tagEXCEPINFO __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::AtlIAccessibleInvokeHelper(
        IAccessible *pAccessible,
        int dispIdMember,
        const _GUID *__formal,
        unsigned int a4,
        int wFlags,
        tagDISPPARAMS *pDispParams,
        tagVARIANT *pVarResult,
        tagEXCEPINFO *a8,
        unsigned int *puArgErr)
{
  int v10; // edx
  tagDISPPARAMS *v12; // edi
  tagVARIANT *cArgs; // ecx
  tagVARIANT *rgvarg; // eax
  tagVARIANT *v15; // esi
  int v16; // eax
  char *v17; // ecx
  int *v18; // edx
  HRESULT v19; // esi
  int v20; // ecx
  int v21; // eax
  tagVARIANT *p_varg; // eax
  tagVARIANT *v23; // eax
  tagVARIANT *v24; // eax
  int v25; // edi
  tagVARIANT *v26; // esi
  unsigned __int16 vt; // ax
  int *plVal; // eax
  tagVARIANT *v29; // eax
  int v30; // eax
  tagVARIANT *v31; // esi
  unsigned __int16 v32; // ax
  unsigned int Lo32; // eax
  int v34; // eax
  tagVARIANT *v35; // eax
  bool v36; // zf
  tagVARIANT *v37; // eax
  int v38; // eax
  unsigned __int16 v39; // [esp-4h] [ebp-54h]
  _BYTE v40[4]; // [esp+8h] [ebp-48h] BYREF
  tagVARIANT *rgpParams[5]; // [esp+Ch] [ebp-44h]
  tagVARIANT vResult; // [esp+20h] [ebp-30h] BYREF
  int *pI4Params[4]; // [esp+30h] [ebp-20h]
  tagVARIANT varg; // [esp+40h] [ebp-10h] BYREF
  unsigned int i; // [esp+58h] [ebp+8h]

  v10 = 0;
  vResult.vt = 0;
  if ( pAccessible == nullptr )
    return -2147024809;
  v12 = pDispParams;
  if ( pDispParams == nullptr )
    return -2147352568;
  cArgs = (tagVARIANT *)pDispParams->cArgs;
  if ( (unsigned int)cArgs > 5 )
    return -2147352562;
  i = 0;
  if ( pDispParams->cNamedArgs != 0 )
  {
    pDispParams = (tagDISPPARAMS *)pDispParams->rgdispidNamedArgs;
    do
    {
      rgvarg = pDispParams->rgvarg;
      if ( pDispParams->rgvarg >= cArgs )
        return -2147352562;
      v15 = v12->rgvarg;
      pDispParams = (tagDISPPARAMS *)((char *)pDispParams + 4);
      ++i;
      rgpParams[(_DWORD)rgvarg] = &v15[v10++];
    }
    while ( i < v12->cNamedArgs );
  }
  if ( i < (unsigned int)cArgs )
  {
    v16 = (int)&v12->rgvarg[i];
    v17 = (char *)cArgs - i;
    v18 = (int *)&v40[4 * (_DWORD)v17];
    do
    {
      *v18 = v16;
      v16 += 16;
      --v18;
      --v17;
    }
    while ( v17 != nullptr );
  }
  v19 = -2147352573;
  if ( puArgErr == nullptr )
    puArgErr = (unsigned int *)&wFlags;
  if ( pVarResult == nullptr )
    pVarResult = &vResult;
  VariantInit(pvarg: &varg);
  LOBYTE(v20) = wFlags;
  switch ( dispIdMember )
  {
    case -5018:
      if ( v12->cArgs != 1 )
        goto LABEL_99;
      v21 = ((int (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int))pAccessible->accDoDefaultAction)(
              a1: pAccessible,
              a2: *(_DWORD *)rgpParams[0],
              a3: rgpParams[0]->decVal.Hi32,
              a4: rgpParams[0]->decVal.Lo32,
              a5: rgpParams[0]->decVal.Mid32);
      goto LABEL_97;
    case -5017:
      if ( v12->cArgs != 2 )
        goto LABEL_99;
      p_varg = rgpParams[0];
      if ( rgpParams[0]->vt != 3 )
      {
        v19 = VariantChangeType(pvargDest: &varg, pvarSrc: rgpParams[0], wFlags: 0, vt: 3u);
        if ( v19 < 0 )
          goto LABEL_61;
        p_varg = &varg;
      }
      wFlags = p_varg->lVal;
      v23 = rgpParams[1];
      if ( rgpParams[1]->vt != 3 )
      {
        v19 = VariantChangeType(pvargDest: &varg, pvarSrc: rgpParams[1], wFlags: 0, vt: 3u);
        if ( v19 < 0 )
          goto LABEL_94;
        v23 = &varg;
      }
      v21 = pAccessible->accHitTest(this: pAccessible, a2: wFlags, a3: v23->decVal.Lo32, a4: pVarResult);
      goto LABEL_97;
    case -5016:
      if ( v12->cArgs != 2 )
        goto LABEL_99;
      v24 = rgpParams[0];
      if ( rgpParams[0]->vt != 3 )
      {
        v19 = VariantChangeType(pvargDest: &varg, pvarSrc: rgpParams[0], wFlags: 0, vt: 3u);
        if ( v19 < 0 )
          goto LABEL_61;
        v24 = &varg;
      }
      v21 = ((int (__stdcall *)(IAccessible *, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, tagVARIANT *))pAccessible->accNavigate)(
              a1: pAccessible,
              a2: v24->decVal.Lo32,
              a3: *(_DWORD *)rgpParams[1],
              a4: rgpParams[1]->decVal.Hi32,
              a5: rgpParams[1]->decVal.Lo32,
              a6: rgpParams[1]->decVal.Mid32,
              a7: pVarResult);
      goto LABEL_97;
    case -5015:
      if ( v12->cArgs != 5 )
        goto LABEL_99;
      v25 = 0;
      while ( 1 )
      {
        v26 = rgpParams[v25];
        vt = v26->vt;
        if ( (v26->vt & 0x4000) == 0 || (vt & 0xF) == 0 )
          break;
        if ( (vt & 0xC) != 0 )
        {
          VariantClear(pvarg: v26->pvarVal);
          *v26->bstrVal = 3;
          plVal = (int *)(v26->decVal.Lo32 + 8);
        }
        else
        {
          plVal = v26->plVal;
        }
        pI4Params[v25++] = plVal;
        if ( v25 >= 4 )
        {
          v21 = ((int (__stdcall *)(IAccessible *, int *, int *, int *, int *, _DWORD, unsigned int, unsigned int, unsigned int))pAccessible->accLocation)(
                  a1: pAccessible,
                  a2: pI4Params[0],
                  a3: pI4Params[1],
                  a4: pI4Params[2],
                  a5: pI4Params[3],
                  a6: *(_DWORD *)rgpParams[4],
                  a7: rgpParams[4]->decVal.Hi32,
                  a8: rgpParams[4]->decVal.Lo32,
                  a9: rgpParams[4]->decVal.Mid32);
          goto LABEL_97;
        }
      }
      v19 = -2147352571;
      *puArgErr = v25;
      goto LABEL_106;
    case -5014:
      if ( v12->cArgs != 2 )
        goto LABEL_99;
      v29 = rgpParams[0];
      if ( rgpParams[0]->vt != 3 )
      {
        v19 = VariantChangeType(pvargDest: &varg, pvarSrc: rgpParams[0], wFlags: 0, vt: 3u);
        if ( v19 < 0 )
          goto LABEL_61;
        v29 = &varg;
      }
      v21 = ((int (__stdcall *)(IAccessible *, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int))pAccessible->accSelect)(
              a1: pAccessible,
              a2: v29->decVal.Lo32,
              a3: *(_DWORD *)rgpParams[1],
              a4: rgpParams[1]->decVal.Hi32,
              a5: rgpParams[1]->decVal.Lo32,
              a6: rgpParams[1]->decVal.Mid32);
      goto LABEL_97;
    case -5013:
      if ( v12->cArgs != 1 )
        goto LABEL_99;
      v30 = ((int (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, __int16 *))pAccessible->get_accDefaultAction)(
              a1: pAccessible,
              a2: *(_DWORD *)rgpParams[0],
              a3: rgpParams[0]->decVal.Hi32,
              a4: rgpParams[0]->decVal.Lo32,
              a5: rgpParams[0]->decVal.Mid32,
              a6: &pVarResult->boolVal);
      goto LABEL_51;
    case -5012:
      v21 = ((int (__fastcall *)(int, int, IAccessible *, tagVARIANT *))pAccessible->get_accSelection)(
              a1: v20,
              a2: 2,
              a3: pAccessible,
              a4: pVarResult);
      goto LABEL_97;
    case -5011:
      v21 = ((int (__fastcall *)(int, int, IAccessible *, tagVARIANT *))pAccessible->get_accFocus)(
              a1: v20,
              a2: 2,
              a3: pAccessible,
              a4: pVarResult);
      goto LABEL_97;
    case -5010:
      if ( v12->cArgs != 1 )
        goto LABEL_99;
      v30 = ((int (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, __int16 *))pAccessible->get_accKeyboardShortcut)(
              a1: pAccessible,
              a2: *(_DWORD *)rgpParams[0],
              a3: rgpParams[0]->decVal.Hi32,
              a4: rgpParams[0]->decVal.Lo32,
              a5: rgpParams[0]->decVal.Mid32,
              a6: &pVarResult->boolVal);
      goto LABEL_51;
    case -5009:
      if ( v12->cArgs != 2 )
        goto LABEL_99;
      v31 = rgpParams[0];
      v32 = rgpParams[0]->vt;
      if ( (rgpParams[0]->vt & 0x4000) == 0 || (v32 & 0xC) != 0 )
      {
        if ( v32 == 16396 )
        {
          VariantClear(pvarg: rgpParams[0]->pvarVal);
          *v31->bstrVal = 8;
          Lo32 = v31->decVal.Lo32 + 8;
        }
        else if ( v32 == 16392 )
        {
          Lo32 = rgpParams[0]->decVal.Lo32;
        }
        else
        {
          VariantClear(pvarg: rgpParams[0]);
          Lo32 = (unsigned int)&v31->decVal.$9BBF5D2FD0C92DEB81BE0D23DDBEB39C::$E2F13C0D8C7A5E44CBEA2DDC2BADB614::__s0;
          v31->vt = 8;
        }
        v34 = ((int (__stdcall *)(IAccessible *, unsigned int, _DWORD, unsigned int, unsigned int, unsigned int, __int16 *))pAccessible->get_accHelpTopic)(
                a1: pAccessible,
                a2: Lo32,
                a3: *(_DWORD *)rgpParams[1],
                a4: rgpParams[1]->decVal.Hi32,
                a5: rgpParams[1]->decVal.Lo32,
                a6: rgpParams[1]->decVal.Mid32,
                a7: &pVarResult->boolVal);
LABEL_68:
        v19 = v34;
        if ( v34 >= 0 )
        {
          v39 = 3;
          goto LABEL_105;
        }
      }
      else
      {
        v19 = -2147352571;
LABEL_61:
        *puArgErr = 0;
      }
      goto LABEL_106;
    case -5008:
      if ( v12->cArgs != 1 )
        goto LABEL_99;
      v30 = ((int (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, __int16 *))pAccessible->get_accHelp)(
              a1: pAccessible,
              a2: *(_DWORD *)rgpParams[0],
              a3: rgpParams[0]->decVal.Hi32,
              a4: rgpParams[0]->decVal.Lo32,
              a5: rgpParams[0]->decVal.Mid32,
              a6: &pVarResult->boolVal);
      goto LABEL_51;
    case -5007:
      if ( v12->cArgs != 1 )
        goto LABEL_99;
      v21 = ((int (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, tagVARIANT *))pAccessible->get_accState)(
              a1: pAccessible,
              a2: *(_DWORD *)rgpParams[0],
              a3: rgpParams[0]->decVal.Hi32,
              a4: rgpParams[0]->decVal.Lo32,
              a5: rgpParams[0]->decVal.Mid32,
              a6: pVarResult);
      goto LABEL_97;
    case -5006:
      if ( v12->cArgs != 1 )
        goto LABEL_99;
      v21 = ((int (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, tagVARIANT *))pAccessible->get_accRole)(
              a1: pAccessible,
              a2: *(_DWORD *)rgpParams[0],
              a3: rgpParams[0]->decVal.Hi32,
              a4: rgpParams[0]->decVal.Lo32,
              a5: rgpParams[0]->decVal.Mid32,
              a6: pVarResult);
      goto LABEL_97;
    case -5005:
      if ( v12->cArgs != 1 )
        goto LABEL_99;
      v30 = ((int (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, __int16 *))pAccessible->get_accDescription)(
              a1: pAccessible,
              a2: *(_DWORD *)rgpParams[0],
              a3: rgpParams[0]->decVal.Hi32,
              a4: rgpParams[0]->decVal.Lo32,
              a5: rgpParams[0]->decVal.Mid32,
              a6: &pVarResult->boolVal);
      goto LABEL_51;
    case -5004:
      if ( (wFlags & 2) != 0 )
      {
        if ( v12->cArgs == 1 )
        {
          v30 = ((int (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, __int16 *))pAccessible->get_accValue)(
                  a1: pAccessible,
                  a2: *(_DWORD *)rgpParams[0],
                  a3: rgpParams[0]->decVal.Hi32,
                  a4: rgpParams[0]->decVal.Lo32,
                  a5: rgpParams[0]->decVal.Mid32,
                  a6: &pVarResult->boolVal);
LABEL_51:
          v19 = v30;
          if ( v30 < 0 )
            goto LABEL_106;
          v39 = 8;
LABEL_105:
          pVarResult->vt = v39;
          goto LABEL_106;
        }
        goto LABEL_99;
      }
      if ( (wFlags & 4) == 0 )
      {
$LN21_13:
        if ( (wFlags & 2) != 0 )
        {
          if ( v12->cArgs == 1 )
          {
            v30 = ((int (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, __int16 *))pAccessible->get_accName)(
                    a1: pAccessible,
                    a2: *(_DWORD *)rgpParams[0],
                    a3: rgpParams[0]->decVal.Hi32,
                    a4: rgpParams[0]->decVal.Lo32,
                    a5: rgpParams[0]->decVal.Mid32,
                    a6: &pVarResult->boolVal);
            goto LABEL_51;
          }
          goto LABEL_99;
        }
        if ( (wFlags & 4) != 0 )
        {
          if ( v12->cArgs == 2 )
          {
            v37 = rgpParams[1];
            v36 = rgpParams[1]->vt == 8;
            *(tagVARIANT *)pI4Params = *rgpParams[0];
            if ( !v36 )
            {
              v19 = VariantChangeType(pvargDest: &varg, pvarSrc: rgpParams[1], wFlags: 0, vt: 3u);
              if ( v19 < 0 )
                goto LABEL_94;
              v37 = &varg;
            }
            v21 = ((int (__stdcall *)(IAccessible *, int *, int *, int *, int *, unsigned int))pAccessible->put_accName)(
                    a1: pAccessible,
                    a2: pI4Params[0],
                    a3: pI4Params[1],
                    a4: pI4Params[2],
                    a5: pI4Params[3],
                    a6: v37->decVal.Lo32);
LABEL_97:
            v19 = v21;
            goto LABEL_106;
          }
        }
        else
        {
$LN12_41:
          if ( v12->cArgs == 1 )
          {
            v38 = ((int (__stdcall *)(IAccessible *, _DWORD, unsigned int, unsigned int, unsigned int, __int16 *))pAccessible->get_accChild)(
                    a1: pAccessible,
                    a2: *(_DWORD *)rgpParams[0],
                    a3: rgpParams[0]->decVal.Hi32,
                    a4: rgpParams[0]->decVal.Lo32,
                    a5: rgpParams[0]->decVal.Mid32,
                    a6: &pVarResult->boolVal);
LABEL_103:
            v19 = v38;
            if ( v38 < 0 )
              goto LABEL_106;
            v39 = 9;
            goto LABEL_105;
          }
        }
LABEL_99:
        v19 = -2147352562;
        goto LABEL_106;
      }
      if ( v12->cArgs != 2 )
        goto LABEL_99;
      v35 = rgpParams[1];
      v36 = rgpParams[1]->vt == 8;
      *(tagVARIANT *)pI4Params = *rgpParams[0];
      if ( v36 )
      {
LABEL_86:
        v21 = ((int (__stdcall *)(IAccessible *, int *, int *, int *, int *, unsigned int))pAccessible->put_accValue)(
                a1: pAccessible,
                a2: pI4Params[0],
                a3: pI4Params[1],
                a4: pI4Params[2],
                a5: pI4Params[3],
                a6: v35->decVal.Lo32);
        goto LABEL_97;
      }
      v19 = VariantChangeType(pvargDest: &varg, pvarSrc: rgpParams[1], wFlags: 0, vt: 3u);
      if ( v19 >= 0 )
      {
        v35 = &varg;
        goto LABEL_86;
      }
LABEL_94:
      *puArgErr = 1;
LABEL_106:
      VariantClear(pvarg: &varg);
      return v19;
    case -5003:
      goto $LN21_13;
    case -5002:
      goto $LN12_41;
    case -5001:
      v34 = pAccessible->get_accChildCount(this: pAccessible, a2: (int *)&pVarResult->boolVal);
      goto LABEL_68;
    case -5000:
      v38 = pAccessible->get_accParent(this: pAccessible, a2: (IDispatch **)&pVarResult->boolVal);
      goto LABEL_103;
    default:
      goto LABEL_106;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10339885
// Name: long ATL::AtlIAccessibleGetIDsOfNamesHelper(struct _GUID const __near &,wchar_t __near * __near *,unsigned int,unsigned long,long __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::AtlIAccessibleGetIDsOfNamesHelper(
        const _GUID *__formal,
        wchar_t **rgszNames,
        unsigned int cNames,
        unsigned int a4,
        char *rgDispId)
{
  char *v5; // edi
  int v6; // ebx
  unsigned int j; // esi
  unsigned int i; // [esp+Ch] [ebp-4h]
  char bFoundIt_3; // [esp+2Bh] [ebp+1Bh]

  i = 0;
  if ( cNames == 0 )
    return 0;
  v5 = rgDispId;
  v6 = (char *)rgszNames - rgDispId;
  while ( 1 )
  {
    bFoundIt_3 = 0;
    for ( j = 0; j < 19; ++j )
    {
      if ( lstrcmpW(lpString1: *(LPCWSTR *)&v5[v6], lpString2: `ATL::AtlIAccessibleGetIDsOfNamesHelper'::`2'::names[j]) == 0 )
      {
        bFoundIt_3 = 1;
        *(_DWORD *)v5 = `ATL::AtlIAccessibleGetIDsOfNamesHelper'::`2'::dids[j];
      }
    }
    if ( bFoundIt_3 == 0 )
      break;
    ++i;
    v5 += 4;
    if ( i >= cNames )
      return 0;
  }
  return -2147352570;
}

//------------------------------------------------------------------------------
// Address: 0x1033D9C0
// Name: int ATL::InlineIsEqualUnknown(struct _GUID const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __stdcall ATL::InlineIsEqualUnknown(const _GUID *rguid1)
{
  return rguid1->Data1 == 0
      && *(_DWORD *)&rguid1->Data2 == 0
      && *(_DWORD *)rguid1->Data4 == 192
      && *(_DWORD *)&rguid1->Data4[4] == 1174405120;
}

//------------------------------------------------------------------------------
// Address: 0x1033D9F0
// Name: long ATL::AtlInternalQueryInterface(void __near *,struct ATL::_ATL_INTMAP_ENTRY const __near *,struct _GUID const __near &,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall ATL::AtlInternalQueryInterface(
        char *pThis,
        const ATL::_ATL_INTMAP_ENTRY *pEntries,
        const _GUID *iid,
        void **ppvObject)
{
  const ATL::_ATL_INTMAP_ENTRY *v4; // esi
  HRESULT result; // eax
  char *v6; // esi
  HRESULT (__stdcall *pFunc)(void *, const _GUID *, void **, unsigned int); // edi
  BOOL bBlind; // [esp+18h] [ebp+Ch]

  if ( pThis == nullptr )
    return -2147024809;
  v4 = pEntries;
  if ( pEntries == nullptr )
    return -2147024809;
  if ( ppvObject == nullptr )
    return -2147467261;
  *ppvObject = nullptr;
  if ( ATL::InlineIsEqualUnknown(rguid1: iid) )
  {
LABEL_6:
    v6 = &pThis[v4->dw];
    (*(void (__stdcall **)(char *))(*(_DWORD *)v6 + 4))(a1: v6);
    *ppvObject = v6;
    return 0;
  }
  else
  {
    while ( 1 )
    {
      pFunc = v4->pFunc;
      if ( pFunc == nullptr )
        return -2147467262;
      bBlind = v4->piid == nullptr;
      if ( v4->piid == nullptr || InlineIsEqualGUID(rguid1: v4->piid, rguid2: iid) != 0 )
      {
        if ( pFunc == (HRESULT (__stdcall *)(void *, const _GUID *, void **, unsigned int))1 )
          goto LABEL_6;
        result = pFunc(a1: pThis, a2: iid, a3: ppvObject, a4: v4->dw);
        if ( result == 0 || !bBlind && result < 0 )
          return result;
      }
      ++v4;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103404B0
// Name: public: void CFrameWnd::InitialUpdateFrame(class CDocument __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::InitialUpdateFrame(CFrameWnd *this, CDocument *pDoc, int bMakeVisible)
{
  CView *v4; // edi
  CWnd *DescendantWindow; // eax
  CView *v6; // ebx
  int m_nCmdShow; // ebx
  CWinApp *m_pCurrentWinApp; // eax

  v4 = nullptr;
  if ( this->m_pViewActive == nullptr )
  {
    DescendantWindow = CWnd::GetDescendantWindow(hWnd: this->m_hWnd, nID: 59648, bOnlyPerm: 1);
    v6 = (CView *)DescendantWindow;
    if ( DescendantWindow != nullptr && CObject::IsKindOf(this: DescendantWindow, pClass: &CView::classCView) != 0 )
    {
      v4 = v6;
      CFrameWnd::SetActiveView(this, pViewNew: v6, bNotify: 0);
    }
  }
  if ( bMakeVisible != 0 )
  {
    CWnd::SendMessageToDescendants(hWnd: this->m_hWnd, message: 0x364u, wParam: 0, lParam: 0, bDeep: 1, bOnlyPerm: 1);
    if ( v4 != nullptr )
      v4->OnActivateFrame(this: v4, a2: 0, a3: this);
    m_nCmdShow = -1;
    m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
    if ( m_pCurrentWinApp != nullptr && m_pCurrentWinApp->m_pMainWnd == this )
    {
      m_nCmdShow = m_pCurrentWinApp->m_nCmdShow;
      m_pCurrentWinApp->m_nCmdShow = -1;
    }
    this->ActivateFrame(this, a2: m_nCmdShow);
    if ( v4 != nullptr )
      v4->OnActivateView(this: v4, a2: 1, a3: v4, a4: v4);
  }
  if ( pDoc != nullptr )
    pDoc->UpdateFrameCounts(this: pDoc);
  this->OnUpdateFrameTitle(this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10344C55
// Name: long ATL::AtlMultiply<unsigned long>(unsigned long __near *,unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
HRESULT __cdecl ATL::AtlMultiply<unsigned long>(unsigned int *piResult, unsigned int iLeft, unsigned int iRight)
{
  if ( !is_mul_ok(iRight, iLeft) )
    return -2147024362;
  *piResult = iRight * iLeft;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10344C79
// Name: void __near * ATL::AtlCoTaskMemCAlloc(unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
LPVOID __cdecl ATL::AtlCoTaskMemCAlloc(unsigned int nCount, unsigned int nSize)
{
  unsigned int nBytes; // [esp+0h] [ebp-4h] BYREF

  nBytes = 0;
  if ( ATL::AtlMultiply<unsigned long>(piResult: &nBytes, iLeft: nCount, iRight: nSize) >= 0 )
    return CoTaskMemAlloc(cb: nBytes);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10344D2F
// Name: long ATL::AtlAdd<unsigned long>(unsigned long __near *,unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
HRESULT __cdecl ATL::AtlAdd<unsigned long>(unsigned int *ptResult, unsigned int tLeft, unsigned int tRight)
{
  if ( -1 - tLeft < tRight )
    return -2147024362;
  *ptResult = tRight + tLeft;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10344F85
// Name: unsigned long ATL::AtlAddThrow<unsigned long>(unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl ATL::AtlAddThrow<unsigned long>(unsigned int tLeft, unsigned int tRight)
{
  HRESULT v2; // eax
  unsigned int tResult; // [esp+0h] [ebp-4h] BYREF

  v2 = ATL::AtlAdd<unsigned long>(ptResult: &tResult, tLeft, tRight);
  if ( v2 < 0 )
    ATL::AtlThrowImpl(hr: v2);
  return tResult;
}

//------------------------------------------------------------------------------
// Address: 0x10345969
// Name: public: virtual void CWinThread::Delete(void)
// Source: rtti_class
//------------------------------------------------------------------------------
void __thiscall CWinThread::Delete(CWinThread *this)
{
  if ( this->m_bAutoDelete != 0 )
    ((void (__thiscall *)(CWinThread *, int))this->dtr_CObject)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10345A0B
// Name: public: virtual int CWinThread::ExitInstance(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinThread::ExitInstance(CWinThread *this)
{
  return AfxGetThreadState()->m_msgCur.wParam;
}

//------------------------------------------------------------------------------
// Address: 0x10345C3F
// Name: public: virtual int CWinThread::IsIdleMessage(struct tagMSG __near *)
// Source: rtti_class
//------------------------------------------------------------------------------
int __thiscall CWinThread::IsIdleMessage(CWinThread *this, tagMSG *pMsg)
{
  return AfxInternalIsIdleMessage(pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10345C51
// Name: public: virtual int CWinThread::PreTranslateMessage(struct tagMSG __near *)
// Source: rtti_class
//------------------------------------------------------------------------------
int __thiscall CWinThread::PreTranslateMessage(CWinThread *this, tagMSG *pMsg)
{
  return AfxInternalPreTranslateMessage(pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10345D3E
// Name: public: virtual int CWinThread::ProcessMessageFilter(int,struct tagMSG __near *)
// Source: rtti_class
//------------------------------------------------------------------------------
int __thiscall CWinThread::ProcessMessageFilter(CWinThread *this, int code, tagMSG *lpMsg)
{
  CWnd *v4; // eax
  CFrameWnd *TopLevelFrame; // eax
  CFrameWnd *v6; // edi
  CWnd *MainWnd; // edi
  unsigned int message; // eax
  CNoTrackObject *Data; // eax
  CNoTrackObject *v10; // ebx
  tagMSG msg; // [esp+8h] [ebp-20h] BYREF
  CWinThread *v12; // [esp+24h] [ebp-4h]

  v12 = this;
  if ( lpMsg == nullptr )
    return 0;
  if ( code != 0 )
  {
    if ( code != 2 )
      return 0;
    v4 = CWnd::FromHandle(hWnd: lpMsg->hwnd);
    if ( v4 != nullptr )
    {
      TopLevelFrame = CWnd::GetTopLevelFrame(this: v4);
      v6 = TopLevelFrame;
      if ( TopLevelFrame != nullptr && CFrameWnd::IsTracking(this: TopLevelFrame) != 0 && v6->m_bHelpMode != 0 )
      {
        MainWnd = AfxGetMainWnd();
        if ( v12->m_pMainWnd != nullptr && (IsEnterKey(lpMsg) != 0 || lpMsg->message == 514) )
        {
          SendMessageA(hWnd: MainWnd->m_hWnd, Msg: 0x111u, wParam: 0xE146u, lParam: 0);
          return 1;
        }
      }
    }
  }
  AfxGetMainWnd();
  if ( code == 0 && v12->m_pActiveWnd != nullptr )
  {
    message = lpMsg->message;
    if ( message >= 0x100 && message <= 0x109 )
    {
      Data = CThreadLocalObject::GetData(
               this: &_afxThreadState,
               pfnCreateObject: CThreadLocal<_AFX_THREAD_STATE>::CreateObject);
      v10 = Data;
      if ( Data == nullptr )
        AfxThrowInvalidArgException();
      if ( Data[56].__vftable == nullptr )
      {
        Data[56].__vftable = (CNoTrackObject_vtbl *)1;
        msg = *lpMsg;
        if ( CWnd::IsWindowEnabled(this: v12->m_pActiveWnd) != 0 && v12->PreTranslateMessage(this: v12, a2: &msg) != 0 )
        {
          v10[56].__vftable = nullptr;
          return 1;
        }
        v10[56].__vftable = nullptr;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10345E70
// Name: public: virtual int CWinThread::PumpMessage(void)
// Source: rtti_class
//------------------------------------------------------------------------------
// attributes: thunk
int __thiscall CWinThread::PumpMessage(CWinThread *this)
{
  return AfxInternalPumpMessage();
}

//------------------------------------------------------------------------------
// Address: 0x10345FA4
// Name: protected: void CWinApp::RegisterShellFileTypes(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::RegisterShellFileTypes(CWinApp *this, int bCompat)
{
  if ( this->m_pDocManager == nullptr )
    AfxThrowInvalidArgException();
  this->m_pDocManager->RegisterShellFileTypes(this: this->m_pDocManager, a2: bCompat);
}

//------------------------------------------------------------------------------
// Address: 0x10345FBD
// Name: public: struct __POSITION __near * CWinApp::GetFirstDocTemplatePosition(void)const
// Source: json
//------------------------------------------------------------------------------
__POSITION *__thiscall CWinApp::GetFirstDocTemplatePosition(CWinApp *this)
{
  if ( this->m_pDocManager != nullptr )
    return this->m_pDocManager->GetFirstDocTemplatePosition(this: this->m_pDocManager);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10345FCE
// Name: public: class CDocTemplate __near * CWinApp::GetNextDocTemplate(struct __POSITION __near * __near &)const
// Source: json
//------------------------------------------------------------------------------
CDocTemplate *__thiscall CWinApp::GetNextDocTemplate(CWinApp *this, __POSITION **rPosition)
{
  if ( this->m_pDocManager == nullptr )
    AfxThrowInvalidArgException();
  return this->m_pDocManager->GetNextDocTemplate(this: this->m_pDocManager, a2: rPosition);
}

//------------------------------------------------------------------------------
// Address: 0x10346094
// Name: public: int CWinApp::ProcessShellCommand(class CCommandLineInfo __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWinApp::ProcessShellCommand(CWinApp *this, CCommandLineInfo *rCmdInfo)
{
  CWinApp_vtbl *v3; // ebx
  int v4; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  CWinApp_vtbl *v6; // edx
  CWnd *m_pMainWnd; // eax
  CCommandLineInfo *m_nCmdShow; // eax
  int v9; // eax
  CCommandLineInfo *v10; // ecx
  CCommandLineInfo *v11; // eax
  int bResult; // [esp+10h] [ebp-10h]

  bResult = 1;
  switch ( rCmdInfo->m_nShellCommand )
  {
    case FileNew:
      goto $LN21_17;
    case FileOpen:
      return this->OpenDocumentFile(this, a2: rCmdInfo->m_strFileName.m_pszData) != nullptr;
    case FilePrint:
    case FilePrintTo:
      v6 = this->__vftable;
      this->m_nCmdShow = 0;
      if ( ((int (__stdcall *)(char *))v6->OpenDocumentFile)(a1: rCmdInfo->m_strFileName.m_pszData) != 0 )
      {
        m_pMainWnd = this->m_pMainWnd;
        this->m_pCmdInfo = rCmdInfo;
        if ( m_pMainWnd == nullptr )
          AfxThrowInvalidArgException();
        SendMessageA(hWnd: m_pMainWnd->m_hWnd, Msg: 0x111u, wParam: 0xE108u, lParam: 0);
        this->m_pCmdInfo = nullptr;
      }
      goto LABEL_6;
    case FileDDENoShow:
      m_nCmdShow = (CCommandLineInfo *)this->m_nCmdShow;
      this->m_nCmdShow = 0;
      this->m_pCmdInfo = m_nCmdShow;
      return bResult;
    case AppRegister:
      this->Register(this);
      bResult = 0;
      if ( this->m_pCmdInfo == nullptr )
        goto LABEL_20;
      return bResult;
    case AppUnregister:
      v9 = this->Unregister(this);
      if ( rCmdInfo->m_bRunEmbedded == 0 )
      {
        if ( v9 != 0 )
          AfxMessageBox(nIDPrompt: 0xF10Bu, nType: 0, nIDHelp: 0xFFFFFFFF);
        else
          AfxMessageBox(nIDPrompt: 0xF10Cu, nType: 0, nIDHelp: 0xFFFFFFFF);
      }
      bResult = 0;
      if ( this->m_pCmdInfo == nullptr )
      {
LABEL_20:
        v10 = (CCommandLineInfo *)operator new(nSize: 0x2Cu);
        if ( v10 != nullptr )
          v11 = CCommandLineInfo::CCommandLineInfo(this: v10);
        else
          v11 = nullptr;
        this->m_pCmdInfo = v11;
        v11->m_nShellCommand = AppUnregister;
      }
      break;
    case RestartByRestartManager:
      v3 = this->__vftable;
      v4 = ((int (__thiscall *)(CWinApp *, ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *))this->SupportsApplicationRecovery)(
             a1: this,
             a2: &rCmdInfo->m_strRestartIdentifier);
      ((void (__thiscall *)(CWinApp *, int))v3->RegisterWithRestartManager)(a1: this, a2: v4);
      if ( this->RestartInstance(this) == 0 )
      {
$LN21_17:
        ModuleState = AfxGetModuleState();
        if ( ModuleState->m_pCurrentWinApp->OnCmdMsg(
               this: ModuleState->m_pCurrentWinApp,
               a2: 57600u,
               a3: 0,
               a4: nullptr,
               a5: nullptr) == 0 )
          CWinApp::OnFileNew(this);
        if ( this->m_pMainWnd == nullptr )
LABEL_6:
          bResult = 0;
      }
      break;
    default:
      return bResult;
  }
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x10346244
// Name: public: void CWinApp::AddDocTemplate(class CDocTemplate __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::AddDocTemplate(CWinApp *this, CDocTemplate *pTemplate)
{
  CDocManager *v3; // ecx
  CDocManager *v4; // eax

  if ( this->m_pDocManager == nullptr )
  {
    v3 = (CDocManager *)operator new(nSize: 0x20u);
    if ( v3 != nullptr )
      v4 = CDocManager::CDocManager(this: v3);
    else
      v4 = nullptr;
    this->m_pDocManager = v4;
  }
  this->m_pDocManager->AddDocTemplate(this: this->m_pDocManager, a2: pTemplate);
}

//------------------------------------------------------------------------------
// Address: 0x1034645C
// Name: public: virtual int CWinApp::Unregister(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::Unregister(CWinApp *this)
{
  CDocTemplate *NextDocTemplate; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v3; // eax
  const char *m_pszProfileName; // [esp-10h] [ebp-150h]
  char *m_pszRegistryKey; // [esp-4h] [ebp-144h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v7; // [esp+10h] [ebp-130h] BYREF
  int cbData; // [esp+14h] [ebp-12Ch] BYREF
  __POSITION *rPosition; // [esp+18h] [ebp-128h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strKeyName; // [esp+1Ch] [ebp-124h] BYREF
  HKEY__ *phkResult; // [esp+20h] [ebp-120h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str1; // [esp+24h] [ebp-11Ch] BYREF
  CHAR Name[276]; // [esp+28h] [ebp-118h] BYREF
  int v14; // [esp+13Ch] [ebp-4h]

  phkResult = nullptr;
  cbData = 0;
  rPosition = CWinApp::GetFirstDocTemplatePosition(this);
  while ( rPosition != nullptr )
  {
    NextDocTemplate = CWinApp::GetNextDocTemplate(this, &rPosition);
    if ( NextDocTemplate != nullptr )
      NextDocTemplate->OnCmdMsg(this: NextDocTemplate, a2: 0, a3: -4, a4: nullptr, a5: nullptr);
  }
  if ( this->m_pszRegistryKey != nullptr )
  {
    if ( this->m_pszProfileName == nullptr )
      AfxThrowInvalidArgException();
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &str1,
      pszSrc: "Software\\");
    m_pszRegistryKey = (char *)this->m_pszRegistryKey;
    v14 = 0;
    ATL::CSimpleStringT<char,0>::Append(this: &str1, pszSrc: m_pszRegistryKey);
    v3 = ATL::operator+(a1: 0, a2: (int)this, result: &v7, &str1, psz2: "\\");
    m_pszProfileName = this->m_pszProfileName;
    LOBYTE(v14) = 1;
    ATL::operator+(a1: 0, a2: (int)this, result: &strKeyName, str1: v3, psz2: m_pszProfileName);
    LOBYTE(v14) = 3;
    ATL::CStringData::Release(this: (ATL::CStringData *)v7.m_pszData - 1);
    AfxDelRegTreeHelper(hParentKey: (HKEY__ *)0x80000001, &strKeyName, pTM: nullptr);
    if ( RegOpenKeyExA(hKey: HKEY_CURRENT_USER, lpSubKey: str1.m_pszData, ulOptions: 0, samDesired: 8u, &phkResult) == 0 )
    {
      if ( RegEnumKeyA(hKey: phkResult, dwIndex: 0, lpName: Name, cchName: 0x104u) == 259 )
        AfxDelRegTreeHelper(hParentKey: (HKEY__ *)0x80000001, strKeyName: &str1, pTM: nullptr);
      RegCloseKey(hKey: phkResult);
    }
    RegQueryValueA(hKey: HKEY_CURRENT_USER, lpSubKey: strKeyName.m_pszData, lpData: Name, lpcbData: &cbData);
    ATL::CStringData::Release(this: (ATL::CStringData *)strKeyName.m_pszData - 1);
    ATL::CStringData::Release(this: (ATL::CStringData *)str1.m_pszData - 1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10346961
// Name: struct IUnknown __near * ATL::AtlComPtrAssign(struct IUnknown __near * __near *,struct IUnknown __near *)
// Source: json
//------------------------------------------------------------------------------
IUnknown *__stdcall ATL::AtlComPtrAssign(IUnknown **pp, IUnknown *lp)
{
  if ( pp == nullptr )
    return nullptr;
  if ( lp != nullptr )
    lp->AddRef(this: lp);
  if ( *pp != nullptr )
    (*pp)->Release(this: *pp);
  *pp = lp;
  return lp;
}

//------------------------------------------------------------------------------
// Address: 0x103485AB
// Name: public: virtual int CStatic::Create(char const __near *,unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CStatic::Create(
        CStatic *this,
        const char *lpszText,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  return this->Create(this, a2: "STATIC", a3: lpszText, a4: dwStyle, a5: rect, a6: pParentWnd, a7: nID, a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103485CF
// Name: public: virtual CStatic::~CStatic(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CStatic::~CStatic(CStatic *this)
{
  this->__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::DestroyWindow(this);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x10348600
// Name: protected: virtual int CButton::OnChildNotify(unsigned int,unsigned int,long,long __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CButton::OnChildNotify(
        CButton *this,
        unsigned int message,
        unsigned int wParam,
        tagDRAWITEMSTRUCT *lParam,
        int *pResult)
{
  if ( message != 43 )
    return CWnd::OnChildNotify(this, uMsg: message, wParam, (int)lParam, pResult);
  this->DrawItem(this, a2: lParam);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10348623
// Name: public: virtual int CButton::Create(char const __near *,unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CButton::Create(
        CButton *this,
        const char *lpszCaption,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  return this->Create(this, a2: "BUTTON", a3: lpszCaption, a4: dwStyle, a5: rect, a6: pParentWnd, a7: nID, a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10348647
// Name: public: virtual CButton::~CButton(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CButton::~CButton(CButton *this)
{
  this->__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::DestroyWindow(this);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x103488EE
// Name: public: virtual struct CRuntimeClass __near * CStatic::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CStatic::GetRuntimeClass(CStatic *this)
{
  return &CStatic::classCStatic;
}

//------------------------------------------------------------------------------
// Address: 0x103488F4
// Name: public: virtual struct CRuntimeClass __near * CButton::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CButton::GetRuntimeClass(CButton *this)
{
  return &CButton::classCButton;
}

//------------------------------------------------------------------------------
// Address: 0x10349672
// Name: struct ATL::IAtlStringMgr __near * AfxGetStringManager(void)
// Source: json
//------------------------------------------------------------------------------
CAfxStringMgr *__stdcall AfxGetStringManager()
{
  return &afxStringManager;
}

//------------------------------------------------------------------------------
// Address: 0x10349739
// Name: unsigned int ATL::AtlMultiplyThrow<unsigned int>(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl ATL::AtlMultiplyThrow<unsigned int>(unsigned int tLeft, unsigned int tRight)
{
  HRESULT v2; // eax
  unsigned int tResult; // [esp+0h] [ebp-4h] BYREF

  v2 = ATL::AtlMultiply<unsigned long>(piResult: &tResult, iLeft: tLeft, iRight: tRight);
  if ( v2 < 0 )
    ATL::AtlThrowImpl(hr: v2);
  return tResult;
}

//------------------------------------------------------------------------------
// Address: 0x10349B53
// Name: public: static void CWinApp::DoEnableModeless(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CWinApp::DoEnableModeless(int bEnable)
{
  CWnd *MainWnd; // esi

  MainWnd = AfxGetMainWnd();
  if ( MainWnd != nullptr && MainWnd->IsFrameWnd(this: MainWnd) != 0 && MainWnd[1].m_pProxy != nullptr )
    ((void (__thiscall *)(IAccessibleProxy *, int))MainWnd[1].m_pProxy->__vftable[6].AddRef)(
      a1: MainWnd[1].m_pProxy,
      a2: bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x10349C2E
// Name: public: void CWinApp::EnableModeless(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::EnableModeless(CWinApp *this, int bEnable)
{
  CWinApp::DoEnableModeless(bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x10349C40
// Name: public: static int CWinApp::ShowAppMessageBox(class CWinApp __near *,char const __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CWinApp::ShowAppMessageBox(CWinApp *pApp, const char *lpszPrompt, UINT nType, unsigned int nIDPrompt)
{
  unsigned int *p_m_dwPromptContext; // esi
  HWND__ *SafeOwner; // eax
  HWND v6; // ebx
  LRESULT v7; // eax
  unsigned int v8; // eax
  const char *m_pszAppName; // ebx
  int v10; // edi
  HWND__ *hWnd; // [esp+10h] [ebp-118h]
  unsigned int dwWndPid; // [esp+14h] [ebp-114h] BYREF
  unsigned int dwOldPromptContext; // [esp+18h] [ebp-110h]
  HWND__ *hWndTop; // [esp+1Ch] [ebp-10Ch] BYREF
  char szAppName[260]; // [esp+20h] [ebp-108h] BYREF

  p_m_dwPromptContext = nullptr;
  CWinApp::DoEnableModeless(bEnable: 0);
  SafeOwner = CWnd::GetSafeOwner_(hParent: nullptr, pWndTop: &hWndTop);
  v6 = SafeOwner;
  hWnd = SafeOwner;
  if ( SafeOwner != hWndTop )
    EnableWindow(hWnd: SafeOwner, bEnable: true);
  dwWndPid = 0;
  GetWindowThreadProcessId(hWnd: v6, lpdwProcessId: &dwWndPid);
  if ( v6 != nullptr
    && dwWndPid == GetCurrentProcessId()
    && (v7 = SendMessageA(hWnd: v6, Msg: 0x376u, wParam: 0, lParam: 0)) != 0 )
  {
    p_m_dwPromptContext = (unsigned int *)v7;
  }
  else if ( pApp != nullptr )
  {
    p_m_dwPromptContext = &pApp->m_dwPromptContext;
  }
  dwOldPromptContext = 0;
  if ( p_m_dwPromptContext != nullptr )
  {
    dwOldPromptContext = *p_m_dwPromptContext;
    if ( nIDPrompt != 0 )
      *p_m_dwPromptContext = nIDPrompt + 196608;
  }
  if ( (nType & 0xF0) == 0 )
  {
    v8 = nType & 0xF;
    if ( v8 <= 1 )
    {
      nType |= 0x30u;
    }
    else if ( v8 - 3 <= 1 )
    {
      nType |= 0x20u;
    }
  }
  szAppName[0] = 0;
  if ( pApp != nullptr )
  {
    m_pszAppName = pApp->m_pszAppName;
  }
  else
  {
    m_pszAppName = szAppName;
    if ( GetModuleFileNameA(hModule: nullptr, lpFilename: szAppName, nSize: 0x104u) == 260 )
      szAppName[259] = 0;
  }
  v10 = AfxCtxMessageBoxA(hWnd, lpText: lpszPrompt, lpCaption: m_pszAppName, uType: nType);
  if ( p_m_dwPromptContext != nullptr )
    *p_m_dwPromptContext = dwOldPromptContext;
  if ( hWndTop != nullptr )
    EnableWindow(hWnd: hWndTop, bEnable: true);
  CWinApp::DoEnableModeless(bEnable: 1);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10349DD4
// Name: public: virtual int CWinApp::DoMessageBox(char const __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::DoMessageBox(CWinApp *this, const char *lpszPrompt, UINT nType, unsigned int nIDPrompt)
{
  return CWinApp::ShowAppMessageBox(pApp: this, lpszPrompt, nType, nIDPrompt);
}

//------------------------------------------------------------------------------
// Address: 0x1034C266
// Name: public: virtual class CDocument __near * CMultiDocTemplate::OpenDocumentFile(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CDocument *__thiscall CMultiDocTemplate::OpenDocumentFile(
        CMultiDocTemplate *this,
        const char *lpszPathName,
        int bMakeVisible)
{
  return this->OpenDocumentFile(this, a2: lpszPathName, a3: 1, a4: bMakeVisible);
}

//------------------------------------------------------------------------------
// Address: 0x1034C372
// Name: public: virtual class CDocument __near * CMultiDocTemplate::OpenDocumentFile(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
CDocument *__thiscall CMultiDocTemplate::OpenDocumentFile(
        CMultiDocTemplate *this,
        const char *lpszPathName,
        int bAddToMRU,
        int bMakeVisible)
{
  CDocument *v5; // eax
  CDocument *v6; // esi
  int m_bAutoDelete; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  int bAutoDelete; // [esp+10h] [ebp-14h]
  CFrameWnd *pFrame; // [esp+14h] [ebp-10h]

  v5 = this->CreateNewDocument(this);
  v6 = v5;
  if ( v5 == nullptr )
  {
    AfxMessageBox(nIDPrompt: 0xF104u, nType: 0, nIDHelp: 0xFFFFFFFF);
    return nullptr;
  }
  m_bAutoDelete = v5->m_bAutoDelete;
  v6->m_bAutoDelete = 0;
  bAutoDelete = m_bAutoDelete;
  pFrame = this->CreateNewFrame(this, a2: v6, a3: 0);
  v6->m_bAutoDelete = bAutoDelete;
  if ( pFrame == nullptr )
  {
    AfxMessageBox(nIDPrompt: 0xF104u, nType: 0, nIDHelp: 0xFFFFFFFF);
    ((void (__thiscall *)(CDocument *, int))v6->dtr_CObject)(a1: v6, a2: 1);
    return nullptr;
  }
  if ( lpszPathName != nullptr )
  {
    ModuleState = AfxGetModuleState();
    CCmdTarget::BeginWaitCursor(this: ModuleState->m_pCurrentWinApp);
    if ( v6->OnOpenDocument(this: v6, a2: lpszPathName) == 0 )
    {
      pFrame->DestroyWindow(this: pFrame);
      CWaitCursor::~CWaitCursor(this: (CWaitCursor *)&lpszPathName + 3);
      return nullptr;
    }
    v6->SetPathName(this: v6, a2: lpszPathName, a3: bAddToMRU);
    v6->OnDocumentEvent(this: v6, a2: onAfterOpenDocument);
    CWaitCursor::~CWaitCursor(this: (CWaitCursor *)&lpszPathName + 3);
  }
  else
  {
    this->SetDefaultTitle(this, a2: v6);
    if ( bMakeVisible == 0 )
      v6->m_bEmbedded = 1;
    if ( v6->OnNewDocument(this: v6) == 0 )
    {
      pFrame->DestroyWindow(this: pFrame);
      return nullptr;
    }
    ++this->m_nUntitledCount;
  }
  this->InitialUpdateFrame(this, a2: pFrame, a3: v6, a4: bMakeVisible);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1034C589
// Name: public: virtual void CDocTemplate::InitialUpdateFrame(class CFrameWnd __near *,class CDocument __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocTemplate::InitialUpdateFrame(
        CDocTemplate *this,
        CFrameWnd *pFrame,
        CDocument *pDoc,
        int bMakeVisible)
{
  CFrameWnd::InitialUpdateFrame(this: pFrame, pDoc, bMakeVisible);
}

//------------------------------------------------------------------------------
// Address: 0x1034C5DE
// Name: public: virtual void CDocTemplate::CloseAllDocuments(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocTemplate::CloseAllDocuments(CDocTemplate *this, int __formal)
{
  CDocument *v3; // eax
  __POSITION *pos; // [esp+4h] [ebp-4h] BYREF

  pos = this->GetFirstDocPosition(this);
  while ( pos != nullptr )
  {
    v3 = this->GetNextDoc(this, a2: &pos);
    v3->OnCloseDocument(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034CB44
// Name: protected: int CWinApp::_LoadSysPolicies(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::_LoadSysPolicies(CWinApp *this)
{
  _AfxSysPolicies *i; // ebx
  _AfxSysPolicyData *j; // esi
  unsigned int dwID; // ecx
  unsigned int dwDataLen; // [esp+8h] [ebp-14h] BYREF
  CWinApp *v6; // [esp+Ch] [ebp-10h]
  unsigned int dwType; // [esp+10h] [ebp-Ch] BYREF
  unsigned int dwValue; // [esp+14h] [ebp-8h] BYREF
  HKEY__ *hkPolicy; // [esp+18h] [ebp-4h] BYREF

  this->m_dwPolicies = 0;
  v6 = this;
  hkPolicy = nullptr;
  dwValue = 0;
  dwDataLen = 4;
  dwType = 0;
  for ( i = rgPolicies; i->szPolicyKey != nullptr; ++i )
  {
    if ( RegOpenKeyExA(
           hKey: HKEY_CURRENT_USER,
           lpSubKey: i->szPolicyKey,
           ulOptions: 0,
           samDesired: 1u,
           phkResult: &hkPolicy) == 0 )
    {
      for ( j = i->pData; j->szPolicyName != nullptr; ++j )
      {
        if ( RegQueryValueExA(
               hKey: hkPolicy,
               lpValueName: j->szPolicyName,
               lpReserved: nullptr,
               lpType: &dwType,
               lpData: (LPBYTE)&dwValue,
               lpcbData: &dwDataLen) == 0
          && dwType == 4 )
        {
          dwID = j->dwID;
          if ( dwValue != 0 )
            v6->m_dwPolicies |= dwID;
          else
            v6->m_dwPolicies &= ~dwID;
        }
        dwValue = 0;
        dwDataLen = 4;
        dwType = 0;
      }
      RegCloseKey(hKey: hkPolicy);
      hkPolicy = nullptr;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034CC09
// Name: public: int CWinApp::GetSysPolicyValue(unsigned long,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::GetSysPolicyValue(CWinApp *this, unsigned int dwPolicyID, int *pbValue)
{
  int result; // eax

  result = (int)pbValue;
  if ( pbValue != nullptr )
  {
    *pbValue = (dwPolicyID & this->m_dwPolicies) != 0;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034CC2D
// Name: public: virtual int CWinApp::InitApplication(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::InitApplication(CWinApp *this)
{
  CDocManager *m_pDocManager; // ecx

  if ( CDocManager::pStaticDocManager != nullptr )
  {
    if ( this->m_pDocManager == nullptr )
      this->m_pDocManager = CDocManager::pStaticDocManager;
    CDocManager::pStaticDocManager = nullptr;
  }
  m_pDocManager = this->m_pDocManager;
  if ( m_pDocManager != nullptr )
    m_pDocManager->AddDocTemplate(this: m_pDocManager, a2: nullptr);
  else
    CDocManager::bStaticInit = 0;
  this->LoadSysPolicies(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034CC6D
// Name: protected: void CWinApp::LoadStdProfileSettings(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::LoadStdProfileSettings(CWinApp *this, unsigned int nMaxMRU)
{
  CRecentFileList *v3; // ecx
  CRecentFileList *v4; // eax
  int bNoRecentDocs[3]; // [esp+10h] [ebp-10h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  bNoRecentDocs[0] = 0;
  CWinApp::GetSysPolicyValue(this, dwPolicyID: 0x20u, pbValue: bNoRecentDocs);
  if ( nMaxMRU != 0 && bNoRecentDocs[0] == 0 )
  {
    v3 = (CRecentFileList *)operator new(nSize: 0x20u);
    bNoRecentDocs[0] = (int)v3;
    v6 = 0;
    if ( v3 != nullptr )
      v4 = CRecentFileList::CRecentFileList(
             this: v3,
             nStart: 0,
             lpszSection: "Recent File List",
             lpszEntryFormat: "File%d",
             nSize: nMaxMRU,
             nMaxDispLen: 30);
    else
      v4 = nullptr;
    v6 = -1;
    this->m_pRecentFileList = v4;
    v4->ReadList(this: v4);
  }
  this->m_nNumPreviewPages = this->GetProfileIntA(this, a2: "Settings", a3: "PreviewPages", a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1034CCF3
// Name: public: void CWinApp::ParseCommandLine(class CCommandLineInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::ParseCommandLine(CWinApp *this, CCommandLineInfo *rCmdInfo)
{
  int v2; // eax
  char *v3; // ecx
  int v4; // esi
  int v5; // edx

  v2 = 1;
  if ( __argc > 1 )
  {
    do
    {
      v3 = __argv[v2];
      v4 = v2 + 1;
      v5 = 0;
      if ( *v3 == 45 || *v3 == 47 )
      {
        v5 = 1;
        ++v3;
      }
      rCmdInfo->ParseParam(this: rCmdInfo, a2: v3, a3: v5, a4: v4 == __argc);
      v2 = v4;
    }
    while ( v4 < __argc );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034CD4B
// Name: public: virtual int CWinApp::RestartInstance(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::RestartInstance(CWinApp *this)
{
  int v1; // edi
  CDataRecoveryHandler *v2; // esi

  v1 = 0;
  v2 = this->GetDataRecoveryHandler(this);
  if ( v2 != nullptr && v2->ReadOpenDocumentList(this: v2) != 0 )
  {
    v1 = v2->ReopenPreviousDocuments(this: v2);
    v2->RestoreAutosavedDocuments(this: v2);
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1034CD7D
// Name: protected: void CWinApp::SaveStdProfileSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::SaveStdProfileSettings(CWinApp *this)
{
  if ( this->m_pRecentFileList != nullptr )
    this->m_pRecentFileList->WriteList(this: this->m_pRecentFileList);
  if ( this->m_nNumPreviewPages != 0 )
    this->WriteProfileInt(this, a2: "Settings", a3: "PreviewPages", a4: this->m_nNumPreviewPages);
}

//------------------------------------------------------------------------------
// Address: 0x1034CDB9
// Name: public: virtual int CWinApp::ExitInstance(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::ExitInstance(CWinApp *this)
{
  CCommandLineInfo *m_pCmdInfo; // eax
  CCommandLineInfo::<unnamed_type_m_nShellCommand> m_nShellCommand; // eax
  void (*m_lpfnDaoTerm)(void); // eax
  int v5; // esi

  m_pCmdInfo = this->m_pCmdInfo;
  if ( (m_pCmdInfo == nullptr
     || (m_nShellCommand = m_pCmdInfo->m_nShellCommand) != AppUnregister && m_nShellCommand != AppRegister)
    && AfxGetModuleState()->m_bDLL == 0 )
  {
    CWinApp::SaveStdProfileSettings(this);
  }
  m_lpfnDaoTerm = this->m_lpfnDaoTerm;
  if ( m_lpfnDaoTerm != nullptr )
    m_lpfnDaoTerm();
  if ( this->m_hLangResourceDLL != nullptr )
  {
    FreeLibrary(hLibModule: this->m_hLangResourceDLL);
    this->m_hLangResourceDLL = nullptr;
  }
  v5 = 0;
  if ( AfxGetCurrentMessage() != nullptr )
    return AfxGetCurrentMessage()->wParam;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1034CE44
// Name: public: virtual long CWinApp::RegisterWithRestartManager(wchar_t const __near *,unsigned long,unsigned long (*)(void __near *),void __near *,unsigned long,unsigned long)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWinApp::RegisterWithRestartManager(
        CWinApp *this,
        const wchar_t *pwzCommandLineArgs,
        DWORD dwRestartFlags,
        unsigned int (__stdcall *pRecoveryCallback)(void *),
        void *lpvParam,
        DWORD dwPingInterval,
        DWORD dwCallbackFlags)
{
  HMODULE ModuleHandleW; // eax
  HMODULE v8; // edi
  HRESULT (__stdcall *RegisterApplicationRestart)(PCWSTR, DWORD); // ebx
  HRESULT (__stdcall *RegisterApplicationRecoveryCallback)(APPLICATION_RECOVERY_CALLBACK, PVOID, DWORD, DWORD); // eax
  HRESULT (__stdcall *v11)(APPLICATION_RECOVERY_CALLBACK, PVOID, DWORD, DWORD); // esi
  HRESULT result; // eax

  ModuleHandleW = GetModuleHandleW(lpModuleName: L"KERNEL32.DLL");
  v8 = ModuleHandleW;
  if ( ModuleHandleW == nullptr )
    AfxThrowInvalidArgException();
  RegisterApplicationRestart = (HRESULT (__stdcall *)(PCWSTR, DWORD))GetProcAddress(
                                                                       hModule: ModuleHandleW,
                                                                       lpProcName: "RegisterApplicationRestart");
  RegisterApplicationRecoveryCallback = (HRESULT (__stdcall *)(APPLICATION_RECOVERY_CALLBACK, PVOID, DWORD, DWORD))GetProcAddress(hModule: v8, lpProcName: "RegisterApplicationRecoveryCallback");
  v11 = RegisterApplicationRecoveryCallback;
  if ( RegisterApplicationRestart == nullptr )
    return 0;
  if ( RegisterApplicationRecoveryCallback == nullptr )
    return 0;
  result = RegisterApplicationRestart(pwzCommandline: pwzCommandLineArgs, dwFlags: dwRestartFlags);
  if ( result == 0 )
  {
    if ( pRecoveryCallback == nullptr )
      return 0;
    result = v11(pRecoveyCallback: pRecoveryCallback, pvParameter: lpvParam, dwPingInterval, dwFlags: dwCallbackFlags);
    if ( result == 0 )
      return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034CEB0
// Name: public: virtual unsigned long CWinApp::ApplicationRecoveryCallback(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CWinApp::ApplicationRecoveryCallback(CWinApp *this, void *__formal)
{
  HMODULE ModuleHandleW; // eax
  HMODULE v3; // edi
  HRESULT (__stdcall *ApplicationRecoveryInProgress)(PBOOL); // ebx
  void (__stdcall *ApplicationRecoveryFinished)(BOOL); // eax
  void (__stdcall *v6)(BOOL); // edi
  int v7; // esi
  CDataRecoveryHandler *v8; // eax
  int bRecoveryCanceled; // [esp+10h] [ebp-4h] BYREF

  ModuleHandleW = GetModuleHandleW(lpModuleName: L"KERNEL32.DLL");
  v3 = ModuleHandleW;
  if ( ModuleHandleW == nullptr )
    AfxThrowInvalidArgException();
  ApplicationRecoveryInProgress = (HRESULT (__stdcall *)(PBOOL))GetProcAddress(
                                                                  hModule: ModuleHandleW,
                                                                  lpProcName: "ApplicationRecoveryInProgress");
  ApplicationRecoveryFinished = (void (__stdcall *)(BOOL))GetProcAddress(
                                                            hModule: v3,
                                                            lpProcName: "ApplicationRecoveryFinished");
  v6 = ApplicationRecoveryFinished;
  if ( ApplicationRecoveryInProgress != nullptr && ApplicationRecoveryFinished != nullptr )
  {
    bRecoveryCanceled = 0;
    ApplicationRecoveryInProgress(pbCancelled: &bRecoveryCanceled);
    if ( bRecoveryCanceled == 0 )
    {
      v7 = 1;
      v8 = this->GetDataRecoveryHandler(this);
      if ( v8 != nullptr )
        v7 = v8->SaveOpenDocumentList(this: v8);
      v6(bSuccess: v7);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1034CF2C
// Name: public: virtual long CWinApp::ProcessWndProcException(class CException __near *,struct tagMSG const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::ProcessWndProcException(CWinApp *this, CException *e, const tagMSG *pMsg)
{
  int v3; // ebx
  int v4; // esi

  v3 = 0;
  if ( e == nullptr || pMsg == nullptr )
    AfxThrowInvalidArgException();
  if ( pMsg->message == 1 || pMsg->message == 15 )
    return CWinThread::ProcessWndProcException(this, e, pMsg);
  v4 = 61704;
  if ( pMsg->message == 273 )
  {
    if ( pMsg->lParam == 0 )
      v4 = 61705;
    v3 = 1;
  }
  if ( CObject::IsKindOf(this: e, pClass: &CMemoryException::classCMemoryException) != 0 )
  {
    ((void (__stdcall *)(int, int))e->ReportError)(a1: 4144, a2: v4);
  }
  else if ( CObject::IsKindOf(this: e, pClass: &CUserException::classCUserException) == 0 )
  {
    ((void (__stdcall *)(int, int))e->ReportError)(a1: 16, a2: v4);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1034CFAF
// Name: public: virtual int CWinApp::OnIdle(long)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWinApp::OnIdle(CWinApp *this, __POSITION *lCount)
{
  int v2; // ebx
  CDocTemplate *v4; // eax
  CDataRecoveryHandler *v5; // eax

  v2 = (int)lCount;
  if ( (int)lCount > 0 )
  {
    if ( lCount == (__POSITION *)1 )
      CWinThread::OnIdle(this, lCount: 1);
  }
  else
  {
    CWinThread::OnIdle(this, (int)lCount);
    lCount = nullptr;
    if ( this->m_pDocManager != nullptr )
    {
      lCount = this->m_pDocManager->GetFirstDocTemplatePosition(this: this->m_pDocManager);
      while ( lCount != nullptr )
      {
        v4 = this->m_pDocManager->GetNextDocTemplate(this: this->m_pDocManager, a2: &lCount);
        v4->OnIdle(this: v4);
      }
    }
    v5 = this->GetDataRecoveryHandler(this);
    if ( v5 != nullptr )
      v5->SetSaveDocumentInfoOnIdle(this: v5, a2: 0);
  }
  return v2 < 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034D02C
// Name: public: void CWinApp::DevModeChange(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::DevModeChange(CWinApp *this, char *lpDeviceName)
{
  void *m_hDevNames; // eax
  const char *v4; // eax
  SIZE_T v5; // eax
  HGLOBAL v6; // eax
  _devicemodeA *v7; // eax
  void *hPrinter; // [esp+8h] [ebp-4h] BYREF

  m_hDevNames = this->m_hDevNames;
  if ( m_hDevNames != nullptr )
  {
    v4 = (const char *)GlobalLock(hMem: m_hDevNames);
    if ( lstrcmpA(lpString1: &v4[*((unsigned __int16 *)v4 + 1)], lpString2: lpDeviceName) == 0
      && OpenPrinterA(pPrinterName: lpDeviceName, phPrinter: &hPrinter, pDefault: nullptr) )
    {
      if ( this->m_hDevMode != nullptr )
        AfxGlobalFree(hGlobal: this->m_hDevMode);
      v5 = DocumentPropertiesA(
             hWnd: nullptr,
             hPrinter,
             pDeviceName: lpDeviceName,
             pDevModeOutput: nullptr,
             pDevModeInput: nullptr,
             fMode: 0);
      v6 = GlobalAlloc(uFlags: 0x42u, dwBytes: v5);
      this->m_hDevMode = v6;
      v7 = (_devicemodeA *)GlobalLock(hMem: v6);
      if ( DocumentPropertiesA(
             hWnd: nullptr,
             hPrinter,
             pDeviceName: lpDeviceName,
             pDevModeOutput: v7,
             pDevModeInput: nullptr,
             fMode: 2u) != 1 )
      {
        AfxGlobalFree(hGlobal: this->m_hDevMode);
        this->m_hDevMode = nullptr;
      }
      ClosePrinter(hPrinter);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034D0CC
// Name: public: virtual struct CRuntimeClass __near * CWinApp::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CWinApp::GetRuntimeClass(CWinApp *this)
{
  return &CWinApp::classCWinApp;
}

//------------------------------------------------------------------------------
// Address: 0x1034D0F0
// Name: protected: static struct AFX_MSGMAP const __near * CWinApp::GetThisMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CWinApp::GetThisMessageMap(CWinApp *this)
{
  return &messageMap_18;
}

//------------------------------------------------------------------------------
// Address: 0x1034D397
// Name: public: virtual int CWinApp::LoadSysPolicies(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __thiscall CWinApp::LoadSysPolicies(CWinApp *this)
{
  return CWinApp::_LoadSysPolicies(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034D39C
// Name: public: virtual struct HINSTANCE__ __near * CWinApp::LoadAppLangResourceDLL(void)
// Source: json
//------------------------------------------------------------------------------
HINSTANCE__ *__thiscall CWinApp::LoadAppLangResourceDLL(CWinApp *this)
{
  DWORD ModuleFileNameA; // eax
  char szPath[260]; // [esp+4h] [ebp-114h] BYREF
  char szFormat[12]; // [esp+108h] [ebp-10h] BYREF

  ModuleFileNameA = GetModuleFileNameA(hModule: this->m_hInstance, lpFilename: szPath, nSize: 0x104u);
  if ( ModuleFileNameA == 0 || ModuleFileNameA == 260 )
    return nullptr;
  *PathFindExtensionA(pszPath: szPath) = 0;
  strcpy(szFormat, "%s%s.dll");
  return AfxLoadLangResourceDLL(pszFormat: szFormat, pszPath: szPath);
}

//------------------------------------------------------------------------------
// Address: 0x1034D410
// Name: public: virtual int CWinApp::Run(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::Run(CWinApp *this)
{
  if ( this->m_pMainWnd == nullptr && AfxOleGetUserCtrl() != 0 )
    AfxPostQuitMessage(nExitCode: 0);
  return CWinThread::Run(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034D433
// Name: public: virtual void CWinApp::WinHelpA(unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::WinHelpA(CWinApp *this, unsigned int dwData, unsigned int nCmd)
{
  CWnd *MainWnd; // esi

  MainWnd = AfxGetMainWnd();
  if ( MainWnd == nullptr )
    AfxThrowInvalidArgException();
  this->m_bHelpMode = 0;
  PostMessageA(hWnd: MainWnd->m_hWnd, Msg: 0x36Au, wParam: 0, lParam: 0);
  MainWnd->WinHelpA(this: MainWnd, a2: dwData, a3: nCmd);
}

//------------------------------------------------------------------------------
// Address: 0x1034D474
// Name: public: virtual void CWinApp::HtmlHelpA(unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::HtmlHelpA(CWinApp *this, unsigned int dwData, unsigned int nCmd)
{
  CWnd *MainWnd; // esi

  MainWnd = AfxGetMainWnd();
  if ( MainWnd == nullptr )
    AfxThrowInvalidArgException();
  this->m_bHelpMode = 0;
  PostMessageA(hWnd: MainWnd->m_hWnd, Msg: 0x36Au, wParam: 0, lParam: 0);
  MainWnd->HtmlHelpA(this: MainWnd, a2: dwData, a3: nCmd);
}

//------------------------------------------------------------------------------
// Address: 0x1034D4B8
// Name: public: virtual void CWinApp::WinHelpInternal(unsigned long,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::WinHelpInternal(CWinApp *this, unsigned int dwData, unsigned int nCmd)
{
  CWnd *MainWnd; // esi

  MainWnd = AfxGetMainWnd();
  if ( MainWnd == nullptr )
    AfxThrowInvalidArgException();
  this->m_bHelpMode = 0;
  PostMessageA(hWnd: MainWnd->m_hWnd, Msg: 0x36Au, wParam: 0, lParam: 0);
  MainWnd->WinHelpInternal(this: MainWnd, a2: dwData, a3: nCmd);
}

//------------------------------------------------------------------------------
// Address: 0x1034D526
// Name: public: virtual class CDataRecoveryHandler __near * CWinApp::GetDataRecoveryHandler(void)
// Source: json
//------------------------------------------------------------------------------
CDataRecoveryHandler *__thiscall CWinApp::GetDataRecoveryHandler(CWinApp *this)
{
  CDataRecoveryHandler *v2; // ecx
  CDataRecoveryHandler *v3; // eax
  CDataRecoveryHandler *m_pDataRecoveryHandler; // ecx

  if ( afxGlobalData.bIsWindowsVista != 0
    && (this->SupportsRestartManager(this) != 0 || this->SupportsApplicationRecovery(this) != 0)
    && bTriedOnce == 0
    && this->m_pDataRecoveryHandler == nullptr )
  {
    v2 = (CDataRecoveryHandler *)operator new(nSize: 0xCCu);
    v3 = v2 != nullptr
       ? CDataRecoveryHandler::CDataRecoveryHandler(
           this: v2,
           dwRestartManagerSupportFlags: this->m_dwRestartManagerSupportFlags,
           nAutosaveInterval: this->m_nAutosaveInterval)
       : nullptr;
    this->m_pDataRecoveryHandler = v3;
    if ( v3->Initialize(this: v3) == 0 )
    {
      m_pDataRecoveryHandler = this->m_pDataRecoveryHandler;
      if ( m_pDataRecoveryHandler != nullptr )
        ((void (__thiscall *)(CDataRecoveryHandler *, int))m_pDataRecoveryHandler->dtr_CObject)(
          a1: m_pDataRecoveryHandler,
          a2: 1);
      this->m_pDataRecoveryHandler = nullptr;
    }
  }
  bTriedOnce = 1;
  return this->m_pDataRecoveryHandler;
}

//------------------------------------------------------------------------------
// Address: 0x1034D676
// Name: public: CWinApp::CWinApp(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CWinApp *__thiscall CWinApp::CWinApp(CWinApp *this, const char *lpszAppName)
{
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v4; // ebx
  AFX_MODULE_THREAD_STATE *Data; // eax

  CWinThread::CWinThread(this);
  this->__vftable = (CWinApp_vtbl *)&CWinApp::`vftable';
  if ( lpszAppName != nullptr )
    this->m_pszAppName = _strdup(string: lpszAppName);
  else
    this->m_pszAppName = nullptr;
  ModuleState = AfxGetModuleState();
  v4 = ModuleState;
  if ( ModuleState == nullptr
    || (Data = CThreadLocal<AFX_MODULE_THREAD_STATE>::GetData(this: &ModuleState->m_thread)) == nullptr )
  {
    AfxThrowInvalidArgException();
  }
  Data->m_pCurrentWinThread = this;
  this->m_hThread = GetCurrentThread();
  this->m_nThreadID = GetCurrentThreadId();
  v4->m_pCurrentWinApp = this;
  this->m_atomSystemTopic = 0;
  this->m_atomApp = 0;
  this->m_hInstance = nullptr;
  this->m_hLangResourceDLL = nullptr;
  this->m_pszHelpFilePath = nullptr;
  this->m_pszProfileName = nullptr;
  this->m_pszRegistryKey = nullptr;
  this->m_pszExeName = nullptr;
  this->m_pRecentFileList = nullptr;
  this->m_pDocManager = nullptr;
  this->m_lpCmdLine = nullptr;
  this->m_pCmdInfo = nullptr;
  this->m_pDataRecoveryHandler = nullptr;
  this->m_nWaitCursorCount = 0;
  this->m_hcurWaitCursorRestore = nullptr;
  this->m_hDevMode = nullptr;
  this->m_hDevNames = nullptr;
  this->m_nNumPreviewPages = 0;
  this->m_lpfnDaoTerm = nullptr;
  this->m_bHelpMode = 0;
  this->m_eHelpType = afxWinHelp;
  this->m_nSafetyPoolSize = 512;
  this->m_dwRestartManagerSupportFlags = 0;
  this->m_nAutosaveInterval = 300000;
  this->m_bTaskbarInteractionEnabled = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1034D872
// Name: public: virtual CWinApp::~CWinApp(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CWinApp::~CWinApp(CWinApp *this)
{
  CDocManager *m_pDocManager; // ecx
  CRecentFileList *m_pRecentFileList; // ecx
  CDataRecoveryHandler *m_pDataRecoveryHandler; // ecx
  CCommandLineInfo *m_pCmdInfo; // ecx
  AFX_MODULE_STATE *ModuleState; // eax

  this->__vftable = (CWinApp_vtbl *)&CWinApp::`vftable';
  m_pDocManager = this->m_pDocManager;
  if ( m_pDocManager != nullptr )
    ((void (__thiscall *)(CDocManager *, int))m_pDocManager->dtr_CObject)(a1: m_pDocManager, a2: 1);
  m_pRecentFileList = this->m_pRecentFileList;
  if ( m_pRecentFileList != nullptr )
    ((void (__thiscall *)(CRecentFileList *, int))m_pRecentFileList->dtr_CRecentFileList)(a1: m_pRecentFileList, a2: 1);
  m_pDataRecoveryHandler = this->m_pDataRecoveryHandler;
  if ( m_pDataRecoveryHandler != nullptr )
    ((void (__thiscall *)(CDataRecoveryHandler *, int))m_pDataRecoveryHandler->dtr_CObject)(
      a1: m_pDataRecoveryHandler,
      a2: 1);
  if ( AfxGetModuleState()->m_bDLL == 0 )
  {
    if ( CDocManager::pStaticList != nullptr )
    {
      ((void (__thiscall *)(CPtrList *, int))CDocManager::pStaticList->dtr_CObject)(a1: CDocManager::pStaticList, a2: 1);
      CDocManager::pStaticList = nullptr;
    }
    if ( CDocManager::pStaticDocManager != nullptr )
    {
      ((void (__thiscall *)(CDocManager *, int))CDocManager::pStaticDocManager->dtr_CObject)(
        a1: CDocManager::pStaticDocManager,
        a2: 1);
      CDocManager::pStaticDocManager = nullptr;
    }
  }
  if ( this->m_hDevMode != nullptr )
    AfxGlobalFree(hGlobal: this->m_hDevMode);
  if ( this->m_hDevNames != nullptr )
    AfxGlobalFree(hGlobal: this->m_hDevNames);
  if ( this->m_atomApp != 0 )
    GlobalDeleteAtom(nAtom: this->m_atomApp);
  if ( this->m_atomSystemTopic != 0 )
    GlobalDeleteAtom(nAtom: this->m_atomSystemTopic);
  m_pCmdInfo = this->m_pCmdInfo;
  if ( m_pCmdInfo != nullptr )
    ((void (__thiscall *)(CCommandLineInfo *, int))m_pCmdInfo->dtr_CObject)(a1: m_pCmdInfo, a2: 1);
  ModuleState = AfxGetModuleState();
  if ( ModuleState->m_lpszCurrentAppName == this->m_pszAppName )
    ModuleState->m_lpszCurrentAppName = nullptr;
  if ( ModuleState->m_pCurrentWinApp == this )
    ModuleState->m_pCurrentWinApp = nullptr;
  free(pMem: (void *)this->m_pszAppName);
  free(pMem: (void *)this->m_pszRegistryKey);
  free(pMem: (void *)this->m_pszExeName);
  free(pMem: (void *)this->m_pszHelpFilePath);
  free(pMem: (void *)this->m_pszProfileName);
  this->m_hThread = nullptr;
  CWinThread::~CWinThread(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034DAD4
// Name: public: virtual int CWinApp::InitInstance(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::InitInstance(CWinApp *this)
{
  HINSTANCE__ *v2; // ebx
  CWinApp_vtbl *v3; // edi
  int v4; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v6; // [esp+10h] [ebp-10h] BYREF
  int v7; // [esp+1Ch] [ebp-4h]

  this->InitLibId(this);
  v2 = this->LoadAppLangResourceDLL(this);
  this->m_hLangResourceDLL = v2;
  if ( v2 != nullptr )
  {
    AfxGetModuleState()->m_hCurrentResourceHandle = v2;
    InterlockedExchange(
      Target: (volatile LONG *)&ATL::_AtlBaseModule.m_hInstResource,
      Value: (LONG)this->m_hLangResourceDLL);
  }
  if ( this->SupportsRestartManager(this) != 0 )
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &v6,
      pszSrc: &var);
    v3 = this->__vftable;
    v7 = 0;
    v4 = ((int (__thiscall *)(CWinApp *, ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *))v3->SupportsApplicationRecovery)(
           a1: this,
           a2: &v6);
    ((void (__thiscall *)(CWinApp *, int))v3->RegisterWithRestartManager)(a1: this, a2: v4);
    ATL::CStringData::Release(this: (ATL::CStringData *)v6.m_pszData - 1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034DD65
// Name: public: virtual long CWinApp::RegisterWithRestartManager(int,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall CWinApp::RegisterWithRestartManager(
        CWinApp *this,
        int bRegisterRecoveryCallback,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strRestartIdentifierParam)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v5; // eax
  ATL::CStringData *v6; // eax
  CAfxStringMgr *v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  CDataRecoveryHandler *v11; // eax
  char *m_str; // eax
  CWinApp_vtbl *v13; // esi
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  wchar_t *v18; // eax
  CWinApp_vtbl *v19; // esi
  int v20; // eax
  int v21; // esi
  ATL::CStringData *v23; // [esp-4h] [ebp-48h]
  wchar_t *m_pszData; // [esp+0h] [ebp-44h]
  ATL::CComBSTR v25; // [esp+10h] [ebp-34h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v26; // [esp+14h] [ebp-30h] BYREF
  ATL::CSimpleStringT<char,0> v27; // [esp+18h] [ebp-2Ch] BYREF
  ATL::CSimpleStringT<char,0> v28; // [esp+1Ch] [ebp-28h] BYREF
  ATL::CSimpleStringT<char,0> v29; // [esp+20h] [ebp-24h] BYREF
  GUID pguid; // [esp+24h] [ebp-20h] BYREF
  int v31; // [esp+40h] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v29, pStringMgr: StringManager);
  v31 = 0;
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v28, pStringMgr: v5);
  v23 = (ATL::CStringData *)(strRestartIdentifierParam->m_pszData - 16);
  LOBYTE(v31) = 1;
  v6 = ATL::CSimpleStringT<char,0>::CloneData(pData: v23);
  v26.m_pszData = (char *)&v6[1];
  LOBYTE(v31) = 2;
  if ( v6->nDataLength == 0 )
  {
    memset((void *)&pguid, 0, sizeof(pguid));
    CoCreateGuid(&pguid);
    v7 = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v27, pStringMgr: v7);
    LOBYTE(v31) = 3;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &v26,
      pszFormat: "%08lX-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X",
      pguid.Data1,
      pguid.Data2,
      pguid.Data3,
      pguid.Data4[0],
      pguid.Data4[1],
      pguid.Data4[2],
      pguid.Data4[3],
      pguid.Data4[4],
      pguid.Data4[5],
      pguid.Data4[6],
      pguid.Data4[7]);
    LOBYTE(v31) = 2;
    ATL::CStringData::Release(this: (ATL::CStringData *)v27.m_pszData - 1);
  }
  ATL::CSimpleStringT<char,0>::SetString(this: &v29, pszSrc: this->m_lpCmdLine);
  strlen(buf: "RestartByRestartManager");
  ATL::CSimpleStringT<char,0>::Append(this: &v28, pszSrc: "RestartByRestartManager", nLength: v8);
  strlen(buf: ":");
  ATL::CSimpleStringT<char,0>::Append(this: &v28, pszSrc: ":", nLength: v9);
  ATL::CSimpleStringT<char,0>::Append(this: &v28, pszSrc: v26.m_pszData, nLength: *((_DWORD *)v26.m_pszData - 3));
  if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
         this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v29,
         pszSub: v28.m_pszData,
         iStart: 0) == -1 )
  {
    strlen(buf: " /");
    ATL::CSimpleStringT<char,0>::Append(this: &v29, pszSrc: " /", nLength: v10);
    ATL::CSimpleStringT<char,0>::Append(this: &v29, pszSrc: v28.m_pszData, nLength: *((_DWORD *)v28.m_pszData - 3));
  }
  v11 = this->GetDataRecoveryHandler(this);
  if ( v11 != nullptr )
    v11->SetRestartIdentifier(this: v11, a2: &v26);
  if ( bRegisterRecoveryCallback != 0 )
  {
    m_str = (char *)ATL::CComBSTR::CComBSTR(this: &v25, pSrc: v29.m_pszData)->m_str;
    v13 = this->__vftable;
    LOBYTE(v31) = 4;
    v27.m_pszData = m_str;
    v14 = ((int (__thiscall *)(CWinApp *, _DWORD))v13->GetApplicationRecoveryPingInterval)(a1: this, a2: 0);
    v15 = ((int (__thiscall *)(CWinApp *, int))this->GetApplicationRecoveryParameter)(a1: this, a2: v14);
    v16 = ((int (__thiscall *)(CWinApp *, unsigned int (__stdcall *)(void *), int))this->GetApplicationRestartFlags)(
            a1: this,
            a2: AfxApplicationRecoveryWrapper,
            a3: v15);
    v17 = ((int (__thiscall *)(CWinApp *, char *, int))v13->RegisterWithRestartManager)(
            a1: this,
            a2: v27.m_pszData,
            a3: v16);
    m_pszData = v25.m_str;
  }
  else
  {
    v18 = ATL::CComBSTR::CComBSTR(this: (ATL::CComBSTR *)&v27, pSrc: v29.m_pszData)->m_str;
    v19 = this->__vftable;
    LOBYTE(v31) = 5;
    v25.m_str = v18;
    v20 = ((int (__thiscall *)(CWinApp *, _DWORD, _DWORD, _DWORD, _DWORD))v19->GetApplicationRestartFlags)(
            a1: this,
            a2: 0,
            a3: 0,
            a4: 0,
            a5: 0);
    v17 = ((int (__thiscall *)(CWinApp *, wchar_t *, int))v19->RegisterWithRestartManager)(
            a1: this,
            a2: v25.m_str,
            a3: v20);
    m_pszData = (wchar_t *)v27.m_pszData;
  }
  v21 = v17;
  SysFreeString(bstrString: m_pszData);
  ATL::CStringData::Release(this: (ATL::CStringData *)v26.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)v28.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)v29.m_pszData - 1);
  return v21;
}

//------------------------------------------------------------------------------
// Address: 0x1034DF7B
// Name: public: virtual void CCommandLineInfo::ParseParam(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommandLineInfo::ParseParam(CCommandLineInfo *this, const char *pszParam, int bFlag, int bLast)
{
  if ( bFlag != 0 )
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pszParam,
      pszSrc: pszParam);
    CCommandLineInfo::ParseParamFlag(this, pszParam);
    ATL::CStringData::Release(this: (ATL::CStringData *)pszParam - 1);
  }
  else
  {
    CCommandLineInfo::ParseParamNotFlag(this, pszParam);
  }
  CCommandLineInfo::ParseLast(this, bLast);
}

//------------------------------------------------------------------------------
// Address: 0x1034DFCC
// Name: protected: void CWinApp::SetRegistryKey(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::SetRegistryKey(CWinApp *this, const char *lpszRegistryKey)
{
  const char *v3; // eax
  char *m_pszProfileName; // [esp-Ch] [ebp-10h]

  free(pMem: (void *)this->m_pszRegistryKey);
  v3 = _strdup(string: lpszRegistryKey);
  m_pszProfileName = (char *)this->m_pszProfileName;
  this->m_pszRegistryKey = v3;
  free(pMem: m_pszProfileName);
  this->m_pszProfileName = _strdup(string: this->m_pszAppName);
}

//------------------------------------------------------------------------------
// Address: 0x1034E002
// Name: public: virtual int CWinApp::IsTaskbarInteractionEnabled(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWinApp::IsTaskbarInteractionEnabled(CWinApp *this)
{
  BOOL result; // eax

  result = false;
  if ( afxGlobalData.bIsWindows7 != 0 )
    return this->m_bTaskbarInteractionEnabled != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034E098
// Name: public: struct HKEY__ __near * CWinApp::GetAppRegistryKey(class ATL::CAtlTransactionManager __near *)
// Source: json
//------------------------------------------------------------------------------
HKEY__ *__thiscall CWinApp::GetAppRegistryKey(CWinApp *this, ATL::CAtlTransactionManager *pTM)
{
  LSTATUS v3; // eax
  int v4; // eax
  const char *m_pszRegistryKey; // [esp-20h] [ebp-3Ch]
  const char *m_pszProfileName; // [esp-20h] [ebp-3Ch]
  HKEY__ *hAppKey; // [esp+Ch] [ebp-10h] BYREF
  unsigned int dw; // [esp+10h] [ebp-Ch] BYREF
  HKEY__ *hCompanyKey; // [esp+14h] [ebp-8h] BYREF
  HKEY__ *hSoftKey; // [esp+18h] [ebp-4h] BYREF

  hAppKey = nullptr;
  hSoftKey = nullptr;
  hCompanyKey = nullptr;
  if ( pTM != nullptr )
    v3 = ATL::CAtlTransactionManager::RegOpenKeyExA(
           this: pTM,
           hKey: (HKEY__ *)0x80000001,
           lpSubKey: "software",
           ulOptions: 0,
           samDesired: 0x2001Fu,
           phkResult: &hSoftKey);
  else
    v3 = RegOpenKeyExA(
           hKey: HKEY_CURRENT_USER,
           lpSubKey: "software",
           ulOptions: 0,
           samDesired: 0x2001Fu,
           phkResult: &hSoftKey);
  if ( v3 == 0 )
  {
    m_pszRegistryKey = this->m_pszRegistryKey;
    v4 = pTM != nullptr
       ? ATL::CAtlTransactionManager::RegCreateKeyExA(
           this: pTM,
           hKey: hSoftKey,
           lpSubKey: m_pszRegistryKey,
           dwReserved: 0,
           lpClass: nullptr,
           dwOptions: 0,
           samDesired: 0x2001Fu,
           lpSecurityAttributes: nullptr,
           phkResult: &hCompanyKey,
           lpdwDisposition: &dw)
       : RegCreateKeyExA(
           hKey: hSoftKey,
           lpSubKey: m_pszRegistryKey,
           Reserved: 0,
           lpClass: nullptr,
           dwOptions: 0,
           samDesired: 0x2001Fu,
           lpSecurityAttributes: nullptr,
           phkResult: &hCompanyKey,
           lpdwDisposition: &dw);
    if ( v4 == 0 )
    {
      m_pszProfileName = this->m_pszProfileName;
      if ( pTM != nullptr )
        ATL::CAtlTransactionManager::RegCreateKeyExA(
          this: pTM,
          hKey: hCompanyKey,
          lpSubKey: m_pszProfileName,
          dwReserved: 0,
          lpClass: nullptr,
          dwOptions: 0,
          samDesired: 0x2001Fu,
          lpSecurityAttributes: nullptr,
          phkResult: &hAppKey,
          lpdwDisposition: &dw);
      else
        RegCreateKeyExA(
          hKey: hCompanyKey,
          lpSubKey: m_pszProfileName,
          Reserved: 0,
          lpClass: nullptr,
          dwOptions: 0,
          samDesired: 0x2001Fu,
          lpSecurityAttributes: nullptr,
          phkResult: &hAppKey,
          lpdwDisposition: &dw);
    }
  }
  if ( hSoftKey != nullptr )
    RegCloseKey(hKey: hSoftKey);
  if ( hCompanyKey != nullptr )
    RegCloseKey(hKey: hCompanyKey);
  return hAppKey;
}

//------------------------------------------------------------------------------
// Address: 0x1034E153
// Name: public: struct HKEY__ __near * CWinApp::GetSectionKey(char const __near *,class ATL::CAtlTransactionManager __near *)
// Source: json
//------------------------------------------------------------------------------
HKEY__ *__thiscall CWinApp::GetSectionKey(CWinApp *this, const char *lpszSection, ATL::CAtlTransactionManager *pTM)
{
  HKEY__ *AppRegistryKey; // edi
  unsigned int dw; // [esp+8h] [ebp-8h] BYREF
  HKEY__ *hSectionKey; // [esp+Ch] [ebp-4h] BYREF

  hSectionKey = nullptr;
  AppRegistryKey = CWinApp::GetAppRegistryKey(this, pTM);
  if ( AppRegistryKey == nullptr )
    return nullptr;
  if ( pTM != nullptr )
    ATL::CAtlTransactionManager::RegCreateKeyExA(
      this: pTM,
      hKey: AppRegistryKey,
      lpSubKey: lpszSection,
      dwReserved: 0,
      lpClass: nullptr,
      dwOptions: 0,
      samDesired: 0x2001Fu,
      lpSecurityAttributes: nullptr,
      phkResult: &hSectionKey,
      lpdwDisposition: &dw);
  else
    RegCreateKeyExA(
      hKey: AppRegistryKey,
      lpSubKey: lpszSection,
      Reserved: 0,
      lpClass: nullptr,
      dwOptions: 0,
      samDesired: 0x2001Fu,
      lpSecurityAttributes: nullptr,
      phkResult: &hSectionKey,
      lpdwDisposition: &dw);
  RegCloseKey(hKey: AppRegistryKey);
  return hSectionKey;
}

//------------------------------------------------------------------------------
// Address: 0x1034E1AD
// Name: public: virtual unsigned int CWinApp::GetProfileIntA(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
UINT __thiscall CWinApp::GetProfileIntA(CWinApp *this, unsigned int lpszSection, const char *lpszEntry, INT nDefault)
{
  HKEY SectionKey; // esi
  LSTATUS v6; // ebx
  unsigned int dwType; // [esp+4h] [ebp-8h] BYREF
  unsigned int dwValue; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_pszRegistryKey == nullptr )
    return GetPrivateProfileIntA(
             lpAppName: (LPCSTR)lpszSection,
             lpKeyName: lpszEntry,
             nDefault,
             lpFileName: this->m_pszProfileName);
  SectionKey = CWinApp::GetSectionKey(this, (const char *)lpszSection, pTM: nullptr);
  if ( SectionKey == nullptr )
    return nDefault;
  lpszSection = 4;
  v6 = RegQueryValueExA(
         hKey: SectionKey,
         lpValueName: lpszEntry,
         lpReserved: nullptr,
         lpType: &dwType,
         lpData: (LPBYTE)&dwValue,
         lpcbData: &lpszSection);
  RegCloseKey(hKey: SectionKey);
  if ( v6 != 0 )
    return nDefault;
  else
    return dwValue;
}

//------------------------------------------------------------------------------
// Address: 0x1034E21A
// Name: public: virtual int CWinApp::WriteProfileInt(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
HKEY __thiscall CWinApp::WriteProfileInt(CWinApp *this, const char *lpszSection, const char *lpszEntry, int nValue)
{
  HKEY result; // eax
  HKEY v6; // esi
  LSTATUS v7; // edi
  char szT[16]; // [esp+Ch] [ebp-14h] BYREF

  if ( this->m_pszRegistryKey != nullptr )
  {
    result = CWinApp::GetSectionKey(this, lpszSection, pTM: nullptr);
    v6 = result;
    if ( result != nullptr )
    {
      v7 = RegSetValueExA(
             hKey: result,
             lpValueName: lpszEntry,
             Reserved: 0,
             dwType: 4u,
             lpData: (const BYTE *)&nValue,
             cbData: 4u);
      RegCloseKey(hKey: v6);
      return (HKEY)(v7 == 0);
    }
  }
  else
  {
    sprintf_s(string: szT, sizeInBytes: 0x10u, format: "%d", nValue);
    return (HKEY)WritePrivateProfileStringA(
                   lpAppName: lpszSection,
                   lpKeyName: lpszEntry,
                   lpString: szT,
                   lpFileName: this->m_pszProfileName);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034E2A5
// Name: public: virtual int CWinApp::WriteProfileStringA(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWinApp::WriteProfileStringA(
        CWinApp *this,
        const char *lpszSection,
        const char *lpszEntry,
        const char *lpszValue)
{
  HKEY AppRegistryKey; // eax
  HKEY v5; // esi
  LSTATUS v7; // eax
  HKEY SectionKey; // eax
  int v9; // eax
  LSTATUS v10; // edi

  if ( this->m_pszRegistryKey == nullptr )
    return WritePrivateProfileStringA(
             lpAppName: lpszSection,
             lpKeyName: lpszEntry,
             lpString: lpszValue,
             lpFileName: this->m_pszProfileName);
  if ( lpszEntry != nullptr )
  {
    SectionKey = CWinApp::GetSectionKey(this, lpszSection, pTM: nullptr);
    v5 = SectionKey;
    if ( lpszValue != nullptr )
    {
      if ( SectionKey == nullptr )
        return false;
      v9 = lstrlenA(lpString: lpszValue);
      v7 = RegSetValueExA(
             hKey: v5,
             lpValueName: lpszEntry,
             Reserved: 0,
             dwType: 1u,
             lpData: (const BYTE *)lpszValue,
             cbData: v9 + 1);
    }
    else
    {
      if ( SectionKey == nullptr )
        return false;
      v7 = RegDeleteValueA(hKey: SectionKey, lpValueName: lpszEntry);
    }
  }
  else
  {
    AppRegistryKey = CWinApp::GetAppRegistryKey(this, pTM: nullptr);
    v5 = AppRegistryKey;
    if ( AppRegistryKey == nullptr )
      return false;
    v7 = RegDeleteKeyA(hKey: AppRegistryKey, lpSubKey: lpszSection);
  }
  v10 = v7;
  RegCloseKey(hKey: v5);
  return v10 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1034E33E
// Name: public: virtual int CWinApp::WriteProfileBinary(char const __near *,char const __near *,unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CWinApp::WriteProfileBinary(
        CWinApp *this,
        const char *lpszSection,
        const char *lpszEntry,
        unsigned __int8 *pData,
        DWORD nBytes)
{
  HKEY SectionKey; // eax
  HKEY v7; // esi
  LSTATUS v9; // ebx
  char *v10; // esi
  DWORD i; // eax
  int v12; // edi

  if ( this->m_pszRegistryKey != nullptr )
  {
    SectionKey = CWinApp::GetSectionKey(this, lpszSection, pTM: nullptr);
    v7 = SectionKey;
    if ( SectionKey != nullptr )
    {
      v9 = RegSetValueExA(
             hKey: SectionKey,
             lpValueName: lpszEntry,
             Reserved: 0,
             dwType: 3u,
             lpData: pData,
             cbData: nBytes);
      RegCloseKey(hKey: v7);
      return v9 == 0;
    }
    else
    {
      return false;
    }
  }
  else
  {
    v10 = (char *)operator new(nSize: 2 * nBytes + 1);
    for ( i = 0; i < nBytes; ++i )
    {
      v10[2 * i] = (pData[i] & 0xF) + 65;
      v10[2 * i + 1] = (pData[i] >> 4) + 65;
    }
    v10[2 * i] = 0;
    v12 = this->WriteProfileStringA(this, a2: lpszSection, a3: lpszEntry, a4: v10);
    operator delete(p: v10);
    return v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034E3EA
// Name: public: virtual int CWinApp::GetProfileBinary(char const __near *,char const __near *,unsigned char __near * __near *,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::GetProfileBinary(
        CWinApp *this,
        const char *lpszSection,
        const char *lpszEntry,
        unsigned __int8 **ppData,
        unsigned int *pBytes)
{
  void **v5; // edi
  unsigned int *v6; // ebx
  int v7; // esi
  HKEY__ *SectionKey; // eax
  LSTATUS Value; // eax
  const char *v11; // ecx
  unsigned __int8 *v12; // eax
  unsigned int *v13; // eax
  void *v14; // eax
  int v15; // ecx
  int v16; // edx
  int v17; // ebx
  char v18; // bl
  int v19; // eax
  ATL::CRegKey rkSecKey; // [esp+10h] [ebp-1Ch] BYREF
  HKEY__ *hSecKey; // [esp+1Ch] [ebp-10h]
  int v22; // [esp+28h] [ebp-4h]

  v5 = (void **)ppData;
  v6 = pBytes;
  v7 = 0;
  *ppData = nullptr;
  *v6 = 0;
  if ( this->m_pszRegistryKey != nullptr )
  {
    SectionKey = CWinApp::GetSectionKey(this, lpszSection, pTM: nullptr);
    hSecKey = SectionKey;
    if ( SectionKey == nullptr )
      return 0;
    rkSecKey.m_hKey = SectionKey;
    rkSecKey.m_samWOW64 = 0;
    rkSecKey.m_pTM = nullptr;
    v22 = 0;
    ppData = nullptr;
    lpszSection = nullptr;
    Value = RegQueryValueExA(
              hKey: SectionKey,
              lpValueName: lpszEntry,
              lpReserved: nullptr,
              lpType: (LPDWORD)&ppData,
              lpData: nullptr,
              lpcbData: (LPDWORD)&lpszSection);
    v11 = lpszSection;
    *pBytes = (unsigned int)lpszSection;
    if ( Value != 0
      || (v12 = (unsigned __int8 *)operator new(nSize: (unsigned int)v11),
          *v5 = v12,
          RegQueryValueExA(
            hKey: hSecKey,
            lpValueName: lpszEntry,
            lpReserved: nullptr,
            lpType: (LPDWORD)&ppData,
            lpData: v12,
            lpcbData: (LPDWORD)&lpszSection) != 0) )
    {
      operator delete(p: *v5);
      *v5 = nullptr;
    }
    else
    {
      v7 = 1;
    }
    ATL::CRegKey::Close(this: &rkSecKey);
    return v7;
  }
  else
  {
    this->GetProfileStringA(
      this,
      result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszEntry,
      a3: lpszSection,
      a4: lpszEntry,
      a5: nullptr);
    v13 = *((unsigned int **)lpszEntry - 3);
    v22 = 1;
    if ( v13 == nullptr )
    {
      ATL::CStringData::Release(this: (ATL::CStringData *)lpszEntry - 1);
      return 0;
    }
    pBytes = v13;
    *v6 = (unsigned int)v13 >> 1;
    v14 = operator new(nSize: (unsigned int)v13 >> 1);
    v15 = 0;
    for ( *v5 = v14; v15 < (int)pBytes; *((_BYTE *)*v5 + v19) = v18 - 65 )
    {
      v16 = v15 + 1;
      if ( v15 + 1 < 0 || (v17 = *((_DWORD *)lpszEntry - 3), v16 > v17) || v15 < 0 || v15 > v17 )
        ATL::AtlThrowImpl(hr: -2147024809);
      v18 = lpszEntry[v15] + 16 * (lpszEntry[v16] - 1);
      v19 = v15 / 2;
      v15 += 2;
    }
    ATL::CStringData::Release(this: (ATL::CStringData *)lpszEntry - 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034E6DB
// Name: public: virtual void CWinApp::DoWaitCursor(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::DoWaitCursor(CWinApp *this, int nCode)
{
  HICON__ *v3; // eax
  HICON__ *m_hcurWaitCursorRestore; // [esp-4h] [ebp-Ch]

  if ( (unsigned int)nCode >= 2 && nCode != -1 || afxData.hcurWait == nullptr )
    AfxThrowInvalidArgException();
  AfxLockGlobals(nLockType: 2);
  this->m_nWaitCursorCount += nCode;
  if ( this->m_nWaitCursorCount <= 0 )
  {
    m_hcurWaitCursorRestore = this->m_hcurWaitCursorRestore;
    this->m_nWaitCursorCount = 0;
    SetCursor(hCursor: m_hcurWaitCursorRestore);
  }
  else
  {
    v3 = SetCursor(hCursor: afxData.hcurWait);
    if ( nCode > 0 && this->m_nWaitCursorCount == 1 )
      this->m_hcurWaitCursorRestore = v3;
  }
  AfxUnlockGlobals(nLockType: 2);
}

//------------------------------------------------------------------------------
// Address: 0x1034E75A
// Name: public: virtual int CWinApp::SaveAllModified(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::SaveAllModified(CWinApp *this)
{
  if ( this->m_pDocManager != nullptr )
    return this->m_pDocManager->SaveAllModified(this: this->m_pDocManager);
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034E76C
// Name: public: virtual void CWinApp::AddToRecentFileList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::AddToRecentFileList(CWinApp *this, const char *lpszPathName)
{
  if ( lpszPathName == nullptr )
    AfxThrowInvalidArgException();
  if ( this->m_pRecentFileList != nullptr )
    this->m_pRecentFileList->Add(this: this->m_pRecentFileList, a2: lpszPathName, a3: this->m_pszAppID);
}

//------------------------------------------------------------------------------
// Address: 0x1034E79C
// Name: public: virtual class CDocument __near * CWinApp::OpenDocumentFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDocument *__thiscall CWinApp::OpenDocumentFile(CWinApp *this, const char *lpszFileName)
{
  if ( this->m_pDocManager == nullptr )
    AfxThrowInvalidArgException();
  return this->m_pDocManager->OpenDocumentFile_2(this: this->m_pDocManager, a2: lpszFileName);
}

//------------------------------------------------------------------------------
// Address: 0x1034E7B5
// Name: public: virtual class CDocument __near * CWinApp::OpenDocumentFile(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CDocument *__thiscall CWinApp::OpenDocumentFile(CWinApp *this, const char *lpszFileName, int bAddToMRU)
{
  if ( this->m_pDocManager == nullptr )
    AfxThrowInvalidArgException();
  return this->m_pDocManager->OpenDocumentFile(this: this->m_pDocManager, a2: lpszFileName, a3: bAddToMRU);
}

//------------------------------------------------------------------------------
// Address: 0x1034E7CE
// Name: public: void CWinApp::CloseAllDocuments(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::CloseAllDocuments(CWinApp *this, int bEndSession)
{
  if ( this->m_pDocManager != nullptr )
    this->m_pDocManager->CloseAllDocuments(this: this->m_pDocManager, a2: bEndSession);
}

//------------------------------------------------------------------------------
// Address: 0x1034E7E6
// Name: protected: void CWinApp::OnUpdateRecentFileMenu(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::OnUpdateRecentFileMenu(CWinApp *this, CCmdUI *pCmdUI)
{
  if ( pCmdUI == nullptr )
    AfxThrowInvalidArgException();
  if ( this->m_pRecentFileList != nullptr )
    this->m_pRecentFileList->UpdateMenu(this: this->m_pRecentFileList, a2: pCmdUI);
  else
    ((void (__stdcall *)(_DWORD))pCmdUI->Enable)(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1034E81C
// Name: public: virtual int CWinApp::OnDDECommand(char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::OnDDECommand(CWinApp *this, char *lpszCommand)
{
  if ( this->m_pDocManager != nullptr )
    return this->m_pDocManager->OnDDECommand(this: this->m_pDocManager, a2: lpszCommand);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1034E856
// Name: protected: void CWinApp::OnAppExit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::OnAppExit(CWinApp *this)
{
  SendMessageA(hWnd: this->m_pMainWnd->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1034E869
// Name: public: void CWinApp::HideApplication(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::HideApplication(CWinApp *this)
{
  CWnd::ShowWindow(this: this->m_pMainWnd, nCmdShow: 0);
  ShowOwnedPopups(hWnd: this->m_pMainWnd->m_hWnd, fShow: false);
  CWnd::SetWindowPos(this: this->m_pMainWnd, pWndInsertAfter: &CWnd::wndBottom, x: 0, y: 0, cx: 0, cy: 0, nFlags: 0x13u);
}

//------------------------------------------------------------------------------
// Address: 0x1034E89D
// Name: protected: int CWinApp::OnOpenRecentFile(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::OnOpenRecentFile(CWinApp *this, unsigned int nID)
{
  CRecentFileList *m_pRecentFileList; // edx
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v4; // eax

  m_pRecentFileList = this->m_pRecentFileList;
  if ( m_pRecentFileList == nullptr || nID < 0xE110 || nID >= m_pRecentFileList->m_nSize + 57616 )
    AfxThrowInvalidArgException();
  g_bRemoveFromMRU = 1;
  v4 = CRecentFileList::operator[](this: this->m_pRecentFileList, nIndex: nID - 57616);
  if ( this->OpenDocumentFile(this, a2: v4->m_pszData) == nullptr && g_bRemoveFromMRU != 0 )
    this->m_pRecentFileList->Remove(this: this->m_pRecentFileList, a2: nID - 57616);
  g_bRemoveFromMRU = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034E919
// Name: protected: void CWinApp::OnFileNew(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::OnFileNew(CWinApp *this)
{
  if ( this->m_pDocManager != nullptr )
    this->m_pDocManager->OnFileNew(this: this->m_pDocManager);
}

//------------------------------------------------------------------------------
// Address: 0x1034E928
// Name: protected: void CWinApp::OnFileOpen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::OnFileOpen(CWinApp *this)
{
  if ( this->m_pDocManager == nullptr )
    AfxThrowInvalidArgException();
  this->m_pDocManager->OnFileOpen(this: this->m_pDocManager);
}

//------------------------------------------------------------------------------
// Address: 0x1034E93B
// Name: public: int CWinApp::DoPromptFileName(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,unsigned int,unsigned long,int,class CDocTemplate __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::DoPromptFileName(
        CWinApp *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *fileName,
        unsigned int nIDSTitle,
        unsigned int lFlags,
        int bOpenFileDialog,
        CDocTemplate *pTemplate)
{
  if ( this->m_pDocManager == nullptr )
    AfxThrowInvalidArgException();
  return this->m_pDocManager->DoPromptFileName(
           this: this->m_pDocManager,
           a2: fileName,
           a3: nIDSTitle,
           a4: lFlags,
           a5: bOpenFileDialog,
           a6: pTemplate);
}

//------------------------------------------------------------------------------
// Address: 0x1034EA2D
// Name: protected: void CWinApp::UpdatePrinterSelection(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::UpdatePrinterSelection(CWinApp *this, int bForceDefaults)
{
  unsigned __int16 *v3; // esi
  CPrintDialog *p_pd; // ecx
  tagPDA *v5; // eax
  tagPDA *m_pd; // eax
  const char *v7; // [esp-8h] [ebp-1ECh]
  const char *v8; // [esp-8h] [ebp-1ECh]
  const char *v9; // [esp-8h] [ebp-1ECh]
  char *m_pszData; // [esp-4h] [ebp-1E8h]
  char *v11; // [esp-4h] [ebp-1E8h]
  char *v12; // [esp-4h] [ebp-1E8h]
  CPrintDialog v13; // [esp+10h] [ebp-1D4h] BYREF
  CPrintDialog pd; // [esp+ECh] [ebp-F8h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v15; // [esp+1C8h] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+1CCh] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v17; // [esp+1D0h] [ebp-14h] BYREF
  int v18; // [esp+1D4h] [ebp-10h]
  int v19; // [esp+1E0h] [ebp-4h]
  char bForceDefaults_3; // [esp+1EFh] [ebp+Bh]

  v18 = 0;
  if ( bForceDefaults != 0 || this->m_hDevNames == nullptr )
  {
    CPrintDialog::CPrintDialog(this: &v13, bPrintSetupOnly: 1, dwFlags: 0x14000Cu, pParentWnd: nullptr);
    v19 = 3;
    CPrintDialog::GetDefaults(this: &v13);
    if ( this->m_hDevMode != nullptr )
      AfxGlobalFree(hGlobal: this->m_hDevMode);
    if ( this->m_hDevNames != nullptr )
      AfxGlobalFree(hGlobal: this->m_hDevNames);
    m_pd = v13.m_pd;
    this->m_hDevMode = v13.m_pd->hDevMode;
    this->m_hDevNames = m_pd->hDevNames;
    v13.__vftable = (CPrintDialog_vtbl *)&CCommonDialog::`vftable';
    p_pd = &v13;
    goto LABEL_35;
  }
  v3 = (unsigned __int16 *)GlobalLock(hMem: this->m_hDevNames);
  if ( v3 == nullptr )
    AfxThrowInvalidArgException();
  if ( (v3[3] & 1) != 0 )
  {
    CPrintDialog::CPrintDialog(this: &pd, bPrintSetupOnly: 1, dwFlags: 0x14000Cu, pParentWnd: nullptr);
    v19 = 0;
    if ( CPrintDialog::GetDefaults(this: &pd) != 0 )
    {
      if ( pd.m_pd->hDevNames != nullptr )
      {
        m_pszData = CPrintDialog::GetDriverName(this: &pd, &result)->m_pszData;
        v7 = (char *)v3 + *v3;
        LOBYTE(v19) = 1;
        v18 = 1;
        if ( lstrcmpA(lpString1: v7, lpString2: m_pszData) != 0 )
          goto LABEL_15;
        v11 = CPrintDialog::GetDeviceName(this: &pd, result: &v17)->m_pszData;
        v8 = (char *)v3 + v3[1];
        v19 = 2;
        v18 = 3;
        if ( lstrcmpA(lpString1: v8, lpString2: v11) != 0
          || (v12 = CPrintDialog::GetPortName(this: &pd, result: &v15)->m_pszData,
              v9 = (char *)v3 + v3[2],
              v18 = 7,
              bForceDefaults_3 = 0,
              lstrcmpA(lpString1: v9, lpString2: v12) != 0) )
        {
LABEL_15:
          bForceDefaults_3 = 1;
        }
        if ( (v18 & 4) != 0 )
        {
          v18 &= ~4u;
          ATL::CStringData::Release(this: (ATL::CStringData *)v15.m_pszData - 1);
        }
        if ( (v18 & 2) != 0 )
        {
          v18 &= ~2u;
          ATL::CStringData::Release(this: (ATL::CStringData *)v17.m_pszData - 1);
        }
        v19 = 0;
        if ( (v18 & 1) != 0 )
          ATL::CStringData::Release(this: (ATL::CStringData *)result.m_pszData - 1);
        if ( bForceDefaults_3 != 0 )
        {
          if ( this->m_hDevMode != nullptr )
            AfxGlobalFree(hGlobal: this->m_hDevMode);
          AfxGlobalFree(hGlobal: this->m_hDevNames);
          v5 = pd.m_pd;
          this->m_hDevMode = pd.m_pd->hDevMode;
          this->m_hDevNames = v5->hDevNames;
        }
        else
        {
          if ( pd.m_pd->hDevMode != nullptr )
            AfxGlobalFree(hGlobal: pd.m_pd->hDevMode);
          if ( pd.m_pd->hDevNames != nullptr )
            AfxGlobalFree(hGlobal: pd.m_pd->hDevNames);
        }
      }
      else
      {
        if ( this->m_hDevMode != nullptr )
          AfxGlobalFree(hGlobal: this->m_hDevMode);
        AfxGlobalFree(hGlobal: this->m_hDevNames);
        this->m_hDevMode = nullptr;
        this->m_hDevNames = nullptr;
      }
    }
    pd.__vftable = (CPrintDialog_vtbl *)&CCommonDialog::`vftable';
    p_pd = &pd;
LABEL_35:
    v19 = -1;
    CDialog::~CDialog(this: p_pd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034EC69
// Name: public: int CWinApp::DoPrintDialog(class CPrintDialog __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::DoPrintDialog(CWinApp *this, CPrintDialog *pPD)
{
  AFX_MODULE_STATE *ModuleState; // eax
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx

  if ( pPD == nullptr )
    AfxThrowInvalidArgException();
  CWinApp::UpdatePrinterSelection(this, bForceDefaults: 0);
  pPD->m_pd->hDevMode = this->m_hDevMode;
  pPD->m_pd->hDevNames = this->m_hDevNames;
  while ( 1 )
  {
    v5 = pPD->DoModal(this: pPD);
    v6 = v5;
    if ( v5 == 1 || v5 == 2 )
      break;
    ModuleState = AfxGetModuleState();
    v4 = CCommDlgWrapper::_CommDlgExtendedError(this: *((CCommDlgWrapper **)ModuleState->m_pDllIsolationWrappers + 1));
    if ( v4 != 4105 && v4 - 4107 > 1 )
      return v6;
    if ( pPD->m_pd->hDevNames != nullptr )
    {
      AfxGlobalFree(hGlobal: pPD->m_pd->hDevNames);
      pPD->m_pd->hDevNames = nullptr;
      this->m_hDevNames = nullptr;
    }
    if ( pPD->m_pd->hDevMode != nullptr )
    {
      AfxGlobalFree(hGlobal: pPD->m_pd->hDevMode);
      pPD->m_pd->hDevMode = nullptr;
      this->m_hDevMode = nullptr;
    }
  }
  this->m_hDevMode = pPD->m_pd->hDevMode;
  this->m_hDevNames = pPD->m_pd->hDevNames;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1034ED38
// Name: protected: void CWinApp::OnFilePrintSetup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::OnFilePrintSetup(CWinApp *this)
{
  CPrintDialog pd; // [esp+10h] [ebp-E8h] BYREF
  int v3; // [esp+F4h] [ebp-4h]

  CPrintDialog::CPrintDialog(this: &pd, bPrintSetupOnly: 1, dwFlags: 0x14000Cu, pParentWnd: nullptr);
  v3 = 0;
  CWinApp::DoPrintDialog(this, pPD: &pd);
  v3 = -1;
  pd.__vftable = (CPrintDialog_vtbl *)&CCommonDialog::`vftable';
  CDialog::~CDialog(this: &pd);
}

//------------------------------------------------------------------------------
// Address: 0x1034ED8E
// Name: public: int CWinApp::GetPrinterDeviceDefaults(struct tagPDA __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWinApp::GetPrinterDeviceDefaults(CWinApp *this, tagPDA *pPrintDlg)
{
  CWinApp::UpdatePrinterSelection(this, bForceDefaults: this->m_hDevNames == nullptr);
  if ( this->m_hDevNames == nullptr )
    return 0;
  if ( pPrintDlg == nullptr )
    AfxThrowInvalidArgException();
  pPrintDlg->hDevNames = this->m_hDevNames;
  pPrintDlg->hDevMode = this->m_hDevMode;
  GlobalUnlock(hMem: this->m_hDevNames);
  GlobalUnlock(hMem: this->m_hDevMode);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1035DFA3
// Name: long ATL::AtlHresultFromLastError(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __cdecl ATL::AtlHresultFromLastError()
{
  HRESULT result; // eax

  result = GetLastError();
  if ( result > 0 )
    return (unsigned __int16)result | 0x80070000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1035DFB8
// Name: long ATL::AtlGetDllVersion(struct HINSTANCE__ __near *,struct _DLLVERSIONINFO __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __cdecl ATL::AtlGetDllVersion(HINSTANCE__ *hInstDLL, _DLLVERSIONINFO *pDllVersionInfo)
{
  FARPROC DllGetVersion; // eax

  if ( pDllVersionInfo == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  DllGetVersion = GetProcAddress(hModule: hInstDLL, lpProcName: "DllGetVersion");
  if ( DllGetVersion != nullptr )
    return ((HRESULT (__stdcall *)(_DLLVERSIONINFO *))DllGetVersion)(a1: pDllVersionInfo);
  else
    return -2147467263;
}

//------------------------------------------------------------------------------
// Address: 0x1035DFED
// Name: long ATL::AtlGetDllVersion(char const __near *,struct _DLLVERSIONINFO __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __cdecl ATL::AtlGetDllVersion(const char *lpstrDllName, _DLLVERSIONINFO *pDllVersionInfo)
{
  HMODULE LibraryA; // eax
  HMODULE v3; // esi
  HRESULT DllVersion; // edi

  LibraryA = LoadLibraryA(lpLibFileName: lpstrDllName);
  v3 = LibraryA;
  if ( LibraryA == nullptr )
    return ATL::AtlHresultFromLastError();
  DllVersion = ATL::AtlGetDllVersion(hInstDLL: LibraryA, pDllVersionInfo);
  FreeLibrary(hLibModule: v3);
  return DllVersion;
}

//------------------------------------------------------------------------------
// Address: 0x1035E024
// Name: long ATL::AtlGetCommCtrlVersion(unsigned long __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
HRESULT __cdecl ATL::AtlGetCommCtrlVersion(unsigned int *pdwMajor, unsigned int *pdwMinor)
{
  HRESULT result; // eax
  _DLLVERSIONINFO dvi; // [esp+8h] [ebp-18h] BYREF

  if ( pdwMajor == nullptr || pdwMinor == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  memset(dst: (unsigned __int8 *)&dvi, value: 0, count: sizeof(dvi));
  dvi.cbSize = 20;
  result = ATL::AtlGetDllVersion(lpstrDllName: "comctl32.dll", pDllVersionInfo: &dvi);
  if ( result >= 0 )
  {
    *pdwMajor = dvi.dwMajorVersion;
    *pdwMinor = dvi.dwMinorVersion;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1035FF66
// Name: public: void CWinApp::SetCurrentHandles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWinApp::SetCurrentHandles(CWinApp *this)
{
  AFX_MODULE_STATE *ModuleState; // ebx
  DWORD ModuleFileNameA; // eax
  const char *v4; // eax
  const char *v5; // eax
  int v6; // eax
  const char *v7; // eax
  int v8; // eax
  const char *v9; // eax
  LPSTR lpszExt; // [esp+Ch] [ebp-410h]
  char szTitle[256]; // [esp+10h] [ebp-40Ch] BYREF
  char szAppID[256]; // [esp+110h] [ebp-30Ch] BYREF
  char szExeName[260]; // [esp+210h] [ebp-20Ch] BYREF
  char szBuff[260]; // [esp+314h] [ebp-108h] BYREF
  int v15; // [esp+418h] [ebp-4h] BYREF

  ModuleState = AfxGetModuleState();
  ModuleState->m_hCurrentInstanceHandle = this->m_hInstance;
  ModuleState->m_hCurrentResourceHandle = this->m_hInstance;
  ModuleFileNameA = GetModuleFileNameA(hModule: this->m_hInstance, lpFilename: szBuff, nSize: 0x104u);
  if ( ModuleFileNameA == 0 || ModuleFileNameA == 260 )
    AfxThrowUserException();
  lpszExt = PathFindExtensionA(pszPath: szBuff);
  if ( lpszExt == nullptr )
    AfxThrowUserException();
  *lpszExt = 0;
  if ( AfxGetFileName(lpszPathName: szBuff, lpszTitle: szExeName, nMax: 0x104u) != 0 )
    AfxThrowUserException();
  if ( this->m_pszExeName == nullptr )
  {
    v4 = _strdup(string: szExeName);
    this->m_pszExeName = v4;
    if ( v4 == nullptr )
      goto LABEL_10;
  }
  if ( this->m_pszAppName == nullptr )
  {
    v5 = AfxLoadString(nID: 0xE000u, lpszBuf: szTitle, nMaxBuf: 0x100u) != 0
       ? _strdup(string: szTitle)
       : _strdup(string: this->m_pszExeName);
    this->m_pszAppName = v5;
    if ( v5 == nullptr )
      goto LABEL_10;
  }
  if ( this->m_pszAppID == nullptr )
  {
    this->m_pszAppID = AfxLoadString(nID: 0xE006u, lpszBuf: szAppID, nMaxBuf: 0x100u) != 0
                     ? _strdup(string: szAppID)
                     : &var;
    if ( this->m_pszAppID == nullptr )
      goto LABEL_10;
  }
  ModuleState->m_lpszCurrentAppName = this->m_pszAppName;
  if ( this->m_pszHelpFilePath == nullptr )
  {
    if ( this->m_eHelpType == afxHTMLHelp )
      v6 = strcpy_s(_Dst: lpszExt, _SizeInBytes: (char *)&v15 - lpszExt, _Src: ".CHM");
    else
      v6 = strcpy_s(_Dst: lpszExt, _SizeInBytes: (char *)&v15 - lpszExt, _Src: ".HLP");
    AfxCrtErrorCheck(error: v6);
    v7 = _strdup(string: szBuff);
    this->m_pszHelpFilePath = v7;
    if ( v7 != nullptr )
    {
      *lpszExt = 0;
      goto LABEL_27;
    }
LABEL_10:
    AfxThrowMemoryException();
  }
LABEL_27:
  if ( this->m_pszProfileName == nullptr )
  {
    v8 = strcat_s(_Dst: szExeName, _SizeInBytes: 0x104u, _Src: ".INI");
    AfxCrtErrorCheck(error: v8);
    v9 = _strdup(string: szExeName);
    this->m_pszProfileName = v9;
    if ( v9 == nullptr )
      goto LABEL_10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10367C0F
// Name: char __near * ATL::AtlAllocTaskAnsiString(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ATL::AtlAllocTaskAnsiString(const wchar_t *lpszString)
{
  unsigned int v2; // esi
  CHAR *v3; // eax
  CHAR *v4; // edi

  if ( lpszString == nullptr )
    return nullptr;
  v2 = 2 * wcslen(wcs: lpszString) + 2;
  v3 = (CHAR *)CoTaskMemAlloc(cb: v2);
  v4 = v3;
  if ( v3 != nullptr
    && WideCharToMultiByte(
         CodePage: 0,
         dwFlags: 0,
         lpWideCharStr: lpszString,
         cchWideChar: -1,
         lpMultiByteStr: v3,
         cbMultiByte: v2,
         lpDefaultChar: nullptr,
         lpUsedDefaultChar: nullptr) == 0 )
  {
    CoTaskMemFree(pv: v4);
    return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10368000
// Name: public: virtual class CDocument __near * CDocManager::OpenDocumentFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDocument *__thiscall CDocManager::OpenDocumentFile(CDocManager *this, const char *lpszFileName)
{
  return this->OpenDocumentFile(this, a2: lpszFileName, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10368168
// Name: public: virtual void CDocManager::CloseAllDocuments(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocManager::CloseAllDocuments(CDocManager *this, int bEndSession)
{
  CPtrList::CNode *m_pNodeHead; // esi
  void *data; // ecx

  m_pNodeHead = this->m_templateList.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)data + 124))(a1: data, a2: bEndSession);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036826D
// Name: public: virtual class CDocument __near * CDocManager::OpenDocumentFile(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CDocument *__thiscall CDocManager::OpenDocumentFile(CDocManager *this, const char *lpszFileName, int bAddToMRU)
{
  const char *v3; // eax
  bool v4; // zf
  CPtrList::CNode *m_pNodeHead; // esi
  int v6; // eax
  _BYTE *v7; // eax
  CWnd *MainWnd; // eax
  int v10; // eax
  __POSITION *data; // edi
  int v12; // eax
  CView *v13; // eax
  CFrameWnd *ParentFrame; // eax
  CFrameWnd *v15; // esi
  HWND Parent; // eax
  CWnd *m_pMainWnd; // ecx
  CDocTemplate::Confidence bestMatch; // [esp+10h] [ebp-31Ch]
  CDocument *pOpenDocument; // [esp+14h] [ebp-318h] BYREF
  __POSITION *posOpenDoc; // [esp+18h] [ebp-314h] BYREF
  char szLinkName[260]; // [esp+1Ch] [ebp-310h] BYREF
  char szTemp[260]; // [esp+120h] [ebp-20Ch] BYREF
  char szPath[260]; // [esp+224h] [ebp-108h] BYREF

  v3 = lpszFileName;
  if ( lpszFileName == nullptr )
    AfxThrowInvalidArgException();
  v4 = *lpszFileName == 34;
  m_pNodeHead = this->m_templateList.m_pNodeHead;
  bestMatch = noAttempt;
  posOpenDoc = nullptr;
  pOpenDocument = nullptr;
  if ( v4 )
    v3 = lpszFileName + 1;
  v6 = _mbsnbcpy_s(
         _Arg1: (unsigned __int8 *)szTemp,
         _Arg2: 0x104u,
         _Arg3: (const unsigned __int8 *)v3,
         _Arg4: 0xFFFFFFFF);
  AfxCrtErrorCheck(error: v6);
  _mbsrchr(str: (unsigned __int8 *)szTemp, c: 0x22u);
  if ( v7 != nullptr )
    *v7 = 0;
  if ( AfxFullPath(lpszPathOut: szPath, lpszFileIn: szTemp) == 0 )
    return nullptr;
  MainWnd = AfxGetMainWnd();
  if ( AfxResolveShortcut(pWnd: MainWnd, lpszFileIn: (wchar_t *)szPath, lpszFileOut: szLinkName, cchPath: 260) != 0 )
  {
    v10 = strcpy_s(_Dst: szPath, _SizeInBytes: 0x104u, _Src: szLinkName);
    AfxCrtErrorCheck(error: v10);
  }
  do
  {
    if ( m_pNodeHead == nullptr )
      break;
    data = (__POSITION *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    v12 = (*(int (__thiscall **)(__POSITION *, char *, CDocument **))(*(_DWORD *)data + 104))(
            a1: data,
            a2: szPath,
            a3: &pOpenDocument);
    if ( v12 > bestMatch )
    {
      bestMatch = v12;
      posOpenDoc = data;
    }
  }
  while ( v12 != 5 );
  if ( pOpenDocument != nullptr )
  {
    posOpenDoc = pOpenDocument->GetFirstViewPosition(this: pOpenDocument);
    if ( posOpenDoc != nullptr )
    {
      v13 = pOpenDocument->GetNextView(this: pOpenDocument, a2: &posOpenDoc);
      ParentFrame = CWnd::GetParentFrame(this: v13);
      v15 = ParentFrame;
      if ( ParentFrame != nullptr )
      {
        ParentFrame->ActivateFrame(this: ParentFrame, a2: -1);
        Parent = GetParent(hWnd: v15->m_hWnd);
        if ( CWnd::FromHandle(hWnd: Parent) != nullptr )
        {
          m_pMainWnd = AfxGetModuleState()->m_pCurrentWinApp->m_pMainWnd;
          if ( v15 != m_pMainWnd )
            m_pMainWnd->__vftable[1].GetDispatchIID(this: m_pMainWnd, a2: (_GUID *)-1);
        }
      }
    }
    return pOpenDocument;
  }
  else
  {
    if ( posOpenDoc == nullptr )
    {
      AfxMessageBox(nIDPrompt: 0xF101u, nType: 0, nIDHelp: 0xFFFFFFFF);
      return nullptr;
    }
    return (*(CDocument *(__thiscall **)(__POSITION *, char *, int, int))(*(_DWORD *)posOpenDoc + 128))(
             a1: posOpenDoc,
             a2: szPath,
             a3: bAddToMRU,
             a4: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10368692
// Name: public: virtual void CDocManager::OnFileOpen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDocManager::OnFileOpen(CDocManager *this)
{
  CAfxStringMgr *StringManager; // eax
  CDocManager_vtbl *v3; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > newName; // [esp+10h] [ebp-10h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &newName, pStringMgr: StringManager);
  v3 = this->__vftable;
  v6 = 0;
  if ( v3->DoPromptFileName(this, a2: &newName, a3: 61440u, a4: 4100u, a5: 1, a6: nullptr) != 0 )
  {
    ModuleState = AfxGetModuleState();
    ModuleState->m_pCurrentWinApp->OpenDocumentFile(this: ModuleState->m_pCurrentWinApp, a2: newName.m_pszData);
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)newName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1036BF63
// Name: int ATL::AtlConvertSystemTimeToVariantTime(struct _SYSTEMTIME const __near &,double __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
BOOL __cdecl ATL::AtlConvertSystemTimeToVariantTime(const _SYSTEMTIME *systimeSrc, long double *pVarDtTm)
{
  INT v2; // ebx
  _SYSTEMTIME dst; // [esp+14h] [ebp-14h] OVERLAPPED BYREF

  if ( pVarDtTm == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  v2 = SystemTimeToVariantTime(lpSystemTime: systimeSrc, pvtime: pVarDtTm);
  memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
  return v2 != 0
      && VariantTimeToSystemTime(vtime: *pVarDtTm, lpSystemTime: &dst) != 0
      && systimeSrc->wYear == dst.wYear
      && systimeSrc->wMonth == dst.wMonth
      && systimeSrc->wDay == dst.wDay
      && systimeSrc->wHour == dst.wHour
      && systimeSrc->wMinute == dst.wMinute
      && systimeSrc->wSecond == dst.wSecond;
}

//------------------------------------------------------------------------------
// Address: 0x105C5991
// Name: ATL::_dynamic_initializer_for___AtlBaseModule__
// Source: json
//------------------------------------------------------------------------------
int ATL::_dynamic_initializer_for___AtlBaseModule__()
{
  ATL::CAtlBaseModule::CAtlBaseModule(this: &ATL::_AtlBaseModule);
  return atexit(func: ATL::_dynamic_atexit_destructor_for___AtlBaseModule__);
}

//------------------------------------------------------------------------------
// Address: 0x105CC891
// Name: ATL::_dynamic_atexit_destructor_for___AtlBaseModule__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ATL::_dynamic_atexit_destructor_for___AtlBaseModule__()
{
  ATL::CAtlBaseModule::~CAtlBaseModule(this: &ATL::_AtlBaseModule);
}

//------------------------------------------------------------------------------
// Address: 0x1003CE70
// Name: __CreateCHammerIHammer_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CTier3AppSystem<IHammer,0> *__cdecl _CreateCHammerIHammer_interface()
{
  return &theApp.CTier3AppSystem<IHammer,0>;
}

//------------------------------------------------------------------------------
// Address: 0x103398F1
// Name: int _AfxModifyStyle(struct HWND__ __near *,int,unsigned long,unsigned long,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _AfxModifyStyle(
        HWND__ *hWnd,
        int nStyleOffset,
        unsigned int dwRemove,
        unsigned int dwAdd,
        unsigned int nFlags)
{
  LONG WindowLongA; // eax

  WindowLongA = GetWindowLongA(hWnd, nIndex: nStyleOffset);
  if ( WindowLongA == (dwAdd | WindowLongA & ~dwRemove) )
    return 0;
  SetWindowLongA(hWnd, nIndex: nStyleOffset, dwNewLong: dwAdd | WindowLongA & ~dwRemove);
  if ( nFlags != 0 )
    SetWindowPos(hWnd, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: 0, cy: 0, uFlags: nFlags | 0x17);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1033DA93
// Name: public: virtual CMFCComObject<class ATL::CAccessibleProxy>::~CMFCComObject<class ATL::CAccessibleProxy>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCComObject<ATL::CAccessibleProxy>::~CMFCComObject<ATL::CAccessibleProxy>(
        CMFCComObject<ATL::CAccessibleProxy> *this)
{
  this->ATL::CAccessibleProxy::ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::IAccessible::IDispatch::IUnknown::__vftable = (CMFCComObject<ATL::CAccessibleProxy>_vtbl *)&CMFCComObject<ATL::CAccessibleProxy>::`vftable'{for `IAccessible'};
  this->ATL::CAccessibleProxy::ATL::IAccessibleProxyImpl<ATL::CAccessibleProxy>::IAccessibleProxy::IUnknown::__vftable = (IAccessibleProxy_vtbl *)&CMFCComObject<ATL::CAccessibleProxy>::`vftable'{for `IAccessibleProxy'};
  this->ATL::CAccessibleProxy::IOleWindow::IUnknown::__vftable = (IOleWindow_vtbl *)&CMFCComObject<ATL::CAccessibleProxy>::`vftable';
  this->m_dwRef = -1073741823;
  ATL::CAccessibleProxy::FinalRelease(this);
  AfxOleUnlockApp();
}

//------------------------------------------------------------------------------
// Address: 0x1033DAB8
// Name: public: virtual unsigned long CMFCComObject<class ATL::CAccessibleProxy>::AddRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CMFCComObject<ATL::CAccessibleProxy>::AddRef(CMFCComObject<ATL::CAccessibleProxy> *this)
{
  return ++this->m_dwRef;
}

//------------------------------------------------------------------------------
// Address: 0x1033DACA
// Name: public: virtual unsigned long CMFCComObject<class ATL::CAccessibleProxy>::Release(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CMFCComObject<ATL::CAccessibleProxy>::Release(CMFCComObject<ATL::CAccessibleProxy> *this)
{
  bool v1; // zf
  int m_dwRef; // esi

  v1 = this->m_dwRef-- == 1;
  m_dwRef = this->m_dwRef;
  if ( v1 && this != nullptr )
    ((void (__thiscall *)(CMFCComObject<ATL::CAccessibleProxy> *, int))this->dtr_CAccessibleProxy)(a1: this, a2: 1);
  return m_dwRef;
}

//------------------------------------------------------------------------------
// Address: 0x1033DAED
// Name: public: virtual long CMFCComObject<class ATL::CAccessibleProxy>::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CMFCComObject<ATL::CAccessibleProxy>::QueryInterface(
        CMFCComObject<ATL::CAccessibleProxy> *this,
        const _GUID *iid,
        void **ppvObject)
{
  return ATL::AtlInternalQueryInterface(
           pThis: (char *)this,
           pEntries: &`ATL::CAccessibleProxy::_GetEntries'::`2'::_entries,
           iid,
           ppvObject);
}

//------------------------------------------------------------------------------
// Address: 0x1033DB66
// Name: void _AfxHandleActivate(class CWnd __near *,unsigned int,class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _AfxHandleActivate(CWnd *pWnd, WPARAM nState, CWnd *pWndOther)
{
  CWnd *TopLevelParent; // ebx
  HWND__ *hWnd2[2]; // [esp+4h] [ebp-8h] BYREF

  if ( (CWnd::GetStyle(this: pWnd) & 0x40000000) == 0 )
  {
    TopLevelParent = CWnd::GetTopLevelParent(this: pWnd);
    if ( TopLevelParent != nullptr
      && (pWndOther == nullptr
       || !IsWindow(hWnd: pWndOther->m_hWnd)
       || TopLevelParent != CWnd::GetTopLevelParent(this: pWndOther)) )
    {
      hWnd2[0] = pWnd->m_hWnd;
      if ( pWndOther != nullptr )
        hWnd2[1] = pWndOther->m_hWnd;
      else
        hWnd2[1] = nullptr;
      SendMessageA(hWnd: TopLevelParent->m_hWnd, Msg: 0x36Eu, wParam: nState, lParam: (LPARAM)hWnd2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1033DBDE
// Name: int _AfxHandleSetCursor(class CWnd __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _AfxHandleSetCursor(CWnd *pWnd, unsigned int nHitTest, unsigned int nMsg)
{
  CWnd *TopLevelParent; // eax
  HWND LastActivePopup; // eax
  CWnd *v5; // esi
  HWND ForegroundWindow; // eax

  if ( nHitTest != -2 || nMsg != 513 && nMsg != 519 && nMsg != 516 )
    return 0;
  TopLevelParent = CWnd::GetTopLevelParent(this: pWnd);
  if ( TopLevelParent == nullptr )
    return 0;
  LastActivePopup = GetLastActivePopup(hWnd: TopLevelParent->m_hWnd);
  v5 = CWnd::FromHandle(hWnd: LastActivePopup);
  if ( v5 == nullptr )
    return 0;
  ForegroundWindow = GetForegroundWindow();
  if ( v5 == CWnd::FromHandle(hWnd: ForegroundWindow) || CWnd::IsWindowEnabled(this: v5) == 0 )
    return 0;
  SetForegroundWindow(hWnd: v5->m_hWnd);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1033DC56
// Name: long _AfxActivationWndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LRESULT __stdcall _AfxActivationWndProc(HWND hWnd, UINT nMsg, WPARAM wParam, unsigned int lParam)
{
  CWnd *v4; // esi
  ATOM AtomA; // ax
  CWnd *v7; // eax
  CWnd *v8; // esi
  CWnd *v9; // eax
  int (__stdcall *lpPrevWndFunc)(HWND__ *, unsigned int, unsigned int, int); // [esp+38h] [ebp-30h]
  unsigned int pdwStyleOld; // [esp+3Ch] [ebp-2Ch] BYREF
  LRESULT v12; // [esp+40h] [ebp-28h]
  tagRECT RectOld; // [esp+44h] [ebp-24h] BYREF
  int v14; // [esp+64h] [ebp-4h]

  lpPrevWndFunc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))GetPropA(
                                                                                  hWnd,
                                                                                  lpString: "AfxOldWndProc423");
  v12 = 0;
  v14 = 0;
  pdwStyleOld = 1;
  switch ( nMsg )
  {
    case 6u:
      v8 = CWnd::FromHandle(hWnd: (HWND__ *)lParam);
      v9 = CWnd::FromHandle(hWnd);
      _AfxHandleActivate(pWnd: v9, nState: wParam, pWndOther: v8);
LABEL_10:
      if ( pdwStyleOld == 0 )
        return v12;
      return CallWindowProcA(lpPrevWndFunc, hWnd, Msg: nMsg, wParam, lParam);
    case 0x20u:
      v7 = CWnd::FromHandle(hWnd);
      pdwStyleOld = _AfxHandleSetCursor(pWnd: v7, nHitTest: (__int16)lParam, nMsg: HIWORD(lParam)) == 0;
      goto LABEL_10;
    case 0x82u:
      SetWindowLongA(hWnd, nIndex: -4, dwNewLong: (LONG)lpPrevWndFunc);
      RemovePropA(hWnd, lpString: "AfxOldWndProc423");
      AtomA = GlobalFindAtomA(lpString: "AfxOldWndProc423");
      GlobalDeleteAtom(nAtom: AtomA);
      return CallWindowProcA(lpPrevWndFunc, hWnd, Msg: nMsg, wParam, lParam);
    default:
      break;
  }
  if ( nMsg != 272 )
    return CallWindowProcA(lpPrevWndFunc, hWnd, Msg: nMsg, wParam, lParam);
  memset(&RectOld, 0, sizeof(RectOld));
  v4 = CWnd::FromHandle(hWnd);
  _AfxPreInitDialog(pWnd: v4, lpRectOld: &RectOld, &pdwStyleOld);
  v12 = CallWindowProcA(lpPrevWndFunc, hWnd, Msg: 0x110u, wParam, lParam);
  _AfxPostInitDialog(pWnd: v4, rectOld: &RectOld, dwStyleOld: pdwStyleOld);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1033DDBD
// Name: long _AfxCbtFilterHook(int,unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LRESULT __stdcall _AfxCbtFilterHook(int code, HWND__ *wParam, int *lParam)
{
  CNoTrackObject *Data; // eax
  int v5; // edi
  CWnd *v6; // esi
  int m_bDLL; // eax
  const char *v8; // eax
  LRESULT (__stdcall **v9)(HWND__ *, CNoTrackObject_vtbl *, CNoTrackObject_vtbl *, CNoTrackObject_vtbl *); // edi
  LRESULT (__stdcall *v10)(HWND__ *, CNoTrackObject_vtbl *, CNoTrackObject_vtbl *, CNoTrackObject_vtbl *); // eax
  HANDLE PropA; // eax
  CNoTrackObject *v12; // edi
  LRESULT v13; // esi
  ATOM v14; // [esp-Ch] [ebp-170h]
  tagWNDCLASSEXA dst; // [esp+10h] [ebp-154h] BYREF
  int v16; // [esp+40h] [ebp-124h]
  LPARAM v17; // [esp+44h] [ebp-120h]
  CNoTrackObject *v18; // [esp+48h] [ebp-11Ch]
  CHAR ClassName[256]; // [esp+4Ch] [ebp-118h] BYREF
  AFX_MAINTAIN_STATE2 Buffer[2]; // [esp+14Ch] [ebp-18h] BYREF
  int v21; // [esp+160h] [ebp-4h]

  v17 = (LPARAM)lParam;
  Data = CThreadLocalObject::GetData(
           this: &_afxThreadState,
           pfnCreateObject: CThreadLocal<_AFX_THREAD_STATE>::CreateObject);
  v18 = Data;
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  if ( code != 3 )
    return CallNextHookEx(hhk: (HHOOK)Data[10].__vftable, nCode: code, (WPARAM)wParam, (LPARAM)lParam);
  v5 = *lParam;
  v6 = (CWnd *)Data[5].__vftable;
  m_bDLL = AfxGetModuleState()->m_bDLL;
  v16 = m_bDLL;
  if ( v6 != nullptr || (*(_DWORD *)(v5 + 32) & 0x40000000) == 0 && m_bDLL == 0 )
  {
    if ( _afxDBCS == 0 )
      goto LABEL_13;
    if ( (GetClassLongA(hWnd: wParam, nIndex: -26) & 0x10000) == 0 )
    {
      v8 = *(const char **)(v5 + 40);
      if ( (unsigned int)v8 <= 0xFFFF )
      {
        v14 = *(_WORD *)(v5 + 40);
        LOBYTE(Buffer[0].m_ulActCtxCookie) = 0;
        GlobalGetAtomNameA(nAtom: v14, lpBuffer: (LPSTR)Buffer, nSize: 5);
        v8 = (const char *)Buffer;
      }
      if ( AfxInvariantStrICmp(pszLeft: v8, pszRight: "ime") != 0 )
      {
LABEL_13:
        if ( v6 != nullptr )
        {
          AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: Buffer, pNewState: v6->m_pModuleState);
          v21 = 0;
          CWnd::Attach(this: v6, hWndNew: wParam);
          v6->PreSubclassWindow(this: v6);
          v9 = (LRESULT (__stdcall **)(HWND__ *, CNoTrackObject_vtbl *, CNoTrackObject_vtbl *, CNoTrackObject_vtbl *))v6->GetSuperWndProcAddr(this: v6);
          v10 = (LRESULT (__stdcall *)(HWND__ *, CNoTrackObject_vtbl *, CNoTrackObject_vtbl *, CNoTrackObject_vtbl *))SetWindowLongA(hWnd: wParam, nIndex: -4, dwNewLong: (LONG)AfxWndProc);
          if ( v10 != AfxWndProc )
            *v9 = v10;
          v18[5].__vftable = nullptr;
          v21 = -1;
          AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: Buffer);
          goto lCallNextHook;
        }
        if ( s_atomMenu != 0
          || (memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst)),
              dst.cbSize = 48,
              s_atomMenu = AfxCtxGetClassInfoExA(unnamed1: nullptr, unnamed2: "#32768", unnamed3: &dst),
              s_atomMenu != 0) )
        {
          if ( (unsigned __int16)GetClassLongA(hWnd: wParam, nIndex: -32) == s_atomMenu )
            goto lCallNextHook;
LABEL_23:
          Buffer[0].m_bValidActCtxCookie = GetWindowLongA(hWnd: wParam, nIndex: -4);
          if ( Buffer[0].m_bValidActCtxCookie != 0 && GetPropA(hWnd: wParam, lpString: "AfxOldWndProc423") == nullptr )
          {
            SetPropA(hWnd: wParam, lpString: "AfxOldWndProc423", hData: (HANDLE)Buffer[0].m_bValidActCtxCookie);
            PropA = GetPropA(hWnd: wParam, lpString: "AfxOldWndProc423");
            if ( PropA == (HANDLE)Buffer[0].m_bValidActCtxCookie )
            {
              GlobalAddAtomA(lpString: "AfxOldWndProc423");
              SetWindowLongA(hWnd: wParam, nIndex: -4, dwNewLong: (LONG)_AfxActivationWndProc);
            }
          }
          goto lCallNextHook;
        }
        if ( GetClassNameA(hWnd: wParam, lpClassName: ClassName, nMaxCount: 256) == 0 )
          goto LABEL_23;
        ClassName[255] = 0;
        if ( _mbscmp(s1: (const unsigned __int8 *)ClassName, s2: "#32768") != 0 )
          goto LABEL_23;
      }
    }
  }
lCallNextHook:
  v12 = v18;
  v13 = CallNextHookEx(hhk: (HHOOK)v18[10].__vftable, nCode: 3, (WPARAM)wParam, lParam: v17);
  if ( v16 != 0 )
  {
    UnhookWindowsHookEx(hhk: (HHOOK)v12[10].__vftable);
    v12[10].__vftable = nullptr;
  }
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x1033E004
// Name: void AfxHookWindowCreate(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxHookWindowCreate(CWnd *pWnd)
{
  CNoTrackObject *Data; // eax
  CNoTrackObject *v2; // esi
  DWORD CurrentThreadId; // eax
  HHOOK v4; // eax

  Data = CThreadLocalObject::GetData(
           this: &_afxThreadState,
           pfnCreateObject: CThreadLocal<_AFX_THREAD_STATE>::CreateObject);
  v2 = Data;
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  if ( (CWnd *)Data[5].__vftable != pWnd )
  {
    if ( Data[10].__vftable == nullptr )
    {
      CurrentThreadId = GetCurrentThreadId();
      v4 = SetWindowsHookExA(idHook: 5, lpfn: (HOOKPROC)_AfxCbtFilterHook, hmod: nullptr, dwThreadId: CurrentThreadId);
      v2[10].__vftable = (CNoTrackObject_vtbl *)v4;
      if ( v4 == nullptr )
        AfxThrowMemoryException();
    }
    v2[5].__vftable = (CNoTrackObject_vtbl *)pWnd;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10340579
// Name: protected: void CFrameWnd::OnClose(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnClose(CFrameWnd *this)
{
  CFrameWnd *v1; // ebx
  int (__stdcall *m_lpfnCloseProc)(CFrameWnd *); // eax
  CDocument *v3; // eax
  _DWORD *v4; // esi
  CWinApp *m_pCurrentWinApp; // edi
  int v6; // ebx
  CWnd *v7; // eax
  __POSITION *pos; // [esp+4h] [ebp-4h] BYREF

  v1 = this;
  m_lpfnCloseProc = this->m_lpfnCloseProc;
  pos = (__POSITION *)this;
  if ( m_lpfnCloseProc != nullptr )
  {
    m_lpfnCloseProc(a1: this);
    return;
  }
  v3 = this->GetActiveDocument(this);
  v4 = &v3->__vftable;
  if ( v3 == nullptr || v3->CanCloseFrame(this: v3, a2: v1) != 0 )
  {
    m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
    if ( m_pCurrentWinApp != nullptr && m_pCurrentWinApp->m_pMainWnd == v1 )
    {
      v6 = (int)m_pCurrentWinApp->GetDataRecoveryHandler(this: m_pCurrentWinApp);
      if ( v6 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 48))(a1: v6) != 0 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 68))(a1: v6);
        (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 56))(a1: v6);
      }
      if ( v4 == nullptr && m_pCurrentWinApp->SaveAllModified(this: m_pCurrentWinApp) == 0 )
        return;
      if ( v6 != 0 && (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 48))(a1: v6) == 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 88))(a1: v6);
      CWinApp::HideApplication(this: m_pCurrentWinApp);
      CWinApp::CloseAllDocuments(this: m_pCurrentWinApp, bEndSession: 0);
      if ( !AfxOleCanExitApp() )
      {
        AfxOleSetUserCtrl(bUserCtrl: 0);
        return;
      }
      if ( AfxGetModuleState()->m_bDLL == 0 && m_pCurrentWinApp->m_pMainWnd == nullptr )
      {
        AfxPostQuitMessage(nExitCode: 0);
        return;
      }
      v1 = (CFrameWnd *)pos;
    }
    if ( v4 != nullptr && v4[39] != 0 )
    {
      pos = (__POSITION *)(*(int (__thiscall **)(_DWORD *))(*v4 + 104))(a1: v4);
      if ( pos == nullptr )
      {
LABEL_27:
        (*(void (__thiscall **)(_DWORD *))(*v4 + 132))(a1: v4);
        return;
      }
      while ( 1 )
      {
        v7 = (CWnd *)(*(int (__thiscall **)(_DWORD *, __POSITION **))(*v4 + 108))(a1: v4, a2: &pos);
        if ( v7 == nullptr )
          AfxThrowInvalidArgException();
        if ( CWnd::GetParentFrame(this: v7) != v1 )
          break;
        if ( pos == nullptr )
          goto LABEL_27;
      }
      (*(void (__thiscall **)(_DWORD *, CFrameWnd *))(*v4 + 220))(a1: v4, a2: v1);
    }
    v1->DestroyWindow(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103406C9
// Name: public: virtual int CFrameWnd::OnCmdMsg(unsigned int,int,void __near *,struct AFX_CMDHANDLERINFO __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CFrameWnd::OnCmdMsg(
        CFrameWnd *this,
        unsigned int nID,
        int nCode,
        void *pExtra,
        AFX_CMDHANDLERINFO *pHandlerInfo)
{
  CView *m_pViewActive; // ecx
  CWinApp *m_pCurrentWinApp; // eax
  BOOL v9; // esi
  CPushRoutingFrame push; // [esp+10h] [ebp-18h] BYREF
  int v11; // [esp+24h] [ebp-4h]

  CPushRoutingFrame::CPushRoutingFrame(this: &push, pNewRoutingFrame: this);
  m_pViewActive = this->m_pViewActive;
  v11 = 0;
  if ( m_pViewActive != nullptr
    && m_pViewActive->OnCmdMsg(this: m_pViewActive, a2: nID, a3: nCode, a4: pExtra, a5: pHandlerInfo) != 0
    || CCmdTarget::OnCmdMsg(this, nID, nCode, pExtra, pHandlerInfo) != 0 )
  {
    CPushRoutingFrame::~CPushRoutingFrame(this: &push);
    return true;
  }
  else
  {
    m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
    v9 = m_pCurrentWinApp != nullptr
      && m_pCurrentWinApp->OnCmdMsg(this: m_pCurrentWinApp, a2: nID, a3: nCode, a4: pExtra, a5: pHandlerInfo) != 0;
    CPushRoutingFrame::~CPushRoutingFrame(this: &push);
    return v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10340763
// Name: protected: void CFrameWnd::OnHScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnHScroll(CFrameWnd *this, unsigned int __formal, unsigned int __formala, CScrollBar *a4)
{
  CView *m_pViewActive; // esi
  const tagMSG *CurrentMessage; // eax

  m_pViewActive = this->m_pViewActive;
  if ( m_pViewActive != nullptr )
  {
    CurrentMessage = CWnd::GetCurrentMessage();
    SendMessageA(
      hWnd: m_pViewActive->m_hWnd,
      Msg: 0x114u,
      wParam: CurrentMessage->wParam,
      lParam: CurrentMessage->lParam);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034078D
// Name: protected: void CFrameWnd::OnVScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnVScroll(CFrameWnd *this, unsigned int __formal, unsigned int __formala, CScrollBar *a4)
{
  CView *m_pViewActive; // esi
  const tagMSG *CurrentMessage; // eax

  m_pViewActive = this->m_pViewActive;
  if ( m_pViewActive != nullptr )
  {
    CurrentMessage = CWnd::GetCurrentMessage();
    SendMessageA(
      hWnd: m_pViewActive->m_hWnd,
      Msg: 0x115u,
      wParam: CurrentMessage->wParam,
      lParam: CurrentMessage->lParam);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103407B7
// Name: protected: long CFrameWnd::OnActivateTopLevel(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWnd::OnActivateTopLevel(CFrameWnd *this, unsigned int wParam, int lParam)
{
  BOOL v4; // eax
  CView *m_pViewActive; // ecx

  CWnd::OnActivateTopLevel(this, wParam, __formal: lParam);
  this->ExitHelpMode(this);
  if ( this->m_pNotifyHook != nullptr )
  {
    v4 = (_WORD)wParam != 0 && HIWORD(wParam) == 0;
    this->m_pNotifyHook->OnActivate(this: this->m_pNotifyHook, a2: v4);
  }
  if ( AfxGetThread()->m_pMainWnd == this )
  {
    m_pViewActive = this->m_pViewActive;
    if ( m_pViewActive != nullptr || (m_pViewActive = this->GetActiveFrame(this)->m_pViewActive) != nullptr )
      ((void (__stdcall *)(_DWORD, CView *, CView *))m_pViewActive->OnActivateView)(
        a1: 0,
        a2: m_pViewActive,
        a3: m_pViewActive);
  }
  PostMessageA(hWnd: this->m_hWnd, Msg: 0x36Au, wParam: 0, lParam: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1034084D
// Name: protected: void CFrameWnd::OnActivate(unsigned int,class CWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWnd::OnActivate(CFrameWnd *this, unsigned int nState, CFrameWnd *pWndOther, int bMinimized)
{
  CFrameWnd *TopLevelFrame; // esi
  BOOL v7; // ecx
  CView *m_pViewActive; // esi

  CWnd::Default(this);
  if ( nState == 0 && (this->m_dwMenuBarVisibility & 1) == 0 )
    this->SetMenuBarState(this, a2: 2u);
  if ( (CWnd::GetStyle(this) & 0x40000000) != 0 )
    TopLevelFrame = this;
  else
    TopLevelFrame = CWnd::GetTopLevelFrame(this);
  if ( TopLevelFrame == nullptr )
    AfxThrowInvalidArgException();
  if ( nState != 0 )
    pWndOther = this;
  v7 = pWndOther != nullptr
    && (TopLevelFrame == pWndOther
     || TopLevelFrame == CWnd::GetTopLevelFrame(this: pWndOther)
     && SendMessageA(hWnd: pWndOther->m_hWnd, Msg: 0x36Du, wParam: 0x40u, lParam: 0) != 0);
  TopLevelFrame->m_nFlags &= ~0x20u;
  if ( v7 )
    TopLevelFrame->m_nFlags |= 0x20u;
  CFrameWnd::NotifyFloatingWindows(this, dwFlags: 4 * !v7 + 4);
  m_pViewActive = this->m_pViewActive;
  if ( m_pViewActive != nullptr || (m_pViewActive = this->GetActiveFrame(this)->m_pViewActive) != nullptr )
  {
    if ( nState != 0 && bMinimized == 0 )
      m_pViewActive->OnActivateView(this: m_pViewActive, a2: 1, a3: m_pViewActive, a4: m_pViewActive);
    m_pViewActive->OnActivateFrame(this: m_pViewActive, a2: nState, a3: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10344D55
// Name: void AfxThrowOleException(long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __noreturn AfxThrowOleException(_DWORD *sc)
{
  CException *v1; // eax
  _DWORD *v2; // esi

  v1 = (CException *)operator new(nSize: 0xCu);
  v2 = &v1->__vftable;
  if ( v1 != nullptr )
  {
    CException::CException(this: v1);
    v2[2] = 0;
    *v2 = &COleException::`vftable';
  }
  else
  {
    v2 = nullptr;
  }
  v2[2] = sc;
  sc = v2;
  _CxxThrowException(pExceptionObject: &sc, pThrowInfo: &_TI4PAVCOleException__);
}

//------------------------------------------------------------------------------
// Address: 0x10344DA7
// Name: public: virtual int COleException::GetErrorMessage(char __near *,unsigned int,unsigned int __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleException::GetErrorMessage(
        COleException *this,
        char *lpszError,
        unsigned int nMaxError,
        char *pnHelpContext)
{
  int v5; // eax

  if ( pnHelpContext != nullptr )
    *(_DWORD *)pnHelpContext = 0;
  if ( FormatMessageA(
         dwFlags: 0x1100u,
         lpSource: nullptr,
         dwMessageId: this->m_sc,
         dwLanguageId: 0x800u,
         lpBuffer: (LPSTR)&pnHelpContext,
         nSize: 0,
         Arguments: nullptr) != 0 )
  {
    v5 = _mbsnbcpy_s(
           _Arg1: (unsigned __int8 *)lpszError,
           _Arg2: nMaxError,
           _Arg3: (const unsigned __int8 *)pnHelpContext,
           _Arg4: 0xFFFFFFFF);
    AfxCrtErrorCheck(error: v5);
    LocalFree(hMem: pnHelpContext);
    return 1;
  }
  else
  {
    *lpszError = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10344E09
// Name: void __near * _AfxCopyGlobalMemory(void __near *,void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HGLOBAL __stdcall _AfxCopyGlobalMemory(void *hDest, void *hSource)
{
  SIZE_T v2; // eax
  HGLOBAL v3; // ebx
  void *v5; // esi
  SIZE_T v6; // eax
  unsigned int nSize; // [esp+8h] [ebp-4h]
  void *lpSource; // [esp+14h] [ebp+8h]

  v2 = GlobalSize(hMem: hSource);
  v3 = hDest;
  nSize = v2;
  if ( hDest != nullptr )
  {
    if ( v2 > GlobalSize(hMem: hDest) )
      return nullptr;
  }
  else
  {
    v3 = GlobalAlloc(uFlags: 0x2002u, dwBytes: v2);
    if ( v3 == nullptr )
      return nullptr;
  }
  lpSource = GlobalLock(hMem: hSource);
  v5 = GlobalLock(hMem: v3);
  v6 = GlobalSize(hMem: v3);
  ATL::Checked::memcpy_s(_S1: v5, _S1max: v6, _S2: lpSource, _N: nSize);
  GlobalUnlock(hMem: v3);
  GlobalUnlock(hMem: hSource);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10344E82
// Name: struct tagDVTARGETDEVICE __near * _AfxOleCopyTargetDevice(struct tagDVTARGETDEVICE __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
tagDVTARGETDEVICE *__stdcall _AfxOleCopyTargetDevice(tagDVTARGETDEVICE *ptdSrc)
{
  tagDVTARGETDEVICE *result; // eax
  tagDVTARGETDEVICE *v2; // edi

  if ( ptdSrc == nullptr )
    return nullptr;
  result = (tagDVTARGETDEVICE *)CoTaskMemAlloc(cb: ptdSrc->tdSize);
  v2 = result;
  if ( result != nullptr )
  {
    ATL::Checked::memcpy_s(_S1: result, _S1max: ptdSrc->tdSize, _S2: ptdSrc, _N: ptdSrc->tdSize);
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10344EB8
// Name: void _AfxOleCopyFormatEtc(struct tagFORMATETC __near *,struct tagFORMATETC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _AfxOleCopyFormatEtc(tagFORMATETC *petcDest, tagFORMATETC *petcSrc)
{
  petcDest->cfFormat = petcSrc->cfFormat;
  petcDest->ptd = _AfxOleCopyTargetDevice(ptdSrc: petcSrc->ptd);
  petcDest->dwAspect = petcSrc->dwAspect;
  petcDest->lindex = petcSrc->lindex;
  petcDest->tymed = petcSrc->tymed;
}

//------------------------------------------------------------------------------
// Address: 0x10344EEE
// Name: bool ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl ATL::_ATL_SAFE_ALLOCA_IMPL::_AtlVerifyStackAvailable(unsigned int Size)
{
  void *v1; // esp
  int v3; // [esp+0h] [ebp-34h] BYREF
  unsigned int ptResult; // [esp+10h] [ebp-24h] BYREF
  char v5; // [esp+17h] [ebp-1Dh]
  int *v6; // [esp+1Ch] [ebp-18h]
  int v7; // [esp+30h] [ebp-4h]

  v5 = 1;
  v7 = 0;
  ptResult = 0;
  if ( ATL::AtlAdd<unsigned long>(&ptResult, tLeft: Size, tRight: 0x2000u) < 0 )
    return 0;
  v1 = alloca(ptResult);
  v6 = &v3;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10345977
// Name: public: virtual int CWinThread::Run(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CWinThread::Run(CWinThread *this)
{
  int v2; // eax
  bool v3; // zf
  CWinThread_vtbl *v4; // eax
  _AFX_THREAD_STATE *pState; // [esp+Ch] [ebp-Ch]
  int lIdleCount; // [esp+10h] [ebp-8h]
  int bIdle; // [esp+14h] [ebp-4h]

  pState = AfxGetThreadState();
  bIdle = 1;
  lIdleCount = 0;
LABEL_2:
  while ( bIdle != 0 )
  {
    if ( PeekMessageA(lpMsg: &pState->m_msgCur, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 0) )
      break;
    v2 = this->OnIdle(this, a2: lIdleCount++);
    if ( v2 == 0 )
      bIdle = 0;
  }
  while ( 1 )
  {
    v3 = this->PumpMessage(this) == 0;
    v4 = this->__vftable;
    if ( v3 )
      return v4->ExitInstance(this);
    if ( v4->IsIdleMessage(this, a2: &pState->m_msgCur) != 0 )
    {
      bIdle = 1;
      lIdleCount = 0;
    }
    if ( !PeekMessageA(lpMsg: &pState->m_msgCur, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 0) )
      goto LABEL_2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10345A14
// Name: protected: int CWinThread::DispatchThreadMessageEx(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CWinThread::DispatchThreadMessageEx(CWinThread *this, tagMSG *pMsg)
{
  int v2; // esi
  unsigned int message; // eax
  const AFX_MSGMAP_ENTRY *MessageEntry; // eax
  tagMSG *v5; // ecx
  const AFX_MSGMAP_ENTRY *i; // eax

  v2 = ((int (__fastcall *)(CWinThread *))this->GetMessageMap)(a1: this);
  if ( *(_DWORD *)v2 == 0 )
    return 0;
  while ( 1 )
  {
    message = pMsg->message;
    if ( message >= 0xC000 )
    {
      for ( i = *(const AFX_MSGMAP_ENTRY **)(v2 + 4); ; i = MessageEntry + 1 )
      {
        MessageEntry = AfxFindMessageEntry(lpEntry: i, nMsg: 0xC000u, nCode: 0, nID: 0);
        if ( MessageEntry == nullptr )
          break;
        v5 = pMsg;
        if ( *(_DWORD *)MessageEntry->nSig == pMsg->message )
          goto LDispatch_0;
      }
      goto LABEL_10;
    }
    MessageEntry = AfxFindMessageEntry(lpEntry: *(const AFX_MSGMAP_ENTRY **)(v2 + 4), nMsg: message, nCode: 0, nID: 0);
    if ( MessageEntry != nullptr )
      break;
LABEL_10:
    v2 = (*(int (**)(void))v2)();
    if ( *(_DWORD *)v2 == 0 )
      return 0;
  }
  v5 = pMsg;
LDispatch_0:
  ((void (__thiscall *)(CWinThread *, unsigned int, int))MessageEntry->pfn)(a1: this, a2: v5->wParam, a3: v5->lParam);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10345A92
// Name: public: virtual long CWinThread::ProcessWndProcException(class CException __near *,struct tagMSG const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CWinThread::ProcessWndProcException(CWinThread *this, CException *e, const tagMSG *pMsg)
{
  return AfxInternalProcessWndProcException(__formal: e, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10345A9D
// Name: int IsEnterKey(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl IsEnterKey(tagMSG *lpMsg)
{
  return lpMsg->message == 256 && lpMsg->wParam == 13;
}

//------------------------------------------------------------------------------
// Address: 0x10345ABD
// Name: public: virtual struct CRuntimeClass __near * CWinThread::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CWinThread::GetRuntimeClass(CWinThread *this)
{
  return &CWinThread::classCWinThread;
}

//------------------------------------------------------------------------------
// Address: 0x10345AC3
// Name: int AfxInternalPreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl AfxInternalPreTranslateMessage(tagMSG *pMsg)
{
  CWinThread *m_pCurrentWinThread; // eax
  HWND__ *MainWnd; // eax
  CWnd *v4; // esi
  CWnd *v5; // eax

  m_pCurrentWinThread = AfxGetModuleThreadState()->m_pCurrentWinThread;
  if ( m_pCurrentWinThread != nullptr
    && pMsg->hwnd == nullptr
    && CWinThread::DispatchThreadMessageEx(this: m_pCurrentWinThread, pMsg) != 0 )
  {
    return 1;
  }
  MainWnd = (HWND__ *)AfxGetMainWnd();
  v4 = (CWnd *)MainWnd;
  if ( MainWnd != nullptr )
    MainWnd = *((HWND__ **)MainWnd + 8);
  if ( CWnd::WalkPreTranslateTree(hWndStop: MainWnd, pMsg) != 0 )
    return 1;
  if ( v4 == nullptr )
    return 0;
  v5 = CWnd::FromHandle(hWnd: pMsg->hwnd);
  if ( CWnd::GetTopLevelParent(this: v5) == v4 )
    return 0;
  return v4->PreTranslateMessage(this: v4, a2: pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10345B36
// Name: int AfxPreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl AfxPreTranslateMessage(tagMSG *pMsg)
{
  CWinThread *m_pCurrentWinThread; // ecx

  m_pCurrentWinThread = AfxGetModuleThreadState()->m_pCurrentWinThread;
  if ( m_pCurrentWinThread != nullptr )
    return m_pCurrentWinThread->PreTranslateMessage(this: m_pCurrentWinThread, a2: pMsg);
  else
    return AfxInternalPreTranslateMessage(pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10345B57
// Name: int AfxInternalIsIdleMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl AfxInternalIsIdleMessage(tagMSG *pMsg)
{
  unsigned int message; // eax
  _AFX_THREAD_STATE *ThreadState; // ebx
  int y; // ecx

  message = pMsg->message;
  if ( message != 512 && message != 160 )
    return message != 15 && message != 280;
  ThreadState = AfxGetThreadState();
  if ( CPoint::operator==(this: &ThreadState->m_ptCursorLast, point: pMsg->pt) != 0
    && pMsg->message == ThreadState->m_nMsgLast )
  {
    return false;
  }
  else
  {
    y = pMsg->pt.y;
    ThreadState->m_ptCursorLast.x = pMsg->pt.x;
    ThreadState->m_ptCursorLast.y = y;
    ThreadState->m_nMsgLast = pMsg->message;
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10345BC7
// Name: int AfxIsIdleMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl AfxIsIdleMessage(tagMSG *pMsg)
{
  CWinThread *m_pCurrentWinThread; // ecx

  m_pCurrentWinThread = AfxGetModuleThreadState()->m_pCurrentWinThread;
  if ( m_pCurrentWinThread != nullptr )
    return m_pCurrentWinThread->IsIdleMessage(this: m_pCurrentWinThread, a2: pMsg);
  else
    return AfxInternalIsIdleMessage(pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x10345C09
// Name: public: CWinThread::CWinThread(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWinThread *__thiscall CWinThread::CWinThread(CWinThread *this)
{
  CCmdTarget::CCmdTarget(this);
  this->__vftable = (CWinThread_vtbl *)&CWinThread::`vftable';
  this->m_pThreadParams = nullptr;
  this->m_pfnThreadProc = nullptr;
  CWinThread::CommonConstruct(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10345E75
// Name: void AfxInitThread(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxInitThread()
{
  _AFX_THREAD_STATE *ThreadState; // esi
  DWORD CurrentThreadId; // eax

  if ( AfxGetModuleState()->m_bDLL == 0 )
  {
    ThreadState = AfxGetThreadState();
    CurrentThreadId = GetCurrentThreadId();
    ThreadState->m_hHookOldMsgFilter = SetWindowsHookExA(
                                         idHook: -1,
                                         lpfn: _AfxMsgFilterHook,
                                         hmod: nullptr,
                                         dwThreadId: CurrentThreadId);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10345EA3
// Name: public: virtual int CWinThread::OnIdle(long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CWinThread::OnIdle(CWinThread *this, int lCount)
{
  CWnd *m_pMainWnd; // ebx
  AFX_MODULE_STATE *v3; // eax
  CWnd *i; // esi
  AFX_MODULE_STATE *ModuleState; // eax

  if ( lCount > 0 )
  {
    ModuleState = AfxGetModuleState();
    if ( CThreadLocal<AFX_MODULE_THREAD_STATE>::GetData(this: &ModuleState->m_thread)->m_nTempMapLock == 0 )
    {
      AfxLockTempMaps();
      AfxUnlockTempMaps(bDeleteTemps: 1);
    }
  }
  else
  {
    m_pMainWnd = this->m_pMainWnd;
    if ( m_pMainWnd != nullptr && m_pMainWnd->m_hWnd != nullptr && IsWindowVisible(hWnd: m_pMainWnd->m_hWnd) )
    {
      AfxCallWndProc(
        pWnd: m_pMainWnd,
        hWnd: (CNoTrackObject_vtbl *)m_pMainWnd->m_hWnd,
        nMsg: (CNoTrackObject_vtbl *)0x363,
        wParam: (CNoTrackObject_vtbl *)1,
        lParam: nullptr);
      CWnd::SendMessageToDescendants(
        hWnd: m_pMainWnd->m_hWnd,
        message: 0x363u,
        wParam: 1u,
        lParam: 0,
        bDeep: 1,
        bOnlyPerm: 1);
    }
    v3 = AfxGetModuleState();
    for ( i = (CWnd *)CThreadLocal<AFX_MODULE_THREAD_STATE>::GetData(this: &v3->m_thread)->m_frameList.m_pHead;
          i != nullptr;
          i = (CWnd *)i[1].m_xConnPtContainer.m_vtbl )
    {
      if ( i->m_hWnd != nullptr && i != m_pMainWnd )
      {
        if ( i[1].m_bGestureInited == 0 )
          CWnd::ShowWindow(this: i, nCmdShow: 0);
        if ( IsWindowVisible(hWnd: i->m_hWnd) || i[1].m_bGestureInited >= 0 )
        {
          AfxCallWndProc(
            pWnd: i,
            hWnd: (CNoTrackObject_vtbl *)i->m_hWnd,
            nMsg: (CNoTrackObject_vtbl *)0x363,
            wParam: (CNoTrackObject_vtbl *)1,
            lParam: nullptr);
          CWnd::SendMessageToDescendants(
            hWnd: i->m_hWnd,
            message: 0x363u,
            wParam: 1u,
            lParam: 0,
            bDeep: 1,
            bOnlyPerm: 1);
        }
        if ( i[1].m_bGestureInited > 0 )
          CWnd::ShowWindow(this: i, nCmdShow: i[1].m_bGestureInited);
        i[1].m_bGestureInited = -1;
      }
    }
  }
  return lCount < 1;
}

//------------------------------------------------------------------------------
// Address: 0x10345FE7
// Name: public: long ATL::CAtlTransactionManager::RegOpenKeyExA(struct HKEY__ __near *,char const __near *,unsigned long,unsigned long,struct HKEY__ __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __thiscall ATL::CAtlTransactionManager::RegOpenKeyExA(
        ATL::CAtlTransactionManager *this,
        HKEY__ *hKey,
        const char *lpSubKey,
        DWORD ulOptions,
        REGSAM samDesired,
        HKEY__ **phkResult)
{
  HMODULE ModuleHandleA; // eax
  LSTATUS (__stdcall *RegOpenKeyTransactedA)(HKEY, LPCSTR, DWORD, REGSAM, PHKEY, HANDLE, PVOID); // eax

  if ( this->m_hTransaction != nullptr )
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "Advapi32.dll");
    if ( ModuleHandleA != nullptr )
    {
      RegOpenKeyTransactedA = (LSTATUS (__stdcall *)(HKEY, LPCSTR, DWORD, REGSAM, PHKEY, HANDLE, PVOID))GetProcAddress(hModule: ModuleHandleA, lpProcName: "RegOpenKeyTransactedA");
      if ( RegOpenKeyTransactedA != nullptr )
        return RegOpenKeyTransactedA(
                 hKey,
                 lpSubKey,
                 ulOptions,
                 samDesired,
                 phkResult,
                 hTransaction: this->m_hTransaction,
                 pExtendedParemeter: nullptr);
    }
  }
  else if ( this->m_bFallback != 0 )
  {
    return RegOpenKeyExA(hKey, lpSubKey, ulOptions, samDesired, phkResult);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10346040
// Name: public: long ATL::CAtlTransactionManager::RegDeleteKeyA(struct HKEY__ __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __thiscall ATL::CAtlTransactionManager::RegDeleteKeyA(
        ATL::CAtlTransactionManager *this,
        HKEY__ *hKey,
        const char *lpSubKey)
{
  HMODULE ModuleHandleA; // eax
  LSTATUS (__stdcall *RegDeleteKeyTransactedA)(HKEY, LPCSTR, REGSAM, DWORD, HANDLE, PVOID); // eax

  if ( this->m_hTransaction != nullptr )
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "Advapi32.dll");
    if ( ModuleHandleA != nullptr )
    {
      RegDeleteKeyTransactedA = (LSTATUS (__stdcall *)(HKEY, LPCSTR, REGSAM, DWORD, HANDLE, PVOID))GetProcAddress(
                                                                                                     hModule: ModuleHandleA,
                                                                                                     lpProcName: "RegDeleteKeyTransactedA");
      if ( RegDeleteKeyTransactedA != nullptr )
        return RegDeleteKeyTransactedA(
                 hKey,
                 lpSubKey,
                 samDesired: 0,
                 Reserved: 0,
                 hTransaction: this->m_hTransaction,
                 pExtendedParameter: nullptr);
    }
  }
  else if ( this->m_bFallback != 0 )
  {
    return RegDeleteKeyA(hKey, lpSubKey);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10346290
// Name: long AfxDelRegTreeHelper(struct HKEY__ __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &,class ATL::CAtlTransactionManager __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __stdcall AfxDelRegTreeHelper(
        HKEY__ *hParentKey,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strKeyName,
        ATL::CAtlTransactionManager *pTM)
{
  char *m_pszData; // edi
  ATL::CStringData *v4; // eax
  LSTATUS v5; // eax
  LSTATUS v6; // esi
  LSTATUS v7; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str2; // [esp+18h] [ebp-130h] BYREF
  HKEY__ *phkResult; // [esp+1Ch] [ebp-12Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v11; // [esp+20h] [ebp-128h] BYREF
  HKEY__ *hKey; // [esp+24h] [ebp-124h]
  bool v13; // [esp+2Bh] [ebp-11Dh]
  CHAR Name[280]; // [esp+2Ch] [ebp-11Ch] BYREF
  int v15; // [esp+144h] [ebp-4h]

  hKey = hParentKey;
  m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)strKeyName->m_pszData - 1)[1];
  str2.m_pszData = m_pszData;
  v15 = 0;
  if ( hParentKey == (HKEY__ *)0x80000000 && AfxGetPerUserRegistration() == 1 )
  {
    v4 = (ATL::CStringData *)ATL::operator+(result: &v11, psz1: "Software\\Classes\\", &str2);
    LOBYTE(v15) = 1;
    ATL::CSimpleStringT<char,0>::operator=(this: &str2, strSrc: v4);
    LOBYTE(v15) = 0;
    ATL::CStringData::Release(this: (ATL::CStringData *)v11.m_pszData - 1);
    m_pszData = str2.m_pszData;
    hKey = (HKEY__ *)-2147483647;
  }
  if ( pTM != nullptr )
    v5 = ATL::CAtlTransactionManager::RegOpenKeyExA(
           this: pTM,
           hKey,
           lpSubKey: m_pszData,
           ulOptions: 0,
           samDesired: 0x2001Fu,
           &phkResult);
  else
    v5 = RegOpenKeyExA(hKey, lpSubKey: m_pszData, ulOptions: 0, samDesired: 0x2001Fu, &phkResult);
  v6 = v5;
  if ( v5 == 0 )
  {
    while ( 1 )
    {
      v6 = RegEnumKeyA(hKey: phkResult, dwIndex: 0, lpName: Name, cchName: 0x104u);
      if ( v6 != 0 )
        break;
      LOBYTE(v15) = 2;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: &v11,
        pszSrc: Name);
      LOBYTE(v15) = 3;
      v6 = AfxDelRegTreeHelper(hParentKey: phkResult, strKeyName: &v11, pTM);
      v13 = v6 != 0;
      ATL::CStringData::Release(this: (ATL::CStringData *)v11.m_pszData - 1);
      if ( v13 )
      {
        LOBYTE(v15) = 0;
        break;
      }
      v15 = 0;
    }
    if ( v6 == 259 || v6 == 1010 )
    {
      if ( pTM != nullptr )
        v7 = ATL::CAtlTransactionManager::RegDeleteKeyA(this: pTM, hKey, lpSubKey: m_pszData);
      else
        v7 = RegDeleteKeyA(hKey, lpSubKey: m_pszData);
      v6 = v7;
    }
    RegCloseKey(hKey: phkResult);
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10349678
// Name: public: virtual struct ATL::CStringData __near * CAfxStringMgr::Allocate(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ATL::CStringData *__thiscall CAfxStringMgr::Allocate(CAfxStringMgr *this, int nChars, int nCharSize)
{
  ATL::CStringData *result; // eax

  if ( nChars < 0 )
    return nullptr;
  result = (ATL::CStringData *)MemAlloc_Alloc(nSize: nCharSize * (nChars + 1) + 16);
  if ( result == nullptr )
    return nullptr;
  result->nDataLength = 0;
  result->pStringMgr = this;
  result->nRefs = 1;
  result->nAllocLength = nChars;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10349760
// Name: public: virtual struct ATL::CStringData __near * CAfxStringMgr::GetNilString(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ATL::CNilStringData *__thiscall CAfxStringMgr::GetNilString(CAfxStringMgr *this)
{
  _InterlockedExchangeAdd(&this->m_nil.nRefs, 1u);
  return &this->m_nil;
}

//------------------------------------------------------------------------------
// Address: 0x10349DA1
// Name: int AfxMessageBox(char const __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxMessageBox(const char *lpszText, UINT nType, unsigned int nIDHelp)
{
  CWinApp *m_pCurrentWinApp; // eax

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr )
    return m_pCurrentWinApp->DoMessageBox(this: m_pCurrentWinApp, a2: lpszText, a3: nType, a4: nIDHelp);
  else
    return CWinApp::ShowAppMessageBox(pApp: nullptr, lpszPrompt: lpszText, nType, nIDPrompt: nIDHelp);
}

//------------------------------------------------------------------------------
// Address: 0x10349DEF
// Name: int AfxMessageBox(unsigned int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxMessageBox(unsigned int nIDPrompt, UINT nType, unsigned int nIDHelp)
{
  CAfxStringMgr *StringManager; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  unsigned int v5; // eax
  char *m_pszData; // esi
  int v7; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > string; // [esp+10h] [ebp-10h] BYREF
  int v10; // [esp+1Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &string, pStringMgr: StringManager);
  v10 = 0;
  StringResourceHandle = AfxFindStringResourceHandle(__formal: nIDPrompt);
  if ( StringResourceHandle != nullptr )
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
      this: &string,
      hInstance: StringResourceHandle,
      nID: nIDPrompt);
  v5 = nIDHelp;
  if ( nIDHelp == -1 )
    v5 = nIDPrompt;
  m_pszData = string.m_pszData;
  v7 = AfxMessageBox(lpszText: string.m_pszData, nType, nIDHelp: v5);
  ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10349E51
// Name: public: struct HWND__ __near * CDataExchange::PrepareCtrl(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HWND__ *__thiscall CDataExchange::PrepareCtrl(CDataExchange *this, HWND__ *nIDC)
{
  unsigned int v2; // edi
  HWND__ *result; // eax

  v2 = (unsigned int)nIDC;
  CWnd::GetDlgItem(this: this->m_pDlgWnd, nID: (int)nIDC, phWnd: &nIDC);
  if ( nIDC == nullptr && CWnd::GetOleControlSite(this: this->m_pDlgWnd, idControl: v2) == nullptr )
    AfxThrowNotSupportedException();
  this->m_bEditLastControl = 0;
  result = nIDC;
  this->m_idLastControl = v2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10349E92
// Name: public: void CDataExchange::Fail(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall __noreturn CDataExchange::Fail(CDataExchange *this)
{
  unsigned int m_idLastControl; // eax
  HWND__ *hWndLastControl; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_bSaveAndValidate != 0 )
  {
    m_idLastControl = this->m_idLastControl;
    if ( m_idLastControl != 0 )
    {
      CWnd::GetDlgItem(this: this->m_pDlgWnd, nID: m_idLastControl, phWnd: &hWndLastControl);
      if ( hWndLastControl != nullptr )
      {
        SetFocus(hWnd: hWndLastControl);
        if ( this->m_bEditLastControl != 0 )
          SendMessageA(hWnd: hWndLastControl, Msg: 0xB1u, wParam: 0, lParam: -1);
      }
    }
  }
  AfxThrowUserException();
}

//------------------------------------------------------------------------------
// Address: 0x10349EE3
// Name: void DDX_Check(class CDataExchange __near *,int,int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall DDX_Check(HWND__ *pDX, HWND__ *nIDC, int *value)
{
  HWND__ *v3; // esi
  LRESULT v4; // eax
  WPARAM *v5; // eax

  v3 = pDX;
  CDataExchange::PrepareCtrl(this: (CDataExchange *)pDX, nIDC);
  CWnd::GetDlgItem(this: *((CWnd **)v3 + 1), nID: (int)nIDC, phWnd: &pDX);
  if ( *(_DWORD *)v3 != 0 )
  {
    v4 = SendMessageA(hWnd: pDX, Msg: 0xF0u, wParam: 0, lParam: 0);
    *value = v4;
  }
  else
  {
    v5 = (WPARAM *)value;
    if ( (unsigned int)*value > 2 )
      *value = 0;
    SendMessageA(hWnd: pDX, Msg: 0xF1u, wParam: *v5, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10349F48
// Name: void DDX_Radio(class CDataExchange __near *,int,int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall DDX_Radio(HWND__ *pDX, HWND__ *nIDC, HWND__ **value)
{
  HWND__ *v3; // edi
  HWND Window; // eax

  v3 = pDX;
  CDataExchange::PrepareCtrl(this: (CDataExchange *)pDX, nIDC);
  CWnd::GetDlgItem(this: *((CWnd **)v3 + 1), nID: (int)nIDC, phWnd: &pDX);
  if ( *(_DWORD *)v3 != 0 )
    *value = (HWND__ *)-1;
  nIDC = nullptr;
  do
  {
    if ( (SendMessageA(hWnd: pDX, Msg: 0x87u, wParam: 0, lParam: 0) & 0x40) != 0 )
    {
      if ( *(_DWORD *)v3 != 0 )
      {
        if ( SendMessageA(hWnd: pDX, Msg: 0xF0u, wParam: 0, lParam: 0) != 0 )
          *value = nIDC;
      }
      else
      {
        SendMessageA(hWnd: pDX, Msg: 0xF1u, wParam: nIDC == *value, lParam: 0);
      }
      nIDC = (HWND__ *)((char *)nIDC + 1);
    }
    Window = GetWindow(hWnd: pDX, uCmd: 2u);
    pDX = Window;
  }
  while ( Window != nullptr && (GetWindowLongA(hWnd: Window, nIndex: -16) & 0x20000) == 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10349FF3
// Name: void DDX_CBIndex(class CDataExchange __near *,int,int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall DDX_CBIndex(HWND__ *pDX, HWND__ *nIDC, int *index)
{
  HWND__ *v3; // esi
  LRESULT v4; // eax

  v3 = pDX;
  CDataExchange::PrepareCtrl(this: (CDataExchange *)pDX, nIDC);
  CWnd::GetDlgItem(this: *((CWnd **)v3 + 1), nID: (int)nIDC, phWnd: &pDX);
  if ( *(_DWORD *)v3 != 0 )
  {
    v4 = SendMessageA(hWnd: pDX, Msg: 0x147u, wParam: 0, lParam: 0);
    *index = v4;
  }
  else
  {
    SendMessageA(hWnd: pDX, Msg: 0x14Eu, wParam: *index, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034A04A
// Name: public: struct HWND__ __near * CDataExchange::PrepareEditCtrl(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HWND__ *__thiscall CDataExchange::PrepareEditCtrl(CDataExchange *this, HWND__ *nIDC)
{
  HWND__ *result; // eax

  result = CDataExchange::PrepareCtrl(this, nIDC);
  this->m_bEditLastControl = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034A066
// Name: void _Afx_DDX_TextWithFormat(class CDataExchange __near *,int,char const __near *,unsigned int,...)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _Afx_DDX_TextWithFormat(CDataExchange *pDX, HWND__ *nIDC, const char *lpszFormat, unsigned int nIDPrompt, ...)
{
  HWND__ *v4; // eax
  bool v5; // zf
  int v6; // esi
  int *v7; // eax
  HWND__ *pResult; // [esp+8h] [ebp-48h]
  void *pResulta; // [esp+8h] [ebp-48h]
  char szT[64]; // [esp+Ch] [ebp-44h] BYREF
  void *ap; // [esp+68h] [ebp+18h] BYREF
  va_list apa; // [esp+68h] [ebp+18h]
  va_list va1; // [esp+6Ch] [ebp+1Ch] BYREF

  va_start(va1, nIDPrompt);
  va_start(apa, nIDPrompt);
  ap = va_arg(va1, void *);
  v4 = CDataExchange::PrepareCtrl(this: pDX, nIDC);
  v5 = pDX->m_bSaveAndValidate == 0;
  pResult = v4;
  pDX->m_bEditLastControl = 1;
  if ( v5 )
  {
    v6 = *_errno();
    *_errno() = 0;
    _vsnprintf_s(string: szT, sizeInBytes: 0x40u, count: 0x3Fu, format: lpszFormat, ap: apa);
    if ( *_errno() != 0 )
    {
      v7 = _errno();
      ATL::AtlCrtErrorCheck(nError: *v7);
    }
    else
    {
      *_errno() = v6;
    }
    AfxSetWindowText(hWndCtrl: pResult, lpszNew: szT);
  }
  else
  {
    pResulta = ap;
    GetWindowTextA(hWnd: v4, lpString: szT, nMaxCount: 64);
    if ( _snscanf_s(string: szT, count: 0x40u, format: lpszFormat, pResulta) != 1 )
    {
      AfxMessageBox(nIDPrompt, nType: 0, nIDHelp: 0xFFFFFFFF);
      CDataExchange::Fail(this: pDX);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034A137
// Name: void DDX_Text(class CDataExchange __near *,int,int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall DDX_Text(CDataExchange *pDX, HWND__ *nIDC, int *value)
{
  if ( pDX->m_bSaveAndValidate != 0 )
    _Afx_DDX_TextWithFormat(pDX, nIDC, lpszFormat: "%d", nIDPrompt: 0xF110u, value);
  else
    _Afx_DDX_TextWithFormat(pDX, nIDC, lpszFormat: "%d", nIDPrompt: 0xF110u, *value);
}

//------------------------------------------------------------------------------
// Address: 0x1034A168
// Name: void DDX_Text(class CDataExchange __near *,int,unsigned int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall DDX_Text(CDataExchange *pDX, HWND__ *nIDC, unsigned int *value)
{
  if ( pDX->m_bSaveAndValidate != 0 )
    _Afx_DDX_TextWithFormat(pDX, nIDC, lpszFormat: "%u", nIDPrompt: 0xF117u, value);
  else
    _Afx_DDX_TextWithFormat(pDX, nIDC, lpszFormat: "%u", nIDPrompt: 0xF117u, *value);
}

//------------------------------------------------------------------------------
// Address: 0x1034A199
// Name: void DDX_Control(class CDataExchange __near *,int,class CWnd __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall DDX_Control(CDataExchange *pDX, HWND__ *nIDC, HWND__ *rControl)
{
  CWnd *v3; // ebx
  CMFCControlContainer *m_pMFCCtrlContainer; // edi
  CWnd *m_pDlgWnd; // esi

  v3 = (CWnd *)rControl;
  if ( *((_DWORD *)rControl + 8) == 0 && CWnd::GetControlUnknown(this: (CWnd *)rControl) == nullptr )
  {
    CDataExchange::PrepareCtrl(this: pDX, nIDC);
    CWnd::GetDlgItem(this: pDX->m_pDlgWnd, nID: (int)nIDC, phWnd: &rControl);
    m_pMFCCtrlContainer = pDX->m_pDlgWnd->m_pMFCCtrlContainer;
    if ( m_pMFCCtrlContainer != nullptr
      && CMFCControlContainer::IsSubclassedFeaturePackControl(this: m_pMFCCtrlContainer, hWndCtrl: rControl) != 0 )
    {
      CMFCControlContainer::ReSubclassControl(
        this: m_pMFCCtrlContainer,
        hWndCtrl: rControl,
        (unsigned __int16)nIDC,
        control: v3);
    }
    else
    {
      if ( rControl == nullptr )
        goto LABEL_10;
      if ( CWnd::SubclassWindow(this: v3, hWnd: rControl) == 0 )
        AfxThrowNotSupportedException();
      if ( rControl != nullptr )
      {
        m_pDlgWnd = pDX->m_pDlgWnd;
        if ( m_pDlgWnd->m_hWnd != GetParent(hWnd: v3->m_hWnd) )
          CWnd::AttachControlSite(this: v3, pWndParent: m_pDlgWnd, nIDC: 0);
      }
      else
      {
LABEL_10:
        if ( CWnd::GetOleControlSite(this: pDX->m_pDlgWnd, idControl: (unsigned int)nIDC) != nullptr )
          CWnd::AttachControlSite(this: v3, pWndParent: pDX->m_pDlgWnd, (unsigned int)nIDC);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034A259
// Name: void _AfxFailMinMaxWithFormat(class CDataExchange __near *,__int64,__int64,char const __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _AfxFailMinMaxWithFormat(
        CDataExchange *pDX,
        __int64 minVal,
        __int64 maxVal,
        char *lpszFormat,
        unsigned int nIDPrompt)
{
  int v5; // edi
  int *v6; // eax
  int v7; // edi
  int *v8; // eax
  CAfxStringMgr *StringManager; // eax
  ATL::CSimpleStringT<char,0> v10; // [esp+14h] [ebp-94h] BYREF
  char string[64]; // [esp+18h] [ebp-90h] BYREF
  char sz2[76]; // [esp+58h] [ebp-50h] BYREF
  int v13; // [esp+A4h] [ebp-4h]

  if ( pDX->m_bSaveAndValidate != 0 )
  {
    v5 = *_errno();
    *_errno() = 0;
    _snprintf_s(string, sizeInBytes: 0x40u, count: 0x3Fu, format: lpszFormat, minVal);
    if ( *_errno() != 0 )
    {
      v6 = _errno();
      ATL::AtlCrtErrorCheck(nError: *v6);
    }
    else
    {
      *_errno() = v5;
    }
    v7 = *_errno();
    *_errno() = 0;
    _snprintf_s(string: sz2, sizeInBytes: 0x40u, count: 0x3Fu, format: lpszFormat, maxVal);
    if ( *_errno() != 0 )
    {
      v8 = _errno();
      ATL::AtlCrtErrorCheck(nError: *v8);
    }
    else
    {
      *_errno() = v7;
    }
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v10, pStringMgr: StringManager);
    v13 = 0;
    AfxFormatString2(
      rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v10,
      nIDS: nIDPrompt,
      lpsz1: string,
      lpsz2: sz2);
    AfxMessageBox(lpszText: v10.m_pszData, nType: 0x30u, nIDHelp: nIDPrompt);
    ATL::CSimpleStringT<char,0>::Empty(this: &v10);
    CDataExchange::Fail(this: pDX);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034A373
// Name: void DDV_MinMaxInt(class CDataExchange __near *,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall DDV_MinMaxInt(CDataExchange *pDX, int value, int minVal, int maxVal)
{
  if ( value < minVal || value > maxVal )
    _AfxFailMinMaxWithFormat(pDX, minVal, maxVal, lpszFormat: "%I64d", nIDPrompt: 0xF112u);
}

//------------------------------------------------------------------------------
// Address: 0x1034A3A6
// Name: void DDV_MaxChars(class CDataExchange __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall DDV_MaxChars(
        CDataExchange *pDX,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *value,
        int nChars)
{
  CAfxStringMgr *StringManager; // eax
  unsigned int m_idLastControl; // eax
  HWND__ *phWnd; // [esp+10h] [ebp-38h] BYREF
  ATL::CSimpleStringT<char,0> v6; // [esp+14h] [ebp-34h] BYREF
  char string[44]; // [esp+18h] [ebp-30h] BYREF
  int v8; // [esp+44h] [ebp-4h]

  if ( pDX->m_bSaveAndValidate != 0 && *((_DWORD *)value->m_pszData - 3) > nChars )
  {
    sprintf_s(string, sizeInBytes: 0x20u, format: "%d", nChars);
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v6, pStringMgr: StringManager);
    v8 = 0;
    AfxFormatString1(
      rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v6,
      nIDS: 0xF114u,
      lpsz1: string);
    AfxMessageBox(lpszText: v6.m_pszData, nType: 0x30u, nIDHelp: 0xF114u);
    ATL::CSimpleStringT<char,0>::Empty(this: &v6);
    CDataExchange::Fail(this: pDX);
  }
  m_idLastControl = pDX->m_idLastControl;
  if ( m_idLastControl != 0 && pDX->m_bEditLastControl != 0 )
  {
    CWnd::GetDlgItem(this: pDX->m_pDlgWnd, nID: m_idLastControl, &phWnd);
    SendMessageA(hWnd: phWnd, Msg: 0xC5u, wParam: nChars, lParam: 0);
    SendMessageA(hWnd: phWnd, Msg: 0x141u, wParam: nChars, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034A466
// Name: void DDX_Text(class CDataExchange __near *,int,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall DDX_Text(
        CDataExchange *pDX,
        HWND__ *nIDC,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *value)
{
  HWND__ *v3; // eax
  bool v4; // zf
  HWND v5; // edi
  int WindowTextLengthA; // eax
  CHAR *BufferSetLength; // eax
  int v8; // [esp-4h] [ebp-Ch]

  v3 = CDataExchange::PrepareCtrl(this: pDX, nIDC);
  v4 = pDX->m_bSaveAndValidate == 0;
  v5 = v3;
  pDX->m_bEditLastControl = 1;
  if ( v4 )
  {
    AfxSetWindowText(hWndCtrl: v3, lpszNew: value->m_pszData);
  }
  else
  {
    WindowTextLengthA = GetWindowTextLengthA(hWnd: v3);
    v8 = WindowTextLengthA + 1;
    BufferSetLength = ATL::CSimpleStringT<char,0>::GetBufferSetLength(this: value, nLength: WindowTextLengthA);
    GetWindowTextA(hWnd: v5, lpString: BufferSetLength, nMaxCount: v8);
    ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: value, nNewLength: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034A4C1
// Name: void DDX_CBString(class CDataExchange __near *,int,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall DDX_CBString(
        HWND__ *pDX,
        HWND__ *nIDC,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *value)
{
  CDataExchange *v3; // esi
  int WindowTextLengthA; // eax
  CHAR *BufferSetLength; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v6; // esi
  int v7; // [esp-4h] [ebp-8h]

  v3 = (CDataExchange *)pDX;
  CWnd::GetDlgItem(this: *((CWnd **)pDX + 1), nID: (int)nIDC, phWnd: &pDX);
  if ( (GetWindowLongA(hWnd: pDX, nIndex: -16) & 3) == 3 )
  {
    CDataExchange::PrepareCtrl(this: v3, nIDC);
  }
  else
  {
    CDataExchange::PrepareCtrl(this: v3, nIDC);
    v3->m_bEditLastControl = 1;
  }
  if ( v3->m_bSaveAndValidate != 0 )
  {
    WindowTextLengthA = GetWindowTextLengthA(hWnd: pDX);
    if ( WindowTextLengthA <= 0 )
    {
      BufferSetLength = ATL::CSimpleStringT<char,0>::PrepareWrite(this: value, nLength: 255);
      v7 = 256;
    }
    else
    {
      v7 = WindowTextLengthA + 1;
      BufferSetLength = ATL::CSimpleStringT<char,0>::GetBufferSetLength(this: value, nLength: WindowTextLengthA);
    }
    GetWindowTextA(hWnd: pDX, lpString: BufferSetLength, nMaxCount: v7);
    ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: value, nNewLength: -1);
  }
  else
  {
    v6 = value;
    if ( SendMessageA(hWnd: pDX, Msg: 0x14Du, wParam: 0xFFFFFFFF, lParam: (LPARAM)value->m_pszData) == -1 )
      AfxSetWindowText(hWndCtrl: pDX, lpszNew: v6->m_pszData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034C27F
// Name: public: virtual struct CRuntimeClass __near * CMultiDocTemplate::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMultiDocTemplate::GetRuntimeClass(CMultiDocTemplate *this)
{
  return &CMultiDocTemplate::classCMultiDocTemplate;
}

//------------------------------------------------------------------------------
// Address: 0x1034C2A6
// Name: public: virtual void CMultiDocTemplate::LoadTemplate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMultiDocTemplate::LoadTemplate(CMultiDocTemplate *this)
{
  HINSTANCE__ *m_hCurrentResourceHandle; // ebx

  CDocTemplate::LoadTemplate(this);
  if ( this->m_nIDResource != 0 && this->m_hMenuShared == nullptr )
  {
    m_hCurrentResourceHandle = AfxGetModuleState()->m_hCurrentResourceHandle;
    this->m_hMenuShared = LoadMenuW(
                            hInstance: m_hCurrentResourceHandle,
                            lpMenuName: (LPCWSTR)LOWORD(this->m_nIDResource));
    this->m_hAccelTable = LoadAcceleratorsW(
                            hInstance: m_hCurrentResourceHandle,
                            lpTableName: (LPCWSTR)LOWORD(this->m_nIDResource));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034C2F1
// Name: public: virtual int CMFCRibbonBaseElement::IsAlwaysLargeImage(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonBaseElement::IsAlwaysLargeImage(CMFCRibbonBaseElement *this)
{
  return this->m_bIsAlwaysLarge;
}

//------------------------------------------------------------------------------
// Address: 0x1034C2F8
// Name: public: virtual class CDocument __near * CMultiDocTemplate::GetNextDoc(struct __POSITION __near * __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDocument *__thiscall CMultiDocTemplate::GetNextDoc(CMultiDocTemplate *this, __POSITION **rPos)
{
  return (CDocument *)CPtrList::GetNext(this: &this->m_docList, rPosition: rPos);
}

//------------------------------------------------------------------------------
// Address: 0x1034C309
// Name: public: CMultiDocTemplate::CMultiDocTemplate(unsigned int,struct CRuntimeClass __near *,struct CRuntimeClass __near *,struct CRuntimeClass __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMultiDocTemplate *__thiscall CMultiDocTemplate::CMultiDocTemplate(
        CMultiDocTemplate *this,
        unsigned int nIDResource,
        CRuntimeClass *pDocClass,
        CRuntimeClass *pFrameClass,
        CRuntimeClass *pViewClass)
{
  CDocTemplate::CDocTemplate(this, nIDResource, pDocClass, pFrameClass, pViewClass);
  this->__vftable = (CMultiDocTemplate_vtbl *)&CMultiDocTemplate::`vftable';
  CPtrList::CPtrList(this: &this->m_docList, nBlockSize: 10);
  this->m_hMenuShared = nullptr;
  this->m_hAccelTable = nullptr;
  this->m_nUntitledCount = 0;
  if ( CDocManager::bStaticInit == 0 )
    CMultiDocTemplate::LoadTemplate(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1034C493
// Name: public: virtual void CMultiDocTemplate::SetDefaultTitle(class CDocument __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMultiDocTemplate::SetDefaultTitle(CMultiDocTemplate *this, CDocument *pDocument)
{
  CAfxStringMgr *StringManager; // eax
  CMultiDocTemplate_vtbl *v4; // eax
  int v5; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  ATL::CSimpleStringT<char,0> v7; // [esp+10h] [ebp-24h] BYREF
  char string[28]; // [esp+14h] [ebp-20h] BYREF
  int v9; // [esp+30h] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v7, pStringMgr: StringManager);
  v4 = this->__vftable;
  v9 = 0;
  if ( v4->GetDocString(this, a2: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v7, a3: docName) != 0
    && *((_DWORD *)v7.m_pszData - 3) != 0 )
  {
    sprintf_s(string, sizeInBytes: 0x10u, format: "%d", this->m_nUntitledCount + 1);
    strlen(buf: (unsigned __int8 *)string);
    ATL::CSimpleStringT<char,0>::Append(this: &v7, pszSrc: string, nLength: v5);
  }
  else
  {
    StringResourceHandle = AfxFindStringResourceHandle(__formal: 0xF003u);
    if ( StringResourceHandle == nullptr
      || ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
           this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v7,
           hInstance: StringResourceHandle,
           nID: 0xF003u) == 0 )
    {
      AfxThrowInvalidArgException();
    }
  }
  pDocument->SetTitle(this: pDocument, a2: v7.m_pszData);
  ATL::CStringData::Release(this: (ATL::CStringData *)v7.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1034C541
// Name: public: virtual void CDocTemplate::AddDocument(class CDocument __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDocTemplate::AddDocument(CDocTemplate *this, CDocument *pDoc)
{
  pDoc->m_pDocTemplate = this;
}

//------------------------------------------------------------------------------
// Address: 0x1034C550
// Name: public: virtual void CDocTemplate::RemoveDocument(class CDocument __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDocTemplate::RemoveDocument(CDocTemplate *this, CDocument *pDoc)
{
  pDoc->m_pDocTemplate = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1034C560
// Name: public: virtual class CDocument __near * CDocTemplate::CreateNewDocument(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDocument *__thiscall CDocTemplate::CreateNewDocument(CDocTemplate *this)
{
  CRuntimeClass *m_pDocClass; // ecx
  CDocument *result; // eax
  CDocument *v4; // edi

  m_pDocClass = this->m_pDocClass;
  if ( m_pDocClass == nullptr )
    return nullptr;
  result = (CDocument *)CRuntimeClass::CreateObject(this: m_pDocClass);
  v4 = result;
  if ( result != nullptr )
  {
    this->AddDocument(this, a2: result);
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034C5A0
// Name: public: virtual int CDocTemplate::SaveAllModified(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDocTemplate::SaveAllModified(CDocTemplate *this)
{
  CDocument *v2; // eax
  __POSITION *pos; // [esp+4h] [ebp-4h] BYREF

  pos = this->GetFirstDocPosition(this);
  if ( pos == nullptr )
    return 1;
  while ( 1 )
  {
    v2 = this->GetNextDoc(this, a2: &pos);
    if ( v2->SaveModified(this: v2) == 0 )
      break;
    if ( pos == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1034C613
// Name: public: virtual void CDocTemplate::OnIdle(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDocTemplate::OnIdle(CDocTemplate *this)
{
  CDocument *v2; // eax
  __POSITION *pos; // [esp+4h] [ebp-4h] BYREF

  pos = this->GetFirstDocPosition(this);
  while ( pos != nullptr )
  {
    v2 = this->GetNextDoc(this, a2: &pos);
    v2->OnIdle(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034C646
// Name: public: virtual int CDocTemplate::OnCmdMsg(unsigned int,int,void __near *,struct AFX_CMDHANDLERINFO __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDocTemplate::OnCmdMsg(
        CDocTemplate *this,
        unsigned int nID,
        int nCode,
        void *pExtra,
        AFX_CMDHANDLERINFO *pHandlerInfo)
{
  CObject *v6; // eax

  v6 = AfxDynamicDownCast(pClass: &CCmdTarget::classCCmdTarget, pObject: this->m_pAttachedFactory);
  if ( nCode == -4 && v6 != nullptr )
    return ((int (__thiscall *)(CObject *, unsigned int, int, void *, AFX_CMDHANDLERINFO *))v6->__vftable[1].GetRuntimeClass)(
             a1: v6,
             a2: nID,
             a3: -4,
             a4: pExtra,
             a5: pHandlerInfo);
  else
    return CCmdTarget::OnCmdMsg(this, nID, nCode, pExtra, pHandlerInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1034C693
// Name: public: virtual int CDocTemplate::GetDocString(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,enum CDocTemplate::DocStringIndex)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDocTemplate::GetDocString(
        CDocTemplate *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *rString,
        CDocTemplate::DocStringIndex i)
{
  return AfxExtractSubString(rString, lpszFullString: this->m_strDocStrings.m_pszData, iSubString: i, chSep: 10);
}

//------------------------------------------------------------------------------
// Address: 0x1034CE22
// Name: void AfxPostQuitMessage(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxPostQuitMessage(int nExitCode)
{
  CWinThread *Thread; // eax
  void (__stdcall *m_lpfnOleTermOrFreeLib)(int, int); // eax

  Thread = AfxGetThread();
  if ( Thread != nullptr )
  {
    m_lpfnOleTermOrFreeLib = Thread->m_lpfnOleTermOrFreeLib;
    if ( m_lpfnOleTermOrFreeLib != nullptr )
      m_lpfnOleTermOrFreeLib(a1: 1, a2: 1);
  }
  PostQuitMessage(nExitCode);
}

//------------------------------------------------------------------------------
// Address: 0x1034D0F6
// Name: _AfxLoadLangDLL
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HMODULE __cdecl AfxLoadLangDLL(const char *pszPath, LCID lcid)
{
  const char *pszFormat; // ecx
  const char *v3; // esi
  int v4; // eax
  int v5; // edi
  int *v6; // eax
  char szLangCode[4]; // [esp+4h] [ebp-120h] BYREF
  int ret; // [esp+8h] [ebp-11Ch]
  char szLangDLL[276]; // [esp+Ch] [ebp-118h] BYREF

  ret = (int)pszPath;
  v3 = pszFormat;
  if ( lcid == 2048 )
  {
    v4 = strcpy_s(_Dst: szLangCode, _SizeInBytes: 4u, _Src: "LOC");
    AfxCrtErrorCheck(error: v4);
  }
  else if ( GetLocaleInfoA(Locale: lcid, LCType: 3u, lpLCData: szLangCode, cchData: 4) == 0 )
  {
    return nullptr;
  }
  v5 = *_errno();
  *_errno() = 0;
  ret = _snprintf_s(string: szLangDLL, sizeInBytes: 0x112u, count: 0x111u, format: v3, ret, szLangCode);
  if ( *_errno() != 0 )
  {
    v6 = _errno();
    ATL::AtlCrtErrorCheck(nError: *v6);
  }
  else
  {
    *_errno() = v5;
  }
  if ( (unsigned int)ret <= 0x111 )
    return LoadLibraryExA(lpLibFileName: szLangDLL, hFile: nullptr, dwFlags: 0);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1034D1E6
// Name: struct HINSTANCE__ __near * AfxLoadLangResourceDLL(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HMODULE __stdcall AfxLoadLangResourceDLL(const char *pszFormat, char *pszPath)
{
  int v2; // esi
  HMODULE LibraryA; // eax
  BOOL (__stdcall *GetThreadPreferredUILanguages)(DWORD, PULONG, PZZWSTR, PULONG); // edi
  wchar_t *i; // edi
  unsigned int v6; // ebx
  LANGID UserDefaultUILanguage; // ax
  LCID v8; // eax
  LANGID SystemDefaultUILanguage; // ax
  LCID v10; // eax
  int v11; // esi
  int v12; // edi
  HMODULE result; // eax
  LCID v14; // [esp-4h] [ebp-154h]
  LCID v15; // [esp-4h] [ebp-154h]
  unsigned int nLanguages; // [esp+10h] [ebp-140h] BYREF
  char *v17; // [esp+14h] [ebp-13Ch]
  unsigned int cchLanguagesBuffer; // [esp+18h] [ebp-138h] BYREF
  unsigned int alcidSearch[25]; // [esp+1Ch] [ebp-134h]
  wchar_t wszLanguages[102]; // [esp+80h] [ebp-D0h] BYREF

  v17 = pszPath;
  v2 = 0;
  LibraryA = AfxCtxLoadLibraryA(lpLibFileName: "KERNEL32.DLL");
  if ( LibraryA != nullptr )
  {
    GetThreadPreferredUILanguages = (BOOL (__stdcall *)(DWORD, PULONG, PZZWSTR, PULONG))GetProcAddress(
                                                                                          hModule: LibraryA,
                                                                                          lpProcName: "GetThreadPreferredUILanguages");
    if ( GetThreadPreferredUILanguages != nullptr )
    {
      memset(wszLanguages, 0, 202);
      nLanguages = 0;
      cchLanguagesBuffer = 101;
      if ( GetThreadPreferredUILanguages(
             dwFlags: 52,
             pulNumLanguages: &nLanguages,
             pwszLanguagesBuffer: wszLanguages,
             pcchLanguagesBuffer: &cchLanguagesBuffer) )
      {
        for ( i = wszLanguages; *i != 0; i += wcslen(wcs: i) + 1 )
        {
          if ( v2 >= 20 )
            break;
          v6 = wcstoul(nptr: i, endptr: nullptr, ibase: 16);
          if ( v6 != 0 && *_errno() != 34 )
            alcidSearch[v2++] = v6;
        }
      }
    }
  }
  UserDefaultUILanguage = GetUserDefaultUILanguage();
  cchLanguagesBuffer = UserDefaultUILanguage & 0x3FF;
  v8 = ConvertDefaultLocale(Locale: UserDefaultUILanguage);
  v14 = cchLanguagesBuffer;
  alcidSearch[v2] = v8;
  alcidSearch[v2 + 1] = ConvertDefaultLocale(Locale: v14);
  SystemDefaultUILanguage = GetSystemDefaultUILanguage();
  cchLanguagesBuffer = SystemDefaultUILanguage & 0x3FF;
  v10 = ConvertDefaultLocale(Locale: cchLanguagesBuffer | SystemDefaultUILanguage & 0xFC00);
  v15 = cchLanguagesBuffer;
  alcidSearch[v2 + 2] = v10;
  alcidSearch[v2 + 3] = ConvertDefaultLocale(Locale: v15);
  v11 = v2 + 4;
  if ( g_fLoadingResourcesForMFCDLL == 0 )
    alcidSearch[v11++] = 2048;
  v12 = 0;
  if ( v11 <= 0 )
    return nullptr;
  while ( 1 )
  {
    result = AfxLoadLangDLL(pszPath: v17, lcid: alcidSearch[v12]);
    if ( result != nullptr )
      break;
    if ( ++v12 >= v11 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034D4FC
// Name: unsigned long AfxApplicationRecoveryWrapper(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxApplicationRecoveryWrapper(void *lpvParam)
{
  int v1; // esi
  CWinApp *m_pCurrentWinApp; // eax

  v1 = 0;
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr )
    return m_pCurrentWinApp->ApplicationRecoveryCallback(this: m_pCurrentWinApp, a2: lpvParam);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1034D5DA
// Name: wchar_t __near * A2WBSTR(char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t *__cdecl A2WBSTR(const char *lp, int nLen)
{
  UINT v2; // eax
  int v3; // edi
  wchar_t *v4; // eax
  wchar_t *str; // [esp+Ch] [ebp-4h]

  if ( lp == nullptr || nLen == 0 )
    return nullptr;
  v2 = MultiByteToWideChar(
         CodePage: 3u,
         dwFlags: 0,
         lpMultiByteStr: lp,
         cbMultiByte: nLen,
         lpWideCharStr: nullptr,
         cchWideChar: 0);
  v3 = v2;
  if ( nLen == -1 )
    --v2;
  v4 = SysAllocStringLen(strIn: nullptr, ui: v2);
  str = v4;
  if ( v4 != nullptr
    && MultiByteToWideChar(
         CodePage: 3u,
         dwFlags: 0,
         lpMultiByteStr: lp,
         cbMultiByte: nLen,
         lpWideCharStr: v4,
         cchWideChar: v3) != v3 )
  {
    SysFreeString(bstrString: str);
    return nullptr;
  }
  return str;
}

//------------------------------------------------------------------------------
// Address: 0x1034D642
// Name: public: ATL::CComBSTR::CComBSTR(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ATL::CComBSTR *__thiscall ATL::CComBSTR::CComBSTR(ATL::CComBSTR *this, const char *pSrc)
{
  wchar_t *v3; // eax

  if ( pSrc != nullptr )
  {
    v3 = A2WBSTR(lp: pSrc, nLen: -1);
    this->m_str = v3;
    if ( v3 == nullptr )
      ATL::AtlThrowImpl(hr: -2147024882);
  }
  else
  {
    this->m_str = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1034D770
// Name: public: CCommandLineInfo::CCommandLineInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCommandLineInfo *__thiscall CCommandLineInfo::CCommandLineInfo(CCommandLineInfo *this)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v3; // eax
  CAfxStringMgr *v4; // eax
  CAfxStringMgr *v5; // eax
  CAfxStringMgr *v6; // eax

  this->__vftable = (CCommandLineInfo_vtbl *)&CCommandLineInfo::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strFileName, pStringMgr: StringManager);
  v3 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strPrinterName, pStringMgr: v3);
  v4 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strDriverName, pStringMgr: v4);
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strPortName, pStringMgr: v5);
  v6 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strRestartIdentifier, pStringMgr: v6);
  this->m_bRunEmbedded = 0;
  this->m_bRunAutomated = 0;
  this->m_bRegisterPerUser = 0;
  this->m_nShellCommand = FileNew;
  this->m_bShowSplash = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1034D7DA
// Name: public: virtual CCommandLineInfo::~CCommandLineInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CCommandLineInfo::~CCommandLineInfo(CCommandLineInfo *this)
{
  ATL::CStringData *v2; // ecx

  v2 = (ATL::CStringData *)(this->m_strRestartIdentifier.m_pszData - 16);
  this->__vftable = (CCommandLineInfo_vtbl *)&CCommandLineInfo::`vftable';
  ATL::CStringData::Release(this: v2);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strPortName.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strDriverName.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strPrinterName.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strFileName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1034D81D
// Name: protected: void CCommandLineInfo::ParseLast(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CCommandLineInfo::ParseLast(CCommandLineInfo *this, int bLast)
{
  int v2; // eax

  v2 = 0;
  if ( bLast != 0 )
  {
    if ( this->m_nShellCommand == FileNew && *((_DWORD *)this->m_strFileName.m_pszData - 3) != 0 )
      this->m_nShellCommand = FileOpen;
    if ( this->m_bRunEmbedded == 0 && this->m_bRunAutomated == 0 )
      v2 = 1;
    this->m_bShowSplash = v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034DA81
// Name: protected: void CCommandLineInfo::ParseParamNotFlag(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CCommandLineInfo::ParseParamNotFlag(CCommandLineInfo *this, const char *pszParam)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_strFileName; // ecx

  p_m_strFileName = &this->m_strFileName;
  if ( *((_DWORD *)p_m_strFileName->m_pszData - 3) == 0
    || this->m_nShellCommand == FilePrintTo
    && ((p_m_strFileName = &this->m_strPrinterName, *((_DWORD *)this->m_strPrinterName.m_pszData - 3) == 0)
     || (p_m_strFileName = &this->m_strDriverName, *((_DWORD *)this->m_strDriverName.m_pszData - 3) == 0)
     || (p_m_strFileName = &this->m_strPortName, *((_DWORD *)this->m_strPortName.m_pszData - 3) == 0)) )
  {
    ATL::CSimpleStringT<char,0>::SetString(this: p_m_strFileName, pszSrc: pszParam);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034DB63
// Name: protected: void CCommandLineInfo::ParseParamFlag(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CCommandLineInfo::ParseParamFlag(CCommandLineInfo *this, const char *pszParam)
{
  const char *v3; // ebx
  ATL::CStringData *v4; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+10h] [ebp-10h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  v3 = pszParam;
  if ( lstrcmpA(lpString1: pszParam, lpString2: "pt") == 0 )
  {
    this->m_nShellCommand = FilePrintTo;
    return;
  }
  if ( lstrcmpA(lpString1: v3, lpString2: "p") == 0 )
  {
    this->m_nShellCommand = FilePrint;
    return;
  }
  if ( AfxInvariantStrICmp(pszLeft: v3, pszRight: "Register") == 0
    || AfxInvariantStrICmp(pszLeft: v3, pszRight: "Regserver") == 0 )
  {
    goto LABEL_29;
  }
  if ( AfxInvariantStrICmp(pszLeft: v3, pszRight: "RegisterPerUser") == 0
    || AfxInvariantStrICmp(pszLeft: v3, pszRight: "RegserverPerUser") == 0 )
  {
    this->m_bRegisterPerUser = 1;
LABEL_29:
    this->m_nShellCommand = AppRegister;
    return;
  }
  if ( AfxInvariantStrICmp(pszLeft: v3, pszRight: "Unregister") != 0
    && AfxInvariantStrICmp(pszLeft: v3, pszRight: "Unregserver") != 0 )
  {
    if ( AfxInvariantStrICmp(pszLeft: v3, pszRight: "UnregisterPerUser") != 0
      && AfxInvariantStrICmp(pszLeft: v3, pszRight: "UnregserverPerUser") != 0 )
    {
      if ( _strnicmp(dst: v3, src: "RestartByRestartManager", count: 0x17u) != 0 )
      {
        if ( lstrcmpA(lpString1: v3, lpString2: "ddenoshow") == 0 )
        {
          AfxOleSetUserCtrl(bUserCtrl: 0);
          this->m_nShellCommand = FileDDENoShow;
          return;
        }
        if ( lstrcmpA(lpString1: v3, lpString2: "dde") == 0 )
        {
          AfxOleSetUserCtrl(bUserCtrl: 0);
          this->m_nShellCommand = FileDDE;
          return;
        }
        if ( AfxInvariantStrICmp(pszLeft: v3, pszRight: "Embedding") != 0 )
        {
          if ( AfxInvariantStrICmp(pszLeft: v3, pszRight: "Automation") != 0 )
            return;
          AfxOleSetUserCtrl(bUserCtrl: 0);
          this->m_bRunAutomated = 1;
        }
        else
        {
          AfxOleSetUserCtrl(bUserCtrl: 0);
          this->m_bRunEmbedded = 1;
        }
        this->m_bShowSplash = 0;
        return;
      }
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pszParam,
        pszSrc: v3);
      v6 = 0;
      if ( *((_DWORD *)pszParam - 3) == 60 )
      {
        this->m_nShellCommand = RestartByRestartManager;
        v4 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Right(
                                   this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pszParam,
                                   &result,
                                   nCount: 36);
        LOBYTE(v6) = 1;
        ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strRestartIdentifier, strSrc: v4);
        ATL::CStringData::Release(this: (ATL::CStringData *)result.m_pszData - 1);
      }
      ATL::CStringData::Release(this: (ATL::CStringData *)pszParam - 1);
    }
    else
    {
      this->m_nShellCommand = AppUnregister;
      this->m_bRegisterPerUser = 1;
    }
  }
  else
  {
    this->m_nShellCommand = AppUnregister;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1034E016
// Name: public: long ATL::CAtlTransactionManager::RegCreateKeyExA(struct HKEY__ __near *,char const __near *,unsigned long,char __near *,unsigned long,unsigned long,struct _SECURITY_ATTRIBUTES __near * const,struct HKEY__ __near * __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __thiscall ATL::CAtlTransactionManager::RegCreateKeyExA(
        ATL::CAtlTransactionManager *this,
        HKEY__ *hKey,
        const char *lpSubKey,
        DWORD dwReserved,
        char *lpClass,
        DWORD dwOptions,
        REGSAM samDesired,
        _SECURITY_ATTRIBUTES *const lpSecurityAttributes,
        HKEY__ **phkResult,
        unsigned int *lpdwDisposition)
{
  HMODULE ModuleHandleA; // eax
  LSTATUS (__stdcall *RegCreateKeyTransactedA)(HKEY, LPCSTR, DWORD, LPSTR, DWORD, REGSAM, const LPSECURITY_ATTRIBUTES, PHKEY, LPDWORD, HANDLE, PVOID); // eax

  if ( this->m_hTransaction != nullptr )
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "Advapi32.dll");
    if ( ModuleHandleA != nullptr )
    {
      RegCreateKeyTransactedA = (LSTATUS (__stdcall *)(HKEY, LPCSTR, DWORD, LPSTR, DWORD, REGSAM, const LPSECURITY_ATTRIBUTES, PHKEY, LPDWORD, HANDLE, PVOID))GetProcAddress(hModule: ModuleHandleA, lpProcName: "RegCreateKeyTransactedA");
      if ( RegCreateKeyTransactedA != nullptr )
        return RegCreateKeyTransactedA(
                 hKey,
                 lpSubKey,
                 Reserved: dwReserved,
                 lpClass,
                 dwOptions,
                 samDesired,
                 lpSecurityAttributes,
                 phkResult,
                 lpdwDisposition,
                 hTransaction: this->m_hTransaction,
                 pExtendedParemeter: nullptr);
    }
  }
  else if ( this->m_bFallback != 0 )
  {
    return RegCreateKeyExA(
             hKey,
             lpSubKey,
             Reserved: dwReserved,
             lpClass,
             dwOptions,
             samDesired,
             lpSecurityAttributes,
             phkResult,
             lpdwDisposition);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034E07B
// Name: public: long ATL::CRegKey::Close(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __thiscall ATL::CRegKey::Close(ATL::CRegKey *this)
{
  HKEY__ *m_hKey; // ecx
  LSTATUS result; // eax

  m_hKey = this->m_hKey;
  result = 0;
  if ( m_hKey != nullptr )
  {
    result = RegCloseKey(hKey: m_hKey);
    this->m_hKey = nullptr;
  }
  this->m_samWOW64 = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034E3E5
// Name: public: ATL::CRegKey::~CRegKey(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall ATL::CRegKey::~CRegKey(ATL::CRegKey *this)
{
  ATL::CRegKey::Close(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034E954
// Name: public: virtual CPrintDialog::~CPrintDialog(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPrintDialog::~CPrintDialog(CPrintDialog *this)
{
  this->__vftable = (CPrintDialog_vtbl *)&CCommonDialog::`vftable';
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x1034E95F
// Name: public: struct CCommDlgWrapper::CommDlgExtendedError_Type CCommDlgWrapper::GetProcAddress_CommDlgExtendedError(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCommDlgWrapper::CommDlgExtendedError_Type *__thiscall CCommDlgWrapper::GetProcAddress_CommDlgExtendedError(
        CCommDlgWrapper *this,
        CCommDlgWrapper::CommDlgExtendedError_Type *result)
{
  HMODULE ModuleHandleA; // eax

  if ( this->m__CommDlgExtendedError.p == nullptr )
  {
    ModuleHandleA = CDllIsolationWrapperBase::GetModuleHandleA(this);
    this->m__CommDlgExtendedError.p = (unsigned int (__stdcall *)())GetProcAddress(
                                                                      hModule: ModuleHandleA,
                                                                      lpProcName: "CommDlgExtendedError");
  }
  result->p = (unsigned int (__stdcall *)())this->m__CommDlgExtendedError;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034E98E
// Name: public: unsigned long CCommDlgWrapper::_CommDlgExtendedError(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CCommDlgWrapper::_CommDlgExtendedError(CCommDlgWrapper *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v3; // eax
  unsigned int (__stdcall *p)(); // eax
  BOOL v6; // esi
  DWORD LastError; // edi
  int v8; // [esp+0h] [ebp-34h]
  CCommDlgWrapper::CommDlgExtendedError_Type v9; // [esp+10h] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+14h] [ebp-20h] BYREF
  unsigned int v11; // [esp+18h] [ebp-1Ch]
  int v12; // [esp+30h] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v3 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v11 = 0;
  if ( !v3 )
    return 0;
  v12 = 0;
  CCommDlgWrapper::GetProcAddress_CommDlgExtendedError(this, result: &v9);
  p = this->m__CommDlgExtendedError.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v11 = ((int (__stdcall *)(int))p)(a1: v8);
  v12 = -2;
  v6 = v11 == 0;
  if ( v11 != 0 )
    LastError = 0;
  else
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v6 )
    SetLastError(dwErrCode: LastError);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x1034EDE0
// Name: public: virtual _AFX_RICHEDIT_STATE::~_AFX_RICHEDIT_STATE(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall _AFX_RICHEDIT_STATE::~_AFX_RICHEDIT_STATE(_AFX_RICHEDIT_STATE *this)
{
  HINSTANCE__ *m_hInstRichEdit; // eax

  m_hInstRichEdit = this->m_hInstRichEdit;
  this->__vftable = (_AFX_RICHEDIT_STATE_vtbl *)&_AFX_RICHEDIT_STATE::`vftable';
  if ( m_hInstRichEdit != nullptr )
    FreeLibrary(hLibModule: m_hInstRichEdit);
  if ( this->m_hInstRichEdit2 != nullptr )
    FreeLibrary(hLibModule: this->m_hInstRichEdit2);
  _AFX_EDIT_STATE::~_AFX_EDIT_STATE(this);
}

//------------------------------------------------------------------------------
// Address: 0x1035E091
// Name: public: virtual _AFX_CHECKLIST_STATE::~_AFX_CHECKLIST_STATE(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall _AFX_CHECKLIST_STATE::~_AFX_CHECKLIST_STATE(_AFX_CHECKLIST_STATE *this)
{
  HBITMAP__ *m_hbitmapCheck; // ecx

  this->__vftable = (_AFX_CHECKLIST_STATE_vtbl *)&_AFX_CHECKLIST_STATE::`vftable';
  m_hbitmapCheck = this->m_hbitmapCheck;
  if ( m_hbitmapCheck != nullptr )
    DeleteObject(ho: m_hbitmapCheck);
}

//------------------------------------------------------------------------------
// Address: 0x10360133
// Name: int AfxWinInit(struct HINSTANCE__ __near *,struct HINSTANCE__ __near *,char __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxWinInit(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow)
{
  UINT v4; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  CWinApp *m_pCurrentWinApp; // eax

  v4 = SetErrorMode(uMode: 0);
  SetErrorMode(uMode: v4 | 0x8001);
  ModuleState = AfxGetModuleState();
  ModuleState->m_hCurrentInstanceHandle = hInstance;
  ModuleState->m_hCurrentResourceHandle = hInstance;
  AFX_MODULE_STATE::CreateActivationContext(this: ModuleState);
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr )
  {
    m_pCurrentWinApp->m_lpCmdLine = lpCmdLine;
    m_pCurrentWinApp->m_nCmdShow = nCmdShow;
    m_pCurrentWinApp->m_hInstance = hInstance;
    CWinApp::SetCurrentHandles(this: m_pCurrentWinApp);
  }
  if ( AfxGetModuleState()->m_bDLL == 0 )
    AfxInitThread();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1036019A
// Name: void AfxFormatStrings(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,char const __near *,char const __near * const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxFormatStrings(
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *rString,
        const char *lpszFormat,
        const char *const *rglpsz,
        int nString)
{
  const char *v5; // edi
  char v6; // al
  int v7; // eax
  const char *v8; // eax
  const char *v9; // ebx
  char *v10; // edi
  char v11; // al
  int v12; // eax
  LPCSTR *v13; // esi
  int nLen; // [esp+Ch] [ebp-4h]
  int nTotalLen; // [esp+1Ch] [ebp+Ch]

  if ( lpszFormat == nullptr || rglpsz == nullptr )
    AfxThrowInvalidArgException();
  nTotalLen = 0;
  v5 = lpszFormat;
  if ( *lpszFormat != 0 )
  {
    while ( *v5 == 37 )
    {
      v6 = v5[1];
      if ( v6 >= 49 && v6 <= 57 )
      {
        v7 = v6 - 49;
      }
      else
      {
        if ( v6 < 65 || v6 > 90 )
          break;
        v7 = v6 - 56;
      }
      v5 += 2;
      if ( v7 < nString )
      {
        v8 = rglpsz[v7];
        if ( v8 != nullptr )
          nTotalLen += lstrlenA(lpString: v8);
        goto LABEL_19;
      }
LABEL_18:
      ++nTotalLen;
LABEL_19:
      if ( *v5 == 0 )
        goto LABEL_20;
    }
    if ( _ismbblead(tst: *v5) != 0 )
    {
      ++nTotalLen;
      ++v5;
    }
    ++v5;
    goto LABEL_18;
  }
LABEL_20:
  v9 = lpszFormat;
  v10 = ATL::CSimpleStringT<char,0>::PrepareWrite(this: rString, nLength: nTotalLen);
  if ( *lpszFormat != 0 )
  {
    while ( *v9 == 37 )
    {
      v11 = v9[1];
      if ( v11 >= 49 && v11 <= 57 )
      {
        v12 = v11 - 49;
      }
      else
      {
        if ( v11 < 65 || v11 > 90 )
          break;
        v12 = v11 - 56;
      }
      v9 += 2;
      if ( v12 < nString )
      {
        v13 = (LPCSTR *)&rglpsz[v12];
        if ( *v13 != nullptr )
        {
          nLen = lstrlenA(lpString: *v13);
          ATL::Checked::tcscpy_s(_Dst: v10, _SizeInChars: nTotalLen + 1, _Src: *v13);
          nTotalLen -= nLen;
          v10 += nLen;
        }
        goto LABEL_36;
      }
      *v10++ = 63;
LABEL_35:
      --nTotalLen;
LABEL_36:
      if ( *v9 == 0 )
        goto LABEL_37;
    }
    if ( _ismbblead(tst: *v9) != 0 )
    {
      *v10++ = *v9++;
      --nTotalLen;
    }
    *v10++ = *v9++;
    goto LABEL_35;
  }
LABEL_37:
  ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: rString, nNewLength: v10 - rString->m_pszData);
}

//------------------------------------------------------------------------------
// Address: 0x103602E0
// Name: void AfxFormatStrings(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,unsigned int,char const __near * const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxFormatStrings(
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *rString,
        unsigned int nIDS,
        const char *const *rglpsz,
        int nString)
{
  CAfxStringMgr *StringManager; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  ATL::CStringData *v6; // ecx
  char *m_pszData; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strFormat; // [esp+10h] [ebp-10h] BYREF
  int v9; // [esp+1Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strFormat, pStringMgr: StringManager);
  v9 = 0;
  StringResourceHandle = AfxFindStringResourceHandle(__formal: nIDS);
  if ( StringResourceHandle != nullptr
    && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
         this: &strFormat,
         hInstance: StringResourceHandle,
         nID: nIDS) != 0 )
  {
    m_pszData = strFormat.m_pszData;
    AfxFormatStrings(rString, lpszFormat: strFormat.m_pszData, rglpsz, nString);
    v6 = (ATL::CStringData *)(m_pszData - 16);
  }
  else
  {
    v6 = (ATL::CStringData *)(strFormat.m_pszData - 16);
  }
  ATL::CStringData::Release(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10360344
// Name: void AfxFormatString1(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,unsigned int,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxFormatString1(
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *rString,
        unsigned int nIDS,
        const char *lpsz1)
{
  AfxFormatStrings(rString, nIDS, rglpsz: &lpsz1, nString: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1036035E
// Name: void AfxFormatString2(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,unsigned int,char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall AfxFormatString2(
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *rString,
        unsigned int nIDS,
        const char *lpsz1,
        const char *lpsz2)
{
  const char *rglpsz[2]; // [esp+0h] [ebp-8h] BYREF

  rglpsz[0] = lpsz1;
  rglpsz[1] = lpsz2;
  AfxFormatStrings(rString, nIDS, rglpsz, nString: 2);
}

//------------------------------------------------------------------------------
// Address: 0x10360386
// Name: public: void CMapStringToPtr::InitHashTable(unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMapStringToPtr::InitHashTable(CMapPtrToPtr *this, unsigned int nHashSize, int bAllocNow)
{
  unsigned int v3; // edi
  CMapPtrToPtr::CAssoc **v5; // eax

  v3 = nHashSize;
  if ( nHashSize == 0 )
    v3 = 17;
  if ( this->m_pHashTable != nullptr )
  {
    operator delete(p: this->m_pHashTable);
    this->m_pHashTable = nullptr;
  }
  if ( bAllocNow != 0 )
  {
    v5 = (CMapPtrToPtr::CAssoc **)operator new(nSize: 4 * v3);
    this->m_pHashTable = v5;
    memset(dst: (unsigned __int8 *)v5, value: 0, count: 4 * v3);
  }
  this->m_nHashTableSize = v3;
}

//------------------------------------------------------------------------------
// Address: 0x103603E4
// Name: public: void CMapPtrToPtr::RemoveAll(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMapPtrToPtr::RemoveAll(CMapPtrToPtr *this)
{
  CPlex *m_pBlocks; // ecx

  if ( this->m_pHashTable != nullptr )
  {
    operator delete(p: this->m_pHashTable);
    this->m_pHashTable = nullptr;
  }
  m_pBlocks = this->m_pBlocks;
  this->m_nCount = 0;
  this->m_pFreeList = nullptr;
  CPlex::FreeDataChain(this: m_pBlocks);
  this->m_pBlocks = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10360411
// Name: protected: void CMapPtrToPtr::FreeAssoc(struct CMapPtrToPtr::CAssoc __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMapPtrToPtr::FreeAssoc(CMapPtrToPtr *this, CMapPtrToPtr::CAssoc *pAssoc)
{
  bool v2; // zf

  pAssoc->pNext = this->m_pFreeList;
  v2 = this->m_nCount-- == 1;
  this->m_pFreeList = pAssoc;
  if ( v2 )
    CMapPtrToPtr::RemoveAll(this);
}

//------------------------------------------------------------------------------
// Address: 0x1036042F
// Name: public: virtual struct CRuntimeClass __near * CMapPtrToPtr::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMapPtrToPtr::GetRuntimeClass(CMapPtrToPtr *this)
{
  return &CMapPtrToPtr::classCMapPtrToPtr;
}

//------------------------------------------------------------------------------
// Address: 0x10360435
// Name: public: CMapPtrToPtr::CMapPtrToPtr(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMapPtrToPtr *__thiscall CMapPtrToPtr::CMapPtrToPtr(CMapPtrToPtr *this, int nBlockSize)
{
  CMapPtrToPtr *result; // eax
  int v3; // ecx

  result = this;
  v3 = nBlockSize;
  result->__vftable = (CMapPtrToPtr_vtbl *)&CMapPtrToPtr::`vftable';
  if ( nBlockSize <= 0 )
    v3 = 10;
  result->m_pHashTable = nullptr;
  result->m_nHashTableSize = 17;
  result->m_nCount = 0;
  result->m_pFreeList = nullptr;
  result->m_pBlocks = nullptr;
  result->m_nBlockSize = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10360468
// Name: public: virtual CMapPtrToPtr::~CMapPtrToPtr(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMapPtrToPtr::~CMapPtrToPtr(CMapPtrToPtr *this)
{
  this->__vftable = (CMapPtrToPtr_vtbl *)&CMapPtrToPtr::`vftable';
  CMapPtrToPtr::RemoveAll(this);
}

//------------------------------------------------------------------------------
// Address: 0x10367C61
// Name: char __near * AfxTaskStringW2A(wchar_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__stdcall AfxTaskStringW2A(wchar_t *lpw)
{
  char *v1; // esi

  v1 = ATL::AtlAllocTaskAnsiString(lpszString: lpw);
  CoTaskMemFree(pv: lpw);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x10367C82
// Name: public: long ATL::CRegKey::Create(struct HKEY__ __near *,char const __near *,char __near *,unsigned long,unsigned long,struct _SECURITY_ATTRIBUTES __near *,unsigned long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __thiscall ATL::CRegKey::Create(
        ATL::CRegKey *this,
        HKEY__ *hKeyParent,
        const char *lpszKeyName,
        char *lpszClass,
        DWORD dwOptions,
        REGSAM samDesired,
        _SECURITY_ATTRIBUTES *lpSecAttr,
        unsigned int *lpdwDisposition)
{
  ATL::CAtlTransactionManager *m_pTM; // ecx
  LSTATUS result; // eax
  HKEY__ *hKey; // [esp+8h] [ebp-4h] BYREF

  hKey = nullptr;
  m_pTM = this->m_pTM;
  if ( m_pTM != nullptr )
    result = ATL::CAtlTransactionManager::RegCreateKeyExA(
               this: m_pTM,
               hKey: hKeyParent,
               lpSubKey: lpszKeyName,
               dwReserved: 0,
               lpClass: lpszClass,
               dwOptions,
               samDesired,
               lpSecurityAttributes: lpSecAttr,
               phkResult: &hKey,
               lpdwDisposition: (unsigned int *)&lpSecAttr);
  else
    result = RegCreateKeyExA(
               hKey: hKeyParent,
               lpSubKey: lpszKeyName,
               Reserved: 0,
               lpClass: lpszClass,
               dwOptions,
               samDesired,
               lpSecurityAttributes: lpSecAttr,
               phkResult: &hKey,
               lpdwDisposition: (LPDWORD)&lpSecAttr);
  if ( lpdwDisposition != nullptr )
    *lpdwDisposition = (unsigned int)lpSecAttr;
  if ( result == 0 )
  {
    result = ATL::CRegKey::Close(this);
    this->m_hKey = hKey;
    this->m_samWOW64 = samDesired & 0x300;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10367CEC
// Name: long AfxRegCreateKey(struct HKEY__ __near *,char const __near *,struct HKEY__ __near * __near *,class ATL::CAtlTransactionManager __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __stdcall AfxRegCreateKey(
        HKEY__ *hKey,
        const char *lpSubKey,
        HKEY__ **phkResult,
        ATL::CAtlTransactionManager *pTM)
{
  HKEY__ *v4; // esi
  ATL::CStringData *v5; // eax
  LSTATUS Key; // eax
  LSTATUS v7; // esi
  DWORD dw[3]; // [esp+10h] [ebp-10h] BYREF
  int v10; // [esp+1Ch] [ebp-4h]

  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpSubKey,
    pszSrc: lpSubKey);
  v4 = hKey;
  v10 = 0;
  if ( hKey == (HKEY__ *)0x80000000 && AfxGetPerUserRegistration() == 1 )
  {
    v5 = (ATL::CStringData *)ATL::operator+(
                               result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&hKey,
                               psz1: "Software\\Classes\\",
                               str2: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpSubKey);
    ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&lpSubKey, strSrc: v5);
    LOBYTE(v10) = 0;
    ATL::CStringData::Release(this: (ATL::CStringData *)hKey - 1);
    v4 = (HKEY__ *)((char *)v4 + 1);
  }
  dw[0] = 0;
  if ( pTM != nullptr )
    Key = ATL::CAtlTransactionManager::RegCreateKeyExA(
            this: pTM,
            hKey: v4,
            lpSubKey,
            dwReserved: 0,
            lpClass: nullptr,
            dwOptions: 0,
            samDesired: 0x2001Fu,
            lpSecurityAttributes: nullptr,
            phkResult,
            lpdwDisposition: dw);
  else
    Key = RegCreateKeyExA(
            hKey: v4,
            lpSubKey,
            Reserved: 0,
            lpClass: nullptr,
            dwOptions: 0,
            samDesired: 0x2001Fu,
            lpSecurityAttributes: nullptr,
            phkResult,
            lpdwDisposition: dw);
  v7 = Key;
  ATL::CStringData::Release(this: (ATL::CStringData *)lpSubKey - 1);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10367D90
// Name: long AfxRegOpenKeyEx(struct HKEY__ __near *,char const __near *,unsigned long,unsigned long,struct HKEY__ __near * __near *,class ATL::CAtlTransactionManager __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __stdcall AfxRegOpenKeyEx(
        HKEY__ *hKey,
        const char *lpSubKey,
        DWORD ulOptions,
        REGSAM samDesired,
        HKEY__ **phkResult,
        ATL::CAtlTransactionManager *pTM)
{
  HKEY__ *v6; // esi
  ATL::CStringData *v7; // eax
  LSTATUS v8; // eax
  LSTATUS v9; // esi

  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpSubKey,
    pszSrc: lpSubKey);
  v6 = hKey;
  if ( hKey == (HKEY__ *)0x80000000 && AfxGetPerUserRegistration() == 1 )
  {
    v7 = (ATL::CStringData *)ATL::operator+(
                               result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&hKey,
                               psz1: "Software\\Classes\\",
                               str2: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpSubKey);
    ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&lpSubKey, strSrc: v7);
    ATL::CStringData::Release(this: (ATL::CStringData *)hKey - 1);
    v6 = (HKEY__ *)((char *)v6 + 1);
  }
  if ( pTM != nullptr )
    v8 = ATL::CAtlTransactionManager::RegOpenKeyExA(this: pTM, hKey: v6, lpSubKey, ulOptions, samDesired, phkResult);
  else
    v8 = RegOpenKeyExA(hKey: v6, lpSubKey, ulOptions, samDesired, phkResult);
  v9 = v8;
  ATL::CStringData::Release(this: (ATL::CStringData *)lpSubKey - 1);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10367E2A
// Name: long AfxRegQueryValue(struct HKEY__ __near *,char const __near *,char __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __stdcall AfxRegQueryValue(HKEY__ *hKey, const char *lpSubKey, char *lpValue, int *lpcbValue)
{
  ATL::CStringData *v4; // eax
  LSTATUS ValueA; // esi

  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpSubKey,
    pszSrc: lpSubKey);
  if ( hKey == (HKEY__ *)0x80000000 && AfxGetPerUserRegistration() == 1 )
  {
    v4 = (ATL::CStringData *)ATL::operator+(
                               result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&hKey,
                               psz1: "Software\\Classes\\",
                               str2: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpSubKey);
    ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&lpSubKey, strSrc: v4);
    ATL::CStringData::Release(this: (ATL::CStringData *)hKey - 1);
    hKey = (HKEY__ *)-2147483647;
  }
  ValueA = RegQueryValueA(hKey, lpSubKey, lpData: lpValue, lpcbData: lpcbValue);
  ATL::CStringData::Release(this: (ATL::CStringData *)lpSubKey - 1);
  return ValueA;
}

//------------------------------------------------------------------------------
// Address: 0x10367EB5
// Name: long AfxRegSetValue(struct HKEY__ __near *,char const __near *,unsigned long,char const __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LSTATUS __stdcall AfxRegSetValue(HKEY__ *hKey, const char *lpSubKey, DWORD dwType, const char *lpData, DWORD cbData)
{
  ATL::CStringData *v5; // eax
  LSTATUS v6; // esi

  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpSubKey,
    pszSrc: lpSubKey);
  if ( hKey == (HKEY__ *)0x80000000 && AfxGetPerUserRegistration() == 1 )
  {
    v5 = (ATL::CStringData *)ATL::operator+(
                               result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&hKey,
                               psz1: "Software\\Classes\\",
                               str2: (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpSubKey);
    ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&lpSubKey, strSrc: v5);
    ATL::CStringData::Release(this: (ATL::CStringData *)hKey - 1);
    hKey = (HKEY__ *)-2147483647;
  }
  v6 = RegSetValueA(hKey, lpSubKey, dwType, lpData, cbData);
  ATL::CStringData::Release(this: (ATL::CStringData *)lpSubKey - 1);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10367F43
// Name: int _AfxSetRegKey(char const __near *,char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall _AfxSetRegKey(HKEY__ *lpszKey, const char *lpszValue, const char *lpszValueName)
{
  DWORD v3; // eax
  int v5; // eax
  LSTATUS v6; // esi

  if ( lpszValueName != nullptr )
    return AfxRegCreateKey(
             hKey: (HKEY__ *)0x80000000,
             lpSubKey: (const char *)lpszKey,
             phkResult: &lpszKey,
             pTM: nullptr) == 0
        && (v5 = lstrlenA(lpString: lpszValue),
            v6 = RegSetValueExA(
                   hKey: lpszKey,
                   lpValueName: lpszValueName,
                   Reserved: 0,
                   dwType: 1u,
                   lpData: (const BYTE *)lpszValue,
                   cbData: v5 + 1),
            RegCloseKey(hKey: lpszKey) == 0)
        && v6 == 0;
  v3 = lstrlenA(lpString: lpszValue);
  return AfxRegSetValue(
           hKey: (HKEY__ *)0x80000000,
           lpSubKey: (const char *)lpszKey,
           dwType: 1u,
           lpData: lpszValue,
           cbData: v3) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10367FC4
// Name: public: CNewTypeDlg::CNewTypeDlg(class CPtrList __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CNewTypeDlg *__thiscall CNewTypeDlg::CNewTypeDlg(CNewTypeDlg *this, CPtrList *pList)
{
  CDialog::CDialog(this, nIDTemplate: 0x7801u, pParentWnd: nullptr);
  this->m_pSelectedTemplate = nullptr;
  this->m_pList = pList;
  this->__vftable = (CNewTypeDlg_vtbl *)&CNewTypeDlg::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10367FF5
// Name: public: virtual CNewTypeDlg::~CNewTypeDlg(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CNewTypeDlg::~CNewTypeDlg(CNewTypeDlg *this)
{
  this->__vftable = (CNewTypeDlg_vtbl *)&CNewTypeDlg::`vftable';
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x10368013
// Name: public: virtual struct CRuntimeClass __near * CDocManager::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CDocManager::GetRuntimeClass(CDocManager *this)
{
  return &CDocManager::classCDocManager;
}

//------------------------------------------------------------------------------
// Address: 0x10368021
// Name: public: CDocManager::CDocManager(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDocManager *__thiscall CDocManager::CDocManager(CDocManager *this)
{
  this->__vftable = (CDocManager_vtbl *)&CDocManager::`vftable';
  CPtrList::CPtrList(this: &this->m_templateList, nBlockSize: 10);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10368061
// Name: protected: virtual void CNewTypeDlg::OnOK(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CNewTypeDlg::OnOK(CNewTypeDlg *this)
{
  CWnd *DlgItem; // eax
  CWnd *v3; // edi
  WPARAM v4; // eax

  DlgItem = CWnd::GetDlgItem(this, nID: 100);
  v3 = DlgItem;
  if ( DlgItem == nullptr )
    AfxThrowInvalidArgException();
  v4 = SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  if ( v4 == -1 )
    this->m_pSelectedTemplate = nullptr;
  else
    this->m_pSelectedTemplate = (CDocTemplate *)SendMessageA(hWnd: v3->m_hWnd, Msg: 0x199u, wParam: v4, lParam: 0);
  CDialog::OnOK(this);
}

//------------------------------------------------------------------------------
// Address: 0x103680B9
// Name: public: virtual void CDocManager::AddDocTemplate(class CDocTemplate __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDocManager::AddDocTemplate(CDocManager *this, CDocTemplate *pTemplate)
{
  CPtrList *v3; // ecx
  CPtrList::CNode *m_pNodeHead; // esi
  CDocTemplate *data; // [esp-4h] [ebp-Ch]

  if ( pTemplate != nullptr )
  {
    pTemplate->LoadTemplate(this: pTemplate);
    CPtrList::AddTail(this: (CObList *)&this->m_templateList, newElement: pTemplate);
  }
  else
  {
    v3 = CDocManager::pStaticList;
    if ( CDocManager::pStaticList != nullptr )
    {
      m_pNodeHead = CDocManager::pStaticList->m_pNodeHead;
      if ( m_pNodeHead != nullptr )
      {
        do
        {
          data = (CDocTemplate *)m_pNodeHead->data;
          m_pNodeHead = m_pNodeHead->pNext;
          this->AddDocTemplate(this, a2: data);
        }
        while ( m_pNodeHead != nullptr );
        v3 = CDocManager::pStaticList;
      }
      if ( v3 != nullptr )
        ((void (__thiscall *)(CPtrList *, int))v3->dtr_CObject)(a1: v3, a2: 1);
      CDocManager::pStaticList = nullptr;
    }
    CDocManager::bStaticInit = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036812C
// Name: public: virtual class CDocTemplate __near * CDocManager::GetNextDocTemplate(struct __POSITION __near * __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDocTemplate *__thiscall CDocManager::GetNextDocTemplate(CDocManager *this, __POSITION **pos)
{
  return (CDocTemplate *)CPtrList::GetNext(this: &this->m_templateList, rPosition: pos);
}

//------------------------------------------------------------------------------
// Address: 0x1036813A
// Name: public: virtual int CDocManager::SaveAllModified(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDocManager::SaveAllModified(CDocManager *this)
{
  CPtrList::CNode *m_pNodeHead; // esi
  void *data; // ecx

  m_pNodeHead = this->m_templateList.m_pNodeHead;
  do
  {
    if ( m_pNodeHead == nullptr )
      return 1;
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
  }
  while ( (*(int (__thiscall **)(void *))(*(_DWORD *)data + 120))(a1: data) != 0 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10368441
// Name: public: virtual int CDocManager::GetOpenDocumentCount(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDocManager::GetOpenDocumentCount(CDocManager *this)
{
  CPtrList::CNode *m_pNodeHead; // esi
  int v2; // ebx
  void *data; // edi
  __POSITION *pos2; // [esp+8h] [ebp-4h] BYREF

  m_pNodeHead = this->m_templateList.m_pNodeHead;
  v2 = 0;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    pos2 = (__POSITION *)(*(int (__thiscall **)(void *))(*(_DWORD *)data + 84))(a1: data);
    while ( pos2 != nullptr )
    {
      if ( (*(int (__thiscall **)(void *, __POSITION **))(*(_DWORD *)data + 88))(a1: data, a2: &pos2) != 0 )
        ++v2;
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10368493
// Name: public: virtual class CDocTemplate __near * CDocManager::GetBestTemplate(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDocTemplate *__userpurge CDocManager::GetBestTemplate@<eax>(
        CDocManager *this@<ecx>,
        int a2@<edi>,
        const char *lpszFileName)
{
  int v3; // ebx
  CPtrList::CNode *m_pNodeHead; // esi
  CDocTemplate *data; // edi
  int v6; // eax
  int v8; // [esp-4h] [ebp-14h]
  CDocument *pOpenDocument; // [esp+8h] [ebp-8h] BYREF
  CDocTemplate *pBestTemplate; // [esp+Ch] [ebp-4h]

  v3 = 0;
  if ( lpszFileName == nullptr )
    AfxThrowInvalidArgException();
  m_pNodeHead = this->m_templateList.m_pNodeHead;
  pBestTemplate = nullptr;
  pOpenDocument = nullptr;
  if ( m_pNodeHead != nullptr )
  {
    v8 = a2;
    do
    {
      data = (CDocTemplate *)m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      v6 = ((int (__thiscall *)(CDocTemplate *, const char *, CDocument **, int))data->MatchDocType)(
             a1: data,
             a2: lpszFileName,
             a3: &pOpenDocument,
             a4: v8);
      if ( v6 > v3 )
      {
        v3 = v6;
        pBestTemplate = data;
      }
    }
    while ( m_pNodeHead != nullptr );
  }
  return pBestTemplate;
}

//------------------------------------------------------------------------------
// Address: 0x103684E6
// Name: public: virtual CDocManager::~CDocManager(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDocManager::~CDocManager(CDocManager *this)
{
  CPtrList::CNode *m_pNodeHead; // esi
  __POSITION *v3; // ecx
  _DWORD *data; // edi

  this->__vftable = (CDocManager_vtbl *)&CDocManager::`vftable';
  m_pNodeHead = this->m_templateList.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    v3 = (__POSITION *)m_pNodeHead;
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data[8] != 0 )
    {
      CPtrList::RemoveAt(this: (CObList *)&this->m_templateList, position: v3);
      (*(void (__thiscall **)(_DWORD *, int))(*data + 4))(a1: data, a2: 1);
    }
  }
  CPtrList::~CPtrList(this: &this->m_templateList);
}

//------------------------------------------------------------------------------
// Address: 0x10368568
// Name: protected: virtual struct AFX_MSGMAP const __near * CNewTypeDlg::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CNewTypeDlg::GetMessageMap(CNewTypeDlg *this)
{
  return (const AFX_MSGMAP *)&off_1067A290;
}

//------------------------------------------------------------------------------
// Address: 0x1036856E
// Name: protected: virtual int CNewTypeDlg::OnInitDialog(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CNewTypeDlg::OnInitDialog(CNewTypeDlg *this)
{
  CWnd *DlgItem; // edi
  CPtrList::CNode *m_pNodeHead; // ebx
  CDocTemplate *data; // eax
  CAfxStringMgr *StringManager; // eax
  CDocTemplate_vtbl *v6; // eax
  WPARAM v7; // eax
  LRESULT v8; // eax
  CDocTemplate *pTemplate; // [esp+10h] [ebp-18h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strTypeName; // [esp+18h] [ebp-10h] BYREF
  int v13; // [esp+24h] [ebp-4h]

  DlgItem = CWnd::GetDlgItem(this, nID: 100);
  if ( DlgItem == nullptr )
    AfxThrowInvalidArgException();
  SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0x184u, wParam: 0, lParam: 0);
  m_pNodeHead = this->m_pList->m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = (CDocTemplate *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    pTemplate = data;
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strTypeName, pStringMgr: StringManager);
    v6 = pTemplate->__vftable;
    v13 = 0;
    if ( v6->GetDocString(this: pTemplate, a2: &strTypeName, a3: fileNewName) != 0
      && *((_DWORD *)strTypeName.m_pszData - 3) != 0 )
    {
      v7 = SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0x180u, wParam: 0, lParam: (LPARAM)strTypeName.m_pszData);
      if ( v7 == -1 )
      {
        CDialog::EndDialog(this, nResult: -1);
        ATL::CStringData::Release(this: (ATL::CStringData *)strTypeName.m_pszData - 1);
        return 0;
      }
      SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0x19Au, wParam: v7, lParam: (LPARAM)pTemplate);
    }
    v13 = -1;
    ATL::CStringData::Release(this: (ATL::CStringData *)strTypeName.m_pszData - 1);
  }
  v8 = SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0);
  if ( v8 != 0 )
  {
    if ( v8 == 1 )
    {
      this->m_pSelectedTemplate = (CDocTemplate *)SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0x199u, wParam: 0, lParam: 0);
      CDialog::EndDialog(this, nResult: 1);
    }
    else
    {
      SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0x186u, wParam: 0, lParam: 0);
    }
  }
  else
  {
    CDialog::EndDialog(this, nResult: -1);
  }
  return CDialog::OnInitDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x103686F5
// Name: public: virtual void CDocManager::RegisterShellFileTypes(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDocManager::RegisterShellFileTypes(CDocManager *this, int bCompat)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v4; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  void *m_pNodeHead; // eax
  __POSITION *v7; // ecx
  char *v8; // esi
  char *v9; // ebx
  char *v10; // edi
  CAfxStringMgr *v11; // eax
  char *m_pszData; // edi
  AFX_MODULE_STATE *v13; // eax
  HICON IconA; // edi
  char *v15; // edi
  CAfxStringMgr *v16; // eax
  CAfxStringMgr *v17; // eax
  CAfxStringMgr *v18; // eax
  CDocTemplate_vtbl *v19; // eax
  CWinApp *m_pCurrentWinApp; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  char *v24; // esi
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  char *v29; // eax
  CAfxStringMgr *v30; // eax
  CDocTemplate_vtbl *v31; // eax
  CAfxStringMgr *v32; // eax
  CAfxStringMgr *v33; // eax
  CAfxStringMgr *v34; // eax
  CDocTemplate_vtbl *v35; // eax
  LSTATUS lResult; // [esp+10h] [ebp-58h]
  int lSize; // [esp+14h] [ebp-54h] BYREF
  __POSITION *pos; // [esp+18h] [ebp-50h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strDefaultIconCommandLine; // [esp+1Ch] [ebp-4Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strIconIndex; // [esp+20h] [ebp-48h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strShortTypeName; // [esp+24h] [ebp-44h] BYREF
  int nTemplateIndex; // [esp+28h] [ebp-40h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strOpenCommandLine; // [esp+2Ch] [ebp-3Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strPrintCommandLine; // [esp+30h] [ebp-38h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strLocalShortName; // [esp+34h] [ebp-34h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strServerName; // [esp+38h] [ebp-30h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strLocalServerName; // [esp+3Ch] [ebp-2Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strPathName; // [esp+40h] [ebp-28h] BYREF
  CDocTemplate *pTemplate; // [esp+44h] [ebp-24h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strPrintToCommandLine; // [esp+48h] [ebp-20h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strFileTypeName; // [esp+4Ch] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strFilterExt; // [esp+50h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strTemp; // [esp+54h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strFileTypeId; // [esp+58h] [ebp-10h] BYREF
  int v55; // [esp+64h] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strPathName, pStringMgr: StringManager);
  v55 = 0;
  v4 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strTemp, pStringMgr: v4);
  LOBYTE(v55) = 1;
  ModuleState = AfxGetModuleState();
  AfxGetModuleShortFileName(hInst: ModuleState->m_hCurrentInstanceHandle, strShortName: &strPathName);
  m_pNodeHead = this->m_templateList.m_pNodeHead;
  nTemplateIndex = 1;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      v7 = *(__POSITION **)m_pNodeHead;
      pTemplate = *((CDocTemplate **)m_pNodeHead + 2);
      pos = v7;
      v8 = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)strPathName.m_pszData - 1)[1];
      strOpenCommandLine.m_pszData = v8;
      LOBYTE(v55) = 2;
      v9 = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)strPathName.m_pszData - 1)[1];
      strPrintCommandLine.m_pszData = v9;
      LOBYTE(v55) = 3;
      strPrintToCommandLine.m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)strPathName.m_pszData - 1)[1];
      LOBYTE(v55) = 4;
      v10 = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)strPathName.m_pszData - 1)[1];
      strDefaultIconCommandLine.m_pszData = v10;
      LOBYTE(v55) = 5;
      if ( bCompat != 0 )
      {
        v11 = AfxGetStringManager();
        ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strIconIndex, pStringMgr: v11);
        m_pszData = strPathName.m_pszData;
        LOBYTE(v55) = 6;
        v13 = AfxGetModuleState();
        IconA = ExtractIconA(
                  hInst: v13->m_hCurrentInstanceHandle,
                  pszExeFileName: m_pszData,
                  nIconIndex: nTemplateIndex);
        if ( IconA != nullptr )
        {
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
            this: &strIconIndex,
            pszFormat: ",%d",
            nTemplateIndex);
          DestroyIcon(hIcon: IconA);
        }
        else
        {
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &strIconIndex, pszFormat: ",%d", 0);
        }
        v15 = strIconIndex.m_pszData;
        ATL::CSimpleStringT<char,0>::Append(
          this: &strDefaultIconCommandLine,
          pszSrc: strIconIndex.m_pszData,
          nLength: *((_DWORD *)strIconIndex.m_pszData - 3));
        LOBYTE(v55) = 5;
        ATL::CStringData::Release(this: (ATL::CStringData *)v15 - 1);
        v10 = strDefaultIconCommandLine.m_pszData;
      }
      v16 = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strFilterExt, pStringMgr: v16);
      LOBYTE(v55) = 7;
      v17 = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strFileTypeId, pStringMgr: v17);
      LOBYTE(v55) = 8;
      v18 = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strFileTypeName, pStringMgr: v18);
      v19 = pTemplate->__vftable;
      LOBYTE(v55) = 9;
      if ( v19->GetDocString(this: pTemplate, a2: &strFileTypeId, a3: regFileTypeId) == 0
        || *((_DWORD *)strFileTypeId.m_pszData - 3) == 0 )
      {
        goto LABEL_50;
      }
      if ( pTemplate->GetDocString(this: pTemplate, a2: &strFileTypeName, a3: regFileTypeName) == 0 )
        ATL::CSimpleStringT<char,0>::operator=(this: &strFileTypeName, strSrc: (ATL::CStringData *)&strFileTypeId);
      if ( !_AfxSetRegKey(
              lpszKey: (HKEY__ *)strFileTypeId.m_pszData,
              lpszValue: strFileTypeName.m_pszData,
              lpszValueName: nullptr) )
        goto LABEL_50;
      if ( afxGlobalData.bIsWindows7 != 0 )
      {
        m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
        lSize = (int)m_pCurrentWinApp;
        if ( m_pCurrentWinApp != nullptr )
        {
          strlen(buf: (unsigned __int8 *)m_pCurrentWinApp->m_pszAppID);
          if ( v21 != 0 )
            _AfxSetRegKey(
              lpszKey: (HKEY__ *)strFileTypeId.m_pszData,
              lpszValue: *(const char **)(lSize + 84),
              lpszValueName: "AppUserModelID");
        }
      }
      if ( bCompat != 0 )
      {
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
          this: &strTemp,
          pszFormat: "%s\\DefaultIcon",
          strFileTypeId.m_pszData);
        if ( !_AfxSetRegKey(lpszKey: (HKEY__ *)strTemp.m_pszData, lpszValue: v10, lpszValueName: nullptr) )
          goto LABEL_50;
      }
      if ( pTemplate->GetDocString(this: pTemplate, a2: &strTemp, a3: windowTitle) != 0
        && *((_DWORD *)strTemp.m_pszData - 3) != 0 )
      {
        break;
      }
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
        this: &strTemp,
        pszFormat: "%s\\shell\\open\\%s",
        strFileTypeId.m_pszData,
        "ddeexec");
      if ( !_AfxSetRegKey(lpszKey: (HKEY__ *)strTemp.m_pszData, lpszValue: "[open(\"%1\")]", lpszValueName: nullptr) )
        goto LABEL_50;
      if ( bCompat != 0 )
      {
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
          this: &strTemp,
          pszFormat: "%s\\shell\\print\\%s",
          strFileTypeId.m_pszData,
          "ddeexec");
        if ( !_AfxSetRegKey(lpszKey: (HKEY__ *)strTemp.m_pszData, lpszValue: "[print(\"%1\")]", lpszValueName: nullptr) )
          goto LABEL_50;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
          this: &strTemp,
          pszFormat: "%s\\shell\\printto\\%s",
          strFileTypeId.m_pszData,
          "ddeexec");
        if ( !_AfxSetRegKey(
                lpszKey: (HKEY__ *)strTemp.m_pszData,
                lpszValue: "[printto(\"%1\",\"%2\",\"%3\",\"%4\")]",
                lpszValueName: nullptr) )
          goto LABEL_50;
        strlen(buf: " /dde");
        ATL::CSimpleStringT<char,0>::Append(this: &strOpenCommandLine, pszSrc: " /dde", nLength: v25);
        v24 = " /ddenoshow";
        strlen(buf: " /ddenoshow");
        ATL::CSimpleStringT<char,0>::Append(this: &strPrintCommandLine, pszSrc: " /ddenoshow", nLength: v26);
LABEL_29:
        strlen(buf: (unsigned __int8 *)v24);
        ATL::CSimpleStringT<char,0>::Append(this: &strPrintToCommandLine, pszSrc: v24, nLength: v27);
        v9 = strPrintCommandLine.m_pszData;
        goto LABEL_31;
      }
      strlen(buf: " \"%1\"");
      ATL::CSimpleStringT<char,0>::Append(this: &strOpenCommandLine, pszSrc: " \"%1\"", nLength: v28);
LABEL_31:
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
        this: &strTemp,
        pszFormat: "%s\\shell\\open\\%s",
        strFileTypeId.m_pszData,
        "command");
      v8 = strOpenCommandLine.m_pszData;
      if ( _AfxSetRegKey(
             lpszKey: (HKEY__ *)strTemp.m_pszData,
             lpszValue: strOpenCommandLine.m_pszData,
             lpszValueName: nullptr) )
      {
        if ( bCompat == 0
          || (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
                this: &strTemp,
                pszFormat: "%s\\shell\\print\\%s",
                strFileTypeId.m_pszData,
                "command"),
              _AfxSetRegKey(lpszKey: (HKEY__ *)strTemp.m_pszData, lpszValue: v9, lpszValueName: nullptr))
          && (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
                this: &strTemp,
                pszFormat: "%s\\shell\\printto\\%s",
                strFileTypeId.m_pszData,
                "command"),
              _AfxSetRegKey(
                lpszKey: (HKEY__ *)strTemp.m_pszData,
                lpszValue: strPrintToCommandLine.m_pszData,
                lpszValueName: nullptr)) )
        {
          pTemplate->GetDocString(this: pTemplate, a2: &strFilterExt, a3: filterExt);
          if ( *((_DWORD *)strFilterExt.m_pszData - 3) != 0 )
          {
            lSize = 520;
            v29 = ATL::CSimpleStringT<char,0>::PrepareWrite(this: &strTemp, nLength: 520);
            lResult = AfxRegQueryValue(
                        hKey: (HKEY__ *)0x80000000,
                        lpSubKey: strFilterExt.m_pszData,
                        lpValue: v29,
                        lpcbValue: &lSize);
            ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: &strTemp, nNewLength: -1);
            if ( lResult != 0
              || *((_DWORD *)strTemp.m_pszData - 3) == 0
              || ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
                   this: &strTemp,
                   psz: strFileTypeId.m_pszData) == 0 )
            {
              if ( !_AfxSetRegKey(
                      lpszKey: (HKEY__ *)strFilterExt.m_pszData,
                      lpszValue: strFileTypeId.m_pszData,
                      lpszValueName: nullptr) )
                goto LABEL_50;
              if ( bCompat != 0 )
              {
                ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
                  this: &strTemp,
                  pszFormat: "%s\\ShellNew",
                  strFilterExt.m_pszData);
                _AfxSetRegKey(
                  lpszKey: (HKEY__ *)strTemp.m_pszData,
                  lpszValue: _afxShellNewValue,
                  lpszValueName: "NullFile");
              }
            }
            if ( *((_DWORD *)pTemplate->m_strCLSID.m_pszData - 3) != 0 )
            {
              v30 = AfxGetStringManager();
              ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strShortTypeName, pStringMgr: v30);
              v31 = pTemplate->__vftable;
              LOBYTE(v55) = 10;
              v31->GetDocString(this: pTemplate, a2: &strShortTypeName, a3: fileNewName);
              AfxRegisterPreviewHandler(
                lpszCLSID: pTemplate->m_strCLSID.m_pszData,
                lpszShortTypeName: strShortTypeName.m_pszData,
                lpszFilterExt: strFilterExt.m_pszData);
              v32 = AfxGetStringManager();
              ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strServerName, pStringMgr: v32);
              LOBYTE(v55) = 11;
              v33 = AfxGetStringManager();
              ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strLocalServerName, pStringMgr: v33);
              LOBYTE(v55) = 12;
              v34 = AfxGetStringManager();
              ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strLocalShortName, pStringMgr: v34);
              v35 = pTemplate->__vftable;
              LOBYTE(v55) = 13;
              if ( v35->GetDocString(this: pTemplate, a2: &strServerName, a3: regFileTypeId) == 0
                || *((_DWORD *)strServerName.m_pszData - 3) == 0 )
              {
                ATL::CStringData::Release(this: (ATL::CStringData *)strLocalShortName.m_pszData - 1);
                ATL::CStringData::Release(this: (ATL::CStringData *)strLocalServerName.m_pszData - 1);
                ATL::CStringData::Release(this: (ATL::CStringData *)strServerName.m_pszData - 1);
                ATL::CStringData::Release(this: (ATL::CStringData *)strShortTypeName.m_pszData - 1);
                ATL::CStringData::Release(this: (ATL::CStringData *)strFileTypeName.m_pszData - 1);
                ATL::CStringData::Release(this: (ATL::CStringData *)strFileTypeId.m_pszData - 1);
                ATL::CStringData::Release(this: (ATL::CStringData *)strFilterExt.m_pszData - 1);
                ATL::CStringData::Release(this: (ATL::CStringData *)v10 - 1);
                ATL::CStringData::Release(this: (ATL::CStringData *)strPrintToCommandLine.m_pszData - 1);
                ATL::CStringData::Release(this: (ATL::CStringData *)v9 - 1);
                ATL::CStringData::Release(this: (ATL::CStringData *)v8 - 1);
                goto LABEL_53;
              }
              if ( pTemplate->GetDocString(this: pTemplate, a2: &strLocalServerName, a3: regFileTypeName) == 0 )
                ATL::CSimpleStringT<char,0>::operator=(
                  this: &strLocalServerName,
                  strSrc: (ATL::CStringData *)&strServerName);
              if ( pTemplate->GetDocString(this: pTemplate, a2: &strLocalShortName, a3: fileNewName) == 0 )
                ATL::CSimpleStringT<char,0>::operator=(
                  this: &strLocalShortName,
                  strSrc: (ATL::CStringData *)&strLocalServerName);
              AfxOleRegisterServerClass(
                clsid: &pTemplate->m_clsid,
                lpszClassName: strServerName.m_pszData,
                lpszShortTypeName: strLocalShortName.m_pszData,
                lpszLongTypeName: strLocalServerName.m_pszData,
                nAppType: OAT_DISPATCH_OBJECT,
                rglpszRegister: nullptr,
                rglpszOverwrite: nullptr,
                nIconIndex: 0,
                lpszFilterName: nullptr,
                lpszFilterExt: nullptr);
              ATL::CStringData::Release(this: (ATL::CStringData *)strLocalShortName.m_pszData - 1);
              ATL::CStringData::Release(this: (ATL::CStringData *)strLocalServerName.m_pszData - 1);
              ATL::CStringData::Release(this: (ATL::CStringData *)strServerName.m_pszData - 1);
              ATL::CStringData::Release(this: (ATL::CStringData *)strShortTypeName.m_pszData - 1);
            }
          }
        }
      }
LABEL_50:
      ATL::CStringData::Release(this: (ATL::CStringData *)strFileTypeName.m_pszData - 1);
      ATL::CStringData::Release(this: (ATL::CStringData *)strFileTypeId.m_pszData - 1);
      ATL::CStringData::Release(this: (ATL::CStringData *)strFilterExt.m_pszData - 1);
      ATL::CStringData::Release(this: (ATL::CStringData *)v10 - 1);
      ATL::CStringData::Release(this: (ATL::CStringData *)strPrintToCommandLine.m_pszData - 1);
      ATL::CStringData::Release(this: (ATL::CStringData *)v9 - 1);
      LOBYTE(v55) = 1;
      ATL::CStringData::Release(this: (ATL::CStringData *)v8 - 1);
      ++nTemplateIndex;
      if ( pos == nullptr )
        goto LABEL_53;
      m_pNodeHead = pos;
    }
    strlen(buf: " \"%1\"");
    ATL::CSimpleStringT<char,0>::Append(this: &strOpenCommandLine, pszSrc: " \"%1\"", nLength: v22);
    if ( bCompat == 0 )
      goto LABEL_31;
    strlen(buf: " /p \"%1\"");
    ATL::CSimpleStringT<char,0>::Append(this: &strPrintCommandLine, pszSrc: " /p \"%1\"", nLength: v23);
    v24 = " /pt \"%1\" \"%2\" \"%3\" \"%4\"";
    goto LABEL_29;
  }
LABEL_53:
  ATL::CStringData::Release(this: (ATL::CStringData *)strTemp.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)strPathName.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x10368DBF
// Name: public: virtual int CDocManager::OnDDECommand(char __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDocManager::OnDDECommand(CDocManager *this, char *lpszCommand)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v2; // eax
  char v3; // bl
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v4; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v5; // eax
  char v6; // bl
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v7; // eax
  char v8; // bl
  int v9; // eax
  int v10; // esi
  ATL::CStringData *v11; // eax
  ATL::CStringData *v12; // eax
  CWinApp *m_pCurrentWinApp; // esi
  CWnd *m_pMainWnd; // ebx
  int m_nCmdShow; // esi
  AFX_MODULE_STATE *ModuleState; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v17; // eax
  bool v18; // bl
  ATL::CStringData *v19; // eax
  int v20; // eax
  int v21; // ebx
  ATL::CStringData *v22; // eax
  ATL::CStringData *v23; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v24; // eax
  bool v25; // bl
  ATL::CStringData *v26; // eax
  int v27; // eax
  int v28; // ebx
  ATL::CStringData *v29; // eax
  ATL::CStringData *v30; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v31; // eax
  bool v32; // bl
  ATL::CStringData *v33; // eax
  int v34; // eax
  int v35; // esi
  ATL::CStringData *v36; // eax
  ATL::CStringData *v37; // eax
  int DocumentCount; // esi
  AFX_MODULE_STATE *v39; // eax
  int v40; // ebx
  AFX_MODULE_STATE *v41; // eax
  AFX_MODULE_STATE *v42; // eax
  CDocManager *v43; // ecx
  AFX_MODULE_STATE *v44; // eax
  CCommandLineInfo cmdInfo; // [esp+10h] [ebp-48h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v47; // [esp+3Ch] [ebp-1Ch] BYREF
  CCommandLineInfo *pOldInfo; // [esp+40h] [ebp-18h] BYREF
  CDocManager *v49; // [esp+44h] [ebp-14h]
  int bRetVal; // [esp+48h] [ebp-10h]
  int v51; // [esp+54h] [ebp-4h]

  v49 = this;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
    pszSrc: lpszCommand);
  v51 = 0;
  CCommandLineInfo::CCommandLineInfo(this: &cmdInfo);
  LOBYTE(v51) = 1;
  cmdInfo.m_nShellCommand = FileDDE;
  v2 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
         this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
         result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pOldInfo,
         nCount: 7);
  LOBYTE(v51) = 2;
  v3 = -(ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(this: v2, psz: "[open(\"") != 0);
  LOBYTE(v51) = 1;
  ATL::CStringData::Release(this: (ATL::CStringData *)&pOldInfo[-1].m_strPrinterName);
  if ( v3 == -1 )
  {
    v5 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
           this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
           result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pOldInfo,
           nCount: 8);
    LOBYTE(v51) = 4;
    v6 = -(ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(this: v5, psz: "[print(\"") != 0);
    LOBYTE(v51) = 1;
    ATL::CStringData::Release(this: (ATL::CStringData *)&pOldInfo[-1].m_strPrinterName);
    if ( v6 == -1 )
    {
      v7 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
             this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
             result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pOldInfo,
             nCount: 10);
      LOBYTE(v51) = 6;
      v8 = -(ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(this: v7, psz: "[printto(\"") != 0);
      LOBYTE(v51) = 1;
      ATL::CStringData::Release(this: (ATL::CStringData *)&pOldInfo[-1].m_strPrinterName);
      if ( v8 == -1 )
        goto LABEL_34;
      cmdInfo.m_nShellCommand = FilePrintTo;
      v4 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Right(
             this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
             result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pOldInfo,
             nCount: *((_DWORD *)lpszCommand - 3) - 10);
      LOBYTE(v51) = 7;
    }
    else
    {
      cmdInfo.m_nShellCommand = FilePrint;
      v4 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Right(
             this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
             result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pOldInfo,
             nCount: *((_DWORD *)lpszCommand - 3) - 8);
      LOBYTE(v51) = 5;
    }
  }
  else
  {
    cmdInfo.m_nShellCommand = FileOpen;
    v4 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Right(
           this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
           result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pOldInfo,
           nCount: *((_DWORD *)lpszCommand - 3) - 7);
    LOBYTE(v51) = 3;
  }
  ATL::CSimpleStringT<char,0>::operator=(
    this: (ATL::CSimpleStringT<char,0> *)&lpszCommand,
    strSrc: (ATL::CStringData *)v4);
  LOBYTE(v51) = 1;
  ATL::CStringData::Release(this: (ATL::CStringData *)&pOldInfo[-1].m_strPrinterName);
  v9 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
         this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
         ch: 0x22u,
         iStart: 0);
  v10 = v9;
  if ( v9 != -1 )
  {
    v11 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
                                this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
                                result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pOldInfo,
                                nCount: v9);
    LOBYTE(v51) = 8;
    ATL::CSimpleStringT<char,0>::operator=(this: &cmdInfo.m_strFileName, strSrc: v11);
    LOBYTE(v51) = 1;
    ATL::CStringData::Release(this: (ATL::CStringData *)&pOldInfo[-1].m_strPrinterName);
    v12 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Right(
                                this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
                                result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pOldInfo,
                                nCount: *((_DWORD *)lpszCommand - 3) - v10);
    LOBYTE(v51) = 9;
    ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&lpszCommand, strSrc: v12);
    LOBYTE(v51) = 1;
    ATL::CStringData::Release(this: (ATL::CStringData *)&pOldInfo[-1].m_strPrinterName);
    pOldInfo = nullptr;
    bRetVal = 1;
    if ( AfxGetModuleState()->m_pCurrentWinApp->m_pCmdInfo != nullptr )
    {
      m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
      AfxGetModuleState()->m_pCurrentWinApp->m_nCmdShow = (int)m_pCurrentWinApp->m_pCmdInfo;
      AfxGetModuleState()->m_pCurrentWinApp->m_pCmdInfo = &cmdInfo;
    }
    else
    {
      pOldInfo = AfxGetModuleState()->m_pCurrentWinApp->m_pCmdInfo;
    }
    if ( cmdInfo.m_nShellCommand == FileOpen )
    {
      m_pMainWnd = AfxGetModuleState()->m_pCurrentWinApp->m_pMainWnd;
      m_nCmdShow = AfxGetModuleState()->m_pCurrentWinApp->m_nCmdShow;
      if ( m_nCmdShow == -1 || m_nCmdShow == 1 )
        m_nCmdShow = IsIconic(hWnd: m_pMainWnd->m_hWnd) ? 9 : 5;
      CWnd::ShowWindow(this: m_pMainWnd, nCmdShow: m_nCmdShow);
      if ( m_nCmdShow != 6 )
        SetForegroundWindow(hWnd: m_pMainWnd->m_hWnd);
      ModuleState = AfxGetModuleState();
      ModuleState->m_pCurrentWinApp->OpenDocumentFile(
        this: ModuleState->m_pCurrentWinApp,
        a2: cmdInfo.m_strFileName.m_pszData);
      if ( AfxOleGetUserCtrl() == 0 )
        AfxOleSetUserCtrl(bUserCtrl: 1);
      AfxGetModuleState()->m_pCurrentWinApp->m_nCmdShow = -1;
      goto RestoreAndReturn;
    }
    if ( cmdInfo.m_nShellCommand == FilePrintTo )
    {
      v17 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
              this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
              result: &v47,
              nCount: 3);
      LOBYTE(v51) = 10;
      v18 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(this: v17, psz: "\",\"") != 0;
      LOBYTE(v51) = 1;
      ATL::CStringData::Release(this: (ATL::CStringData *)v47.m_pszData - 1);
      if ( v18 )
        goto LABEL_22;
      v19 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Right(
                                  this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
                                  result: &v47,
                                  nCount: *((_DWORD *)lpszCommand - 3) - 3);
      LOBYTE(v51) = 11;
      ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&lpszCommand, strSrc: v19);
      LOBYTE(v51) = 1;
      ATL::CStringData::Release(this: (ATL::CStringData *)v47.m_pszData - 1);
      v20 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
              this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
              ch: 0x22u,
              iStart: 0);
      v21 = v20;
      if ( v20 == -1 )
        goto LABEL_22;
      v22 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
                                  this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
                                  result: &v47,
                                  nCount: v20);
      LOBYTE(v51) = 12;
      ATL::CSimpleStringT<char,0>::operator=(this: &cmdInfo.m_strPrinterName, strSrc: v22);
      LOBYTE(v51) = 1;
      ATL::CStringData::Release(this: (ATL::CStringData *)v47.m_pszData - 1);
      v23 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Right(
                                  this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
                                  result: &v47,
                                  nCount: *((_DWORD *)lpszCommand - 3) - v21);
      LOBYTE(v51) = 13;
      ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&lpszCommand, strSrc: v23);
      LOBYTE(v51) = 1;
      ATL::CStringData::Release(this: (ATL::CStringData *)v47.m_pszData - 1);
      v24 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
              this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
              result: &v47,
              nCount: 3);
      LOBYTE(v51) = 14;
      v25 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(this: v24, psz: "\",\"") != 0;
      LOBYTE(v51) = 1;
      ATL::CStringData::Release(this: (ATL::CStringData *)v47.m_pszData - 1);
      if ( v25 )
        goto LABEL_22;
      v26 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Right(
                                  this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
                                  result: &v47,
                                  nCount: *((_DWORD *)lpszCommand - 3) - 3);
      LOBYTE(v51) = 15;
      ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&lpszCommand, strSrc: v26);
      LOBYTE(v51) = 1;
      ATL::CStringData::Release(this: (ATL::CStringData *)v47.m_pszData - 1);
      v27 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
              this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
              ch: 0x22u,
              iStart: 0);
      v28 = v27;
      if ( v27 == -1 )
        goto LABEL_22;
      v29 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
                                  this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
                                  result: &v47,
                                  nCount: v27);
      LOBYTE(v51) = 16;
      ATL::CSimpleStringT<char,0>::operator=(this: &cmdInfo.m_strDriverName, strSrc: v29);
      LOBYTE(v51) = 1;
      ATL::CStringData::Release(this: (ATL::CStringData *)v47.m_pszData - 1);
      v30 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Right(
                                  this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
                                  result: &v47,
                                  nCount: *((_DWORD *)lpszCommand - 3) - v28);
      LOBYTE(v51) = 17;
      ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&lpszCommand, strSrc: v30);
      LOBYTE(v51) = 1;
      ATL::CStringData::Release(this: (ATL::CStringData *)v47.m_pszData - 1);
      v31 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
              this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
              result: &v47,
              nCount: 3);
      LOBYTE(v51) = 18;
      v32 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(this: v31, psz: "\",\"") != 0;
      LOBYTE(v51) = 1;
      ATL::CStringData::Release(this: (ATL::CStringData *)v47.m_pszData - 1);
      if ( v32
        || (v33 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Right(
                                        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
                                        result: &v47,
                                        nCount: *((_DWORD *)lpszCommand - 3) - 3),
            LOBYTE(v51) = 19,
            ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&lpszCommand, strSrc: v33),
            LOBYTE(v51) = 1,
            ATL::CStringData::Release(this: (ATL::CStringData *)v47.m_pszData - 1),
            v34 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
                    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
                    ch: 0x22u,
                    iStart: 0),
            v35 = v34,
            v34 == -1) )
      {
LABEL_22:
        bRetVal = 0;
RestoreAndReturn:
        AfxGetModuleState()->m_pCurrentWinApp->m_pCmdInfo = pOldInfo;
        LOBYTE(v51) = 0;
        CCommandLineInfo::~CCommandLineInfo(this: &cmdInfo);
        ATL::CStringData::Release(this: (ATL::CStringData *)lpszCommand - 1);
        return bRetVal;
      }
      v36 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
                                  this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
                                  result: &v47,
                                  nCount: v34);
      LOBYTE(v51) = 20;
      ATL::CSimpleStringT<char,0>::operator=(this: &cmdInfo.m_strPortName, strSrc: v36);
      LOBYTE(v51) = 1;
      ATL::CStringData::Release(this: (ATL::CStringData *)v47.m_pszData - 1);
      v37 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Right(
                                  this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lpszCommand,
                                  result: &v47,
                                  nCount: *((_DWORD *)lpszCommand - 3) - v35);
      LOBYTE(v51) = 21;
      ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&lpszCommand, strSrc: v37);
      LOBYTE(v51) = 1;
      ATL::CStringData::Release(this: (ATL::CStringData *)v47.m_pszData - 1);
    }
    DocumentCount = CDocManager::GetDocumentCount(this: v49);
    v39 = AfxGetModuleState();
    v40 = (int)v39->m_pCurrentWinApp->OpenDocumentFile(
                 this: v39->m_pCurrentWinApp,
                 a2: cmdInfo.m_strFileName.m_pszData,
                 a3: 0);
    AfxGetModuleState()->m_pCurrentWinApp->m_pCmdInfo = &cmdInfo;
    v41 = AfxGetModuleState();
    SendMessageA(hWnd: v41->m_pCurrentWinApp->m_pMainWnd->m_hWnd, Msg: 0x111u, wParam: 0xE108u, lParam: 0);
    v42 = AfxGetModuleState();
    v43 = v49;
    v42->m_pCurrentWinApp->m_pCmdInfo = nullptr;
    if ( CDocManager::GetDocumentCount(this: v43) > DocumentCount )
      (*(void (__thiscall **)(int))(*(_DWORD *)v40 + 132))(a1: v40);
    if ( AfxOleGetUserCtrl() == 0 )
    {
      v44 = AfxGetModuleState();
      PostMessageA(hWnd: v44->m_pCurrentWinApp->m_pMainWnd->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
    }
    goto RestoreAndReturn;
  }
LABEL_34:
  LOBYTE(v51) = 0;
  CCommandLineInfo::~CCommandLineInfo(this: &cmdInfo);
  ATL::CStringData::Release(this: (ATL::CStringData *)lpszCommand - 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103693E2
// Name: void _AfxAppendFilterSuffix(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,struct tagOFNA __near &,class CDocTemplate __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _AfxAppendFilterSuffix(
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *filter,
        tagOFNA *ofn,
        CDocTemplate *pTemplate,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *pstrDefaultExt)
{
  CDocTemplate *v4; // esi
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v6; // eax
  CDocTemplate_vtbl *v7; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v8; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v9; // ebx
  tagOFNA *v10; // esi
  ATL::CStringData *v11; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strFilterExt; // [esp+10h] [ebp-10h] BYREF
  int v13; // [esp+1Ch] [ebp-4h]

  v4 = pTemplate;
  if ( pTemplate == nullptr )
    AfxThrowInvalidArgException();
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strFilterExt, pStringMgr: StringManager);
  v13 = 0;
  v6 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: (ATL::CSimpleStringT<char,0> *)&pTemplate, pStringMgr: v6);
  v7 = v4->__vftable;
  LOBYTE(v13) = 1;
  if ( v7->GetDocString(this: v4, a2: &strFilterExt, a3: filterExt) != 0
    && *((_DWORD *)strFilterExt.m_pszData - 3) != 0
    && v4->GetDocString(
         this: v4,
         a2: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pTemplate,
         a3: filterName) != 0
    && pTemplate[-1].m_pPreviewFrameClass != nullptr )
  {
    v8 = pstrDefaultExt;
    if ( pstrDefaultExt != nullptr )
      ATL::CSimpleStringT<char,0>::Empty(this: pstrDefaultExt);
    v9 = filter;
    ATL::CSimpleStringT<char,0>::Append(
      this: filter,
      pszSrc: (char *)pTemplate,
      nLength: (int)pTemplate[-1].m_pPreviewFrameClass);
    ATL::CSimpleStringT<char,0>::AppendChar(this: v9, ch: 0);
    filter = nullptr;
    v10 = ofn;
    do
    {
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Tokenize(
        this: &strFilterExt,
        result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pstrDefaultExt,
        pszTokens: ";",
        iStart: (int *)&filter);
      LOBYTE(v13) = 2;
      if ( filter != (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)-1 )
      {
        if ( v8 != nullptr && *((_DWORD *)v8->m_pszData - 3) == 0 )
        {
          v11 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Mid(
                                      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pstrDefaultExt,
                                      result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&ofn,
                                      iFirst: 1);
          LOBYTE(v13) = 3;
          ATL::CSimpleStringT<char,0>::operator=(this: v8, strSrc: v11);
          LOBYTE(v13) = 2;
          ATL::CStringData::Release(this: (ATL::CStringData *)&ofn[-1].lpTemplateName);
          v10->lpstrDefExt = v8->m_pszData;
          v10->nFilterIndex = v10->nMaxCustFilter + 1;
        }
        ATL::CSimpleStringT<char,0>::AppendChar(this: v9, ch: 42);
        ATL::CSimpleStringT<char,0>::Append(
          this: v9,
          pszSrc: (char *)pstrDefaultExt,
          nLength: (int)pstrDefaultExt[-3].m_pszData);
        ATL::CSimpleStringT<char,0>::AppendChar(this: v9, ch: 59);
      }
      LOBYTE(v13) = 1;
      ATL::CStringData::Release(this: (ATL::CStringData *)&pstrDefaultExt[-4]);
    }
    while ( filter != (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)-1 );
    ATL::CSimpleStringT<char,0>::SetAt(this: v9, iChar: *((_DWORD *)v9->m_pszData - 3) - 1, ch: 0);
    ++v10->nMaxCustFilter;
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)&pTemplate[-1].m_pOleViewClass);
  ATL::CStringData::Release(this: (ATL::CStringData *)strFilterExt.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1036955A
// Name: public: virtual int CDocManager::DoPromptFileName(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,unsigned int,unsigned long,int,class CDocTemplate __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDocManager::DoPromptFileName(
        CDocManager *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *fileName,
        unsigned int nIDSTitle,
        unsigned int lFlags,
        int bOpenFileDialog,
        CDocTemplate *pTemplate)
{
  CAfxStringMgr *StringManager; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  int StringA; // eax
  int IsAlwaysLargeImage; // eax
  CAfxStringMgr *v11; // eax
  CAfxStringMgr *v12; // eax
  tagOFNA *v13; // eax
  CPtrList::CNode *m_pNodeHead; // esi
  int v15; // ecx
  CDocTemplate *data; // eax
  tagOFNA *v17; // eax
  CAfxStringMgr *v18; // eax
  HINSTANCE__ *v19; // eax
  char *m_pszData; // edi
  int v21; // eax
  int v22; // eax
  ATL::CSimpleStringT<char,0> *v23; // eax
  char *v24; // esi
  ATL::CSimpleStringT<char,0> *v25; // eax
  char *v26; // ebx
  int v27; // eax
  CDocTemplate *v29; // [esp-8h] [ebp-244h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v30; // [esp-4h] [ebp-240h]
  ATL::CSimpleStringT<char,0> v31; // [esp+14h] [ebp-228h] BYREF
  ATL::CSimpleStringT<char,0> v32; // [esp+18h] [ebp-224h] BYREF
  ATL::CSimpleStringT<char,0> v33; // [esp+1Ch] [ebp-220h] BYREF
  int v34; // [esp+20h] [ebp-21Ch]
  ATL::CSimpleStringT<char,0> v35; // [esp+24h] [ebp-218h] BYREF
  CFileDialog v36; // [esp+28h] [ebp-214h] BYREF
  int v37; // [esp+238h] [ebp-4h]

  CFileDialog::CFileDialog(
    this: &v36,
    bOpenFileDialog,
    lpszDefExt: nullptr,
    lpszFileName: nullptr,
    dwFlags: 6u,
    lpszFilter: nullptr,
    pParentWnd: nullptr,
    dwSize: 0,
    bVistaStyle: 1);
  v37 = 0;
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v32, pStringMgr: StringManager);
  LOBYTE(v37) = 1;
  StringResourceHandle = AfxFindStringResourceHandle(__formal: nIDSTitle);
  if ( StringResourceHandle != nullptr )
    StringA = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v32,
                hInstance: StringResourceHandle,
                nID: nIDSTitle);
  else
    StringA = 0;
  if ( StringA == 0 )
    AfxThrowInvalidArgException();
  IsAlwaysLargeImage = CMFCRibbonBaseElement::IsAlwaysLargeImage(this: (CMFCRibbonBaseElement *)&v36);
  *(_DWORD *)(IsAlwaysLargeImage + 52) |= lFlags;
  v11 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v35, pStringMgr: v11);
  LOBYTE(v37) = 2;
  v12 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v33, pStringMgr: v12);
  LOBYTE(v37) = 3;
  if ( pTemplate != nullptr )
  {
    v13 = (tagOFNA *)CMFCRibbonBaseElement::IsAlwaysLargeImage(this: (CMFCRibbonBaseElement *)&v36);
    _AfxAppendFilterSuffix(
      filter: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v35,
      ofn: v13,
      pTemplate,
      pstrDefaultExt: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v33);
  }
  else
  {
    m_pNodeHead = this->m_templateList.m_pNodeHead;
    v15 = 1;
    while ( m_pNodeHead != nullptr )
    {
      data = (CDocTemplate *)m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      v30 = v15 != 0 ? (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v33 : nullptr;
      v29 = data;
      v17 = (tagOFNA *)CMFCRibbonBaseElement::IsAlwaysLargeImage(this: (CMFCRibbonBaseElement *)&v36);
      _AfxAppendFilterSuffix(
        filter: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v35,
        ofn: v17,
        pTemplate: v29,
        pstrDefaultExt: v30);
      v15 = 0;
    }
  }
  v18 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v31, pStringMgr: v18);
  LOBYTE(v37) = 4;
  v19 = AfxFindStringResourceHandle(__formal: 0xF002u);
  if ( v19 != nullptr )
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v31,
      hInstance: v19,
      nID: 0xF002u);
  m_pszData = v31.m_pszData;
  ATL::CSimpleStringT<char,0>::Append(this: &v35, pszSrc: v31.m_pszData, nLength: *((_DWORD *)v31.m_pszData - 3));
  ATL::CSimpleStringT<char,0>::AppendChar(this: &v35, ch: 0);
  strlen(buf: "*.*");
  ATL::CSimpleStringT<char,0>::Append(this: &v35, pszSrc: "*.*", nLength: v21);
  ATL::CSimpleStringT<char,0>::AppendChar(this: &v35, ch: 0);
  v22 = CMFCRibbonBaseElement::IsAlwaysLargeImage(this: (CMFCRibbonBaseElement *)&v36);
  ++*(_DWORD *)(v22 + 20);
  v23 = (ATL::CSimpleStringT<char,0> *)CMFCRibbonBaseElement::IsAlwaysLargeImage(this: (CMFCRibbonBaseElement *)&v36);
  v24 = v35.m_pszData;
  v23[3].m_pszData = v35.m_pszData;
  v25 = (ATL::CSimpleStringT<char,0> *)CMFCRibbonBaseElement::IsAlwaysLargeImage(this: (CMFCRibbonBaseElement *)&v36);
  v26 = v32.m_pszData;
  v25[12].m_pszData = v32.m_pszData;
  v34 = (int)ATL::CSimpleStringT<char,0>::PrepareWrite(this: fileName, nLength: 260);
  v27 = CMFCRibbonBaseElement::IsAlwaysLargeImage(this: (CMFCRibbonBaseElement *)&v36);
  *(_DWORD *)(v27 + 28) = v34;
  v34 = CFileDialog::DoModal(this: &v36);
  ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: fileName, nNewLength: -1);
  v34 = v34 == 1;
  ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)v33.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)v24 - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)v26 - 1);
  v37 = -1;
  CFileDialog::~CFileDialog(this: &v36);
  return v34;
}

//------------------------------------------------------------------------------
// Address: 0x103697C2
// Name: $LN111_3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __usercall _LN111_3@<eax>(const char *psz@<eax>, unsigned int cchMax@<edx>, unsigned int *pcchLength@<edi>)
{
  HRESULT result; // eax
  unsigned int v5; // ecx

  result = 0;
  v5 = cchMax;
  if ( cchMax == 0 )
    goto LABEL_5;
  do
  {
    if ( *psz == 0 )
      break;
    ++psz;
    --cchMax;
  }
  while ( cchMax != 0 );
  if ( cchMax == 0 )
LABEL_5:
    result = -2147024809;
  if ( pcchLength != nullptr )
  {
    if ( result < 0 )
      *pcchLength = 0;
    else
      *pcchLength = v5 - cchMax;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103697F2
// Name: public: virtual int CFile::Open(char const __near *,unsigned int,class ATL::CAtlTransactionManager __near *,class CFileException __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFile::Open(
        CFile *this,
        const char *lpszFileName,
        unsigned int nOpenFlags,
        ATL::CAtlTransactionManager *pTM,
        CFileException *pException)
{
  this->m_pTM = pTM;
  return this->Open(this, a2: lpszFileName, a3: nOpenFlags, a4: pException);
}

//------------------------------------------------------------------------------
// Address: 0x1036980F
// Name: int AfxComparePath(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxComparePath(const char *lpszPath1, const char *lpszPath2)
{
  LCID ThreadLocale; // ebx
  const unsigned __int8 *v4; // eax
  int i; // esi
  int nLen; // [esp+Ch] [ebp-620h]
  unsigned __int16 aCharType11[260]; // [esp+10h] [ebp-61Ch] BYREF
  unsigned __int16 aCharType21[260]; // [esp+218h] [ebp-414h] BYREF
  unsigned __int16 aCharType13[260]; // [esp+420h] [ebp-20Ch] BYREF

  if ( lstrcmpiA(lpString1: lpszPath1, lpString2: lpszPath2) != 0 )
    return 0;
  if ( GetSystemMetrics(nIndex: 42) == 0 )
    return 1;
  nLen = lstrlenA(lpString: lpszPath1);
  if ( nLen != lstrlenA(lpString: lpszPath2) )
    return 0;
  ThreadLocale = GetThreadLocale();
  GetStringTypeExA(Locale: ThreadLocale, dwInfoType: 1u, lpSrcStr: lpszPath1, cchSrc: -1, lpCharType: aCharType11);
  GetStringTypeExA(Locale: ThreadLocale, dwInfoType: 4u, lpSrcStr: lpszPath1, cchSrc: -1, lpCharType: aCharType13);
  GetStringTypeExA(Locale: ThreadLocale, dwInfoType: 1u, lpSrcStr: lpszPath2, cchSrc: -1, lpCharType: aCharType21);
  v4 = (const unsigned __int8 *)lpszPath1;
  if ( *lpszPath1 != 0 )
  {
    for ( i = 0; SLOBYTE(aCharType13[i]) >= 0 || aCharType11[i] == aCharType21[i]; ++i )
    {
      v4 = _mbsinc(current: v4);
      if ( *v4 == 0 )
        return 1;
    }
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10369902
// Name: public: virtual struct CRuntimeClass __near * CFile::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CFile::GetRuntimeClass(CFile *this)
{
  return &CFile::classCFile;
}

//------------------------------------------------------------------------------
// Address: 0x10369908
// Name: public: void __near * ATL::CAtlTransactionManager::CreateFileA(char const __near *,unsigned long,unsigned long,struct _SECURITY_ATTRIBUTES __near *,unsigned long,unsigned long,void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall ATL::CAtlTransactionManager::CreateFileA(
        ATL::CAtlTransactionManager *this,
        const char *lpFileName,
        DWORD dwDesiredAccess,
        DWORD dwShareMode,
        _SECURITY_ATTRIBUTES *lpSecurityAttributes,
        DWORD dwCreationDisposition,
        DWORD dwFlagsAndAttributes,
        void *hTemplateFile)
{
  HMODULE ModuleHandleA; // eax
  HANDLE (__stdcall *CreateFileTransactedA)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE, HANDLE, PUSHORT, PVOID); // eax

  if ( this->m_hTransaction != nullptr )
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "kernel32.dll");
    if ( ModuleHandleA != nullptr )
    {
      CreateFileTransactedA = (HANDLE (__stdcall *)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE, HANDLE, PUSHORT, PVOID))GetProcAddress(hModule: ModuleHandleA, lpProcName: "CreateFileTransactedA");
      if ( CreateFileTransactedA != nullptr )
        return (int)CreateFileTransactedA(
                      lpFileName,
                      dwDesiredAccess,
                      dwShareMode,
                      lpSecurityAttributes,
                      dwCreationDisposition,
                      dwFlagsAndAttributes,
                      hTemplateFile,
                      hTransaction: this->m_hTransaction,
                      pusMiniVersion: nullptr,
                      lpExtendedParameter: nullptr);
    }
  }
  else if ( this->m_bFallback != 0 )
  {
    return (int)CreateFileA(
                  lpFileName,
                  dwDesiredAccess,
                  dwShareMode,
                  lpSecurityAttributes,
                  dwCreationDisposition,
                  dwFlagsAndAttributes,
                  hTemplateFile: nullptr);
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1036C010
// Name: public: class COleVariant const __near & COleVariant::operator=(long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const COleVariant *__thiscall COleVariant::operator=(COleVariant *this, unsigned int lSrc)
{
  int vt; // eax
  __int16 v4; // ax

  vt = this->vt;
  if ( vt == 3 || vt == 10 )
    goto LABEL_9;
  if ( vt != 11 )
  {
    VariantClear(pvarg: this);
    this->vt = 3;
LABEL_9:
    this->decVal.Lo32 = lSrc;
    return this;
  }
  if ( lSrc != 0 )
    v4 = -1;
  else
    v4 = 0;
  this->iVal = v4;
  return this;
}
