// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/vmtpicker.cpp
// Functions: 29
// ============================================================

#include "vgui2\matsys_controls\vmtpicker.h"

//------------------------------------------------------------------------------
// Address: 0x004C0070
// Name: public: static char const __near * CVMTPreviewToolbar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVMTPreviewToolbar::GetPanelClassName()
{
  return "CVMTPreviewToolbar";
}

//------------------------------------------------------------------------------
// Address: 0x004C0080
// Name: public: static char const __near * CVMTPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVMTPicker::GetPanelClassName()
{
  return "CVMTPicker";
}

//------------------------------------------------------------------------------
// Address: 0x004C0090
// Name: public: static char const __near * CVMTPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVMTPickerFrame::GetPanelClassName()
{
  return "CVMTPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004C00A0
// Name: public: virtual void CVMTPreviewToolbar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::ApplySchemeSettings(CVMTPreviewToolbar *this, vgui::IScheme *pScheme)
{
  vgui::MenuButton_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v3 = this->m_pSequenceSelection->__vftable;
  v4 = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
  v3->SetFont(this: this->m_pSequenceSelection, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004C00E0
// Name: public: virtual void CVMTPicker::CustomizeSelectionMessage(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPicker::CustomizeSelectionMessage(CVMTPicker *this, KeyValues *pKeyValues)
{
  int SheetSequenceCount; // eax
  int RealSequenceNumber; // eax
  int CurrentSecondarySequence; // eax

  SheetSequenceCount = CVMTPreviewPanel::GetSheetSequenceCount(this: this->m_pVMTPreview3D);
  KeyValues::SetInt(this: pKeyValues, keyName: "sheet_sequence_count", value: SheetSequenceCount);
  RealSequenceNumber = CVMTPreviewPanel::GetRealSequenceNumber(this: this->m_pVMTPreview3D);
  KeyValues::SetInt(this: pKeyValues, keyName: "sheet_sequence_number", value: RealSequenceNumber);
  CurrentSecondarySequence = CVMTPreviewPanel::GetCurrentSecondarySequence(this: this->m_pVMTPreview3D);
  KeyValues::SetInt(this: pKeyValues, keyName: "sheet_sequence_secondary_number", value: CurrentSecondarySequence);
}

//------------------------------------------------------------------------------
// Address: 0x004C0140
// Name: public: virtual struct vgui::PanelMessageMap __near * CVMTPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVMTPicker::GetMessageMap(CVMTPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVMTPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPicker::GetMessageMap'::`2'::s_pMap;
  `CVMTPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVMTPicker");
  `CVMTPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C0170
// Name: public: virtual struct PanelAnimationMap __near * CVMTPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVMTPicker::GetAnimMap(CVMTPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CVMTPicker");
}

//------------------------------------------------------------------------------
// Address: 0x004C0180
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVMTPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVMTPicker::GetKBMap(CVMTPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVMTPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPicker::GetKBMap'::`2'::s_pMap;
  `CVMTPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPicker");
  `CVMTPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C01B0
// Name: public: virtual void CVMTPreviewToolbar::OnSliderMoved(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::OnSliderMoved(CVMTPreviewToolbar *this, KeyValues *pData)
{
  int v3; // eax
  CVMTPicker *m_pParentPicker; // esi
  float pDataa; // [esp+10h] [ebp+8h]

  if ( KeyValues::GetPtr(this: pData, keyName: "panel", defaultValue: nullptr) == this->m_pSheetPreviewSpeed )
  {
    v3 = this->m_pSheetPreviewSpeed->GetValue(this: this->m_pSheetPreviewSpeed);
    m_pParentPicker = this->m_pParentPicker;
    pDataa = (float)v3;
    CVMTPreviewPanel::SetSheetPreviewSpeed(this: m_pParentPicker->m_pVMTPreview2D, flPreviewSpeed: (float)v3);
    CVMTPreviewPanel::SetSheetPreviewSpeed(this: m_pParentPicker->m_pVMTPreview3D, flPreviewSpeed: pDataa);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C0220
// Name: public: void CVMTPreviewToolbar::UpdateToolbarGUI(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::UpdateToolbarGUI(CVMTPreviewToolbar *this)
{
  int SheetSequenceCount; // edi
  int RealSequenceNumber; // ebx
  IMaterial *NumColumns; // eax
  IMaterial *v5; // eax
  IMaterial *v6; // [esp+0h] [ebp-54h]
  char sz[64]; // [esp+Ch] [ebp-48h] BYREF
  BOOL bSecondPicker; // [esp+4Ch] [ebp-8h]
  int nRealSeqNumber; // [esp+50h] [ebp-4h]

  SheetSequenceCount = CVMTPreviewPanel::GetSheetSequenceCount(this: this->m_pParentPicker->m_pVMTPreview3D);
  RealSequenceNumber = CVMTPreviewPanel::GetRealSequenceNumber(this: this->m_pParentPicker->m_pVMTPreview3D);
  nRealSeqNumber = CVMTPreviewPanel::GetRealSequenceNumber(this: this->m_pParentPicker->m_pVMTPreview3D);
  NumColumns = (IMaterial *)vgui::CTreeViewListControl::GetNumColumns(this: (vgui::CTreeViewListControl *)this->m_pParentPicker->m_pVMTPreview3D);
  LOBYTE(bSecondPicker) = CSheetExtended::IsMaterialSeparateAlphaColorMaterial(pMat: NumColumns);
  if ( SheetSequenceCount != 0 )
  {
    V_snprintf(
      pDest: sz,
      maxLen: 64,
      pFormat: "%d/%d Sequences (#%d)",
      RealSequenceNumber + 1,
      SheetSequenceCount,
      nRealSeqNumber);
    this->m_pSequenceSelection->SetText_2(this: this->m_pSequenceSelection, a2: sz);
    this->m_pSequenceSelection->SetEnabled(this: this->m_pSequenceSelection, a2: true);
    this->m_pSequenceSelection_Second->SetVisible(this: this->m_pSequenceSelection_Second, a2: bSecondPicker);
    this->m_pNextSeqButton->SetEnabled(this: this->m_pNextSeqButton, a2: true);
    this->m_pPrevSeqButton->SetEnabled(this: this->m_pPrevSeqButton, a2: true);
    v5 = (IMaterial *)vgui::CTreeViewListControl::GetNumColumns(this: (vgui::CTreeViewListControl *)this->m_pParentPicker->m_pVMTPreview3D);
    CSheetSequencePanel::SetFromMaterial(this: this->m_pSheetPanel, sourceMaterial: v5);
    v6 = (IMaterial *)vgui::CTreeViewListControl::GetNumColumns(this: (vgui::CTreeViewListControl *)this->m_pParentPicker->m_pVMTPreview3D);
    CSheetSequencePanel::SetFromMaterial(this: this->m_pSheetPanel_Second, sourceMaterial: v6);
  }
  else
  {
    this->m_pSequenceSelection->SetText_2(this: this->m_pSequenceSelection, a2: "No Sequences");
    this->m_pSequenceSelection->SetEnabled(this: this->m_pSequenceSelection, a2: false);
    this->m_pNextSeqButton->SetEnabled(this: this->m_pNextSeqButton, a2: false);
    this->m_pPrevSeqButton->SetEnabled(this: this->m_pPrevSeqButton, a2: false);
    this->m_pSequenceSelection_Second->SetVisible(this: this->m_pSequenceSelection_Second, a2: false);
    CSheetSequencePanel::SetFromMaterial(this: this->m_pSheetPanel, sourceMaterial: nullptr);
    CSheetSequencePanel::SetFromMaterial(this: this->m_pSheetPanel_Second, sourceMaterial: nullptr);
  }
  ((void (__thiscall *)(CVMTPreviewToolbar *, _DWORD))this->InvalidateLayout)(a1: this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004C03F0
// Name: private: virtual void CVMTPicker::OnSelectedAssetPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPicker::OnSelectedAssetPicked(CVMTPicker *this, const char *pAssetName)
{
  CVMTPreviewPanel::SetVMT(this: this->m_pVMTPreview2D, pMaterialName: pAssetName);
  CVMTPreviewPanel::SetVMT(this: this->m_pVMTPreview3D, pMaterialName: pAssetName);
  CVMTPreviewToolbar::UpdateToolbarGUI(this: this->m_pVMTPreviewToolbar);
}

//------------------------------------------------------------------------------
// Address: 0x004C0430
// Name: public: virtual void CVMTPreviewToolbar::OnNextSequence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::OnNextSequence(CVMTPreviewToolbar *this)
{
  int RealSequenceNumber; // edi
  int SheetSequenceCount; // eax
  CVMTPicker *m_pParentPicker; // ebx
  int v5; // edi

  RealSequenceNumber = CVMTPreviewPanel::GetRealSequenceNumber(this: this->m_pParentPicker->m_pVMTPreview3D);
  SheetSequenceCount = CVMTPreviewPanel::GetSheetSequenceCount(this: this->m_pParentPicker->m_pVMTPreview3D);
  m_pParentPicker = this->m_pParentPicker;
  v5 = (RealSequenceNumber + 1) % SheetSequenceCount;
  CVMTPreviewPanel::SetSheetSequence(this: m_pParentPicker->m_pVMTPreview2D, nSequence: v5);
  CVMTPreviewPanel::SetSheetSequence(this: m_pParentPicker->m_pVMTPreview3D, nSequence: v5);
  CVMTPreviewToolbar::UpdateToolbarGUI(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C0490
// Name: public: virtual void CVMTPreviewToolbar::OnPrevSequence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::OnPrevSequence(CVMTPreviewToolbar *this)
{
  int RealSequenceNumber; // esi
  int SheetSequenceCount; // eax
  int v4; // esi
  CVMTPicker *m_pParentPicker; // ebx

  RealSequenceNumber = CVMTPreviewPanel::GetRealSequenceNumber(this: this->m_pParentPicker->m_pVMTPreview3D);
  SheetSequenceCount = CVMTPreviewPanel::GetSheetSequenceCount(this: this->m_pParentPicker->m_pVMTPreview3D);
  if ( RealSequenceNumber != 0 )
    v4 = (RealSequenceNumber - 1) % SheetSequenceCount;
  else
    v4 = SheetSequenceCount - 1;
  m_pParentPicker = this->m_pParentPicker;
  CVMTPreviewPanel::SetSheetSequence(this: m_pParentPicker->m_pVMTPreview2D, nSequence: v4);
  CVMTPreviewPanel::SetSheetSequence(this: m_pParentPicker->m_pVMTPreview3D, nSequence: v4);
  CVMTPreviewToolbar::UpdateToolbarGUI(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C0500
// Name: public: virtual void CVMTPreviewToolbar::OnSelectSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::OnSelectSequence(CVMTPreviewToolbar *this, int nSequenceNumber)
{
  CVMTPicker *m_pParentPicker; // edi

  m_pParentPicker = this->m_pParentPicker;
  CVMTPreviewPanel::SetSheetSequence(this: m_pParentPicker->m_pVMTPreview2D, nSequence: nSequenceNumber);
  CVMTPreviewPanel::SetSheetSequence(this: m_pParentPicker->m_pVMTPreview3D, nSequence: nSequenceNumber);
  CVMTPreviewToolbar::UpdateToolbarGUI(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C0540
// Name: public: virtual void CVMTPreviewToolbar::OnSheetSequenceSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::OnSheetSequenceSelected(CVMTPreviewToolbar *this, KeyValues *pData)
{
  int Int; // eax
  CVMTPicker *m_pParentPicker; // edi
  int v5; // esi
  int v6; // eax
  CVMTPicker *v7; // edi
  int v8; // esi

  if ( KeyValues::GetInt(this: pData, keyName: "bIsSecondSequence", defaultValue: 0) != 0 )
  {
    Int = KeyValues::GetInt(this: pData, keyName: "nSequenceNumber", defaultValue: 0);
    m_pParentPicker = this->m_pParentPicker;
    v5 = Int;
    CVMTPreviewPanel::SetSecondarySheetSequence(this: m_pParentPicker->m_pVMTPreview2D, nSequence: Int);
    CVMTPreviewPanel::SetSecondarySheetSequence(this: m_pParentPicker->m_pVMTPreview3D, nSequence: v5);
  }
  else
  {
    v6 = KeyValues::GetInt(this: pData, keyName: "nSequenceNumber", defaultValue: 0);
    v7 = this->m_pParentPicker;
    v8 = v6;
    CVMTPreviewPanel::SetSheetSequence(this: v7->m_pVMTPreview2D, nSequence: v6);
    CVMTPreviewPanel::SetSheetSequence(this: v7->m_pVMTPreview3D, nSequence: v8);
  }
  CVMTPreviewToolbar::UpdateToolbarGUI(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C05D0
// Name: public: static void CVMTPreviewToolbar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVMTPreviewToolbar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`CVMTPreviewToolbar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `CVMTPreviewToolbar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SliderMoved";
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
// Address: 0x004C0660
// Name: public: static void CVMTPreviewToolbar::PanelMessageFunc_OnSelectSequence::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVMTPreviewToolbar::PanelMessageFunc_OnSelectSequence::InitVar(int a1@<ebp>)
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
  if ( !`CVMTPreviewToolbar::PanelMessageFunc_OnSelectSequence::InitVar'::`2'::bAdded )
  {
    `CVMTPreviewToolbar::PanelMessageFunc_OnSelectSequence::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OnSelectSequence";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "nSequenceNumber";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C0700
// Name: public: static void CVMTPreviewToolbar::PanelMessageFunc_OnNextSequence::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVMTPreviewToolbar::PanelMessageFunc_OnNextSequence::InitVar(int a1@<ebp>)
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
  if ( !`CVMTPreviewToolbar::PanelMessageFunc_OnNextSequence::InitVar'::`2'::bAdded )
  {
    `CVMTPreviewToolbar::PanelMessageFunc_OnNextSequence::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnNextSequence";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C0790
// Name: public: static void CVMTPreviewToolbar::PanelMessageFunc_OnPrevSequence::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVMTPreviewToolbar::PanelMessageFunc_OnPrevSequence::InitVar(int a1@<ebp>)
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
  if ( !`CVMTPreviewToolbar::PanelMessageFunc_OnPrevSequence::InitVar'::`2'::bAdded )
  {
    `CVMTPreviewToolbar::PanelMessageFunc_OnPrevSequence::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnPrevSequence";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C0820
// Name: public: static void CVMTPreviewToolbar::PanelMessageFunc_OnSheetSequenceSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVMTPreviewToolbar::PanelMessageFunc_OnSheetSequenceSelected::InitVar(int a1@<ebp>)
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
  if ( !`CVMTPreviewToolbar::PanelMessageFunc_OnSheetSequenceSelected::InitVar'::`2'::bAdded )
  {
    `CVMTPreviewToolbar::PanelMessageFunc_OnSheetSequenceSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SheetSequenceSelected";
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
// Address: 0x004C08B0
// Name: public: CVMTPreviewToolbar::CVMTPreviewToolbar(class vgui::Panel __near *,char const __near *,class CVMTPicker __near *)
// Source: json
//------------------------------------------------------------------------------
CVMTPreviewToolbar *__thiscall CVMTPreviewToolbar::CVMTPreviewToolbar(
        CVMTPreviewToolbar *this,
        vgui::Panel *parent,
        const char *panelName,
        CVMTPicker *parentpicker)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::CBoxSizer *v8; // eax
  vgui::CBoxSizer *v9; // edi
  __int64 v10; // xmm1_8
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // eax
  vgui::MenuButton *v15; // eax
  vgui::MenuButton *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  vgui::MenuButton *v21; // eax
  vgui::MenuButton *v22; // eax
  vgui::Slider *v23; // eax
  vgui::Slider *v24; // eax
  CSheetSequencePanel *v25; // eax
  CSheetSequencePanel *v26; // eax
  CSheetSequencePanel *v27; // eax
  CSheetSequencePanel *v28; // eax
  int v30; // [esp-Ch] [ebp-48h]
  int v31; // [esp-Ch] [ebp-48h]
  int m_Size; // [esp-8h] [ebp-44h]
  vgui::Slider *m_pSheetPreviewSpeed; // [esp-8h] [ebp-44h]
  vgui::SizerAddArgs_t buttonAddArgs; // [esp+Ch] [ebp-30h] BYREF
  vgui::SizerAddArgs_t args; // [esp+24h] [ebp-18h] BYREF
  int savedregs; // [esp+3Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (CVMTPreviewToolbar_vtbl *)&CVMTPreviewToolbar::`vftable';
  if ( `CVMTPreviewToolbar::ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPreviewToolbar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
    v5->pfnClassName = CVMTPreviewToolbar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CVMTPreviewToolbar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVMTPreviewToolbar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CVMTPreviewToolbar");
    v6->pfnClassName = CVMTPreviewToolbar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CVMTPreviewToolbar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPreviewToolbar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPreviewToolbar");
    v7->pfnClassName = CVMTPreviewToolbar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  CVMTPreviewToolbar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  CVMTPreviewToolbar::PanelMessageFunc_OnSelectSequence::InitVar(a1: (int)&savedregs);
  CVMTPreviewToolbar::PanelMessageFunc_OnNextSequence::InitVar(a1: (int)&savedregs);
  CVMTPreviewToolbar::PanelMessageFunc_OnPrevSequence::InitVar(a1: (int)&savedregs);
  CVMTPreviewToolbar::PanelMessageFunc_OnSheetSequenceSelected::InitVar(a1: (int)&savedregs);
  this->m_pParentPicker = parentpicker;
  v8 = (vgui::CBoxSizer *)MemAlloc_Alloc(nSize: 0x24u);
  if ( v8 != nullptr )
    v9 = vgui::CBoxSizer::CBoxSizer(this: v8, LayoutDirection: ESLD_HORIZONTAL);
  else
    v9 = nullptr;
  vgui::Panel::SetSizer(this, pSizer: v9);
  *(_QWORD *)&args.m_flExpandFactor = 0x200000000LL;
  args.m_nMinX = -1;
  *(_QWORD *)&buttonAddArgs.m_flExpandFactor = 0x200000000LL;
  args.m_bMinorExpand = false;
  args.m_bIgnoreMemberMin = true;
  args.m_nMinY = 18;
  *(_QWORD *)&buttonAddArgs.m_bMinorExpand = *(_QWORD *)&args.m_bMinorExpand;
  v10 = *(_QWORD *)&args.m_nMinY;
  args.m_nMinY = -1;
  *(_QWORD *)&buttonAddArgs.m_nMinY = v10;
  m_Size = v9->m_Members.m_Size;
  args.m_bMinorExpand = true;
  args.m_bIgnoreMemberMin = false;
  args.m_nPadding = 15;
  vgui::CSizerBase::InsertSpacer(this: v9, nIndex: m_Size, &args);
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "PrevSeqButton",
            text: "<",
            pActionSignalTarget: this,
            pCmd: nullptr);
  else
    v12 = nullptr;
  this->m_pPrevSeqButton = v12;
  v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v13 != nullptr )
    v14 = KeyValues::KeyValues(this: v13, setName: "OnPrevSequence");
  else
    v14 = nullptr;
  this->m_pPrevSeqButton->SetCommand(this: this->m_pPrevSeqButton, a2: v14);
  vgui::CSizerBase::InsertPanel(
    this: v9,
    nIndex: v9->m_Members.m_Size,
    pPanel: this->m_pPrevSeqButton,
    args: &buttonAddArgs);
  v15 = (vgui::MenuButton *)MemAlloc_Alloc(nSize: 0x214u);
  if ( v15 != nullptr )
    v16 = vgui::MenuButton::MenuButton(this: v15, parent: this, panelName: "SequenceSelection", text: "-");
  else
    v16 = nullptr;
  this->m_pSequenceSelection = v16;
  v30 = v9->m_Members.m_Size;
  args.m_bIgnoreMemberMin = true;
  args.m_nMinX = 120;
  args.m_nMinY = 18;
  args.m_flExpandFactor = 0.0;
  args.m_bMinorExpand = false;
  args.m_nPadding = 2;
  vgui::CSizerBase::InsertPanel(this: v9, nIndex: v30, pPanel: v16, &args);
  v17 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v17 != nullptr )
    v18 = vgui::Button::Button(
            this: v17,
            parent: this,
            panelName: "NextSeqButton",
            text: ">",
            pActionSignalTarget: this,
            pCmd: nullptr);
  else
    v18 = nullptr;
  this->m_pNextSeqButton = v18;
  v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v19 != nullptr )
    v20 = KeyValues::KeyValues(this: v19, setName: "OnNextSequence");
  else
    v20 = nullptr;
  this->m_pNextSeqButton->SetCommand(this: this->m_pNextSeqButton, a2: v20);
  vgui::CSizerBase::InsertPanel(
    this: v9,
    nIndex: v9->m_Members.m_Size,
    pPanel: this->m_pNextSeqButton,
    args: &buttonAddArgs);
  v21 = (vgui::MenuButton *)MemAlloc_Alloc(nSize: 0x214u);
  if ( v21 != nullptr )
    v22 = vgui::MenuButton::MenuButton(this: v21, parent: this, panelName: "SequenceSelection", text: "(Color)");
  else
    v22 = nullptr;
  this->m_pSequenceSelection_Second = v22;
  vgui::CSizerBase::InsertPanel(this: v9, nIndex: v9->m_Members.m_Size, pPanel: v22, args: &buttonAddArgs);
  v23 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v23 != nullptr )
    v24 = vgui::Slider::Slider(this: v23, parent: this, panelName: "SheetPreviewSpeed");
  else
    v24 = nullptr;
  this->m_pSheetPreviewSpeed = v24;
  v24->SetRange(this: v24, a2: 5, a3: 3000);
  this->m_pSheetPreviewSpeed->SetValue(this: this->m_pSheetPreviewSpeed, a2: 750, a3: true);
  this->m_pSheetPreviewSpeed->AddActionSignalTarget_2(this: this->m_pSheetPreviewSpeed, a2: this);
  m_pSheetPreviewSpeed = this->m_pSheetPreviewSpeed;
  v31 = v9->m_Members.m_Size;
  args.m_bIgnoreMemberMin = true;
  args.m_nMinX = 150;
  args.m_nMinY = 18;
  args.m_flExpandFactor = 0.0;
  args.m_bMinorExpand = false;
  args.m_nPadding = 2;
  vgui::CSizerBase::InsertPanel(this: v9, nIndex: v31, pPanel: m_pSheetPreviewSpeed, &args);
  v25 = (CSheetSequencePanel *)MemAlloc_Alloc(nSize: 0x438u);
  if ( v25 != nullptr )
    v26 = CSheetSequencePanel::CSheetSequencePanel(this: v25, pParent: this, pPanelName: "sheetpanel");
  else
    v26 = nullptr;
  this->m_pSheetPanel = v26;
  v26->AddActionSignalTarget_2(this: v26, a2: this);
  this->m_pSequenceSelection->SetMenu(this: this->m_pSequenceSelection, a2: this->m_pSheetPanel);
  v27 = (CSheetSequencePanel *)MemAlloc_Alloc(nSize: 0x438u);
  if ( v27 != nullptr )
    v28 = CSheetSequencePanel::CSheetSequencePanel(this: v27, pParent: this, pPanelName: "sheetpanel_second");
  else
    v28 = nullptr;
  this->m_pSheetPanel_Second = v28;
  CSheetSequencePanel::SetSecondSequenceView(this: v28, bIsSecondSequenceView: true);
  this->m_pSheetPanel_Second->AddActionSignalTarget_2(this: this->m_pSheetPanel_Second, a2: this);
  this->m_pSequenceSelection_Second->SetMenu(this: this->m_pSequenceSelection_Second, a2: this->m_pSheetPanel_Second);
  CVMTPreviewToolbar::UpdateToolbarGUI(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C0CF0
// Name: public: virtual struct vgui::PanelMessageMap __near * CVMTPreviewToolbar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVMTPreviewToolbar::GetMessageMap(CVMTPreviewToolbar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVMTPreviewToolbar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPreviewToolbar::GetMessageMap'::`2'::s_pMap;
  `CVMTPreviewToolbar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
  `CVMTPreviewToolbar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C0D20
// Name: public: virtual struct PanelAnimationMap __near * CVMTPreviewToolbar::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVMTPreviewToolbar::GetAnimMap(CVMTPreviewToolbar *this)
{
  return FindOrAddPanelAnimationMap(className: "CVMTPreviewToolbar");
}

//------------------------------------------------------------------------------
// Address: 0x004C0D30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVMTPreviewToolbar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVMTPreviewToolbar::GetKBMap(CVMTPreviewToolbar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVMTPreviewToolbar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPreviewToolbar::GetKBMap'::`2'::s_pMap;
  `CVMTPreviewToolbar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPreviewToolbar");
  `CVMTPreviewToolbar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C0D60
// Name: public: CVMTPicker::CVMTPicker(class vgui::Panel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CVMTPicker *__thiscall CVMTPicker::CVMTPicker(CVMTPicker *this, vgui::Panel *pParent, bool bAllowMultiselect)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Splitter *v7; // eax
  vgui::Splitter *v8; // eax
  vgui::Panel *Child; // edi
  vgui::Splitter *v10; // eax
  vgui::Splitter *v11; // eax
  vgui::Panel *v12; // edi
  vgui::Panel *v13; // ebx
  CVMTPreviewPanel *v14; // eax
  CVMTPreviewPanel *v15; // eax
  CVMTPreviewPanel *v16; // eax
  CVMTPreviewPanel *v17; // eax
  CVMTPreviewToolbar *v18; // eax
  CVMTPreviewToolbar *v19; // eax
  vgui::Panel *pSplitterLeftSide; // [esp+14h] [ebp+8h]

  CBaseAssetPicker::CBaseAssetPicker(
    this,
    pParent,
    pAssetType: "VMT Files",
    pExt: "vmt",
    pSubDir: "materials",
    pTextType: "vmtName",
    pAssetSearchPath: "GAME");
  this->__vftable = (CVMTPicker_vtbl *)&CVMTPicker::`vftable';
  if ( `CVMTPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPicker::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CVMTPicker");
    v4->pfnClassName = CVMTPicker::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CVMTPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVMTPicker::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CVMTPicker");
    v5->pfnClassName = CVMTPicker::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CVMTPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPicker::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPicker");
    v6->pfnClassName = CVMTPicker::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  }
  v7 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v7 != nullptr )
    v8 = vgui::Splitter::Splitter(
           this: v7,
           parent: this,
           name: "PreviewSplitter",
           mode: SPLITTER_MODE_VERTICAL,
           nCount: 1);
  else
    v8 = nullptr;
  this->m_pPreviewSplitter = v8;
  pSplitterLeftSide = vgui::Panel::GetChild(this: v8, index: 0);
  Child = vgui::Panel::GetChild(this: this->m_pPreviewSplitter, index: 1);
  v10 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v10 != nullptr )
    v11 = vgui::Splitter::Splitter(
            this: v10,
            parent: Child,
            name: "2D3DSplitter",
            mode: SPLITTER_MODE_HORIZONTAL,
            nCount: 1);
  else
    v11 = nullptr;
  this->m_p2D3DSplitter = v11;
  v12 = vgui::Panel::GetChild(this: v11, index: 0);
  v13 = vgui::Panel::GetChild(this: this->m_p2D3DSplitter, index: 1);
  v14 = (CVMTPreviewPanel *)MemAlloc_Alloc(nSize: 0x1A8u);
  if ( v14 != nullptr )
    v15 = CVMTPreviewPanel::CVMTPreviewPanel(this: v14, pParent: v12, pName: "VMTPreview2D");
  else
    v15 = nullptr;
  this->m_pVMTPreview2D = v15;
  v16 = (CVMTPreviewPanel *)MemAlloc_Alloc(nSize: 0x1A8u);
  if ( v16 != nullptr )
    v17 = CVMTPreviewPanel::CVMTPreviewPanel(this: v16, pParent: v13, pName: "VMTPreview3D");
  else
    v17 = nullptr;
  this->m_pVMTPreview3D = v17;
  CVMTPreviewPanel::DrawIn3DMode(this: v17, b3DMode: true);
  v18 = (CVMTPreviewToolbar *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v18 != nullptr )
    v19 = CVMTPreviewToolbar::CVMTPreviewToolbar(
            this: v18,
            parent: v13,
            panelName: "PreviewToolbar",
            parentpicker: this);
  else
    v19 = nullptr;
  this->m_pVMTPreviewToolbar = v19;
  CBaseAssetPicker::CreateStandardControls(this, pParent: pSplitterLeftSide, bAllowMultiselect);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/vmtpicker.res", dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C0F60
// Name: public: CVMTPickerFrame::CVMTPickerFrame(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CVMTPickerFrame *__thiscall CVMTPickerFrame::CVMTPickerFrame(
        CVMTPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        bool bAllowMultiselect)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  CVMTPicker *v8; // eax
  CVMTPicker *v9; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CVMTPickerFrame_vtbl *)&CVMTPickerFrame::`vftable';
  if ( `CVMTPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPickerFrame::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CVMTPickerFrame");
    v5->pfnClassName = CVMTPickerFrame::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CVMTPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVMTPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CVMTPickerFrame");
    v6->pfnClassName = CVMTPickerFrame::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CVMTPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPickerFrame");
    v7->pfnClassName = CVMTPickerFrame::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v8 = (CVMTPicker *)MemAlloc_Alloc(nSize: 0x258u);
  if ( v8 != nullptr )
    v9 = CVMTPicker::CVMTPicker(this: v8, pParent: this, bAllowMultiselect);
  else
    v9 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v9);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/vmtpickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C1060
// Name: public: virtual struct vgui::PanelMessageMap __near * CVMTPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVMTPickerFrame::GetMessageMap(CVMTPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVMTPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CVMTPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVMTPickerFrame");
  `CVMTPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C1090
// Name: public: virtual struct PanelAnimationMap __near * CVMTPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVMTPickerFrame::GetAnimMap(CVMTPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CVMTPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004C10A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVMTPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVMTPickerFrame::GetKBMap(CVMTPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVMTPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPickerFrame::GetKBMap'::`2'::s_pMap;
  `CVMTPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPickerFrame");
  `CVMTPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104CCE70
// Name: public: static char const __near * CVMTPreviewToolbar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVMTPreviewToolbar::GetPanelClassName()
{
  return "CVMTPreviewToolbar";
}

//------------------------------------------------------------------------------
// Address: 0x104CCE80
// Name: public: static char const __near * CVMTPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVMTPicker::GetPanelClassName()
{
  return "CVMTPicker";
}

//------------------------------------------------------------------------------
// Address: 0x104CCE90
// Name: public: static char const __near * CVMTPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVMTPickerFrame::GetPanelClassName()
{
  return "CVMTPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x104CCEA0
// Name: public: virtual void CVMTPreviewToolbar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::ApplySchemeSettings(CVMTPreviewToolbar *this, vgui::IScheme *pScheme)
{
  vgui::MenuButton_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = this->m_pSequenceSelection->__vftable;
  v4 = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
  v3->SetFont(this: this->m_pSequenceSelection, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x104CCEE0
// Name: public: virtual void CVMTPicker::CustomizeSelectionMessage(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPicker::CustomizeSelectionMessage(CVMTPicker *this, KeyValues *pKeyValues)
{
  int SheetSequenceCount; // eax
  int RealSequenceNumber; // eax
  int v5; // eax

  SheetSequenceCount = CVMTPreviewPanel::GetSheetSequenceCount(this: this->m_pVMTPreview3D);
  KeyValues::SetInt(this: pKeyValues, keyName: "sheet_sequence_count", value: SheetSequenceCount);
  RealSequenceNumber = CVMTPreviewPanel::GetRealSequenceNumber(this: this->m_pVMTPreview3D);
  KeyValues::SetInt(this: pKeyValues, keyName: "sheet_sequence_number", value: RealSequenceNumber);
  v5 = CMapDoc::NeedsAutosave(this: this->m_pVMTPreview3D);
  KeyValues::SetInt(this: pKeyValues, keyName: "sheet_sequence_secondary_number", value: v5);
}

//------------------------------------------------------------------------------
// Address: 0x104CCF40
// Name: public: virtual struct vgui::PanelMessageMap __near * CVMTPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVMTPicker::GetMessageMap(CVMTPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVMTPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPicker::GetMessageMap'::`2'::s_pMap;
  `CVMTPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVMTPicker");
  `CVMTPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CCF70
// Name: public: virtual struct PanelAnimationMap __near * CVMTPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVMTPicker::GetAnimMap(CVMTPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CVMTPicker");
}

//------------------------------------------------------------------------------
// Address: 0x104CCF80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVMTPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVMTPicker::GetKBMap(CVMTPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVMTPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPicker::GetKBMap'::`2'::s_pMap;
  `CVMTPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPicker");
  `CVMTPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CCFB0
// Name: public: virtual void CVMTPreviewToolbar::OnSliderMoved(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::OnSliderMoved(CVMTPreviewToolbar *this, KeyValues *pData)
{
  int v3; // eax
  CVMTPicker *m_pParentPicker; // esi
  float v5; // [esp+Ch] [ebp+8h]

  if ( KeyValues::GetPtr(this: pData, keyName: "panel", defaultValue: nullptr) == this->m_pSheetPreviewSpeed )
  {
    v3 = this->m_pSheetPreviewSpeed->GetValue(this: this->m_pSheetPreviewSpeed);
    m_pParentPicker = this->m_pParentPicker;
    v5 = (float)v3;
    CVMTPreviewPanel::SetSheetPreviewSpeed(this: m_pParentPicker->m_pVMTPreview2D, flPreviewSpeed: (float)v3);
    CVMTPreviewPanel::SetSheetPreviewSpeed(this: m_pParentPicker->m_pVMTPreview3D, flPreviewSpeed: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CD020
// Name: public: void CVMTPreviewToolbar::UpdateToolbarGUI(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::UpdateToolbarGUI(CVMTPreviewToolbar *this)
{
  int SheetSequenceCount; // edi
  int RealSequenceNumber; // ebx
  IMaterial *NumColumns; // eax
  IMaterial *v5; // eax
  IMaterial *v6; // [esp+0h] [ebp-54h]
  char sz[64]; // [esp+Ch] [ebp-48h] BYREF
  BOOL bSecondPicker; // [esp+4Ch] [ebp-8h]
  int nRealSeqNumber; // [esp+50h] [ebp-4h]

  SheetSequenceCount = CVMTPreviewPanel::GetSheetSequenceCount(this: this->m_pParentPicker->m_pVMTPreview3D);
  RealSequenceNumber = CVMTPreviewPanel::GetRealSequenceNumber(this: this->m_pParentPicker->m_pVMTPreview3D);
  nRealSeqNumber = CVMTPreviewPanel::GetRealSequenceNumber(this: this->m_pParentPicker->m_pVMTPreview3D);
  NumColumns = (IMaterial *)vgui::CTreeViewListControl::GetNumColumns(this: (vgui::CTreeViewListControl *)this->m_pParentPicker->m_pVMTPreview3D);
  LOBYTE(bSecondPicker) = CSheetExtended::IsMaterialSeparateAlphaColorMaterial(pMat: NumColumns);
  if ( SheetSequenceCount != 0 )
  {
    V_snprintf(
      pDest: sz,
      maxLen: 0x40u,
      pFormat: "%d/%d Sequences (#%d)",
      RealSequenceNumber + 1,
      SheetSequenceCount,
      nRealSeqNumber);
    this->m_pSequenceSelection->SetText(this: this->m_pSequenceSelection, a2: sz);
    this->m_pSequenceSelection->SetEnabled(this: this->m_pSequenceSelection, a2: true);
    this->m_pSequenceSelection_Second->SetVisible(this: this->m_pSequenceSelection_Second, a2: bSecondPicker);
    this->m_pNextSeqButton->SetEnabled(this: this->m_pNextSeqButton, a2: true);
    this->m_pPrevSeqButton->SetEnabled(this: this->m_pPrevSeqButton, a2: true);
    v5 = (IMaterial *)vgui::CTreeViewListControl::GetNumColumns(this: (vgui::CTreeViewListControl *)this->m_pParentPicker->m_pVMTPreview3D);
    CSheetSequencePanel::SetFromMaterial(this: this->m_pSheetPanel, sourceMaterial: v5);
    v6 = (IMaterial *)vgui::CTreeViewListControl::GetNumColumns(this: (vgui::CTreeViewListControl *)this->m_pParentPicker->m_pVMTPreview3D);
    CSheetSequencePanel::SetFromMaterial(this: this->m_pSheetPanel_Second, sourceMaterial: v6);
  }
  else
  {
    this->m_pSequenceSelection->SetText(this: this->m_pSequenceSelection, a2: "No Sequences");
    this->m_pSequenceSelection->SetEnabled(this: this->m_pSequenceSelection, a2: false);
    this->m_pNextSeqButton->SetEnabled(this: this->m_pNextSeqButton, a2: false);
    this->m_pPrevSeqButton->SetEnabled(this: this->m_pPrevSeqButton, a2: false);
    this->m_pSequenceSelection_Second->SetVisible(this: this->m_pSequenceSelection_Second, a2: false);
    CSheetSequencePanel::SetFromMaterial(this: this->m_pSheetPanel, sourceMaterial: nullptr);
    CSheetSequencePanel::SetFromMaterial(this: this->m_pSheetPanel_Second, sourceMaterial: nullptr);
  }
  ((void (__thiscall *)(CVMTPreviewToolbar *, _DWORD))this->InvalidateLayout)(a1: this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x104CD1F0
// Name: private: virtual void CVMTPicker::OnSelectedAssetPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPicker::OnSelectedAssetPicked(CVMTPicker *this, const char *pAssetName)
{
  CVMTPreviewPanel::SetVMT(this: this->m_pVMTPreview2D, pMaterialName: pAssetName);
  CVMTPreviewPanel::SetVMT(this: this->m_pVMTPreview3D, pMaterialName: pAssetName);
  CVMTPreviewToolbar::UpdateToolbarGUI(this: this->m_pVMTPreviewToolbar);
}

//------------------------------------------------------------------------------
// Address: 0x104CD230
// Name: public: virtual void CVMTPreviewToolbar::OnNextSequence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::OnNextSequence(CVMTPreviewToolbar *this)
{
  int RealSequenceNumber; // edi
  int SheetSequenceCount; // eax
  CVMTPicker *m_pParentPicker; // ebx
  int v5; // edi

  RealSequenceNumber = CVMTPreviewPanel::GetRealSequenceNumber(this: this->m_pParentPicker->m_pVMTPreview3D);
  SheetSequenceCount = CVMTPreviewPanel::GetSheetSequenceCount(this: this->m_pParentPicker->m_pVMTPreview3D);
  m_pParentPicker = this->m_pParentPicker;
  v5 = (RealSequenceNumber + 1) % SheetSequenceCount;
  CVMTPreviewPanel::SetSheetSequence(this: m_pParentPicker->m_pVMTPreview2D, nSequence: v5);
  CVMTPreviewPanel::SetSheetSequence(this: m_pParentPicker->m_pVMTPreview3D, nSequence: v5);
  CVMTPreviewToolbar::UpdateToolbarGUI(this);
}

//------------------------------------------------------------------------------
// Address: 0x104CD290
// Name: public: virtual void CVMTPreviewToolbar::OnPrevSequence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::OnPrevSequence(CVMTPreviewToolbar *this)
{
  int RealSequenceNumber; // esi
  int SheetSequenceCount; // eax
  int v4; // esi
  CVMTPicker *m_pParentPicker; // ebx

  RealSequenceNumber = CVMTPreviewPanel::GetRealSequenceNumber(this: this->m_pParentPicker->m_pVMTPreview3D);
  SheetSequenceCount = CVMTPreviewPanel::GetSheetSequenceCount(this: this->m_pParentPicker->m_pVMTPreview3D);
  if ( RealSequenceNumber != 0 )
    v4 = (RealSequenceNumber - 1) % SheetSequenceCount;
  else
    v4 = SheetSequenceCount - 1;
  m_pParentPicker = this->m_pParentPicker;
  CVMTPreviewPanel::SetSheetSequence(this: m_pParentPicker->m_pVMTPreview2D, nSequence: v4);
  CVMTPreviewPanel::SetSheetSequence(this: m_pParentPicker->m_pVMTPreview3D, nSequence: v4);
  CVMTPreviewToolbar::UpdateToolbarGUI(this);
}

//------------------------------------------------------------------------------
// Address: 0x104CD300
// Name: public: virtual void CVMTPreviewToolbar::OnSelectSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::OnSelectSequence(CVMTPreviewToolbar *this, int nSequenceNumber)
{
  CVMTPicker *m_pParentPicker; // edi

  m_pParentPicker = this->m_pParentPicker;
  CVMTPreviewPanel::SetSheetSequence(this: m_pParentPicker->m_pVMTPreview2D, nSequence: nSequenceNumber);
  CVMTPreviewPanel::SetSheetSequence(this: m_pParentPicker->m_pVMTPreview3D, nSequence: nSequenceNumber);
  CVMTPreviewToolbar::UpdateToolbarGUI(this);
}

//------------------------------------------------------------------------------
// Address: 0x104CD340
// Name: public: virtual void CVMTPreviewToolbar::OnSheetSequenceSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::OnSheetSequenceSelected(CVMTPreviewToolbar *this, KeyValues *pData)
{
  int Int; // eax
  CVMTPicker *m_pParentPicker; // edi
  int v5; // esi
  int v6; // eax
  CVMTPicker *v7; // edi
  int v8; // esi

  if ( KeyValues::GetInt(this: pData, keyName: "bIsSecondSequence", defaultValue: 0) != 0 )
  {
    Int = KeyValues::GetInt(this: pData, keyName: "nSequenceNumber", defaultValue: 0);
    m_pParentPicker = this->m_pParentPicker;
    v5 = Int;
    CVMTPreviewPanel::SetSecondarySheetSequence(this: m_pParentPicker->m_pVMTPreview2D, nSequence: Int);
    CVMTPreviewPanel::SetSecondarySheetSequence(this: m_pParentPicker->m_pVMTPreview3D, nSequence: v5);
  }
  else
  {
    v6 = KeyValues::GetInt(this: pData, keyName: "nSequenceNumber", defaultValue: 0);
    v7 = this->m_pParentPicker;
    v8 = v6;
    CVMTPreviewPanel::SetSheetSequence(this: v7->m_pVMTPreview2D, nSequence: v6);
    CVMTPreviewPanel::SetSheetSequence(this: v7->m_pVMTPreview3D, nSequence: v8);
  }
  CVMTPreviewToolbar::UpdateToolbarGUI(this);
}

//------------------------------------------------------------------------------
// Address: 0x104CD3D0
// Name: public: static void CVMTPreviewToolbar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVMTPreviewToolbar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`CVMTPreviewToolbar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `CVMTPreviewToolbar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SliderMoved";
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
// Address: 0x104CD460
// Name: public: static void CVMTPreviewToolbar::PanelMessageFunc_OnSelectSequence::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVMTPreviewToolbar::PanelMessageFunc_OnSelectSequence::InitVar(int a1@<ebp>)
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
  if ( !`CVMTPreviewToolbar::PanelMessageFunc_OnSelectSequence::InitVar'::`2'::bAdded )
  {
    `CVMTPreviewToolbar::PanelMessageFunc_OnSelectSequence::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OnSelectSequence";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "nSequenceNumber";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CD500
// Name: public: static void CVMTPreviewToolbar::PanelMessageFunc_OnNextSequence::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVMTPreviewToolbar::PanelMessageFunc_OnNextSequence::InitVar(int a1@<ebp>)
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
  if ( !`CVMTPreviewToolbar::PanelMessageFunc_OnNextSequence::InitVar'::`2'::bAdded )
  {
    `CVMTPreviewToolbar::PanelMessageFunc_OnNextSequence::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSnapshotGrid::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnNextSequence";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CD590
// Name: public: static void CVMTPreviewToolbar::PanelMessageFunc_OnPrevSequence::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVMTPreviewToolbar::PanelMessageFunc_OnPrevSequence::InitVar(int a1@<ebp>)
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
  if ( !`CVMTPreviewToolbar::PanelMessageFunc_OnPrevSequence::InitVar'::`2'::bAdded )
  {
    `CVMTPreviewToolbar::PanelMessageFunc_OnPrevSequence::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnPrevSequence";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104CD620
// Name: public: static void CVMTPreviewToolbar::PanelMessageFunc_OnSheetSequenceSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVMTPreviewToolbar::PanelMessageFunc_OnSheetSequenceSelected::InitVar(int a1@<ebp>)
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
  if ( !`CVMTPreviewToolbar::PanelMessageFunc_OnSheetSequenceSelected::InitVar'::`2'::bAdded )
  {
    `CVMTPreviewToolbar::PanelMessageFunc_OnSheetSequenceSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SheetSequenceSelected";
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
// Address: 0x104CD6B0
// Name: public: CVMTPreviewToolbar::CVMTPreviewToolbar(class vgui::Panel __near *,char const __near *,class CVMTPicker __near *)
// Source: json
//------------------------------------------------------------------------------
CVMTPreviewToolbar *__thiscall CVMTPreviewToolbar::CVMTPreviewToolbar(
        CVMTPreviewToolbar *this,
        vgui::Panel *parent,
        const char *panelName,
        CVMTPicker *parentpicker)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::CBoxSizer *v8; // eax
  vgui::CBoxSizer *v9; // edi
  __int64 v10; // xmm1_8
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // eax
  vgui::MenuButton *v15; // eax
  vgui::MenuButton *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  vgui::MenuButton *v21; // eax
  vgui::MenuButton *v22; // eax
  vgui::Slider *v23; // eax
  vgui::Slider *v24; // eax
  CSheetSequencePanel *v25; // eax
  CSheetSequencePanel *v26; // eax
  CSheetSequencePanel *v27; // eax
  CSheetSequencePanel *v28; // eax
  int v30; // [esp-Ch] [ebp-48h]
  int v31; // [esp-Ch] [ebp-48h]
  int m_Size; // [esp-8h] [ebp-44h]
  vgui::Slider *m_pSheetPreviewSpeed; // [esp-8h] [ebp-44h]
  vgui::SizerAddArgs_t buttonAddArgs; // [esp+Ch] [ebp-30h] BYREF
  vgui::SizerAddArgs_t args; // [esp+24h] [ebp-18h] BYREF
  int savedregs; // [esp+3Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (CVMTPreviewToolbar_vtbl *)&CVMTPreviewToolbar::`vftable';
  if ( `CVMTPreviewToolbar::ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPreviewToolbar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
    v5->pfnClassName = CVMTPreviewToolbar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CVMTPreviewToolbar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVMTPreviewToolbar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CVMTPreviewToolbar");
    v6->pfnClassName = CVMTPreviewToolbar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CVMTPreviewToolbar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPreviewToolbar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPreviewToolbar");
    v7->pfnClassName = CVMTPreviewToolbar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  CVMTPreviewToolbar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  CVMTPreviewToolbar::PanelMessageFunc_OnSelectSequence::InitVar(a1: (int)&savedregs);
  CVMTPreviewToolbar::PanelMessageFunc_OnNextSequence::InitVar(a1: (int)&savedregs);
  CVMTPreviewToolbar::PanelMessageFunc_OnPrevSequence::InitVar(a1: (int)&savedregs);
  CVMTPreviewToolbar::PanelMessageFunc_OnSheetSequenceSelected::InitVar(a1: (int)&savedregs);
  this->m_pParentPicker = parentpicker;
  v8 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v8 != nullptr )
    v9 = vgui::CBoxSizer::CBoxSizer(this: v8, LayoutDirection: ESLD_HORIZONTAL);
  else
    v9 = nullptr;
  vgui::Panel::SetSizer(this, pSizer: v9);
  *(_QWORD *)&args.m_flExpandFactor = 0x200000000LL;
  args.m_nMinX = -1;
  *(_QWORD *)&buttonAddArgs.m_flExpandFactor = 0x200000000LL;
  args.m_bMinorExpand = false;
  args.m_bIgnoreMemberMin = true;
  args.m_nMinY = 18;
  *(_QWORD *)&buttonAddArgs.m_bMinorExpand = *(_QWORD *)&args.m_bMinorExpand;
  v10 = *(_QWORD *)&args.m_nMinY;
  args.m_nMinY = -1;
  *(_QWORD *)&buttonAddArgs.m_nMinY = v10;
  m_Size = v9->m_Members.m_Size;
  args.m_bMinorExpand = true;
  args.m_bIgnoreMemberMin = false;
  args.m_nPadding = 15;
  vgui::CSizerBase::InsertSpacer(this: v9, nIndex: m_Size, &args);
  v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "PrevSeqButton",
            text: "<",
            pActionSignalTarget: this,
            pCmd: nullptr);
  else
    v12 = nullptr;
  this->m_pPrevSeqButton = v12;
  v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v13 != nullptr )
    v14 = KeyValues::KeyValues(this: v13, setName: "OnPrevSequence");
  else
    v14 = nullptr;
  this->m_pPrevSeqButton->SetCommand(this: this->m_pPrevSeqButton, a2: v14);
  vgui::CSizerBase::InsertPanel(
    this: v9,
    nIndex: v9->m_Members.m_Size,
    pPanel: this->m_pPrevSeqButton,
    args: &buttonAddArgs);
  v15 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v15 != nullptr )
    v16 = vgui::MenuButton::MenuButton(this: v15, parent: this, panelName: "SequenceSelection", text: "-");
  else
    v16 = nullptr;
  this->m_pSequenceSelection = v16;
  v30 = v9->m_Members.m_Size;
  args.m_bIgnoreMemberMin = true;
  args.m_nMinX = 120;
  args.m_nMinY = 18;
  args.m_flExpandFactor = 0.0;
  args.m_bMinorExpand = false;
  args.m_nPadding = 2;
  vgui::CSizerBase::InsertPanel(this: v9, nIndex: v30, pPanel: v16, &args);
  v17 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v17 != nullptr )
    v18 = vgui::Button::Button(
            this: v17,
            parent: this,
            panelName: "NextSeqButton",
            text: ">",
            pActionSignalTarget: this,
            pCmd: nullptr);
  else
    v18 = nullptr;
  this->m_pNextSeqButton = v18;
  v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v19 != nullptr )
    v20 = KeyValues::KeyValues(this: v19, setName: "OnNextSequence");
  else
    v20 = nullptr;
  this->m_pNextSeqButton->SetCommand(this: this->m_pNextSeqButton, a2: v20);
  vgui::CSizerBase::InsertPanel(
    this: v9,
    nIndex: v9->m_Members.m_Size,
    pPanel: this->m_pNextSeqButton,
    args: &buttonAddArgs);
  v21 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v21 != nullptr )
    v22 = vgui::MenuButton::MenuButton(this: v21, parent: this, panelName: "SequenceSelection", text: "(Color)");
  else
    v22 = nullptr;
  this->m_pSequenceSelection_Second = v22;
  vgui::CSizerBase::InsertPanel(this: v9, nIndex: v9->m_Members.m_Size, pPanel: v22, args: &buttonAddArgs);
  v23 = (vgui::Slider *)operator new(nSize: 0x1ACu);
  if ( v23 != nullptr )
    v24 = vgui::Slider::Slider(this: v23, parent: this, panelName: "SheetPreviewSpeed");
  else
    v24 = nullptr;
  this->m_pSheetPreviewSpeed = v24;
  v24->SetRange(this: v24, a2: 5, a3: 3000);
  this->m_pSheetPreviewSpeed->SetValue(this: this->m_pSheetPreviewSpeed, a2: 750, a3: true);
  this->m_pSheetPreviewSpeed->AddActionSignalTarget_2(this: this->m_pSheetPreviewSpeed, a2: this);
  m_pSheetPreviewSpeed = this->m_pSheetPreviewSpeed;
  v31 = v9->m_Members.m_Size;
  args.m_bIgnoreMemberMin = true;
  args.m_nMinX = 150;
  args.m_nMinY = 18;
  args.m_flExpandFactor = 0.0;
  args.m_bMinorExpand = false;
  args.m_nPadding = 2;
  vgui::CSizerBase::InsertPanel(this: v9, nIndex: v31, pPanel: m_pSheetPreviewSpeed, &args);
  v25 = (CSheetSequencePanel *)operator new(nSize: 0x438u);
  if ( v25 != nullptr )
    v26 = CSheetSequencePanel::CSheetSequencePanel(this: v25, pParent: this, pPanelName: "sheetpanel");
  else
    v26 = nullptr;
  this->m_pSheetPanel = v26;
  v26->AddActionSignalTarget_2(this: v26, a2: this);
  this->m_pSequenceSelection->SetMenu(this: this->m_pSequenceSelection, a2: this->m_pSheetPanel);
  v27 = (CSheetSequencePanel *)operator new(nSize: 0x438u);
  if ( v27 != nullptr )
    v28 = CSheetSequencePanel::CSheetSequencePanel(this: v27, pParent: this, pPanelName: "sheetpanel_second");
  else
    v28 = nullptr;
  this->m_pSheetPanel_Second = v28;
  CSheetSequencePanel::SetSecondSequenceView(this: v28, bIsSecondSequenceView: true);
  this->m_pSheetPanel_Second->AddActionSignalTarget_2(this: this->m_pSheetPanel_Second, a2: this);
  this->m_pSequenceSelection_Second->SetMenu(this: this->m_pSequenceSelection_Second, a2: this->m_pSheetPanel_Second);
  CVMTPreviewToolbar::UpdateToolbarGUI(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104CDAF0
// Name: public: virtual struct vgui::PanelMessageMap __near * CVMTPreviewToolbar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVMTPreviewToolbar::GetMessageMap(CVMTPreviewToolbar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVMTPreviewToolbar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPreviewToolbar::GetMessageMap'::`2'::s_pMap;
  `CVMTPreviewToolbar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
  `CVMTPreviewToolbar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CDB20
// Name: public: virtual struct PanelAnimationMap __near * CVMTPreviewToolbar::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVMTPreviewToolbar::GetAnimMap(CVMTPreviewToolbar *this)
{
  return FindOrAddPanelAnimationMap(className: "CVMTPreviewToolbar");
}

//------------------------------------------------------------------------------
// Address: 0x104CDB30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVMTPreviewToolbar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVMTPreviewToolbar::GetKBMap(CVMTPreviewToolbar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVMTPreviewToolbar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPreviewToolbar::GetKBMap'::`2'::s_pMap;
  `CVMTPreviewToolbar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPreviewToolbar");
  `CVMTPreviewToolbar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CDB60
// Name: public: CVMTPicker::CVMTPicker(class vgui::Panel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CVMTPicker *__thiscall CVMTPicker::CVMTPicker(CVMTPicker *this, vgui::Panel *pParent, bool bAllowMultiselect)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Splitter *v7; // eax
  vgui::Splitter *v8; // eax
  vgui::Panel *Child; // edi
  vgui::Splitter *v10; // eax
  vgui::Splitter *v11; // eax
  vgui::Panel *v12; // edi
  vgui::Panel *v13; // ebx
  CVMTPreviewPanel *v14; // eax
  CVMTPreviewPanel *v15; // eax
  CVMTPreviewPanel *v16; // eax
  CVMTPreviewPanel *v17; // eax
  CVMTPreviewToolbar *v18; // eax
  CVMTPreviewToolbar *v19; // eax
  vgui::Panel *pSplitterLeftSide; // [esp+14h] [ebp+8h]

  CBaseAssetPicker::CBaseAssetPicker(
    this,
    pParent,
    pAssetType: "VMT Files",
    pExt: "vmt",
    pSubDir: "materials",
    pTextType: "vmtName",
    pAssetSearchPath: "GAME");
  this->__vftable = (CVMTPicker_vtbl *)&CVMTPicker::`vftable';
  if ( `CVMTPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPicker::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CVMTPicker");
    v4->pfnClassName = CVMTPicker::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CVMTPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVMTPicker::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CVMTPicker");
    v5->pfnClassName = CVMTPicker::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CVMTPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPicker::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPicker");
    v6->pfnClassName = CVMTPicker::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  }
  v7 = (vgui::Splitter *)operator new(nSize: 0x198u);
  if ( v7 != nullptr )
    v8 = vgui::Splitter::Splitter(
           this: v7,
           parent: this,
           name: "PreviewSplitter",
           mode: SPLITTER_MODE_VERTICAL,
           nCount: 1);
  else
    v8 = nullptr;
  this->m_pPreviewSplitter = v8;
  pSplitterLeftSide = vgui::Panel::GetChild(this: v8, index: 0);
  Child = vgui::Panel::GetChild(this: this->m_pPreviewSplitter, index: 1);
  v10 = (vgui::Splitter *)operator new(nSize: 0x198u);
  if ( v10 != nullptr )
    v11 = vgui::Splitter::Splitter(
            this: v10,
            parent: Child,
            name: "2D3DSplitter",
            mode: SPLITTER_MODE_HORIZONTAL,
            nCount: 1);
  else
    v11 = nullptr;
  this->m_p2D3DSplitter = v11;
  v12 = vgui::Panel::GetChild(this: v11, index: 0);
  v13 = vgui::Panel::GetChild(this: this->m_p2D3DSplitter, index: 1);
  v14 = (CVMTPreviewPanel *)operator new(nSize: 0x1A8u);
  if ( v14 != nullptr )
    v15 = CVMTPreviewPanel::CVMTPreviewPanel(this: v14, pParent: v12, pName: "VMTPreview2D");
  else
    v15 = nullptr;
  this->m_pVMTPreview2D = v15;
  v16 = (CVMTPreviewPanel *)operator new(nSize: 0x1A8u);
  if ( v16 != nullptr )
    v17 = CVMTPreviewPanel::CVMTPreviewPanel(this: v16, pParent: v13, pName: "VMTPreview3D");
  else
    v17 = nullptr;
  this->m_pVMTPreview3D = v17;
  CVMTPreviewPanel::DrawIn3DMode(this: v17, b3DMode: true);
  v18 = (CVMTPreviewToolbar *)operator new(nSize: 0x1A4u);
  if ( v18 != nullptr )
    v19 = CVMTPreviewToolbar::CVMTPreviewToolbar(
            this: v18,
            parent: v13,
            panelName: "PreviewToolbar",
            parentpicker: this);
  else
    v19 = nullptr;
  this->m_pVMTPreviewToolbar = v19;
  CBaseAssetPicker::CreateStandardControls(this, pParent: pSplitterLeftSide, bAllowMultiselect);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/vmtpicker.res", dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104CDD60
// Name: public: CVMTPickerFrame::CVMTPickerFrame(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CVMTPickerFrame *__thiscall CVMTPickerFrame::CVMTPickerFrame(
        CVMTPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        bool bAllowMultiselect)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  CVMTPicker *v8; // eax
  CVMTPicker *v9; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CVMTPickerFrame_vtbl *)&CVMTPickerFrame::`vftable';
  if ( `CVMTPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPickerFrame::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CVMTPickerFrame");
    v5->pfnClassName = CVMTPickerFrame::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CVMTPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVMTPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CVMTPickerFrame");
    v6->pfnClassName = CVMTPickerFrame::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CVMTPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPickerFrame");
    v7->pfnClassName = CVMTPickerFrame::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v8 = (CVMTPicker *)operator new(nSize: 0x258u);
  if ( v8 != nullptr )
    v9 = CVMTPicker::CVMTPicker(this: v8, pParent: this, bAllowMultiselect);
  else
    v9 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v9);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/vmtpickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104CDE60
// Name: public: virtual struct vgui::PanelMessageMap __near * CVMTPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVMTPickerFrame::GetMessageMap(CVMTPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVMTPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CVMTPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVMTPickerFrame");
  `CVMTPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104CDE90
// Name: public: virtual struct PanelAnimationMap __near * CVMTPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVMTPickerFrame::GetAnimMap(CVMTPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CVMTPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x104CDEA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVMTPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVMTPickerFrame::GetKBMap(CVMTPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVMTPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPickerFrame::GetKBMap'::`2'::s_pMap;
  `CVMTPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPickerFrame");
  `CVMTPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004D4610
// Name: public: static char const __near * CVMTPreviewToolbar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVMTPreviewToolbar::GetPanelClassName()
{
  return "CVMTPreviewToolbar";
}

//------------------------------------------------------------------------------
// Address: 0x004D4620
// Name: public: static char const __near * CVMTPicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVMTPicker::GetPanelClassName()
{
  return "CVMTPicker";
}

//------------------------------------------------------------------------------
// Address: 0x004D4630
// Name: public: static char const __near * CVMTPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVMTPickerFrame::GetPanelClassName()
{
  return "CVMTPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004D4640
// Name: public: virtual void CVMTPreviewToolbar::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::ApplySchemeSettings(CVMTPreviewToolbar *this, vgui::IScheme *pScheme)
{
  vgui::MenuButton_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v3 = this->m_pSequenceSelection->__vftable;
  v4 = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
  v3->SetFont(this: this->m_pSequenceSelection, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004D4680
// Name: public: virtual void CVMTPicker::CustomizeSelectionMessage(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPicker::CustomizeSelectionMessage(CVMTPicker *this, KeyValues *pKeyValues)
{
  int SheetSequenceCount; // eax
  int RealSequenceNumber; // eax
  int CurrentSecondarySequence; // eax

  SheetSequenceCount = CVMTPreviewPanel::GetSheetSequenceCount(this: this->m_pVMTPreview3D);
  KeyValues::SetInt(this: pKeyValues, keyName: "sheet_sequence_count", value: SheetSequenceCount);
  RealSequenceNumber = CVMTPreviewPanel::GetRealSequenceNumber(this: this->m_pVMTPreview3D);
  KeyValues::SetInt(this: pKeyValues, keyName: "sheet_sequence_number", value: RealSequenceNumber);
  CurrentSecondarySequence = CVMTPreviewPanel::GetCurrentSecondarySequence(this: this->m_pVMTPreview3D);
  KeyValues::SetInt(this: pKeyValues, keyName: "sheet_sequence_secondary_number", value: CurrentSecondarySequence);
}

//------------------------------------------------------------------------------
// Address: 0x004D46E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CVMTPicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVMTPicker::GetMessageMap(CVMTPicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVMTPicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPicker::GetMessageMap'::`2'::s_pMap;
  `CVMTPicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVMTPicker");
  `CVMTPicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D4710
// Name: public: virtual struct PanelAnimationMap __near * CVMTPicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVMTPicker::GetAnimMap(CVMTPicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CVMTPicker");
}

//------------------------------------------------------------------------------
// Address: 0x004D4720
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVMTPicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVMTPicker::GetKBMap(CVMTPicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVMTPicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPicker::GetKBMap'::`2'::s_pMap;
  `CVMTPicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPicker");
  `CVMTPicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D4750
// Name: public: virtual void CVMTPreviewToolbar::OnSliderMoved(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::OnSliderMoved(CVMTPreviewToolbar *this, KeyValues *pData)
{
  int v3; // eax
  CVMTPicker *m_pParentPicker; // esi
  float pDataa; // [esp+10h] [ebp+8h]

  if ( KeyValues::GetPtr(this: pData, keyName: "panel", defaultValue: nullptr) == this->m_pSheetPreviewSpeed )
  {
    v3 = this->m_pSheetPreviewSpeed->GetValue(this: this->m_pSheetPreviewSpeed);
    m_pParentPicker = this->m_pParentPicker;
    pDataa = (float)v3;
    CVMTPreviewPanel::SetSheetPreviewSpeed(this: m_pParentPicker->m_pVMTPreview2D, flPreviewSpeed: (float)v3);
    CVMTPreviewPanel::SetSheetPreviewSpeed(this: m_pParentPicker->m_pVMTPreview3D, flPreviewSpeed: pDataa);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D47C0
// Name: public: void CVMTPreviewToolbar::UpdateToolbarGUI(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::UpdateToolbarGUI(CVMTPreviewToolbar *this)
{
  int SheetSequenceCount; // edi
  int RealSequenceNumber; // ebx
  IMaterial *NumColumns; // eax
  IMaterial *v5; // eax
  IMaterial *v6; // [esp+0h] [ebp-54h]
  char sz[64]; // [esp+Ch] [ebp-48h] BYREF
  BOOL bSecondPicker; // [esp+4Ch] [ebp-8h]
  int nRealSeqNumber; // [esp+50h] [ebp-4h]

  SheetSequenceCount = CVMTPreviewPanel::GetSheetSequenceCount(this: this->m_pParentPicker->m_pVMTPreview3D);
  RealSequenceNumber = CVMTPreviewPanel::GetRealSequenceNumber(this: this->m_pParentPicker->m_pVMTPreview3D);
  nRealSeqNumber = CVMTPreviewPanel::GetRealSequenceNumber(this: this->m_pParentPicker->m_pVMTPreview3D);
  NumColumns = (IMaterial *)vgui::CTreeViewListControl::GetNumColumns(this: (vgui::CTreeViewListControl *)this->m_pParentPicker->m_pVMTPreview3D);
  LOBYTE(bSecondPicker) = CSheetExtended::IsMaterialSeparateAlphaColorMaterial(pMat: NumColumns);
  if ( SheetSequenceCount != 0 )
  {
    V_snprintf(
      pDest: sz,
      maxLen: 64,
      pFormat: "%d/%d Sequences (#%d)",
      RealSequenceNumber + 1,
      SheetSequenceCount,
      nRealSeqNumber);
    this->m_pSequenceSelection->SetText_2(this: this->m_pSequenceSelection, a2: sz);
    this->m_pSequenceSelection->SetEnabled(this: this->m_pSequenceSelection, a2: true);
    this->m_pSequenceSelection_Second->SetVisible(this: this->m_pSequenceSelection_Second, a2: bSecondPicker);
    this->m_pNextSeqButton->SetEnabled(this: this->m_pNextSeqButton, a2: true);
    this->m_pPrevSeqButton->SetEnabled(this: this->m_pPrevSeqButton, a2: true);
    v5 = (IMaterial *)vgui::CTreeViewListControl::GetNumColumns(this: (vgui::CTreeViewListControl *)this->m_pParentPicker->m_pVMTPreview3D);
    CSheetSequencePanel::SetFromMaterial(this: this->m_pSheetPanel, sourceMaterial: v5);
    v6 = (IMaterial *)vgui::CTreeViewListControl::GetNumColumns(this: (vgui::CTreeViewListControl *)this->m_pParentPicker->m_pVMTPreview3D);
    CSheetSequencePanel::SetFromMaterial(this: this->m_pSheetPanel_Second, sourceMaterial: v6);
  }
  else
  {
    this->m_pSequenceSelection->SetText_2(this: this->m_pSequenceSelection, a2: "No Sequences");
    this->m_pSequenceSelection->SetEnabled(this: this->m_pSequenceSelection, a2: false);
    this->m_pNextSeqButton->SetEnabled(this: this->m_pNextSeqButton, a2: false);
    this->m_pPrevSeqButton->SetEnabled(this: this->m_pPrevSeqButton, a2: false);
    this->m_pSequenceSelection_Second->SetVisible(this: this->m_pSequenceSelection_Second, a2: false);
    CSheetSequencePanel::SetFromMaterial(this: this->m_pSheetPanel, sourceMaterial: nullptr);
    CSheetSequencePanel::SetFromMaterial(this: this->m_pSheetPanel_Second, sourceMaterial: nullptr);
  }
  ((void (__thiscall *)(CVMTPreviewToolbar *, _DWORD))this->InvalidateLayout)(a1: this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004D4990
// Name: private: virtual void CVMTPicker::OnSelectedAssetPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPicker::OnSelectedAssetPicked(CVMTPicker *this, const char *pAssetName)
{
  CVMTPreviewPanel::SetVMT(this: this->m_pVMTPreview2D, pMaterialName: pAssetName);
  CVMTPreviewPanel::SetVMT(this: this->m_pVMTPreview3D, pMaterialName: pAssetName);
  CVMTPreviewToolbar::UpdateToolbarGUI(this: this->m_pVMTPreviewToolbar);
}

//------------------------------------------------------------------------------
// Address: 0x004D49D0
// Name: public: virtual void CVMTPreviewToolbar::OnNextSequence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::OnNextSequence(CVMTPreviewToolbar *this)
{
  int RealSequenceNumber; // edi
  int SheetSequenceCount; // eax
  CVMTPicker *m_pParentPicker; // ebx
  int v5; // edi

  RealSequenceNumber = CVMTPreviewPanel::GetRealSequenceNumber(this: this->m_pParentPicker->m_pVMTPreview3D);
  SheetSequenceCount = CVMTPreviewPanel::GetSheetSequenceCount(this: this->m_pParentPicker->m_pVMTPreview3D);
  m_pParentPicker = this->m_pParentPicker;
  v5 = (RealSequenceNumber + 1) % SheetSequenceCount;
  CVMTPreviewPanel::SetSheetSequence(this: m_pParentPicker->m_pVMTPreview2D, nSequence: v5);
  CVMTPreviewPanel::SetSheetSequence(this: m_pParentPicker->m_pVMTPreview3D, nSequence: v5);
  CVMTPreviewToolbar::UpdateToolbarGUI(this);
}

//------------------------------------------------------------------------------
// Address: 0x004D4A30
// Name: public: virtual void CVMTPreviewToolbar::OnPrevSequence(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::OnPrevSequence(CVMTPreviewToolbar *this)
{
  int RealSequenceNumber; // esi
  int SheetSequenceCount; // eax
  int v4; // esi
  CVMTPicker *m_pParentPicker; // ebx

  RealSequenceNumber = CVMTPreviewPanel::GetRealSequenceNumber(this: this->m_pParentPicker->m_pVMTPreview3D);
  SheetSequenceCount = CVMTPreviewPanel::GetSheetSequenceCount(this: this->m_pParentPicker->m_pVMTPreview3D);
  if ( RealSequenceNumber != 0 )
    v4 = (RealSequenceNumber - 1) % SheetSequenceCount;
  else
    v4 = SheetSequenceCount - 1;
  m_pParentPicker = this->m_pParentPicker;
  CVMTPreviewPanel::SetSheetSequence(this: m_pParentPicker->m_pVMTPreview2D, nSequence: v4);
  CVMTPreviewPanel::SetSheetSequence(this: m_pParentPicker->m_pVMTPreview3D, nSequence: v4);
  CVMTPreviewToolbar::UpdateToolbarGUI(this);
}

//------------------------------------------------------------------------------
// Address: 0x004D4AA0
// Name: public: virtual void CVMTPreviewToolbar::OnSelectSequence(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::OnSelectSequence(CVMTPreviewToolbar *this, int nSequenceNumber)
{
  CVMTPicker *m_pParentPicker; // edi

  m_pParentPicker = this->m_pParentPicker;
  CVMTPreviewPanel::SetSheetSequence(this: m_pParentPicker->m_pVMTPreview2D, nSequence: nSequenceNumber);
  CVMTPreviewPanel::SetSheetSequence(this: m_pParentPicker->m_pVMTPreview3D, nSequence: nSequenceNumber);
  CVMTPreviewToolbar::UpdateToolbarGUI(this);
}

//------------------------------------------------------------------------------
// Address: 0x004D4AE0
// Name: public: virtual void CVMTPreviewToolbar::OnSheetSequenceSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVMTPreviewToolbar::OnSheetSequenceSelected(CVMTPreviewToolbar *this, KeyValues *pData)
{
  int Int; // eax
  CVMTPicker *m_pParentPicker; // edi
  int v5; // esi
  int v6; // eax
  CVMTPicker *v7; // edi
  int v8; // esi

  if ( KeyValues::GetInt(this: pData, keyName: "bIsSecondSequence", defaultValue: 0) != 0 )
  {
    Int = KeyValues::GetInt(this: pData, keyName: "nSequenceNumber", defaultValue: 0);
    m_pParentPicker = this->m_pParentPicker;
    v5 = Int;
    CVMTPreviewPanel::SetSecondarySheetSequence(this: m_pParentPicker->m_pVMTPreview2D, nSequence: Int);
    CVMTPreviewPanel::SetSecondarySheetSequence(this: m_pParentPicker->m_pVMTPreview3D, nSequence: v5);
  }
  else
  {
    v6 = KeyValues::GetInt(this: pData, keyName: "nSequenceNumber", defaultValue: 0);
    v7 = this->m_pParentPicker;
    v8 = v6;
    CVMTPreviewPanel::SetSheetSequence(this: v7->m_pVMTPreview2D, nSequence: v6);
    CVMTPreviewPanel::SetSheetSequence(this: v7->m_pVMTPreview3D, nSequence: v8);
  }
  CVMTPreviewToolbar::UpdateToolbarGUI(this);
}

//------------------------------------------------------------------------------
// Address: 0x004D4B70
// Name: public: static void CVMTPreviewToolbar::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVMTPreviewToolbar::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`CVMTPreviewToolbar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `CVMTPreviewToolbar::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SliderMoved";
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
// Address: 0x004D4C00
// Name: public: static void CVMTPreviewToolbar::PanelMessageFunc_OnSelectSequence::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVMTPreviewToolbar::PanelMessageFunc_OnSelectSequence::InitVar(int a1@<ebp>)
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
  if ( !`CVMTPreviewToolbar::PanelMessageFunc_OnSelectSequence::InitVar'::`2'::bAdded )
  {
    `CVMTPreviewToolbar::PanelMessageFunc_OnSelectSequence::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OnSelectSequence";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "nSequenceNumber";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D4CA0
// Name: public: static void CVMTPreviewToolbar::PanelMessageFunc_OnNextSequence::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVMTPreviewToolbar::PanelMessageFunc_OnNextSequence::InitVar(int a1@<ebp>)
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
  if ( !`CVMTPreviewToolbar::PanelMessageFunc_OnNextSequence::InitVar'::`2'::bAdded )
  {
    `CVMTPreviewToolbar::PanelMessageFunc_OnNextSequence::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnNextSequence";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D4D30
// Name: public: static void CVMTPreviewToolbar::PanelMessageFunc_OnPrevSequence::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVMTPreviewToolbar::PanelMessageFunc_OnPrevSequence::InitVar(int a1@<ebp>)
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
  if ( !`CVMTPreviewToolbar::PanelMessageFunc_OnPrevSequence::InitVar'::`2'::bAdded )
  {
    `CVMTPreviewToolbar::PanelMessageFunc_OnPrevSequence::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "OnPrevSequence";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D4DC0
// Name: public: static void CVMTPreviewToolbar::PanelMessageFunc_OnSheetSequenceSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVMTPreviewToolbar::PanelMessageFunc_OnSheetSequenceSelected::InitVar(int a1@<ebp>)
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
  if ( !`CVMTPreviewToolbar::PanelMessageFunc_OnSheetSequenceSelected::InitVar'::`2'::bAdded )
  {
    `CVMTPreviewToolbar::PanelMessageFunc_OnSheetSequenceSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SheetSequenceSelected";
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
// Address: 0x004D4E50
// Name: public: CVMTPreviewToolbar::CVMTPreviewToolbar(class vgui::Panel __near *,char const __near *,class CVMTPicker __near *)
// Source: json
//------------------------------------------------------------------------------
CVMTPreviewToolbar *__thiscall CVMTPreviewToolbar::CVMTPreviewToolbar(
        CVMTPreviewToolbar *this,
        vgui::Panel *parent,
        const char *panelName,
        CVMTPicker *parentpicker)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::CBoxSizer *v8; // eax
  vgui::CBoxSizer *v9; // edi
  __int64 v10; // xmm1_8
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // eax
  vgui::MenuButton *v15; // eax
  vgui::MenuButton *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  vgui::MenuButton *v21; // eax
  vgui::MenuButton *v22; // eax
  vgui::Slider *v23; // eax
  vgui::Slider *v24; // eax
  CSheetSequencePanel *v25; // eax
  CSheetSequencePanel *v26; // eax
  CSheetSequencePanel *v27; // eax
  CSheetSequencePanel *v28; // eax
  int v30; // [esp-Ch] [ebp-48h]
  int v31; // [esp-Ch] [ebp-48h]
  int m_Size; // [esp-8h] [ebp-44h]
  vgui::Slider *m_pSheetPreviewSpeed; // [esp-8h] [ebp-44h]
  vgui::SizerAddArgs_t buttonAddArgs; // [esp+Ch] [ebp-30h] BYREF
  vgui::SizerAddArgs_t args; // [esp+24h] [ebp-18h] BYREF
  int savedregs; // [esp+3Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName);
  this->__vftable = (CVMTPreviewToolbar_vtbl *)&CVMTPreviewToolbar::`vftable';
  if ( `CVMTPreviewToolbar::ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPreviewToolbar::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
    v5->pfnClassName = CVMTPreviewToolbar::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CVMTPreviewToolbar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVMTPreviewToolbar::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CVMTPreviewToolbar");
    v6->pfnClassName = CVMTPreviewToolbar::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CVMTPreviewToolbar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPreviewToolbar::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPreviewToolbar");
    v7->pfnClassName = CVMTPreviewToolbar::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  CVMTPreviewToolbar::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  CVMTPreviewToolbar::PanelMessageFunc_OnSelectSequence::InitVar(a1: (int)&savedregs);
  CVMTPreviewToolbar::PanelMessageFunc_OnNextSequence::InitVar(a1: (int)&savedregs);
  CVMTPreviewToolbar::PanelMessageFunc_OnPrevSequence::InitVar(a1: (int)&savedregs);
  CVMTPreviewToolbar::PanelMessageFunc_OnSheetSequenceSelected::InitVar(a1: (int)&savedregs);
  this->m_pParentPicker = parentpicker;
  v8 = (vgui::CBoxSizer *)MemAlloc_Alloc(nSize: 0x24u);
  if ( v8 != nullptr )
    v9 = vgui::CBoxSizer::CBoxSizer(this: v8, LayoutDirection: ESLD_HORIZONTAL);
  else
    v9 = nullptr;
  vgui::Panel::SetSizer(this, pSizer: v9);
  *(_QWORD *)&args.m_flExpandFactor = 0x200000000LL;
  args.m_nMinX = -1;
  *(_QWORD *)&buttonAddArgs.m_flExpandFactor = 0x200000000LL;
  args.m_bMinorExpand = false;
  args.m_bIgnoreMemberMin = true;
  args.m_nMinY = 18;
  *(_QWORD *)&buttonAddArgs.m_bMinorExpand = *(_QWORD *)&args.m_bMinorExpand;
  v10 = *(_QWORD *)&args.m_nMinY;
  args.m_nMinY = -1;
  *(_QWORD *)&buttonAddArgs.m_nMinY = v10;
  m_Size = v9->m_Members.m_Size;
  args.m_bMinorExpand = true;
  args.m_bIgnoreMemberMin = false;
  args.m_nPadding = 15;
  vgui::CSizerBase::InsertSpacer(this: v9, nIndex: m_Size, &args);
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "PrevSeqButton",
            text: "<",
            pActionSignalTarget: this,
            pCmd: nullptr);
  else
    v12 = nullptr;
  this->m_pPrevSeqButton = v12;
  v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v13 != nullptr )
    v14 = KeyValues::KeyValues(this: v13, setName: "OnPrevSequence");
  else
    v14 = nullptr;
  this->m_pPrevSeqButton->SetCommand(this: this->m_pPrevSeqButton, a2: v14);
  vgui::CSizerBase::InsertPanel(
    this: v9,
    nIndex: v9->m_Members.m_Size,
    pPanel: this->m_pPrevSeqButton,
    args: &buttonAddArgs);
  v15 = (vgui::MenuButton *)MemAlloc_Alloc(nSize: 0x214u);
  if ( v15 != nullptr )
    v16 = vgui::MenuButton::MenuButton(this: v15, parent: this, panelName: "SequenceSelection", text: "-");
  else
    v16 = nullptr;
  this->m_pSequenceSelection = v16;
  v30 = v9->m_Members.m_Size;
  args.m_bIgnoreMemberMin = true;
  args.m_nMinX = 120;
  args.m_nMinY = 18;
  args.m_flExpandFactor = 0.0;
  args.m_bMinorExpand = false;
  args.m_nPadding = 2;
  vgui::CSizerBase::InsertPanel(this: v9, nIndex: v30, pPanel: v16, &args);
  v17 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v17 != nullptr )
    v18 = vgui::Button::Button(
            this: v17,
            parent: this,
            panelName: "NextSeqButton",
            text: ">",
            pActionSignalTarget: this,
            pCmd: nullptr);
  else
    v18 = nullptr;
  this->m_pNextSeqButton = v18;
  v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v19 != nullptr )
    v20 = KeyValues::KeyValues(this: v19, setName: "OnNextSequence");
  else
    v20 = nullptr;
  this->m_pNextSeqButton->SetCommand(this: this->m_pNextSeqButton, a2: v20);
  vgui::CSizerBase::InsertPanel(
    this: v9,
    nIndex: v9->m_Members.m_Size,
    pPanel: this->m_pNextSeqButton,
    args: &buttonAddArgs);
  v21 = (vgui::MenuButton *)MemAlloc_Alloc(nSize: 0x214u);
  if ( v21 != nullptr )
    v22 = vgui::MenuButton::MenuButton(this: v21, parent: this, panelName: "SequenceSelection", text: "(Color)");
  else
    v22 = nullptr;
  this->m_pSequenceSelection_Second = v22;
  vgui::CSizerBase::InsertPanel(this: v9, nIndex: v9->m_Members.m_Size, pPanel: v22, args: &buttonAddArgs);
  v23 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v23 != nullptr )
    v24 = vgui::Slider::Slider(this: v23, parent: this, panelName: "SheetPreviewSpeed");
  else
    v24 = nullptr;
  this->m_pSheetPreviewSpeed = v24;
  v24->SetRange(this: v24, a2: 5, a3: 3000);
  this->m_pSheetPreviewSpeed->SetValue(this: this->m_pSheetPreviewSpeed, a2: 750, a3: true);
  this->m_pSheetPreviewSpeed->AddActionSignalTarget_2(this: this->m_pSheetPreviewSpeed, a2: this);
  m_pSheetPreviewSpeed = this->m_pSheetPreviewSpeed;
  v31 = v9->m_Members.m_Size;
  args.m_bIgnoreMemberMin = true;
  args.m_nMinX = 150;
  args.m_nMinY = 18;
  args.m_flExpandFactor = 0.0;
  args.m_bMinorExpand = false;
  args.m_nPadding = 2;
  vgui::CSizerBase::InsertPanel(this: v9, nIndex: v31, pPanel: m_pSheetPreviewSpeed, &args);
  v25 = (CSheetSequencePanel *)MemAlloc_Alloc(nSize: 0x438u);
  if ( v25 != nullptr )
    v26 = CSheetSequencePanel::CSheetSequencePanel(this: v25, pParent: this, pPanelName: "sheetpanel");
  else
    v26 = nullptr;
  this->m_pSheetPanel = v26;
  v26->AddActionSignalTarget_2(this: v26, a2: this);
  this->m_pSequenceSelection->SetMenu(this: this->m_pSequenceSelection, a2: this->m_pSheetPanel);
  v27 = (CSheetSequencePanel *)MemAlloc_Alloc(nSize: 0x438u);
  if ( v27 != nullptr )
    v28 = CSheetSequencePanel::CSheetSequencePanel(this: v27, pParent: this, pPanelName: "sheetpanel_second");
  else
    v28 = nullptr;
  this->m_pSheetPanel_Second = v28;
  CSheetSequencePanel::SetSecondSequenceView(this: v28, bIsSecondSequenceView: true);
  this->m_pSheetPanel_Second->AddActionSignalTarget_2(this: this->m_pSheetPanel_Second, a2: this);
  this->m_pSequenceSelection_Second->SetMenu(this: this->m_pSequenceSelection_Second, a2: this->m_pSheetPanel_Second);
  CVMTPreviewToolbar::UpdateToolbarGUI(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D5290
// Name: public: virtual struct vgui::PanelMessageMap __near * CVMTPreviewToolbar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVMTPreviewToolbar::GetMessageMap(CVMTPreviewToolbar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVMTPreviewToolbar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPreviewToolbar::GetMessageMap'::`2'::s_pMap;
  `CVMTPreviewToolbar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVMTPreviewToolbar");
  `CVMTPreviewToolbar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D52C0
// Name: public: virtual struct PanelAnimationMap __near * CVMTPreviewToolbar::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVMTPreviewToolbar::GetAnimMap(CVMTPreviewToolbar *this)
{
  return FindOrAddPanelAnimationMap(className: "CVMTPreviewToolbar");
}

//------------------------------------------------------------------------------
// Address: 0x004D52D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVMTPreviewToolbar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVMTPreviewToolbar::GetKBMap(CVMTPreviewToolbar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVMTPreviewToolbar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPreviewToolbar::GetKBMap'::`2'::s_pMap;
  `CVMTPreviewToolbar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPreviewToolbar");
  `CVMTPreviewToolbar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D5300
// Name: public: CVMTPicker::CVMTPicker(class vgui::Panel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CVMTPicker *__thiscall CVMTPicker::CVMTPicker(CVMTPicker *this, vgui::Panel *pParent, bool bAllowMultiselect)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Splitter *v7; // eax
  vgui::Splitter *v8; // eax
  vgui::Panel *Child; // edi
  vgui::Splitter *v10; // eax
  vgui::Splitter *v11; // eax
  vgui::Panel *v12; // edi
  vgui::Panel *v13; // ebx
  CVMTPreviewPanel *v14; // eax
  CVMTPreviewPanel *v15; // eax
  CVMTPreviewPanel *v16; // eax
  CVMTPreviewPanel *v17; // eax
  CVMTPreviewToolbar *v18; // eax
  CVMTPreviewToolbar *v19; // eax
  vgui::Panel *pSplitterLeftSide; // [esp+14h] [ebp+8h]

  CBaseAssetPicker::CBaseAssetPicker(
    this,
    pParent,
    pAssetType: "VMT Files",
    pExt: "vmt",
    pSubDir: "materials",
    pTextType: "vmtName",
    pAssetSearchPath: "GAME");
  this->__vftable = (CVMTPicker_vtbl *)&CVMTPicker::`vftable';
  if ( `CVMTPicker::ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPicker::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CVMTPicker");
    v4->pfnClassName = CVMTPicker::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CVMTPicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVMTPicker::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CVMTPicker");
    v5->pfnClassName = CVMTPicker::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CVMTPicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPicker::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPicker");
    v6->pfnClassName = CVMTPicker::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  }
  v7 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v7 != nullptr )
    v8 = vgui::Splitter::Splitter(
           this: v7,
           parent: this,
           name: "PreviewSplitter",
           mode: SPLITTER_MODE_VERTICAL,
           nCount: 1);
  else
    v8 = nullptr;
  this->m_pPreviewSplitter = v8;
  pSplitterLeftSide = vgui::Panel::GetChild(this: v8, index: 0);
  Child = vgui::Panel::GetChild(this: this->m_pPreviewSplitter, index: 1);
  v10 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v10 != nullptr )
    v11 = vgui::Splitter::Splitter(
            this: v10,
            parent: Child,
            name: "2D3DSplitter",
            mode: SPLITTER_MODE_HORIZONTAL,
            nCount: 1);
  else
    v11 = nullptr;
  this->m_p2D3DSplitter = v11;
  v12 = vgui::Panel::GetChild(this: v11, index: 0);
  v13 = vgui::Panel::GetChild(this: this->m_p2D3DSplitter, index: 1);
  v14 = (CVMTPreviewPanel *)MemAlloc_Alloc(nSize: 0x1A8u);
  if ( v14 != nullptr )
    v15 = CVMTPreviewPanel::CVMTPreviewPanel(this: v14, pParent: v12, pName: "VMTPreview2D");
  else
    v15 = nullptr;
  this->m_pVMTPreview2D = v15;
  v16 = (CVMTPreviewPanel *)MemAlloc_Alloc(nSize: 0x1A8u);
  if ( v16 != nullptr )
    v17 = CVMTPreviewPanel::CVMTPreviewPanel(this: v16, pParent: v13, pName: "VMTPreview3D");
  else
    v17 = nullptr;
  this->m_pVMTPreview3D = v17;
  CVMTPreviewPanel::DrawIn3DMode(this: v17, b3DMode: true);
  v18 = (CVMTPreviewToolbar *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v18 != nullptr )
    v19 = CVMTPreviewToolbar::CVMTPreviewToolbar(
            this: v18,
            parent: v13,
            panelName: "PreviewToolbar",
            parentpicker: this);
  else
    v19 = nullptr;
  this->m_pVMTPreviewToolbar = v19;
  CBaseAssetPicker::CreateStandardControls(this, pParent: pSplitterLeftSide, bAllowMultiselect);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(this, dialogResourceName: "resource/vmtpicker.res", dialogID: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D5500
// Name: public: CVMTPickerFrame::CVMTPickerFrame(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CVMTPickerFrame *__thiscall CVMTPickerFrame::CVMTPickerFrame(
        CVMTPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle,
        bool bAllowMultiselect)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  CVMTPicker *v8; // eax
  CVMTPicker *v9; // eax

  CBaseAssetPickerFrame::CBaseAssetPickerFrame(this, pParent);
  this->__vftable = (CVMTPickerFrame_vtbl *)&CVMTPickerFrame::`vftable';
  if ( `CVMTPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPickerFrame::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CVMTPickerFrame");
    v5->pfnClassName = CVMTPickerFrame::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CVMTPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVMTPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CVMTPickerFrame");
    v6->pfnClassName = CVMTPickerFrame::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPickerFrame");
  }
  if ( `CVMTPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVMTPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPickerFrame");
    v7->pfnClassName = CVMTPickerFrame::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPickerFrame");
  }
  v8 = (CVMTPicker *)MemAlloc_Alloc(nSize: 0x258u);
  if ( v8 != nullptr )
    v9 = CVMTPicker::CVMTPicker(this: v8, pParent: this, bAllowMultiselect);
  else
    v9 = nullptr;
  CBaseAssetPickerFrame::SetAssetPicker(this, pPicker: v9);
  vgui::EditablePanel::LoadControlSettingsAndUserConfig(
    this,
    dialogResourceName: "resource/vmtpickerframe.res",
    dialogID: 0);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D5600
// Name: public: virtual struct vgui::PanelMessageMap __near * CVMTPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVMTPickerFrame::GetMessageMap(CVMTPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVMTPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CVMTPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVMTPickerFrame");
  `CVMTPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D5630
// Name: public: virtual struct PanelAnimationMap __near * CVMTPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVMTPickerFrame::GetAnimMap(CVMTPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CVMTPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004D5640
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVMTPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVMTPickerFrame::GetKBMap(CVMTPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVMTPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVMTPickerFrame::GetKBMap'::`2'::s_pMap;
  `CVMTPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVMTPickerFrame");
  `CVMTPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace sceneviewer
