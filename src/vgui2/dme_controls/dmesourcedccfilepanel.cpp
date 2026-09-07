// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/dmesourcedccfilepanel.cpp
// Functions: 27
// ============================================================

#include "vgui2\dme_controls\dmesourcedccfilepanel.h"

//------------------------------------------------------------------------------
// Address: 0x00468E10
// Name: private: void CDmeSourceDCCFilePanel::SetDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::SetDirty(CDmeSourceSkinPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "DmeElementChanged");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477490
// Name: public: static char const __near * CDmeSourceDCCFilePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeSourceDCCFilePanel::GetPanelClassName()
{
  return "CDmeSourceDCCFilePanel";
}

//------------------------------------------------------------------------------
// Address: 0x004774A0
// Name: DccObjectSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl DccObjectSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *String; // esi
  const char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "dccobject", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "dccobject", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004774E0
// Name: private: void CDmeSourceDCCFilePanel::OnItemSelectionChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnItemSelectionChanged(CDmeSourceDCCFilePanel *this)
{
  bool v2; // bl
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // eax
  vgui::TextEntry_vtbl *v8; // edi
  const char *String; // eax
  bool bMultiselect; // [esp+Fh] [ebp-1h]

  v3 = this->m_pRootDCCObjects->GetSelectedItemsCount(this: this->m_pRootDCCObjects);
  v2 = v3 > 0;
  LOBYTE(v3) = v3 > 1;
  bMultiselect = v3;
  LOBYTE(v3) = v2 && (_BYTE)v3 == 0;
  v4 = ((int (__thiscall *)(vgui::Button *, int))this->m_pDCCObjectBrowser->SetEnabled)(
         a1: this->m_pDCCObjectBrowser,
         a2: v3);
  LOBYTE(v4) = v2 && !bMultiselect;
  v5 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pDCCObjectName->SetEnabled)(
         a1: this->m_pDCCObjectName,
         a2: v4);
  LOBYTE(v5) = v2 && !bMultiselect;
  this->m_pApplyChanges->SetEnabled(this: this->m_pApplyChanges, a2: v5);
  this->m_pRemoveDCCObject->SetEnabled(this: this->m_pRemoveDCCObject, a2: v2);
  if ( !v2 || bMultiselect )
  {
    this->m_pDCCObjectName->SetText(this: this->m_pDCCObjectName, a2: defaultValue);
  }
  else
  {
    v6 = this->m_pRootDCCObjects->GetSelectedItem(this: this->m_pRootDCCObjects, a2: 0);
    v7 = this->m_pRootDCCObjects->GetItem(this: this->m_pRootDCCObjects, a2: v6);
    v8 = this->m_pDCCObjectName->__vftable;
    String = KeyValues::GetString(this: v7, keyName: "dccobject", defaultValue: defaultValue);
    v8->SetText(this: this->m_pDCCObjectName, a2: String);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477600
// Name: private: virtual void CDmeSourceDCCFilePanel::OnItemDeselected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnItemDeselected(CDmeSourceDCCFilePanel *this, KeyValues *kv)
{
  if ( KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pRootDCCObjects )
    CDmeSourceDCCFilePanel::OnItemSelectionChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x00477630
// Name: private: void CDmeSourceDCCFilePanel::SelectDCCObject(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeSourceDCCFilePanel::SelectDCCObject(
        CDmeSourceDCCFilePanel *this@<ecx>,
        int a2@<esi>,
        int nDCCObjectIndex)
{
  vgui::ListPanel_vtbl *v4; // eax
  int v5; // esi
  KeyValues *v6; // eax
  bool v7; // zf
  vgui::ListPanel_vtbl *v8; // eax

  v4 = this->m_pRootDCCObjects->__vftable;
  if ( nDCCObjectIndex >= 0 )
  {
    v5 = ((int (*)(void))v4->FirstItem)();
    if ( v5 != this->m_pRootDCCObjects->InvalidItemID(this: this->m_pRootDCCObjects) )
    {
      while ( 1 )
      {
        v6 = (KeyValues *)((int (__thiscall *)(vgui::ListPanel *, int, int))this->m_pRootDCCObjects->GetItem)(
                            a1: this->m_pRootDCCObjects,
                            a2: v5,
                            a3: a2);
        v7 = KeyValues::GetInt(this: v6, keyName: "dccObjectIndex", defaultValue: -1) == nDCCObjectIndex;
        v8 = this->m_pRootDCCObjects->__vftable;
        a2 = v5;
        if ( v7 )
          break;
        v5 = ((int (*)(void))v8->NextItem)();
        if ( v5 == this->m_pRootDCCObjects->InvalidItemID(this: this->m_pRootDCCObjects) )
          return;
      }
      ((void (*)(void))v8->SetSingleSelectedItem)();
    }
  }
  else
  {
    ((void (*)(void))v4->ClearSelectedItems)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x004776E0
// Name: IntCompare
// Source: json
//------------------------------------------------------------------------------
int __cdecl IntCompare(_DWORD *pSrc1, _DWORD *pSrc2)
{
  return *pSrc1 - *pSrc2;
}

//------------------------------------------------------------------------------
// Address: 0x004777A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeSourceDCCFilePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeSourceDCCFilePanel::GetMessageMap(CDmeSourceDCCFilePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeSourceDCCFilePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeSourceDCCFilePanel::GetMessageMap'::`2'::s_pMap;
  `CDmeSourceDCCFilePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeSourceDCCFilePanel");
  `CDmeSourceDCCFilePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004777D0
// Name: public: virtual struct PanelAnimationMap __near * CDmeSourceDCCFilePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeSourceDCCFilePanel::GetAnimMap(CDmeSourceDCCFilePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeSourceDCCFilePanel");
}

//------------------------------------------------------------------------------
// Address: 0x004777E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeSourceDCCFilePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeSourceDCCFilePanel::GetKBMap(CDmeSourceDCCFilePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeSourceDCCFilePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeSourceDCCFilePanel::GetKBMap'::`2'::s_pMap;
  `CDmeSourceDCCFilePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeSourceDCCFilePanel");
  `CDmeSourceDCCFilePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00477810
// Name: private: void CDmeSourceDCCFilePanel::OnAddDCCObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnAddDCCObject(CDmeSourceDCCFilePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  vgui::InputDialog *v4; // eax
  vgui::InputDialog *v5; // esi

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle) != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "AddDCCObject");
    else
      v3 = nullptr;
    v4 = (vgui::InputDialog *)MemAlloc_Alloc(nSize: 0x22Cu);
    if ( v4 != nullptr )
    {
      v5 = vgui::InputDialog::InputDialog(
             this: v4,
             parent: this,
             title: "Add DCC Object",
             prompt: "Enter DCC object name to add",
             defaultValue: defaultValue);
      vgui::InputDialog::SetMultiline(this: v5, state: false);
      vgui::BaseInputDialog::DoModal(this: v5, pContextKeyValues: v3);
    }
    else
    {
      vgui::InputDialog::SetMultiline(this: nullptr, state: false);
      vgui::BaseInputDialog::DoModal(this: nullptr, pContextKeyValues: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004778A0
// Name: private: void CDmeSourceDCCFilePanel::OnBrowseDCCObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnBrowseDCCObject(CDmeSourceDCCFilePanel *this)
{
  int v2; // eax
  KeyValues *v3; // eax
  int Int; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  vgui::InputDialog *v7; // eax
  vgui::InputDialog *v8; // esi

  if ( this->m_pRootDCCObjects->GetSelectedItemsCount(this: this->m_pRootDCCObjects) != 0
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle) != nullptr )
  {
    v2 = this->m_pRootDCCObjects->GetSelectedItem(this: this->m_pRootDCCObjects, a2: 0);
    v3 = this->m_pRootDCCObjects->GetItem(this: this->m_pRootDCCObjects, a2: v2);
    Int = KeyValues::GetInt(this: v3, keyName: "dccObjectIndex", defaultValue: -1);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "ChangeDCCObject", firstKey: "dccObjectIndex", firstValue: Int);
    else
      v6 = nullptr;
    v7 = (vgui::InputDialog *)MemAlloc_Alloc(nSize: 0x22Cu);
    if ( v7 != nullptr )
    {
      v8 = vgui::InputDialog::InputDialog(
             this: v7,
             parent: this,
             title: "Edit Maya/XSI Object",
             prompt: "Enter new name of Maya/XSI object",
             defaultValue: defaultValue);
      vgui::InputDialog::SetMultiline(this: v8, state: false);
      vgui::BaseInputDialog::DoModal(this: v8, pContextKeyValues: v6);
    }
    else
    {
      vgui::InputDialog::SetMultiline(this: nullptr, state: false);
      vgui::BaseInputDialog::DoModal(this: nullptr, pContextKeyValues: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004779E0
// Name: private: void CDmeSourceDCCFilePanel::RefreshDCCObjectList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::RefreshDCCObjectList(CDmeSourceDCCFilePanel *this)
{
  int v2; // esi
  KeyValues *v3; // edi
  const char *v4; // eax
  KeyValues *v5; // edi
  int nCount; // [esp+4h] [ebp-4h]

  this->m_pRootDCCObjects->RemoveAll(this: this->m_pRootDCCObjects);
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle) != nullptr )
  {
    v2 = 0;
    nCount = *(_DWORD *)&g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle)[1].m_Id.m_Value[12];
    if ( nCount > 0 )
    {
      do
      {
        v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v3 != nullptr )
        {
          v4 = *(const char **)(*(_DWORD *)g_pDataModel->GetElement(
                                             this: g_pDataModel,
                                             a2: this->m_hSourceDCCFile.m_handle)[1].m_Id.m_Value
                              + 4 * v2);
          if ( v4 == (const char *)-1 )
            v4 = defaultValue;
          v5 = KeyValues::KeyValues(this: v3, setName: "node", firstKey: "dccobject", firstValue: v4);
        }
        else
        {
          v5 = nullptr;
        }
        KeyValues::SetInt(this: v5, keyName: "dccObjectIndex", value: v2);
        this->m_pRootDCCObjects->AddItem(this: this->m_pRootDCCObjects, a2: v5, a3: 0, a4: false, a5: false);
        ++v2;
      }
      while ( v2 < nCount );
    }
    this->m_pRootDCCObjects->SortList(this: this->m_pRootDCCObjects);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477AD0
// Name: public: void CDmeSourceDCCFilePanel::SetDmeElement(class CDmeSourceDCCFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::SetDmeElement(
        CDmeSourceDCCFilePanel *this,
        CExpressionCalculator *pSourceDCCFile)
{
  CExpressionCalculator *v2; // edi
  DmElementHandle_t BufferType; // eax

  v2 = pSourceDCCFile;
  if ( pSourceDCCFile != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: pSourceDCCFile);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeSourceDCCFile,0>::Set(this: &this->m_hSourceDCCFile, h: BufferType);
  LOBYTE(pSourceDCCFile) = pSourceDCCFile != nullptr;
  this->m_pDCCObjectBrowser->SetEnabled(this: this->m_pDCCObjectBrowser, a2: (bool)pSourceDCCFile);
  this->m_pAddDCCObject->SetEnabled(this: this->m_pAddDCCObject, a2: (bool)pSourceDCCFile);
  this->m_pRemoveDCCObject->SetEnabled(this: this->m_pRemoveDCCObject, a2: (bool)pSourceDCCFile);
  this->m_pApplyChanges->SetEnabled(this: this->m_pApplyChanges, a2: (bool)pSourceDCCFile);
  if ( v2 != nullptr )
  {
    CDmeSourceDCCFilePanel::RefreshDCCObjectList(this);
  }
  else
  {
    this->m_pRootDCCObjects->RemoveAll(this: this->m_pRootDCCObjects);
    this->m_pDCCObjectName->SetText(this: this->m_pDCCObjectName, a2: defaultValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477B90
// Name: private: bool CDmeSourceDCCFilePanel::CheckForDuplicateNames(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSourceDCCFilePanel::CheckForDuplicateNames(
        CDmeSourceDCCFilePanel *this,
        const char *pDCCObjectName,
        int nDCCObjectSkipIndex)
{
  int v4; // ebx
  int v5; // esi
  const char *v6; // eax
  vgui::MessageBox *v8; // esi
  vgui::Panel *v9; // eax
  vgui::MessageBox *v10; // eax

  if ( *pDCCObjectName == 0 )
    return 0;
  v4 = *(_DWORD *)&g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle)[1].m_Id.m_Value[12];
  v5 = 0;
  if ( v4 <= 0 )
    return 0;
  while ( 1 )
  {
    if ( v5 != nDCCObjectSkipIndex )
    {
      v6 = *(const char **)(*(_DWORD *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle)[1].m_Id.m_Value
                          + 4 * v5);
      if ( v6 == (const char *)-1 )
        v6 = defaultValue;
      if ( _V_stricmp(s1: pDCCObjectName, s2: v6) == 0 )
        break;
    }
    if ( ++v5 >= v4 )
      return 0;
  }
  v8 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
  if ( v8 != nullptr )
  {
    v9 = this->GetParent(this);
    v10 = vgui::MessageBox::MessageBox(
            this: v8,
            title: "#DmeSourceDCCFile_DuplicateSourceTitle",
            text: "#DmeSourceDCCFile_DuplicateSourceText",
            parent: v9);
  }
  else
  {
    v10 = nullptr;
  }
  v10->DoModal_2(this: v10, a2: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00477C60
// Name: private: void CDmeSourceDCCFilePanel::OnDCCObjectNameChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeSourceDCCFilePanel::OnDCCObjectNameChanged(
        CDmeSourceDCCFilePanel *this@<ecx>,
        const char *a2@<edi>)
{
  int v3; // ebx
  int Int; // edi
  CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *v5; // eax
  char pDCCObjectName[260]; // [esp+4h] [ebp-110h] BYREF
  CDisableUndoScopeGuard guard; // [esp+108h] [ebp-Ch] BYREF
  KeyValues *pKeyValues; // [esp+110h] [ebp-4h]

  if ( this->m_pRootDCCObjects->GetSelectedItemsCount(this: this->m_pRootDCCObjects) != 0
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle) != nullptr )
  {
    v3 = this->m_pRootDCCObjects->GetSelectedItem(this: this->m_pRootDCCObjects, a2: 0);
    pKeyValues = this->m_pRootDCCObjects->GetItem(this: this->m_pRootDCCObjects, a2: v3);
    Int = KeyValues::GetInt(this: pKeyValues, keyName: "dccObjectIndex", defaultValue: -1);
    if ( Int >= 0 )
    {
      this->m_pDCCObjectName->GetText_2(this: this->m_pDCCObjectName, a2: pDCCObjectName, a3: 260);
      if ( CDmeSourceDCCFilePanel::CheckForDuplicateNames(this, pDCCObjectName, nDCCObjectSkipIndex: Int) == 0 )
      {
        CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: &guard);
        v5 = (CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(a1: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle, a3: Int);
        CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::Set(
          this: v5 + 3,
          i: (int)pDCCObjectName,
          pValue: a2);
        CChangeUndoScopeGuard::Release(this: &guard);
        KeyValues::SetString(this: pKeyValues, keyName: "dccobject", value: pDCCObjectName);
        this->m_pRootDCCObjects->ApplyItemChanges(this: this->m_pRootDCCObjects, a2: v3);
        this->m_pRootDCCObjects->SortList(this: this->m_pRootDCCObjects);
        CDmeSourceDCCFilePanel::SetDirty((CDmeSourceSkinPanel *)this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477D90
// Name: private: void CDmeSourceDCCFilePanel::OnRemoveDCCObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnRemoveDCCObject(CDmeSourceDCCFilePanel *this)
{
  int v2; // edi
  unsigned int v3; // ebx
  void *v4; // esp
  int v5; // edi
  int v6; // eax
  KeyValues *v7; // eax
  int Int; // eax
  int v9; // eax
  int v10; // eax
  IDataModel_vtbl *v11; // edx
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // eax
  bool v13; // al
  IDataModel_vtbl *v14; // edx
  int i; // edi
  CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // [esp+0h] [ebp-1Ch] BYREF
  CDisableUndoScopeGuard guard; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  int *pDCCObjectIndex; // [esp+18h] [ebp-4h]

  v2 = this->m_pRootDCCObjects->GetSelectedItemsCount(this: this->m_pRootDCCObjects);
  nCount = v2;
  if ( v2 != 0 && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle) != nullptr )
  {
    v3 = 0;
    v4 = alloca(4 * v2);
    v5 = 0;
    pDCCObjectIndex = &v21;
    if ( nCount > 0 )
    {
      do
      {
        v6 = this->m_pRootDCCObjects->GetSelectedItem(this: this->m_pRootDCCObjects, a2: v5);
        v7 = this->m_pRootDCCObjects->GetItem(this: this->m_pRootDCCObjects, a2: v6);
        Int = KeyValues::GetInt(this: v7, keyName: "dccObjectIndex", defaultValue: -1);
        if ( Int >= 0 )
          pDCCObjectIndex[v3++] = Int;
        ++v5;
      }
      while ( v5 < nCount );
      if ( v3 != 0 )
      {
        qsort(base: pDCCObjectIndex, num: v3, width: 4u, comp: (int (__cdecl *)(const void *, const void *))IntCompare);
        v9 = this->m_pRootDCCObjects->GetSelectedItem(this: this->m_pRootDCCObjects, a2: 0);
        v10 = this->m_pRootDCCObjects->GetItemCurrentRow(this: this->m_pRootDCCObjects, a2: v9);
        v11 = g_pDataModel->__vftable;
        nCount = v10;
        IsUndoEnabled = v11->IsUndoEnabled;
        *(_WORD *)&guard.m_bReleased = 0;
        guard.m_pNotify = nullptr;
        v13 = IsUndoEnabled(this: g_pDataModel);
        v14 = g_pDataModel->__vftable;
        guard.m_bOldValue = v13;
        v14->SetUndoEnabled(this: g_pDataModel, a2: false);
        for ( i = v3 - 1; i >= 0; --i )
        {
          v16 = (CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle);
          CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::Remove(
            this: v16 + 3,
            elem: pDCCObjectIndex[i]);
        }
        v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v17 != nullptr )
          v18 = KeyValues::KeyValues(this: v17, setName: "DmeElementChanged");
        else
          v18 = nullptr;
        this->PostActionSignal(this, a2: v18);
        CChangeUndoScopeGuard::Release(this: &guard);
        CDmeSourceDCCFilePanel::RefreshDCCObjectList(this);
        v19 = this->m_pRootDCCObjects->GetItemCount(this: this->m_pRootDCCObjects);
        if ( v19 != 0 )
        {
          if ( nCount >= v19 )
            nCount = v19 - 1;
          v20 = this->m_pRootDCCObjects->GetItemIDFromRow(this: this->m_pRootDCCObjects, a2: nCount);
          this->m_pRootDCCObjects->SetSingleSelectedItem(this: this->m_pRootDCCObjects, a2: v20);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00477F60
// Name: public: virtual void CDmeSourceDCCFilePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnKeyCodeTyped(CDmeSourceDCCFilePanel *this, ButtonCode_t code)
{
  if ( code == KEY_DELETE )
    CDmeSourceDCCFilePanel::OnRemoveDCCObject(this);
  else
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x00477F80
// Name: public: virtual void CDmeSourceDCCFilePanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnCommand(CDmeSourceDCCFilePanel *this, const char *pCommand)
{
  if ( _V_stricmp(s1: pCommand, s2: "OnBrowseDCCObject") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnAddDCCObject") != 0 )
    {
      if ( _V_stricmp(s1: pCommand, s2: "OnRemoveDCCObject") != 0 )
      {
        if ( _V_stricmp(s1: pCommand, s2: "OnApplyChanges") != 0 )
          vgui::Panel::OnCommand(this, command: pCommand);
        else
          CDmeSourceDCCFilePanel::OnDCCObjectNameChanged(this, a2: (const char *)this);
      }
      else
      {
        CDmeSourceDCCFilePanel::OnRemoveDCCObject(this);
      }
    }
    else
    {
      CDmeSourceDCCFilePanel::OnAddDCCObject(this);
    }
  }
  else
  {
    CDmeSourceDCCFilePanel::OnBrowseDCCObject(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478040
// Name: private: virtual void CDmeSourceDCCFilePanel::OnTextNewLine(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeSourceDCCFilePanel::OnTextNewLine(
        CDmeSourceDCCFilePanel *this@<ecx>,
        const char *a2@<edi>,
        KeyValues *kv)
{
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle) != nullptr
    && KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pDCCObjectName )
  {
    CDmeSourceDCCFilePanel::OnDCCObjectNameChanged(this, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478090
// Name: private: void CDmeSourceDCCFilePanel::OnDCCObjectAdded(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeSourceDCCFilePanel::OnDCCObjectAdded(
        CDmeSourceDCCFilePanel *this@<ecx>,
        int a2@<edi>,
        const char *pDCCObjectName,
        KeyValues *pContextKeys)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // eax
  char v6; // al
  IDataModel_vtbl *v7; // edx
  CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *v8; // edi
  int v9; // edi
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  CDisableUndoScopeGuard guard; // [esp+4h] [ebp-8h] BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle) != nullptr
    && CDmeSourceDCCFilePanel::CheckForDuplicateNames(this, pDCCObjectName, nDCCObjectSkipIndex: -1) == 0 )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    *(_WORD *)&guard.m_bReleased = 0;
    guard.m_pNotify = nullptr;
    v6 = ((int (__thiscall *)(IDataModel *, int))IsUndoEnabled)(a1: g_pDataModel, a2);
    v7 = g_pDataModel->__vftable;
    guard.m_bOldValue = v6;
    v7->SetUndoEnabled(this: g_pDataModel, a2: false);
    v8 = (CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pDCCObjectName, a3: pDCCObjectName);
    v9 = CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::AddToTail(
           this: v8 + 3,
           src: (vgui::PageTab **)&pDCCObjectName);
    CChangeUndoScopeGuard::Release(this: &guard);
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "DmeElementChanged");
    else
      v11 = nullptr;
    this->PostActionSignal(this, a2: v11);
    CDmeSourceDCCFilePanel::RefreshDCCObjectList(this);
    CDmeSourceDCCFilePanel::SelectDCCObject(this, a2: (int)this, nDCCObjectIndex: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478190
// Name: private: virtual void CDmeSourceDCCFilePanel::OnInputCompleted(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnInputCompleted(CDmeSourceDCCFilePanel *this, KeyValues *kv)
{
  const char *String; // esi
  KeyValues *Key; // eax

  String = KeyValues::GetString(this: kv, keyName: "text", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( KeyValues::FindKey(this: kv, keyName: "ChangeDCCObject", bCreate: false) != nullptr )
    {
      this->m_pDCCObjectName->SetText(this: this->m_pDCCObjectName, a2: String);
      CDmeSourceDCCFilePanel::OnDCCObjectNameChanged(this, a2: (const char *)this);
    }
    else
    {
      Key = KeyValues::FindKey(this: kv, keyName: "AddDCCObject", bCreate: false);
      if ( Key != nullptr )
        CDmeSourceDCCFilePanel::OnDCCObjectAdded(this, a2: (int)this, pDCCObjectName: String, pContextKeys: Key);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00478210
// Name: public: static void CDmeSourceDCCFilePanel::PanelMessageFunc_OnTextNewLine::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeSourceDCCFilePanel::PanelMessageFunc_OnTextNewLine::InitVar(int a1@<ebp>)
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
  if ( !`CDmeSourceDCCFilePanel::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded )
  {
    `CDmeSourceDCCFilePanel::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeSourceDCCFilePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextNewLine";
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
// Address: 0x004782A0
// Name: public: static void CDmeSourceDCCFilePanel::PanelMessageFunc_OnInputCompleted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeSourceDCCFilePanel::PanelMessageFunc_OnInputCompleted::InitVar(int a1@<ebp>)
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
  if ( !`CDmeSourceDCCFilePanel::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded )
  {
    `CDmeSourceDCCFilePanel::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeSourceDCCFilePanel");
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
// Address: 0x00478330
// Name: public: static void CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeSourceDCCFilePanel");
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
// Address: 0x004783C0
// Name: public: static void CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemDeselected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded )
  {
    `CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeSourceDCCFilePanel");
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
// Address: 0x00478450
// Name: public: CDmeSourceDCCFilePanel::CDmeSourceDCCFilePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSourceDCCFilePanel *__thiscall CDmeSourceDCCFilePanel::CDmeSourceDCCFilePanel(
        CDmeSourceDCCFilePanel *this,
        vgui::Panel *pParent,
        const char *pPanelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ListPanel *v7; // eax
  vgui::ListPanel *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CDmeSourceDCCFilePanel_vtbl *)&CDmeSourceDCCFilePanel::`vftable';
  if ( `CDmeSourceDCCFilePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeSourceDCCFilePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeSourceDCCFilePanel");
    v4->pfnClassName = CDmeSourceDCCFilePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CDmeSourceDCCFilePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeSourceDCCFilePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeSourceDCCFilePanel");
    v5->pfnClassName = CDmeSourceDCCFilePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CDmeSourceDCCFilePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeSourceDCCFilePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeSourceDCCFilePanel");
    v6->pfnClassName = CDmeSourceDCCFilePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  CDmeSourceDCCFilePanel::PanelMessageFunc_OnTextNewLine::InitVar(a1: (int)&savedregs);
  CDmeSourceDCCFilePanel::PanelMessageFunc_OnInputCompleted::InitVar(a1: (int)&savedregs);
  CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemDeselected::InitVar(a1: (int)&savedregs);
  this->m_hSourceDCCFile.m_handle = DMELEMENT_HANDLE_INVALID;
  v7 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v7 != nullptr )
    v8 = vgui::ListPanel::ListPanel(this: v7, parent: this, panelName: "DCCObjectList");
  else
    v8 = nullptr;
  this->m_pRootDCCObjects = v8;
  v8->AddColumnHeader(this: v8, a2: 0, a3: "dccobject", a4: "Maya/XSI Object Name", a5: 100, a6: 0);
  this->m_pRootDCCObjects->AddActionSignalTarget_2(this: this->m_pRootDCCObjects, a2: this);
  this->m_pRootDCCObjects->SetSortFunc(this: this->m_pRootDCCObjects, a2: 0, a3: DccObjectSortFunc);
  this->m_pRootDCCObjects->SetSortColumn(this: this->m_pRootDCCObjects, a2: 0);
  this->m_pRootDCCObjects->SetEmptyListText_2(this: this->m_pRootDCCObjects, a2: "No sources");
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "DCCObjectBrowser",
            text: "...",
            pActionSignalTarget: this,
            pCmd: "OnBrowseDCCObject");
  else
    v10 = nullptr;
  this->m_pDCCObjectBrowser = v10;
  v11 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: "DCCObjectName");
  else
    v12 = nullptr;
  this->m_pDCCObjectName = v12;
  v12->SendNewLine(this: v12, a2: true);
  this->m_pDCCObjectName->AddActionSignalTarget_2(this: this->m_pDCCObjectName, a2: this);
  v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "AddDCCObjectButton",
            text: "Add",
            pActionSignalTarget: this,
            pCmd: "OnAddDCCObject");
  else
    v14 = nullptr;
  this->m_pAddDCCObject = v14;
  v15 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v15 != nullptr )
    v16 = vgui::Button::Button(
            this: v15,
            parent: this,
            panelName: "RemoveDCCObjectButton",
            text: "Remove",
            pActionSignalTarget: this,
            pCmd: "OnRemoveDCCObject");
  else
    v16 = nullptr;
  this->m_pRemoveDCCObject = v16;
  v17 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v17 != nullptr )
    v18 = vgui::Button::Button(
            this: v17,
            parent: this,
            panelName: "ApplyChangesButton",
            text: "Apply",
            pActionSignalTarget: this,
            pCmd: "OnApplyChanges");
  else
    v18 = nullptr;
  this->m_pApplyChanges = v18;
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/DmeSourceDCCFilePanel.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1047D1B0
// Name: public: static char const __near * CDmeSourceDCCFilePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeSourceDCCFilePanel::GetPanelClassName()
{
  return "CDmeSourceDCCFilePanel";
}

//------------------------------------------------------------------------------
// Address: 0x1047D1C0
// Name: DccObjectSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl DccObjectSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  char *String; // esi
  char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "dccobject", defaultValue: &var);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "dccobject", defaultValue: &var);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1047D200
// Name: private: void CDmeSourceDCCFilePanel::SetDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::SetDirty(CDmeSourceSkinPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "DmeElementChanged");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047D240
// Name: private: void CDmeSourceDCCFilePanel::OnItemSelectionChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnItemSelectionChanged(CDmeSourceDCCFilePanel *this)
{
  bool v2; // bl
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // eax
  vgui::TextEntry_vtbl *v8; // edi
  char *String; // eax
  bool bMultiselect; // [esp+Fh] [ebp-1h]

  v3 = this->m_pRootDCCObjects->GetSelectedItemsCount(this: this->m_pRootDCCObjects);
  v2 = v3 > 0;
  LOBYTE(v3) = v3 > 1;
  bMultiselect = v3;
  LOBYTE(v3) = v2 && (_BYTE)v3 == 0;
  v4 = ((int (__thiscall *)(vgui::Button *, int))this->m_pDCCObjectBrowser->SetEnabled)(
         a1: this->m_pDCCObjectBrowser,
         a2: v3);
  LOBYTE(v4) = v2 && !bMultiselect;
  v5 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pDCCObjectName->SetEnabled)(
         a1: this->m_pDCCObjectName,
         a2: v4);
  LOBYTE(v5) = v2 && !bMultiselect;
  this->m_pApplyChanges->SetEnabled(this: this->m_pApplyChanges, a2: v5);
  this->m_pRemoveDCCObject->SetEnabled(this: this->m_pRemoveDCCObject, a2: v2);
  if ( !v2 || bMultiselect )
  {
    this->m_pDCCObjectName->SetText(this: this->m_pDCCObjectName, a2: &var);
  }
  else
  {
    v6 = this->m_pRootDCCObjects->GetSelectedItem(this: this->m_pRootDCCObjects, a2: 0);
    v7 = this->m_pRootDCCObjects->GetItem(this: this->m_pRootDCCObjects, a2: v6);
    v8 = this->m_pDCCObjectName->__vftable;
    String = KeyValues::GetString(this: v7, keyName: "dccobject", defaultValue: &var);
    v8->SetText(this: this->m_pDCCObjectName, a2: String);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047D360
// Name: private: virtual void CDmeSourceDCCFilePanel::OnItemDeselected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnItemDeselected(CDmeSourceDCCFilePanel *this, KeyValues *kv)
{
  if ( KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pRootDCCObjects )
    CDmeSourceDCCFilePanel::OnItemSelectionChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x1047D390
// Name: private: void CDmeSourceDCCFilePanel::SelectDCCObject(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeSourceDCCFilePanel::SelectDCCObject(
        CDmeSourceDCCFilePanel *this@<ecx>,
        int a2@<esi>,
        int nDCCObjectIndex)
{
  vgui::ListPanel_vtbl *v4; // eax
  int v5; // esi
  KeyValues *v6; // eax
  bool v7; // zf
  vgui::ListPanel_vtbl *v8; // eax

  v4 = this->m_pRootDCCObjects->__vftable;
  if ( nDCCObjectIndex >= 0 )
  {
    v5 = ((int (*)(void))v4->FirstItem)();
    if ( v5 != this->m_pRootDCCObjects->InvalidItemID(this: this->m_pRootDCCObjects) )
    {
      while ( 1 )
      {
        v6 = (KeyValues *)((int (__thiscall *)(vgui::ListPanel *, int, int))this->m_pRootDCCObjects->GetItem)(
                            a1: this->m_pRootDCCObjects,
                            a2: v5,
                            a3: a2);
        v7 = KeyValues::GetInt(this: v6, keyName: "dccObjectIndex", defaultValue: -1) == nDCCObjectIndex;
        v8 = this->m_pRootDCCObjects->__vftable;
        a2 = v5;
        if ( v7 )
          break;
        v5 = ((int (*)(void))v8->NextItem)();
        if ( v5 == this->m_pRootDCCObjects->InvalidItemID(this: this->m_pRootDCCObjects) )
          return;
      }
      ((void (*)(void))v8->SetSingleSelectedItem)();
    }
  }
  else
  {
    ((void (*)(void))v4->ClearSelectedItems)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047D440
// Name: IntCompare
// Source: json
//------------------------------------------------------------------------------
int __cdecl IntCompare(_DWORD *pSrc1, _DWORD *pSrc2)
{
  return *pSrc1 - *pSrc2;
}

//------------------------------------------------------------------------------
// Address: 0x1047D500
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeSourceDCCFilePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeSourceDCCFilePanel::GetMessageMap(CDmeSourceDCCFilePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeSourceDCCFilePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeSourceDCCFilePanel::GetMessageMap'::`2'::s_pMap;
  `CDmeSourceDCCFilePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeSourceDCCFilePanel");
  `CDmeSourceDCCFilePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1047D530
// Name: public: virtual struct PanelAnimationMap __near * CDmeSourceDCCFilePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeSourceDCCFilePanel::GetAnimMap(CDmeSourceDCCFilePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeSourceDCCFilePanel");
}

//------------------------------------------------------------------------------
// Address: 0x1047D540
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeSourceDCCFilePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeSourceDCCFilePanel::GetKBMap(CDmeSourceDCCFilePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeSourceDCCFilePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeSourceDCCFilePanel::GetKBMap'::`2'::s_pMap;
  `CDmeSourceDCCFilePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeSourceDCCFilePanel");
  `CDmeSourceDCCFilePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1047D570
// Name: private: void CDmeSourceDCCFilePanel::OnAddDCCObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnAddDCCObject(CDmeSourceDCCFilePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  vgui::InputDialog *v4; // eax
  vgui::InputDialog *v5; // esi

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle) != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "AddDCCObject");
    else
      v3 = nullptr;
    v4 = (vgui::InputDialog *)operator new(nSize: 0x22Cu);
    if ( v4 != nullptr )
    {
      v5 = vgui::InputDialog::InputDialog(
             this: v4,
             parent: this,
             title: "Add DCC Object",
             prompt: "Enter DCC object name to add",
             defaultValue: &var);
      vgui::InputDialog::SetMultiline(this: v5, state: false);
      vgui::BaseInputDialog::DoModal(this: v5, pContextKeyValues: v3);
    }
    else
    {
      vgui::InputDialog::SetMultiline(this: nullptr, state: false);
      vgui::BaseInputDialog::DoModal(this: nullptr, pContextKeyValues: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047D600
// Name: private: void CDmeSourceDCCFilePanel::OnBrowseDCCObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnBrowseDCCObject(CDmeSourceDCCFilePanel *this)
{
  int v2; // eax
  KeyValues *v3; // eax
  int Int; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  vgui::InputDialog *v7; // eax
  vgui::InputDialog *v8; // esi

  if ( this->m_pRootDCCObjects->GetSelectedItemsCount(this: this->m_pRootDCCObjects) != 0
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle) != nullptr )
  {
    v2 = this->m_pRootDCCObjects->GetSelectedItem(this: this->m_pRootDCCObjects, a2: 0);
    v3 = this->m_pRootDCCObjects->GetItem(this: this->m_pRootDCCObjects, a2: v2);
    Int = KeyValues::GetInt(this: v3, keyName: "dccObjectIndex", defaultValue: -1);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "ChangeDCCObject", firstKey: "dccObjectIndex", firstValue: Int);
    else
      v6 = nullptr;
    v7 = (vgui::InputDialog *)operator new(nSize: 0x22Cu);
    if ( v7 != nullptr )
    {
      v8 = vgui::InputDialog::InputDialog(
             this: v7,
             parent: this,
             title: "Edit Maya/XSI Object",
             prompt: "Enter new name of Maya/XSI object",
             defaultValue: &var);
      vgui::InputDialog::SetMultiline(this: v8, state: false);
      vgui::BaseInputDialog::DoModal(this: v8, pContextKeyValues: v6);
    }
    else
    {
      vgui::InputDialog::SetMultiline(this: nullptr, state: false);
      vgui::BaseInputDialog::DoModal(this: nullptr, pContextKeyValues: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047D740
// Name: private: void CDmeSourceDCCFilePanel::RefreshDCCObjectList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::RefreshDCCObjectList(CDmeSourceDCCFilePanel *this)
{
  int v2; // esi
  KeyValues *v3; // edi
  char *v4; // eax
  KeyValues *v5; // edi
  int nCount; // [esp+4h] [ebp-4h]

  this->m_pRootDCCObjects->RemoveAll(this: this->m_pRootDCCObjects);
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle) != nullptr )
  {
    v2 = 0;
    nCount = *(_DWORD *)&g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle)[1].m_Id.m_Value[12];
    if ( nCount > 0 )
    {
      do
      {
        v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v3 != nullptr )
        {
          v4 = *(char **)(*(_DWORD *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle)[1].m_Id.m_Value
                        + 4 * v2);
          if ( v4 == (char *)-1 )
            v4 = (char *)&var;
          v5 = KeyValues::KeyValues(this: v3, setName: "node", firstKey: "dccobject", firstValue: v4);
        }
        else
        {
          v5 = nullptr;
        }
        KeyValues::SetInt(this: v5, keyName: "dccObjectIndex", value: v2);
        this->m_pRootDCCObjects->AddItem(this: this->m_pRootDCCObjects, a2: v5, a3: 0, a4: false, a5: false);
        ++v2;
      }
      while ( v2 < nCount );
    }
    this->m_pRootDCCObjects->SortList(this: this->m_pRootDCCObjects);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047D830
// Name: public: void CDmeSourceDCCFilePanel::SetDmeElement(class CDmeSourceDCCFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::SetDmeElement(
        CDmeSourceDCCFilePanel *this,
        CExpressionCalculator *pSourceDCCFile)
{
  CExpressionCalculator *v2; // edi
  DmElementHandle_t BufferType; // eax

  v2 = pSourceDCCFile;
  if ( pSourceDCCFile != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: pSourceDCCFile);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeSourceDCCFile,0>::Set(this: &this->m_hSourceDCCFile, h: BufferType);
  LOBYTE(pSourceDCCFile) = pSourceDCCFile != nullptr;
  this->m_pDCCObjectBrowser->SetEnabled(this: this->m_pDCCObjectBrowser, a2: (bool)pSourceDCCFile);
  this->m_pAddDCCObject->SetEnabled(this: this->m_pAddDCCObject, a2: (bool)pSourceDCCFile);
  this->m_pRemoveDCCObject->SetEnabled(this: this->m_pRemoveDCCObject, a2: (bool)pSourceDCCFile);
  this->m_pApplyChanges->SetEnabled(this: this->m_pApplyChanges, a2: (bool)pSourceDCCFile);
  if ( v2 != nullptr )
  {
    CDmeSourceDCCFilePanel::RefreshDCCObjectList(this);
  }
  else
  {
    this->m_pRootDCCObjects->RemoveAll(this: this->m_pRootDCCObjects);
    this->m_pDCCObjectName->SetText(this: this->m_pDCCObjectName, a2: &var);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047D8F0
// Name: private: bool CDmeSourceDCCFilePanel::CheckForDuplicateNames(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSourceDCCFilePanel::CheckForDuplicateNames(
        CDmeSourceDCCFilePanel *this,
        const char *pDCCObjectName,
        int nDCCObjectSkipIndex)
{
  int v4; // ebx
  int v5; // esi
  const char *v6; // eax
  vgui::MessageBox *v8; // esi
  vgui::Panel *v9; // eax
  vgui::MessageBox *v10; // eax

  if ( *pDCCObjectName == 0 )
    return 0;
  v4 = *(_DWORD *)&g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle)[1].m_Id.m_Value[12];
  v5 = 0;
  if ( v4 <= 0 )
    return 0;
  while ( 1 )
  {
    if ( v5 != nDCCObjectSkipIndex )
    {
      v6 = *(const char **)(*(_DWORD *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle)[1].m_Id.m_Value
                          + 4 * v5);
      if ( v6 == (const char *)-1 )
        v6 = &var;
      if ( _V_stricmp(s1: pDCCObjectName, s2: v6) == 0 )
        break;
    }
    if ( ++v5 >= v4 )
      return 0;
  }
  v8 = (vgui::MessageBox *)operator new(nSize: 0x234u);
  if ( v8 != nullptr )
  {
    v9 = this->GetParent(this);
    v10 = vgui::MessageBox::MessageBox(
            this: v8,
            title: "#DmeSourceDCCFile_DuplicateSourceTitle",
            text: "#DmeSourceDCCFile_DuplicateSourceText",
            parent: v9);
  }
  else
  {
    v10 = nullptr;
  }
  v10->DoModal_2(this: v10, a2: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1047D9C0
// Name: private: void CDmeSourceDCCFilePanel::OnDCCObjectNameChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeSourceDCCFilePanel::OnDCCObjectNameChanged(
        CDmeSourceDCCFilePanel *this@<ecx>,
        const char *a2@<edi>)
{
  int v3; // ebx
  int Int; // edi
  CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *v5; // eax
  char pDCCObjectName[260]; // [esp+4h] [ebp-110h] BYREF
  CDisableUndoScopeGuard guard; // [esp+108h] [ebp-Ch] BYREF
  KeyValues *pKeyValues; // [esp+110h] [ebp-4h]

  if ( this->m_pRootDCCObjects->GetSelectedItemsCount(this: this->m_pRootDCCObjects) != 0
    && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle) != nullptr )
  {
    v3 = this->m_pRootDCCObjects->GetSelectedItem(this: this->m_pRootDCCObjects, a2: 0);
    pKeyValues = this->m_pRootDCCObjects->GetItem(this: this->m_pRootDCCObjects, a2: v3);
    Int = KeyValues::GetInt(this: pKeyValues, keyName: "dccObjectIndex", defaultValue: -1);
    if ( Int >= 0 )
    {
      this->m_pDCCObjectName->GetText_2(this: this->m_pDCCObjectName, a2: pDCCObjectName, a3: 260);
      if ( CDmeSourceDCCFilePanel::CheckForDuplicateNames(this, pDCCObjectName, nDCCObjectSkipIndex: Int) == 0 )
      {
        CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: &guard);
        v5 = (CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *)((int (__thiscall *)(IDataModel *, DmElementHandle_t, int))g_pDataModel->GetElement)(a1: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle, a3: Int);
        CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::Set(
          this: v5 + 3,
          i: (int)pDCCObjectName,
          pValue: a2);
        CChangeUndoScopeGuard::Release(this: &guard);
        KeyValues::SetString(this: pKeyValues, keyName: "dccobject", value: pDCCObjectName);
        this->m_pRootDCCObjects->ApplyItemChanges(this: this->m_pRootDCCObjects, a2: v3);
        this->m_pRootDCCObjects->SortList(this: this->m_pRootDCCObjects);
        CDmeSourceDCCFilePanel::SetDirty((CDmeSourceSkinPanel *)this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047DAF0
// Name: private: void CDmeSourceDCCFilePanel::OnRemoveDCCObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnRemoveDCCObject(CDmeSourceDCCFilePanel *this)
{
  int v2; // edi
  unsigned int v3; // ebx
  void *v4; // esp
  int v5; // edi
  int v6; // eax
  KeyValues *v7; // eax
  int Int; // eax
  int v9; // eax
  int v10; // eax
  IDataModel_vtbl *v11; // edx
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // eax
  bool v13; // al
  IDataModel_vtbl *v14; // edx
  int i; // edi
  CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // [esp+0h] [ebp-1Ch] BYREF
  CDisableUndoScopeGuard guard; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  int *pDCCObjectIndex; // [esp+18h] [ebp-4h]

  v2 = this->m_pRootDCCObjects->GetSelectedItemsCount(this: this->m_pRootDCCObjects);
  nCount = v2;
  if ( v2 != 0 && g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle) != nullptr )
  {
    v3 = 0;
    v4 = alloca(4 * v2);
    v5 = 0;
    pDCCObjectIndex = &v21;
    if ( nCount > 0 )
    {
      do
      {
        v6 = this->m_pRootDCCObjects->GetSelectedItem(this: this->m_pRootDCCObjects, a2: v5);
        v7 = this->m_pRootDCCObjects->GetItem(this: this->m_pRootDCCObjects, a2: v6);
        Int = KeyValues::GetInt(this: v7, keyName: "dccObjectIndex", defaultValue: -1);
        if ( Int >= 0 )
          pDCCObjectIndex[v3++] = Int;
        ++v5;
      }
      while ( v5 < nCount );
      if ( v3 != 0 )
      {
        qsort(
          base: (char *)pDCCObjectIndex,
          num: v3,
          width: 4u,
          comp: (int (__cdecl *)(const void *, const void *))IntCompare);
        v9 = this->m_pRootDCCObjects->GetSelectedItem(this: this->m_pRootDCCObjects, a2: 0);
        v10 = this->m_pRootDCCObjects->GetItemCurrentRow(this: this->m_pRootDCCObjects, a2: v9);
        v11 = g_pDataModel->__vftable;
        nCount = v10;
        IsUndoEnabled = v11->IsUndoEnabled;
        *(_WORD *)&guard.m_bReleased = 0;
        guard.m_pNotify = nullptr;
        v13 = IsUndoEnabled(this: g_pDataModel);
        v14 = g_pDataModel->__vftable;
        guard.m_bOldValue = v13;
        v14->SetUndoEnabled(this: g_pDataModel, a2: false);
        for ( i = v3 - 1; i >= 0; --i )
        {
          v16 = (CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle);
          CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::Remove(
            this: v16 + 3,
            elem: pDCCObjectIndex[i]);
        }
        v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v17 != nullptr )
          v18 = KeyValues::KeyValues(this: v17, setName: "DmeElementChanged");
        else
          v18 = nullptr;
        this->PostActionSignal(this, a2: v18);
        CChangeUndoScopeGuard::Release(this: &guard);
        CDmeSourceDCCFilePanel::RefreshDCCObjectList(this);
        v19 = this->m_pRootDCCObjects->GetItemCount(this: this->m_pRootDCCObjects);
        if ( v19 != 0 )
        {
          if ( nCount >= v19 )
            nCount = v19 - 1;
          v20 = this->m_pRootDCCObjects->GetItemIDFromRow(this: this->m_pRootDCCObjects, a2: nCount);
          this->m_pRootDCCObjects->SetSingleSelectedItem(this: this->m_pRootDCCObjects, a2: v20);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047DCC0
// Name: public: virtual void CDmeSourceDCCFilePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnKeyCodeTyped(CDmeSourceDCCFilePanel *this, ButtonCode_t code)
{
  if ( code == KEY_DELETE )
    CDmeSourceDCCFilePanel::OnRemoveDCCObject(this);
  else
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x1047DCE0
// Name: public: virtual void CDmeSourceDCCFilePanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnCommand(CDmeSourceDCCFilePanel *this, const char *pCommand)
{
  if ( _V_stricmp(s1: pCommand, s2: "OnBrowseDCCObject") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnAddDCCObject") != 0 )
    {
      if ( _V_stricmp(s1: pCommand, s2: "OnRemoveDCCObject") != 0 )
      {
        if ( _V_stricmp(s1: pCommand, s2: "OnApplyChanges") != 0 )
          vgui::Panel::OnCommand(this, command: pCommand);
        else
          CDmeSourceDCCFilePanel::OnDCCObjectNameChanged(this, a2: (const char *)this);
      }
      else
      {
        CDmeSourceDCCFilePanel::OnRemoveDCCObject(this);
      }
    }
    else
    {
      CDmeSourceDCCFilePanel::OnAddDCCObject(this);
    }
  }
  else
  {
    CDmeSourceDCCFilePanel::OnBrowseDCCObject(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047DDA0
// Name: private: virtual void CDmeSourceDCCFilePanel::OnTextNewLine(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeSourceDCCFilePanel::OnTextNewLine(
        CDmeSourceDCCFilePanel *this@<ecx>,
        const char *a2@<edi>,
        KeyValues *kv)
{
  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle) != nullptr
    && KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pDCCObjectName )
  {
    CDmeSourceDCCFilePanel::OnDCCObjectNameChanged(this, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047DDF0
// Name: private: void CDmeSourceDCCFilePanel::OnDCCObjectAdded(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeSourceDCCFilePanel::OnDCCObjectAdded(
        CDmeSourceDCCFilePanel *this@<ecx>,
        int a2@<edi>,
        const char *pDCCObjectName,
        KeyValues *pContextKeys)
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // eax
  char v6; // al
  IDataModel_vtbl *v7; // edx
  CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *v8; // edi
  int v9; // edi
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  CDisableUndoScopeGuard guard; // [esp+4h] [ebp-8h] BYREF

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle) != nullptr
    && CDmeSourceDCCFilePanel::CheckForDuplicateNames(this, pDCCObjectName, nDCCObjectSkipIndex: -1) == 0 )
  {
    IsUndoEnabled = g_pDataModel->IsUndoEnabled;
    *(_WORD *)&guard.m_bReleased = 0;
    guard.m_pNotify = nullptr;
    v6 = ((int (__thiscall *)(IDataModel *, int))IsUndoEnabled)(a1: g_pDataModel, a2);
    v7 = g_pDataModel->__vftable;
    guard.m_bOldValue = v6;
    v7->SetUndoEnabled(this: g_pDataModel, a2: false);
    v8 = (CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hSourceDCCFile.m_handle);
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pDCCObjectName, a3: pDCCObjectName);
    v9 = CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::AddToTail(
           this: v8 + 3,
           src: (vgui::PageTab *const *)&pDCCObjectName);
    CChangeUndoScopeGuard::Release(this: &guard);
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "DmeElementChanged");
    else
      v11 = nullptr;
    this->PostActionSignal(this, a2: v11);
    CDmeSourceDCCFilePanel::RefreshDCCObjectList(this);
    CDmeSourceDCCFilePanel::SelectDCCObject(this, a2: (int)this, nDCCObjectIndex: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047DEF0
// Name: private: virtual void CDmeSourceDCCFilePanel::OnInputCompleted(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnInputCompleted(CDmeSourceDCCFilePanel *this, KeyValues *kv)
{
  char *String; // esi
  KeyValues *Key; // eax

  String = KeyValues::GetString(this: kv, keyName: "text", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( KeyValues::FindKey(this: kv, keyName: "ChangeDCCObject", bCreate: false) != nullptr )
    {
      this->m_pDCCObjectName->SetText(this: this->m_pDCCObjectName, a2: String);
      CDmeSourceDCCFilePanel::OnDCCObjectNameChanged(this, a2: (const char *)this);
    }
    else
    {
      Key = KeyValues::FindKey(this: kv, keyName: "AddDCCObject", bCreate: false);
      if ( Key != nullptr )
        CDmeSourceDCCFilePanel::OnDCCObjectAdded(this, a2: (int)this, pDCCObjectName: String, pContextKeys: Key);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1047DF70
// Name: public: static void CDmeSourceDCCFilePanel::PanelMessageFunc_OnTextNewLine::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeSourceDCCFilePanel::PanelMessageFunc_OnTextNewLine::InitVar(int a1@<ebp>)
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
  if ( !`CDmeSourceDCCFilePanel::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded )
  {
    `CDmeSourceDCCFilePanel::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeSourceDCCFilePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextNewLine";
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
// Address: 0x1047E000
// Name: public: static void CDmeSourceDCCFilePanel::PanelMessageFunc_OnInputCompleted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeSourceDCCFilePanel::PanelMessageFunc_OnInputCompleted::InitVar(int a1@<ebp>)
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
  if ( !`CDmeSourceDCCFilePanel::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded )
  {
    `CDmeSourceDCCFilePanel::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeSourceDCCFilePanel");
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
// Address: 0x1047E090
// Name: public: static void CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSnapshotGrid::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeSourceDCCFilePanel");
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
// Address: 0x1047E120
// Name: public: static void CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemDeselected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded )
  {
    `CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeSourceDCCFilePanel");
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
// Address: 0x1047E1B0
// Name: public: CDmeSourceDCCFilePanel::CDmeSourceDCCFilePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSourceDCCFilePanel *__thiscall CDmeSourceDCCFilePanel::CDmeSourceDCCFilePanel(
        CDmeSourceDCCFilePanel *this,
        vgui::Panel *pParent,
        const char *pPanelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ListPanel *v7; // eax
  vgui::ListPanel *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CDmeSourceDCCFilePanel_vtbl *)&CDmeSourceDCCFilePanel::`vftable';
  if ( `CDmeSourceDCCFilePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeSourceDCCFilePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeSourceDCCFilePanel");
    v4->pfnClassName = CDmeSourceDCCFilePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CDmeSourceDCCFilePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeSourceDCCFilePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeSourceDCCFilePanel");
    v5->pfnClassName = CDmeSourceDCCFilePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CDmeSourceDCCFilePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeSourceDCCFilePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeSourceDCCFilePanel");
    v6->pfnClassName = CDmeSourceDCCFilePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  CDmeSourceDCCFilePanel::PanelMessageFunc_OnTextNewLine::InitVar(a1: (int)&savedregs);
  CDmeSourceDCCFilePanel::PanelMessageFunc_OnInputCompleted::InitVar(a1: (int)&savedregs);
  CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemDeselected::InitVar(a1: (int)&savedregs);
  this->m_hSourceDCCFile.m_handle = DMELEMENT_HANDLE_INVALID;
  v7 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
  if ( v7 != nullptr )
    v8 = vgui::ListPanel::ListPanel(this: v7, parent: this, panelName: "DCCObjectList");
  else
    v8 = nullptr;
  this->m_pRootDCCObjects = v8;
  v8->AddColumnHeader(this: v8, a2: 0, a3: "dccobject", a4: "Maya/XSI Object Name", a5: 100, a6: 0);
  this->m_pRootDCCObjects->AddActionSignalTarget_2(this: this->m_pRootDCCObjects, a2: this);
  this->m_pRootDCCObjects->SetSortFunc(this: this->m_pRootDCCObjects, a2: 0, a3: DccObjectSortFunc);
  this->m_pRootDCCObjects->SetSortColumn(this: this->m_pRootDCCObjects, a2: 0);
  this->m_pRootDCCObjects->SetEmptyListText_2(this: this->m_pRootDCCObjects, a2: "No sources");
  v9 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "DCCObjectBrowser",
            text: "...",
            pActionSignalTarget: this,
            pCmd: "OnBrowseDCCObject");
  else
    v10 = nullptr;
  this->m_pDCCObjectBrowser = v10;
  v11 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: (vgui::Panel *)"DCCObjectName");
  else
    v12 = nullptr;
  this->m_pDCCObjectName = v12;
  v12->SendNewLine(this: v12, a2: true);
  this->m_pDCCObjectName->AddActionSignalTarget_2(this: this->m_pDCCObjectName, a2: this);
  v13 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "AddDCCObjectButton",
            text: "Add",
            pActionSignalTarget: this,
            pCmd: "OnAddDCCObject");
  else
    v14 = nullptr;
  this->m_pAddDCCObject = v14;
  v15 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v15 != nullptr )
    v16 = vgui::Button::Button(
            this: v15,
            parent: this,
            panelName: "RemoveDCCObjectButton",
            text: "Remove",
            pActionSignalTarget: this,
            pCmd: "OnRemoveDCCObject");
  else
    v16 = nullptr;
  this->m_pRemoveDCCObject = v16;
  v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v17 != nullptr )
    v18 = vgui::Button::Button(
            this: v17,
            parent: this,
            panelName: "ApplyChangesButton",
            text: "Apply",
            pActionSignalTarget: this,
            pCmd: "OnApplyChanges");
  else
    v18 = nullptr;
  this->m_pApplyChanges = v18;
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/DmeSourceDCCFilePanel.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0048E170
// Name: private: void CDmeSourceDCCFilePanel::SetDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::SetDirty(CDmeSourceSkinPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "DmeElementChanged");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048E990
// Name: public: static char const __near * CDmeSourceDCCFilePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeSourceDCCFilePanel::GetPanelClassName()
{
  return "CDmeSourceDCCFilePanel";
}

//------------------------------------------------------------------------------
// Address: 0x0048E9A0
// Name: DccObjectSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl DccObjectSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *String; // esi
  const char *v4; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "dccobject", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "dccobject", defaultValue: defaultValue);
  return _V_stricmp(s1: String, s2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0048E9E0
// Name: private: void CDmeSourceDCCFilePanel::OnItemSelectionChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnItemSelectionChanged(CDmeSourceDCCFilePanel *this)
{
  bool v2; // bl
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  KeyValues *v7; // eax
  vgui::TextEntry_vtbl *v8; // edi
  const char *String; // eax
  bool bMultiselect; // [esp+Fh] [ebp-1h]

  v3 = this->m_pRootDCCObjects->GetSelectedItemsCount(this: this->m_pRootDCCObjects);
  v2 = v3 > 0;
  LOBYTE(v3) = v3 > 1;
  bMultiselect = v3;
  LOBYTE(v3) = v2 && (_BYTE)v3 == 0;
  v4 = ((int (__thiscall *)(vgui::Button *, int))this->m_pDCCObjectBrowser->SetEnabled)(
         a1: this->m_pDCCObjectBrowser,
         a2: v3);
  LOBYTE(v4) = v2 && !bMultiselect;
  v5 = ((int (__thiscall *)(vgui::TextEntry *, int))this->m_pDCCObjectName->SetEnabled)(
         a1: this->m_pDCCObjectName,
         a2: v4);
  LOBYTE(v5) = v2 && !bMultiselect;
  this->m_pApplyChanges->SetEnabled(this: this->m_pApplyChanges, a2: v5);
  this->m_pRemoveDCCObject->SetEnabled(this: this->m_pRemoveDCCObject, a2: v2);
  if ( !v2 || bMultiselect )
  {
    this->m_pDCCObjectName->SetText(this: this->m_pDCCObjectName, a2: defaultValue);
  }
  else
  {
    v6 = this->m_pRootDCCObjects->GetSelectedItem(this: this->m_pRootDCCObjects, a2: 0);
    v7 = this->m_pRootDCCObjects->GetItem(this: this->m_pRootDCCObjects, a2: v6);
    v8 = this->m_pDCCObjectName->__vftable;
    String = KeyValues::GetString(this: v7, keyName: "dccobject", defaultValue: defaultValue);
    v8->SetText(this: this->m_pDCCObjectName, a2: String);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048EB00
// Name: private: virtual void CDmeSourceDCCFilePanel::OnItemDeselected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnItemDeselected(CDmeSourceDCCFilePanel *this, KeyValues *kv)
{
  if ( KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pRootDCCObjects )
    CDmeSourceDCCFilePanel::OnItemSelectionChanged(this);
}

//------------------------------------------------------------------------------
// Address: 0x0048EB30
// Name: private: void CDmeSourceDCCFilePanel::SelectDCCObject(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeSourceDCCFilePanel::SelectDCCObject(
        CDmeSourceDCCFilePanel *this@<ecx>,
        int a2@<esi>,
        int nDCCObjectIndex)
{
  vgui::ListPanel_vtbl *v4; // eax
  int v5; // esi
  KeyValues *v6; // eax
  bool v7; // zf
  vgui::ListPanel_vtbl *v8; // eax

  v4 = this->m_pRootDCCObjects->__vftable;
  if ( nDCCObjectIndex >= 0 )
  {
    v5 = ((int (*)(void))v4->FirstItem)();
    if ( v5 != this->m_pRootDCCObjects->InvalidItemID(this: this->m_pRootDCCObjects) )
    {
      while ( 1 )
      {
        v6 = (KeyValues *)((int (__thiscall *)(vgui::ListPanel *, int, int))this->m_pRootDCCObjects->GetItem)(
                            a1: this->m_pRootDCCObjects,
                            a2: v5,
                            a3: a2);
        v7 = KeyValues::GetInt(this: v6, keyName: "dccObjectIndex", defaultValue: -1) == nDCCObjectIndex;
        v8 = this->m_pRootDCCObjects->__vftable;
        a2 = v5;
        if ( v7 )
          break;
        v5 = ((int (*)(void))v8->NextItem)();
        if ( v5 == this->m_pRootDCCObjects->InvalidItemID(this: this->m_pRootDCCObjects) )
          return;
      }
      ((void (*)(void))v8->SetSingleSelectedItem)();
    }
  }
  else
  {
    ((void (*)(void))v4->ClearSelectedItems)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048EC90
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeSourceDCCFilePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeSourceDCCFilePanel::GetMessageMap(CDmeSourceDCCFilePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeSourceDCCFilePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeSourceDCCFilePanel::GetMessageMap'::`2'::s_pMap;
  `CDmeSourceDCCFilePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeSourceDCCFilePanel");
  `CDmeSourceDCCFilePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048ECC0
// Name: public: virtual struct PanelAnimationMap __near * CDmeSourceDCCFilePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeSourceDCCFilePanel::GetAnimMap(CDmeSourceDCCFilePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeSourceDCCFilePanel");
}

//------------------------------------------------------------------------------
// Address: 0x0048ECD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeSourceDCCFilePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeSourceDCCFilePanel::GetKBMap(CDmeSourceDCCFilePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeSourceDCCFilePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeSourceDCCFilePanel::GetKBMap'::`2'::s_pMap;
  `CDmeSourceDCCFilePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeSourceDCCFilePanel");
  `CDmeSourceDCCFilePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048ED00
// Name: private: void CDmeSourceDCCFilePanel::OnAddDCCObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnAddDCCObject(CDmeSourceDCCFilePanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  vgui::InputDialog *v4; // eax
  vgui::InputDialog *v5; // esi

  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hSourceDCCFile.m_handle) != 0 )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "AddDCCObject");
    else
      v3 = nullptr;
    v4 = (vgui::InputDialog *)MemAlloc_Alloc(nSize: 0x22Cu);
    if ( v4 != nullptr )
    {
      v5 = vgui::InputDialog::InputDialog(
             this: v4,
             parent: this,
             title: "Add DCC Object",
             prompt: "Enter DCC object name to add",
             defaultValue: defaultValue);
      vgui::InputDialog::SetMultiline(this: v5, state: false);
      vgui::BaseInputDialog::DoModal(this: v5, pContextKeyValues: v3);
    }
    else
    {
      vgui::InputDialog::SetMultiline(this: nullptr, state: false);
      vgui::BaseInputDialog::DoModal(this: nullptr, pContextKeyValues: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048ED90
// Name: private: void CDmeSourceDCCFilePanel::OnBrowseDCCObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnBrowseDCCObject(CDmeSourceDCCFilePanel *this)
{
  int v2; // eax
  KeyValues *v3; // eax
  int Int; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  vgui::InputDialog *v7; // eax
  vgui::InputDialog *v8; // esi

  if ( this->m_pRootDCCObjects->GetSelectedItemsCount(this: this->m_pRootDCCObjects) != 0
    && (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hSourceDCCFile.m_handle) != 0 )
  {
    v2 = this->m_pRootDCCObjects->GetSelectedItem(this: this->m_pRootDCCObjects, a2: 0);
    v3 = this->m_pRootDCCObjects->GetItem(this: this->m_pRootDCCObjects, a2: v2);
    Int = KeyValues::GetInt(this: v3, keyName: "dccObjectIndex", defaultValue: -1);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "ChangeDCCObject", firstKey: "dccObjectIndex", firstValue: Int);
    else
      v6 = nullptr;
    v7 = (vgui::InputDialog *)MemAlloc_Alloc(nSize: 0x22Cu);
    if ( v7 != nullptr )
    {
      v8 = vgui::InputDialog::InputDialog(
             this: v7,
             parent: this,
             title: "Edit Maya/XSI Object",
             prompt: "Enter new name of Maya/XSI object",
             defaultValue: defaultValue);
      vgui::InputDialog::SetMultiline(this: v8, state: false);
      vgui::BaseInputDialog::DoModal(this: v8, pContextKeyValues: v6);
    }
    else
    {
      vgui::InputDialog::SetMultiline(this: nullptr, state: false);
      vgui::BaseInputDialog::DoModal(this: nullptr, pContextKeyValues: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048EED0
// Name: private: void CDmeSourceDCCFilePanel::RefreshDCCObjectList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::RefreshDCCObjectList(CDmeSourceDCCFilePanel *this)
{
  int v2; // esi
  KeyValues *v3; // edi
  const char *v4; // eax
  KeyValues *v5; // edi
  int nCount; // [esp+4h] [ebp-4h]

  this->m_pRootDCCObjects->RemoveAll(this: this->m_pRootDCCObjects);
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hSourceDCCFile.m_handle) != 0 )
  {
    v2 = 0;
    nCount = *(_DWORD *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                           a1: g_pDataModel.u,
                           a2: this->m_hSourceDCCFile.m_handle)
                       + 84);
    if ( nCount > 0 )
    {
      do
      {
        v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v3 != nullptr )
        {
          v4 = *(const char **)(*(_DWORD *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                              a1: g_pDataModel.u,
                                              a2: this->m_hSourceDCCFile.m_handle)
                                          + 72)
                              + 4 * v2);
          if ( v4 == (const char *)-1 )
            v4 = defaultValue;
          v5 = KeyValues::KeyValues(this: v3, setName: "node", firstKey: "dccobject", firstValue: v4);
        }
        else
        {
          v5 = nullptr;
        }
        KeyValues::SetInt(this: v5, keyName: "dccObjectIndex", value: v2);
        this->m_pRootDCCObjects->AddItem(this: this->m_pRootDCCObjects, a2: v5, a3: 0, a4: false, a5: false);
        ++v2;
      }
      while ( v2 < nCount );
    }
    this->m_pRootDCCObjects->SortList(this: this->m_pRootDCCObjects);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048EFC0
// Name: public: void CDmeSourceDCCFilePanel::SetDmeElement(class CDmeSourceDCCFile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::SetDmeElement(
        CDmeSourceDCCFilePanel *this,
        CExpressionCalculator *pSourceDCCFile)
{
  CExpressionCalculator *v2; // edi
  DmElementHandle_t BufferType; // eax

  v2 = pSourceDCCFile;
  if ( pSourceDCCFile != nullptr )
    BufferType = CCodecBuffer_Block::GetBufferType(this: pSourceDCCFile);
  else
    BufferType = DMELEMENT_HANDLE_INVALID;
  CDmeHandle<CDmeSourceDCCFile,0>::Set(this: &this->m_hSourceDCCFile, h: BufferType);
  LOBYTE(pSourceDCCFile) = pSourceDCCFile != nullptr;
  this->m_pDCCObjectBrowser->SetEnabled(this: this->m_pDCCObjectBrowser, a2: (bool)pSourceDCCFile);
  this->m_pAddDCCObject->SetEnabled(this: this->m_pAddDCCObject, a2: (bool)pSourceDCCFile);
  this->m_pRemoveDCCObject->SetEnabled(this: this->m_pRemoveDCCObject, a2: (bool)pSourceDCCFile);
  this->m_pApplyChanges->SetEnabled(this: this->m_pApplyChanges, a2: (bool)pSourceDCCFile);
  if ( v2 != nullptr )
  {
    CDmeSourceDCCFilePanel::RefreshDCCObjectList(this);
  }
  else
  {
    this->m_pRootDCCObjects->RemoveAll(this: this->m_pRootDCCObjects);
    this->m_pDCCObjectName->SetText(this: this->m_pDCCObjectName, a2: defaultValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048F080
// Name: private: bool CDmeSourceDCCFilePanel::CheckForDuplicateNames(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSourceDCCFilePanel::CheckForDuplicateNames(
        CDmeSourceDCCFilePanel *this,
        const char *pDCCObjectName,
        int nDCCObjectSkipIndex)
{
  int v4; // ebx
  int v5; // esi
  const char *v6; // eax
  vgui::MessageBox *v8; // esi
  vgui::Panel *v9; // eax
  vgui::MessageBox *v10; // eax

  if ( *pDCCObjectName == 0 )
    return 0;
  v4 = *(_DWORD *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
                     a1: g_pDataModel.u,
                     a2: this->m_hSourceDCCFile.m_handle)
                 + 84);
  v5 = 0;
  if ( v4 <= 0 )
    return 0;
  while ( 1 )
  {
    if ( v5 != nDCCObjectSkipIndex )
    {
      v6 = *(const char **)(*(_DWORD *)((*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                          a1: g_pDataModel.u,
                                          a2: this->m_hSourceDCCFile.m_handle)
                                      + 72)
                          + 4 * v5);
      if ( v6 == (const char *)-1 )
        v6 = defaultValue;
      if ( _V_stricmp(s1: pDCCObjectName, s2: v6) == 0 )
        break;
    }
    if ( ++v5 >= v4 )
      return 0;
  }
  v8 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
  if ( v8 != nullptr )
  {
    v9 = this->GetParent(this);
    v10 = vgui::MessageBox::MessageBox(
            this: v8,
            title: "#DmeSourceDCCFile_DuplicateSourceTitle",
            text: "#DmeSourceDCCFile_DuplicateSourceText",
            parent: v9);
  }
  else
  {
    v10 = nullptr;
  }
  v10->DoModal_2(this: v10, a2: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0048F150
// Name: private: void CDmeSourceDCCFilePanel::OnDCCObjectNameChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CDmeSourceDCCFilePanel::OnDCCObjectNameChanged(
        CDmeSourceDCCFilePanel *this@<ecx>,
        const char *a2@<edi>)
{
  int v3; // ebx
  int Int; // edi
  CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *v5; // eax
  char pDCCObjectName[260]; // [esp+4h] [ebp-110h] BYREF
  CDisableUndoScopeGuard guard; // [esp+108h] [ebp-Ch] BYREF
  KeyValues *pKeyValues; // [esp+110h] [ebp-4h]

  if ( this->m_pRootDCCObjects->GetSelectedItemsCount(this: this->m_pRootDCCObjects) != 0
    && (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hSourceDCCFile.m_handle) != 0 )
  {
    v3 = this->m_pRootDCCObjects->GetSelectedItem(this: this->m_pRootDCCObjects, a2: 0);
    pKeyValues = this->m_pRootDCCObjects->GetItem(this: this->m_pRootDCCObjects, a2: v3);
    Int = KeyValues::GetInt(this: pKeyValues, keyName: "dccObjectIndex", defaultValue: -1);
    if ( Int >= 0 )
    {
      this->m_pDCCObjectName->GetText_2(this: this->m_pDCCObjectName, a2: pDCCObjectName, a3: 260);
      if ( CDmeSourceDCCFilePanel::CheckForDuplicateNames(this, pDCCObjectName, nDCCObjectSkipIndex: Int) == 0 )
      {
        CDisableUndoScopeGuard::CDisableUndoScopeGuard(this: &guard);
        v5 = (CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(a1: g_pDataModel.u, a2: this->m_hSourceDCCFile.m_handle, a3: Int);
        CDmaStringArrayBase<CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::Set(
          this: v5 + 3,
          i: (int)pDCCObjectName,
          pValue: a2);
        CChangeUndoScopeGuard::Release(this: &guard);
        KeyValues::SetString(this: pKeyValues, keyName: "dccobject", value: pDCCObjectName);
        this->m_pRootDCCObjects->ApplyItemChanges(this: this->m_pRootDCCObjects, a2: v3);
        this->m_pRootDCCObjects->SortList(this: this->m_pRootDCCObjects);
        CDmeSourceDCCFilePanel::SetDirty((CDmeSourceSkinPanel *)this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048F280
// Name: private: void CDmeSourceDCCFilePanel::OnRemoveDCCObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnRemoveDCCObject(CDmeSourceDCCFilePanel *this)
{
  int v2; // edi
  unsigned int v3; // ebx
  void *v4; // esp
  int v5; // edi
  int v6; // eax
  KeyValues *v7; // eax
  int Int; // eax
  int v9; // eax
  int v10; // eax
  int v11; // edx
  int (__thiscall *v12)(CUtlSymbolLarge::<unnamed_type_u>); // eax
  char v13; // al
  int v14; // edx
  int i; // edi
  CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // [esp+0h] [ebp-1Ch] BYREF
  CDisableUndoScopeGuard guard; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+14h] [ebp-8h]
  int *pDCCObjectIndex; // [esp+18h] [ebp-4h]

  v2 = this->m_pRootDCCObjects->GetSelectedItemsCount(this: this->m_pRootDCCObjects);
  nCount = v2;
  if ( v2 != 0
    && (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hSourceDCCFile.m_handle) != 0 )
  {
    v3 = 0;
    v4 = alloca(4 * v2);
    v5 = 0;
    pDCCObjectIndex = &v21;
    if ( nCount > 0 )
    {
      do
      {
        v6 = this->m_pRootDCCObjects->GetSelectedItem(this: this->m_pRootDCCObjects, a2: v5);
        v7 = this->m_pRootDCCObjects->GetItem(this: this->m_pRootDCCObjects, a2: v6);
        Int = KeyValues::GetInt(this: v7, keyName: "dccObjectIndex", defaultValue: -1);
        if ( Int >= 0 )
          pDCCObjectIndex[v3++] = Int;
        ++v5;
      }
      while ( v5 < nCount );
      if ( v3 != 0 )
      {
        qsort(
          base: pDCCObjectIndex,
          num: v3,
          width: 4u,
          comp: (int (__cdecl *)(const void *, const void *))DeltaStateUsageLessFunc);
        v9 = this->m_pRootDCCObjects->GetSelectedItem(this: this->m_pRootDCCObjects, a2: 0);
        v10 = this->m_pRootDCCObjects->GetItemCurrentRow(this: this->m_pRootDCCObjects, a2: v9);
        v11 = *(_DWORD *)g_pDataModel.u.m_Id;
        nCount = v10;
        v12 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(v11 + 236);
        *(_WORD *)&guard.m_bReleased = 0;
        guard.m_pNotify = nullptr;
        v13 = ((int (__thiscall *)(_DWORD))v12)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
        v14 = *(_DWORD *)g_pDataModel.u.m_Id;
        guard.m_bOldValue = v13;
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(v14 + 232))(a1: g_pDataModel.u, a2: 0);
        for ( i = v3 - 1; i >= 0; --i )
        {
          v16 = (CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(a1: g_pDataModel.u, a2: this->m_hSourceDCCFile.m_handle);
          CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::Remove(
            this: v16 + 3,
            elem: pDCCObjectIndex[i]);
        }
        v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v17 != nullptr )
          v18 = KeyValues::KeyValues(this: v17, setName: "DmeElementChanged");
        else
          v18 = nullptr;
        this->PostActionSignal(this, a2: v18);
        CChangeUndoScopeGuard::Release(this: &guard);
        CDmeSourceDCCFilePanel::RefreshDCCObjectList(this);
        v19 = this->m_pRootDCCObjects->GetItemCount(this: this->m_pRootDCCObjects);
        if ( v19 != 0 )
        {
          if ( nCount >= v19 )
            nCount = v19 - 1;
          v20 = this->m_pRootDCCObjects->GetItemIDFromRow(this: this->m_pRootDCCObjects, a2: nCount);
          this->m_pRootDCCObjects->SetSingleSelectedItem(this: this->m_pRootDCCObjects, a2: v20);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048F450
// Name: public: virtual void CDmeSourceDCCFilePanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnKeyCodeTyped(CDmeSourceDCCFilePanel *this, ButtonCode_t code)
{
  if ( code == KEY_DELETE )
    CDmeSourceDCCFilePanel::OnRemoveDCCObject(this);
  else
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x0048F470
// Name: public: virtual void CDmeSourceDCCFilePanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnCommand(CDmeSourceDCCFilePanel *this, const char *pCommand)
{
  if ( _V_stricmp(s1: pCommand, s2: "OnBrowseDCCObject") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnAddDCCObject") != 0 )
    {
      if ( _V_stricmp(s1: pCommand, s2: "OnRemoveDCCObject") != 0 )
      {
        if ( _V_stricmp(s1: pCommand, s2: "OnApplyChanges") != 0 )
          vgui::Panel::OnCommand(this, command: pCommand);
        else
          CDmeSourceDCCFilePanel::OnDCCObjectNameChanged(this, a2: (const char *)this);
      }
      else
      {
        CDmeSourceDCCFilePanel::OnRemoveDCCObject(this);
      }
    }
    else
    {
      CDmeSourceDCCFilePanel::OnAddDCCObject(this);
    }
  }
  else
  {
    CDmeSourceDCCFilePanel::OnBrowseDCCObject(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048F530
// Name: private: virtual void CDmeSourceDCCFilePanel::OnTextNewLine(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeSourceDCCFilePanel::OnTextNewLine(
        CDmeSourceDCCFilePanel *this@<ecx>,
        const char *a2@<edi>,
        KeyValues *kv)
{
  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hSourceDCCFile.m_handle) != 0
    && KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr) == this->m_pDCCObjectName )
  {
    CDmeSourceDCCFilePanel::OnDCCObjectNameChanged(this, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048F580
// Name: private: void CDmeSourceDCCFilePanel::OnDCCObjectAdded(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeSourceDCCFilePanel::OnDCCObjectAdded(
        CDmeSourceDCCFilePanel *this@<ecx>,
        int a2@<edi>,
        const char *pDCCObjectName,
        KeyValues *pContextKeys)
{
  int (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>, int); // eax
  char v6; // al
  int v7; // edx
  CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *v8; // edi
  int v9; // edi
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  CDisableUndoScopeGuard guard; // [esp+4h] [ebp-8h] BYREF

  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hSourceDCCFile.m_handle) != 0
    && CDmeSourceDCCFilePanel::CheckForDuplicateNames(this, pDCCObjectName, nDCCObjectSkipIndex: -1) == 0 )
  {
    v5 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
    *(_WORD *)&guard.m_bReleased = 0;
    guard.m_pNotify = nullptr;
    v6 = ((int (__thiscall *)(_DWORD, _DWORD))v5)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id, a2);
    v7 = *(_DWORD *)g_pDataModel.u.m_Id;
    guard.m_bOldValue = v6;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(v7 + 232))(a1: g_pDataModel.u, a2: 0);
    v8 = (CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > > > *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(a1: g_pDataModel.u, a2: this->m_hSourceDCCFile.m_handle);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 200))(
      a1: g_pDataModel.u,
      a2: &pDCCObjectName,
      a3: pDCCObjectName);
    v9 = CDmaArrayBase<CUtlSymbolLarge,CDmaDataInternal<CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int>>>>::AddToTail(
           this: v8 + 3,
           src: (const CUtlSymbolLarge *)&pDCCObjectName);
    CChangeUndoScopeGuard::Release(this: &guard);
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "DmeElementChanged");
    else
      v11 = nullptr;
    this->PostActionSignal(this, a2: v11);
    CDmeSourceDCCFilePanel::RefreshDCCObjectList(this);
    CDmeSourceDCCFilePanel::SelectDCCObject(this, a2: (int)this, nDCCObjectIndex: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048F680
// Name: private: virtual void CDmeSourceDCCFilePanel::OnInputCompleted(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSourceDCCFilePanel::OnInputCompleted(CDmeSourceDCCFilePanel *this, KeyValues *kv)
{
  const char *String; // esi
  KeyValues *Key; // eax

  String = KeyValues::GetString(this: kv, keyName: "text", defaultValue: nullptr);
  if ( String != nullptr )
  {
    if ( KeyValues::FindKey(this: kv, keyName: "ChangeDCCObject", bCreate: false) != nullptr )
    {
      this->m_pDCCObjectName->SetText(this: this->m_pDCCObjectName, a2: String);
      CDmeSourceDCCFilePanel::OnDCCObjectNameChanged(this, a2: (const char *)this);
    }
    else
    {
      Key = KeyValues::FindKey(this: kv, keyName: "AddDCCObject", bCreate: false);
      if ( Key != nullptr )
        CDmeSourceDCCFilePanel::OnDCCObjectAdded(this, a2: (int)this, pDCCObjectName: String, pContextKeys: Key);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048F700
// Name: public: static void CDmeSourceDCCFilePanel::PanelMessageFunc_OnTextNewLine::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeSourceDCCFilePanel::PanelMessageFunc_OnTextNewLine::InitVar(int a1@<ebp>)
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
  if ( !`CDmeSourceDCCFilePanel::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded )
  {
    `CDmeSourceDCCFilePanel::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeSourceDCCFilePanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextNewLine";
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
// Address: 0x0048F790
// Name: public: static void CDmeSourceDCCFilePanel::PanelMessageFunc_OnInputCompleted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeSourceDCCFilePanel::PanelMessageFunc_OnInputCompleted::InitVar(int a1@<ebp>)
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
  if ( !`CDmeSourceDCCFilePanel::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded )
  {
    `CDmeSourceDCCFilePanel::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeSourceDCCFilePanel");
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
// Address: 0x0048F820
// Name: public: static void CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeSourceDCCFilePanel");
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
// Address: 0x0048F8B0
// Name: public: static void CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemDeselected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemDeselected::InitVar(int a1@<ebp>)
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
  if ( !`CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded )
  {
    `CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemDeselected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeSourceDCCFilePanel");
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
// Address: 0x0048F940
// Name: public: CDmeSourceDCCFilePanel::CDmeSourceDCCFilePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSourceDCCFilePanel *__thiscall CDmeSourceDCCFilePanel::CDmeSourceDCCFilePanel(
        CDmeSourceDCCFilePanel *this,
        vgui::Panel *pParent,
        const char *pPanelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ListPanel *v7; // eax
  vgui::ListPanel *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CDmeSourceDCCFilePanel_vtbl *)&CDmeSourceDCCFilePanel::`vftable';
  if ( `CDmeSourceDCCFilePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeSourceDCCFilePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeSourceDCCFilePanel");
    v4->pfnClassName = CDmeSourceDCCFilePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CDmeSourceDCCFilePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeSourceDCCFilePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeSourceDCCFilePanel");
    v5->pfnClassName = CDmeSourceDCCFilePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CDmeSourceDCCFilePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeSourceDCCFilePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeSourceDCCFilePanel");
    v6->pfnClassName = CDmeSourceDCCFilePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  CDmeSourceDCCFilePanel::PanelMessageFunc_OnTextNewLine::InitVar(a1: (int)&savedregs);
  CDmeSourceDCCFilePanel::PanelMessageFunc_OnInputCompleted::InitVar(a1: (int)&savedregs);
  CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CDmeSourceDCCFilePanel::PanelMessageFunc_OnItemDeselected::InitVar(a1: (int)&savedregs);
  this->m_hSourceDCCFile.m_handle = DMELEMENT_HANDLE_INVALID;
  v7 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v7 != nullptr )
    v8 = vgui::ListPanel::ListPanel(this: v7, parent: this, panelName: "DCCObjectList");
  else
    v8 = nullptr;
  this->m_pRootDCCObjects = v8;
  v8->AddColumnHeader(this: v8, a2: 0, a3: "dccobject", a4: "Maya/XSI Object Name", a5: 100, a6: 0);
  this->m_pRootDCCObjects->AddActionSignalTarget_2(this: this->m_pRootDCCObjects, a2: this);
  this->m_pRootDCCObjects->SetSortFunc(this: this->m_pRootDCCObjects, a2: 0, a3: DccObjectSortFunc);
  this->m_pRootDCCObjects->SetSortColumn(this: this->m_pRootDCCObjects, a2: 0);
  this->m_pRootDCCObjects->SetEmptyListText_2(this: this->m_pRootDCCObjects, a2: "No sources");
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "DCCObjectBrowser",
            text: "...",
            pActionSignalTarget: this,
            pCmd: "OnBrowseDCCObject");
  else
    v10 = nullptr;
  this->m_pDCCObjectBrowser = v10;
  v11 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: "DCCObjectName");
  else
    v12 = nullptr;
  this->m_pDCCObjectName = v12;
  v12->SendNewLine(this: v12, a2: true);
  this->m_pDCCObjectName->AddActionSignalTarget_2(this: this->m_pDCCObjectName, a2: this);
  v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "AddDCCObjectButton",
            text: "Add",
            pActionSignalTarget: this,
            pCmd: "OnAddDCCObject");
  else
    v14 = nullptr;
  this->m_pAddDCCObject = v14;
  v15 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v15 != nullptr )
    v16 = vgui::Button::Button(
            this: v15,
            parent: this,
            panelName: "RemoveDCCObjectButton",
            text: "Remove",
            pActionSignalTarget: this,
            pCmd: "OnRemoveDCCObject");
  else
    v16 = nullptr;
  this->m_pRemoveDCCObject = v16;
  v17 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v17 != nullptr )
    v18 = vgui::Button::Button(
            this: v17,
            parent: this,
            panelName: "ApplyChangesButton",
            text: "Apply",
            pActionSignalTarget: this,
            pCmd: "OnApplyChanges");
  else
    v18 = nullptr;
  this->m_pApplyChanges = v18;
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/DmeSourceDCCFilePanel.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

} // namespace sceneviewer
