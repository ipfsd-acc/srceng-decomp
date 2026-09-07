// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/keyvalues_editor/kv_fit_children_panel.cpp
// Functions: 12
// ============================================================

#include "missionchooser\keyvalues_editor\kv_fit_children_panel.h"

//------------------------------------------------------------------------------
// Address: 0x1000E680
// Name: public: static char const __near * CKV_Fit_Children_Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CKV_Fit_Children_Panel::GetPanelClassName()
{
  return "CKV_Fit_Children_Panel";
}

//------------------------------------------------------------------------------
// Address: 0x1000E690
// Name: public: static void __near * CKV_Fit_Children_Panel::GetVar_m_iBorder(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int **__cdecl CKV_Fit_Children_Panel::GetVar_m_iBorder(vgui::Panel *panel)
{
  return &panel[1]._actionSignalTargetDar.m_pElements;
}

//------------------------------------------------------------------------------
// Address: 0x1000E6A0
// Name: public: static void __near * CKV_Fit_Children_Panel::GetVar_m_iSpacing(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int *__cdecl CKV_Fit_Children_Panel::GetVar_m_iSpacing(vgui::Panel *panel)
{
  return &panel[1].m_OverridableColorEntries.m_Memory.m_nAllocationCount;
}

//------------------------------------------------------------------------------
// Address: 0x1000E6B0
// Name: public: virtual void CKV_Fit_Children_Panel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Fit_Children_Panel::PerformLayout(CKV_Fit_Children_Panel *this)
{
  KeyValues *m_pFileSpecNode; // ecx
  int Int; // eax
  KeyValues *v4; // ecx
  int v5; // eax
  KeyValues *v6; // ecx
  int m_iAutoPositionStartY; // ebx
  CKV_Editor_Base_Panel *v8; // esi
  void *v9; // eax
  int v10; // eax
  int v11; // eax
  int m_iBorder; // [esp-4h] [ebp-2Ch]
  int m_iSpacing; // [esp-4h] [ebp-2Ch]
  int v14; // [esp+Ch] [ebp-1Ch]
  int wide; // [esp+10h] [ebp-18h]
  int tall; // [esp+14h] [ebp-14h]
  int i; // [esp+18h] [ebp-10h]
  int y; // [esp+1Ch] [ebp-Ch] BYREF
  int x; // [esp+20h] [ebp-8h] BYREF
  bool bNode; // [esp+27h] [ebp-1h]

  CKV_Editor_Base_Panel::PerformLayout(this);
  m_pFileSpecNode = this->m_pFileSpecNode;
  if ( m_pFileSpecNode != nullptr )
  {
    Int = KeyValues::GetInt(
            this: m_pFileSpecNode,
            keyName: "AutoPositionStartY",
            defaultValue: this->m_iAutoPositionStartY);
    m_iBorder = this->m_iBorder;
    v4 = this->m_pFileSpecNode;
    this->m_iAutoPositionStartY = Int;
    v5 = KeyValues::GetInt(this: v4, keyName: "Border", defaultValue: m_iBorder);
    v6 = this->m_pFileSpecNode;
    m_iSpacing = this->m_iSpacing;
    this->m_iBorder = v5;
    this->m_iSpacing = KeyValues::GetInt(this: v6, keyName: "Spacing", defaultValue: m_iSpacing);
  }
  m_iAutoPositionStartY = this->m_iAutoPositionStartY;
  wide = 0;
  tall = m_iAutoPositionStartY;
  for ( i = 0; i < this->m_AutoPositionPanels.m_Size; ++i )
  {
    v8 = this->m_AutoPositionPanels.m_Memory.m_pMemory[i];
    v9 = __RTDynamicCast(
           inptr: v8,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &CKV_Fit_Children_Panel `RTTI Type Descriptor',
           isReference: 0);
    bNode = v9 != nullptr;
    if ( v9 != nullptr )
      m_iAutoPositionStartY += 2 * this->m_iSpacing;
    vgui::Panel::SetPos(this: v8, x: this->m_iBorder, y: m_iAutoPositionStartY);
    v8->InvalidateLayout(this: v8, a2: true, a3: false);
    vgui::Panel::GetPos(this: v8, &x, &y);
    v10 = vgui::Panel::GetWide(this: v8);
    x += v10;
    v11 = vgui::Panel::GetTall(this: v8);
    y += v11;
    v14 = this->m_iSpacing;
    m_iAutoPositionStartY += v14 + vgui::Panel::GetTall(this: v8);
    if ( bNode )
      m_iAutoPositionStartY += 2 * v14;
    if ( wide <= x )
      wide = x;
    if ( tall <= y )
      tall = y;
  }
  vgui::Panel::SetSize(this, wide: wide + this->m_iBorder, tall: this->m_iBorder + tall);
}

//------------------------------------------------------------------------------
// Address: 0x1000EC10
// Name: public: void CKV_Fit_Children_Panel::RemoveAutoPositionPanel(class CKV_Editor_Base_Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Fit_Children_Panel::RemoveAutoPositionPanel(
        CKV_Fit_Children_Panel *this,
        CKV_Editor_Base_Panel *pPanel)
{
  CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc>::Remove(
    this: &this->m_AutoPositionPanels,
    search: &pPanel);
}

//------------------------------------------------------------------------------
// Address: 0x1000ED00
// Name: public: static void CKV_Fit_Children_Panel::PanelAnimationVar_m_iBorder::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CKV_Fit_Children_Panel::PanelAnimationVar_m_iBorder::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CKV_Fit_Children_Panel::PanelAnimationVar_m_iBorder::InitVar'::`2'::bAdded )
  {
    `CKV_Fit_Children_Panel::PanelAnimationVar_m_iBorder::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CKV_Fit_Children_Panel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "border";
    src.m_pszVariable = "m_iBorder";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "5";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CKV_Fit_Children_Panel::GetVar_m_iBorder;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000ED60
// Name: public: static void CKV_Fit_Children_Panel::PanelAnimationVar_m_iSpacing::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CKV_Fit_Children_Panel::PanelAnimationVar_m_iSpacing::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CKV_Fit_Children_Panel::PanelAnimationVar_m_iSpacing::InitVar'::`2'::bAdded )
  {
    `CKV_Fit_Children_Panel::PanelAnimationVar_m_iSpacing::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CKV_Fit_Children_Panel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "spacing";
    src.m_pszVariable = "m_iSpacing";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "1";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CKV_Fit_Children_Panel::GetVar_m_iSpacing;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EDC0
// Name: public: void CKV_Fit_Children_Panel::AddAutoPositionPanel(class CKV_Editor_Base_Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Fit_Children_Panel::AddAutoPositionPanel(
        CKV_Fit_Children_Panel *this,
        CKV_Editor_Base_Panel *pPanel)
{
  CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc>::Insert(this: &this->m_AutoPositionPanels, src: &pPanel);
}

//------------------------------------------------------------------------------
// Address: 0x1000EDE0
// Name: public: CKV_Fit_Children_Panel::CKV_Fit_Children_Panel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CKV_Fit_Children_Panel *__thiscall CKV_Fit_Children_Panel::CKV_Fit_Children_Panel(
        CKV_Fit_Children_Panel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CKV_Editor_Base_Panel::CKV_Editor_Base_Panel(this, parent, name);
  this->__vftable = (CKV_Fit_Children_Panel_vtbl *)&CKV_Fit_Children_Panel::`vftable';
  if ( `CKV_Fit_Children_Panel::ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Fit_Children_Panel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CKV_Fit_Children_Panel");
    v4->pfnClassName = CKV_Fit_Children_Panel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CKV_Editor_Base_Panel");
  }
  if ( `CKV_Fit_Children_Panel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CKV_Fit_Children_Panel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CKV_Fit_Children_Panel");
    v5->pfnClassName = CKV_Fit_Children_Panel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CKV_Editor_Base_Panel");
  }
  if ( `CKV_Fit_Children_Panel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Fit_Children_Panel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Fit_Children_Panel");
    v6->pfnClassName = CKV_Fit_Children_Panel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Editor_Base_Panel");
  }
  this->m_AutoPositionPanels.m_Memory.m_pMemory = nullptr;
  this->m_AutoPositionPanels.m_Memory.m_nAllocationCount = 0;
  this->m_AutoPositionPanels.m_Memory.m_nGrowSize = 0;
  this->m_AutoPositionPanels.m_Size = 0;
  this->m_AutoPositionPanels.m_pElements = nullptr;
  this->m_AutoPositionPanels.m_pLessContext = nullptr;
  this->m_AutoPositionPanels.m_bNeedsSort = false;
  this->m_iAutoPositionStartY = 5;
  CKV_Fit_Children_Panel::PanelAnimationVar_m_iBorder::InitVar();
  this->m_iBorder = 5;
  CKV_Fit_Children_Panel::PanelAnimationVar_m_iSpacing::InitVar();
  this->m_iSpacing = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000EEF0
// Name: public: virtual struct vgui::PanelMessageMap __near * CKV_Fit_Children_Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CKV_Fit_Children_Panel::GetMessageMap(CKV_Fit_Children_Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CKV_Fit_Children_Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Fit_Children_Panel::GetMessageMap'::`2'::s_pMap;
  `CKV_Fit_Children_Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CKV_Fit_Children_Panel");
  `CKV_Fit_Children_Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000EF20
// Name: public: virtual struct PanelAnimationMap __near * CKV_Fit_Children_Panel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CKV_Fit_Children_Panel::GetAnimMap(CKV_Fit_Children_Panel *this)
{
  return FindOrAddPanelAnimationMap(className: "CKV_Fit_Children_Panel");
}

//------------------------------------------------------------------------------
// Address: 0x1000EF30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CKV_Fit_Children_Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CKV_Fit_Children_Panel::GetKBMap(CKV_Fit_Children_Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CKV_Fit_Children_Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Fit_Children_Panel::GetKBMap'::`2'::s_pMap;
  `CKV_Fit_Children_Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Fit_Children_Panel");
  `CKV_Fit_Children_Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x00407ED0
// Name: public: static char const __near * CKV_Fit_Children_Panel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CKV_Fit_Children_Panel::GetPanelClassName()
{
  return "CKV_Fit_Children_Panel";
}

//------------------------------------------------------------------------------
// Address: 0x00407EE0
// Name: public: static void __near * CKV_Fit_Children_Panel::GetVar_m_iBorder(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int **__cdecl CKV_Fit_Children_Panel::GetVar_m_iBorder(vgui::Panel *panel)
{
  return &panel[1]._actionSignalTargetDar.m_pElements;
}

//------------------------------------------------------------------------------
// Address: 0x00407EF0
// Name: public: static void __near * CKV_Fit_Children_Panel::GetVar_m_iSpacing(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int *__cdecl CKV_Fit_Children_Panel::GetVar_m_iSpacing(vgui::Panel *panel)
{
  return &panel[1].m_OverridableColorEntries.m_Memory.m_nAllocationCount;
}

//------------------------------------------------------------------------------
// Address: 0x00407F00
// Name: public: virtual void CKV_Fit_Children_Panel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Fit_Children_Panel::PerformLayout(CKV_Fit_Children_Panel *this)
{
  KeyValues *m_pFileSpecNode; // ecx
  int Int; // eax
  KeyValues *v4; // ecx
  int v5; // eax
  KeyValues *v6; // ecx
  int m_iAutoPositionStartY; // ebx
  CKV_Editor_Base_Panel *v8; // esi
  void *v9; // eax
  int v10; // eax
  int v11; // eax
  int m_iBorder; // [esp-4h] [ebp-2Ch]
  int m_iSpacing; // [esp-4h] [ebp-2Ch]
  int v14; // [esp+Ch] [ebp-1Ch]
  int wide; // [esp+10h] [ebp-18h]
  int tall; // [esp+14h] [ebp-14h]
  int i; // [esp+18h] [ebp-10h]
  int y; // [esp+1Ch] [ebp-Ch] BYREF
  int x; // [esp+20h] [ebp-8h] BYREF
  bool bNode; // [esp+27h] [ebp-1h]

  CKV_Editor_Base_Panel::PerformLayout(this);
  m_pFileSpecNode = this->m_pFileSpecNode;
  if ( m_pFileSpecNode != nullptr )
  {
    Int = KeyValues::GetInt(
            this: m_pFileSpecNode,
            keyName: "AutoPositionStartY",
            defaultValue: this->m_iAutoPositionStartY);
    m_iBorder = this->m_iBorder;
    v4 = this->m_pFileSpecNode;
    this->m_iAutoPositionStartY = Int;
    v5 = KeyValues::GetInt(this: v4, keyName: "Border", defaultValue: m_iBorder);
    v6 = this->m_pFileSpecNode;
    m_iSpacing = this->m_iSpacing;
    this->m_iBorder = v5;
    this->m_iSpacing = KeyValues::GetInt(this: v6, keyName: "Spacing", defaultValue: m_iSpacing);
  }
  m_iAutoPositionStartY = this->m_iAutoPositionStartY;
  wide = 0;
  tall = m_iAutoPositionStartY;
  for ( i = 0; i < this->m_AutoPositionPanels.m_Size; ++i )
  {
    v8 = this->m_AutoPositionPanels.m_Memory.m_pMemory[i];
    v9 = __RTDynamicCast(
           inptr: v8,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &CKV_Fit_Children_Panel `RTTI Type Descriptor',
           isReference: 0);
    bNode = v9 != nullptr;
    if ( v9 != nullptr )
      m_iAutoPositionStartY += 2 * this->m_iSpacing;
    vgui::Panel::SetPos(this: v8, x: this->m_iBorder, y: m_iAutoPositionStartY);
    v8->InvalidateLayout(this: v8, a2: true, a3: false);
    vgui::Panel::GetPos(this: v8, &x, &y);
    v10 = vgui::Panel::GetWide(this: v8);
    x += v10;
    v11 = vgui::Panel::GetTall(this: v8);
    y += v11;
    v14 = this->m_iSpacing;
    m_iAutoPositionStartY += v14 + vgui::Panel::GetTall(this: v8);
    if ( bNode )
      m_iAutoPositionStartY += 2 * v14;
    if ( wide <= x )
      wide = x;
    if ( tall <= y )
      tall = y;
  }
  vgui::Panel::SetSize(this, wide: wide + this->m_iBorder, tall: this->m_iBorder + tall);
}

//------------------------------------------------------------------------------
// Address: 0x00408080
// Name: public: int CUtlSortVector<class CKV_Editor_Base_Panel __near *,class FitChildrenLessFunc>::Find(class CKV_Editor_Base_Panel __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc>::Find(
        CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc> *this,
        CKV_Editor_Base_Panel *const *src)
{
  CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc> *v2; // edi
  int v3; // eax
  int v4; // ecx
  int v5; // esi
  CKV_Editor_Base_Panel *v6; // edi
  CKV_Editor_Base_Panel *const *v7; // eax
  vgui::Panel *v8; // edx
  CKV_Editor_Base_Panel *v9; // ecx
  CKV_Editor_Base_Panel *v10; // eax
  vgui::Panel **v11; // edi
  int v13; // ebx
  int ZPos; // [esp+Ch] [ebp-10h]
  int start; // [esp+14h] [ebp-8h]
  int end; // [esp+18h] [ebp-4h]

  v2 = this;
  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h", a2: 215);
  }
  v3 = 0;
  v4 = v2->m_Size - 1;
  start = 0;
  end = v4;
  if ( v4 >= 0 )
  {
    while ( 1 )
    {
      v5 = (v4 + v3) >> 1;
      v6 = v2->m_Memory.m_pMemory[v5];
      v7 = src;
      v8 = *src;
      if ( v6 != nullptr && v8 != nullptr )
      {
        if ( *(float *)&v8[1].m_hKeyBindingsContext > v6->m_flSortOrder )
          goto LABEL_14;
      }
      else
      {
        ZPos = vgui::Panel::GetZPos(this: *(vgui::Panel **)src);
        if ( vgui::Panel::GetZPos(this: v6) < ZPos )
        {
          v4 = end;
LABEL_14:
          start = v5 + 1;
          goto LABEL_22;
        }
        v7 = src;
      }
      v9 = *v7;
      v10 = this->m_Memory.m_pMemory[v5];
      v11 = &this->m_Memory.m_pMemory[v5];
      if ( v9 != nullptr && v10 != nullptr )
      {
        if ( v10->m_flSortOrder <= v9->m_flSortOrder )
          return v5;
      }
      else
      {
        v13 = vgui::Panel::GetZPos(this: v9);
        if ( v13 >= vgui::Panel::GetZPos(this: *v11) )
          return v5;
      }
      end = v5 - 1;
      v4 = v5 - 1;
LABEL_22:
      v3 = start;
      if ( start > v4 )
        return -1;
      v2 = this;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004081D0
// Name: public: int CUtlSortVector<class CKV_Editor_Base_Panel __near *,class FitChildrenLessFunc>::FindLessOrEqual(class CKV_Editor_Base_Panel __near * const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc>::FindLessOrEqual(
        CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc> *this,
        CKV_Editor_Base_Panel *const *src)
{
  CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc> *v2; // edi
  int v3; // eax
  int v4; // ecx
  int v5; // esi
  CKV_Editor_Base_Panel *v6; // edi
  CKV_Editor_Base_Panel *const *v7; // eax
  vgui::Panel *v8; // edx
  CKV_Editor_Base_Panel *v9; // ecx
  CKV_Editor_Base_Panel *v10; // eax
  vgui::Panel **v11; // edi
  int v13; // ebx
  int ZPos; // [esp+Ch] [ebp-10h]
  int start; // [esp+14h] [ebp-8h]
  int end; // [esp+18h] [ebp-4h]

  v2 = this;
  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h", a2: 277);
  }
  v3 = 0;
  v4 = v2->m_Size - 1;
  start = 0;
  end = v4;
  if ( v4 >= 0 )
  {
    while ( 1 )
    {
      v5 = (v4 + v3) >> 1;
      v6 = v2->m_Memory.m_pMemory[v5];
      v7 = src;
      v8 = *src;
      if ( v6 != nullptr && v8 != nullptr )
      {
        if ( *(float *)&v8[1].m_hKeyBindingsContext > v6->m_flSortOrder )
          goto LABEL_14;
      }
      else
      {
        ZPos = vgui::Panel::GetZPos(this: *(vgui::Panel **)src);
        if ( vgui::Panel::GetZPos(this: v6) < ZPos )
        {
          v4 = end;
LABEL_14:
          start = v5 + 1;
          goto LABEL_22;
        }
        v7 = src;
      }
      v9 = *v7;
      v10 = this->m_Memory.m_pMemory[v5];
      v11 = &this->m_Memory.m_pMemory[v5];
      if ( v9 != nullptr && v10 != nullptr )
      {
        if ( v10->m_flSortOrder <= v9->m_flSortOrder )
          return v5;
      }
      else
      {
        v13 = vgui::Panel::GetZPos(this: v9);
        if ( v13 >= vgui::Panel::GetZPos(this: *v11) )
          return v5;
      }
      end = v5 - 1;
      v4 = v5 - 1;
LABEL_22:
      v3 = start;
      if ( start > v4 )
        return v4;
      v2 = this;
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00408320
// Name: public: void CUtlSortVector<class CKV_Editor_Base_Panel __near *,class FitChildrenLessFunc>::Remove(class CKV_Editor_Base_Panel __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc>::Remove(
        CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc> *this,
        CKV_Editor_Base_Panel *const *search)
{
  int v3; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
         329,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
                            a2: 329,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h", a2: 329);
  }
  v3 = CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc>::Find(this, src: search);
  if ( v3 != -1 )
  {
    if ( this->m_Size - v3 - 1 > 0 )
      _V_memmove(
        dest: &this->m_Memory.m_pMemory[v3],
        src: &this->m_Memory.m_pMemory[v3 + 1],
        count: 4 * (this->m_Size - v3 - 1));
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408460
// Name: public: void CKV_Fit_Children_Panel::RemoveAutoPositionPanel(class CKV_Editor_Base_Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Fit_Children_Panel::RemoveAutoPositionPanel(
        CKV_Fit_Children_Panel *this,
        CKV_Editor_Base_Panel *pPanel)
{
  CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc>::Remove(
    this: &this->m_AutoPositionPanels,
    search: &pPanel);
}

//------------------------------------------------------------------------------
// Address: 0x00408480
// Name: public: int CUtlSortVector<class CKV_Editor_Base_Panel __near *,class FitChildrenLessFunc>::Insert(class CKV_Editor_Base_Panel __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc>::Insert(
        CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc> *this,
        CKV_Editor_Base_Panel *const *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  CKV_Editor_Base_Panel **m_pMemory; // ecx
  int v8; // eax
  CKV_Editor_Base_Panel **v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(a1: "u:\\buildbot\\portal2_staging_win32\\build\\src\\public\\tier1/UtlSortVector.h", a2: 150);
  }
  LessOrEqual = CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 4 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = *src;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00408550
// Name: public: static void CKV_Fit_Children_Panel::PanelAnimationVar_m_iBorder::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CKV_Fit_Children_Panel::PanelAnimationVar_m_iBorder::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CKV_Fit_Children_Panel::PanelAnimationVar_m_iBorder::InitVar'::`2'::bAdded )
  {
    `CKV_Fit_Children_Panel::PanelAnimationVar_m_iBorder::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CKV_Fit_Children_Panel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "border";
    src.m_pszVariable = "m_iBorder";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "5";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CKV_Fit_Children_Panel::GetVar_m_iBorder;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004085B0
// Name: public: static void CKV_Fit_Children_Panel::PanelAnimationVar_m_iSpacing::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CKV_Fit_Children_Panel::PanelAnimationVar_m_iSpacing::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CKV_Fit_Children_Panel::PanelAnimationVar_m_iSpacing::InitVar'::`2'::bAdded )
  {
    `CKV_Fit_Children_Panel::PanelAnimationVar_m_iSpacing::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CKV_Fit_Children_Panel");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "spacing";
    src.m_pszVariable = "m_iSpacing";
    src.m_pszType = "proportional_int";
    src.m_pszDefaultValue = "1";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CKV_Fit_Children_Panel::GetVar_m_iSpacing;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408610
// Name: public: void CKV_Fit_Children_Panel::AddAutoPositionPanel(class CKV_Editor_Base_Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CKV_Fit_Children_Panel::AddAutoPositionPanel(
        CKV_Fit_Children_Panel *this,
        CKV_Editor_Base_Panel *pPanel)
{
  CUtlSortVector<CKV_Editor_Base_Panel *,FitChildrenLessFunc>::Insert(this: &this->m_AutoPositionPanels, src: &pPanel);
}

//------------------------------------------------------------------------------
// Address: 0x00408630
// Name: public: CKV_Fit_Children_Panel::CKV_Fit_Children_Panel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CKV_Fit_Children_Panel *__thiscall CKV_Fit_Children_Panel::CKV_Fit_Children_Panel(
        CKV_Fit_Children_Panel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CKV_Editor_Base_Panel::CKV_Editor_Base_Panel(this, parent, name);
  this->__vftable = (CKV_Fit_Children_Panel_vtbl *)&CKV_Fit_Children_Panel::`vftable';
  if ( `CKV_Fit_Children_Panel::ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Fit_Children_Panel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CKV_Fit_Children_Panel");
    v4->pfnClassName = CKV_Fit_Children_Panel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CKV_Editor_Base_Panel");
  }
  if ( `CKV_Fit_Children_Panel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CKV_Fit_Children_Panel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CKV_Fit_Children_Panel");
    v5->pfnClassName = CKV_Fit_Children_Panel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CKV_Editor_Base_Panel");
  }
  if ( `CKV_Fit_Children_Panel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CKV_Fit_Children_Panel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Fit_Children_Panel");
    v6->pfnClassName = CKV_Fit_Children_Panel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Editor_Base_Panel");
  }
  this->m_AutoPositionPanels.m_Memory.m_pMemory = nullptr;
  this->m_AutoPositionPanels.m_Memory.m_nAllocationCount = 0;
  this->m_AutoPositionPanels.m_Memory.m_nGrowSize = 0;
  this->m_AutoPositionPanels.m_Size = 0;
  this->m_AutoPositionPanels.m_pElements = nullptr;
  this->m_AutoPositionPanels.m_pLessContext = nullptr;
  this->m_AutoPositionPanels.m_bNeedsSort = false;
  this->m_iAutoPositionStartY = 5;
  CKV_Fit_Children_Panel::PanelAnimationVar_m_iBorder::InitVar();
  this->m_iBorder = 5;
  CKV_Fit_Children_Panel::PanelAnimationVar_m_iSpacing::InitVar();
  this->m_iSpacing = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00408740
// Name: public: virtual struct vgui::PanelMessageMap __near * CKV_Fit_Children_Panel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CKV_Fit_Children_Panel::GetMessageMap(CKV_Fit_Children_Panel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CKV_Fit_Children_Panel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Fit_Children_Panel::GetMessageMap'::`2'::s_pMap;
  `CKV_Fit_Children_Panel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CKV_Fit_Children_Panel");
  `CKV_Fit_Children_Panel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408770
// Name: public: virtual struct PanelAnimationMap __near * CKV_Fit_Children_Panel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CKV_Fit_Children_Panel::GetAnimMap(CKV_Fit_Children_Panel *this)
{
  return FindOrAddPanelAnimationMap(className: "CKV_Fit_Children_Panel");
}

//------------------------------------------------------------------------------
// Address: 0x00408780
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CKV_Fit_Children_Panel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CKV_Fit_Children_Panel::GetKBMap(CKV_Fit_Children_Panel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CKV_Fit_Children_Panel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CKV_Fit_Children_Panel::GetKBMap'::`2'::s_pMap;
  `CKV_Fit_Children_Panel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CKV_Fit_Children_Panel");
  `CKV_Fit_Children_Panel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace vgui_editor
