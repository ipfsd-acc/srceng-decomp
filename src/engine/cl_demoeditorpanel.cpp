// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_demoeditorpanel.cpp
// Functions: 20
// ============================================================

#include "engine\cl_demoeditorpanel.h"

//------------------------------------------------------------------------------
// Address: 0x1007B000
// Name: public: static char const __near * CDemoEditorPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDemoEditorPanel::GetPanelClassName()
{
  return "CDemoEditorPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1007B010
// Name: public: CNewActionButton::CNewActionButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNewActionButton *__thiscall CNewActionButton::CNewActionButton(
        CNewActionButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::Menu *v5; // eax
  vgui::Menu *v6; // eax
  DEMOACTION i; // edi
  const char *v8; // ebx
  bool HasEditorFactory; // al
  void (__thiscall **texta)(vgui::Menu *, const char *, bool); // [esp+1Ch] [ebp+10h]

  vgui::MenuButton::MenuButton(this, parent, panelName, text);
  this->__vftable = (CNewActionButton_vtbl *)&CNewActionButton::`vftable';
  v5 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v5 != nullptr )
    v6 = vgui::Menu::Menu(this: v5, parent: this, panelName: "DemoEditNewAction");
  else
    v6 = nullptr;
  this->m_pMenu = v6;
  for ( i = DEMO_ACTION_SKIPAHEAD; i < NUM_DEMO_ACTIONS; ++i )
  {
    v8 = CBaseDemoAction::NameForType(actionType: i);
    this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: v8, a3: v8, a4: parent, a5: nullptr);
    texta = &this->m_pMenu->SetItemEnabled;
    HasEditorFactory = CBaseDemoAction::HasEditorFactory(actionType: i);
    (*texta)(this: this->m_pMenu, a2: v8, a3: HasEditorFactory);
  }
  vgui::Panel::MakePopup(this: this->m_pMenu, showTaskbarIcon: true, disabled: false);
  vgui::MenuButton::SetMenu(this, menu: this->m_pMenu);
  vgui::MenuButton::SetOpenDirection(this, direction: (vgui::Menu::MenuDirection_e)2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007B0F0
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x1007B100
// Name: public: virtual void CDemoEditorPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoEditorPanel::OnTick(CDemoEditorPanel *this)
{
  vgui::Label_vtbl *v2; // edi
  const char *v3; // eax
  const char *v4; // eax
  void (__thiscall *SetEnabled)(vgui::Panel *, bool); // edx
  bool v6; // bl
  vgui::Button_vtbl *v7; // edi
  bool v8; // al
  vgui::Button_vtbl *v9; // edi
  bool v10; // al

  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  v2 = this->m_pCurrentDemo->__vftable;
  v3 = demoaction->GetCurrentDemoFile(this: demoaction);
  v2->SetText(this: this->m_pCurrentDemo, a2: v3);
  v4 = demoaction->GetCurrentDemoFile(this: demoaction);
  SetEnabled = this->m_pNew->SetEnabled;
  if ( *v4 != 0 )
  {
    ((void (__stdcall *)(int))SetEnabled)(a1: 1);
    v6 = demoaction->GetActionCount(this: demoaction) > 0;
    this->m_pEdit->SetEnabled(this: this->m_pEdit, a2: v6);
    this->m_pDelete->SetEnabled(this: this->m_pDelete, a2: v6);
    if ( this->m_pActions != nullptr && this->m_pActions->GetSelectedItemsCount(this: this->m_pActions) != 1 )
    {
      this->m_pEdit->SetEnabled(this: this->m_pEdit, a2: false);
      this->m_pDelete->SetEnabled(this: this->m_pDelete, a2: false);
    }
    v7 = this->m_pSave->__vftable;
    v8 = demoaction->IsDirty(this: demoaction);
    v7->SetEnabled(this: this->m_pSave, a2: v8);
    v9 = this->m_pRevert->__vftable;
    v10 = demoaction->IsDirty(this: demoaction);
    v9->SetEnabled(this: this->m_pRevert, a2: v10);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))SetEnabled)(a1: 0);
    this->m_pEdit->SetEnabled(this: this->m_pEdit, a2: false);
    this->m_pDelete->SetEnabled(this: this->m_pDelete, a2: false);
    this->m_pSave->SetEnabled(this: this->m_pSave, a2: false);
    this->m_pRevert->SetEnabled(this: this->m_pRevert, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B270
// Name: protected: void CDemoEditorPanel::PopulateActionList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoEditorPanel::PopulateActionList(CDemoEditorPanel *this@<ecx>, int a2@<ebx>, __int64 a3@<esi:edi>)
{
  int v3; // eax
  int v4; // ebx
  CBaseDemoAction *v5; // esi
  KeyValues *v6; // edi
  char *ActionName; // eax
  KeyValues *v8; // edi
  char *v9; // eax
  const char *v10; // eax
  __int32 v11; // eax
  double StartTime; // st7
  const char *v13; // eax
  int StartTick; // eax
  int v16; // [esp+8h] [ebp-8h]

  if ( this->m_pActions != nullptr )
    this->m_pActions->DeleteAllItems(this: this->m_pActions);
  v3 = ((int (__thiscall *)(IDemoActionManager *, int))demoaction->GetActionCount)(a1: demoaction, a2);
  v4 = 0;
  v16 = v3;
  if ( v3 > 0 )
  {
    while ( 1 )
    {
      v5 = (CBaseDemoAction *)((int (__thiscall *)(IDemoActionManager *, int, _DWORD, _DWORD))demoaction->GetAction)(
                                a1: demoaction,
                                a2: v4,
                                a3,
                                a4: HIDWORD(a3));
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        ActionName = CBaseDemoAction::GetActionName(this: v5);
        v8 = KeyValues::KeyValues(this: v6, setName: "data", firstKey: "actionname", firstValue: ActionName);
      }
      else
      {
        v8 = nullptr;
      }
      v9 = CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)v5);
      v10 = CBaseDemoAction::NameForType(actionType: (DEMOACTION)v9);
      KeyValues::SetString(this: v8, keyName: "actiontype", value: v10);
      v11 = CNetChan::GetSocket(this: v5) - 1;
      if ( v11 == 0 )
        break;
      if ( v11 == 1 )
      {
        StartTime = CBaseDemoAction::GetStartTime(this: v5);
        v13 = va(format: "Time %.3f", StartTime);
LABEL_11:
        KeyValues::SetString(this: v8, keyName: "actionstart", value: v13);
      }
      a3 = 0;
      ((void (__thiscall *)(vgui::ListPanel *, KeyValues *, _DWORD))this->m_pActions->AddItem)(
        a1: this->m_pActions,
        a2: v8,
        a3: 0);
      if ( ++v4 >= v16 )
        return;
    }
    StartTick = CBaseDemoAction::GetStartTick(this: v5);
    v13 = va(format: "Tick %i", StartTick);
    goto LABEL_11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B3A0
// Name: public: virtual void vgui::Button::OnHotkey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Button::OnHotkey(vgui::Button *this)
{
  this->DoClick(this);
}

//------------------------------------------------------------------------------
// Address: 0x1007B3B0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDemoEditorPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDemoEditorPanel::GetMessageMap(CDemoEditorPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDemoEditorPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDemoEditorPanel::GetMessageMap'::`2'::s_pMap;
  `CDemoEditorPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDemoEditorPanel");
  `CDemoEditorPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B3E0
// Name: public: virtual struct PanelAnimationMap __near * CDemoEditorPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDemoEditorPanel::GetAnimMap(CDemoEditorPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDemoEditorPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1007B3F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDemoEditorPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDemoEditorPanel::GetKBMap(CDemoEditorPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDemoEditorPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDemoEditorPanel::GetKBMap'::`2'::s_pMap;
  `CDemoEditorPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDemoEditorPanel");
  `CDemoEditorPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B420
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuButton::GetMessageMap(vgui::MenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
  `vgui::MenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B450
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuButton::GetAnimMap(vgui::MenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x1007B460
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuButton::GetKBMap(vgui::MenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetKBMap'::`2'::s_pMap;
  `vgui::MenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
  `vgui::MenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B4F0
// Name: protected: void CDemoEditorPanel::CreateNewAction(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoEditorPanel::CreateNewAction(CDemoEditorPanel *this, const char *actiontype)
{
  DEMOACTION v3; // eax
  CBaseDemoAction *DemoAction; // esi
  const char *v5; // eax
  char *v6; // eax
  CBaseActionEditDialog *ActionEditor; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  int v10; // [esp-8h] [ebp-10h]

  if ( vgui::PHandle::Get(this: &this->m_hCurrentEditor) == nullptr )
  {
    v3 = CBaseDemoAction::TypeForName(name: actiontype);
    if ( v3 != DEMO_ACTION_UNKNOWN )
    {
      DemoAction = CBaseDemoAction::CreateDemoAction(actionType: v3);
      if ( DemoAction != nullptr )
      {
        v10 = g_nNewActionNumber++;
        v5 = va(format: "Unnamed%i", v10);
        CBaseDemoAction::SetActionName(this: DemoAction, name: v5);
        demoaction->SetDirty(this: demoaction, a2: true);
        v6 = CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)DemoAction);
        ActionEditor = CBaseDemoAction::CreateActionEditor(
                         actionType: (DEMOACTION)v6,
                         parent: this,
                         action: DemoAction,
                         newaction: true);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(
          this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hCurrentEditor,
          pPanel: (CDragDropHelperPanel *)ActionEditor);
        if ( vgui::PHandle::Get(this: &this->m_hCurrentEditor) != nullptr )
        {
          v8 = vgui::PHandle::Get(this: &this->m_hCurrentEditor);
          v8->SetVisible(this: v8, a2: true);
          v9 = vgui::PHandle::Get(this: &this->m_hCurrentEditor);
          vgui::Panel::SetSize(this: v9, wide: 400, tall: 300);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B5D0
// Name: public: void CDemoEditorPanel::OnVDMChanged(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __usercall CDemoEditorPanel::OnVDMChanged(CDemoEditorPanel *this@<ecx>, int a2@<ebx>, __int64 a3@<esi:edi>)
{
  CDemoEditorPanel::PopulateActionList(this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x1007B5E0
// Name: protected: void CDemoEditorPanel::OnEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoEditorPanel::OnEdit(CDemoEditorPanel *this)
{
  int v2; // eax
  char *v3; // eax
  CBaseActionEditDialog *ActionEditor; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Tooltip *v7; // [esp-8h] [ebp-10h]

  if ( vgui::PHandle::Get(this: &this->m_hCurrentEditor) == nullptr
    && this->m_pActions->GetSelectedItemsCount(this: this->m_pActions) == 1 )
  {
    v2 = this->m_pActions->GetSelectedItem(this: this->m_pActions, a2: 0);
    if ( v2 != -1 )
    {
      v7 = (vgui::Tooltip *)demoaction->GetAction(this: demoaction, a2: v2);
      v3 = CWaveDataStreamAsync::Source(this: v7);
      ActionEditor = CBaseDemoAction::CreateActionEditor(
                       actionType: (DEMOACTION)v3,
                       parent: this,
                       action: (CBaseDemoAction *)v7,
                       newaction: false);
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hCurrentEditor,
        pPanel: (CDragDropHelperPanel *)ActionEditor);
      if ( vgui::PHandle::Get(this: &this->m_hCurrentEditor) != nullptr )
      {
        v5 = vgui::PHandle::Get(this: &this->m_hCurrentEditor);
        v5->SetVisible(this: v5, a2: true);
        v6 = vgui::PHandle::Get(this: &this->m_hCurrentEditor);
        vgui::Panel::SetSize(this: v6, wide: 400, tall: 300);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B6A0
// Name: protected: virtual void CDemoEditorPanel::OnDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoEditorPanel::OnDelete(CDemoEditorPanel *this)
{
  int v2; // eax
  int i; // edi
  int v4; // eax
  CBaseDemoAction *v5; // eax

  v2 = this->m_pActions->GetSelectedItemsCount(this: this->m_pActions);
  if ( v2 >= 1 )
  {
    for ( i = v2; i != 0; --i )
    {
      v4 = this->m_pActions->GetSelectedItem(this: this->m_pActions, a2: 0);
      if ( v4 != -1 )
      {
        v5 = demoaction->GetAction(this: demoaction, a2: v4);
        if ( v5 != nullptr )
          demoaction->RemoveAction(this: demoaction, a2: v5);
      }
    }
    CDemoEditorPanel::PopulateActionList(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B710
// Name: protected: void CDemoEditorPanel::OnRevert(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoEditorPanel::OnRevert(CDemoEditorPanel *this@<ecx>, int a2@<ebx>, __int64 a3@<esi:edi>)
{
  HIDWORD(a3) = this;
  demoaction->ReloadFromDisk(this: demoaction);
  CDemoEditorPanel::PopulateActionList(this: (CDemoEditorPanel *)HIDWORD(a3), a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x1007B730
// Name: public: CDemoEditorPanel::CDemoEditorPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CDemoEditorPanel *__userpurge CDemoEditorPanel::CDemoEditorPanel@<eax>(
        CDemoEditorPanel *this@<ecx>,
        int a2@<ebx>,
        vgui::Panel *parent)
{
  __int64 v3; // rdi
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  CNewActionButton *v15; // eax
  CNewActionButton *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  vgui::Button *v19; // eax
  vgui::Button *v20; // eax
  vgui::Label *v21; // eax
  vgui::Label *v22; // eax
  vgui::ListPanel *v23; // eax
  vgui::ListPanel *v24; // eax
  int Tall; // eax
  vgui::Panel *v26; // ecx
  int Wide; // eax
  vgui::Panel *v28; // ecx
  int v29; // eax
  vgui::Panel *v30; // ecx
  int v31; // eax
  int xpos; // [esp+8h] [ebp-8h] BYREF
  int ypos; // [esp+Ch] [ebp-4h] BYREF

  HIDWORD(v3) = this;
  vgui::Frame::Frame(this, parent, panelName: "DemoEditorPanel", showTaskbarIcon: true, bPopup: true);
  *(_DWORD *)HIDWORD(v3) = &CDemoEditorPanel::`vftable';
  if ( `CDemoEditorPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDemoEditorPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDemoEditorPanel");
    v4->pfnClassName = CDemoEditorPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CDemoEditorPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDemoEditorPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDemoEditorPanel");
    v5->pfnClassName = CDemoEditorPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CDemoEditorPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDemoEditorPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDemoEditorPanel");
    v6->pfnClassName = CDemoEditorPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  *(_DWORD *)(HIDWORD(v3) + 568) = -1;
  vgui::Panel::SetSize(this: (vgui::Panel *)HIDWORD(v3), wide: 440, tall: 300);
  vgui::Frame::SetTitle(this: (vgui::Frame *)HIDWORD(v3), title: "Demo Editor", surfaceTitle: true);
  v7 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v7 != nullptr )
    v8 = vgui::Button::Button(
           this: v7,
           parent: (vgui::Panel *)HIDWORD(v3),
           panelName: "DemoEditSave",
           text: "Save",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v8 = nullptr;
  *(_DWORD *)(HIDWORD(v3) + 536) = v8;
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: (vgui::Panel *)HIDWORD(v3),
            panelName: "DemoEditRevert",
            text: "Revert",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  *(_DWORD *)(HIDWORD(v3) + 540) = v10;
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: (vgui::Panel *)HIDWORD(v3),
            panelName: "DemoEditOk",
            text: "OK",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v12 = nullptr;
  *(_DWORD *)(HIDWORD(v3) + 544) = v12;
  v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: (vgui::Panel *)HIDWORD(v3),
            panelName: "DemoEditCancel",
            text: "Cancel",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v14 = nullptr;
  *(_DWORD *)(HIDWORD(v3) + 548) = v14;
  v15 = (CNewActionButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v15 != nullptr )
    v16 = CNewActionButton::CNewActionButton(
            this: v15,
            parent: (vgui::Panel *)HIDWORD(v3),
            panelName: "DemoEditNew",
            text: "New->");
  else
    v16 = nullptr;
  *(_DWORD *)(HIDWORD(v3) + 552) = v16;
  v17 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v17 != nullptr )
    v18 = vgui::Button::Button(
            this: v17,
            parent: (vgui::Panel *)HIDWORD(v3),
            panelName: "DemoEditEdit",
            text: "Edit...",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v18 = nullptr;
  *(_DWORD *)(HIDWORD(v3) + 556) = v18;
  v19 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v19 != nullptr )
    v20 = vgui::Button::Button(
            this: v19,
            parent: (vgui::Panel *)HIDWORD(v3),
            panelName: "DemoEditDelete",
            text: "Delete",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v20 = nullptr;
  *(_DWORD *)(HIDWORD(v3) + 560) = v20;
  v21 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v21 != nullptr )
    v22 = vgui::Label::Label(this: v21, parent: (vgui::Panel *)HIDWORD(v3), panelName: "DemoName", text: defaultValue);
  else
    v22 = nullptr;
  *(_DWORD *)(HIDWORD(v3) + 532) = v22;
  v23 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v23 != nullptr )
    v24 = vgui::ListPanel::ListPanel(this: v23, parent: (vgui::Panel *)HIDWORD(v3), panelName: "DemoActionList");
  else
    v24 = nullptr;
  *(_DWORD *)(HIDWORD(v3) + 564) = v24;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: *(_DWORD *)(HIDWORD(v3) + 72), a3: 0);
  vgui::Frame::LoadControlSettings(
    this: (vgui::Frame *)HIDWORD(v3),
    dialogResourceName: "Resource\\DemoEditorPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::GetPos(this: parent, x: &xpos, y: &ypos);
  Tall = vgui::Panel::GetTall(this: parent);
  ypos += Tall;
  vgui::Panel::SetPos(this: (vgui::Panel *)HIDWORD(v3), x: xpos, y: ypos);
  v26 = *(vgui::Panel **)(HIDWORD(v3) + 564);
  LODWORD(v3) = v26->__vftable;
  Wide = vgui::Panel::GetWide(this: v26);
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, const char *, int, _DWORD))(v3 + 844))(
    a1: *(_DWORD *)(HIDWORD(v3) + 564),
    a2: 0,
    a3: "actionname",
    a4: "Action",
    a5: Wide / 3,
    a6: 0);
  v28 = *(vgui::Panel **)(HIDWORD(v3) + 564);
  LODWORD(v3) = v28->__vftable;
  v29 = vgui::Panel::GetWide(this: v28);
  (*(void (__thiscall **)(_DWORD, int, const char *, const char *, int, _DWORD))(v3 + 844))(
    a1: *(_DWORD *)(HIDWORD(v3) + 564),
    a2: 1,
    a3: "actiontype",
    a4: "Type",
    a5: v29 / 3,
    a6: 0);
  v30 = *(vgui::Panel **)(HIDWORD(v3) + 564);
  LODWORD(v3) = v30->__vftable;
  v31 = vgui::Panel::GetWide(this: v30);
  (*(void (__thiscall **)(_DWORD, int, const char *, const char *, int, _DWORD))(v3 + 844))(
    a1: *(_DWORD *)(HIDWORD(v3) + 564),
    a2: 2,
    a3: "actionstart",
    a4: "Start",
    a5: v31 / 3,
    a6: 0);
  CDemoEditorPanel::PopulateActionList(this: (CDemoEditorPanel *)HIDWORD(v3), a2, a3: v3);
  vgui::Panel::SetVisible(this: (vgui::Panel *)HIDWORD(v3), state: 1);
  vgui::Frame::SetSizeable(this: (vgui::Frame *)HIDWORD(v3), state: false);
  vgui::Frame::SetMoveable(this: (vgui::Frame *)HIDWORD(v3), state: true);
  return (CDemoEditorPanel *)HIDWORD(v3);
}

//------------------------------------------------------------------------------
// Address: 0x1007BAF0
// Name: public: virtual void CDemoEditorPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoEditorPanel::OnCommand(CDemoEditorPanel *this, const char *command)
{
  if ( V_strcasecmp(s1: command, s2: "edit") == 0 )
  {
    CDemoEditorPanel::OnEdit(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "delete") == 0 )
  {
    this->OnDelete(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "save") == 0 )
  {
    demoaction->SaveToFile(this: demoaction);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "Close") == 0 )
  {
    demoaction->SaveToFile(this: demoaction);
LABEL_11:
    this->MarkForDeletion(this);
    this->OnClose(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "cancel") == 0 )
  {
    CDemoEditorPanel::OnRevert(this);
    goto LABEL_11;
  }
  if ( V_strcasecmp(s1: command, s2: "revert") != 0 )
  {
    if ( CBaseDemoAction::TypeForName(name: command) != DEMO_ACTION_UNKNOWN )
      CDemoEditorPanel::CreateNewAction(this, actiontype: command);
    else
      vgui::Frame::OnCommand(this, command);
  }
  else
  {
    CDemoEditorPanel::OnRevert(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AB270
// Name: public: class vgui::Menu __near * vgui::MenuButton::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuButton::GetMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1007AD70
// Name: public: static char const __near * CDemoEditorPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDemoEditorPanel::GetPanelClassName()
{
  return "CDemoEditorPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1007AD80
// Name: public: CNewActionButton::CNewActionButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNewActionButton *__thiscall CNewActionButton::CNewActionButton(
        CNewActionButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::Menu *v5; // eax
  vgui::Menu *v6; // eax
  DEMOACTION i; // edi
  const char *v8; // ebx
  bool HasEditorFactory; // al
  void (__thiscall **texta)(vgui::Menu *, const char *, bool); // [esp+1Ch] [ebp+10h]

  vgui::MenuButton::MenuButton(this, parent, panelName, text);
  this->__vftable = (CNewActionButton_vtbl *)&CNewActionButton::`vftable';
  v5 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v5 != nullptr )
    v6 = vgui::Menu::Menu(this: v5, parent: this, panelName: "DemoEditNewAction");
  else
    v6 = nullptr;
  this->m_pMenu = v6;
  for ( i = DEMO_ACTION_SKIPAHEAD; i < NUM_DEMO_ACTIONS; ++i )
  {
    v8 = CBaseDemoAction::NameForType(actionType: i);
    this->m_pMenu->AddMenuItem(this: this->m_pMenu, a2: v8, a3: v8, a4: parent, a5: nullptr);
    texta = &this->m_pMenu->SetItemEnabled;
    HasEditorFactory = CBaseDemoAction::HasEditorFactory(actionType: i);
    (*texta)(this: this->m_pMenu, a2: v8, a3: HasEditorFactory);
  }
  vgui::Panel::MakePopup(this: this->m_pMenu, showTaskbarIcon: true, disabled: false);
  vgui::MenuButton::SetMenu(this, menu: this->m_pMenu);
  vgui::MenuButton::SetOpenDirection(this, direction: (vgui::Menu::MenuDirection_e)2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007AE60
// Name: public: static char const __near * vgui::MenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MenuButton::GetPanelClassName()
{
  return "MenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x1007AE70
// Name: public: virtual void CDemoEditorPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoEditorPanel::OnTick(CDemoEditorPanel *this)
{
  vgui::Label_vtbl *v2; // edi
  const char *v3; // eax
  const char *v4; // eax
  void (__thiscall *SetEnabled)(vgui::Panel *, bool); // edx
  bool v6; // bl
  vgui::Button_vtbl *v7; // edi
  bool v8; // al
  vgui::Button_vtbl *v9; // edi
  bool v10; // al

  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  v2 = this->m_pCurrentDemo->__vftable;
  v3 = demoaction->GetCurrentDemoFile(this: demoaction);
  v2->SetText(this: this->m_pCurrentDemo, a2: v3);
  v4 = demoaction->GetCurrentDemoFile(this: demoaction);
  SetEnabled = this->m_pNew->SetEnabled;
  if ( *v4 != 0 )
  {
    ((void (__stdcall *)(int))SetEnabled)(a1: 1);
    v6 = demoaction->GetActionCount(this: demoaction) > 0;
    this->m_pEdit->SetEnabled(this: this->m_pEdit, a2: v6);
    this->m_pDelete->SetEnabled(this: this->m_pDelete, a2: v6);
    if ( this->m_pActions != nullptr && this->m_pActions->GetSelectedItemsCount(this: this->m_pActions) != 1 )
    {
      this->m_pEdit->SetEnabled(this: this->m_pEdit, a2: false);
      this->m_pDelete->SetEnabled(this: this->m_pDelete, a2: false);
    }
    v7 = this->m_pSave->__vftable;
    v8 = demoaction->IsDirty(this: demoaction);
    v7->SetEnabled(this: this->m_pSave, a2: v8);
    v9 = this->m_pRevert->__vftable;
    v10 = demoaction->IsDirty(this: demoaction);
    v9->SetEnabled(this: this->m_pRevert, a2: v10);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))SetEnabled)(a1: 0);
    this->m_pEdit->SetEnabled(this: this->m_pEdit, a2: false);
    this->m_pDelete->SetEnabled(this: this->m_pDelete, a2: false);
    this->m_pSave->SetEnabled(this: this->m_pSave, a2: false);
    this->m_pRevert->SetEnabled(this: this->m_pRevert, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007AFE0
// Name: protected: void CDemoEditorPanel::PopulateActionList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDemoEditorPanel::PopulateActionList(CDemoEditorPanel *this@<ecx>, int a2@<ebx>, __int64 a3@<esi:edi>)
{
  int v3; // eax
  int v4; // ebx
  CBaseDemoAction *v5; // esi
  KeyValues *v6; // edi
  char *ActionName; // eax
  KeyValues *v8; // edi
  char *v9; // eax
  const char *v10; // eax
  __int32 v11; // eax
  double StartTime; // st7
  const char *v13; // eax
  int StartTick; // eax
  int count; // [esp+18h] [ebp-8h]

  if ( this->m_pActions != nullptr )
    this->m_pActions->DeleteAllItems(this: this->m_pActions);
  v3 = ((int (__thiscall *)(IDemoActionManager *, int))demoaction->GetActionCount)(a1: demoaction, a2);
  v4 = 0;
  count = v3;
  if ( v3 > 0 )
  {
    while ( 1 )
    {
      v5 = (CBaseDemoAction *)((int (__thiscall *)(IDemoActionManager *, int, _DWORD, _DWORD))demoaction->GetAction)(
                                a1: demoaction,
                                a2: v4,
                                a3,
                                a4: HIDWORD(a3));
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        ActionName = CBaseDemoAction::GetActionName(this: v5);
        v8 = KeyValues::KeyValues(this: v6, setName: "data", firstKey: "actionname", firstValue: ActionName);
      }
      else
      {
        v8 = nullptr;
      }
      v9 = CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)v5);
      v10 = CBaseDemoAction::NameForType(actionType: (DEMOACTION)v9);
      KeyValues::SetString(this: v8, keyName: "actiontype", value: v10);
      v11 = CNetChan::GetSocket(this: v5) - 1;
      if ( v11 == 0 )
        break;
      if ( v11 == 1 )
      {
        StartTime = CBaseDemoAction::GetStartTime(this: v5);
        v13 = va(format: "Time %.3f", StartTime);
LABEL_11:
        KeyValues::SetString(this: v8, keyName: "actionstart", value: v13);
      }
      a3 = 0;
      ((void (__thiscall *)(vgui::ListPanel *, KeyValues *, _DWORD))this->m_pActions->AddItem)(
        a1: this->m_pActions,
        a2: v8,
        a3: 0);
      if ( ++v4 >= count )
        return;
    }
    StartTick = CBaseDemoAction::GetStartTick(this: v5);
    v13 = va(format: "Tick %i", StartTick);
    goto LABEL_11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B120
// Name: public: virtual void vgui::Button::OnHotkey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Button::OnHotkey(vgui::Button *this)
{
  this->DoClick(this);
}

//------------------------------------------------------------------------------
// Address: 0x1007B130
// Name: public: virtual struct vgui::PanelMessageMap __near * CDemoEditorPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDemoEditorPanel::GetMessageMap(CDemoEditorPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDemoEditorPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDemoEditorPanel::GetMessageMap'::`2'::s_pMap;
  `CDemoEditorPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDemoEditorPanel");
  `CDemoEditorPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B160
// Name: public: virtual struct PanelAnimationMap __near * CDemoEditorPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDemoEditorPanel::GetAnimMap(CDemoEditorPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDemoEditorPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1007B170
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDemoEditorPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDemoEditorPanel::GetKBMap(CDemoEditorPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDemoEditorPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDemoEditorPanel::GetKBMap'::`2'::s_pMap;
  `CDemoEditorPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDemoEditorPanel");
  `CDemoEditorPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B1A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuButton::GetMessageMap(vgui::MenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
  `vgui::MenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B1D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuButton::GetAnimMap(vgui::MenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x1007B1E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuButton::GetKBMap(vgui::MenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetKBMap'::`2'::s_pMap;
  `vgui::MenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
  `vgui::MenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007B240
// Name: protected: void CDemoEditorPanel::CreateNewAction(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoEditorPanel::CreateNewAction(CDemoEditorPanel *this, const char *actiontype)
{
  DEMOACTION v3; // eax
  CBaseDemoAction *DemoAction; // esi
  const char *v5; // eax
  char *v6; // eax
  CBaseActionEditDialog *ActionEditor; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  int v10; // [esp-8h] [ebp-10h]

  if ( vgui::PHandle::Get(this: &this->m_hCurrentEditor) == nullptr )
  {
    v3 = CBaseDemoAction::TypeForName(name: actiontype);
    if ( v3 != DEMO_ACTION_UNKNOWN )
    {
      DemoAction = CBaseDemoAction::CreateDemoAction(actionType: v3);
      if ( DemoAction != nullptr )
      {
        v10 = g_nNewActionNumber++;
        v5 = va(format: "Unnamed%i", v10);
        CBaseDemoAction::SetActionName(this: DemoAction, name: v5);
        demoaction->SetDirty(this: demoaction, a2: true);
        v6 = CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)DemoAction);
        ActionEditor = CBaseDemoAction::CreateActionEditor(
                         actionType: (DEMOACTION)v6,
                         parent: this,
                         action: DemoAction,
                         newaction: true);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(
          this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hCurrentEditor,
          pPanel: (CDragDropHelperPanel *)ActionEditor);
        if ( vgui::PHandle::Get(this: &this->m_hCurrentEditor) != nullptr )
        {
          v8 = vgui::PHandle::Get(this: &this->m_hCurrentEditor);
          v8->SetVisible(this: v8, a2: true);
          v9 = vgui::PHandle::Get(this: &this->m_hCurrentEditor);
          vgui::Panel::SetSize(this: v9, wide: 400, tall: 300);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B320
// Name: public: void CDemoEditorPanel::OnVDMChanged(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __usercall CDemoEditorPanel::OnVDMChanged(CDemoEditorPanel *this@<ecx>, int a2@<ebx>, __int64 a3@<esi:edi>)
{
  CDemoEditorPanel::PopulateActionList(this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x1007B330
// Name: protected: void CDemoEditorPanel::OnEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoEditorPanel::OnEdit(CDemoEditorPanel *this)
{
  int v2; // eax
  char *v3; // eax
  CBaseActionEditDialog *ActionEditor; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Tooltip *v7; // [esp-8h] [ebp-10h]

  if ( vgui::PHandle::Get(this: &this->m_hCurrentEditor) == nullptr
    && this->m_pActions->GetSelectedItemsCount(this: this->m_pActions) == 1 )
  {
    v2 = this->m_pActions->GetSelectedItem(this: this->m_pActions, a2: 0);
    if ( v2 != -1 )
    {
      v7 = (vgui::Tooltip *)demoaction->GetAction(this: demoaction, a2: v2);
      v3 = CWaveDataStreamAsync::Source(this: v7);
      ActionEditor = CBaseDemoAction::CreateActionEditor(
                       actionType: (DEMOACTION)v3,
                       parent: this,
                       action: (CBaseDemoAction *)v7,
                       newaction: false);
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hCurrentEditor,
        pPanel: (CDragDropHelperPanel *)ActionEditor);
      if ( vgui::PHandle::Get(this: &this->m_hCurrentEditor) != nullptr )
      {
        v5 = vgui::PHandle::Get(this: &this->m_hCurrentEditor);
        v5->SetVisible(this: v5, a2: true);
        v6 = vgui::PHandle::Get(this: &this->m_hCurrentEditor);
        vgui::Panel::SetSize(this: v6, wide: 400, tall: 300);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007B480
// Name: public: CDemoEditorPanel::CDemoEditorPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CDemoEditorPanel *__userpurge CDemoEditorPanel::CDemoEditorPanel@<eax>(
        CDemoEditorPanel *this@<ecx>,
        int a2@<ebx>,
        vgui::Panel *parent)
{
  __int64 v3; // rdi
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  CNewActionButton *v15; // eax
  CNewActionButton *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  vgui::Button *v19; // eax
  vgui::Button *v20; // eax
  vgui::Label *v21; // eax
  vgui::Label *v22; // eax
  vgui::ListPanel *v23; // eax
  vgui::ListPanel *v24; // eax
  int Tall; // eax
  vgui::Panel *v26; // ecx
  int Wide; // eax
  vgui::Panel *v28; // ecx
  int v29; // eax
  vgui::Panel *v30; // ecx
  int v31; // eax
  int xpos; // [esp+8h] [ebp-8h] BYREF
  int ypos; // [esp+Ch] [ebp-4h] BYREF

  HIDWORD(v3) = this;
  vgui::Frame::Frame(this, parent, panelName: "DemoEditorPanel", showTaskbarIcon: true, bPopup: true);
  *(_DWORD *)HIDWORD(v3) = &CDemoEditorPanel::`vftable';
  if ( `CDemoEditorPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDemoEditorPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDemoEditorPanel");
    v4->pfnClassName = CDemoEditorPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CDemoEditorPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDemoEditorPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDemoEditorPanel");
    v5->pfnClassName = CDemoEditorPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CDemoEditorPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDemoEditorPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDemoEditorPanel");
    v6->pfnClassName = CDemoEditorPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  *(_DWORD *)(HIDWORD(v3) + 568) = -1;
  vgui::Panel::SetSize(this: (vgui::Panel *)HIDWORD(v3), wide: 440, tall: 300);
  vgui::Frame::SetTitle(this: (vgui::Frame *)HIDWORD(v3), title: "Demo Editor", surfaceTitle: true);
  v7 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v7 != nullptr )
    v8 = vgui::Button::Button(
           this: v7,
           parent: (vgui::Panel *)HIDWORD(v3),
           panelName: "DemoEditSave",
           text: "Save",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v8 = nullptr;
  *(_DWORD *)(HIDWORD(v3) + 536) = v8;
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: (vgui::Panel *)HIDWORD(v3),
            panelName: "DemoEditRevert",
            text: "Revert",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  *(_DWORD *)(HIDWORD(v3) + 540) = v10;
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: (vgui::Panel *)HIDWORD(v3),
            panelName: "DemoEditOk",
            text: "OK",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v12 = nullptr;
  *(_DWORD *)(HIDWORD(v3) + 544) = v12;
  v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: (vgui::Panel *)HIDWORD(v3),
            panelName: "DemoEditCancel",
            text: "Cancel",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v14 = nullptr;
  *(_DWORD *)(HIDWORD(v3) + 548) = v14;
  v15 = (CNewActionButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v15 != nullptr )
    v16 = CNewActionButton::CNewActionButton(
            this: v15,
            parent: (vgui::Panel *)HIDWORD(v3),
            panelName: "DemoEditNew",
            text: "New->");
  else
    v16 = nullptr;
  *(_DWORD *)(HIDWORD(v3) + 552) = v16;
  v17 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v17 != nullptr )
    v18 = vgui::Button::Button(
            this: v17,
            parent: (vgui::Panel *)HIDWORD(v3),
            panelName: "DemoEditEdit",
            text: "Edit...",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v18 = nullptr;
  *(_DWORD *)(HIDWORD(v3) + 556) = v18;
  v19 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v19 != nullptr )
    v20 = vgui::Button::Button(
            this: v19,
            parent: (vgui::Panel *)HIDWORD(v3),
            panelName: "DemoEditDelete",
            text: "Delete",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v20 = nullptr;
  *(_DWORD *)(HIDWORD(v3) + 560) = v20;
  v21 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v21 != nullptr )
    v22 = vgui::Label::Label(this: v21, parent: (vgui::Panel *)HIDWORD(v3), panelName: "DemoName", text: defaultValue);
  else
    v22 = nullptr;
  *(_DWORD *)(HIDWORD(v3) + 532) = v22;
  v23 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v23 != nullptr )
    v24 = vgui::ListPanel::ListPanel(this: v23, parent: (vgui::Panel *)HIDWORD(v3), panelName: "DemoActionList");
  else
    v24 = nullptr;
  *(_DWORD *)(HIDWORD(v3) + 564) = v24;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: *(_DWORD *)(HIDWORD(v3) + 72), a3: 0);
  vgui::Frame::LoadControlSettings(
    this: (vgui::Frame *)HIDWORD(v3),
    dialogResourceName: "Resource\\DemoEditorPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::GetPos(this: parent, x: &xpos, y: &ypos);
  Tall = vgui::Panel::GetTall(this: parent);
  ypos += Tall;
  vgui::Panel::SetPos(this: (vgui::Panel *)HIDWORD(v3), x: xpos, y: ypos);
  v26 = *(vgui::Panel **)(HIDWORD(v3) + 564);
  LODWORD(v3) = v26->__vftable;
  Wide = vgui::Panel::GetWide(this: v26);
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, const char *, int, _DWORD))(v3 + 844))(
    a1: *(_DWORD *)(HIDWORD(v3) + 564),
    a2: 0,
    a3: "actionname",
    a4: "Action",
    a5: Wide / 3,
    a6: 0);
  v28 = *(vgui::Panel **)(HIDWORD(v3) + 564);
  LODWORD(v3) = v28->__vftable;
  v29 = vgui::Panel::GetWide(this: v28);
  (*(void (__thiscall **)(_DWORD, int, const char *, const char *, int, _DWORD))(v3 + 844))(
    a1: *(_DWORD *)(HIDWORD(v3) + 564),
    a2: 1,
    a3: "actiontype",
    a4: "Type",
    a5: v29 / 3,
    a6: 0);
  v30 = *(vgui::Panel **)(HIDWORD(v3) + 564);
  LODWORD(v3) = v30->__vftable;
  v31 = vgui::Panel::GetWide(this: v30);
  (*(void (__thiscall **)(_DWORD, int, const char *, const char *, int, _DWORD))(v3 + 844))(
    a1: *(_DWORD *)(HIDWORD(v3) + 564),
    a2: 2,
    a3: "actionstart",
    a4: "Start",
    a5: v31 / 3,
    a6: 0);
  CDemoEditorPanel::PopulateActionList(this: (CDemoEditorPanel *)HIDWORD(v3), a2, a3: v3);
  vgui::Panel::SetVisible(this: (vgui::Panel *)HIDWORD(v3), state: true);
  vgui::Frame::SetSizeable(this: (vgui::Frame *)HIDWORD(v3), state: false);
  vgui::Frame::SetMoveable(this: (vgui::Frame *)HIDWORD(v3), state: true);
  return (CDemoEditorPanel *)HIDWORD(v3);
}

//------------------------------------------------------------------------------
// Address: 0x1007B840
// Name: public: virtual void CDemoEditorPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDemoEditorPanel::OnCommand(CDemoEditorPanel *this, const char *command)
{
  if ( V_strcasecmp(s1: command, s2: "edit") == 0 )
  {
    CDemoEditorPanel::OnEdit(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "delete") == 0 )
  {
    this->OnDelete(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "save") == 0 )
  {
    demoaction->SaveToFile(this: demoaction);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "Close") == 0 )
  {
    demoaction->SaveToFile(this: demoaction);
LABEL_11:
    this->MarkForDeletion(this);
    this->OnClose(this);
    return;
  }
  if ( V_strcasecmp(s1: command, s2: "cancel") == 0 )
  {
    CDemoEditorPanel::OnRevert(this);
    goto LABEL_11;
  }
  if ( V_strcasecmp(s1: command, s2: "revert") != 0 )
  {
    if ( CBaseDemoAction::TypeForName(name: command) != DEMO_ACTION_UNKNOWN )
      CDemoEditorPanel::CreateNewAction(this, actiontype: command);
    else
      vgui::Frame::OnCommand(this, command);
  }
  else
  {
    CDemoEditorPanel::OnRevert(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C9660
// Name: public: class vgui::Menu __near * vgui::MenuButton::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuButton::GetMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1031E0A0
// Name: _dynamic_initializer_for__editor_toggle__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__editor_toggle__()
{
  ConCommand::ConCommand(
    this: &editor_toggle,
    pName: "editor_toggle",
    callback: EditorToggle_f,
    pHelpString: "Disables the simulation and returns focus to the editor",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__editor_toggle__);
}

//------------------------------------------------------------------------------
// Address: 0x10326C30
// Name: _dynamic_atexit_destructor_for__editor_toggle__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__editor_toggle__()
{
  ConCommand::~ConCommand(this: &editor_toggle);
}

//------------------------------------------------------------------------------
// Address: 0x1031E0D0
// Name: _dynamic_initializer_for__g_TextModeLine__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TextModeLine__()
{
  g_TextModeLine.m_Size = 0;
  g_TextModeLine.m_pElements = g_TextModeLine.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__g_TextModeLine__);
}

//------------------------------------------------------------------------------
// Address: 0x1031E120
// Name: _dynamic_initializer_for____g_CreateCEngineAPIIEngineAPI_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCEngineAPIIEngineAPI_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCEngineAPIIEngineAPI_reg,
           fn: _CreateCEngineAPIIEngineAPI_interface,
           pName: "VENGINE_LAUNCHER_API_VERSION004");
}

//------------------------------------------------------------------------------
// Address: 0x1031E140
// Name: _dynamic_initializer_for__reload_vjobs_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__reload_vjobs_command__()
{
  ConCommand::ConCommand(
    this: &reload_vjobs_command,
    pName: "reload_vjobs",
    callback: reload_vjobs,
    pHelpString: "reload vjobs module",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__reload_vjobs_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10326C40
// Name: _dynamic_atexit_destructor_for__reload_vjobs_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__reload_vjobs_command__()
{
  ConCommand::~ConCommand(this: &reload_vjobs_command);
}

} // namespace engine_xlsp
