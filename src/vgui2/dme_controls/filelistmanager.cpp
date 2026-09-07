// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/filelistmanager.cpp
// Functions: 47
// ============================================================

#include "vgui2\dme_controls\filelistmanager.h"

//------------------------------------------------------------------------------
// Address: 0x00464B90
// Name: public: static char const __near * CFileListManager::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CFileListManager::GetPanelClassName()
{
  return "CFileListManager";
}

//------------------------------------------------------------------------------
// Address: 0x00464BA0
// Name: public: static char const __near * CFileManagerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CFileManagerFrame::GetPanelClassName()
{
  return "CFileManagerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x00464BB0
// Name: void AddColumn(class CFileListManager __near *,enum ColumnIndex_t)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddColumn(CFileListManager *pFileManager, ColumnIndex_t ci)
{
  pFileManager->AddColumnHeader(
    this: pFileManager,
    a2: ci,
    a3: *(&g_ColInfo[0].columnName + 6 * ci),
    a4: *(&g_ColInfo[0].columnText + 6 * ci),
    a5: *(&g_ColInfo[0].startingWidth + 6 * ci),
    a6: *(&g_ColInfo[0].minWidth + 6 * ci));
  pFileManager->SetSortFunc(
    this: pFileManager,
    a2: ci,
    a3: *((int (__cdecl **)(vgui::ListPanel *, const vgui::ListPanelItem *, const vgui::ListPanelItem *))&g_ColInfo[0].maxWidth
    + 6 * ci));
  pFileManager->SetColumnTextAlignment(this: pFileManager, a2: ci, a3: *(&g_ColInfo[0].flags + 6 * ci));
}

//------------------------------------------------------------------------------
// Address: 0x00464C20
// Name: protected: int CFileListManager::AddItem(enum DmFileId_t,char const __near *,char const __near *,bool,int,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFileListManager::AddItem(
        CFileListManager *this,
        DmFileId_t fileid,
        const char *pFilename,
        const char *pPath,
        bool bLoaded,
        int nElements,
        bool bChanged,
        bool bInPerforce,
        bool bOpenForEdit)
{
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  int v16; // edi

  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(
            this: v10,
            setName: defaultValue,
            firstKey: g_ColInfo[0].columnName,
            firstValue: pFilename,
            secondKey: (const char *)g_ColInfo[0].pfnSort,
            secondValue: pPath);
  else
    v11 = nullptr;
  KeyValues::SetInt(this: v11, keyName: (const char *)g_ColInfo[2].startingWidth, value: nElements);
  v12 = "Y";
  if ( !bLoaded )
    v12 = "N";
  KeyValues::SetString(this: v11, keyName: (const char *)g_ColInfo[1].maxWidth, value: v12);
  v13 = "Y";
  if ( !bChanged )
    v13 = "N";
  KeyValues::SetString(this: v11, keyName: g_ColInfo[3].columnName, value: v13);
  v14 = "Y";
  if ( !bInPerforce )
    v14 = "N";
  KeyValues::SetString(this: v11, keyName: (const char *)g_ColInfo[3].pfnSort, value: v14);
  v15 = "Y";
  if ( !bOpenForEdit )
    v15 = "N";
  KeyValues::SetString(this: v11, keyName: (const char *)g_ColInfo[4].maxWidth, value: v15);
  v16 = vgui::ListPanel::AddItem(this, item: v11, userData: fileid, bScrollToItem: false, bSortOnAdd: false);
  KeyValues::deleteThis(this: v11);
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x00464D10
// Name: protected: virtual void CFileListManager::OnOpenFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileListManager::OnOpenFile(CFileListManager *this, KeyValues *pParams)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  vgui::FileOpenDialog *v5; // eax
  vgui::FileOpenDialog *v6; // esi

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "OnOpen");
  else
    v4 = nullptr;
  v5 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
  if ( v5 != nullptr )
    v6 = vgui::FileOpenDialog::FileOpenDialog(
           this: v5,
           parent: this,
           title: "Save .dmx File As",
           bOpenOnly: false,
           pContextKeyValues: v4);
  else
    v6 = nullptr;
  vgui::FileOpenDialog::AddFilter(
    this: v6,
    filter: "*.dmx",
    filterName: "DmElements File (*.dmx)",
    bActive: true,
    pFilterInfo: nullptr);
  v6->AddActionSignalTarget_2(this: v6, a2: this);
  vgui::FileOpenDialog::DoModal(this: v6, bUnused: false);
}

//------------------------------------------------------------------------------
// Address: 0x00464D90
// Name: protected: virtual void CFileListManager::OnSaveFileAs(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFileListManager::OnSaveFileAs(CFileListManager *this@<ecx>, int a2@<edi>, KeyValues *pParams)
{
  KeyValues *v4; // eax
  int v5; // eax
  CFileListManager_vtbl *v6; // edi
  int v7; // eax
  DmFileId_t v8; // eax
  const char *v9; // ebx
  vgui::FileOpenDialog *v10; // eax
  vgui::FileOpenDialog *v11; // edi
  const char *v12; // eax
  char description[256]; // [esp+4h] [ebp-104h] BYREF
  KeyValues *pContextKeyValues; // [esp+104h] [ebp-4h]

  if ( this->GetSelectedItemsCount(this) == 1 )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      pContextKeyValues = KeyValues::KeyValues(this: v4, setName: "OnSaveAs");
    else
      pContextKeyValues = nullptr;
    v5 = ((int (__thiscall *)(CFileListManager *, _DWORD, int))this->GetSelectedItem)(a1: this, a2: 0, a3: a2);
    KeyValues::SetInt(this: pContextKeyValues, keyName: "itemId", value: v5);
    v6 = this->__vftable;
    v7 = this->GetSelectedItem(this, a2: 0);
    v8 = v6->GetItemUserData(this, a2: v7);
    v9 = g_pDataModel->GetFileFormat(this: g_pDataModel, a2: v8);
    v10 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
    if ( v10 != nullptr )
      v11 = vgui::FileOpenDialog::FileOpenDialog(
              this: v10,
              parent: this,
              title: "Save .dmx File As",
              bOpenOnly: false,
              pContextKeyValues);
    else
      v11 = nullptr;
    vgui::FileOpenDialog::AddFilter(
      this: v11,
      filter: "*.dmx",
      filterName: "Generic MovieObjects File (*.dmx)",
      bActive: false,
      pFilterInfo: "movieobjects");
    if ( _V_strcmp(s1: v9, s2: "movieobjects") != 0 )
    {
      v12 = g_pDataModel->GetFormatDescription(this: g_pDataModel, a2: v9);
      V_snprintf(pDest: description, maxLen: 256, pFormat: "%s (*.dmx)", v12);
      vgui::FileOpenDialog::AddFilter(
        this: v11,
        filter: "*.dmx",
        filterName: description,
        bActive: true,
        pFilterInfo: v9);
    }
    v11->AddActionSignalTarget_2(this: v11, a2: this);
    vgui::FileOpenDialog::DoModal(this: v11, bUnused: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00464ED0
// Name: protected: virtual void CFileListManager::OnAddToPerforce(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileListManager::OnAddToPerforce(CFileListManager *this, KeyValues *pParams)
{
  int (__thiscall *GetSelectedItemsCount)(vgui::ListPanel *); // edx
  int v4; // edi
  int v5; // ebx
  void *v6; // esp
  int v7; // eax
  DmFileId_t v8; // eax
  const char *v9; // eax
  vgui::MessageBox *v10; // edi
  const char *v11; // eax
  vgui::MessageBox *v12; // edi
  vgui::Panel *v13; // [esp-4h] [ebp-18h]
  int v14; // [esp+0h] [ebp-14h] BYREF
  const char **ppFileNames; // [esp+Ch] [ebp-8h]
  int nFileCount; // [esp+10h] [ebp-4h]

  GetSelectedItemsCount = this->GetSelectedItemsCount;
  v4 = 0;
  nFileCount = 0;
  v5 = GetSelectedItemsCount(this);
  v6 = alloca(4 * v5);
  ppFileNames = (const char **)&v14;
  if ( v5 > 0 )
  {
    do
    {
      v7 = this->GetSelectedItem(this, a2: v4);
      v8 = this->GetItemUserData(this, a2: v7);
      v9 = g_pDataModel->GetFileName(this: g_pDataModel, a2: v8);
      if ( v9 != nullptr )
      {
        ++nFileCount;
        ppFileNames[v4] = v9;
      }
      ++v4;
    }
    while ( v4 < v5 );
  }
  if ( !p4->OpenFilesForAdd(this: p4, a2: nFileCount, a3: ppFileNames) )
  {
    v10 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v10 != nullptr )
    {
      v13 = this->GetParent(this);
      v11 = p4->GetLastError(this: p4);
      v12 = vgui::MessageBox::MessageBox(this: v10, title: "Perforce Error!", text: v11, parent: v13);
    }
    else
    {
      v12 = nullptr;
    }
    v12->SetSmallCaption(this: v12, a2: true);
    v12->DoModal_2(this: v12, a2: nullptr);
  }
  this->Refresh(this);
}

//------------------------------------------------------------------------------
// Address: 0x00464FD0
// Name: protected: virtual void CFileListManager::OnOpenForEdit(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileListManager::OnOpenForEdit(CFileListManager *this, KeyValues *pParams)
{
  int (__thiscall *GetSelectedItemsCount)(vgui::ListPanel *); // edx
  int v4; // edi
  int v5; // ebx
  void *v6; // esp
  int v7; // eax
  DmFileId_t v8; // eax
  const char *v9; // eax
  vgui::MessageBox *v10; // edi
  const char *v11; // eax
  vgui::MessageBox *v12; // edi
  vgui::Panel *v13; // [esp-4h] [ebp-18h]
  int v14; // [esp+0h] [ebp-14h] BYREF
  const char **ppFileNames; // [esp+Ch] [ebp-8h]
  int nFileCount; // [esp+10h] [ebp-4h]

  GetSelectedItemsCount = this->GetSelectedItemsCount;
  v4 = 0;
  nFileCount = 0;
  v5 = GetSelectedItemsCount(this);
  v6 = alloca(4 * v5);
  ppFileNames = (const char **)&v14;
  if ( v5 > 0 )
  {
    do
    {
      v7 = this->GetSelectedItem(this, a2: v4);
      v8 = this->GetItemUserData(this, a2: v7);
      v9 = g_pDataModel->GetFileName(this: g_pDataModel, a2: v8);
      if ( v9 != nullptr )
      {
        ++nFileCount;
        ppFileNames[v4] = v9;
      }
      ++v4;
    }
    while ( v4 < v5 );
  }
  if ( !p4->OpenFilesForEdit(this: p4, a2: nFileCount, a3: ppFileNames) )
  {
    v10 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v10 != nullptr )
    {
      v13 = this->GetParent(this);
      v11 = p4->GetLastError(this: p4);
      v12 = vgui::MessageBox::MessageBox(this: v10, title: "Perforce Error!", text: v11, parent: v13);
    }
    else
    {
      v12 = nullptr;
    }
    v12->SetSmallCaption(this: v12, a2: true);
    v12->DoModal_2(this: v12, a2: nullptr);
  }
  this->Refresh(this);
}

//------------------------------------------------------------------------------
// Address: 0x004650D0
// Name: protected: virtual void CFileListManager::OnDataChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFileListManager::OnDataChanged(CFileListManager *this@<ecx>, int a2@<ebx>, KeyValues *pParams)
{
  int v4; // ebx
  int v5; // edi
  const char *v6; // eax
  KeyValues *v7; // ebx
  const char *String; // eax
  int v9; // eax
  bool v10; // zf
  const char *v11; // eax
  int nCount; // [esp+8h] [ebp-Ch]
  const char *pFileName; // [esp+Ch] [ebp-8h]
  const char *pFileNamea; // [esp+Ch] [ebp-8h]
  const char *pNameKey; // [esp+10h] [ebp-4h]
  DmFileId_t fileid; // [esp+1Ch] [ebp+8h]

  if ( (KeyValues::GetInt(this: pParams, keyName: "notifyFlags", defaultValue: 0) & 0x1000) != 0
    && KeyValues::GetInt(this: pParams, keyName: "source", defaultValue: 0) != 5 )
  {
    if ( !this->IsVisible(this) )
    {
      this->m_bRefreshRequired = true;
      return;
    }
    v4 = this->GetItemCount(this);
    nCount = v4;
    if ( v4 == g_pDataModel->NumFileIds(this: g_pDataModel) )
    {
      v5 = 0;
      pNameKey = g_ColInfo[0].columnName;
      if ( v4 <= 0 )
        return;
      while ( 1 )
      {
        fileid = g_pDataModel->GetFileId_2(this: g_pDataModel, a2: v5);
        v6 = g_pDataModel->GetFileName(this: g_pDataModel, a2: fileid);
        if ( v6 == nullptr )
          break;
        if ( *v6 == 0 )
          break;
        pFileName = V_UnqualifiedFileName(in: v6);
        v7 = this->GetItem(this, a2: v5);
        if ( fileid != this->GetItemUserData(this, a2: v5) )
          break;
        String = KeyValues::GetString(this: v7, keyName: pNameKey, defaultValue: defaultValue);
        if ( _V_stricmp(s1: pFileName, s2: String) != 0 )
          break;
        pFileNamea = (const char *)g_ColInfo[2].startingWidth;
        v9 = ((int (__thiscall *)(IDataModel *, DmFileId_t, int))g_pDataModel->NumElementsInFile)(
               a1: g_pDataModel,
               a2: fileid,
               a3: a2);
        KeyValues::SetInt(this: v7, keyName: pFileNamea, value: v9);
        v10 = !g_pDataModel->IsFileLoaded(this: g_pDataModel, a2: fileid);
        v11 = "Y";
        if ( v10 )
          v11 = "N";
        KeyValues::SetString(this: v7, keyName: (const char *)g_ColInfo[1].maxWidth, value: v11);
        KeyValues::SetString(this: v7, keyName: g_ColInfo[3].columnName, value: "N");
        a2 = v5;
        ((void (__thiscall *)(CFileListManager *))this->ApplyItemChanges)(a1: this);
        if ( ++v5 >= nCount )
          return;
      }
    }
    this->Refresh(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004652A0
// Name: public: virtual void CFileListManager::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CFileListManager::Refresh(CFileListManager *this@<ecx>, int a2@<ebx>)
{
  void (*RemoveAll)(void); // edx
  int v3; // eax
  int v4; // ebx
  DmFileId_t v5; // esi
  const char *v6; // eax
  const char *v7; // edi
  int v8; // ebx
  P4FileState_t (__thiscall *GetFileState)(IP4 *, const char *); // edx
  int v10; // eax
  const char *v11; // eax
  bool v12; // [esp-1Ch] [ebp-138h]
  bool v13; // [esp-10h] [ebp-12Ch]
  bool v14; // [esp-Ch] [ebp-128h]
  char path[256]; // [esp+0h] [ebp-11Ch] BYREF
  CFileListManager *v16; // [esp+100h] [ebp-1Ch]
  int nFiles; // [esp+104h] [ebp-18h]
  BOOL bLoaded; // [esp+108h] [ebp-14h]
  BOOL bOpenForEdit; // [esp+10Ch] [ebp-10h]
  BOOL bInPerforce; // [esp+110h] [ebp-Ch]
  int i; // [esp+114h] [ebp-8h]
  bool bP4Connected; // [esp+11Bh] [ebp-1h]

  RemoveAll = (void (*)(void))this->RemoveAll;
  v16 = this;
  this->m_bRefreshRequired = false;
  RemoveAll();
  bP4Connected = p4 != nullptr && p4->IsConnectedToServer(this: p4, a2: true);
  v3 = ((int (__thiscall *)(IDataModel *, int))g_pDataModel->NumFileIds)(a1: g_pDataModel, a2);
  v4 = 0;
  nFiles = v3;
  i = 0;
  if ( v3 > 0 )
  {
    while ( 1 )
    {
      v5 = g_pDataModel->GetFileId_2(this: g_pDataModel, a2: v4);
      v6 = g_pDataModel->GetFileName(this: g_pDataModel, a2: v5);
      v7 = v6;
      if ( v6 == nullptr || *v6 == 0 )
        goto LABEL_12;
      LOBYTE(bLoaded) = g_pDataModel->IsFileLoaded(this: g_pDataModel, a2: v5);
      v8 = g_pDataModel->NumElementsInFile(this: g_pDataModel, a2: v5);
      if ( !bP4Connected || !p4->IsFileInPerforce(this: p4, a2: v7) )
        break;
      GetFileState = p4->GetFileState;
      LOBYTE(bInPerforce) = 1;
      v10 = GetFileState(this: p4, a2: v7);
      LOBYTE(bOpenForEdit) = 1;
      if ( v10 == 0 )
        goto LABEL_10;
LABEL_11:
      V_ExtractFilePath(path: v7, dest: path, destSize: 256);
      v14 = bOpenForEdit;
      v13 = bInPerforce;
      v12 = bLoaded;
      v11 = V_UnqualifiedFileName(in: v7);
      CFileListManager::AddItem(
        this: v16,
        fileid: v5,
        pFilename: v11,
        pPath: path,
        bLoaded: v12,
        nElements: v8,
        bChanged: false,
        bInPerforce: v13,
        bOpenForEdit: v14);
      v4 = i;
LABEL_12:
      i = ++v4;
      if ( v4 >= nFiles )
        return;
    }
    LOBYTE(bInPerforce) = 0;
LABEL_10:
    LOBYTE(bOpenForEdit) = 0;
    goto LABEL_11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465400
// Name: public: virtual void CFileListManager::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileListManager::OnThink(CFileListManager *this)
{
  vgui::Panel::OnThink(this);
  if ( this->m_bRefreshRequired && this->IsVisible(this) )
    this->Refresh(this);
}

//------------------------------------------------------------------------------
// Address: 0x00465430
// Name: public: virtual void CFileListManager::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileListManager::OnCommand(CFileListManager *this, const char *cmd)
{
  vgui::Panel::OnCommand(this, command: cmd);
}

//------------------------------------------------------------------------------
// Address: 0x00465440
// Name: public: virtual void CFileManagerFrame::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileManagerFrame::Refresh(CFileManagerFrame *this)
{
  this->m_pFileListManager->Refresh(this: this->m_pFileListManager);
}

//------------------------------------------------------------------------------
// Address: 0x00465450
// Name: public: virtual void CFileManagerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileManagerFrame::OnCommand(CFileManagerFrame *this, const char *cmd)
{
  vgui::Frame::OnCommand(this, command: cmd);
  this->m_pFileListManager->OnCommand(this: this->m_pFileListManager, a2: cmd);
}

//------------------------------------------------------------------------------
// Address: 0x00465480
// Name: public: virtual void CFileManagerFrame::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileManagerFrame::PerformLayout(CFileManagerFrame *this)
{
  int v2; // eax
  int v3; // eax
  int iWidth; // [esp+4h] [ebp-8h] BYREF
  int iHeight; // [esp+8h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &iWidth, tall: &iHeight);
  v2 = this->GetCaptionHeight(this);
  vgui::Panel::SetPos(this: this->m_pFileListManager, x: 0, y: v2);
  v3 = this->GetCaptionHeight(this);
  vgui::Panel::SetSize(this: this->m_pFileListManager, wide: iWidth, tall: iHeight - v3);
}

//------------------------------------------------------------------------------
// Address: 0x004654E0
// Name: int ListPanelStringSortFunc<0>(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ListPanelStringSortFunc<0>(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *columnName; // esi
  const char *String; // edi
  const char *v5; // eax

  columnName = g_ColInfo[0].columnName;
  String = KeyValues::GetString(this: item1->kv, keyName: g_ColInfo[0].columnName, defaultValue: defaultValue);
  v5 = KeyValues::GetString(this: item2->kv, keyName: columnName, defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00465520
// Name: int ListPanelStringSortFunc<1>(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ListPanelStringSortFunc<1>(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  int (__cdecl *pfnSort)(vgui::ListPanel *, const vgui::ListPanelItem *, const vgui::ListPanelItem *); // esi
  const char *String; // edi
  const char *v5; // eax

  pfnSort = g_ColInfo[0].pfnSort;
  String = KeyValues::GetString(
             this: item1->kv,
             keyName: (const char *)g_ColInfo[0].pfnSort,
             defaultValue: defaultValue);
  v5 = KeyValues::GetString(this: item2->kv, keyName: (const char *)pfnSort, defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00465560
// Name: int ListPanelStringSortFunc<2>(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ListPanelStringSortFunc<2>(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *maxWidth; // esi
  const char *String; // edi
  const char *v5; // eax

  maxWidth = (const char *)g_ColInfo[1].maxWidth;
  String = KeyValues::GetString(
             this: item1->kv,
             keyName: (const char *)g_ColInfo[1].maxWidth,
             defaultValue: defaultValue);
  v5 = KeyValues::GetString(this: item2->kv, keyName: maxWidth, defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x004655A0
// Name: int ListPanelStringSortFunc<3>(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ListPanelStringSortFunc<3>(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *startingWidth; // esi
  const char *String; // edi
  const char *v5; // eax

  startingWidth = (const char *)g_ColInfo[2].startingWidth;
  String = KeyValues::GetString(
             this: item1->kv,
             keyName: (const char *)g_ColInfo[2].startingWidth,
             defaultValue: defaultValue);
  v5 = KeyValues::GetString(this: item2->kv, keyName: startingWidth, defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x004655E0
// Name: int ListPanelStringSortFunc<4>(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ListPanelStringSortFunc<4>(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *columnName; // esi
  const char *String; // edi
  const char *v5; // eax

  columnName = g_ColInfo[3].columnName;
  String = KeyValues::GetString(this: item1->kv, keyName: g_ColInfo[3].columnName, defaultValue: defaultValue);
  v5 = KeyValues::GetString(this: item2->kv, keyName: columnName, defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00465620
// Name: int ListPanelStringSortFunc<5>(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ListPanelStringSortFunc<5>(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  int (__cdecl *pfnSort)(vgui::ListPanel *, const vgui::ListPanelItem *, const vgui::ListPanelItem *); // esi
  const char *String; // edi
  const char *v5; // eax

  pfnSort = g_ColInfo[3].pfnSort;
  String = KeyValues::GetString(
             this: item1->kv,
             keyName: (const char *)g_ColInfo[3].pfnSort,
             defaultValue: defaultValue);
  v5 = KeyValues::GetString(this: item2->kv, keyName: (const char *)pfnSort, defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00465660
// Name: int ListPanelStringSortFunc<6>(class vgui::ListPanel __near *,class vgui::ListPanelItem const __near &,class vgui::ListPanelItem const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ListPanelStringSortFunc<6>(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *maxWidth; // esi
  const char *String; // edi
  const char *v5; // eax

  maxWidth = (const char *)g_ColInfo[4].maxWidth;
  String = KeyValues::GetString(
             this: item1->kv,
             keyName: (const char *)g_ColInfo[4].maxWidth,
             defaultValue: defaultValue);
  v5 = KeyValues::GetString(this: item2->kv, keyName: maxWidth, defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x004656D0
// Name: protected: void CFileListManager::SetLoaded(enum DmFileId_t,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileListManager::SetLoaded(CFileListManager *this, DmFileId_t fileid, CDmElement *bLoaded)
{
  IDataModel_vtbl *v3; // eax
  int v4; // eax
  IDataModel_vtbl *v5; // edx
  const char *v6; // esi
  int (*v7)(void); // eax
  char v8; // al
  IDataModel_vtbl *v9; // edx
  unsigned __int8 (*IsUndoEnabled)(void); // edx
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-8h] BYREF

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CFileListManager::SetLoaded", a3: 5, a4: 256);
  v3 = g_pDataModel->__vftable;
  if ( (_BYTE)bLoaded == 0 )
  {
    IsUndoEnabled = (unsigned __int8 (*)(void))v3->IsUndoEnabled;
    guard.m_bNotify = false;
    guard.m_pNotify = nullptr;
    *(_WORD *)&guard.m_bOldValue = IsUndoEnabled();
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    g_pDataModel->UnloadFile(this: g_pDataModel, a2: fileid);
    goto LABEL_5;
  }
  v4 = ((int (__stdcall *)(DmFileId_t))v3->GetFileName)(a1: fileid);
  v5 = g_pDataModel->__vftable;
  v6 = (const char *)v4;
  if ( v4 != 0 )
  {
    v7 = (int (*)(void))v5->IsUndoEnabled;
    *(_WORD *)&guard.m_bReleased = 0;
    guard.m_pNotify = nullptr;
    v8 = v7();
    v9 = g_pDataModel->__vftable;
    guard.m_bOldValue = v8;
    v9->SetUndoEnabled(this: g_pDataModel, a2: false);
    bLoaded = nullptr;
    g_pDataModel->RestoreFromFile(
      this: g_pDataModel,
      a2: v6,
      a3: nullptr,
      a4: nullptr,
      a5: &bLoaded,
      a6: CR_DELETE_NEW,
      a7: nullptr);
LABEL_5:
    CChangeUndoScopeGuard::Release(this: &guard);
    v5 = g_pDataModel->__vftable;
  }
  ((void (__stdcall *)(_DWORD))v5->PopNotificationScope)(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004657C0
// Name: public: virtual void CFileListManager::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFileListManager::OnMousePressed(CFileListManager *this@<ecx>, int a2@<ebx>, CDmElement *code)
{
  int v4; // eax
  int v5; // edi
  KeyValues *v6; // ebx
  const char *v7; // eax
  DmFileId_t v8; // eax
  int v9; // edi
  int v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // edi
  int x; // [esp+8h] [ebp-10h] BYREF
  int y; // [esp+Ch] [ebp-Ch] BYREF
  int column; // [esp+10h] [ebp-8h] BYREF
  int row; // [esp+14h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  this->GetCellAtPos(this, a2: x, a3: y, a4: &row, a5: &column);
  if ( code == (CDmElement *)107 )
  {
    if ( column == 2 && row >= 0 )
    {
      v4 = this->GetItemCount(this);
      if ( row < v4 )
      {
        v5 = ((int (__thiscall *)(CFileListManager *, int, int))this->GetItemIDFromRow)(a1: this, a2: row, a3: a2);
        v6 = this->GetItem(this, a2: v5);
        LOBYTE(code) = *KeyValues::GetString(
                          this: v6,
                          keyName: *(&g_ColInfo[0].columnName + 6 * column),
                          defaultValue: defaultValue) == 78;
        v7 = "Y";
        if ( (_BYTE)code == 0 )
          v7 = "N";
        KeyValues::SetString(this: v6, keyName: *(&g_ColInfo[0].columnName + 6 * column), value: v7);
        v8 = this->GetItemUserData(this, a2: v5);
        CFileListManager::SetLoaded(this, fileid: v8, bLoaded: code);
        this->RequestFocus(this, a2: 0);
        return;
      }
    }
LABEL_17:
    vgui::ListPanel::OnMousePressed(this, (ButtonCode_t)code);
    return;
  }
  if ( code != (CDmElement *)108 )
    goto LABEL_17;
  v9 = -1;
  if ( row >= 0 )
  {
    v10 = this->GetItemCount(this);
    if ( row < v10 )
    {
      v9 = this->GetItemIDFromRow(this, a2: row);
      if ( !this->IsItemSelected(this, a2: v9) )
        this->SetSingleSelectedItem(this, a2: v9);
    }
  }
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "OpenContextMenu", firstKey: "itemID", firstValue: v9);
  else
    v12 = nullptr;
  this->OnOpenContextMenu(this, a2: v12);
  KeyValues::deleteThis(this: v12);
}

//------------------------------------------------------------------------------
// Address: 0x00465970
// Name: protected: virtual void CFileListManager::OnOpenContextMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileListManager::OnOpenContextMenu(CFileListManager *this, KeyValues *pParams)
{
  vgui::Panel *v3; // eax
  int v4; // ebx
  vgui::Menu *v5; // eax
  vgui::Menu *v6; // eax
  vgui::Panel *v7; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  int v10; // eax
  int v11; // eax
  DmFileId_t v12; // edi
  const char *v13; // edi
  vgui::Panel *v14; // edi
  KeyValues *v15; // eax
  KeyValues *v16; // eax
  int v17; // eax
  vgui::Panel *v18; // edi
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  int v21; // eax
  vgui::Panel *v22; // edi
  KeyValues *v23; // eax
  KeyValues *v24; // eax
  int v25; // eax
  vgui::Panel *v26; // edi
  KeyValues *v27; // eax
  KeyValues *v28; // eax
  int v29; // eax
  vgui::Panel *v30; // edi
  KeyValues *v31; // eax
  KeyValues *v32; // eax
  int v33; // eax
  vgui::Panel *v34; // edi
  KeyValues *v35; // eax
  KeyValues *v36; // eax
  int v37; // eax
  vgui::Menu *v38; // eax
  int nOpenForEdit; // [esp+Ch] [ebp-18h]
  int nInPerforce; // [esp+10h] [ebp-14h]
  int nChanged; // [esp+14h] [ebp-10h]
  int nLoaded; // [esp+18h] [ebp-Ch]
  int nOnDisk; // [esp+1Ch] [ebp-8h]
  int nSelected; // [esp+20h] [ebp-4h]

  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v3 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v4 = 0;
    if ( v3 != nullptr )
      ((void (__thiscall *)(vgui::Panel *, int))v3->dtr_Panel)(a1: v3, a2: 1);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  else
  {
    v4 = 0;
  }
  v5 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v5 != nullptr )
    v6 = vgui::Menu::Menu(this: v5, parent: this, panelName: "ContextMenu");
  else
    v6 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: v6);
  if ( KeyValues::GetInt(this: pParams, keyName: "itemID", defaultValue: -1) >= 0 )
  {
    HIBYTE(pParams) = p4->IsConnectedToServer(this: p4, a2: true);
    nSelected = this->GetSelectedItemsCount(this);
    nLoaded = 0;
    nChanged = 0;
    nOnDisk = 0;
    nInPerforce = 0;
    nOpenForEdit = 0;
    if ( nSelected <= 0 )
      goto LABEL_26;
    do
    {
      v11 = this->GetSelectedItem(this, a2: v4);
      v12 = this->GetItemUserData(this, a2: v11);
      if ( g_pDataModel->IsFileLoaded(this: g_pDataModel, a2: v12) )
      {
        ++nLoaded;
        ++nChanged;
      }
      v13 = g_pDataModel->GetFileName(this: g_pDataModel, a2: v12);
      if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: v13, a3: nullptr) )
        ++nOnDisk;
      if ( HIBYTE(pParams) != 0 && p4->IsFileInPerforce(this: p4, a2: v13) )
      {
        ++nInPerforce;
        if ( p4->GetFileState(this: p4, a2: v13) != P4FILE_UNOPENED )
          ++nOpenForEdit;
      }
      ++v4;
    }
    while ( v4 < nSelected );
    if ( nLoaded >= nSelected || (LOBYTE(pParams) = 1, nOnDisk <= 0) )
LABEL_26:
      LOBYTE(pParams) = 0;
    v14 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v15 != nullptr )
      v16 = KeyValues::KeyValues(this: v15, setName: "load");
    else
      v16 = nullptr;
    v17 = ((int (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CFileListManager *, _DWORD))v14->__vftable[1].PaintTraverse)(
            a1: v14,
            a2: "Load",
            a3: v16,
            a4: this,
            a5: 0);
    ((void (__thiscall *)(vgui::Panel *, int, KeyValues *))v14->__vftable[1].GetKBMap)(a1: v14, a2: v17, a3: pParams);
    v18 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v19 != nullptr )
      v20 = KeyValues::KeyValues(this: v19, setName: "unload");
    else
      v20 = nullptr;
    v21 = ((int (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CFileListManager *, _DWORD))v18->__vftable[1].PaintTraverse)(
            a1: v18,
            a2: "Unload",
            a3: v20,
            a4: this,
            a5: 0);
    ((void (__thiscall *)(vgui::Panel *, int, bool))v18->__vftable[1].GetKBMap)(a1: v18, a2: v21, a3: nLoaded > 0);
    if ( nChanged <= 0 || (LOBYTE(pParams) = 1, nOnDisk != nSelected) )
      LOBYTE(pParams) = 0;
    v22 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v23 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v23 != nullptr )
      v24 = KeyValues::KeyValues(this: v23, setName: "save");
    else
      v24 = nullptr;
    v25 = ((int (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CFileListManager *, _DWORD))v22->__vftable[1].PaintTraverse)(
            a1: v22,
            a2: "Save",
            a3: v24,
            a4: this,
            a5: 0);
    ((void (__thiscall *)(vgui::Panel *, int, KeyValues *))v22->__vftable[1].GetKBMap)(a1: v22, a2: v25, a3: pParams);
    if ( nLoaded != 1 || (LOBYTE(pParams) = 1, nSelected != 1) )
      LOBYTE(pParams) = 0;
    v26 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v27 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v27 != nullptr )
      v28 = KeyValues::KeyValues(this: v27, setName: "saveas");
    else
      v28 = nullptr;
    v29 = ((int (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CFileListManager *, _DWORD))v26->__vftable[1].PaintTraverse)(
            a1: v26,
            a2: "Save As...",
            a3: v28,
            a4: this,
            a5: 0);
    ((void (__thiscall *)(vgui::Panel *, int, KeyValues *))v26->__vftable[1].GetKBMap)(a1: v26, a2: v29, a3: pParams);
    if ( nInPerforce >= nSelected || (LOBYTE(pParams) = 1, nOnDisk <= 0) )
      LOBYTE(pParams) = 0;
    v30 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v31 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v31 != nullptr )
      v32 = KeyValues::KeyValues(this: v31, setName: "p4add");
    else
      v32 = nullptr;
    v33 = ((int (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CFileListManager *, _DWORD))v30->__vftable[1].PaintTraverse)(
            a1: v30,
            a2: "Add To Perforce",
            a3: v32,
            a4: this,
            a5: 0);
    ((void (__thiscall *)(vgui::Panel *, int, KeyValues *))v30->__vftable[1].GetKBMap)(a1: v30, a2: v33, a3: pParams);
    if ( nOpenForEdit >= nSelected || (LOBYTE(pParams) = 1, nOnDisk <= 0) )
      LOBYTE(pParams) = 0;
    v34 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v35 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v35 != nullptr )
      v36 = KeyValues::KeyValues(this: v35, setName: "p4edit");
    else
      v36 = nullptr;
    v37 = ((int (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CFileListManager *, _DWORD))v34->__vftable[1].PaintTraverse)(
            a1: v34,
            a2: "Open For Edit",
            a3: v36,
            a4: this,
            a5: 0);
    ((void (__thiscall *)(vgui::Panel *, int, KeyValues *))v34->__vftable[1].GetKBMap)(a1: v34, a2: v37, a3: pParams);
  }
  else
  {
    v7 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
      v9 = KeyValues::KeyValues(this: v8, setName: "open");
    else
      v9 = nullptr;
    v10 = ((int (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CFileListManager *, _DWORD))v7->__vftable[1].PaintTraverse)(
            a1: v7,
            a2: "Open File...",
            a3: v9,
            a4: this,
            a5: 0);
    ((void (__thiscall *)(vgui::Panel *, int, int))v7->__vftable[1].GetKBMap)(a1: v7, a2: v10, a3: 1);
  }
  v38 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
  vgui::Menu::PlaceContextMenu(parent: this, menu: v38);
}

//------------------------------------------------------------------------------
// Address: 0x00465DC0
// Name: protected: virtual void CFileListManager::OnLoadFiles(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileListManager::OnLoadFiles(CFileListManager *this, KeyValues *pParams)
{
  int v3; // ebx
  int v4; // eax
  DmFileId_t v5; // edi
  int nSelected; // [esp+8h] [ebp-4h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CFileListManager::OnLoadFiles", a3: 5, a4: 256);
  v3 = 0;
  nSelected = this->GetSelectedItemsCount(this);
  if ( nSelected > 0 )
  {
    do
    {
      v4 = this->GetSelectedItem(this, a2: v3);
      v5 = this->GetItemUserData(this, a2: v4);
      if ( !g_pDataModel->IsFileLoaded(this: g_pDataModel, a2: v5) )
        CFileListManager::SetLoaded(this, fileid: v5, bLoaded: (CDmElement *)1);
      ++v3;
    }
    while ( v3 < nSelected );
  }
  this->Refresh(this);
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00465E70
// Name: protected: virtual void CFileListManager::OnUnloadFiles(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileListManager::OnUnloadFiles(CFileListManager *this, KeyValues *pParams)
{
  int v3; // ebx
  int v4; // eax
  DmFileId_t v5; // edi
  bool v6; // [esp+Ch] [ebp-8h]
  int nSelected; // [esp+10h] [ebp-4h]

  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CFileListManager::OnUnloadFiles", a3: 5, a4: 256);
  v3 = 0;
  nSelected = this->GetSelectedItemsCount(this);
  if ( nSelected > 0 )
  {
    do
    {
      v4 = this->GetSelectedItem(this, a2: v3);
      v5 = this->GetItemUserData(this, a2: v4);
      if ( g_pDataModel->IsFileLoaded(this: g_pDataModel, a2: v5) )
      {
        g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "CFileListManager::SetLoaded", a3: 5, a4: 256);
        v6 = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
        g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
        g_pDataModel->UnloadFile(this: g_pDataModel, a2: v5);
        g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: v6);
        g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
      }
      ++v3;
    }
    while ( v3 < nSelected );
  }
  this->Refresh(this);
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00465F90
// Name: protected: virtual void CFileListManager::OnSaveFiles(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileListManager::OnSaveFiles(CFileListManager *this, KeyValues *pParams)
{
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  DmFileId_t v6; // edi
  DmElementHandle_t v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  const char *v10; // edi
  const char *v11; // eax
  int nSelected; // [esp+Ch] [ebp-Ch]
  const char *pFilename; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v3 = this->GetSelectedItemsCount(this);
  v4 = 0;
  nSelected = v3;
  for ( i = 0; v4 < nSelected; i = v4 )
  {
    v5 = this->GetSelectedItem(this, a2: v4);
    v6 = this->GetItemUserData(this, a2: v5);
    if ( g_pDataModel->IsFileLoaded(this: g_pDataModel, a2: v6) )
    {
      pFilename = g_pDataModel->GetFileName(this: g_pDataModel, a2: v6);
      if ( pFilename != nullptr )
      {
        v7 = g_pDataModel->GetFileRoot(this: g_pDataModel, a2: v6);
        v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v7);
        v9 = v8;
        if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmElement::m_classType) )
        {
          v10 = g_pDataModel->GetFileFormat(this: g_pDataModel, a2: v6);
          v11 = g_pDataModel->GetDefaultEncoding(this: g_pDataModel, a2: v10);
          g_pDataModel->SaveToFile(this: g_pDataModel, a2: pFilename, a3: nullptr, a4: v11, a5: v10, a6: v9);
        }
      }
    }
    v4 = i + 1;
  }
  this->Refresh(this);
}

//------------------------------------------------------------------------------
// Address: 0x004660A0
// Name: protected: virtual void CFileListManager::OnFileSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFileListManager::OnFileSelected(CFileListManager *this, KeyValues *pParams)
{
  KeyValues *v2; // ebx
  KeyValues *String; // eax
  const char *v5; // edi
  KeyValues *Key; // eax
  int Int; // eax
  DmFileId_t v8; // edi
  DmElementHandle_t v9; // eax
  const char *v10; // ebx
  IDataModel_vtbl *v11; // edi
  int v12; // eax
  CDmElement *pRoot; // [esp+Ch] [ebp-4h]

  v2 = pParams;
  String = (KeyValues *)KeyValues::GetString(this: pParams, keyName: "fullpath", defaultValue: defaultValue);
  v5 = (const char *)String;
  pParams = String;
  if ( String != nullptr && *(_BYTE *)String != 0 )
  {
    Key = KeyValues::FindKey(this: v2, keyName: "OnSaveAs", bCreate: false);
    if ( Key != nullptr )
    {
      Int = KeyValues::GetInt(this: Key, keyName: "itemId", defaultValue: -1);
      if ( Int != -1 )
      {
        v8 = this->GetItemUserData(this, a2: Int);
        if ( v8 != DMFILEID_INVALID )
        {
          v9 = g_pDataModel->GetFileRoot(this: g_pDataModel, a2: v8);
          pRoot = GetElement<CDmElement>(hElement: v9);
          if ( pRoot != nullptr )
          {
            v10 = KeyValues::GetString(this: v2, keyName: "filterinfo", defaultValue: defaultValue);
            if ( v10 != nullptr )
            {
              g_pDataModel->SetFileName(this: g_pDataModel, a2: v8, a3: (const char *)pParams);
              v11 = g_pDataModel->__vftable;
              v12 = ((int (__thiscall *)(IDataModel *, const char *, const char *, CDmElement *))g_pDataModel->GetDefaultEncoding)(
                      a1: g_pDataModel,
                      a2: v10,
                      a3: v10,
                      a4: pRoot);
              ((void (__thiscall *)(IDataModel *, KeyValues *, _DWORD, int))v11->SaveToFile)(
                a1: g_pDataModel,
                a2: pParams,
                a3: 0,
                a4: v12);
              this->Refresh(this);
            }
          }
        }
      }
    }
    else if ( KeyValues::FindKey(this: v2, keyName: "OnOpen", bCreate: false) != nullptr )
    {
      pParams = nullptr;
      g_pDataModel->RestoreFromFile(
        this: g_pDataModel,
        a2: v5,
        a3: nullptr,
        a4: nullptr,
        a5: (CDmElement **)&pParams,
        a6: CR_DELETE_NEW,
        a7: nullptr);
      this->Refresh(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466200
// Name: public: static void CFileListManager::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFileListManager::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CFileListManager::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CFileListManager::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1124,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFileListManager");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OpenContextMenu";
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
// Address: 0x00466290
// Name: public: static void CFileListManager::PanelMessageFunc_OnOpenFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFileListManager::PanelMessageFunc_OnOpenFile::InitVar(int a1@<ebp>)
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
  if ( !`CFileListManager::PanelMessageFunc_OnOpenFile::InitVar'::`2'::bAdded )
  {
    `CFileListManager::PanelMessageFunc_OnOpenFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFileListManager");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "open";
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
// Address: 0x00466320
// Name: public: static void CFileListManager::PanelMessageFunc_OnLoadFiles::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFileListManager::PanelMessageFunc_OnLoadFiles::InitVar(int a1@<ebp>)
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
  if ( !`CFileListManager::PanelMessageFunc_OnLoadFiles::InitVar'::`2'::bAdded )
  {
    `CFileListManager::PanelMessageFunc_OnLoadFiles::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1132,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFileListManager");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "load";
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
// Address: 0x004663B0
// Name: public: static void CFileListManager::PanelMessageFunc_OnUnloadFiles::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFileListManager::PanelMessageFunc_OnUnloadFiles::InitVar(int a1@<ebp>)
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
  if ( !`CFileListManager::PanelMessageFunc_OnUnloadFiles::InitVar'::`2'::bAdded )
  {
    `CFileListManager::PanelMessageFunc_OnUnloadFiles::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CFileListManager::`vcall'{1136,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFileListManager");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "unload";
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
// Address: 0x00466440
// Name: public: static void CFileListManager::PanelMessageFunc_OnSaveFiles::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFileListManager::PanelMessageFunc_OnSaveFiles::InitVar(int a1@<ebp>)
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
  if ( !`CFileListManager::PanelMessageFunc_OnSaveFiles::InitVar'::`2'::bAdded )
  {
    `CFileListManager::PanelMessageFunc_OnSaveFiles::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CFileListManager::`vcall'{1140,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFileListManager");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "save";
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
// Address: 0x004664D0
// Name: public: static void CFileListManager::PanelMessageFunc_OnSaveFileAs::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFileListManager::PanelMessageFunc_OnSaveFileAs::InitVar(int a1@<ebp>)
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
  if ( !`CFileListManager::PanelMessageFunc_OnSaveFileAs::InitVar'::`2'::bAdded )
  {
    `CFileListManager::PanelMessageFunc_OnSaveFileAs::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CFileListManager::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFileListManager");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "saveas";
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
// Address: 0x00466560
// Name: public: static void CFileListManager::PanelMessageFunc_OnAddToPerforce::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFileListManager::PanelMessageFunc_OnAddToPerforce::InitVar(int a1@<ebp>)
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
  if ( !`CFileListManager::PanelMessageFunc_OnAddToPerforce::InitVar'::`2'::bAdded )
  {
    `CFileListManager::PanelMessageFunc_OnAddToPerforce::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFileListManager");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "p4add";
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
// Address: 0x004665F0
// Name: public: static void CFileListManager::PanelMessageFunc_OnOpenForEdit::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFileListManager::PanelMessageFunc_OnOpenForEdit::InitVar(int a1@<ebp>)
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
  if ( !`CFileListManager::PanelMessageFunc_OnOpenForEdit::InitVar'::`2'::bAdded )
  {
    `CFileListManager::PanelMessageFunc_OnOpenForEdit::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CFileListManager::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFileListManager");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "p4edit";
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
// Address: 0x00466680
// Name: public: static void CFileListManager::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFileListManager::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CFileListManager::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CFileListManager::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CFileListManager::`vcall'{1156,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFileListManager");
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
// Address: 0x00466710
// Name: public: static void CFileListManager::PanelMessageFunc_OnDataChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CFileListManager::PanelMessageFunc_OnDataChanged::InitVar(int a1@<ebp>)
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
  if ( !`CFileListManager::PanelMessageFunc_OnDataChanged::InitVar'::`2'::bAdded )
  {
    `CFileListManager::PanelMessageFunc_OnDataChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CFileListManager::`vcall'{1160,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CFileListManager");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DataChanged";
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
// Address: 0x004667A0
// Name: public: CFileListManager::CFileListManager(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CFileListManager *__userpurge CFileListManager::CFileListManager@<eax>(
        CFileListManager *this@<ecx>,
        int a2@<ebx>,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int v7; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::ListPanel::ListPanel(this, parent, panelName: "FileListManager");
  this->__vftable = (CFileListManager_vtbl *)&CFileListManager::`vftable';
  if ( `CFileListManager::ChainToMap'::`2'::chained == 0 )
  {
    `CFileListManager::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CFileListManager");
    v4->pfnClassName = CFileListManager::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::ListPanel");
  }
  if ( `CFileListManager::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CFileListManager::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CFileListManager");
    v5->pfnClassName = CFileListManager::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::ListPanel");
  }
  if ( `CFileListManager::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CFileListManager::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CFileListManager");
    v6->pfnClassName = CFileListManager::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::ListPanel");
  }
  CFileListManager::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  CFileListManager::PanelMessageFunc_OnOpenFile::InitVar(a1: (int)&savedregs);
  CFileListManager::PanelMessageFunc_OnLoadFiles::InitVar(a1: (int)&savedregs);
  CFileListManager::PanelMessageFunc_OnUnloadFiles::InitVar(a1: (int)&savedregs);
  CFileListManager::PanelMessageFunc_OnSaveFiles::InitVar(a1: (int)&savedregs);
  CFileListManager::PanelMessageFunc_OnSaveFileAs::InitVar(a1: (int)&savedregs);
  CFileListManager::PanelMessageFunc_OnAddToPerforce::InitVar(a1: (int)&savedregs);
  CFileListManager::PanelMessageFunc_OnOpenForEdit::InitVar(a1: (int)&savedregs);
  CFileListManager::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  CFileListManager::PanelMessageFunc_OnDataChanged::InitVar(a1: (int)&savedregs);
  this->m_hContextMenu.m_iPanelID = -1;
  vgui::ListPanel::SetMultiselectEnabled(this, bState: true);
  vgui::Panel::SetVisible(this, state: true);
  this->m_bRefreshRequired = false;
  vgui::Panel::SetSize(this, wide: 800, tall: 200);
  vgui::Panel::SetPos(this, x: 100, y: 100);
  AddColumn(pFileManager: this, ci: CI_FILENAME);
  AddColumn(pFileManager: this, ci: CI_PATH);
  AddColumn(pFileManager: this, ci: CI_LOADED);
  AddColumn(pFileManager: this, ci: CI_NUMELEMENTS);
  AddColumn(pFileManager: this, ci: CI_CHANGED);
  AddColumn(pFileManager: this, ci: CI_INPERFORCE);
  AddColumn(pFileManager: this, ci: CI_OPENFOREDIT);
  vgui::ListPanel::SetSortColumn(this, column: 0);
  CFileListManager::Refresh(this, a2);
  v7 = g_pVGuiSchemeManager->LoadSchemeFromFile(
         this: g_pVGuiSchemeManager,
         a2: "Resource/BoxRocket.res",
         a3: "BoxRocket");
  vgui::Panel::SetScheme(this, scheme: v7);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00466940
// Name: public: virtual struct vgui::PanelMessageMap __near * CFileListManager::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CFileListManager::GetMessageMap(CFileListManager *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CFileListManager::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CFileListManager::GetMessageMap'::`2'::s_pMap;
  `CFileListManager::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CFileListManager");
  `CFileListManager::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00466970
// Name: public: virtual struct PanelAnimationMap __near * CFileListManager::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CFileListManager::GetAnimMap(CFileListManager *this)
{
  return FindOrAddPanelAnimationMap(className: "CFileListManager");
}

//------------------------------------------------------------------------------
// Address: 0x00466980
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CFileListManager::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CFileListManager::GetKBMap(CFileListManager *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CFileListManager::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CFileListManager::GetKBMap'::`2'::s_pMap;
  `CFileListManager::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CFileListManager");
  `CFileListManager::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004669E0
// Name: public: CFileManagerFrame::CFileManagerFrame(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CFileManagerFrame *__userpurge CFileManagerFrame::CFileManagerFrame@<eax>(
        CFileManagerFrame *this@<ecx>,
        int a2@<ebx>,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CFileListManager *v7; // eax
  CFileListManager *v8; // eax
  unsigned int v9; // eax

  vgui::Frame::Frame(this, parent, panelName: "FileManagerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CFileManagerFrame_vtbl *)&CFileManagerFrame::`vftable';
  if ( `CFileManagerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CFileManagerFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CFileManagerFrame");
    v4->pfnClassName = CFileManagerFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CFileManagerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CFileManagerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CFileManagerFrame");
    v5->pfnClassName = CFileManagerFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CFileManagerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CFileManagerFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CFileManagerFrame");
    v6->pfnClassName = CFileManagerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Frame::SetTitle(this, title: "#BxFileManagerFrame", surfaceTitle: true);
  vgui::Frame::SetSizeable(this, state: true);
  vgui::Frame::SetCloseButtonVisible(this, state: false);
  vgui::Panel::SetMinimumSize(this, wide: 200, tall: 200);
  vgui::Panel::SetVisible(this, state: true);
  vgui::Panel::SetSize(this, wide: 800, tall: 200);
  vgui::Panel::SetPos(this, x: 100, y: 100);
  v7 = (CFileListManager *)MemAlloc_Alloc(nSize: 0x268u);
  if ( v7 != nullptr )
    v8 = CFileListManager::CFileListManager(this: v7, a2, parent: this);
  else
    v8 = nullptr;
  this->m_pFileListManager = v8;
  v8->Refresh(this: v8);
  v9 = g_pVGuiSchemeManager->LoadSchemeFromFile(
         this: g_pVGuiSchemeManager,
         a2: "Resource/BoxRocket.res",
         a3: "BoxRocket");
  vgui::Panel::SetScheme(this, scheme: v9);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00466B50
// Name: public: virtual struct vgui::PanelMessageMap __near * CFileManagerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CFileManagerFrame::GetMessageMap(CFileManagerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CFileManagerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CFileManagerFrame::GetMessageMap'::`2'::s_pMap;
  `CFileManagerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CFileManagerFrame");
  `CFileManagerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00466B80
// Name: public: virtual struct PanelAnimationMap __near * CFileManagerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CFileManagerFrame::GetAnimMap(CFileManagerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CFileManagerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x00466B90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CFileManagerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CFileManagerFrame::GetKBMap(CFileManagerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CFileManagerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CFileManagerFrame::GetKBMap'::`2'::s_pMap;
  `CFileManagerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CFileManagerFrame");
  `CFileManagerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}
