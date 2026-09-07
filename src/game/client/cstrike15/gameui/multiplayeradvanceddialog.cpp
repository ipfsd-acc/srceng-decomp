// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/multiplayeradvanceddialog.cpp
// Functions: 13
// ============================================================

#include "game\client\cstrike15\gameui\multiplayeradvanceddialog.h"

//------------------------------------------------------------------------------
// Address: 0x101D74B0
// Name: public: static char const __near * CMultiplayerAdvancedDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMultiplayerAdvancedDialog::GetPanelClassName()
{
  return "CMultiplayerAdvancedDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101D74F0
// Name: private: virtual void CMultiplayerAdvancedDialog::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayerAdvancedDialog::OnClose(CMultiplayerAdvancedDialog *this)
{
  vgui::Frame::OnClose(this);
  this->MarkForDeletion(this);
}

//------------------------------------------------------------------------------
// Address: 0x101D7510
// Name: private: void CMultiplayerAdvancedDialog::GatherCurrentValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayerAdvancedDialog::GatherCurrentValues(CMultiplayerAdvancedDialog *this)
{
  mpcontrol_t *i; // edi
  vgui::ComboBox *pControl; // ecx
  CScriptObject *pScrObj; // esi
  bool v4; // zf
  const char *v5; // eax
  int ActiveItem; // eax
  CScriptListItem *pListItems; // ecx
  int v8; // edx
  int v9; // eax
  char v10; // cl
  char strValue[256]; // [esp+0h] [ebp-200h] BYREF
  char szValue[256]; // [esp+100h] [ebp-100h] BYREF

  if ( this->m_pDescription != nullptr )
  {
    for ( i = this->m_pList; i != nullptr; i = i->next )
    {
      pControl = (vgui::ComboBox *)i->pControl;
      pScrObj = i->pScrObj;
      if ( pControl != nullptr )
      {
        switch ( pScrObj->type )
        {
          case O_BOOL:
            v4 = ((unsigned __int8 (__thiscall *)(vgui::ComboBox *))pControl->SetVerticalScrollbar)(a1: pControl) == 0;
            v5 = "1";
            if ( v4 )
              v5 = "0";
            V_snprintf(pDest: szValue, maxLen: 0x100u, pFormat: "%s", v5);
            break;
          case O_NUMBER:
          case O_STRING:
            pControl->GetText_2(this: pControl, a2: strValue, a3: 256);
            V_snprintf(pDest: szValue, maxLen: 0x100u, pFormat: "%s", strValue);
            break;
          case O_LIST:
            ActiveItem = vgui::ComboBox::GetActiveItem(this: pControl);
            pListItems = pScrObj->pListItems;
            if ( pListItems != nullptr )
            {
              while ( 1 )
              {
                v8 = ActiveItem--;
                if ( v8 == 0 )
                  break;
                pListItems = pListItems->pNext;
                if ( pListItems == nullptr )
                  goto LABEL_13;
              }
              V_snprintf(pDest: szValue, maxLen: 0x100u, pFormat: "%s", pListItems->szValue);
            }
            else
            {
LABEL_13:
              V_snprintf(pDest: szValue, maxLen: 0x100u, pFormat: "%s", pScrObj->defValue);
            }
            break;
          default:
            break;
        }
        UTIL_StripInvalidCharacters(pszInput: szValue, maxlen: 256);
        v9 = 0;
        do
        {
          v10 = szValue[v9];
          strValue[v9++] = v10;
        }
        while ( v10 != 0 );
        CScriptObject::SetCurValue(this: pScrObj, strValue);
      }
      else
      {
        CScriptObject::SetCurValue(this: pScrObj, strValue: pScrObj->defValue);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D7690
// Name: private: void CMultiplayerAdvancedDialog::DestroyControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayerAdvancedDialog::DestroyControls(CMultiplayerAdvancedDialog *this)
{
  mpcontrol_t *m_pList; // esi
  vgui::Panel *pControl; // ecx
  mpcontrol_t *next; // edi
  vgui::Label *pPrompt; // ecx

  m_pList = this->m_pList;
  if ( m_pList != nullptr )
  {
    do
    {
      pControl = m_pList->pControl;
      next = m_pList->next;
      if ( pControl != nullptr )
        ((void (__thiscall *)(vgui::Panel *, int))pControl->dtr_Panel)(a1: pControl, a2: 1);
      pPrompt = m_pList->pPrompt;
      if ( pPrompt != nullptr )
        ((void (__thiscall *)(vgui::Label *, int))pPrompt->dtr_Panel)(a1: pPrompt, a2: 1);
      ((void (__thiscall *)(mpcontrol_t *, int))m_pList->dtr_Panel)(a1: m_pList, a2: 1);
      m_pList = next;
    }
    while ( next != nullptr );
    this->m_pList = nullptr;
  }
  else
  {
    this->m_pList = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D7720
// Name: private: void CMultiplayerAdvancedDialog::SaveValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayerAdvancedDialog::SaveValues(CMultiplayerAdvancedDialog *this)
{
  CInfoDescription *m_pDescription; // ecx
  void *v3; // eax
  void *v4; // esi

  CMultiplayerAdvancedDialog::GatherCurrentValues(this);
  m_pDescription = this->m_pDescription;
  if ( m_pDescription != nullptr )
  {
    CDescription::WriteToConfig(this: m_pDescription);
    g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: "cfg", a3: nullptr);
    v3 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: "cfg/user.scr", a3: "wb", a4: 0);
    v4 = v3;
    if ( v3 != nullptr )
    {
      CDescription::WriteToScriptFile(this: this->m_pDescription, fp: v3);
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D7790
// Name: public: virtual void CInfoDescription::WriteScriptHeader(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInfoDescription::WriteScriptHeader(CInfoDescription *this, void *fp)
{
  char timeString[64]; // [esp+Ch] [ebp-68h] BYREF
  tm newtime; // [esp+4Ch] [ebp-28h] BYREF
  char am_pm[4]; // [esp+70h] [ebp-4h] BYREF

  strcpy(am_pm, "AM");
  _Plat_GetLocalTime(a1: &newtime);
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: this->m_pszHintText);
  _Plat_GetTimeString(a1: &newtime, a2: timeString, a3: 64);
  g_pFullFileSystem->FPrintf(
    this: g_pFullFileSystem,
    a2: fp,
    a3: "// Half-Life User Info Configuration Layout Script (stores last settings chosen, too)\r\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "// File generated:  %.19s %s\r\n", timeString, am_pm);
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "//\r\n//\r\n// Cvar\t-\tSetting\r\n\r\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "VERSION %.1f\r\n\r\n", 0, 1072693248);
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "DESCRIPTION INFO_OPTIONS\r\n{\r\n");
}

//------------------------------------------------------------------------------
// Address: 0x101D7860
// Name: public: virtual void CInfoDescription::WriteFileHeader(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInfoDescription::WriteFileHeader(CInfoDescription *this, void *fp)
{
  char timeString[64]; // [esp+4h] [ebp-68h] BYREF
  tm newtime; // [esp+44h] [ebp-28h] BYREF
  char am_pm[4]; // [esp+68h] [ebp-4h] BYREF

  strcpy(am_pm, "AM");
  _Plat_GetLocalTime(a1: &newtime);
  _Plat_GetTimeString(a1: &newtime, a2: timeString, a3: 64);
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "// Half-Life User Info Configuration Settings\r\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "// DO NOT EDIT, GENERATED BY HALF-LIFE\r\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "// File generated:  %.19s %s\r\n", timeString, am_pm);
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "//\r\n//\r\n// Cvar\t-\tSetting\r\n\r\n");
}

//------------------------------------------------------------------------------
// Address: 0x101D7900
// Name: private: virtual void CMultiplayerAdvancedDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayerAdvancedDialog::OnCommand(CMultiplayerAdvancedDialog *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "Ok") != 0 )
  {
    vgui::Frame::OnCommand(this, command);
  }
  else
  {
    CMultiplayerAdvancedDialog::SaveValues(this);
    this->OnClose(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D7950
// Name: private: void CMultiplayerAdvancedDialog::CreateControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayerAdvancedDialog::CreateControls(CMultiplayerAdvancedDialog *this)
{
  CMultiplayerAdvancedDialog *v1; // ebx
  CScriptObject *pObjList; // edi
  mpcontrol_t *v3; // eax
  mpcontrol_t *v4; // esi
  objtype_t type; // eax
  vgui::CheckButton *v6; // eax
  char v7; // fl
  vgui::ComboBox *v8; // ebx
  float fdefValue; // xmm0_4
  bool v10; // cf
  bool v11; // zf
  char v12; // sf
  char v13; // of
  char v14; // pf
  vgui::TextEntry *v15; // eax
  vgui::ComboBox *v16; // eax
  CScriptListItem *i; // edi
  vgui::Label *v18; // eax
  vgui::Label *v19; // eax
  mpcontrol_t *m_pList; // eax
  vgui::Panel *objParent; // [esp+8h] [ebp-Ch]
  CScriptObject *pObj; // [esp+10h] [ebp-4h]

  v1 = this;
  CMultiplayerAdvancedDialog::DestroyControls(this);
  pObjList = v1->m_pDescription->pObjList;
  pObj = pObjList;
  objParent = v1->m_pListPanel;
  if ( pObjList != nullptr )
  {
    while ( 1 )
    {
      if ( pObjList->type == O_OBSOLETE )
      {
        pObj = pObjList->pNext;
      }
      else
      {
        v3 = (mpcontrol_t *)MemAlloc_Alloc(nSize: 0x160u);
        v4 = v3 != nullptr ? mpcontrol_t::mpcontrol_t(this: v3, parent: objParent, panelName: "mpcontrol_t") : nullptr;
        type = pObjList->type;
        v4->type = type;
        switch ( type )
        {
          case O_BOOL:
            v6 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
            if ( v6 != nullptr )
            {
              v6 = vgui::CheckButton::CheckButton(
                     this: v6,
                     parent: v4,
                     panelName: "DescCheckButton",
                     text: pObjList->prompt);
              v8 = (vgui::ComboBox *)v6;
            }
            else
            {
              v8 = nullptr;
            }
            fdefValue = pObjList->fdefValue;
            v10 = fdefValue < 0.0;
            v14 = 0;
            v11 = fdefValue == 0.0;
            v12 = 0;
            v13 = 0;
            BYTE1(v6) = v7;
            LOBYTE(v6) = fdefValue != 0.0;
            ((void (__thiscall *)(vgui::ComboBox *, vgui::CheckButton *))v8->IsMultiline)(a1: v8, a2: v6);
            goto LABEL_24;
          case O_NUMBER:
          case O_STRING:
            v15 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
            if ( v15 != nullptr )
              v8 = (vgui::ComboBox *)vgui::TextEntry::TextEntry(this: v15, parent: v4, panelName: "DescTextEntry");
            else
              v8 = nullptr;
            v8->InsertString_2(this: v8, a2: pObjList->defValue);
            goto LABEL_24;
          case O_LIST:
            v16 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
            if ( v16 != nullptr )
              v8 = vgui::ComboBox::ComboBox(
                     this: v16,
                     parent: v4,
                     panelName: "DescComboBox",
                     numLines: 5,
                     allowEdit: false);
            else
              v8 = nullptr;
            for ( i = pObjList->pListItems; i != nullptr; i = i->pNext )
              v8->AddItem_2(this: v8, a2: i->szItemText, a3: nullptr);
            vgui::ComboBox::ActivateItemByRow(this: v8, row: (int)pObj->fdefValue);
            pObjList = pObj;
LABEL_24:
            v4->pControl = v8;
            v1 = this;
            break;
          default:
            break;
        }
        if ( v4->type != O_BOOL )
        {
          v18 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
          if ( v18 != nullptr )
            v19 = vgui::Label::Label(this: v18, parent: v4, panelName: "DescLabel", text: prType);
          else
            v19 = nullptr;
          v4->pPrompt = v19;
          v19->SetContentAlignment(this: v19, a2: a_west);
          v4->pPrompt->SetTextInset(this: v4->pPrompt, a2: 5, a3: 0);
          v4->pPrompt->SetText(this: v4->pPrompt, a2: pObjList->prompt);
        }
        v4->pScrObj = pObjList;
        vgui::Panel::SetSize(this: v4, wide: 100, tall: 28);
        v1->m_pListPanel->AddItem(this: v1->m_pListPanel, a2: v4);
        m_pList = v1->m_pList;
        if ( m_pList != nullptr )
        {
          while ( m_pList->next != nullptr )
            m_pList = m_pList->next;
          m_pList->next = v4;
        }
        else
        {
          v1->m_pList = v4;
        }
        v4->next = nullptr;
        pObj = pObjList->pNext;
      }
      if ( pObj == nullptr )
        break;
      pObjList = pObj;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D7BE0
// Name: public: CMultiplayerAdvancedDialog::CMultiplayerAdvancedDialog(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CMultiplayerAdvancedDialog *__thiscall CMultiplayerAdvancedDialog::CMultiplayerAdvancedDialog(
        CMultiplayerAdvancedDialog *this,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  CPanelListPanel *v10; // eax
  CPanelListPanel *v11; // eax
  CDescription *v12; // eax
  CDescription *v13; // edi
  CInfoDescription *v14; // ecx

  vgui::Frame::Frame(this, parent: nullptr, panelName: "MultiplayerAdvancedDialog", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CMultiplayerAdvancedDialog_vtbl *)&CMultiplayerAdvancedDialog::`vftable';
  if ( `CMultiplayerAdvancedDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CMultiplayerAdvancedDialog::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CMultiplayerAdvancedDialog");
    v3->pfnClassName = CMultiplayerAdvancedDialog::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CMultiplayerAdvancedDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMultiplayerAdvancedDialog::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CMultiplayerAdvancedDialog");
    v4->pfnClassName = CMultiplayerAdvancedDialog::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CMultiplayerAdvancedDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMultiplayerAdvancedDialog::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CMultiplayerAdvancedDialog");
    v5->pfnClassName = CMultiplayerAdvancedDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 372, tall: 160);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetTitle(this, title: "#GameUI_MultiplayerAdvanced", surfaceTitle: true);
  v6 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v6 != nullptr )
    v7 = vgui::Button::Button(
           this: v6,
           parent: this,
           panelName: "Cancel",
           text: "#GameUI_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v7 = nullptr;
  v7->SetCommand(this: v7, a2: "Close");
  v8 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "OK",
           text: "#GameUI_OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v9 = nullptr;
  v9->SetCommand(this: v9, a2: "Ok");
  v10 = (CPanelListPanel *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v10 != nullptr )
    v11 = CPanelListPanel::CPanelListPanel(this: v10, parent: this, panelName: "PanelListPanel", inverseButtons: false);
  else
    v11 = nullptr;
  this->m_pListPanel = v11;
  this->m_pList = nullptr;
  v12 = (CDescription *)MemAlloc_Alloc(nSize: 0x14u);
  v13 = v12;
  if ( v12 != nullptr )
  {
    CDescription::CDescription(this: v12, panel: this->m_pListPanel);
    v13->__vftable = (CDescription_vtbl *)&CInfoDescription::`vftable';
    CDescription::setHint(
      this: v13,
      pszHint: "// NOTE:  THIS FILE IS AUTOMATICALLY REGENERATED, \r\n"
      "//DO NOT EDIT THIS HEADER, YOUR COMMENTS WILL BE LOST IF YOU DO\r\n"
      "// User options script\r\n"
      "//\r\n"
      "// Format:\r\n"
      "//  Version [float]\r\n"
      "//  Options description followed by \r\n"
      "//  Options defaults\r\n"
      "//\r\n"
      "// Option description syntax:\r\n"
      "//\r\n"
      "//  \"cvar\" { \"Prompt\" { type [ type info ] } { default } }\r\n"
      "//\r\n"
      "//  type = \r\n"
      "//   BOOL   (a yes/no toggle)\r\n"
      "//   STRING\r\n"
      "//   NUMBER\r\n"
      "//   LIST\r\n"
      "//\r\n"
      "// type info:\r\n"
      "// BOOL                 no type info\r\n"
      "// NUMBER       min max range, use -1 -1 for no limits\r\n"
      "// STRING       no type info\r\n"
      "// LIST          delimited list of options value pairs\r\n"
      "//\r\n"
      "//\r\n"
      "// default depends on type\r\n"
      "// BOOL is \"0\" or \"1\"\r\n"
      "// NUMBER is \"value\"\r\n"
      "// STRING is \"value\"\r\n"
      "// LIST is \"index\", where index \"0\" is the first element of the list\r\n"
      "\r\n"
      "\r\n");
    CDescription::setDescription(this: v13, pszDesc: "INFO_OPTIONS");
    v14 = (CInfoDescription *)v13;
  }
  else
  {
    v14 = nullptr;
  }
  this->m_pDescription = v14;
  CDescription::InitFromFile(this: v14, pszFileName: "cfg/user_default.scr");
  CDescription::InitFromFile(this: this->m_pDescription, pszFileName: "cfg/user.scr");
  CDescription::TransferCurrentValues(this: this->m_pDescription, pszConfigFile: nullptr);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\MultiplayerAdvancedDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  CMultiplayerAdvancedDialog::CreateControls(this);
  vgui::Frame::MoveToCenterOfScreen(this);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D7E20
// Name: public: virtual struct vgui::PanelMessageMap __near * CMultiplayerAdvancedDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMultiplayerAdvancedDialog::GetMessageMap(CMultiplayerAdvancedDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMultiplayerAdvancedDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMultiplayerAdvancedDialog::GetMessageMap'::`2'::s_pMap;
  `CMultiplayerAdvancedDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMultiplayerAdvancedDialog");
  `CMultiplayerAdvancedDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D7E50
// Name: public: virtual struct PanelAnimationMap __near * CMultiplayerAdvancedDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMultiplayerAdvancedDialog::GetAnimMap(CMultiplayerAdvancedDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CMultiplayerAdvancedDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101D7E60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMultiplayerAdvancedDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMultiplayerAdvancedDialog::GetKBMap(CMultiplayerAdvancedDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMultiplayerAdvancedDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMultiplayerAdvancedDialog::GetKBMap'::`2'::s_pMap;
  `CMultiplayerAdvancedDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMultiplayerAdvancedDialog");
  `CMultiplayerAdvancedDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}
