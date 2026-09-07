// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vgui_editor/vgui/vgui_src_editor_dialog.cpp
// Functions: 19
// ============================================================

#include "utils\vgui_editor\vgui\vgui_src_editor_dialog.h"

//------------------------------------------------------------------------------
// Address: 0x0040C9B0
// Name: public: static char const __near * CVGUI_Src_Editor_Dialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVGUI_Src_Editor_Dialog::GetPanelClassName()
{
  return "CVGUI_Src_Editor_Dialog";
}

//------------------------------------------------------------------------------
// Address: 0x0040C9C0
// Name: public: virtual void CVGUI_Src_Editor_Dialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGUI_Src_Editor_Dialog::PerformLayout(CVGUI_Src_Editor_Dialog *this)
{
  int v2; // [esp-8h] [ebp-14h]
  int v3; // [esp-4h] [ebp-10h]
  int screenWide; // [esp+4h] [ebp-8h] BYREF
  int screenTall; // [esp+8h] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  if ( this->m_bFirstPerformLayout )
  {
    g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &screenWide, a3: &screenTall);
    v3 = screenTall;
    v2 = screenWide;
    this->m_bFirstPerformLayout = false;
    vgui::Panel::SetBounds(this, x: 0, y: 0, wide: v2, tall: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CA10
// Name: public: virtual void CVGUI_Src_Editor_Dialog::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGUI_Src_Editor_Dialog::ApplySchemeSettings(CVGUI_Src_Editor_Dialog *this, vgui::IScheme *pScheme)
{
  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->LoadControlSettings(
    this,
    a2: "resource/UI/vgui_editor/VGUISrcEditorDialog.res",
    a3: nullptr,
    a4: nullptr,
    a5: nullptr);
  this->SetMoveable(this, a2: false);
  this->SetSizeable(this, a2: false);
  this->SetMinimizeButtonVisible(this, a2: false);
  this->SetMaximizeButtonVisible(this, a2: false);
  this->SetCloseButtonVisible(this, a2: false);
  this->SetMenuButtonVisible(this, a2: false);
  this->SetTitleBarVisible(this, a2: false);
  this->SetVisible(this, a2: true);
  this->m_bFirstPerformLayout = true;
}

//------------------------------------------------------------------------------
// Address: 0x0040CAC0
// Name: public: virtual void CVGUI_Src_Editor_Dialog::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGUI_Src_Editor_Dialog::OnTick(CVGUI_Src_Editor_Dialog *this)
{
  vgui::AnimationController *AnimationController; // eax
  float currentTime; // [esp+0h] [ebp-4h]

  currentTime = _Plat_FloatTime(a1: this);
  AnimationController = vgui::GetAnimationController();
  vgui::AnimationController::UpdateAnimations(this: AnimationController, currentTime);
}

//------------------------------------------------------------------------------
// Address: 0x0040CAE0
// Name: public: virtual void CVGUI_Src_Editor_Dialog::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CVGUI_Src_Editor_Dialog::OnClose(CVGUI_Src_Editor_Dialog *this)
{
  vgui::Frame::OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040CAF0
// Name: public: void CVGUI_Src_Editor_Dialog::SetCurrentManagedData(class CManaged_Panel_Data __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGUI_Src_Editor_Dialog::SetCurrentManagedData(
        CVGUI_Src_Editor_Dialog *this,
        CManaged_Panel_Data *pData)
{
  KeyValues *ResFileKeys; // ebx
  vgui::Label_vtbl *v4; // ebx
  char *FullResFilename; // eax

  CManaged_Child_List::SetCurrentManagedPanel(this: this->m_pManagedChildList, pManagedPanelData: pData);
  ResFileKeys = CManaged_Panel_Data::GetResFileKeys(this: pData, bForceReload: false);
  CRes_Visualizer::SetKeys(this: this->m_pResVis, pKeys: ResFileKeys, bRecurse: true);
  CRes_Child_List::SetKeys(this: this->m_pResChildList, pResKeys: ResFileKeys);
  v4 = this->m_pCurrentResFileLabel->__vftable;
  FullResFilename = CManaged_Panel_Data::GetFullResFilename(this: pData);
  v4->SetText(this: this->m_pCurrentResFileLabel, a2: FullResFilename);
}

//------------------------------------------------------------------------------
// Address: 0x0040CB60
// Name: public: void CVGUI_Src_Editor_Dialog::StartEditingChildKeys(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGUI_Src_Editor_Dialog::StartEditingChildKeys(CVGUI_Src_Editor_Dialog *this, KeyValues *pChildResKeys)
{
  CKV_Editor *m_pChildEditor; // ecx
  KeyValues *m_pChildResKeys; // ecx
  const char *String; // edi
  bool v6; // zf
  void (__thiscall *SetFileSpec_2)(CKV_Editor *, const char *, const char *); // eax

  m_pChildEditor = this->m_pChildEditor;
  this->m_pChildResKeys = pChildResKeys;
  m_pChildEditor->SetKeys(this: m_pChildEditor, a2: nullptr);
  m_pChildResKeys = this->m_pChildResKeys;
  if ( m_pChildResKeys != nullptr )
  {
    String = KeyValues::GetString(this: m_pChildResKeys, keyName: "ControlName", defaultValue: &defaultValue);
    if ( _V_stricmp(s1: String, s2: "Label") != 0 && _V_stricmp(s1: String, s2: "Button") != 0 )
    {
      v6 = _V_stricmp(s1: String, s2: "ImagePanel") == 0;
      SetFileSpec_2 = this->m_pChildEditor->SetFileSpec_2;
      if ( v6 )
        ((void (__stdcall *)(const char *, const char *))SetFileSpec_2)(
          a1: "resource/UI/vgui_editor/filespec_imagepanel.txt",
          a2: "GAME");
      else
        ((void (__stdcall *)(const char *, const char *))SetFileSpec_2)(
          a1: "resource/UI/vgui_editor/filespec_panel.txt",
          a2: "GAME");
    }
    else
    {
      ((void (__stdcall *)(const char *, const char *))this->m_pChildEditor->SetFileSpec_2)(
        a1: "resource/UI/vgui_editor/filespec_label.txt",
        a2: "GAME");
    }
  }
  this->m_pChildEditor->SetKeys(this: this->m_pChildEditor, a2: this->m_pChildResKeys);
}

//------------------------------------------------------------------------------
// Address: 0x0040CC30
// Name: public: virtual void CVGUI_Src_Editor_Dialog::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGUI_Src_Editor_Dialog::OnKeyCodePressed(CVGUI_Src_Editor_Dialog *this, ButtonCode_t code)
{
  vgui::Panel::OnKeyCodePressed(this, code);
  if ( code == KEY_BACKQUOTE )
  {
    this->m_pConsole->IsVisible(this: this->m_pConsole);
  }
  else if ( code == KEY_ESCAPE )
  {
    g_pVGui->Stop(this: g_pVGui);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CC80
// Name: public: virtual void CVGUI_Src_Editor_Dialog::OnCommandSubmitted(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVGUI_Src_Editor_Dialog::OnCommandSubmitted(
        CVGUI_Src_Editor_Dialog *this@<ecx>,
        int a2@<esi>,
        const char *command)
{
  const char *v3; // eax
  int v4; // eax
  _DWORD *v5; // esi
  int Channel; // eax
  int v7; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // ecx
  const char *v11; // eax
  _DWORD *v12; // edi
  int v13; // esi
  char *v14; // eax
  float v15; // [esp+Ch] [ebp-510h]
  CCommand args; // [esp+14h] [ebp-508h] BYREF

  CCommand::CCommand(this: &args);
  CCommand::Tokenize(this: &args, pCommand: command, pBreakSet: nullptr);
  v3 = &defaultValue;
  if ( args.m_nArgc > 0 )
    v3 = args.m_ppArgv[0];
  v4 = ((int (__thiscall *)(ICvar *, const char *, int))g_pCVar->FindCommandBase_2)(a1: g_pCVar, a2: v3, a3: a2);
  v5 = (_DWORD *)v4;
  if ( v4 != 0 )
  {
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4) != 0 )
    {
      (*(void (__thiscall **)(_DWORD *, CCommand *))(*v5 + 56))(a1: v5, a2: &args);
    }
    else if ( args.m_nArgc == 1 )
    {
      if ( (*(unsigned __int8 (__stdcall **)(int))(*v5 + 8))(a1: 4096) != 0 )
      {
        v8 = &defaultValue;
        if ( args.m_nArgc > 0 )
          v8 = args.m_ppArgv[0];
        ConMsg(a1: "%s = %f\n", v8, *(float *)(v5[7] + 44));
      }
      else
      {
        if ( (v5[5] & 0x1000) != 0 )
        {
          v9 = "FCVAR_NEVER_AS_STRING";
        }
        else
        {
          v9 = *(const char **)(v5[7] + 36);
          if ( v9 == nullptr )
            v9 = &defaultValue;
        }
        v10 = &defaultValue;
        if ( args.m_nArgc > 0 )
          v10 = args.m_ppArgv[0];
        ConMsg(a1: "%s = %s\n", v10, v9);
      }
    }
    else if ( (*(unsigned __int8 (__stdcall **)(int))(*v5 + 8))(a1: 4096) != 0 )
    {
      v11 = &defaultValue;
      if ( args.m_nArgc > 1 )
        v11 = args.m_ppArgv[1];
      v12 = v5 + 6;
      v13 = v5[6];
      v15 = atof(nptr: v11);
      (*(void (__thiscall **)(_DWORD *, _DWORD))(v13 + 8))(a1: v12, a2: LODWORD(v15));
    }
    else
    {
      v14 = &args.m_pArgSBuffer[args.m_nArgv0Size];
      if ( args.m_nArgv0Size == 0 )
        v14 = (char *)&defaultValue;
      (*(void (__thiscall **)(_DWORD *, char *))(v5[6] + 12))(a1: v5 + 6, a2: v14);
    }
  }
  else
  {
    Channel = _LoggingSystem_FindChannel(a1: "Console");
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: Channel) != 0 )
    {
      v7 = _LoggingSystem_FindChannel(a1: "Console");
      _LoggingSystem_Log(a1: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CE60
// Name: public: virtual void CVGUI_Src_Editor_Dialog::KeyValuesChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGUI_Src_Editor_Dialog::KeyValuesChanged(CVGUI_Src_Editor_Dialog *this, CKV_Editor *panel)
{
  CManaged_Panel_Data *m_pCurrentManagedPanel; // ecx
  KeyValues *ResFileKeys; // eax

  if ( panel == this->m_pChildEditor )
  {
    m_pCurrentManagedPanel = this->m_pManagedChildList->m_pCurrentManagedPanel;
    if ( m_pCurrentManagedPanel != nullptr )
    {
      ResFileKeys = CManaged_Panel_Data::GetResFileKeys(this: m_pCurrentManagedPanel, bForceReload: false);
      if ( ResFileKeys != nullptr )
        CRes_Visualizer::SetKeys(this: this->m_pResVis, pKeys: ResFileKeys, bRecurse: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CEB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CVGUI_Src_Editor_Dialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVGUI_Src_Editor_Dialog::GetMessageMap(CVGUI_Src_Editor_Dialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVGUI_Src_Editor_Dialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVGUI_Src_Editor_Dialog::GetMessageMap'::`2'::s_pMap;
  `CVGUI_Src_Editor_Dialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVGUI_Src_Editor_Dialog");
  `CVGUI_Src_Editor_Dialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040CEE0
// Name: public: virtual struct PanelAnimationMap __near * CVGUI_Src_Editor_Dialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVGUI_Src_Editor_Dialog::GetAnimMap(CVGUI_Src_Editor_Dialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CVGUI_Src_Editor_Dialog");
}

//------------------------------------------------------------------------------
// Address: 0x0040CEF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVGUI_Src_Editor_Dialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVGUI_Src_Editor_Dialog::GetKBMap(CVGUI_Src_Editor_Dialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVGUI_Src_Editor_Dialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVGUI_Src_Editor_Dialog::GetKBMap'::`2'::s_pMap;
  `CVGUI_Src_Editor_Dialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVGUI_Src_Editor_Dialog");
  `CVGUI_Src_Editor_Dialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040CF20
// Name: public: virtual void CVGUI_Src_Editor_Dialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGUI_Src_Editor_Dialog::OnCommand(CVGUI_Src_Editor_Dialog *this, const char *command)
{
  CManaged_Panel_Data *v3; // ecx
  CManaged_Panel_Data *m_pCurrentManagedPanel; // edi

  vgui::Frame::OnCommand(this, command);
  if ( _V_stricmp(s1: command, s2: "SaveRes") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "ReloadRes") == 0 )
    {
      m_pCurrentManagedPanel = this->m_pManagedChildList->m_pCurrentManagedPanel;
      if ( m_pCurrentManagedPanel != nullptr )
      {
        CManaged_Panel_Data::GetResFileKeys(this: m_pCurrentManagedPanel, bForceReload: true);
        CVGUI_Src_Editor_Dialog::SetCurrentManagedData(this, pData: m_pCurrentManagedPanel);
      }
    }
  }
  else
  {
    v3 = this->m_pManagedChildList->m_pCurrentManagedPanel;
    if ( v3 != nullptr )
      CManaged_Panel_Data::SaveResFileKeys(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CFF0
// Name: public: void CVGUI_Src_Editor_Dialog::ShowChildList(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGUI_Src_Editor_Dialog::ShowChildList(CVGUI_Src_Editor_Dialog *this, int nManagedPanel)
{
  if ( nManagedPanel >= 0 && nManagedPanel < this->m_pEditor->m_ManagedPanels.m_Size )
  {
    this->m_pChildEditor->SetKeys(this: this->m_pChildEditor, a2: nullptr);
    CVGUI_Src_Editor_Dialog::SetCurrentManagedData(
      this,
      pData: this->m_pEditor->m_ManagedPanels.m_Memory.m_pMemory[nManagedPanel]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D040
// Name: public: void CVGUI_Src_Editor_Dialog::StartEditingChild(class CManaged_Panel_Data __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGUI_Src_Editor_Dialog::StartEditingChild(
        CVGUI_Src_Editor_Dialog *this,
        CManaged_Panel_Data *pManagedPanel,
        int nChild)
{
  KeyValues *ResFileKeys; // eax
  KeyValues *Key; // eax
  char *m_szName; // [esp-8h] [ebp-14h]

  m_szName = pManagedPanel->m_Children.m_Memory.m_pMemory[nChild]->m_szName;
  ResFileKeys = CManaged_Panel_Data::GetResFileKeys(this: pManagedPanel, bForceReload: false);
  Key = KeyValues::FindKey(this: ResFileKeys, keyName: m_szName, bCreate: false);
  if ( Key != nullptr )
  {
    CVGUI_Src_Editor_Dialog::StartEditingChildKeys(this, pChildResKeys: Key);
  }
  else
  {
    _Warning(
      a1: "Unable to find res file section for child %s\n",
      pManagedPanel->m_Children.m_Memory.m_pMemory[nChild]->m_szName);
    this->m_pChildEditor->SetKeys(this: this->m_pChildEditor, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D0C0
// Name: public: static void CVGUI_Src_Editor_Dialog::PanelMessageFunc_OnCommandSubmitted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVGUI_Src_Editor_Dialog::PanelMessageFunc_OnCommandSubmitted::InitVar(int a1@<ebp>)
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
  if ( !`CVGUI_Src_Editor_Dialog::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded )
  {
    `CVGUI_Src_Editor_Dialog::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CVGUI_Src_Editor_Dialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CVGUI_Src_Editor_Dialog");
    v2 = (__int128)_mm_load_si128(&v5);
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_CONSTCHARPTR;
    memset(&v4.secondParamType, 0, 20);
    m_Size = v1->entries.m_Size;
    v4.name = "CommandSubmitted";
    v4.func = v2;
    v4.firstParamName = "command";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040D160
// Name: public: static void CVGUI_Src_Editor_Dialog::PanelMessageFunc_KeyValuesChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVGUI_Src_Editor_Dialog::PanelMessageFunc_KeyValuesChanged::InitVar(int a1@<ebp>)
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
  if ( !`CVGUI_Src_Editor_Dialog::PanelMessageFunc_KeyValuesChanged::InitVar'::`2'::bAdded )
  {
    `CVGUI_Src_Editor_Dialog::PanelMessageFunc_KeyValuesChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CVGUI_Src_Editor_Dialog");
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
// Address: 0x0040D200
// Name: public: CVGUI_Src_Editor_Dialog::CVGUI_Src_Editor_Dialog(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVGUI_Src_Editor_Dialog *__thiscall CVGUI_Src_Editor_Dialog::CVGUI_Src_Editor_Dialog(
        CVGUI_Src_Editor_Dialog *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CVGUI_Src_Editor *v7; // eax
  CVGUI_Src_Editor *v8; // eax
  vgui::MessageBox *v9; // eax
  vgui::MessageBox *v10; // eax
  CManaged_Panel_List *v12; // eax
  CManaged_Panel_List *v13; // eax
  CManaged_Child_List *v14; // eax
  CManaged_Child_List *v15; // eax
  CRes_Child_List *v16; // eax
  CRes_Child_List *v17; // eax
  CKV_Editor *v18; // eax
  CKV_Editor *v19; // eax
  vgui::Label *v20; // eax
  vgui::Label *v21; // eax
  vgui::Button *v22; // eax
  vgui::Button *v23; // eax
  vgui::Button *v24; // eax
  vgui::Button *v25; // eax
  CRes_Visualizer *v26; // eax
  CRes_Visualizer *v27; // eax
  vgui::CConsolePanel *v28; // eax
  vgui::CConsolePanel *v29; // eax
  int v30; // ecx
  vgui::AnimationController *AnimationController; // eax
  float currentTime; // [esp+8h] [ebp-Ch]
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CVGUI_Src_Editor_Dialog_vtbl *)&CVGUI_Src_Editor_Dialog::`vftable';
  if ( `CVGUI_Src_Editor_Dialog::ChainToMap'::`2'::chained == 0 )
  {
    `CVGUI_Src_Editor_Dialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CVGUI_Src_Editor_Dialog");
    v4->pfnClassName = CVGUI_Src_Editor_Dialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CVGUI_Src_Editor_Dialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVGUI_Src_Editor_Dialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CVGUI_Src_Editor_Dialog");
    v5->pfnClassName = CVGUI_Src_Editor_Dialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CVGUI_Src_Editor_Dialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVGUI_Src_Editor_Dialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CVGUI_Src_Editor_Dialog");
    v6->pfnClassName = CVGUI_Src_Editor_Dialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CVGUI_Src_Editor_Dialog::PanelMessageFunc_OnCommandSubmitted::InitVar(a1: (int)&savedregs);
  CVGUI_Src_Editor_Dialog::PanelMessageFunc_KeyValuesChanged::InitVar(a1: (int)&savedregs);
  this->m_bFirstPerformLayout = false;
  v7 = (CVGUI_Src_Editor *)operator new(nSize: 0x120u);
  if ( v7 != nullptr )
    v8 = CVGUI_Src_Editor::CVGUI_Src_Editor(this: v7);
  else
    v8 = nullptr;
  this->m_pEditor = v8;
  if ( CVGUI_Src_Editor::Init(this: v8) )
  {
    v12 = (CManaged_Panel_List *)operator new(nSize: 0x190u);
    if ( v12 != nullptr )
      v13 = CManaged_Panel_List::CManaged_Panel_List(this: v12, parent: this, name: "ManagedPanelList");
    else
      v13 = nullptr;
    this->m_pManagedPanelList = v13;
    v14 = (CManaged_Child_List *)operator new(nSize: 0x194u);
    if ( v14 != nullptr )
      v15 = CManaged_Child_List::CManaged_Child_List(this: v14, parent: this, name: "ManagedChildList");
    else
      v15 = nullptr;
    this->m_pManagedChildList = v15;
    v16 = (CRes_Child_List *)operator new(nSize: 0x190u);
    if ( v16 != nullptr )
      v17 = CRes_Child_List::CRes_Child_List(this: v16, parent: this, name: "ResChildList");
    else
      v17 = nullptr;
    this->m_pResChildList = v17;
    v18 = (CKV_Editor *)operator new(nSize: 0x2ECu);
    if ( v18 != nullptr )
      v19 = CKV_Editor::CKV_Editor(this: v18, parent: this, name: "ChildEditor");
    else
      v19 = nullptr;
    this->m_pChildEditor = v19;
    v19->m_bRequireFileSpec = false;
    this->m_pChildEditor->m_bShowSiblings = false;
    this->m_pChildEditor->AddActionSignalTarget_2(this: this->m_pChildEditor, a2: this);
    this->m_pChildResKeys = nullptr;
    v20 = (vgui::Label *)operator new(nSize: 0x1A4u);
    if ( v20 != nullptr )
      v21 = vgui::Label::Label(this: v20, parent: this, panelName: "CurrentResLabel", text: &defaultValue);
    else
      v21 = nullptr;
    this->m_pCurrentResFileLabel = v21;
    v22 = (vgui::Button *)operator new(nSize: 0x1F4u);
    if ( v22 != nullptr )
      v23 = vgui::Button::Button(
              this: v22,
              parent: this,
              panelName: "SaveResButton",
              text: "Save",
              pActionSignalTarget: this,
              pCmd: "SaveRes");
    else
      v23 = nullptr;
    this->m_pSaveResButton = v23;
    v24 = (vgui::Button *)operator new(nSize: 0x1F4u);
    if ( v24 != nullptr )
      v25 = vgui::Button::Button(
              this: v24,
              parent: this,
              panelName: "ReloadResButton",
              text: "Reload",
              pActionSignalTarget: this,
              pCmd: "ReloadRes");
    else
      v25 = nullptr;
    this->m_pReloadResButton = v25;
    v26 = (CRes_Visualizer *)operator new(nSize: 0x1CCu);
    if ( v26 != nullptr )
      v27 = CRes_Visualizer::CRes_Visualizer(this: v26, parent: this, name: "ResVisualizer");
    else
      v27 = nullptr;
    this->m_pResVis = v27;
    v28 = (vgui::CConsolePanel *)operator new(nSize: 0x3D0u);
    if ( v28 != nullptr )
      v29 = vgui::CConsolePanel::CConsolePanel(this: v28, pParent: this, pName: "ConsolePanel", bStatusVersion: false);
    else
      v29 = nullptr;
    this->m_pConsole = v29;
    v29->AddActionSignalTarget_2(this: v29, a2: this);
    currentTime = _Plat_FloatTime(a1: v30);
    AnimationController = vgui::GetAnimationController();
    vgui::AnimationController::UpdateAnimations(this: AnimationController, currentTime);
    g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
    return this;
  }
  else
  {
    _Warning(a1: this->m_pEditor->m_szInitError);
    v9 = (vgui::MessageBox *)operator new(nSize: 0x234u);
    if ( v9 != nullptr )
      v10 = vgui::MessageBox::MessageBox(
              this: v9,
              title: "VGUI Src Editor - Initialization Error",
              text: this->m_pEditor->m_szInitError,
              parent: nullptr);
    else
      v10 = nullptr;
    v10->DoModal_2(this: v10, a2: nullptr);
    vgui::Panel::MarkForDeletion(this);
    return this;
  }
}
