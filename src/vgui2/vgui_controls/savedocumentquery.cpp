// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/savedocumentquery.cpp
// Functions: 59
// ============================================================

#include "vgui2\vgui_controls\savedocumentquery.h"

//------------------------------------------------------------------------------
// Address: 0x102DDAD0
// Name: public: static char const __near * CSaveDocumentQuery::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSaveDocumentQuery::GetPanelClassName()
{
  return "CSaveDocumentQuery";
}

//------------------------------------------------------------------------------
// Address: 0x102DDAE0
// Name: private: void CSaveDocumentQuery::PostCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::PostCommand(CSaveDocumentQuery *this, const char *pCommand)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  vgui::IVGui *v5; // esi
  vgui::IVGui_vtbl *v6; // edi
  int v7; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: pCommand);
  else
    v4 = nullptr;
  v5 = g_pVGui;
  v6 = g_pVGui->__vftable;
  v7 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->m_pActionSignalTarget->GetVPanel)(
         a1: this->m_pActionSignalTarget,
         a2: v4,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v6->PostMessage)(a1: v5, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x102DDB40
// Name: public: virtual void CSaveDocumentQuery::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::OnCommand(CSaveDocumentQuery *this, const char *cmd)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  KeyValues *v5; // ecx
  KeyValues *v6; // eax
  vgui::IVGui *v7; // ebx
  int v8; // eax
  KeyValues *m_pPostSaveKeyValues; // ecx
  vgui::IVGui *v10; // edi
  vgui::Panel *m_pActionSignalTarget; // ebx
  KeyValues *Copy; // eax
  int v13; // eax
  vgui::IVGui_vtbl *v14; // [esp+18h] [ebp+8h]
  vgui::IVGui_vtbl *v15; // [esp+18h] [ebp+8h]

  if ( _V_stricmp(s1: cmd, s2: "yes") != 0 )
  {
    if ( _V_stricmp(s1: cmd, s2: "no") != 0 )
    {
      if ( _V_stricmp(s1: cmd, s2: "cancel") != 0 )
      {
        vgui::Frame::OnCommand(this, command: cmd);
      }
      else
      {
        CSaveDocumentQuery::PostCommand(this, pCommand: "OnCancelSaveDocument");
        this->MarkForDeletion(this);
      }
    }
    else
    {
      CSaveDocumentQuery::PostCommand(this, pCommand: "OnMarkNotDirty");
      m_pPostSaveKeyValues = this->m_pPostSaveKeyValues;
      if ( m_pPostSaveKeyValues != nullptr )
      {
        v10 = g_pVGui;
        m_pActionSignalTarget = this->m_pActionSignalTarget;
        v15 = g_pVGui->__vftable;
        Copy = KeyValues::MakeCopy(this: m_pPostSaveKeyValues);
        v13 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))m_pActionSignalTarget->GetVPanel)(
                a1: m_pActionSignalTarget,
                a2: Copy,
                a3: 0,
                a4: 0);
        ((void (__thiscall *)(vgui::IVGui *, int))v15->PostMessage)(a1: v10, a2: v13);
      }
      this->MarkForDeletion(this);
    }
  }
  else
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "OnSaveFile");
    else
      v4 = nullptr;
    KeyValues::SetString(this: v4, keyName: "filename", value: this->m_szFileName);
    KeyValues::SetString(this: v4, keyName: "filetype", value: this->m_szFileType);
    KeyValues::SetInt(this: v4, keyName: "context", value: this->m_nContext);
    KeyValues::SetPtr(this: v4, keyName: "actionTarget", value: this->m_pActionSignalTarget);
    v5 = this->m_pPostSaveKeyValues;
    if ( v5 != nullptr )
    {
      v6 = KeyValues::MakeCopy(this: v5);
      KeyValues::AddSubKey(this: v4, pSubkey: v6);
    }
    v7 = g_pVGui;
    v14 = g_pVGui->__vftable;
    v8 = ((int (__stdcall *)(KeyValues *, _DWORD, _DWORD))this->m_pActionSignalTarget->GetVPanel)(a1: v4, a2: 0, a3: 0);
    ((void (__thiscall *)(vgui::IVGui *, int))v14->PostMessage)(a1: v7, a2: v8);
    this->MarkForDeletion(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DDCE0
// Name: public: virtual void CSaveDocumentQuery::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::ApplySchemeSettings(CSaveDocumentQuery *this, vgui::IScheme *pScheme)
{
  int wide; // [esp+4h] [ebp-Ch] BYREF
  int swide; // [esp+8h] [ebp-8h] BYREF
  int tall; // [esp+Ch] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: (int *)&pScheme);
  vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: ((int)pScheme - tall) / 2);
}

//------------------------------------------------------------------------------
// Address: 0x102DDD40
// Name: public: virtual void CSaveDocumentQuery::DoModal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::DoModal(CSaveDocumentQuery *this)
{
  this->SetVisible(this, a2: true);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  this->RequestFocus(this, a2: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102DDD90
// Name: public: virtual struct vgui::PanelMessageMap __near * CSaveDocumentQuery::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSaveDocumentQuery::GetMessageMap(CSaveDocumentQuery *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSaveDocumentQuery::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveDocumentQuery::GetMessageMap'::`2'::s_pMap;
  `CSaveDocumentQuery::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSaveDocumentQuery");
  `CSaveDocumentQuery::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DDDC0
// Name: public: virtual struct PanelAnimationMap __near * CSaveDocumentQuery::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSaveDocumentQuery::GetAnimMap(CSaveDocumentQuery *this)
{
  return FindOrAddPanelAnimationMap(className: "CSaveDocumentQuery");
}

//------------------------------------------------------------------------------
// Address: 0x102DDDD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSaveDocumentQuery::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSaveDocumentQuery::GetKBMap(CSaveDocumentQuery *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSaveDocumentQuery::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveDocumentQuery::GetKBMap'::`2'::s_pMap;
  `CSaveDocumentQuery::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSaveDocumentQuery");
  `CSaveDocumentQuery::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DDE00
// Name: public: CSaveDocumentQuery::CSaveDocumentQuery(class vgui::Panel __near *,char const __near *,char const __near *,int,class vgui::Panel __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CSaveDocumentQuery *__thiscall CSaveDocumentQuery::CSaveDocumentQuery(
        CSaveDocumentQuery *this,
        vgui::Panel *pParent,
        const char *pFileName,
        const char *pFileType,
        int nContext,
        vgui::Panel *pActionSignalTarget,
        KeyValues *pPostSaveCommand)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  const char *v11; // eax
  vgui::Label *v12; // eax
  vgui::Label *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  vgui::Button *v19; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "SaveDocumentQuery", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CSaveDocumentQuery_vtbl *)&CSaveDocumentQuery::`vftable';
  if ( `CSaveDocumentQuery::ChainToMap'::`2'::chained == 0 )
  {
    `CSaveDocumentQuery::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "CSaveDocumentQuery");
    v8->pfnClassName = CSaveDocumentQuery::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CSaveDocumentQuery::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSaveDocumentQuery::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "CSaveDocumentQuery");
    v9->pfnClassName = CSaveDocumentQuery::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CSaveDocumentQuery::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSaveDocumentQuery::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "CSaveDocumentQuery");
    v10->pfnClassName = CSaveDocumentQuery::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  v11 = pFileName;
  this->m_pActionSignalTarget = pActionSignalTarget;
  this->m_nContext = nContext;
  if ( pFileName == nullptr || *pFileName == 0 )
    v11 = "<untitled>";
  V_strncpy(pDest: this->m_szFileName, pSrc: v11, maxLen: 256);
  V_strncpy(pDest: this->m_szFileType, pSrc: pFileType, maxLen: 256);
  this->m_pPostSaveKeyValues = pPostSaveCommand;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  vgui::Frame::SetMinimizeButtonVisible(this, state: false);
  vgui::Frame::SetCloseButtonVisible(this, state: false);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetTitle(this, title: "Save Changes", surfaceTitle: true);
  v12 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v12 != nullptr )
    v13 = vgui::Label::Label(this: v12, parent: this, panelName: "FileNameLabel", text: defaultValue);
  else
    v13 = nullptr;
  this->m_pMessageLabel = v13;
  v14 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "Yes",
            text: "Yes",
            pActionSignalTarget: this,
            pCmd: "yes");
  else
    v15 = nullptr;
  this->m_pYesButton = v15;
  v16 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v16 != nullptr )
    v17 = vgui::Button::Button(
            this: v16,
            parent: this,
            panelName: "No",
            text: "No",
            pActionSignalTarget: this,
            pCmd: "no");
  else
    v17 = nullptr;
  this->m_pNoButton = v17;
  v18 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v18 != nullptr )
    v19 = vgui::Button::Button(
            this: v18,
            parent: this,
            panelName: "Cancel",
            text: "Cancel",
            pActionSignalTarget: this,
            pCmd: "cancel");
  else
    v19 = nullptr;
  this->m_pCancelButton = v19;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/ToolSaveDocumentQuery.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  this->m_pMessageLabel->SetText(this: this->m_pMessageLabel, a2: this->m_szFileName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102DE090
// Name: void ShowSaveDocumentQuery(class vgui::Panel __near *,char const __near *,char const __near *,int,class vgui::Panel __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSaveDocumentQuery(
        vgui::Panel *pParent,
        const char *pFileName,
        const char *pFileType,
        int nContext,
        vgui::Panel *pActionSignalTarget,
        KeyValues *pPostSaveCommand)
{
  CSaveDocumentQuery *v6; // eax
  CSaveDocumentQuery *v7; // esi

  v6 = (CSaveDocumentQuery *)MemAlloc_Alloc(nSize: 0x430u);
  if ( v6 != nullptr )
    v7 = CSaveDocumentQuery::CSaveDocumentQuery(
           this: v6,
           pParent,
           pFileName,
           pFileType,
           nContext,
           pActionSignalTarget,
           pPostSaveCommand);
  else
    v7 = nullptr;
  v7->SetSmallCaption(this: v7, a2: true);
  v7->DoModal(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1031B8E0
// Name: _dynamic_initializer_for__save_history_count__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_history_count__()
{
  ConVar::ConVar(
    this: &save_history_count,
    pName: "save_history_count",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Keep this many old copies in history of autosaves and quicksaves.");
  return atexit(func: dynamic_atexit_destructor_for__save_history_count__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B940
// Name: _dynamic_initializer_for__save_async__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_async__()
{
  ConVar::ConVar(this: &save_async, pName: "save_async", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__save_async__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B970
// Name: _dynamic_initializer_for__save_disable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_disable__()
{
  ConVar::ConVar(this: &save_disable, pName: "save_disable", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__save_disable__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B9D0
// Name: _dynamic_initializer_for__save_noxsave__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_noxsave__()
{
  ConVar::ConVar(this: &save_noxsave, pName: "save_noxsave", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__save_noxsave__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BA00
// Name: _dynamic_initializer_for__save_screenshot__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_screenshot__()
{
  ConVar::ConVar(
    this: &save_screenshot,
    pName: "save_screenshot",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "0 = none, 1 = non-autosave, 2 = always");
  return atexit(func: dynamic_atexit_destructor_for__save_screenshot__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BA30
// Name: _dynamic_initializer_for__save_spew__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_spew__()
{
  ConVar::ConVar(this: &save_spew, pName: "save_spew", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__save_spew__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BA60
// Name: _dynamic_initializer_for__save_multiplayer_override__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_multiplayer_override__()
{
  ConVar::ConVar(this: &save_multiplayer_override, pName: "save_multiplayer_override", pDefaultValue: "0", flags: 18);
  return atexit(func: dynamic_atexit_destructor_for__save_multiplayer_override__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BA90
// Name: _dynamic_initializer_for__save_console__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_console__()
{
  ConVar::ConVar(
    this: &save_console,
    pName: "save_console",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Autosave on the PC behaves like it does on the consoles.");
  return atexit(func: dynamic_atexit_destructor_for__save_console__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BAC0
// Name: _dynamic_initializer_for__save_huddelayframes__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_huddelayframes__()
{
  ConVar::ConVar(
    this: &save_huddelayframes,
    pName: "save_huddelayframes",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Number of frames to defer for drawing the Saving message.");
  return atexit(func: dynamic_atexit_destructor_for__save_huddelayframes__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BB90
// Name: _dynamic_initializer_for__save_asyncdelay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_asyncdelay__()
{
  ConVar::ConVar(
    this: &save_asyncdelay,
    pName: "save_asyncdelay",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "For testing, adds this many milliseconds of delay to the save operation.");
  return atexit(func: dynamic_atexit_destructor_for__save_asyncdelay__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BBF0
// Name: _dynamic_initializer_for__save_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_command__()
{
  ConCommand::ConCommand(
    this: &save_command,
    pName: "save",
    callback: (void (__cdecl *)())xsave,
    pHelpString: "Saves current game.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__save_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BDD0
// Name: _dynamic_initializer_for__save_finish_async_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_finish_async_command__()
{
  ConCommand::ConCommand(
    this: &save_finish_async_command,
    pName: "save_finish_async",
    callback: (void (__cdecl *)())CSaveRestore::FinishAsyncSave,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__save_finish_async_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D420
// Name: _dynamic_initializer_for__save_in_memory__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__save_in_memory__()
{
  ConVar::ConVar(
    this: &save_in_memory,
    pName: "save_in_memory",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Set to 1 to save to memory instead of disk (Xbox 360)",
    callback: (void (__cdecl *)(IConVar *, const char *, float))SaveInMemoryCallback);
  return atexit(func: dynamic_atexit_destructor_for__save_in_memory__);
}

//------------------------------------------------------------------------------
// Address: 0x10325B20
// Name: _dynamic_atexit_destructor_for__save_history_count__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_history_count__()
{
  ConVar::~ConVar(this: &save_history_count);
}

//------------------------------------------------------------------------------
// Address: 0x10325B40
// Name: _dynamic_atexit_destructor_for__save_async__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_async__()
{
  ConVar::~ConVar(this: &save_async);
}

//------------------------------------------------------------------------------
// Address: 0x10325B50
// Name: _dynamic_atexit_destructor_for__save_disable__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_disable__()
{
  ConVar::~ConVar(this: &save_disable);
}

//------------------------------------------------------------------------------
// Address: 0x10325B70
// Name: _dynamic_atexit_destructor_for__save_noxsave__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_noxsave__()
{
  ConVar::~ConVar(this: &save_noxsave);
}

//------------------------------------------------------------------------------
// Address: 0x10325B80
// Name: _dynamic_atexit_destructor_for__save_screenshot__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_screenshot__()
{
  ConVar::~ConVar(this: &save_screenshot);
}

//------------------------------------------------------------------------------
// Address: 0x10325B90
// Name: _dynamic_atexit_destructor_for__save_spew__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_spew__()
{
  ConVar::~ConVar(this: &save_spew);
}

//------------------------------------------------------------------------------
// Address: 0x10325BA0
// Name: _dynamic_atexit_destructor_for__save_multiplayer_override__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_multiplayer_override__()
{
  ConVar::~ConVar(this: &save_multiplayer_override);
}

//------------------------------------------------------------------------------
// Address: 0x10325BB0
// Name: _dynamic_atexit_destructor_for__save_console__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_console__()
{
  ConVar::~ConVar(this: &save_console);
}

//------------------------------------------------------------------------------
// Address: 0x10325BC0
// Name: _dynamic_atexit_destructor_for__save_huddelayframes__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_huddelayframes__()
{
  ConVar::~ConVar(this: &save_huddelayframes);
}

//------------------------------------------------------------------------------
// Address: 0x10325BD0
// Name: _dynamic_atexit_destructor_for__save_asyncdelay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_asyncdelay__()
{
  ConVar::~ConVar(this: &save_asyncdelay);
}

//------------------------------------------------------------------------------
// Address: 0x10325BE0
// Name: _dynamic_atexit_destructor_for__save_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_command__()
{
  ConCommand::~ConCommand(this: &save_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325C80
// Name: _dynamic_atexit_destructor_for__save_finish_async_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_finish_async_command__()
{
  ConCommand::~ConCommand(this: &save_finish_async_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326640
// Name: _dynamic_atexit_destructor_for__save_in_memory__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__save_in_memory__()
{
  ConVar::~ConVar(this: &save_in_memory);
}

//------------------------------------------------------------------------------
// Address: 0x1031B9A0
// Name: _dynamic_initializer_for__map_wants_save_disable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__map_wants_save_disable__()
{
  ConVar::ConVar(this: &map_wants_save_disable, pName: "map_wants_save_disable", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__map_wants_save_disable__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BAF0
// Name: _dynamic_initializer_for__g_AsyncSaveCallQueue__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AsyncSaveCallQueue__()
{
  CTSQueue<int,0,1>::CTSQueue<int,0,1>(this: (CTSQueue<int,0,1> *)&g_AsyncSaveCallQueue);
  g_AsyncSaveCallQueue.m_bNoQueue = false;
  return atexit(func: dynamic_atexit_destructor_for__g_AsyncSaveCallQueue__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BB10
// Name: _dynamic_initializer_for__g_bSaveInProgress__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_bSaveInProgress__()
{
  g_bSaveInProgress.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1031BB20
// Name: _dynamic_initializer_for__g_bAutoSaveDangerousInProgress__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void dynamic_initializer_for__g_bAutoSaveDangerousInProgress__()
{
  g_bAutoSaveDangerousInProgress.m_value = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1031BB30
// Name: _dynamic_initializer_for__g_SaveRestore__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SaveRestore__()
{
  CSaveRestore::CSaveRestore(this: &g_SaveRestore);
  return atexit(func: dynamic_atexit_destructor_for__g_SaveRestore__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BC20
// Name: _dynamic_initializer_for__xsave_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__xsave_command__()
{
  ConCommand::ConCommand(
    this: &xsave_command,
    pName: "xsave",
    callback: (void (__cdecl *)())xsave,
    pHelpString: "Saves current game to a console storage device.",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__xsave_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BC50
// Name: _dynamic_initializer_for__minisave_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__minisave_command__()
{
  ConCommand::ConCommand(
    this: &minisave_command,
    pName: "minisave",
    callback: (void (__cdecl *)())minisave,
    pHelpString: "Saves game (for current level only!)",
    flags: 0x20000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__minisave_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BC80
// Name: _dynamic_initializer_for___autosave_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for___autosave_command__()
{
  ConCommand::ConCommand(
    this: &autosave_command,
    pName: "_autosave",
    callback: (void (__cdecl *)())autosave,
    pHelpString: "Autosave",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for___autosave_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BCB0
// Name: _dynamic_initializer_for___autosavedangerous_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for___autosavedangerous_command__()
{
  ConCommand::ConCommand(
    this: &autosavedangerous_command,
    pName: "_autosavedangerous",
    callback: (void (__cdecl *)())autosavedangerous,
    pHelpString: "AutoSaveDangerous",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for___autosavedangerous_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BCE0
// Name: _dynamic_initializer_for__autosave_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__autosave_command__()
{
  ConCommand::ConCommand(
    this: &autosave_command,
    pName: "autosave",
    callback: (void (__cdecl *)())autosave,
    pHelpString: "Autosave",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__autosave_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BD10
// Name: _dynamic_initializer_for__autosavedangerous_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__autosavedangerous_command__()
{
  ConCommand::ConCommand(
    this: &autosavedangerous_command,
    pName: "autosavedangerous",
    callback: (void (__cdecl *)())autosavedangerous,
    pHelpString: "AutoSaveDangerous",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__autosavedangerous_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BD40
// Name: _dynamic_initializer_for__autosavedangerousissafe_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__autosavedangerousissafe_command__()
{
  ConCommand::ConCommand(
    this: &autosavedangerousissafe_command,
    pName: "autosavedangerousissafe",
    callback: autosavedangerousissafe,
    pHelpString: defaultValue,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__autosavedangerousissafe_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031BE00
// Name: _dynamic_initializer_for__in_forceuser__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__in_forceuser__()
{
  ConVar::ConVar(
    this: &in_forceuser,
    pName: "in_forceuser",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Force user input to this split screen player.");
  return atexit(func: dynamic_atexit_destructor_for__in_forceuser__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D450
// Name: _dynamic_initializer_for__audit_save_in_memory_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__audit_save_in_memory_command__()
{
  ConCommand::ConCommand(
    this: &audit_save_in_memory_command,
    pName: "audit_save_in_memory",
    callback: (void (__cdecl *)())CColorBalanceUIPanel::Init,
    pHelpString: "Audit the memory usage and files in the save-to-memory system",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__audit_save_in_memory_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325B60
// Name: _dynamic_atexit_destructor_for__map_wants_save_disable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__map_wants_save_disable__()
{
  ConVar::~ConVar(this: &map_wants_save_disable);
}

//------------------------------------------------------------------------------
// Address: 0x10325BF0
// Name: _dynamic_atexit_destructor_for__xsave_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__xsave_command__()
{
  ConCommand::~ConCommand(this: &xsave_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325C00
// Name: _dynamic_atexit_destructor_for__minisave_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__minisave_command__()
{
  ConCommand::~ConCommand(this: &minisave_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325C10
// Name: _dynamic_atexit_destructor_for___autosave_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___autosave_command__()
{
  ConCommand::~ConCommand(this: &autosave_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325C20
// Name: _dynamic_atexit_destructor_for___autosavedangerous_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for___autosavedangerous_command__()
{
  ConCommand::~ConCommand(this: &autosavedangerous_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325C30
// Name: _dynamic_atexit_destructor_for__autosave_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__autosave_command__()
{
  ConCommand::~ConCommand(this: &autosave_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325C40
// Name: _dynamic_atexit_destructor_for__autosavedangerous_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__autosavedangerous_command__()
{
  ConCommand::~ConCommand(this: &autosavedangerous_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325C50
// Name: _dynamic_atexit_destructor_for__autosavedangerousissafe_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__autosavedangerousissafe_command__()
{
  ConCommand::~ConCommand(this: &autosavedangerousissafe_command);
}

//------------------------------------------------------------------------------
// Address: 0x10326650
// Name: _dynamic_atexit_destructor_for__audit_save_in_memory_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__audit_save_in_memory_command__()
{
  ConCommand::~ConCommand(this: &audit_save_in_memory_command);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00641080
// Name: public: static char const __near * CSaveDocumentQuery::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSaveDocumentQuery::GetPanelClassName()
{
  return "CSaveDocumentQuery";
}

//------------------------------------------------------------------------------
// Address: 0x00641090
// Name: private: void CSaveDocumentQuery::PostCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::PostCommand(CSaveDocumentQuery *this, const char *pCommand)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  vgui::IVGui *v5; // esi
  vgui::IVGui_vtbl *v6; // edi
  int v7; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: pCommand);
  else
    v4 = nullptr;
  v5 = g_pVGui;
  v6 = g_pVGui->__vftable;
  v7 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->m_pActionSignalTarget->GetVPanel)(
         a1: this->m_pActionSignalTarget,
         a2: v4,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v6->PostMessage)(a1: v5, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x006410F0
// Name: public: virtual void CSaveDocumentQuery::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::OnCommand(CSaveDocumentQuery *this, const char *cmd)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  KeyValues *v5; // ecx
  KeyValues *v6; // eax
  vgui::IVGui *v7; // ebx
  int v8; // eax
  KeyValues *m_pPostSaveKeyValues; // ecx
  vgui::IVGui *v10; // edi
  vgui::Panel *m_pActionSignalTarget; // ebx
  KeyValues *Copy; // eax
  int v13; // eax
  vgui::IVGui_vtbl *cmda; // [esp+18h] [ebp+8h]
  vgui::IVGui_vtbl *cmdb; // [esp+18h] [ebp+8h]

  if ( _V_stricmp(s1: cmd, s2: "yes") != 0 )
  {
    if ( _V_stricmp(s1: cmd, s2: "no") != 0 )
    {
      if ( _V_stricmp(s1: cmd, s2: "cancel") != 0 )
      {
        vgui::Frame::OnCommand(this, command: cmd);
      }
      else
      {
        CSaveDocumentQuery::PostCommand(this, pCommand: "OnCancelSaveDocument");
        this->MarkForDeletion(this);
      }
    }
    else
    {
      CSaveDocumentQuery::PostCommand(this, pCommand: "OnMarkNotDirty");
      m_pPostSaveKeyValues = this->m_pPostSaveKeyValues;
      if ( m_pPostSaveKeyValues != nullptr )
      {
        v10 = g_pVGui;
        m_pActionSignalTarget = this->m_pActionSignalTarget;
        cmdb = g_pVGui->__vftable;
        Copy = KeyValues::MakeCopy(this: m_pPostSaveKeyValues);
        v13 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))m_pActionSignalTarget->GetVPanel)(
                a1: m_pActionSignalTarget,
                a2: Copy,
                a3: 0,
                a4: 0);
        ((void (__thiscall *)(vgui::IVGui *, int))cmdb->PostMessage)(a1: v10, a2: v13);
      }
      this->MarkForDeletion(this);
    }
  }
  else
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "OnSaveFile");
    else
      v4 = nullptr;
    KeyValues::SetString(this: v4, keyName: "filename", value: this->m_szFileName);
    KeyValues::SetString(this: v4, keyName: "filetype", value: this->m_szFileType);
    KeyValues::SetInt(this: v4, keyName: "context", value: this->m_nContext);
    KeyValues::SetPtr(this: v4, keyName: "actionTarget", value: this->m_pActionSignalTarget);
    v5 = this->m_pPostSaveKeyValues;
    if ( v5 != nullptr )
    {
      v6 = KeyValues::MakeCopy(this: v5);
      KeyValues::AddSubKey(this: v4, pSubkey: v6);
    }
    v7 = g_pVGui;
    cmda = g_pVGui->__vftable;
    v8 = ((int (__stdcall *)(KeyValues *, _DWORD, _DWORD))this->m_pActionSignalTarget->GetVPanel)(a1: v4, a2: 0, a3: 0);
    ((void (__thiscall *)(vgui::IVGui *, int))cmda->PostMessage)(a1: v7, a2: v8);
    this->MarkForDeletion(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00641290
// Name: public: virtual void CSaveDocumentQuery::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::ApplySchemeSettings(CSaveDocumentQuery *this, vgui::IScheme *pScheme)
{
  int wide; // [esp+4h] [ebp-Ch] BYREF
  int swide; // [esp+8h] [ebp-8h] BYREF
  int tall; // [esp+Ch] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: (int *)&pScheme);
  vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: ((int)pScheme - tall) / 2);
}

//------------------------------------------------------------------------------
// Address: 0x006412F0
// Name: public: virtual void CSaveDocumentQuery::DoModal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::DoModal(CSaveDocumentQuery *this)
{
  this->SetVisible(this, a2: true);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  this->RequestFocus(this, a2: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00641340
// Name: public: virtual struct vgui::PanelMessageMap __near * CSaveDocumentQuery::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSaveDocumentQuery::GetMessageMap(CSaveDocumentQuery *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSaveDocumentQuery::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveDocumentQuery::GetMessageMap'::`2'::s_pMap;
  `CSaveDocumentQuery::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"CSaveDocumentQuery");
  `CSaveDocumentQuery::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00641370
// Name: public: virtual struct PanelAnimationMap __near * CSaveDocumentQuery::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSaveDocumentQuery::GetAnimMap(CSaveDocumentQuery *this)
{
  return FindOrAddPanelAnimationMap(className: "CSaveDocumentQuery");
}

//------------------------------------------------------------------------------
// Address: 0x00641380
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSaveDocumentQuery::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSaveDocumentQuery::GetKBMap(CSaveDocumentQuery *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSaveDocumentQuery::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveDocumentQuery::GetKBMap'::`2'::s_pMap;
  `CSaveDocumentQuery::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CSaveDocumentQuery");
  `CSaveDocumentQuery::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006413B0
// Name: public: CSaveDocumentQuery::CSaveDocumentQuery(class vgui::Panel __near *,char const __near *,char const __near *,int,class vgui::Panel __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CSaveDocumentQuery *__thiscall CSaveDocumentQuery::CSaveDocumentQuery(
        CSaveDocumentQuery *this,
        vgui::Panel *pParent,
        char *pFileName,
        char *pFileType,
        int nContext,
        vgui::Panel *pActionSignalTarget,
        KeyValues *pPostSaveCommand)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  char *v11; // eax
  vgui::Label *v12; // eax
  vgui::Label *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  vgui::Button *v19; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "SaveDocumentQuery", showTaskbarIcon: 1, bPopup: true);
  this->__vftable = (CSaveDocumentQuery_vtbl *)&CSaveDocumentQuery::`vftable';
  if ( `CSaveDocumentQuery::ChainToMap'::`2'::chained == 0 )
  {
    `CSaveDocumentQuery::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: (void **)"CSaveDocumentQuery");
    v8->pfnClassName = CSaveDocumentQuery::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"vgui::Frame");
  }
  if ( `CSaveDocumentQuery::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSaveDocumentQuery::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "CSaveDocumentQuery");
    v9->pfnClassName = CSaveDocumentQuery::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CSaveDocumentQuery::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSaveDocumentQuery::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CSaveDocumentQuery");
    v10->pfnClassName = CSaveDocumentQuery::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"vgui::Frame");
  }
  v11 = pFileName;
  this->m_pActionSignalTarget = pActionSignalTarget;
  this->m_nContext = nContext;
  if ( pFileName == nullptr || *pFileName == 0 )
    v11 = "<untitled>";
  V_strncpy(pDest: this->m_szFileName, pSrc: v11, maxLen: 256);
  V_strncpy(pDest: this->m_szFileType, pSrc: pFileType, maxLen: 256);
  this->m_pPostSaveKeyValues = pPostSaveCommand;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  vgui::Frame::SetMinimizeButtonVisible(this, state: false);
  vgui::Frame::SetCloseButtonVisible(this, state: false);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetTitle(this, title: "Save Changes", surfaceTitle: true);
  v12 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v12 != nullptr )
    v13 = vgui::Label::Label(this: v12, parent: this, panelName: "FileNameLabel", text: defaultValue);
  else
    v13 = nullptr;
  this->m_pMessageLabel = v13;
  v14 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "Yes",
            text: "Yes",
            pActionSignalTarget: this,
            pCmd: "yes");
  else
    v15 = nullptr;
  this->m_pYesButton = v15;
  v16 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v16 != nullptr )
    v17 = vgui::Button::Button(
            this: v16,
            parent: this,
            panelName: "No",
            text: "No",
            pActionSignalTarget: this,
            pCmd: "no");
  else
    v17 = nullptr;
  this->m_pNoButton = v17;
  v18 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v18 != nullptr )
    v19 = vgui::Button::Button(
            this: v18,
            parent: this,
            panelName: "Cancel",
            text: "Cancel",
            pActionSignalTarget: this,
            pCmd: "cancel");
  else
    v19 = nullptr;
  this->m_pCancelButton = v19;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/ToolSaveDocumentQuery.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  this->m_pMessageLabel->SetText_2(this: this->m_pMessageLabel, a2: this->m_szFileName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00641640
// Name: void ShowSaveDocumentQuery(class vgui::Panel __near *,char const __near *,char const __near *,int,class vgui::Panel __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSaveDocumentQuery(
        vgui::Panel *pParent,
        char *pFileName,
        char *pFileType,
        int nContext,
        vgui::Panel *pActionSignalTarget,
        KeyValues *pPostSaveCommand)
{
  CSaveDocumentQuery *v6; // eax
  CSaveDocumentQuery *v7; // esi

  v6 = (CSaveDocumentQuery *)MemAlloc_Alloc(nSize: 0x430u);
  if ( v6 != nullptr )
    v7 = CSaveDocumentQuery::CSaveDocumentQuery(
           this: v6,
           pParent,
           pFileName,
           pFileType,
           nContext,
           pActionSignalTarget,
           pPostSaveCommand);
  else
    v7 = nullptr;
  v7->SetSmallCaption(this: v7, a2: true);
  v7->DoModal(this: v7);
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102DDB90
// Name: public: static char const __near * CSaveDocumentQuery::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSaveDocumentQuery::GetPanelClassName()
{
  return "CSaveDocumentQuery";
}

//------------------------------------------------------------------------------
// Address: 0x102DDBA0
// Name: private: void CSaveDocumentQuery::PostCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::PostCommand(CSaveDocumentQuery *this, const char *pCommand)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  vgui::IVGui *v5; // esi
  vgui::IVGui_vtbl *v6; // edi
  int v7; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: pCommand);
  else
    v4 = nullptr;
  v5 = g_pVGui;
  v6 = g_pVGui->__vftable;
  v7 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->m_pActionSignalTarget->GetVPanel)(
         a1: this->m_pActionSignalTarget,
         a2: v4,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v6->PostMessage)(a1: v5, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x102DDC00
// Name: public: virtual void CSaveDocumentQuery::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::OnCommand(CSaveDocumentQuery *this, const char *cmd)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  KeyValues *v5; // ecx
  KeyValues *v6; // eax
  vgui::IVGui *v7; // ebx
  int v8; // eax
  KeyValues *m_pPostSaveKeyValues; // ecx
  vgui::IVGui *v10; // edi
  vgui::Panel *m_pActionSignalTarget; // ebx
  KeyValues *Copy; // eax
  int v13; // eax
  vgui::IVGui_vtbl *v14; // [esp+18h] [ebp+8h]
  vgui::IVGui_vtbl *v15; // [esp+18h] [ebp+8h]

  if ( _V_stricmp(s1: cmd, s2: "yes") != 0 )
  {
    if ( _V_stricmp(s1: cmd, s2: "no") != 0 )
    {
      if ( _V_stricmp(s1: cmd, s2: "cancel") != 0 )
      {
        vgui::Frame::OnCommand(this, command: cmd);
      }
      else
      {
        CSaveDocumentQuery::PostCommand(this, pCommand: "OnCancelSaveDocument");
        this->MarkForDeletion(this);
      }
    }
    else
    {
      CSaveDocumentQuery::PostCommand(this, pCommand: "OnMarkNotDirty");
      m_pPostSaveKeyValues = this->m_pPostSaveKeyValues;
      if ( m_pPostSaveKeyValues != nullptr )
      {
        v10 = g_pVGui;
        m_pActionSignalTarget = this->m_pActionSignalTarget;
        v15 = g_pVGui->__vftable;
        Copy = KeyValues::MakeCopy(this: m_pPostSaveKeyValues);
        v13 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))m_pActionSignalTarget->GetVPanel)(
                a1: m_pActionSignalTarget,
                a2: Copy,
                a3: 0,
                a4: 0);
        ((void (__thiscall *)(vgui::IVGui *, int))v15->PostMessage)(a1: v10, a2: v13);
      }
      this->MarkForDeletion(this);
    }
  }
  else
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "OnSaveFile");
    else
      v4 = nullptr;
    KeyValues::SetString(this: v4, keyName: "filename", value: this->m_szFileName);
    KeyValues::SetString(this: v4, keyName: "filetype", value: this->m_szFileType);
    KeyValues::SetInt(this: v4, keyName: "context", value: this->m_nContext);
    KeyValues::SetPtr(this: v4, keyName: "actionTarget", value: this->m_pActionSignalTarget);
    v5 = this->m_pPostSaveKeyValues;
    if ( v5 != nullptr )
    {
      v6 = KeyValues::MakeCopy(this: v5);
      KeyValues::AddSubKey(this: v4, pSubkey: v6);
    }
    v7 = g_pVGui;
    v14 = g_pVGui->__vftable;
    v8 = ((int (__stdcall *)(KeyValues *, _DWORD, _DWORD))this->m_pActionSignalTarget->GetVPanel)(a1: v4, a2: 0, a3: 0);
    ((void (__thiscall *)(vgui::IVGui *, int))v14->PostMessage)(a1: v7, a2: v8);
    this->MarkForDeletion(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DDDA0
// Name: public: virtual void CSaveDocumentQuery::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::ApplySchemeSettings(CSaveDocumentQuery *this, vgui::IScheme *pScheme)
{
  int wide; // [esp+4h] [ebp-Ch] BYREF
  int swide; // [esp+8h] [ebp-8h] BYREF
  int tall; // [esp+Ch] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: (int *)&pScheme);
  vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: ((int)pScheme - tall) / 2);
}

//------------------------------------------------------------------------------
// Address: 0x102DDE50
// Name: public: virtual struct vgui::PanelMessageMap __near * CSaveDocumentQuery::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSaveDocumentQuery::GetMessageMap(CSaveDocumentQuery *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSaveDocumentQuery::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveDocumentQuery::GetMessageMap'::`2'::s_pMap;
  `CSaveDocumentQuery::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: (void **)"CSaveDocumentQuery");
  `CSaveDocumentQuery::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DDE80
// Name: public: virtual struct PanelAnimationMap __near * CSaveDocumentQuery::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSaveDocumentQuery::GetAnimMap(CSaveDocumentQuery *this)
{
  return FindOrAddPanelAnimationMap(className: "CSaveDocumentQuery");
}

//------------------------------------------------------------------------------
// Address: 0x102DDE90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSaveDocumentQuery::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSaveDocumentQuery::GetKBMap(CSaveDocumentQuery *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSaveDocumentQuery::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveDocumentQuery::GetKBMap'::`2'::s_pMap;
  `CSaveDocumentQuery::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CSaveDocumentQuery");
  `CSaveDocumentQuery::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102DDED0
// Name: public: CSaveDocumentQuery::CSaveDocumentQuery(class vgui::Panel __near *,char const __near *,char const __near *,int,class vgui::Panel __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CSaveDocumentQuery *__thiscall CSaveDocumentQuery::CSaveDocumentQuery(
        CSaveDocumentQuery *this,
        vgui::Panel *pParent,
        const char *pFileName,
        const char *pFileType,
        int nContext,
        vgui::Panel *pActionSignalTarget,
        KeyValues *pPostSaveCommand)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  const char *v11; // eax
  vgui::Label *v12; // eax
  vgui::Label *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  vgui::Button *v19; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "SaveDocumentQuery", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CSaveDocumentQuery_vtbl *)&CSaveDocumentQuery::`vftable';
  if ( `CSaveDocumentQuery::ChainToMap'::`2'::chained == 0 )
  {
    `CSaveDocumentQuery::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: (void **)"CSaveDocumentQuery");
    v8->pfnClassName = CSaveDocumentQuery::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"vgui::Frame");
  }
  if ( `CSaveDocumentQuery::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSaveDocumentQuery::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "CSaveDocumentQuery");
    v9->pfnClassName = CSaveDocumentQuery::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CSaveDocumentQuery::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSaveDocumentQuery::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"CSaveDocumentQuery");
    v10->pfnClassName = CSaveDocumentQuery::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"vgui::Frame");
  }
  v11 = pFileName;
  this->m_pActionSignalTarget = pActionSignalTarget;
  this->m_nContext = nContext;
  if ( pFileName == nullptr || *pFileName == 0 )
    v11 = "<untitled>";
  V_strncpy(pDest: this->m_szFileName, pSrc: v11, maxLen: 256);
  V_strncpy(pDest: this->m_szFileType, pSrc: pFileType, maxLen: 256);
  this->m_pPostSaveKeyValues = pPostSaveCommand;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  vgui::Frame::SetMinimizeButtonVisible(this, state: false);
  vgui::Frame::SetCloseButtonVisible(this, state: false);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetTitle(this, title: "Save Changes", surfaceTitle: true);
  v12 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v12 != nullptr )
    v13 = vgui::Label::Label(this: v12, parent: this, panelName: (__m128i *)"FileNameLabel", text: defaultValue);
  else
    v13 = nullptr;
  this->m_pMessageLabel = v13;
  v14 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "Yes",
            text: "Yes",
            pActionSignalTarget: this,
            pCmd: "yes");
  else
    v15 = nullptr;
  this->m_pYesButton = v15;
  v16 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v16 != nullptr )
    v17 = vgui::Button::Button(
            this: v16,
            parent: this,
            panelName: "No",
            text: "No",
            pActionSignalTarget: this,
            pCmd: "no");
  else
    v17 = nullptr;
  this->m_pNoButton = v17;
  v18 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v18 != nullptr )
    v19 = vgui::Button::Button(
            this: v18,
            parent: this,
            panelName: "Cancel",
            text: "Cancel",
            pActionSignalTarget: this,
            pCmd: "cancel");
  else
    v19 = nullptr;
  this->m_pCancelButton = v19;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/ToolSaveDocumentQuery.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  this->m_pMessageLabel->SetText(this: this->m_pMessageLabel, a2: this->m_szFileName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102DE160
// Name: void ShowSaveDocumentQuery(class vgui::Panel __near *,char const __near *,char const __near *,int,class vgui::Panel __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSaveDocumentQuery(
        vgui::Panel *pParent,
        const char *pFileName,
        const char *pFileType,
        int nContext,
        vgui::Panel *pActionSignalTarget,
        KeyValues *pPostSaveCommand)
{
  CSaveDocumentQuery *v6; // eax
  CSaveDocumentQuery *v7; // esi

  v6 = (CSaveDocumentQuery *)MemAlloc_Alloc(nSize: 0x430u);
  if ( v6 != nullptr )
    v7 = CSaveDocumentQuery::CSaveDocumentQuery(
           this: v6,
           pParent,
           pFileName,
           pFileType,
           nContext,
           pActionSignalTarget,
           pPostSaveCommand);
  else
    v7 = nullptr;
  v7->SetSmallCaption(this: v7, a2: true);
  v7->DoModal(this: v7);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10331A90
// Name: public: static char const __near * CSaveDocumentQuery::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSaveDocumentQuery::GetPanelClassName()
{
  return "CSaveDocumentQuery";
}

//------------------------------------------------------------------------------
// Address: 0x10331AA0
// Name: private: void CSaveDocumentQuery::PostCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::PostCommand(CSaveDocumentQuery *this, const char *pCommand)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  vgui::IVGui *v5; // esi
  vgui::IVGui_vtbl *v6; // edi
  int v7; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: pCommand);
  else
    v4 = nullptr;
  v5 = g_pVGui;
  v6 = g_pVGui->__vftable;
  v7 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->m_pActionSignalTarget->GetVPanel)(
         a1: this->m_pActionSignalTarget,
         a2: v4,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v6->PostMessage)(a1: v5, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10331B00
// Name: public: virtual void CSaveDocumentQuery::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::OnCommand(CSaveDocumentQuery *this, const char *cmd)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  KeyValues *v5; // ecx
  KeyValues *v6; // eax
  vgui::IVGui *v7; // ebx
  int v8; // eax
  KeyValues *m_pPostSaveKeyValues; // ecx
  vgui::IVGui *v10; // edi
  vgui::Panel *m_pActionSignalTarget; // ebx
  KeyValues *Copy; // eax
  int v13; // eax
  vgui::IVGui_vtbl *v14; // [esp+18h] [ebp+8h]
  vgui::IVGui_vtbl *v15; // [esp+18h] [ebp+8h]

  if ( _V_stricmp(s1: cmd, s2: "yes") != 0 )
  {
    if ( _V_stricmp(s1: cmd, s2: "no") != 0 )
    {
      if ( _V_stricmp(s1: cmd, s2: "cancel") != 0 )
      {
        vgui::Frame::OnCommand(this, command: cmd);
      }
      else
      {
        CSaveDocumentQuery::PostCommand(this, pCommand: "OnCancelSaveDocument");
        this->MarkForDeletion(this);
      }
    }
    else
    {
      CSaveDocumentQuery::PostCommand(this, pCommand: "OnMarkNotDirty");
      m_pPostSaveKeyValues = this->m_pPostSaveKeyValues;
      if ( m_pPostSaveKeyValues != nullptr )
      {
        v10 = g_pVGui;
        m_pActionSignalTarget = this->m_pActionSignalTarget;
        v15 = g_pVGui->__vftable;
        Copy = KeyValues::MakeCopy(this: m_pPostSaveKeyValues);
        v13 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))m_pActionSignalTarget->GetVPanel)(
                a1: m_pActionSignalTarget,
                a2: Copy,
                a3: 0,
                a4: 0);
        ((void (__thiscall *)(vgui::IVGui *, int))v15->PostMessage)(a1: v10, a2: v13);
      }
      this->MarkForDeletion(this);
    }
  }
  else
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "OnSaveFile");
    else
      v4 = nullptr;
    KeyValues::SetString(this: v4, keyName: "filename", value: this->m_szFileName);
    KeyValues::SetString(this: v4, keyName: "filetype", value: this->m_szFileType);
    KeyValues::SetInt(this: v4, keyName: "context", value: this->m_nContext);
    KeyValues::SetPtr(this: v4, keyName: "actionTarget", value: this->m_pActionSignalTarget);
    v5 = this->m_pPostSaveKeyValues;
    if ( v5 != nullptr )
    {
      v6 = KeyValues::MakeCopy(this: v5);
      KeyValues::AddSubKey(this: v4, pSubkey: v6);
    }
    v7 = g_pVGui;
    v14 = g_pVGui->__vftable;
    v8 = ((int (__stdcall *)(KeyValues *, _DWORD, _DWORD))this->m_pActionSignalTarget->GetVPanel)(a1: v4, a2: 0, a3: 0);
    ((void (__thiscall *)(vgui::IVGui *, int))v14->PostMessage)(a1: v7, a2: v8);
    this->MarkForDeletion(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10331CA0
// Name: public: virtual void CSaveDocumentQuery::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::ApplySchemeSettings(CSaveDocumentQuery *this, vgui::IScheme *pScheme)
{
  int wide; // [esp+4h] [ebp-Ch] BYREF
  int swide; // [esp+8h] [ebp-8h] BYREF
  int tall; // [esp+Ch] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: (int *)&pScheme);
  vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: ((int)pScheme - tall) / 2);
}

//------------------------------------------------------------------------------
// Address: 0x10331D00
// Name: public: virtual void CSaveDocumentQuery::DoModal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::DoModal(CSaveDocumentQuery *this)
{
  this->SetVisible(this, a2: true);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  this->RequestFocus(this, a2: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10331D50
// Name: public: virtual struct vgui::PanelMessageMap __near * CSaveDocumentQuery::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSaveDocumentQuery::GetMessageMap(CSaveDocumentQuery *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSaveDocumentQuery::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveDocumentQuery::GetMessageMap'::`2'::s_pMap;
  `CSaveDocumentQuery::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSaveDocumentQuery");
  `CSaveDocumentQuery::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10331D80
// Name: public: virtual struct PanelAnimationMap __near * CSaveDocumentQuery::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSaveDocumentQuery::GetAnimMap(CSaveDocumentQuery *this)
{
  return FindOrAddPanelAnimationMap(className: "CSaveDocumentQuery");
}

//------------------------------------------------------------------------------
// Address: 0x10331D90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSaveDocumentQuery::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSaveDocumentQuery::GetKBMap(CSaveDocumentQuery *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSaveDocumentQuery::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveDocumentQuery::GetKBMap'::`2'::s_pMap;
  `CSaveDocumentQuery::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSaveDocumentQuery");
  `CSaveDocumentQuery::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10331DC0
// Name: public: CSaveDocumentQuery::CSaveDocumentQuery(class vgui::Panel __near *,char const __near *,char const __near *,int,class vgui::Panel __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CSaveDocumentQuery *__thiscall CSaveDocumentQuery::CSaveDocumentQuery(
        CSaveDocumentQuery *this,
        vgui::Panel *pParent,
        char *pFileName,
        char *pFileType,
        int nContext,
        vgui::Panel *pActionSignalTarget,
        KeyValues *pPostSaveCommand)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  char *v11; // eax
  vgui::Label *v12; // eax
  vgui::Label *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  vgui::Button *v19; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "SaveDocumentQuery", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CSaveDocumentQuery_vtbl *)&CSaveDocumentQuery::`vftable';
  if ( `CSaveDocumentQuery::ChainToMap'::`2'::chained == 0 )
  {
    `CSaveDocumentQuery::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "CSaveDocumentQuery");
    v8->pfnClassName = CSaveDocumentQuery::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CSaveDocumentQuery::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSaveDocumentQuery::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "CSaveDocumentQuery");
    v9->pfnClassName = CSaveDocumentQuery::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CSaveDocumentQuery::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSaveDocumentQuery::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "CSaveDocumentQuery");
    v10->pfnClassName = CSaveDocumentQuery::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  v11 = pFileName;
  this->m_pActionSignalTarget = pActionSignalTarget;
  this->m_nContext = nContext;
  if ( pFileName == nullptr || *pFileName == 0 )
    v11 = "<untitled>";
  V_strncpy(pDest: this->m_szFileName, pSrc: v11, maxLen: 256);
  V_strncpy(pDest: this->m_szFileType, pSrc: pFileType, maxLen: 256);
  this->m_pPostSaveKeyValues = pPostSaveCommand;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  vgui::Frame::SetMinimizeButtonVisible(this, state: false);
  vgui::Frame::SetCloseButtonVisible(this, state: false);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetTitle(this, title: "Save Changes", surfaceTitle: true);
  v12 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v12 != nullptr )
    v13 = vgui::Label::Label(this: v12, parent: this, panelName: "FileNameLabel", text: &var);
  else
    v13 = nullptr;
  this->m_pMessageLabel = v13;
  v14 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "Yes",
            text: "Yes",
            pActionSignalTarget: this,
            pCmd: "yes");
  else
    v15 = nullptr;
  this->m_pYesButton = v15;
  v16 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v16 != nullptr )
    v17 = vgui::Button::Button(
            this: v16,
            parent: this,
            panelName: "No",
            text: "No",
            pActionSignalTarget: this,
            pCmd: "no");
  else
    v17 = nullptr;
  this->m_pNoButton = v17;
  v18 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v18 != nullptr )
    v19 = vgui::Button::Button(
            this: v18,
            parent: this,
            panelName: "Cancel",
            text: "Cancel",
            pActionSignalTarget: this,
            pCmd: "cancel");
  else
    v19 = nullptr;
  this->m_pCancelButton = v19;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/ToolSaveDocumentQuery.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  this->m_pMessageLabel->SetText(this: this->m_pMessageLabel, a2: this->m_szFileName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10332050
// Name: void ShowSaveDocumentQuery(class vgui::Panel __near *,char const __near *,char const __near *,int,class vgui::Panel __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSaveDocumentQuery(
        vgui::Panel *pParent,
        char *pFileName,
        char *pFileType,
        int nContext,
        vgui::Panel *pActionSignalTarget,
        KeyValues *pPostSaveCommand)
{
  CSaveDocumentQuery *v6; // eax
  CSaveDocumentQuery *v7; // esi

  v6 = (CSaveDocumentQuery *)operator new(nSize: 0x430u);
  if ( v6 != nullptr )
    v7 = CSaveDocumentQuery::CSaveDocumentQuery(
           this: v6,
           pParent,
           pFileName,
           pFileType,
           nContext,
           pActionSignalTarget,
           pPostSaveCommand);
  else
    v7 = nullptr;
  v7->SetSmallCaption(this: v7, a2: true);
  v7->DoModal(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1037E43F
// Name: public: int CMFCPopupMenu::PostCommand(unsigned int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMFCPopupMenu::PostCommand(CMFCPopupMenu *this, WPARAM commandID)
{
  CWnd *m_pMessageWnd; // ecx

  m_pMessageWnd = this->m_pMessageWnd;
  return m_pMessageWnd != nullptr
      && PostMessageA(
           hWnd: m_pMessageWnd->m_hWnd,
           Msg: (commandID - 61440 <= 0x1EF) + 273,
           wParam: commandID,
           lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1037E483
// Name: protected: int CMFCPopupMenu::AdjustScroll(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPopupMenu::AdjustScroll(CMFCPopupMenu *this, int bForceMenuBarResize)
{
  int m_iShadowSize; // eax
  CMFCPopupMenu::LOGO_LOCATION m_nLogoLocation; // eax
  __int32 v5; // eax
  __int32 v6; // eax
  int m_iScrollBtnHeight; // ecx
  int v8; // eax
  int v9; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-50h]
  CMFCPopupMenuBar *pMenuBar; // [esp+8h] [ebp-40h]
  unsigned int uiSWPFlags; // [esp+Ch] [ebp-3Ch]
  int nBorderSize; // [esp+10h] [ebp-38h]
  int nBorderSizea; // [esp+10h] [ebp-38h]
  CRect rectScrollUpOld; // [esp+14h] [ebp-34h] BYREF
  CRect rectScrollDnOld; // [esp+24h] [ebp-24h] BYREF
  CRect rectClient; // [esp+34h] [ebp-14h] BYREF

  pMenuBar = this->GetMenuBar(this);
  m_hWnd = this->m_hWnd;
  memset(&rectClient, 0, sizeof(rectClient));
  GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
  if ( CMFCToolBar::m_bCustomizeMode == 0 )
  {
    m_iShadowSize = this->m_iShadowSize;
    rectClient.right -= m_iShadowSize;
    rectClient.bottom -= m_iShadowSize;
  }
  nBorderSize = this->GetBorderSize(this);
  InflateRect(lprc: &rectClient, dx: -nBorderSize, dy: -nBorderSize);
  m_nLogoLocation = this->m_nLogoLocation;
  if ( m_nLogoLocation != MENU_LOGO_LEFT )
  {
    v5 = m_nLogoLocation - 1;
    if ( v5 != 0 )
    {
      v6 = v5 - 1;
      if ( v6 != 0 )
      {
        if ( v6 == 1 )
          rectClient.bottom -= this->m_iLogoWidth;
      }
      else
      {
        rectClient.top += this->m_iLogoWidth;
      }
    }
    else
    {
      rectClient.right -= this->m_iLogoWidth;
    }
  }
  else
  {
    rectClient.left += this->m_iLogoWidth;
  }
  rectClient.top += this->m_rectTearOffCaption.bottom - this->m_rectTearOffCaption.top;
  if ( this->m_bIsResizeBarOnTop != 0 )
    rectClient.top += this->m_rectResize.bottom - this->m_rectResize.top;
  else
    rectClient.bottom += this->m_rectResize.top - this->m_rectResize.bottom;
  rectScrollUpOld = this->m_rectScrollUp;
  rectScrollDnOld = this->m_rectScrollDn;
  SetRectEmpty(lprc: &this->m_rectScrollUp);
  SetRectEmpty(lprc: &this->m_rectScrollDn);
  uiSWPFlags = 20;
  if ( this->m_bScrollable != 0 )
  {
    if ( this->m_bShowScrollBar != 0 )
    {
      rectClient.right -= GetSystemMetrics(nIndex: 2);
    }
    else
    {
      if ( this->IsScrollUpAvailable(this) != 0 )
      {
        m_iScrollBtnHeight = this->m_iScrollBtnHeight;
        this->m_rectScrollUp = rectClient;
        this->m_rectScrollUp.top += nBorderSize;
        v8 = m_iScrollBtnHeight + this->m_rectScrollUp.top;
        rectClient.top += nBorderSize + m_iScrollBtnHeight;
        this->m_rectScrollUp.bottom = v8;
      }
      if ( this->IsScrollDnAvailable(this) != 0 )
      {
        v9 = this->m_iScrollBtnHeight;
        this->m_rectScrollDn = rectClient;
        this->m_rectScrollDn.top = this->m_rectScrollDn.bottom - v9;
        rectClient.bottom -= nBorderSize + v9;
      }
    }
  }
  else if ( this->m_bAnimationIsDone == 0 )
  {
    uiSWPFlags = 28;
    KillTimer(hWnd: this->m_hWnd, uIDEvent: 2u);
    this->m_iScrollMode = 0;
  }
  if ( bForceMenuBarResize == 0
    && EqualRect(lprc1: &rectScrollUpOld, lprc2: &this->m_rectScrollUp)
    && EqualRect(lprc1: &rectScrollDnOld, lprc2: &this->m_rectScrollDn) )
  {
    pMenuBar->AdjustLayout(this: pMenuBar);
  }
  else
  {
    pMenuBar->SetWindowPos(
      this: pMenuBar,
      a2: nullptr,
      a3: rectClient.left,
      a4: rectClient.top,
      a5: rectClient.right - rectClient.left,
      a6: rectClient.bottom - rectClient.top,
      a7: uiSWPFlags,
      a8: nullptr);
    this->m_nMenuBarHeight = rectClient.bottom - rectClient.top;
  }
  nBorderSizea = 0;
  if ( !EqualRect(lprc1: &rectScrollUpOld, lprc2: &this->m_rectScrollUp) )
  {
    InvalidateRect(hWnd: this->m_hWnd, lpRect: &rectScrollUpOld, bErase: true);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rectScrollUp, bErase: true);
    nBorderSizea = 1;
  }
  if ( !EqualRect(lprc1: &rectScrollDnOld, lprc2: &this->m_rectScrollDn) )
  {
    InvalidateRect(hWnd: this->m_hWnd, lpRect: &rectScrollDnOld, bErase: true);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rectScrollDn, bErase: true);
    nBorderSizea = 1;
  }
  if ( nBorderSizea != 0 )
    UpdateWindow(hWnd: this->m_hWnd);
  return nBorderSizea;
}

//------------------------------------------------------------------------------
// Address: 0x1037E74A
// Name: public: enum CMFCPopupMenu::MENUAREA_TYPE CMFCPopupMenu::CheckArea(class CPoint const __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPopupMenu::CheckArea(CMFCPopupMenu *this, const CPoint *ptScreen)
{
  CMFCPopupMenu::LOGO_LOCATION m_nLogoLocation; // eax
  __int32 v5; // eax
  __int32 v6; // eax
  int m_iShadowSize; // eax
  CRect rectTearOffCaption; // [esp+Ch] [ebp-34h] BYREF
  CRect rectLogo; // [esp+1Ch] [ebp-24h] BYREF
  CRect rectWindow; // [esp+2Ch] [ebp-14h] BYREF

  memset(&rectWindow, 0, sizeof(rectWindow));
  GetClientRect(hWnd: this->m_hWnd, lpRect: &rectWindow);
  CWnd::ClientToScreen(this, lpRect: (tagPOINT *)&rectWindow);
  if ( !PtInRect(lprc: &rectWindow, pt: ptScreen->tagPOINT) )
    return 4;
  rectLogo = rectWindow;
  m_nLogoLocation = this->m_nLogoLocation;
  if ( m_nLogoLocation != MENU_LOGO_LEFT )
  {
    v5 = m_nLogoLocation - 1;
    if ( v5 != 0 )
    {
      v6 = v5 - 1;
      if ( v6 != 0 )
      {
        if ( v6 == 1 )
          rectLogo.top = rectWindow.bottom - this->m_iLogoWidth;
      }
      else
      {
        rectLogo.bottom = rectWindow.top + this->m_iLogoWidth;
      }
    }
    else
    {
      rectLogo.left = rectWindow.right - this->m_iLogoWidth;
    }
  }
  else
  {
    rectLogo.right = rectWindow.left + this->m_iLogoWidth;
  }
  if ( PtInRect(lprc: &rectLogo, pt: ptScreen->tagPOINT) )
    return 3;
  m_iShadowSize = this->m_iShadowSize;
  if ( ptScreen->x > rectWindow.right - m_iShadowSize )
    return 1;
  if ( ptScreen->y > rectWindow.bottom - m_iShadowSize )
    return 2;
  if ( !IsRectEmpty(lprc: &this->m_rectTearOffCaption) )
  {
    rectTearOffCaption = this->m_rectTearOffCaption;
    CWnd::ClientToScreen(this, lpRect: (tagPOINT *)&rectTearOffCaption);
    if ( PtInRect(lprc: &rectTearOffCaption, pt: ptScreen->tagPOINT) )
      return 5;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1037E887
// Name: protected: void CMFCPopupMenu::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::OnLButtonDown(CMFCPopupMenu *this, unsigned int nFlags, CPoint point)
{
  HWND v4; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-18h]
  HWND__ *v6; // [esp-8h] [ebp-10h]

  if ( CMFCToolBar::m_bCustomizeMode != 0 || !PtInRect(lprc: &this->m_rectTearOffCaption, pt: point.tagPOINT) )
  {
    CWnd::Default(this);
  }
  else
  {
    m_hWnd = this->m_hWnd;
    this->m_bIsTearOffCaptionActive = 1;
    InvalidateRect(hWnd: m_hWnd, lpRect: &this->m_rectTearOffCaption, bErase: true);
    v6 = this->m_hWnd;
    this->m_bTearOffTracking = 1;
    v4 = SetCapture(hWnd: v6);
    CWnd::FromHandle(hWnd: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037E8EA
// Name: protected: void CMFCPopupMenu::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::OnLButtonUp(CMFCPopupMenu *this, unsigned int nFlags, CPoint point)
{
  if ( this->m_bTearOffTracking != 0 )
  {
    this->m_bTearOffTracking = 0;
    ReleaseCapture();
    this->m_bIsTearOffCaptionActive = 0;
    InvalidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rectTearOffCaption, bErase: true);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1037E929
// Name: public: virtual int CMFCPopupMenu::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCPopupMenu::PreTranslateMessage(CMFCPopupMenu *this, tagMSG *pMsg)
{
  CPoint ptCursor; // [esp+Ch] [ebp-8h] BYREF

  if ( this != (CMFCPopupMenu *)-4080 && this->m_wndToolTip.m_hWnd != nullptr )
    SendMessageA(hWnd: this->m_wndToolTip.m_hWnd, Msg: 0x407u, wParam: 0, lParam: (LPARAM)pMsg);
  if ( pMsg->message != 512 || IsRectEmpty(lprc: &this->m_rectScrollUp) && IsRectEmpty(lprc: &this->m_rectScrollDn) )
    return CFrameWnd::PreTranslateMessage(this, pMsg);
  ptCursor = 0;
  GetCursorPos(lpPoint: &ptCursor);
  ScreenToClient(hWnd: this->m_hWnd, lpPoint: &ptCursor);
  if ( !PtInRect(lprc: &this->m_rectScrollUp, pt: ptCursor.tagPOINT)
    && !PtInRect(lprc: &this->m_rectScrollDn, pt: ptCursor.tagPOINT) )
  {
    return CFrameWnd::PreTranslateMessage(this, pMsg);
  }
  CMFCPopupMenu::OnMouseMove(this, nFlags: pMsg->wParam, point: ptCursor);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1037E9F5
// Name: protected: virtual int CMFCPopupMenu::OnNotify(unsigned int,long,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPopupMenu::OnNotify(CMFCPopupMenu *this, unsigned int wParam, tagNMHDR *lParam, int *pResult)
{
  unsigned int code; // eax

  if ( lParam == nullptr )
    AfxThrowInvalidArgException();
  code = lParam->code;
  if ( code == -521 )
  {
    this->m_bIsTearOffCaptionActive = 1;
    InvalidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rectTearOffCaption, bErase: true);
LABEL_7:
    UpdateWindow(hWnd: this->m_hWnd);
    return CWnd::OnNotify(this, __formal: wParam, lParam, pResult);
  }
  if ( code == -522 )
  {
    this->m_bIsTearOffCaptionActive = 0;
    InvalidateRect(hWnd: this->m_hWnd, lpRect: &this->m_rectTearOffCaption, bErase: true);
    goto LABEL_7;
  }
  return CWnd::OnNotify(this, __formal: wParam, lParam, pResult);
}

//------------------------------------------------------------------------------
// Address: 0x1037EA5D
// Name: public: void CMFCPopupMenu::UpdateShadow(struct tagRECT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::UpdateShadow(CMFCPopupMenu *this, tagRECT *lprectScreen)
{
  CWnd *TopLevelParent; // eax
  int v4; // eax
  int v5; // ecx
  HWND__ *m_hWnd; // [esp-Ch] [ebp-BCh]
  HWND__ *v7; // [esp-Ch] [ebp-BCh]
  HWND v8; // [esp-Ch] [ebp-BCh]
  int v9; // [esp-Ch] [ebp-BCh]
  CMFCPopupMenuBar *pMenuBar; // [esp+8h] [ebp-A8h]
  int bIsRTL; // [esp+Ch] [ebp-A4h]
  int iShadowSize; // [esp+10h] [ebp-A0h]
  CWnd *pWndMain; // [esp+14h] [ebp-9Ch]
  unsigned int uiSWPFlags; // [esp+18h] [ebp-98h]
  CRect rectShadowBottom; // [esp+1Ch] [ebp-94h] BYREF
  CRect rectMenu; // [esp+2Ch] [ebp-84h] BYREF
  CRect rectParent; // [esp+3Ch] [ebp-74h] BYREF
  CRect rectWindow; // [esp+4Ch] [ebp-64h] BYREF
  CRect rectUpdate2; // [esp+5Ch] [ebp-54h] BYREF
  CRect rectInter; // [esp+6Ch] [ebp-44h] BYREF
  CRect rectUpdate1; // [esp+7Ch] [ebp-34h] BYREF
  CRect rectMain; // [esp+8Ch] [ebp-24h] BYREF
  CRect rectClient; // [esp+9Ch] [ebp-14h] BYREF

  if ( this->m_iShadowSize > 0 )
  {
    TopLevelParent = CWnd::GetTopLevelParent(this);
    pWndMain = TopLevelParent;
    if ( TopLevelParent != nullptr && TopLevelParent->m_hWnd != nullptr )
    {
      bIsRTL = CWnd::GetExStyle(this) & 0x400000;
      m_hWnd = this->m_hWnd;
      memset(&rectClient, 0, sizeof(rectClient));
      GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
      rectUpdate1 = rectClient;
      rectUpdate2 = rectClient;
      if ( lprectScreen == nullptr )
        goto LABEL_14;
      CopyRect(lprcDst: &rectMain, lprcSrc: lprectScreen);
      CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&rectMain);
      rectInter = rectClient;
      if ( bIsRTL != 0 )
        rectInter.right = rectClient.left + this->m_iShadowSize + 1;
      else
        rectInter.left = rectClient.right - this->m_iShadowSize - 1;
      if ( !IntersectRect(lprcDst: &rectUpdate1, lprcSrc1: &rectMain, lprcSrc2: &rectInter) )
        SetRectEmpty(lprc: &rectUpdate1);
      v4 = rectClient.bottom - this->m_iShadowSize;
      rectShadowBottom.left = rectClient.left;
      rectShadowBottom.right = rectClient.right;
      rectShadowBottom.bottom = rectClient.bottom;
      rectShadowBottom.top = v4 - 1;
      if ( !IntersectRect(lprcDst: &rectUpdate2, lprcSrc1: &rectMain, lprcSrc2: &rectShadowBottom) )
        SetRectEmpty(lprc: &rectUpdate2);
      if ( !IsRectEmpty(lprc: &rectUpdate1) || !IsRectEmpty(lprc: &rectUpdate2) )
      {
LABEL_14:
        v7 = this->m_hWnd;
        memset(&rectMenu, 0, sizeof(rectMenu));
        GetWindowRect(hWnd: v7, lpRect: &rectMenu);
        if ( CMFCPopupMenu::m_bForceShadow != 0
          || (v8 = pWndMain->m_hWnd,
              memset(&rectMain, 0, sizeof(rectMain)),
              GetWindowRect(hWnd: v8, lpRect: &rectMain),
              memset(&rectInter, 0, sizeof(rectInter)),
              UnionRect(lprcDst: &rectInter, lprcSrc1: &rectMenu, lprcSrc2: &rectMain),
              EqualRect(lprc1: &rectInter, lprc2: &rectMain)) )
        {
          iShadowSize = this->m_iShadowSize;
          this->m_iShadowSize = 0;
          if ( this != (CMFCPopupMenu *)-4036 && this->m_bmpShadowRight.m_hObject != nullptr )
            CGdiObject::DeleteObject(this: &this->m_bmpShadowRight);
          if ( this != (CMFCPopupMenu *)-4044 && this->m_bmpShadowBottom.m_hObject != nullptr )
            CGdiObject::DeleteObject(this: &this->m_bmpShadowBottom);
          memset(&rectWindow, 255, sizeof(rectWindow));
          uiSWPFlags = 1052;
          pMenuBar = this->GetMenuBar(this);
          pMenuBar->m_bInUpdateShadow = 1;
          if ( bIsRTL != 0 )
          {
            GetWindowRect(hWnd: this->m_hWnd, lpRect: &rectWindow);
            CWnd::SetWindowPos(
              this,
              pWndInsertAfter: nullptr,
              x: iShadowSize + rectWindow.left,
              y: rectWindow.top,
              cx: rectClient.right - rectClient.left - iShadowSize,
              cy: rectClient.bottom - rectClient.top - iShadowSize,
              nFlags: 0x41Cu);
          }
          else
          {
            uiSWPFlags = 1054;
            CWnd::SetWindowPos(
              this,
              pWndInsertAfter: nullptr,
              x: -1,
              y: -1,
              cx: rectClient.right - rectClient.left - iShadowSize,
              cy: rectClient.bottom - rectClient.top - iShadowSize,
              nFlags: 0x41Eu);
          }
          rectParent = rectUpdate1;
          if ( !IsRectEmpty(lprc: &rectUpdate1) )
          {
            MapWindowPoints(
              hWndFrom: this->m_hWnd,
              hWndTo: pWndMain->m_hWnd,
              lpPoints: (LPPOINT)&rectParent,
              cPoints: 2u);
            RedrawWindow(hWnd: pWndMain->m_hWnd, lprcUpdate: &rectParent, hrgnUpdate: nullptr, flags: 0x185u);
          }
          rectParent = rectUpdate2;
          if ( !IsRectEmpty(lprc: &rectUpdate2) && !EqualRect(lprc1: &rectUpdate1, lprc2: &rectUpdate2) )
          {
            MapWindowPoints(
              hWndFrom: this->m_hWnd,
              hWndTo: pWndMain->m_hWnd,
              lpPoints: (LPPOINT)&rectParent,
              cPoints: 2u);
            RedrawWindow(hWnd: pWndMain->m_hWnd, lprcUpdate: &rectParent, hrgnUpdate: nullptr, flags: 0x185u);
          }
          UpdateWindow(hWnd: pWndMain->m_hWnd);
          v9 = rectClient.bottom - rectClient.top;
          v5 = rectClient.right - rectClient.left;
          this->m_iShadowSize = iShadowSize;
          if ( bIsRTL != 0 )
            CWnd::SetWindowPos(
              this,
              pWndInsertAfter: nullptr,
              x: rectWindow.left,
              y: rectWindow.top,
              cx: v5,
              cy: v9,
              nFlags: uiSWPFlags);
          else
            CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: -1, y: -1, cx: v5, cy: v9, nFlags: uiSWPFlags);
          if ( !IsRectEmpty(lprc: &rectUpdate1) )
            InvalidateRect(hWnd: this->m_hWnd, lpRect: &rectUpdate1, bErase: true);
          if ( !IsRectEmpty(lprc: &rectUpdate2) && !EqualRect(lprc1: &rectUpdate1, lprc2: &rectUpdate2) )
            InvalidateRect(hWnd: this->m_hWnd, lpRect: &rectUpdate2, bErase: true);
          UpdateWindow(hWnd: this->m_hWnd);
          pMenuBar->m_bInUpdateShadow = 0;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037EE6E
// Name: public: static void CMFCPopupMenu::UpdateAllShadows(struct tagRECT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CMFCPopupMenu::UpdateAllShadows(tagRECT *lprectScreen)
{
  CMFCPopupMenu *i; // esi

  for ( i = (CMFCPopupMenu *)CMFCPopupMenu::m_pActivePopupMenu; i != nullptr; i = CMFCPopupMenu::GetParentPopupMenu(this: i) )
  {
    if ( CWnd::FromHandlePermanent(hWnd: (CDocument *)i->m_hWnd) != nullptr )
      CMFCPopupMenu::UpdateShadow(this: i, lprectScreen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1037EEA5
// Name: protected: void CMFCPopupMenu::OnShowWindow(int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenu::OnShowWindow(CMFCPopupMenu *this, int bShow, unsigned int nStatus)
{
  CWnd::Default(this);
  if ( bShow == 0 )
    this->m_bShown = 0;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0066FBC0
// Name: public: static char const __near * CSaveDocumentQuery::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSaveDocumentQuery::GetPanelClassName()
{
  return "CSaveDocumentQuery";
}

//------------------------------------------------------------------------------
// Address: 0x0066FBD0
// Name: private: void CSaveDocumentQuery::PostCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::PostCommand(CSaveDocumentQuery *this, const char *pCommand)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  vgui::IVGui *v5; // esi
  vgui::IVGui_vtbl *v6; // edi
  int v7; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: pCommand);
  else
    v4 = nullptr;
  v5 = g_pVGui;
  v6 = g_pVGui->__vftable;
  v7 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))this->m_pActionSignalTarget->GetVPanel)(
         a1: this->m_pActionSignalTarget,
         a2: v4,
         a3: 0,
         a4: 0);
  ((void (__thiscall *)(vgui::IVGui *, int))v6->PostMessage)(a1: v5, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x0066FC30
// Name: public: virtual void CSaveDocumentQuery::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::OnCommand(CSaveDocumentQuery *this, const char *cmd)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  KeyValues *v5; // ecx
  KeyValues *v6; // eax
  vgui::IVGui *v7; // ebx
  int v8; // eax
  KeyValues *m_pPostSaveKeyValues; // ecx
  vgui::IVGui *v10; // edi
  vgui::Panel *m_pActionSignalTarget; // ebx
  KeyValues *Copy; // eax
  int v13; // eax
  vgui::IVGui_vtbl *cmda; // [esp+18h] [ebp+8h]
  vgui::IVGui_vtbl *cmdb; // [esp+18h] [ebp+8h]

  if ( _V_stricmp(s1: cmd, s2: "yes") != 0 )
  {
    if ( _V_stricmp(s1: cmd, s2: "no") != 0 )
    {
      if ( _V_stricmp(s1: cmd, s2: "cancel") != 0 )
      {
        vgui::Frame::OnCommand(this, command: cmd);
      }
      else
      {
        CSaveDocumentQuery::PostCommand(this, pCommand: "OnCancelSaveDocument");
        this->MarkForDeletion(this);
      }
    }
    else
    {
      CSaveDocumentQuery::PostCommand(this, pCommand: "OnMarkNotDirty");
      m_pPostSaveKeyValues = this->m_pPostSaveKeyValues;
      if ( m_pPostSaveKeyValues != nullptr )
      {
        v10 = g_pVGui;
        m_pActionSignalTarget = this->m_pActionSignalTarget;
        cmdb = g_pVGui->__vftable;
        Copy = KeyValues::MakeCopy(this: m_pPostSaveKeyValues);
        v13 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD, _DWORD))m_pActionSignalTarget->GetVPanel)(
                a1: m_pActionSignalTarget,
                a2: Copy,
                a3: 0,
                a4: 0);
        ((void (__thiscall *)(vgui::IVGui *, int))cmdb->PostMessage)(a1: v10, a2: v13);
      }
      this->MarkForDeletion(this);
    }
  }
  else
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(this: v3, setName: "OnSaveFile");
    else
      v4 = nullptr;
    KeyValues::SetString(this: v4, keyName: "filename", value: this->m_szFileName);
    KeyValues::SetString(this: v4, keyName: "filetype", value: this->m_szFileType);
    KeyValues::SetInt(this: v4, keyName: "context", value: this->m_nContext);
    KeyValues::SetPtr(this: v4, keyName: "actionTarget", value: this->m_pActionSignalTarget);
    v5 = this->m_pPostSaveKeyValues;
    if ( v5 != nullptr )
    {
      v6 = KeyValues::MakeCopy(this: v5);
      KeyValues::AddSubKey(this: v4, pSubkey: v6);
    }
    v7 = g_pVGui;
    cmda = g_pVGui->__vftable;
    v8 = ((int (__stdcall *)(KeyValues *, _DWORD, _DWORD))this->m_pActionSignalTarget->GetVPanel)(a1: v4, a2: 0, a3: 0);
    ((void (__thiscall *)(vgui::IVGui *, int))cmda->PostMessage)(a1: v7, a2: v8);
    this->MarkForDeletion(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0066FDD0
// Name: public: virtual void CSaveDocumentQuery::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::ApplySchemeSettings(CSaveDocumentQuery *this, vgui::IScheme *pScheme)
{
  int wide; // [esp+4h] [ebp-Ch] BYREF
  int swide; // [esp+8h] [ebp-8h] BYREF
  int tall; // [esp+Ch] [ebp-4h] BYREF

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &swide, a3: (int *)&pScheme);
  vgui::Panel::SetPos(this, x: (swide - wide) / 2, y: ((int)pScheme - tall) / 2);
}

//------------------------------------------------------------------------------
// Address: 0x0066FE30
// Name: public: virtual void CSaveDocumentQuery::DoModal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveDocumentQuery::DoModal(CSaveDocumentQuery *this)
{
  this->SetVisible(this, a2: true);
  this->SetEnabled(this, a2: true);
  this->MoveToFront(this);
  this->RequestFocus(this, a2: 0);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0066FE80
// Name: public: virtual struct vgui::PanelMessageMap __near * CSaveDocumentQuery::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSaveDocumentQuery::GetMessageMap(CSaveDocumentQuery *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSaveDocumentQuery::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveDocumentQuery::GetMessageMap'::`2'::s_pMap;
  `CSaveDocumentQuery::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSaveDocumentQuery");
  `CSaveDocumentQuery::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0066FEB0
// Name: public: virtual struct PanelAnimationMap __near * CSaveDocumentQuery::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSaveDocumentQuery::GetAnimMap(CSaveDocumentQuery *this)
{
  return FindOrAddPanelAnimationMap(className: "CSaveDocumentQuery");
}

//------------------------------------------------------------------------------
// Address: 0x0066FEC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSaveDocumentQuery::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSaveDocumentQuery::GetKBMap(CSaveDocumentQuery *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSaveDocumentQuery::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveDocumentQuery::GetKBMap'::`2'::s_pMap;
  `CSaveDocumentQuery::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSaveDocumentQuery");
  `CSaveDocumentQuery::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0066FEF0
// Name: public: CSaveDocumentQuery::CSaveDocumentQuery(class vgui::Panel __near *,char const __near *,char const __near *,int,class vgui::Panel __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CSaveDocumentQuery *__thiscall CSaveDocumentQuery::CSaveDocumentQuery(
        CSaveDocumentQuery *this,
        vgui::Panel *pParent,
        char *pFileName,
        char *pFileType,
        int nContext,
        vgui::Panel *pActionSignalTarget,
        KeyValues *pPostSaveCommand)
{
  vgui::PanelMessageMap *v8; // edi
  PanelAnimationMap *v9; // edi
  vgui::PanelKeyBindingMap *v10; // edi
  char *v11; // eax
  vgui::Label *v12; // eax
  vgui::Label *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  vgui::Button *v19; // eax

  vgui::Frame::Frame(this, parent: pParent, panelName: "SaveDocumentQuery", showTaskbarIcon: 1, bPopup: true);
  this->__vftable = (CSaveDocumentQuery_vtbl *)&CSaveDocumentQuery::`vftable';
  if ( `CSaveDocumentQuery::ChainToMap'::`2'::chained == 0 )
  {
    `CSaveDocumentQuery::ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelMessageMap(className: "CSaveDocumentQuery");
    v8->pfnClassName = CSaveDocumentQuery::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CSaveDocumentQuery::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSaveDocumentQuery::ChainToAnimationMap'::`2'::chained = 1;
    v9 = FindOrAddPanelAnimationMap(className: "CSaveDocumentQuery");
    v9->pfnClassName = CSaveDocumentQuery::GetPanelClassName;
    v9->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CSaveDocumentQuery::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSaveDocumentQuery::KB_ChainToMap'::`2'::chained = 1;
    v10 = vgui::FindOrAddPanelKeyBindingMap(className: "CSaveDocumentQuery");
    v10->pfnClassName = CSaveDocumentQuery::GetPanelClassName;
    v10->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  v11 = pFileName;
  this->m_pActionSignalTarget = pActionSignalTarget;
  this->m_nContext = nContext;
  if ( pFileName == nullptr || *pFileName == 0 )
    v11 = "<untitled>";
  V_strncpy(pDest: this->m_szFileName, pSrc: v11, maxLen: 256);
  V_strncpy(pDest: this->m_szFileType, pSrc: pFileType, maxLen: 256);
  this->m_pPostSaveKeyValues = pPostSaveCommand;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetMenuButtonResponsive(this, state: false);
  vgui::Frame::SetMinimizeButtonVisible(this, state: false);
  vgui::Frame::SetCloseButtonVisible(this, state: false);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetTitle(this, title: "Save Changes", surfaceTitle: true);
  v12 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v12 != nullptr )
    v13 = vgui::Label::Label(this: v12, parent: this, panelName: "FileNameLabel", text: defaultValue);
  else
    v13 = nullptr;
  this->m_pMessageLabel = v13;
  v14 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "Yes",
            text: "Yes",
            pActionSignalTarget: this,
            pCmd: "yes");
  else
    v15 = nullptr;
  this->m_pYesButton = v15;
  v16 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v16 != nullptr )
    v17 = vgui::Button::Button(
            this: v16,
            parent: this,
            panelName: "No",
            text: "No",
            pActionSignalTarget: this,
            pCmd: "no");
  else
    v17 = nullptr;
  this->m_pNoButton = v17;
  v18 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v18 != nullptr )
    v19 = vgui::Button::Button(
            this: v18,
            parent: this,
            panelName: "Cancel",
            text: "Cancel",
            pActionSignalTarget: this,
            pCmd: "cancel");
  else
    v19 = nullptr;
  this->m_pCancelButton = v19;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/ToolSaveDocumentQuery.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  this->m_pMessageLabel->SetText_2(this: this->m_pMessageLabel, a2: this->m_szFileName);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00670180
// Name: void ShowSaveDocumentQuery(class vgui::Panel __near *,char const __near *,char const __near *,int,class vgui::Panel __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowSaveDocumentQuery(
        vgui::Panel *pParent,
        char *pFileName,
        char *pFileType,
        int nContext,
        vgui::Panel *pActionSignalTarget,
        KeyValues *pPostSaveCommand)
{
  CSaveDocumentQuery *v6; // eax
  CSaveDocumentQuery *v7; // esi

  v6 = (CSaveDocumentQuery *)MemAlloc_Alloc(nSize: 0x430u);
  if ( v6 != nullptr )
    v7 = CSaveDocumentQuery::CSaveDocumentQuery(
           this: v6,
           pParent,
           pFileName,
           pFileType,
           nContext,
           pActionSignalTarget,
           pPostSaveCommand);
  else
    v7 = nullptr;
  v7->SetSmallCaption(this: v7, a2: true);
  v7->DoModal(this: v7);
}

} // namespace sceneviewer
