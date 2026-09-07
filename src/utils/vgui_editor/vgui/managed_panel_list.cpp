// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vgui_editor/vgui/managed_panel_list.cpp
// Functions: 9
// ============================================================

#include "utils\vgui_editor\vgui\managed_panel_list.h"

//------------------------------------------------------------------------------
// Address: 0x0040A480
// Name: public: static char const __near * CManaged_Panel_List::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CManaged_Panel_List::GetPanelClassName()
{
  return "CManaged_Panel_List";
}

//------------------------------------------------------------------------------
// Address: 0x0040A490
// Name: public: virtual struct vgui::PanelMessageMap __near * CManaged_Panel_List::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CManaged_Panel_List::GetMessageMap(CManaged_Panel_List *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CManaged_Panel_List::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CManaged_Panel_List::GetMessageMap'::`2'::s_pMap;
  `CManaged_Panel_List::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CManaged_Panel_List");
  `CManaged_Panel_List::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040A4C0
// Name: public: virtual struct PanelAnimationMap __near * CManaged_Panel_List::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CManaged_Panel_List::GetAnimMap(CManaged_Panel_List *this)
{
  return FindOrAddPanelAnimationMap(className: "CManaged_Panel_List");
}

//------------------------------------------------------------------------------
// Address: 0x0040A4D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CManaged_Panel_List::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CManaged_Panel_List::GetKBMap(CManaged_Panel_List *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CManaged_Panel_List::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CManaged_Panel_List::GetKBMap'::`2'::s_pMap;
  `CManaged_Panel_List::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CManaged_Panel_List");
  `CManaged_Panel_List::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040A500
// Name: public: CManaged_Panel_List::CManaged_Panel_List(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CManaged_Panel_List *__thiscall CManaged_Panel_List::CManaged_Panel_List(
        CManaged_Panel_List *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Label *v7; // eax
  vgui::Label *v8; // eax
  vgui::PanelListPanel *v9; // eax
  vgui::PanelListPanel *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (CManaged_Panel_List_vtbl *)&CManaged_Panel_List::`vftable';
  if ( `CManaged_Panel_List::ChainToMap'::`2'::chained == 0 )
  {
    `CManaged_Panel_List::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CManaged_Panel_List");
    v4->pfnClassName = CManaged_Panel_List::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CManaged_Panel_List::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CManaged_Panel_List::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CManaged_Panel_List");
    v5->pfnClassName = CManaged_Panel_List::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CManaged_Panel_List::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CManaged_Panel_List::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CManaged_Panel_List");
    v6->pfnClassName = CManaged_Panel_List::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  v7 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v7 != nullptr )
    v8 = vgui::Label::Label(this: v7, parent: this, panelName: "Title", text: "Managed Panels");
  else
    v8 = nullptr;
  this->m_pTitle = v8;
  v9 = (vgui::PanelListPanel *)operator new(nSize: 0x1ACu);
  if ( v9 != nullptr )
    v10 = vgui::PanelListPanel::PanelListPanel(this: v9, parent: this, panelName: "PanelList");
  else
    v10 = nullptr;
  this->m_pPanelList = v10;
  vgui::PanelListPanel::SetFirstColumnWidth(this: v10, width: 0);
  vgui::PanelListPanel::SetVerticalBufferPixels(this: this->m_pPanelList, buffer: 0);
  v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "NewButton",
            text: "+ New Managed Panel",
            pActionSignalTarget: this,
            pCmd: "NewPanel");
  else
    v12 = nullptr;
  this->m_pNewButton = v12;
  this->m_pEditorDialog = (CVGUI_Src_Editor_Dialog *)__RTDynamicCast(
                                                       inptr: parent,
                                                       VfDelta: 0,
                                                       SrcType: &vgui::Panel `RTTI Type Descriptor',
                                                       TargetType: &CVGUI_Src_Editor_Dialog `RTTI Type Descriptor',
                                                       isReference: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040A6B0
// Name: public: virtual void CManaged_Panel_List::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManaged_Panel_List::ApplySchemeSettings(CManaged_Panel_List *this, vgui::IScheme *pScheme)
{
  vgui::TextEntry **v2; // esi
  void *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  vgui::IScheme_vtbl *v6; // edx
  int v7; // eax
  vgui::IScheme_vtbl *v8; // edx
  int v9; // eax
  vgui::IScheme_vtbl *v10; // edx
  int v11; // eax
  vgui::IScheme_vtbl *v12; // edx
  int v13; // eax
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // edx
  _DWORD *v15; // eax
  void (__thiscall *v16)(_DWORD *, int, int); // edx
  char v17[4]; // [esp+8h] [ebp-28h] BYREF
  int nPanelCount; // [esp+Ch] [ebp-24h]
  void (__thiscall **v19)(_DWORD *, int); // [esp+10h] [ebp-20h]
  CManaged_Panel_List *v20; // [esp+14h] [ebp-1Ch]
  int i; // [esp+18h] [ebp-18h]
  int v22; // [esp+1Ch] [ebp-14h]
  int v23; // [esp+20h] [ebp-10h]
  int v24; // [esp+24h] [ebp-Ch]
  int v25; // [esp+28h] [ebp-8h]
  int v26; // [esp+2Ch] [ebp-4h]

  v2 = (vgui::TextEntry **)this;
  v20 = this;
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  (*(void (__thiscall **)(vgui::TextEntry **, const char *, _DWORD, _DWORD, _DWORD))&(*v2)->m_szComposition[151])(
    a1: v2,
    a2: "resource/UI/vgui_editor/ManagedPanelList.res",
    a3: 0,
    a4: 0,
    a5: 0);
  nPanelCount = vgui::PanelListPanel::GetItemCount(this: v2[96]);
  i = 0;
  if ( nPanelCount > 0 )
  {
    while ( 1 )
    {
      v3 = (void *)((int (__thiscall *)(vgui::TextEntry *, int))v2[96]->GetText)(a1: v2[96], a2: i);
      v4 = __RTDynamicCast(
             inptr: v3,
             VfDelta: 0,
             SrcType: &vgui::Panel `RTTI Type Descriptor',
             TargetType: &vgui::Button `RTTI Type Descriptor',
             isReference: 0);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v6 = pScheme->__vftable;
        v19 = (void (__thiscall **)(_DWORD *, int))(*v4 + 896);
        v7 = v6->GetFont(this: pScheme, a2: "DefaultSmall", a3: false);
        (*v19)(a1: v5, a2: v7);
        v8 = pScheme->__vftable;
        v19 = (void (__thiscall **)(_DWORD *, int))(*v5 + 1108);
        v9 = (int)v8->GetBorder(this: pScheme, a2: "NoBorder");
        (*v19)(a1: v5, a2: v9);
        v10 = pScheme->__vftable;
        v19 = (void (__thiscall **)(_DWORD *, int))(*v5 + 1112);
        v11 = (int)v10->GetBorder(this: pScheme, a2: "NoBorder");
        (*v19)(a1: v5, a2: v11);
        v12 = pScheme->__vftable;
        v19 = (void (__thiscall **)(_DWORD *, int))(*v5 + 1116);
        v13 = (int)v12->GetBorder(this: pScheme, a2: "NoBorder");
        (*v19)(a1: v5, a2: v13);
        GetColor = pScheme->GetColor;
        v19 = (void (__thiscall **)(_DWORD *, int))(*v5 + 1084);
        v26 = 0;
        v15 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, char *, const char *, int))GetColor)(
                          a1: pScheme,
                          a2: v17,
                          a3: "ControlText",
                          a4: -1);
        ((void (__thiscall *)(_DWORD *, _DWORD, int))*v19)(a1: v5, a2: *v15, a3: v26);
        v25 = -1069531072;
        v24 = -1;
        (*(void (__thiscall **)(_DWORD *, int, int))(*v5 + 1088))(a1: v5, a2: -1, a3: -1069531072);
        v16 = *(void (__thiscall **)(_DWORD *, int, int))(*v5 + 1092);
        v23 = 6310465;
        v22 = -16711681;
        v16(a1: v5, a2: -16711681, a3: 6310465);
      }
      if ( ++i >= nPanelCount )
        break;
      v2 = (vgui::TextEntry **)v20;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A870
// Name: public: virtual void CManaged_Panel_List::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManaged_Panel_List::OnCommand(CManaged_Panel_List *this, const char *command)
{
  CNew_Panel_Dialog *v3; // esi
  vgui::Panel *v4; // eax
  CNew_Panel_Dialog *v5; // eax
  int v6; // esi

  if ( _V_stricmp(s1: command, s2: "NewPanel") != 0 )
  {
    v6 = atoi(nptr: command);
    if ( v6 >= 0 && v6 < VGUI_Src_Editor()->m_ManagedPanels.m_Size )
      CVGUI_Src_Editor_Dialog::ShowChildList(this: this->m_pEditorDialog, nManagedPanel: v6);
  }
  else
  {
    v3 = (CNew_Panel_Dialog *)operator new(nSize: 0x22Cu);
    if ( v3 != nullptr )
    {
      v4 = this->GetParent(this);
      v5 = CNew_Panel_Dialog::CNew_Panel_Dialog(this: v3, parent: v4, name: "NewPanelDialog");
      v5->Activate(this: v5);
    }
    else
    {
      (*(void (__thiscall **)(_DWORD))(MEMORY[0] + 952))(a1: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A910
// Name: public: void CManaged_Panel_List::UpdateList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CManaged_Panel_List::UpdateList(CManaged_Panel_List *this)
{
  int v2; // esi
  vgui::Button *v3; // eax
  vgui::Button *v4; // eax
  vgui::Panel *v5; // eax
  void *v6; // edi
  CVGUI_Src_Editor *v7; // eax
  char buffer[256]; // [esp+8h] [ebp-108h] BYREF
  int nPanelCount; // [esp+108h] [ebp-8h]
  bool bAdded; // [esp+10Fh] [ebp-1h]

  v2 = 0;
  nPanelCount = VGUI_Src_Editor()->m_ManagedPanels.m_Size;
  bAdded = false;
  if ( nPanelCount > 0 )
  {
    while ( 1 )
    {
      if ( v2 >= vgui::PanelListPanel::GetItemCount(this: (vgui::TextEntry *)this->m_pPanelList) )
      {
        V_snprintf(pDest: buffer, maxLen: 256, pFormat: "%d", v2);
        v3 = (vgui::Button *)operator new(nSize: 0x1F4u);
        if ( v3 != nullptr )
          v4 = vgui::Button::Button(
                 this: v3,
                 parent: this,
                 panelName: buffer,
                 text: &defaultValue,
                 pActionSignalTarget: this,
                 pCmd: buffer);
        else
          v4 = nullptr;
        this->m_pPanelList->AddItem(this: this->m_pPanelList, a2: nullptr, a3: v4);
      }
      v5 = this->m_pPanelList->GetItemPanel(this: this->m_pPanelList, a2: v2);
      v6 = __RTDynamicCast(
             inptr: v5,
             VfDelta: 0,
             SrcType: &vgui::Panel `RTTI Type Descriptor',
             TargetType: &vgui::Button `RTTI Type Descriptor',
             isReference: 0);
      if ( v6 == nullptr )
        break;
      v7 = VGUI_Src_Editor();
      (*(void (__thiscall **)(void *, CManaged_Panel_Data *))(*(_DWORD *)v6 + 848))(
        a1: v6,
        a2: v7->m_ManagedPanels.m_Memory.m_pMemory[v2++]);
      bAdded = true;
      if ( v2 >= nPanelCount )
        goto LABEL_11;
    }
    if ( !bAdded )
      return;
LABEL_11:
    this->InvalidateLayout(this, a2: true, a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040AA20
// Name: public: virtual void CManaged_Panel_List::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CManaged_Panel_List::OnThink(CManaged_Panel_List *this)
{
  CManaged_Panel_List::UpdateList(this);
}
