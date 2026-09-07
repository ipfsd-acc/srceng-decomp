// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/baseanimationseteditor.cpp
// Functions: 17
// ============================================================

#include "vgui2\dme_controls\baseanimationseteditor.h"

//------------------------------------------------------------------------------
// Address: 0x00487D50
// Name: public: static char const __near * CBaseAnimationSetEditor::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAnimationSetEditor::GetPanelClassName()
{
  return "CBaseAnimationSetEditor";
}

//------------------------------------------------------------------------------
// Address: 0x00487D60
// Name: public: virtual CBaseAnimationSetEditor::~CBaseAnimationSetEditor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::~CBaseAnimationSetEditor(CBaseAnimationSetEditor *this)
{
  this->__vftable = (CBaseAnimationSetEditor_vtbl *)&CBaseAnimationSetEditor::`vftable';
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00487D70
// Name: public: class CBaseAnimationSetControl __near * CBaseAnimationSetEditor::GetController(void)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimationSetControl *__thiscall CBaseAnimationSetEditor::GetController(CBaseAnimationSetEditor *this)
{
  return this->m_pController;
}

//------------------------------------------------------------------------------
// Address: 0x00487D90
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAnimationSetEditor::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAnimationSetEditor::GetMessageMap(CBaseAnimationSetEditor *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAnimationSetEditor::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimationSetEditor::GetMessageMap'::`2'::s_pMap;
  `CBaseAnimationSetEditor::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimationSetEditor");
  `CBaseAnimationSetEditor::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00487DC0
// Name: public: virtual struct PanelAnimationMap __near * CBaseAnimationSetEditor::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAnimationSetEditor::GetAnimMap(CBaseAnimationSetEditor *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAnimationSetEditor");
}

//------------------------------------------------------------------------------
// Address: 0x00487DD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAnimationSetEditor::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAnimationSetEditor::GetKBMap(CBaseAnimationSetEditor *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAnimationSetEditor::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimationSetEditor::GetKBMap'::`2'::s_pMap;
  `CBaseAnimationSetEditor::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimationSetEditor");
  `CBaseAnimationSetEditor::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00487E30
// Name: public: virtual void CBaseAnimationSetEditor::CreateToolsSubPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::CreateToolsSubPanels(CBaseAnimationSetEditor *this)
{
  CBaseAnimSetControlGroupPanel *v2; // eax
  CBaseAnimSetControlGroupPanel *v3; // eax
  CBaseAnimSetPresetFaderPanel *v4; // eax
  CBaseAnimSetPresetFaderPanel *v5; // eax
  CBaseAnimSetAttributeSliderPanel *v6; // eax
  CBaseAnimSetAttributeSliderPanel *v7; // eax

  v2 = (CBaseAnimSetControlGroupPanel *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v2 != nullptr )
    v3 = CBaseAnimSetControlGroupPanel::CBaseAnimSetControlGroupPanel(
           this: v2,
           parent: nullptr,
           className: "AnimSetControlGroup",
           editor: this,
           bControlStateInterface: false);
  else
    v3 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hControlGroup, pPanel: v3);
  v4 = (CBaseAnimSetPresetFaderPanel *)MemAlloc_Alloc(nSize: 0x1C0u);
  if ( v4 != nullptr )
    v5 = CBaseAnimSetPresetFaderPanel::CBaseAnimSetPresetFaderPanel(
           this: v4,
           parent: nullptr,
           className: "AnimSetPresetFader",
           editor: this);
  else
    v5 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hPresetFader, pPanel: v5);
  v6 = (CBaseAnimSetAttributeSliderPanel *)MemAlloc_Alloc(nSize: 0x1C4u);
  if ( v6 != nullptr )
  {
    v7 = CBaseAnimSetAttributeSliderPanel::CBaseAnimSetAttributeSliderPanel(
           this: v6,
           parent: nullptr,
           className: "AnimSetAttributeSliderPanel",
           editor: this);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hAttributeSlider, pPanel: v7);
  }
  else
  {
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hAttributeSlider, pPanel: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487EE0
// Name: protected: virtual void CBaseAnimationSetEditor::OnOpenContextMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::OnOpenContextMenu(CBaseAnimationSetEditor *this, KeyValues *params)
{
  vgui::Panel *v3; // eax
  vgui::Menu *v4; // eax
  vgui::Menu *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  vgui::Panel *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // edi
  vgui::Panel *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // edi
  vgui::Panel *v14; // eax
  void *Ptr; // edi
  vgui::Menu *v16; // eax
  vgui::Panel *v17; // eax

  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v3 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    if ( v3 != nullptr )
      ((void (__thiscall *)(vgui::Panel *, int))v3->dtr_Panel)(a1: v3, a2: 1);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  v4 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v4 != nullptr )
    v5 = vgui::Menu::Menu(this: v4, parent: this, panelName: "ActionMenu");
  else
    v5 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: v5);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "OnChangeLayout", firstKey: "value", firstValue: 0);
  else
    v7 = nullptr;
  v8 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimationSetEditor *, _DWORD))v8->__vftable[1].PaintTraverse)(
    a1: v8,
    a2: "#BxAnimSetSplitLayout",
    a3: v7,
    a4: this,
    a5: 0);
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: "OnChangeLayout", firstKey: "value", firstValue: 1);
  else
    v10 = nullptr;
  v11 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimationSetEditor *, _DWORD))v11->__vftable[1].PaintTraverse)(
    a1: v11,
    a2: "#BxAnimSetVerticalLayout",
    a3: v10,
    a4: this,
    a5: 0);
  v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v12 != nullptr )
    v13 = KeyValues::KeyValues(this: v12, setName: "OnChangeLayout", firstKey: "value", firstValue: 2);
  else
    v13 = nullptr;
  v14 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimationSetEditor *, _DWORD))v14->__vftable[1].PaintTraverse)(
    a1: v14,
    a2: "#BxAnimSetHorizontalLayout",
    a3: v13,
    a4: this,
    a5: 0);
  Ptr = KeyValues::GetPtr(this: params, keyName: "contextlabel", defaultValue: nullptr);
  v16 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
  if ( Ptr != nullptr )
  {
    v16->PerformLayout(this: v16);
    v17 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    ((void (__thiscall *)(vgui::Panel *, void *, int, _DWORD, int))v17->__vftable[1].GetVPanel)(
      a1: v17,
      a2: Ptr,
      a3: 3,
      a4: 0,
      a5: 1);
  }
  else
  {
    vgui::Menu::PlaceContextMenu(parent: this, menu: v16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00488090
// Name: protected: virtual void CBaseAnimationSetEditor::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::ApplySchemeSettings(CBaseAnimationSetEditor *this, vgui::IScheme *pScheme)
{
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v3 = vgui::PHandle::Get(this: &this->m_hControlGroup);
  if ( v3->GetParent(this: v3) != this )
  {
    v4 = vgui::PHandle::Get(this: &this->m_hControlGroup);
    v4->ApplySchemeSettings(this: v4, a2: pScheme);
  }
  v5 = vgui::PHandle::Get(this: &this->m_hPresetFader);
  if ( v5->GetParent(this: v5) != this )
  {
    v6 = vgui::PHandle::Get(this: &this->m_hPresetFader);
    v6->ApplySchemeSettings(this: v6, a2: pScheme);
  }
  v7 = vgui::PHandle::Get(this: &this->m_hAttributeSlider);
  if ( v7->GetParent(this: v7) != this )
  {
    v8 = vgui::PHandle::Get(this: &this->m_hAttributeSlider);
    v8->ApplySchemeSettings(this: v8, a2: pScheme);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00488150
// Name: public: class CBaseAnimSetPresetFaderPanel __near * CBaseAnimationSetEditor::GetPresetFader(void)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimSetPresetFaderPanel *__thiscall CBaseAnimationSetEditor::GetPresetFader(CBaseAnimationSetEditor *this)
{
  return (CBaseAnimSetPresetFaderPanel *)vgui::PHandle::Get(this: &this->m_hPresetFader);
}

//------------------------------------------------------------------------------
// Address: 0x00488160
// Name: public: class CBaseAnimSetAttributeSliderPanel __near * CBaseAnimationSetEditor::GetAttributeSlider(void)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimSetAttributeSliderPanel *__thiscall CBaseAnimationSetEditor::GetAttributeSlider(CBaseAnimationSetEditor *this)
{
  return (CBaseAnimSetAttributeSliderPanel *)vgui::PHandle::Get(this: &this->m_hAttributeSlider);
}

//------------------------------------------------------------------------------
// Address: 0x00488170
// Name: public: void CBaseAnimationSetEditor::ChangeAnimationSetClip(class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::ChangeAnimationSetClip(CBaseAnimationSetEditor *this, CDmeFilmClip *pFilmClip)
{
  CBaseAnimSetControlGroupPanel *v3; // eax
  vgui::Panel *v4; // eax

  this->m_pController->ChangeAnimationSetClip(this: this->m_pController, a2: pFilmClip);
  if ( vgui::PHandle::Get(this: &this->m_hControlGroup) != nullptr )
  {
    v3 = (CBaseAnimSetControlGroupPanel *)vgui::PHandle::Get(this: &this->m_hControlGroup);
    CBaseAnimSetControlGroupPanel::ChangeAnimationSetClip(this: v3, pFilmClip);
  }
  if ( vgui::PHandle::Get(this: &this->m_hAttributeSlider) != nullptr )
  {
    v4 = vgui::PHandle::Get(this: &this->m_hAttributeSlider);
    ((void (__thiscall *)(vgui::Panel *, CDmeFilmClip *))v4->__vftable[1].GetPanel)(a1: v4, a2: pFilmClip);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004881E0
// Name: public: static void CBaseAnimationSetEditor::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimationSetEditor::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimationSetEditor::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CBaseAnimationSetEditor::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimationSetEditor");
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
// Address: 0x00488270
// Name: public: static void CBaseAnimationSetEditor::PanelMessageFunc_OnChangeLayout::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimationSetEditor::PanelMessageFunc_OnChangeLayout::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimationSetEditor::PanelMessageFunc_OnChangeLayout::InitVar'::`2'::bAdded )
  {
    `CBaseAnimationSetEditor::PanelMessageFunc_OnChangeLayout::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimationSetEditor");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OnChangeLayout";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "value";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00488310
// Name: public: CBaseAnimationSetEditor::CBaseAnimationSetEditor(class vgui::Panel __near *,char const __near *,class CBaseAnimationSetControl __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimationSetEditor *__thiscall CBaseAnimationSetEditor::CBaseAnimationSetEditor(
        CBaseAnimationSetEditor *this,
        vgui::Panel *parent,
        const char *className,
        CBaseAnimationSetControl *pAnimationSetController)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName: className);
  this->__vftable = (CBaseAnimationSetEditor_vtbl *)&CBaseAnimationSetEditor::`vftable';
  if ( `CBaseAnimationSetEditor::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimationSetEditor::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimationSetEditor");
    v5->pfnClassName = CBaseAnimationSetEditor::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAnimationSetEditor::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAnimationSetEditor::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CBaseAnimationSetEditor");
    v6->pfnClassName = CBaseAnimationSetEditor::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAnimationSetEditor::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimationSetEditor::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimationSetEditor");
    v7->pfnClassName = CBaseAnimationSetEditor::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CBaseAnimationSetEditor::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  CBaseAnimationSetEditor::PanelMessageFunc_OnChangeLayout::InitVar(a1: (int)&savedregs);
  this->m_Layout = LAYOUT_SPLIT;
  this->m_Splitter.m_iPanelID = -1;
  this->m_hControlGroup.m_iPanelID = -1;
  this->m_hPresetFader.m_iPanelID = -1;
  this->m_hAttributeSlider.m_iPanelID = -1;
  this->m_hContextMenu.m_iPanelID = -1;
  this->m_pController = pAnimationSetController;
  pAnimationSetController->m_pEditor = this;
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v9 = KeyValues::KeyValues(this: v8, setName: "OnChangeLayout", firstKey: "value", firstValue: this->m_Layout);
  else
    v9 = nullptr;
  vgui::Panel::PostMessage(this, target: this->_vpanel, message: v9, delaySeconds: 0.0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00488450
// Name: public: virtual void CBaseAnimationSetEditor::ChangeLayout(enum CBaseAnimationSetEditor::EAnimSetLayout_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::ChangeLayout(
        CBaseAnimationSetEditor *this,
        CBaseAnimationSetEditor::EAnimSetLayout_t newLayout)
{
  vgui::DHANDLE<CBaseAnimSetControlGroupPanel> *p_m_hControlGroup; // ebx
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::DHANDLE<vgui::Splitter> *p_m_Splitter; // esi
  vgui::Panel *v8; // eax
  vgui::Panel **m_pMemory; // ebx
  int m_Size; // eax
  int v11; // ecx
  int v12; // eax
  vgui::Panel **v13; // eax
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  vgui::Panel **v17; // eax
  vgui::Splitter *v18; // eax
  vgui::Splitter *v19; // eax
  vgui::Panel *v20; // eax
  int v21; // eax
  vgui::Splitter *v22; // eax
  vgui::Panel *v23; // eax
  vgui::Panel_vtbl *v24; // edi
  vgui::Panel *v25; // eax
  vgui::Panel *v26; // eax
  vgui::Splitter *v27; // edi
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Splitter *v30; // esi
  vgui::Panel *v31; // eax
  vgui::Panel_vtbl *v32; // edi
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  vgui::Panel_vtbl *v36; // edi
  vgui::Panel *v37; // eax
  vgui::Panel *v38; // eax
  vgui::Splitter_vtbl *v39; // edi
  int v40; // eax
  vgui::Splitter *v41; // ecx
  vgui::Splitter *v42; // eax
  vgui::Splitter *v43; // eax
  vgui::Splitter *v44; // eax
  vgui::Panel *v45; // eax
  int v46; // eax
  int j; // edi
  vgui::Panel *v48; // eax
  vgui::Panel *v49; // eax
  vgui::Panel *v50; // eax
  vgui::Panel *v51; // eax
  int v52; // eax
  vgui::Splitter *v53; // eax
  vgui::Splitter *v54; // eax
  vgui::Splitter *v55; // eax
  vgui::Panel *v56; // eax
  int Wide; // eax
  int i; // edi
  vgui::Panel *v59; // eax
  vgui::Panel *Child; // eax
  vgui::Panel *v61; // eax
  vgui::Panel *v62; // eax
  int v63; // eax
  int v64; // [esp-4h] [ebp-34h]
  int v65; // [esp-4h] [ebp-34h]
  int v66; // [esp-4h] [ebp-34h]
  int v67; // [esp-4h] [ebp-34h]
  int v68; // [esp-4h] [ebp-34h]
  int Tall; // [esp-4h] [ebp-34h]
  CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > list; // [esp+Ch] [ebp-24h] BYREF
  vgui::Panel *v71; // [esp+20h] [ebp-10h]
  vgui::PHandle *v72; // [esp+24h] [ebp-Ch]
  vgui::PHandle *p_m_hAttributeSlider; // [esp+28h] [ebp-8h]
  vgui::PHandle *p_m_hPresetFader; // [esp+2Ch] [ebp-4h]
  vgui::Panel *newLayouta; // [esp+38h] [ebp+8h]
  CBaseAnimationSetEditor::EAnimSetLayout_t newLayoutb; // [esp+38h] [ebp+8h]
  CBaseAnimationSetEditor::EAnimSetLayout_t newLayoutc; // [esp+38h] [ebp+8h]
  vgui::Panel *newLayoutd; // [esp+38h] [ebp+8h]
  vgui::Panel *newLayoute; // [esp+38h] [ebp+8h]
  CBaseAnimationSetEditor::EAnimSetLayout_t newLayoutf; // [esp+38h] [ebp+8h]
  CBaseAnimationSetEditor::EAnimSetLayout_t newLayoutg; // [esp+38h] [ebp+8h]
  vgui::Panel *newLayouth; // [esp+38h] [ebp+8h]
  CBaseAnimationSetEditor::EAnimSetLayout_t newLayouti; // [esp+38h] [ebp+8h]
  vgui::Panel *newLayoutj; // [esp+38h] [ebp+8h]
  vgui::Panel *newLayoutk; // [esp+38h] [ebp+8h]
  CBaseAnimationSetEditor::EAnimSetLayout_t newLayoutl; // [esp+38h] [ebp+8h]
  vgui::Panel *newLayoutm; // [esp+38h] [ebp+8h]

  p_m_hControlGroup = &this->m_hControlGroup;
  this->m_Layout = newLayout;
  v72 = &this->m_hControlGroup;
  v4 = vgui::PHandle::Get(this: &this->m_hControlGroup);
  v4->SetParent_2(this: v4, a2: nullptr);
  p_m_hPresetFader = &this->m_hPresetFader;
  v5 = vgui::PHandle::Get(this: &this->m_hPresetFader);
  v5->SetParent_2(this: v5, a2: nullptr);
  p_m_hAttributeSlider = &this->m_hAttributeSlider;
  v6 = vgui::PHandle::Get(this: &this->m_hAttributeSlider);
  v6->SetParent_2(this: v6, a2: nullptr);
  p_m_Splitter = &this->m_Splitter;
  v8 = vgui::PHandle::Get(this: &this->m_Splitter);
  if ( v8 != nullptr )
    ((void (__thiscall *)(vgui::Panel *, int))v8->dtr_Panel)(a1: v8, a2: 1);
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_Splitter, pPanel: nullptr);
  memset(&list, 0, sizeof(list));
  newLayouta = vgui::PHandle::Get(this: p_m_hControlGroup);
  CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&list, num: 1);
  m_pMemory = list.m_Memory.m_pMemory;
  ++list.m_Size;
  list.m_pElements = list.m_Memory.m_pMemory;
  if ( list.m_Size - 1 > 0 )
    _V_memmove(dest: list.m_Memory.m_pMemory + 1, src: list.m_Memory.m_pMemory, count: 4 * (list.m_Size - 1));
  if ( m_pMemory != nullptr )
    *m_pMemory = newLayouta;
  v71 = vgui::PHandle::Get(this: p_m_hPresetFader);
  m_Size = list.m_Size;
  v11 = list.m_Size;
  newLayoutb = list.m_Size;
  if ( list.m_Size + 1 > list.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&list,
      num: list.m_Size - list.m_Memory.m_nAllocationCount + 1);
    m_pMemory = list.m_Memory.m_pMemory;
    v11 = newLayoutb;
    m_Size = list.m_Size;
  }
  list.m_Size = m_Size + 1;
  v12 = m_Size - v11;
  list.m_pElements = m_pMemory;
  if ( v12 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v11 + 1], src: &m_pMemory[v11], count: 4 * v12);
    v11 = newLayoutb;
  }
  v13 = &m_pMemory[v11];
  if ( v13 != nullptr )
    *v13 = v71;
  v71 = vgui::PHandle::Get(this: p_m_hAttributeSlider);
  v14 = list.m_Size;
  v15 = list.m_Size;
  newLayoutc = list.m_Size;
  if ( list.m_Size + 1 > list.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&list,
      num: list.m_Size - list.m_Memory.m_nAllocationCount + 1);
    m_pMemory = list.m_Memory.m_pMemory;
    v15 = newLayoutc;
    v14 = list.m_Size;
  }
  list.m_Size = v14 + 1;
  v16 = v14 - v15;
  if ( v16 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v15 + 1], src: &m_pMemory[v15], count: 4 * v16);
    v15 = newLayoutc;
  }
  v17 = &m_pMemory[v15];
  if ( v17 != nullptr )
    *v17 = v71;
  if ( this->m_Layout == LAYOUT_VERTICAL )
  {
    v53 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
    if ( v53 != nullptr )
      v54 = vgui::Splitter::Splitter(
              this: v53,
              parent: this,
              name: "AnimSetEditorMainSplitter",
              mode: SPLITTER_MODE_VERTICAL,
              nCount: 2);
    else
      v54 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_Splitter, pPanel: v54);
    v55 = (vgui::Splitter *)vgui::PHandle::Get(this: &this->m_Splitter);
    vgui::Splitter::SetSplitterColor(this: v55, c: (Color)-14671840);
    v56 = vgui::PHandle::Get(this: &this->m_Splitter);
    vgui::Panel::SetAutoResize(
      this: v56,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 0,
      nPinOffsetY: 38,
      nUnpinnedCornerOffsetX: 0,
      nUnpinnedCornerOffsetY: 0);
    newLayoutk = vgui::PHandle::Get(this: &this->m_Splitter);
    v68 = vgui::Panel::GetTall(this) - 38;
    Wide = vgui::Panel::GetWide(this);
    vgui::Panel::SetBounds(this: newLayoutk, x: 0, y: 38, wide: Wide, tall: v68);
    for ( i = 0; i < list.m_Size; ++i )
    {
      newLayoutl = (CBaseAnimationSetEditor::EAnimSetLayout_t)m_pMemory[i];
      v59 = vgui::PHandle::Get(this: p_m_Splitter);
      v71 = (vgui::Panel *)(*(_DWORD *)newLayoutl + 168);
      Child = vgui::Panel::GetChild(this: v59, index: i);
      ((void (__thiscall *)(CBaseAnimationSetEditor::EAnimSetLayout_t, vgui::Panel *))v71->__vftable)(
        a1: newLayoutl,
        a2: Child);
      newLayoutm = vgui::PHandle::Get(this: p_m_Splitter);
      v71 = vgui::PHandle::Get(this: p_m_Splitter);
      v61 = vgui::Panel::GetChild(this: newLayoutm, index: i);
      Tall = vgui::Panel::GetTall(this: v61);
      v62 = vgui::Panel::GetChild(this: v71, index: i);
      v63 = vgui::Panel::GetWide(this: v62);
      vgui::Panel::SetSize(this: m_pMemory[i], wide: v63, tall: Tall);
      vgui::Panel::SetAutoResize(
        this: m_pMemory[i],
        pinCorner: PIN_TOPLEFT,
        resizeDir: AUTORESIZE_DOWNANDRIGHT,
        nPinOffsetX: 0,
        nPinOffsetY: 0,
        nUnpinnedCornerOffsetX: 0,
        nUnpinnedCornerOffsetY: 0);
    }
    goto LABEL_39;
  }
  if ( this->m_Layout == LAYOUT_HORIZONTAL )
  {
    v42 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
    if ( v42 != nullptr )
      v43 = vgui::Splitter::Splitter(
              this: v42,
              parent: this,
              name: "AnimSetEditorMainSplitter",
              mode: SPLITTER_MODE_HORIZONTAL,
              nCount: 2);
    else
      v43 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_Splitter, pPanel: v43);
    v44 = (vgui::Splitter *)vgui::PHandle::Get(this: &this->m_Splitter);
    vgui::Splitter::SetSplitterColor(this: v44, c: (Color)-14671840);
    v45 = vgui::PHandle::Get(this: &this->m_Splitter);
    vgui::Panel::SetAutoResize(
      this: v45,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 0,
      nPinOffsetY: 38,
      nUnpinnedCornerOffsetX: 0,
      nUnpinnedCornerOffsetY: 0);
    newLayouth = vgui::PHandle::Get(this: &this->m_Splitter);
    v66 = vgui::Panel::GetTall(this) - 38;
    v46 = vgui::Panel::GetWide(this);
    vgui::Panel::SetBounds(this: newLayouth, x: 0, y: 38, wide: v46, tall: v66);
    for ( j = 0; j < list.m_Size; ++j )
    {
      newLayouti = (CBaseAnimationSetEditor::EAnimSetLayout_t)m_pMemory[j];
      v48 = vgui::PHandle::Get(this: p_m_Splitter);
      v71 = (vgui::Panel *)(*(_DWORD *)newLayouti + 168);
      v49 = vgui::Panel::GetChild(this: v48, index: j);
      ((void (__thiscall *)(CBaseAnimationSetEditor::EAnimSetLayout_t, vgui::Panel *))v71->__vftable)(
        a1: newLayouti,
        a2: v49);
      newLayoutj = vgui::PHandle::Get(this: p_m_Splitter);
      v71 = vgui::PHandle::Get(this: p_m_Splitter);
      v50 = vgui::Panel::GetChild(this: newLayoutj, index: j);
      v67 = vgui::Panel::GetTall(this: v50);
      v51 = vgui::Panel::GetChild(this: v71, index: j);
      v52 = vgui::Panel::GetWide(this: v51);
      vgui::Panel::SetSize(this: m_pMemory[j], wide: v52, tall: v67);
      vgui::Panel::SetAutoResize(
        this: m_pMemory[j],
        pinCorner: PIN_TOPLEFT,
        resizeDir: AUTORESIZE_DOWNANDRIGHT,
        nPinOffsetX: 0,
        nPinOffsetY: 0,
        nUnpinnedCornerOffsetX: 0,
        nUnpinnedCornerOffsetY: 0);
    }
LABEL_39:
    v41 = (vgui::Splitter *)vgui::PHandle::Get(this: p_m_Splitter);
    goto LABEL_29;
  }
  v18 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v18 != nullptr )
    v19 = vgui::Splitter::Splitter(
            this: v18,
            parent: this,
            name: "AnimSetEditorMainSplitter",
            mode: SPLITTER_MODE_VERTICAL,
            nCount: 1);
  else
    v19 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_Splitter, pPanel: v19);
  v20 = vgui::PHandle::Get(this: &this->m_Splitter);
  vgui::Panel::SetAutoResize(
    this: v20,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 38,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  newLayoutd = vgui::PHandle::Get(this: &this->m_Splitter);
  v64 = vgui::Panel::GetTall(this) - 38;
  v21 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: newLayoutd, x: 0, y: 38, wide: v21, tall: v64);
  v22 = (vgui::Splitter *)vgui::PHandle::Get(this: &this->m_Splitter);
  vgui::Splitter::SetSplitterColor(this: v22, c: (Color)-14671840);
  newLayoute = vgui::PHandle::Get(this: v72);
  v23 = vgui::PHandle::Get(this: p_m_Splitter);
  v24 = newLayoute->__vftable;
  v25 = vgui::Panel::GetChild(this: v23, index: 0);
  v24->SetParent_2(this: newLayoute, a2: v25);
  v26 = vgui::PHandle::Get(this: v72);
  vgui::Panel::SetAutoResize(
    this: v26,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  v27 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v27 != nullptr )
  {
    v28 = vgui::PHandle::Get(this: p_m_Splitter);
    v29 = vgui::Panel::GetChild(this: v28, index: 1);
    v30 = vgui::Splitter::Splitter(
            this: v27,
            parent: v29,
            name: "AnimSetEditorSubSplitter",
            mode: SPLITTER_MODE_HORIZONTAL,
            nCount: 1);
  }
  else
  {
    v30 = nullptr;
  }
  vgui::Panel::SetAutoResize(
    this: v30,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  v31 = vgui::PHandle::Get(this: p_m_hPresetFader);
  v32 = v31->__vftable;
  newLayoutf = (CBaseAnimationSetEditor::EAnimSetLayout_t)v31;
  v33 = vgui::Panel::GetChild(this: v30, index: 0);
  v32->SetParent_2(this: (vgui::Panel *)newLayoutf, a2: v33);
  v34 = vgui::PHandle::Get(this: p_m_hPresetFader);
  vgui::Panel::SetAutoResize(
    this: v34,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  v35 = vgui::PHandle::Get(this: p_m_hAttributeSlider);
  v36 = v35->__vftable;
  newLayoutg = (CBaseAnimationSetEditor::EAnimSetLayout_t)v35;
  v37 = vgui::Panel::GetChild(this: v30, index: 1);
  v36->SetParent_2(this: (vgui::Panel *)newLayoutg, a2: v37);
  v38 = vgui::PHandle::Get(this: p_m_hAttributeSlider);
  vgui::Panel::SetAutoResize(
    this: v38,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  if ( v30 != nullptr )
  {
    v39 = v30->__vftable;
    v65 = vgui::Panel::GetTall(this: v30);
    v40 = vgui::Panel::GetWide(this: v30);
    v39->OnSizeChanged(this: v30, a2: v40, a3: v65);
    v41 = v30;
LABEL_29:
    vgui::Splitter::EvenlyRespaceSplitters(this: v41);
  }
  if ( list.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004BCE50
// Name: protected: virtual void CBaseAnimationSetEditor::OnChangeLayout(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::OnChangeLayout(CSequencePicker *this, KeyValues *pData)
{
  this->OnTextKillFocus(this, a2: pData);
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x103A3AF5
// Name: public: virtual void CMFCEditBrowseCtrl::OnChangeLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnChangeLayout(CMFCEditBrowseCtrl *this)
{
  int v2; // eax

  if ( this == nullptr || this->m_hWnd == nullptr )
    AfxThrowInvalidArgException();
  v2 = this->m_sizeImage.cx + 8;
  if ( v2 < 20 )
    v2 = 20;
  this->m_nBrowseButtonWidth = v2;
  CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: 0, y: 0, cx: 0, cy: 0, nFlags: 0x27u);
  if ( this->m_Mode != BrowseMode_None )
  {
    GetWindowRect(hWnd: this->m_hWnd, lpRect: &this->m_rectBtn);
    this->m_rectBtn.left = this->m_rectBtn.right - this->m_nBrowseButtonWidth;
    CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&this->m_rectBtn);
  }
  else
  {
    SetRectEmpty(lprc: &this->m_rectBtn);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048BC40
// Name: public: static char const __near * CBaseAnimationSetEditor::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAnimationSetEditor::GetPanelClassName()
{
  return "CBaseAnimationSetEditor";
}

//------------------------------------------------------------------------------
// Address: 0x1048BC50
// Name: public: virtual CBaseAnimationSetEditor::~CBaseAnimationSetEditor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::~CBaseAnimationSetEditor(CBaseAnimationSetEditor *this)
{
  this->__vftable = (CBaseAnimationSetEditor_vtbl *)&CBaseAnimationSetEditor::`vftable';
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1048BC60
// Name: public: class CBaseAnimationSetControl __near * CBaseAnimationSetEditor::GetController(void)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimationSetControl *__thiscall CBaseAnimationSetEditor::GetController(CBaseAnimationSetEditor *this)
{
  return this->m_pController;
}

//------------------------------------------------------------------------------
// Address: 0x1048BC70
// Name: protected: virtual void CBaseAnimationSetEditor::OnChangeLayout(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::OnChangeLayout(CSequencePicker *this, KeyValues *pData)
{
  this->OnTextKillFocus(this, a2: pData);
}

//------------------------------------------------------------------------------
// Address: 0x1048BC80
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAnimationSetEditor::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAnimationSetEditor::GetMessageMap(CBaseAnimationSetEditor *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAnimationSetEditor::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimationSetEditor::GetMessageMap'::`2'::s_pMap;
  `CBaseAnimationSetEditor::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimationSetEditor");
  `CBaseAnimationSetEditor::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1048BCB0
// Name: public: virtual struct PanelAnimationMap __near * CBaseAnimationSetEditor::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAnimationSetEditor::GetAnimMap(CBaseAnimationSetEditor *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAnimationSetEditor");
}

//------------------------------------------------------------------------------
// Address: 0x1048BCC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAnimationSetEditor::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAnimationSetEditor::GetKBMap(CBaseAnimationSetEditor *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAnimationSetEditor::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimationSetEditor::GetKBMap'::`2'::s_pMap;
  `CBaseAnimationSetEditor::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimationSetEditor");
  `CBaseAnimationSetEditor::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1048BD20
// Name: public: virtual void CBaseAnimationSetEditor::CreateToolsSubPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::CreateToolsSubPanels(CBaseAnimationSetEditor *this)
{
  CBaseAnimSetControlGroupPanel *v2; // eax
  CDragDropHelperPanel *v3; // eax
  CBaseAnimSetPresetFaderPanel *v4; // eax
  CDragDropHelperPanel *v5; // eax
  CBaseAnimSetAttributeSliderPanel *v6; // eax
  CDragDropHelperPanel *v7; // eax

  v2 = (CBaseAnimSetControlGroupPanel *)operator new(nSize: 0x1A4u);
  if ( v2 != nullptr )
    v3 = (CDragDropHelperPanel *)CBaseAnimSetControlGroupPanel::CBaseAnimSetControlGroupPanel(
                                   this: v2,
                                   parent: nullptr,
                                   className: "AnimSetControlGroup",
                                   editor: this,
                                   bControlStateInterface: false);
  else
    v3 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hControlGroup,
    pPanel: v3);
  v4 = (CBaseAnimSetPresetFaderPanel *)operator new(nSize: 0x1C0u);
  if ( v4 != nullptr )
    v5 = (CDragDropHelperPanel *)CBaseAnimSetPresetFaderPanel::CBaseAnimSetPresetFaderPanel(
                                   this: v4,
                                   parent: nullptr,
                                   className: "AnimSetPresetFader",
                                   editor: this);
  else
    v5 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hPresetFader,
    pPanel: v5);
  v6 = (CBaseAnimSetAttributeSliderPanel *)operator new(nSize: 0x1C4u);
  if ( v6 != nullptr )
  {
    v7 = (CDragDropHelperPanel *)CBaseAnimSetAttributeSliderPanel::CBaseAnimSetAttributeSliderPanel(
                                   this: v6,
                                   parent: nullptr,
                                   className: "AnimSetAttributeSliderPanel",
                                   editor: this);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hAttributeSlider,
      pPanel: v7);
  }
  else
  {
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hAttributeSlider,
      pPanel: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048BDD0
// Name: protected: virtual void CBaseAnimationSetEditor::OnOpenContextMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::OnOpenContextMenu(CBaseAnimationSetEditor *this, KeyValues *params)
{
  vgui::Panel *v3; // eax
  vgui::Menu *v4; // eax
  CDragDropHelperPanel *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  vgui::Panel *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // edi
  vgui::Panel *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // edi
  vgui::Panel *v14; // eax
  void *Ptr; // edi
  vgui::Menu *v16; // eax
  vgui::Panel *v17; // eax

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
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "OnChangeLayout", firstKey: "value", firstValue: 0);
  else
    v7 = nullptr;
  v8 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimationSetEditor *, _DWORD))v8->__vftable[1].PaintTraverse)(
    a1: v8,
    a2: "#BxAnimSetSplitLayout",
    a3: v7,
    a4: this,
    a5: 0);
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: "OnChangeLayout", firstKey: "value", firstValue: 1);
  else
    v10 = nullptr;
  v11 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimationSetEditor *, _DWORD))v11->__vftable[1].PaintTraverse)(
    a1: v11,
    a2: "#BxAnimSetVerticalLayout",
    a3: v10,
    a4: this,
    a5: 0);
  v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v12 != nullptr )
    v13 = KeyValues::KeyValues(this: v12, setName: "OnChangeLayout", firstKey: "value", firstValue: 2);
  else
    v13 = nullptr;
  v14 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimationSetEditor *, _DWORD))v14->__vftable[1].PaintTraverse)(
    a1: v14,
    a2: "#BxAnimSetHorizontalLayout",
    a3: v13,
    a4: this,
    a5: 0);
  Ptr = KeyValues::GetPtr(this: params, keyName: "contextlabel", defaultValue: nullptr);
  v16 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
  if ( Ptr != nullptr )
  {
    v16->PerformLayout(this: v16);
    v17 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    ((void (__thiscall *)(vgui::Panel *, void *, int, _DWORD, int))v17->__vftable[1].GetVPanel)(
      a1: v17,
      a2: Ptr,
      a3: 3,
      a4: 0,
      a5: 1);
  }
  else
  {
    vgui::Menu::PlaceContextMenu(a1: 0, parent: this, menu: v16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048BF80
// Name: protected: virtual void CBaseAnimationSetEditor::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::ApplySchemeSettings(CBaseAnimationSetEditor *this, vgui::IScheme *pScheme)
{
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = vgui::PHandle::Get(this: &this->m_hControlGroup);
  if ( v3->GetParent(this: v3) != this )
  {
    v4 = vgui::PHandle::Get(this: &this->m_hControlGroup);
    v4->ApplySchemeSettings(this: v4, a2: pScheme);
  }
  v5 = vgui::PHandle::Get(this: &this->m_hPresetFader);
  if ( v5->GetParent(this: v5) != this )
  {
    v6 = vgui::PHandle::Get(this: &this->m_hPresetFader);
    v6->ApplySchemeSettings(this: v6, a2: pScheme);
  }
  v7 = vgui::PHandle::Get(this: &this->m_hAttributeSlider);
  if ( v7->GetParent(this: v7) != this )
  {
    v8 = vgui::PHandle::Get(this: &this->m_hAttributeSlider);
    v8->ApplySchemeSettings(this: v8, a2: pScheme);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048C040
// Name: public: class CBaseAnimSetPresetFaderPanel __near * CBaseAnimationSetEditor::GetPresetFader(void)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimSetPresetFaderPanel *__thiscall CBaseAnimationSetEditor::GetPresetFader(CBaseAnimationSetEditor *this)
{
  return (CBaseAnimSetPresetFaderPanel *)vgui::PHandle::Get(this: &this->m_hPresetFader);
}

//------------------------------------------------------------------------------
// Address: 0x1048C050
// Name: public: class CBaseAnimSetAttributeSliderPanel __near * CBaseAnimationSetEditor::GetAttributeSlider(void)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimSetAttributeSliderPanel *__thiscall CBaseAnimationSetEditor::GetAttributeSlider(CBaseAnimationSetEditor *this)
{
  return (CBaseAnimSetAttributeSliderPanel *)vgui::PHandle::Get(this: &this->m_hAttributeSlider);
}

//------------------------------------------------------------------------------
// Address: 0x1048C060
// Name: public: void CBaseAnimationSetEditor::ChangeAnimationSetClip(class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::ChangeAnimationSetClip(CBaseAnimationSetEditor *this, CDmeFilmClip *pFilmClip)
{
  CBaseAnimSetControlGroupPanel *v3; // eax
  vgui::Panel *v4; // eax

  this->m_pController->ChangeAnimationSetClip(this: this->m_pController, a2: pFilmClip);
  if ( vgui::PHandle::Get(this: &this->m_hControlGroup) != nullptr )
  {
    v3 = (CBaseAnimSetControlGroupPanel *)vgui::PHandle::Get(this: &this->m_hControlGroup);
    CBaseAnimSetControlGroupPanel::ChangeAnimationSetClip(this: v3, pFilmClip);
  }
  if ( vgui::PHandle::Get(this: &this->m_hAttributeSlider) != nullptr )
  {
    v4 = vgui::PHandle::Get(this: &this->m_hAttributeSlider);
    ((void (__thiscall *)(vgui::Panel *, CDmeFilmClip *))v4->__vftable[1].GetPanel)(a1: v4, a2: pFilmClip);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048C0D0
// Name: public: static void CBaseAnimationSetEditor::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimationSetEditor::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimationSetEditor::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CBaseAnimationSetEditor::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimationSetEditor");
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
// Address: 0x1048C160
// Name: public: static void CBaseAnimationSetEditor::PanelMessageFunc_OnChangeLayout::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimationSetEditor::PanelMessageFunc_OnChangeLayout::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimationSetEditor::PanelMessageFunc_OnChangeLayout::InitVar'::`2'::bAdded )
  {
    `CBaseAnimationSetEditor::PanelMessageFunc_OnChangeLayout::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimationSetEditor");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OnChangeLayout";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "value";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048C200
// Name: public: CBaseAnimationSetEditor::CBaseAnimationSetEditor(class vgui::Panel __near *,char const __near *,class CBaseAnimationSetControl __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimationSetEditor *__thiscall CBaseAnimationSetEditor::CBaseAnimationSetEditor(
        CBaseAnimationSetEditor *this,
        vgui::Panel *parent,
        vgui::Panel *className,
        CBaseAnimationSetControl *pAnimationSetController)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  int _8; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName: (const char *)className);
  this->__vftable = (CBaseAnimationSetEditor_vtbl *)&CBaseAnimationSetEditor::`vftable';
  if ( `CBaseAnimationSetEditor::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimationSetEditor::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimationSetEditor");
    v5->pfnClassName = CBaseAnimationSetEditor::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAnimationSetEditor::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAnimationSetEditor::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CBaseAnimationSetEditor");
    v6->pfnClassName = CBaseAnimationSetEditor::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAnimationSetEditor::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimationSetEditor::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimationSetEditor");
    v7->pfnClassName = CBaseAnimationSetEditor::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CBaseAnimationSetEditor::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&_8);
  CBaseAnimationSetEditor::PanelMessageFunc_OnChangeLayout::InitVar(a1: (int)&_8);
  this->m_Layout = LAYOUT_SPLIT;
  this->m_Splitter.m_iPanelID = -1;
  this->m_hControlGroup.m_iPanelID = -1;
  this->m_hPresetFader.m_iPanelID = -1;
  this->m_hAttributeSlider.m_iPanelID = -1;
  this->m_hContextMenu.m_iPanelID = -1;
  this->m_pController = pAnimationSetController;
  pAnimationSetController->m_pEditor = this;
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v9 = KeyValues::KeyValues(this: v8, setName: "OnChangeLayout", firstKey: "value", firstValue: this->m_Layout);
  else
    v9 = nullptr;
  vgui::Panel::PostMessage(this, target: this->_vpanel, message: v9, delaySeconds: 0.0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1048C340
// Name: public: virtual void CBaseAnimationSetEditor::ChangeLayout(enum CBaseAnimationSetEditor::EAnimSetLayout_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::ChangeLayout(
        CBaseAnimationSetEditor *this,
        CBaseAnimationSetEditor::EAnimSetLayout_t newLayout)
{
  vgui::DHANDLE<CBaseAnimSetControlGroupPanel> *p_m_hControlGroup; // ebx
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::DHANDLE<vgui::Splitter> *p_m_Splitter; // esi
  vgui::Panel *v8; // eax
  vgui::Panel **m_pMemory; // ebx
  int m_Size; // eax
  int v11; // ecx
  int v12; // eax
  vgui::Panel **v13; // eax
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  vgui::Panel **v17; // eax
  vgui::Splitter *v18; // eax
  CDragDropHelperPanel *v19; // eax
  vgui::Panel *v20; // eax
  int v21; // eax
  vgui::Splitter *v22; // eax
  vgui::Panel *v23; // eax
  vgui::Panel_vtbl *v24; // edi
  vgui::Panel *v25; // eax
  vgui::Panel *v26; // eax
  vgui::Splitter *v27; // edi
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Splitter *v30; // esi
  vgui::Panel *v31; // eax
  vgui::Panel_vtbl *v32; // edi
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  vgui::Panel_vtbl *v36; // edi
  vgui::Panel *v37; // eax
  vgui::Panel *v38; // eax
  vgui::Splitter_vtbl *v39; // edi
  int v40; // eax
  vgui::Splitter *v41; // ecx
  vgui::Splitter *v42; // eax
  CDragDropHelperPanel *v43; // eax
  vgui::Splitter *v44; // eax
  vgui::Panel *v45; // eax
  int v46; // eax
  int j; // edi
  vgui::Panel *v48; // eax
  vgui::Panel *v49; // eax
  vgui::Panel *v50; // eax
  vgui::Panel *v51; // eax
  int v52; // eax
  vgui::Splitter *v53; // eax
  CDragDropHelperPanel *v54; // eax
  vgui::Splitter *v55; // eax
  vgui::Panel *v56; // eax
  int Wide; // eax
  int i; // edi
  vgui::Panel *v59; // eax
  vgui::Panel *Child; // eax
  vgui::Panel *v61; // eax
  vgui::Panel *v62; // eax
  int v63; // eax
  int v64; // [esp-4h] [ebp-34h]
  int v65; // [esp-4h] [ebp-34h]
  int v66; // [esp-4h] [ebp-34h]
  int v67; // [esp-4h] [ebp-34h]
  int v68; // [esp-4h] [ebp-34h]
  int Tall; // [esp-4h] [ebp-34h]
  CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > list; // [esp+Ch] [ebp-24h] BYREF
  vgui::Panel *v71; // [esp+20h] [ebp-10h]
  vgui::PHandle *v72; // [esp+24h] [ebp-Ch]
  vgui::PHandle *p_m_hAttributeSlider; // [esp+28h] [ebp-8h]
  vgui::PHandle *p_m_hPresetFader; // [esp+2Ch] [ebp-4h]
  vgui::Panel *newLayouta; // [esp+38h] [ebp+8h]
  CBaseAnimationSetEditor::EAnimSetLayout_t newLayoutb; // [esp+38h] [ebp+8h]
  CBaseAnimationSetEditor::EAnimSetLayout_t newLayoutc; // [esp+38h] [ebp+8h]
  vgui::Panel *newLayoutd; // [esp+38h] [ebp+8h]
  vgui::Panel *newLayoute; // [esp+38h] [ebp+8h]
  CBaseAnimationSetEditor::EAnimSetLayout_t newLayoutf; // [esp+38h] [ebp+8h]
  CBaseAnimationSetEditor::EAnimSetLayout_t newLayoutg; // [esp+38h] [ebp+8h]
  vgui::Panel *newLayouth; // [esp+38h] [ebp+8h]
  CBaseAnimationSetEditor::EAnimSetLayout_t newLayouti; // [esp+38h] [ebp+8h]
  vgui::Panel *newLayoutj; // [esp+38h] [ebp+8h]
  vgui::Panel *newLayoutk; // [esp+38h] [ebp+8h]
  CBaseAnimationSetEditor::EAnimSetLayout_t newLayoutl; // [esp+38h] [ebp+8h]
  vgui::Panel *newLayoutm; // [esp+38h] [ebp+8h]

  p_m_hControlGroup = &this->m_hControlGroup;
  this->m_Layout = newLayout;
  v72 = &this->m_hControlGroup;
  v4 = vgui::PHandle::Get(this: &this->m_hControlGroup);
  v4->SetParent_2(this: v4, a2: nullptr);
  p_m_hPresetFader = &this->m_hPresetFader;
  v5 = vgui::PHandle::Get(this: &this->m_hPresetFader);
  v5->SetParent_2(this: v5, a2: nullptr);
  p_m_hAttributeSlider = &this->m_hAttributeSlider;
  v6 = vgui::PHandle::Get(this: &this->m_hAttributeSlider);
  v6->SetParent_2(this: v6, a2: nullptr);
  p_m_Splitter = &this->m_Splitter;
  v8 = vgui::PHandle::Get(this: &this->m_Splitter);
  if ( v8 != nullptr )
    ((void (__thiscall *)(vgui::Panel *, int))v8->dtr_Panel)(a1: v8, a2: 1);
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_Splitter,
    pPanel: nullptr);
  memset(&list, 0, sizeof(list));
  newLayouta = vgui::PHandle::Get(this: p_m_hControlGroup);
  CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&list, num: 1);
  m_pMemory = list.m_Memory.m_pMemory;
  ++list.m_Size;
  list.m_pElements = list.m_Memory.m_pMemory;
  if ( list.m_Size - 1 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)list.m_Memory.m_pMemory + 4,
      src: (unsigned __int8 *)list.m_Memory.m_pMemory,
      count: 4 * (list.m_Size - 1));
  if ( m_pMemory != nullptr )
    *m_pMemory = newLayouta;
  v71 = vgui::PHandle::Get(this: p_m_hPresetFader);
  m_Size = list.m_Size;
  v11 = list.m_Size;
  newLayoutb = list.m_Size;
  if ( list.m_Size + 1 > list.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&list,
      num: list.m_Size - list.m_Memory.m_nAllocationCount + 1);
    m_pMemory = list.m_Memory.m_pMemory;
    v11 = newLayoutb;
    m_Size = list.m_Size;
  }
  list.m_Size = m_Size + 1;
  v12 = m_Size - v11;
  list.m_pElements = m_pMemory;
  if ( v12 > 0 )
  {
    _V_memmove(dest: (unsigned __int8 *)&m_pMemory[v11 + 1], src: (unsigned __int8 *)&m_pMemory[v11], count: 4 * v12);
    v11 = newLayoutb;
  }
  v13 = &m_pMemory[v11];
  if ( v13 != nullptr )
    *v13 = v71;
  v71 = vgui::PHandle::Get(this: p_m_hAttributeSlider);
  v14 = list.m_Size;
  v15 = list.m_Size;
  newLayoutc = list.m_Size;
  if ( list.m_Size + 1 > list.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&list,
      num: list.m_Size - list.m_Memory.m_nAllocationCount + 1);
    m_pMemory = list.m_Memory.m_pMemory;
    v15 = newLayoutc;
    v14 = list.m_Size;
  }
  list.m_Size = v14 + 1;
  v16 = v14 - v15;
  if ( v16 > 0 )
  {
    _V_memmove(dest: (unsigned __int8 *)&m_pMemory[v15 + 1], src: (unsigned __int8 *)&m_pMemory[v15], count: 4 * v16);
    v15 = newLayoutc;
  }
  v17 = &m_pMemory[v15];
  if ( v17 != nullptr )
    *v17 = v71;
  if ( this->m_Layout == LAYOUT_VERTICAL )
  {
    v53 = (vgui::Splitter *)operator new(nSize: 0x198u);
    if ( v53 != nullptr )
      v54 = (CDragDropHelperPanel *)vgui::Splitter::Splitter(
                                      this: v53,
                                      parent: this,
                                      name: "AnimSetEditorMainSplitter",
                                      mode: SPLITTER_MODE_VERTICAL,
                                      nCount: 2);
    else
      v54 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_Splitter,
      pPanel: v54);
    v55 = (vgui::Splitter *)vgui::PHandle::Get(this: &this->m_Splitter);
    vgui::Splitter::SetSplitterColor(this: v55, c: (Color)-14671840);
    v56 = vgui::PHandle::Get(this: &this->m_Splitter);
    vgui::Panel::SetAutoResize(
      this: v56,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 0,
      nPinOffsetY: 38,
      nUnpinnedCornerOffsetX: 0,
      nUnpinnedCornerOffsetY: 0);
    newLayoutk = vgui::PHandle::Get(this: &this->m_Splitter);
    v68 = vgui::Panel::GetTall(this) - 38;
    Wide = vgui::Panel::GetWide(this);
    vgui::Panel::SetBounds(this: newLayoutk, x: 0, y: 38, wide: Wide, tall: v68);
    for ( i = 0; i < list.m_Size; ++i )
    {
      newLayoutl = (CBaseAnimationSetEditor::EAnimSetLayout_t)m_pMemory[i];
      v59 = vgui::PHandle::Get(this: p_m_Splitter);
      v71 = (vgui::Panel *)(*(_DWORD *)newLayoutl + 168);
      Child = vgui::Panel::GetChild(this: v59, index: i);
      ((void (__thiscall *)(CBaseAnimationSetEditor::EAnimSetLayout_t, vgui::Panel *))v71->__vftable)(
        a1: newLayoutl,
        a2: Child);
      newLayoutm = vgui::PHandle::Get(this: p_m_Splitter);
      v71 = vgui::PHandle::Get(this: p_m_Splitter);
      v61 = vgui::Panel::GetChild(this: newLayoutm, index: i);
      Tall = vgui::Panel::GetTall(this: v61);
      v62 = vgui::Panel::GetChild(this: v71, index: i);
      v63 = vgui::Panel::GetWide(this: v62);
      vgui::Panel::SetSize(this: m_pMemory[i], wide: v63, tall: Tall);
      vgui::Panel::SetAutoResize(
        this: m_pMemory[i],
        pinCorner: PIN_TOPLEFT,
        resizeDir: AUTORESIZE_DOWNANDRIGHT,
        nPinOffsetX: 0,
        nPinOffsetY: 0,
        nUnpinnedCornerOffsetX: 0,
        nUnpinnedCornerOffsetY: 0);
    }
    goto LABEL_39;
  }
  if ( this->m_Layout == LAYOUT_HORIZONTAL )
  {
    v42 = (vgui::Splitter *)operator new(nSize: 0x198u);
    if ( v42 != nullptr )
      v43 = (CDragDropHelperPanel *)vgui::Splitter::Splitter(
                                      this: v42,
                                      parent: this,
                                      name: "AnimSetEditorMainSplitter",
                                      mode: SPLITTER_MODE_HORIZONTAL,
                                      nCount: 2);
    else
      v43 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(
      this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_Splitter,
      pPanel: v43);
    v44 = (vgui::Splitter *)vgui::PHandle::Get(this: &this->m_Splitter);
    vgui::Splitter::SetSplitterColor(this: v44, c: (Color)-14671840);
    v45 = vgui::PHandle::Get(this: &this->m_Splitter);
    vgui::Panel::SetAutoResize(
      this: v45,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 0,
      nPinOffsetY: 38,
      nUnpinnedCornerOffsetX: 0,
      nUnpinnedCornerOffsetY: 0);
    newLayouth = vgui::PHandle::Get(this: &this->m_Splitter);
    v66 = vgui::Panel::GetTall(this) - 38;
    v46 = vgui::Panel::GetWide(this);
    vgui::Panel::SetBounds(this: newLayouth, x: 0, y: 38, wide: v46, tall: v66);
    for ( j = 0; j < list.m_Size; ++j )
    {
      newLayouti = (CBaseAnimationSetEditor::EAnimSetLayout_t)m_pMemory[j];
      v48 = vgui::PHandle::Get(this: p_m_Splitter);
      v71 = (vgui::Panel *)(*(_DWORD *)newLayouti + 168);
      v49 = vgui::Panel::GetChild(this: v48, index: j);
      ((void (__thiscall *)(CBaseAnimationSetEditor::EAnimSetLayout_t, vgui::Panel *))v71->__vftable)(
        a1: newLayouti,
        a2: v49);
      newLayoutj = vgui::PHandle::Get(this: p_m_Splitter);
      v71 = vgui::PHandle::Get(this: p_m_Splitter);
      v50 = vgui::Panel::GetChild(this: newLayoutj, index: j);
      v67 = vgui::Panel::GetTall(this: v50);
      v51 = vgui::Panel::GetChild(this: v71, index: j);
      v52 = vgui::Panel::GetWide(this: v51);
      vgui::Panel::SetSize(this: m_pMemory[j], wide: v52, tall: v67);
      vgui::Panel::SetAutoResize(
        this: m_pMemory[j],
        pinCorner: PIN_TOPLEFT,
        resizeDir: AUTORESIZE_DOWNANDRIGHT,
        nPinOffsetX: 0,
        nPinOffsetY: 0,
        nUnpinnedCornerOffsetX: 0,
        nUnpinnedCornerOffsetY: 0);
    }
LABEL_39:
    v41 = (vgui::Splitter *)vgui::PHandle::Get(this: p_m_Splitter);
    goto LABEL_29;
  }
  v18 = (vgui::Splitter *)operator new(nSize: 0x198u);
  if ( v18 != nullptr )
    v19 = (CDragDropHelperPanel *)vgui::Splitter::Splitter(
                                    this: v18,
                                    parent: this,
                                    name: "AnimSetEditorMainSplitter",
                                    mode: SPLITTER_MODE_VERTICAL,
                                    nCount: 1);
  else
    v19 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_Splitter,
    pPanel: v19);
  v20 = vgui::PHandle::Get(this: &this->m_Splitter);
  vgui::Panel::SetAutoResize(
    this: v20,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 38,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  newLayoutd = vgui::PHandle::Get(this: &this->m_Splitter);
  v64 = vgui::Panel::GetTall(this) - 38;
  v21 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: newLayoutd, x: 0, y: 38, wide: v21, tall: v64);
  v22 = (vgui::Splitter *)vgui::PHandle::Get(this: &this->m_Splitter);
  vgui::Splitter::SetSplitterColor(this: v22, c: (Color)-14671840);
  newLayoute = vgui::PHandle::Get(this: v72);
  v23 = vgui::PHandle::Get(this: p_m_Splitter);
  v24 = newLayoute->__vftable;
  v25 = vgui::Panel::GetChild(this: v23, index: 0);
  v24->SetParent_2(this: newLayoute, a2: v25);
  v26 = vgui::PHandle::Get(this: v72);
  vgui::Panel::SetAutoResize(
    this: v26,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  v27 = (vgui::Splitter *)operator new(nSize: 0x198u);
  if ( v27 != nullptr )
  {
    v28 = vgui::PHandle::Get(this: p_m_Splitter);
    v29 = vgui::Panel::GetChild(this: v28, index: 1);
    v30 = vgui::Splitter::Splitter(
            this: v27,
            parent: v29,
            name: "AnimSetEditorSubSplitter",
            mode: SPLITTER_MODE_HORIZONTAL,
            nCount: 1);
  }
  else
  {
    v30 = nullptr;
  }
  vgui::Panel::SetAutoResize(
    this: v30,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  v31 = vgui::PHandle::Get(this: p_m_hPresetFader);
  v32 = v31->__vftable;
  newLayoutf = (CBaseAnimationSetEditor::EAnimSetLayout_t)v31;
  v33 = vgui::Panel::GetChild(this: v30, index: 0);
  v32->SetParent_2(this: (vgui::Panel *)newLayoutf, a2: v33);
  v34 = vgui::PHandle::Get(this: p_m_hPresetFader);
  vgui::Panel::SetAutoResize(
    this: v34,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  v35 = vgui::PHandle::Get(this: p_m_hAttributeSlider);
  v36 = v35->__vftable;
  newLayoutg = (CBaseAnimationSetEditor::EAnimSetLayout_t)v35;
  v37 = vgui::Panel::GetChild(this: v30, index: 1);
  v36->SetParent_2(this: (vgui::Panel *)newLayoutg, a2: v37);
  v38 = vgui::PHandle::Get(this: p_m_hAttributeSlider);
  vgui::Panel::SetAutoResize(
    this: v38,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  if ( v30 != nullptr )
  {
    v39 = v30->__vftable;
    v65 = vgui::Panel::GetTall(this: v30);
    v40 = vgui::Panel::GetWide(this: v30);
    v39->OnSizeChanged(this: v30, a2: v40, a3: v65);
    v41 = v30;
LABEL_29:
    vgui::Splitter::EvenlyRespaceSplitters(this: v41);
  }
  if ( list.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x103A3B68
// Name: protected: void CMFCEditBrowseCtrl::OnNcMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnNcMouseMove(CMFCEditBrowseCtrl *this, unsigned int nHitTest, CPoint point)
{
  HWND v4; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-1Ch]
  CPoint ptClient; // [esp+4h] [ebp-8h] BYREF

  if ( this->m_bIsButtonCaptured == 0 )
  {
    ptClient = point;
    ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptClient);
    if ( PtInRect(lprc: &this->m_rectBtn, pt: ptClient.tagPOINT) )
    {
      v4 = SetCapture(hWnd: this->m_hWnd);
      CWnd::FromHandle(hWnd: v4);
      m_hWnd = this->m_hWnd;
      this->m_bIsButtonHighlighted = 1;
      RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x401u);
    }
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A3BDF
// Name: protected: void CMFCEditBrowseCtrl::OnCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnCancelMode(CMFCEditBrowseCtrl *this)
{
  HWND__ *m_hWnd; // [esp-10h] [ebp-14h]

  CWnd::Default(this);
  if ( CWnd::IsWindowEnabled(this) != 0 )
    ReleaseCapture();
  m_hWnd = this->m_hWnd;
  this->m_bIsButtonPressed = 0;
  this->m_bIsButtonCaptured = 0;
  this->m_bIsButtonHighlighted = 0;
  RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x401u);
}

//------------------------------------------------------------------------------
// Address: 0x103A3C1A
// Name: protected: void CMFCEditBrowseCtrl::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnLButtonDown(CMFCEditBrowseCtrl *this, unsigned int nFlags, CPoint point)
{
  HWND v4; // eax
  HWND__ *m_hWnd; // [esp-4h] [ebp-8h]

  if ( this->m_Mode != BrowseMode_None && PtInRect(lprc: &this->m_rectBtn, pt: point.tagPOINT) )
  {
    CWnd::SetFocus(this);
    m_hWnd = this->m_hWnd;
    this->m_bIsButtonPressed = 1;
    this->m_bIsButtonCaptured = 1;
    v4 = SetCapture(hWnd: m_hWnd);
    CWnd::FromHandle(hWnd: v4);
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x401u);
  }
  else
  {
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A3C84
// Name: protected: void CMFCEditBrowseCtrl::OnRButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnRButtonUp(CMFCEditBrowseCtrl *this, unsigned int nFlags, CPoint point)
{
  if ( this->m_Mode == BrowseMode_None || !PtInRect(lprc: &this->m_rectBtn, pt: point.tagPOINT) )
    CWnd::Default(this);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004820B0
// Name: public: static char const __near * CBaseAnimationSetEditor::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAnimationSetEditor::GetPanelClassName()
{
  return "CBaseAnimationSetEditor";
}

//------------------------------------------------------------------------------
// Address: 0x004820C0
// Name: public: virtual CBaseAnimationSetEditor::~CBaseAnimationSetEditor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::~CBaseAnimationSetEditor(CBaseAnimationSetEditor *this)
{
  this->__vftable = (CBaseAnimationSetEditor_vtbl *)&CBaseAnimationSetEditor::`vftable';
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x004820D0
// Name: public: class CBaseAnimationSetControl __near * CBaseAnimationSetEditor::GetController(void)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimationSetControl *__thiscall CBaseAnimationSetEditor::GetController(CBaseAnimationSetEditor *this)
{
  return this->m_pController;
}

//------------------------------------------------------------------------------
// Address: 0x004820E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAnimationSetEditor::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAnimationSetEditor::GetMessageMap(CBaseAnimationSetEditor *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAnimationSetEditor::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimationSetEditor::GetMessageMap'::`2'::s_pMap;
  `CBaseAnimationSetEditor::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimationSetEditor");
  `CBaseAnimationSetEditor::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00482110
// Name: public: virtual struct PanelAnimationMap __near * CBaseAnimationSetEditor::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAnimationSetEditor::GetAnimMap(CBaseAnimationSetEditor *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAnimationSetEditor");
}

//------------------------------------------------------------------------------
// Address: 0x00482120
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAnimationSetEditor::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAnimationSetEditor::GetKBMap(CBaseAnimationSetEditor *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAnimationSetEditor::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimationSetEditor::GetKBMap'::`2'::s_pMap;
  `CBaseAnimationSetEditor::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimationSetEditor");
  `CBaseAnimationSetEditor::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00482180
// Name: public: virtual void CBaseAnimationSetEditor::CreateToolsSubPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::CreateToolsSubPanels(CBaseAnimationSetEditor *this)
{
  CBaseAnimSetControlGroupPanel *v2; // eax
  CBaseAnimSetControlGroupPanel *v3; // eax
  CBaseAnimSetPresetFaderPanel *v4; // eax
  CBaseAnimSetPresetFaderPanel *v5; // eax
  CBaseAnimSetAttributeSliderPanel *v6; // eax
  CBaseAnimSetAttributeSliderPanel *v7; // eax

  v2 = (CBaseAnimSetControlGroupPanel *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v2 != nullptr )
    v3 = CBaseAnimSetControlGroupPanel::CBaseAnimSetControlGroupPanel(
           this: v2,
           parent: nullptr,
           className: "AnimSetControlGroup",
           editor: this,
           bControlStateInterface: false);
  else
    v3 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hControlGroup, pPanel: v3);
  v4 = (CBaseAnimSetPresetFaderPanel *)MemAlloc_Alloc(nSize: 0x1C0u);
  if ( v4 != nullptr )
    v5 = CBaseAnimSetPresetFaderPanel::CBaseAnimSetPresetFaderPanel(
           this: v4,
           parent: nullptr,
           className: "AnimSetPresetFader",
           editor: this);
  else
    v5 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hPresetFader, pPanel: v5);
  v6 = (CBaseAnimSetAttributeSliderPanel *)MemAlloc_Alloc(nSize: 0x1C4u);
  if ( v6 != nullptr )
  {
    v7 = CBaseAnimSetAttributeSliderPanel::CBaseAnimSetAttributeSliderPanel(
           this: v6,
           parent: nullptr,
           className: "AnimSetAttributeSliderPanel",
           editor: this);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hAttributeSlider, pPanel: v7);
  }
  else
  {
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hAttributeSlider, pPanel: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482230
// Name: protected: virtual void CBaseAnimationSetEditor::OnOpenContextMenu(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::OnOpenContextMenu(CBaseAnimationSetEditor *this, KeyValues *params)
{
  vgui::Panel *v3; // eax
  vgui::Menu *v4; // eax
  vgui::Menu *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  vgui::Panel *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // edi
  vgui::Panel *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // edi
  vgui::Panel *v14; // eax
  void *Ptr; // edi
  vgui::Menu *v16; // eax
  vgui::Panel *v17; // eax

  if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
  {
    v3 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    if ( v3 != nullptr )
      ((void (__thiscall *)(vgui::Panel *, int))v3->dtr_Panel)(a1: v3, a2: 1);
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
  }
  v4 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v4 != nullptr )
    v5 = vgui::Menu::Menu(this: v4, parent: this, panelName: "ActionMenu");
  else
    v5 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: v5);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "OnChangeLayout", firstKey: "value", firstValue: 0);
  else
    v7 = nullptr;
  v8 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimationSetEditor *, _DWORD))v8->__vftable[1].PaintTraverse)(
    a1: v8,
    a2: "#BxAnimSetSplitLayout",
    a3: v7,
    a4: this,
    a5: 0);
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: "OnChangeLayout", firstKey: "value", firstValue: 1);
  else
    v10 = nullptr;
  v11 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimationSetEditor *, _DWORD))v11->__vftable[1].PaintTraverse)(
    a1: v11,
    a2: "#BxAnimSetVerticalLayout",
    a3: v10,
    a4: this,
    a5: 0);
  v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v12 != nullptr )
    v13 = KeyValues::KeyValues(this: v12, setName: "OnChangeLayout", firstKey: "value", firstValue: 2);
  else
    v13 = nullptr;
  v14 = vgui::PHandle::Get(this: &this->m_hContextMenu);
  ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CBaseAnimationSetEditor *, _DWORD))v14->__vftable[1].PaintTraverse)(
    a1: v14,
    a2: "#BxAnimSetHorizontalLayout",
    a3: v13,
    a4: this,
    a5: 0);
  Ptr = KeyValues::GetPtr(this: params, keyName: "contextlabel", defaultValue: nullptr);
  v16 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
  if ( Ptr != nullptr )
  {
    v16->PerformLayout(this: v16);
    v17 = vgui::PHandle::Get(this: &this->m_hContextMenu);
    ((void (__thiscall *)(vgui::Panel *, void *, int, _DWORD, int))v17->__vftable[1].GetVPanel)(
      a1: v17,
      a2: Ptr,
      a3: 3,
      a4: 0,
      a5: 1);
  }
  else
  {
    vgui::Menu::PlaceContextMenu(parent: this, menu: v16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004823E0
// Name: protected: virtual void CBaseAnimationSetEditor::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::ApplySchemeSettings(CBaseAnimationSetEditor *this, vgui::IScheme *pScheme)
{
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v3 = vgui::PHandle::Get(this: &this->m_hControlGroup);
  if ( v3->GetParent(this: v3) != this )
  {
    v4 = vgui::PHandle::Get(this: &this->m_hControlGroup);
    v4->ApplySchemeSettings(this: v4, a2: pScheme);
  }
  v5 = vgui::PHandle::Get(this: &this->m_hPresetFader);
  if ( v5->GetParent(this: v5) != this )
  {
    v6 = vgui::PHandle::Get(this: &this->m_hPresetFader);
    v6->ApplySchemeSettings(this: v6, a2: pScheme);
  }
  v7 = vgui::PHandle::Get(this: &this->m_hAttributeSlider);
  if ( v7->GetParent(this: v7) != this )
  {
    v8 = vgui::PHandle::Get(this: &this->m_hAttributeSlider);
    v8->ApplySchemeSettings(this: v8, a2: pScheme);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004824A0
// Name: public: class CBaseAnimSetPresetFaderPanel __near * CBaseAnimationSetEditor::GetPresetFader(void)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimSetPresetFaderPanel *__thiscall CBaseAnimationSetEditor::GetPresetFader(CBaseAnimationSetEditor *this)
{
  return (CBaseAnimSetPresetFaderPanel *)vgui::PHandle::Get(this: &this->m_hPresetFader);
}

//------------------------------------------------------------------------------
// Address: 0x004824B0
// Name: public: class CBaseAnimSetAttributeSliderPanel __near * CBaseAnimationSetEditor::GetAttributeSlider(void)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimSetAttributeSliderPanel *__thiscall CBaseAnimationSetEditor::GetAttributeSlider(CBaseAnimationSetEditor *this)
{
  return (CBaseAnimSetAttributeSliderPanel *)vgui::PHandle::Get(this: &this->m_hAttributeSlider);
}

//------------------------------------------------------------------------------
// Address: 0x004824C0
// Name: public: void CBaseAnimationSetEditor::ChangeAnimationSetClip(class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::ChangeAnimationSetClip(CBaseAnimationSetEditor *this, CDmeFilmClip *pFilmClip)
{
  CBaseAnimSetControlGroupPanel *v3; // eax
  vgui::Panel *v4; // eax

  this->m_pController->ChangeAnimationSetClip(this: this->m_pController, a2: pFilmClip);
  if ( vgui::PHandle::Get(this: &this->m_hControlGroup) != nullptr )
  {
    v3 = (CBaseAnimSetControlGroupPanel *)vgui::PHandle::Get(this: &this->m_hControlGroup);
    CBaseAnimSetControlGroupPanel::ChangeAnimationSetClip(this: v3, pFilmClip);
  }
  if ( vgui::PHandle::Get(this: &this->m_hAttributeSlider) != nullptr )
  {
    v4 = vgui::PHandle::Get(this: &this->m_hAttributeSlider);
    ((void (__thiscall *)(vgui::Panel *, CDmeFilmClip *))v4->__vftable[1].GetPanel)(a1: v4, a2: pFilmClip);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482530
// Name: public: static void CBaseAnimationSetEditor::PanelMessageFunc_OnOpenContextMenu::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimationSetEditor::PanelMessageFunc_OnOpenContextMenu::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimationSetEditor::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded )
  {
    `CBaseAnimationSetEditor::PanelMessageFunc_OnOpenContextMenu::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimationSetEditor");
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
// Address: 0x004825C0
// Name: public: static void CBaseAnimationSetEditor::PanelMessageFunc_OnChangeLayout::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBaseAnimationSetEditor::PanelMessageFunc_OnChangeLayout::InitVar(int a1@<ebp>)
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
  if ( !`CBaseAnimationSetEditor::PanelMessageFunc_OnChangeLayout::InitVar'::`2'::bAdded )
  {
    `CBaseAnimationSetEditor::PanelMessageFunc_OnChangeLayout::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBaseAnimationSetEditor");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "OnChangeLayout";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "value";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00482660
// Name: public: CBaseAnimationSetEditor::CBaseAnimationSetEditor(class vgui::Panel __near *,char const __near *,class CBaseAnimationSetControl __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimationSetEditor *__thiscall CBaseAnimationSetEditor::CBaseAnimationSetEditor(
        CBaseAnimationSetEditor *this,
        vgui::Panel *parent,
        const char *className,
        CBaseAnimationSetControl *pAnimationSetController)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName: className);
  this->__vftable = (CBaseAnimationSetEditor_vtbl *)&CBaseAnimationSetEditor::`vftable';
  if ( `CBaseAnimationSetEditor::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimationSetEditor::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimationSetEditor");
    v5->pfnClassName = CBaseAnimationSetEditor::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAnimationSetEditor::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAnimationSetEditor::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CBaseAnimationSetEditor");
    v6->pfnClassName = CBaseAnimationSetEditor::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAnimationSetEditor::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimationSetEditor::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimationSetEditor");
    v7->pfnClassName = CBaseAnimationSetEditor::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CBaseAnimationSetEditor::PanelMessageFunc_OnOpenContextMenu::InitVar(a1: (int)&savedregs);
  CBaseAnimationSetEditor::PanelMessageFunc_OnChangeLayout::InitVar(a1: (int)&savedregs);
  this->m_Layout = LAYOUT_SPLIT;
  this->m_Splitter.m_iPanelID = -1;
  this->m_hControlGroup.m_iPanelID = -1;
  this->m_hPresetFader.m_iPanelID = -1;
  this->m_hAttributeSlider.m_iPanelID = -1;
  this->m_hContextMenu.m_iPanelID = -1;
  this->m_pController = pAnimationSetController;
  pAnimationSetController->m_pEditor = this;
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v9 = KeyValues::KeyValues(this: v8, setName: "OnChangeLayout", firstKey: "value", firstValue: this->m_Layout);
  else
    v9 = nullptr;
  vgui::Panel::PostMessage(this, target: this->_vpanel, message: v9, delaySeconds: 0.0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004827A0
// Name: public: virtual void CBaseAnimationSetEditor::ChangeLayout(enum CBaseAnimationSetEditor::EAnimSetLayout_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::ChangeLayout(
        CBaseAnimationSetEditor *this,
        CBaseAnimationSetEditor::EAnimSetLayout_t newLayout)
{
  vgui::DHANDLE<CBaseAnimSetControlGroupPanel> *p_m_hControlGroup; // ebx
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  vgui::DHANDLE<vgui::Splitter> *p_m_Splitter; // esi
  vgui::Panel *v8; // eax
  vgui::Panel **m_pMemory; // ebx
  int m_Size; // eax
  int v11; // ecx
  int v12; // eax
  vgui::Panel **v13; // eax
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  vgui::Panel **v17; // eax
  vgui::Splitter *v18; // eax
  vgui::Splitter *v19; // eax
  vgui::Panel *v20; // eax
  int v21; // eax
  vgui::Splitter *v22; // eax
  vgui::Panel *v23; // eax
  vgui::Panel_vtbl *v24; // edi
  vgui::Panel *v25; // eax
  vgui::Panel *v26; // eax
  vgui::Splitter *v27; // edi
  vgui::Panel *v28; // eax
  vgui::Panel *v29; // eax
  vgui::Splitter *v30; // esi
  vgui::Panel *v31; // eax
  vgui::Panel_vtbl *v32; // edi
  vgui::Panel *v33; // eax
  vgui::Panel *v34; // eax
  vgui::Panel *v35; // eax
  vgui::Panel_vtbl *v36; // edi
  vgui::Panel *v37; // eax
  vgui::Panel *v38; // eax
  vgui::Splitter_vtbl *v39; // edi
  int v40; // eax
  vgui::Splitter *v41; // ecx
  vgui::Splitter *v42; // eax
  vgui::Splitter *v43; // eax
  vgui::Splitter *v44; // eax
  vgui::Panel *v45; // eax
  int v46; // eax
  int j; // edi
  vgui::Panel *v48; // eax
  vgui::Panel *v49; // eax
  vgui::Panel *v50; // eax
  vgui::Panel *v51; // eax
  int v52; // eax
  vgui::Splitter *v53; // eax
  vgui::Splitter *v54; // eax
  vgui::Splitter *v55; // eax
  vgui::Panel *v56; // eax
  int Wide; // eax
  int i; // edi
  vgui::Panel *v59; // eax
  vgui::Panel *Child; // eax
  vgui::Panel *v61; // eax
  vgui::Panel *v62; // eax
  int v63; // eax
  int v64; // [esp-4h] [ebp-34h]
  int v65; // [esp-4h] [ebp-34h]
  int v66; // [esp-4h] [ebp-34h]
  int v67; // [esp-4h] [ebp-34h]
  int v68; // [esp-4h] [ebp-34h]
  int Tall; // [esp-4h] [ebp-34h]
  CUtlVector<vgui::Panel *,CUtlMemory<vgui::Panel *,int> > list; // [esp+Ch] [ebp-24h] BYREF
  vgui::Panel *v71; // [esp+20h] [ebp-10h]
  vgui::PHandle *v72; // [esp+24h] [ebp-Ch]
  vgui::PHandle *p_m_hAttributeSlider; // [esp+28h] [ebp-8h]
  vgui::PHandle *p_m_hPresetFader; // [esp+2Ch] [ebp-4h]
  vgui::Panel *newLayouta; // [esp+38h] [ebp+8h]
  CBaseAnimationSetEditor::EAnimSetLayout_t newLayoutb; // [esp+38h] [ebp+8h]
  CBaseAnimationSetEditor::EAnimSetLayout_t newLayoutc; // [esp+38h] [ebp+8h]
  vgui::Panel *newLayoutd; // [esp+38h] [ebp+8h]
  vgui::Panel *newLayoute; // [esp+38h] [ebp+8h]
  CBaseAnimationSetEditor::EAnimSetLayout_t newLayoutf; // [esp+38h] [ebp+8h]
  CBaseAnimationSetEditor::EAnimSetLayout_t newLayoutg; // [esp+38h] [ebp+8h]
  vgui::Panel *newLayouth; // [esp+38h] [ebp+8h]
  CBaseAnimationSetEditor::EAnimSetLayout_t newLayouti; // [esp+38h] [ebp+8h]
  vgui::Panel *newLayoutj; // [esp+38h] [ebp+8h]
  vgui::Panel *newLayoutk; // [esp+38h] [ebp+8h]
  CBaseAnimationSetEditor::EAnimSetLayout_t newLayoutl; // [esp+38h] [ebp+8h]
  vgui::Panel *newLayoutm; // [esp+38h] [ebp+8h]

  p_m_hControlGroup = &this->m_hControlGroup;
  this->m_Layout = newLayout;
  v72 = &this->m_hControlGroup;
  v4 = vgui::PHandle::Get(this: &this->m_hControlGroup);
  v4->SetParent_2(this: v4, a2: nullptr);
  p_m_hPresetFader = &this->m_hPresetFader;
  v5 = vgui::PHandle::Get(this: &this->m_hPresetFader);
  v5->SetParent_2(this: v5, a2: nullptr);
  p_m_hAttributeSlider = &this->m_hAttributeSlider;
  v6 = vgui::PHandle::Get(this: &this->m_hAttributeSlider);
  v6->SetParent_2(this: v6, a2: nullptr);
  p_m_Splitter = &this->m_Splitter;
  v8 = vgui::PHandle::Get(this: &this->m_Splitter);
  if ( v8 != nullptr )
    ((void (__thiscall *)(vgui::Panel *, int))v8->dtr_Panel)(a1: v8, a2: 1);
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_Splitter, pPanel: nullptr);
  memset(&list, 0, sizeof(list));
  newLayouta = vgui::PHandle::Get(this: p_m_hControlGroup);
  CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&list, num: 1);
  m_pMemory = list.m_Memory.m_pMemory;
  ++list.m_Size;
  list.m_pElements = list.m_Memory.m_pMemory;
  if ( list.m_Size - 1 > 0 )
    _V_memmove(dest: list.m_Memory.m_pMemory + 1, src: list.m_Memory.m_pMemory, count: 4 * (list.m_Size - 1));
  if ( m_pMemory != nullptr )
    *m_pMemory = newLayouta;
  v71 = vgui::PHandle::Get(this: p_m_hPresetFader);
  m_Size = list.m_Size;
  v11 = list.m_Size;
  newLayoutb = list.m_Size;
  if ( list.m_Size + 1 > list.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&list,
      num: list.m_Size - list.m_Memory.m_nAllocationCount + 1);
    m_pMemory = list.m_Memory.m_pMemory;
    v11 = newLayoutb;
    m_Size = list.m_Size;
  }
  list.m_Size = m_Size + 1;
  v12 = m_Size - v11;
  list.m_pElements = m_pMemory;
  if ( v12 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v11 + 1], src: &m_pMemory[v11], count: 4 * v12);
    v11 = newLayoutb;
  }
  v13 = &m_pMemory[v11];
  if ( v13 != nullptr )
    *v13 = v71;
  v71 = vgui::PHandle::Get(this: p_m_hAttributeSlider);
  v14 = list.m_Size;
  v15 = list.m_Size;
  newLayoutc = list.m_Size;
  if ( list.m_Size + 1 > list.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&list,
      num: list.m_Size - list.m_Memory.m_nAllocationCount + 1);
    m_pMemory = list.m_Memory.m_pMemory;
    v15 = newLayoutc;
    v14 = list.m_Size;
  }
  list.m_Size = v14 + 1;
  v16 = v14 - v15;
  if ( v16 > 0 )
  {
    _V_memmove(dest: &m_pMemory[v15 + 1], src: &m_pMemory[v15], count: 4 * v16);
    v15 = newLayoutc;
  }
  v17 = &m_pMemory[v15];
  if ( v17 != nullptr )
    *v17 = v71;
  if ( this->m_Layout == LAYOUT_VERTICAL )
  {
    v53 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
    if ( v53 != nullptr )
      v54 = vgui::Splitter::Splitter(
              this: v53,
              parent: this,
              name: "AnimSetEditorMainSplitter",
              mode: SPLITTER_MODE_VERTICAL,
              nCount: 2);
    else
      v54 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_Splitter, pPanel: v54);
    v55 = (vgui::Splitter *)vgui::PHandle::Get(this: &this->m_Splitter);
    vgui::Splitter::SetSplitterColor(this: v55, c: (Color)-14671840);
    v56 = vgui::PHandle::Get(this: &this->m_Splitter);
    vgui::Panel::SetAutoResize(
      this: v56,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 0,
      nPinOffsetY: 38,
      nUnpinnedCornerOffsetX: 0,
      nUnpinnedCornerOffsetY: 0);
    newLayoutk = vgui::PHandle::Get(this: &this->m_Splitter);
    v68 = vgui::Panel::GetTall(this) - 38;
    Wide = vgui::Panel::GetWide(this);
    vgui::Panel::SetBounds(this: newLayoutk, x: 0, y: 38, wide: Wide, tall: v68);
    for ( i = 0; i < list.m_Size; ++i )
    {
      newLayoutl = (CBaseAnimationSetEditor::EAnimSetLayout_t)m_pMemory[i];
      v59 = vgui::PHandle::Get(this: p_m_Splitter);
      v71 = (vgui::Panel *)(*(_DWORD *)newLayoutl + 168);
      Child = vgui::Panel::GetChild(this: v59, index: i);
      ((void (__thiscall *)(CBaseAnimationSetEditor::EAnimSetLayout_t, vgui::Panel *))v71->__vftable)(
        a1: newLayoutl,
        a2: Child);
      newLayoutm = vgui::PHandle::Get(this: p_m_Splitter);
      v71 = vgui::PHandle::Get(this: p_m_Splitter);
      v61 = vgui::Panel::GetChild(this: newLayoutm, index: i);
      Tall = vgui::Panel::GetTall(this: v61);
      v62 = vgui::Panel::GetChild(this: v71, index: i);
      v63 = vgui::Panel::GetWide(this: v62);
      vgui::Panel::SetSize(this: m_pMemory[i], wide: v63, tall: Tall);
      vgui::Panel::SetAutoResize(
        this: m_pMemory[i],
        pinCorner: PIN_TOPLEFT,
        resizeDir: AUTORESIZE_DOWNANDRIGHT,
        nPinOffsetX: 0,
        nPinOffsetY: 0,
        nUnpinnedCornerOffsetX: 0,
        nUnpinnedCornerOffsetY: 0);
    }
    goto LABEL_39;
  }
  if ( this->m_Layout == LAYOUT_HORIZONTAL )
  {
    v42 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
    if ( v42 != nullptr )
      v43 = vgui::Splitter::Splitter(
              this: v42,
              parent: this,
              name: "AnimSetEditorMainSplitter",
              mode: SPLITTER_MODE_HORIZONTAL,
              nCount: 2);
    else
      v43 = nullptr;
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_Splitter, pPanel: v43);
    v44 = (vgui::Splitter *)vgui::PHandle::Get(this: &this->m_Splitter);
    vgui::Splitter::SetSplitterColor(this: v44, c: (Color)-14671840);
    v45 = vgui::PHandle::Get(this: &this->m_Splitter);
    vgui::Panel::SetAutoResize(
      this: v45,
      pinCorner: PIN_TOPLEFT,
      resizeDir: AUTORESIZE_DOWNANDRIGHT,
      nPinOffsetX: 0,
      nPinOffsetY: 38,
      nUnpinnedCornerOffsetX: 0,
      nUnpinnedCornerOffsetY: 0);
    newLayouth = vgui::PHandle::Get(this: &this->m_Splitter);
    v66 = vgui::Panel::GetTall(this) - 38;
    v46 = vgui::Panel::GetWide(this);
    vgui::Panel::SetBounds(this: newLayouth, x: 0, y: 38, wide: v46, tall: v66);
    for ( j = 0; j < list.m_Size; ++j )
    {
      newLayouti = (CBaseAnimationSetEditor::EAnimSetLayout_t)m_pMemory[j];
      v48 = vgui::PHandle::Get(this: p_m_Splitter);
      v71 = (vgui::Panel *)(*(_DWORD *)newLayouti + 168);
      v49 = vgui::Panel::GetChild(this: v48, index: j);
      ((void (__thiscall *)(CBaseAnimationSetEditor::EAnimSetLayout_t, vgui::Panel *))v71->__vftable)(
        a1: newLayouti,
        a2: v49);
      newLayoutj = vgui::PHandle::Get(this: p_m_Splitter);
      v71 = vgui::PHandle::Get(this: p_m_Splitter);
      v50 = vgui::Panel::GetChild(this: newLayoutj, index: j);
      v67 = vgui::Panel::GetTall(this: v50);
      v51 = vgui::Panel::GetChild(this: v71, index: j);
      v52 = vgui::Panel::GetWide(this: v51);
      vgui::Panel::SetSize(this: m_pMemory[j], wide: v52, tall: v67);
      vgui::Panel::SetAutoResize(
        this: m_pMemory[j],
        pinCorner: PIN_TOPLEFT,
        resizeDir: AUTORESIZE_DOWNANDRIGHT,
        nPinOffsetX: 0,
        nPinOffsetY: 0,
        nUnpinnedCornerOffsetX: 0,
        nUnpinnedCornerOffsetY: 0);
    }
LABEL_39:
    v41 = (vgui::Splitter *)vgui::PHandle::Get(this: p_m_Splitter);
    goto LABEL_29;
  }
  v18 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v18 != nullptr )
    v19 = vgui::Splitter::Splitter(
            this: v18,
            parent: this,
            name: "AnimSetEditorMainSplitter",
            mode: SPLITTER_MODE_VERTICAL,
            nCount: 1);
  else
    v19 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_Splitter, pPanel: v19);
  v20 = vgui::PHandle::Get(this: &this->m_Splitter);
  vgui::Panel::SetAutoResize(
    this: v20,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 38,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  newLayoutd = vgui::PHandle::Get(this: &this->m_Splitter);
  v64 = vgui::Panel::GetTall(this) - 38;
  v21 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: newLayoutd, x: 0, y: 38, wide: v21, tall: v64);
  v22 = (vgui::Splitter *)vgui::PHandle::Get(this: &this->m_Splitter);
  vgui::Splitter::SetSplitterColor(this: v22, c: (Color)-14671840);
  newLayoute = vgui::PHandle::Get(this: v72);
  v23 = vgui::PHandle::Get(this: p_m_Splitter);
  v24 = newLayoute->__vftable;
  v25 = vgui::Panel::GetChild(this: v23, index: 0);
  v24->SetParent_2(this: newLayoute, a2: v25);
  v26 = vgui::PHandle::Get(this: v72);
  vgui::Panel::SetAutoResize(
    this: v26,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  v27 = (vgui::Splitter *)MemAlloc_Alloc(nSize: 0x198u);
  if ( v27 != nullptr )
  {
    v28 = vgui::PHandle::Get(this: p_m_Splitter);
    v29 = vgui::Panel::GetChild(this: v28, index: 1);
    v30 = vgui::Splitter::Splitter(
            this: v27,
            parent: v29,
            name: "AnimSetEditorSubSplitter",
            mode: SPLITTER_MODE_HORIZONTAL,
            nCount: 1);
  }
  else
  {
    v30 = nullptr;
  }
  vgui::Panel::SetAutoResize(
    this: v30,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  v31 = vgui::PHandle::Get(this: p_m_hPresetFader);
  v32 = v31->__vftable;
  newLayoutf = (CBaseAnimationSetEditor::EAnimSetLayout_t)v31;
  v33 = vgui::Panel::GetChild(this: v30, index: 0);
  v32->SetParent_2(this: (vgui::Panel *)newLayoutf, a2: v33);
  v34 = vgui::PHandle::Get(this: p_m_hPresetFader);
  vgui::Panel::SetAutoResize(
    this: v34,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  v35 = vgui::PHandle::Get(this: p_m_hAttributeSlider);
  v36 = v35->__vftable;
  newLayoutg = (CBaseAnimationSetEditor::EAnimSetLayout_t)v35;
  v37 = vgui::Panel::GetChild(this: v30, index: 1);
  v36->SetParent_2(this: (vgui::Panel *)newLayoutg, a2: v37);
  v38 = vgui::PHandle::Get(this: p_m_hAttributeSlider);
  vgui::Panel::SetAutoResize(
    this: v38,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  if ( v30 != nullptr )
  {
    v39 = v30->__vftable;
    v65 = vgui::Panel::GetTall(this: v30);
    v40 = vgui::Panel::GetWide(this: v30);
    v39->OnSizeChanged(this: v30, a2: v40, a3: v65);
    v41 = v30;
LABEL_29:
    vgui::Splitter::EvenlyRespaceSplitters(this: v41);
  }
  if ( list.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004D1400
// Name: protected: virtual void CBaseAnimationSetEditor::OnChangeLayout(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimationSetEditor::OnChangeLayout(CSequencePicker *this, KeyValues *pData)
{
  this->OnTextKillFocus(this, a2: pData);
}

} // namespace sceneviewer
