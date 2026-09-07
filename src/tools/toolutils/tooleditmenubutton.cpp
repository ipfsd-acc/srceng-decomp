// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tools/toolutils/tooleditmenubutton.cpp
// Functions: 7
// ============================================================

#include "tools\toolutils\tooleditmenubutton.h"

//------------------------------------------------------------------------------
// Address: 0x102C19E0
// Name: public: static char const __near * CToolEditMenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CToolEditMenuButton::GetPanelClassName()
{
  return "CToolEditMenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x102C19F0
// Name: public: virtual void CToolEditMenuButton::OnShowMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolEditMenuButton::OnShowMenu(CToolEditMenuButton *this, vgui::Menu *menu)
{
  int v3; // ebx
  bool v4; // zf
  void (__thiscall *SetItemEnabled)(vgui::Menu *, int, bool); // eax
  const wchar_t *v6; // edi
  vgui::ILocalize_vtbl *v7; // ebx
  int v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  int v13; // ebx
  bool v14; // al
  vgui::Menu *m_pMenu; // ecx
  const wchar_t *v16; // edi
  vgui::ILocalize_vtbl *v17; // ebx
  int v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // eax
  KeyValues *v22; // eax
  KeyValues *v23; // eax
  KeyValues *v24; // eax
  int v25; // edi
  bool v26; // al
  vgui::Menu *v27; // esi
  void (__thiscall *v28)(vgui::Menu *, int, bool); // eax
  char sz[512]; // [esp+Ch] [ebp-808h] BYREF
  wchar_t buf[512]; // [esp+20Ch] [ebp-608h] BYREF
  wchar_t desc[256]; // [esp+60Ch] [ebp-208h] BYREF
  CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t search; // [esp+80Ch] [ebp-8h] BYREF
  int id; // [esp+81Ch] [ebp+8h]
  int ida; // [esp+81Ch] [ebp+8h]

  CToolMenuButton::OnShowMenu(this, menu);
  search.elem = (CToolMenuButton::MenuItem_t)-65536;
  search.key = "undo";
  v3 = CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Items.m_Elements.m_Tree,
         &search);
  id = v3;
  v4 = !g_pDataModel->CanUndo(this: g_pDataModel);
  SetItemEnabled = this->CToolMenuButton::m_pMenu->SetItemEnabled;
  if ( v4 )
  {
    ((void (__stdcall *)(int, _DWORD))SetItemEnabled)(a1: v3, a2: 0);
    goto LABEL_8;
  }
  ((void (__stdcall *)(int, int))SetItemEnabled)(a1: v3, a2: 1);
  v6 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "ToolEditUndoStr");
  if ( v6 == nullptr )
  {
LABEL_8:
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "Command", firstKey: "command", firstValue: "OnUndo");
    else
      v12 = nullptr;
    this->CToolMenuButton::m_pMenu->UpdateMenuItem(
      this: this->CToolMenuButton::m_pMenu,
      a2: v3,
      a3: "#ToolEditUndo",
      a4: v12,
      a5: nullptr);
    goto LABEL_12;
  }
  v7 = g_pVGuiLocalize->__vftable;
  v8 = ((int (__thiscall *)(IDataModel *, wchar_t *, int))g_pDataModel->GetUndoDesc)(
         a1: g_pDataModel,
         a2: desc,
         a3: 512);
  ((void (__thiscall *)(vgui::ILocalize *, int))v7->ConvertANSIToUnicode)(a1: g_pVGuiLocalize, a2: v8);
  g_pVGuiLocalize->ConstructString_3(this: g_pVGuiLocalize, a2: buf, a3: 1024, a4: v6, a5: 1, desc);
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: "Command", firstKey: "command", firstValue: "OnUndo");
  else
    v10 = nullptr;
  this->CToolMenuButton::m_pMenu->UpdateMenuItem(
    this: this->CToolMenuButton::m_pMenu,
    a2: id,
    a3: buf,
    a4: v10,
    a5: nullptr);
LABEL_12:
  search.elem = (CToolMenuButton::MenuItem_t)-65536;
  search.key = "redo";
  v13 = CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
          this: &this->m_Items.m_Elements.m_Tree,
          &search);
  ida = v13;
  v14 = g_pDataModel->CanRedo(this: g_pDataModel);
  m_pMenu = this->CToolMenuButton::m_pMenu;
  if ( v14 )
  {
    m_pMenu->SetItemEnabled(this: m_pMenu, a2: v13, a3: true);
    v16 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "ToolEditRedoStr");
    if ( v16 != nullptr )
    {
      v17 = g_pVGuiLocalize->__vftable;
      v18 = ((int (__thiscall *)(IDataModel *, wchar_t *, int))g_pDataModel->GetRedoDesc)(
              a1: g_pDataModel,
              a2: desc,
              a3: 512);
      ((void (__thiscall *)(vgui::ILocalize *, int))v17->ConvertANSIToUnicode)(a1: g_pVGuiLocalize, a2: v18);
      g_pVGuiLocalize->ConstructString_3(this: g_pVGuiLocalize, a2: buf, a3: 1024, a4: v16, a5: 1, desc);
      v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v19 != nullptr )
        v20 = KeyValues::KeyValues(this: v19, setName: "Command", firstKey: "command", firstValue: "OnRedo");
      else
        v20 = nullptr;
      this->CToolMenuButton::m_pMenu->UpdateMenuItem(
        this: this->CToolMenuButton::m_pMenu,
        a2: ida,
        a3: buf,
        a4: v20,
        a5: nullptr);
    }
    else
    {
      v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v21 != nullptr )
        v22 = KeyValues::KeyValues(this: v21, setName: "Command", firstKey: "command", firstValue: "OnRedo");
      else
        v22 = nullptr;
      this->CToolMenuButton::m_pMenu->UpdateMenuItem(
        this: this->CToolMenuButton::m_pMenu,
        a2: v13,
        a3: sz,
        a4: v22,
        a5: nullptr);
    }
  }
  else
  {
    m_pMenu->SetItemEnabled(this: m_pMenu, a2: v13, a3: false);
    v23 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v23 != nullptr )
      v24 = KeyValues::KeyValues(this: v23, setName: "Command", firstKey: "command", firstValue: "OnRedo");
    else
      v24 = nullptr;
    this->CToolMenuButton::m_pMenu->UpdateMenuItem(
      this: this->CToolMenuButton::m_pMenu,
      a2: v13,
      a3: "#ToolEditRedo",
      a4: v24,
      a5: nullptr);
  }
  search.elem = (CToolMenuButton::MenuItem_t)-65536;
  search.key = "describe";
  v25 = CUtlRBTree<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CToolMenuButton::MenuItem_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
          this: &this->m_Items.m_Elements.m_Tree,
          &search);
  v26 = g_pDataModel->CanUndo(this: g_pDataModel);
  v27 = this->CToolMenuButton::m_pMenu;
  v4 = !v26;
  v28 = v27->SetItemEnabled;
  if ( v4 )
    v28(this: v27, a2: v25, a3: false);
  else
    v28(this: v27, a2: v25, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x102C1D50
// Name: public: CToolEditMenuButton::CToolEditMenuButton(class vgui::Panel __near *,char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CToolEditMenuButton *__thiscall CToolEditMenuButton::CToolEditMenuButton(
        CToolEditMenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        vgui::Panel *pActionSignalTarget)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // eax

  CToolMenuButton::CToolMenuButton(this, parent, panelName, text, actionTarget: pActionSignalTarget);
  this->__vftable = (CToolEditMenuButton_vtbl *)&CToolEditMenuButton::`vftable';
  if ( `CToolEditMenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `CToolEditMenuButton::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CToolEditMenuButton");
    v6->pfnClassName = CToolEditMenuButton::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "CToolMenuButton");
  }
  if ( `CToolEditMenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CToolEditMenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CToolEditMenuButton");
    v7->pfnClassName = CToolEditMenuButton::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "CToolMenuButton");
  }
  if ( `CToolEditMenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CToolEditMenuButton::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CToolEditMenuButton");
    v8->pfnClassName = CToolEditMenuButton::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CToolMenuButton");
  }
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: "Command", firstKey: "command", firstValue: "OnUndo");
  else
    v10 = nullptr;
  CToolMenuButton::AddMenuItem(
    this,
    itemName: "undo",
    itemText: "#ToolEditUndo",
    message: v10,
    target: pActionSignalTarget,
    userData: nullptr,
    kbcommandname: "undo");
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "Command", firstKey: "command", firstValue: "OnRedo");
  else
    v12 = nullptr;
  CToolMenuButton::AddMenuItem(
    this,
    itemName: "redo",
    itemText: "#ToolEditRedo",
    message: v12,
    target: pActionSignalTarget,
    userData: nullptr,
    kbcommandname: "redo");
  CToolMenuButton::AddSeparator(this);
  v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v13 != nullptr )
    v14 = KeyValues::KeyValues(this: v13, setName: "Command", firstKey: "command", firstValue: "OnDescribeUndo");
  else
    v14 = nullptr;
  CToolMenuButton::AddMenuItem(
    this,
    itemName: "describe",
    itemText: "#ToolEditDescribeUndo",
    message: v14,
    target: pActionSignalTarget,
    userData: nullptr,
    kbcommandname: nullptr);
  v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v15 != nullptr )
    v16 = KeyValues::KeyValues(this: v15, setName: "Command", firstKey: "command", firstValue: "OnWipeUndo");
  else
    v16 = nullptr;
  CToolMenuButton::AddMenuItem(
    this,
    itemName: "wipeundo",
    itemText: "#ToolEditWipeUndo",
    message: v16,
    target: pActionSignalTarget,
    userData: nullptr,
    kbcommandname: nullptr);
  CToolMenuButton::AddSeparator(this);
  v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v17 != nullptr )
    v18 = KeyValues::KeyValues(this: v17, setName: "OnEditKeyBindings");
  else
    v18 = nullptr;
  CToolMenuButton::AddMenuItem(
    this,
    itemName: "editkeybindings",
    itemText: "#BxEditKeyBindings",
    message: v18,
    target: pActionSignalTarget,
    userData: nullptr,
    kbcommandname: "editkeybindings");
  vgui::MenuButton::SetMenu(this, menu: this->CToolMenuButton::m_pMenu);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C1F70
// Name: public: virtual struct vgui::PanelMessageMap __near * CToolEditMenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CToolEditMenuButton::GetMessageMap(CToolEditMenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CToolEditMenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CToolEditMenuButton::GetMessageMap'::`2'::s_pMap;
  `CToolEditMenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CToolEditMenuButton");
  `CToolEditMenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C1FA0
// Name: public: virtual struct PanelAnimationMap __near * CToolEditMenuButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CToolEditMenuButton::GetAnimMap(CToolEditMenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CToolEditMenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x102C1FB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CToolEditMenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CToolEditMenuButton::GetKBMap(CToolEditMenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CToolEditMenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CToolEditMenuButton::GetKBMap'::`2'::s_pMap;
  `CToolEditMenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CToolEditMenuButton");
  `CToolEditMenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C1FE0
// Name: class CToolMenuButton __near * CreateToolEditMenuButton(class vgui::Panel __near *,char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CToolEditMenuButton *__cdecl CreateToolEditMenuButton(
        vgui::Panel *parent,
        const char *panelName,
        const char *text,
        vgui::Panel *pActionTarget)
{
  CToolEditMenuButton *v4; // eax

  v4 = (CToolEditMenuButton *)operator new(nSize: 0x240u);
  if ( v4 != nullptr )
    return CToolEditMenuButton::CToolEditMenuButton(
             this: v4,
             parent,
             panelName,
             text,
             pActionSignalTarget: pActionTarget);
  else
    return nullptr;
}
