// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/dmecombinationsystemeditorpanel.cpp
// Functions: 133
// ============================================================

#include "vgui2\dme_controls\dmecombinationsystemeditorpanel.h"

//------------------------------------------------------------------------------
// Address: 0x0046CC50
// Name: public: static char const __near * CDmeCombinationSystemEditorPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeCombinationSystemEditorPanel::GetPanelClassName()
{
  return "CDmeCombinationSystemEditorPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0046CC60
// Name: public: static char const __near * CDmeCombinationSystemEditorFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeCombinationSystemEditorFrame::GetPanelClassName()
{
  return "CDmeCombinationSystemEditorFrame";
}

//------------------------------------------------------------------------------
// Address: 0x0046CC70
// Name: ImportDominationRules
// Source: json
//------------------------------------------------------------------------------
void __cdecl ImportDominationRules(
        CDmeCombinationOperator *pDestComboOp,
        CDmeCombinationOperator *pSrcComboOp,
        COperationFileListFrame *pStatusFrame)
{
  int v3; // eax
  int v4; // ecx
  CDmeTransform *DominationRule; // edi
  int v6; // esi
  const char *Dominator; // ebx
  int v8; // esi
  const char *Suppressed; // ebx
  int nRuleCount; // [esp+0h] [ebp-10h]
  CDmAttribute *nDominatorCount; // [esp+4h] [ebp-Ch]
  int nDominatorCounta; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  bool bMismatch; // [esp+Fh] [ebp-1h]

  CDmeCombinationOperator::RemoveAllDominationRules(this: pDestComboOp);
  v3 = CDmeCombinationOperator::DominationRuleCount(this: pSrcComboOp);
  v4 = 0;
  nRuleCount = v3;
  for ( i = 0; v4 < nRuleCount; i = v4 )
  {
    bMismatch = false;
    DominationRule = (CDmeTransform *)CDmeCombinationOperator::GetDominationRule(this: pSrcComboOp, i: v4);
    v6 = 0;
    nDominatorCount = CDmeTrack::GetClipCount(this: DominationRule);
    if ( (int)nDominatorCount > 0 )
    {
      while ( 1 )
      {
        Dominator = CDmeCombinationDominationRule::GetDominator(
                      this: (CDmeCombinationDominationRule *)DominationRule,
                      i: v6);
        if ( !CDmeCombinationOperator::HasRawControl(this: pDestComboOp, pRawControlName: Dominator) )
          break;
        if ( ++v6 >= (int)nDominatorCount )
          goto LABEL_7;
      }
      bMismatch = true;
      COperationFileListFrame::AddOperation(
        this: pStatusFrame,
        pOperation: Dominator,
        pFileName: "Missing raw control for dominance rule");
    }
LABEL_7:
    v8 = 0;
    nDominatorCounta = CDmeCombinationDominationRule::SuppressedCount(this: (CDmeCombinationDominationRule *)DominationRule);
    if ( nDominatorCounta <= 0 )
    {
LABEL_10:
      if ( !bMismatch )
        CDmeCombinationOperator::AddDominationRule(
          this: pDestComboOp,
          pSrcRule: (CDmeCombinationDominationRule *)DominationRule);
    }
    else
    {
      while ( 1 )
      {
        Suppressed = CDmeCombinationDominationRule::GetSuppressed(
                       this: (CDmeCombinationDominationRule *)DominationRule,
                       i: v8);
        if ( !CDmeCombinationOperator::HasRawControl(this: pDestComboOp, pRawControlName: Suppressed) )
          break;
        if ( ++v8 >= nDominatorCounta )
          goto LABEL_10;
      }
      COperationFileListFrame::AddOperation(
        this: pStatusFrame,
        pOperation: Suppressed,
        pFileName: "Missing raw control for dominance rule");
    }
    v4 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046CD60
// Name: public: static char const __near * CDmeInputControlListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeInputControlListPanel::GetPanelClassName()
{
  return "CDmeInputControlListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0046CD70
// Name: public: static char const __near * CDmeRawControlListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeRawControlListPanel::GetPanelClassName()
{
  return "CDmeRawControlListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0046CD80
// Name: public: static char const __near * CDmeCombinationControlsPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeCombinationControlsPanel::GetPanelClassName()
{
  return "CDmeCombinationControlsPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0046CD90
// Name: public: void CDmeCombinationControlsPanel::NotifyDataChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationControlsPanel::NotifyDataChanged(CDmeCombinationControlsPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(
           this: v2,
           setName: "DmeElementChanged",
           firstKey: "DmeCombinationControlsPanel",
           firstValue: 1);
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046CDE0
// Name: private: virtual void CDmeCombinationControlsPanel::OnGroupControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationControlsPanel::OnGroupControls(CDmeCombinationControlsPanel *this)
{
  vgui::InputDialog *v2; // eax
  vgui::InputDialog *v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v2 = (vgui::InputDialog *)MemAlloc_Alloc(nSize: 0x22Cu);
  if ( v2 != nullptr )
    v3 = vgui::InputDialog::InputDialog(
           this: v2,
           parent: this,
           title: "Group Controls",
           prompt: "Enter name of grouped control",
           defaultValue: defaultValue);
  else
    v3 = nullptr;
  vgui::InputDialog::SetMultiline(this: v3, state: false);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "OnGroupControls");
    vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: v5);
  }
  else
  {
    vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046CE50
// Name: private: virtual void CDmeCombinationControlsPanel::OnRenameControl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationControlsPanel::OnRenameControl(CDmeCombinationControlsPanel *this)
{
  vgui::InputDialog *v2; // eax
  vgui::InputDialog *v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  if ( this->m_pControlList->GetSelectedItemsCount(this: this->m_pControlList) == 1 )
  {
    v2 = (vgui::InputDialog *)MemAlloc_Alloc(nSize: 0x22Cu);
    if ( v2 != nullptr )
      v3 = vgui::InputDialog::InputDialog(
             this: v2,
             parent: this,
             title: "Rename Control",
             prompt: "Enter new name of control",
             defaultValue: defaultValue);
    else
      v3 = nullptr;
    vgui::InputDialog::SetMultiline(this: v3, state: false);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "OnRenameControl");
      vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: v5);
    }
    else
    {
      vgui::BaseInputDialog::DoModal(this: v3, pContextKeyValues: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046CED0
// Name: private: virtual void CDmeCombinationControlsPanel::OnImportCombination(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationControlsPanel::OnImportCombination(CDmeCombinationControlsPanel *this)
{
  vgui::FileOpenDialog *v2; // esi
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  vgui::FileOpenDialog *v5; // esi
  char pStartingDir[260]; // [esp+8h] [ebp-104h] BYREF

  GetModContentSubdirectory(pSubDir: "models", pBuf: pStartingDir, nBufLen: 260);
  v2 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
  if ( v2 != nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "ImportControls");
    else
      v4 = nullptr;
    v5 = vgui::FileOpenDialog::FileOpenDialog(
           this: v2,
           parent: this,
           title: "Select File to Import",
           bOpenOnly: true,
           pContextKeyValues: v4);
  }
  else
  {
    v5 = nullptr;
  }
  vgui::FileOpenDialog::SetStartDirectoryContext(
    this: v5,
    pStartDirContext: "combination_system_import",
    pDefaultDir: pStartingDir);
  vgui::FileOpenDialog::AddFilter(
    this: v5,
    filter: "*.dmx",
    filterName: "Exported model file (*.dmx)",
    bActive: true,
    pFilterInfo: nullptr);
  v5->AddActionSignalTarget_2(this: v5, a2: this);
  vgui::FileOpenDialog::DoModal(this: v5, bUnused: false);
}

//------------------------------------------------------------------------------
// Address: 0x0046CF80
// Name: public: virtual void CDmeInputControlListPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeInputControlListPanel::OnKeyCodeTyped(CDmeInputControlListPanel *this, ButtonCode_t code)
{
  int v3; // edi

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
  {
    if ( code == KEY_UP )
    {
      v3 = this->m_pComboPanel->m_pControlList->GetSelectedItem(this: this->m_pComboPanel->m_pControlList, a2: 0);
      this->m_pComboPanel->OnMoveUpInputControl(this: this->m_pComboPanel);
      vgui::ListPanel::OnKeyCodeTyped(this, code: KEY_UP);
LABEL_5:
      this->m_pComboPanel->m_pControlList->SetSingleSelectedItem(this: this->m_pComboPanel->m_pControlList, a2: v3);
      return;
    }
    if ( code == KEY_DOWN )
    {
      v3 = this->m_pComboPanel->m_pControlList->GetSelectedItem(this: this->m_pComboPanel->m_pControlList, a2: 0);
      this->m_pComboPanel->OnMoveDownInputControl(this: this->m_pComboPanel);
      vgui::ListPanel::OnKeyCodeTyped(this, code: KEY_DOWN);
      goto LABEL_5;
    }
  }
  vgui::ListPanel::OnKeyCodeTyped(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x0046D050
// Name: public: virtual void CDmeRawControlListPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRawControlListPanel::OnKeyCodeTyped(CDmeRawControlListPanel *this, ButtonCode_t code)
{
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
  {
    if ( code == KEY_UP )
    {
      this->m_pComboPanel->OnMoveUp(this: this->m_pComboPanel);
      vgui::ListPanel::OnKeyCodeTyped(this, code: KEY_UP);
      return;
    }
    if ( code == KEY_DOWN )
      this->m_pComboPanel->OnMoveDown(this: this->m_pComboPanel);
  }
  vgui::ListPanel::OnKeyCodeTyped(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x0046D0D0
// Name: public: virtual void CDmeRawControlListPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeRawControlListPanel::OnMouseDoublePressed(CDmeRawControlListPanel *this, ButtonCode_t code)
{
  int v3; // edi
  int v4; // edi
  KeyValues *v5; // ebx
  const char *String; // eax
  char buf[64]; // [esp+24h] [ebp-40h] BYREF
  float flWrinkleValue; // [esp+6Ch] [ebp+8h]

  if ( code == KEY_COUNT )
  {
    v3 = this->GetSelectedItemsCount(this);
    if ( !this->IsInEditMode(this) && v3 == 1 )
    {
      this->m_pWrinkleEdit->SetVisible(this: this->m_pWrinkleEdit, a2: true);
      this->m_pWrinkleEdit->SendNewLine(this: this->m_pWrinkleEdit, a2: true);
      v4 = this->GetSelectedItem(this, a2: 0);
      v5 = this->GetItem(this, a2: v4);
      flWrinkleValue = KeyValues::GetFloat(this: v5, keyName: "wrinkle", defaultValue: 0.0);
      String = KeyValues::GetString(this: v5, keyName: "wrinkletype", defaultValue: defaultValue);
      this->m_bIsWrinkle = _V_stricmp(s1: String, s2: "Wrinkle") == 0;
      V_snprintf(pDest: buf, maxLen: 64, pFormat: "%f", flWrinkleValue);
      this->m_pWrinkleEdit->SetText(this: this->m_pWrinkleEdit, a2: buf);
      this->EnterEditMode(this, a2: v4, a3: 2, a4: this->m_pWrinkleEdit);
    }
  }
  else
  {
    vgui::ListPanel::OnMouseDoublePressed(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D1F0
// Name: public: static char const __near * CRawControlPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CRawControlPickerFrame::GetPanelClassName()
{
  return "CRawControlPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x0046D200
// Name: private: void CRawControlPickerFrame::RefreshRawControlNames(class CDmeCombinationOperator __near *,class CDmeCombinationDominationRule __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRawControlPickerFrame::RefreshRawControlNames(
        CRawControlPickerFrame *this,
        CDmeCombinationOperator *pCombinationOperator,
        CDmeCombinationDominationRule *pRule,
        bool bChooseSuppressed)
{
  CRawControlPickerFrame *v4; // esi
  int v6; // edi
  const char *RawControlName; // esi
  bool HasSuppressedControl; // al
  bool v9; // zf
  KeyValues *v10; // esi
  const char *v11; // eax
  const KeyValues *v12; // eax
  int v13; // eax
  int nCount; // [esp+8h] [ebp-Ch]
  bool bIsSuppressed; // [esp+13h] [ebp-1h]
  bool bIsDominator_3; // [esp+1Fh] [ebp+Bh]

  v4 = this;
  this->m_pRawControlList->RemoveAll(this: this->m_pRawControlList);
  if ( pCombinationOperator == nullptr )
    return;
  v6 = 0;
  nCount = CDmeCombinationOperator::GetRawControlCount(this: pCombinationOperator);
  if ( nCount <= 0 )
    goto LABEL_17;
  do
  {
    RawControlName = CDmeCombinationOperator::GetRawControlName(this: pCombinationOperator, nIndex: v6);
    bIsDominator_3 = CDmeCombinationDominationRule::HasDominatorControl(this: pRule, pDominatorControl: RawControlName);
    HasSuppressedControl = CDmeCombinationDominationRule::HasSuppressedControl(
                             this: pRule,
                             pSuppressedControl: RawControlName);
    bIsSuppressed = HasSuppressedControl;
    if ( bChooseSuppressed )
      v9 = !bIsDominator_3;
    else
      v9 = !HasSuppressedControl;
    if ( v9 )
    {
      v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v10 != nullptr )
      {
        v11 = CDmeCombinationOperator::GetRawControlName(this: pCombinationOperator, nIndex: v6);
        v12 = KeyValues::KeyValues(this: v10, setName: "node", firstKey: "name", firstValue: v11);
      }
      else
      {
        v12 = nullptr;
      }
      v13 = this->m_pRawControlList->AddItem(this: this->m_pRawControlList, a2: v12, a3: 0, a4: false, a5: false);
      if ( !bChooseSuppressed )
      {
        if ( !bIsDominator_3 )
          goto LABEL_15;
LABEL_14:
        this->m_pRawControlList->AddSelectedItem(this: this->m_pRawControlList, a2: v13);
        goto LABEL_15;
      }
      if ( bIsSuppressed )
        goto LABEL_14;
    }
LABEL_15:
    ++v6;
  }
  while ( v6 < nCount );
  v4 = this;
LABEL_17:
  v4->m_pRawControlList->SortList(this: v4->m_pRawControlList);
}

//------------------------------------------------------------------------------
// Address: 0x0046D310
// Name: public: virtual void CRawControlPickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRawControlPickerFrame::OnCommand(CRawControlPickerFrame *this, KeyValues *pCommand)
{
  KeyValues *v3; // eax
  int v4; // esi
  int v5; // ebx
  int v6; // eax
  KeyValues *v7; // eax
  const char *String; // eax
  KeyValues *pControlList; // [esp+8h] [ebp-4h]
  KeyValues *pActionKeys; // [esp+14h] [ebp+8h]

  if ( _V_stricmp(s1: (const char *)pCommand, s2: "Ok") != 0 )
  {
    if ( _V_stricmp(s1: (const char *)pCommand, s2: "Cancel") != 0 )
      vgui::Frame::OnCommand(this, command: (const char *)pCommand);
    else
      this->CloseModal(this);
  }
  else
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v4 = 0;
    if ( v3 != nullptr )
      pActionKeys = KeyValues::KeyValues(this: v3, setName: "RawControlPicked");
    else
      pActionKeys = nullptr;
    pControlList = KeyValues::FindKey(this: pActionKeys, keyName: "rawControls", bCreate: true);
    v5 = this->m_pRawControlList->GetSelectedItemsCount(this: this->m_pRawControlList);
    if ( v5 > 0 )
    {
      do
      {
        v6 = this->m_pRawControlList->GetSelectedItem(this: this->m_pRawControlList, a2: v4);
        v7 = this->m_pRawControlList->GetItem(this: this->m_pRawControlList, a2: v6);
        String = KeyValues::GetString(this: v7, keyName: "name", defaultValue: defaultValue);
        KeyValues::SetString(this: pControlList, keyName: String, value: String);
        ++v4;
      }
      while ( v4 < v5 );
    }
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: pActionKeys, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    this->PostActionSignal(this, a2: pActionKeys);
    this->CloseModal(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D440
// Name: public: static char const __near * CDmeCombinationDominationRulesPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeCombinationDominationRulesPanel::GetPanelClassName()
{
  return "CDmeCombinationDominationRulesPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0046D450
// Name: ControlNameSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl ControlNameSortFunc(const char **elem1, const char **elem2)
{
  return _V_stricmp(s1: *elem1, s2: *elem2);
}

//------------------------------------------------------------------------------
// Address: 0x0046D470
// Name: private: virtual void CDmeCombinationDominationRulesPanel::OnImportDominationRules(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationDominationRulesPanel::OnImportDominationRules(CDmeCombinationDominationRulesPanel *this)
{
  vgui::FileOpenDialog *v2; // esi
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  vgui::FileOpenDialog *v5; // esi
  char pStartingDir[260]; // [esp+8h] [ebp-104h] BYREF

  GetModContentSubdirectory(pSubDir: "models", pBuf: pStartingDir, nBufLen: 260);
  v2 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
  if ( v2 != nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "ImportDominationRules");
    else
      v4 = nullptr;
    v5 = vgui::FileOpenDialog::FileOpenDialog(
           this: v2,
           parent: this,
           title: "Select File to Import",
           bOpenOnly: true,
           pContextKeyValues: v4);
  }
  else
  {
    v5 = nullptr;
  }
  vgui::FileOpenDialog::SetStartDirectoryContext(
    this: v5,
    pStartDirContext: "combination_system_import",
    pDefaultDir: pStartingDir);
  vgui::FileOpenDialog::AddFilter(
    this: v5,
    filter: "*.dmx",
    filterName: "Exported model file (*.dmx)",
    bActive: true,
    pFilterInfo: nullptr);
  v5->AddActionSignalTarget_2(this: v5, a2: this);
  vgui::FileOpenDialog::DoModal(this: v5, bUnused: false);
}

//------------------------------------------------------------------------------
// Address: 0x0046D520
// Name: private: virtual void CDmeCombinationSystemEditorPanel::OnPageChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationSystemEditorPanel::OnPageChanged(CDmeCombinationSystemEditorPanel *this)
{
  if ( this->m_pEditorSheet->GetActivePage(this: this->m_pEditorSheet) != this->m_pControlsPage )
    this->m_pEditorSheet->GetActivePage(this: this->m_pEditorSheet);
}

//------------------------------------------------------------------------------
// Address: 0x0046D550
// Name: public: virtual void CDmeCombinationSystemEditorFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationSystemEditorFrame::OnCommand(
        CDmeCombinationSystemEditorFrame *this,
        const char *pCommand)
{
  if ( _V_stricmp(s1: pCommand, s2: "Open") != 0 && _V_stricmp(s1: pCommand, s2: "Cancel") != 0 )
    vgui::Frame::OnCommand(this, command: pCommand);
}

//------------------------------------------------------------------------------
// Address: 0x0046D590
// Name: private: virtual void CDmeCombinationSystemEditorFrame::OnDmeElementChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationSystemEditorFrame::OnDmeElementChanged(CDmeCombinationSystemEditorFrame *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "CombinationOperatorChanged");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D670
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeCombinationSystemEditorPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeCombinationSystemEditorPanel::GetMessageMap(
        CDmeCombinationSystemEditorPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeCombinationSystemEditorPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeCombinationSystemEditorPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeCombinationSystemEditorPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationSystemEditorPanel");
  `CDmeCombinationSystemEditorPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046D6A0
// Name: public: virtual struct PanelAnimationMap __near * CDmeCombinationSystemEditorPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeCombinationSystemEditorPanel::GetAnimMap(CDmeCombinationSystemEditorPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeCombinationSystemEditorPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0046D6B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeCombinationSystemEditorPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeCombinationSystemEditorPanel::GetKBMap(CDmeCombinationSystemEditorPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeCombinationSystemEditorPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeCombinationSystemEditorPanel::GetKBMap'::`2'::s_pMap;
  `CDmeCombinationSystemEditorPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeCombinationSystemEditorPanel");
  `CDmeCombinationSystemEditorPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046D6E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeCombinationSystemEditorFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeCombinationSystemEditorFrame::GetMessageMap(
        CDmeCombinationSystemEditorFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeCombinationSystemEditorFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeCombinationSystemEditorFrame::GetMessageMap'::`2'::s_pMap;
  `CDmeCombinationSystemEditorFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationSystemEditorFrame");
  `CDmeCombinationSystemEditorFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046D710
// Name: public: virtual struct PanelAnimationMap __near * CDmeCombinationSystemEditorFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeCombinationSystemEditorFrame::GetAnimMap(CDmeCombinationSystemEditorFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeCombinationSystemEditorFrame");
}

//------------------------------------------------------------------------------
// Address: 0x0046D720
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeCombinationSystemEditorFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeCombinationSystemEditorFrame::GetKBMap(CDmeCombinationSystemEditorFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeCombinationSystemEditorFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeCombinationSystemEditorFrame::GetKBMap'::`2'::s_pMap;
  `CDmeCombinationSystemEditorFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeCombinationSystemEditorFrame");
  `CDmeCombinationSystemEditorFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046D750
// Name: private: void CDmeCombinationControlsPanel::RefreshRawControlNames(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeCombinationControlsPanel::RefreshRawControlNames(
        CDmeCombinationControlsPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>)
{
  int v4; // eax
  int v5; // eax
  KeyValues *v6; // eax
  const char *String; // esi
  int v8; // eax
  CDmeCombinationOperator *v9; // eax
  int ControlIndex; // esi
  int v11; // eax
  CDmeCombinationOperator *v12; // ecx
  int v13; // ebx
  KeyValues *v14; // esi
  int v15; // eax
  CDmeCombinationOperator *v16; // ecx
  const char *RawControlName; // eax
  KeyValues *v18; // esi
  int v19; // eax
  CDmeCombinationOperator *v20; // ecx
  double RawControlWrinkleScale; // st7
  const char *v22; // eax
  int nCount; // [esp+28h] [ebp-Ch]
  float flWrinkleScale; // [esp+2Ch] [ebp-8h]
  int nControlIndex; // [esp+30h] [ebp-4h]

  this->m_pRawControlList->RemoveAll(this: this->m_pRawControlList);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  if ( v4 != 0 && v4 != 4 && this->m_pControlList->GetSelectedItemsCount(this: this->m_pControlList) == 1 )
  {
    v5 = this->m_pControlList->GetSelectedItem(this: this->m_pControlList, a2: 0);
    v6 = this->m_pControlList->GetItem(this: this->m_pControlList, a2: v5);
    String = KeyValues::GetString(this: v6, keyName: "name", defaultValue: defaultValue);
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hCombinationOperator.m_handle);
    v9 = v8 != 0 ? (CDmeCombinationOperator *)(v8 - 4) : nullptr;
    ControlIndex = CDmeCombinationOperator::FindControlIndex(this: v9, pControlName: String);
    nControlIndex = ControlIndex;
    if ( ControlIndex >= 0 )
    {
      v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_hCombinationOperator.m_handle);
      if ( v11 != 0 )
        v12 = (CDmeCombinationOperator *)(v11 - 4);
      else
        v12 = nullptr;
      v13 = 0;
      nCount = CDmeCombinationOperator::GetRawControlCount(this: v12, nControl: ControlIndex);
      if ( nCount > 0 )
      {
        do
        {
          v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v14 != nullptr )
          {
            v15 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: this->m_hCombinationOperator.m_handle);
            if ( v15 != 0 )
              v16 = (CDmeCombinationOperator *)(v15 - 4);
            else
              v16 = nullptr;
            RawControlName = CDmeCombinationOperator::GetRawControlName(this: v16, nControl: nControlIndex, nIndex: v13);
            v18 = KeyValues::KeyValues(this: v14, setName: "node", firstKey: "name", firstValue: RawControlName);
          }
          else
          {
            v18 = nullptr;
          }
          v19 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, int, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                  a1: g_pDataModel.u,
                  a2: this->m_hCombinationOperator.m_handle,
                  a3: a2,
                  a4: a3);
          if ( v19 != 0 )
            v20 = (CDmeCombinationOperator *)(v19 - 4);
          else
            v20 = nullptr;
          RawControlWrinkleScale = CDmeCombinationOperator::GetRawControlWrinkleScale(
                                     this: v20,
                                     nControl: nControlIndex,
                                     nIndex: v13);
          v22 = "- Compress";
          if ( RawControlWrinkleScale >= 0.0 )
            v22 = "+ Stretch";
          KeyValues::SetString(this: v18, keyName: "wrinkletype", value: v22);
          flWrinkleScale = RawControlWrinkleScale;
          KeyValues::SetFloat(
            this: v18,
            keyName: "wrinkle",
            value: COERCE_FLOAT(LODWORD(flWrinkleScale) & _mask__AbsFloat_));
          a3 = 0;
          a2 = 0;
          ((void (__thiscall *)(CDmeRawControlListPanel *, KeyValues *, _DWORD))this->m_pRawControlList->AddItem)(
            a1: this->m_pRawControlList,
            a2: v18,
            a3: 0);
          ++v13;
        }
        while ( v13 < nCount );
      }
      this->m_pRawControlList->SortList(this: this->m_pRawControlList);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D940
// Name: private: char const __near * CDmeCombinationControlsPanel::GetSelectedRawControl(int __near &)
// Source: json
//------------------------------------------------------------------------------
const char *__userpurge CDmeCombinationControlsPanel::GetSelectedRawControl@<eax>(
        CDmeCombinationControlsPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int *nControlIndex)
{
  int v5; // eax
  int v7; // eax
  KeyValues *v8; // eax
  const char *String; // edi
  int v10; // eax
  CDmeCombinationOperator *v11; // ecx
  int v12; // eax
  KeyValues *v13; // eax

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  if ( v5 == 0 || v5 == 4 )
    return nullptr;
  *nControlIndex = -1;
  if ( this->m_pControlList->GetSelectedItemsCount(this: this->m_pControlList) != 1
    || this->m_pRawControlList->GetSelectedItemsCount(this: this->m_pRawControlList) != 1 )
  {
    return nullptr;
  }
  v7 = ((int (__thiscall *)(CDmeInputControlListPanel *, _DWORD, int, int))this->m_pControlList->GetSelectedItem)(
         a1: this->m_pControlList,
         a2: 0,
         a3,
         a4: a2);
  v8 = this->m_pControlList->GetItem(this: this->m_pControlList, a2: v7);
  String = KeyValues::GetString(this: v8, keyName: "name", defaultValue: defaultValue);
  v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
          a1: g_pDataModel.u,
          a2: this->m_hCombinationOperator.m_handle);
  if ( v10 != 0 )
    v11 = (CDmeCombinationOperator *)(v10 - 4);
  else
    v11 = nullptr;
  *nControlIndex = CDmeCombinationOperator::FindControlIndex(this: v11, pControlName: String);
  v12 = this->m_pRawControlList->GetSelectedItem(this: this->m_pRawControlList, a2: 0);
  v13 = this->m_pRawControlList->GetItem(this: this->m_pRawControlList, a2: v12);
  return KeyValues::GetString(this: v13, keyName: "name", defaultValue: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x0046DA40
// Name: public: char const __near * CDmeCombinationControlsPanel::GetSelectedControlName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeCombinationControlsPanel::GetSelectedControlName(CDmeCombinationControlsPanel *this)
{
  int v2; // eax
  int v4; // edi
  KeyValues *v5; // eax

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  if ( v2 == 0 || v2 == 4 || this->m_pControlList->GetSelectedItemsCount(this: this->m_pControlList) != 1 )
    return nullptr;
  v4 = this->m_pControlList->GetSelectedItem(this: this->m_pControlList, a2: 0);
  if ( this->m_pControlList->IsValidItemID(this: this->m_pControlList, a2: v4)
    && (v5 = this->m_pControlList->GetItem(this: this->m_pControlList, a2: v4)) != nullptr )
  {
    return KeyValues::GetString(this: v5, keyName: "name", defaultValue: defaultValue);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046DAE0
// Name: public: virtual void CDmeCombinationControlsPanel::OnMoveUp(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeCombinationControlsPanel::OnMoveUp(
        CDmeCombinationControlsPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>)
{
  const char *SelectedRawControl; // edi
  int v5; // eax
  CDmeCombinationOperator *v6; // ecx
  int nControlIndex; // [esp+8h] [ebp-4h] BYREF

  SelectedRawControl = CDmeCombinationControlsPanel::GetSelectedRawControl(this, a2, a3, &nControlIndex);
  if ( SelectedRawControl != nullptr )
  {
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hCombinationOperator.m_handle);
    if ( v5 != 0 )
      v6 = (CDmeCombinationOperator *)(v5 - 4);
    else
      v6 = nullptr;
    CDmeCombinationOperator::MoveRawControlUp(this: v6, nControlIndex, pRawControlName: SelectedRawControl);
    CDmeCombinationControlsPanel::RefreshRawControlNames(this, a2, a3: (int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046DB30
// Name: public: virtual void CDmeCombinationControlsPanel::OnMoveDown(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeCombinationControlsPanel::OnMoveDown(
        CDmeCombinationControlsPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>)
{
  const char *SelectedRawControl; // edi
  int v5; // eax
  CDmeCombinationOperator *v6; // ecx
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  int nControlIndex; // [esp+8h] [ebp-4h] BYREF

  SelectedRawControl = CDmeCombinationControlsPanel::GetSelectedRawControl(this, a2, a3, &nControlIndex);
  if ( SelectedRawControl != nullptr )
  {
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hCombinationOperator.m_handle);
    if ( v5 != 0 )
      v6 = (CDmeCombinationOperator *)(v5 - 4);
    else
      v6 = nullptr;
    CDmeCombinationOperator::MoveRawControlDown(this: v6, nControlIndex, pRawControlName: SelectedRawControl);
    CDmeCombinationControlsPanel::RefreshRawControlNames(this, a2, a3: (int)this);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
    {
      v8 = KeyValues::KeyValues(
             this: v7,
             setName: "DmeElementChanged",
             firstKey: "DmeCombinationControlsPanel",
             firstValue: 1);
      this->PostActionSignal(this, a2: v8);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046DBC0
// Name: public: virtual void CDmeCombinationControlsPanel::OnMoveUpInputControl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationControlsPanel::OnMoveUpInputControl(CDmeCombinationControlsPanel *this)
{
  const char *SelectedControlName; // edi
  int v3; // eax
  CDmeCombinationOperator *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  SelectedControlName = CDmeCombinationControlsPanel::GetSelectedControlName(this);
  if ( SelectedControlName != nullptr )
  {
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hCombinationOperator.m_handle);
    if ( v3 != 0 )
      v4 = (CDmeCombinationOperator *)(v3 - 4);
    else
      v4 = nullptr;
    CDmeCombinationOperator::MoveControlUp(this: v4, pControlName: SelectedControlName);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
    {
      v6 = KeyValues::KeyValues(
             this: v5,
             setName: "DmeElementChanged",
             firstKey: "DmeCombinationControlsPanel",
             firstValue: 1);
      this->PostActionSignal(this, a2: v6);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046DC40
// Name: public: virtual void CDmeCombinationControlsPanel::OnMoveDownInputControl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationControlsPanel::OnMoveDownInputControl(CDmeCombinationControlsPanel *this)
{
  const char *SelectedControlName; // edi
  int v3; // eax
  CDmeCombinationOperator *v4; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  SelectedControlName = CDmeCombinationControlsPanel::GetSelectedControlName(this);
  if ( SelectedControlName != nullptr )
  {
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hCombinationOperator.m_handle);
    if ( v3 != 0 )
      v4 = (CDmeCombinationOperator *)(v3 - 4);
    else
      v4 = nullptr;
    CDmeCombinationOperator::MoveControlDown(this: v4, pControlName: SelectedControlName);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
    {
      v6 = KeyValues::KeyValues(
             this: v5,
             setName: "DmeElementChanged",
             firstKey: "DmeCombinationControlsPanel",
             firstValue: 1);
      this->PostActionSignal(this, a2: v6);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046DCC0
// Name: private: virtual void CDmeCombinationControlsPanel::OnToggleWrinkleType(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeCombinationControlsPanel::OnToggleWrinkleType(
        CDmeCombinationControlsPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>)
{
  const char *SelectedRawControl; // edi
  int v5; // eax
  CDmeCombinationOperator *v6; // ecx
  int v7; // ebx
  int v8; // eax
  CDmeCombinationOperator *v9; // ecx
  float flWrinkleScale; // [esp+18h] [ebp-4h] BYREF

  SelectedRawControl = CDmeCombinationControlsPanel::GetSelectedRawControl(
                         this,
                         a2,
                         a3,
                         nControlIndex: (int *)&flWrinkleScale);
  if ( SelectedRawControl != nullptr )
  {
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hCombinationOperator.m_handle);
    if ( v5 != 0 )
      v6 = (CDmeCombinationOperator *)(v5 - 4);
    else
      v6 = nullptr;
    v7 = LODWORD(flWrinkleScale);
    flWrinkleScale = CDmeCombinationOperator::GetRawControlWrinkleScale(
                       this: v6,
                       nControl: SLODWORD(flWrinkleScale),
                       pRawControlName: SelectedRawControl);
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hCombinationOperator.m_handle);
    if ( v8 != 0 )
      v9 = (CDmeCombinationOperator *)(v8 - 4);
    else
      v9 = nullptr;
    CDmeCombinationOperator::SetWrinkleScale(
      this: v9,
      nControl: v7,
      pRawControlName: SelectedRawControl,
      flWrinkleScale: COERCE_FLOAT(LODWORD(flWrinkleScale) ^ _mask__NegFloat_));
    CDmeCombinationControlsPanel::RefreshRawControlNames(this, a2: v7, a3: (int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046DD50
// Name: public: void CDmeCombinationControlsPanel::SetRawControlWrinkleValue(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeCombinationControlsPanel::SetRawControlWrinkleValue(
        CDmeCombinationControlsPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        float flWrinkleValue)
{
  const char *SelectedRawControl; // edi
  int v6; // eax
  CDmeCombinationOperator *v7; // ecx
  int v8; // ebx
  int v9; // eax
  float flWrinkleScale; // xmm0_4
  CDmeCombinationOperator *v11; // ecx
  int v12; // eax
  int nControlIndex; // [esp+18h] [ebp-4h] BYREF

  SelectedRawControl = CDmeCombinationControlsPanel::GetSelectedRawControl(this, a2, a3, &nControlIndex);
  if ( SelectedRawControl != nullptr )
  {
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hCombinationOperator.m_handle);
    if ( v6 != 0 )
      v7 = (CDmeCombinationOperator *)(v6 - 4);
    else
      v7 = nullptr;
    v8 = nControlIndex;
    if ( CDmeCombinationOperator::GetRawControlWrinkleScale(
           this: v7,
           nControl: nControlIndex,
           pRawControlName: SelectedRawControl) >= 0.0 )
    {
      v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_hCombinationOperator.m_handle);
      if ( v12 != 0 )
        v11 = (CDmeCombinationOperator *)(v12 - 4);
      else
        v11 = nullptr;
      flWrinkleScale = flWrinkleValue;
    }
    else
    {
      v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_hCombinationOperator.m_handle);
      LODWORD(flWrinkleScale) = LODWORD(flWrinkleValue) ^ _mask__NegFloat_;
      if ( v9 != 0 )
        v11 = (CDmeCombinationOperator *)(v9 - 4);
      else
        v11 = nullptr;
    }
    CDmeCombinationOperator::SetWrinkleScale(
      this: v11,
      nControl: v8,
      pRawControlName: SelectedRawControl,
      flWrinkleScale);
    CDmeCombinationControlsPanel::RefreshRawControlNames(this, a2: v8, a3: (int)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046DE20
// Name: private: void CDmeCombinationControlsPanel::OnOpenRawControlsContextMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeCombinationControlsPanel::OnOpenRawControlsContextMenu(
        CDmeCombinationControlsPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>)
{
  int v4; // eax
  vgui::Menu *v5; // eax
  vgui::Menu *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // ebx
  vgui::Panel *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  vgui::Panel *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // ebx
  vgui::Panel *v15; // eax
  vgui::Menu *v16; // eax

  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  if ( v4 != 0
    && v4 != 4
    && this->m_pControlList->GetSelectedItemsCount(this: this->m_pControlList) == 1
    && this->m_pRawControlList->GetSelectedItemsCount(this: this->m_pRawControlList) == 1 )
  {
    v5 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
    if ( v5 != nullptr )
      v6 = vgui::Menu::Menu(this: v5, parent: this, panelName: "ActionMenu");
    else
      v6 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: v6);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "MoveUp");
    else
      v8 = nullptr;
    v9 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationControlsPanel *, _DWORD, int, int))v9->__vftable[1].PaintTraverse)(
      a1: v9,
      a2: "#DmeCombinationSystemEditor_MoveUp",
      a3: v8,
      a4: this,
      a5: 0,
      a6: a3,
      a7: a2);
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "MoveDown");
    else
      v11 = nullptr;
    v12 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationControlsPanel *, _DWORD))v12->__vftable[1].PaintTraverse)(
      a1: v12,
      a2: "#DmeCombinationSystemEditor_MoveDown",
      a3: v11,
      a4: this,
      a5: 0);
    v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v13 != nullptr )
      v14 = KeyValues::KeyValues(this: v13, setName: "ToggleWrinkleType");
    else
      v14 = nullptr;
    v15 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v15->__vftable[1].PaintTraverse(this: v15, a2: (bool)"#DmeCombinationSystemEditor_ToggleWrinkleType", a3: (bool)v14);
    v16 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
    vgui::Menu::PlaceContextMenu(parent: this, menu: v16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046DF90
// Name: private: virtual void CDmeCombinationControlsPanel::OnOpenContextMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeCombinationControlsPanel::OnOpenContextMenu(
        CDmeCombinationControlsPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        KeyValues *kv)
{
  vgui::Panel *v5; // eax
  int v6; // eax
  CDmeRawControlListPanel *Ptr; // eax
  int v8; // edi
  int v9; // ebx
  int v10; // eax
  KeyValues *v11; // eax
  const char *String; // edi
  int v13; // eax
  CDmeCombinationOperator *v14; // ecx
  int ControlIndex; // edi
  int v16; // eax
  CDmeCombinationOperator *v17; // ecx
  int v18; // eax
  CDmeCombinationOperator *v19; // ecx
  int v20; // eax
  CDmeCombinationOperator *v21; // ecx
  vgui::Menu *v22; // eax
  vgui::Menu *v23; // eax
  KeyValues *v24; // eax
  KeyValues *v25; // edi
  vgui::Panel *v26; // eax
  KeyValues *v27; // eax
  KeyValues *v28; // edi
  vgui::Panel *v29; // eax
  KeyValues *v30; // eax
  KeyValues *v31; // edi
  vgui::Panel *v32; // eax
  vgui::Menu *v33; // eax
  KeyValues *v34; // eax
  KeyValues *v35; // edi
  vgui::Panel *v36; // eax
  vgui::Menu *v37; // eax
  KeyValues *v38; // eax
  KeyValues *v39; // edi
  vgui::Panel *v40; // eax
  vgui::Panel *v41; // eax
  KeyValues *v42; // eax
  KeyValues *v43; // edi
  vgui::Panel *v44; // eax
  KeyValues *v45; // eax
  KeyValues *v46; // edi
  vgui::Panel *v47; // eax
  vgui::Panel *v48; // eax
  KeyValues *v49; // eax
  KeyValues *v50; // edi
  vgui::Panel *v51; // eax
  vgui::Menu *v52; // eax
  int v53; // [esp-8h] [ebp-1Ch]
  int v54; // [esp-8h] [ebp-1Ch]
  bool bEyelidControls; // [esp+8h] [ebp-Ch]
  bool bStereoControls; // [esp+Ch] [ebp-8h]
  int nSelectedItemCount; // [esp+10h] [ebp-4h]
  char bGroupedControls_3; // [esp+1Fh] [ebp+Bh]

  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v5 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v5->MarkForDeletion(this: v5);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  if ( v6 != 0 && v6 != 4 )
  {
    Ptr = (CDmeRawControlListPanel *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
    if ( Ptr == this->m_pRawControlList )
    {
      CDmeCombinationControlsPanel::OnOpenRawControlsContextMenu(this, a2, a3);
      return;
    }
    if ( Ptr == (CDmeRawControlListPanel *)this->m_pControlList )
    {
      bGroupedControls_3 = 0;
      bStereoControls = false;
      bEyelidControls = false;
      v8 = ((int (__thiscall *)(CDmeInputControlListPanel *, int))this->m_pControlList->GetSelectedItemsCount)(
             a1: this->m_pControlList,
             a2);
      v9 = 0;
      nSelectedItemCount = v8;
      if ( v8 > 0 )
      {
        do
        {
          v10 = this->m_pControlList->GetSelectedItem(this: this->m_pControlList, a2: v9);
          v11 = this->m_pControlList->GetItem(this: this->m_pControlList, a2: v10);
          String = KeyValues::GetString(this: v11, keyName: "name", defaultValue: defaultValue);
          v13 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
                  a1: g_pDataModel.u,
                  a2: this->m_hCombinationOperator.m_handle);
          if ( v13 != 0 )
            v14 = (CDmeCombinationOperator *)(v13 - 4);
          else
            v14 = nullptr;
          ControlIndex = CDmeCombinationOperator::FindControlIndex(this: v14, pControlName: String);
          if ( ControlIndex >= 0 )
          {
            v16 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: this->m_hCombinationOperator.m_handle);
            if ( v16 != 0 )
              v17 = (CDmeCombinationOperator *)(v16 - 4);
            else
              v17 = nullptr;
            if ( CDmeCombinationOperator::GetRawControlCount(this: v17, nControl: ControlIndex) > 1 )
              bGroupedControls_3 = 1;
            v18 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: this->m_hCombinationOperator.m_handle);
            if ( v18 != 0 )
              v19 = (CDmeCombinationOperator *)(v18 - 4);
            else
              v19 = nullptr;
            if ( CDmeCombinationOperator::IsStereoControl(this: v19, nControlIndex: ControlIndex) )
              bStereoControls = true;
            v20 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: this->m_hCombinationOperator.m_handle);
            if ( v20 != 0 )
              v21 = (CDmeCombinationOperator *)(v20 - 4);
            else
              v21 = nullptr;
            if ( CDmeCombinationOperator::IsEyelidControl(this: v21, nControlIndex: ControlIndex) )
              bEyelidControls = true;
          }
          ++v9;
        }
        while ( v9 < nSelectedItemCount );
        v8 = nSelectedItemCount;
      }
      v22 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
      if ( v22 != nullptr )
        v23 = vgui::Menu::Menu(this: v22, parent: this, panelName: "ActionMenu");
      else
        v23 = nullptr;
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: v23);
      if ( v8 > 1 )
      {
        v24 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v24 != nullptr )
          v25 = KeyValues::KeyValues(this: v24, setName: "GroupControls");
        else
          v25 = nullptr;
        v26 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationControlsPanel *, _DWORD))v26->__vftable[1].PaintTraverse)(
          a1: v26,
          a2: "#DmeCombinationSystemEditor_GroupControls",
          a3: v25,
          a4: this,
          a5: 0);
        v8 = nSelectedItemCount;
      }
      if ( bGroupedControls_3 != 0 )
      {
        v27 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v27 != nullptr )
          v28 = KeyValues::KeyValues(this: v27, setName: "UngroupControls");
        else
          v28 = nullptr;
        v29 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationControlsPanel *, _DWORD))v29->__vftable[1].PaintTraverse)(
          a1: v29,
          a2: "#DmeCombinationSystemEditor_UngroupControls",
          a3: v28,
          a4: this,
          a5: 0);
        v8 = nSelectedItemCount;
      }
      if ( v8 >= 1 )
      {
        v30 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v30 != nullptr )
          v31 = KeyValues::KeyValues(this: v30, setName: "ToggleStereoControl");
        else
          v31 = nullptr;
        v32 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        v53 = ((int (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationControlsPanel *, _DWORD))v32->__vftable[1].InternalFocusChanged)(
                a1: v32,
                a2: "#DmeCombinationSystemEditor_StereoControl",
                a3: v31,
                a4: this,
                a5: 0);
        v33 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
        vgui::Menu::SetMenuItemChecked(this: v33, itemID: v53, state: bStereoControls);
        v34 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v34 != nullptr )
          v35 = KeyValues::KeyValues(this: v34, setName: "ToggleEyelidControl");
        else
          v35 = nullptr;
        v36 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        v54 = ((int (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationControlsPanel *, _DWORD))v36->__vftable[1].InternalFocusChanged)(
                a1: v36,
                a2: "#DmeCombinationSystemEditor_EyelidControl",
                a3: v35,
                a4: this,
                a5: 0);
        v37 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
        vgui::Menu::SetMenuItemChecked(this: v37, itemID: v54, state: bEyelidControls);
        if ( nSelectedItemCount == 1 )
        {
          v38 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v38 != nullptr )
            v39 = KeyValues::KeyValues(this: v38, setName: "RenameControl");
          else
            v39 = nullptr;
          v40 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationControlsPanel *, _DWORD))v40->__vftable[1].PaintTraverse)(
            a1: v40,
            a2: "#DmeCombinationSystemEditor_RenameControl",
            a3: v39,
            a4: this,
            a5: 0);
          goto LABEL_56;
        }
        if ( nSelectedItemCount >= 1 )
        {
LABEL_56:
          v41 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          v41->__vftable[1].DeletePanel(this: v41);
          v42 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v42 != nullptr )
            v43 = KeyValues::KeyValues(this: v42, setName: "MoveUpInputControl");
          else
            v43 = nullptr;
          v44 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationControlsPanel *, _DWORD))v44->__vftable[1].PaintTraverse)(
            a1: v44,
            a2: "#DmeCombinationSystemEditor_MoveUp",
            a3: v43,
            a4: this,
            a5: 0);
          v45 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v45 != nullptr )
            v46 = KeyValues::KeyValues(this: v45, setName: "MoveDownInputControl");
          else
            v46 = nullptr;
          v47 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationControlsPanel *, _DWORD))v47->__vftable[1].PaintTraverse)(
            a1: v47,
            a2: "#DmeCombinationSystemEditor_MoveDown",
            a3: v46,
            a4: this,
            a5: 0);
          goto LABEL_64;
        }
      }
      if ( bGroupedControls_3 == 0 )
      {
LABEL_65:
        v49 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v49 != nullptr )
          v50 = KeyValues::KeyValues(this: v49, setName: "ImportCombination");
        else
          v50 = nullptr;
        v51 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationControlsPanel *))v51->__vftable[1].PaintTraverse)(
          a1: v51,
          a2: "#DmeCombinationSystemEditor_Import",
          a3: v50,
          a4: this);
        v52 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
        vgui::Menu::PlaceContextMenu(parent: this, menu: v52);
        return;
      }
LABEL_64:
      v48 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      v48->__vftable[1].DeletePanel(this: v48);
      goto LABEL_65;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046E430
// Name: private: virtual void CDmeCombinationControlsPanel::OnItemDeselected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeCombinationControlsPanel::OnItemDeselected(
        CDmeCombinationControlsPanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *kv)
{
  if ( KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pControlList )
    CDmeCombinationControlsPanel::RefreshRawControlNames(this, a2, a3: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x0046E460
// Name: public: CDmeInputControlListPanel::CDmeInputControlListPanel(class vgui::Panel __near *,char const __near *,class CDmeCombinationControlsPanel __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeInputControlListPanel *__thiscall CDmeInputControlListPanel::CDmeInputControlListPanel(
        CDmeInputControlListPanel *this,
        vgui::Panel *pParent,
        const char *pName,
        CDmeCombinationControlsPanel *pComboPanel)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::ListPanel::ListPanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CDmeInputControlListPanel_vtbl *)&CDmeInputControlListPanel::`vftable';
  if ( `CDmeInputControlListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeInputControlListPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CDmeInputControlListPanel");
    v5->pfnClassName = CDmeInputControlListPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::ListPanel");
  }
  if ( `CDmeInputControlListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeInputControlListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CDmeInputControlListPanel");
    v6->pfnClassName = CDmeInputControlListPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::ListPanel");
  }
  if ( `CDmeInputControlListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeInputControlListPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeInputControlListPanel");
    v7->pfnClassName = CDmeInputControlListPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::ListPanel");
  }
  this->m_pComboPanel = pComboPanel;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046E540
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeInputControlListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeInputControlListPanel::GetMessageMap(CDmeInputControlListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeInputControlListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeInputControlListPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeInputControlListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeInputControlListPanel");
  `CDmeInputControlListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046E570
// Name: public: virtual struct PanelAnimationMap __near * CDmeInputControlListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeInputControlListPanel::GetAnimMap(CDmeInputControlListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeInputControlListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0046E580
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeInputControlListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeInputControlListPanel::GetKBMap(CDmeInputControlListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeInputControlListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeInputControlListPanel::GetKBMap'::`2'::s_pMap;
  `CDmeInputControlListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeInputControlListPanel");
  `CDmeInputControlListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046E5B0
// Name: public: virtual void CDmeInputControlListPanel::OnCreateDragData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeInputControlListPanel::OnCreateDragData(CDmeInputControlListPanel *this, KeyValues *msg)
{
  const char *SelectedControlName; // eax

  SelectedControlName = CDmeCombinationControlsPanel::GetSelectedControlName(this: this->m_pComboPanel);
  if ( SelectedControlName != nullptr )
  {
    KeyValues::SetString(this: msg, keyName: "inputControl", value: SelectedControlName);
    KeyValues::SetInt(this: msg, keyName: "selfDroppable", value: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046E5F0
// Name: private: virtual void CDmeRawControlListPanel::OnNewWrinkleText(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeRawControlListPanel::OnNewWrinkleText(
        CDmeRawControlListPanel *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>)
{
  float flWrinkleValue; // xmm0_4
  char szEditText[260]; // [esp+14h] [ebp-108h] BYREF
  float flWrinkleScale; // [esp+118h] [ebp-4h]

  this->LeaveEditMode(this);
  this->m_pWrinkleEdit->GetText_2(this: this->m_pWrinkleEdit, a2: szEditText, a3: 260);
  this->m_pWrinkleEdit->SetVisible(this: this->m_pWrinkleEdit, a2: false);
  flWrinkleScale = atof(nptr: szEditText);
  flWrinkleValue = flWrinkleScale;
  if ( this->m_bIsWrinkle )
    LODWORD(flWrinkleValue) = LODWORD(flWrinkleScale) ^ _mask__NegFloat_;
  CDmeCombinationControlsPanel::SetRawControlWrinkleValue(this: this->m_pComboPanel, a2, a3, flWrinkleValue);
}

//------------------------------------------------------------------------------
// Address: 0x0046E680
// Name: public: CRawControlPickerFrame::CRawControlPickerFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CRawControlPickerFrame *__thiscall CRawControlPickerFrame::CRawControlPickerFrame(
        CRawControlPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ListPanel *v7; // eax
  vgui::ListPanel *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "RawControlPickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CRawControlPickerFrame_vtbl *)&CRawControlPickerFrame::`vftable';
  if ( `CRawControlPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CRawControlPickerFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CRawControlPickerFrame");
    v4->pfnClassName = CRawControlPickerFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CRawControlPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CRawControlPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CRawControlPickerFrame");
    v5->pfnClassName = CRawControlPickerFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CRawControlPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CRawControlPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CRawControlPickerFrame");
    v6->pfnClassName = CRawControlPickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  this->m_pContextKeyValues = nullptr;
  v7 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v7 != nullptr )
    v8 = vgui::ListPanel::ListPanel(this: v7, parent: this, panelName: "RawControlList");
  else
    v8 = nullptr;
  this->m_pRawControlList = v8;
  v8->AddColumnHeader(this: v8, a2: 0, a3: "name", a4: "Raw Control Name", a5: 52, a6: 0);
  this->m_pRawControlList->SetSelectIndividualCells(this: this->m_pRawControlList, a2: false);
  this->m_pRawControlList->SetEmptyListText_2(this: this->m_pRawControlList, a2: "No raw controls");
  this->m_pRawControlList->AddActionSignalTarget_2(this: this->m_pRawControlList, a2: this);
  this->m_pRawControlList->SetSortFunc(this: this->m_pRawControlList, a2: 0, a3: PresetNameSortFunc);
  this->m_pRawControlList->SetSortColumn(this: this->m_pRawControlList, a2: 0);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OkButton",
            text: "#MessageBox_OK",
            pActionSignalTarget: this,
            pCmd: "Ok");
  else
    v10 = nullptr;
  this->m_pOpenButton = v10;
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "CancelButton",
            text: "#MessageBox_Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v12 = nullptr;
  this->m_pCancelButton = v12;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/dmecombinationsystemeditor_rawcontrolpickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046E890
// Name: public: virtual struct vgui::PanelMessageMap __near * CRawControlPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CRawControlPickerFrame::GetMessageMap(CRawControlPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CRawControlPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CRawControlPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CRawControlPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CRawControlPickerFrame");
  `CRawControlPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046E8C0
// Name: public: virtual struct PanelAnimationMap __near * CRawControlPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CRawControlPickerFrame::GetAnimMap(CRawControlPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CRawControlPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x0046E8D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CRawControlPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CRawControlPickerFrame::GetKBMap(CRawControlPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CRawControlPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CRawControlPickerFrame::GetKBMap'::`2'::s_pMap;
  `CRawControlPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CRawControlPickerFrame");
  `CRawControlPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046E900
// Name: private: virtual void CDmeCombinationDominationRulesPanel::OnOpenContextMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeCombinationDominationRulesPanel::OnOpenContextMenu(
        CDmeCombinationDominationRulesPanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *kv)
{
  vgui::Panel *v4; // eax
  int v5; // eax
  vgui::Menu *v6; // eax
  vgui::Menu *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // ebx
  vgui::Panel *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // ebx
  vgui::Panel *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // ebx
  vgui::Panel *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // ebx
  vgui::Panel *v19; // eax
  vgui::Panel *v20; // eax
  KeyValues *v21; // eax
  KeyValues *v22; // ebx
  vgui::Panel *v23; // eax
  KeyValues *v24; // eax
  KeyValues *v25; // ebx
  vgui::Panel *v26; // eax
  vgui::Panel *v27; // eax
  KeyValues *v28; // eax
  KeyValues *v29; // ebx
  vgui::Panel *v30; // eax
  KeyValues *v31; // eax
  KeyValues *v32; // ebx
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  KeyValues *v35; // eax
  KeyValues *v36; // ebx
  vgui::Panel *v37; // eax
  vgui::Menu *v38; // eax
  int nSelectedItemCount; // [esp+10h] [ebp+8h]

  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v4 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v4->MarkForDeletion(this: v4);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  if ( v5 != 0
    && v5 != 4
    && KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pDominationRulesList )
  {
    nSelectedItemCount = this->m_pDominationRulesList->GetSelectedItemsCount(this: this->m_pDominationRulesList);
    v6 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
    if ( v6 != nullptr )
      v7 = vgui::Menu::Menu(this: v6, parent: this, panelName: "ActionMenu");
    else
      v7 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: v7);
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
      v9 = KeyValues::KeyValues(this: v8, setName: "AddDominationRule");
    else
      v9 = nullptr;
    v10 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationDominationRulesPanel *, _DWORD, int))v10->__vftable[1].PaintTraverse)(
      a1: v10,
      a2: "#DmeCombinationSystemEditor_AddDominationRule",
      a3: v9,
      a4: this,
      a5: 0,
      a6: a2);
    if ( nSelectedItemCount > 0 )
    {
      v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v11 != nullptr )
        v12 = KeyValues::KeyValues(this: v11, setName: "RemoveDominationRule");
      else
        v12 = nullptr;
      v13 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationDominationRulesPanel *, _DWORD))v13->__vftable[1].PaintTraverse)(
        a1: v13,
        a2: "#DmeCombinationSystemEditor_RemoveDominationRule",
        a3: v12,
        a4: this,
        a5: 0);
    }
    if ( nSelectedItemCount == 1 )
    {
      v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v14 != nullptr )
        v15 = KeyValues::KeyValues(this: v14, setName: "DuplicateSuppressed");
      else
        v15 = nullptr;
      v16 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationDominationRulesPanel *, _DWORD))v16->__vftable[1].PaintTraverse)(
        a1: v16,
        a2: "#DmeCombinationSystemEditor_DuplicateSuppressed",
        a3: v15,
        a4: this,
        a5: 0);
      v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v17 != nullptr )
        v18 = KeyValues::KeyValues(this: v17, setName: "DuplicateDominators");
      else
        v18 = nullptr;
      v19 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationDominationRulesPanel *, _DWORD))v19->__vftable[1].PaintTraverse)(
        a1: v19,
        a2: "#DmeCombinationSystemEditor_DuplicateDominators",
        a3: v18,
        a4: this,
        a5: 0);
      v20 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      v20->__vftable[1].DeletePanel(this: v20);
      v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v21 != nullptr )
        v22 = KeyValues::KeyValues(this: v21, setName: "SelectSuppressed");
      else
        v22 = nullptr;
      v23 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationDominationRulesPanel *, _DWORD))v23->__vftable[1].PaintTraverse)(
        a1: v23,
        a2: "#DmeCombinationSystemEditor_SelectSuppressed",
        a3: v22,
        a4: this,
        a5: 0);
      v24 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v24 != nullptr )
        v25 = KeyValues::KeyValues(this: v24, setName: "SelectDominators");
      else
        v25 = nullptr;
      v26 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationDominationRulesPanel *, _DWORD))v26->__vftable[1].PaintTraverse)(
        a1: v26,
        a2: "#DmeCombinationSystemEditor_SelectDominators",
        a3: v25,
        a4: this,
        a5: 0);
      v27 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      v27->__vftable[1].DeletePanel(this: v27);
      v28 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v28 != nullptr )
        v29 = KeyValues::KeyValues(this: v28, setName: "MoveUp");
      else
        v29 = nullptr;
      v30 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationDominationRulesPanel *, _DWORD))v30->__vftable[1].PaintTraverse)(
        a1: v30,
        a2: "#DmeCombinationSystemEditor_MoveUp",
        a3: v29,
        a4: this,
        a5: 0);
      v31 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v31 != nullptr )
        v32 = KeyValues::KeyValues(this: v31, setName: "MoveDown");
      else
        v32 = nullptr;
      v33 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationDominationRulesPanel *, _DWORD))v33->__vftable[1].PaintTraverse)(
        a1: v33,
        a2: "#DmeCombinationSystemEditor_MoveDown",
        a3: v32,
        a4: this,
        a5: 0);
    }
    v34 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v34->__vftable[1].DeletePanel(this: v34);
    v35 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v35 != nullptr )
      v36 = KeyValues::KeyValues(this: v35, setName: "ImportDominationRules");
    else
      v36 = nullptr;
    v37 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CDmeCombinationDominationRulesPanel *))v37->__vftable[1].PaintTraverse)(
      a1: v37,
      a2: "#DmeCombinationSystemEditor_ImportDomination",
      a3: v36,
      a4: this);
    v38 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
    vgui::Menu::PlaceContextMenu(parent: this, menu: v38);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046ECD0
// Name: public: void CUtlMemoryFixedGrowable<bool,256,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryFixedGrowable<bool,256,int>::Grow(CUtlMemoryFixedGrowable<bool,256,int> *this, int nCount)
{
  unsigned int m_nAllocationCount; // edi
  unsigned __int8 *v4; // ebx

  if ( this->m_nGrowSize < 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    this->m_nGrowSize = this->m_nMallocGrowSize;
    if ( m_nAllocationCount != 0 )
    {
      v4 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
      memcpy(dst: v4, src: (unsigned __int8 *)this->m_pMemory, count: m_nAllocationCount);
      this->m_pMemory = (bool *)v4;
      CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: nCount);
      return;
    }
    this->m_pMemory = nullptr;
  }
  CUtlMemory<bool,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: nCount);
}

//------------------------------------------------------------------------------
// Address: 0x0046ED40
// Name: public: virtual CDmeCombinationControlsPanel::~CDmeCombinationControlsPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationControlsPanel::~CDmeCombinationControlsPanel(CDmeCombinationControlsPanel *this)
{
  vgui::Panel *v2; // eax

  this->__vftable = (CDmeCombinationControlsPanel_vtbl *)&CDmeCombinationControlsPanel::`vftable';
  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v2->MarkForDeletion(this: v2);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  vgui::EditablePanel::SaveUserConfig(this);
  if ( g_pDataModel.u.m_Id != 0 )
    CDmeElementRefHelper::Unref(
      this: &this->m_hCombinationOperator,
      hElement: this->m_hCombinationOperator.m_handle,
      handleType: HT_WEAK);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046EDB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeCombinationControlsPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeCombinationControlsPanel::GetMessageMap(CDmeCombinationControlsPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeCombinationControlsPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeCombinationControlsPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeCombinationControlsPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationControlsPanel");
  `CDmeCombinationControlsPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046EDE0
// Name: public: virtual struct PanelAnimationMap __near * CDmeCombinationControlsPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeCombinationControlsPanel::GetAnimMap(CDmeCombinationControlsPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeCombinationControlsPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0046EDF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeCombinationControlsPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeCombinationControlsPanel::GetKBMap(CDmeCombinationControlsPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeCombinationControlsPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeCombinationControlsPanel::GetKBMap'::`2'::s_pMap;
  `CDmeCombinationControlsPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeCombinationControlsPanel");
  `CDmeCombinationControlsPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046EE20
// Name: private: bool CDmeCombinationControlsPanel::HasDuplicateControlName(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeCombinationControlsPanel::HasDuplicateControlName(
        CDmeCombinationControlsPanel *this,
        const char *pControlName,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *retiredControlNames)
{
  int m_Size; // edi
  int v4; // esi
  int v5; // ebx
  const char *v6; // eax
  int v7; // eax
  CDmeCombinationOperator *v8; // ecx
  vgui::MessageBox *v9; // eax
  vgui::MessageBox *v10; // eax

  m_Size = retiredControlNames->m_Size;
  v4 = 0;
  if ( m_Size > 0 )
  {
    v5 = 0;
    do
    {
      v6 = CUtlString::operator char const *(this: &retiredControlNames->m_Memory.m_pMemory[v5]);
      if ( _V_stricmp(s1: v6, s2: pControlName) == 0 )
        break;
      ++v4;
      ++v5;
    }
    while ( v4 < m_Size );
  }
  if ( v4 != m_Size )
    return 0;
  v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  v8 = v7 != 0 ? (CDmeCombinationOperator *)(v7 - 4) : nullptr;
  if ( CDmeCombinationOperator::FindControlIndex(this: v8, pControlName) < 0 )
    return 0;
  v9 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
  if ( v9 != nullptr )
    v10 = vgui::MessageBox::MessageBox(
            this: v9,
            title: "#DmeCombinationSystemEditor_DuplicateNameTitle",
            text: "#DmeCombinationSystemEditor_DuplicateNameText",
            parent: this);
  else
    v10 = nullptr;
  v10->DoModal_2(this: v10, a2: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0046EEE0
// Name: public: virtual bool CDmeInputControlListPanel::IsDroppable(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeInputControlListPanel::IsDroppable(
        CDmeInputControlListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msgList)
{
  KeyValues *v3; // esi
  bool result; // al

  result = false;
  if ( msgList->m_Size > 0 )
  {
    v3 = *msgList->m_Memory.m_pMemory;
    if ( KeyValues::GetPtr(this: v3, keyName: "panel", defaultValue: nullptr) == this
      && this->m_pComboPanel != nullptr
      && KeyValues::GetString(this: v3, keyName: "inputControl", defaultValue: defaultValue) != nullptr
      && KeyValues::GetInt(this: v3, keyName: "selfDroppable", defaultValue: 0) != 0 )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046EFA0
// Name: public: virtual CDmeCombinationDominationRulesPanel::~CDmeCombinationDominationRulesPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationDominationRulesPanel::~CDmeCombinationDominationRulesPanel(
        CDmeCombinationDominationRulesPanel *this)
{
  vgui::Panel *v2; // eax

  this->__vftable = (CDmeCombinationDominationRulesPanel_vtbl *)&CDmeCombinationDominationRulesPanel::`vftable';
  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v2->MarkForDeletion(this: v2);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  vgui::EditablePanel::SaveUserConfig(this);
  if ( g_pDataModel.u.m_Id != 0 )
    CDmeElementRefHelper::Unref(
      this: &this->m_hCombinationOperator,
      hElement: this->m_hCombinationOperator.m_handle,
      handleType: HT_WEAK);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0046F010
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeCombinationDominationRulesPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeCombinationDominationRulesPanel::GetMessageMap(
        CDmeCombinationDominationRulesPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeCombinationDominationRulesPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeCombinationDominationRulesPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeCombinationDominationRulesPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationDominationRulesPanel");
  `CDmeCombinationDominationRulesPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046F040
// Name: public: virtual struct PanelAnimationMap __near * CDmeCombinationDominationRulesPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeCombinationDominationRulesPanel::GetAnimMap(
        CDmeCombinationDominationRulesPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeCombinationDominationRulesPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0046F050
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeCombinationDominationRulesPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeCombinationDominationRulesPanel::GetKBMap(
        CDmeCombinationDominationRulesPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeCombinationDominationRulesPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeCombinationDominationRulesPanel::GetKBMap'::`2'::s_pMap;
  `CDmeCombinationDominationRulesPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeCombinationDominationRulesPanel");
  `CDmeCombinationDominationRulesPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046F100
// Name: public: void CDmeCombinationControlsPanel::RefreshCombinationOperator(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeCombinationControlsPanel::RefreshCombinationOperator(
        CDmeCombinationControlsPanel *this@<ecx>,
        int a2@<ebx>)
{
  const char *SelectedControlName; // eax
  int v4; // eax
  int v5; // esi
  unsigned __int8 *m_pMemory; // eax
  bool v7; // zf
  int v8; // eax
  CDmeCombinationOperator *v9; // ecx
  int j; // eax
  CDmeCombinationOperator *v11; // ecx
  int RawControlCount; // eax
  int (__thiscall *v13)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // edx
  int v14; // eax
  CDmeCombinationOperator *v15; // ecx
  float v16; // xmm0_4
  int (__thiscall *v17)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // eax
  int v18; // eax
  CDmeCombinationOperator *v19; // ecx
  const char *v20; // ebx
  KeyValues *v21; // eax
  KeyValues *v22; // esi
  int v23; // eax
  CDmeCombinationOperator *v24; // ecx
  const char *v25; // eax
  int v26; // eax
  CDmeCombinationOperator *v27; // ecx
  const char *v28; // eax
  Color v29; // eax
  const char *v30; // eax
  DmElementHandle_t value; // [esp+20h] [ebp-34h]
  DmElementHandle_t valuea; // [esp+20h] [ebp-34h]
  CUtlString controlName; // [esp+2Ch] [ebp-28h] BYREF
  int nCount; // [esp+3Ch] [ebp-18h]
  float flDefault; // [esp+40h] [ebp-14h]
  int v36; // [esp+44h] [ebp-10h]
  Color v37; // [esp+48h] [ebp-Ch]
  int i; // [esp+4Ch] [ebp-8h]
  bool bIsMultiControl; // [esp+53h] [ebp-1h]

  SelectedControlName = CDmeCombinationControlsPanel::GetSelectedControlName(this);
  CUtlString::CUtlString(this: &controlName, pString: SelectedControlName);
  this->m_pControlList->RemoveAll(this: this->m_pControlList);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  v5 = 0;
  if ( v4 == 0 || v4 == 4 )
  {
    controlName.m_Storage.m_nActualLength = 0;
    if ( controlName.m_Storage.m_Memory.m_nGrowSize < 0 )
      return;
    m_pMemory = controlName.m_Storage.m_Memory.m_pMemory;
    v7 = controlName.m_Storage.m_Memory.m_pMemory == nullptr;
    goto LABEL_45;
  }
  v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  if ( v8 != 0 )
    v9 = (CDmeCombinationOperator *)(v8 - 4);
  else
    v9 = nullptr;
  nCount = CDmeMaterialGroup::GetListAttr(this: v9);
  i = 0;
  if ( nCount > 0 )
  {
    for ( j = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
                a1: g_pDataModel.u,
                a2: this->m_hCombinationOperator.m_handle,
                a3: a2);
          ;
          j = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 72))(
                a1: g_pDataModel.u,
                a2: this->m_hCombinationOperator.m_handle,
                a3: 0) )
    {
      if ( j != 0 )
        v11 = (CDmeCombinationOperator *)(j - 4);
      else
        v11 = nullptr;
      RawControlCount = CDmeCombinationOperator::GetRawControlCount(this: v11, nControl: v5);
      v13 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72);
      value = this->m_hCombinationOperator.m_handle;
      bIsMultiControl = RawControlCount > 1;
      v14 = ((int (__thiscall *)(_DWORD, _DWORD))v13)(
              a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
              a2: value);
      if ( v14 != 0 )
        v15 = (CDmeCombinationOperator *)(v14 - 4);
      else
        v15 = nullptr;
      if ( CDmeCombinationOperator::GetRawControlCount(this: v15, nControl: v5) == 2 )
        v16 = 0.5;
      else
        v16 = 0.0;
      v17 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72);
      valuea = this->m_hCombinationOperator.m_handle;
      flDefault = v16;
      v18 = ((int (__thiscall *)(_DWORD, _DWORD))v17)(
              a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
              a2: valuea);
      if ( v18 != 0 )
        v19 = (CDmeCombinationOperator *)(v18 - 4);
      else
        v19 = nullptr;
      v20 = CDmeCombinationOperator::GetControlName(this: v19, i: v5);
      v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v21 != nullptr )
        v22 = KeyValues::KeyValues(this: v21, setName: "node", firstKey: "name", firstValue: v20);
      else
        v22 = nullptr;
      v23 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_hCombinationOperator.m_handle);
      if ( v23 != 0 )
        v24 = (CDmeCombinationOperator *)(v23 - 4);
      else
        v24 = nullptr;
      v7 = !CDmeCombinationOperator::IsStereoControl(this: v24, nControlIndex: i);
      v25 = "On";
      if ( v7 )
        v25 = "Off";
      KeyValues::SetString(this: v22, keyName: "stereo", value: v25);
      v26 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_hCombinationOperator.m_handle);
      if ( v26 != 0 )
        v27 = (CDmeCombinationOperator *)(v26 - 4);
      else
        v27 = nullptr;
      v7 = !CDmeCombinationOperator::IsEyelidControl(this: v27, nControlIndex: i);
      v28 = "On";
      if ( v7 )
        v28 = "Off";
      KeyValues::SetString(this: v22, keyName: "eyelid", value: v28);
      KeyValues::SetFloat(this: v22, keyName: "default", value: flDefault);
      if ( bIsMultiControl )
      {
        v37 = (Color)-16727872;
        v29 = (Color)-16727872;
      }
      else
      {
        v36 = -1;
        v29 = (Color)-1;
      }
      KeyValues::SetColor(this: v22, keyName: "cellcolor", value: v29);
      v5 = ((int (__thiscall *)(CDmeInputControlListPanel *, KeyValues *, _DWORD, _DWORD))this->m_pControlList->AddItem)(
             a1: this->m_pControlList,
             a2: v22,
             a3: 0,
             a4: 0);
      v30 = CUtlString::operator char const *(this: &controlName);
      if ( _V_strcmp(s1: v30, s2: v20) == 0 )
        this->m_pControlList->SetSingleSelectedItem(this: this->m_pControlList, a2: v5);
      if ( ++i >= nCount )
        break;
      v5 = i;
    }
    a2 = 0;
  }
  CDmeCombinationControlsPanel::RefreshRawControlNames(this, a2, a3: v5);
  controlName.m_Storage.m_nActualLength = 0;
  if ( controlName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = controlName.m_Storage.m_Memory.m_pMemory;
    v7 = controlName.m_Storage.m_Memory.m_pMemory == nullptr;
LABEL_45:
    if ( !v7 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F3A0
// Name: public: void CDmeCombinationControlsPanel::MoveControlInFrontOf(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeCombinationControlsPanel::MoveControlInFrontOf(
        CDmeCombinationControlsPanel *this@<ecx>,
        int a2@<ebx>,
        const char *pDragControl,
        const char *pDropControl)
{
  int v5; // eax
  CDmeCombinationOperator *v6; // ecx
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  if ( v5 != 0 )
    v6 = (CDmeCombinationOperator *)(v5 - 4);
  else
    v6 = nullptr;
  CDmeCombinationOperator::MoveControlBefore(this: v6, pDragControlName: pDragControl, pDropControlName: pDropControl);
  CDmeCombinationControlsPanel::RefreshCombinationOperator(this, a2);
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
  {
    v8 = KeyValues::KeyValues(
           this: v7,
           setName: "DmeElementChanged",
           firstKey: "DmeCombinationControlsPanel",
           firstValue: 1);
    this->PostActionSignal(this, a2: v8);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F420
// Name: private: void CDmeCombinationControlsPanel::PerformRenameControl(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationControlsPanel::PerformRenameControl(
        CDmeCombinationControlsPanel *this,
        const char *pNewControlName)
{
  int v3; // eax
  KeyValues *v4; // eax
  const char *String; // edi
  int v6; // eax
  CDmeCombinationOperator *v7; // ecx
  int ControlIndex; // edi
  int v9; // eax
  CDmeCombinationOperator *v10; // ecx
  int v11; // eax
  int v12; // eax
  CDmeCombinationOperator *v13; // ecx

  if ( this->m_pControlList->GetSelectedItemsCount(this: this->m_pControlList) == 1 )
  {
    v3 = this->m_pControlList->GetSelectedItem(this: this->m_pControlList, a2: 0);
    v4 = this->m_pControlList->GetItem(this: this->m_pControlList, a2: v3);
    String = KeyValues::GetString(this: v4, keyName: "name", defaultValue: defaultValue);
    v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hCombinationOperator.m_handle);
    v7 = v6 != 0 ? (CDmeCombinationOperator *)(v6 - 4) : nullptr;
    ControlIndex = CDmeCombinationOperator::FindControlIndex(this: v7, pControlName: String);
    if ( ControlIndex >= 0 )
    {
      v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_hCombinationOperator.m_handle);
      v10 = v9 != 0 ? (CDmeCombinationOperator *)(v9 - 4) : nullptr;
      v11 = CDmeCombinationOperator::FindControlIndex(this: v10, pControlName: pNewControlName);
      if ( v11 < 0 || v11 == ControlIndex )
      {
        v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: this->m_hCombinationOperator.m_handle);
        if ( v12 != 0 )
          v13 = (CDmeCombinationOperator *)(v12 - 4);
        else
          v13 = nullptr;
        CDmeCombinationOperator::SetControlName(this: v13, nControl: ControlIndex, pControlName: pNewControlName);
        CDmeCombinationControlsPanel::RefreshCombinationOperator(this, a2: (int)pNewControlName);
        CDmeCombinationControlsPanel::NotifyDataChanged(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F510
// Name: public: virtual void CDmeInputControlListPanel::OnPanelDropped(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeInputControlListPanel::OnPanelDropped(
        CDmeInputControlListPanel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msgList)
{
  KeyValues *v3; // edi
  const char *String; // ebx
  CDmeInputControlListPanel_vtbl *v5; // edi
  int v6; // eax
  KeyValues *v7; // eax
  const char *v8; // eax
  int column; // [esp+4h] [ebp-Ch] BYREF
  int row; // [esp+8h] [ebp-8h] BYREF
  int x; // [esp+Ch] [ebp-4h] BYREF

  if ( msgList->m_Size > 0 )
  {
    v3 = *msgList->m_Memory.m_pMemory;
    if ( KeyValues::GetPtr(this: v3, keyName: "panel", defaultValue: nullptr) == this && this->m_pComboPanel != nullptr )
    {
      String = KeyValues::GetString(this: v3, keyName: "inputControl", defaultValue: defaultValue);
      if ( String != nullptr )
      {
        g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: (int *)&msgList);
        this->GetCellAtPos(this, a2: x, a3: (int)msgList, a4: &row, a5: &column);
        v5 = this->__vftable;
        v6 = this->GetItemIDFromRow(this, a2: row);
        v7 = v5->GetItem(this, a2: v6);
        if ( v7 != nullptr )
        {
          v8 = KeyValues::GetString(this: v7, keyName: "name", defaultValue: defaultValue);
          if ( v8 != nullptr )
            CDmeCombinationControlsPanel::MoveControlInFrontOf(
              this: this->m_pComboPanel,
              a2: (int)String,
              pDragControl: String,
              pDropControl: v8);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F620
// Name: private: class CDmeCombinationDominationRule __near * CDmeCombinationDominationRulesPanel::GetSelectedRule(void)
// Source: json
//------------------------------------------------------------------------------
CDmeCombinationDominationRule *__thiscall CDmeCombinationDominationRulesPanel::GetSelectedRule(
        CDmeCombinationDominationRulesPanel *this)
{
  int v2; // eax
  int v3; // eax
  KeyValues *v4; // eax
  int Int; // eax
  int v6; // eax
  int v7; // esi

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  if ( v2 != 0
    && v2 != 4
    && this->m_pDominationRulesList->GetSelectedItemsCount(this: this->m_pDominationRulesList) == 1
    && (v3 = this->m_pDominationRulesList->GetSelectedItem(this: this->m_pDominationRulesList, a2: 0),
        v4 = this->m_pDominationRulesList->GetItem(this: this->m_pDominationRulesList, a2: v3),
        Int = KeyValues::GetInt(this: v4, keyName: "rule", defaultValue: -1),
        v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
               a1: g_pDataModel.u,
               a2: Int),
        v7 = v6,
        v6 != 0)
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
         a1: v6,
         a2: CDmeCombinationDominationRule::m_classType.u) != 0 )
  {
    return (CDmeCombinationDominationRule *)v7;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F6C0
// Name: private: void CDmeCombinationDominationRulesPanel::SelectRule(class CDmeCombinationDominationRule __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationDominationRulesPanel::SelectRule(
        CDmeCombinationDominationRulesPanel *this,
        CDmeCombinationDominationRule *pRule)
{
  int v3; // edi
  KeyValues *v4; // eax
  int Int; // eax
  int v6; // eax
  CDmeCombinationDominationRule *v7; // esi
  vgui::ListPanel_vtbl *v8; // edx

  v3 = this->m_pDominationRulesList->FirstItem(this: this->m_pDominationRulesList);
  if ( v3 != this->m_pDominationRulesList->InvalidItemID(this: this->m_pDominationRulesList) )
  {
    while ( 1 )
    {
      v4 = this->m_pDominationRulesList->GetItem(this: this->m_pDominationRulesList, a2: v3);
      Int = KeyValues::GetInt(this: v4, keyName: "rule", defaultValue: -1);
      v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: Int);
      v7 = (CDmeCombinationDominationRule *)v6;
      if ( v6 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
             a1: v6,
             a2: CDmeCombinationDominationRule::m_classType.u) == 0 )
      {
        v7 = nullptr;
      }
      v8 = this->m_pDominationRulesList->__vftable;
      if ( pRule == v7 )
        break;
      v3 = ((int (__stdcall *)(int))v8->NextItem)(a1: v3);
      if ( v3 == this->m_pDominationRulesList->InvalidItemID(this: this->m_pDominationRulesList) )
        return;
    }
    ((void (__stdcall *)(int))v8->SetSingleSelectedItem)(a1: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F790
// Name: private: virtual void CDmeCombinationDominationRulesPanel::OnSelectDominators(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationDominationRulesPanel::OnSelectDominators(CDmeCombinationDominationRulesPanel *this)
{
  CExpressionCalculator *SelectedRule; // esi
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int BufferType; // eax
  CRawControlPickerFrame *v6; // eax
  CRawControlPickerFrame *v7; // esi
  int v8; // eax
  CDmeCombinationOperator *v9; // edi
  KeyValues *m_pContextKeyValues; // ecx
  CDmeCombinationDominationRule *pRule; // [esp+8h] [ebp-4h]

  SelectedRule = (CExpressionCalculator *)CDmeCombinationDominationRulesPanel::GetSelectedRule(this);
  pRule = (CDmeCombinationDominationRule *)SelectedRule;
  if ( SelectedRule != nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "OnSelectDominators");
    else
      v4 = nullptr;
    BufferType = CCodecBuffer_Block::GetBufferType(this: SelectedRule);
    KeyValues::SetInt(this: v4, keyName: "rule", value: BufferType);
    v6 = (CRawControlPickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
    if ( v6 != nullptr )
      v7 = CRawControlPickerFrame::CRawControlPickerFrame(this: v6, pParent: this, pTitle: "Select Dominator(s)");
    else
      v7 = nullptr;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hCombinationOperator.m_handle);
    if ( v8 != 0 )
      v9 = (CDmeCombinationOperator *)(v8 - 4);
    else
      v9 = nullptr;
    m_pContextKeyValues = v7->m_pContextKeyValues;
    if ( m_pContextKeyValues != nullptr )
    {
      KeyValues::deleteThis(this: m_pContextKeyValues);
      v7->m_pContextKeyValues = nullptr;
    }
    CRawControlPickerFrame::RefreshRawControlNames(this: v7, pCombinationOperator: v9, pRule, bChooseSuppressed: false);
    v7->m_pContextKeyValues = v4;
    vgui::Frame::DoModal(this: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F860
// Name: private: virtual void CDmeCombinationDominationRulesPanel::OnSelectSuppressed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationDominationRulesPanel::OnSelectSuppressed(CDmeCombinationDominationRulesPanel *this)
{
  CExpressionCalculator *SelectedRule; // esi
  KeyValues *v3; // eax
  KeyValues *v4; // ebx
  int BufferType; // eax
  CRawControlPickerFrame *v6; // eax
  CRawControlPickerFrame *v7; // esi
  int v8; // eax
  CDmeCombinationOperator *v9; // edi
  KeyValues *m_pContextKeyValues; // ecx
  CDmeCombinationDominationRule *pRule; // [esp+8h] [ebp-4h]

  SelectedRule = (CExpressionCalculator *)CDmeCombinationDominationRulesPanel::GetSelectedRule(this);
  pRule = (CDmeCombinationDominationRule *)SelectedRule;
  if ( SelectedRule != nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "OnSelectSuppressed");
    else
      v4 = nullptr;
    BufferType = CCodecBuffer_Block::GetBufferType(this: SelectedRule);
    KeyValues::SetInt(this: v4, keyName: "rule", value: BufferType);
    v6 = (CRawControlPickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
    if ( v6 != nullptr )
      v7 = CRawControlPickerFrame::CRawControlPickerFrame(this: v6, pParent: this, pTitle: "Select Suppressed");
    else
      v7 = nullptr;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hCombinationOperator.m_handle);
    if ( v8 != 0 )
      v9 = (CDmeCombinationOperator *)(v8 - 4);
    else
      v9 = nullptr;
    m_pContextKeyValues = v7->m_pContextKeyValues;
    if ( m_pContextKeyValues != nullptr )
    {
      KeyValues::deleteThis(this: m_pContextKeyValues);
      v7->m_pContextKeyValues = nullptr;
    }
    CRawControlPickerFrame::RefreshRawControlNames(this: v7, pCombinationOperator: v9, pRule, bChooseSuppressed: true);
    v7->m_pContextKeyValues = v4;
    vgui::Frame::DoModal(this: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046F9C0
// Name: public: void CDmeCombinationControlsPanel::SetCombinationOperator(class CDmeCombinationOperator __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeCombinationControlsPanel::SetCombinationOperator(
        CDmeCombinationControlsPanel *this@<ecx>,
        int a2@<ebx>,
        CDmeCombinationOperator *pOp)
{
  int v4; // eax
  CDmeCombinationOperator *v5; // ecx
  CDmElement *v6; // ecx
  DmElementHandle_t BufferType; // eax

  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  if ( v4 != 0 )
    v5 = (CDmeCombinationOperator *)(v4 - 4);
  else
    v5 = nullptr;
  if ( pOp != v5 )
  {
    if ( pOp != nullptr )
      v6 = &pOp->CDmElement;
    else
      v6 = nullptr;
    if ( v6 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v6);
    else
      BufferType = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmeCombinationOperator,0>::Set(this: &this->m_hCombinationOperator, h: BufferType);
    CDmeCombinationControlsPanel::RefreshCombinationOperator(this, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FA20
// Name: public: static void CDmeCombinationSystemEditorPanel::PanelMessageFunc_OnPageChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationSystemEditorPanel::PanelMessageFunc_OnPageChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationSystemEditorPanel::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationSystemEditorPanel::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationSystemEditorPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FAB0
// Name: public: static void CDmeCombinationSystemEditorPanel::PanelMessageFunc_OnDmeElementChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationSystemEditorPanel::PanelMessageFunc_OnDmeElementChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationSystemEditorPanel::PanelMessageFunc_OnDmeElementChanged::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationSystemEditorPanel::PanelMessageFunc_OnDmeElementChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationSystemEditorPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "DmeElementChanged";
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
// Address: 0x0046FB40
// Name: public: static void CDmeCombinationSystemEditorFrame::PanelMessageFunc_OnDmeElementChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationSystemEditorFrame::PanelMessageFunc_OnDmeElementChanged::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationSystemEditorFrame::PanelMessageFunc_OnDmeElementChanged::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationSystemEditorFrame::PanelMessageFunc_OnDmeElementChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationSystemEditorFrame");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "DmeElementChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FBD0
// Name: public: static void CDmeRawControlListPanel::PanelMessageFunc_OnNewWrinkleText::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeRawControlListPanel::PanelMessageFunc_OnNewWrinkleText::InitVar(int a1@<ebp>)
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
  if ( !`CDmeRawControlListPanel::PanelMessageFunc_OnNewWrinkleText::InitVar'::`2'::bAdded )
  {
    `CDmeRawControlListPanel::PanelMessageFunc_OnNewWrinkleText::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeRawControlListPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TextNewLine";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FC60
// Name: public: static void CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveUpInputControl::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveUpInputControl::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveUpInputControl::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveUpInputControl::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationControlsPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MoveUpInputControl";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FCF0
// Name: public: static void CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveDownInputControl::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveDownInputControl::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveDownInputControl::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveDownInputControl::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationControlsPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MoveDownInputControl";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FD80
// Name: public: static void CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveUp::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveUp::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveUp::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveUp::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationControlsPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MoveUp";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FE10
// Name: public: static void CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveDown::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveDown::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveDown::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveDown::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationControlsPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MoveDown";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046FEA0
// Name: public: static void CDmeCombinationControlsPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationControlsPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationControlsPanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationControlsPanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationControlsPanel");
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
// Address: 0x0046FF30
// Name: public: static void CDmeCombinationControlsPanel::PanelMessageFunc_OnInputCompleted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationControlsPanel::PanelMessageFunc_OnInputCompleted::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationControlsPanel::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationControlsPanel::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationControlsPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "InputCompleted";
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
// Address: 0x0046FFC0
// Name: public: static void CDmeCombinationControlsPanel::PanelMessageFunc_OnGroupControls::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationControlsPanel::PanelMessageFunc_OnGroupControls::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationControlsPanel::PanelMessageFunc_OnGroupControls::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationControlsPanel::PanelMessageFunc_OnGroupControls::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationControlsPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "GroupControls";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470050
// Name: public: static void CDmeCombinationControlsPanel::PanelMessageFunc_OnUngroupControls::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationControlsPanel::PanelMessageFunc_OnUngroupControls::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationControlsPanel::PanelMessageFunc_OnUngroupControls::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationControlsPanel::PanelMessageFunc_OnUngroupControls::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationControlsPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "UngroupControls";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004700E0
// Name: public: static void CDmeCombinationControlsPanel::PanelMessageFunc_OnRenameControl::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationControlsPanel::PanelMessageFunc_OnRenameControl::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationControlsPanel::PanelMessageFunc_OnRenameControl::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationControlsPanel::PanelMessageFunc_OnRenameControl::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationControlsPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RenameControl";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470170
// Name: public: static void CDmeCombinationControlsPanel::PanelMessageFunc_OnImportCombination::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationControlsPanel::PanelMessageFunc_OnImportCombination::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationControlsPanel::PanelMessageFunc_OnImportCombination::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationControlsPanel::PanelMessageFunc_OnImportCombination::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAssetBuilder::`vcall'{980,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationControlsPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ImportCombination";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470200
// Name: public: static void CDmeCombinationControlsPanel::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationControlsPanel::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationControlsPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationControlsPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{984,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationControlsPanel");
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
// Address: 0x00470290
// Name: public: static void CDmeCombinationControlsPanel::PanelMessageFunc_OnToggleStereoControl::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationControlsPanel::PanelMessageFunc_OnToggleStereoControl::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationControlsPanel::PanelMessageFunc_OnToggleStereoControl::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationControlsPanel::PanelMessageFunc_OnToggleStereoControl::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{988,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationControlsPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ToggleStereoControl";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470320
// Name: public: static void CDmeCombinationControlsPanel::PanelMessageFunc_OnToggleEyelidControl::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationControlsPanel::PanelMessageFunc_OnToggleEyelidControl::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationControlsPanel::PanelMessageFunc_OnToggleEyelidControl::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationControlsPanel::PanelMessageFunc_OnToggleEyelidControl::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{992,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationControlsPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ToggleEyelidControl";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004703B0
// Name: public: static void CDmeCombinationControlsPanel::PanelMessageFunc_OnToggleWrinkleType::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationControlsPanel::PanelMessageFunc_OnToggleWrinkleType::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationControlsPanel::PanelMessageFunc_OnToggleWrinkleType::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationControlsPanel::PanelMessageFunc_OnToggleWrinkleType::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationControlsPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ToggleWrinkleType";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470440
// Name: public: static void CDmeCombinationControlsPanel::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationControlsPanel::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationControlsPanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationControlsPanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1000,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationControlsPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ItemSelected";
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
// Address: 0x004704D0
// Name: public: static void CDmeCombinationControlsPanel::PanelMessageFunc_OnItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationControlsPanel::PanelMessageFunc_OnItemDeselected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationControlsPanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationControlsPanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1004,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationControlsPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ItemDeselected";
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
// Address: 0x00470560
// Name: private: void CDmeCombinationControlsPanel::BuildSelectedControlLists(bool,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &,bool __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeCombinationControlsPanel::BuildSelectedControlLists(
        CDmeCombinationControlsPanel *this@<ecx>,
        DmElementHandle_t m_handle@<edi>,
        bool bOnlyGroupedControls,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *controlNames,
        CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *rawControlNames,
        bool *pbStereo,
        bool *pbEyelid)
{
  CDmeCombinationControlsPanel *v7; // ebx
  CDmeInputControlListPanel *m_pControlList; // ecx
  int (__thiscall *GetSelectedItemsCount)(vgui::ListPanel *); // edx
  int v11; // eax
  KeyValues *v12; // eax
  const char *v13; // esi
  int v14; // eax
  CDmeCombinationOperator *v15; // ecx
  int v16; // eax
  CDmeCombinationOperator *v17; // ecx
  int RawControlCount; // eax
  int v19; // eax
  CDmeCombinationOperator *v20; // ecx
  int v21; // eax
  CDmeCombinationOperator *v22; // ecx
  int m_Size; // esi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v26; // eax
  CUtlString *v27; // ecx
  int v28; // ebx
  int v29; // eax
  CDmeCombinationOperator *v30; // ecx
  const char *RawControlName; // eax
  int v32; // esi
  int v33; // eax
  CUtlString *v34; // ecx
  int v35; // eax
  CUtlString *v36; // ecx
  CUtlString v38; // [esp+4h] [ebp-34h] BYREF
  CUtlString string; // [esp+14h] [ebp-24h] BYREF
  int nSelectedItemCount; // [esp+24h] [ebp-14h]
  int nRawControlCount; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]
  CDmeCombinationControlsPanel *v43; // [esp+30h] [ebp-8h]
  bool bIsEyelid; // [esp+36h] [ebp-2h]
  bool bIsStereo; // [esp+37h] [ebp-1h]
  int nControlIndex; // [esp+48h] [ebp+10h]

  v7 = this;
  m_pControlList = this->m_pControlList;
  GetSelectedItemsCount = m_pControlList->GetSelectedItemsCount;
  v43 = v7;
  bIsStereo = false;
  bIsEyelid = false;
  nSelectedItemCount = GetSelectedItemsCount(this: m_pControlList);
  for ( i = 0; i < nSelectedItemCount; ++i )
  {
    v11 = v7->m_pControlList->GetSelectedItem(this: v7->m_pControlList, a2: i);
    v12 = v7->m_pControlList->GetItem(this: v7->m_pControlList, a2: v11);
    v13 = KeyValues::GetString(this: v12, keyName: "name", defaultValue: defaultValue);
    v14 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 72))(
            a1: g_pDataModel.u,
            a2: v7->m_hCombinationOperator.m_handle);
    if ( v14 != 0 )
      v15 = (CDmeCombinationOperator *)(v14 - 4);
    else
      v15 = nullptr;
    nControlIndex = CDmeCombinationOperator::FindControlIndex(this: v15, pControlName: v13);
    if ( nControlIndex >= 0 )
    {
      v16 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: v7->m_hCombinationOperator.m_handle);
      v17 = v16 != 0 ? (CDmeCombinationOperator *)(v16 - 4) : nullptr;
      RawControlCount = CDmeCombinationOperator::GetRawControlCount(this: v17, nControl: nControlIndex);
      nRawControlCount = RawControlCount;
      if ( !bOnlyGroupedControls || RawControlCount > 1 )
      {
        v19 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                a1: g_pDataModel.u,
                a2: v7->m_hCombinationOperator.m_handle,
                a3: m_handle);
        if ( v19 != 0 )
          v20 = (CDmeCombinationOperator *)(v19 - 4);
        else
          v20 = nullptr;
        if ( CDmeCombinationOperator::IsStereoControl(this: v20, nControlIndex) )
          bIsStereo = true;
        m_handle = v7->m_hCombinationOperator.m_handle;
        v21 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(a1: g_pDataModel.u);
        if ( v21 != 0 )
          v22 = (CDmeCombinationOperator *)(v21 - 4);
        else
          v22 = nullptr;
        if ( CDmeCombinationOperator::IsEyelidControl(this: v22, nControlIndex) )
          bIsEyelid = true;
        CUtlString::CUtlString(this: &string, pString: v13);
        m_Size = controlNames->m_Size;
        m_nAllocationCount = controlNames->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(
            this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)controlNames,
            num: m_Size - m_nAllocationCount + 1);
        ++controlNames->m_Size;
        m_pMemory = controlNames->m_Memory.m_pMemory;
        v26 = controlNames->m_Size - m_Size - 1;
        controlNames->m_pElements = controlNames->m_Memory.m_pMemory;
        if ( v26 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v26);
        v27 = &controlNames->m_Memory.m_pMemory[m_Size];
        if ( v27 != nullptr )
          CUtlString::CUtlString(this: v27, &string);
        v28 = 0;
        string.m_Storage.m_nActualLength = 0;
        if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
            string.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v28 = 0;
          string.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        if ( nRawControlCount > 0 )
        {
          do
          {
            v29 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 72))(
                    a1: g_pDataModel.u,
                    a2: v43->m_hCombinationOperator.m_handle);
            if ( v29 != 0 )
              v30 = (CDmeCombinationOperator *)(v29 - 4);
            else
              v30 = nullptr;
            RawControlName = CDmeCombinationOperator::GetRawControlName(this: v30, nControl: nControlIndex, nIndex: v28);
            CUtlString::CUtlString(this: &v38, pString: RawControlName);
            v32 = (int)rawControlNames[1].m_pMemory;
            v33 = rawControlNames->m_nAllocationCount;
            if ( v32 + 1 > v33 )
              CUtlMemory<ActiveLayer_t<QAngle>,int>::Grow(this: rawControlNames, num: v32 - v33 + 1);
            ++rawControlNames[1].m_pMemory;
            v34 = (CUtlString *)rawControlNames->m_pMemory;
            v35 = (int)rawControlNames[1].m_pMemory - v32 - 1;
            rawControlNames[1].m_nAllocationCount = (int)rawControlNames->m_pMemory;
            if ( v35 > 0 )
              _V_memmove(dest: &v34[v32 + 1], src: &v34[v32], count: 16 * v35);
            v36 = (CUtlString *)&rawControlNames->m_pMemory[v32];
            if ( v36 != nullptr )
              CUtlString::CUtlString(this: v36, string: &v38);
            v38.m_Storage.m_nActualLength = 0;
            if ( v38.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( v38.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v38.m_Storage.m_Memory.m_pMemory);
                v38.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              v38.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
            ++v28;
          }
          while ( v28 < nRawControlCount );
        }
        v7 = v43;
      }
    }
  }
  if ( pbStereo != nullptr )
    *pbStereo = bIsStereo;
  if ( pbEyelid != nullptr )
    *pbEyelid = bIsEyelid;
}

//------------------------------------------------------------------------------
// Address: 0x00470840
// Name: public: CDmeRawControlListPanel::CDmeRawControlListPanel(class vgui::Panel __near *,char const __near *,class CDmeCombinationControlsPanel __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeRawControlListPanel *__thiscall CDmeRawControlListPanel::CDmeRawControlListPanel(
        CDmeRawControlListPanel *this,
        vgui::Panel *pParent,
        const char *pName,
        CDmeCombinationControlsPanel *pComboPanel)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::TextEntry *v8; // eax
  vgui::TextEntry *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::ListPanel::ListPanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CDmeRawControlListPanel_vtbl *)&CDmeRawControlListPanel::`vftable';
  if ( `CDmeRawControlListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeRawControlListPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CDmeRawControlListPanel");
    v5->pfnClassName = CDmeRawControlListPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::ListPanel");
  }
  if ( `CDmeRawControlListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeRawControlListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CDmeRawControlListPanel");
    v6->pfnClassName = CDmeRawControlListPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::ListPanel");
  }
  if ( `CDmeRawControlListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeRawControlListPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeRawControlListPanel");
    v7->pfnClassName = CDmeRawControlListPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::ListPanel");
  }
  CDmeRawControlListPanel::PanelMessageFunc_OnNewWrinkleText::InitVar(a1: (int)&savedregs);
  this->m_pComboPanel = pComboPanel;
  v8 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v8 != nullptr )
    v9 = vgui::TextEntry::TextEntry(this: v8, parent: this, panelName: "WrinkleEdit");
  else
    v9 = nullptr;
  this->m_pWrinkleEdit = v9;
  v9->SetVisible(this: v9, a2: false);
  this->m_pWrinkleEdit->AddActionSignalTarget_2(this: this->m_pWrinkleEdit, a2: this);
  vgui::TextEntry::SetAllowNumericInputOnly(this: this->m_pWrinkleEdit, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00470960
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeRawControlListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeRawControlListPanel::GetMessageMap(CDmeRawControlListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeRawControlListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeRawControlListPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeRawControlListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeRawControlListPanel");
  `CDmeRawControlListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470990
// Name: public: virtual struct PanelAnimationMap __near * CDmeRawControlListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeRawControlListPanel::GetAnimMap(CDmeRawControlListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeRawControlListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004709A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeRawControlListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeRawControlListPanel::GetKBMap(CDmeRawControlListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeRawControlListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeRawControlListPanel::GetKBMap'::`2'::s_pMap;
  `CDmeRawControlListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeRawControlListPanel");
  `CDmeRawControlListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00470A00
// Name: public: static void CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationDominationRulesPanel");
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
// Address: 0x00470A90
// Name: public: static void CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnRawControlPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnRawControlPicked::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnRawControlPicked::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnRawControlPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationDominationRulesPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "RawControlPicked";
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
// Address: 0x00470B20
// Name: public: static void CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnAddDominationRule::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnAddDominationRule::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnAddDominationRule::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnAddDominationRule::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationDominationRulesPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "AddDominationRule";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470BB0
// Name: public: static void CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnRemoveDominationRule::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnRemoveDominationRule::InitVar(
        int a1@<ebp>)
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
  if ( !`CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnRemoveDominationRule::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnRemoveDominationRule::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationDominationRulesPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "RemoveDominationRule";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470C40
// Name: public: static void CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnDuplicateSuppressed::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnDuplicateSuppressed::InitVar(
        int a1@<ebp>)
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
  if ( !`CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnDuplicateSuppressed::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnDuplicateSuppressed::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationDominationRulesPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "DuplicateSuppressed";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470CD0
// Name: public: static void CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnDuplicateDominators::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnDuplicateDominators::InitVar(
        int a1@<ebp>)
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
  if ( !`CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnDuplicateDominators::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnDuplicateDominators::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationDominationRulesPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "DuplicateDominators";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470D60
// Name: public: static void CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnSelectDominators::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnSelectDominators::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnSelectDominators::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnSelectDominators::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationDominationRulesPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "SelectDominators";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470DF0
// Name: public: static void CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnSelectSuppressed::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnSelectSuppressed::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnSelectSuppressed::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnSelectSuppressed::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationDominationRulesPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "SelectSuppressed";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470E80
// Name: public: static void CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnMoveUp::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnMoveUp::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnMoveUp::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnMoveUp::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{976,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationDominationRulesPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MoveUp";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470F10
// Name: public: static void CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnMoveDown::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnMoveDown::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnMoveDown::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnMoveDown::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAssetBuilder::`vcall'{980,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationDominationRulesPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "MoveDown";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470FA0
// Name: public: static void CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnImportDominationRules::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnImportDominationRules::InitVar(
        int a1@<ebp>)
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
  if ( !`CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnImportDominationRules::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnImportDominationRules::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{984,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationDominationRulesPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ImportDominationRules";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471030
// Name: public: static void CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePresetGroupEditorPanel::`vcall'{988,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationDominationRulesPanel");
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
// Address: 0x004710C0
// Name: public: CDmeCombinationDominationRulesPanel::CDmeCombinationDominationRulesPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeCombinationDominationRulesPanel *__thiscall CDmeCombinationDominationRulesPanel::CDmeCombinationDominationRulesPanel(
        CDmeCombinationDominationRulesPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ListPanel *v7; // eax
  vgui::ListPanel *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CDmeCombinationDominationRulesPanel_vtbl *)&CDmeCombinationDominationRulesPanel::`vftable';
  if ( `CDmeCombinationDominationRulesPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeCombinationDominationRulesPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationDominationRulesPanel");
    v4->pfnClassName = CDmeCombinationDominationRulesPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CDmeCombinationDominationRulesPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeCombinationDominationRulesPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeCombinationDominationRulesPanel");
    v5->pfnClassName = CDmeCombinationDominationRulesPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CDmeCombinationDominationRulesPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeCombinationDominationRulesPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeCombinationDominationRulesPanel");
    v6->pfnClassName = CDmeCombinationDominationRulesPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnRawControlPicked::InitVar(a1: (int)&savedregs);
  CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnAddDominationRule::InitVar(a1: (int)&savedregs);
  CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnRemoveDominationRule::InitVar(a1: (int)&savedregs);
  CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnDuplicateSuppressed::InitVar(a1: (int)&savedregs);
  CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnDuplicateDominators::InitVar(a1: (int)&savedregs);
  CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnSelectDominators::InitVar(a1: (int)&savedregs);
  CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnSelectSuppressed::InitVar(a1: (int)&savedregs);
  CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnMoveUp::InitVar(a1: (int)&savedregs);
  CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnMoveDown::InitVar(a1: (int)&savedregs);
  CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnImportDominationRules::InitVar(a1: (int)&savedregs);
  CDmeCombinationDominationRulesPanel::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  this->m_hCombinationOperator.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hContextMenu.m_iPanelID = -1;
  v7 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v7 != nullptr )
    v8 = vgui::ListPanel::ListPanel(this: v7, parent: this, panelName: "DominationRulesList");
  else
    v8 = nullptr;
  this->m_pDominationRulesList = v8;
  v8->AddColumnHeader(this: v8, a2: 0, a3: "dominator", a4: "Dominate", a5: 100, a6: 0);
  this->m_pDominationRulesList->AddColumnHeader(
    this: this->m_pDominationRulesList,
    a2: 1,
    a3: "suppressed",
    a4: "Suppress",
    a5: 100,
    a6: 0);
  this->m_pDominationRulesList->AddActionSignalTarget_2(this: this->m_pDominationRulesList, a2: this);
  this->m_pDominationRulesList->SetSortFunc(this: this->m_pDominationRulesList, a2: 0, a3: IndexSortFunc);
  this->m_pDominationRulesList->SetSortFunc(this: this->m_pDominationRulesList, a2: 1, a3: IndexSortFunc);
  this->m_pDominationRulesList->SetSortColumn(this: this->m_pDominationRulesList, a2: 0);
  this->m_pDominationRulesList->SetEmptyListText_2(this: this->m_pDominationRulesList, a2: "No domination rules.");
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pDominationRulesList, bState: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004712A0
// Name: ImportCombinationControls
// Source: json
//------------------------------------------------------------------------------
void __cdecl ImportCombinationControls(
        CDmeCombinationOperator *pDestComboOp,
        CDmeCombinationOperator *pSrcComboOp,
        COperationFileListFrame *pStatusFrame)
{
  int v3; // edi
  int RawControlCount; // eax
  int m_Size; // ecx
  int v6; // esi
  int v7; // ecx
  int v8; // esi
  const char *RawControlName; // eax
  bool DoesTargetContainDeltaState; // al
  const char *v11; // eax
  const char *v12; // esi
  int v13; // esi
  bool *m_pMemory; // eax
  CUtlVectorFixedGrowable<bool,256> foundMatch; // [esp+10h] [ebp-134h] BYREF
  BOOL bIsEyelid; // [esp+128h] [ebp-1Ch]
  int nCount; // [esp+12Ch] [ebp-18h]
  BOOL bIsStereo; // [esp+130h] [ebp-14h]
  int nRawControls; // [esp+134h] [ebp-10h]
  const char *pRawControl; // [esp+138h] [ebp-Ch]
  float flWrinkleScale; // [esp+13Ch] [ebp-8h]
  int index; // [esp+140h] [ebp-4h]

  CDmeCombinationOperator::RemoveAllControls(this: pDestComboOp);
  v3 = 0;
  foundMatch.m_pElements = foundMatch.m_Memory.m_pFixedMemory;
  foundMatch.m_Memory.m_pMemory = foundMatch.m_Memory.m_pFixedMemory;
  foundMatch.m_Memory.m_nAllocationCount = 256;
  foundMatch.m_Memory.m_nGrowSize = -1;
  foundMatch.m_Memory.m_nMallocGrowSize = 0;
  foundMatch.m_Size = 0;
  nCount = CDmeMaterialGroup::GetListAttr(this: pSrcComboOp);
  if ( nCount > 0 )
  {
    do
    {
      pRawControl = CDmeCombinationOperator::GetControlName(this: pSrcComboOp, i: v3);
      RawControlCount = CDmeCombinationOperator::GetRawControlCount(this: pSrcComboOp, nControl: v3);
      m_Size = foundMatch.m_Size;
      nRawControls = RawControlCount;
      index = 0;
      if ( foundMatch.m_Size < RawControlCount )
      {
        v6 = RawControlCount - foundMatch.m_Size;
        flWrinkleScale = *(float *)&foundMatch.m_Size;
        if ( RawControlCount != foundMatch.m_Size )
        {
          if ( RawControlCount > foundMatch.m_Memory.m_nAllocationCount )
          {
            CUtlMemoryFixedGrowable<bool,256,int>::Grow(
              this: &foundMatch.m_Memory,
              nCount: RawControlCount - foundMatch.m_Memory.m_nAllocationCount);
            m_Size = foundMatch.m_Size;
          }
          foundMatch.m_Size = v6 + m_Size;
          v7 = m_Size - LODWORD(flWrinkleScale);
          foundMatch.m_pElements = foundMatch.m_Memory.m_pMemory;
          if ( v7 > 0 && v6 > 0 )
            _V_memmove(
              dest: &foundMatch.m_Memory.m_pMemory[LODWORD(flWrinkleScale) + v6],
              src: &foundMatch.m_Memory.m_pMemory[LODWORD(flWrinkleScale)],
              count: v7);
          RawControlCount = nRawControls;
        }
      }
      v8 = 0;
      if ( RawControlCount <= 0 )
        goto LABEL_13;
      do
      {
        RawControlName = CDmeCombinationOperator::GetRawControlName(this: pSrcComboOp, nControl: v3, nIndex: v8);
        LODWORD(flWrinkleScale) = &foundMatch.m_Memory.m_pMemory[v8];
        DoesTargetContainDeltaState = CDmeCombinationOperator::DoesTargetContainDeltaState(
                                        this: pDestComboOp,
                                        pSearchName: RawControlName);
        *(_BYTE *)LODWORD(flWrinkleScale) = DoesTargetContainDeltaState;
        index += foundMatch.m_Memory.m_pMemory[v8++];
      }
      while ( v8 < nRawControls );
      if ( index != 0 )
      {
        v11 = "Partial rule match";
        if ( index == nRawControls )
          v11 = "Successful";
        v12 = pRawControl;
        COperationFileListFrame::AddOperation(this: pStatusFrame, pOperation: pRawControl, pFileName: v11);
        LOBYTE(bIsStereo) = CDmeCombinationOperator::IsStereoControl(this: pSrcComboOp, nControlIndex: v3);
        LOBYTE(bIsEyelid) = CDmeCombinationOperator::IsEyelidControl(this: pSrcComboOp, nControlIndex: v3);
        index = CDmeCombinationOperator::FindOrCreateControl(
                  this: pDestComboOp,
                  pControlName: v12,
                  bStereo: bIsStereo,
                  bAutoAddRawControl: false);
        CDmeCombinationOperator::SetEyelidControl(this: pDestComboOp, nControlIndex: index, bIsEyelid);
        v13 = 0;
        do
        {
          if ( foundMatch.m_Memory.m_pMemory[v13] )
          {
            pRawControl = CDmeCombinationOperator::GetRawControlName(this: pSrcComboOp, nControl: v3, nIndex: v13);
            flWrinkleScale = CDmeCombinationOperator::GetRawControlWrinkleScale(
                               this: pSrcComboOp,
                               nControl: v3,
                               nIndex: v13);
            CDmeCombinationOperator::AddRawControl(this: pDestComboOp, nControl: index, pRawControlName: pRawControl);
            CDmeCombinationOperator::SetWrinkleScale(
              this: pDestComboOp,
              nControl: index,
              pRawControlName: pRawControl,
              flWrinkleScale);
          }
          ++v13;
        }
        while ( v13 < nRawControls );
      }
      else
      {
LABEL_13:
        COperationFileListFrame::AddOperation(
          this: pStatusFrame,
          pOperation: pRawControl,
          pFileName: "No raw controls found!");
      }
      ++v3;
    }
    while ( v3 < nCount );
  }
  m_pMemory = foundMatch.m_Memory.m_pMemory;
  foundMatch.m_Size = 0;
  if ( foundMatch.m_Memory.m_nGrowSize >= 0 )
  {
    if ( foundMatch.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: foundMatch.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      foundMatch.m_Memory.m_pMemory = nullptr;
    }
    foundMatch.m_Memory.m_nAllocationCount = 0;
  }
  foundMatch.m_pElements = m_pMemory;
  if ( foundMatch.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004714F0
// Name: ImportCombinationData
// Source: json
//------------------------------------------------------------------------------
char __cdecl ImportCombinationData(vgui::Panel *pParent, CDmeCombinationOperator *pDestComboOp, KeyValues *kv)
{
  const char *String; // esi
  unsigned __int8 (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  CDmElement *v6; // esi
  CDmeCombinationOperator *Value; // edi
  COperationFileListFrame *v8; // eax
  COperationFileListFrame *v9; // esi
  void (__thiscall *v10)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD); // eax
  int (__thiscall *v11)(CUtlSymbolLarge::<unnamed_type_u>); // eax
  char v12; // al
  int v13; // edx
  CUndoScopeGuard sg; // [esp+Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+14h] [ebp-4h] BYREF

  String = KeyValues::GetString(this: kv, keyName: "fullpath", defaultValue: nullptr);
  if ( String == nullptr )
    return 0;
  v5 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
  *(&sg.m_bNotify + 1) = false;
  sg.m_pNotify = nullptr;
  *(_WORD *)&sg.m_bReleased = ((int (__thiscall *)(_DWORD))v5)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, _DWORD, _DWORD, CDmElement **, int, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 188))(
    a1: g_pDataModel.u,
    a2: String,
    a3: 0,
    a4: 0,
    a5: &pRoot,
    a6: 3,
    a7: 0);
  CChangeUndoScopeGuard::Release(this: (CChangeUndoScopeGuard *)&sg);
  v6 = pRoot;
  if ( pRoot == nullptr )
    return 0;
  if ( ((int (__thiscall *)(_DWORD, _DWORD))pRoot->IsA)(
         a1: pRoot,
         a2: (CUtlSymbolLarge)CDmeCombinationOperator::m_classType.u.m_Id)
    && (Value = (CDmeCombinationOperator *)((char *)&v6[-1] + 64), v6 != (CDmElement *)4)
    || (Value = CDmElement::GetValueElement<CDmeCombinationOperator>(this: pRoot, pAttributeName: "combinationOperator")) != nullptr )
  {
    v8 = (COperationFileListFrame *)MemAlloc_Alloc(nSize: 0x240u);
    if ( v8 != nullptr )
      v9 = COperationFileListFrame::COperationFileListFrame(
             this: v8,
             pParent,
             pTitle: "Import Status",
             pColumnHeader: "Status",
             bShowDescription: false,
             bShowOkOnly: true,
             nDialogID: 1);
    else
      v9 = nullptr;
    COperationFileListFrame::SetOperationColumnHeaderText(this: v9, pText: "Control Name");
    v10 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 256);
    *(_WORD *)&sg.m_bReleased = 0;
    sg.m_pNotify = nullptr;
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))v10)(
      a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
      a2: "Import Combination Rules",
      a3: "Import Combination Rules",
      a4: 0);
    if ( KeyValues::FindKey(this: kv, keyName: "ImportControls", bCreate: false) != nullptr )
      ImportCombinationControls(pDestComboOp, pSrcComboOp: Value, pStatusFrame: v9);
    ImportDominationRules(pDestComboOp, pSrcComboOp: Value, pStatusFrame: v9);
    CUndoScopeGuard::Release(this: &sg);
    COperationFileListFrame::DoModal(this: v9, pContextKeyValues: nullptr, pMessage: nullptr);
    if ( !sg.m_bReleased )
    {
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
      if ( sg.m_bNotify )
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
          a1: g_pDataModel.u,
          a2: 0);
      if ( sg.m_pNotify != nullptr )
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
          a1: g_pDataModel.u,
          a2: sg.m_pNotify);
    }
  }
  v11 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
  *(_WORD *)&sg.m_bNotify = 0;
  sg.m_pNotify = nullptr;
  v12 = ((int (__thiscall *)(_DWORD))v11)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
  v13 = *(_DWORD *)g_pDataModel.u.m_Id;
  sg.m_bReleased = v12;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(v13 + 232))(a1: g_pDataModel.u, a2: 0);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id + 408))(
    a1: g_pDataModel.u,
    a2: pRoot->m_fileId);
  CChangeUndoScopeGuard::Release(this: (CChangeUndoScopeGuard *)&sg);
  CChangeUndoScopeGuard::Release(this: (CChangeUndoScopeGuard *)&sg);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004716E0
// Name: public: CDmeCombinationControlsPanel::CDmeCombinationControlsPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeCombinationControlsPanel *__thiscall CDmeCombinationControlsPanel::CDmeCombinationControlsPanel(
        CDmeCombinationControlsPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Splitter *v7; // eax
  vgui::Splitter *v8; // eax
  vgui::Panel *Child; // edi
  vgui::Panel *v10; // ebx
  CDmeInputControlListPanel *v11; // eax
  CDmeInputControlListPanel *v12; // eax
  CDmeRawControlListPanel *v13; // eax
  CDmeRawControlListPanel *v14; // eax
  int savedregs; // [esp+D4h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CDmeCombinationControlsPanel_vtbl *)&CDmeCombinationControlsPanel::`vftable';
  if ( `CDmeCombinationControlsPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeCombinationControlsPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationControlsPanel");
    v4->pfnClassName = CDmeCombinationControlsPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CDmeCombinationControlsPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeCombinationControlsPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeCombinationControlsPanel");
    v5->pfnClassName = CDmeCombinationControlsPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CDmeCombinationControlsPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeCombinationControlsPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeCombinationControlsPanel");
    v6->pfnClassName = CDmeCombinationControlsPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveUpInputControl::InitVar(a1: (int)&savedregs);
  CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveDownInputControl::InitVar(a1: (int)&savedregs);
  CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveUp::InitVar(a1: (int)&savedregs);
  CDmeCombinationControlsPanel::PanelMessageFunc_OnMoveDown::InitVar(a1: (int)&savedregs);
  CDmeCombinationControlsPanel::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  CDmeCombinationControlsPanel::PanelMessageFunc_OnInputCompleted::InitVar(a1: (int)&savedregs);
  CDmeCombinationControlsPanel::PanelMessageFunc_OnGroupControls::InitVar(a1: (int)&savedregs);
  CDmeCombinationControlsPanel::PanelMessageFunc_OnUngroupControls::InitVar(a1: (int)&savedregs);
  CDmeCombinationControlsPanel::PanelMessageFunc_OnRenameControl::InitVar(a1: (int)&savedregs);
  CDmeCombinationControlsPanel::PanelMessageFunc_OnImportCombination::InitVar(a1: (int)&savedregs);
  CDmeCombinationControlsPanel::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  CDmeCombinationControlsPanel::PanelMessageFunc_OnToggleStereoControl::InitVar(a1: (int)&savedregs);
  CDmeCombinationControlsPanel::PanelMessageFunc_OnToggleEyelidControl::InitVar(a1: (int)&savedregs);
  CDmeCombinationControlsPanel::PanelMessageFunc_OnToggleWrinkleType::InitVar(a1: (int)&savedregs);
  CDmeCombinationControlsPanel::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CDmeCombinationControlsPanel::PanelMessageFunc_OnItemDeselected::InitVar(a1: (int)&savedregs);
  this->m_hCombinationOperator.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_hContextMenu.m_iPanelID = -1;
  v7 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v7 != nullptr )
    v8 = vgui::Splitter::Splitter(
           this: v7,
           parent: this,
           name: "ControlsSplitter",
           mode: SPLITTER_MODE_VERTICAL,
           nCount: 1);
  else
    v8 = nullptr;
  this->m_pSplitter = v8;
  Child = vgui::Panel::GetChild(this: v8, index: 0);
  v10 = vgui::Panel::GetChild(this: this->m_pSplitter, index: 1);
  v11 = (CDmeInputControlListPanel *)MemAlloc_Alloc(nSize: 0x254u);
  if ( v11 != nullptr )
    v12 = CDmeInputControlListPanel::CDmeInputControlListPanel(
            this: v11,
            pParent: Child,
            pName: "ControlList",
            pComboPanel: this);
  else
    v12 = nullptr;
  this->m_pControlList = v12;
  v12->AddColumnHeader_2(this: v12, a2: 0, a3: "name", a4: "Control Name", a5: 60, a6: 60, a7: 1000, a8: 2);
  this->m_pControlList->AddColumnHeader_2(
    this: this->m_pControlList,
    a2: 1,
    a3: "stereo",
    a4: "Stereo",
    a5: 35,
    a6: 35,
    a7: 35,
    a8: 0);
  this->m_pControlList->AddColumnHeader_2(
    this: this->m_pControlList,
    a2: 2,
    a3: "eyelid",
    a4: "Eyelid",
    a5: 32,
    a6: 32,
    a7: 32,
    a8: 0);
  this->m_pControlList->AddColumnHeader_2(
    this: this->m_pControlList,
    a2: 3,
    a3: "default",
    a4: "Default",
    a5: 65,
    a6: 65,
    a7: 65,
    a8: 0);
  this->m_pControlList->SetSelectIndividualCells(this: this->m_pControlList, a2: false);
  vgui::ListPanel::SetMultiselectEnabled(this: this->m_pControlList, bState: true);
  this->m_pControlList->SetEmptyListText_2(this: this->m_pControlList, a2: "No controls");
  this->m_pControlList->AddActionSignalTarget_2(this: this->m_pControlList, a2: this);
  this->m_pControlList->SetSortFunc(this: this->m_pControlList, a2: 0, a3: nullptr);
  this->m_pControlList->SetColumnSortable(this: this->m_pControlList, a2: 0, a3: false);
  this->m_pControlList->SetSortFunc(this: this->m_pControlList, a2: 1, a3: nullptr);
  this->m_pControlList->SetColumnSortable(this: this->m_pControlList, a2: 1, a3: false);
  this->m_pControlList->SetSortFunc(this: this->m_pControlList, a2: 2, a3: nullptr);
  this->m_pControlList->SetColumnSortable(this: this->m_pControlList, a2: 2, a3: false);
  this->m_pControlList->SetSortFunc(this: this->m_pControlList, a2: 3, a3: nullptr);
  this->m_pControlList->SetColumnSortable(this: this->m_pControlList, a2: 3, a3: false);
  this->m_pControlList->SetDragEnabled(this: this->m_pControlList, a2: true);
  this->m_pControlList->SetDragEnabled(this: this->m_pControlList, a2: true);
  ((void (__stdcall *)(int, _DWORD))this->m_pControlList->SetDropEnabled)(a1: 1, a2: 0);
  v13 = (CDmeRawControlListPanel *)MemAlloc_Alloc(nSize: 0x25Cu);
  if ( v13 != nullptr )
    v14 = CDmeRawControlListPanel::CDmeRawControlListPanel(
            this: v13,
            pParent: v10,
            pName: "RawControlList",
            pComboPanel: this);
  else
    v14 = nullptr;
  this->m_pRawControlList = v14;
  v14->AddColumnHeader_2(this: v14, a2: 0, a3: "name", a4: "Raw Control Name", a5: 75, a6: 75, a7: 1000, a8: 2);
  this->m_pRawControlList->AddColumnHeader_2(
    this: this->m_pRawControlList,
    a2: 1,
    a3: "wrinkletype",
    a4: "Type",
    a5: 60,
    a6: 60,
    a7: 1000,
    a8: 0);
  this->m_pRawControlList->AddColumnHeader_2(
    this: this->m_pRawControlList,
    a2: 2,
    a3: "wrinkle",
    a4: "Amount",
    a5: 65,
    a6: 65,
    a7: 1000,
    a8: 0);
  this->m_pRawControlList->SetSelectIndividualCells(this: this->m_pRawControlList, a2: false);
  this->m_pRawControlList->SetEmptyListText_2(this: this->m_pRawControlList, a2: "No raw controls");
  this->m_pRawControlList->AddActionSignalTarget_2(this: this->m_pRawControlList, a2: this);
  this->m_pRawControlList->SetSortFunc(this: this->m_pRawControlList, a2: 0, a3: PresetNameSortFunc);
  this->m_pRawControlList->SetSortFunc(this: this->m_pRawControlList, a2: 1, a3: nullptr);
  this->m_pRawControlList->SetColumnSortable(this: this->m_pRawControlList, a2: 1, a3: false);
  this->m_pRawControlList->SetSortFunc(this: this->m_pRawControlList, a2: 2, a3: nullptr);
  this->m_pRawControlList->SetColumnSortable(this: this->m_pRawControlList, a2: 2, a3: false);
  this->m_pRawControlList->SetSortColumn(this: this->m_pRawControlList, a2: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00471B70
// Name: private: virtual void CDmeCombinationControlsPanel::OnFileSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeCombinationControlsPanel::OnFileSelected(
        CDmeCombinationControlsPanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *kv)
{
  int v4; // eax
  CDmeCombinationOperator *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  if ( v4 != 0 )
    v5 = (CDmeCombinationOperator *)(v4 - 4);
  else
    v5 = nullptr;
  if ( ImportCombinationData(pParent: this, pDestComboOp: v5, kv) != 0 )
  {
    CDmeCombinationControlsPanel::RefreshCombinationOperator(this, a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
    {
      v7 = KeyValues::KeyValues(
             this: v6,
             setName: "DmeElementChanged",
             firstKey: "DmeCombinationControlsPanel",
             firstValue: 1);
      this->PostActionSignal(this, a2: v7);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471C00
// Name: public: void CDmeCombinationDominationRulesPanel::RefreshCombinationOperator(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeCombinationDominationRulesPanel::RefreshCombinationOperator(
        CDmeCombinationDominationRulesPanel *this@<ecx>,
        int a2@<ebx>)
{
  CDmeCombinationDominationRulesPanel *v2; // edi
  vgui::ListPanel *m_pDominationRulesList; // ecx
  void (__thiscall *RemoveAll)(vgui::ListPanel *); // edx
  int v5; // eax
  int v6; // esi
  DmElementHandle_t m_handle; // edx
  int v8; // eax
  CDmeCombinationOperator *v9; // ecx
  int j; // eax
  CDmeCombinationOperator *v11; // ecx
  CDmeCombinationDominationRule *DominationRule; // edi
  KeyValues *v13; // eax
  int v14; // ebx
  CDmAttribute *ClipCount; // edi
  const char *Dominator; // eax
  int k; // esi
  int v18; // eax
  int v19; // ebx
  signed int v20; // edi
  int m_Size; // eax
  int v22; // esi
  int v23; // ebx
  signed int v24; // edx
  unsigned int v25; // ebx
  int v26; // eax
  int v27; // esi
  const char **v28; // ebx
  const char *Suppressed; // eax
  signed int m; // esi
  int v31; // eax
  KeyValues *v32; // edi
  int v33; // esi
  int v34; // eax
  const char **m_pMemory; // eax
  char pTemp[1024]; // [esp+8h] [ebp-840h] BYREF
  CUtlVectorFixedGrowable<char const *,256> strings; // [esp+408h] [ebp-440h] BYREF
  int v38; // [esp+820h] [ebp-28h]
  int num; // [esp+824h] [ebp-24h]
  int nCount; // [esp+828h] [ebp-20h]
  signed int v41; // [esp+82Ch] [ebp-1Ch]
  unsigned __int8 *v42; // [esp+830h] [ebp-18h]
  CDmeCombinationDominationRulesPanel *v43; // [esp+834h] [ebp-14h]
  int i; // [esp+838h] [ebp-10h]
  KeyValues *pItemKeys; // [esp+83Ch] [ebp-Ch]
  CDmeCombinationDominationRule *pRule; // [esp+840h] [ebp-8h]
  int nLen; // [esp+844h] [ebp-4h]

  v2 = this;
  m_pDominationRulesList = this->m_pDominationRulesList;
  RemoveAll = m_pDominationRulesList->RemoveAll;
  v43 = v2;
  RemoveAll(this: m_pDominationRulesList);
  v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v2->m_hCombinationOperator.m_handle);
  v6 = 0;
  if ( v5 != 0 && v5 != 4 )
  {
    strings.m_Memory.m_pMemory = strings.m_Memory.m_pFixedMemory;
    strings.m_pElements = strings.m_Memory.m_pFixedMemory;
    m_handle = v2->m_hCombinationOperator.m_handle;
    strings.m_Memory.m_nAllocationCount = 256;
    strings.m_Memory.m_nGrowSize = -1;
    strings.m_Memory.m_nMallocGrowSize = 0;
    strings.m_Size = 0;
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: m_handle);
    if ( v8 != 0 )
      v9 = (CDmeCombinationOperator *)(v8 - 4);
    else
      v9 = nullptr;
    nCount = CDmeCombinationOperator::DominationRuleCount(this: v9);
    i = 0;
    if ( nCount > 0 )
    {
      for ( j = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                  a1: g_pDataModel.u,
                  a2: v2->m_hCombinationOperator.m_handle,
                  a3: a2);
            ;
            j = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                  a1: g_pDataModel.u,
                  a2: v43->m_hCombinationOperator.m_handle,
                  a3: 0) )
      {
        if ( j != 0 )
          v11 = (CDmeCombinationOperator *)(j - 4);
        else
          v11 = nullptr;
        DominationRule = CDmeCombinationOperator::GetDominationRule(this: v11, i);
        pRule = DominationRule;
        v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v13 != nullptr )
          pItemKeys = KeyValues::KeyValues(this: v13, setName: "node");
        else
          pItemKeys = nullptr;
        v14 = 0;
        ClipCount = CDmeTrack::GetClipCount(this: (CDmeTransform *)DominationRule);
        pTemp[0] = 0;
        if ( strings.m_Size < (int)ClipCount )
          CUtlVector<char const *,CUtlMemoryFixedGrowable<char const *,256,int>>::InsertMultipleBefore(
            this: &strings,
            elem: strings.m_Size,
            num: (int)ClipCount - strings.m_Size);
        if ( (int)ClipCount > 0 )
        {
          do
          {
            nLen = (int)&strings.m_Memory.m_pMemory[v6];
            Dominator = CDmeCombinationDominationRule::GetDominator(this: pRule, i: v6++);
            *(_DWORD *)nLen = Dominator;
          }
          while ( v6 < (int)ClipCount );
        }
        qsort(
          base: strings.m_Memory.m_pMemory,
          num: (unsigned int)ClipCount,
          width: 4u,
          comp: (int (__cdecl *)(const void *, const void *))ControlNameSortFunc);
        for ( k = 0; k < (int)ClipCount; v14 += v18 )
          v18 = V_snprintf(pDest: &pTemp[v14], maxLen: 1024 - v14, pFormat: "%s ", strings.m_Memory.m_pMemory[k++]);
        KeyValues::SetString(this: pItemKeys, keyName: "dominator", value: pTemp);
        v19 = 0;
        nLen = 0;
        v20 = CDmeCombinationDominationRule::SuppressedCount(this: pRule);
        m_Size = strings.m_Size;
        pTemp[0] = 0;
        if ( strings.m_Size < v20 )
        {
          v22 = v20 - strings.m_Size;
          v23 = strings.m_Size;
          v38 = strings.m_Size;
          if ( v20 != strings.m_Size )
          {
            v24 = v20;
            v41 = v20;
            if ( v20 > strings.m_Memory.m_nAllocationCount )
            {
              num = v20 - strings.m_Memory.m_nAllocationCount;
              if ( strings.m_Memory.m_nGrowSize < 0 )
              {
                strings.m_Memory.m_nGrowSize = strings.m_Memory.m_nMallocGrowSize;
                if ( strings.m_Memory.m_nAllocationCount != 0 )
                {
                  v25 = 4 * strings.m_Memory.m_nAllocationCount;
                  v42 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(
                                             this: _g_pMemAlloc,
                                             a2: 4 * strings.m_Memory.m_nAllocationCount);
                  memcpy(dst: v42, src: (unsigned __int8 *)strings.m_Memory.m_pMemory, count: v25);
                  v23 = v38;
                  strings.m_Memory.m_pMemory = (const char **)v42;
                }
                else
                {
                  strings.m_Memory.m_pMemory = nullptr;
                }
              }
              CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&strings, num);
              m_Size = strings.m_Size;
              v24 = v41;
            }
            strings.m_Size = v22 + m_Size;
            v26 = m_Size - v23;
            strings.m_pElements = strings.m_Memory.m_pMemory;
            if ( v26 > 0 && v22 > 0 )
              _V_memmove(dest: &strings.m_Memory.m_pMemory[v24], src: &strings.m_Memory.m_pMemory[v23], count: 4 * v26);
          }
          v19 = nLen;
        }
        v27 = 0;
        if ( v20 > 0 )
        {
          do
          {
            v28 = &strings.m_Memory.m_pMemory[v27];
            Suppressed = CDmeCombinationDominationRule::GetSuppressed(this: pRule, i: v27++);
            *v28 = Suppressed;
          }
          while ( v27 < v20 );
          v19 = nLen;
        }
        qsort(
          base: strings.m_Memory.m_pMemory,
          num: v20,
          width: 4u,
          comp: (int (__cdecl *)(const void *, const void *))ControlNameSortFunc);
        for ( m = 0; m < v20; v19 += v31 )
          v31 = V_snprintf(pDest: &pTemp[v19], maxLen: 1024 - v19, pFormat: "%s ", strings.m_Memory.m_pMemory[m++]);
        v32 = pItemKeys;
        KeyValues::SetString(this: pItemKeys, keyName: "suppressed", value: pTemp);
        v33 = i;
        KeyValues::SetInt(this: v32, keyName: "index", value: i);
        v34 = pRule != nullptr ? CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pRule) : -1;
        KeyValues::SetInt(this: v32, keyName: "rule", value: v34);
        ((void (__thiscall *)(vgui::ListPanel *, KeyValues *, _DWORD, _DWORD))v43->m_pDominationRulesList->AddItem)(
          a1: v43->m_pDominationRulesList,
          a2: v32,
          a3: 0,
          a4: 0);
        v2 = v43;
        i = v33 + 1;
        if ( v33 + 1 >= nCount )
          break;
        v6 = 0;
      }
    }
    v2->m_pDominationRulesList->SortList(this: v2->m_pDominationRulesList);
    m_pMemory = strings.m_Memory.m_pMemory;
    strings.m_Size = 0;
    if ( strings.m_Memory.m_nGrowSize >= 0 )
    {
      if ( strings.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: strings.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        strings.m_Memory.m_pMemory = nullptr;
      }
      strings.m_Memory.m_nAllocationCount = 0;
    }
    strings.m_pElements = m_pMemory;
    if ( strings.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471FF0
// Name: private: virtual void CDmeCombinationDominationRulesPanel::OnMoveUp(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeCombinationDominationRulesPanel::OnMoveUp(
        CDmeCombinationDominationRulesPanel *this@<ecx>,
        int a2@<ebx>)
{
  CDmeCombinationDominationRule *SelectedRule; // edi
  int v4; // eax
  CDmeCombinationOperator *v5; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  SelectedRule = CDmeCombinationDominationRulesPanel::GetSelectedRule(this);
  if ( SelectedRule != nullptr )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hCombinationOperator.m_handle);
    if ( v4 != 0 )
      v5 = (CDmeCombinationOperator *)(v4 - 4);
    else
      v5 = nullptr;
    CDmeCombinationOperator::MoveDominationRuleUp(this: v5, pRule: SelectedRule);
    CDmeCombinationDominationRulesPanel::RefreshCombinationOperator(this, a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
    {
      v7 = KeyValues::KeyValues(
             this: v6,
             setName: "DmeElementChanged",
             firstKey: "DmeCombinationDominationRulesPanel",
             firstValue: 2);
      this->PostActionSignal(this, a2: v7);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472070
// Name: private: virtual void CDmeCombinationDominationRulesPanel::OnMoveDown(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeCombinationDominationRulesPanel::OnMoveDown(
        CDmeCombinationDominationRulesPanel *this@<ecx>,
        int a2@<ebx>)
{
  CDmeCombinationDominationRule *SelectedRule; // edi
  int v4; // eax
  CDmeCombinationOperator *v5; // ecx
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  SelectedRule = CDmeCombinationDominationRulesPanel::GetSelectedRule(this);
  if ( SelectedRule != nullptr )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hCombinationOperator.m_handle);
    if ( v4 != 0 )
      v5 = (CDmeCombinationOperator *)(v4 - 4);
    else
      v5 = nullptr;
    CDmeCombinationOperator::MoveDominationRuleDown(this: v5, pRule: SelectedRule);
    CDmeCombinationDominationRulesPanel::RefreshCombinationOperator(this, a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
    {
      v7 = KeyValues::KeyValues(
             this: v6,
             setName: "DmeElementChanged",
             firstKey: "DmeCombinationDominationRulesPanel",
             firstValue: 2);
      this->PostActionSignal(this, a2: v7);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004720F0
// Name: private: virtual void CDmeCombinationDominationRulesPanel::OnFileSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeCombinationDominationRulesPanel::OnFileSelected(
        CDmeCombinationDominationRulesPanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *kv)
{
  int v4; // eax
  CDmeCombinationOperator *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  if ( v4 != 0 )
    v5 = (CDmeCombinationOperator *)(v4 - 4);
  else
    v5 = nullptr;
  if ( ImportCombinationData(pParent: this, pDestComboOp: v5, kv) != 0 )
  {
    CDmeCombinationDominationRulesPanel::RefreshCombinationOperator(this, a2);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
    {
      v7 = KeyValues::KeyValues(
             this: v6,
             setName: "DmeElementChanged",
             firstKey: "DmeCombinationDominationRulesPanel",
             firstValue: 2);
      this->PostActionSignal(this, a2: v7);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472180
// Name: private: virtual void CDmeCombinationDominationRulesPanel::OnAddDominationRule(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeCombinationDominationRulesPanel::OnAddDominationRule(
        CDmeCombinationDominationRulesPanel *this@<ecx>,
        int a2@<ebx>)
{
  int v3; // eax
  CDmeCombinationOperator *v4; // ecx
  CDmeCombinationDominationRule *v5; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  if ( v3 != 0 )
    v4 = (CDmeCombinationOperator *)(v3 - 4);
  else
    v4 = nullptr;
  v5 = CDmeCombinationOperator::AddDominationRule(this: v4);
  CDmeCombinationDominationRulesPanel::RefreshCombinationOperator(this, a2);
  CDmeCombinationDominationRulesPanel::SelectRule(this, pRule: v5);
  this->OnSelectSuppressed(this);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
  {
    v7 = KeyValues::KeyValues(
           this: v6,
           setName: "DmeElementChanged",
           firstKey: "DmeCombinationDominationRulesPanel",
           firstValue: 2);
    this->PostActionSignal(this, a2: v7);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472210
// Name: private: virtual void CDmeCombinationDominationRulesPanel::OnDuplicateSuppressed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationDominationRulesPanel::OnDuplicateSuppressed(CDmeCombinationDominationRulesPanel *this)
{
  CDmeCombinationDominationRule *SelectedRule; // ebx
  int v3; // eax
  CDmeCombinationOperator *v4; // ecx
  int i; // esi
  const char *Suppressed; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  CDmeCombinationDominationRule *pRule; // [esp+8h] [ebp-4h]

  SelectedRule = CDmeCombinationDominationRulesPanel::GetSelectedRule(this);
  if ( SelectedRule != nullptr )
  {
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hCombinationOperator.m_handle);
    if ( v3 != 0 )
      v4 = (CDmeCombinationOperator *)(v3 - 4);
    else
      v4 = nullptr;
    pRule = CDmeCombinationOperator::AddDominationRule(this: v4);
    CDmeCombinationDominationRulesPanel::RefreshCombinationOperator(this, a2: (int)SelectedRule);
    CDmeCombinationDominationRulesPanel::SelectRule(this, pRule);
    for ( i = 0; i < CDmeCombinationDominationRule::SuppressedCount(this: SelectedRule); ++i )
    {
      Suppressed = CDmeCombinationDominationRule::GetSuppressed(this: SelectedRule, i);
      CDmeCombinationDominationRule::AddSuppressed(this: pRule, pSuppressedControl: Suppressed);
    }
    this->OnSelectDominators(this);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
    {
      v8 = KeyValues::KeyValues(
             this: v7,
             setName: "DmeElementChanged",
             firstKey: "DmeCombinationDominationRulesPanel",
             firstValue: 2);
      this->PostActionSignal(this, a2: v8);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004722F0
// Name: private: virtual void CDmeCombinationDominationRulesPanel::OnDuplicateDominators(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationDominationRulesPanel::OnDuplicateDominators(CDmeCombinationDominationRulesPanel *this)
{
  CDmeCombinationDominationRule *SelectedRule; // ebx
  int v3; // eax
  CDmeCombinationOperator *v4; // ecx
  int i; // esi
  const char *Dominator; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  CDmeCombinationDominationRule *pRule; // [esp+8h] [ebp-4h]

  SelectedRule = CDmeCombinationDominationRulesPanel::GetSelectedRule(this);
  if ( SelectedRule != nullptr )
  {
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hCombinationOperator.m_handle);
    if ( v3 != 0 )
      v4 = (CDmeCombinationOperator *)(v3 - 4);
    else
      v4 = nullptr;
    pRule = CDmeCombinationOperator::AddDominationRule(this: v4);
    CDmeCombinationDominationRulesPanel::RefreshCombinationOperator(this, a2: (int)SelectedRule);
    CDmeCombinationDominationRulesPanel::SelectRule(this, pRule);
    for ( i = 0; i < (int)CDmeTrack::GetClipCount(this: (CDmeTransform *)SelectedRule); ++i )
    {
      Dominator = CDmeCombinationDominationRule::GetDominator(this: SelectedRule, i);
      CDmeCombinationDominationRule::AddDominator(this: pRule, pDominatorControl: Dominator);
    }
    this->OnSelectSuppressed(this);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
    {
      v8 = KeyValues::KeyValues(
             this: v7,
             setName: "DmeElementChanged",
             firstKey: "DmeCombinationDominationRulesPanel",
             firstValue: 2);
      this->PostActionSignal(this, a2: v8);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004723D0
// Name: private: virtual void CDmeCombinationDominationRulesPanel::OnRemoveDominationRule(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationDominationRulesPanel::OnRemoveDominationRule(CDmeCombinationDominationRulesPanel *this)
{
  int v2; // ebx
  int v3; // eax
  KeyValues *v4; // eax
  int Int; // eax
  int v6; // eax
  CDmeCombinationDominationRule *v7; // esi
  int v8; // eax
  CDmeCombinationOperator *v9; // ecx
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  int nSelectedItemCount; // [esp+Ch] [ebp-4h]

  v2 = 0;
  nSelectedItemCount = this->m_pDominationRulesList->GetSelectedItemsCount(this: this->m_pDominationRulesList);
  if ( nSelectedItemCount > 0 )
  {
    do
    {
      v3 = this->m_pDominationRulesList->GetSelectedItem(this: this->m_pDominationRulesList, a2: v2);
      v4 = this->m_pDominationRulesList->GetItem(this: this->m_pDominationRulesList, a2: v3);
      Int = KeyValues::GetInt(this: v4, keyName: "rule", defaultValue: -1);
      v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: Int);
      v7 = (CDmeCombinationDominationRule *)v6;
      if ( v6 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
             a1: v6,
             a2: CDmeCombinationDominationRule::m_classType.u) != 0 )
      {
        v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_hCombinationOperator.m_handle);
        if ( v8 != 0 )
          v9 = (CDmeCombinationOperator *)(v8 - 4);
        else
          v9 = nullptr;
        CDmeCombinationOperator::RemoveDominationRule(this: v9, pRule: v7);
      }
      ++v2;
    }
    while ( v2 < nSelectedItemCount );
  }
  CDmeCombinationDominationRulesPanel::RefreshCombinationOperator(this, a2: v2);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
  {
    v11 = KeyValues::KeyValues(
            this: v10,
            setName: "DmeElementChanged",
            firstKey: "DmeCombinationDominationRulesPanel",
            firstValue: 2);
    this->PostActionSignal(this, a2: v11);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004724E0
// Name: private: virtual void CDmeCombinationDominationRulesPanel::OnRawControlPicked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationDominationRulesPanel::OnRawControlPicked(
        CDmeCombinationDominationRulesPanel *this,
        KeyValues *pKeyValues)
{
  KeyValues *Key; // ebx
  KeyValues *v3; // eax
  int Int; // eax
  int v5; // eax
  CDmeCombinationDominationRule *v6; // edi
  KeyValues *i; // esi
  const char *Name; // eax
  CDmeCombinationDominationRulesPanel *v9; // esi
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  CDmeCombinationDominationRule *ElementKey; // eax
  CDmeCombinationDominationRule *v14; // edi
  KeyValues *j; // esi
  const char *v16; // eax

  Key = KeyValues::FindKey(this: pKeyValues, keyName: "rawControls", bCreate: false);
  if ( Key != nullptr )
  {
    v3 = KeyValues::FindKey(this: pKeyValues, keyName: "OnSelectDominators", bCreate: false);
    if ( v3 != nullptr )
    {
      Int = KeyValues::GetInt(this: v3, keyName: "rule", defaultValue: -1);
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: Int);
      v6 = (CDmeCombinationDominationRule *)v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmeCombinationDominationRule::m_classType.u) != 0 )
      {
        CDmeCombinationDominationRule::RemoveAllDominators(this: v6);
        for ( i = KeyValues::GetFirstValue(this: Key); i != nullptr; i = KeyValues::GetNextValue(this: i) )
        {
          Name = KeyValues::GetName(this: i);
          CDmeCombinationDominationRule::AddDominator(this: v6, pDominatorControl: Name);
        }
        v9 = this;
        CDmeCombinationDominationRulesPanel::RefreshCombinationOperator(this, a2: (int)Key);
        v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v10 != nullptr )
        {
LABEL_8:
          v11 = KeyValues::KeyValues(
                  this: v10,
                  setName: "DmeElementChanged",
                  firstKey: "DmeCombinationDominationRulesPanel",
                  firstValue: 2);
LABEL_15:
          v9->PostActionSignal(this: v9, a2: v11);
          return;
        }
LABEL_14:
        v11 = nullptr;
        goto LABEL_15;
      }
    }
    else
    {
      v12 = KeyValues::FindKey(this: pKeyValues, keyName: "OnSelectSuppressed", bCreate: false);
      if ( v12 != nullptr )
      {
        ElementKey = GetElementKeyValue<CDmeCombinationDominationRule>(pKeyValues: v12, pName: "rule");
        v14 = ElementKey;
        if ( ElementKey != nullptr )
        {
          CDmeCombinationDominationRule::RemoveAllSuppressed(this: ElementKey);
          for ( j = KeyValues::GetFirstValue(this: Key); j != nullptr; j = KeyValues::GetNextValue(this: j) )
          {
            v16 = KeyValues::GetName(this: j);
            CDmeCombinationDominationRule::AddSuppressed(this: v14, pSuppressedControl: v16);
          }
          v9 = this;
          CDmeCombinationDominationRulesPanel::RefreshCombinationOperator(this, a2: (int)Key);
          v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v10 != nullptr )
            goto LABEL_8;
          goto LABEL_14;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472670
// Name: public: CDmeCombinationSystemEditorPanel::CDmeCombinationSystemEditorPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeCombinationSystemEditorPanel *__thiscall CDmeCombinationSystemEditorPanel::CDmeCombinationSystemEditorPanel(
        CDmeCombinationSystemEditorPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::PropertySheet *v7; // eax
  vgui::PropertySheet *v8; // eax
  vgui::PropertyPage *v9; // eax
  vgui::PropertyPage *v10; // eax
  vgui::PropertyPage *v11; // eax
  vgui::PropertyPage *v12; // eax
  vgui::PropertyPage *v13; // eax
  vgui::PropertyPage *v14; // eax
  CDmeCombinationControlsPanel *v15; // eax
  CDmeCombinationControlsPanel *v16; // eax
  CDmeCombinationDominationRulesPanel *v17; // eax
  CDmeCombinationDominationRulesPanel *v18; // eax
  CDmeElementPanel *v19; // eax
  CDmeElementPanel *v20; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CDmeCombinationSystemEditorPanel_vtbl *)&CDmeCombinationSystemEditorPanel::`vftable';
  if ( `CDmeCombinationSystemEditorPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeCombinationSystemEditorPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationSystemEditorPanel");
    v4->pfnClassName = CDmeCombinationSystemEditorPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CDmeCombinationSystemEditorPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeCombinationSystemEditorPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeCombinationSystemEditorPanel");
    v5->pfnClassName = CDmeCombinationSystemEditorPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CDmeCombinationSystemEditorPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeCombinationSystemEditorPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeCombinationSystemEditorPanel");
    v6->pfnClassName = CDmeCombinationSystemEditorPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CDmeCombinationSystemEditorPanel::PanelMessageFunc_OnPageChanged::InitVar(a1: (int)&savedregs);
  CDmeCombinationSystemEditorPanel::PanelMessageFunc_OnDmeElementChanged::InitVar(a1: (int)&savedregs);
  v7 = (vgui::PropertySheet *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v7 != nullptr )
    v8 = vgui::PropertySheet::PropertySheet(this: v7, parent: this, panelName: "EditorSheet", draggableTabs: false);
  else
    v8 = nullptr;
  this->m_pEditorSheet = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v9 != nullptr )
    v10 = vgui::PropertyPage::PropertyPage(this: v9, parent: this->m_pEditorSheet, panelName: "ControlsPage");
  else
    v10 = nullptr;
  this->m_pControlsPage = v10;
  v11 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v11 != nullptr )
    v12 = vgui::PropertyPage::PropertyPage(this: v11, parent: this->m_pEditorSheet, panelName: "DominationRulesPage");
  else
    v12 = nullptr;
  this->m_pDominationRulesPage = v12;
  v13 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v13 != nullptr )
    v14 = vgui::PropertyPage::PropertyPage(this: v13, parent: this->m_pEditorSheet, panelName: "PropertiesPage");
  else
    v14 = nullptr;
  this->m_pPropertiesPage = v14;
  v15 = (CDmeCombinationControlsPanel *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v15 != nullptr )
    v16 = CDmeCombinationControlsPanel::CDmeCombinationControlsPanel(
            this: v15,
            pParent: nullptr,
            pName: "CombinationControls");
  else
    v16 = nullptr;
  this->m_pControlsPanel = v16;
  v16->AddActionSignalTarget_2(this: v16, a2: this);
  v17 = (CDmeCombinationDominationRulesPanel *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v17 != nullptr )
    v18 = CDmeCombinationDominationRulesPanel::CDmeCombinationDominationRulesPanel(
            this: v17,
            pParent: nullptr,
            pName: "DominationRules");
  else
    v18 = nullptr;
  this->m_pDominationRulesPanel = v18;
  v18->AddActionSignalTarget_2(this: v18, a2: this);
  v19 = (CDmeElementPanel *)MemAlloc_Alloc(nSize: 0x2C4u);
  if ( v19 != nullptr )
    v20 = CDmeElementPanel::CDmeElementPanel(this: v19, pParent: nullptr, pPanelName: "PropertiesPanel");
  else
    v20 = nullptr;
  this->m_pPropertiesPanel = v20;
  v20->AddActionSignalTarget_2(this: v20, a2: this);
  this->m_pControlsPanel->LoadControlSettingsAndUserConfig(
    this: this->m_pControlsPanel,
    a2: "resource/dmecombinationsystemeditorpanel_controlspage.res",
    a3: 0);
  this->m_pDominationRulesPanel->LoadControlSettingsAndUserConfig(
    this: this->m_pDominationRulesPanel,
    a2: "resource/dmecombinationsystemeditorpanel_dominationpage.res",
    a3: 0);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/dmecombinationsystemeditorpanel.res",
    dialogID: 0);
  this->m_pEditorSheet->AddPage(
    this: this->m_pEditorSheet,
    a2: this->m_pControlsPanel,
    a3: "Controls",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pEditorSheet->AddPage(
    this: this->m_pEditorSheet,
    a2: this->m_pDominationRulesPanel,
    a3: "Domination",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pEditorSheet->AddPage(
    this: this->m_pEditorSheet,
    a2: this->m_pPropertiesPanel,
    a3: "Properties",
    a4: nullptr,
    a5: false,
    a6: -1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00472940
// Name: private: virtual void CDmeCombinationSystemEditorPanel::OnDmeElementChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeCombinationSystemEditorPanel::OnDmeElementChanged(
        CDmeCombinationSystemEditorPanel *this@<ecx>,
        int a2@<ebx>,
        KeyValues *kv)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  CDmeCombinationControlsPanel::RefreshCombinationOperator(this: this->m_pControlsPanel, a2);
  CDmeCombinationDominationRulesPanel::RefreshCombinationOperator(this: this->m_pDominationRulesPanel, a2);
  this->m_pPropertiesPanel->Refresh(this: this->m_pPropertiesPanel, a2: REFRESH_TREE_VIEW, a3: false);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v4, setName: "DmeElementChanged");
    this->PostActionSignal(this, a2: v5);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004729B0
// Name: public: CDmeCombinationSystemEditorFrame::CDmeCombinationSystemEditorFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeCombinationSystemEditorFrame *__thiscall CDmeCombinationSystemEditorFrame::CDmeCombinationSystemEditorFrame(
        CDmeCombinationSystemEditorFrame *this,
        vgui::Panel *pParent,
        const char *pTitle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CDmeCombinationSystemEditorPanel *v7; // eax
  CDmeCombinationSystemEditorPanel *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(
    this,
    parent: pParent,
    panelName: "DmeCombinationSystemEditorFrame",
    showTaskbarIcon: true,
    bPopup: true);
  this->__vftable = (CDmeCombinationSystemEditorFrame_vtbl *)&CDmeCombinationSystemEditorFrame::`vftable';
  if ( `CDmeCombinationSystemEditorFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeCombinationSystemEditorFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeCombinationSystemEditorFrame");
    v4->pfnClassName = CDmeCombinationSystemEditorFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CDmeCombinationSystemEditorFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeCombinationSystemEditorFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeCombinationSystemEditorFrame");
    v5->pfnClassName = CDmeCombinationSystemEditorFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CDmeCombinationSystemEditorFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeCombinationSystemEditorFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeCombinationSystemEditorFrame");
    v6->pfnClassName = CDmeCombinationSystemEditorFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CDmeCombinationSystemEditorFrame::PanelMessageFunc_OnDmeElementChanged::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v7 = (CDmeCombinationSystemEditorPanel *)MemAlloc_Alloc(nSize: 0x1A0u);
  if ( v7 != nullptr )
    v8 = CDmeCombinationSystemEditorPanel::CDmeCombinationSystemEditorPanel(
           this: v7,
           pParent: this,
           pName: "DmeCombinationSystemEditorPanel");
  else
    v8 = nullptr;
  this->m_pEditor = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OpenButton",
            text: "#FileOpenDialog_Open",
            pActionSignalTarget: this,
            pCmd: "Open");
  else
    v10 = nullptr;
  this->m_pOpenButton = v10;
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "CancelButton",
            text: "#FileOpenDialog_Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v12 = nullptr;
  this->m_pCancelButton = v12;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/dmecombinationsystemeditorframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00472B40
// Name: private: void CDmeCombinationControlsPanel::PerformGroupControls(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeCombinationControlsPanel::PerformGroupControls(
        CDmeCombinationControlsPanel *this@<ecx>,
        DmElementHandle_t a2@<edi>,
        int a3@<esi>,
        const char *pGroupedControlName)
{
  CDmeCombinationOperator *v5; // esi
  CUtlString *m_pMemory; // edi
  int v7; // eax
  const char *v8; // eax
  int v9; // eax
  CDmeCombinationOperator *v10; // ecx
  int Control; // edi
  int (__thiscall *v12)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // eax
  int v13; // eax
  CDmeCombinationOperator *v14; // eax
  CUtlString *v15; // edi
  int v16; // eax
  CDmeCombinationOperator *v17; // esi
  const char *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  DmElementHandle_t m_handle; // [esp-4h] [ebp-3Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > rawControlNames; // [esp+4h] [ebp-34h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > controlNames; // [esp+18h] [ebp-20h] BYREF
  BOOL bIsEyelid; // [esp+2Ch] [ebp-Ch] BYREF
  int nNewControl; // [esp+30h] [ebp-8h] BYREF
  int i; // [esp+34h] [ebp-4h]
  const char *pGroupedControlNamea; // [esp+40h] [ebp+8h]

  if ( this->m_pControlList->GetSelectedItemsCount(this: this->m_pControlList) > 1 )
  {
    v5 = nullptr;
    memset(&controlNames, 0, sizeof(controlNames));
    memset(&rawControlNames, 0, sizeof(rawControlNames));
    LOBYTE(nNewControl) = 0;
    LOBYTE(bIsEyelid) = 0;
    CDmeCombinationControlsPanel::BuildSelectedControlLists(
      this,
      m_handle: a2,
      bOnlyGroupedControls: false,
      &controlNames,
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&rawControlNames,
      pbStereo: (bool *)&nNewControl,
      pbEyelid: (bool *)&bIsEyelid);
    if ( CDmeCombinationControlsPanel::HasDuplicateControlName(
           this,
           pControlName: pGroupedControlName,
           retiredControlNames: &controlNames) != 0 )
    {
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: &rawControlNames);
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: &controlNames);
    }
    else
    {
      if ( controlNames.m_Size > 0 )
      {
        m_pMemory = controlNames.m_Memory.m_pMemory;
        for ( i = controlNames.m_Size; i != 0; --i )
        {
          v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: this->m_hCombinationOperator.m_handle);
          if ( v7 != 0 )
            v5 = (CDmeCombinationOperator *)(v7 - 4);
          v8 = CUtlString::operator char const *(this: m_pMemory);
          CDmeCombinationOperator::RemoveControl(this: v5, pControlName: v8);
          ++m_pMemory;
          v5 = nullptr;
        }
      }
      v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, DmElementHandle_t, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: this->m_hCombinationOperator.m_handle,
             a3: a2,
             a4: a3);
      if ( v9 != 0 )
        v10 = (CDmeCombinationOperator *)(v9 - 4);
      else
        v10 = nullptr;
      Control = CDmeCombinationOperator::FindOrCreateControl(
                  this: v10,
                  pControlName: pGroupedControlName,
                  bStereo: nNewControl,
                  bAutoAddRawControl: false);
      v12 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72);
      m_handle = this->m_hCombinationOperator.m_handle;
      nNewControl = Control;
      v13 = ((int (__thiscall *)(_DWORD, _DWORD))v12)(
              a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
              a2: m_handle);
      if ( v13 != 0 )
        v14 = (CDmeCombinationOperator *)(v13 - 4);
      else
        v14 = nullptr;
      CDmeCombinationOperator::SetEyelidControl(this: v14, nControlIndex: Control, bIsEyelid);
      if ( rawControlNames.m_Size > 0 )
      {
        v15 = rawControlNames.m_Memory.m_pMemory;
        for ( pGroupedControlNamea = (const char *)rawControlNames.m_Size;
              pGroupedControlNamea != nullptr;
              --pGroupedControlNamea )
        {
          v16 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 72))(
                  a1: g_pDataModel.u,
                  a2: this->m_hCombinationOperator.m_handle);
          if ( v16 != 0 )
            v17 = (CDmeCombinationOperator *)(v16 - 4);
          else
            v17 = nullptr;
          v18 = CUtlString::operator char const *(this: v15);
          CDmeCombinationOperator::AddRawControl(this: v17, nControl: nNewControl, pRawControlName: v18);
          ++v15;
        }
      }
      CDmeCombinationControlsPanel::RefreshCombinationOperator(this, a2: (int)this);
      v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v19 != nullptr )
        v20 = KeyValues::KeyValues(
                this: v19,
                setName: "DmeElementChanged",
                firstKey: "DmeCombinationControlsPanel",
                firstValue: 1);
      else
        v20 = nullptr;
      this->PostActionSignal(this, a2: v20);
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &rawControlNames);
      if ( rawControlNames.m_Memory.m_nGrowSize >= 0 && rawControlNames.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rawControlNames.m_Memory.m_pMemory);
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &controlNames);
      if ( controlNames.m_Memory.m_nGrowSize >= 0 && controlNames.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: controlNames.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472D50
// Name: private: virtual void CDmeCombinationControlsPanel::OnInputCompleted(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeCombinationControlsPanel::OnInputCompleted(
        CDmeCombinationControlsPanel *this,
        KeyValues *pKeyValues)
{
  const char *String; // eax
  const char *v4; // esi

  String = KeyValues::GetString(this: pKeyValues, keyName: "text", defaultValue: nullptr);
  v4 = String;
  if ( String != nullptr && *String != 0 )
  {
    if ( KeyValues::FindKey(this: pKeyValues, keyName: "OnGroupControls", bCreate: false) != nullptr )
    {
      CDmeCombinationControlsPanel::PerformGroupControls(
        this,
        a2: (DmElementHandle_t)pKeyValues,
        a3: (int)v4,
        pGroupedControlName: v4);
    }
    else if ( KeyValues::FindKey(this: pKeyValues, keyName: "OnRenameControl", bCreate: false) != nullptr )
    {
      CDmeCombinationControlsPanel::PerformRenameControl(this, pNewControlName: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472DC0
// Name: private: virtual void CDmeCombinationControlsPanel::OnUngroupControls(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeCombinationControlsPanel::OnUngroupControls(
        CDmeCombinationControlsPanel *this@<ecx>,
        DmElementHandle_t a2@<edi>)
{
  int v3; // esi
  CUtlString *v4; // edi
  const char *v5; // eax
  CUtlString *m_pMemory; // edi
  int v7; // eax
  CDmeCombinationOperator *v8; // esi
  CUtlString *v9; // eax
  bool v10; // zf
  const char *v11; // eax
  CUtlString *v12; // edi
  int v13; // eax
  CDmeCombinationOperator *v14; // esi
  const char *v15; // eax
  int Control; // esi
  int v17; // eax
  CDmeCombinationOperator *v18; // ecx
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  bool v21; // [esp-8h] [ebp-48h]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > controlNames; // [esp+Ch] [ebp-34h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > rawControlNames; // [esp+20h] [ebp-20h] BYREF
  BOOL bIsEyelid; // [esp+34h] [ebp-Ch] BYREF
  BOOL bIsStereo; // [esp+38h] [ebp-8h] BYREF
  int i; // [esp+3Ch] [ebp-4h]

  v3 = 0;
  memset(&controlNames, 0, sizeof(controlNames));
  memset(&rawControlNames, 0, sizeof(rawControlNames));
  LOBYTE(bIsStereo) = 0;
  LOBYTE(bIsEyelid) = 0;
  CDmeCombinationControlsPanel::BuildSelectedControlLists(
    this,
    m_handle: a2,
    bOnlyGroupedControls: true,
    &controlNames,
    (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&rawControlNames,
    pbStereo: (bool *)&bIsStereo,
    pbEyelid: (bool *)&bIsEyelid);
  if ( rawControlNames.m_Size <= 0 )
  {
LABEL_5:
    if ( controlNames.m_Size > 0 )
    {
      m_pMemory = controlNames.m_Memory.m_pMemory;
      for ( i = controlNames.m_Size; i != 0; --i )
      {
        v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_hCombinationOperator.m_handle);
        if ( v7 != 0 )
          v8 = (CDmeCombinationOperator *)(v7 - 4);
        else
          v8 = nullptr;
        v11 = CUtlString::operator char const *(this: m_pMemory);
        CDmeCombinationOperator::RemoveControl(this: v8, pControlName: v11);
        ++m_pMemory;
      }
    }
    if ( rawControlNames.m_Size > 0 )
    {
      v12 = rawControlNames.m_Memory.m_pMemory;
      for ( i = rawControlNames.m_Size; i != 0; --i )
      {
        v13 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: this->m_hCombinationOperator.m_handle);
        if ( v13 != 0 )
          v14 = (CDmeCombinationOperator *)(v13 - 4);
        else
          v14 = nullptr;
        v21 = bIsStereo;
        v15 = CUtlString::operator char const *(this: v12);
        Control = CDmeCombinationOperator::FindOrCreateControl(
                    this: v14,
                    pControlName: v15,
                    bStereo: v21,
                    bAutoAddRawControl: true);
        v17 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: this->m_hCombinationOperator.m_handle);
        if ( v17 != 0 )
          v18 = (CDmeCombinationOperator *)(v17 - 4);
        else
          v18 = nullptr;
        CDmeCombinationOperator::SetEyelidControl(this: v18, nControlIndex: Control, bIsEyelid);
        ++v12;
      }
    }
    CDmeCombinationControlsPanel::RefreshCombinationOperator(this, a2: (int)this);
    v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v19 != nullptr )
      v20 = KeyValues::KeyValues(
              this: v19,
              setName: "DmeElementChanged",
              firstKey: "DmeCombinationControlsPanel",
              firstValue: 1);
    else
      v20 = nullptr;
    this->PostActionSignal(this, a2: v20);
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &rawControlNames);
    if ( rawControlNames.m_Memory.m_nGrowSize >= 0 && rawControlNames.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rawControlNames.m_Memory.m_pMemory);
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &controlNames);
    if ( controlNames.m_Memory.m_nGrowSize >= 0 )
    {
      v9 = controlNames.m_Memory.m_pMemory;
      v10 = controlNames.m_Memory.m_pMemory == nullptr;
LABEL_33:
      if ( !v10 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
    }
  }
  else
  {
    v4 = rawControlNames.m_Memory.m_pMemory;
    while ( 1 )
    {
      v5 = CUtlString::operator char const *(this: v4);
      if ( CDmeCombinationControlsPanel::HasDuplicateControlName(
             this,
             pControlName: v5,
             retiredControlNames: &controlNames) != 0 )
        break;
      ++v3;
      ++v4;
      if ( v3 >= rawControlNames.m_Size )
        goto LABEL_5;
    }
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &rawControlNames);
    if ( rawControlNames.m_Memory.m_nGrowSize >= 0 && rawControlNames.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rawControlNames.m_Memory.m_pMemory);
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &controlNames);
    if ( controlNames.m_Memory.m_nGrowSize >= 0 )
    {
      v9 = controlNames.m_Memory.m_pMemory;
      v10 = controlNames.m_Memory.m_pMemory == nullptr;
      goto LABEL_33;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00472FE0
// Name: private: virtual void CDmeCombinationControlsPanel::OnToggleStereoControl(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeCombinationControlsPanel::OnToggleStereoControl(
        CDmeCombinationControlsPanel *this@<ecx>,
        DmElementHandle_t a2@<edi>)
{
  CDmeCombinationOperator *v2; // esi
  CUtlString *m_pMemory; // edi
  int v5; // eax
  const char *v6; // eax
  int ControlIndex; // esi
  int v8; // eax
  CDmeCombinationOperator *v9; // ecx
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  DmElementHandle_t m_handle; // [esp-4h] [ebp-40h]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > rawControlNames; // [esp+8h] [ebp-34h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > controlNames; // [esp+1Ch] [ebp-20h] BYREF
  bool v15[4]; // [esp+30h] [ebp-Ch]
  int i; // [esp+34h] [ebp-8h]
  bool bIsStereo; // [esp+3Bh] [ebp-1h] BYREF

  v2 = nullptr;
  memset(&controlNames, 0, sizeof(controlNames));
  memset(&rawControlNames, 0, sizeof(rawControlNames));
  bIsStereo = false;
  CDmeCombinationControlsPanel::BuildSelectedControlLists(
    this,
    m_handle: a2,
    bOnlyGroupedControls: false,
    &controlNames,
    (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&rawControlNames,
    pbStereo: &bIsStereo,
    pbEyelid: nullptr);
  if ( controlNames.m_Size > 0 )
  {
    m_handle = a2;
    m_pMemory = controlNames.m_Memory.m_pMemory;
    v15[0] = !bIsStereo;
    for ( i = controlNames.m_Size; i != 0; --i )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: this->m_hCombinationOperator.m_handle,
             a3: m_handle);
      if ( v5 != 0 )
        v2 = (CDmeCombinationOperator *)(v5 - 4);
      v6 = CUtlString::operator char const *(this: m_pMemory);
      ControlIndex = CDmeCombinationOperator::FindControlIndex(this: v2, pControlName: v6);
      m_handle = this->m_hCombinationOperator.m_handle;
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(a1: g_pDataModel.u);
      if ( v8 != 0 )
        v9 = (CDmeCombinationOperator *)(v8 - 4);
      else
        v9 = nullptr;
      CDmeCombinationOperator::SetStereoControl(this: v9, nControlIndex: ControlIndex, bIsStereo: v15[0]);
      ++m_pMemory;
      v2 = nullptr;
    }
  }
  CDmeCombinationControlsPanel::RefreshCombinationOperator(this, a2: (int)this);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(
            this: v10,
            setName: "DmeElementChanged",
            firstKey: "DmeCombinationControlsPanel",
            firstValue: 1);
  else
    v11 = nullptr;
  this->PostActionSignal(this, a2: v11);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &rawControlNames);
  if ( rawControlNames.m_Memory.m_nGrowSize >= 0 && rawControlNames.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rawControlNames.m_Memory.m_pMemory);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &controlNames);
  if ( controlNames.m_Memory.m_nGrowSize >= 0 && controlNames.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: controlNames.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00473130
// Name: private: virtual void CDmeCombinationControlsPanel::OnToggleEyelidControl(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeCombinationControlsPanel::OnToggleEyelidControl(
        CDmeCombinationControlsPanel *this@<ecx>,
        DmElementHandle_t a2@<edi>)
{
  CDmeCombinationOperator *v2; // esi
  CUtlString *m_pMemory; // edi
  int v5; // eax
  const char *v6; // eax
  int ControlIndex; // esi
  int v8; // eax
  CDmeCombinationOperator *v9; // ecx
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  DmElementHandle_t m_handle; // [esp-4h] [ebp-40h]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > rawControlNames; // [esp+8h] [ebp-34h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > controlNames; // [esp+1Ch] [ebp-20h] BYREF
  bool v15[4]; // [esp+30h] [ebp-Ch]
  int i; // [esp+34h] [ebp-8h]
  bool bIsEyelid; // [esp+3Bh] [ebp-1h] BYREF

  v2 = nullptr;
  memset(&controlNames, 0, sizeof(controlNames));
  memset(&rawControlNames, 0, sizeof(rawControlNames));
  bIsEyelid = false;
  CDmeCombinationControlsPanel::BuildSelectedControlLists(
    this,
    m_handle: a2,
    bOnlyGroupedControls: false,
    &controlNames,
    (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&rawControlNames,
    pbStereo: nullptr,
    pbEyelid: &bIsEyelid);
  if ( controlNames.m_Size > 0 )
  {
    m_handle = a2;
    m_pMemory = controlNames.m_Memory.m_pMemory;
    v15[0] = !bIsEyelid;
    for ( i = controlNames.m_Size; i != 0; --i )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: this->m_hCombinationOperator.m_handle,
             a3: m_handle);
      if ( v5 != 0 )
        v2 = (CDmeCombinationOperator *)(v5 - 4);
      v6 = CUtlString::operator char const *(this: m_pMemory);
      ControlIndex = CDmeCombinationOperator::FindControlIndex(this: v2, pControlName: v6);
      m_handle = this->m_hCombinationOperator.m_handle;
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(a1: g_pDataModel.u);
      if ( v8 != 0 )
        v9 = (CDmeCombinationOperator *)(v8 - 4);
      else
        v9 = nullptr;
      CDmeCombinationOperator::SetEyelidControl(this: v9, nControlIndex: ControlIndex, bIsEyelid: v15[0]);
      ++m_pMemory;
      v2 = nullptr;
    }
  }
  CDmeCombinationControlsPanel::RefreshCombinationOperator(this, a2: (int)this);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(
            this: v10,
            setName: "DmeElementChanged",
            firstKey: "DmeCombinationControlsPanel",
            firstValue: 1);
  else
    v11 = nullptr;
  this->PostActionSignal(this, a2: v11);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &rawControlNames);
  if ( rawControlNames.m_Memory.m_nGrowSize >= 0 && rawControlNames.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: rawControlNames.m_Memory.m_pMemory);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &controlNames);
  if ( controlNames.m_Memory.m_nGrowSize >= 0 && controlNames.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: controlNames.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00473280
// Name: public: void CDmeCombinationDominationRulesPanel::SetCombinationOperator(class CDmeCombinationOperator __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeCombinationDominationRulesPanel::SetCombinationOperator(
        CDmeCombinationDominationRulesPanel *this@<ecx>,
        int a2@<ebx>,
        CDmeCombinationOperator *pOp)
{
  int v4; // eax
  CDmeCombinationOperator *v5; // ecx
  CDmElement *v6; // ecx
  DmElementHandle_t BufferType; // eax

  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hCombinationOperator.m_handle);
  if ( v4 != 0 )
    v5 = (CDmeCombinationOperator *)(v4 - 4);
  else
    v5 = nullptr;
  if ( pOp != v5 )
  {
    if ( pOp != nullptr )
      v6 = &pOp->CDmElement;
    else
      v6 = nullptr;
    if ( v6 != nullptr )
      BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v6);
    else
      BufferType = DMELEMENT_HANDLE_INVALID;
    CDmeHandle<CDmeCombinationOperator,0>::Set(this: &this->m_hCombinationOperator, h: BufferType);
    CDmeCombinationDominationRulesPanel::RefreshCombinationOperator(this, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004732E0
// Name: public: void CDmeCombinationSystemEditorFrame::SetCombinationOperator(class CDmeCombinationOperator __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeCombinationSystemEditorFrame::SetCombinationOperator(
        CDmeCombinationSystemEditorFrame *this@<ecx>,
        int a2@<ebx>,
        CDmeCombinationOperator *pComboSystem)
{
  CDmeCombinationSystemEditorPanel *m_pEditor; // edi

  m_pEditor = this->m_pEditor;
  CDmeCombinationControlsPanel::SetCombinationOperator(this: m_pEditor->m_pControlsPanel, a2, pOp: pComboSystem);
  CDmeCombinationDominationRulesPanel::SetCombinationOperator(
    this: m_pEditor->m_pDominationRulesPanel,
    a2,
    pOp: pComboSystem);
  if ( pComboSystem != nullptr )
    CDmeElementPanel::SetDmeElement(this: m_pEditor->m_pPropertiesPanel, pElement: &pComboSystem->CDmElement);
  else
    CDmeElementPanel::SetDmeElement(this: m_pEditor->m_pPropertiesPanel, pElement: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0046F080
// Name: class CDmeCombinationDominationRule __near * GetElementKeyValue<class CDmeCombinationDominationRule>(class KeyValues __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationDominationRule *__cdecl GetElementKeyValue<CDmeCombinationDominationRule>(
        KeyValues *pKeyValues,
        const char *pName)
{
  int Int; // eax
  int v3; // eax
  int v4; // esi

  Int = KeyValues::GetInt(this: pKeyValues, keyName: pName, defaultValue: -1);
  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: Int);
  v4 = v3;
  if ( v3 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
         a1: v3,
         a2: CDmeCombinationDominationRule::m_classType.u) != 0 )
  {
    return (CDmeCombinationDominationRule *)v4;
  }
  else
  {
    return nullptr;
  }
}
