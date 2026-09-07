// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/keyvalues_editor/kv_node_panel.cpp
// Functions: 15
// ============================================================

#include "missionchooser\keyvalues_editor\kv_node_panel.h"

//------------------------------------------------------------------------------
// Address: 0x1000F610
// Name: public: static char const __near * CKV_Node_Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CKV_Node_Panel::GetPanelClassName()
{
  return "CKV_Node_Panel";
}

//------------------------------------------------------------------------------
// Address: 0x1000F620
// Name: public: static void __near * CKV_Node_Panel::GetVar_m_iLabelInsetX(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl CKV_Node_Panel::GetVar_m_iLabelInsetX(vgui::Panel *panel)
{
  return &panel[1]._buildModeFlags;
}

//------------------------------------------------------------------------------
// Address: 0x1000F630
// Name: public: static void __near * CKV_Node_Panel::GetVar_m_iLabelInsetY(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CKV_Node_Panel::GetVar_m_iLabelInsetY(vgui::Panel *panel)
{
  return (char *)&panel[1] + 172;
}

//------------------------------------------------------------------------------
// Address: 0x1000F640
// Name: public: virtual void CKV_Node_Panel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Node_Panel::ApplySchemeSettings(CKV_Node_Panel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  this->m_pLabel->SetPaintBackgroundEnabled(this: this->m_pLabel, a2: false);
  this->m_pDeleteButton->SetVisible(this: this->m_pDeleteButton, a2: this->m_bAllowDeletion);
}

//------------------------------------------------------------------------------
// Address: 0x1000F680
// Name: public: virtual void CKV_Node_Panel::OnAddButtonPressed(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Node_Panel::OnAddButtonPressed(CKV_Node_Panel *this, const char *szKeyName)
{
  this->m_pEditor->AddToKey(this: this->m_pEditor, a2: this->m_pFileSpecNode, a3: this->m_pKey, a4: szKeyName);
}

//------------------------------------------------------------------------------
// Address: 0x1000F6B0
// Name: public: virtual void CKV_Node_Panel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Node_Panel::PerformLayout(CKV_Node_Panel *this)
{
  KeyValues *m_pFileSpecNode; // ecx
  int Int; // eax
  KeyValues *v4; // ecx
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  vgui::Button *v8; // esi
  int v9; // eax
  int Tall; // eax
  int v11; // [esp-Ch] [ebp-24h]
  int m_iLabelInsetY; // [esp-4h] [ebp-1Ch]
  int i; // [esp+8h] [ebp-10h]
  int y; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h]
  int x; // [esp+14h] [ebp-4h] BYREF

  CKV_Fit_Children_Panel::PerformLayout(this);
  m_pFileSpecNode = this->m_pFileSpecNode;
  if ( m_pFileSpecNode != nullptr )
  {
    Int = KeyValues::GetInt(this: m_pFileSpecNode, keyName: "LabelInsetX", defaultValue: this->m_iLabelInsetX);
    m_iLabelInsetY = this->m_iLabelInsetY;
    v4 = this->m_pFileSpecNode;
    this->m_iLabelInsetX = Int;
    this->m_iLabelInsetY = KeyValues::GetInt(this: v4, keyName: "LabelInsetY", defaultValue: m_iLabelInsetY);
  }
  vgui::Panel::SetBounds(
    this: this->m_pLabel,
    x: 2 * this->m_iLabelInsetX,
    y: this->m_iLabelInsetY,
    wide: 300,
    tall: 16);
  v11 = this->m_iLabelInsetY;
  v5 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pDeleteButton, x: v5 - 25, y: v11, wide: 20, tall: 16);
  wide = vgui::Panel::GetWide(this);
  v6 = vgui::Panel::GetTall(this) - this->m_iSpacing;
  v7 = 0;
  for ( i = 0; v7 < this->m_pAddButtons.m_Size; i = v7 )
  {
    v8 = this->m_pAddButtons.m_Memory.m_pMemory[v7];
    if ( v8 != nullptr )
    {
      vgui::Panel::SetPos(this: v8, x: this->m_iBorder, y: v6);
      vgui::Panel::SetSize(this: v8, wide: 300, tall: 25);
      v8->InvalidateLayout(this: v8, a2: true, a3: false);
      vgui::Panel::GetPos(this: v8, &x, &y);
      v9 = vgui::Panel::GetWide(this: v8);
      x += v9;
      Tall = vgui::Panel::GetTall(this: v8);
      y += Tall;
      v6 += this->m_iSpacing + vgui::Panel::GetTall(this: v8);
      if ( wide <= x )
        wide = x;
    }
    v7 = i + 1;
  }
  vgui::Panel::SetSize(this, wide, tall: v6 + 2 * this->m_iSpacing);
}

//------------------------------------------------------------------------------
// Address: 0x1000F820
// Name: public: static void CKV_Node_Panel::PanelMessageFunc_OnAddButtonPressed::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CKV_Node_Panel::PanelMessageFunc_OnAddButtonPressed::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CKV_Node_Panel::PanelMessageFunc_OnAddButtonPressed::InitVar'::`2'::bAdded )
  {
    `CKV_Node_Panel::PanelMessageFunc_OnAddButtonPressed::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CKV_Node_Panel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CKV_Node_Panel");
    v2 = (__int128)_mm_load_si128(&v5);
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTCHARPTR;
    memset(&v4.secondParamType, 0, 20);
    m_Size = v1->entries.m_Size;
    v4.name = "AddButtonPressed";
    v4.func = v2;
    v4.firstParamName = "szKeyName";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F8C0
// Name: public: static void CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetX::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetX::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetX::InitVar'::`2'::bAdded )
  {
    `CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetX::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CKV_Node_Panel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "LabelInsetX";
    src.m_pszVariable = "m_iLabelInsetX";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "2";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CKV_Node_Panel::GetVar_m_iLabelInsetX;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F920
// Name: public: static void CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetY::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetY::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetY::InitVar'::`2'::bAdded )
  {
    `CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetY::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CKV_Node_Panel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "LabelInsetY";
    src.m_pszVariable = "m_iLabelInsetY";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "2";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CKV_Node_Panel::GetVar_m_iLabelInsetY;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F980
// Name: public: virtual void CKV_Node_Panel::UpdatePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Node_Panel::UpdatePanel(CKV_Node_Panel *this)
{
  KeyValues *m_pFileSpecNode; // ecx
  vgui::Button_vtbl *v3; // esi
  KeyValues *Key; // eax
  int i; // esi
  vgui::Button *v6; // ecx
  vgui::Button *v7; // ecx
  KeyValues *v8; // ecx
  vgui::Label_vtbl *v9; // esi
  const char *String; // eax
  vgui::Label_vtbl *v11; // esi
  const char *v12; // eax
  int v13; // eax
  vgui::Label_vtbl *v14; // esi
  const char *Name; // eax
  KeyValues *v16; // ecx
  KeyValues *j; // ebx
  const char *v18; // eax
  const char *v19; // eax
  KeyValues *NextKey; // esi
  const char *v21; // eax
  const char *v22; // eax
  vgui::Button *v23; // eax
  vgui::Button *v24; // esi
  const char *v25; // eax
  KeyValues *v26; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  vgui::Button **m_pMemory; // ecx
  int v30; // eax
  vgui::Button **v31; // esi
  const char *v32; // [esp-4h] [ebp-118h]
  const char *v33; // [esp-4h] [ebp-118h]
  const char *v34; // [esp-4h] [ebp-118h]
  char buffer[256]; // [esp+Ch] [ebp-108h] BYREF
  KeyValues *v36; // [esp+10Ch] [ebp-8h]
  vgui::Button *pAdd; // [esp+110h] [ebp-4h]

  m_pFileSpecNode = this->m_pFileSpecNode;
  if ( m_pFileSpecNode != nullptr )
  {
    v3 = this->m_pDeleteButton->__vftable;
    Key = KeyValues::FindKey(this: m_pFileSpecNode, keyName: "Autocreate", bCreate: false);
    v3->SetVisible(this: this->m_pDeleteButton, a2: Key == nullptr);
  }
  for ( i = 0; i < this->m_pAddButtons.m_Size; ++i )
  {
    v6 = this->m_pAddButtons.m_Memory.m_pMemory[i];
    v6->SetVisible(this: v6, a2: false);
    v7 = this->m_pAddButtons.m_Memory.m_pMemory[i];
    v7->MarkForDeletion(this: v7);
  }
  this->m_pAddButtons.m_Size = 0;
  if ( this->m_pAddButtons.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_pAddButtons.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pAddButtons.m_Memory.m_pMemory);
      this->m_pAddButtons.m_Memory.m_pMemory = nullptr;
    }
    this->m_pAddButtons.m_Memory.m_nAllocationCount = 0;
  }
  this->m_pAddButtons.m_pElements = this->m_pAddButtons.m_Memory.m_pMemory;
  if ( this->m_pKey != nullptr )
  {
    v8 = this->m_pFileSpecNode;
    if ( v8 != nullptr && KeyValues::FindKey(this: v8, keyName: "FriendlyName", bCreate: false) != nullptr )
    {
      v9 = this->m_pLabel->__vftable;
      String = KeyValues::GetString(this: this->m_pFileSpecNode, keyName: "FriendlyName", defaultValue: szDescription);
      v9->SetText(this: this->m_pLabel, a2: String);
      v11 = this->m_pLabel->__vftable;
      v12 = KeyValues::GetString(this: this->m_pFileSpecNode, keyName: "FriendlyName", defaultValue: szDescription);
      v13 = _V_strlen(str: v12);
      v11->SetVisible(this: this->m_pLabel, a2: v13 > 0);
    }
    else
    {
      v14 = this->m_pLabel->__vftable;
      Name = KeyValues::GetName(this: this->m_pKey);
      v14->SetText(this: this->m_pLabel, a2: Name);
    }
    v16 = this->m_pFileSpecNode;
    if ( v16 != nullptr )
    {
      for ( j = KeyValues::GetFirstSubKey(this: v16); j != nullptr; j = KeyValues::GetNextKey(this: j) )
      {
        v18 = KeyValues::GetName(this: j);
        if ( _V_stricmp(s1: v18, s2: "_Node") != 0 )
        {
          v19 = KeyValues::GetName(this: j);
          if ( _V_stricmp(s1: v19, s2: "_Leaf") != 0 )
            continue;
        }
        if ( KeyValues::FindKey(this: j, keyName: "Unique", bCreate: false) != nullptr
          && (NextKey = KeyValues::GetFirstSubKey(this: this->m_pKey)) != nullptr )
        {
          while ( 1 )
          {
            v32 = KeyValues::GetString(this: j, keyName: "Name", defaultValue: szDescription);
            v21 = KeyValues::GetName(this: NextKey);
            if ( _V_stricmp(s1: v21, s2: v32) == 0 )
              break;
            NextKey = KeyValues::GetNextKey(this: NextKey);
            if ( NextKey == nullptr )
              goto LABEL_23;
          }
        }
        else
        {
LABEL_23:
          if ( this->m_pFileSpecNode != nullptr
            && KeyValues::FindKey(this: j, keyName: "FriendlyAddButtonText", bCreate: false) != nullptr )
          {
            v33 = KeyValues::GetString(this: j, keyName: "FriendlyAddButtonText", defaultValue: "ADD BUTTON ERROR");
            V_snprintf(pDest: buffer, maxLen: 256, pFormat: "%s", v33);
          }
          else
          {
            v22 = KeyValues::GetString(this: j, keyName: "Name", defaultValue: "Unknown key");
            v34 = KeyValues::GetString(this: j, keyName: "FriendlyName", defaultValue: v22);
            V_snprintf(pDest: buffer, maxLen: 256, pFormat: "Add %s", v34);
          }
          v23 = (vgui::Button *)operator new(nSize: 0x1F4u);
          if ( v23 != nullptr )
          {
            v24 = vgui::Button::Button(
                    this: v23,
                    parent: this,
                    panelName: "AddButton",
                    text: buffer,
                    pActionSignalTarget: this,
                    pCmd: nullptr);
            pAdd = v24;
          }
          else
          {
            pAdd = nullptr;
            v24 = nullptr;
          }
          v36 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v36 != nullptr )
          {
            v25 = KeyValues::GetString(this: j, keyName: "Name", defaultValue: "Unknown key");
            v26 = KeyValues::KeyValues(this: v36, setName: "AddButtonPressed", firstKey: "szKeyName", firstValue: v25);
          }
          else
          {
            v26 = nullptr;
          }
          v24->SetCommand(this: v24, a2: v26);
          m_Size = this->m_pAddButtons.m_Size;
          m_nAllocationCount = this->m_pAddButtons.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pAddButtons,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_pAddButtons.m_Size;
          m_pMemory = this->m_pAddButtons.m_Memory.m_pMemory;
          v30 = this->m_pAddButtons.m_Size - m_Size - 1;
          this->m_pAddButtons.m_pElements = m_pMemory;
          if ( v30 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v30);
          v31 = &this->m_pAddButtons.m_Memory.m_pMemory[m_Size];
          if ( v31 != nullptr )
            *v31 = pAdd;
        }
      }
    }
  }
  else
  {
    this->m_pLabel->SetText(this: this->m_pLabel, a2: "INVALID KEY");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FD40
// Name: public: CKV_Node_Panel::CKV_Node_Panel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CKV_Node_Panel *__thiscall CKV_Node_Panel::CKV_Node_Panel(CKV_Node_Panel *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Label *v7; // eax
  vgui::Label *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  CKV_Fit_Children_Panel::CKV_Fit_Children_Panel(this, parent, name);
  this->__vftable = (CKV_Node_Panel_vtbl *)&CKV_Node_Panel::`vftable';
  if ( `CKV_Node_Panel::ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Node_Panel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CKV_Node_Panel");
    v4->pfnClassName = CKV_Node_Panel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CKV_Fit_Children_Panel");
  }
  if ( `CKV_Node_Panel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CKV_Node_Panel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CKV_Node_Panel");
    v5->pfnClassName = CKV_Node_Panel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CKV_Fit_Children_Panel");
  }
  if ( `CKV_Node_Panel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Node_Panel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Node_Panel");
    v6->pfnClassName = CKV_Node_Panel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Fit_Children_Panel");
  }
  this->m_pAddButtons.m_Memory.m_pMemory = nullptr;
  this->m_pAddButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pAddButtons.m_Memory.m_nGrowSize = 0;
  this->m_pAddButtons.m_Size = 0;
  this->m_pAddButtons.m_pElements = nullptr;
  CKV_Node_Panel::PanelMessageFunc_OnAddButtonPressed::InitVar(a1: (int)&savedregs);
  CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetX::InitVar();
  this->m_iLabelInsetX = 2;
  CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetY::InitVar();
  this->m_iLabelInsetY = 2;
  v7 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v7 != nullptr )
    v8 = vgui::Label::Label(this: v7, parent: this, panelName: "Label", text: szDescription);
  else
    v8 = nullptr;
  this->m_pLabel = v8;
  v8->SetMouseInputEnabled(this: v8, a2: false);
  v9 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "DeleteButton",
            text: "X",
            pActionSignalTarget: this,
            pCmd: "Delete");
  else
    v10 = nullptr;
  this->m_pDeleteButton = v10;
  vgui::Panel::SetKeyBoardInputEnabled(this, state: false);
  this->m_iAutoPositionStartY = 30;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000FEC0
// Name: public: virtual struct vgui::PanelMessageMap __near * CKV_Node_Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CKV_Node_Panel::GetMessageMap(CKV_Node_Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CKV_Node_Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Node_Panel::GetMessageMap'::`2'::s_pMap;
  `CKV_Node_Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CKV_Node_Panel");
  `CKV_Node_Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000FEF0
// Name: public: virtual struct PanelAnimationMap __near * CKV_Node_Panel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CKV_Node_Panel::GetAnimMap(CKV_Node_Panel *this)
{
  return FindOrAddPanelAnimationMap(className: "CKV_Node_Panel");
}

//------------------------------------------------------------------------------
// Address: 0x1000FF00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CKV_Node_Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CKV_Node_Panel::GetKBMap(CKV_Node_Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CKV_Node_Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Node_Panel::GetKBMap'::`2'::s_pMap;
  `CKV_Node_Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Node_Panel");
  `CKV_Node_Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000FF70
// Name: Create_CKV_Node_Panel
// Source: json
//------------------------------------------------------------------------------
CKV_Node_Panel *__cdecl Create_CKV_Node_Panel()
{
  CKV_Node_Panel *v0; // eax

  v0 = (CKV_Node_Panel *)operator new(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return CKV_Node_Panel::CKV_Node_Panel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00408D50
// Name: public: static char const __near * CKV_Node_Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CKV_Node_Panel::GetPanelClassName()
{
  return "CKV_Node_Panel";
}

//------------------------------------------------------------------------------
// Address: 0x00408D60
// Name: public: static void __near * CKV_Node_Panel::GetVar_m_iLabelInsetX(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl CKV_Node_Panel::GetVar_m_iLabelInsetX(vgui::Panel *panel)
{
  return &panel[1]._buildModeFlags;
}

//------------------------------------------------------------------------------
// Address: 0x00408D70
// Name: public: static void __near * CKV_Node_Panel::GetVar_m_iLabelInsetY(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl CKV_Node_Panel::GetVar_m_iLabelInsetY(vgui::Panel *panel)
{
  return (char *)&panel[1] + 172;
}

//------------------------------------------------------------------------------
// Address: 0x00408D80
// Name: public: virtual void CKV_Node_Panel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Node_Panel::ApplySchemeSettings(CKV_Node_Panel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  this->m_pLabel->SetPaintBackgroundEnabled(this: this->m_pLabel, a2: false);
  this->m_pDeleteButton->SetVisible(this: this->m_pDeleteButton, a2: this->m_bAllowDeletion);
}

//------------------------------------------------------------------------------
// Address: 0x00408DC0
// Name: public: virtual void CKV_Node_Panel::OnAddButtonPressed(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Node_Panel::OnAddButtonPressed(CKV_Node_Panel *this, const char *szKeyName)
{
  this->m_pEditor->AddToKey(this: this->m_pEditor, a2: this->m_pFileSpecNode, a3: this->m_pKey, a4: szKeyName);
}

//------------------------------------------------------------------------------
// Address: 0x00408DF0
// Name: public: virtual void CKV_Node_Panel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Node_Panel::PerformLayout(CKV_Node_Panel *this)
{
  KeyValues *m_pFileSpecNode; // ecx
  int Int; // eax
  KeyValues *v4; // ecx
  int v5; // eax
  int v6; // ebx
  int v7; // eax
  vgui::Button *v8; // esi
  int v9; // eax
  int Tall; // eax
  int v11; // [esp-Ch] [ebp-24h]
  int m_iLabelInsetY; // [esp-4h] [ebp-1Ch]
  int i; // [esp+8h] [ebp-10h]
  int y; // [esp+Ch] [ebp-Ch] BYREF
  int wide; // [esp+10h] [ebp-8h]
  int x; // [esp+14h] [ebp-4h] BYREF

  CKV_Fit_Children_Panel::PerformLayout(this);
  m_pFileSpecNode = this->m_pFileSpecNode;
  if ( m_pFileSpecNode != nullptr )
  {
    Int = KeyValues::GetInt(this: m_pFileSpecNode, keyName: "LabelInsetX", defaultValue: this->m_iLabelInsetX);
    m_iLabelInsetY = this->m_iLabelInsetY;
    v4 = this->m_pFileSpecNode;
    this->m_iLabelInsetX = Int;
    this->m_iLabelInsetY = KeyValues::GetInt(this: v4, keyName: "LabelInsetY", defaultValue: m_iLabelInsetY);
  }
  vgui::Panel::SetBounds(
    this: this->m_pLabel,
    x: 2 * this->m_iLabelInsetX,
    y: this->m_iLabelInsetY,
    wide: 300,
    tall: 16);
  v11 = this->m_iLabelInsetY;
  v5 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pDeleteButton, x: v5 - 25, y: v11, wide: 20, tall: 16);
  wide = vgui::Panel::GetWide(this);
  v6 = vgui::Panel::GetTall(this) - this->m_iSpacing;
  v7 = 0;
  for ( i = 0; v7 < this->m_pAddButtons.m_Size; i = v7 )
  {
    v8 = this->m_pAddButtons.m_Memory.m_pMemory[v7];
    if ( v8 != nullptr )
    {
      vgui::Panel::SetPos(this: v8, x: this->m_iBorder, y: v6);
      vgui::Panel::SetSize(this: v8, wide: 300, tall: 25);
      v8->InvalidateLayout(this: v8, a2: true, a3: false);
      vgui::Panel::GetPos(this: v8, &x, &y);
      v9 = vgui::Panel::GetWide(this: v8);
      x += v9;
      Tall = vgui::Panel::GetTall(this: v8);
      y += Tall;
      v6 += this->m_iSpacing + vgui::Panel::GetTall(this: v8);
      if ( wide <= x )
        wide = x;
    }
    v7 = i + 1;
  }
  vgui::Panel::SetSize(this, wide, tall: v6 + 2 * this->m_iSpacing);
}

//------------------------------------------------------------------------------
// Address: 0x00408F60
// Name: public: static void CKV_Node_Panel::PanelMessageFunc_OnAddButtonPressed::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CKV_Node_Panel::PanelMessageFunc_OnAddButtonPressed::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CKV_Node_Panel::PanelMessageFunc_OnAddButtonPressed::InitVar'::`2'::bAdded )
  {
    `CKV_Node_Panel::PanelMessageFunc_OnAddButtonPressed::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CKV_Node_Panel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CKV_Node_Panel");
    v2 = (__int128)_mm_load_si128(&v5);
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTCHARPTR;
    memset(&v4.secondParamType, 0, 20);
    m_Size = v1->entries.m_Size;
    v4.name = "AddButtonPressed";
    v4.func = v2;
    v4.firstParamName = "szKeyName";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409000
// Name: public: static void CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetX::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetX::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetX::InitVar'::`2'::bAdded )
  {
    `CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetX::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CKV_Node_Panel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "LabelInsetX";
    src.m_pszVariable = "m_iLabelInsetX";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "2";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CKV_Node_Panel::GetVar_m_iLabelInsetX;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409060
// Name: public: static void CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetY::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetY::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetY::InitVar'::`2'::bAdded )
  {
    `CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetY::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CKV_Node_Panel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "LabelInsetY";
    src.m_pszVariable = "m_iLabelInsetY";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "2";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CKV_Node_Panel::GetVar_m_iLabelInsetY;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004090C0
// Name: public: virtual void CKV_Node_Panel::UpdatePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Node_Panel::UpdatePanel(CKV_Node_Panel *this)
{
  KeyValues *m_pFileSpecNode; // ecx
  vgui::Button_vtbl *v3; // esi
  KeyValues *Key; // eax
  int i; // esi
  vgui::Button *v6; // ecx
  vgui::Button *v7; // ecx
  KeyValues *v8; // ecx
  vgui::Label_vtbl *v9; // esi
  const char *String; // eax
  vgui::Label_vtbl *v11; // esi
  const char *v12; // eax
  int v13; // eax
  vgui::Label_vtbl *v14; // esi
  const char *Name; // eax
  KeyValues *v16; // ecx
  KeyValues *j; // ebx
  const char *v18; // eax
  const char *v19; // eax
  KeyValues *NextKey; // esi
  const char *v21; // eax
  const char *v22; // eax
  vgui::Button *v23; // eax
  vgui::Button *v24; // esi
  const char *v25; // eax
  KeyValues *v26; // eax
  int m_Size; // esi
  int m_nAllocationCount; // eax
  vgui::Button **m_pMemory; // ecx
  int v30; // eax
  vgui::Button **v31; // esi
  const char *v32; // [esp-4h] [ebp-118h]
  const char *v33; // [esp-4h] [ebp-118h]
  const char *v34; // [esp-4h] [ebp-118h]
  char buffer[256]; // [esp+Ch] [ebp-108h] BYREF
  KeyValues *v36; // [esp+10Ch] [ebp-8h]
  vgui::Button *pAdd; // [esp+110h] [ebp-4h]

  m_pFileSpecNode = this->m_pFileSpecNode;
  if ( m_pFileSpecNode != nullptr )
  {
    v3 = this->m_pDeleteButton->__vftable;
    Key = KeyValues::FindKey(this: m_pFileSpecNode, keyName: "Autocreate", bCreate: false);
    v3->SetVisible(this: this->m_pDeleteButton, a2: Key == nullptr);
  }
  for ( i = 0; i < this->m_pAddButtons.m_Size; ++i )
  {
    v6 = this->m_pAddButtons.m_Memory.m_pMemory[i];
    v6->SetVisible(this: v6, a2: false);
    v7 = this->m_pAddButtons.m_Memory.m_pMemory[i];
    v7->MarkForDeletion(this: v7);
  }
  this->m_pAddButtons.m_Size = 0;
  if ( this->m_pAddButtons.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_pAddButtons.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pAddButtons.m_Memory.m_pMemory);
      this->m_pAddButtons.m_Memory.m_pMemory = nullptr;
    }
    this->m_pAddButtons.m_Memory.m_nAllocationCount = 0;
  }
  this->m_pAddButtons.m_pElements = this->m_pAddButtons.m_Memory.m_pMemory;
  if ( this->m_pKey != nullptr )
  {
    v8 = this->m_pFileSpecNode;
    if ( v8 != nullptr && KeyValues::FindKey(this: v8, keyName: "FriendlyName", bCreate: false) != nullptr )
    {
      v9 = this->m_pLabel->__vftable;
      String = KeyValues::GetString(this: this->m_pFileSpecNode, keyName: "FriendlyName", defaultValue: &defaultValue);
      v9->SetText(this: this->m_pLabel, a2: String);
      v11 = this->m_pLabel->__vftable;
      v12 = KeyValues::GetString(this: this->m_pFileSpecNode, keyName: "FriendlyName", defaultValue: &defaultValue);
      v13 = _V_strlen(str: v12);
      v11->SetVisible(this: this->m_pLabel, a2: v13 > 0);
    }
    else
    {
      v14 = this->m_pLabel->__vftable;
      Name = KeyValues::GetName(this: this->m_pKey);
      v14->SetText(this: this->m_pLabel, a2: Name);
    }
    v16 = this->m_pFileSpecNode;
    if ( v16 != nullptr )
    {
      for ( j = KeyValues::GetFirstSubKey(this: v16); j != nullptr; j = KeyValues::GetNextKey(this: j) )
      {
        v18 = KeyValues::GetName(this: j);
        if ( _V_stricmp(s1: v18, s2: "_Node") != 0 )
        {
          v19 = KeyValues::GetName(this: j);
          if ( _V_stricmp(s1: v19, s2: "_Leaf") != 0 )
            continue;
        }
        if ( KeyValues::FindKey(this: j, keyName: "Unique", bCreate: false) != nullptr
          && (NextKey = KeyValues::GetFirstSubKey(this: this->m_pKey)) != nullptr )
        {
          while ( 1 )
          {
            v32 = KeyValues::GetString(this: j, keyName: "Name", defaultValue: &defaultValue);
            v21 = KeyValues::GetName(this: NextKey);
            if ( _V_stricmp(s1: v21, s2: v32) == 0 )
              break;
            NextKey = KeyValues::GetNextKey(this: NextKey);
            if ( NextKey == nullptr )
              goto LABEL_23;
          }
        }
        else
        {
LABEL_23:
          if ( this->m_pFileSpecNode != nullptr
            && KeyValues::FindKey(this: j, keyName: "FriendlyAddButtonText", bCreate: false) != nullptr )
          {
            v33 = KeyValues::GetString(this: j, keyName: "FriendlyAddButtonText", defaultValue: "ADD BUTTON ERROR");
            V_snprintf(pDest: buffer, maxLen: 256, pFormat: "%s", v33);
          }
          else
          {
            v22 = KeyValues::GetString(this: j, keyName: "Name", defaultValue: "Unknown key");
            v34 = KeyValues::GetString(this: j, keyName: "FriendlyName", defaultValue: v22);
            V_snprintf(pDest: buffer, maxLen: 256, pFormat: "Add %s", v34);
          }
          v23 = (vgui::Button *)operator new(nSize: 0x1F4u);
          if ( v23 != nullptr )
          {
            v24 = vgui::Button::Button(
                    this: v23,
                    parent: this,
                    panelName: "AddButton",
                    text: buffer,
                    pActionSignalTarget: this,
                    pCmd: nullptr);
            pAdd = v24;
          }
          else
          {
            pAdd = nullptr;
            v24 = nullptr;
          }
          v36 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v36 != nullptr )
          {
            v25 = KeyValues::GetString(this: j, keyName: "Name", defaultValue: "Unknown key");
            v26 = KeyValues::KeyValues(this: v36, setName: "AddButtonPressed", firstKey: "szKeyName", firstValue: v25);
          }
          else
          {
            v26 = nullptr;
          }
          v24->SetCommand(this: v24, a2: v26);
          m_Size = this->m_pAddButtons.m_Size;
          m_nAllocationCount = this->m_pAddButtons.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<unsigned long,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_pAddButtons,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_pAddButtons.m_Size;
          m_pMemory = this->m_pAddButtons.m_Memory.m_pMemory;
          v30 = this->m_pAddButtons.m_Size - m_Size - 1;
          this->m_pAddButtons.m_pElements = m_pMemory;
          if ( v30 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v30);
          v31 = &this->m_pAddButtons.m_Memory.m_pMemory[m_Size];
          if ( v31 != nullptr )
            *v31 = pAdd;
        }
      }
    }
  }
  else
  {
    this->m_pLabel->SetText(this: this->m_pLabel, a2: "INVALID KEY");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409480
// Name: public: CKV_Node_Panel::CKV_Node_Panel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CKV_Node_Panel *__thiscall CKV_Node_Panel::CKV_Node_Panel(CKV_Node_Panel *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Label *v7; // eax
  vgui::Label *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  CKV_Fit_Children_Panel::CKV_Fit_Children_Panel(this, parent, name);
  this->__vftable = (CKV_Node_Panel_vtbl *)&CKV_Node_Panel::`vftable';
  if ( `CKV_Node_Panel::ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Node_Panel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CKV_Node_Panel");
    v4->pfnClassName = CKV_Node_Panel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CKV_Fit_Children_Panel");
  }
  if ( `CKV_Node_Panel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CKV_Node_Panel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CKV_Node_Panel");
    v5->pfnClassName = CKV_Node_Panel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CKV_Fit_Children_Panel");
  }
  if ( `CKV_Node_Panel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Node_Panel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Node_Panel");
    v6->pfnClassName = CKV_Node_Panel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Fit_Children_Panel");
  }
  this->m_pAddButtons.m_Memory.m_pMemory = nullptr;
  this->m_pAddButtons.m_Memory.m_nAllocationCount = 0;
  this->m_pAddButtons.m_Memory.m_nGrowSize = 0;
  this->m_pAddButtons.m_Size = 0;
  this->m_pAddButtons.m_pElements = nullptr;
  CKV_Node_Panel::PanelMessageFunc_OnAddButtonPressed::InitVar(a1: (int)&savedregs);
  CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetX::InitVar();
  this->m_iLabelInsetX = 2;
  CKV_Node_Panel::PanelAnimationVar_m_iLabelInsetY::InitVar();
  this->m_iLabelInsetY = 2;
  v7 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v7 != nullptr )
    v8 = vgui::Label::Label(this: v7, parent: this, panelName: "Label", text: &defaultValue);
  else
    v8 = nullptr;
  this->m_pLabel = v8;
  v8->SetMouseInputEnabled(this: v8, a2: false);
  v9 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "DeleteButton",
            text: "X",
            pActionSignalTarget: this,
            pCmd: "Delete");
  else
    v10 = nullptr;
  this->m_pDeleteButton = v10;
  vgui::Panel::SetKeyBoardInputEnabled(this, state: false);
  this->m_iAutoPositionStartY = 30;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00409600
// Name: public: virtual struct vgui::PanelMessageMap __near * CKV_Node_Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CKV_Node_Panel::GetMessageMap(CKV_Node_Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CKV_Node_Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Node_Panel::GetMessageMap'::`2'::s_pMap;
  `CKV_Node_Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CKV_Node_Panel");
  `CKV_Node_Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409630
// Name: public: virtual struct PanelAnimationMap __near * CKV_Node_Panel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CKV_Node_Panel::GetAnimMap(CKV_Node_Panel *this)
{
  return FindOrAddPanelAnimationMap(className: "CKV_Node_Panel");
}

//------------------------------------------------------------------------------
// Address: 0x00409640
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CKV_Node_Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CKV_Node_Panel::GetKBMap(CKV_Node_Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CKV_Node_Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Node_Panel::GetKBMap'::`2'::s_pMap;
  `CKV_Node_Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Node_Panel");
  `CKV_Node_Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004096B0
// Name: Create_CKV_Node_Panel
// Source: json
//------------------------------------------------------------------------------
CKV_Node_Panel *__cdecl Create_CKV_Node_Panel()
{
  CKV_Node_Panel *v0; // eax

  v0 = (CKV_Node_Panel *)operator new(nSize: 0x1FCu);
  if ( v0 != nullptr )
    return CKV_Node_Panel::CKV_Node_Panel(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}

} // namespace vgui_editor
