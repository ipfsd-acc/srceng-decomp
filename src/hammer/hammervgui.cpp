// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/hammervgui.cpp
// Functions: 55
// ============================================================

#include "hammer\hammervgui.h"

//------------------------------------------------------------------------------
// Address: 0x10045A20
// Name: class CHammerVGui __near * HammerVGui(void)
// Source: json
//------------------------------------------------------------------------------
CHammerVGui *__cdecl HammerVGui()
{
  return &s_HammerVGui;
}

//------------------------------------------------------------------------------
// Address: 0x10045A30
// Name: public: static char const __near * vgui::Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Panel::GetPanelClassName()
{
  return "Panel";
}

//------------------------------------------------------------------------------
// Address: 0x10045A50
// Name: public: virtual unsigned long vgui::Panel::GetDragFailCursor(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::Panel::GetDragFailCursor(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  return 13;
}

//------------------------------------------------------------------------------
// Address: 0x10045A60
// Name: public: bool CHammerVGui::HasFocus(class CVGuiWnd __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHammerVGui::HasFocus(CHammerVGui *this, CVGuiWnd *pWnd)
{
  return this->m_pActiveWindow == pWnd;
}

//------------------------------------------------------------------------------
// Address: 0x10045A80
// Name: public: void CHammerVGui::Simulate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammerVGui::Simulate(CHammerVGui *this)
{
  vgui::AnimationController *AnimationController; // eax
  float v2; // [esp-4h] [ebp-4h]

  if ( this->m_hMainWindow != nullptr )
  {
    g_pInputSystem->PollInputState(this: g_pInputSystem);
    g_pVGui->RunFrame(this: g_pVGui);
    v2 = g_pVGuiSystem->GetCurrentTime(this: g_pVGuiSystem);
    AnimationController = vgui::GetAnimationController();
    vgui::AnimationController::UpdateAnimations(this: AnimationController, currentTime: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045AC0
// Name: public: void CHammerVGui::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammerVGui::Shutdown(CHammerVGui *this)
{
  vgui::Panel *m_pDummyPopup; // ecx

  if ( this->m_hMainWindow != nullptr )
  {
    m_pDummyPopup = this->m_pDummyPopup;
    if ( m_pDummyPopup != nullptr )
    {
      ((void (__thiscall *)(vgui::Panel *, int))m_pDummyPopup->dtr_Panel)(a1: m_pDummyPopup, a2: 1);
      this->m_pDummyPopup = nullptr;
    }
    if ( this->m_hVguiInputContext != nullptr )
    {
      g_pMatSystemSurface->SetInputContext(this: g_pMatSystemSurface, a2: nullptr);
      g_pInputStackSystem->PopInputContext(this: g_pInputStackSystem);
      this->m_hVguiInputContext = nullptr;
    }
    g_pInputSystem->PollInputState(this: g_pInputSystem);
    g_pVGui->RunFrame(this: g_pVGui);
    g_pVGui->Stop(this: g_pVGui);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10045B40
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Panel::GetMessageMap(vgui::Panel *this)
{
  if ( (`vgui::Panel::GetMessageMap'::`2'::`local static guard' & 1) == 0 )
  {
    `vgui::Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
    `vgui::Panel::GetMessageMap'::`2'::s_pMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  return `vgui::Panel::GetMessageMap'::`2'::s_pMap;
}

//------------------------------------------------------------------------------
// Address: 0x10045BB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::GetKBMap(vgui::Panel *this)
{
  if ( (`vgui::Panel::GetKBMap'::`2'::`local static guard' & 1) == 0 )
  {
    `vgui::Panel::GetKBMap'::`2'::`local static guard' |= 1u;
    `vgui::Panel::GetKBMap'::`2'::s_pMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  return `vgui::Panel::GetKBMap'::`2'::s_pMap;
}

//------------------------------------------------------------------------------
// Address: 0x10045C10
// Name: public: virtual bool vgui::Panel::IsProportional(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::Panel::IsProportional(vgui::Panel *this)
{
  return (this->_flags.m_nFlags & 0x1000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10045C20
// Name: public: bool CHammerVGui::Init(struct HWND__ __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHammerVGui::Init(CHammerVGui *this, HWND__ *hWindow)
{
  InputContextHandle_t__ *v4; // eax
  unsigned int v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // edi
  vgui::Panel *v8; // ecx

  this->m_hMainWindow = hWindow;
  if ( LOBYTE(AfxGetModuleState()->m_pCurrentWinApp[4].m_dwRef) == 0 )
  {
    if ( !vgui::VGui_InitInterfacesList(moduleName: "HAMMER", factoryList: &g_Factory, numFactories: 1)
      || !vgui::VGui_InitMatSysInterfacesList(moduleName: "HAMMER", factoryList: &g_Factory, numFactories: 1)
      || g_pMatSystemSurface == nullptr )
    {
      return 0;
    }
    g_pVGuiSystem->SetUserConfigFile(this: g_pVGuiSystem, a2: "hammer.vdf", a3: "EXECUTABLE_PATH");
    g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: true);
  }
  v4 = g_pInputStackSystem->PushInputContext(this: g_pInputStackSystem);
  this->m_hVguiInputContext = v4;
  g_pMatSystemSurface->SetInputContext(this: g_pMatSystemSurface, a2: v4);
  v5 = g_pVGuiSchemeManager->LoadSchemeFromFile(
         this: g_pVGuiSchemeManager,
         a2: "//PLATFORM/Resource/SourceScheme.res",
         a3: "Hammer");
  this->m_hHammerScheme = v5;
  if ( v5 == 0 )
    return 0;
  if ( LOBYTE(AfxGetModuleState()->m_pCurrentWinApp[4].m_dwRef) == 0 )
  {
    g_pVGui->Start(this: g_pVGui);
    g_pVGui->SetSleep(this: g_pVGui, a2: false);
    v6 = (vgui::Panel *)operator new(nSize: 0x14Cu);
    v7 = v6;
    if ( v6 != nullptr )
    {
      vgui::Panel::Panel(this: v6);
      v7->__vftable = (vgui::Panel_vtbl *)&CDummyPopupPanel::`vftable';
      v8 = v7;
    }
    else
    {
      v8 = nullptr;
    }
    this->m_pDummyPopup = v8;
    vgui::Panel::MakePopup(this: v8, showTaskbarIcon: false, disabled: true);
    this->m_pDummyPopup->SetVisible(this: this->m_pDummyPopup, a2: true);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10045E00
// Name: public: void CHammerVGui::SetFocus(class CVGuiWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHammerVGui::SetFocus(CHammerVGui *this, CVGuiWnd *pVGuiWnd)
{
  const char *Text; // eax
  const char *v4; // eax
  CMapClass *ParentWnd; // eax
  vgui::IVGui *v6; // edi
  vgui::IVGui_vtbl *v7; // ebx
  int Wide; // eax
  HWND v9; // eax
  IEngineTool *v10; // ecx
  HWND v11; // eax
  IInputSystem_vtbl *v12; // esi
  int v13; // eax

  if ( pVGuiWnd != this->m_pActiveWindow )
  {
    g_pInputSystem->PollInputState(this: g_pInputSystem);
    g_pVGui->RunFrame(this: g_pVGui);
    g_pMatSystemSurface->SetAppDrivesInput(this: g_pMatSystemSurface, a2: true);
    g_pInputSystem->DetachFromWindow(this: g_pInputSystem);
    if ( this->m_pActiveWindow != nullptr
      && vgui::Tooltip::GetText(this: (vgui::Tooltip *)this->m_pActiveWindow) != nullptr )
    {
      Text = vgui::Tooltip::GetText(this: (vgui::Tooltip *)this->m_pActiveWindow);
      (*(void (__thiscall **)(const char *, _DWORD))(*(_DWORD *)Text + 540))(a1: Text, a2: 0);
    }
    if ( pVGuiWnd != nullptr )
    {
      this->m_pActiveWindow = pVGuiWnd;
      this->m_bCurrentDialogIsModal = pVGuiWnd->IsModal(this: pVGuiWnd);
      if ( vgui::Tooltip::GetText(this: (vgui::Tooltip *)pVGuiWnd) != nullptr )
      {
        v4 = vgui::Tooltip::GetText(this: (vgui::Tooltip *)pVGuiWnd);
        (*(void (__thiscall **)(const char *, int))(*(_DWORD *)v4 + 540))(a1: v4, a2: 1);
      }
      ParentWnd = CVGuiWnd::GetParentWnd(this: (CMapClass *)pVGuiWnd);
      if ( ParentWnd != nullptr )
        ParentWnd = (CMapClass *)ParentWnd->m_References.m_pHead;
      g_pInputSystem->AttachToWindow(this: g_pInputSystem, a2: ParentWnd);
      ((void (__stdcall *)(bool))g_pMatSystemSurface->SetAppDrivesInput)(a1: !this->m_bCurrentDialogIsModal);
      v6 = g_pVGui;
      v7 = g_pVGui->__vftable;
      Wide = vgui::Image::GetWide(this: (vgui::Image *)pVGuiWnd);
      v7->ActivateContext(this: v6, a2: Wide);
      if ( pVGuiWnd->IsModal(this: pVGuiWnd) != 0 && enginetools != nullptr )
      {
        v9 = (HWND)enginetools->GetEngineHwnd(this: enginetools);
        EnableWindow(hWnd: v9, bEnable: false);
      }
    }
    else
    {
      v10 = enginetools;
      if ( enginetools != nullptr )
      {
        if ( this->m_bCurrentDialogIsModal )
        {
          v11 = (HWND)((int (*)(void))enginetools->GetEngineHwnd)();
          EnableWindow(hWnd: v11, bEnable: true);
          v10 = enginetools;
        }
        v12 = g_pInputSystem->__vftable;
        v13 = (int)v10->GetEngineHwnd(this: v10);
        v12->AttachToWindow(this: g_pInputSystem, a2: (void *)v13);
        g_pMatSystemSurface->SetAppDrivesInput(this: g_pMatSystemSurface, a2: true);
      }
      this->m_pActiveWindow = nullptr;
      g_pVGui->ActivateContext(this: g_pVGui, a2: -1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4920
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
// Address: 0x102C4CB0
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
// Address: 0x102C5370
// Name: public: virtual enum vgui::KeyBindingContextHandle_t vgui::Panel::GetKeyBindingsContext(void)const
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t __thiscall vgui::Panel::GetKeyBindingsContext(vgui::Panel *this)
{
  return this->m_hKeyBindingsContext;
}

//------------------------------------------------------------------------------
// Address: 0x102C5940
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
// Address: 0x102C5DF0
// Name: public: class vgui::CSizerBase __near * vgui::Panel::GetSizer(void)
// Source: json
//------------------------------------------------------------------------------
vgui::CSizerBase *__thiscall vgui::Panel::GetSizer(vgui::Panel *this)
{
  return this->m_pSizer;
}

//------------------------------------------------------------------------------
// Address: 0x102C61A0
// Name: public: enum vgui::Panel::PinCorner_e vgui::Panel::GetPinCorner(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetPinCorner(vgui::Panel *this)
{
  return *((_BYTE *)this + 166) & 0xF;
}

//------------------------------------------------------------------------------
// Address: 0x102C61D0
// Name: public: enum vgui::Panel::AutoResize_e vgui::Panel::GetAutoResize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetAutoResize(vgui::Panel *this)
{
  return *((unsigned __int8 *)this + 166) >> 4;
}

//------------------------------------------------------------------------------
// Address: 0x102C6650
// Name: public: virtual struct vgui::PanelMap_t __near * vgui::Panel::GetPanelMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMap_t *__thiscall vgui::Panel::GetPanelMap(vgui::Panel *this)
{
  return &vgui::Panel::m_PanelMap;
}

//------------------------------------------------------------------------------
// Address: 0x102C7EF0
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
// Address: 0x102C7F60
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
// Address: 0x102C7FB0
// Name: public: virtual struct vgui::DragDrop_t __near * vgui::Panel::GetDragDropInfo(void)
// Source: json
//------------------------------------------------------------------------------
vgui::DragDrop_t *__thiscall vgui::Panel::GetDragDropInfo(vgui::Panel *this)
{
  return this->m_pDragDrop;
}

//------------------------------------------------------------------------------
// Address: 0x102C8CE0
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
// Address: 0x102C9E40
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
// Address: 0x102CA630
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavUp(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavUp(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::DHANDLE<vgui::Menu> *p_m_NavUp; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Menu *ChildByName; // eax
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
  vgui::DHANDLE<vgui::Menu> *v22; // ebx
  unsigned int v23; // edi
  vgui::IPanel *v24; // esi
  vgui::IPanel_vtbl *v25; // ebx
  const char *v26; // eax
  vgui::Panel *v27; // eax
  vgui::Menu *v28; // eax
  vgui::Panel *v29; // eax
  const char *v31; // [esp-8h] [ebp-20h]
  vgui::DHANDLE<vgui::Menu> *v33; // [esp+10h] [ebp-8h]
  vgui::Panel *v34; // [esp+14h] [ebp-4h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavUp.m_iPanelID;
  p_m_NavUp = (vgui::DHANDLE<vgui::Menu> *)&this->m_NavUp;
  v33 = (vgui::DHANDLE<vgui::Menu> *)&this->m_NavUp;
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
      ChildByName = (vgui::Menu *)vgui::Panel::FindChildByName(this: v9, childName: v31, recurseDown: true);
      if ( ChildByName != nullptr )
        vgui::DHANDLE<vgui::Menu>::operator=(this: p_m_NavUp, pPanel: ChildByName);
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
  v22 = (vgui::DHANDLE<vgui::Menu> *)&this->m_NavUp;
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
    v22 = (vgui::DHANDLE<vgui::Menu> *)&this->m_NavUp;
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
// Address: 0x102CA7F0
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavDown(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavDown(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::DHANDLE<vgui::Menu> *p_m_NavDown; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Menu *v11; // eax
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
  vgui::DHANDLE<vgui::Menu> *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Menu *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::DHANDLE<vgui::Menu> *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavDown.m_iPanelID;
  p_m_NavDown = (vgui::DHANDLE<vgui::Menu> *)&this->m_NavDown;
  v34 = (vgui::DHANDLE<vgui::Menu> *)&this->m_NavDown;
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
        v11 = (vgui::Menu *)ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<vgui::Menu>::operator=(this: p_m_NavDown, pPanel: v11);
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
  v23 = (vgui::DHANDLE<vgui::Menu> *)&this->m_NavDown;
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
    v23 = (vgui::DHANDLE<vgui::Menu> *)&this->m_NavDown;
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
// Address: 0x102CA9C0
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavLeft(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavLeft(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::DHANDLE<vgui::Menu> *p_m_NavLeft; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Menu *v11; // eax
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
  vgui::DHANDLE<vgui::Menu> *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Menu *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::DHANDLE<vgui::Menu> *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavLeft.m_iPanelID;
  p_m_NavLeft = (vgui::DHANDLE<vgui::Menu> *)&this->m_NavLeft;
  v34 = (vgui::DHANDLE<vgui::Menu> *)&this->m_NavLeft;
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
        v11 = (vgui::Menu *)ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<vgui::Menu>::operator=(this: p_m_NavLeft, pPanel: v11);
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
  v23 = (vgui::DHANDLE<vgui::Menu> *)&this->m_NavLeft;
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
    v23 = (vgui::DHANDLE<vgui::Menu> *)&this->m_NavLeft;
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
// Address: 0x102CAB90
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavRight(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavRight(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::DHANDLE<vgui::Menu> *p_m_NavRight; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Menu *v11; // eax
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
  vgui::DHANDLE<vgui::Menu> *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Menu *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::DHANDLE<vgui::Menu> *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavRight.m_iPanelID;
  p_m_NavRight = (vgui::DHANDLE<vgui::Menu> *)&this->m_NavRight;
  v34 = (vgui::DHANDLE<vgui::Menu> *)&this->m_NavRight;
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
        v11 = (vgui::Menu *)ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<vgui::Menu>::operator=(this: p_m_NavRight, pPanel: v11);
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
  v23 = (vgui::DHANDLE<vgui::Menu> *)&this->m_NavRight;
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
    v23 = (vgui::DHANDLE<vgui::Menu> *)&this->m_NavRight;
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
// Address: 0x102CB3F0
// Name: public: struct vgui::KeyBindingMap_t __near * vgui::Panel::LookupBinding(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::LookupBinding(vgui::Panel *this, const char *bindingName)
{
  vgui::PanelKeyBindingMap *result; // eax
  int v3; // ebx
  int v4; // edi
  const char **p_bindingname; // esi
  int c; // [esp+Ch] [ebp-8h]
  vgui::KeyBindingMap_t *map; // [esp+10h] [ebp-4h]

  result = this->GetKBMap(this);
  map = (vgui::KeyBindingMap_t *)result;
  if ( result != nullptr )
  {
    while ( 1 )
    {
      v3 = 0;
      c = result->entries.m_Size;
      if ( c > 0 )
        break;
LABEL_6:
      result = result->baseMap;
      map = (vgui::KeyBindingMap_t *)result;
      if ( result == nullptr )
        return result;
    }
    v4 = 0;
    while ( 1 )
    {
      p_bindingname = &result->entries.m_Memory.m_pMemory[v4].bindingname;
      if ( _V_stricmp(s1: *p_bindingname, s2: bindingName) == 0 )
        return (vgui::PanelKeyBindingMap *)p_bindingname;
      result = (vgui::PanelKeyBindingMap *)map;
      ++v3;
      ++v4;
      if ( v3 >= c )
        goto LABEL_6;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CB470
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
// Address: 0x102CB4D0
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
// Address: 0x102CB5D0
// Name: public: struct vgui::BoundKey_t __near * vgui::Panel::LookupDefaultKey(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::LookupDefaultKey(vgui::Panel *this, const char *bindingName)
{
  vgui::PanelKeyBindingMap *result; // eax
  int v3; // ebx
  int v4; // edi
  int m_pMemory; // esi
  const char *v6; // ecx
  int v7; // esi
  int c; // [esp+Ch] [ebp-8h]
  vgui::BoundKey_t *map; // [esp+10h] [ebp-4h]

  result = this->GetKBMap(this);
  map = (vgui::BoundKey_t *)result;
  if ( result != nullptr )
  {
    while ( 1 )
    {
      v3 = 0;
      c = result->defaultkeys.m_Size;
      if ( c > 0 )
        break;
LABEL_6:
      result = result->baseMap;
      map = (vgui::BoundKey_t *)result;
      if ( result == nullptr )
        return result;
    }
    v4 = 0;
    while ( 1 )
    {
      m_pMemory = (int)result->defaultkeys.m_Memory.m_pMemory;
      v6 = *(const char **)(m_pMemory + v4 + 4);
      v7 = v4 + m_pMemory;
      if ( _V_stricmp(s1: v6, s2: bindingName) == 0 )
        return (vgui::PanelKeyBindingMap *)v7;
      result = (vgui::PanelKeyBindingMap *)map;
      ++v3;
      v4 += 16;
      if ( v3 >= c )
        goto LABEL_6;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CCCE0
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
// Address: 0x102CCD20
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
// Address: 0x102CCD60
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
// Address: 0x102CCDA0
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
// Address: 0x102D13A0
// Name: public: static class vgui::Panel __near * vgui::Panel::GetPanelWithKeyBindings(enum vgui::KeyBindingContextHandle_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__cdecl vgui::Panel::GetPanelWithKeyBindings(vgui::KeyBindingContextHandle_t handle, int index)
{
  int v2; // eax
  CKeyBindingsMgr::KBContext_t *p_m_Data; // esi
  CKeyBindingsMgr::KBContext_t search; // [esp+8h] [ebp-1Ch] BYREF

  *(_DWORD *)&search.m_KeyBindingsFile.m_Id = -1;
  memset(&search.m_Panels, 0, sizeof(search.m_Panels));
  search.m_Handle = handle;
  v2 = CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::Find(
         this: &g_KBMgr.m_Bindings,
         &search);
  if ( v2 == -1 )
  {
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&search.m_Panels);
    return nullptr;
  }
  p_m_Data = &g_KBMgr.m_Bindings.m_Elements.m_pMemory[v2].m_Data;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&search.m_Panels);
  if ( p_m_Data == nullptr )
    return nullptr;
  return p_m_Data->m_Panels.m_Memory.m_pMemory[index];
}

//------------------------------------------------------------------------------
// Address: 0x102D3520
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
// Address: 0x102D47B0
// Name: public: static enum vgui::KeyBindingContextHandle_t vgui::Panel::CreateKeyBindingsContext(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t __cdecl vgui::Panel::CreateKeyBindingsContext(const char *filename, const char *pathID)
{
  return CKeyBindingsMgr::CreateContext(this: &g_KBMgr, filename, pathID);
}

//------------------------------------------------------------------------------
// Address: 0x10347196
// Name: public: virtual long CDocument::XPreviewHandler::SetFocus(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XPreviewHandler::SetFocus(CDocument::XPreviewHandler *this)
{
  int v1; // eax
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 42));
  v1 = *((_DWORD *)this - 21);
  if ( v1 != 0 && IsWindow(hWnd: *(HWND *)(v1 + 32)) )
    CWnd::SetFocus(this: *((CWnd **)this - 21));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103DEB01
// Name: public: class CMFCRibbonPanel __near * CMFCRibbonCategory::GetPanel(int)
// Source: json
//------------------------------------------------------------------------------
CMFCRibbonPanel *__thiscall CMFCRibbonCategory::GetPanel(CMFCRibbonCategory *this, int nIndex)
{
  if ( nIndex < 0 || nIndex >= this->m_arPanels.m_nSize )
    AfxThrowInvalidArgException();
  return this->m_arPanels.m_pData[nIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10463720
// Name: public: virtual bool vgui::Panel::LookupElementBounds(char const __near *,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Panel::LookupElementBounds(
        CParticleOperatorInstance *this,
        int nStartBlock,
        int nNumBlocks,
        CParticleCollection *pParticles,
        CParticleCollection *pContext,
        void *nNumValidParticlesInLastChunk)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x103471DA
// Name: public: virtual long CDocument::XPreviewHandler::QueryFocus(struct HWND__ __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XPreviewHandler::QueryFocus(CDocument::XPreviewHandler *this, HWND__ **phwnd)
{
  int v2; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 42));
  v2 = (*(int (__thiscall **)(CDocument::XPreviewHandler *, HWND__ **))(*((_DWORD *)this - 49) + 252))(
         a1: this - 49,
         a2: phwnd);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10347219
// Name: public: virtual long CDocument::XPreviewHandler::TranslateAcceleratorA(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XPreviewHandler::TranslateAcceleratorA(CDocument::XPreviewHandler *this, tagMSG *pmsg)
{
  int v2; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 42));
  v2 = (*(int (__thiscall **)(CDocument::XPreviewHandler *, tagMSG *))(*((_DWORD *)this - 49) + 256))(
         a1: this - 49,
         a2: pmsg);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10347258
// Name: public: virtual unsigned long CDocument::XPreviewHandlerVisuals::AddRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall CDocument::XPreviewHandlerVisuals::AddRef(CDocument::XPreviewHandlerVisuals *this)
{
  LONG v1; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 43));
  v1 = CCmdTarget::ExternalAddRef(this: (CCmdTarget *)(this - 50));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1034728D
// Name: public: virtual unsigned long CDocument::XPreviewHandlerVisuals::Release(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __stdcall CDocument::XPreviewHandlerVisuals::Release(CDocument::XPreviewHandlerVisuals *this)
{
  LONG v1; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 43));
  v1 = CCmdTarget::ExternalRelease(this: (CCmdTarget *)(this - 50));
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x103472C2
// Name: public: virtual long CDocument::XPreviewHandlerVisuals::QueryInterface(struct _GUID const __near &,void __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __stdcall CDocument::XPreviewHandlerVisuals::QueryInterface(
        CDocument::XPreviewHandlerVisuals *this,
        const _GUID *iid,
        void **ppvObj)
{
  int Interface; // esi
  AFX_MAINTAIN_STATE2 _ctlState; // [esp+4h] [ebp-8h] BYREF

  AFX_MAINTAIN_STATE2::AFX_MAINTAIN_STATE2(this: &_ctlState, pNewState: *((AFX_MODULE_STATE **)this - 43));
  Interface = CCmdTarget::ExternalQueryInterface(this: (CCmdTarget *)(this - 50), iid, ppvObj);
  AFX_MAINTAIN_STATE2::~AFX_MAINTAIN_STATE2(this: &_ctlState);
  return Interface;
}

//------------------------------------------------------------------------------
// Address: 0x103DEB28
// Name: public: virtual void CMFCRibbonCategory::ReposPanels(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::ReposPanels(CMFCRibbonCategory *this, CDC *pDC)
{
  int v3; // edi
  int v4; // eax
  CMFCRibbonPanel *v5; // esi
  int v6; // eax
  int m_nCurrWidthIndex; // eax
  int v8; // eax
  int bForceCollpapse; // [esp+Ch] [ebp-30h]
  int rectClient; // [esp+10h] [ebp-2Ch]
  int rectClient_4; // [esp+14h] [ebp-28h]
  int rectClient_8; // [esp+18h] [ebp-24h]
  int rectClient_12; // [esp+1Ch] [ebp-20h]
  int i; // [esp+24h] [ebp-18h]
  CRect rectPanel; // [esp+28h] [ebp-14h] BYREF

  rectClient_8 = this->m_rect.right - 4;
  rectClient = this->m_rect.left + 4;
  rectClient_4 = this->m_rect.top + 3;
  rectClient_12 = this->m_rect.bottom - 4;
  v3 = rectClient - this->m_nScrollOffset;
  v4 = 0;
  i = 0;
  bForceCollpapse = rectClient_8 - rectClient <= this->m_nMinWidth;
  if ( this->m_arPanels.m_nSize > 0 )
  {
    while ( 1 )
    {
      if ( v4 < 0 || v4 >= this->m_arPanels.m_nSize )
        goto LABEL_17;
      v5 = this->m_arPanels.m_pData[v4];
      if ( bForceCollpapse != 0 )
      {
        v6 = v5->m_arWidths.m_nSize - 1;
        v5->m_bForceCollpapse = 1;
        v5->m_nCurrWidthIndex = v6;
      }
      m_nCurrWidthIndex = v5->m_nCurrWidthIndex;
      if ( m_nCurrWidthIndex < 0 || m_nCurrWidthIndex >= v5->m_arWidths.m_nSize )
LABEL_17:
        AfxThrowInvalidArgException();
      v8 = v5->m_arWidths.m_pData[m_nCurrWidthIndex] + 2 * v5->m_nXMargin;
      rectPanel.top = rectClient_4;
      rectPanel.right = v3 + v8;
      rectPanel.left = v3;
      rectPanel.bottom = rectClient_12;
      v5->Reposition(this: v5, a2: pDC, a3: &rectPanel);
      v3 = v5->m_rect.right + 2;
      if ( rectPanel.right <= rectClient + 4 || rectPanel.left >= rectClient_8 - 4 )
      {
        SetRectEmpty(lprc: &rectPanel);
        v5->Reposition(this: v5, a2: pDC, a3: &rectPanel);
      }
      if ( bForceCollpapse != 0 )
        v5->m_bForceCollpapse = 1;
      v5->OnAfterChangeRect(this: v5, a2: pDC);
      if ( ++i >= this->m_arPanels.m_nSize )
        break;
      v4 = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DEC81
// Name: protected: void CMFCRibbonCategory::CleanUpSizes(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::CleanUpSizes(CMFCRibbonCategory *this)
{
  int i; // edi
  CMFCRibbonPanel *v3; // ebx

  for ( i = 0; i < this->m_arPanels.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arPanels.m_nSize )
      AfxThrowInvalidArgException();
    v3 = this->m_arPanels.m_pData[i];
    CMFCRibbonPanel::CleanUpSizes(this: v3);
    CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::SetSize(
      this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)&v3->m_arWidths,
      nNewSize: 0,
      nGrowBy: -1);
  }
  this->m_nLastCategoryWidth = -1;
  this->m_nMinWidth = -1;
}

//------------------------------------------------------------------------------
// Address: 0x103DECDB
// Name: protected: int CMFCRibbonCategory::GetMinWidth(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonCategory::GetMinWidth(CMFCRibbonCategory *this, CDC *pDC)
{
  int v3; // edi
  int i; // ebx
  int MinWidth; // eax

  v3 = 0;
  for ( i = 2; v3 < this->m_arPanels.m_nSize; i += MinWidth + 2 )
  {
    if ( v3 < 0 || v3 >= this->m_arPanels.m_nSize )
      AfxThrowInvalidArgException();
    MinWidth = CMFCRibbonPanel::GetMinWidth(this: this->m_arPanels.m_pData[v3++], pDC);
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x103DED2B
// Name: public: class CMFCRibbonPanel __near * CMFCRibbonCategory::GetPanelFromPoint(class CPoint)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonPanel *__thiscall CMFCRibbonCategory::GetPanelFromPoint(CMFCRibbonCategory *this, CPoint point)
{
  int v3; // edi
  CMFCRibbonPanel *v4; // ebx

  v3 = 0;
  if ( this->m_arPanels.m_nSize <= 0 )
    return nullptr;
  while ( 1 )
  {
    if ( v3 < 0 || v3 >= this->m_arPanels.m_nSize )
      AfxThrowInvalidArgException();
    v4 = this->m_arPanels.m_pData[v3];
    if ( PtInRect(lprc: &v4->m_rect, pt: point.tagPOINT) )
      break;
    if ( ++v3 >= this->m_arPanels.m_nSize )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x103DED84
// Name: public: class CMFCRibbonPanel __near * CMFCRibbonCategory::HighlightPanel(class CMFCRibbonPanel __near *,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonPanel *__thiscall CMFCRibbonCategory::HighlightPanel(
        CMFCRibbonCategory *this,
        CMFCRibbonPanel *pHLPanel,
        CPoint point)
{
  int v3; // ebx
  CMFCRibbonPanel *v5; // esi
  HWND *m_pParentMenuBar; // eax
  CMFCRibbonPanel *pPrevHLPanel; // [esp+8h] [ebp-4h]

  v3 = 0;
  for ( pPrevHLPanel = nullptr; v3 < this->m_arPanels.m_nSize; ++v3 )
  {
    if ( v3 < 0 || v3 >= this->m_arPanels.m_nSize )
      AfxThrowInvalidArgException();
    v5 = this->m_arPanels.m_pData[v3];
    if ( v5->m_bIsHighlighted != 0 )
    {
      if ( pHLPanel != v5 )
        ((void (__thiscall *)(CMFCRibbonPanel *, _DWORD, int, int))v5->Highlight)(
          a1: v5,
          a2: 0,
          a3: point.x,
          a4: point.y);
      pPrevHLPanel = v5;
    }
    if ( pHLPanel == v5 )
      ((void (__thiscall *)(CMFCRibbonPanel *, int, int, int))v5->Highlight)(a1: v5, a2: 1, a3: point.x, a4: point.y);
  }
  m_pParentMenuBar = (HWND *)this->m_pParentMenuBar;
  if ( m_pParentMenuBar == nullptr )
    m_pParentMenuBar = (HWND *)this->m_pParentRibbonBar;
  UpdateWindow(hWnd: m_pParentMenuBar[8]);
  return pPrevHLPanel;
}

//------------------------------------------------------------------------------
// Address: 0x103DEE14
// Name: public: virtual void CMFCRibbonCategory::OnCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::OnCancelMode(CMFCRibbonCategory *this)
{
  int i; // edi

  this->m_bMouseIsPressed = 0;
  for ( i = 0; i < this->m_arPanels.m_nSize; ++i )
  {
    if ( i < 0 || i >= this->m_arPanels.m_nSize )
      AfxThrowInvalidArgException();
    CMFCRibbonPanel::CancelMode(this: this->m_arPanels.m_pData[i]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103DEE54
// Name: public: virtual class CMFCRibbonBaseElement __near * CMFCRibbonCategory::OnLButtonDown(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonCategory::OnLButtonDown(CMFCRibbonCategory *this, CPoint point)
{
  CMFCRibbonBaseElement *v3; // esi
  CMFCRibbonBaseElement *result; // eax

  v3 = CMFCRibbonCategory::HitTestScrollButtons(this, point);
  if ( v3 != nullptr )
  {
    v3->OnAutoRepeat(this: v3);
    return v3 == CMFCRibbonCategory::HitTestScrollButtons(this, point) ? v3 : nullptr;
  }
  else
  {
    result = (CMFCRibbonBaseElement *)CMFCRibbonCategory::GetPanelFromPoint(this, point);
    if ( result != nullptr )
    {
      this->m_bMouseIsPressed = 1;
      return ((CMFCRibbonBaseElement *(__thiscall *)(CMFCRibbonBaseElement *, int, int))result->IsSeparator)(
               a1: result,
               a2: point.x,
               a3: point.y);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103DEEBC
// Name: public: virtual void CMFCRibbonCategory::OnLButtonUp(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonCategory::OnLButtonUp(CMFCRibbonCategory *this, CPoint point)
{
  CMFCRibbonPanel *PanelFromPoint; // eax

  this->m_ScrollLeft.m_bIsHighlighted = 0;
  this->m_ScrollRight.m_bIsHighlighted = 0;
  PanelFromPoint = CMFCRibbonCategory::GetPanelFromPoint(this, point);
  if ( PanelFromPoint != nullptr )
  {
    this->m_bMouseIsPressed = 0;
    ((void (__thiscall *)(CMFCRibbonPanel *, int, int))PanelFromPoint->MouseButtonUp)(
      a1: PanelFromPoint,
      a2: point.x,
      a3: point.y);
  }
}
