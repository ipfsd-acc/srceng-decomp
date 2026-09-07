// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tools/toolutils/basetoolsystem.cpp
// Functions: 63
// ============================================================

#include "tools\toolutils\basetoolsystem.h"

//------------------------------------------------------------------------------
// Address: 0x10049000
// Name: public: class vgui::Panel __near * CBaseToolSystem::GetActionTarget(void)
// Source: json
//------------------------------------------------------------------------------
CBaseToolSystem *__thiscall CBaseToolSystem::GetActionTarget(CBaseToolSystem *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10153CC0
// Name: public: virtual class vgui::Menu __near * CBaseToolSystem::CreateActionMenu(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CBaseToolSystem::CreateActionMenu(vgui::Panel *this, wchar_t key)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102BBDA0
// Name: public: vgui::DHANDLE<class vgui::Menu>::operator class vgui::Menu __near *(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
vgui::Menu *__thiscall vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(vgui::DHANDLE<vgui::Menu> *this)
{
  return (vgui::Menu *)vgui::PHandle::Get(this);
}

//------------------------------------------------------------------------------
// Address: 0x102BBDB0
// Name: public: class vgui::Menu __near * vgui::DHANDLE<class vgui::Menu>::operator=(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
CDragDropHelperPanel *__thiscall vgui::DHANDLE<vgui::Menu>::operator=(
        vgui::DHANDLE<vgui::Menu> *this,
        vgui::Menu *pPanel)
{
  return vgui::DHANDLE<CDragDropHelperPanel>::operator=(
           (vgui::DHANDLE<CDragDropHelperPanel> *)this,
           (CDragDropHelperPanel *)pPanel);
}

//------------------------------------------------------------------------------
// Address: 0x102BBDC0
// Name: public: static char const __near * CBaseToolSystem::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseToolSystem::GetPanelClassName()
{
  return "CBaseToolSystem";
}

//------------------------------------------------------------------------------
// Address: 0x102BBDD0
// Name: public: virtual void CBaseToolSystem::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::ApplySchemeSettings(CBaseToolSystem *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  this->SetKeyBoardInputEnabled(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x102BBE00
// Name: protected: virtual unsigned long CBaseToolSystem::GetToolScheme(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CBaseToolSystem::GetToolScheme(CBaseToolSystem *this)
{
  vgui::ISchemeManager *v1; // esi
  vgui::ISchemeManager_vtbl *v2; // edi
  int v3; // eax

  v1 = g_pVGuiSchemeManager;
  v2 = g_pVGuiSchemeManager->__vftable;
  v3 = this->GetToolName(this: &this->IToolSystem);
  return v2->LoadSchemeFromFile(this: v1, a2: "Resource/BoxRocket.res", a3: (const char *)v3);
}

//------------------------------------------------------------------------------
// Address: 0x102BBE40
// Name: public: virtual bool CBaseToolSystem::ServerInit(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseToolSystem::ServerInit(CBaseToolSystem *this, void *(__cdecl *serverFactory)(const char *, int *))
{
  servertools = (IServerTools *)serverFactory(a1: "VSERVERTOOLS001", a2: nullptr);
  if ( servertools == nullptr )
    _Error(this: (ISceneTokenProcessor *)&stru_10654E00, a2: "VSERVERTOOLS001");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102BBE80
// Name: public: virtual bool CBaseToolSystem::ClientInit(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseToolSystem::ClientInit(CBaseToolSystem *this, void *(__cdecl *clientFactory)(const char *, int *))
{
  clienttools = (IClientTools *)clientFactory(a1: "VCLIENTTOOLS001", a2: nullptr);
  if ( clienttools != nullptr )
    g_pGlobalFlexController = &g_GlobalFlexController;
  else
    _Error(this: (ISceneTokenProcessor *)&stru_10654E60, a2: "VCLIENTTOOLS001");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102BBED0
// Name: public: virtual void CBaseToolSystem::ServerShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::ServerShutdown(CBaseToolSystem *this)
{
  servertools = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102BBEE0
// Name: public: virtual void CBaseToolSystem::ClientShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::ClientShutdown(CBaseToolSystem *this)
{
  clienttools = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102BBEF0
// Name: public: virtual void CBaseToolSystem::Think(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::Think(CBaseToolSystem *this, bool finalTick)
{
  vgui::AnimationController *AnimationController; // eax
  float v3; // [esp-4h] [ebp-4h]

  v3 = enginetools->Time(this: enginetools);
  AnimationController = vgui::GetAnimationController();
  vgui::AnimationController::UpdateAnimations(this: AnimationController, currentTime: v3);
}

//------------------------------------------------------------------------------
// Address: 0x102BBF20
// Name: public: virtual char const __near * CBaseToolSystem::GetEntityData(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseToolSystem::GetEntityData(CBaseToolSystem *this, const char *pActualEntityData)
{
  return pActualEntityData;
}

//------------------------------------------------------------------------------
// Address: 0x102BBF60
// Name: private: bool CBaseToolSystem::ShowUI(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseToolSystem::ShowUI(CBaseToolSystem *this, BOOL bVisible)
{
  bool result; // al
  ConVar *v4; // eax
  bool bPrevVisible; // [esp+Bh] [ebp-1h]

  result = this->IsVisible(this);
  bPrevVisible = result;
  if ( result != bVisible )
  {
    this->SetMouseInputEnabled(this, a2: bVisible);
    this->SetVisible(this, a2: bVisible);
    if ( bVisible )
    {
      v4 = cvar->FindVar_2(this: cvar, a2: "cl_showpausedimage");
      if ( v4 != nullptr )
        v4->SetValue_2(this: &v4->IConVar, a2: 0);
    }
    return bPrevVisible;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BBFD0
// Name: public: virtual class vgui::MenuBar __near * CBaseToolSystem::CreateMenuBar(class CBaseToolSystem __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::MenuBar *__thiscall CBaseToolSystem::CreateMenuBar(CBaseToolSystem *this, CBaseToolSystem *pParent)
{
  vgui::MenuBar *v2; // eax

  v2 = (vgui::MenuBar *)operator new(nSize: 0x16Cu);
  if ( v2 != nullptr )
    return vgui::MenuBar::MenuBar(this: v2, parent: pParent, panelName: "ToolMenuBar");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102BC000
// Name: public: virtual class vgui::Panel __near * CBaseToolSystem::CreateStatusBar(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseStatusBar *__thiscall CBaseToolSystem::CreateStatusBar(CBaseToolSystem *this, vgui::Panel *pParent)
{
  CBaseStatusBar *v3; // eax

  v3 = (CBaseStatusBar *)operator new(nSize: 0x198u);
  if ( v3 != nullptr )
    return CBaseStatusBar::CBaseStatusBar(this: v3, parent: this, panelName: "Status Bar");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102BC030
// Name: public: class vgui::Panel __near * CBaseToolSystem::GetClientArea(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CBaseToolSystem::GetClientArea(CBaseToolSystem *this)
{
  return (vgui::Panel *)CToolUI::GetClientArea(this: (vgui::TreeView *)this->m_pToolUI);
}

//------------------------------------------------------------------------------
// Address: 0x102BC040
// Name: private: virtual void CBaseToolSystem::OnClearRecent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::OnClearRecent(CBaseToolSystem *this)
{
  const char *v2; // eax

  CToolsRecentFileList::Clear(this: &this->m_RecentFiles);
  v2 = this->GetRegistryName(this);
  CToolsRecentFileList::SaveToRegistry(this: &this->m_RecentFiles, pToolKeyName: v2);
}

//------------------------------------------------------------------------------
// Address: 0x102BC070
// Name: private: virtual void CBaseToolSystem::OnFileStateMachineFinished(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::OnFileStateMachineFinished(CBaseToolSystem *this, KeyValues *pKeyValues)
{
  KeyValues *FirstTrueSubKey; // ebx
  const char *String; // eax
  bool bWroteFile; // [esp+Ch] [ebp-4h]
  vgui::FileOpenStateMachine::CompletionState_t state; // [esp+18h] [ebp+8h]

  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKeyValues);
  bWroteFile = KeyValues::GetInt(this: pKeyValues, keyName: "wroteFile", defaultValue: 0) != 0;
  state = KeyValues::GetInt(this: pKeyValues, keyName: "completionState", defaultValue: 0);
  String = KeyValues::GetString(this: pKeyValues, keyName: "fileType", defaultValue: &var);
  this->OnFileOperationCompleted(this, a2: String, a3: bWroteFile, a4: state, a5: FirstTrueSubKey);
}

//------------------------------------------------------------------------------
// Address: 0x102BC0E0
// Name: protected: void CBaseToolSystem::OpenFile(char const __near *,char const __near *,char const __near *,int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::OpenFile(
        CBaseToolSystem *this,
        const char *pOpenFileType,
        const char *pSaveFileName,
        const char *pSaveFileType,
        int nFlags,
        KeyValues *pContextKeyValues)
{
  vgui::FileOpenStateMachine::OpenFile(
    this: this->m_pFileOpenStateMachine,
    pOpenFileType,
    pContextKeyValues,
    pSaveFileName,
    pSaveFileType,
    nFlags);
}

//------------------------------------------------------------------------------
// Address: 0x102BC110
// Name: protected: void CBaseToolSystem::OpenFile(char const __near *,char const __near *,char const __near *,char const __near *,int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::OpenFile(
        CBaseToolSystem *this,
        const char *pOpenFileName,
        const char *pOpenFileType,
        const char *pSaveFileName,
        const char *pSaveFileType,
        int nFlags,
        KeyValues *pContextKeyValues)
{
  vgui::FileOpenStateMachine::OpenFile(
    this: this->m_pFileOpenStateMachine,
    pOpenFileName,
    pOpenFileType,
    pContextKeyValues,
    pSaveFileName,
    pSaveFileType,
    nFlags);
}

//------------------------------------------------------------------------------
// Address: 0x102BC140
// Name: protected: void CBaseToolSystem::SaveFile(char const __near *,char const __near *,int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::SaveFile(
        CBaseToolSystem *this,
        const char *pFileName,
        const char *pFileType,
        int nFlags,
        KeyValues *pContextKeyValues)
{
  vgui::FileOpenStateMachine::SaveFile(
    this: this->m_pFileOpenStateMachine,
    pContextKeyValues,
    pFileName,
    pFileType,
    nFlags);
}

//------------------------------------------------------------------------------
// Address: 0x102BC170
// Name: protected: virtual char const __near * CBaseToolSystem::GetBackgroundTextureName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseToolSystem::GetBackgroundTextureName(CBaseToolSystem *this)
{
  return "vgui/tools/ifm/ifm_background";
}

//------------------------------------------------------------------------------
// Address: 0x102BC180
// Name: public: virtual class CMiniViewport __near * CBaseToolSystem::CreateMiniViewport(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CMiniViewport *__thiscall CBaseToolSystem::CreateMiniViewport(CBaseToolSystem *this, vgui::Panel *parent)
{
  CMiniViewport *v2; // eax
  CMiniViewport *v3; // esi
  int w; // [esp+4h] [ebp-8h] BYREF
  int h; // [esp+8h] [ebp-4h] BYREF

  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &w, a3: &h);
  v2 = (CMiniViewport *)operator new(nSize: 0x228u);
  if ( v2 != nullptr )
    v3 = CMiniViewport::CMiniViewport(
           this: v2,
           parent,
           contextLabel: true,
           factory: nullptr,
           page: nullptr,
           title: nullptr,
           contextMenu: false);
  else
    v3 = nullptr;
  v3->SetVisible(this: v3, a2: true);
  vgui::Panel::SetBounds(this: v3, x: 2 * w / 3 - 4, y: 32, wide: w / 3, tall: h / 3 + 22);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102BC230
// Name: public: virtual void CBaseToolSystem::ComputeMenuBarTitle(char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::ComputeMenuBarTitle(CBaseToolSystem *this, char *buf, unsigned int buflen)
{
  const char *v3; // eax

  if ( !this->m_bGameInputEnabled && this->m_bIsActive )
    v3 = "Tool Mode";
  else
    v3 = "Game Mode";
  V_snprintf(pDest: buf, maxLen: buflen, pFormat: ": %s [ %s - Switch Mode ] [ %s - Full Screen ]", v3, "F10", "F11");
}

//------------------------------------------------------------------------------
// Address: 0x102BC290
// Name: public: virtual int CGlobalFlexController::FindGlobalFlexController(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGlobalFlexController::FindGlobalFlexController(CGlobalFlexController *this, const char *name)
{
  return clienttools->FindGlobalFlexcontroller(this: clienttools, a2: name);
}

//------------------------------------------------------------------------------
// Address: 0x102BC2B0
// Name: public: virtual char const __near * CGlobalFlexController::GetGlobalFlexControllerName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CGlobalFlexController::GetGlobalFlexControllerName(CGlobalFlexController *this, int idx)
{
  return clienttools->GetGlobalFlexControllerName(this: clienttools, a2: idx);
}

//------------------------------------------------------------------------------
// Address: 0x102BC2D0
// Name: public: virtual bool CBaseToolSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseToolSystem::Init(CBaseToolSystem *this)
{
  int v2; // ebx
  char *v3; // esi
  unsigned int ToolRootPanel; // eax
  int v5; // eax
  const char *v6; // eax
  vgui::KeyBindingContextHandle_t KeyBindingsContext; // eax
  int v8; // edx
  IMaterialSystem_vtbl *v9; // ebx
  int v10; // eax
  int v11; // eax
  IMaterialSystem_vtbl *v12; // ebx
  int v13; // eax
  unsigned int v14; // eax
  CToolUI *v15; // eax
  vgui::DragDrop_t *v16; // eax
  int ClientArea; // eax
  CDragDropHelperPanel *v18; // eax
  int w; // [esp+Ch] [ebp-8h] BYREF
  int h; // [esp+10h] [ebp-4h] BYREF

  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "resource/dmecontrols_%language%.txt", a3: nullptr, a4: false);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "resource/toolshared_%language%.txt", a3: nullptr, a4: false);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Resource/vgui_%language%.txt", a3: nullptr, a4: false);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "Resource/platform_%language%.txt", a3: nullptr, a4: false);
  g_pVGuiLocalize->AddFile(this: g_pVGuiLocalize, a2: "resource/boxrocket_%language%.txt", a3: nullptr, a4: false);
  v2 = *((_DWORD *)this - 95);
  v3 = (char *)this - 380;
  ToolRootPanel = VGui_GetToolRootPanel();
  (*(void (__thiscall **)(char *, unsigned int))(v2 + 164))(a1: (char *)this - 380, a2: ToolRootPanel);
  v5 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 95) + 988))(a1: (char *)this - 380);
  if ( v5 != 0 )
    (*(void (__thiscall **)(char *, int))(*(_DWORD *)v3 + 336))(a1: (char *)this - 380, a2: v5);
  v6 = (const char *)(*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 980))(a1: (char *)this - 380);
  KeyBindingsContext = vgui::Panel::CreateKeyBindingsContext(filename: v6, pathID: "GAME");
  v8 = *(_DWORD *)v3;
  this->m_hKeyBindingsContext = KeyBindingsContext;
  (*(void (__thiscall **)(char *, vgui::KeyBindingContextHandle_t))(v8 + 448))(
    a1: (char *)this - 380,
    a2: KeyBindingsContext);
  vgui::Panel::ReloadKeyBindings(handle: this->m_hKeyBindingsContext);
  if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 1000))(a1: (char *)this - 380) != 0 )
  {
    v9 = materials->__vftable;
    v10 = (*(int (__thiscall **)(char *, const char *, int, _DWORD))(*(_DWORD *)v3 + 1000))(
            a1: (char *)this - 380,
            a2: "VGUI textures",
            a3: 1,
            a4: 0);
    v11 = ((int (__thiscall *)(IMaterialSystem *, int))v9->FindMaterial)(a1: materials, a2: v10);
    this->m_lLastDoublePressTime = v11;
    (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 48))(a1: v11);
  }
  if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 1004))(a1: (char *)this - 380) != 0 )
  {
    v12 = materials->__vftable;
    v13 = (*(int (__thiscall **)(char *, const char *, int, _DWORD))(*(_DWORD *)v3 + 1004))(
            a1: (char *)this - 380,
            a2: "VGUI textures",
            a3: 1,
            a4: 0);
    v14 = ((int (__thiscall *)(IMaterialSystem *, int))v12->FindMaterial)(a1: materials, a2: v13);
    this->m_infoFont = v14;
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)v14 + 48))(a1: v14);
  }
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &w, a3: &h);
  vgui::Panel::SetBounds(this: (CBaseToolSystem *)((char *)this - 380), x: 0, y: 0, wide: w, tall: h);
  (*(void (__thiscall **)(char *, int))(*(_DWORD *)v3 + 284))(a1: (char *)this - 380, a2: 1);
  (*(void (__thiscall **)(char *, _DWORD))(*(_DWORD *)v3 + 280))(a1: (char *)this - 380, a2: 0);
  (*(void (__thiscall **)(char *, _DWORD))(*(_DWORD *)v3 + 288))(a1: (char *)this - 380, a2: 0);
  (*(void (__thiscall **)(char *, int))(*(_DWORD *)v3 + 252))(a1: (char *)this - 380, a2: 1);
  (*(void (__thiscall **)(char *, _DWORD))(*(_DWORD *)v3 + 132))(a1: (char *)this - 380, a2: 0);
  v15 = (CToolUI *)operator new(nSize: 0x160u);
  if ( v15 != nullptr )
    v16 = (vgui::DragDrop_t *)CToolUI::CToolUI(
                                this: v15,
                                pParent: (CBaseToolSystem *)((char *)this - 380),
                                panelName: "ToolUI",
                                pBaseToolSystem: (CBaseToolSystem *)((char *)this - 380));
  else
    v16 = nullptr;
  this->m_pDragDrop = v16;
  ClientArea = CToolUI::GetClientArea(this: (vgui::TreeView *)v16);
  v18 = (CDragDropHelperPanel *)(*(int (__thiscall **)(char *, int))(*(_DWORD *)v3 + 960))(
                                  a1: (char *)this - 380,
                                  a2: ClientArea);
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_pTooltips,
    pPanel: v18);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102BC510
// Name: public: virtual void CBaseToolSystem::ShowMiniViewport(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::ShowMiniViewport(CBaseToolSystem *this, BOOL state)
{
  vgui::DHANDLE<CMiniViewport> *p_m_hMiniViewport; // esi
  vgui::Panel *v3; // eax

  p_m_hMiniViewport = &this->m_hMiniViewport;
  if ( vgui::PHandle::Get(this: &this->m_hMiniViewport) != nullptr )
  {
    v3 = vgui::PHandle::Get(this: p_m_hMiniViewport);
    v3->SetVisible(this: v3, a2: state);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BC540
// Name: public: virtual void CBaseToolSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::Shutdown(CBaseToolSystem *this)
{
  vgui::Panel *v2; // eax

  if ( this->m_lLastDoublePressTime != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)this->m_lLastDoublePressTime + 52))(a1: this->m_lLastDoublePressTime);
  if ( this->m_infoFont != 0 )
    (*(void (__thiscall **)(unsigned int))(*(_DWORD *)this->m_infoFont + 52))(a1: this->m_infoFont);
  if ( vgui::PHandle::Get(this: (vgui::PHandle *)&this->m_pTooltips) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: (vgui::PHandle *)&this->m_pTooltips);
    if ( v2 != nullptr )
      ((void (__thiscall *)(vgui::Panel *, int))v2->dtr_Panel)(a1: v2, a2: 1);
  }
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 95) + 320))(a1: (char *)this - 380);
  g_pVGui->RunFrame(this: g_pVGui);
}

//------------------------------------------------------------------------------
// Address: 0x102BC5B0
// Name: public: void CBaseToolSystem::SetMode(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::SetMode(CBaseToolSystem *this, bool bGameInputEnabled, BOOL bFullscreen)
{
  bool v4; // al
  bool v5; // zf
  char m_bGameInputEnabled; // al
  const char *v7; // eax
  CToolUI *m_pToolUI; // ecx
  char bOldGameInputEnabled; // [esp+13h] [ebp+Bh]

  v4 = (this->m_bFullscreenToolModeEnabled || bGameInputEnabled) && bFullscreen;
  if ( this->m_bFullscreenMode != v4 || this->m_bGameInputEnabled != bGameInputEnabled )
  {
    v5 = !this->m_bIsActive;
    bOldGameInputEnabled = this->m_bGameInputEnabled;
    this->m_bFullscreenMode = v4;
    this->m_bGameInputEnabled = bGameInputEnabled;
    LOBYTE(bFullscreen) = !v5 && (!bGameInputEnabled || !v4);
    CBaseToolSystem::ShowUI(this, bVisible: bFullscreen);
    m_bGameInputEnabled = this->m_bGameInputEnabled;
    if ( bOldGameInputEnabled != m_bGameInputEnabled )
    {
      v5 = m_bGameInputEnabled == 0;
      v7 = "Game";
      if ( v5 )
        v7 = "Tools";
      _Warning(a1: "Input is now being sent to the %s\n", v7);
      if ( bGameInputEnabled )
        g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
      if ( g_pVGuiInput->GetModalSubTree(this: g_pVGuiInput) != 0 )
        ((void (__stdcall *)(bool))g_pVGuiInput->SetModalSubTreeReceiveMessages)(a1: !this->m_bGameInputEnabled);
      ((void (__stdcall *)(bool))enginetools->OnModeChanged)(a1: this->m_bGameInputEnabled);
    }
    m_pToolUI = this->m_pToolUI;
    if ( m_pToolUI != nullptr )
      m_pToolUI->UpdateMenuBarTitle(this: m_pToolUI);
    this->OnModeChanged(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BC6D0
// Name: protected: void CBaseToolSystem::ShowKeyBindingsEditor(class vgui::Panel __near *,enum vgui::KeyBindingContextHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::ShowKeyBindingsEditor(
        CBaseToolSystem *this,
        vgui::Panel *panel,
        vgui::KeyBindingContextHandle_t handle)
{
  vgui::CKeyBoardEditorDialog *v4; // esi
  vgui::Panel *ClientArea; // eax
  CDragDropHelperPanel *v6; // eax
  vgui::Panel *v7; // eax

  if ( vgui::PHandle::Get(this: &this->m_hKeyBindingsEditor) == nullptr )
  {
    v4 = (vgui::CKeyBoardEditorDialog *)operator new(nSize: 0x228u);
    if ( v4 != nullptr )
    {
      ClientArea = (vgui::Panel *)CToolUI::GetClientArea(this: (vgui::TreeView *)this->m_pToolUI);
      v6 = (CDragDropHelperPanel *)vgui::CKeyBoardEditorDialog::CKeyBoardEditorDialog(
                                     this: v4,
                                     parent: ClientArea,
                                     panelToEdit: panel,
                                     handle);
    }
    else
    {
      v6 = nullptr;
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hKeyBindingsEditor,
      pPanel: v6);
    v7 = vgui::PHandle::Get(this: &this->m_hKeyBindingsEditor);
    v7->__vftable[1].IsEnabled(this: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BC750
// Name: protected: void CBaseToolSystem::ShowKeyBindingsHelp(class vgui::Panel __near *,enum vgui::KeyBindingContextHandle_t,enum ButtonCode_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::ShowKeyBindingsHelp(
        CBaseToolSystem *this,
        vgui::Panel *panel,
        vgui::KeyBindingContextHandle_t handle,
        ButtonCode_t boundKey,
        int modifiers)
{
  vgui::CKeyBindingHelpDialog *v6; // eax
  vgui::CKeyBindingHelpDialog *v7; // esi
  vgui::Panel *ClientArea; // eax
  CDragDropHelperPanel *v9; // eax

  if ( vgui::PHandle::Get(this: &this->m_hKeyBindingsHelp) != nullptr )
  {
    v6 = (vgui::CKeyBindingHelpDialog *)vgui::PHandle::Get(this: &this->m_hKeyBindingsHelp);
    vgui::CKeyBindingHelpDialog::HelpKeyPressed(this: v6);
  }
  else
  {
    v7 = (vgui::CKeyBindingHelpDialog *)operator new(nSize: 0x238u);
    if ( v7 != nullptr )
    {
      ClientArea = (vgui::Panel *)CToolUI::GetClientArea(this: (vgui::TreeView *)this->m_pToolUI);
      v9 = (CDragDropHelperPanel *)vgui::CKeyBindingHelpDialog::CKeyBindingHelpDialog(
                                     this: v7,
                                     parent: ClientArea,
                                     panelToView: panel,
                                     handle,
                                     code: boundKey,
                                     modifiers);
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hKeyBindingsHelp,
        pPanel: v9);
    }
    else
    {
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hKeyBindingsHelp,
        pPanel: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BC7E0
// Name: public: virtual void CBaseToolSystem::AdjustEngineViewport(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::AdjustEngineViewport(CBaseToolSystem *this, int *x, int *y, int *width, int *height)
{
  vgui::Tooltip **p_m_pTooltips; // esi
  CMiniViewport *v6; // eax
  int vph; // [esp+4h] [ebp-14h] BYREF
  int vpw; // [esp+8h] [ebp-10h] BYREF
  int vpy; // [esp+Ch] [ebp-Ch] BYREF
  int vpx; // [esp+10h] [ebp-8h] BYREF
  bool enabled; // [esp+17h] [ebp-1h] BYREF

  p_m_pTooltips = &this->m_pTooltips;
  if ( vgui::PHandle::Get(this: (vgui::PHandle *)&this->m_pTooltips) != nullptr )
  {
    v6 = (CMiniViewport *)vgui::PHandle::Get(this: (vgui::PHandle *)p_m_pTooltips);
    CMiniViewport::GetViewport(this: v6, &enabled, x: &vpx, y: &vpy, w: &vpw, h: &vph);
    if ( enabled )
    {
      *x = vpx;
      *y = vpy;
      *width = vpw;
      *height = vph;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BC850
// Name: public: virtual bool CBaseToolSystem::ShouldGameRenderView(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseToolSystem::ShouldGameRenderView(CBaseToolSystem *this)
{
  vgui::Panel *v3; // eax

  if ( (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 95) + 136))(a1: (char *)this - 380) == 0
    || vgui::PHandle::Get(this: (vgui::PHandle *)&this->m_pTooltips) == nullptr )
  {
    return true;
  }
  v3 = vgui::PHandle::Get(this: (vgui::PHandle *)&this->m_pTooltips);
  return !v3->IsVisible(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x102BC8A0
// Name: public: virtual void CBaseToolSystem::RenderFrameBegin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::RenderFrameBegin(CBaseToolSystem *this)
{
  vgui::Tooltip **p_m_pTooltips; // esi
  vgui::Panel *v3; // eax
  CMiniViewport *v4; // eax

  if ( (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 95) + 136))(a1: (char *)this - 380) != 0
    && this->m_clrDropFrame._color[2] != 0 )
  {
    p_m_pTooltips = &this->m_pTooltips;
    if ( vgui::PHandle::Get(this: (vgui::PHandle *)p_m_pTooltips) != nullptr )
    {
      v3 = vgui::PHandle::Get(this: (vgui::PHandle *)p_m_pTooltips);
      if ( v3->IsVisible(this: v3) )
      {
        v4 = (CMiniViewport *)vgui::PHandle::Get(this: (vgui::PHandle *)p_m_pTooltips);
        CMiniViewport::RenderFrameBegin(this: v4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BC900
// Name: public: virtual void CBaseToolSystem::VGui_PreSimulate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::VGui_PreSimulate(CBaseToolSystem *this)
{
  unsigned int v2; // esi
  bool wantsToBeSeen; // [esp+4h] [ebp-4h]

  if ( this->m_clrDropFrame._color[2] != 0 )
  {
    v2 = enginevgui->GetPanel(this: enginevgui, a2: PANEL_GAMEUIDLL);
    if ( v2 != 0 )
    {
      wantsToBeSeen = (this->m_clrDropFrame._color[0] != 0 || this->m_clrDropFrame._color[2] == 0)
                   && (enginetools->IsGamePaused(this: enginetools)
                    || !enginetools->IsInGame(this: enginetools)
                    || enginetools->IsConsoleVisible(this: enginetools));
      g_pVGuiPanel->SetVisible(this: g_pVGuiPanel, a2: v2, a3: wantsToBeSeen);
    }
    if ( this->m_clrDropFrame._color[0] == 0
      && this->m_clrDropFrame._color[2] != 0
      && (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 95) + 136))(a1: (char *)this - 380) == 0
      && !enginetools->IsInGame(this: enginetools) )
    {
      CBaseToolSystem::SetMode(
        this: (CBaseToolSystem *)((char *)this - 380),
        bGameInputEnabled: true,
        bFullscreen: this->m_clrDropFrame._color[1]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BC9E0
// Name: public: class vgui::Menu __near * CBaseToolSystem::GetActionMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall CBaseToolSystem::GetActionMenu(CBaseToolSystem *this)
{
  return (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hActionMenu);
}

//------------------------------------------------------------------------------
// Address: 0x102BC9F0
// Name: private: void CBaseToolSystem::PositionActionMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::PositionActionMenu(CBaseToolSystem *this)
{
  vgui::Panel *v2; // eax
  vgui::Panel *v3; // eax
  int v4; // eax
  vgui::DHANDLE<vgui::Menu> *p_m_hActionMenu; // ecx
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  int v9; // ecx
  int wide; // [esp+8h] [ebp-18h] BYREF
  int tall; // [esp+Ch] [ebp-14h] BYREF
  int menuWide; // [esp+10h] [ebp-10h] BYREF
  int menuTall; // [esp+14h] [ebp-Ch] BYREF
  int cursorX; // [esp+18h] [ebp-8h] BYREF
  int cursorY; // [esp+1Ch] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cursorX, a3: &cursorY);
  v2 = vgui::PHandle::Get(this: &this->m_hActionMenu);
  v2->InvalidateLayout(this: v2, a2: true, a3: false);
  v3 = vgui::PHandle::Get(this: &this->m_hActionMenu);
  vgui::Panel::GetSize(this: v3, wide: &menuWide, tall: &menuTall);
  vgui::Panel::GetSize(this, &wide, &tall);
  v4 = tall - menuTall;
  p_m_hActionMenu = &this->m_hActionMenu;
  if ( wide - menuWide <= cursorX )
  {
    if ( v4 <= cursorY )
    {
      v8 = vgui::PHandle::Get(this: p_m_hActionMenu);
      v9 = cursorY - menuTall;
    }
    else
    {
      v8 = vgui::PHandle::Get(this: p_m_hActionMenu);
      v9 = cursorY;
    }
    vgui::Panel::SetPos(this: v8, x: cursorX - menuWide, y: v9);
  }
  else if ( v4 <= cursorY )
  {
    v7 = vgui::PHandle::Get(this: p_m_hActionMenu);
    vgui::Panel::SetPos(this: v7, x: cursorX, y: cursorY - menuTall);
  }
  else
  {
    v6 = vgui::PHandle::Get(this: p_m_hActionMenu);
    vgui::Panel::SetPos(this: v6, x: cursorX, y: cursorY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BCAE0
// Name: public: virtual void CBaseToolSystem::OnUnhandledMouseClick(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::OnUnhandledMouseClick(CBaseToolSystem *this, int code)
{
  if ( code == 107 && !this->m_bFullscreenMode && (this->m_bGameInputEnabled || !this->m_bIsActive) )
    CBaseToolSystem::SetMode(this, bGameInputEnabled: false, bFullscreen: false);
}

//------------------------------------------------------------------------------
// Address: 0x102BCB20
// Name: public: virtual void CBaseToolSystem::OnToolActivate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseToolSystem::OnToolActivate(CBaseToolSystem *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  char *v3; // esi
  vgui::IInput *v4; // ebx
  BOOL v5; // eax
  vgui::IInput_vtbl *v6; // edi
  unsigned int ToolRootPanel; // eax
  bool v8; // al
  bool bVisible[4]; // [esp+8h] [ebp-4h]

  v3 = (char *)this - 380;
  this->m_clrDropFrame._color[2] = 1;
  bVisible[0] = this->m_clrDropFrame._color[2] != 0 && (v3[428] == 0 || v3[429] == 0);
  CBaseToolSystem::ShowUI(this: (CBaseToolSystem *)((char *)this - 380), bVisible: *(BOOL *)bVisible);
  (*(void (__thiscall **)(char *, int, int))(*(_DWORD *)v3 + 984))(a1: v3, a2: a3, a3: a2);
  v4 = g_pVGuiInput;
  v5 = v3[428] != 0 || v3[430] == 0;
  v6 = g_pVGuiInput->__vftable;
  (**(void (__thiscall ***)(char *, BOOL))v3)(a1: v3, a2: v5);
  ToolRootPanel = VGui_GetToolRootPanel();
  ((void (__thiscall *)(vgui::IInput *, unsigned int))v6->SetModalSubTree)(a1: v4, a2: ToolRootPanel);
  v8 = v3[428] != 0 || v3[430] == 0;
  g_pVGuiInput->SetModalSubTreeReceiveMessages(this: g_pVGuiInput, a2: !v8);
  (*(void (__thiscall **)(vgui::DragDrop_t *))(*(_DWORD *)this->m_pDragDrop + 844))(a1: this->m_pDragDrop);
}

//------------------------------------------------------------------------------
// Address: 0x102BCC00
// Name: public: virtual void CBaseToolSystem::OnToolDeactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::OnToolDeactivate(CBaseToolSystem *this)
{
  char *v1; // esi
  bool bVisible[4]; // [esp+4h] [ebp-4h]

  v1 = (char *)this - 380;
  this->m_clrDropFrame._color[2] = 0;
  bVisible[0] = this->m_clrDropFrame._color[2] != 0 && (v1[428] == 0 || v1[429] == 0);
  CBaseToolSystem::ShowUI(this: (CBaseToolSystem *)((char *)this - 380), bVisible: *(BOOL *)bVisible);
  (*(void (__thiscall **)(char *))(*(_DWORD *)v1 + 984))(a1: v1);
  g_pVGuiInput->ReleaseModalSubTree(this: g_pVGuiInput);
}

//------------------------------------------------------------------------------
// Address: 0x102BCC60
// Name: public: virtual bool CBaseToolSystem::TrapKey(enum ButtonCode_t,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseToolSystem::TrapKey(CBaseToolSystem *this, ButtonCode_t key, bool down)
{
  unsigned __int8 v5; // al

  if ( this->m_clrDropFrame._color[2] == 0 )
    return 0;
  if ( this->m_clrDropFrame._color[0] == 0 && this->m_clrDropFrame._color[2] != 0 && key == KEY_ESCAPE )
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
  v5 = this->m_clrDropFrame._color[0];
  if ( v5 == 0 && this->m_clrDropFrame._color[1] != 0 && key == KEY_ESCAPE )
    return 1;
  if ( down )
  {
    if ( key == KEY_F11 )
    {
      CBaseToolSystem::SetMode(
        this: (CBaseToolSystem *)((char *)this - 380),
        bGameInputEnabled: v5,
        bFullscreen: this->m_clrDropFrame._color[1] == 0);
      return 1;
    }
    if ( key == KEY_F10 )
    {
      if ( !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
        && !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL) )
      {
        CBaseToolSystem::SetMode(
          this: (CBaseToolSystem *)((char *)this - 380),
          bGameInputEnabled: this->m_clrDropFrame._color[0] == 0,
          bFullscreen: this->m_clrDropFrame._color[1]);
        return 1;
      }
      (*(void (__thiscall **)(char *))(*((_DWORD *)this - 95) + 1012))(a1: (char *)this - 380);
      return 1;
    }
    if ( this->m_clrDropFrame._color[0] == 0
      && this->m_clrDropFrame._color[2] != 0
      && (key == (KEY_XBUTTON_INACTIVE_START|KEY_1) || key == KEY_F5) )
    {
      CBaseToolSystem::SetMode(
        this: (CBaseToolSystem *)((char *)this - 380),
        bGameInputEnabled: true,
        bFullscreen: this->m_clrDropFrame._color[1]);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102BCD80
// Name: public: class vgui::Panel __near * CBaseToolSystem::GetMostRecentlyFocusedTool(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CBaseToolSystem::GetMostRecentlyFocusedTool(CBaseToolSystem *this)
{
  CBaseToolSystem *v1; // ebx
  int v2; // edi
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // esi
  vgui::IPanel *v5; // ebx
  vgui::IPanel_vtbl *v6; // edi
  int v7; // eax
  bool v8; // al
  int c; // [esp+Ch] [ebp-14h]
  int i; // [esp+14h] [ebp-Ch]
  unsigned int focus; // [esp+18h] [ebp-8h]
  bool hasFocus; // [esp+1Fh] [ebp-1h]

  v1 = this;
  focus = g_pVGuiInput->GetFocus(this: g_pVGuiInput);
  v2 = 0;
  c = v1->m_Tools.m_Size;
  i = 0;
  if ( c <= 0 )
    return vgui::PHandle::Get(this: &v1->m_MostRecentlyFocused);
  while ( 1 )
  {
    v3 = vgui::PHandle::Get(this: &v1->m_Tools.m_Memory.m_pMemory[v2]);
    v4 = v3;
    if ( v3 != nullptr && v3->GetParent(this: v3) != nullptr )
    {
      hasFocus = v4->HasFocus(this: v4);
      v8 = false;
      if ( focus != 0 )
      {
        v5 = g_pVGuiPanel;
        v6 = g_pVGuiPanel->__vftable;
        v7 = v4->GetVPanel(this: v4);
        if ( v6->HasParent(this: v5, a2: focus, a3: v7) )
          v8 = true;
      }
      if ( hasFocus || v8 )
        break;
      v2 = i;
      v1 = this;
    }
    i = ++v2;
    if ( v2 >= c )
      return vgui::PHandle::Get(this: &v1->m_MostRecentlyFocused);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x102BCE50
// Name: public: virtual void CBaseToolSystem::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::OnThink(CBaseToolSystem *this)
{
  CBaseToolSystem *v1; // ebx
  int v2; // eax
  vgui::Panel *v3; // eax
  CDragDropHelperPanel *v4; // esi
  vgui::Panel *v5; // edi
  void *v6; // eax
  int (__thiscall ***v7)(_DWORD); // eax
  int (__thiscall ***v8)(_DWORD); // ebx
  vgui::IPanel_vtbl *v9; // edi
  int v10; // eax
  vgui::IPanel *v11; // ebx
  vgui::IPanel_vtbl *v12; // edi
  int v13; // eax
  int c; // [esp+4h] [ebp-18h]
  vgui::IPanel *v15; // [esp+8h] [ebp-14h]
  int i; // [esp+10h] [ebp-Ch]
  unsigned int focus; // [esp+14h] [ebp-8h]
  bool bFocusOnTab; // [esp+1Bh] [ebp-1h]

  v1 = this;
  vgui::Panel::OnThink(this);
  focus = g_pVGuiInput->GetFocus(this: g_pVGuiInput);
  v2 = 0;
  c = v1->m_Tools.m_Size;
  i = 0;
  if ( c > 0 )
  {
    do
    {
      v3 = vgui::PHandle::Get(this: &v1->m_Tools.m_Memory.m_pMemory[v2]);
      v4 = (CDragDropHelperPanel *)v3;
      if ( v3 != nullptr )
      {
        v5 = v3->GetParent(this: v3);
        if ( v5 != nullptr )
        {
          bFocusOnTab = false;
          if ( v4->HasFocus(this: v4) )
            goto LABEL_16;
          v6 = __RTDynamicCast(
                 inptr: v5,
                 VfDelta: 0,
                 SrcType: &vgui::Panel `RTTI Type Descriptor',
                 TargetType: &vgui::PropertySheet `RTTI Type Descriptor',
                 isReference: 0);
          if ( v6 != nullptr )
          {
            v7 = (int (__thiscall ***)(_DWORD))(*(int (__thiscall **)(void *))(*(_DWORD *)v6 + 992))(a1: v6);
            v8 = v7;
            if ( v7 != nullptr )
            {
              if ( focus == (**v7)(a1: v7)
                || (v9 = g_pVGuiPanel->__vftable,
                    v15 = g_pVGuiPanel,
                    v10 = (**v8)(a1: v8),
                    bFocusOnTab = false,
                    v9->HasParent(this: v15, a2: focus, a3: v10)) )
              {
                bFocusOnTab = true;
              }
            }
          }
          if ( focus != 0
            && (v11 = g_pVGuiPanel,
                v12 = g_pVGuiPanel->__vftable,
                v13 = v4->GetVPanel(this: v4),
                v12->HasParent(this: v11, a2: focus, a3: v13))
            || bFocusOnTab )
          {
LABEL_16:
            if ( vgui::PHandle::Get(this: &this->m_MostRecentlyFocused) != v4 )
              vgui::DHANDLE<CDragDropHelperPanel>::operator=(
                this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_MostRecentlyFocused,
                pPanel: v4);
            return;
          }
          v1 = this;
        }
      }
      v2 = i + 1;
      i = v2;
    }
    while ( v2 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BCFB0
// Name: private: void CBaseToolSystem::InitActionMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::InitActionMenu(CBaseToolSystem *this)
{
  vgui::Panel *v2; // eax
  CDragDropHelperPanel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax

  if ( vgui::PHandle::Get(this: &this->m_hActionMenu) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hActionMenu);
    v2->MarkForDeletion(this: v2);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hActionMenu,
      pPanel: nullptr);
  }
  v3 = (CDragDropHelperPanel *)this->CreateActionMenu(this, a2: this);
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hActionMenu,
    pPanel: v3);
  if ( vgui::PHandle::Get(this: &this->m_hActionMenu) != nullptr )
  {
    v4 = vgui::PHandle::Get(this: &this->m_hActionMenu);
    v4->SetVisible(this: v4, a2: true);
    CBaseToolSystem::PositionActionMenu(this);
    v5 = vgui::PHandle::Get(this: &this->m_hActionMenu);
    v5->RequestFocus(this: v5, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BD050
// Name: protected: virtual void CBaseToolSystem::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::PaintBackground(CBaseToolSystem *this)
{
  IMatRenderContext *v2; // edi
  int v3; // edi
  float v4; // xmm2_4
  bool v5; // al
  bool v6; // zf
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  float v10; // [esp-18h] [ebp-40h]
  float v11; // [esp-18h] [ebp-40h]
  float v12; // [esp-Ch] [ebp-34h]
  float v13; // [esp-8h] [ebp-30h]
  IMatRenderContext *v14; // [esp+Ch] [ebp-1Ch]
  int z; // [esp+10h] [ebp-18h] BYREF
  int s0; // [esp+14h] [ebp-14h] BYREF
  int t0; // [esp+18h] [ebp-10h] BYREF
  int s1; // [esp+1Ch] [ebp-Ch] BYREF
  int t1; // [esp+20h] [ebp-8h] BYREF
  bool v20; // [esp+27h] [ebp-1h]

  vgui::Panel::GetSize(this, wide: &s1, tall: &t1);
  vgui::Panel::GetPos(this, x: &s0, y: &t0);
  vgui::Panel::LocalToScreen(this, x: &s0, y: &t0);
  v2 = materials->GetRenderContext(this: materials);
  v14 = v2;
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  if ( this->m_pBackground != nullptr )
  {
    v3 = this->m_pBackground->GetMappingWidth(this: this->m_pBackground);
    v4 = (float)this->m_pBackground->GetMappingHeight(this: this->m_pBackground);
    v13 = (float)t1 / v4;
    v12 = (float)s1 / (float)v3;
    z = -1;
    v10 = g_pVGuiSurface->GetZPos(this: g_pVGuiSurface);
    RenderQuad(
      pMaterial: this->m_pBackground,
      x: (float)s0,
      y: (float)t0,
      w: (float)s1,
      h: (float)t1,
      z: v10,
      s0: 0.0,
      t0: 0.0,
      s1: v12,
      t1: v13,
      clr: (const Color *)&z);
    v2 = v14;
  }
  v5 = this->HasDocument(this);
  v6 = this->m_pLogo == nullptr;
  v20 = v5;
  if ( !v6 )
  {
    v7 = this->m_pLogo->GetMappingWidth(this: this->m_pLogo);
    if ( v20 )
    {
      v8 = v7 / 2;
      s0 = s1 - v8 - 15;
      v9 = (int)(float)((float)v8 * 0.442);
      t0 = t1 - v9 - 30;
      s1 = v8;
    }
    else
    {
      z = (int)(float)((float)v7 * 0.442);
      s0 = (s1 - v7) / 2;
      s1 = v7;
      v9 = z;
      t0 = (t1 - z) / 2;
    }
    t1 = v9;
    LOWORD(z) = -1;
    BYTE2(z) = -1;
    HIBYTE(z) = v20 - 1;
    v11 = g_pVGuiSurface->GetZPos(this: g_pVGuiSurface);
    RenderQuad(
      pMaterial: this->m_pLogo,
      x: (float)s0,
      y: (float)t0,
      w: (float)s1,
      h: (float)t1,
      z: v11,
      s0: 0.0,
      t0: 0.0,
      s1: 1.0,
      t1: 1.0,
      clr: (const Color *)&z);
  }
  if ( v2 != nullptr )
  {
    v2->EndRender(this: v2);
    v2->Release(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BD2E0
// Name: private: virtual void CBaseToolSystem::OnEditKeyBindings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::OnEditKeyBindings(CBaseToolSystem *this)
{
  vgui::Panel *MostRecentlyFocusedTool; // esi
  vgui::KeyBindingContextHandle_t v3; // eax

  MostRecentlyFocusedTool = CBaseToolSystem::GetMostRecentlyFocusedTool(this);
  if ( MostRecentlyFocusedTool != nullptr )
  {
    v3 = MostRecentlyFocusedTool->GetKeyBindingsContext(this: MostRecentlyFocusedTool);
    CBaseToolSystem::ShowKeyBindingsEditor(this, panel: MostRecentlyFocusedTool, handle: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BD310
// Name: protected: void CBaseToolSystem::UnregisterAllToolWindows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::UnregisterAllToolWindows(CBaseToolSystem *this)
{
  this->m_Tools.m_Size = 0;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_MostRecentlyFocused,
    pPanel: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102BD330
// Name: public: virtual void CBaseToolSystem::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::OnMousePressed(CBaseToolSystem *this, ButtonCode_t code)
{
  if ( code == MOUSE_RIGHT )
    CBaseToolSystem::InitActionMenu(this);
  else
    CToolEntitySprinkle::RenderTool2D((vgui::TreeView *)this, itemIndex: code);
}

//------------------------------------------------------------------------------
// Address: 0x102BD350
// Name: protected: virtual void CBaseToolSystem::OnKeyBindingHelp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseToolSystem::OnKeyBindingHelp(CBaseToolSystem *this)
{
  vgui::Panel *MostRecentlyFocusedTool; // esi
  vgui::KeyBindingContextHandle_t v3; // eax
  ButtonCode_t keycode; // [esp-8h] [ebp-28h]
  int modifiers; // [esp-4h] [ebp-24h]
  CUtlVector<vgui::BoundKey_t *,CUtlMemory<vgui::BoundKey_t *,int> > list; // [esp+Ch] [ebp-14h] BYREF

  MostRecentlyFocusedTool = CBaseToolSystem::GetMostRecentlyFocusedTool(this);
  if ( MostRecentlyFocusedTool != nullptr )
  {
    memset(&list, 0, sizeof(list));
    vgui::Panel::LookupBoundKeys(this, bindingName: "keybindinghelp", &list);
    if ( list.m_Size > 0 )
    {
      modifiers = (*list.m_Memory.m_pMemory)->modifiers;
      keycode = (*list.m_Memory.m_pMemory)->keycode;
      v3 = MostRecentlyFocusedTool->GetKeyBindingsContext(this: MostRecentlyFocusedTool);
      CBaseToolSystem::ShowKeyBindingsHelp(
        this,
        panel: MostRecentlyFocusedTool,
        handle: v3,
        boundKey: keycode,
        modifiers);
    }
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&list);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BD3C0
// Name: public: static void CBaseToolSystem::KB_AddToMap(char const __near *,enum ButtonCode_t,int,void (vgui::Panel::*)(void),char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseToolSystem::KB_AddToMap(
        const char *a1@<ebp>,
        const char *bindingname,
        ButtonCode_t defaultcode,
        int default_modifiers,
        __int128 function,
        __int64 helpstring,
        bool passive)
{
  vgui::PanelKeyBindingMap *v7; // esi
  _DWORD v8[3]; // [esp-Ch] [ebp-4Ch] BYREF
  vgui::KeyBindingMap_t entry; // [esp+0h] [ebp-40h] BYREF
  vgui::BoundKey_t kb; // [esp+30h] [ebp-10h]
  int retaddr; // [esp+40h] [ebp+0h]

  kb.bindingname = a1;
  kb.keycode = retaddr;
  v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseToolSystem");
  vgui::KeyBindingMap_t::KeyBindingMap_t(this: (vgui::KeyBindingMap_t *)v8);
  *(_OWORD *)(&entry.bindingname + 1) = function;
  *(_QWORD *)((char *)&entry.func + 4) = helpstring;
  v8[0] = bindingname;
  BYTE12(entry.func) = passive;
  CUtlVector<vgui::KeyBindingMap_t,CUtlMemory<vgui::KeyBindingMap_t,int>>::InsertBefore(
    this: &v7->entries,
    elem: v7->entries.m_Size,
    src: (const vgui::KeyBindingMap_t *)v8);
  vgui::BoundKey_t::BoundKey_t(this: (vgui::BoundKey_t *)&entry.docstring);
  *((_DWORD *)&entry.passive + 1) = defaultcode;
  LOBYTE(entry.docstring) = 1;
  *(_DWORD *)&entry.passive = bindingname;
  *(_DWORD *)&kb.isbuiltin = default_modifiers;
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
    this: &v7->defaultkeys,
    elem: v7->defaultkeys.m_Size,
    src: (const vgui::BoundKey_t *)&entry.docstring);
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
    this: &v7->boundkeys,
    elem: v7->boundkeys.m_Size,
    src: (const vgui::BoundKey_t *)&entry.docstring);
  vgui::BoundKey_t::~BoundKey_t(this: (vgui::BoundKey_t *)&entry.docstring);
  CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)v8);
}

//------------------------------------------------------------------------------
// Address: 0x102BD490
// Name: public: static void CBaseToolSystem::PanelMessageFunc_OnUnhandledMouseClick::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseToolSystem::PanelMessageFunc_OnUnhandledMouseClick::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseToolSystem::PanelMessageFunc_OnUnhandledMouseClick::InitVar'::`2'::bAdded )
  {
    `CBaseToolSystem::PanelMessageFunc_OnUnhandledMouseClick::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseToolSystem");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "UnhandledMouseClick";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "code";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BD530
// Name: public: static void CBaseToolSystem::PanelMessageFunc_OnFileStateMachineFinished::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseToolSystem::PanelMessageFunc_OnFileStateMachineFinished::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseToolSystem::PanelMessageFunc_OnFileStateMachineFinished::InitVar'::`2'::bAdded )
  {
    `CBaseToolSystem::PanelMessageFunc_OnFileStateMachineFinished::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseToolSystem::`vcall'{1020,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseToolSystem");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "FileStateMachineFinished";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BD5C0
// Name: public: static void CBaseToolSystem::PanelMessageFunc_OnClearRecent::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseToolSystem::PanelMessageFunc_OnClearRecent::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseToolSystem::PanelMessageFunc_OnClearRecent::InitVar'::`2'::bAdded )
  {
    `CBaseToolSystem::PanelMessageFunc_OnClearRecent::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1024,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseToolSystem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnClearRecent";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BD650
// Name: public: static void CBaseToolSystem::PanelMessageFunc_OnEditKeyBindings::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseToolSystem::PanelMessageFunc_OnEditKeyBindings::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CBaseToolSystem::PanelMessageFunc_OnEditKeyBindings::InitVar'::`2'::bAdded )
  {
    `CBaseToolSystem::PanelMessageFunc_OnEditKeyBindings::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Menu::`vcall'{1028,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseToolSystem");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnEditKeyBindings";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102BD6E0
// Name: public: CBaseToolSystem::CBaseToolSystem(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseToolSystem *__thiscall CBaseToolSystem::CBaseToolSystem(CBaseToolSystem *this, const char *pToolName)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::FileOpenStateMachine *v6; // eax
  vgui::FileOpenStateMachine *v7; // eax
  __int128 v9; // [esp-1Ch] [ebp-38h]
  __int128 v10; // [esp-1Ch] [ebp-38h]
  __int64 v11; // [esp+14h] [ebp-8h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: nullptr, panelName: pToolName);
  this->IToolSystem::__vftable = (IToolSystem_vtbl *)&IToolSystem::`vftable';
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&vgui::IFileOpenStateMachineClient::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CBaseToolSystem_vtbl *)&CBaseToolSystem::`vftable'{for `vgui::EditablePanel'};
  this->IToolSystem::__vftable = (IToolSystem_vtbl *)&CBaseToolSystem::`vftable'{for `IToolSystem'};
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&CBaseToolSystem::`vftable'{for `vgui::IFileOpenStateMachineClient'};
  if ( `CBaseToolSystem::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseToolSystem::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CBaseToolSystem");
    v3->pfnClassName = CBaseToolSystem::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseToolSystem::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseToolSystem::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CBaseToolSystem");
    v4->pfnClassName = CBaseToolSystem::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseToolSystem::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseToolSystem::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseToolSystem");
    v5->pfnClassName = CBaseToolSystem::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CBaseToolSystem::PanelMessageFunc_OnUnhandledMouseClick::InitVar(a1: (int)&savedregs);
  if ( `CBaseToolSystem::PanelKBMapFunc_editkeybindings::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v9 = (unsigned int) __thiscall vgui::Menu::`vcall'{1028,{flat}};
    v11 = 0;
    `CBaseToolSystem::PanelKBMapFunc_editkeybindings::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v9 + 1) = 0;
    CBaseToolSystem::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "editkeybindings",
      defaultcode: KEY_E,
      default_modifiers: 7,
      function: v9,
      helpstring: (unsigned int)"#editkeybindings_help",
      passive: false);
  }
  if ( `CBaseToolSystem::PanelKBMapFunc_keybindinghelp::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v10 = (unsigned int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    v11 = 0;
    `CBaseToolSystem::PanelKBMapFunc_keybindinghelp::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v10 + 1) = 0;
    CBaseToolSystem::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "keybindinghelp",
      defaultcode: KEY_H,
      default_modifiers: 0,
      function: v10,
      helpstring: (unsigned int)"#keybindinghelp_help",
      passive: false);
  }
  this->m_RecentFiles.m_RecentFiles.m_Memory.m_pMemory = nullptr;
  this->m_RecentFiles.m_RecentFiles.m_Memory.m_nAllocationCount = 0;
  this->m_RecentFiles.m_RecentFiles.m_Memory.m_nGrowSize = 0;
  this->m_RecentFiles.m_RecentFiles.m_Size = 0;
  this->m_RecentFiles.m_RecentFiles.m_pElements = nullptr;
  CBaseToolSystem::PanelMessageFunc_OnFileStateMachineFinished::InitVar(a1: (int)&savedregs);
  CBaseToolSystem::PanelMessageFunc_OnClearRecent::InitVar(a1: (int)&savedregs);
  CBaseToolSystem::PanelMessageFunc_OnEditKeyBindings::InitVar(a1: (int)&savedregs);
  this->m_hActionMenu.m_iPanelID = -1;
  this->m_hMiniViewport.m_iPanelID = -1;
  this->m_pBackground = nullptr;
  this->m_pLogo = nullptr;
  this->m_hKeyBindingsEditor.m_iPanelID = -1;
  this->m_hKeyBindingsHelp.m_iPanelID = -1;
  this->m_Tools.m_Memory.m_pMemory = nullptr;
  this->m_Tools.m_Memory.m_nAllocationCount = 0;
  this->m_Tools.m_Memory.m_nGrowSize = 0;
  this->m_Tools.m_Size = 0;
  this->m_Tools.m_pElements = nullptr;
  this->m_MostRecentlyFocused.m_iPanelID = -1;
  RegisterTool(tool: &this->IToolSystem);
  vgui::Panel::SetAutoDelete(this, state: false);
  *(_DWORD *)&this->m_bGameInputEnabled = 0;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_MostRecentlyFocused,
    pPanel: nullptr);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: true);
  g_pVGuiInput->RegisterKeyCodeUnhandledListener(this: g_pVGuiInput, a2: this->_vpanel);
  v6 = (vgui::FileOpenStateMachine *)operator new(nSize: 0x1B0u);
  if ( v6 != nullptr )
    v7 = vgui::FileOpenStateMachine::FileOpenStateMachine(
           this: v6,
           pParent: this,
           pClient: &this->vgui::IFileOpenStateMachineClient);
  else
    v7 = nullptr;
  this->m_pFileOpenStateMachine = v7;
  v7->AddActionSignalTarget_2(this: v7, a2: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102BD960
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseToolSystem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseToolSystem::GetMessageMap(CBaseToolSystem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseToolSystem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseToolSystem::GetMessageMap'::`2'::s_pMap;
  `CBaseToolSystem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseToolSystem");
  `CBaseToolSystem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102BD990
// Name: public: virtual struct PanelAnimationMap __near * CBaseToolSystem::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseToolSystem::GetAnimMap(CBaseToolSystem *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseToolSystem");
}

//------------------------------------------------------------------------------
// Address: 0x102BD9A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseToolSystem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseToolSystem::GetKBMap(CBaseToolSystem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseToolSystem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseToolSystem::GetKBMap'::`2'::s_pMap;
  `CBaseToolSystem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseToolSystem");
  `CBaseToolSystem::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C6810
// Name: public: class vgui::Panel __near * vgui::PHandle::Get(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::PHandle::Get(vgui::PHandle *this)
{
  unsigned int v1; // esi
  vgui::IPanel *v2; // edi
  vgui::IPanel_vtbl *v3; // ebx
  const char *ControlsModuleName; // eax

  if ( this->m_iPanelID == -1 )
    return nullptr;
  v1 = g_pVGui->HandleToPanel(this: g_pVGui, a2: this->m_iPanelID);
  if ( v1 == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  return v3->GetPanel(this: v2, a2: v1, a3: ControlsModuleName);
}

//------------------------------------------------------------------------------
// Address: 0x102C8490
// Name: public: class CDragDropHelperPanel __near * vgui::DHANDLE<class CDragDropHelperPanel>::Get(void)
// Source: json
//------------------------------------------------------------------------------
CDragDropHelperPanel *__thiscall vgui::DHANDLE<CDragDropHelperPanel>::Get(vgui::DHANDLE<CDragDropHelperPanel> *this)
{
  unsigned int v1; // edi
  vgui::IPanel *v2; // esi
  vgui::IPanel_vtbl *v3; // ebx
  const char *ControlsModuleName; // eax

  if ( this->m_iPanelID == -1 )
    return nullptr;
  v1 = g_pVGui->HandleToPanel(this: g_pVGui, a2: this->m_iPanelID);
  if ( v1 == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  return (CDragDropHelperPanel *)v3->GetPanel(this: v2, a2: v1, a3: ControlsModuleName);
}

//------------------------------------------------------------------------------
// Address: 0x102C84D0
// Name: public: class CDragDropHelperPanel __near * vgui::DHANDLE<class CDragDropHelperPanel>::operator=(class CDragDropHelperPanel __near *)
// Source: json
//------------------------------------------------------------------------------
CDragDropHelperPanel *__thiscall vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        vgui::DHANDLE<CDragDropHelperPanel> *this,
        CDragDropHelperPanel *pPanel)
{
  vgui::IVGui *v2; // edi
  vgui::IVGui_vtbl *v3; // ebx
  int v4; // eax

  if ( pPanel != nullptr )
  {
    v2 = g_pVGui;
    v3 = g_pVGui->__vftable;
    v4 = pPanel->GetVPanel(this: pPanel);
    this->m_iPanelID = v3->PanelToHandle(this: v2, a2: v4);
    return pPanel;
  }
  else
  {
    this->m_iPanelID = -1;
    return nullptr;
  }
}
