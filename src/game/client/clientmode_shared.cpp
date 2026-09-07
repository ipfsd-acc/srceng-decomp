// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/clientmode_shared.cpp
// Functions: 40
// ============================================================

#include "game\client\clientmode_shared.h"

//------------------------------------------------------------------------------
// Address: 0x100AC930
// Name: hud_reloadscheme
// Source: json
//------------------------------------------------------------------------------
void __cdecl hud_reloadscheme()
{
  ClientModeShared *ClientModeNormal; // eax
  ClientModeCSFullscreen *FullscreenClientMode; // eax
  ClientModeCSFullscreen *v2; // edi
  ClientModeCSFullscreen_vtbl *v3; // esi
  unsigned int FullscreenRootVPANEL; // eax

  g_pFullFileSystem->SyncDvdDevCache(this: g_pFullFileSystem);
  ClientModeNormal = GetClientModeNormal();
  if ( ClientModeNormal != nullptr )
    ClientModeNormal->ReloadScheme(this: ClientModeNormal);
  FullscreenClientMode = GetFullscreenClientMode();
  v2 = FullscreenClientMode;
  if ( FullscreenClientMode != nullptr )
  {
    v3 = FullscreenClientMode->ClientModeCSNormal::ClientModeShared::IClientMode::__vftable;
    FullscreenRootVPANEL = VGui_GetFullscreenRootVPANEL();
    v3->ReloadSchemeWithRoot(this: v2, a2: FullscreenRootVPANEL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AC980
// Name: public: virtual void ClientModeShared::ReloadScheme(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::ReloadScheme(ClientModeShared *this)
{
  ClientModeShared_vtbl *v2; // edi
  unsigned int ClientDLLRootPanel; // eax

  v2 = this->IClientMode::__vftable;
  ClientDLLRootPanel = VGui_GetClientDLLRootPanel();
  v2->ReloadSchemeWithRoot(this, a2: ClientDLLRootPanel);
}

//------------------------------------------------------------------------------
// Address: 0x100AC9A0
// Name: public: virtual void ClientModeShared::ReloadSchemeWithRoot(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::ReloadSchemeWithRoot(ClientModeShared *this, unsigned int pRoot)
{
  int v3; // edx
  int tall; // [esp+4h] [ebp-4h] BYREF

  if ( pRoot != 0 )
  {
    g_pVGuiPanel->GetSize(this: g_pVGuiPanel, a2: pRoot, a3: (int *)&pRoot, a4: &tall);
    v3 = tall;
    this->m_nRootSize[0] = pRoot;
    this->m_nRootSize[1] = v3;
  }
  this->m_pViewport->ReloadScheme(this: this->m_pViewport, a2: "resource/ClientScheme.res");
  ClearKeyValuesCache();
}

//------------------------------------------------------------------------------
// Address: 0x100AC9F0
// Name: public: virtual void ClientModeShared::InitChatHudElement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::InitChatHudElement(ClientModeShared *this)
{
  this->m_pChatElement = CBaseHudChat::GetHudChat();
}

//------------------------------------------------------------------------------
// Address: 0x100ACA00
// Name: public: virtual void ClientModeShared::InitWeaponSelectionHudElement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::InitWeaponSelectionHudElement(ClientModeShared *this)
{
  CHud *Hud; // eax

  Hud = GetHud(nSlot: -1);
  this->m_pWeaponSelection = (CBaseHudWeaponSelection *)CHud::FindElement(this: Hud, pName: "CHudWeaponSelection");
}

//------------------------------------------------------------------------------
// Address: 0x100ACA20
// Name: public: virtual void ClientModeShared::VGui_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::VGui_Shutdown(ClientModeShared *this)
{
  CBaseViewport *m_pViewport; // ecx

  m_pViewport = this->m_pViewport;
  if ( m_pViewport != nullptr )
    ((void (__thiscall *)(CBaseViewport *, int))m_pViewport->dtr_Panel)(a1: m_pViewport, a2: 1);
  this->m_pViewport = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100ACA40
// Name: public: virtual bool ClientModeShared::CreateMove(float,class CUserCmd __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ClientModeShared::CreateMove(ClientModeShared *this, float flInputSampleTime, CUserCmd *cmd)
{
  C_BasePlayer *LocalPlayer; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  return LocalPlayer == nullptr
      || ((bool (__thiscall *)(C_BasePlayer *, _DWORD, CUserCmd *))LocalPlayer->CreateMove)(
           a1: LocalPlayer,
           a2: LODWORD(flInputSampleTime),
           a3: cmd);
}

//------------------------------------------------------------------------------
// Address: 0x100ACA80
// Name: public: virtual void ClientModeShared::OverrideMouseInput(float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::OverrideMouseInput(ClientModeShared *this, float *x, float *y)
{
  C_BasePlayer *LocalPlayer; // eax
  int v4; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    v4 = (int)LocalPlayer->GetActiveWeapon(this: LocalPlayer);
    if ( v4 != 0 )
      (*(void (__thiscall **)(int, float *, float *))(*(_DWORD *)v4 + 1416))(a1: v4, a2: x, a3: y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ACAC0
// Name: public: virtual bool ClientModeShared::ShouldDrawLocalPlayer(class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ClientModeShared::ShouldDrawLocalPlayer(ClientModeShared *this, C_BasePlayer *pPlayer)
{
  bool result; // al

  if ( !C_BaseEntity::IsViewEntity(this: pPlayer) )
    return true;
  result = C_BasePlayer::ShouldDrawLocalPlayer(this: pPlayer);
  if ( result )
    return true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ACAF0
// Name: public: virtual void ClientModeShared::PostRender(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::PostRender(ClientModeShared *this)
{
  CParticleMgr *v1; // eax

  v1 = ParticleMgr();
  CParticleMgr::PostRender(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100ACB00
// Name: public: virtual void ClientModeShared::ProcessInput(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::ProcessInput(ClientModeShared *this, bool bActive)
{
  CHud *Hud; // eax

  Hud = GetHud(nSlot: -1);
  CHud::ProcessInput(this: Hud, bActive);
}

//------------------------------------------------------------------------------
// Address: 0x100ACB20
// Name: ContainsBinding
// Source: json
//------------------------------------------------------------------------------
bool __usercall ContainsBinding@<al>(char *pszBindingString@<esi>, const char *pszBinding@<edi>)
{
  int v2; // eax
  const char *v4; // eax
  char szBinding[256]; // [esp+0h] [ebp-100h] BYREF

  strchr(string: (unsigned __int8 *)pszBindingString, chr: 0x3Bu);
  if ( v2 == 0 )
    return _V_stricmp(s1: pszBindingString, s2: pszBinding) == 0;
  V_strncpy(pDest: szBinding, pSrc: pszBindingString, maxLen: 256);
  v4 = strtok(string: szBinding, control: ";");
  if ( v4 == nullptr )
    return false;
  while ( _V_stricmp(s1: pszBinding, s2: v4) != 0 )
  {
    v4 = strtok(string: nullptr, control: ";");
    if ( v4 == nullptr )
      return false;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x100ACBB0
// Name: public: virtual int ClientModeShared::HandleSpectatorKeyInput(int,enum ButtonCode_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ClientModeShared::HandleSpectatorKeyInput(
        ClientModeShared *this,
        int down,
        ButtonCode_t keynum,
        char *pszCurrentBinding)
{
  C_HLTVCamera *v6; // eax

  if ( down == 0 || pszCurrentBinding == nullptr )
    return 1;
  if ( ContainsBinding(pszBindingString: pszCurrentBinding, pszBinding: "+duck") )
  {
    this->m_pViewport->ShowPanel_2(this: &this->m_pViewport->IViewPort, a2: "specmenu", a3: true);
    return 0;
  }
  if ( ContainsBinding(pszBindingString: pszCurrentBinding, pszBinding: "+attack") )
  {
    engine->ClientCmd(this: engine, a2: "spec_next");
    return 0;
  }
  if ( ContainsBinding(pszBindingString: pszCurrentBinding, pszBinding: "+attack2") )
  {
    engine->ClientCmd(this: engine, a2: "spec_prev");
    return 0;
  }
  if ( ContainsBinding(pszBindingString: pszCurrentBinding, pszBinding: "+jump") )
  {
    engine->ClientCmd(this: engine, a2: "spec_mode");
    return 0;
  }
  if ( !ContainsBinding(pszBindingString: pszCurrentBinding, pszBinding: "+strafe") )
    return 1;
  v6 = HLTVCamera();
  C_HLTVCamera::SetAutoDirector(this: v6, bActive: true);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100ACCB0
// Name: public: virtual int ClientModeShared::HudElementKeyInput(int,enum ButtonCode_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall ClientModeShared::HudElementKeyInput(
        ClientModeShared *this,
        int down,
        ButtonCode_t keynum,
        const char *pszCurrentBinding)
{
  ClientModeCSFullscreen *FullscreenClientMode; // eax
  BOOL result; // eax

  result = (GetFullscreenClientMode() == nullptr
         || GetFullscreenClientMode() == this
         || (FullscreenClientMode = GetFullscreenClientMode(),
             FullscreenClientMode->HudElementKeyInput(
               this: FullscreenClientMode,
               a2: down,
               a3: keynum,
               a4: pszCurrentBinding) != 0))
        && (this->m_pWeaponSelection == nullptr
         || this->m_pWeaponSelection->KeyInput(
              this: this->m_pWeaponSelection,
              a2: down,
              a3: keynum,
              a4: pszCurrentBinding) != 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ACD20
// Name: public: virtual class vgui::Panel __near * ClientModeShared::GetMessagePanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall ClientModeShared::GetMessagePanel(ClientModeShared *this)
{
  CBaseHudChat *m_pChatElement; // ecx
  vgui::Panel *InputPanel; // eax

  m_pChatElement = this->m_pChatElement;
  if ( m_pChatElement != nullptr
    && CBaseHudChat::GetInputPanel(this: m_pChatElement) != nullptr
    && (InputPanel = CBaseHudChat::GetInputPanel(this: this->m_pChatElement), InputPanel->IsVisible(this: InputPanel)) )
  {
    return CBaseHudChat::GetInputPanel(this: this->m_pChatElement);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ACD60
// Name: public: virtual void ClientModeShared::StartMessageMode(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::StartMessageMode(ClientModeShared *this, int iMessageModeType)
{
  if ( *(_DWORD *)(gpGlobals.m_Index + 20) != 1 && this->m_pChatElement != nullptr )
    this->m_pChatElement->StartMessageMode(this: this->m_pChatElement, a2: iMessageModeType);
}

//------------------------------------------------------------------------------
// Address: 0x100ACD90
// Name: public: virtual void ClientModeShared::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::LevelShutdown(ClientModeShared *this)
{
  CLocalPlayerFilter filter; // [esp+0h] [ebp-20h] BYREF

  if ( this->m_pChatElement != nullptr )
    this->m_pChatElement->LevelShutdown(this: this->m_pChatElement);
  if ( s_hVGuiContext != -1 )
  {
    g_pVGui->DestroyContext(this: g_pVGui, a2: s_hVGuiContext);
    s_hVGuiContext = -1;
  }
  CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
  enginesound->SetPlayerDSP(this: enginesound, a2: &filter, a3: 0, a4: true);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x100ACE00
// Name: public: virtual void ClientModeShared::Enable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::Enable(ClientModeShared *this)
{
  unsigned int ClientDLLRootPanel; // eax

  ClientDLLRootPanel = VGui_GetClientDLLRootPanel();
  this->EnableWithRootPanel(this, a2: ClientDLLRootPanel);
}

//------------------------------------------------------------------------------
// Address: 0x100ACE20
// Name: public: virtual void ClientModeShared::EnableWithRootPanel(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::EnableWithRootPanel(ClientModeShared *this, unsigned int pRoot)
{
  if ( pRoot != 0 )
    this->m_pViewport->SetParent(this: this->m_pViewport, a2: pRoot);
  this->m_pViewport->SetProportional(this: this->m_pViewport, a2: true);
  this->m_pViewport->SetCursor(this: this->m_pViewport, a2: this->m_CursorNone);
  g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: this->m_CursorNone);
  this->m_pViewport->SetVisible(this: this->m_pViewport, a2: true);
  if ( this->m_pViewport->IsKeyBoardInputEnabled(this: this->m_pViewport) )
    this->m_pViewport->RequestFocus(this: this->m_pViewport, a2: 0);
  this->Layout(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100ACEB0
// Name: public: virtual void ClientModeShared::Disable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::Disable(ClientModeShared *this)
{
  if ( VGui_GetClientDLLRootPanel() != 0 )
    this->m_pViewport->SetParent(this: this->m_pViewport, a2: 0);
  this->m_pViewport->SetVisible(this: this->m_pViewport, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100ACEE0
// Name: public: virtual void ClientModeShared::Layout(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::Layout(ClientModeShared *this, bool bForce)
{
  unsigned int v3; // edi
  bool v4; // bl
  int tall; // [esp+8h] [ebp-8h] BYREF
  int wide; // [esp+Ch] [ebp-4h] BYREF

  v3 = this->m_pViewport->GetVParent(this: this->m_pViewport);
  if ( v3 != 0 )
  {
    g_pVGuiPanel->GetSize(this: g_pVGuiPanel, a2: v3, a3: &wide, a4: &tall);
    v4 = wide != this->m_nRootSize[0] || tall != this->m_nRootSize[1];
    vgui::Panel::SetBounds(this: this->m_pViewport, x: 0, y: 0, wide, tall);
    if ( v4 || bForce )
      this->ReloadSchemeWithRoot(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ACF60
// Name: public: virtual class vgui::Panel __near * ClientModeShared::GetPanelFromViewport(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall ClientModeShared::GetPanelFromViewport(ClientModeShared *this, char *pchNamePath)
{
  _BYTE *v3; // eax
  int v4; // edi
  char *v5; // eax
  int v6; // eax
  vgui::Panel *(__thiscall *GetViewport)(struct ClientModeShared *); // eax
  vgui::Panel *v8; // ebx
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *Child; // eax
  const char *v12; // eax
  vgui::Panel *v13; // eax
  char *v14; // eax
  int v15; // edi
  char *v16; // eax
  char *v17; // esi
  int v18; // eax
  vgui::Panel *v19; // eax
  vgui::Panel *v20; // esi
  const char *v21; // eax
  char *v23; // [esp-4h] [ebp-120h]
  char szTagetName[256]; // [esp+Ch] [ebp-110h] BYREF
  char *pchName; // [esp+10Ch] [ebp-10h]
  vgui::Panel *pNextPanel; // [esp+110h] [ebp-Ch]
  int nCurrentInstance; // [esp+114h] [ebp-8h]
  int nInstance; // [esp+118h] [ebp-4h]
  char *pchNextName; // [esp+124h] [ebp+8h]
  char *pchNextNamea; // [esp+124h] [ebp+8h]

  V_strncpy(pDest: szTagetName, pSrc: pchNamePath, maxLen: 256);
  strchr(string: szTagetName, chr: 0x3Bu);
  v4 = 0;
  if ( v3 != nullptr )
    *v3 = 0;
  strchr(string: szTagetName, chr: 0x2Fu);
  pchNextName = v5;
  if ( v5 != nullptr )
  {
    *v5 = 0;
    pchNextName = v5 + 1;
  }
  nInstance = 0;
  strchr(string: szTagetName, chr: 0x2Cu);
  if ( v6 != 0 )
  {
    *(_BYTE *)v6 = 0;
    nInstance = atoi(nptr: (const char *)(v6 + 1));
  }
  GetViewport = this->GetViewport;
  nCurrentInstance = 0;
  v8 = nullptr;
  v9 = GetViewport(this);
  if ( vgui::Panel::GetChildCount(this: v9) > 0 )
  {
    while ( 1 )
    {
      v10 = this->GetViewport(this);
      Child = vgui::Panel::GetChild(this: v10, index: v4);
      pNextPanel = Child;
      if ( Child != nullptr )
      {
        v12 = Child->GetName(this: Child);
        if ( _V_stricmp(s1: v12, s2: szTagetName) == 0 && ++nCurrentInstance > nInstance )
          break;
      }
      ++v4;
      v13 = this->GetViewport(this);
      if ( v4 >= vgui::Panel::GetChildCount(this: v13) )
        goto LABEL_14;
    }
    v8 = pNextPanel;
  }
LABEL_14:
  v14 = pchNextName;
  v15 = 0;
  pchName = pchNextName;
  if ( v8 != nullptr )
  {
    while ( v14 != nullptr && *v14 != 0 )
    {
      strchr(string: v14, chr: 0x2Fu);
      v17 = v16;
      pchNextNamea = v16;
      if ( v16 != nullptr )
      {
        *v16 = 0;
        v17 = v16 + 1;
        pchNextNamea = v16 + 1;
      }
      nInstance = 0;
      strchr(string: pchName, chr: 0x2Cu);
      if ( v18 != 0 )
      {
        *(_BYTE *)v18 = 0;
        nInstance = atoi(nptr: (const char *)(v18 + 1));
      }
      nCurrentInstance = 0;
      pNextPanel = nullptr;
      if ( vgui::Panel::GetChildCount(this: v8) > 0 )
      {
        while ( 1 )
        {
          v19 = vgui::Panel::GetChild(this: v8, index: v15);
          v20 = v19;
          if ( v19 != nullptr )
          {
            v23 = pchName;
            v21 = v19->GetName(this: v19);
            if ( _V_stricmp(s1: v21, s2: v23) == 0 && ++nCurrentInstance > nInstance )
              break;
          }
          if ( ++v15 >= vgui::Panel::GetChildCount(this: v8) )
            goto LABEL_30;
        }
        pNextPanel = v20;
LABEL_30:
        v17 = pchNextNamea;
      }
      v8 = pNextPanel;
      pchName = v17;
      if ( pNextPanel == nullptr )
        break;
      v14 = pchNextNamea;
      v15 = 0;
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100AD140
// Name: bool PlayerNameNotSetYet(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl PlayerNameNotSetYet(const char *pszName)
{
  return pszName != nullptr
      && *pszName != 0
      && (V_strnicmp(s1: pszName, s2: "unconnected", n: 11) == 0 || V_strnicmp(s1: pszName, s2: "NULLNAME", n: 11) == 0);
}

//------------------------------------------------------------------------------
// Address: 0x100AD190
// Name: public: virtual void ClientModeShared::ActivateInGameVGuiContext(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::ActivateInGameVGuiContext(ClientModeShared *this, vgui::Panel *pPanel)
{
  vgui::IVGui *v2; // esi
  vgui::IVGui_vtbl *v3; // edi
  int v4; // eax

  v2 = g_pVGui;
  v3 = g_pVGui->__vftable;
  v4 = pPanel->GetVPanel(this: pPanel);
  v3->AssociatePanelWithContext(this: v2, a2: s_hVGuiContext, a3: v4);
  g_pVGui->ActivateContext(this: g_pVGui, a2: s_hVGuiContext);
}

//------------------------------------------------------------------------------
// Address: 0x100AD1D0
// Name: public: virtual void ClientModeShared::DeactivateInGameVGuiContext(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::DeactivateInGameVGuiContext(ClientModeShared *this)
{
  g_pVGui->ActivateContext(this: g_pVGui, a2: -1);
}

//------------------------------------------------------------------------------
// Address: 0x100AD1E0
// Name: protected: int ClientModeShared::GetSplitScreenPlayerSlot(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall ClientModeShared::GetSplitScreenPlayerSlot(ClientModeShared *this)
{
  vgui::IPanel *v1; // esi
  vgui::IPanel_vtbl *v2; // edi
  unsigned int v3; // eax

  v1 = g_pVGuiPanel;
  v2 = g_pVGuiPanel->__vftable;
  v3 = this->m_pViewport->GetVPanel(this: this->m_pViewport);
  return v2->GetMessageContextId(this: v1, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100AD210
// Name: enum ButtonCode_t GetBaseButtonCode(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
ButtonCode_t __cdecl GetBaseButtonCode(ButtonCode_t code)
{
  ButtonCode_t result; // eax

  result = code;
  if ( (unsigned int)(code - 114) <= 0x7F )
    return ((code - 114) & 0x8000001F) + 114;
  if ( (unsigned int)(code - 242) <= 0xF )
    return ((code - 242) & 0x80000003) + 242;
  if ( (unsigned int)(code - 258) <= 0x2F )
    return (code - 258) % 12 + 258;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AD540
// Name: public: ClientModeShared::ClientModeShared(void)
// Source: json
//------------------------------------------------------------------------------
ClientModeShared *__thiscall ClientModeShared::ClientModeShared(ClientModeShared *this)
{
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->m_pViewport = nullptr;
  this->m_pChatElement = nullptr;
  this->m_pWeaponSelection = nullptr;
  this->IClientMode::__vftable = (ClientModeShared_vtbl *)&ClientModeShared::`vftable'{for `IClientMode'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&ClientModeShared::`vftable'{for `CGameEventListener'};
  this->m_nRootSize[1] = -1;
  this->m_nRootSize[0] = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AD580
// Name: public: virtual class vgui::AnimationController __near * ClientModeShared::GetViewportAnimationController(void)
// Source: json
//------------------------------------------------------------------------------
vgui::AnimationController *__thiscall ClientModeShared::GetViewportAnimationController(ClientModeShared *this)
{
  return this->m_pViewport->GetAnimationController(this: this->m_pViewport);
}

//------------------------------------------------------------------------------
// Address: 0x100AD5A0
// Name: public: virtual ClientModeShared::~ClientModeShared(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::~ClientModeShared(ClientModeShared *this)
{
  CGameEventListener *v2; // esi
  bool v3; // zf

  v2 = &this->CGameEventListener;
  this->IClientMode::__vftable = (ClientModeShared_vtbl *)&ClientModeShared::`vftable'{for `IClientMode'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&ClientModeShared::`vftable'{for `CGameEventListener'};
  v3 = !this->m_bRegisteredForEvents;
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 13;
  if ( !v3 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: v2);
    v2->m_bRegisteredForEvents = false;
  }
  v2->__vftable = (CGameEventListener_vtbl *)&IGameEventListener2::`vftable';
  this->IClientMode::__vftable = (ClientModeShared_vtbl *)&IClientMode::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x100AD5F0
// Name: public: virtual int ClientModeShared::KeyInput(int,enum ButtonCode_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ClientModeShared::KeyInput(
        ClientModeShared *this,
        int down,
        ButtonCode_t keynum,
        const char *pszCurrentBinding)
{
  C_BasePlayer *LocalPlayer; // esi
  int v7; // eax

  if ( engine->Con_IsVisible(this: engine) )
    return 1;
  if ( pszCurrentBinding == nullptr )
    goto LABEL_14;
  if ( _V_strcmp(s1: pszCurrentBinding, s2: "messagemode") == 0 || _V_strcmp(s1: pszCurrentBinding, s2: "say") == 0 )
  {
    if ( down != 0 )
      this->StartMessageMode(this, a2: 1);
    return 0;
  }
  if ( _V_strcmp(s1: pszCurrentBinding, s2: "messagemode2") != 0
    && _V_strcmp(s1: pszCurrentBinding, s2: "say_team") != 0 )
  {
LABEL_14:
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( (unsigned int)(keynum - 114) <= 0xBF )
      keynum = GetBaseButtonCode(code: keynum);
    if ( (LocalPlayer == nullptr
       || LocalPlayer->GetObserverMode(this: LocalPlayer) <= 1
       || this->HandleSpectatorKeyInput(this, a2: down, a3: keynum, a4: pszCurrentBinding) != 0)
      && this->HudElementKeyInput(this, a2: down, a3: keynum, a4: pszCurrentBinding) != 0 )
    {
      if ( LocalPlayer != nullptr && (v7 = (int)LocalPlayer->GetActiveWeapon(this: LocalPlayer)) != 0 )
        return (*(int (__thiscall **)(int, int, ButtonCode_t, const char *))(*(_DWORD *)v7 + 1420))(
                 a1: v7,
                 a2: down,
                 a3: keynum,
                 a4: pszCurrentBinding);
      else
        return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    if ( down != 0 )
      this->StartMessageMode(this, a2: 2);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD750
// Name: public: virtual void ClientModeShared::LevelInit(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::LevelInit(ClientModeShared *this, const char *newmap)
{
  vgui::AnimationController *v3; // eax
  CBaseHudChat *m_pChatElement; // ecx
  IGameEvent *v5; // esi
  CLocalPlayerFilter filter; // [esp+8h] [ebp-20h] BYREF

  v3 = this->m_pViewport->GetAnimationController(this: this->m_pViewport);
  vgui::AnimationController::StartAnimationSequence(this: v3, sequenceName: "LevelInit");
  m_pChatElement = this->m_pChatElement;
  if ( m_pChatElement != nullptr )
    CBaseHudChat::LevelInit(this: m_pChatElement, newmap);
  v5 = (IGameEvent *)((int (__thiscall *)(IGameEventManager2 *, const char *))gameeventmanager->CreateEventA)(
                       a1: gameeventmanager,
                       a2: "game_newmap");
  if ( v5 != nullptr )
  {
    v5->SetString(this: v5, a2: "mapname", a3: newmap);
    gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v5);
  }
  if ( s_hVGuiContext == -1 )
    s_hVGuiContext = g_pVGui->CreateContext(this: g_pVGui);
  CLocalPlayerFilter::CLocalPlayerFilter(this: &filter);
  enginesound->SetPlayerDSP(this: enginesound, a2: &filter, a3: 0, a4: true);
  C_RecipientFilter::~C_RecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x100AD810
// Name: public: virtual float ClientModeShared::GetViewModelFOV(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall ClientModeShared::GetViewModelFOV(ClientModeShared *this)
{
  return v_viewmodel_fov.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x100ADB50
// Name: public: virtual void ClientModeShared::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::Init(ClientModeShared *this)
{
  C_HLTVCamera *v2; // eax

  this->InitChatHudElement(this);
  this->InitWeaponSelectionHudElement(this);
  CBaseViewport::LoadHudLayout(this: this->m_pViewport);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "player_connect", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "player_disconnect",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "player_team", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "server_cvar", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "player_changename",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "teamplay_broadcast_audio",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "achievement_earned",
    a4: false);
  v2 = HLTVCamera();
  C_HLTVCamera::Init(this: v2);
  this->m_CursorNone = 1;
  CUserMessages::HookMessage(this: usermessages, name: "VGUIMenu", hook: _MsgFunc_VGUIMenu);
  CUserMessages::HookMessage(this: usermessages, name: "Rumble", hook: _MsgFunc_Rumble);
}

//------------------------------------------------------------------------------
// Address: 0x100ADC60
// Name: public: virtual void ClientModeShared::OverrideView(class CViewSetup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::OverrideView(ClientModeShared *this, CViewSetup *pSetup)
{
  C_BasePlayer *LocalPlayer; // edi
  CViewSetup *v3; // esi
  float *v4; // eax
  float z; // xmm0_4
  float x; // xmm1_4
  float v7; // xmm0_4
  float m_fValue; // xmm0_4
  float v9; // xmm0_4
  ConVar *m_pConVarState; // edi
  double v11; // xmm0_8
  double v12; // xmm0_8
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  Vector v16; // [esp+4h] [ebp-4Ch] BYREF
  Vector camUp; // [esp+10h] [ebp-40h] BYREF
  Vector camRight; // [esp+1Ch] [ebp-34h] BYREF
  Vector camForward; // [esp+28h] [ebp-28h] BYREF
  Vector cam_ofs; // [esp+34h] [ebp-1Ch] BYREF
  QAngle camAngles; // [esp+40h] [ebp-10h] BYREF
  float h; // [esp+4Ch] [ebp-4h] BYREF

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    v3 = pSetup;
    LocalPlayer->OverrideView(this: LocalPlayer, a2: pSetup);
    if ( input->CAM_IsThirdPerson(this: input, a2: -1) != 0 )
    {
      input->CAM_GetCameraOffset(this: input, a2: &cam_ofs);
      camAngles.x = cam_ofs.x;
      camAngles.y = cam_ofs.y;
      camAngles.z = 0.0;
      AngleVectors(angles: &camAngles, forward: &camForward, right: &camRight, up: &camUp);
      v4 = (float *)LocalPlayer->GetThirdPersonViewPosition(this: LocalPlayer, result: &v16);
      z = cam_ofs.z;
      v3->origin.x = *v4;
      x = camForward.x;
      v3->origin.y = v4[1];
      v3->origin.z = v4[2];
      LODWORD(v7) = LODWORD(z) ^ _mask__NegFloat_;
      v3->origin.x = (float)(x * v7) + v3->origin.x;
      v3->origin.y = (float)(camForward.y * v7) + v3->origin.y;
      v3->origin.z = (float)(camForward.z * v7) + v3->origin.z;
      if ( (_S5_90 & 1) == 0 )
      {
        _S5_90 |= 1u;
        ConVarRef::ConVarRef(this: &c_thirdpersonshoulder, pName: "c_thirdpersonshoulder");
      }
      if ( c_thirdpersonshoulder.m_pConVarState->m_Value.m_nValue != 0 )
      {
        if ( (_S5_90 & 2) == 0 )
        {
          _S5_90 |= 2u;
          ConVarRef::ConVarRef(this: &c_thirdpersonshoulderoffset, pName: "c_thirdpersonshoulderoffset");
        }
        if ( (_S5_90 & 4) == 0 )
        {
          _S5_90 |= 4u;
          ConVarRef::ConVarRef(this: &c_thirdpersonshoulderheight, pName: "c_thirdpersonshoulderheight");
        }
        if ( (_S5_90 & 8) == 0 )
        {
          _S5_90 |= 8u;
          ConVarRef::ConVarRef(this: &c_thirdpersonshoulderaimdist, pName: "c_thirdpersonshoulderaimdist");
        }
        m_fValue = c_thirdpersonshoulderoffset.m_pConVarState->m_Value.m_fValue;
        v3->origin.x = (float)(camRight.x * m_fValue) + v3->origin.x;
        v3->origin.y = (float)(camRight.y * m_fValue) + v3->origin.y;
        v3->origin.z = (float)(camRight.z * m_fValue) + v3->origin.z;
        v9 = c_thirdpersonshoulderheight.m_pConVarState->m_Value.m_fValue;
        v3->origin.x = (float)(camUp.x * v9) + v3->origin.x;
        v3->origin.y = (float)(camUp.y * v9) + v3->origin.y;
        v3->origin.z = (float)(camUp.z * v9) + v3->origin.z;
        m_pConVarState = c_thirdpersonshoulderaimdist.m_pConVarState;
        v11 = (float)(c_thirdpersonshoulderoffset.m_pConVarState->m_Value.m_fValue
                    / (float)(c_thirdpersonshoulderaimdist.m_pConVarState->m_Value.m_fValue + cam_ofs.z));
        __libm_sse2_atan();
        *(float *)&v11 = v11;
        camAngles.y = (float)(*(float *)&v11 * 57.29578) + camAngles.y;
        v12 = (float)(c_thirdpersonshoulderheight.m_pConVarState->m_Value.m_fValue
                    / (float)(m_pConVarState->m_Value.m_fValue + cam_ofs.z));
        __libm_sse2_atan();
        *(float *)&v12 = v12;
        v13 = (float)(*(float *)&v12 * 57.29578) + camAngles.x;
      }
      else
      {
        v13 = camAngles.x;
      }
      v3->angles.x = v13;
      v3->angles.y = camAngles.y;
      v3->angles.z = camAngles.z;
    }
    else if ( input->CAM_IsOrthographic(this: input) )
    {
      v3->m_bOrtho = true;
      input->CAM_OrthographicSize(this: input, a2: (float *)&pSetup, a3: &h);
      v14 = *(float *)&pSetup * 0.5;
      v15 = h * 0.5;
      v3->m_OrthoLeft = -(float)(*(float *)&pSetup * 0.5);
      v3->m_OrthoTop = -v15;
      v3->m_OrthoRight = v14;
      v3->m_OrthoBottom = v15;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ADF80
// Name: public: virtual void ClientModeShared::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::Update(ClientModeShared *this)
{
  int m_nValue; // esi
  bool v3; // al
  vgui::CTreeViewListControl *v4; // ecx
  int v5; // eax
  vgui::PropertyPage *v6; // ecx

  if ( cl_drawhud.m_pParent != nullptr )
    m_nValue = cl_drawhud.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v3 = this->m_pViewport->IsVisible(this: this->m_pViewport);
  LOBYTE(v4) = m_nValue != 0;
  if ( v3 != (m_nValue != 0) )
  {
    if ( cl_drawhud.m_pParent != nullptr )
      v5 = cl_drawhud.m_pParent->m_Value.m_nValue;
    else
      v5 = 0;
    this->m_pViewport->SetVisible(this: this->m_pViewport, a2: v5 != 0);
  }
  C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: v4);
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100ADFF0
// Name: public: virtual void ClientModeShared::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ClientModeShared::FireGameEvent(ClientModeShared *this, IGameEvent *event)
{
  CBaseHudChat *HudChat; // edi
  const char *v4; // ebx
  const char *v5; // eax
  vgui::ILocalize_vtbl *v6; // ebx
  int v7; // eax
  CClientEntityList *m_Index; // ebx
  int v9; // eax
  int v10; // eax
  C_BaseEntity *BaseEntity; // eax
  const char *v12; // eax
  vgui::ILocalize_vtbl *v13; // ebx
  const char *PlayerName; // eax
  vgui::ILocalize_vtbl *v15; // ebx
  int v16; // eax
  vgui::ILocalize_vtbl *v17; // esi
  int v18; // eax
  const char *v19; // eax
  vgui::ILocalize_vtbl *v20; // ebx
  int v21; // eax
  vgui::ILocalize_vtbl *v22; // esi
  int v23; // eax
  CClientEntityList *v24; // ebx
  int v25; // eax
  int v26; // eax
  C_BaseEntity *v27; // eax
  C_CSPlayer *v28; // eax
  C_BasePlayer *v29; // ebx
  int v30; // eax
  IGameEvent_vtbl *v31; // edx
  bool v32; // al
  IGameEvent_vtbl *v33; // edx
  const char *v34; // esi
  int v35; // esi
  C_Team *GlobalTeam; // eax
  vgui::ILocalize_vtbl *v37; // esi
  int v38; // eax
  vgui::ILocalize_vtbl *v39; // esi
  int v40; // eax
  const char *v41; // ebx
  vgui::ILocalize_vtbl *v42; // ebx
  int v43; // eax
  vgui::ILocalize_vtbl *v44; // esi
  int v45; // eax
  int v46; // edi
  C_Team *v47; // eax
  int SpectatorTarget; // eax
  C_BasePlayer *v49; // ebx
  bool v50; // zf
  int v51; // edi
  C_Team *LocalTeam; // eax
  const char *v53; // eax
  vgui::ILocalize_vtbl *v54; // ebx
  int v55; // eax
  vgui::ILocalize_vtbl *v56; // ebx
  int v57; // eax
  vgui::ILocalize_vtbl *v58; // esi
  int v59; // eax
  int v60; // eax
  C_BasePlayer *v61; // ebx
  int v62; // [esp+14h] [ebp-220h]
  int v63; // [esp+14h] [ebp-220h]
  int v64; // [esp+14h] [ebp-220h]
  const char *v65; // [esp+18h] [ebp-21Ch]
  wchar_t wszLocalized[100]; // [esp+24h] [ebp-210h] BYREF
  wchar_t szLocalized[64]; // [esp+ECh] [ebp-148h] BYREF
  _BYTE v68[28]; // [esp+16Ch] [ebp-C8h] BYREF
  wchar_t wszOldName[32]; // [esp+188h] [ebp-ACh] BYREF
  CLocalPlayerFilter filter; // [esp+1ECh] [ebp-48h] BYREF
  wchar_t wszCvarValue[16]; // [esp+20Ch] [ebp-28h] BYREF
  bool bAutoTeamed; // [esp+22Fh] [ebp-5h]
  int team; // [esp+230h] [ebp-4h]
  IVEngineClient_vtbl *bSilenta; // [esp+23Ch] [ebp+8h]
  C_BasePlayer *bSilent; // [esp+23Ch] [ebp+8h]
  IVEngineClient_vtbl *bSilentb; // [esp+23Ch] [ebp+8h]
  bool bSilent_3; // [esp+23Fh] [ebp+Bh]
  char bSilent_3a; // [esp+23Fh] [ebp+Bh]

  team = (int)this;
  HudChat = CBaseHudChat::GetHudChat();
  v4 = event->GetName(this: event);
  if ( _V_strcmp(s1: "player_connect", s2: v4) == 0 )
  {
    if ( (ClientModeCSFullscreen *)(team - 4) != GetFullscreenClientMode() && HudChat != nullptr )
    {
      v5 = event->GetString(this: event, a2: "name", a3: prType);
      if ( !PlayerNameNotSetYet(pszName: v5) && !IsInCommentaryMode() )
      {
        v6 = g_pVGuiLocalize->__vftable;
        v7 = ((int (__thiscall *)(IGameEvent *, const char *, const char *, CLocalPlayerFilter *, int))event->GetString)(
               a1: event,
               a2: "name",
               a3: prType,
               a4: &filter,
               a5: 64);
        ((void (__thiscall *)(vgui::ILocalize *, int))v6->ConvertANSIToUnicode)(a1: g_pVGuiLocalize, a2: v7);
        v65 = "#game_player_connecting";
LABEL_21:
        v22 = g_pVGuiLocalize->__vftable;
        v23 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, CLocalPlayerFilter *))g_pVGuiLocalize->Find)(
                a1: g_pVGuiLocalize,
                a2: v65,
                a3: 1,
                a4: &filter);
        ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v22->ConstructString_3)(
          a1: g_pVGuiLocalize,
          a2: wszLocalized,
          a3: 200,
          a4: v23);
        ((void (__thiscall *)(vgui::ILocalize *, wchar_t *))g_pVGuiLocalize->ConvertUnicodeToANSI)(
          a1: g_pVGuiLocalize,
          a2: wszLocalized);
        HudChat->Printf(this: HudChat, a2: 1, a3: "%s", wszOldName);
        return;
      }
    }
    return;
  }
  if ( _V_strcmp(s1: "player_disconnect", s2: v4) == 0 )
  {
    if ( (ClientModeCSFullscreen *)(team - 4) != GetFullscreenClientMode() )
    {
      m_Index = (CClientEntityList *)cl_entitylist.m_Index;
      bSilenta = engine->__vftable;
      v9 = event->GetInt(this: event, a2: "userid", a3: 0);
      v10 = bSilenta->GetPlayerForUserID(this: engine, a2: v9);
      BaseEntity = CClientEntityList::GetBaseEntity(this: m_Index, entnum: v10);
      if ( BaseEntity == nullptr || (bSilent = (C_BasePlayer *)BaseEntity, !BaseEntity->IsPlayer(this: BaseEntity)) )
        bSilent = nullptr;
      if ( HudChat != nullptr && bSilent != nullptr )
      {
        v12 = event->GetString(this: event, a2: "name", a3: prType);
        if ( !PlayerNameNotSetYet(pszName: v12) && !IsInCommentaryMode() )
        {
          v13 = g_pVGuiLocalize->__vftable;
          PlayerName = C_BasePlayer::GetPlayerName(this: bSilent);
          v13->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: PlayerName, a3: (wchar_t *)&filter, a4: 64);
          v15 = g_pVGuiLocalize->__vftable;
          v16 = ((int (__thiscall *)(IGameEvent *, const char *, const char *, wchar_t *, int))event->GetString)(
                  a1: event,
                  a2: "reason",
                  a3: prType,
                  a4: szLocalized,
                  a5: 128);
          ((void (__thiscall *)(vgui::ILocalize *, int))v15->ConvertANSIToUnicode)(a1: g_pVGuiLocalize, a2: v16);
          v17 = g_pVGuiLocalize->__vftable;
          v18 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, CLocalPlayerFilter *, wchar_t *))g_pVGuiLocalize->Find)(
                  a1: g_pVGuiLocalize,
                  a2: "#game_player_left_game",
                  a3: 2,
                  a4: &filter,
                  a5: szLocalized);
          ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v17->ConstructString_3)(
            a1: g_pVGuiLocalize,
            a2: wszLocalized,
            a3: 200,
            a4: v18);
          ((void (__thiscall *)(vgui::ILocalize *, wchar_t *, wchar_t *, int, int))g_pVGuiLocalize->ConvertUnicodeToANSI)(
            a1: g_pVGuiLocalize,
            a2: wszLocalized,
            a3: wszOldName,
            a4: 100,
            a5: v62);
          HudChat->Printf(this: HudChat, a2: 1, a3: "%s", wszOldName);
        }
      }
    }
    return;
  }
  if ( _V_strcmp(s1: "player_fullyjoined", s2: v4) != 0 )
  {
    if ( _V_strcmp(s1: "player_team", s2: v4) == 0 )
    {
      if ( (ClientModeCSFullscreen *)(team - 4) != GetFullscreenClientMode() )
      {
        v24 = (CClientEntityList *)cl_entitylist.m_Index;
        bSilentb = engine->__vftable;
        v25 = event->GetInt(this: event, a2: "userid", a3: 0);
        v26 = bSilentb->GetPlayerForUserID(this: engine, a2: v25);
        v27 = CClientEntityList::GetBaseEntity(this: v24, entnum: v26);
        v28 = ToBasePlayer(pEntity: v27);
        v29 = v28;
        if ( HudChat != nullptr && v28 != nullptr && !event->GetBool(this: event, a2: "disconnect", a3: false) )
        {
          v30 = event->GetInt(this: event, a2: "team", a3: 0);
          v31 = event->__vftable;
          team = v30;
          v32 = v31->GetBool(this: event, a2: "autoteam", a3: false);
          v33 = event->__vftable;
          bAutoTeamed = v32;
          bSilent_3 = v33->GetBool(this: event, a2: "silent", a3: false);
          v34 = C_BasePlayer::GetPlayerName(this: v29);
          if ( !PlayerNameNotSetYet(pszName: v34) )
          {
            if ( !bSilent_3 )
            {
              g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v34, a3: (wchar_t *)&filter, a4: 64);
              v35 = team;
              GlobalTeam = GetGlobalTeam(iTeamNumber: team);
              if ( GlobalTeam != nullptr )
              {
                v37 = g_pVGuiLocalize->__vftable;
                v38 = ((int (__thiscall *)(C_Team *, wchar_t *, int))GlobalTeam->Get_Name)(
                        a1: GlobalTeam,
                        a2: szLocalized,
                        a3: 128);
                ((void (__thiscall *)(vgui::ILocalize *, int))v37->ConvertANSIToUnicode)(a1: g_pVGuiLocalize, a2: v38);
              }
              else
              {
                V_snwprintf(pDest: szLocalized, maxLen: 64, pFormat: L"%d", v35);
              }
              if ( !IsInCommentaryMode() )
              {
                v39 = g_pVGuiLocalize->__vftable;
                if ( bAutoTeamed )
                  v40 = ((int (__cdecl *)(const char *, int, CLocalPlayerFilter *, wchar_t *))v39->Find)(
                          a1: "#game_player_joined_autoteam",
                          a2: 2,
                          a3: &filter,
                          a4: szLocalized);
                else
                  v40 = ((int (__cdecl *)(const char *, int, CLocalPlayerFilter *, wchar_t *))v39->Find)(
                          a1: "#game_player_joined_team",
                          a2: 2,
                          a3: &filter,
                          a4: szLocalized);
                ((void (__stdcall *)(vgui::ILocalize *, wchar_t *, int, int))v39->ConstructString_3)(
                  a1: g_pVGuiLocalize,
                  a2: wszLocalized,
                  a3: 200,
                  a4: v40);
                g_pVGuiLocalize->ConvertUnicodeToANSI(
                  this: g_pVGuiLocalize,
                  a2: wszLocalized,
                  a3: (char *)wszOldName,
                  a4: 100);
                HudChat->Printf(this: HudChat, a2: 16, a3: "%s", wszOldName);
              }
            }
            if ( C_BasePlayer::IsLocalPlayer(pEntity: v29) )
              v29->TeamChange(this: v29, a2: team);
          }
        }
      }
      return;
    }
    if ( _V_strcmp(s1: "player_changename", s2: v4) == 0 )
    {
      if ( (ClientModeCSFullscreen *)(team - 4) != GetFullscreenClientMode() && HudChat != nullptr )
      {
        v41 = event->GetString(this: event, a2: "oldname", a3: prType);
        if ( !PlayerNameNotSetYet(pszName: v41) )
        {
          g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v41, a3: &wszOldName[18], a4: 64);
          v42 = g_pVGuiLocalize->__vftable;
          v43 = ((int (__thiscall *)(IGameEvent *, const char *, const char *, CLocalPlayerFilter *, int))event->GetString)(
                  a1: event,
                  a2: "newname",
                  a3: prType,
                  a4: &filter,
                  a5: 64);
          ((void (__thiscall *)(vgui::ILocalize *, int))v42->ConvertANSIToUnicode)(a1: g_pVGuiLocalize, a2: v43);
          v44 = g_pVGuiLocalize->__vftable;
          v45 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, wchar_t *, CLocalPlayerFilter *))g_pVGuiLocalize->Find)(
                  a1: g_pVGuiLocalize,
                  a2: "#game_player_changed_name",
                  a3: 2,
                  a4: &wszOldName[18],
                  a5: &filter);
          ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v44->ConstructString_3)(
            a1: g_pVGuiLocalize,
            a2: wszLocalized,
            a3: 200,
            a4: v45);
          ((void (__thiscall *)(vgui::ILocalize *, wchar_t *, wchar_t *, int, int))g_pVGuiLocalize->ConvertUnicodeToANSI)(
            a1: g_pVGuiLocalize,
            a2: wszLocalized,
            a3: &szLocalized[14],
            a4: 100,
            a5: v63);
          HudChat->Printf(this: HudChat, a2: 2, a3: "%s", &szLocalized[14]);
        }
      }
      return;
    }
    if ( _V_strcmp(s1: "teamplay_broadcast_audio", s2: v4) != 0 )
    {
      if ( _V_strcmp(s1: "teamplay_broadcast_audio", s2: v4) != 0 )
      {
        if ( _V_strcmp(s1: "server_cvar", s2: v4) != 0 )
        {
          if ( _V_strcmp(s1: "achievement_earned", s2: v4) != 0 )
          {
            event->GetName(this: event);
            _DevMsg(a1: 2, a2: "Unhandled GameEvent in ClientModeShared::FireGameEvent - %s\n");
          }
          else if ( (ClientModeCSFullscreen *)(team - 4) != GetFullscreenClientMode() )
          {
            v60 = event->GetInt(this: event, a2: "player", a3: 0);
            v61 = UTIL_PlayerByIndex(entindex: v60);
            event->GetInt(this: event, a2: "achievement", a3: 0);
            if ( HudChat != nullptr && v61 != nullptr )
              IsInCommentaryMode();
          }
        }
        else if ( (ClientModeCSFullscreen *)(team - 4) != GetFullscreenClientMode() && !IsInCommentaryMode() )
        {
          v54 = g_pVGuiLocalize->__vftable;
          v55 = ((int (__thiscall *)(IGameEvent *, const char *, const char *, _BYTE *, int))event->GetString)(
                  a1: event,
                  a2: "cvarname",
                  a3: prType,
                  a4: v68,
                  a5: 128);
          ((void (__thiscall *)(vgui::ILocalize *, int))v54->ConvertANSIToUnicode)(a1: g_pVGuiLocalize, a2: v55);
          v56 = g_pVGuiLocalize->__vftable;
          v57 = ((int (__thiscall *)(IGameEvent *, const char *, const char *, wchar_t *, int))event->GetString)(
                  a1: event,
                  a2: "cvarvalue",
                  a3: prType,
                  a4: wszCvarValue,
                  a5: 32);
          ((void (__thiscall *)(vgui::ILocalize *, int))v56->ConvertANSIToUnicode)(a1: g_pVGuiLocalize, a2: v57);
          v58 = g_pVGuiLocalize->__vftable;
          v59 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, _BYTE *, wchar_t *))g_pVGuiLocalize->Find)(
                  a1: g_pVGuiLocalize,
                  a2: "#game_server_cvar_changed",
                  a3: 2,
                  a4: v68,
                  a5: wszCvarValue);
          ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v58->ConstructString_3)(
            a1: g_pVGuiLocalize,
            a2: wszLocalized,
            a3: 200,
            a4: v59);
          ((void (__thiscall *)(vgui::ILocalize *, wchar_t *, wchar_t *, int, int))g_pVGuiLocalize->ConvertUnicodeToANSI)(
            a1: g_pVGuiLocalize,
            a2: wszLocalized,
            a3: &szLocalized[14],
            a4: 100,
            a5: v64);
          HudChat->Printf(this: HudChat, a2: 8, a3: "%s", &szLocalized[14]);
        }
        return;
      }
      if ( (ClientModeCSFullscreen *)(team - 4) == GetFullscreenClientMode() )
        return;
      v51 = event->GetInt(this: event, a2: "team", a3: 0);
      if ( v51 != 0 )
      {
        if ( GetLocalTeam() == nullptr )
          return;
        LocalTeam = GetLocalTeam();
        v50 = LocalTeam->GetTeamNumber(this: LocalTeam) == v51;
LABEL_63:
        if ( !v50 )
          return;
      }
    }
    else
    {
      if ( (ClientModeCSFullscreen *)(team - 4) == GetFullscreenClientMode() )
        return;
      v46 = event->GetInt(this: event, a2: "team", a3: 0);
      bSilent_3a = 0;
      if ( GetLocalTeam() != nullptr && (v47 = GetLocalTeam(), v47->GetTeamNumber(this: v47) == v46)
        || (SpectatorTarget = GetSpectatorTarget(), (v49 = UTIL_PlayerByIndex(entindex: SpectatorTarget)) != nullptr)
        && (GetSpectatorMode() == 4 || GetSpectatorMode() == 5)
        && v49->GetTeamNumber(this: v49) == v46 )
      {
        bSilent_3a = 1;
      }
      if ( v46 == 0 )
      {
        if ( GetLocalTeam() != nullptr )
          return;
        goto LABEL_57;
      }
      if ( v46 != 255 )
      {
LABEL_57:
        v50 = bSilent_3a == 1;
        goto LABEL_63;
      }
    }
    CLocalPlayerFilter::CLocalPlayerFilter(this: (CLocalPlayerFilter *)wszCvarValue);
    v53 = event->GetString(this: event, a2: "sound", a3: prType);
    C_BaseEntity::EmitSound(
      filter: (IRecipientFilter *)wszCvarValue,
      iEntIndex: -1,
      soundname: v53,
      pOrigin: nullptr,
      soundtime: 0.0,
      duration: nullptr);
    C_RecipientFilter::~C_RecipientFilter(this: (C_RecipientFilter *)wszCvarValue);
    return;
  }
  if ( HudChat != nullptr )
  {
    v19 = event->GetString(this: event, a2: "name", a3: prType);
    if ( !PlayerNameNotSetYet(pszName: v19) )
    {
      v20 = g_pVGuiLocalize->__vftable;
      v21 = ((int (__thiscall *)(IGameEvent *, const char *, const char *, CLocalPlayerFilter *, int))event->GetString)(
              a1: event,
              a2: "name",
              a3: prType,
              a4: &filter,
              a5: 64);
      ((void (__thiscall *)(vgui::ILocalize *, int))v20->ConvertANSIToUnicode)(a1: g_pVGuiLocalize, a2: v21);
      v65 = "#game_player_joined_game";
      goto LABEL_21;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AE820
// Name: public: virtual bool ClientModeShared::OverrideRenderBounds(int __near &,int __near &,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ClientModeShared::OverrideRenderBounds(
        ClientModeShared *this,
        int *x,
        int *y,
        int *w,
        int *h,
        int *insetX,
        int *insetY)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x100AD280
// Name: __MsgFunc_Rumble
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _MsgFunc_Rumble(bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int v2; // edx
  vgui::PropertyPage *v3; // esi
  int v4; // ecx
  const unsigned int *v5; // ecx
  const unsigned int *v6; // edx
  unsigned int v7; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v10; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v12; // esi
  unsigned int v13; // ebx
  int v14; // ecx
  unsigned int v15; // edx
  int v16; // ecx
  const unsigned int *v17; // ecx
  const unsigned int *v18; // edx
  unsigned int v19; // edx
  const unsigned int *v20; // esi
  int v21; // edx
  const unsigned int *v22; // ecx
  unsigned int v23; // esi
  int v24; // ecx
  unsigned int v25; // edx
  unsigned int *v26; // ecx
  const unsigned int *v27; // edx
  unsigned int v28; // edx
  const unsigned int *v29; // esi
  unsigned int *v30; // edx
  unsigned int v31; // esi
  vgui::PropertyPage *v32; // [esp+Ch] [ebp-4h]

  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v10 = 8 - m_nBitsAvail;
    m_pDataIn = msg->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_16;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( msg->m_bOverflow )
    {
      v32 = nullptr;
    }
    else
    {
      v12 = msg->m_nInBufWord;
      v13 = (v12 & CBitBuffer::s_nMaskTable[v10]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v10;
      v32 = (vgui::PropertyPage *)(v13 | m_nInBufWord);
      msg->m_nInBufWord = v12 >> v10;
    }
    goto LABEL_19;
  }
  v2 = msg->m_nInBufWord;
  v3 = (vgui::PropertyPage *)(unsigned __int8)v2;
  v4 = m_nBitsAvail - 8;
  msg->m_nBitsAvail = v4;
  if ( v4 != 0 )
  {
    msg->m_nInBufWord = v2 >> 8;
    v32 = (vgui::PropertyPage *)(unsigned __int8)v2;
  }
  else
  {
    v5 = msg->m_pDataIn;
    v6 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v5 == v6 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v5 + 1;
      v32 = v3;
    }
    else
    {
      if ( v5 <= v6 )
      {
        v7 = *v5;
        msg->m_pDataIn = v5 + 1;
        msg->m_nInBufWord = v7;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v32 = v3;
    }
  }
LABEL_19:
  v14 = msg->m_nBitsAvail;
  if ( v14 >= 8 )
  {
    v15 = msg->m_nInBufWord;
    v16 = v14 - 8;
    msg->m_nBitsAvail = v16;
    if ( v16 != 0 )
    {
      msg->m_nInBufWord = v15 >> 8;
    }
    else
    {
      v17 = msg->m_pDataIn;
      v18 = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( v17 == v18 )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_pDataIn = v17 + 1;
      }
      else if ( v17 <= v18 )
      {
        v19 = *v17;
        msg->m_pDataIn = v17 + 1;
        msg->m_nInBufWord = v19;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
    }
    goto LABEL_35;
  }
  v20 = msg->m_pBufferEnd;
  v21 = 8 - v14;
  v22 = msg->m_pDataIn;
  if ( v22 == v20 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
  }
  else
  {
    if ( v22 > v20 )
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
      goto LABEL_33;
    }
    msg->m_nInBufWord = *v22;
  }
  msg->m_pDataIn = v22 + 1;
LABEL_33:
  if ( !msg->m_bOverflow )
  {
    v23 = msg->m_nInBufWord;
    msg->m_nBitsAvail = 32 - v21;
    msg->m_nInBufWord = v23 >> v21;
  }
LABEL_35:
  v24 = msg->m_nBitsAvail;
  if ( v24 >= 8 )
  {
    v25 = msg->m_nInBufWord;
    v26 = (unsigned int *)(v24 - 8);
    msg->m_nBitsAvail = (int)v26;
    if ( v26 != nullptr )
    {
      msg->m_nInBufWord = v25 >> 8;
    }
    else
    {
      v26 = (unsigned int *)msg->m_pDataIn;
      v27 = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( v26 == v27 )
      {
        ++v26;
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_pDataIn = v26;
      }
      else if ( v26 <= v27 )
      {
        v28 = *v26++;
        msg->m_pDataIn = v26;
        msg->m_nInBufWord = v28;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
    }
    goto LABEL_51;
  }
  v29 = msg->m_pBufferEnd;
  v30 = (unsigned int *)(8 - v24);
  v26 = (unsigned int *)msg->m_pDataIn;
  if ( v26 == v29 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
  }
  else
  {
    if ( v26 > v29 )
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
      goto LABEL_49;
    }
    msg->m_nInBufWord = *v26;
  }
  msg->m_pDataIn = ++v26;
LABEL_49:
  if ( !msg->m_bOverflow )
  {
    v31 = msg->m_nInBufWord;
    msg->m_nBitsAvail = 32 - (_DWORD)v30;
    v26 = v30;
    msg->m_nInBufWord = v31 >> (char)v30;
  }
LABEL_51:
  C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: (vgui::CTreeViewListControl *)v26);
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v32);
}

//------------------------------------------------------------------------------
// Address: 0x100AD820
// Name: __MsgFunc_VGUIMenu
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _MsgFunc_VGUIMenu(bf_read *msg)
{
  bf_read *v1; // esi
  int v2; // ebx
  int m_nBitsAvail; // ecx
  unsigned int v4; // edx
  int v5; // edi
  unsigned int v6; // edx
  const unsigned int *v7; // eax
  const unsigned int *v8; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v11; // eax
  const unsigned int *m_pDataIn; // ecx
  int v13; // eax
  unsigned int v14; // edx
  unsigned int v15; // ebx
  int v16; // ecx
  unsigned int v17; // eax
  int v18; // edx
  int v19; // ecx
  const unsigned int *v20; // eax
  const unsigned int *v21; // ecx
  const unsigned int *v22; // edx
  unsigned int v23; // edi
  int v24; // eax
  const unsigned int *v25; // ecx
  unsigned int v26; // edx
  unsigned int v27; // ebx
  KeyValues *v28; // edi
  KeyValues *v29; // eax
  IViewPort *ViewPortInterface; // eax
  char panelname[2048]; // [esp+Ch] [ebp-A00h] BYREF
  char data[256]; // [esp+80Ch] [ebp-200h] BYREF
  char name[256]; // [esp+90Ch] [ebp-100h] BYREF
  float bShow; // [esp+A14h] [ebp+8h]

  v1 = msg;
  v2 = 0;
  CBitRead::ReadString(this: msg, pStr: panelname, maxLen: 2048, bLine: false, pOutNumChars: nullptr);
  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v11 = 8 - m_nBitsAvail;
    m_pDataIn = msg->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
LABEL_15:
        if ( msg->m_bOverflow )
        {
          v13 = 0;
          goto LABEL_20;
        }
        v14 = msg->m_nInBufWord;
        v15 = (v14 & CBitBuffer::s_nMaskTable[v11]) << msg->m_nBitsAvail;
        msg->m_nBitsAvail = 32 - v11;
        v5 = v15 | m_nInBufWord;
        v6 = v14 >> v11;
        v2 = 0;
        goto LABEL_18;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v4 = msg->m_nInBufWord;
  v5 = (unsigned __int8)v4;
  msg->m_nBitsAvail = m_nBitsAvail - 8;
  if ( m_nBitsAvail == 8 )
  {
    v7 = msg->m_pDataIn;
    v8 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v7 + 1;
    }
    else if ( v7 <= v8 )
    {
      msg->m_nInBufWord = *v7;
      msg->m_pDataIn = v7 + 1;
    }
    else
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v6 = v4 >> 8;
LABEL_18:
  msg->m_nInBufWord = v6;
LABEL_19:
  v13 = v5;
LABEL_20:
  v16 = msg->m_nBitsAvail;
  LOBYTE(msg) = v13 != 0;
  if ( v16 >= 8 )
  {
    v17 = v1->m_nInBufWord;
    v18 = (unsigned __int8)v17;
    v19 = v16 - 8;
    v1->m_nBitsAvail = v19;
    if ( v19 != 0 )
    {
      v1->m_nInBufWord = v17 >> 8;
      v2 = (unsigned __int8)v17;
    }
    else
    {
      v20 = v1->m_pDataIn;
      v21 = v1->m_pBufferEnd;
      v1->m_nBitsAvail = 32;
      if ( v20 == v21 )
      {
        v1->m_nInBufWord = 0;
        v1->m_nBitsAvail = 1;
        v1->m_pDataIn = v20 + 1;
        v2 = v18;
      }
      else
      {
        if ( v20 <= v21 )
        {
          v1->m_nInBufWord = *v20;
          v1->m_pDataIn = v20 + 1;
        }
        else
        {
          v1->m_nInBufWord = 0;
          v1->m_bOverflow = true;
        }
        v2 = v18;
      }
    }
    goto LABEL_37;
  }
  v22 = v1->m_pBufferEnd;
  v23 = v1->m_nInBufWord;
  v24 = 8 - v16;
  v25 = v1->m_pDataIn;
  if ( v25 == v22 )
  {
    v1->m_nBitsAvail = 1;
    v1->m_nInBufWord = 0;
    v1->m_bOverflow = true;
  }
  else
  {
    if ( v25 > v22 )
    {
      v1->m_bOverflow = true;
      v1->m_nInBufWord = 0;
      goto LABEL_35;
    }
    v1->m_nInBufWord = *v25;
  }
  v1->m_pDataIn = v25 + 1;
LABEL_35:
  if ( !v1->m_bOverflow )
  {
    v26 = v1->m_nInBufWord;
    v27 = (v26 & CBitBuffer::s_nMaskTable[v24]) << v1->m_nBitsAvail;
    v1->m_nBitsAvail = 32 - v24;
    v2 = v23 | v27;
    v1->m_nInBufWord = v26 >> v24;
  }
LABEL_37:
  v28 = nullptr;
  if ( v2 > 0 )
  {
    v29 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v29 != nullptr )
      v28 = KeyValues::KeyValues(this: v29, setName: "data");
    else
      v28 = nullptr;
    do
    {
      CBitRead::ReadString(this: v1, pStr: name, maxLen: 255, bLine: false, pOutNumChars: nullptr);
      CBitRead::ReadString(this: v1, pStr: data, maxLen: 255, bLine: false, pOutNumChars: nullptr);
      KeyValues::SetString(this: v28, keyName: name, value: data);
      --v2;
    }
    while ( v2 != 0 );
  }
  ViewPortInterface = GetViewPortInterface();
  ViewPortInterface->ShowPanel_3(this: ViewPortInterface, a2: panelname, a3: (bool)msg, a4: v28, a5: true);
  if ( _V_stricmp(s1: panelname, s2: "scores") == 0
    && hud_takesshots.m_pParent != nullptr
    && hud_takesshots.m_pParent->m_Value.m_nValue != 0 )
  {
    bShow = *(float *)(gpGlobals.m_Index + 12) + 1.0;
    GetHud(nSlot: -1)->m_flScreenShotTime = bShow;
  }
}
