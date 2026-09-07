// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vgui/location_editor/location_editor_frame.cpp
// Functions: 25
// ============================================================

#include "missionchooser\vgui\location_editor\location_editor_frame.h"

//------------------------------------------------------------------------------
// Address: 0x1000FF90
// Name: public: static char const __near * CGroup_Edit_Page::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CGroup_Edit_Page::GetPanelClassName()
{
  return "CGroup_Edit_Page";
}

//------------------------------------------------------------------------------
// Address: 0x1000FFA0
// Name: public: static char const __near * CLocation_Editor_Frame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CLocation_Editor_Frame::GetPanelClassName()
{
  return "CLocation_Editor_Frame";
}

//------------------------------------------------------------------------------
// Address: 0x1000FFB0
// Name: public: virtual void CLocation_Editor_Frame::KeyValuesChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocation_Editor_Frame::KeyValuesChanged(CLocation_Editor_Frame *this, CKV_Editor *panel)
{
  IASW_Location_Grid *v3; // eax
  CASW_Location_Group *v4; // eax

  if ( panel == this->m_pGroupPage->m_pEditor )
  {
    v3 = CASW_Mission_Chooser::LocationGrid(this: (CASW_Mission_Chooser *)panel);
    v4 = (CASW_Location_Group *)v3->__vftable[1].GetGroup(this: v3, a2: this->m_pGroupPage->m_iCurrentGroupIndex);
    if ( v4 != nullptr )
      CASW_Location_Group::LoadFromKeyValues(this: v4, pKeys: this->m_pGroupPage->m_pEditor->m_pKeys);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010010
// Name: public: virtual void CLocation_Editor_Frame::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocation_Editor_Frame::PerformLayout(CLocation_Editor_Frame *this)
{
  int screenWide; // [esp+4h] [ebp-8h] BYREF
  int screenTall; // [esp+8h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  if ( this->m_bFirstPerformLayout )
  {
    g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &screenWide, a3: &screenTall);
    this->m_bFirstPerformLayout = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010060
// Name: public: void CLocation_Editor_Frame::SetGroup(class IASW_Location_Group __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocation_Editor_Frame::SetGroup(CLocation_Editor_Frame *this, IASW_Location_Group *pGroup)
{
  CASW_Location_Group *v3; // eax
  CKV_Editor_vtbl *v4; // edi
  KeyValues *KeyValuesForEditor; // eax

  if ( pGroup != nullptr )
  {
    v3 = (CASW_Location_Group *)__RTDynamicCast(
                                  inptr: pGroup,
                                  VfDelta: 0,
                                  SrcType: &IASW_Location_Group `RTTI Type Descriptor',
                                  TargetType: &CASW_Location_Group `RTTI Type Descriptor',
                                  isReference: 0);
    if ( v3 != nullptr )
    {
      v4 = this->m_pGroupPage->m_pEditor->__vftable;
      KeyValuesForEditor = CASW_Location_Group::GetKeyValuesForEditor(this: v3);
      v4->SetKeys(this: this->m_pGroupPage->m_pEditor, a2: KeyValuesForEditor);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100100C0
// Name: public: virtual void CGroup_Edit_Page::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGroup_Edit_Page::PerformLayout(CGroup_Edit_Page *this)
{
  int Wide; // eax
  int v3; // eax
  int v4; // eax
  int v5; // [esp-4h] [ebp-8h]

  v5 = vgui::Panel::GetTall(this) - 55;
  Wide = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pEditor, x: 5, y: 45, wide: Wide - 10, tall: v5);
  v3 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pNewGroupButton, x: v3 - 110, y: 16, wide: 100, tall: 22);
  v4 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pDeleteGroupButton, x: v4 - 215, y: 16, wide: 100, tall: 22);
}

//------------------------------------------------------------------------------
// Address: 0x10010130
// Name: public: virtual void CGroup_Edit_Page::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGroup_Edit_Page::OnCommand(CGroup_Edit_Page *this, const char *command)
{
  vgui::Panel::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x10010150
// Name: public: virtual struct vgui::PanelMessageMap __near * CGroup_Edit_Page::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CGroup_Edit_Page::GetMessageMap(CGroup_Edit_Page *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CGroup_Edit_Page::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CGroup_Edit_Page::GetMessageMap'::`2'::s_pMap;
  `CGroup_Edit_Page::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CGroup_Edit_Page");
  `CGroup_Edit_Page::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010180
// Name: public: virtual struct PanelAnimationMap __near * CGroup_Edit_Page::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CGroup_Edit_Page::GetAnimMap(CGroup_Edit_Page *this)
{
  return FindOrAddPanelAnimationMap(className: "CGroup_Edit_Page");
}

//------------------------------------------------------------------------------
// Address: 0x10010190
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CGroup_Edit_Page::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CGroup_Edit_Page::GetKBMap(CGroup_Edit_Page *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CGroup_Edit_Page::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CGroup_Edit_Page::GetKBMap'::`2'::s_pMap;
  `CGroup_Edit_Page::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CGroup_Edit_Page");
  `CGroup_Edit_Page::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100101C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CLocation_Editor_Frame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CLocation_Editor_Frame::GetMessageMap(CLocation_Editor_Frame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CLocation_Editor_Frame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CLocation_Editor_Frame::GetMessageMap'::`2'::s_pMap;
  `CLocation_Editor_Frame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CLocation_Editor_Frame");
  `CLocation_Editor_Frame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100101F0
// Name: public: virtual struct PanelAnimationMap __near * CLocation_Editor_Frame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CLocation_Editor_Frame::GetAnimMap(CLocation_Editor_Frame *this)
{
  return FindOrAddPanelAnimationMap(className: "CLocation_Editor_Frame");
}

//------------------------------------------------------------------------------
// Address: 0x10010200
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CLocation_Editor_Frame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CLocation_Editor_Frame::GetKBMap(CLocation_Editor_Frame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CLocation_Editor_Frame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CLocation_Editor_Frame::GetKBMap'::`2'::s_pMap;
  `CLocation_Editor_Frame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CLocation_Editor_Frame");
  `CLocation_Editor_Frame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010260
// Name: protected: void CLocation_Editor_Frame::UpdateTree(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CLocation_Editor_Frame::UpdateTree(CLocation_Editor_Frame *this@<ecx>, int a2@<esi>)
{
  CASW_Mission_Chooser *v3; // ecx
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int v6; // eax
  int v7; // esi
  CASW_Mission_Chooser *v8; // ecx
  IASW_Location_Grid *v9; // eax
  CASW_Mission_Chooser *v10; // ecx
  IASW_Location_Grid *v11; // eax
  CASW_Mission_Chooser *v12; // ecx
  IASW_Location_Group *v13; // ebx
  KeyValues *v14; // eax
  KeyValues *v15; // esi
  const char *v16; // eax
  int v17; // eax
  vgui::TreeView *m_pTree; // ecx
  IASW_Location_Grid *v19; // eax
  int i; // [esp+4h] [ebp-8h]
  int v22; // [esp+8h] [ebp-4h] BYREF

  this->m_pTree->RemoveAll(this: this->m_pTree);
  if ( CASW_Mission_Chooser::LocationGrid(this: v3) != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "TVI");
    else
      v5 = nullptr;
    KeyValues::SetString(this: v5, keyName: "Text", value: "Groups");
    v6 = ((int (__thiscall *)(vgui::TreeView *, KeyValues *, int, int))this->m_pTree->AddItem)(
           a1: this->m_pTree,
           a2: v5,
           a3: -1,
           a4: a2);
    v7 = 0;
    this->m_iRootIndex = v6;
    i = 0;
    v9 = CASW_Mission_Chooser::LocationGrid(this: v8);
    if ( v9->GetNumGroups(this: v9) > 0 )
    {
      do
      {
        v11 = CASW_Mission_Chooser::LocationGrid(this: v10);
        v13 = v11->__vftable[1].GetGroup(this: v11, a2: v7);
        if ( v13 != nullptr )
        {
          v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v14 != nullptr )
            v15 = KeyValues::KeyValues(this: v14, setName: "Group");
          else
            v15 = nullptr;
          v16 = (const char *)v13->GetGroupName(this: v13);
          KeyValues::SetString(this: v15, keyName: "Text", value: v16);
          KeyValues::SetInt(this: v15, keyName: "Index", value: i);
          KeyValues::SetString(this: v15, keyName: "Type", value: "Group");
          v17 = this->m_pTree->AddItem(this: this->m_pTree, a2: v15, a3: this->m_iRootIndex);
          m_pTree = this->m_pTree;
          v22 = -1;
          m_pTree->SetItemFgColor(this: m_pTree, a2: v17, a3: (const Color *)&v22);
          v7 = i;
        }
        i = ++v7;
        v19 = CASW_Mission_Chooser::LocationGrid(this: v12);
      }
      while ( v7 < v19->GetNumGroups(this: v19) );
    }
    ((void (__thiscall *)(vgui::TreeView *, int))this->m_pTree->ExpandItem)(a1: this->m_pTree, a2: this->m_iRootIndex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100103D0
// Name: protected: void CLocation_Editor_Frame::SetLocationID(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocation_Editor_Frame::SetLocationID(CLocation_Editor_Frame *this, int iLocationID)
{
  CASW_Mission_Chooser *v3; // ecx
  IASW_Location_Grid *v4; // eax
  int v5; // eax
  CASW_Mission_Chooser *v6; // ecx
  int v7; // edi
  int v8; // esi
  IASW_Location_Grid *v9; // eax
  CASW_Mission_Chooser *v10; // ecx
  IASW_Location_Grid *v11; // eax
  CASW_Mission_Chooser *v12; // ecx
  IASW_Location_Grid *v13; // eax
  CASW_Mission_Chooser *m_pGroupPage; // ecx
  IASW_Location_Grid *v15; // eax
  IASW_Location_Group *v16; // eax

  if ( CASW_Mission_Chooser::LocationGrid((CASW_Mission_Chooser *)this) != nullptr )
  {
    this->m_iCurrentLocationID = iLocationID;
    v4 = CASW_Mission_Chooser::LocationGrid(this: v3);
    v5 = (int)v4->GetLocationByID(this: v4, a2: iLocationID);
    if ( v5 != 0 )
    {
      v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
      if ( v7 != 0 )
      {
        v8 = 0;
        v9 = CASW_Mission_Chooser::LocationGrid(this: v6);
        if ( v9->GetNumGroups(this: v9) > 0 )
        {
          while ( 1 )
          {
            v11 = CASW_Mission_Chooser::LocationGrid(this: v10);
            if ( (IASW_Location_Group *)v7 == v11->__vftable[1].GetGroup(this: v11, a2: v8) )
              break;
            ++v8;
            v13 = CASW_Mission_Chooser::LocationGrid(this: v12);
            if ( v8 >= v13->GetNumGroups(this: v13) )
              return;
          }
          m_pGroupPage = (CASW_Mission_Chooser *)this->m_pGroupPage;
          m_pGroupPage[87].__vftable = (CASW_Mission_Chooser_vtbl *)v8;
          v15 = CASW_Mission_Chooser::LocationGrid(this: m_pGroupPage);
          v16 = v15->__vftable[1].GetGroup(this: v15, a2: v8);
          CLocation_Editor_Frame::SetGroup(this, pGroup: v16);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010480
// Name: public: CGroup_Edit_Page::CGroup_Edit_Page(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CGroup_Edit_Page *__thiscall CGroup_Edit_Page::CGroup_Edit_Page(
        CGroup_Edit_Page *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CKV_Editor *v7; // eax
  CKV_Editor *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CGroup_Edit_Page_vtbl *)&CGroup_Edit_Page::`vftable';
  if ( `CGroup_Edit_Page::ChainToMap'::`2'::chained == 0 )
  {
    `CGroup_Edit_Page::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CGroup_Edit_Page");
    v4->pfnClassName = CGroup_Edit_Page::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CGroup_Edit_Page::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CGroup_Edit_Page::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CGroup_Edit_Page");
    v5->pfnClassName = CGroup_Edit_Page::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CGroup_Edit_Page::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CGroup_Edit_Page::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CGroup_Edit_Page");
    v6->pfnClassName = CGroup_Edit_Page::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  v7 = (CKV_Editor *)operator new(nSize: 0x2ECu);
  if ( v7 != nullptr )
    v8 = CKV_Editor::CKV_Editor(this: v7, parent: this, name: "KVEditor");
  else
    v8 = nullptr;
  this->m_pEditor = v8;
  v8->SetFileSpec_2(this: v8, a2: "tilegen/location_group_editor_spec.txt", a3: "GAME");
  v9 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "NewGroupButton",
            text: "New Group",
            pActionSignalTarget: this,
            pCmd: "NewGroup");
  else
    v10 = nullptr;
  this->m_pNewGroupButton = v10;
  v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "DeleteGroupButton",
            text: "Delete Group",
            pActionSignalTarget: this,
            pCmd: "DeleteGroup");
  else
    v12 = nullptr;
  this->m_pDeleteGroupButton = v12;
  this->m_iCurrentGroupIndex = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10010620
// Name: protected: virtual void CLocation_Editor_Frame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocation_Editor_Frame::OnCommand(CLocation_Editor_Frame *this, const char *command)
{
  int v3; // eax
  CASW_Mission_Chooser *v4; // ecx
  CASW_Location_Grid *v5; // eax

  vgui::Frame::OnCommand(this, command);
  if ( V_strnicmp(s1: command, s2: "Location", n: 8) != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Save") == 0 )
    {
      v5 = (CASW_Location_Grid *)CASW_Mission_Chooser::LocationGrid(this: v4);
      if ( !CASW_Location_Grid::SaveLocationGrid(this: v5) )
        VGUIMessageBox(
          pParent: this,
          pTitle: "Save Error",
          pMsg: "Failed to save %s.  Make sure file is checked out from Perforce.",
          "resource/mission_grid.txt");
    }
  }
  else
  {
    v3 = atoi(nptr: command + 8);
    CLocation_Editor_Frame::SetLocationID(this, iLocationID: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100106A0
// Name: public: virtual void CLocation_Editor_Frame::NewGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocation_Editor_Frame::NewGroup(CLocation_Editor_Frame *this, vgui::Panel *panel)
{
  CASW_Location_Grid *v3; // eax

  v3 = (CASW_Location_Grid *)CASW_Mission_Chooser::LocationGrid((CASW_Mission_Chooser *)this);
  CASW_Location_Grid::CreateNewGroup(this: v3);
  CLocation_Editor_Frame::UpdateTree(this, a2: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x100106C0
// Name: public: virtual void CLocation_Editor_Frame::DeleteGroup(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocation_Editor_Frame::DeleteGroup(CLocation_Editor_Frame *this, vgui::Panel *panel)
{
  CASW_Location_Grid *v3; // eax
  CASW_Mission_Chooser *m_iCurrentGroupIndex; // [esp-4h] [ebp-8h]

  m_iCurrentGroupIndex = (CASW_Mission_Chooser *)this->m_pGroupPage->m_iCurrentGroupIndex;
  v3 = (CASW_Location_Grid *)CASW_Mission_Chooser::LocationGrid(this: m_iCurrentGroupIndex);
  CASW_Location_Grid::DeleteGroup(this: v3, iIndex: (int)m_iCurrentGroupIndex);
  CLocation_Editor_Frame::UpdateTree(this, a2: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x100106F0
// Name: protected: virtual void CLocation_Editor_Frame::OnTreeViewItemSelected(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLocation_Editor_Frame::OnTreeViewItemSelected(CLocation_Editor_Frame *this, int itemIndex)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  const char *String; // eax
  int Int; // edi
  CASW_Mission_Chooser *v7; // ecx
  IASW_Location_Grid *v8; // eax
  IASW_Location_Group *v9; // eax
  int v10; // eax

  v3 = this->m_pTree->GetItemData(this: this->m_pTree, a2: itemIndex);
  v4 = v3;
  if ( v3 != nullptr && KeyValues::FindKey(this: v3, keyName: "Text", bCreate: false) != nullptr )
  {
    if ( this->m_pTree->GetItemParent(this: this->m_pTree, a2: itemIndex) == this->m_iRootIndex
      && (String = KeyValues::GetString(this: v4, keyName: "Text", defaultValue: szDescription),
          _V_stricmp(s1: String, s2: "Ungrouped") != 0) )
    {
      Int = KeyValues::GetInt(this: v4, keyName: "Index", defaultValue: -1);
      this->m_pGroupPage->m_iCurrentGroupIndex = Int;
      v8 = CASW_Mission_Chooser::LocationGrid(this: v7);
      v9 = v8->__vftable[1].GetGroup(this: v8, a2: Int);
      CLocation_Editor_Frame::SetGroup(this, pGroup: v9);
    }
    else
    {
      v10 = KeyValues::GetInt(this: v4, keyName: "LocationID", defaultValue: -1);
      CLocation_Editor_Frame::SetLocationID(this, iLocationID: v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100107C0
// Name: public: static void CLocation_Editor_Frame::PanelMessageFunc_KeyValuesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CLocation_Editor_Frame::PanelMessageFunc_KeyValuesChanged::InitVar(int a1@<ebp>)
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
  if ( !`CLocation_Editor_Frame::PanelMessageFunc_KeyValuesChanged::InitVar'::`2'::bAdded )
  {
    `CLocation_Editor_Frame::PanelMessageFunc_KeyValuesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CLocation_Editor_Frame");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "KeyValuesChanged";
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
// Address: 0x10010860
// Name: public: static void CLocation_Editor_Frame::PanelMessageFunc_NewGroup::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CLocation_Editor_Frame::PanelMessageFunc_NewGroup::InitVar(int a1@<ebp>)
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
  if ( !`CLocation_Editor_Frame::PanelMessageFunc_NewGroup::InitVar'::`2'::bAdded )
  {
    `CLocation_Editor_Frame::PanelMessageFunc_NewGroup::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CLocation_Editor_Frame");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "NewGroup";
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
// Address: 0x10010900
// Name: public: static void CLocation_Editor_Frame::PanelMessageFunc_DeleteGroup::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CLocation_Editor_Frame::PanelMessageFunc_DeleteGroup::InitVar(int a1@<ebp>)
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
  if ( !`CLocation_Editor_Frame::PanelMessageFunc_DeleteGroup::InitVar'::`2'::bAdded )
  {
    `CLocation_Editor_Frame::PanelMessageFunc_DeleteGroup::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1124,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CLocation_Editor_Frame");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "DeleteGroup";
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
// Address: 0x100109A0
// Name: public: static void CLocation_Editor_Frame::PanelMessageFunc_OnTreeViewItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CLocation_Editor_Frame::PanelMessageFunc_OnTreeViewItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CLocation_Editor_Frame::PanelMessageFunc_OnTreeViewItemSelected::InitVar'::`2'::bAdded )
  {
    `CLocation_Editor_Frame::PanelMessageFunc_OnTreeViewItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CLocation_Editor_Frame");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "TreeViewItemSelected";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "itemIndex";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010A40
// Name: public: CLocation_Editor_Frame::CLocation_Editor_Frame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CLocation_Editor_Frame *__thiscall CLocation_Editor_Frame::CLocation_Editor_Frame(
        CLocation_Editor_Frame *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CGroup_Edit_Page *v7; // eax
  CGroup_Edit_Page *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  CScrollingWindow *v11; // eax
  CScrollingWindow *v12; // eax
  CLocation_Layout_Panel *v13; // eax
  CLocation_Layout_Panel *v14; // eax
  CScrollingWindow *m_pScrollingWindow; // ecx
  vgui::TreeView *v16; // eax
  vgui::TreeView *v17; // eax
  vgui::ISchemeManager *v18; // edi
  vgui::ISchemeManager_vtbl *v19; // ebx
  unsigned int Scheme; // eax
  int v21; // eax
  unsigned int v22; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CLocation_Editor_Frame_vtbl *)&CLocation_Editor_Frame::`vftable';
  if ( `CLocation_Editor_Frame::ChainToMap'::`2'::chained == 0 )
  {
    `CLocation_Editor_Frame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CLocation_Editor_Frame");
    v4->pfnClassName = CLocation_Editor_Frame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CLocation_Editor_Frame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CLocation_Editor_Frame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CLocation_Editor_Frame");
    v5->pfnClassName = CLocation_Editor_Frame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CLocation_Editor_Frame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CLocation_Editor_Frame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CLocation_Editor_Frame");
    v6->pfnClassName = CLocation_Editor_Frame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CLocation_Editor_Frame::PanelMessageFunc_KeyValuesChanged::InitVar(a1: (int)&savedregs);
  CLocation_Editor_Frame::PanelMessageFunc_NewGroup::InitVar(a1: (int)&savedregs);
  CLocation_Editor_Frame::PanelMessageFunc_DeleteGroup::InitVar(a1: (int)&savedregs);
  CLocation_Editor_Frame::PanelMessageFunc_OnTreeViewItemSelected::InitVar(a1: (int)&savedregs);
  CUniformRandomStream::CUniformRandomStream(this: &this->m_Random);
  v7 = (CGroup_Edit_Page *)operator new(nSize: 0x160u);
  if ( v7 != nullptr )
    v8 = CGroup_Edit_Page::CGroup_Edit_Page(this: v7, parent: this, name: "GroupPage");
  else
    v8 = nullptr;
  this->m_pGroupPage = v8;
  v8->m_pEditor->AddActionSignalTarget_2(this: v8->m_pEditor, a2: this);
  this->m_pGroupPage->AddActionSignalTarget_2(this: this->m_pGroupPage, a2: this);
  v9 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "SaveButton",
            text: "Save",
            pActionSignalTarget: this,
            pCmd: "Save");
  else
    v10 = nullptr;
  this->m_pSaveButton = v10;
  v11 = (CScrollingWindow *)operator new(nSize: 0x168u);
  if ( v11 != nullptr )
    v12 = CScrollingWindow::CScrollingWindow(this: v11, parent: this, name: "ScrollingWindow");
  else
    v12 = nullptr;
  this->m_pScrollingWindow = v12;
  v13 = (CLocation_Layout_Panel *)operator new(nSize: 0x170u);
  if ( v13 != nullptr )
    v14 = CLocation_Layout_Panel::CLocation_Layout_Panel(
            this: v13,
            parent: this,
            pActionTarget: this,
            name: "LocationLayoutPanel");
  else
    v14 = nullptr;
  m_pScrollingWindow = this->m_pScrollingWindow;
  this->m_pLocationLayoutPanel = v14;
  CScrollingWindow::SetChildPanel(this: m_pScrollingWindow, pPanel: v14);
  v16 = (vgui::TreeView *)operator new(nSize: 0x1BCu);
  if ( v16 != nullptr )
    v17 = vgui::TreeView::TreeView(this: v16, parent: this, panelName: "Tree");
  else
    v17 = nullptr;
  this->m_pTree = v17;
  vgui::Panel::MakeReadyForUse(this: v17);
  v18 = g_pVGuiSchemeManager;
  v19 = g_pVGuiSchemeManager->__vftable;
  Scheme = vgui::Panel::GetScheme(this);
  v21 = (int)v19->GetIScheme(this: v18, a2: Scheme);
  v22 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v21 + 12))(a1: v21, a2: "DefaultVerySmall", a3: 0);
  this->m_pTree->SetFont(this: this->m_pTree, a2: v22);
  vgui::TreeView::SetSortFunc(this: this->m_pTree, pSortFunc: `anonymous namespace'::GroupTreeSortFunc);
  this->m_iRootIndex = -1;
  this->m_iCurrentLocationID = -1;
  CLocation_Editor_Frame::UpdateTree(this, a2: (int)this);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "LocationEditor.res",
    pathID: "TILEGEN",
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::SetMinimumSize(this, wide: 384, tall: 420);
  vgui::Frame::SetSizeable(this, state: true);
  vgui::Frame::SetMinimizeButtonVisible(this, state: false);
  vgui::Frame::SetMaximizeButtonVisible(this, state: false);
  vgui::Frame::SetMenuButtonVisible(this, state: false);
  this->m_bFirstPerformLayout = true;
  vgui::Frame::SetTitle(this, title: "Location Grid Editor", surfaceTitle: true);
  return this;
}
