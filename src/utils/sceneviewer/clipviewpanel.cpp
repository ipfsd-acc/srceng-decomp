// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/sceneviewer/clipviewpanel.cpp
// Functions: 86
// ============================================================

#include "utils\sceneviewer\clipviewpanel.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: public: static char const __near * CClipViewPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CClipViewPanel::GetPanelClassName()
{
  return "CClipViewPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00401010
// Name: public: static char const __near * CDmeEditPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CDmeEditPanel::GetPanelClassName()
{
  return "CDmeEditPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00401020
// Name: protected: virtual void CDmeEditPanel::OnCommandSubmitted(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditPanel::OnCommandSubmitted(vgui::CConsoleDialog *this, const char *pCommand)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "CommandSubmitted", firstKey: "command", firstValue: pCommand);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401070
// Name: public: virtual void CDmeEditPanel::NotifyDataChanged(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditPanel::NotifyDataChanged(
        CDmeEditPanel *this,
        const char *pReason,
        const char *nNotifySource,
        int nNotifyFlags)
{
  (*(void (__thiscall **)(vgui::Panel::NAV_DIRECTION, int, int))(*(_DWORD *)this->m_LastNavDirection + 948))(
    a1: this->m_LastNavDirection,
    a2: 2,
    a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004010A0
// Name: public: virtual unsigned long vgui::Panel::GetDragFailCursor(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::Panel::GetDragFailCursor(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  return 13;
}

//------------------------------------------------------------------------------
// Address: 0x004010B0
// Name: public: virtual void CClipViewPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipViewPanel::ApplySchemeSettings(CClipViewPanel *this, vgui::IScheme *pScheme)
{
  CClipViewPanel_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "MenuBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004010F0
// Name: public: void CClipViewPanel::SetScene(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipViewPanel::SetScene(CClipViewPanel *this, CDmElement *pDmRoot)
{
  this->m_pClipViewPreview->SetScene(this: this->m_pClipViewPreview, a2: pDmRoot);
}

//------------------------------------------------------------------------------
// Address: 0x00401110
// Name: public: class CDmeDag __near * CClipViewPanel::GetScene(void)
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CClipViewPanel::GetScene(CClipViewPanel *this)
{
  return CDmeDagEditPanel::GetDmeElement(this: this->m_pClipViewPreview);
}

//------------------------------------------------------------------------------
// Address: 0x00401120
// Name: public: void CClipViewPanel::SetAnimationList(class CDmeAnimationList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipViewPanel::SetAnimationList(CClipViewPanel *this, CDmeAnimationList *pAnimationList)
{
  CDmeDagEditPanel::SetAnimationList(this: this->m_pClipViewPreview, pAnimationList);
}

//------------------------------------------------------------------------------
// Address: 0x00401130
// Name: public: void CClipViewPanel::SetVertexAnimationList(class CDmeAnimationList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipViewPanel::SetVertexAnimationList(CClipViewPanel *this, CDmeAnimationList *pAnimationList)
{
  CDmeDagEditPanel::SetVertexAnimationList(this: this->m_pClipViewPreview, pAnimationList);
}

//------------------------------------------------------------------------------
// Address: 0x00401140
// Name: public: void CClipViewPanel::SetCombinationOperator(class CDmeCombinationOperator __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipViewPanel::SetCombinationOperator(CClipViewPanel *this, CDmeCombinationOperator *pComboOp)
{
  CDmeDagEditPanel::SetCombinationOperator(this: this->m_pClipViewPreview, pComboOp);
}

//------------------------------------------------------------------------------
// Address: 0x00401150
// Name: public: void CClipViewPanel::RefreshCombinationOperator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipViewPanel::RefreshCombinationOperator(CClipViewPanel *this)
{
  CDmeDagEditPanel::RefreshCombinationOperator(this: this->m_pClipViewPreview);
}

//------------------------------------------------------------------------------
// Address: 0x00401160
// Name: public: virtual void CClipViewPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClipViewPanel::PerformLayout(CClipViewPanel *this)
{
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int w; // [esp+Ch] [ebp-8h] BYREF
  int h; // [esp+10h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  this->GetClientArea(this, a2: &x, a3: &y, a4: &w, a5: &h);
  vgui::Panel::SetBounds(this: this->m_pClipViewPreview, x, y, wide: w, tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x004011B0
// Name: public: virtual bool vgui::Panel::IsProportional(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall vgui::Panel::IsProportional(vgui::Panel *this)
{
  return (this->_flags.m_nFlags & 0x1000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004011C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CClipViewPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CClipViewPanel::GetMessageMap(CClipViewPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CClipViewPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CClipViewPanel::GetMessageMap'::`2'::s_pMap;
  `CClipViewPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CClipViewPanel");
  `CClipViewPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004011F0
// Name: public: virtual struct PanelAnimationMap __near * CClipViewPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CClipViewPanel::GetAnimMap(CClipViewPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CClipViewPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00401200
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CClipViewPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CClipViewPanel::GetKBMap(CClipViewPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CClipViewPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CClipViewPanel::GetKBMap'::`2'::s_pMap;
  `CClipViewPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CClipViewPanel");
  `CClipViewPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401260
// Name: public: void CUtlMemory<struct vgui::MessageMapItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<vgui::MessageMapItem_t,int>::Grow(CUtlMemory<VMatrix,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  VMatrix *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = m_nAllocationCount << 6;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (VMatrix *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (VMatrix *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004012F0
// Name: public: enum DmElementHandle_t const __near & CDmAttribute::GetValue<enum DmElementHandle_t>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<enum DmElementHandle_t> *__thiscall CDmAttribute::GetValue<enum DmElementHandle_t>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  if ( (this->m_nFlags & 0x1F) == 1 )
    return (CDmaVar<enum DmElementHandle_t> *)this->m_pData;
  if ( !CDmAttribute::IsTypeConvertable<enum DmElementHandle_t>(this) )
    return &`CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  CDmAttribute::CopyDataOut<enum DmElementHandle_t>(
    this,
    value: &`CDmAttribute::GetValue<enum DmElementHandle_t>'::`7'::tempVal);
  return (CDmaVar<enum DmElementHandle_t> *)&`CDmAttribute::GetValue<enum DmElementHandle_t>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x004013C0
// Name: public: enum DmElementHandle_t const __near & CDmElement::GetValue<enum DmElementHandle_t>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<enum DmElementHandle_t> *__thiscall CDmElement::GetValue<enum DmElementHandle_t>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    return &`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004014A0
// Name: public: static void CClipViewPanel::PanelMessageFunc_OnCommandSubmitted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CClipViewPanel::PanelMessageFunc_OnCommandSubmitted::InitVar(int a1@<ebp>)
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
  if ( !`CClipViewPanel::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded )
  {
    `CClipViewPanel::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CClipViewPanel");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CommandSubmitted";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "command";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401540
// Name: public: static void CDmeEditPanel::PanelMessageFunc_OnCommandSubmitted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CDmeEditPanel::PanelMessageFunc_OnCommandSubmitted::InitVar(int a1@<ebp>)
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
  if ( !`CDmeEditPanel::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded )
  {
    `CDmeEditPanel::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CDmeEditPanel");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CommandSubmitted";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "command";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004015E0
// Name: public: CDmeEditPanel::CDmeEditPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeEditPanel *__thiscall CDmeEditPanel::CDmeEditPanel(CDmeEditPanel *this, vgui::Panel *pParent, vgui::Panel *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Splitter *v7; // edi
  vgui::Panel *Child; // eax
  vgui::Splitter *v9; // eax
  vgui::Panel *v10; // edi
  vgui::CConsolePanel *v11; // eax
  vgui::CConsolePanel *v12; // eax
  vgui::PropertyPage *v13; // eax
  vgui::PropertyPage *v14; // eax
  CElementPropertiesTreeInternal *v15; // eax
  CElementPropertiesTreeInternal *v16; // eax
  float flSplitters[2]; // [esp+Ch] [ebp-8h] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF
  vgui::Panel *pSplitterBottomLeft; // [esp+20h] [ebp+Ch]

  CDmeDagEditPanel::CDmeDagEditPanel(this, pParent, (const char *)pName);
  this->IDmNotify::__vftable = (IDmNotify_vtbl *)&IDmNotify::`vftable';
  this->CDmeDagEditPanel::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CDmeEditPanel_vtbl *)&CDmeEditPanel::`vftable'{for `CDmeDagEditPanel'};
  this->IDmNotify::__vftable = (IDmNotify_vtbl *)&CDmeEditPanel::`vftable'{for `IDmNotify'};
  if ( `CDmeEditPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CDmeEditPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CDmeEditPanel");
    v4->pfnClassName = CDmeEditPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CDmeDagEditPanel");
  }
  if ( `CDmeEditPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CDmeEditPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CDmeEditPanel");
    v5->pfnClassName = CDmeEditPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CDmeDagEditPanel");
  }
  if ( `CDmeEditPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CDmeEditPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeEditPanel");
    v6->pfnClassName = CDmeEditPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeDagEditPanel");
  }
  CDmeEditPanel::PanelMessageFunc_OnCommandSubmitted::InitVar(a1: (int)&savedregs);
  v7 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v7 != nullptr )
  {
    Child = vgui::Panel::GetChild(this: this->m_pPropertiesSplitter, index: 0);
    v9 = vgui::Splitter::Splitter(
           this: v7,
           parent: Child,
           name: "LeftSplitter",
           mode: SPLITTER_MODE_HORIZONTAL,
           nCount: 1);
  }
  else
  {
    v9 = nullptr;
  }
  this->m_pLeftSplitter = v9;
  vgui::Panel::SetAutoResize(
    this: v9,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  v10 = vgui::Panel::GetChild(this: this->m_pLeftSplitter, index: 0);
  pSplitterBottomLeft = vgui::Panel::GetChild(this: this->m_pLeftSplitter, index: 1);
  this->m_pEditorSheet->SetParent_2(this: this->m_pEditorSheet, a2: v10);
  v11 = (vgui::CConsolePanel *)MemAlloc_Alloc(nSize: 0x3D0u);
  if ( v11 != nullptr )
    v12 = vgui::CConsolePanel::CConsolePanel(
            this: v11,
            pParent: pSplitterBottomLeft,
            pName: "Console",
            bStatusVersion: false);
  else
    v12 = nullptr;
  this->m_pConsole = v12;
  vgui::Panel::SetAutoResize(
    this: v12,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  this->m_pConsole->AddActionSignalTarget_2(this: this->m_pConsole, a2: this);
  v13 = (vgui::PropertyPage *)MemAlloc_Alloc(nSize: 0x188u);
  if ( v13 != nullptr )
    v14 = vgui::PropertyPage::PropertyPage(this: v13, parent: this->m_pEditorSheet, panelName: "NerdEditorPage");
  else
    v14 = nullptr;
  this->m_pNerdEditorPage = v14;
  vgui::Panel::SetPos(this: v14, x: 6, y: 6);
  vgui::Panel::SetSize(this: this->m_pNerdEditorPage, wide: 256, tall: 256);
  this->m_pNerdEditorPage->SetEnabled(this: this->m_pNerdEditorPage, a2: true);
  vgui::Panel::SetAutoResize(
    this: this->m_pNerdEditorPage,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_NO,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  v15 = (CElementPropertiesTreeInternal *)MemAlloc_Alloc(nSize: 0x2BCu);
  if ( v15 != nullptr )
    v16 = CElementPropertiesTreeInternal::CElementPropertiesTreeInternal(
            this: v15,
            parent: this->m_pNerdEditorPage,
            pNotify: &this->IDmNotify,
            pObject: nullptr,
            autoApply: true,
            pDict: nullptr);
  else
    v16 = nullptr;
  this->m_pNerdEditor = v16;
  v16->AddActionSignalTarget_2(this: v16, a2: this);
  vgui::Panel::SetPos(this: this->m_pNerdEditor, x: 6, y: 6);
  vgui::Panel::SetSize(this: this->m_pNerdEditor, wide: 256, tall: 256);
  this->m_pNerdEditor->SetEnabled(this: this->m_pNerdEditor, a2: true);
  vgui::Panel::SetAutoResize(
    this: this->m_pNerdEditor,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 6,
    nPinOffsetY: 6,
    nUnpinnedCornerOffsetX: -6,
    nUnpinnedCornerOffsetY: -6);
  this->m_pEditorSheet->RemoveAllPages(this: this->m_pEditorSheet);
  this->m_pEditorSheet->AddPage(
    this: this->m_pEditorSheet,
    a2: this->m_pNerdEditorPage,
    a3: "Element Viewer",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pEditorSheet->AddPage(
    this: this->m_pEditorSheet,
    a2: this->m_pCombinationPage,
    a3: "Combination",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pEditorSheet->AddPage(
    this: this->m_pEditorSheet,
    a2: this->m_pAnimationPage,
    a3: "Animation",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pEditorSheet->AddPage(
    this: this->m_pEditorSheet,
    a2: this->m_pVertexAnimationPage,
    a3: "Vertex Animation",
    a4: nullptr,
    a5: false,
    a6: -1);
  this->m_pEditorSheet->SetActivePage(this: this->m_pEditorSheet, a2: this->m_pNerdEditorPage);
  flSplitters[0] = 0.80000001;
  flSplitters[1] = 0.2;
  vgui::Splitter::RespaceSplitters(this: this->m_pLeftSplitter, flFractions: flSplitters);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 444))(
    a1: g_pDataModel.u,
    a2: &this->IDmNotify);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401980
// Name: public: virtual struct vgui::PanelMessageMap __near * CDmeEditPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CDmeEditPanel::GetMessageMap(CDmeEditPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CDmeEditPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeEditPanel::GetMessageMap'::`2'::s_pMap;
  `CDmeEditPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CDmeEditPanel");
  `CDmeEditPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004019B0
// Name: public: virtual struct PanelAnimationMap __near * CDmeEditPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CDmeEditPanel::GetAnimMap(CDmeEditPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CDmeEditPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004019C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CDmeEditPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CDmeEditPanel::GetKBMap(CDmeEditPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CDmeEditPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CDmeEditPanel::GetKBMap'::`2'::s_pMap;
  `CDmeEditPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CDmeEditPanel");
  `CDmeEditPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401A20
// Name: public: virtual void CDmeEditPanel::SetScene(class CDmElement __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeEditPanel::SetScene(CDmeEditPanel *this, CDmElement *pDmRoot)
{
  CDmeDag *Value; // eax

  this->m_pNerdEditor->SetObject(this: this->m_pNerdEditor, a2: pDmRoot);
  Value = nullptr;
  if ( pDmRoot != nullptr )
  {
    Value = CDmElement::GetValueElement<CDmeDag>(this: pDmRoot, pAttributeName: "model");
    if ( Value == nullptr )
      Value = CDmElement::GetValueElement<CDmeDag>(this: pDmRoot, pAttributeName: "skeleton");
  }
  this->SetDmeElement(this, a2: Value);
}

//------------------------------------------------------------------------------
// Address: 0x00401A70
// Name: public: CClipViewPanel::CClipViewPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CClipViewPanel *__thiscall CClipViewPanel::CClipViewPanel(
        CClipViewPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CDmeEditPanel *v7; // eax
  CDmeEditPanel *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent: pParent, panelName: pName, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CClipViewPanel_vtbl *)&CClipViewPanel::`vftable';
  if ( `CClipViewPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CClipViewPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CClipViewPanel");
    v4->pfnClassName = CClipViewPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CClipViewPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CClipViewPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CClipViewPanel");
    v5->pfnClassName = CClipViewPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CClipViewPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CClipViewPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CClipViewPanel");
    v6->pfnClassName = CClipViewPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CClipViewPanel::PanelMessageFunc_OnCommandSubmitted::InitVar(a1: (int)&savedregs);
  v7 = (CDmeEditPanel *)MemAlloc_Alloc(nSize: 0x1C0u);
  if ( v7 != nullptr )
    v8 = CDmeEditPanel::CDmeEditPanel(this: v7, pParent: this, pName: (vgui::Panel *)"ClipViewPreview");
  else
    v8 = nullptr;
  this->m_pClipViewPreview = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  vgui::Panel::SetVisible(this, state: true);
  vgui::Frame::SetMinimizeButtonVisible(this, state: false);
  vgui::Frame::SetMaximizeButtonVisible(this, state: false);
  vgui::Frame::SetMinimizeToSysTrayButtonVisible(this, state: false);
  vgui::Frame::SetCloseButtonVisible(this, state: false);
  vgui::Frame::SetTitle(this, title: "3d View", surfaceTitle: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401BB0
// Name: void __near * MemAlloc_Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_Alloc(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x0040CB80
// Name: private: void CDmAttribute::CopyDataOut<class DmeTime_t>(class DmeTime_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAttribute::CopyDataOut<DmeTime_t>(CDmAttribute *this, DmeTime_t *value)
{
  switch ( this->m_nFlags & 0x1F )
  {
    case 2:
      value->m_tms = *(int *)this->m_pData;
      break;
    case 3:
      value->m_tms = DmeTime_t::RoundSecondsToTMS(sec: *(float *)this->m_pData);
      break;
    case 4:
      if ( *(_BYTE *)this->m_pData != 0 )
        value->m_tms = DmeTime_t::RoundSecondsToTMS(sec: 1.0);
      else
        value->m_tms = 0;
      break;
    case 7:
      value->m_tms = *(int *)this->m_pData;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CC40
// Name: private: void CDmAttribute::CopyData<class QAngle>(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAttribute::CopyData<QAngle>(CDmAttribute *this, const QAngle *value)
{
  Quaternion qValue; // [esp+4h] [ebp-10h] BYREF

  if ( (this->m_nFlags & 0x1F) == 0xC )
  {
    *(QAngle *)this->m_pData = *value;
  }
  else if ( (this->m_nFlags & 0x1F) == 0xD )
  {
    AngleQuaternion(angles: value, outQuat: &qValue);
    *(Quaternion *)this->m_pData = qValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D200
// Name: private: bool CDmAttribute::IsTypeConvertable<class CUtlSymbolLarge>(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::IsTypeConvertable<CUtlSymbolLarge>(CDmAttribute *this)
{
  return (this->m_nFlags & 0x1F) == 5;
}

//------------------------------------------------------------------------------
// Address: 0x0040D210
// Name: public: class DmeTime_t const __near & CDmAttribute::GetValue<class DmeTime_t>(class DmeTime_t const __near &)const
// Source: json
//------------------------------------------------------------------------------
const DmeTime_t *__thiscall CDmAttribute::GetValue<DmeTime_t>(CDmAttribute *this, const DmeTime_t *defaultValue)
{
  unsigned __int16 m_nFlags; // ax
  int v4; // eax

  m_nFlags = this->m_nFlags;
  if ( (m_nFlags & 0x1F) == 7 )
    return (const DmeTime_t *)this->m_pData;
  v4 = m_nFlags & 0x1F;
  if ( v4 != 7 && v4 != 3 && v4 != 2 && v4 != 4 )
    return defaultValue;
  if ( (`CDmAttribute::GetValue<DmeTime_t>'::`7'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<DmeTime_t>'::`7'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<DmeTime_t>'::`7'::tempVal.m_tms = 0x80000000;
  }
  CDmAttribute::CopyDataOut<DmeTime_t>(this, value: &`CDmAttribute::GetValue<DmeTime_t>'::`7'::tempVal);
  return &`CDmAttribute::GetValue<DmeTime_t>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x0040D280
// Name: public: class QAngle const __near & CDmAttribute::GetValue<class QAngle>(class QAngle const __near &)const
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CDmAttribute::GetValue<QAngle>(CDmAttribute *this, const QAngle *defaultValue)
{
  unsigned __int16 m_nFlags; // ax
  int v4; // eax

  m_nFlags = this->m_nFlags;
  if ( (m_nFlags & 0x1F) == 0xC )
    return (const QAngle *)this->m_pData;
  v4 = m_nFlags & 0x1F;
  if ( v4 != 12 && v4 != 13 )
    return defaultValue;
  if ( (`CDmAttribute::GetValue<QAngle>'::`7'::`local static guard' & 1) == 0 )
    `CDmAttribute::GetValue<QAngle>'::`7'::`local static guard' |= 1u;
  if ( (this->m_nFlags & 0x1F) == 0xC )
  {
    `CDmAttribute::GetValue<QAngle>'::`7'::tempVal = *(QAngle *)this->m_pData;
  }
  else if ( (this->m_nFlags & 0x1F) == 0xD )
  {
    QuaternionAngles(q: (const Quaternion *)this->m_pData, angles: &`CDmAttribute::GetValue<QAngle>'::`7'::tempVal);
    return &`CDmAttribute::GetValue<QAngle>'::`7'::tempVal;
  }
  return &`CDmAttribute::GetValue<QAngle>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x0040D320
// Name: public: class Quaternion const __near & CDmAttribute::GetValue<class Quaternion>(class Quaternion const __near &)const
// Source: json
//------------------------------------------------------------------------------
const Quaternion *__thiscall CDmAttribute::GetValue<Quaternion>(CDmAttribute *this, const Quaternion *defaultValue)
{
  unsigned __int16 m_nFlags; // ax
  int v4; // eax

  m_nFlags = this->m_nFlags;
  if ( (m_nFlags & 0x1F) == 0xD )
    return (const Quaternion *)this->m_pData;
  v4 = m_nFlags & 0x1F;
  if ( v4 != 13 && v4 != 12 )
    return defaultValue;
  if ( (`CDmAttribute::GetValue<Quaternion>'::`7'::`local static guard' & 1) == 0 )
    `CDmAttribute::GetValue<Quaternion>'::`7'::`local static guard' |= 1u;
  if ( (this->m_nFlags & 0x1F) == 0xC )
  {
    AngleQuaternion(angles: (const QAngle *)this->m_pData, outQuat: &`CDmAttribute::GetValue<Quaternion>'::`7'::tempVal);
  }
  else if ( (this->m_nFlags & 0x1F) == 0xD )
  {
    `CDmAttribute::GetValue<Quaternion>'::`7'::tempVal = *(Quaternion *)this->m_pData;
    return &`CDmAttribute::GetValue<Quaternion>'::`7'::tempVal;
  }
  return &`CDmAttribute::GetValue<Quaternion>'::`7'::tempVal;
}

//------------------------------------------------------------------------------
// Address: 0x0040F0F0
// Name: public: class DmeTime_t const __near & CDmAttribute::GetValue<class DmeTime_t>(void)const
// Source: json
//------------------------------------------------------------------------------
const DmeTime_t *__thiscall CDmAttribute::GetValue<DmeTime_t>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<DmeTime_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<DmeTime_t>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<DmeTime_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<DmeTime_t>'::`2'::defaultVal.m_Storage.m_tms = 0;
  }
  return CDmAttribute::GetValue<DmeTime_t>(
           this,
           defaultValue: &`CDmAttribute::GetValue<DmeTime_t>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x0040F640
// Name: public: class CUtlSymbolLarge const __near & CDmAttribute::GetValue<class CUtlSymbolLarge>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlSymbolLarge> *__thiscall CDmAttribute::GetValue<CUtlSymbolLarge>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_Storage.u.m_Id = -1;
  }
  if ( (this->m_nFlags & 0x1F) == 5 )
    return (CDmaVar<CUtlSymbolLarge> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0040F960
// Name: public: class CDmElement __near * CDmAttribute::GetValueElement<class CDmElement>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmAttribute::GetValueElement<CDmElement>(CDmAttribute *this)
{
  _DWORD *v1; // eax
  int v2; // eax
  int v3; // esi

  if ( (this->m_nFlags & 0x1F) != 1 )
    return nullptr;
  if ( (`CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  v1 = (this->m_nFlags & 0x1F) == 1 ? this->m_pData : &`CDmAttribute::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: *v1);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return (CDmElement *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004103B0
// Name: private: bool CDmAttribute::ShouldModify<class CUtlSymbolLarge>(class CUtlSymbolLarge const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::ShouldModify<CUtlSymbolLarge>(CDmAttribute *this, const CUtlSymbolLarge *value)
{
  _DWORD *v3; // eax

  if ( (this->m_nFlags & 0x1F) != 5 )
    return false;
  if ( (`CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_Storage.u.m_Id = -1;
  }
  v3 = (this->m_nFlags & 0x1F) == 5 ? this->m_pData : &`CDmAttribute::GetValue<CUtlSymbolLarge>'::`2'::defaultVal;
  return *v3 != value->u.m_Id && CDmAttribute::MarkDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x00410470
// Name: private: bool CDmAttribute::ShouldModify<class DmeTime_t>(class DmeTime_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::ShouldModify<DmeTime_t>(CDmAttribute *this, const DmeTime_t *value)
{
  unsigned __int16 m_nFlags; // cx
  int v4; // eax

  m_nFlags = this->m_nFlags;
  v4 = m_nFlags & 0x1F;
  if ( v4 != 7 && v4 != 3 && v4 != 2 && v4 != 4 )
    return false;
  if ( (m_nFlags & 0x1F) != 7 )
    return CDmAttribute::MarkDirty(this);
  if ( (`CDmAttribute::GetValue<DmeTime_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<DmeTime_t>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<DmeTime_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<DmeTime_t>'::`2'::defaultVal.m_Storage.m_tms = 0;
  }
  return CDmAttribute::GetValue<DmeTime_t>(
           this,
           defaultValue: &`CDmAttribute::GetValue<DmeTime_t>'::`2'::defaultVal.m_Storage)->m_tms != value->m_tms
      && CDmAttribute::MarkDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x00410560
// Name: public: class QAngle const __near & CDmAttribute::GetValue<class QAngle>(void)const
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall CDmAttribute::GetValue<QAngle>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<QAngle>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<QAngle>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  return CDmAttribute::GetValue<QAngle>(
           this,
           defaultValue: &`CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x004105B0
// Name: private: bool CDmAttribute::ShouldModify<class QAngle>(class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::ShouldModify<QAngle>(CDmAttribute *this, const QAngle *value)
{
  unsigned __int16 m_nFlags; // cx
  int v4; // eax
  const QAngle *v6; // eax

  m_nFlags = this->m_nFlags;
  v4 = m_nFlags & 0x1F;
  if ( v4 != 12 && v4 != 13 )
    return false;
  if ( (m_nFlags & 0x1F) != 0xC )
    return CDmAttribute::MarkDirty(this);
  if ( (`CDmAttribute::GetValue<QAngle>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<QAngle>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  v6 = CDmAttribute::GetValue<QAngle>(this, defaultValue: &`CDmAttribute::GetValue<QAngle>'::`2'::defaultVal.m_Storage);
  return (value->x != v6->x || value->y != v6->y || value->z != v6->z) && CDmAttribute::MarkDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x00410660
// Name: public: class Quaternion const __near & CDmAttribute::GetValue<class Quaternion>(void)const
// Source: json
//------------------------------------------------------------------------------
const Quaternion *__thiscall CDmAttribute::GetValue<Quaternion>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Quaternion>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Quaternion>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.z = 0.0;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.w = 1.0;
  }
  return CDmAttribute::GetValue<Quaternion>(
           this,
           defaultValue: &`CDmAttribute::GetValue<Quaternion>'::`2'::defaultVal.m_Storage);
}

//------------------------------------------------------------------------------
// Address: 0x004106C0
// Name: public: class Color const __near & CDmAttribute::GetValue<class Color>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Color> *__thiscall CDmAttribute::GetValue<Color>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Color>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Color>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Color>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Color>'::`2'::defaultVal.m_Storage = (Color)-16777216;
  }
  if ( (this->m_nFlags & 0x1F) == 8 )
    return (CDmaVar<Color> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<Color>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00410700
// Name: public: class Vector2D const __near & CDmAttribute::GetValue<class Vector2D>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector2D> *__thiscall CDmAttribute::GetValue<Vector2D>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Vector2D>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Vector2D>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_Storage.y = 0.0;
  }
  if ( (this->m_nFlags & 0x1F) == 9 )
    return (CDmaVar<Vector2D> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00410750
// Name: public: class Vector const __near & CDmAttribute::GetValue<class Vector>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmAttribute::GetValue<Vector>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Vector>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  if ( (this->m_nFlags & 0x1F) == 0xA )
    return (CDmaVar<Vector> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<Vector>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004107A0
// Name: public: class Vector4D const __near & CDmAttribute::GetValue<class Vector4D>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector4D> *__thiscall CDmAttribute::GetValue<Vector4D>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<Vector4D>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Vector4D>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_Storage.z = 0.0;
    `CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal.m_Storage.w = 0.0;
  }
  if ( (this->m_nFlags & 0x1F) == 0xB )
    return (CDmaVar<Vector4D> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<Vector4D>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00410800
// Name: public: class VMatrix const __near & CDmAttribute::GetValue<class VMatrix>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<VMatrix> *__thiscall CDmAttribute::GetValue<VMatrix>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<VMatrix>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<VMatrix>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal.m_pAttribute = nullptr;
    MatrixSetIdentity(dst: &`CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal.m_Storage);
  }
  if ( (this->m_nFlags & 0x1F) == 0xE )
    return (CDmaVar<VMatrix> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00417750
// Name: private: bool CDmAttribute::ShouldModify<class Vector2D>(class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::ShouldModify<Vector2D>(CDmAttribute *this, const Vector2D *value)
{
  CDmaVar<Vector2D> *m_pData; // edx

  if ( (this->m_nFlags & 0x1F) != 9 )
    return false;
  if ( (`CDmAttribute::GetValue<Vector2D>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<Vector2D>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal.m_Storage.y = 0.0;
  }
  if ( (this->m_nFlags & 0x1F) == 9 )
    m_pData = (CDmaVar<Vector2D> *)this->m_pData;
  else
    m_pData = &`CDmAttribute::GetValue<Vector2D>'::`2'::defaultVal;
  return (value->x != m_pData->m_Storage.x || value->y != m_pData->m_Storage.y) && CDmAttribute::MarkDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x004177E0
// Name: private: bool CDmAttribute::ShouldModify<class VMatrix>(class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmAttribute::ShouldModify<VMatrix>(CDmAttribute *this, const VMatrix *value)
{
  VMatrix *v4; // ecx

  if ( (this->m_nFlags & 0x1F) != 0xE )
    return false;
  if ( (`CDmAttribute::GetValue<VMatrix>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<VMatrix>'::`2'::`local static guard' |= 1u;
    `CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal.m_pAttribute = nullptr;
    MatrixSetIdentity(dst: &`CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal.m_Storage);
  }
  v4 = (VMatrix *)((this->m_nFlags & 0x1F) == 0xE ? this->m_pData : &`CDmAttribute::GetValue<VMatrix>'::`2'::defaultVal);
  return !VMatrix::operator==(this: v4, src: value) && CDmAttribute::MarkDirty(this);
}

//------------------------------------------------------------------------------
// Address: 0x00427470
// Name: public: class CUtlBinaryBlock const __near & CDmAttribute::GetValue<class CUtlBinaryBlock>(void)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlBinaryBlock> *__thiscall CDmAttribute::GetValue<CUtlBinaryBlock>(CDmAttribute *this)
{
  if ( (`CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::`local static guard' |= 1u;
    CUtlBinaryBlock::CUtlBinaryBlock(
      this: &`CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::defaultVal.m_Storage,
      growSize: 0,
      initSize: 0);
    `CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::defaultVal.m_pAttribute = nullptr;
    CUtlBinaryBlock::Set(
      this: &`CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::defaultVal.m_Storage,
      pValue: nullptr,
      nLen: 0);
    atexit(func: `CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::`dynamic atexit destructor for 'defaultVal'');
  }
  if ( (this->m_nFlags & 0x1F) == 6 )
    return (CDmaVar<CUtlBinaryBlock> *)this->m_pData;
  else
    return &`CDmAttribute::GetValue<CUtlBinaryBlock>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00433780
// Name: public: class CUtlBinaryBlock __near & CDmAttribute::BeginModifyValueInPlace<class CUtlBinaryBlock>(void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlBinaryBlock *__thiscall CDmAttribute::BeginModifyValueInPlace<CUtlBinaryBlock>(CDmAttribute *this, void **pHandle)
{
  CUndoAttributeSetValueElement<CUtlBinaryBlock> *v4; // eax

  *pHandle = nullptr;
  if ( (this->m_nFlags & 0x1F) != 6 )
    return nullptr;
  if ( (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmElement *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 240))(
         a1: g_pDataModel.u,
         a2: this->m_pOwner) != 0 )
  {
    v4 = (CUndoAttributeSetValueElement<CUtlBinaryBlock> *)MemAlloc_Alloc(nSize: 0x3Cu);
    if ( v4 != nullptr )
    {
      *pHandle = CUndoAttributeSetValueElement<CUtlBinaryBlock>::CUndoAttributeSetValueElement<CUtlBinaryBlock>(
                   this: v4,
                   pAttribute: this);
      return (CUtlBinaryBlock *)this->m_pData;
    }
    *pHandle = nullptr;
  }
  return (CUtlBinaryBlock *)this->m_pData;
}

//------------------------------------------------------------------------------
// Address: 0x004337F0
// Name: public: void CDmAttribute::EndModifyValueInPlace<class CUtlBinaryBlock>(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAttribute::EndModifyValueInPlace<CUtlBinaryBlock>(CDmAttribute *this, char *handle)
{
  CDmaVar<CUtlBinaryBlock> *v3; // eax
  int v4; // eax
  bool v5; // al

  if ( (this->m_nFlags & 0x1F) == 6 )
  {
    if ( handle != nullptr )
    {
      v3 = CDmAttribute::GetValue<CUtlBinaryBlock>(this);
      CUtlString::operator=(this: (CUtlString *)(handle + 44), src: (const CUtlString *)v3);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char *))(*(_DWORD *)g_pDataModel.u.m_Id + 300))(
        a1: g_pDataModel.u,
        a2: handle);
    }
    if ( (this->m_nFlags & 0x100) != 0 && CDmElement::AreOnChangedCallbacksEnabled(this: this->m_pOwner) )
      this->m_pOwner->OnAttributeChanged(this: this->m_pOwner, a2: this);
    v4 = this->m_nFlags & 0x1F;
    v5 = v4 == 1 || v4 == 15;
    g_pDataModelImp->m_UndoMgr.m_nNotifyFlags |= v5 ? 4096 : 0x2000;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045F100
// Name: protected: void CElementPropertiesTreeInternal::CollectSelectedElements<class CDmrElementArray<class CDmElement>>(class CDmrElementArray<class CDmElement> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CElementPropertiesTreeInternal::CollectSelectedElements<CDmrElementArray<CDmElement>>(
        CElementPropertiesTreeInternal *this,
        CDmrElementArray<CDmElement> *container)
{
  CElementTreeViewListControl *m_pTree; // ecx
  int m_Size; // ebx
  int v4; // eax
  int v5; // ecx
  KeyValues *v6; // edi
  int Int; // eax
  int v8; // eax
  CDmElement *v9; // esi
  const char *String; // eax
  CDmAttribute *Attribute; // eax
  CDmAttribute *v12; // esi
  unsigned __int16 m_nFlags; // cx
  int v14; // eax
  CDmaVar<enum DmElementHandle_t> *v15; // eax
  int v16; // eax
  CExpressionCalculator *v17; // esi
  int v18; // eax
  int v19; // eax
  CExpressionCalculator *v20; // esi
  int j; // edi
  int v22; // eax
  CExpressionCalculator *v23; // esi
  KeyValues **m_pMemory; // eax
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > selection; // [esp+Ch] [ebp-30h] BYREF
  CDmrElementArray<CDmElement> arrayAttr; // [esp+20h] [ebp-1Ch] BYREF
  int nSelected; // [esp+28h] [ebp-14h]
  int i; // [esp+2Ch] [ebp-10h]
  DmElementHandle_t BufferType; // [esp+30h] [ebp-Ch] BYREF
  DmElementHandle_t v30; // [esp+34h] [ebp-8h] BYREF
  DmElementHandle_t src; // [esp+38h] [ebp-4h] BYREF

  m_pTree = this->m_pTree;
  m_Size = 0;
  memset(&selection, 0, sizeof(selection));
  v4 = (int)m_pTree->GetTree(this: m_pTree);
  (*(void (__thiscall **)(int, CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *))(*(_DWORD *)v4 + 940))(
    a1: v4,
    a2: &selection);
  v5 = 0;
  nSelected = selection.m_Size;
  for ( i = 0; v5 < nSelected; i = v5 )
  {
    v6 = selection.m_Memory.m_pMemory[v5];
    if ( v6 != nullptr )
    {
      Int = KeyValues::GetInt(this: v6, keyName: "ownerelement", defaultValue: -1);
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
             a1: g_pDataModel.u,
             a2: Int);
      v9 = (CDmElement *)v8;
      if ( v8 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
             a1: v8,
             a2: CDmElement::m_classType.u) != 0 )
      {
        String = KeyValues::GetString(this: v6, keyName: "attributeName", defaultValue: defaultValue);
        Attribute = CDmElement::FindAttribute(this: v9, pAttributeName: String);
        v12 = Attribute;
        if ( Attribute != nullptr )
        {
          m_nFlags = Attribute->m_nFlags;
          v14 = m_nFlags & 0x1F;
          if ( v14 == 1 )
          {
            if ( (m_nFlags & 0x1F) == 1
              && (v15 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: v12),
                  v16 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                          a1: g_pDataModel.u,
                          a2: v15->m_Storage.m_Handle),
                  v17 = (CExpressionCalculator *)v16,
                  v16 != 0)
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v16 + 16))(
                   a1: v16,
                   a2: CDmElement::m_classType.u) != 0 )
            {
              src = CCodecBuffer_Block::GetBufferType(this: v17);
              CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
                this: container,
                &src);
            }
            else
            {
              src = DMELEMENT_HANDLE_INVALID;
              CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
                this: container,
                &src);
            }
          }
          else if ( v14 == 15 )
          {
            CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>::CDmaArrayConstBase<Color,CDmaDataExternal<CUtlVector<Color,CUtlMemory<Color,int>>>>(this: (CDmaArrayConstBase<DmeTime_t,CDmaDataExternal<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > > > *)&arrayAttr);
            if ( (v12->m_nFlags & 0x1F) == 0xF )
            {
              arrayAttr.m_pAttribute = v12;
              arrayAttr.m_pStorage = (DmElementArray_t *)v12->m_pData;
              m_Size = arrayAttr.m_pStorage->m_Size;
            }
            else
            {
              arrayAttr.m_pAttribute = nullptr;
              arrayAttr.m_pStorage = nullptr;
            }
            v18 = KeyValues::GetInt(this: v6, keyName: "arrayIndex", defaultValue: -1);
            if ( v18 < 0 )
            {
              for ( j = 0; j < m_Size; ++j )
              {
                v22 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                  + 72))(
                        a1: g_pDataModel.u,
                        a2: arrayAttr.m_pStorage->m_Memory.m_pMemory[j]);
                v23 = (CExpressionCalculator *)v22;
                if ( v22 != 0
                  && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v22 + 16))(
                       a1: v22,
                       a2: CDmElement::m_classType.u) != 0 )
                {
                  BufferType = CCodecBuffer_Block::GetBufferType(this: v23);
                }
                else
                {
                  BufferType = DMELEMENT_HANDLE_INVALID;
                }
                CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
                  this: container,
                  src: &BufferType);
              }
            }
            else
            {
              v19 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: arrayAttr.m_pStorage->m_Memory.m_pMemory[v18]);
              v20 = (CExpressionCalculator *)v19;
              if ( v19 != 0
                && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v19 + 16))(
                     a1: v19,
                     a2: CDmElement::m_classType.u) != 0 )
              {
                v30 = CCodecBuffer_Block::GetBufferType(this: v20);
                CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
                  this: container,
                  src: &v30);
              }
              else
              {
                v30 = DMELEMENT_HANDLE_INVALID;
                CDmaArrayBase<enum DmElementHandle_t,CDmaDataExternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
                  this: container,
                  src: &v30);
              }
            }
            m_Size = 0;
          }
        }
      }
    }
    v5 = i + 1;
  }
  m_pMemory = selection.m_Memory.m_pMemory;
  selection.m_Size = 0;
  if ( selection.m_Memory.m_nGrowSize >= 0 )
  {
    if ( selection.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: selection.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      selection.m_Memory.m_pMemory = nullptr;
    }
    selection.m_Memory.m_nAllocationCount = 0;
  }
  selection.m_pElements = m_pMemory;
  if ( selection.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0046CC40
// Name: public: virtual bool vgui::Panel::LookupElementBounds(char const __near *,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall vgui::Panel::LookupElementBounds(
        CBaseElementPropertiesChoices *this,
        const char *pChoiceListType,
        CDmElement *pElement,
        CDmElement *pAttributeName,
        bool bArrayElement,
        CUtlVector<ElementChoice_t,CUtlMemory<ElementChoice_t,int> > *list)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x005F6060
// Name: public: virtual class vgui::Panel __near * vgui::Panel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::HasHotkey(vgui::Panel *this, wchar_t key)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0060A8C0
// Name: public: virtual class vgui::Menu __near * vgui::Frame::GetSysMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::Frame::GetSysMenu(vgui::Frame *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax
  vgui::Panel *ChildByName; // edi
  vgui::Panel_vtbl *v5; // ebx
  bool v6; // al
  vgui::Panel *v7; // edi
  vgui::Panel_vtbl *v8; // ebx
  bool v9; // al
  vgui::Panel *v10; // edi
  vgui::Panel_vtbl *v11; // ebx
  bool v12; // al

  if ( this->_sysMenu != nullptr )
    return this->_sysMenu;
  v2 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v2 != nullptr )
    v3 = vgui::Menu::Menu(this: v2, parent: this, panelName: nullptr);
  else
    v3 = nullptr;
  this->_sysMenu = v3;
  v3->SetVisible(this: v3, a2: false);
  this->_sysMenu->AddActionSignalTarget_2(this: this->_sysMenu, a2: this);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Minimize",
    a3: "#SysMenu_Minimize",
    a4: "Minimize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Maximize",
    a3: "#SysMenu_Maximize",
    a4: "Maximize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Close",
    a3: "#SysMenu_Close",
    a4: "Close",
    a5: this,
    a6: nullptr);
  ChildByName = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Minimize", recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = ChildByName->__vftable;
    v6 = this->_minimizeButton->IsVisible(this: this->_minimizeButton);
    v5->SetEnabled(this: ChildByName, a2: v6);
  }
  v7 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Maximize", recurseDown: false);
  if ( v7 != nullptr )
  {
    v8 = v7->__vftable;
    v9 = this->_maximizeButton->IsVisible(this: this->_maximizeButton);
    v8->SetEnabled(this: v7, a2: v9);
  }
  v10 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Close", recurseDown: false);
  if ( v10 != nullptr )
  {
    v11 = v10->__vftable;
    v12 = this->_closeButton->IsVisible(this: this->_closeButton);
    v11->SetEnabled(this: v10, a2: v12);
  }
  return this->_sysMenu;
}

//------------------------------------------------------------------------------
// Address: 0x0060B330
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Panel::GetMessageMap(vgui::Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Panel::GetMessageMap'::`2'::s_pMap;
  `vgui::Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Panel");
  `vgui::Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0060B370
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::GetKBMap(vgui::Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Panel::GetKBMap'::`2'::s_pMap;
  `vgui::Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  `vgui::Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0060B3A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Frame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Frame::GetMessageMap(vgui::Frame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Frame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetMessageMap'::`2'::s_pMap;
  `vgui::Frame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Frame");
  `vgui::Frame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0060B3D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Frame::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Frame::GetAnimMap(vgui::Frame *this)
{
  return FindOrAddPanelAnimationMap(className: "Frame");
}

//------------------------------------------------------------------------------
// Address: 0x0060B3E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Frame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Frame::GetKBMap(vgui::Frame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Frame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetKBMap'::`2'::s_pMap;
  `vgui::Frame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  `vgui::Frame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0060D850
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetParent(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetParent(vgui::Panel *this)
{
  vgui::IPanel *v1; // esi
  vgui::IPanel_vtbl *v2; // edi
  int v3; // eax
  int v4; // esi
  vgui::IPanel *v5; // edi
  vgui::IPanel_vtbl *v6; // ebx
  const char *ControlsModuleName; // eax

  v1 = g_pVGuiPanel;
  if ( g_pVGuiPanel == nullptr )
    return nullptr;
  v2 = g_pVGuiPanel->__vftable;
  v3 = this->GetVPanel(this);
  v4 = v2->GetParent(this: v1, a2: v3);
  if ( v4 == 0 )
    return nullptr;
  v5 = g_pVGuiPanel;
  v6 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  return v6->GetPanel(this: v5, a2: v4, a3: ControlsModuleName);
}

//------------------------------------------------------------------------------
// Address: 0x0060DBE0
// Name: public: class vgui::Panel __near * vgui::Panel::FindSiblingByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindSiblingByName(vgui::Panel *this, const char *siblingName)
{
  vgui::Panel *result; // eax
  vgui::IPanel *v4; // edi
  vgui::IPanel_vtbl *v5; // esi
  unsigned int v6; // eax
  vgui::IPanel *v7; // edi
  vgui::IPanel_vtbl *v8; // esi
  int v9; // eax
  int v10; // eax
  vgui::IPanel *v11; // edi
  vgui::IPanel_vtbl *v12; // esi
  const char *ControlsModuleName; // eax
  int v14; // esi
  const char *v15; // eax
  int siblingCount; // [esp+4h] [ebp-Ch]
  unsigned int sibling; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  result = (vgui::Panel *)this->GetVParent(this);
  if ( result != nullptr )
  {
    v4 = g_pVGuiPanel;
    v5 = g_pVGuiPanel->__vftable;
    v6 = this->GetVParent(this);
    siblingCount = v5->GetChildCount(this: v4, a2: v6);
    i = 0;
    if ( siblingCount <= 0 )
    {
      return nullptr;
    }
    else
    {
      while ( 1 )
      {
        v7 = g_pVGuiPanel;
        v8 = g_pVGuiPanel->__vftable;
        v9 = ((int (__thiscall *)(vgui::Panel *, int))this->GetVParent)(a1: this, a2: i);
        v10 = ((int (__thiscall *)(vgui::IPanel *, int))v8->GetChild)(a1: v7, a2: v9);
        v11 = g_pVGuiPanel;
        v12 = g_pVGuiPanel->__vftable;
        sibling = v10;
        ControlsModuleName = vgui::GetControlsModuleName();
        v14 = (int)v12->GetPanel(this: v11, a2: sibling, a3: ControlsModuleName);
        v15 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v14 + 72))(a1: v14);
        if ( _V_stricmp(s1: v15, s2: siblingName) == 0 )
          break;
        if ( ++i >= siblingCount )
          return nullptr;
      }
      return (vgui::Panel *)v14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0060E040
// Name: public: virtual enum vgui::KeyBindingContextHandle_t vgui::Panel::GetKeyBindingsContext(void)const
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t __thiscall vgui::Panel::GetKeyBindingsContext(vgui::Panel *this)
{
  return this->m_hKeyBindingsContext;
}

//------------------------------------------------------------------------------
// Address: 0x0060E610
// Name: public: class vgui::Panel __near * vgui::Panel::GetChild(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetChild(vgui::Panel *this, int index)
{
  vgui::IPanel *v2; // edi
  vgui::IPanel *v4; // ebx
  const char *ControlsModuleName; // eax
  int v6; // eax
  int v7; // eax
  vgui::IPanel_vtbl *v9; // [esp+Ch] [ebp-8h]
  vgui::IPanel_vtbl *v10; // [esp+10h] [ebp-4h]

  v2 = g_pVGuiPanel;
  v4 = g_pVGuiPanel;
  v9 = g_pVGuiPanel->__vftable;
  v10 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  v6 = ((int (__thiscall *)(vgui::Panel *, int, const char *))this->GetVPanel)(
         a1: this,
         a2: index,
         a3: ControlsModuleName);
  v7 = ((int (__thiscall *)(vgui::IPanel *, int))v10->GetChild)(a1: v2, a2: v6);
  return ((vgui::Panel *(__thiscall *)(vgui::IPanel *, int))v9->GetPanel)(a1: v4, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x0060EE50
// Name: public: enum vgui::Panel::PinCorner_e vgui::Panel::GetPinCorner(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetPinCorner(vgui::Panel *this)
{
  return *((_BYTE *)this + 166) & 0xF;
}

//------------------------------------------------------------------------------
// Address: 0x0060EE80
// Name: public: enum vgui::Panel::AutoResize_e vgui::Panel::GetAutoResize(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::Panel::GetAutoResize(vgui::Panel *this)
{
  return *((unsigned __int8 *)this + 166) >> 4;
}

//------------------------------------------------------------------------------
// Address: 0x0060F300
// Name: public: virtual struct vgui::PanelMap_t __near * vgui::Panel::GetPanelMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMap_t *__thiscall vgui::Panel::GetPanelMap(vgui::Panel *this)
{
  return &vgui::Panel::m_PanelMap;
}

//------------------------------------------------------------------------------
// Address: 0x00610BA0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetDropTarget(class CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetDropTarget(
        vgui::Panel *this,
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *msglist)
{
  vgui::Panel *v4; // eax

  if ( this->m_pDragDrop->m_bDropEnabled && this->IsDroppable(this, a2: msglist) )
    return this;
  if ( this->GetParent(this) == nullptr )
    return nullptr;
  v4 = this->GetParent(this);
  return v4->GetDropTarget(this: v4, a2: msglist);
}

//------------------------------------------------------------------------------
// Address: 0x00610C10
// Name: public: virtual class vgui::Panel __near * vgui::Panel::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetDragPanel(vgui::Panel *this)
{
  vgui::DragDrop_t *m_pDragDrop; // eax
  vgui::Panel *v4; // eax

  m_pDragDrop = this->m_pDragDrop;
  if ( m_pDragDrop->m_bPreventChaining )
    return nullptr;
  if ( m_pDragDrop->m_bDragEnabled )
    return this;
  if ( this->GetParent(this) == nullptr )
    return nullptr;
  v4 = this->GetParent(this);
  return v4->GetDragPanel(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00610C80
// Name: public: virtual struct vgui::DragDrop_t __near * vgui::Panel::GetDragDropInfo(void)
// Source: json
//------------------------------------------------------------------------------
vgui::DragDrop_t *__thiscall vgui::Panel::GetDragDropInfo(vgui::Panel *this)
{
  return this->m_pDragDrop;
}

//------------------------------------------------------------------------------
// Address: 0x00611990
// Name: public: class vgui::Panel __near * vgui::Panel::FindChildByName(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindChildByName(vgui::Panel *this, const char *childName, bool recurseDown)
{
  vgui::IPanel *v3; // ebx
  vgui::IPanel_vtbl *v4; // esi
  int v5; // eax
  int v6; // eax
  vgui::IPanel_vtbl *v7; // edi
  vgui::IPanel_vtbl *v8; // esi
  const char *ControlsModuleName; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  vgui::Panel *v13; // esi
  const char *v14; // eax
  vgui::Panel *result; // eax
  vgui::Panel *v16; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v16 = this;
  for ( i = 0; ; ++i )
  {
    v3 = g_pVGuiPanel;
    if ( g_pVGuiPanel != nullptr )
    {
      v4 = g_pVGuiPanel->__vftable;
      v5 = this->GetVPanel(this);
      v6 = v4->GetChildCount(this: v3, a2: v5);
      v3 = g_pVGuiPanel;
    }
    else
    {
      v6 = 0;
    }
    if ( i >= v6 )
      break;
    v7 = v3->__vftable;
    v8 = v3->__vftable;
    ControlsModuleName = vgui::GetControlsModuleName();
    v10 = ((int (__thiscall *)(vgui::Panel *, int, const char *))v16->GetVPanel)(a1: v16, a2: i, a3: ControlsModuleName);
    v11 = ((int (__thiscall *)(vgui::IPanel *, int))v7->GetChild)(a1: v3, a2: v10);
    v12 = ((int (__thiscall *)(vgui::IPanel *, int))v8->GetPanel)(a1: v3, a2: v11);
    v13 = (vgui::Panel *)v12;
    if ( v12 != 0 )
    {
      v14 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 72))(a1: v12);
      if ( _V_stricmp(s1: v14, s2: childName) == 0 )
        return v13;
      if ( recurseDown )
      {
        result = vgui::Panel::FindChildByName(this: v13, childName, recurseDown);
        if ( result != nullptr )
          return result;
      }
    }
    this = v16;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00612AE0
// Name: public: class vgui::Tooltip __near * vgui::Panel::GetTooltip(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip *__thiscall vgui::Panel::GetTooltip(vgui::Panel *this)
{
  vgui::Tooltip *v2; // eax
  vgui::Tooltip *result; // eax
  bool v4; // zf

  if ( this->m_pTooltips != nullptr )
    return this->m_pTooltips;
  v2 = (vgui::Tooltip *)MemAlloc_Alloc(nSize: 0x28u);
  if ( v2 != nullptr )
    result = vgui::Tooltip::Tooltip(this: v2, parent: this, text: nullptr);
  else
    result = nullptr;
  v4 = (*((_BYTE *)this + 172) & 8) == 0;
  this->m_pTooltips = result;
  if ( !v4 )
  {
    vgui::Tooltip::SetEnabled(this: result, bState: false);
    return this->m_pTooltips;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006132D0
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavUp(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavUp(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavUp; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  unsigned int v11; // edi
  vgui::IPanel *v12; // esi
  vgui::IPanel_vtbl *v13; // ebx
  const char *v14; // eax
  int v15; // eax
  int v16; // ebx
  unsigned int v17; // edi
  vgui::IPanel *v18; // esi
  vgui::IPanel_vtbl *v19; // ebx
  const char *v20; // eax
  unsigned int v21; // eax
  vgui::PHandle *v22; // ebx
  unsigned int v23; // edi
  vgui::IPanel *v24; // esi
  vgui::IPanel_vtbl *v25; // ebx
  const char *v26; // eax
  vgui::Panel *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  const char *v31; // [esp-8h] [ebp-20h]
  vgui::PHandle *v33; // [esp+10h] [ebp-8h]
  vgui::Panel *v34; // [esp+14h] [ebp-4h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavUp.m_iPanelID;
  p_m_NavUp = &this->m_NavUp;
  v33 = &this->m_NavUp;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v34 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v34->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavUp = v33,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavUpName) > 0 )
    {
      v31 = CUtlString::operator char const *(this: &this->m_sNavUpName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v31, recurseDown: true);
      if ( ChildByName != nullptr )
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavUp, pPanel: ChildByName);
    }
  }
  if ( p_m_NavUp->m_iPanelID == -1 || (v11 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID)) == 0 )
  {
    v35 = nullptr;
    v16 = 0;
  }
  else
  {
    v12 = g_pVGuiPanel;
    v13 = g_pVGuiPanel->__vftable;
    v14 = vgui::GetControlsModuleName();
    v15 = (int)v13->GetPanel(this: v12, a2: v11, a3: v14);
    p_m_NavUp = v33;
    v16 = v15;
    v35 = (vgui::Panel *)v15;
  }
  if ( p_m_NavUp->m_iPanelID == -1 )
    return (vgui::Panel *)v16;
  v17 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavUp->m_iPanelID);
  if ( v17 == 0 )
    return (vgui::Panel *)v16;
  v18 = g_pVGuiPanel;
  v19 = g_pVGuiPanel->__vftable;
  v20 = vgui::GetControlsModuleName();
  if ( v19->GetPanel(this: v18, a2: v17, a3: v20) == nullptr )
    return v35;
  v21 = this->m_NavUp.m_iPanelID;
  v22 = &this->m_NavUp;
  if ( v21 == -1 || (v23 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v21)) == 0 )
  {
    v27 = nullptr;
  }
  else
  {
    v24 = g_pVGuiPanel;
    v25 = g_pVGuiPanel->__vftable;
    v26 = vgui::GetControlsModuleName();
    v27 = v25->GetPanel(this: v24, a2: v23, a3: v26);
    v22 = &this->m_NavUp;
  }
  if ( v27 == first )
    return v35;
  v28 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v22);
  if ( v28->IsVisible(this: v28) )
    return v35;
  v29 = this;
  if ( first != nullptr )
    v29 = first;
  return vgui::Panel::GetNavUp(this: v35, first: v29);
}

//------------------------------------------------------------------------------
// Address: 0x00613490
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavDown(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavDown(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavDown; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavDown.m_iPanelID;
  p_m_NavDown = &this->m_NavDown;
  v34 = &this->m_NavDown;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavDown = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavDownName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavDownName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavDown, pPanel: v11);
      }
    }
  }
  if ( p_m_NavDown->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavDown = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavDown->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavDown->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavDown.m_iPanelID;
  v23 = &this->m_NavDown;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavDown;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavDown(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x00613660
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavLeft(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavLeft(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavLeft; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavLeft.m_iPanelID;
  p_m_NavLeft = &this->m_NavLeft;
  v34 = &this->m_NavLeft;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavLeft = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavLeftName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavLeftName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavLeft, pPanel: v11);
      }
    }
  }
  if ( p_m_NavLeft->m_iPanelID == -1 || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavLeft = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavLeft->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavLeft->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavLeft.m_iPanelID;
  v23 = &this->m_NavLeft;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavLeft;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavLeft(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x00613830
// Name: public: class vgui::Panel __near * vgui::Panel::GetNavRight(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::GetNavRight(vgui::Panel *this, vgui::Panel *first)
{
  unsigned int m_iPanelID; // eax
  vgui::PHandle *p_m_NavRight; // esi
  unsigned int v5; // edi
  vgui::IPanel *v6; // esi
  const char *ControlsModuleName; // eax
  int v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Panel *v11; // eax
  unsigned int v12; // edi
  vgui::IPanel *v13; // esi
  vgui::IPanel_vtbl *v14; // ebx
  const char *v15; // eax
  int v16; // eax
  int v17; // ebx
  unsigned int v18; // edi
  vgui::IPanel *v19; // esi
  vgui::IPanel_vtbl *v20; // ebx
  const char *v21; // eax
  unsigned int v22; // eax
  vgui::PHandle *v23; // ebx
  unsigned int v24; // edi
  vgui::IPanel *v25; // esi
  vgui::IPanel_vtbl *v26; // ebx
  const char *v27; // eax
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Panel *v30; // eax
  const char *v32; // [esp-8h] [ebp-20h]
  vgui::PHandle *v34; // [esp+10h] [ebp-8h]
  vgui::Panel *v35; // [esp+14h] [ebp-4h]
  vgui::Panel *v36; // [esp+14h] [ebp-4h]

  m_iPanelID = this->m_NavRight.m_iPanelID;
  p_m_NavRight = &this->m_NavRight;
  v34 = &this->m_NavRight;
  if ( m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: m_iPanelID)) == 0
    || (v6 = g_pVGuiPanel,
        v35 = (vgui::Panel *)g_pVGuiPanel->__vftable,
        ControlsModuleName = vgui::GetControlsModuleName(),
        v8 = ((int (__thiscall *)(vgui::IPanel *, unsigned int, const char *))v35->m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount)(
               a1: v6,
               a2: v5,
               a3: ControlsModuleName),
        p_m_NavRight = v34,
        v8 == 0) )
  {
    if ( CUtlString::Length(this: &this->m_sNavRightName) > 0 )
    {
      v32 = CUtlString::operator char const *(this: &this->m_sNavRightName);
      v9 = this->GetParent(this);
      ChildByName = vgui::Panel::FindChildByName(this: v9, childName: v32, recurseDown: true);
      if ( ChildByName != nullptr )
      {
        v11 = ChildByName->GetPanel(this: ChildByName);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: p_m_NavRight, pPanel: v11);
      }
    }
  }
  if ( p_m_NavRight->m_iPanelID == -1
    || (v12 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID)) == 0 )
  {
    v36 = nullptr;
    v17 = 0;
  }
  else
  {
    v13 = g_pVGuiPanel;
    v14 = g_pVGuiPanel->__vftable;
    v15 = vgui::GetControlsModuleName();
    v16 = (int)v14->GetPanel(this: v13, a2: v12, a3: v15);
    p_m_NavRight = v34;
    v17 = v16;
    v36 = (vgui::Panel *)v16;
  }
  if ( p_m_NavRight->m_iPanelID == -1 )
    return (vgui::Panel *)v17;
  v18 = g_pVGui->HandleToPanel(this: g_pVGui, a2: p_m_NavRight->m_iPanelID);
  if ( v18 == 0 )
    return (vgui::Panel *)v17;
  v19 = g_pVGuiPanel;
  v20 = g_pVGuiPanel->__vftable;
  v21 = vgui::GetControlsModuleName();
  if ( v20->GetPanel(this: v19, a2: v18, a3: v21) == nullptr )
    return v36;
  v22 = this->m_NavRight.m_iPanelID;
  v23 = &this->m_NavRight;
  if ( v22 == -1 || (v24 = g_pVGui->HandleToPanel(this: g_pVGui, a2: v22)) == 0 )
  {
    v28 = nullptr;
  }
  else
  {
    v25 = g_pVGuiPanel;
    v26 = g_pVGuiPanel->__vftable;
    v27 = vgui::GetControlsModuleName();
    v28 = v26->GetPanel(this: v25, a2: v24, a3: v27);
    v23 = &this->m_NavRight;
  }
  if ( v28 == first )
    return v36;
  v29 = vgui::DHANDLE<vgui::Menu>::operator vgui::Menu *(this: v23);
  if ( v29->IsVisible(this: v29) )
    return v36;
  v30 = this;
  if ( first != nullptr )
    v30 = first;
  return vgui::Panel::GetNavRight(this: v36, first: v30);
}

//------------------------------------------------------------------------------
// Address: 0x00614050
// Name: public: struct vgui::PanelKeyBindingMap __near * vgui::Panel::LookupMapForBinding(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Panel::LookupMapForBinding(vgui::Panel *this, const char *bindingName)
{
  vgui::PanelKeyBindingMap *v2; // ebx
  int v3; // edi
  int v4; // esi
  int c; // [esp+Ch] [ebp-4h]

  v2 = this->GetKBMap(this);
  if ( v2 == nullptr )
    return nullptr;
  while ( 1 )
  {
    v3 = 0;
    c = v2->entries.m_Size;
    if ( c > 0 )
      break;
LABEL_6:
    v2 = v2->baseMap;
    if ( v2 == nullptr )
      return nullptr;
  }
  v4 = 0;
  while ( _V_stricmp(s1: v2->entries.m_Memory.m_pMemory[v4].bindingname, s2: bindingName) != 0 )
  {
    ++v3;
    ++v4;
    if ( v3 >= c )
      goto LABEL_6;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x006140B0
// Name: public: struct vgui::KeyBindingMap_t __near * vgui::Panel::LookupBindingByKeyCode(enum ButtonCode_t,int)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingMap_t *__thiscall vgui::Panel::LookupBindingByKeyCode(
        vgui::Panel *this,
        ButtonCode_t code,
        int modifiers)
{
  vgui::Panel *v3; // esi
  vgui::PanelKeyBindingMap *v4; // ebx
  int m_Size; // edi
  vgui::BoundKey_t *v6; // eax
  vgui::PanelKeyBindingMap *v7; // eax
  int v8; // ebx
  int v9; // edi
  const char **p_bindingname; // esi
  int c; // [esp+Ch] [ebp-20h]
  int v14; // [esp+14h] [ebp-18h]
  char *s2; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  vgui::PanelKeyBindingMap *map; // [esp+20h] [ebp-Ch]
  int v18; // [esp+24h] [ebp-8h]
  vgui::PanelKeyBindingMap *baseMap; // [esp+28h] [ebp-4h]

  v3 = this;
  map = (vgui::PanelKeyBindingMap *)((int (__fastcall *)(vgui::Panel *))this->GetKBMap)(a1: this);
  if ( map == nullptr )
    return nullptr;
  while ( 1 )
  {
    v4 = map;
    m_Size = map->boundkeys.m_Size;
    c = m_Size;
    i = 0;
    if ( m_Size > 0 )
      break;
LABEL_17:
    map = v4->baseMap;
    if ( map == nullptr )
      return nullptr;
  }
  v18 = 0;
  while ( 1 )
  {
    v6 = &v4->boundkeys.m_Memory.m_pMemory[v18];
    if ( v6->keycode == code && v6->modifiers == modifiers )
    {
      s2 = (char *)v6->bindingname;
      v7 = v3->GetKBMap(this: v3);
      baseMap = v7;
      if ( v7 != nullptr )
        break;
    }
LABEL_16:
    ++v18;
    if ( ++i >= m_Size )
      goto LABEL_17;
  }
  while ( 1 )
  {
    v8 = 0;
    v14 = v7->entries.m_Size;
    if ( v14 > 0 )
      break;
LABEL_14:
    baseMap = v7->baseMap;
    if ( baseMap == nullptr )
    {
      m_Size = c;
      v4 = map;
      goto LABEL_16;
    }
    v7 = v7->baseMap;
  }
  v9 = 0;
  while ( 1 )
  {
    p_bindingname = &v7->entries.m_Memory.m_pMemory[v9].bindingname;
    if ( _V_stricmp(s1: *p_bindingname, s2) == 0 )
      return (vgui::KeyBindingMap_t *)p_bindingname;
    v7 = baseMap;
    ++v8;
    ++v9;
    if ( v8 >= v14 )
    {
      v3 = this;
      goto LABEL_14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00615720
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateUp(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateUp(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavUp(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_UP;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00615760
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateDown(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateDown(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavDown(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_DOWN;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006157A0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateLeft(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateLeft(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavLeft(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_LEFT;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006157E0
// Name: public: virtual class vgui::Panel __near * vgui::Panel::NavigateRight(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::NavigateRight(vgui::Panel *this)
{
  vgui::Panel *result; // eax
  vgui::Panel *v3; // esi
  void (__thiscall *NavigateTo)(vgui::Panel *); // edx

  result = vgui::Panel::GetNavRight(this, first: nullptr);
  v3 = result;
  if ( result != nullptr )
  {
    this->NavigateFrom(this);
    NavigateTo = v3->NavigateTo;
    v3->m_LastNavDirection = ND_RIGHT;
    NavigateTo(this: v3);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0061ACE0
// Name: private: class vgui::Panel __near * vgui::Panel::FindDropTargetPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::Panel::FindDropTargetPanel(vgui::Panel *this)
{
  unsigned int v1; // ebx
  vgui::IPanel *v2; // edi
  vgui::IPanel_vtbl *v3; // esi
  const char *ControlsModuleName; // eax
  unsigned int v5; // ebx
  vgui::IPanel *v6; // edi
  vgui::IPanel_vtbl *v7; // esi
  const char *v8; // eax
  vgui::Panel *v9; // eax
  int v10; // ebx
  int v11; // edi
  int m_Size; // eax
  unsigned int v13; // eax
  unsigned int v14; // esi
  int v15; // eax
  vgui::IPanel *v17; // edi
  vgui::IPanel_vtbl *v18; // esi
  unsigned int *v19; // ebx
  const char *v20; // eax
  int v21; // esi
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > hits; // [esp+Ch] [ebp-24h] BYREF
  int nCount; // [esp+20h] [ebp-10h]
  vgui::Panel *v24; // [esp+24h] [ebp-Ch]
  int x; // [esp+28h] [ebp-8h] BYREF
  int y; // [esp+2Ch] [ebp-4h] BYREF

  v24 = this;
  if ( s_DragDropHelper.m_iPanelID == -1 )
    return nullptr;
  v1 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID);
  if ( v1 == 0 )
    return nullptr;
  v2 = g_pVGuiPanel;
  v3 = g_pVGuiPanel->__vftable;
  ControlsModuleName = vgui::GetControlsModuleName();
  if ( v3->GetPanel(this: v2, a2: v1, a3: ControlsModuleName) == nullptr )
    return nullptr;
  memset(&hits, 0, sizeof(hits));
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  nCount = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  if ( s_DragDropHelper.m_iPanelID == -1
    || (v5 = g_pVGui->HandleToPanel(this: g_pVGui, a2: s_DragDropHelper.m_iPanelID)) == 0 )
  {
    v9 = nullptr;
  }
  else
  {
    v6 = g_pVGuiPanel;
    v7 = g_pVGuiPanel->__vftable;
    v8 = vgui::GetControlsModuleName();
    v9 = v7->GetPanel(this: v6, a2: v5, a3: v8);
  }
  v10 = v9->GetVPanel(this: v9);
  if ( g_pVGuiSurface->IsCursorVisible(this: g_pVGuiSurface)
    && g_pVGuiSurface->IsWithin(this: g_pVGuiSurface, a2: x, a3: y) )
  {
    v11 = g_pVGuiSurface->GetPopupCount(this: g_pVGuiSurface) - 1;
    if ( v11 >= 0 )
    {
      do
      {
        m_Size = hits.m_Size;
        if ( hits.m_Size != 0 )
          goto LABEL_20;
        v13 = g_pVGuiSurface->GetPopup(this: g_pVGuiSurface, a2: v11);
        v14 = v13;
        if ( v13 != nCount && v13 != v10 && g_pVGuiPanel->IsFullyVisible(this: g_pVGuiPanel, a2: v13) )
          vgui::Panel::FindDropTargetPanel_R(this: v24, panelList: &hits, x, y, check: v14);
      }
      while ( --v11 >= 0 );
    }
    m_Size = hits.m_Size;
    if ( hits.m_Size != 0 )
      goto LABEL_20;
    vgui::Panel::FindDropTargetPanel_R(this: v24, panelList: &hits, x, y, check: nCount);
  }
  m_Size = hits.m_Size;
  if ( hits.m_Size == 0 )
  {
LABEL_21:
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&hits);
    return nullptr;
  }
LABEL_20:
  v15 = m_Size - 1;
  nCount = v15;
  if ( v15 < 0 )
    goto LABEL_21;
  while ( 1 )
  {
    v17 = g_pVGuiPanel;
    v18 = g_pVGuiPanel->__vftable;
    v19 = &hits.m_Memory.m_pMemory[v15];
    v20 = v24->GetModuleName(this: v24);
    v21 = (int)v18->GetPanel(this: v17, a2: *v19, a3: v20);
    if ( v21 != 0 )
      break;
    if ( --nCount < 0 )
    {
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&hits);
      return nullptr;
    }
    v15 = nCount;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&hits);
  return (vgui::Panel *)v21;
}

//------------------------------------------------------------------------------
// Address: 0x0040F120
// Name: class CDmElement __near * GetElement<class CDmElement>(enum DmElementHandle_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *__cdecl GetElement<CDmElement>(DmElementHandle_t hElement)
{
  int v1; // eax
  int v2; // esi

  v1 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: hElement);
  v2 = v1;
  if ( v1 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v1 + 16))(
         a1: v1,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return (CDmElement *)v2;
  }
  else
  {
    return nullptr;
  }
}
