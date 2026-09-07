// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vgui_editor/vgui/res_child_list.cpp
// Functions: 10
// ============================================================

#include "utils\vgui_editor\vgui\res_child_list.h"

//------------------------------------------------------------------------------
// Address: 0x0040B2E0
// Name: public: static char const __near * CRes_Child_List::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CRes_Child_List::GetPanelClassName()
{
  return "CRes_Child_List";
}

//------------------------------------------------------------------------------
// Address: 0x0040B2F0
// Name: public: void CRes_Child_List::UpdateList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRes_Child_List::UpdateList(CRes_Child_List *this)
{
  CRes_Child_List *v1; // esi
  KeyValues *m_pResKeys; // ecx
  int v3; // edi
  KeyValues *FirstSubKey; // ebx
  vgui::Button *v5; // eax
  vgui::Button *v6; // eax
  vgui::Panel *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  int v10; // esi
  const char *String; // eax
  KeyValues *NextKey; // eax
  char buffer[256]; // [esp+4h] [ebp-10Ch] BYREF
  CRes_Child_List *v14; // [esp+104h] [ebp-Ch]
  int i; // [esp+108h] [ebp-8h]
  bool bAdded; // [esp+10Fh] [ebp-1h]

  v1 = this;
  m_pResKeys = this->m_pResKeys;
  v14 = v1;
  if ( m_pResKeys != nullptr )
  {
    v3 = 0;
    bAdded = false;
    i = 0;
    FirstSubKey = KeyValues::GetFirstSubKey(this: m_pResKeys);
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        if ( v3 >= vgui::PanelListPanel::GetItemCount(this: (vgui::TextEntry *)v1->m_pPanelList) )
        {
          V_snprintf(pDest: buffer, maxLen: 256, pFormat: "%d", v3);
          v5 = (vgui::Button *)operator new(nSize: 0x1F4u);
          if ( v5 != nullptr )
            v6 = vgui::Button::Button(
                   this: v5,
                   parent: v1,
                   panelName: buffer,
                   text: &defaultValue,
                   pActionSignalTarget: v1,
                   pCmd: buffer);
          else
            v6 = nullptr;
          v1->m_pPanelList->AddItem(this: v1->m_pPanelList, a2: nullptr, a3: v6);
        }
        v7 = v1->m_pPanelList->GetItemPanel(this: v1->m_pPanelList, a2: v3);
        v8 = __RTDynamicCast(
               inptr: v7,
               VfDelta: 0,
               SrcType: &vgui::Panel `RTTI Type Descriptor',
               TargetType: &vgui::Button `RTTI Type Descriptor',
               isReference: 0);
        v9 = v8;
        if ( v8 == nullptr )
          break;
        v10 = *v8;
        String = KeyValues::GetString(this: FirstSubKey, keyName: "fieldName", defaultValue: &defaultValue);
        (*(void (__thiscall **)(_DWORD *, const char *))(v10 + 848))(a1: v9, a2: String);
        ++i;
        bAdded = true;
        NextKey = KeyValues::GetNextKey(this: FirstSubKey);
        v1 = v14;
        FirstSubKey = NextKey;
        if ( NextKey == nullptr )
          goto LABEL_14;
        v3 = i;
      }
      if ( !bAdded )
        return;
LABEL_14:
      v1->InvalidateLayout(this: v1, a2: true, a3: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B420
// Name: public: virtual void CRes_Child_List::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRes_Child_List::OnCommand(CRes_Child_List *this, const char *command)
{
  int v3; // edi
  int v4; // esi
  KeyValues *FirstSubKey; // eax

  v3 = atoi(nptr: command);
  if ( v3 >= 0 && v3 < vgui::PanelListPanel::GetItemCount(this: (vgui::TextEntry *)this->m_pPanelList) )
  {
    v4 = 0;
    FirstSubKey = KeyValues::GetFirstSubKey(this: this->m_pResKeys);
    if ( FirstSubKey != nullptr )
    {
      while ( v4 != v3 )
      {
        ++v4;
        FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
        if ( FirstSubKey == nullptr )
          return;
      }
      CVGUI_Src_Editor_Dialog::StartEditingChildKeys(this: this->m_pEditorDialog, pChildResKeys: FirstSubKey);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B490
// Name: public: void CRes_Child_List::SetKeys(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRes_Child_List::SetKeys(CRes_Child_List *this, KeyValues *pResKeys)
{
  this->m_pResKeys = pResKeys;
}

//------------------------------------------------------------------------------
// Address: 0x0040B4A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CRes_Child_List::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CRes_Child_List::GetMessageMap(CRes_Child_List *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CRes_Child_List::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CRes_Child_List::GetMessageMap'::`2'::s_pMap;
  `CRes_Child_List::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CRes_Child_List");
  `CRes_Child_List::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040B4D0
// Name: public: virtual struct PanelAnimationMap __near * CRes_Child_List::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CRes_Child_List::GetAnimMap(CRes_Child_List *this)
{
  return FindOrAddPanelAnimationMap(className: "CRes_Child_List");
}

//------------------------------------------------------------------------------
// Address: 0x0040B4E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CRes_Child_List::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CRes_Child_List::GetKBMap(CRes_Child_List *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CRes_Child_List::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CRes_Child_List::GetKBMap'::`2'::s_pMap;
  `CRes_Child_List::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CRes_Child_List");
  `CRes_Child_List::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040B510
// Name: public: CRes_Child_List::CRes_Child_List(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CRes_Child_List *__thiscall CRes_Child_List::CRes_Child_List(
        CRes_Child_List *this,
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

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (CRes_Child_List_vtbl *)&CRes_Child_List::`vftable';
  if ( `CRes_Child_List::ChainToMap'::`2'::chained == 0 )
  {
    `CRes_Child_List::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CRes_Child_List");
    v4->pfnClassName = CRes_Child_List::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CRes_Child_List::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CRes_Child_List::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CRes_Child_List");
    v5->pfnClassName = CRes_Child_List::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CRes_Child_List::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CRes_Child_List::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CRes_Child_List");
    v6->pfnClassName = CRes_Child_List::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  v7 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v7 != nullptr )
    v8 = vgui::Label::Label(this: v7, parent: this, panelName: "Title", text: "Panels in .res file:");
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
  this->m_pEditorDialog = (CVGUI_Src_Editor_Dialog *)__RTDynamicCast(
                                                       inptr: parent,
                                                       VfDelta: 0,
                                                       SrcType: &vgui::Panel `RTTI Type Descriptor',
                                                       TargetType: &CVGUI_Src_Editor_Dialog `RTTI Type Descriptor',
                                                       isReference: 0);
  this->m_pResKeys = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040B6A0
// Name: public: virtual void CRes_Child_List::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CRes_Child_List::OnThink(CRes_Child_List *this)
{
  CRes_Child_List::UpdateList(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040B6B0
// Name: public: virtual void CRes_Child_List::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRes_Child_List::ApplySchemeSettings(CRes_Child_List *this, vgui::IScheme *pScheme)
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
  CRes_Child_List *v20; // [esp+14h] [ebp-1Ch]
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
    a2: "resource/UI/vgui_editor/ResChildList.res",
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
