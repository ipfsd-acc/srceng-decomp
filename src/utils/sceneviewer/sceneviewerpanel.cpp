// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/sceneviewer/sceneviewerpanel.cpp
// Functions: 233
// ============================================================

#include "utils\sceneviewer\sceneviewerpanel.h"

//------------------------------------------------------------------------------
// Address: 0x00401410
// Name: public: class CDmeDag __near * CDmElement::GetValueElement<class CDmeDag>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeDag *__thiscall CDmElement::GetValueElement<CDmeDag>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeDag::m_classType.u) != 0 )
  {
    return (CDmeDag *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402BB0
// Name: public: Vector::Vector(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall Vector::Vector(vgui::Panel *this)
{
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402BC0
// Name: char __near * MemAlloc_StrDup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MemAlloc_StrDup(const char *pString)
{
  char *result; // eax

  if ( pString == nullptr )
    return nullptr;
  result = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pString) + 1);
  if ( result == nullptr )
    return nullptr;
  strcpy(result, pString);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402C10
// Name: bool StringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl StringLessThan(const char **lhs, const char **rhs)
{
  int v3; // kr00_4

  if ( *lhs == nullptr )
    return false;
  if ( *rhs == nullptr )
    return true;
  v3 = strcmp(*lhs, *rhs);
  return v3 != 0 && -(v3 < 0) - ((v3 < 0) - 1) < 0;
}

//------------------------------------------------------------------------------
// Address: 0x00402C70
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  if ( *lhs == nullptr )
    return false;
  if ( *rhs != nullptr )
    return _V_stricmp(s1: *lhs, s2: *rhs) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00402CA0
// Name: public: void CChangeUndoScopeGuard::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeUndoScopeGuard::Release(CChangeUndoScopeGuard *this)
{
  bool v2; // zf

  if ( !this->m_bReleased )
  {
    (*(void (__stdcall **)(bool))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(a1: this->m_bOldValue);
    v2 = !this->m_bNotify;
    this->m_bReleased = true;
    if ( !v2 )
    {
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 464))(
        a1: g_pDataModel.u,
        a2: 0);
      this->m_bNotify = false;
    }
    if ( this->m_pNotify != nullptr )
    {
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, IDmNotify *))(*(_DWORD *)g_pDataModel.u.m_Id + 448))(
        a1: g_pDataModel.u,
        a2: this->m_pNotify);
      this->m_pNotify = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402D00
// Name: public: static char const __near * CSceneViewerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSceneViewerPanel::GetPanelClassName()
{
  return "CSceneViewerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00402D10
// Name: public: static char const __near * CSceneViewerMenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSceneViewerMenuButton::GetPanelClassName()
{
  return "CSceneViewerMenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x00402D20
// Name: public: static char const __near * CSceneViewerEditMenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSceneViewerEditMenuButton::GetPanelClassName()
{
  return "CSceneViewerEditMenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x00402D30
// Name: public: static char const __near * CSceneViewerMenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSceneViewerMenuBar::GetPanelClassName()
{
  return "CSceneViewerMenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x00402D40
// Name: public: virtual void CSceneViewerMenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerMenuBar::PerformLayout(CSceneViewerMenuBar *this)
{
  int v2; // edi
  int v3; // [esp+8h] [ebp-18h] BYREF
  int bary; // [esp+Ch] [ebp-14h] BYREF
  int cw; // [esp+10h] [ebp-10h] BYREF
  int h; // [esp+14h] [ebp-Ch] BYREF
  int barx; // [esp+18h] [ebp-8h] BYREF
  int w; // [esp+1Ch] [ebp-4h] BYREF

  vgui::MenuBar::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  this->GetContentSize(this, a2: &barx, a3: &bary);
  v2 = (int)(float)((float)(w + barx) * 0.5);
  this->m_pFileName->GetContentSize(this: this->m_pFileName, a2: &cw, a3: &v3);
  vgui::Panel::SetBounds(
    this: this->m_pFileName,
    x: (int)(float)((float)v2 - (float)((float)cw * 0.5)),
    y: 0,
    wide: cw,
    tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x00402DE0
// Name: public: virtual void CSceneViewerPanel::OnCommandSubmitted(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSceneViewerPanel::OnCommandSubmitted(
        CSceneViewerPanel *this@<ecx>,
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
  v3 = defaultValue;
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
        v8 = defaultValue;
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
            v9 = defaultValue;
        }
        v10 = defaultValue;
        if ( args.m_nArgc > 0 )
          v10 = args.m_ppArgv[0];
        ConMsg(a1: "%s = %s\n", v10, v9);
      }
    }
    else if ( (*(unsigned __int8 (__stdcall **)(int))(*v5 + 8))(a1: 4096) != 0 )
    {
      v11 = defaultValue;
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
        v14 = (char *)defaultValue;
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
// Address: 0x00402FC0
// Name: public: virtual unsigned int CSceneViewerPanel::GetCurrentKeyFocus(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CSceneViewerPanel::GetCurrentKeyFocus(CSceneViewerPanel *this)
{
  return this->m_pClipViewPanel->GetVPanel(this: this->m_pClipViewPanel);
}

//------------------------------------------------------------------------------
// Address: 0x00402FD0
// Name: protected: virtual void CSceneViewerPanel::SetupFileOpenDialog(class vgui::FileOpenDialog __near *,bool,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::SetupFileOpenDialog(
        CSceneViewerPanel *this,
        vgui::FileOpenDialog *pDialog,
        bool bOpenFile,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  int *p_m_nGrowSize; // esi
  const char *v6; // eax
  const char *Name; // eax
  void (__thiscall *SetTitle_2)(vgui::Frame *, const char *, bool); // eax
  char pStartingDir[260]; // [esp+8h] [ebp-104h] BYREF

  p_m_nGrowSize = &this->m_sNavLeftName.m_Storage.m_Memory.m_nGrowSize;
  if ( CUtlString::Length(this: (CUtlString *)&this->m_sNavLeftName.m_Storage.m_Memory.m_nGrowSize) == 0 )
  {
    if ( !g_pVGuiSystem->GetRegistryString(
            this: g_pVGuiSystem,
            a2: "HKEY_CURRENT_USER\\Software\\Valve\\sceneviewer\\dmxfiles\\opendir",
            a3: pStartingDir,
            a4: 260) )
      _getcwd(pnbuf: pStartingDir, maxlen: 260);
    CUtlString::operator=(this: (CUtlString *)p_m_nGrowSize, src: pStartingDir);
  }
  v6 = CUtlString::Get(this: (CUtlString *)p_m_nGrowSize);
  vgui::FileOpenDialog::SetStartDirectoryContext(
    this: pDialog,
    pStartDirContext: "sceneviewer_browser",
    pDefaultDir: v6);
  if ( bOpenFile || (Name = KeyValues::GetName(this: pContextKeyValues), _V_strcmp(s1: Name, s2: "SaveCurrentAs") != 0) )
  {
    vgui::FileOpenDialog::AddFilter(
      this: pDialog,
      filter: "*.obj",
      filterName: "OBJ File (*.obj)",
      bActive: false,
      pFilterInfo: "obj");
    vgui::FileOpenDialog::AddFilter(
      this: pDialog,
      filter: "*.dmx",
      filterName: "DMX File (*.dmx)",
      bActive: bOpenFile,
      pFilterInfo: "model");
    vgui::FileOpenDialog::AddFilter(
      this: pDialog,
      filter: "*.*",
      filterName: "All Files (*.*)",
      bActive: !bOpenFile,
      pFilterInfo: "model");
    SetTitle_2 = pDialog->SetTitle_2;
    if ( bOpenFile )
      SetTitle_2(this: pDialog, a2: "Open DMX/OBJ File", a3: true);
    else
      SetTitle_2(this: pDialog, a2: "Save DMX/OBJ File As", a3: true);
  }
  else
  {
    vgui::FileOpenDialog::AddFilter(
      this: pDialog,
      filter: "*.obj",
      filterName: "OBJ File (*.obj)",
      bActive: false,
      pFilterInfo: "obj");
    vgui::FileOpenDialog::AddFilter(
      this: pDialog,
      filter: "*.*",
      filterName: "All Files (*.*)",
      bActive: true,
      pFilterInfo: "obj");
    pDialog->SetTitle_2(this: pDialog, a2: "Save Current State As OBJ File", a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403130
// Name: private: void CSceneViewerPanel::SendFrameToDagRenderPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::SendFrameToDagRenderPanel(CSceneViewerPanel *this, vgui::Panel *pPanel)
{
  int v2; // edi
  vgui::Panel *Child; // esi
  void *v4; // ebx
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  int nChildren; // [esp+10h] [ebp-8h]

  v2 = 0;
  nChildren = vgui::Panel::GetChildCount(this: pPanel);
  if ( nChildren > 0 )
  {
    while ( 1 )
    {
      Child = vgui::Panel::GetChild(this: pPanel, index: v2);
      v4 = __RTDynamicCast(
             inptr: Child,
             VfDelta: 0,
             SrcType: &vgui::Panel `RTTI Type Descriptor',
             TargetType: &CDmeDagRenderPanel `RTTI Type Descriptor',
             isReference: 0);
      if ( v4 != nullptr )
        break;
      CSceneViewerPanel::SendFrameToDagRenderPanel(this, pPanel: Child);
      if ( ++v2 >= nChildren )
        return;
    }
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
      v6 = KeyValues::KeyValues(this: v5, setName: "Frame");
    else
      v6 = nullptr;
    ((void (__thiscall *)(vgui::Panel *, void *, KeyValues *, _DWORD))pPanel->PostMessage)(
      a1: pPanel,
      a2: v4,
      a3: v6,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004031D0
// Name: public: virtual void CSceneViewerPanel::OnOpen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnOpen(CSceneViewerPanel *this)
{
  CDmElement *m_pRoot; // eax
  int v3; // esi
  const char *v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  m_pRoot = this->m_pRoot;
  v3 = 0;
  v4 = nullptr;
  if ( m_pRoot != nullptr )
  {
    v3 = 1;
    v4 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 364))(
                         a1: g_pDataModel.u,
                         a2: m_pRoot->m_fileId);
  }
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "FileOpen");
  else
    v6 = nullptr;
  vgui::FileOpenStateMachine::OpenFile(
    this: this->m_pFileOpenStateMachine,
    pOpenFileType: "model",
    pContextKeyValues: v6,
    pSaveFileName: v4,
    pSaveFileType: nullptr,
    nFlags: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00403240
// Name: public: virtual void CSceneViewerPanel::OnSave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnSave(CSceneViewerPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  const char *v4; // eax

  if ( this->m_pRoot != nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "FileSave");
    else
      v3 = nullptr;
    v4 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 364))(
                         a1: g_pDataModel.u,
                         a2: this->m_pRoot->m_fileId);
    vgui::FileOpenStateMachine::SaveFile(
      this: this->m_pFileOpenStateMachine,
      pContextKeyValues: v3,
      pFileName: v4,
      pFileType: "model",
      nFlags: 1);
  }
  else
  {
    this->OnSaveAs(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004032B0
// Name: public: virtual void CSceneViewerPanel::OnSaveAs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnSaveAs(CSceneViewerPanel *this)
{
  vgui::MessageBox *v2; // eax
  vgui::MessageBox *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  if ( this->m_pRoot != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "FileSave");
    else
      v5 = nullptr;
    vgui::FileOpenStateMachine::SaveFile(
      this: this->m_pFileOpenStateMachine,
      pContextKeyValues: v5,
      pFileName: nullptr,
      pFileType: "model",
      nFlags: 1);
  }
  else
  {
    v2 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v2 != nullptr )
    {
      v3 = vgui::MessageBox::MessageBox(
             this: v2,
             title: "#SceneViewer_NothingToSave",
             text: "#SceneViewer_NothingToSave",
             parent: this);
      v3->DoModal_2(this: v3, a2: nullptr);
    }
    else
    {
      (*(void (__thiscall **)(_DWORD, _DWORD))(MEMORY[0] + 1116))(a1: 0, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403340
// Name: public: virtual void CSceneViewerPanel::OnSaveCurrentAs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnSaveCurrentAs(CSceneViewerPanel *this)
{
  vgui::MessageBox *v2; // eax
  vgui::MessageBox *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  if ( this->m_pRoot != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "SaveCurrentAs");
    else
      v5 = nullptr;
    vgui::FileOpenStateMachine::SaveFile(
      this: this->m_pFileOpenStateMachine,
      pContextKeyValues: v5,
      pFileName: nullptr,
      pFileType: "model",
      nFlags: 1);
  }
  else
  {
    v2 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
    if ( v2 != nullptr )
    {
      v3 = vgui::MessageBox::MessageBox(
             this: v2,
             title: "#SceneViewer_NothingToSave",
             text: "#SceneViewer_NothingToSave",
             parent: this);
      v3->DoModal_2(this: v3, a2: nullptr);
    }
    else
    {
      (*(void (__thiscall **)(_DWORD, _DWORD))(MEMORY[0] + 1116))(a1: 0, a2: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004033D0
// Name: public: virtual void CSceneViewerPanel::OnExit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnExit(CSceneViewerPanel *this)
{
  g_pVGui->Stop(this: g_pVGui);
}

//------------------------------------------------------------------------------
// Address: 0x004033E0
// Name: public: virtual void CSceneViewerPanel::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnSizeChanged(CSceneViewerPanel *this, int __formal, int __formala)
{
  if ( vgui::Panel::GetAutoResize(this: this->m_pClipViewPanel) != 0 )
    this->OnPinAndZoomIt(this);
}

//------------------------------------------------------------------------------
// Address: 0x00403410
// Name: public: virtual void CSceneViewerPanel::OnPinAndZoomIt(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnPinAndZoomIt(CSceneViewerPanel *this)
{
  int mw; // [esp+4h] [ebp-18h] BYREF
  int mx; // [esp+8h] [ebp-14h] BYREF
  int w; // [esp+Ch] [ebp-10h] BYREF
  int h; // [esp+10h] [ebp-Ch] BYREF
  int my; // [esp+14h] [ebp-8h] BYREF
  int mh; // [esp+18h] [ebp-4h] BYREF

  vgui::Panel::GetPos(this: this->m_pMenuBar, x: &mx, y: &my);
  vgui::Panel::GetSize(this: this->m_pMenuBar, wide: &mw, tall: &mh);
  vgui::Panel::SetPinCorner(this: this->m_pClipViewPanel, pinCorner: PIN_TOPLEFT, nOffsetX: 0, nOffsetY: mh + my + 2);
  vgui::Panel::SetAutoResize(
    this: this->m_pClipViewPanel,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: mh + my + 2,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  vgui::Panel::SetBounds(this: this->m_pClipViewPanel, x: 0, y: mh + my + 2, wide: w, tall: h - mh - my - 2);
}

//------------------------------------------------------------------------------
// Address: 0x004034C0
// Name: public: virtual void CSceneViewerPanel::OnShow3DView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnShow3DView(CSceneViewerPanel *this)
{
  if ( this->m_pClipViewPanel != nullptr )
  {
    this->m_pClipViewPanel->SetVisible(this: this->m_pClipViewPanel, a2: true);
    this->m_pClipViewPanel->MoveToFront(this: this->m_pClipViewPanel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403500
// Name: public: virtual void CSceneViewerPanel::OnHide3DView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnHide3DView(CSceneViewerPanel *this)
{
  if ( this->m_pClipViewPanel != nullptr )
    this->m_pClipViewPanel->SetVisible(this: this->m_pClipViewPanel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00403520
// Name: public: virtual void CSceneViewerPanel::OnHideConsole(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnHideConsole(CSceneViewerPanel *this)
{
  if ( this->m_pConsole != nullptr )
    this->m_pConsole->SetVisible(this: this->m_pConsole, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x00403540
// Name: public: virtual void CSceneViewerPanel::OnCombinationOperatorChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnCombinationOperatorChanged(CSceneViewerPanel *this)
{
  CClipViewPanel *m_pClipViewPanel; // ecx

  m_pClipViewPanel = this->m_pClipViewPanel;
  if ( m_pClipViewPanel != nullptr )
    CClipViewPanel::RefreshCombinationOperator(this: m_pClipViewPanel);
}

//------------------------------------------------------------------------------
// Address: 0x00403550
// Name: public: virtual void CSceneViewerPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSceneViewerPanel::PerformLayout(CSceneViewerPanel *this@<ecx>, int a2@<edi>)
{
  unsigned int (__thiscall *GetVPanel)(vgui::IClientPanel *); // eax
  int v4; // eax
  vgui::IPanel_vtbl *v5; // edx
  int v6; // [esp+0h] [ebp-14h]
  int iTemp; // [esp+4h] [ebp-10h] BYREF
  int iMenuHeight; // [esp+8h] [ebp-Ch] BYREF
  int iHeight; // [esp+Ch] [ebp-8h] BYREF
  int iWidth; // [esp+10h] [ebp-4h] BYREF

  if ( this->GetParent(this) != nullptr )
  {
    GetVPanel = this->GetParent(this)->GetVPanel;
    v4 = ((int (__stdcall *)(int, int, int))GetVPanel)(a1: v6, a2: iTemp, a3: iMenuHeight);
  }
  else
  {
    v4 = ((int (__stdcall *)(int, int, int))g_pVGuiSurface->GetEmbeddedPanel)(a1: v6, a2: iTemp, a3: iMenuHeight);
  }
  v5 = g_pVGuiPanel->__vftable;
  iMenuHeight = a2;
  v5->GetSize(this: g_pVGuiPanel, a2: v4, a3: &iWidth, a4: &iHeight);
  vgui::Panel::SetSize(this, wide: iWidth, tall: iHeight);
  vgui::Panel::SetSize(this: this->m_pMenuBar, wide: iWidth, tall: 28);
  vgui::Panel::GetSize(this: this->m_pMenuBar, wide: &iTemp, tall: &iMenuHeight);
  vgui::Panel::SetPos(this: this->m_pClientArea, x: 0, y: iMenuHeight);
  vgui::Panel::SetSize(this: this->m_pClientArea, wide: iWidth, tall: iHeight - iMenuHeight);
  if ( !this->m_bConsolePositioned )
  {
    vgui::Panel::SetSize(this: this->m_pConsole, wide: iWidth / 2, tall: iHeight / 2);
    this->m_pConsole->MoveToCenterOfScreen(this: this->m_pConsole);
    this->m_bConsolePositioned = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403650
// Name: public: virtual void CConCommandMemberAccessor<class CSceneViewerPanel>::CommandCallback(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConCommandMemberAccessor<CSceneViewerPanel>::CommandCallback(
        CConCommandMemberAccessor<CSceneViewerPanel> *this,
        const CCommand *command)
{
  ((void (__thiscall *)(const char *, const CCommand *))this->m_pszName)(
    a1: &this->m_pszHelpString[*(_DWORD *)&this->m_bRegistered],
    a2: command);
}

//------------------------------------------------------------------------------
// Address: 0x00403670
// Name: public: virtual int CConCommandMemberAccessor<class CSceneViewerPanel>::CommandCompletionCallback(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CConCommandMemberAccessor<CSceneViewerPanel>::CommandCompletionCallback(
        CConCommandMemberAccessor<CSceneViewerPanel> *this,
        const char *pPartial,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *commands)
{
  return ((int (__thiscall *)(char *, const char *, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *))this->m_fnCommandCallbackV1)(
           a1: (char *)this->m_pNext + (unsigned int)this->m_fnCompletionCallback,
           a2: pPartial,
           a3: commands);
}

//------------------------------------------------------------------------------
// Address: 0x004037E0
// Name: public: CDisableUndoScopeGuard::CDisableUndoScopeGuard(void)
// Source: json
//------------------------------------------------------------------------------
CDisableUndoScopeGuard *__thiscall CDisableUndoScopeGuard::CDisableUndoScopeGuard(CDisableUndoScopeGuard *this)
{
  *(_WORD *)&this->m_bReleased = 0;
  this->m_pNotify = nullptr;
  this->m_bOldValue = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236))(a1: g_pDataModel.u);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00403820
// Name: public: void CDmElement::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElement::SetName(CDmElement *this, const char *pName)
{
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 200))(
    a1: g_pDataModel.u,
    a2: &pName,
    a3: pName);
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: this->m_Name.m_pAttribute, value: (const CUtlSymbolLarge *)&pName);
}

//------------------------------------------------------------------------------
// Address: 0x00403850
// Name: public: CSceneViewerMenuBar::CSceneViewerMenuBar(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSceneViewerMenuBar *__thiscall CSceneViewerMenuBar::CSceneViewerMenuBar(
        CSceneViewerMenuBar *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Label *v7; // eax

  vgui::MenuBar::MenuBar(this, parent, panelName);
  this->__vftable = (CSceneViewerMenuBar_vtbl *)&CSceneViewerMenuBar::`vftable';
  if ( `CSceneViewerMenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `CSceneViewerMenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CSceneViewerMenuBar");
    v4->pfnClassName = CSceneViewerMenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::MenuBar");
  }
  if ( `CSceneViewerMenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSceneViewerMenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CSceneViewerMenuBar");
    v5->pfnClassName = CSceneViewerMenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::MenuBar");
  }
  if ( `CSceneViewerMenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSceneViewerMenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CSceneViewerMenuBar");
    v6->pfnClassName = CSceneViewerMenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::MenuBar");
  }
  v7 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v7 != nullptr )
    this->m_pFileName = vgui::Label::Label(this: v7, parent: this, panelName: "IFMFileName", text: defaultValue);
  else
    this->m_pFileName = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00403950
// Name: public: virtual struct vgui::PanelMessageMap __near * CSceneViewerMenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSceneViewerMenuBar::GetMessageMap(CSceneViewerMenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSceneViewerMenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSceneViewerMenuBar::GetMessageMap'::`2'::s_pMap;
  `CSceneViewerMenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSceneViewerMenuBar");
  `CSceneViewerMenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403980
// Name: public: virtual struct PanelAnimationMap __near * CSceneViewerMenuBar::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSceneViewerMenuBar::GetAnimMap(CSceneViewerMenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CSceneViewerMenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x00403990
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSceneViewerMenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSceneViewerMenuBar::GetKBMap(CSceneViewerMenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSceneViewerMenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSceneViewerMenuBar::GetKBMap'::`2'::s_pMap;
  `CSceneViewerMenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSceneViewerMenuBar");
  `CSceneViewerMenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004039F0
// Name: protected: void CSceneViewerPanel::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::Clear(CSceneViewerPanel *this)
{
  CClipViewPanel *m_pClipViewPanel; // ecx
  CDmeCombinationSystemEditorFrame *v3; // eax
  vgui::Panel *v4; // eax
  int (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>); // eax
  char v6; // al
  int v7; // edx
  CDisableUndoScopeGuard guard; // [esp+8h] [ebp-8h] BYREF

  m_pClipViewPanel = this->m_pClipViewPanel;
  if ( m_pClipViewPanel != nullptr )
  {
    CClipViewPanel::SetScene(this: m_pClipViewPanel, pDmRoot: nullptr);
    CClipViewPanel::SetAnimationList(this: this->m_pClipViewPanel, pAnimationList: nullptr);
    CClipViewPanel::SetVertexAnimationList(this: this->m_pClipViewPanel, pAnimationList: nullptr);
    CClipViewPanel::SetCombinationOperator(this: this->m_pClipViewPanel, pComboOp: nullptr);
  }
  if ( vgui::PHandle::Get(this: &this->m_pCombinationEditor) != nullptr )
  {
    v3 = (CDmeCombinationSystemEditorFrame *)vgui::PHandle::Get(this: &this->m_pCombinationEditor);
    CDmeCombinationSystemEditorFrame::SetCombinationOperator(this: v3, pComboSystem: nullptr);
  }
  if ( vgui::PHandle::Get(this: &this->m_pNerdEditor) != nullptr )
  {
    v4 = vgui::PHandle::Get(this: &this->m_pNerdEditor);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v4->__vftable[1].PostMessage)(a1: v4, a2: 0);
  }
  if ( this->m_pRoot != nullptr )
  {
    v5 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
    *(_WORD *)&guard.m_bReleased = 0;
    guard.m_pNotify = nullptr;
    v6 = ((int (__thiscall *)(_DWORD))v5)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
    v7 = *(_DWORD *)g_pDataModel.u.m_Id;
    guard.m_bOldValue = v6;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(v7 + 232))(a1: g_pDataModel.u, a2: 0);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id + 360))(
      a1: g_pDataModel.u,
      a2: this->m_pRoot->m_fileId);
    CChangeUndoScopeGuard::Release(this: &guard);
  }
  this->m_pRoot = nullptr;
  CUtlString::operator=(this: &this->m_filename, src: defaultValue);
}

//------------------------------------------------------------------------------
// Address: 0x00403AF0
// Name: public: virtual void CSceneViewerPanel::OnNew(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CSceneViewerPanel::OnNew(CSceneViewerPanel *this)
{
  CSceneViewerPanel::Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x00403B00
// Name: public: void CSceneViewerPanel::OnUndo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnUndo(CSceneViewerPanel *this)
{
  vgui::Panel *v2; // eax

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 280))(a1: g_pDataModel.u);
  if ( vgui::PHandle::Get(this: &this->m_hProperties) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hProperties);
    ((void (__thiscall *)(vgui::Panel *, int, _DWORD))v2->__vftable[1].GetModuleName)(a1: v2, a2: 2, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403B40
// Name: public: void CSceneViewerPanel::OnRedo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnRedo(CSceneViewerPanel *this)
{
  vgui::Panel *v2; // eax

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 284))(a1: g_pDataModel.u);
  if ( vgui::PHandle::Get(this: &this->m_hProperties) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hProperties);
    ((void (__thiscall *)(vgui::Panel *, int, _DWORD))v2->__vftable[1].GetModuleName)(a1: v2, a2: 2, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403B80
// Name: public: void CSceneViewerPanel::OnEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnEdit(CSceneViewerPanel *this)
{
  vgui::Panel *v2; // eax
  vgui::DHANDLE<CElementPropertiesTreeInternal> *p_m_hProperties; // ecx
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  CElementPropertiesTreeInternal *v6; // ebx
  CDmeDag *Scene; // eax
  CElementPropertiesTreeInternal *v8; // eax
  vgui::Panel *v9; // eax

  v2 = vgui::PHandle::Get(this: &this->m_hProperties);
  p_m_hProperties = &this->m_hProperties;
  if ( v2 != nullptr )
  {
    v4 = vgui::PHandle::Get(this: p_m_hProperties);
    v4->MoveToFront(this: v4);
  }
  else
  {
    if ( vgui::PHandle::Get(this: p_m_hProperties) != nullptr )
    {
      v5 = vgui::PHandle::Get(this: &this->m_hProperties);
      if ( v5 != nullptr )
        ((void (__thiscall *)(vgui::Panel *, int))v5->dtr_Panel)(a1: v5, a2: 1);
    }
    v6 = (CElementPropertiesTreeInternal *)MemAlloc_Alloc(nSize: 0x2BCu);
    if ( v6 != nullptr )
    {
      Scene = CClipViewPanel::GetScene(this: this->m_pClipViewPanel);
      v8 = CElementPropertiesTreeInternal::CElementPropertiesTreeInternal(
             this: v6,
             parent: this,
             pNotify: nullptr,
             pObject: Scene,
             autoApply: true,
             pDict: nullptr);
    }
    else
    {
      v8 = nullptr;
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hProperties, pPanel: v8);
    if ( vgui::PHandle::Get(this: &this->m_hProperties) != nullptr )
    {
      v9 = vgui::PHandle::Get(this: &this->m_hProperties);
      v9->__vftable[1].GetPanel(this: v9);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403C40
// Name: public: virtual void CSceneViewerPanel::OnShowComboEditor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnShowComboEditor(CSceneViewerPanel *this)
{
  vgui::DHANDLE<CDmeCombinationSystemEditorFrame> *p_m_pCombinationEditor; // esi
  vgui::Panel *v2; // eax
  vgui::Panel *v3; // eax

  p_m_pCombinationEditor = &this->m_pCombinationEditor;
  if ( vgui::PHandle::Get(this: &this->m_pCombinationEditor) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: p_m_pCombinationEditor);
    v2->SetVisible(this: v2, a2: true);
    v3 = vgui::PHandle::Get(this: p_m_pCombinationEditor);
    v3->MoveToFront(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403C80
// Name: public: virtual void CSceneViewerPanel::OnHideComboEditor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnHideComboEditor(CSceneViewerPanel *this)
{
  vgui::DHANDLE<CDmeCombinationSystemEditorFrame> *p_m_pCombinationEditor; // esi
  vgui::Panel *v2; // eax

  p_m_pCombinationEditor = &this->m_pCombinationEditor;
  if ( vgui::PHandle::Get(this: &this->m_pCombinationEditor) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: p_m_pCombinationEditor);
    v2->SetVisible(this: v2, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403CB0
// Name: public: virtual void CSceneViewerPanel::OnShowAssetBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnShowAssetBuilder(CSceneViewerPanel *this)
{
  vgui::DHANDLE<CAssetBuilderFrame> *p_m_pAssetBuilder; // esi
  vgui::Panel *v2; // eax
  vgui::Panel *v3; // eax

  p_m_pAssetBuilder = &this->m_pAssetBuilder;
  if ( vgui::PHandle::Get(this: &this->m_pAssetBuilder) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: p_m_pAssetBuilder);
    v2->SetVisible(this: v2, a2: true);
    v3 = vgui::PHandle::Get(this: p_m_pAssetBuilder);
    v3->MoveToFront(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403CF0
// Name: public: virtual void CSceneViewerPanel::OnHideAssetBuilder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnHideAssetBuilder(CSceneViewerPanel *this)
{
  vgui::DHANDLE<CAssetBuilderFrame> *p_m_pAssetBuilder; // esi
  vgui::Panel *v2; // eax

  p_m_pAssetBuilder = &this->m_pAssetBuilder;
  if ( vgui::PHandle::Get(this: &this->m_pAssetBuilder) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: p_m_pAssetBuilder);
    v2->SetVisible(this: v2, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403D20
// Name: public: virtual void CSceneViewerPanel::OnShowConsole(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnShowConsole(CSceneViewerPanel *this)
{
  if ( vgui::PHandle::Get(this: &this->m_pAssetBuilder) != nullptr )
  {
    this->m_pConsole->SetVisible(this: this->m_pConsole, a2: true);
    this->m_pConsole->MoveToFront(this: this->m_pConsole);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403D60
// Name: public: virtual void CSceneViewerPanel::OnShowNerdEditor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnShowNerdEditor(CSceneViewerPanel *this)
{
  vgui::DHANDLE<CElementPropertiesTreeInternal> *p_m_pNerdEditor; // esi
  vgui::Panel *v2; // eax
  vgui::Panel *v3; // eax

  p_m_pNerdEditor = &this->m_pNerdEditor;
  if ( vgui::PHandle::Get(this: &this->m_pNerdEditor) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: p_m_pNerdEditor);
    v2->SetVisible(this: v2, a2: true);
    v3 = vgui::PHandle::Get(this: p_m_pNerdEditor);
    v3->MoveToFront(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403DA0
// Name: public: virtual void CSceneViewerPanel::OnHideNerdEditor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnHideNerdEditor(CSceneViewerPanel *this)
{
  vgui::DHANDLE<CElementPropertiesTreeInternal> *p_m_pNerdEditor; // esi
  vgui::Panel *v2; // eax

  p_m_pNerdEditor = &this->m_pNerdEditor;
  if ( vgui::PHandle::Get(this: &this->m_pNerdEditor) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: p_m_pNerdEditor);
    v2->SetVisible(this: v2, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403DD0
// Name: public: CConCommandMemberAccessor<class CSceneViewerPanel>::CConCommandMemberAccessor<class CSceneViewerPanel>(class CSceneViewerPanel __near *,char const __near *,void (CSceneViewerPanel::*)(class CCommand const __near &),char const __near *,int,int (CSceneViewerPanel::*)(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &))
// Source: json
//------------------------------------------------------------------------------
CConCommandMemberAccessor<CSceneViewerPanel> *__thiscall CConCommandMemberAccessor<CSceneViewerPanel>::CConCommandMemberAccessor<CSceneViewerPanel>(
        CConCommandMemberAccessor<CSceneViewerPanel> *this,
        CSceneViewerPanel *pOwner,
        const char *pName,
        __int128 callback,
        const char *pHelpString,
        int flags,
        __int128 completionFunc)
{
  ICommandCompletionCallback *v8; // ecx
  ICommandCallback *v9; // eax
  __int64 v10; // xmm0_8

  if ( (_DWORD)completionFunc != 0 && this != nullptr )
    v8 = &this->ICommandCompletionCallback;
  else
    v8 = nullptr;
  if ( this != nullptr )
    v9 = &this->ICommandCallback;
  else
    v9 = nullptr;
  ConCommand::ConCommand(this, pName, pCallback: v9, pHelpString, flags, pCompletionCallback: v8);
  this->ICommandCallback::__vftable = (ICommandCallback_vtbl *)&ICommandCallback::`vftable';
  this->ICommandCompletionCallback::__vftable = (ICommandCompletionCallback_vtbl *)&ICommandCompletionCallback::`vftable';
  this->m_Func = callback;
  *(_QWORD *)&this->m_CompletionFunc = completionFunc;
  v10 = *((_QWORD *)&completionFunc + 1);
  this->ConCommand::ConCommandBase::__vftable = (CConCommandMemberAccessor<CSceneViewerPanel>_vtbl *)&CConCommandMemberAccessor<CSceneViewerPanel>::`vftable'{for `ConCommand'};
  this->ICommandCallback::__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CSceneViewerPanel>::`vftable'{for `ICommandCallback'};
  this->ICommandCompletionCallback::__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CSceneViewerPanel>::`vftable'{for `ICommandCompletionCallback'};
  this->m_pOwner = pOwner;
  *((_QWORD *)&this->m_CompletionFunc + 1) = v10;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00403EF0
// Name: public: virtual void CSceneViewerPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnCommand(CSceneViewerPanel *this, const char *cmd)
{
  if ( _V_stricmp(s1: cmd, s2: "OnEdit") != 0 )
  {
    if ( _V_stricmp(s1: cmd, s2: "OnUndo") != 0 )
    {
      if ( _V_stricmp(s1: cmd, s2: "OnRedo") != 0 )
        vgui::Panel::OnCommand(this, command: cmd);
      else
        CSceneViewerPanel::OnRedo(this);
    }
    else
    {
      CSceneViewerPanel::OnUndo(this);
    }
  }
  else
  {
    CSceneViewerPanel::OnEdit(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004042A0
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CUtlString *this)
{
  bool v2; // sf

  v2 = this->m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Storage.m_Memory.m_pMemory);
      this->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004042E0
// Name: public: virtual CSceneViewerPanel::~CSceneViewerPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::~CSceneViewerPanel(CSceneViewerPanel *this)
{
  CDmElement *m_pRoot; // eax

  m_pRoot = this->m_pRoot;
  this->vgui::Panel::vgui::IClientPanel::__vftable = (CSceneViewerPanel_vtbl *)&CSceneViewerPanel::`vftable'{for `vgui::Panel'};
  this->IDmNotify::__vftable = (IDmNotify_vtbl *)&CSceneViewerPanel::`vftable'{for `IDmNotify'};
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&CSceneViewerPanel::`vftable'{for `vgui::IFileOpenStateMachineClient'};
  if ( m_pRoot != nullptr )
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id + 408))(
      a1: g_pDataModel.u,
      a2: m_pRoot->m_fileId);
  this->m_filename.m_Storage.m_nActualLength = 0;
  if ( this->m_filename.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_filename.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_filename.m_Storage.m_Memory.m_pMemory);
      this->m_filename.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_filename.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_fileDirectory.m_Storage.m_nActualLength = 0;
  if ( this->m_fileDirectory.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_fileDirectory.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_fileDirectory.m_Storage.m_Memory.m_pMemory);
      this->m_fileDirectory.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_fileDirectory.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_CollapseJointSubtree_register.m_ConCommandAccessor.__vftable = (CConCommandMemberAccessor<CSceneViewerPanel>_vtbl *)&CConCommandMemberAccessor<CSceneViewerPanel>::`vftable'{for `ConCommand'};
  this->m_CollapseJointSubtree_register.m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CSceneViewerPanel>::`vftable'{for `ICommandCallback'};
  this->m_CollapseJointSubtree_register.m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CSceneViewerPanel>::`vftable'{for `ICommandCompletionCallback'};
  ConCommandBase::Shutdown(this: &this->m_CollapseJointSubtree_register.m_ConCommandAccessor);
  ConCommand::~ConCommand(this: &this->m_CollapseJointSubtree_register.m_ConCommandAccessor);
  this->m_ReplaceMaterial_register.m_ConCommandAccessor.__vftable = (CConCommandMemberAccessor<CSceneViewerPanel>_vtbl *)&CConCommandMemberAccessor<CSceneViewerPanel>::`vftable'{for `ConCommand'};
  this->m_ReplaceMaterial_register.m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CSceneViewerPanel>::`vftable'{for `ICommandCallback'};
  this->m_ReplaceMaterial_register.m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CSceneViewerPanel>::`vftable'{for `ICommandCompletionCallback'};
  ConCommandBase::Shutdown(this: &this->m_ReplaceMaterial_register.m_ConCommandAccessor);
  ConCommand::~ConCommand(this: &this->m_ReplaceMaterial_register.m_ConCommandAccessor);
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00404400
// Name: public: virtual struct vgui::PanelMessageMap __near * CSceneViewerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSceneViewerPanel::GetMessageMap(CSceneViewerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSceneViewerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSceneViewerPanel::GetMessageMap'::`2'::s_pMap;
  `CSceneViewerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
  `CSceneViewerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404430
// Name: public: virtual struct PanelAnimationMap __near * CSceneViewerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSceneViewerPanel::GetAnimMap(CSceneViewerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CSceneViewerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00404440
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSceneViewerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSceneViewerPanel::GetKBMap(CSceneViewerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSceneViewerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSceneViewerPanel::GetKBMap'::`2'::s_pMap;
  `CSceneViewerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSceneViewerPanel");
  `CSceneViewerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00404C10
// Name: public: class CDmeCombinationOperator __near * CDmElement::GetValueElement<class CDmeCombinationOperator>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeCombinationOperator *__thiscall CDmElement::GetValueElement<CDmeCombinationOperator>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeCombinationOperator::m_classType.u) != 0 )
  {
    return (CDmeCombinationOperator *)(v5 - 4);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404CA0
// Name: public: class CDmeAnimationList __near * CDmElement::GetValueElement<class CDmeAnimationList>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeAnimationList *__thiscall CDmElement::GetValueElement<CDmeAnimationList>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeAnimationList::m_classType.u) != 0 )
  {
    return (CDmeAnimationList *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404D30
// Name: public: class CDmeModel __near * CDmElement::GetValueElement<class CDmeModel>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeModel *__thiscall CDmElement::GetValueElement<CDmeModel>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeModel::m_classType.u) != 0 )
  {
    return (CDmeModel *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404E40
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnNew::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnNew::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnNew::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnNew::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{848,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "New";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404ED0
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnOpen::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnOpen::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnOpen::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnOpen::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Open";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404F60
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnSave::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnSave::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnSave::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnSave::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Save";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404FF0
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnSaveAs::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnSaveAs::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnSaveAs::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnSaveAs::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MenuBar::`vcall'{860,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "SaveAs";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405080
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnSaveCurrentAs::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnSaveCurrentAs::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnSaveCurrentAs::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnSaveCurrentAs::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{864,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "SaveCurrentAs";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405110
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnExit::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnExit::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnExit::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnExit::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenStateMachine::`vcall'{868,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Exit";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004051A0
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnLoadFile::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnLoadFile::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnLoadFile::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnLoadFile::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::RichText::`vcall'{872,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "LoadFile";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405240
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnPinAndZoomIt::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnPinAndZoomIt::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnPinAndZoomIt::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnPinAndZoomIt::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeElementPickerPanel::`vcall'{876,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PinAndZoomIt";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004052D0
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnShow3DView::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnShow3DView::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnShow3DView::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnShow3DView::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSheetSequencePickerPanel::`vcall'{880,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Show3DView";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405360
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnHide3DView::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnHide3DView::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnHide3DView::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnHide3DView::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "Hide3DView";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004053F0
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnShowComboEditor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnShowComboEditor::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnShowComboEditor::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnShowComboEditor::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseAttributeChoicePanel::`vcall'{888,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ShowComboEditor";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405480
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnHideComboEditor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnHideComboEditor::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnHideComboEditor::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnHideComboEditor::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSceneViewerPanel::`vcall'{892,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "HideComboEditor";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405510
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnShowAssetBuilder::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnShowAssetBuilder::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnShowAssetBuilder::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnShowAssetBuilder::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSceneViewerPanel::`vcall'{896,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ShowAssetBuilder";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004055A0
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnHideAssetBuilder::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnHideAssetBuilder::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnHideAssetBuilder::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnHideAssetBuilder::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSceneViewerPanel::`vcall'{900,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "HideAssetBuilder";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405630
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnShowConsole::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnShowConsole::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnShowConsole::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnShowConsole::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSceneViewerPanel::`vcall'{904,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ShowConsole";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004056C0
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnHideConsole::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnHideConsole::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnHideConsole::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnHideConsole::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSceneViewerPanel::`vcall'{908,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "HideConsole";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405750
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnShowNerdEditor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnShowNerdEditor::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnShowNerdEditor::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnShowNerdEditor::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{912,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ShowNerdEditor";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004057E0
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnHideNerdEditor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnHideNerdEditor::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnHideNerdEditor::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnHideNerdEditor::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ScrollBar::`vcall'{916,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "HideNerdEditor";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405870
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnCombinationOperatorChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnCombinationOperatorChanged::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnCombinationOperatorChanged::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnCombinationOperatorChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSceneViewerPanel::`vcall'{920,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CombinationOperatorChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405900
// Name: public: static void CSceneViewerPanel::PanelMessageFunc_OnCommandSubmitted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSceneViewerPanel::PanelMessageFunc_OnCommandSubmitted::InitVar(int a1@<ebp>)
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
  if ( !`CSceneViewerPanel::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded )
  {
    `CSceneViewerPanel::PanelMessageFunc_OnCommandSubmitted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSceneViewerPanel::`vcall'{924,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
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
// Address: 0x004059A0
// Name: protected: void CSceneViewerPanel::SetScene(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::SetScene(CSceneViewerPanel *this, bool bFrame)
{
  CDmeAnimationList *Value; // eax
  CDmeAnimationList *v4; // eax
  CDmeCombinationOperator *v5; // edi
  CDmeCombinationSystemEditorFrame *v6; // eax
  vgui::Panel *v7; // eax

  CClipViewPanel::SetScene(this: this->m_pClipViewPanel, pDmRoot: this->m_pRoot);
  Value = CDmElement::GetValueElement<CDmeAnimationList>(this: this->m_pRoot, pAttributeName: "animationList");
  CClipViewPanel::SetAnimationList(this: this->m_pClipViewPanel, pAnimationList: Value);
  v4 = CDmElement::GetValueElement<CDmeAnimationList>(this: this->m_pRoot, pAttributeName: "vertexAnimationList");
  CClipViewPanel::SetVertexAnimationList(this: this->m_pClipViewPanel, pAnimationList: v4);
  v5 = CDmElement::GetValueElement<CDmeCombinationOperator>(this: this->m_pRoot, pAttributeName: "combinationOperator");
  CClipViewPanel::SetCombinationOperator(this: this->m_pClipViewPanel, pComboOp: v5);
  v6 = (CDmeCombinationSystemEditorFrame *)vgui::PHandle::Get(this: &this->m_pCombinationEditor);
  CDmeCombinationSystemEditorFrame::SetCombinationOperator(this: v6, pComboSystem: v5);
  if ( vgui::PHandle::Get(this: &this->m_pNerdEditor) != nullptr )
  {
    v7 = vgui::PHandle::Get(this: &this->m_pNerdEditor);
    ((void (__thiscall *)(vgui::Panel *, CDmElement *))v7->__vftable[1].PostMessage)(a1: v7, a2: this->m_pRoot);
  }
  if ( v5 != nullptr )
    CDmeMaterialGroup::GetListAttr(this: v5);
  if ( bFrame )
    CSceneViewerPanel::SendFrameToDagRenderPanel(this, pPanel: this->m_pClipViewPanel);
}

//------------------------------------------------------------------------------
// Address: 0x00405A80
// Name: protected: void CSceneViewerPanel::ReplaceMaterial(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::ReplaceMaterial(CSceneViewerPanel *this, const CCommand *args)
{
  const char *v3; // esi
  CDmeModel *Value; // edi
  int (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>); // eax
  char v6; // al
  int v7; // edx
  CDisableUndoScopeGuard sg; // [esp+4h] [ebp-8h] BYREF
  const char *pNewMaterial; // [esp+14h] [ebp+8h]

  if ( args->m_nArgc == 3 )
  {
    v3 = args->m_ppArgv[1];
    pNewMaterial = args->m_ppArgv[2];
    if ( _V_stricmp(s1: v3, s2: "all") == 0 )
      v3 = nullptr;
    Value = CDmElement::GetValueElement<CDmeModel>(this: this->m_pRoot, pAttributeName: "model");
    if ( Value != nullptr )
    {
      v5 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
      *(_WORD *)&sg.m_bReleased = 0;
      sg.m_pNotify = nullptr;
      v6 = ((int (__thiscall *)(_DWORD))v5)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
      v7 = *(_DWORD *)g_pDataModel.u.m_Id;
      sg.m_bOldValue = v6;
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(v7 + 232))(a1: g_pDataModel.u, a2: 0);
      CDmeModel::ReplaceMaterial(this: Value, pOldMaterialName: v3, pNewMaterialName: pNewMaterial);
      CChangeUndoScopeGuard::Release(this: &sg);
    }
  }
  else
  {
    ConMsg(a1: "usage: replacematerial [<old material>|all] <new material>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405B30
// Name: protected: void CSceneViewerPanel::CollapseJointSubtree(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::CollapseJointSubtree(CSceneViewerPanel *this, const CCommand *args)
{
  const char *v2; // edi
  CDmeModel *Value; // esi
  unsigned __int8 (__thiscall *v4)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  CDisableUndoScopeGuard sg; // [esp+0h] [ebp-8h] BYREF

  if ( args->m_nArgc == 2 )
  {
    v2 = args->m_ppArgv[1];
    Value = CDmElement::GetValueElement<CDmeModel>(this: this->m_pRoot, pAttributeName: "model");
    if ( Value != nullptr )
    {
      v4 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
      sg.m_bNotify = false;
      sg.m_pNotify = nullptr;
      *(_WORD *)&sg.m_bOldValue = ((int (__thiscall *)(_DWORD))v4)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
        a1: g_pDataModel.u,
        a2: 0);
      CDmeModel::CollapseJoints(this: Value, pJointName: v2);
      CChangeUndoScopeGuard::Release(this: &sg);
    }
  }
  else
  {
    ConMsg(a1: "usage: collapsejointsubtree <joint name>\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405BC0
// Name: public: CSceneViewerPanel::CCommandMemberInitializer_ReplaceMaterial::CCommandMemberInitializer_ReplaceMaterial(void)
// Source: json
//------------------------------------------------------------------------------
CSceneViewerPanel::CCommandMemberInitializer_ReplaceMaterial *__thiscall CSceneViewerPanel::CCommandMemberInitializer_ReplaceMaterial::CCommandMemberInitializer_ReplaceMaterial(
        CSceneViewerPanel::CCommandMemberInitializer_ReplaceMaterial *this)
{
  __int128 v3; // [esp-10h] [ebp-34h]

  *(_QWORD *)&v3 = 0;
  *((_QWORD *)&v3 + 1) = 0xFFFFFFFF00000000uLL;
  CConCommandMemberAccessor<CSceneViewerPanel>::CConCommandMemberAccessor<CSceneViewerPanel>(
    this: &this->m_ConCommandAccessor,
    pOwner: nullptr,
    pName: "replacematerial",
    callback: (unsigned int)CSceneViewerPanel::ReplaceMaterial,
    pHelpString: "Replace all instances of a material",
    flags: 0,
    completionFunc: v3);
  this->m_ConCommandAccessor.m_pOwner = (CSceneViewerPanel *)((char *)this - 368);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00405C40
// Name: public: CSceneViewerPanel::CCommandMemberInitializer_CollapseJointSubtree::CCommandMemberInitializer_CollapseJointSubtree(void)
// Source: json
//------------------------------------------------------------------------------
CSceneViewerPanel::CCommandMemberInitializer_CollapseJointSubtree *__thiscall CSceneViewerPanel::CCommandMemberInitializer_CollapseJointSubtree::CCommandMemberInitializer_CollapseJointSubtree(
        CSceneViewerPanel::CCommandMemberInitializer_CollapseJointSubtree *this)
{
  __int128 v3; // [esp-10h] [ebp-34h]

  *(_QWORD *)&v3 = 0;
  *((_QWORD *)&v3 + 1) = 0xFFFFFFFF00000000uLL;
  CConCommandMemberAccessor<CSceneViewerPanel>::CConCommandMemberAccessor<CSceneViewerPanel>(
    this: &this->m_ConCommandAccessor,
    pOwner: nullptr,
    pName: "collapsejointsubtree",
    callback: (unsigned int)CSceneViewerPanel::CollapseJointSubtree,
    pHelpString: "Collapses all bones which are children of the specified bone",
    flags: 0,
    completionFunc: v3);
  this->m_ConCommandAccessor.m_pOwner = (CSceneViewerPanel *)((char *)this - 448);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00405CC0
// Name: public: virtual void CSceneViewerEditMenuButton::OnShowMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerEditMenuButton::OnShowMenu(CSceneViewerEditMenuButton *this, vgui::Menu *menu)
{
  int v3; // edi
  char v4; // al
  vgui::Menu *m_pMenu; // ecx
  const char *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  int v11; // edi
  char v12; // al
  vgui::Menu *v13; // ecx
  const char *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  int v19; // edi
  bool v20; // zf
  void (__thiscall *SetItemEnabled)(vgui::Menu *, int, bool); // eax
  int v22; // edi
  CDmeDag *Scene; // eax
  char sz[512]; // [esp+Ch] [ebp-208h] BYREF
  CUtlMap<char const *,int,unsigned short>::Node_t search; // [esp+20Ch] [ebp-8h] BYREF

  search.key = "undo";
  v3 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Items.m_Elements.m_Tree,
         &search);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 248))(a1: g_pDataModel.u);
  m_pMenu = this->CSceneViewerMenuButton::m_pMenu;
  if ( v4 != 0 )
  {
    m_pMenu->SetItemEnabled(this: m_pMenu, a2: v3, a3: true);
    v6 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 272))(a1: g_pDataModel.u);
    V_snprintf(pDest: sz, maxLen: 512, pFormat: "Undo '%s'", v6);
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "Command", firstKey: "command", firstValue: "OnUndo");
    else
      v8 = nullptr;
    this->CSceneViewerMenuButton::m_pMenu->UpdateMenuItem(
      this: this->CSceneViewerMenuButton::m_pMenu,
      a2: v3,
      a3: sz,
      a4: v8,
      a5: nullptr);
  }
  else
  {
    m_pMenu->SetItemEnabled(this: m_pMenu, a2: v3, a3: false);
    v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v9 != nullptr )
      v10 = KeyValues::KeyValues(this: v9, setName: "Command", firstKey: "command", firstValue: "OnUndo");
    else
      v10 = nullptr;
    this->CSceneViewerMenuButton::m_pMenu->UpdateMenuItem(
      this: this->CSceneViewerMenuButton::m_pMenu,
      a2: v3,
      a3: "Undo...",
      a4: v10,
      a5: nullptr);
  }
  search.key = "redo";
  v11 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
          this: &this->m_Items.m_Elements.m_Tree,
          &search);
  v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 252))(a1: g_pDataModel.u);
  v13 = this->CSceneViewerMenuButton::m_pMenu;
  if ( v12 != 0 )
  {
    v13->SetItemEnabled(this: v13, a2: v11, a3: true);
    v14 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 276))(a1: g_pDataModel.u);
    V_snprintf(pDest: sz, maxLen: 512, pFormat: "Redo '%s'", v14);
    v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v15 != nullptr )
      v16 = KeyValues::KeyValues(this: v15, setName: "Command", firstKey: "command", firstValue: "OnRedo");
    else
      v16 = nullptr;
    this->CSceneViewerMenuButton::m_pMenu->UpdateMenuItem(
      this: this->CSceneViewerMenuButton::m_pMenu,
      a2: v11,
      a3: sz,
      a4: v16,
      a5: nullptr);
  }
  else
  {
    v13->SetItemEnabled(this: v13, a2: v11, a3: false);
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v17 != nullptr )
      v18 = KeyValues::KeyValues(this: v17, setName: "Command", firstKey: "command", firstValue: "OnRedo");
    else
      v18 = nullptr;
    this->CSceneViewerMenuButton::m_pMenu->UpdateMenuItem(
      this: this->CSceneViewerMenuButton::m_pMenu,
      a2: v11,
      a3: "Redo...",
      a4: v18,
      a5: nullptr);
  }
  search.key = "describe";
  v19 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
          this: &this->m_Items.m_Elements.m_Tree,
          &search);
  v20 = (*(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 248))(a1: g_pDataModel.u) == 0;
  SetItemEnabled = this->CSceneViewerMenuButton::m_pMenu->SetItemEnabled;
  if ( v20 )
    ((void (__stdcall *)(int, _DWORD))SetItemEnabled)(a1: v19, a2: 0);
  else
    ((void (__stdcall *)(int, int))SetItemEnabled)(a1: v19, a2: 1);
  search.key = "properties";
  v22 = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
          this: &this->m_Items.m_Elements.m_Tree,
          &search);
  Scene = CClipViewPanel::GetScene(this: this->m_pUI->m_pClipViewPanel);
  this->CSceneViewerMenuButton::m_pMenu->SetItemEnabled(
    this: this->CSceneViewerMenuButton::m_pMenu,
    a2: v22,
    a3: Scene != nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00406040
// Name: public: CSceneViewerMenuButton::CSceneViewerMenuButton(class CSceneViewerPanel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSceneViewerMenuButton *__thiscall CSceneViewerMenuButton::CSceneViewerMenuButton(
        CSceneViewerMenuButton *this,
        CSceneViewerPanel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  vgui::Menu *v9; // eax

  vgui::MenuButton::MenuButton(this, parent, panelName, text);
  this->__vftable = (CSceneViewerMenuButton_vtbl *)&CSceneViewerMenuButton::`vftable';
  if ( `CSceneViewerMenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `CSceneViewerMenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CSceneViewerMenuButton");
    v5->pfnClassName = CSceneViewerMenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::MenuButton");
  }
  if ( `CSceneViewerMenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSceneViewerMenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CSceneViewerMenuButton");
    v6->pfnClassName = CSceneViewerMenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::MenuButton");
  }
  if ( `CSceneViewerMenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSceneViewerMenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CSceneViewerMenuButton");
    v7->pfnClassName = CSceneViewerMenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::MenuButton");
  }
  this->m_pActionTarget = parent;
  this->m_pUI = parent;
  this->m_Items.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_Items.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_Items.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_Items.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_Items.m_Elements.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_Items.m_Elements.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_Items.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_Items.m_Elements.m_Tree.m_pElements = m_pMemory;
  if ( this->m_Items.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_Items.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  v9 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v9 != nullptr )
    this->m_pMenu = vgui::Menu::Menu(this: v9, parent: this, panelName: "Menu");
  else
    this->m_pMenu = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004061A0
// Name: public: virtual void vgui::Button::OnHotkey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Button::OnHotkey(vgui::Button *this)
{
  this->DoClick(this);
}

//------------------------------------------------------------------------------
// Address: 0x004061B0
// Name: public: virtual struct vgui::PanelMessageMap __near * CSceneViewerMenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSceneViewerMenuButton::GetMessageMap(CSceneViewerMenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSceneViewerMenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSceneViewerMenuButton::GetMessageMap'::`2'::s_pMap;
  `CSceneViewerMenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSceneViewerMenuButton");
  `CSceneViewerMenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004061E0
// Name: public: virtual struct PanelAnimationMap __near * CSceneViewerMenuButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSceneViewerMenuButton::GetAnimMap(CSceneViewerMenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CSceneViewerMenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x004061F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSceneViewerMenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSceneViewerMenuButton::GetKBMap(CSceneViewerMenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSceneViewerMenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSceneViewerMenuButton::GetKBMap'::`2'::s_pMap;
  `CSceneViewerMenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSceneViewerMenuButton");
  `CSceneViewerMenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406220
// Name: void GetComboVals(class CDmeCombinationOperator __near *,class CUtlStringMap<class Vector> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetComboVals(CDmeCombinationOperator *pComboOp, CUtlVector<QAngle,CUtlMemory<QAngle,int> > *controlValues)
{
  CUtlVector<QAngle,CUtlMemory<QAngle,int> > *v2; // edi
  int v3; // esi
  const char *ControlName; // eax
  int m_Id; // edi
  CUtlVector<QAngle,CUtlMemory<QAngle,int> > *v6; // ecx
  int m_Size; // eax
  Vector2D *v8; // edi
  int nControls; // [esp+Ch] [ebp-8h]
  CUtlSymbol result; // [esp+10h] [ebp-4h] BYREF

  v2 = controlValues;
  v3 = 0;
  controlValues->m_Size = 0;
  CUtlSymbolTable::RemoveAll(this: (CUtlSymbolTable *)&controlValues[1]);
  nControls = CDmeMaterialGroup::GetListAttr(this: pComboOp);
  if ( nControls > 0 )
  {
    while ( 1 )
    {
      ControlName = CDmeCombinationOperator::GetControlName(this: pComboOp, i: v3);
      CUtlSymbolTable::AddString(this: (CUtlSymbolTable *)&v2[1], &result, pString: ControlName);
      m_Id = result.m_Id;
      v6 = controlValues;
      m_Size = controlValues->m_Size;
      if ( m_Size <= result.m_Id && m_Size < result.m_Id + 1 )
      {
        CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
          this: controlValues,
          elem: m_Size,
          num: result.m_Id + 1 - m_Size);
        v6 = controlValues;
      }
      v8 = (Vector2D *)&v6->m_Memory.m_pMemory[m_Id];
      *v8 = *CDmeCombinationOperator::GetStereoControlValue(
               this: pComboOp,
               nControlIndex: v3,
               type: COMBO_CONTROL_FIRST);
      v8[1].x = CDmeCombinationOperator::GetMultiControlLevel(
                  this: pComboOp,
                  nControlIndex: v3++,
                  type: COMBO_CONTROL_FIRST);
      if ( v3 >= nControls )
        break;
      v2 = controlValues;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004062C0
// Name: void SetComboVals(class CDmeCombinationOperator __near *,class CUtlStringMap<class Vector> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetComboVals(CDmeCombinationOperator *pComboOp, CUtlVector<QAngle,CUtlMemory<QAngle,int> > *controlValues)
{
  int v2; // esi
  const char *ControlName; // eax
  const char *v4; // eax
  int m_Id; // edi
  CUtlVector<QAngle,CUtlMemory<QAngle,int> > *v6; // ecx
  int m_Size; // eax
  const Vector2D *v8; // edi
  int nControls; // [esp+14h] [ebp-Ch]
  CUtlSymbol result; // [esp+1Ah] [ebp-6h] BYREF
  CUtlSymbol v11; // [esp+1Ch] [ebp-4h] BYREF

  v2 = 0;
  nControls = CDmeMaterialGroup::GetListAttr(this: pComboOp);
  if ( nControls > 0 )
  {
    do
    {
      ControlName = CDmeCombinationOperator::GetControlName(this: pComboOp, i: v2);
      if ( CUtlSymbolTable::Find(this: (CUtlSymbolTable *)&controlValues[1], &result, pString: ControlName)->m_Id != 0xFFFF )
      {
        v4 = CDmeCombinationOperator::GetControlName(this: pComboOp, i: v2);
        CUtlSymbolTable::AddString(this: (CUtlSymbolTable *)&controlValues[1], result: &v11, pString: v4);
        m_Id = v11.m_Id;
        v6 = controlValues;
        m_Size = controlValues->m_Size;
        if ( m_Size <= v11.m_Id && m_Size < v11.m_Id + 1 )
        {
          CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertMultipleBefore(
            this: controlValues,
            elem: m_Size,
            num: v11.m_Id + 1 - m_Size);
          v6 = controlValues;
        }
        v8 = (const Vector2D *)&v6->m_Memory.m_pMemory[m_Id];
        CDmeCombinationOperator::SetControlValue(this: pComboOp, nControlIndex: v2, vec: v8, type: COMBO_CONTROL_FIRST);
        CDmeCombinationOperator::SetMultiControlLevel(
          this: pComboOp,
          nControlIndex: v2,
          flMultiLevel: v8[1].x,
          type: COMBO_CONTROL_FIRST);
      }
      ++v2;
    }
    while ( v2 < nControls );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406480
// Name: public: unsigned short CUtlDict<int,unsigned short>::Insert(char const __near *,int const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<int,unsigned short>::Insert(
        CUtlDict<int,unsigned short> *this,
        const char *pName,
        int *element)
{
  char *v4; // eax
  int v5; // edx
  CUtlMap<char const *,int,unsigned short>::Node_t insert; // [esp+8h] [ebp-8h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  v5 = *element;
  insert.key = v4;
  insert.elem = v5;
  return CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Elements.m_Tree,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x004064F0
// Name: public: virtual int CSceneViewerMenuButton::AddMenuItem(char const __near *,char const __near *,class KeyValues __near *,class vgui::Panel __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
const KeyValues *__thiscall CSceneViewerMenuButton::AddMenuItem(
        CSceneViewerMenuButton *this,
        const char *itemName,
        const char *itemText,
        KeyValues *message,
        vgui::Panel *target,
        const KeyValues *userData)
{
  const KeyValues *v7; // edi

  v7 = (const KeyValues *)this->m_pMenu->AddMenuItem(
                            this: this->m_pMenu,
                            a2: itemText,
                            a3: message,
                            a4: target,
                            a5: userData);
  userData = v7;
  CUtlDict<int,unsigned short>::Insert(this: &this->m_Items, pName: itemName, element: (int *)&userData);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00406540
// Name: public: virtual int CSceneViewerMenuButton::AddCheckableMenuItem(char const __near *,char const __near *,class KeyValues __near *,class vgui::Panel __near *,class KeyValues const __near *)
// Source: json
//------------------------------------------------------------------------------
const KeyValues *__thiscall CSceneViewerMenuButton::AddCheckableMenuItem(
        CSceneViewerMenuButton *this,
        const char *itemName,
        const char *itemText,
        KeyValues *message,
        vgui::Panel *target,
        const KeyValues *userData)
{
  const KeyValues *v7; // edi

  v7 = (const KeyValues *)this->m_pMenu->AddCheckableMenuItem(
                            this: this->m_pMenu,
                            a2: itemText,
                            a3: message,
                            a4: target,
                            a5: userData);
  userData = v7;
  CUtlDict<int,unsigned short>::Insert(this: &this->m_Items, pName: itemName, element: (int *)&userData);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00406590
// Name: public: CSceneViewerEditMenuButton::CSceneViewerEditMenuButton(class CSceneViewerPanel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CSceneViewerEditMenuButton *__thiscall CSceneViewerEditMenuButton::CSceneViewerEditMenuButton(
        CSceneViewerEditMenuButton *this,
        CSceneViewerPanel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // eax

  CSceneViewerMenuButton::CSceneViewerMenuButton(this, parent, panelName, text);
  this->__vftable = (CSceneViewerEditMenuButton_vtbl *)&CSceneViewerEditMenuButton::`vftable';
  if ( `CSceneViewerEditMenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `CSceneViewerEditMenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CSceneViewerEditMenuButton");
    v5->pfnClassName = CSceneViewerEditMenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "CSceneViewerMenuButton");
  }
  if ( `CSceneViewerEditMenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSceneViewerEditMenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CSceneViewerEditMenuButton");
    v6->pfnClassName = CSceneViewerEditMenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "CSceneViewerMenuButton");
  }
  if ( `CSceneViewerEditMenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSceneViewerEditMenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CSceneViewerEditMenuButton");
    v7->pfnClassName = CSceneViewerEditMenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CSceneViewerMenuButton");
  }
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v9 = KeyValues::KeyValues(this: v8, setName: "Command", firstKey: "command", firstValue: "OnUndo");
  else
    v9 = nullptr;
  text = (const char *)this->CSceneViewerMenuButton::m_pMenu->AddMenuItem(
                         this: this->CSceneViewerMenuButton::m_pMenu,
                         a2: "&Undo",
                         a3: v9,
                         a4: parent,
                         a5: nullptr);
  CUtlDict<int,unsigned short>::Insert(this: &this->m_Items, pName: "undo", element: (int *)&text);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(this: v10, setName: "Command", firstKey: "command", firstValue: "OnRedo");
  else
    v11 = nullptr;
  text = (const char *)this->CSceneViewerMenuButton::m_pMenu->AddMenuItem(
                         this: this->CSceneViewerMenuButton::m_pMenu,
                         a2: "&Redo",
                         a3: v11,
                         a4: parent,
                         a5: nullptr);
  CUtlDict<int,unsigned short>::Insert(this: &this->m_Items, pName: "redo", element: (int *)&text);
  v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v12 != nullptr )
    v13 = KeyValues::KeyValues(this: v12, setName: "Command", firstKey: "command", firstValue: "OnDescribeUndoStack");
  else
    v13 = nullptr;
  text = (const char *)this->CSceneViewerMenuButton::m_pMenu->AddMenuItem(
                         this: this->CSceneViewerMenuButton::m_pMenu,
                         a2: "Describe Undo Stack",
                         a3: v13,
                         a4: parent,
                         a5: nullptr);
  CUtlDict<int,unsigned short>::Insert(this: &this->m_Items, pName: "describe", element: (int *)&text);
  v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v14 != nullptr )
    v15 = KeyValues::KeyValues(this: v14, setName: "Command", firstKey: "command", firstValue: "OnEdit");
  else
    v15 = nullptr;
  text = (const char *)this->CSceneViewerMenuButton::m_pMenu->AddMenuItem(
                         this: this->CSceneViewerMenuButton::m_pMenu,
                         a2: "&Properties...",
                         a3: v15,
                         a4: parent,
                         a5: nullptr);
  CUtlDict<int,unsigned short>::Insert(this: &this->m_Items, pName: "properties", element: (int *)&text);
  vgui::MenuButton::SetMenu(this, menu: this->CSceneViewerMenuButton::m_pMenu);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004067D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CSceneViewerEditMenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSceneViewerEditMenuButton::GetMessageMap(CSceneViewerEditMenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSceneViewerEditMenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSceneViewerEditMenuButton::GetMessageMap'::`2'::s_pMap;
  `CSceneViewerEditMenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSceneViewerEditMenuButton");
  `CSceneViewerEditMenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406800
// Name: public: virtual struct PanelAnimationMap __near * CSceneViewerEditMenuButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSceneViewerEditMenuButton::GetAnimMap(CSceneViewerEditMenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CSceneViewerEditMenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x00406810
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSceneViewerEditMenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSceneViewerEditMenuButton::GetKBMap(CSceneViewerEditMenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSceneViewerEditMenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSceneViewerEditMenuButton::GetKBMap'::`2'::s_pMap;
  `CSceneViewerEditMenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSceneViewerEditMenuButton");
  `CSceneViewerEditMenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406840
// Name: public: CSceneViewerPanel::CSceneViewerPanel(void)
// Source: json
//------------------------------------------------------------------------------
CSceneViewerPanel *__thiscall CSceneViewerPanel::CSceneViewerPanel(CSceneViewerPanel *this)
{
  vgui::PanelMessageMap *v2; // edi
  PanelAnimationMap *v3; // edi
  vgui::PanelKeyBindingMap *v4; // edi
  CSceneViewerMenuBar *v5; // eax
  CSceneViewerMenuBar *v6; // eax
  vgui::Menu *v7; // eax
  vgui::Menu *v8; // edi
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  CSceneViewerEditMenuButton *v21; // eax
  CSceneViewerEditMenuButton *v22; // eax
  vgui::Menu *v23; // eax
  vgui::Menu *v24; // edi
  KeyValues *v25; // eax
  KeyValues *v26; // eax
  KeyValues *v27; // eax
  KeyValues *v28; // eax
  KeyValues *v29; // eax
  KeyValues *v30; // eax
  KeyValues *v31; // eax
  KeyValues *v32; // eax
  KeyValues *v33; // eax
  KeyValues *v34; // eax
  vgui::Panel *v35; // eax
  vgui::Panel *v36; // eax
  CClipViewPanel *v37; // eax
  CClipViewPanel *v38; // eax
  CDmeCombinationSystemEditorFrame *v39; // eax
  CDmeCombinationSystemEditorFrame *v40; // eax
  vgui::Panel *v41; // eax
  vgui::Panel *v42; // eax
  vgui::Panel *v43; // eax
  vgui::Panel *v44; // eax
  CAssetBuilderFrame *v45; // eax
  CAssetBuilderFrame *v46; // eax
  vgui::Panel *v47; // ebx
  vgui::Panel_vtbl *v48; // edi
  unsigned int v49; // eax
  vgui::Panel *v50; // eax
  vgui::Panel *v51; // eax
  vgui::Panel *v52; // eax
  CElementPropertiesTreeInternal *v53; // eax
  CElementPropertiesTreeInternal *v54; // eax
  vgui::Panel *v55; // eax
  vgui::Panel_vtbl *v56; // edi
  unsigned int v57; // eax
  vgui::Panel *v58; // eax
  vgui::Panel *v59; // eax
  vgui::FileOpenStateMachine *v60; // eax
  vgui::FileOpenStateMachine *v61; // eax
  vgui::CConsoleDialog *v62; // eax
  vgui::CConsoleDialog *v63; // eax
  vgui::Panel *v65; // [esp+Ch] [ebp-4h]
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent: nullptr, panelName: "SceneViewer");
  this->IDmNotify::__vftable = (IDmNotify_vtbl *)&IDmNotify::`vftable';
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&vgui::IFileOpenStateMachineClient::`vftable';
  this->vgui::Panel::vgui::IClientPanel::__vftable = (CSceneViewerPanel_vtbl *)&CSceneViewerPanel::`vftable'{for `vgui::Panel'};
  this->IDmNotify::__vftable = (IDmNotify_vtbl *)&CSceneViewerPanel::`vftable'{for `IDmNotify'};
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&CSceneViewerPanel::`vftable'{for `vgui::IFileOpenStateMachineClient'};
  if ( `CSceneViewerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CSceneViewerPanel::ChainToMap'::`2'::chained = 1;
    v2 = vgui::FindOrAddPanelMessageMap(className: "CSceneViewerPanel");
    v2->pfnClassName = CSceneViewerPanel::GetPanelClassName;
    v2->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CSceneViewerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSceneViewerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v3 = FindOrAddPanelAnimationMap(className: "CSceneViewerPanel");
    v3->pfnClassName = CSceneViewerPanel::GetPanelClassName;
    v3->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CSceneViewerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSceneViewerPanel::KB_ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelKeyBindingMap(className: "CSceneViewerPanel");
    v4->pfnClassName = CSceneViewerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CSceneViewerPanel::PanelMessageFunc_OnNew::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnOpen::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnSave::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnSaveAs::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnSaveCurrentAs::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnExit::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnLoadFile::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnPinAndZoomIt::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnShow3DView::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnHide3DView::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnShowComboEditor::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnHideComboEditor::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnShowAssetBuilder::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnHideAssetBuilder::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnShowConsole::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnHideConsole::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnShowNerdEditor::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnHideNerdEditor::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnCombinationOperatorChanged::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::PanelMessageFunc_OnCommandSubmitted::InitVar(a1: (int)&savedregs);
  CSceneViewerPanel::CCommandMemberInitializer_ReplaceMaterial::CCommandMemberInitializer_ReplaceMaterial(this: &this->m_ReplaceMaterial_register);
  CSceneViewerPanel::CCommandMemberInitializer_CollapseJointSubtree::CCommandMemberInitializer_CollapseJointSubtree(this: &this->m_CollapseJointSubtree_register);
  this->m_hFileOpenDialog.m_iPanelID = -1;
  this->m_hProperties.m_iPanelID = -1;
  this->m_pCombinationEditor.m_iPanelID = -1;
  this->m_pAssetBuilder.m_iPanelID = -1;
  this->m_pNerdEditor.m_iPanelID = -1;
  CUtlString::CUtlString(this: &this->m_fileDirectory);
  CUtlString::CUtlString(this: &this->m_filename);
  v5 = (CSceneViewerMenuBar *)MemAlloc_Alloc(nSize: 0x174u);
  if ( v5 != nullptr )
    v6 = CSceneViewerMenuBar::CSceneViewerMenuBar(this: v5, parent: this, panelName: "Main Menu Bar");
  else
    v6 = nullptr;
  this->m_pMenuBar = v6;
  vgui::Panel::SetSize(this: v6, wide: 10, tall: 28);
  v7 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v7 != nullptr )
    v8 = vgui::Menu::Menu(this: v7, parent: nullptr, panelName: "File Menu");
  else
    v8 = nullptr;
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: "New");
  else
    v10 = nullptr;
  v8->AddMenuItem(this: v8, a2: "&New", a3: v10, a4: this, a5: nullptr);
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "Open");
  else
    v12 = nullptr;
  v8->AddMenuItem(this: v8, a2: "&Open", a3: v12, a4: this, a5: nullptr);
  v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v13 != nullptr )
    v14 = KeyValues::KeyValues(this: v13, setName: "Save");
  else
    v14 = nullptr;
  v8->AddMenuItem(this: v8, a2: "&Save", a3: v14, a4: this, a5: nullptr);
  v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v15 != nullptr )
    v16 = KeyValues::KeyValues(this: v15, setName: "SaveAs");
  else
    v16 = nullptr;
  v8->AddMenuItem(this: v8, a2: "Save &As", a3: v16, a4: this, a5: nullptr);
  v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v17 != nullptr )
    v18 = KeyValues::KeyValues(this: v17, setName: "SaveCurrentAs");
  else
    v18 = nullptr;
  v8->AddMenuItem(this: v8, a2: "Save &Current As", a3: v18, a4: this, a5: nullptr);
  v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v19 != nullptr )
    v20 = KeyValues::KeyValues(this: v19, setName: "Exit");
  else
    v20 = nullptr;
  v8->AddMenuItem(this: v8, a2: "E&xit", a3: v20, a4: this, a5: nullptr);
  this->m_pMenuBar->AddMenu(this: this->m_pMenuBar, a2: "&File", a3: v8);
  v21 = (CSceneViewerEditMenuButton *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v21 != nullptr )
    v22 = CSceneViewerEditMenuButton::CSceneViewerEditMenuButton(
            this: v21,
            parent: this,
            panelName: "Edit Menu",
            text: "&Edit");
  else
    v22 = nullptr;
  this->m_pMenuBar->AddButton(this: this->m_pMenuBar, a2: v22);
  v23 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v23 != nullptr )
    v24 = vgui::Menu::Menu(this: v23, parent: nullptr, panelName: "Windows Menu");
  else
    v24 = nullptr;
  v25 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v25 != nullptr )
    v26 = KeyValues::KeyValues(this: v25, setName: "Show3DView");
  else
    v26 = nullptr;
  v24->AddMenuItem(this: v24, a2: "3D &View", a3: v26, a4: this, a5: nullptr);
  v27 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v27 != nullptr )
    v28 = KeyValues::KeyValues(this: v27, setName: "ShowComboEditor");
  else
    v28 = nullptr;
  v24->AddMenuItem(this: v24, a2: "&Combo Editor", a3: v28, a4: this, a5: nullptr);
  v29 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v29 != nullptr )
    v30 = KeyValues::KeyValues(this: v29, setName: "ShowAssetBuilder");
  else
    v30 = nullptr;
  v24->AddMenuItem(this: v24, a2: "&Asset Builder", a3: v30, a4: this, a5: nullptr);
  v31 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v31 != nullptr )
    v32 = KeyValues::KeyValues(this: v31, setName: "ShowNerdEditor");
  else
    v32 = nullptr;
  v24->AddMenuItem(this: v24, a2: "&Nerd Editor", a3: v32, a4: this, a5: nullptr);
  v33 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v33 != nullptr )
    v34 = KeyValues::KeyValues(this: v33, setName: "ShowConsole");
  else
    v34 = nullptr;
  v24->AddMenuItem(this: v24, a2: "C&onsole", a3: v34, a4: this, a5: nullptr);
  this->m_pMenuBar->AddMenu(this: this->m_pMenuBar, a2: "&Windows", a3: v24);
  v35 = (vgui::Panel *)MemAlloc_Alloc(nSize: 0x14Cu);
  if ( v35 != nullptr )
    v36 = vgui::Panel::Panel(this: v35, parent: this, panelName: "ClientArea");
  else
    v36 = nullptr;
  this->m_pClientArea = v36;
  v37 = (CClipViewPanel *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v37 != nullptr )
    v38 = CClipViewPanel::CClipViewPanel(this: v37, pParent: this->m_pClientArea, pName: "Clip Viewer");
  else
    v38 = nullptr;
  this->m_pClipViewPanel = v38;
  vgui::Panel::SetBounds(this: v38, x: 10, y: 40, wide: 500, tall: 500);
  this->m_pClipViewPanel->AddActionSignalTarget_2(this: this->m_pClipViewPanel, a2: this);
  v39 = (CDmeCombinationSystemEditorFrame *)MemAlloc_Alloc(nSize: 0x220u);
  if ( v39 != nullptr )
    v40 = CDmeCombinationSystemEditorFrame::CDmeCombinationSystemEditorFrame(
            this: v39,
            pParent: this->m_pClientArea,
            pTitle: "Combination Control Builder");
  else
    v40 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_pCombinationEditor, pPanel: v40);
  v41 = vgui::PHandle::Get(this: &this->m_pCombinationEditor);
  vgui::Panel::SetBounds(this: v41, x: 100, y: 100, wide: 512, tall: 512);
  v42 = vgui::PHandle::Get(this: &this->m_pCombinationEditor);
  v42->SetVisible(this: v42, a2: false);
  v43 = vgui::PHandle::Get(this: &this->m_pCombinationEditor);
  ((void (__thiscall *)(vgui::Panel *, _DWORD))v43->__vftable[1].GetUnpackStructure)(a1: v43, a2: 0);
  v44 = vgui::PHandle::Get(this: &this->m_pCombinationEditor);
  v44->AddActionSignalTarget_2(this: v44, a2: this);
  v45 = (CAssetBuilderFrame *)MemAlloc_Alloc(nSize: 0x23Cu);
  if ( v45 != nullptr )
    v46 = CAssetBuilderFrame::CAssetBuilderFrame(this: v45, pParent: this->m_pClientArea, pTitle: "Asset Builder");
  else
    v46 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_pAssetBuilder, pPanel: v46);
  v47 = vgui::PHandle::Get(this: &this->m_pAssetBuilder);
  v48 = v47->__vftable;
  v49 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  v48->SetParent(this: v47, a2: v49);
  v50 = vgui::PHandle::Get(this: &this->m_pAssetBuilder);
  v50->SetVisible(this: v50, a2: false);
  v51 = vgui::PHandle::Get(this: &this->m_pAssetBuilder);
  vgui::Panel::SetBounds(this: v51, x: 50, y: 50, wide: 512, tall: 512);
  v52 = vgui::PHandle::Get(this: &this->m_pAssetBuilder);
  ((void (__thiscall *)(vgui::Panel *, _DWORD))v52->__vftable[1].GetUnpackStructure)(a1: v52, a2: 0);
  v53 = (CElementPropertiesTreeInternal *)MemAlloc_Alloc(nSize: 0x2BCu);
  if ( v53 != nullptr )
    v54 = CElementPropertiesTreeInternal::CElementPropertiesTreeInternal(
            this: v53,
            parent: this->m_pClientArea,
            pNotify: &this->IDmNotify,
            pObject: nullptr,
            autoApply: true,
            pDict: nullptr);
  else
    v54 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_pNerdEditor, pPanel: v54);
  v55 = vgui::PHandle::Get(this: &this->m_pNerdEditor);
  v56 = v55->__vftable;
  v65 = v55;
  v57 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  v56->SetParent(this: v65, a2: v57);
  v58 = vgui::PHandle::Get(this: &this->m_pNerdEditor);
  v58->SetVisible(this: v58, a2: false);
  v59 = vgui::PHandle::Get(this: &this->m_pNerdEditor);
  vgui::Panel::SetBounds(this: v59, x: 50, y: 50, wide: 512, tall: 512);
  v60 = (vgui::FileOpenStateMachine *)MemAlloc_Alloc(nSize: 0x1B0u);
  if ( v60 != nullptr )
    v61 = vgui::FileOpenStateMachine::FileOpenStateMachine(
            this: v60,
            pParent: this,
            pClient: &this->vgui::IFileOpenStateMachineClient);
  else
    v61 = nullptr;
  this->m_pFileOpenStateMachine = v61;
  v61->AddActionSignalTarget_2(this: v61, a2: this);
  v62 = (vgui::CConsoleDialog *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v62 != nullptr )
    v63 = vgui::CConsoleDialog::CConsoleDialog(this: v62, pParent: this, pName: "ConsoleDialog", bStatusVersion: false);
  else
    v63 = nullptr;
  this->m_pConsole = v63;
  v63->AddActionSignalTarget_2(this: v63, a2: this);
  this->m_bConsolePositioned = false;
  CSceneViewerPanel::OnPinAndZoomIt(this);
  this->m_pRoot = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00406FD0
// Name: public: CDmObjSerializer::CDmObjSerializer(void)
// Source: json
//------------------------------------------------------------------------------
CDmObjSerializer *__thiscall CDmObjSerializer::CDmObjSerializer(CDmObjSerializer *this)
{
  this->__vftable = (CDmObjSerializer_vtbl *)&CDmObjSerializer::`vftable';
  this->m_mtlLib.m_Memory.m_pMemory = nullptr;
  this->m_mtlLib.m_Memory.m_nAllocationCount = 0;
  this->m_mtlLib.m_Memory.m_nGrowSize = 0;
  this->m_mtlLib.m_Size = 0;
  this->m_mtlLib.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_objDirectory);
  this->m_deltas.m_Vector.m_Memory.m_pMemory = nullptr;
  this->m_deltas.m_Vector.m_Memory.m_nAllocationCount = 0;
  this->m_deltas.m_Vector.m_Memory.m_nGrowSize = 32;
  this->m_deltas.m_Vector.m_Size = 0;
  this->m_deltas.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &this->m_deltas.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00407020
// Name: public: virtual char const __near * CDmObjSerializer::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmObjSerializer::GetName(CDmObjSerializer *this)
{
  return "obj";
}

//------------------------------------------------------------------------------
// Address: 0x00407030
// Name: public: virtual char const __near * CDmObjSerializer::GetDescription(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmObjSerializer::GetDescription(CDmObjSerializer *this)
{
  return "Wavefront OBJ";
}

//------------------------------------------------------------------------------
// Address: 0x00407040
// Name: public: CDmObjSerializer::~CDmObjSerializer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmObjSerializer::~CDmObjSerializer(CDmObjSerializer *this)
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_deltas.m_SymbolTable);
  CUtlVector<CDmObjSerializer::DeltaInfo_t,CUtlMemory<CDmObjSerializer::DeltaInfo_t,int>>::~CUtlVector<CDmObjSerializer::DeltaInfo_t,CUtlMemory<CDmObjSerializer::DeltaInfo_t,int>>(this: &this->m_deltas.m_Vector);
  this->m_objDirectory.m_Storage.m_nActualLength = 0;
  if ( this->m_objDirectory.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_objDirectory.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_objDirectory.m_Storage.m_Memory.m_pMemory);
      this->m_objDirectory.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_objDirectory.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>::~CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>(this: (CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int> > *)&this->m_mtlLib);
}

//------------------------------------------------------------------------------
// Address: 0x00407090
// Name: public: bool CSceneViewerPanel::Load(char const __near *,bool,class CUtlStringMap<class Vector> __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneViewerPanel::Load(
        CSceneViewerPanel *this,
        const char *pFilename,
        bool bFrame,
        CUtlVector<QAngle,CUtlMemory<QAngle,int> > *pOldComboVals)
{
  unsigned __int8 (__thiscall *v5)(CUtlSymbolLarge::<unnamed_type_u>); // edx
  int v6; // eax
  CDmObjSerializer *v7; // eax
  CDmeCombinationOperator *Value; // eax
  CDmObjSerializer v10; // [esp+Ch] [ebp-8Ch] BYREF
  CDisableUndoScopeGuard guard; // [esp+8Ch] [ebp-Ch] BYREF
  CDmElement *pRoot; // [esp+94h] [ebp-4h] BYREF

  v5 = *(unsigned __int8 (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 236);
  guard.m_bNotify = false;
  guard.m_pNotify = nullptr;
  *(_WORD *)&guard.m_bOldValue = ((int (__thiscall *)(_DWORD))v5)(a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id);
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 232))(
    a1: g_pDataModel.u,
    a2: 0);
  CSceneViewerPanel::Clear(this);
  pRoot = nullptr;
  v6 = _V_strlen(str: pFilename);
  if ( v6 <= 4 || _V_stricmp(s1: &pFilename[v6 - 4], s2: ".obj") != 0 )
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, _DWORD, _DWORD, CDmElement **, _DWORD, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 188))(
      a1: g_pDataModel.u,
      a2: pFilename,
      a3: 0,
      a4: 0,
      a5: &pRoot,
      a6: 0,
      a7: 0);
  }
  else
  {
    v7 = CDmObjSerializer::CDmObjSerializer(this: &v10);
    pRoot = CDmObjSerializer::ReadOBJ(
              this: v7,
              pFilename,
              ppCreatedMesh: nullptr,
              bLoadAllDeltas: true,
              bAbsolute: true);
    CDmObjSerializer::~CDmObjSerializer(this: &v10);
  }
  if ( pRoot != nullptr )
  {
    if ( pOldComboVals != nullptr )
    {
      Value = CDmElement::GetValueElement<CDmeCombinationOperator>(this: pRoot, pAttributeName: "combinationOperator");
      if ( Value != nullptr )
        SetComboVals(pComboOp: Value, controlValues: pOldComboVals);
    }
    CUtlString::operator=(this: &this->m_filename, src: pFilename);
    this->m_pRoot = pRoot;
    CSceneViewerPanel::SetScene(this, bFrame);
    CChangeUndoScopeGuard::Release(this: &guard);
    return 1;
  }
  else
  {
    CChangeUndoScopeGuard::Release(this: &guard);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004071B0
// Name: public: bool CSceneViewerPanel::Reload(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneViewerPanel::Reload(CSceneViewerPanel *this)
{
  CUtlString *p_m_filename; // esi
  const char *v4; // eax
  char v5; // bl
  CUtlVector<QAngle,CUtlMemory<QAngle,int> > *v6; // [esp-4h] [ebp-70h]
  CUtlStringMap<Vector> oldComboVals; // [esp+Ch] [ebp-60h] BYREF
  CUtlString tmpFilename; // [esp+58h] [ebp-14h] BYREF
  CDmeCombinationOperator *pComboOp; // [esp+68h] [ebp-4h]

  p_m_filename = &this->m_filename;
  if ( CUtlString::Length(this: &this->m_filename) != 0 )
  {
    _Msg(a1: "Reload( \"%s\" )\n", (const char *)p_m_filename->m_Storage.m_Memory.m_pMemory);
    pComboOp = CDmElement::GetValueElement<CDmeCombinationOperator>(
                 this: this->m_pRoot,
                 pAttributeName: "combinationOperator");
    oldComboVals.m_Vector.m_Memory.m_pMemory = nullptr;
    oldComboVals.m_Vector.m_Memory.m_nAllocationCount = 0;
    oldComboVals.m_Vector.m_Memory.m_nGrowSize = 32;
    oldComboVals.m_Vector.m_Size = 0;
    oldComboVals.m_Vector.m_pElements = nullptr;
    CUtlSymbolTable::CUtlSymbolTable(
      this: &oldComboVals.m_SymbolTable,
      growSize: 0,
      initSize: 32,
      caseInsensitive: true);
    if ( pComboOp != nullptr )
      GetComboVals(pComboOp, controlValues: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&oldComboVals);
    CUtlString::CUtlString(this: &tmpFilename, string: p_m_filename);
    v6 = oldComboVals.m_SymbolTable.m_Lookup.m_NumElements == 0
       ? nullptr
       : (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&oldComboVals;
    v4 = CUtlString::operator char const *(this: &tmpFilename);
    v5 = CSceneViewerPanel::Load(this, pFilename: v4, bFrame: false, pOldComboVals: v6);
    tmpFilename.m_Storage.m_nActualLength = 0;
    if ( tmpFilename.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( tmpFilename.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tmpFilename.m_Storage.m_Memory.m_pMemory);
        tmpFilename.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      tmpFilename.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    CUtlSymbolTable::~CUtlSymbolTable(this: &oldComboVals.m_SymbolTable);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&oldComboVals);
    return v5;
  }
  else
  {
    _Error(a1: "ERROR: Reload() Failed - No File loaded\n");
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004072C0
// Name: public: virtual void CSceneViewerPanel::OnLoadFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnLoadFile(CSceneViewerPanel *this, const char *fullpath)
{
  CSceneViewerPanel::Load(this, pFilename: fullpath, bFrame: true, pOldComboVals: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00407340
// Name: public: virtual void CSceneViewerPanel::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSceneViewerPanel::OnKeyCodePressed(CSceneViewerPanel *this, ButtonCode_t code)
{
  bool v3; // al
  vgui::CConsoleDialog *m_pConsole; // ecx

  vgui::Panel::OnKeyCodePressed(this, code);
  if ( code == KEY_BACKQUOTE )
  {
    v3 = this->m_pConsole->IsVisible(this: this->m_pConsole);
    m_pConsole = this->m_pConsole;
    if ( v3 )
      vgui::CConsoleDialog::Close(this: m_pConsole);
    else
      m_pConsole->Activate(this: m_pConsole);
  }
  else if ( code == KEY_F5 )
  {
    CSceneViewerPanel::Reload(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004073A0
// Name: protected: virtual bool CSceneViewerPanel::OnReadFileFromDisk(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneViewerPanel::OnReadFileFromDisk(
        CSceneViewerPanel *this,
        const char *pFileName,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  const char *v5; // eax
  vgui::ISystem *v6; // ebx
  char *v7; // eax
  char buf[260]; // [esp+Ch] [ebp-108h] BYREF
  vgui::ISystem_vtbl *v10; // [esp+110h] [ebp-4h]

  V_strncpy(pDest: buf, pSrc: pFileName, maxLen: 260);
  V_FixSlashes(pname: buf, separator: 92);
  V_StripFilename(path: buf);
  CUtlString::operator=(this: (CUtlString *)&this->m_sNavLeftName.m_Storage.m_Memory.m_nGrowSize, src: buf);
  v5 = CUtlString::operator char const *(this: (CUtlString *)&this->m_sNavLeftName.m_Storage.m_Memory.m_nGrowSize);
  _fullpath(UserBuf: buf, path: v5, maxlen: 0x104u);
  CUtlString::operator=(this: (CUtlString *)&this->m_sNavLeftName.m_Storage.m_Memory.m_nGrowSize, src: buf);
  v6 = g_pVGuiSystem;
  v10 = g_pVGuiSystem->__vftable;
  v7 = CUtlString::Get(this: (CUtlString *)&this->m_sNavLeftName.m_Storage.m_Memory.m_nGrowSize);
  v10->SetRegistryString(this: v6, a2: "HKEY_CURRENT_USER\\Software\\Valve\\sceneviewer\\dmxfiles\\opendir", a3: v7);
  return CSceneViewerPanel::Load(
           this: (CSceneViewerPanel *)((char *)this - 336),
           pFilename: pFileName,
           bFrame: true,
           pOldComboVals: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00407470
// Name: protected: bool CSceneViewerPanel::SaveCurrentAs(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSceneViewerPanel::SaveCurrentAs(CSceneViewerPanel *this, CDmeVertexData *pFilename)
{
  CDmElement *m_pRoot; // ecx
  CDmeDag **m_pMemory; // ebx
  int m_Size; // esi
  CDmeDag **v6; // eax
  CDmeDag *v7; // edi
  int v8; // eax
  CDmeShape *Shape; // eax
  CDmeMesh *v10; // edi
  CDmeVertexData *BaseState; // ebx
  int v12; // esi
  CDmeDag *v13; // edi
  int v14; // eax
  CDmeShape *v15; // eax
  CDmeMesh *v16; // edi
  CDmeVertexData *v17; // eax
  int v18; // edi
  int BufferType; // eax
  CDmObjSerializer v20; // [esp+Ch] [ebp-ACh] BYREF
  CDmeDag *Child; // [esp+8Ch] [ebp-2Ch]
  CUtlSymbolLarge value; // [esp+90h] [ebp-28h] BYREF
  CDmeDag *pModel; // [esp+94h] [ebp-24h]
  CUtlSymbolLarge v24; // [esp+98h] [ebp-20h] BYREF
  CDmeVertexData *pNewBind; // [esp+9Ch] [ebp-1Ch]
  CUtlStack<CDmeDag *,CUtlMemory<CDmeDag *,int> > traverseStack; // [esp+A0h] [ebp-18h] BYREF
  int nChildIndex; // [esp+B4h] [ebp-4h]
  CDmeVertexData *pOldBind; // [esp+C0h] [ebp+8h]
  CDmeVertexData *pOldBinda; // [esp+C0h] [ebp+8h]

  pNewBind = (CDmeVertexData *)this;
  m_pRoot = this->m_pRoot;
  if ( m_pRoot == nullptr )
    return 0;
  pModel = CDmElement::GetValueElement<CDmeDag>(this: m_pRoot, pAttributeName: "model");
  if ( pModel == nullptr )
    return 0;
  memset(&traverseStack, 0, sizeof(traverseStack));
  CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&traverseStack, num: 1);
  m_pMemory = traverseStack.m_Memory.m_pMemory;
  m_Size = traverseStack.m_Size + 1;
  v6 = &traverseStack.m_Memory.m_pMemory[traverseStack.m_Size++];
  traverseStack.m_pElements = traverseStack.m_Memory.m_pMemory;
  if ( v6 != nullptr )
    *v6 = pModel;
  while ( m_Size != 0 )
  {
    v7 = m_pMemory[--m_Size];
    traverseStack.m_Size = m_Size;
    if ( v7 != nullptr )
    {
      v8 = CDmElementFramework::GetPhase(this: v7) - 1;
      nChildIndex = v8;
      if ( v8 >= 0 )
      {
        while ( 1 )
        {
          Child = CDmeDag::GetChild(this: v7, i: v8);
          if ( m_Size >= traverseStack.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&traverseStack, num: 1);
            m_Size = traverseStack.m_Size;
            m_pMemory = traverseStack.m_Memory.m_pMemory;
          }
          traverseStack.m_Size = ++m_Size;
          traverseStack.m_pElements = m_pMemory;
          if ( &m_pMemory[m_Size] != (CDmeDag **)4 )
            m_pMemory[m_Size - 1] = Child;
          if ( --nChildIndex < 0 )
            break;
          v8 = nChildIndex;
        }
      }
      Shape = CDmeDag::GetShape(this: v7);
      v10 = (CDmeMesh *)Shape;
      if ( Shape != nullptr && Shape->IsA(this: Shape, a2: CDmeMesh::m_classType) )
      {
        nChildIndex = (int)CDmeMesh::FindBaseState(this: v10, pStateName: "bind");
        if ( nChildIndex != 0 )
        {
          BaseState = CDmeMesh::FindOrCreateBaseState(this: v10, pStateName: "__sceneviewer_newBind");
          CDmeVertexDataBase::CopyTo(this: (CDmeVertexDataBase *)nChildIndex, pDst: BaseState);
          (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
            a1: g_pDataModel.u,
            a2: &value,
            a3: "__sceneviewer_oldBind");
          CDmAttribute::SetValue<CUtlSymbolLarge>(this: *(CDmAttribute **)(nChildIndex + 24), &value);
          (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
            a1: g_pDataModel.u,
            a2: &v24,
            a3: "bind");
          CDmAttribute::SetValue<CUtlSymbolLarge>(this: BaseState->m_Name.m_pAttribute, value: &v24);
          CDmeMesh::SetBaseStateToDeltas(this: v10, pPassedBase: BaseState);
          m_pMemory = traverseStack.m_Memory.m_pMemory;
        }
      }
    }
  }
  v20.__vftable = (CDmObjSerializer_vtbl *)&CDmObjSerializer::`vftable';
  memset(&v20.m_mtlLib, 0, sizeof(v20.m_mtlLib));
  CUtlString::CUtlString(this: &v20.m_objDirectory);
  v20.m_deltas.m_Vector.m_Memory.m_pMemory = nullptr;
  v20.m_deltas.m_Vector.m_Memory.m_nAllocationCount = 0;
  v20.m_deltas.m_Vector.m_Memory.m_nGrowSize = 32;
  v20.m_deltas.m_Vector.m_Size = 0;
  v20.m_deltas.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(this: &v20.m_deltas.m_SymbolTable, growSize: 0, initSize: 32, caseInsensitive: true);
  CDmObjSerializer::WriteOBJ(
    this: &v20,
    (const char *)pFilename,
    pRoot: *((CDmElement **)&pNewBind[3].m_ref + 2),
    bWriteOBJs: false,
    pDeltaName: nullptr,
    absolute: true);
  CUtlSymbolTable::~CUtlSymbolTable(this: &v20.m_deltas.m_SymbolTable);
  CUtlVector<CDmObjSerializer::DeltaInfo_t,CUtlMemory<CDmObjSerializer::DeltaInfo_t,int>>::~CUtlVector<CDmObjSerializer::DeltaInfo_t,CUtlMemory<CDmObjSerializer::DeltaInfo_t,int>>(this: &v20.m_deltas.m_Vector);
  v20.m_objDirectory.m_Storage.m_nActualLength = 0;
  if ( v20.m_objDirectory.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v20.m_objDirectory.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v20.m_objDirectory.m_Storage.m_Memory.m_pMemory);
      v20.m_objDirectory.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    v20.m_objDirectory.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>::~CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int>>(this: (CUtlVector<CacheModInfo_t,CUtlMemory<CacheModInfo_t,int> > *)&v20.m_mtlLib);
  if ( m_Size >= traverseStack.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&traverseStack, num: 1);
    m_Size = traverseStack.m_Size;
    m_pMemory = traverseStack.m_Memory.m_pMemory;
  }
  v12 = m_Size + 1;
  traverseStack.m_pElements = m_pMemory;
  if ( &m_pMemory[v12] != (CDmeDag **)4 )
    m_pMemory[v12 - 1] = pModel;
  while ( v12 != 0 )
  {
    v13 = m_pMemory[--v12];
    traverseStack.m_Size = v12;
    if ( v13 != nullptr )
    {
      v14 = CDmElementFramework::GetPhase(this: v13) - 1;
      pOldBind = (CDmeVertexData *)v14;
      if ( v14 >= 0 )
      {
        while ( 1 )
        {
          pNewBind = (CDmeVertexData *)CDmeDag::GetChild(this: v13, i: v14);
          if ( v12 >= traverseStack.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&traverseStack, num: 1);
            v12 = traverseStack.m_Size;
            m_pMemory = traverseStack.m_Memory.m_pMemory;
          }
          traverseStack.m_Size = ++v12;
          traverseStack.m_pElements = m_pMemory;
          if ( &m_pMemory[v12] != (CDmeDag **)4 )
            m_pMemory[v12 - 1] = (CDmeDag *)pNewBind;
          pOldBind = (CDmeVertexData *)((char *)pOldBind - 1);
          if ( (int)pOldBind < 0 )
            break;
          v14 = (int)pOldBind;
        }
      }
      v15 = CDmeDag::GetShape(this: v13);
      v16 = (CDmeMesh *)v15;
      if ( v15 != nullptr && v15->IsA(this: v15, a2: CDmeMesh::m_classType) )
      {
        pOldBinda = CDmeMesh::FindBaseState(this: v16, pStateName: "__sceneviewer_oldBind");
        v17 = CDmeMesh::FindBaseState(this: v16, pStateName: "bind");
        pNewBind = v17;
        if ( pOldBinda != nullptr && v17 != nullptr )
        {
          CDmeMesh::DeleteBaseState(this: v16, pStateName: "bind");
          (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
            a1: g_pDataModel.u,
            a2: &v24,
            a3: "bind");
          CDmAttribute::SetValue<CUtlSymbolLarge>(this: pOldBinda->m_Name.m_pAttribute, value: &v24);
          v18 = *(_DWORD *)g_pDataModel.u.m_Id;
          BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pNewBind);
          (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v18 + 68))(
            a1: g_pDataModel.u,
            a2: BufferType);
        }
      }
    }
  }
  if ( traverseStack.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00407820
// Name: protected: virtual bool CSceneViewerPanel::OnWriteFileToDisk(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CSceneViewerPanel::OnWriteFileToDisk@<al>(
        CSceneViewerPanel *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        CDmeVertexData *pFilename,
        const char *pPassedFileFormat,
        KeyValues *pContextKeyValues)
{
  const char *Name; // eax
  CDmObjSerializer *v9; // eax
  bool v10; // bl
  int v12; // eax
  CDmObjSerializer *v13; // eax
  bool v14; // bl
  const char *v15; // edi
  vgui::MessageBox *v16; // esi
  vgui::Panel *v17; // eax
  vgui::MessageBox *v18; // esi
  CDmElement *m_nActualLength; // [esp-18h] [ebp-49Ch]
  CDmElement *v20; // [esp-14h] [ebp-498h]
  char pBuf[1024]; // [esp+4h] [ebp-480h] BYREF
  CDmObjSerializer v23; // [esp+404h] [ebp-80h] BYREF
  char retVal_3; // [esp+48Fh] [ebp+Bh]

  if ( this->m_sNavDownName.m_Storage.m_nActualLength == 0 )
    return 0;
  Name = KeyValues::GetName(this: pContextKeyValues);
  if ( _V_strcmp(s1: Name, s2: "SaveCurrentAs") == 0 )
    return CSceneViewerPanel::SaveCurrentAs(this: (CSceneViewerPanel *)((char *)this - 336), pFilename);
  if ( _V_stricmp(s1: pPassedFileFormat, s2: "obj") != 0 )
  {
    v12 = _V_strlen(str: (const char *)pFilename);
    if ( v12 <= 4 || _V_stricmp(s1: (const char *)pFilename + v12 - 4, s2: ".obj") != 0 )
    {
      v15 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, int, int))(*(_DWORD *)g_pDataModel.u.m_Id + 124))(
                            a1: g_pDataModel.u,
                            a2: pPassedFileFormat,
                            a3,
                            a4: a2);
      if ( v15 == nullptr
        || (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 172))(
             a1: g_pDataModel.u,
             a2: v15) == 0 )
      {
        v15 = "binary";
      }
      retVal_3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CDmeVertexData *, _DWORD, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 184))(
                   a1: g_pDataModel.u,
                   a2: pFilename,
                   a3: 0,
                   a4: v15);
      if ( retVal_3 != 0
        && g_pFullFileSystem->FileExists(
             this: &g_pFullFileSystem->IBaseFileSystem,
             a2: (const char *)pFilename,
             a3: nullptr) )
      {
        return retVal_3;
      }
      else
      {
        V_snprintf(
          pDest: pBuf,
          maxLen: 1024,
          pFormat: "DMX Write Failed!\n\nCouldn't Save \"%s\"\n\nAs DMX Format \"%s\"",
          (const char *)pFilename,
          pPassedFileFormat);
        v16 = (vgui::MessageBox *)MemAlloc_Alloc(nSize: 0x234u);
        if ( v16 != nullptr )
        {
          v17 = (vgui::Panel *)(*(int (__thiscall **)(char *))(*((_DWORD *)this - 84) + 156))(a1: (char *)this - 336);
          v18 = vgui::MessageBox::MessageBox(this: v16, title: "DMX Write Failed", text: pBuf, parent: v17);
        }
        else
        {
          v18 = nullptr;
        }
        v18->AddActionSignalTarget_2(this: v18, a2: (CSceneViewerPanel *)((char *)this - 336));
        v18->SetOKButtonVisible(this: v18, a2: true);
        v18->SetOKButtonText_2(this: v18, a2: "Ok");
        v18->DoModal_2(this: v18, a2: nullptr);
        return 0;
      }
    }
    else
    {
      m_nActualLength = (CDmElement *)this->m_sNavDownName.m_Storage.m_nActualLength;
      v13 = CDmObjSerializer::CDmObjSerializer(this: &v23);
      v14 = CDmObjSerializer::WriteOBJ(
              this: v13,
              (const char *)pFilename,
              pRoot: m_nActualLength,
              bWriteOBJs: true,
              pDeltaName: nullptr,
              absolute: true);
      CDmObjSerializer::~CDmObjSerializer(this: &v23);
      return v14;
    }
  }
  else
  {
    v20 = (CDmElement *)this->m_sNavDownName.m_Storage.m_nActualLength;
    v9 = CDmObjSerializer::CDmObjSerializer(this: &v23);
    v10 = CDmObjSerializer::WriteOBJ(
            this: v9,
            (const char *)pFilename,
            pRoot: v20,
            bWriteOBJs: true,
            pDeltaName: nullptr,
            absolute: true);
    CDmObjSerializer::~CDmObjSerializer(this: &v23);
    return v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043B250
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<class CUtlSymbolLarge,struct DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbolLarge,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<CUtlSymbolLarge,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<CUtlSymbolLarge,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 52 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlSymbolLarge,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<CUtlSymbolLarge,DmMemoryInfo_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004415C0
// Name: public: void CUtlDict<class CDmElementFactoryHelper __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CDmElementFactoryHelper *,int>::RemoveAll(CUtlDict<CDmElementFactoryHelper *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int,CUtlMap<char const *,CDmElementFactoryHelper *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElementFactoryHelper *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00443000
// Name: public: int CUtlDict<class CDmElementFactoryHelper __near *,int>::Insert(char const __near *,class CDmElementFactoryHelper __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CDmElementFactoryHelper *,int>::Insert(
        CUtlDict<CDmElementFactoryHelper *,int> *this,
        char *pName,
        CDmElementFactoryHelper *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CDmElementFactoryHelper *,int>::Insert(
           this: &this->m_Elements,
           key: (const char *const *)&pName,
           insert: element);
}

//------------------------------------------------------------------------------
// Address: 0x00459750
// Name: public: class CDmAttribute __near * CDmElement::AddAttributeElementArray<class CDmElement>(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::AddAttributeElementArray<CDmElement>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v4; // esi

  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v4 = (Attribute->m_nFlags & 0x1F) != 15 ? nullptr : Attribute;
  else
    v4 = CDmElement::CreateAttribute(this, pAttributeName, type: AT_FIRST_ARRAY_TYPE);
  if ( v4 == nullptr )
    return nullptr;
  CDmAttribute::SetElementTypeSymbol(this: v4, typeSymbol: CDmElement::m_classType);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0045B700
// Name: public: class CUtlSymbolLarge const __near & CDmElement::GetValue<class CUtlSymbolLarge>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<CUtlSymbolLarge> *__thiscall CDmElement::GetValue<CUtlSymbolLarge>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal.m_Storage.u.m_Id = -1;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<CUtlSymbolLarge>(this: Attribute);
  else
    return &`CDmElement::GetValue<CUtlSymbolLarge>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x0045B820
// Name: public: class CDmElement __near * CDmElement::GetValueElement<class CDmElement>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmElement::GetValueElement<CDmElement>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmElement::m_classType.u) != 0 )
  {
    return (CDmElement *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474F70
// Name: public: class CDmeMakefile __near * CDmElement::GetValueElement<class CDmeMakefile>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeMakefile *__thiscall CDmElement::GetValueElement<CDmeMakefile>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeMakefile::m_classType.u) != 0 )
  {
    return (CDmeMakefile *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004789D0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<enum DmElementHandle_t,struct AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
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
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 92 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<enum DmElementHandle_t,AnimationControlAttributes_t,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047ACC0
// Name: public: class CDmeChannel __near * CDmElement::GetValueElement<class CDmeChannel>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeChannel *__thiscall CDmElement::GetValueElement<CDmeChannel>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeChannel::m_classType.u) != 0 )
  {
    return (CDmeChannel *)(v5 - 4);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00484330
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<int,class CUtlSymbolLarge,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CUtlSymbolLarge,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<ArrayItem_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<ArrayItem_t,unsigned short> *m_pMemory; // edx
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
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 16 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<ArrayItem_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                         this: _g_pMemAlloc,
                                                                         a2: m_pMemory,
                                                                         a3: v7);
    else
      this->m_pMemory = (UtlRBTreeNode_t<ArrayItem_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004851F0
// Name: public: unsigned short CUtlDict<class IAttributeWidgetFactory __near *,unsigned short>::Insert(char const __near *,class IAttributeWidgetFactory __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
        CUtlDict<IAttributeWidgetFactory *,unsigned short> *this,
        const char *pName,
        IAttributeWidgetFactory **element)
{
  char *v4; // eax
  IAttributeWidgetFactory *v5; // edx
  CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::Node_t insert; // [esp+8h] [ebp-8h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v4, pName);
  else
    v4 = nullptr;
  v5 = *element;
  insert.key = v4;
  insert.elem = v5;
  return CUtlRBTree<CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IAttributeWidgetFactory *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
           this: &this->m_Elements.m_Tree,
           &insert);
}

//------------------------------------------------------------------------------
// Address: 0x004882D0
// Name: public: class Quaternion const __near & CDmElement::GetValue<class Quaternion>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Quaternion> *__thiscall CDmElement::GetValue<Quaternion>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<Quaternion>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Quaternion>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.z = 0.0;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Quaternion>'::`2'::defaultVal.m_Storage.w = 1.0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return (CDmaVar<Quaternion> *)CDmAttribute::GetValue<Quaternion>(this: Attribute);
  else
    return &`CDmElement::GetValue<Quaternion>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00488340
// Name: public: class Vector const __near & CDmElement::GetValue<class Vector>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmElement::GetValue<Vector>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<Vector>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Vector>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.x = 0.0;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.y = 0.0;
    `CDmElement::GetValue<Vector>'::`2'::defaultVal.m_Storage.z = 0.0;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<Vector>(this: Attribute);
  else
    return &`CDmElement::GetValue<Vector>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x00494510
// Name: public: class CDmAttribute __near * CDmElement::SetValue<char const>(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<char const>(
        CDmElement *this,
        const char *pAttributeName,
        const char *pValue,
        char bCreateIfNotFound)
{
  CDmAttribute *Attribute; // esi

  if ( bCreateIfNotFound == 0 && !CDmElement::HasAttribute(this, pAttributeName, type: AT_STRING) )
    return nullptr;
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, char *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
    a1: g_pDataModel.u,
    a2: &bCreateIfNotFound,
    a3: pValue);
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
  {
    Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_STRING);
    if ( Attribute == nullptr )
      return nullptr;
  }
  CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&bCreateIfNotFound);
  return Attribute;
}

//------------------------------------------------------------------------------
// Address: 0x0049B370
// Name: public: class Color const __near & CDmElement::GetValue<class Color>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Color> *__thiscall CDmElement::GetValue<Color>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax

  if ( (`CDmElement::GetValue<Color>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<Color>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<Color>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<Color>'::`2'::defaultVal.m_Storage = (Color)-16777216;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    return CDmAttribute::GetValue<Color>(this: Attribute);
  else
    return &`CDmElement::GetValue<Color>'::`2'::defaultVal;
}

//------------------------------------------------------------------------------
// Address: 0x004A80D0
// Name: public: class CDmAttribute __near * CDmElement::InitValue<char const>(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::InitValue<char const>(
        CDmElement *this,
        const char *pAttributeName,
        const char *pValue)
{
  CDmAttribute *result; // eax
  CDmAttribute *Attribute; // esi

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 200))(
    a1: g_pDataModel.u,
    a2: &pValue,
    a3: pValue);
  result = CDmElement::FindAttribute(this, pAttributeName);
  if ( result == nullptr )
  {
    Attribute = CDmElement::FindAttribute(this, pAttributeName);
    if ( Attribute != nullptr
      || (Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_STRING)) != nullptr )
    {
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: Attribute, value: (const CUtlSymbolLarge *)&pValue);
      return Attribute;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A8450
// Name: public: class CDmAttribute __near * CDmElement::SetValue<class CDmElement>(char const __near *,class CDmElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<CDmElement>(
        CDmElement *this,
        const char *pAttributeName,
        DmElementHandle_t pElement,
        bool bCreateIfNotFound)
{
  CDmAttribute *Attribute; // esi

  if ( pElement != 0 )
    pElement = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pElement);
  else
    pElement = DMELEMENT_HANDLE_INVALID;
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
  {
    if ( !bCreateIfNotFound )
      return nullptr;
    Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_FIRST_VALUE_TYPE);
    if ( Attribute == nullptr )
      return nullptr;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: &pElement);
  return Attribute;
}

//------------------------------------------------------------------------------
// Address: 0x004AEBD0
// Name: public: void CUtlDict<class CDmElement __near *,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CDmElement *,int>::RemoveAll(CUtlDict<CDmElement *,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CDmElement *,int>::Node_t,int,CUtlMap<char const *,CDmElement *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CDmElement *,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x004B02E0
// Name: public: int CUtlDict<class CDmElement __near *,int>::Insert(char const __near *,class CDmElement __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<CDmElement *,int>::Insert(
        CUtlDict<CDmElement *,int> *this,
        char *pName,
        CDmElement *const *element)
{
  const char *v3; // edi
  char *v5; // eax

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  pName = v5;
  return CUtlMap<char const *,CDmElement *,int>::Insert(
           this: &this->m_Elements,
           key: (const char *const *)&pName,
           insert: element);
}

//------------------------------------------------------------------------------
// Address: 0x005178E0
// Name: public: class CDmeSequenceList __near * CDmElement::GetValueElement<class CDmeSequenceList>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeSequenceList *__thiscall CDmElement::GetValueElement<CDmeSequenceList>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeSequenceList::m_classType.u) != 0 )
  {
    return (CDmeSequenceList *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00524690
// Name: public: class CDmeLog __near * CDmElement::GetValueElement<class CDmeLog>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeLog *__thiscall CDmElement::GetValueElement<CDmeLog>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeLog::m_classType.u) != 0 )
  {
    return (CDmeLog *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005364A0
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<struct CUtlMap<char const __near *,class CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx

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
        m_nAllocationCount = 2;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D04E0
// Name: public: class CDmAttribute __near * CDmElement::SetValue<class CDmeCombinationOperator>(char const __near *,class CDmeCombinationOperator __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmElement::SetValue<CDmeCombinationOperator>(
        CDmElement *this,
        const char *pAttributeName,
        DmElementHandle_t pElement,
        bool bCreateIfNotFound)
{
  CDmAttribute *Attribute; // esi

  if ( pElement != 0 )
    pElement = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)(pElement + 4));
  else
    pElement = DMELEMENT_HANDLE_INVALID;
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute == nullptr )
  {
    if ( !bCreateIfNotFound )
      return nullptr;
    Attribute = CDmElement::CreateAttribute(this, pAttributeName, type: AT_FIRST_VALUE_TYPE);
    if ( Attribute == nullptr )
      return nullptr;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: Attribute, value: &pElement);
  return Attribute;
}

//------------------------------------------------------------------------------
// Address: 0x005D10E0
// Name: class CUtlBuffer __near & operator<<(class CUtlBuffer __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlBuffer *__cdecl operator<<(CUtlBuffer *b, const Vector *v)
{
  float src; // xmm0_4
  float y; // xmm0_4
  float z; // xmm0_4

  src = v->x;
  if ( (b->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: b, pFmt: "%f", src);
  else
    CUtlBuffer::PutTypeBin<float>(this: b, src);
  CUtlBuffer::PutString(this: b, pString: " ");
  y = v->y;
  if ( (b->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: b, pFmt: "%f", y);
  else
    CUtlBuffer::PutTypeBin<float>(this: b, src: y);
  CUtlBuffer::PutString(this: b, pString: " ");
  z = v->z;
  if ( (b->m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: b, pFmt: "%f", z);
  else
    CUtlBuffer::PutTypeBin<float>(this: b, src: z);
  return b;
}

//------------------------------------------------------------------------------
// Address: 0x005E11B0
// Name: public: class CDmeEditorAttributeInfo __near * CDmElement::GetValueElement<class CDmeEditorAttributeInfo>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeEditorAttributeInfo *__thiscall CDmElement::GetValueElement<CDmeEditorAttributeInfo>(
        CDmElement *this,
        const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeEditorAttributeInfo::m_classType.u) != 0 )
  {
    return (CDmeEditorAttributeInfo *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E1240
// Name: public: class CDmeEditorType __near * CDmElement::GetValueElement<class CDmeEditorType>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
CDmeEditorType *__thiscall CDmElement::GetValueElement<CDmeEditorType>(CDmElement *this, const char *pAttributeName)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<enum DmElementHandle_t> *v3; // eax
  int v4; // eax
  int v5; // esi

  if ( (`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_ElementType.u.m_Id = -1;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal.m_Storage.m_Handle = DMELEMENT_HANDLE_INVALID;
  }
  Attribute = CDmElement::FindAttribute(this, pAttributeName);
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<enum DmElementHandle_t>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<enum DmElementHandle_t>'::`2'::defaultVal;
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3->m_Storage.m_Handle);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeEditorType::m_classType.u) != 0 )
  {
    return (CDmeEditorType *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0060B410
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Button::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Button::GetMessageMap(vgui::Button *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Button::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Button::GetMessageMap'::`2'::s_pMap;
  `vgui::Button::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Button");
  `vgui::Button::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0060B450
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Button::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Button::GetKBMap(vgui::Button *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Button::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Button::GetKBMap'::`2'::s_pMap;
  `vgui::Button::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  `vgui::Button::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0062D4F0
// Name: public: unsigned short CUtlDict<class CUtlString,unsigned short>::Find(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<CUtlString,unsigned short>::Find(
        CUtlDict<CUtlString,unsigned short> *this,
        const char *pName)
{
  unsigned __int16 v3; // si
  CUtlMap<char const *,CUtlString,unsigned short>::Node_t search; // [esp+8h] [ebp-14h] BYREF

  if ( pName == nullptr )
    return -1;
  CUtlString::CUtlString(this: &search.elem);
  search.key = pName;
  v3 = CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_Elements.m_Tree,
         &search);
  search.elem.m_Storage.m_nActualLength = 0;
  if ( search.elem.m_Storage.m_Memory.m_nGrowSize >= 0 && search.elem.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.m_Storage.m_Memory.m_pMemory);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0062E8E0
// Name: public: void CUtlDict<class CUtlString,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<CUtlString,unsigned short>::RemoveAll(CUtlDict<CUtlString,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x0062EC30
// Name: public: unsigned short CUtlDict<class CUtlString,unsigned short>::Insert(char const __near *,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlDict<CUtlString,unsigned short>::Insert(
        CUtlDict<CUtlString,unsigned short> *this,
        const char *pName,
        const CUtlString *element)
{
  char *v4; // eax
  const char *v5; // esi
  unsigned __int16 v6; // si
  CUtlMap<char const *,CUtlString,unsigned short>::Node_t insert; // [esp+Ch] [ebp-14h] BYREF

  if ( pName != nullptr && (v4 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
  {
    strcpy(v4, pName);
    v5 = v4;
  }
  else
  {
    v5 = nullptr;
  }
  CUtlString::CUtlString(this: &insert.elem);
  insert.key = v5;
  CUtlString::operator=(this: &insert.elem, src: element);
  v6 = CUtlRBTree<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,CUtlString,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CUtlString,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
         this: &this->m_Elements.m_Tree,
         &insert);
  insert.elem.m_Storage.m_nActualLength = 0;
  if ( insert.elem.m_Storage.m_Memory.m_nGrowSize >= 0 && insert.elem.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: insert.elem.m_Storage.m_Memory.m_pMemory);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0062FA40
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::FileOpenStateMachine::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::FileOpenStateMachine::GetMessageMap(vgui::FileOpenStateMachine *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::FileOpenStateMachine::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::FileOpenStateMachine::GetMessageMap'::`2'::s_pMap;
  `vgui::FileOpenStateMachine::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "FileOpenStateMachine");
  `vgui::FileOpenStateMachine::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0062FA70
// Name: public: virtual struct PanelAnimationMap __near * vgui::FileOpenStateMachine::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::FileOpenStateMachine::GetAnimMap(vgui::FileOpenStateMachine *this)
{
  return FindOrAddPanelAnimationMap(className: "FileOpenStateMachine");
}

//------------------------------------------------------------------------------
// Address: 0x0062FA80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::FileOpenStateMachine::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::FileOpenStateMachine::GetKBMap(vgui::FileOpenStateMachine *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::FileOpenStateMachine::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::FileOpenStateMachine::GetKBMap'::`2'::s_pMap;
  `vgui::FileOpenStateMachine::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "FileOpenStateMachine");
  `vgui::FileOpenStateMachine::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00630EA0
// Name: public: virtual class vgui::Panel __near * vgui::Label::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Label *__thiscall vgui::Label::HasHotkey(vgui::Label *this, wchar_t key)
{
  unsigned __int16 v2; // si

  v2 = key;
  if ( iswalnum(c: key) != 0 )
    v2 = towlower(c: key);
  return this->_hotkey != v2 ? nullptr : this;
}

//------------------------------------------------------------------------------
// Address: 0x00632420
// Name: public: virtual class vgui::IImage __near * vgui::Label::GetImageAtIndex(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::Label::GetImageAtIndex(vgui::Label *this, int index)
{
  if ( index < 0 || index >= this->_imageDar.m_Size )
    return nullptr;
  else
    return this->_imageDar.m_Memory.m_pMemory[index].image;
}

//------------------------------------------------------------------------------
// Address: 0x00632950
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Label::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Label::GetMessageMap(vgui::Label *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Label::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Label::GetMessageMap'::`2'::s_pMap;
  `vgui::Label::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Label");
  `vgui::Label::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00632980
// Name: public: virtual struct PanelAnimationMap __near * vgui::Label::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Label::GetAnimMap(vgui::Label *this)
{
  return FindOrAddPanelAnimationMap(className: "Label");
}

//------------------------------------------------------------------------------
// Address: 0x00632990
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Label::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Label::GetKBMap(vgui::Label *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Label::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Label::GetKBMap'::`2'::s_pMap;
  `vgui::Label::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  `vgui::Label::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00637930
// Name: public: class vgui::Menu __near * vgui::MenuButton::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuButton::GetMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu;
}

//------------------------------------------------------------------------------
// Address: 0x00637960
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuButton::GetMessageMap(vgui::MenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
  `vgui::MenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00637990
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuButton::GetAnimMap(vgui::MenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x006379A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuButton::GetKBMap(vgui::MenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetKBMap'::`2'::s_pMap;
  `vgui::MenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
  `vgui::MenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00639150
// Name: protected: virtual class vgui::IBorder __near * vgui::Button::GetBorder(bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall vgui::Button::GetBorder(
        vgui::Button *this,
        bool depressed,
        bool armed,
        bool selected,
        bool keyfocus)
{
  if ( (this->_buttonFlags.m_nFlags & 8) != 0 )
  {
    if ( depressed )
      return this->_depressedBorder;
    if ( keyfocus || this->IsEnabled(this) && (this->_buttonFlags.m_nFlags & 0x40) != 0 )
      return this->_keyFocusBorder;
  }
  else if ( depressed )
  {
    return this->_depressedBorder;
  }
  return this->_defaultBorder;
}

//------------------------------------------------------------------------------
// Address: 0x006A5770
// Name: public: int CUtlStack<float,class CUtlMemory<float,int>>::Push(float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlStack<float,CUtlMemory<float,int>>::Push(CUtlStack<float,CUtlMemory<float,int> > *this, float *src)
{
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v5; // eax

  if ( this->m_Size >= this->m_Memory.m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  m_Size = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = *src;
  return this->m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x006AAF50
// Name: _dynamic_initializer_for__CDmElement::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmElement::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmElement::s_Allocator,
    blockSize: 68,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmElement pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmElement::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B36B0
// Name: _dynamic_atexit_destructor_for__CDmElement::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmElement::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmElement::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004036D0
// Name: class CDmeModel __near * CastElement<class CDmeModel>(class CDmElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeModel *__cdecl CastElement<CDmeModel>(CDmElement *pElement)
{
  if ( pElement != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pElement->IsA)(
         a1: pElement,
         a2: (CUtlSymbolLarge)CDmeModel::m_classType.u.m_Id) )
  {
    return (CDmeModel *)pElement;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403E60
// Name: class CDmeMesh __near * CreateElement<class CDmeMesh>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMesh *__cdecl CreateElement<CDmeMesh>(const char *pObjectName, DmFileId_t fileid, const UniqueId_t *pObjectID)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, const UniqueId_t *))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeMesh::m_classType.u,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeMesh::m_classType.u) != 0 )
  {
    return (CDmeMesh *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403F70
// Name: class CDmeDag __near * CreateElement<class CDmeDag>(char const __near *,enum DmFileId_t,struct UniqueId_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDag *__cdecl CreateElement<CDmeDag>(const char *pObjectName, DmFileId_t fileid, const UniqueId_t *pObjectID)
{
  int v3; // eax
  int v4; // eax
  int v5; // esi

  v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge::<unnamed_type_u>, const char *, DmFileId_t, const UniqueId_t *))(*(_DWORD *)g_pDataModel.u.m_Id + 64))(
         a1: g_pDataModel.u,
         a2: CDmeDag::m_classType.u,
         a3: pObjectName,
         a4: fileid,
         a5: pObjectID);
  v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v3);
  v5 = v4;
  if ( v4 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
         a1: v4,
         a2: CDmeDag::m_classType.u) != 0 )
  {
    return (CDmeDag *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006AAF80
// Name: _dynamic_initializer_for__g_CDmElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmElement_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmElement_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AAF90
// Name: _dynamic_initializer_for__g_CDmElement_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmElement_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmElement_Helper,
           classname: "DmElement",
           pFactory: &g_CDmElement_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AAFB0
// Name: _dynamic_initializer_for__g_CDmeElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeElement_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeElement_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AAFC0
// Name: _dynamic_initializer_for__g_CDmeElement_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeElement_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeElement_Helper,
           classname: "DmeElement",
           pFactory: &g_CDmeElement_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006AAFE0
// Name: _dynamic_initializer_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DmElementFramework__()
{
  CDependencyGraph::CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
  g_DmElementFramework.m_dirtyElements.m_Memory.m_pMemory = nullptr;
  g_DmElementFramework.m_dirtyElements.m_Memory.m_nAllocationCount = 256;
  g_DmElementFramework.m_dirtyElements.m_Memory.m_nGrowSize = 128;
  g_DmElementFramework.m_dirtyElements.m_Memory.m_pMemory = (DmElementHandle_t *)_g_pMemAlloc->Alloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: 1024);
  g_DmElementFramework.m_dirtyElements.m_Size = 0;
  g_DmElementFramework.m_dirtyElements.m_pElements = g_DmElementFramework.m_dirtyElements.m_Memory.m_pMemory;
  g_DmElementFramework.m_phase = PH_EDIT;
  return atexit(func: dynamic_atexit_destructor_for__g_DmElementFramework__);
}

//------------------------------------------------------------------------------
// Address: 0x006AB050
// Name: _dynamic_initializer_for__g_KeyValues2ErrorStack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValues2ErrorStack__()
{
  memset(&g_KeyValues2ErrorStack, 0xFFu, 0x100u);
  g_KeyValues2ErrorStack.m_pFilename = "NULL";
  g_KeyValues2ErrorStack.m_nFileLine = 1;
  g_KeyValues2ErrorStack.m_errorIndex = 0;
  g_KeyValues2ErrorStack.m_maxErrorIndex = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x006AB090
// Name: _dynamic_initializer_for__s_DMSerializerKeyValues2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMSerializerKeyValues2__()
{
  CDmElementDictionary::CDmElementDictionary(this: &s_DMSerializerKeyValues2.m_ElementDict);
  s_DMSerializerKeyValues2.m_bFlatMode = false;
  return atexit(func: dynamic_atexit_destructor_for__s_DMSerializerKeyValues2__);
}

//------------------------------------------------------------------------------
// Address: 0x006AB0B0
// Name: _dynamic_initializer_for__s_DMSerializerKeyValues2Flat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMSerializerKeyValues2Flat__()
{
  CDmElementDictionary::CDmElementDictionary(this: &s_DMSerializerKeyValues2Flat.m_ElementDict);
  s_DMSerializerKeyValues2Flat.m_bFlatMode = true;
  return atexit(func: dynamic_atexit_destructor_for__s_DMSerializerKeyValues2Flat__);
}

//------------------------------------------------------------------------------
// Address: 0x006AB0D0
// Name: _dynamic_initializer_for__s_DMSerializerKeyValues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMSerializerKeyValues__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_DMSerializerKeyValues__);
}

//------------------------------------------------------------------------------
// Address: 0x006AB0E0
// Name: _dynamic_initializer_for__g_AttrNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AttrNodePool__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_AttrNodePool,
    blockSize: 28,
    numElements: 1000,
    growMode: 1,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_AttrNodePool__);
}

//------------------------------------------------------------------------------
// Address: 0x006AB110
// Name: _dynamic_initializer_for__g_OperatorNodePool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_OperatorNodePool__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &g_OperatorNodePool,
    blockSize: 32,
    numElements: 1000,
    growMode: 1,
    pszAllocOwner: nullptr,
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__g_OperatorNodePool__);
}

//------------------------------------------------------------------------------
// Address: 0x006AB140
// Name: _dynamic_initializer_for__g_CDmeDagEditPanel_DmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeDagEditPanel_DmeDag_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeDagEditPanel_DmeDag_Factory,
             pElementType: "DmeDag",
             pEditorName: "DmeDagPreview2",
             pEditorDisplayName: "DmeDag Previewer 2",
             bIsDefault: false,
             bIsOverride: false);
  g_CDmeDagEditPanel_DmeDag_Factory.__vftable = (CDmePanelFactory<CDmeDagEditPanel,CDmeDag>_vtbl *)&CDmePanelFactory<CDmeDagEditPanel,CDmeDag>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006AB170
// Name: _dynamic_initializer_for__g_CDmeDagEditPanel_DmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeDagEditPanel_DmeSourceSkin_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeDagEditPanel_DmeSourceSkin_Factory,
             pElementType: "DmeSourceSkin",
             pEditorName: "DmeSourceSkinPreview2",
             pEditorDisplayName: "MDL Skin Previewer 2",
             bIsDefault: false,
             bIsOverride: false);
  g_CDmeDagEditPanel_DmeSourceSkin_Factory.__vftable = (CDmePanelFactory<CDmeDagEditPanel,CDmeSourceSkin>_vtbl *)&CDmePanelFactory<CDmeDagEditPanel,CDmeSourceSkin>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006AB1A0
// Name: _dynamic_initializer_for__g_CDmeDagEditPanel_DmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeDagEditPanel_DmeSourceAnimation_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeDagEditPanel_DmeSourceAnimation_Factory,
             pElementType: "DmeSourceAnimation",
             pEditorName: "DmeSourceAnimationPreview2",
             pEditorDisplayName: "MDL Animation Previewer 2",
             bIsDefault: false,
             bIsOverride: false);
  g_CDmeDagEditPanel_DmeSourceAnimation_Factory.__vftable = (CDmePanelFactory<CDmeDagEditPanel,CDmeSourceAnimation>_vtbl *)&CDmePanelFactory<CDmeDagEditPanel,CDmeSourceAnimation>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006AB1D0
// Name: _dynamic_initializer_for__g_CDmeDagEditPanel_DmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeDagEditPanel_DmeDCCMakefile_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeDagEditPanel_DmeDCCMakefile_Factory,
             pElementType: "DmeDCCMakefile",
             pEditorName: "DmeMakeFileOutputPreview2",
             pEditorDisplayName: "DCC MakeFile Output Previewer 2",
             bIsDefault: false,
             bIsOverride: false);
  g_CDmeDagEditPanel_DmeDCCMakefile_Factory.__vftable = (CDmePanelFactory<CDmeDagEditPanel,CDmeDCCMakefile>_vtbl *)&CDmePanelFactory<CDmeDagEditPanel,CDmeDCCMakefile>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006AB200
// Name: _dynamic_initializer_for__dme_properties_maxsearchresults__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__dme_properties_maxsearchresults__()
{
  ConVar::ConVar(
    this: &dme_properties_maxsearchresults,
    pName: "dme_properties_maxsearchresults",
    pDefaultValue: "50",
    flags: 0,
    pHelpString: "Max number of search results to track.");
  return atexit(func: dynamic_atexit_destructor_for__dme_properties_maxsearchresults__);
}

//------------------------------------------------------------------------------
// Address: 0x006AB230
// Name: _dynamic_initializer_for__g_CDmeElementPanel_DmElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeElementPanel_DmElement_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeElementPanel_DmElement_Factory,
             pElementType: "DmElement",
             pEditorName: "DmeElementDefault",
             pEditorDisplayName: "Dme Element Editor",
             bIsDefault: true,
             bIsOverride: false);
  g_CDmeElementPanel_DmElement_Factory.__vftable = (CDmePanelFactory<CDmeElementPanel,CDmElement>_vtbl *)&CDmePanelFactory<CDmeElementPanel,CDmElement>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006AB260
// Name: _dynamic_initializer_for__g_CDmeCombinationSystemEditorPanel_DmeCombinationOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeCombinationSystemEditorPanel_DmeCombinationOperator_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeCombinationSystemEditorPanel_DmeCombinationOperator_Factory,
             pElementType: "DmeCombinationOperator",
             pEditorName: "DmeCombinationOperatorEditor",
             pEditorDisplayName: "Combination Operator Editor",
             bIsDefault: true,
             bIsOverride: false);
  g_CDmeCombinationSystemEditorPanel_DmeCombinationOperator_Factory.__vftable = (CDmePanelFactory<CDmeCombinationSystemEditorPanel,CDmeCombinationOperator>_vtbl *)&CDmePanelFactory<CDmeCombinationSystemEditorPanel,CDmeCombinationOperator>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006AB290
// Name: _dynamic_initializer_for__g_CAssetBuilder_DmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CAssetBuilder_DmeMakefile_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CAssetBuilder_DmeMakefile_Factory,
             pElementType: "DmeMakefile",
             pEditorName: "DmeMakeFileDefault",
             pEditorDisplayName: "MakeFile Editor",
             bIsDefault: true,
             bIsOverride: false);
  g_CAssetBuilder_DmeMakefile_Factory.__vftable = (CDmePanelFactory<CAssetBuilder,CDmeMakefile>_vtbl *)&CDmePanelFactory<CAssetBuilder,CDmeMakefile>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006AB2C0
// Name: _dynamic_initializer_for__s_AssetTypes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_AssetTypes__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_AssetTypes__);
}

//------------------------------------------------------------------------------
// Address: 0x006AB2D0
// Name: _dynamic_initializer_for__SelectionInfo_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__SelectionInfo_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &SelectionInfo_t::s_Allocator,
    blockSize: 12,
    numElements: 256,
    growMode: 2,
    pszAllocOwner: "SelectionInfo_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__SelectionInfo_t::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AB300
// Name: _dynamic_initializer_for__g_CDmeDagRenderPanel_DmeDag_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeDagRenderPanel_DmeDag_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeDagRenderPanel_DmeDag_Factory,
             pElementType: "DmeDag",
             pEditorName: "DmeDagRenderer",
             pEditorDisplayName: "DmeDag Preview Renderer",
             bIsDefault: false,
             bIsOverride: false);
  g_CDmeDagRenderPanel_DmeDag_Factory.__vftable = (CDmePanelFactory<CDmeDagRenderPanel,CDmeDag>_vtbl *)&CDmePanelFactory<CDmeDagRenderPanel,CDmeDag>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006AB330
// Name: _dynamic_initializer_for__g_CDmeDagRenderPanel_DmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeDagRenderPanel_DmeSourceSkin_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeDagRenderPanel_DmeSourceSkin_Factory,
             pElementType: "DmeSourceSkin",
             pEditorName: "DmeSourceSkinPreview",
             pEditorDisplayName: "MDL Skin Previewer",
             bIsDefault: false,
             bIsOverride: false);
  g_CDmeDagRenderPanel_DmeSourceSkin_Factory.__vftable = (CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceSkin>_vtbl *)&CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceSkin>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006AB360
// Name: _dynamic_initializer_for__g_CDmeDagRenderPanel_DmeSourceAnimation_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeDagRenderPanel_DmeSourceAnimation_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeDagRenderPanel_DmeSourceAnimation_Factory,
             pElementType: "DmeSourceAnimation",
             pEditorName: "DmeSourceAnimationPreview",
             pEditorDisplayName: "MDL Animation Previewer",
             bIsDefault: false,
             bIsOverride: false);
  g_CDmeDagRenderPanel_DmeSourceAnimation_Factory.__vftable = (CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceAnimation>_vtbl *)&CDmePanelFactory<CDmeDagRenderPanel,CDmeSourceAnimation>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006AB390
// Name: _dynamic_initializer_for__g_CDmeDagRenderPanel_DmeDCCMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeDagRenderPanel_DmeDCCMakefile_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeDagRenderPanel_DmeDCCMakefile_Factory,
             pElementType: "DmeDCCMakefile",
             pEditorName: "DmeMakeFileOutputPreview",
             pEditorDisplayName: "DCC MakeFile Output Preview",
             bIsDefault: false,
             bIsOverride: false);
  g_CDmeDagRenderPanel_DmeDCCMakefile_Factory.__vftable = (CDmePanelFactory<CDmeDagRenderPanel,CDmeDCCMakefile>_vtbl *)&CDmePanelFactory<CDmeDagRenderPanel,CDmeDCCMakefile>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006AB3C0
// Name: _dynamic_initializer_for__g_CDmeElementPanel_DmElementPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeElementPanel *dynamic_initializer_for__g_CDmeElementPanel_DmElementPullInModule__()
{
  g_CDmeElementPanel_DmElementPullInModule = g_CDmeElementPanel_DmElementLinkerHack;
  return g_CDmeElementPanel_DmElementLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x006AB3D0
// Name: _dynamic_initializer_for__g_CDmeSourceSkinPanel_DmeSourceSkinPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceSkinPanel *dynamic_initializer_for__g_CDmeSourceSkinPanel_DmeSourceSkinPullInModule__()
{
  g_CDmeSourceSkinPanel_DmeSourceSkinPullInModule = g_CDmeSourceSkinPanel_DmeSourceSkinLinkerHack;
  return g_CDmeSourceSkinPanel_DmeSourceSkinLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x006AB3E0
// Name: _dynamic_initializer_for__g_CAssetBuilder_DmeMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAssetBuilder *dynamic_initializer_for__g_CAssetBuilder_DmeMakefilePullInModule__()
{
  g_CAssetBuilder_DmeMakefilePullInModule = g_CAssetBuilder_DmeMakefileLinkerHack;
  return g_CAssetBuilder_DmeMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x006AB3F0
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFilePanel_DmeSourceDCCFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceDCCFilePanel *dynamic_initializer_for__g_CDmeSourceDCCFilePanel_DmeSourceDCCFilePullInModule__()
{
  g_CDmeSourceDCCFilePanel_DmeSourceDCCFilePullInModule = g_CDmeSourceDCCFilePanel_DmeSourceDCCFileLinkerHack;
  return g_CDmeSourceDCCFilePanel_DmeSourceDCCFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x006AB400
// Name: _dynamic_initializer_for__g_CDmeDagRenderPanel_DmeDagPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDagRenderPanel *dynamic_initializer_for__g_CDmeDagRenderPanel_DmeDagPullInModule__()
{
  g_CDmeDagRenderPanel_DmeDagPullInModule = g_CDmeDagRenderPanel_DmeDagLinkerHack;
  return g_CDmeDagRenderPanel_DmeDagLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x006AB410
// Name: _dynamic_initializer_for__g_CDmeDagRenderPanel_DmeSourceAnimationPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDagRenderPanel *dynamic_initializer_for__g_CDmeDagRenderPanel_DmeSourceAnimationPullInModule__()
{
  g_CDmeDagRenderPanel_DmeSourceAnimationPullInModule = g_CDmeDagRenderPanel_DmeSourceAnimationLinkerHack;
  return g_CDmeDagRenderPanel_DmeSourceAnimationLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x006AB420
// Name: _dynamic_initializer_for__g_CDmeDagRenderPanel_DmeSourceSkinPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDagRenderPanel *dynamic_initializer_for__g_CDmeDagRenderPanel_DmeSourceSkinPullInModule__()
{
  g_CDmeDagRenderPanel_DmeSourceSkinPullInModule = g_CDmeDagRenderPanel_DmeSourceSkinLinkerHack;
  return g_CDmeDagRenderPanel_DmeSourceSkinLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x006AB430
// Name: _dynamic_initializer_for__g_CDmeDagRenderPanel_DmeDCCMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDagRenderPanel *dynamic_initializer_for__g_CDmeDagRenderPanel_DmeDCCMakefilePullInModule__()
{
  g_CDmeDagRenderPanel_DmeDCCMakefilePullInModule = g_CDmeDagRenderPanel_DmeDCCMakefileLinkerHack;
  return g_CDmeDagRenderPanel_DmeDCCMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x006AB440
// Name: _dynamic_initializer_for__g_CDmeDagEditPanel_DmeDagPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDagEditPanel *dynamic_initializer_for__g_CDmeDagEditPanel_DmeDagPullInModule__()
{
  g_CDmeDagEditPanel_DmeDagPullInModule = g_CDmeDagEditPanel_DmeDagLinkerHack;
  return g_CDmeDagEditPanel_DmeDagLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x006AB450
// Name: _dynamic_initializer_for__g_CDmeDagEditPanel_DmeSourceAnimationPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDagEditPanel *dynamic_initializer_for__g_CDmeDagEditPanel_DmeSourceAnimationPullInModule__()
{
  g_CDmeDagEditPanel_DmeSourceAnimationPullInModule = g_CDmeDagEditPanel_DmeSourceAnimationLinkerHack;
  return g_CDmeDagEditPanel_DmeSourceAnimationLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x006AB460
// Name: _dynamic_initializer_for__g_CDmeDagEditPanel_DmeSourceSkinPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDagEditPanel *dynamic_initializer_for__g_CDmeDagEditPanel_DmeSourceSkinPullInModule__()
{
  g_CDmeDagEditPanel_DmeSourceSkinPullInModule = g_CDmeDagEditPanel_DmeSourceSkinLinkerHack;
  return g_CDmeDagEditPanel_DmeSourceSkinLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x006AB470
// Name: _dynamic_initializer_for__g_CDmeDagEditPanel_DmeDCCMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDagEditPanel *dynamic_initializer_for__g_CDmeDagEditPanel_DmeDCCMakefilePullInModule__()
{
  g_CDmeDagEditPanel_DmeDCCMakefilePullInModule = g_CDmeDagEditPanel_DmeDCCMakefileLinkerHack;
  return g_CDmeDagEditPanel_DmeDCCMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x006AB480
// Name: _dynamic_initializer_for__g_CDmeMDLPanel_DmeMDLMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMDLPanel *dynamic_initializer_for__g_CDmeMDLPanel_DmeMDLMakefilePullInModule__()
{
  g_CDmeMDLPanel_DmeMDLMakefilePullInModule = g_CDmeMDLPanel_DmeMDLMakefileLinkerHack;
  return g_CDmeMDLPanel_DmeMDLMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x006AB490
// Name: _dynamic_initializer_for__g_AttributeTextWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeTextWidgetFactory__(IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeTextWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(this: &v1->m_Factories, pName: "text", &element);
}

//------------------------------------------------------------------------------
// Address: 0x006AB4E0
// Name: _dynamic_initializer_for__g_AttributeBooleanWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeBooleanWidgetFactory__(IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeBooleanWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(this: &v1->m_Factories, pName: "boolean", &element);
}

//------------------------------------------------------------------------------
// Address: 0x006AB530
// Name: _dynamic_initializer_for__g_AttributeFilePickerWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeFilePickerWidgetFactory__(
        IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeFilePickerWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "filepicker",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006AB580
// Name: _dynamic_initializer_for__g_AttributeBoolChoiceWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeBoolChoiceWidgetFactory__(
        IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeBoolChoiceWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "boolchoice",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006AB5D0
// Name: _dynamic_initializer_for__g_AttributeIntChoiceWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeIntChoiceWidgetFactory__(IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeIntChoiceWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "intchoice",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006AB620
// Name: _dynamic_initializer_for__g_AttributeStringChoiceWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeStringChoiceWidgetFactory__(
        IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeStringChoiceWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "stringchoice",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006AB670
// Name: _dynamic_initializer_for__g_AttributeElementWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeElementWidgetFactory__(IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeElementWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(this: &v1->m_Factories, pName: "element", &element);
}

//------------------------------------------------------------------------------
// Address: 0x006AB6C0
// Name: _dynamic_initializer_for__g_AttributeElementPickerWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeElementPickerWidgetFactory__(
        IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeElementPickerWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "elementchoice",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006AB710
// Name: _dynamic_initializer_for__g_AttributeMDLPickerWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeMDLPickerWidgetFactory__(IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeMDLPickerWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "mdlpicker",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006AB760
// Name: _dynamic_initializer_for__g_AttributeSequencePickerWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeSequencePickerWidgetFactory__(
        IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeSequencePickerWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "sequencepicker",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006AB7B0
// Name: _dynamic_initializer_for__g_AttributeSoundPickerWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeSoundPickerWidgetFactory__(
        IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeSoundPickerWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "soundpicker",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006AB800
// Name: _dynamic_initializer_for__g_AttributeBspPickerWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeBspPickerWidgetFactory__(IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeBspPickerWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "bsppicker",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006AB850
// Name: _dynamic_initializer_for__g_AttributeVmtPickerWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeVmtPickerWidgetFactory__(IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeVmtPickerWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "vmtpicker",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006AB8A0
// Name: _dynamic_initializer_for__g_AttributeVtfPickerWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeVtfPickerWidgetFactory__(IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeVtfPickerWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "vtfpicker",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006AB8F0
// Name: _dynamic_initializer_for__g_AttributeTgaPickerWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeTgaPickerWidgetFactory__(IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeTgaPickerWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "tgapicker",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006AB940
// Name: _dynamic_initializer_for__g_AttributeShaderPickerWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeShaderPickerWidgetFactory__(
        IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeShaderPickerWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "shaderpicker",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006AB990
// Name: _dynamic_initializer_for__g_AttributeSurfacePropertyPickerWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeSurfacePropertyPickerWidgetFactory__(
        IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeSurfacePropertyPickerWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "surfacepropertypicker",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006AB9E0
// Name: _dynamic_initializer_for__g_AttributeColorPickerWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeColorPickerWidgetFactory__(
        IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeColorPickerWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "colorpicker",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006ABA30
// Name: _dynamic_initializer_for__g_AttributeAviPickerWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeAviPickerWidgetFactory__(IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeAviPickerWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "avipicker",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006ABA80
// Name: _dynamic_initializer_for__g_AttributeShtPickerWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeShtPickerWidgetFactory__(IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeShtPickerWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "shtpicker",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006ABAD0
// Name: _dynamic_initializer_for__g_AttributeDetailTypePickerWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeDetailTypePickerWidgetFactory__(
        IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeDetailTypePickerWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "detailtypepicker",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006ABB20
// Name: _dynamic_initializer_for__g_AttributeRawPickerWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeRawPickerWidgetFactory__(IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeRawPickerWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "rawpicker",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006ABB70
// Name: _dynamic_initializer_for__g_AttributeInterpolatorChoiceWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeInterpolatorChoiceWidgetFactory__(
        IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeInterpolatorChoiceWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "interpolatorchoice",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006ABBC0
// Name: _dynamic_initializer_for__g_AttributeSheetSequencePickerWidgetFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeSheetSequencePickerWidgetFactory__(
        IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeSheetSequencePickerWidgetFactory;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "sheetsequencepicker",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006ABC10
// Name: _dynamic_initializer_for__g_AttributeSheetSequencePickerWidgetFactorySecond__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __thiscall dynamic_initializer_for__g_AttributeSheetSequencePickerWidgetFactorySecond__(
        IAttributeWidgetFactory *this)
{
  CAttributeWidgetFactoryList *v1; // eax
  CAttributeWidgetFactoryList *v2; // eax
  IAttributeWidgetFactory *element; // [esp+0h] [ebp-4h] BYREF

  element = this;
  v1 = g_pWidgetFactoryFactoryList;
  if ( g_pWidgetFactoryFactoryList == nullptr )
  {
    v2 = (CAttributeWidgetFactoryList *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v2 != nullptr )
      v1 = CAttributeWidgetFactoryList::CAttributeWidgetFactoryList(this: v2);
    else
      v1 = nullptr;
    g_pWidgetFactoryFactoryList = v1;
    attributewidgetfactorylist = v1;
  }
  element = &g_AttributeSheetSequencePickerWidgetFactorySecond;
  return CUtlDict<IAttributeWidgetFactory *,unsigned short>::Insert(
           this: &v1->m_Factories,
           pName: "sheetsequencepicker_second",
           &element);
}

//------------------------------------------------------------------------------
// Address: 0x006ABC60
// Name: _dynamic_initializer_for__ifm_attributeslider_sensitivity__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ifm_attributeslider_sensitivity__()
{
  ConVar::ConVar(
    this: &ifm_attributeslider_sensitivity,
    pName: "ifm_attributeslider_sensitivity",
    pDefaultValue: "3.0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ifm_attributeslider_sensitivity__);
}

//------------------------------------------------------------------------------
// Address: 0x006ABC90
// Name: _dynamic_initializer_for__ifm_attributeslider_legacy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ifm_attributeslider_legacy__()
{
  ConVar::ConVar(
    this: &ifm_attributeslider_legacy,
    pName: "ifm_attributeslider_legacy",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Uses old style slider dragging.");
  return atexit(func: dynamic_atexit_destructor_for__ifm_attributeslider_legacy__);
}

//------------------------------------------------------------------------------
// Address: 0x006ABCC0
// Name: _dynamic_initializer_for__ifm_threaded_updatecontrolvalues__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ifm_threaded_updatecontrolvalues__()
{
  ConVar::ConVar(
    this: &ifm_threaded_updatecontrolvalues,
    pName: "ifm_threaded_updatecontrolvalues",
    pDefaultValue: "1",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ifm_threaded_updatecontrolvalues__);
}

//------------------------------------------------------------------------------
// Address: 0x006ABCF0
// Name: _dynamic_initializer_for__g_CDmeSourceSkinPanel_DmeSourceSkin_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeSourceSkinPanel_DmeSourceSkin_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeSourceSkinPanel_DmeSourceSkin_Factory,
             pElementType: "DmeSourceSkin",
             pEditorName: "DmeSourceSkinDefault",
             pEditorDisplayName: "MDL Skin Editor",
             bIsDefault: true,
             bIsOverride: false);
  g_CDmeSourceSkinPanel_DmeSourceSkin_Factory.__vftable = (CDmePanelFactory<CDmeSourceSkinPanel,CDmeSourceSkin>_vtbl *)&CDmePanelFactory<CDmeSourceSkinPanel,CDmeSourceSkin>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006ABD20
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFilePanel_DmeSourceDCCFile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeSourceDCCFilePanel_DmeSourceDCCFile_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeSourceDCCFilePanel_DmeSourceDCCFile_Factory,
             pElementType: "DmeSourceDCCFile",
             pEditorName: "DmeSourceDCCFileDefault",
             pEditorDisplayName: "Maya/XSI Source File Editor",
             bIsDefault: true,
             bIsOverride: false);
  g_CDmeSourceDCCFilePanel_DmeSourceDCCFile_Factory.__vftable = (CDmePanelFactory<CDmeSourceDCCFilePanel,CDmeSourceDCCFile>_vtbl *)&CDmePanelFactory<CDmeSourceDCCFilePanel,CDmeSourceDCCFile>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006ABD50
// Name: _dynamic_initializer_for__g_CDmeMDLPanel_DmeMDLMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseDmePanelFactory *dynamic_initializer_for__g_CDmeMDLPanel_DmeMDLMakefile_Factory__()
{
  CBaseDmePanelFactory *result; // eax

  result = CBaseDmePanelFactory::CBaseDmePanelFactory(
             this: &g_CDmeMDLPanel_DmeMDLMakefile_Factory,
             pElementType: "DmeMDLMakefile",
             pEditorName: "DmeMakeFileOutputPreview",
             pEditorDisplayName: "MDL MakeFile Output Preview",
             bIsDefault: false,
             bIsOverride: false);
  g_CDmeMDLPanel_DmeMDLMakefile_Factory.__vftable = (CDmePanelFactory<CDmeMDLPanel,CDmeMDLMakefile>_vtbl *)&CDmePanelFactory<CDmeMDLPanel,CDmeMDLMakefile>::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006B3690
// Name: _dynamic_atexit_destructor_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataModel__()
{
  CDataModel::~CDataModel(this: &g_DataModel);
}

//------------------------------------------------------------------------------
// Address: 0x006B36A0
// Name: _dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &DmAttributeList_t::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B36C0
// Name: _dynamic_atexit_destructor_for__g_CDmeElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeElement_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeElement_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B36D0
// Name: _dynamic_atexit_destructor_for__g_CDmElement_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmElement_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmElement_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B36E0
// Name: _dynamic_atexit_destructor_for__g_DmElementFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DmElementFramework__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_DmElementFramework.m_dirtyElements);
  CDependencyGraph::~CDependencyGraph(this: &g_DmElementFramework.m_dependencyGraph);
}
