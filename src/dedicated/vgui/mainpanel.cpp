// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dedicated/vgui/mainpanel.cpp
// Functions: 78
// ============================================================

#include "dedicated\vgui\mainpanel.h"

//------------------------------------------------------------------------------
// Address: 0x1001C0A0
// Name: public: virtual enum vgui::KeyBindingContextHandle_t vgui::Panel::GetKeyBindingsContext(void)const
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t __thiscall vgui::Panel::GetKeyBindingsContext(vgui::Panel *this)
{
  return this->m_hKeyBindingsContext;
}

//------------------------------------------------------------------------------
// Address: 0x1001C0C0
// Name: public: virtual class vgui::IBorder __near * vgui::Panel::GetBorder(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall vgui::Panel::GetBorder(vgui::Panel *this)
{
  return this->_border;
}

//------------------------------------------------------------------------------
// Address: 0x10026140
// Name: private: virtual class vgui::Panel __near * vgui::Panel::GetPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetPanel(vgui::Panel *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10027160
// Name: public: static char const __near * vgui::Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Panel::GetPanelClassName()
{
  return "Panel";
}

//------------------------------------------------------------------------------
// Address: 0x10027170
// Name: public: virtual void CMainPanel::Open(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainPanel::Open(CMainPanel *this)
{
  this->m_pConfigPage->SetVisible(this: this->m_pConfigPage, a2: true);
  this->m_pConfigPage->MoveToFront(this: this->m_pConfigPage);
}

//------------------------------------------------------------------------------
// Address: 0x100271A0
// Name: public: static class CMainPanel __near * CMainPanel::GetInstance(void)
// Source: json
//------------------------------------------------------------------------------
CMainPanel *__cdecl CMainPanel::GetInstance()
{
  return s_InternetDlg;
}

//------------------------------------------------------------------------------
// Address: 0x100271B0
// Name: public: void CMainPanel::AddConsoleText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainPanel::AddConsoleText(CMainPanel *this, const char *msg)
{
  if ( this->m_pGameServer != nullptr )
    this->m_pGameServer->AddToConsole(this: this->m_pGameServer, a2: msg);
}

//------------------------------------------------------------------------------
// Address: 0x100271D0
// Name: private: virtual struct vgui::PanelMap_t __near * CMainPanel::GetPanelMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMap_t *__thiscall CMainPanel::GetPanelMap(CMainPanel *this)
{
  return &CMainPanel::m_PanelMap;
}

//------------------------------------------------------------------------------
// Address: 0x100271E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Panel::GetMessageMap(vgui::Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Panel::GetMessageMap'::`2'::s_pMap;
  `vgui::Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Panel");
  `vgui::Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10027220
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::GetKBMap(vgui::Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Panel::GetKBMap'::`2'::s_pMap;
  `vgui::Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  `vgui::Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10027250
// Name: public: CMainPanel::CMainPanel(void)
// Source: json
//------------------------------------------------------------------------------
CMainPanel *__thiscall CMainPanel::CMainPanel(CMainPanel *this)
{
  vgui::Panel::Panel(this, parent: nullptr, panelName: "CMainPanel");
  this->__vftable = (CMainPanel_vtbl *)&CMainPanel::`vftable';
  this->m_pProgressBox.m_iPanelID = -1;
  this->s1.pings[0] = 0;
  this->s1.pings[1] = 0;
  this->s1.pings[2] = 0;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetFgColor(this, color: 0);
  this->m_bStarting = false;
  this->m_pGameServer = nullptr;
  this->m_flPreviousSteamProgress = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10027310
// Name: public: virtual void CMainPanel::Initialize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainPanel::Initialize(CMainPanel *this)
{
  void (__thiscall *MoveToFront)(vgui::Panel *); // edx
  CCreateMultiplayerGameServerPage *v3; // eax

  s_InternetDlg = this;
  this->m_pGameServer = nullptr;
  this->m_bStarted = false;
  *(_WORD *)&this->m_bClosing = 256;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_pProgressBox, pPanel: nullptr);
  MoveToFront = this->MoveToFront;
  this->m_hShutdown = nullptr;
  MoveToFront(this);
  v3 = (CCreateMultiplayerGameServerPage *)operator new(nSize: 0x544u);
  if ( v3 != nullptr )
    this->m_pConfigPage = CCreateMultiplayerGameServerPage::CCreateMultiplayerGameServerPage(
                            this: v3,
                            parent: this,
                            name: "Config");
  else
    this->m_pConfigPage = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10027390
// Name: public: virtual void CMainPanel::StartServer(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainPanel::StartServer(CMainPanel *this, const char *cvars)
{
  char *v3; // eax
  vgui::ProgressBox *v4; // eax
  vgui::ProgressBox *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  HANDLE EventA; // eax
  CMainPanel_vtbl *v10; // edx
  vgui::IVGui *v11; // ebx
  vgui::IVGui_vtbl *v12; // edi
  int v13; // eax
  char reslist[260]; // [esp+Ch] [ebp-104h] BYREF

  g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 4u);
  CCreateMultiplayerGameServerPage::GetServer(this: this->m_pConfigPage, s: &this->s1);
  this->m_pConfigPage->SetVisible(this: this->m_pConfigPage, a2: false);
  this->m_pConfigPage->Close(this: this->m_pConfigPage);
  if ( cvars != nullptr && (v3 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(cvars) + 1)) != nullptr )
    strcpy(v3, cvars);
  else
    v3 = nullptr;
  gpszCvars = v3;
  v4 = (vgui::ProgressBox *)operator new(nSize: 0x52Cu);
  if ( v4 != nullptr )
    v5 = vgui::ProgressBox::ProgressBox(
           this: v4,
           title: "#Start_Server_Loading_Title",
           text: "#Server_UpdatingSteamResources",
           pszUnknownTimeString: "Starting dedicated server...",
           parent: nullptr);
  else
    v5 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_pProgressBox, pPanel: v5);
  v6 = vgui::PHandle::Get(this: &this->m_pProgressBox);
  v6->__vftable[1].SetPaintEnabled(this: v6, a2: true);
  v7 = vgui::PHandle::Get(this: &this->m_pProgressBox);
  ((void (__thiscall *)(vgui::Panel *, _DWORD))v7->__vftable[1].GetBorder)(a1: v7, a2: 0);
  _snprintf(string: reslist, count: 0x104u, format: "reslists/%s/preload.lst", this->m_pConfigPage->m_szGameName);
  this->m_hResourceWaitHandle = g_pFullFileSystem->WaitForResources(this: g_pFullFileSystem, a2: reslist);
  v8 = vgui::PHandle::Get(this: &this->m_pProgressBox);
  v8->__vftable[1].SetPostChildPaintEnabled(this: v8, a2: false);
  EventA = CreateEventA(lpEventAttributes: nullptr, bManualReset: true, bInitialState: false, lpName: nullptr);
  v10 = this->__vftable;
  this->m_hShutdown = EventA;
  v11 = g_pVGui;
  v12 = g_pVGui->__vftable;
  v13 = ((int (__thiscall *)(CMainPanel *, _DWORD))v10->GetVPanel)(a1: this, a2: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v12->AddTickSignal)(a1: v11, a2: v13);
}

//------------------------------------------------------------------------------
// Address: 0x10027530
// Name: private: void CMainPanel::DoStop(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainPanel::DoStop(CMainPanel *this)
{
  vgui::DHANDLE<vgui::ProgressBox> *p_m_pProgressBox; // esi
  vgui::Panel *v3; // eax

  g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 0);
  *(_WORD *)&this->m_bStarted = 256;
  p_m_pProgressBox = &this->m_pProgressBox;
  if ( vgui::PHandle::Get(this: p_m_pProgressBox) != nullptr )
  {
    v3 = vgui::PHandle::Get(this: p_m_pProgressBox);
    v3->__vftable[1].GetAnimMap(this: v3);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_pProgressBox, pPanel: nullptr);
  }
  g_pVGui->Stop(this: g_pVGui);
}

//------------------------------------------------------------------------------
// Address: 0x10027590
// Name: private: virtual void CMainPanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CMainPanel::OnClose(CMainPanel *this)
{
  CMainPanel::DoStop(this);
}

//------------------------------------------------------------------------------
// Address: 0x100275A0
// Name: private: virtual void CMainPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMainPanel::OnTick(CMainPanel *this)
{
  vgui::Panel *v2; // eax
  const char *v3; // ecx
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  CCreateMultiplayerGameServerPage *m_pConfigPage; // ecx
  unsigned int v7; // eax
  vgui::Panel *v8; // eax
  void *m_hShutdown; // [esp+14h] [ebp-154h]
  serveritem_t server; // [esp+24h] [ebp-144h] BYREF
  float progress; // [esp+160h] [ebp-8h] BYREF
  bool complete; // [esp+167h] [ebp-1h] BYREF

  if ( this->m_hResourceWaitHandle != 0 )
  {
    if ( vgui::PHandle::Get(this: &this->m_pProgressBox) == nullptr
      || (v2 = vgui::PHandle::Get(this: &this->m_pProgressBox), !v2->IsVisible(this: v2)) )
    {
      g_pFullFileSystem->CancelWaitForResources(this: g_pFullFileSystem, a2: this->m_hResourceWaitHandle);
      this->m_hResourceWaitHandle = 0;
      CMainPanel::DoStop(this);
      return;
    }
    if ( g_pFullFileSystem->GetWaitForResourcesProgress(
           this: g_pFullFileSystem,
           a2: this->m_hResourceWaitHandle,
           a3: &progress,
           a4: &complete) )
    {
      v3 = "not complete";
      if ( !complete )
        v3 = "complete";
      g_pVGui->DPrintf2(this: g_pVGui, a2: "progress %.2f %s\n", progress, v3);
      if ( progress != 1.0 || this->m_flPreviousSteamProgress != 0.0 )
      {
        v4 = vgui::PHandle::Get(this: &this->m_pProgressBox);
        ((void (__thiscall *)(vgui::Panel *, float))v4->__vftable[1].SetPaintBorderEnabled)(
          a1: v4,
          a2: COERCE_FLOAT(LODWORD(progress)));
        this->m_flPreviousSteamProgress = progress;
      }
    }
    Sleep(dwMilliseconds: 0xC8u);
    if ( complete )
    {
      this->m_hResourceWaitHandle = 0;
      this->m_bStarting = true;
      this->m_bIsInConfig = false;
      v5 = vgui::PHandle::Get(this: &this->m_pProgressBox);
      v5->__vftable[1].SetPostChildPaintEnabled(this: v5, a2: false);
    }
  }
  if ( this->m_bStarting )
  {
    if ( WaitForSingleObject(hHandle: this->m_hShutdown, dwMilliseconds: 0xAu) != 0 && count <= 5000 )
    {
      ++count;
    }
    else
    {
      if ( this->m_bStarted )
      {
        CMainPanel::DoStop(this);
      }
      else
      {
        m_pConfigPage = this->m_pConfigPage;
        memset(server.pings, 0, sizeof(server.pings));
        CCreateMultiplayerGameServerPage::GetServer(this: m_pConfigPage, s: &server);
        v7 = g_pAdminServer->OpenManageServerDialog_2(this: g_pAdminServer, a2: server.name, a3: server.gameDir);
        this->m_pGameServer = g_pAdminServer->GetManageServerInterface(this: g_pAdminServer, a2: v7);
        this->m_bStarted = true;
        if ( vgui::PHandle::Get(this: &this->m_pProgressBox) != nullptr )
        {
          v8 = vgui::PHandle::Get(this: &this->m_pProgressBox);
          v8->__vftable[1].GetAnimMap(this: v8);
          vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_pProgressBox, pPanel: nullptr);
        }
      }
      g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 0);
      m_hShutdown = this->m_hShutdown;
      this->m_bStarting = false;
      ResetEvent(hEvent: m_hShutdown);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038BC0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetParent(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetParent(vgui::Panel *this)
{
  vgui::IPanel *v1; // esi
  vgui::IPanel_vtbl *v2; // edi
  int v3; // eax
  int v4; // esi
  vgui::IPanel *v5; // edi
  vgui::IPanel_vtbl *v6; // ebx
  const char *ControlsModuleName; // eax

  v1 = g_pVGuiPanel;
  if ( g_pVGuiPanel == nullptr )
    return nullptr;
  v2 = g_pVGuiPanel->__vftable;
  v3 = this->GetVPanel(this);
  v4 = v2->GetParent(this: v1, a2: v3);
  if ( v4 == 0 )
    return nullptr;
  v5 = g_pVGuiPanel;
  v6 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  return v6->GetPanel(this: v5, a2: v4, a3: ControlsModuleName);
}

//------------------------------------------------------------------------------
// Address: 0x10038F50
// Name: public: class vgui::Panel __near * vgui::Panel::FindSiblingByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindSiblingByName(vgui::Panel *this, const char *siblingName)
{
  vgui::Panel *result; // eax
  vgui::IPanel *v4; // edi
  vgui::IPanel_vtbl *v5; // esi
  unsigned int v6; // eax
  vgui::IPanel *v7; // edi
  vgui::IPanel_vtbl *v8; // esi
  int v9; // eax
  int v10; // eax
  vgui::IPanel *v11; // edi
  vgui::IPanel_vtbl *v12; // esi
  const char *ControlsModuleName; // eax
  int v14; // esi
  const char *v15; // eax
  int siblingCount; // [esp+4h] [ebp-Ch]
  unsigned int sibling; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  result = (vgui::Panel *)this->GetVParent(this);
  if ( result != nullptr )
  {
    v4 = g_pVGuiPanel;
    v5 = g_pVGuiPanel->__vftable;
    v6 = this->GetVParent(this);
    siblingCount = v5->GetChildCount(this: v4, a2: v6);
    i = 0;
    if ( siblingCount <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        v7 = g_pVGuiPanel;
        v8 = g_pVGuiPanel->__vftable;
        v9 = ((int (__thiscall *)(vgui::Panel *, int))this->GetVParent)(a1: this, a2: i);
        v10 = ((int (__thiscall *)(vgui::IPanel *, int))v8->GetChild)(a1: v7, a2: v9);
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        sibling = v10;
        ControlsModuleName = vgui::GetControlsModuleName();
        v14 = (int)v12->GetPanel(this: v11, a2: sibling, a3: ControlsModuleName);
        v15 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v14 + 72))(a1: v14);
        if ( _V_stricmp(s1: v15, s2: siblingName) == 0 )
          break;
        if ( ++i >= siblingCount )
          return nullptr;
      }
      return (vgui::Panel *)v14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039980
// Name: public: class vgui::Panel __near * vgui::Panel::GetChild(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetChild(vgui::Panel *this, int index)
{
  vgui::IPanel *v2; // edi
  vgui::IPanel *v4; // ebx
  const char *ControlsModuleName; // eax
  int v6; // eax
  int v7; // eax
  vgui::IPanel_vtbl *v9; // [esp+Ch] [ebp-8h]
  vgui::IPanel_vtbl *v10; // [esp+10h] [ebp-4h]

  v2 = g_pVGuiPanel;
  v4 = g_pVGuiPanel;
  v9 = g_pVGuiPanel->__vftable;
  v10 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  v6 = ((int (__thiscall *)(vgui::Panel *, int, const char *))this->GetVPanel)(
         a1: this,
         a2: index,
         a3: ControlsModuleName);
  v7 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v2, a2: v6);
  return ((vgui::Panel *(__thiscall *)(vgui::IPanel *, int))v9->GetPanel)(a1: v4, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10039F80
// Name: public: enum vgui::Panel::PinCorner_e vgui::Panel::GetPinCorner(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetPinCorner(vgui::Panel *this)
{
  return *((_BYTE *)this + 166) & 0xF;
}

//------------------------------------------------------------------------------
// Address: 0x10039FB0
// Name: public: enum vgui::Panel::AutoResize_e vgui::Panel::GetAutoResize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetAutoResize(vgui::Panel *this)
{
  return *((unsigned __int8 *)this + 166) >> 4;
}

//------------------------------------------------------------------------------
// Address: 0x1003A430
// Name: public: virtual struct vgui::PanelMap_t __near * vgui::Panel::GetPanelMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMap_t *__thiscall vgui::Panel::GetPanelMap(vgui::Panel *this)
{
  return &vgui::Panel::m_PanelMap;
}

//------------------------------------------------------------------------------
// Address: 0x1003BD20
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetDropTarget(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetDropTarget(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  vgui::Panel *v4; // eax

  if ( this->m_pDragDrop->m_bDropEnabled && this->IsDroppable(this, a2: msglist) )
    return this;
  if ( this->GetParent(this) == nullptr )
    return nullptr;
  v4 = this->GetParent(this);
  return v4->GetDropTarget(this: v4, a2: msglist);
}

//------------------------------------------------------------------------------
// Address: 0x1003BD90
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetDragPanel(vgui::Panel *this)
{
  vgui::DragDrop_t *m_pDragDrop; // eax
  vgui::Panel *v4; // eax

  m_pDragDrop = this->m_pDragDrop;
  if ( m_pDragDrop->m_bPreventChaining )
    return nullptr;
  if ( m_pDragDrop->m_bDragEnabled )
    return this;
  if ( this->GetParent(this) == nullptr )
    return nullptr;
  v4 = this->GetParent(this);
  return v4->GetDragPanel(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1003CAA0
// Name: public: class vgui::Panel __near * vgui::Panel::FindChildByName(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindChildByName(vgui::Panel *this, const char *childName, bool recurseDown)
{
  vgui::IPanel *v3; // ebx
  vgui::IPanel_vtbl *v4; // esi
  int v5; // eax
  int v6; // eax
  vgui::IPanel_vtbl *v7; // edi
  vgui::IPanel_vtbl *v8; // esi
  const char *ControlsModuleName; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  vgui::Panel *v13; // esi
  const char *v14; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v16; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v16 = this;
  for ( i = 0; ; ++i )
  {
    v3 = g_pVGuiPanel;
    if ( g_pVGuiPanel != nullptr )
    {
      v4 = g_pVGuiPanel->__vftable;
      v5 = this->GetVPanel(this);
      v6 = v4->GetChildCount(this: v3, a2: v5);
      v3 = g_pVGuiPanel;
    }
    else
    {
      v6 = 0;
    }
    if ( i >= v6 )
      break;
    v7 = v3->__vftable;
    v8 = v3->__vftable;
    ControlsModuleName = vgui::GetControlsModuleName();
    v10 = ((int (__thiscall *)(vgui::Panel *, int, const char *))v16->GetVPanel)(a1: v16, a2: i, a3: ControlsModuleName);
    v11 = ((int (__thiscall *)(vgui::IPanel *, int))v7->GetChild)(a1: v3, a2: v10);
    v12 = ((int (__thiscall *)(vgui::IPanel *, int))v8->GetPanel)(a1: v3, a2: v11);
    v13 = (vgui::Panel *)v12;
    if ( v12 != 0 )
    {
      v14 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 72))(a1: v12);
      if ( _V_stricmp(s1: v14, s2: childName) == 0 )
        return v13;
      if ( recurseDown )
      {
        result = vgui::Panel::FindChildByName(this: v13, childName, recurseDown);
        if ( result != nullptr )
          return result;
      }
    }
    this = v16;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003DBF0
// Name: public: class vgui::Tooltip __near * vgui::Panel::GetTooltip(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Panel::GetTooltip(vgui::Panel *this)
{
  vgui::Tooltip *v2; // eax
  vgui::Tooltip *result; // eax
  bool v4; // zf

  if ( this->m_pTooltips != nullptr )
    return this->m_pTooltips;
  v2 = (vgui::Tooltip *)operator new(nSize: 0x24u);
  if ( v2 != nullptr )
    result = vgui::Tooltip::Tooltip(this: v2, parent: this, text: nullptr);
  else
    result = nullptr;
  v4 = (*((_BYTE *)this + 172) & 8) == 0;
  this->m_pTooltips = result;
  if ( !v4 )
  {
    vgui::Tooltip::SetEnabled(this: result, bState: false);
    return this->m_pTooltips;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003E3E0
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavUp(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavUp(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavUp; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  unsigned int v11; // edi
  vgui::IPanel *v12; // esi
  vgui::IPanel_vtbl *v13; // ebx
  const char *v14; // eax
  int v15; // eax
  int v16; // ebx
  unsigned int v17; // edi
  vgui::IPanel *v18; // esi
  vgui::IPanel_vtbl *v19; // ebx
  const char *v20; // eax
  unsigned int v21; // eax
  vgui::PHandle *v22; // ebx
  unsigned int v23; // edi
  vgui::IPanel *v24; // esi
  vgui::IPanel_vtbl *v25; // ebx
  const char *v26; // eax
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  const char *v31; // [esp-8h] [ebp-20h]
  vgui::PHandle *v33; // [esp+10h] [ebp-8h]
  vgui::Panel *v34; // [esp+14h] [ebp-4h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavUp.m_iPanelID;
  p_m_NavUp = &this->m_NavUp;
  v33 = &this->m_NavUp;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v34 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v34->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavUp = v33,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavUpName) > 0 )
    {
      v31 = CUtlString::operator char const *(this: &this->m_sNavUpName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v31, recurseDown: true);
      if ( ChildByName != nullptr )
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavUp, pPanel: ChildByName);
    }
  }
  if ( p_m_NavUp->m_iPanelID == -1 || (v11 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID)) == 0 )
  {
    v35 = nullptr;
    v16 = 0;
  }
  else
  {
    v12 = g_pVGuiPanel;
    v13 = g_pVGuiPanel->__vftable;
    v14 = vgui::GetControlsModuleName();
    v15 = (int)v13->GetPanel(this: v12, a2: v11, a3: v14);
    p_m_NavUp = v33;
    v16 = v15;
    v35 = (vgui::Panel *)v15;
  }
  if ( p_m_NavUp->m_iPanelID == -1 )
    return (vgui::Panel *)v16;
  v17 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID);
  if ( v17 == 0 )
    return (vgui::Panel *)v16;
  v18 = g_pVGuiPanel;
  v19 = g_pVGuiPanel->__vftable;
  v20 = vgui::GetControlsModuleName();
  if ( v19->GetPanel(this: v18, a2: v17, a3: v20) == nullptr )
    return v35;
  v21 = this->m_NavUp.m_iPanelID;
  v22 = &this->m_NavUp;
  if ( v21 == -1 || (v23 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v21)) == 0 )
  {
    v27 = nullptr;
  }
  else
  {
    v24 = g_pVGuiPanel;
    v25 = g_pVGuiPanel->__vftable;
    v26 = vgui::GetControlsModuleName();
    v27 = v25->GetPanel(this: v24, a2: v23, a3: v26);
    v22 = &this->m_NavUp;
  }
  if ( v27 == first )
    return v35;
  v28 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v22);
  if ( v28->IsVisible(this: v28) )
    return v35;
  v29 = this;
  if ( first != nullptr )
    v29 = first;
  return vgui::Panel::GetNavUp(this: v35, first: v29);
}

//------------------------------------------------------------------------------
// Address: 0x1003E5A0
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavDown(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavDown(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavDown; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavDown.m_iPanelID;
  p_m_NavDown = &this->m_NavDown;
  v34 = &this->m_NavDown;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavDown = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavDownName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavDownName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavDown, pPanel: v11);
      }
    }
  }
  if ( p_m_NavDown->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavDown = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavDown->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavDown.m_iPanelID;
  v23 = &this->m_NavDown;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavDown;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavDown(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x1003E770
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavLeft(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavLeft(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavLeft; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavLeft.m_iPanelID;
  p_m_NavLeft = &this->m_NavLeft;
  v34 = &this->m_NavLeft;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavLeft = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavLeftName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavLeftName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavLeft, pPanel: v11);
      }
    }
  }
  if ( p_m_NavLeft->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavLeft = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavLeft->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavLeft.m_iPanelID;
  v23 = &this->m_NavLeft;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavLeft;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavLeft(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x1003E940
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavRight(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavRight(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavRight; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavRight.m_iPanelID;
  p_m_NavRight = &this->m_NavRight;
  v34 = &this->m_NavRight;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavRight = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavRightName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavRightName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavRight, pPanel: v11);
      }
    }
  }
  if ( p_m_NavRight->m_iPanelID == -1
    || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavRight = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavRight->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavRight.m_iPanelID;
  v23 = &this->m_NavRight;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavRight;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavRight(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x1003F1E0
// Name: public: struct vgui::PanelKeyBindingMap __near * vgui::Panel::LookupMapForBinding(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::LookupMapForBinding(vgui::Panel *this, const char *bindingName)
{
  vgui::PanelKeyBindingMap *v2; // ebx
  int v3; // edi
  int v4; // esi
  int c; // [esp+Ch] [ebp-4h]

  v2 = this->GetKBMap(this);
  if ( v2 == nullptr )
    return nullptr;
  while ( 1 )
  {
    v3 = 0;
    c = v2->entries.m_Size;
    if ( c > 0 )
      break;
LABEL_6:
    v2 = v2->baseMap;
    if ( v2 == nullptr )
      return nullptr;
  }
  v4 = 0;
  while ( _V_stricmp(s1: v2->entries.m_Memory.m_pMemory[v4].bindingname, s2: bindingName) != 0 )
  {
    ++v3;
    ++v4;
    if ( v3 >= c )
      goto LABEL_6;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1003F240
// Name: public: struct vgui::KeyBindingMap_t __near * vgui::Panel::LookupBindingByKeyCode(enum ButtonCode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingMap_t *__thiscall vgui::Panel::LookupBindingByKeyCode(
        vgui::Panel *this,
        ButtonCode_t code,
        int modifiers)
{
  vgui::Panel *v3; // esi
  vgui::PanelKeyBindingMap *v4; // ebx
  int m_Size; // edi
  vgui::BoundKey_t *v6; // eax
  vgui::PanelKeyBindingMap *v7; // eax
  int v8; // ebx
  int v9; // edi
  const char **p_bindingname; // esi
  int c; // [esp+Ch] [ebp-20h]
  int v14; // [esp+14h] [ebp-18h]
  char *s2; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  vgui::PanelKeyBindingMap *map; // [esp+20h] [ebp-Ch]
  int v18; // [esp+24h] [ebp-8h]
  vgui::PanelKeyBindingMap *baseMap; // [esp+28h] [ebp-4h]

  v3 = this;
  map = (vgui::PanelKeyBindingMap *)((int (__fastcall *)(vgui::Panel *))this->GetKBMap)(a1: this);
  if ( map == nullptr )
    return nullptr;
  while ( 1 )
  {
    v4 = map;
    m_Size = map->boundkeys.m_Size;
    c = m_Size;
    i = 0;
    if ( m_Size > 0 )
      break;
LABEL_17:
    map = v4->baseMap;
    if ( map == nullptr )
      return nullptr;
  }
  v18 = 0;
  while ( 1 )
  {
    v6 = &v4->boundkeys.m_Memory.m_pMemory[v18];
    if ( v6->keycode == code && v6->modifiers == modifiers )
    {
      s2 = (char *)v6->bindingname;
      v7 = v3->GetKBMap(this: v3);
      baseMap = v7;
      if ( v7 != nullptr )
        break;
    }
LABEL_16:
    ++v18;
    if ( ++i >= m_Size )
      goto LABEL_17;
  }
  while ( 1 )
  {
    v8 = 0;
    v14 = v7->entries.m_Size;
    if ( v14 > 0 )
      break;
LABEL_14:
    baseMap = v7->baseMap;
    if ( baseMap == nullptr )
    {
      m_Size = c;
      v4 = map;
      goto LABEL_16;
    }
    v7 = v7->baseMap;
  }
  v9 = 0;
  while ( 1 )
  {
    p_bindingname = &v7->entries.m_Memory.m_pMemory[v9].bindingname;
    if ( _V_stricmp(s1: *p_bindingname, s2) == 0 )
      return (vgui::KeyBindingMap_t *)p_bindingname;
    v7 = baseMap;
    ++v8;
    ++v9;
    if ( v8 >= v14 )
    {
      v3 = this;
      goto LABEL_14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040640
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateUp(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateUp(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavUp(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_UP;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10040680
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateDown(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateDown(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavDown(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_DOWN;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100406C0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateLeft(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateLeft(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavLeft(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_LEFT;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10040700
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateRight(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateRight(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavRight(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_RIGHT;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10045BB0
// Name: private: class vgui::Panel __near * vgui::Panel::FindDropTargetPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindDropTargetPanel(vgui::Panel *this)
{
  unsigned int v1; // ebx
  vgui::IPanel *v2; // edi
  vgui::IPanel_vtbl *v3; // esi
  const char *ControlsModuleName; // eax
  unsigned int v5; // ebx
  vgui::IPanel *v6; // edi
  vgui::IPanel_vtbl *v7; // esi
  const char *v8; // eax
  vgui::Panel *v9; // eax
  int v10; // ebx
  int v11; // edi
  int m_Size; // eax
  unsigned int v13; // eax
  unsigned int v14; // esi
  int v15; // eax
  vgui::IPanel *v17; // edi
  vgui::IPanel_vtbl *v18; // esi
  unsigned int *v19; // ebx
  const char *v20; // eax
  int v21; // esi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > hits; // [esp+Ch] [ebp-24h] BYREF
  int nCount; // [esp+20h] [ebp-10h]
  vgui::Panel *v24; // [esp+24h] [ebp-Ch]
  int x; // [esp+28h] [ebp-8h] BYREF
  int y; // [esp+2Ch] [ebp-4h] BYREF

  v24 = this;
  if ( s_DragDropHelper.m_iPanelID == -1 )
    return nullptr;
  v1 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID);
  if ( v1 == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  if ( v3->GetPanel(this: v2, a2: v1, a3: ControlsModuleName) == nullptr )
    return nullptr;
  memset(&hits, 0, sizeof(hits));
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  nCount = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  if ( s_DragDropHelper.m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID)) == 0 )
  {
    v9 = nullptr;
  }
  else
  {
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    v8 = vgui::GetControlsModuleName();
    v9 = v7->GetPanel(this: v6, a2: v5, a3: v8);
  }
  v10 = v9->GetVPanel(this: v9);
  if ( g_pVGuiSurface->IsCursorVisible(this: g_pVGuiSurface)
    && g_pVGuiSurface->IsWithin(this: g_pVGuiSurface, a2: x, a3: y) )
  {
    v11 = g_pVGuiSurface->GetPopupCount(this: g_pVGuiSurface) - 1;
    if ( v11 >= 0 )
    {
      do
      {
        m_Size = hits.m_Size;
        if ( hits.m_Size != 0 )
          goto LABEL_20;
        v13 = g_pVGuiSurface->GetPopup(this: g_pVGuiSurface, a2: v11);
        v14 = v13;
        if ( v13 != nCount && v13 != v10 && g_pVGuiPanel->IsFullyVisible(this: g_pVGuiPanel, a2: v13) )
          vgui::Panel::FindDropTargetPanel_R(this: v24, panelList: &hits, x, y, check: v14);
      }
      while ( --v11 >= 0 );
    }
    m_Size = hits.m_Size;
    if ( hits.m_Size != 0 )
      goto LABEL_20;
    vgui::Panel::FindDropTargetPanel_R(this: v24, panelList: &hits, x, y, check: nCount);
  }
  m_Size = hits.m_Size;
  if ( hits.m_Size == 0 )
  {
LABEL_21:
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits);
    return nullptr;
  }
LABEL_20:
  v15 = m_Size - 1;
  nCount = v15;
  if ( v15 < 0 )
    goto LABEL_21;
  while ( 1 )
  {
    v17 = g_pVGuiPanel;
    v18 = g_pVGuiPanel->__vftable;
    v19 = &hits.m_Memory.m_pMemory[v15];
    v20 = v24->GetModuleName(this: v24);
    v21 = (int)v18->GetPanel(this: v17, a2: *v19, a3: v20);
    if ( v21 != 0 )
      break;
    if ( --nCount < 0 )
    {
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits);
      return nullptr;
    }
    v15 = nCount;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits);
  return (vgui::Panel *)v21;
}

//------------------------------------------------------------------------------
// Address: 0x100B2ED0
// Name: _dynamic_initializer_for__CMainPanel::m_MessageMap__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CMainPanel::m_MessageMap__()
{
  *(_QWORD *)&CMainPanel::m_MessageMap[0].func = (unsigned int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
  *((_QWORD *)&CMainPanel::m_MessageMap[0].func + 1) = 0;
  *(_QWORD *)&CMainPanel::m_MessageMap[0].firstParamType = 0;
  *(_QWORD *)&CMainPanel::m_MessageMap[0].secondParamType = 0;
  *(_QWORD *)&CMainPanel::m_MessageMap[0].nameSymbol = 0;
  CMainPanel::m_MessageMap[0].secondParamSymbol = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B2F30
// Name: _dynamic_initializer_for__g_ButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Button *dynamic_initializer_for__g_ButtonPullInModule__()
{
  g_ButtonPullInModule = g_ButtonLinkerHack;
  return g_ButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B2F40
// Name: _dynamic_initializer_for__g_EditablePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::EditablePanel *dynamic_initializer_for__g_EditablePanelPullInModule__()
{
  g_EditablePanelPullInModule = g_EditablePanelLinkerHack;
  return g_EditablePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B2F50
// Name: _dynamic_initializer_for__g_ImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ImagePanel *dynamic_initializer_for__g_ImagePanelPullInModule__()
{
  g_ImagePanelPullInModule = g_ImagePanelLinkerHack;
  return g_ImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B2F60
// Name: _dynamic_initializer_for__g_LabelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Label *dynamic_initializer_for__g_LabelPullInModule__()
{
  g_LabelPullInModule = g_LabelLinkerHack;
  return g_LabelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B2F70
// Name: _dynamic_initializer_for__g_PanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Panel *dynamic_initializer_for__g_PanelPullInModule__()
{
  g_PanelPullInModule = g_PanelLinkerHack;
  return g_PanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B2F80
// Name: _dynamic_initializer_for__g_ToggleButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ToggleButton *dynamic_initializer_for__g_ToggleButtonPullInModule__()
{
  g_ToggleButtonPullInModule = g_ToggleButtonLinkerHack;
  return g_ToggleButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B2F90
// Name: _dynamic_initializer_for__g_AnimatingImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::AnimatingImagePanel *dynamic_initializer_for__g_AnimatingImagePanelPullInModule__()
{
  g_AnimatingImagePanelPullInModule = g_AnimatingImagePanelLinkerHack;
  return g_AnimatingImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B2FA0
// Name: _dynamic_initializer_for__g_CBitmapImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBitmapImagePanel *dynamic_initializer_for__g_CBitmapImagePanelPullInModule__()
{
  g_CBitmapImagePanelPullInModule = g_CBitmapImagePanelLinkerHack;
  return g_CBitmapImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B2FB0
// Name: _dynamic_initializer_for__g_CheckButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CheckButton *dynamic_initializer_for__g_CheckButtonPullInModule__()
{
  g_CheckButtonPullInModule = g_CheckButtonLinkerHack;
  return g_CheckButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B2FC0
// Name: _dynamic_initializer_for__g_ComboBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ComboBox *dynamic_initializer_for__g_ComboBoxPullInModule__()
{
  g_ComboBoxPullInModule = g_ComboBoxLinkerHack;
  return g_ComboBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B2FD0
// Name: _dynamic_initializer_for__g_CvarToggleCheckButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CvarToggleCheckButton<ConVarRef> *dynamic_initializer_for__g_CvarToggleCheckButtonPullInModule__()
{
  g_CvarToggleCheckButtonPullInModule = g_CvarToggleCheckButtonLinkerHack;
  return g_CvarToggleCheckButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B2FE0
// Name: _dynamic_initializer_for__g_DividerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Divider *dynamic_initializer_for__g_DividerPullInModule__()
{
  g_DividerPullInModule = g_DividerLinkerHack;
  return g_DividerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B2FF0
// Name: _dynamic_initializer_for__g_ExpandButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ExpandButton *dynamic_initializer_for__g_ExpandButtonPullInModule__()
{
  g_ExpandButtonPullInModule = g_ExpandButtonLinkerHack;
  return g_ExpandButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B3000
// Name: _dynamic_initializer_for__g_GraphPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::GraphPanel *dynamic_initializer_for__g_GraphPanelPullInModule__()
{
  g_GraphPanelPullInModule = g_GraphPanelLinkerHack;
  return g_GraphPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B3010
// Name: _dynamic_initializer_for__g_ListPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ListPanel *dynamic_initializer_for__g_ListPanelPullInModule__()
{
  g_ListPanelPullInModule = g_ListPanelLinkerHack;
  return g_ListPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B3020
// Name: _dynamic_initializer_for__g_ListViewPanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ListViewPanel *dynamic_initializer_for__g_ListViewPanelPullInModule__()
{
  g_ListViewPanelPullInModule = g_ListViewPanelLinkerHack;
  return g_ListViewPanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B3030
// Name: _dynamic_initializer_for__g_MenuPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::Menu *dynamic_initializer_for__g_MenuPullInModule__()
{
  g_MenuPullInModule = g_MenuLinkerHack;
  return g_MenuLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B3040
// Name: _dynamic_initializer_for__g_MenuBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuBar *dynamic_initializer_for__g_MenuBarPullInModule__()
{
  g_MenuBarPullInModule = g_MenuBarLinkerHack;
  return g_MenuBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B3050
// Name: _dynamic_initializer_for__g_MenuButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuButton *dynamic_initializer_for__g_MenuButtonPullInModule__()
{
  g_MenuButtonPullInModule = g_MenuButtonLinkerHack;
  return g_MenuButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B3060
// Name: _dynamic_initializer_for__g_MenuItemPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MenuItem *dynamic_initializer_for__g_MenuItemPullInModule__()
{
  g_MenuItemPullInModule = g_MenuItemLinkerHack;
  return g_MenuItemLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B3070
// Name: _dynamic_initializer_for__g_MessageBoxPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::MessageBox *dynamic_initializer_for__g_MessageBoxPullInModule__()
{
  g_MessageBoxPullInModule = g_MessageBoxLinkerHack;
  return g_MessageBoxLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B3080
// Name: _dynamic_initializer_for__g_ProgressBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ProgressBar *dynamic_initializer_for__g_ProgressBarPullInModule__()
{
  g_ProgressBarPullInModule = g_ProgressBarLinkerHack;
  return g_ProgressBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B3090
// Name: _dynamic_initializer_for__g_CircularProgressBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CircularProgressBar *dynamic_initializer_for__g_CircularProgressBarPullInModule__()
{
  g_CircularProgressBarPullInModule = g_CircularProgressBarLinkerHack;
  return g_CircularProgressBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B30A0
// Name: _dynamic_initializer_for__g_RadioButtonPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::RadioButton *dynamic_initializer_for__g_RadioButtonPullInModule__()
{
  g_RadioButtonPullInModule = g_RadioButtonLinkerHack;
  return g_RadioButtonLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B30B0
// Name: _dynamic_initializer_for__g_RichTextPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::RichText *dynamic_initializer_for__g_RichTextPullInModule__()
{
  g_RichTextPullInModule = g_RichTextLinkerHack;
  return g_RichTextLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B30C0
// Name: _dynamic_initializer_for__g_ScalableImagePanelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScalableImagePanel *dynamic_initializer_for__g_ScalableImagePanelPullInModule__()
{
  g_ScalableImagePanelPullInModule = g_ScalableImagePanelLinkerHack;
  return g_ScalableImagePanelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B30D0
// Name: _dynamic_initializer_for__g_ScrollBar_VerticalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBar_VerticalPullInModule__()
{
  g_ScrollBar_VerticalPullInModule = g_ScrollBar_VerticalLinkerHack;
  return g_ScrollBar_VerticalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B30E0
// Name: _dynamic_initializer_for__g_ScrollBar_HorizontalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBar_HorizontalPullInModule__()
{
  g_ScrollBar_HorizontalPullInModule = g_ScrollBar_HorizontalLinkerHack;
  return g_ScrollBar_HorizontalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B30F0
// Name: _dynamic_initializer_for__g_ScrollBarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::ScrollBar *dynamic_initializer_for__g_ScrollBarPullInModule__()
{
  g_ScrollBarPullInModule = g_ScrollBarLinkerHack;
  return g_ScrollBarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B3100
// Name: _dynamic_initializer_for__g_TextEntryPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::TextEntry *dynamic_initializer_for__g_TextEntryPullInModule__()
{
  g_TextEntryPullInModule = g_TextEntryLinkerHack;
  return g_TextEntryLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B3110
// Name: _dynamic_initializer_for__g_TreeViewPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::TreeView *dynamic_initializer_for__g_TreeViewPullInModule__()
{
  g_TreeViewPullInModule = g_TreeViewLinkerHack;
  return g_TreeViewLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B3120
// Name: _dynamic_initializer_for__g_CTreeViewListControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CTreeViewListControl *dynamic_initializer_for__g_CTreeViewListControlPullInModule__()
{
  g_CTreeViewListControlPullInModule = g_CTreeViewListControlLinkerHack;
  return g_CTreeViewListControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B3130
// Name: _dynamic_initializer_for__g_URLLabelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::URLLabel *dynamic_initializer_for__g_URLLabelPullInModule__()
{
  g_URLLabelPullInModule = g_URLLabelLinkerHack;
  return g_URLLabelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x100B3140
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x100B3160
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B3170
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x100B3190
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x100B31A0
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B3200
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B3230
// Name: _dynamic_initializer_for__g_ComboBox_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_ComboBox_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_ComboBox_Helper,
           className: "ComboBox",
           func: ComboBox_Factory);
}
