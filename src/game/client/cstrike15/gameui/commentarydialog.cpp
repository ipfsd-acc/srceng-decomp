// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/commentarydialog.cpp
// Functions: 40
// ============================================================

#include "game\client\cstrike15\gameui\commentarydialog.h"

//------------------------------------------------------------------------------
// Address: 0x101EF480
// Name: public: static char const __near * CCommentaryDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCommentaryDialog::GetPanelClassName()
{
  return "CCommentaryDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101EF490
// Name: public: static char const __near * CPostCommentaryDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPostCommentaryDialog::GetPanelClassName()
{
  return "CPostCommentaryDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101EF4A0
// Name: public: virtual void CCommentaryDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryDialog::OnCommand(CCommentaryDialog *this, const char *command)
{
  ConVarRef commentary; // [esp+8h] [ebp-8h] BYREF

  if ( _V_stricmp(s1: command, s2: "TurnOn") == 0 )
  {
    ConVarRef::ConVarRef(this: &commentary, pName: "commentary");
    commentary.m_pConVar->SetValue_2(this: commentary.m_pConVar, a2: 1);
LABEL_5:
    this->Close(this);
    return;
  }
  if ( _V_stricmp(s1: command, s2: "TurnOff") == 0 )
  {
    ConVarRef::ConVarRef(this: &commentary, pName: "commentary");
    commentary.m_pConVar->SetValue_2(this: commentary.m_pConVar, a2: 0);
    goto LABEL_5;
  }
  vgui::Frame::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x101EF520
// Name: public: virtual void CCommentaryDialog::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryDialog::OnKeyCodePressed(CCommentaryDialog *this, ButtonCode_t code)
{
  if ( code != KEY_ESCAPE )
    vgui::Panel::OnKeyCodePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x101EF540
// Name: public: virtual void CPostCommentaryDialog::OnFinishedClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostCommentaryDialog::OnFinishedClose(CPostCommentaryDialog *this)
{
  CGameUI *v2; // eax

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  if ( !this->m_bResetPaintRestrict )
  {
    this->m_bResetPaintRestrict = true;
    g_pVGuiSurface->RestrictPaintToSinglePanel(this: g_pVGuiSurface, a2: 0, a3: false);
    v2 = GameUI();
    CGameUI::HideGameUI(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF580
// Name: public: virtual void CPostCommentaryDialog::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPostCommentaryDialog::OnKeyCodePressed(CPostCommentaryDialog *this, ButtonCode_t code)
{
  if ( code == KEY_ESCAPE )
  {
    this->Close(this);
    g_pVGuiSurface->RestrictPaintToSinglePanel(this: g_pVGuiSurface, a2: 0, a3: false);
    this->m_bResetPaintRestrict = true;
  }
  else
  {
    vgui::Panel::OnKeyCodePressed(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF5D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CCommentaryDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCommentaryDialog::GetMessageMap(CCommentaryDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCommentaryDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCommentaryDialog::GetMessageMap'::`2'::s_pMap;
  `CCommentaryDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCommentaryDialog");
  `CCommentaryDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EF600
// Name: public: virtual struct PanelAnimationMap __near * CCommentaryDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCommentaryDialog::GetAnimMap(CCommentaryDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CCommentaryDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101EF610
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCommentaryDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCommentaryDialog::GetKBMap(CCommentaryDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCommentaryDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCommentaryDialog::GetKBMap'::`2'::s_pMap;
  `CCommentaryDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCommentaryDialog");
  `CCommentaryDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EF640
// Name: public: virtual struct vgui::PanelMessageMap __near * CPostCommentaryDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPostCommentaryDialog::GetMessageMap(CPostCommentaryDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPostCommentaryDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPostCommentaryDialog::GetMessageMap'::`2'::s_pMap;
  `CPostCommentaryDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPostCommentaryDialog");
  `CPostCommentaryDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EF670
// Name: public: virtual struct PanelAnimationMap __near * CPostCommentaryDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPostCommentaryDialog::GetAnimMap(CPostCommentaryDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CPostCommentaryDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101EF680
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPostCommentaryDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPostCommentaryDialog::GetKBMap(CPostCommentaryDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPostCommentaryDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPostCommentaryDialog::GetKBMap'::`2'::s_pMap;
  `CPostCommentaryDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPostCommentaryDialog");
  `CPostCommentaryDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EF6B0
// Name: public: CCommentaryDialog::CCommentaryDialog(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CCommentaryDialog *__thiscall CCommentaryDialog::CCommentaryDialog(CCommentaryDialog *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  CGameUI *v6; // eax
  ConVarRef commentary; // [esp+8h] [ebp-8h] BYREF

  vgui::Frame::Frame(this, parent, panelName: "CommentaryDialog", showTaskbarIcon: 1, bPopup: true);
  this->__vftable = (CCommentaryDialog_vtbl *)&CCommentaryDialog::`vftable';
  if ( `CCommentaryDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CCommentaryDialog::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CCommentaryDialog");
    v3->pfnClassName = CCommentaryDialog::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CCommentaryDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCommentaryDialog::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CCommentaryDialog");
    v4->pfnClassName = CCommentaryDialog::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CCommentaryDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCommentaryDialog::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CCommentaryDialog");
    v5->pfnClassName = CCommentaryDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetSizeable(this, state: false);
  g_pVGuiInput->SetAppModalSurface(this: g_pVGuiInput, a2: this->_vpanel);
  g_pVGuiSurface->RestrictPaintToSinglePanel(this: g_pVGuiSurface, a2: this->_vpanel, a3: false);
  v6 = GameUI();
  CGameUI::PreventEngineHideGameUI(this: v6);
  vgui::Frame::SetTitle(this, title: "#GameUI_CommentaryDialogTitle", surfaceTitle: true);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource/CommentaryDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Frame::MoveToCenterOfScreen(this);
  ConVarRef::ConVarRef(this: &commentary, pName: "commentary");
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&commentary) && commentary.m_pConVarState->m_Value.m_nValue != 0 )
  {
    vgui::EditablePanel::SetControlString(this, controlName: "ModeLabel", string: "#GAMEUI_Commentary_LabelOn");
    vgui::EditablePanel::SetControlString(this, controlName: "TurnOnButton", string: "#GAMEUI_Commentary_LeaveOn");
    vgui::EditablePanel::SetControlString(this, controlName: "TurnOffButton", string: "#GAMEUI_Commentary_TurnOff");
  }
  else
  {
    vgui::EditablePanel::SetControlString(this, controlName: "ModeLabel", string: "#GAMEUI_Commentary_LabelOff");
    vgui::EditablePanel::SetControlString(this, controlName: "TurnOnButton", string: "#GAMEUI_Commentary_TurnOn");
    vgui::EditablePanel::SetControlString(this, controlName: "TurnOffButton", string: "#GAMEUI_Commentary_LeaveOff");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101EF8A0
// Name: void OpenCommentaryDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OpenCommentaryDialog()
{
  CCommentaryDialog *v0; // esi
  CCStrike15BasePanel *v1; // eax
  CCommentaryDialog *v2; // eax
  CGameUI *v3; // eax
  vgui::Panel *v4; // eax
  vgui::DHANDLE<CCommentaryDialog> hCommentaryDialog; // [esp+0h] [ebp-4h] BYREF

  hCommentaryDialog.m_iPanelID = -1;
  if ( vgui::PHandle::Get(this: &hCommentaryDialog) == nullptr )
  {
    v0 = (CCommentaryDialog *)MemAlloc_Alloc(nSize: 0x214u);
    if ( v0 != nullptr )
    {
      v1 = BasePanel();
      v2 = CCommentaryDialog::CCommentaryDialog(this: v0, parent: v1);
    }
    else
    {
      v2 = nullptr;
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &hCommentaryDialog, pPanel: v2);
  }
  v3 = GameUI();
  CGameUI::ActivateGameUI(this: v3);
  v4 = vgui::PHandle::Get(this: &hCommentaryDialog);
  v4->__vftable[1].OnTick(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101EF910
// Name: void CC_CommentaryTestFirstRun(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_CommentaryTestFirstRun()
{
  if ( commentary_firstrun.m_pParent == nullptr || commentary_firstrun.m_pParent->m_Value.m_nValue == 0 )
  {
    ConVar::SetValue(this: (ConVar *)&commentary_firstrun.IConVar, value: 1);
    OpenCommentaryDialog();
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF940
// Name: public: CPostCommentaryDialog::CPostCommentaryDialog(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CPostCommentaryDialog *__thiscall CPostCommentaryDialog::CPostCommentaryDialog(
        CPostCommentaryDialog *this,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  ConVarRef commentary; // [esp+8h] [ebp-8h] BYREF

  vgui::Frame::Frame(this, parent, panelName: "PostCommentaryDialog", showTaskbarIcon: 1, bPopup: true);
  this->__vftable = (CPostCommentaryDialog_vtbl *)&CPostCommentaryDialog::`vftable';
  if ( `CPostCommentaryDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CPostCommentaryDialog::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CPostCommentaryDialog");
    v3->pfnClassName = CPostCommentaryDialog::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CPostCommentaryDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPostCommentaryDialog::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CPostCommentaryDialog");
    v4->pfnClassName = CPostCommentaryDialog::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CPostCommentaryDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPostCommentaryDialog::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CPostCommentaryDialog");
    v5->pfnClassName = CPostCommentaryDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetSizeable(this, state: false);
  g_pVGuiInput->SetAppModalSurface(this: g_pVGuiInput, a2: this->_vpanel);
  g_pVGuiSurface->RestrictPaintToSinglePanel(this: g_pVGuiSurface, a2: this->_vpanel, a3: false);
  this->m_bResetPaintRestrict = false;
  vgui::Frame::SetTitle(this, title: "#GameUI_CommentaryDialogTitle", surfaceTitle: true);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource/PostCommentaryDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Frame::MoveToCenterOfScreen(this);
  ConVarRef::ConVarRef(this: &commentary, pName: "commentary");
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&commentary) && commentary.m_pConVarState->m_Value.m_nValue != 0 )
    vgui::EditablePanel::SetControlString(
      this,
      controlName: "PostModeLabel",
      string: "#GAMEUI_PostCommentary_ModeLabelOn");
  else
    vgui::EditablePanel::SetControlString(
      this,
      controlName: "PostModeLabel",
      string: "#GAMEUI_PostCommentary_ModeLabelOff");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101EFAE0
// Name: public: virtual void CCommentaryDialog::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CCommentaryDialog::OnClose(CCommentaryDialog *this)
{
  CGameUI *v1; // eax
  CPostCommentaryDialog *v2; // esi
  CCStrike15BasePanel *v3; // eax
  CPostCommentaryDialog *v4; // eax
  vgui::Panel *v5; // eax
  vgui::DHANDLE<CPostCommentaryDialog> hPostCommentaryDialog; // [esp+0h] [ebp-4h] BYREF

  hPostCommentaryDialog.m_iPanelID = (unsigned int)this;
  vgui::Frame::OnClose(this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD, _DWORD, unsigned int))g_pVGuiSurface->RestrictPaintToSinglePanel)(
    a1: g_pVGuiSurface,
    a2: 0,
    a3: 0,
    a4: hPostCommentaryDialog.m_iPanelID);
  v1 = GameUI();
  CGameUI::AllowEngineHideGameUI(this: v1);
  hPostCommentaryDialog.m_iPanelID = -1;
  if ( vgui::PHandle::Get(this: &hPostCommentaryDialog) == nullptr )
  {
    v2 = (CPostCommentaryDialog *)MemAlloc_Alloc(nSize: 0x214u);
    if ( v2 != nullptr )
    {
      v3 = BasePanel();
      v4 = CPostCommentaryDialog::CPostCommentaryDialog(this: v2, parent: v3);
    }
    else
    {
      v4 = nullptr;
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &hPostCommentaryDialog, pPanel: v4);
  }
  v5 = vgui::PHandle::Get(this: &hPostCommentaryDialog);
  v5->__vftable[1].OnTick(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10415160
// Name: _dynamic_initializer_for__commentary_showmodelviewer__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__commentary_showmodelviewer__()
{
  ConCommand::ConCommand(
    this: &commentary_showmodelviewer,
    pName: "commentary_showmodelviewer",
    callback: (void (__cdecl *)())CommentaryShowModelViewer,
    pHelpString: "Display the commentary model viewer. Usage: commentary_showmodelviewer <model name> <optional attached model name>",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__commentary_showmodelviewer__);
}

//------------------------------------------------------------------------------
// Address: 0x10423F40
// Name: _dynamic_initializer_for__commentary_firstrun__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__commentary_firstrun__()
{
  ConVar::ConVar(this: &commentary_firstrun, pName: "commentary_firstrun", pDefaultValue: "0", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__commentary_firstrun__);
}

//------------------------------------------------------------------------------
// Address: 0x10423F70
// Name: _dynamic_initializer_for__commentary_testfirstrun__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__commentary_testfirstrun__()
{
  ConCommand::ConCommand(
    this: &commentary_testfirstrun,
    pName: "commentary_testfirstrun",
    callback: CC_CommentaryTestFirstRun,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__commentary_testfirstrun__);
}

//------------------------------------------------------------------------------
// Address: 0x10423FA0
// Name: _dynamic_initializer_for__commentary_testfirstrun___0
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__commentary_testfirstrun___0()
{
  ConCommand::ConCommand(
    this: &commentary_testfirstrun_0,
    pName: "loadcommentary",
    callback: CC_LoadCommentary_Test,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__commentary_testfirstrun___0);
}

//------------------------------------------------------------------------------
// Address: 0x104313B0
// Name: _dynamic_atexit_destructor_for__commentary_showmodelviewer__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__commentary_showmodelviewer__()
{
  ConCommand::~ConCommand(this: &commentary_showmodelviewer);
}

//------------------------------------------------------------------------------
// Address: 0x10435AB0
// Name: _dynamic_atexit_destructor_for__commentary_firstrun__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__commentary_firstrun__()
{
  ConVar::~ConVar(this: &commentary_firstrun);
}

//------------------------------------------------------------------------------
// Address: 0x10435AC0
// Name: _dynamic_atexit_destructor_for__commentary_testfirstrun__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__commentary_testfirstrun__()
{
  ConCommand::~ConCommand(this: &commentary_testfirstrun);
}

//------------------------------------------------------------------------------
// Address: 0x10435AD0
// Name: _dynamic_atexit_destructor_for__commentary_testfirstrun___0
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__commentary_testfirstrun___0()
{
  ConCommand::~ConCommand(this: &commentary_testfirstrun_0);
}

//------------------------------------------------------------------------------
// Address: 0x104313C0
// Name: _DataMapInit_CompiledCaptionHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CompiledCaptionHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_10);
}

//------------------------------------------------------------------------------
// Address: 0x104313D0
// Name: _DataMapInit_CaptionLookup_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CaptionLookup_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_11);
}

//------------------------------------------------------------------------------
// Address: 0x104313E0
// Name: _dynamic_atexit_destructor_for__g_DecalSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DecalSystem__()
{
  CUtlDict<int,int>::RemoveAll(this: &g_DecalSystem.m_GameMaterialTranslation);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &g_DecalSystem.m_GameMaterialTranslation.m_Elements.m_Tree);
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_DecalSystem.m_DecalFileNames);
  CUtlDict<CDecalEmitterSystem::DecalEntry,int>::RemoveAll(this: &g_DecalSystem.m_Decals);
  CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int,CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDecalEmitterSystem::DecalEntry,int>::Node_t,int>,int>>(this: &g_DecalSystem.m_Decals.m_Elements.m_Tree);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_DecalSystem.m_AllDecals);
  IGameSystem::~IGameSystem(this: &g_DecalSystem.CAutoGameSystem);
}

//------------------------------------------------------------------------------
// Address: 0x10431430
// Name: _dynamic_atexit_destructor_for__cl_detail_max_sway__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_detail_max_sway__()
{
  ConVar::~ConVar(this: &cl_detail_max_sway);
}

//------------------------------------------------------------------------------
// Address: 0x10431440
// Name: _dynamic_atexit_destructor_for__cl_detail_avoid_radius__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_detail_avoid_radius__()
{
  ConVar::~ConVar(this: &cl_detail_avoid_radius);
}

//------------------------------------------------------------------------------
// Address: 0x10431450
// Name: _dynamic_atexit_destructor_for__cl_detail_avoid_force__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_detail_avoid_force__()
{
  ConVar::~ConVar(this: &cl_detail_avoid_force);
}

//------------------------------------------------------------------------------
// Address: 0x10431460
// Name: _dynamic_atexit_destructor_for__cl_detail_avoid_recover_speed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_detail_avoid_recover_speed__()
{
  ConVar::~ConVar(this: &cl_detail_avoid_recover_speed);
}

//------------------------------------------------------------------------------
// Address: 0x10431470
// Name: _dynamic_atexit_destructor_for__r_FlashlightDetailProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_FlashlightDetailProps__()
{
  ConVar::~ConVar(this: &r_FlashlightDetailProps);
}

//------------------------------------------------------------------------------
// Address: 0x10431480
// Name: _dynamic_atexit_destructor_for__r_ThreadedDetailProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_ThreadedDetailProps__()
{
  ConVar::~ConVar(this: &r_ThreadedDetailProps);
}

//------------------------------------------------------------------------------
// Address: 0x10431490
// Name: _dynamic_atexit_destructor_for__mat_fullbright___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_fullbright___0()
{
  ConVar::~ConVar(this: &mat_fullbright_0);
}

//------------------------------------------------------------------------------
// Address: 0x104314A0
// Name: _dynamic_atexit_destructor_for__cl_detaildist__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_detaildist__()
{
  ConVar::~ConVar(this: &cl_detaildist);
}

//------------------------------------------------------------------------------
// Address: 0x104314B0
// Name: _dynamic_atexit_destructor_for__cl_detailfade__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_detailfade__()
{
  ConVar::~ConVar(this: &cl_detailfade);
}

//------------------------------------------------------------------------------
// Address: 0x104314C0
// Name: _dynamic_atexit_destructor_for__cl_detail_multiplier__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_detail_multiplier__()
{
  ConVar::~ConVar(this: &cl_detail_multiplier);
}

//------------------------------------------------------------------------------
// Address: 0x104314D0
// Name: _dynamic_atexit_destructor_for__cl_fastdetailsprites__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_fastdetailsprites__()
{
  ConVar::~ConVar(this: &cl_fastdetailsprites);
}

//------------------------------------------------------------------------------
// Address: 0x104314E0
// Name: _dynamic_atexit_destructor_for__s_DetailObjectSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DetailObjectSystem__()
{
  CDetailObjectSystem::~CDetailObjectSystem(this: &s_DetailObjectSystem);
}
