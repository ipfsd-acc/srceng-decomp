// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/createmultiplayergamegameplaypage.cpp
// Functions: 11
// ============================================================

#include "game\client\cstrike15\gameui\createmultiplayergamegameplaypage.h"

//------------------------------------------------------------------------------
// Address: 0x101D2850
// Name: private: char const __near * CCreateMultiplayerGameGameplayPage::GetValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CCreateMultiplayerGameGameplayPage::GetValue(
        CCreateMultiplayerGameGameplayPage *this,
        const char *cvarName,
        char *defaultValue)
{
  mpcontrol_t *m_pList; // esi
  vgui::Panel *pControl; // edi
  const char *v5; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // esi
  char *String; // [esp-8h] [ebp-14h]

  m_pList = this->m_pList;
  if ( m_pList == nullptr )
    return defaultValue;
  while ( 1 )
  {
    pControl = m_pList->pControl;
    if ( pControl != nullptr )
    {
      v5 = m_pList->GetName(this: m_pList);
      if ( _V_stricmp(s1: v5, s2: cvarName) == 0 )
        break;
    }
    m_pList = m_pList->next;
    if ( m_pList == nullptr )
      return defaultValue;
  }
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "GetText");
  else
    v8 = nullptr;
  if ( pControl->RequestInfo(this: pControl, a2: v8) )
  {
    String = KeyValues::GetString(this: v8, keyName: "text", defaultValue);
    V_strncpy(pDest: buf, pSrc: String, maxLen: 127);
  }
  else
  {
    V_strncpy(pDest: buf, pSrc: defaultValue, maxLen: 127);
  }
  buf[127] = 0;
  KeyValues::deleteThis(this: v8);
  return buf;
}

//------------------------------------------------------------------------------
// Address: 0x101D2910
// Name: private: void CCreateMultiplayerGameGameplayPage::LoadGameOptionsList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameGameplayPage::LoadGameOptionsList(CCreateMultiplayerGameGameplayPage *this)
{
  CCreateMultiplayerGameGameplayPage *v1; // ebx
  mpcontrol_t *m_pList; // esi
  vgui::Panel *pControl; // ecx
  mpcontrol_t *next; // edi
  vgui::Label *pPrompt; // ecx
  CDescription *m_pDescription; // eax
  CPanelListPanel *m_pOptionsList; // ecx
  CScriptObject *pObjList; // edi
  mpcontrol_t *v9; // eax
  mpcontrol_t *v10; // esi
  objtype_t type; // eax
  vgui::CheckButton *v12; // eax
  char v13; // fl
  vgui::ComboBox *v14; // ebx
  float fdefValue; // xmm0_4
  bool v16; // cf
  bool v17; // zf
  char v18; // sf
  char v19; // of
  char v20; // pf
  vgui::TextEntry *v21; // eax
  vgui::ComboBox *v22; // eax
  CScriptListItem *i; // edi
  vgui::Label *v24; // eax
  vgui::Label *v25; // eax
  mpcontrol_t *v26; // eax
  vgui::Panel *objParent; // [esp+Ch] [ebp-Ch]
  CScriptObject *pObj; // [esp+14h] [ebp-4h]

  v1 = this;
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
  }
  m_pDescription = v1->m_pDescription;
  m_pOptionsList = v1->m_pOptionsList;
  v1->m_pList = nullptr;
  pObjList = m_pDescription->pObjList;
  pObj = pObjList;
  objParent = m_pOptionsList;
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
        v9 = (mpcontrol_t *)MemAlloc_Alloc(nSize: 0x160u);
        v10 = v9 != nullptr
            ? mpcontrol_t::mpcontrol_t(this: v9, parent: objParent, panelName: pObjList->cvarname)
            : nullptr;
        type = pObjList->type;
        v10->type = type;
        switch ( type )
        {
          case O_BOOL:
            v12 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
            if ( v12 != nullptr )
            {
              v12 = vgui::CheckButton::CheckButton(
                      this: v12,
                      parent: v10,
                      panelName: "DescCheckButton",
                      text: pObjList->prompt);
              v14 = (vgui::ComboBox *)v12;
            }
            else
            {
              v14 = nullptr;
            }
            fdefValue = pObjList->fdefValue;
            v16 = fdefValue < 0.0;
            v20 = 0;
            v17 = fdefValue == 0.0;
            v18 = 0;
            v19 = 0;
            BYTE1(v12) = v13;
            LOBYTE(v12) = fdefValue != 0.0;
            ((void (__thiscall *)(vgui::ComboBox *, vgui::CheckButton *))v14->IsMultiline)(a1: v14, a2: v12);
            goto LABEL_30;
          case O_NUMBER:
          case O_STRING:
            v21 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
            if ( v21 != nullptr )
              v14 = (vgui::ComboBox *)vgui::TextEntry::TextEntry(this: v21, parent: v10, panelName: "DescEdit");
            else
              v14 = nullptr;
            v14->InsertString_2(this: v14, a2: pObjList->defValue);
            goto LABEL_30;
          case O_LIST:
            v22 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
            if ( v22 != nullptr )
              v14 = vgui::ComboBox::ComboBox(
                      this: v22,
                      parent: v10,
                      panelName: "DescEdit",
                      numLines: 5,
                      allowEdit: false);
            else
              v14 = nullptr;
            for ( i = pObjList->pListItems; i != nullptr; i = i->pNext )
              v14->AddItem_2(this: v14, a2: i->szItemText, a3: nullptr);
            vgui::ComboBox::ActivateItemByRow(this: v14, row: (int)pObj->fdefValue);
            pObjList = pObj;
LABEL_30:
            v10->pControl = v14;
            v1 = this;
            break;
          default:
            break;
        }
        if ( v10->type != O_BOOL )
        {
          v24 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
          if ( v24 != nullptr )
            v25 = vgui::Label::Label(this: v24, parent: v10, panelName: "DescLabel", text: prType);
          else
            v25 = nullptr;
          v10->pPrompt = v25;
          v25->SetContentAlignment(this: v25, a2: a_west);
          v10->pPrompt->SetTextInset(this: v10->pPrompt, a2: 5, a3: 0);
          v10->pPrompt->SetText(this: v10->pPrompt, a2: pObjList->prompt);
        }
        v10->pScrObj = pObjList;
        vgui::Panel::SetSize(this: v10, wide: 100, tall: 28);
        v1->m_pOptionsList->AddItem(this: v1->m_pOptionsList, a2: v10);
        v26 = v1->m_pList;
        if ( v26 != nullptr )
        {
          while ( v26->next != nullptr )
            v26 = v26->next;
          v26->next = v10;
        }
        else
        {
          v1->m_pList = v10;
        }
        v10->next = nullptr;
        pObj = pObjList->pNext;
      }
      if ( pObj == nullptr )
        break;
      pObjList = pObj;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D2C00
// Name: private: void CCreateMultiplayerGameGameplayPage::GatherCurrentValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameGameplayPage::GatherCurrentValues(CCreateMultiplayerGameGameplayPage *this)
{
  mpcontrol_t *i; // ebx
  vgui::Panel *pControl; // ecx
  CScriptObject *pScrObj; // edi
  bool v4; // zf
  char *defValue; // eax
  CScriptListItem *pListItems; // esi
  const wchar_t *v7; // eax
  wchar_t w_szStrValue[256]; // [esp+0h] [ebp-600h] BYREF
  wchar_t w_szStrTemp[256]; // [esp+200h] [ebp-400h] BYREF
  char strValue[256]; // [esp+400h] [ebp-200h] BYREF
  char szValue[256]; // [esp+500h] [ebp-100h] BYREF

  if ( this->m_pDescription != nullptr )
  {
    for ( i = this->m_pList; i != nullptr; i = i->next )
    {
      pControl = i->pControl;
      pScrObj = i->pScrObj;
      if ( pControl != nullptr )
      {
        switch ( pScrObj->type )
        {
          case O_BOOL:
            v4 = ((unsigned __int8 (__thiscall *)(vgui::Panel *))pControl->__vftable[1].SetAutoDelete)(a1: pControl) == 0;
            defValue = "1";
            if ( v4 )
              defValue = "0";
            goto LABEL_17;
          case O_NUMBER:
          case O_STRING:
            pControl->__vftable[1].PaintTraverse(this: pControl, a2: (bool)strValue, a3: 256);
            defValue = strValue;
            goto LABEL_17;
          case O_LIST:
            ((void (__thiscall *)(vgui::Panel *, wchar_t *, int))pControl->__vftable[1].PerformApplySchemeSettings)(
              a1: pControl,
              a2: w_szStrValue,
              a3: 256);
            pListItems = pScrObj->pListItems;
            if ( pListItems == nullptr )
              goto LABEL_16;
            break;
          default:
            goto LABEL_18;
        }
        do
        {
          if ( pListItems->szItemText[0] == 35
            && (v7 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: pListItems)) != nullptr )
          {
            wcsncpy(dest: w_szStrTemp, source: v7, count: 0x100u);
          }
          else
          {
            g_pVGuiLocalize->ConvertANSIToUnicode(
              this: g_pVGuiLocalize,
              a2: (const char *)pListItems,
              a3: w_szStrTemp,
              a4: 512);
          }
          if ( _wcsicmp(dst: w_szStrTemp, src: w_szStrValue) == 0 )
          {
            V_snprintf(pDest: szValue, maxLen: 0x100u, pFormat: "%s", pListItems->szValue);
            goto LABEL_18;
          }
          pListItems = pListItems->pNext;
        }
        while ( pListItems != nullptr );
LABEL_16:
        defValue = pScrObj->defValue;
LABEL_17:
        V_snprintf(pDest: szValue, maxLen: 0x100u, pFormat: "%s", defValue);
LABEL_18:
        UTIL_StripInvalidCharacters(pszInput: szValue, maxlen: 256);
        V_strncpy(pDest: strValue, pSrc: szValue, maxLen: 256);
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
// Address: 0x101D2DD0
// Name: public: virtual void CServerDescription::WriteScriptHeader(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerDescription::WriteScriptHeader(CServerDescription *this, void *fp)
{
  int tm_hour; // eax
  char timeString[64]; // [esp+Ch] [ebp-68h] BYREF
  tm newtime; // [esp+4Ch] [ebp-28h] BYREF
  char am_pm[4]; // [esp+70h] [ebp-4h] BYREF

  strcpy(am_pm, "AM");
  _Plat_GetLocalTime(a1: &newtime);
  tm_hour = newtime.tm_hour;
  if ( newtime.tm_hour > 12 )
  {
    V_strncpy(pDest: am_pm, pSrc: "PM", maxLen: 3);
    tm_hour = newtime.tm_hour;
    if ( newtime.tm_hour > 12 )
    {
      tm_hour = newtime.tm_hour - 12;
      newtime.tm_hour -= 12;
    }
  }
  if ( tm_hour == 0 )
    newtime.tm_hour = 12;
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: this->m_pszHintText);
  _Plat_GetTimeString(a1: &newtime, a2: timeString, a3: 64);
  g_pFullFileSystem->FPrintf(
    this: g_pFullFileSystem,
    a2: fp,
    a3: "// Half-Life Server Configuration Layout Script (stores last settings chosen, too)\r\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "// File generated:  %.19s %s\r\n", timeString, am_pm);
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "//\r\n//\r\n// Cvar\t-\tSetting\r\n\r\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "VERSION %.1f\r\n\r\n", 0, 1072693248);
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "DESCRIPTION SERVER_OPTIONS\r\n{\r\n");
}

//------------------------------------------------------------------------------
// Address: 0x101D2EE0
// Name: public: virtual void CServerDescription::WriteFileHeader(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerDescription::WriteFileHeader(CServerDescription *this, void *fp)
{
  int tm_hour; // eax
  char timeString[64]; // [esp+0h] [ebp-68h] BYREF
  tm newtime; // [esp+40h] [ebp-28h] BYREF
  char am_pm[4]; // [esp+64h] [ebp-4h] BYREF

  strcpy(am_pm, "AM");
  _Plat_GetLocalTime(a1: &newtime);
  tm_hour = newtime.tm_hour;
  if ( newtime.tm_hour > 12 )
  {
    V_strncpy(pDest: am_pm, pSrc: "PM", maxLen: 3);
    tm_hour = newtime.tm_hour;
    if ( newtime.tm_hour > 12 )
    {
      tm_hour = newtime.tm_hour - 12;
      newtime.tm_hour -= 12;
    }
  }
  if ( tm_hour == 0 )
    newtime.tm_hour = 12;
  _Plat_GetTimeString(a1: &newtime, a2: timeString, a3: 64);
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "// Half-Life Server Configuration Settings\r\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "// DO NOT EDIT, GENERATED BY HALF-LIFE\r\n");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "// File generated:  %.19s %s\r\n", timeString, am_pm);
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: fp, a3: "//\r\n//\r\n// Cvar\t-\tSetting\r\n\r\n");
}

//------------------------------------------------------------------------------
// Address: 0x101D2FB0
// Name: public: CCreateMultiplayerGameGameplayPage::CCreateMultiplayerGameGameplayPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CCreateMultiplayerGameGameplayPage *__thiscall CCreateMultiplayerGameGameplayPage::CCreateMultiplayerGameGameplayPage(
        CCreateMultiplayerGameGameplayPage *this,
        vgui::Panel *parent,
        const char *name)
{
  CPanelListPanel *v4; // eax
  CPanelListPanel *v5; // eax
  CDescription *v6; // eax
  CDescription *v7; // edi
  CDescription *v8; // ecx

  vgui::PropertyPage::PropertyPage(this, parent, panelName: name);
  this->__vftable = (CCreateMultiplayerGameGameplayPage_vtbl *)&CCreateMultiplayerGameGameplayPage::`vftable';
  v4 = (CPanelListPanel *)MemAlloc_Alloc(nSize: 0x178u);
  if ( v4 != nullptr )
    v5 = CPanelListPanel::CPanelListPanel(this: v4, parent: this, panelName: "GameOptions", inverseButtons: false);
  else
    v5 = nullptr;
  this->m_pOptionsList = v5;
  v6 = (CDescription *)MemAlloc_Alloc(nSize: 0x14u);
  v7 = v6;
  if ( v6 != nullptr )
  {
    CDescription::CDescription(this: v6, panel: this->m_pOptionsList);
    v7->__vftable = (CDescription_vtbl *)&CServerDescription::`vftable';
    CDescription::setHint(
      this: v7,
      pszHint: "// NOTE:  THIS FILE IS AUTOMATICALLY REGENERATED, \r\n"
      "//DO NOT EDIT THIS HEADER, YOUR COMMENTS WILL BE LOST IF YOU DO\r\n"
      "// Multiplayer options script\r\n"
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
    CDescription::setDescription(this: v7, pszDesc: "SERVER_OPTIONS");
    v8 = v7;
  }
  else
  {
    v8 = nullptr;
  }
  this->m_pDescription = v8;
  CDescription::InitFromFile(this: v8, pszFileName: "cfg/settings_default.scr");
  CDescription::InitFromFile(this: this->m_pDescription, pszFileName: "cfg/settings.scr");
  this->m_pList = nullptr;
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource/CreateMultiplayerGameGameplayPage.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  CCreateMultiplayerGameGameplayPage::LoadGameOptionsList(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D3090
// Name: public: static char const __near * vgui::PropertyPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::PropertyPage::GetPanelClassName()
{
  return "PropertyPage";
}

//------------------------------------------------------------------------------
// Address: 0x101D3110
// Name: public: int CCreateMultiplayerGameGameplayPage::GetMaxPlayers(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCreateMultiplayerGameGameplayPage::GetMaxPlayers(CCreateMultiplayerGameGameplayPage *this)
{
  char *Value; // eax

  Value = CCreateMultiplayerGameGameplayPage::GetValue(this, cvarName: "maxplayers", defaultValue: "32");
  return atoi(nptr: Value);
}

//------------------------------------------------------------------------------
// Address: 0x101D3130
// Name: public: char const __near * CCreateMultiplayerGameGameplayPage::GetPassword(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CCreateMultiplayerGameGameplayPage::GetPassword(CCreateMultiplayerGameGameplayPage *this)
{
  return CCreateMultiplayerGameGameplayPage::GetValue(this, cvarName: "sv_password", defaultValue: (char *)prType);
}

//------------------------------------------------------------------------------
// Address: 0x101D3140
// Name: public: char const __near * CCreateMultiplayerGameGameplayPage::GetHostName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CCreateMultiplayerGameGameplayPage::GetHostName(CCreateMultiplayerGameGameplayPage *this)
{
  return CCreateMultiplayerGameGameplayPage::GetValue(this, cvarName: "hostname", defaultValue: "Half-Life");
}

//------------------------------------------------------------------------------
// Address: 0x101D3150
// Name: protected: virtual void CCreateMultiplayerGameGameplayPage::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameGameplayPage::OnApplyChanges(CCreateMultiplayerGameGameplayPage *this)
{
  CDescription *m_pDescription; // ecx
  void *v3; // eax
  void *v4; // esi

  CCreateMultiplayerGameGameplayPage::GatherCurrentValues(this);
  m_pDescription = this->m_pDescription;
  if ( m_pDescription != nullptr )
  {
    CDescription::WriteToConfig(this: m_pDescription);
    g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: "cfg", a3: "GAME");
    v3 = g_pFullFileSystem->Open(
           this: &g_pFullFileSystem->IBaseFileSystem,
           a2: "cfg/settings.scr",
           a3: "wb",
           a4: "GAME");
    v4 = v3;
    if ( v3 != nullptr )
    {
      CDescription::WriteToScriptFile(this: this->m_pDescription, fp: v3);
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v4);
    }
  }
}
