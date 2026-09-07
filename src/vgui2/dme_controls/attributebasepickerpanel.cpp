// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributebasepickerpanel.cpp
// Functions: 6
// ============================================================

#include "vgui2\dme_controls\attributebasepickerpanel.h"

//------------------------------------------------------------------------------
// Address: 0x0046D570
// Name: public: static char const __near * CAttributeBasePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeBasePickerPanel::GetPanelClassName()
{
  return "CAttributeBasePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0046D580
// Name: public: virtual void CAttributeBasePickerPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBasePickerPanel::PerformLayout(CAttributeBasePickerPanel *this)
{
  vgui::IImage *v2; // eax
  vgui::Button *m_pOpen; // ecx
  int viewWidth; // [esp+4h] [ebp-8h] BYREF
  int viewHeight; // [esp+8h] [ebp-4h] BYREF

  CBaseAttributePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &viewWidth, tall: &viewHeight);
  v2 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_properties_linkarrow", a3: 0);
  m_pOpen = this->m_pOpen;
  if ( v2 != nullptr )
  {
    m_pOpen->SetImage(this: m_pOpen, a2: v2, a3: 0);
    this->m_pOpen->SetPaintBorderEnabled(this: this->m_pOpen, a2: false);
    this->m_pOpen->SetContentAlignment(this: this->m_pOpen, a2: a_center);
    vgui::Panel::SetBounds(this: this->m_pOpen, x: 6, y: (int)((double)(viewHeight - 16) * 0.5), wide: 16, tall: 16);
  }
  else
  {
    vgui::Panel::SetBounds(this: m_pOpen, x: 0, y: 0, wide: 50, tall: 20);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D630
// Name: public: CAttributeBasePickerPanel::CAttributeBasePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBasePickerPanel *__thiscall CAttributeBasePickerPanel::CAttributeBasePickerPanel(
        CAttributeBasePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Button *v7; // eax

  CAttributeTextPanel::CAttributeTextPanel(this, parent, info);
  this->__vftable = (CAttributeBasePickerPanel_vtbl *)&CAttributeBasePickerPanel::`vftable';
  if ( `CAttributeBasePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBasePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
    v4->pfnClassName = CAttributeBasePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeBasePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeBasePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
    v5->pfnClassName = CAttributeBasePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeBasePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBasePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
    v6->pfnClassName = CAttributeBasePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextPanel");
  }
  v7 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v7 != nullptr )
    this->m_pOpen = vgui::Button::Button(
                      this: v7,
                      parent: this,
                      panelName: "Open",
                      text: "...",
                      pActionSignalTarget: this,
                      pCmd: "open");
  else
    this->m_pOpen = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0046D730
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeBasePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeBasePickerPanel::GetMessageMap(CAttributeBasePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeBasePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBasePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeBasePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  `CAttributeBasePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046D760
// Name: public: virtual struct PanelAnimationMap __near * CAttributeBasePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeBasePickerPanel::GetAnimMap(CAttributeBasePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0046D770
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeBasePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeBasePickerPanel::GetKBMap(CAttributeBasePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeBasePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBasePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeBasePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  `CAttributeBasePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10490A50
// Name: public: static char const __near * CAttributeBasePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeBasePickerPanel::GetPanelClassName()
{
  return "CAttributeBasePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10490A60
// Name: public: virtual void CAttributeBasePickerPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBasePickerPanel::PerformLayout(CAttributeBasePickerPanel *this)
{
  vgui::IImage *v2; // eax
  vgui::Button *m_pOpen; // ecx
  int viewWidth; // [esp+4h] [ebp-8h] BYREF
  int viewHeight; // [esp+8h] [ebp-4h] BYREF

  CBaseAttributePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &viewWidth, tall: &viewHeight);
  v2 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_properties_linkarrow", a3: 0);
  m_pOpen = this->m_pOpen;
  if ( v2 != nullptr )
  {
    m_pOpen->SetImage(this: m_pOpen, a2: v2, a3: 0);
    this->m_pOpen->SetPaintBorderEnabled(this: this->m_pOpen, a2: false);
    this->m_pOpen->SetContentAlignment(this: this->m_pOpen, a2: a_center);
    vgui::Panel::SetBounds(this: this->m_pOpen, x: 6, y: (int)((double)(viewHeight - 16) * 0.5), wide: 16, tall: 16);
  }
  else
  {
    vgui::Panel::SetBounds(this: m_pOpen, x: 0, y: 0, wide: 50, tall: 20);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10490B10
// Name: public: CAttributeBasePickerPanel::CAttributeBasePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBasePickerPanel *__thiscall CAttributeBasePickerPanel::CAttributeBasePickerPanel(
        CAttributeBasePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Button *v7; // eax

  CAttributeTextPanel::CAttributeTextPanel(this, parent, info);
  this->__vftable = (CAttributeBasePickerPanel_vtbl *)&CAttributeBasePickerPanel::`vftable';
  if ( `CAttributeBasePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBasePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
    v4->pfnClassName = CAttributeBasePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeBasePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeBasePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
    v5->pfnClassName = CAttributeBasePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeBasePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBasePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
    v6->pfnClassName = CAttributeBasePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextPanel");
  }
  v7 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v7 != nullptr )
    this->m_pOpen = vgui::Button::Button(
                      this: v7,
                      parent: this,
                      panelName: "Open",
                      text: "...",
                      pActionSignalTarget: this,
                      pCmd: "open");
  else
    this->m_pOpen = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10490C10
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeBasePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeBasePickerPanel::GetMessageMap(CAttributeBasePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeBasePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBasePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeBasePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  `CAttributeBasePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10490C40
// Name: public: virtual struct PanelAnimationMap __near * CAttributeBasePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeBasePickerPanel::GetAnimMap(CAttributeBasePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10490C50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeBasePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeBasePickerPanel::GetKBMap(CAttributeBasePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeBasePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBasePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeBasePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  `CAttributeBasePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C4360
// Name: _dynamic_initializer_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__panel_test_title_safe__()
{
  ConVar::ConVar(
    this: &panel_test_title_safe,
    pName: "panel_test_title_safe",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Test vgui panel positioning with title safe indentation");
  return atexit(func: dynamic_atexit_destructor_for__panel_test_title_safe__);
}

//------------------------------------------------------------------------------
// Address: 0x105CBFD0
// Name: _dynamic_atexit_destructor_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__panel_test_title_safe__()
{
  ConVar::~ConVar(this: &panel_test_title_safe);
}

//------------------------------------------------------------------------------
// Address: 0x105CBE80
// Name: _dynamic_atexit_destructor_for__mat_normals__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_normals__()
{
  ConVar::~ConVar(this: &mat_normals);
}

//------------------------------------------------------------------------------
// Address: 0x105CBE90
// Name: _dynamic_atexit_destructor_for__r_eyeglintlodpixels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_eyeglintlodpixels__()
{
  ConVar::~ConVar(this: &r_eyeglintlodpixels);
}

//------------------------------------------------------------------------------
// Address: 0x105CBEA0
// Name: _dynamic_atexit_destructor_for__r_rootlod__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_rootlod__()
{
  ConVar::~ConVar(this: &r_rootlod);
}

//------------------------------------------------------------------------------
// Address: 0x105CBEE0
// Name: _dynamic_atexit_destructor_for__s_ParticleSystemMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ParticleSystemMgr__()
{
  CParticleSystemMgr::~CParticleSystemMgr(this: &s_ParticleSystemMgr);
}

//------------------------------------------------------------------------------
// Address: 0x105CBEF0
// Name: _dynamic_atexit_destructor_for__r_sse_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_sse_s__()
{
  ConVar::~ConVar(this: &r_sse_s);
}

//------------------------------------------------------------------------------
// Address: 0x105CBF00
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x105CBF10
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    operator delete(p: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x105CBF50
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    operator delete(p: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x105CBFA0
// Name: _dynamic_atexit_destructor_for__g_ToolDictionary__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ToolDictionary__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_ToolDictionary.m_Tools);
}

//------------------------------------------------------------------------------
// Address: 0x105CBFB0
// Name: _dynamic_atexit_destructor_for__g_WindowPositionMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_WindowPositionMgr__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_WindowPositionMgr.m_Panels);
}

//------------------------------------------------------------------------------
// Address: 0x105CBFC0
// Name: _dynamic_atexit_destructor_for__g_OverridenColorSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OverridenColorSymbols__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_OverridenColorSymbols);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004971D0
// Name: public: static char const __near * CAttributeBasePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeBasePickerPanel::GetPanelClassName()
{
  return "CAttributeBasePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00497220
// Name: public: virtual void CAttributeBasePickerPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeBasePickerPanel::PerformLayout(CAttributeBasePickerPanel *this)
{
  vgui::IImage *v2; // eax
  vgui::Button *m_pOpen; // ecx
  int viewWidth; // [esp+4h] [ebp-8h] BYREF
  int viewHeight; // [esp+8h] [ebp-4h] BYREF

  CBaseAttributePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &viewWidth, tall: &viewHeight);
  v2 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "tools/ifm/icon_properties_linkarrow", a3: 0);
  m_pOpen = this->m_pOpen;
  if ( v2 != nullptr )
  {
    m_pOpen->SetImage(this: m_pOpen, a2: v2, a3: 0);
    this->m_pOpen->SetPaintBorderEnabled(this: this->m_pOpen, a2: false);
    this->m_pOpen->SetContentAlignment(this: this->m_pOpen, a2: a_center);
    vgui::Panel::SetBounds(this: this->m_pOpen, x: 6, y: (int)((double)(viewHeight - 16) * 0.5), wide: 16, tall: 16);
  }
  else
  {
    vgui::Panel::SetBounds(this: m_pOpen, x: 0, y: 0, wide: 50, tall: 20);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004972D0
// Name: public: CAttributeBasePickerPanel::CAttributeBasePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeBasePickerPanel *__thiscall CAttributeBasePickerPanel::CAttributeBasePickerPanel(
        CAttributeBasePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Button *v7; // eax

  CAttributeTextPanel::CAttributeTextPanel(this, parent, info);
  this->__vftable = (CAttributeBasePickerPanel_vtbl *)&CAttributeBasePickerPanel::`vftable';
  if ( `CAttributeBasePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBasePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
    v4->pfnClassName = CAttributeBasePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeBasePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeBasePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
    v5->pfnClassName = CAttributeBasePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeTextPanel");
  }
  if ( `CAttributeBasePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeBasePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
    v6->pfnClassName = CAttributeBasePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeTextPanel");
  }
  v7 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v7 != nullptr )
    this->m_pOpen = vgui::Button::Button(
                      this: v7,
                      parent: this,
                      panelName: "Open",
                      text: "...",
                      pActionSignalTarget: this,
                      pCmd: "open");
  else
    this->m_pOpen = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004973D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeBasePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeBasePickerPanel::GetMessageMap(CAttributeBasePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeBasePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBasePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeBasePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  `CAttributeBasePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00497400
// Name: public: virtual struct PanelAnimationMap __near * CAttributeBasePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeBasePickerPanel::GetAnimMap(CAttributeBasePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00497410
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeBasePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeBasePickerPanel::GetKBMap(CAttributeBasePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeBasePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeBasePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeBasePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  `CAttributeBasePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

} // namespace sceneviewer
