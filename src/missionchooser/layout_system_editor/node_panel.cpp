// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/layout_system_editor/node_panel.cpp
// Functions: 32
// ============================================================

#include "missionchooser\layout_system_editor\node_panel.h"

//------------------------------------------------------------------------------
// Address: 0x1001FF60
// Name: public: static char const __near * CNodePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CNodePanel::GetPanelClassName()
{
  return "CNodePanel";
}

//------------------------------------------------------------------------------
// Address: 0x1001FF70
// Name: public: static char const __near * CNewElementPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CNewElementPanel::GetPanelClassName()
{
  return "CNewElementPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1001FF80
// Name: public: virtual void CNodePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodePanel::ApplySchemeSettings(CNodePanel *this, vgui::IScheme *pScheme)
{
  CNodePanel_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "RaisedBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1001FFC0
// Name: public: virtual void CNodePanel::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodePanel::OnTextChanged(CNodePanel *this, vgui::Panel *pPanel)
{
  void (__thiscall *SetNodeName)(CNodePanel *, const char *); // edx
  char buf[2048]; // [esp+4h] [ebp-800h] BYREF

  this->m_pNameEditBox->GetText_2(this: this->m_pNameEditBox, a2: buf, a3: 2048);
  SetNodeName = this->SetNodeName;
  buf[2047] = 0;
  SetNodeName(this, a2: buf);
}

//------------------------------------------------------------------------------
// Address: 0x10020010
// Name: protected: virtual void CNodePanel::SetNodeName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodePanel::SetNodeName(CNodePanel *this, const char *pNodeName)
{
  KeyValues *m_pNodeKV; // ecx

  m_pNodeKV = this->m_pNodeKV;
  if ( m_pNodeKV != nullptr )
    KeyValues::SetString(this: m_pNodeKV, keyName: "name", value: pNodeName);
}

//------------------------------------------------------------------------------
// Address: 0x10020040
// Name: protected: void CNodePanel::AddHeadingElement(class vgui::Panel __near *,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodePanel::AddHeadingElement(
        CNodePanel *this,
        vgui::Panel *pPanel,
        unsigned int flExpandFactor,
        unsigned int nPadding)
{
  vgui::CBoxSizer *m_pHeadingSizer; // ecx
  vgui::SizerAddArgs_t args; // [esp+0h] [ebp-18h] BYREF

  args.m_nMinX = -1;
  args.m_nMinY = -1;
  m_pHeadingSizer = this->m_pHeadingSizer;
  args.m_bMinorExpand = true;
  args.m_bIgnoreMemberMin = false;
  *(_QWORD *)&args.m_flExpandFactor = __PAIR64__(nPadding, flExpandFactor);
  vgui::CSizerBase::InsertPanel(this: m_pHeadingSizer, nIndex: m_pHeadingSizer->m_Members.m_Size, pPanel, &args);
  if ( this->m_pEditor != nullptr )
    this->m_pEditor->InvalidateLayout(this: this->m_pEditor, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100200B0
// Name: protected: void CNodePanel::AddHeadingSpacer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodePanel::AddHeadingSpacer(CNodePanel *this)
{
  vgui::CBoxSizer *m_pHeadingSizer; // ecx
  vgui::SizerAddArgs_t args; // [esp+0h] [ebp-18h] BYREF

  m_pHeadingSizer = this->m_pHeadingSizer;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bMinorExpand = true;
  args.m_bIgnoreMemberMin = false;
  args.m_nPadding = 0;
  args.m_flExpandFactor = 1.0;
  vgui::CSizerBase::InsertSpacer(this: m_pHeadingSizer, nIndex: m_pHeadingSizer->m_Members.m_Size, &args);
  if ( this->m_pEditor != nullptr )
    this->m_pEditor->InvalidateLayout(this: this->m_pEditor, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10020120
// Name: protected: void CNodePanel::AddChild(class vgui::Panel __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodePanel::AddChild(CNodePanel *this, vgui::Panel *pPanel, int nPadding)
{
  vgui::CBoxSizer *m_pChildSizer; // ecx
  vgui::SizerAddArgs_t args; // [esp+0h] [ebp-18h] BYREF

  args.m_nMinX = -1;
  args.m_nMinY = -1;
  m_pChildSizer = this->m_pChildSizer;
  args.m_nPadding = nPadding;
  args.m_flExpandFactor = 0.0;
  args.m_bMinorExpand = true;
  args.m_bIgnoreMemberMin = false;
  vgui::CSizerBase::InsertPanel(this: m_pChildSizer, nIndex: m_pChildSizer->m_Members.m_Size, pPanel, &args);
  if ( this->m_pEditor != nullptr )
    this->m_pEditor->InvalidateLayout(this: this->m_pEditor, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10020190
// Name: public: CNewElementPanel::CNewElementPanel(class vgui::Panel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CNewElementPanel *__thiscall CNewElementPanel::CNewElementPanel(
        CNewElementPanel *this,
        vgui::Panel *pParent,
        const char *pName,
        int nIndex)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::CBoxSizer *v8; // eax
  vgui::CBoxSizer *v9; // eax

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CNewElementPanel_vtbl *)&CNewElementPanel::`vftable';
  if ( `CNewElementPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CNewElementPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CNewElementPanel");
    v5->pfnClassName = CNewElementPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CNewElementPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CNewElementPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CNewElementPanel");
    v6->pfnClassName = CNewElementPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CNewElementPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CNewElementPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CNewElementPanel");
    v7->pfnClassName = CNewElementPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_nIndex = nIndex;
  v8 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v8 != nullptr )
    v9 = vgui::CBoxSizer::CBoxSizer(this: v8, LayoutDirection: ESLD_HORIZONTAL);
  else
    v9 = nullptr;
  this->m_pHorizontalSizer = v9;
  vgui::Panel::SetSizer(this, pSizer: v9);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10020280
// Name: public: virtual struct vgui::PanelMessageMap __near * CNewElementPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CNewElementPanel::GetMessageMap(CNewElementPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CNewElementPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CNewElementPanel::GetMessageMap'::`2'::s_pMap;
  `CNewElementPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CNewElementPanel");
  `CNewElementPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100202B0
// Name: public: virtual struct PanelAnimationMap __near * CNewElementPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CNewElementPanel::GetAnimMap(CNewElementPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CNewElementPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100202C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CNewElementPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CNewElementPanel::GetKBMap(CNewElementPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CNewElementPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CNewElementPanel::GetKBMap'::`2'::s_pMap;
  `CNewElementPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CNewElementPanel");
  `CNewElementPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100202F0
// Name: public: void CNewElementPanel::AddButton(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewElementPanel::AddButton(CNewElementPanel *this, const char *pButtonText, KeyValues *pActionName)
{
  vgui::Button *v4; // edi
  vgui::Panel *v5; // eax
  vgui::Button *v6; // edi
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // ebx
  vgui::CBoxSizer *m_pHorizontalSizer; // ecx
  vgui::SizerAddArgs_t args; // [esp+Ch] [ebp-18h] BYREF
  KeyValues *pMessageKV; // [esp+30h] [ebp+Ch]

  v4 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v4 != nullptr )
  {
    v5 = this->GetParent(this);
    v6 = vgui::Button::Button(
           this: v4,
           parent: this,
           panelName: (const char *)pActionName,
           text: pButtonText,
           pActionSignalTarget: v5,
           pCmd: (const char *)pActionName);
  }
  else
  {
    v6 = nullptr;
  }
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    pMessageKV = KeyValues::KeyValues(this: v7, setName: (const char *)pActionName);
  else
    pMessageKV = nullptr;
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v9 = KeyValues::KeyValues(this: v8, setName: "index");
  else
    v9 = nullptr;
  KeyValues::SetInt(this: v9, keyName: nullptr, value: this->m_nIndex);
  KeyValues::AddSubKey(this: pMessageKV, pSubkey: v9);
  v6->SetCommand(this: v6, a2: pMessageKV);
  m_pHorizontalSizer = this->m_pHorizontalSizer;
  args.m_flExpandFactor = 0.0;
  args.m_bMinorExpand = true;
  args.m_bIgnoreMemberMin = false;
  args.m_nMinX = 50;
  args.m_nMinY = 20;
  args.m_nPadding = 0;
  vgui::CSizerBase::InsertPanel(
    this: m_pHorizontalSizer,
    nIndex: m_pHorizontalSizer->m_Members.m_Size,
    pPanel: v6,
    &args);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x100203F0
// Name: public: virtual void CNodePanel::UpdateState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodePanel::UpdateState(CNodePanel *this)
{
  vgui::Label_vtbl *v2; // edx
  vgui::CBoxSizer *m_pChildSizer; // ecx
  int i; // edi
  vgui::Panel *Panel; // eax
  void *v6; // eax
  int j; // edi
  CNodePanel *v8; // ecx
  int v9; // [esp+0h] [ebp-8h]

  v2 = this->m_pLabel->__vftable;
  if ( this->m_NodeLabel[0] != 0 )
  {
    ((void (__stdcall *)(char *, int))v2->SetText)(a1: this->m_NodeLabel, a2: v9);
    this->m_pLabel->SetVisible(this: this->m_pLabel, a2: true);
  }
  else
  {
    ((void (__stdcall *)(const char *, int))v2->SetText)(a1: szDescription, a2: v9);
    this->m_pLabel->SetVisible(this: this->m_pLabel, a2: false);
  }
  if ( this->m_bShowNameEditBox )
    this->m_pNameEditBox->SetText(this: this->m_pNameEditBox, a2: this->m_NodeName);
  this->m_pNameEditBox->SetVisible(this: this->m_pNameEditBox, a2: this->m_bShowNameEditBox);
  this->m_pDeleteSelfButton->SetVisible(this: this->m_pDeleteSelfButton, a2: this->m_bShowDeleteButton);
  m_pChildSizer = this->m_pChildSizer;
  for ( i = 0; i < m_pChildSizer->m_Members.m_Size; ++i )
  {
    if ( vgui::CSizerBase::GetElementType(this: m_pChildSizer, i) == ESET_PANEL )
    {
      Panel = vgui::CSizerBase::GetPanel(this: this->m_pChildSizer, i);
      v6 = __RTDynamicCast(
             inptr: Panel,
             VfDelta: 0,
             SrcType: &vgui::Panel `RTTI Type Descriptor',
             TargetType: &CNewElementPanel `RTTI Type Descriptor',
             isReference: 0);
      if ( v6 != nullptr )
        (*(void (__thiscall **)(void *, bool))(*(_DWORD *)v6 + 132))(a1: v6, a2: this->m_pEditor->m_bShowAddButtons);
    }
    m_pChildSizer = this->m_pChildSizer;
  }
  for ( j = 0; j < this->m_ChildPanels.m_Size; ++j )
  {
    v8 = this->m_ChildPanels.m_Memory.m_pMemory[j];
    v8->UpdateState(this: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020520
// Name: protected: void CNodePanel::SetChildIndent(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodePanel::SetChildIndent(CNodePanel *this, int nIndent)
{
  vgui::CBoxSizer *m_pChildIndentSizer; // edx
  vgui::SizerAddArgs_t args; // [esp+0h] [ebp-18h] BYREF

  m_pChildIndentSizer = this->m_pChildIndentSizer;
  args.m_flExpandFactor = 0.0;
  args.m_bMinorExpand = true;
  args.m_bIgnoreMemberMin = false;
  args.m_nMinX = nIndent;
  args.m_nMinY = 0;
  args.m_nPadding = 0;
  vgui::CSizerBase::CSizerMember::Fill(this: m_pChildIndentSizer->m_Members.m_Memory.m_pMemory, &args);
  if ( this->m_pEditor != nullptr )
    this->m_pEditor->InvalidateLayout(this: this->m_pEditor, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10020590
// Name: protected: void CNodePanel::AddNewElementPanel(int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodePanel::AddNewElementPanel(CNodePanel *this, int nIndex, bool bAllowRules, bool bAllowStates)
{
  CNewElementPanel *v5; // eax
  CNewElementPanel *v6; // edi
  vgui::CBoxSizer *m_pChildSizer; // ecx
  vgui::SizerAddArgs_t args; // [esp+8h] [ebp-18h] BYREF

  v5 = (CNewElementPanel *)operator new(nSize: 0x188u);
  if ( v5 != nullptr )
    v6 = CNewElementPanel::CNewElementPanel(this: v5, pParent: this, pName: "NewElement", nIndex);
  else
    v6 = nullptr;
  if ( bAllowRules )
    CNewElementPanel::AddButton(this: v6, pButtonText: "Add Rule", pActionName: (KeyValues *)"AddRule");
  if ( bAllowStates )
    CNewElementPanel::AddButton(this: v6, pButtonText: "Add State", pActionName: (KeyValues *)"AddState");
  m_pChildSizer = this->m_pChildSizer;
  args.m_flExpandFactor = 0.0;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  args.m_nPadding = 5;
  vgui::CSizerBase::InsertPanel(this: m_pChildSizer, nIndex: m_pChildSizer->m_Members.m_Size, pPanel: v6, &args);
  if ( this->m_pEditor != nullptr )
    this->m_pEditor->InvalidateLayout(this: this->m_pEditor, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10020650
// Name: public: void CNodePanel::RecreateControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodePanel::RecreateControls(CNodePanel *this)
{
  vgui::CSizerBase::RemoveAllMembers(this: this->m_pHeadingSizer, bDelete: true);
  if ( this->m_pEditor != nullptr )
    this->m_pEditor->InvalidateLayout(this: this->m_pEditor, a2: false, a3: false);
  this->m_ChildPanels.m_Size = 0;
  vgui::CSizerBase::RemoveAllMembers(this: this->m_pChildSizer, bDelete: true);
  if ( this->m_pEditor != nullptr )
    this->m_pEditor->InvalidateLayout(this: this->m_pEditor, a2: false, a3: false);
  this->CreatePanelContents(this);
  this->UpdateState(this);
}

//------------------------------------------------------------------------------
// Address: 0x100206D0
// Name: protected: void CNodePanel::InsertChildData(int,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodePanel::InsertChildData(CNodePanel *this, int nIndex, KeyValues *pKeyValues)
{
  KeyValues::InsertSubKey(this: this->m_pNodeKV, nIndex, pSubKey: pKeyValues);
  CNodePanel::RecreateControls(this);
}

//------------------------------------------------------------------------------
// Address: 0x10020700
// Name: protected: void CNodePanel::DeleteSelf(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodePanel::DeleteSelf(CNodePanel *this)
{
  vgui::Panel *v2; // eax
  CNodePanel *v3; // edi

  v2 = this->GetParent(this);
  v3 = (CNodePanel *)__RTDynamicCast(
                       inptr: v2,
                       VfDelta: 0,
                       SrcType: &vgui::Panel `RTTI Type Descriptor',
                       TargetType: &CNodePanel `RTTI Type Descriptor',
                       isReference: 0);
  KeyValues::RemoveSubKey(this: v3->m_pNodeKV, subKey: this->m_pNodeKV);
  KeyValues::deleteThis(this: this->m_pNodeKV);
  this->m_pNodeKV = nullptr;
  CNodePanel::RecreateControls(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10020760
// Name: public: static void CNodePanel::PanelMessageFunc_OnAddRule::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CNodePanel::PanelMessageFunc_OnAddRule::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CNodePanel::PanelMessageFunc_OnAddRule::InitVar'::`2'::bAdded )
  {
    `CNodePanel::PanelMessageFunc_OnAddRule::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::TextEntry::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CNodePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "AddRule";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100207F0
// Name: public: static void CNodePanel::PanelMessageFunc_OnAddState::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CNodePanel::PanelMessageFunc_OnAddState::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CNodePanel::PanelMessageFunc_OnAddState::InitVar'::`2'::bAdded )
  {
    `CNodePanel::PanelMessageFunc_OnAddState::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CKV_Node_Panel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CNodePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "AddState";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020880
// Name: public: static void CNodePanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CNodePanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CNodePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CNodePanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CTilegenKVEditorPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CNodePanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "TextChanged";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020920
// Name: public: CNodePanel::CNodePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNodePanel *__thiscall CNodePanel::CNodePanel(CNodePanel *this, vgui::Panel *pParent, const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Label *v7; // eax
  vgui::Label *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::CBoxSizer *v11; // eax
  vgui::CBoxSizer *v12; // eax
  vgui::CBoxSizer *v13; // eax
  vgui::CBoxSizer *v14; // eax
  vgui::Label *m_pLabel; // edx
  vgui::CBoxSizer *m_pLabelSizer; // ecx
  vgui::TextEntry *m_pNameEditBox; // eax
  vgui::CBoxSizer *m_pRootSizer; // ecx
  vgui::CBoxSizer *v19; // edx
  vgui::CBoxSizer *v20; // eax
  vgui::CBoxSizer *v21; // eax
  vgui::CBoxSizer *v22; // ecx
  vgui::Button *v23; // eax
  vgui::Button *v24; // eax
  vgui::CBoxSizer *v25; // ecx
  vgui::CBoxSizer *v26; // eax
  vgui::CBoxSizer *v27; // eax
  vgui::CBoxSizer *v28; // eax
  vgui::CBoxSizer *v29; // eax
  vgui::CBoxSizer *m_pChildIndentSizer; // ecx
  vgui::CBoxSizer *m_pChildSizer; // edx
  vgui::CBoxSizer *v32; // ecx
  vgui::CBoxSizer *v33; // eax
  vgui::SizerAddArgs_t args; // [esp+Ch] [ebp-18h] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CNodePanel_vtbl *)&CNodePanel::`vftable';
  if ( `CNodePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CNodePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CNodePanel");
    v4->pfnClassName = CNodePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CNodePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CNodePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CNodePanel");
    v5->pfnClassName = CNodePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CNodePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CNodePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CNodePanel");
    v6->pfnClassName = CNodePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CNodePanel::PanelMessageFunc_OnAddRule::InitVar(a1: (int)&savedregs);
  CNodePanel::PanelMessageFunc_OnAddState::InitVar(a1: (int)&savedregs);
  CNodePanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  this->m_pNodeKV = nullptr;
  this->m_pEditor = nullptr;
  *(_WORD *)&this->m_bShowNameEditBox = 0;
  this->m_ChildPanels.m_Memory.m_pMemory = nullptr;
  this->m_ChildPanels.m_Memory.m_nAllocationCount = 0;
  this->m_ChildPanels.m_Memory.m_nGrowSize = 0;
  this->m_ChildPanels.m_Size = 0;
  this->m_ChildPanels.m_pElements = nullptr;
  v7 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v7 != nullptr )
    v8 = vgui::Label::Label(this: v7, parent: this, panelName: "Label", text: szDescription);
  else
    v8 = nullptr;
  this->m_pLabel = v8;
  v8->SetMouseInputEnabled(this: v8, a2: false);
  v9 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v9 != nullptr )
    v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "TextEntry");
  else
    v10 = nullptr;
  this->m_pNameEditBox = v10;
  this->m_NodeLabel[0] = 0;
  this->m_NodeName[0] = 0;
  v11 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v11 != nullptr )
    v12 = vgui::CBoxSizer::CBoxSizer(this: v11, LayoutDirection: ESLD_VERTICAL);
  else
    v12 = nullptr;
  this->m_pRootSizer = v12;
  v13 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v13 != nullptr )
    v14 = vgui::CBoxSizer::CBoxSizer(this: v13, LayoutDirection: ESLD_HORIZONTAL);
  else
    v14 = nullptr;
  m_pLabel = this->m_pLabel;
  this->m_pLabelSizer = v14;
  args.m_flExpandFactor = 0.0;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  args.m_nPadding = 2;
  vgui::CSizerBase::InsertPanel(this: v14, nIndex: v14->m_Members.m_Size, pPanel: m_pLabel, &args);
  m_pLabelSizer = this->m_pLabelSizer;
  m_pNameEditBox = this->m_pNameEditBox;
  args.m_flExpandFactor = 0.0;
  args.m_bMinorExpand = true;
  args.m_bIgnoreMemberMin = false;
  args.m_nPadding = 2;
  args.m_nMinX = 200;
  args.m_nMinY = 20;
  vgui::CSizerBase::InsertPanel(
    this: m_pLabelSizer,
    nIndex: m_pLabelSizer->m_Members.m_Size,
    pPanel: m_pNameEditBox,
    &args);
  m_pRootSizer = this->m_pRootSizer;
  v19 = this->m_pLabelSizer;
  args.m_flExpandFactor = 0.0;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  args.m_nPadding = 5;
  vgui::CSizerBase::InsertSizer(this: m_pRootSizer, nIndex: m_pRootSizer->m_Members.m_Size, pSizer: v19, &args);
  v20 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v20 != nullptr )
    v21 = vgui::CBoxSizer::CBoxSizer(this: v20, LayoutDirection: ESLD_HORIZONTAL);
  else
    v21 = nullptr;
  v22 = this->m_pLabelSizer;
  this->m_pHeadingSizer = v21;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  args.m_nPadding = 0;
  args.m_flExpandFactor = 1.0;
  vgui::CSizerBase::InsertSizer(this: v22, nIndex: v22->m_Members.m_Size, pSizer: v21, &args);
  v23 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v23 != nullptr )
    v24 = vgui::Button::Button(
            this: v23,
            parent: this,
            panelName: "DeleteSelf",
            text: "X",
            pActionSignalTarget: this,
            pCmd: "DeleteSelf");
  else
    v24 = nullptr;
  v25 = this->m_pLabelSizer;
  this->m_pDeleteSelfButton = v24;
  args.m_flExpandFactor = 0.0;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  args.m_nPadding = 2;
  vgui::CSizerBase::InsertPanel(this: v25, nIndex: v25->m_Members.m_Size, pPanel: v24, &args);
  v26 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v26 != nullptr )
    v27 = vgui::CBoxSizer::CBoxSizer(this: v26, LayoutDirection: ESLD_VERTICAL);
  else
    v27 = nullptr;
  this->m_pChildSizer = v27;
  v28 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v28 != nullptr )
    v29 = vgui::CBoxSizer::CBoxSizer(this: v28, LayoutDirection: ESLD_HORIZONTAL);
  else
    v29 = nullptr;
  this->m_pChildIndentSizer = v29;
  args.m_flExpandFactor = 0.0;
  args.m_bMinorExpand = true;
  memset(&args.m_nMinX, 0, 9);
  args.m_nPadding = 0;
  vgui::CSizerBase::InsertSpacer(this: v29, nIndex: v29->m_Members.m_Size, &args);
  m_pChildIndentSizer = this->m_pChildIndentSizer;
  m_pChildSizer = this->m_pChildSizer;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  args.m_nPadding = 0;
  args.m_flExpandFactor = 1.0;
  vgui::CSizerBase::InsertSizer(
    this: m_pChildIndentSizer,
    nIndex: m_pChildIndentSizer->m_Members.m_Size,
    pSizer: m_pChildSizer,
    &args);
  v32 = this->m_pRootSizer;
  v33 = this->m_pChildIndentSizer;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  args.m_nPadding = 0;
  args.m_flExpandFactor = 1.0;
  vgui::CSizerBase::InsertSizer(this: v32, nIndex: v32->m_Members.m_Size, pSizer: v33, &args);
  vgui::Panel::SetSizer(this, pSizer: this->m_pRootSizer);
  this->m_pLabel->SetPaintBackgroundEnabled(this: this->m_pLabel, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10020D30
// Name: public: virtual struct vgui::PanelMessageMap __near * CNodePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CNodePanel::GetMessageMap(CNodePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CNodePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CNodePanel::GetMessageMap'::`2'::s_pMap;
  `CNodePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CNodePanel");
  `CNodePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10020D60
// Name: public: virtual struct PanelAnimationMap __near * CNodePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CNodePanel::GetAnimMap(CNodePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CNodePanel");
}

//------------------------------------------------------------------------------
// Address: 0x10020D70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CNodePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CNodePanel::GetKBMap(CNodePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CNodePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CNodePanel::GetKBMap'::`2'::s_pMap;
  `CNodePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CNodePanel");
  `CNodePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10020DA0
// Name: public: virtual void CNodePanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodePanel::OnCommand(CNodePanel *this, const char *pCommand)
{
  if ( _V_stricmp(s1: pCommand, s2: "DeleteSelf") != 0 )
    vgui::Panel::OnCommand(this, command: pCommand);
  else
    CNodePanel::DeleteSelf(this);
}

//------------------------------------------------------------------------------
// Address: 0x10020DE0
// Name: public: virtual void CNodePanel::OnAddRule(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodePanel::OnAddRule(CNodePanel *this, KeyValues *pKV)
{
  int Int; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  Int = KeyValues::GetInt(this: pKV, keyName: "index", defaultValue: -1);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "rule_instance", firstKey: nullptr, firstValue: "<null>");
  else
    v5 = nullptr;
  KeyValues::InsertSubKey(this: this->m_pNodeKV, nIndex: Int, pSubKey: v5);
  CNodePanel::RecreateControls(this);
}

//------------------------------------------------------------------------------
// Address: 0x10020E40
// Name: public: virtual void CNodePanel::OnAddState(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodePanel::OnAddState(CNodePanel *this, KeyValues *pKV)
{
  int Int; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  Int = KeyValues::GetInt(this: pKV, keyName: "index", defaultValue: -1);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "state", firstKey: "name", firstValue: "MyNewState");
  else
    v5 = nullptr;
  KeyValues::InsertSubKey(this: this->m_pNodeKV, nIndex: Int, pSubKey: v5);
  CNodePanel::RecreateControls(this);
}

//------------------------------------------------------------------------------
// Address: 0x10020EA0
// Name: public: void CNodePanel::SetData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodePanel::SetData(CNodePanel *this, KeyValues *pNodeKV)
{
  KeyValues *m_pNodeKV; // eax
  vgui::Panel *v4; // eax
  KeyValues **v5; // eax

  m_pNodeKV = this->m_pNodeKV;
  if ( m_pNodeKV != nullptr && m_pNodeKV != pNodeKV )
  {
    v4 = this->GetParent(this);
    v5 = (KeyValues **)__RTDynamicCast(
                         inptr: v4,
                         VfDelta: 0,
                         SrcType: &vgui::Panel `RTTI Type Descriptor',
                         TargetType: &CNodePanel `RTTI Type Descriptor',
                         isReference: 0);
    if ( v5 != nullptr )
    {
      if ( pNodeKV != nullptr )
        KeyValues::SwapSubKey(this: v5[147], pExistingSubkey: this->m_pNodeKV, pNewSubKey: pNodeKV);
      else
        KeyValues::RemoveSubKey(this: v5[147], subKey: this->m_pNodeKV);
    }
    KeyValues::deleteThis(this: this->m_pNodeKV);
  }
  this->m_pNodeKV = pNodeKV;
  CNodePanel::RecreateControls(this);
}

//------------------------------------------------------------------------------
// Address: 0x10020F30
// Name: protected: void CNodePanel::AddChild(class CNodePanel __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNodePanel::AddChild(CNodePanel *this, CNodePanel *pPanel, int nPadding)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CNodePanel **m_pMemory; // ecx
  int v7; // eax
  CNodePanel **v8; // edi
  vgui::CBoxSizer *m_pChildSizer; // ecx
  vgui::SizerAddArgs_t args; // [esp+Ch] [ebp-18h] BYREF

  m_nAllocationCount = this->m_ChildPanels.m_Memory.m_nAllocationCount;
  m_Size = this->m_ChildPanels.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ChildPanels,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_ChildPanels.m_Size;
  m_pMemory = this->m_ChildPanels.m_Memory.m_pMemory;
  v7 = this->m_ChildPanels.m_Size - m_Size - 1;
  this->m_ChildPanels.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_ChildPanels.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = pPanel;
  args.m_nPadding = nPadding;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  m_pChildSizer = this->m_pChildSizer;
  args.m_flExpandFactor = 0.0;
  args.m_bMinorExpand = true;
  args.m_bIgnoreMemberMin = false;
  vgui::CSizerBase::InsertPanel(this: m_pChildSizer, nIndex: m_pChildSizer->m_Members.m_Size, pPanel, &args);
  if ( this->m_pEditor != nullptr )
    this->m_pEditor->InvalidateLayout(this: this->m_pEditor, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10021000
// Name: protected: class CNodePanel __near * CNodePanel::CreateChild(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CRuleInstanceNodePanel *__thiscall CNodePanel::CreateChild(CNodePanel *this, KeyValues *pKey)
{
  const char *Name; // ebx
  CStateNodePanel *v4; // eax
  CRuleInstanceNodePanel *v5; // eax
  CRuleInstanceNodePanel *v6; // eax
  CRuleInstanceNodePanel *v7; // esi

  Name = KeyValues::GetName(this: pKey);
  if ( _V_stricmp(s1: Name, s2: "state") != 0 )
  {
    if ( _V_stricmp(s1: Name, s2: "rule_instance") != 0 )
      goto LABEL_8;
    v6 = (CRuleInstanceNodePanel *)operator new(nSize: 0x2B0u);
    if ( v6 == nullptr )
      goto LABEL_8;
    v5 = CRuleInstanceNodePanel::CRuleInstanceNodePanel(this: v6, pParent: this, pName: "rule_instance_panel");
  }
  else
  {
    v4 = (CStateNodePanel *)operator new(nSize: 0x290u);
    if ( v4 == nullptr )
      goto LABEL_8;
    v5 = (CRuleInstanceNodePanel *)CStateNodePanel::CStateNodePanel(this: v4, pParent: this, pName: "state_panel");
  }
  v7 = v5;
  if ( v5 != nullptr )
  {
    v5->m_pEditor = this->m_pEditor;
    CNodePanel::SetData(this: v5, pNodeKV: pKey);
    return v7;
  }
LABEL_8:
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
    _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Unrecognized node type (cannot create panel): %s.\n");
  return nullptr;
}
