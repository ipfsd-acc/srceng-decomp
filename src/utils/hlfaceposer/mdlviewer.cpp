// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/mdlviewer.cpp
// Functions: 62
// ============================================================

#include "utils\hlfaceposer\mdlviewer.h"

//------------------------------------------------------------------------------
// Address: 0x00460310
// Name: int LoadFile(char const __near *,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LoadFile(const char *filename, void **bufferptr)
{
  void *v2; // edi
  int v3; // esi
  _BYTE *v4; // ebx
  const char *v6; // [esp+0h] [ebp-Ch]

  v2 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: filename, a3: "rb", a4: 0);
  v3 = filesystem->Size_2(this: &filesystem->IBaseFileSystem, a2: v2);
  v4 = operator new(nSize: v3 + 1);
  v4[v3] = 0;
  if ( filesystem->Read(this: &filesystem->IBaseFileSystem, a2: v4, a3: v3, a4: v2) != v3 )
    _Error(this: (ISceneTokenProcessor *)&stru_4F43D4, a2: v6);
  filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v2);
  *bufferptr = v4;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x004603A0
// Name: char __near * ExpandPath(char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ExpandPath(char *path)
{
  char *result; // eax

  result = path;
  if ( *path != 47 && *path != 92 && path[1] != 58 )
  {
    V_snprintf(pDest: full, maxLen: 1024, pFormat: "%s%s", gamedir, path);
    return full;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004603E0
// Name: void LoadFileSystemDialogModule(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadFileSystemDialogModule()
{
  struct CSysModule *Module; // eax
  void *(__cdecl *Factory)(const char *, int *); // eax

  Module = Sys_LoadModule(pModuleName: "FileSystemOpenDialog.dll");
  g_pFSDialogModule = Module;
  if ( Module != nullptr )
  {
    Factory = Sys_GetFactory(pModule: Module);
    g_FSDialogFactory = Factory;
    if ( g_pFSDialogModule != nullptr && Factory == nullptr )
    {
      Sys_UnloadModule(pModule: g_pFSDialogModule);
      g_pFSDialogModule = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460430
// Name: private: void MDLViewer::initRecentFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::initRecentFiles(MDLViewer *this)
{
  int v2; // esi
  const char *v3; // edi
  unsigned int v4; // kr00_4
  mxMenuBar *d_MatSysWindow; // ecx
  int i; // [esp+10h] [ebp-4h]

  v2 = 1008;
  v3 = recentFiles[0];
  for ( i = 8; i != 0; --i )
  {
    v4 = strlen(v3);
    d_MatSysWindow = (mxMenuBar *)this->d_MatSysWindow;
    if ( v4 != 0 )
    {
      mxMenuBar::modify(this: d_MatSysWindow, id: v2, newId: v2, newItem: v3);
    }
    else
    {
      mxMenuBar::modify(this: d_MatSysWindow, id: v2, newId: v2, newItem: "(empty)");
      mxMenu::setEnabled(this: (mxMenuBar *)this->d_MatSysWindow, id: v2, b: false);
    }
    v3 += 256;
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004604A0
// Name: private: void MDLViewer::loadRecentFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::loadRecentFiles(MDLViewer *this)
{
  char *ApplicationPath; // eax
  char *v2; // edx
  char v3; // cl
  char *v4; // eax
  char v5; // cl
  _iobuf *v6; // eax
  _iobuf *v7; // esi
  char v8; // [esp-1h] [ebp-101h] BYREF
  char path[256]; // [esp+0h] [ebp-100h] BYREF

  ApplicationPath = (char *)mx::getApplicationPath();
  v2 = (char *)(path - ApplicationPath);
  do
  {
    v3 = *ApplicationPath;
    ApplicationPath[(_DWORD)v2] = *ApplicationPath;
    ++ApplicationPath;
  }
  while ( v3 != 0 );
  v4 = &v8;
  do
    v5 = *++v4;
  while ( v5 != 0 );
  *(_DWORD *)v4 = *(_DWORD *)aHlf;
  *((_DWORD *)v4 + 1) = 1885692769;
  *((_DWORD *)v4 + 2) = 1919251311;
  *((_DWORD *)v4 + 3) = (char *)&g_flexedverts[11409].x + 2;
  v6 = fopen(file: path, mode: "rb");
  v7 = v6;
  if ( v6 != nullptr )
  {
    fread(buffer: recentFiles, elementSize: 0x800u, count: 1u, stream: v6);
    fclose(stream: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460530
// Name: private: void MDLViewer::saveRecentFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::saveRecentFiles(MDLViewer *this)
{
  char *ApplicationPath; // eax
  char *v2; // edx
  char v3; // cl
  char *v4; // eax
  char v5; // cl
  _iobuf *v6; // eax
  _iobuf *v7; // esi
  char v8; // [esp-1h] [ebp-101h] BYREF
  char path[256]; // [esp+0h] [ebp-100h] BYREF

  ApplicationPath = (char *)mx::getApplicationPath();
  v2 = (char *)(path - ApplicationPath);
  do
  {
    v3 = *ApplicationPath;
    ApplicationPath[(_DWORD)v2] = *ApplicationPath;
    ++ApplicationPath;
  }
  while ( v3 != 0 );
  v4 = &v8;
  do
    v5 = *++v4;
  while ( v5 != 0 );
  *(_DWORD *)v4 = *(_DWORD *)aHlf;
  *((_DWORD *)v4 + 1) = 1885692769;
  *((_DWORD *)v4 + 2) = 1919251311;
  *((_DWORD *)v4 + 3) = (char *)&g_flexedverts[11409].x + 2;
  v6 = fopen(file: path, mode: "wb");
  v7 = v6;
  if ( v6 != nullptr )
  {
    fwrite(buffer: recentFiles, size: 0x800u, count: 1u, stream: v6);
    fclose(stream: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004605C0
// Name: public: CMDLViewerGridSettings::CMDLViewerGridSettings(class mxWindow __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
CMDLViewerGridSettings *__thiscall CMDLViewerGridSettings::CMDLViewerGridSettings(
        CMDLViewerGridSettings *this,
        mxWindow *parent,
        int x,
        int y,
        int w,
        int h)
{
  mxButton *v7; // eax
  CFlatButton *v8; // edi
  HWND Handle; // ebx
  LONG WindowLongA; // eax
  LONG v11; // eax
  mxButton *v12; // eax
  CFlatButton *v13; // ebx
  HWND v14; // edi
  LONG v15; // eax
  LONG v16; // eax

  mxWindow::mxWindow(this, parent, x, y, w, h, label: nullptr, style: 0);
  this->__vftable = (CMDLViewerGridSettings_vtbl *)&CMDLViewerGridSettings::`vftable';
  FacePoser_AddWindowStyle(w: this, addbits: 1174405120);
  v7 = (mxButton *)operator new(nSize: 0xCu);
  v8 = (CFlatButton *)v7;
  if ( v7 != nullptr )
  {
    mxButton::mxButton(this: v7, parent: this, x: 0, y: 0, w: 0, h: 0, label: defaultValue, id: 1001);
    v8->__vftable = (CFlatButton_vtbl *)&CFlatButton::`vftable';
    Handle = (HWND)mxWidget::getHandle(this: v8);
    WindowLongA = GetWindowLongA(hWnd: Handle, nIndex: -20);
    SetWindowLongA(hWnd: Handle, nIndex: -20, dwNewLong: WindowLongA | 0x200);
    v11 = GetWindowLongA(hWnd: Handle, nIndex: -16);
    SetWindowLongA(hWnd: Handle, nIndex: -16, dwNewLong: v11 & 0xFF7FFFFF);
  }
  else
  {
    v8 = nullptr;
  }
  this->m_btnFPS = v8;
  v12 = (mxButton *)operator new(nSize: 0xCu);
  v13 = (CFlatButton *)v12;
  if ( v12 != nullptr )
  {
    mxButton::mxButton(this: v12, parent: this, x: 0, y: 0, w: 0, h: 0, label: defaultValue, id: 1002);
    v13->__vftable = (CFlatButton_vtbl *)&CFlatButton::`vftable';
    v14 = (HWND)mxWidget::getHandle(this: v13);
    v15 = GetWindowLongA(hWnd: v14, nIndex: -20);
    SetWindowLongA(hWnd: v14, nIndex: -20, dwNewLong: v15 | 0x200);
    v16 = GetWindowLongA(hWnd: v14, nIndex: -16);
    SetWindowLongA(hWnd: v14, nIndex: -16, dwNewLong: v16 & 0xFF7FFFFF);
    this->m_btnGridSnap = v13;
  }
  else
  {
    this->m_btnGridSnap = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004606F0
// Name: public: void CMDLViewerGridSettings::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLViewerGridSettings::Init(CMDLViewerGridSettings *this)
{
  CChoreoScene *Scene; // eax
  CChoreoScene *v3; // edi
  int SceneFPS; // eax
  bool v5; // zf
  const char *v6; // eax
  char sz[256]; // [esp+8h] [ebp-100h] BYREF

  if ( g_pChoreoView != nullptr && (Scene = CChoreoView::GetScene(this: g_pChoreoView), v3 = Scene, Scene != nullptr) )
  {
    SceneFPS = CChoreoScene::GetSceneFPS(this: Scene);
    V_snprintf(pDest: sz, maxLen: 256, pFormat: "%i fps", SceneFPS);
    mxWidget::setLabel(this: this->m_btnFPS, format: sz);
    v5 = !CChoreoScene::IsUsingFrameSnap(this: v3);
    v6 = "on";
    if ( v5 )
      v6 = "off";
    V_snprintf(pDest: sz, maxLen: 256, pFormat: "snap: %s", v6);
    mxWidget::setLabel(this: this->m_btnGridSnap, format: sz);
    mxWidget::setVisible(this: this->m_btnFPS, b: true);
    mxWidget::setVisible(this: this->m_btnGridSnap, b: true);
  }
  else
  {
    mxWidget::setVisible(this: this->m_btnFPS, b: false);
    mxWidget::setVisible(this: this->m_btnGridSnap, b: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004607C0
// Name: public: virtual int CMDLViewerGridSettings::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDLViewerGridSettings::handleEvent(CMDLViewerGridSettings *this, mxEvent *event)
{
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // eax
  int v8; // eax
  CChoreoScene *v9; // edi
  bool IsUsingFrameSnap; // al
  bool v11; // zf
  Color v12; // ecx
  const char *v13; // eax
  CChoreoScene *Scene; // eax
  CChoreoScene *v15; // ebx
  int v16; // eax
  int v17; // edi
  Color v18; // ecx
  int v19; // [esp-4h] [ebp-5A0h]
  CInputParams params; // [esp+Ch] [ebp-590h] BYREF
  int iret; // [esp+598h] [ebp-4h]
  int currentFPS; // [esp+5A4h] [ebp+8h]

  v3 = event->event;
  iret = 0;
  if ( v3 != 0 )
  {
    if ( v3 == 1 )
    {
      v4 = (int)(float)((float)mxWidget::w2(this) * 0.44999999);
      v5 = mxWidget::h2(this);
      mxWidget::setBounds(this: this->m_btnFPS, x: 0, y: 0, w: v4, h: v5);
      v19 = mxWidget::h2(this);
      v6 = mxWidget::w2(this);
      mxWidget::setBounds(this: this->m_btnGridSnap, x: v4, y: 0, w: v6 - v4, h: v19);
      iret = 1;
      return 1;
    }
    return iret;
  }
  v8 = event->action - 1001;
  iret = 1;
  if ( v8 == 0 )
  {
    if ( g_pChoreoView != nullptr )
    {
      Scene = CChoreoView::GetScene(this: g_pChoreoView);
      v15 = Scene;
      if ( Scene != nullptr )
      {
        currentFPS = CChoreoScene::GetSceneFPS(this: Scene);
        memset(dst: (unsigned __int8 *)&params, value: 0, count: sizeof(params));
        strcpy(params.m_szDialogTitle, "Change FPS");
        V_snprintf(pDest: params.m_szInputText, maxLen: 1024, pFormat: "%i", currentFPS);
        strcpy(params.m_szPrompt, "Current FPS:");
        if ( InputProperties(&params) != 0 )
        {
          v16 = atoi(nptr: params.m_szInputText);
          v17 = v16;
          if ( v16 > 0 && v16 != currentFPS )
          {
            CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
            CChoreoView::PushUndo(this: g_pChoreoView, description: "Change Scene FPS");
            CChoreoEvent::SetScene(this: v15, fps: v17);
            CChoreoView::PushRedo(this: g_pChoreoView, description: "Change Scene FPS");
            CMDLViewerGridSettings::Init(this);
            Con_Printf(a1: v18, fmt: "FPS changed to %i\n", v17);
          }
        }
      }
    }
    return iret;
  }
  if ( v8 != 1 )
  {
    iret = 0;
    return 0;
  }
  if ( g_pChoreoView == nullptr )
    return iret;
  v9 = CChoreoView::GetScene(this: g_pChoreoView);
  if ( v9 == nullptr )
    return iret;
  CChoreoView::SetDirty(this: g_pChoreoView, dirty: true, clearundo: true);
  CChoreoView::PushUndo(this: g_pChoreoView, description: "Change Snap Frame");
  IsUsingFrameSnap = CChoreoScene::IsUsingFrameSnap(this: v9);
  CChoreoScene::SetUsingFrameSnap(this: v9, snap: !IsUsingFrameSnap);
  CChoreoView::PushRedo(this: g_pChoreoView, description: "Change Snap Frame");
  CMDLViewerGridSettings::Init(this);
  v11 = !CChoreoScene::IsUsingFrameSnap(this: v9);
  v13 = "on";
  if ( v11 )
    v13 = "off";
  Con_Printf(a1: v12, fmt: "Time frame snapping: %s\n", v13);
  return iret;
}

//------------------------------------------------------------------------------
// Address: 0x00460A30
// Name: public: virtual void CMDLViewerModelTab::ShowRightClickMenu(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLViewerModelTab::ShowRightClickMenu(CMDLViewerModelTab *this, int mx, int my)
{
  mxPopupMenu *v4; // eax
  mxPopupMenu *v5; // ebx
  const char *v6; // edi
  int v7; // esi
  const char *v8; // eax
  const char *v9; // eax
  CChoreoScene *Scene; // eax
  CChoreoScene *v11; // edi
  int v12; // esi
  CChoreoActor *Actor; // eax
  char *FacePoserModelName; // eax
  const char *v15; // eax
  const char *v16; // eax
  int c; // [esp+Ch] [ebp-10h]
  int idx; // [esp+10h] [ebp-Ch]
  const char *filename; // [esp+14h] [ebp-8h]
  const char *current; // [esp+18h] [ebp-4h]

  v4 = (mxPopupMenu *)operator new(nSize: 0xCu);
  if ( v4 != nullptr )
    v5 = mxPopupMenu::mxPopupMenu(this: v4);
  else
    v5 = nullptr;
  v6 = defaultValue;
  current = defaultValue;
  filename = defaultValue;
  v7 = this->getSelectedIndex(this);
  idx = v7;
  if ( v7 >= 0 )
  {
    current = models->GetModelName(this: models, a2: v7);
    v6 = current;
    filename = models->GetModelFileName(this: models, a2: v7);
  }
  if ( models->Count(this: models) < 16 )
    mxPopupMenu::add(this: v5, item: "Load Model...", id: 1000);
  if ( v7 >= 0 )
  {
    v8 = va(fmt: "Close '%s'", v6);
    mxPopupMenu::add(this: v5, item: v8, id: 1001);
  }
  if ( models->Count(this: models) > 0 )
    mxPopupMenu::add(this: v5, item: "Close All", id: 1002);
  if ( v7 >= 0 )
  {
    mxMenu::addSeparator(this: v5);
    v9 = va(fmt: "Center %s's face", v6);
    mxPopupMenu::add(this: v5, item: v9, id: 1003);
    Scene = CChoreoView::GetScene(this: g_pChoreoView);
    v11 = Scene;
    if ( Scene != nullptr )
    {
      v12 = 0;
      c = CChoreoScene::GetNumActors(this: Scene);
      if ( c <= 0 )
      {
LABEL_17:
        v15 = va(fmt: "Associate actor to %s", current);
      }
      else
      {
        while ( 1 )
        {
          Actor = CChoreoScene::GetActor(this: v11, actor: v12);
          FacePoserModelName = CChoreoActor::GetFacePoserModelName(this: Actor);
          if ( _V_stricmp(s1: FacePoserModelName, s2: filename) == 0 )
            break;
          if ( ++v12 >= c )
            goto LABEL_17;
        }
        v15 = va(fmt: "Change associated actor for %s", current);
      }
      mxPopupMenu::add(this: v5, item: v15, id: 1004);
      v7 = idx;
    }
    mxMenu::addSeparator(this: v5);
    if ( models->IsModelShownIn3DView(this: models, a2: v7) )
      v16 = va(fmt: "Remove %s from 3D View", current);
    else
      v16 = va(fmt: "Show %s in 3D View", current);
    mxPopupMenu::add(this: v5, item: v16, id: 1005);
  }
  if ( models->Count(this: models) > 0 )
  {
    mxMenu::addSeparator(this: v5);
    mxPopupMenu::add(this: v5, item: "Show All", id: 1006);
    mxPopupMenu::add(this: v5, item: "Hide All", id: 1007);
  }
  mxPopupMenu::popup(this: v5, widget: this, x: mx, y: my);
}

//------------------------------------------------------------------------------
// Address: 0x00460C40
// Name: public: void CMDLViewerModelTab::HandleModelSelect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLViewerModelTab::HandleModelSelect(CMDLViewerModelTab *this)
{
  int v1; // eax
  const char *v2; // eax

  v1 = this->getSelectedIndex(this);
  if ( v1 >= 0 )
  {
    v2 = models->GetModelFileName(this: models, a2: v1);
    ControlPanel::ChangeModel(this: g_pControlPanel, filename: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460C70
// Name: public: void CMDLViewerModelTab::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLViewerModelTab::Init(CMDLViewerModelTab *this)
{
  int v2; // ebx
  int i; // esi
  const char *v4; // eax
  char cleanname[256]; // [esp+Ch] [ebp-100h] BYREF

  this->removeAll(this);
  v2 = models->Count(this: models);
  for ( i = 0; i < v2; ++i )
  {
    v4 = models->GetModelName(this: models, a2: i);
    V_FileBase(in: v4, out: cleanname, maxlen: 256);
    this->add(this, a2: cleanname);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460CE0
// Name: private: void MDLViewer::LoadPosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::LoadPosition(MDLViewer *this)
{
  HWND Handle; // eax
  int x; // [esp+4h] [ebp-18h] BYREF
  int y; // [esp+8h] [ebp-14h] BYREF
  int h; // [esp+Ch] [ebp-10h] BYREF
  int w; // [esp+10h] [ebp-Ch] BYREF
  BOOL visible; // [esp+16h] [ebp-6h] BYREF
  bool locked; // [esp+1Ah] [ebp-2h] BYREF
  bool zoomed; // [esp+1Bh] [ebp-1h] BYREF

  FacePoser_LoadWindowPositions(name: "MDLViewer", (bool *)&visible, &x, &y, &w, &h, &locked, &zoomed);
  if ( w == 0 || h == 0 )
  {
    zoomed = true;
    LOBYTE(visible) = 1;
  }
  mxWidget::setBounds(this, x, y, w, h);
  if ( zoomed )
  {
    Handle = (HWND)mxWidget::getHandle(this);
    ShowWindow(hWnd: Handle, nCmdShow: 3);
  }
  else
  {
    mxWidget::setVisible(this, b: visible);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460D70
// Name: private: void MDLViewer::SavePosition(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::SavePosition(MDLViewer *this)
{
  int x_low; // edi
  int y_low; // ebx
  mxWindow *Parent; // eax
  HWND Handle; // eax
  HWND v6; // eax
  HWND v7; // eax
  tagPOINT pt; // [esp+Ch] [ebp-18h] BYREF
  BOOL visible; // [esp+14h] [ebp-10h]
  int width; // [esp+18h] [ebp-Ch]
  int height; // [esp+1Ch] [ebp-8h]
  BOOL zoomed; // [esp+20h] [ebp-4h]

  LOBYTE(visible) = mxWidget::isVisible(this);
  x_low = mxWidget::x(this);
  y_low = mxWidget::y(this);
  width = mxWidget::w(this);
  height = mxWidget::h(this);
  pt.x = x_low;
  pt.y = y_low;
  if ( mxWidget::getParent(this) != nullptr )
  {
    Parent = mxWidget::getParent(this);
    Handle = (HWND)mxWidget::getHandle(this: Parent);
    ScreenToClient(hWnd: Handle, lpPoint: &pt);
    x_low = SLOWORD(pt.x);
    y_low = SLOWORD(pt.y);
  }
  v6 = (HWND)mxWidget::getHandle(this);
  LOBYTE(zoomed) = IsZoomed(hWnd: v6);
  v7 = (HWND)mxWidget::getHandle(this);
  if ( !IsIconic(hWnd: v7) )
    FacePoser_SaveWindowPositions(
      name: "MDLViewer",
      visible,
      x: x_low,
      y: y_low,
      w: width,
      h: height,
      locked: false,
      zoomed);
}

//------------------------------------------------------------------------------
// Address: 0x00460E30
// Name: public: void MDLViewer::UpdateWindowMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::UpdateWindowMenu(MDLViewer *this)
{
  int ToolCount; // edi
  int i; // esi
  IFacePoserToolWindow *Tool; // eax
  mxWidget *v5; // eax
  bool isVisible; // al

  ToolCount = IFacePoserToolWindow::GetToolCount();
  for ( i = 0; i < ToolCount; ++i )
  {
    Tool = IFacePoserToolWindow::GetTool(index: i);
    v5 = Tool->GetMxWindow(this: Tool);
    isVisible = mxWidget::isVisible(this: v5);
    mxMenu::setChecked(this: *((mxPopupMenu **)this + 8), id: i + 1200, b: isVisible);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460E80
// Name: public: void MDLViewer::UpdateLanguageMenu(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::UpdateLanguageMenu(MDLViewer *this, int currentLanguageId)
{
  int i; // esi

  if ( this->menuView != nullptr )
  {
    for ( i = 0; i < 12; ++i )
      mxMenu::setChecked(this: (mxPopupMenu *)this->menuView, id: i + 1150, b: i == currentLanguageId);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460EC0
// Name: public: virtual void MDLViewer::OnDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::OnDelete(MDLViewer *this)
{
  MDLViewer::saveRecentFiles(this);
  SaveViewerRootSettings();
  DeleteFileA(lpFileName: "hlmv.cfg");
  DeleteFileA(lpFileName: "midump.txt");
  IFacePoserToolWindow::ShutdownTools();
  g_MDLViewer = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00460EF0
// Name: public: void MDLViewer::InitModelTab(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::InitModelTab(MDLViewer *this)
{
  CMDLViewerModelTab::Init(this: *((CMDLViewerModelTab **)this + 16));
}

//------------------------------------------------------------------------------
// Address: 0x00460F00
// Name: public: void MDLViewer::InitGridSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::InitGridSettings(MDLViewer *this)
{
  CMDLViewerGridSettings::Init(this: *((CMDLViewerGridSettings **)this + 17));
}

//------------------------------------------------------------------------------
// Address: 0x00460F10
// Name: public: int MDLViewer::GetActiveModelTab(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall MDLViewer::GetActiveModelTab(MDLViewer *this)
{
  return (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 16) + 52))(a1: *((_DWORD *)this + 16));
}

//------------------------------------------------------------------------------
// Address: 0x00460F20
// Name: public: void MDLViewer::SetActiveModelTab(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::SetActiveModelTab(MDLViewer *this, int modelindex)
{
  int v3; // eax
  const char *v4; // eax

  (*(void (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 16) + 32))(a1: *((_DWORD *)this + 16), a2: modelindex);
  v3 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 16) + 52))(a1: *((_DWORD *)this + 16));
  if ( v3 >= 0 )
  {
    v4 = models->GetModelFileName(this: models, a2: v3);
    ControlPanel::ChangeModel(this: g_pControlPanel, filename: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00460F70
// Name: public: void MDLViewer::OnFileLoaded(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::OnFileLoaded(MDLViewer *this, const char *pszFile)
{
  int v2; // edi
  const char *v3; // esi
  char *v4; // esi
  int i; // edi
  char *v6; // eax
  char v7; // cl
  int v8; // eax
  char v9; // cl
  int v10; // edi
  char *v11; // eax
  char v12; // cl
  char tmp[256]; // [esp+Ch] [ebp-104h] BYREF
  MDLViewer *v14; // [esp+10Ch] [ebp-4h]

  v14 = this;
  v2 = 0;
  v3 = recentFiles[0];
  while ( _V_stricmp(s1: v3, s2: pszFile) != 0 )
  {
    v3 += 256;
    ++v2;
    if ( (int)v3 >= (int)&soundemitter )
      goto LABEL_4;
  }
  if ( v2 < 8 )
  {
    v8 = 0;
    do
    {
      v9 = recentFiles[0][v8];
      tmp[v8++] = v9;
    }
    while ( v9 != 0 );
    v10 = v2 << 8;
    v11 = &recentFiles[0][v10];
    do
    {
      v12 = *v11;
      v11[-v10] = *v11;
      ++v11;
    }
    while ( v12 != 0 );
    strcpy(&recentFiles[0][v10], tmp);
    goto LABEL_9;
  }
LABEL_4:
  v4 = recentFiles[6];
  for ( i = 7; i != 0; --i )
  {
    v6 = v4;
    do
    {
      v7 = *v6;
      v6[256] = *v6;
      ++v6;
    }
    while ( v7 != 0 );
    v4 -= 256;
  }
  strcpy(recentFiles[0], pszFile);
LABEL_9:
  MDLViewer::initRecentFiles(this: v14);
  if ( g_pVCDBrowser != nullptr )
    CVCDBrowser::SetCurrent(this: g_pVCDBrowser, filename: pszFile);
}

//------------------------------------------------------------------------------
// Address: 0x00461060
// Name: public: void MDLViewer::LoadModelFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::LoadModelFile(MDLViewer *this, const char *pszFile)
{
  models->LoadModel(this: models, a2: pszFile);
  MDLViewer::OnFileLoaded(this, pszFile);
  ControlPanel::CenterOnFace(this: g_pControlPanel);
}

//------------------------------------------------------------------------------
// Address: 0x004610A0
// Name: public: void MDLViewer::LoadModel_Steam(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::LoadModel_Steam(MDLViewer *this)
{
  void *v2; // esi
  char filename[512]; // [esp+4h] [ebp-200h] BYREF

  if ( g_FSDialogFactory != nullptr )
  {
    v2 = g_FSDialogFactory(a1: "FileSystemOpenDlg003", a2: nullptr);
    if ( v2 != nullptr )
    {
      (**(void (__thiscall ***)(void *, void *(__cdecl *)(const char *, int *), _DWORD))v2)(
        a1: v2,
        a2: g_Factory,
        a3: 0);
      (*(void (__thiscall **)(void *, const char *))(*(_DWORD *)v2 + 8))(a1: v2, a2: "*.jpg");
      (*(void (__thiscall **)(void *, const char *))(*(_DWORD *)v2 + 8))(a1: v2, a2: "*.mdl");
      (*(void (__thiscall **)(void *, const char *, const char *))(*(_DWORD *)v2 + 12))(
        a1: v2,
        a2: "models",
        a3: "game");
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)v2 + 16))(a1: v2, a2: 1);
      if ( (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)v2 + 24))(a1: v2) == 1 )
      {
        (*(void (__thiscall **)(void *, char *, int))(*(_DWORD *)v2 + 20))(a1: v2, a2: &filename[252], a3: 260);
        models->LoadModel(this: models, a2: &filename[252]);
        MDLViewer::OnFileLoaded(this, pszFile: &filename[252]);
        ControlPanel::CenterOnFace(this: g_pControlPanel);
      }
      (*(void (__thiscall **)(void *))(*(_DWORD *)v2 + 4))(a1: v2);
    }
    else
    {
      V_snprintf(pDest: filename, maxLen: 512, pFormat: "Can't create %s interface.", "FileSystemOpenDlg003");
      MessageBoxA(hWnd: nullptr, lpText: filename, lpCaption: "Error", uType: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004611B0
// Name: public: int MDLViewer::GetCurrentFrame(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall MDLViewer::GetCurrentFrame(MDLViewer *this)
{
  return *((_DWORD *)this + 18);
}

//------------------------------------------------------------------------------
// Address: 0x004611C0
// Name: public: void MDLViewer::Think(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::Think(MDLViewer *this, float dt)
{
  int v3; // ebx
  int v4; // esi
  char v5; // bl

  ++*((_DWORD *)this + 18);
  IFacePoserToolWindow::ToolThink(dt);
  ((void (__thiscall *)(IFacePoserSound *, _DWORD))sound->Update)(a1: sound, a2: LODWORD(dt));
  v3 = soundemitter->GetNumSoundScripts(this: soundemitter);
  v4 = 0;
  if ( v3 <= 0 )
  {
LABEL_4:
    v5 = 0;
  }
  else
  {
    while ( !soundemitter->IsSoundScriptDirty(this: soundemitter, a2: v4) )
    {
      if ( ++v4 >= v3 )
        goto LABEL_4;
    }
    v5 = 1;
  }
  if ( v5 != *((_BYTE *)this + 77) )
    mxMenu::setEnabled(this: (mxMenuBar *)this->d_cpl, id: 1018, b: v5);
  *((_BYTE *)this + 77) = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00461260
// Name: CountVisibleTools
// Source: json
//------------------------------------------------------------------------------
int __cdecl CountVisibleTools()
{
  int ToolCount; // edi
  int v1; // ebx
  int i; // esi
  IFacePoserToolWindow *Tool; // eax
  mxWidget *v4; // eax

  ToolCount = IFacePoserToolWindow::GetToolCount();
  v1 = 0;
  for ( i = 0; i < ToolCount; ++i )
  {
    Tool = IFacePoserToolWindow::GetTool(index: i);
    v4 = Tool->GetMxWindow(this: Tool);
    if ( mxWidget::isVisible(this: v4) )
      ++v1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x004612A0
// Name: public: void MDLViewer::OnCascade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::OnCascade(MDLViewer *this)
{
  int v2; // edi
  int v3; // esi
  int v4; // ebx
  int v5; // esi
  IFacePoserToolWindow *Tool; // eax
  mxWindow *w; // [esp+Ch] [ebp-Ch]
  int c; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  c = IFacePoserToolWindow::GetToolCount();
  v2 = 0;
  v3 = 20 * CountVisibleTools();
  v4 = mxWidget::w2(this: *((mxWidget **)this + 14)) - v3;
  v5 = (mxWidget::h2(this: *((mxWidget **)this + 14)) - v3) / 2;
  for ( i = 0; i < c; ++i )
  {
    Tool = IFacePoserToolWindow::GetTool(index: i);
    w = Tool->GetMxWindow(this: Tool);
    if ( mxWidget::isVisible(this: w) )
    {
      mxWidget::setBounds(this: w, x: v2, y: v2, w: v4, h: v5);
      v2 += 20;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00461340
// Name: public: void MDLViewer::OnHideAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::OnHideAll(MDLViewer *this)
{
  int ToolCount; // edi
  int i; // esi
  IFacePoserToolWindow *Tool; // eax
  mxWidget *v5; // eax
  int v6; // edi
  int j; // esi
  IFacePoserToolWindow *v8; // eax
  mxWidget *v9; // eax
  bool isVisible; // al

  ToolCount = IFacePoserToolWindow::GetToolCount();
  for ( i = 0; i < ToolCount; ++i )
  {
    Tool = IFacePoserToolWindow::GetTool(index: i);
    v5 = Tool->GetMxWindow(this: Tool);
    mxWidget::setVisible(this: v5, b: false);
  }
  v6 = IFacePoserToolWindow::GetToolCount();
  for ( j = 0; j < v6; ++j )
  {
    v8 = IFacePoserToolWindow::GetTool(index: j);
    v9 = v8->GetMxWindow(this: v8);
    isVisible = mxWidget::isVisible(this: v9);
    mxMenu::setChecked(this: *((mxPopupMenu **)this + 8), id: j + 1200, b: isVisible);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004613C0
// Name: public: void MDLViewer::OnShowAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::OnShowAll(MDLViewer *this)
{
  int ToolCount; // edi
  int i; // esi
  IFacePoserToolWindow *Tool; // eax
  mxWidget *v5; // eax
  int v6; // edi
  int j; // esi
  IFacePoserToolWindow *v8; // eax
  mxWidget *v9; // eax
  bool isVisible; // al

  ToolCount = IFacePoserToolWindow::GetToolCount();
  for ( i = 0; i < ToolCount; ++i )
  {
    Tool = IFacePoserToolWindow::GetTool(index: i);
    v5 = Tool->GetMxWindow(this: Tool);
    mxWidget::setVisible(this: v5, b: true);
  }
  v6 = IFacePoserToolWindow::GetToolCount();
  for ( j = 0; j < v6; ++j )
  {
    v8 = IFacePoserToolWindow::GetTool(index: j);
    v9 = v8->GetMxWindow(this: v8);
    isVisible = mxWidget::isVisible(this: v9);
    mxMenu::setChecked(this: *((mxPopupMenu **)this + 8), id: j + 1200, b: isVisible);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00461440
// Name: private: void MDLViewer::DoTile(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::DoTile(MDLViewer *this, int x, int y)
{
  int v4; // esi
  int v5; // eax
  int v6; // edi
  int v7; // ebx
  IFacePoserToolWindow *Tool; // eax
  mxWidget *v9; // esi
  int i; // [esp+8h] [ebp-14h]
  int tall; // [esp+Ch] [ebp-10h]
  int wide; // [esp+10h] [ebp-Ch]
  int c; // [esp+14h] [ebp-8h]
  int v14; // [esp+18h] [ebp-4h]
  int xa; // [esp+24h] [ebp+8h]

  v4 = x;
  c = IFacePoserToolWindow::GetToolCount();
  if ( x < 1 )
    v4 = 1;
  if ( y < 1 )
    y = 1;
  wide = mxWidget::w2(this: *((mxWidget **)this + 14)) / y;
  v5 = mxWidget::h2(this: *((mxWidget **)this + 14));
  v6 = 0;
  tall = v5 / v4;
  if ( v4 > 0 )
  {
    v14 = 0;
    for ( i = v4; i != 0; --i )
    {
      v7 = 0;
      xa = 0;
      do
      {
        if ( v6 >= c )
          break;
        while ( 1 )
        {
          Tool = IFacePoserToolWindow::GetTool(index: v6++);
          v9 = Tool->GetMxWindow(this: Tool);
          if ( mxWidget::isVisible(this: v9) )
            break;
          if ( v6 >= c )
            goto LABEL_13;
        }
        mxWidget::setBounds(this: v9, x: xa, y: v14, w: wide, h: tall);
        xa += wide;
        ++v7;
      }
      while ( v7 < y );
LABEL_13:
      v14 += tall;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00461510
// Name: bool SendConsoleCommandToEngine(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SendConsoleCommandToEngine(
        char *szConsoleCommand,
        const char *szCopyDataFailedMsg,
        const char *szEngineNotRunningMsg)
{
  HWND WindowA; // esi
  tagCOPYDATASTRUCT copyData; // [esp+8h] [ebp-Ch] BYREF

  WindowA = FindWindowA(lpClassName: "Valve001", lpWindowName: nullptr);
  if ( WindowA != nullptr )
  {
    copyData.cbData = strlen(szConsoleCommand) + 1;
    copyData.dwData = 0;
    copyData.lpData = szConsoleCommand;
    if ( SendMessageA(hWnd: WindowA, Msg: 0x4Au, wParam: 0, lParam: (LPARAM)&copyData) != 0 )
    {
      SetFocus(hWnd: WindowA);
      return 1;
    }
    else
    {
      MessageBoxA(hWnd: nullptr, lpText: szCopyDataFailedMsg, lpCaption: "Source Engine Declined Request", uType: 0x30u);
      return 0;
    }
  }
  else
  {
    MessageBoxA(hWnd: nullptr, lpText: szEngineNotRunningMsg, lpCaption: "Source Engine Not Running", uType: 0x30u);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004615B0
// Name: public: virtual void MDLViewer::UpdateStatus(char const __near *,bool,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::UpdateStatus(MDLViewer *this, const char *pchSceneName, bool bQuiet, int nIndex, int nCount)
{
  g_pProgressDialog->UpdateText(this: g_pProgressDialog, a2: pchSceneName);
  ((void (__thiscall *)(IProgressDialog *, _DWORD))g_pProgressDialog->Update)(
    a1: g_pProgressDialog,
    a2: (float)nIndex / (float)nCount);
}

//------------------------------------------------------------------------------
// Address: 0x00461600
// Name: public: void MDLViewer::OnSaveSoundScriptChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::OnSaveSoundScriptChanges(MDLViewer *this)
{
  int v1; // edi
  int v2; // esi
  int v3; // ebx
  int i; // edi
  const char *v5; // esi
  const char *v6; // eax
  const char *v7; // eax
  int v8; // eax

  v1 = soundemitter->GetNumSoundScripts(this: soundemitter);
  v2 = 0;
  if ( v1 > 0 )
  {
    while ( !soundemitter->IsSoundScriptDirty(this: soundemitter, a2: v2) )
    {
      if ( ++v2 >= v1 )
        return;
    }
    v3 = soundemitter->GetNumSoundScripts(this: soundemitter);
    for ( i = 0; i < v3; ++i )
    {
      if ( soundemitter->IsSoundScriptDirty(this: soundemitter, a2: i) )
      {
        v5 = soundemitter->GetSoundScriptName(this: soundemitter, a2: i);
        if ( v5 != nullptr && filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: v5, a3: nullptr) )
        {
          if ( filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: v5, a3: nullptr) )
          {
            v7 = va(fmt: "Save changes to sound script '%s'?", v5);
            v8 = mxMessageBox(parent: nullptr, msg: v7, title: g_appTitle, style: 2);
            if ( v8 == 2 )
              return;
            if ( v8 == 0 )
              soundemitter->SaveChangesToSoundScript(this: soundemitter, a2: i);
          }
          else
          {
            v6 = va(fmt: "Can't save changes to sound script '%s', file is READ-ONLY?", v5);
            mxMessageBox(parent: nullptr, msg: v6, title: g_appTitle, style: 0);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00461730
// Name: public: virtual void CHLFacePoserLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLFacePoserLoggingListener::Log(
        CHLFacePoserLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  LoggingSeverity_t m_Severity; // eax
  __int32 v4; // eax

  g_bInError = true;
  m_Severity = pContext->m_Severity;
  if ( m_Severity != LS_MESSAGE )
  {
    v4 = m_Severity - 1;
    if ( v4 != 0 )
    {
      if ( v4 == 2 )
      {
        _Plat_MessageBox(a1: "Error", a2: pMessage);
        g_bInError = false;
      }
    }
    else
    {
      Con_ErrorPrintf(a1: (Color)this, fmt: pMessage);
      g_bInError = false;
    }
  }
  else
  {
    Con_Printf(a1: (Color)this, fmt: pMessage);
    g_bInError = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004617A0
// Name: public: virtual bool CHLFacePoserApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHLFacePoserApp::Create(CHLFacePoserApp *this)
{
  int v2; // eax
  int Module; // eax
  void *System; // esi
  int v6; // eax
  const char *v7; // eax
  AppSystemInfo_t appSystems[10]; // [esp+8h] [ebp-50h] BYREF

  v2 = _CommandLine();
  (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 20))(a1: v2, a2: "-disallowhwmorph", a3: 0);
  _LoggingSystem_PushLoggingState(a1: 0, a2: 1);
  _LoggingSystem_RegisterLoggingListener(a1: &s_HLFacePoserLoggingListener);
  appSystems[4].m_pModuleName = "datacache.dll";
  appSystems[5].m_pModuleName = "datacache.dll";
  appSystems[6].m_pModuleName = "datacache.dll";
  appSystems[0].m_pModuleName = "inputsystem.dll";
  appSystems[0].m_pInterfaceName = "InputSystemVersion001";
  appSystems[1].m_pModuleName = "materialsystem.dll";
  appSystems[1].m_pInterfaceName = "VMaterialSystem080";
  appSystems[2].m_pModuleName = "studiorender.dll";
  appSystems[2].m_pInterfaceName = "VStudioRender026";
  appSystems[3].m_pModuleName = "vphysics.dll";
  appSystems[3].m_pInterfaceName = "VPhysics031";
  appSystems[4].m_pInterfaceName = "VDataCache003";
  appSystems[5].m_pInterfaceName = "MDLCache004";
  appSystems[6].m_pInterfaceName = "VStudioDataCache005";
  appSystems[7].m_pModuleName = "vgui2.dll";
  appSystems[7].m_pInterfaceName = "VGUI_ivgui008";
  appSystems[8].m_pModuleName = "soundemittersystem.dll";
  appSystems[8].m_pInterfaceName = "VSoundEmitter003";
  appSystems[9].m_pModuleName = defaultValue;
  appSystems[9].m_pInterfaceName = defaultValue;
  if ( !CAppSystemGroup::AddSystems(this, pSystemList: appSystems) )
    return 0;
  Module = CAppSystemGroup::LoadModule(this, pDLLName: "p4lib.dll");
  CAppSystemGroup::AddSystem(this, module: Module, pInterfaceName: "VP4002");
  g_Factory = CAppSystemGroup::GetFactory();
  System = CAppSystemGroup::FindSystem(this, pSystemName: "VMaterialSystem080");
  if ( System == nullptr )
  {
    _Warning(a1: "Material System interface could not be found!\n");
    return 0;
  }
  v6 = _CommandLine();
  v7 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 32))(
                       a1: v6,
                       a2: "-shaderdll",
                       a3: 0);
  if ( v7 == nullptr )
    v7 = "shaderapidx9.dll";
  (*(void (__thiscall **)(void *, const char *))(*(_DWORD *)System + 36))(a1: System, a2: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004618F0
// Name: public: virtual void CHLFacePoserApp::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHLFacePoserApp::Destroy(CHLFacePoserApp *this)
{
  _LoggingSystem_PopLoggingState(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00461900
// Name: char const __near * GetGameDirectory(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetGameDirectory()
{
  return gamedir;
}

//------------------------------------------------------------------------------
// Address: 0x00461910
// Name: private: bool CHLFacePoserApp::SetupSearchPaths(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHLFacePoserApp::SetupSearchPaths(CHLFacePoserApp *this)
{
  bool result; // al
  const char *GameInfoPath; // eax

  result = CSteamAppSystemGroup::SetupSearchPaths(
             this,
             pStartingDir: nullptr,
             bOnlyUseStartingDir: false,
             bIsTool: true);
  if ( result )
  {
    GameInfoPath = CSteamAppSystemGroup::GetGameInfoPath(this);
    V_MakeAbsolutePath(pOut: gamedir, outLen: 260, pPath: GameInfoPath, pStartingDir: nullptr);
    V_FileBase(in: gamedir, out: gamedirsimple, maxlen: 260);
    V_AppendSlash(pStr: gamedir, strSize: 260);
    workspacefiles->Init(this: workspacefiles, a2: gamedirsimple);
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00461980
// Name: public: virtual bool CHLFacePoserApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CHLFacePoserApp::PreInit@<al>(CHLFacePoserApp *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  bool result; // al
  int v5; // ebx
  int v6; // eax
  int v7; // esi
  int v8; // eax
  const char *v10; // [esp+20h] [ebp-10h]
  const char *pAdapterString; // [esp+24h] [ebp-Ch] BYREF
  void *(__cdecl *Factory)(const char *, int *); // [esp+28h] [ebp-8h] BYREF
  void *(__cdecl *pFactoryList)(const char *, int *); // [esp+2Ch] [ebp-4h] BYREF

  pFactoryList = CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(&pFactoryList, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  ConnectTier2Libraries(&pFactoryList, nFactoryCount: 1);
  Factory = CAppSystemGroup::GetFactory();
  CSteamApplication::PostShutdown(pFactoryList: &Factory, nFactoryCount: 1);
  filesystem = g_pFullFileSystem;
  g_pFileSystem = g_pFullFileSystem;
  g_pStudioDataCache = (IStudioDataCache *)CAppSystemGroup::FindSystem(this, pSystemName: "VStudioDataCache005");
  physcollision = (IPhysicsCollision *)CAppSystemGroup::FindSystem(this, pSystemName: "VPhysicsCollision007");
  physprop = (IPhysicsSurfaceProps *)CAppSystemGroup::FindSystem(this, pSystemName: "VPhysicsSurfaceProps001");
  soundemitter = (ISoundEmitterSystemBase *)CAppSystemGroup::FindSystem(this, pSystemName: "VSoundEmitter003");
  if ( soundemitter == nullptr
    || g_pLocalize == nullptr
    || filesystem == nullptr
    || physprop == nullptr
    || physcollision == nullptr
    || g_pMaterialSystem == nullptr
    || g_pStudioRender == nullptr
    || g_pMDLCache == nullptr
    || g_pDataCache == nullptr )
  {
    _Error(this: (ISceneTokenProcessor *)&stru_4F492C, a2: v10);
  }
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: false,
    bAllowSSE: false,
    bAllowSSE2: false,
    bAllowMMX: false);
  filesystem->SetWarningFunc(this: filesystem, a2: (void (*)(const char *, ...))_Warning);
  result = CHLFacePoserApp::SetupSearchPaths(this);
  if ( result )
  {
    v5 = 0;
    v6 = _CommandLine(a1: a3, a2);
    if ( (*(int (__thiscall **)(int, const char *, const char **))(*(_DWORD *)v6 + 12))(
           a1: v6,
           a2: "-adapter",
           a3: &pAdapterString) != 0 )
      v5 = atoi(nptr: pAdapterString);
    v7 = 2;
    v8 = _CommandLine(a1: v10, a2: pAdapterString);
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v8 + 12))(a1: v8, a2: "-ref", a3: 0) != 0 )
      v7 = 6;
    g_pMaterialSystem->SetAdapter(this: g_pMaterialSystem, a2: v5, a3: v7);
    LoadFileSystemDialogModule();
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00461B40
// Name: public: virtual void CHLFacePoserApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00461BA0
// Name: CHLFacePoserApp_SuggestGameInfoDirFn
// Source: json
//------------------------------------------------------------------------------
char __usercall CHLFacePoserApp_SuggestGameInfoDirFn@<al>(
        int a1@<edi>,
        int a2@<esi>,
        const CFSSteamSetupInfo *pFsSteamSetupInfo,
        char *pchPathBuffer,
        int nBufferLength,
        bool *pbBubbleDirectories)
{
  int v6; // esi
  int v7; // eax
  int v8; // eax
  const char *v9; // eax
  int v10; // eax
  int v12; // eax
  const char *v13; // eax
  int v14; // [esp-8h] [ebp-8h]
  int v16; // [esp-4h] [ebp-4h]
  int v17; // [esp-4h] [ebp-4h]

  if ( pbBubbleDirectories != nullptr )
    *pbBubbleDirectories = true;
  v6 = 1;
  v7 = _CommandLine(a1, a2);
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 36))(a1: v7) <= 1 )
    return 0;
  while ( 1 )
  {
    v8 = _CommandLine(a1: v14, a2: v16);
    v9 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v8 + 44))(a1: v8);
    if ( V_stristr(pStr: v9, pSearch: (const char *)v6) != nullptr )
      break;
    ++v6;
    v10 = _CommandLine(a1: aMdl_1, a2: v17);
    if ( v6 >= (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 36))(a1: v10) )
      return 0;
  }
  v12 = _CommandLine(a1: aMdl_1, a2: v17);
  v13 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v12 + 44))(a1: v12);
  V_MakeAbsolutePath(pOut: pchPathBuffer, outLen: nBufferLength, pPath: v13, pStartingDir: (const char *)v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00461C30
// Name: void CreatePath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreatePath(const char *relative)
{
  char *v1; // edi
  char *i; // esi
  char v3; // bl
  int *v4; // eax
  char *v5; // eax
  char fullpath[512]; // [esp+8h] [ebp-200h] BYREF

  V_snprintf(pDest: fullpath, maxLen: 512, pFormat: "%s%s", gamedir, relative);
  v1 = fullpath;
  if ( fullpath[1] == 58 )
    v1 = &fullpath[2];
  for ( i = v1 + 1; *i != 0; ++i )
  {
    v3 = *i;
    if ( *i == 47 || v3 == 92 )
    {
      *i = 0;
      if ( V_stristr(pStr: v1, pSearch: ".") == nullptr && _mkdir(path: v1) == -1 && *_errno() != 17 )
      {
        v4 = _errno();
        v5 = strerror(errnum: *v4);
        _Error(this: (ISceneTokenProcessor *)&stru_4F43C4, a2: v1, v5);
      }
      *i = v3;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00461D80
// Name: public: virtual void CMDLViewerWindowTab::ShowRightClickMenu(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLViewerWindowTab::ShowRightClickMenu(CMDLViewerWindowTab *this, int mx, int my)
{
  int v3; // esi
  int ToolCount; // eax
  IFacePoserToolWindow *Tool; // esi
  mxWidget *v6; // ebx
  mxPopupMenu *v7; // eax
  mxPopupMenu *v8; // edi
  bool isVisible; // bl
  const char *v10; // eax
  const char *v11; // eax
  bool isLocked; // [esp+Bh] [ebp-1h]

  v3 = ((int (__fastcall *)(CMDLViewerWindowTab *))this->getSelectedIndex)(a1: this);
  ToolCount = IFacePoserToolWindow::GetToolCount();
  if ( v3 >= 0 && v3 < ToolCount )
  {
    Tool = IFacePoserToolWindow::GetTool(index: v3);
    if ( Tool != nullptr )
    {
      v6 = Tool->GetMxWindow(this: Tool);
      if ( v6 != nullptr )
      {
        v7 = (mxPopupMenu *)operator new(nSize: 0xCu);
        if ( v7 != nullptr )
          v8 = mxPopupMenu::mxPopupMenu(this: v7);
        else
          v8 = nullptr;
        isVisible = mxWidget::isVisible(this: v6);
        isLocked = Tool->IsLocked(this: Tool);
        v10 = "Hide";
        if ( !isVisible )
          v10 = "Show";
        mxPopupMenu::add(this: v8, item: v10, id: 1000);
        v11 = "Unlock";
        if ( !isLocked )
          v11 = "Lock";
        mxPopupMenu::add(this: v8, item: v11, id: 1001);
        mxPopupMenu::popup(this: v8, widget: this, x: mx, y: my);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00461E50
// Name: public: virtual int CMDLViewerWindowTab::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDLViewerWindowTab::handleEvent(CMDLViewerWindowTab *this, mxEvent *event)
{
  int v2; // esi
  int v3; // eax
  IFacePoserToolWindow *v4; // eax
  int v6; // esi
  int ToolCount; // eax
  IFacePoserToolWindow *Tool; // eax
  mxWidget *v9; // eax
  mxWidget *v10; // esi
  bool isVisible; // al

  if ( event->event == 0 )
  {
    if ( event->action == 1000 )
    {
      v6 = this->getSelectedIndex(this);
      ToolCount = IFacePoserToolWindow::GetToolCount();
      if ( v6 >= 0 && v6 < ToolCount )
      {
        Tool = IFacePoserToolWindow::GetTool(index: v6);
        if ( Tool != nullptr )
        {
          v9 = Tool->GetMxWindow(this: Tool);
          v10 = v9;
          if ( v9 != nullptr )
          {
            isVisible = mxWidget::isVisible(this: v9);
            mxWidget::setVisible(this: v10, b: !isVisible);
            MDLViewer::UpdateWindowMenu(this: g_MDLViewer);
          }
        }
      }
      return 1;
    }
    if ( event->action == 1001 )
    {
      v2 = this->getSelectedIndex(this);
      v3 = IFacePoserToolWindow::GetToolCount();
      if ( v2 >= 0 && v2 < v3 )
      {
        v4 = IFacePoserToolWindow::GetTool(index: v2);
        if ( v4 != nullptr )
        {
          IFacePoserToolWindow::ToggleLockedState(this: v4);
          return 1;
        }
      }
      return 1;
    }
  }
  return CTabWindow::handleEvent(this, event);
}

//------------------------------------------------------------------------------
// Address: 0x00461F10
// Name: public: void CMDLViewerWindowTab::HandleWindowSelect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDLViewerWindowTab::HandleWindowSelect(CMDLViewerWindowTab *this)
{
  int v2; // edi
  int ToolCount; // eax
  IFacePoserToolWindow *Tool; // edi
  int v5; // eax
  mxWidget *v6; // eax
  mxWidget *v7; // ebx
  bool isVisible; // al
  mxWidget *v9; // eax
  HWND Handle; // esi
  double curtime; // [esp+8h] [ebp-Ch]
  bool doubleclicked; // [esp+13h] [ebp-1h]

  v2 = this->getSelectedIndex(this);
  ToolCount = IFacePoserToolWindow::GetToolCount();
  if ( v2 >= 0 && v2 < ToolCount )
  {
    Tool = IFacePoserToolWindow::GetTool(index: v2);
    if ( Tool != nullptr )
    {
      doubleclicked = false;
      curtime = realtime;
      v5 = this->getSelectedIndex(this);
      if ( v5 == this->m_nLastSelected )
        doubleclicked = this->m_flLastSelectedTime + 0.4 > curtime;
      this->m_flLastSelectedTime = curtime;
      this->m_nLastSelected = v5;
      v6 = Tool->GetMxWindow(this: Tool);
      v7 = v6;
      if ( v6 != nullptr )
      {
        if ( doubleclicked )
        {
          isVisible = mxWidget::isVisible(this: v6);
          mxWidget::setVisible(this: v7, b: !isVisible);
          this->m_flLastSelectedTime = -1.0;
        }
        if ( mxWidget::isVisible(this: v7) )
        {
          v9 = Tool->GetMxWindow(this: Tool);
          Handle = (HWND)mxWidget::getHandle(this: v9);
          SetFocus(hWnd: Handle);
          SetWindowPos(hWnd: Handle, hWndInsertAfter: nullptr, X: 0, Y: 0, cx: 0, cy: 0, uFlags: 0x43u);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462010
// Name: public: virtual bool CMDLViewerWorkspace::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMDLViewerWorkspace::PaintBackground(CMDLViewerWorkspace *this)
{
  DWORD SysColor; // eax
  CChoreoWidgetDrawHelper drawHelper; // [esp+0h] [ebp-6Ch] BYREF
  tagRECT rc; // [esp+58h] [ebp-14h] BYREF
  Color clr; // [esp+68h] [ebp-4h] BYREF

  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this);
  CChoreoWidgetDrawHelper::GetClientRect(this: &drawHelper, &rc);
  SysColor = GetSysColor(nIndex: 12);
  *(_WORD *)clr._color = SysColor;
  clr._color[2] = BYTE2(SysColor);
  clr._color[3] = 0;
  CChoreoWidgetDrawHelper::DrawFilledRect(this: &drawHelper, &clr, &rc);
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00462070
// Name: public: void MDLViewer::Refresh(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::Refresh(MDLViewer *this)
{
  int (__thiscall *GetNumSoundScripts)(ISoundEmitterSystemBase *); // eax
  int v2; // edi
  const char *v3; // esi
  const char *v4; // eax
  int c; // [esp+8h] [ebp-Ch]
  Color rgb; // [esp+Fh] [ebp-5h] BYREF
  bool reinit_soundemitter; // [esp+13h] [ebp-1h]

  rgb = (Color)16743680;
  Con_ColorPrintf(&rgb, fmt: "Refreshing...\n");
  GetNumSoundScripts = soundemitter->GetNumSoundScripts;
  reinit_soundemitter = true;
  v2 = 0;
  c = GetNumSoundScripts(this: soundemitter);
  if ( c <= 0 )
    goto LABEL_11;
  do
  {
    if ( soundemitter->IsSoundScriptDirty(this: soundemitter, a2: v2) )
    {
      v3 = soundemitter->GetSoundScriptName(this: soundemitter, a2: v2);
      if ( v3 != nullptr
        && filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: v3, a3: nullptr)
        && filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: v3, a3: nullptr) )
      {
        v4 = va(fmt: "Save changes to sound script '%s'?", v3);
        if ( mxMessageBox(parent: nullptr, msg: v4, title: g_appTitle, style: 2) != 0 )
        {
          reinit_soundemitter = false;
        }
        else
        {
          soundemitter->SaveChangesToSoundScript(this: soundemitter, a2: v2);
          rgb = (Color)((char *)&g_flexedverts[3494].z + 2);
          Con_ColorPrintf(&rgb, fmt: "  saving changes to script file '%s'\n", v3);
        }
      }
    }
    ++v2;
  }
  while ( v2 < c );
  if ( reinit_soundemitter )
LABEL_11:
    soundemitter->Shutdown(this: soundemitter);
  rgb = (Color)((char *)&g_flexedverts[3494].z + 2);
  Con_ColorPrintf(&rgb, fmt: "  reloading textures\n");
  g_pMaterialSystem->ReloadTextures(this: g_pMaterialSystem);
  models->ReleaseModels(this: models);
  rgb = (Color)((char *)&g_flexedverts[3494].z + 2);
  Con_ColorPrintf(&rgb, fmt: "  reloading models\n");
  models->RestoreModels(this: models);
  if ( reinit_soundemitter )
  {
    rgb = (Color)((char *)&g_flexedverts[3494].z + 2);
    Con_ColorPrintf(&rgb, fmt: "  reloading sound emitter system\n");
    soundemitter->Init(this: soundemitter);
  }
  else
  {
    rgb = (Color)3289850;
    Con_ColorPrintf(&rgb, fmt: "  NOT reloading sound emitter system\n");
  }
  rgb = (Color)16743680;
  Con_ColorPrintf(&rgb, fmt: "done.\n");
}

//------------------------------------------------------------------------------
// Address: 0x00462240
// Name: public: void MDLViewer::OnTile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::OnTile(MDLViewer *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // esi
  int v5; // edx

  v2 = CountVisibleTools();
  v3 = (int)fsqrt((float)v2);
  if ( v3 < 1 )
    v3 = 1;
  v4 = 1;
  if ( v3 < v2 )
  {
    v5 = v3;
    do
    {
      v5 += v3;
      ++v4;
    }
    while ( v5 < v2 );
  }
  MDLViewer::DoTile(this, x: v3, y: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00462290
// Name: public: virtual bool MDLViewer::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall MDLViewer::PaintBackground(MDLViewer *this)
{
  CChoreoWidgetDrawHelper drawHelper; // [esp+0h] [ebp-6Ch] BYREF
  tagRECT rc; // [esp+58h] [ebp-14h] BYREF
  Color clr; // [esp+68h] [ebp-4h] BYREF

  CChoreoWidgetDrawHelper::CChoreoWidgetDrawHelper(this: &drawHelper, widget: this);
  CChoreoWidgetDrawHelper::GetClientRect(this: &drawHelper, &rc);
  clr = (Color)14479600;
  CChoreoWidgetDrawHelper::DrawFilledRect(this: &drawHelper, &clr, &rc);
  CChoreoWidgetDrawHelper::~CChoreoWidgetDrawHelper(this: &drawHelper);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00462770
// Name: public: virtual int CMDLViewerModelTab::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDLViewerModelTab::handleEvent(CMDLViewerModelTab *this, mxEvent *event)
{
  int action; // eax
  int v3; // edi
  int v4; // esi
  int result; // eax
  int v6; // eax
  int v7; // esi
  bool v8; // al
  int v9; // edi
  CChoreoScene *Scene; // ebx
  int v11; // esi
  CChoreoActor *v12; // edi
  CChoreoActor *Name; // eax
  int v14; // edx
  char v15; // cl
  char *FacePoserModelName; // eax
  CChoreoActor *v17; // eax
  ChoiceText text; // [esp+Ch] [ebp-288h] BYREF
  CChoiceParams params; // [esp+8Ch] [ebp-208h] BYREF
  CUtlVector<ChoiceText,CUtlMemory<ChoiceText,int> > v20; // [esp+274h] [ebp-20h] BYREF
  int actor; // [esp+288h] [ebp-Ch]
  int c; // [esp+28Ch] [ebp-8h]
  int idx; // [esp+290h] [ebp-4h]
  const char *modelname; // [esp+29Ch] [ebp+8h]

  if ( event->event != 0 )
    return CTabWindow::handleEvent(this, event);
  action = event->action;
  switch ( action )
  {
    case 1000:
      if ( filesystem->IsSteam(this: filesystem) )
      {
        MDLViewer::LoadModel_Steam(this: g_MDLViewer);
        result = 1;
      }
      else if ( FacePoser_ShowOpenFileNameDialog(
                  relative: params.m_szDialogTitle,
                  bufsize: 0x200u,
                  subdir: "models",
                  wildcard: "*.mdl") != 0 )
      {
        MDLViewer::LoadModelFile(this: g_MDLViewer, pszFile: params.m_szDialogTitle);
        result = 1;
      }
      else
      {
LABEL_29:
        result = 1;
      }
      break;
    case 1001:
      v6 = this->getSelectedIndex(this);
      if ( v6 < 0 )
        goto LABEL_29;
      models->FreeModel(this: models, a2: v6);
      result = 1;
      break;
    case 1002:
      models->CloseAllModels(this: models);
      return 1;
    case 1003:
      ControlPanel::CenterOnFace(this: g_pControlPanel);
      return 1;
    case 1004:
      v9 = this->getSelectedIndex(this);
      idx = v9;
      if ( v9 >= 0 )
      {
        modelname = models->GetModelFileName(this: models, a2: v9);
        Scene = CChoreoView::GetScene(this: g_pChoreoView);
        v11 = 0;
        if ( Scene != nullptr )
        {
          CChoiceParams::CChoiceParams(this: (CChoiceParams *)&params.m_szDialogTitle[92]);
          strcpy(&params.m_szDialogTitle[92], "Associate Actor");
          params.m_szPrompt[80] = 0;
          *(_DWORD *)&params.m_szPrompt[84] = 0;
          *(_DWORD *)&params.m_szPrompt[88] = 0;
          strcpy(&params.m_szPrompt[92], "Choose actor:");
          v20.m_Size = 0;
          actor = -1;
          c = CChoreoScene::GetNumActors(this: Scene);
          if ( c > 0 )
          {
            do
            {
              v12 = CChoreoScene::GetActor(this: Scene, actor: v11);
              Name = CChoreoActor::GetName(this: v12);
              v14 = (char *)&text - (char *)Name;
              do
              {
                v15 = Name->m_szName[0];
                Name->m_szName[v14] = Name->m_szName[0];
                Name = (CChoreoActor *)((char *)Name + 1);
              }
              while ( v15 != 0 );
              FacePoserModelName = CChoreoActor::GetFacePoserModelName(this: v12);
              if ( _V_stricmp(s1: FacePoserModelName, s2: modelname) == 0 )
                actor = v11;
              CUtlVector<ChoiceText,CUtlMemory<ChoiceText,int>>::InsertBefore(this: &v20, elem: v20.m_Size, src: &text);
              ++v11;
            }
            while ( v11 < c );
            v9 = idx;
          }
          if ( ChoiceProperties(params: (CChoiceParams *)&params.m_szDialogTitle[92]) != 0 && actor != -1 )
          {
            v17 = CChoreoScene::GetActor(this: Scene, actor);
            CChoreoView::AssociateModelToActor(this: g_pChoreoView, actor: v17, modelindex: v9);
          }
          CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v20);
        }
      }
      goto LABEL_29;
    case 1005:
      v7 = this->getSelectedIndex(this);
      if ( v7 < 0 )
        goto LABEL_29;
      v8 = models->IsModelShownIn3DView(this: models, a2: v7);
      models->ShowModelIn3DView(this: models, a2: v7, a3: !v8);
      result = 1;
      break;
    case 1006:
    case 1007:
      LOBYTE(event) = action == 1006;
      v3 = models->Count(this: models);
      v4 = 0;
      if ( v3 <= 0 )
        goto LABEL_29;
      do
        models->ShowModelIn3DView(this: models, a2: v4++, a3: (bool)event);
      while ( v4 < v3 );
      result = 1;
      break;
    default:
      return CTabWindow::handleEvent(this, event);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00462B10
// Name: public: void CUtlDict<int,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,unsigned short>::RemoveAll(CUtlDict<int,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00462B70
// Name: public: void MDLViewer::OnUpdateScenesImage(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall MDLViewer::OnUpdateScenesImage(MDLViewer *this@<ecx>, int a2@<edi>)
{
  bool v3; // zf
  bool v4; // sf
  CP4File *v5; // edi
  char v6; // al
  char szFilename[260]; // [esp+4h] [ebp-138h] BYREF
  CUtlBuffer targetBuffer; // [esp+108h] [ebp-34h] BYREF

  v3 = *((_DWORD *)this + 23) == 0;
  v4 = *((int *)this + 23) < 0;
  if ( *((int *)this + 23) > 0 )
  {
    ((void (__thiscall *)(IProgressDialog *, const char *, const char *, _DWORD, int))g_pProgressDialog->Start)(
      a1: g_pProgressDialog,
      a2: "Updating scenes.image",
      a3: defaultValue,
      a4: 0,
      a5: a2);
    CUtlBuffer::CUtlBuffer(this: &targetBuffer, growSize: 0, initSize: 0, nFlags: 0);
    V_strncpy(pDest: szFilename, pSrc: gamedir, maxLen: 260);
    V_strncat(pDest: szFilename, pSrc: "scenes/scenes.image", destBufferSize: 0x104u, max_chars_to_copy: -1);
    v5 = CP4Factory::AccessFile(this: g_p4factory, szFilename);
    v5->Edit(this: v5);
    if ( scriptlib->ReadFileToBuffer(this: scriptlib, a2: szFilename, a3: &targetBuffer, a4: false, a5: false) != 0 )
      v6 = g_pSceneImage->UpdateSceneImageFile(
             this: g_pSceneImage,
             a2: &targetBuffer,
             a3: gamedir,
             a4: true,
             a5: false,
             a6: (ISceneCompileStatus *)&this->mb,
             a7: *((CUtlString **)this + 20),
             a8: *((_DWORD *)this + 23));
    else
      v6 = g_pSceneImage->CreateSceneImageFile(
             this: g_pSceneImage,
             a2: &targetBuffer,
             a3: gamedir,
             a4: true,
             a5: false,
             a6: (ISceneCompileStatus *)&this->mb);
    if ( v6 != 0 )
    {
      MakeFileWriteable(filename: szFilename);
      scriptlib->WriteBufferToFile(this: scriptlib, a2: szFilename, a3: &targetBuffer, a4: WRITE_TO_DISK_ALWAYS);
    }
    g_pProgressDialog->Finish(this: g_pProgressDialog);
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this + 4);
    v5->Add(this: v5);
    ((void (__thiscall *)(CP4File *, int))v5->dtr_CP4File)(a1: v5, a2: 1);
    if ( targetBuffer.m_Memory.m_nGrowSize >= 0 && targetBuffer.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuffer.m_Memory.m_pMemory);
    v3 = *((_DWORD *)this + 23) == 0;
    v4 = *((int *)this + 23) < 0;
  }
  mxMenu::setEnabled(this: (mxMenuBar *)this->d_MatSysWindow, id: 1028, b: !v4 && !v3);
}

//------------------------------------------------------------------------------
// Address: 0x00462CF0
// Name: public: void MDLViewer::OnRebuildScenesImage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::OnRebuildScenesImage(MDLViewer *this)
{
  CP4File *v2; // esi
  mxMenuBar **p_mb; // eax
  char szFilename[260]; // [esp+8h] [ebp-134h] BYREF
  CUtlBuffer targetBuffer; // [esp+10Ch] [ebp-30h] BYREF

  g_pProgressDialog->Start(this: g_pProgressDialog, a2: "Rebuilding scenes.image", a3: defaultValue, a4: false);
  CUtlBuffer::CUtlBuffer(this: &targetBuffer, growSize: 0, initSize: 0, nFlags: 0);
  V_strncpy(pDest: szFilename, pSrc: gamedir, maxLen: 260);
  V_strncat(pDest: szFilename, pSrc: "scenes/scenes.image", destBufferSize: 0x104u, max_chars_to_copy: -1);
  v2 = CP4Factory::AccessFile(this: g_p4factory, szFilename);
  v2->Edit(this: v2);
  if ( this != nullptr )
    p_mb = &this->mb;
  else
    p_mb = nullptr;
  if ( g_pSceneImage->CreateSceneImageFile(
         this: g_pSceneImage,
         a2: &targetBuffer,
         a3: gamedir,
         a4: true,
         a5: false,
         a6: (ISceneCompileStatus *)p_mb) != 0 )
  {
    MakeFileWriteable(filename: szFilename);
    scriptlib->WriteBufferToFile(this: scriptlib, a2: szFilename, a3: &targetBuffer, a4: WRITE_TO_DISK_ALWAYS);
  }
  g_pProgressDialog->Finish(this: g_pProgressDialog);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this + 4);
  mxMenu::setEnabled(this: (mxMenuBar *)this->d_MatSysWindow, id: 1028, b: *((_DWORD *)this + 23) > 0);
  v2->Add(this: v2);
  ((void (__thiscall *)(CP4File *, int))v2->dtr_CP4File)(a1: v2, a2: 1);
  if ( targetBuffer.m_Memory.m_nGrowSize >= 0 && targetBuffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuffer.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00462E30
// Name: public: void MDLViewer::OnPlaySceneInFoundry(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MDLViewer::OnPlaySceneInFoundry(MDLViewer *this)
{
  CChoreoScene *Scene; // esi
  const char *Filename; // eax
  char szConsoleCommand[260]; // [esp+8h] [ebp-208h] BYREF
  char szSceneFileName[260]; // [esp+10Ch] [ebp-104h] BYREF

  Scene = CChoreoView::GetScene(this: g_pChoreoView);
  if ( Scene != nullptr )
  {
    MDLViewer::OnRebuildScenesImage(this);
    SendConsoleCommandToEngine(
      szConsoleCommand: "scene_flush\n",
      szCopyDataFailedMsg: "Unable to clear scene_cache.",
      szEngineNotRunningMsg: "The Source engine must be running in order to utilize this feature.");
    Filename = CChoreoScene::GetFilename(this: Scene);
    V_FileBase(in: Filename, out: szSceneFileName, maxlen: 260);
    V_snprintf(pDest: szConsoleCommand, maxLen: 260, pFormat: "load faceposer\\%s\n", szSceneFileName);
    SendConsoleCommandToEngine(
      szConsoleCommand,
      szCopyDataFailedMsg: "Unable to load savegame for requested scene.",
      szEngineNotRunningMsg: "The Source engine must be running in order to utilize this feature.");
  }
  else
  {
    MessageBoxA(
      hWnd: nullptr,
      lpText: "There is no scene presently loaded. Please load a scene using Choreography|Load... before attempting to play the s"
      "cene inside the engine.",
      lpCaption: "No Scene Loaded",
      uType: 0x30u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462EE0
// Name: public: void MDLViewer::OnVCDSaved(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge MDLViewer::OnVCDSaved(MDLViewer *this@<ecx>, int a2@<edi>, const char *pFullpath)
{
  CUtlString str; // [esp+4h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &str);
  CUtlString::operator=(this: &str, src: pFullpath);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
    this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this + 4,
    elem: *((_DWORD *)this + 23),
    src: &str);
  mxMenu::setEnabled(this: (mxMenuBar *)this->d_MatSysWindow, id: 1028, b: *((_DWORD *)this + 23) > 0);
  if ( *((_BYTE *)this + 76) != 0 )
    MDLViewer::OnUpdateScenesImage(this, a2);
  str.m_Storage.m_nActualLength = 0;
  if ( str.m_Storage.m_Memory.m_nGrowSize >= 0 && str.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: str.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00462F60
// Name: public: virtual bool MDLViewer::CanClose(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall MDLViewer::CanClose@<al>(MDLViewer *this@<ecx>, int a2@<edi>)
{
  MDLViewer *v2; // esi
  Color v3; // ecx
  int v5; // edi
  const char *v6; // esi
  const char *v7; // eax
  int v8; // eax
  int ToolCount; // edi
  int i; // esi
  IFacePoserToolWindow *Tool; // eax
  CMessageBoxWithCheckBoxParams params; // [esp+8h] [ebp-598h] BYREF
  int c; // [esp+598h] [ebp-8h]
  MDLViewer *v14; // [esp+59Ch] [ebp-4h]

  v2 = this;
  v14 = this;
  Con_Printf(a1: (Color)this, fmt: "Checking for vcd changes...\n");
  if ( (int)v2[2].menuView > 0 )
  {
    params.m_szPrompt[0] = 0;
    params.m_szCheckBoxText[0] = 0;
    params.m_bChecked = false;
    _V_memset(dest: &params, fill: 0, count: 1424);
    V_strncpy(pDest: params.m_szDialogTitle, pSrc: "Scenes Image", maxLen: 128);
    V_strncpy(pDest: params.m_szPrompt, pSrc: "Update scenes.image?", maxLen: 256);
    V_strncpy(pDest: params.m_szCheckBoxText, pSrc: "Rebuild full .image", maxLen: 1024);
    params.m_bChecked = false;
    if ( MessageBoxWithCheckBox(&params) == 0 )
      return 0;
    if ( params.m_bChecked )
      MDLViewer::OnRebuildScenesImage(this: v2);
    else
      MDLViewer::OnUpdateScenesImage(this: v2, a2);
  }
  Con_Printf(a1: v3, fmt: "Checking for sound script changes...\n");
  v5 = 0;
  c = soundemitter->GetNumSoundScripts(this: soundemitter);
  if ( c > 0 )
  {
    while ( 1 )
    {
      if ( soundemitter->IsSoundScriptDirty(this: soundemitter, a2: v5) )
      {
        v6 = soundemitter->GetSoundScriptName(this: soundemitter, a2: v5);
        if ( v6 != nullptr
          && filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: v6, a3: nullptr)
          && filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: v6, a3: nullptr) )
        {
          v7 = va(fmt: "Save changes to sound script '%s'?", v6);
          v8 = mxMessageBox(parent: nullptr, msg: v7, title: g_appTitle, style: 2);
          if ( v8 == 2 )
            return 0;
          if ( v8 == 0 )
            soundemitter->SaveChangesToSoundScript(this: soundemitter, a2: v5);
        }
      }
      if ( ++v5 >= c )
      {
        v2 = v14;
        break;
      }
    }
  }
  MDLViewer::SavePosition(this: v2);
  ToolCount = IFacePoserToolWindow::GetToolCount();
  for ( i = 0; i < ToolCount; ++i )
  {
    Tool = IFacePoserToolWindow::GetTool(index: i);
    IFacePoserToolWindow::SavePosition(this: Tool);
  }
  models->SaveModelList(this: models);
  models->CloseAllModels(this: models);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00463150
// Name: public: MDLViewer::MDLViewer(void)
// Source: json
//------------------------------------------------------------------------------
MDLViewer *__thiscall MDLViewer::MDLViewer(MDLViewer *this)
{
  mxWindow *v2; // eax
  mxWindow *v3; // edi
  CTabWindow *v4; // eax
  CTabWindow *v5; // edi
  CTabWindow *v6; // eax
  CTabWindow *v7; // edi
  CMDLViewerGridSettings *v8; // eax
  CMDLViewerGridSettings *v9; // eax
  CTabWindow *v10; // ecx
  mxStatusWindow *v11; // eax
  mxStatusWindow *v12; // eax
  int v13; // eax
  Color v14; // ecx
  Color v15; // ecx
  mxMenuBar *v16; // eax
  MatSysWindow *v17; // eax
  mxMenu *v18; // eax
  ControlPanel *v19; // eax
  mxMenu *v20; // eax
  mxMenu *v21; // eax
  mxMenu *v22; // eax
  mxMenu *v23; // eax
  mxMenu *v24; // eax
  mxMenu *v25; // eax
  mxMenu *v26; // eax
  mxMenu *v27; // eax
  mxMenu *v28; // eax
  mxMenu *v29; // eax
  mxMenu *v30; // eax
  mxMenu *v31; // eax
  mxMenu *v32; // eax
  mxMenu *v33; // eax
  mxPopupMenu *d_MatSysWindow; // ecx
  mxMenu *v35; // eax
  mxPopupMenu *v36; // edi
  mxMenu *v37; // eax
  mxMenu *v38; // eax
  int i; // edi
  const char *v40; // eax
  Color v41; // ecx
  MatSysWindow *v42; // eax
  Color v43; // ecx
  CloseCaptionTool *v44; // eax
  Color v45; // ecx
  ControlPanel *v46; // eax
  Color v47; // ecx
  PhonemeEditor *v48; // eax
  Color v49; // ecx
  ExpressionTool *v50; // eax
  Color v51; // ecx
  GestureTool *v52; // eax
  Color v53; // ecx
  RampTool *v54; // eax
  Color v55; // ecx
  SceneRampTool *v56; // eax
  Color v57; // ecx
  mxExpressionTray *v58; // eax
  Color v59; // ecx
  AnimationBrowser *v60; // eax
  Color v61; // ecx
  FlexPanel *v62; // eax
  Color v63; // ecx
  CWaveBrowser *v64; // eax
  Color v65; // ecx
  CVCDBrowser *v66; // eax
  Color v67; // ecx
  CChoreoView *v68; // eax
  CChoreoView *v69; // eax
  Color v70; // ecx
  Color v71; // ecx
  int v72; // ebx
  Color v73; // ecx
  CExpClass *Tool; // eax
  int v75; // edi
  char *Name; // eax
  Color v77; // ecx
  Color v78; // ecx
  int v79; // ebx
  int j; // edi
  CChoreoChannel *v81; // eax
  char *v82; // eax
  Color v83; // ecx
  Color v84; // ecx
  int v85; // ebx
  int k; // edi
  IFacePoserToolWindow *v87; // eax
  mxWidget *v88; // eax
  bool isVisible; // al
  int cclanguageid; // ebx
  int m; // edi
  Color v92; // ecx
  int v93; // edi
  int v94; // eax
  Color v95; // ecx
  int v96; // ebx
  int n; // edi
  IFacePoserToolWindow *v98; // eax
  int v100; // [esp-8h] [ebp-1Ch]
  mxPopupMenu *d_cpl; // [esp-4h] [ebp-18h]
  int ToolCount; // [esp+Ch] [ebp-8h]
  int *v103; // [esp+10h] [ebp-4h]

  mxWindow::mxWindow(this, parent: nullptr, x: 0, y: 0, w: 0, h: 0, label: g_appTitle, style: 0);
  this->mb = (mxMenuBar *)&ISceneCompileStatus::`vftable';
  this->__vftable = (MDLViewer_vtbl *)&MDLViewer::`vftable'{for `mxWindow'};
  this->mb = (mxMenuBar *)&MDLViewer::`vftable'{for `ISceneCompileStatus'};
  this->menuView = nullptr;
  *((_WORD *)this + 38) = 257;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  g_MDLViewer = this;
  FacePoser_MakeToolWindow(w: this, smallcaption: false);
  v2 = (mxWindow *)operator new(nSize: 0xCu);
  v3 = v2;
  if ( v2 != nullptr )
  {
    mxWindow::mxWindow(this: v2, parent: this, x: 0, y: 0, w: 500, h: 500, label: defaultValue, style: 0);
    v3->__vftable = (mxWindow_vtbl *)&CMDLViewerWorkspace::`vftable';
    FacePoser_AddWindowStyle(w: v3, addbits: 369098752);
  }
  else
  {
    v3 = nullptr;
  }
  *((_DWORD *)this + 14) = v3;
  v4 = (CTabWindow *)operator new(nSize: 0x60u);
  v5 = v4;
  if ( v4 != nullptr )
  {
    CTabWindow::CTabWindow(this: v4, parent: this, x: 0, y: 500, w: 500, h: 20, id: 1238, style: 0);
    v5->__vftable = (CTabWindow_vtbl *)&CMDLViewerWindowTab::`vftable';
    CTabWindow::SetInverted(this: v5, invert: true);
    v5[1].__vftable = (CTabWindow_vtbl *)-1;
    *(_QWORD *)&v5[1].mxWindow::mxWidget::d_this = 0xBFF0000000000000uLL;
  }
  else
  {
    v5 = nullptr;
  }
  *((_DWORD *)this + 15) = v5;
  v6 = (CTabWindow *)operator new(nSize: 0x54u);
  v7 = v6;
  if ( v6 != nullptr )
  {
    CTabWindow::CTabWindow(this: v6, parent: this, x: 500, y: 500, w: 200, h: 20, id: 1239, style: 0);
    v7->__vftable = (CTabWindow_vtbl *)&CMDLViewerModelTab::`vftable';
    CTabWindow::SetInverted(this: v7, invert: true);
  }
  else
  {
    v7 = nullptr;
  }
  *((_DWORD *)this + 16) = v7;
  v8 = (CMDLViewerGridSettings *)operator new(nSize: 0x14u);
  if ( v8 != nullptr )
    v9 = CMDLViewerGridSettings::CMDLViewerGridSettings(this: v8, parent: this, x: 0, y: 500, w: 500, h: 20);
  else
    v9 = nullptr;
  v10 = *((CTabWindow **)this + 16);
  *((_DWORD *)this + 17) = v9;
  CTabWindow::SetRightJustify(this: v10, rightjustify: true);
  v11 = (mxStatusWindow *)operator new(nSize: 0x82280u);
  if ( v11 != nullptr )
    v12 = mxStatusWindow::mxStatusWindow(
            this: v11,
            parent: *((mxWindow **)this + 14),
            x: 0,
            y: 0,
            w: 1024,
            h: 150,
            label: defaultValue);
  else
    v12 = nullptr;
  g_pStatusWindow = v12;
  mxWidget::setVisible(this: v12, b: true);
  InitViewerSettings(subkey: "faceposer");
  g_viewerSettings.speechapiindex = 1;
  g_viewerSettings.m_iEditAttachment = -1;
  LoadViewerRootSettings();
  MDLViewer::LoadPosition(this);
  v100 = mxWidget::w2(this);
  v13 = mxWidget::h2(this);
  mxWidget::setBounds(this: g_pStatusWindow, x: 0, y: v13 - 150, w: v100, h: 150);
  Con_Printf(a1: v14, fmt: "MDLViewer started\n");
  Con_Printf(a1: v15, fmt: "Creating menu bar\n");
  v16 = (mxMenuBar *)operator new(nSize: 0xCu);
  if ( v16 != nullptr )
    v17 = (MatSysWindow *)mxMenuBar::mxMenuBar(this: v16, parent: this);
  else
    v17 = nullptr;
  this->d_MatSysWindow = v17;
  v18 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v18 != nullptr )
    v19 = (ControlPanel *)mxMenu::mxMenu(this: v18);
  else
    v19 = nullptr;
  this->d_cpl = v19;
  v20 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v20 != nullptr )
    v21 = mxMenu::mxMenu(this: v20);
  else
    v21 = nullptr;
  this->menuOptions = v21;
  v22 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v22 != nullptr )
    v23 = mxMenu::mxMenu(this: v22);
  else
    v23 = nullptr;
  *((_DWORD *)this + 8) = v23;
  v24 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v24 != nullptr )
    v25 = mxMenu::mxMenu(this: v24);
  else
    v25 = nullptr;
  *((_DWORD *)this + 9) = v25;
  v26 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v26 != nullptr )
    v27 = mxMenu::mxMenu(this: v26);
  else
    v27 = nullptr;
  *((_DWORD *)this + 10) = v27;
  v28 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v28 != nullptr )
    v29 = mxMenu::mxMenu(this: v28);
  else
    v29 = nullptr;
  *((_DWORD *)this + 11) = v29;
  v30 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v30 != nullptr )
    v31 = mxMenu::mxMenu(this: v30);
  else
    v31 = nullptr;
  *((_DWORD *)this + 12) = v31;
  v32 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v32 != nullptr )
    v33 = mxMenu::mxMenu(this: v32);
  else
    v33 = nullptr;
  d_MatSysWindow = (mxPopupMenu *)this->d_MatSysWindow;
  d_cpl = (mxPopupMenu *)this->d_cpl;
  *((_DWORD *)this + 13) = v33;
  mxMenu::addMenu(this: d_MatSysWindow, item: "File", menu: d_cpl);
  mxMenu::addMenu(this: (mxPopupMenu *)this->d_MatSysWindow, item: "Options", menu: (mxPopupMenu *)this->menuOptions);
  mxMenu::addMenu(this: (mxPopupMenu *)this->d_MatSysWindow, item: "Expression", menu: *((mxPopupMenu **)this + 11));
  mxMenu::addMenu(this: (mxPopupMenu *)this->d_MatSysWindow, item: "Choreography", menu: *((mxPopupMenu **)this + 12));
  mxMenu::addMenu(this: (mxPopupMenu *)this->d_MatSysWindow, item: "Foundry", menu: *((mxPopupMenu **)this + 13));
  mxMenu::addMenu(this: (mxPopupMenu *)this->d_MatSysWindow, item: "Window", menu: *((mxPopupMenu **)this + 8));
  mxMenu::addMenu(this: (mxPopupMenu *)this->d_MatSysWindow, item: "Help", menu: *((mxPopupMenu **)this + 9));
  v35 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v35 != nullptr )
    v36 = (mxPopupMenu *)mxMenu::mxMenu(this: v35);
  else
    v36 = nullptr;
  mxPopupMenu::add(this: v36, item: "(empty)", id: 1008);
  mxPopupMenu::add(this: v36, item: "(empty)", id: 1009);
  mxPopupMenu::add(this: v36, item: "(empty)", id: 1010);
  mxPopupMenu::add(this: v36, item: "(empty)", id: 1011);
  mxPopupMenu::add(this: (mxPopupMenu *)this->d_cpl, item: "Load Model...", id: 1001);
  mxPopupMenu::add(this: (mxPopupMenu *)this->d_cpl, item: "Refresh\tF5", id: 1017);
  mxMenu::addSeparator(this: (mxPopupMenu *)this->d_cpl);
  mxPopupMenu::add(this: (mxPopupMenu *)this->d_cpl, item: "Save Sound Changes...", id: 1018);
  mxPopupMenu::add(this: (mxPopupMenu *)this->d_cpl, item: "Rebuild scenes.image...", id: 1019);
  mxPopupMenu::add(this: (mxPopupMenu *)this->d_cpl, item: "Update scenes.image...", id: 1028);
  mxMenu::setEnabled(this: (mxMenuBar *)this->d_cpl, id: 1028, b: false);
  mxMenu::addSeparator(this: (mxPopupMenu *)this->d_cpl);
  mxPopupMenu::add(this: (mxPopupMenu *)this->d_cpl, item: "Load Background Texture...", id: 1002);
  mxPopupMenu::add(this: (mxPopupMenu *)this->d_cpl, item: "Load Ground Texture...", id: 1003);
  mxMenu::addSeparator(this: (mxPopupMenu *)this->d_cpl);
  mxPopupMenu::add(this: (mxPopupMenu *)this->d_cpl, item: "Unload Ground Texture", id: 1004);
  mxMenu::addSeparator(this: (mxPopupMenu *)this->d_cpl);
  mxMenu::addMenu(this: (mxPopupMenu *)this->d_cpl, item: "Recent Files", menu: v36);
  mxMenu::addSeparator(this: (mxPopupMenu *)this->d_cpl);
  mxPopupMenu::add(this: (mxPopupMenu *)this->d_cpl, item: "Exit", id: 1016);
  mxMenu::setEnabled(this: (mxMenuBar *)this->d_cpl, id: 1002, b: false);
  mxMenu::setEnabled(this: (mxMenuBar *)this->d_cpl, id: 1003, b: false);
  mxMenu::setEnabled(this: (mxMenuBar *)this->d_cpl, id: 1004, b: false);
  mxMenu::setEnabled(this: (mxMenuBar *)this->d_cpl, id: 1018, b: false);
  mxPopupMenu::add(this: (mxPopupMenu *)this->menuOptions, item: "Background Color...", id: 1101);
  mxPopupMenu::add(this: (mxPopupMenu *)this->menuOptions, item: "Ground Color...", id: 1102);
  mxPopupMenu::add(this: (mxPopupMenu *)this->menuOptions, item: "Light Color...", id: 1103);
  v37 = (mxMenu *)operator new(nSize: 0xCu);
  if ( v37 != nullptr )
    v38 = mxMenu::mxMenu(this: v37);
  else
    v38 = nullptr;
  this->menuView = v38;
  for ( i = 0; i < 12; ++i )
  {
    v40 = CSentence::NameForLanguage(language: i);
    mxPopupMenu::add(this: (mxPopupMenu *)this->menuView, item: v40, id: i + 1150);
  }
  mxMenu::addSeparator(this: (mxPopupMenu *)this->menuOptions);
  mxMenu::addMenu(this: (mxPopupMenu *)this->menuOptions, item: "CC Language", menu: (mxPopupMenu *)this->menuView);
  mxMenu::addSeparator(this: (mxPopupMenu *)this->menuOptions);
  mxPopupMenu::add(this: (mxPopupMenu *)this->menuOptions, item: "Center View", id: 1104);
  mxPopupMenu::add(this: (mxPopupMenu *)this->menuOptions, item: "Center on Face", id: 1107);
  mxMenu::addSeparator(this: (mxPopupMenu *)this->menuOptions);
  mxPopupMenu::add(this: (mxPopupMenu *)this->menuOptions, item: "Make Screenshot...", id: 1105);
  mxMenu::addSeparator(this: (mxPopupMenu *)this->menuOptions);
  mxPopupMenu::add(this: (mxPopupMenu *)this->menuOptions, item: "Clear model sounds.", id: 1108);
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 11), item: "New...", id: 1026);
  mxMenu::addSeparator(this: *((mxPopupMenu **)this + 11));
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 11), item: "Load...", id: 1021);
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 11), item: "Save", id: 1020);
  mxMenu::addSeparator(this: *((mxPopupMenu **)this + 11));
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 11), item: "Export to VFE", id: 1023);
  mxMenu::addSeparator(this: *((mxPopupMenu **)this + 11));
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 11), item: "Close class", id: 1024);
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 11), item: "Close all classes", id: 1025);
  mxMenu::addSeparator(this: *((mxPopupMenu **)this + 11));
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 11), item: "Recreate all bitmaps", id: 1027);
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 12), item: "New...", id: 1030);
  mxMenu::addSeparator(this: *((mxPopupMenu **)this + 12));
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 12), item: "Load...", id: 1031);
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 12), item: "Save", id: 1032);
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 12), item: "Save As...", id: 1033);
  mxMenu::addSeparator(this: *((mxPopupMenu **)this + 12));
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 12), item: "Close", id: 1034);
  mxMenu::addSeparator(this: *((mxPopupMenu **)this + 12));
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 12), item: "Add Actor...", id: 1035);
  mxMenu::addSeparator(this: *((mxPopupMenu **)this + 12));
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 12), item: "Scrubber units in seconds", id: 1037);
  mxMenu::addSeparator(this: *((mxPopupMenu **)this + 12));
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 12), item: "Load Next", id: 1038);
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 9), item: "Goto Homepage...", id: 1301);
  mxMenu::addSeparator(this: *((mxPopupMenu **)this + 9));
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 9), item: "About...", id: 1302);
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 13), item: "Play Scene In Engine...", id: 1400);
  Con_Printf(a1: v41, fmt: "Creating 3D View\n");
  v42 = (MatSysWindow *)operator new(nSize: 0x2C4u);
  if ( v42 != nullptr )
    g_pMatSysWindow = MatSysWindow::MatSysWindow(
                        this: v42,
                        parent: *((mxWindow **)this + 14),
                        x: 0,
                        y: 0,
                        w: 100,
                        h: 100,
                        label: defaultValue,
                        style: 0);
  else
    g_pMatSysWindow = nullptr;
  Con_Printf(a1: v43, fmt: "Creating Close Caption tool");
  v44 = (CloseCaptionTool *)operator new(nSize: 0x2A4u);
  if ( v44 != nullptr )
    g_pCloseCaptionTool = CloseCaptionTool::CloseCaptionTool(this: v44, parent: *((mxWindow **)this + 14));
  else
    g_pCloseCaptionTool = nullptr;
  Con_Printf(a1: v45, fmt: "Creating control panel\n");
  v46 = (ControlPanel *)operator new(nSize: 0x2C4u);
  if ( v46 != nullptr )
    g_pControlPanel = ControlPanel::ControlPanel(this: v46, parent: *((mxWindow **)this + 14));
  else
    g_pControlPanel = nullptr;
  Con_Printf(a1: v47, fmt: "Creating phoneme editor\n");
  v48 = (PhonemeEditor *)operator new(nSize: 0x6E4u);
  if ( v48 != nullptr )
    g_pPhonemeEditor = PhonemeEditor::PhonemeEditor(this: v48, parent: *((mxWindow **)this + 14));
  else
    g_pPhonemeEditor = nullptr;
  Con_Printf(a1: v49, fmt: "Creating expression tool\n");
  v50 = (ExpressionTool *)operator new(nSize: 0x35Cu);
  if ( v50 != nullptr )
    g_pExpressionTool = ExpressionTool::ExpressionTool(this: v50, parent: *((mxWindow **)this + 14));
  else
    g_pExpressionTool = nullptr;
  Con_Printf(a1: v51, fmt: "Creating gesture tool\n");
  v52 = (GestureTool *)operator new(nSize: 0x2F8u);
  if ( v52 != nullptr )
    g_pGestureTool = GestureTool::GestureTool(this: v52, parent: *((mxWindow **)this + 14));
  else
    g_pGestureTool = nullptr;
  Con_Printf(a1: v53, fmt: "Creating ramp tool\n");
  v54 = (RampTool *)operator new(nSize: 0x300u);
  if ( v54 != nullptr )
    g_pRampTool = RampTool::RampTool(this: v54, parent: *((mxWindow **)this + 14));
  else
    g_pRampTool = nullptr;
  Con_Printf(a1: v55, fmt: "Creating scene ramp tool\n");
  v56 = (SceneRampTool *)operator new(nSize: 0x2F4u);
  if ( v56 != nullptr )
    g_pSceneRampTool = SceneRampTool::SceneRampTool(this: v56, parent: *((mxWindow **)this + 14));
  else
    g_pSceneRampTool = nullptr;
  Con_Printf(a1: v57, fmt: "Creating expression tray\n");
  v58 = (mxExpressionTray *)operator new(nSize: 0x2ECu);
  if ( v58 != nullptr )
    g_pExpressionTrayTool = mxExpressionTray::mxExpressionTray(this: v58, parent: *((mxWindow **)this + 14), id: 5002);
  else
    g_pExpressionTrayTool = nullptr;
  Con_Printf(a1: v59, fmt: "Creating animation browser\n");
  v60 = (AnimationBrowser *)operator new(nSize: 0x414u);
  if ( v60 != nullptr )
    g_pAnimationBrowserTool = AnimationBrowser::AnimationBrowser(this: v60, parent: *((mxWindow **)this + 14), id: 5003);
  else
    g_pAnimationBrowserTool = nullptr;
  Con_Printf(a1: v61, fmt: "Creating flex slider window\n");
  v62 = (FlexPanel *)operator new(nSize: 0x1494u);
  if ( v62 != nullptr )
    g_pFlexPanel = FlexPanel::FlexPanel(this: v62, parent: *((mxWindow **)this + 14));
  else
    g_pFlexPanel = nullptr;
  Con_Printf(a1: v63, fmt: "Creating wave browser\n");
  v64 = (CWaveBrowser *)operator new(nSize: 0x310u);
  if ( v64 != nullptr )
    `CUtlRBTree<CUtlSymbolTree::FileTreePath,int,bool (__cdecl *)(CUtlSymbolTree::FileTreePath const &,CUtlSymbolTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = (int)CWaveBrowser::CWaveBrowser(this: v64, parent: *((mxWindow **)this + 14));
  else
    `CUtlRBTree<CUtlSymbolTree::FileTreePath,int,bool (__cdecl *)(CUtlSymbolTree::FileTreePath const &,CUtlSymbolTree::FileTreePath const &),CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTree::FileTreePath,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements = 0;
  Con_Printf(a1: v65, fmt: "Creating VCD browser\n");
  v66 = (CVCDBrowser *)operator new(nSize: 0x308u);
  if ( v66 != nullptr )
    g_pVCDBrowser = CVCDBrowser::CVCDBrowser(this: v66, parent: *((mxWindow **)this + 14));
  else
    g_pVCDBrowser = nullptr;
  Con_Printf(a1: v67, fmt: "Creating choreography view\n");
  v68 = (CChoreoView *)operator new(nSize: 0x53Cu);
  if ( v68 != nullptr )
    v69 = CChoreoView::CChoreoView(
            this: v68,
            a2: i,
            parent: *((mxWindow **)this + 14),
            x: 200,
            y: 200,
            w: 400,
            h: 300,
            id: 0);
  else
    v69 = nullptr;
  g_pChoreoView = v69;
  IFacePoserToolWindow::SetUseForMainWindowTitle(this: &v69->IFacePoserToolWindow, use: true);
  Con_Printf(a1: v70, fmt: "IFacePoserToolWindow::Init\n");
  IFacePoserToolWindow::InitTools();
  Con_Printf(a1: v71, fmt: "windowtab->Init\n");
  v103 = *((int **)this + 15);
  v72 = 0;
  ToolCount = IFacePoserToolWindow::GetToolCount();
  if ( ToolCount > 0 )
  {
    do
    {
      Tool = (CExpClass *)IFacePoserToolWindow::GetTool(index: v72);
      v75 = *v103;
      Name = CExpClass::GetName(this: Tool);
      (*(void (__thiscall **)(int *, char *))(v75 + 28))(a1: v103, a2: Name);
      ++v72;
    }
    while ( v72 < ToolCount );
  }
  Con_Printf(a1: v73, fmt: "loadRecentFiles\n");
  MDLViewer::loadRecentFiles(this);
  MDLViewer::initRecentFiles(this);
  Con_Printf(a1: v77, fmt: "RestoreThumbnailSize\n");
  mxExpressionTray::RestoreThumbnailSize(this: g_pExpressionTrayTool);
  AnimationBrowser::RestoreThumbnailSize(this: g_pAnimationBrowserTool);
  Con_Printf(a1: v78, fmt: "Add Tool Windows\n");
  v79 = IFacePoserToolWindow::GetToolCount();
  for ( j = 0; j < v79; ++j )
  {
    v81 = (CChoreoChannel *)IFacePoserToolWindow::GetTool(index: j);
    v82 = CChoreoChannel::GetName(this: v81);
    mxPopupMenu::add(this: *((mxPopupMenu **)this + 8), item: v82, id: j + 1200);
  }
  mxMenu::addSeparator(this: *((mxPopupMenu **)this + 8));
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 8), item: "Cascade", id: 1234);
  mxMenu::addSeparator(this: *((mxPopupMenu **)this + 8));
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 8), item: "Tile", id: 1237);
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 8), item: "Tile Horizontally", id: 1232);
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 8), item: "Tile Vertically", id: 1233);
  mxMenu::addSeparator(this: *((mxPopupMenu **)this + 8));
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 8), item: "Hide All", id: 1235);
  mxPopupMenu::add(this: *((mxPopupMenu **)this + 8), item: "Show All", id: 1236);
  Con_Printf(a1: v83, fmt: "UpdateWindowMenu\n");
  v85 = IFacePoserToolWindow::GetToolCount();
  for ( k = 0; k < v85; ++k )
  {
    v87 = IFacePoserToolWindow::GetTool(index: k);
    v88 = v87->GetMxWindow(this: v87);
    isVisible = mxWidget::isVisible(this: v88);
    mxMenu::setChecked(this: *((mxPopupMenu **)this + 8), id: k + 1200, b: isVisible);
  }
  cclanguageid = g_viewerSettings.cclanguageid;
  if ( this->menuView != nullptr )
  {
    for ( m = 0; m < 12; ++m )
      mxMenu::setChecked(this: (mxPopupMenu *)this->menuView, id: m + 1150, b: m == cclanguageid);
  }
  *((_DWORD *)this + 18) = 0;
  Con_Printf(a1: v84, fmt: "gridsettings->Init()\n");
  CMDLViewerGridSettings::Init(this: *((CMDLViewerGridSettings **)this + 17));
  Con_Printf(a1: v92, fmt: "LoadWindowPositions\n");
  v93 = mxWidget::w(this);
  v94 = mxWidget::h(this);
  g_viewerSettings.width = v93;
  g_viewerSettings.height = v94;
  v96 = IFacePoserToolWindow::GetToolCount();
  for ( n = 0; n < v96; ++n )
  {
    v98 = IFacePoserToolWindow::GetTool(index: n);
    IFacePoserToolWindow::LoadPosition(this: v98);
  }
  Con_Printf(a1: v95, fmt: "Model viewer created\n");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00463E20
// Name: public: virtual int MDLViewer::handleEvent(class mxEvent __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall MDLViewer::handleEvent(MDLViewer *this, int event)
{
  void (*BeginLock)(void); // edx
  mxEvent *v4; // edi
  int v5; // ebx
  int v6; // eax
  CTabWindow *v7; // ecx
  int v8; // ebx
  int BestHeight; // eax
  CTabWindow *v10; // ecx
  mxEvent *v11; // eax
  mxWidget *v12; // ecx
  int v13; // edi
  int v14; // ecx
  int v15; // ebx
  char *v16; // edi
  int v17; // eax
  char v18; // cl
  char *v19; // eax
  char v20; // cl
  float *v21; // edi
  const char *SaveFileName; // eax
  CExpClass *v23; // edi
  int v24; // esi
  CExpression *Expression; // ebx
  IProgressDialog_vtbl *v26; // edi
  float v27; // xmm1_4
  int v28; // eax
  CExpClass *v29; // eax
  CExpClass *v30; // esi
  CExpClass *v31; // eax
  bool isChecked; // al
  bool v33; // al
  int v34; // eax
  int v35; // eax
  mxWidget *v36; // esi
  IFacePoserToolWindow *Tool; // eax
  bool isVisible; // al
  unsigned int v39; // edi
  IFacePoserToolWindow *ActiveTool; // eax
  int v41; // eax
  int CloseCaptionLanguageId; // eax
  _DWORD v44[969]; // [esp+0h] [ebp-1158h]
  CExpClass *v45; // [esp+F24h] [ebp-234h]
  void *(__cdecl **v46)(const char *, int *); // [esp+F28h] [ebp-230h]
  int v47; // [esp+F2Ch] [ebp-22Ch]
  char classfile[512]; // [esp+F34h] [ebp-224h] BYREF
  float *cols[3]; // [esp+1134h] [ebp-24h]
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+1140h] [ebp-18h]
  int width; // [esp+1144h] [ebp-14h]
  int gridstart; // [esp+1148h] [ebp-10h]
  Color rgb; // [esp+114Ch] [ebp-Ch] BYREF
  int b; // [esp+1150h] [ebp-8h] BYREF
  CExpClass *active; // [esp+1154h] [ebp-4h] BYREF

  BeginLock = (void (*)(void))g_pMDLCache->BeginLock;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock();
  v4 = (mxEvent *)event;
  v5 = 0;
  switch ( *(_DWORD *)(event + 4) )
  {
    case 0:
      v14 = *(_DWORD *)(event + 12);
      v5 = 1;
      event = 1;
      if ( v14 <= 1301 )
      {
        if ( v14 == 1301 )
        {
          ShellExecuteA(
            hwnd: nullptr,
            lpOperation: "open",
            lpFile: "http://developer.valvesoftware.com/wiki/Category:Choreography",
            lpParameters: nullptr,
            lpDirectory: nullptr,
            nShowCmd: 5);
          goto LABEL_97;
        }
        switch ( v14 )
        {
          case 1001:
            if ( filesystem->IsSteam(this: filesystem) )
            {
              MDLViewer::LoadModel_Steam(this: g_MDLViewer);
            }
            else if ( FacePoser_ShowOpenFileNameDialog(
                        relative: classfile,
                        bufsize: 0x200u,
                        subdir: "models",
                        wildcard: "*.mdl") != 0 )
            {
              MDLViewer::LoadModelFile(this, pszFile: classfile);
            }
            goto LABEL_97;
          case 1002:
          case 1003:
            if ( mxGetOpenFileName(parent: this, path: nullptr, filter: "*.*") != nullptr )
              mxMessageBox(parent: this, msg: "Error loading texture.", title: g_appTitle, style: 8);
            goto LABEL_97;
          case 1004:
            ControlPanel::setShowGround(this: g_pControlPanel, b: false);
            goto LABEL_97;
          case 1008:
          case 1009:
          case 1010:
          case 1011:
          case 1012:
          case 1013:
          case 1014:
          case 1015:
            v15 = (v14 - 1008) << 8;
            v16 = &recentFiles[0][v15];
            if ( (char (*)[256])((char *)recentFiles + v15) == nullptr || *v16 == 0 )
              goto LABEL_33;
            V_ExtractFileExtension(path: &recentFiles[0][v15], dest: (char *)&active, destSize: 4);
            if ( _V_stricmp(s1: (const char *)&active, s2: "mdl") != 0 )
            {
              if ( _V_stricmp(s1: (const char *)&active, s2: "vcd") != 0 )
                goto LABEL_33;
              CChoreoView::LoadSceneFromFile(this: g_pChoreoView, a2: v15, a3: (int)v16, filename: &recentFiles[0][v15]);
            }
            else
            {
              MDLViewer::LoadModelFile(this, pszFile: &recentFiles[0][v15]);
            }
            v17 = 0;
            do
            {
              v18 = recentFiles[0][v17];
              classfile[v17++ + 256] = v18;
            }
            while ( v18 != 0 );
            v19 = &recentFiles[0][v15];
            do
            {
              v20 = *v19;
              v19[-v15] = *v19;
              ++v19;
            }
            while ( v20 != 0 );
            strcpy(&recentFiles[0][v15], &classfile[256]);
            MDLViewer::initRecentFiles(this);
LABEL_33:
            this->redraw(this);
            v5 = event;
            goto LABEL_97;
          case 1016:
            this->redraw(this);
            mx::quit();
            goto LABEL_97;
          case 1017:
            MDLViewer::Refresh(this);
            goto LABEL_97;
          case 1018:
            MDLViewer::OnSaveSoundScriptChanges(this);
            goto LABEL_97;
          case 1019:
            MDLViewer::OnRebuildScenesImage(this);
            goto LABEL_97;
          case 1020:
            v29 = expressions->GetActiveClass(this: expressions);
            v30 = v29;
            if ( v29 != nullptr )
            {
              CExpClass::Save(this: v29);
              CExpClass::Export(this: v30);
            }
            goto LABEL_97;
          case 1021:
            if ( FacePoser_ShowOpenFileNameDialog(
                   relative: classfile,
                   bufsize: 0x200u,
                   subdir: "expressions",
                   wildcard: "*.txt") != 0 )
              expressions->LoadClass(this: expressions, a2: classfile);
            goto LABEL_97;
          case 1023:
            v31 = expressions->GetActiveClass(this: expressions);
            if ( v31 != nullptr )
              CExpClass::Export(this: v31);
            goto LABEL_97;
          case 1024:
            ControlPanel::Close(this: g_pControlPanel);
            goto LABEL_97;
          case 1025:
            ControlPanel::Closeall(this: g_pControlPanel);
            goto LABEL_97;
          case 1026:
            if ( FacePoser_ShowSaveFileNameDialog(
                   relative: classfile,
                   bufsize: 0x200u,
                   subdir: "expressions",
                   wildcard: "*.txt") != 0 )
            {
              V_DefaultExtension(path: classfile, extension: ".txt", pathStringLength: 512);
              expressions->CreateNewClass(this: expressions, a2: classfile);
            }
            goto LABEL_97;
          case 1027:
            v23 = expressions->GetActiveClass(this: expressions);
            active = v23;
            if ( v23 == nullptr )
              goto LABEL_97;
            g_pProgressDialog->Start(this: g_pProgressDialog, a2: "Rebuild Bitmaps", a3: defaultValue, a4: true);
            MatSysWindow::EnableStickySnapshotMode(this: g_pMatSysWindow);
            v24 = 0;
            if ( CExpClass::GetNumExpressions(this: v23) <= 0 )
              goto LABEL_53;
            break;
          case 1028:
            MDLViewer::OnUpdateScenesImage(this, a2: (int)v4);
            goto LABEL_97;
          case 1030:
            CChoreoView::New(this: g_pChoreoView, a2: 1);
            goto LABEL_97;
          case 1031:
            CChoreoView::Load(this: g_pChoreoView, a2: 1, a3: (int)v4);
            goto LABEL_97;
          case 1032:
            CChoreoView::Save(this: g_pChoreoView, a2: 1);
            goto LABEL_97;
          case 1033:
            CChoreoView::SaveAs(this: g_pChoreoView, a2: (int)v4);
            goto LABEL_97;
          case 1034:
            CChoreoView::Close(this: g_pChoreoView, a2: 1);
            goto LABEL_97;
          case 1035:
            CChoreoView::NewActor(this: g_pChoreoView);
            goto LABEL_97;
          case 1037:
            isChecked = mxMenu::isChecked(this: *((mxMenu **)this + 12), id: 1037);
            CChoreoView::SetScrubUnitSeconds(this: g_pChoreoView, bUseSeconds: !isChecked);
            v33 = mxMenu::isChecked(this: *((mxMenu **)this + 12), id: 1037);
            mxMenu::setChecked(this: *((mxPopupMenu **)this + 12), id: 1037, b: !v33);
            goto LABEL_97;
          case 1038:
            CChoreoView::LoadNext(this: g_pChoreoView, a2: (int)this);
            goto LABEL_97;
          case 1101:
          case 1102:
          case 1103:
            cols[0] = g_viewerSettings.bgColor;
            cols[1] = g_viewerSettings.gColor;
            cols[2] = g_viewerSettings.lColor;
            v21 = (float *)v44[v14];
            event = (int)(float)(*v21 * 255.0);
            active = (CExpClass *)(int)(float)(v21[1] * 255.0);
            b = (int)(float)(v21[2] * 255.0);
            if ( mxChooseColor(parent: this, r: &event, g: (int *)&active, &b) )
            {
              *v21 = (float)event * 0.0039215689;
              v21[1] = (float)(int)active * 0.0039215689;
              v21[2] = (float)b * 0.0039215689;
            }
            goto LABEL_97;
          case 1104:
            ControlPanel::centerView(this: g_pControlPanel);
            goto LABEL_97;
          case 1105:
            SaveFileName = mxGetSaveFileName(parent: this, path: defaultValue, filter: "*.tga");
            if ( SaveFileName != nullptr )
            {
              V_strncpy(pDest: classfile, pSrc: SaveFileName, maxLen: 512);
              V_SetExtension(path: classfile, extension: ".tga", pathStringLength: 512);
              MatSysWindow::TakeScreenShot(this: g_pMatSysWindow, filename: classfile);
            }
            goto LABEL_97;
          case 1106:
            CSteamApplication::PostShutdown(pFactoryList: v46, nFactoryCount: v47);
            goto LABEL_97;
          case 1107:
            ControlPanel::CenterOnFace(this: g_pControlPanel);
            goto LABEL_97;
          case 1108:
            sound->StopAll(this: sound);
            rgb = (Color)16737280;
            Con_ColorPrintf(&rgb, fmt: "Resetting model sound channels\n");
            goto LABEL_97;
          case 1232:
            v34 = CountVisibleTools();
            MDLViewer::DoTile(this, x: v34, y: 1);
            goto LABEL_97;
          case 1233:
            v35 = CountVisibleTools();
            MDLViewer::DoTile(this, x: 1, y: v35);
            goto LABEL_97;
          case 1234:
            MDLViewer::OnCascade(this);
            goto LABEL_97;
          case 1235:
            MDLViewer::OnHideAll(this);
            goto LABEL_97;
          case 1236:
            MDLViewer::OnShowAll(this);
            goto LABEL_97;
          case 1237:
            MDLViewer::OnTile(this);
            goto LABEL_97;
          case 1238:
            CMDLViewerWindowTab::HandleWindowSelect(this: *((CMDLViewerWindowTab **)this + 15));
            goto LABEL_97;
          case 1239:
            CMDLViewerModelTab::HandleModelSelect(this: *((CMDLViewerModelTab **)this + 16));
            goto LABEL_97;
          default:
            goto LABEL_82;
        }
        while ( 1 )
        {
          Expression = CExpClass::GetExpression(this: v23, num: v24);
          if ( Expression != nullptr )
          {
            g_pProgressDialog->UpdateText(this: g_pProgressDialog, a2: (const char *)Expression);
            v26 = g_pProgressDialog->__vftable;
            *(float *)&gridstart = (float)v24;
            v27 = (float)v24 / (float)CExpClass::GetNumExpressions(this: active);
            ((void (__thiscall *)(IProgressDialog *, _DWORD))v26->Update)(a1: g_pProgressDialog, a2: LODWORD(v27));
            if ( g_pProgressDialog->IsCancelled(this: g_pProgressDialog) )
            {
              _Msg(a1: "Cancelled\n");
              v23 = active;
LABEL_52:
              v5 = event;
LABEL_53:
              MatSysWindow::DisableStickySnapshotMode(this: g_pMatSysWindow);
              g_pProgressDialog->Finish(this: g_pProgressDialog);
              CExpClass::SelectExpression(this: v23, num: 0, deselect: true);
              goto LABEL_97;
            }
            v28 = models->GetActiveModelIndex(this: models);
            CExpression::CreateNewBitmap(this: Expression, modelindex: v28);
            if ( v24 % 5 == 0 )
              g_pExpressionTrayTool->redraw(this: g_pExpressionTrayTool);
          }
          v23 = active;
          if ( ++v24 >= CExpClass::GetNumExpressions(this: active) )
            goto LABEL_52;
        }
      }
      if ( v14 == 1302 )
      {
        mxMessageBox(parent: this, msg: aV10Copyright, title: "Valve Face Poser", style: 4);
      }
      else
      {
        if ( v14 == 1400 )
          MDLViewer::OnPlaySceneInFoundry(this);
LABEL_82:
        v36 = (mxWidget *)(v4->action - 1200);
        v5 = 0;
        if ( (unsigned int)v36 <= 0x1F && (int)v36 < IFacePoserToolWindow::GetToolCount() )
        {
          v5 = 1;
          Tool = IFacePoserToolWindow::GetTool(index: (int)v36);
          if ( Tool != nullptr )
          {
            v36 = Tool->GetMxWindow(this: Tool);
            isVisible = mxWidget::isVisible(this: v36);
            mxWidget::setVisible(this: v36, b: !isVisible);
            MDLViewer::UpdateWindowMenu(this: g_MDLViewer);
          }
        }
        v39 = v4->action - 1150;
        if ( v39 <= 0xB )
        {
          v5 = 1;
          SetCloseCaptionLanguageId(a1: (int)v36, id: v39, force: false);
        }
      }
LABEL_97:
      cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
      return v5;
    case 1:
      width = mxWidget::w2(this);
      v6 = mxWidget::h2(this);
      v7 = *((CTabWindow **)this + 15);
      b = v6;
      CTabWindow::SetRowHeight(this: v7, rowheight: 22);
      CTabWindow::SetRowHeight(this: *((CTabWindow **)this + 16), rowheight: 22);
      gridstart = width - 105;
      v8 = (width - 105) / 3;
      active = (CExpClass *)(width - 105 - v8);
      BestHeight = CTabWindow::GetBestHeight(this: *((CTabWindow **)this + 15), width: (int)active);
      if ( BestHeight <= CTabWindow::GetBestHeight(this: *((CTabWindow **)this + 16), width: v8) )
      {
        v10 = *((CTabWindow **)this + 16);
        v45 = (CExpClass *)((width - 105) / 3);
      }
      else
      {
        v45 = active;
        v10 = *((CTabWindow **)this + 15);
      }
      v11 = (mxEvent *)CTabWindow::GetBestHeight(this: v10, width: (int)v45);
      v12 = *((mxWidget **)this + 14);
      v13 = b - (_DWORD)v11;
      event = (int)v11;
      mxWidget::setBounds(this: v12, x: 0, y: 0, w: width, h: b - (_DWORD)v11);
      mxWidget::setBounds(this: *((mxWidget **)this + 17), x: gridstart, y: v13 + 1, w: 100, h: 22);
      mxWidget::setBounds(this: *((mxWidget **)this + 15), x: 0, y: v13, w: (int)active, h: event);
      mxWidget::setBounds(this: *((mxWidget **)this + 16), x: (int)active, y: v13, w: v8, h: event);
      event = 1;
      v5 = 1;
      goto LABEL_97;
    case 0xB:
      ActiveTool = IFacePoserToolWindow::GetActiveTool();
      if ( ActiveTool != nullptr )
      {
        v41 = (int)ActiveTool->GetMxWindow(this: ActiveTool);
        if ( v41 != 0 )
          (*(void (__thiscall **)(int, mxEvent *))(*(_DWORD *)v41 + 12))(a1: v41, a2: v4);
      }
      else
      {
        g_pMatSysWindow->handleEvent(this: g_pMatSysWindow, a2: v4);
      }
      goto LABEL_96;
    case 0xE:
      if ( *(_DWORD *)(event + 12) != 0 )
      {
        mx::setIdleWindow(window: g_pMatSysWindow);
        CloseCaptionLanguageId = GetCloseCaptionLanguageId();
        SetCloseCaptionLanguageId(a1: (int)this, id: CloseCaptionLanguageId, force: true);
      }
      else
      {
        mx::setIdleWindow(window: nullptr);
      }
LABEL_96:
      v5 = 1;
      goto LABEL_97;
    default:
      goto LABEL_97;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004648F0
// Name: public: virtual int CHLFacePoserApp::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CHLFacePoserApp::Main@<eax>(CHLFacePoserApp *this@<ecx>, int a2@<esi>)
{
  int v2; // eax
  MDLViewer *v3; // eax
  MDLViewer *v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  const char *v8; // eax
  int v9; // eax
  int v10; // eax
  const char *v11; // eax
  MDLViewer *v12; // edi
  const char *v13; // esi
  int v14; // ebx
  int i; // edi
  IExpressionManager_vtbl *v16; // esi
  const char *v17; // eax
  int v18; // esi

  CP4Factory::SetDummyMode(this: g_p4factory, bDummyMode: false);
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-nop4") != 0 )
    CP4Factory::SetDummyMode(this: g_p4factory, bDummyMode: true);
  CP4Factory::SetOpenFileChangeList(this: g_p4factory, szChangeListName: "FacePoser Auto Checkout");
  g_pMaterialSystem->ModInit(this: g_pMaterialSystem);
  g_pDataCache->SetSize(this: g_pDataCache, a2: 0x4000000);
  g_pLocalize->AddFile(this: g_pLocalize, a2: "resource/closecaption_english.txt", a3: "GAME", a4: true);
  sound->Init(this: sound);
  IFacePoserToolWindow::EnableToolRedraw(enabled: false);
  v3 = (MDLViewer *)operator new(nSize: 0x64u);
  if ( v3 != nullptr )
    v4 = MDLViewer::MDLViewer(this: v3);
  else
    v4 = nullptr;
  g_MDLViewer = v4;
  mxWindow::setMenuBar(this: v4, menuBar: (mxMenuBar *)v4->d_MatSysWindow);
  SetCloseCaptionLanguageId(a1: a2, id: g_viewerSettings.cclanguageid, force: true);
  StudioModel::Init();
  v5 = 1;
  v6 = _CommandLine();
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 36))(a1: v6) > 1 )
  {
    while ( 1 )
    {
      v7 = _CommandLine();
      v8 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 44))(a1: v7);
      if ( V_stristr(pStr: v8, pSearch: (const char *)v5) != nullptr )
        break;
      ++v5;
      v9 = _CommandLine();
      if ( v5 >= (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 36))(a1: v9) )
        goto LABEL_11;
    }
    v10 = _CommandLine();
    v11 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v10 + 44))(a1: v10, a2: v5);
    v12 = g_MDLViewer;
    v13 = v11;
    models->LoadModel(this: models, a2: v11);
    MDLViewer::OnFileLoaded(this: v12, pszFile: v13);
    ControlPanel::CenterOnFace(this: g_pControlPanel);
  }
LABEL_11:
  models->LoadModelList(this: models);
  PhonemeEditor::ValidateSpeechAPIIndex(this: g_pPhonemeEditor);
  if ( models->Count(this: models) == 0 )
    FlexPanel::initFlexes(this: g_pFlexPanel);
  v14 = workspacefiles->GetNumStoredFiles(this: workspacefiles, a2: 0);
  for ( i = 0; i < v14; ++i )
  {
    v16 = expressions->__vftable;
    v17 = workspacefiles->GetStoredFile(this: workspacefiles, a2: 0, a3: i);
    v16->LoadClass(this: expressions, a2: v17);
  }
  IFacePoserToolWindow::EnableToolRedraw(enabled: true);
  v18 = mx::run();
  if ( g_pStudioModel != nullptr )
  {
    StudioModel::Shutdown();
    g_pStudioModel = nullptr;
  }
  g_pMaterialSystem->ModShutdown(this: g_pMaterialSystem);
  return v18;
}

//------------------------------------------------------------------------------
// Address: 0x00464B40
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  void (__thiscall ***v3)(_DWORD, int, const char **); // eax
  int v4; // esi
  char workingdir[256]; // [esp+108h] [ebp-2DCh] BYREF
  CHLFacePoserApp hlFacePoserApp; // [esp+208h] [ebp-1DCh] BYREF
  CSteamApplication steamApplication; // [esp+374h] [ebp-70h] BYREF

  v3 = (void (__thiscall ***)(_DWORD, int, const char **))_CommandLine();
  (**v3)(a1: v3, a2: argc, a3: argv);
  CoInitialize(pvReserved: nullptr);
  strlen(mx::getApplicationPath());
  mx::init(argc, (char **)argv);
  workingdir[0] = 0;
  Q_getwd(out: workingdir, outSize: 256);
  SetSuggestGameInfoDirFn(pfnNewFn: (bool (__cdecl *)(const CFSSteamSetupInfo *, char *, int, bool *))CHLFacePoserApp_SuggestGameInfoDirFn);
  CSteamAppSystemGroup::CSteamAppSystemGroup(this: &hlFacePoserApp, pFileSystem: nullptr, pAppSystemParent: nullptr);
  hlFacePoserApp.__vftable = (CHLFacePoserApp_vtbl *)&CHLFacePoserApp::`vftable';
  CSteamApplication::CSteamApplication(this: &steamApplication, pAppSystemGroup: &hlFacePoserApp);
  v4 = CAppSystemGroup::Run(this: &steamApplication);
  CoUninitialize();
  CUtlDict<int,unsigned short>::RemoveAll(this: &steamApplication.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &steamApplication.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&steamApplication.m_NonAppSystemFactories);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&steamApplication.m_Systems);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&steamApplication.m_Modules);
  CUtlDict<int,unsigned short>::RemoveAll(this: &hlFacePoserApp.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &hlFacePoserApp.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&hlFacePoserApp.m_NonAppSystemFactories);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&hlFacePoserApp.m_Systems);
  CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>::~CUtlVector<IFaceposerModels::CFacePoserModel::AnimBitmap *,CUtlMemory<IFaceposerModels::CFacePoserModel::AnimBitmap *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&hlFacePoserApp.m_Modules);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004949B0
// Name: protected: static void __near * (*CAppSystemGroup::GetFactory(void))(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void *(__cdecl *__cdecl CAppSystemGroup::GetFactory())(const char *, int *)
{
  return AppSystemCreateInterfaceFn;
}
