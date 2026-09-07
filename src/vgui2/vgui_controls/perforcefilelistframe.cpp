// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/perforcefilelistframe.cpp
// Functions: 28
// ============================================================

#include "vgui2\vgui_controls\perforcefilelistframe.h"

//------------------------------------------------------------------------------
// Address: 0x102DE0F0
// Name: public: static char const __near * COperationFileListFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COperationFileListFrame::GetPanelClassName()
{
  return "COperationFileListFrame";
}

//------------------------------------------------------------------------------
// Address: 0x102DE100
// Name: public: static char const __near * CPerforceFileListFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPerforceFileListFrame::GetPanelClassName()
{
  return "CPerforceFileListFrame";
}

//------------------------------------------------------------------------------
// Address: 0x102DE110
// Name: OperationSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl OperationSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  char *String; // esi
  char *v4; // eax
  int result; // eax
  char *v6; // esi
  char *v7; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "operation", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "operation", defaultValue: defaultValue);
  result = _V_stricmp(s1: String, s2: v4);
  if ( result == 0 )
  {
    v6 = KeyValues::GetString(this: item1->kv, keyName: "filename", defaultValue: defaultValue);
    v7 = KeyValues::GetString(this: item2->kv, keyName: "filename", defaultValue: defaultValue);
    return _V_stricmp(s1: v6, s2: v7);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DE190
// Name: FileBrowserSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl FileBrowserSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  char *String; // esi
  char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "filename", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "filename", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x102DE1D0
// Name: public: virtual void COperationFileListFrame::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::PerformLayout(COperationFileListFrame *this)
{
  int x; // [esp+4h] [ebp-10h] BYREF
  int w; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  if ( this->m_pSplitter != nullptr )
  {
    this->GetClientArea(this, a2: &x, a3: &y, a4: &w, a5: &h);
    vgui::Panel::SetBounds(this: this->m_pSplitter, x, y: y + 6, wide: w, tall: h - 36);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DE230
// Name: public: void COperationFileListFrame::AddOperation(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::AddOperation(
        COperationFileListFrame *this,
        const char *pOperation,
        const char *pFileName)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "node", firstKey: "filename", firstValue: pFileName);
  else
    v5 = nullptr;
  KeyValues::SetString(this: v5, keyName: "operation", value: pOperation);
  this->m_pFileBrowser->AddItem(this: this->m_pFileBrowser, a2: v5, a3: 0, a4: false, a5: false);
}

//------------------------------------------------------------------------------
// Address: 0x102DE290
// Name: public: void COperationFileListFrame::DoModal(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::DoModal(
        COperationFileListFrame *this,
        KeyValues *pContextKeyValues,
        const char *pMessage)
{
  const char *v3; // eax
  KeyValues *m_pContextKeyValues; // ecx
  vgui::ListPanel *m_pFileBrowser; // ecx
  vgui::Button_vtbl *v7; // edi
  int v8; // eax

  v3 = pMessage;
  if ( pMessage == nullptr )
    v3 = "OperationConfirmed";
  CUtlString::operator=(this: &this->m_MessageName, src: v3);
  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  m_pFileBrowser = this->m_pFileBrowser;
  this->m_pContextKeyValues = pContextKeyValues;
  m_pFileBrowser->SortList(this: m_pFileBrowser);
  if ( this->m_pNoButton->IsVisible(this: this->m_pNoButton) )
  {
    v7 = this->m_pYesButton->__vftable;
    v8 = this->m_pFileBrowser->GetItemCount(this: this->m_pFileBrowser);
    v7->SetEnabled(this: this->m_pYesButton, a2: v8 != 0);
  }
  vgui::Frame::DoModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x102DE340
// Name: public: virtual char const __near * COperationFileListFrame::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall COperationFileListFrame::GetDescription(COperationFileListFrame *this)
{
  return this->m_pText;
}

//------------------------------------------------------------------------------
// Address: 0x102DE350
// Name: public: virtual void COperationFileListFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::OnCommand(COperationFileListFrame *this, const char *pCommand)
{
  vgui::TextEntry *m_pDescription; // ecx
  unsigned int v4; // edi
  char *v5; // eax
  vgui::TextEntry *v6; // ecx
  KeyValues *v7; // edi
  const char *v8; // eax
  KeyValues *v9; // edi
  KeyValues *v10; // edi
  const char *v11; // eax
  KeyValues *v12; // edi
  const char *v13; // eax

  if ( _V_stricmp(s1: pCommand, s2: "Yes") == 0 )
  {
    m_pDescription = this->m_pDescription;
    if ( m_pDescription != nullptr )
    {
      v4 = m_pDescription->GetTextLength(this: m_pDescription) + 1;
      v5 = (char *)MemAlloc_Alloc(nSize: v4);
      v6 = this->m_pDescription;
      this->m_pText = v5;
      v6->GetText_2(this: v6, a2: v5, a3: v4);
    }
    if ( this->PerformOperation(this) )
    {
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
      {
        v8 = CUtlString::operator char const *(this: &this->m_MessageName);
        v9 = KeyValues::KeyValues(this: v7, setName: v8, firstKey: "operationPerformed", firstValue: 1);
        goto LABEL_10;
      }
    }
    else
    {
      v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v10 != nullptr )
      {
        v11 = CUtlString::operator char const *(this: &this->m_MessageName);
        v9 = KeyValues::KeyValues(this: v10, setName: v11, firstKey: "operationPerformed", firstValue: 0);
        goto LABEL_10;
      }
    }
    v9 = nullptr;
LABEL_10:
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v9, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
LABEL_12:
    this->CloseModal(this);
    this->PostActionSignal(this, a2: v9);
    return;
  }
  if ( _V_stricmp(s1: pCommand, s2: "No") == 0 )
  {
    v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v12 != nullptr )
    {
      v13 = CUtlString::operator char const *(this: &this->m_MessageName);
      v9 = KeyValues::KeyValues(this: v12, setName: v13, firstKey: "operationPerformed", firstValue: 0);
    }
    else
    {
      v9 = nullptr;
    }
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v9, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    goto LABEL_12;
  }
  vgui::Frame::OnCommand(this, command: pCommand);
}

//------------------------------------------------------------------------------
// Address: 0x102DE4E0
// Name: private: void CPerforceFileListFrame::AddFileForOpen(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::AddFileForOpen(CPerforceFileListFrame *this, const char *pFullPath)
{
  bool v3; // bl
  bool v4; // zf
  PerforceAction_t m_Action; // eax
  __int32 v6; // eax

  v3 = p4->IsFileInPerforce(this: p4, a2: pFullPath);
  v4 = p4->GetFileState(this: p4, a2: pFullPath) == P4FILE_UNOPENED;
  m_Action = this->m_Action;
  if ( m_Action != PERFORCE_ACTION_FILE_ADD )
  {
    v6 = m_Action - 1;
    if ( v6 != 0 )
    {
      if ( v6 == 1 && v3 && v4 )
        COperationFileListFrame::AddOperation(this, pOperation: "Delete", pFileName: pFullPath);
    }
    else if ( v3 && v4 )
    {
      COperationFileListFrame::AddOperation(this, pOperation: "Edit", pFileName: pFullPath);
    }
  }
  else if ( !v3 && v4 )
  {
    COperationFileListFrame::AddOperation(this, pOperation: "Add", pFileName: pFullPath);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DE580
// Name: private: void CPerforceFileListFrame::AddFileForSubmit(char const __near *,enum P4FileState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::AddFileForSubmit(
        CPerforceFileListFrame *this,
        const char *pFullPath,
        P4FileState_t state)
{
  const char *v4; // eax
  char pBuf[128]; // [esp+4h] [ebp-80h] BYREF

  if ( state != P4FILE_UNOPENED )
  {
    v4 = "Revert";
    if ( this->m_Action != PERFORCE_ACTION_FILE_REVERT )
      v4 = "Submit";
    switch ( state )
    {
      case P4FILE_OPENED_FOR_ADD:
        V_snprintf(pDest: pBuf, maxLen: 128, pFormat: "%s Add", v4);
        goto LABEL_9;
      case P4FILE_OPENED_FOR_EDIT:
        V_snprintf(pDest: pBuf, maxLen: 128, pFormat: "%s Edit", v4);
        goto LABEL_9;
      case P4FILE_OPENED_FOR_DELETE:
        V_snprintf(pDest: pBuf, maxLen: 128, pFormat: "%s Delete", v4);
        goto LABEL_9;
      case P4FILE_OPENED_FOR_INTEGRATE:
        V_snprintf(pDest: pBuf, maxLen: 128, pFormat: "%s Integrate", v4);
LABEL_9:
        COperationFileListFrame::AddOperation(this, pOperation: pBuf, pFileName: pFullPath);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DE610
// Name: public: void CPerforceFileListFrame::AddFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::AddFile(CPerforceFileListFrame *this, const char *pFullPath)
{
  bool (__thiscall *FileExists)(IBaseFileSystem *, const char *, const char *); // edx
  IBaseFileSystem *v4; // ecx
  bool v5; // bl
  P4FileState_t v6; // eax

  FileExists = g_pFullFileSystem->FileExists;
  v4 = &g_pFullFileSystem->IBaseFileSystem;
  if ( this->m_Action >= PERFORCE_ACTION_FILE_REVERT )
  {
    v5 = FileExists(this: v4, a2: pFullPath, a3: nullptr);
    v6 = p4->GetFileState(this: p4, a2: pFullPath);
    if ( v5 || v6 == P4FILE_OPENED_FOR_DELETE )
      CPerforceFileListFrame::AddFileForSubmit(this, pFullPath, state: v6);
  }
  else if ( FileExists(this: v4, a2: pFullPath, a3: nullptr) )
  {
    CPerforceFileListFrame::AddFileForOpen(this, pFullPath);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DE680
// Name: private: virtual bool CPerforceFileListFrame::PerformOperation(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPerforceFileListFrame::PerformOperation(CPerforceFileListFrame *this)
{
  int v2; // ebx
  void *v3; // esp
  const char **v4; // eax
  int v5; // esi
  int v6; // eax
  KeyValues *v7; // eax
  const char *String; // eax
  const char **v9; // ecx
  PerforceAction_t m_Action; // ecx
  char v11; // al
  const char *v12; // ebx
  vgui::MessageBox *v13; // esi
  vgui::Panel *v14; // eax
  vgui::MessageBox *v15; // esi
  const char *v16; // eax
  const char *v17; // esi
  vgui::MessageBox *v18; // esi
  vgui::Panel *v19; // eax
  vgui::MessageBox *v20; // esi
  _BYTE v22[12]; // [esp+0h] [ebp-14h] BYREF
  const char **ppFileNames; // [esp+Ch] [ebp-8h]
  bool bSuccess; // [esp+13h] [ebp-1h]

  v2 = this->m_pFileBrowser->GetItemCount(this: this->m_pFileBrowser);
  v3 = alloca(4 * v2);
  v4 = (const char **)v22;
  v5 = 0;
  ppFileNames = (const char **)v22;
  if ( v2 > 0 )
  {
    do
    {
      v6 = this->m_pFileBrowser->GetItemIDFromRow(this: this->m_pFileBrowser, a2: v5);
      v7 = this->m_pFileBrowser->GetItem(this: this->m_pFileBrowser, a2: v6);
      String = KeyValues::GetString(this: v7, keyName: "filename", defaultValue: defaultValue);
      v9 = ppFileNames;
      ppFileNames[v5++] = String;
    }
    while ( v5 < v2 );
    v4 = v9;
  }
  m_Action = this->m_Action;
  bSuccess = false;
  switch ( m_Action )
  {
    case PERFORCE_ACTION_FILE_ADD:
      v11 = ((int (__stdcall *)(int, const char **))p4->OpenFilesForAdd)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_EDIT:
      v11 = ((int (__stdcall *)(int, const char **))p4->OpenFilesForEdit)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_DELETE:
      v11 = ((int (__stdcall *)(int, const char **))p4->OpenFilesForDelete)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_REVERT:
      v11 = ((int (__stdcall *)(int, const char **))p4->RevertFiles)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_SUBMIT:
      v16 = this->GetDescription(this);
      v17 = v16;
      if ( *v16 != 0 && _V_stricmp(s1: v16, s2: "<enter description here>") != 0 )
      {
        v11 = p4->SubmitFiles(this: p4, a2: v2, a3: ppFileNames, a4: v17);
LABEL_6:
        bSuccess = v11;
LABEL_7:
        v12 = p4->GetLastError(this: p4);
        if ( !bSuccess )
        {
          v13 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
          if ( v13 != nullptr )
          {
            v14 = this->GetParent(this);
            v15 = vgui::MessageBox::MessageBox(this: v13, title: "Perforce Error!", text: v12, parent: v14);
          }
          else
          {
            v15 = nullptr;
          }
          v15->SetSmallCaption(this: v15, a2: true);
          v15->DoModal_2(this: v15, a2: nullptr);
        }
        return bSuccess;
      }
      else
      {
        v18 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
        if ( v18 != nullptr )
        {
          v19 = this->GetParent(this);
          v20 = vgui::MessageBox::MessageBox(
                  this: v18,
                  title: "Submission Error!",
                  text: "Description required for submission.",
                  parent: v19);
        }
        else
        {
          v20 = nullptr;
        }
        v20->SetSmallCaption(this: v20, a2: true);
        v20->DoModal_2(this: v20, a2: nullptr);
        return false;
      }
    default:
      goto LABEL_7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DE890
// Name: public: COperationFileListFrame::COperationFileListFrame(class vgui::Panel __near *,char const __near *,char const __near *,bool,bool,int)
// Source: json
//------------------------------------------------------------------------------
COperationFileListFrame *__thiscall COperationFileListFrame::COperationFileListFrame(
        COperationFileListFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        const char *pColumnHeader,
        bool bShowDescription,
        bool bShowOkOnly,
        int nDialogID)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  COperationFileListFrame *Child; // ebx
  vgui::Splitter *v12; // eax
  vgui::Splitter *v13; // eax
  vgui::Panel *v14; // edi
  vgui::TextEntry *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::ListPanel *v17; // eax
  vgui::ListPanel *v18; // eax
  vgui::Button *v19; // eax
  vgui::Button *v20; // eax
  vgui::Button *v21; // eax
  vgui::Button *v22; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "PerforceFileList", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (COperationFileListFrame_vtbl *)&COperationFileListFrame::`vftable';
  if ( `COperationFileListFrame::ChainToMap'::`2'::chained == 0 )
  {
    `COperationFileListFrame::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "COperationFileListFrame");
    v8->pfnClassName = COperationFileListFrame::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `COperationFileListFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COperationFileListFrame::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "COperationFileListFrame");
    v9->pfnClassName = COperationFileListFrame::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `COperationFileListFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COperationFileListFrame::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "COperationFileListFrame");
    v10->pfnClassName = COperationFileListFrame::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CUtlString::CUtlString(this: &this->m_MessageName);
  this->m_pText = nullptr;
  Child = this;
  this->m_pDescription = nullptr;
  this->m_pSplitter = nullptr;
  if ( bShowDescription )
  {
    v12 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
    if ( v12 != nullptr )
      v13 = vgui::Splitter::Splitter(
              this: v12,
              parent: this,
              name: "Splitter",
              mode: SPLITTER_MODE_HORIZONTAL,
              nCount: 1);
    else
      v13 = nullptr;
    this->m_pSplitter = v13;
    Child = (COperationFileListFrame *)vgui::Panel::GetChild(this: v13, index: 0);
    v14 = vgui::Panel::GetChild(this: this->m_pSplitter, index: 1);
    v15 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
    if ( v15 != nullptr )
      v16 = vgui::TextEntry::TextEntry(this: v15, parent: v14, panelName: "Description");
    else
      v16 = nullptr;
    this->m_pDescription = v16;
    v16->SetMultiline(this: v16, a2: true);
    this->m_pDescription->SetCatchEnterKey(this: this->m_pDescription, a2: true);
    this->m_pDescription->SetText(this: this->m_pDescription, a2: "<enter description here>");
  }
  v17 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v17 != nullptr )
    v18 = vgui::ListPanel::ListPanel(this: v17, parent: Child, panelName: "Browser");
  else
    v18 = nullptr;
  this->m_pFileBrowser = v18;
  v18->AddColumnHeader(this: v18, a2: 0, a3: "operation", a4: "Operation", a5: 52, a6: 0);
  this->m_pFileBrowser->AddColumnHeader(
    this: this->m_pFileBrowser,
    a2: 1,
    a3: "filename",
    a4: pColumnHeader,
    a5: 128,
    a6: 2);
  this->m_pFileBrowser->SetSelectIndividualCells(this: this->m_pFileBrowser, a2: false);
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pFileBrowser, bState: false);
  this->m_pFileBrowser->SetEmptyListText_2(this: this->m_pFileBrowser, a2: "No Perforce Operations");
  this->m_pFileBrowser->SetDragEnabled(this: this->m_pFileBrowser, a2: true);
  this->m_pFileBrowser->AddActionSignalTarget_2(this: this->m_pFileBrowser, a2: this);
  this->m_pFileBrowser->SetSortFunc(this: this->m_pFileBrowser, a2: 0, a3: OperationSortFunc);
  this->m_pFileBrowser->SetSortFunc(this: this->m_pFileBrowser, a2: 1, a3: FileBrowserSortFunc);
  this->m_pFileBrowser->SetSortColumn(this: this->m_pFileBrowser, a2: 0);
  v19 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v19 != nullptr )
    v20 = vgui::Button::Button(
            this: v19,
            parent: this,
            panelName: "YesButton",
            text: "Yes",
            pActionSignalTarget: this,
            pCmd: "Yes");
  else
    v20 = nullptr;
  this->m_pYesButton = v20;
  v21 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v21 != nullptr )
    v22 = vgui::Button::Button(
            this: v21,
            parent: this,
            panelName: "NoButton",
            text: "No",
            pActionSignalTarget: this,
            pCmd: "No");
  else
    v22 = nullptr;
  this->m_pNoButton = v22;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  if ( bShowDescription )
    vgui::EditablePanel::LoadControlSettingsAndUserConfig(
      this,
      dialogResourceName: "resource/perforcefilelistdescription.res",
      dialogID: nDialogID);
  else
    vgui::EditablePanel::LoadControlSettingsAndUserConfig(
      this,
      dialogResourceName: "resource/perforcefilelist.res",
      dialogID: nDialogID);
  if ( bShowOkOnly )
  {
    this->m_pYesButton->SetText(this: this->m_pYesButton, a2: "#MessageBox_OK");
    this->m_pNoButton->SetVisible(this: this->m_pNoButton, a2: false);
  }
  this->m_pContextKeyValues = nullptr;
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102DEBF0
// Name: public: virtual struct vgui::PanelMessageMap __near * COperationFileListFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COperationFileListFrame::GetMessageMap(COperationFileListFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COperationFileListFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COperationFileListFrame::GetMessageMap'::`2'::s_pMap;
  `COperationFileListFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COperationFileListFrame");
  `COperationFileListFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DEC20
// Name: public: virtual struct PanelAnimationMap __near * COperationFileListFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COperationFileListFrame::GetAnimMap(COperationFileListFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "COperationFileListFrame");
}

//------------------------------------------------------------------------------
// Address: 0x102DEC30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COperationFileListFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COperationFileListFrame::GetKBMap(COperationFileListFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COperationFileListFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COperationFileListFrame::GetKBMap'::`2'::s_pMap;
  `COperationFileListFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COperationFileListFrame");
  `COperationFileListFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DEC60
// Name: public: virtual COperationFileListFrame::~COperationFileListFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::~COperationFileListFrame(COperationFileListFrame *this)
{
  KeyValues *m_pContextKeyValues; // ecx

  this->__vftable = (COperationFileListFrame_vtbl *)&COperationFileListFrame::`vftable';
  vgui::EditablePanel::SaveUserConfig(this);
  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  if ( this->m_pText != nullptr )
    free(pMem: this->m_pText);
  this->m_MessageName.m_Storage.m_nActualLength = 0;
  if ( this->m_MessageName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_MessageName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_MessageName.m_Storage.m_Memory.m_pMemory);
      this->m_MessageName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_MessageName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x102DED10
// Name: public: CPerforceFileListFrame::CPerforceFileListFrame(class vgui::Panel __near *,char const __near *,char const __near *,enum PerforceAction_t)
// Source: json
//------------------------------------------------------------------------------
CPerforceFileListFrame *__thiscall CPerforceFileListFrame::CPerforceFileListFrame(
        CPerforceFileListFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        const char *pColumnHeader,
        PerforceAction_t action)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  COperationFileListFrame::COperationFileListFrame(
    this,
    pParent,
    pTitle,
    pColumnHeader,
    bShowDescription: action == PERFORCE_ACTION_FILE_SUBMIT,
    bShowOkOnly: false,
    nDialogID: 0);
  this->__vftable = (CPerforceFileListFrame_vtbl *)&CPerforceFileListFrame::`vftable';
  if ( `CPerforceFileListFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CPerforceFileListFrame::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CPerforceFileListFrame");
    v6->pfnClassName = CPerforceFileListFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "COperationFileListFrame");
  }
  if ( `CPerforceFileListFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPerforceFileListFrame::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CPerforceFileListFrame");
    v7->pfnClassName = CPerforceFileListFrame::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "COperationFileListFrame");
  }
  if ( `CPerforceFileListFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPerforceFileListFrame::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CPerforceFileListFrame");
    v8->pfnClassName = CPerforceFileListFrame::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "COperationFileListFrame");
  }
  this->m_OpenedFiles.m_Memory.m_pMemory = nullptr;
  this->m_OpenedFiles.m_Memory.m_nAllocationCount = 0;
  this->m_OpenedFiles.m_Memory.m_nGrowSize = 0;
  this->m_OpenedFiles.m_Size = 0;
  this->m_OpenedFiles.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_LastOpenedFilePathId);
  this->m_Action = action;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102DEE20
// Name: public: virtual struct vgui::PanelMessageMap __near * CPerforceFileListFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPerforceFileListFrame::GetMessageMap(CPerforceFileListFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPerforceFileListFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPerforceFileListFrame::GetMessageMap'::`2'::s_pMap;
  `CPerforceFileListFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPerforceFileListFrame");
  `CPerforceFileListFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DEE50
// Name: public: virtual struct PanelAnimationMap __near * CPerforceFileListFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPerforceFileListFrame::GetAnimMap(CPerforceFileListFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CPerforceFileListFrame");
}

//------------------------------------------------------------------------------
// Address: 0x102DEE60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPerforceFileListFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPerforceFileListFrame::GetKBMap(CPerforceFileListFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPerforceFileListFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPerforceFileListFrame::GetKBMap'::`2'::s_pMap;
  `CPerforceFileListFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPerforceFileListFrame");
  `CPerforceFileListFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DEE90
// Name: public: virtual CPerforceFileListFrame::~CPerforceFileListFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::~CPerforceFileListFrame(CPerforceFileListFrame *this)
{
  bool v2; // sf

  this->__vftable = (CPerforceFileListFrame_vtbl *)&CPerforceFileListFrame::`vftable';
  v2 = this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_LastOpenedFilePathId.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_pMemory);
      this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_OpenedFiles);
  COperationFileListFrame::~COperationFileListFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x102DEEF0
// Name: void ShowPerforceQuery(class vgui::Panel __near *,char const __near *,class vgui::Panel __near *,class KeyValues __near *,enum PerforceAction_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowPerforceQuery(
        vgui::Panel *pParent,
        const char *pFileName,
        vgui::Panel *pActionSignalTarget,
        KeyValues *pKeyValues,
        const char *actionFilter)
{
  PerforceAction_t v5; // esi
  const char *v6; // edi
  CPerforceFileListFrame *v7; // eax
  CPerforceFileListFrame *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // edi
  vgui::IVGui *v11; // esi
  vgui::IVGui_vtbl *v12; // ebx
  int v13; // eax

  p4->RefreshActiveClient(this: p4);
  if ( p4->IsFileInPerforce(this: p4, a2: pFileName) )
  {
    if ( p4->GetFileState(this: p4, a2: pFileName) != P4FILE_UNOPENED )
      goto LABEL_13;
    v5 = PERFORCE_ACTION_FILE_EDIT;
    v6 = "Check Out File from Perforce?";
  }
  else
  {
    v5 = PERFORCE_ACTION_FILE_ADD;
    v6 = "Add File to Perforce?";
  }
  if ( actionFilter == (const char *)-1 || actionFilter == (const char *)v5 )
  {
    v7 = (CPerforceFileListFrame *)MemAlloc_Alloc(nSize: 0x26Cu);
    if ( v7 != nullptr )
      v8 = CPerforceFileListFrame::CPerforceFileListFrame(
             this: v7,
             pParent,
             pTitle: v6,
             pColumnHeader: "File",
             action: v5);
    else
      v8 = nullptr;
    CPerforceFileListFrame::AddFile(this: v8, pFullPath: pFileName);
    if ( pActionSignalTarget != nullptr )
      v8->AddActionSignalTarget_2(this: v8, a2: pActionSignalTarget);
    COperationFileListFrame::DoModal(this: v8, pContextKeyValues: pKeyValues, pMessage: "PerforceQueryCompleted");
    return;
  }
LABEL_13:
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(
            this: v9,
            setName: "PerforceQueryCompleted",
            firstKey: "operationPerformed",
            firstValue: 1);
  else
    v10 = nullptr;
  if ( pKeyValues != nullptr )
    KeyValues::AddSubKey(this: v10, pSubkey: pKeyValues);
  v11 = g_pVGui;
  v12 = g_pVGui->__vftable;
  v13 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))pActionSignalTarget->GetVPanel)(
          a1: pActionSignalTarget,
          a2: v10,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v12->PostMessage)(a1: v11, a2: v13);
}

//------------------------------------------------------------------------------
// Address: 0x103119D0
// Name: _dynamic_initializer_for__force_audio_english__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__force_audio_english__()
{
  ConVar::ConVar(
    this: &force_audio_english,
    pName: "force_audio_english",
    pDefaultValue: "0",
    flags: 16777344,
    pHelpString: "Keeps track of whether we're forcing english in a localized language.");
  return atexit(func: dynamic_atexit_destructor_for__force_audio_english__);
}

//------------------------------------------------------------------------------
// Address: 0x10321570
// Name: _dynamic_atexit_destructor_for__force_audio_english__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__force_audio_english__()
{
  ConVar::~ConVar(this: &force_audio_english);
}

//------------------------------------------------------------------------------
// Address: 0x10311A00
// Name: _dynamic_initializer_for__g_ASCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ASCache__()
{
  CUtlString::CUtlString(this: &g_ASCache.m_szMODPath);
  CUtlString::CUtlString(this: &g_ASCache.m_szMapCacheBase);
  CUtlString::CUtlString(this: &g_ASCache.m_szMasterCache);
  CUtlString::CUtlString(this: &g_ASCache.m_szCurrentLanguage);
  g_ASCache.m_pMasterSoundCache = nullptr;
  g_ASCache.m_pBuildingCache = nullptr;
  g_ASCache.m_nServerCount = -1;
  return atexit(func: dynamic_atexit_destructor_for__g_ASCache__);
}

//------------------------------------------------------------------------------
// Address: 0x10321580
// Name: _MaybeReportMissingWav_::_2_::_dynamic_atexit_destructor_for__wavErrors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl MaybeReportMissingWav_::_2_::_dynamic_atexit_destructor_for__wavErrors__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &wavErrors);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00402380
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Panel::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Panel::GetUnpackStructure(vgui::Panel *this)
{
  return vgui::Panel::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x005DE390
// Name: public: virtual class Color vgui::Panel::GetFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Panel::GetFgColor(vgui::Panel *this, Color *result)
{
  *result = this->_fgColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006416A0
// Name: public: static char const __near * COperationFileListFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COperationFileListFrame::GetPanelClassName()
{
  return "COperationFileListFrame";
}

//------------------------------------------------------------------------------
// Address: 0x006416B0
// Name: public: static char const __near * CPerforceFileListFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPerforceFileListFrame::GetPanelClassName()
{
  return "CPerforceFileListFrame";
}

//------------------------------------------------------------------------------
// Address: 0x006416C0
// Name: OperationSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl OperationSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *String; // esi
  const char *v4; // eax
  int result; // eax
  const char *v6; // esi
  const char *v7; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "operation", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "operation", defaultValue: defaultValue);
  result = _V_stricmp(s1: String, s2: v4);
  if ( result == 0 )
  {
    v6 = KeyValues::GetString(this: item1->kv, keyName: "filename", defaultValue: defaultValue);
    v7 = KeyValues::GetString(this: item2->kv, keyName: "filename", defaultValue: defaultValue);
    return _V_stricmp(s1: v6, s2: v7);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00641740
// Name: FileBrowserSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl FileBrowserSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *String; // esi
  const char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "filename", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "filename", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00641780
// Name: public: virtual void COperationFileListFrame::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::PerformLayout(COperationFileListFrame *this)
{
  int x; // [esp+4h] [ebp-10h] BYREF
  int w; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  if ( this->m_pSplitter != nullptr )
  {
    this->GetClientArea(this, a2: &x, a3: &y, a4: &w, a5: &h);
    vgui::Panel::SetBounds(this: this->m_pSplitter, x, y: y + 6, wide: w, tall: h - 36);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006417E0
// Name: public: void COperationFileListFrame::AddOperation(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::AddOperation(
        COperationFileListFrame *this,
        const char *pOperation,
        const char *pFileName)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "node", firstKey: "filename", firstValue: pFileName);
  else
    v5 = nullptr;
  KeyValues::SetString(this: v5, keyName: "operation", value: pOperation);
  this->m_pFileBrowser->AddItem(this: this->m_pFileBrowser, a2: v5, a3: 0, a4: false, a5: false);
}

//------------------------------------------------------------------------------
// Address: 0x00641840
// Name: public: void COperationFileListFrame::DoModal(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::DoModal(
        COperationFileListFrame *this,
        KeyValues *pContextKeyValues,
        const char *pMessage)
{
  const char *v3; // eax
  KeyValues *m_pContextKeyValues; // ecx
  vgui::ListPanel *m_pFileBrowser; // ecx
  vgui::Button_vtbl *v7; // edi
  int v8; // eax

  v3 = pMessage;
  if ( pMessage == nullptr )
    v3 = "OperationConfirmed";
  CUtlString::operator=(this: &this->m_MessageName, src: v3);
  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  m_pFileBrowser = this->m_pFileBrowser;
  this->m_pContextKeyValues = pContextKeyValues;
  m_pFileBrowser->SortList(this: m_pFileBrowser);
  if ( this->m_pNoButton->IsVisible(this: this->m_pNoButton) )
  {
    v7 = this->m_pYesButton->__vftable;
    v8 = this->m_pFileBrowser->GetItemCount(this: this->m_pFileBrowser);
    v7->SetEnabled(this: this->m_pYesButton, a2: v8 != 0);
  }
  vgui::Frame::DoModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x006418F0
// Name: public: virtual char const __near * COperationFileListFrame::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall COperationFileListFrame::GetDescription(COperationFileListFrame *this)
{
  return this->m_pText;
}

//------------------------------------------------------------------------------
// Address: 0x00641900
// Name: public: virtual void COperationFileListFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::OnCommand(COperationFileListFrame *this, const char *pCommand)
{
  vgui::TextEntry *m_pDescription; // ecx
  unsigned int v4; // edi
  char *v5; // eax
  vgui::TextEntry *v6; // ecx
  KeyValues *v7; // edi
  const char *v8; // eax
  KeyValues *v9; // edi
  KeyValues *v10; // edi
  const char *v11; // eax
  KeyValues *v12; // edi
  const char *v13; // eax

  if ( _V_stricmp(s1: pCommand, s2: "Yes") == 0 )
  {
    m_pDescription = this->m_pDescription;
    if ( m_pDescription != nullptr )
    {
      v4 = m_pDescription->GetTextLength(this: m_pDescription) + 1;
      v5 = (char *)MemAlloc_Alloc(nSize: v4);
      v6 = this->m_pDescription;
      this->m_pText = v5;
      v6->GetText_2(this: v6, a2: v5, a3: v4);
    }
    if ( this->PerformOperation(this) )
    {
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
      {
        v8 = CUtlString::operator char const *(this: &this->m_MessageName);
        v9 = KeyValues::KeyValues(this: v7, setName: v8, firstKey: "operationPerformed", firstValue: 1);
        goto LABEL_10;
      }
    }
    else
    {
      v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v10 != nullptr )
      {
        v11 = CUtlString::operator char const *(this: &this->m_MessageName);
        v9 = KeyValues::KeyValues(this: v10, setName: v11, firstKey: "operationPerformed", firstValue: 0);
        goto LABEL_10;
      }
    }
    v9 = nullptr;
LABEL_10:
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v9, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
LABEL_12:
    this->CloseModal(this);
    this->PostActionSignal(this, a2: v9);
    return;
  }
  if ( _V_stricmp(s1: pCommand, s2: "No") == 0 )
  {
    v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v12 != nullptr )
    {
      v13 = CUtlString::operator char const *(this: &this->m_MessageName);
      v9 = KeyValues::KeyValues(this: v12, setName: v13, firstKey: "operationPerformed", firstValue: 0);
    }
    else
    {
      v9 = nullptr;
    }
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v9, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    goto LABEL_12;
  }
  vgui::Frame::OnCommand(this, command: pCommand);
}

//------------------------------------------------------------------------------
// Address: 0x00641A90
// Name: private: void CPerforceFileListFrame::AddFileForOpen(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::AddFileForOpen(CPerforceFileListFrame *this, const char *pFullPath)
{
  bool v3; // bl
  bool v4; // zf
  PerforceAction_t m_Action; // eax
  __int32 v6; // eax

  v3 = p4->IsFileInPerforce(this: p4, a2: pFullPath);
  v4 = p4->GetFileState(this: p4, a2: pFullPath) == P4FILE_UNOPENED;
  m_Action = this->m_Action;
  if ( m_Action != PERFORCE_ACTION_FILE_ADD )
  {
    v6 = m_Action - 1;
    if ( v6 != 0 )
    {
      if ( v6 == 1 && v3 && v4 )
        COperationFileListFrame::AddOperation(this, pOperation: "Delete", pFileName: pFullPath);
    }
    else if ( v3 && v4 )
    {
      COperationFileListFrame::AddOperation(this, pOperation: "Edit", pFileName: pFullPath);
    }
  }
  else if ( !v3 && v4 )
  {
    COperationFileListFrame::AddOperation(this, pOperation: "Add", pFileName: pFullPath);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00641B30
// Name: private: void CPerforceFileListFrame::AddFileForSubmit(char const __near *,enum P4FileState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::AddFileForSubmit(
        CPerforceFileListFrame *this,
        const char *pFullPath,
        P4FileState_t state)
{
  const char *v4; // eax
  char pBuf[128]; // [esp+4h] [ebp-80h] BYREF

  if ( state != P4FILE_UNOPENED )
  {
    v4 = "Revert";
    if ( this->m_Action != PERFORCE_ACTION_FILE_REVERT )
      v4 = "Submit";
    switch ( state )
    {
      case P4FILE_OPENED_FOR_ADD:
        V_snprintf(pDest: pBuf, maxLen: 128, pFormat: "%s Add", v4);
        goto LABEL_9;
      case P4FILE_OPENED_FOR_EDIT:
        V_snprintf(pDest: pBuf, maxLen: 128, pFormat: "%s Edit", v4);
        goto LABEL_9;
      case P4FILE_OPENED_FOR_DELETE:
        V_snprintf(pDest: pBuf, maxLen: 128, pFormat: "%s Delete", v4);
        goto LABEL_9;
      case P4FILE_OPENED_FOR_INTEGRATE:
        V_snprintf(pDest: pBuf, maxLen: 128, pFormat: "%s Integrate", v4);
LABEL_9:
        COperationFileListFrame::AddOperation(this, pOperation: pBuf, pFileName: pFullPath);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00641BC0
// Name: public: void CPerforceFileListFrame::AddFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::AddFile(CPerforceFileListFrame *this, const char *pFullPath)
{
  bool (__thiscall *FileExists)(IBaseFileSystem *, const char *, const char *); // edx
  IBaseFileSystem *v4; // ecx
  bool v5; // bl
  P4FileState_t v6; // eax

  FileExists = g_pFullFileSystem->FileExists;
  v4 = &g_pFullFileSystem->IBaseFileSystem;
  if ( this->m_Action >= PERFORCE_ACTION_FILE_REVERT )
  {
    v5 = FileExists(this: v4, a2: pFullPath, a3: nullptr);
    v6 = p4->GetFileState(this: p4, a2: pFullPath);
    if ( v5 || v6 == P4FILE_OPENED_FOR_DELETE )
      CPerforceFileListFrame::AddFileForSubmit(this, pFullPath, state: v6);
  }
  else if ( FileExists(this: v4, a2: pFullPath, a3: nullptr) )
  {
    CPerforceFileListFrame::AddFileForOpen(this, pFullPath);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00641C30
// Name: private: virtual bool CPerforceFileListFrame::PerformOperation(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPerforceFileListFrame::PerformOperation(CPerforceFileListFrame *this)
{
  int v2; // ebx
  void *v3; // esp
  const char **v4; // eax
  int v5; // esi
  int v6; // eax
  KeyValues *v7; // eax
  const char *String; // eax
  const char **v9; // ecx
  PerforceAction_t m_Action; // ecx
  char v11; // al
  const char *v12; // ebx
  vgui::MessageBox *v13; // esi
  vgui::Panel *v14; // eax
  vgui::MessageBox *v15; // esi
  const char *v16; // eax
  const char *v17; // esi
  vgui::MessageBox *v18; // esi
  vgui::Panel *v19; // eax
  vgui::MessageBox *v20; // esi
  _BYTE v22[12]; // [esp+0h] [ebp-14h] BYREF
  const char **ppFileNames; // [esp+Ch] [ebp-8h]
  bool bSuccess; // [esp+13h] [ebp-1h]

  v2 = this->m_pFileBrowser->GetItemCount(this: this->m_pFileBrowser);
  v3 = alloca(4 * v2);
  v4 = (const char **)v22;
  v5 = 0;
  ppFileNames = (const char **)v22;
  if ( v2 > 0 )
  {
    do
    {
      v6 = this->m_pFileBrowser->GetItemIDFromRow(this: this->m_pFileBrowser, a2: v5);
      v7 = this->m_pFileBrowser->GetItem(this: this->m_pFileBrowser, a2: v6);
      String = KeyValues::GetString(this: v7, keyName: "filename", defaultValue: defaultValue);
      v9 = ppFileNames;
      ppFileNames[v5++] = String;
    }
    while ( v5 < v2 );
    v4 = v9;
  }
  m_Action = this->m_Action;
  bSuccess = false;
  switch ( m_Action )
  {
    case PERFORCE_ACTION_FILE_ADD:
      v11 = ((int (__stdcall *)(int, const char **))p4->OpenFilesForAdd)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_EDIT:
      v11 = ((int (__stdcall *)(int, const char **))p4->OpenFilesForEdit)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_DELETE:
      v11 = ((int (__stdcall *)(int, const char **))p4->OpenFilesForDelete)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_REVERT:
      v11 = ((int (__stdcall *)(int, const char **))p4->RevertFiles)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_SUBMIT:
      v16 = this->GetDescription(this);
      v17 = v16;
      if ( *v16 != 0 && _V_stricmp(s1: v16, s2: "<enter description here>") != 0 )
      {
        v11 = p4->SubmitFiles(this: p4, a2: v2, a3: ppFileNames, a4: v17);
LABEL_6:
        bSuccess = v11;
LABEL_7:
        v12 = p4->GetLastError(this: p4);
        if ( !bSuccess )
        {
          v13 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
          if ( v13 != nullptr )
          {
            v14 = this->GetParent(this);
            v15 = vgui::MessageBox::MessageBox(this: v13, title: "Perforce Error!", text: v12, parent: v14);
          }
          else
          {
            v15 = nullptr;
          }
          v15->SetSmallCaption(this: v15, a2: true);
          v15->DoModal_2(this: v15, a2: nullptr);
        }
        return bSuccess;
      }
      else
      {
        v18 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
        if ( v18 != nullptr )
        {
          v19 = this->GetParent(this);
          v20 = vgui::MessageBox::MessageBox(
                  this: v18,
                  title: "Submission Error!",
                  text: "Description required for submission.",
                  parent: v19);
        }
        else
        {
          v20 = nullptr;
        }
        v20->SetSmallCaption(this: v20, a2: true);
        v20->DoModal_2(this: v20, a2: nullptr);
        return false;
      }
    default:
      goto LABEL_7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00641E40
// Name: public: COperationFileListFrame::COperationFileListFrame(class vgui::Panel __near *,char const __near *,char const __near *,bool,bool,int)
// Source: json
//------------------------------------------------------------------------------
COperationFileListFrame *__thiscall COperationFileListFrame::COperationFileListFrame(
        COperationFileListFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        const char *pColumnHeader,
        bool bShowDescription,
        bool bShowOkOnly,
        int nDialogID)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  COperationFileListFrame *Child; // ebx
  vgui::Splitter *v12; // eax
  vgui::Splitter *v13; // eax
  vgui::Panel *v14; // edi
  vgui::TextEntry *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::ListPanel *v17; // eax
  vgui::ListPanel *v18; // eax
  vgui::Button *v19; // eax
  vgui::Button *v20; // eax
  vgui::Button *v21; // eax
  vgui::Button *v22; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "PerforceFileList", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (COperationFileListFrame_vtbl *)&COperationFileListFrame::`vftable';
  if ( `COperationFileListFrame::ChainToMap'::`2'::chained == 0 )
  {
    `COperationFileListFrame::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "COperationFileListFrame");
    v8->pfnClassName = COperationFileListFrame::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `COperationFileListFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COperationFileListFrame::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "COperationFileListFrame");
    v9->pfnClassName = COperationFileListFrame::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `COperationFileListFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COperationFileListFrame::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "COperationFileListFrame");
    v10->pfnClassName = COperationFileListFrame::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CUtlString::CUtlString(this: &this->m_MessageName);
  this->m_pText = nullptr;
  Child = this;
  this->m_pDescription = nullptr;
  this->m_pSplitter = nullptr;
  if ( bShowDescription )
  {
    v12 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
    if ( v12 != nullptr )
      v13 = vgui::Splitter::Splitter(
              this: v12,
              parent: this,
              name: "Splitter",
              mode: SPLITTER_MODE_HORIZONTAL,
              nCount: 1);
    else
      v13 = nullptr;
    this->m_pSplitter = v13;
    Child = (COperationFileListFrame *)vgui::Panel::GetChild(this: v13, index: 0);
    v14 = vgui::Panel::GetChild(this: this->m_pSplitter, index: 1);
    v15 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
    if ( v15 != nullptr )
      v16 = vgui::TextEntry::TextEntry(this: v15, parent: v14, panelName: "Description");
    else
      v16 = nullptr;
    this->m_pDescription = v16;
    v16->SetMultiline(this: v16, a2: true);
    this->m_pDescription->SetCatchEnterKey(this: this->m_pDescription, a2: true);
    this->m_pDescription->SetText(this: this->m_pDescription, a2: "<enter description here>");
  }
  v17 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v17 != nullptr )
    v18 = vgui::ListPanel::ListPanel(this: v17, parent: Child, panelName: "Browser");
  else
    v18 = nullptr;
  this->m_pFileBrowser = v18;
  v18->AddColumnHeader(this: v18, a2: 0, a3: "operation", a4: "Operation", a5: 52, a6: 0);
  this->m_pFileBrowser->AddColumnHeader(
    this: this->m_pFileBrowser,
    a2: 1,
    a3: "filename",
    a4: pColumnHeader,
    a5: 128,
    a6: 2);
  this->m_pFileBrowser->SetSelectIndividualCells(this: this->m_pFileBrowser, a2: false);
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pFileBrowser, bState: false);
  this->m_pFileBrowser->SetEmptyListText_2(this: this->m_pFileBrowser, a2: "No Perforce Operations");
  this->m_pFileBrowser->SetDragEnabled(this: this->m_pFileBrowser, a2: true);
  this->m_pFileBrowser->AddActionSignalTarget_2(this: this->m_pFileBrowser, a2: this);
  this->m_pFileBrowser->SetSortFunc(this: this->m_pFileBrowser, a2: 0, a3: OperationSortFunc);
  this->m_pFileBrowser->SetSortFunc(this: this->m_pFileBrowser, a2: 1, a3: FileBrowserSortFunc);
  this->m_pFileBrowser->SetSortColumn(this: this->m_pFileBrowser, a2: 0);
  v19 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v19 != nullptr )
    v20 = vgui::Button::Button(
            this: v19,
            parent: this,
            panelName: "YesButton",
            text: "Yes",
            pActionSignalTarget: this,
            pCmd: "Yes");
  else
    v20 = nullptr;
  this->m_pYesButton = v20;
  v21 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v21 != nullptr )
    v22 = vgui::Button::Button(
            this: v21,
            parent: this,
            panelName: "NoButton",
            text: "No",
            pActionSignalTarget: this,
            pCmd: "No");
  else
    v22 = nullptr;
  this->m_pNoButton = v22;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  if ( bShowDescription )
    vgui::EditablePanel::LoadControlSettingsAndUserConfig(
      this,
      dialogResourceName: "resource/perforcefilelistdescription.res",
      dialogID: nDialogID);
  else
    vgui::EditablePanel::LoadControlSettingsAndUserConfig(
      this,
      dialogResourceName: "resource/perforcefilelist.res",
      dialogID: nDialogID);
  if ( bShowOkOnly )
  {
    this->m_pYesButton->SetText_2(this: this->m_pYesButton, a2: "#MessageBox_OK");
    this->m_pNoButton->SetVisible(this: this->m_pNoButton, a2: false);
  }
  this->m_pContextKeyValues = nullptr;
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x006421A0
// Name: public: virtual struct vgui::PanelMessageMap __near * COperationFileListFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COperationFileListFrame::GetMessageMap(COperationFileListFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COperationFileListFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COperationFileListFrame::GetMessageMap'::`2'::s_pMap;
  `COperationFileListFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COperationFileListFrame");
  `COperationFileListFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006421D0
// Name: public: virtual struct PanelAnimationMap __near * COperationFileListFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COperationFileListFrame::GetAnimMap(COperationFileListFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "COperationFileListFrame");
}

//------------------------------------------------------------------------------
// Address: 0x006421E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COperationFileListFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COperationFileListFrame::GetKBMap(COperationFileListFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COperationFileListFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COperationFileListFrame::GetKBMap'::`2'::s_pMap;
  `COperationFileListFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COperationFileListFrame");
  `COperationFileListFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00642210
// Name: public: virtual COperationFileListFrame::~COperationFileListFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::~COperationFileListFrame(COperationFileListFrame *this)
{
  KeyValues *m_pContextKeyValues; // ecx

  this->__vftable = (COperationFileListFrame_vtbl *)&COperationFileListFrame::`vftable';
  vgui::EditablePanel::SaveUserConfig(this);
  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  if ( this->m_pText != nullptr )
    free(pMem: this->m_pText);
  this->m_MessageName.m_Storage.m_nActualLength = 0;
  if ( this->m_MessageName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_MessageName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_MessageName.m_Storage.m_Memory.m_pMemory);
      this->m_MessageName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_MessageName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x006422C0
// Name: public: CPerforceFileListFrame::CPerforceFileListFrame(class vgui::Panel __near *,char const __near *,char const __near *,enum PerforceAction_t)
// Source: json
//------------------------------------------------------------------------------
CPerforceFileListFrame *__thiscall CPerforceFileListFrame::CPerforceFileListFrame(
        CPerforceFileListFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        const char *pColumnHeader,
        PerforceAction_t action)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  COperationFileListFrame::COperationFileListFrame(
    this,
    pParent,
    pTitle,
    pColumnHeader,
    bShowDescription: action == PERFORCE_ACTION_FILE_SUBMIT,
    bShowOkOnly: false,
    nDialogID: 0);
  this->__vftable = (CPerforceFileListFrame_vtbl *)&CPerforceFileListFrame::`vftable';
  if ( `CPerforceFileListFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CPerforceFileListFrame::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CPerforceFileListFrame");
    v6->pfnClassName = CPerforceFileListFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "COperationFileListFrame");
  }
  if ( `CPerforceFileListFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPerforceFileListFrame::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CPerforceFileListFrame");
    v7->pfnClassName = CPerforceFileListFrame::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "COperationFileListFrame");
  }
  if ( `CPerforceFileListFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPerforceFileListFrame::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CPerforceFileListFrame");
    v8->pfnClassName = CPerforceFileListFrame::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "COperationFileListFrame");
  }
  this->m_OpenedFiles.m_Memory.m_pMemory = nullptr;
  this->m_OpenedFiles.m_Memory.m_nAllocationCount = 0;
  this->m_OpenedFiles.m_Memory.m_nGrowSize = 0;
  this->m_OpenedFiles.m_Size = 0;
  this->m_OpenedFiles.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_LastOpenedFilePathId);
  this->m_Action = action;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x006423D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPerforceFileListFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPerforceFileListFrame::GetMessageMap(CPerforceFileListFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPerforceFileListFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPerforceFileListFrame::GetMessageMap'::`2'::s_pMap;
  `CPerforceFileListFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPerforceFileListFrame");
  `CPerforceFileListFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00642400
// Name: public: virtual struct PanelAnimationMap __near * CPerforceFileListFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPerforceFileListFrame::GetAnimMap(CPerforceFileListFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CPerforceFileListFrame");
}

//------------------------------------------------------------------------------
// Address: 0x00642410
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPerforceFileListFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPerforceFileListFrame::GetKBMap(CPerforceFileListFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPerforceFileListFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPerforceFileListFrame::GetKBMap'::`2'::s_pMap;
  `CPerforceFileListFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPerforceFileListFrame");
  `CPerforceFileListFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00642440
// Name: public: virtual CPerforceFileListFrame::~CPerforceFileListFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::~CPerforceFileListFrame(CPerforceFileListFrame *this)
{
  bool v2; // sf

  this->__vftable = (CPerforceFileListFrame_vtbl *)&CPerforceFileListFrame::`vftable';
  v2 = this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_LastOpenedFilePathId.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_pMemory);
      this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_OpenedFiles);
  COperationFileListFrame::~COperationFileListFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x006424A0
// Name: void ShowPerforceQuery(class vgui::Panel __near *,char const __near *,class vgui::Panel __near *,class KeyValues __near *,enum PerforceAction_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowPerforceQuery(
        vgui::Panel *pParent,
        const char *pFileName,
        vgui::Panel *pActionSignalTarget,
        KeyValues *pKeyValues,
        PerforceAction_t actionFilter)
{
  PerforceAction_t v5; // esi
  const char *v6; // edi
  CPerforceFileListFrame *v7; // eax
  CPerforceFileListFrame *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // edi
  vgui::IVGui *v11; // esi
  vgui::IVGui_vtbl *v12; // ebx
  int v13; // eax

  p4->RefreshActiveClient(this: p4);
  if ( p4->IsFileInPerforce(this: p4, a2: pFileName) )
  {
    if ( p4->GetFileState(this: p4, a2: pFileName) != P4FILE_UNOPENED )
      goto LABEL_13;
    v5 = PERFORCE_ACTION_FILE_EDIT;
    v6 = "Check Out File from Perforce?";
  }
  else
  {
    v5 = PERFORCE_ACTION_FILE_ADD;
    v6 = "Add File to Perforce?";
  }
  if ( actionFilter == PERFORCE_ACTION_NONE || actionFilter == v5 )
  {
    v7 = (CPerforceFileListFrame *)MemAlloc_Alloc(nSize: 0x26Cu);
    if ( v7 != nullptr )
      v8 = CPerforceFileListFrame::CPerforceFileListFrame(
             this: v7,
             pParent,
             pTitle: v6,
             pColumnHeader: "File",
             action: v5);
    else
      v8 = nullptr;
    CPerforceFileListFrame::AddFile(this: v8, pFullPath: pFileName);
    if ( pActionSignalTarget != nullptr )
      v8->AddActionSignalTarget_2(this: v8, a2: pActionSignalTarget);
    COperationFileListFrame::DoModal(this: v8, pContextKeyValues: pKeyValues, pMessage: "PerforceQueryCompleted");
    return;
  }
LABEL_13:
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(
            this: v9,
            setName: "PerforceQueryCompleted",
            firstKey: "operationPerformed",
            firstValue: 1);
  else
    v10 = nullptr;
  if ( pKeyValues != nullptr )
    KeyValues::AddSubKey(this: v10, pSubkey: pKeyValues);
  v11 = g_pVGui;
  v12 = g_pVGui->__vftable;
  v13 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))pActionSignalTarget->GetVPanel)(
          a1: pActionSignalTarget,
          a2: v10,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v12->PostMessage)(a1: v11, a2: v13);
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102DE1C0
// Name: public: static char const __near * COperationFileListFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COperationFileListFrame::GetPanelClassName()
{
  return "COperationFileListFrame";
}

//------------------------------------------------------------------------------
// Address: 0x102DE1E0
// Name: OperationSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl OperationSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  char *String; // esi
  char *v4; // eax
  int result; // eax
  char *v6; // esi
  char *v7; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "operation", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "operation", defaultValue: defaultValue);
  result = _V_stricmp(s1: String, s2: v4);
  if ( result == 0 )
  {
    v6 = KeyValues::GetString(this: item1->kv, keyName: "filename", defaultValue: defaultValue);
    v7 = KeyValues::GetString(this: item2->kv, keyName: "filename", defaultValue: defaultValue);
    return _V_stricmp(s1: v6, s2: v7);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DE260
// Name: FileBrowserSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl FileBrowserSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  char *String; // esi
  char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "filename", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "filename", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x102DE2A0
// Name: public: virtual void COperationFileListFrame::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::PerformLayout(COperationFileListFrame *this)
{
  int x; // [esp+4h] [ebp-10h] BYREF
  int w; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  if ( this->m_pSplitter != nullptr )
  {
    this->GetClientArea(this, a2: &x, a3: &y, a4: &w, a5: &h);
    vgui::Panel::SetBounds(this: this->m_pSplitter, x, y: y + 6, wide: w, tall: h - 36);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DE300
// Name: public: void COperationFileListFrame::AddOperation(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::AddOperation(
        COperationFileListFrame *this,
        const char *pOperation,
        const char *pFileName)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "node", firstKey: "filename", firstValue: pFileName);
  else
    v5 = nullptr;
  KeyValues::SetString(this: v5, keyName: "operation", value: pOperation);
  this->m_pFileBrowser->AddItem(this: this->m_pFileBrowser, a2: v5, a3: 0, a4: false, a5: false);
}

//------------------------------------------------------------------------------
// Address: 0x102DE360
// Name: public: void COperationFileListFrame::DoModal(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::DoModal(
        COperationFileListFrame *this,
        KeyValues *pContextKeyValues,
        __m128i *pMessage)
{
  __m128i *v3; // eax
  KeyValues *m_pContextKeyValues; // ecx
  vgui::ListPanel *m_pFileBrowser; // ecx
  vgui::Button_vtbl *v7; // edi
  int v8; // eax

  v3 = pMessage;
  if ( pMessage == nullptr )
    v3 = (__m128i *)"OperationConfirmed";
  CUtlString::operator=(this: &this->m_MessageName, src: v3);
  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  m_pFileBrowser = this->m_pFileBrowser;
  this->m_pContextKeyValues = pContextKeyValues;
  m_pFileBrowser->SortList(this: m_pFileBrowser);
  if ( this->m_pNoButton->IsVisible(this: this->m_pNoButton) )
  {
    v7 = this->m_pYesButton->__vftable;
    v8 = this->m_pFileBrowser->GetItemCount(this: this->m_pFileBrowser);
    v7->SetEnabled(this: this->m_pYesButton, a2: v8 != 0);
  }
  vgui::Frame::DoModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x102DE410
// Name: public: virtual char const __near * COperationFileListFrame::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall COperationFileListFrame::GetDescription(COperationFileListFrame *this)
{
  return this->m_pText;
}

//------------------------------------------------------------------------------
// Address: 0x102DE420
// Name: public: virtual void COperationFileListFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::OnCommand(COperationFileListFrame *this, const char *pCommand)
{
  vgui::TextEntry *m_pDescription; // ecx
  unsigned int v4; // edi
  char *v5; // eax
  vgui::TextEntry *v6; // ecx
  KeyValues *v7; // edi
  const char *v8; // eax
  KeyValues *v9; // edi
  KeyValues *v10; // edi
  const char *v11; // eax
  KeyValues *v12; // edi
  const char *v13; // eax

  if ( _V_stricmp(s1: pCommand, s2: "Yes") == 0 )
  {
    m_pDescription = this->m_pDescription;
    if ( m_pDescription != nullptr )
    {
      v4 = m_pDescription->GetTextLength(this: m_pDescription) + 1;
      v5 = (char *)MemAlloc_Alloc(nSize: v4);
      v6 = this->m_pDescription;
      this->m_pText = v5;
      v6->GetText_2(this: v6, a2: v5, a3: v4);
    }
    if ( this->PerformOperation(this) )
    {
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
      {
        v8 = CUtlString::operator char const *(this: &this->m_MessageName);
        v9 = KeyValues::KeyValues(this: v7, setName: v8, firstKey: "operationPerformed", firstValue: 1);
        goto LABEL_10;
      }
    }
    else
    {
      v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v10 != nullptr )
      {
        v11 = CUtlString::operator char const *(this: &this->m_MessageName);
        v9 = KeyValues::KeyValues(this: v10, setName: v11, firstKey: "operationPerformed", firstValue: 0);
        goto LABEL_10;
      }
    }
    v9 = nullptr;
LABEL_10:
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v9, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
LABEL_12:
    this->CloseModal(this);
    this->PostActionSignal(this, a2: v9);
    return;
  }
  if ( _V_stricmp(s1: pCommand, s2: "No") == 0 )
  {
    v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v12 != nullptr )
    {
      v13 = CUtlString::operator char const *(this: &this->m_MessageName);
      v9 = KeyValues::KeyValues(this: v12, setName: v13, firstKey: "operationPerformed", firstValue: 0);
    }
    else
    {
      v9 = nullptr;
    }
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v9, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    goto LABEL_12;
  }
  vgui::Frame::OnCommand(this, command: pCommand);
}

//------------------------------------------------------------------------------
// Address: 0x102DE5B0
// Name: private: void CPerforceFileListFrame::AddFileForOpen(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::AddFileForOpen(CPerforceFileListFrame *this, const char *pFullPath)
{
  bool v3; // bl
  bool v4; // zf
  PerforceAction_t m_Action; // eax
  __int32 v6; // eax

  v3 = p4->IsFileInPerforce(this: p4, a2: pFullPath);
  v4 = p4->GetFileState(this: p4, a2: pFullPath) == P4FILE_UNOPENED;
  m_Action = this->m_Action;
  if ( m_Action != PERFORCE_ACTION_FILE_ADD )
  {
    v6 = m_Action - 1;
    if ( v6 != 0 )
    {
      if ( v6 == 1 && v3 && v4 )
        COperationFileListFrame::AddOperation(this, pOperation: "Delete", pFileName: pFullPath);
    }
    else if ( v3 && v4 )
    {
      COperationFileListFrame::AddOperation(this, pOperation: "Edit", pFileName: pFullPath);
    }
  }
  else if ( !v3 && v4 )
  {
    COperationFileListFrame::AddOperation(this, pOperation: "Add", pFileName: pFullPath);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DE650
// Name: private: void CPerforceFileListFrame::AddFileForSubmit(char const __near *,enum P4FileState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::AddFileForSubmit(
        CPerforceFileListFrame *this,
        const char *pFullPath,
        P4FileState_t state)
{
  const char *v4; // eax
  char pBuf[128]; // [esp+4h] [ebp-80h] BYREF

  if ( state != P4FILE_UNOPENED )
  {
    v4 = "Revert";
    if ( this->m_Action != PERFORCE_ACTION_FILE_REVERT )
      v4 = "Submit";
    switch ( state )
    {
      case P4FILE_OPENED_FOR_ADD:
        V_snprintf(pDest: pBuf, maxLen: 128, pFormat: "%s Add", v4);
        goto LABEL_9;
      case P4FILE_OPENED_FOR_EDIT:
        V_snprintf(pDest: pBuf, maxLen: 128, pFormat: "%s Edit", v4);
        goto LABEL_9;
      case P4FILE_OPENED_FOR_DELETE:
        V_snprintf(pDest: pBuf, maxLen: 128, pFormat: "%s Delete", v4);
        goto LABEL_9;
      case P4FILE_OPENED_FOR_INTEGRATE:
        V_snprintf(pDest: pBuf, maxLen: 128, pFormat: "%s Integrate", v4);
LABEL_9:
        COperationFileListFrame::AddOperation(this, pOperation: pBuf, pFileName: pFullPath);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DE6E0
// Name: public: void CPerforceFileListFrame::AddFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::AddFile(CPerforceFileListFrame *this, const char *pFullPath)
{
  bool (__thiscall *FileExists)(IBaseFileSystem *, const char *, const char *); // edx
  IBaseFileSystem *v4; // ecx
  bool v5; // bl
  P4FileState_t v6; // eax

  FileExists = g_pFullFileSystem->FileExists;
  v4 = &g_pFullFileSystem->IBaseFileSystem;
  if ( this->m_Action >= PERFORCE_ACTION_FILE_REVERT )
  {
    v5 = FileExists(this: v4, a2: pFullPath, a3: nullptr);
    v6 = p4->GetFileState(this: p4, a2: pFullPath);
    if ( v5 || v6 == P4FILE_OPENED_FOR_DELETE )
      CPerforceFileListFrame::AddFileForSubmit(this, pFullPath, state: v6);
  }
  else if ( FileExists(this: v4, a2: pFullPath, a3: nullptr) )
  {
    CPerforceFileListFrame::AddFileForOpen(this, pFullPath);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DE750
// Name: private: virtual bool CPerforceFileListFrame::PerformOperation(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPerforceFileListFrame::PerformOperation(CPerforceFileListFrame *this)
{
  int v2; // ebx
  void *v3; // esp
  const char **v4; // eax
  int v5; // esi
  int v6; // eax
  KeyValues *v7; // eax
  char *String; // eax
  const char **v9; // ecx
  PerforceAction_t m_Action; // ecx
  char v11; // al
  const char *v12; // ebx
  vgui::MessageBox *v13; // esi
  vgui::Panel *v14; // eax
  vgui::MessageBox *v15; // esi
  const char *v16; // eax
  const char *v17; // esi
  vgui::MessageBox *v18; // esi
  vgui::Panel *v19; // eax
  vgui::MessageBox *v20; // esi
  _BYTE v22[12]; // [esp+0h] [ebp-14h] BYREF
  const char **ppFileNames; // [esp+Ch] [ebp-8h]
  bool bSuccess; // [esp+13h] [ebp-1h]

  v2 = this->m_pFileBrowser->GetItemCount(this: this->m_pFileBrowser);
  v3 = alloca(4 * v2);
  v4 = (const char **)v22;
  v5 = 0;
  ppFileNames = (const char **)v22;
  if ( v2 > 0 )
  {
    do
    {
      v6 = this->m_pFileBrowser->GetItemIDFromRow(this: this->m_pFileBrowser, a2: v5);
      v7 = this->m_pFileBrowser->GetItem(this: this->m_pFileBrowser, a2: v6);
      String = KeyValues::GetString(this: v7, keyName: "filename", defaultValue: defaultValue);
      v9 = ppFileNames;
      ppFileNames[v5++] = String;
    }
    while ( v5 < v2 );
    v4 = v9;
  }
  m_Action = this->m_Action;
  bSuccess = false;
  switch ( m_Action )
  {
    case PERFORCE_ACTION_FILE_ADD:
      v11 = ((int (__stdcall *)(int, const char **))p4->OpenFilesForAdd)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_EDIT:
      v11 = ((int (__stdcall *)(int, const char **))p4->OpenFilesForEdit)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_DELETE:
      v11 = ((int (__stdcall *)(int, const char **))p4->OpenFilesForDelete)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_REVERT:
      v11 = ((int (__stdcall *)(int, const char **))p4->RevertFiles)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_SUBMIT:
      v16 = this->GetDescription(this);
      v17 = v16;
      if ( *v16 != 0 && _V_stricmp(s1: v16, s2: "<enter description here>") != 0 )
      {
        v11 = p4->SubmitFiles(this: p4, a2: v2, a3: ppFileNames, a4: v17);
LABEL_6:
        bSuccess = v11;
LABEL_7:
        v12 = p4->GetLastError(this: p4);
        if ( !bSuccess )
        {
          v13 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
          if ( v13 != nullptr )
          {
            v14 = this->GetParent(this);
            v15 = vgui::MessageBox::MessageBox(this: v13, title: "Perforce Error!", text: v12, parent: v14);
          }
          else
          {
            v15 = nullptr;
          }
          v15->SetSmallCaption(this: v15, a2: true);
          v15->DoModal_2(this: v15, a2: nullptr);
        }
        return bSuccess;
      }
      else
      {
        v18 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
        if ( v18 != nullptr )
        {
          v19 = this->GetParent(this);
          v20 = vgui::MessageBox::MessageBox(
                  this: v18,
                  title: "Submission Error!",
                  text: "Description required for submission.",
                  parent: v19);
        }
        else
        {
          v20 = nullptr;
        }
        v20->SetSmallCaption(this: v20, a2: true);
        v20->DoModal_2(this: v20, a2: nullptr);
        return false;
      }
    default:
      goto LABEL_7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DE960
// Name: public: COperationFileListFrame::COperationFileListFrame(class vgui::Panel __near *,char const __near *,char const __near *,bool,bool,int)
// Source: json
//------------------------------------------------------------------------------
COperationFileListFrame *__thiscall COperationFileListFrame::COperationFileListFrame(
        COperationFileListFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        const char *pColumnHeader,
        bool bShowDescription,
        bool bShowOkOnly,
        int nDialogID)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  COperationFileListFrame *Child; // ebx
  vgui::Splitter *v12; // eax
  vgui::Splitter *v13; // eax
  vgui::Panel *v14; // edi
  vgui::TextEntry *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::ListPanel *v17; // eax
  vgui::ListPanel *v18; // eax
  vgui::Button *v19; // eax
  vgui::Button *v20; // eax
  vgui::Button *v21; // eax
  vgui::Button *v22; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "PerforceFileList", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (COperationFileListFrame_vtbl *)&COperationFileListFrame::`vftable';
  if ( `COperationFileListFrame::ChainToMap'::`2'::chained == 0 )
  {
    `COperationFileListFrame::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: (void **)"COperationFileListFrame");
    v8->pfnClassName = COperationFileListFrame::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"vgui::Frame");
  }
  if ( `COperationFileListFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COperationFileListFrame::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "COperationFileListFrame");
    v9->pfnClassName = COperationFileListFrame::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `COperationFileListFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COperationFileListFrame::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"COperationFileListFrame");
    v10->pfnClassName = COperationFileListFrame::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"vgui::Frame");
  }
  CUtlString::CUtlString(this: &this->m_MessageName);
  this->m_pText = nullptr;
  Child = this;
  this->m_pDescription = nullptr;
  this->m_pSplitter = nullptr;
  if ( bShowDescription )
  {
    v12 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
    if ( v12 != nullptr )
      v13 = vgui::Splitter::Splitter(
              this: v12,
              parent: this,
              name: "Splitter",
              mode: SPLITTER_MODE_HORIZONTAL,
              nCount: 1);
    else
      v13 = nullptr;
    this->m_pSplitter = v13;
    Child = (COperationFileListFrame *)vgui::Panel::GetChild(this: v13, index: 0);
    v14 = vgui::Panel::GetChild(this: this->m_pSplitter, index: 1);
    v15 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
    if ( v15 != nullptr )
      v16 = vgui::TextEntry::TextEntry(this: v15, parent: v14, panelName: "Description");
    else
      v16 = nullptr;
    this->m_pDescription = v16;
    v16->SetMultiline(this: v16, a2: true);
    this->m_pDescription->SetCatchEnterKey(this: this->m_pDescription, a2: true);
    this->m_pDescription->SetText(this: this->m_pDescription, a2: "<enter description here>");
  }
  v17 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v17 != nullptr )
    v18 = vgui::ListPanel::ListPanel(this: v17, parent: Child, panelName: (__m128i *)"Browser");
  else
    v18 = nullptr;
  this->m_pFileBrowser = v18;
  v18->AddColumnHeader(this: v18, a2: 0, a3: "operation", a4: "Operation", a5: 52, a6: 0);
  this->m_pFileBrowser->AddColumnHeader(
    this: this->m_pFileBrowser,
    a2: 1,
    a3: "filename",
    a4: pColumnHeader,
    a5: 128,
    a6: 2);
  this->m_pFileBrowser->SetSelectIndividualCells(this: this->m_pFileBrowser, a2: false);
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pFileBrowser, bState: false);
  this->m_pFileBrowser->SetEmptyListText_2(this: this->m_pFileBrowser, a2: "No Perforce Operations");
  this->m_pFileBrowser->SetDragEnabled(this: this->m_pFileBrowser, a2: true);
  this->m_pFileBrowser->AddActionSignalTarget_2(this: this->m_pFileBrowser, a2: this);
  this->m_pFileBrowser->SetSortFunc(this: this->m_pFileBrowser, a2: 0, a3: OperationSortFunc);
  this->m_pFileBrowser->SetSortFunc(this: this->m_pFileBrowser, a2: 1, a3: FileBrowserSortFunc);
  this->m_pFileBrowser->SetSortColumn(this: this->m_pFileBrowser, a2: 0);
  v19 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v19 != nullptr )
    v20 = vgui::Button::Button(
            this: v19,
            parent: this,
            panelName: "YesButton",
            text: "Yes",
            pActionSignalTarget: this,
            pCmd: "Yes");
  else
    v20 = nullptr;
  this->m_pYesButton = v20;
  v21 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v21 != nullptr )
    v22 = vgui::Button::Button(
            this: v21,
            parent: this,
            panelName: "NoButton",
            text: "No",
            pActionSignalTarget: this,
            pCmd: "No");
  else
    v22 = nullptr;
  this->m_pNoButton = v22;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  if ( bShowDescription )
    vgui::EditablePanel::LoadControlSettingsAndUserConfig(
      this,
      dialogResourceName: "resource/perforcefilelistdescription.res",
      dialogID: nDialogID);
  else
    vgui::EditablePanel::LoadControlSettingsAndUserConfig(
      this,
      dialogResourceName: "resource/perforcefilelist.res",
      dialogID: nDialogID);
  if ( bShowOkOnly )
  {
    this->m_pYesButton->SetText(this: this->m_pYesButton, a2: "#MessageBox_OK");
    this->m_pNoButton->SetVisible(this: this->m_pNoButton, a2: false);
  }
  this->m_pContextKeyValues = nullptr;
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102DECC0
// Name: public: virtual struct vgui::PanelMessageMap __near * COperationFileListFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COperationFileListFrame::GetMessageMap(COperationFileListFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COperationFileListFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COperationFileListFrame::GetMessageMap'::`2'::s_pMap;
  `COperationFileListFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"COperationFileListFrame");
  `COperationFileListFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DECF0
// Name: public: virtual struct PanelAnimationMap __near * COperationFileListFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COperationFileListFrame::GetAnimMap(COperationFileListFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "COperationFileListFrame");
}

//------------------------------------------------------------------------------
// Address: 0x102DED00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COperationFileListFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COperationFileListFrame::GetKBMap(COperationFileListFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COperationFileListFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COperationFileListFrame::GetKBMap'::`2'::s_pMap;
  `COperationFileListFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"COperationFileListFrame");
  `COperationFileListFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DED30
// Name: public: virtual COperationFileListFrame::~COperationFileListFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::~COperationFileListFrame(COperationFileListFrame *this)
{
  KeyValues *m_pContextKeyValues; // ecx

  this->__vftable = (COperationFileListFrame_vtbl *)&COperationFileListFrame::`vftable';
  vgui::EditablePanel::SaveUserConfig(this);
  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  if ( this->m_pText != nullptr )
    free(pMem: this->m_pText);
  this->m_MessageName.m_Storage.m_nActualLength = 0;
  if ( this->m_MessageName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_MessageName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_MessageName.m_Storage.m_Memory.m_pMemory);
      this->m_MessageName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_MessageName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x102DEDE0
// Name: public: CPerforceFileListFrame::CPerforceFileListFrame(class vgui::Panel __near *,char const __near *,char const __near *,enum PerforceAction_t)
// Source: json
//------------------------------------------------------------------------------
CPerforceFileListFrame *__thiscall CPerforceFileListFrame::CPerforceFileListFrame(
        CPerforceFileListFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        const char *pColumnHeader,
        PerforceAction_t action)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  COperationFileListFrame::COperationFileListFrame(
    this,
    pParent,
    pTitle,
    pColumnHeader,
    bShowDescription: action == PERFORCE_ACTION_FILE_SUBMIT,
    bShowOkOnly: false,
    nDialogID: 0);
  this->__vftable = (CPerforceFileListFrame_vtbl *)&CPerforceFileListFrame::`vftable';
  if ( `CPerforceFileListFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CPerforceFileListFrame::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: (void **)"CPerforceFileListFrame");
    v6->pfnClassName = CPerforceFileListFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"COperationFileListFrame");
  }
  if ( `CPerforceFileListFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPerforceFileListFrame::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CPerforceFileListFrame");
    v7->pfnClassName = CPerforceFileListFrame::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "COperationFileListFrame");
  }
  if ( `CPerforceFileListFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPerforceFileListFrame::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CPerforceFileListFrame");
    v8->pfnClassName = CPerforceFileListFrame::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"COperationFileListFrame");
  }
  this->m_OpenedFiles.m_Memory.m_pMemory = nullptr;
  this->m_OpenedFiles.m_Memory.m_nAllocationCount = 0;
  this->m_OpenedFiles.m_Memory.m_nGrowSize = 0;
  this->m_OpenedFiles.m_Size = 0;
  this->m_OpenedFiles.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_LastOpenedFilePathId);
  this->m_Action = action;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102DEF20
// Name: public: virtual struct PanelAnimationMap __near * CPerforceFileListFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPerforceFileListFrame::GetAnimMap(CPerforceFileListFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CPerforceFileListFrame");
}

//------------------------------------------------------------------------------
// Address: 0x102DEF30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPerforceFileListFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPerforceFileListFrame::GetKBMap(CPerforceFileListFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPerforceFileListFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPerforceFileListFrame::GetKBMap'::`2'::s_pMap;
  `CPerforceFileListFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CPerforceFileListFrame");
  `CPerforceFileListFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DEF60
// Name: public: virtual CPerforceFileListFrame::~CPerforceFileListFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::~CPerforceFileListFrame(CPerforceFileListFrame *this)
{
  bool v2; // sf

  this->__vftable = (CPerforceFileListFrame_vtbl *)&CPerforceFileListFrame::`vftable';
  v2 = this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_LastOpenedFilePathId.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_pMemory);
      this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_OpenedFiles);
  COperationFileListFrame::~COperationFileListFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x102DEFC0
// Name: void ShowPerforceQuery(class vgui::Panel __near *,char const __near *,class vgui::Panel __near *,class KeyValues __near *,enum PerforceAction_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowPerforceQuery(
        vgui::Panel *pParent,
        const char *pFileName,
        vgui::Panel *pActionSignalTarget,
        KeyValues *pKeyValues,
        const char *actionFilter)
{
  PerforceAction_t v5; // esi
  const char *v6; // edi
  CPerforceFileListFrame *v7; // eax
  CPerforceFileListFrame *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // edi
  vgui::IVGui *v11; // esi
  vgui::IVGui_vtbl *v12; // ebx
  int v13; // eax

  p4->RefreshActiveClient(this: p4);
  if ( p4->IsFileInPerforce(this: p4, a2: pFileName) )
  {
    if ( p4->GetFileState(this: p4, a2: pFileName) != P4FILE_UNOPENED )
      goto LABEL_13;
    v5 = PERFORCE_ACTION_FILE_EDIT;
    v6 = "Check Out File from Perforce?";
  }
  else
  {
    v5 = PERFORCE_ACTION_FILE_ADD;
    v6 = "Add File to Perforce?";
  }
  if ( actionFilter == (const char *)-1 || actionFilter == (const char *)v5 )
  {
    v7 = (CPerforceFileListFrame *)MemAlloc_Alloc(nSize: 0x26Cu);
    if ( v7 != nullptr )
      v8 = CPerforceFileListFrame::CPerforceFileListFrame(
             this: v7,
             pParent,
             pTitle: v6,
             pColumnHeader: "File",
             action: v5);
    else
      v8 = nullptr;
    CPerforceFileListFrame::AddFile(this: v8, pFullPath: pFileName);
    if ( pActionSignalTarget != nullptr )
      v8->AddActionSignalTarget_2(this: v8, a2: pActionSignalTarget);
    COperationFileListFrame::DoModal(
      this: v8,
      pContextKeyValues: pKeyValues,
      pMessage: (__m128i *)"PerforceQueryCompleted");
    return;
  }
LABEL_13:
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(
            this: v9,
            setName: "PerforceQueryCompleted",
            firstKey: "operationPerformed",
            firstValue: 1);
  else
    v10 = nullptr;
  if ( pKeyValues != nullptr )
    KeyValues::AddSubKey(this: v10, pSubkey: pKeyValues);
  v11 = g_pVGui;
  v12 = g_pVGui->__vftable;
  v13 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))pActionSignalTarget->GetVPanel)(
          a1: pActionSignalTarget,
          a2: v10,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v12->PostMessage)(a1: v11, a2: v13);
}

//------------------------------------------------------------------------------
// Address: 0x10311BB0
// Name: _dynamic_initializer_for__force_audio_english__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__force_audio_english__()
{
  ConVar::ConVar(
    this: &force_audio_english,
    pName: "force_audio_english",
    pDefaultValue: "0",
    flags: 16777344,
    pHelpString: "Keeps track of whether we're forcing english in a localized language.");
  return atexit(func: dynamic_atexit_destructor_for__force_audio_english__);
}

//------------------------------------------------------------------------------
// Address: 0x10321740
// Name: _dynamic_atexit_destructor_for__force_audio_english__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__force_audio_english__()
{
  ConVar::~ConVar(this: &force_audio_english);
}

//------------------------------------------------------------------------------
// Address: 0x10311BE0
// Name: _dynamic_initializer_for__g_ASCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ASCache__()
{
  CUtlString::CUtlString(this: &g_ASCache.m_szMODPath);
  CUtlString::CUtlString(this: &g_ASCache.m_szMapCacheBase);
  CUtlString::CUtlString(this: &g_ASCache.m_szMasterCache);
  CUtlString::CUtlString(this: &g_ASCache.m_szCurrentLanguage);
  g_ASCache.m_pMasterSoundCache = nullptr;
  g_ASCache.m_pBuildingCache = nullptr;
  g_ASCache.m_nServerCount = -1;
  return atexit(func: dynamic_atexit_destructor_for__g_ASCache__);
}

//------------------------------------------------------------------------------
// Address: 0x10321750
// Name: _MaybeReportMissingWav_::_2_::_dynamic_atexit_destructor_for__wavErrors__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl MaybeReportMissingWav_::_2_::_dynamic_atexit_destructor_for__wavErrors__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &wavErrors);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10152F00
// Name: public: virtual char const __near * COperationFileListFrame::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall COperationFileListFrame::GetDescription(COperationFileListFrame *this)
{
  return this->m_pText;
}

//------------------------------------------------------------------------------
// Address: 0x10322E60
// Name: public: static char const __near * COperationFileListFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COperationFileListFrame::GetPanelClassName()
{
  return "COperationFileListFrame";
}

//------------------------------------------------------------------------------
// Address: 0x10322E70
// Name: public: static char const __near * CPerforceFileListFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPerforceFileListFrame::GetPanelClassName()
{
  return "CPerforceFileListFrame";
}

//------------------------------------------------------------------------------
// Address: 0x10322E80
// Name: OperationSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl OperationSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *String; // esi
  const char *v4; // eax
  int result; // eax
  const char *v6; // esi
  const char *v7; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "operation", defaultValue: &var);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "operation", defaultValue: &var);
  result = _V_stricmp(s1: String, s2: v4);
  if ( result == 0 )
  {
    v6 = KeyValues::GetString(this: item1->kv, keyName: "filename", defaultValue: &var);
    v7 = KeyValues::GetString(this: item2->kv, keyName: "filename", defaultValue: &var);
    return _V_stricmp(s1: v6, s2: v7);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10322F00
// Name: FileBrowserSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl FileBrowserSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *String; // esi
  const char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "filename", defaultValue: &var);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "filename", defaultValue: &var);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10322F40
// Name: public: virtual void COperationFileListFrame::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::PerformLayout(COperationFileListFrame *this)
{
  int x; // [esp+4h] [ebp-10h] BYREF
  int w; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  if ( this->m_pSplitter != nullptr )
  {
    this->GetClientArea(this, a2: &x, a3: &y, a4: &w, a5: &h);
    vgui::Panel::SetBounds(this: this->m_pSplitter, x, y: y + 6, wide: w, tall: h - 36);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10322FA0
// Name: public: void COperationFileListFrame::AddOperation(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::AddOperation(
        COperationFileListFrame *this,
        const char *pOperation,
        const char *pFileName)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "node", firstKey: "filename", firstValue: pFileName);
  else
    v5 = nullptr;
  KeyValues::SetString(this: v5, keyName: "operation", value: pOperation);
  this->m_pFileBrowser->AddItem(this: this->m_pFileBrowser, a2: v5, a3: 0, a4: false, a5: false);
}

//------------------------------------------------------------------------------
// Address: 0x10323000
// Name: public: void COperationFileListFrame::DoModal(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::DoModal(
        COperationFileListFrame *this,
        KeyValues *pContextKeyValues,
        const char *pMessage)
{
  const char *v3; // eax
  KeyValues *m_pContextKeyValues; // ecx
  vgui::ListPanel *m_pFileBrowser; // ecx
  vgui::Button_vtbl *v7; // edi
  int v8; // eax

  v3 = pMessage;
  if ( pMessage == nullptr )
    v3 = "OperationConfirmed";
  CUtlString::operator=(this: &this->m_MessageName, src: v3);
  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  m_pFileBrowser = this->m_pFileBrowser;
  this->m_pContextKeyValues = pContextKeyValues;
  m_pFileBrowser->SortList(this: m_pFileBrowser);
  if ( this->m_pNoButton->IsVisible(this: this->m_pNoButton) )
  {
    v7 = this->m_pYesButton->__vftable;
    v8 = this->m_pFileBrowser->GetItemCount(this: this->m_pFileBrowser);
    v7->SetEnabled(this: this->m_pYesButton, a2: v8 != 0);
  }
  vgui::Frame::DoModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x103230B0
// Name: public: virtual void COperationFileListFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::OnCommand(COperationFileListFrame *this, const char *pCommand)
{
  vgui::TextEntry *m_pDescription; // ecx
  unsigned int v4; // edi
  char *v5; // eax
  vgui::TextEntry *v6; // ecx
  KeyValues *v7; // edi
  const char *v8; // eax
  KeyValues *v9; // edi
  KeyValues *v10; // edi
  const char *v11; // eax
  KeyValues *v12; // edi
  const char *v13; // eax

  if ( _V_stricmp(s1: pCommand, s2: "Yes") == 0 )
  {
    m_pDescription = this->m_pDescription;
    if ( m_pDescription != nullptr )
    {
      v4 = m_pDescription->GetTextLength(this: m_pDescription) + 1;
      v5 = (char *)operator new(nSize: v4);
      v6 = this->m_pDescription;
      this->m_pText = v5;
      v6->GetText_2(this: v6, a2: v5, a3: v4);
    }
    if ( this->PerformOperation(this) )
    {
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
      {
        v8 = CUtlString::operator char const *(this: &this->m_MessageName);
        v9 = KeyValues::KeyValues(this: v7, setName: v8, firstKey: "operationPerformed", firstValue: 1);
        goto LABEL_10;
      }
    }
    else
    {
      v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v10 != nullptr )
      {
        v11 = CUtlString::operator char const *(this: &this->m_MessageName);
        v9 = KeyValues::KeyValues(this: v10, setName: v11, firstKey: "operationPerformed", firstValue: 0);
        goto LABEL_10;
      }
    }
    v9 = nullptr;
LABEL_10:
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v9, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
LABEL_12:
    this->CloseModal(this);
    this->PostActionSignal(this, a2: v9);
    return;
  }
  if ( _V_stricmp(s1: pCommand, s2: "No") == 0 )
  {
    v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v12 != nullptr )
    {
      v13 = CUtlString::operator char const *(this: &this->m_MessageName);
      v9 = KeyValues::KeyValues(this: v12, setName: v13, firstKey: "operationPerformed", firstValue: 0);
    }
    else
    {
      v9 = nullptr;
    }
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v9, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    goto LABEL_12;
  }
  vgui::Frame::OnCommand(this, command: pCommand);
}

//------------------------------------------------------------------------------
// Address: 0x10323240
// Name: public: void CPerforceFileListFrame::DoModal(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::DoModal(
        CPerforceFileListFrame *this,
        KeyValues *pContextKeys,
        const char *pMessage)
{
  const char *v3; // eax

  v3 = pMessage;
  if ( pMessage == nullptr )
    v3 = "PerforceActionConfirmed";
  COperationFileListFrame::DoModal(this, pContextKeyValues: pContextKeys, pMessage: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10323260
// Name: private: void CPerforceFileListFrame::AddFileForOpen(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::AddFileForOpen(CPerforceFileListFrame *this, const char *pFullPath)
{
  bool v3; // bl
  bool v4; // zf
  PerforceAction_t m_Action; // eax
  __int32 v6; // eax

  v3 = p4->IsFileInPerforce(this: p4, a2: pFullPath);
  v4 = p4->GetFileState(this: p4, a2: pFullPath) == P4FILE_UNOPENED;
  m_Action = this->m_Action;
  if ( m_Action != PERFORCE_ACTION_FILE_ADD )
  {
    v6 = m_Action - 1;
    if ( v6 != 0 )
    {
      if ( v6 == 1 && v3 && v4 )
        COperationFileListFrame::AddOperation(this, pOperation: "Delete", pFileName: pFullPath);
    }
    else if ( v3 && v4 )
    {
      COperationFileListFrame::AddOperation(this, pOperation: "Edit", pFileName: pFullPath);
    }
  }
  else if ( !v3 && v4 )
  {
    COperationFileListFrame::AddOperation(this, pOperation: "Add", pFileName: pFullPath);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10323300
// Name: private: void CPerforceFileListFrame::AddFileForSubmit(char const __near *,enum P4FileState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::AddFileForSubmit(
        CPerforceFileListFrame *this,
        const char *pFullPath,
        P4FileState_t state)
{
  const char *v4; // eax
  char pBuf[128]; // [esp+4h] [ebp-80h] BYREF

  if ( state != P4FILE_UNOPENED )
  {
    v4 = "Revert";
    if ( this->m_Action != PERFORCE_ACTION_FILE_REVERT )
      v4 = "Submit";
    switch ( state )
    {
      case P4FILE_OPENED_FOR_ADD:
        V_snprintf(pDest: pBuf, maxLen: 128, pFormat: "%s Add", v4);
        goto LABEL_9;
      case P4FILE_OPENED_FOR_EDIT:
        V_snprintf(pDest: pBuf, maxLen: 128, pFormat: "%s Edit", v4);
        goto LABEL_9;
      case P4FILE_OPENED_FOR_DELETE:
        V_snprintf(pDest: pBuf, maxLen: 128, pFormat: "%s Delete", v4);
        goto LABEL_9;
      case P4FILE_OPENED_FOR_INTEGRATE:
        V_snprintf(pDest: pBuf, maxLen: 128, pFormat: "%s Integrate", v4);
LABEL_9:
        COperationFileListFrame::AddOperation(this, pOperation: pBuf, pFileName: pFullPath);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10323390
// Name: public: void CPerforceFileListFrame::AddFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::AddFile(CPerforceFileListFrame *this, const char *pFullPath)
{
  bool (__thiscall *FileExists)(IBaseFileSystem *, const char *, const char *); // edx
  IBaseFileSystem *v4; // ecx
  bool v5; // bl
  P4FileState_t v6; // eax

  FileExists = g_pFullFileSystem->FileExists;
  v4 = &g_pFullFileSystem->IBaseFileSystem;
  if ( this->m_Action >= PERFORCE_ACTION_FILE_REVERT )
  {
    v5 = FileExists(this: v4, a2: pFullPath, a3: nullptr);
    v6 = p4->GetFileState(this: p4, a2: pFullPath);
    if ( v5 || v6 == P4FILE_OPENED_FOR_DELETE )
      CPerforceFileListFrame::AddFileForSubmit(this, pFullPath, state: v6);
  }
  else if ( FileExists(this: v4, a2: pFullPath, a3: nullptr) )
  {
    CPerforceFileListFrame::AddFileForOpen(this, pFullPath);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10323400
// Name: private: virtual bool CPerforceFileListFrame::PerformOperation(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPerforceFileListFrame::PerformOperation(CPerforceFileListFrame *this)
{
  int v2; // ebx
  void *v3; // esp
  const char **v4; // eax
  int v5; // esi
  int v6; // eax
  KeyValues *v7; // eax
  const char *String; // eax
  const char **v9; // ecx
  PerforceAction_t m_Action; // ecx
  char v11; // al
  const char *v12; // ebx
  vgui::MessageBox *v13; // esi
  vgui::Panel *v14; // eax
  vgui::MessageBox *v15; // esi
  const char *v16; // eax
  const char *v17; // esi
  vgui::MessageBox *v18; // esi
  vgui::Panel *v19; // eax
  vgui::MessageBox *v20; // esi
  _BYTE v22[12]; // [esp+0h] [ebp-14h] BYREF
  const char **ppFileNames; // [esp+Ch] [ebp-8h]
  bool bSuccess; // [esp+13h] [ebp-1h]

  v2 = this->m_pFileBrowser->GetItemCount(this: this->m_pFileBrowser);
  v3 = alloca(4 * v2);
  v4 = (const char **)v22;
  v5 = 0;
  ppFileNames = (const char **)v22;
  if ( v2 > 0 )
  {
    do
    {
      v6 = this->m_pFileBrowser->GetItemIDFromRow(this: this->m_pFileBrowser, a2: v5);
      v7 = this->m_pFileBrowser->GetItem(this: this->m_pFileBrowser, a2: v6);
      String = KeyValues::GetString(this: v7, keyName: "filename", defaultValue: &var);
      v9 = ppFileNames;
      ppFileNames[v5++] = String;
    }
    while ( v5 < v2 );
    v4 = v9;
  }
  m_Action = this->m_Action;
  bSuccess = false;
  switch ( m_Action )
  {
    case PERFORCE_ACTION_FILE_ADD:
      v11 = ((int (__stdcall *)(int, const char **))p4->OpenFilesForAdd)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_EDIT:
      v11 = ((int (__stdcall *)(int, const char **))p4->OpenFilesForEdit)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_DELETE:
      v11 = ((int (__stdcall *)(int, const char **))p4->OpenFilesForDelete)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_REVERT:
      v11 = ((int (__stdcall *)(int, const char **))p4->RevertFiles)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_SUBMIT:
      v16 = this->GetDescription(this);
      v17 = v16;
      if ( *v16 != 0 && _V_stricmp(s1: v16, s2: "<enter description here>") != 0 )
      {
        v11 = p4->SubmitFiles(this: p4, a2: v2, a3: ppFileNames, a4: v17);
LABEL_6:
        bSuccess = v11;
LABEL_7:
        v12 = p4->GetLastError(this: p4);
        if ( !bSuccess )
        {
          v13 = (vgui::MessageBox *)operator new(nSize: 0x234u);
          if ( v13 != nullptr )
          {
            v14 = this->GetParent(this);
            v15 = vgui::MessageBox::MessageBox(this: v13, title: "Perforce Error!", text: v12, parent: v14);
          }
          else
          {
            v15 = nullptr;
          }
          v15->SetSmallCaption(this: v15, a2: true);
          v15->DoModal_2(this: v15, a2: nullptr);
        }
        return bSuccess;
      }
      else
      {
        v18 = (vgui::MessageBox *)operator new(nSize: 0x234u);
        if ( v18 != nullptr )
        {
          v19 = this->GetParent(this);
          v20 = vgui::MessageBox::MessageBox(
                  this: v18,
                  title: "Submission Error!",
                  text: "Description required for submission.",
                  parent: v19);
        }
        else
        {
          v20 = nullptr;
        }
        v20->SetSmallCaption(this: v20, a2: true);
        v20->DoModal_2(this: v20, a2: nullptr);
        return false;
      }
    default:
      goto LABEL_7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10323610
// Name: public: COperationFileListFrame::COperationFileListFrame(class vgui::Panel __near *,char const __near *,char const __near *,bool,bool,int)
// Source: json
//------------------------------------------------------------------------------
COperationFileListFrame *__thiscall COperationFileListFrame::COperationFileListFrame(
        COperationFileListFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        const char *pColumnHeader,
        bool bShowDescription,
        bool bShowOkOnly,
        int nDialogID)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  COperationFileListFrame *Child; // ebx
  vgui::Splitter *v12; // eax
  vgui::Splitter *v13; // eax
  vgui::Panel *v14; // edi
  vgui::TextEntry *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::ListPanel *v17; // eax
  vgui::ListPanel *v18; // eax
  vgui::Button *v19; // eax
  vgui::Button *v20; // eax
  vgui::Button *v21; // eax
  vgui::Button *v22; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "PerforceFileList", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (COperationFileListFrame_vtbl *)&COperationFileListFrame::`vftable';
  if ( `COperationFileListFrame::ChainToMap'::`2'::chained == 0 )
  {
    `COperationFileListFrame::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "COperationFileListFrame");
    v8->pfnClassName = COperationFileListFrame::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `COperationFileListFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COperationFileListFrame::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "COperationFileListFrame");
    v9->pfnClassName = COperationFileListFrame::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `COperationFileListFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COperationFileListFrame::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "COperationFileListFrame");
    v10->pfnClassName = COperationFileListFrame::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CUtlString::CUtlString(this: &this->m_MessageName);
  this->m_pText = nullptr;
  Child = this;
  this->m_pDescription = nullptr;
  this->m_pSplitter = nullptr;
  if ( bShowDescription )
  {
    v12 = (vgui::Splitter *)operator new(nSize: 0x198u);
    if ( v12 != nullptr )
      v13 = vgui::Splitter::Splitter(
              this: v12,
              parent: this,
              name: "Splitter",
              mode: SPLITTER_MODE_HORIZONTAL,
              nCount: 1);
    else
      v13 = nullptr;
    this->m_pSplitter = v13;
    Child = (COperationFileListFrame *)vgui::Panel::GetChild(this: v13, index: 0);
    v14 = vgui::Panel::GetChild(this: this->m_pSplitter, index: 1);
    v15 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
    if ( v15 != nullptr )
      v16 = vgui::TextEntry::TextEntry(this: v15, parent: v14, panelName: "Description");
    else
      v16 = nullptr;
    this->m_pDescription = v16;
    v16->SetMultiline(this: v16, a2: true);
    this->m_pDescription->SetCatchEnterKey(this: this->m_pDescription, a2: true);
    this->m_pDescription->SetText(this: this->m_pDescription, a2: "<enter description here>");
  }
  v17 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v17 != nullptr )
    v18 = vgui::ListPanel::ListPanel(this: v17, parent: Child, panelName: "Browser");
  else
    v18 = nullptr;
  this->m_pFileBrowser = v18;
  v18->AddColumnHeader(this: v18, a2: 0, a3: "operation", a4: "Operation", a5: 52, a6: 0);
  this->m_pFileBrowser->AddColumnHeader(
    this: this->m_pFileBrowser,
    a2: 1,
    a3: "filename",
    a4: pColumnHeader,
    a5: 128,
    a6: 2);
  this->m_pFileBrowser->SetSelectIndividualCells(this: this->m_pFileBrowser, a2: false);
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pFileBrowser, bState: false);
  this->m_pFileBrowser->SetEmptyListText_2(this: this->m_pFileBrowser, a2: "No Perforce Operations");
  this->m_pFileBrowser->SetDragEnabled(this: this->m_pFileBrowser, a2: true);
  this->m_pFileBrowser->AddActionSignalTarget_2(this: this->m_pFileBrowser, a2: this);
  this->m_pFileBrowser->SetSortFunc(this: this->m_pFileBrowser, a2: 0, a3: OperationSortFunc);
  this->m_pFileBrowser->SetSortFunc(this: this->m_pFileBrowser, a2: 1, a3: FileBrowserSortFunc);
  this->m_pFileBrowser->SetSortColumn(this: this->m_pFileBrowser, a2: 0);
  v19 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v19 != nullptr )
    v20 = vgui::Button::Button(
            this: v19,
            parent: this,
            panelName: "YesButton",
            text: "Yes",
            pActionSignalTarget: this,
            pCmd: "Yes");
  else
    v20 = nullptr;
  this->m_pYesButton = v20;
  v21 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v21 != nullptr )
    v22 = vgui::Button::Button(
            this: v21,
            parent: this,
            panelName: "NoButton",
            text: "No",
            pActionSignalTarget: this,
            pCmd: "No");
  else
    v22 = nullptr;
  this->m_pNoButton = v22;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  if ( bShowDescription )
    vgui::EditablePanel::LoadControlSettingsAndUserConfig(
      this,
      dialogResourceName: "resource/perforcefilelistdescription.res",
      dialogID: nDialogID);
  else
    vgui::EditablePanel::LoadControlSettingsAndUserConfig(
      this,
      dialogResourceName: "resource/perforcefilelist.res",
      dialogID: nDialogID);
  if ( bShowOkOnly )
  {
    this->m_pYesButton->SetText(this: this->m_pYesButton, a2: "#MessageBox_OK");
    this->m_pNoButton->SetVisible(this: this->m_pNoButton, a2: false);
  }
  this->m_pContextKeyValues = nullptr;
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10323970
// Name: public: virtual struct vgui::PanelMessageMap __near * COperationFileListFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COperationFileListFrame::GetMessageMap(COperationFileListFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COperationFileListFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COperationFileListFrame::GetMessageMap'::`2'::s_pMap;
  `COperationFileListFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COperationFileListFrame");
  `COperationFileListFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103239A0
// Name: public: virtual struct PanelAnimationMap __near * COperationFileListFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COperationFileListFrame::GetAnimMap(COperationFileListFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "COperationFileListFrame");
}

//------------------------------------------------------------------------------
// Address: 0x103239B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COperationFileListFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COperationFileListFrame::GetKBMap(COperationFileListFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COperationFileListFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COperationFileListFrame::GetKBMap'::`2'::s_pMap;
  `COperationFileListFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COperationFileListFrame");
  `COperationFileListFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103239E0
// Name: public: virtual COperationFileListFrame::~COperationFileListFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::~COperationFileListFrame(COperationFileListFrame *this)
{
  KeyValues *m_pContextKeyValues; // ecx

  this->__vftable = (COperationFileListFrame_vtbl *)&COperationFileListFrame::`vftable';
  vgui::EditablePanel::SaveUserConfig(this);
  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  if ( this->m_pText != nullptr )
    operator delete(p: this->m_pText);
  this->m_MessageName.m_Storage.m_nActualLength = 0;
  if ( this->m_MessageName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_MessageName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_MessageName.m_Storage.m_Memory.m_pMemory);
      this->m_MessageName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_MessageName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x10323A90
// Name: public: CPerforceFileListFrame::CPerforceFileListFrame(class vgui::Panel __near *,char const __near *,char const __near *,enum PerforceAction_t)
// Source: json
//------------------------------------------------------------------------------
CPerforceFileListFrame *__thiscall CPerforceFileListFrame::CPerforceFileListFrame(
        CPerforceFileListFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        const char *pColumnHeader,
        PerforceAction_t action)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  COperationFileListFrame::COperationFileListFrame(
    this,
    pParent,
    pTitle,
    pColumnHeader,
    bShowDescription: action == PERFORCE_ACTION_FILE_SUBMIT,
    bShowOkOnly: false,
    nDialogID: 0);
  this->__vftable = (CPerforceFileListFrame_vtbl *)&CPerforceFileListFrame::`vftable';
  if ( `CPerforceFileListFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CPerforceFileListFrame::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CPerforceFileListFrame");
    v6->pfnClassName = CPerforceFileListFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "COperationFileListFrame");
  }
  if ( `CPerforceFileListFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPerforceFileListFrame::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CPerforceFileListFrame");
    v7->pfnClassName = CPerforceFileListFrame::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "COperationFileListFrame");
  }
  if ( `CPerforceFileListFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPerforceFileListFrame::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CPerforceFileListFrame");
    v8->pfnClassName = CPerforceFileListFrame::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "COperationFileListFrame");
  }
  this->m_OpenedFiles.m_Memory.m_pMemory = nullptr;
  this->m_OpenedFiles.m_Memory.m_nAllocationCount = 0;
  this->m_OpenedFiles.m_Memory.m_nGrowSize = 0;
  this->m_OpenedFiles.m_Size = 0;
  this->m_OpenedFiles.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_LastOpenedFilePathId);
  this->m_Action = action;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10323BA0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPerforceFileListFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPerforceFileListFrame::GetMessageMap(CPerforceFileListFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPerforceFileListFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPerforceFileListFrame::GetMessageMap'::`2'::s_pMap;
  `CPerforceFileListFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPerforceFileListFrame");
  `CPerforceFileListFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10323BD0
// Name: public: virtual struct PanelAnimationMap __near * CPerforceFileListFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPerforceFileListFrame::GetAnimMap(CPerforceFileListFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CPerforceFileListFrame");
}

//------------------------------------------------------------------------------
// Address: 0x10323BE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPerforceFileListFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPerforceFileListFrame::GetKBMap(CPerforceFileListFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPerforceFileListFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPerforceFileListFrame::GetKBMap'::`2'::s_pMap;
  `CPerforceFileListFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPerforceFileListFrame");
  `CPerforceFileListFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10323C10
// Name: public: virtual CPerforceFileListFrame::~CPerforceFileListFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::~CPerforceFileListFrame(CPerforceFileListFrame *this)
{
  bool v2; // sf

  this->__vftable = (CPerforceFileListFrame_vtbl *)&CPerforceFileListFrame::`vftable';
  v2 = this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_LastOpenedFilePathId.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_pMemory);
      this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>::~CUtlVector<DetailObjects::DetailModel_t,CUtlMemory<DetailObjects::DetailModel_t,int>>(this: (CUtlVector<CAnchorDef,CUtlMemory<CAnchorDef,int> > *)&this->m_OpenedFiles);
  COperationFileListFrame::~COperationFileListFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x10323C70
// Name: void ShowPerforceQuery(class vgui::Panel __near *,char const __near *,class vgui::Panel __near *,class KeyValues __near *,enum PerforceAction_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowPerforceQuery(
        vgui::Panel *pParent,
        const char *pFileName,
        vgui::Panel *pActionSignalTarget,
        KeyValues *pKeyValues,
        const char *actionFilter)
{
  PerforceAction_t v5; // esi
  const char *v6; // edi
  CPerforceFileListFrame *v7; // eax
  CPerforceFileListFrame *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // edi
  vgui::IVGui *v11; // esi
  vgui::IVGui_vtbl *v12; // ebx
  int v13; // eax

  p4->RefreshActiveClient(this: p4);
  if ( p4->IsFileInPerforce(this: p4, a2: pFileName) )
  {
    if ( p4->GetFileState(this: p4, a2: pFileName) != P4FILE_UNOPENED )
      goto LABEL_13;
    v5 = PERFORCE_ACTION_FILE_EDIT;
    v6 = "Check Out File from Perforce?";
  }
  else
  {
    v5 = PERFORCE_ACTION_FILE_ADD;
    v6 = "Add File to Perforce?";
  }
  if ( actionFilter == (const char *)-1 || actionFilter == (const char *)v5 )
  {
    v7 = (CPerforceFileListFrame *)operator new(nSize: 0x26Cu);
    if ( v7 != nullptr )
      v8 = CPerforceFileListFrame::CPerforceFileListFrame(
             this: v7,
             pParent,
             pTitle: v6,
             pColumnHeader: "File",
             action: v5);
    else
      v8 = nullptr;
    CPerforceFileListFrame::AddFile(this: v8, pFullPath: pFileName);
    if ( pActionSignalTarget != nullptr )
      v8->AddActionSignalTarget_2(this: v8, a2: pActionSignalTarget);
    COperationFileListFrame::DoModal(this: v8, pContextKeyValues: pKeyValues, pMessage: "PerforceQueryCompleted");
    return;
  }
LABEL_13:
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(
            this: v9,
            setName: "PerforceQueryCompleted",
            firstKey: "operationPerformed",
            firstValue: 1);
  else
    v10 = nullptr;
  if ( pKeyValues != nullptr )
    KeyValues::AddSubKey(this: v10, pSubkey: pKeyValues);
  v11 = g_pVGui;
  v12 = g_pVGui->__vftable;
  v13 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))pActionSignalTarget->GetVPanel)(
          a1: pActionSignalTarget,
          a2: v10,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v12->PostMessage)(a1: v11, a2: v13);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00662F40
// Name: public: static char const __near * COperationFileListFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COperationFileListFrame::GetPanelClassName()
{
  return "COperationFileListFrame";
}

//------------------------------------------------------------------------------
// Address: 0x00662F50
// Name: public: static char const __near * CPerforceFileListFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPerforceFileListFrame::GetPanelClassName()
{
  return "CPerforceFileListFrame";
}

//------------------------------------------------------------------------------
// Address: 0x00662F60
// Name: OperationSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl OperationSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  char *String; // esi
  char *v4; // eax
  int result; // eax
  char *v6; // esi
  char *v7; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "operation", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "operation", defaultValue: defaultValue);
  result = _V_stricmp(s1: String, s2: v4);
  if ( result == 0 )
  {
    v6 = KeyValues::GetString(this: item1->kv, keyName: "filename", defaultValue: defaultValue);
    v7 = KeyValues::GetString(this: item2->kv, keyName: "filename", defaultValue: defaultValue);
    return _V_stricmp(s1: v6, s2: v7);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00663000
// Name: FileBrowserSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl FileBrowserSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  char *String; // esi
  char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "filename", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "filename", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00663040
// Name: public: virtual void COperationFileListFrame::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::PerformLayout(COperationFileListFrame *this)
{
  int x; // [esp+4h] [ebp-10h] BYREF
  int w; // [esp+8h] [ebp-Ch] BYREF
  int h; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  if ( this->m_pSplitter != nullptr )
  {
    this->GetClientArea(this, a2: &x, a3: &y, a4: &w, a5: &h);
    vgui::Panel::SetBounds(this: this->m_pSplitter, x, y: y + 6, wide: w, tall: h - 36);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006630A0
// Name: public: void COperationFileListFrame::AddOperation(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::AddOperation(
        COperationFileListFrame *this,
        const char *pOperation,
        const char *pFileName)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "node", firstKey: "filename", firstValue: pFileName);
  else
    v5 = nullptr;
  KeyValues::SetString(this: v5, keyName: "operation", value: pOperation);
  this->m_pFileBrowser->AddItem(this: this->m_pFileBrowser, a2: v5, a3: 0, a4: false, a5: false);
}

//------------------------------------------------------------------------------
// Address: 0x00663100
// Name: public: void COperationFileListFrame::SetOperationColumnHeaderText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::SetOperationColumnHeaderText(COperationFileListFrame *this, const char *pText)
{
  this->m_pFileBrowser->SetColumnHeaderText_2(this: this->m_pFileBrowser, a2: 0, a3: pText);
}

//------------------------------------------------------------------------------
// Address: 0x00663120
// Name: public: void COperationFileListFrame::DoModal(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::DoModal(
        COperationFileListFrame *this,
        KeyValues *pContextKeyValues,
        char *pMessage)
{
  char *v3; // eax
  KeyValues *m_pContextKeyValues; // ecx
  vgui::ListPanel *m_pFileBrowser; // ecx
  vgui::Button_vtbl *v7; // edi
  int v8; // eax

  v3 = pMessage;
  if ( pMessage == nullptr )
    v3 = "OperationConfirmed";
  CUtlString::operator=(this: &this->m_MessageName, src: v3);
  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  m_pFileBrowser = this->m_pFileBrowser;
  this->m_pContextKeyValues = pContextKeyValues;
  m_pFileBrowser->SortList(this: m_pFileBrowser);
  if ( this->m_pNoButton->IsVisible(this: this->m_pNoButton) )
  {
    v7 = this->m_pYesButton->__vftable;
    v8 = this->m_pFileBrowser->GetItemCount(this: this->m_pFileBrowser);
    v7->SetEnabled(this: this->m_pYesButton, a2: v8 != 0);
  }
  vgui::Frame::DoModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x006631D0
// Name: public: virtual char const __near * COperationFileListFrame::GetDescription(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall COperationFileListFrame::GetDescription(COperationFileListFrame *this)
{
  return this->m_pText;
}

//------------------------------------------------------------------------------
// Address: 0x006631E0
// Name: public: virtual void COperationFileListFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::OnCommand(COperationFileListFrame *this, const char *pCommand)
{
  vgui::TextEntry *m_pDescription; // ecx
  unsigned int v4; // edi
  char *v5; // eax
  vgui::TextEntry *v6; // ecx
  KeyValues *v7; // edi
  const char *v8; // eax
  KeyValues *v9; // edi
  KeyValues *v10; // edi
  const char *v11; // eax
  KeyValues *v12; // edi
  const char *v13; // eax

  if ( _V_stricmp(s1: pCommand, s2: "Yes") == 0 )
  {
    m_pDescription = this->m_pDescription;
    if ( m_pDescription != nullptr )
    {
      v4 = m_pDescription->GetTextLength(this: m_pDescription) + 1;
      v5 = (char *)MemAlloc_Alloc(nSize: v4);
      v6 = this->m_pDescription;
      this->m_pText = v5;
      v6->GetText_2(this: v6, a2: v5, a3: v4);
    }
    if ( this->PerformOperation(this) )
    {
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
      {
        v8 = CUtlString::operator char const *(this: &this->m_MessageName);
        v9 = KeyValues::KeyValues(this: v7, setName: v8, firstKey: "operationPerformed", firstValue: 1);
        goto LABEL_10;
      }
    }
    else
    {
      v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v10 != nullptr )
      {
        v11 = CUtlString::operator char const *(this: &this->m_MessageName);
        v9 = KeyValues::KeyValues(this: v10, setName: v11, firstKey: "operationPerformed", firstValue: 0);
        goto LABEL_10;
      }
    }
    v9 = nullptr;
LABEL_10:
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v9, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
LABEL_12:
    this->CloseModal(this);
    this->PostActionSignal(this, a2: v9);
    return;
  }
  if ( _V_stricmp(s1: pCommand, s2: "No") == 0 )
  {
    v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v12 != nullptr )
    {
      v13 = CUtlString::operator char const *(this: &this->m_MessageName);
      v9 = KeyValues::KeyValues(this: v12, setName: v13, firstKey: "operationPerformed", firstValue: 0);
    }
    else
    {
      v9 = nullptr;
    }
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v9, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    goto LABEL_12;
  }
  vgui::Frame::OnCommand(this, command: pCommand);
}

//------------------------------------------------------------------------------
// Address: 0x00663370
// Name: private: void CPerforceFileListFrame::AddFileForOpen(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::AddFileForOpen(CPerforceFileListFrame *this, const char *pFullPath)
{
  bool v3; // bl
  bool v4; // zf
  PerforceAction_t m_Action; // eax
  __int32 v6; // eax

  v3 = p4->IsFileInPerforce(this: p4, a2: pFullPath);
  v4 = p4->GetFileState(this: p4, a2: pFullPath) == P4FILE_UNOPENED;
  m_Action = this->m_Action;
  if ( m_Action != PERFORCE_ACTION_FILE_ADD )
  {
    v6 = m_Action - 1;
    if ( v6 != 0 )
    {
      if ( v6 == 1 && v3 && v4 )
        COperationFileListFrame::AddOperation(this, pOperation: "Delete", pFileName: pFullPath);
    }
    else if ( v3 && v4 )
    {
      COperationFileListFrame::AddOperation(this, pOperation: "Edit", pFileName: pFullPath);
    }
  }
  else if ( !v3 && v4 )
  {
    COperationFileListFrame::AddOperation(this, pOperation: "Add", pFileName: pFullPath);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00663410
// Name: private: void CPerforceFileListFrame::AddFileForSubmit(char const __near *,enum P4FileState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::AddFileForSubmit(
        CPerforceFileListFrame *this,
        const char *pFullPath,
        P4FileState_t state)
{
  const char *v4; // eax
  char pBuf[128]; // [esp+4h] [ebp-80h] BYREF

  if ( state != P4FILE_UNOPENED )
  {
    v4 = "Revert";
    if ( this->m_Action != PERFORCE_ACTION_FILE_REVERT )
      v4 = "Submit";
    switch ( state )
    {
      case P4FILE_OPENED_FOR_ADD:
        V_snprintf(pDest: pBuf, maxLen: 0x80u, pFormat: "%s Add", v4);
        goto LABEL_9;
      case P4FILE_OPENED_FOR_EDIT:
        V_snprintf(pDest: pBuf, maxLen: 0x80u, pFormat: "%s Edit", v4);
        goto LABEL_9;
      case P4FILE_OPENED_FOR_DELETE:
        V_snprintf(pDest: pBuf, maxLen: 0x80u, pFormat: "%s Delete", v4);
        goto LABEL_9;
      case P4FILE_OPENED_FOR_INTEGRATE:
        V_snprintf(pDest: pBuf, maxLen: 0x80u, pFormat: "%s Integrate", v4);
LABEL_9:
        COperationFileListFrame::AddOperation(this, pOperation: pBuf, pFileName: pFullPath);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006634A0
// Name: public: void CPerforceFileListFrame::AddFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::AddFile(CPerforceFileListFrame *this, const char *pFullPath)
{
  bool (__thiscall *FileExists)(IBaseFileSystem *, const char *, const char *); // edx
  IBaseFileSystem *v4; // ecx
  bool v5; // bl
  P4FileState_t v6; // eax

  FileExists = g_pFullFileSystem->FileExists;
  v4 = &g_pFullFileSystem->IBaseFileSystem;
  if ( this->m_Action >= PERFORCE_ACTION_FILE_REVERT )
  {
    v5 = FileExists(this: v4, a2: pFullPath, a3: nullptr);
    v6 = p4->GetFileState(this: p4, a2: pFullPath);
    if ( v5 || v6 == P4FILE_OPENED_FOR_DELETE )
      CPerforceFileListFrame::AddFileForSubmit(this, pFullPath, state: v6);
  }
  else if ( FileExists(this: v4, a2: pFullPath, a3: nullptr) )
  {
    CPerforceFileListFrame::AddFileForOpen(this, pFullPath);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00663510
// Name: private: virtual bool CPerforceFileListFrame::PerformOperation(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPerforceFileListFrame::PerformOperation(CPerforceFileListFrame *this)
{
  int v2; // ebx
  void *v3; // esp
  const char **v4; // eax
  int v5; // esi
  int v6; // eax
  KeyValues *v7; // eax
  char *String; // eax
  const char **v9; // ecx
  PerforceAction_t m_Action; // ecx
  char v11; // al
  const char *v12; // ebx
  vgui::MessageBox *v13; // esi
  vgui::Panel *v14; // eax
  vgui::MessageBox *v15; // esi
  const char *v16; // eax
  const char *v17; // esi
  vgui::MessageBox *v18; // esi
  vgui::Panel *v19; // eax
  vgui::MessageBox *v20; // esi
  _BYTE v22[12]; // [esp+0h] [ebp-14h] BYREF
  const char **ppFileNames; // [esp+Ch] [ebp-8h]
  bool bSuccess; // [esp+13h] [ebp-1h]

  v2 = this->m_pFileBrowser->GetItemCount(this: this->m_pFileBrowser);
  v3 = alloca(4 * v2);
  v4 = (const char **)v22;
  v5 = 0;
  ppFileNames = (const char **)v22;
  if ( v2 > 0 )
  {
    do
    {
      v6 = this->m_pFileBrowser->GetItemIDFromRow(this: this->m_pFileBrowser, a2: v5);
      v7 = this->m_pFileBrowser->GetItem(this: this->m_pFileBrowser, a2: v6);
      String = KeyValues::GetString(this: v7, keyName: "filename", defaultValue: defaultValue);
      v9 = ppFileNames;
      ppFileNames[v5++] = String;
    }
    while ( v5 < v2 );
    v4 = v9;
  }
  m_Action = this->m_Action;
  bSuccess = false;
  switch ( m_Action )
  {
    case PERFORCE_ACTION_FILE_ADD:
      v11 = ((int (__stdcall *)(int, const char **))p4->OpenFilesForAdd)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_EDIT:
      v11 = ((int (__stdcall *)(int, const char **))p4->OpenFilesForEdit)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_DELETE:
      v11 = ((int (__stdcall *)(int, const char **))p4->OpenFilesForDelete)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_REVERT:
      v11 = ((int (__stdcall *)(int, const char **))p4->RevertFiles)(a1: v2, a2: v4);
      goto LABEL_6;
    case PERFORCE_ACTION_FILE_SUBMIT:
      v16 = this->GetDescription(this);
      v17 = v16;
      if ( *v16 != 0 && _V_stricmp(s1: v16, s2: "<enter description here>") != 0 )
      {
        v11 = p4->SubmitFiles(this: p4, a2: v2, a3: ppFileNames, a4: v17);
LABEL_6:
        bSuccess = v11;
LABEL_7:
        v12 = p4->GetLastError(this: p4);
        if ( !bSuccess )
        {
          v13 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
          if ( v13 != nullptr )
          {
            v14 = this->GetParent(this);
            v15 = vgui::MessageBox::MessageBox(this: v13, title: "Perforce Error!", text: v12, parent: v14);
          }
          else
          {
            v15 = nullptr;
          }
          v15->SetSmallCaption(this: v15, a2: true);
          v15->DoModal_2(this: v15, a2: nullptr);
        }
        return bSuccess;
      }
      else
      {
        v18 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
        if ( v18 != nullptr )
        {
          v19 = this->GetParent(this);
          v20 = vgui::MessageBox::MessageBox(
                  this: v18,
                  title: "Submission Error!",
                  text: "Description required for submission.",
                  parent: v19);
        }
        else
        {
          v20 = nullptr;
        }
        v20->SetSmallCaption(this: v20, a2: true);
        v20->DoModal_2(this: v20, a2: nullptr);
        return false;
      }
    default:
      goto LABEL_7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00663720
// Name: public: COperationFileListFrame::COperationFileListFrame(class vgui::Panel __near *,char const __near *,char const __near *,bool,bool,int)
// Source: json
//------------------------------------------------------------------------------
COperationFileListFrame *__thiscall COperationFileListFrame::COperationFileListFrame(
        COperationFileListFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        const char *pColumnHeader,
        bool bShowDescription,
        bool bShowOkOnly,
        int nDialogID)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  COperationFileListFrame *Child; // ebx
  vgui::Splitter *v12; // eax
  vgui::Splitter *v13; // eax
  vgui::Panel *v14; // edi
  vgui::TextEntry *v15; // eax
  vgui::TextEntry *v16; // eax
  vgui::ListPanel *v17; // eax
  vgui::ListPanel *v18; // eax
  vgui::Button *v19; // eax
  vgui::Button *v20; // eax
  vgui::Button *v21; // eax
  vgui::Button *v22; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "PerforceFileList", showTaskbarIcon: 1, bPopup: true);
  this->__vftable = (COperationFileListFrame_vtbl *)&COperationFileListFrame::`vftable';
  if ( `COperationFileListFrame::ChainToMap'::`2'::chained == 0 )
  {
    `COperationFileListFrame::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "COperationFileListFrame");
    v8->pfnClassName = COperationFileListFrame::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `COperationFileListFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COperationFileListFrame::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "COperationFileListFrame");
    v9->pfnClassName = COperationFileListFrame::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `COperationFileListFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COperationFileListFrame::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "COperationFileListFrame");
    v10->pfnClassName = COperationFileListFrame::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CUtlString::CUtlString(this: &this->m_MessageName);
  this->m_pText = nullptr;
  Child = this;
  this->m_pDescription = nullptr;
  this->m_pSplitter = nullptr;
  if ( bShowDescription )
  {
    v12 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
    if ( v12 != nullptr )
      v13 = vgui::Splitter::Splitter(
              this: v12,
              parent: this,
              name: "Splitter",
              mode: SPLITTER_MODE_HORIZONTAL,
              nCount: 1);
    else
      v13 = nullptr;
    this->m_pSplitter = v13;
    Child = (COperationFileListFrame *)vgui::Panel::GetChild(this: v13, index: 0);
    v14 = vgui::Panel::GetChild(this: this->m_pSplitter, index: 1);
    v15 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
    if ( v15 != nullptr )
      v16 = vgui::TextEntry::TextEntry(this: v15, parent: v14, panelName: "Description");
    else
      v16 = nullptr;
    this->m_pDescription = v16;
    v16->SetMultiline(this: v16, a2: true);
    this->m_pDescription->SetCatchEnterKey(this: this->m_pDescription, a2: true);
    this->m_pDescription->SetText(this: this->m_pDescription, a2: "<enter description here>");
  }
  v17 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v17 != nullptr )
    v18 = vgui::ListPanel::ListPanel(this: v17, parent: Child, panelName: "Browser");
  else
    v18 = nullptr;
  this->m_pFileBrowser = v18;
  v18->AddColumnHeader(this: v18, a2: 0, a3: "operation", a4: "Operation", a5: 52, a6: 0);
  this->m_pFileBrowser->AddColumnHeader(
    this: this->m_pFileBrowser,
    a2: 1,
    a3: "filename",
    a4: pColumnHeader,
    a5: 128,
    a6: 2);
  this->m_pFileBrowser->SetSelectIndividualCells(this: this->m_pFileBrowser, a2: false);
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pFileBrowser, bState: false);
  this->m_pFileBrowser->SetEmptyListText_2(this: this->m_pFileBrowser, a2: "No Perforce Operations");
  this->m_pFileBrowser->SetDragEnabled(this: this->m_pFileBrowser, a2: true);
  this->m_pFileBrowser->AddActionSignalTarget_2(this: this->m_pFileBrowser, a2: this);
  this->m_pFileBrowser->SetSortFunc(this: this->m_pFileBrowser, a2: 0, a3: OperationSortFunc);
  this->m_pFileBrowser->SetSortFunc(this: this->m_pFileBrowser, a2: 1, a3: FileBrowserSortFunc);
  this->m_pFileBrowser->SetSortColumn(this: this->m_pFileBrowser, a2: 0);
  v19 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v19 != nullptr )
    v20 = vgui::Button::Button(
            this: v19,
            parent: this,
            panelName: "YesButton",
            text: "Yes",
            pActionSignalTarget: this,
            pCmd: "Yes");
  else
    v20 = nullptr;
  this->m_pYesButton = v20;
  v21 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v21 != nullptr )
    v22 = vgui::Button::Button(
            this: v21,
            parent: this,
            panelName: "NoButton",
            text: "No",
            pActionSignalTarget: this,
            pCmd: "No");
  else
    v22 = nullptr;
  this->m_pNoButton = v22;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  if ( bShowDescription )
    vgui::EditablePanel::LoadControlSettingsAndUserConfig(
      this,
      dialogResourceName: "resource/perforcefilelistdescription.res",
      dialogID: nDialogID);
  else
    vgui::EditablePanel::LoadControlSettingsAndUserConfig(
      this,
      dialogResourceName: "resource/perforcefilelist.res",
      dialogID: nDialogID);
  if ( bShowOkOnly )
  {
    this->m_pYesButton->SetText_2(this: this->m_pYesButton, a2: "#MessageBox_OK");
    this->m_pNoButton->SetVisible(this: this->m_pNoButton, a2: false);
  }
  this->m_pContextKeyValues = nullptr;
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00663A80
// Name: public: virtual struct vgui::PanelMessageMap __near * COperationFileListFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COperationFileListFrame::GetMessageMap(COperationFileListFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COperationFileListFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COperationFileListFrame::GetMessageMap'::`2'::s_pMap;
  `COperationFileListFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COperationFileListFrame");
  `COperationFileListFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00663AB0
// Name: public: virtual struct PanelAnimationMap __near * COperationFileListFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COperationFileListFrame::GetAnimMap(COperationFileListFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "COperationFileListFrame");
}

//------------------------------------------------------------------------------
// Address: 0x00663AC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COperationFileListFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COperationFileListFrame::GetKBMap(COperationFileListFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COperationFileListFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COperationFileListFrame::GetKBMap'::`2'::s_pMap;
  `COperationFileListFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COperationFileListFrame");
  `COperationFileListFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00663AF0
// Name: public: virtual COperationFileListFrame::~COperationFileListFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationFileListFrame::~COperationFileListFrame(COperationFileListFrame *this)
{
  KeyValues *m_pContextKeyValues; // ecx

  this->__vftable = (COperationFileListFrame_vtbl *)&COperationFileListFrame::`vftable';
  vgui::EditablePanel::SaveUserConfig(this);
  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  if ( this->m_pText != nullptr )
    free(pMem: this->m_pText);
  this->m_MessageName.m_Storage.m_nActualLength = 0;
  if ( this->m_MessageName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_MessageName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_MessageName.m_Storage.m_Memory.m_pMemory);
      this->m_MessageName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_MessageName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x00663BA0
// Name: public: CPerforceFileListFrame::CPerforceFileListFrame(class vgui::Panel __near *,char const __near *,char const __near *,enum PerforceAction_t)
// Source: json
//------------------------------------------------------------------------------
CPerforceFileListFrame *__thiscall CPerforceFileListFrame::CPerforceFileListFrame(
        CPerforceFileListFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        const char *pColumnHeader,
        PerforceAction_t action)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi

  COperationFileListFrame::COperationFileListFrame(
    this,
    pParent,
    pTitle,
    pColumnHeader,
    bShowDescription: action == PERFORCE_ACTION_FILE_SUBMIT,
    bShowOkOnly: false,
    nDialogID: 0);
  this->__vftable = (CPerforceFileListFrame_vtbl *)&CPerforceFileListFrame::`vftable';
  if ( `CPerforceFileListFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CPerforceFileListFrame::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CPerforceFileListFrame");
    v6->pfnClassName = CPerforceFileListFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "COperationFileListFrame");
  }
  if ( `CPerforceFileListFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPerforceFileListFrame::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CPerforceFileListFrame");
    v7->pfnClassName = CPerforceFileListFrame::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "COperationFileListFrame");
  }
  if ( `CPerforceFileListFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPerforceFileListFrame::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CPerforceFileListFrame");
    v8->pfnClassName = CPerforceFileListFrame::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "COperationFileListFrame");
  }
  this->m_OpenedFiles.m_Memory.m_pMemory = nullptr;
  this->m_OpenedFiles.m_Memory.m_nAllocationCount = 0;
  this->m_OpenedFiles.m_Memory.m_nGrowSize = 0;
  this->m_OpenedFiles.m_Size = 0;
  this->m_OpenedFiles.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_LastOpenedFilePathId);
  this->m_Action = action;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00663CB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPerforceFileListFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPerforceFileListFrame::GetMessageMap(CPerforceFileListFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPerforceFileListFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPerforceFileListFrame::GetMessageMap'::`2'::s_pMap;
  `CPerforceFileListFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPerforceFileListFrame");
  `CPerforceFileListFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00663CE0
// Name: public: virtual struct PanelAnimationMap __near * CPerforceFileListFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPerforceFileListFrame::GetAnimMap(CPerforceFileListFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CPerforceFileListFrame");
}

//------------------------------------------------------------------------------
// Address: 0x00663CF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPerforceFileListFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPerforceFileListFrame::GetKBMap(CPerforceFileListFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPerforceFileListFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPerforceFileListFrame::GetKBMap'::`2'::s_pMap;
  `CPerforceFileListFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPerforceFileListFrame");
  `CPerforceFileListFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00663D20
// Name: public: virtual CPerforceFileListFrame::~CPerforceFileListFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPerforceFileListFrame::~CPerforceFileListFrame(CPerforceFileListFrame *this)
{
  bool v2; // sf

  this->__vftable = (CPerforceFileListFrame_vtbl *)&CPerforceFileListFrame::`vftable';
  v2 = this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_LastOpenedFilePathId.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_pMemory);
      this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_LastOpenedFilePathId.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_OpenedFiles);
  COperationFileListFrame::~COperationFileListFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x00663D80
// Name: void ShowPerforceQuery(class vgui::Panel __near *,char const __near *,class vgui::Panel __near *,class KeyValues __near *,enum PerforceAction_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowPerforceQuery(
        vgui::Panel *pParent,
        const char *pFileName,
        vgui::Panel *pActionSignalTarget,
        KeyValues *pKeyValues,
        PerforceAction_t actionFilter)
{
  PerforceAction_t v5; // esi
  const char *v6; // edi
  CPerforceFileListFrame *v7; // eax
  CPerforceFileListFrame *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // edi
  vgui::IVGui *v11; // esi
  vgui::IVGui_vtbl *v12; // ebx
  int v13; // eax

  p4->RefreshActiveClient(this: p4);
  if ( p4->IsFileInPerforce(this: p4, a2: pFileName) )
  {
    if ( p4->GetFileState(this: p4, a2: pFileName) != P4FILE_UNOPENED )
      goto LABEL_13;
    v5 = PERFORCE_ACTION_FILE_EDIT;
    v6 = "Check Out File from Perforce?";
  }
  else
  {
    v5 = PERFORCE_ACTION_FILE_ADD;
    v6 = "Add File to Perforce?";
  }
  if ( actionFilter == PERFORCE_ACTION_NONE || actionFilter == v5 )
  {
    v7 = (CPerforceFileListFrame *)MemAlloc_Alloc(nSize: 0x26Cu);
    if ( v7 != nullptr )
      v8 = CPerforceFileListFrame::CPerforceFileListFrame(
             this: v7,
             pParent,
             pTitle: v6,
             pColumnHeader: "File",
             action: v5);
    else
      v8 = nullptr;
    CPerforceFileListFrame::AddFile(this: v8, pFullPath: pFileName);
    if ( pActionSignalTarget != nullptr )
      v8->AddActionSignalTarget_2(this: v8, a2: pActionSignalTarget);
    COperationFileListFrame::DoModal(this: v8, pContextKeyValues: pKeyValues, pMessage: "PerforceQueryCompleted");
    return;
  }
LABEL_13:
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(
            this: v9,
            setName: "PerforceQueryCompleted",
            firstKey: "operationPerformed",
            firstValue: 1);
  else
    v10 = nullptr;
  if ( pKeyValues != nullptr )
    KeyValues::AddSubKey(this: v10, pSubkey: pKeyValues);
  v11 = g_pVGui;
  v12 = g_pVGui->__vftable;
  v13 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))pActionSignalTarget->GetVPanel)(
          a1: pActionSignalTarget,
          a2: v10,
          a3: 0,
          a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v12->PostMessage)(a1: v11, a2: v13);
}

} // namespace sceneviewer
