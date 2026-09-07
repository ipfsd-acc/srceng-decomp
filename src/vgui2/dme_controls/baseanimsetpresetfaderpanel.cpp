// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/baseanimsetpresetfaderpanel.cpp
// Functions: 100
// ============================================================

#include "vgui2\dme_controls\baseanimsetpresetfaderpanel.h"

//------------------------------------------------------------------------------
// Address: 0x0048DA60
// Name: int ProceduralTypeForPresetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ProceduralTypeForPresetName(const char *pPresetName)
{
  int v1; // esi

  v1 = 0;
  while ( _V_stricmp(s1: pPresetName, s2: g_ProceduralPresetNames_14[v1]) != 0 )
  {
    if ( ++v1 >= 21 )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0048DAA0
// Name: public: static char const __near * CBaseAnimSetPresetFaderPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAnimSetPresetFaderPanel::GetPanelClassName()
{
  return "CBaseAnimSetPresetFaderPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0048DAB0
// Name: public: static char const __near * CPresetSlider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPresetSlider::GetPanelClassName()
{
  return "CPresetSlider";
}

//------------------------------------------------------------------------------
// Address: 0x0048DAC0
// Name: class CDmePresetGroup __near * FindAnyPresetGroup(class CDmeFilmClip __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePresetGroup *__cdecl FindAnyPresetGroup(CDmeFilmClip *pFilmClip, const char *pPresetGroupName)
{
  CDmeAnimationSet *v2; // eax
  CDmePresetGroup *result; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-8h] BYREF

  traversal.m_pFilmClip = pFilmClip;
  traversal.m_nIndex = 0;
  v2 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  if ( v2 == nullptr )
    return nullptr;
  while ( 1 )
  {
    result = CDmeAnimationSet::FindPresetGroup(this: v2, pGroupName: pPresetGroupName);
    if ( result != nullptr )
      break;
    v2 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v2 == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048DB10
// Name: class CDmePreset __near * FindAnyPreset(class CDmeFilmClip __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePreset *__cdecl FindAnyPreset(CDmeFilmClip *pFilmClip, const char *pPresetGroupName, const char *pPresetName)
{
  CDmeAnimationSet *v3; // eax
  CDmePresetGroup *PresetGroup; // eax
  CDmePreset *result; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-8h] BYREF

  traversal.m_pFilmClip = pFilmClip;
  traversal.m_nIndex = 0;
  v3 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  if ( v3 == nullptr )
    return nullptr;
  while ( 1 )
  {
    PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v3, pGroupName: pPresetGroupName);
    if ( PresetGroup != nullptr )
    {
      result = CDmePresetGroup::FindPreset(this: PresetGroup, pPresetName);
      if ( result != nullptr )
        break;
    }
    v3 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v3 == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048DB70
// Name: public: static char const __near * CAddPresetDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAddPresetDialog::GetPanelClassName()
{
  return "CAddPresetDialog";
}

//------------------------------------------------------------------------------
// Address: 0x0048DB80
// Name: protected: virtual void CAddPresetDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAddPresetDialog::OnCommand(CAddPresetDialog *this, const char *command)
{
  int v3; // edi
  void *v4; // esp
  vgui::TextEntry *m_pPresetName; // ecx
  vgui::TextEntry_vtbl *v6; // edx
  int v7; // edi
  void *v8; // esp
  KeyValues *v9; // eax
  KeyValues *v10; // edi
  char v11[12]; // [esp+0h] [ebp-10h] BYREF
  char *txt; // [esp+Ch] [ebp-4h]
  bool bAnimated_3; // [esp+1Bh] [ebp+Bh]

  if ( _V_stricmp(s1: command, s2: "OK") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Cancel") != 0 )
      vgui::BaseInputDialog::OnCommand(this, command);
    else
      this->CloseModal(this);
  }
  else
  {
    v3 = this->m_pPresetName->GetTextLength(this: this->m_pPresetName) + 1;
    v4 = alloca(v3);
    m_pPresetName = this->m_pPresetName;
    v6 = m_pPresetName->__vftable;
    txt = v11;
    v6->GetText_2(this: m_pPresetName, a2: v11, a3: v3);
    v7 = this->m_pPresetGroup->GetTextLength(this: this->m_pPresetGroup) + 1;
    v8 = alloca(v7);
    this->m_pPresetGroup->GetText_2(this: this->m_pPresetGroup, a2: v11, a3: v7);
    bAnimated_3 = this->m_pAnimated->IsSelected(this: this->m_pAnimated);
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
      v10 = KeyValues::KeyValues(this: v9, setName: "PresetNameSelected", firstKey: "text", firstValue: txt);
    else
      v10 = nullptr;
    KeyValues::SetString(this: v10, keyName: "presetGroupName", value: v11);
    KeyValues::SetInt(this: v10, keyName: "animated", value: bAnimated_3);
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v10, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    this->PostActionSignal(this, a2: v10);
    this->CloseModal(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048DCE0
// Name: protected: virtual void CAddPresetDialog::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAddPresetDialog::OnTick(CAddPresetDialog *this)
{
  bool bEnableOkayButton; // [esp+4h] [ebp-4h]

  if ( this->m_pPresetName->GetTextLength(this: this->m_pPresetName) <= 0
    || (bEnableOkayButton = true, this->m_pPresetGroup->GetTextLength(this: this->m_pPresetGroup) <= 0) )
  {
    bEnableOkayButton = false;
  }
  this->m_pOKButton->SetEnabled(this: this->m_pOKButton, a2: bEnableOkayButton);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0048DD40
// Name: public: char const __near * CPresetSlider::GetPresetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPresetSlider::GetPresetName(CPresetSlider *this)
{
  const char *result; // eax

  result = this->m_presetName.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048DD60
// Name: public: char const __near * CPresetSlider::GetPresetGroupName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPresetSlider::GetPresetGroupName(CPresetSlider *this)
{
  const char *result; // eax

  result = this->m_presetGroupName.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048DD80
// Name: protected: virtual void CPresetSlider::OnRename(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnRename(CPresetSlider *this)
{
  vgui::InputDialog *v2; // edi
  const char *v3; // eax
  vgui::InputDialog *v4; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v2 = (vgui::InputDialog *)MemAlloc_Alloc(nSize: 0x22Cu);
  if ( v2 != nullptr )
  {
    v3 = this->GetName(this);
    v4 = vgui::InputDialog::InputDialog(
           this: v2,
           parent: this,
           title: "Rename Preset",
           prompt: "Name:",
           defaultValue: v3);
    if ( v4 != nullptr )
    {
      v4->SetSmallCaption(this: v4, a2: true);
      vgui::InputDialog::SetMultiline(this: v4, state: false);
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
      {
        v6 = KeyValues::KeyValues(this: v5, setName: "RenamePreset");
        vgui::BaseInputDialog::DoModal(this: v4, pContextKeyValues: v6);
      }
      else
      {
        vgui::BaseInputDialog::DoModal(this: v4, pContextKeyValues: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048DE10
// Name: protected: virtual void CPresetSlider::OnDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnDelete(CPresetSlider *this)
{
  const char *v2; // eax
  vgui::MessageBox *v3; // eax
  vgui::MessageBox *v4; // eax
  vgui::MessageBox *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  char sz[256]; // [esp+4h] [ebp-100h] BYREF

  v2 = this->GetName(this);
  V_snprintf(pDest: sz, maxLen: 256, pFormat: "Delete '%s'?", v2);
  v3 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
  if ( v3 != nullptr )
  {
    v4 = vgui::MessageBox::MessageBox(this: v3, title: "Delete Preset", text: sz, parent: this);
    v5 = v4;
    if ( v4 != nullptr )
    {
      vgui::MessageBox::SetCancelButtonVisible(this: v4, state: true);
      vgui::MessageBox::SetCancelButtonText(this: v5, buttonText: "#VGui_Cancel");
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "OnDeleteConfirmed");
      else
        v7 = nullptr;
      v5->SetCommand(this: v5, a2: v7);
      v5->AddActionSignalTarget_2(this: v5, a2: this);
      v5->DoModal_2(this: v5, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048DED0
// Name: protected: virtual void CPresetSlider::GetTrackRect(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::GetTrackRect(CPresetSlider *this, int *x, int *y, int *w, int *h)
{
  vgui::Panel::GetSize(this, wide: w, tall: h);
  *x = 2;
  *y = 2;
  *w -= 4;
  *h -= 4;
}

//------------------------------------------------------------------------------
// Address: 0x0048DF00
// Name: protected: virtual void CPresetSlider::OnCurve1(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCurve1(CPresetSlider *this)
{
  this->m_pPresetFaderPanel->DispatchCurve(this: this->m_pPresetFaderPanel, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0048DF20
// Name: protected: virtual void CPresetSlider::OnCurve2(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCurve2(CPresetSlider *this)
{
  this->m_pPresetFaderPanel->DispatchCurve(this: this->m_pPresetFaderPanel, a2: 2);
}

//------------------------------------------------------------------------------
// Address: 0x0048DF40
// Name: protected: virtual void CPresetSlider::OnCurve3(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCurve3(CPresetSlider *this)
{
  this->m_pPresetFaderPanel->DispatchCurve(this: this->m_pPresetFaderPanel, a2: 3);
}

//------------------------------------------------------------------------------
// Address: 0x0048DF60
// Name: protected: virtual void CPresetSlider::OnCurve4(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCurve4(CPresetSlider *this)
{
  this->m_pPresetFaderPanel->DispatchCurve(this: this->m_pPresetFaderPanel, a2: 4);
}

//------------------------------------------------------------------------------
// Address: 0x0048DF80
// Name: public: static char const __near * CSliderListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSliderListPanel::GetPanelClassName()
{
  return "CSliderListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0048DF90
// Name: public: virtual void CSliderListPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSliderListPanel::OnMousePressed(CSliderListPanel *this, const char *code)
{
  if ( code != (const char *)108 )
    vgui::Panel::OnMousePressed(this, panelName: code);
}

//------------------------------------------------------------------------------
// Address: 0x0048DFB0
// Name: public: virtual void CSliderListPanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSliderListPanel::OnMouseReleased(CSliderListPanel *this, const char *code)
{
  if ( code == (const char *)108 )
    this->OnShowContextMenu(this);
  else
    vgui::Panel::OnMousePressed(this, panelName: code);
}

//------------------------------------------------------------------------------
// Address: 0x0048E090
// Name: public: int CJob::Abort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::Abort(CJob *this, BOOL bDiscard)
{
  int result; // eax
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  bool v6; // bl
  int v7; // eax
  int m_status; // [esp+10h] [ebp+8h]

  result = this->m_status;
  if ( result == 1 || result == 2 || result == 4 )
  {
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    this->AddRef(this);
    switch ( this->m_status )
    {
      case 1:
      case 4:
        v6 = bDiscard;
        v7 = this->DoAbort(this, a2: bDiscard);
        this->m_status = v7;
        m_status = v7;
        if ( v6 )
          this->DoCleanup(this);
        CThreadEvent::Set(this: &this->m_CompleteEvent);
        break;
      default:
        m_status = this->m_status;
        break;
    }
    this->Release(this);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return m_status;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048E160
// Name: public: CAddPresetDialog::CAddPresetDialog(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CAddPresetDialog *__thiscall CAddPresetDialog::CAddPresetDialog(CAddPresetDialog *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::TextEntry *v6; // eax
  vgui::TextEntry *v7; // eax
  vgui::ComboBox *v8; // eax
  vgui::ComboBox *v9; // eax
  vgui::CheckButton *v10; // eax
  vgui::CheckButton *v11; // eax

  vgui::BaseInputDialog::BaseInputDialog(this, parent, title: "Enter Preset Name", bShowCancelButton: true);
  this->__vftable = (CAddPresetDialog_vtbl *)&CAddPresetDialog::`vftable';
  if ( `CAddPresetDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CAddPresetDialog::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CAddPresetDialog");
    v3->pfnClassName = CAddPresetDialog::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::BaseInputDialog");
  }
  if ( `CAddPresetDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAddPresetDialog::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CAddPresetDialog");
    v4->pfnClassName = CAddPresetDialog::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::BaseInputDialog");
  }
  if ( `CAddPresetDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAddPresetDialog::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CAddPresetDialog");
    v5->pfnClassName = CAddPresetDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::BaseInputDialog");
  }
  v6 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v6 != nullptr )
    v7 = vgui::TextEntry::TextEntry(this: v6, parent: this, panelName: "PresetName");
  else
    v7 = nullptr;
  this->m_pPresetName = v7;
  v8 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v8 != nullptr )
    v9 = vgui::ComboBox::ComboBox(this: v8, parent: this, panelName: "PresetGroup", numLines: 8, allowEdit: true);
  else
    v9 = nullptr;
  this->m_pPresetGroup = v9;
  v10 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v10 != nullptr )
    v11 = vgui::CheckButton::CheckButton(this: v10, parent: this, panelName: "Animated", text: "Animated");
  else
    v11 = nullptr;
  this->m_pAnimated = v11;
  vgui::Frame::SetDeleteSelfOnClose(this, state: false);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/addpresetdialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0048E2D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAddPresetDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAddPresetDialog::GetMessageMap(CAddPresetDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAddPresetDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAddPresetDialog::GetMessageMap'::`2'::s_pMap;
  `CAddPresetDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAddPresetDialog");
  `CAddPresetDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048E300
// Name: public: virtual struct PanelAnimationMap __near * CAddPresetDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAddPresetDialog::GetAnimMap(CAddPresetDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CAddPresetDialog");
}

//------------------------------------------------------------------------------
// Address: 0x0048E310
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAddPresetDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAddPresetDialog::GetKBMap(CAddPresetDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAddPresetDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAddPresetDialog::GetKBMap'::`2'::s_pMap;
  `CAddPresetDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAddPresetDialog");
  `CAddPresetDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048E370
// Name: public: void CPresetSlider::Init(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::Init(CPresetSlider *this, const char *pPresetGroupName, const char *pPresetName)
{
  CUtlSymbolLarge *v4; // eax
  const char *v5; // edi
  CUtlSymbolLarge *v6; // eax
  bool v7; // zf
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // eax
  CDmeAnimationSet *v9; // eax
  CDmePresetGroup *PresetGroup; // eax
  CDmePreset *Preset; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-8h] BYREF

  this->m_nProceduralType = 0;
  this->m_bReadOnly = false;
  v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &traversal.m_nIndex, a3: pPresetGroupName);
  v5 = pPresetName;
  this->m_presetGroupName = (CUtlSymbolLarge)v4->u.m_Id;
  v6 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pPresetName, a3: v5);
  v7 = (_S1_2 & 1) == 0;
  this->m_presetName = (CUtlSymbolLarge)v6->u.m_Id;
  if ( v7 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_2 |= 1u;
    GetSymbol(this: g_pDataModel, result: &proceduralPresetGroupNameSym, a3: "Procedural");
  }
  if ( this->m_presetGroupName.u.m_Id == proceduralPresetGroupNameSym.u.m_Id )
  {
    this->m_nProceduralType = ProceduralTypeForPresetName(pPresetName: v5);
    this->m_bReadOnly = true;
  }
  else
  {
    traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pPresetFaderPanel->m_pController);
    traversal.m_nIndex = 0;
    while ( 1 )
    {
      v9 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      if ( v9 == nullptr )
        break;
      PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v9, pGroupName: pPresetGroupName);
      if ( PresetGroup != nullptr )
      {
        Preset = CDmePresetGroup::FindPreset(this: PresetGroup, pPresetName: v5);
        if ( Preset != nullptr )
        {
          this->m_bReadOnly = CDmePreset::IsReadOnly(this: Preset);
          break;
        }
      }
    }
  }
  vgui::Panel::SetName(this, panelName: v5);
  this->m_pName->SetText_2(this: this->m_pName, a2: v5);
  vgui::TextImage::ResizeImageToContent(this: this->m_pName);
  ((void (__thiscall *)(CPresetSlider *, int))this->SetBgColor)(a1: this, a2: -2139062144);
}

//------------------------------------------------------------------------------
// Address: 0x0048E4B0
// Name: protected: virtual void CPresetSlider::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnMouseReleased(CPresetSlider *this, ButtonCode_t code)
{
  int v3; // eax
  bool dragging; // bl
  float flLastValue; // [esp+14h] [ebp+8h]

  this->m_bIgnoreCursorMovedEvents = false;
  if ( code == MOUSE_RIGHT )
  {
    this->OnShowContextMenu(this);
  }
  else if ( code == KEY_COUNT )
  {
    v3 = this->GetValue(this);
    dragging = this->_dragging;
    flLastValue = (float)v3 * 0.001;
    vgui::Slider::OnMouseReleased(this, code: KEY_COUNT);
    if ( dragging )
    {
      CBaseAnimationSetControl::ApplyPreset(
        this: this->m_pPresetFaderPanel->m_pController,
        flScale: flLastValue,
        values: &this->m_AttributeLookup);
      this->SetCursor(this, a2: 2u);
    }
    if ( CPresetSlider::s_bResetMousePosOnMouseUp )
    {
      CPresetSlider::s_bResetMousePosOnMouseUp = false;
      g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: CPresetSlider::s_nMousePosX, a3: CPresetSlider::s_nMousePosY);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048E570
// Name: private: void CPresetSlider::OnRenameCompleted(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnRenameCompleted(CPresetSlider *this, const char *pText, KeyValues *pContextKeyValues)
{
  const char *v3; // edi
  const char *v5; // eax
  const char *PresetGroupName; // eax
  CDmeAnimationSet *v7; // edx
  const char *PresetName; // eax
  CDmePresetGroup *v9; // edx
  CDmePreset *Preset; // ebx
  const char *v11; // eax
  const char *v12; // [esp-4h] [ebp-14h]
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-8h] BYREF

  v3 = pText;
  if ( pText != nullptr && *pText != 0 )
  {
    v12 = pText;
    v5 = this->GetName(this);
    if ( _V_strcmp(s1: v5, s2: v12) != 0 )
    {
      g_pDataModel->StartUndo(this: g_pDataModel, a2: "Rename Preset", a3: "Rename Preset", a4: 0);
      g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Rename Preset", a3: 0, a4: 256);
      vgui::Panel::SetName(this, panelName: v3);
      this->m_pName->SetText_2(this: this->m_pName, a2: v3);
      vgui::TextImage::ResizeImageToContent(this: this->m_pName);
      this->m_presetName.u.m_Id = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pText, a3: v3)->u.m_Id;
      traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pPresetFaderPanel->m_pController);
      traversal.m_nIndex = 0;
      while ( CAnimSetGroupAnimSetTraversal::Next(this: &traversal) != nullptr )
      {
        PresetGroupName = CPresetSlider::GetPresetGroupName(this);
        CDmeAnimationSet::FindPresetGroup(this: v7, pGroupName: PresetGroupName);
        PresetName = CPresetSlider::GetPresetName(this);
        Preset = CDmePresetGroup::FindPreset(this: v9, pPresetName: PresetName);
        g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pText, a3: v3);
        CDmAttribute::SetValue<CUtlSymbolLarge>(
          this: Preset->m_Name.m_pAttribute,
          value: (const CUtlSymbolLarge *)&pText);
      }
      g_pDataModel->FinishUndo(this: g_pDataModel);
      g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    }
  }
  else
  {
    v11 = this->GetName(this);
    _Warning(a1: "Can't rename preset for %s to an empty name\n", v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048E6F0
// Name: protected: virtual void CPresetSlider::OnInputCompleted(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnInputCompleted(CPresetSlider *this, KeyValues *pParams)
{
  const char *String; // ebx
  KeyValues *Key; // eax

  String = KeyValues::GetString(this: pParams, keyName: "text", defaultValue: nullptr);
  Key = KeyValues::FindKey(this: pParams, keyName: "RenamePreset", bCreate: false);
  if ( Key != nullptr )
    CPresetSlider::OnRenameCompleted(this, pText: String, pContextKeyValues: Key);
}

//------------------------------------------------------------------------------
// Address: 0x0048E730
// Name: protected: virtual void CPresetSlider::OnShowContextMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnShowContextMenu(CPresetSlider *this)
{
  vgui::Panel *v2; // eax
  vgui::Menu *v3; // eax
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // ebx
  vgui::Panel *v7; // eax
  const char *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // ebx
  vgui::Panel *v15; // eax
  int v16; // ebx
  vgui::Panel *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // ebx
  vgui::Panel *v20; // eax
  vgui::Menu *v21; // eax

  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    if ( v2 != nullptr )
      ((void (__thiscall *)(vgui::Panel *, int))v2->dtr_Panel)(a1: v2, a2: 1);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  v3 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v3 != nullptr )
    v4 = vgui::Menu::Menu(this: v3, parent: this, panelName: "ActionMenu");
  else
    v4 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: v4);
  if ( !this->m_bReadOnly )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "OnRename");
    else
      v6 = nullptr;
    v7 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CPresetSlider *, _DWORD))v7->__vftable[1].PaintTraverse)(
      a1: v7,
      a2: "Rename...",
      a3: v6,
      a4: this,
      a5: 0);
    v8 = this->GetName(this);
    if ( _V_stricmp(s1: v8, s2: "Default") != 0 )
    {
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
        v10 = KeyValues::KeyValues(this: v9, setName: "OnDelete");
      else
        v10 = nullptr;
      v11 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CPresetSlider *, _DWORD))v11->__vftable[1].PaintTraverse)(
        a1: v11,
        a2: "Delete...",
        a3: v10,
        a4: this,
        a5: 0);
    }
    v12 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v12->__vftable[1].DeletePanel(this: v12);
  }
  v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v13 != nullptr )
    v14 = KeyValues::KeyValues(this: v13, setName: "ShowAddPresetDialog");
  else
    v14 = nullptr;
  v15 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  v16 = ((int (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimSetPresetFaderPanel *, _DWORD))v15->__vftable[1].PaintTraverse)(
          a1: v15,
          a2: "Add...",
          a3: v14,
          a4: this->m_pPresetFaderPanel,
          a5: 0);
  if ( CBaseAnimationSetControl::GetMostRecentlySelectedControl(this: this->m_pPresetFaderPanel->m_pController) == nullptr )
  {
    v17 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    ((void (__thiscall *)(vgui::Panel *, int, _DWORD))v17->__vftable[1].GetKBMap)(a1: v17, a2: v16, a3: 0);
  }
  v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v18 != nullptr )
    v19 = KeyValues::KeyValues(this: v18, setName: "ManagePresets");
  else
    v19 = nullptr;
  v20 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimSetPresetFaderPanel *, _DWORD))v20->__vftable[1].PaintTraverse)(
    a1: v20,
    a2: "Manage...",
    a3: v19,
    a4: this->m_pPresetFaderPanel,
    a5: 0);
  v21 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
  vgui::Menu::PlaceContextMenu(parent: this, menu: v21);
}

//------------------------------------------------------------------------------
// Address: 0x0048E940
// Name: private: void CPresetSlider::UpdateTickPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::UpdateTickPos(CPresetSlider *this, int x, int y)
{
  float v4; // xmm0_4
  int ty; // [esp+4h] [ebp-10h] BYREF
  int th; // [esp+8h] [ebp-Ch] BYREF
  int tw; // [esp+Ch] [ebp-8h] BYREF
  int tx; // [esp+10h] [ebp-4h] BYREF

  if ( !this->m_bIgnoreCursorMovedEvents )
  {
    this->GetTrackRect(this, a2: &tx, a3: &ty, a4: &tw, a5: &th);
    v4 = 0.0;
    if ( x > tx )
    {
      if ( x >= tx + tw || tw <= 0 )
        v4 = 1.0;
      else
        v4 = (float)(x - tx) / (float)tw;
    }
    this->SetValue(this, a2: (int)(float)((float)(v4 * 1000.0) + 0.5), a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048E9E0
// Name: protected: virtual void CPresetSlider::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCursorMoved(CPresetSlider *this, int x, int y)
{
  CPresetSlider::UpdateTickPos(this, x, y);
}

//------------------------------------------------------------------------------
// Address: 0x0048E9F0
// Name: protected: virtual void CPresetSlider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::ApplySchemeSettings(CPresetSlider *this, vgui::IScheme *scheme)
{
  vgui::TextImage_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::Slider::ApplySchemeSettings(this, pScheme: scheme);
  v3 = this->m_pName->__vftable;
  v4 = scheme->GetFont(this: scheme, a2: "DefaultBold", a3: false);
  v3->SetFont(this: this->m_pName, a2: v4);
  ((void (__thiscall *)(vgui::TextImage *, _DWORD))this->m_pName->SetColor)(
    a1: this->m_pName,
    a2: *(_DWORD *)&this->m_TextColor);
  vgui::TextImage::ResizeImageToContent(this: this->m_pName);
  ((void (__thiscall *)(CPresetSlider *, int))this->SetFgColor)(a1: this, a2: -16746302);
  this->SetThumbWidth(this, a2: 3);
}

//------------------------------------------------------------------------------
// Address: 0x0048EA80
// Name: private: virtual void CSliderListPanel::OnShowContextMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSliderListPanel::OnShowContextMenu(CSliderListPanel *this)
{
  vgui::Panel *v2; // eax
  vgui::Menu *v3; // eax
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // ebx
  vgui::Panel *v7; // eax
  int v8; // ebx
  vgui::Panel *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  vgui::Panel *v12; // eax
  vgui::Menu *v13; // eax

  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    if ( v2 != nullptr )
      ((void (__thiscall *)(vgui::Panel *, int))v2->dtr_Panel)(a1: v2, a2: 1);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  v3 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v3 != nullptr )
    v4 = vgui::Menu::Menu(this: v3, parent: this, panelName: "ActionMenu");
  else
    v4 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: v4);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ShowAddPresetDialog");
  else
    v6 = nullptr;
  v7 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  v8 = ((int (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimSetPresetFaderPanel *, _DWORD))v7->__vftable[1].PaintTraverse)(
         a1: v7,
         a2: "Add...",
         a3: v6,
         a4: this->m_pPresetFaderPanel,
         a5: 0);
  if ( CBaseAnimationSetControl::GetMostRecentlySelectedControl(this: this->m_pPresetFaderPanel->m_pController) == nullptr )
  {
    v9 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    ((void (__thiscall *)(vgui::Panel *, int, _DWORD))v9->__vftable[1].GetKBMap)(a1: v9, a2: v8, a3: 0);
  }
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(this: v10, setName: "ManagePresets");
  else
    v11 = nullptr;
  v12 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimSetPresetFaderPanel *, _DWORD))v12->__vftable[1].PaintTraverse)(
    a1: v12,
    a2: "Manage...",
    a3: v11,
    a4: this->m_pPresetFaderPanel,
    a5: 0);
  v13 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
  vgui::Menu::PlaceContextMenu(parent: this, menu: v13);
}

//------------------------------------------------------------------------------
// Address: 0x0048EBD0
// Name: protected: virtual void CBaseAnimSetPresetFaderPanel::OnManagePresets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::OnManagePresets(CBaseAnimSetPresetFaderPanel *this)
{
  CDmePresetGroupEditorFrame *v2; // eax
  CDmePresetGroupEditorFrame *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // ebx
  CDmeFilmClip *AnimationSetClip; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &this->m_hPresetEditor) == nullptr )
  {
    v2 = (CDmePresetGroupEditorFrame *)MemAlloc_Alloc(nSize: 0x224u);
    if ( v2 != nullptr )
      v3 = CDmePresetGroupEditorFrame::CDmePresetGroupEditorFrame(this: v2, pParent: this, pTitle: "Manage Presets");
    else
      v3 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hPresetEditor, pPanel: v3);
    v4 = vgui::PHandle::Get(this: &this->m_hPresetEditor);
    v4->AddActionSignalTarget_2(this: v4, a2: this);
    v5 = vgui::PHandle::Get(this: &this->m_hPresetEditor);
    v5->SetVisible(this: v5, a2: false);
    v6 = vgui::PHandle::Get(this: &this->m_hPresetEditor);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v6->__vftable[1].GetUnpackStructure)(a1: v6, a2: 0);
    v7 = vgui::PHandle::Get(this: &this->m_hPresetEditor);
    v7->__vftable[1].dtr_Panel(this: v7);
  }
  v8 = vgui::PHandle::Get(this: &this->m_hPresetEditor);
  AnimationSetClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  CDmePresetGroupEditorPanel::SetAnimationSetClip(
    this: (CDmePresetGroupEditorPanel *)v8[1].m_sNavUpName.m_Storage.m_nActualLength,
    pFilmClip: AnimationSetClip);
  v10 = vgui::PHandle::Get(this: &this->m_hPresetEditor);
  v10->__vftable[1].IsEnabled(this: v10);
}

//------------------------------------------------------------------------------
// Address: 0x0048ECC0
// Name: public: virtual void CBaseAnimSetPresetFaderPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::ApplySchemeSettings(
        CBaseAnimSetPresetFaderPanel *this,
        vgui::IScheme *scheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme: scheme);
  ((void (__thiscall *)(CSliderListPanel *, int))this->m_pSliders->SetBgColor)(a1: this->m_pSliders, a2: -14013910);
}

//------------------------------------------------------------------------------
// Address: 0x0048ECF0
// Name: public: class CPresetSlider __near * CBaseAnimSetPresetFaderPanel::GetActivePresetSlider(void)
// Source: json
//------------------------------------------------------------------------------
CPresetSlider *__thiscall CBaseAnimSetPresetFaderPanel::GetActivePresetSlider(CBaseAnimSetPresetFaderPanel *this)
{
  return (CPresetSlider *)vgui::PHandle::Get(this: &this->m_hActivePresetSlider);
}

//------------------------------------------------------------------------------
// Address: 0x0048ED00
// Name: private: void CParallelProcessor<class CPresetSlider __near *,class CFuncJobItemProcessor<class CPresetSlider __near *>,1>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::DoExecute(
        CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *this)
{
  void (*m_pfnBegin)(void); // eax
  CPresetSlider **m_pLimit; // ecx
  unsigned int v4; // edx
  CPresetSlider **v5; // esi
  CPresetSlider **v6; // edi
  void (*m_pfnEnd)(void); // ebx
  unsigned int v8; // [esp+4h] [ebp-8h]
  CPresetSlider **pLimit; // [esp+8h] [ebp-4h]

  if ( this->m_pItems.m_value < this->m_pLimit )
  {
    m_pfnBegin = this->m_ItemProcessor.m_pfnBegin;
    if ( m_pfnBegin != nullptr )
      m_pfnBegin();
    m_pLimit = this->m_pLimit;
    v4 = 4 * this->m_nChunkSize;
    pLimit = m_pLimit;
    v8 = v4;
    do
    {
      v5 = (CPresetSlider **)_InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pItems, v4);
      v6 = (CPresetSlider **)((char *)v5 + v4);
      if ( m_pLimit < (CPresetSlider **)((char *)v5 + v4) )
        v6 = m_pLimit;
      if ( v5 < v6 )
      {
        do
          this->m_ItemProcessor.m_pfnProcess(a1: v5++);
        while ( v5 < v6 );
        m_pLimit = pLimit;
        v4 = v8;
      }
    }
    while ( v5 < m_pLimit );
    m_pfnEnd = this->m_ItemProcessor.m_pfnEnd;
    if ( m_pfnEnd != nullptr )
      m_pfnEnd();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048EDD0
// Name: protected: virtual void CPresetSlider::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnMousePressed(CPresetSlider *this, ButtonCode_t code)
{
  vgui::DHANDLE<CPresetSlider> *p_m_hActivePresetSlider; // ecx
  int th; // [esp+4h] [ebp-18h] BYREF
  int my; // [esp+8h] [ebp-14h] BYREF
  int mx; // [esp+Ch] [ebp-10h] BYREF
  int tw; // [esp+10h] [ebp-Ch] BYREF
  int ty; // [esp+14h] [ebp-8h] BYREF
  int tx; // [esp+18h] [ebp-4h] BYREF

  p_m_hActivePresetSlider = &this->m_pPresetFaderPanel->m_hActivePresetSlider;
  this->m_bIgnoreCursorMovedEvents = false;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_hActivePresetSlider, pPanel: this);
  if ( code == KEY_COUNT )
  {
    if ( this->_dragging )
    {
      this->OnMouseReleased(this, a2: KEY_COUNT);
    }
    else
    {
      vgui::Slider::OnMousePressed(this, code: KEY_COUNT);
      if ( this->_dragging )
      {
        this->SetCursor(this, a2: 15u);
        g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my);
        this->GetTrackRect(this, a2: &tx, a3: &ty, a4: &tw, a5: &th);
        vgui::Panel::LocalToScreen(this, x: &tx, y: &ty);
        if ( mx < tx + tw )
        {
          if ( mx >= tx )
          {
            CPresetSlider::s_nMousePosX = mx;
            CPresetSlider::s_bResetMousePosOnMouseUp = true;
            CPresetSlider::s_nMousePosY = my;
            g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: tx, a3: my);
          }
          this->SetValue(this, a2: 0, a3: false);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048EED0
// Name: protected: virtual void CPresetSlider::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCursorEntered(CPresetSlider *this)
{
  if ( !this->_dragging )
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: &this->m_pPresetFaderPanel->m_hActivePresetSlider,
      pPanel: this);
}

//------------------------------------------------------------------------------
// Address: 0x0048EEF0
// Name: protected: virtual void CPresetSlider::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCursorExited(CPresetSlider *this)
{
  if ( !this->_dragging )
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: &this->m_pPresetFaderPanel->m_hActivePresetSlider,
      pPanel: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0048EF10
// Name: protected: virtual void CPresetSlider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::Paint(CPresetSlider *this)
{
  bool v2; // al
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  int v5; // eax
  int x; // [esp+4h] [ebp-1Ch] BYREF
  int wide; // [esp+8h] [ebp-18h] BYREF
  int tall; // [esp+Ch] [ebp-14h] BYREF
  int y; // [esp+10h] [ebp-10h] BYREF
  Color col; // [esp+14h] [ebp-Ch] BYREF
  int mx; // [esp+18h] [ebp-8h] BYREF
  int my; // [esp+1Ch] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &this->m_pPresetFaderPanel->m_hActivePresetSlider) == this )
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
      || (v2 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
    {
      v2 = true;
    }
    if ( this->_dragging || v2 )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my);
      vgui::Panel::ScreenToLocal(this, x: &mx, y: &my);
      CPresetSlider::UpdateTickPos(this, x: mx, y: my);
      this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
      this->GetFgColor(this, result: &col);
      ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: col);
      v3 = g_pVGuiSurface;
      v4 = g_pVGuiSurface->__vftable;
      v5 = vgui::Panel::GetTall(this);
      v4->DrawFilledRect(this: v3, a2: this->_nobPos[0], a3: 1, a4: this->_nobPos[1], a5: v5 - 1);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->m_ZeroColor);
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: this->_nobPos[0] - 1,
        a3: y + 1,
        a4: this->_nobPos[0],
        a5: y + tall - 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048F050
// Name: protected: virtual void CPresetSlider::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPresetSlider::PaintBackground(CPresetSlider *this@<ecx>, int a2@<edi>)
{
  bool v3; // zf
  bool (__thiscall *IsKeyDown)(vgui::IInput *, ButtonCode_t); // eax
  bool v5; // al
  bool v6; // al
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // eax
  int (__thiscall *GetValue)(vgui::Slider *); // edx
  int v9; // eax
  int v10; // edi
  float v11; // xmm0_4
  vgui::ISurface_vtbl *v12; // edx
  void (__thiscall *DrawFilledRectFade)(vgui::ISurface *, int, int, int, int, unsigned int, unsigned int, bool); // edx
  Color m_TextColor; // eax
  Color m_GradientColor; // eax
  int cw; // [esp+8h] [ebp-30h] BYREF
  int w; // [esp+Ch] [ebp-2Ch] BYREF
  int v18; // [esp+10h] [ebp-28h] BYREF
  int h; // [esp+14h] [ebp-24h] BYREF
  __int64 v20; // [esp+18h] [ebp-20h]
  int tw; // [esp+20h] [ebp-18h] BYREF
  int th; // [esp+24h] [ebp-14h] BYREF
  int tx; // [esp+28h] [ebp-10h] BYREF
  int ty; // [esp+2Ch] [ebp-Ch] BYREF
  float v25; // [esp+30h] [ebp-8h]
  bool bIsAltKeyDown; // [esp+36h] [ebp-2h]
  bool bIsShiftKeyDown; // [esp+37h] [ebp-1h]

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v3 = vgui::PHandle::Get(this: &this->m_pPresetFaderPanel->m_hActivePresetSlider) == this;
  IsKeyDown = g_pVGuiInput->IsKeyDown;
  HIBYTE(v25) = v3;
  if ( IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (v5 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT), bIsShiftKeyDown = false, v5) )
  {
    bIsShiftKeyDown = true;
  }
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v6 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT), bIsAltKeyDown = false, v6) )
  {
    bIsAltKeyDown = true;
  }
  if ( HIBYTE(v25) == 0 )
  {
    m_TextColor = this->m_TextColor;
    goto LABEL_20;
  }
  if ( !this->_dragging && !bIsShiftKeyDown )
    goto LABEL_18;
  ((void (__thiscall *)(CPresetSlider *, int *, int *, int *, int *, int))this->GetTrackRect)(
    a1: this,
    a2: &tx,
    a3: &ty,
    a4: &tw,
    a5: &th,
    a6: a2);
  DrawSetColor = g_pVGuiSurface->DrawSetColor;
  v25 = -1.7014118e38;
  ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: -16777216);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: tx, a3: ty, a4: tx + tw, a5: ty + th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_GradientColor);
  tw -= 2;
  th -= 2;
  GetValue = this->GetValue;
  ++tx;
  ++ty;
  v9 = GetValue(this);
  v10 = (int)(float)((float)((float)tw * (float)((float)v9 * 0.001)) + 0.5);
  v11 = 15.0;
  if ( (float)((float)((float)this->GetValue(this) * 0.001) * 255.0) > 15.0 )
    v11 = (float)((float)this->GetValue(this) * 0.001) * 255.0;
  v3 = !this->_dragging;
  v25 = v11;
  if ( v3 )
  {
    if ( bIsAltKeyDown )
      m_GradientColor = this->m_GradientColor;
    else
      m_GradientColor = this->m_ZeroColor;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: m_GradientColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: tx, a3: ty, a4: tx + tw, a5: ty + th);
LABEL_18:
    m_TextColor = this->m_TextColorFocus;
    goto LABEL_20;
  }
  v12 = g_pVGuiSurface->__vftable;
  HIDWORD(v20) = HIWORD(v25) | 0xC00;
  DrawFilledRectFade = v12->DrawFilledRectFade;
  v20 = (__int64)v25;
  ((void (__thiscall *)(vgui::ISurface *, int, int, int, int, int, _DWORD))DrawFilledRectFade)(
    a1: g_pVGuiSurface,
    a2: tx,
    a3: ty,
    a4: v10 + tx,
    a5: ty + th,
    a6: 15,
    a7: v20);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_ZeroColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v10 + tx + 1, a3: ty, a4: tx + tw, a5: th + ty);
  m_TextColor = this->m_TextColorFocus;
LABEL_20:
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pName->SetColor)(a1: this->m_pName, a2: m_TextColor);
  this->m_pName->GetContentSize(this: this->m_pName, a2: &cw, a3: &v18);
  this->m_pName->SetPos(
    this: this->m_pName,
    a2: (int)(float)((float)(w - cw) * 0.5),
    a3: (int)(float)((float)(h - v18) * 0.5));
  this->m_pName->Paint(this: this->m_pName);
}

//------------------------------------------------------------------------------
// Address: 0x0048F370
// Name: protected: void CBaseAnimSetPresetFaderPanel::AddPreset(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::AddPreset(
        CBaseAnimSetPresetFaderPanel *this,
        const char *pPresetGroupName,
        const char *pPresetName,
        int bAnimated)
{
  const char *v4; // edi
  vgui::MessageBox *v5; // esi
  CDmeAnimationSet *v7; // esi
  CDmePresetGroup *PresetGroup; // edi
  vgui::MessageBox *v9; // eax
  vgui::MessageBox *v10; // esi
  vgui::MessageBox *v11; // eax
  vgui::MessageBox *v12; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-8h] BYREF

  v4 = pPresetName;
  v5 = nullptr;
  if ( pPresetName == nullptr || *pPresetName == 0 )
  {
    v12 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v12 != nullptr )
      v5 = vgui::MessageBox::MessageBox(
             this: v12,
             title: "Add Preset Error",
             text: "Can't add preset with an empty name\n",
             parent: this);
    v5->SetDeleteSelfOnClose(this: v5, a2: true);
    v5->DoModal_2(this: v5, a2: nullptr);
    return;
  }
  if ( CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController) == nullptr )
    return;
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  traversal.m_nIndex = 0;
  v7 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  if ( v7 == nullptr )
  {
LABEL_11:
    CBaseAnimationSetControl::AddPreset(this: this->m_pController, pPresetGroupName, pPresetName: v4, bAnimated);
    return;
  }
  while ( 1 )
  {
    PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v7, pGroupName: pPresetGroupName);
    if ( PresetGroup != nullptr
      && (unsigned int)CBaseAnimationSetControl::GetSelectionState(this: this->m_pController, pAnimSet: v7) >= 2 )
    {
      if ( PresetGroup->m_bIsReadOnly.m_Storage )
      {
        v9 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
        if ( v9 != nullptr )
        {
          v10 = vgui::MessageBox::MessageBox(
                  this: v9,
                  title: "Add Preset Error",
                  text: "Can't add preset to a read-only preset group!\n",
                  parent: this);
          goto LABEL_15;
        }
        goto LABEL_14;
      }
      if ( CDmePresetGroup::FindPreset(this: PresetGroup, pPresetName) != nullptr )
        break;
    }
    v7 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v7 == nullptr )
    {
      v4 = pPresetName;
      goto LABEL_11;
    }
  }
  v11 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
  if ( v11 == nullptr )
  {
LABEL_14:
    v10 = nullptr;
    goto LABEL_15;
  }
  v10 = vgui::MessageBox::MessageBox(
          this: v11,
          title: "Add Preset Error",
          text: "A preset with that name already exists!\n",
          parent: this);
LABEL_15:
  v10->SetDeleteSelfOnClose(this: v10, a2: true);
  v10->DoModal_2(this: v10, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0048F4F0
// Name: public: void CBaseAnimSetPresetFaderPanel::GetPreviewFader(struct FaderPreview_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::GetPreviewFader(
        CBaseAnimSetPresetFaderPanel *this,
        FaderPreview_t *fader)
{
  FaderPreview_t *v2; // esi
  vgui::Panel *v4; // eax
  _DWORD *v5; // edi
  bool v6; // al
  int mx; // [esp+Ch] [ebp-4h] BYREF

  v2 = fader;
  _V_memset(dest: fader, fill: 0, count: 20);
  *(_WORD *)&v2->isbeingdragged = 0;
  v4 = vgui::PHandle::Get(this: &this->m_hActivePresetSlider);
  v5 = &v4->__vftable;
  if ( v4 != nullptr )
  {
    v2->isbeingdragged = HIBYTE(v4[1].__vftable);
    v6 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT);
    v2->holdingPreviewKey = v6;
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: (int *)&fader);
    if ( !vgui::Panel::IsWithin(this, x: mx, y: (int)fader) )
      v2->holdingPreviewKey = false;
    v2->name = (const char *)(*(int (__thiscall **)(_DWORD *))(*v5 + 72))(a1: v5);
    v2->amount = (float)(*(int (__thiscall **)(_DWORD *))(*v5 + 848))(a1: v5) * 0.001;
    v2->values = (CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short> *)(v5 + 117);
    v2->nProceduralType = v5[126];
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048F5D0
// Name: public: void CBaseAnimSetPresetFaderPanel::UpdateProceduralPresetSlider(class CUtlMap<enum DmElementHandle_t,struct AnimationControlAttributes_t,unsigned short> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::UpdateProceduralPresetSlider(
        CBaseAnimSetPresetFaderPanel *this,
        CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short> *values)
{
  vgui::Panel *v3; // eax
  int v4; // eax

  v3 = vgui::PHandle::Get(this: &this->m_hActivePresetSlider);
  if ( v3 != nullptr )
  {
    v4 = *((_DWORD *)&v3[1] + 43);
    if ( v4 > 0 && v4 <= 7 )
      this->m_pController->ProceduralPreset_UpdateCrossfade(this: this->m_pController, a2: values, a3: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048F620
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x0048F630
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048F660
// Name: public: virtual void CMemberFunctor0<class CParallelProcessor<class CPresetSlider __near *,class CFuncJobItemProcessor<class CPresetSlider __near *>,1> __near *,void (CParallelProcessor<class CPresetSlider __near *,class CFuncJobItemProcessor<class CPresetSlider __near *>,1>::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *,void (__thiscall CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *,void (__thiscall CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *))LODWORD(this->m_Proxy.m_pfnProxied))(a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied));
}

//------------------------------------------------------------------------------
// Address: 0x0048F7F0
// Name: void CollectPresetGroupInfo(class CDmeFilmClip __near *,class CUtlVector<struct PresetGroupInfo_t,class CUtlMemory<struct PresetGroupInfo_t,int>> __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollectPresetGroupInfo(
        CDmeFilmClip *pFilmClip,
        CUtlMemory<vgui::PropertySheet::Page_t,int> *presetInfo,
        bool bSkipReadOnly,
        bool bSkipInvisible)
{
  CDmeAnimationSet *j; // eax
  CDmaElementArray<CDmePresetGroup> *v5; // esi
  CDmAttribute *m_pAttribute; // eax
  DmElementArray_t *m_pData; // eax
  int v8; // ecx
  CDmElement *v9; // eax
  CDmElement *v10; // esi
  const char *m_pAsString; // eax
  char v12; // cl
  CDmAttribute *Attribute; // eax
  CDmAttribute *v14; // esi
  CDmaVar<bool> *v15; // eax
  bool m_Storage; // bl
  int m_pMemory; // esi
  int v18; // eax
  PresetGroupInfo_t *v19; // ecx
  int m_nAllocationCount; // eax
  PresetGroupInfo_t *v21; // ecx
  int v22; // eax
  PresetGroupInfo_t *v23; // eax
  bool bGroupReadOnly; // cl
  bool bGroupVisible; // dl
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-20h] BYREF
  PresetGroupInfo_t info; // [esp+14h] [ebp-18h]
  CDmrElementArray<CDmePresetGroup> presetGroups; // [esp+1Ch] [ebp-10h] BYREF
  int i; // [esp+24h] [ebp-8h]
  CUtlSymbolLarge::<unnamed_type_u> v30; // [esp+28h] [ebp-4h] BYREF
  CDmeFilmClip *pFilmClipa; // [esp+34h] [ebp+8h]

  traversal.m_pFilmClip = pFilmClip;
  traversal.m_nIndex = 0;
  for ( j = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        j != nullptr;
        j = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
  {
    v5 = CDmeAnimationSet::GetPresetGroups(this: j);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroups);
    m_pAttribute = v5->m_pAttribute;
    if ( m_pAttribute != nullptr && (m_pAttribute->m_nFlags & 0x1F) == 0xF )
    {
      presetGroups.m_pAttribute = v5->m_pAttribute;
      m_pData = (DmElementArray_t *)m_pAttribute->m_pData;
      presetGroups.m_pStorage = m_pData;
      pFilmClipa = (CDmeFilmClip *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      presetGroups.m_pAttribute = nullptr;
      presetGroups.m_pStorage = nullptr;
      pFilmClipa = nullptr;
    }
    v8 = 0;
    i = 0;
    if ( (int)pFilmClipa > 0 )
    {
      while ( 1 )
      {
        v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v8]);
        v10 = v9;
        if ( v9 != nullptr
          && v9->IsA(this: v9, a2: CDmePresetGroup::m_classType)
          && (!bSkipReadOnly || v10[1].m_Id.m_Value[4] == 0)
          && (!bSkipInvisible || LOBYTE(v10[1].__vftable) != 0) )
        {
          m_pAsString = v10->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = defaultValue;
          g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&v30, a3: m_pAsString);
          v12 = (char)v10[1].__vftable;
          info.bGroupReadOnly = v10[1].m_Id.m_Value[4];
          info.bGroupVisible = v12;
          if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
            `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
          }
          Attribute = CDmElement::FindAttribute(this: v10, pAttributeName: "shared");
          v14 = Attribute;
          if ( Attribute != nullptr )
          {
            if ( (`CDmAttribute::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
            {
              `CDmAttribute::GetValue<bool>'::`2'::`local static guard' |= 1u;
              `CDmAttribute::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
              `CDmAttribute::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
            }
            if ( (Attribute->m_nFlags & 0x1F) == 4 )
            {
              v15 = (CDmaVar<bool> *)Attribute->m_pData;
            }
            else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
            {
              CDmAttribute::CopyDataOut<bool>(this: v14, value: &`CDmAttribute::GetValue<bool>'::`7'::tempVal);
              v15 = (CDmaVar<bool> *)&`CDmAttribute::GetValue<bool>'::`7'::tempVal;
            }
            else
            {
              v15 = &`CDmAttribute::GetValue<bool>'::`2'::defaultVal;
            }
          }
          else
          {
            v15 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
          }
          m_Storage = v15->m_Storage;
          m_pMemory = (int)presetInfo[1].m_pMemory;
          v18 = 0;
          if ( m_pMemory <= 0 )
            goto LABEL_34;
          v19 = (PresetGroupInfo_t *)presetInfo->m_pMemory;
          while ( v19->presetGroupSym.u.m_Id != v30.m_Id )
          {
            ++v18;
            ++v19;
            if ( v18 >= m_pMemory )
              goto LABEL_34;
          }
          if ( v18 == -1 )
          {
LABEL_34:
            m_nAllocationCount = presetInfo->m_nAllocationCount;
            if ( m_pMemory + 1 > m_nAllocationCount )
              CUtlMemory<MDLSquenceLayer_t,int>::Grow(this: presetInfo, num: m_pMemory - m_nAllocationCount + 1);
            ++presetInfo[1].m_pMemory;
            v21 = (PresetGroupInfo_t *)presetInfo->m_pMemory;
            v22 = (int)presetInfo[1].m_pMemory - m_pMemory - 1;
            presetInfo[1].m_nAllocationCount = (int)presetInfo->m_pMemory;
            if ( v22 > 0 )
              _V_memmove(dest: &v21[m_pMemory + 1], src: &v21[m_pMemory], count: 8 * v22);
            v23 = (PresetGroupInfo_t *)&presetInfo->m_pMemory[m_pMemory];
            if ( v23 != nullptr )
            {
              bGroupReadOnly = info.bGroupReadOnly;
              v23->presetGroupSym.u = v30;
              bGroupVisible = info.bGroupVisible;
              v23->bGroupShared = m_Storage;
              v23->bGroupReadOnly = bGroupReadOnly;
              v23->bGroupVisible = bGroupVisible;
            }
          }
        }
        v8 = i + 1;
        i = v8;
        if ( v8 >= (int)pFilmClipa )
          break;
        m_pData = presetGroups.m_pStorage;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048FA20
// Name: void CollectProceduralPresetNames(class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollectProceduralPresetNames(CUtlMemory<vgui::TreeNode *,int> *presetNames)
{
  int m_pMemory; // esi
  int m_nAllocationCount; // ecx
  CUtlSymbolLarge *v4; // ecx
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  int i; // edx
  _DWORD *v9; // eax
  int v10; // ebx
  const char *v11; // eax
  _DWORD *v12; // esi
  _BYTE v13[4]; // [esp+0h] [ebp-4h] BYREF
  CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > *presetNamesa; // [esp+Ch] [ebp+8h]

  if ( (`CollectProceduralPresetNames'::`2'::`local static guard' & 1) == 0 )
  {
    `CollectProceduralPresetNames'::`2'::`local static guard' |= 1u;
    g_pDataModel->GetSymbol(
      this: g_pDataModel,
      result: &`CollectProceduralPresetNames'::`2'::proceduralPresetGroupNameSymbol,
      a3: "Procedural");
  }
  m_pMemory = (int)presetNames[1].m_pMemory;
  m_nAllocationCount = presetNames->m_nAllocationCount;
  if ( m_pMemory + 20 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: presetNames, num: m_pMemory - m_nAllocationCount + 20);
  presetNames[1].m_pMemory += 5;
  v4 = (CUtlSymbolLarge *)presetNames->m_pMemory;
  v5 = (int)presetNames[1].m_pMemory - m_pMemory - 20;
  presetNames[1].m_nAllocationCount = (int)presetNames->m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &v4[m_pMemory + 20], src: &v4[m_pMemory], count: 4 * v5);
  v6 = 4 * m_pMemory;
  v7 = v6;
  for ( i = 20; i != 0; --i )
  {
    v9 = (vgui::TreeNode **)((char *)presetNames->m_pMemory + v7);
    if ( v9 != nullptr )
      *v9 = -1;
    v7 += 4;
  }
  v10 = 1;
  presetNamesa = (CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > *)v6;
  do
  {
    if ( (unsigned int)v10 > 0x14 )
      v11 = "???";
    else
      v11 = g_ProceduralPresetNames_14[v10];
    v12 = (CUtlSymbolLarge **)((char *)&presetNamesa->m_Memory.m_pMemory + (unsigned int)presetNames->m_pMemory);
    presetNamesa = (CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > *)((char *)presetNamesa + 4);
    ++v10;
    *v12 = *(_DWORD *)((int (__stdcall *)(_BYTE *, const char *))g_pDataModel->GetSymbol)(a1: v13, a2: v11);
  }
  while ( v10 < 21 );
}

//------------------------------------------------------------------------------
// Address: 0x0048FB20
// Name: void CollectPresetNamesForGroup(class CDmeFilmClip __near *,char const __near *,class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollectPresetNamesForGroup(
        CDmeFilmClip *pFilmClip,
        const char *pPresetGroupName,
        CUtlMemory<vgui::TreeNode *,int> *presetNames)
{
  int v3; // ebx
  CDmeAnimationSet *i; // eax
  CDmeTransformControl *PresetGroup; // eax
  const Vector *Position; // edi
  float x; // eax
  DmElementArray_t *m_pStorage; // eax
  CDmElement *v9; // eax
  CDmElement *v10; // edi
  const char *m_pAsString; // eax
  int m_pMemory; // edi
  int v13; // eax
  CUtlSymbolLarge *v14; // ecx
  int m_nAllocationCount; // eax
  CUtlSymbolLarge *v16; // ecx
  int v17; // eax
  CUtlSymbolLarge *v18; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-14h] BYREF
  CDmrElementArray<CDmePreset> presets; // [esp+14h] [ebp-Ch] BYREF
  CUtlSymbolLarge symPresetName; // [esp+1Ch] [ebp-4h] BYREF
  CDmeFilmClip *pFilmClipa; // [esp+28h] [ebp+8h]

  v3 = 0;
  traversal.m_pFilmClip = pFilmClip;
  traversal.m_nIndex = 0;
  for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal); i != nullptr; v3 = 0 )
  {
    PresetGroup = (CDmeTransformControl *)CDmeAnimationSet::FindPresetGroup(this: i, pGroupName: pPresetGroupName);
    if ( PresetGroup != nullptr )
    {
      Position = CDmeTransformControl::GetPosition(this: PresetGroup);
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
      x = Position[2].x;
      if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
      {
        m_pStorage = nullptr;
        presets.m_pAttribute = nullptr;
        presets.m_pStorage = nullptr;
        pFilmClipa = nullptr;
      }
      else
      {
        presets.m_pAttribute = (CDmAttribute *)LODWORD(Position[2].x);
        m_pStorage = *(DmElementArray_t **)(LODWORD(x) + 4);
        presets.m_pStorage = m_pStorage;
        pFilmClipa = (CDmeFilmClip *)m_pStorage->m_Size;
      }
      if ( (int)pFilmClipa > 0 )
      {
        while ( 1 )
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[v3]);
          v10 = v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmePreset::m_classType) )
          {
            m_pAsString = v10->m_Name.m_Storage.u.m_pAsString;
            if ( m_pAsString == (const char *)-1 )
              m_pAsString = defaultValue;
            g_pDataModel->GetSymbol(this: g_pDataModel, result: &symPresetName, a3: m_pAsString);
            m_pMemory = (int)presetNames[1].m_pMemory;
            v13 = 0;
            if ( m_pMemory <= 0 )
              goto LABEL_20;
            v14 = (CUtlSymbolLarge *)presetNames->m_pMemory;
            while ( v14->u.m_Id != symPresetName.u.m_Id )
            {
              ++v13;
              ++v14;
              if ( v13 >= m_pMemory )
                goto LABEL_20;
            }
            if ( v13 == -1 )
            {
LABEL_20:
              m_nAllocationCount = presetNames->m_nAllocationCount;
              if ( m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: presetNames, num: m_pMemory - m_nAllocationCount + 1);
              ++presetNames[1].m_pMemory;
              v16 = (CUtlSymbolLarge *)presetNames->m_pMemory;
              v17 = (int)presetNames[1].m_pMemory - m_pMemory - 1;
              presetNames[1].m_nAllocationCount = (int)presetNames->m_pMemory;
              if ( v17 > 0 )
                _V_memmove(dest: &v16[m_pMemory + 1], src: &v16[m_pMemory], count: 4 * v17);
              v18 = (CUtlSymbolLarge *)&presetNames->m_pMemory[m_pMemory];
              if ( v18 != nullptr )
                v18->u.m_Id = symPresetName.u.m_Id;
            }
          }
          if ( ++v3 >= (int)pFilmClipa )
            break;
          m_pStorage = presets.m_pStorage;
        }
      }
    }
    i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048FCA0
// Name: public: static void CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnShowAddPresetDialog::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnShowAddPresetDialog::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnShowAddPresetDialog::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnShowAddPresetDialog::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ShowAddPresetDialog";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048FD30
// Name: public: static void CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetsChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetsChanged::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetsChanged::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetsChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PresetsChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048FDC0
// Name: public: static void CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnManagePresets::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnManagePresets::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnManagePresets::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnManagePresets::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ManagePresets";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048FE50
// Name: public: static void CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetNameSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetNameSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetNameSelected::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetNameSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PresetNameSelected";
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
// Address: 0x0048FEE0
// Name: public: static void CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPageChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPageChanged::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
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
// Address: 0x0048FF70
// Name: public: static void CPresetSlider::KB_AddToMap(char const __near *,enum ButtonCode_t,int,void (vgui::Panel::*)(void),char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPresetSlider::KB_AddToMap(
        const char *a1@<ebp>,
        const char *bindingname,
        ButtonCode_t defaultcode,
        int default_modifiers,
        __int128 function,
        __int64 helpstring,
        bool passive)
{
  vgui::PanelKeyBindingMap *v7; // esi
  _DWORD v8[3]; // [esp-Ch] [ebp-4Ch] BYREF
  vgui::KeyBindingMap_t entry; // [esp+0h] [ebp-40h] BYREF
  vgui::BoundKey_t kb; // [esp+30h] [ebp-10h]
  int retaddr; // [esp+40h] [ebp+0h]

  kb.bindingname = a1;
  kb.keycode = retaddr;
  v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetSlider");
  vgui::KeyBindingMap_t::KeyBindingMap_t(this: (vgui::KeyBindingMap_t *)v8);
  *(_OWORD *)(&entry.bindingname + 1) = function;
  *(_QWORD *)((char *)&entry.func + 4) = helpstring;
  v8[0] = bindingname;
  BYTE12(entry.func) = passive;
  CUtlVector<vgui::KeyBindingMap_t,CUtlMemory<vgui::KeyBindingMap_t,int>>::InsertBefore(
    this: &v7->entries,
    elem: v7->entries.m_Size,
    src: (const vgui::KeyBindingMap_t *)v8);
  vgui::BoundKey_t::BoundKey_t(this: (vgui::BoundKey_t *)&entry.docstring);
  *((_DWORD *)&entry.passive + 1) = defaultcode;
  LOBYTE(entry.docstring) = 1;
  *(_DWORD *)&entry.passive = bindingname;
  *(_DWORD *)&kb.isbuiltin = default_modifiers;
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
    this: &v7->defaultkeys,
    elem: v7->defaultkeys.m_Size,
    src: (const vgui::BoundKey_t *)&entry.docstring);
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
    this: &v7->boundkeys,
    elem: v7->boundkeys.m_Size,
    src: (const vgui::BoundKey_t *)&entry.docstring);
  vgui::BoundKey_t::~BoundKey_t(this: (vgui::BoundKey_t *)&entry.docstring);
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)v8);
}

//------------------------------------------------------------------------------
// Address: 0x00490040
// Name: public: static void CPresetSlider::PanelMessageFunc_OnShowContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPresetSlider::PanelMessageFunc_OnShowContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CPresetSlider::PanelMessageFunc_OnShowContextMenu::InitVar'::`2'::bAdded )
  {
    `CPresetSlider::PanelMessageFunc_OnShowContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnShowContextMenu";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004900D0
// Name: public: static void CPresetSlider::PanelMessageFunc_OnRename::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPresetSlider::PanelMessageFunc_OnRename::InitVar(int a1@<ebp>)
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
  if ( !`CPresetSlider::PanelMessageFunc_OnRename::InitVar'::`2'::bAdded )
  {
    `CPresetSlider::PanelMessageFunc_OnRename::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnRename";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490160
// Name: public: static void CPresetSlider::PanelMessageFunc_OnDelete::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPresetSlider::PanelMessageFunc_OnDelete::InitVar(int a1@<ebp>)
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
  if ( !`CPresetSlider::PanelMessageFunc_OnDelete::InitVar'::`2'::bAdded )
  {
    `CPresetSlider::PanelMessageFunc_OnDelete::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{400,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnDelete";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004901F0
// Name: public: static void CPresetSlider::PanelMessageFunc_OnInputCompleted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPresetSlider::PanelMessageFunc_OnInputCompleted::InitVar(int a1@<ebp>)
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
  if ( !`CPresetSlider::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded )
  {
    `CPresetSlider::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
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
// Address: 0x00490280
// Name: public: static void CPresetSlider::PanelMessageFunc_OnDeleteConfirmed::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPresetSlider::PanelMessageFunc_OnDeleteConfirmed::InitVar(int a1@<ebp>)
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
  if ( !`CPresetSlider::PanelMessageFunc_OnDeleteConfirmed::InitVar'::`2'::bAdded )
  {
    `CPresetSlider::PanelMessageFunc_OnDeleteConfirmed::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnDeleteConfirmed";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490310
// Name: public: void CAddPresetDialog::DoModal(class CDmeFilmClip __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAddPresetDialog::DoModal(
        CAddPresetDialog *this,
        CDmeFilmClip *pFilmClip,
        const char *pCurrentGroupName,
        KeyValues *pContextKeyValues)
{
  KeyValues *v5; // esi
  const char *m_pAsString; // edi
  KeyValues *v7; // eax
  int v8; // esi
  CUtlVector<PresetGroupInfo_t,CUtlMemory<PresetGroupInfo_t,int> > presetGroupInfo; // [esp+8h] [ebp-14h] BYREF
  int i; // [esp+24h] [ebp+8h]

  vgui::ComboBox::RemoveAll(this: this->m_pPresetGroup);
  v5 = nullptr;
  memset(&presetGroupInfo, 0, sizeof(presetGroupInfo));
  CollectPresetGroupInfo(
    pFilmClip,
    presetInfo: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&presetGroupInfo,
    bSkipReadOnly: true,
    bSkipInvisible: false);
  for ( i = 0; i < presetGroupInfo.m_Size; ++i )
  {
    m_pAsString = presetGroupInfo.m_Memory.m_pMemory[i].presetGroupSym.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v5 = KeyValues::KeyValues(this: v7, setName: "entry");
    KeyValues::SetString(this: v5, keyName: "presetGroupName", value: m_pAsString);
    v8 = this->m_pPresetGroup->AddItem_2(this: this->m_pPresetGroup, a2: m_pAsString, a3: v5);
    if ( pCurrentGroupName != nullptr && _V_stricmp(s1: m_pAsString, s2: pCurrentGroupName) == 0 )
      this->m_pPresetGroup->ActivateItem(this: this->m_pPresetGroup, a2: v8);
    v5 = nullptr;
  }
  vgui::BaseInputDialog::DoModal(this, pContextKeyValues);
  this->m_pPresetName->SetText(this: this->m_pPresetName, a2: defaultValue);
  this->m_pPresetName->RequestFocus(this: this->m_pPresetName, a2: 0);
  vgui::Frame::PlaceUnderCursor(this);
  if ( presetGroupInfo.m_Memory.m_nGrowSize >= 0 && presetGroupInfo.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: presetGroupInfo.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00490440
// Name: public: virtual struct vgui::PanelMessageMap __near * CPresetSlider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPresetSlider::GetMessageMap(CPresetSlider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPresetSlider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPresetSlider::GetMessageMap'::`2'::s_pMap;
  `CPresetSlider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
  `CPresetSlider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00490470
// Name: public: virtual struct PanelAnimationMap __near * CPresetSlider::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPresetSlider::GetAnimMap(CPresetSlider *this)
{
  return FindOrAddPanelAnimationMap(className: "CPresetSlider");
}

//------------------------------------------------------------------------------
// Address: 0x00490480
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPresetSlider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPresetSlider::GetKBMap(CPresetSlider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPresetSlider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPresetSlider::GetKBMap'::`2'::s_pMap;
  `CPresetSlider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetSlider");
  `CPresetSlider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004904B0
// Name: public: static void CSliderListPanel::PanelMessageFunc_OnShowContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSliderListPanel::PanelMessageFunc_OnShowContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CSliderListPanel::PanelMessageFunc_OnShowContextMenu::InitVar'::`2'::bAdded )
  {
    `CSliderListPanel::PanelMessageFunc_OnShowContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::RichText::`vcall'{872,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSliderListPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnShowContextMenu";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490540
// Name: public: CSliderListPanel::CSliderListPanel(class CBaseAnimSetPresetFaderPanel __near *,class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSliderListPanel *__thiscall CSliderListPanel::CSliderListPanel(
        CSliderListPanel *this,
        CBaseAnimSetPresetFaderPanel *pFader,
        vgui::Panel *pParent,
        const char *panelName)
{
  vgui::PanelMessageMap *v5; // esi
  PanelAnimationMap *v6; // esi
  vgui::PanelKeyBindingMap *v7; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::PanelListPanel::PanelListPanel(this, parent: pParent, panelName);
  this->__vftable = (CSliderListPanel_vtbl *)&CSliderListPanel::`vftable';
  if ( `CSliderListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CSliderListPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CSliderListPanel");
    v5->pfnClassName = CSliderListPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PanelListPanel");
  }
  if ( `CSliderListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSliderListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CSliderListPanel");
    v6->pfnClassName = CSliderListPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PanelListPanel");
  }
  if ( `CSliderListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSliderListPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CSliderListPanel");
    v7->pfnClassName = CSliderListPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PanelListPanel");
  }
  CSliderListPanel::PanelMessageFunc_OnShowContextMenu::InitVar(a1: (int)&savedregs);
  this->m_hContextMenu.m_iPanelID = -1;
  this->m_pPresetFaderPanel = pFader;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00490620
// Name: public: virtual struct vgui::PanelMessageMap __near * CSliderListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSliderListPanel::GetMessageMap(CSliderListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSliderListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSliderListPanel::GetMessageMap'::`2'::s_pMap;
  `CSliderListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSliderListPanel");
  `CSliderListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00490650
// Name: public: virtual struct PanelAnimationMap __near * CSliderListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSliderListPanel::GetAnimMap(CSliderListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CSliderListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00490660
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSliderListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSliderListPanel::GetKBMap(CSliderListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSliderListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSliderListPanel::GetKBMap'::`2'::s_pMap;
  `CSliderListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSliderListPanel");
  `CSliderListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00490690
// Name: protected: virtual void CBaseAnimSetPresetFaderPanel::OnShowAddPresetDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::OnShowAddPresetDialog(CBaseAnimSetPresetFaderPanel *this)
{
  CAddPresetDialog *v2; // eax
  CAddPresetDialog *v3; // edi
  vgui::Panel *v4; // eax
  const char *v5; // eax
  CDmeFilmClip *AnimationSetClip; // eax
  const char *v7; // [esp-Ch] [ebp-10h]

  if ( CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController) != nullptr )
  {
    v2 = (CAddPresetDialog *)MemAlloc_Alloc(nSize: 0x230u);
    if ( v2 != nullptr )
      v3 = CAddPresetDialog::CAddPresetDialog(this: v2, parent: this);
    else
      v3 = nullptr;
    v3->AddActionSignalTarget_2(this: v3, a2: this);
    if ( this->m_pSheet->GetActivePage(this: this->m_pSheet) != nullptr )
    {
      v4 = this->m_pSheet->GetActivePage(this: this->m_pSheet);
      v5 = v4->GetName(this: v4);
    }
    else
    {
      v5 = defaultValue;
    }
    v7 = v5;
    AnimationSetClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
    CAddPresetDialog::DoModal(this: v3, pFilmClip: AnimationSetClip, pCurrentGroupName: v7, pContextKeyValues: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490720
// Name: public: void CParallelProcessor<class CPresetSlider __near *,class CFuncJobItemProcessor<class CPresetSlider __near *>,1>::Run(class CPresetSlider __near * __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::Run(
        CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *this,
        CPresetSlider **pItems,
        int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  IThreadPool *v7; // esi
  int v8; // eax
  int v9; // edi
  int v10; // eax
  void *v11; // esp
  CFunctor *v12; // eax
  CFunctor v13; // xmm0_8
  CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *v14; // ecx
  int i; // esi
  _DWORD v16[3]; // [esp+0h] [ebp-20h]
  CFunctor v17; // [esp+Ch] [ebp-14h]
  CFunctor v18; // [esp+14h] [ebp-Ch]
  CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *v19; // [esp+1Ch] [ebp-4h]
  int nJobs; // [esp+2Ch] [ebp+Ch]

  v19 = this;
  if ( nItems != 0 )
  {
    v7 = pThreadPool;
    this->m_nChunkSize = nChunkSize;
    if ( v7 == nullptr )
      v7 = _g_pThreadPool;
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v8 = nMaxParallel;
    v9 = nItems - 1;
    this->m_pLimit = &pItems[nItems];
    nJobs = v9;
    if ( v9 > v8 )
    {
      nJobs = v8;
      v9 = v8;
    }
    if ( v7 == nullptr )
      goto LABEL_18;
    v10 = v7->NumThreads(this: v7);
    if ( v9 > v10 )
    {
      nJobs = v10;
      v9 = v10;
    }
    if ( v9 > 0 )
    {
      v11 = alloca(4 * v9);
      v17.__vftable = (CFunctor_vtbl *)CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::DoExecute;
      v17.m_nUserID = 0;
      v18 = 0;
      do
      {
        --v9;
        v12 = (CFunctor *)MemAlloc_Alloc(nSize: 0x28u);
        if ( v12 != nullptr )
        {
          v13 = v17;
          v14 = v19;
          v12[1].m_nUserID = 1;
          v12->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *,void (__thiscall CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v12[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *,void (__thiscall CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v12[2] = v13;
          v12[3] = v18;
          v12[4].__vftable = (CFunctor_vtbl *)v14;
        }
        else
        {
          v12 = nullptr;
        }
        v7->AddFunctorInternal(this: v7, a2: v12, a3: (CJob **)&nChunkSize, a4: nullptr, a5: 8u);
        v16[v9] = nChunkSize;
      }
      while ( v9 != 0 );
      CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::DoExecute(this: v19);
      for ( i = 0; i < nJobs; ++i )
      {
        CJob::Abort(this: (CJob *)v16[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v16[i] + 4))(a1: v16[i]);
      }
    }
    else
    {
LABEL_18:
      CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::DoExecute(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00490860
// Name: public: CPresetSlider::CPresetSlider(class vgui::Panel __near *,class CBaseAnimSetPresetFaderPanel __near *)
// Source: json
//------------------------------------------------------------------------------
CPresetSlider *__thiscall CPresetSlider::CPresetSlider(
        CPresetSlider *this,
        vgui::Panel *parent,
        CBaseAnimSetPresetFaderPanel *pFaderPanel)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax
  __int128 v11; // [esp-1Ch] [ebp-38h]
  __int128 v12; // [esp-1Ch] [ebp-38h]
  __int128 v13; // [esp-1Ch] [ebp-38h]
  __int128 v14; // [esp-1Ch] [ebp-38h]
  __int64 v15; // [esp+14h] [ebp-8h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  vgui::Slider::Slider(this, parent, panelName: "preset");
  this->__vftable = (CPresetSlider_vtbl *)&CPresetSlider::`vftable';
  if ( `CPresetSlider::ChainToMap'::`2'::chained == 0 )
  {
    `CPresetSlider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
    v4->pfnClassName = CPresetSlider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Slider");
  }
  if ( `CPresetSlider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPresetSlider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CPresetSlider");
    v5->pfnClassName = CPresetSlider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Slider");
  }
  if ( `CPresetSlider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPresetSlider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetSlider");
    v6->pfnClassName = CPresetSlider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Slider");
  }
  CPresetSlider::PanelMessageFunc_OnShowContextMenu::InitVar(a1: (int)&savedregs);
  CPresetSlider::PanelMessageFunc_OnRename::InitVar(a1: (int)&savedregs);
  CPresetSlider::PanelMessageFunc_OnDelete::InitVar(a1: (int)&savedregs);
  CPresetSlider::PanelMessageFunc_OnInputCompleted::InitVar(a1: (int)&savedregs);
  CPresetSlider::PanelMessageFunc_OnDeleteConfirmed::InitVar(a1: (int)&savedregs);
  if ( `CPresetSlider::PanelKBMapFunc_ts_curve_1::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v11 = (unsigned int) __thiscall CDmePanel::`vcall'{960,{flat}};
    v15 = 0;
    `CPresetSlider::PanelKBMapFunc_ts_curve_1::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v11 + 1) = 0;
    CPresetSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_1",
      defaultcode: KEY_1,
      default_modifiers: 0,
      function: v11,
      helpstring: (unsigned int)"#ts_curve1_help",
      passive: false);
  }
  if ( `CPresetSlider::PanelKBMapFunc_ts_curve_2::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v12 = (unsigned int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    v15 = 0;
    `CPresetSlider::PanelKBMapFunc_ts_curve_2::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v12 + 1) = 0;
    CPresetSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_2",
      defaultcode: KEY_2,
      default_modifiers: 0,
      function: v12,
      helpstring: (unsigned int)"#ts_curve2_help",
      passive: false);
  }
  if ( `CPresetSlider::PanelKBMapFunc_ts_curve_3::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v13 = (unsigned int) __thiscall CAttributeSlider::`vcall'{968,{flat}};
    v15 = 0;
    `CPresetSlider::PanelKBMapFunc_ts_curve_3::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v13 + 1) = 0;
    CPresetSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_3",
      defaultcode: KEY_3,
      default_modifiers: 0,
      function: v13,
      helpstring: (unsigned int)"#ts_curve3_help",
      passive: false);
  }
  if ( `CPresetSlider::PanelKBMapFunc_ts_curve_4::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v14 = (unsigned int) __thiscall CDmePresetGroupEditorPanel::`vcall'{972,{flat}};
    v15 = 0;
    `CPresetSlider::PanelKBMapFunc_ts_curve_4::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v14 + 1) = 0;
    CPresetSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_4",
      defaultcode: KEY_4,
      default_modifiers: 0,
      function: v14,
      helpstring: (unsigned int)"#ts_curve4_help",
      passive: false);
  }
  this->m_pPresetFaderPanel = pFaderPanel;
  this->m_GradientColor = 0;
  this->m_ZeroColor = 0;
  this->m_TextColor = 0;
  this->m_TextColorFocus = 0;
  this->m_hContextMenu.m_iPanelID = -1;
  this->m_AttributeLookup.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const DmElementHandle_t *, const DmElementHandle_t *))CDefOps<DmeTime_t>::LessFunc;
  this->m_AttributeLookup.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_AttributeLookup.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_AttributeLookup.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_AttributeLookup.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_AttributeLookup.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_AttributeLookup.m_Tree.m_FirstFree = -1;
  this->m_AttributeLookup.m_Tree.m_pElements = m_pMemory;
  this->m_presetGroupName.u.m_Id = -1;
  this->m_presetName.u.m_Id = -1;
  this->m_nProceduralType = 0;
  *(_WORD *)&this->m_bReadOnly = 0;
  vgui::Slider::SetRange(this, min: 0, max: 1000);
  vgui::Slider::SetDragOnRepositionNob(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
  if ( v8 != nullptr )
    v9 = vgui::TextImage::TextImage(this: v8, text: defaultValue);
  else
    v9 = nullptr;
  this->m_pName = v9;
  this->m_ZeroColor = (Color)-12237499;
  this->m_GradientColor = (Color)-16746302;
  this->m_TextColor = (Color)-3618616;
  this->m_TextColorFocus = (Color)-14118960;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00490BD0
// Name: public: CBaseAnimSetPresetFaderPanel::CBaseAnimSetPresetFaderPanel(class vgui::Panel __near *,char const __near *,class CBaseAnimationSetEditor __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimSetPresetFaderPanel *__thiscall CBaseAnimSetPresetFaderPanel::CBaseAnimSetPresetFaderPanel(
        CBaseAnimSetPresetFaderPanel *this,
        vgui::Panel *parent,
        const char *className,
        CBaseAnimationSetEditor *editor)
{
  vgui::PanelMessageMap *v5; // esi
  PanelAnimationMap *v6; // esi
  vgui::PanelKeyBindingMap *v7; // esi
  vgui::PropertySheet *v8; // eax
  vgui::PropertySheet *v9; // eax
  CSliderListPanel *v10; // eax
  CSliderListPanel *v11; // eax
  CPresetSlider **m_pMemory; // eax
  IMemAlloc_vtbl *v13; // edx
  CPresetSlider **v14; // eax
  CPresetSlider *v15; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CPresetSlider **v18; // ecx
  int v19; // eax
  CPresetSlider **v20; // ebx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  int parenta; // [esp+14h] [ebp+8h]
  const char *classNamea; // [esp+18h] [ebp+Ch]

  vgui::EditablePanel::EditablePanel(this, parent, panelName: className);
  this->__vftable = (CBaseAnimSetPresetFaderPanel_vtbl *)&CBaseAnimSetPresetFaderPanel::`vftable';
  if ( `CBaseAnimSetPresetFaderPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetPresetFaderPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
    v5->pfnClassName = CBaseAnimSetPresetFaderPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAnimSetPresetFaderPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetPresetFaderPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CBaseAnimSetPresetFaderPanel");
    v6->pfnClassName = CBaseAnimSetPresetFaderPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAnimSetPresetFaderPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetPresetFaderPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimSetPresetFaderPanel");
    v7->pfnClassName = CBaseAnimSetPresetFaderPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnShowAddPresetDialog::InitVar(a1: (int)&savedregs);
  CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetsChanged::InitVar(a1: (int)&savedregs);
  CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnManagePresets::InitVar(a1: (int)&savedregs);
  CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetNameSelected::InitVar(a1: (int)&savedregs);
  CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPageChanged::InitVar(a1: (int)&savedregs);
  this->m_presetGroupPages.m_Memory.m_pMemory = nullptr;
  this->m_presetGroupPages.m_Memory.m_nAllocationCount = 0;
  this->m_presetGroupPages.m_Memory.m_nGrowSize = 0;
  this->m_presetGroupPages.m_Size = 0;
  this->m_presetGroupPages.m_pElements = nullptr;
  this->m_presetSliders.m_Memory.m_pMemory = nullptr;
  this->m_presetSliders.m_Memory.m_nAllocationCount = 0;
  this->m_presetSliders.m_Memory.m_nGrowSize = 0;
  this->m_presetSliders.m_Size = 0;
  this->m_presetSliders.m_pElements = nullptr;
  this->m_hPresetEditor.m_iPanelID = -1;
  this->m_hActivePresetSlider.m_iPanelID = -1;
  this->m_pController = CBaseAnimationSetEditor::GetController(this: editor);
  v8 = (vgui::PropertySheet *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v8 != nullptr )
    v9 = vgui::PropertySheet::PropertySheet(
           this: v8,
           parent: this,
           panelName: "presetPropertySheet",
           draggableTabs: false);
  else
    v9 = nullptr;
  this->m_pSheet = v9;
  vgui::Panel::SetAutoResize(
    this: v9,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  this->m_pSheet->SetSmallTabs(this: this->m_pSheet, a2: true);
  v10 = (CSliderListPanel *)MemAlloc_Alloc(nSize: 0x1B8u);
  if ( v10 != nullptr )
    v11 = CSliderListPanel::CSliderListPanel(this: v10, pFader: this, pParent: nullptr, panelName: "PresetSliders");
  else
    v11 = nullptr;
  this->m_pSliders = v11;
  vgui::PanelListPanel::SetFirstColumnWidth(this: v11, width: 0);
  vgui::Panel::SetAutoResize(
    this: this->m_pSliders,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  vgui::Panel::SetPos(this: this->m_pSliders, x: 0, y: 0);
  vgui::PanelListPanel::SetVerticalBufferPixels(this: this->m_pSliders, buffer: 0);
  if ( this->m_presetSliders.m_Memory.m_nAllocationCount < 400 && this->m_presetSliders.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_presetSliders.m_Memory.m_nAllocationCount = 400;
    m_pMemory = this->m_presetSliders.m_Memory.m_pMemory;
    v13 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v14 = (CPresetSlider **)((int (__stdcall *)(CPresetSlider **, int))v13->Realloc_2)(a1: m_pMemory, a2: 1600);
    else
      v14 = (CPresetSlider **)((int (__stdcall *)(int))v13->Alloc_2)(a1: 1600);
    this->m_presetSliders.m_Memory.m_pMemory = v14;
  }
  this->m_presetSliders.m_pElements = this->m_presetSliders.m_Memory.m_pMemory;
  for ( parenta = 400; parenta != 0; --parenta )
  {
    v15 = (CPresetSlider *)MemAlloc_Alloc(nSize: 0x200u);
    if ( v15 != nullptr )
      classNamea = (const char *)CPresetSlider::CPresetSlider(this: v15, parent: nullptr, pFaderPanel: this);
    else
      classNamea = nullptr;
    m_Size = this->m_presetSliders.m_Size;
    m_nAllocationCount = this->m_presetSliders.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_presetSliders,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_presetSliders.m_Size;
    v18 = this->m_presetSliders.m_Memory.m_pMemory;
    v19 = this->m_presetSliders.m_Size - m_Size - 1;
    this->m_presetSliders.m_pElements = v18;
    if ( v19 > 0 )
      _V_memmove(dest: &v18[m_Size + 1], src: &v18[m_Size], count: 4 * v19);
    v20 = &this->m_presetSliders.m_Memory.m_pMemory[m_Size];
    if ( v20 != nullptr )
      *v20 = (CPresetSlider *)classNamea;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00490EA0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAnimSetPresetFaderPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAnimSetPresetFaderPanel::GetMessageMap(CBaseAnimSetPresetFaderPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAnimSetPresetFaderPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimSetPresetFaderPanel::GetMessageMap'::`2'::s_pMap;
  `CBaseAnimSetPresetFaderPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
  `CBaseAnimSetPresetFaderPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00490ED0
// Name: public: virtual struct PanelAnimationMap __near * CBaseAnimSetPresetFaderPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAnimSetPresetFaderPanel::GetAnimMap(CBaseAnimSetPresetFaderPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAnimSetPresetFaderPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00490EE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAnimSetPresetFaderPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAnimSetPresetFaderPanel::GetKBMap(CBaseAnimSetPresetFaderPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAnimSetPresetFaderPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimSetPresetFaderPanel::GetKBMap'::`2'::s_pMap;
  `CBaseAnimSetPresetFaderPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimSetPresetFaderPanel");
  `CBaseAnimSetPresetFaderPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00490F50
// Name: protected: void CBaseAnimSetPresetFaderPanel::UpdateOrCreatePresetSlider(int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::UpdateOrCreatePresetSlider(
        CBaseAnimSetPresetFaderPanel *this,
        int nSlot,
        const char *pPresetGroupName,
        const char *pPresetName)
{
  CPresetSlider *v5; // eax
  CPresetSlider *v6; // esi
  CSliderListPanel *m_pSliders; // ecx
  CSliderListPanel_vtbl *v8; // esi
  int ItemIDFromRow; // eax
  int v10; // eax

  if ( pPresetName != nullptr )
  {
    if ( nSlot < vgui::PanelListPanel::GetItemCount(this: (vgui::TextEntry *)this->m_pSliders) )
    {
      m_pSliders = this->m_pSliders;
      v8 = m_pSliders->__vftable;
      ItemIDFromRow = vgui::PanelListPanel::GetItemIDFromRow(this: m_pSliders, nRow: nSlot);
      v6 = (CPresetSlider *)v8->GetItemPanel(this: this->m_pSliders, a2: ItemIDFromRow);
    }
    else
    {
      v5 = (CPresetSlider *)MemAlloc_Alloc(nSize: 0x200u);
      if ( v5 != nullptr )
        v6 = CPresetSlider::CPresetSlider(this: v5, parent: this->m_pSliders, pFaderPanel: this);
      else
        v6 = nullptr;
      this->m_pSliders->AddItem(this: this->m_pSliders, a2: nullptr, a3: v6);
    }
    if ( v6 != nullptr )
    {
      CPresetSlider::Init(this: v6, pPresetGroupName, pPresetName);
      v6->SetValue(this: v6, a2: 0, a3: false);
      vgui::Panel::SetSize(this: v6, wide: 100, tall: 20);
      v10 = vgui::PanelListPanel::GetItemIDFromRow(this: this->m_pSliders, nRow: nSlot);
      vgui::PanelListPanel::SetItemVisible(this: this->m_pSliders, nItemID: v10, bVisible: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00491020
// Name: public: void CPresetSlider::SetControlValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::SetControlValues(CPresetSlider *this)
{
  CPresetSlider *v1; // edi
  const char *PresetGroupName; // eax
  CDmeAnimationSet *v3; // edx
  const char *PresetName; // eax
  CDmePresetGroup *v5; // edx
  CDmeTransform *Preset; // eax
  const Vector *Position; // esi
  float x; // eax
  int v9; // eax
  UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short> *v11; // eax
  int v12; // eax
  CDmElement *v13; // eax
  CDmElement *v14; // edi
  const char *m_pAsString; // eax
  CExpressionCalculator *Control; // eax
  DmElementHandle_t BufferType; // eax
  CPresetSlider *v18; // esi
  unsigned __int16 v19; // ax
  float *m_pValue; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  unsigned int v26; // [esp-4h] [ebp-88h]
  CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t search; // [esp+Ch] [ebp-78h] BYREF
  CAnimSetGroupAnimSetTraversal traversal; // [esp+60h] [ebp-24h] BYREF
  CDmrElementArray<CDmElement> values; // [esp+68h] [ebp-1Ch] BYREF
  DmElementHandle_t handle; // [esp+70h] [ebp-14h] BYREF
  int i; // [esp+74h] [ebp-10h]
  CDmeAnimationSet *pAnimSet; // [esp+78h] [ebp-Ch]
  CPresetSlider *v33; // [esp+7Ch] [ebp-8h]
  int m_Size; // [esp+80h] [ebp-4h]

  v1 = this;
  v33 = this;
  CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_AttributeLookup.m_Tree);
  if ( v1->m_nProceduralType == 0 )
  {
    traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: v1->m_pPresetFaderPanel->m_pController);
    traversal.m_nIndex = 0;
    for ( pAnimSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
          pAnimSet != nullptr;
          pAnimSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
    {
      PresetGroupName = CPresetSlider::GetPresetGroupName(this: v1);
      if ( CDmeAnimationSet::FindPresetGroup(this: v3, pGroupName: PresetGroupName) != nullptr )
      {
        PresetName = CPresetSlider::GetPresetName(this: v1);
        Preset = (CDmeTransform *)CDmePresetGroup::FindPreset(this: v5, pPresetName: PresetName);
        if ( Preset != nullptr )
        {
          Position = CDmeTransform::GetPosition(this: Preset);
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&values);
          x = Position[2].x;
          if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
          {
            values.m_pAttribute = nullptr;
            values.m_pStorage = nullptr;
            m_Size = 0;
          }
          else
          {
            values.m_pAttribute = (CDmAttribute *)LODWORD(Position[2].x);
            values.m_pStorage = *(DmElementArray_t **)(LODWORD(x) + 4);
            m_Size = values.m_pStorage->m_Size;
          }
          v9 = m_Size + v1->m_AttributeLookup.m_Tree.m_NumElements;
          if ( v1->m_AttributeLookup.m_Tree.m_Elements.m_nAllocationCount < v9
            && v1->m_AttributeLookup.m_Tree.m_Elements.m_nGrowSize >= 0 )
          {
            m_pMemory = v1->m_AttributeLookup.m_Tree.m_Elements.m_pMemory;
            v1->m_AttributeLookup.m_Tree.m_Elements.m_nAllocationCount = v9;
            v26 = 92 * v9;
            if ( m_pMemory != nullptr )
              v11 = (UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v26);
            else
              v11 = (UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v26);
            v1->m_AttributeLookup.m_Tree.m_Elements.m_pMemory = v11;
          }
          v12 = 0;
          i = 0;
          if ( m_Size > 0 )
          {
            do
            {
              v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: values.m_pStorage->m_Memory.m_pMemory[v12]);
              v14 = v13;
              if ( v13 != nullptr && v13->IsA(this: v13, a2: CDmElement::m_classType) )
              {
                m_pAsString = v14->m_Name.m_Storage.u.m_pAsString;
                if ( m_pAsString == (const char *)-1 )
                  m_pAsString = defaultValue;
                Control = (CExpressionCalculator *)CDmeAnimationSet::FindControl(
                                                     this: pAnimSet,
                                                     pControlName: m_pAsString);
                if ( Control != nullptr )
                {
                  BufferType = CCodecBuffer_Block::GetBufferType(this: Control);
                  v18 = v33;
                  memset(&search.elem, 0, 24);
                  search.elem.m_Quaternion = quat_identity;
                  handle = BufferType;
                  memset(search.elem.m_pValueAttribute, 0, 40);
                  search.key = BufferType;
                  v19 = CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                          this: &v33->m_AttributeLookup.m_Tree,
                          &search);
                  if ( v19 == 0xFFFF )
                    v19 = CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Insert(
                            this: &v18->m_AttributeLookup,
                            key: &handle);
                  m_pValue = v18->m_AttributeLookup.m_Tree.m_Elements.m_pMemory[v19].m_Data.elem.m_pValue;
                  _V_memset(dest: m_pValue, fill: 0, count: 80);
                  *(Quaternion *)(m_pValue + 6) = quat_identity;
                  Attribute = CDmElement::FindAttribute(this: v14, pAttributeName: "value");
                  if ( Attribute != nullptr )
                  {
                    *((_DWORD *)m_pValue + 10) = Attribute;
                    *m_pValue = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
                  }
                  else
                  {
                    *((_DWORD *)m_pValue + 10) = CDmElement::FindAttribute(this: v14, pAttributeName: "values");
                    *((_DWORD *)m_pValue + 15) = CDmElement::FindAttribute(this: v14, pAttributeName: "times");
                  }
                  v22 = CDmElement::FindAttribute(this: v14, pAttributeName: "leftValue");
                  if ( v22 != nullptr )
                  {
                    *((_DWORD *)m_pValue + 12) = v22;
                    m_pValue[2] = CDmAttribute::GetValue<float>(this: v22)->m_Storage;
                  }
                  else
                  {
                    *((_DWORD *)m_pValue + 12) = CDmElement::FindAttribute(this: v14, pAttributeName: "leftValues");
                    *((_DWORD *)m_pValue + 17) = CDmElement::FindAttribute(this: v14, pAttributeName: "leftTimes");
                  }
                  v23 = CDmElement::FindAttribute(this: v14, pAttributeName: "rightValue");
                  if ( v23 != nullptr )
                  {
                    *((_DWORD *)m_pValue + 11) = v23;
                    m_pValue[1] = CDmAttribute::GetValue<float>(this: v23)->m_Storage;
                  }
                  else
                  {
                    *((_DWORD *)m_pValue + 11) = CDmElement::FindAttribute(this: v14, pAttributeName: "rightValues");
                    *((_DWORD *)m_pValue + 16) = CDmElement::FindAttribute(this: v14, pAttributeName: "rightTimes");
                  }
                  v24 = CDmElement::FindAttribute(this: v14, pAttributeName: "valuePosition");
                  if ( v24 != nullptr )
                  {
                    *((_DWORD *)m_pValue + 13) = v24;
                    *((Vector *)m_pValue + 1) = CDmAttribute::GetValue<Vector>(this: v24)->m_Storage;
                  }
                  else
                  {
                    *((_DWORD *)m_pValue + 13) = CDmElement::FindAttribute(this: v14, pAttributeName: "valuePositions");
                    *((_DWORD *)m_pValue + 18) = CDmElement::FindAttribute(this: v14, pAttributeName: "timePositions");
                  }
                  v25 = CDmElement::FindAttribute(this: v14, pAttributeName: "valueOrientation");
                  if ( v25 != nullptr )
                  {
                    *((_DWORD *)m_pValue + 14) = v25;
                    *(Quaternion *)(m_pValue + 6) = *CDmAttribute::GetValue<Quaternion>(this: v25);
                  }
                  else
                  {
                    *((_DWORD *)m_pValue + 14) = CDmElement::FindAttribute(
                                                   this: v14,
                                                   pAttributeName: "valueOrientations");
                    *((_DWORD *)m_pValue + 19) = CDmElement::FindAttribute(
                                                   this: v14,
                                                   pAttributeName: "timeOrientations");
                  }
                }
              }
              v12 = i + 1;
              i = v12;
            }
            while ( v12 < m_Size );
            v1 = v33;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004913F0
// Name: Parallel_UpdateControlValues
// Source: json
//------------------------------------------------------------------------------
void __cdecl Parallel_UpdateControlValues(CPresetSlider **slider)
{
  CPresetSlider::SetControlValues(this: *slider);
}

//------------------------------------------------------------------------------
// Address: 0x00491400
// Name: public: void CBaseAnimSetPresetFaderPanel::UpdateControlValues(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::UpdateControlValues(
        CBaseAnimSetPresetFaderPanel *this,
        bool bVisibleOnly)
{
  vgui::TextEntry *m_pSliders; // ecx
  int ItemCount; // esi
  IMemAlloc_vtbl *v5; // edx
  CPresetSlider **v6; // eax
  vgui::ScrollBarSlider *i; // esi
  CPresetSlider *v8; // eax
  _BYTE *m_Id; // ecx
  int m_Size; // eax
  CPresetSlider **m_pMemory; // ecx
  int j; // esi
  CPresetSlider **v13; // eax
  CUtlVectorFixedGrowable<CPresetSlider *,100> workItems; // [esp+Ch] [ebp-1C4h] BYREF
  CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> v15; // [esp+1B4h] [ebp-1Ch] BYREF
  CPresetSlider *pSlider; // [esp+1CCh] [ebp-4h] BYREF

  workItems.m_pElements = workItems.m_Memory.m_pFixedMemory;
  m_pSliders = (vgui::TextEntry *)this->m_pSliders;
  workItems.m_Memory.m_pMemory = workItems.m_Memory.m_pFixedMemory;
  workItems.m_Memory.m_nAllocationCount = 100;
  workItems.m_Memory.m_nGrowSize = -1;
  workItems.m_Memory.m_nMallocGrowSize = 0;
  workItems.m_Size = 0;
  ItemCount = vgui::PanelListPanel::GetItemCount(this: m_pSliders);
  if ( ItemCount > 100 )
  {
    CUtlMemory<CPresetSlider *,int>::ConvertToGrowableMemory(
      this: &workItems.m_Memory,
      nGrowSize: workItems.m_Memory.m_nMallocGrowSize);
    if ( workItems.m_Memory.m_nAllocationCount < ItemCount && workItems.m_Memory.m_nGrowSize >= 0 )
    {
      workItems.m_Memory.m_nAllocationCount = ItemCount;
      v5 = _g_pMemAlloc->__vftable;
      if ( workItems.m_Memory.m_pMemory != nullptr )
        v6 = (CPresetSlider **)((int (__stdcall *)(CPresetSlider **, int))v5->Realloc_2)(
                                 a1: workItems.m_Memory.m_pMemory,
                                 a2: 4 * ItemCount);
      else
        v6 = (CPresetSlider **)((int (__stdcall *)(int))v5->Alloc_2)(a1: 4 * ItemCount);
      workItems.m_Memory.m_pMemory = v6;
    }
  }
  workItems.m_pElements = workItems.m_Memory.m_pMemory;
  for ( i = vgui::ScrollBar::GetSlider(this: (vgui::ScrollBar *)this->m_pSliders);
        i != (vgui::ScrollBarSlider *)vgui::TreeView::InvalidItemID(this: (vgui::TreeView *)this->m_pSliders);
        i = (vgui::ScrollBarSlider *)vgui::PanelListPanel::NextItem(this: this->m_pSliders, nItemID: (int)i) )
  {
    v8 = (CPresetSlider *)this->m_pSliders->GetItemPanel(this: this->m_pSliders, a2: i);
    pSlider = v8;
    if ( v8 != nullptr )
    {
      m_Id = (_BYTE *)v8->m_presetName.u.m_Id;
      if ( m_Id != (_BYTE *)-1 && m_Id != nullptr && *m_Id != 0 && (!bVisibleOnly || v8->IsVisible(this: v8)) )
        CUtlVector<CPresetSlider *,CUtlMemoryFixedGrowable<CPresetSlider *,100,int>>::InsertBefore(
          this: &workItems,
          elem: workItems.m_Size,
          src: &pSlider);
    }
  }
  if ( ifm_threaded_updatecontrolvalues.m_pParent->m_Value.m_nValue != 0 )
  {
    m_Size = workItems.m_Size;
    m_pMemory = workItems.m_Memory.m_pMemory;
    v15.m_pItems.m_value = nullptr;
    v15.m_pLimit = nullptr;
    _InterlockedExchange((volatile __int32 *)&v15.m_pItems, 0);
    v15.m_ItemProcessor.m_pfnProcess = Parallel_UpdateControlValues;
    v15.m_ItemProcessor.m_pfnBegin = nullptr;
    v15.m_ItemProcessor.m_pfnEnd = nullptr;
    CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::Run(
      this: &v15,
      pItems: m_pMemory,
      nItems: m_Size,
      nChunkSize: 1,
      nMaxParallel: 0x7FFFFFFF,
      pThreadPool: nullptr);
  }
  else
  {
    for ( j = 0; j < workItems.m_Size; ++j )
      CPresetSlider::SetControlValues(this: workItems.m_Memory.m_pMemory[j]);
  }
  v13 = workItems.m_Memory.m_pMemory;
  workItems.m_Size = 0;
  if ( workItems.m_Memory.m_nGrowSize >= 0 )
  {
    if ( workItems.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: workItems.m_Memory.m_pMemory);
      v13 = nullptr;
      workItems.m_Memory.m_pMemory = nullptr;
    }
    workItems.m_Memory.m_nAllocationCount = 0;
  }
  workItems.m_pElements = v13;
  if ( workItems.m_Memory.m_nGrowSize >= 0 && v13 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
}

//------------------------------------------------------------------------------
// Address: 0x00491610
// Name: protected: void CBaseAnimSetPresetFaderPanel::RebuildPresetSliders(char const __near *,class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::RebuildPresetSliders(
        CBaseAnimSetPresetFaderPanel *this,
        const char *pPresetGroupName,
        const CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > *presetNames)
{
  int m_Size; // ebx
  int i; // edi
  const char *m_pAsString; // eax
  CSliderListPanel *m_pSliders; // ecx
  CSliderListPanel_vtbl *v8; // edi
  int ItemIDFromRow; // eax
  int v10; // eax
  int nSliders; // [esp+18h] [ebp+Ch]

  vgui::PanelListPanel::HideAllItems(this: this->m_pSliders);
  m_Size = presetNames->m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    m_pAsString = presetNames->m_Memory.m_pMemory[i].u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    CBaseAnimSetPresetFaderPanel::UpdateOrCreatePresetSlider(this, nSlot: i, pPresetGroupName, pPresetName: m_pAsString);
  }
  for ( nSliders = vgui::PanelListPanel::GetItemCount(this: (vgui::TextEntry *)this->m_pSliders);
        m_Size < nSliders;
        ++m_Size )
  {
    m_pSliders = this->m_pSliders;
    v8 = m_pSliders->__vftable;
    ItemIDFromRow = vgui::PanelListPanel::GetItemIDFromRow(this: m_pSliders, nRow: m_Size);
    v10 = (int)v8->GetItemPanel(this: this->m_pSliders, a2: ItemIDFromRow);
    if ( v10 != 0 )
    {
      *(_DWORD *)(v10 + 504) = 0;
      *(_BYTE *)(v10 + 508) = 0;
      *(_DWORD *)(v10 + 500) = -1;
      *(_DWORD *)(v10 + 496) = -1;
      CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v10 + 468));
    }
  }
  CBaseAnimSetPresetFaderPanel::UpdateControlValues(this, bVisibleOnly: false);
}

//------------------------------------------------------------------------------
// Address: 0x004916E0
// Name: protected: void CBaseAnimSetPresetFaderPanel::PopulatePresetList(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::PopulatePresetList(CBaseAnimSetPresetFaderPanel *this, bool bChanged)
{
  CDmeFilmClip *AnimationSetClip; // eax
  vgui::PropertySheet *m_pSheet; // ecx
  int v5; // eax
  vgui::PropertySheet *v6; // ecx
  int v7; // edi
  vgui::Panel *(__thiscall *GetActivePage)(vgui::PropertySheet *); // edx
  int v9; // ebx
  vgui::Panel *v10; // eax
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int m_Size; // eax
  vgui::PropertyPage *v13; // edi
  const char *m_pAsString; // ebx
  bool v15; // zf
  vgui::PropertySheet_vtbl *v16; // eax
  const char *v17; // eax
  vgui::PropertyPage *v18; // eax
  int v19; // ebx
  int m_nAllocationCount; // eax
  vgui::PropertyPage **m_pMemory; // ecx
  int v22; // eax
  vgui::PropertyPage **v23; // ebx
  vgui::PropertyPage *v24; // edi
  CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > presetNames; // [esp+Ch] [ebp-48h] BYREF
  CUtlVector<PresetGroupInfo_t,CUtlMemory<PresetGroupInfo_t,int> > presetGroupInfo; // [esp+20h] [ebp-34h] BYREF
  CDmeFilmClip *pFilmClip; // [esp+34h] [ebp-20h]
  int nCurrentGroupIndex; // [esp+38h] [ebp-1Ch]
  const char *pCurrentGroupName; // [esp+3Ch] [ebp-18h]
  int nPresetGroupPages; // [esp+40h] [ebp-14h] BYREF
  PresetGroupInfo_t src; // [esp+44h] [ebp-10h] BYREF
  const char *pName; // [esp+4Ch] [ebp-8h]
  bool bCurrentGroupIsProceduralGroup; // [esp+53h] [ebp-1h]

  AnimationSetClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  m_pSheet = this->m_pSheet;
  pFilmClip = AnimationSetClip;
  v5 = m_pSheet->GetActivePageNum(this: m_pSheet);
  v6 = this->m_pSheet;
  v7 = v5;
  GetActivePage = v6->GetActivePage;
  v9 = 0;
  nCurrentGroupIndex = v5;
  bCurrentGroupIsProceduralGroup = v5 == 0;
  if ( (int)GetActivePage(this: v6) != 0 )
  {
    v10 = this->m_pSheet->GetActivePage(this: this->m_pSheet);
    pCurrentGroupName = v10->GetName(this: v10);
  }
  else
  {
    pCurrentGroupName = defaultValue;
  }
  GetSymbol = g_pDataModel->GetSymbol;
  memset(&presetGroupInfo, 0, sizeof(presetGroupInfo));
  GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&nPresetGroupPages, a3: "Procedural");
  src.presetGroupSym.u.m_Id = nPresetGroupPages;
  CUtlVector<PresetGroupInfo_t,CUtlMemory<PresetGroupInfo_t,int>>::InsertBefore(this: &presetGroupInfo, elem: 0, &src);
  CollectPresetGroupInfo(
    pFilmClip,
    presetInfo: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&presetGroupInfo,
    bSkipReadOnly: false,
    bSkipInvisible: true);
  m_Size = this->m_presetGroupPages.m_Size;
  nPresetGroupPages = m_Size;
  *(_DWORD *)&src.bGroupShared = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v13 = this->m_presetGroupPages.m_Memory.m_pMemory[v9];
      if ( v13 != nullptr )
      {
        if ( v9 >= presetGroupInfo.m_Size )
        {
          this->m_pSheet->RemovePage(this: this->m_pSheet, a2: v13);
          vgui::Panel::SetName(this: v13, panelName: defaultValue);
        }
        else
        {
          m_pAsString = presetGroupInfo.m_Memory.m_pMemory[v9].presetGroupSym.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = defaultValue;
          v15 = *v13->GetName(this: v13) == 0;
          v16 = this->m_pSheet->__vftable;
          if ( v15 )
            ((void (__stdcall *)(vgui::PropertyPage *, const char *, _DWORD, _DWORD, int))v16->AddPage)(
              a1: v13,
              a2: m_pAsString,
              a3: 0,
              a4: 0,
              a5: -1);
          else
            ((void (__stdcall *)(vgui::PropertyPage *, const char *))v16->SetPageTitle)(a1: v13, a2: m_pAsString);
          vgui::Panel::SetName(this: v13, panelName: m_pAsString);
          v9 = *(_DWORD *)&src.bGroupShared;
        }
        m_Size = nPresetGroupPages;
      }
      *(_DWORD *)&src.bGroupShared = ++v9;
    }
    while ( v9 < m_Size );
    v7 = nCurrentGroupIndex;
  }
  nPresetGroupPages = m_Size;
  if ( m_Size < presetGroupInfo.m_Size )
  {
    do
    {
      v17 = presetGroupInfo.m_Memory.m_pMemory[nPresetGroupPages].presetGroupSym.u.m_pAsString;
      pName = defaultValue;
      if ( v17 != (const char *)-1 )
        pName = v17;
      v18 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
      if ( v18 != nullptr )
        *(_DWORD *)&src.bGroupShared = vgui::PropertyPage::PropertyPage(this: v18, parent: this, panelName: pName);
      else
        *(_DWORD *)&src.bGroupShared = 0;
      v19 = this->m_presetGroupPages.m_Size;
      m_nAllocationCount = this->m_presetGroupPages.m_Memory.m_nAllocationCount;
      if ( v19 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_presetGroupPages,
          num: v19 - m_nAllocationCount + 1);
      ++this->m_presetGroupPages.m_Size;
      m_pMemory = this->m_presetGroupPages.m_Memory.m_pMemory;
      v22 = this->m_presetGroupPages.m_Size - v19 - 1;
      this->m_presetGroupPages.m_pElements = m_pMemory;
      if ( v22 > 0 )
        _V_memmove(dest: &m_pMemory[v19 + 1], src: &m_pMemory[v19], count: 4 * v22);
      v23 = &this->m_presetGroupPages.m_Memory.m_pMemory[v19];
      if ( v23 != nullptr )
        *v23 = *(vgui::PropertyPage **)&src.bGroupShared;
      this->m_pSheet->AddPage(
        this: this->m_pSheet,
        a2: *(vgui::Panel **)&src.bGroupShared,
        a3: pName,
        a4: nullptr,
        a5: false,
        a6: -1);
      ++nPresetGroupPages;
    }
    while ( nPresetGroupPages < presetGroupInfo.m_Size );
    v7 = nCurrentGroupIndex;
  }
  if ( v7 >= 0 )
  {
    v24 = this->m_presetGroupPages.m_Memory.m_pMemory[v7];
    this->m_pSheet->SetActivePage(this: this->m_pSheet, a2: v24);
    this->m_pSliders->SetParent_2(this: this->m_pSliders, a2: v24);
    memset(&presetNames, 0, sizeof(presetNames));
    if ( bCurrentGroupIsProceduralGroup )
      CollectProceduralPresetNames((CUtlMemory<vgui::TreeNode *,int> *)&presetNames);
    else
      CollectPresetNamesForGroup(
        pFilmClip,
        pPresetGroupName: pCurrentGroupName,
        (CUtlMemory<vgui::TreeNode *,int> *)&presetNames);
    CBaseAnimSetPresetFaderPanel::RebuildPresetSliders(this, pPresetGroupName: pCurrentGroupName, &presetNames);
    if ( presetNames.m_Memory.m_nGrowSize >= 0 && presetNames.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: presetNames.m_Memory.m_pMemory);
  }
  else
  {
    vgui::PanelListPanel::HideAllItems(this: this->m_pSliders);
  }
  if ( presetGroupInfo.m_Memory.m_nGrowSize >= 0 && presetGroupInfo.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: presetGroupInfo.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00491A10
// Name: public: void CBaseAnimSetPresetFaderPanel::OnDeletePreset(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::OnDeletePreset(
        CBaseAnimSetPresetFaderPanel *this,
        const char *pPresetName)
{
  CDmeAnimationSet *i; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-8h] BYREF

  g_pDataModel->StartUndo(this: g_pDataModel, a2: "Delete Preset", a3: "Delete Preset", a4: 0);
  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Delete Preset", a3: 0, a4: 256);
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  traversal.m_nIndex = 0;
  for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        i != nullptr;
        i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
  {
    CDmeAnimationSet::RemovePreset(this: i, pPresetName);
  }
  CBaseAnimSetPresetFaderPanel::PopulatePresetList(this, bChanged: false);
  g_pDataModel->FinishUndo(this: g_pDataModel);
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00491AC0
// Name: protected: virtual void CPresetSlider::OnDeleteConfirmed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnDeleteConfirmed(CPresetSlider *this)
{
  const char *m_pAsString; // eax

  m_pAsString = this->m_presetName.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  CBaseAnimSetPresetFaderPanel::OnDeletePreset(this: this->m_pPresetFaderPanel, pPresetName: m_pAsString);
}

//------------------------------------------------------------------------------
// Address: 0x00491AE0
// Name: protected: virtual void CBaseAnimSetPresetFaderPanel::OnPresetNameSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::OnPresetNameSelected(
        CBaseAnimSetPresetFaderPanel *this,
        KeyValues *pParams)
{
  const char *String; // ebx
  const char *pPresetGroupName; // [esp+Ch] [ebp-4h]

  String = KeyValues::GetString(this: pParams, keyName: "text", defaultValue: nullptr);
  pPresetGroupName = KeyValues::GetString(this: pParams, keyName: "presetGroupName", defaultValue: defaultValue);
  LOBYTE(pParams) = KeyValues::GetInt(this: pParams, keyName: "animated", defaultValue: 0) != 0;
  CBaseAnimSetPresetFaderPanel::AddPreset(this, pPresetGroupName, pPresetName: String, bAnimated: (int)pParams);
  CBaseAnimSetPresetFaderPanel::PopulatePresetList(this, bChanged: false);
}

//------------------------------------------------------------------------------
// Address: 0x00491B50
// Name: protected: virtual void CBaseAnimSetPresetFaderPanel::OnPresetsChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::OnPresetsChanged(CBaseAnimSetPresetFaderPanel *this)
{
  CBaseAnimSetPresetFaderPanel::PopulatePresetList(this, bChanged: false);
}

//------------------------------------------------------------------------------
// Address: 0x00491B60
// Name: protected: virtual void CBaseAnimSetPresetFaderPanel::OnPageChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::OnPageChanged(CBaseAnimSetPresetFaderPanel *this)
{
  CBaseAnimSetPresetFaderPanel::PopulatePresetList(this, bChanged: true);
}

//------------------------------------------------------------------------------
// Address: 0x005D8B00
// Name: private: void CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute(
        CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *this)
{
  void (__thiscall *m_pfnBegin)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *); // eax
  int *m_pLimit; // ecx
  unsigned int v4; // edx
  int *v5; // esi
  int *v6; // ebx
  void (__thiscall *m_pfnEnd)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *); // eax
  unsigned int v8; // [esp+4h] [ebp-8h]
  int *pLimit; // [esp+8h] [ebp-4h]

  if ( this->m_pItems.m_value < this->m_pLimit )
  {
    m_pfnBegin = this->m_ItemProcessor.m_pfnBegin;
    if ( m_pfnBegin != nullptr )
      m_pfnBegin(this: this->m_ItemProcessor.m_pObject);
    m_pLimit = this->m_pLimit;
    v4 = 4 * this->m_nChunkSize;
    pLimit = m_pLimit;
    v8 = v4;
    do
    {
      v5 = (int *)_InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pItems, v4);
      v6 = (int *)((char *)v5 + v4);
      if ( m_pLimit < (int *)((char *)v5 + v4) )
        v6 = m_pLimit;
      if ( v5 < v6 )
      {
        do
          this->m_ItemProcessor.m_pfnProcess(this: this->m_ItemProcessor.m_pObject, a2: v5++);
        while ( v5 < v6 );
        m_pLimit = pLimit;
        v4 = v8;
      }
    }
    while ( v5 < m_pLimit );
    m_pfnEnd = this->m_ItemProcessor.m_pfnEnd;
    if ( m_pfnEnd != nullptr )
      m_pfnEnd(this: this->m_ItemProcessor.m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D8D90
// Name: public: virtual void CMemberFunctor0<class CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1> __near *,void (CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1>::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x005D8F70
// Name: public: void CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1>::Run(int __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::Run(
        CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *this,
        int *pItems,
        unsigned int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  unsigned int v6; // ebx
  IThreadPool *v8; // ecx
  int *v9; // eax
  int v10; // ebx
  int v11; // eax
  void *v12; // esp
  int i; // esi
  CFunctor *v14; // eax
  CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *v15; // ecx
  _DWORD v16[3]; // [esp+0h] [ebp-10h]
  CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *v17; // [esp+Ch] [ebp-4h]

  v6 = nItems;
  v17 = this;
  if ( nItems != 0 )
  {
    v8 = pThreadPool;
    this->m_nChunkSize = nChunkSize;
    if ( v8 == nullptr )
    {
      pThreadPool = _g_pThreadPool;
      v8 = _g_pThreadPool;
    }
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v9 = &pItems[v6];
    v10 = v6 - 1;
    this->m_pLimit = v9;
    if ( v10 > nMaxParallel )
      v10 = nMaxParallel;
    if ( v8 == nullptr )
      goto LABEL_18;
    v11 = v8->NumThreads(this: v8);
    if ( v10 > v11 )
      v10 = v11;
    if ( v10 > 0 )
    {
      v12 = alloca(4 * v10);
      for ( i = v10; i != 0; v16[i] = nItems )
      {
        --i;
        v14 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
        if ( v14 != nullptr )
        {
          v15 = v17;
          v14[1].m_nUserID = 1;
          v14->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v14[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v14[2].__vftable = (CFunctor_vtbl *)CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute;
          v14[2].m_nUserID = (unsigned int)v15;
        }
        else
        {
          v14 = nullptr;
        }
        pThreadPool->AddFunctorInternal(this: pThreadPool, a2: v14, a3: (CJob **)&nItems, a4: nullptr, a5: 8u);
      }
      CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute(this: v17);
      do
      {
        CJob::Abort(this: (CJob *)v16[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v16[i] + 4))(a1: v16[i]);
        ++i;
      }
      while ( i < v10 );
    }
    else
    {
LABEL_18:
      CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00627D90
// Name: protected: virtual void vgui::BaseInputDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::BaseInputDialog::PerformLayout(vgui::BaseInputDialog *this)
{
  bool v2; // al
  int v3; // edi
  int v4; // [esp-Ch] [ebp-20h]
  int w; // [esp+Ch] [ebp-8h] BYREF
  int h; // [esp+10h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v2 = this->IsSmallCaption(this);
  v3 = w / 2;
  this->PerformLayout_2(this, a2: 12, a3: v2 ? 15 : 30, a4: w - 24, a5: h - 100);
  v4 = h - 30;
  if ( this->m_pCancelButton != nullptr )
  {
    vgui::Panel::SetBounds(this: this->m_pOKButton, x: v3 - 84, y: v4, wide: 72, tall: 24);
    vgui::Panel::SetBounds(this: this->m_pCancelButton, x: v3 + 12, y: h - 30, wide: 72, tall: 24);
  }
  else
  {
    vgui::Panel::SetBounds(this: this->m_pOKButton, x: v3 - 36, y: v4, wide: 72, tall: 24);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006281D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::BaseInputDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::BaseInputDialog::GetMessageMap(vgui::BaseInputDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::BaseInputDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::BaseInputDialog::GetMessageMap'::`2'::s_pMap;
  `vgui::BaseInputDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "BaseInputDialog");
  `vgui::BaseInputDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00628200
// Name: public: virtual struct PanelAnimationMap __near * vgui::BaseInputDialog::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::BaseInputDialog::GetAnimMap(vgui::BaseInputDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "BaseInputDialog");
}

//------------------------------------------------------------------------------
// Address: 0x00628210
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::BaseInputDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::BaseInputDialog::GetKBMap(vgui::BaseInputDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::BaseInputDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::BaseInputDialog::GetKBMap'::`2'::s_pMap;
  `vgui::BaseInputDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "BaseInputDialog");
  `vgui::BaseInputDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0062E280
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
// Address: 0x0062E2B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::FileOpenStateMachine::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::FileOpenStateMachine::GetAnimMap(vgui::FileOpenStateMachine *this)
{
  return FindOrAddPanelAnimationMap(className: "FileOpenStateMachine");
}

//------------------------------------------------------------------------------
// Address: 0x0062E2C0
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

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1039B043
// Name: protected: void CMFCShellTreeCtrl::OnShowContextMenu(class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCShellTreeCtrl::OnShowContextMenu(CMFCShellTreeCtrl *this, tagPOINT point)
{
  struct _TREEITEM *v3; // ebx
  int v4; // ebx
  IShellFolder *v5; // eax
  HWND Parent; // eax
  CWnd *v7; // eax
  HWND__ *v8; // ebx
  unsigned int v9; // ebx
  AFX_MODULE_STATE *ModuleState; // eax
  void (__stdcall **v11)(int, GUID *, IContextMenu2 **); // ecx
  HWND v12; // eax
  HWND v13; // eax
  CWnd *v14; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-9Ch]
  HWND__ *v16; // [esp-10h] [ebp-9Ch]
  unsigned __int8 dst[40]; // [esp+10h] [ebp-7Ch] BYREF
  _DWORD v18[9]; // [esp+38h] [ebp-54h] BYREF
  CWaitCursor v19; // [esp+5Fh] [ebp-2Dh] BYREF
  IShellFolder *ppshf; // [esp+60h] [ebp-2Ch] BYREF
  void (__stdcall ***v21)(int, GUID *, IContextMenu2 **); // [esp+64h] [ebp-28h] BYREF
  unsigned int pFlags; // [esp+68h] [ebp-24h] BYREF
  tagRECT Rect; // [esp+6Ch] [ebp-20h] BYREF
  int v24; // [esp+88h] [ebp-4h]

  if ( CMFCShellTreeCtrl::m_pContextMenu2 == nullptr )
  {
    if ( this->m_bContextMenu == 0 )
    {
      CWnd::Default(this);
      return;
    }
    if ( point.x == -1 && point.y == -1 )
    {
      m_hWnd = this->m_hWnd;
      memset(&Rect, 0, sizeof(Rect));
      v3 = (struct _TREEITEM *)SendMessageA(hWnd: m_hWnd, Msg: 0x110Au, wParam: 9u, lParam: 0);
      if ( v3 == nullptr )
        return;
      if ( CTreeCtrl::GetItemRect(this, hItem: v3, lpRect: &Rect, bTextOnly: 0) != 0 )
      {
        point.x = Rect.left;
        point.y = Rect.bottom + 1;
        ClientToScreen(hWnd: this->m_hWnd, lpPoint: &point);
      }
    }
    else
    {
      *(tagPOINT *)&Rect.right = point;
      ScreenToClient(hWnd: this->m_hWnd, lpPoint: (LPPOINT)&Rect.right);
      pFlags = 0;
      v3 = CTreeCtrl::HitTest(this, pt: *(tagPOINT *)&Rect.right, &pFlags);
    }
    if ( v3 != nullptr )
    {
      memset(dst, value: 0, count: sizeof(dst));
      v16 = this->m_hWnd;
      *(_DWORD *)dst = 4;
      *(_DWORD *)&dst[4] = v3;
      if ( SendMessageA(hWnd: v16, Msg: 0x110Cu, wParam: 0, lParam: (LPARAM)dst) != 0 )
      {
        v4 = *(_DWORD *)&dst[36];
        if ( *(_DWORD *)&dst[36] != 0 )
        {
          v5 = **(IShellFolder ***)&dst[36];
          ppshf = v5;
          if ( v5 != nullptr )
          {
            v5->AddRef(this: v5);
          }
          else if ( SHGetDesktopFolder(&ppshf) < 0 )
          {
            AfxThrowInvalidArgException();
          }
          if ( ppshf != nullptr )
          {
            Parent = GetParent(hWnd: this->m_hWnd);
            v7 = CWnd::FromHandle(hWnd: Parent);
            if ( v7 != nullptr )
              Rect.bottom = (int)v7->m_hWnd;
            else
              Rect.bottom = 0;
            v21 = nullptr;
            if ( ppshf->GetUIObjectOf(
                   this: ppshf,
                   a2: (HWND__ *)Rect.bottom,
                   a3: 1u,
                   a4: (const _ITEMIDLIST **)(v4 + 8),
                   a5: &IID_IContextMenu,
                   a6: nullptr,
                   a7: (void **)&v21) >= 0 )
            {
              pFlags = (unsigned int)CreatePopupMenu();
              if ( pFlags != 0
                && ((int (__stdcall *)(void (__stdcall ***)(int, GUID *, IContextMenu2 **), unsigned int, _DWORD, int, int, int))(*v21)[3])(
                     a1: v21,
                     a2: pFlags,
                     a3: 0,
                     a4: 1,
                     a5: 0x7FFF,
                     a6: 4) >= 0 )
              {
                (**v21)(a1: (int)v21, a2: &IID_IContextMenu2, a3: &CMFCShellTreeCtrl::m_pContextMenu2);
                v8 = this->m_hWnd;
                pFlags = TrackPopupMenu(
                           hMenu: (HMENU)pFlags,
                           uFlags: 0x102u,
                           x: point.x,
                           y: point.y,
                           nReserved: 0,
                           hWnd: v8,
                           prcRect: nullptr);
                if ( IsWindow(hWnd: v8) )
                {
                  if ( CMFCShellTreeCtrl::m_pContextMenu2 != nullptr )
                  {
                    CMFCShellTreeCtrl::m_pContextMenu2->Release(this: CMFCShellTreeCtrl::m_pContextMenu2);
                    CMFCShellTreeCtrl::m_pContextMenu2 = nullptr;
                  }
                  v9 = pFlags;
                  if ( pFlags != 0 )
                  {
                    ModuleState = AfxGetModuleState();
                    CCmdTarget::BeginWaitCursor(this: ModuleState->m_pCurrentWinApp);
                    v18[2] = Rect.bottom;
                    v18[0] = 36;
                    v18[1] = 0;
                    v18[3] = v9 - 1;
                    v18[4] = 0;
                    v18[5] = 0;
                    v18[6] = 1;
                    v18[7] = 0;
                    v18[8] = 0;
                    v11 = *v21;
                    v24 = 0;
                    if ( ((int (__stdcall *)(void (__stdcall ***)(int, GUID *, IContextMenu2 **), _DWORD *))v11[4])(
                           a1: v21,
                           a2: v18) >= 0 )
                    {
                      v12 = GetParent(hWnd: this->m_hWnd);
                      if ( CWnd::FromHandle(hWnd: v12) != nullptr )
                      {
                        v13 = GetParent(hWnd: this->m_hWnd);
                        v14 = CWnd::FromHandle(hWnd: v13);
                        SendMessageA(hWnd: v14->m_hWnd, Msg: AFX_WM_ON_AFTER_SHELL_COMMAND, wParam: pFlags, lParam: 0);
                      }
                    }
                    CWnd::SetFocus(this);
                    v24 = -1;
                    CWaitCursor::~CWaitCursor(this: &v19);
                  }
                }
              }
              if ( v21 != nullptr )
              {
                ((void (__stdcall *)(void (__stdcall ***)(int, GUID *, IContextMenu2 **)))(*v21)[2])(a1: v21);
                v21 = nullptr;
              }
            }
            if ( ppshf != nullptr )
              ppshf->Release(this: ppshf);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049A060
// Name: int ProceduralTypeForPresetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ProceduralTypeForPresetName(const char *pPresetName)
{
  int v1; // esi

  v1 = 0;
  while ( _V_stricmp(s1: pPresetName, s2: g_ProceduralPresetNames_12[v1]) != 0 )
  {
    if ( ++v1 >= 21 )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1049A0A0
// Name: public: static char const __near * CBaseAnimSetPresetFaderPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAnimSetPresetFaderPanel::GetPanelClassName()
{
  return "CBaseAnimSetPresetFaderPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1049A0B0
// Name: public: static char const __near * CPresetSlider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPresetSlider::GetPanelClassName()
{
  return "CPresetSlider";
}

//------------------------------------------------------------------------------
// Address: 0x1049A0C0
// Name: class CDmePresetGroup __near * FindAnyPresetGroup(class CDmeFilmClip __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePresetGroup *__cdecl FindAnyPresetGroup(CDmeFilmClip *pFilmClip, const char *pPresetGroupName)
{
  CDmeAnimationSet *v2; // eax
  CDmePresetGroup *result; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-8h] BYREF

  traversal.m_pFilmClip = pFilmClip;
  traversal.m_nIndex = 0;
  v2 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  if ( v2 == nullptr )
    return nullptr;
  while ( 1 )
  {
    result = CDmeAnimationSet::FindPresetGroup(this: v2, pGroupName: pPresetGroupName);
    if ( result != nullptr )
      break;
    v2 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v2 == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049A110
// Name: class CDmePreset __near * FindAnyPreset(class CDmeFilmClip __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePreset *__cdecl FindAnyPreset(CDmeFilmClip *pFilmClip, const char *pPresetGroupName, const char *pPresetName)
{
  CDmeAnimationSet *v3; // eax
  CDmePresetGroup *PresetGroup; // eax
  CDmePreset *result; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-8h] BYREF

  traversal.m_pFilmClip = pFilmClip;
  traversal.m_nIndex = 0;
  v3 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  if ( v3 == nullptr )
    return nullptr;
  while ( 1 )
  {
    PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v3, pGroupName: pPresetGroupName);
    if ( PresetGroup != nullptr )
    {
      result = CDmePresetGroup::FindPreset(this: PresetGroup, pPresetName);
      if ( result != nullptr )
        break;
    }
    v3 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v3 == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049A170
// Name: public: static char const __near * CAddPresetDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAddPresetDialog::GetPanelClassName()
{
  return "CAddPresetDialog";
}

//------------------------------------------------------------------------------
// Address: 0x1049A180
// Name: protected: virtual void CAddPresetDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAddPresetDialog::OnCommand(CAddPresetDialog *this, const char *command)
{
  int v3; // edi
  void *v4; // esp
  vgui::TextEntry *m_pPresetName; // ecx
  vgui::TextEntry_vtbl *v6; // edx
  int v7; // edi
  void *v8; // esp
  KeyValues *v9; // eax
  KeyValues *v10; // edi
  char v11[12]; // [esp+0h] [ebp-10h] BYREF
  char *txt; // [esp+Ch] [ebp-4h]
  bool bAnimated_3; // [esp+1Bh] [ebp+Bh]

  if ( _V_stricmp(s1: command, s2: "OK") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Cancel") != 0 )
      vgui::BaseInputDialog::OnCommand(this, command);
    else
      this->CloseModal(this);
  }
  else
  {
    v3 = this->m_pPresetName->GetTextLength(this: this->m_pPresetName) + 1;
    v4 = alloca(v3);
    m_pPresetName = this->m_pPresetName;
    v6 = m_pPresetName->__vftable;
    txt = v11;
    v6->GetText_2(this: m_pPresetName, a2: v11, a3: v3);
    v7 = this->m_pPresetGroup->GetTextLength(this: this->m_pPresetGroup) + 1;
    v8 = alloca(v7);
    this->m_pPresetGroup->GetText_2(this: this->m_pPresetGroup, a2: v11, a3: v7);
    bAnimated_3 = this->m_pAnimated->IsSelected(this: this->m_pAnimated);
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
      v10 = KeyValues::KeyValues(this: v9, setName: "PresetNameSelected", firstKey: "text", firstValue: txt);
    else
      v10 = nullptr;
    KeyValues::SetString(this: v10, keyName: "presetGroupName", value: v11);
    KeyValues::SetInt(this: v10, keyName: "animated", value: bAnimated_3);
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v10, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    this->PostActionSignal(this, a2: v10);
    this->CloseModal(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049A2E0
// Name: protected: virtual void CAddPresetDialog::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAddPresetDialog::OnTick(CAddPresetDialog *this)
{
  bool bEnableOkayButton; // [esp+4h] [ebp-4h]

  if ( this->m_pPresetName->GetTextLength(this: this->m_pPresetName) <= 0
    || (bEnableOkayButton = true, this->m_pPresetGroup->GetTextLength(this: this->m_pPresetGroup) <= 0) )
  {
    bEnableOkayButton = false;
  }
  this->m_pOKButton->SetEnabled(this: this->m_pOKButton, a2: bEnableOkayButton);
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1049A340
// Name: public: char const __near * CPresetSlider::GetPresetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPresetSlider::GetPresetName(CPresetSlider *this)
{
  const char *result; // eax

  result = this->m_presetName.u.m_pAsString;
  if ( result == (const char *)-1 )
    return &var;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049A360
// Name: public: char const __near * CPresetSlider::GetPresetGroupName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPresetSlider::GetPresetGroupName(CPresetSlider *this)
{
  const char *result; // eax

  result = this->m_presetGroupName.u.m_pAsString;
  if ( result == (const char *)-1 )
    return &var;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049A380
// Name: protected: virtual void CPresetSlider::OnRename(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnRename(CPresetSlider *this)
{
  vgui::InputDialog *v2; // edi
  const char *v3; // eax
  vgui::InputDialog *v4; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v2 = (vgui::InputDialog *)operator new(nSize: 0x22Cu);
  if ( v2 != nullptr )
  {
    v3 = this->GetName(this);
    v4 = vgui::InputDialog::InputDialog(
           this: v2,
           parent: this,
           title: "Rename Preset",
           prompt: "Name:",
           defaultValue: v3);
    if ( v4 != nullptr )
    {
      v4->SetSmallCaption(this: v4, a2: true);
      vgui::InputDialog::SetMultiline(this: v4, state: false);
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
      {
        v6 = KeyValues::KeyValues(this: v5, setName: "RenamePreset");
        vgui::BaseInputDialog::DoModal(this: v4, pContextKeyValues: v6);
      }
      else
      {
        vgui::BaseInputDialog::DoModal(this: v4, pContextKeyValues: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049A410
// Name: protected: virtual void CPresetSlider::OnDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnDelete(CPresetSlider *this)
{
  const char *v2; // eax
  vgui::MessageBox *v3; // eax
  vgui::MessageBox *v4; // eax
  vgui::MessageBox *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  char sz[256]; // [esp+4h] [ebp-100h] BYREF

  v2 = this->GetName(this);
  V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "Delete '%s'?", v2);
  v3 = (vgui::MessageBox *)operator new(nSize: 0x234u);
  if ( v3 != nullptr )
  {
    v4 = vgui::MessageBox::MessageBox(this: v3, title: "Delete Preset", text: sz, parent: this);
    v5 = v4;
    if ( v4 != nullptr )
    {
      vgui::MessageBox::SetCancelButtonVisible(this: v4, state: true);
      vgui::MessageBox::SetCancelButtonText(this: v5, buttonText: "#VGui_Cancel");
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "OnDeleteConfirmed");
      else
        v7 = nullptr;
      v5->SetCommand(this: v5, a2: v7);
      v5->AddActionSignalTarget_2(this: v5, a2: this);
      v5->DoModal_2(this: v5, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049A4D0
// Name: protected: virtual void CPresetSlider::GetTrackRect(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::GetTrackRect(CPresetSlider *this, int *x, int *y, int *w, int *h)
{
  vgui::Panel::GetSize(this, wide: w, tall: h);
  *x = 2;
  *y = 2;
  *w -= 4;
  *h -= 4;
}

//------------------------------------------------------------------------------
// Address: 0x1049A500
// Name: protected: virtual void CPresetSlider::OnCurve1(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCurve1(CPresetSlider *this)
{
  this->m_pPresetFaderPanel->DispatchCurve(this: this->m_pPresetFaderPanel, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1049A520
// Name: protected: virtual void CPresetSlider::OnCurve2(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCurve2(CPresetSlider *this)
{
  this->m_pPresetFaderPanel->DispatchCurve(this: this->m_pPresetFaderPanel, a2: 2);
}

//------------------------------------------------------------------------------
// Address: 0x1049A540
// Name: protected: virtual void CPresetSlider::OnCurve3(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCurve3(CPresetSlider *this)
{
  this->m_pPresetFaderPanel->DispatchCurve(this: this->m_pPresetFaderPanel, a2: 3);
}

//------------------------------------------------------------------------------
// Address: 0x1049A560
// Name: protected: virtual void CPresetSlider::OnCurve4(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCurve4(CPresetSlider *this)
{
  this->m_pPresetFaderPanel->DispatchCurve(this: this->m_pPresetFaderPanel, a2: 4);
}

//------------------------------------------------------------------------------
// Address: 0x1049A580
// Name: public: static char const __near * CSliderListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSliderListPanel::GetPanelClassName()
{
  return "CSliderListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1049A590
// Name: public: virtual void CSliderListPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSliderListPanel::OnMousePressed(CSliderListPanel *this, ButtonCode_t code)
{
  if ( code != MOUSE_RIGHT )
    CToolEntitySprinkle::RenderTool2D((vgui::TreeView *)this, itemIndex: code);
}

//------------------------------------------------------------------------------
// Address: 0x1049A5B0
// Name: public: virtual void CSliderListPanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSliderListPanel::OnMouseReleased(CSliderListPanel *this, ButtonCode_t code)
{
  if ( code == MOUSE_RIGHT )
    this->OnShowContextMenu(this);
  else
    CToolEntitySprinkle::RenderTool2D((vgui::TreeView *)this, itemIndex: code);
}

//------------------------------------------------------------------------------
// Address: 0x1049A5E0
// Name: public: CAddPresetDialog::CAddPresetDialog(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CAddPresetDialog *__thiscall CAddPresetDialog::CAddPresetDialog(CAddPresetDialog *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::TextEntry *v6; // eax
  vgui::TextEntry *v7; // eax
  vgui::ComboBox *v8; // eax
  vgui::ComboBox *v9; // eax
  vgui::CheckButton *v10; // eax
  vgui::CheckButton *v11; // eax

  vgui::BaseInputDialog::BaseInputDialog(this, parent, title: "Enter Preset Name", bShowCancelButton: true);
  this->__vftable = (CAddPresetDialog_vtbl *)&CAddPresetDialog::`vftable';
  if ( `CAddPresetDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CAddPresetDialog::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CAddPresetDialog");
    v3->pfnClassName = CAddPresetDialog::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::BaseInputDialog");
  }
  if ( `CAddPresetDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAddPresetDialog::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CAddPresetDialog");
    v4->pfnClassName = CAddPresetDialog::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::BaseInputDialog");
  }
  if ( `CAddPresetDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAddPresetDialog::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CAddPresetDialog");
    v5->pfnClassName = CAddPresetDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::BaseInputDialog");
  }
  v6 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v6 != nullptr )
    v7 = vgui::TextEntry::TextEntry(this: v6, parent: this, panelName: (vgui::Panel *)"PresetName");
  else
    v7 = nullptr;
  this->m_pPresetName = v7;
  v8 = (vgui::ComboBox *)operator new(nSize: 0x458u);
  if ( v8 != nullptr )
    v9 = vgui::ComboBox::ComboBox(
           this: v8,
           parent: this,
           panelName: (vgui::Panel *)"PresetGroup",
           numLines: 8,
           allowEdit: true);
  else
    v9 = nullptr;
  this->m_pPresetGroup = v9;
  v10 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v10 != nullptr )
    v11 = vgui::CheckButton::CheckButton(this: v10, parent: this, panelName: "Animated", text: "Animated");
  else
    v11 = nullptr;
  this->m_pAnimated = v11;
  vgui::Frame::SetDeleteSelfOnClose(this, state: false);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/addpresetdialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1049A750
// Name: public: virtual struct vgui::PanelMessageMap __near * CAddPresetDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAddPresetDialog::GetMessageMap(CAddPresetDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAddPresetDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAddPresetDialog::GetMessageMap'::`2'::s_pMap;
  `CAddPresetDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAddPresetDialog");
  `CAddPresetDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049A780
// Name: public: virtual struct PanelAnimationMap __near * CAddPresetDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAddPresetDialog::GetAnimMap(CAddPresetDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CAddPresetDialog");
}

//------------------------------------------------------------------------------
// Address: 0x1049A790
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAddPresetDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAddPresetDialog::GetKBMap(CAddPresetDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAddPresetDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAddPresetDialog::GetKBMap'::`2'::s_pMap;
  `CAddPresetDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAddPresetDialog");
  `CAddPresetDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049A7F0
// Name: public: void CPresetSlider::Init(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::Init(CPresetSlider *this, const char *pPresetGroupName, const char *pPresetName)
{
  CUtlSymbolLarge *v4; // eax
  const char *v5; // edi
  CUtlSymbolLarge *v6; // eax
  bool v7; // zf
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // eax
  CDmeAnimationSet *v9; // eax
  CDmePresetGroup *PresetGroup; // eax
  CDmePreset *Preset; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-8h] BYREF

  this->m_nProceduralType = 0;
  this->m_bReadOnly = false;
  v4 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &traversal.m_nIndex, a3: pPresetGroupName);
  v5 = pPresetName;
  this->m_presetGroupName = (CUtlSymbolLarge)v4->u.m_Id;
  v6 = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pPresetName, a3: v5);
  v7 = (_S1_49 & 1) == 0;
  this->m_presetName = (CUtlSymbolLarge)v6->u.m_Id;
  if ( v7 )
  {
    GetSymbol = g_pDataModel->GetSymbol;
    _S1_49 |= 1u;
    GetSymbol(this: g_pDataModel, result: &proceduralPresetGroupNameSym, a3: "Procedural");
  }
  if ( this->m_presetGroupName.u.m_Id == proceduralPresetGroupNameSym.u.m_Id )
  {
    this->m_nProceduralType = ProceduralTypeForPresetName(pPresetName: v5);
    this->m_bReadOnly = true;
  }
  else
  {
    traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pPresetFaderPanel->m_pController);
    traversal.m_nIndex = 0;
    while ( 1 )
    {
      v9 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      if ( v9 == nullptr )
        break;
      PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v9, pGroupName: pPresetGroupName);
      if ( PresetGroup != nullptr )
      {
        Preset = CDmePresetGroup::FindPreset(this: PresetGroup, pPresetName: v5);
        if ( Preset != nullptr )
        {
          this->m_bReadOnly = CDmePreset::IsReadOnly(this: Preset);
          break;
        }
      }
    }
  }
  vgui::Panel::SetName(this, panelName: v5);
  this->m_pName->SetText_2(this: this->m_pName, a2: v5);
  vgui::TextImage::ResizeImageToContent(this: this->m_pName);
  ((void (__thiscall *)(CPresetSlider *, int))this->SetBgColor)(a1: this, a2: -2139062144);
}

//------------------------------------------------------------------------------
// Address: 0x1049A930
// Name: protected: virtual void CPresetSlider::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnMouseReleased(CPresetSlider *this, ButtonCode_t code)
{
  int v3; // eax
  bool dragging; // bl
  float v5; // [esp+14h] [ebp+8h]

  this->m_bIgnoreCursorMovedEvents = false;
  if ( code == MOUSE_RIGHT )
  {
    this->OnShowContextMenu(this);
  }
  else if ( code == KEY_COUNT )
  {
    v3 = this->GetValue(this);
    dragging = this->_dragging;
    v5 = (float)v3 * 0.001;
    vgui::Slider::OnMouseReleased(this, code: KEY_COUNT);
    if ( dragging )
    {
      CBaseAnimationSetControl::ApplyPreset(
        this: this->m_pPresetFaderPanel->m_pController,
        flScale: v5,
        values: &this->m_AttributeLookup);
      this->SetCursor(this, a2: 2u);
    }
    if ( CPresetSlider::s_bResetMousePosOnMouseUp )
    {
      CPresetSlider::s_bResetMousePosOnMouseUp = false;
      g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: CPresetSlider::s_nMousePosX, a3: CPresetSlider::s_nMousePosY);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049A9F0
// Name: private: void CPresetSlider::OnRenameCompleted(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnRenameCompleted(CPresetSlider *this, const char *pText, KeyValues *pContextKeyValues)
{
  const char *v3; // edi
  const char *v5; // eax
  const char *PresetGroupName; // eax
  CDmeAnimationSet *v7; // edx
  const char *PresetName; // eax
  CDmePresetGroup *v9; // edx
  CDmePreset *Preset; // ebx
  const char *v11; // eax
  const char *v12; // [esp-4h] [ebp-14h]
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-8h] BYREF

  v3 = pText;
  if ( pText != nullptr && *pText != 0 )
  {
    v12 = pText;
    v5 = this->GetName(this);
    if ( _V_strcmp(s1: v5, s2: v12) != 0 )
    {
      g_pDataModel->StartUndo(this: g_pDataModel, a2: "Rename Preset", a3: "Rename Preset", a4: 0);
      g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Rename Preset", a3: 0, a4: 256);
      vgui::Panel::SetName(this, panelName: v3);
      this->m_pName->SetText_2(this: this->m_pName, a2: v3);
      vgui::TextImage::ResizeImageToContent(this: this->m_pName);
      this->m_presetName.u.m_Id = g_pDataModel->GetSymbol(this: g_pDataModel, result: &pText, a3: v3)->u.m_Id;
      traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pPresetFaderPanel->m_pController);
      traversal.m_nIndex = 0;
      while ( CAnimSetGroupAnimSetTraversal::Next(this: &traversal) != nullptr )
      {
        PresetGroupName = CPresetSlider::GetPresetGroupName(this);
        CDmeAnimationSet::FindPresetGroup(this: v7, pGroupName: PresetGroupName);
        PresetName = CPresetSlider::GetPresetName(this);
        Preset = CDmePresetGroup::FindPreset(this: v9, pPresetName: PresetName);
        g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pText, a3: v3);
        CDmAttribute::SetValue<CUtlSymbolLarge>(
          this: Preset->m_Name.m_pAttribute,
          value: (const CUtlSymbolLarge *)&pText);
      }
      g_pDataModel->FinishUndo(this: g_pDataModel);
      g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
    }
  }
  else
  {
    v11 = this->GetName(this);
    _Warning(a1: "Can't rename preset for %s to an empty name\n", v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049AB70
// Name: protected: virtual void CPresetSlider::OnInputCompleted(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnInputCompleted(CPresetSlider *this, KeyValues *pParams)
{
  char *String; // ebx
  KeyValues *Key; // eax

  String = KeyValues::GetString(this: pParams, keyName: "text", defaultValue: nullptr);
  Key = KeyValues::FindKey(this: pParams, keyName: "RenamePreset", bCreate: false);
  if ( Key != nullptr )
    CPresetSlider::OnRenameCompleted(this, pText: String, pContextKeyValues: Key);
}

//------------------------------------------------------------------------------
// Address: 0x1049ABB0
// Name: protected: virtual void CPresetSlider::OnShowContextMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPresetSlider::OnShowContextMenu(CPresetSlider *this@<ecx>, int a2@<edi>)
{
  vgui::Panel *v3; // eax
  vgui::Menu *v4; // eax
  CDragDropHelperPanel *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // ebx
  vgui::Panel *v8; // eax
  const char *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  vgui::Panel *v12; // eax
  vgui::Panel *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // ebx
  vgui::Panel *v16; // eax
  int v17; // ebx
  vgui::Panel *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // ebx
  vgui::Panel *v21; // eax
  vgui::Menu *v22; // eax

  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v3 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    if ( v3 != nullptr )
      ((void (__thiscall *)(vgui::Panel *, int))v3->dtr_Panel)(a1: v3, a2: 1);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hContextMenu,
      pPanel: nullptr);
  }
  v4 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v4 != nullptr )
    v5 = (CDragDropHelperPanel *)vgui::Menu::Menu(this: v4, parent: this, panelName: "ActionMenu");
  else
    v5 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hContextMenu,
    pPanel: v5);
  if ( !this->m_bReadOnly )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v7 = KeyValues::KeyValues(this: v6, setName: "OnRename");
    else
      v7 = nullptr;
    v8 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CPresetSlider *, _DWORD))v8->__vftable[1].PaintTraverse)(
      a1: v8,
      a2: "Rename...",
      a3: v7,
      a4: this,
      a5: 0);
    v9 = this->GetName(this);
    if ( _V_stricmp(s1: v9, s2: aDefa_0) != 0 )
    {
      v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v10 != nullptr )
        v11 = KeyValues::KeyValues(this: v10, setName: "OnDelete");
      else
        v11 = nullptr;
      v12 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CPresetSlider *, _DWORD))v12->__vftable[1].PaintTraverse)(
        a1: v12,
        a2: "Delete...",
        a3: v11,
        a4: this,
        a5: 0);
    }
    v13 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v13->__vftable[1].DeletePanel(this: v13);
  }
  v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v14 != nullptr )
    v15 = KeyValues::KeyValues(this: v14, setName: "ShowAddPresetDialog");
  else
    v15 = nullptr;
  v16 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  v17 = ((int (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimSetPresetFaderPanel *, _DWORD))v16->__vftable[1].PaintTraverse)(
          a1: v16,
          a2: "Add...",
          a3: v15,
          a4: this->m_pPresetFaderPanel,
          a5: 0);
  if ( CBaseAnimationSetControl::GetMostRecentlySelectedControl(this: this->m_pPresetFaderPanel->m_pController) == nullptr )
  {
    v18 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    ((void (__thiscall *)(vgui::Panel *, int, _DWORD))v18->__vftable[1].GetKBMap)(a1: v18, a2: v17, a3: 0);
  }
  v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v19 != nullptr )
    v20 = KeyValues::KeyValues(this: v19, setName: "ManagePresets");
  else
    v20 = nullptr;
  v21 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimSetPresetFaderPanel *, _DWORD))v21->__vftable[1].PaintTraverse)(
    a1: v21,
    a2: "Manage...",
    a3: v20,
    a4: this->m_pPresetFaderPanel,
    a5: 0);
  v22 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
  vgui::Menu::PlaceContextMenu(a1: a2, parent: this, menu: v22);
}

//------------------------------------------------------------------------------
// Address: 0x1049ADC0
// Name: private: void CPresetSlider::UpdateTickPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::UpdateTickPos(CPresetSlider *this, int x, int y)
{
  float v4; // xmm0_4
  int ty; // [esp+4h] [ebp-10h] BYREF
  int th; // [esp+8h] [ebp-Ch] BYREF
  int tw; // [esp+Ch] [ebp-8h] BYREF
  int tx; // [esp+10h] [ebp-4h] BYREF

  if ( !this->m_bIgnoreCursorMovedEvents )
  {
    this->GetTrackRect(this, a2: &tx, a3: &ty, a4: &tw, a5: &th);
    v4 = 0.0;
    if ( x > tx )
    {
      if ( x >= tx + tw || tw <= 0 )
        v4 = 1.0;
      else
        v4 = (float)(x - tx) / (float)tw;
    }
    this->SetValue(this, a2: (int)(float)((float)(v4 * 1000.0) + 0.5), a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049AE60
// Name: protected: virtual void CPresetSlider::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCursorMoved(CPresetSlider *this, int x, int y)
{
  CPresetSlider::UpdateTickPos(this, x, y);
}

//------------------------------------------------------------------------------
// Address: 0x1049AE70
// Name: protected: virtual void CPresetSlider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::ApplySchemeSettings(CPresetSlider *this, vgui::IScheme *scheme)
{
  vgui::TextImage_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::Slider::ApplySchemeSettings(this, pScheme: scheme);
  v3 = this->m_pName->__vftable;
  v4 = scheme->GetFont(this: scheme, a2: "DefaultBold", a3: false);
  v3->SetFont(this: this->m_pName, a2: v4);
  ((void (__thiscall *)(vgui::TextImage *, _DWORD))this->m_pName->SetColor)(
    a1: this->m_pName,
    a2: *(_DWORD *)&this->m_TextColor);
  vgui::TextImage::ResizeImageToContent(this: this->m_pName);
  ((void (__thiscall *)(CPresetSlider *, int))this->SetFgColor)(a1: this, a2: -16746302);
  this->SetThumbWidth(this, a2: 3);
}

//------------------------------------------------------------------------------
// Address: 0x1049AF00
// Name: private: virtual void CSliderListPanel::OnShowContextMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSliderListPanel::OnShowContextMenu(CSliderListPanel *this)
{
  vgui::Panel *v2; // eax
  vgui::Menu *v3; // eax
  CDragDropHelperPanel *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // ebx
  vgui::Panel *v7; // eax
  int v8; // ebx
  vgui::Panel *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  vgui::Panel *v12; // eax
  vgui::Menu *v13; // eax

  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    if ( v2 != nullptr )
      ((void (__thiscall *)(vgui::Panel *, int))v2->dtr_Panel)(a1: v2, a2: 1);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hContextMenu,
      pPanel: nullptr);
  }
  v3 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v3 != nullptr )
    v4 = (CDragDropHelperPanel *)vgui::Menu::Menu(this: v3, parent: this, panelName: "ActionMenu");
  else
    v4 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hContextMenu,
    pPanel: v4);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ShowAddPresetDialog");
  else
    v6 = nullptr;
  v7 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  v8 = ((int (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimSetPresetFaderPanel *, _DWORD))v7->__vftable[1].PaintTraverse)(
         a1: v7,
         a2: "Add...",
         a3: v6,
         a4: this->m_pPresetFaderPanel,
         a5: 0);
  if ( CBaseAnimationSetControl::GetMostRecentlySelectedControl(this: this->m_pPresetFaderPanel->m_pController) == nullptr )
  {
    v9 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    ((void (__thiscall *)(vgui::Panel *, int, _DWORD))v9->__vftable[1].GetKBMap)(a1: v9, a2: v8, a3: 0);
  }
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(this: v10, setName: "ManagePresets");
  else
    v11 = nullptr;
  v12 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimSetPresetFaderPanel *, _DWORD))v12->__vftable[1].PaintTraverse)(
    a1: v12,
    a2: "Manage...",
    a3: v11,
    a4: this->m_pPresetFaderPanel,
    a5: 0);
  v13 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
  vgui::Menu::PlaceContextMenu(a1: (int)this, parent: this, menu: v13);
}

//------------------------------------------------------------------------------
// Address: 0x1049B050
// Name: protected: virtual void CBaseAnimSetPresetFaderPanel::OnManagePresets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::OnManagePresets(CBaseAnimSetPresetFaderPanel *this)
{
  CDmePresetGroupEditorFrame *v2; // eax
  CDragDropHelperPanel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // ebx
  CDmeFilmClip *AnimationSetClip; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &this->m_hPresetEditor) == nullptr )
  {
    v2 = (CDmePresetGroupEditorFrame *)operator new(nSize: 0x224u);
    if ( v2 != nullptr )
      v3 = (CDragDropHelperPanel *)CDmePresetGroupEditorFrame::CDmePresetGroupEditorFrame(
                                     this: v2,
                                     pParent: this,
                                     pTitle: "Manage Presets");
    else
      v3 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hPresetEditor,
      pPanel: v3);
    v4 = vgui::PHandle::Get(this: &this->m_hPresetEditor);
    v4->AddActionSignalTarget_2(this: v4, a2: this);
    v5 = vgui::PHandle::Get(this: &this->m_hPresetEditor);
    v5->SetVisible(this: v5, a2: false);
    v6 = vgui::PHandle::Get(this: &this->m_hPresetEditor);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v6->__vftable[1].GetUnpackStructure)(a1: v6, a2: 0);
    v7 = vgui::PHandle::Get(this: &this->m_hPresetEditor);
    v7->__vftable[1].dtr_Panel(this: v7);
  }
  v8 = vgui::PHandle::Get(this: &this->m_hPresetEditor);
  AnimationSetClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  CDmePresetGroupEditorPanel::SetAnimationSetClip(
    this: (CDmePresetGroupEditorPanel *)v8[1].m_sNavUpName.m_Storage.m_nActualLength,
    pFilmClip: AnimationSetClip);
  v10 = vgui::PHandle::Get(this: &this->m_hPresetEditor);
  v10->__vftable[1].IsEnabled(this: v10);
}

//------------------------------------------------------------------------------
// Address: 0x1049B140
// Name: public: virtual void CBaseAnimSetPresetFaderPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::ApplySchemeSettings(
        CBaseAnimSetPresetFaderPanel *this,
        vgui::IScheme *scheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme: (int)scheme);
  ((void (__thiscall *)(CSliderListPanel *, int))this->m_pSliders->SetBgColor)(a1: this->m_pSliders, a2: -14013910);
}

//------------------------------------------------------------------------------
// Address: 0x1049B170
// Name: public: class CPresetSlider __near * CBaseAnimSetPresetFaderPanel::GetActivePresetSlider(void)
// Source: json
//------------------------------------------------------------------------------
CPresetSlider *__thiscall CBaseAnimSetPresetFaderPanel::GetActivePresetSlider(CBaseAnimSetPresetFaderPanel *this)
{
  return (CPresetSlider *)vgui::PHandle::Get(this: &this->m_hActivePresetSlider);
}

//------------------------------------------------------------------------------
// Address: 0x1049B1E0
// Name: protected: virtual void CPresetSlider::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPresetSlider::OnMousePressed(CPresetSlider *this@<ecx>, int a2@<ebx>, ButtonCode_t code)
{
  vgui::DHANDLE<CPresetSlider> *p_m_hActivePresetSlider; // ecx
  int th; // [esp+4h] [ebp-18h] BYREF
  int my; // [esp+8h] [ebp-14h] BYREF
  int mx; // [esp+Ch] [ebp-10h] BYREF
  int tw; // [esp+10h] [ebp-Ch] BYREF
  int ty; // [esp+14h] [ebp-8h] BYREF
  int tx; // [esp+18h] [ebp-4h] BYREF

  p_m_hActivePresetSlider = &this->m_pPresetFaderPanel->m_hActivePresetSlider;
  this->m_bIgnoreCursorMovedEvents = false;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)p_m_hActivePresetSlider,
    pPanel: (CDragDropHelperPanel *)this);
  if ( code == KEY_COUNT )
  {
    if ( this->_dragging )
    {
      this->OnMouseReleased(this, a2: KEY_COUNT);
    }
    else
    {
      vgui::Slider::OnMousePressed(this, a2, code: KEY_COUNT);
      if ( this->_dragging )
      {
        this->SetCursor(this, a2: 15u);
        g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my);
        this->GetTrackRect(this, a2: &tx, a3: &ty, a4: &tw, a5: &th);
        vgui::Panel::LocalToScreen(this, x: &tx, y: &ty);
        if ( mx < tx + tw )
        {
          if ( mx >= tx )
          {
            CPresetSlider::s_nMousePosX = mx;
            CPresetSlider::s_bResetMousePosOnMouseUp = true;
            CPresetSlider::s_nMousePosY = my;
            g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: tx, a3: my);
          }
          this->SetValue(this, a2: 0, a3: false);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049B2E0
// Name: protected: virtual void CPresetSlider::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCursorEntered(CPresetSlider *this)
{
  if ( !this->_dragging )
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_pPresetFaderPanel->m_hActivePresetSlider,
      pPanel: (CDragDropHelperPanel *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1049B300
// Name: protected: virtual void CPresetSlider::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCursorExited(CPresetSlider *this)
{
  if ( !this->_dragging )
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_pPresetFaderPanel->m_hActivePresetSlider,
      pPanel: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1049B320
// Name: protected: virtual void CPresetSlider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::Paint(CPresetSlider *this)
{
  bool v2; // al
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  int v5; // eax
  int x; // [esp+4h] [ebp-1Ch] BYREF
  int wide; // [esp+8h] [ebp-18h] BYREF
  int tall; // [esp+Ch] [ebp-14h] BYREF
  int y; // [esp+10h] [ebp-10h] BYREF
  Color col; // [esp+14h] [ebp-Ch] BYREF
  int mx; // [esp+18h] [ebp-8h] BYREF
  int my; // [esp+1Ch] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &this->m_pPresetFaderPanel->m_hActivePresetSlider) == this )
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
      || (v2 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
    {
      v2 = true;
    }
    if ( this->_dragging || v2 )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my);
      vgui::Panel::ScreenToLocal(this, x: &mx, y: &my);
      CPresetSlider::UpdateTickPos(this, x: mx, y: my);
      this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
      this->GetFgColor(this, result: &col);
      ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: col);
      v3 = g_pVGuiSurface;
      v4 = g_pVGuiSurface->__vftable;
      v5 = vgui::Panel::GetTall(this);
      v4->DrawFilledRect(this: v3, a2: this->_nobPos[0], a3: 1, a4: this->_nobPos[1], a5: v5 - 1);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->m_ZeroColor);
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: this->_nobPos[0] - 1,
        a3: y + 1,
        a4: this->_nobPos[0],
        a5: y + tall - 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049B460
// Name: protected: virtual void CPresetSlider::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPresetSlider::PaintBackground(CPresetSlider *this@<ecx>, int a2@<edi>)
{
  bool v3; // zf
  bool (__thiscall *IsKeyDown)(vgui::IInput *, ButtonCode_t); // eax
  bool v5; // al
  bool v6; // al
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // eax
  int (__thiscall *GetValue)(vgui::Slider *); // edx
  int v9; // eax
  int v10; // edi
  float v11; // xmm0_4
  vgui::ISurface_vtbl *v12; // edx
  void (__thiscall *DrawFilledRectFade)(vgui::ISurface *, int, int, int, int, unsigned int, unsigned int, bool); // edx
  Color m_TextColor; // eax
  Color m_GradientColor; // eax
  int cw; // [esp+8h] [ebp-30h] BYREF
  int w; // [esp+Ch] [ebp-2Ch] BYREF
  int v18; // [esp+10h] [ebp-28h] BYREF
  int h; // [esp+14h] [ebp-24h] BYREF
  __int64 v20; // [esp+18h] [ebp-20h]
  int tw; // [esp+20h] [ebp-18h] BYREF
  int th; // [esp+24h] [ebp-14h] BYREF
  int tx; // [esp+28h] [ebp-10h] BYREF
  int ty; // [esp+2Ch] [ebp-Ch] BYREF
  float v25; // [esp+30h] [ebp-8h]
  bool bIsAltKeyDown; // [esp+36h] [ebp-2h]
  bool bIsShiftKeyDown; // [esp+37h] [ebp-1h]

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v3 = vgui::PHandle::Get(this: &this->m_pPresetFaderPanel->m_hActivePresetSlider) == this;
  IsKeyDown = g_pVGuiInput->IsKeyDown;
  HIBYTE(v25) = v3;
  if ( IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (v5 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT), bIsShiftKeyDown = false, v5) )
  {
    bIsShiftKeyDown = true;
  }
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v6 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT), bIsAltKeyDown = false, v6) )
  {
    bIsAltKeyDown = true;
  }
  if ( HIBYTE(v25) == 0 )
  {
    m_TextColor = this->m_TextColor;
    goto LABEL_20;
  }
  if ( !this->_dragging && !bIsShiftKeyDown )
    goto LABEL_18;
  ((void (__thiscall *)(CPresetSlider *, int *, int *, int *, int *, int))this->GetTrackRect)(
    a1: this,
    a2: &tx,
    a3: &ty,
    a4: &tw,
    a5: &th,
    a6: a2);
  DrawSetColor = g_pVGuiSurface->DrawSetColor;
  v25 = -1.7014118e38;
  ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: -16777216);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: tx, a3: ty, a4: tx + tw, a5: ty + th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_GradientColor);
  tw -= 2;
  th -= 2;
  GetValue = this->GetValue;
  ++tx;
  ++ty;
  v9 = GetValue(this);
  v10 = (int)(float)((float)((float)tw * (float)((float)v9 * 0.001)) + 0.5);
  v11 = 15.0;
  if ( (float)((float)((float)this->GetValue(this) * 0.001) * 255.0) > 15.0 )
    v11 = (float)((float)this->GetValue(this) * 0.001) * 255.0;
  v3 = !this->_dragging;
  v25 = v11;
  if ( v3 )
  {
    if ( bIsAltKeyDown )
      m_GradientColor = this->m_GradientColor;
    else
      m_GradientColor = this->m_ZeroColor;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: m_GradientColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: tx, a3: ty, a4: tx + tw, a5: ty + th);
LABEL_18:
    m_TextColor = this->m_TextColorFocus;
    goto LABEL_20;
  }
  v12 = g_pVGuiSurface->__vftable;
  HIDWORD(v20) = HIWORD(v25) | 0xC00;
  DrawFilledRectFade = v12->DrawFilledRectFade;
  v20 = (__int64)v25;
  ((void (__thiscall *)(vgui::ISurface *, int, int, int, int, int, _DWORD))DrawFilledRectFade)(
    a1: g_pVGuiSurface,
    a2: tx,
    a3: ty,
    a4: v10 + tx,
    a5: ty + th,
    a6: 15,
    a7: v20);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_ZeroColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v10 + tx + 1, a3: ty, a4: tx + tw, a5: th + ty);
  m_TextColor = this->m_TextColorFocus;
LABEL_20:
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pName->SetColor)(a1: this->m_pName, a2: m_TextColor);
  this->m_pName->GetContentSize(this: this->m_pName, a2: &cw, a3: &v18);
  this->m_pName->SetPos(
    this: this->m_pName,
    a2: (int)(float)((float)(w - cw) * 0.5),
    a3: (int)(float)((float)(h - v18) * 0.5));
  this->m_pName->Paint(this: this->m_pName);
}

//------------------------------------------------------------------------------
// Address: 0x1049B780
// Name: protected: void CBaseAnimSetPresetFaderPanel::AddPreset(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::AddPreset(
        CBaseAnimSetPresetFaderPanel *this,
        const char *pPresetGroupName,
        const char *pPresetName,
        bool bAnimated)
{
  const char *v4; // edi
  vgui::MessageBox *v5; // esi
  CDmeAnimationSet *v7; // esi
  CDmePresetGroup *PresetGroup; // edi
  vgui::MessageBox *v9; // eax
  vgui::MessageBox *v10; // esi
  vgui::MessageBox *v11; // eax
  vgui::MessageBox *v12; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-8h] BYREF

  v4 = pPresetName;
  v5 = nullptr;
  if ( pPresetName == nullptr || *pPresetName == 0 )
  {
    v12 = (vgui::MessageBox *)operator new(nSize: 0x234u);
    if ( v12 != nullptr )
      v5 = vgui::MessageBox::MessageBox(
             this: v12,
             title: "Add Preset Error",
             text: "Can't add preset with an empty name\n",
             parent: this);
    v5->SetDeleteSelfOnClose(this: v5, a2: true);
    v5->DoModal_2(this: v5, a2: nullptr);
    return;
  }
  if ( CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController) == nullptr )
    return;
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  traversal.m_nIndex = 0;
  v7 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  if ( v7 == nullptr )
  {
LABEL_11:
    CBaseAnimationSetControl::AddPreset(this: this->m_pController, pPresetGroupName, pPresetName: v4, bAnimated);
    return;
  }
  while ( 1 )
  {
    PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v7, pGroupName: pPresetGroupName);
    if ( PresetGroup != nullptr
      && (unsigned int)CBaseAnimationSetControl::GetSelectionState(this: this->m_pController, pAnimSet: v7) >= SELECT_MORPH )
    {
      if ( PresetGroup->m_bIsReadOnly.m_Storage )
      {
        v9 = (vgui::MessageBox *)operator new(nSize: 0x234u);
        if ( v9 != nullptr )
        {
          v10 = vgui::MessageBox::MessageBox(
                  this: v9,
                  title: "Add Preset Error",
                  text: "Can't add preset to a read-only preset group!\n",
                  parent: this);
          goto LABEL_15;
        }
        goto LABEL_14;
      }
      if ( CDmePresetGroup::FindPreset(this: PresetGroup, pPresetName) != nullptr )
        break;
    }
    v7 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v7 == nullptr )
    {
      v4 = pPresetName;
      goto LABEL_11;
    }
  }
  v11 = (vgui::MessageBox *)operator new(nSize: 0x234u);
  if ( v11 == nullptr )
  {
LABEL_14:
    v10 = nullptr;
    goto LABEL_15;
  }
  v10 = vgui::MessageBox::MessageBox(
          this: v11,
          title: "Add Preset Error",
          text: "A preset with that name already exists!\n",
          parent: this);
LABEL_15:
  v10->SetDeleteSelfOnClose(this: v10, a2: true);
  v10->DoModal_2(this: v10, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1049B900
// Name: public: void CBaseAnimSetPresetFaderPanel::GetPreviewFader(struct FaderPreview_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::GetPreviewFader(
        CBaseAnimSetPresetFaderPanel *this,
        FaderPreview_t *fader)
{
  FaderPreview_t *v2; // esi
  vgui::Panel *v4; // eax
  _DWORD *v5; // edi
  bool v6; // al
  int mx; // [esp+Ch] [ebp-4h] BYREF

  v2 = fader;
  _V_memset(dest: (unsigned __int8 *)fader, fill: 0, count: 0x14u);
  *(_WORD *)&v2->isbeingdragged = 0;
  v4 = vgui::PHandle::Get(this: &this->m_hActivePresetSlider);
  v5 = &v4->__vftable;
  if ( v4 != nullptr )
  {
    v2->isbeingdragged = HIBYTE(v4[1].__vftable);
    v6 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT);
    v2->holdingPreviewKey = v6;
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: (int *)&fader);
    if ( !vgui::Panel::IsWithin(this, x: mx, y: (int)fader) )
      v2->holdingPreviewKey = false;
    v2->name = (const char *)(*(int (__thiscall **)(_DWORD *))(*v5 + 72))(a1: v5);
    v2->amount = (float)(*(int (__thiscall **)(_DWORD *))(*v5 + 848))(a1: v5) * 0.001;
    v2->values = (CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short> *)(v5 + 117);
    v2->nProceduralType = v5[126];
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049B9E0
// Name: public: void CBaseAnimSetPresetFaderPanel::UpdateProceduralPresetSlider(class CUtlMap<enum DmElementHandle_t,struct AnimationControlAttributes_t,unsigned short> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::UpdateProceduralPresetSlider(
        CBaseAnimSetPresetFaderPanel *this,
        CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short> *values)
{
  vgui::Panel *v3; // eax
  int v4; // eax

  v3 = vgui::PHandle::Get(this: &this->m_hActivePresetSlider);
  if ( v3 != nullptr )
  {
    v4 = *((_DWORD *)&v3[1] + 43);
    if ( v4 > 0 && v4 <= 7 )
      this->m_pController->ProceduralPreset_UpdateCrossfade(this: this->m_pController, a2: values, a3: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049BBB0
// Name: void CollectPresetGroupInfo(class CDmeFilmClip __near *,class CUtlVector<struct PresetGroupInfo_t,class CUtlMemory<struct PresetGroupInfo_t,int>> __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollectPresetGroupInfo(
        CDmeFilmClip *pFilmClip,
        CUtlMemory<vgui::PropertySheet::Page_t,int> *presetInfo,
        bool bSkipReadOnly,
        bool bSkipInvisible)
{
  CDmeAnimationSet *j; // eax
  CDmaElementArray<CDmePresetGroup> *v5; // esi
  CDmAttribute *m_pAttribute; // eax
  DmElementArray_t *m_pData; // eax
  int v8; // ecx
  CDmElement *v9; // eax
  CDmElement *v10; // esi
  const char *m_pAsString; // eax
  char v12; // cl
  CDmAttribute *Attribute; // eax
  CDmAttribute *v14; // esi
  CDmaVar<bool> *v15; // eax
  bool m_Storage; // bl
  int m_pMemory; // esi
  int v18; // eax
  PresetGroupInfo_t *v19; // ecx
  int m_nAllocationCount; // eax
  PresetGroupInfo_t *v21; // ecx
  int v22; // eax
  PresetGroupInfo_t *v23; // eax
  bool bGroupReadOnly; // cl
  bool bGroupVisible; // dl
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-20h] BYREF
  PresetGroupInfo_t info; // [esp+14h] [ebp-18h]
  CDmrElementArray<CDmePresetGroup> presetGroups; // [esp+1Ch] [ebp-10h] BYREF
  int i; // [esp+24h] [ebp-8h]
  CUtlSymbolLarge::<unnamed_type_u> v30; // [esp+28h] [ebp-4h] BYREF
  CDmeFilmClip *pFilmClipa; // [esp+34h] [ebp+8h]

  traversal.m_pFilmClip = pFilmClip;
  traversal.m_nIndex = 0;
  for ( j = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        j != nullptr;
        j = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
  {
    v5 = CDmeAnimationSet::GetPresetGroups(this: j);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroups);
    m_pAttribute = v5->m_pAttribute;
    if ( m_pAttribute != nullptr && (m_pAttribute->m_nFlags & 0x1F) == 0xF )
    {
      presetGroups.m_pAttribute = v5->m_pAttribute;
      m_pData = (DmElementArray_t *)m_pAttribute->m_pData;
      presetGroups.m_pStorage = m_pData;
      pFilmClipa = (CDmeFilmClip *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      presetGroups.m_pAttribute = nullptr;
      presetGroups.m_pStorage = nullptr;
      pFilmClipa = nullptr;
    }
    v8 = 0;
    i = 0;
    if ( (int)pFilmClipa > 0 )
    {
      while ( 1 )
      {
        v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pData->m_Memory.m_pMemory[v8]);
        v10 = v9;
        if ( v9 != nullptr
          && v9->IsA(this: v9, a2: CDmePresetGroup::m_classType)
          && (!bSkipReadOnly || v10[1].m_Id.m_Value[4] == 0)
          && (!bSkipInvisible || LOBYTE(v10[1].__vftable) != 0) )
        {
          m_pAsString = v10->m_Name.m_Storage.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = &var;
          g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&v30, a3: m_pAsString);
          v12 = (char)v10[1].__vftable;
          info.bGroupReadOnly = v10[1].m_Id.m_Value[4];
          info.bGroupVisible = v12;
          if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
            `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
          }
          Attribute = CDmElement::FindAttribute(this: v10, pAttributeName: "shared");
          v14 = Attribute;
          if ( Attribute != nullptr )
          {
            if ( (`CDmAttribute::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
            {
              `CDmAttribute::GetValue<bool>'::`2'::`local static guard' |= 1u;
              `CDmAttribute::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
              `CDmAttribute::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
            }
            if ( (Attribute->m_nFlags & 0x1F) == 4 )
            {
              v15 = (CDmaVar<bool> *)Attribute->m_pData;
            }
            else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
            {
              CDmAttribute::CopyDataOut<bool>(this: v14, value: &`CDmAttribute::GetValue<bool>'::`7'::tempVal);
              v15 = (CDmaVar<bool> *)&`CDmAttribute::GetValue<bool>'::`7'::tempVal;
            }
            else
            {
              v15 = &`CDmAttribute::GetValue<bool>'::`2'::defaultVal;
            }
          }
          else
          {
            v15 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
          }
          m_Storage = v15->m_Storage;
          m_pMemory = (int)presetInfo[1].m_pMemory;
          v18 = 0;
          if ( m_pMemory <= 0 )
            goto LABEL_34;
          v19 = (PresetGroupInfo_t *)presetInfo->m_pMemory;
          while ( v19->presetGroupSym.u.m_Id != v30.m_Id )
          {
            ++v18;
            ++v19;
            if ( v18 >= m_pMemory )
              goto LABEL_34;
          }
          if ( v18 == -1 )
          {
LABEL_34:
            m_nAllocationCount = presetInfo->m_nAllocationCount;
            if ( m_pMemory + 1 > m_nAllocationCount )
              CUtlMemory<CacheOptimizedKDNode,int>::Grow(this: presetInfo, num: m_pMemory - m_nAllocationCount + 1);
            ++presetInfo[1].m_pMemory;
            v21 = (PresetGroupInfo_t *)presetInfo->m_pMemory;
            v22 = (int)presetInfo[1].m_pMemory - m_pMemory - 1;
            presetInfo[1].m_nAllocationCount = (int)presetInfo->m_pMemory;
            if ( v22 > 0 )
              _V_memmove(
                dest: (unsigned __int8 *)&v21[m_pMemory + 1],
                src: (unsigned __int8 *)&v21[m_pMemory],
                count: 8 * v22);
            v23 = (PresetGroupInfo_t *)&presetInfo->m_pMemory[m_pMemory];
            if ( v23 != nullptr )
            {
              bGroupReadOnly = info.bGroupReadOnly;
              v23->presetGroupSym.u = v30;
              bGroupVisible = info.bGroupVisible;
              v23->bGroupShared = m_Storage;
              v23->bGroupReadOnly = bGroupReadOnly;
              v23->bGroupVisible = bGroupVisible;
            }
          }
        }
        v8 = i + 1;
        i = v8;
        if ( v8 >= (int)pFilmClipa )
          break;
        m_pData = presetGroups.m_pStorage;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049BDE0
// Name: void CollectProceduralPresetNames(class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollectProceduralPresetNames(CUtlMemory<vgui::TreeNode *,int> *presetNames)
{
  int m_pMemory; // esi
  int m_nAllocationCount; // ecx
  CUtlSymbolLarge *v4; // ecx
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  int i; // edx
  _DWORD *v9; // eax
  int v10; // ebx
  const char *v11; // eax
  _DWORD *v12; // esi
  _BYTE v13[4]; // [esp+0h] [ebp-4h] BYREF
  int v14; // [esp+Ch] [ebp+8h]

  if ( (`CollectProceduralPresetNames'::`2'::`local static guard' & 1) == 0 )
  {
    `CollectProceduralPresetNames'::`2'::`local static guard' |= 1u;
    g_pDataModel->GetSymbol(
      this: g_pDataModel,
      result: &`CollectProceduralPresetNames'::`2'::proceduralPresetGroupNameSymbol,
      a3: "Procedural");
  }
  m_pMemory = (int)presetNames[1].m_pMemory;
  m_nAllocationCount = presetNames->m_nAllocationCount;
  if ( m_pMemory + 20 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: presetNames, num: m_pMemory - m_nAllocationCount + 20);
  presetNames[1].m_pMemory += 5;
  v4 = (CUtlSymbolLarge *)presetNames->m_pMemory;
  v5 = (int)presetNames[1].m_pMemory - m_pMemory - 20;
  presetNames[1].m_nAllocationCount = (int)presetNames->m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v4[m_pMemory + 20], src: (unsigned __int8 *)&v4[m_pMemory], count: 4 * v5);
  v6 = 4 * m_pMemory;
  v7 = v6;
  for ( i = 20; i != 0; --i )
  {
    v9 = (vgui::TreeNode **)((char *)presetNames->m_pMemory + v7);
    if ( v9 != nullptr )
      *v9 = -1;
    v7 += 4;
  }
  v10 = 1;
  v14 = v6;
  do
  {
    if ( (unsigned int)v10 > 0x14 )
      v11 = "???";
    else
      v11 = g_ProceduralPresetNames_12[v10];
    v12 = (vgui::TreeNode **)((char *)presetNames->m_pMemory + v14);
    v14 += 4;
    ++v10;
    *v12 = *(_DWORD *)((int (__stdcall *)(_BYTE *, const char *))g_pDataModel->GetSymbol)(a1: v13, a2: v11);
  }
  while ( v10 < 21 );
}

//------------------------------------------------------------------------------
// Address: 0x1049BEE0
// Name: void CollectPresetNamesForGroup(class CDmeFilmClip __near *,char const __near *,class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollectPresetNamesForGroup(
        CDmeFilmClip *pFilmClip,
        const char *pPresetGroupName,
        CUtlMemory<vgui::TreeNode *,int> *presetNames)
{
  int v3; // ebx
  CDmeAnimationSet *i; // eax
  CDmeTransformControl *PresetGroup; // eax
  CDmaVar<Vector> *Position; // edi
  float z; // eax
  DmElementArray_t *m_pStorage; // eax
  CDmElement *v9; // eax
  CDmElement *v10; // edi
  const char *m_pAsString; // eax
  int m_pMemory; // edi
  int v13; // eax
  CUtlSymbolLarge *v14; // ecx
  int m_nAllocationCount; // eax
  CUtlSymbolLarge *v16; // ecx
  int v17; // eax
  CUtlSymbolLarge *v18; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-14h] BYREF
  CDmrElementArray<CDmePreset> presets; // [esp+14h] [ebp-Ch] BYREF
  CUtlSymbolLarge symPresetName; // [esp+1Ch] [ebp-4h] BYREF
  CDmeFilmClip *pFilmClipa; // [esp+28h] [ebp+8h]

  v3 = 0;
  traversal.m_pFilmClip = pFilmClip;
  traversal.m_nIndex = 0;
  for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal); i != nullptr; v3 = 0 )
  {
    PresetGroup = (CDmeTransformControl *)CDmeAnimationSet::FindPresetGroup(this: i, pGroupName: pPresetGroupName);
    if ( PresetGroup != nullptr )
    {
      Position = CDmeTransformControl::GetPosition(this: PresetGroup);
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
      z = Position[1].m_Storage.z;
      if ( z == 0.0 || (*(_BYTE *)(LODWORD(z) + 16) & 0x1F) != 0xF )
      {
        m_pStorage = nullptr;
        presets.m_pAttribute = nullptr;
        presets.m_pStorage = nullptr;
        pFilmClipa = nullptr;
      }
      else
      {
        presets.m_pAttribute = (CDmAttribute *)LODWORD(Position[1].m_Storage.z);
        m_pStorage = *(DmElementArray_t **)(LODWORD(z) + 4);
        presets.m_pStorage = m_pStorage;
        pFilmClipa = (CDmeFilmClip *)m_pStorage->m_Size;
      }
      if ( (int)pFilmClipa > 0 )
      {
        while ( 1 )
        {
          v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_pStorage->m_Memory.m_pMemory[v3]);
          v10 = v9;
          if ( v9 != nullptr && v9->IsA(this: v9, a2: CDmePreset::m_classType) )
          {
            m_pAsString = v10->m_Name.m_Storage.u.m_pAsString;
            if ( m_pAsString == (const char *)-1 )
              m_pAsString = &var;
            g_pDataModel->GetSymbol(this: g_pDataModel, result: &symPresetName, a3: m_pAsString);
            m_pMemory = (int)presetNames[1].m_pMemory;
            v13 = 0;
            if ( m_pMemory <= 0 )
              goto LABEL_20;
            v14 = (CUtlSymbolLarge *)presetNames->m_pMemory;
            while ( v14->u.m_Id != symPresetName.u.m_Id )
            {
              ++v13;
              ++v14;
              if ( v13 >= m_pMemory )
                goto LABEL_20;
            }
            if ( v13 == -1 )
            {
LABEL_20:
              m_nAllocationCount = presetNames->m_nAllocationCount;
              if ( m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: presetNames, num: m_pMemory - m_nAllocationCount + 1);
              ++presetNames[1].m_pMemory;
              v16 = (CUtlSymbolLarge *)presetNames->m_pMemory;
              v17 = (int)presetNames[1].m_pMemory - m_pMemory - 1;
              presetNames[1].m_nAllocationCount = (int)presetNames->m_pMemory;
              if ( v17 > 0 )
                _V_memmove(
                  dest: (unsigned __int8 *)&v16[m_pMemory + 1],
                  src: (unsigned __int8 *)&v16[m_pMemory],
                  count: 4 * v17);
              v18 = (CUtlSymbolLarge *)&presetNames->m_pMemory[m_pMemory];
              if ( v18 != nullptr )
                v18->u.m_Id = symPresetName.u.m_Id;
            }
          }
          if ( ++v3 >= (int)pFilmClipa )
            break;
          m_pStorage = presets.m_pStorage;
        }
      }
    }
    i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049C060
// Name: public: static void CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnShowAddPresetDialog::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnShowAddPresetDialog::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnShowAddPresetDialog::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnShowAddPresetDialog::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ShowAddPresetDialog";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049C0F0
// Name: public: static void CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetsChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetsChanged::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetsChanged::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetsChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSnapshotGrid::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PresetsChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049C180
// Name: public: static void CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnManagePresets::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnManagePresets::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnManagePresets::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnManagePresets::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ManagePresets";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049C210
// Name: public: static void CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetNameSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetNameSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetNameSelected::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetNameSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PresetNameSelected";
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
// Address: 0x1049C2A0
// Name: public: static void CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPageChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPageChanged::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
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
// Address: 0x1049C330
// Name: public: static void CPresetSlider::KB_AddToMap(char const __near *,enum ButtonCode_t,int,void (vgui::Panel::*)(void),char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPresetSlider::KB_AddToMap(
        const char *a1@<ebp>,
        const char *bindingname,
        ButtonCode_t defaultcode,
        int default_modifiers,
        __int128 function,
        __int64 helpstring,
        bool passive)
{
  vgui::PanelKeyBindingMap *v7; // esi
  _DWORD v8[3]; // [esp-Ch] [ebp-4Ch] BYREF
  vgui::KeyBindingMap_t entry; // [esp+0h] [ebp-40h] BYREF
  vgui::BoundKey_t kb; // [esp+30h] [ebp-10h]
  int retaddr; // [esp+40h] [ebp+0h]

  kb.bindingname = a1;
  kb.keycode = retaddr;
  v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetSlider");
  vgui::KeyBindingMap_t::KeyBindingMap_t(this: (vgui::KeyBindingMap_t *)v8);
  *(_OWORD *)(&entry.bindingname + 1) = function;
  *(_QWORD *)((char *)&entry.func + 4) = helpstring;
  v8[0] = bindingname;
  BYTE12(entry.func) = passive;
  CUtlVector<vgui::KeyBindingMap_t,CUtlMemory<vgui::KeyBindingMap_t,int>>::InsertBefore(
    this: &v7->entries,
    elem: v7->entries.m_Size,
    src: (const vgui::KeyBindingMap_t *)v8);
  vgui::BoundKey_t::BoundKey_t(this: (vgui::BoundKey_t *)&entry.docstring);
  *((_DWORD *)&entry.passive + 1) = defaultcode;
  LOBYTE(entry.docstring) = 1;
  *(_DWORD *)&entry.passive = bindingname;
  *(_DWORD *)&kb.isbuiltin = default_modifiers;
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
    this: &v7->defaultkeys,
    elem: v7->defaultkeys.m_Size,
    src: (const vgui::BoundKey_t *)&entry.docstring);
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
    this: &v7->boundkeys,
    elem: v7->boundkeys.m_Size,
    src: (const vgui::BoundKey_t *)&entry.docstring);
  vgui::BoundKey_t::~BoundKey_t(this: (vgui::BoundKey_t *)&entry.docstring);
  CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)v8);
}

//------------------------------------------------------------------------------
// Address: 0x1049C400
// Name: public: static void CPresetSlider::PanelMessageFunc_OnShowContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPresetSlider::PanelMessageFunc_OnShowContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CPresetSlider::PanelMessageFunc_OnShowContextMenu::InitVar'::`2'::bAdded )
  {
    `CPresetSlider::PanelMessageFunc_OnShowContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnShowContextMenu";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049C490
// Name: public: static void CPresetSlider::PanelMessageFunc_OnRename::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPresetSlider::PanelMessageFunc_OnRename::InitVar(int a1@<ebp>)
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
  if ( !`CPresetSlider::PanelMessageFunc_OnRename::InitVar'::`2'::bAdded )
  {
    `CPresetSlider::PanelMessageFunc_OnRename::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnRename";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049C520
// Name: public: static void CPresetSlider::PanelMessageFunc_OnDelete::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPresetSlider::PanelMessageFunc_OnDelete::InitVar(int a1@<ebp>)
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
  if ( !`CPresetSlider::PanelMessageFunc_OnDelete::InitVar'::`2'::bAdded )
  {
    `CPresetSlider::PanelMessageFunc_OnDelete::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{400,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnDelete";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049C5B0
// Name: public: static void CPresetSlider::PanelMessageFunc_OnInputCompleted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPresetSlider::PanelMessageFunc_OnInputCompleted::InitVar(int a1@<ebp>)
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
  if ( !`CPresetSlider::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded )
  {
    `CPresetSlider::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSnapshotGrid::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
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
// Address: 0x1049C640
// Name: public: static void CPresetSlider::PanelMessageFunc_OnDeleteConfirmed::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPresetSlider::PanelMessageFunc_OnDeleteConfirmed::InitVar(int a1@<ebp>)
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
  if ( !`CPresetSlider::PanelMessageFunc_OnDeleteConfirmed::InitVar'::`2'::bAdded )
  {
    `CPresetSlider::PanelMessageFunc_OnDeleteConfirmed::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnDeleteConfirmed";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049C6D0
// Name: public: void CAddPresetDialog::DoModal(class CDmeFilmClip __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAddPresetDialog::DoModal(
        CAddPresetDialog *this,
        CDmeFilmClip *pFilmClip,
        const char *pCurrentGroupName,
        KeyValues *pContextKeyValues)
{
  KeyValues *v5; // esi
  char *m_Id; // edi
  KeyValues *v7; // eax
  int v8; // esi
  CUtlVector<PresetGroupInfo_t,CUtlMemory<PresetGroupInfo_t,int> > presetGroupInfo; // [esp+8h] [ebp-14h] BYREF
  int i; // [esp+24h] [ebp+8h]

  vgui::ComboBox::RemoveAll(this: this->m_pPresetGroup);
  v5 = nullptr;
  memset(&presetGroupInfo, 0, sizeof(presetGroupInfo));
  CollectPresetGroupInfo(
    pFilmClip,
    presetInfo: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&presetGroupInfo,
    bSkipReadOnly: true,
    bSkipInvisible: false);
  for ( i = 0; i < presetGroupInfo.m_Size; ++i )
  {
    m_Id = (char *)presetGroupInfo.m_Memory.m_pMemory[i].presetGroupSym.u.m_Id;
    if ( m_Id == (char *)-1 )
      m_Id = (char *)&var;
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v5 = KeyValues::KeyValues(this: v7, setName: "entry");
    KeyValues::SetString(this: v5, keyName: "presetGroupName", value: m_Id);
    v8 = this->m_pPresetGroup->AddItem_2(this: this->m_pPresetGroup, a2: m_Id, a3: v5);
    if ( pCurrentGroupName != nullptr && _V_stricmp(s1: m_Id, s2: pCurrentGroupName) == 0 )
      this->m_pPresetGroup->ActivateItem(this: this->m_pPresetGroup, a2: v8);
    v5 = nullptr;
  }
  vgui::BaseInputDialog::DoModal(this, pContextKeyValues);
  this->m_pPresetName->SetText(this: this->m_pPresetName, a2: &var);
  this->m_pPresetName->RequestFocus(this: this->m_pPresetName, a2: 0);
  vgui::Frame::PlaceUnderCursor(this);
  if ( presetGroupInfo.m_Memory.m_nGrowSize >= 0 && presetGroupInfo.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: presetGroupInfo.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1049C800
// Name: public: virtual struct vgui::PanelMessageMap __near * CPresetSlider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPresetSlider::GetMessageMap(CPresetSlider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPresetSlider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPresetSlider::GetMessageMap'::`2'::s_pMap;
  `CPresetSlider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
  `CPresetSlider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049C830
// Name: public: virtual struct PanelAnimationMap __near * CPresetSlider::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPresetSlider::GetAnimMap(CPresetSlider *this)
{
  return FindOrAddPanelAnimationMap(className: "CPresetSlider");
}

//------------------------------------------------------------------------------
// Address: 0x1049C840
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPresetSlider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPresetSlider::GetKBMap(CPresetSlider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPresetSlider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPresetSlider::GetKBMap'::`2'::s_pMap;
  `CPresetSlider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetSlider");
  `CPresetSlider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049C870
// Name: public: static void CSliderListPanel::PanelMessageFunc_OnShowContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSliderListPanel::PanelMessageFunc_OnShowContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CSliderListPanel::PanelMessageFunc_OnShowContextMenu::InitVar'::`2'::bAdded )
  {
    `CSliderListPanel::PanelMessageFunc_OnShowContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::RichText::`vcall'{872,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSliderListPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnShowContextMenu";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049C900
// Name: public: CSliderListPanel::CSliderListPanel(class CBaseAnimSetPresetFaderPanel __near *,class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSliderListPanel *__thiscall CSliderListPanel::CSliderListPanel(
        CSliderListPanel *this,
        CBaseAnimSetPresetFaderPanel *pFader,
        vgui::Panel *pParent,
        const char *panelName)
{
  vgui::PanelMessageMap *v5; // esi
  PanelAnimationMap *v6; // esi
  vgui::PanelKeyBindingMap *v7; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::PanelListPanel::PanelListPanel(this, parent: pParent, panelName);
  this->__vftable = (CSliderListPanel_vtbl *)&CSliderListPanel::`vftable';
  if ( `CSliderListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CSliderListPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CSliderListPanel");
    v5->pfnClassName = CSliderListPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PanelListPanel");
  }
  if ( `CSliderListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSliderListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CSliderListPanel");
    v6->pfnClassName = CSliderListPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PanelListPanel");
  }
  if ( `CSliderListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSliderListPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CSliderListPanel");
    v7->pfnClassName = CSliderListPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PanelListPanel");
  }
  CSliderListPanel::PanelMessageFunc_OnShowContextMenu::InitVar(a1: (int)&savedregs);
  this->m_hContextMenu.m_iPanelID = -1;
  this->m_pPresetFaderPanel = pFader;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1049C9E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CSliderListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSliderListPanel::GetMessageMap(CSliderListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSliderListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSliderListPanel::GetMessageMap'::`2'::s_pMap;
  `CSliderListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSliderListPanel");
  `CSliderListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049CA10
// Name: public: virtual struct PanelAnimationMap __near * CSliderListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSliderListPanel::GetAnimMap(CSliderListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CSliderListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1049CA20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSliderListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSliderListPanel::GetKBMap(CSliderListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSliderListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSliderListPanel::GetKBMap'::`2'::s_pMap;
  `CSliderListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSliderListPanel");
  `CSliderListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049CA50
// Name: protected: virtual void CBaseAnimSetPresetFaderPanel::OnShowAddPresetDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::OnShowAddPresetDialog(CBaseAnimSetPresetFaderPanel *this)
{
  CAddPresetDialog *v2; // eax
  CAddPresetDialog *v3; // edi
  vgui::Panel *v4; // eax
  const char *v5; // eax
  CDmeFilmClip *AnimationSetClip; // eax
  const char *v7; // [esp-Ch] [ebp-10h]

  if ( CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController) != nullptr )
  {
    v2 = (CAddPresetDialog *)operator new(nSize: 0x230u);
    if ( v2 != nullptr )
      v3 = CAddPresetDialog::CAddPresetDialog(this: v2, parent: this);
    else
      v3 = nullptr;
    v3->AddActionSignalTarget_2(this: v3, a2: this);
    if ( this->m_pSheet->GetActivePage(this: this->m_pSheet) != nullptr )
    {
      v4 = this->m_pSheet->GetActivePage(this: this->m_pSheet);
      v5 = v4->GetName(this: v4);
    }
    else
    {
      v5 = &var;
    }
    v7 = v5;
    AnimationSetClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
    CAddPresetDialog::DoModal(this: v3, pFilmClip: AnimationSetClip, pCurrentGroupName: v7, pContextKeyValues: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049CC20
// Name: public: CPresetSlider::CPresetSlider(class vgui::Panel __near *,class CBaseAnimSetPresetFaderPanel __near *)
// Source: json
//------------------------------------------------------------------------------
CPresetSlider *__thiscall CPresetSlider::CPresetSlider(
        CPresetSlider *this,
        vgui::Panel *parent,
        CBaseAnimSetPresetFaderPanel *pFaderPanel)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax
  __int128 v11; // [esp-1Ch] [ebp-38h]
  __int128 v12; // [esp-1Ch] [ebp-38h]
  __int128 v13; // [esp-1Ch] [ebp-38h]
  __int128 v14; // [esp-1Ch] [ebp-38h]
  __int64 v15; // [esp+14h] [ebp-8h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  vgui::Slider::Slider(this, parent, panelName: "preset");
  this->__vftable = (CPresetSlider_vtbl *)&CPresetSlider::`vftable';
  if ( `CPresetSlider::ChainToMap'::`2'::chained == 0 )
  {
    `CPresetSlider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
    v4->pfnClassName = CPresetSlider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Slider");
  }
  if ( `CPresetSlider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPresetSlider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CPresetSlider");
    v5->pfnClassName = CPresetSlider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Slider");
  }
  if ( `CPresetSlider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPresetSlider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetSlider");
    v6->pfnClassName = CPresetSlider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Slider");
  }
  CPresetSlider::PanelMessageFunc_OnShowContextMenu::InitVar(a1: (int)&savedregs);
  CPresetSlider::PanelMessageFunc_OnRename::InitVar(a1: (int)&savedregs);
  CPresetSlider::PanelMessageFunc_OnDelete::InitVar(a1: (int)&savedregs);
  CPresetSlider::PanelMessageFunc_OnInputCompleted::InitVar(a1: (int)&savedregs);
  CPresetSlider::PanelMessageFunc_OnDeleteConfirmed::InitVar(a1: (int)&savedregs);
  if ( `CPresetSlider::PanelKBMapFunc_ts_curve_1::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v11 = (unsigned int) __thiscall CParticleSystemPreviewPanel::`vcall'{960,{flat}};
    v15 = 0;
    `CPresetSlider::PanelKBMapFunc_ts_curve_1::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v11 + 1) = 0;
    CPresetSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_1",
      defaultcode: KEY_1,
      default_modifiers: 0,
      function: v11,
      helpstring: (unsigned int)"#ts_curve1_help",
      passive: false);
  }
  if ( `CPresetSlider::PanelKBMapFunc_ts_curve_2::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v12 = (unsigned int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    v15 = 0;
    `CPresetSlider::PanelKBMapFunc_ts_curve_2::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v12 + 1) = 0;
    CPresetSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_2",
      defaultcode: KEY_2,
      default_modifiers: 0,
      function: v12,
      helpstring: (unsigned int)"#ts_curve2_help",
      passive: false);
  }
  if ( `CPresetSlider::PanelKBMapFunc_ts_curve_3::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v13 = (unsigned int) __thiscall CAttributeSlider::`vcall'{968,{flat}};
    v15 = 0;
    `CPresetSlider::PanelKBMapFunc_ts_curve_3::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v13 + 1) = 0;
    CPresetSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_3",
      defaultcode: KEY_3,
      default_modifiers: 0,
      function: v13,
      helpstring: (unsigned int)"#ts_curve3_help",
      passive: false);
  }
  if ( `CPresetSlider::PanelKBMapFunc_ts_curve_4::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v14 = (unsigned int) __thiscall CDmePresetGroupEditorPanel::`vcall'{972,{flat}};
    v15 = 0;
    `CPresetSlider::PanelKBMapFunc_ts_curve_4::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v14 + 1) = 0;
    CPresetSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_4",
      defaultcode: KEY_4,
      default_modifiers: 0,
      function: v14,
      helpstring: (unsigned int)"#ts_curve4_help",
      passive: false);
  }
  this->m_pPresetFaderPanel = pFaderPanel;
  this->m_GradientColor = 0;
  this->m_ZeroColor = 0;
  this->m_TextColor = 0;
  this->m_TextColorFocus = 0;
  this->m_hContextMenu.m_iPanelID = -1;
  this->m_AttributeLookup.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const DmElementHandle_t *, const DmElementHandle_t *))CDefOps<DmeTime_t>::LessFunc;
  this->m_AttributeLookup.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_AttributeLookup.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_AttributeLookup.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_AttributeLookup.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_AttributeLookup.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_AttributeLookup.m_Tree.m_FirstFree = -1;
  this->m_AttributeLookup.m_Tree.m_pElements = m_pMemory;
  this->m_presetGroupName.u.m_Id = -1;
  this->m_presetName.u.m_Id = -1;
  this->m_nProceduralType = 0;
  *(_WORD *)&this->m_bReadOnly = 0;
  vgui::Slider::SetRange(this, min: 0, max: 1000);
  vgui::Slider::SetDragOnRepositionNob(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  v8 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
  if ( v8 != nullptr )
    v9 = vgui::TextImage::TextImage(this: v8, text: &var);
  else
    v9 = nullptr;
  this->m_pName = v9;
  this->m_ZeroColor = (Color)-12237499;
  this->m_GradientColor = (Color)-16746302;
  this->m_TextColor = (Color)-3618616;
  this->m_TextColorFocus = (Color)-14118960;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1049CFA0
// Name: public: CBaseAnimSetPresetFaderPanel::CBaseAnimSetPresetFaderPanel(class vgui::Panel __near *,char const __near *,class CBaseAnimationSetEditor __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimSetPresetFaderPanel *__thiscall CBaseAnimSetPresetFaderPanel::CBaseAnimSetPresetFaderPanel(
        CBaseAnimSetPresetFaderPanel *this,
        vgui::Panel *parent,
        const char *className,
        CBaseAnimationSetEditor *editor)
{
  vgui::PanelMessageMap *v5; // esi
  PanelAnimationMap *v6; // esi
  vgui::PanelKeyBindingMap *v7; // esi
  vgui::PropertySheet *v8; // eax
  vgui::PropertySheet *v9; // eax
  CSliderListPanel *v10; // eax
  CSliderListPanel *v11; // eax
  CPresetSlider **m_pMemory; // eax
  IMemAlloc_vtbl *v13; // edx
  CPresetSlider **v14; // eax
  CPresetSlider *v15; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CPresetSlider **v18; // ecx
  int v19; // eax
  CPresetSlider **v20; // ebx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  int parenta; // [esp+14h] [ebp+8h]
  const char *classNamea; // [esp+18h] [ebp+Ch]

  vgui::EditablePanel::EditablePanel(this, parent, panelName: className);
  this->__vftable = (CBaseAnimSetPresetFaderPanel_vtbl *)&CBaseAnimSetPresetFaderPanel::`vftable';
  if ( `CBaseAnimSetPresetFaderPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetPresetFaderPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
    v5->pfnClassName = CBaseAnimSetPresetFaderPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAnimSetPresetFaderPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetPresetFaderPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CBaseAnimSetPresetFaderPanel");
    v6->pfnClassName = CBaseAnimSetPresetFaderPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAnimSetPresetFaderPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetPresetFaderPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimSetPresetFaderPanel");
    v7->pfnClassName = CBaseAnimSetPresetFaderPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnShowAddPresetDialog::InitVar(a1: (int)&savedregs);
  CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetsChanged::InitVar(a1: (int)&savedregs);
  CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnManagePresets::InitVar(a1: (int)&savedregs);
  CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetNameSelected::InitVar(a1: (int)&savedregs);
  CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPageChanged::InitVar(a1: (int)&savedregs);
  this->m_presetGroupPages.m_Memory.m_pMemory = nullptr;
  this->m_presetGroupPages.m_Memory.m_nAllocationCount = 0;
  this->m_presetGroupPages.m_Memory.m_nGrowSize = 0;
  this->m_presetGroupPages.m_Size = 0;
  this->m_presetGroupPages.m_pElements = nullptr;
  this->m_presetSliders.m_Memory.m_pMemory = nullptr;
  this->m_presetSliders.m_Memory.m_nAllocationCount = 0;
  this->m_presetSliders.m_Memory.m_nGrowSize = 0;
  this->m_presetSliders.m_Size = 0;
  this->m_presetSliders.m_pElements = nullptr;
  this->m_hPresetEditor.m_iPanelID = -1;
  this->m_hActivePresetSlider.m_iPanelID = -1;
  this->m_pController = CBaseAnimationSetEditor::GetController(this: editor);
  v8 = (vgui::PropertySheet *)operator new(nSize: 0x210u);
  if ( v8 != nullptr )
    v9 = vgui::PropertySheet::PropertySheet(
           this: v8,
           parent: this,
           panelName: (vgui::Panel *)"presetPropertySheet",
           draggableTabs: false);
  else
    v9 = nullptr;
  this->m_pSheet = v9;
  vgui::Panel::SetAutoResize(
    this: v9,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  this->m_pSheet->SetSmallTabs(this: this->m_pSheet, a2: true);
  v10 = (CSliderListPanel *)operator new(nSize: 0x1B8u);
  if ( v10 != nullptr )
    v11 = CSliderListPanel::CSliderListPanel(this: v10, pFader: this, pParent: nullptr, panelName: "PresetSliders");
  else
    v11 = nullptr;
  this->m_pSliders = v11;
  vgui::PanelListPanel::SetFirstColumnWidth(this: v11, width: 0);
  vgui::Panel::SetAutoResize(
    this: this->m_pSliders,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  vgui::Panel::SetPos(this: this->m_pSliders, x: 0, y: 0);
  vgui::PanelListPanel::SetVerticalBufferPixels(this: this->m_pSliders, buffer: 0);
  if ( this->m_presetSliders.m_Memory.m_nAllocationCount < 400 && this->m_presetSliders.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_presetSliders.m_Memory.m_nAllocationCount = 400;
    m_pMemory = this->m_presetSliders.m_Memory.m_pMemory;
    v13 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v14 = (CPresetSlider **)((int (__stdcall *)(CPresetSlider **, int))v13->Realloc_2)(a1: m_pMemory, a2: 1600);
    else
      v14 = (CPresetSlider **)((int (__stdcall *)(int))v13->Alloc_2)(a1: 1600);
    this->m_presetSliders.m_Memory.m_pMemory = v14;
  }
  this->m_presetSliders.m_pElements = this->m_presetSliders.m_Memory.m_pMemory;
  for ( parenta = 400; parenta != 0; --parenta )
  {
    v15 = (CPresetSlider *)operator new(nSize: 0x200u);
    if ( v15 != nullptr )
      classNamea = (const char *)CPresetSlider::CPresetSlider(this: v15, parent: nullptr, pFaderPanel: this);
    else
      classNamea = nullptr;
    m_Size = this->m_presetSliders.m_Size;
    m_nAllocationCount = this->m_presetSliders.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_presetSliders,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_presetSliders.m_Size;
    v18 = this->m_presetSliders.m_Memory.m_pMemory;
    v19 = this->m_presetSliders.m_Size - m_Size - 1;
    this->m_presetSliders.m_pElements = v18;
    if ( v19 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v18[m_Size + 1], src: (unsigned __int8 *)&v18[m_Size], count: 4 * v19);
    v20 = &this->m_presetSliders.m_Memory.m_pMemory[m_Size];
    if ( v20 != nullptr )
      *v20 = (CPresetSlider *)classNamea;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1049D270
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAnimSetPresetFaderPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAnimSetPresetFaderPanel::GetMessageMap(CBaseAnimSetPresetFaderPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAnimSetPresetFaderPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimSetPresetFaderPanel::GetMessageMap'::`2'::s_pMap;
  `CBaseAnimSetPresetFaderPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
  `CBaseAnimSetPresetFaderPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049D2A0
// Name: public: virtual struct PanelAnimationMap __near * CBaseAnimSetPresetFaderPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAnimSetPresetFaderPanel::GetAnimMap(CBaseAnimSetPresetFaderPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAnimSetPresetFaderPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1049D2B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAnimSetPresetFaderPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAnimSetPresetFaderPanel::GetKBMap(CBaseAnimSetPresetFaderPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAnimSetPresetFaderPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimSetPresetFaderPanel::GetKBMap'::`2'::s_pMap;
  `CBaseAnimSetPresetFaderPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimSetPresetFaderPanel");
  `CBaseAnimSetPresetFaderPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1049D320
// Name: protected: void CBaseAnimSetPresetFaderPanel::UpdateOrCreatePresetSlider(int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::UpdateOrCreatePresetSlider(
        CBaseAnimSetPresetFaderPanel *this,
        int nSlot,
        const char *pPresetGroupName,
        const char *pPresetName)
{
  CPresetSlider *v5; // eax
  CPresetSlider *v6; // esi
  CSliderListPanel *m_pSliders; // ecx
  CSliderListPanel_vtbl *v8; // esi
  int ItemIDFromRow; // eax
  int v10; // eax

  if ( pPresetName != nullptr )
  {
    if ( nSlot < vgui::PanelListPanel::GetItemCount(this: (vgui::TextEntry *)this->m_pSliders) )
    {
      m_pSliders = this->m_pSliders;
      v8 = m_pSliders->__vftable;
      ItemIDFromRow = vgui::PanelListPanel::GetItemIDFromRow(this: m_pSliders, nRow: nSlot);
      v6 = (CPresetSlider *)v8->GetItemPanel(this: this->m_pSliders, a2: ItemIDFromRow);
    }
    else
    {
      v5 = (CPresetSlider *)operator new(nSize: 0x200u);
      if ( v5 != nullptr )
        v6 = CPresetSlider::CPresetSlider(this: v5, parent: this->m_pSliders, pFaderPanel: this);
      else
        v6 = nullptr;
      this->m_pSliders->AddItem(this: this->m_pSliders, a2: nullptr, a3: v6);
    }
    if ( v6 != nullptr )
    {
      CPresetSlider::Init(this: v6, pPresetGroupName, pPresetName);
      v6->SetValue(this: v6, a2: 0, a3: false);
      vgui::Panel::SetSize(this: v6, wide: 100, tall: 20);
      v10 = vgui::PanelListPanel::GetItemIDFromRow(this: this->m_pSliders, nRow: nSlot);
      vgui::PanelListPanel::SetItemVisible(this: this->m_pSliders, nItemID: v10, bVisible: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049D3F0
// Name: public: void CPresetSlider::SetControlValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::SetControlValues(CPresetSlider *this)
{
  CPresetSlider *v1; // edi
  const char *PresetGroupName; // eax
  CDmeAnimationSet *v3; // edx
  const char *PresetName; // eax
  CDmePresetGroup *v5; // edx
  CDmeTransform *Preset; // eax
  const Vector *Position; // esi
  float x; // eax
  int v9; // eax
  UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short> *v11; // eax
  int v12; // eax
  CDmElement *v13; // eax
  CDmElement *v14; // edi
  const char *m_pAsString; // eax
  CExpressionCalculator *Control; // eax
  DmElementHandle_t BufferType; // eax
  CPresetSlider *v18; // esi
  unsigned __int16 v19; // ax
  int p_elem; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  unsigned int v26; // [esp-4h] [ebp-88h]
  CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t search; // [esp+Ch] [ebp-78h] BYREF
  CAnimSetGroupAnimSetTraversal traversal; // [esp+60h] [ebp-24h] BYREF
  CDmrElementArray<CDmElement> values; // [esp+68h] [ebp-1Ch] BYREF
  DmElementHandle_t handle; // [esp+70h] [ebp-14h] BYREF
  int i; // [esp+74h] [ebp-10h]
  CDmeAnimationSet *pAnimSet; // [esp+78h] [ebp-Ch]
  CPresetSlider *v33; // [esp+7Ch] [ebp-8h]
  int m_Size; // [esp+80h] [ebp-4h]

  v1 = this;
  v33 = this;
  CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_AttributeLookup.m_Tree);
  if ( v1->m_nProceduralType == 0 )
  {
    traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: v1->m_pPresetFaderPanel->m_pController);
    traversal.m_nIndex = 0;
    for ( pAnimSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
          pAnimSet != nullptr;
          pAnimSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
    {
      PresetGroupName = CPresetSlider::GetPresetGroupName(this: v1);
      if ( CDmeAnimationSet::FindPresetGroup(this: v3, pGroupName: PresetGroupName) != nullptr )
      {
        PresetName = CPresetSlider::GetPresetName(this: v1);
        Preset = (CDmeTransform *)CDmePresetGroup::FindPreset(this: v5, pPresetName: PresetName);
        if ( Preset != nullptr )
        {
          Position = CDmeTransform::GetPosition(this: Preset);
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&values);
          x = Position[2].x;
          if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
          {
            values.m_pAttribute = nullptr;
            values.m_pStorage = nullptr;
            m_Size = 0;
          }
          else
          {
            values.m_pAttribute = (CDmAttribute *)LODWORD(Position[2].x);
            values.m_pStorage = *(DmElementArray_t **)(LODWORD(x) + 4);
            m_Size = values.m_pStorage->m_Size;
          }
          v9 = m_Size + v1->m_AttributeLookup.m_Tree.m_NumElements;
          if ( v1->m_AttributeLookup.m_Tree.m_Elements.m_nAllocationCount < v9
            && v1->m_AttributeLookup.m_Tree.m_Elements.m_nGrowSize >= 0 )
          {
            m_pMemory = v1->m_AttributeLookup.m_Tree.m_Elements.m_pMemory;
            v1->m_AttributeLookup.m_Tree.m_Elements.m_nAllocationCount = v9;
            v26 = 92 * v9;
            if ( m_pMemory != nullptr )
              v11 = (UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v26);
            else
              v11 = (UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v26);
            v1->m_AttributeLookup.m_Tree.m_Elements.m_pMemory = v11;
          }
          v12 = 0;
          i = 0;
          if ( m_Size > 0 )
          {
            do
            {
              v13 = g_pDataModel->GetElement(this: g_pDataModel, a2: values.m_pStorage->m_Memory.m_pMemory[v12]);
              v14 = v13;
              if ( v13 != nullptr && v13->IsA(this: v13, a2: CDmElement::m_classType) )
              {
                m_pAsString = v14->m_Name.m_Storage.u.m_pAsString;
                if ( m_pAsString == (const char *)-1 )
                  m_pAsString = &var;
                Control = (CExpressionCalculator *)CDmeAnimationSet::FindControl(
                                                     this: pAnimSet,
                                                     pControlName: m_pAsString);
                if ( Control != nullptr )
                {
                  BufferType = CCodecBuffer_Block::GetBufferType(this: Control);
                  v18 = v33;
                  memset(&search.elem, 0, 24);
                  search.elem.m_Quaternion = quat_identity;
                  handle = BufferType;
                  memset(search.elem.m_pValueAttribute, 0, 40);
                  search.key = BufferType;
                  v19 = CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                          this: &v33->m_AttributeLookup.m_Tree,
                          &search);
                  if ( v19 == 0xFFFF )
                    v19 = CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Insert(
                            this: &v18->m_AttributeLookup,
                            key: &handle);
                  p_elem = (int)&v18->m_AttributeLookup.m_Tree.m_Elements.m_pMemory[v19].m_Data.elem;
                  _V_memset(dest: (unsigned __int8 *)p_elem, fill: 0, count: 0x50u);
                  *(Quaternion *)(p_elem + 24) = quat_identity;
                  Attribute = CDmElement::FindAttribute(this: v14, pAttributeName: "value");
                  if ( Attribute != nullptr )
                  {
                    *(_DWORD *)(p_elem + 40) = Attribute;
                    *(float *)p_elem = CDmAttribute::GetValue<float>(this: Attribute)->m_Storage;
                  }
                  else
                  {
                    *(_DWORD *)(p_elem + 40) = CDmElement::FindAttribute(this: v14, pAttributeName: "values");
                    *(_DWORD *)(p_elem + 60) = CDmElement::FindAttribute(this: v14, pAttributeName: "times");
                  }
                  v22 = CDmElement::FindAttribute(this: v14, pAttributeName: "leftValue");
                  if ( v22 != nullptr )
                  {
                    *(_DWORD *)(p_elem + 48) = v22;
                    *(float *)(p_elem + 8) = CDmAttribute::GetValue<float>(this: v22)->m_Storage;
                  }
                  else
                  {
                    *(_DWORD *)(p_elem + 48) = CDmElement::FindAttribute(this: v14, pAttributeName: "leftValues");
                    *(_DWORD *)(p_elem + 68) = CDmElement::FindAttribute(this: v14, pAttributeName: "leftTimes");
                  }
                  v23 = CDmElement::FindAttribute(this: v14, pAttributeName: "rightValue");
                  if ( v23 != nullptr )
                  {
                    *(_DWORD *)(p_elem + 44) = v23;
                    *(float *)(p_elem + 4) = CDmAttribute::GetValue<float>(this: v23)->m_Storage;
                  }
                  else
                  {
                    *(_DWORD *)(p_elem + 44) = CDmElement::FindAttribute(this: v14, pAttributeName: "rightValues");
                    *(_DWORD *)(p_elem + 64) = CDmElement::FindAttribute(this: v14, pAttributeName: "rightTimes");
                  }
                  v24 = CDmElement::FindAttribute(this: v14, pAttributeName: "valuePosition");
                  if ( v24 != nullptr )
                  {
                    *(_DWORD *)(p_elem + 52) = v24;
                    *(Vector *)(p_elem + 12) = CDmAttribute::GetValue<Vector>(this: v24)->m_Storage;
                  }
                  else
                  {
                    *(_DWORD *)(p_elem + 52) = CDmElement::FindAttribute(this: v14, pAttributeName: "valuePositions");
                    *(_DWORD *)(p_elem + 72) = CDmElement::FindAttribute(this: v14, pAttributeName: "timePositions");
                  }
                  v25 = CDmElement::FindAttribute(this: v14, pAttributeName: "valueOrientation");
                  if ( v25 != nullptr )
                  {
                    *(_DWORD *)(p_elem + 56) = v25;
                    *(Quaternion *)(p_elem + 24) = *CDmAttribute::GetValue<Quaternion>(this: v25);
                  }
                  else
                  {
                    *(_DWORD *)(p_elem + 56) = CDmElement::FindAttribute(this: v14, pAttributeName: "valueOrientations");
                    *(_DWORD *)(p_elem + 76) = CDmElement::FindAttribute(this: v14, pAttributeName: "timeOrientations");
                  }
                }
              }
              v12 = i + 1;
              i = v12;
            }
            while ( v12 < m_Size );
            v1 = v33;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1049D7C0
// Name: Parallel_UpdateControlValues
// Source: json
//------------------------------------------------------------------------------
void __cdecl Parallel_UpdateControlValues(CPresetSlider **slider)
{
  CPresetSlider::SetControlValues(this: *slider);
}

//------------------------------------------------------------------------------
// Address: 0x1049D7D0
// Name: public: void CBaseAnimSetPresetFaderPanel::UpdateControlValues(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::UpdateControlValues(
        CBaseAnimSetPresetFaderPanel *this,
        bool bVisibleOnly)
{
  vgui::TextEntry *m_pSliders; // ecx
  int ItemCount; // esi
  IMemAlloc_vtbl *v5; // edx
  CPresetSlider **v6; // eax
  vgui::ScrollBarSlider *i; // esi
  CPresetSlider *v8; // eax
  _BYTE *m_Id; // ecx
  int m_Size; // eax
  CPresetSlider **m_pMemory; // ecx
  int j; // esi
  CPresetSlider **v13; // eax
  CUtlVectorFixedGrowable<CPresetSlider *,100> workItems; // [esp+Ch] [ebp-1C4h] BYREF
  CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> v15; // [esp+1B4h] [ebp-1Ch] BYREF
  CPresetSlider *pSlider; // [esp+1CCh] [ebp-4h] BYREF

  workItems.m_pElements = workItems.m_Memory.m_pFixedMemory;
  m_pSliders = (vgui::TextEntry *)this->m_pSliders;
  workItems.m_Memory.m_pMemory = workItems.m_Memory.m_pFixedMemory;
  workItems.m_Memory.m_nAllocationCount = 100;
  workItems.m_Memory.m_nGrowSize = -1;
  workItems.m_Memory.m_nMallocGrowSize = 0;
  workItems.m_Size = 0;
  ItemCount = vgui::PanelListPanel::GetItemCount(this: m_pSliders);
  if ( ItemCount > 100 )
  {
    CUtlMemory<CPresetSlider *,int>::ConvertToGrowableMemory(
      this: &workItems.m_Memory,
      nGrowSize: workItems.m_Memory.m_nMallocGrowSize);
    if ( workItems.m_Memory.m_nAllocationCount < ItemCount && workItems.m_Memory.m_nGrowSize >= 0 )
    {
      workItems.m_Memory.m_nAllocationCount = ItemCount;
      v5 = _g_pMemAlloc->__vftable;
      if ( workItems.m_Memory.m_pMemory != nullptr )
        v6 = (CPresetSlider **)((int (__stdcall *)(CPresetSlider **, int))v5->Realloc_2)(
                                 a1: workItems.m_Memory.m_pMemory,
                                 a2: 4 * ItemCount);
      else
        v6 = (CPresetSlider **)((int (__stdcall *)(int))v5->Alloc_2)(a1: 4 * ItemCount);
      workItems.m_Memory.m_pMemory = v6;
    }
  }
  workItems.m_pElements = workItems.m_Memory.m_pMemory;
  for ( i = vgui::ScrollBar::GetSlider(this: (vgui::ScrollBar *)this->m_pSliders);
        i != (vgui::ScrollBarSlider *)std::streambuf::underflow(this: (vgui::TreeView *)this->m_pSliders);
        i = (vgui::ScrollBarSlider *)vgui::PanelListPanel::NextItem(this: this->m_pSliders, nItemID: (int)i) )
  {
    v8 = (CPresetSlider *)this->m_pSliders->GetItemPanel(this: this->m_pSliders, a2: i);
    pSlider = v8;
    if ( v8 != nullptr )
    {
      m_Id = (_BYTE *)v8->m_presetName.u.m_Id;
      if ( m_Id != (_BYTE *)-1 && m_Id != nullptr && *m_Id != 0 && (!bVisibleOnly || v8->IsVisible(this: v8)) )
        CUtlVector<CPresetSlider *,CUtlMemoryFixedGrowable<CPresetSlider *,100,int>>::InsertBefore(
          this: &workItems,
          elem: workItems.m_Size,
          src: &pSlider);
    }
  }
  if ( ifm_threaded_updatecontrolvalues.m_pParent != nullptr
    && ifm_threaded_updatecontrolvalues.m_pParent->m_Value.m_nValue != 0 )
  {
    m_Size = workItems.m_Size;
    m_pMemory = workItems.m_Memory.m_pMemory;
    v15.m_pItems.m_value = nullptr;
    v15.m_pLimit = nullptr;
    _InterlockedExchange((volatile __int32 *)&v15.m_pItems, 0);
    v15.m_ItemProcessor.m_pfnProcess = Parallel_UpdateControlValues;
    v15.m_ItemProcessor.m_pfnBegin = nullptr;
    v15.m_ItemProcessor.m_pfnEnd = nullptr;
    CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::Run(
      this: &v15,
      pItems: m_pMemory,
      nItems: m_Size,
      nChunkSize: 1,
      nMaxParallel: 0x7FFFFFFF,
      pThreadPool: nullptr);
  }
  else
  {
    for ( j = 0; j < workItems.m_Size; ++j )
      CPresetSlider::SetControlValues(this: workItems.m_Memory.m_pMemory[j]);
  }
  v13 = workItems.m_Memory.m_pMemory;
  workItems.m_Size = 0;
  if ( workItems.m_Memory.m_nGrowSize >= 0 )
  {
    if ( workItems.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: workItems.m_Memory.m_pMemory);
      v13 = nullptr;
      workItems.m_Memory.m_pMemory = nullptr;
    }
    workItems.m_Memory.m_nAllocationCount = 0;
  }
  workItems.m_pElements = v13;
  if ( workItems.m_Memory.m_nGrowSize >= 0 && v13 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
}

//------------------------------------------------------------------------------
// Address: 0x1049D9E0
// Name: protected: void CBaseAnimSetPresetFaderPanel::RebuildPresetSliders(char const __near *,class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::RebuildPresetSliders(
        CBaseAnimSetPresetFaderPanel *this,
        const char *pPresetGroupName,
        const CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > *presetNames)
{
  int m_Size; // ebx
  int i; // edi
  const char *m_pAsString; // eax
  CSliderListPanel *m_pSliders; // ecx
  CSliderListPanel_vtbl *v8; // edi
  int ItemIDFromRow; // eax
  int v10; // eax
  int nSliders; // [esp+18h] [ebp+Ch]

  vgui::PanelListPanel::HideAllItems(this: this->m_pSliders);
  m_Size = presetNames->m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    m_pAsString = presetNames->m_Memory.m_pMemory[i].u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    CBaseAnimSetPresetFaderPanel::UpdateOrCreatePresetSlider(this, nSlot: i, pPresetGroupName, pPresetName: m_pAsString);
  }
  for ( nSliders = vgui::PanelListPanel::GetItemCount(this: (vgui::TextEntry *)this->m_pSliders);
        m_Size < nSliders;
        ++m_Size )
  {
    m_pSliders = this->m_pSliders;
    v8 = m_pSliders->__vftable;
    ItemIDFromRow = vgui::PanelListPanel::GetItemIDFromRow(this: m_pSliders, nRow: m_Size);
    v10 = (int)v8->GetItemPanel(this: this->m_pSliders, a2: ItemIDFromRow);
    if ( v10 != 0 )
    {
      *(_DWORD *)(v10 + 504) = 0;
      *(_BYTE *)(v10 + 508) = 0;
      *(_DWORD *)(v10 + 500) = -1;
      *(_DWORD *)(v10 + 496) = -1;
      CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v10 + 468));
    }
  }
  CBaseAnimSetPresetFaderPanel::UpdateControlValues(this, bVisibleOnly: false);
}

//------------------------------------------------------------------------------
// Address: 0x1049DAB0
// Name: protected: void CBaseAnimSetPresetFaderPanel::PopulatePresetList(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::PopulatePresetList(CBaseAnimSetPresetFaderPanel *this, bool bChanged)
{
  CDmeFilmClip *AnimationSetClip; // eax
  vgui::PropertySheet *m_pSheet; // ecx
  int v5; // eax
  vgui::PropertySheet *v6; // ecx
  int v7; // edi
  vgui::Panel *(__thiscall *GetActivePage)(vgui::PropertySheet *); // edx
  int v9; // ebx
  vgui::Panel *v10; // eax
  CUtlSymbolLarge *(__thiscall *GetSymbol)(IDataModel *, CUtlSymbolLarge *, const char *); // edx
  int m_Size; // eax
  vgui::PropertyPage *v13; // edi
  const char *m_pAsString; // ebx
  bool v15; // zf
  vgui::PropertySheet_vtbl *v16; // eax
  const char *v17; // eax
  vgui::PropertyPage *v18; // eax
  int v19; // ebx
  int m_nAllocationCount; // eax
  vgui::PropertyPage **m_pMemory; // ecx
  int v22; // eax
  vgui::PropertyPage **v23; // ebx
  vgui::PropertyPage *v24; // edi
  CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > presetNames; // [esp+Ch] [ebp-48h] BYREF
  CUtlVector<PresetGroupInfo_t,CUtlMemory<PresetGroupInfo_t,int> > presetGroupInfo; // [esp+20h] [ebp-34h] BYREF
  CDmeFilmClip *pFilmClip; // [esp+34h] [ebp-20h]
  int nCurrentGroupIndex; // [esp+38h] [ebp-1Ch]
  const char *pCurrentGroupName; // [esp+3Ch] [ebp-18h]
  int nPresetGroupPages; // [esp+40h] [ebp-14h] BYREF
  PresetGroupInfo_t src; // [esp+44h] [ebp-10h] BYREF
  const char *pName; // [esp+4Ch] [ebp-8h]
  bool bCurrentGroupIsProceduralGroup; // [esp+53h] [ebp-1h]

  AnimationSetClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  m_pSheet = this->m_pSheet;
  pFilmClip = AnimationSetClip;
  v5 = m_pSheet->GetActivePageNum(this: m_pSheet);
  v6 = this->m_pSheet;
  v7 = v5;
  GetActivePage = v6->GetActivePage;
  v9 = 0;
  nCurrentGroupIndex = v5;
  bCurrentGroupIsProceduralGroup = v5 == 0;
  if ( (int)GetActivePage(this: v6) != 0 )
  {
    v10 = this->m_pSheet->GetActivePage(this: this->m_pSheet);
    pCurrentGroupName = v10->GetName(this: v10);
  }
  else
  {
    pCurrentGroupName = &var;
  }
  GetSymbol = g_pDataModel->GetSymbol;
  memset(&presetGroupInfo, 0, sizeof(presetGroupInfo));
  GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&nPresetGroupPages, a3: "Procedural");
  src.presetGroupSym.u.m_Id = nPresetGroupPages;
  CUtlVector<PresetGroupInfo_t,CUtlMemory<PresetGroupInfo_t,int>>::InsertBefore(this: &presetGroupInfo, elem: 0, &src);
  CollectPresetGroupInfo(
    pFilmClip,
    presetInfo: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&presetGroupInfo,
    bSkipReadOnly: false,
    bSkipInvisible: true);
  m_Size = this->m_presetGroupPages.m_Size;
  nPresetGroupPages = m_Size;
  *(_DWORD *)&src.bGroupShared = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v13 = this->m_presetGroupPages.m_Memory.m_pMemory[v9];
      if ( v13 != nullptr )
      {
        if ( v9 >= presetGroupInfo.m_Size )
        {
          this->m_pSheet->RemovePage(this: this->m_pSheet, a2: v13);
          vgui::Panel::SetName(this: v13, panelName: &var);
        }
        else
        {
          m_pAsString = presetGroupInfo.m_Memory.m_pMemory[v9].presetGroupSym.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = &var;
          v15 = *v13->GetName(this: v13) == 0;
          v16 = this->m_pSheet->__vftable;
          if ( v15 )
            ((void (__stdcall *)(vgui::PropertyPage *, const char *, _DWORD, _DWORD, int))v16->AddPage)(
              a1: v13,
              a2: m_pAsString,
              a3: 0,
              a4: 0,
              a5: -1);
          else
            ((void (__stdcall *)(vgui::PropertyPage *, const char *))v16->SetPageTitle)(a1: v13, a2: m_pAsString);
          vgui::Panel::SetName(this: v13, panelName: m_pAsString);
          v9 = *(_DWORD *)&src.bGroupShared;
        }
        m_Size = nPresetGroupPages;
      }
      *(_DWORD *)&src.bGroupShared = ++v9;
    }
    while ( v9 < m_Size );
    v7 = nCurrentGroupIndex;
  }
  nPresetGroupPages = m_Size;
  if ( m_Size < presetGroupInfo.m_Size )
  {
    do
    {
      v17 = presetGroupInfo.m_Memory.m_pMemory[nPresetGroupPages].presetGroupSym.u.m_pAsString;
      pName = &var;
      if ( v17 != (const char *)-1 )
        pName = v17;
      v18 = (vgui::PropertyPage *)operator new(nSize: 0x188u);
      if ( v18 != nullptr )
        *(_DWORD *)&src.bGroupShared = vgui::PropertyPage::PropertyPage(this: v18, parent: this, panelName: pName);
      else
        *(_DWORD *)&src.bGroupShared = 0;
      v19 = this->m_presetGroupPages.m_Size;
      m_nAllocationCount = this->m_presetGroupPages.m_Memory.m_nAllocationCount;
      if ( v19 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_presetGroupPages,
          num: v19 - m_nAllocationCount + 1);
      ++this->m_presetGroupPages.m_Size;
      m_pMemory = this->m_presetGroupPages.m_Memory.m_pMemory;
      v22 = this->m_presetGroupPages.m_Size - v19 - 1;
      this->m_presetGroupPages.m_pElements = m_pMemory;
      if ( v22 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[v19 + 1],
          src: (unsigned __int8 *)&m_pMemory[v19],
          count: 4 * v22);
      v23 = &this->m_presetGroupPages.m_Memory.m_pMemory[v19];
      if ( v23 != nullptr )
        *v23 = *(vgui::PropertyPage **)&src.bGroupShared;
      this->m_pSheet->AddPage(
        this: this->m_pSheet,
        a2: *(vgui::Panel **)&src.bGroupShared,
        a3: pName,
        a4: nullptr,
        a5: false,
        a6: -1);
      ++nPresetGroupPages;
    }
    while ( nPresetGroupPages < presetGroupInfo.m_Size );
    v7 = nCurrentGroupIndex;
  }
  if ( v7 >= 0 )
  {
    v24 = this->m_presetGroupPages.m_Memory.m_pMemory[v7];
    this->m_pSheet->SetActivePage(this: this->m_pSheet, a2: v24);
    this->m_pSliders->SetParent_2(this: this->m_pSliders, a2: v24);
    memset(&presetNames, 0, sizeof(presetNames));
    if ( bCurrentGroupIsProceduralGroup )
      CollectProceduralPresetNames((CUtlMemory<vgui::TreeNode *,int> *)&presetNames);
    else
      CollectPresetNamesForGroup(
        pFilmClip,
        pPresetGroupName: pCurrentGroupName,
        (CUtlMemory<vgui::TreeNode *,int> *)&presetNames);
    CBaseAnimSetPresetFaderPanel::RebuildPresetSliders(this, pPresetGroupName: pCurrentGroupName, &presetNames);
    if ( presetNames.m_Memory.m_nGrowSize >= 0 && presetNames.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: presetNames.m_Memory.m_pMemory);
  }
  else
  {
    vgui::PanelListPanel::HideAllItems(this: this->m_pSliders);
  }
  if ( presetGroupInfo.m_Memory.m_nGrowSize >= 0 && presetGroupInfo.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: presetGroupInfo.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1049DDE0
// Name: public: void CBaseAnimSetPresetFaderPanel::OnDeletePreset(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::OnDeletePreset(
        CBaseAnimSetPresetFaderPanel *this,
        const char *pPresetName)
{
  CDmeAnimationSet *i; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-8h] BYREF

  g_pDataModel->StartUndo(this: g_pDataModel, a2: "Delete Preset", a3: "Delete Preset", a4: 0);
  g_pDataModel->PushNotificationScope(this: g_pDataModel, a2: "Delete Preset", a3: 0, a4: 256);
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  traversal.m_nIndex = 0;
  for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        i != nullptr;
        i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
  {
    CDmeAnimationSet::RemovePreset(this: i, pPresetName);
  }
  CBaseAnimSetPresetFaderPanel::PopulatePresetList(this, bChanged: false);
  g_pDataModel->FinishUndo(this: g_pDataModel);
  g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1049DE90
// Name: protected: virtual void CPresetSlider::OnDeleteConfirmed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnDeleteConfirmed(CPresetSlider *this)
{
  const char *m_pAsString; // eax

  m_pAsString = this->m_presetName.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &var;
  CBaseAnimSetPresetFaderPanel::OnDeletePreset(this: this->m_pPresetFaderPanel, pPresetName: m_pAsString);
}

//------------------------------------------------------------------------------
// Address: 0x1049DEB0
// Name: protected: virtual void CBaseAnimSetPresetFaderPanel::OnPresetNameSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::OnPresetNameSelected(
        CBaseAnimSetPresetFaderPanel *this,
        KeyValues *pParams)
{
  char *String; // ebx
  char *pPresetGroupName; // [esp+Ch] [ebp-4h]
  bool bAnimated; // [esp+18h] [ebp+8h]

  String = KeyValues::GetString(this: pParams, keyName: "text", defaultValue: nullptr);
  pPresetGroupName = KeyValues::GetString(this: pParams, keyName: "presetGroupName", defaultValue: &var);
  bAnimated = KeyValues::GetInt(this: pParams, keyName: "animated", defaultValue: 0) != 0;
  CBaseAnimSetPresetFaderPanel::AddPreset(this, pPresetGroupName, pPresetName: String, bAnimated);
  CBaseAnimSetPresetFaderPanel::PopulatePresetList(this, bChanged: false);
}

//------------------------------------------------------------------------------
// Address: 0x1049DF20
// Name: protected: virtual void CBaseAnimSetPresetFaderPanel::OnPresetsChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::OnPresetsChanged(CBaseAnimSetPresetFaderPanel *this)
{
  CBaseAnimSetPresetFaderPanel::PopulatePresetList(this, bChanged: false);
}

//------------------------------------------------------------------------------
// Address: 0x1049DF30
// Name: protected: virtual void CBaseAnimSetPresetFaderPanel::OnPageChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::OnPageChanged(CBaseAnimSetPresetFaderPanel *this)
{
  CBaseAnimSetPresetFaderPanel::PopulatePresetList(this, bChanged: true);
}

//------------------------------------------------------------------------------
// Address: 0x1039B2FB
// Name: protected: void CMFCShellTreeCtrl::OnItemexpanding(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCShellTreeCtrl::OnItemexpanding(CMFCShellTreeCtrl *this, tagNMHDR *pNMHDR, int *pResult)
{
  HWND__ *hwndFrom; // ebx
  LPARAM v5; // eax
  tagTVITEMA tvItem; // [esp+Ch] [ebp-28h] BYREF

  if ( pNMHDR == nullptr || (hwndFrom = pNMHDR[5].hwndFrom) == nullptr )
    AfxThrowInvalidArgException();
  if ( pNMHDR[1].hwndFrom == (HWND__ *)1 )
  {
    v5 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 9u, lParam: 0);
    while ( v5 != 0 )
    {
      v5 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 3u, lParam: v5);
      if ( (HWND__ *)v5 == hwndFrom )
      {
        SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Bu, wParam: 9u, lParam: (LPARAM)hwndFrom);
        break;
      }
    }
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x1102u, wParam: 0x8001u, lParam: (LPARAM)hwndFrom);
  }
  else if ( pNMHDR[1].hwndFrom == (HWND__ *)2 )
  {
    CMFCShellTreeCtrl::GetChildItems(this, hParentItem: (struct _TREEITEM *)hwndFrom);
    if ( SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Au, wParam: 4u, lParam: (LPARAM)hwndFrom) == 0 )
    {
      memset(dst: (unsigned __int8 *)&tvItem, value: 0, count: sizeof(tvItem));
      tvItem.hItem = (struct _TREEITEM *)hwndFrom;
      tvItem.mask = 64;
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x110Du, wParam: 0, lParam: (LPARAM)&tvItem);
    }
  }
  *pResult = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1039B3C7
// Name: protected: void CMFCShellTreeCtrl::OnContextMenu(class CWnd __near *,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCShellTreeCtrl::OnContextMenu(CMFCShellTreeCtrl *this, CWnd *__formal, CPoint point)
{
  if ( this->m_bContextMenu != 0 )
    CMFCShellTreeCtrl::OnShowContextMenu(this, point: point.tagPOINT);
  else
    CWnd::Default(this);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0048A0E0
// Name: int ProceduralTypeForPresetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ProceduralTypeForPresetName(const char *pPresetName)
{
  int v1; // esi

  v1 = 0;
  while ( _V_stricmp(s1: pPresetName, s2: g_ProceduralPresetNames_12[v1]) != 0 )
  {
    if ( ++v1 >= 21 )
      return -1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0048A120
// Name: public: static char const __near * CBaseAnimSetPresetFaderPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAnimSetPresetFaderPanel::GetPanelClassName()
{
  return "CBaseAnimSetPresetFaderPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0048A130
// Name: public: static char const __near * CPresetSlider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPresetSlider::GetPanelClassName()
{
  return "CPresetSlider";
}

//------------------------------------------------------------------------------
// Address: 0x0048A170
// Name: class CDmePresetGroup __near * FindAnyPresetGroup(class CDmeFilmClip __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePresetGroup *__cdecl FindAnyPresetGroup(CDmeFilmClip *pFilmClip, const char *pPresetGroupName)
{
  CDmeAnimationSet *v2; // eax
  CDmePresetGroup *result; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-8h] BYREF

  traversal.m_pFilmClip = pFilmClip;
  traversal.m_nIndex = 0;
  v2 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  if ( v2 == nullptr )
    return nullptr;
  while ( 1 )
  {
    result = CDmeAnimationSet::FindPresetGroup(this: v2, pGroupName: pPresetGroupName);
    if ( result != nullptr )
      break;
    v2 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v2 == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048A1C0
// Name: class CDmePreset __near * FindAnyPreset(class CDmeFilmClip __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmePreset *__cdecl FindAnyPreset(CDmeFilmClip *pFilmClip, const char *pPresetGroupName, const char *pPresetName)
{
  CDmeAnimationSet *v3; // eax
  CDmePresetGroup *PresetGroup; // eax
  CDmePreset *result; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-8h] BYREF

  traversal.m_pFilmClip = pFilmClip;
  traversal.m_nIndex = 0;
  v3 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  if ( v3 == nullptr )
    return nullptr;
  while ( 1 )
  {
    PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v3, pGroupName: pPresetGroupName);
    if ( PresetGroup != nullptr )
    {
      result = CDmePresetGroup::FindPreset(this: PresetGroup, pPresetName);
      if ( result != nullptr )
        break;
    }
    v3 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v3 == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048A220
// Name: public: static char const __near * CAddPresetDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAddPresetDialog::GetPanelClassName()
{
  return "CAddPresetDialog";
}

//------------------------------------------------------------------------------
// Address: 0x0048A230
// Name: protected: virtual void CAddPresetDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAddPresetDialog::OnCommand(CAddPresetDialog *this, const char *command)
{
  int v3; // edi
  void *v4; // esp
  vgui::TextEntry *m_pPresetName; // ecx
  vgui::TextEntry_vtbl *v6; // edx
  int v7; // edi
  void *v8; // esp
  KeyValues *v9; // eax
  KeyValues *v10; // edi
  char v11[12]; // [esp+0h] [ebp-10h] BYREF
  char *txt; // [esp+Ch] [ebp-4h]
  bool bAnimated_3; // [esp+1Bh] [ebp+Bh]

  if ( _V_stricmp(s1: command, s2: "OK") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Cancel") != 0 )
      vgui::BaseInputDialog::OnCommand(this, command);
    else
      this->CloseModal(this);
  }
  else
  {
    v3 = this->m_pPresetName->GetTextLength(this: this->m_pPresetName) + 1;
    v4 = alloca(v3);
    m_pPresetName = this->m_pPresetName;
    v6 = m_pPresetName->__vftable;
    txt = v11;
    v6->GetText_2(this: m_pPresetName, a2: v11, a3: v3);
    v7 = this->m_pPresetGroup->GetTextLength(this: this->m_pPresetGroup) + 1;
    v8 = alloca(v7);
    this->m_pPresetGroup->GetText_2(this: this->m_pPresetGroup, a2: v11, a3: v7);
    bAnimated_3 = this->m_pAnimated->IsSelected(this: this->m_pAnimated);
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
      v10 = KeyValues::KeyValues(this: v9, setName: "PresetNameSelected", firstKey: "text", firstValue: txt);
    else
      v10 = nullptr;
    KeyValues::SetString(this: v10, keyName: "presetGroupName", value: v11);
    KeyValues::SetInt(this: v10, keyName: "animated", value: bAnimated_3);
    if ( this->m_pContextKeyValues != nullptr )
    {
      KeyValues::AddSubKey(this: v10, pSubkey: this->m_pContextKeyValues);
      this->m_pContextKeyValues = nullptr;
    }
    this->PostActionSignal(this, a2: v10);
    this->CloseModal(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048A390
// Name: protected: virtual void CAddPresetDialog::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAddPresetDialog::OnTick(CAddPresetDialog *this)
{
  bool bEnableOkayButton; // [esp+4h] [ebp-4h]

  if ( this->m_pPresetName->GetTextLength(this: this->m_pPresetName) <= 0
    || (bEnableOkayButton = true, this->m_pPresetGroup->GetTextLength(this: this->m_pPresetGroup) <= 0) )
  {
    bEnableOkayButton = false;
  }
  this->m_pOKButton->SetEnabled(this: this->m_pOKButton, a2: bEnableOkayButton);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0048A3F0
// Name: public: char const __near * CPresetSlider::GetPresetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPresetSlider::GetPresetName(CPresetSlider *this)
{
  const char *result; // eax

  result = this->m_presetName.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048A410
// Name: public: char const __near * CPresetSlider::GetPresetGroupName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CPresetSlider::GetPresetGroupName(CPresetSlider *this)
{
  const char *result; // eax

  result = this->m_presetGroupName.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048A430
// Name: protected: virtual void CPresetSlider::OnRename(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnRename(CPresetSlider *this)
{
  vgui::InputDialog *v2; // edi
  const char *v3; // eax
  vgui::InputDialog *v4; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  v2 = (vgui::InputDialog *)MemAlloc_Alloc(nSize: 0x22Cu);
  if ( v2 != nullptr )
  {
    v3 = this->GetName(this);
    v4 = vgui::InputDialog::InputDialog(
           this: v2,
           parent: this,
           title: "Rename Preset",
           prompt: "Name:",
           defaultValue: v3);
    if ( v4 != nullptr )
    {
      v4->SetSmallCaption(this: v4, a2: true);
      vgui::InputDialog::SetMultiline(this: v4, state: false);
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
      {
        v6 = KeyValues::KeyValues(this: v5, setName: "RenamePreset");
        vgui::BaseInputDialog::DoModal(this: v4, pContextKeyValues: v6);
      }
      else
      {
        vgui::BaseInputDialog::DoModal(this: v4, pContextKeyValues: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048A4C0
// Name: protected: virtual void CPresetSlider::OnDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnDelete(CPresetSlider *this)
{
  const char *v2; // eax
  vgui::MessageBox *v3; // eax
  vgui::MessageBox *v4; // eax
  vgui::MessageBox *v5; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  char sz[256]; // [esp+4h] [ebp-100h] BYREF

  v2 = this->GetName(this);
  V_snprintf(pDest: sz, maxLen: 256, pFormat: "Delete '%s'?", v2);
  v3 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
  if ( v3 != nullptr )
  {
    v4 = vgui::MessageBox::MessageBox(this: v3, title: "Delete Preset", text: sz, parent: this);
    v5 = v4;
    if ( v4 != nullptr )
    {
      vgui::MessageBox::SetCancelButtonVisible(this: v4, state: true);
      vgui::MessageBox::SetCancelButtonText(this: v5, buttonText: "#VGui_Cancel");
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "OnDeleteConfirmed");
      else
        v7 = nullptr;
      v5->SetCommand(this: v5, a2: v7);
      v5->AddActionSignalTarget_2(this: v5, a2: this);
      v5->DoModal_2(this: v5, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048A580
// Name: protected: virtual void CPresetSlider::GetTrackRect(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::GetTrackRect(CPresetSlider *this, int *x, int *y, int *w, int *h)
{
  vgui::Panel::GetSize(this, wide: w, tall: h);
  *x = 2;
  *y = 2;
  *w -= 4;
  *h -= 4;
}

//------------------------------------------------------------------------------
// Address: 0x0048A5B0
// Name: protected: virtual void CPresetSlider::OnCurve1(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCurve1(CPresetSlider *this)
{
  this->m_pPresetFaderPanel->DispatchCurve(this: this->m_pPresetFaderPanel, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0048A5D0
// Name: protected: virtual void CPresetSlider::OnCurve2(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCurve2(CPresetSlider *this)
{
  this->m_pPresetFaderPanel->DispatchCurve(this: this->m_pPresetFaderPanel, a2: 2);
}

//------------------------------------------------------------------------------
// Address: 0x0048A5F0
// Name: protected: virtual void CPresetSlider::OnCurve3(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCurve3(CPresetSlider *this)
{
  this->m_pPresetFaderPanel->DispatchCurve(this: this->m_pPresetFaderPanel, a2: 3);
}

//------------------------------------------------------------------------------
// Address: 0x0048A610
// Name: protected: virtual void CPresetSlider::OnCurve4(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCurve4(CPresetSlider *this)
{
  this->m_pPresetFaderPanel->DispatchCurve(this: this->m_pPresetFaderPanel, a2: 4);
}

//------------------------------------------------------------------------------
// Address: 0x0048A630
// Name: public: static char const __near * CSliderListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSliderListPanel::GetPanelClassName()
{
  return "CSliderListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0048A640
// Name: public: virtual void CSliderListPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSliderListPanel::OnMousePressed(CSliderListPanel *this, const char *code)
{
  if ( code != (const char *)108 )
    vgui::Panel::OnMousePressed(this, panelName: code);
}

//------------------------------------------------------------------------------
// Address: 0x0048A660
// Name: public: virtual void CSliderListPanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSliderListPanel::OnMouseReleased(CSliderListPanel *this, const char *code)
{
  if ( code == (const char *)108 )
    this->OnShowContextMenu(this);
  else
    vgui::Panel::OnMousePressed(this, panelName: code);
}

//------------------------------------------------------------------------------
// Address: 0x0048A6A0
// Name: public: int CJob::Abort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::Abort(CJob *this, BOOL bDiscard)
{
  int result; // eax
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  bool v6; // bl
  int v7; // eax
  int m_status; // [esp+10h] [ebp+8h]

  result = this->m_status;
  if ( result == 1 || result == 2 || result == 4 )
  {
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    this->AddRef(this);
    switch ( this->m_status )
    {
      case 1:
      case 4:
        v6 = bDiscard;
        v7 = this->DoAbort(this, a2: bDiscard);
        this->m_status = v7;
        m_status = v7;
        if ( v6 )
          this->DoCleanup(this);
        CThreadEvent::Set(this: &this->m_CompleteEvent);
        break;
      default:
        m_status = this->m_status;
        break;
    }
    this->Release(this);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return m_status;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048A770
// Name: public: CAddPresetDialog::CAddPresetDialog(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CAddPresetDialog *__thiscall CAddPresetDialog::CAddPresetDialog(CAddPresetDialog *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::TextEntry *v6; // eax
  vgui::TextEntry *v7; // eax
  vgui::ComboBox *v8; // eax
  vgui::ComboBox *v9; // eax
  vgui::CheckButton *v10; // eax
  vgui::CheckButton *v11; // eax

  vgui::BaseInputDialog::BaseInputDialog(this, parent, title: "Enter Preset Name", bShowCancelButton: true);
  this->__vftable = (CAddPresetDialog_vtbl *)&CAddPresetDialog::`vftable';
  if ( `CAddPresetDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CAddPresetDialog::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CAddPresetDialog");
    v3->pfnClassName = CAddPresetDialog::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::BaseInputDialog");
  }
  if ( `CAddPresetDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAddPresetDialog::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CAddPresetDialog");
    v4->pfnClassName = CAddPresetDialog::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::BaseInputDialog");
  }
  if ( `CAddPresetDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAddPresetDialog::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CAddPresetDialog");
    v5->pfnClassName = CAddPresetDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::BaseInputDialog");
  }
  v6 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v6 != nullptr )
    v7 = vgui::TextEntry::TextEntry(this: v6, parent: this, panelName: "PresetName");
  else
    v7 = nullptr;
  this->m_pPresetName = v7;
  v8 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v8 != nullptr )
    v9 = vgui::ComboBox::ComboBox(this: v8, parent: this, panelName: "PresetGroup", numLines: 8, allowEdit: true);
  else
    v9 = nullptr;
  this->m_pPresetGroup = v9;
  v10 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v10 != nullptr )
    v11 = vgui::CheckButton::CheckButton(this: v10, parent: this, panelName: "Animated", text: "Animated");
  else
    v11 = nullptr;
  this->m_pAnimated = v11;
  vgui::Frame::SetDeleteSelfOnClose(this, state: false);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/addpresetdialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0048A8F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAddPresetDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAddPresetDialog::GetMessageMap(CAddPresetDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAddPresetDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAddPresetDialog::GetMessageMap'::`2'::s_pMap;
  `CAddPresetDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAddPresetDialog");
  `CAddPresetDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048A920
// Name: public: virtual struct PanelAnimationMap __near * CAddPresetDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAddPresetDialog::GetAnimMap(CAddPresetDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CAddPresetDialog");
}

//------------------------------------------------------------------------------
// Address: 0x0048A930
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAddPresetDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAddPresetDialog::GetKBMap(CAddPresetDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAddPresetDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAddPresetDialog::GetKBMap'::`2'::s_pMap;
  `CAddPresetDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAddPresetDialog");
  `CAddPresetDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048A990
// Name: public: void CPresetSlider::Init(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::Init(CPresetSlider *this, const char *pPresetGroupName, const char *pPresetName)
{
  CUtlSymbolLarge::<unnamed_type_u> *v4; // eax
  const char *v5; // edi
  CUtlSymbolLarge::<unnamed_type_u> *v6; // eax
  bool v7; // zf
  void (__thiscall *v8)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *); // eax
  CDmeAnimationSet *v9; // eax
  CDmePresetGroup *PresetGroup; // eax
  CDmePreset *Preset; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-8h] BYREF

  this->m_nProceduralType = 0;
  this->m_bReadOnly = false;
  v4 = (CUtlSymbolLarge::<unnamed_type_u> *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                              a1: g_pDataModel.u,
                                              a2: &traversal.m_nIndex,
                                              a3: pPresetGroupName);
  v5 = pPresetName;
  this->m_presetGroupName.u = (CUtlSymbolLarge::<unnamed_type_u>)v4->m_Id;
  v6 = (CUtlSymbolLarge::<unnamed_type_u> *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                              a1: g_pDataModel.u,
                                              a2: &pPresetName,
                                              a3: v5);
  v7 = (_S1_3 & 1) == 0;
  this->m_presetName.u = (CUtlSymbolLarge::<unnamed_type_u>)v6->m_Id;
  if ( v7 )
  {
    v8 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200);
    _S1_3 |= 1u;
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v8)(
      a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
      a2: &proceduralPresetGroupNameSym,
      a3: "Procedural");
  }
  if ( this->m_presetGroupName.u.m_Id == proceduralPresetGroupNameSym.u.m_Id )
  {
    this->m_nProceduralType = ProceduralTypeForPresetName(pPresetName: v5);
    this->m_bReadOnly = true;
  }
  else
  {
    traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pPresetFaderPanel->m_pController);
    traversal.m_nIndex = 0;
    while ( 1 )
    {
      v9 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      if ( v9 == nullptr )
        break;
      PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v9, pGroupName: pPresetGroupName);
      if ( PresetGroup != nullptr )
      {
        Preset = CDmePresetGroup::FindPreset(this: PresetGroup, pPresetName: v5);
        if ( Preset != nullptr )
        {
          this->m_bReadOnly = CDmePreset::IsReadOnly(this: Preset);
          break;
        }
      }
    }
  }
  vgui::Panel::SetName(this, panelName: v5);
  this->m_pName->SetText_2(this: this->m_pName, a2: v5);
  vgui::TextImage::ResizeImageToContent(this: this->m_pName);
  ((void (__thiscall *)(CPresetSlider *, int))this->SetBgColor)(a1: this, a2: -2139062144);
}

//------------------------------------------------------------------------------
// Address: 0x0048AAD0
// Name: protected: virtual void CPresetSlider::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnMouseReleased(CPresetSlider *this, ButtonCode_t code)
{
  int v3; // eax
  bool dragging; // bl
  float flLastValue; // [esp+14h] [ebp+8h]

  this->m_bIgnoreCursorMovedEvents = false;
  if ( code == MOUSE_RIGHT )
  {
    this->OnShowContextMenu(this);
  }
  else if ( code == KEY_COUNT )
  {
    v3 = this->GetValue(this);
    dragging = this->_dragging;
    flLastValue = (float)v3 * 0.001;
    vgui::Slider::OnMouseReleased(this, code: KEY_COUNT);
    if ( dragging )
    {
      CBaseAnimationSetControl::ApplyPreset(
        this: this->m_pPresetFaderPanel->m_pController,
        flScale: flLastValue,
        values: &this->m_AttributeLookup);
      this->SetCursor(this, a2: 2u);
    }
    if ( CPresetSlider::s_bResetMousePosOnMouseUp )
    {
      CPresetSlider::s_bResetMousePosOnMouseUp = false;
      g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: CPresetSlider::s_nMousePosX, a3: CPresetSlider::s_nMousePosY);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048AB90
// Name: private: void CPresetSlider::OnRenameCompleted(char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnRenameCompleted(CPresetSlider *this, const char *pText, KeyValues *pContextKeyValues)
{
  const char *v3; // edi
  const char *v5; // eax
  const char *PresetGroupName; // eax
  CDmeAnimationSet *v7; // edx
  const char *PresetName; // eax
  CDmePresetGroup *v9; // edx
  CDmePreset *Preset; // ebx
  const char *v11; // eax
  const char *v12; // [esp-4h] [ebp-14h]
  CAnimSetGroupAnimSetTraversal traversal; // [esp+8h] [ebp-8h] BYREF

  v3 = pText;
  if ( pText != nullptr && *pText != 0 )
  {
    v12 = pText;
    v5 = this->GetName(this);
    if ( _V_strcmp(s1: v5, s2: v12) != 0 )
    {
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 256))(
        a1: g_pDataModel.u,
        a2: "Rename Preset",
        a3: "Rename Preset",
        a4: 0);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, _DWORD, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 460))(
        a1: g_pDataModel.u,
        a2: "Rename Preset",
        a3: 0,
        a4: 256);
      vgui::Panel::SetName(this, panelName: v3);
      this->m_pName->SetText_2(this: this->m_pName, a2: v3);
      vgui::TextImage::ResizeImageToContent(this: this->m_pName);
      this->m_presetName.u.m_Id = *(_DWORD *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                                               a1: g_pDataModel.u,
                                               a2: &pText,
                                               a3: v3);
      traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pPresetFaderPanel->m_pController);
      traversal.m_nIndex = 0;
      while ( CAnimSetGroupAnimSetTraversal::Next(this: &traversal) != nullptr )
      {
        PresetGroupName = CPresetSlider::GetPresetGroupName(this);
        CDmeAnimationSet::FindPresetGroup(this: v7, pGroupName: PresetGroupName);
        PresetName = CPresetSlider::GetPresetName(this);
        Preset = CDmePresetGroup::FindPreset(this: v9, pPresetName: PresetName);
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
          a1: g_pDataModel.u,
          a2: &pText,
          a3: v3);
        CDmAttribute::SetValue<CUtlSymbolLarge>(
          this: Preset->m_Name.m_pAttribute,
          value: (const CUtlSymbolLarge *)&pText);
      }
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
        a1: g_pDataModel.u,
        a2: 0);
    }
  }
  else
  {
    v11 = this->GetName(this);
    _Warning(a1: "Can't rename preset for %s to an empty name\n", v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048AD10
// Name: protected: virtual void CPresetSlider::OnInputCompleted(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnInputCompleted(CPresetSlider *this, KeyValues *pParams)
{
  const char *String; // ebx
  KeyValues *Key; // eax

  String = KeyValues::GetString(this: pParams, keyName: "text", defaultValue: nullptr);
  Key = KeyValues::FindKey(this: pParams, keyName: "RenamePreset", bCreate: false);
  if ( Key != nullptr )
    CPresetSlider::OnRenameCompleted(this, pText: String, pContextKeyValues: Key);
}

//------------------------------------------------------------------------------
// Address: 0x0048AD50
// Name: protected: virtual void CPresetSlider::OnShowContextMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnShowContextMenu(CPresetSlider *this)
{
  vgui::Panel *v2; // eax
  vgui::Menu *v3; // eax
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // ebx
  vgui::Panel *v7; // eax
  const char *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // ebx
  vgui::Panel *v15; // eax
  int v16; // ebx
  vgui::Panel *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // ebx
  vgui::Panel *v20; // eax
  vgui::Menu *v21; // eax

  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    if ( v2 != nullptr )
      ((void (__thiscall *)(vgui::Panel *, int))v2->dtr_Panel)(a1: v2, a2: 1);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  v3 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v3 != nullptr )
    v4 = vgui::Menu::Menu(this: v3, parent: this, panelName: "ActionMenu");
  else
    v4 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: v4);
  if ( !this->m_bReadOnly )
  {
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "OnRename");
    else
      v6 = nullptr;
    v7 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CPresetSlider *, _DWORD))v7->__vftable[1].PaintTraverse)(
      a1: v7,
      a2: "Rename...",
      a3: v6,
      a4: this,
      a5: 0);
    v8 = this->GetName(this);
    if ( _V_stricmp(s1: v8, s2: "Default") != 0 )
    {
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
        v10 = KeyValues::KeyValues(this: v9, setName: "OnDelete");
      else
        v10 = nullptr;
      v11 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CPresetSlider *, _DWORD))v11->__vftable[1].PaintTraverse)(
        a1: v11,
        a2: "Delete...",
        a3: v10,
        a4: this,
        a5: 0);
    }
    v12 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    v12->__vftable[1].DeletePanel(this: v12);
  }
  v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v13 != nullptr )
    v14 = KeyValues::KeyValues(this: v13, setName: "ShowAddPresetDialog");
  else
    v14 = nullptr;
  v15 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  v16 = ((int (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimSetPresetFaderPanel *, _DWORD))v15->__vftable[1].PaintTraverse)(
          a1: v15,
          a2: "Add...",
          a3: v14,
          a4: this->m_pPresetFaderPanel,
          a5: 0);
  if ( CBaseAnimationSetControl::GetMostRecentlySelectedControl(this: this->m_pPresetFaderPanel->m_pController) == nullptr )
  {
    v17 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    ((void (__thiscall *)(vgui::Panel *, int, _DWORD))v17->__vftable[1].GetKBMap)(a1: v17, a2: v16, a3: 0);
  }
  v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v18 != nullptr )
    v19 = KeyValues::KeyValues(this: v18, setName: "ManagePresets");
  else
    v19 = nullptr;
  v20 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimSetPresetFaderPanel *, _DWORD))v20->__vftable[1].PaintTraverse)(
    a1: v20,
    a2: "Manage...",
    a3: v19,
    a4: this->m_pPresetFaderPanel,
    a5: 0);
  v21 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
  vgui::Menu::PlaceContextMenu(parent: this, menu: v21);
}

//------------------------------------------------------------------------------
// Address: 0x0048AF60
// Name: private: void CPresetSlider::UpdateTickPos(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::UpdateTickPos(CPresetSlider *this, int x, int y)
{
  float v4; // xmm0_4
  int ty; // [esp+4h] [ebp-10h] BYREF
  int th; // [esp+8h] [ebp-Ch] BYREF
  int tw; // [esp+Ch] [ebp-8h] BYREF
  int tx; // [esp+10h] [ebp-4h] BYREF

  if ( !this->m_bIgnoreCursorMovedEvents )
  {
    this->GetTrackRect(this, a2: &tx, a3: &ty, a4: &tw, a5: &th);
    v4 = 0.0;
    if ( x > tx )
    {
      if ( x >= tx + tw || tw <= 0 )
        v4 = 1.0;
      else
        v4 = (float)(x - tx) / (float)tw;
    }
    this->SetValue(this, a2: (int)(float)((float)(v4 * 1000.0) + 0.5), a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048B000
// Name: protected: virtual void CPresetSlider::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCursorMoved(CPresetSlider *this, int x, int y)
{
  CPresetSlider::UpdateTickPos(this, x, y);
}

//------------------------------------------------------------------------------
// Address: 0x0048B010
// Name: protected: virtual void CPresetSlider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::ApplySchemeSettings(CPresetSlider *this, vgui::IScheme *scheme)
{
  vgui::TextImage_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::Slider::ApplySchemeSettings(this, pScheme: scheme);
  v3 = this->m_pName->__vftable;
  v4 = scheme->GetFont(this: scheme, a2: "DefaultBold", a3: false);
  v3->SetFont(this: this->m_pName, a2: v4);
  ((void (__thiscall *)(vgui::TextImage *, _DWORD))this->m_pName->SetColor)(
    a1: this->m_pName,
    a2: *(_DWORD *)&this->m_TextColor);
  vgui::TextImage::ResizeImageToContent(this: this->m_pName);
  ((void (__thiscall *)(CPresetSlider *, int))this->SetFgColor)(a1: this, a2: -16746302);
  this->SetThumbWidth(this, a2: 3);
}

//------------------------------------------------------------------------------
// Address: 0x0048B0A0
// Name: private: virtual void CSliderListPanel::OnShowContextMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSliderListPanel::OnShowContextMenu(CSliderListPanel *this)
{
  vgui::Panel *v2; // eax
  vgui::Menu *v3; // eax
  vgui::Menu *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // ebx
  vgui::Panel *v7; // eax
  int v8; // ebx
  vgui::Panel *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // ebx
  vgui::Panel *v12; // eax
  vgui::Menu *v13; // eax

  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    if ( v2 != nullptr )
      ((void (__thiscall *)(vgui::Panel *, int))v2->dtr_Panel)(a1: v2, a2: 1);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  v3 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v3 != nullptr )
    v4 = vgui::Menu::Menu(this: v3, parent: this, panelName: "ActionMenu");
  else
    v4 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: v4);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ShowAddPresetDialog");
  else
    v6 = nullptr;
  v7 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  v8 = ((int (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimSetPresetFaderPanel *, _DWORD))v7->__vftable[1].PaintTraverse)(
         a1: v7,
         a2: "Add...",
         a3: v6,
         a4: this->m_pPresetFaderPanel,
         a5: 0);
  if ( CBaseAnimationSetControl::GetMostRecentlySelectedControl(this: this->m_pPresetFaderPanel->m_pController) == nullptr )
  {
    v9 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    ((void (__thiscall *)(vgui::Panel *, int, _DWORD))v9->__vftable[1].GetKBMap)(a1: v9, a2: v8, a3: 0);
  }
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(this: v10, setName: "ManagePresets");
  else
    v11 = nullptr;
  v12 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimSetPresetFaderPanel *, _DWORD))v12->__vftable[1].PaintTraverse)(
    a1: v12,
    a2: "Manage...",
    a3: v11,
    a4: this->m_pPresetFaderPanel,
    a5: 0);
  v13 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
  vgui::Menu::PlaceContextMenu(parent: this, menu: v13);
}

//------------------------------------------------------------------------------
// Address: 0x0048B1F0
// Name: protected: virtual void CBaseAnimSetPresetFaderPanel::OnManagePresets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::OnManagePresets(CBaseAnimSetPresetFaderPanel *this)
{
  CDmePresetGroupEditorFrame *v2; // eax
  CDmePresetGroupEditorFrame *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // ebx
  CDmeFilmClip *AnimationSetClip; // eax
  vgui::Panel *v10; // eax

  if ( vgui::PHandle::Get(this: &this->m_hPresetEditor) == nullptr )
  {
    v2 = (CDmePresetGroupEditorFrame *)MemAlloc_Alloc(nSize: 0x224u);
    if ( v2 != nullptr )
      v3 = CDmePresetGroupEditorFrame::CDmePresetGroupEditorFrame(this: v2, pParent: this, pTitle: "Manage Presets");
    else
      v3 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hPresetEditor, pPanel: v3);
    v4 = vgui::PHandle::Get(this: &this->m_hPresetEditor);
    v4->AddActionSignalTarget_2(this: v4, a2: this);
    v5 = vgui::PHandle::Get(this: &this->m_hPresetEditor);
    v5->SetVisible(this: v5, a2: false);
    v6 = vgui::PHandle::Get(this: &this->m_hPresetEditor);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v6->__vftable[1].GetUnpackStructure)(a1: v6, a2: 0);
    v7 = vgui::PHandle::Get(this: &this->m_hPresetEditor);
    v7->__vftable[1].dtr_Panel(this: v7);
  }
  v8 = vgui::PHandle::Get(this: &this->m_hPresetEditor);
  AnimationSetClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  CDmePresetGroupEditorPanel::SetAnimationSetClip(
    this: (CDmePresetGroupEditorPanel *)v8[1].m_sNavUpName.m_Storage.m_nActualLength,
    pFilmClip: AnimationSetClip);
  v10 = vgui::PHandle::Get(this: &this->m_hPresetEditor);
  v10->__vftable[1].IsEnabled(this: v10);
}

//------------------------------------------------------------------------------
// Address: 0x0048B2E0
// Name: public: virtual void CBaseAnimSetPresetFaderPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::ApplySchemeSettings(
        CBaseAnimSetPresetFaderPanel *this,
        vgui::IScheme *scheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme: scheme);
  ((void (__thiscall *)(CSliderListPanel *, int))this->m_pSliders->SetBgColor)(a1: this->m_pSliders, a2: -14013910);
}

//------------------------------------------------------------------------------
// Address: 0x0048B310
// Name: public: class CPresetSlider __near * CBaseAnimSetPresetFaderPanel::GetActivePresetSlider(void)
// Source: json
//------------------------------------------------------------------------------
CPresetSlider *__thiscall CBaseAnimSetPresetFaderPanel::GetActivePresetSlider(CBaseAnimSetPresetFaderPanel *this)
{
  return (CPresetSlider *)vgui::PHandle::Get(this: &this->m_hActivePresetSlider);
}

//------------------------------------------------------------------------------
// Address: 0x0048B320
// Name: private: void CParallelProcessor<class CPresetSlider __near *,class CFuncJobItemProcessor<class CPresetSlider __near *>,1>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::DoExecute(
        CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *this)
{
  void (*m_pfnBegin)(void); // eax
  CPresetSlider **m_pLimit; // ecx
  unsigned int v4; // edx
  CPresetSlider **v5; // esi
  CPresetSlider **v6; // edi
  void (*m_pfnEnd)(void); // ebx
  unsigned int v8; // [esp+4h] [ebp-8h]
  CPresetSlider **pLimit; // [esp+8h] [ebp-4h]

  if ( this->m_pItems.m_value < this->m_pLimit )
  {
    m_pfnBegin = this->m_ItemProcessor.m_pfnBegin;
    if ( m_pfnBegin != nullptr )
      m_pfnBegin();
    m_pLimit = this->m_pLimit;
    v4 = 4 * this->m_nChunkSize;
    pLimit = m_pLimit;
    v8 = v4;
    do
    {
      v5 = (CPresetSlider **)_InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pItems, v4);
      v6 = (CPresetSlider **)((char *)v5 + v4);
      if ( m_pLimit < (CPresetSlider **)((char *)v5 + v4) )
        v6 = m_pLimit;
      if ( v5 < v6 )
      {
        do
          this->m_ItemProcessor.m_pfnProcess(a1: v5++);
        while ( v5 < v6 );
        m_pLimit = pLimit;
        v4 = v8;
      }
    }
    while ( v5 < m_pLimit );
    m_pfnEnd = this->m_ItemProcessor.m_pfnEnd;
    if ( m_pfnEnd != nullptr )
      m_pfnEnd();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048B390
// Name: protected: virtual void CPresetSlider::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnMousePressed(CPresetSlider *this, ButtonCode_t code)
{
  vgui::DHANDLE<CPresetSlider> *p_m_hActivePresetSlider; // ecx
  int th; // [esp+4h] [ebp-18h] BYREF
  int my; // [esp+8h] [ebp-14h] BYREF
  int mx; // [esp+Ch] [ebp-10h] BYREF
  int tw; // [esp+10h] [ebp-Ch] BYREF
  int ty; // [esp+14h] [ebp-8h] BYREF
  int tx; // [esp+18h] [ebp-4h] BYREF

  p_m_hActivePresetSlider = &this->m_pPresetFaderPanel->m_hActivePresetSlider;
  this->m_bIgnoreCursorMovedEvents = false;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_hActivePresetSlider, pPanel: this);
  if ( code == KEY_COUNT )
  {
    if ( this->_dragging )
    {
      this->OnMouseReleased(this, a2: KEY_COUNT);
    }
    else
    {
      vgui::Slider::OnMousePressed(this, code: KEY_COUNT);
      if ( this->_dragging )
      {
        this->SetCursor(this, a2: 15u);
        g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my);
        this->GetTrackRect(this, a2: &tx, a3: &ty, a4: &tw, a5: &th);
        vgui::Panel::LocalToScreen(this, x: &tx, y: &ty);
        if ( mx < tx + tw )
        {
          if ( mx >= tx )
          {
            CPresetSlider::s_nMousePosX = mx;
            CPresetSlider::s_bResetMousePosOnMouseUp = true;
            CPresetSlider::s_nMousePosY = my;
            g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: tx, a3: my);
          }
          this->SetValue(this, a2: 0, a3: false);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048B490
// Name: protected: virtual void CPresetSlider::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCursorEntered(CPresetSlider *this)
{
  if ( !this->_dragging )
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: &this->m_pPresetFaderPanel->m_hActivePresetSlider,
      pPanel: this);
}

//------------------------------------------------------------------------------
// Address: 0x0048B4B0
// Name: protected: virtual void CPresetSlider::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnCursorExited(CPresetSlider *this)
{
  if ( !this->_dragging )
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: &this->m_pPresetFaderPanel->m_hActivePresetSlider,
      pPanel: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0048B4D0
// Name: protected: virtual void CPresetSlider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::Paint(CPresetSlider *this)
{
  bool v2; // al
  vgui::ISurface *v3; // edi
  vgui::ISurface_vtbl *v4; // ebx
  int v5; // eax
  int x; // [esp+4h] [ebp-1Ch] BYREF
  int wide; // [esp+8h] [ebp-18h] BYREF
  int tall; // [esp+Ch] [ebp-14h] BYREF
  int y; // [esp+10h] [ebp-10h] BYREF
  Color col; // [esp+14h] [ebp-Ch] BYREF
  int mx; // [esp+18h] [ebp-8h] BYREF
  int my; // [esp+1Ch] [ebp-4h] BYREF

  if ( vgui::PHandle::Get(this: &this->m_pPresetFaderPanel->m_hActivePresetSlider) == this )
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
      || (v2 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
    {
      v2 = true;
    }
    if ( this->_dragging || v2 )
    {
      g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: &my);
      vgui::Panel::ScreenToLocal(this, x: &mx, y: &my);
      CPresetSlider::UpdateTickPos(this, x: mx, y: my);
      this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
      this->GetFgColor(this, result: &col);
      ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: col);
      v3 = g_pVGuiSurface;
      v4 = g_pVGuiSurface->__vftable;
      v5 = vgui::Panel::GetTall(this);
      v4->DrawFilledRect(this: v3, a2: this->_nobPos[0], a3: 1, a4: this->_nobPos[1], a5: v5 - 1);
      ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: *(_DWORD *)&this->m_ZeroColor);
      g_pVGuiSurface->DrawFilledRect(
        this: g_pVGuiSurface,
        a2: this->_nobPos[0] - 1,
        a3: y + 1,
        a4: this->_nobPos[0],
        a5: y + tall - 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048B610
// Name: protected: virtual void CPresetSlider::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPresetSlider::PaintBackground(CPresetSlider *this@<ecx>, int a2@<edi>)
{
  bool v3; // zf
  bool (__thiscall *IsKeyDown)(vgui::IInput *, ButtonCode_t); // eax
  bool v5; // al
  bool v6; // al
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // eax
  int (__thiscall *GetValue)(vgui::Slider *); // edx
  int v9; // eax
  int v10; // edi
  float v11; // xmm0_4
  vgui::ISurface_vtbl *v12; // edx
  void (__thiscall *DrawFilledRectFade)(vgui::ISurface *, int, int, int, int, unsigned int, unsigned int, bool); // edx
  Color m_TextColor; // eax
  Color m_GradientColor; // eax
  int cw; // [esp+8h] [ebp-30h] BYREF
  int w; // [esp+Ch] [ebp-2Ch] BYREF
  int v18; // [esp+10h] [ebp-28h] BYREF
  int h; // [esp+14h] [ebp-24h] BYREF
  __int64 v20; // [esp+18h] [ebp-20h]
  int tw; // [esp+20h] [ebp-18h] BYREF
  int th; // [esp+24h] [ebp-14h] BYREF
  int tx; // [esp+28h] [ebp-10h] BYREF
  int ty; // [esp+2Ch] [ebp-Ch] BYREF
  float v25; // [esp+30h] [ebp-8h]
  bool bIsAltKeyDown; // [esp+36h] [ebp-2h]
  bool bIsShiftKeyDown; // [esp+37h] [ebp-1h]

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v3 = vgui::PHandle::Get(this: &this->m_pPresetFaderPanel->m_hActivePresetSlider) == this;
  IsKeyDown = g_pVGuiInput->IsKeyDown;
  HIBYTE(v25) = v3;
  if ( IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (v5 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT), bIsShiftKeyDown = false, v5) )
  {
    bIsShiftKeyDown = true;
  }
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v6 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT), bIsAltKeyDown = false, v6) )
  {
    bIsAltKeyDown = true;
  }
  if ( HIBYTE(v25) == 0 )
  {
    m_TextColor = this->m_TextColor;
    goto LABEL_20;
  }
  if ( !this->_dragging && !bIsShiftKeyDown )
    goto LABEL_18;
  ((void (__thiscall *)(CPresetSlider *, int *, int *, int *, int *, int))this->GetTrackRect)(
    a1: this,
    a2: &tx,
    a3: &ty,
    a4: &tw,
    a5: &th,
    a6: a2);
  DrawSetColor = g_pVGuiSurface->DrawSetColor;
  v25 = -1.7014118e38;
  ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: -16777216);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: tx, a3: ty, a4: tx + tw, a5: ty + th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_GradientColor);
  tw -= 2;
  th -= 2;
  GetValue = this->GetValue;
  ++tx;
  ++ty;
  v9 = GetValue(this);
  v10 = (int)(float)((float)((float)tw * (float)((float)v9 * 0.001)) + 0.5);
  v11 = 15.0;
  if ( (float)((float)((float)this->GetValue(this) * 0.001) * 255.0) > 15.0 )
    v11 = (float)((float)this->GetValue(this) * 0.001) * 255.0;
  v3 = !this->_dragging;
  v25 = v11;
  if ( v3 )
  {
    if ( bIsAltKeyDown )
      m_GradientColor = this->m_GradientColor;
    else
      m_GradientColor = this->m_ZeroColor;
    ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: m_GradientColor);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: tx, a3: ty, a4: tx + tw, a5: ty + th);
LABEL_18:
    m_TextColor = this->m_TextColorFocus;
    goto LABEL_20;
  }
  v12 = g_pVGuiSurface->__vftable;
  HIDWORD(v20) = HIWORD(v25) | 0xC00;
  DrawFilledRectFade = v12->DrawFilledRectFade;
  v20 = (__int64)v25;
  ((void (__thiscall *)(vgui::ISurface *, int, int, int, int, int, _DWORD))DrawFilledRectFade)(
    a1: g_pVGuiSurface,
    a2: tx,
    a3: ty,
    a4: v10 + tx,
    a5: ty + th,
    a6: 15,
    a7: v20);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_ZeroColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v10 + tx + 1, a3: ty, a4: tx + tw, a5: th + ty);
  m_TextColor = this->m_TextColorFocus;
LABEL_20:
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pName->SetColor)(a1: this->m_pName, a2: m_TextColor);
  this->m_pName->GetContentSize(this: this->m_pName, a2: &cw, a3: &v18);
  this->m_pName->SetPos(
    this: this->m_pName,
    a2: (int)(float)((float)(w - cw) * 0.5),
    a3: (int)(float)((float)(h - v18) * 0.5));
  this->m_pName->Paint(this: this->m_pName);
}

//------------------------------------------------------------------------------
// Address: 0x0048B930
// Name: protected: void CBaseAnimSetPresetFaderPanel::AddPreset(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::AddPreset(
        CBaseAnimSetPresetFaderPanel *this,
        const char *pPresetGroupName,
        const char *pPresetName,
        int bAnimated)
{
  const char *v4; // edi
  vgui::MessageBox *v5; // esi
  CDmeAnimationSet *v7; // esi
  CDmePresetGroup *PresetGroup; // edi
  vgui::MessageBox *v9; // eax
  vgui::MessageBox *v10; // esi
  vgui::MessageBox *v11; // eax
  vgui::MessageBox *v12; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-8h] BYREF

  v4 = pPresetName;
  v5 = nullptr;
  if ( pPresetName == nullptr || *pPresetName == 0 )
  {
    v12 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v12 != nullptr )
      v5 = vgui::MessageBox::MessageBox(
             this: v12,
             title: "Add Preset Error",
             text: "Can't add preset with an empty name\n",
             parent: this);
    v5->SetDeleteSelfOnClose(this: v5, a2: true);
    v5->DoModal_2(this: v5, a2: nullptr);
    return;
  }
  if ( CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController) == nullptr )
    return;
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  traversal.m_nIndex = 0;
  v7 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  if ( v7 == nullptr )
  {
LABEL_11:
    CBaseAnimationSetControl::AddPreset(this: this->m_pController, pPresetGroupName, pPresetName: v4, bAnimated);
    return;
  }
  while ( 1 )
  {
    PresetGroup = CDmeAnimationSet::FindPresetGroup(this: v7, pGroupName: pPresetGroupName);
    if ( PresetGroup != nullptr
      && (unsigned int)CBaseAnimationSetControl::GetSelectionState(this: this->m_pController, pAnimSet: v7) >= 2 )
    {
      if ( PresetGroup->m_bIsReadOnly.m_Storage )
      {
        v9 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
        if ( v9 != nullptr )
        {
          v10 = vgui::MessageBox::MessageBox(
                  this: v9,
                  title: "Add Preset Error",
                  text: "Can't add preset to a read-only preset group!\n",
                  parent: this);
          goto LABEL_15;
        }
        goto LABEL_14;
      }
      if ( CDmePresetGroup::FindPreset(this: PresetGroup, pPresetName) != nullptr )
        break;
    }
    v7 = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
    if ( v7 == nullptr )
    {
      v4 = pPresetName;
      goto LABEL_11;
    }
  }
  v11 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
  if ( v11 == nullptr )
  {
LABEL_14:
    v10 = nullptr;
    goto LABEL_15;
  }
  v10 = vgui::MessageBox::MessageBox(
          this: v11,
          title: "Add Preset Error",
          text: "A preset with that name already exists!\n",
          parent: this);
LABEL_15:
  v10->SetDeleteSelfOnClose(this: v10, a2: true);
  v10->DoModal_2(this: v10, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0048BAB0
// Name: public: void CBaseAnimSetPresetFaderPanel::GetPreviewFader(struct FaderPreview_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::GetPreviewFader(
        CBaseAnimSetPresetFaderPanel *this,
        FaderPreview_t *fader)
{
  FaderPreview_t *v2; // esi
  vgui::Panel *v4; // eax
  _DWORD *v5; // edi
  bool v6; // al
  int mx; // [esp+Ch] [ebp-4h] BYREF

  v2 = fader;
  _V_memset(dest: fader, fill: 0, count: 20);
  *(_WORD *)&v2->isbeingdragged = 0;
  v4 = vgui::PHandle::Get(this: &this->m_hActivePresetSlider);
  v5 = &v4->__vftable;
  if ( v4 != nullptr )
  {
    v2->isbeingdragged = HIBYTE(v4[1].__vftable);
    v6 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT);
    v2->holdingPreviewKey = v6;
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &mx, a3: (int *)&fader);
    if ( !vgui::Panel::IsWithin(this, x: mx, y: (int)fader) )
      v2->holdingPreviewKey = false;
    v2->name = (const char *)(*(int (__thiscall **)(_DWORD *))(*v5 + 72))(a1: v5);
    v2->amount = (float)(*(int (__thiscall **)(_DWORD *))(*v5 + 848))(a1: v5) * 0.001;
    v2->values = (CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short> *)(v5 + 117);
    v2->nProceduralType = v5[126];
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048BB90
// Name: public: void CBaseAnimSetPresetFaderPanel::UpdateProceduralPresetSlider(class CUtlMap<enum DmElementHandle_t,struct AnimationControlAttributes_t,unsigned short> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::UpdateProceduralPresetSlider(
        CBaseAnimSetPresetFaderPanel *this,
        CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short> *values)
{
  vgui::Panel *v3; // eax
  int v4; // eax

  v3 = vgui::PHandle::Get(this: &this->m_hActivePresetSlider);
  if ( v3 != nullptr )
  {
    v4 = *((_DWORD *)&v3[1] + 43);
    if ( v4 > 0 && v4 <= 7 )
      this->m_pController->ProceduralPreset_UpdateCrossfade(this: this->m_pController, a2: values, a3: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048BBD0
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::AddRef(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::AddRef(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  return _InterlockedIncrement(&this->m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x0048BBE0
// Name: public: virtual int CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>::Release(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>::Release(
        CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *this)
{
  CRefCountServiceBase<1,CRefMT> *v1; // esi
  int result; // eax

  v1 = &this->CRefCountServiceBase<1,CRefMT>;
  result = _InterlockedDecrement(&this->m_iRefs);
  if ( result == 0 )
  {
    if ( v1->OnFinalRelease(this: v1) )
      ((void (__thiscall *)(CRefCountServiceBase<1,CRefMT> *, int))v1->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: v1,
        a2: 1);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048BC10
// Name: public: virtual void CMemberFunctor0<class CParallelProcessor<class CPresetSlider __near *,class CFuncJobItemProcessor<class CPresetSlider __near *>,1> __near *,void (CParallelProcessor<class CPresetSlider __near *,class CFuncJobItemProcessor<class CPresetSlider __near *>,1>::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *,void (__thiscall CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *,void (__thiscall CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  ((void (__thiscall *)(char *))LODWORD(this->m_Proxy.m_pfnProxied))(a1: (char *)this->m_Proxy.m_pObject + DWORD1(this->m_Proxy.m_pfnProxied));
}

//------------------------------------------------------------------------------
// Address: 0x0048BDA0
// Name: void CollectPresetGroupInfo(class CDmeFilmClip __near *,class CUtlVector<struct PresetGroupInfo_t,class CUtlMemory<struct PresetGroupInfo_t,int>> __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollectPresetGroupInfo(
        CDmeFilmClip *pFilmClip,
        CUtlMemory<vgui::PropertySheet::Page_t,int> *presetInfo,
        bool bSkipReadOnly,
        bool bSkipInvisible)
{
  CDmeAnimationSet *j; // eax
  CDmaElementArray<CDmePresetGroup> *v5; // esi
  CDmAttribute *m_pAttribute; // eax
  DmElementArray_t *m_pData; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // esi
  const char *v11; // eax
  char v12; // cl
  CDmAttribute *Attribute; // eax
  CDmAttribute *v14; // esi
  CDmaVar<bool> *v15; // eax
  bool m_Storage; // bl
  int m_pMemory; // esi
  int v18; // eax
  PresetGroupInfo_t *v19; // ecx
  int m_nAllocationCount; // eax
  PresetGroupInfo_t *v21; // ecx
  int v22; // eax
  PresetGroupInfo_t *v23; // eax
  bool bGroupReadOnly; // cl
  bool bGroupVisible; // dl
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-20h] BYREF
  PresetGroupInfo_t info; // [esp+14h] [ebp-18h]
  CDmrElementArray<CDmePresetGroup> presetGroups; // [esp+1Ch] [ebp-10h] BYREF
  int i; // [esp+24h] [ebp-8h]
  CUtlSymbolLarge::<unnamed_type_u> v30; // [esp+28h] [ebp-4h] BYREF
  CDmeFilmClip *pFilmClipa; // [esp+34h] [ebp+8h]

  traversal.m_pFilmClip = pFilmClip;
  traversal.m_nIndex = 0;
  for ( j = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        j != nullptr;
        j = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
  {
    v5 = CDmeAnimationSet::GetPresetGroups(this: j);
    CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presetGroups);
    m_pAttribute = v5->m_pAttribute;
    if ( m_pAttribute != nullptr && (m_pAttribute->m_nFlags & 0x1F) == 0xF )
    {
      presetGroups.m_pAttribute = v5->m_pAttribute;
      m_pData = (DmElementArray_t *)m_pAttribute->m_pData;
      presetGroups.m_pStorage = m_pData;
      pFilmClipa = (CDmeFilmClip *)m_pData->m_Size;
    }
    else
    {
      m_pData = nullptr;
      presetGroups.m_pAttribute = nullptr;
      presetGroups.m_pStorage = nullptr;
      pFilmClipa = nullptr;
    }
    v8 = 0;
    i = 0;
    if ( (int)pFilmClipa > 0 )
    {
      while ( 1 )
      {
        v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: m_pData->m_Memory.m_pMemory[v8]);
        v10 = v9;
        if ( v9 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
               a1: v9,
               a2: CDmePresetGroup::m_classType.u) != 0
          && (!bSkipReadOnly || *(_BYTE *)(v10 + 76) == 0)
          && (!bSkipInvisible || *(_BYTE *)(v10 + 68) != 0) )
        {
          v11 = *(const char **)(v10 + 20);
          if ( v11 == (const char *)-1 )
            v11 = defaultValue;
          (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u> *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
            a1: g_pDataModel.u,
            a2: &v30,
            a3: v11);
          v12 = *(_BYTE *)(v10 + 68);
          info.bGroupReadOnly = *(_BYTE *)(v10 + 76);
          info.bGroupVisible = v12;
          if ( (`CDmElement::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
          {
            `CDmElement::GetValue<bool>'::`2'::`local static guard' |= 1u;
            `CDmElement::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
            `CDmElement::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
          }
          Attribute = CDmElement::FindAttribute(this: (CDmElement *)v10, pAttributeName: "shared");
          v14 = Attribute;
          if ( Attribute != nullptr )
          {
            if ( (`CDmAttribute::GetValue<bool>'::`2'::`local static guard' & 1) == 0 )
            {
              `CDmAttribute::GetValue<bool>'::`2'::`local static guard' |= 1u;
              `CDmAttribute::GetValue<bool>'::`2'::defaultVal.m_pAttribute = nullptr;
              `CDmAttribute::GetValue<bool>'::`2'::defaultVal.m_Storage = false;
            }
            if ( (Attribute->m_nFlags & 0x1F) == 4 )
            {
              v15 = (CDmaVar<bool> *)Attribute->m_pData;
            }
            else if ( CDmAttribute::IsTypeConvertable<bool>(this: Attribute) )
            {
              CDmAttribute::CopyDataOut<bool>(this: v14, value: &`CDmAttribute::GetValue<bool>'::`7'::tempVal);
              v15 = (CDmaVar<bool> *)&`CDmAttribute::GetValue<bool>'::`7'::tempVal;
            }
            else
            {
              v15 = &`CDmAttribute::GetValue<bool>'::`2'::defaultVal;
            }
          }
          else
          {
            v15 = &`CDmElement::GetValue<bool>'::`2'::defaultVal;
          }
          m_Storage = v15->m_Storage;
          m_pMemory = (int)presetInfo[1].m_pMemory;
          v18 = 0;
          if ( m_pMemory <= 0 )
            goto LABEL_34;
          v19 = (PresetGroupInfo_t *)presetInfo->m_pMemory;
          while ( v19->presetGroupSym.u.m_Id != v30.m_Id )
          {
            ++v18;
            ++v19;
            if ( v18 >= m_pMemory )
              goto LABEL_34;
          }
          if ( v18 == -1 )
          {
LABEL_34:
            m_nAllocationCount = presetInfo->m_nAllocationCount;
            if ( m_pMemory + 1 > m_nAllocationCount )
              CUtlMemory<MDLSquenceLayer_t,int>::Grow(this: presetInfo, num: m_pMemory - m_nAllocationCount + 1);
            ++presetInfo[1].m_pMemory;
            v21 = (PresetGroupInfo_t *)presetInfo->m_pMemory;
            v22 = (int)presetInfo[1].m_pMemory - m_pMemory - 1;
            presetInfo[1].m_nAllocationCount = (int)presetInfo->m_pMemory;
            if ( v22 > 0 )
              _V_memmove(dest: &v21[m_pMemory + 1], src: &v21[m_pMemory], count: 8 * v22);
            v23 = (PresetGroupInfo_t *)&presetInfo->m_pMemory[m_pMemory];
            if ( v23 != nullptr )
            {
              bGroupReadOnly = info.bGroupReadOnly;
              v23->presetGroupSym.u = v30;
              bGroupVisible = info.bGroupVisible;
              v23->bGroupShared = m_Storage;
              v23->bGroupReadOnly = bGroupReadOnly;
              v23->bGroupVisible = bGroupVisible;
            }
          }
        }
        v8 = i + 1;
        i = v8;
        if ( v8 >= (int)pFilmClipa )
          break;
        m_pData = presetGroups.m_pStorage;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048BFD0
// Name: void CollectProceduralPresetNames(class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollectProceduralPresetNames(CUtlMemory<vgui::TreeNode *,int> *presetNames)
{
  int m_pMemory; // esi
  int m_nAllocationCount; // ecx
  CUtlSymbolLarge *v4; // ecx
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  int i; // edx
  _DWORD *v9; // eax
  int v10; // ebx
  const char *v11; // eax
  _DWORD *v12; // esi
  _BYTE v13[4]; // [esp+0h] [ebp-4h] BYREF
  CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > *presetNamesa; // [esp+Ch] [ebp+8h]

  if ( (`CollectProceduralPresetNames'::`2'::`local static guard' & 1) == 0 )
  {
    `CollectProceduralPresetNames'::`2'::`local static guard' |= 1u;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 200))(
      a1: g_pDataModel.u,
      a2: &`CollectProceduralPresetNames'::`2'::proceduralPresetGroupNameSymbol,
      a3: "Procedural");
  }
  m_pMemory = (int)presetNames[1].m_pMemory;
  m_nAllocationCount = presetNames->m_nAllocationCount;
  if ( m_pMemory + 20 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: presetNames, num: m_pMemory - m_nAllocationCount + 20);
  presetNames[1].m_pMemory += 5;
  v4 = (CUtlSymbolLarge *)presetNames->m_pMemory;
  v5 = (int)presetNames[1].m_pMemory - m_pMemory - 20;
  presetNames[1].m_nAllocationCount = (int)presetNames->m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &v4[m_pMemory + 20], src: &v4[m_pMemory], count: 4 * v5);
  v6 = 4 * m_pMemory;
  v7 = v6;
  for ( i = 20; i != 0; --i )
  {
    v9 = (vgui::TreeNode **)((char *)presetNames->m_pMemory + v7);
    if ( v9 != nullptr )
      *v9 = -1;
    v7 += 4;
  }
  v10 = 1;
  presetNamesa = (CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > *)v6;
  do
  {
    if ( (unsigned int)v10 > 0x14 )
      v11 = "???";
    else
      v11 = g_ProceduralPresetNames_12[v10];
    v12 = (CUtlSymbolLarge **)((char *)&presetNamesa->m_Memory.m_pMemory + (unsigned int)presetNames->m_pMemory);
    presetNamesa = (CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > *)((char *)presetNamesa + 4);
    ++v10;
    *v12 = *(_DWORD *)(*(int (__stdcall **)(_BYTE *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
                        a1: v13,
                        a2: v11);
  }
  while ( v10 < 21 );
}

//------------------------------------------------------------------------------
// Address: 0x0048C0D0
// Name: void CollectPresetNamesForGroup(class CDmeFilmClip __near *,char const __near *,class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CollectPresetNamesForGroup(
        CDmeFilmClip *pFilmClip,
        const char *pPresetGroupName,
        CUtlMemory<vgui::TreeNode *,int> *presetNames)
{
  int v3; // ebx
  CDmeAnimationSet *i; // eax
  CDmeTransformControl *PresetGroup; // eax
  const Vector *Position; // edi
  float x; // eax
  DmElementArray_t *m_pStorage; // eax
  int v9; // eax
  int v10; // edi
  const char *v11; // eax
  int m_pMemory; // edi
  int v13; // eax
  CUtlSymbolLarge *v14; // ecx
  int m_nAllocationCount; // eax
  CUtlSymbolLarge *v16; // ecx
  int v17; // eax
  CUtlSymbolLarge *v18; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-14h] BYREF
  CDmrElementArray<CDmePreset> presets; // [esp+14h] [ebp-Ch] BYREF
  CUtlSymbolLarge symPresetName; // [esp+1Ch] [ebp-4h] BYREF
  CDmeFilmClip *pFilmClipa; // [esp+28h] [ebp+8h]

  v3 = 0;
  traversal.m_pFilmClip = pFilmClip;
  traversal.m_nIndex = 0;
  for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal); i != nullptr; v3 = 0 )
  {
    PresetGroup = (CDmeTransformControl *)CDmeAnimationSet::FindPresetGroup(this: i, pGroupName: pPresetGroupName);
    if ( PresetGroup != nullptr )
    {
      Position = CDmeTransformControl::GetPosition(this: PresetGroup);
      CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&presets);
      x = Position[2].x;
      if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
      {
        m_pStorage = nullptr;
        presets.m_pAttribute = nullptr;
        presets.m_pStorage = nullptr;
        pFilmClipa = nullptr;
      }
      else
      {
        presets.m_pAttribute = (CDmAttribute *)LODWORD(Position[2].x);
        m_pStorage = *(DmElementArray_t **)(LODWORD(x) + 4);
        presets.m_pStorage = m_pStorage;
        pFilmClipa = (CDmeFilmClip *)m_pStorage->m_Size;
      }
      if ( (int)pFilmClipa > 0 )
      {
        while ( 1 )
        {
          v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: m_pStorage->m_Memory.m_pMemory[v3]);
          v10 = v9;
          if ( v9 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
                 a1: v9,
                 a2: CDmePreset::m_classType.u) != 0 )
          {
            v11 = *(const char **)(v10 + 20);
            if ( v11 == (const char *)-1 )
              v11 = defaultValue;
            (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
              a1: g_pDataModel.u,
              a2: &symPresetName,
              a3: v11);
            m_pMemory = (int)presetNames[1].m_pMemory;
            v13 = 0;
            if ( m_pMemory <= 0 )
              goto LABEL_20;
            v14 = (CUtlSymbolLarge *)presetNames->m_pMemory;
            while ( v14->u.m_Id != symPresetName.u.m_Id )
            {
              ++v13;
              ++v14;
              if ( v13 >= m_pMemory )
                goto LABEL_20;
            }
            if ( v13 == -1 )
            {
LABEL_20:
              m_nAllocationCount = presetNames->m_nAllocationCount;
              if ( m_pMemory + 1 > m_nAllocationCount )
                CUtlMemory<IDmFormatUpdater *,int>::Grow(this: presetNames, num: m_pMemory - m_nAllocationCount + 1);
              ++presetNames[1].m_pMemory;
              v16 = (CUtlSymbolLarge *)presetNames->m_pMemory;
              v17 = (int)presetNames[1].m_pMemory - m_pMemory - 1;
              presetNames[1].m_nAllocationCount = (int)presetNames->m_pMemory;
              if ( v17 > 0 )
                _V_memmove(dest: &v16[m_pMemory + 1], src: &v16[m_pMemory], count: 4 * v17);
              v18 = (CUtlSymbolLarge *)&presetNames->m_pMemory[m_pMemory];
              if ( v18 != nullptr )
                v18->u.m_Id = symPresetName.u.m_Id;
            }
          }
          if ( ++v3 >= (int)pFilmClipa )
            break;
          m_pStorage = presets.m_pStorage;
        }
      }
    }
    i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048C250
// Name: public: static void CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnShowAddPresetDialog::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnShowAddPresetDialog::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnShowAddPresetDialog::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnShowAddPresetDialog::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ShowAddPresetDialog";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048C2E0
// Name: public: static void CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetsChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetsChanged::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetsChanged::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetsChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PresetsChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048C370
// Name: public: static void CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnManagePresets::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnManagePresets::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnManagePresets::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnManagePresets::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ManagePresets";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048C400
// Name: public: static void CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetNameSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetNameSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetNameSelected::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetNameSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PresetNameSelected";
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
// Address: 0x0048C490
// Name: public: static void CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPageChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPageChanged::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded )
  {
    `CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPageChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
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
// Address: 0x0048C520
// Name: public: static void CPresetSlider::KB_AddToMap(char const __near *,enum ButtonCode_t,int,void (vgui::Panel::*)(void),char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPresetSlider::KB_AddToMap(
        const char *a1@<ebp>,
        const char *bindingname,
        ButtonCode_t defaultcode,
        int default_modifiers,
        __int128 function,
        __int64 helpstring,
        bool passive)
{
  vgui::PanelKeyBindingMap *v7; // esi
  _DWORD v8[3]; // [esp-Ch] [ebp-4Ch] BYREF
  vgui::KeyBindingMap_t entry; // [esp+0h] [ebp-40h] BYREF
  vgui::BoundKey_t kb; // [esp+30h] [ebp-10h]
  int retaddr; // [esp+40h] [ebp+0h]

  kb.bindingname = a1;
  kb.keycode = retaddr;
  v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetSlider");
  vgui::KeyBindingMap_t::KeyBindingMap_t(this: (vgui::KeyBindingMap_t *)v8);
  *(_OWORD *)(&entry.bindingname + 1) = function;
  *(_QWORD *)((char *)&entry.func + 4) = helpstring;
  v8[0] = bindingname;
  BYTE12(entry.func) = passive;
  CUtlVector<vgui::KeyBindingMap_t,CUtlMemory<vgui::KeyBindingMap_t,int>>::InsertBefore(
    this: &v7->entries,
    elem: v7->entries.m_Size,
    src: (const vgui::KeyBindingMap_t *)v8);
  vgui::BoundKey_t::BoundKey_t(this: (vgui::BoundKey_t *)&entry.docstring);
  *((_DWORD *)&entry.passive + 1) = defaultcode;
  LOBYTE(entry.docstring) = 1;
  *(_DWORD *)&entry.passive = bindingname;
  *(_DWORD *)&kb.isbuiltin = default_modifiers;
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
    this: &v7->defaultkeys,
    elem: v7->defaultkeys.m_Size,
    src: (const vgui::BoundKey_t *)&entry.docstring);
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
    this: &v7->boundkeys,
    elem: v7->boundkeys.m_Size,
    src: (const vgui::BoundKey_t *)&entry.docstring);
  vgui::BoundKey_t::~BoundKey_t(this: (vgui::BoundKey_t *)&entry.docstring);
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)v8);
}

//------------------------------------------------------------------------------
// Address: 0x0048C5F0
// Name: public: static void CPresetSlider::PanelMessageFunc_OnShowContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPresetSlider::PanelMessageFunc_OnShowContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CPresetSlider::PanelMessageFunc_OnShowContextMenu::InitVar'::`2'::bAdded )
  {
    `CPresetSlider::PanelMessageFunc_OnShowContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnShowContextMenu";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048C680
// Name: public: static void CPresetSlider::PanelMessageFunc_OnRename::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPresetSlider::PanelMessageFunc_OnRename::InitVar(int a1@<ebp>)
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
  if ( !`CPresetSlider::PanelMessageFunc_OnRename::InitVar'::`2'::bAdded )
  {
    `CPresetSlider::PanelMessageFunc_OnRename::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnRename";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048C710
// Name: public: static void CPresetSlider::PanelMessageFunc_OnDelete::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPresetSlider::PanelMessageFunc_OnDelete::InitVar(int a1@<ebp>)
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
  if ( !`CPresetSlider::PanelMessageFunc_OnDelete::InitVar'::`2'::bAdded )
  {
    `CPresetSlider::PanelMessageFunc_OnDelete::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Panel::`vcall'{400,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnDelete";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048C7A0
// Name: public: static void CPresetSlider::PanelMessageFunc_OnInputCompleted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPresetSlider::PanelMessageFunc_OnInputCompleted::InitVar(int a1@<ebp>)
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
  if ( !`CPresetSlider::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded )
  {
    `CPresetSlider::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
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
// Address: 0x0048C830
// Name: public: static void CPresetSlider::PanelMessageFunc_OnDeleteConfirmed::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPresetSlider::PanelMessageFunc_OnDeleteConfirmed::InitVar(int a1@<ebp>)
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
  if ( !`CPresetSlider::PanelMessageFunc_OnDeleteConfirmed::InitVar'::`2'::bAdded )
  {
    `CPresetSlider::PanelMessageFunc_OnDeleteConfirmed::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnDeleteConfirmed";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048C8C0
// Name: public: void CAddPresetDialog::DoModal(class CDmeFilmClip __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAddPresetDialog::DoModal(
        CAddPresetDialog *this,
        CDmeFilmClip *pFilmClip,
        const char *pCurrentGroupName,
        KeyValues *pContextKeyValues)
{
  KeyValues *v5; // esi
  const char *m_pAsString; // edi
  KeyValues *v7; // eax
  int v8; // esi
  CUtlVector<PresetGroupInfo_t,CUtlMemory<PresetGroupInfo_t,int> > presetGroupInfo; // [esp+8h] [ebp-14h] BYREF
  int i; // [esp+24h] [ebp+8h]

  vgui::ComboBox::RemoveAll(this: this->m_pPresetGroup);
  v5 = nullptr;
  memset(&presetGroupInfo, 0, sizeof(presetGroupInfo));
  CollectPresetGroupInfo(
    pFilmClip,
    presetInfo: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&presetGroupInfo,
    bSkipReadOnly: true,
    bSkipInvisible: false);
  for ( i = 0; i < presetGroupInfo.m_Size; ++i )
  {
    m_pAsString = presetGroupInfo.m_Memory.m_pMemory[i].presetGroupSym.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v5 = KeyValues::KeyValues(this: v7, setName: "entry");
    KeyValues::SetString(this: v5, keyName: "presetGroupName", value: m_pAsString);
    v8 = this->m_pPresetGroup->AddItem_2(this: this->m_pPresetGroup, a2: m_pAsString, a3: v5);
    if ( pCurrentGroupName != nullptr && _V_stricmp(s1: m_pAsString, s2: pCurrentGroupName) == 0 )
      this->m_pPresetGroup->ActivateItem(this: this->m_pPresetGroup, a2: v8);
    v5 = nullptr;
  }
  vgui::BaseInputDialog::DoModal(this, pContextKeyValues);
  this->m_pPresetName->SetText(this: this->m_pPresetName, a2: defaultValue);
  this->m_pPresetName->RequestFocus(this: this->m_pPresetName, a2: 0);
  vgui::Frame::PlaceUnderCursor(this);
  if ( presetGroupInfo.m_Memory.m_nGrowSize >= 0 && presetGroupInfo.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: presetGroupInfo.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0048C9F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPresetSlider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPresetSlider::GetMessageMap(CPresetSlider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPresetSlider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPresetSlider::GetMessageMap'::`2'::s_pMap;
  `CPresetSlider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
  `CPresetSlider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048CA20
// Name: public: virtual struct PanelAnimationMap __near * CPresetSlider::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPresetSlider::GetAnimMap(CPresetSlider *this)
{
  return FindOrAddPanelAnimationMap(className: "CPresetSlider");
}

//------------------------------------------------------------------------------
// Address: 0x0048CA30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPresetSlider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPresetSlider::GetKBMap(CPresetSlider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPresetSlider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPresetSlider::GetKBMap'::`2'::s_pMap;
  `CPresetSlider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetSlider");
  `CPresetSlider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048CA60
// Name: public: static void CSliderListPanel::PanelMessageFunc_OnShowContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSliderListPanel::PanelMessageFunc_OnShowContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CSliderListPanel::PanelMessageFunc_OnShowContextMenu::InitVar'::`2'::bAdded )
  {
    `CSliderListPanel::PanelMessageFunc_OnShowContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::RichText::`vcall'{872,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSliderListPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnShowContextMenu";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048CAF0
// Name: public: CSliderListPanel::CSliderListPanel(class CBaseAnimSetPresetFaderPanel __near *,class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSliderListPanel *__thiscall CSliderListPanel::CSliderListPanel(
        CSliderListPanel *this,
        CBaseAnimSetPresetFaderPanel *pFader,
        vgui::Panel *pParent,
        const char *panelName)
{
  vgui::PanelMessageMap *v5; // esi
  PanelAnimationMap *v6; // esi
  vgui::PanelKeyBindingMap *v7; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::PanelListPanel::PanelListPanel(this, parent: pParent, panelName);
  this->__vftable = (CSliderListPanel_vtbl *)&CSliderListPanel::`vftable';
  if ( `CSliderListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CSliderListPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CSliderListPanel");
    v5->pfnClassName = CSliderListPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PanelListPanel");
  }
  if ( `CSliderListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSliderListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CSliderListPanel");
    v6->pfnClassName = CSliderListPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PanelListPanel");
  }
  if ( `CSliderListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSliderListPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CSliderListPanel");
    v7->pfnClassName = CSliderListPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PanelListPanel");
  }
  CSliderListPanel::PanelMessageFunc_OnShowContextMenu::InitVar(a1: (int)&savedregs);
  this->m_hContextMenu.m_iPanelID = -1;
  this->m_pPresetFaderPanel = pFader;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0048CBD0
// Name: public: virtual struct vgui::PanelMessageMap __near * CSliderListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSliderListPanel::GetMessageMap(CSliderListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSliderListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSliderListPanel::GetMessageMap'::`2'::s_pMap;
  `CSliderListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSliderListPanel");
  `CSliderListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048CC00
// Name: public: virtual struct PanelAnimationMap __near * CSliderListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSliderListPanel::GetAnimMap(CSliderListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CSliderListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0048CC10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSliderListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSliderListPanel::GetKBMap(CSliderListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSliderListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSliderListPanel::GetKBMap'::`2'::s_pMap;
  `CSliderListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSliderListPanel");
  `CSliderListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048CC40
// Name: protected: virtual void CBaseAnimSetPresetFaderPanel::OnShowAddPresetDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::OnShowAddPresetDialog(CBaseAnimSetPresetFaderPanel *this)
{
  CAddPresetDialog *v2; // eax
  CAddPresetDialog *v3; // edi
  vgui::Panel *v4; // eax
  const char *v5; // eax
  CDmeFilmClip *AnimationSetClip; // eax
  const char *v7; // [esp-Ch] [ebp-10h]

  if ( CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController) != nullptr )
  {
    v2 = (CAddPresetDialog *)MemAlloc_Alloc(nSize: 0x230u);
    if ( v2 != nullptr )
      v3 = CAddPresetDialog::CAddPresetDialog(this: v2, parent: this);
    else
      v3 = nullptr;
    v3->AddActionSignalTarget_2(this: v3, a2: this);
    if ( this->m_pSheet->GetActivePage(this: this->m_pSheet) != nullptr )
    {
      v4 = this->m_pSheet->GetActivePage(this: this->m_pSheet);
      v5 = v4->GetName(this: v4);
    }
    else
    {
      v5 = defaultValue;
    }
    v7 = v5;
    AnimationSetClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
    CAddPresetDialog::DoModal(this: v3, pFilmClip: AnimationSetClip, pCurrentGroupName: v7, pContextKeyValues: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048CCD0
// Name: public: void CParallelProcessor<class CPresetSlider __near *,class CFuncJobItemProcessor<class CPresetSlider __near *>,1>::Run(class CPresetSlider __near * __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::Run(
        CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *this,
        CPresetSlider **pItems,
        int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  IThreadPool *v7; // esi
  int v8; // eax
  int v9; // edi
  int v10; // eax
  void *v11; // esp
  CFunctor *v12; // eax
  CFunctor v13; // xmm0_8
  CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *v14; // ecx
  int i; // esi
  _DWORD v16[3]; // [esp+0h] [ebp-20h]
  CFunctor v17; // [esp+Ch] [ebp-14h]
  CFunctor v18; // [esp+14h] [ebp-Ch]
  CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *v19; // [esp+1Ch] [ebp-4h]
  int nJobs; // [esp+2Ch] [ebp+Ch]

  v19 = this;
  if ( nItems != 0 )
  {
    v7 = pThreadPool;
    this->m_nChunkSize = nChunkSize;
    if ( v7 == nullptr )
      v7 = _g_pThreadPool;
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v8 = nMaxParallel;
    v9 = nItems - 1;
    this->m_pLimit = &pItems[nItems];
    nJobs = v9;
    if ( v9 > v8 )
    {
      nJobs = v8;
      v9 = v8;
    }
    if ( v7 == nullptr )
      goto LABEL_18;
    v10 = v7->NumThreads(this: v7);
    if ( v9 > v10 )
    {
      nJobs = v10;
      v9 = v10;
    }
    if ( v9 > 0 )
    {
      v11 = alloca(4 * v9);
      v17.__vftable = (CFunctor_vtbl *)CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::DoExecute;
      v17.m_nUserID = 0;
      v18 = 0;
      do
      {
        --v9;
        v12 = (CFunctor *)MemAlloc_Alloc(nSize: 0x28u);
        if ( v12 != nullptr )
        {
          v13 = v17;
          v14 = v19;
          v12[1].m_nUserID = 1;
          v12->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *,void (__thiscall CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v12[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> *,void (__thiscall CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v12[2] = v13;
          v12[3] = v18;
          v12[4].__vftable = (CFunctor_vtbl *)v14;
        }
        else
        {
          v12 = nullptr;
        }
        v7->AddFunctorInternal(this: v7, a2: v12, a3: (CJob **)&nChunkSize, a4: nullptr, a5: 8u);
        v16[v9] = nChunkSize;
      }
      while ( v9 != 0 );
      CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::DoExecute(this: v19);
      for ( i = 0; i < nJobs; ++i )
      {
        CJob::Abort(this: (CJob *)v16[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v16[i] + 4))(a1: v16[i]);
      }
    }
    else
    {
LABEL_18:
      CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::DoExecute(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048CE10
// Name: public: CPresetSlider::CPresetSlider(class vgui::Panel __near *,class CBaseAnimSetPresetFaderPanel __near *)
// Source: json
//------------------------------------------------------------------------------
CPresetSlider *__thiscall CPresetSlider::CPresetSlider(
        CPresetSlider *this,
        vgui::Panel *parent,
        CBaseAnimSetPresetFaderPanel *pFaderPanel)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax
  __int128 v11; // [esp-1Ch] [ebp-38h]
  __int128 v12; // [esp-1Ch] [ebp-38h]
  __int128 v13; // [esp-1Ch] [ebp-38h]
  __int128 v14; // [esp-1Ch] [ebp-38h]
  __int64 v15; // [esp+14h] [ebp-8h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  vgui::Slider::Slider(this, parent, panelName: "preset");
  this->__vftable = (CPresetSlider_vtbl *)&CPresetSlider::`vftable';
  if ( `CPresetSlider::ChainToMap'::`2'::chained == 0 )
  {
    `CPresetSlider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CPresetSlider");
    v4->pfnClassName = CPresetSlider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Slider");
  }
  if ( `CPresetSlider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPresetSlider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CPresetSlider");
    v5->pfnClassName = CPresetSlider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Slider");
  }
  if ( `CPresetSlider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPresetSlider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetSlider");
    v6->pfnClassName = CPresetSlider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Slider");
  }
  CPresetSlider::PanelMessageFunc_OnShowContextMenu::InitVar(a1: (int)&savedregs);
  CPresetSlider::PanelMessageFunc_OnRename::InitVar(a1: (int)&savedregs);
  CPresetSlider::PanelMessageFunc_OnDelete::InitVar(a1: (int)&savedregs);
  CPresetSlider::PanelMessageFunc_OnInputCompleted::InitVar(a1: (int)&savedregs);
  CPresetSlider::PanelMessageFunc_OnDeleteConfirmed::InitVar(a1: (int)&savedregs);
  if ( `CPresetSlider::PanelKBMapFunc_ts_curve_1::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v11 = (unsigned int) __thiscall CDmePanel::`vcall'{960,{flat}};
    v15 = 0;
    `CPresetSlider::PanelKBMapFunc_ts_curve_1::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v11 + 1) = 0;
    CPresetSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_1",
      defaultcode: KEY_1,
      default_modifiers: 0,
      function: v11,
      helpstring: (unsigned int)"#ts_curve1_help",
      passive: false);
  }
  if ( `CPresetSlider::PanelKBMapFunc_ts_curve_2::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v12 = (unsigned int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    v15 = 0;
    `CPresetSlider::PanelKBMapFunc_ts_curve_2::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v12 + 1) = 0;
    CPresetSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_2",
      defaultcode: KEY_2,
      default_modifiers: 0,
      function: v12,
      helpstring: (unsigned int)"#ts_curve2_help",
      passive: false);
  }
  if ( `CPresetSlider::PanelKBMapFunc_ts_curve_3::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v13 = (unsigned int) __thiscall CAttributeSlider::`vcall'{968,{flat}};
    v15 = 0;
    `CPresetSlider::PanelKBMapFunc_ts_curve_3::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v13 + 1) = 0;
    CPresetSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_3",
      defaultcode: KEY_3,
      default_modifiers: 0,
      function: v13,
      helpstring: (unsigned int)"#ts_curve3_help",
      passive: false);
  }
  if ( `CPresetSlider::PanelKBMapFunc_ts_curve_4::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v14 = (unsigned int) __thiscall CDmePresetGroupEditorPanel::`vcall'{972,{flat}};
    v15 = 0;
    `CPresetSlider::PanelKBMapFunc_ts_curve_4::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v14 + 1) = 0;
    CPresetSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_4",
      defaultcode: KEY_4,
      default_modifiers: 0,
      function: v14,
      helpstring: (unsigned int)"#ts_curve4_help",
      passive: false);
  }
  this->m_pPresetFaderPanel = pFaderPanel;
  this->m_GradientColor = 0;
  this->m_ZeroColor = 0;
  this->m_TextColor = 0;
  this->m_TextColorFocus = 0;
  this->m_hContextMenu.m_iPanelID = -1;
  this->m_AttributeLookup.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const DmElementHandle_t *, const DmElementHandle_t *))CDefOps<DmeTime_t>::LessFunc;
  this->m_AttributeLookup.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_AttributeLookup.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_AttributeLookup.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_AttributeLookup.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_AttributeLookup.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_AttributeLookup.m_Tree.m_FirstFree = -1;
  this->m_AttributeLookup.m_Tree.m_pElements = m_pMemory;
  this->m_presetGroupName.u.m_Id = -1;
  this->m_presetName.u.m_Id = -1;
  this->m_nProceduralType = 0;
  *(_WORD *)&this->m_bReadOnly = 0;
  vgui::Slider::SetRange(this, min: 0, max: 1000);
  vgui::Slider::SetDragOnRepositionNob(this, state: true);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
  if ( v8 != nullptr )
    v9 = vgui::TextImage::TextImage(this: v8, text: defaultValue);
  else
    v9 = nullptr;
  this->m_pName = v9;
  this->m_ZeroColor = (Color)-12237499;
  this->m_GradientColor = (Color)-16746302;
  this->m_TextColor = (Color)-3618616;
  this->m_TextColorFocus = (Color)-14118960;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0048D180
// Name: public: CBaseAnimSetPresetFaderPanel::CBaseAnimSetPresetFaderPanel(class vgui::Panel __near *,char const __near *,class CBaseAnimationSetEditor __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimSetPresetFaderPanel *__thiscall CBaseAnimSetPresetFaderPanel::CBaseAnimSetPresetFaderPanel(
        CBaseAnimSetPresetFaderPanel *this,
        vgui::Panel *parent,
        const char *className,
        CBaseAnimationSetEditor *editor)
{
  vgui::PanelMessageMap *v5; // esi
  PanelAnimationMap *v6; // esi
  vgui::PanelKeyBindingMap *v7; // esi
  vgui::PropertySheet *v8; // eax
  vgui::PropertySheet *v9; // eax
  CSliderListPanel *v10; // eax
  CSliderListPanel *v11; // eax
  CPresetSlider **m_pMemory; // eax
  IMemAlloc_vtbl *v13; // edx
  CPresetSlider **v14; // eax
  CPresetSlider *v15; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CPresetSlider **v18; // ecx
  int v19; // eax
  CPresetSlider **v20; // ebx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  int parenta; // [esp+14h] [ebp+8h]
  const char *classNamea; // [esp+18h] [ebp+Ch]

  vgui::EditablePanel::EditablePanel(this, parent, panelName: className);
  this->__vftable = (CBaseAnimSetPresetFaderPanel_vtbl *)&CBaseAnimSetPresetFaderPanel::`vftable';
  if ( `CBaseAnimSetPresetFaderPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetPresetFaderPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
    v5->pfnClassName = CBaseAnimSetPresetFaderPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAnimSetPresetFaderPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetPresetFaderPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CBaseAnimSetPresetFaderPanel");
    v6->pfnClassName = CBaseAnimSetPresetFaderPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAnimSetPresetFaderPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetPresetFaderPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimSetPresetFaderPanel");
    v7->pfnClassName = CBaseAnimSetPresetFaderPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnShowAddPresetDialog::InitVar(a1: (int)&savedregs);
  CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetsChanged::InitVar(a1: (int)&savedregs);
  CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnManagePresets::InitVar(a1: (int)&savedregs);
  CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPresetNameSelected::InitVar(a1: (int)&savedregs);
  CBaseAnimSetPresetFaderPanel::PanelMessageFunc_OnPageChanged::InitVar(a1: (int)&savedregs);
  this->m_presetGroupPages.m_Memory.m_pMemory = nullptr;
  this->m_presetGroupPages.m_Memory.m_nAllocationCount = 0;
  this->m_presetGroupPages.m_Memory.m_nGrowSize = 0;
  this->m_presetGroupPages.m_Size = 0;
  this->m_presetGroupPages.m_pElements = nullptr;
  this->m_presetSliders.m_Memory.m_pMemory = nullptr;
  this->m_presetSliders.m_Memory.m_nAllocationCount = 0;
  this->m_presetSliders.m_Memory.m_nGrowSize = 0;
  this->m_presetSliders.m_Size = 0;
  this->m_presetSliders.m_pElements = nullptr;
  this->m_hPresetEditor.m_iPanelID = -1;
  this->m_hActivePresetSlider.m_iPanelID = -1;
  this->m_pController = CBaseAnimationSetEditor::GetController(this: editor);
  v8 = (vgui::PropertySheet *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v8 != nullptr )
    v9 = vgui::PropertySheet::PropertySheet(
           this: v8,
           parent: this,
           panelName: "presetPropertySheet",
           draggableTabs: false);
  else
    v9 = nullptr;
  this->m_pSheet = v9;
  vgui::Panel::SetAutoResize(
    this: v9,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  this->m_pSheet->SetSmallTabs(this: this->m_pSheet, a2: true);
  v10 = (CSliderListPanel *)MemAlloc_Alloc(nSize: 0x1B8u);
  if ( v10 != nullptr )
    v11 = CSliderListPanel::CSliderListPanel(this: v10, pFader: this, pParent: nullptr, panelName: "PresetSliders");
  else
    v11 = nullptr;
  this->m_pSliders = v11;
  vgui::PanelListPanel::SetFirstColumnWidth(this: v11, width: 0);
  vgui::Panel::SetAutoResize(
    this: this->m_pSliders,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  vgui::Panel::SetPos(this: this->m_pSliders, x: 0, y: 0);
  vgui::PanelListPanel::SetVerticalBufferPixels(this: this->m_pSliders, buffer: 0);
  if ( this->m_presetSliders.m_Memory.m_nAllocationCount < 400 && this->m_presetSliders.m_Memory.m_nGrowSize >= 0 )
  {
    this->m_presetSliders.m_Memory.m_nAllocationCount = 400;
    m_pMemory = this->m_presetSliders.m_Memory.m_pMemory;
    v13 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v14 = (CPresetSlider **)((int (__stdcall *)(CPresetSlider **, int))v13->Realloc_2)(a1: m_pMemory, a2: 1600);
    else
      v14 = (CPresetSlider **)((int (__stdcall *)(int))v13->Alloc_2)(a1: 1600);
    this->m_presetSliders.m_Memory.m_pMemory = v14;
  }
  this->m_presetSliders.m_pElements = this->m_presetSliders.m_Memory.m_pMemory;
  for ( parenta = 400; parenta != 0; --parenta )
  {
    v15 = (CPresetSlider *)MemAlloc_Alloc(nSize: 0x200u);
    if ( v15 != nullptr )
      classNamea = (const char *)CPresetSlider::CPresetSlider(this: v15, parent: nullptr, pFaderPanel: this);
    else
      classNamea = nullptr;
    m_Size = this->m_presetSliders.m_Size;
    m_nAllocationCount = this->m_presetSliders.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_presetSliders,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_presetSliders.m_Size;
    v18 = this->m_presetSliders.m_Memory.m_pMemory;
    v19 = this->m_presetSliders.m_Size - m_Size - 1;
    this->m_presetSliders.m_pElements = v18;
    if ( v19 > 0 )
      _V_memmove(dest: &v18[m_Size + 1], src: &v18[m_Size], count: 4 * v19);
    v20 = &this->m_presetSliders.m_Memory.m_pMemory[m_Size];
    if ( v20 != nullptr )
      *v20 = (CPresetSlider *)classNamea;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0048D450
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAnimSetPresetFaderPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAnimSetPresetFaderPanel::GetMessageMap(CBaseAnimSetPresetFaderPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAnimSetPresetFaderPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimSetPresetFaderPanel::GetMessageMap'::`2'::s_pMap;
  `CBaseAnimSetPresetFaderPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetPresetFaderPanel");
  `CBaseAnimSetPresetFaderPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048D480
// Name: public: virtual struct PanelAnimationMap __near * CBaseAnimSetPresetFaderPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAnimSetPresetFaderPanel::GetAnimMap(CBaseAnimSetPresetFaderPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAnimSetPresetFaderPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0048D490
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAnimSetPresetFaderPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAnimSetPresetFaderPanel::GetKBMap(CBaseAnimSetPresetFaderPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAnimSetPresetFaderPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimSetPresetFaderPanel::GetKBMap'::`2'::s_pMap;
  `CBaseAnimSetPresetFaderPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimSetPresetFaderPanel");
  `CBaseAnimSetPresetFaderPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048D500
// Name: protected: void CBaseAnimSetPresetFaderPanel::UpdateOrCreatePresetSlider(int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::UpdateOrCreatePresetSlider(
        CBaseAnimSetPresetFaderPanel *this,
        int nSlot,
        const char *pPresetGroupName,
        const char *pPresetName)
{
  CPresetSlider *v5; // eax
  CPresetSlider *v6; // esi
  CSliderListPanel *m_pSliders; // ecx
  CSliderListPanel_vtbl *v8; // esi
  int ItemIDFromRow; // eax
  int v10; // eax

  if ( pPresetName != nullptr )
  {
    if ( nSlot < vgui::PanelListPanel::GetItemCount(this: (vgui::TextEntry *)this->m_pSliders) )
    {
      m_pSliders = this->m_pSliders;
      v8 = m_pSliders->__vftable;
      ItemIDFromRow = vgui::PanelListPanel::GetItemIDFromRow(this: m_pSliders, nRow: nSlot);
      v6 = (CPresetSlider *)v8->GetItemPanel(this: this->m_pSliders, a2: ItemIDFromRow);
    }
    else
    {
      v5 = (CPresetSlider *)MemAlloc_Alloc(nSize: 0x200u);
      if ( v5 != nullptr )
        v6 = CPresetSlider::CPresetSlider(this: v5, parent: this->m_pSliders, pFaderPanel: this);
      else
        v6 = nullptr;
      this->m_pSliders->AddItem(this: this->m_pSliders, a2: nullptr, a3: v6);
    }
    if ( v6 != nullptr )
    {
      CPresetSlider::Init(this: v6, pPresetGroupName, pPresetName);
      v6->SetValue(this: v6, a2: 0, a3: false);
      vgui::Panel::SetSize(this: v6, wide: 100, tall: 20);
      v10 = vgui::PanelListPanel::GetItemIDFromRow(this: this->m_pSliders, nRow: nSlot);
      vgui::PanelListPanel::SetItemVisible(this: this->m_pSliders, nItemID: v10, bVisible: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048D5D0
// Name: public: void CPresetSlider::SetControlValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::SetControlValues(CPresetSlider *this)
{
  CPresetSlider *v1; // edi
  const char *PresetGroupName; // eax
  CDmeAnimationSet *v3; // edx
  const char *PresetName; // eax
  CDmePresetGroup *v5; // edx
  CDmeTransform *Preset; // eax
  const Vector *Position; // esi
  float x; // eax
  int v9; // eax
  UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short> *v11; // eax
  int v12; // eax
  int v13; // eax
  CDmElement *v14; // edi
  const char *m_pAsString; // eax
  CExpressionCalculator *Control; // eax
  DmElementHandle_t BufferType; // eax
  CPresetSlider *v18; // esi
  unsigned __int16 v19; // ax
  float *m_pValue; // esi
  CDmAttribute *Attribute; // eax
  CDmAttribute *v22; // eax
  CDmAttribute *v23; // eax
  CDmAttribute *v24; // eax
  CDmAttribute *v25; // eax
  unsigned int v26; // [esp-4h] [ebp-88h]
  CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t search; // [esp+Ch] [ebp-78h] BYREF
  CAnimSetGroupAnimSetTraversal traversal; // [esp+60h] [ebp-24h] BYREF
  CDmrElementArray<CDmElement> values; // [esp+68h] [ebp-1Ch] BYREF
  DmElementHandle_t handle; // [esp+70h] [ebp-14h] BYREF
  int i; // [esp+74h] [ebp-10h]
  CDmeAnimationSet *pAnimSet; // [esp+78h] [ebp-Ch]
  CPresetSlider *v33; // [esp+7Ch] [ebp-8h]
  int m_Size; // [esp+80h] [ebp-4h]

  v1 = this;
  v33 = this;
  CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_AttributeLookup.m_Tree);
  if ( v1->m_nProceduralType == 0 )
  {
    traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: v1->m_pPresetFaderPanel->m_pController);
    traversal.m_nIndex = 0;
    for ( pAnimSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
          pAnimSet != nullptr;
          pAnimSet = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
    {
      PresetGroupName = CPresetSlider::GetPresetGroupName(this: v1);
      if ( CDmeAnimationSet::FindPresetGroup(this: v3, pGroupName: PresetGroupName) != nullptr )
      {
        PresetName = CPresetSlider::GetPresetName(this: v1);
        Preset = (CDmeTransform *)CDmePresetGroup::FindPreset(this: v5, pPresetName: PresetName);
        if ( Preset != nullptr )
        {
          Position = CDmeTransform::GetPosition(this: Preset);
          CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&values);
          x = Position[2].x;
          if ( x == 0.0 || (*(_BYTE *)(LODWORD(x) + 16) & 0x1F) != 0xF )
          {
            values.m_pAttribute = nullptr;
            values.m_pStorage = nullptr;
            m_Size = 0;
          }
          else
          {
            values.m_pAttribute = (CDmAttribute *)LODWORD(Position[2].x);
            values.m_pStorage = *(DmElementArray_t **)(LODWORD(x) + 4);
            m_Size = values.m_pStorage->m_Size;
          }
          v9 = m_Size + v1->m_AttributeLookup.m_Tree.m_NumElements;
          if ( v1->m_AttributeLookup.m_Tree.m_Elements.m_nAllocationCount < v9
            && v1->m_AttributeLookup.m_Tree.m_Elements.m_nGrowSize >= 0 )
          {
            m_pMemory = v1->m_AttributeLookup.m_Tree.m_Elements.m_pMemory;
            v1->m_AttributeLookup.m_Tree.m_Elements.m_nAllocationCount = v9;
            v26 = 92 * v9;
            if ( m_pMemory != nullptr )
              v11 = (UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v26);
            else
              v11 = (UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v26);
            v1->m_AttributeLookup.m_Tree.m_Elements.m_pMemory = v11;
          }
          v12 = 0;
          i = 0;
          if ( m_Size > 0 )
          {
            do
            {
              v13 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: values.m_pStorage->m_Memory.m_pMemory[v12]);
              v14 = (CDmElement *)v13;
              if ( v13 != 0
                && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v13 + 16))(
                     a1: v13,
                     a2: CDmElement::m_classType.u) != 0 )
              {
                m_pAsString = v14->m_Name.m_Storage.u.m_pAsString;
                if ( m_pAsString == (const char *)-1 )
                  m_pAsString = defaultValue;
                Control = (CExpressionCalculator *)CDmeAnimationSet::FindControl(
                                                     this: pAnimSet,
                                                     pControlName: m_pAsString);
                if ( Control != nullptr )
                {
                  BufferType = CCodecBuffer_Block::GetBufferType(this: Control);
                  v18 = v33;
                  memset(&search.elem, 0, 24);
                  search.elem.m_Quaternion = quat_identity;
                  handle = BufferType;
                  memset(search.elem.m_pValueAttribute, 0, 40);
                  search.key = BufferType;
                  v19 = CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                          this: &v33->m_AttributeLookup.m_Tree,
                          &search);
                  if ( v19 == 0xFFFF )
                    v19 = CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Insert(
                            this: &v18->m_AttributeLookup,
                            key: &handle);
                  m_pValue = v18->m_AttributeLookup.m_Tree.m_Elements.m_pMemory[v19].m_Data.elem.m_pValue;
                  _V_memset(dest: m_pValue, fill: 0, count: 80);
                  *(Quaternion *)(m_pValue + 6) = quat_identity;
                  Attribute = CDmElement::FindAttribute(this: v14, pAttributeName: "value");
                  if ( Attribute != nullptr )
                  {
                    *((_DWORD *)m_pValue + 10) = Attribute;
                    *m_pValue = *CDmAttribute::GetValue<float>(this: Attribute);
                  }
                  else
                  {
                    *((_DWORD *)m_pValue + 10) = CDmElement::FindAttribute(this: v14, pAttributeName: "values");
                    *((_DWORD *)m_pValue + 15) = CDmElement::FindAttribute(this: v14, pAttributeName: "times");
                  }
                  v22 = CDmElement::FindAttribute(this: v14, pAttributeName: "leftValue");
                  if ( v22 != nullptr )
                  {
                    *((_DWORD *)m_pValue + 12) = v22;
                    m_pValue[2] = *CDmAttribute::GetValue<float>(this: v22);
                  }
                  else
                  {
                    *((_DWORD *)m_pValue + 12) = CDmElement::FindAttribute(this: v14, pAttributeName: "leftValues");
                    *((_DWORD *)m_pValue + 17) = CDmElement::FindAttribute(this: v14, pAttributeName: "leftTimes");
                  }
                  v23 = CDmElement::FindAttribute(this: v14, pAttributeName: "rightValue");
                  if ( v23 != nullptr )
                  {
                    *((_DWORD *)m_pValue + 11) = v23;
                    m_pValue[1] = *CDmAttribute::GetValue<float>(this: v23);
                  }
                  else
                  {
                    *((_DWORD *)m_pValue + 11) = CDmElement::FindAttribute(this: v14, pAttributeName: "rightValues");
                    *((_DWORD *)m_pValue + 16) = CDmElement::FindAttribute(this: v14, pAttributeName: "rightTimes");
                  }
                  v24 = CDmElement::FindAttribute(this: v14, pAttributeName: "valuePosition");
                  if ( v24 != nullptr )
                  {
                    *((_DWORD *)m_pValue + 13) = v24;
                    *((Vector *)m_pValue + 1) = CDmAttribute::GetValue<Vector>(this: v24)->m_Storage;
                  }
                  else
                  {
                    *((_DWORD *)m_pValue + 13) = CDmElement::FindAttribute(this: v14, pAttributeName: "valuePositions");
                    *((_DWORD *)m_pValue + 18) = CDmElement::FindAttribute(this: v14, pAttributeName: "timePositions");
                  }
                  v25 = CDmElement::FindAttribute(this: v14, pAttributeName: "valueOrientation");
                  if ( v25 != nullptr )
                  {
                    *((_DWORD *)m_pValue + 14) = v25;
                    *(Quaternion *)(m_pValue + 6) = *CDmAttribute::GetValue<Quaternion>(this: v25);
                  }
                  else
                  {
                    *((_DWORD *)m_pValue + 14) = CDmElement::FindAttribute(
                                                   this: v14,
                                                   pAttributeName: "valueOrientations");
                    *((_DWORD *)m_pValue + 19) = CDmElement::FindAttribute(
                                                   this: v14,
                                                   pAttributeName: "timeOrientations");
                  }
                }
              }
              v12 = i + 1;
              i = v12;
            }
            while ( v12 < m_Size );
            v1 = v33;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048D9A0
// Name: Parallel_UpdateControlValues
// Source: json
//------------------------------------------------------------------------------
void __cdecl Parallel_UpdateControlValues(CPresetSlider **slider)
{
  CPresetSlider::SetControlValues(this: *slider);
}

//------------------------------------------------------------------------------
// Address: 0x0048D9B0
// Name: public: void CBaseAnimSetPresetFaderPanel::UpdateControlValues(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::UpdateControlValues(
        CBaseAnimSetPresetFaderPanel *this,
        bool bVisibleOnly)
{
  vgui::TextEntry *m_pSliders; // ecx
  int ItemCount; // esi
  IMemAlloc_vtbl *v5; // edx
  CPresetSlider **v6; // eax
  vgui::ScrollBarSlider *i; // esi
  CPresetSlider *v8; // eax
  _BYTE *m_Id; // ecx
  int m_Size; // eax
  CPresetSlider **m_pMemory; // ecx
  int j; // esi
  CPresetSlider **v13; // eax
  CUtlVectorFixedGrowable<CPresetSlider *,100> workItems; // [esp+Ch] [ebp-1C4h] BYREF
  CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1> v15; // [esp+1B4h] [ebp-1Ch] BYREF
  CPresetSlider *pSlider; // [esp+1CCh] [ebp-4h] BYREF

  workItems.m_pElements = workItems.m_Memory.m_pFixedMemory;
  m_pSliders = (vgui::TextEntry *)this->m_pSliders;
  workItems.m_Memory.m_pMemory = workItems.m_Memory.m_pFixedMemory;
  workItems.m_Memory.m_nAllocationCount = 100;
  workItems.m_Memory.m_nGrowSize = -1;
  workItems.m_Memory.m_nMallocGrowSize = 0;
  workItems.m_Size = 0;
  ItemCount = vgui::PanelListPanel::GetItemCount(this: m_pSliders);
  if ( ItemCount > 100 )
  {
    CUtlMemory<CPresetSlider *,int>::ConvertToGrowableMemory(
      this: &workItems.m_Memory,
      nGrowSize: workItems.m_Memory.m_nMallocGrowSize);
    if ( workItems.m_Memory.m_nAllocationCount < ItemCount && workItems.m_Memory.m_nGrowSize >= 0 )
    {
      workItems.m_Memory.m_nAllocationCount = ItemCount;
      v5 = _g_pMemAlloc->__vftable;
      if ( workItems.m_Memory.m_pMemory != nullptr )
        v6 = (CPresetSlider **)((int (__stdcall *)(CPresetSlider **, int))v5->Realloc_2)(
                                 a1: workItems.m_Memory.m_pMemory,
                                 a2: 4 * ItemCount);
      else
        v6 = (CPresetSlider **)((int (__stdcall *)(int))v5->Alloc_2)(a1: 4 * ItemCount);
      workItems.m_Memory.m_pMemory = v6;
    }
  }
  workItems.m_pElements = workItems.m_Memory.m_pMemory;
  for ( i = vgui::ScrollBar::GetSlider(this: (vgui::ScrollBar *)this->m_pSliders);
        i != (vgui::ScrollBarSlider *)vgui::TreeView::InvalidItemID(this: (vgui::TreeView *)this->m_pSliders);
        i = (vgui::ScrollBarSlider *)vgui::PanelListPanel::NextItem(this: this->m_pSliders, nItemID: (int)i) )
  {
    v8 = (CPresetSlider *)this->m_pSliders->GetItemPanel(this: this->m_pSliders, a2: i);
    pSlider = v8;
    if ( v8 != nullptr )
    {
      m_Id = (_BYTE *)v8->m_presetName.u.m_Id;
      if ( m_Id != (_BYTE *)-1 && m_Id != nullptr && *m_Id != 0 && (!bVisibleOnly || v8->IsVisible(this: v8)) )
        CUtlVector<CPresetSlider *,CUtlMemoryFixedGrowable<CPresetSlider *,100,int>>::InsertBefore(
          this: &workItems,
          elem: workItems.m_Size,
          src: &pSlider);
    }
  }
  if ( ifm_threaded_updatecontrolvalues.m_pParent->m_Value.m_nValue != 0 )
  {
    m_Size = workItems.m_Size;
    m_pMemory = workItems.m_Memory.m_pMemory;
    v15.m_pItems.m_value = nullptr;
    v15.m_pLimit = nullptr;
    _InterlockedExchange((volatile __int32 *)&v15.m_pItems, 0);
    v15.m_ItemProcessor.m_pfnProcess = Parallel_UpdateControlValues;
    v15.m_ItemProcessor.m_pfnBegin = nullptr;
    v15.m_ItemProcessor.m_pfnEnd = nullptr;
    CParallelProcessor<CPresetSlider *,CFuncJobItemProcessor<CPresetSlider *>,1>::Run(
      this: &v15,
      pItems: m_pMemory,
      nItems: m_Size,
      nChunkSize: 1,
      nMaxParallel: 0x7FFFFFFF,
      pThreadPool: nullptr);
  }
  else
  {
    for ( j = 0; j < workItems.m_Size; ++j )
      CPresetSlider::SetControlValues(this: workItems.m_Memory.m_pMemory[j]);
  }
  v13 = workItems.m_Memory.m_pMemory;
  workItems.m_Size = 0;
  if ( workItems.m_Memory.m_nGrowSize >= 0 )
  {
    if ( workItems.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: workItems.m_Memory.m_pMemory);
      v13 = nullptr;
      workItems.m_Memory.m_pMemory = nullptr;
    }
    workItems.m_Memory.m_nAllocationCount = 0;
  }
  workItems.m_pElements = v13;
  if ( workItems.m_Memory.m_nGrowSize >= 0 && v13 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13);
}

//------------------------------------------------------------------------------
// Address: 0x0048DBC0
// Name: protected: void CBaseAnimSetPresetFaderPanel::RebuildPresetSliders(char const __near *,class CUtlVector<class CUtlSymbolLarge,class CUtlMemory<class CUtlSymbolLarge,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::RebuildPresetSliders(
        CBaseAnimSetPresetFaderPanel *this,
        const char *pPresetGroupName,
        const CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > *presetNames)
{
  int m_Size; // ebx
  int i; // edi
  const char *m_pAsString; // eax
  CSliderListPanel *m_pSliders; // ecx
  CSliderListPanel_vtbl *v8; // edi
  int ItemIDFromRow; // eax
  int v10; // eax
  int nSliders; // [esp+18h] [ebp+Ch]

  vgui::PanelListPanel::HideAllItems(this: this->m_pSliders);
  m_Size = presetNames->m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    m_pAsString = presetNames->m_Memory.m_pMemory[i].u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    CBaseAnimSetPresetFaderPanel::UpdateOrCreatePresetSlider(this, nSlot: i, pPresetGroupName, pPresetName: m_pAsString);
  }
  for ( nSliders = vgui::PanelListPanel::GetItemCount(this: (vgui::TextEntry *)this->m_pSliders);
        m_Size < nSliders;
        ++m_Size )
  {
    m_pSliders = this->m_pSliders;
    v8 = m_pSliders->__vftable;
    ItemIDFromRow = vgui::PanelListPanel::GetItemIDFromRow(this: m_pSliders, nRow: m_Size);
    v10 = (int)v8->GetItemPanel(this: this->m_pSliders, a2: ItemIDFromRow);
    if ( v10 != 0 )
    {
      *(_DWORD *)(v10 + 504) = 0;
      *(_BYTE *)(v10 + 508) = 0;
      *(_DWORD *)(v10 + 500) = -1;
      *(_DWORD *)(v10 + 496) = -1;
      CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short,CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v10 + 468));
    }
  }
  CBaseAnimSetPresetFaderPanel::UpdateControlValues(this, bVisibleOnly: false);
}

//------------------------------------------------------------------------------
// Address: 0x0048DC90
// Name: protected: void CBaseAnimSetPresetFaderPanel::PopulatePresetList(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::PopulatePresetList(CBaseAnimSetPresetFaderPanel *this, bool bChanged)
{
  CDmeFilmClip *AnimationSetClip; // eax
  vgui::PropertySheet *m_pSheet; // ecx
  int v5; // eax
  vgui::PropertySheet *v6; // ecx
  int v7; // edi
  vgui::Panel *(__thiscall *GetActivePage)(vgui::PropertySheet *); // edx
  int v9; // ebx
  vgui::Panel *v10; // eax
  void (__thiscall *v11)(CUtlSymbolLarge::<unnamed_type_u>, int *, const char *); // edx
  int m_Size; // eax
  vgui::PropertyPage *v13; // edi
  const char *m_pAsString; // ebx
  bool v15; // zf
  vgui::PropertySheet_vtbl *v16; // eax
  const char *v17; // eax
  vgui::PropertyPage *v18; // eax
  int v19; // ebx
  int m_nAllocationCount; // eax
  vgui::PropertyPage **m_pMemory; // ecx
  int v22; // eax
  vgui::PropertyPage **v23; // ebx
  vgui::PropertyPage *v24; // edi
  CUtlVector<CUtlSymbolLarge,CUtlMemory<CUtlSymbolLarge,int> > presetNames; // [esp+Ch] [ebp-48h] BYREF
  CUtlVector<PresetGroupInfo_t,CUtlMemory<PresetGroupInfo_t,int> > presetGroupInfo; // [esp+20h] [ebp-34h] BYREF
  CDmeFilmClip *pFilmClip; // [esp+34h] [ebp-20h]
  int nCurrentGroupIndex; // [esp+38h] [ebp-1Ch]
  const char *pCurrentGroupName; // [esp+3Ch] [ebp-18h]
  int nPresetGroupPages; // [esp+40h] [ebp-14h] BYREF
  PresetGroupInfo_t src; // [esp+44h] [ebp-10h] BYREF
  const char *pName; // [esp+4Ch] [ebp-8h]
  bool bCurrentGroupIsProceduralGroup; // [esp+53h] [ebp-1h]

  AnimationSetClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  m_pSheet = this->m_pSheet;
  pFilmClip = AnimationSetClip;
  v5 = m_pSheet->GetActivePageNum(this: m_pSheet);
  v6 = this->m_pSheet;
  v7 = v5;
  GetActivePage = v6->GetActivePage;
  v9 = 0;
  nCurrentGroupIndex = v5;
  bCurrentGroupIsProceduralGroup = v5 == 0;
  if ( (int)GetActivePage(this: v6) != 0 )
  {
    v10 = this->m_pSheet->GetActivePage(this: this->m_pSheet);
    pCurrentGroupName = v10->GetName(this: v10);
  }
  else
  {
    pCurrentGroupName = defaultValue;
  }
  v11 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 200);
  memset(&presetGroupInfo, 0, sizeof(presetGroupInfo));
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v11)(
    a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
    a2: &nPresetGroupPages,
    a3: "Procedural");
  src.presetGroupSym.u.m_Id = nPresetGroupPages;
  CUtlVector<PresetGroupInfo_t,CUtlMemory<PresetGroupInfo_t,int>>::InsertBefore(this: &presetGroupInfo, elem: 0, &src);
  CollectPresetGroupInfo(
    pFilmClip,
    presetInfo: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&presetGroupInfo,
    bSkipReadOnly: false,
    bSkipInvisible: true);
  m_Size = this->m_presetGroupPages.m_Size;
  nPresetGroupPages = m_Size;
  *(_DWORD *)&src.bGroupShared = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v13 = this->m_presetGroupPages.m_Memory.m_pMemory[v9];
      if ( v13 != nullptr )
      {
        if ( v9 >= presetGroupInfo.m_Size )
        {
          this->m_pSheet->RemovePage(this: this->m_pSheet, a2: v13);
          vgui::Panel::SetName(this: v13, panelName: defaultValue);
        }
        else
        {
          m_pAsString = presetGroupInfo.m_Memory.m_pMemory[v9].presetGroupSym.u.m_pAsString;
          if ( m_pAsString == (const char *)-1 )
            m_pAsString = defaultValue;
          v15 = *v13->GetName(this: v13) == 0;
          v16 = this->m_pSheet->__vftable;
          if ( v15 )
            ((void (__stdcall *)(vgui::PropertyPage *, const char *, _DWORD, _DWORD, int))v16->AddPage)(
              a1: v13,
              a2: m_pAsString,
              a3: 0,
              a4: 0,
              a5: -1);
          else
            ((void (__stdcall *)(vgui::PropertyPage *, const char *))v16->SetPageTitle)(a1: v13, a2: m_pAsString);
          vgui::Panel::SetName(this: v13, panelName: m_pAsString);
          v9 = *(_DWORD *)&src.bGroupShared;
        }
        m_Size = nPresetGroupPages;
      }
      *(_DWORD *)&src.bGroupShared = ++v9;
    }
    while ( v9 < m_Size );
    v7 = nCurrentGroupIndex;
  }
  nPresetGroupPages = m_Size;
  if ( m_Size < presetGroupInfo.m_Size )
  {
    do
    {
      v17 = presetGroupInfo.m_Memory.m_pMemory[nPresetGroupPages].presetGroupSym.u.m_pAsString;
      pName = defaultValue;
      if ( v17 != (const char *)-1 )
        pName = v17;
      v18 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
      if ( v18 != nullptr )
        *(_DWORD *)&src.bGroupShared = vgui::PropertyPage::PropertyPage(this: v18, parent: this, panelName: pName);
      else
        *(_DWORD *)&src.bGroupShared = 0;
      v19 = this->m_presetGroupPages.m_Size;
      m_nAllocationCount = this->m_presetGroupPages.m_Memory.m_nAllocationCount;
      if ( v19 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_presetGroupPages,
          num: v19 - m_nAllocationCount + 1);
      ++this->m_presetGroupPages.m_Size;
      m_pMemory = this->m_presetGroupPages.m_Memory.m_pMemory;
      v22 = this->m_presetGroupPages.m_Size - v19 - 1;
      this->m_presetGroupPages.m_pElements = m_pMemory;
      if ( v22 > 0 )
        _V_memmove(dest: &m_pMemory[v19 + 1], src: &m_pMemory[v19], count: 4 * v22);
      v23 = &this->m_presetGroupPages.m_Memory.m_pMemory[v19];
      if ( v23 != nullptr )
        *v23 = *(vgui::PropertyPage **)&src.bGroupShared;
      this->m_pSheet->AddPage(
        this: this->m_pSheet,
        a2: *(vgui::Panel **)&src.bGroupShared,
        a3: pName,
        a4: nullptr,
        a5: false,
        a6: -1);
      ++nPresetGroupPages;
    }
    while ( nPresetGroupPages < presetGroupInfo.m_Size );
    v7 = nCurrentGroupIndex;
  }
  if ( v7 >= 0 )
  {
    v24 = this->m_presetGroupPages.m_Memory.m_pMemory[v7];
    this->m_pSheet->SetActivePage(this: this->m_pSheet, a2: v24);
    this->m_pSliders->SetParent_2(this: this->m_pSliders, a2: v24);
    memset(&presetNames, 0, sizeof(presetNames));
    if ( bCurrentGroupIsProceduralGroup )
      CollectProceduralPresetNames((CUtlMemory<vgui::TreeNode *,int> *)&presetNames);
    else
      CollectPresetNamesForGroup(
        pFilmClip,
        pPresetGroupName: pCurrentGroupName,
        (CUtlMemory<vgui::TreeNode *,int> *)&presetNames);
    CBaseAnimSetPresetFaderPanel::RebuildPresetSliders(this, pPresetGroupName: pCurrentGroupName, &presetNames);
    if ( presetNames.m_Memory.m_nGrowSize >= 0 && presetNames.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: presetNames.m_Memory.m_pMemory);
  }
  else
  {
    vgui::PanelListPanel::HideAllItems(this: this->m_pSliders);
  }
  if ( presetGroupInfo.m_Memory.m_nGrowSize >= 0 && presetGroupInfo.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: presetGroupInfo.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0048DFC0
// Name: public: void CBaseAnimSetPresetFaderPanel::OnDeletePreset(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::OnDeletePreset(
        CBaseAnimSetPresetFaderPanel *this,
        const char *pPresetName)
{
  CDmeAnimationSet *i; // eax
  CAnimSetGroupAnimSetTraversal traversal; // [esp+4h] [ebp-8h] BYREF

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 256))(
    a1: g_pDataModel.u,
    a2: "Delete Preset",
    a3: "Delete Preset",
    a4: 0);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, _DWORD, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 460))(
    a1: g_pDataModel.u,
    a2: "Delete Preset",
    a3: 0,
    a4: 256);
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: this->m_pController);
  traversal.m_nIndex = 0;
  for ( i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        i != nullptr;
        i = CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
  {
    CDmeAnimationSet::RemovePreset(this: i, pPresetName);
  }
  CBaseAnimSetPresetFaderPanel::PopulatePresetList(this, bChanged: false);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
    a1: g_pDataModel.u,
    a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0048E070
// Name: protected: virtual void CPresetSlider::OnDeleteConfirmed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSlider::OnDeleteConfirmed(CPresetSlider *this)
{
  const char *m_pAsString; // eax

  m_pAsString = this->m_presetName.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  CBaseAnimSetPresetFaderPanel::OnDeletePreset(this: this->m_pPresetFaderPanel, pPresetName: m_pAsString);
}

//------------------------------------------------------------------------------
// Address: 0x0048E100
// Name: protected: virtual void CBaseAnimSetPresetFaderPanel::OnPresetsChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::OnPresetsChanged(CBaseAnimSetPresetFaderPanel *this)
{
  CBaseAnimSetPresetFaderPanel::PopulatePresetList(this, bChanged: false);
}

//------------------------------------------------------------------------------
// Address: 0x0048E110
// Name: protected: virtual void CBaseAnimSetPresetFaderPanel::OnPageChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetPresetFaderPanel::OnPageChanged(CBaseAnimSetPresetFaderPanel *this)
{
  CBaseAnimSetPresetFaderPanel::PopulatePresetList(this, bChanged: true);
}

//------------------------------------------------------------------------------
// Address: 0x004DE070
// Name: public: virtual void CMemberFunctor0<class CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1> __near *,void (CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1>::*)(void),class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x00604BD0
// Name: private: void CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1>::DoExecute(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute(
        CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *this)
{
  void (__thiscall *m_pfnBegin)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *); // eax
  int *m_pLimit; // ecx
  unsigned int v4; // edx
  int *v5; // esi
  int *v6; // ebx
  void (__thiscall *m_pfnEnd)(CCallQueueT<CTSQueue<CFunctor *,0,1> > *); // eax
  unsigned int v8; // [esp+4h] [ebp-8h]
  int *pLimit; // [esp+8h] [ebp-4h]

  if ( this->m_pItems.m_value < this->m_pLimit )
  {
    m_pfnBegin = this->m_ItemProcessor.m_pfnBegin;
    if ( m_pfnBegin != nullptr )
      m_pfnBegin(this: this->m_ItemProcessor.m_pObject);
    m_pLimit = this->m_pLimit;
    v4 = 4 * this->m_nChunkSize;
    pLimit = m_pLimit;
    v8 = v4;
    do
    {
      v5 = (int *)_InterlockedExchangeAdd((volatile signed __int32 *)&this->m_pItems, v4);
      v6 = (int *)((char *)v5 + v4);
      if ( m_pLimit < (int *)((char *)v5 + v4) )
        v6 = m_pLimit;
      if ( v5 < v6 )
      {
        do
          this->m_ItemProcessor.m_pfnProcess(this: this->m_ItemProcessor.m_pObject, a2: v5++);
        while ( v5 < v6 );
        m_pLimit = pLimit;
        v4 = v8;
      }
    }
    while ( v5 < m_pLimit );
    m_pfnEnd = this->m_ItemProcessor.m_pfnEnd;
    if ( m_pfnEnd != nullptr )
      m_pfnEnd(this: this->m_ItemProcessor.m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00604FF0
// Name: public: void CParallelProcessor<int,class CMemberFuncJobItemProcessor<int,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>,class CCallQueueT<class CTSQueue<class CFunctor __near *,0,1>>>,1>::Run(int __near *,unsigned int,int,int,class IThreadPool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::Run(
        CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *this,
        int *pItems,
        unsigned int nItems,
        int nChunkSize,
        int nMaxParallel,
        IThreadPool *pThreadPool)
{
  unsigned int v6; // ebx
  IThreadPool *v8; // ecx
  int *v9; // eax
  int v10; // ebx
  int v11; // eax
  void *v12; // esp
  int i; // esi
  CFunctor *v14; // eax
  CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *v15; // ecx
  _DWORD v16[3]; // [esp+0h] [ebp-10h]
  CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1> >,CCallQueueT<CTSQueue<CFunctor *,0,1> > >,1> *v17; // [esp+Ch] [ebp-4h]

  v6 = nItems;
  v17 = this;
  if ( nItems != 0 )
  {
    v8 = pThreadPool;
    this->m_nChunkSize = nChunkSize;
    if ( v8 == nullptr )
    {
      pThreadPool = _g_pThreadPool;
      v8 = _g_pThreadPool;
    }
    _InterlockedExchange((volatile __int32 *)&this->m_pItems, (__int32)pItems);
    v9 = &pItems[v6];
    v10 = v6 - 1;
    this->m_pLimit = v9;
    if ( v10 > nMaxParallel )
      v10 = nMaxParallel;
    if ( v8 == nullptr )
      goto LABEL_18;
    v11 = v8->NumThreads(this: v8);
    if ( v10 > v11 )
      v10 = v11;
    if ( v10 > 0 )
    {
      v12 = alloca(4 * v10);
      for ( i = v10; i != 0; v16[i] = nItems )
      {
        --i;
        v14 = (CFunctor *)MemAlloc_Alloc(nSize: 0x18u);
        if ( v14 != nullptr )
        {
          v15 = v17;
          v14[1].m_nUserID = 1;
          v14->__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
          v14[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor0<CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1> *,void (__thiscall CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::*)(void),CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
          v14[2].__vftable = (CFunctor_vtbl *)CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute;
          v14[2].m_nUserID = (unsigned int)v15;
        }
        else
        {
          v14 = nullptr;
        }
        pThreadPool->AddFunctorInternal(this: pThreadPool, a2: v14, a3: (CJob **)&nItems, a4: nullptr, a5: 8u);
      }
      CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute(this: v17);
      do
      {
        CJob::Abort(this: (CJob *)v16[i], bDiscard: true);
        (*(void (__thiscall **)(_DWORD))(*(_DWORD *)v16[i] + 4))(a1: v16[i]);
        ++i;
      }
      while ( i < v10 );
    }
    else
    {
LABEL_18:
      CParallelProcessor<int,CMemberFuncJobItemProcessor<int,CCallQueueT<CTSQueue<CFunctor *,0,1>>,CCallQueueT<CTSQueue<CFunctor *,0,1>>>,1>::DoExecute(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00661D90
// Name: protected: virtual void vgui::BaseInputDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::BaseInputDialog::PerformLayout(vgui::BaseInputDialog *this)
{
  bool v2; // al
  int v3; // edi
  int v4; // [esp-Ch] [ebp-20h]
  int w; // [esp+Ch] [ebp-8h] BYREF
  int h; // [esp+10h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v2 = this->IsSmallCaption(this);
  v3 = w / 2;
  this->PerformLayout_2(this, a2: 12, a3: v2 ? 15 : 30, a4: w - 24, a5: h - 100);
  v4 = h - 30;
  if ( this->m_pCancelButton != nullptr )
  {
    vgui::Panel::SetBounds(this: this->m_pOKButton, x: v3 - 84, y: v4, wide: 72, tall: 24);
    vgui::Panel::SetBounds(this: this->m_pCancelButton, x: v3 + 12, y: h - 30, wide: 72, tall: 24);
  }
  else
  {
    vgui::Panel::SetBounds(this: this->m_pOKButton, x: v3 - 36, y: v4, wide: 72, tall: 24);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006621D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::BaseInputDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::BaseInputDialog::GetMessageMap(vgui::BaseInputDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::BaseInputDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::BaseInputDialog::GetMessageMap'::`2'::s_pMap;
  `vgui::BaseInputDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "BaseInputDialog");
  `vgui::BaseInputDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00662200
// Name: public: virtual struct PanelAnimationMap __near * vgui::BaseInputDialog::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::BaseInputDialog::GetAnimMap(vgui::BaseInputDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "BaseInputDialog");
}

//------------------------------------------------------------------------------
// Address: 0x00662210
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::BaseInputDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::BaseInputDialog::GetKBMap(vgui::BaseInputDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::BaseInputDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::BaseInputDialog::GetKBMap'::`2'::s_pMap;
  `vgui::BaseInputDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "BaseInputDialog");
  `vgui::BaseInputDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace sceneviewer
