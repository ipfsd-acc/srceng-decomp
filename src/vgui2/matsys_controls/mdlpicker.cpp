// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/mdlpicker.cpp
// Functions: 33
// ============================================================

#include "vgui2\matsys_controls\mdlpicker.h"

//------------------------------------------------------------------------------
// Address: 0x004BAD00
// Name: public: static char const __near * CMDLPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMDLPicker::GetPanelClassName()
{
  return "CMDLPicker";
}

//------------------------------------------------------------------------------
// Address: 0x004BAD10
// Name: public: static char const __near * CMDLPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMDLPickerFrame::GetPanelClassName()
{
  return "CMDLPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004BAD20
// Name: public: struct mstudioseqdesc_t __near & studiohdr_t::pSeqdesc(int)const
// Source: json
//------------------------------------------------------------------------------
mstudioseqdesc_t *__thiscall studiohdr_t::pSeqdesc(studiohdr_t *this, int i)
{
  int v2; // eax

  if ( this->numincludemodels != 0 )
    return studiohdr_t::pSeqdesc_Internal(this, i);
  v2 = i;
  if ( i < 0 || i >= this->numlocalseq )
    v2 = 0;
  return (mstudioseqdesc_t *)((char *)this + 212 * v2 + this->localseqindex);
}

//------------------------------------------------------------------------------
// Address: 0x004BAD60
// Name: private: void CMDLPicker::RefreshRenderSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::RefreshRenderSettings(CMDLPicker *this)
{
  vgui::PropertyPage *m_pRenderPage; // ecx
  vgui::Panel *ChildByName; // edi
  char v4; // al
  vgui::Panel *v5; // edi
  char v6; // al
  vgui::Panel *v7; // edi
  char v8; // al
  vgui::Panel *v9; // edi
  char v10; // al
  vgui::Panel *v11; // edi
  char v12; // al

  m_pRenderPage = this->m_pRenderPage;
  if ( m_pRenderPage != nullptr )
  {
    ChildByName = vgui::Panel::FindChildByName(this: m_pRenderPage, childName: "NoGround", recurseDown: false);
    ChildByName->AddActionSignalTarget_2(this: ChildByName, a2: this);
    v4 = ((int (__thiscall *)(vgui::Panel *))ChildByName->__vftable[1].SetAutoDelete)(a1: ChildByName);
    CMDLPanel::SetGroundGrid(this: this->m_pMDLPreview, bVisible: v4 == 0);
    v5 = vgui::Panel::FindChildByName(this: this->m_pRenderPage, childName: "Collision", recurseDown: false);
    v5->AddActionSignalTarget_2(this: v5, a2: this);
    v6 = ((int (__thiscall *)(vgui::Panel *))v5->__vftable[1].SetAutoDelete)(a1: v5);
    CMDLPanel::SetCollsionModel(this: this->m_pMDLPreview, bVisible: v6);
    v7 = vgui::Panel::FindChildByName(this: this->m_pRenderPage, childName: "Wireframe", recurseDown: false);
    v7->AddActionSignalTarget_2(this: v7, a2: this);
    v8 = ((int (__thiscall *)(vgui::Panel *))v7->__vftable[1].SetAutoDelete)(a1: v7);
    CMDLPanel::SetWireFrame(this: this->m_pMDLPreview, bVisible: v8);
    v9 = vgui::Panel::FindChildByName(this: this->m_pRenderPage, childName: "LockView", recurseDown: false);
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    v10 = ((int (__thiscall *)(vgui::Panel *))v9->__vftable[1].SetAutoDelete)(a1: v9);
    CMDLPanel::SetLockView(this: this->m_pMDLPreview, bLocked: v10);
    v11 = vgui::Panel::FindChildByName(this: this->m_pRenderPage, childName: "LookAtCamera", recurseDown: false);
    v11->AddActionSignalTarget_2(this: v11, a2: this);
    v12 = ((int (__thiscall *)(vgui::Panel *))v11->__vftable[1].SetAutoDelete)(a1: v11);
    CMDLPanel::SetLookAtCamera(this: this->m_pMDLPreview, bLookAtCamera: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BAEA0
// Name: public: virtual void CMDLPicker::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::PerformLayout(CMDLPicker *this)
{
  int w; // [esp+4h] [ebp-8h] BYREF
  int h; // [esp+8h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  vgui::Panel::SetBounds(this: this->m_pFileBrowserSplitter, x: 0, y: 0, wide: w, tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x004BAEE0
// Name: private: virtual void CMDLPicker::OnAssetSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnAssetSelected(CMDLPicker *this, KeyValues *pParams)
{
  const char *String; // eax
  bool v4; // al
  vgui::MessageBox *v5; // edi
  vgui::Panel *v6; // eax
  vgui::MessageBox *v7; // eax
  char pBuf[1024]; // [esp+4h] [ebp-504h] BYREF
  char pProbeBuf[260]; // [esp+404h] [ebp-104h] BYREF

  String = KeyValues::GetString(this: pParams, keyName: "asset", defaultValue: defaultValue);
  V_snprintf(pDest: pProbeBuf, maxLen: 260, pFormat: "materials/lightprobes/%s", String);
  BeginDMXContext();
  pParams = nullptr;
  v4 = UnserializeDMX(pFileName: pProbeBuf, pPathID: "GAME", bTextMode: true, ppRoot: (CDmxElement **)&pParams);
  if ( pParams != nullptr && v4 )
  {
    CPotteryWheelPanel::SetLightProbe(this: this->m_pMDLPreview, pLightProbe: (CDmxElement *)pParams);
    EndDMXContext(bDecommitMemory: true);
  }
  else
  {
    V_snprintf(pDest: pBuf, maxLen: 1024, pFormat: "Error loading lightprobe file '%s'!\n", pProbeBuf);
    v5 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v5 != nullptr )
    {
      v6 = this->GetParent(this);
      v7 = vgui::MessageBox::MessageBox(this: v5, title: "Error Loading File!\n", text: pBuf, parent: v6);
    }
    else
    {
      v7 = nullptr;
    }
    v7->DoModal_2(this: v7, a2: nullptr);
    EndDMXContext(bDecommitMemory: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BAFE0
// Name: public: virtual void CMDLPicker::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnCommand(CMDLPicker *this, const char *pCommand)
{
  CAssetPickerFrame *v3; // eax
  CAssetPickerFrame *v4; // eax

  if ( _V_stricmp(s1: pCommand, s2: "ChooseLightProbe") != 0 )
  {
    CBaseAssetPicker::OnCommand(this, pCommand);
  }
  else
  {
    v3 = (CAssetPickerFrame *)MemAlloc_Alloc(nSize: 0x228u);
    if ( v3 != nullptr )
    {
      v4 = CAssetPickerFrame::CAssetPickerFrame(
             this: v3,
             pParent: this,
             pTitle: "Select Light Probe (.prb) File",
             pAssetType: "Light Probe",
             pExt: "prb",
             pSubDir: "materials/lightprobes",
             pTextType: "lightprobe");
      CBaseAssetPickerFrame::DoModal(this: v4, pKeyValues: nullptr);
    }
    else
    {
      CBaseAssetPickerFrame::DoModal(this: nullptr, pKeyValues: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BB060
// Name: private: virtual void CMDLPicker::OnCheckButtonChecked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMDLPicker::OnCheckButtonChecked(CMDLPicker *this@<ecx>, int a2@<ebx>, int a3@<edi>, KeyValues *kv)
{
  CBaseAssetPicker::OnCheckButtonChecked(this, a2, a3, kv);
  CMDLPicker::RefreshRenderSettings(this);
}

//------------------------------------------------------------------------------
// Address: 0x004BB080
// Name: public: char const __near * CMDLPicker::GetSelectedSequenceName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMDLPicker::GetSelectedSequenceName(CMDLPicker *this)
{
  int v2; // eax
  KeyValues *v3; // eax

  if ( this->m_pSequencesPage == nullptr )
    return nullptr;
  v2 = this->m_pSequencesList->GetSelectedItem(this: this->m_pSequencesList, a2: 0);
  if ( v2 < 0 )
    return nullptr;
  v3 = this->m_pSequencesList->GetItem(this: this->m_pSequencesList, a2: v2);
  return KeyValues::GetString(this: v3, keyName: "sequence", defaultValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004BB0D0
// Name: public: char const __near * CMDLPicker::GetSelectedActivityName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMDLPicker::GetSelectedActivityName(CMDLPicker *this)
{
  int v2; // eax
  KeyValues *v3; // eax

  if ( this->m_pActivitiesPage == nullptr )
    return nullptr;
  v2 = this->m_pActivitiesList->GetSelectedItem(this: this->m_pActivitiesList, a2: 0);
  if ( v2 < 0 )
    return nullptr;
  v3 = this->m_pActivitiesList->GetItem(this: this->m_pActivitiesList, a2: v2);
  return KeyValues::GetString(this: v3, keyName: "activity", defaultValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004BB120
// Name: public: void CMDLPicker::SelectActivity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::SelectActivity(CMDLPicker *this, const char *pActivityName)
{
  IMDLCache *v3; // eax
  studiohdr_t *v4; // esi
  int i; // edi
  int v6; // eax
  int v7; // eax
  mstudioseqdesc_t *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax

  v3 = vgui::MDLCache();
  v4 = v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  for ( i = 0; ; ++i )
  {
    v6 = v4->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v4) : v4->numlocalseq;
    if ( i >= v6 )
      break;
    if ( v4->numincludemodels != 0 )
    {
      v8 = studiohdr_t::pSeqdesc_Internal(this: v4, i);
    }
    else
    {
      v7 = i;
      if ( i < 0 || i >= v4->numlocalseq )
        v7 = 0;
      v8 = (mstudioseqdesc_t *)((char *)v4 + 212 * v7 + v4->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v8 + v8->szactivitynameindex, s2: pActivityName) == 0 )
    {
      CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: i);
      break;
    }
  }
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
  {
    v10 = KeyValues::KeyValues(
            this: v9,
            setName: "SequenceSelectionChanged",
            firstKey: "activity",
            firstValue: pActivityName);
    this->PostActionSignal(this, a2: v10);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BB210
// Name: public: void CMDLPicker::SelectSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::SelectSequence(CMDLPicker *this, const char *pSequenceName)
{
  IMDLCache *v3; // eax
  studiohdr_t *v4; // esi
  int i; // edi
  int v6; // eax
  int v7; // eax
  mstudioseqdesc_t *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax

  v3 = vgui::MDLCache();
  v4 = v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  for ( i = 0; ; ++i )
  {
    v6 = v4->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v4) : v4->numlocalseq;
    if ( i >= v6 )
      break;
    if ( v4->numincludemodels != 0 )
    {
      v8 = studiohdr_t::pSeqdesc_Internal(this: v4, i);
    }
    else
    {
      v7 = i;
      if ( i < 0 || i >= v4->numlocalseq )
        v7 = 0;
      v8 = (mstudioseqdesc_t *)((char *)v4 + 212 * v7 + v4->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v8 + v8->szlabelindex, s2: pSequenceName) == 0 )
    {
      CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: i);
      break;
    }
  }
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
  {
    v10 = KeyValues::KeyValues(
            this: v9,
            setName: "SequenceSelectionChanged",
            firstKey: "sequence",
            firstValue: pSequenceName);
    this->PostActionSignal(this, a2: v10);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BB300
// Name: public: void CMDLPicker::SelectSkin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::SelectSkin(CMDLPicker *this, int nSkin)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  CMDLPanel::SetSkin(this: this->m_pMDLPreview, nSkin);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "SkinSelectionChanged", firstKey: "skin", firstValue: nSkin);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BB360
// Name: private: virtual void CMDLPicker::OnItemSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnItemSelected(CMDLPicker *this, KeyValues *kv)
{
  vgui::ListPanel *Ptr; // eax
  vgui::ListPanel *m_pSequencesList; // ecx
  const char *SelectedSequenceName; // eax
  vgui::ListPanel *m_pActivitiesList; // ecx
  const char *SelectedActivityName; // eax
  vgui::ListPanel *m_pSkinsList; // ecx
  int v9; // eax

  Ptr = (vgui::ListPanel *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
  m_pSequencesList = this->m_pSequencesList;
  if ( m_pSequencesList != nullptr && Ptr == m_pSequencesList )
  {
    SelectedSequenceName = CMDLPicker::GetSelectedSequenceName(this);
    if ( SelectedSequenceName != nullptr )
      CMDLPicker::SelectSequence(this, pSequenceName: SelectedSequenceName);
  }
  else
  {
    m_pActivitiesList = this->m_pActivitiesList;
    if ( m_pActivitiesList != nullptr && Ptr == m_pActivitiesList )
    {
      SelectedActivityName = CMDLPicker::GetSelectedActivityName(this);
      if ( SelectedActivityName != nullptr )
        CMDLPicker::SelectActivity(this, pActivityName: SelectedActivityName);
    }
    else
    {
      m_pSkinsList = this->m_pSkinsList;
      if ( m_pSkinsList != nullptr && Ptr == m_pSkinsList )
      {
        if ( this->m_pSkinsPage != nullptr )
        {
          v9 = m_pSkinsList->GetSelectedItem(this: m_pSkinsList, a2: 0);
          CMDLPicker::SelectSkin(this, nSkin: v9 < 0 ? 0 : v9);
        }
        else
        {
          CMDLPicker::SelectSkin(this, nSkin: 0);
        }
      }
      else
      {
        CBaseAssetPicker::OnItemSelected(this, kv);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BB430
// Name: private: virtual void CMDLPicker::OnPageChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnPageChanged(CMDLPicker *this)
{
  const char *SelectedSequenceName; // eax
  const char *SelectedActivityName; // eax

  if ( this->m_pSequencesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pSequencesPage )
  {
    this->m_pSequencesList->RequestFocus(this: this->m_pSequencesList, a2: 0);
    SelectedSequenceName = CMDLPicker::GetSelectedSequenceName(this);
    if ( SelectedSequenceName != nullptr )
      CMDLPicker::SelectSequence(this, pSequenceName: SelectedSequenceName);
  }
  else if ( this->m_pActivitiesPage != nullptr
         && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pActivitiesPage )
  {
    this->m_pActivitiesList->RequestFocus(this: this->m_pActivitiesList, a2: 0);
    SelectedActivityName = CMDLPicker::GetSelectedActivityName(this);
    if ( SelectedActivityName != nullptr )
      CMDLPicker::SelectActivity(this, pActivityName: SelectedActivityName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BB4C0
// Name: private: int CMDLPicker::UpdateSkinsList(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDLPicker::UpdateSkinsList(CMDLPicker *this)
{
  int v2; // esi
  IMDLCache *v3; // eax
  int v4; // eax
  int v5; // ebx
  KeyValues *v6; // eax
  const KeyValues *v7; // eax
  char skinText[28]; // [esp+8h] [ebp-1Ch] BYREF

  v2 = 0;
  if ( this->m_pSkinsList == nullptr )
    return 0;
  this->m_pSkinsList->RemoveAll(this: this->m_pSkinsList);
  v3 = vgui::MDLCache();
  v4 = (int)v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  if ( v4 == 0 )
    return 0;
  v5 = *(_DWORD *)(v4 + 224);
  if ( v5 > 0 )
  {
    do
    {
      memset(skinText, 0, 25);
      sprintf(string: skinText, format: "skin%i", v2);
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "node", firstKey: "skin", firstValue: skinText);
      else
        v7 = nullptr;
      this->m_pSkinsList->AddItem(this: this->m_pSkinsList, a2: v7, a3: 0, a4: false, a5: false);
      ++v2;
    }
    while ( v2 < v5 );
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004BB590
// Name: private: int CMDLPicker::UpdatePropDataList(class KeyValues __near *,bool __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDLPicker::UpdatePropDataList(CMDLPicker *this, KeyValues *pkvPropData, bool *bIsStatic)
{
  int v3; // edi
  KeyValues *i; // esi
  const char *Name; // eax
  const char *String; // eax
  vgui::Panel *ChildByName; // eax
  KeyValues *v9; // edi
  const char *v10; // eax
  const KeyValues *v11; // eax
  const char *v13; // [esp-8h] [ebp-14h]
  int iCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  iCount = 0;
  if ( this->m_pPropDataList == nullptr )
    return 0;
  this->m_pPropDataList->RemoveAll(this: this->m_pPropDataList);
  for ( i = KeyValues::GetFirstSubKey(this: pkvPropData); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      Name = KeyValues::GetName(this: i);
      if ( _V_strcmp(s1: Name, s2: "allowstatic") == 0 )
      {
        String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
        if ( _V_strcmp(s1: String, s2: "1") == 0 )
        {
          if ( !*bIsStatic )
          {
            ChildByName = vgui::Panel::FindChildByName(
                            this: this->m_pInfoPage,
                            childName: "StaticText",
                            recurseDown: false);
            ChildByName->SetVisible(this: ChildByName, a2: true);
          }
          *bIsStatic = *bIsStatic;
        }
      }
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
      {
        v13 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
        v10 = KeyValues::GetName(this: i);
        v11 = KeyValues::KeyValues(
                this: v9,
                setName: "node",
                firstKey: "key",
                firstValue: v10,
                secondKey: "value",
                secondValue: v13);
      }
      else
      {
        v11 = nullptr;
      }
      this->m_pPropDataList->AddItem(this: this->m_pPropDataList, a2: v11, a3: 0, a4: false, a5: false);
      v3 = ++iCount;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004BB6F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CMDLPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMDLPicker::GetMessageMap(CMDLPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMDLPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPicker::GetMessageMap'::`2'::s_pMap;
  `CMDLPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
  `CMDLPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BB720
// Name: public: virtual struct PanelAnimationMap __near * CMDLPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMDLPicker::GetAnimMap(CMDLPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CMDLPicker");
}

//------------------------------------------------------------------------------
// Address: 0x004BB730
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMDLPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMDLPicker::GetKBMap(CMDLPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMDLPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPicker::GetKBMap'::`2'::s_pMap;
  `CMDLPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPicker");
  `CMDLPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BB760
// Name: public: virtual struct vgui::PanelMessageMap __near * CMDLPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMDLPickerFrame::GetMessageMap(CMDLPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMDLPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CMDLPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMDLPickerFrame");
  `CMDLPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BB790
// Name: public: virtual struct PanelAnimationMap __near * CMDLPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMDLPickerFrame::GetAnimMap(CMDLPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CMDLPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004BB7A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMDLPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMDLPickerFrame::GetKBMap(CMDLPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMDLPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPickerFrame::GetKBMap'::`2'::s_pMap;
  `CMDLPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPickerFrame");
  `CMDLPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BB830
// Name: private: void CMDLPicker::UpdateInfoTab(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMDLPicker::UpdateInfoTab(CMDLPicker *this@<ecx>, int a2@<ebx>)
{
  IMDLCache *v3; // eax
  int v4; // eax
  _DWORD *v5; // esi
  vgui::PropertyPage *m_pInfoPage; // ecx
  vgui::Panel *ChildByName; // ebx
  vgui::PropertyPage *v8; // ecx
  vgui::Panel *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  const char *v12; // eax
  KeyValues *Key; // eax
  vgui::Panel *v14; // esi
  vgui::Panel *v15; // esi
  vgui::Panel *v16; // esi
  char massBuff[12]; // [esp+8h] [ebp-14h] BYREF
  int bIsStatic; // [esp+14h] [ebp-8h] BYREF
  int bIsPhysics; // [esp+18h] [ebp-4h]

  v3 = vgui::MDLCache();
  v4 = (int)v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  v5 = (_DWORD *)v4;
  if ( v4 != 0 )
  {
    m_pInfoPage = this->m_pInfoPage;
    bIsStatic = (int)*(float *)(v4 + 328);
    ChildByName = vgui::Panel::FindChildByName(this: m_pInfoPage, childName: "MassValue", recurseDown: false);
    V_snprintf(pDest: massBuff, maxLen: 10, pFormat: "%d", bIsStatic);
    ((void (__thiscall *)(vgui::Panel *, char *, int))ChildByName->__vftable[1].Think)(
      a1: ChildByName,
      a2: massBuff,
      a3: a2);
    v8 = this->m_pInfoPage;
    LOBYTE(bIsStatic) = (v5[38] & 0x10) != 0;
    LOBYTE(bIsPhysics) = 0;
    v9 = vgui::Panel::FindChildByName(this: v8, childName: "StaticText", recurseDown: false);
    v9->SetVisible(this: v9, a2: false);
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "modelkeys");
    else
      v11 = nullptr;
    if ( v5[79] != 0 )
      v12 = (char *)v5 + v5[78];
    else
      v12 = nullptr;
    KeyValues::LoadFromBuffer(
      this: v11,
      resourceName: "modelkeys",
      pBuffer: v12,
      pFileSystem: nullptr,
      pPathID: nullptr,
      pfnEvaluateSymbolProc: nullptr);
    Key = KeyValues::FindKey(this: v11, keyName: "prop_data", bCreate: false);
    if ( Key != nullptr )
    {
      if ( CMDLPicker::UpdatePropDataList(this, pkvPropData: Key, (bool *)&bIsStatic) != 0 )
        LOBYTE(bIsPhysics) = 1;
    }
    else
    {
      this->m_pPropDataList->RemoveAll(this: this->m_pPropDataList);
    }
    KeyValues::deleteThis(this: v11);
    v14 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "StaticObject", recurseDown: false);
    ((void (__thiscall *)(vgui::Panel *, int))v14->__vftable[1].GetPaintSize)(a1: v14, a2: 1);
    ((void (__thiscall *)(vgui::Panel *, int))v14->__vftable[1].LookupElementBounds)(a1: v14, a2: bIsStatic);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v14->__vftable[1].GetPaintSize)(a1: v14, a2: 0);
    v15 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "PhysicsObject", recurseDown: false);
    ((void (__thiscall *)(vgui::Panel *, int))v15->__vftable[1].GetPaintSize)(a1: v15, a2: 1);
    ((void (__thiscall *)(vgui::Panel *, int))v15->__vftable[1].LookupElementBounds)(a1: v15, a2: bIsPhysics);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v15->__vftable[1].GetPaintSize)(a1: v15, a2: 0);
    v16 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "DynamicObject", recurseDown: false);
    ((void (__thiscall *)(vgui::Panel *, int))v16->__vftable[1].GetPaintSize)(a1: v16, a2: 1);
    ((void (__thiscall *)(vgui::Panel *, bool))v16->__vftable[1].LookupElementBounds)(
      a1: v16,
      a2: (_BYTE)bIsPhysics == 0);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v16->__vftable[1].GetPaintSize)(a1: v16, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BBA30
// Name: public: static void CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar(int a1@<ebp>)
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
  if ( !`CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded )
  {
    `CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSoundPicker::`vcall'{1012,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AssetSelected";
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
// Address: 0x004BBAC0
// Name: public: static void CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1004,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
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
// Address: 0x004BBB50
// Name: public: static void CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
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
// Address: 0x004BBBE0
// Name: public: static void CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar(int a1@<ebp>)
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
  if ( !`CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded )
  {
    `CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1016,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
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
// Address: 0x004BBC70
// Name: public: CMDLPicker::CMDLPicker(class vgui::Panel __near *,int)
// Source: json
//------------------------------------------------------------------------------
CMDLPicker *__thiscall CMDLPicker::CMDLPicker(CMDLPicker *this, vgui::Panel *pParent, int nFlags)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int v7; // edx
  vgui::Splitter *v8; // eax
  vgui::Splitter *v9; // eax
  vgui::Panel *Child; // edi
  vgui::Panel *v11; // ebx
  vgui::Splitter *v12; // eax
  vgui::Splitter *v13; // eax
  vgui::Panel *v14; // edi
  vgui::Panel *v15; // ebx
  CMDLPanel *v16; // eax
  CMDLPanel *v17; // eax
  vgui::PropertySheet *v18; // eax
  vgui::PropertySheet *v19; // eax
  char v20; // bl
  vgui::PropertyPage *v21; // eax
  vgui::PropertyPage *v22; // eax
  vgui::Panel *ChildByName; // eax
  vgui::PropertyPage *v24; // eax
  vgui::PropertyPage *v25; // eax
  vgui::ListPanel *v26; // eax
  vgui::ListPanel *v27; // eax
  vgui::PropertyPage *v28; // eax
  vgui::PropertyPage *v29; // eax
  vgui::ListPanel *v30; // eax
  vgui::ListPanel *v31; // eax
  vgui::PropertyPage *v32; // eax
  vgui::PropertyPage *v33; // eax
  vgui::ListPanel *v34; // eax
  vgui::ListPanel *v35; // eax
  vgui::PropertyPage *v36; // eax
  vgui::PropertyPage *v37; // eax
  vgui::Panel *v38; // edi
  vgui::Panel_vtbl *v39; // ebx
  Color *v40; // eax
  vgui::Panel_vtbl *v41; // ebx
  Color *v42; // eax
  vgui::Panel *v43; // edi
  vgui::Panel_vtbl *v44; // ebx
  Color *v45; // eax
  vgui::Panel_vtbl *v46; // ebx
  Color *v47; // eax
  vgui::Panel *v48; // edi
  vgui::Panel_vtbl *v49; // ebx
  Color *v50; // eax
  vgui::Panel_vtbl *v51; // ebx
  Color *v52; // eax
  vgui::ListPanel *v53; // eax
  vgui::ListPanel *v54; // eax
  vgui::PropertyPage *m_pRenderPage; // eax
  vgui::PropertyPage *m_pSequencesPage; // eax
  vgui::PropertyPage *m_pActivitiesPage; // eax
  vgui::PropertyPage *m_pSkinsPage; // eax
  vgui::PropertyPage *m_pInfoPage; // eax
  float flFractions[2]; // [esp+Ch] [ebp-8h] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  CBaseAssetPicker::CBaseAssetPicker(
    this,
    pParent,
    pAssetType: "MDL Files",
    pExt: "mdl",
    pSubDir: "models",
    pTextType: "mdlName",
    pAssetSearchPath: "GAME");
  this->__vftable = (CMDLPicker_vtbl *)&CMDLPicker::`vftable';
  if ( `CMDLPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPicker::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
    v4->pfnClassName = CMDLPicker::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CMDLPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMDLPicker::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CMDLPicker");
    v5->pfnClassName = CMDLPicker::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CMDLPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPicker::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPicker");
    v6->pfnClassName = CMDLPicker::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  }
  CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar(a1: (int)&savedregs);
  CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar(a1: (int)&savedregs);
  v7 = nFlags;
  this->m_hSelectedMDL = -1;
  this->m_nFlags = v7;
  this->m_pRenderPage = nullptr;
  this->m_pSequencesPage = nullptr;
  this->m_pActivitiesPage = nullptr;
  this->m_pSkinsPage = nullptr;
  this->m_pInfoPage = nullptr;
  this->m_pSequencesList = nullptr;
  this->m_pActivitiesList = nullptr;
  v8 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v8 != nullptr )
    v9 = vgui::Splitter::Splitter(
           this: v8,
           parent: this,
           name: "FileBrowserSplitter",
           mode: SPLITTER_MODE_VERTICAL,
           nCount: 1);
  else
    v9 = nullptr;
  flFractions[0] = 0.33000001;
  this->m_pFileBrowserSplitter = v9;
  flFractions[1] = 0.67000002;
  vgui::Splitter::RespaceSplitters(this: v9, flFractions);
  Child = vgui::Panel::GetChild(this: this->m_pFileBrowserSplitter, index: 0);
  v11 = vgui::Panel::GetChild(this: this->m_pFileBrowserSplitter, index: 1);
  Child->RequestFocus(this: Child, a2: 0);
  CBaseAssetPicker::CreateStandardControls(this, pParent: Child, bAllowMultiselect: false);
  v12 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v12 != nullptr )
    v13 = vgui::Splitter::Splitter(
            this: v12,
            parent: v11,
            name: "PreviewSplitter",
            mode: SPLITTER_MODE_HORIZONTAL,
            nCount: 1);
  else
    v13 = nullptr;
  this->m_pPreviewSplitter = v13;
  v14 = vgui::Panel::GetChild(this: v13, index: 0);
  v15 = vgui::Panel::GetChild(this: this->m_pPreviewSplitter, index: 1);
  v16 = (CMDLPanel *)MemAlloc_Alloc(nSize: 0xBE4u);
  if ( v16 != nullptr )
    v17 = CMDLPanel::CMDLPanel(this: v16, pParent: v14, pName: "MDLPreview");
  else
    v17 = nullptr;
  this->m_pMDLPreview = v17;
  vgui::Panel::SetSkipChildDuringPainting(this, child: v17);
  v18 = (vgui::PropertySheet *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v18 != nullptr )
    v19 = vgui::PropertySheet::PropertySheet(this: v18, parent: v15, panelName: "ViewsSheet", draggableTabs: false);
  else
    v19 = nullptr;
  this->m_pViewsSheet = v19;
  v19->AddActionSignalTarget_2(this: v19, a2: this);
  v20 = nFlags;
  if ( (nFlags & 1) != 0 )
  {
    v21 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v21 != nullptr )
      v22 = vgui::PropertyPage::PropertyPage(this: v21, parent: this->m_pViewsSheet, panelName: "RenderPage");
    else
      v22 = nullptr;
    this->m_pRenderPage = v22;
    v22->AddActionSignalTarget_2(this: v22, a2: this);
    this->m_pRenderPage->LoadControlSettingsAndUserConfig(
      this: this->m_pRenderPage,
      a2: "resource/mdlpickerrender.res",
      a3: 0);
    CMDLPicker::RefreshRenderSettings(this);
    ChildByName = vgui::Panel::FindChildByName(
                    this: this->m_pRenderPage,
                    childName: "ChooseLightProbe",
                    recurseDown: false);
    ChildByName->AddActionSignalTarget_2(this: ChildByName, a2: this);
  }
  if ( (v20 & 2) != 0 )
  {
    v24 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v24 != nullptr )
      v25 = vgui::PropertyPage::PropertyPage(this: v24, parent: this->m_pViewsSheet, panelName: "SequencesPage");
    else
      v25 = nullptr;
    this->m_pSequencesPage = v25;
    v26 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
    if ( v26 != nullptr )
      v27 = vgui::ListPanel::ListPanel(this: v26, parent: this->m_pSequencesPage, panelName: "SequencesList");
    else
      v27 = nullptr;
    this->m_pSequencesList = v27;
    v27->AddColumnHeader(this: v27, a2: 0, a3: "sequence", a4: "sequence", a5: 52, a6: 0);
    this->m_pSequencesList->AddActionSignalTarget_2(this: this->m_pSequencesList, a2: this);
    this->m_pSequencesList->SetSelectIndividualCells(this: this->m_pSequencesList, a2: true);
    this->m_pSequencesList->SetEmptyListText_2(this: this->m_pSequencesList, a2: "No .MDL file currently selected.");
    this->m_pSequencesList->SetDragEnabled(this: this->m_pSequencesList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pSequencesList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 6,
      nPinOffsetY: 6,
      nUnpinnedCornerOffsetX: -6,
      nUnpinnedCornerOffsetY: -6);
  }
  if ( (v20 & 4) != 0 )
  {
    v28 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v28 != nullptr )
      v29 = vgui::PropertyPage::PropertyPage(this: v28, parent: this->m_pViewsSheet, panelName: "ActivitiesPage");
    else
      v29 = nullptr;
    this->m_pActivitiesPage = v29;
    v30 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
    if ( v30 != nullptr )
      v31 = vgui::ListPanel::ListPanel(this: v30, parent: this->m_pActivitiesPage, panelName: "ActivitiesList");
    else
      v31 = nullptr;
    this->m_pActivitiesList = v31;
    v31->AddColumnHeader(this: v31, a2: 0, a3: "activity", a4: "activity", a5: 52, a6: 0);
    this->m_pActivitiesList->AddActionSignalTarget_2(this: this->m_pActivitiesList, a2: this);
    this->m_pActivitiesList->SetSelectIndividualCells(this: this->m_pActivitiesList, a2: true);
    this->m_pActivitiesList->SetEmptyListText_2(this: this->m_pActivitiesList, a2: "No .MDL file currently selected.");
    this->m_pActivitiesList->SetDragEnabled(this: this->m_pActivitiesList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pActivitiesList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 6,
      nPinOffsetY: 6,
      nUnpinnedCornerOffsetX: -6,
      nUnpinnedCornerOffsetY: -6);
  }
  if ( (v20 & 8) != 0 )
  {
    v32 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v32 != nullptr )
      v33 = vgui::PropertyPage::PropertyPage(this: v32, parent: this->m_pViewsSheet, panelName: "SkinsPage");
    else
      v33 = nullptr;
    this->m_pSkinsPage = v33;
    v34 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
    if ( v34 != nullptr )
      v35 = vgui::ListPanel::ListPanel(this: v34, parent: this->m_pSkinsPage, panelName: "SkinsList");
    else
      v35 = nullptr;
    this->m_pSkinsList = v35;
    v35->AddColumnHeader(this: v35, a2: 0, a3: "skin", a4: "skin", a5: 52, a6: 0);
    this->m_pSkinsList->AddActionSignalTarget_2(this: this->m_pSkinsList, a2: this);
    this->m_pSkinsList->SetSelectIndividualCells(this: this->m_pSkinsList, a2: true);
    this->m_pSkinsList->SetEmptyListText_2(this: this->m_pSkinsList, a2: "No .MDL file currently selected.");
    this->m_pSkinsList->SetDragEnabled(this: this->m_pSkinsList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pSkinsList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 6,
      nPinOffsetY: 6,
      nUnpinnedCornerOffsetX: -6,
      nUnpinnedCornerOffsetY: -6);
  }
  if ( (v20 & 0x10) != 0 )
  {
    v36 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v36 != nullptr )
      v37 = vgui::PropertyPage::PropertyPage(this: v36, parent: this->m_pViewsSheet, panelName: "InfoPage");
    else
      v37 = nullptr;
    this->m_pInfoPage = v37;
    v37->AddActionSignalTarget_2(this: v37, a2: this);
    this->m_pInfoPage->LoadControlSettingsAndUserConfig(
      this: this->m_pInfoPage,
      a2: "resource/mdlpickerinfo.res",
      a3: 0);
    v38 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "PhysicsObject", recurseDown: false);
    v39 = v38->__vftable;
    v40 = v38->GetFgColor(this: v38, result: (Color *)&nFlags);
    v39[1].OnChildAdded(this: v38, a2: (unsigned int)*v40);
    v41 = v38->__vftable;
    v42 = v38->GetFgColor(this: v38, result: (Color *)&nFlags);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v41[1].OnSizeChanged)(a1: v38, a2: *v42);
    v43 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "StaticObject", recurseDown: false);
    v44 = v43->__vftable;
    v45 = v43->GetFgColor(this: v43, result: (Color *)&nFlags);
    v44[1].OnChildAdded(this: v43, a2: (unsigned int)*v45);
    v46 = v43->__vftable;
    v47 = v43->GetFgColor(this: v43, result: (Color *)&nFlags);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v46[1].OnSizeChanged)(a1: v43, a2: *v47);
    v48 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "DynamicObject", recurseDown: false);
    v49 = v48->__vftable;
    v50 = v48->GetFgColor(this: v48, result: (Color *)&nFlags);
    v49[1].OnChildAdded(this: v48, a2: (unsigned int)*v50);
    v51 = v48->__vftable;
    v52 = v48->GetFgColor(this: v48, result: (Color *)&nFlags);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v51[1].OnSizeChanged)(a1: v48, a2: *v52);
    v53 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
    if ( v53 != nullptr )
      v54 = vgui::ListPanel::ListPanel(this: v53, parent: this->m_pInfoPage, panelName: "PropData");
    else
      v54 = nullptr;
    this->m_pPropDataList = v54;
    v54->AddColumnHeader(this: v54, a2: 0, a3: "key", a4: "key", a5: 250, a6: 1);
    this->m_pPropDataList->AddColumnHeader(this: this->m_pPropDataList, a2: 1, a3: "value", a4: "value", a5: 52, a6: 0);
    this->m_pPropDataList->AddActionSignalTarget_2(this: this->m_pPropDataList, a2: this);
    this->m_pPropDataList->SetSelectIndividualCells(this: this->m_pPropDataList, a2: false);
    this->m_pPropDataList->SetEmptyListText_2(this: this->m_pPropDataList, a2: "No prop_data available.");
    this->m_pPropDataList->SetDragEnabled(this: this->m_pPropDataList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pPropDataList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 6,
      nPinOffsetY: 72,
      nUnpinnedCornerOffsetX: -6,
      nUnpinnedCornerOffsetY: -6);
    CMDLPicker::RefreshRenderSettings(this);
  }
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/mdlpicker.res", dialogID: 0);
  m_pRenderPage = this->m_pRenderPage;
  if ( m_pRenderPage != nullptr )
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: m_pRenderPage,
      a3: "Render",
      a4: nullptr,
      a5: false,
      a6: -1);
  m_pSequencesPage = this->m_pSequencesPage;
  if ( m_pSequencesPage != nullptr )
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: m_pSequencesPage,
      a3: "Sequences",
      a4: nullptr,
      a5: false,
      a6: -1);
  m_pActivitiesPage = this->m_pActivitiesPage;
  if ( m_pActivitiesPage != nullptr )
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: m_pActivitiesPage,
      a3: "Activities",
      a4: nullptr,
      a5: false,
      a6: -1);
  m_pSkinsPage = this->m_pSkinsPage;
  if ( m_pSkinsPage != nullptr )
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: m_pSkinsPage,
      a3: "Skins",
      a4: nullptr,
      a5: false,
      a6: -1);
  m_pInfoPage = this->m_pInfoPage;
  if ( m_pInfoPage != nullptr )
    this->m_pViewsSheet->AddPage(this: this->m_pViewsSheet, a2: m_pInfoPage, a3: "Info", a4: nullptr, a5: false, a6: -1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BC4E0
// Name: public: CMDLPickerFrame::CMDLPickerFrame(class vgui::Panel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CMDLPickerFrame *__thiscall CMDLPickerFrame::CMDLPickerFrame(
        CMDLPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        int nFlags)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  CMDLPicker *v8; // eax
  CMDLPicker *v9; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CMDLPickerFrame_vtbl *)&CMDLPickerFrame::`vftable';
  if ( `CMDLPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPickerFrame::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CMDLPickerFrame");
    v5->pfnClassName = CMDLPickerFrame::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CMDLPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMDLPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CMDLPickerFrame");
    v6->pfnClassName = CMDLPickerFrame::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CMDLPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPickerFrame");
    v7->pfnClassName = CMDLPickerFrame::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v8 = (CMDLPicker *)MemAlloc_Alloc(nSize: 0x284u);
  if ( v8 != nullptr )
    v9 = CMDLPicker::CMDLPicker(this: v8, pParent: this, nFlags);
  else
    v9 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v9);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/mdlpickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004BC5E0
// Name: private: void CMDLPicker::RefreshActivitiesAndSequencesList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMDLPicker::RefreshActivitiesAndSequencesList(CMDLPicker *this@<ecx>, int m_hSelectedMDL@<esi>)
{
  int v3; // edi
  void (__thiscall *SetEmptyListText_2)(vgui::ListPanel *, const char *); // eax
  IMDLCache *v5; // eax
  studiohdr_t *v6; // eax
  studiohdr_t *v7; // esi
  int NumSeq_Internal; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v9; // ecx
  bool v10; // zf
  int v11; // eax
  int v12; // eax
  mstudioseqdesc_t *v13; // eax
  int v14; // eax
  mstudioseqdesc_t *v15; // eax
  const char *v16; // edi
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // esi
  IMDLCache *v21; // eax
  const char *v22; // eax
  int v23; // eax
  mstudioseqdesc_t *v24; // eax
  const char *v25; // esi
  KeyValues *v26; // eax
  KeyValues *v27; // eax
  int v28; // edi
  KeyValues *v29; // eax
  KeyValues *v30; // esi
  IMDLCache *v31; // eax
  const char *v32; // eax
  CUtlDict<int,unsigned short> activityNames; // [esp+8h] [ebp-30h] BYREF
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+24h] [ebp-14h] BYREF
  int nItemID; // [esp+2Ch] [ebp-Ch]
  studiohdr_t *hdr; // [esp+30h] [ebp-8h]
  int j; // [esp+34h] [ebp-4h] BYREF

  this->m_pActivitiesList->RemoveAll(this: this->m_pActivitiesList);
  this->m_pSequencesList->RemoveAll(this: this->m_pSequencesList);
  v3 = 0;
  CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: 0);
  SetEmptyListText_2 = this->m_pActivitiesList->SetEmptyListText_2;
  if ( this->m_hSelectedMDL == 0xFFFF )
  {
    ((void (__stdcall *)(const char *))SetEmptyListText_2)(a1: "No .MDL file currently selected");
    this->m_pSequencesList->SetEmptyListText_2(this: this->m_pSequencesList, a2: "No .MDL file currently selected");
  }
  else
  {
    ((void (__stdcall *)(const char *))SetEmptyListText_2)(a1: ".MDL file contains no activities");
    this->m_pSequencesList->SetEmptyListText_2(this: this->m_pSequencesList, a2: ".MDL file contains no sequences");
    v5 = vgui::MDLCache();
    v6 = v5->GetStudioHdr(this: v5, a2: this->m_hSelectedMDL);
    v7 = v6;
    hdr = v6;
    if ( v6->numincludemodels != 0 )
      NumSeq_Internal = studiohdr_t::GetNumSeq_Internal(this: v6);
    else
      NumSeq_Internal = v6->numlocalseq;
    v9 = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_nAllocationCount = NumSeq_Internal;
    activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
    if ( NumSeq_Internal != 0 )
    {
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: 16 * NumSeq_Internal);
      activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = v9;
    }
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_FirstFree = -1;
    activityNames.m_Elements.m_Tree.m_pElements = v9;
    activityNames.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    while ( 1 )
    {
      v10 = v7->numincludemodels == 0;
      j = v3;
      v11 = v10 ? v7->numlocalseq : studiohdr_t::GetNumSeq_Internal(this: v7);
      if ( v3 >= v11 )
        break;
      if ( v7->numincludemodels != 0 )
      {
        v13 = studiohdr_t::pSeqdesc_Internal(this: v7, i: v3);
      }
      else
      {
        v12 = v3;
        if ( v3 < 0 || v3 >= v7->numlocalseq )
          v12 = 0;
        v13 = (mstudioseqdesc_t *)((char *)v7 + 212 * v12 + v7->localseqindex);
      }
      if ( (v13->flags & 0x400) == 0 )
      {
        if ( v7->numincludemodels != 0 )
        {
          v15 = studiohdr_t::pSeqdesc_Internal(this: v7, i: v3);
        }
        else
        {
          v14 = v3;
          if ( v3 < 0 || v3 >= v7->numlocalseq )
            v14 = 0;
          v15 = (mstudioseqdesc_t *)((char *)v7 + 212 * v14 + v7->localseqindex);
        }
        v16 = (char *)v15 + v15->szactivitynameindex;
        if ( v16 != nullptr && *v16 != 0 )
        {
          search.key = (char *)v15 + v15->szactivitynameindex;
          if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                 this: &activityNames.m_Elements.m_Tree,
                 &search) == 0xFFFF )
          {
            v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v17 != nullptr )
              v18 = KeyValues::KeyValues(this: v17, setName: "node", firstKey: "activity", firstValue: v16);
            else
              v18 = nullptr;
            nItemID = ((int (__thiscall *)(vgui::ListPanel *, KeyValues *, _DWORD, _DWORD, _DWORD, int))this->m_pActivitiesList->AddItem)(
                        a1: this->m_pActivitiesList,
                        a2: v18,
                        a3: 0,
                        a4: 0,
                        a5: 0,
                        a6: m_hSelectedMDL);
            v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v19 != nullptr )
              v20 = KeyValues::KeyValues(this: v19, setName: "drag", firstKey: "text", firstValue: v16);
            else
              v20 = nullptr;
            KeyValues::SetString(this: v20, keyName: "texttype", value: "activityName");
            v21 = vgui::MDLCache();
            m_hSelectedMDL = this->m_hSelectedMDL;
            v22 = (const char *)((int (__thiscall *)(IMDLCache *))v21->GetModelName)(a1: v21);
            KeyValues::SetString(this: v20, keyName: "mdl", value: v22);
            vgui::ListPanel::SetItemDragData(this: this->m_pActivitiesList, itemID: nItemID, data: v20);
            CUtlDict<int,unsigned short>::Insert(this: &activityNames, pName: v16, element: &j);
            v7 = hdr;
          }
        }
        if ( v7->numincludemodels != 0 )
        {
          v24 = studiohdr_t::pSeqdesc_Internal(this: v7, i: j);
        }
        else
        {
          v23 = j;
          if ( j < 0 || j >= v7->numlocalseq )
            v23 = 0;
          v24 = (mstudioseqdesc_t *)((char *)v7 + 212 * v23 + v7->localseqindex);
        }
        v25 = (char *)v24 + v24->szlabelindex;
        if ( v25 != nullptr && *v25 != 0 )
        {
          v26 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v26 != nullptr )
            v27 = KeyValues::KeyValues(this: v26, setName: "node", firstKey: "sequence", firstValue: v25);
          else
            v27 = nullptr;
          v28 = ((int (__thiscall *)(vgui::ListPanel *, KeyValues *, _DWORD, _DWORD, _DWORD, int))this->m_pSequencesList->AddItem)(
                  a1: this->m_pSequencesList,
                  a2: v27,
                  a3: 0,
                  a4: 0,
                  a5: 0,
                  a6: m_hSelectedMDL);
          v29 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v29 != nullptr )
            v30 = KeyValues::KeyValues(this: v29, setName: "drag", firstKey: "text", firstValue: v25);
          else
            v30 = nullptr;
          KeyValues::SetString(this: v30, keyName: "texttype", value: "sequenceName");
          v31 = vgui::MDLCache();
          m_hSelectedMDL = this->m_hSelectedMDL;
          v32 = (const char *)((int (__thiscall *)(IMDLCache *))v31->GetModelName)(a1: v31);
          KeyValues::SetString(this: v30, keyName: "mdl", value: v32);
          vgui::ListPanel::SetItemDragData(this: this->m_pSequencesList, itemID: v28, data: v30);
        }
        v3 = j;
        v7 = hdr;
      }
      ++v3;
    }
    CUtlDict<int,unsigned short>::RemoveAll(this: &activityNames);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &activityNames.m_Elements.m_Tree);
    if ( activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && activityNames.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: activityNames.m_Elements.m_Tree.m_Elements.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BC9B0
// Name: public: void CMDLPicker::SelectMDL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::SelectMDL(CMDLPicker *this, const char *pRelativePath)
{
  IMDLCache *v3; // eax
  int v4; // edi
  IMDLCache *v5; // eax
  IMDLCache *v6; // eax
  IMDLCache *v7; // eax
  KeyValues *v8; // eax
  const char *v9; // edx
  KeyValues *v10; // eax

  if ( pRelativePath != nullptr )
  {
    v3 = vgui::MDLCache();
    v4 = v3->FindMDL(this: v3, a2: pRelativePath);
  }
  else
  {
    v4 = 0xFFFF;
  }
  if ( (_WORD)v4 == this->m_hSelectedMDL )
  {
    if ( (_WORD)v4 != 0xFFFF )
    {
      v5 = vgui::MDLCache();
      v5->Release(this: v5, a2: v4);
    }
  }
  else
  {
    this->m_hSelectedMDL = v4;
    v6 = vgui::MDLCache();
    if ( v6->IsErrorModel(this: v6, a2: this->m_hSelectedMDL) )
      this->m_hSelectedMDL = -1;
    this->m_pMDLPreview->SetMDL_2(this: this->m_pMDLPreview, a2: this->m_hSelectedMDL, a3: nullptr);
    CMDLPanel::LookAtMDL(this: this->m_pMDLPreview);
    if ( (this->m_nFlags & 8) != 0 )
      CMDLPicker::UpdateSkinsList(this);
    if ( (this->m_nFlags & 0x10) != 0 )
      CMDLPicker::UpdateInfoTab(this, a2: (int)pRelativePath);
    if ( (this->m_nFlags & 6) != 0 )
      CMDLPicker::RefreshActivitiesAndSequencesList(this, m_hSelectedMDL: (int)this);
    if ( (_WORD)v4 != 0xFFFF )
    {
      v7 = vgui::MDLCache();
      v7->Release(this: v7, a2: v4);
    }
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
    {
      v9 = pRelativePath;
      if ( pRelativePath == nullptr )
        v9 = defaultValue;
      v10 = KeyValues::KeyValues(this: v8, setName: "MDLPreviewChanged", firstKey: "mdl", firstValue: v9);
      this->PostActionSignal(this, a2: v10);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004BCB00
// Name: private: virtual void CMDLPicker::OnSelectedAssetPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnSelectedAssetPicked(CMDLPicker *this, const char *pMDLName)
{
  char pRelativePath[260]; // [esp+4h] [ebp-104h] BYREF

  if ( pMDLName != nullptr )
  {
    V_snprintf(pDest: pRelativePath, maxLen: 260, pFormat: "models\\%s", pMDLName);
    CMDLPicker::SelectMDL(this, pRelativePath);
  }
  else
  {
    CMDLPicker::SelectMDL(this, pRelativePath: nullptr);
  }
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1020BDF0
// Name: public: static char const __near * CMDLPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMDLPicker::GetPanelClassName()
{
  return "CMDLPicker";
}

//------------------------------------------------------------------------------
// Address: 0x1020BE00
// Name: public: static char const __near * CMDLPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMDLPickerFrame::GetPanelClassName()
{
  return "CMDLPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x1020BE10
// Name: private: void CMDLPicker::RefreshRenderSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::RefreshRenderSettings(CMDLPicker *this)
{
  vgui::PropertyPage *m_pRenderPage; // ecx
  vgui::Panel *ChildByName; // edi
  char v4; // al
  vgui::Panel *v5; // edi
  char v6; // al
  vgui::Panel *v7; // edi
  char v8; // al
  vgui::Panel *v9; // edi
  char v10; // al
  vgui::Panel *v11; // edi
  char v12; // al

  m_pRenderPage = this->m_pRenderPage;
  if ( m_pRenderPage != nullptr )
  {
    ChildByName = vgui::Panel::FindChildByName(this: m_pRenderPage, childName: "NoGround", recurseDown: false);
    ChildByName->AddActionSignalTarget_2(this: ChildByName, a2: this);
    v4 = ((int (__thiscall *)(vgui::Panel *))ChildByName->__vftable[1].SetAutoDelete)(a1: ChildByName);
    CMDLPanel::SetGroundGrid(this: this->m_pMDLPreview, bVisible: v4 == 0);
    v5 = vgui::Panel::FindChildByName(this: this->m_pRenderPage, childName: "Collision", recurseDown: false);
    v5->AddActionSignalTarget_2(this: v5, a2: this);
    v6 = ((int (__thiscall *)(vgui::Panel *))v5->__vftable[1].SetAutoDelete)(a1: v5);
    CMDLPanel::SetCollsionModel(this: this->m_pMDLPreview, bVisible: v6);
    v7 = vgui::Panel::FindChildByName(this: this->m_pRenderPage, childName: "Wireframe", recurseDown: false);
    v7->AddActionSignalTarget_2(this: v7, a2: this);
    v8 = ((int (__thiscall *)(vgui::Panel *))v7->__vftable[1].SetAutoDelete)(a1: v7);
    CMDLPanel::SetWireFrame(this: this->m_pMDLPreview, bVisible: v8);
    v9 = vgui::Panel::FindChildByName(this: this->m_pRenderPage, childName: "LockView", recurseDown: false);
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    v10 = ((int (__thiscall *)(vgui::Panel *))v9->__vftable[1].SetAutoDelete)(a1: v9);
    CMDLPanel::SetLockView(this: this->m_pMDLPreview, bLocked: v10);
    v11 = vgui::Panel::FindChildByName(this: this->m_pRenderPage, childName: "LookAtCamera", recurseDown: false);
    v11->AddActionSignalTarget_2(this: v11, a2: this);
    v12 = ((int (__thiscall *)(vgui::Panel *))v11->__vftable[1].SetAutoDelete)(a1: v11);
    CMDLPanel::SetLookAtCamera(this: this->m_pMDLPreview, bLookAtCamera: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020BF50
// Name: public: virtual void CMDLPicker::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::PerformLayout(CMDLPicker *this)
{
  int w; // [esp+4h] [ebp-8h] BYREF
  int h; // [esp+8h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  vgui::Panel::SetBounds(this: this->m_pFileBrowserSplitter, x: 0, y: 0, wide: w, tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x1020BF90
// Name: private: virtual void CMDLPicker::OnAssetSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnAssetSelected(CMDLPicker *this, KeyValues *pParams)
{
  const char *String; // eax
  bool v4; // al
  vgui::MessageBox *v5; // edi
  vgui::Panel *v6; // eax
  vgui::MessageBox *v7; // eax
  char pBuf[1024]; // [esp+4h] [ebp-504h] BYREF
  char pProbeBuf[260]; // [esp+404h] [ebp-104h] BYREF

  String = KeyValues::GetString(this: pParams, keyName: "asset", defaultValue: &var);
  V_snprintf(pDest: pProbeBuf, maxLen: 260, pFormat: "materials/lightprobes/%s", String);
  BeginDMXContext();
  pParams = nullptr;
  v4 = UnserializeDMX(pFileName: pProbeBuf, pPathID: "GAME", bTextMode: true, ppRoot: (CDmxElement **)&pParams);
  if ( pParams != nullptr && v4 )
  {
    CPotteryWheelPanel::SetLightProbe(this: this->m_pMDLPreview, pLightProbe: (CDmxElement *)pParams);
    EndDMXContext(bDecommitMemory: true);
  }
  else
  {
    V_snprintf(pDest: pBuf, maxLen: 1024, pFormat: "Error loading lightprobe file '%s'!\n", pProbeBuf);
    v5 = (vgui::MessageBox *)operator new(nSize: 0x234u);
    if ( v5 != nullptr )
    {
      v6 = this->GetParent(this);
      v7 = vgui::MessageBox::MessageBox(this: v5, title: "Error Loading File!\n", text: pBuf, parent: v6);
    }
    else
    {
      v7 = nullptr;
    }
    v7->DoModal_2(this: v7, a2: nullptr);
    EndDMXContext(bDecommitMemory: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C090
// Name: public: virtual void CMDLPicker::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnCommand(CMDLPicker *this, const char *pCommand)
{
  CAssetPickerFrame *v3; // eax
  CAssetPickerFrame *v4; // eax

  if ( _V_stricmp(s1: pCommand, s2: "ChooseLightProbe") != 0 )
  {
    CBaseAssetPicker::OnCommand(this, pCommand);
  }
  else
  {
    v3 = (CAssetPickerFrame *)operator new(nSize: 0x228u);
    if ( v3 != nullptr )
    {
      v4 = CAssetPickerFrame::CAssetPickerFrame(
             this: v3,
             pParent: this,
             pTitle: "Select Light Probe (.prb) File",
             pAssetType: "Light Probe",
             pExt: "prb",
             pSubDir: "materials/lightprobes",
             pTextType: "lightprobe");
      CBaseAssetPickerFrame::DoModal(this: v4, pKeyValues: nullptr);
    }
    else
    {
      CBaseAssetPickerFrame::DoModal(this: nullptr, pKeyValues: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C110
// Name: private: virtual void CMDLPicker::OnCheckButtonChecked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMDLPicker::OnCheckButtonChecked(CMDLPicker *this@<ecx>, int a2@<ebx>, int a3@<edi>, KeyValues *kv)
{
  CBaseAssetPicker::OnCheckButtonChecked(this, a2, a3, kv);
  CMDLPicker::RefreshRenderSettings(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020C130
// Name: public: void CMDLPicker::GetSelectedMDLName(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::GetSelectedMDLName(CMDLPicker *this, char *pBuffer, int nMaxLen)
{
  const char *SelectedAsset; // eax

  if ( CBaseAssetPicker::GetSelectedAssetCount(this) <= 0 )
  {
    *pBuffer = 0;
  }
  else
  {
    SelectedAsset = CBaseAssetPicker::GetSelectedAsset(this, nSelectionIndex: -1);
    V_snprintf(pDest: pBuffer, maxLen: nMaxLen, pFormat: "models\\%s", SelectedAsset);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C170
// Name: public: char const __near * CMDLPicker::GetSelectedSequenceName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMDLPicker::GetSelectedSequenceName(CMDLPicker *this)
{
  int v2; // eax
  KeyValues *v3; // eax

  if ( this->m_pSequencesPage == nullptr )
    return nullptr;
  v2 = this->m_pSequencesList->GetSelectedItem(this: this->m_pSequencesList, a2: 0);
  if ( v2 < 0 )
    return nullptr;
  v3 = this->m_pSequencesList->GetItem(this: this->m_pSequencesList, a2: v2);
  return KeyValues::GetString(this: v3, keyName: "sequence", defaultValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1020C1C0
// Name: public: char const __near * CMDLPicker::GetSelectedActivityName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMDLPicker::GetSelectedActivityName(CMDLPicker *this)
{
  int v2; // eax
  KeyValues *v3; // eax

  if ( this->m_pActivitiesPage == nullptr )
    return nullptr;
  v2 = this->m_pActivitiesList->GetSelectedItem(this: this->m_pActivitiesList, a2: 0);
  if ( v2 < 0 )
    return nullptr;
  v3 = this->m_pActivitiesList->GetItem(this: this->m_pActivitiesList, a2: v2);
  return KeyValues::GetString(this: v3, keyName: "activity", defaultValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1020C210
// Name: public: int CMDLPicker::GetSelectedSkin(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDLPicker::GetSelectedSkin(CMDLPicker *this)
{
  int v2; // eax

  if ( this->m_pSkinsPage == nullptr )
    return 0;
  v2 = this->m_pSkinsList->GetSelectedItem(this: this->m_pSkinsList, a2: 0);
  return v2 < 0 ? 0 : v2;
}

//------------------------------------------------------------------------------
// Address: 0x1020C240
// Name: public: void CMDLPicker::SelectActivity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::SelectActivity(CMDLPicker *this, const char *pActivityName)
{
  IMDLCache *v3; // eax
  studiohdr_t *v4; // esi
  int i; // edi
  int v6; // eax
  int v7; // eax
  mstudioseqdesc_t *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax

  v3 = vgui::MDLCache();
  v4 = v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  for ( i = 0; ; ++i )
  {
    v6 = v4->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v4) : v4->numlocalseq;
    if ( i >= v6 )
      break;
    if ( v4->numincludemodels != 0 )
    {
      v8 = studiohdr_t::pSeqdesc_Internal(this: v4, i);
    }
    else
    {
      v7 = i;
      if ( i < 0 || i >= v4->numlocalseq )
        v7 = 0;
      v8 = (mstudioseqdesc_t *)((char *)v4 + 212 * v7 + v4->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v8 + v8->szactivitynameindex, s2: pActivityName) == 0 )
    {
      CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: i);
      break;
    }
  }
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
  {
    v10 = KeyValues::KeyValues(
            this: v9,
            setName: "SequenceSelectionChanged",
            firstKey: "activity",
            firstValue: pActivityName);
    this->PostActionSignal(this, a2: v10);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C330
// Name: public: void CMDLPicker::SelectSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::SelectSequence(CMDLPicker *this, const char *pSequenceName)
{
  IMDLCache *v3; // eax
  studiohdr_t *v4; // esi
  int i; // edi
  int v6; // eax
  int v7; // eax
  mstudioseqdesc_t *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax

  v3 = vgui::MDLCache();
  v4 = v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  for ( i = 0; ; ++i )
  {
    v6 = v4->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v4) : v4->numlocalseq;
    if ( i >= v6 )
      break;
    if ( v4->numincludemodels != 0 )
    {
      v8 = studiohdr_t::pSeqdesc_Internal(this: v4, i);
    }
    else
    {
      v7 = i;
      if ( i < 0 || i >= v4->numlocalseq )
        v7 = 0;
      v8 = (mstudioseqdesc_t *)((char *)v4 + 212 * v7 + v4->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v8 + v8->szlabelindex, s2: pSequenceName) == 0 )
    {
      CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: i);
      break;
    }
  }
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
  {
    v10 = KeyValues::KeyValues(
            this: v9,
            setName: "SequenceSelectionChanged",
            firstKey: "sequence",
            firstValue: pSequenceName);
    this->PostActionSignal(this, a2: v10);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C420
// Name: public: void CMDLPicker::SelectSkin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::SelectSkin(CMDLPicker *this, int nSkin)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  CMDLPanel::SetSkin(this: this->m_pMDLPreview, nSkin);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "SkinSelectionChanged", firstKey: "skin", firstValue: nSkin);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C480
// Name: private: virtual void CMDLPicker::OnItemSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnItemSelected(CMDLPicker *this, KeyValues *kv)
{
  vgui::ListPanel *Ptr; // eax
  vgui::ListPanel *m_pSequencesList; // ecx
  const char *SelectedSequenceName; // eax
  vgui::ListPanel *m_pActivitiesList; // ecx
  const char *SelectedActivityName; // eax
  vgui::ListPanel *m_pSkinsList; // ecx
  int v9; // eax

  Ptr = (vgui::ListPanel *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
  m_pSequencesList = this->m_pSequencesList;
  if ( m_pSequencesList != nullptr && Ptr == m_pSequencesList )
  {
    SelectedSequenceName = CMDLPicker::GetSelectedSequenceName(this);
    if ( SelectedSequenceName != nullptr )
      CMDLPicker::SelectSequence(this, pSequenceName: SelectedSequenceName);
  }
  else
  {
    m_pActivitiesList = this->m_pActivitiesList;
    if ( m_pActivitiesList != nullptr && Ptr == m_pActivitiesList )
    {
      SelectedActivityName = CMDLPicker::GetSelectedActivityName(this);
      if ( SelectedActivityName != nullptr )
        CMDLPicker::SelectActivity(this, pActivityName: SelectedActivityName);
    }
    else
    {
      m_pSkinsList = this->m_pSkinsList;
      if ( m_pSkinsList != nullptr && Ptr == m_pSkinsList )
      {
        if ( this->m_pSkinsPage != nullptr )
        {
          v9 = m_pSkinsList->GetSelectedItem(this: m_pSkinsList, a2: 0);
          CMDLPicker::SelectSkin(this, nSkin: v9 < 0 ? 0 : v9);
        }
        else
        {
          CMDLPicker::SelectSkin(this, nSkin: 0);
        }
      }
      else
      {
        CBaseAssetPicker::OnItemSelected(this, kv);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C550
// Name: private: virtual void CMDLPicker::OnPageChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnPageChanged(CMDLPicker *this)
{
  const char *SelectedSequenceName; // eax
  const char *SelectedActivityName; // eax

  if ( this->m_pSequencesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pSequencesPage )
  {
    this->m_pSequencesList->RequestFocus(this: this->m_pSequencesList, a2: 0);
    SelectedSequenceName = CMDLPicker::GetSelectedSequenceName(this);
    if ( SelectedSequenceName != nullptr )
      CMDLPicker::SelectSequence(this, pSequenceName: SelectedSequenceName);
  }
  else if ( this->m_pActivitiesPage != nullptr
         && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pActivitiesPage )
  {
    this->m_pActivitiesList->RequestFocus(this: this->m_pActivitiesList, a2: 0);
    SelectedActivityName = CMDLPicker::GetSelectedActivityName(this);
    if ( SelectedActivityName != nullptr )
      CMDLPicker::SelectActivity(this, pActivityName: SelectedActivityName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020C5E0
// Name: private: int CMDLPicker::UpdateSkinsList(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDLPicker::UpdateSkinsList(CMDLPicker *this)
{
  int v2; // esi
  IMDLCache *v3; // eax
  int v4; // eax
  int v5; // ebx
  KeyValues *v6; // eax
  const KeyValues *v7; // eax
  char skinText[28]; // [esp+8h] [ebp-1Ch] BYREF

  v2 = 0;
  if ( this->m_pSkinsList == nullptr )
    return 0;
  this->m_pSkinsList->RemoveAll(this: this->m_pSkinsList);
  v3 = vgui::MDLCache();
  v4 = (int)v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  if ( v4 == 0 )
    return 0;
  v5 = *(_DWORD *)(v4 + 224);
  if ( v5 > 0 )
  {
    do
    {
      memset(skinText, 0, 25);
      sprintf(string: skinText, format: "skin%i", v2);
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "node", firstKey: "skin", firstValue: skinText);
      else
        v7 = nullptr;
      this->m_pSkinsList->AddItem(this: this->m_pSkinsList, a2: v7, a3: 0, a4: false, a5: false);
      ++v2;
    }
    while ( v2 < v5 );
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1020C6B0
// Name: private: int CMDLPicker::UpdatePropDataList(class KeyValues __near *,bool __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDLPicker::UpdatePropDataList(CMDLPicker *this, KeyValues *pkvPropData, bool *bIsStatic)
{
  int v3; // edi
  KeyValues *i; // esi
  const char *Name; // eax
  const char *String; // eax
  vgui::Panel *ChildByName; // eax
  KeyValues *v9; // edi
  const char *v10; // eax
  const KeyValues *v11; // eax
  const char *v13; // [esp-8h] [ebp-14h]
  int iCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  iCount = 0;
  if ( this->m_pPropDataList == nullptr )
    return 0;
  this->m_pPropDataList->RemoveAll(this: this->m_pPropDataList);
  for ( i = KeyValues::GetFirstSubKey(this: pkvPropData); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      Name = KeyValues::GetName(this: i);
      if ( _V_strcmp(s1: Name, s2: "allowstatic") == 0 )
      {
        String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &var);
        if ( _V_strcmp(s1: String, s2: "1") == 0 )
        {
          if ( !*bIsStatic )
          {
            ChildByName = vgui::Panel::FindChildByName(
                            this: this->m_pInfoPage,
                            childName: "StaticText",
                            recurseDown: false);
            ChildByName->SetVisible(this: ChildByName, a2: true);
          }
          *bIsStatic = *bIsStatic;
        }
      }
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
      {
        v13 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: &var);
        v10 = KeyValues::GetName(this: i);
        v11 = KeyValues::KeyValues(
                this: v9,
                setName: "node",
                firstKey: "key",
                firstValue: v10,
                secondKey: "value",
                secondValue: v13);
      }
      else
      {
        v11 = nullptr;
      }
      this->m_pPropDataList->AddItem(this: this->m_pPropDataList, a2: v11, a3: 0, a4: false, a5: false);
      v3 = ++iCount;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1020C800
// Name: public: virtual struct vgui::PanelMessageMap __near * CMDLPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMDLPicker::GetMessageMap(CMDLPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMDLPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPicker::GetMessageMap'::`2'::s_pMap;
  `CMDLPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
  `CMDLPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020C830
// Name: public: virtual struct PanelAnimationMap __near * CMDLPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMDLPicker::GetAnimMap(CMDLPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CMDLPicker");
}

//------------------------------------------------------------------------------
// Address: 0x1020C840
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMDLPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMDLPicker::GetKBMap(CMDLPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMDLPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPicker::GetKBMap'::`2'::s_pMap;
  `CMDLPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPicker");
  `CMDLPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020C870
// Name: public: virtual struct vgui::PanelMessageMap __near * CMDLPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMDLPickerFrame::GetMessageMap(CMDLPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMDLPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CMDLPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMDLPickerFrame");
  `CMDLPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020C8A0
// Name: public: virtual struct PanelAnimationMap __near * CMDLPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMDLPickerFrame::GetAnimMap(CMDLPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CMDLPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x1020C8B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMDLPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMDLPickerFrame::GetKBMap(CMDLPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMDLPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPickerFrame::GetKBMap'::`2'::s_pMap;
  `CMDLPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPickerFrame");
  `CMDLPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020C940
// Name: private: void CMDLPicker::UpdateInfoTab(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMDLPicker::UpdateInfoTab(CMDLPicker *this@<ecx>, int a2@<ebx>)
{
  IMDLCache *v3; // eax
  int v4; // eax
  _DWORD *v5; // esi
  vgui::PropertyPage *m_pInfoPage; // ecx
  vgui::Panel *ChildByName; // ebx
  vgui::PropertyPage *v8; // ecx
  vgui::Panel *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  const char *v12; // eax
  KeyValues *Key; // eax
  vgui::Panel *v14; // esi
  vgui::Panel *v15; // esi
  vgui::Panel *v16; // esi
  char massBuff[12]; // [esp+8h] [ebp-14h] BYREF
  int bIsStatic; // [esp+14h] [ebp-8h] BYREF
  int bIsPhysics; // [esp+18h] [ebp-4h]

  v3 = vgui::MDLCache();
  v4 = (int)v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  v5 = (_DWORD *)v4;
  if ( v4 != 0 )
  {
    m_pInfoPage = this->m_pInfoPage;
    bIsStatic = (int)*(float *)(v4 + 328);
    ChildByName = vgui::Panel::FindChildByName(this: m_pInfoPage, childName: "MassValue", recurseDown: false);
    V_snprintf(pDest: massBuff, maxLen: 10, pFormat: "%d", bIsStatic);
    ((void (__thiscall *)(vgui::Panel *, char *, int))ChildByName->__vftable[1].Think)(
      a1: ChildByName,
      a2: massBuff,
      a3: a2);
    v8 = this->m_pInfoPage;
    LOBYTE(bIsStatic) = (v5[38] & 0x10) != 0;
    LOBYTE(bIsPhysics) = 0;
    v9 = vgui::Panel::FindChildByName(this: v8, childName: "StaticText", recurseDown: false);
    v9->SetVisible(this: v9, a2: false);
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "modelkeys");
    else
      v11 = nullptr;
    if ( v5[79] != 0 )
      v12 = (char *)v5 + v5[78];
    else
      v12 = nullptr;
    KeyValues::LoadFromBuffer(
      this: v11,
      resourceName: "modelkeys",
      pBuffer: v12,
      pFileSystem: nullptr,
      pPathID: nullptr,
      pfnEvaluateSymbolProc: nullptr);
    Key = KeyValues::FindKey(this: v11, keyName: "prop_data", bCreate: false);
    if ( Key != nullptr )
    {
      if ( CMDLPicker::UpdatePropDataList(this, pkvPropData: Key, (bool *)&bIsStatic) != 0 )
        LOBYTE(bIsPhysics) = 1;
    }
    else
    {
      this->m_pPropDataList->RemoveAll(this: this->m_pPropDataList);
    }
    KeyValues::deleteThis(this: v11);
    v14 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "StaticObject", recurseDown: false);
    ((void (__thiscall *)(vgui::Panel *, int))v14->__vftable[1].GetPaintSize)(a1: v14, a2: 1);
    ((void (__thiscall *)(vgui::Panel *, int))v14->__vftable[1].LookupElementBounds)(a1: v14, a2: bIsStatic);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v14->__vftable[1].GetPaintSize)(a1: v14, a2: 0);
    v15 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "PhysicsObject", recurseDown: false);
    ((void (__thiscall *)(vgui::Panel *, int))v15->__vftable[1].GetPaintSize)(a1: v15, a2: 1);
    ((void (__thiscall *)(vgui::Panel *, int))v15->__vftable[1].LookupElementBounds)(a1: v15, a2: bIsPhysics);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v15->__vftable[1].GetPaintSize)(a1: v15, a2: 0);
    v16 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "DynamicObject", recurseDown: false);
    ((void (__thiscall *)(vgui::Panel *, int))v16->__vftable[1].GetPaintSize)(a1: v16, a2: 1);
    ((void (__thiscall *)(vgui::Panel *, bool))v16->__vftable[1].LookupElementBounds)(
      a1: v16,
      a2: (_BYTE)bIsPhysics == 0);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v16->__vftable[1].GetPaintSize)(a1: v16, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020DA10
// Name: public: static void CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar(int a1@<ebp>)
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
  if ( !`CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded )
  {
    `CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSoundPicker::`vcall'{1012,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AssetSelected";
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
// Address: 0x1020DAA0
// Name: public: static void CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1004,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
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
// Address: 0x1020DB30
// Name: public: static void CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
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
// Address: 0x1020DBC0
// Name: public: static void CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar(int a1@<ebp>)
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
  if ( !`CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded )
  {
    `CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1016,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
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
// Address: 0x1020DC50
// Name: public: CMDLPicker::CMDLPicker(class vgui::Panel __near *,int)
// Source: json
//------------------------------------------------------------------------------
CMDLPicker *__thiscall CMDLPicker::CMDLPicker(CMDLPicker *this, vgui::Panel *pParent, int nFlags)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int v7; // edx
  vgui::Splitter *v8; // eax
  vgui::Splitter *v9; // eax
  vgui::Panel *Child; // edi
  vgui::Panel *v11; // ebx
  vgui::Splitter *v12; // eax
  vgui::Splitter *v13; // eax
  vgui::Panel *v14; // edi
  vgui::Panel *v15; // ebx
  CMDLPanel *v16; // eax
  CMDLPanel *v17; // eax
  vgui::PropertySheet *v18; // eax
  vgui::PropertySheet *v19; // eax
  char v20; // bl
  vgui::PropertyPage *v21; // eax
  vgui::PropertyPage *v22; // eax
  vgui::Panel *ChildByName; // eax
  vgui::PropertyPage *v24; // eax
  vgui::PropertyPage *v25; // eax
  vgui::ListPanel *v26; // eax
  vgui::ListPanel *v27; // eax
  vgui::PropertyPage *v28; // eax
  vgui::PropertyPage *v29; // eax
  vgui::ListPanel *v30; // eax
  vgui::ListPanel *v31; // eax
  vgui::PropertyPage *v32; // eax
  vgui::PropertyPage *v33; // eax
  vgui::ListPanel *v34; // eax
  vgui::ListPanel *v35; // eax
  vgui::PropertyPage *v36; // eax
  vgui::PropertyPage *v37; // eax
  vgui::Panel *v38; // edi
  vgui::Panel_vtbl *v39; // ebx
  Color *v40; // eax
  vgui::Panel_vtbl *v41; // ebx
  Color *v42; // eax
  vgui::Panel *v43; // edi
  vgui::Panel_vtbl *v44; // ebx
  Color *v45; // eax
  vgui::Panel_vtbl *v46; // ebx
  Color *v47; // eax
  vgui::Panel *v48; // edi
  vgui::Panel_vtbl *v49; // ebx
  Color *v50; // eax
  vgui::Panel_vtbl *v51; // ebx
  Color *v52; // eax
  vgui::ListPanel *v53; // eax
  vgui::ListPanel *v54; // eax
  vgui::PropertyPage *m_pRenderPage; // eax
  vgui::PropertyPage *m_pSequencesPage; // eax
  vgui::PropertyPage *m_pActivitiesPage; // eax
  vgui::PropertyPage *m_pSkinsPage; // eax
  vgui::PropertyPage *m_pInfoPage; // eax
  float flFractions[2]; // [esp+Ch] [ebp-8h] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  CBaseAssetPicker::CBaseAssetPicker(
    this,
    pParent,
    pAssetType: "MDL Files",
    pExt: "mdl",
    pSubDir: "models",
    pTextType: "mdlName",
    pAssetSearchPath: "GAME");
  this->__vftable = (CMDLPicker_vtbl *)&CMDLPicker::`vftable';
  if ( `CMDLPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPicker::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
    v4->pfnClassName = CMDLPicker::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CMDLPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMDLPicker::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CMDLPicker");
    v5->pfnClassName = CMDLPicker::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CMDLPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPicker::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPicker");
    v6->pfnClassName = CMDLPicker::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  }
  CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar(a1: (int)&savedregs);
  CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar(a1: (int)&savedregs);
  v7 = nFlags;
  this->m_hSelectedMDL = -1;
  this->m_nFlags = v7;
  this->m_pRenderPage = nullptr;
  this->m_pSequencesPage = nullptr;
  this->m_pActivitiesPage = nullptr;
  this->m_pSkinsPage = nullptr;
  this->m_pInfoPage = nullptr;
  this->m_pSequencesList = nullptr;
  this->m_pActivitiesList = nullptr;
  v8 = (vgui::Splitter *)operator new(nSize: 0x198u);
  if ( v8 != nullptr )
    v9 = vgui::Splitter::Splitter(
           this: v8,
           parent: this,
           name: "FileBrowserSplitter",
           mode: SPLITTER_MODE_VERTICAL,
           nCount: 1);
  else
    v9 = nullptr;
  flFractions[0] = 0.33000001;
  this->m_pFileBrowserSplitter = v9;
  flFractions[1] = 0.67000002;
  vgui::Splitter::RespaceSplitters(this: v9, flFractions);
  Child = vgui::Panel::GetChild(this: this->m_pFileBrowserSplitter, index: 0);
  v11 = vgui::Panel::GetChild(this: this->m_pFileBrowserSplitter, index: 1);
  Child->RequestFocus(this: Child, a2: 0);
  CBaseAssetPicker::CreateStandardControls(this, pParent: Child, bAllowMultiselect: false);
  v12 = (vgui::Splitter *)operator new(nSize: 0x198u);
  if ( v12 != nullptr )
    v13 = vgui::Splitter::Splitter(
            this: v12,
            parent: v11,
            name: "PreviewSplitter",
            mode: SPLITTER_MODE_HORIZONTAL,
            nCount: 1);
  else
    v13 = nullptr;
  this->m_pPreviewSplitter = v13;
  v14 = vgui::Panel::GetChild(this: v13, index: 0);
  v15 = vgui::Panel::GetChild(this: this->m_pPreviewSplitter, index: 1);
  v16 = (CMDLPanel *)operator new(nSize: 0xBE4u);
  if ( v16 != nullptr )
    v17 = CMDLPanel::CMDLPanel(this: v16, pParent: v14, pName: "MDLPreview");
  else
    v17 = nullptr;
  this->m_pMDLPreview = v17;
  vgui::Panel::SetSkipChildDuringPainting(this, child: v17);
  v18 = (vgui::PropertySheet *)operator new(nSize: 0x210u);
  if ( v18 != nullptr )
    v19 = vgui::PropertySheet::PropertySheet(this: v18, parent: v15, panelName: "ViewsSheet", draggableTabs: false);
  else
    v19 = nullptr;
  this->m_pViewsSheet = v19;
  v19->AddActionSignalTarget_2(this: v19, a2: this);
  v20 = nFlags;
  if ( (nFlags & 1) != 0 )
  {
    v21 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
    if ( v21 != nullptr )
      v22 = vgui::PropertyPage::PropertyPage(this: v21, parent: this->m_pViewsSheet, panelName: "RenderPage");
    else
      v22 = nullptr;
    this->m_pRenderPage = v22;
    v22->AddActionSignalTarget_2(this: v22, a2: this);
    this->m_pRenderPage->LoadControlSettingsAndUserConfig(
      this: this->m_pRenderPage,
      a2: "resource/mdlpickerrender.res",
      a3: 0);
    CMDLPicker::RefreshRenderSettings(this);
    ChildByName = vgui::Panel::FindChildByName(
                    this: this->m_pRenderPage,
                    childName: "ChooseLightProbe",
                    recurseDown: false);
    ChildByName->AddActionSignalTarget_2(this: ChildByName, a2: this);
  }
  if ( (v20 & 2) != 0 )
  {
    v24 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
    if ( v24 != nullptr )
      v25 = vgui::PropertyPage::PropertyPage(this: v24, parent: this->m_pViewsSheet, panelName: "SequencesPage");
    else
      v25 = nullptr;
    this->m_pSequencesPage = v25;
    v26 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
    if ( v26 != nullptr )
      v27 = vgui::ListPanel::ListPanel(this: v26, parent: this->m_pSequencesPage, panelName: "SequencesList");
    else
      v27 = nullptr;
    this->m_pSequencesList = v27;
    v27->AddColumnHeader(this: v27, a2: 0, a3: "sequence", a4: "sequence", a5: 52, a6: 0);
    this->m_pSequencesList->AddActionSignalTarget_2(this: this->m_pSequencesList, a2: this);
    this->m_pSequencesList->SetSelectIndividualCells(this: this->m_pSequencesList, a2: true);
    this->m_pSequencesList->SetEmptyListText_2(this: this->m_pSequencesList, a2: "No .MDL file currently selected.");
    this->m_pSequencesList->SetDragEnabled(this: this->m_pSequencesList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pSequencesList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 6,
      nPinOffsetY: 6,
      nUnpinnedCornerOffsetX: -6,
      nUnpinnedCornerOffsetY: -6);
  }
  if ( (v20 & 4) != 0 )
  {
    v28 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
    if ( v28 != nullptr )
      v29 = vgui::PropertyPage::PropertyPage(this: v28, parent: this->m_pViewsSheet, panelName: "ActivitiesPage");
    else
      v29 = nullptr;
    this->m_pActivitiesPage = v29;
    v30 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
    if ( v30 != nullptr )
      v31 = vgui::ListPanel::ListPanel(this: v30, parent: this->m_pActivitiesPage, panelName: "ActivitiesList");
    else
      v31 = nullptr;
    this->m_pActivitiesList = v31;
    v31->AddColumnHeader(this: v31, a2: 0, a3: "activity", a4: "activity", a5: 52, a6: 0);
    this->m_pActivitiesList->AddActionSignalTarget_2(this: this->m_pActivitiesList, a2: this);
    this->m_pActivitiesList->SetSelectIndividualCells(this: this->m_pActivitiesList, a2: true);
    this->m_pActivitiesList->SetEmptyListText_2(this: this->m_pActivitiesList, a2: "No .MDL file currently selected.");
    this->m_pActivitiesList->SetDragEnabled(this: this->m_pActivitiesList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pActivitiesList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 6,
      nPinOffsetY: 6,
      nUnpinnedCornerOffsetX: -6,
      nUnpinnedCornerOffsetY: -6);
  }
  if ( (v20 & 8) != 0 )
  {
    v32 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
    if ( v32 != nullptr )
      v33 = vgui::PropertyPage::PropertyPage(this: v32, parent: this->m_pViewsSheet, panelName: "SkinsPage");
    else
      v33 = nullptr;
    this->m_pSkinsPage = v33;
    v34 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
    if ( v34 != nullptr )
      v35 = vgui::ListPanel::ListPanel(this: v34, parent: this->m_pSkinsPage, panelName: "SkinsList");
    else
      v35 = nullptr;
    this->m_pSkinsList = v35;
    v35->AddColumnHeader(this: v35, a2: 0, a3: "skin", a4: "skin", a5: 52, a6: 0);
    this->m_pSkinsList->AddActionSignalTarget_2(this: this->m_pSkinsList, a2: this);
    this->m_pSkinsList->SetSelectIndividualCells(this: this->m_pSkinsList, a2: true);
    this->m_pSkinsList->SetEmptyListText_2(this: this->m_pSkinsList, a2: "No .MDL file currently selected.");
    this->m_pSkinsList->SetDragEnabled(this: this->m_pSkinsList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pSkinsList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 6,
      nPinOffsetY: 6,
      nUnpinnedCornerOffsetX: -6,
      nUnpinnedCornerOffsetY: -6);
  }
  if ( (v20 & 0x10) != 0 )
  {
    v36 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
    if ( v36 != nullptr )
      v37 = vgui::PropertyPage::PropertyPage(this: v36, parent: this->m_pViewsSheet, panelName: "InfoPage");
    else
      v37 = nullptr;
    this->m_pInfoPage = v37;
    v37->AddActionSignalTarget_2(this: v37, a2: this);
    this->m_pInfoPage->LoadControlSettingsAndUserConfig(
      this: this->m_pInfoPage,
      a2: "resource/mdlpickerinfo.res",
      a3: 0);
    v38 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "PhysicsObject", recurseDown: false);
    v39 = v38->__vftable;
    v40 = v38->GetFgColor(this: v38, result: (Color *)&nFlags);
    v39[1].OnChildAdded(this: v38, a2: (unsigned int)*v40);
    v41 = v38->__vftable;
    v42 = v38->GetFgColor(this: v38, result: (Color *)&nFlags);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v41[1].OnSizeChanged)(a1: v38, a2: *v42);
    v43 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "StaticObject", recurseDown: false);
    v44 = v43->__vftable;
    v45 = v43->GetFgColor(this: v43, result: (Color *)&nFlags);
    v44[1].OnChildAdded(this: v43, a2: (unsigned int)*v45);
    v46 = v43->__vftable;
    v47 = v43->GetFgColor(this: v43, result: (Color *)&nFlags);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v46[1].OnSizeChanged)(a1: v43, a2: *v47);
    v48 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "DynamicObject", recurseDown: false);
    v49 = v48->__vftable;
    v50 = v48->GetFgColor(this: v48, result: (Color *)&nFlags);
    v49[1].OnChildAdded(this: v48, a2: (unsigned int)*v50);
    v51 = v48->__vftable;
    v52 = v48->GetFgColor(this: v48, result: (Color *)&nFlags);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v51[1].OnSizeChanged)(a1: v48, a2: *v52);
    v53 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
    if ( v53 != nullptr )
      v54 = vgui::ListPanel::ListPanel(this: v53, parent: this->m_pInfoPage, panelName: "PropData");
    else
      v54 = nullptr;
    this->m_pPropDataList = v54;
    v54->AddColumnHeader(this: v54, a2: 0, a3: "key", a4: "key", a5: 250, a6: 1);
    this->m_pPropDataList->AddColumnHeader(this: this->m_pPropDataList, a2: 1, a3: "value", a4: "value", a5: 52, a6: 0);
    this->m_pPropDataList->AddActionSignalTarget_2(this: this->m_pPropDataList, a2: this);
    this->m_pPropDataList->SetSelectIndividualCells(this: this->m_pPropDataList, a2: false);
    this->m_pPropDataList->SetEmptyListText_2(this: this->m_pPropDataList, a2: "No prop_data available.");
    this->m_pPropDataList->SetDragEnabled(this: this->m_pPropDataList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pPropDataList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 6,
      nPinOffsetY: 72,
      nUnpinnedCornerOffsetX: -6,
      nUnpinnedCornerOffsetY: -6);
    CMDLPicker::RefreshRenderSettings(this);
  }
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/mdlpicker.res", dialogID: 0);
  m_pRenderPage = this->m_pRenderPage;
  if ( m_pRenderPage != nullptr )
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: m_pRenderPage,
      a3: "Render",
      a4: nullptr,
      a5: false,
      a6: -1);
  m_pSequencesPage = this->m_pSequencesPage;
  if ( m_pSequencesPage != nullptr )
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: m_pSequencesPage,
      a3: "Sequences",
      a4: nullptr,
      a5: false,
      a6: -1);
  m_pActivitiesPage = this->m_pActivitiesPage;
  if ( m_pActivitiesPage != nullptr )
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: m_pActivitiesPage,
      a3: "Activities",
      a4: nullptr,
      a5: false,
      a6: -1);
  m_pSkinsPage = this->m_pSkinsPage;
  if ( m_pSkinsPage != nullptr )
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: m_pSkinsPage,
      a3: "Skins",
      a4: nullptr,
      a5: false,
      a6: -1);
  m_pInfoPage = this->m_pInfoPage;
  if ( m_pInfoPage != nullptr )
    this->m_pViewsSheet->AddPage(this: this->m_pViewsSheet, a2: m_pInfoPage, a3: "Info", a4: nullptr, a5: false, a6: -1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020E4C0
// Name: public: CMDLPickerFrame::CMDLPickerFrame(class vgui::Panel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CMDLPickerFrame *__thiscall CMDLPickerFrame::CMDLPickerFrame(
        CMDLPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        int nFlags)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  CMDLPicker *v8; // eax
  CMDLPicker *v9; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CMDLPickerFrame_vtbl *)&CMDLPickerFrame::`vftable';
  if ( `CMDLPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPickerFrame::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CMDLPickerFrame");
    v5->pfnClassName = CMDLPickerFrame::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CMDLPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMDLPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CMDLPickerFrame");
    v6->pfnClassName = CMDLPickerFrame::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CMDLPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPickerFrame");
    v7->pfnClassName = CMDLPickerFrame::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v8 = (CMDLPicker *)operator new(nSize: 0x284u);
  if ( v8 != nullptr )
    v9 = CMDLPicker::CMDLPicker(this: v8, pParent: this, nFlags);
  else
    v9 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v9);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/mdlpickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020E5C0
// Name: public: void CUtlDict<int,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,unsigned short>::RemoveAll(CUtlDict<int,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1020E690
// Name: public: unsigned short CUtlDict<int,unsigned short>::Insert(char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<int,unsigned short>::Insert(
        CUtlDict<int,unsigned short> *this,
        const char *pName,
        int *element)
{
  char *v4; // eax
  int v5; // edx
  CUtlMap<char const *,int,unsigned short>::Node_t insert; // [esp+8h] [ebp-8h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  v5 = *element;
  insert.key = v4;
  insert.elem = v5;
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Elements.m_Tree,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x1020E700
// Name: private: void CMDLPicker::RefreshActivitiesAndSequencesList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMDLPicker::RefreshActivitiesAndSequencesList(CMDLPicker *this@<ecx>, int m_hSelectedMDL@<esi>)
{
  int v3; // edi
  void (__thiscall *SetEmptyListText_2)(vgui::ListPanel *, const char *); // eax
  IMDLCache *v5; // eax
  studiohdr_t *v6; // eax
  studiohdr_t *v7; // esi
  int NumSeq_Internal; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v9; // ecx
  bool v10; // zf
  int v11; // eax
  int v12; // eax
  mstudioseqdesc_t *v13; // eax
  int v14; // eax
  mstudioseqdesc_t *v15; // eax
  const char *v16; // edi
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // esi
  IMDLCache *v21; // eax
  const char *v22; // eax
  int v23; // eax
  mstudioseqdesc_t *v24; // eax
  const char *v25; // esi
  KeyValues *v26; // eax
  KeyValues *v27; // eax
  int v28; // edi
  KeyValues *v29; // eax
  KeyValues *v30; // esi
  IMDLCache *v31; // eax
  const char *v32; // eax
  CUtlDict<int,unsigned short> activityNames; // [esp+8h] [ebp-30h] BYREF
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+24h] [ebp-14h] BYREF
  int nItemID; // [esp+2Ch] [ebp-Ch]
  studiohdr_t *hdr; // [esp+30h] [ebp-8h]
  int j; // [esp+34h] [ebp-4h] BYREF

  this->m_pActivitiesList->RemoveAll(this: this->m_pActivitiesList);
  this->m_pSequencesList->RemoveAll(this: this->m_pSequencesList);
  v3 = 0;
  CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: 0);
  SetEmptyListText_2 = this->m_pActivitiesList->SetEmptyListText_2;
  if ( this->m_hSelectedMDL == 0xFFFF )
  {
    ((void (__stdcall *)(const char *))SetEmptyListText_2)(a1: "No .MDL file currently selected");
    this->m_pSequencesList->SetEmptyListText_2(this: this->m_pSequencesList, a2: "No .MDL file currently selected");
  }
  else
  {
    ((void (__stdcall *)(const char *))SetEmptyListText_2)(a1: ".MDL file contains no activities");
    this->m_pSequencesList->SetEmptyListText_2(this: this->m_pSequencesList, a2: ".MDL file contains no sequences");
    v5 = vgui::MDLCache();
    v6 = v5->GetStudioHdr(this: v5, a2: this->m_hSelectedMDL);
    v7 = v6;
    hdr = v6;
    if ( v6->numincludemodels != 0 )
      NumSeq_Internal = studiohdr_t::GetNumSeq_Internal(this: v6);
    else
      NumSeq_Internal = v6->numlocalseq;
    v9 = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_nAllocationCount = NumSeq_Internal;
    activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
    if ( NumSeq_Internal != 0 )
    {
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: 16 * NumSeq_Internal);
      activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = v9;
    }
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_FirstFree = -1;
    activityNames.m_Elements.m_Tree.m_pElements = v9;
    activityNames.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    while ( 1 )
    {
      v10 = v7->numincludemodels == 0;
      j = v3;
      v11 = v10 ? v7->numlocalseq : studiohdr_t::GetNumSeq_Internal(this: v7);
      if ( v3 >= v11 )
        break;
      if ( v7->numincludemodels != 0 )
      {
        v13 = studiohdr_t::pSeqdesc_Internal(this: v7, i: v3);
      }
      else
      {
        v12 = v3;
        if ( v3 < 0 || v3 >= v7->numlocalseq )
          v12 = 0;
        v13 = (mstudioseqdesc_t *)((char *)v7 + 212 * v12 + v7->localseqindex);
      }
      if ( (v13->flags & 0x400) == 0 )
      {
        if ( v7->numincludemodels != 0 )
        {
          v15 = studiohdr_t::pSeqdesc_Internal(this: v7, i: v3);
        }
        else
        {
          v14 = v3;
          if ( v3 < 0 || v3 >= v7->numlocalseq )
            v14 = 0;
          v15 = (mstudioseqdesc_t *)((char *)v7 + 212 * v14 + v7->localseqindex);
        }
        v16 = (char *)v15 + v15->szactivitynameindex;
        if ( v16 != nullptr && *v16 != 0 )
        {
          search.key = (char *)v15 + v15->szactivitynameindex;
          if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                 this: &activityNames.m_Elements.m_Tree,
                 &search) == 0xFFFF )
          {
            v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v17 != nullptr )
              v18 = KeyValues::KeyValues(this: v17, setName: "node", firstKey: "activity", firstValue: v16);
            else
              v18 = nullptr;
            nItemID = ((int (__thiscall *)(vgui::ListPanel *, KeyValues *, _DWORD, _DWORD, _DWORD, int))this->m_pActivitiesList->AddItem)(
                        a1: this->m_pActivitiesList,
                        a2: v18,
                        a3: 0,
                        a4: 0,
                        a5: 0,
                        a6: m_hSelectedMDL);
            v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v19 != nullptr )
              v20 = KeyValues::KeyValues(this: v19, setName: "drag", firstKey: "text", firstValue: v16);
            else
              v20 = nullptr;
            KeyValues::SetString(this: v20, keyName: "texttype", value: "activityName");
            v21 = vgui::MDLCache();
            m_hSelectedMDL = this->m_hSelectedMDL;
            v22 = (const char *)((int (__thiscall *)(IMDLCache *))v21->GetModelName)(a1: v21);
            KeyValues::SetString(this: v20, keyName: "mdl", value: v22);
            vgui::ListPanel::SetItemDragData(this: this->m_pActivitiesList, itemID: nItemID, data: v20);
            CUtlDict<int,unsigned short>::Insert(this: &activityNames, pName: v16, element: &j);
            v7 = hdr;
          }
        }
        if ( v7->numincludemodels != 0 )
        {
          v24 = studiohdr_t::pSeqdesc_Internal(this: v7, i: j);
        }
        else
        {
          v23 = j;
          if ( j < 0 || j >= v7->numlocalseq )
            v23 = 0;
          v24 = (mstudioseqdesc_t *)((char *)v7 + 212 * v23 + v7->localseqindex);
        }
        v25 = (char *)v24 + v24->szlabelindex;
        if ( v25 != nullptr && *v25 != 0 )
        {
          v26 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v26 != nullptr )
            v27 = KeyValues::KeyValues(this: v26, setName: "node", firstKey: "sequence", firstValue: v25);
          else
            v27 = nullptr;
          v28 = ((int (__thiscall *)(vgui::ListPanel *, KeyValues *, _DWORD, _DWORD, _DWORD, int))this->m_pSequencesList->AddItem)(
                  a1: this->m_pSequencesList,
                  a2: v27,
                  a3: 0,
                  a4: 0,
                  a5: 0,
                  a6: m_hSelectedMDL);
          v29 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v29 != nullptr )
            v30 = KeyValues::KeyValues(this: v29, setName: "drag", firstKey: "text", firstValue: v25);
          else
            v30 = nullptr;
          KeyValues::SetString(this: v30, keyName: "texttype", value: "sequenceName");
          v31 = vgui::MDLCache();
          m_hSelectedMDL = this->m_hSelectedMDL;
          v32 = (const char *)((int (__thiscall *)(IMDLCache *))v31->GetModelName)(a1: v31);
          KeyValues::SetString(this: v30, keyName: "mdl", value: v32);
          vgui::ListPanel::SetItemDragData(this: this->m_pSequencesList, itemID: v28, data: v30);
        }
        v3 = j;
        v7 = hdr;
      }
      ++v3;
    }
    CUtlDict<int,unsigned short>::RemoveAll(this: &activityNames);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &activityNames.m_Elements.m_Tree);
    if ( activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && activityNames.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: activityNames.m_Elements.m_Tree.m_Elements.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020EAD0
// Name: public: void CMDLPicker::SelectMDL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::SelectMDL(CMDLPicker *this, const char *pRelativePath)
{
  IMDLCache *v3; // eax
  int v4; // edi
  IMDLCache *v5; // eax
  IMDLCache *v6; // eax
  IMDLCache *v7; // eax
  KeyValues *v8; // eax
  const char *v9; // edx
  KeyValues *v10; // eax

  if ( pRelativePath != nullptr )
  {
    v3 = vgui::MDLCache();
    v4 = v3->FindMDL(this: v3, a2: pRelativePath);
  }
  else
  {
    v4 = 0xFFFF;
  }
  if ( (_WORD)v4 == this->m_hSelectedMDL )
  {
    if ( (_WORD)v4 != 0xFFFF )
    {
      v5 = vgui::MDLCache();
      v5->Release(this: v5, a2: v4);
    }
  }
  else
  {
    this->m_hSelectedMDL = v4;
    v6 = vgui::MDLCache();
    if ( v6->IsErrorModel(this: v6, a2: this->m_hSelectedMDL) )
      this->m_hSelectedMDL = -1;
    this->m_pMDLPreview->SetMDL_2(this: this->m_pMDLPreview, a2: this->m_hSelectedMDL, a3: nullptr);
    CMDLPanel::LookAtMDL(this: this->m_pMDLPreview);
    if ( (this->m_nFlags & 8) != 0 )
      CMDLPicker::UpdateSkinsList(this);
    if ( (this->m_nFlags & 0x10) != 0 )
      CMDLPicker::UpdateInfoTab(this, a2: (int)pRelativePath);
    if ( (this->m_nFlags & 6) != 0 )
      CMDLPicker::RefreshActivitiesAndSequencesList(this, m_hSelectedMDL: (int)this);
    if ( (_WORD)v4 != 0xFFFF )
    {
      v7 = vgui::MDLCache();
      v7->Release(this: v7, a2: v4);
    }
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
    {
      v9 = pRelativePath;
      if ( pRelativePath == nullptr )
        v9 = &var;
      v10 = KeyValues::KeyValues(this: v8, setName: "MDLPreviewChanged", firstKey: "mdl", firstValue: v9);
      this->PostActionSignal(this, a2: v10);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020EC20
// Name: private: virtual void CMDLPicker::OnSelectedAssetPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnSelectedAssetPicked(CMDLPicker *this, const char *pMDLName)
{
  char pRelativePath[260]; // [esp+4h] [ebp-104h] BYREF

  if ( pMDLName != nullptr )
  {
    V_snprintf(pDest: pRelativePath, maxLen: 260, pFormat: "models\\%s", pMDLName);
    CMDLPicker::SelectMDL(this, pRelativePath);
  }
  else
  {
    CMDLPicker::SelectMDL(this, pRelativePath: nullptr);
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0040BAA0
// Name: public: static char const __near * CMDLPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMDLPicker::GetPanelClassName()
{
  return "CMDLPicker";
}

//------------------------------------------------------------------------------
// Address: 0x0040BAB0
// Name: private: void CMDLPicker::RefreshRenderSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::RefreshRenderSettings(CMDLPicker *this)
{
  vgui::PropertyPage *m_pRenderPage; // ecx
  vgui::Panel *ChildByName; // edi
  char v4; // al
  vgui::Panel *v5; // edi
  char v6; // al
  vgui::Panel *v7; // edi
  char v8; // al
  vgui::Panel *v9; // edi
  char v10; // al
  vgui::Panel *v11; // edi
  char v12; // al

  m_pRenderPage = this->m_pRenderPage;
  if ( m_pRenderPage != nullptr )
  {
    ChildByName = vgui::Panel::FindChildByName(this: m_pRenderPage, childName: "NoGround", recurseDown: false);
    ChildByName->AddActionSignalTarget_2(this: ChildByName, a2: this);
    v4 = ((int (__thiscall *)(vgui::Panel *))ChildByName->__vftable[1].SetAutoDelete)(a1: ChildByName);
    CMDLPanel::SetGroundGrid(this: this->m_pMDLPreview, bVisible: v4 == 0);
    v5 = vgui::Panel::FindChildByName(this: this->m_pRenderPage, childName: "Collision", recurseDown: false);
    v5->AddActionSignalTarget_2(this: v5, a2: this);
    v6 = ((int (__thiscall *)(vgui::Panel *))v5->__vftable[1].SetAutoDelete)(a1: v5);
    CMDLPanel::SetCollsionModel(this: this->m_pMDLPreview, bVisible: v6);
    v7 = vgui::Panel::FindChildByName(this: this->m_pRenderPage, childName: "Wireframe", recurseDown: false);
    v7->AddActionSignalTarget_2(this: v7, a2: this);
    v8 = ((int (__thiscall *)(vgui::Panel *))v7->__vftable[1].SetAutoDelete)(a1: v7);
    CMDLPanel::SetWireFrame(this: this->m_pMDLPreview, bVisible: v8);
    v9 = vgui::Panel::FindChildByName(this: this->m_pRenderPage, childName: "LockView", recurseDown: false);
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    v10 = ((int (__thiscall *)(vgui::Panel *))v9->__vftable[1].SetAutoDelete)(a1: v9);
    CMDLPanel::SetLockView(this: this->m_pMDLPreview, bLocked: v10);
    v11 = vgui::Panel::FindChildByName(this: this->m_pRenderPage, childName: "LookAtCamera", recurseDown: false);
    v11->AddActionSignalTarget_2(this: v11, a2: this);
    v12 = ((int (__thiscall *)(vgui::Panel *))v11->__vftable[1].SetAutoDelete)(a1: v11);
    CMDLPanel::SetLookAtCamera(this: this->m_pMDLPreview, bLookAtCamera: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BBF0
// Name: public: virtual void CMDLPicker::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::PerformLayout(CMDLPicker *this)
{
  int w; // [esp+4h] [ebp-8h] BYREF
  int h; // [esp+8h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  vgui::Panel::SetBounds(this: this->m_pFileBrowserSplitter, x: 0, y: 0, wide: w, tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x0040BC30
// Name: private: virtual void CMDLPicker::OnAssetSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnAssetSelected(CMDLPicker *this, KeyValues *pParams)
{
  const char *String; // eax
  bool v4; // al
  vgui::MessageBox *v5; // edi
  vgui::Panel *v6; // eax
  vgui::MessageBox *v7; // eax
  char pBuf[1024]; // [esp+4h] [ebp-504h] BYREF
  char pProbeBuf[260]; // [esp+404h] [ebp-104h] BYREF

  String = KeyValues::GetString(this: pParams, keyName: "asset", defaultValue: defaultValue);
  V_snprintf(pDest: pProbeBuf, maxLen: 260, pFormat: "materials/lightprobes/%s", String);
  BeginDMXContext();
  pParams = nullptr;
  v4 = UnserializeDMX(pFileName: pProbeBuf, pPathID: "GAME", bTextMode: true, ppRoot: (CDmxElement **)&pParams);
  if ( pParams != nullptr && v4 )
  {
    CPotteryWheelPanel::SetLightProbe(this: this->m_pMDLPreview, pLightProbe: (CDmxElement *)pParams);
    EndDMXContext(bDecommitMemory: true);
  }
  else
  {
    V_snprintf(pDest: pBuf, maxLen: 1024, pFormat: "Error loading lightprobe file '%s'!\n", pProbeBuf);
    v5 = (vgui::MessageBox *)operator new(nSize: 0x234u);
    if ( v5 != nullptr )
    {
      v6 = this->GetParent(this);
      v7 = vgui::MessageBox::MessageBox(this: v5, title: "Error Loading File!\n", text: pBuf, parent: v6);
    }
    else
    {
      v7 = nullptr;
    }
    v7->DoModal_2(this: v7, a2: nullptr);
    EndDMXContext(bDecommitMemory: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BD30
// Name: public: virtual void CMDLPicker::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnCommand(CMDLPicker *this, const char *pCommand)
{
  CAssetPickerFrame *v3; // eax
  CAssetPickerFrame *v4; // eax

  if ( _V_stricmp(s1: pCommand, s2: "ChooseLightProbe") != 0 )
  {
    CBaseAssetPicker::OnCommand(this, pCommand);
  }
  else
  {
    v3 = (CAssetPickerFrame *)operator new(nSize: 0x228u);
    if ( v3 != nullptr )
    {
      v4 = CAssetPickerFrame::CAssetPickerFrame(
             this: v3,
             pParent: this,
             pTitle: "Select Light Probe (.prb) File",
             pAssetType: "Light Probe",
             pExt: "prb",
             pSubDir: "materials/lightprobes",
             pTextType: "lightprobe");
      CBaseAssetPickerFrame::DoModal(this: v4, pKeyValues: nullptr);
    }
    else
    {
      CBaseAssetPickerFrame::DoModal(this: nullptr, pKeyValues: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BDB0
// Name: private: virtual void CMDLPicker::OnCheckButtonChecked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnCheckButtonChecked(CMDLPicker *this, KeyValues *kv)
{
  CBaseAssetPicker::OnCheckButtonChecked(this, kv);
  CMDLPicker::RefreshRenderSettings(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040BDD0
// Name: public: void CMDLPicker::GetSelectedMDLName(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::GetSelectedMDLName(CMDLPicker *this, char *pBuffer, int nMaxLen)
{
  const char *SelectedAsset; // eax

  if ( CBaseAssetPicker::GetSelectedAssetCount(this) <= 0 )
  {
    *pBuffer = 0;
  }
  else
  {
    SelectedAsset = CBaseAssetPicker::GetSelectedAsset(this, nSelectionIndex: -1);
    V_snprintf(pDest: pBuffer, maxLen: nMaxLen, pFormat: "models\\%s", SelectedAsset);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BE10
// Name: public: char const __near * CMDLPicker::GetSelectedSequenceName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMDLPicker::GetSelectedSequenceName(CMDLPicker *this)
{
  int v2; // eax
  KeyValues *v3; // eax

  if ( this->m_pSequencesPage == nullptr )
    return nullptr;
  v2 = this->m_pSequencesList->GetSelectedItem(this: this->m_pSequencesList, a2: 0);
  if ( v2 < 0 )
    return nullptr;
  v3 = this->m_pSequencesList->GetItem(this: this->m_pSequencesList, a2: v2);
  return KeyValues::GetString(this: v3, keyName: "sequence", defaultValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040BE60
// Name: public: char const __near * CMDLPicker::GetSelectedActivityName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMDLPicker::GetSelectedActivityName(CMDLPicker *this)
{
  int v2; // eax
  KeyValues *v3; // eax

  if ( this->m_pActivitiesPage == nullptr )
    return nullptr;
  v2 = this->m_pActivitiesList->GetSelectedItem(this: this->m_pActivitiesList, a2: 0);
  if ( v2 < 0 )
    return nullptr;
  v3 = this->m_pActivitiesList->GetItem(this: this->m_pActivitiesList, a2: v2);
  return KeyValues::GetString(this: v3, keyName: "activity", defaultValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040BEB0
// Name: public: void CMDLPicker::SelectActivity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::SelectActivity(CMDLPicker *this, const char *pActivityName)
{
  IMDLCache *v3; // eax
  studiohdr_t *v4; // esi
  int i; // edi
  int v6; // eax
  int v7; // eax
  mstudioseqdesc_t *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax

  v3 = vgui::MDLCache();
  v4 = v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  for ( i = 0; ; ++i )
  {
    v6 = v4->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v4) : v4->numlocalseq;
    if ( i >= v6 )
      break;
    if ( v4->numincludemodels != 0 )
    {
      v8 = studiohdr_t::pSeqdesc_Internal(this: v4, i);
    }
    else
    {
      v7 = i;
      if ( i < 0 || i >= v4->numlocalseq )
        v7 = 0;
      v8 = (mstudioseqdesc_t *)((char *)v4 + 212 * v7 + v4->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v8 + v8->szactivitynameindex, s2: pActivityName) == 0 )
    {
      CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: i);
      break;
    }
  }
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
  {
    v10 = KeyValues::KeyValues(
            this: v9,
            setName: "SequenceSelectionChanged",
            firstKey: "activity",
            firstValue: pActivityName);
    this->PostActionSignal(this, a2: v10);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BFA0
// Name: public: void CMDLPicker::SelectSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::SelectSequence(CMDLPicker *this, const char *pSequenceName)
{
  IMDLCache *v3; // eax
  studiohdr_t *v4; // esi
  int i; // edi
  int v6; // eax
  int v7; // eax
  mstudioseqdesc_t *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax

  v3 = vgui::MDLCache();
  v4 = v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  for ( i = 0; ; ++i )
  {
    v6 = v4->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v4) : v4->numlocalseq;
    if ( i >= v6 )
      break;
    if ( v4->numincludemodels != 0 )
    {
      v8 = studiohdr_t::pSeqdesc_Internal(this: v4, i);
    }
    else
    {
      v7 = i;
      if ( i < 0 || i >= v4->numlocalseq )
        v7 = 0;
      v8 = (mstudioseqdesc_t *)((char *)v4 + 212 * v7 + v4->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v8 + v8->szlabelindex, s2: pSequenceName) == 0 )
    {
      CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: i);
      break;
    }
  }
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
  {
    v10 = KeyValues::KeyValues(
            this: v9,
            setName: "SequenceSelectionChanged",
            firstKey: "sequence",
            firstValue: pSequenceName);
    this->PostActionSignal(this, a2: v10);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C090
// Name: public: void CMDLPicker::SelectSkin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::SelectSkin(CMDLPicker *this, int nSkin)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  CMDLPanel::SetSkin(this: this->m_pMDLPreview, nSkin);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "SkinSelectionChanged", firstKey: "skin", firstValue: nSkin);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C0F0
// Name: private: virtual void CMDLPicker::OnItemSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnItemSelected(CMDLPicker *this, KeyValues *kv)
{
  vgui::ListPanel *Ptr; // eax
  vgui::ListPanel *m_pSequencesList; // ecx
  const char *SelectedSequenceName; // eax
  vgui::ListPanel *m_pActivitiesList; // ecx
  const char *SelectedActivityName; // eax
  vgui::ListPanel *m_pSkinsList; // ecx
  int v9; // eax

  Ptr = (vgui::ListPanel *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
  m_pSequencesList = this->m_pSequencesList;
  if ( m_pSequencesList != nullptr && Ptr == m_pSequencesList )
  {
    SelectedSequenceName = CMDLPicker::GetSelectedSequenceName(this);
    if ( SelectedSequenceName != nullptr )
      CMDLPicker::SelectSequence(this, pSequenceName: SelectedSequenceName);
  }
  else
  {
    m_pActivitiesList = this->m_pActivitiesList;
    if ( m_pActivitiesList != nullptr && Ptr == m_pActivitiesList )
    {
      SelectedActivityName = CMDLPicker::GetSelectedActivityName(this);
      if ( SelectedActivityName != nullptr )
        CMDLPicker::SelectActivity(this, pActivityName: SelectedActivityName);
    }
    else
    {
      m_pSkinsList = this->m_pSkinsList;
      if ( m_pSkinsList != nullptr && Ptr == m_pSkinsList )
      {
        if ( this->m_pSkinsPage != nullptr )
        {
          v9 = m_pSkinsList->GetSelectedItem(this: m_pSkinsList, a2: 0);
          CMDLPicker::SelectSkin(this, nSkin: v9 < 0 ? 0 : v9);
        }
        else
        {
          CMDLPicker::SelectSkin(this, nSkin: 0);
        }
      }
      else
      {
        CBaseAssetPicker::OnItemSelected(this, kv);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C1C0
// Name: private: virtual void CMDLPicker::OnPageChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnPageChanged(CMDLPicker *this)
{
  const char *SelectedSequenceName; // eax
  const char *SelectedActivityName; // eax

  if ( this->m_pSequencesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pSequencesPage )
  {
    this->m_pSequencesList->RequestFocus(this: this->m_pSequencesList, a2: 0);
    SelectedSequenceName = CMDLPicker::GetSelectedSequenceName(this);
    if ( SelectedSequenceName != nullptr )
      CMDLPicker::SelectSequence(this, pSequenceName: SelectedSequenceName);
  }
  else if ( this->m_pActivitiesPage != nullptr
         && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pActivitiesPage )
  {
    this->m_pActivitiesList->RequestFocus(this: this->m_pActivitiesList, a2: 0);
    SelectedActivityName = CMDLPicker::GetSelectedActivityName(this);
    if ( SelectedActivityName != nullptr )
      CMDLPicker::SelectActivity(this, pActivityName: SelectedActivityName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C250
// Name: private: int CMDLPicker::UpdateSkinsList(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDLPicker::UpdateSkinsList(CMDLPicker *this)
{
  int v2; // esi
  IMDLCache *v3; // eax
  int v4; // eax
  int v5; // ebx
  KeyValues *v6; // eax
  const KeyValues *v7; // eax
  char skinText[28]; // [esp+8h] [ebp-1Ch] BYREF

  v2 = 0;
  if ( this->m_pSkinsList == nullptr )
    return 0;
  this->m_pSkinsList->RemoveAll(this: this->m_pSkinsList);
  v3 = vgui::MDLCache();
  v4 = (int)v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  if ( v4 == 0 )
    return 0;
  v5 = *(_DWORD *)(v4 + 224);
  if ( v5 > 0 )
  {
    do
    {
      memset(skinText, 0, 25);
      sprintf(string: skinText, format: "skin%i", v2);
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "node", firstKey: "skin", firstValue: skinText);
      else
        v7 = nullptr;
      this->m_pSkinsList->AddItem(this: this->m_pSkinsList, a2: v7, a3: 0, a4: false, a5: false);
      ++v2;
    }
    while ( v2 < v5 );
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0040C320
// Name: private: int CMDLPicker::UpdatePropDataList(class KeyValues __near *,bool __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDLPicker::UpdatePropDataList(CMDLPicker *this, KeyValues *pkvPropData, bool *bIsStatic)
{
  int v3; // edi
  KeyValues *i; // esi
  const char *Name; // eax
  const char *String; // eax
  vgui::Panel *ChildByName; // eax
  KeyValues *v9; // edi
  const char *v10; // eax
  const KeyValues *v11; // eax
  const char *v13; // [esp-8h] [ebp-14h]
  int iCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  iCount = 0;
  if ( this->m_pPropDataList == nullptr )
    return 0;
  this->m_pPropDataList->RemoveAll(this: this->m_pPropDataList);
  for ( i = KeyValues::GetFirstSubKey(this: pkvPropData); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      Name = KeyValues::GetName(this: i);
      if ( _V_strcmp(s1: Name, s2: "allowstatic") == 0 )
      {
        String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
        if ( _V_strcmp(s1: String, s2: "1") == 0 )
        {
          if ( !*bIsStatic )
          {
            ChildByName = vgui::Panel::FindChildByName(
                            this: this->m_pInfoPage,
                            childName: "StaticText",
                            recurseDown: false);
            ChildByName->SetVisible(this: ChildByName, a2: true);
          }
          *bIsStatic = *bIsStatic;
        }
      }
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
      {
        v13 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
        v10 = KeyValues::GetName(this: i);
        v11 = KeyValues::KeyValues(
                this: v9,
                setName: "node",
                firstKey: "key",
                firstValue: v10,
                secondKey: "value",
                secondValue: v13);
      }
      else
      {
        v11 = nullptr;
      }
      this->m_pPropDataList->AddItem(this: this->m_pPropDataList, a2: v11, a3: 0, a4: false, a5: false);
      v3 = ++iCount;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0040C4A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CMDLPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMDLPicker::GetMessageMap(CMDLPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMDLPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPicker::GetMessageMap'::`2'::s_pMap;
  `CMDLPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
  `CMDLPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040C4D0
// Name: public: virtual struct PanelAnimationMap __near * CMDLPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMDLPicker::GetAnimMap(CMDLPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CMDLPicker");
}

//------------------------------------------------------------------------------
// Address: 0x0040C4E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMDLPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMDLPicker::GetKBMap(CMDLPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMDLPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPicker::GetKBMap'::`2'::s_pMap;
  `CMDLPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPicker");
  `CMDLPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040C540
// Name: private: void CMDLPicker::UpdateInfoTab(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMDLPicker::UpdateInfoTab(CMDLPicker *this@<ecx>, int a2@<ebx>)
{
  IMDLCache *v3; // eax
  int v4; // eax
  _DWORD *v5; // esi
  vgui::PropertyPage *m_pInfoPage; // ecx
  vgui::Panel *ChildByName; // ebx
  vgui::PropertyPage *v8; // ecx
  vgui::Panel *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  const char *v12; // eax
  KeyValues *Key; // eax
  vgui::Panel *v14; // esi
  vgui::Panel *v15; // esi
  vgui::Panel *v16; // esi
  char massBuff[12]; // [esp+8h] [ebp-14h] BYREF
  int bIsStatic; // [esp+14h] [ebp-8h] BYREF
  int bIsPhysics; // [esp+18h] [ebp-4h]

  v3 = vgui::MDLCache();
  v4 = (int)v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  v5 = (_DWORD *)v4;
  if ( v4 != 0 )
  {
    m_pInfoPage = this->m_pInfoPage;
    bIsStatic = (int)*(float *)(v4 + 328);
    ChildByName = vgui::Panel::FindChildByName(this: m_pInfoPage, childName: "MassValue", recurseDown: false);
    V_snprintf(pDest: massBuff, maxLen: 10, pFormat: "%d", bIsStatic);
    ((void (__thiscall *)(vgui::Panel *, char *, int))ChildByName->__vftable[1].Think)(
      a1: ChildByName,
      a2: massBuff,
      a3: a2);
    v8 = this->m_pInfoPage;
    LOBYTE(bIsStatic) = (v5[38] & 0x10) != 0;
    LOBYTE(bIsPhysics) = 0;
    v9 = vgui::Panel::FindChildByName(this: v8, childName: "StaticText", recurseDown: false);
    v9->SetVisible(this: v9, a2: false);
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "modelkeys");
    else
      v11 = nullptr;
    if ( v5[79] != 0 )
      v12 = (char *)v5 + v5[78];
    else
      v12 = nullptr;
    KeyValues::LoadFromBuffer(
      this: v11,
      resourceName: "modelkeys",
      pBuffer: v12,
      pFileSystem: nullptr,
      pPathID: nullptr,
      pfnEvaluateSymbolProc: nullptr);
    Key = KeyValues::FindKey(this: v11, keyName: "prop_data", bCreate: false);
    if ( Key != nullptr )
    {
      if ( CMDLPicker::UpdatePropDataList(this, pkvPropData: Key, (bool *)&bIsStatic) != 0 )
        LOBYTE(bIsPhysics) = 1;
    }
    else
    {
      this->m_pPropDataList->RemoveAll(this: this->m_pPropDataList);
    }
    KeyValues::deleteThis(this: v11);
    v14 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "StaticObject", recurseDown: false);
    ((void (__thiscall *)(vgui::Panel *, int))v14->__vftable[1].GetPaintSize)(a1: v14, a2: 1);
    ((void (__thiscall *)(vgui::Panel *, int))v14->__vftable[1].LookupElementBounds)(a1: v14, a2: bIsStatic);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v14->__vftable[1].GetPaintSize)(a1: v14, a2: 0);
    v15 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "PhysicsObject", recurseDown: false);
    ((void (__thiscall *)(vgui::Panel *, int))v15->__vftable[1].GetPaintSize)(a1: v15, a2: 1);
    ((void (__thiscall *)(vgui::Panel *, int))v15->__vftable[1].LookupElementBounds)(a1: v15, a2: bIsPhysics);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v15->__vftable[1].GetPaintSize)(a1: v15, a2: 0);
    v16 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "DynamicObject", recurseDown: false);
    ((void (__thiscall *)(vgui::Panel *, int))v16->__vftable[1].GetPaintSize)(a1: v16, a2: 1);
    ((void (__thiscall *)(vgui::Panel *, bool))v16->__vftable[1].LookupElementBounds)(
      a1: v16,
      a2: (_BYTE)bIsPhysics == 0);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v16->__vftable[1].GetPaintSize)(a1: v16, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C740
// Name: public: static void CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar(int a1@<ebp>)
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
  if ( !`CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded )
  {
    `CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CMDLPicker::`vcall'{1012,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AssetSelected";
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
// Address: 0x0040C7D0
// Name: public: static void CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1004,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
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
// Address: 0x0040C860
// Name: public: static void CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
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
// Address: 0x0040C8F0
// Name: public: static void CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar(int a1@<ebp>)
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
  if ( !`CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded )
  {
    `CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CMDLPicker::`vcall'{1016,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
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
// Address: 0x0040C980
// Name: public: CMDLPicker::CMDLPicker(class vgui::Panel __near *,int)
// Source: json
//------------------------------------------------------------------------------
CMDLPicker *__thiscall CMDLPicker::CMDLPicker(CMDLPicker *this, vgui::Panel *pParent, int nFlags)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int v7; // edx
  vgui::Splitter *v8; // eax
  vgui::Splitter *v9; // eax
  vgui::Panel *Child; // edi
  vgui::Panel *v11; // ebx
  vgui::Splitter *v12; // eax
  vgui::Splitter *v13; // eax
  vgui::Panel *v14; // edi
  vgui::Panel *v15; // ebx
  CMDLPanel *v16; // eax
  CMDLPanel *v17; // eax
  vgui::PropertySheet *v18; // eax
  vgui::PropertySheet *v19; // eax
  char v20; // bl
  vgui::PropertyPage *v21; // eax
  vgui::PropertyPage *v22; // eax
  vgui::Panel *ChildByName; // eax
  vgui::PropertyPage *v24; // eax
  vgui::PropertyPage *v25; // eax
  vgui::ListPanel *v26; // eax
  vgui::ListPanel *v27; // eax
  vgui::PropertyPage *v28; // eax
  vgui::PropertyPage *v29; // eax
  vgui::ListPanel *v30; // eax
  vgui::ListPanel *v31; // eax
  vgui::PropertyPage *v32; // eax
  vgui::PropertyPage *v33; // eax
  vgui::ListPanel *v34; // eax
  vgui::ListPanel *v35; // eax
  vgui::PropertyPage *v36; // eax
  vgui::PropertyPage *v37; // eax
  vgui::Panel *v38; // edi
  vgui::Panel_vtbl *v39; // ebx
  Color *v40; // eax
  vgui::Panel_vtbl *v41; // ebx
  Color *v42; // eax
  vgui::Panel *v43; // edi
  vgui::Panel_vtbl *v44; // ebx
  Color *v45; // eax
  vgui::Panel_vtbl *v46; // ebx
  Color *v47; // eax
  vgui::Panel *v48; // edi
  vgui::Panel_vtbl *v49; // ebx
  Color *v50; // eax
  vgui::Panel_vtbl *v51; // ebx
  Color *v52; // eax
  vgui::ListPanel *v53; // eax
  vgui::ListPanel *v54; // eax
  vgui::PropertyPage *m_pRenderPage; // eax
  vgui::PropertyPage *m_pSequencesPage; // eax
  vgui::PropertyPage *m_pActivitiesPage; // eax
  vgui::PropertyPage *m_pSkinsPage; // eax
  vgui::PropertyPage *m_pInfoPage; // eax
  float flFractions[2]; // [esp+Ch] [ebp-8h] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  CBaseAssetPicker::CBaseAssetPicker(
    this,
    pParent,
    pAssetType: "MDL Files",
    pExt: "mdl",
    pSubDir: "models",
    pTextType: "mdlName",
    pAssetSearchPath: "GAME");
  this->__vftable = (CMDLPicker_vtbl *)&CMDLPicker::`vftable';
  if ( `CMDLPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPicker::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
    v4->pfnClassName = CMDLPicker::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CMDLPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMDLPicker::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CMDLPicker");
    v5->pfnClassName = CMDLPicker::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CMDLPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPicker::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPicker");
    v6->pfnClassName = CMDLPicker::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  }
  CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar(a1: (int)&savedregs);
  CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar(a1: (int)&savedregs);
  v7 = nFlags;
  this->m_hSelectedMDL = -1;
  this->m_nFlags = v7;
  this->m_pRenderPage = nullptr;
  this->m_pSequencesPage = nullptr;
  this->m_pActivitiesPage = nullptr;
  this->m_pSkinsPage = nullptr;
  this->m_pInfoPage = nullptr;
  this->m_pSequencesList = nullptr;
  this->m_pActivitiesList = nullptr;
  v8 = (vgui::Splitter *)operator new(nSize: 0x198u);
  if ( v8 != nullptr )
    v9 = vgui::Splitter::Splitter(
           this: v8,
           parent: this,
           name: "FileBrowserSplitter",
           mode: SPLITTER_MODE_VERTICAL,
           nCount: 1);
  else
    v9 = nullptr;
  flFractions[0] = 0.33000001;
  this->m_pFileBrowserSplitter = v9;
  flFractions[1] = 0.67000002;
  vgui::Splitter::RespaceSplitters(this: v9, flFractions);
  Child = vgui::Panel::GetChild(this: this->m_pFileBrowserSplitter, index: 0);
  v11 = vgui::Panel::GetChild(this: this->m_pFileBrowserSplitter, index: 1);
  Child->RequestFocus(this: Child, a2: 0);
  CBaseAssetPicker::CreateStandardControls(this, pParent: Child, bAllowMultiselect: false);
  v12 = (vgui::Splitter *)operator new(nSize: 0x198u);
  if ( v12 != nullptr )
    v13 = vgui::Splitter::Splitter(
            this: v12,
            parent: v11,
            name: "PreviewSplitter",
            mode: SPLITTER_MODE_HORIZONTAL,
            nCount: 1);
  else
    v13 = nullptr;
  this->m_pPreviewSplitter = v13;
  v14 = vgui::Panel::GetChild(this: v13, index: 0);
  v15 = vgui::Panel::GetChild(this: this->m_pPreviewSplitter, index: 1);
  v16 = (CMDLPanel *)operator new(nSize: 0xBE4u);
  if ( v16 != nullptr )
    v17 = CMDLPanel::CMDLPanel(this: v16, pParent: v14, pName: "MDLPreview");
  else
    v17 = nullptr;
  this->m_pMDLPreview = v17;
  vgui::Panel::SetSkipChildDuringPainting(this, child: v17);
  v18 = (vgui::PropertySheet *)operator new(nSize: 0x210u);
  if ( v18 != nullptr )
    v19 = vgui::PropertySheet::PropertySheet(this: v18, parent: v15, panelName: "ViewsSheet", draggableTabs: false);
  else
    v19 = nullptr;
  this->m_pViewsSheet = v19;
  v19->AddActionSignalTarget_2(this: v19, a2: this);
  v20 = nFlags;
  if ( (nFlags & 1) != 0 )
  {
    v21 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
    if ( v21 != nullptr )
      v22 = vgui::PropertyPage::PropertyPage(this: v21, parent: this->m_pViewsSheet, panelName: "RenderPage");
    else
      v22 = nullptr;
    this->m_pRenderPage = v22;
    v22->AddActionSignalTarget_2(this: v22, a2: this);
    this->m_pRenderPage->LoadControlSettingsAndUserConfig(
      this: this->m_pRenderPage,
      a2: "resource/mdlpickerrender.res",
      a3: 0);
    CMDLPicker::RefreshRenderSettings(this);
    ChildByName = vgui::Panel::FindChildByName(
                    this: this->m_pRenderPage,
                    childName: "ChooseLightProbe",
                    recurseDown: false);
    ChildByName->AddActionSignalTarget_2(this: ChildByName, a2: this);
  }
  if ( (v20 & 2) != 0 )
  {
    v24 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
    if ( v24 != nullptr )
      v25 = vgui::PropertyPage::PropertyPage(this: v24, parent: this->m_pViewsSheet, panelName: "SequencesPage");
    else
      v25 = nullptr;
    this->m_pSequencesPage = v25;
    v26 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
    if ( v26 != nullptr )
      v27 = vgui::ListPanel::ListPanel(this: v26, parent: this->m_pSequencesPage, panelName: "SequencesList");
    else
      v27 = nullptr;
    this->m_pSequencesList = v27;
    v27->AddColumnHeader(this: v27, a2: 0, a3: "sequence", a4: "sequence", a5: 52, a6: 0);
    this->m_pSequencesList->AddActionSignalTarget_2(this: this->m_pSequencesList, a2: this);
    this->m_pSequencesList->SetSelectIndividualCells(this: this->m_pSequencesList, a2: true);
    this->m_pSequencesList->SetEmptyListText_2(this: this->m_pSequencesList, a2: "No .MDL file currently selected.");
    this->m_pSequencesList->SetDragEnabled(this: this->m_pSequencesList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pSequencesList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 6,
      nPinOffsetY: 6,
      nUnpinnedCornerOffsetX: -6,
      nUnpinnedCornerOffsetY: -6);
  }
  if ( (v20 & 4) != 0 )
  {
    v28 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
    if ( v28 != nullptr )
      v29 = vgui::PropertyPage::PropertyPage(this: v28, parent: this->m_pViewsSheet, panelName: "ActivitiesPage");
    else
      v29 = nullptr;
    this->m_pActivitiesPage = v29;
    v30 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
    if ( v30 != nullptr )
      v31 = vgui::ListPanel::ListPanel(this: v30, parent: this->m_pActivitiesPage, panelName: "ActivitiesList");
    else
      v31 = nullptr;
    this->m_pActivitiesList = v31;
    v31->AddColumnHeader(this: v31, a2: 0, a3: "activity", a4: "activity", a5: 52, a6: 0);
    this->m_pActivitiesList->AddActionSignalTarget_2(this: this->m_pActivitiesList, a2: this);
    this->m_pActivitiesList->SetSelectIndividualCells(this: this->m_pActivitiesList, a2: true);
    this->m_pActivitiesList->SetEmptyListText_2(this: this->m_pActivitiesList, a2: "No .MDL file currently selected.");
    this->m_pActivitiesList->SetDragEnabled(this: this->m_pActivitiesList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pActivitiesList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 6,
      nPinOffsetY: 6,
      nUnpinnedCornerOffsetX: -6,
      nUnpinnedCornerOffsetY: -6);
  }
  if ( (v20 & 8) != 0 )
  {
    v32 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
    if ( v32 != nullptr )
      v33 = vgui::PropertyPage::PropertyPage(this: v32, parent: this->m_pViewsSheet, panelName: "SkinsPage");
    else
      v33 = nullptr;
    this->m_pSkinsPage = v33;
    v34 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
    if ( v34 != nullptr )
      v35 = vgui::ListPanel::ListPanel(this: v34, parent: this->m_pSkinsPage, panelName: "SkinsList");
    else
      v35 = nullptr;
    this->m_pSkinsList = v35;
    v35->AddColumnHeader(this: v35, a2: 0, a3: "skin", a4: "skin", a5: 52, a6: 0);
    this->m_pSkinsList->AddActionSignalTarget_2(this: this->m_pSkinsList, a2: this);
    this->m_pSkinsList->SetSelectIndividualCells(this: this->m_pSkinsList, a2: true);
    this->m_pSkinsList->SetEmptyListText_2(this: this->m_pSkinsList, a2: "No .MDL file currently selected.");
    this->m_pSkinsList->SetDragEnabled(this: this->m_pSkinsList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pSkinsList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 6,
      nPinOffsetY: 6,
      nUnpinnedCornerOffsetX: -6,
      nUnpinnedCornerOffsetY: -6);
  }
  if ( (v20 & 0x10) != 0 )
  {
    v36 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
    if ( v36 != nullptr )
      v37 = vgui::PropertyPage::PropertyPage(this: v36, parent: this->m_pViewsSheet, panelName: "InfoPage");
    else
      v37 = nullptr;
    this->m_pInfoPage = v37;
    v37->AddActionSignalTarget_2(this: v37, a2: this);
    this->m_pInfoPage->LoadControlSettingsAndUserConfig(
      this: this->m_pInfoPage,
      a2: "resource/mdlpickerinfo.res",
      a3: 0);
    v38 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "PhysicsObject", recurseDown: false);
    v39 = v38->__vftable;
    v40 = v38->GetFgColor(this: v38, result: (Color *)&nFlags);
    v39[1].OnChildAdded(this: v38, a2: (unsigned int)*v40);
    v41 = v38->__vftable;
    v42 = v38->GetFgColor(this: v38, result: (Color *)&nFlags);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v41[1].OnSizeChanged)(a1: v38, a2: *v42);
    v43 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "StaticObject", recurseDown: false);
    v44 = v43->__vftable;
    v45 = v43->GetFgColor(this: v43, result: (Color *)&nFlags);
    v44[1].OnChildAdded(this: v43, a2: (unsigned int)*v45);
    v46 = v43->__vftable;
    v47 = v43->GetFgColor(this: v43, result: (Color *)&nFlags);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v46[1].OnSizeChanged)(a1: v43, a2: *v47);
    v48 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "DynamicObject", recurseDown: false);
    v49 = v48->__vftable;
    v50 = v48->GetFgColor(this: v48, result: (Color *)&nFlags);
    v49[1].OnChildAdded(this: v48, a2: (unsigned int)*v50);
    v51 = v48->__vftable;
    v52 = v48->GetFgColor(this: v48, result: (Color *)&nFlags);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v51[1].OnSizeChanged)(a1: v48, a2: *v52);
    v53 = (vgui::ListPanel *)operator new(nSize: 0x24Cu);
    if ( v53 != nullptr )
      v54 = vgui::ListPanel::ListPanel(this: v53, parent: this->m_pInfoPage, panelName: "PropData");
    else
      v54 = nullptr;
    this->m_pPropDataList = v54;
    v54->AddColumnHeader(this: v54, a2: 0, a3: "key", a4: "key", a5: 250, a6: 1);
    this->m_pPropDataList->AddColumnHeader(this: this->m_pPropDataList, a2: 1, a3: "value", a4: "value", a5: 52, a6: 0);
    this->m_pPropDataList->AddActionSignalTarget_2(this: this->m_pPropDataList, a2: this);
    this->m_pPropDataList->SetSelectIndividualCells(this: this->m_pPropDataList, a2: false);
    this->m_pPropDataList->SetEmptyListText_2(this: this->m_pPropDataList, a2: "No prop_data available.");
    this->m_pPropDataList->SetDragEnabled(this: this->m_pPropDataList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pPropDataList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 6,
      nPinOffsetY: 72,
      nUnpinnedCornerOffsetX: -6,
      nUnpinnedCornerOffsetY: -6);
    CMDLPicker::RefreshRenderSettings(this);
  }
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/mdlpicker.res", dialogID: 0);
  m_pRenderPage = this->m_pRenderPage;
  if ( m_pRenderPage != nullptr )
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: m_pRenderPage,
      a3: "Render",
      a4: nullptr,
      a5: false,
      a6: -1);
  m_pSequencesPage = this->m_pSequencesPage;
  if ( m_pSequencesPage != nullptr )
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: m_pSequencesPage,
      a3: "Sequences",
      a4: nullptr,
      a5: false,
      a6: -1);
  m_pActivitiesPage = this->m_pActivitiesPage;
  if ( m_pActivitiesPage != nullptr )
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: m_pActivitiesPage,
      a3: "Activities",
      a4: nullptr,
      a5: false,
      a6: -1);
  m_pSkinsPage = this->m_pSkinsPage;
  if ( m_pSkinsPage != nullptr )
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: m_pSkinsPage,
      a3: "Skins",
      a4: nullptr,
      a5: false,
      a6: -1);
  m_pInfoPage = this->m_pInfoPage;
  if ( m_pInfoPage != nullptr )
    this->m_pViewsSheet->AddPage(this: this->m_pViewsSheet, a2: m_pInfoPage, a3: "Info", a4: nullptr, a5: false, a6: -1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040D1F0
// Name: private: void CMDLPicker::RefreshActivitiesAndSequencesList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMDLPicker::RefreshActivitiesAndSequencesList(CMDLPicker *this@<ecx>, int m_hSelectedMDL@<esi>)
{
  int v3; // edi
  void (__thiscall *SetEmptyListText_2)(vgui::ListPanel *, const char *); // eax
  IMDLCache *v5; // eax
  studiohdr_t *v6; // eax
  studiohdr_t *v7; // esi
  int NumSeq_Internal; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v9; // ecx
  bool v10; // zf
  int v11; // eax
  int v12; // eax
  mstudioseqdesc_t *v13; // eax
  int v14; // eax
  mstudioseqdesc_t *v15; // eax
  const char *v16; // edi
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // esi
  IMDLCache *v21; // eax
  const char *v22; // eax
  int v23; // eax
  mstudioseqdesc_t *v24; // eax
  const char *v25; // esi
  KeyValues *v26; // eax
  KeyValues *v27; // eax
  int v28; // edi
  KeyValues *v29; // eax
  KeyValues *v30; // esi
  IMDLCache *v31; // eax
  const char *v32; // eax
  CUtlDict<int,unsigned short> activityNames; // [esp+8h] [ebp-30h] BYREF
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+24h] [ebp-14h] BYREF
  int nItemID; // [esp+2Ch] [ebp-Ch]
  studiohdr_t *hdr; // [esp+30h] [ebp-8h]
  int j; // [esp+34h] [ebp-4h] BYREF

  this->m_pActivitiesList->RemoveAll(this: this->m_pActivitiesList);
  this->m_pSequencesList->RemoveAll(this: this->m_pSequencesList);
  v3 = 0;
  CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: 0);
  SetEmptyListText_2 = this->m_pActivitiesList->SetEmptyListText_2;
  if ( this->m_hSelectedMDL == 0xFFFF )
  {
    ((void (__stdcall *)(const char *))SetEmptyListText_2)(a1: "No .MDL file currently selected");
    this->m_pSequencesList->SetEmptyListText_2(this: this->m_pSequencesList, a2: "No .MDL file currently selected");
  }
  else
  {
    ((void (__stdcall *)(const char *))SetEmptyListText_2)(a1: ".MDL file contains no activities");
    this->m_pSequencesList->SetEmptyListText_2(this: this->m_pSequencesList, a2: ".MDL file contains no sequences");
    v5 = vgui::MDLCache();
    v6 = v5->GetStudioHdr(this: v5, a2: this->m_hSelectedMDL);
    v7 = v6;
    hdr = v6;
    if ( v6->numincludemodels != 0 )
      NumSeq_Internal = studiohdr_t::GetNumSeq_Internal(this: v6);
    else
      NumSeq_Internal = v6->numlocalseq;
    v9 = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_nAllocationCount = NumSeq_Internal;
    activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
    if ( NumSeq_Internal != 0 )
    {
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: 16 * NumSeq_Internal);
      activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = v9;
    }
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_FirstFree = -1;
    activityNames.m_Elements.m_Tree.m_pElements = v9;
    activityNames.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    while ( 1 )
    {
      v10 = v7->numincludemodels == 0;
      j = v3;
      v11 = v10 ? v7->numlocalseq : studiohdr_t::GetNumSeq_Internal(this: v7);
      if ( v3 >= v11 )
        break;
      if ( v7->numincludemodels != 0 )
      {
        v13 = studiohdr_t::pSeqdesc_Internal(this: v7, i: v3);
      }
      else
      {
        v12 = v3;
        if ( v3 < 0 || v3 >= v7->numlocalseq )
          v12 = 0;
        v13 = (mstudioseqdesc_t *)((char *)v7 + 212 * v12 + v7->localseqindex);
      }
      if ( (v13->flags & 0x400) == 0 )
      {
        if ( v7->numincludemodels != 0 )
        {
          v15 = studiohdr_t::pSeqdesc_Internal(this: v7, i: v3);
        }
        else
        {
          v14 = v3;
          if ( v3 < 0 || v3 >= v7->numlocalseq )
            v14 = 0;
          v15 = (mstudioseqdesc_t *)((char *)v7 + 212 * v14 + v7->localseqindex);
        }
        v16 = (char *)v15 + v15->szactivitynameindex;
        if ( v16 != nullptr && *v16 != 0 )
        {
          search.key = (char *)v15 + v15->szactivitynameindex;
          if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                 this: &activityNames.m_Elements.m_Tree,
                 &search) == 0xFFFF )
          {
            v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v17 != nullptr )
              v18 = KeyValues::KeyValues(this: v17, setName: "node", firstKey: "activity", firstValue: v16);
            else
              v18 = nullptr;
            nItemID = ((int (__thiscall *)(vgui::ListPanel *, KeyValues *, _DWORD, _DWORD, _DWORD, int))this->m_pActivitiesList->AddItem)(
                        a1: this->m_pActivitiesList,
                        a2: v18,
                        a3: 0,
                        a4: 0,
                        a5: 0,
                        a6: m_hSelectedMDL);
            v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v19 != nullptr )
              v20 = KeyValues::KeyValues(this: v19, setName: "drag", firstKey: "text", firstValue: v16);
            else
              v20 = nullptr;
            KeyValues::SetString(this: v20, keyName: "texttype", value: "activityName");
            v21 = vgui::MDLCache();
            m_hSelectedMDL = this->m_hSelectedMDL;
            v22 = (const char *)((int (__thiscall *)(IMDLCache *))v21->GetModelName)(a1: v21);
            KeyValues::SetString(this: v20, keyName: "mdl", value: v22);
            vgui::ListPanel::SetItemDragData(this: this->m_pActivitiesList, itemID: nItemID, data: v20);
            CUtlDict<int,unsigned short>::Insert(this: &activityNames, pName: v16, element: &j);
            v7 = hdr;
          }
        }
        if ( v7->numincludemodels != 0 )
        {
          v24 = studiohdr_t::pSeqdesc_Internal(this: v7, i: j);
        }
        else
        {
          v23 = j;
          if ( j < 0 || j >= v7->numlocalseq )
            v23 = 0;
          v24 = (mstudioseqdesc_t *)((char *)v7 + 212 * v23 + v7->localseqindex);
        }
        v25 = (char *)v24 + v24->szlabelindex;
        if ( v25 != nullptr && *v25 != 0 )
        {
          v26 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v26 != nullptr )
            v27 = KeyValues::KeyValues(this: v26, setName: "node", firstKey: "sequence", firstValue: v25);
          else
            v27 = nullptr;
          v28 = ((int (__thiscall *)(vgui::ListPanel *, KeyValues *, _DWORD, _DWORD, _DWORD, int))this->m_pSequencesList->AddItem)(
                  a1: this->m_pSequencesList,
                  a2: v27,
                  a3: 0,
                  a4: 0,
                  a5: 0,
                  a6: m_hSelectedMDL);
          v29 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v29 != nullptr )
            v30 = KeyValues::KeyValues(this: v29, setName: "drag", firstKey: "text", firstValue: v25);
          else
            v30 = nullptr;
          KeyValues::SetString(this: v30, keyName: "texttype", value: "sequenceName");
          v31 = vgui::MDLCache();
          m_hSelectedMDL = this->m_hSelectedMDL;
          v32 = (const char *)((int (__thiscall *)(IMDLCache *))v31->GetModelName)(a1: v31);
          KeyValues::SetString(this: v30, keyName: "mdl", value: v32);
          vgui::ListPanel::SetItemDragData(this: this->m_pSequencesList, itemID: v28, data: v30);
        }
        v3 = j;
        v7 = hdr;
      }
      ++v3;
    }
    CUtlDict<int,unsigned short>::RemoveAll(this: &activityNames);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &activityNames.m_Elements.m_Tree);
    if ( activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && activityNames.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: activityNames.m_Elements.m_Tree.m_Elements.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D5C0
// Name: public: void CMDLPicker::SelectMDL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::SelectMDL(CMDLPicker *this, const char *pRelativePath)
{
  IMDLCache *v3; // eax
  int v4; // edi
  IMDLCache *v5; // eax
  IMDLCache *v6; // eax
  IMDLCache *v7; // eax
  KeyValues *v8; // eax
  const char *v9; // edx
  KeyValues *v10; // eax

  if ( pRelativePath != nullptr )
  {
    v3 = vgui::MDLCache();
    v4 = v3->FindMDL(this: v3, a2: pRelativePath);
  }
  else
  {
    v4 = 0xFFFF;
  }
  if ( (_WORD)v4 == this->m_hSelectedMDL )
  {
    if ( (_WORD)v4 != 0xFFFF )
    {
      v5 = vgui::MDLCache();
      v5->Release(this: v5, a2: v4);
    }
  }
  else
  {
    this->m_hSelectedMDL = v4;
    v6 = vgui::MDLCache();
    if ( v6->IsErrorModel(this: v6, a2: this->m_hSelectedMDL) )
      this->m_hSelectedMDL = -1;
    this->m_pMDLPreview->SetMDL_2(this: this->m_pMDLPreview, a2: this->m_hSelectedMDL, a3: nullptr);
    CMDLPanel::LookAtMDL(this: this->m_pMDLPreview);
    if ( (this->m_nFlags & 8) != 0 )
      CMDLPicker::UpdateSkinsList(this);
    if ( (this->m_nFlags & 0x10) != 0 )
      CMDLPicker::UpdateInfoTab(this, a2: (int)pRelativePath);
    if ( (this->m_nFlags & 6) != 0 )
      CMDLPicker::RefreshActivitiesAndSequencesList(this, m_hSelectedMDL: (int)this);
    if ( (_WORD)v4 != 0xFFFF )
    {
      v7 = vgui::MDLCache();
      v7->Release(this: v7, a2: v4);
    }
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
    {
      v9 = pRelativePath;
      if ( pRelativePath == nullptr )
        v9 = defaultValue;
      v10 = KeyValues::KeyValues(this: v8, setName: "MDLPreviewChanged", firstKey: "mdl", firstValue: v9);
      this->PostActionSignal(this, a2: v10);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D710
// Name: private: virtual void CMDLPicker::OnSelectedAssetPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnSelectedAssetPicked(CMDLPicker *this, const char *pMDLName)
{
  char pRelativePath[260]; // [esp+4h] [ebp-104h] BYREF

  if ( pMDLName != nullptr )
  {
    V_snprintf(pDest: pRelativePath, maxLen: 260, pFormat: "models\\%s", pMDLName);
    CMDLPicker::SelectMDL(this, pRelativePath);
  }
  else
  {
    CMDLPicker::SelectMDL(this, pRelativePath: nullptr);
  }
}

} // namespace modelbrowser

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004CF350
// Name: public: static char const __near * CMDLPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMDLPicker::GetPanelClassName()
{
  return "CMDLPicker";
}

//------------------------------------------------------------------------------
// Address: 0x004CF360
// Name: public: static char const __near * CMDLPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMDLPickerFrame::GetPanelClassName()
{
  return "CMDLPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004CF370
// Name: private: void CMDLPicker::RefreshRenderSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::RefreshRenderSettings(CMDLPicker *this)
{
  vgui::PropertyPage *m_pRenderPage; // ecx
  vgui::Panel *ChildByName; // edi
  char v4; // al
  vgui::Panel *v5; // edi
  char v6; // al
  vgui::Panel *v7; // edi
  char v8; // al
  vgui::Panel *v9; // edi
  char v10; // al
  vgui::Panel *v11; // edi
  char v12; // al

  m_pRenderPage = this->m_pRenderPage;
  if ( m_pRenderPage != nullptr )
  {
    ChildByName = vgui::Panel::FindChildByName(this: m_pRenderPage, childName: "NoGround", recurseDown: false);
    ChildByName->AddActionSignalTarget_2(this: ChildByName, a2: this);
    v4 = ((int (__thiscall *)(vgui::Panel *))ChildByName->__vftable[1].SetAutoDelete)(a1: ChildByName);
    CMDLPanel::SetGroundGrid(this: this->m_pMDLPreview, bVisible: v4 == 0);
    v5 = vgui::Panel::FindChildByName(this: this->m_pRenderPage, childName: "Collision", recurseDown: false);
    v5->AddActionSignalTarget_2(this: v5, a2: this);
    v6 = ((int (__thiscall *)(vgui::Panel *))v5->__vftable[1].SetAutoDelete)(a1: v5);
    CMDLPanel::SetCollsionModel(this: this->m_pMDLPreview, bVisible: v6);
    v7 = vgui::Panel::FindChildByName(this: this->m_pRenderPage, childName: "Wireframe", recurseDown: false);
    v7->AddActionSignalTarget_2(this: v7, a2: this);
    v8 = ((int (__thiscall *)(vgui::Panel *))v7->__vftable[1].SetAutoDelete)(a1: v7);
    CMDLPanel::SetWireFrame(this: this->m_pMDLPreview, bVisible: v8);
    v9 = vgui::Panel::FindChildByName(this: this->m_pRenderPage, childName: "LockView", recurseDown: false);
    v9->AddActionSignalTarget_2(this: v9, a2: this);
    v10 = ((int (__thiscall *)(vgui::Panel *))v9->__vftable[1].SetAutoDelete)(a1: v9);
    CMDLPanel::SetLockView(this: this->m_pMDLPreview, bLocked: v10);
    v11 = vgui::Panel::FindChildByName(this: this->m_pRenderPage, childName: "LookAtCamera", recurseDown: false);
    v11->AddActionSignalTarget_2(this: v11, a2: this);
    v12 = ((int (__thiscall *)(vgui::Panel *))v11->__vftable[1].SetAutoDelete)(a1: v11);
    CMDLPanel::SetLookAtCamera(this: this->m_pMDLPreview, bLookAtCamera: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CF4B0
// Name: public: virtual void CMDLPicker::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::PerformLayout(CMDLPicker *this)
{
  int w; // [esp+4h] [ebp-8h] BYREF
  int h; // [esp+8h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  vgui::Panel::SetBounds(this: this->m_pFileBrowserSplitter, x: 0, y: 0, wide: w, tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x004CF4F0
// Name: private: virtual void CMDLPicker::OnAssetSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnAssetSelected(CMDLPicker *this, KeyValues *pParams)
{
  const char *String; // eax
  bool v4; // al
  vgui::MessageBox *v5; // edi
  vgui::Panel *v6; // eax
  vgui::MessageBox *v7; // eax
  char pBuf[1024]; // [esp+4h] [ebp-504h] BYREF
  char pProbeBuf[260]; // [esp+404h] [ebp-104h] BYREF

  String = KeyValues::GetString(this: pParams, keyName: "asset", defaultValue: defaultValue);
  V_snprintf(pDest: pProbeBuf, maxLen: 260, pFormat: "materials/lightprobes/%s", String);
  BeginDMXContext();
  pParams = nullptr;
  v4 = UnserializeDMX(pFileName: pProbeBuf, pPathID: "GAME", bTextMode: true, ppRoot: (CDmxElement **)&pParams);
  if ( pParams != nullptr && v4 )
  {
    CPotteryWheelPanel::SetLightProbe(this: this->m_pMDLPreview, pLightProbe: (CDmxElement *)pParams);
    EndDMXContext(bDecommitMemory: true);
  }
  else
  {
    V_snprintf(pDest: pBuf, maxLen: 1024, pFormat: "Error loading lightprobe file '%s'!\n", pProbeBuf);
    v5 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v5 != nullptr )
    {
      v6 = this->GetParent(this);
      v7 = vgui::MessageBox::MessageBox(this: v5, title: "Error Loading File!\n", text: pBuf, parent: v6);
    }
    else
    {
      v7 = nullptr;
    }
    v7->DoModal_2(this: v7, a2: nullptr);
    EndDMXContext(bDecommitMemory: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CF5F0
// Name: public: virtual void CMDLPicker::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnCommand(CMDLPicker *this, const char *pCommand)
{
  CAssetPickerFrame *v3; // eax
  CAssetPickerFrame *v4; // eax

  if ( _V_stricmp(s1: pCommand, s2: "ChooseLightProbe") != 0 )
  {
    CBaseAssetPicker::OnCommand(this, pCommand);
  }
  else
  {
    v3 = (CAssetPickerFrame *)MemAlloc_Alloc(nSize: 0x228u);
    if ( v3 != nullptr )
    {
      v4 = CAssetPickerFrame::CAssetPickerFrame(
             this: v3,
             pParent: this,
             pTitle: "Select Light Probe (.prb) File",
             pAssetType: "Light Probe",
             pExt: "prb",
             pSubDir: "materials/lightprobes",
             pTextType: "lightprobe");
      CBaseAssetPickerFrame::DoModal(this: v4, pKeyValues: nullptr);
    }
    else
    {
      CBaseAssetPickerFrame::DoModal(this: nullptr, pKeyValues: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CF670
// Name: private: virtual void CMDLPicker::OnCheckButtonChecked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMDLPicker::OnCheckButtonChecked(CMDLPicker *this@<ecx>, int a2@<ebx>, int a3@<edi>, KeyValues *kv)
{
  CBaseAssetPicker::OnCheckButtonChecked(this, a2, a3, kv);
  CMDLPicker::RefreshRenderSettings(this);
}

//------------------------------------------------------------------------------
// Address: 0x004CF690
// Name: public: char const __near * CMDLPicker::GetSelectedSequenceName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMDLPicker::GetSelectedSequenceName(CMDLPicker *this)
{
  int v2; // eax
  KeyValues *v3; // eax

  if ( this->m_pSequencesPage == nullptr )
    return nullptr;
  v2 = this->m_pSequencesList->GetSelectedItem(this: this->m_pSequencesList, a2: 0);
  if ( v2 < 0 )
    return nullptr;
  v3 = this->m_pSequencesList->GetItem(this: this->m_pSequencesList, a2: v2);
  return KeyValues::GetString(this: v3, keyName: "sequence", defaultValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004CF6E0
// Name: public: char const __near * CMDLPicker::GetSelectedActivityName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CMDLPicker::GetSelectedActivityName(CMDLPicker *this)
{
  int v2; // eax
  KeyValues *v3; // eax

  if ( this->m_pActivitiesPage == nullptr )
    return nullptr;
  v2 = this->m_pActivitiesList->GetSelectedItem(this: this->m_pActivitiesList, a2: 0);
  if ( v2 < 0 )
    return nullptr;
  v3 = this->m_pActivitiesList->GetItem(this: this->m_pActivitiesList, a2: v2);
  return KeyValues::GetString(this: v3, keyName: "activity", defaultValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004CF730
// Name: public: void CMDLPicker::SelectActivity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::SelectActivity(CMDLPicker *this, const char *pActivityName)
{
  IMDLCache *v3; // eax
  studiohdr_t *v4; // esi
  int i; // edi
  int v6; // eax
  int v7; // eax
  mstudioseqdesc_t *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax

  v3 = vgui::MDLCache();
  v4 = v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  for ( i = 0; ; ++i )
  {
    v6 = v4->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v4) : v4->numlocalseq;
    if ( i >= v6 )
      break;
    if ( v4->numincludemodels != 0 )
    {
      v8 = studiohdr_t::pSeqdesc_Internal(this: v4, i);
    }
    else
    {
      v7 = i;
      if ( i < 0 || i >= v4->numlocalseq )
        v7 = 0;
      v8 = (mstudioseqdesc_t *)((char *)v4 + 212 * v7 + v4->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v8 + v8->szactivitynameindex, s2: pActivityName) == 0 )
    {
      CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: i);
      break;
    }
  }
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
  {
    v10 = KeyValues::KeyValues(
            this: v9,
            setName: "SequenceSelectionChanged",
            firstKey: "activity",
            firstValue: pActivityName);
    this->PostActionSignal(this, a2: v10);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CF820
// Name: public: void CMDLPicker::SelectSequence(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::SelectSequence(CMDLPicker *this, const char *pSequenceName)
{
  IMDLCache *v3; // eax
  studiohdr_t *v4; // esi
  int i; // edi
  int v6; // eax
  int v7; // eax
  mstudioseqdesc_t *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax

  v3 = vgui::MDLCache();
  v4 = v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  for ( i = 0; ; ++i )
  {
    v6 = v4->numincludemodels != 0 ? studiohdr_t::GetNumSeq_Internal(this: v4) : v4->numlocalseq;
    if ( i >= v6 )
      break;
    if ( v4->numincludemodels != 0 )
    {
      v8 = studiohdr_t::pSeqdesc_Internal(this: v4, i);
    }
    else
    {
      v7 = i;
      if ( i < 0 || i >= v4->numlocalseq )
        v7 = 0;
      v8 = (mstudioseqdesc_t *)((char *)v4 + 212 * v7 + v4->localseqindex);
    }
    if ( _V_stricmp(s1: (const char *)v8 + v8->szlabelindex, s2: pSequenceName) == 0 )
    {
      CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: i);
      break;
    }
  }
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
  {
    v10 = KeyValues::KeyValues(
            this: v9,
            setName: "SequenceSelectionChanged",
            firstKey: "sequence",
            firstValue: pSequenceName);
    this->PostActionSignal(this, a2: v10);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CF910
// Name: public: void CMDLPicker::SelectSkin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::SelectSkin(CMDLPicker *this, int nSkin)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  CMDLPanel::SetSkin(this: this->m_pMDLPreview, nSkin);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "SkinSelectionChanged", firstKey: "skin", firstValue: nSkin);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CF970
// Name: private: virtual void CMDLPicker::OnItemSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnItemSelected(CMDLPicker *this, KeyValues *kv)
{
  vgui::ListPanel *Ptr; // eax
  vgui::ListPanel *m_pSequencesList; // ecx
  const char *SelectedSequenceName; // eax
  vgui::ListPanel *m_pActivitiesList; // ecx
  const char *SelectedActivityName; // eax
  vgui::ListPanel *m_pSkinsList; // ecx
  int v9; // eax

  Ptr = (vgui::ListPanel *)KeyValues::GetPtr(this: kv, keyName: "panel", defaultValue: nullptr);
  m_pSequencesList = this->m_pSequencesList;
  if ( m_pSequencesList != nullptr && Ptr == m_pSequencesList )
  {
    SelectedSequenceName = CMDLPicker::GetSelectedSequenceName(this);
    if ( SelectedSequenceName != nullptr )
      CMDLPicker::SelectSequence(this, pSequenceName: SelectedSequenceName);
  }
  else
  {
    m_pActivitiesList = this->m_pActivitiesList;
    if ( m_pActivitiesList != nullptr && Ptr == m_pActivitiesList )
    {
      SelectedActivityName = CMDLPicker::GetSelectedActivityName(this);
      if ( SelectedActivityName != nullptr )
        CMDLPicker::SelectActivity(this, pActivityName: SelectedActivityName);
    }
    else
    {
      m_pSkinsList = this->m_pSkinsList;
      if ( m_pSkinsList != nullptr && Ptr == m_pSkinsList )
      {
        if ( this->m_pSkinsPage != nullptr )
        {
          v9 = m_pSkinsList->GetSelectedItem(this: m_pSkinsList, a2: 0);
          CMDLPicker::SelectSkin(this, nSkin: v9 < 0 ? 0 : v9);
        }
        else
        {
          CMDLPicker::SelectSkin(this, nSkin: 0);
        }
      }
      else
      {
        CBaseAssetPicker::OnItemSelected(this, kv);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CFA40
// Name: private: virtual void CMDLPicker::OnPageChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnPageChanged(CMDLPicker *this)
{
  const char *SelectedSequenceName; // eax
  const char *SelectedActivityName; // eax

  if ( this->m_pSequencesPage != nullptr
    && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pSequencesPage )
  {
    this->m_pSequencesList->RequestFocus(this: this->m_pSequencesList, a2: 0);
    SelectedSequenceName = CMDLPicker::GetSelectedSequenceName(this);
    if ( SelectedSequenceName != nullptr )
      CMDLPicker::SelectSequence(this, pSequenceName: SelectedSequenceName);
  }
  else if ( this->m_pActivitiesPage != nullptr
         && this->m_pViewsSheet->GetActivePage(this: this->m_pViewsSheet) == this->m_pActivitiesPage )
  {
    this->m_pActivitiesList->RequestFocus(this: this->m_pActivitiesList, a2: 0);
    SelectedActivityName = CMDLPicker::GetSelectedActivityName(this);
    if ( SelectedActivityName != nullptr )
      CMDLPicker::SelectActivity(this, pActivityName: SelectedActivityName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CFAD0
// Name: private: int CMDLPicker::UpdateSkinsList(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDLPicker::UpdateSkinsList(CMDLPicker *this)
{
  int v2; // esi
  IMDLCache *v3; // eax
  int v4; // eax
  int v5; // ebx
  KeyValues *v6; // eax
  const KeyValues *v7; // eax
  char skinText[28]; // [esp+8h] [ebp-1Ch] BYREF

  v2 = 0;
  if ( this->m_pSkinsList == nullptr )
    return 0;
  this->m_pSkinsList->RemoveAll(this: this->m_pSkinsList);
  v3 = vgui::MDLCache();
  v4 = (int)v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  if ( v4 == 0 )
    return 0;
  v5 = *(_DWORD *)(v4 + 224);
  if ( v5 > 0 )
  {
    do
    {
      memset(skinText, 0, 25);
      sprintf(string: skinText, format: "skin%i", v2);
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "node", firstKey: "skin", firstValue: skinText);
      else
        v7 = nullptr;
      this->m_pSkinsList->AddItem(this: this->m_pSkinsList, a2: v7, a3: 0, a4: false, a5: false);
      ++v2;
    }
    while ( v2 < v5 );
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004CFBA0
// Name: private: int CMDLPicker::UpdatePropDataList(class KeyValues __near *,bool __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDLPicker::UpdatePropDataList(CMDLPicker *this, KeyValues *pkvPropData, bool *bIsStatic)
{
  int v3; // edi
  KeyValues *i; // esi
  const char *Name; // eax
  const char *String; // eax
  vgui::Panel *ChildByName; // eax
  KeyValues *v9; // edi
  const char *v10; // eax
  const KeyValues *v11; // eax
  const char *v13; // [esp-8h] [ebp-14h]
  int iCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  iCount = 0;
  if ( this->m_pPropDataList == nullptr )
    return 0;
  this->m_pPropDataList->RemoveAll(this: this->m_pPropDataList);
  for ( i = KeyValues::GetFirstSubKey(this: pkvPropData); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    if ( KeyValues::GetDataType(this: i, keyName: nullptr) != TYPE_NONE )
    {
      Name = KeyValues::GetName(this: i);
      if ( _V_strcmp(s1: Name, s2: "allowstatic") == 0 )
      {
        String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
        if ( _V_strcmp(s1: String, s2: "1") == 0 )
        {
          if ( !*bIsStatic )
          {
            ChildByName = vgui::Panel::FindChildByName(
                            this: this->m_pInfoPage,
                            childName: "StaticText",
                            recurseDown: false);
            ChildByName->SetVisible(this: ChildByName, a2: true);
          }
          *bIsStatic = *bIsStatic;
        }
      }
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
      {
        v13 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
        v10 = KeyValues::GetName(this: i);
        v11 = KeyValues::KeyValues(
                this: v9,
                setName: "node",
                firstKey: "key",
                firstValue: v10,
                secondKey: "value",
                secondValue: v13);
      }
      else
      {
        v11 = nullptr;
      }
      this->m_pPropDataList->AddItem(this: this->m_pPropDataList, a2: v11, a3: 0, a4: false, a5: false);
      v3 = ++iCount;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004CFCE0
// Name: public: virtual struct vgui::PanelMessageMap __near * CMDLPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMDLPicker::GetMessageMap(CMDLPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMDLPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPicker::GetMessageMap'::`2'::s_pMap;
  `CMDLPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
  `CMDLPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CFD10
// Name: public: virtual struct PanelAnimationMap __near * CMDLPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMDLPicker::GetAnimMap(CMDLPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CMDLPicker");
}

//------------------------------------------------------------------------------
// Address: 0x004CFD20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMDLPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMDLPicker::GetKBMap(CMDLPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMDLPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPicker::GetKBMap'::`2'::s_pMap;
  `CMDLPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPicker");
  `CMDLPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CFD50
// Name: public: virtual struct vgui::PanelMessageMap __near * CMDLPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMDLPickerFrame::GetMessageMap(CMDLPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMDLPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CMDLPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMDLPickerFrame");
  `CMDLPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CFD80
// Name: public: virtual struct PanelAnimationMap __near * CMDLPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMDLPickerFrame::GetAnimMap(CMDLPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CMDLPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004CFD90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMDLPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMDLPickerFrame::GetKBMap(CMDLPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMDLPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMDLPickerFrame::GetKBMap'::`2'::s_pMap;
  `CMDLPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPickerFrame");
  `CMDLPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004CFE20
// Name: private: void CMDLPicker::UpdateInfoTab(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMDLPicker::UpdateInfoTab(CMDLPicker *this@<ecx>, int a2@<ebx>)
{
  IMDLCache *v3; // eax
  int v4; // eax
  _DWORD *v5; // esi
  vgui::PropertyPage *m_pInfoPage; // ecx
  vgui::Panel *ChildByName; // ebx
  vgui::PropertyPage *v8; // ecx
  vgui::Panel *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  const char *v12; // eax
  KeyValues *Key; // eax
  vgui::Panel *v14; // esi
  vgui::Panel *v15; // esi
  vgui::Panel *v16; // esi
  char massBuff[12]; // [esp+8h] [ebp-14h] BYREF
  int bIsStatic; // [esp+14h] [ebp-8h] BYREF
  int bIsPhysics; // [esp+18h] [ebp-4h]

  v3 = vgui::MDLCache();
  v4 = (int)v3->GetStudioHdr(this: v3, a2: this->m_hSelectedMDL);
  v5 = (_DWORD *)v4;
  if ( v4 != 0 )
  {
    m_pInfoPage = this->m_pInfoPage;
    bIsStatic = (int)*(float *)(v4 + 328);
    ChildByName = vgui::Panel::FindChildByName(this: m_pInfoPage, childName: "MassValue", recurseDown: false);
    V_snprintf(pDest: massBuff, maxLen: 10, pFormat: "%d", bIsStatic);
    ((void (__thiscall *)(vgui::Panel *, char *, int))ChildByName->__vftable[1].Think)(
      a1: ChildByName,
      a2: massBuff,
      a3: a2);
    v8 = this->m_pInfoPage;
    LOBYTE(bIsStatic) = (v5[38] & 0x10) != 0;
    LOBYTE(bIsPhysics) = 0;
    v9 = vgui::Panel::FindChildByName(this: v8, childName: "StaticText", recurseDown: false);
    v9->SetVisible(this: v9, a2: false);
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "modelkeys");
    else
      v11 = nullptr;
    if ( v5[79] != 0 )
      v12 = (char *)v5 + v5[78];
    else
      v12 = nullptr;
    KeyValues::LoadFromBuffer(
      this: v11,
      resourceName: "modelkeys",
      pBuffer: v12,
      pFileSystem: nullptr,
      pPathID: nullptr,
      pfnEvaluateSymbolProc: nullptr);
    Key = KeyValues::FindKey(this: v11, keyName: "prop_data", bCreate: false);
    if ( Key != nullptr )
    {
      if ( CMDLPicker::UpdatePropDataList(this, pkvPropData: Key, (bool *)&bIsStatic) != 0 )
        LOBYTE(bIsPhysics) = 1;
    }
    else
    {
      this->m_pPropDataList->RemoveAll(this: this->m_pPropDataList);
    }
    KeyValues::deleteThis(this: v11);
    v14 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "StaticObject", recurseDown: false);
    ((void (__thiscall *)(vgui::Panel *, int))v14->__vftable[1].GetPaintSize)(a1: v14, a2: 1);
    ((void (__thiscall *)(vgui::Panel *, int))v14->__vftable[1].LookupElementBounds)(a1: v14, a2: bIsStatic);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v14->__vftable[1].GetPaintSize)(a1: v14, a2: 0);
    v15 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "PhysicsObject", recurseDown: false);
    ((void (__thiscall *)(vgui::Panel *, int))v15->__vftable[1].GetPaintSize)(a1: v15, a2: 1);
    ((void (__thiscall *)(vgui::Panel *, int))v15->__vftable[1].LookupElementBounds)(a1: v15, a2: bIsPhysics);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v15->__vftable[1].GetPaintSize)(a1: v15, a2: 0);
    v16 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "DynamicObject", recurseDown: false);
    ((void (__thiscall *)(vgui::Panel *, int))v16->__vftable[1].GetPaintSize)(a1: v16, a2: 1);
    ((void (__thiscall *)(vgui::Panel *, bool))v16->__vftable[1].LookupElementBounds)(
      a1: v16,
      a2: (_BYTE)bIsPhysics == 0);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v16->__vftable[1].GetPaintSize)(a1: v16, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D0020
// Name: public: static void CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar(int a1@<ebp>)
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
  if ( !`CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded )
  {
    `CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSoundPicker::`vcall'{1012,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AssetSelected";
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
// Address: 0x004D00B0
// Name: public: static void CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{1004,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
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
// Address: 0x004D0140
// Name: public: static void CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAssetPicker::`vcall'{996,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
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
// Address: 0x004D01D0
// Name: public: static void CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar(int a1@<ebp>)
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
  if ( !`CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded )
  {
    `CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1016,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
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
// Address: 0x004D0260
// Name: public: CMDLPicker::CMDLPicker(class vgui::Panel __near *,int)
// Source: json
//------------------------------------------------------------------------------
CMDLPicker *__thiscall CMDLPicker::CMDLPicker(CMDLPicker *this, vgui::Panel *pParent, int nFlags)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int v7; // edx
  vgui::Splitter *v8; // eax
  vgui::Splitter *v9; // eax
  vgui::Panel *Child; // edi
  vgui::Panel *v11; // ebx
  vgui::Splitter *v12; // eax
  vgui::Splitter *v13; // eax
  vgui::Panel *v14; // edi
  vgui::Panel *v15; // ebx
  CMDLPanel *v16; // eax
  CMDLPanel *v17; // eax
  vgui::PropertySheet *v18; // eax
  vgui::PropertySheet *v19; // eax
  char v20; // bl
  vgui::PropertyPage *v21; // eax
  vgui::PropertyPage *v22; // eax
  vgui::Panel *ChildByName; // eax
  vgui::PropertyPage *v24; // eax
  vgui::PropertyPage *v25; // eax
  vgui::ListPanel *v26; // eax
  vgui::ListPanel *v27; // eax
  vgui::PropertyPage *v28; // eax
  vgui::PropertyPage *v29; // eax
  vgui::ListPanel *v30; // eax
  vgui::ListPanel *v31; // eax
  vgui::PropertyPage *v32; // eax
  vgui::PropertyPage *v33; // eax
  vgui::ListPanel *v34; // eax
  vgui::ListPanel *v35; // eax
  vgui::PropertyPage *v36; // eax
  vgui::PropertyPage *v37; // eax
  vgui::Panel *v38; // edi
  vgui::Panel_vtbl *v39; // ebx
  Color *v40; // eax
  vgui::Panel_vtbl *v41; // ebx
  Color *v42; // eax
  vgui::Panel *v43; // edi
  vgui::Panel_vtbl *v44; // ebx
  Color *v45; // eax
  vgui::Panel_vtbl *v46; // ebx
  Color *v47; // eax
  vgui::Panel *v48; // edi
  vgui::Panel_vtbl *v49; // ebx
  Color *v50; // eax
  vgui::Panel_vtbl *v51; // ebx
  Color *v52; // eax
  vgui::ListPanel *v53; // eax
  vgui::ListPanel *v54; // eax
  vgui::PropertyPage *m_pRenderPage; // eax
  vgui::PropertyPage *m_pSequencesPage; // eax
  vgui::PropertyPage *m_pActivitiesPage; // eax
  vgui::PropertyPage *m_pSkinsPage; // eax
  vgui::PropertyPage *m_pInfoPage; // eax
  float flFractions[2]; // [esp+Ch] [ebp-8h] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  CBaseAssetPicker::CBaseAssetPicker(
    this,
    pParent,
    pAssetType: "MDL Files",
    pExt: "mdl",
    pSubDir: "models",
    pTextType: "mdlName",
    pAssetSearchPath: "GAME");
  this->__vftable = (CMDLPicker_vtbl *)&CMDLPicker::`vftable';
  if ( `CMDLPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPicker::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CMDLPicker");
    v4->pfnClassName = CMDLPicker::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CMDLPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMDLPicker::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CMDLPicker");
    v5->pfnClassName = CMDLPicker::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CMDLPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPicker::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPicker");
    v6->pfnClassName = CMDLPicker::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  }
  CMDLPicker::PanelMessageFunc_OnAssetSelected::InitVar(a1: (int)&savedregs);
  CMDLPicker::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  CMDLPicker::PanelMessageFunc_OnItemSelected::InitVar(a1: (int)&savedregs);
  CMDLPicker::PanelMessageFunc_OnPageChanged::InitVar(a1: (int)&savedregs);
  v7 = nFlags;
  this->m_hSelectedMDL = -1;
  this->m_nFlags = v7;
  this->m_pRenderPage = nullptr;
  this->m_pSequencesPage = nullptr;
  this->m_pActivitiesPage = nullptr;
  this->m_pSkinsPage = nullptr;
  this->m_pInfoPage = nullptr;
  this->m_pSequencesList = nullptr;
  this->m_pActivitiesList = nullptr;
  v8 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v8 != nullptr )
    v9 = vgui::Splitter::Splitter(
           this: v8,
           parent: this,
           name: "FileBrowserSplitter",
           mode: SPLITTER_MODE_VERTICAL,
           nCount: 1);
  else
    v9 = nullptr;
  flFractions[0] = 0.33000001;
  this->m_pFileBrowserSplitter = v9;
  flFractions[1] = 0.67000002;
  vgui::Splitter::RespaceSplitters(this: v9, flFractions);
  Child = vgui::Panel::GetChild(this: this->m_pFileBrowserSplitter, index: 0);
  v11 = vgui::Panel::GetChild(this: this->m_pFileBrowserSplitter, index: 1);
  Child->RequestFocus(this: Child, a2: 0);
  CBaseAssetPicker::CreateStandardControls(this, pParent: Child, bAllowMultiselect: false);
  v12 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v12 != nullptr )
    v13 = vgui::Splitter::Splitter(
            this: v12,
            parent: v11,
            name: "PreviewSplitter",
            mode: SPLITTER_MODE_HORIZONTAL,
            nCount: 1);
  else
    v13 = nullptr;
  this->m_pPreviewSplitter = v13;
  v14 = vgui::Panel::GetChild(this: v13, index: 0);
  v15 = vgui::Panel::GetChild(this: this->m_pPreviewSplitter, index: 1);
  v16 = (CMDLPanel *)MemAlloc_Alloc(nSize: 0xBE4u);
  if ( v16 != nullptr )
    v17 = CMDLPanel::CMDLPanel(this: v16, pParent: v14, pName: "MDLPreview");
  else
    v17 = nullptr;
  this->m_pMDLPreview = v17;
  vgui::Panel::SetSkipChildDuringPainting(this, child: v17);
  v18 = (vgui::PropertySheet *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v18 != nullptr )
    v19 = vgui::PropertySheet::PropertySheet(this: v18, parent: v15, panelName: "ViewsSheet", draggableTabs: false);
  else
    v19 = nullptr;
  this->m_pViewsSheet = v19;
  v19->AddActionSignalTarget_2(this: v19, a2: this);
  v20 = nFlags;
  if ( (nFlags & 1) != 0 )
  {
    v21 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v21 != nullptr )
      v22 = vgui::PropertyPage::PropertyPage(this: v21, parent: this->m_pViewsSheet, panelName: "RenderPage");
    else
      v22 = nullptr;
    this->m_pRenderPage = v22;
    v22->AddActionSignalTarget_2(this: v22, a2: this);
    this->m_pRenderPage->LoadControlSettingsAndUserConfig(
      this: this->m_pRenderPage,
      a2: "resource/mdlpickerrender.res",
      a3: 0);
    CMDLPicker::RefreshRenderSettings(this);
    ChildByName = vgui::Panel::FindChildByName(
                    this: this->m_pRenderPage,
                    childName: "ChooseLightProbe",
                    recurseDown: false);
    ChildByName->AddActionSignalTarget_2(this: ChildByName, a2: this);
  }
  if ( (v20 & 2) != 0 )
  {
    v24 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v24 != nullptr )
      v25 = vgui::PropertyPage::PropertyPage(this: v24, parent: this->m_pViewsSheet, panelName: "SequencesPage");
    else
      v25 = nullptr;
    this->m_pSequencesPage = v25;
    v26 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
    if ( v26 != nullptr )
      v27 = vgui::ListPanel::ListPanel(this: v26, parent: this->m_pSequencesPage, panelName: "SequencesList");
    else
      v27 = nullptr;
    this->m_pSequencesList = v27;
    v27->AddColumnHeader(this: v27, a2: 0, a3: "sequence", a4: "sequence", a5: 52, a6: 0);
    this->m_pSequencesList->AddActionSignalTarget_2(this: this->m_pSequencesList, a2: this);
    this->m_pSequencesList->SetSelectIndividualCells(this: this->m_pSequencesList, a2: true);
    this->m_pSequencesList->SetEmptyListText_2(this: this->m_pSequencesList, a2: "No .MDL file currently selected.");
    this->m_pSequencesList->SetDragEnabled(this: this->m_pSequencesList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pSequencesList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 6,
      nPinOffsetY: 6,
      nUnpinnedCornerOffsetX: -6,
      nUnpinnedCornerOffsetY: -6);
  }
  if ( (v20 & 4) != 0 )
  {
    v28 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v28 != nullptr )
      v29 = vgui::PropertyPage::PropertyPage(this: v28, parent: this->m_pViewsSheet, panelName: "ActivitiesPage");
    else
      v29 = nullptr;
    this->m_pActivitiesPage = v29;
    v30 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
    if ( v30 != nullptr )
      v31 = vgui::ListPanel::ListPanel(this: v30, parent: this->m_pActivitiesPage, panelName: "ActivitiesList");
    else
      v31 = nullptr;
    this->m_pActivitiesList = v31;
    v31->AddColumnHeader(this: v31, a2: 0, a3: "activity", a4: "activity", a5: 52, a6: 0);
    this->m_pActivitiesList->AddActionSignalTarget_2(this: this->m_pActivitiesList, a2: this);
    this->m_pActivitiesList->SetSelectIndividualCells(this: this->m_pActivitiesList, a2: true);
    this->m_pActivitiesList->SetEmptyListText_2(this: this->m_pActivitiesList, a2: "No .MDL file currently selected.");
    this->m_pActivitiesList->SetDragEnabled(this: this->m_pActivitiesList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pActivitiesList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 6,
      nPinOffsetY: 6,
      nUnpinnedCornerOffsetX: -6,
      nUnpinnedCornerOffsetY: -6);
  }
  if ( (v20 & 8) != 0 )
  {
    v32 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v32 != nullptr )
      v33 = vgui::PropertyPage::PropertyPage(this: v32, parent: this->m_pViewsSheet, panelName: "SkinsPage");
    else
      v33 = nullptr;
    this->m_pSkinsPage = v33;
    v34 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
    if ( v34 != nullptr )
      v35 = vgui::ListPanel::ListPanel(this: v34, parent: this->m_pSkinsPage, panelName: "SkinsList");
    else
      v35 = nullptr;
    this->m_pSkinsList = v35;
    v35->AddColumnHeader(this: v35, a2: 0, a3: "skin", a4: "skin", a5: 52, a6: 0);
    this->m_pSkinsList->AddActionSignalTarget_2(this: this->m_pSkinsList, a2: this);
    this->m_pSkinsList->SetSelectIndividualCells(this: this->m_pSkinsList, a2: true);
    this->m_pSkinsList->SetEmptyListText_2(this: this->m_pSkinsList, a2: "No .MDL file currently selected.");
    this->m_pSkinsList->SetDragEnabled(this: this->m_pSkinsList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pSkinsList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 6,
      nPinOffsetY: 6,
      nUnpinnedCornerOffsetX: -6,
      nUnpinnedCornerOffsetY: -6);
  }
  if ( (v20 & 0x10) != 0 )
  {
    v36 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
    if ( v36 != nullptr )
      v37 = vgui::PropertyPage::PropertyPage(this: v36, parent: this->m_pViewsSheet, panelName: "InfoPage");
    else
      v37 = nullptr;
    this->m_pInfoPage = v37;
    v37->AddActionSignalTarget_2(this: v37, a2: this);
    this->m_pInfoPage->LoadControlSettingsAndUserConfig(
      this: this->m_pInfoPage,
      a2: "resource/mdlpickerinfo.res",
      a3: 0);
    v38 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "PhysicsObject", recurseDown: false);
    v39 = v38->__vftable;
    v40 = v38->GetFgColor(this: v38, result: (Color *)&nFlags);
    v39[1].OnChildAdded(this: v38, a2: (unsigned int)*v40);
    v41 = v38->__vftable;
    v42 = v38->GetFgColor(this: v38, result: (Color *)&nFlags);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v41[1].OnSizeChanged)(a1: v38, a2: *v42);
    v43 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "StaticObject", recurseDown: false);
    v44 = v43->__vftable;
    v45 = v43->GetFgColor(this: v43, result: (Color *)&nFlags);
    v44[1].OnChildAdded(this: v43, a2: (unsigned int)*v45);
    v46 = v43->__vftable;
    v47 = v43->GetFgColor(this: v43, result: (Color *)&nFlags);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v46[1].OnSizeChanged)(a1: v43, a2: *v47);
    v48 = vgui::Panel::FindChildByName(this: this->m_pInfoPage, childName: "DynamicObject", recurseDown: false);
    v49 = v48->__vftable;
    v50 = v48->GetFgColor(this: v48, result: (Color *)&nFlags);
    v49[1].OnChildAdded(this: v48, a2: (unsigned int)*v50);
    v51 = v48->__vftable;
    v52 = v48->GetFgColor(this: v48, result: (Color *)&nFlags);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v51[1].OnSizeChanged)(a1: v48, a2: *v52);
    v53 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
    if ( v53 != nullptr )
      v54 = vgui::ListPanel::ListPanel(this: v53, parent: this->m_pInfoPage, panelName: "PropData");
    else
      v54 = nullptr;
    this->m_pPropDataList = v54;
    v54->AddColumnHeader(this: v54, a2: 0, a3: "key", a4: "key", a5: 250, a6: 1);
    this->m_pPropDataList->AddColumnHeader(this: this->m_pPropDataList, a2: 1, a3: "value", a4: "value", a5: 52, a6: 0);
    this->m_pPropDataList->AddActionSignalTarget_2(this: this->m_pPropDataList, a2: this);
    this->m_pPropDataList->SetSelectIndividualCells(this: this->m_pPropDataList, a2: false);
    this->m_pPropDataList->SetEmptyListText_2(this: this->m_pPropDataList, a2: "No prop_data available.");
    this->m_pPropDataList->SetDragEnabled(this: this->m_pPropDataList, a2: true);
    vgui::Panel::SetAutoResize(
      this: this->m_pPropDataList,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 6,
      nPinOffsetY: 72,
      nUnpinnedCornerOffsetX: -6,
      nUnpinnedCornerOffsetY: -6);
    CMDLPicker::RefreshRenderSettings(this);
  }
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/mdlpicker.res", dialogID: 0);
  m_pRenderPage = this->m_pRenderPage;
  if ( m_pRenderPage != nullptr )
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: m_pRenderPage,
      a3: "Render",
      a4: nullptr,
      a5: false,
      a6: -1);
  m_pSequencesPage = this->m_pSequencesPage;
  if ( m_pSequencesPage != nullptr )
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: m_pSequencesPage,
      a3: "Sequences",
      a4: nullptr,
      a5: false,
      a6: -1);
  m_pActivitiesPage = this->m_pActivitiesPage;
  if ( m_pActivitiesPage != nullptr )
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: m_pActivitiesPage,
      a3: "Activities",
      a4: nullptr,
      a5: false,
      a6: -1);
  m_pSkinsPage = this->m_pSkinsPage;
  if ( m_pSkinsPage != nullptr )
    this->m_pViewsSheet->AddPage(
      this: this->m_pViewsSheet,
      a2: m_pSkinsPage,
      a3: "Skins",
      a4: nullptr,
      a5: false,
      a6: -1);
  m_pInfoPage = this->m_pInfoPage;
  if ( m_pInfoPage != nullptr )
    this->m_pViewsSheet->AddPage(this: this->m_pViewsSheet, a2: m_pInfoPage, a3: "Info", a4: nullptr, a5: false, a6: -1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D0AD0
// Name: public: CMDLPickerFrame::CMDLPickerFrame(class vgui::Panel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CMDLPickerFrame *__thiscall CMDLPickerFrame::CMDLPickerFrame(
        CMDLPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        int nFlags)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  CMDLPicker *v8; // eax
  CMDLPicker *v9; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CMDLPickerFrame_vtbl *)&CMDLPickerFrame::`vftable';
  if ( `CMDLPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPickerFrame::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CMDLPickerFrame");
    v5->pfnClassName = CMDLPickerFrame::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CMDLPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMDLPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CMDLPickerFrame");
    v6->pfnClassName = CMDLPickerFrame::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CMDLPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMDLPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CMDLPickerFrame");
    v7->pfnClassName = CMDLPickerFrame::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v8 = (CMDLPicker *)MemAlloc_Alloc(nSize: 0x284u);
  if ( v8 != nullptr )
    v9 = CMDLPicker::CMDLPicker(this: v8, pParent: this, nFlags);
  else
    v9 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v9);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/mdlpickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D0BD0
// Name: private: void CMDLPicker::RefreshActivitiesAndSequencesList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMDLPicker::RefreshActivitiesAndSequencesList(CMDLPicker *this@<ecx>, int m_hSelectedMDL@<esi>)
{
  int v3; // edi
  void (__thiscall *SetEmptyListText_2)(vgui::ListPanel *, const char *); // eax
  IMDLCache *v5; // eax
  studiohdr_t *v6; // eax
  studiohdr_t *v7; // esi
  int NumSeq_Internal; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *v9; // ecx
  bool v10; // zf
  int v11; // eax
  int v12; // eax
  mstudioseqdesc_t *v13; // eax
  int v14; // eax
  mstudioseqdesc_t *v15; // eax
  const char *v16; // edi
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // esi
  IMDLCache *v21; // eax
  const char *v22; // eax
  int v23; // eax
  mstudioseqdesc_t *v24; // eax
  const char *v25; // esi
  KeyValues *v26; // eax
  KeyValues *v27; // eax
  int v28; // edi
  KeyValues *v29; // eax
  KeyValues *v30; // esi
  IMDLCache *v31; // eax
  const char *v32; // eax
  CUtlDict<int,unsigned short> activityNames; // [esp+8h] [ebp-30h] BYREF
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+24h] [ebp-14h] BYREF
  int nItemID; // [esp+2Ch] [ebp-Ch]
  studiohdr_t *hdr; // [esp+30h] [ebp-8h]
  int j; // [esp+34h] [ebp-4h] BYREF

  this->m_pActivitiesList->RemoveAll(this: this->m_pActivitiesList);
  this->m_pSequencesList->RemoveAll(this: this->m_pSequencesList);
  v3 = 0;
  CMDLPanel::SetSequence(this: this->m_pMDLPreview, nSequence: 0);
  SetEmptyListText_2 = this->m_pActivitiesList->SetEmptyListText_2;
  if ( this->m_hSelectedMDL == 0xFFFF )
  {
    ((void (__stdcall *)(const char *))SetEmptyListText_2)(a1: "No .MDL file currently selected");
    this->m_pSequencesList->SetEmptyListText_2(this: this->m_pSequencesList, a2: "No .MDL file currently selected");
  }
  else
  {
    ((void (__stdcall *)(const char *))SetEmptyListText_2)(a1: ".MDL file contains no activities");
    this->m_pSequencesList->SetEmptyListText_2(this: this->m_pSequencesList, a2: ".MDL file contains no sequences");
    v5 = vgui::MDLCache();
    v6 = v5->GetStudioHdr(this: v5, a2: this->m_hSelectedMDL);
    v7 = v6;
    hdr = v6;
    if ( v6->numincludemodels != 0 )
      NumSeq_Internal = studiohdr_t::GetNumSeq_Internal(this: v6);
    else
      NumSeq_Internal = v6->numlocalseq;
    v9 = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    activityNames.m_Elements.m_Tree.m_Elements.m_nAllocationCount = NumSeq_Internal;
    activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
    if ( NumSeq_Internal != 0 )
    {
      v9 = (UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                 this: _g_pMemAlloc,
                                                                                                 a2: 16 * NumSeq_Internal);
      activityNames.m_Elements.m_Tree.m_Elements.m_pMemory = v9;
    }
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&activityNames.m_Elements.m_Tree.m_FirstFree = -1;
    activityNames.m_Elements.m_Tree.m_pElements = v9;
    activityNames.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
    while ( 1 )
    {
      v10 = v7->numincludemodels == 0;
      j = v3;
      v11 = v10 ? v7->numlocalseq : studiohdr_t::GetNumSeq_Internal(this: v7);
      if ( v3 >= v11 )
        break;
      if ( v7->numincludemodels != 0 )
      {
        v13 = studiohdr_t::pSeqdesc_Internal(this: v7, i: v3);
      }
      else
      {
        v12 = v3;
        if ( v3 < 0 || v3 >= v7->numlocalseq )
          v12 = 0;
        v13 = (mstudioseqdesc_t *)((char *)v7 + 212 * v12 + v7->localseqindex);
      }
      if ( (v13->flags & 0x400) == 0 )
      {
        if ( v7->numincludemodels != 0 )
        {
          v15 = studiohdr_t::pSeqdesc_Internal(this: v7, i: v3);
        }
        else
        {
          v14 = v3;
          if ( v3 < 0 || v3 >= v7->numlocalseq )
            v14 = 0;
          v15 = (mstudioseqdesc_t *)((char *)v7 + 212 * v14 + v7->localseqindex);
        }
        v16 = (char *)v15 + v15->szactivitynameindex;
        if ( v16 != nullptr && *v16 != 0 )
        {
          search.key = (char *)v15 + v15->szactivitynameindex;
          if ( CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                 this: &activityNames.m_Elements.m_Tree,
                 &search) == 0xFFFF )
          {
            v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v17 != nullptr )
              v18 = KeyValues::KeyValues(this: v17, setName: "node", firstKey: "activity", firstValue: v16);
            else
              v18 = nullptr;
            nItemID = ((int (__thiscall *)(vgui::ListPanel *, KeyValues *, _DWORD, _DWORD, _DWORD, int))this->m_pActivitiesList->AddItem)(
                        a1: this->m_pActivitiesList,
                        a2: v18,
                        a3: 0,
                        a4: 0,
                        a5: 0,
                        a6: m_hSelectedMDL);
            v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v19 != nullptr )
              v20 = KeyValues::KeyValues(this: v19, setName: "drag", firstKey: "text", firstValue: v16);
            else
              v20 = nullptr;
            KeyValues::SetString(this: v20, keyName: "texttype", value: "activityName");
            v21 = vgui::MDLCache();
            m_hSelectedMDL = this->m_hSelectedMDL;
            v22 = (const char *)((int (__thiscall *)(IMDLCache *))v21->GetModelName)(a1: v21);
            KeyValues::SetString(this: v20, keyName: "mdl", value: v22);
            vgui::ListPanel::SetItemDragData(this: this->m_pActivitiesList, itemID: nItemID, data: v20);
            CUtlDict<int,unsigned short>::Insert(this: &activityNames, pName: v16, element: &j);
            v7 = hdr;
          }
        }
        if ( v7->numincludemodels != 0 )
        {
          v24 = studiohdr_t::pSeqdesc_Internal(this: v7, i: j);
        }
        else
        {
          v23 = j;
          if ( j < 0 || j >= v7->numlocalseq )
            v23 = 0;
          v24 = (mstudioseqdesc_t *)((char *)v7 + 212 * v23 + v7->localseqindex);
        }
        v25 = (char *)v24 + v24->szlabelindex;
        if ( v25 != nullptr && *v25 != 0 )
        {
          v26 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v26 != nullptr )
            v27 = KeyValues::KeyValues(this: v26, setName: "node", firstKey: "sequence", firstValue: v25);
          else
            v27 = nullptr;
          v28 = ((int (__thiscall *)(vgui::ListPanel *, KeyValues *, _DWORD, _DWORD, _DWORD, int))this->m_pSequencesList->AddItem)(
                  a1: this->m_pSequencesList,
                  a2: v27,
                  a3: 0,
                  a4: 0,
                  a5: 0,
                  a6: m_hSelectedMDL);
          v29 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v29 != nullptr )
            v30 = KeyValues::KeyValues(this: v29, setName: "drag", firstKey: "text", firstValue: v25);
          else
            v30 = nullptr;
          KeyValues::SetString(this: v30, keyName: "texttype", value: "sequenceName");
          v31 = vgui::MDLCache();
          m_hSelectedMDL = this->m_hSelectedMDL;
          v32 = (const char *)((int (__thiscall *)(IMDLCache *))v31->GetModelName)(a1: v31);
          KeyValues::SetString(this: v30, keyName: "mdl", value: v32);
          vgui::ListPanel::SetItemDragData(this: this->m_pSequencesList, itemID: v28, data: v30);
        }
        v3 = j;
        v7 = hdr;
      }
      ++v3;
    }
    CUtlDict<int,unsigned short>::RemoveAll(this: &activityNames);
    CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &activityNames.m_Elements.m_Tree);
    if ( activityNames.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0
      && activityNames.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: activityNames.m_Elements.m_Tree.m_Elements.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D0FA0
// Name: public: void CMDLPicker::SelectMDL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::SelectMDL(CMDLPicker *this, const char *pRelativePath)
{
  IMDLCache *v3; // eax
  int v4; // edi
  IMDLCache *v5; // eax
  IMDLCache *v6; // eax
  IMDLCache *v7; // eax
  KeyValues *v8; // eax
  const char *v9; // edx
  KeyValues *v10; // eax

  if ( pRelativePath != nullptr )
  {
    v3 = vgui::MDLCache();
    v4 = v3->FindMDL(this: v3, a2: pRelativePath);
  }
  else
  {
    v4 = 0xFFFF;
  }
  if ( (_WORD)v4 == this->m_hSelectedMDL )
  {
    if ( (_WORD)v4 != 0xFFFF )
    {
      v5 = vgui::MDLCache();
      v5->Release(this: v5, a2: v4);
    }
  }
  else
  {
    this->m_hSelectedMDL = v4;
    v6 = vgui::MDLCache();
    if ( v6->IsErrorModel(this: v6, a2: this->m_hSelectedMDL) )
      this->m_hSelectedMDL = -1;
    this->m_pMDLPreview->SetMDL_2(this: this->m_pMDLPreview, a2: this->m_hSelectedMDL, a3: nullptr);
    CMDLPanel::LookAtMDL(this: this->m_pMDLPreview, a2: v4);
    if ( (this->m_nFlags & 8) != 0 )
      CMDLPicker::UpdateSkinsList(this);
    if ( (this->m_nFlags & 0x10) != 0 )
      CMDLPicker::UpdateInfoTab(this, a2: (int)pRelativePath);
    if ( (this->m_nFlags & 6) != 0 )
      CMDLPicker::RefreshActivitiesAndSequencesList(this, m_hSelectedMDL: (int)this);
    if ( (_WORD)v4 != 0xFFFF )
    {
      v7 = vgui::MDLCache();
      v7->Release(this: v7, a2: v4);
    }
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
    {
      v9 = pRelativePath;
      if ( pRelativePath == nullptr )
        v9 = defaultValue;
      v10 = KeyValues::KeyValues(this: v8, setName: "MDLPreviewChanged", firstKey: "mdl", firstValue: v9);
      this->PostActionSignal(this, a2: v10);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D10F0
// Name: private: virtual void CMDLPicker::OnSelectedAssetPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLPicker::OnSelectedAssetPicked(CMDLPicker *this, const char *pMDLName)
{
  char pRelativePath[260]; // [esp+4h] [ebp-104h] BYREF

  if ( pMDLName != nullptr )
  {
    V_snprintf(pDest: pRelativePath, maxLen: 260, pFormat: "models\\%s", pMDLName);
    CMDLPicker::SelectMDL(this, pRelativePath);
  }
  else
  {
    CMDLPicker::SelectMDL(this, pRelativePath: nullptr);
  }
}

} // namespace sceneviewer
