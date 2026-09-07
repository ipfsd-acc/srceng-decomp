// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_pluginhelpers.cpp
// Functions: 47
// ============================================================

#include "engine\cl_pluginhelpers.h"

//------------------------------------------------------------------------------
// Address: 0x1008D420
// Name: public: static char const __near * CPluginUIManager::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPluginUIManager::GetPanelClassName()
{
  return "CPluginUIManager";
}

//------------------------------------------------------------------------------
// Address: 0x1008D430
// Name: public: static char const __near * CPluginMenu::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPluginMenu::GetPanelClassName()
{
  return "CPluginMenu";
}

//------------------------------------------------------------------------------
// Address: 0x1008D440
// Name: public: void CPluginMenu::Show(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginMenu::Show(CPluginMenu *this, KeyValues *kv)
{
  CPluginMenu *v2; // edi
  vgui::Panel *ChildByName; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  int v6; // ebx
  const wchar_t *WString; // eax
  int j; // esi
  vgui::Panel *Child; // eax
  void *v10; // eax
  KeyValues *FirstTrueSubKey; // ebx
  vgui::Panel *v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // esi
  int v15; // edi
  const wchar_t *v16; // eax
  int v17; // edi
  const char *String; // eax
  KeyValues *NextTrueSubKey; // eax
  char controlName[64]; // [esp+Ch] [ebp-48h] BYREF
  CPluginMenu *v21; // [esp+4Ch] [ebp-8h]
  int i; // [esp+50h] [ebp-4h]

  v2 = this;
  v21 = this;
  ChildByName = vgui::Panel::FindChildByName(this, childName: "Text", recurseDown: false);
  v4 = __RTDynamicCast(
         inptr: ChildByName,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::Label `RTTI Type Descriptor',
         isReference: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v6 = *v4;
    WString = KeyValues::GetWString(this: kv, keyName: "msg", defaultValue: &wszText);
    (*(void (__thiscall **)(_DWORD *, const wchar_t *, _DWORD))(v6 + 844))(a1: v5, a2: WString, a3: 0);
  }
  for ( j = 0; j < vgui::Panel::GetChildCount(this: v2); ++j )
  {
    Child = vgui::Panel::GetChild(this: v2, index: j);
    v10 = __RTDynamicCast(
            inptr: Child,
            VfDelta: 0,
            SrcType: &vgui::Panel `RTTI Type Descriptor',
            TargetType: &vgui::Button `RTTI Type Descriptor',
            isReference: 0);
    if ( v10 != nullptr )
      (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v10 + 132))(a1: v10, a2: 0);
  }
  i = 1;
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: kv);
  if ( FirstTrueSubKey != nullptr )
  {
    do
    {
      V_snprintf(pDest: controlName, maxLen: 64, pFormat: "option%i", i);
      v12 = vgui::Panel::FindChildByName(this: v2, childName: controlName, recurseDown: true);
      v13 = __RTDynamicCast(
              inptr: v12,
              VfDelta: 0,
              SrcType: &vgui::Panel `RTTI Type Descriptor',
              TargetType: &vgui::Button `RTTI Type Descriptor',
              isReference: 0);
      v14 = v13;
      if ( v13 != nullptr )
      {
        v15 = *v13;
        v16 = KeyValues::GetWString(this: FirstTrueSubKey, keyName: "msg", defaultValue: &wszText);
        (*(void (__thiscall **)(_DWORD *, const wchar_t *, _DWORD))(v15 + 844))(a1: v14, a2: v16, a3: 0);
        v17 = *v14;
        String = KeyValues::GetString(this: FirstTrueSubKey, keyName: "command", defaultValue: defaultValue);
        (*(void (__thiscall **)(_DWORD *, const char *))(v17 + 1124))(a1: v14, a2: String);
        (*(void (__thiscall **)(_DWORD *, int))(*v14 + 132))(a1: v14, a2: 1);
        v2 = v21;
      }
      NextTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      ++i;
      FirstTrueSubKey = NextTrueSubKey;
    }
    while ( NextTrueSubKey != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D5C0
// Name: public: virtual void CPluginMenu::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginMenu::OnCommand(CPluginMenu *this, const char *command)
{
  ECommandTarget_t TraceType; // eax
  vgui::CTreeViewListControl *v4; // ecx
  ECommandTarget_t v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  TraceType = CTraceFilter::GetTraceType((vgui::CTreeViewListControl *)this);
  Cbuf_AddText(eTarget: TraceType, pText: command, nTickDelay: 0);
  v5 = CTraceFilter::GetTraceType(this: v4);
  Cbuf_AddText(eTarget: v5, pText: "\n", nTickDelay: 0);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
  {
    v7 = KeyValues::KeyValues(this: v6, setName: "Command", firstKey: "command", firstValue: "close");
    vgui::Panel::CallParentFunction(this, message: v7);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D630
// Name: public: static char const __near * CPluginGameUIDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPluginGameUIDialog::GetPanelClassName()
{
  return "CPluginGameUIDialog";
}

//------------------------------------------------------------------------------
// Address: 0x1008D640
// Name: public: virtual void CPluginGameUIDialog::Show(enum DIALOG_TYPE,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginGameUIDialog::Show(CPluginGameUIDialog *this, DIALOG_TYPE type, KeyValues *kv)
{
  CPluginGameUIDialog_vtbl *v4; // eax
  const wchar_t *WString; // eax
  const wchar_t *v7; // eax
  const wchar_t *v8; // eax
  const char *String; // eax
  CPluginGameUIDialog_vtbl *v10; // [esp+Ch] [ebp-4h]
  KeyValues *kva; // [esp+1Ch] [ebp+Ch]

  this->m_Menu->SetVisible(this: this->m_Menu, a2: false);
  this->m_RichText->SetVisible(this: this->m_RichText, a2: false);
  this->m_Message->SetVisible(this: this->m_Message, a2: false);
  this->m_Entry->SetVisible(this: this->m_Entry, a2: false);
  this->m_EntryLabel->SetVisible(this: this->m_EntryLabel, a2: false);
  v4 = this->__vftable;
  this->m_szEntryCommand[0] = 0;
  v10 = v4;
  WString = KeyValues::GetWString(this: kv, keyName: "title", defaultValue: &wszText);
  v10->SetTitle(this, a2: WString, a3: true);
  switch ( type )
  {
    case DIALOG_MSG:
      this->SetVisible(this, a2: false);
      return;
    case DIALOG_MENU:
      CPluginMenu::Show(this: this->m_Menu, kv);
      this->m_Menu->SetVisible(this: this->m_Menu, a2: true);
      goto LABEL_7;
    case DIALOG_TEXT:
      v7 = KeyValues::GetWString(this: kv, keyName: "msg", defaultValue: &wszText);
      vgui::RichText::SetText(this: this->m_RichText, text: v7);
      this->m_RichText->SetVisible(this: this->m_RichText, a2: true);
      goto LABEL_7;
    case DIALOG_ENTRY:
      this->m_Entry->SetVisible(this: this->m_Entry, a2: true);
      this->m_EntryLabel->SetVisible(this: this->m_EntryLabel, a2: true);
      kva = (KeyValues *)this->m_EntryLabel->__vftable;
      v8 = KeyValues::GetWString(this: kv, keyName: "msg", defaultValue: &wszText);
      (*(void (__thiscall **)(vgui::Label *, const wchar_t *, _DWORD))&kva[23].m_iDataType)(
        a1: this->m_EntryLabel,
        a2: v8,
        a3: 0);
      String = KeyValues::GetString(this: kv, keyName: "command", defaultValue: defaultValue);
      V_strncpy(pDest: this->m_szEntryCommand, pSrc: String, maxLen: 255);
      this->m_CloseButton->SetText(this: this->m_CloseButton, a2: "#GameUI_OK");
      goto LABEL_7;
    default:
      _Msg(a1: "Invalid menu type (%i)\n", type);
LABEL_7:
      this->Activate(this);
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D820
// Name: public: static char const __near * CMessage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMessage::GetPanelClassName()
{
  return "CMessage";
}

//------------------------------------------------------------------------------
// Address: 0x1008D830
// Name: protected: virtual void CMessage::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessage::ApplySchemeSettings(CMessage *this, vgui::IScheme *pScheme)
{
  unsigned int v3; // eax

  v3 = pScheme->GetFont(this: pScheme, a2: "PluginText", a3: false);
  if ( v3 == 0 )
    v3 = pScheme->GetFont(this: pScheme, a2: "HudHintText", a3: false);
  this->SetFont(this, a2: v3);
  vgui::Label::ApplySchemeSettings(this, pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x1008D880
// Name: public: static char const __near * CPluginHudMessage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPluginHudMessage::GetPanelClassName()
{
  return "CPluginHudMessage";
}

//------------------------------------------------------------------------------
// Address: 0x1008D890
// Name: protected: virtual void CPluginHudMessage::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginHudMessage::OnTick(CPluginHudMessage *this)
{
  float v2; // [esp-4h] [ebp-8h]

  v2 = _Plat_FloatTime((CStatTime *)this);
  vgui::AnimationController::UpdateAnimations(this: this->m_pAnimationController, currentTime: v2);
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1008D8B0
// Name: protected: virtual void CPluginHudMessage::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginHudMessage::OnSizeChanged(CPluginHudMessage *this, int newWide, int newTall)
{
  vgui::EditablePanel::OnSizeChanged(this, wide: newWide, tall: newTall);
  vgui::Panel::GetSize(this, wide: &newWide, tall: &newTall);
  vgui::Panel::SetBounds(this: this->m_Message, x: 40, y: 5, wide: newWide - 50, tall: newTall - 10);
}

//------------------------------------------------------------------------------
// Address: 0x1008D900
// Name: public: void CPluginHudMessage::Hide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginHudMessage::Hide(CPluginHudMessage *this)
{
  vgui::AnimationController::StartAnimationSequence(
    this: this->m_pAnimationController,
    sequenceName: "PluginMessageHide");
  this->m_pExtraPanelIcon->SetVisible(this: this->m_pExtraPanelIcon, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1008D930
// Name: public: void CPluginHudMessage::ShowMessage(wchar_t const __near *,int,class Color,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginHudMessage::ShowMessage(
        CPluginHudMessage *this,
        const wchar_t *text,
        int time,
        Color clr,
        bool bHasExtraPanel)
{
  int v6; // eax
  int m_iTargetH; // [esp-4h] [ebp-10h]
  int textH; // [esp+4h] [ebp-8h] BYREF
  int textW; // [esp+8h] [ebp-4h] BYREF

  this->m_Message->SetVisible(this: this->m_Message, a2: true);
  vgui::Panel::SetBounds(this: this->m_Message, x: 40, y: 5, wide: this->m_iTargetW - 50, tall: this->m_iTargetH - 10);
  this->m_Message->SetText(this: this->m_Message, a2: text, a3: false);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_Message->SetFgColor)(a1: this->m_Message, a2: clr);
  this->m_fgColor = clr;
  this->m_bHidingControl = !bHasExtraPanel;
  if ( bHasExtraPanel )
    this->m_pExtraPanelIcon->SetVisible(this: this->m_pExtraPanelIcon, a2: true);
  vgui::AnimationController::StartAnimationSequence(
    this: this->m_pAnimationController,
    sequenceName: "PluginMessageShow");
  this->SetVisible(this, a2: true);
  this->InvalidateLayout(this, a2: false, a3: false);
  this->m_Message->GetContentSize(this: this->m_Message, a2: &textW, a3: &textH);
  v6 = textW + 50;
  if ( textW + 50 >= 400 )
    v6 = 400;
  m_iTargetH = this->m_iTargetH;
  textW = v6;
  vgui::Panel::SetSize(this, wide: v6, tall: m_iTargetH);
}

//------------------------------------------------------------------------------
// Address: 0x1008DA40
// Name: public: void CPluginUIManager::OnPanelClosed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginUIManager::OnPanelClosed(CPluginUIManager *this)
{
  CPluginGameUIDialog *m_pGameUIDialog; // ecx
  CPluginHudMessage *m_pHudMessage; // esi

  m_pGameUIDialog = this->m_pGameUIDialog;
  this->m_iCurPriority = 0x7FFFFFFF;
  this->m_iHudDisplayUntil = 0;
  this->m_iMessageDisplayUntil = 0;
  m_pGameUIDialog->SetVisible(this: m_pGameUIDialog, a2: false);
  m_pHudMessage = this->m_pHudMessage;
  vgui::AnimationController::StartAnimationSequence(
    this: m_pHudMessage->m_pAnimationController,
    sequenceName: "PluginMessageHide");
  m_pHudMessage->m_pExtraPanelIcon->SetVisible(this: m_pHudMessage->m_pExtraPanelIcon, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1008DAA0
// Name: public: void CPluginUIManager::GetHudMessagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginUIManager::GetHudMessagePosition(CPluginUIManager *this, int *x, int *y, int *wide, int *tall)
{
  CPluginHudMessage *m_pHudMessage; // ecx

  m_pHudMessage = this->m_pHudMessage;
  if ( m_pHudMessage != nullptr )
  {
    vgui::Panel::GetBounds(this: m_pHudMessage, x, y, wide, tall);
  }
  else
  {
    *tall = 0;
    *wide = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008DAF0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPluginUIManager::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPluginUIManager::GetMessageMap(CPluginUIManager *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPluginUIManager::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPluginUIManager::GetMessageMap'::`2'::s_pMap;
  `CPluginUIManager::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPluginUIManager");
  `CPluginUIManager::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008DB20
// Name: public: virtual struct PanelAnimationMap __near * CPluginUIManager::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPluginUIManager::GetAnimMap(CPluginUIManager *this)
{
  return FindOrAddPanelAnimationMap(className: "CPluginUIManager");
}

//------------------------------------------------------------------------------
// Address: 0x1008DB30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPluginUIManager::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPluginUIManager::GetKBMap(CPluginUIManager *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPluginUIManager::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPluginUIManager::GetKBMap'::`2'::s_pMap;
  `CPluginUIManager::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPluginUIManager");
  `CPluginUIManager::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008DB60
// Name: public: virtual struct vgui::PanelMessageMap __near * CPluginMenu::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPluginMenu::GetMessageMap(CPluginMenu *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPluginMenu::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPluginMenu::GetMessageMap'::`2'::s_pMap;
  `CPluginMenu::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPluginMenu");
  `CPluginMenu::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008DB90
// Name: public: virtual struct PanelAnimationMap __near * CPluginMenu::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPluginMenu::GetAnimMap(CPluginMenu *this)
{
  return FindOrAddPanelAnimationMap(className: "CPluginMenu");
}

//------------------------------------------------------------------------------
// Address: 0x1008DBA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPluginMenu::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPluginMenu::GetKBMap(CPluginMenu *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPluginMenu::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPluginMenu::GetKBMap'::`2'::s_pMap;
  `CPluginMenu::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPluginMenu");
  `CPluginMenu::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008DBD0
// Name: public: CPluginMenu::CPluginMenu(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CPluginMenu *__thiscall CPluginMenu::CPluginMenu(CPluginMenu *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // esi
  PanelAnimationMap *v4; // esi
  vgui::PanelKeyBindingMap *v5; // esi

  vgui::EditablePanel::EditablePanel(this, parent, panelName: "PluginMenu");
  this->__vftable = (CPluginMenu_vtbl *)&CPluginMenu::`vftable';
  if ( `CPluginMenu::ChainToMap'::`2'::chained == 0 )
  {
    `CPluginMenu::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CPluginMenu");
    v3->pfnClassName = CPluginMenu::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CPluginMenu::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPluginMenu::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CPluginMenu");
    v4->pfnClassName = CPluginMenu::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CPluginMenu::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPluginMenu::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CPluginMenu");
    v5->pfnClassName = CPluginMenu::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource/UI/PluginMenu.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008DCD0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPluginGameUIDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPluginGameUIDialog::GetMessageMap(CPluginGameUIDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPluginGameUIDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPluginGameUIDialog::GetMessageMap'::`2'::s_pMap;
  `CPluginGameUIDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPluginGameUIDialog");
  `CPluginGameUIDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008DD00
// Name: public: virtual struct PanelAnimationMap __near * CPluginGameUIDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPluginGameUIDialog::GetAnimMap(CPluginGameUIDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CPluginGameUIDialog");
}

//------------------------------------------------------------------------------
// Address: 0x1008DD10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPluginGameUIDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPluginGameUIDialog::GetKBMap(CPluginGameUIDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPluginGameUIDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPluginGameUIDialog::GetKBMap'::`2'::s_pMap;
  `CPluginGameUIDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPluginGameUIDialog");
  `CPluginGameUIDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008DD40
// Name: public: CPluginGameUIDialog::CPluginGameUIDialog(void)
// Source: json
//------------------------------------------------------------------------------
CPluginGameUIDialog *__thiscall CPluginGameUIDialog::CPluginGameUIDialog(CPluginGameUIDialog *this)
{
  vgui::PanelMessageMap *v2; // edi
  PanelAnimationMap *v3; // edi
  vgui::PanelKeyBindingMap *v4; // edi
  CPluginMenu *v5; // eax
  CPluginMenu *v6; // eax
  vgui::RichText *v7; // eax
  vgui::RichText *v8; // eax
  vgui::Label *v9; // eax
  vgui::Label *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Label *v13; // eax
  vgui::Label *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax

  vgui::Frame::Frame(this, parent: nullptr, panelName: "Plugins", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CPluginGameUIDialog_vtbl *)&CPluginGameUIDialog::`vftable';
  if ( `CPluginGameUIDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CPluginGameUIDialog::ChainToMap'::`2'::chained = 1;
    v2 = vgui::FindOrAddPanelMessageMap(className: "CPluginGameUIDialog");
    v2->pfnClassName = CPluginGameUIDialog::GetPanelClassName;
    v2->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CPluginGameUIDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPluginGameUIDialog::ChainToAnimationMap'::`2'::chained = 1;
    v3 = FindOrAddPanelAnimationMap(className: "CPluginGameUIDialog");
    v3->pfnClassName = CPluginGameUIDialog::GetPanelClassName;
    v3->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CPluginGameUIDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPluginGameUIDialog::KB_ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelKeyBindingMap(className: "CPluginGameUIDialog");
    v4->pfnClassName = CPluginGameUIDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Frame::SetTitle(this, title: "Plugins", surfaceTitle: true);
  vgui::Panel::SetAlpha(this, alpha: 255);
  vgui::Panel::SetScheme(this, tag: "Tracker");
  this->m_szEntryCommand[0] = 0;
  v5 = (CPluginMenu *)MemAlloc_Alloc(nSize: 0x180u);
  if ( v5 != nullptr )
    v6 = CPluginMenu::CPluginMenu(this: v5, parent: this);
  else
    v6 = nullptr;
  this->m_Menu = v6;
  v7 = (vgui::RichText *)MemAlloc_Alloc(nSize: 0x220u);
  if ( v7 != nullptr )
    v8 = vgui::RichText::RichText(this: v7, parent: this, panelName: "Rich");
  else
    v8 = nullptr;
  this->m_RichText = v8;
  v9 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v9 != nullptr )
    v10 = vgui::Label::Label(this: v9, parent: this, panelName: "Label", text: defaultValue);
  else
    v10 = nullptr;
  this->m_Message = v10;
  v11 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: "Entry");
  else
    v12 = nullptr;
  this->m_Entry = v12;
  v13 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v13 != nullptr )
    v14 = vgui::Label::Label(this: v13, parent: this, panelName: "EntryLabel", text: defaultValue);
  else
    v14 = nullptr;
  this->m_EntryLabel = v14;
  v15 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v15 != nullptr )
    v16 = vgui::Button::Button(
            this: v15,
            parent: this,
            panelName: "Close",
            text: defaultValue,
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v16 = nullptr;
  this->m_CloseButton = v16;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource/UI/Plugin.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::InvalidateLayout(this, layoutNow: 0, reloadScheme: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008DF70
// Name: protected: virtual void CPluginGameUIDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginGameUIDialog::OnCommand(CPluginGameUIDialog *this, const char *cmd)
{
  vgui::CTreeViewListControl *v3; // ecx
  ECommandTarget_t TraceType; // eax
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t v6; // eax
  vgui::CTreeViewListControl *v7; // ecx
  ECommandTarget_t v8; // eax
  char userCMD[512]; // [esp+8h] [ebp-300h] BYREF
  char entryText[256]; // [esp+208h] [ebp-100h] BYREF

  if ( _V_stricmp(s1: cmd, s2: "close") != 0 )
  {
    vgui::Frame::OnCommand(this, command: cmd);
  }
  else
  {
    if ( _V_strlen(str: this->m_szEntryCommand) > 0 )
    {
      this->m_Entry->GetText_2(this: this->m_Entry, a2: entryText, a3: 255);
      V_snprintf(pDest: userCMD, maxLen: 512, pFormat: "%s %s\n", this->m_szEntryCommand, entryText);
      TraceType = CTraceFilter::GetTraceType(this: v3);
      Cbuf_AddExecutionMarker(eTarget: TraceType, marker: eCmdExecutionMarker_Enable_FCVAR_CLIENTCMD_CAN_EXECUTE);
      v6 = CTraceFilter::GetTraceType(this: v5);
      Cbuf_AddText(eTarget: v6, pText: userCMD, nTickDelay: 0);
      v8 = CTraceFilter::GetTraceType(this: v7);
      Cbuf_AddExecutionMarker(eTarget: v8, marker: eCmdExecutionMarker_Disable_FCVAR_CLIENTCMD_CAN_EXECUTE);
    }
    this->Close(this);
    CPluginUIManager::OnPanelClosed(this: g_PluginManager);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E050
// Name: public: virtual struct vgui::PanelMessageMap __near * CMessage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMessage::GetMessageMap(CMessage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMessage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMessage::GetMessageMap'::`2'::s_pMap;
  `CMessage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMessage");
  `CMessage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008E080
// Name: public: virtual struct PanelAnimationMap __near * CMessage::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMessage::GetAnimMap(CMessage *this)
{
  return FindOrAddPanelAnimationMap(className: "CMessage");
}

//------------------------------------------------------------------------------
// Address: 0x1008E090
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMessage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMessage::GetKBMap(CMessage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMessage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMessage::GetKBMap'::`2'::s_pMap;
  `CMessage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMessage");
  `CMessage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008E0C0
// Name: public: CMessage::CMessage(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMessage *__thiscall CMessage::CMessage(CMessage *this, vgui::Panel *parent, const char *panelName, const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (CMessage_vtbl *)&CMessage::`vftable';
  if ( `CMessage::ChainToMap'::`2'::chained == 0 )
  {
    `CMessage::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CMessage");
    v5->pfnClassName = CMessage::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Label");
  }
  if ( `CMessage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMessage::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CMessage");
    v6->pfnClassName = CMessage::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Label");
  }
  if ( `CMessage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMessage::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CMessage");
    v7->pfnClassName = CMessage::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Label");
  }
  this->m_bHasExtraPanel = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008E1C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPluginHudMessage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPluginHudMessage::GetMessageMap(CPluginHudMessage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPluginHudMessage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPluginHudMessage::GetMessageMap'::`2'::s_pMap;
  `CPluginHudMessage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPluginHudMessage");
  `CPluginHudMessage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008E1F0
// Name: public: virtual struct PanelAnimationMap __near * CPluginHudMessage::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPluginHudMessage::GetAnimMap(CPluginHudMessage *this)
{
  return FindOrAddPanelAnimationMap(className: "CPluginHudMessage");
}

//------------------------------------------------------------------------------
// Address: 0x1008E200
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPluginHudMessage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPluginHudMessage::GetKBMap(CPluginHudMessage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPluginHudMessage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPluginHudMessage::GetKBMap'::`2'::s_pMap;
  `CPluginHudMessage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPluginHudMessage");
  `CPluginHudMessage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008E230
// Name: public: CPluginHudMessage::CPluginHudMessage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CPluginHudMessage *__thiscall CPluginHudMessage::CPluginHudMessage(CPluginHudMessage *this, unsigned int parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::ImagePanel *v6; // eax
  vgui::ImagePanel *v7; // eax
  CMessage *v8; // eax
  CMessage *v9; // eax
  vgui::AnimationController *v10; // eax
  vgui::AnimationController *v11; // eax

  vgui::Frame::Frame(this, parent: nullptr, panelName: "PluginHudMessage", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CPluginHudMessage_vtbl *)&CPluginHudMessage::`vftable';
  if ( `CPluginHudMessage::ChainToMap'::`2'::chained == 0 )
  {
    `CPluginHudMessage::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CPluginHudMessage");
    v3->pfnClassName = CPluginHudMessage::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CPluginHudMessage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPluginHudMessage::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CPluginHudMessage");
    v4->pfnClassName = CPluginHudMessage::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CPluginHudMessage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPluginHudMessage::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CPluginHudMessage");
    v5->pfnClassName = CPluginHudMessage::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_fgColor = 0;
  vgui::Panel::SetParent(this, newParent: parent);
  vgui::Panel::SetVisible(this, state: 0);
  vgui::Panel::SetAlpha(this, alpha: 255);
  vgui::Panel::SetMinimumSize(this, wide: 10, tall: 10);
  vgui::Panel::SetScheme(this, tag: "ClientScheme");
  vgui::Frame::SetMoveable(this, state: false);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 0);
  vgui::Panel::SetMouseInputEnabled(this, state: 0);
  vgui::Frame::SetTitleBarVisible(this, state: false);
  v6 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v6 != nullptr )
    v7 = vgui::ImagePanel::ImagePanel(this: v6, parent: this, name: "ExtraPanelIcon");
  else
    v7 = nullptr;
  this->m_pExtraPanelIcon = v7;
  v7->SetVisible(this: v7, a2: false);
  v8 = (CMessage *)MemAlloc_Alloc(nSize: 0x1A8u);
  if ( v8 != nullptr )
    v9 = CMessage::CMessage(this: v8, parent: this, panelName: "Msg", text: defaultValue);
  else
    v9 = nullptr;
  this->m_Message = v9;
  v9->SetVisible(this: v9, a2: false);
  v10 = (vgui::AnimationController *)MemAlloc_Alloc(nSize: 0x1C8u);
  if ( v10 != nullptr )
    v11 = vgui::AnimationController::AnimationController(this: v10, parent: nullptr);
  else
    v11 = nullptr;
  this->m_pAnimationController = v11;
  v11->SetParent(this: v11, a2: parent);
  vgui::AnimationController::SetScriptFile(
    this: this->m_pAnimationController,
    sizingPanel: parent,
    fileName: "scripts/plugin_animations.txt",
    wipeAll: false);
  this->m_pAnimationController->SetProportional(this: this->m_pAnimationController, a2: false);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource/UI/PluginHud.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::InvalidateLayout(this, layoutNow: 0, reloadScheme: false);
  vgui::Panel::GetSize(this, wide: &this->m_iTargetW, tall: &this->m_iTargetH);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008E4A0
// Name: protected: virtual void CPluginHudMessage::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginHudMessage::ApplySchemeSettings(CPluginHudMessage *this, vgui::IScheme *pScheme)
{
  vgui::ImagePanel_vtbl *v3; // edi
  vgui::IImage *v4; // eax
  vgui::IScheme *v5; // edi
  CPluginHudMessage_vtbl *v6; // eax
  vgui::IScheme_vtbl *v7; // ebx
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  _BYTE v10[4]; // [esp+Ch] [ebp-8h] BYREF
  CPluginHudMessage_vtbl *v11; // [esp+10h] [ebp-4h]

  v3 = this->m_pExtraPanelIcon->__vftable;
  v4 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "plugin/message_waiting", a3: 1);
  v3->SetImage(this: this->m_pExtraPanelIcon, a2: v4);
  v5 = pScheme;
  vgui::Frame::ApplySchemeSettings(this, pScheme);
  v6 = this->__vftable;
  v7 = v5->__vftable;
  pScheme = (vgui::IScheme *)-1073741824;
  v11 = v6;
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, const char *, int))v7->GetColor)(
                   a1: v5,
                   a2: &pScheme,
                   a3: "TransparentBlack",
                   a4: -1073741824);
  v9 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v7->GetColor)(
                   a1: v5,
                   a2: v10,
                   a3: "Plugins.BgColor",
                   a4: *v8);
  ((void (__thiscall *)(CPluginHudMessage *, _DWORD))v11->SetBgColor)(a1: this, a2: *v9);
  this->SetPaintBackgroundType(this, a2: 2);
  ((void (__thiscall *)(CMessage *, _DWORD))this->m_Message->SetFgColor)(
    a1: this->m_Message,
    a2: *(_DWORD *)&this->m_fgColor);
  this->m_pExtraPanelIcon->SetVisible(this: this->m_pExtraPanelIcon, a2: !this->m_bHidingControl);
}

//------------------------------------------------------------------------------
// Address: 0x1008E580
// Name: public: void CPluginHudMessage::StartHiding(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginHudMessage::StartHiding(CPluginHudMessage *this)
{
  bool v2; // al
  vgui::AnimationController *m_pAnimationController; // ecx

  v2 = this->m_pExtraPanelIcon->IsVisible(this: this->m_pExtraPanelIcon);
  m_pAnimationController = this->m_pAnimationController;
  if ( v2 )
  {
    vgui::AnimationController::StartAnimationSequence(this: m_pAnimationController, sequenceName: "PluginMessageSmall");
  }
  else
  {
    vgui::AnimationController::StartAnimationSequence(this: m_pAnimationController, sequenceName: "PluginMessageHide");
    this->m_pExtraPanelIcon->SetVisible(this: this->m_pExtraPanelIcon, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E5D0
// Name: public: CPluginUIManager::CPluginUIManager(void)
// Source: json
//------------------------------------------------------------------------------
CPluginUIManager *__thiscall CPluginUIManager::CPluginUIManager(CPluginUIManager *this)
{
  vgui::PanelMessageMap *v2; // edi
  PanelAnimationMap *v3; // edi
  vgui::PanelKeyBindingMap *v4; // edi
  CPluginGameUIDialog *v5; // eax
  CPluginGameUIDialog *v6; // eax
  IEngineVGuiInternal *v7; // eax
  CPluginGameUIDialog_vtbl *v8; // edi
  int v9; // eax
  CPluginHudMessage *v10; // edi
  IEngineVGuiInternal *v11; // eax
  unsigned int v12; // eax
  CPluginHudMessage *v13; // eax

  vgui::Panel::Panel(this, parent: nullptr, panelName: "PluginManager");
  this->__vftable = (CPluginUIManager_vtbl *)&CPluginUIManager::`vftable';
  if ( `CPluginUIManager::ChainToMap'::`2'::chained == 0 )
  {
    `CPluginUIManager::ChainToMap'::`2'::chained = 1;
    v2 = vgui::FindOrAddPanelMessageMap(className: "CPluginUIManager");
    v2->pfnClassName = CPluginUIManager::GetPanelClassName;
    v2->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CPluginUIManager::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPluginUIManager::ChainToAnimationMap'::`2'::chained = 1;
    v3 = FindOrAddPanelAnimationMap(className: "CPluginUIManager");
    v3->pfnClassName = CPluginUIManager::GetPanelClassName;
    v3->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CPluginUIManager::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPluginUIManager::KB_ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelKeyBindingMap(className: "CPluginUIManager");
    v4->pfnClassName = CPluginUIManager::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_iCurPriority = 0x7FFFFFFF;
  this->m_iMessageDisplayUntil = 0;
  this->m_iHudDisplayUntil = 0;
  this->m_bShutdown = false;
  v5 = (CPluginGameUIDialog *)MemAlloc_Alloc(nSize: 0x32Cu);
  if ( v5 != nullptr )
    v6 = CPluginGameUIDialog::CPluginGameUIDialog(this: v5);
  else
    v6 = nullptr;
  this->m_pGameUIDialog = v6;
  v7 = EngineVGui();
  v8 = this->m_pGameUIDialog->__vftable;
  v9 = v7->GetPanel(this: v7, a2: PANEL_GAMEUIDLL);
  v8->SetParent(this: this->m_pGameUIDialog, a2: v9);
  v10 = (CPluginHudMessage *)MemAlloc_Alloc(nSize: 0x230u);
  if ( v10 != nullptr )
  {
    v11 = EngineVGui();
    v12 = v11->GetPanel(this: v11, a2: PANEL_CLIENTDLL);
    v13 = CPluginHudMessage::CPluginHudMessage(this: v10, parent: v12);
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pHudMessage = v13;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008E770
// Name: protected: virtual void CPluginUIManager::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginUIManager::OnTick(CPluginUIManager *this)
{
  IEngineVGuiInternal *v2; // eax
  double m_iMessageDisplayUntil; // [esp+4h] [ebp-8h]
  int m_iHudDisplayUntil; // [esp+8h] [ebp-4h]

  if ( !this->m_bShutdown )
  {
    if ( this->m_iMessageDisplayUntil != 0 )
    {
      v2 = EngineVGui();
      if ( !v2->IsGameUIVisible(this: v2) )
      {
        m_iMessageDisplayUntil = (double)this->m_iMessageDisplayUntil;
        if ( _Plat_FloatTime((CStatTime *)this) > m_iMessageDisplayUntil )
        {
          this->m_pGameUIDialog->SetVisible(this: this->m_pGameUIDialog, a2: false);
          CPluginHudMessage::Hide(this: this->m_pHudMessage);
          this->m_iMessageDisplayUntil = 0;
          this->m_iCurPriority = 0x7FFFFFFF;
        }
      }
    }
    m_iHudDisplayUntil = this->m_iHudDisplayUntil;
    if ( m_iHudDisplayUntil != 0 && _Plat_FloatTime((CStatTime *)this) > (double)m_iHudDisplayUntil )
    {
      CPluginHudMessage::StartHiding(this: this->m_pHudMessage);
      this->m_iHudDisplayUntil = 0;
    }
    CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E840
// Name: public: void CPluginUIManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginUIManager::Shutdown(CPluginUIManager *this)
{
  vgui::IVGui *v2; // edi
  vgui::IVGui_vtbl *v3; // ebx
  int v4; // eax
  CPluginHudMessage *m_pHudMessage; // edi

  v2 = g_pVGui;
  v3 = g_pVGui->__vftable;
  v4 = this->GetVPanel(this);
  v3->RemoveTickSignal(this: v2, a2: v4);
  m_pHudMessage = this->m_pHudMessage;
  vgui::AnimationController::StartAnimationSequence(
    this: m_pHudMessage->m_pAnimationController,
    sequenceName: "PluginMessageHide");
  m_pHudMessage->m_pExtraPanelIcon->SetVisible(this: m_pHudMessage->m_pExtraPanelIcon, a2: false);
  this->m_pGameUIDialog->SetVisible(this: this->m_pGameUIDialog, a2: false);
  this->MarkForDeletion(this);
  this->m_bShutdown = true;
}

//------------------------------------------------------------------------------
// Address: 0x1008E8B0
// Name: public: void CPluginUIManager::Show(enum DIALOG_TYPE,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginUIManager::Show(CPluginUIManager *this, DIALOG_TYPE type, DIALOG_TYPE kv)
{
  DIALOG_TYPE v3; // ebx
  KeyValues *v4; // esi
  const char *String; // eax
  int Int; // eax
  CStatTime *m_iCurPriority; // ecx
  CStatTime *v9; // ecx
  CStatTime *v10; // ecx
  CStatTime *v11; // ecx
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  CPluginGameUIDialog *m_pGameUIDialog; // ecx
  DIALOG_TYPE v17; // eax
  const wchar_t *WString; // eax
  const char *Name; // eax
  Color v20; // [esp-4h] [ebp-14h]
  int v21; // [esp-4h] [ebp-14h]
  int v22; // [esp+0h] [ebp-10h]

  v3 = type;
  v4 = (KeyValues *)kv;
  if ( type == DIALOG_ASKCONNECT )
  {
    *(float *)&kv = KeyValues::GetFloat(this: (KeyValues *)kv, keyName: "time", defaultValue: 4.0);
    String = KeyValues::GetString(this: v4, keyName: "title", defaultValue: nullptr);
    if ( String != nullptr )
      ShowAskConnectPanel(pHostName: String, flDuration: *(float *)&kv);
    else
      DevMsg(a1: "Ignoring DIALOG_ASKCONNECT message. No IP specified.");
  }
  else
  {
    Int = KeyValues::GetInt(this: (KeyValues *)kv, keyName: "level", defaultValue: 0x7FFFFFFF);
    m_iCurPriority = (CStatTime *)this->m_iCurPriority;
    if ( Int >= (int)m_iCurPriority )
    {
      v22 = this->m_iCurPriority;
      v21 = Int;
      Name = KeyValues::GetName(this: v4);
      DevMsg(a1: "Ignoring message %s, %i < %i\n", Name, v21, v22);
    }
    else
    {
      this->m_iCurPriority = Int;
      if ( v3 != DIALOG_MSG )
      {
        if ( KeyValues::GetInt(this: v4, keyName: "time", defaultValue: 10) > 10
          && KeyValues::GetInt(this: v4, keyName: "time", defaultValue: 10) >= 200 )
        {
          kv = 200;
          v14 = _Plat_FloatTime(this: v9);
          v13 = v14 + (double)(int)kv;
        }
        else
        {
          if ( KeyValues::GetInt(this: v4, keyName: "time", defaultValue: 10) <= 10 )
            kv = 10;
          else
            *(float *)&kv = COERCE_FLOAT(KeyValues::GetInt(this: v4, keyName: "time", defaultValue: 10));
          v12 = _Plat_FloatTime(this: v10);
          v13 = v12 + (double)(int)kv;
        }
      }
      else
      {
        v13 = _Plat_FloatTime(this: m_iCurPriority) + 10.0;
      }
      this->m_iMessageDisplayUntil = (int)v13;
      v15 = _Plat_FloatTime(this: v11) + 10.0;
      m_pGameUIDialog = this->m_pGameUIDialog;
      this->m_iHudDisplayUntil = (int)v15;
      m_pGameUIDialog->Show(this: m_pGameUIDialog, a2: v3, a3: v4);
      *(float *)&kv = NAN;
      if ( KeyValues::IsEmpty(this: v4, keyName: "color") )
      {
        v17 = kv;
      }
      else
      {
        *(float *)&kv = 0.0;
        v17 = (DIALOG_TYPE)*KeyValues::GetColor(
                              this: v4,
                              result: (Color *)&type,
                              keyName: "color",
                              defaultColor: (const Color *)&kv);
      }
      v20 = (Color)v17;
      WString = KeyValues::GetWString(this: v4, keyName: "title", defaultValue: &wszText);
      CPluginHudMessage::ShowMessage(
        this: this->m_pHudMessage,
        text: WString,
        time: 10,
        clr: v20,
        bHasExtraPanel: v3 != DIALOG_MSG);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008EA90
// Name: void PluginHelpers_Menu(class SVC_Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PluginHelpers_Menu(SVC_Menu *msg)
{
  CPluginUIManager *v1; // eax
  CPluginUIManager *v2; // eax

  if ( msg->m_MenuKeyValues != nullptr
    && cl_showpluginmessages.m_pParent != nullptr
    && cl_showpluginmessages.m_pParent->m_Value.m_nValue != 0 )
  {
    v1 = g_PluginManager;
    if ( g_PluginManager == nullptr )
    {
      v2 = (CPluginUIManager *)MemAlloc_Alloc(nSize: 0x168u);
      if ( v2 != nullptr )
        v1 = CPluginUIManager::CPluginUIManager(this: v2);
      else
        v1 = nullptr;
      g_PluginManager = v1;
    }
    CPluginUIManager::Show(this: v1, type: msg->m_Type, kv: (DIALOG_TYPE)msg->m_MenuKeyValues);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AFCB0
// Name: public: virtual class vgui::Panel __near * vgui::Label::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Label *__thiscall vgui::Label::HasHotkey(vgui::Label *this, wchar_t key)
{
  unsigned __int16 v2; // si

  v2 = key;
  if ( iswalnum(c: key) != 0 )
    v2 = towlower(c: key);
  return this->_hotkey != v2 ? nullptr : this;
}

//------------------------------------------------------------------------------
// Address: 0x102B1300
// Name: public: virtual class vgui::IImage __near * vgui::Label::GetImageAtIndex(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::Label::GetImageAtIndex(vgui::Label *this, int index)
{
  if ( index < 0 || index >= this->_imageDar.m_Size )
    return nullptr;
  else
    return this->_imageDar.m_Memory.m_pMemory[index].image;
}

//------------------------------------------------------------------------------
// Address: 0x102B1820
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Label::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Label::GetMessageMap(vgui::Label *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Label::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Label::GetMessageMap'::`2'::s_pMap;
  `vgui::Label::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Label");
  `vgui::Label::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102B1850
// Name: public: virtual struct PanelAnimationMap __near * vgui::Label::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Label::GetAnimMap(vgui::Label *this)
{
  return FindOrAddPanelAnimationMap(className: "Label");
}

//------------------------------------------------------------------------------
// Address: 0x102B1860
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Label::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Label::GetKBMap(vgui::Label *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Label::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Label::GetKBMap'::`2'::s_pMap;
  `vgui::Label::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  `vgui::Label::GetKBMap'::`2'::s_pMap = result;
  return result;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1008D0D0
// Name: public: static char const __near * CPluginUIManager::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPluginUIManager::GetPanelClassName()
{
  return "CPluginUIManager";
}

//------------------------------------------------------------------------------
// Address: 0x1008D0E0
// Name: public: static char const __near * CPluginMenu::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPluginMenu::GetPanelClassName()
{
  return "CPluginMenu";
}

//------------------------------------------------------------------------------
// Address: 0x1008D0F0
// Name: public: void CPluginMenu::Show(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginMenu::Show(CPluginMenu *this, KeyValues *kv)
{
  CPluginMenu *v2; // edi
  vgui::Panel *ChildByName; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  int v6; // ebx
  const wchar_t *WString; // eax
  int j; // esi
  vgui::Panel *Child; // eax
  void *v10; // eax
  KeyValues *FirstTrueSubKey; // ebx
  vgui::Panel *v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // esi
  int v15; // edi
  const wchar_t *v16; // eax
  int v17; // edi
  const char *String; // eax
  KeyValues *NextTrueSubKey; // eax
  char controlName[64]; // [esp+Ch] [ebp-48h] BYREF
  CPluginMenu *v21; // [esp+4Ch] [ebp-8h]
  int i; // [esp+50h] [ebp-4h]

  v2 = this;
  v21 = this;
  ChildByName = vgui::Panel::FindChildByName(this, childName: "Text", recurseDown: false);
  v4 = __RTDynamicCast(
         inptr: ChildByName,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::Label `RTTI Type Descriptor',
         isReference: 0);
  v5 = v4;
  if ( v4 != nullptr )
  {
    v6 = *v4;
    WString = KeyValues::GetWString(this: kv, keyName: "msg", defaultValue: &wszText);
    (*(void (__thiscall **)(_DWORD *, const wchar_t *, _DWORD))(v6 + 844))(a1: v5, a2: WString, a3: 0);
  }
  for ( j = 0; j < vgui::Panel::GetChildCount(this: v2); ++j )
  {
    Child = vgui::Panel::GetChild(this: v2, index: j);
    v10 = __RTDynamicCast(
            inptr: Child,
            VfDelta: 0,
            SrcType: &vgui::Panel `RTTI Type Descriptor',
            TargetType: &vgui::Button `RTTI Type Descriptor',
            isReference: 0);
    if ( v10 != nullptr )
      (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v10 + 132))(a1: v10, a2: 0);
  }
  i = 1;
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: kv);
  if ( FirstTrueSubKey != nullptr )
  {
    do
    {
      V_snprintf(pDest: controlName, maxLen: 64, pFormat: "option%i", i);
      v12 = vgui::Panel::FindChildByName(this: v2, childName: controlName, recurseDown: true);
      v13 = __RTDynamicCast(
              inptr: v12,
              VfDelta: 0,
              SrcType: &vgui::Panel `RTTI Type Descriptor',
              TargetType: &vgui::Button `RTTI Type Descriptor',
              isReference: 0);
      v14 = v13;
      if ( v13 != nullptr )
      {
        v15 = *v13;
        v16 = KeyValues::GetWString(this: FirstTrueSubKey, keyName: "msg", defaultValue: &wszText);
        (*(void (__thiscall **)(_DWORD *, const wchar_t *, _DWORD))(v15 + 844))(a1: v14, a2: v16, a3: 0);
        v17 = *v14;
        String = KeyValues::GetString(this: FirstTrueSubKey, keyName: "command", defaultValue: defaultValue);
        (*(void (__thiscall **)(_DWORD *, const char *))(v17 + 1124))(a1: v14, a2: String);
        (*(void (__thiscall **)(_DWORD *, int))(*v14 + 132))(a1: v14, a2: 1);
        v2 = v21;
      }
      NextTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      ++i;
      FirstTrueSubKey = NextTrueSubKey;
    }
    while ( NextTrueSubKey != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D270
// Name: public: virtual void CPluginMenu::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginMenu::OnCommand(CPluginMenu *this, const char *command)
{
  ECommandTarget_t TraceType; // eax
  vgui::CTreeViewListControl *v4; // ecx
  ECommandTarget_t v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  TraceType = CTraceFilter::GetTraceType((vgui::CTreeViewListControl *)this);
  Cbuf_AddText(eTarget: TraceType, pText: command, nTickDelay: 0);
  v5 = CTraceFilter::GetTraceType(this: v4);
  Cbuf_AddText(eTarget: v5, pText: "\n", nTickDelay: 0);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
  {
    v7 = KeyValues::KeyValues(this: v6, setName: "Command", firstKey: "command", firstValue: "close");
    vgui::Panel::CallParentFunction(this, message: v7);
  }
  else
  {
    vgui::Panel::CallParentFunction(this, message: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D2E0
// Name: public: static char const __near * CPluginGameUIDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPluginGameUIDialog::GetPanelClassName()
{
  return "CPluginGameUIDialog";
}

//------------------------------------------------------------------------------
// Address: 0x1008D2F0
// Name: public: virtual void CPluginGameUIDialog::Show(enum DIALOG_TYPE,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginGameUIDialog::Show(CPluginGameUIDialog *this, DIALOG_TYPE type, KeyValues *kv)
{
  CPluginGameUIDialog_vtbl *v4; // eax
  const wchar_t *WString; // eax
  const wchar_t *v7; // eax
  const wchar_t *v8; // eax
  const char *String; // eax
  CPluginGameUIDialog_vtbl *v10; // [esp+Ch] [ebp-4h]
  KeyValues *kva; // [esp+1Ch] [ebp+Ch]

  this->m_Menu->SetVisible(this: this->m_Menu, a2: false);
  this->m_RichText->SetVisible(this: this->m_RichText, a2: false);
  this->m_Message->SetVisible(this: this->m_Message, a2: false);
  this->m_Entry->SetVisible(this: this->m_Entry, a2: false);
  this->m_EntryLabel->SetVisible(this: this->m_EntryLabel, a2: false);
  v4 = this->__vftable;
  this->m_szEntryCommand[0] = 0;
  v10 = v4;
  WString = KeyValues::GetWString(this: kv, keyName: "title", defaultValue: &wszText);
  v10->SetTitle(this, a2: WString, a3: true);
  switch ( type )
  {
    case DIALOG_MSG:
      this->SetVisible(this, a2: false);
      return;
    case DIALOG_MENU:
      CPluginMenu::Show(this: this->m_Menu, kv);
      this->m_Menu->SetVisible(this: this->m_Menu, a2: true);
      goto LABEL_7;
    case DIALOG_TEXT:
      v7 = KeyValues::GetWString(this: kv, keyName: "msg", defaultValue: &wszText);
      vgui::RichText::SetText(this: this->m_RichText, text: v7);
      this->m_RichText->SetVisible(this: this->m_RichText, a2: true);
      goto LABEL_7;
    case DIALOG_ENTRY:
      this->m_Entry->SetVisible(this: this->m_Entry, a2: true);
      this->m_EntryLabel->SetVisible(this: this->m_EntryLabel, a2: true);
      kva = (KeyValues *)this->m_EntryLabel->__vftable;
      v8 = KeyValues::GetWString(this: kv, keyName: "msg", defaultValue: &wszText);
      (*(void (__thiscall **)(vgui::Label *, const wchar_t *, _DWORD))&kva[23].m_iDataType)(
        a1: this->m_EntryLabel,
        a2: v8,
        a3: 0);
      String = KeyValues::GetString(this: kv, keyName: "command", defaultValue: defaultValue);
      V_strncpy(pDest: this->m_szEntryCommand, pSrc: String, maxLen: 255);
      this->m_CloseButton->SetText(this: this->m_CloseButton, a2: "#GameUI_OK");
      goto LABEL_7;
    default:
      _Msg(a1: "Invalid menu type (%i)\n", type);
LABEL_7:
      this->Activate(this);
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D4D0
// Name: public: static char const __near * CMessage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMessage::GetPanelClassName()
{
  return "CMessage";
}

//------------------------------------------------------------------------------
// Address: 0x1008D4E0
// Name: protected: virtual void CMessage::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessage::ApplySchemeSettings(CMessage *this, vgui::IScheme *pScheme)
{
  unsigned int v3; // eax

  v3 = pScheme->GetFont(this: pScheme, a2: "PluginText", a3: false);
  if ( v3 == 0 )
    v3 = pScheme->GetFont(this: pScheme, a2: "HudHintText", a3: false);
  this->SetFont(this, a2: v3);
  vgui::Label::ApplySchemeSettings(this, pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x1008D530
// Name: public: static char const __near * CPluginHudMessage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPluginHudMessage::GetPanelClassName()
{
  return "CPluginHudMessage";
}

//------------------------------------------------------------------------------
// Address: 0x1008D540
// Name: protected: virtual void CPluginHudMessage::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginHudMessage::OnTick(CPluginHudMessage *this)
{
  float currentTime; // [esp+0h] [ebp-8h]

  currentTime = _Plat_FloatTime(a1: this);
  vgui::AnimationController::UpdateAnimations(this: this->m_pAnimationController, currentTime);
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1008D560
// Name: protected: virtual void CPluginHudMessage::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginHudMessage::OnSizeChanged(CPluginHudMessage *this, int newWide, int newTall)
{
  vgui::EditablePanel::OnSizeChanged(this, wide: newWide, tall: newTall);
  vgui::Panel::GetSize(this, wide: &newWide, tall: &newTall);
  vgui::Panel::SetBounds(this: this->m_Message, x: 40, y: 5, wide: newWide - 50, tall: newTall - 10);
}

//------------------------------------------------------------------------------
// Address: 0x1008D5B0
// Name: public: void CPluginHudMessage::Hide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginHudMessage::Hide(CPluginHudMessage *this)
{
  vgui::AnimationController::StartAnimationSequence(
    this: this->m_pAnimationController,
    sequenceName: "PluginMessageHide");
  this->m_pExtraPanelIcon->SetVisible(this: this->m_pExtraPanelIcon, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1008D5E0
// Name: public: void CPluginHudMessage::ShowMessage(wchar_t const __near *,int,class Color,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginHudMessage::ShowMessage(
        CPluginHudMessage *this,
        const wchar_t *text,
        int time,
        Color clr,
        bool bHasExtraPanel)
{
  int v6; // eax
  int m_iTargetH; // [esp-4h] [ebp-10h]
  int textH; // [esp+4h] [ebp-8h] BYREF
  int textW; // [esp+8h] [ebp-4h] BYREF

  this->m_Message->SetVisible(this: this->m_Message, a2: true);
  vgui::Panel::SetBounds(this: this->m_Message, x: 40, y: 5, wide: this->m_iTargetW - 50, tall: this->m_iTargetH - 10);
  this->m_Message->SetText(this: this->m_Message, a2: text, a3: false);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_Message->SetFgColor)(a1: this->m_Message, a2: clr);
  this->m_fgColor = clr;
  this->m_bHidingControl = !bHasExtraPanel;
  if ( bHasExtraPanel )
    this->m_pExtraPanelIcon->SetVisible(this: this->m_pExtraPanelIcon, a2: true);
  vgui::AnimationController::StartAnimationSequence(
    this: this->m_pAnimationController,
    sequenceName: "PluginMessageShow");
  this->SetVisible(this, a2: true);
  this->InvalidateLayout(this, a2: false, a3: false);
  this->m_Message->GetContentSize(this: this->m_Message, a2: &textW, a3: &textH);
  v6 = textW + 50;
  if ( textW + 50 >= 400 )
    v6 = 400;
  m_iTargetH = this->m_iTargetH;
  textW = v6;
  vgui::Panel::SetSize(this, wide: v6, tall: m_iTargetH);
}

//------------------------------------------------------------------------------
// Address: 0x1008D6F0
// Name: public: void CPluginUIManager::OnPanelClosed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginUIManager::OnPanelClosed(CPluginUIManager *this)
{
  CPluginGameUIDialog *m_pGameUIDialog; // ecx
  CPluginHudMessage *m_pHudMessage; // esi

  m_pGameUIDialog = this->m_pGameUIDialog;
  this->m_iCurPriority = 0x7FFFFFFF;
  this->m_iHudDisplayUntil = 0;
  this->m_iMessageDisplayUntil = 0;
  m_pGameUIDialog->SetVisible(this: m_pGameUIDialog, a2: false);
  m_pHudMessage = this->m_pHudMessage;
  vgui::AnimationController::StartAnimationSequence(
    this: m_pHudMessage->m_pAnimationController,
    sequenceName: "PluginMessageHide");
  m_pHudMessage->m_pExtraPanelIcon->SetVisible(this: m_pHudMessage->m_pExtraPanelIcon, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1008D750
// Name: public: void CPluginUIManager::GetHudMessagePosition(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginUIManager::GetHudMessagePosition(CPluginUIManager *this, int *x, int *y, int *wide, int *tall)
{
  CPluginHudMessage *m_pHudMessage; // ecx

  m_pHudMessage = this->m_pHudMessage;
  if ( m_pHudMessage != nullptr )
  {
    vgui::Panel::GetBounds(this: m_pHudMessage, x, y, wide, tall);
  }
  else
  {
    *tall = 0;
    *wide = 0;
    *y = 0;
    *x = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D7A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPluginUIManager::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPluginUIManager::GetMessageMap(CPluginUIManager *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPluginUIManager::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPluginUIManager::GetMessageMap'::`2'::s_pMap;
  `CPluginUIManager::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPluginUIManager");
  `CPluginUIManager::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008D7D0
// Name: public: virtual struct PanelAnimationMap __near * CPluginUIManager::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPluginUIManager::GetAnimMap(CPluginUIManager *this)
{
  return FindOrAddPanelAnimationMap(className: "CPluginUIManager");
}

//------------------------------------------------------------------------------
// Address: 0x1008D7E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPluginUIManager::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPluginUIManager::GetKBMap(CPluginUIManager *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPluginUIManager::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPluginUIManager::GetKBMap'::`2'::s_pMap;
  `CPluginUIManager::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPluginUIManager");
  `CPluginUIManager::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008D810
// Name: public: virtual struct vgui::PanelMessageMap __near * CPluginMenu::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPluginMenu::GetMessageMap(CPluginMenu *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPluginMenu::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPluginMenu::GetMessageMap'::`2'::s_pMap;
  `CPluginMenu::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPluginMenu");
  `CPluginMenu::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008D840
// Name: public: virtual struct PanelAnimationMap __near * CPluginMenu::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPluginMenu::GetAnimMap(CPluginMenu *this)
{
  return FindOrAddPanelAnimationMap(className: "CPluginMenu");
}

//------------------------------------------------------------------------------
// Address: 0x1008D850
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPluginMenu::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPluginMenu::GetKBMap(CPluginMenu *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPluginMenu::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPluginMenu::GetKBMap'::`2'::s_pMap;
  `CPluginMenu::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPluginMenu");
  `CPluginMenu::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008D980
// Name: public: virtual struct vgui::PanelMessageMap __near * CPluginGameUIDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPluginGameUIDialog::GetMessageMap(CPluginGameUIDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPluginGameUIDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPluginGameUIDialog::GetMessageMap'::`2'::s_pMap;
  `CPluginGameUIDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPluginGameUIDialog");
  `CPluginGameUIDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008D9B0
// Name: public: virtual struct PanelAnimationMap __near * CPluginGameUIDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPluginGameUIDialog::GetAnimMap(CPluginGameUIDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CPluginGameUIDialog");
}

//------------------------------------------------------------------------------
// Address: 0x1008D9C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPluginGameUIDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPluginGameUIDialog::GetKBMap(CPluginGameUIDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPluginGameUIDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPluginGameUIDialog::GetKBMap'::`2'::s_pMap;
  `CPluginGameUIDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPluginGameUIDialog");
  `CPluginGameUIDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008D9F0
// Name: public: CPluginGameUIDialog::CPluginGameUIDialog(void)
// Source: json
//------------------------------------------------------------------------------
CPluginGameUIDialog *__thiscall CPluginGameUIDialog::CPluginGameUIDialog(CPluginGameUIDialog *this)
{
  vgui::PanelMessageMap *v2; // edi
  PanelAnimationMap *v3; // edi
  vgui::PanelKeyBindingMap *v4; // edi
  CPluginMenu *v5; // eax
  CPluginMenu *v6; // eax
  vgui::RichText *v7; // eax
  vgui::RichText *v8; // eax
  vgui::Label *v9; // eax
  vgui::Label *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Label *v13; // eax
  vgui::Label *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax

  vgui::Frame::Frame(this, parent: nullptr, panelName: "Plugins", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CPluginGameUIDialog_vtbl *)&CPluginGameUIDialog::`vftable';
  if ( `CPluginGameUIDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CPluginGameUIDialog::ChainToMap'::`2'::chained = 1;
    v2 = vgui::FindOrAddPanelMessageMap(className: "CPluginGameUIDialog");
    v2->pfnClassName = CPluginGameUIDialog::GetPanelClassName;
    v2->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CPluginGameUIDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPluginGameUIDialog::ChainToAnimationMap'::`2'::chained = 1;
    v3 = FindOrAddPanelAnimationMap(className: "CPluginGameUIDialog");
    v3->pfnClassName = CPluginGameUIDialog::GetPanelClassName;
    v3->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CPluginGameUIDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPluginGameUIDialog::KB_ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelKeyBindingMap(className: "CPluginGameUIDialog");
    v4->pfnClassName = CPluginGameUIDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Frame::SetTitle(this, title: "Plugins", surfaceTitle: true);
  vgui::Panel::SetAlpha(this, alpha: 255);
  vgui::Panel::SetScheme(this, tag: "Tracker");
  this->m_szEntryCommand[0] = 0;
  v5 = (CPluginMenu *)MemAlloc_Alloc(nSize: 0x180u);
  if ( v5 != nullptr )
    v6 = CPluginMenu::CPluginMenu(this: v5, parent: this);
  else
    v6 = nullptr;
  this->m_Menu = v6;
  v7 = (vgui::RichText *)MemAlloc_Alloc(nSize: 0x220u);
  if ( v7 != nullptr )
    v8 = vgui::RichText::RichText(this: v7, parent: this, panelName: "Rich");
  else
    v8 = nullptr;
  this->m_RichText = v8;
  v9 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v9 != nullptr )
    v10 = vgui::Label::Label(this: v9, parent: this, panelName: "Label", text: defaultValue);
  else
    v10 = nullptr;
  this->m_Message = v10;
  v11 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: "Entry");
  else
    v12 = nullptr;
  this->m_Entry = v12;
  v13 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v13 != nullptr )
    v14 = vgui::Label::Label(this: v13, parent: this, panelName: "EntryLabel", text: defaultValue);
  else
    v14 = nullptr;
  this->m_EntryLabel = v14;
  v15 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v15 != nullptr )
    v16 = vgui::Button::Button(
            this: v15,
            parent: this,
            panelName: "Close",
            text: defaultValue,
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v16 = nullptr;
  this->m_CloseButton = v16;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource/UI/Plugin.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::InvalidateLayout(this, layoutNow: false, reloadScheme: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008DC20
// Name: protected: virtual void CPluginGameUIDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginGameUIDialog::OnCommand(CPluginGameUIDialog *this, const char *cmd)
{
  vgui::CTreeViewListControl *v3; // ecx
  ECommandTarget_t TraceType; // eax
  vgui::CTreeViewListControl *v5; // ecx
  ECommandTarget_t v6; // eax
  vgui::CTreeViewListControl *v7; // ecx
  ECommandTarget_t v8; // eax
  char userCMD[512]; // [esp+8h] [ebp-300h] BYREF
  char entryText[256]; // [esp+208h] [ebp-100h] BYREF

  if ( _V_stricmp(s1: cmd, s2: "close") != 0 )
  {
    vgui::Frame::OnCommand(this, command: cmd);
  }
  else
  {
    if ( _V_strlen(str: this->m_szEntryCommand) > 0 )
    {
      this->m_Entry->GetText_2(this: this->m_Entry, a2: entryText, a3: 255);
      V_snprintf(pDest: userCMD, maxLen: 512, pFormat: "%s %s\n", this->m_szEntryCommand, entryText);
      TraceType = CTraceFilter::GetTraceType(this: v3);
      Cbuf_AddExecutionMarker(eTarget: TraceType, marker: eCmdExecutionMarker_Enable_FCVAR_CLIENTCMD_CAN_EXECUTE);
      v6 = CTraceFilter::GetTraceType(this: v5);
      Cbuf_AddText(eTarget: v6, pText: userCMD, nTickDelay: 0);
      v8 = CTraceFilter::GetTraceType(this: v7);
      Cbuf_AddExecutionMarker(eTarget: v8, marker: eCmdExecutionMarker_Disable_FCVAR_CLIENTCMD_CAN_EXECUTE);
    }
    this->Close(this);
    CPluginUIManager::OnPanelClosed(this: g_PluginManager);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008DD30
// Name: public: virtual struct PanelAnimationMap __near * CMessage::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMessage::GetAnimMap(CMessage *this)
{
  return FindOrAddPanelAnimationMap(className: "CMessage");
}

//------------------------------------------------------------------------------
// Address: 0x1008DD70
// Name: public: CMessage::CMessage(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMessage *__thiscall CMessage::CMessage(CMessage *this, vgui::Panel *parent, const char *panelName, const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Label::Label(this, parent, panelName, text);
  this->__vftable = (CMessage_vtbl *)&CMessage::`vftable';
  if ( `CMessage::ChainToMap'::`2'::chained == 0 )
  {
    `CMessage::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CMessage");
    v5->pfnClassName = CMessage::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Label");
  }
  if ( `CMessage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMessage::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CMessage");
    v6->pfnClassName = CMessage::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Label");
  }
  if ( `CMessage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMessage::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CMessage");
    v7->pfnClassName = CMessage::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Label");
  }
  this->m_bHasExtraPanel = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008DE70
// Name: public: virtual struct vgui::PanelMessageMap __near * CPluginHudMessage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPluginHudMessage::GetMessageMap(CPluginHudMessage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPluginHudMessage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPluginHudMessage::GetMessageMap'::`2'::s_pMap;
  `CPluginHudMessage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPluginHudMessage");
  `CPluginHudMessage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008DEA0
// Name: public: virtual struct PanelAnimationMap __near * CPluginHudMessage::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPluginHudMessage::GetAnimMap(CPluginHudMessage *this)
{
  return FindOrAddPanelAnimationMap(className: "CPluginHudMessage");
}

//------------------------------------------------------------------------------
// Address: 0x1008DEB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPluginHudMessage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPluginHudMessage::GetKBMap(CPluginHudMessage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPluginHudMessage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPluginHudMessage::GetKBMap'::`2'::s_pMap;
  `CPluginHudMessage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPluginHudMessage");
  `CPluginHudMessage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008DEE0
// Name: public: CPluginHudMessage::CPluginHudMessage(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CPluginHudMessage *__thiscall CPluginHudMessage::CPluginHudMessage(CPluginHudMessage *this, unsigned int parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::ImagePanel *v6; // eax
  vgui::ImagePanel *v7; // eax
  CMessage *v8; // eax
  CMessage *v9; // eax
  vgui::AnimationController *v10; // eax
  vgui::AnimationController *v11; // eax

  vgui::Frame::Frame(this, parent: nullptr, panelName: "PluginHudMessage", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CPluginHudMessage_vtbl *)&CPluginHudMessage::`vftable';
  if ( `CPluginHudMessage::ChainToMap'::`2'::chained == 0 )
  {
    `CPluginHudMessage::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CPluginHudMessage");
    v3->pfnClassName = CPluginHudMessage::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CPluginHudMessage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPluginHudMessage::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CPluginHudMessage");
    v4->pfnClassName = CPluginHudMessage::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CPluginHudMessage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPluginHudMessage::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CPluginHudMessage");
    v5->pfnClassName = CPluginHudMessage::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_fgColor = 0;
  vgui::Panel::SetParent(this, newParent: parent);
  vgui::Panel::SetVisible(this, state: false);
  vgui::Panel::SetAlpha(this, alpha: 255);
  vgui::Panel::SetMinimumSize(this, wide: 10, tall: 10);
  vgui::Panel::SetScheme(this, tag: "ClientScheme");
  vgui::Frame::SetMoveable(this, state: false);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: false);
  vgui::Panel::SetMouseInputEnabled(this, state: false);
  vgui::Frame::SetTitleBarVisible(this, state: false);
  v6 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v6 != nullptr )
    v7 = vgui::ImagePanel::ImagePanel(this: v6, parent: this, name: "ExtraPanelIcon");
  else
    v7 = nullptr;
  this->m_pExtraPanelIcon = v7;
  v7->SetVisible(this: v7, a2: false);
  v8 = (CMessage *)MemAlloc_Alloc(nSize: 0x1A8u);
  if ( v8 != nullptr )
    v9 = CMessage::CMessage(this: v8, parent: this, panelName: "Msg", text: defaultValue);
  else
    v9 = nullptr;
  this->m_Message = v9;
  v9->SetVisible(this: v9, a2: false);
  v10 = (vgui::AnimationController *)MemAlloc_Alloc(nSize: 0x1C8u);
  if ( v10 != nullptr )
    v11 = vgui::AnimationController::AnimationController(this: v10, parent: nullptr);
  else
    v11 = nullptr;
  this->m_pAnimationController = v11;
  v11->SetParent(this: v11, a2: parent);
  vgui::AnimationController::SetScriptFile(
    this: this->m_pAnimationController,
    sizingPanel: parent,
    fileName: "scripts/plugin_animations.txt",
    wipeAll: false);
  this->m_pAnimationController->SetProportional(this: this->m_pAnimationController, a2: false);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource/UI/PluginHud.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::InvalidateLayout(this, layoutNow: false, reloadScheme: false);
  vgui::Panel::GetSize(this, wide: &this->m_iTargetW, tall: &this->m_iTargetH);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008E150
// Name: protected: virtual void CPluginHudMessage::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginHudMessage::ApplySchemeSettings(CPluginHudMessage *this, vgui::IScheme *pScheme)
{
  vgui::ImagePanel_vtbl *v3; // edi
  vgui::IImage *v4; // eax
  vgui::IScheme *v5; // edi
  CPluginHudMessage_vtbl *v6; // eax
  vgui::IScheme_vtbl *v7; // ebx
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  _BYTE v10[4]; // [esp+Ch] [ebp-8h] BYREF
  CPluginHudMessage_vtbl *v11; // [esp+10h] [ebp-4h]

  v3 = this->m_pExtraPanelIcon->__vftable;
  v4 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "plugin/message_waiting", a3: 1);
  v3->SetImage(this: this->m_pExtraPanelIcon, a2: v4);
  v5 = pScheme;
  vgui::Frame::ApplySchemeSettings(this, pScheme);
  v6 = this->__vftable;
  v7 = v5->__vftable;
  pScheme = (vgui::IScheme *)-1073741824;
  v11 = v6;
  v8 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, const char *, int))v7->GetColor)(
                   a1: v5,
                   a2: &pScheme,
                   a3: "TransparentBlack",
                   a4: -1073741824);
  v9 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))v7->GetColor)(
                   a1: v5,
                   a2: v10,
                   a3: "Plugins.BgColor",
                   a4: *v8);
  ((void (__thiscall *)(CPluginHudMessage *, _DWORD))v11->SetBgColor)(a1: this, a2: *v9);
  this->SetPaintBackgroundType(this, a2: 2);
  ((void (__thiscall *)(CMessage *, _DWORD))this->m_Message->SetFgColor)(
    a1: this->m_Message,
    a2: *(_DWORD *)&this->m_fgColor);
  this->m_pExtraPanelIcon->SetVisible(this: this->m_pExtraPanelIcon, a2: !this->m_bHidingControl);
}

//------------------------------------------------------------------------------
// Address: 0x1008E280
// Name: public: CPluginUIManager::CPluginUIManager(void)
// Source: json
//------------------------------------------------------------------------------
CPluginUIManager *__thiscall CPluginUIManager::CPluginUIManager(CPluginUIManager *this)
{
  vgui::PanelMessageMap *v2; // edi
  PanelAnimationMap *v3; // edi
  vgui::PanelKeyBindingMap *v4; // edi
  CPluginGameUIDialog *v5; // eax
  CPluginGameUIDialog *v6; // eax
  IEngineVGuiInternal *v7; // eax
  CPluginGameUIDialog_vtbl *v8; // edi
  int v9; // eax
  CPluginHudMessage *v10; // edi
  IEngineVGuiInternal *v11; // eax
  unsigned int v12; // eax
  CPluginHudMessage *v13; // eax

  vgui::Panel::Panel(this, parent: nullptr, panelName: "PluginManager");
  this->__vftable = (CPluginUIManager_vtbl *)&CPluginUIManager::`vftable';
  if ( `CPluginUIManager::ChainToMap'::`2'::chained == 0 )
  {
    `CPluginUIManager::ChainToMap'::`2'::chained = 1;
    v2 = vgui::FindOrAddPanelMessageMap(className: "CPluginUIManager");
    v2->pfnClassName = CPluginUIManager::GetPanelClassName;
    v2->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CPluginUIManager::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPluginUIManager::ChainToAnimationMap'::`2'::chained = 1;
    v3 = FindOrAddPanelAnimationMap(className: "CPluginUIManager");
    v3->pfnClassName = CPluginUIManager::GetPanelClassName;
    v3->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CPluginUIManager::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPluginUIManager::KB_ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelKeyBindingMap(className: "CPluginUIManager");
    v4->pfnClassName = CPluginUIManager::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_iCurPriority = 0x7FFFFFFF;
  this->m_iMessageDisplayUntil = 0;
  this->m_iHudDisplayUntil = 0;
  this->m_bShutdown = false;
  v5 = (CPluginGameUIDialog *)MemAlloc_Alloc(nSize: 0x32Cu);
  if ( v5 != nullptr )
    v6 = CPluginGameUIDialog::CPluginGameUIDialog(this: v5);
  else
    v6 = nullptr;
  this->m_pGameUIDialog = v6;
  v7 = EngineVGui();
  v8 = this->m_pGameUIDialog->__vftable;
  v9 = v7->GetPanel(this: v7, a2: PANEL_GAMEUIDLL);
  v8->SetParent(this: this->m_pGameUIDialog, a2: v9);
  v10 = (CPluginHudMessage *)MemAlloc_Alloc(nSize: 0x230u);
  if ( v10 != nullptr )
  {
    v11 = EngineVGui();
    v12 = v11->GetPanel(this: v11, a2: PANEL_CLIENTDLL);
    v13 = CPluginHudMessage::CPluginHudMessage(this: v10, parent: v12);
  }
  else
  {
    v13 = nullptr;
  }
  this->m_pHudMessage = v13;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008E420
// Name: protected: virtual void CPluginUIManager::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginUIManager::OnTick(CPluginUIManager *this)
{
  IEngineVGuiInternal *v2; // eax
  double m_iMessageDisplayUntil; // [esp+4h] [ebp-8h]
  int m_iHudDisplayUntil; // [esp+8h] [ebp-4h]

  if ( !this->m_bShutdown )
  {
    if ( this->m_iMessageDisplayUntil != 0 )
    {
      v2 = EngineVGui();
      if ( !v2->IsGameUIVisible(this: v2) )
      {
        m_iMessageDisplayUntil = (double)this->m_iMessageDisplayUntil;
        if ( _Plat_FloatTime(a1: this) > m_iMessageDisplayUntil )
        {
          this->m_pGameUIDialog->SetVisible(this: this->m_pGameUIDialog, a2: false);
          CPluginHudMessage::Hide(this: this->m_pHudMessage);
          this->m_iMessageDisplayUntil = 0;
          this->m_iCurPriority = 0x7FFFFFFF;
        }
      }
    }
    m_iHudDisplayUntil = this->m_iHudDisplayUntil;
    if ( m_iHudDisplayUntil != 0 && _Plat_FloatTime(a1: this) > (double)m_iHudDisplayUntil )
    {
      CPluginHudMessage::StartHiding(this: this->m_pHudMessage);
      this->m_iHudDisplayUntil = 0;
    }
    CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E4F0
// Name: public: void CPluginUIManager::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginUIManager::Shutdown(CPluginUIManager *this)
{
  vgui::IVGui *v2; // edi
  vgui::IVGui_vtbl *v3; // ebx
  int v4; // eax
  CPluginHudMessage *m_pHudMessage; // edi

  v2 = g_pVGui;
  v3 = g_pVGui->__vftable;
  v4 = this->GetVPanel(this);
  v3->RemoveTickSignal(this: v2, a2: v4);
  m_pHudMessage = this->m_pHudMessage;
  vgui::AnimationController::StartAnimationSequence(
    this: m_pHudMessage->m_pAnimationController,
    sequenceName: "PluginMessageHide");
  m_pHudMessage->m_pExtraPanelIcon->SetVisible(this: m_pHudMessage->m_pExtraPanelIcon, a2: false);
  this->m_pGameUIDialog->SetVisible(this: this->m_pGameUIDialog, a2: false);
  this->MarkForDeletion(this);
  this->m_bShutdown = true;
}

//------------------------------------------------------------------------------
// Address: 0x1008E560
// Name: public: void CPluginUIManager::Show(enum DIALOG_TYPE,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPluginUIManager::Show(CPluginUIManager *this, DIALOG_TYPE type, float kv)
{
  DIALOG_TYPE v3; // ebx
  KeyValues *v4; // esi
  const char *String; // eax
  int Int; // eax
  int m_iCurPriority; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  CPluginGameUIDialog *m_pGameUIDialog; // ecx
  float v17; // eax
  const wchar_t *WString; // eax
  const char *Name; // eax
  Color v20; // [esp-4h] [ebp-14h]
  int v21; // [esp-4h] [ebp-14h]
  int defaultValue; // [esp+0h] [ebp-10h]

  v3 = type;
  v4 = (KeyValues *)LODWORD(kv);
  if ( type == DIALOG_ASKCONNECT )
  {
    kv = KeyValues::GetFloat(this: (KeyValues *)LODWORD(kv), keyName: "time", defaultValue: 4.0);
    String = KeyValues::GetString(this: v4, keyName: "title", defaultValue: nullptr);
    if ( String != nullptr )
      ShowAskConnectPanel(pHostName: String, flDuration: kv);
    else
      DevMsg(a1: "Ignoring DIALOG_ASKCONNECT message. No IP specified.");
  }
  else
  {
    Int = KeyValues::GetInt(this: (KeyValues *)LODWORD(kv), keyName: "level", defaultValue: 0x7FFFFFFF);
    m_iCurPriority = this->m_iCurPriority;
    if ( Int >= m_iCurPriority )
    {
      defaultValue = this->m_iCurPriority;
      v21 = Int;
      Name = KeyValues::GetName(this: v4);
      DevMsg(a1: "Ignoring message %s, %i < %i\n", Name, v21, defaultValue);
    }
    else
    {
      this->m_iCurPriority = Int;
      if ( v3 != DIALOG_MSG )
      {
        if ( KeyValues::GetInt(this: v4, keyName: "time", defaultValue: 10) > 10
          && KeyValues::GetInt(this: v4, keyName: "time", defaultValue: 10) >= 200 )
        {
          LODWORD(kv) = 200;
          v14 = _Plat_FloatTime(a1: v9);
          v13 = v14 + (double)SLODWORD(kv);
        }
        else
        {
          if ( KeyValues::GetInt(this: v4, keyName: "time", defaultValue: 10) <= 10 )
            LODWORD(kv) = 10;
          else
            kv = COERCE_FLOAT(KeyValues::GetInt(this: v4, keyName: "time", defaultValue: 10));
          v12 = _Plat_FloatTime(a1: v10);
          v13 = v12 + (double)SLODWORD(kv);
        }
      }
      else
      {
        v13 = _Plat_FloatTime(a1: m_iCurPriority) + 10.0;
      }
      this->m_iMessageDisplayUntil = (int)v13;
      v15 = _Plat_FloatTime(a1: v11) + 10.0;
      m_pGameUIDialog = this->m_pGameUIDialog;
      this->m_iHudDisplayUntil = (int)v15;
      m_pGameUIDialog->Show(this: m_pGameUIDialog, a2: v3, a3: v4);
      kv = NAN;
      if ( KeyValues::IsEmpty(this: v4, keyName: "color") )
      {
        v17 = kv;
      }
      else
      {
        kv = 0.0;
        v17 = *(float *)KeyValues::GetColor(
                          this: v4,
                          result: (Color *)&type,
                          keyName: "color",
                          defaultColor: (const Color *)&kv);
      }
      v20 = (Color)LODWORD(v17);
      WString = KeyValues::GetWString(this: v4, keyName: "title", defaultValue: &wszText);
      CPluginHudMessage::ShowMessage(
        this: this->m_pHudMessage,
        text: WString,
        time: 10,
        clr: v20,
        bHasExtraPanel: v3 != DIALOG_MSG);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008E740
// Name: void PluginHelpers_Menu(class SVC_Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PluginHelpers_Menu(SVC_Menu *msg)
{
  CPluginUIManager *v1; // eax
  CPluginUIManager *v2; // eax

  if ( msg->m_MenuKeyValues != nullptr
    && cl_showpluginmessages.m_pParent != nullptr
    && cl_showpluginmessages.m_pParent->m_Value.m_nValue != 0 )
  {
    v1 = g_PluginManager;
    if ( g_PluginManager == nullptr )
    {
      v2 = (CPluginUIManager *)MemAlloc_Alloc(nSize: 0x168u);
      if ( v2 != nullptr )
        v1 = CPluginUIManager::CPluginUIManager(this: v2);
      else
        v1 = nullptr;
      g_PluginManager = v1;
    }
    CPluginUIManager::Show(this: v1, type: msg->m_Type, kv: *(float *)&msg->m_MenuKeyValues);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102AFE50
// Name: public: virtual class vgui::Panel __near * vgui::Label::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Label *__thiscall vgui::Label::HasHotkey(vgui::Label *this, wchar_t key)
{
  unsigned __int16 v2; // si

  v2 = key;
  if ( iswalnum(c: key) != 0 )
    v2 = towlower(c: key);
  return this->_hotkey != v2 ? nullptr : this;
}

//------------------------------------------------------------------------------
// Address: 0x102B14B0
// Name: public: virtual class vgui::IImage __near * vgui::Label::GetImageAtIndex(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::Label::GetImageAtIndex(vgui::Label *this, int index)
{
  if ( index < 0 || index >= this->_imageDar.m_Size )
    return nullptr;
  else
    return this->_imageDar.m_Memory.m_pMemory[index].image;
}

//------------------------------------------------------------------------------
// Address: 0x102B1A40
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Label::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Label::GetMessageMap(vgui::Label *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Label::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Label::GetMessageMap'::`2'::s_pMap;
  `vgui::Label::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Label");
  `vgui::Label::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102B1A70
// Name: public: virtual struct PanelAnimationMap __near * vgui::Label::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Label::GetAnimMap(vgui::Label *this)
{
  return FindOrAddPanelAnimationMap(className: "Label");
}

//------------------------------------------------------------------------------
// Address: 0x102B1A80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Label::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Label::GetKBMap(vgui::Label *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Label::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Label::GetKBMap'::`2'::s_pMap;
  `vgui::Label::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  `vgui::Label::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x103184E0
// Name: _dynamic_initializer_for__plugin_print_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_print_command__()
{
  ConCommand::ConCommand(
    this: &plugin_print_command,
    pName: "plugin_print",
    callback: plugin_print,
    pHelpString: "Prints details about loaded plugins",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_print_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318510
// Name: _dynamic_initializer_for__plugin_pause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_pause_command__()
{
  ConCommand::ConCommand(
    this: &plugin_pause_command,
    pName: "plugin_pause",
    callback: plugin_pause,
    pHelpString: "plugin_pause <index> : pauses a loaded plugin",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_pause_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318540
// Name: _dynamic_initializer_for__plugin_unpause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_unpause_command__()
{
  ConCommand::ConCommand(
    this: &plugin_unpause_command,
    pName: "plugin_unpause",
    callback: plugin_unpause,
    pHelpString: "plugin_unpause <index> : unpauses a disabled plugin",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_unpause_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318570
// Name: _dynamic_initializer_for__plugin_pause_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_pause_all_command__()
{
  ConCommand::ConCommand(
    this: &plugin_pause_all_command,
    pName: "plugin_pause_all",
    callback: plugin_pause_all,
    pHelpString: "pauses all loaded plugins",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_pause_all_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103185A0
// Name: _dynamic_initializer_for__plugin_unpause_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_unpause_all_command__()
{
  ConCommand::ConCommand(
    this: &plugin_unpause_all_command,
    pName: "plugin_unpause_all",
    callback: plugin_unpause_all,
    pHelpString: "unpauses all disabled plugins",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_unpause_all_command__);
}

//------------------------------------------------------------------------------
// Address: 0x103185D0
// Name: _dynamic_initializer_for__plugin_load_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_load_command__()
{
  ConCommand::ConCommand(
    this: &plugin_load_command,
    pName: "plugin_load",
    callback: plugin_load,
    pHelpString: "plugin_load <filename> : loads a plugin",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_load_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10318600
// Name: _dynamic_initializer_for__plugin_unload_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__plugin_unload_command__()
{
  ConCommand::ConCommand(
    this: &plugin_unload_command,
    pName: "plugin_unload",
    callback: plugin_unload,
    pHelpString: "plugin_unload <index> : unloads a plugin",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__plugin_unload_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10324860
// Name: _dynamic_atexit_destructor_for__plugin_print_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_print_command__()
{
  ConCommand::~ConCommand(this: &plugin_print_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324870
// Name: _dynamic_atexit_destructor_for__plugin_pause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_pause_command__()
{
  ConCommand::~ConCommand(this: &plugin_pause_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324880
// Name: _dynamic_atexit_destructor_for__plugin_unpause_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_unpause_command__()
{
  ConCommand::~ConCommand(this: &plugin_unpause_command);
}

//------------------------------------------------------------------------------
// Address: 0x10324890
// Name: _dynamic_atexit_destructor_for__plugin_pause_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_pause_all_command__()
{
  ConCommand::~ConCommand(this: &plugin_pause_all_command);
}

//------------------------------------------------------------------------------
// Address: 0x103248A0
// Name: _dynamic_atexit_destructor_for__plugin_unpause_all_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_unpause_all_command__()
{
  ConCommand::~ConCommand(this: &plugin_unpause_all_command);
}

//------------------------------------------------------------------------------
// Address: 0x103248B0
// Name: _dynamic_atexit_destructor_for__plugin_load_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_load_command__()
{
  ConCommand::~ConCommand(this: &plugin_load_command);
}

//------------------------------------------------------------------------------
// Address: 0x103248C0
// Name: _dynamic_atexit_destructor_for__plugin_unload_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__plugin_unload_command__()
{
  ConCommand::~ConCommand(this: &plugin_unload_command);
}

} // namespace engine_xlsp
