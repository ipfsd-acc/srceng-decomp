// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/qcgenerator/cqcgenmain.cpp
// Functions: 50
// ============================================================

#include "utils\qcgenerator\cqcgenmain.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: public: static char const __near * CQCGenMain::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CQCGenMain::GetPanelClassName()
{
  return "CQCGenMain";
}

//------------------------------------------------------------------------------
// Address: 0x00401020
// Name: public: virtual bool vgui::Panel::LookupElementBounds(char const __near *,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Panel::LookupElementBounds(
        vgui::Panel *this,
        const char *elementName,
        int *x,
        int *y,
        int *wide,
        int *tall)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00401030
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
// Address: 0x00401040
// Name: private: virtual class vgui::Panel __near * vgui::Panel::GetPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetPanel(vgui::Panel *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401050
// Name: protected: virtual void CQCGenMain::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQCGenMain::OnClose(CQCGenMain *this)
{
  vgui::Frame::OnClose(this);
  g_pVGui->Stop(this: g_pVGui);
}

//------------------------------------------------------------------------------
// Address: 0x00401070
// Name: protected: virtual void CQCGenMain::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CQCGenMain::OnCommand(CQCGenMain *this, const char *command)
{
  vgui::Frame::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x00401080
// Name: public: virtual bool vgui::Panel::IsProportional(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::Panel::IsProportional(vgui::Panel *this)
{
  return (this->_flags.m_nFlags & 0x1000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401090
// Name: public: virtual struct vgui::PanelMessageMap __near * CQCGenMain::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CQCGenMain::GetMessageMap(CQCGenMain *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CQCGenMain::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CQCGenMain::GetMessageMap'::`2'::s_pMap;
  `CQCGenMain::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CQCGenMain");
  `CQCGenMain::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401100
// Name: public: virtual struct PanelAnimationMap __near * CQCGenMain::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CQCGenMain::GetAnimMap(CQCGenMain *this)
{
  return FindOrAddPanelAnimationMap(className: "CQCGenMain");
}

//------------------------------------------------------------------------------
// Address: 0x00401110
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CQCGenMain::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CQCGenMain::GetKBMap(CQCGenMain *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CQCGenMain::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CQCGenMain::GetKBMap'::`2'::s_pMap;
  `CQCGenMain::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CQCGenMain");
  `CQCGenMain::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004011B0
// Name: public: void CUtlMemory<struct vgui::MessageMapItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<vgui::MessageMapItem_t,int>::Grow(CUtlMemory<vgui::MessageMapItem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::MessageMapItem_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = m_nAllocationCount << 6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::MessageMapItem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (vgui::MessageMapItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004012B0
// Name: public: static void CQCGenMain::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CQCGenMain::AddToMap(
        const char *scriptname,
        __int64 function,
        __int64 p1type,
        int p2type,
        const char *p2name,
        const char *p1name,
        vgui::DataType_t p2typea,
        const char *p2namea)
{
  vgui::PanelMessageMap *v8; // eax
  int m_Size; // edx
  vgui::MessageMapItem_t src; // [esp+40h] [ebp-40h] BYREF

  v8 = vgui::FindOrAddPanelMessageMap(className: "CQCGenMain");
  src.name = scriptname;
  src.firstParamType = (vgui::DataType_t)p2name;
  src.numParams = p2type;
  src.secondParamType = p2typea;
  src.firstParamName = p1name;
  memset(&src.nameSymbol, 0, 12);
  src.secondParamName = p2namea;
  m_Size = v8->entries.m_Size;
  *(_QWORD *)&src.func = function;
  *((_QWORD *)&src.func + 1) = p1type;
  CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
    this: &v8->entries,
    elem: m_Size,
    &src);
}

//------------------------------------------------------------------------------
// Address: 0x00401330
// Name: public: static void CQCGenMain::PanelMessageFunc_OnRefresh::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CQCGenMain::PanelMessageFunc_OnRefresh::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`CQCGenMain::PanelMessageFunc_OnRefresh::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `CQCGenMain::PanelMessageFunc_OnRefresh::InitVar'::`2'::bAdded = true;
    CQCGenMain::AddToMap(
      scriptname: "refresh",
      function: (unsigned int) __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401390
// Name: public: CQCGenMain::CQCGenMain(class vgui::Panel __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CQCGenMain *__thiscall CQCGenMain::CQCGenMain(
        CQCGenMain *this,
        vgui::Panel *parent,
        const char *pszPath,
        const char *pszScene,
        const char *name)
{
  vgui::PanelMessageMap *v6; // esi
  PanelAnimationMap *v7; // esi
  vgui::PanelKeyBindingMap *v8; // esi
  char *v9; // edi
  char v10; // al
  unsigned int v11; // eax
  char *v12; // edi
  char v13; // cl
  CQCGenerator *v14; // eax
  CQCGenerator *v15; // eax
  char szTitle[264]; // [esp+14h] [ebp-114h] BYREF
  int v18; // [esp+124h] [ebp-4h]

  szTitle[3] = HIBYTE(this);
  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CQCGenMain_vtbl *)&CQCGenMain::`vftable';
  v18 = 0;
  if ( `CQCGenMain::ChainToMap'::`2'::chained == 0 )
  {
    `CQCGenMain::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CQCGenMain");
    v6->pfnClassName = CQCGenMain::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `CQCGenMain::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CQCGenMain::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CQCGenMain");
    v7->pfnClassName = CQCGenMain::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `CQCGenMain::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CQCGenMain::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CQCGenMain");
    v8->pfnClassName = CQCGenMain::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  this->m_bChanged = false;
  CQCGenMain::PanelMessageFunc_OnRefresh::InitVar();
  g_pCQCGenMain = this;
  vgui::Frame::SetMinimizeButtonVisible(this, state: true);
  vgui::Panel::SetSize(this, wide: 846, tall: 770);
  vgui::Panel::SetMinimumSize(this, wide: 846, tall: 770);
  strcpy(&szTitle[4], pszPath);
  v9 = &szTitle[3];
  do
    v10 = *++v9;
  while ( v10 != 0 );
  strcpy(v9, "\\");
  v11 = strlen(pszScene) + 1;
  v12 = &szTitle[3];
  do
    v13 = *++v12;
  while ( v13 != 0 );
  qmemcpy(v12, pszScene, v11);
  vgui::Frame::SetTitle(this, title: &szTitle[4], surfaceTitle: true);
  v14 = (CQCGenerator *)operator new(nSize: 0x7D8u);
  LOBYTE(v18) = 1;
  if ( v14 != nullptr )
    v15 = CQCGenerator::CQCGenerator(this: v14, pParent: this, pszPath, pszScene);
  else
    v15 = nullptr;
  this->m_pQCGenerator = v15;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00412D40
// Name: public: virtual class vgui::Menu __near * vgui::Frame::GetSysMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::Frame::GetSysMenu(vgui::Frame *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax
  vgui::Panel *ChildByName; // edi
  vgui::Panel_vtbl *v5; // ebx
  int v6; // eax
  vgui::Panel *v7; // edi
  vgui::Panel_vtbl *v8; // ebx
  int v9; // eax
  vgui::Panel *v10; // edi
  vgui::Panel_vtbl *v11; // ebx
  int v12; // eax

  if ( this->_sysMenu != nullptr )
    return this->_sysMenu;
  v2 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v2 != nullptr )
    v3 = vgui::Menu::Menu(this: v2, parent: this, panelName: nullptr);
  else
    v3 = nullptr;
  this->_sysMenu = v3;
  v3->SetVisible(this: v3, a2: false);
  this->_sysMenu->AddActionSignalTarget_2(this: this->_sysMenu, a2: this);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Minimize",
    a3: "#SysMenu_Minimize",
    a4: "Minimize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Maximize",
    a3: "#SysMenu_Maximize",
    a4: "Maximize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Close",
    a3: "#SysMenu_Close",
    a4: "Close",
    a5: this,
    a6: nullptr);
  ChildByName = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Minimize", recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = ChildByName->__vftable;
    v6 = ((int (__thiscall *)(vgui::FrameButton *))this->_minimizeButton->IsVisible)(a1: this->_minimizeButton);
    v5->SetEnabled(this: ChildByName, a2: v6);
  }
  v7 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Maximize", recurseDown: false);
  if ( v7 != nullptr )
  {
    v8 = v7->__vftable;
    v9 = ((int (__thiscall *)(vgui::FrameButton *))this->_maximizeButton->IsVisible)(a1: this->_maximizeButton);
    v8->SetEnabled(this: v7, a2: v9);
  }
  v10 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Close", recurseDown: false);
  if ( v10 != nullptr )
  {
    v11 = v10->__vftable;
    v12 = ((int (__thiscall *)(vgui::FrameButton *))this->_closeButton->IsVisible)(a1: this->_closeButton);
    v11->SetEnabled(this: v10, a2: v12);
  }
  return this->_sysMenu;
}

//------------------------------------------------------------------------------
// Address: 0x00413790
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
// Address: 0x004137D0
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
// Address: 0x00413800
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Frame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Frame::GetMessageMap(vgui::Frame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Frame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetMessageMap'::`2'::s_pMap;
  `vgui::Frame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Frame");
  `vgui::Frame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00413830
// Name: public: virtual struct PanelAnimationMap __near * vgui::Frame::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Frame::GetAnimMap(vgui::Frame *this)
{
  return FindOrAddPanelAnimationMap(className: "Frame");
}

//------------------------------------------------------------------------------
// Address: 0x00413840
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Frame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Frame::GetKBMap(vgui::Frame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Frame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetKBMap'::`2'::s_pMap;
  `vgui::Frame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  `vgui::Frame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415B90
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
// Address: 0x00415F30
// Name: public: class vgui::Panel __near * vgui::Panel::FindSiblingByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindSiblingByName(vgui::Panel *this, const char *siblingName)
{
  vgui::Panel *result; // eax
  vgui::IPanel *v4; // edi
  int (__thiscall **p_GetChildCount)(vgui::IPanel *, unsigned int); // esi
  unsigned int v6; // eax
  vgui::IPanel *v7; // edi
  unsigned int (__thiscall **p_GetChild)(vgui::IPanel *, unsigned int, int); // esi
  int v9; // eax
  int v10; // eax
  vgui::IPanel *v11; // edi
  unsigned int v12; // ebp
  vgui::Panel *(__thiscall **p_GetPanel)(vgui::IPanel *, unsigned int, const char *); // esi
  const char *ControlsModuleName; // eax
  int v15; // esi
  const char *v16; // eax
  int siblingCount; // [esp+14h] [ebp-8h]
  int v18; // [esp+18h] [ebp-4h]

  result = (vgui::Panel *)this->GetVParent(this);
  if ( result != nullptr )
  {
    v4 = g_pVGuiPanel;
    p_GetChildCount = &g_pVGuiPanel->GetChildCount;
    v6 = this->GetVParent(this);
    v18 = (*p_GetChildCount)(this: v4, a2: v6);
    siblingCount = 0;
    if ( v18 <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        v7 = g_pVGuiPanel;
        p_GetChild = &g_pVGuiPanel->GetChild;
        v9 = ((int (__thiscall *)(vgui::Panel *, int))this->GetVParent)(a1: this, a2: siblingCount);
        v10 = ((int (__thiscall *)(vgui::IPanel *, int))*p_GetChild)(a1: v7, a2: v9);
        v11 = g_pVGuiPanel;
        v12 = v10;
        p_GetPanel = &g_pVGuiPanel->GetPanel;
        ControlsModuleName = vgui::GetControlsModuleName();
        v15 = (int)(*p_GetPanel)(this: v11, a2: v12, a3: ControlsModuleName);
        v16 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v15 + 72))(a1: v15);
        if ( _V_stricmp(s1: v16, s2: siblingName) == 0 )
          break;
        if ( ++siblingCount >= v18 )
          return nullptr;
      }
      return (vgui::Panel *)v15;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416140
// Name: public: virtual class vgui::Panel __near * vgui::Panel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::HasHotkey(vgui::Panel *this, wchar_t key)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004163F0
// Name: public: virtual enum vgui::KeyBindingContextHandle_t vgui::Panel::GetKeyBindingsContext(void)const
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t __thiscall vgui::Panel::GetKeyBindingsContext(vgui::Panel *this)
{
  return this->m_hKeyBindingsContext;
}

//------------------------------------------------------------------------------
// Address: 0x00416820
// Name: public: class vgui::Panel __near * vgui::Panel::GetChild(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetChild(vgui::Panel *this, int index)
{
  vgui::IPanel *v2; // edi
  vgui::IPanel *v3; // ebx
  vgui::IPanel_vtbl *v4; // ebp
  const char *ControlsModuleName; // eax
  int v7; // eax
  int v8; // eax

  v2 = g_pVGuiPanel;
  v3 = g_pVGuiPanel;
  v4 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  v7 = ((int (__thiscall *)(vgui::Panel *, int, const char *))this->GetVPanel)(
         a1: this,
         a2: index,
         a3: ControlsModuleName);
  v8 = (*(int (__thiscall **)(vgui::IPanel *, int))(index + 72))(a1: v2, a2: v7);
  return ((vgui::Panel *(__thiscall *)(vgui::IPanel *, int))v4->GetPanel)(a1: v3, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x00416AA0
// Name: public: virtual class vgui::IBorder __near * vgui::Panel::GetBorder(void)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall vgui::Panel::GetBorder(vgui::Panel *this)
{
  return this->_border;
}

//------------------------------------------------------------------------------
// Address: 0x00416E60
// Name: public: enum vgui::Panel::PinCorner_e vgui::Panel::GetPinCorner(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetPinCorner(vgui::Panel *this)
{
  return *((_BYTE *)this + 166) & 0xF;
}

//------------------------------------------------------------------------------
// Address: 0x00416E90
// Name: public: enum vgui::Panel::AutoResize_e vgui::Panel::GetAutoResize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetAutoResize(vgui::Panel *this)
{
  return *((unsigned __int8 *)this + 166) >> 4;
}

//------------------------------------------------------------------------------
// Address: 0x00417320
// Name: public: virtual struct vgui::PanelMap_t __near * vgui::Panel::GetPanelMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMap_t *__thiscall vgui::Panel::GetPanelMap(vgui::Panel *this)
{
  return &vgui::Panel::m_PanelMap;
}

//------------------------------------------------------------------------------
// Address: 0x00418BE0
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
// Address: 0x00418C40
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
// Address: 0x00418C90
// Name: public: virtual struct vgui::DragDrop_t __near * vgui::Panel::GetDragDropInfo(void)
// Source: json
//------------------------------------------------------------------------------
vgui::DragDrop_t *__thiscall vgui::Panel::GetDragDropInfo(vgui::Panel *this)
{
  return this->m_pDragDrop;
}

//------------------------------------------------------------------------------
// Address: 0x00419940
// Name: public: class vgui::Panel __near * vgui::Panel::FindChildByName(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindChildByName(vgui::Panel *this, const char *childName, bool recurseDown)
{
  vgui::IPanel *v3; // ebx
  int (__thiscall **p_GetChildCount)(vgui::IPanel *, unsigned int); // esi
  int v5; // eax
  int v6; // eax
  int (__thiscall **p_GetPanel)(vgui::IPanel *, int); // esi
  int (__thiscall **p_GetChild)(vgui::IPanel *, int); // edi
  const char *ControlsModuleName; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  vgui::Panel *v13; // esi
  const char *v14; // eax
  vgui::Panel *result; // eax
  int i; // [esp+10h] [ebp-8h]
  vgui::Panel *v17; // [esp+14h] [ebp-4h]

  v17 = this;
  for ( i = 0; ; ++i )
  {
    v3 = g_pVGuiPanel;
    if ( g_pVGuiPanel != nullptr )
    {
      p_GetChildCount = &g_pVGuiPanel->GetChildCount;
      v5 = this->GetVPanel(this);
      v6 = (*p_GetChildCount)(this: v3, a2: v5);
      v3 = g_pVGuiPanel;
    }
    else
    {
      v6 = 0;
    }
    if ( i >= v6 )
      break;
    p_GetPanel = (int (__thiscall **)(vgui::IPanel *, int))&v3->GetPanel;
    p_GetChild = (int (__thiscall **)(vgui::IPanel *, int))&v3->GetChild;
    ControlsModuleName = vgui::GetControlsModuleName();
    v10 = ((int (__thiscall *)(vgui::Panel *, int, const char *))v17->GetVPanel)(a1: v17, a2: i, a3: ControlsModuleName);
    v11 = (*p_GetChild)(a1: v3, a2: v10);
    v12 = (*p_GetPanel)(a1: v3, a2: v11);
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
    this = v17;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041AA60
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
  v2 = (vgui::Tooltip *)operator new(nSize: 0x28u);
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
// Address: 0x0041B1E0
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavUp(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavUp(vgui::Panel *this, vgui::Panel *first)
{
  vgui::PHandle *p_m_NavUp; // ebp
  vgui::Panel *v4; // eax
  vgui::Panel *ChildByName; // eax
  unsigned int v6; // edi
  vgui::IPanel *v7; // esi
  vgui::IPanel_vtbl *v8; // ebx
  const char *ControlsModuleName; // eax
  vgui::Panel *v10; // ebx
  unsigned int v11; // edi
  vgui::IPanel *v12; // esi
  vgui::IPanel_vtbl *v13; // ebx
  const char *v14; // eax
  vgui::Panel *v15; // eax
  vgui::Panel *v16; // eax
  vgui::Panel *v17; // eax
  const char *v19; // [esp-8h] [ebp-20h]
  vgui::Panel *v20; // [esp+10h] [ebp-8h]

  p_m_NavUp = &this->m_NavUp;
  if ( !vgui::PHandle::operator bool(this: &this->m_NavUp) && CUtlString::Length(this: &this->m_sNavUpName) > 0 )
  {
    v19 = CUtlString::operator char const *(this: &this->m_sNavUpName);
    v4 = this->GetParent(this);
    ChildByName = vgui::Panel::FindChildByName(this: v4, childName: v19, recurseDown: true);
    if ( ChildByName != nullptr )
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavUp, pPanel: ChildByName);
  }
  if ( p_m_NavUp->m_iPanelID == -1 || (v6 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID)) == 0 )
  {
    v20 = nullptr;
    v10 = nullptr;
  }
  else
  {
    v7 = g_pVGuiPanel;
    v8 = g_pVGuiPanel->__vftable;
    ControlsModuleName = vgui::GetControlsModuleName();
    v10 = v8->GetPanel(this: v7, a2: v6, a3: ControlsModuleName);
    v20 = v10;
  }
  if ( !vgui::PHandle::operator bool(this: p_m_NavUp) )
    return v10;
  if ( p_m_NavUp->m_iPanelID == -1 || (v11 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID)) == 0 )
  {
    v15 = nullptr;
  }
  else
  {
    v12 = g_pVGuiPanel;
    v13 = g_pVGuiPanel->__vftable;
    v14 = vgui::GetControlsModuleName();
    v15 = v13->GetPanel(this: v12, a2: v11, a3: v14);
    v10 = v20;
  }
  if ( v15 == first )
    return v10;
  v16 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: p_m_NavUp);
  if ( v16->IsVisible(this: v16) )
    return v10;
  v17 = this;
  if ( first != nullptr )
    v17 = first;
  return vgui::Panel::GetNavUp(this: v10, first: v17);
}

//------------------------------------------------------------------------------
// Address: 0x0041B310
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavDown(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavDown(vgui::Panel *this, vgui::Panel *first)
{
  vgui::PHandle *p_m_NavDown; // ebp
  vgui::Panel *v4; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v6; // eax
  unsigned int v7; // edi
  vgui::IPanel *v8; // esi
  vgui::IPanel_vtbl *v9; // ebx
  const char *ControlsModuleName; // eax
  vgui::Panel *v11; // ebx
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  vgui::Panel *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  const char *v20; // [esp-8h] [ebp-20h]
  vgui::Panel *v21; // [esp+10h] [ebp-8h]

  p_m_NavDown = &this->m_NavDown;
  if ( !vgui::PHandle::operator bool(this: &this->m_NavDown) && CUtlString::Length(this: &this->m_sNavDownName) > 0 )
  {
    v20 = CUtlString::operator char const *(this: &this->m_sNavDownName);
    v4 = this->GetParent(this);
    ChildByName = vgui::Panel::FindChildByName(this: v4, childName: v20, recurseDown: true);
    if ( ChildByName != nullptr )
    {
      v6 = ChildByName->GetPanel(this: ChildByName);
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavDown, pPanel: v6);
    }
  }
  if ( p_m_NavDown->m_iPanelID == -1 || (v7 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID)) == 0 )
  {
    v21 = nullptr;
    v11 = nullptr;
  }
  else
  {
    v8 = g_pVGuiPanel;
    v9 = g_pVGuiPanel->__vftable;
    ControlsModuleName = vgui::GetControlsModuleName();
    v11 = v9->GetPanel(this: v8, a2: v7, a3: ControlsModuleName);
    v21 = v11;
  }
  if ( !vgui::PHandle::operator bool(this: p_m_NavDown) )
    return v11;
  if ( p_m_NavDown->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID)) == 0 )
  {
    v16 = nullptr;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = v14->GetPanel(this: v13, a2: v12, a3: v15);
    v11 = v21;
  }
  if ( v16 == first )
    return v11;
  v17 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: p_m_NavDown);
  if ( v17->IsVisible(this: v17) )
    return v11;
  v18 = this;
  if ( first != nullptr )
    v18 = first;
  return vgui::Panel::GetNavDown(this: v11, first: v18);
}

//------------------------------------------------------------------------------
// Address: 0x0041B450
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavLeft(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavLeft(vgui::Panel *this, vgui::Panel *first)
{
  vgui::PHandle *p_m_NavLeft; // ebp
  vgui::Panel *v4; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v6; // eax
  unsigned int v7; // edi
  vgui::IPanel *v8; // esi
  vgui::IPanel_vtbl *v9; // ebx
  const char *ControlsModuleName; // eax
  vgui::Panel *v11; // ebx
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  vgui::Panel *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  const char *v20; // [esp-8h] [ebp-20h]
  vgui::Panel *v21; // [esp+10h] [ebp-8h]

  p_m_NavLeft = &this->m_NavLeft;
  if ( !vgui::PHandle::operator bool(this: &this->m_NavLeft) && CUtlString::Length(this: &this->m_sNavLeftName) > 0 )
  {
    v20 = CUtlString::operator char const *(this: &this->m_sNavLeftName);
    v4 = this->GetParent(this);
    ChildByName = vgui::Panel::FindChildByName(this: v4, childName: v20, recurseDown: true);
    if ( ChildByName != nullptr )
    {
      v6 = ChildByName->GetPanel(this: ChildByName);
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavLeft, pPanel: v6);
    }
  }
  if ( p_m_NavLeft->m_iPanelID == -1 || (v7 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID)) == 0 )
  {
    v21 = nullptr;
    v11 = nullptr;
  }
  else
  {
    v8 = g_pVGuiPanel;
    v9 = g_pVGuiPanel->__vftable;
    ControlsModuleName = vgui::GetControlsModuleName();
    v11 = v9->GetPanel(this: v8, a2: v7, a3: ControlsModuleName);
    v21 = v11;
  }
  if ( !vgui::PHandle::operator bool(this: p_m_NavLeft) )
    return v11;
  if ( p_m_NavLeft->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID)) == 0 )
  {
    v16 = nullptr;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = v14->GetPanel(this: v13, a2: v12, a3: v15);
    v11 = v21;
  }
  if ( v16 == first )
    return v11;
  v17 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: p_m_NavLeft);
  if ( v17->IsVisible(this: v17) )
    return v11;
  v18 = this;
  if ( first != nullptr )
    v18 = first;
  return vgui::Panel::GetNavLeft(this: v11, first: v18);
}

//------------------------------------------------------------------------------
// Address: 0x0041B590
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavRight(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavRight(vgui::Panel *this, vgui::Panel *first)
{
  vgui::PHandle *p_m_NavRight; // ebp
  vgui::Panel *v4; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v6; // eax
  unsigned int v7; // edi
  vgui::IPanel *v8; // esi
  vgui::IPanel_vtbl *v9; // ebx
  const char *ControlsModuleName; // eax
  vgui::Panel *v11; // ebx
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  vgui::Panel *v16; // eax
  vgui::Panel *v17; // eax
  vgui::Panel *v18; // eax
  const char *v20; // [esp-8h] [ebp-20h]
  vgui::Panel *v21; // [esp+10h] [ebp-8h]

  p_m_NavRight = &this->m_NavRight;
  if ( !vgui::PHandle::operator bool(this: &this->m_NavRight) && CUtlString::Length(this: &this->m_sNavRightName) > 0 )
  {
    v20 = CUtlString::operator char const *(this: &this->m_sNavRightName);
    v4 = this->GetParent(this);
    ChildByName = vgui::Panel::FindChildByName(this: v4, childName: v20, recurseDown: true);
    if ( ChildByName != nullptr )
    {
      v6 = ChildByName->GetPanel(this: ChildByName);
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavRight, pPanel: v6);
    }
  }
  if ( p_m_NavRight->m_iPanelID == -1 || (v7 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID)) == 0 )
  {
    v21 = nullptr;
    v11 = nullptr;
  }
  else
  {
    v8 = g_pVGuiPanel;
    v9 = g_pVGuiPanel->__vftable;
    ControlsModuleName = vgui::GetControlsModuleName();
    v11 = v9->GetPanel(this: v8, a2: v7, a3: ControlsModuleName);
    v21 = v11;
  }
  if ( !vgui::PHandle::operator bool(this: p_m_NavRight) )
    return v11;
  if ( p_m_NavRight->m_iPanelID == -1
    || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID)) == 0 )
  {
    v16 = nullptr;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = v14->GetPanel(this: v13, a2: v12, a3: v15);
    v11 = v21;
  }
  if ( v16 == first )
    return v11;
  v17 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: p_m_NavRight);
  if ( v17->IsVisible(this: v17) )
    return v11;
  v18 = this;
  if ( first != nullptr )
    v18 = first;
  return vgui::Panel::GetNavRight(this: v11, first: v18);
}

//------------------------------------------------------------------------------
// Address: 0x0041B9E0
// Name: public: struct vgui::KeyBindingMap_t __near * vgui::Panel::LookupBinding(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingMap_t *__thiscall vgui::Panel::LookupBinding(vgui::Panel *this, const char *bindingName)
{
  vgui::PanelKeyBindingMap *v2; // ebp
  int v3; // ebx
  int v4; // edi
  const char **p_bindingname; // esi
  int m_Size; // [esp+10h] [ebp-4h]

  v2 = this->GetKBMap(this);
  if ( v2 == nullptr )
    return nullptr;
  while ( 1 )
  {
    v3 = 0;
    m_Size = v2->entries.m_Size;
    if ( m_Size > 0 )
      break;
LABEL_6:
    v2 = v2->baseMap;
    if ( v2 == nullptr )
      return nullptr;
  }
  v4 = 0;
  while ( 1 )
  {
    p_bindingname = &v2->entries.m_Memory.m_pMemory[v4].bindingname;
    if ( _V_stricmp(s1: *p_bindingname, s2: bindingName) == 0 )
      return (vgui::KeyBindingMap_t *)p_bindingname;
    ++v3;
    ++v4;
    if ( v3 >= m_Size )
      goto LABEL_6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041BA50
// Name: public: struct vgui::PanelKeyBindingMap __near * vgui::Panel::LookupMapForBinding(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::LookupMapForBinding(vgui::Panel *this, const char *bindingName)
{
  vgui::PanelKeyBindingMap *v2; // ebx
  int m_Size; // ebp
  int v4; // edi
  int v5; // esi

  v2 = this->GetKBMap(this);
  if ( v2 == nullptr )
    return nullptr;
  while ( 1 )
  {
    m_Size = v2->entries.m_Size;
    v4 = 0;
    if ( m_Size > 0 )
      break;
LABEL_6:
    v2 = v2->baseMap;
    if ( v2 == nullptr )
      return nullptr;
  }
  v5 = 0;
  while ( _V_stricmp(s1: v2->entries.m_Memory.m_pMemory[v5].bindingname, s2: bindingName) != 0 )
  {
    ++v4;
    ++v5;
    if ( v4 >= m_Size )
      goto LABEL_6;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0041BAB0
// Name: public: struct vgui::KeyBindingMap_t __near * vgui::Panel::LookupBindingByKeyCode(enum ButtonCode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingMap_t *__thiscall vgui::Panel::LookupBindingByKeyCode(
        vgui::Panel *this,
        ButtonCode_t code,
        int modifiers)
{
  _DWORD *v3; // ebx
  int v4; // ebp
  int v5; // edi
  int v6; // esi
  int v7; // eax
  vgui::KeyBindingMap_t *result; // eax

  v3 = (_DWORD *)((int (__fastcall *)(vgui::Panel *))this->GetKBMap)(a1: this);
  if ( v3 == nullptr )
    return nullptr;
  while ( 1 )
  {
    v4 = v3[15];
    v5 = 0;
    if ( v4 > 0 )
      break;
LABEL_8:
    v3 = (_DWORD *)v3[6];
    if ( v3 == nullptr )
      return nullptr;
  }
  v6 = 0;
  while ( 1 )
  {
    v7 = v6 + v3[12];
    if ( *(_DWORD *)(v7 + 8) == code && *(_DWORD *)(v7 + 12) == modifiers )
    {
      result = vgui::Panel::LookupBinding(this, bindingName: *(const char **)(v7 + 4));
      if ( result != nullptr )
        return result;
    }
    ++v5;
    v6 += 16;
    if ( v5 >= v4 )
      goto LABEL_8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041CE40
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
// Address: 0x0041CE80
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
// Address: 0x0041CEC0
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
// Address: 0x0041CF00
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
// Address: 0x00422280
// Name: private: class vgui::Panel __near * vgui::Panel::FindDropTargetPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindDropTargetPanel(vgui::Panel *this)
{
  unsigned int v1; // ebp
  vgui::IPanel *v2; // edi
  vgui::Panel *(__thiscall **p_GetPanel)(vgui::IPanel *, unsigned int, const char *); // esi
  const char *ControlsModuleName; // eax
  unsigned int v5; // ebp
  vgui::IPanel *v6; // edi
  vgui::Panel *(__thiscall **v7)(vgui::IPanel *, unsigned int, const char *); // esi
  const char *v8; // eax
  int (__thiscall ***v9)(_DWORD); // eax
  unsigned int *v10; // eax
  vgui::ISurface_vtbl *v11; // edx
  int v12; // edi
  unsigned int *m_pElements; // ebp
  unsigned int *v14; // eax
  unsigned int v15; // esi
  int v16; // ebp
  vgui::IPanel *v17; // edi
  unsigned int *v18; // ebx
  vgui::Panel *(__thiscall **v19)(vgui::IPanel *, unsigned int, const char *); // esi
  int v20; // eax
  int v21; // esi
  int x; // [esp+24h] [ebp-28h] BYREF
  int v24; // [esp+28h] [ebp-24h] BYREF
  unsigned int embedded; // [esp+2Ch] [ebp-20h]
  unsigned int helper; // [esp+30h] [ebp-1Ch]
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > hits; // [esp+34h] [ebp-18h] BYREF
  int v28; // [esp+48h] [ebp-4h]

  embedded = (unsigned int)this;
  if ( s_DragDropHelper.m_iPanelID == -1 )
    return nullptr;
  v1 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID);
  if ( v1 == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  p_GetPanel = &g_pVGuiPanel->GetPanel;
  ControlsModuleName = vgui::GetControlsModuleName();
  if ( (int)(*p_GetPanel)(this: v2, a2: v1, a3: ControlsModuleName) == 0 )
    return nullptr;
  memset(&hits.m_Memory.m_nAllocationCount, 0, 16);
  v28 = 0;
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &v24, a3: &x);
  helper = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  if ( s_DragDropHelper.m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID)) == 0 )
  {
    v9 = nullptr;
  }
  else
  {
    v6 = g_pVGuiPanel;
    v7 = &g_pVGuiPanel->GetPanel;
    v8 = vgui::GetControlsModuleName();
    v9 = (int (__thiscall ***)(_DWORD))(*v7)(this: v6, a2: v5, a3: v8);
  }
  v10 = (unsigned int *)(**v9)(a1: v9);
  v11 = g_pVGuiSurface->__vftable;
  hits.m_Memory.m_pMemory = v10;
  if ( v11->IsCursorVisible(this: g_pVGuiSurface) && g_pVGuiSurface->IsWithin(this: g_pVGuiSurface, a2: v24, a3: x) )
  {
    v12 = g_pVGuiSurface->GetPopupCount(this: g_pVGuiSurface) - 1;
    if ( v12 >= 0 )
    {
      do
      {
        m_pElements = hits.m_pElements;
        if ( hits.m_pElements != nullptr )
          goto LABEL_20;
        v14 = (unsigned int *)g_pVGuiSurface->GetPopup(this: g_pVGuiSurface, a2: v12);
        v15 = (unsigned int)v14;
        if ( v14 != (unsigned int *)helper
          && v14 != hits.m_Memory.m_pMemory
          && g_pVGuiPanel->IsFullyVisible(this: g_pVGuiPanel, a2: (unsigned int)v14) )
        {
          vgui::Panel::FindDropTargetPanel_R(
            this: (vgui::Panel *)embedded,
            panelList: (CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)&hits.m_Memory.m_nAllocationCount,
            x: v24,
            y: x,
            check: v15);
        }
      }
      while ( --v12 >= 0 );
    }
    m_pElements = hits.m_pElements;
    if ( hits.m_pElements != nullptr )
      goto LABEL_20;
    vgui::Panel::FindDropTargetPanel_R(
      this: (vgui::Panel *)embedded,
      panelList: (CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)&hits.m_Memory.m_nAllocationCount,
      x: v24,
      y: x,
      check: helper);
  }
  m_pElements = hits.m_pElements;
  if ( hits.m_pElements == nullptr )
  {
LABEL_23:
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits.m_Memory.m_nAllocationCount);
    return nullptr;
  }
LABEL_20:
  v16 = (int)m_pElements - 1;
  if ( v16 < 0 )
    goto LABEL_23;
  while ( 1 )
  {
    v17 = g_pVGuiPanel;
    v18 = (unsigned int *)(hits.m_Memory.m_nAllocationCount + 4 * v16);
    v19 = &g_pVGuiPanel->GetPanel;
    v20 = (*(int (**)(void))(*(_DWORD *)embedded + 104))();
    v21 = (int)(*v19)(this: v17, a2: *v18, a3: (const char *)v20);
    if ( v21 != 0 )
      break;
    if ( --v16 < 0 )
      goto LABEL_23;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&hits.m_Memory.m_nAllocationCount);
  return (vgui::Panel *)v21;
}

//------------------------------------------------------------------------------
// Address: 0x0044AA40
// Name: public: virtual class vgui::Panel __near * vgui::TextEntry::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::TextEntry::GetDragPanel(vgui::TextEntry *this)
{
  int v2; // edi
  int x; // [esp+14h] [ebp-10h] BYREF
  int cx0; // [esp+18h] [ebp-Ch] BYREF
  int cx1; // [esp+1Ch] [ebp-8h] BYREF
  int v7; // [esp+20h] [ebp-4h] BYREF

  if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
    return vgui::Panel::GetDragPanel(this);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &cx0, a3: &x);
  vgui::Panel::ScreenToLocal(this, x: &cx0, y: &x);
  v2 = this->PixelToCursorSpace(this, a2: cx0, a3: x);
  if ( this->GetSelectedRange(this, a2: &cx1, a3: &v7) && v2 >= cx1 && v2 < v7 )
    return vgui::Panel::GetDragPanel(this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0044E290
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TextEntry::GetMessageMap(vgui::TextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetMessageMap'::`2'::s_pMap;
  `vgui::TextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  `vgui::TextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044E2C0
// Name: public: virtual struct PanelAnimationMap __near * vgui::TextEntry::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TextEntry::GetAnimMap(vgui::TextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "TextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x0044E2D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TextEntry::GetKBMap(vgui::TextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetKBMap'::`2'::s_pMap;
  `vgui::TextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  `vgui::TextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}
