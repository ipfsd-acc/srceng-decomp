// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/qcgenerator.cpp
// Functions: 48
// ============================================================

#include "vgui2\matsys_controls\qcgenerator.h"

//------------------------------------------------------------------------------
// Address: 0x004021F0
// Name: public: static char const __near * CBrowseButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBrowseButton::GetPanelClassName()
{
  return "CBrowseButton";
}

//------------------------------------------------------------------------------
// Address: 0x00402200
// Name: public: void QCInfo::Init(class CQCGenerator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall QCInfo::Init(QCInfo *this, CQCGenerator *pPanel)
{
  this->pQCGenerator = pPanel;
  _V_strcpy(dest: this->pszSMDPath, src: defaultValue);
  _V_strcpy(dest: this->pszCollisionPath, src: defaultValue);
  _V_strcpy(dest: this->pszSurfaceProperty, src: "default");
  this->fScale = 1.0;
  this->bStaticProp = false;
  this->bMostlyOpaque = false;
  this->bDisableCollision = false;
  this->bReferenceAsPhys = false;
  this->bConcave = false;
  this->bAutomass = false;
  this->bNoAnimation = true;
  this->fMass = 10.0;
}

//------------------------------------------------------------------------------
// Address: 0x00402290
// Name: public: static char const __near * CQCGenerator::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CQCGenerator::GetPanelClassName()
{
  return "CQCGenerator";
}

//------------------------------------------------------------------------------
// Address: 0x004022A0
// Name: char __near * strrchrcount(char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl strrchrcount(char *string, int character, int count)
{
  int v4; // eax

  v4 = strlen(string);
  if ( v4 <= 0 )
    return nullptr;
  while ( 1 )
  {
    if ( string[v4 - 1] == character )
      --count;
    if ( count == 0 )
      break;
    if ( --v4 <= 0 )
      return nullptr;
  }
  return &string[v4 - 1];
}

//------------------------------------------------------------------------------
// Address: 0x004022F0
// Name: public: static char const __near * vgui::MessageBox::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::MessageBox::GetPanelClassName()
{
  return "MessageBox";
}

//------------------------------------------------------------------------------
// Address: 0x00402340
// Name: void VGUIMessageBox(class vgui::Panel __near *,char const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void VGUIMessageBox(vgui::Panel *pParent, char *pTitle, char *pMsg, ...)
{
  vgui::MessageBox *v3; // esi
  char pDest[4096]; // [esp+4h] [ebp-1000h] BYREF
  va_list params; // [esp+1014h] [ebp+10h] BYREF

  va_start(params, pMsg);
  V_vsnprintf(pDest, maxLen: 4096, pFormat: pMsg, params);
  v3 = (vgui::MessageBox *)operator new(nSize: 0x238u);
  if ( v3 != nullptr )
  {
    vgui::MessageBox::MessageBox(this: v3, title: pTitle, text: pDest, parent: pParent);
    v3->__vftable = (vgui::MessageBox_vtbl *)&CModalPreserveMessageBox::`vftable';
    v3[1].__vftable = (vgui::MessageBox_vtbl *)g_pVGuiInput->GetAppModalSurface(this: g_pVGuiInput);
  }
  else
  {
    v3 = nullptr;
  }
  v3->DoModal_2(this: v3, a2: nullptr);
  v3->Activate(this: v3);
  v3->RequestFocus(this: v3, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004023F0
// Name: public: void QCInfo::SyncToControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall QCInfo::SyncToControls(QCInfo *this)
{
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *v11; // eax
  vgui::ComboBox *v12; // edi
  int v13; // ebp
  int v14; // ebx
  char *pszSurfaceProperty; // esi
  char tempText[264]; // [esp+2Ch] [ebp-108h] BYREF

  ChildByName = vgui::Panel::FindChildByName(this: this->pQCGenerator, childName: "staticPropCheck", recurseDown: false);
  ((void (__thiscall *)(vgui::Panel *, bool))ChildByName->__vftable[1].LookupElementBounds)(
    a1: ChildByName,
    a2: this->bStaticProp);
  v3 = vgui::Panel::FindChildByName(this: this->pQCGenerator, childName: "mostlyOpaqueCheck", recurseDown: false);
  ((void (__thiscall *)(vgui::Panel *, bool))v3->__vftable[1].LookupElementBounds)(a1: v3, a2: this->bMostlyOpaque);
  v4 = vgui::Panel::FindChildByName(this: this->pQCGenerator, childName: "disableCollisionsCheck", recurseDown: false);
  ((void (__thiscall *)(vgui::Panel *, bool))v4->__vftable[1].LookupElementBounds)(a1: v4, a2: this->bDisableCollision);
  v5 = vgui::Panel::FindChildByName(this: this->pQCGenerator, childName: "referencePhysicsCheck", recurseDown: false);
  ((void (__thiscall *)(vgui::Panel *, bool))v5->__vftable[1].LookupElementBounds)(a1: v5, a2: this->bReferenceAsPhys);
  v6 = vgui::Panel::FindChildByName(this: this->pQCGenerator, childName: "concaveCheck", recurseDown: false);
  ((void (__thiscall *)(vgui::Panel *, bool))v6->__vftable[1].LookupElementBounds)(a1: v6, a2: this->bConcave);
  v7 = vgui::Panel::FindChildByName(this: this->pQCGenerator, childName: "automassCheck", recurseDown: false);
  ((void (__thiscall *)(vgui::Panel *, bool))v7->__vftable[1].LookupElementBounds)(a1: v7, a2: this->bAutomass);
  V_snprintf(pDest: &tempText[4], maxLen: 10, pFormat: "%d", (int)this->fMass);
  v8 = vgui::Panel::FindChildByName(this: this->pQCGenerator, childName: "massField", recurseDown: false);
  ((void (__thiscall *)(vgui::Panel *, char *))v8->__vftable[1].GetVPanel)(a1: v8, a2: &tempText[4]);
  V_snprintf(pDest: &tempText[4], maxLen: 10, pFormat: "%d", (int)this->fScale);
  v9 = vgui::Panel::FindChildByName(this: this->pQCGenerator, childName: "scaleField", recurseDown: false);
  ((void (__thiscall *)(vgui::Panel *, char *))v9->__vftable[1].GetVPanel)(a1: v9, a2: &tempText[4]);
  v10 = vgui::Panel::FindChildByName(this: this->pQCGenerator, childName: "collisionSMDField", recurseDown: false);
  ((void (__thiscall *)(vgui::Panel *, char *))v10->__vftable[1].GetVPanel)(a1: v10, a2: this->pszCollisionPath);
  v11 = vgui::Panel::FindChildByName(this: this->pQCGenerator, childName: "materialsField", recurseDown: false);
  ((void (__thiscall *)(vgui::Panel *, char *))v11->__vftable[1].GetVPanel)(a1: v11, a2: this->pszMaterialPath);
  v12 = (vgui::ComboBox *)vgui::Panel::FindChildByName(
                            this: this->pQCGenerator,
                            childName: "surfacePropertyDropDown",
                            recurseDown: false);
  v13 = v12->GetItemCount(this: v12);
  v14 = 0;
  if ( v13 > 0 )
  {
    pszSurfaceProperty = this->pszSurfaceProperty;
    while ( 1 )
    {
      vgui::ComboBox::GetItemText(this: v12, itemID: v14, text: &tempText[4], bufLenInBytes: 260);
      if ( _V_strcmp(s1: &tempText[4], s2: pszSurfaceProperty) == 0 )
        break;
      if ( ++v14 >= v13 )
        return;
    }
    v12->SetItemEnabled(this: v12, a2: v14, a3: true);
    v12->SetText(this: v12, a2: &tempText[4]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402630
// Name: public: virtual void vgui::Button::OnHotkey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Button::OnHotkey(vgui::Button *this)
{
  this->DoClick(this);
}

//------------------------------------------------------------------------------
// Address: 0x00402640
// Name: private: void CBrowseButton::SetCharVar(char __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrowseButton::SetCharVar(CBrowseButton *this, char **pVar, const char *pszNewText)
{
  int v3; // esi
  char *v4; // eax

  if ( *pVar == nullptr )
  {
LABEL_6:
    if ( pszNewText != nullptr )
    {
      v3 = _V_strlen(str: pszNewText) + 1;
      v4 = (char *)operator new(nSize: v3);
      *pVar = v4;
      V_strncpy(pDest: v4, pSrc: pszNewText, maxLen: v3);
    }
    return;
  }
  if ( pszNewText == nullptr || _V_strcmp(s1: *pVar, s2: pszNewText) != 0 )
  {
    if ( *pVar != nullptr )
    {
      free(pMem: *pVar);
      *pVar = nullptr;
    }
    goto LABEL_6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004026A0
// Name: private: void CBrowseButton::SetActionMessage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrowseButton::SetActionMessage(CBrowseButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(
           this: v2,
           setName: "browse",
           firstKey: "directory",
           firstValue: this->pszStartingDirectory,
           secondKey: "filter",
           secondValue: this->pszFileFilter);
  else
    v3 = nullptr;
  KeyValues::SetString(this: v3, keyName: "targetField", value: this->pszTargetField);
  this->SetCommand(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00402700
// Name: char const __near * ParseKeyvalue(char const __near *,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl ParseKeyvalue(const char *pBuffer, char *key, char *value)
{
  const char *v3; // esi
  const char *v5; // edi
  char com_token[1028]; // [esp+4h] [ebp-404h] BYREF

  v3 = ParseFile(pFileBytes: pBuffer, pToken: &com_token[4], pWasQuoted: nullptr, pCharSet: nullptr);
  if ( _V_strlen(str: &com_token[4]) < 1024 )
  {
    V_strncpy(pDest: key, pSrc: &com_token[4], maxLen: 1024);
    _V_strlower(start: key);
  }
  if ( _V_strcmp(s1: key, s2: "}") != 0 )
  {
    v5 = ParseFile(pFileBytes: v3, pToken: &com_token[4], pWasQuoted: nullptr, pCharSet: nullptr);
    if ( _V_strlen(str: &com_token[4]) < 1024 )
    {
      V_strncpy(pDest: value, pSrc: &com_token[4], maxLen: 1024);
      _V_strlower(start: value);
    }
    return v5;
  }
  else
  {
    *value = 0;
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004027D0
// Name: public: void CQCGenerator::BrowseFile(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQCGenerator::BrowseFile(CQCGenerator *this, KeyValues *data)
{
  const char *String; // ebx
  vgui::FileOpenDialog *v4; // eax
  vgui::FileOpenDialog *v5; // esi
  const char *v6; // eax

  String = KeyValues::GetString(this: data, keyName: "filter", defaultValue: defaultValue);
  v4 = (vgui::FileOpenDialog *)operator new(nSize: 0x6B0u);
  if ( v4 != nullptr )
    v5 = vgui::FileOpenDialog::FileOpenDialog(
           this: v4,
           parent: this,
           title: "Select File",
           bOpenOnly: true,
           pContextKeyValues: nullptr);
  else
    v5 = nullptr;
  vgui::FileOpenDialog::AddFilter(this: v5, filter: String, filterName: String, bActive: true, pFilterInfo: nullptr);
  v5->AddActionSignalTarget_2(this: v5, a2: this);
  v6 = KeyValues::GetString(this: data, keyName: "directory", defaultValue: defaultValue);
  vgui::FileOpenDialog::SetStartDirectory(this: v5, dir: v6);
  vgui::FileOpenDialog::DoModal(this: v5, bUnused: true);
}

//------------------------------------------------------------------------------
// Address: 0x00402860
// Name: public: virtual void CQCGenerator::OnFileSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQCGenerator::OnFileSelected(CQCGenerator *this, KeyValues *data)
{
  vgui::Panel *ChildByName; // edi
  vgui::Panel_vtbl *v4; // ebx
  const char *String; // eax

  if ( this != (CQCGenerator *)-392 )
  {
    ChildByName = vgui::Panel::FindChildByName(this, childName: this->m_szTargetField, recurseDown: false);
    v4 = ChildByName->__vftable;
    String = KeyValues::GetString(this: data, keyName: "fullpath", defaultValue: defaultValue);
    ((void (__thiscall *)(vgui::Panel *, const char *))v4[1].GetVPanel)(a1: ChildByName, a2: String);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004028B0
// Name: public: virtual void CQCGenerator::OnDirectorySelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQCGenerator::OnDirectorySelected(CQCGenerator *this, KeyValues *data)
{
  vgui::Panel *ChildByName; // edi
  vgui::Panel_vtbl *v4; // ebx
  const char *String; // eax

  if ( this != (CQCGenerator *)-392 )
  {
    ChildByName = vgui::Panel::FindChildByName(this, childName: this->m_szTargetField, recurseDown: false);
    v4 = ChildByName->__vftable;
    String = KeyValues::GetString(this: data, keyName: "dir", defaultValue: defaultValue);
    ((void (__thiscall *)(vgui::Panel *, const char *))v4[1].GetVPanel)(a1: ChildByName, a2: String);
    this->Repaint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402900
// Name: public: void CQCGenerator::InitializeSMDPaths(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQCGenerator::InitializeSMDPaths(CQCGenerator *this, const char *pszPath, char *pszScene)
{
  CQCGenerator *v3; // esi
  char *v4; // eax
  int v5; // edx
  char v6; // cl
  int *v7; // eax
  const char *v8; // edi
  const char *v9; // ebp
  unsigned int v10; // ebx
  const char *v11; // ebx
  char *pszSMDPath; // edx
  const char *v13; // eax
  int v14; // esi
  char v15; // cl
  char *pszCollisionPath; // edx
  const char *v17; // eax
  int v18; // esi
  char v19; // cl
  int v20; // eax
  KeyValues *v21; // eax
  KeyValues *v22; // eax
  char *v23; // eax
  char v24; // cl
  char v25; // [esp+28h] [ebp-1112h]
  char v26; // [esp+29h] [ebp-1111h]
  int *v27; // [esp+2Ah] [ebp-1110h]
  int v29; // [esp+32h] [ebp-1108h]
  unsigned int v30; // [esp+36h] [ebp-1104h]
  char pDest[256]; // [esp+3Ah] [ebp-1100h] BYREF
  char src[1024]; // [esp+13Ah] [ebp-1000h] BYREF
  char pSrc[1024]; // [esp+53Ah] [ebp-C00h] BYREF
  char dest[2048]; // [esp+93Ah] [ebp-800h] BYREF

  v3 = this;
  v4 = pszScene;
  v5 = this->m_QCInfo_t.pszSceneName - pszScene;
  do
  {
    v6 = *v4;
    v4[v5] = *v4;
    ++v4;
  }
  while ( v6 != 0 );
  v7 = (int *)operator new(nSize: 4u);
  if ( v7 != nullptr )
  {
    *v7 = 0;
    v27 = v7;
  }
  else
  {
    v27 = nullptr;
  }
  v8 = pszPath;
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: pszPath, a3: "SMD_DIR", a4: PATH_ADD_TO_TAIL);
  v9 = g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: "*.smd", a3: v27);
  v25 = 0;
  v26 = 0;
  v10 = _V_strlen(str: pszScene);
  v30 = v10;
  v29 = 1;
  if ( v9 != nullptr )
  {
    while ( 1 )
    {
      if ( strncmp(first: pszScene, last: v9, count: v10) == 0 )
      {
        v11 = &v9[v10];
        if ( strncmp(first: v11, last: "_ref", count: 4u) == 0 || strncmp(first: v11, last: ".smd", count: 4u) == 0 )
        {
          pszSMDPath = v3->m_QCInfo_t.pszSMDPath;
          v25 = 1;
          v13 = v8;
          v14 = v3->m_QCInfo_t.pszSMDPath - v8;
          do
          {
            v15 = *v13;
            v13[v14] = *v13;
            ++v13;
          }
          while ( v15 != 0 );
          strcat(pszSMDPath, v9);
          v8 = pszPath;
          v3 = this;
        }
        if ( strncmp(first: v11, last: "_phy", count: 4u) == 0 || strncmp(first: v11, last: "_col", count: 4u) == 0 )
        {
          pszCollisionPath = v3->m_QCInfo_t.pszCollisionPath;
          v26 = 1;
          v17 = v8;
          v18 = v3->m_QCInfo_t.pszCollisionPath - v8;
          do
          {
            v19 = *v17;
            v17[v18] = *v17;
            ++v17;
          }
          while ( v19 != 0 );
          strcat(pszCollisionPath, v9);
          v8 = pszPath;
          v3 = this;
        }
        if ( strncmp(first: v11, last: "_lod", count: 4u) == 0 )
        {
          v20 = _V_strlen(str: pDest);
          V_snprintf(pDest, maxLen: v20, pFormat: "lod%d", v29);
          v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v21 != nullptr )
            v22 = KeyValues::KeyValues(
                    this: v21,
                    setName: pDest,
                    firstKey: "SMD",
                    firstValue: v9,
                    secondKey: "LOD",
                    secondValue: "10");
          else
            v22 = nullptr;
          v3->m_pLODPanel->AddItem(this: v3->m_pLODPanel, a2: v22, a3: v29++, a4: false, a5: false);
        }
      }
      v9 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: *v27);
      if ( v9 == nullptr )
        break;
      v10 = v30;
    }
  }
  memset(dest, 0, sizeof(dest));
  memset(src, 0, sizeof(src));
  memset(pSrc, 0, sizeof(pSrc));
  if ( v25 == 0 )
  {
    strcat(v3->m_QCInfo_t.pszSMDPath, v8);
    strcat(v3->m_QCInfo_t.pszSMDPath, pszScene);
    strcat(v3->m_QCInfo_t.pszSMDPath, ".smd");
    V_snprintf(
      pDest: src,
      maxLen: 1024,
      pFormat: "Reference SMD not found.\n"
      "\n"
      "Valid default reference SMDs are %s%s_ref*.smd and %s%s.smd\n"
      "Using default of %s. Model will not compile.\n"
      "\n",
      pszPath,
      pszScene,
      pszPath,
      pszScene,
      v3->m_QCInfo_t.pszSMDPath);
    v8 = pszPath;
    v3 = this;
  }
  if ( v26 == 0 )
  {
    V_snprintf(
      pDest: pSrc,
      maxLen: 1024,
      pFormat: "Collision SMD not found.\n\nThe valid default collision SMD is %s%s_phy*.smd.\nUsing reference SMD as default.\n",
      v8,
      pszScene);
    v23 = v3->m_QCInfo_t.pszSMDPath;
    do
    {
      v24 = *v23;
      v23[260] = *v23;
      ++v23;
    }
    while ( v24 != 0 );
    v3->m_QCInfo_t.bReferenceAsPhys = true;
  }
  if ( v25 == 0 || v26 == 0 )
  {
    _V_strcpy(dest, src);
    V_strncat(pDest: dest, pSrc, destBufferSize: 0x400u, max_chars_to_copy: -1);
    VGUIMessageBox(pParent: v3, pTitle: "Error Initializing Paths", pMsg: dest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402D50
// Name: public: void CQCGenerator::DeleteLOD(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQCGenerator::DeleteLOD(CQCGenerator *this)
{
  int i; // esi
  int v3; // eax

  for ( i = this->m_pLODPanel->GetSelectedItemsCount(this: this->m_pLODPanel) - 1; i >= 0; --i )
  {
    v3 = this->m_pLODPanel->GetSelectedItem(this: this->m_pLODPanel, a2: i);
    this->m_pLODPanel->RemoveItem(this: this->m_pLODPanel, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402DA0
// Name: public: void CQCGenerator::EditLOD(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQCGenerator::EditLOD(CQCGenerator *this)
{
  vgui::TextEntry *m_pLODEdit; // ecx
  vgui::TextEntry *v3; // eax
  vgui::TextEntry *v4; // eax
  int v5; // eax
  vgui::ListPanel *m_pLODPanel; // ecx
  int v7; // eax
  vgui::ListPanel *v8; // ecx
  vgui::TextEntry *v9; // [esp-8h] [ebp-Ch]

  if ( this->m_pLODPanel->GetSelectedItemsCount(this: this->m_pLODPanel) == 1
    && !this->m_pLODPanel->IsInEditMode(this: this->m_pLODPanel) )
  {
    m_pLODEdit = this->m_pLODEdit;
    if ( m_pLODEdit != nullptr )
    {
      m_pLODEdit->DeletePanel(this: m_pLODEdit);
      this->m_pLODEdit = nullptr;
    }
    v3 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
    if ( v3 != nullptr )
      v4 = vgui::TextEntry::TextEntry(this: v3, parent: this, panelName: "Edit");
    else
      v4 = nullptr;
    this->m_pLODEdit = v4;
    v4->SendNewLine(this: v4, a2: true);
    v5 = this->m_pLODPanel->GetSelectedItem(this: this->m_pLODPanel, a2: 0);
    m_pLODPanel = this->m_pLODPanel;
    this->m_nSelectedSequence = v5;
    v7 = m_pLODPanel->GetSelectedColumn(this: m_pLODPanel);
    v8 = this->m_pLODPanel;
    v9 = this->m_pLODEdit;
    this->m_nSelectedColumn = v7;
    v8->EnterEditMode(this: v8, a2: this->m_nSelectedSequence, a3: v7, a4: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402E80
// Name: public: virtual void CQCGenerator::OnNewLODText(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQCGenerator::OnNewLODText(CQCGenerator *this)
{
  KeyValues *FirstValue; // edi
  int v3; // ebx
  const char *i; // ebp
  wchar_t szEditText[260]; // [esp+10h] [ebp-20Ch] BYREF

  *(_DWORD *)szEditText = this->m_pLODPanel->GetItem(this: this->m_pLODPanel, a2: this->m_nSelectedSequence);
  FirstValue = KeyValues::GetFirstValue(this: *(KeyValues **)szEditText);
  v3 = 0;
  for ( i = KeyValues::GetName(this: FirstValue); v3 < this->m_nSelectedColumn; i = KeyValues::GetName(this: FirstValue) )
  {
    FirstValue = KeyValues::GetNextValue(this: FirstValue);
    ++v3;
  }
  this->m_pLODEdit->GetText(this: this->m_pLODEdit, a2: &szEditText[2], a3: 260);
  KeyValues::SetWString(this: *(KeyValues **)szEditText, keyName: i, value: &szEditText[2]);
  this->m_pLODPanel->LeaveEditMode(this: this->m_pLODPanel);
  this->m_pLODPanel->InvalidateLayout(this: this->m_pLODPanel, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00402F80
// Name: public: virtual struct vgui::PanelMessageMap __near * CBrowseButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBrowseButton::GetMessageMap(CBrowseButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBrowseButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBrowseButton::GetMessageMap'::`2'::s_pMap;
  `CBrowseButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBrowseButton");
  `CBrowseButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402FB0
// Name: public: virtual struct PanelAnimationMap __near * CBrowseButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBrowseButton::GetAnimMap(CBrowseButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CBrowseButton");
}

//------------------------------------------------------------------------------
// Address: 0x00402FC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBrowseButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBrowseButton::GetKBMap(CBrowseButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBrowseButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBrowseButton::GetKBMap'::`2'::s_pMap;
  `CBrowseButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBrowseButton");
  `CBrowseButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402FF0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MessageBox::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MessageBox::GetMessageMap(vgui::MessageBox *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MessageBox::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetMessageMap'::`2'::s_pMap;
  `vgui::MessageBox::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MessageBox");
  `vgui::MessageBox::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403020
// Name: public: virtual struct PanelAnimationMap __near * vgui::MessageBox::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MessageBox::GetAnimMap(vgui::MessageBox *this)
{
  return FindOrAddPanelAnimationMap(className: "MessageBox");
}

//------------------------------------------------------------------------------
// Address: 0x00403030
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MessageBox::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MessageBox::GetKBMap(vgui::MessageBox *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MessageBox::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MessageBox::GetKBMap'::`2'::s_pMap;
  `vgui::MessageBox::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MessageBox");
  `vgui::MessageBox::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403060
// Name: public: CBrowseButton::CBrowseButton(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CBrowseButton *__thiscall CBrowseButton::CBrowseButton(CBrowseButton *this, vgui::Panel *pParent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi

  vgui::Button::Button(
    this,
    parent: pParent,
    panelName: "Browse Button",
    text: "...",
    pActionSignalTarget: pParent,
    pCmd: "browse");
  this->__vftable = (CBrowseButton_vtbl *)&CBrowseButton::`vftable';
  if ( `CBrowseButton::ChainToMap'::`2'::chained == 0 )
  {
    `CBrowseButton::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CBrowseButton");
    v3->pfnClassName = CBrowseButton::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Button");
  }
  if ( `CBrowseButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBrowseButton::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CBrowseButton");
    v4->pfnClassName = CBrowseButton::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Button");
  }
  if ( `CBrowseButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBrowseButton::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CBrowseButton");
    v5->pfnClassName = CBrowseButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Button");
  }
  vgui::Panel::SetParent(this, newParent: pParent);
  this->pszStartingDirectory = nullptr;
  this->pszFileFilter = nullptr;
  this->pszTargetField = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00403180
// Name: public: void CBrowseButton::InitBrowseInfo(int,int,char __near *,char const __near *,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBrowseButton::InitBrowseInfo(
        CBrowseButton *this,
        int x,
        int y,
        char *pszName,
        const char *pszDir,
        char *pszFilter,
        char *pszField)
{
  vgui::Panel::SetSize(this, wide: 24, tall: 24);
  vgui::Panel::SetPos(this, x, y);
  vgui::Panel::SetName(this, panelName: pszName);
  CBrowseButton::SetCharVar(this, pVar: &this->pszStartingDirectory, pszNewText: pszDir);
  CBrowseButton::SetCharVar(this, pVar: &this->pszFileFilter, pszNewText: pszFilter);
  CBrowseButton::SetCharVar(this, pVar: &this->pszTargetField, pszNewText: pszField);
  CBrowseButton::SetActionMessage(this);
}

//------------------------------------------------------------------------------
// Address: 0x004031F0
// Name: public: virtual void CQCGenerator::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQCGenerator::OnKeyCodeTyped(CQCGenerator *this, ButtonCode_t code)
{
  if ( code == KEY_ENTER )
    CQCGenerator::EditLOD(this);
}

//------------------------------------------------------------------------------
// Address: 0x00403200
// Name: public: virtual void CQCGenerator::OnBrowse(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQCGenerator::OnBrowse(CQCGenerator *this, KeyValues *data)
{
  const char *String; // eax
  const char *v4; // eax

  String = KeyValues::GetString(this: data, keyName: "targetField", defaultValue: defaultValue);
  _V_strcpy(dest: this->m_szTargetField, src: String);
  v4 = KeyValues::GetString(this: data, keyName: "filter", defaultValue: defaultValue);
  if ( _V_strlen(str: v4) != 0 )
    CQCGenerator::BrowseFile(this, data);
}

//------------------------------------------------------------------------------
// Address: 0x004032F0
// Name: public: bool CQCGenerator::GenerateQCFile(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CQCGenerator::GenerateQCFile(CQCGenerator *this)
{
  char *pszSMDPath; // esi
  int v3; // eax
  int v4; // eax
  char v5; // cl
  unsigned int v6; // eax
  char *v7; // edi
  char v8; // cl
  char *v9; // edi
  char v10; // al
  void *v11; // eax
  void *v12; // ebp
  const char *v14; // esi
  int v15; // eax
  char *v16; // eax
  char v17; // cl
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int (*FPrintf)(IFileSystem *, void *, const char *, ...); // edx
  int v23; // [esp+44h] [ebp-C90h]
  int i; // [esp+48h] [ebp-C8Ch]
  _PROCESS_INFORMATION process; // [esp+4Ch] [ebp-C88h] BYREF
  _STARTUPINFOA startup; // [esp+5Ch] [ebp-C78h] BYREF
  char v27; // [esp+A3h] [ebp-C31h] BYREF
  char szName[264]; // [esp+A4h] [ebp-C30h] BYREF
  char szPath[264]; // [esp+1ACh] [ebp-B28h] BYREF
  LODInfo thisLOD; // [esp+2B4h] [ebp-A20h] BYREF
  char szModelName[264]; // [esp+3BCh] [ebp-918h] BYREF
  char szCommand[264]; // [esp+4C4h] [ebp-810h] BYREF
  char szGamePath[264]; // [esp+5CCh] [ebp-708h] BYREF
  char studiomdlPath[512]; // [esp+6D4h] [ebp-600h] BYREF
  char szSaveError[1024]; // [esp+8D4h] [ebp-400h] BYREF

  pszSMDPath = this->m_QCInfo_t.pszSMDPath;
  strrchr(string: (unsigned __int8 *)this->m_QCInfo_t.pszSMDPath, chr: 0x5Cu);
  V_strncpy(pDest: szPath, pSrc: pszSMDPath, maxLen: v3 - (_DWORD)this - 670);
  v4 = 0;
  do
  {
    v5 = szPath[v4];
    szName[v4++] = v5;
  }
  while ( v5 != 0 );
  v6 = strlen(this->m_QCInfo_t.pszSceneName) + 1;
  v7 = &v27;
  do
    v8 = *++v7;
  while ( v8 != 0 );
  qmemcpy(v7, this->m_QCInfo_t.pszSceneName, v6);
  v9 = &v27;
  do
    v10 = *++v9;
  while ( v10 != 0 );
  strcpy(v9, ".qc");
  v11 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: szName, a3: "wt", a4: 0);
  v12 = v11;
  if ( v11 == nullptr )
  {
    memset(szSaveError, 0, sizeof(szSaveError));
    V_snprintf(
      pDest: szSaveError,
      maxLen: 1024,
      pFormat: "Save failed: invalid file name '%s'\n\nDirectory '%s' must exist.",
      szName,
      szPath);
    VGUIMessageBox(pParent: this, pTitle: "QC Generator error", pMsg: szSaveError);
    return false;
  }
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v11, a3: "//\n// .qc file version 1.0\n\n");
  v14 = strrchrcount(string: szName, character: 92, count: 2) + 1;
  strrchr(string: (unsigned __int8 *)szName, chr: 0x2Eu);
  V_strncpy(pDest: szModelName, pSrc: v14, maxLen: v15 - (_DWORD)v14 + 1);
  v16 = (char *)&thisLOD.iLOD + 3;
  do
    v17 = *++v16;
  while ( v17 != 0 );
  strcpy(v16, ".mdl");
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v12, a3: "$modelname %s\n\n", szModelName);
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v12, a3: "$scale %f\n", this->m_QCInfo_t.fScale);
  strrchr(string: (unsigned __int8 *)this->m_QCInfo_t.pszSMDPath, chr: 0x5Cu);
  g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v12, a3: "$body \"Body\" \"%s\"\n", v18 + 1);
  if ( this->m_QCInfo_t.bStaticProp )
    g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v12, a3: "$staticprop\n");
  if ( this->m_QCInfo_t.bMostlyOpaque )
    g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v12, a3: "$mostlyopaque\n");
  g_pFullFileSystem->FPrintf(
    this: g_pFullFileSystem,
    a2: v12,
    a3: "$surfaceprop \"%s\"\n\n",
    this->m_QCInfo_t.pszSurfaceProperty);
  g_pFullFileSystem->FPrintf(
    this: g_pFullFileSystem,
    a2: v12,
    a3: "$cdmaterials %s\n\n",
    this->m_QCInfo_t.pszMaterialPath);
  if ( this->m_QCInfo_t.bStaticProp || this->m_QCInfo_t.bNoAnimation )
  {
    g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v12, a3: "// --------- Animation sequences -------\n");
    strrchr(string: (unsigned __int8 *)this->m_QCInfo_t.pszSMDPath, chr: 0x5Cu);
    g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v12, a3: "$sequence  \"idle\" \"%s\" fps 30\n\n", v19 + 1);
  }
  i = 0;
  if ( this->m_QCInfo_t.LODs.m_Size > 0 )
  {
    v23 = 0;
    do
    {
      thisLOD = this->m_QCInfo_t.LODs.m_Memory.m_pMemory[v23];
      strrchr(string: (unsigned __int8 *)this->m_QCInfo_t.pszSMDPath, chr: 0x5Cu);
      g_pFullFileSystem->FPrintf(
        this: g_pFullFileSystem,
        a2: v12,
        a3: "$lod %d\n{\n\treplacemodel \"%s\" \"%s\"\n}\n\n",
        thisLOD.iLOD,
        v20 + 1,
        &thisLOD);
      ++v23;
      ++i;
    }
    while ( i < this->m_QCInfo_t.LODs.m_Size );
  }
  if ( !this->m_QCInfo_t.bDisableCollision )
  {
    g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v12, a3: "\n");
    if ( this->m_QCInfo_t.bReferenceAsPhys )
    {
      strrchr(string: (unsigned __int8 *)this->m_QCInfo_t.pszSMDPath, chr: 0x5Cu);
    }
    else
    {
      if ( _V_strcmp(s1: this->m_QCInfo_t.pszCollisionPath, s2: defaultValue) == 0 )
      {
LABEL_27:
        g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v12, a3: " {\n\t// Mass in kilograms\n ");
        FPrintf = g_pFullFileSystem->FPrintf;
        if ( this->m_QCInfo_t.bAutomass )
          FPrintf(this: g_pFullFileSystem, a2: v12, a3: "\t$automass\n");
        else
          FPrintf(this: g_pFullFileSystem, a2: v12, a3: "\t$mass %f\n", this->m_QCInfo_t.fMass);
        if ( this->m_QCInfo_t.bConcave )
          g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v12, a3: "\t$concave\n");
        g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v12, a3: "}\n\n");
        goto LABEL_33;
      }
      strrchr(string: (unsigned __int8 *)this->m_QCInfo_t.pszCollisionPath, chr: 0x5Cu);
    }
    g_pFullFileSystem->FPrintf(this: g_pFullFileSystem, a2: v12, a3: "$collisionmodel \"%s\"", v21 + 1);
    goto LABEL_27;
  }
LABEL_33:
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v12);
  g_pFullFileSystem->RelativePathToFullPath(
    this: g_pFullFileSystem,
    a2: "studiomdl.bat",
    a3: nullptr,
    a4: studiomdlPath,
    a5: 512,
    a6: FILTER_NONE,
    a7: nullptr);
  GetVConfigRegistrySetting(pName: "VProject", pReturn: szGamePath, size: 260);
  memset(dst: (int)&startup, value: nullptr, count: sizeof(startup));
  startup.cb = 68;
  sprintf(string: szCommand, format: "%s -game %s %s", studiomdlPath, szGamePath, szName);
  return CreateProcessA(
           lpApplicationName: nullptr,
           lpCommandLine: szCommand,
           lpProcessAttributes: nullptr,
           lpThreadAttributes: nullptr,
           bInheritHandles: true,
           dwCreationFlags: 0x10u,
           lpEnvironment: nullptr,
           lpCurrentDirectory: nullptr,
           lpStartupInfo: &startup,
           lpProcessInformation: &process);
}

//------------------------------------------------------------------------------
// Address: 0x00403890
// Name: public: virtual struct vgui::PanelMessageMap __near * CQCGenerator::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CQCGenerator::GetMessageMap(CQCGenerator *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CQCGenerator::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CQCGenerator::GetMessageMap'::`2'::s_pMap;
  `CQCGenerator::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CQCGenerator");
  `CQCGenerator::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004038C0
// Name: public: virtual struct PanelAnimationMap __near * CQCGenerator::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CQCGenerator::GetAnimMap(CQCGenerator *this)
{
  return FindOrAddPanelAnimationMap(className: "CQCGenerator");
}

//------------------------------------------------------------------------------
// Address: 0x004038D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CQCGenerator::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CQCGenerator::GetKBMap(CQCGenerator *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CQCGenerator::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CQCGenerator::GetKBMap'::`2'::s_pMap;
  `CQCGenerator::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CQCGenerator");
  `CQCGenerator::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403900
// Name: public: static void CQCGenerator::AddToMap(char const __near *,void (vgui::Panel::*)(void),int,int,char const __near *,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CQCGenerator::AddToMap(
        const char *scriptname,
        __int64 function,
        __int64 p1type,
        int p2type,
        const char *p2name,
        const char *p1name,
        vgui::DataType_t p2typea,
        const char *p2namea)
{
  vgui::PanelMessageMap *v8; // eax
  int m_Size; // edx
  vgui::MessageMapItem_t src; // [esp+40h] [ebp-40h] BYREF

  v8 = vgui::FindOrAddPanelMessageMap(className: "CQCGenerator");
  src.name = scriptname;
  src.firstParamType = (vgui::DataType_t)p2name;
  src.numParams = p2type;
  src.secondParamType = p2typea;
  src.firstParamName = p1name;
  memset(&src.nameSymbol, 0, 12);
  src.secondParamName = p2namea;
  m_Size = v8->entries.m_Size;
  *(_QWORD *)&src.func = function;
  *((_QWORD *)&src.func + 1) = p1type;
  CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
    this: &v8->entries,
    elem: m_Size,
    &src);
}

//------------------------------------------------------------------------------
// Address: 0x00403980
// Name: public: static void CQCGenerator::PanelMessageFunc_OnNewLODText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CQCGenerator::PanelMessageFunc_OnNewLODText::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`CQCGenerator::PanelMessageFunc_OnNewLODText::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `CQCGenerator::PanelMessageFunc_OnNewLODText::InitVar'::`2'::bAdded = true;
    CQCGenerator::AddToMap(
      scriptname: "TextNewLine",
      function: (unsigned int) __thiscall vgui::TextEntry::`vcall'{944,{flat}},
      p1type: 0,
      p2type: 0,
      p2name: nullptr,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004039E0
// Name: public: static void CQCGenerator::PanelMessageFunc_OnBrowse::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CQCGenerator::PanelMessageFunc_OnBrowse::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`CQCGenerator::PanelMessageFunc_OnBrowse::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `CQCGenerator::PanelMessageFunc_OnBrowse::InitVar'::`2'::bAdded = true;
    CQCGenerator::AddToMap(
      scriptname: "browse",
      function: (unsigned int) __thiscall vgui::TextEntry::`vcall'{948,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)6,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403A40
// Name: public: static void CQCGenerator::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CQCGenerator::PanelMessageFunc_OnFileSelected::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`CQCGenerator::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `CQCGenerator::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    CQCGenerator::AddToMap(
      scriptname: "FileSelected",
      function: (unsigned int) __thiscall vgui::TextEntry::`vcall'{952,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)6,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403AA0
// Name: public: static void CQCGenerator::PanelMessageFunc_OnDirectorySelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CQCGenerator::PanelMessageFunc_OnDirectorySelected::InitVar()
{
  __int64 v0; // [esp+8h] [ebp-8h]

  if ( !`CQCGenerator::PanelMessageFunc_OnDirectorySelected::InitVar'::`2'::bAdded )
  {
    v0 = 0;
    `CQCGenerator::PanelMessageFunc_OnDirectorySelected::InitVar'::`2'::bAdded = true;
    CQCGenerator::AddToMap(
      scriptname: "DirectorySelected",
      function: (unsigned int) __thiscall vgui::TextEntry::`vcall'{956,{flat}},
      p1type: 0,
      p2type: 1,
      p2name: (const char *)6,
      p1name: nullptr,
      p2typea: DATATYPE_VOID,
      p2namea: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403B00
// Name: public: void QCInfo::SyncFromControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall QCInfo::SyncFromControls(QCInfo *this)
{
  int v1; // edi
  vgui::Panel *ChildByName; // eax
  char v4; // al
  CQCGenerator *pQCGenerator; // ecx
  vgui::Panel *v6; // eax
  char v7; // al
  CQCGenerator *v8; // ecx
  vgui::Panel *v9; // eax
  char v10; // al
  CQCGenerator *v11; // ecx
  vgui::Panel *v12; // eax
  char v13; // al
  CQCGenerator *v14; // ecx
  vgui::Panel *v15; // eax
  char v16; // al
  CQCGenerator *v17; // ecx
  vgui::Panel *v18; // eax
  char v19; // al
  CQCGenerator *v20; // ecx
  vgui::Panel *v21; // eax
  vgui::Panel *v22; // eax
  vgui::Panel *v23; // eax
  vgui::Panel *v24; // eax
  vgui::Panel *v25; // eax
  CUtlVector<LODInfo,CUtlMemory<LODInfo,int> > *p_LODs; // ebx
  vgui::Panel *v27; // esi
  KeyValues *v28; // ebp
  const char *String; // eax
  char tempText[260]; // [esp+2Ch] [ebp-210h] BYREF
  LODInfo newLOD; // [esp+130h] [ebp-10Ch] BYREF
  int Int; // [esp+238h] [ebp-4h]

  v1 = 0;
  ChildByName = vgui::Panel::FindChildByName(this: this->pQCGenerator, childName: "staticPropCheck", recurseDown: false);
  v4 = ((int (__thiscall *)(vgui::Panel *))ChildByName->__vftable[1].SetAutoDelete)(a1: ChildByName);
  pQCGenerator = this->pQCGenerator;
  this->bStaticProp = v4;
  v6 = vgui::Panel::FindChildByName(this: pQCGenerator, childName: "mostlyOpaqueCheck", recurseDown: false);
  v7 = ((int (__thiscall *)(vgui::Panel *))v6->__vftable[1].SetAutoDelete)(a1: v6);
  v8 = this->pQCGenerator;
  this->bMostlyOpaque = v7;
  v9 = vgui::Panel::FindChildByName(this: v8, childName: "disableCollisionsCheck", recurseDown: false);
  v10 = ((int (__thiscall *)(vgui::Panel *))v9->__vftable[1].SetAutoDelete)(a1: v9);
  v11 = this->pQCGenerator;
  this->bDisableCollision = v10;
  v12 = vgui::Panel::FindChildByName(this: v11, childName: "referencePhysicsCheck", recurseDown: false);
  v13 = ((int (__thiscall *)(vgui::Panel *))v12->__vftable[1].SetAutoDelete)(a1: v12);
  v14 = this->pQCGenerator;
  this->bReferenceAsPhys = v13;
  v15 = vgui::Panel::FindChildByName(this: v14, childName: "concaveCheck", recurseDown: false);
  v16 = ((int (__thiscall *)(vgui::Panel *))v15->__vftable[1].SetAutoDelete)(a1: v15);
  v17 = this->pQCGenerator;
  this->bConcave = v16;
  v18 = vgui::Panel::FindChildByName(this: v17, childName: "automassCheck", recurseDown: false);
  v19 = ((int (__thiscall *)(vgui::Panel *))v18->__vftable[1].SetAutoDelete)(a1: v18);
  v20 = this->pQCGenerator;
  this->bAutomass = v19;
  v21 = vgui::Panel::FindChildByName(this: v20, childName: "massField", recurseDown: false);
  v21->__vftable[1].PaintTraverse(this: v21, a2: (bool)&tempText[4], a3: 260);
  this->fMass = atof(nptr: &tempText[4]);
  v22 = vgui::Panel::FindChildByName(this: this->pQCGenerator, childName: "scaleField", recurseDown: false);
  v22->__vftable[1].PaintTraverse(this: v22, a2: (bool)&tempText[4], a3: 260);
  this->fScale = atof(nptr: &tempText[4]);
  v23 = vgui::Panel::FindChildByName(this: this->pQCGenerator, childName: "collisionSMDField", recurseDown: false);
  v23->__vftable[1].PaintTraverse(this: v23, a2: (bool)&tempText[4], a3: 260);
  _V_strcpy(dest: this->pszCollisionPath, src: &tempText[4]);
  v24 = vgui::Panel::FindChildByName(this: this->pQCGenerator, childName: "surfacePropertyDropDown", recurseDown: false);
  v24->__vftable[1].PaintTraverse(this: v24, a2: (bool)&tempText[4], a3: 260);
  _V_strcpy(dest: this->pszSurfaceProperty, src: &tempText[4]);
  v25 = vgui::Panel::FindChildByName(this: this->pQCGenerator, childName: "materialsField", recurseDown: false);
  v25->__vftable[1].PaintTraverse(this: v25, a2: (bool)&tempText[4], a3: 260);
  _V_strcpy(dest: this->pszMaterialPath, src: &tempText[4]);
  p_LODs = &this->LODs;
  this->LODs.m_Size = 0;
  v27 = vgui::Panel::FindChildByName(this: this->pQCGenerator, childName: "LODList", recurseDown: false);
  *(_DWORD *)tempText = v27->__vftable[1].GetClassName(this: v27);
  if ( *(int *)tempText > 0 )
  {
    do
    {
      v28 = (KeyValues *)((int (__thiscall *)(vgui::Panel *, int))v27->__vftable[1].GetScheme)(a1: v27, a2: v1);
      String = KeyValues::GetString(this: v28, keyName: "SMD", defaultValue: defaultValue);
      _V_strcpy(dest: &newLOD.pszFilename[4], src: String);
      Int = KeyValues::GetInt(this: v28, keyName: "LOD", defaultValue: 0);
      CUtlVector<LODInfo,CUtlMemory<LODInfo,int>>::InsertBefore(
        this: p_LODs,
        elem: p_LODs->m_Size,
        src: (const LODInfo *)&newLOD.pszFilename[4]);
      ++v1;
    }
    while ( v1 < *(int *)tempText );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403D80
// Name: public: CQCGenerator::CQCGenerator(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CQCGenerator *__thiscall CQCGenerator::CQCGenerator(
        CQCGenerator *this,
        vgui::Panel *pParent,
        char *pszPath,
        char *pszScene)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::ListPanel *v8; // eax
  vgui::ListPanel *v9; // eax
  CBrowseButton *v10; // eax
  CBrowseButton *v11; // eax
  const char *v12; // edi
  int v13; // eax
  void *v14; // ebp
  char *v15; // eax
  int v16; // ebx
  char *v17; // edi
  vgui::Panel *ChildByName; // ebx
  char v20[1024]; // [esp+40h] [ebp-1400h] BYREF
  char string[1024]; // [esp+440h] [ebp-1000h] BYREF
  char pReturn[1024]; // [esp+840h] [ebp-C00h] BYREF
  char key[1024]; // [esp+C40h] [ebp-800h] BYREF
  char value[1024]; // [esp+1040h] [ebp-400h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: "QCGenerator");
  this->__vftable = (CQCGenerator_vtbl *)&CQCGenerator::`vftable';
  if ( `CQCGenerator::ChainToMap'::`2'::chained == 0 )
  {
    `CQCGenerator::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CQCGenerator");
    v5->pfnClassName = CQCGenerator::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CQCGenerator::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CQCGenerator::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CQCGenerator");
    v6->pfnClassName = CQCGenerator::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CQCGenerator::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CQCGenerator::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CQCGenerator");
    v7->pfnClassName = CQCGenerator::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CQCGenerator::PanelMessageFunc_OnNewLODText::InitVar();
  CQCGenerator::PanelMessageFunc_OnBrowse::InitVar();
  CQCGenerator::PanelMessageFunc_OnFileSelected::InitVar();
  CQCGenerator::PanelMessageFunc_OnDirectorySelected::InitVar();
  this->m_QCInfo_t.LODs.m_Memory.m_pMemory = nullptr;
  this->m_QCInfo_t.LODs.m_Memory.m_nAllocationCount = 0;
  this->m_QCInfo_t.LODs.m_Memory.m_nGrowSize = 0;
  this->m_QCInfo_t.LODs.m_Size = 0;
  this->m_QCInfo_t.LODs.m_pElements = nullptr;
  QCInfo::Init(this: &this->m_QCInfo_t, pPanel: this);
  vgui::Panel::SetMinimumSize(this, wide: 846, tall: 770);
  v8 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v8 != nullptr )
    v9 = vgui::ListPanel::ListPanel(this: v8, parent: this, panelName: "LODList");
  else
    v9 = nullptr;
  this->m_pLODPanel = v9;
  v9->SetSelectIndividualCells(this: v9, a2: true);
  this->m_pLODPanel->AddColumnHeader(this: this->m_pLODPanel, a2: 0, a3: "SMD", a4: "LOD SMD", a5: 450, a6: 0);
  this->m_pLODPanel->AddColumnHeader(this: this->m_pLODPanel, a2: 1, a3: "LOD", a4: "LOD Distance", a5: 50, a6: 0);
  this->m_pLODPanel->AddActionSignalTarget_2(this: this->m_pLODPanel, a2: this);
  this->m_pLODPanel->SetMouseInputEnabled(this: this->m_pLODPanel, a2: true);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "QCGenerator.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  v10 = (CBrowseButton *)operator new(nSize: 0x204u);
  if ( v10 != nullptr )
    v11 = CBrowseButton::CBrowseButton(this: v10, pParent: this);
  else
    v11 = nullptr;
  this->m_pCollisionBrowseButton = v11;
  CBrowseButton::InitBrowseInfo(
    this: v11,
    x: 808,
    y: 158,
    pszName: "collisionBrowseButton",
    pszDir: pszPath,
    pszFilter: "*.smd",
    pszField: "collisionSMDField");
  memset(string, 0, sizeof(string));
  sprintf(string, format: "%s\\", pszPath);
  CQCGenerator::InitializeSMDPaths(this, pszPath: string, pszScene);
  v12 = strrchrcount(string, character: 92, count: 3) + 1;
  strrchr((unsigned __int8 *)string, chr: 0x5Cu);
  V_strncpy(pDest: this->m_QCInfo_t.pszMaterialPath, pSrc: v12, maxLen: v13 - (_DWORD)v12 + 1);
  vgui::Panel::SetParent(this, newParent: pParent);
  memset(pReturn, 0, sizeof(pReturn));
  memset(v20, 0, sizeof(v20));
  GetVConfigRegistrySetting(pName: "VProject", pReturn, size: 1024);
  sprintf(string: v20, format: "%s%s", pReturn, pSurfacePropFilename);
  v14 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: v20, a3: "rb", a4: 0);
  if ( v14 == nullptr )
  {
    v15 = _V_strrchr(s: pReturn, c: 92);
    _V_strcpy(dest: v15, src: "\\hl2");
    sprintf(string: v20, format: "%s%s", pReturn, pSurfacePropFilename);
    v14 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: v20, a3: "rb", a4: 0);
  }
  v16 = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v14);
  v17 = (char *)operator new(nSize: v16 + 1);
  g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: v17, a3: v16, a4: v14);
  ChildByName = vgui::Panel::FindChildByName(this, childName: "surfacePropertyDropDown", recurseDown: false);
  while ( v17 != nullptr )
  {
    v17 = (char *)ParseKeyvalue(pBuffer: v17, key, value);
    ((void (__thiscall *)(vgui::Panel *, char *, _DWORD))ChildByName->__vftable[1].MarkForDeletion)(
      a1: ChildByName,
      a2: key,
      a3: 0);
    if ( v17 == nullptr )
      break;
    while ( 1 )
    {
      v17 = (char *)ParseKeyvalue(pBuffer: v17, key, value);
      if ( _V_stricmp(s1: key, s2: "}") == 0 )
        break;
      if ( v17 == nullptr )
        goto LABEL_21;
    }
  }
LABEL_21:
  QCInfo::SyncToControls(this: &this->m_QCInfo_t);
  this->m_pLODEdit = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00404220
// Name: public: virtual void CQCGenerator::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQCGenerator::OnCommand(CQCGenerator *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "createQC") == 0 )
  {
    QCInfo::SyncFromControls(this: &this->m_QCInfo_t);
    CQCGenerator::GenerateQCFile(this);
  }
  if ( _V_stricmp(s1: command, s2: "deleteSeq") == 0 )
    CQCGenerator::DeleteLOD(this);
  if ( _V_stricmp(s1: command, s2: "editSeq") == 0 )
    CQCGenerator::EditLOD(this);
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x00413870
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Button::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Button::GetMessageMap(vgui::Button *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Button::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Button::GetMessageMap'::`2'::s_pMap;
  `vgui::Button::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Button");
  `vgui::Button::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004138B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Button::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Button::GetKBMap(vgui::Button *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Button::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Button::GetKBMap'::`2'::s_pMap;
  `vgui::Button::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  `vgui::Button::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A800
// Name: protected: virtual class vgui::IBorder __near * vgui::Button::GetBorder(bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall vgui::Button::GetBorder(
        vgui::Button *this,
        bool depressed,
        bool armed,
        bool selected,
        bool keyfocus)
{
  if ( (this->_buttonFlags.m_nFlags & 8) != 0 )
  {
    if ( depressed )
      return this->_depressedBorder;
    if ( keyfocus || this->IsEnabled(this) && (this->_buttonFlags.m_nFlags & 0x40) != 0 )
      return this->_keyFocusBorder;
  }
  else if ( depressed )
  {
    return this->_depressedBorder;
  }
  return this->_defaultBorder;
}

//------------------------------------------------------------------------------
// Address: 0x0042C0D0
// Name: public: virtual class vgui::Panel __near * vgui::Label::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Label *__thiscall vgui::Label::HasHotkey(vgui::Label *this, wchar_t key)
{
  wchar_t v2; // si

  v2 = key;
  if ( iswalnum(c: key) != 0 )
    v2 = towlower(c: key);
  return this->_hotkey != v2 ? nullptr : this;
}

//------------------------------------------------------------------------------
// Address: 0x0042D6B0
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
// Address: 0x0042DBE0
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
// Address: 0x0042DC10
// Name: public: virtual struct PanelAnimationMap __near * vgui::Label::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Label::GetAnimMap(vgui::Label *this)
{
  return FindOrAddPanelAnimationMap(className: "Label");
}

//------------------------------------------------------------------------------
// Address: 0x0042DC20
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
