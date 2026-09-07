// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/fileopenstatemachine.cpp
// Functions: 34
// ============================================================

#include "vgui2\vgui_controls\fileopenstatemachine.h"

//------------------------------------------------------------------------------
// Address: 0x102C3B00
// Name: public: static char const __near * vgui::FileOpenStateMachine::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::FileOpenStateMachine::GetPanelClassName()
{
  return "FileOpenStateMachine";
}

//------------------------------------------------------------------------------
// Address: 0x102C3B10
// Name: private: void vgui::FileOpenStateMachine::SetCompletionState(enum vgui::FileOpenStateMachine::CompletionState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::SetCompletionState(
        vgui::FileOpenStateMachine *this,
        vgui::FileOpenStateMachine::CompletionState_t state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  const char *v5; // eax
  CUtlString *p_m_OpenFileType; // ecx
  const char *v7; // eax

  this->m_CompletionState = state;
  if ( state != IN_PROGRESS )
  {
    this->m_CurrentState = STATE_NONE;
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "FileStateMachineFinished");
    else
      v4 = nullptr;
    KeyValues::SetInt(this: v4, keyName: "completionState", value: this->m_CompletionState);
    KeyValues::SetInt(this: v4, keyName: "wroteFile", value: (*((_BYTE *)this + 428) & 8) != 0);
    v5 = CUtlString::Get(this: &this->m_FileName);
    KeyValues::SetString(this: v4, keyName: "fullPath", value: v5);
    p_m_OpenFileType = &this->m_OpenFileType;
    if ( (*((_BYTE *)this + 428) & 4) == 0 )
      p_m_OpenFileType = &this->m_SaveFileType;
    v7 = CUtlString::Get(this: p_m_OpenFileType);
    KeyValues::SetString(this: v4, keyName: "fileType", value: v7);
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v4, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    this->PostActionSignal(this, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C3BF0
// Name: private: virtual void vgui::FileOpenStateMachine::OnCancelOverwriteFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnCancelOverwriteFile(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_OVERWRITTEN);
}

//------------------------------------------------------------------------------
// Address: 0x102C3C00
// Name: private: virtual void vgui::FileOpenStateMachine::OnFileSelectionCancelled(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnFileSelectionCancelled(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::FOSMState_t m_CurrentState; // eax

  m_CurrentState = this->m_CurrentState;
  if ( m_CurrentState == STATE_SHOWING_SAVE_DIALOG )
  {
    vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_SAVE_NAME_NOT_SPECIFIED);
  }
  else if ( m_CurrentState == STATE_SHOWING_OPEN_DIALOG )
  {
    vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_OPEN_NAME_NOT_SPECIFIED);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C3C20
// Name: private: virtual void vgui::FileOpenStateMachine::OnCancelMakeFileWriteable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnCancelMakeFileWriteable(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_MADE_WRITEABLE);
}

//------------------------------------------------------------------------------
// Address: 0x102C3C30
// Name: private: virtual void vgui::FileOpenStateMachine::OnCancelSaveDocument(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnCancelSaveDocument(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_SAVE_CANCELLED);
}

//------------------------------------------------------------------------------
// Address: 0x102C3C40
// Name: public: void vgui::FileOpenStateMachine::SaveFile(class KeyValues __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::SaveFile(
        vgui::FileOpenStateMachine *this,
        KeyValues *pContextKeyValues,
        char *pFileName,
        char *pFileType,
        char nFlags)
{
  KeyValues *m_pContextKeyValues; // ecx
  int v7; // eax
  char v8; // al
  char v9; // cl
  vgui::Panel *v10; // eax
  const char *v11; // [esp-14h] [ebp-20h]
  const char *v12; // [esp-10h] [ebp-1Ch]

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->m_CompletionState = IN_PROGRESS;
  this->m_pContextKeyValues = pContextKeyValues;
  CUtlString::operator=(this: &this->m_FileName, src: pFileName);
  CUtlString::operator=(this: &this->m_SaveFileType, src: pFileType);
  CUtlString::operator=(this: &this->m_OpenFileType, src: nullptr);
  CUtlString::operator=(this: &this->m_OpenFileName, src: nullptr);
  if ( g_pFullFileSystem->IsSteam(this: g_pFullFileSystem)
    || (v7 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-nop4") != 0) )
  {
    v8 = nFlags & 0xFE;
  }
  else
  {
    v8 = nFlags;
  }
  v9 = v8 & 1 | *((_BYTE *)this + 428) & 0xF0 | (2 * ((v8 & 2) != 0));
  *((_BYTE *)this + 428) = v9;
  if ( (v9 & 2) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_SAVE_DIRTY_FILE_DIALOG;
    v12 = CUtlString::operator char const *(this: &this->m_SaveFileType);
    v11 = CUtlString::operator char const *(this: &this->m_FileName);
    v10 = this->GetParent(this);
    ShowSaveDocumentQuery(
      pParent: v10,
      pFileName: v11,
      pFileType: v12,
      nContext: 0,
      pActionSignalTarget: this,
      pPostSaveCommand: nullptr);
  }
  else
  {
    this->OnSaveFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C3D50
// Name: private: void vgui::FileOpenStateMachine::ReadFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::ReadFile(vgui::FileOpenStateMachine *this)
{
  vgui::IFileOpenStateMachineClient *m_pClient; // eax
  vgui::IFileOpenStateMachineClient_vtbl *v3; // edi
  const char *v4; // eax
  const char *v5; // [esp-8h] [ebp-10h]
  KeyValues *m_pContextKeyValues; // [esp-4h] [ebp-Ch]

  m_pClient = this->m_pClient;
  m_pContextKeyValues = this->m_pContextKeyValues;
  this->m_CurrentState = STATE_READING_FILE;
  v3 = m_pClient->__vftable;
  v5 = CUtlString::operator char const *(this: &this->m_OpenFileType);
  v4 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v3->OnReadFileFromDisk(this: this->m_pClient, a2: v4, a3: v5, a4: m_pContextKeyValues) )
    vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
  else
    vgui::FileOpenStateMachine::SetCompletionState(this, state: ERROR_READING_FILE);
}

//------------------------------------------------------------------------------
// Address: 0x102C3DB0
// Name: private: void vgui::FileOpenStateMachine::OpenFileDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OpenFileDialog(vgui::FileOpenStateMachine *this)
{
  CUtlString *p_m_OpenFileName; // edi
  vgui::FileOpenDialog *v3; // edi
  vgui::Panel *v4; // eax
  vgui::FileOpenDialog *v5; // edi
  vgui::IFileOpenStateMachineClient_vtbl *v6; // ebx
  const char *v7; // eax
  KeyValues *m_pContextKeyValues; // [esp-8h] [ebp-10h]

  p_m_OpenFileName = &this->m_OpenFileName;
  this->m_CurrentState = STATE_SHOWING_OPEN_DIALOG;
  if ( CUtlString::Length(this: &this->m_OpenFileName) != 0 )
  {
    CUtlString::operator=(this: &this->m_FileName, src: p_m_OpenFileName);
    vgui::FileOpenStateMachine::ReadFile(this);
  }
  else
  {
    v3 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
    if ( v3 != nullptr )
    {
      v4 = this->GetParent(this);
      v5 = vgui::FileOpenDialog::FileOpenDialog(
             this: v3,
             parent: v4,
             title: "Open",
             bOpenOnly: true,
             pContextKeyValues: nullptr);
    }
    else
    {
      v5 = nullptr;
    }
    v6 = this->m_pClient->__vftable;
    m_pContextKeyValues = this->m_pContextKeyValues;
    v7 = CUtlString::operator char const *(this: &this->m_OpenFileType);
    v6->SetupFileOpenDialog(this: this->m_pClient, a2: v5, a3: true, a4: v7, a5: m_pContextKeyValues);
    v5->AddActionSignalTarget_2(this: v5, a2: this);
    vgui::FileOpenDialog::DoModal(this: v5, bUnused: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C3E60
// Name: public: void vgui::FileOpenStateMachine::OpenFile(char const __near *,char const __near *,class KeyValues __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OpenFile(
        vgui::FileOpenStateMachine *this,
        char *pOpenFileName,
        char *pOpenFileType,
        KeyValues *pContextKeyValues,
        char *pSaveFileName,
        char *pSaveFileType,
        char nFlags)
{
  KeyValues *m_pContextKeyValues; // ecx
  vgui::Panel *v9; // eax
  const char *v10; // [esp-14h] [ebp-20h]
  const char *v11; // [esp-10h] [ebp-1Ch]

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->m_CompletionState = IN_PROGRESS;
  this->m_pContextKeyValues = pContextKeyValues;
  CUtlString::operator=(this: &this->m_FileName, src: pSaveFileName);
  CUtlString::operator=(this: &this->m_SaveFileType, src: pSaveFileType);
  CUtlString::operator=(this: &this->m_OpenFileType, src: pOpenFileType);
  *((_BYTE *)this + 428) = nFlags & 1 | *((_BYTE *)this + 428) & 0xF4 | (2 * (((nFlags & 2) != 0) | 2));
  CUtlString::operator=(this: &this->m_OpenFileName, src: pOpenFileName);
  if ( (*((_BYTE *)this + 428) & 2) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_SAVE_DIRTY_FILE_DIALOG;
    v11 = CUtlString::operator char const *(this: &this->m_SaveFileType);
    v10 = CUtlString::operator char const *(this: &this->m_FileName);
    v9 = this->GetParent(this);
    ShowSaveDocumentQuery(
      pParent: v9,
      pFileName: v10,
      pFileType: v11,
      nContext: 0,
      pActionSignalTarget: this,
      pPostSaveCommand: nullptr);
  }
  else
  {
    vgui::FileOpenStateMachine::OpenFileDialog(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C3FB0
// Name: private: void vgui::FileOpenStateMachine::WriteFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::WriteFile(vgui::FileOpenStateMachine *this)
{
  vgui::IFileOpenStateMachineClient *m_pClient; // eax
  vgui::IFileOpenStateMachineClient_vtbl *v3; // ebx
  const char *v4; // eax
  char v5; // al
  vgui::Panel *v6; // eax
  const char *v7; // [esp-10h] [ebp-1Ch]
  const char *v8; // [esp-8h] [ebp-14h]
  KeyValues *m_pContextKeyValues; // [esp-4h] [ebp-10h]

  m_pClient = this->m_pClient;
  m_pContextKeyValues = this->m_pContextKeyValues;
  this->m_CurrentState = STATE_WRITING_FILE;
  v3 = m_pClient->__vftable;
  v8 = CUtlString::operator char const *(this: &this->m_SaveFileType);
  v4 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v3->OnWriteFileToDisk(this: this->m_pClient, a2: v4, a3: v8, a4: m_pContextKeyValues) )
  {
    *((_BYTE *)this + 428) |= 8u;
    v5 = *((_BYTE *)this + 428);
    if ( (v5 & 1) != 0 )
    {
      this->m_CurrentState = STATE_SHOWING_PERFORCE_ADD_DIALOG;
      v7 = CUtlString::operator char const *(this: &this->m_FileName);
      v6 = this->GetParent(this);
      ShowPerforceQuery(
        pParent: v6,
        pFileName: v7,
        pActionSignalTarget: this,
        pKeyValues: nullptr,
        actionFilter: nullptr);
    }
    else if ( (v5 & 4) != 0 )
    {
      vgui::FileOpenStateMachine::OpenFileDialog(this);
    }
    else
    {
      vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
    }
  }
  else
  {
    vgui::FileOpenStateMachine::SetCompletionState(this, state: ERROR_WRITING_FILE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4060
// Name: private: virtual void vgui::FileOpenStateMachine::OnMakeFileWriteable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnMakeFileWriteable(vgui::FileOpenStateMachine *this)
{
  IBaseFileSystem_vtbl *v1; // edi
  const char *v3; // eax

  v1 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v3 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v1->SetFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: true, a4: nullptr) )
    vgui::FileOpenStateMachine::WriteFile(this);
  else
    vgui::FileOpenStateMachine::SetCompletionState(this, state: ERROR_MAKING_FILE_WRITEABLE);
}

//------------------------------------------------------------------------------
// Address: 0x102C40B0
// Name: private: void vgui::FileOpenStateMachine::MakeFileWriteableDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::MakeFileWriteableDialog(vgui::FileOpenStateMachine *this)
{
  IBaseFileSystem_vtbl *v1; // ebx
  const char *v3; // eax
  IBaseFileSystem_vtbl *v4; // ebx
  const char *v5; // eax
  IP4_vtbl *v6; // ebx
  const char *v7; // eax
  const char *v8; // eax
  bool v9; // al
  const char *v10; // eax
  vgui::MessageBox *v11; // esi
  vgui::Panel *v12; // eax
  vgui::MessageBox *v13; // esi
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  char pBuf[1024]; // [esp+Ch] [ebp-404h] BYREF
  IP4_vtbl *v19; // [esp+40Ch] [ebp-4h]

  v1 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v3 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( !v1->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: nullptr)
    || (v4 = g_pFullFileSystem->IBaseFileSystem::__vftable,
        v5 = CUtlString::operator char const *(this: &this->m_FileName),
        v4->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5, a3: nullptr)) )
  {
    vgui::FileOpenStateMachine::WriteFile(this);
  }
  else
  {
    v6 = p4->__vftable;
    v7 = CUtlString::operator char const *(this: &this->m_FileName);
    LOBYTE(v6) = v6->IsFileInPerforce(this: p4, a2: v7);
    v19 = p4->__vftable;
    v8 = CUtlString::operator char const *(this: &this->m_FileName);
    v9 = v19->GetFileState(this: p4, a2: v8) != P4FILE_UNOPENED;
    if ( (_BYTE)v6 == 0 || v9 )
    {
      this->m_CurrentState = STATE_SHOWING_MAKE_FILE_WRITEABLE_DIALOG;
      v10 = CUtlString::Get(this: &this->m_FileName);
      V_snprintf(
        pDest: pBuf,
        maxLen: 1024,
        pFormat: "Encountered read-only file. Should it be made writeable?\n\n\"%s\"\n",
        v10);
      v11 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
      if ( v11 != nullptr )
      {
        v12 = this->GetParent(this);
        v13 = vgui::MessageBox::MessageBox(this: v11, title: "Make File Writeable?", text: pBuf, parent: v12);
      }
      else
      {
        v13 = nullptr;
      }
      v13->AddActionSignalTarget_2(this: v13, a2: this);
      v13->SetOKButtonVisible(this: v13, a2: true);
      v13->SetOKButtonText_2(this: v13, a2: "Yes");
      vgui::MessageBox::SetCancelButtonVisible(this: v13, state: true);
      vgui::MessageBox::SetCancelButtonText(this: v13, buttonText: "No");
      v13->SetCloseButtonVisible(this: v13, a2: false);
      v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v14 != nullptr )
        v15 = KeyValues::KeyValues(this: v14, setName: "MakeFileWriteable");
      else
        v15 = nullptr;
      v13->SetCommand(this: v13, a2: v15);
      v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v16 != nullptr )
        v17 = KeyValues::KeyValues(this: v16, setName: "CancelMakeFileWriteable");
      else
        v17 = nullptr;
      vgui::MessageBox::SetCancelCommand(this: v13, command: v17);
      v13->DoModal_2(this: v13, a2: nullptr);
    }
    else
    {
      vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_CHECKED_OUT);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C42B0
// Name: private: virtual void vgui::FileOpenStateMachine::OnPerforceQueryCompleted(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnPerforceQueryCompleted(
        vgui::FileOpenStateMachine *this,
        KeyValues *pKeyValues)
{
  vgui::FileOpenStateMachine::FOSMState_t m_CurrentState; // eax

  m_CurrentState = this->m_CurrentState;
  if ( m_CurrentState == STATE_SHOWING_CHECK_OUT_DIALOG )
  {
    if ( KeyValues::GetInt(this: pKeyValues, keyName: "operationPerformed", defaultValue: 0) != 0 )
      vgui::FileOpenStateMachine::MakeFileWriteableDialog(this);
    else
      vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_CHECKED_OUT);
  }
  else if ( m_CurrentState == STATE_SHOWING_PERFORCE_ADD_DIALOG )
  {
    if ( (*((_BYTE *)this + 428) & 4) != 0 )
      vgui::FileOpenStateMachine::OpenFileDialog(this);
    else
      vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4310
// Name: private: virtual void vgui::FileOpenStateMachine::OnSaveFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnSaveFile(vgui::FileOpenStateMachine *this)
{
  const char *v2; // eax
  vgui::FileOpenDialog *v3; // edi
  vgui::Panel *v4; // eax
  vgui::FileOpenDialog *v5; // edi
  vgui::IFileOpenStateMachineClient_vtbl *v6; // ebx
  const char *v7; // eax
  KeyValues *m_pContextKeyValues; // [esp-8h] [ebp-10h]

  if ( *CUtlString::operator char const *(this: &this->m_FileName) != 0
    && (v2 = CUtlString::operator char const *(this: &this->m_FileName), V_IsAbsolutePath(pStr: v2)) )
  {
    vgui::FileOpenStateMachine::CheckOutDialog(this);
  }
  else
  {
    this->m_CurrentState = STATE_SHOWING_SAVE_DIALOG;
    v3 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
    if ( v3 != nullptr )
    {
      v4 = this->GetParent(this);
      v5 = vgui::FileOpenDialog::FileOpenDialog(
             this: v3,
             parent: v4,
             title: "Save As",
             bOpenOnly: false,
             pContextKeyValues: nullptr);
    }
    else
    {
      v5 = nullptr;
    }
    v6 = this->m_pClient->__vftable;
    m_pContextKeyValues = this->m_pContextKeyValues;
    v7 = CUtlString::operator char const *(this: &this->m_SaveFileType);
    v6->SetupFileOpenDialog(this: this->m_pClient, a2: v5, a3: false, a4: v7, a5: m_pContextKeyValues);
    v5->AddActionSignalTarget_2(this: v5, a2: this);
    vgui::FileOpenDialog::DoModal(this: v5, bUnused: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C43D0
// Name: private: virtual void vgui::FileOpenStateMachine::OnMarkNotDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnMarkNotDirty(vgui::FileOpenStateMachine *this)
{
  if ( (*((_BYTE *)this + 428) & 4) != 0 )
    vgui::FileOpenStateMachine::OpenFileDialog(this);
  else
    vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
}

//------------------------------------------------------------------------------
// Address: 0x102C43F0
// Name: private: void vgui::FileOpenStateMachine::CheckOutDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::CheckOutDialog(vgui::FileOpenStateMachine *this)
{
  vgui::Panel *v2; // eax
  const char *v3; // [esp-10h] [ebp-14h]

  if ( (*((_BYTE *)this + 428) & 1) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_CHECK_OUT_DIALOG;
    v3 = CUtlString::operator char const *(this: &this->m_FileName);
    v2 = this->GetParent(this);
    ShowPerforceQuery(
      pParent: v2,
      pFileName: v3,
      pActionSignalTarget: this,
      pKeyValues: nullptr,
      actionFilter: (const char *)1);
  }
  else
  {
    vgui::FileOpenStateMachine::WriteFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4440
// Name: private: void vgui::FileOpenStateMachine::OverwriteFileDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OverwriteFileDialog(vgui::FileOpenStateMachine *this)
{
  IBaseFileSystem_vtbl *v1; // ebx
  const char *v3; // eax
  vgui::Panel *v4; // eax
  const char *v5; // eax
  vgui::MessageBox *v6; // esi
  vgui::Panel *v7; // eax
  vgui::MessageBox *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  const char *v13; // [esp-10h] [ebp-41Ch]
  char pBuf[1024]; // [esp+Ch] [ebp-400h] BYREF

  v1 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v3 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v1->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: nullptr) )
  {
    this->m_CurrentState = STATE_SHOWING_OVERWRITE_DIALOG;
    v5 = CUtlString::Get(this: &this->m_FileName);
    V_snprintf(pDest: pBuf, maxLen: 1024, pFormat: "File already exists. Overwrite it?\n\n\"%s\"\n", v5);
    v6 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v6 != nullptr )
    {
      v7 = this->GetParent(this);
      v8 = vgui::MessageBox::MessageBox(this: v6, title: "Overwrite Existing File?", text: pBuf, parent: v7);
    }
    else
    {
      v8 = nullptr;
    }
    v8->AddActionSignalTarget_2(this: v8, a2: this);
    v8->SetOKButtonVisible(this: v8, a2: true);
    v8->SetOKButtonText_2(this: v8, a2: "Yes");
    vgui::MessageBox::SetCancelButtonVisible(this: v8, state: true);
    vgui::MessageBox::SetCancelButtonText(this: v8, buttonText: "No");
    v8->SetCloseButtonVisible(this: v8, a2: false);
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
      v10 = KeyValues::KeyValues(this: v9, setName: "OverwriteFile");
    else
      v10 = nullptr;
    v8->SetCommand(this: v8, a2: v10);
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "CancelOverwriteFile");
    else
      v12 = nullptr;
    vgui::MessageBox::SetCancelCommand(this: v8, command: v12);
    v8->DoModal_2(this: v8, a2: nullptr);
  }
  else if ( (*((_BYTE *)this + 428) & 1) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_CHECK_OUT_DIALOG;
    v13 = CUtlString::operator char const *(this: &this->m_FileName);
    v4 = this->GetParent(this);
    ShowPerforceQuery(
      pParent: v4,
      pFileName: v13,
      pActionSignalTarget: this,
      pKeyValues: nullptr,
      actionFilter: (const char *)1);
  }
  else
  {
    vgui::FileOpenStateMachine::WriteFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C45E0
// Name: private: virtual void vgui::FileOpenStateMachine::OnFileSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnFileSelected(vgui::FileOpenStateMachine *this, KeyValues *pKeyValues)
{
  vgui::FileOpenStateMachine::FOSMState_t m_CurrentState; // eax
  char *String; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax

  m_CurrentState = this->m_CurrentState;
  if ( m_CurrentState == STATE_SHOWING_SAVE_DIALOG )
  {
    String = KeyValues::GetString(this: pKeyValues, keyName: "fullpath", defaultValue: defaultValue);
    CUtlString::operator=(this: &this->m_FileName, src: String);
    v5 = KeyValues::GetString(this: pKeyValues, keyName: "filterinfo", defaultValue: defaultValue);
    if ( v5 != nullptr )
      CUtlString::operator=(this: &this->m_SaveFileType, src: v5);
    vgui::FileOpenStateMachine::OverwriteFileDialog(this);
  }
  else if ( m_CurrentState == STATE_SHOWING_OPEN_DIALOG )
  {
    v6 = KeyValues::GetString(this: pKeyValues, keyName: "fullpath", defaultValue: defaultValue);
    CUtlString::operator=(this: &this->m_FileName, src: v6);
    v7 = KeyValues::GetString(this: pKeyValues, keyName: "filterinfo", defaultValue: defaultValue);
    if ( v7 != nullptr )
      CUtlString::operator=(this: &this->m_OpenFileType, src: v7);
    vgui::FileOpenStateMachine::ReadFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C46A0
// Name: public: virtual vgui::FileOpenStateMachine::~FileOpenStateMachine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::~FileOpenStateMachine(vgui::FileOpenStateMachine *this)
{
  KeyValues *m_pContextKeyValues; // ecx

  m_pContextKeyValues = this->m_pContextKeyValues;
  this->__vftable = (vgui::FileOpenStateMachine_vtbl *)&vgui::FileOpenStateMachine::`vftable';
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->m_OpenFileName.m_Storage.m_nActualLength = 0;
  if ( this->m_OpenFileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OpenFileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OpenFileName.m_Storage.m_Memory.m_pMemory);
      this->m_OpenFileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_OpenFileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_OpenFileType.m_Storage.m_nActualLength = 0;
  if ( this->m_OpenFileType.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OpenFileType.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OpenFileType.m_Storage.m_Memory.m_pMemory);
      this->m_OpenFileType.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_OpenFileType.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_SaveFileType.m_Storage.m_nActualLength = 0;
  if ( this->m_SaveFileType.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SaveFileType.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SaveFileType.m_Storage.m_Memory.m_pMemory);
      this->m_SaveFileType.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_SaveFileType.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FileName.m_Storage.m_nActualLength = 0;
  if ( this->m_FileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FileName.m_Storage.m_Memory.m_pMemory);
      this->m_FileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_FileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C47A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::FileOpenStateMachine::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::FileOpenStateMachine::GetMessageMap(vgui::FileOpenStateMachine *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::FileOpenStateMachine::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::FileOpenStateMachine::GetMessageMap'::`2'::s_pMap;
  `vgui::FileOpenStateMachine::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
  `vgui::FileOpenStateMachine::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C47D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::FileOpenStateMachine::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::FileOpenStateMachine::GetAnimMap(vgui::FileOpenStateMachine *this)
{
  return FindOrAddPanelAnimationMap(className: "FileOpenStateMachine");
}

//------------------------------------------------------------------------------
// Address: 0x102C47E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::FileOpenStateMachine::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::FileOpenStateMachine::GetKBMap(vgui::FileOpenStateMachine *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::FileOpenStateMachine::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::FileOpenStateMachine::GetKBMap'::`2'::s_pMap;
  `vgui::FileOpenStateMachine::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "FileOpenStateMachine");
  `vgui::FileOpenStateMachine::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C4840
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "FileSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C48D0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{848,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FileSelectionCancelled";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4960
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PerforceQueryCompleted";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C49F0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MakeFileWriteable";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4A80
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CancelMakeFileWriteable";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4B10
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{864,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OverwriteFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4BA0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{868,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CancelOverwriteFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4C30
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::RichText::`vcall'{872,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnSaveFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4CC0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::RichText::`vcall'{876,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnMarkNotDirty";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4D50
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{880,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnCancelSaveDocument";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4DE0
// Name: public: vgui::FileOpenStateMachine::FileOpenStateMachine(class vgui::Panel __near *,class vgui::IFileOpenStateMachineClient __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FileOpenStateMachine *__thiscall vgui::FileOpenStateMachine::FileOpenStateMachine(
        vgui::FileOpenStateMachine *this,
        vgui::Panel *pParent,
        vgui::IFileOpenStateMachineClient *pClient)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: "FileOpenStateMachine");
  this->__vftable = (vgui::FileOpenStateMachine_vtbl *)&vgui::FileOpenStateMachine::`vftable';
  if ( `vgui::FileOpenStateMachine::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::FileOpenStateMachine::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v4->pfnClassName = vgui::FileOpenStateMachine::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::FileOpenStateMachine::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::FileOpenStateMachine::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "FileOpenStateMachine");
    v5->pfnClassName = vgui::FileOpenStateMachine::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::FileOpenStateMachine::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::FileOpenStateMachine::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "FileOpenStateMachine");
    v6->pfnClassName = vgui::FileOpenStateMachine::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar();
  vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar();
  vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar();
  vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar();
  vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar();
  vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar();
  vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar();
  vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar();
  vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar();
  vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar();
  CUtlString::CUtlString(this: &this->m_FileName);
  CUtlString::CUtlString(this: &this->m_SaveFileType);
  CUtlString::CUtlString(this: &this->m_OpenFileType);
  CUtlString::CUtlString(this: &this->m_OpenFileName);
  this->m_pClient = pClient;
  this->m_CompletionState = SUCCESSFUL;
  this->m_CurrentState = STATE_NONE;
  this->m_pContextKeyValues = nullptr;
  vgui::Panel::SetVisible(this, state: 0);
  return this;
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x0062D610
// Name: public: static char const __near * vgui::FileOpenStateMachine::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::FileOpenStateMachine::GetPanelClassName()
{
  return "FileOpenStateMachine";
}

//------------------------------------------------------------------------------
// Address: 0x0062D620
// Name: private: void vgui::FileOpenStateMachine::SetCompletionState(enum vgui::FileOpenStateMachine::CompletionState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::SetCompletionState(
        vgui::FileOpenStateMachine *this,
        vgui::FileOpenStateMachine::CompletionState_t state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  char *v5; // eax
  CUtlString *p_m_OpenFileType; // ecx
  char *v7; // eax

  this->m_CompletionState = state;
  if ( state != IN_PROGRESS )
  {
    this->m_CurrentState = STATE_NONE;
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "FileStateMachineFinished");
    else
      v4 = nullptr;
    KeyValues::SetInt(this: v4, keyName: "completionState", value: this->m_CompletionState);
    KeyValues::SetInt(this: v4, keyName: "wroteFile", value: (*((_BYTE *)this + 428) & 8) != 0);
    v5 = CUtlString::Get(this: &this->m_FileName);
    KeyValues::SetString(this: v4, keyName: "fullPath", value: v5);
    p_m_OpenFileType = &this->m_OpenFileType;
    if ( (*((_BYTE *)this + 428) & 4) == 0 )
      p_m_OpenFileType = &this->m_SaveFileType;
    v7 = CUtlString::Get(this: p_m_OpenFileType);
    KeyValues::SetString(this: v4, keyName: "fileType", value: v7);
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v4, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    this->PostActionSignal(this, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062D700
// Name: private: virtual void vgui::FileOpenStateMachine::OnCancelOverwriteFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnCancelOverwriteFile(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_OVERWRITTEN);
}

//------------------------------------------------------------------------------
// Address: 0x0062D710
// Name: private: virtual void vgui::FileOpenStateMachine::OnFileSelectionCancelled(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnFileSelectionCancelled(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::FOSMState_t m_CurrentState; // eax

  m_CurrentState = this->m_CurrentState;
  if ( m_CurrentState == STATE_SHOWING_SAVE_DIALOG )
  {
    vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_SAVE_NAME_NOT_SPECIFIED);
  }
  else if ( m_CurrentState == STATE_SHOWING_OPEN_DIALOG )
  {
    vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_OPEN_NAME_NOT_SPECIFIED);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062D730
// Name: private: virtual void vgui::FileOpenStateMachine::OnCancelMakeFileWriteable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnCancelMakeFileWriteable(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_MADE_WRITEABLE);
}

//------------------------------------------------------------------------------
// Address: 0x0062D740
// Name: private: virtual void vgui::FileOpenStateMachine::OnCancelSaveDocument(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnCancelSaveDocument(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_SAVE_CANCELLED);
}

//------------------------------------------------------------------------------
// Address: 0x0062D750
// Name: public: void vgui::FileOpenStateMachine::SaveFile(class KeyValues __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::SaveFile(
        vgui::FileOpenStateMachine *this,
        KeyValues *pContextKeyValues,
        char *pFileName,
        char *pFileType,
        char nFlags)
{
  KeyValues *m_pContextKeyValues; // ecx
  int v7; // ecx
  int v8; // eax
  char v9; // al
  char v10; // cl
  vgui::Panel *v11; // eax
  const char *v12; // [esp-14h] [ebp-20h]
  const char *v13; // [esp-10h] [ebp-1Ch]

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->m_CompletionState = IN_PROGRESS;
  this->m_pContextKeyValues = pContextKeyValues;
  CUtlString::operator=(this: &this->m_FileName, src: pFileName);
  CUtlString::operator=(this: &this->m_SaveFileType, src: pFileType);
  CUtlString::operator=(this: &this->m_OpenFileType, src: nullptr);
  CUtlString::operator=(this: &this->m_OpenFileName, src: nullptr);
  if ( g_pFullFileSystem->IsSteam(this: g_pFullFileSystem)
    || (v8 = _CommandLine(a1: v7),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 40))(a1: v8, a2: "-nop4") != 0) )
  {
    v9 = nFlags & 0xFE;
  }
  else
  {
    v9 = nFlags;
  }
  v10 = v9 & 1 | *((_BYTE *)this + 428) & 0xF0 | (2 * ((v9 & 2) != 0));
  *((_BYTE *)this + 428) = v10;
  if ( (v10 & 2) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_SAVE_DIRTY_FILE_DIALOG;
    v13 = CUtlString::operator char const *(this: &this->m_SaveFileType);
    v12 = CUtlString::operator char const *(this: &this->m_FileName);
    v11 = this->GetParent(this);
    ShowSaveDocumentQuery(
      pParent: v11,
      pFileName: v12,
      pFileType: v13,
      nContext: 0,
      pActionSignalTarget: this,
      pPostSaveCommand: nullptr);
  }
  else
  {
    this->OnSaveFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062D860
// Name: private: void vgui::FileOpenStateMachine::ReadFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::ReadFile(vgui::FileOpenStateMachine *this)
{
  vgui::IFileOpenStateMachineClient *m_pClient; // eax
  vgui::IFileOpenStateMachineClient_vtbl *v3; // edi
  const char *v4; // eax
  const char *v5; // [esp-8h] [ebp-10h]
  KeyValues *m_pContextKeyValues; // [esp-4h] [ebp-Ch]

  m_pClient = this->m_pClient;
  m_pContextKeyValues = this->m_pContextKeyValues;
  this->m_CurrentState = STATE_READING_FILE;
  v3 = m_pClient->__vftable;
  v5 = CUtlString::operator char const *(this: &this->m_OpenFileType);
  v4 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v3->OnReadFileFromDisk(this: this->m_pClient, a2: v4, a3: v5, a4: m_pContextKeyValues) )
    vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
  else
    vgui::FileOpenStateMachine::SetCompletionState(this, state: ERROR_READING_FILE);
}

//------------------------------------------------------------------------------
// Address: 0x0062D8C0
// Name: private: void vgui::FileOpenStateMachine::OpenFileDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OpenFileDialog(vgui::FileOpenStateMachine *this)
{
  CUtlString *p_m_OpenFileName; // edi
  vgui::FileOpenDialog *v3; // edi
  vgui::Panel *v4; // eax
  vgui::FileOpenDialog *v5; // edi
  vgui::IFileOpenStateMachineClient_vtbl *v6; // ebx
  const char *v7; // eax
  KeyValues *m_pContextKeyValues; // [esp-8h] [ebp-10h]

  p_m_OpenFileName = &this->m_OpenFileName;
  this->m_CurrentState = STATE_SHOWING_OPEN_DIALOG;
  if ( CUtlString::Length(this: &this->m_OpenFileName) != 0 )
  {
    CUtlString::operator=(this: &this->m_FileName, src: p_m_OpenFileName);
    vgui::FileOpenStateMachine::ReadFile(this);
  }
  else
  {
    v3 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
    if ( v3 != nullptr )
    {
      v4 = this->GetParent(this);
      v5 = vgui::FileOpenDialog::FileOpenDialog(
             this: v3,
             parent: v4,
             title: (vgui::Label *)"Open",
             bOpenOnly: true,
             pContextKeyValues: nullptr);
    }
    else
    {
      v5 = nullptr;
    }
    v6 = this->m_pClient->__vftable;
    m_pContextKeyValues = this->m_pContextKeyValues;
    v7 = CUtlString::operator char const *(this: &this->m_OpenFileType);
    v6->SetupFileOpenDialog(this: this->m_pClient, a2: v5, a3: true, a4: v7, a5: m_pContextKeyValues);
    v5->AddActionSignalTarget_2(this: v5, a2: this);
    vgui::FileOpenDialog::DoModal(this: v5, bUnused: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062D970
// Name: public: void vgui::FileOpenStateMachine::OpenFile(char const __near *,class KeyValues __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OpenFile(
        vgui::FileOpenStateMachine *this,
        char *pOpenFileType,
        KeyValues *pContextKeyValues,
        char *pSaveFileName,
        char *pSaveFileType,
        char nFlags)
{
  KeyValues *m_pContextKeyValues; // ecx
  char v8; // cl
  vgui::Panel *v9; // eax
  const char *v10; // [esp-14h] [ebp-20h]
  const char *v11; // [esp-10h] [ebp-1Ch]

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->m_CompletionState = IN_PROGRESS;
  this->m_pContextKeyValues = pContextKeyValues;
  CUtlString::operator=(this: &this->m_FileName, src: pSaveFileName);
  CUtlString::operator=(this: &this->m_SaveFileType, src: pSaveFileType);
  CUtlString::operator=(this: &this->m_OpenFileType, src: pOpenFileType);
  CUtlString::operator=(this: &this->m_OpenFileName, src: nullptr);
  v8 = nFlags & 1 | *((_BYTE *)this + 428) & 0xF4 | (2 * (((nFlags & 2) != 0) | 2));
  *((_BYTE *)this + 428) = v8;
  if ( (v8 & 2) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_SAVE_DIRTY_FILE_DIALOG;
    v11 = CUtlString::operator char const *(this: &this->m_SaveFileType);
    v10 = CUtlString::operator char const *(this: &this->m_FileName);
    v9 = this->GetParent(this);
    ShowSaveDocumentQuery(
      pParent: v9,
      pFileName: v10,
      pFileType: v11,
      nContext: 0,
      pActionSignalTarget: this,
      pPostSaveCommand: nullptr);
  }
  else
  {
    vgui::FileOpenStateMachine::OpenFileDialog(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062DA90
// Name: private: void vgui::FileOpenStateMachine::WriteFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::WriteFile(vgui::FileOpenStateMachine *this)
{
  vgui::IFileOpenStateMachineClient *m_pClient; // eax
  vgui::IFileOpenStateMachineClient_vtbl *v3; // ebx
  const char *v4; // eax
  char v5; // al
  vgui::Panel *v6; // eax
  const char *v7; // [esp-10h] [ebp-1Ch]
  const char *v8; // [esp-8h] [ebp-14h]
  KeyValues *m_pContextKeyValues; // [esp-4h] [ebp-10h]

  m_pClient = this->m_pClient;
  m_pContextKeyValues = this->m_pContextKeyValues;
  this->m_CurrentState = STATE_WRITING_FILE;
  v3 = m_pClient->__vftable;
  v8 = CUtlString::operator char const *(this: &this->m_SaveFileType);
  v4 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v3->OnWriteFileToDisk(this: this->m_pClient, a2: v4, a3: v8, a4: m_pContextKeyValues) )
  {
    *((_BYTE *)this + 428) |= 8u;
    v5 = *((_BYTE *)this + 428);
    if ( (v5 & 1) != 0 )
    {
      this->m_CurrentState = STATE_SHOWING_PERFORCE_ADD_DIALOG;
      v7 = CUtlString::operator char const *(this: &this->m_FileName);
      v6 = this->GetParent(this);
      ShowPerforceQuery(
        pParent: v6,
        pFileName: v7,
        pActionSignalTarget: this,
        pKeyValues: nullptr,
        actionFilter: PERFORCE_ACTION_FILE_ADD);
    }
    else if ( (v5 & 4) != 0 )
    {
      vgui::FileOpenStateMachine::OpenFileDialog(this);
    }
    else
    {
      vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
    }
  }
  else
  {
    vgui::FileOpenStateMachine::SetCompletionState(this, state: ERROR_WRITING_FILE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062DB40
// Name: private: virtual void vgui::FileOpenStateMachine::OnMakeFileWriteable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnMakeFileWriteable(vgui::FileOpenStateMachine *this)
{
  IBaseFileSystem_vtbl *v1; // edi
  const char *v3; // eax

  v1 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v3 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v1->SetFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: true, a4: nullptr) )
    vgui::FileOpenStateMachine::WriteFile(this);
  else
    vgui::FileOpenStateMachine::SetCompletionState(this, state: ERROR_MAKING_FILE_WRITEABLE);
}

//------------------------------------------------------------------------------
// Address: 0x0062DB90
// Name: private: void vgui::FileOpenStateMachine::MakeFileWriteableDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::MakeFileWriteableDialog(vgui::FileOpenStateMachine *this)
{
  IBaseFileSystem_vtbl *v1; // ebx
  const char *v3; // eax
  IBaseFileSystem_vtbl *v4; // ebx
  const char *v5; // eax
  IP4_vtbl *v6; // ebx
  const char *v7; // eax
  const char *v8; // eax
  bool v9; // al
  const char *v10; // eax
  vgui::MessageBox *v11; // esi
  vgui::Panel *v12; // eax
  vgui::MessageBox *v13; // esi
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  char pBuf[1024]; // [esp+Ch] [ebp-404h] BYREF
  IP4_vtbl *v19; // [esp+40Ch] [ebp-4h]

  v1 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v3 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( !v1->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: nullptr)
    || (v4 = g_pFullFileSystem->IBaseFileSystem::__vftable,
        v5 = CUtlString::operator char const *(this: &this->m_FileName),
        v4->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5, a3: nullptr)) )
  {
    vgui::FileOpenStateMachine::WriteFile(this);
  }
  else
  {
    v6 = p4->__vftable;
    v7 = CUtlString::operator char const *(this: &this->m_FileName);
    LOBYTE(v6) = v6->IsFileInPerforce(this: p4, a2: v7);
    v19 = p4->__vftable;
    v8 = CUtlString::operator char const *(this: &this->m_FileName);
    v9 = v19->GetFileState(this: p4, a2: v8) != P4FILE_UNOPENED;
    if ( (_BYTE)v6 == 0 || v9 )
    {
      this->m_CurrentState = STATE_SHOWING_MAKE_FILE_WRITEABLE_DIALOG;
      v10 = CUtlString::Get(this: &this->m_FileName);
      V_snprintf(
        pDest: pBuf,
        maxLen: 0x400u,
        pFormat: "Encountered read-only file. Should it be made writeable?\n\n\"%s\"\n",
        v10);
      v11 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
      if ( v11 != nullptr )
      {
        v12 = this->GetParent(this);
        v13 = vgui::MessageBox::MessageBox(this: v11, title: "Make File Writeable?", text: pBuf, parent: v12);
      }
      else
      {
        v13 = nullptr;
      }
      v13->AddActionSignalTarget_2(this: v13, a2: this);
      v13->SetOKButtonVisible(this: v13, a2: true);
      v13->SetOKButtonText_2(this: v13, a2: "Yes");
      vgui::MessageBox::SetCancelButtonVisible(this: v13, state: true);
      vgui::MessageBox::SetCancelButtonText(this: v13, buttonText: "No");
      v13->SetCloseButtonVisible(this: v13, a2: false);
      v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v14 != nullptr )
        v15 = KeyValues::KeyValues(this: v14, setName: "MakeFileWriteable");
      else
        v15 = nullptr;
      v13->SetCommand(this: v13, a2: v15);
      v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v16 != nullptr )
        v17 = KeyValues::KeyValues(this: v16, setName: "CancelMakeFileWriteable");
      else
        v17 = nullptr;
      vgui::MessageBox::SetCancelCommand(this: v13, command: v17);
      v13->DoModal_2(this: v13, a2: nullptr);
    }
    else
    {
      vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_CHECKED_OUT);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062DD90
// Name: private: virtual void vgui::FileOpenStateMachine::OnPerforceQueryCompleted(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnPerforceQueryCompleted(
        vgui::FileOpenStateMachine *this,
        KeyValues *pKeyValues)
{
  vgui::FileOpenStateMachine::FOSMState_t m_CurrentState; // eax

  m_CurrentState = this->m_CurrentState;
  if ( m_CurrentState == STATE_SHOWING_CHECK_OUT_DIALOG )
  {
    if ( KeyValues::GetInt(this: pKeyValues, keyName: "operationPerformed", defaultValue: 0) != 0 )
      vgui::FileOpenStateMachine::MakeFileWriteableDialog(this);
    else
      vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_CHECKED_OUT);
  }
  else if ( m_CurrentState == STATE_SHOWING_PERFORCE_ADD_DIALOG )
  {
    if ( (*((_BYTE *)this + 428) & 4) != 0 )
      vgui::FileOpenStateMachine::OpenFileDialog(this);
    else
      vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062DDF0
// Name: private: virtual void vgui::FileOpenStateMachine::OnSaveFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnSaveFile(vgui::FileOpenStateMachine *this)
{
  const char *v2; // eax
  vgui::FileOpenDialog *v3; // edi
  vgui::Panel *v4; // eax
  vgui::FileOpenDialog *v5; // edi
  vgui::IFileOpenStateMachineClient_vtbl *v6; // ebx
  const char *v7; // eax
  KeyValues *m_pContextKeyValues; // [esp-8h] [ebp-10h]

  if ( *CUtlString::operator char const *(this: &this->m_FileName) != 0
    && (v2 = CUtlString::operator char const *(this: &this->m_FileName), V_IsAbsolutePath(pStr: v2)) )
  {
    vgui::FileOpenStateMachine::CheckOutDialog(this);
  }
  else
  {
    this->m_CurrentState = STATE_SHOWING_SAVE_DIALOG;
    v3 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
    if ( v3 != nullptr )
    {
      v4 = this->GetParent(this);
      v5 = vgui::FileOpenDialog::FileOpenDialog(
             this: v3,
             parent: v4,
             title: (vgui::Label *)"Save As",
             bOpenOnly: false,
             pContextKeyValues: nullptr);
    }
    else
    {
      v5 = nullptr;
    }
    v6 = this->m_pClient->__vftable;
    m_pContextKeyValues = this->m_pContextKeyValues;
    v7 = CUtlString::operator char const *(this: &this->m_SaveFileType);
    v6->SetupFileOpenDialog(this: this->m_pClient, a2: v5, a3: false, a4: v7, a5: m_pContextKeyValues);
    v5->AddActionSignalTarget_2(this: v5, a2: this);
    vgui::FileOpenDialog::DoModal(this: v5, bUnused: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062DEB0
// Name: private: virtual void vgui::FileOpenStateMachine::OnMarkNotDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnMarkNotDirty(vgui::FileOpenStateMachine *this)
{
  if ( (*((_BYTE *)this + 428) & 4) != 0 )
    vgui::FileOpenStateMachine::OpenFileDialog(this);
  else
    vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
}

//------------------------------------------------------------------------------
// Address: 0x0062DED0
// Name: private: void vgui::FileOpenStateMachine::CheckOutDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::CheckOutDialog(vgui::FileOpenStateMachine *this)
{
  vgui::Panel *v2; // eax
  const char *v3; // [esp-10h] [ebp-14h]

  if ( (*((_BYTE *)this + 428) & 1) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_CHECK_OUT_DIALOG;
    v3 = CUtlString::operator char const *(this: &this->m_FileName);
    v2 = this->GetParent(this);
    ShowPerforceQuery(
      pParent: v2,
      pFileName: v3,
      pActionSignalTarget: this,
      pKeyValues: nullptr,
      actionFilter: PERFORCE_ACTION_FILE_EDIT);
  }
  else
  {
    vgui::FileOpenStateMachine::WriteFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062DF20
// Name: private: void vgui::FileOpenStateMachine::OverwriteFileDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OverwriteFileDialog(vgui::FileOpenStateMachine *this)
{
  IBaseFileSystem_vtbl *v1; // ebx
  const char *v3; // eax
  vgui::Panel *v4; // eax
  const char *v5; // eax
  vgui::MessageBox *v6; // esi
  vgui::Panel *v7; // eax
  vgui::MessageBox *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  const char *v13; // [esp-10h] [ebp-41Ch]
  char pBuf[1024]; // [esp+Ch] [ebp-400h] BYREF

  v1 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v3 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v1->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: nullptr) )
  {
    this->m_CurrentState = STATE_SHOWING_OVERWRITE_DIALOG;
    v5 = CUtlString::Get(this: &this->m_FileName);
    V_snprintf(pDest: pBuf, maxLen: 0x400u, pFormat: "File already exists. Overwrite it?\n\n\"%s\"\n", v5);
    v6 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v6 != nullptr )
    {
      v7 = this->GetParent(this);
      v8 = vgui::MessageBox::MessageBox(this: v6, title: "Overwrite Existing File?", text: pBuf, parent: v7);
    }
    else
    {
      v8 = nullptr;
    }
    v8->AddActionSignalTarget_2(this: v8, a2: this);
    v8->SetOKButtonVisible(this: v8, a2: true);
    v8->SetOKButtonText_2(this: v8, a2: "Yes");
    vgui::MessageBox::SetCancelButtonVisible(this: v8, state: true);
    vgui::MessageBox::SetCancelButtonText(this: v8, buttonText: "No");
    v8->SetCloseButtonVisible(this: v8, a2: false);
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
      v10 = KeyValues::KeyValues(this: v9, setName: "OverwriteFile");
    else
      v10 = nullptr;
    v8->SetCommand(this: v8, a2: v10);
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "CancelOverwriteFile");
    else
      v12 = nullptr;
    vgui::MessageBox::SetCancelCommand(this: v8, command: v12);
    v8->DoModal_2(this: v8, a2: nullptr);
  }
  else if ( (*((_BYTE *)this + 428) & 1) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_CHECK_OUT_DIALOG;
    v13 = CUtlString::operator char const *(this: &this->m_FileName);
    v4 = this->GetParent(this);
    ShowPerforceQuery(
      pParent: v4,
      pFileName: v13,
      pActionSignalTarget: this,
      pKeyValues: nullptr,
      actionFilter: PERFORCE_ACTION_FILE_EDIT);
  }
  else
  {
    vgui::FileOpenStateMachine::WriteFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062E0C0
// Name: private: virtual void vgui::FileOpenStateMachine::OnFileSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnFileSelected(vgui::FileOpenStateMachine *this, KeyValues *pKeyValues)
{
  vgui::FileOpenStateMachine::FOSMState_t m_CurrentState; // eax
  char *String; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax

  m_CurrentState = this->m_CurrentState;
  if ( m_CurrentState == STATE_SHOWING_SAVE_DIALOG )
  {
    String = KeyValues::GetString(this: pKeyValues, keyName: "fullpath", defaultValue: defaultValue);
    CUtlString::operator=(this: &this->m_FileName, src: String);
    v5 = KeyValues::GetString(this: pKeyValues, keyName: "filterinfo", defaultValue: defaultValue);
    if ( v5 != nullptr )
      CUtlString::operator=(this: &this->m_SaveFileType, src: v5);
    vgui::FileOpenStateMachine::OverwriteFileDialog(this);
  }
  else if ( m_CurrentState == STATE_SHOWING_OPEN_DIALOG )
  {
    v6 = KeyValues::GetString(this: pKeyValues, keyName: "fullpath", defaultValue: defaultValue);
    CUtlString::operator=(this: &this->m_FileName, src: v6);
    v7 = KeyValues::GetString(this: pKeyValues, keyName: "filterinfo", defaultValue: defaultValue);
    if ( v7 != nullptr )
      CUtlString::operator=(this: &this->m_OpenFileType, src: v7);
    vgui::FileOpenStateMachine::ReadFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062E180
// Name: public: virtual vgui::FileOpenStateMachine::~FileOpenStateMachine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::~FileOpenStateMachine(vgui::FileOpenStateMachine *this)
{
  KeyValues *m_pContextKeyValues; // ecx

  m_pContextKeyValues = this->m_pContextKeyValues;
  this->__vftable = (vgui::FileOpenStateMachine_vtbl *)&vgui::FileOpenStateMachine::`vftable';
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->m_OpenFileName.m_Storage.m_nActualLength = 0;
  if ( this->m_OpenFileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OpenFileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OpenFileName.m_Storage.m_Memory.m_pMemory);
      this->m_OpenFileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_OpenFileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_OpenFileType.m_Storage.m_nActualLength = 0;
  if ( this->m_OpenFileType.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OpenFileType.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OpenFileType.m_Storage.m_Memory.m_pMemory);
      this->m_OpenFileType.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_OpenFileType.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_SaveFileType.m_Storage.m_nActualLength = 0;
  if ( this->m_SaveFileType.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SaveFileType.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SaveFileType.m_Storage.m_Memory.m_pMemory);
      this->m_SaveFileType.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_SaveFileType.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FileName.m_Storage.m_nActualLength = 0;
  if ( this->m_FileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FileName.m_Storage.m_Memory.m_pMemory);
      this->m_FileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_FileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0062E320
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "FileSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062E3B0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{848,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FileSelectionCancelled";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062E440
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PerforceQueryCompleted";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062E4D0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MakeFileWriteable";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062E560
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CancelMakeFileWriteable";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062E5F0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{864,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OverwriteFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062E680
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{868,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CancelOverwriteFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062E710
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::RichText::`vcall'{872,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnSaveFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062E7A0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeElementPickerPanel::`vcall'{876,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnMarkNotDirty";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062E830
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSheetSequencePickerPanel::`vcall'{880,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnCancelSaveDocument";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062E8C0
// Name: public: vgui::FileOpenStateMachine::FileOpenStateMachine(class vgui::Panel __near *,class vgui::IFileOpenStateMachineClient __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FileOpenStateMachine *__thiscall vgui::FileOpenStateMachine::FileOpenStateMachine(
        vgui::FileOpenStateMachine *this,
        vgui::Panel *pParent,
        vgui::IFileOpenStateMachineClient *pClient)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent: pParent, panelName: "FileOpenStateMachine");
  this->__vftable = (vgui::FileOpenStateMachine_vtbl *)&vgui::FileOpenStateMachine::`vftable';
  if ( `vgui::FileOpenStateMachine::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::FileOpenStateMachine::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    v4->pfnClassName = vgui::FileOpenStateMachine::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::FileOpenStateMachine::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::FileOpenStateMachine::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "FileOpenStateMachine");
    v5->pfnClassName = vgui::FileOpenStateMachine::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::FileOpenStateMachine::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::FileOpenStateMachine::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"FileOpenStateMachine");
    v6->pfnClassName = vgui::FileOpenStateMachine::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_FileName);
  CUtlString::CUtlString(this: &this->m_SaveFileType);
  CUtlString::CUtlString(this: &this->m_OpenFileType);
  CUtlString::CUtlString(this: &this->m_OpenFileName);
  this->m_pClient = pClient;
  this->m_CompletionState = SUCCESSFUL;
  this->m_CurrentState = STATE_NONE;
  this->m_pContextKeyValues = nullptr;
  vgui::Panel::SetVisible(this, state: 0);
  return this;
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102C3CE0
// Name: private: virtual void vgui::FileOpenStateMachine::OnCancelOverwriteFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnCancelOverwriteFile(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_OVERWRITTEN);
}

//------------------------------------------------------------------------------
// Address: 0x102C3CF0
// Name: private: virtual void vgui::FileOpenStateMachine::OnFileSelectionCancelled(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnFileSelectionCancelled(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::FOSMState_t m_CurrentState; // eax

  m_CurrentState = this->m_CurrentState;
  if ( m_CurrentState == STATE_SHOWING_SAVE_DIALOG )
  {
    vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_SAVE_NAME_NOT_SPECIFIED);
  }
  else if ( m_CurrentState == STATE_SHOWING_OPEN_DIALOG )
  {
    vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_OPEN_NAME_NOT_SPECIFIED);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C3D10
// Name: private: virtual void vgui::FileOpenStateMachine::OnCancelMakeFileWriteable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnCancelMakeFileWriteable(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_MADE_WRITEABLE);
}

//------------------------------------------------------------------------------
// Address: 0x102C3D20
// Name: private: virtual void vgui::FileOpenStateMachine::OnCancelSaveDocument(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnCancelSaveDocument(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_SAVE_CANCELLED);
}

//------------------------------------------------------------------------------
// Address: 0x102C3D30
// Name: public: void vgui::FileOpenStateMachine::SaveFile(class KeyValues __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::SaveFile(
        vgui::FileOpenStateMachine *this,
        KeyValues *pContextKeyValues,
        __m128i *pFileName,
        __m128i *pFileType,
        char nFlags)
{
  KeyValues *m_pContextKeyValues; // ecx
  int v7; // eax
  char v8; // al
  char v9; // cl
  vgui::Panel *v10; // eax
  const char *v11; // [esp-14h] [ebp-20h]
  const char *v12; // [esp-10h] [ebp-1Ch]
  int v13; // [esp+0h] [ebp-Ch]

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->m_CompletionState = IN_PROGRESS;
  this->m_pContextKeyValues = pContextKeyValues;
  CUtlString::operator=(this: &this->m_FileName, src: pFileName);
  CUtlString::operator=(this: &this->m_SaveFileType, src: pFileType);
  CUtlString::operator=(this: &this->m_OpenFileType, src: nullptr);
  CUtlString::operator=(this: &this->m_OpenFileName, src: nullptr);
  if ( g_pFullFileSystem->IsSteam(this: g_pFullFileSystem)
    || (v7 = _CommandLine(a1: v13),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-nop4") != 0) )
  {
    v8 = nFlags & 0xFE;
  }
  else
  {
    v8 = nFlags;
  }
  v9 = v8 & 1 | *((_BYTE *)this + 428) & 0xF0 | (2 * ((v8 & 2) != 0));
  *((_BYTE *)this + 428) = v9;
  if ( (v9 & 2) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_SAVE_DIRTY_FILE_DIALOG;
    v12 = CUtlString::operator char const *(this: &this->m_SaveFileType);
    v11 = CUtlString::operator char const *(this: &this->m_FileName);
    v10 = this->GetParent(this);
    ShowSaveDocumentQuery(
      pParent: v10,
      pFileName: v11,
      pFileType: v12,
      nContext: 0,
      pActionSignalTarget: this,
      pPostSaveCommand: nullptr);
  }
  else
  {
    this->OnSaveFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C3E40
// Name: private: void vgui::FileOpenStateMachine::ReadFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::ReadFile(vgui::FileOpenStateMachine *this)
{
  vgui::IFileOpenStateMachineClient *m_pClient; // eax
  vgui::IFileOpenStateMachineClient_vtbl *v3; // edi
  const char *v4; // eax
  const char *v5; // [esp-8h] [ebp-10h]
  KeyValues *m_pContextKeyValues; // [esp-4h] [ebp-Ch]

  m_pClient = this->m_pClient;
  m_pContextKeyValues = this->m_pContextKeyValues;
  this->m_CurrentState = STATE_READING_FILE;
  v3 = m_pClient->__vftable;
  v5 = CUtlString::operator char const *(this: &this->m_OpenFileType);
  v4 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v3->OnReadFileFromDisk(this: this->m_pClient, a2: v4, a3: v5, a4: m_pContextKeyValues) )
    vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
  else
    vgui::FileOpenStateMachine::SetCompletionState(this, state: ERROR_READING_FILE);
}

//------------------------------------------------------------------------------
// Address: 0x102C3EA0
// Name: private: void vgui::FileOpenStateMachine::OpenFileDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OpenFileDialog(vgui::FileOpenStateMachine *this)
{
  CUtlString *p_m_OpenFileName; // edi
  vgui::FileOpenDialog *v3; // edi
  vgui::Panel *v4; // eax
  vgui::FileOpenDialog *v5; // edi
  vgui::IFileOpenStateMachineClient_vtbl *v6; // ebx
  const char *v7; // eax
  KeyValues *m_pContextKeyValues; // [esp-8h] [ebp-10h]

  p_m_OpenFileName = &this->m_OpenFileName;
  this->m_CurrentState = STATE_SHOWING_OPEN_DIALOG;
  if ( CUtlString::Length(this: &this->m_OpenFileName) != 0 )
  {
    CUtlString::operator=(this: &this->m_FileName, src: p_m_OpenFileName);
    vgui::FileOpenStateMachine::ReadFile(this);
  }
  else
  {
    v3 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
    if ( v3 != nullptr )
    {
      v4 = this->GetParent(this);
      v5 = vgui::FileOpenDialog::FileOpenDialog(
             this: v3,
             parent: v4,
             title: "Open",
             bOpenOnly: true,
             pContextKeyValues: nullptr);
    }
    else
    {
      v5 = nullptr;
    }
    v6 = this->m_pClient->__vftable;
    m_pContextKeyValues = this->m_pContextKeyValues;
    v7 = CUtlString::operator char const *(this: &this->m_OpenFileType);
    v6->SetupFileOpenDialog(this: this->m_pClient, a2: v5, a3: true, a4: v7, a5: m_pContextKeyValues);
    v5->AddActionSignalTarget_2(this: v5, a2: this);
    vgui::FileOpenDialog::DoModal(this: v5, bUnused: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C3F50
// Name: public: void vgui::FileOpenStateMachine::OpenFile(char const __near *,char const __near *,class KeyValues __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OpenFile(
        vgui::FileOpenStateMachine *this,
        __m128i *pOpenFileName,
        __m128i *pOpenFileType,
        KeyValues *pContextKeyValues,
        __m128i *pSaveFileName,
        __m128i *pSaveFileType,
        char nFlags)
{
  KeyValues *m_pContextKeyValues; // ecx
  vgui::Panel *v9; // eax
  const char *v10; // [esp-14h] [ebp-20h]
  const char *v11; // [esp-10h] [ebp-1Ch]

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->m_CompletionState = IN_PROGRESS;
  this->m_pContextKeyValues = pContextKeyValues;
  CUtlString::operator=(this: &this->m_FileName, src: pSaveFileName);
  CUtlString::operator=(this: &this->m_SaveFileType, src: pSaveFileType);
  CUtlString::operator=(this: &this->m_OpenFileType, src: pOpenFileType);
  *((_BYTE *)this + 428) = nFlags & 1 | *((_BYTE *)this + 428) & 0xF4 | (2 * (((nFlags & 2) != 0) | 2));
  CUtlString::operator=(this: &this->m_OpenFileName, src: pOpenFileName);
  if ( (*((_BYTE *)this + 428) & 2) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_SAVE_DIRTY_FILE_DIALOG;
    v11 = CUtlString::operator char const *(this: &this->m_SaveFileType);
    v10 = CUtlString::operator char const *(this: &this->m_FileName);
    v9 = this->GetParent(this);
    ShowSaveDocumentQuery(
      pParent: v9,
      pFileName: v10,
      pFileType: v11,
      nContext: 0,
      pActionSignalTarget: this,
      pPostSaveCommand: nullptr);
  }
  else
  {
    vgui::FileOpenStateMachine::OpenFileDialog(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4080
// Name: private: void vgui::FileOpenStateMachine::WriteFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::WriteFile(vgui::FileOpenStateMachine *this)
{
  vgui::IFileOpenStateMachineClient *m_pClient; // eax
  vgui::IFileOpenStateMachineClient_vtbl *v3; // ebx
  const char *v4; // eax
  char v5; // al
  vgui::Panel *v6; // eax
  const char *v7; // [esp-10h] [ebp-1Ch]
  const char *v8; // [esp-8h] [ebp-14h]
  KeyValues *m_pContextKeyValues; // [esp-4h] [ebp-10h]

  m_pClient = this->m_pClient;
  m_pContextKeyValues = this->m_pContextKeyValues;
  this->m_CurrentState = STATE_WRITING_FILE;
  v3 = m_pClient->__vftable;
  v8 = CUtlString::operator char const *(this: &this->m_SaveFileType);
  v4 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v3->OnWriteFileToDisk(this: this->m_pClient, a2: v4, a3: v8, a4: m_pContextKeyValues) )
  {
    *((_BYTE *)this + 428) |= 8u;
    v5 = *((_BYTE *)this + 428);
    if ( (v5 & 1) != 0 )
    {
      this->m_CurrentState = STATE_SHOWING_PERFORCE_ADD_DIALOG;
      v7 = CUtlString::operator char const *(this: &this->m_FileName);
      v6 = this->GetParent(this);
      ShowPerforceQuery(
        pParent: v6,
        pFileName: v7,
        pActionSignalTarget: this,
        pKeyValues: nullptr,
        actionFilter: PERFORCE_ACTION_FILE_ADD);
    }
    else if ( (v5 & 4) != 0 )
    {
      vgui::FileOpenStateMachine::OpenFileDialog(this);
    }
    else
    {
      vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
    }
  }
  else
  {
    vgui::FileOpenStateMachine::SetCompletionState(this, state: ERROR_WRITING_FILE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4130
// Name: private: virtual void vgui::FileOpenStateMachine::OnMakeFileWriteable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnMakeFileWriteable(vgui::FileOpenStateMachine *this)
{
  IBaseFileSystem_vtbl *v1; // edi
  const char *v3; // eax

  v1 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v3 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v1->SetFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: true, a4: nullptr) )
    vgui::FileOpenStateMachine::WriteFile(this);
  else
    vgui::FileOpenStateMachine::SetCompletionState(this, state: ERROR_MAKING_FILE_WRITEABLE);
}

//------------------------------------------------------------------------------
// Address: 0x102C4180
// Name: private: void vgui::FileOpenStateMachine::MakeFileWriteableDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::MakeFileWriteableDialog(vgui::FileOpenStateMachine *this)
{
  IBaseFileSystem_vtbl *v1; // ebx
  const char *v3; // eax
  IBaseFileSystem_vtbl *v4; // ebx
  const char *v5; // eax
  IP4_vtbl *v6; // ebx
  const char *v7; // eax
  const char *v8; // eax
  bool v9; // al
  const char *v10; // eax
  vgui::MessageBox *v11; // esi
  vgui::Panel *v12; // eax
  vgui::MessageBox *v13; // esi
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  char pBuf[1024]; // [esp+Ch] [ebp-404h] BYREF
  IP4_vtbl *v19; // [esp+40Ch] [ebp-4h]

  v1 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v3 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( !v1->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: nullptr)
    || (v4 = g_pFullFileSystem->IBaseFileSystem::__vftable,
        v5 = CUtlString::operator char const *(this: &this->m_FileName),
        v4->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5, a3: nullptr)) )
  {
    vgui::FileOpenStateMachine::WriteFile(this);
  }
  else
  {
    v6 = p4->__vftable;
    v7 = CUtlString::operator char const *(this: &this->m_FileName);
    LOBYTE(v6) = v6->IsFileInPerforce(this: p4, a2: v7);
    v19 = p4->__vftable;
    v8 = CUtlString::operator char const *(this: &this->m_FileName);
    v9 = v19->GetFileState(this: p4, a2: v8) != P4FILE_UNOPENED;
    if ( (_BYTE)v6 == 0 || v9 )
    {
      this->m_CurrentState = STATE_SHOWING_MAKE_FILE_WRITEABLE_DIALOG;
      v10 = CUtlString::Get(this: &this->m_FileName);
      V_snprintf(
        pDest: pBuf,
        maxLen: 1024,
        pFormat: "Encountered read-only file. Should it be made writeable?\n\n\"%s\"\n",
        v10);
      v11 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
      if ( v11 != nullptr )
      {
        v12 = this->GetParent(this);
        v13 = vgui::MessageBox::MessageBox(this: v11, title: "Make File Writeable?", text: pBuf, parent: v12);
      }
      else
      {
        v13 = nullptr;
      }
      v13->AddActionSignalTarget_2(this: v13, a2: this);
      v13->SetOKButtonVisible(this: v13, a2: true);
      v13->SetOKButtonText_2(this: v13, a2: "Yes");
      vgui::MessageBox::SetCancelButtonVisible(this: v13, state: true);
      vgui::MessageBox::SetCancelButtonText(this: v13, buttonText: "No");
      v13->SetCloseButtonVisible(this: v13, a2: false);
      v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v14 != nullptr )
        v15 = KeyValues::KeyValues(this: v14, setName: "MakeFileWriteable");
      else
        v15 = nullptr;
      v13->SetCommand(this: v13, a2: v15);
      v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v16 != nullptr )
        v17 = KeyValues::KeyValues(this: v16, setName: "CancelMakeFileWriteable");
      else
        v17 = nullptr;
      vgui::MessageBox::SetCancelCommand(this: v13, command: v17);
      v13->DoModal_2(this: v13, a2: nullptr);
    }
    else
    {
      vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_CHECKED_OUT);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4380
// Name: private: virtual void vgui::FileOpenStateMachine::OnPerforceQueryCompleted(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnPerforceQueryCompleted(
        vgui::FileOpenStateMachine *this,
        KeyValues *pKeyValues)
{
  vgui::FileOpenStateMachine::FOSMState_t m_CurrentState; // eax

  m_CurrentState = this->m_CurrentState;
  if ( m_CurrentState == STATE_SHOWING_CHECK_OUT_DIALOG )
  {
    if ( KeyValues::GetInt(this: pKeyValues, keyName: "operationPerformed", defaultValue: 0) != 0 )
      vgui::FileOpenStateMachine::MakeFileWriteableDialog(this);
    else
      vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_CHECKED_OUT);
  }
  else if ( m_CurrentState == STATE_SHOWING_PERFORCE_ADD_DIALOG )
  {
    if ( (*((_BYTE *)this + 428) & 4) != 0 )
      vgui::FileOpenStateMachine::OpenFileDialog(this);
    else
      vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C43E0
// Name: private: virtual void vgui::FileOpenStateMachine::OnSaveFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnSaveFile(vgui::FileOpenStateMachine *this)
{
  const char *v2; // eax
  vgui::FileOpenDialog *v3; // edi
  vgui::Panel *v4; // eax
  vgui::FileOpenDialog *v5; // edi
  vgui::IFileOpenStateMachineClient_vtbl *v6; // ebx
  const char *v7; // eax
  KeyValues *m_pContextKeyValues; // [esp-8h] [ebp-10h]

  if ( *CUtlString::operator char const *(this: &this->m_FileName) != 0
    && (v2 = CUtlString::operator char const *(this: &this->m_FileName), V_IsAbsolutePath(pStr: v2)) )
  {
    vgui::FileOpenStateMachine::CheckOutDialog(this);
  }
  else
  {
    this->m_CurrentState = STATE_SHOWING_SAVE_DIALOG;
    v3 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
    if ( v3 != nullptr )
    {
      v4 = this->GetParent(this);
      v5 = vgui::FileOpenDialog::FileOpenDialog(
             this: v3,
             parent: v4,
             title: "Save As",
             bOpenOnly: false,
             pContextKeyValues: nullptr);
    }
    else
    {
      v5 = nullptr;
    }
    v6 = this->m_pClient->__vftable;
    m_pContextKeyValues = this->m_pContextKeyValues;
    v7 = CUtlString::operator char const *(this: &this->m_SaveFileType);
    v6->SetupFileOpenDialog(this: this->m_pClient, a2: v5, a3: false, a4: v7, a5: m_pContextKeyValues);
    v5->AddActionSignalTarget_2(this: v5, a2: this);
    vgui::FileOpenDialog::DoModal(this: v5, bUnused: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C44A0
// Name: private: virtual void vgui::FileOpenStateMachine::OnMarkNotDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnMarkNotDirty(vgui::FileOpenStateMachine *this)
{
  if ( (*((_BYTE *)this + 428) & 4) != 0 )
    vgui::FileOpenStateMachine::OpenFileDialog(this);
  else
    vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
}

//------------------------------------------------------------------------------
// Address: 0x102C44C0
// Name: private: void vgui::FileOpenStateMachine::CheckOutDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::CheckOutDialog(vgui::FileOpenStateMachine *this)
{
  vgui::Panel *v2; // eax
  const char *v3; // [esp-10h] [ebp-14h]

  if ( (*((_BYTE *)this + 428) & 1) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_CHECK_OUT_DIALOG;
    v3 = CUtlString::operator char const *(this: &this->m_FileName);
    v2 = this->GetParent(this);
    ShowPerforceQuery(
      pParent: v2,
      pFileName: v3,
      pActionSignalTarget: this,
      pKeyValues: nullptr,
      actionFilter: PERFORCE_ACTION_FILE_EDIT);
  }
  else
  {
    vgui::FileOpenStateMachine::WriteFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4510
// Name: private: void vgui::FileOpenStateMachine::OverwriteFileDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OverwriteFileDialog(vgui::FileOpenStateMachine *this)
{
  IBaseFileSystem_vtbl *v1; // ebx
  const char *v3; // eax
  vgui::Panel *v4; // eax
  const char *v5; // eax
  vgui::MessageBox *v6; // esi
  vgui::Panel *v7; // eax
  vgui::MessageBox *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  const char *v13; // [esp-10h] [ebp-41Ch]
  char pBuf[1024]; // [esp+Ch] [ebp-400h] BYREF

  v1 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v3 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v1->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: nullptr) )
  {
    this->m_CurrentState = STATE_SHOWING_OVERWRITE_DIALOG;
    v5 = CUtlString::Get(this: &this->m_FileName);
    V_snprintf(pDest: pBuf, maxLen: 1024, pFormat: "File already exists. Overwrite it?\n\n\"%s\"\n", v5);
    v6 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v6 != nullptr )
    {
      v7 = this->GetParent(this);
      v8 = vgui::MessageBox::MessageBox(this: v6, title: "Overwrite Existing File?", text: pBuf, parent: v7);
    }
    else
    {
      v8 = nullptr;
    }
    v8->AddActionSignalTarget_2(this: v8, a2: this);
    v8->SetOKButtonVisible(this: v8, a2: true);
    v8->SetOKButtonText_2(this: v8, a2: "Yes");
    vgui::MessageBox::SetCancelButtonVisible(this: v8, state: true);
    vgui::MessageBox::SetCancelButtonText(this: v8, buttonText: "No");
    v8->SetCloseButtonVisible(this: v8, a2: false);
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
      v10 = KeyValues::KeyValues(this: v9, setName: "OverwriteFile");
    else
      v10 = nullptr;
    v8->SetCommand(this: v8, a2: v10);
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "CancelOverwriteFile");
    else
      v12 = nullptr;
    vgui::MessageBox::SetCancelCommand(this: v8, command: v12);
    v8->DoModal_2(this: v8, a2: nullptr);
  }
  else if ( (*((_BYTE *)this + 428) & 1) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_CHECK_OUT_DIALOG;
    v13 = CUtlString::operator char const *(this: &this->m_FileName);
    v4 = this->GetParent(this);
    ShowPerforceQuery(
      pParent: v4,
      pFileName: v13,
      pActionSignalTarget: this,
      pKeyValues: nullptr,
      actionFilter: PERFORCE_ACTION_FILE_EDIT);
  }
  else
  {
    vgui::FileOpenStateMachine::WriteFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C46B0
// Name: private: virtual void vgui::FileOpenStateMachine::OnFileSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnFileSelected(vgui::FileOpenStateMachine *this, KeyValues *pKeyValues)
{
  vgui::FileOpenStateMachine::FOSMState_t m_CurrentState; // eax
  __m128i *String; // eax
  __m128i *v5; // eax
  __m128i *v6; // eax
  __m128i *v7; // eax

  m_CurrentState = this->m_CurrentState;
  if ( m_CurrentState == STATE_SHOWING_SAVE_DIALOG )
  {
    String = (__m128i *)KeyValues::GetString(this: pKeyValues, keyName: "fullpath", defaultValue: defaultValue);
    CUtlString::operator=(this: &this->m_FileName, src: String);
    v5 = (__m128i *)KeyValues::GetString(this: pKeyValues, keyName: "filterinfo", defaultValue: defaultValue);
    if ( v5 != nullptr )
      CUtlString::operator=(this: &this->m_SaveFileType, src: v5);
    vgui::FileOpenStateMachine::OverwriteFileDialog(this);
  }
  else if ( m_CurrentState == STATE_SHOWING_OPEN_DIALOG )
  {
    v6 = (__m128i *)KeyValues::GetString(this: pKeyValues, keyName: "fullpath", defaultValue: defaultValue);
    CUtlString::operator=(this: &this->m_FileName, src: v6);
    v7 = (__m128i *)KeyValues::GetString(this: pKeyValues, keyName: "filterinfo", defaultValue: defaultValue);
    if ( v7 != nullptr )
      CUtlString::operator=(this: &this->m_OpenFileType, src: v7);
    vgui::FileOpenStateMachine::ReadFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4770
// Name: public: virtual vgui::FileOpenStateMachine::~FileOpenStateMachine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::~FileOpenStateMachine(vgui::FileOpenStateMachine *this)
{
  KeyValues *m_pContextKeyValues; // ecx

  m_pContextKeyValues = this->m_pContextKeyValues;
  this->__vftable = (vgui::FileOpenStateMachine_vtbl *)&vgui::FileOpenStateMachine::`vftable';
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->m_OpenFileName.m_Storage.m_nActualLength = 0;
  if ( this->m_OpenFileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OpenFileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OpenFileName.m_Storage.m_Memory.m_pMemory);
      this->m_OpenFileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_OpenFileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_OpenFileType.m_Storage.m_nActualLength = 0;
  if ( this->m_OpenFileType.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OpenFileType.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OpenFileType.m_Storage.m_Memory.m_pMemory);
      this->m_OpenFileType.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_OpenFileType.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_SaveFileType.m_Storage.m_nActualLength = 0;
  if ( this->m_SaveFileType.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SaveFileType.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SaveFileType.m_Storage.m_Memory.m_pMemory);
      this->m_SaveFileType.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_SaveFileType.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FileName.m_Storage.m_nActualLength = 0;
  if ( this->m_FileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FileName.m_Storage.m_Memory.m_pMemory);
      this->m_FileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_FileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102C4870
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::FileOpenStateMachine::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::FileOpenStateMachine::GetMessageMap(vgui::FileOpenStateMachine *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::FileOpenStateMachine::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::FileOpenStateMachine::GetMessageMap'::`2'::s_pMap;
  `vgui::FileOpenStateMachine::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
  `vgui::FileOpenStateMachine::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C48A0
// Name: public: virtual struct PanelAnimationMap __near * vgui::FileOpenStateMachine::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::FileOpenStateMachine::GetAnimMap(vgui::FileOpenStateMachine *this)
{
  return FindOrAddPanelAnimationMap(className: "FileOpenStateMachine");
}

//------------------------------------------------------------------------------
// Address: 0x102C48B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::FileOpenStateMachine::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::FileOpenStateMachine::GetKBMap(vgui::FileOpenStateMachine *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::FileOpenStateMachine::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::FileOpenStateMachine::GetKBMap'::`2'::s_pMap;
  `vgui::FileOpenStateMachine::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"FileOpenStateMachine");
  `vgui::FileOpenStateMachine::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C4910
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "FileSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C49A0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{848,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FileSelectionCancelled";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4A30
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PerforceQueryCompleted";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4AC0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MakeFileWriteable";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4B50
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CancelMakeFileWriteable";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4BE0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{864,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OverwriteFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4C70
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{868,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CancelOverwriteFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4D00
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::RichText::`vcall'{872,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnSaveFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4D90
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::RichText::`vcall'{876,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnMarkNotDirty";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4E20
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{880,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnCancelSaveDocument";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C4EB0
// Name: public: vgui::FileOpenStateMachine::FileOpenStateMachine(class vgui::Panel __near *,class vgui::IFileOpenStateMachineClient __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FileOpenStateMachine *__thiscall vgui::FileOpenStateMachine::FileOpenStateMachine(
        vgui::FileOpenStateMachine *this,
        vgui::Panel *pParent,
        vgui::IFileOpenStateMachineClient *pClient)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent: pParent, panelName: (__m128i *)"FileOpenStateMachine");
  this->__vftable = (vgui::FileOpenStateMachine_vtbl *)&vgui::FileOpenStateMachine::`vftable';
  if ( `vgui::FileOpenStateMachine::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::FileOpenStateMachine::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"FileOpenStateMachine");
    v4->pfnClassName = vgui::FileOpenStateMachine::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Panel");
  }
  if ( `vgui::FileOpenStateMachine::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::FileOpenStateMachine::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "FileOpenStateMachine");
    v5->pfnClassName = vgui::FileOpenStateMachine::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::FileOpenStateMachine::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::FileOpenStateMachine::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"FileOpenStateMachine");
    v6->pfnClassName = vgui::FileOpenStateMachine::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Panel");
  }
  vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_FileName);
  CUtlString::CUtlString(this: &this->m_SaveFileType);
  CUtlString::CUtlString(this: &this->m_OpenFileType);
  CUtlString::CUtlString(this: &this->m_OpenFileName);
  this->m_pClient = pClient;
  this->m_CompletionState = SUCCESSFUL;
  this->m_CurrentState = STATE_NONE;
  this->m_pContextKeyValues = nullptr;
  vgui::Panel::SetVisible(this, state: false);
  return this;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1031DD10
// Name: public: static char const __near * vgui::FileOpenStateMachine::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::FileOpenStateMachine::GetPanelClassName()
{
  return "FileOpenStateMachine";
}

//------------------------------------------------------------------------------
// Address: 0x1031DD20
// Name: private: void vgui::FileOpenStateMachine::SetCompletionState(enum vgui::FileOpenStateMachine::CompletionState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::SetCompletionState(
        vgui::FileOpenStateMachine *this,
        vgui::FileOpenStateMachine::CompletionState_t state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  char *v5; // eax
  CUtlString *p_m_OpenFileType; // ecx
  char *v7; // eax

  this->m_CompletionState = state;
  if ( state != IN_PROGRESS )
  {
    this->m_CurrentState = STATE_NONE;
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "FileStateMachineFinished");
    else
      v4 = nullptr;
    KeyValues::SetInt(this: v4, keyName: "completionState", value: this->m_CompletionState);
    KeyValues::SetInt(this: v4, keyName: "wroteFile", value: (*((_BYTE *)this + 428) & 8) != 0);
    v5 = CUtlString::Get(this: &this->m_FileName);
    KeyValues::SetString(this: v4, keyName: "fullPath", value: v5);
    p_m_OpenFileType = &this->m_OpenFileType;
    if ( (*((_BYTE *)this + 428) & 4) == 0 )
      p_m_OpenFileType = &this->m_SaveFileType;
    v7 = CUtlString::Get(this: p_m_OpenFileType);
    KeyValues::SetString(this: v4, keyName: "fileType", value: v7);
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v4, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    this->PostActionSignal(this, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031DE00
// Name: private: virtual void vgui::FileOpenStateMachine::OnCancelOverwriteFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnCancelOverwriteFile(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_OVERWRITTEN);
}

//------------------------------------------------------------------------------
// Address: 0x1031DE10
// Name: private: virtual void vgui::FileOpenStateMachine::OnFileSelectionCancelled(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnFileSelectionCancelled(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::FOSMState_t m_CurrentState; // eax

  m_CurrentState = this->m_CurrentState;
  if ( m_CurrentState == STATE_SHOWING_SAVE_DIALOG )
  {
    vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_SAVE_NAME_NOT_SPECIFIED);
  }
  else if ( m_CurrentState == STATE_SHOWING_OPEN_DIALOG )
  {
    vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_OPEN_NAME_NOT_SPECIFIED);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031DE30
// Name: private: virtual void vgui::FileOpenStateMachine::OnCancelMakeFileWriteable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnCancelMakeFileWriteable(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_MADE_WRITEABLE);
}

//------------------------------------------------------------------------------
// Address: 0x1031DE40
// Name: private: virtual void vgui::FileOpenStateMachine::OnCancelSaveDocument(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnCancelSaveDocument(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_SAVE_CANCELLED);
}

//------------------------------------------------------------------------------
// Address: 0x1031DE50
// Name: public: void vgui::FileOpenStateMachine::SaveFile(class KeyValues __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::SaveFile(
        vgui::FileOpenStateMachine *this,
        KeyValues *pContextKeyValues,
        char *pFileName,
        char *pFileType,
        char nFlags)
{
  KeyValues *m_pContextKeyValues; // ecx
  int v7; // eax
  char v8; // al
  char v9; // cl
  vgui::Panel *v10; // eax
  const char *v11; // [esp-14h] [ebp-20h]
  const char *v12; // [esp-10h] [ebp-1Ch]

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->m_CompletionState = IN_PROGRESS;
  this->m_pContextKeyValues = pContextKeyValues;
  CUtlString::operator=(this: &this->m_FileName, src: pFileName);
  CUtlString::operator=(this: &this->m_SaveFileType, src: pFileType);
  CUtlString::operator=(this: &this->m_OpenFileType, src: nullptr);
  CUtlString::operator=(this: &this->m_OpenFileName, src: nullptr);
  if ( g_pFullFileSystem->IsSteam(this: g_pFullFileSystem)
    || (v7 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-nop4") != 0) )
  {
    v8 = nFlags & 0xFE;
  }
  else
  {
    v8 = nFlags;
  }
  v9 = v8 & 1 | *((_BYTE *)this + 428) & 0xF0 | (2 * ((v8 & 2) != 0));
  *((_BYTE *)this + 428) = v9;
  if ( (v9 & 2) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_SAVE_DIRTY_FILE_DIALOG;
    v12 = CUtlString::operator char const *(this: &this->m_SaveFileType);
    v11 = CUtlString::operator char const *(this: &this->m_FileName);
    v10 = this->GetParent(this);
    ShowSaveDocumentQuery(
      pParent: v10,
      pFileName: v11,
      pFileType: v12,
      nContext: 0,
      pActionSignalTarget: this,
      pPostSaveCommand: nullptr);
  }
  else
  {
    this->OnSaveFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031DF60
// Name: private: void vgui::FileOpenStateMachine::ReadFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::ReadFile(vgui::FileOpenStateMachine *this)
{
  vgui::IFileOpenStateMachineClient *m_pClient; // eax
  vgui::IFileOpenStateMachineClient_vtbl *v3; // edi
  const char *v4; // eax
  const char *v5; // [esp-8h] [ebp-10h]
  KeyValues *m_pContextKeyValues; // [esp-4h] [ebp-Ch]

  m_pClient = this->m_pClient;
  m_pContextKeyValues = this->m_pContextKeyValues;
  this->m_CurrentState = STATE_READING_FILE;
  v3 = m_pClient->__vftable;
  v5 = CUtlString::operator char const *(this: &this->m_OpenFileType);
  v4 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v3->OnReadFileFromDisk(this: this->m_pClient, a2: v4, a3: v5, a4: m_pContextKeyValues) )
    vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
  else
    vgui::FileOpenStateMachine::SetCompletionState(this, state: ERROR_READING_FILE);
}

//------------------------------------------------------------------------------
// Address: 0x1031DFD0
// Name: private: void vgui::FileOpenStateMachine::OpenFileDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OpenFileDialog(vgui::FileOpenStateMachine *this)
{
  CUtlString *p_m_OpenFileName; // edi
  vgui::FileOpenDialog *v3; // edi
  vgui::Panel *v4; // eax
  vgui::FileOpenDialog *v5; // edi
  vgui::IFileOpenStateMachineClient_vtbl *v6; // ebx
  const char *v7; // eax
  KeyValues *m_pContextKeyValues; // [esp-8h] [ebp-10h]

  p_m_OpenFileName = &this->m_OpenFileName;
  this->m_CurrentState = STATE_SHOWING_OPEN_DIALOG;
  if ( CUtlString::Length(this: &this->m_OpenFileName) != 0 )
  {
    CUtlString::operator=(this: &this->m_FileName, src: p_m_OpenFileName);
    vgui::FileOpenStateMachine::ReadFile(this);
  }
  else
  {
    v3 = (vgui::FileOpenDialog *)operator new(nSize: 0x6B0u);
    if ( v3 != nullptr )
    {
      v4 = this->GetParent(this);
      v5 = vgui::FileOpenDialog::FileOpenDialog(
             this: v3,
             parent: v4,
             title: "Open",
             bOpenOnly: true,
             pContextKeyValues: nullptr);
    }
    else
    {
      v5 = nullptr;
    }
    v6 = this->m_pClient->__vftable;
    m_pContextKeyValues = this->m_pContextKeyValues;
    v7 = CUtlString::operator char const *(this: &this->m_OpenFileType);
    v6->SetupFileOpenDialog(this: this->m_pClient, a2: v5, a3: true, a4: v7, a5: m_pContextKeyValues);
    v5->AddActionSignalTarget_2(this: v5, a2: this);
    vgui::FileOpenDialog::DoModal(this: v5, bUnused: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031E080
// Name: public: void vgui::FileOpenStateMachine::OpenFile(char const __near *,class KeyValues __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OpenFile(
        vgui::FileOpenStateMachine *this,
        char *pOpenFileType,
        KeyValues *pContextKeyValues,
        char *pSaveFileName,
        char *pSaveFileType,
        char nFlags)
{
  KeyValues *m_pContextKeyValues; // ecx
  char v8; // cl
  vgui::Panel *v9; // eax
  const char *v10; // [esp-14h] [ebp-20h]
  const char *v11; // [esp-10h] [ebp-1Ch]

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->m_CompletionState = IN_PROGRESS;
  this->m_pContextKeyValues = pContextKeyValues;
  CUtlString::operator=(this: &this->m_FileName, src: pSaveFileName);
  CUtlString::operator=(this: &this->m_SaveFileType, src: pSaveFileType);
  CUtlString::operator=(this: &this->m_OpenFileType, src: pOpenFileType);
  CUtlString::operator=(this: &this->m_OpenFileName, src: nullptr);
  v8 = nFlags & 1 | *((_BYTE *)this + 428) & 0xF4 | (2 * (((nFlags & 2) != 0) | 2));
  *((_BYTE *)this + 428) = v8;
  if ( (v8 & 2) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_SAVE_DIRTY_FILE_DIALOG;
    v11 = CUtlString::operator char const *(this: &this->m_SaveFileType);
    v10 = CUtlString::operator char const *(this: &this->m_FileName);
    v9 = this->GetParent(this);
    ShowSaveDocumentQuery(
      pParent: v9,
      pFileName: v10,
      pFileType: v11,
      nContext: 0,
      pActionSignalTarget: this,
      pPostSaveCommand: nullptr);
  }
  else
  {
    vgui::FileOpenStateMachine::OpenFileDialog(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031E160
// Name: public: void vgui::FileOpenStateMachine::OpenFile(char const __near *,char const __near *,class KeyValues __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OpenFile(
        vgui::FileOpenStateMachine *this,
        char *pOpenFileName,
        char *pOpenFileType,
        KeyValues *pContextKeyValues,
        char *pSaveFileName,
        char *pSaveFileType,
        char nFlags)
{
  KeyValues *m_pContextKeyValues; // ecx
  vgui::Panel *v9; // eax
  const char *v10; // [esp-14h] [ebp-20h]
  const char *v11; // [esp-10h] [ebp-1Ch]

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->m_CompletionState = IN_PROGRESS;
  this->m_pContextKeyValues = pContextKeyValues;
  CUtlString::operator=(this: &this->m_FileName, src: pSaveFileName);
  CUtlString::operator=(this: &this->m_SaveFileType, src: pSaveFileType);
  CUtlString::operator=(this: &this->m_OpenFileType, src: pOpenFileType);
  *((_BYTE *)this + 428) = nFlags & 1 | *((_BYTE *)this + 428) & 0xF4 | (2 * (((nFlags & 2) != 0) | 2));
  CUtlString::operator=(this: &this->m_OpenFileName, src: pOpenFileName);
  if ( (*((_BYTE *)this + 428) & 2) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_SAVE_DIRTY_FILE_DIALOG;
    v11 = CUtlString::operator char const *(this: &this->m_SaveFileType);
    v10 = CUtlString::operator char const *(this: &this->m_FileName);
    v9 = this->GetParent(this);
    ShowSaveDocumentQuery(
      pParent: v9,
      pFileName: v10,
      pFileType: v11,
      nContext: 0,
      pActionSignalTarget: this,
      pPostSaveCommand: nullptr);
  }
  else
  {
    vgui::FileOpenStateMachine::OpenFileDialog(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031E290
// Name: private: void vgui::FileOpenStateMachine::WriteFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::WriteFile(vgui::FileOpenStateMachine *this)
{
  vgui::IFileOpenStateMachineClient *m_pClient; // eax
  vgui::IFileOpenStateMachineClient_vtbl *v3; // ebx
  const char *v4; // eax
  char v5; // al
  vgui::Panel *v6; // eax
  const char *v7; // [esp-10h] [ebp-1Ch]
  const char *v8; // [esp-8h] [ebp-14h]
  KeyValues *m_pContextKeyValues; // [esp-4h] [ebp-10h]

  m_pClient = this->m_pClient;
  m_pContextKeyValues = this->m_pContextKeyValues;
  this->m_CurrentState = STATE_WRITING_FILE;
  v3 = m_pClient->__vftable;
  v8 = CUtlString::operator char const *(this: &this->m_SaveFileType);
  v4 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v3->OnWriteFileToDisk(this: this->m_pClient, a2: v4, a3: v8, a4: m_pContextKeyValues) )
  {
    *((_BYTE *)this + 428) |= 8u;
    v5 = *((_BYTE *)this + 428);
    if ( (v5 & 1) != 0 )
    {
      this->m_CurrentState = STATE_SHOWING_PERFORCE_ADD_DIALOG;
      v7 = CUtlString::operator char const *(this: &this->m_FileName);
      v6 = this->GetParent(this);
      ShowPerforceQuery(
        pParent: v6,
        pFileName: v7,
        pActionSignalTarget: this,
        pKeyValues: nullptr,
        actionFilter: nullptr);
    }
    else if ( (v5 & 4) != 0 )
    {
      vgui::FileOpenStateMachine::OpenFileDialog(this);
    }
    else
    {
      vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
    }
  }
  else
  {
    vgui::FileOpenStateMachine::SetCompletionState(this, state: ERROR_WRITING_FILE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031E340
// Name: private: virtual void vgui::FileOpenStateMachine::OnMakeFileWriteable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnMakeFileWriteable(vgui::FileOpenStateMachine *this)
{
  IBaseFileSystem_vtbl *v1; // edi
  const char *v3; // eax

  v1 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v3 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v1->SetFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: true, a4: nullptr) )
    vgui::FileOpenStateMachine::WriteFile(this);
  else
    vgui::FileOpenStateMachine::SetCompletionState(this, state: ERROR_MAKING_FILE_WRITEABLE);
}

//------------------------------------------------------------------------------
// Address: 0x1031E390
// Name: private: void vgui::FileOpenStateMachine::MakeFileWriteableDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::MakeFileWriteableDialog(vgui::FileOpenStateMachine *this)
{
  IBaseFileSystem_vtbl *v1; // ebx
  const char *v3; // eax
  IBaseFileSystem_vtbl *v4; // ebx
  const char *v5; // eax
  IP4_vtbl *v6; // ebx
  const char *v7; // eax
  const char *v8; // eax
  bool v9; // al
  const char *v10; // eax
  vgui::MessageBox *v11; // esi
  vgui::Panel *v12; // eax
  vgui::MessageBox *v13; // esi
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  char pBuf[1024]; // [esp+Ch] [ebp-404h] BYREF
  IP4_vtbl *v19; // [esp+40Ch] [ebp-4h]

  v1 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v3 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( !v1->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: nullptr)
    || (v4 = g_pFullFileSystem->IBaseFileSystem::__vftable,
        v5 = CUtlString::operator char const *(this: &this->m_FileName),
        v4->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5, a3: nullptr)) )
  {
    vgui::FileOpenStateMachine::WriteFile(this);
  }
  else
  {
    v6 = p4->__vftable;
    v7 = CUtlString::operator char const *(this: &this->m_FileName);
    LOBYTE(v6) = v6->IsFileInPerforce(this: p4, a2: v7);
    v19 = p4->__vftable;
    v8 = CUtlString::operator char const *(this: &this->m_FileName);
    v9 = v19->GetFileState(this: p4, a2: v8) != P4FILE_UNOPENED;
    if ( (_BYTE)v6 == 0 || v9 )
    {
      this->m_CurrentState = STATE_SHOWING_MAKE_FILE_WRITEABLE_DIALOG;
      v10 = CUtlString::Get(this: &this->m_FileName);
      V_snprintf(
        pDest: pBuf,
        maxLen: 0x400u,
        pFormat: "Encountered read-only file. Should it be made writeable?\n\n\"%s\"\n",
        v10);
      v11 = (vgui::MessageBox *)operator new(nSize: 0x234u);
      if ( v11 != nullptr )
      {
        v12 = this->GetParent(this);
        v13 = vgui::MessageBox::MessageBox(this: v11, title: "Make File Writeable?", text: pBuf, parent: v12);
      }
      else
      {
        v13 = nullptr;
      }
      v13->AddActionSignalTarget_2(this: v13, a2: this);
      v13->SetOKButtonVisible(this: v13, a2: true);
      v13->SetOKButtonText_2(this: v13, a2: "Yes");
      vgui::MessageBox::SetCancelButtonVisible(this: v13, state: true);
      vgui::MessageBox::SetCancelButtonText(this: v13, buttonText: "No");
      v13->SetCloseButtonVisible(this: v13, a2: false);
      v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v14 != nullptr )
        v15 = KeyValues::KeyValues(this: v14, setName: "MakeFileWriteable");
      else
        v15 = nullptr;
      v13->SetCommand(this: v13, a2: v15);
      v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v16 != nullptr )
        v17 = KeyValues::KeyValues(this: v16, setName: "CancelMakeFileWriteable");
      else
        v17 = nullptr;
      vgui::MessageBox::SetCancelCommand(this: v13, command: v17);
      v13->DoModal_2(this: v13, a2: nullptr);
    }
    else
    {
      vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_CHECKED_OUT);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031E590
// Name: private: virtual void vgui::FileOpenStateMachine::OnPerforceQueryCompleted(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnPerforceQueryCompleted(
        vgui::FileOpenStateMachine *this,
        KeyValues *pKeyValues)
{
  vgui::FileOpenStateMachine::FOSMState_t m_CurrentState; // eax

  m_CurrentState = this->m_CurrentState;
  if ( m_CurrentState == STATE_SHOWING_CHECK_OUT_DIALOG )
  {
    if ( KeyValues::GetInt(this: pKeyValues, keyName: "operationPerformed", defaultValue: 0) != 0 )
      vgui::FileOpenStateMachine::MakeFileWriteableDialog(this);
    else
      vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_CHECKED_OUT);
  }
  else if ( m_CurrentState == STATE_SHOWING_PERFORCE_ADD_DIALOG )
  {
    if ( (*((_BYTE *)this + 428) & 4) != 0 )
      vgui::FileOpenStateMachine::OpenFileDialog(this);
    else
      vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031E5F0
// Name: private: void vgui::FileOpenStateMachine::CheckOutDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::CheckOutDialog(vgui::FileOpenStateMachine *this)
{
  vgui::Panel *v2; // eax
  const char *v3; // [esp-10h] [ebp-14h]

  if ( (*((_BYTE *)this + 428) & 1) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_CHECK_OUT_DIALOG;
    v3 = CUtlString::operator char const *(this: &this->m_FileName);
    v2 = this->GetParent(this);
    ShowPerforceQuery(
      pParent: v2,
      pFileName: v3,
      pActionSignalTarget: this,
      pKeyValues: nullptr,
      actionFilter: (const char *)1);
  }
  else
  {
    vgui::FileOpenStateMachine::WriteFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031E640
// Name: private: virtual void vgui::FileOpenStateMachine::OnSaveFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnSaveFile(vgui::FileOpenStateMachine *this)
{
  const char *v2; // eax
  vgui::FileOpenDialog *v3; // edi
  vgui::Panel *v4; // eax
  vgui::FileOpenDialog *v5; // edi
  vgui::IFileOpenStateMachineClient_vtbl *v6; // ebx
  const char *v7; // eax
  KeyValues *m_pContextKeyValues; // [esp-8h] [ebp-10h]

  if ( *CUtlString::operator char const *(this: &this->m_FileName) != 0
    && (v2 = CUtlString::operator char const *(this: &this->m_FileName), V_IsAbsolutePath(pStr: v2)) )
  {
    vgui::FileOpenStateMachine::CheckOutDialog(this);
  }
  else
  {
    this->m_CurrentState = STATE_SHOWING_SAVE_DIALOG;
    v3 = (vgui::FileOpenDialog *)operator new(nSize: 0x6B0u);
    if ( v3 != nullptr )
    {
      v4 = this->GetParent(this);
      v5 = vgui::FileOpenDialog::FileOpenDialog(
             this: v3,
             parent: v4,
             title: "Save As",
             bOpenOnly: false,
             pContextKeyValues: nullptr);
    }
    else
    {
      v5 = nullptr;
    }
    v6 = this->m_pClient->__vftable;
    m_pContextKeyValues = this->m_pContextKeyValues;
    v7 = CUtlString::operator char const *(this: &this->m_SaveFileType);
    v6->SetupFileOpenDialog(this: this->m_pClient, a2: v5, a3: false, a4: v7, a5: m_pContextKeyValues);
    v5->AddActionSignalTarget_2(this: v5, a2: this);
    vgui::FileOpenDialog::DoModal(this: v5, bUnused: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031E700
// Name: private: virtual void vgui::FileOpenStateMachine::OnMarkNotDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnMarkNotDirty(vgui::FileOpenStateMachine *this)
{
  if ( (*((_BYTE *)this + 428) & 4) != 0 )
    vgui::FileOpenStateMachine::OpenFileDialog(this);
  else
    vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
}

//------------------------------------------------------------------------------
// Address: 0x1031E720
// Name: private: void vgui::FileOpenStateMachine::OverwriteFileDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OverwriteFileDialog(vgui::FileOpenStateMachine *this)
{
  IBaseFileSystem_vtbl *v1; // ebx
  const char *v3; // eax
  vgui::Panel *v4; // eax
  const char *v5; // eax
  vgui::MessageBox *v6; // esi
  vgui::Panel *v7; // eax
  vgui::MessageBox *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  const char *v13; // [esp-10h] [ebp-41Ch]
  char pBuf[1024]; // [esp+Ch] [ebp-400h] BYREF

  v1 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v3 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v1->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: nullptr) )
  {
    this->m_CurrentState = STATE_SHOWING_OVERWRITE_DIALOG;
    v5 = CUtlString::Get(this: &this->m_FileName);
    V_snprintf(pDest: pBuf, maxLen: 0x400u, pFormat: "File already exists. Overwrite it?\n\n\"%s\"\n", v5);
    v6 = (vgui::MessageBox *)operator new(nSize: 0x234u);
    if ( v6 != nullptr )
    {
      v7 = this->GetParent(this);
      v8 = vgui::MessageBox::MessageBox(this: v6, title: "Overwrite Existing File?", text: pBuf, parent: v7);
    }
    else
    {
      v8 = nullptr;
    }
    v8->AddActionSignalTarget_2(this: v8, a2: this);
    v8->SetOKButtonVisible(this: v8, a2: true);
    v8->SetOKButtonText_2(this: v8, a2: "Yes");
    vgui::MessageBox::SetCancelButtonVisible(this: v8, state: true);
    vgui::MessageBox::SetCancelButtonText(this: v8, buttonText: "No");
    v8->SetCloseButtonVisible(this: v8, a2: false);
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
      v10 = KeyValues::KeyValues(this: v9, setName: "OverwriteFile");
    else
      v10 = nullptr;
    v8->SetCommand(this: v8, a2: v10);
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "CancelOverwriteFile");
    else
      v12 = nullptr;
    vgui::MessageBox::SetCancelCommand(this: v8, command: v12);
    v8->DoModal_2(this: v8, a2: nullptr);
  }
  else if ( (*((_BYTE *)this + 428) & 1) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_CHECK_OUT_DIALOG;
    v13 = CUtlString::operator char const *(this: &this->m_FileName);
    v4 = this->GetParent(this);
    ShowPerforceQuery(
      pParent: v4,
      pFileName: v13,
      pActionSignalTarget: this,
      pKeyValues: nullptr,
      actionFilter: (const char *)1);
  }
  else
  {
    vgui::FileOpenStateMachine::WriteFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031E8C0
// Name: private: virtual void vgui::FileOpenStateMachine::OnFileSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnFileSelected(vgui::FileOpenStateMachine *this, KeyValues *pKeyValues)
{
  vgui::FileOpenStateMachine::FOSMState_t m_CurrentState; // eax
  char *String; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax

  m_CurrentState = this->m_CurrentState;
  if ( m_CurrentState == STATE_SHOWING_SAVE_DIALOG )
  {
    String = KeyValues::GetString(this: pKeyValues, keyName: "fullpath", defaultValue: &var);
    CUtlString::operator=(this: &this->m_FileName, src: String);
    v5 = KeyValues::GetString(this: pKeyValues, keyName: "filterinfo", defaultValue: &var);
    if ( v5 != nullptr )
      CUtlString::operator=(this: &this->m_SaveFileType, src: v5);
    vgui::FileOpenStateMachine::OverwriteFileDialog(this);
  }
  else if ( m_CurrentState == STATE_SHOWING_OPEN_DIALOG )
  {
    v6 = KeyValues::GetString(this: pKeyValues, keyName: "fullpath", defaultValue: &var);
    CUtlString::operator=(this: &this->m_FileName, src: v6);
    v7 = KeyValues::GetString(this: pKeyValues, keyName: "filterinfo", defaultValue: &var);
    if ( v7 != nullptr )
      CUtlString::operator=(this: &this->m_OpenFileType, src: v7);
    vgui::FileOpenStateMachine::ReadFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031E980
// Name: public: virtual vgui::FileOpenStateMachine::~FileOpenStateMachine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::~FileOpenStateMachine(vgui::FileOpenStateMachine *this)
{
  KeyValues *m_pContextKeyValues; // ecx

  m_pContextKeyValues = this->m_pContextKeyValues;
  this->__vftable = (vgui::FileOpenStateMachine_vtbl *)&vgui::FileOpenStateMachine::`vftable';
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->m_OpenFileName.m_Storage.m_nActualLength = 0;
  if ( this->m_OpenFileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OpenFileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OpenFileName.m_Storage.m_Memory.m_pMemory);
      this->m_OpenFileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_OpenFileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_OpenFileType.m_Storage.m_nActualLength = 0;
  if ( this->m_OpenFileType.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OpenFileType.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OpenFileType.m_Storage.m_Memory.m_pMemory);
      this->m_OpenFileType.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_OpenFileType.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_SaveFileType.m_Storage.m_nActualLength = 0;
  if ( this->m_SaveFileType.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SaveFileType.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SaveFileType.m_Storage.m_Memory.m_pMemory);
      this->m_SaveFileType.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_SaveFileType.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FileName.m_Storage.m_nActualLength = 0;
  if ( this->m_FileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FileName.m_Storage.m_Memory.m_pMemory);
      this->m_FileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_FileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1031EA80
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::FileOpenStateMachine::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::FileOpenStateMachine::GetMessageMap(vgui::FileOpenStateMachine *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::FileOpenStateMachine::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::FileOpenStateMachine::GetMessageMap'::`2'::s_pMap;
  `vgui::FileOpenStateMachine::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
  `vgui::FileOpenStateMachine::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031EAB0
// Name: public: virtual struct PanelAnimationMap __near * vgui::FileOpenStateMachine::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::FileOpenStateMachine::GetAnimMap(vgui::FileOpenStateMachine *this)
{
  return FindOrAddPanelAnimationMap(className: "FileOpenStateMachine");
}

//------------------------------------------------------------------------------
// Address: 0x1031EAC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::FileOpenStateMachine::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::FileOpenStateMachine::GetKBMap(vgui::FileOpenStateMachine *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::FileOpenStateMachine::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::FileOpenStateMachine::GetKBMap'::`2'::s_pMap;
  `vgui::FileOpenStateMachine::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "FileOpenStateMachine");
  `vgui::FileOpenStateMachine::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031EB20
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "FileSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031EBB0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{848,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FileSelectionCancelled";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031EC40
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PerforceQueryCompleted";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031ECD0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MakeFileWriteable";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031ED60
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CancelMakeFileWriteable";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031EDF0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{864,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OverwriteFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031EE80
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{868,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CancelOverwriteFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031EF10
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::RichText::`vcall'{872,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnSaveFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031EFA0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeElementPickerPanel::`vcall'{876,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnMarkNotDirty";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031F030
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSheetSequencePickerPanel::`vcall'{880,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnCancelSaveDocument";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031F0C0
// Name: public: vgui::FileOpenStateMachine::FileOpenStateMachine(class vgui::Panel __near *,class vgui::IFileOpenStateMachineClient __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FileOpenStateMachine *__thiscall vgui::FileOpenStateMachine::FileOpenStateMachine(
        vgui::FileOpenStateMachine *this,
        vgui::Panel *pParent,
        vgui::IFileOpenStateMachineClient *pClient)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent: pParent, panelName: "FileOpenStateMachine");
  this->__vftable = (vgui::FileOpenStateMachine_vtbl *)&vgui::FileOpenStateMachine::`vftable';
  if ( `vgui::FileOpenStateMachine::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::FileOpenStateMachine::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v4->pfnClassName = vgui::FileOpenStateMachine::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::FileOpenStateMachine::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::FileOpenStateMachine::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "FileOpenStateMachine");
    v5->pfnClassName = vgui::FileOpenStateMachine::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::FileOpenStateMachine::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::FileOpenStateMachine::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "FileOpenStateMachine");
    v6->pfnClassName = vgui::FileOpenStateMachine::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_FileName);
  CUtlString::CUtlString(this: &this->m_SaveFileType);
  CUtlString::CUtlString(this: &this->m_OpenFileType);
  CUtlString::CUtlString(this: &this->m_OpenFileName);
  this->m_pClient = pClient;
  this->m_CompletionState = SUCCESSFUL;
  this->m_CurrentState = STATE_NONE;
  this->m_pContextKeyValues = nullptr;
  vgui::Panel::SetVisible(this, state: 0);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0062EE10
// Name: public: static char const __near * vgui::FileOpenStateMachine::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::FileOpenStateMachine::GetPanelClassName()
{
  return "FileOpenStateMachine";
}

//------------------------------------------------------------------------------
// Address: 0x0062EE20
// Name: private: void vgui::FileOpenStateMachine::SetCompletionState(enum vgui::FileOpenStateMachine::CompletionState_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::SetCompletionState(
        vgui::FileOpenStateMachine *this,
        vgui::FileOpenStateMachine::CompletionState_t state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  const char *v5; // eax
  CUtlString *p_m_OpenFileType; // ecx
  const char *v7; // eax

  this->m_CompletionState = state;
  if ( state != IN_PROGRESS )
  {
    this->m_CurrentState = STATE_NONE;
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "FileStateMachineFinished");
    else
      v4 = nullptr;
    KeyValues::SetInt(this: v4, keyName: "completionState", value: this->m_CompletionState);
    KeyValues::SetInt(this: v4, keyName: "wroteFile", value: (*((_BYTE *)this + 428) & 8) != 0);
    v5 = CUtlString::Get(this: &this->m_FileName);
    KeyValues::SetString(this: v4, keyName: "fullPath", value: v5);
    p_m_OpenFileType = &this->m_OpenFileType;
    if ( (*((_BYTE *)this + 428) & 4) == 0 )
      p_m_OpenFileType = &this->m_SaveFileType;
    v7 = CUtlString::Get(this: p_m_OpenFileType);
    KeyValues::SetString(this: v4, keyName: "fileType", value: v7);
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v4, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    this->PostActionSignal(this, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062EF00
// Name: private: virtual void vgui::FileOpenStateMachine::OnCancelOverwriteFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnCancelOverwriteFile(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_OVERWRITTEN);
}

//------------------------------------------------------------------------------
// Address: 0x0062EF10
// Name: private: virtual void vgui::FileOpenStateMachine::OnFileSelectionCancelled(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnFileSelectionCancelled(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::FOSMState_t m_CurrentState; // eax

  m_CurrentState = this->m_CurrentState;
  if ( m_CurrentState == STATE_SHOWING_SAVE_DIALOG )
  {
    vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_SAVE_NAME_NOT_SPECIFIED);
  }
  else if ( m_CurrentState == STATE_SHOWING_OPEN_DIALOG )
  {
    vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_OPEN_NAME_NOT_SPECIFIED);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062EF30
// Name: private: virtual void vgui::FileOpenStateMachine::OnCancelMakeFileWriteable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnCancelMakeFileWriteable(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_MADE_WRITEABLE);
}

//------------------------------------------------------------------------------
// Address: 0x0062EF40
// Name: private: virtual void vgui::FileOpenStateMachine::OnCancelSaveDocument(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnCancelSaveDocument(vgui::FileOpenStateMachine *this)
{
  vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_SAVE_CANCELLED);
}

//------------------------------------------------------------------------------
// Address: 0x0062EF50
// Name: public: void vgui::FileOpenStateMachine::SaveFile(class KeyValues __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::SaveFile(
        vgui::FileOpenStateMachine *this,
        KeyValues *pContextKeyValues,
        char *pFileName,
        char *pFileType,
        char nFlags)
{
  KeyValues *m_pContextKeyValues; // ecx
  int v7; // eax
  char v8; // al
  char v9; // cl
  vgui::Panel *v10; // eax
  const char *v11; // [esp-14h] [ebp-20h]
  const char *v12; // [esp-10h] [ebp-1Ch]

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->m_CompletionState = IN_PROGRESS;
  this->m_pContextKeyValues = pContextKeyValues;
  CUtlString::operator=(this: &this->m_FileName, src: pFileName);
  CUtlString::operator=(this: &this->m_SaveFileType, src: pFileType);
  CUtlString::operator=(this: &this->m_OpenFileType, src: nullptr);
  CUtlString::operator=(this: &this->m_OpenFileName, src: nullptr);
  if ( g_pFullFileSystem->IsSteam(this: g_pFullFileSystem)
    || (v7 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 40))(a1: v7, a2: "-nop4") != 0) )
  {
    v8 = nFlags & 0xFE;
  }
  else
  {
    v8 = nFlags;
  }
  v9 = v8 & 1 | *((_BYTE *)this + 428) & 0xF0 | (2 * ((v8 & 2) != 0));
  *((_BYTE *)this + 428) = v9;
  if ( (v9 & 2) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_SAVE_DIRTY_FILE_DIALOG;
    v12 = CUtlString::operator char const *(this: &this->m_SaveFileType);
    v11 = CUtlString::operator char const *(this: &this->m_FileName);
    v10 = this->GetParent(this);
    ShowSaveDocumentQuery(
      pParent: v10,
      pFileName: v11,
      pFileType: v12,
      nContext: 0,
      pActionSignalTarget: this,
      pPostSaveCommand: nullptr);
  }
  else
  {
    this->OnSaveFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F060
// Name: private: void vgui::FileOpenStateMachine::ReadFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::ReadFile(vgui::FileOpenStateMachine *this)
{
  vgui::IFileOpenStateMachineClient *m_pClient; // eax
  vgui::IFileOpenStateMachineClient_vtbl *v3; // edi
  const char *v4; // eax
  const char *v5; // [esp-8h] [ebp-10h]
  KeyValues *m_pContextKeyValues; // [esp-4h] [ebp-Ch]

  m_pClient = this->m_pClient;
  m_pContextKeyValues = this->m_pContextKeyValues;
  this->m_CurrentState = STATE_READING_FILE;
  v3 = m_pClient->__vftable;
  v5 = CUtlString::operator char const *(this: &this->m_OpenFileType);
  v4 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v3->OnReadFileFromDisk(this: this->m_pClient, a2: v4, a3: v5, a4: m_pContextKeyValues) )
    vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
  else
    vgui::FileOpenStateMachine::SetCompletionState(this, state: ERROR_READING_FILE);
}

//------------------------------------------------------------------------------
// Address: 0x0062F0C0
// Name: private: void vgui::FileOpenStateMachine::OpenFileDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OpenFileDialog(vgui::FileOpenStateMachine *this)
{
  CUtlString *p_m_OpenFileName; // edi
  vgui::FileOpenDialog *v3; // edi
  vgui::Panel *v4; // eax
  vgui::FileOpenDialog *v5; // edi
  vgui::IFileOpenStateMachineClient_vtbl *v6; // ebx
  const char *v7; // eax
  KeyValues *m_pContextKeyValues; // [esp-8h] [ebp-10h]

  p_m_OpenFileName = &this->m_OpenFileName;
  this->m_CurrentState = STATE_SHOWING_OPEN_DIALOG;
  if ( CUtlString::Length(this: &this->m_OpenFileName) != 0 )
  {
    CUtlString::operator=(this: &this->m_FileName, src: p_m_OpenFileName);
    vgui::FileOpenStateMachine::ReadFile(this);
  }
  else
  {
    v3 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
    if ( v3 != nullptr )
    {
      v4 = this->GetParent(this);
      v5 = vgui::FileOpenDialog::FileOpenDialog(
             this: v3,
             parent: v4,
             title: (vgui::Label *)"Open",
             bOpenOnly: true,
             pContextKeyValues: nullptr);
    }
    else
    {
      v5 = nullptr;
    }
    v6 = this->m_pClient->__vftable;
    m_pContextKeyValues = this->m_pContextKeyValues;
    v7 = CUtlString::operator char const *(this: &this->m_OpenFileType);
    v6->SetupFileOpenDialog(this: this->m_pClient, a2: v5, a3: true, a4: v7, a5: m_pContextKeyValues);
    v5->AddActionSignalTarget_2(this: v5, a2: this);
    vgui::FileOpenDialog::DoModal(this: v5, bUnused: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F170
// Name: public: void vgui::FileOpenStateMachine::OpenFile(char const __near *,class KeyValues __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OpenFile(
        vgui::FileOpenStateMachine *this,
        char *pOpenFileType,
        KeyValues *pContextKeyValues,
        char *pSaveFileName,
        char *pSaveFileType,
        char nFlags)
{
  KeyValues *m_pContextKeyValues; // ecx
  char v8; // cl
  vgui::Panel *v9; // eax
  const char *v10; // [esp-14h] [ebp-20h]
  const char *v11; // [esp-10h] [ebp-1Ch]

  m_pContextKeyValues = this->m_pContextKeyValues;
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->m_CompletionState = IN_PROGRESS;
  this->m_pContextKeyValues = pContextKeyValues;
  CUtlString::operator=(this: &this->m_FileName, src: pSaveFileName);
  CUtlString::operator=(this: &this->m_SaveFileType, src: pSaveFileType);
  CUtlString::operator=(this: &this->m_OpenFileType, src: pOpenFileType);
  CUtlString::operator=(this: &this->m_OpenFileName, src: nullptr);
  v8 = nFlags & 1 | *((_BYTE *)this + 428) & 0xF4 | (2 * (((nFlags & 2) != 0) | 2));
  *((_BYTE *)this + 428) = v8;
  if ( (v8 & 2) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_SAVE_DIRTY_FILE_DIALOG;
    v11 = CUtlString::operator char const *(this: &this->m_SaveFileType);
    v10 = CUtlString::operator char const *(this: &this->m_FileName);
    v9 = this->GetParent(this);
    ShowSaveDocumentQuery(
      pParent: v9,
      pFileName: v10,
      pFileType: v11,
      nContext: 0,
      pActionSignalTarget: this,
      pPostSaveCommand: nullptr);
  }
  else
  {
    vgui::FileOpenStateMachine::OpenFileDialog(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F250
// Name: private: void vgui::FileOpenStateMachine::WriteFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::WriteFile(vgui::FileOpenStateMachine *this)
{
  vgui::IFileOpenStateMachineClient *m_pClient; // eax
  vgui::IFileOpenStateMachineClient_vtbl *v3; // ebx
  const char *v4; // eax
  char v5; // al
  vgui::Panel *v6; // eax
  const char *v7; // [esp-10h] [ebp-1Ch]
  const char *v8; // [esp-8h] [ebp-14h]
  KeyValues *m_pContextKeyValues; // [esp-4h] [ebp-10h]

  m_pClient = this->m_pClient;
  m_pContextKeyValues = this->m_pContextKeyValues;
  this->m_CurrentState = STATE_WRITING_FILE;
  v3 = m_pClient->__vftable;
  v8 = CUtlString::operator char const *(this: &this->m_SaveFileType);
  v4 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v3->OnWriteFileToDisk(this: this->m_pClient, a2: v4, a3: v8, a4: m_pContextKeyValues) )
  {
    *((_BYTE *)this + 428) |= 8u;
    v5 = *((_BYTE *)this + 428);
    if ( (v5 & 1) != 0 )
    {
      this->m_CurrentState = STATE_SHOWING_PERFORCE_ADD_DIALOG;
      v7 = CUtlString::operator char const *(this: &this->m_FileName);
      v6 = this->GetParent(this);
      ShowPerforceQuery(
        pParent: v6,
        pFileName: v7,
        pActionSignalTarget: this,
        pKeyValues: nullptr,
        actionFilter: PERFORCE_ACTION_FILE_ADD);
    }
    else if ( (v5 & 4) != 0 )
    {
      vgui::FileOpenStateMachine::OpenFileDialog(this);
    }
    else
    {
      vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
    }
  }
  else
  {
    vgui::FileOpenStateMachine::SetCompletionState(this, state: ERROR_WRITING_FILE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F300
// Name: private: virtual void vgui::FileOpenStateMachine::OnMakeFileWriteable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnMakeFileWriteable(vgui::FileOpenStateMachine *this)
{
  IBaseFileSystem_vtbl *v1; // edi
  const char *v3; // eax

  v1 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v3 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v1->SetFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: true, a4: nullptr) )
    vgui::FileOpenStateMachine::WriteFile(this);
  else
    vgui::FileOpenStateMachine::SetCompletionState(this, state: ERROR_MAKING_FILE_WRITEABLE);
}

//------------------------------------------------------------------------------
// Address: 0x0062F350
// Name: private: void vgui::FileOpenStateMachine::MakeFileWriteableDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::MakeFileWriteableDialog(vgui::FileOpenStateMachine *this)
{
  IBaseFileSystem_vtbl *v1; // ebx
  const char *v3; // eax
  IBaseFileSystem_vtbl *v4; // ebx
  const char *v5; // eax
  IP4_vtbl *v6; // ebx
  const char *v7; // eax
  const char *v8; // eax
  bool v9; // al
  const char *v10; // eax
  vgui::MessageBox *v11; // esi
  vgui::Panel *v12; // eax
  vgui::MessageBox *v13; // esi
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  char pBuf[1024]; // [esp+Ch] [ebp-404h] BYREF
  IP4_vtbl *v19; // [esp+40Ch] [ebp-4h]

  v1 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v3 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( !v1->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: nullptr)
    || (v4 = g_pFullFileSystem->IBaseFileSystem::__vftable,
        v5 = CUtlString::operator char const *(this: &this->m_FileName),
        v4->IsFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5, a3: nullptr)) )
  {
    vgui::FileOpenStateMachine::WriteFile(this);
  }
  else
  {
    v6 = p4->__vftable;
    v7 = CUtlString::operator char const *(this: &this->m_FileName);
    LOBYTE(v6) = v6->IsFileInPerforce(this: p4, a2: v7);
    v19 = p4->__vftable;
    v8 = CUtlString::operator char const *(this: &this->m_FileName);
    v9 = v19->GetFileState(this: p4, a2: v8) != P4FILE_UNOPENED;
    if ( (_BYTE)v6 == 0 || v9 )
    {
      this->m_CurrentState = STATE_SHOWING_MAKE_FILE_WRITEABLE_DIALOG;
      v10 = CUtlString::Get(this: &this->m_FileName);
      V_snprintf(
        pDest: pBuf,
        maxLen: 0x400u,
        pFormat: "Encountered read-only file. Should it be made writeable?\n\n\"%s\"\n",
        v10);
      v11 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
      if ( v11 != nullptr )
      {
        v12 = this->GetParent(this);
        v13 = vgui::MessageBox::MessageBox(this: v11, title: "Make File Writeable?", text: pBuf, parent: v12);
      }
      else
      {
        v13 = nullptr;
      }
      v13->AddActionSignalTarget_2(this: v13, a2: this);
      v13->SetOKButtonVisible(this: v13, a2: true);
      v13->SetOKButtonText_2(this: v13, a2: "Yes");
      vgui::MessageBox::SetCancelButtonVisible(this: v13, state: true);
      vgui::MessageBox::SetCancelButtonText(this: v13, buttonText: "No");
      v13->SetCloseButtonVisible(this: v13, a2: false);
      v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v14 != nullptr )
        v15 = KeyValues::KeyValues(this: v14, setName: "MakeFileWriteable");
      else
        v15 = nullptr;
      v13->SetCommand(this: v13, a2: v15);
      v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v16 != nullptr )
        v17 = KeyValues::KeyValues(this: v16, setName: "CancelMakeFileWriteable");
      else
        v17 = nullptr;
      vgui::MessageBox::SetCancelCommand(this: v13, command: v17);
      v13->DoModal_2(this: v13, a2: nullptr);
    }
    else
    {
      vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_CHECKED_OUT);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F550
// Name: private: virtual void vgui::FileOpenStateMachine::OnPerforceQueryCompleted(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnPerforceQueryCompleted(
        vgui::FileOpenStateMachine *this,
        KeyValues *pKeyValues)
{
  vgui::FileOpenStateMachine::FOSMState_t m_CurrentState; // eax

  m_CurrentState = this->m_CurrentState;
  if ( m_CurrentState == STATE_SHOWING_CHECK_OUT_DIALOG )
  {
    if ( KeyValues::GetInt(this: pKeyValues, keyName: "operationPerformed", defaultValue: 0) != 0 )
      vgui::FileOpenStateMachine::MakeFileWriteableDialog(this);
    else
      vgui::FileOpenStateMachine::SetCompletionState(this, state: FILE_NOT_CHECKED_OUT);
  }
  else if ( m_CurrentState == STATE_SHOWING_PERFORCE_ADD_DIALOG )
  {
    if ( (*((_BYTE *)this + 428) & 4) != 0 )
      vgui::FileOpenStateMachine::OpenFileDialog(this);
    else
      vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F5B0
// Name: private: virtual void vgui::FileOpenStateMachine::OnSaveFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnSaveFile(vgui::FileOpenStateMachine *this)
{
  const char *v2; // eax
  vgui::FileOpenDialog *v3; // edi
  vgui::Panel *v4; // eax
  vgui::FileOpenDialog *v5; // edi
  vgui::IFileOpenStateMachineClient_vtbl *v6; // ebx
  const char *v7; // eax
  KeyValues *m_pContextKeyValues; // [esp-8h] [ebp-10h]

  if ( *CUtlString::operator char const *(this: &this->m_FileName) != 0
    && (v2 = CUtlString::operator char const *(this: &this->m_FileName), V_IsAbsolutePath(pStr: v2)) )
  {
    vgui::FileOpenStateMachine::CheckOutDialog(this);
  }
  else
  {
    this->m_CurrentState = STATE_SHOWING_SAVE_DIALOG;
    v3 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
    if ( v3 != nullptr )
    {
      v4 = this->GetParent(this);
      v5 = vgui::FileOpenDialog::FileOpenDialog(
             this: v3,
             parent: v4,
             title: (vgui::Label *)"Save As",
             bOpenOnly: false,
             pContextKeyValues: nullptr);
    }
    else
    {
      v5 = nullptr;
    }
    v6 = this->m_pClient->__vftable;
    m_pContextKeyValues = this->m_pContextKeyValues;
    v7 = CUtlString::operator char const *(this: &this->m_SaveFileType);
    v6->SetupFileOpenDialog(this: this->m_pClient, a2: v5, a3: false, a4: v7, a5: m_pContextKeyValues);
    v5->AddActionSignalTarget_2(this: v5, a2: this);
    vgui::FileOpenDialog::DoModal(this: v5, bUnused: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F670
// Name: private: virtual void vgui::FileOpenStateMachine::OnMarkNotDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnMarkNotDirty(vgui::FileOpenStateMachine *this)
{
  if ( (*((_BYTE *)this + 428) & 4) != 0 )
    vgui::FileOpenStateMachine::OpenFileDialog(this);
  else
    vgui::FileOpenStateMachine::SetCompletionState(this, state: SUCCESSFUL);
}

//------------------------------------------------------------------------------
// Address: 0x0062F690
// Name: private: void vgui::FileOpenStateMachine::CheckOutDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::CheckOutDialog(vgui::FileOpenStateMachine *this)
{
  vgui::Panel *v2; // eax
  const char *v3; // [esp-10h] [ebp-14h]

  if ( (*((_BYTE *)this + 428) & 1) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_CHECK_OUT_DIALOG;
    v3 = CUtlString::operator char const *(this: &this->m_FileName);
    v2 = this->GetParent(this);
    ShowPerforceQuery(
      pParent: v2,
      pFileName: v3,
      pActionSignalTarget: this,
      pKeyValues: nullptr,
      actionFilter: PERFORCE_ACTION_FILE_EDIT);
  }
  else
  {
    vgui::FileOpenStateMachine::WriteFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F6E0
// Name: private: void vgui::FileOpenStateMachine::OverwriteFileDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OverwriteFileDialog(vgui::FileOpenStateMachine *this)
{
  IBaseFileSystem_vtbl *v1; // ebx
  const char *v3; // eax
  vgui::Panel *v4; // eax
  const char *v5; // eax
  vgui::MessageBox *v6; // esi
  vgui::Panel *v7; // eax
  vgui::MessageBox *v8; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  const char *v13; // [esp-10h] [ebp-41Ch]
  char pBuf[1024]; // [esp+Ch] [ebp-400h] BYREF

  v1 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v3 = CUtlString::operator char const *(this: &this->m_FileName);
  if ( v1->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3, a3: nullptr) )
  {
    this->m_CurrentState = STATE_SHOWING_OVERWRITE_DIALOG;
    v5 = CUtlString::Get(this: &this->m_FileName);
    V_snprintf(pDest: pBuf, maxLen: 0x400u, pFormat: "File already exists. Overwrite it?\n\n\"%s\"\n", v5);
    v6 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v6 != nullptr )
    {
      v7 = this->GetParent(this);
      v8 = vgui::MessageBox::MessageBox(this: v6, title: "Overwrite Existing File?", text: pBuf, parent: v7);
    }
    else
    {
      v8 = nullptr;
    }
    v8->AddActionSignalTarget_2(this: v8, a2: this);
    v8->SetOKButtonVisible(this: v8, a2: true);
    v8->SetOKButtonText_2(this: v8, a2: "Yes");
    vgui::MessageBox::SetCancelButtonVisible(this: v8, state: true);
    vgui::MessageBox::SetCancelButtonText(this: v8, buttonText: "No");
    v8->SetCloseButtonVisible(this: v8, a2: false);
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
      v10 = KeyValues::KeyValues(this: v9, setName: "OverwriteFile");
    else
      v10 = nullptr;
    v8->SetCommand(this: v8, a2: v10);
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "CancelOverwriteFile");
    else
      v12 = nullptr;
    vgui::MessageBox::SetCancelCommand(this: v8, command: v12);
    v8->DoModal_2(this: v8, a2: nullptr);
  }
  else if ( (*((_BYTE *)this + 428) & 1) != 0 )
  {
    this->m_CurrentState = STATE_SHOWING_CHECK_OUT_DIALOG;
    v13 = CUtlString::operator char const *(this: &this->m_FileName);
    v4 = this->GetParent(this);
    ShowPerforceQuery(
      pParent: v4,
      pFileName: v13,
      pActionSignalTarget: this,
      pKeyValues: nullptr,
      actionFilter: PERFORCE_ACTION_FILE_EDIT);
  }
  else
  {
    vgui::FileOpenStateMachine::WriteFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F880
// Name: private: virtual void vgui::FileOpenStateMachine::OnFileSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::OnFileSelected(vgui::FileOpenStateMachine *this, KeyValues *pKeyValues)
{
  vgui::FileOpenStateMachine::FOSMState_t m_CurrentState; // eax
  char *String; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax

  m_CurrentState = this->m_CurrentState;
  if ( m_CurrentState == STATE_SHOWING_SAVE_DIALOG )
  {
    String = KeyValues::GetString(this: pKeyValues, keyName: "fullpath", defaultValue: defaultValue);
    CUtlString::operator=(this: &this->m_FileName, src: String);
    v5 = KeyValues::GetString(this: pKeyValues, keyName: "filterinfo", defaultValue: defaultValue);
    if ( v5 != nullptr )
      CUtlString::operator=(this: &this->m_SaveFileType, src: v5);
    vgui::FileOpenStateMachine::OverwriteFileDialog(this);
  }
  else if ( m_CurrentState == STATE_SHOWING_OPEN_DIALOG )
  {
    v6 = KeyValues::GetString(this: pKeyValues, keyName: "fullpath", defaultValue: defaultValue);
    CUtlString::operator=(this: &this->m_FileName, src: v6);
    v7 = KeyValues::GetString(this: pKeyValues, keyName: "filterinfo", defaultValue: defaultValue);
    if ( v7 != nullptr )
      CUtlString::operator=(this: &this->m_OpenFileType, src: v7);
    vgui::FileOpenStateMachine::ReadFile(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F940
// Name: public: virtual vgui::FileOpenStateMachine::~FileOpenStateMachine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::FileOpenStateMachine::~FileOpenStateMachine(vgui::FileOpenStateMachine *this)
{
  KeyValues *m_pContextKeyValues; // ecx

  m_pContextKeyValues = this->m_pContextKeyValues;
  this->__vftable = (vgui::FileOpenStateMachine_vtbl *)&vgui::FileOpenStateMachine::`vftable';
  if ( m_pContextKeyValues != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeyValues);
    this->m_pContextKeyValues = nullptr;
  }
  this->m_OpenFileName.m_Storage.m_nActualLength = 0;
  if ( this->m_OpenFileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OpenFileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OpenFileName.m_Storage.m_Memory.m_pMemory);
      this->m_OpenFileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_OpenFileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_OpenFileType.m_Storage.m_nActualLength = 0;
  if ( this->m_OpenFileType.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_OpenFileType.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_OpenFileType.m_Storage.m_Memory.m_pMemory);
      this->m_OpenFileType.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_OpenFileType.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_SaveFileType.m_Storage.m_nActualLength = 0;
  if ( this->m_SaveFileType.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SaveFileType.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SaveFileType.m_Storage.m_Memory.m_pMemory);
      this->m_SaveFileType.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_SaveFileType.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FileName.m_Storage.m_nActualLength = 0;
  if ( this->m_FileName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_FileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FileName.m_Storage.m_Memory.m_pMemory);
      this->m_FileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_FileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0062FAE0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "FileSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062FB70
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{848,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FileSelectionCancelled";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062FC00
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PerforceQueryCompleted";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062FC90
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MakeFileWriteable";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062FD20
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CancelMakeFileWriteable";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062FDB0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{864,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OverwriteFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062FE40
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{868,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CancelOverwriteFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062FED0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::RichText::`vcall'{872,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnSaveFile";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062FF60
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeElementPickerPanel::`vcall'{876,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnMarkNotDirty";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062FFF0
// Name: public: static void vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar'::`2'::bAdded )
  {
    `vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSheetSequencePickerPanel::`vcall'{880,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnCancelSaveDocument";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00630080
// Name: public: vgui::FileOpenStateMachine::FileOpenStateMachine(class vgui::Panel __near *,class vgui::IFileOpenStateMachineClient __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::FileOpenStateMachine *__thiscall vgui::FileOpenStateMachine::FileOpenStateMachine(
        vgui::FileOpenStateMachine *this,
        vgui::Panel *pParent,
        vgui::IFileOpenStateMachineClient *pClient)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent: pParent, panelName: "FileOpenStateMachine");
  this->__vftable = (vgui::FileOpenStateMachine_vtbl *)&vgui::FileOpenStateMachine::`vftable';
  if ( `vgui::FileOpenStateMachine::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::FileOpenStateMachine::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
    v4->pfnClassName = vgui::FileOpenStateMachine::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::FileOpenStateMachine::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::FileOpenStateMachine::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "FileOpenStateMachine");
    v5->pfnClassName = vgui::FileOpenStateMachine::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::FileOpenStateMachine::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::FileOpenStateMachine::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "FileOpenStateMachine");
    v6->pfnClassName = vgui::FileOpenStateMachine::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnFileSelectionCancelled::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnPerforceQueryCompleted::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnMakeFileWriteable::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelMakeFileWriteable::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnOverwriteFile::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelOverwriteFile::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnSaveFile::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnMarkNotDirty::InitVar(a1: (int)&savedregs);
  vgui::FileOpenStateMachine::PanelMessageFunc_OnCancelSaveDocument::InitVar(a1: (int)&savedregs);
  CUtlString::CUtlString(this: &this->m_FileName);
  CUtlString::CUtlString(this: &this->m_SaveFileType);
  CUtlString::CUtlString(this: &this->m_OpenFileType);
  CUtlString::CUtlString(this: &this->m_OpenFileName);
  this->m_pClient = pClient;
  this->m_CompletionState = SUCCESSFUL;
  this->m_CurrentState = STATE_NONE;
  this->m_pContextKeyValues = nullptr;
  vgui::Panel::SetVisible(this, state: 0);
  return this;
}

} // namespace sceneviewer
