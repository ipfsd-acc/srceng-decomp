// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scenemanager/scenemanager_tools.cpp
// Functions: 142
// ============================================================

#include "utils\scenemanager\scenemanager_tools.h"

//------------------------------------------------------------------------------
// Address: 0x0040A670
// Name: void SceneManager_AddWindowStyle(class mxWindow __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SceneManager_AddWindowStyle(mxWindow *w, int addbits)
{
  HWND Handle; // esi
  LONG WindowLongA; // eax

  Handle = (HWND)mxWidget::getHandle(this: w);
  WindowLongA = GetWindowLongA(hWnd: Handle, nIndex: -16);
  SetWindowLongA(hWnd: Handle, nIndex: -16, dwNewLong: addbits | WindowLongA);
}

//------------------------------------------------------------------------------
// Address: 0x0040A6A0
// Name: void SceneManager_MakeToolWindow(class mxWindow __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SceneManager_MakeToolWindow(mxWindow *w, bool smallcaption)
{
  HWND Handle; // ebx
  LONG WindowLongA; // eax
  HWND v4; // eax
  LONG v5; // eax
  HWND v6; // esi
  LONG v7; // eax
  HWND v8; // esi
  LONG v9; // eax
  HWND smallcaptiona; // [esp+18h] [ebp+Ch]

  Handle = (HWND)mxWidget::getHandle(this: w);
  WindowLongA = GetWindowLongA(hWnd: Handle, nIndex: -16);
  SetWindowLongA(hWnd: Handle, nIndex: -16, dwNewLong: WindowLongA | 0x16CF0000);
  v4 = (HWND)mxWidget::getHandle(this: w);
  if ( smallcaption )
  {
    smallcaptiona = v4;
    v5 = GetWindowLongA(hWnd: v4, nIndex: -20);
    SetWindowLongA(hWnd: smallcaptiona, nIndex: -20, dwNewLong: v5 | 0x300);
    v6 = (HWND)mxWidget::getHandle(this: w);
    v7 = GetWindowLongA(hWnd: v6, nIndex: -20);
    SetWindowLongA(hWnd: v6, nIndex: -20, dwNewLong: v7 | 0x80);
  }
  else
  {
    v8 = v4;
    v9 = GetWindowLongA(hWnd: v4, nIndex: -16);
    SetWindowLongA(hWnd: v8, nIndex: -16, dwNewLong: v9 & 0xFFF7FFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A730
// Name: char __near * va(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *va(const char *fmt, ...)
{
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, fmt);
  ++outbuffer;
  vprintf(format: fmt, ap);
  vsprintf(string: output_2[outbuffer & 3], format: fmt, ap);
  return output_2[outbuffer & 3];
}

//------------------------------------------------------------------------------
// Address: 0x0040A780
// Name: void Con_Printf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Con_Printf(const char *fmt, ...)
{
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, fmt);
  vsprintf(string: output_3, format: fmt, ap);
  if ( g_pStatusWindow != nullptr )
    CStatusWindow::StatusPrint(this: g_pStatusWindow, r: 82, g: 173, b: 216, overwrite: false, text: output_3);
}

//------------------------------------------------------------------------------
// Address: 0x0040A7C0
// Name: void Con_ColorPrintf(int,int,int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Con_ColorPrintf(int r, int g, int b, const char *fmt, ...)
{
  va_list ap; // [esp+18h] [ebp+18h] BYREF

  va_start(ap, fmt);
  vprintf(format: fmt, ap);
  vsprintf(string: output_4, format: fmt, ap);
  if ( g_pStatusWindow != nullptr )
    CStatusWindow::StatusPrint(this: g_pStatusWindow, r, g, b, overwrite: false, text: output_4);
}

//------------------------------------------------------------------------------
// Address: 0x0040A810
// Name: char const __near * SceneManager_GetGameDirectory(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl SceneManager_GetGameDirectory()
{
  return gamedir;
}

//------------------------------------------------------------------------------
// Address: 0x0040A820
// Name: SceneManager_VSSCheckout
// Source: json
//------------------------------------------------------------------------------
void __usercall SceneManager_VSSCheckout(
        const char *pRelativeDir@<edi>,
        const char *pFileNameWithExtension@<esi>,
        const char *pUserName,
        const char *pProjectDir,
        const char *pDestPath)
{
  char buf[1024]; // [esp+4h] [ebp-800h] BYREF
  char string[1024]; // [esp+404h] [ebp-400h] BYREF

  sprintf(
    string: buf,
    format: "filetype %s/%s%s -O- -y%s\n",
    pProjectDir,
    pRelativeDir,
    pFileNameWithExtension,
    pUserName);
  sprintf(string, format: "%s %s\n", "ss.exe", buf);
  strlwr(string);
  if ( system(command: string) != 0 )
  {
    Con_Printf(fmt: "File %s missing from VSS\n", pFileNameWithExtension);
  }
  else
  {
    sprintf(
      string: buf,
      format: "checkout %s/%s%s -GL%s -GWA -O- -y%s\n",
      pProjectDir,
      pRelativeDir,
      pFileNameWithExtension,
      pDestPath,
      pUserName);
    sprintf(string, format: "%s %s\n", "ss.exe", buf);
    strlwr(string);
    if ( system(command: string) != 0 )
      Con_Printf(fmt: "Execution failed: %s\n", string);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A910
// Name: SceneManager_VSSCheckin
// Source: json
//------------------------------------------------------------------------------
void __usercall SceneManager_VSSCheckin(
        const char *pUserName@<esi>,
        const char *pFileNameWithExtension@<edi>,
        const char *pProjectDir,
        const char *pRelativeDir,
        const char *pDestPath)
{
  const char *v5; // [esp+0h] [ebp-838h]
  char buf[1024]; // [esp+8h] [ebp-830h] BYREF
  char string[1024]; // [esp+408h] [ebp-430h] BYREF
  _stat64i32 statbuf; // [esp+808h] [ebp-30h] BYREF

  sprintf(string: buf, format: "%s%s", pDestPath, v5);
  if ( _stat64i32(name: buf, buf: &statbuf) == 0 )
  {
    sprintf(
      string: buf,
      format: "filetype %s/%s%s -O- -y%s\n",
      pProjectDir,
      pRelativeDir,
      pFileNameWithExtension,
      pUserName);
    sprintf(string, format: "%s %s\n", "ss.exe", buf);
    strlwr(string);
    if ( system(command: string) == 0 )
    {
      sprintf(
        string: buf,
        format: "checkin %s/%s%s -GL%s -O- -I- -y%s\n",
        pProjectDir,
        pRelativeDir,
        pFileNameWithExtension,
        pDestPath,
        pUserName);
      sprintf(string, format: "%s %s\n", "ss.exe", buf);
      strlwr(string);
      if ( system(command: string) == 0 )
        return;
      goto LABEL_8;
    }
    sprintf(string: buf, format: "Cp %s -O- -y%s\n", pProjectDir, pUserName);
    sprintf(string, format: "%s %s\n", "ss.exe", buf);
    strlwr(string);
    if ( system(command: string) != 0 )
      Con_Printf(fmt: "Execution failed: %s\n", string);
    sprintf(
      string: buf,
      format: "add %s%s -GL%s -O- -I- -y%s\n",
      pRelativeDir,
      pFileNameWithExtension,
      pDestPath,
      pUserName);
    sprintf(string, format: "%s %s\n", "ss.exe", buf);
    strlwr(string);
    if ( system(command: string) != 0 )
LABEL_8:
      Con_Printf(fmt: "Execution failed: %s\n", string);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040AAF0
// Name: void SplitFileName(char const __near *,char __near *,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SplitFileName(const char *in, char *path, int maxpath, char *filename, int maxfilename)
{
  char fname[256]; // [esp+0h] [ebp-304h] BYREF
  char ext[256]; // [esp+100h] [ebp-204h] BYREF
  char dir[256]; // [esp+200h] [ebp-104h] BYREF
  char drive[4]; // [esp+300h] [ebp-4h] BYREF

  _splitpath(path: in, drive, dir, fname, ext);
  if ( dir[0] != 0 )
    V_snprintf(pDest: path, maxLen: maxpath, pFormat: "\\%s", dir);
  else
    *path = 0;
  V_snprintf(pDest: filename, maxLen: maxfilename, pFormat: "%s%s", fname, ext);
}

//------------------------------------------------------------------------------
// Address: 0x0040AB80
// Name: void VSS_Checkout(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VSS_Checkout(const char *name, bool updatestaticons)
{
  CWorkspaceManager *WorkspaceManager; // eax
  IterateRIFF *Browser; // eax
  CWorkspace *Count; // edi
  char *VSSUserName; // eax
  CWorkspaceManager *v6; // eax
  char *VSSProject; // [esp-Ch] [ebp-210h]
  const char *v8; // [esp-8h] [ebp-20Ch]
  char filename[256]; // [esp+4h] [ebp-200h] BYREF
  char path[256]; // [esp+104h] [ebp-100h] BYREF

  WorkspaceManager = GetWorkspaceManager();
  Browser = (IterateRIFF *)CWorkspaceManager::GetBrowser(this: WorkspaceManager);
  Count = (CWorkspace *)CCurveData::GetCount(this: Browser);
  if ( Count != nullptr && !filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: name, a3: nullptr) )
  {
    SplitFileName(in: name, path, maxpath: 256, filename, maxfilename: 256);
    Con_ColorPrintf(r: 200, g: 200, b: 100, fmt: "VSS Checkout:  '%s'\n", name);
    v8 = va(fmt: "%s%s", gamedir, path);
    VSSProject = CWorkspace::GetVSSProject(this: Count);
    VSSUserName = CWorkspace::GetVSSUserName(this: Count);
    SceneManager_VSSCheckout(
      pRelativeDir: path,
      pFileNameWithExtension: filename,
      pUserName: VSSUserName,
      pProjectDir: VSSProject,
      pDestPath: v8);
    if ( updatestaticons )
    {
      v6 = GetWorkspaceManager();
      CWorkspaceManager::RefreshBrowsers(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040AC60
// Name: void VSS_Checkin(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VSS_Checkin(const char *name, bool updatestaticons)
{
  CWorkspaceManager *WorkspaceManager; // eax
  IterateRIFF *Browser; // eax
  CWorkspace *Count; // edi
  char *VSSUserName; // eax
  CWorkspaceManager *v6; // eax
  char *VSSProject; // [esp-10h] [ebp-214h]
  const char *v8; // [esp-8h] [ebp-20Ch]
  char filename[256]; // [esp+4h] [ebp-200h] BYREF
  char path[256]; // [esp+104h] [ebp-100h] BYREF

  WorkspaceManager = GetWorkspaceManager();
  Browser = (IterateRIFF *)CWorkspaceManager::GetBrowser(this: WorkspaceManager);
  Count = (CWorkspace *)CCurveData::GetCount(this: Browser);
  if ( Count != nullptr && filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: name, a3: nullptr) )
  {
    SplitFileName(in: name, path, maxpath: 256, filename, maxfilename: 256);
    Con_ColorPrintf(r: 200, g: 200, b: 100, fmt: "VSS Checkin:  '%s'\n", name);
    v8 = va(fmt: "%s%s", gamedir, path);
    VSSProject = CWorkspace::GetVSSProject(this: Count);
    VSSUserName = CWorkspace::GetVSSUserName(this: Count);
    SceneManager_VSSCheckin(
      pUserName: VSSUserName,
      pFileNameWithExtension: filename,
      pProjectDir: VSSProject,
      pRelativeDir: path,
      pDestPath: v8);
    if ( updatestaticons )
    {
      v6 = GetWorkspaceManager();
      CWorkspaceManager::RefreshBrowsers(this: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040AD40
// Name: void SceneManager_LoadWindowPositions(class KeyValues __near *,class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SceneManager_LoadWindowPositions(KeyValues *kv, mxWindow *wnd)
{
  bool v2; // bl
  int Int; // edi
  int v4; // eax
  HWND Handle; // eax
  int y; // [esp+Ch] [ebp-8h]
  int w; // [esp+10h] [ebp-4h]

  v2 = KeyValues::GetInt(this: kv, keyName: "zoomed", defaultValue: 0) != 0;
  Int = KeyValues::GetInt(this: kv, keyName: "x", defaultValue: 0);
  y = KeyValues::GetInt(this: kv, keyName: "y", defaultValue: 0);
  w = KeyValues::GetInt(this: kv, keyName: "w", defaultValue: 400);
  v4 = KeyValues::GetInt(this: kv, keyName: "h", defaultValue: 300);
  mxWidget::setBounds(this: wnd, x: Int, y, w, h: v4);
  if ( v2 )
  {
    Handle = (HWND)mxWidget::getHandle(this: wnd);
    ShowWindow(hWnd: Handle, nCmdShow: 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040ADE0
// Name: void SceneManager_SaveWindowPositions(class CUtlBuffer __near &,int,class mxWindow __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SceneManager_SaveWindowPositions(CUtlBuffer *buf, int indent, mxWindow *wnd)
{
  mxWindow *v3; // ebx
  mxWindow *Parent; // eax
  HWND Handle; // eax
  int v6; // edi
  int i; // ebx
  HWND v8; // eax
  bool v9; // bl
  tagPOINT pt; // [esp+Ch] [ebp-18h] BYREF
  int h; // [esp+14h] [ebp-10h]
  int w; // [esp+18h] [ebp-Ch]
  int y; // [esp+1Ch] [ebp-8h]
  int x; // [esp+20h] [ebp-4h]
  int indenta; // [esp+30h] [ebp+Ch]
  int indentb; // [esp+30h] [ebp+Ch]

  v3 = wnd;
  x = mxWidget::x(this: wnd);
  y = mxWidget::y(this: wnd);
  w = mxWidget::w(this: wnd);
  h = mxWidget::h(this: wnd);
  pt.x = x;
  pt.y = y;
  if ( mxWidget::getParent(this: wnd) != nullptr )
  {
    Parent = mxWidget::getParent(this: wnd);
    Handle = (HWND)mxWidget::getHandle(this: Parent);
    ScreenToClient(hWnd: Handle, lpPoint: &pt);
    x = SLOWORD(pt.x);
    y = SLOWORD(pt.y);
  }
  v6 = indent;
  if ( indent > 0 )
  {
    do
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\t");
      --indent;
    }
    while ( indent != 0 );
  }
  CUtlBuffer::Printf(this: buf, pFmt: "\"x\"\t\"%i\"\n", x);
  if ( v6 > 0 )
  {
    for ( indenta = v6; indenta != 0; --indenta )
      CUtlBuffer::Printf(this: buf, pFmt: "\t");
  }
  CUtlBuffer::Printf(this: buf, pFmt: "\"y\"\t\"%i\"\n", y);
  if ( v6 > 0 )
  {
    for ( indentb = v6; indentb != 0; --indentb )
      CUtlBuffer::Printf(this: buf, pFmt: "\t");
  }
  CUtlBuffer::Printf(this: buf, pFmt: "\"w\"\t\"%i\"\n", w);
  if ( v6 > 0 )
  {
    for ( i = v6; i != 0; --i )
      CUtlBuffer::Printf(this: buf, pFmt: "\t");
    v3 = wnd;
  }
  CUtlBuffer::Printf(this: buf, pFmt: "\"h\"\t\"%i\"\n", h);
  v8 = (HWND)mxWidget::getHandle(this: v3);
  v9 = IsZoomed(hWnd: v8);
  if ( v6 > 0 )
  {
    do
    {
      CUtlBuffer::Printf(this: buf, pFmt: "\t");
      --v6;
    }
    while ( v6 != 0 );
  }
  CUtlBuffer::Printf(this: buf, pFmt: "\"zoomed\"\t\"%i\"\n", v9);
}

//------------------------------------------------------------------------------
// Address: 0x0040AF60
// Name: void MakeFileWriteable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakeFileWriteable(const char *filename)
{
  char fullpath[512]; // [esp+0h] [ebp-200h] BYREF

  if ( filesystem->GetLocalPath(this: filesystem, a2: filename, a3: fullpath, a4: 512) != nullptr )
  {
    V_FixSlashes(pname: fullpath, separator: 92);
    SetFileAttributesA(lpFileName: fullpath, dwFileAttributes: 0x80u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040AFC0
// Name: public: virtual int StdIOWriteBinary::create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall StdIOWriteBinary::create(StdIOWriteBinary *this, const char *pFileName)
{
  return filesystem->Open(this: &filesystem->IBaseFileSystem, a2: pFileName, a3: "wb", a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0040AFF0
// Name: public: virtual int StdIOWriteBinary::write(void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall StdIOWriteBinary::write(StdIOWriteBinary *this, void *pData, int size, void *file)
{
  return filesystem->Write(this: &filesystem->IBaseFileSystem, a2: pData, a3: size, a4: file);
}

//------------------------------------------------------------------------------
// Address: 0x0040B010
// Name: public: virtual void StdIOWriteBinary::close(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StdIOWriteBinary::close(StdIOWriteBinary *this, void *file)
{
  filesystem->Close(this: &filesystem->IBaseFileSystem, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x0040B030
// Name: public: virtual void StdIOWriteBinary::seek(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StdIOWriteBinary::seek(StdIOWriteBinary *this, void *file, int pos)
{
  filesystem->Seek(this: &filesystem->IBaseFileSystem, a2: file, a3: pos, a4: FILESYSTEM_SEEK_HEAD);
}

//------------------------------------------------------------------------------
// Address: 0x0040B060
// Name: public: virtual unsigned int StdIOWriteBinary::tell(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall StdIOWriteBinary::tell(StdIOWriteBinary *this, void *file)
{
  return filesystem->Tell(this: &filesystem->IBaseFileSystem, a2: file);
}

//------------------------------------------------------------------------------
// Address: 0x0040B080
// Name: SceneManager_StoreValveDataChunk
// Source: json
//------------------------------------------------------------------------------
void __cdecl SceneManager_StoreValveDataChunk(CSentence *sentence, IterateOutputRIFF *store)
{
  CUtlBuffer buf; // [esp+0h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  CSentence::SaveToBuffer(this: sentence, &buf);
  IterateOutputRIFF::ChunkWriteData(this: store, pOutput: buf.m_Memory.m_pMemory, size: buf.m_Put);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x0040B0E0
// Name: bool SceneManager_SaveSentenceToWavFile(char const __near *,class CSentence __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall SceneManager_SaveSentenceToWavFile@<al>(int a1@<ebx>, const char *wavfile, CSentence *sentence)
{
  const char *v3; // eax
  char v5; // bl
  unsigned int Count; // eax
  char tempfile[512]; // [esp+4h] [ebp-290h] BYREF
  OutFileRIFF riffout; // [esp+204h] [ebp-90h] BYREF
  CUtlBuffer buf; // [esp+220h] [ebp-74h] BYREF
  InFileRIFF riff; // [esp+250h] [ebp-44h] BYREF
  IterateOutputRIFF store; // [esp+260h] [ebp-34h] BYREF
  IterateRIFF walk; // [esp+27Ch] [ebp-18h] BYREF

  V_StripExtension(in: wavfile, out: tempfile, outSize: 512);
  V_DefaultExtension(path: tempfile, extension: ".tmp", pathStringLength: 512);
  if ( filesystem->FileExists(this: &filesystem->IBaseFileSystem, a2: tempfile, a3: "GAME") )
    filesystem->RemoveFile(this: filesystem, a2: tempfile, a3: "GAME");
  if ( !filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: wavfile, a3: nullptr) )
  {
    v3 = va(fmt: "Check out '%s'?", wavfile);
    if ( MultipleRequest(prompt: v3) != 0 )
      return 0;
    VSS_Checkout(name: wavfile, updatestaticons: true);
  }
  if ( !filesystem->IsFileWritable(this: &filesystem->IBaseFileSystem, a2: wavfile, a3: nullptr) )
  {
    Con_Printf(fmt: "%s is not writable, can't save sentence data to file\n", wavfile);
    return 0;
  }
  ((void (__thiscall *)(IFileSystem *, const char *, char *, const char *, int))filesystem->RenameFile)(
    a1: filesystem,
    a2: wavfile,
    a3: tempfile,
    a4: "GAME",
    a5: a1);
  InFileRIFF::InFileRIFF(this: &riff, pFileName: tempfile, io: &io_in);
  IterateRIFF::IterateRIFF(this: &walk, &riff, size: riff.m_riffSize);
  OutFileRIFF::OutFileRIFF(this: &riffout, pFileName: wavfile, io: &io_out);
  IterateOutputRIFF::IterateOutputRIFF(this: &store, riff: &riffout);
  v5 = 0;
  if ( !IterateRIFF::ChunkAvailable(this: &walk) )
    goto LABEL_18;
  do
  {
    Count = CCurveData::GetCount(this: &walk);
    IterateOutputRIFF::ChunkStart(this: &store, chunkname: Count);
    if ( CCurveData::GetCount(this: &walk) == 1413563478 )
    {
      CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
      CSentence::SaveToBuffer(this: sentence, &buf);
      IterateOutputRIFF::ChunkWriteData(this: &store, pOutput: buf.m_Memory.m_pMemory, size: buf.m_Put);
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
      v5 = 1;
    }
    else
    {
      IterateOutputRIFF::CopyChunkData(this: &store, input: &walk);
    }
    IterateOutputRIFF::ChunkFinish(this: &store);
    IterateRIFF::ChunkNext(this: &walk);
  }
  while ( IterateRIFF::ChunkAvailable(this: &walk) );
  if ( v5 == 0 )
  {
LABEL_18:
    IterateOutputRIFF::ChunkStart(this: &store, chunkname: 0x54414456u);
    SceneManager_StoreValveDataChunk(sentence, &store);
    IterateOutputRIFF::ChunkFinish(this: &store);
  }
  OutFileRIFF::~OutFileRIFF(this: &riffout);
  InFileRIFF::~InFileRIFF(this: &riff);
  ((void (__thiscall *)(IFileSystem *, char *))filesystem->RemoveFile)(a1: filesystem, a2: tempfile);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040B320
// Name: bool SceneManager_LoadSentenceFromWavFileUsingIO(char const __near *,class CSentence __near &,class IFileReadBinary __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SceneManager_LoadSentenceFromWavFileUsingIO(const char *wavfile, CSentence *sentence, IFileReadBinary *io)
{
  char v4; // bl
  int NumEvents; // eax
  int v6; // eax
  CUtlBuffer v7; // [esp+4h] [ebp-58h] BYREF
  IterateRIFF walk; // [esp+34h] [ebp-28h] BYREF
  InFileRIFF riff; // [esp+4Ch] [ebp-10h] BYREF

  CSentence::Reset(this: sentence);
  InFileRIFF::InFileRIFF(this: &riff, pFileName: wavfile, io);
  if ( riff.m_riffName == 1163280727 )
  {
    IterateRIFF::IterateRIFF(this: &walk, &riff, size: riff.m_riffSize);
    v4 = 0;
    while ( IterateRIFF::ChunkAvailable(this: &walk) )
    {
      if ( v4 != 0 )
        break;
      if ( CCurveData::GetCount(this: &walk) == 1413563478 )
      {
        v4 = 1;
        CUtlBuffer::CUtlBuffer(this: &v7, growSize: 0, initSize: 0, nFlags: 1);
        NumEvents = CChoreoScene::GetNumEvents(this: &walk);
        CUtlBuffer::EnsureCapacity(this: &v7, num: NumEvents);
        IterateRIFF::ChunkRead(this: &walk, pOutput: v7.m_Memory.m_pMemory);
        v6 = CChoreoScene::GetNumEvents(this: &walk);
        CUtlBuffer::SeekPut(this: &v7, type: SEEK_HEAD, offset: v6);
        CSentence::InitFromDataChunk(this: sentence, data: v7.m_Memory.m_pMemory, size: v7.m_Put);
        if ( v7.m_Memory.m_nGrowSize >= 0 && v7.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7.m_Memory.m_pMemory);
      }
      IterateRIFF::ChunkNext(this: &walk);
    }
    InFileRIFF::~InFileRIFF(this: &riff);
    return 1;
  }
  else
  {
    InFileRIFF::~InFileRIFF(this: &riff);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B430
// Name: bool SceneManager_LoadSentenceFromWavFile(char const __near *,class CSentence __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SceneManager_LoadSentenceFromWavFile(const char *wavfile, CSentence *sentence)
{
  return SceneManager_LoadSentenceFromWavFileUsingIO(wavfile, sentence, io: &io_in);
}

//------------------------------------------------------------------------------
// Address: 0x00446934
// Name: __write
// Source: json
//------------------------------------------------------------------------------
int __cdecl _write(int fh, const void *buf, unsigned int cnt)
{
  ioinfo **v4; // edi
  int v5; // esi
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v4 = &__pioinfo[fh >> 5], v5 = (fh & 0x1F) << 6, (*(&(*v4)->osfile + v5) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v4)->osfile + v5) & 1) != 0 )
  {
    r = _write_nolock(fh, buf, cnt);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x00446A08
// Name: __chsize_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _chsize_nolock(int filedes, __int64 size)
{
  __int64 v2; // rax
  int v3; // edi
  unsigned int v4; // esi
  HANDLE ProcessHeap; // eax
  unsigned int v7; // eax
  int v8; // eax
  bool v9; // of
  unsigned int v10; // kr08_4
  int v11; // esi
  HANDLE v12; // eax
  __int64 v13; // rax
  void *osfhandle; // eax
  unsigned int *v15; // esi
  __int64 v16; // rax
  __int64 place; // [esp+Ch] [ebp-18h]
  __int64 retval; // [esp+14h] [ebp-10h]
  int oldmode; // [esp+1Ch] [ebp-8h]
  char *v20; // [esp+20h] [ebp-4h]

  HIDWORD(retval) = 0;
  place = _lseeki64_nolock(fh: filedes, pos: 0, mthd: 1);
  if ( (HIDWORD(place) & (unsigned int)place) == 0xFFFFFFFF )
    return *_errno();
  v2 = _lseeki64_nolock(fh: filedes, pos: 0, mthd: 2);
  if ( (HIDWORD(v2) & (unsigned int)v2) == 0xFFFFFFFF )
    return *_errno();
  v3 = (unsigned __int64)(size - v2) >> 32;
  v4 = size - v2;
  if ( v3 >= 0 && (size >= v2 && (unsigned __int64)(size - v2) >> 32 != 0 || v4 != 0) )
  {
    ProcessHeap = GetProcessHeap();
    v20 = (char *)HeapAlloc(hHeap: ProcessHeap, dwFlags: 8u, dwBytes: 0x1000u);
    if ( v20 == nullptr )
    {
      *_errno() = 12;
      return *_errno();
    }
    oldmode = _setmode_nolock(fh: filedes, mode: 0x8000);
    while ( 1 )
    {
      v7 = v3 < 0 || v3 <= 0 && v4 < 0x1000 ? v4 : 4096;
      v8 = _write_nolock(fh: filedes, buf: v20, cnt: v7);
      if ( v8 == -1 )
        break;
      v9 = __OFSUB__(__PAIR64__(v3, v4), v8);
      v10 = v4 - v8;
      v3 = (__PAIR64__(v3, v4) - v8) >> 32;
      v4 -= v8;
      if ( v3 < 0 || (v3 < 0) ^ v9 | (v3 == 0) && v10 == 0 )
      {
        v11 = 0;
        goto LABEL_20;
      }
    }
    if ( *__doserrno() == 5 )
      *_errno() = 13;
    v11 = -1;
    HIDWORD(retval) = -1;
LABEL_20:
    _setmode_nolock(fh: filedes, mode: oldmode);
    v12 = GetProcessHeap();
    HeapFree(hHeap: v12, dwFlags: 0, lpMem: v20);
    goto LABEL_28;
  }
  if ( v3 < 0 )
  {
    v13 = _lseeki64_nolock(fh: filedes, pos: size, mthd: 0);
    if ( (HIDWORD(v13) & (unsigned int)v13) == 0xFFFFFFFF )
      return *_errno();
    osfhandle = (void *)_get_osfhandle(fh: filedes);
    retval = SetEndOfFile(hFile: osfhandle) - 1;
    if ( (HIDWORD(retval) & (unsigned int)retval) == 0xFFFFFFFF )
    {
      *_errno() = 13;
      v15 = __doserrno();
      *v15 = GetLastError();
      v11 = retval;
LABEL_28:
      if ( (HIDWORD(retval) & v11) == 0xFFFFFFFF )
        return *_errno();
    }
  }
  v16 = _lseeki64_nolock(fh: filedes, pos: place, mthd: 0);
  if ( (HIDWORD(v16) & (unsigned int)v16) == 0xFFFFFFFF )
    return *_errno();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00446BBE
// Name: __setmode_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmode_nolock(int fh, int mode)
{
  ioinfo **v2; // edx
  int v3; // esi
  char *v4; // ecx
  int v5; // edi
  int v6; // eax
  _BYTE *v7; // ecx
  char v8; // dl

  v2 = &__pioinfo[fh >> 5];
  v3 = (fh & 0x1F) << 6;
  v4 = (char *)*v2 + v3;
  v5 = v4[4] & 0x80;
  v6 = (char)(2 * v4[36]) >> 1;
  if ( mode == 0x4000 )
  {
    v4[4] |= 0x80u;
    *((_BYTE *)*v2 + v3 + 36) &= 0x80u;
  }
  else if ( mode == 0x8000 )
  {
    v4[4] &= ~0x80u;
  }
  else
  {
    if ( mode == 0x10000 || mode == 0x20000 )
    {
      v4[4] |= 0x80u;
      v7 = (char *)*v2 + v3 + 36;
      v8 = *v7 & 0x80 | 2;
    }
    else
    {
      if ( mode != 0x40000 )
        goto LABEL_11;
      v4[4] |= 0x80u;
      v7 = (char *)*v2 + v3 + 36;
      v8 = *v7 & 0x80 | 1;
    }
    *v7 = v8;
  }
LABEL_11:
  if ( v5 != 0 )
    return v6 != 0 ? 0x10000 : 0x4000;
  else
    return 0x8000;
}

//------------------------------------------------------------------------------
// Address: 0x00446C79
// Name: __get_fmode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_fmode(int *pMode)
{
  if ( pMode != nullptr )
  {
    *pMode = _fmode;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00446CA6
// Name: _tzset_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void tzset_nolock()
{
  unsigned __int8 *v0; // eax
  unsigned __int8 *v1; // esi
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // edi
  int v6; // edi
  int v7; // edi
  char **v8; // edi
  const char *v9; // esi
  char v10; // al
  int v11; // eax
  int v12; // eax
  int v13; // esi
  int v14; // esi
  int negdiff; // [esp+14h] [ebp-38h]
  UINT lc_cp; // [esp+18h] [ebp-34h]
  int defused; // [esp+1Ch] [ebp-30h] BYREF
  int nochange; // [esp+20h] [ebp-2Ch]
  int dstbias; // [esp+24h] [ebp-28h] BYREF
  int daylight; // [esp+28h] [ebp-24h] BYREF
  char **tzname; // [esp+2Ch] [ebp-20h]
  int timezone; // [esp+30h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+34h] [ebp-18h]

  negdiff = 0;
  nochange = 0;
  timezone = 0;
  daylight = 0;
  dstbias = 0;
  _lock(locknum: 7);
  ms_exc.registration.TryLevel = 0;
  tzname = __tzname();
  if ( _get_timezone(_Timezone: &timezone) != 0
    || _get_daylight(_Daylight: &daylight) != 0
    || _get_dstbias(_Daylight_savings_bias: &dstbias) != 0 )
  {
LABEL_12:
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  }
  lc_cp = ___lc_codepage_func();
  tzapiused = 0;
  dstend.yr = -1;
  dststart.yr = -1;
  v0 = (unsigned __int8 *)_getenv_helper_nolock(option: "TZ");
  v1 = v0;
  if ( v0 == nullptr || *v0 == 0 )
  {
    if ( lastTZ != nullptr )
    {
      free(pMem: lastTZ);
      lastTZ = nullptr;
    }
    if ( GetTimeZoneInformation(lpTimeZoneInformation: &tzinfo) != -1 )
    {
      tzapiused = 1;
      timezone = 60 * tzinfo.Bias;
      if ( tzinfo.StandardDate.wMonth != 0 )
        timezone = 60 * tzinfo.StandardBias + 60 * tzinfo.Bias;
      if ( tzinfo.DaylightDate.wMonth != 0 && tzinfo.DaylightBias != 0 )
      {
        daylight = 1;
        dstbias = 60 * (tzinfo.DaylightBias - tzinfo.StandardBias);
      }
      else
      {
        daylight = 0;
        dstbias = 0;
      }
      if ( WideCharToMultiByte(
             CodePage: lc_cp,
             dwFlags: 0,
             lpWideCharStr: tzinfo.StandardName,
             cchWideChar: -1,
             lpMultiByteStr: *tzname,
             cbMultiByte: 63,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: &defused) == 0
        || defused != 0 )
      {
        **tzname = 0;
      }
      else
      {
        (*tzname)[63] = 0;
      }
      if ( WideCharToMultiByte(
             CodePage: lc_cp,
             dwFlags: 0,
             lpWideCharStr: tzinfo.DaylightName,
             cchWideChar: -1,
             lpMultiByteStr: tzname[1],
             cbMultiByte: 63,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: &defused) == 0
        || defused != 0 )
      {
        *tzname[1] = 0;
      }
      else
      {
        tzname[1][63] = 0;
      }
    }
    goto LABEL_30;
  }
  if ( lastTZ != nullptr )
  {
    strcmp(str1: v0, str2: (unsigned __int8 *)lastTZ);
    if ( v2 == 0 )
    {
LABEL_30:
      nochange = 1;
      goto LABEL_31;
    }
    if ( lastTZ != nullptr )
      free(pMem: lastTZ);
  }
  strlen(buf: v1);
  lastTZ = (char *)operator new(nSize: v3 + 1);
  if ( lastTZ == nullptr )
    goto LABEL_30;
  strlen(buf: v1);
  if ( strcpy_s(_Dst: lastTZ, _SizeInBytes: v4 + 1, _Src: (const char *)v1) != 0 )
    goto LABEL_12;
LABEL_31:
  v5 = timezone;
  *__timezone() = v5;
  v6 = daylight;
  *__daylight() = v6;
  v7 = dstbias;
  *__dstbias() = v7;
  ms_exc.registration.TryLevel = -2;
  _unlock(locknum: 7);
  if ( nochange == 0 )
  {
    v8 = tzname;
    if ( strncpy_s(_Dst: *tzname, _SizeInBytes: 0x40u, _Src: (const char *)v1, _Count: 3u) != 0 )
      goto LABEL_12;
    v9 = (const char *)(v1 + 3);
    if ( *v9 == 45 )
    {
      negdiff = 1;
      ++v9;
    }
    timezone = 3600 * atol(nptr: v9);
    while ( 1 )
    {
      v10 = *v9;
      if ( *v9 != 43 && (v10 < 48 || v10 > 57) )
        break;
      ++v9;
    }
    if ( *v9 == 58 )
    {
      v11 = atol(nptr: ++v9);
      timezone += 60 * v11;
      while ( *v9 >= 48 && *v9 <= 57 )
        ++v9;
      if ( *v9 == 58 )
      {
        v12 = atol(nptr: ++v9);
        timezone += v12;
        while ( *v9 >= 48 && *v9 <= 57 )
          ++v9;
      }
    }
    if ( negdiff != 0 )
      timezone = -timezone;
    daylight = *v9;
    if ( daylight != 0 )
    {
      if ( strncpy_s(_Dst: v8[1], _SizeInBytes: 0x40u, _Src: v9, _Count: 3u) != 0 )
        goto LABEL_12;
    }
    else
    {
      *v8[1] = 0;
    }
    v13 = timezone;
    *__timezone() = v13;
    v14 = daylight;
    *__daylight() = v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004471B0
// Name: _isindst_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall isindst_nolock@<eax>(tm *tb@<edi>)
{
  int result; // eax
  int tm_year; // edx
  int v3; // eax
  int v4; // ecx
  int tm_yday; // edx
  int v6; // eax
  int endmonth; // [esp+4h] [ebp-Ch]
  int endweek; // [esp+8h] [ebp-8h]
  int daylight; // [esp+Ch] [ebp-4h] BYREF

  daylight = 0;
  result = _get_daylight(_Daylight: &daylight);
  if ( result != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  if ( daylight != 0 )
  {
    tm_year = tb->tm_year;
    if ( tm_year != dststart.yr || tm_year != dstend.yr )
    {
      if ( tzapiused != 0 )
      {
        if ( tzinfo.DaylightDate.wYear != 0 )
          cvtdate(
            trantype: 1,
            datetype: 0,
            year: tm_year,
            month: tzinfo.DaylightDate.wMonth,
            week: 0,
            dayofweek: 0,
            date: tzinfo.DaylightDate.wDay,
            hour: tzinfo.DaylightDate.wHour,
            min: tzinfo.DaylightDate.wMinute,
            sec: tzinfo.DaylightDate.wSecond,
            msec: tzinfo.DaylightDate.wMilliseconds);
        else
          cvtdate(
            trantype: 1,
            datetype: 1,
            year: tm_year,
            month: tzinfo.DaylightDate.wMonth,
            week: tzinfo.DaylightDate.wDay,
            dayofweek: tzinfo.DaylightDate.wDayOfWeek,
            date: 0,
            hour: tzinfo.DaylightDate.wHour,
            min: tzinfo.DaylightDate.wMinute,
            sec: tzinfo.DaylightDate.wSecond,
            msec: tzinfo.DaylightDate.wMilliseconds);
        if ( tzinfo.StandardDate.wYear != 0 )
          cvtdate(
            trantype: 0,
            datetype: 0,
            year: tb->tm_year,
            month: tzinfo.StandardDate.wMonth,
            week: 0,
            dayofweek: 0,
            date: tzinfo.StandardDate.wDay,
            hour: tzinfo.StandardDate.wHour,
            min: tzinfo.StandardDate.wMinute,
            sec: tzinfo.StandardDate.wSecond,
            msec: tzinfo.StandardDate.wMilliseconds);
        else
          cvtdate(
            trantype: 0,
            datetype: 1,
            year: tb->tm_year,
            month: tzinfo.StandardDate.wMonth,
            week: tzinfo.StandardDate.wDay,
            dayofweek: tzinfo.StandardDate.wDayOfWeek,
            date: 0,
            hour: tzinfo.StandardDate.wHour,
            min: tzinfo.StandardDate.wMinute,
            sec: tzinfo.StandardDate.wSecond,
            msec: tzinfo.StandardDate.wMilliseconds);
      }
      else
      {
        v3 = 3;
        v4 = 2;
        endmonth = 11;
        endweek = 1;
        if ( tm_year < 107 )
        {
          v3 = 4;
          v4 = 1;
          endmonth = 10;
          endweek = 5;
        }
        cvtdate(
          trantype: 1,
          datetype: 1,
          year: tm_year,
          month: v3,
          week: v4,
          dayofweek: 0,
          date: 0,
          hour: 2,
          min: 0,
          sec: 0,
          msec: 0);
        cvtdate(
          trantype: 0,
          datetype: 1,
          year: tb->tm_year,
          month: endmonth,
          week: endweek,
          dayofweek: 0,
          date: 0,
          hour: 2,
          min: 0,
          sec: 0,
          msec: 0);
      }
    }
    tm_yday = tb->tm_yday;
    if ( dststart.yd >= dstend.yd )
    {
      if ( tm_yday < dstend.yd || tm_yday > dststart.yd )
        return 1;
      if ( tm_yday <= dstend.yd || tm_yday >= dststart.yd )
        goto LABEL_28;
    }
    else if ( tm_yday >= dststart.yd && tm_yday <= dstend.yd )
    {
      if ( tm_yday > dststart.yd && tm_yday < dstend.yd )
        return 1;
LABEL_28:
      v6 = 1000 * (tb->tm_sec + 60 * (tb->tm_min + 60 * tb->tm_hour));
      if ( tm_yday == dststart.yd )
        return v6 >= dststart.ms;
      else
        return v6 < dstend.ms;
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00447387
// Name: ___tzset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __tzset()
{
  if ( first_time == 0 )
  {
    _lock(locknum: 6);
    if ( first_time == 0 )
    {
      tzset_nolock();
      ++first_time;
    }
    _unlock(locknum: 6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004473D6
// Name: __isindst
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isindst(tm *tb)
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 6);
  retval = isindst_nolock(tb);
  _unlock(locknum: 6);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x00447417
// Name: __get_daylight
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_daylight(int *_Daylight)
{
  if ( _Daylight != nullptr )
  {
    *_Daylight = _daylight;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447444
// Name: __get_dstbias
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_dstbias(int *_Daylight_savings_bias)
{
  if ( _Daylight_savings_bias != nullptr )
  {
    *_Daylight_savings_bias = _dstbias;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447471
// Name: __get_timezone
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_timezone(int *_Timezone)
{
  if ( _Timezone != nullptr )
  {
    *_Timezone = _timezone;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044749E
// Name: ___daylight
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __daylight()
{
  return &_daylight;
}

//------------------------------------------------------------------------------
// Address: 0x004474A4
// Name: ___dstbias
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __dstbias()
{
  return &_dstbias;
}

//------------------------------------------------------------------------------
// Address: 0x004474AA
// Name: ___timezone
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl __timezone()
{
  return &_timezone;
}

//------------------------------------------------------------------------------
// Address: 0x004474B0
// Name: ___tzname
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **__cdecl __tzname()
{
  return _tzname;
}

//------------------------------------------------------------------------------
// Address: 0x004474B6
// Name: __commit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __cdecl _commit(int filedes)
{
  ioinfo **v2; // edi
  int v3; // esi
  void *osfhandle; // eax
  DWORD retval; // [esp+14h] [ebp-1Ch]

  if ( filedes == -2 )
  {
    *_errno() = 9;
    return -1;
  }
  if ( filedes < 0
    || filedes >= _nhandle
    || (v2 = &__pioinfo[filedes >> 5], (*(&(*v2)->osfile + (v3 = (filedes & 0x1F) << 6)) & 1) == 0) )
  {
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh: filedes);
  if ( (*(&(*v2)->osfile + v3) & 1) != 0 )
  {
    osfhandle = (void *)_get_osfhandle(fh: filedes);
    if ( FlushFileBuffers(hFile: osfhandle) )
      retval = 0;
    else
      retval = GetLastError();
    if ( retval == 0 )
      goto good;
    *__doserrno() = retval;
  }
  *_errno() = 9;
  retval = -1;
good:
  _unlock_fhandle(fh: filedes);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x0044758F
// Name: __getbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _getbuf(_iobuf *str)
{
  char *v1; // eax
  char *base; // eax

  ++_cflush;
  v1 = (char *)operator new(nSize: 0x1000u);
  str->_base = v1;
  if ( v1 != nullptr )
  {
    str->_flag |= 8u;
    str->_bufsiz = 4096;
  }
  else
  {
    str->_flag |= 4u;
    str->_base = (char *)&str->_charbuf;
    str->_bufsiz = 2;
  }
  base = str->_base;
  str->_cnt = 0;
  str->_ptr = base;
}

//------------------------------------------------------------------------------
// Address: 0x004475D8
// Name: __mbtowc_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbtowc_l(wchar_t *pwc, const char *s, signed int n, localeinfo_struct *plocinfo)
{
  int result; // eax
  threadlocaleinfostruct *locinfo; // eax
  int mb_cur_max; // ecx
  bool v7; // zf
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  if ( s == nullptr || n == 0 )
    return 0;
  if ( *s == 0 )
  {
    if ( pwc != nullptr )
      *pwc = 0;
    return 0;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->lc_handle[2] == 0 )
  {
    if ( pwc != nullptr )
      *pwc = *(unsigned __int8 *)s;
    goto LABEL_11;
  }
  if ( _isleadbyte_l(c: *(unsigned __int8 *)s, plocinfo: &_loc_update.localeinfo) != 0 )
  {
    locinfo = _loc_update.localeinfo.locinfo;
    mb_cur_max = _loc_update.localeinfo.locinfo->mb_cur_max;
    if ( mb_cur_max > 1
      && n >= mb_cur_max
      && (v7 = MultiByteToWideChar(
                 CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
                 dwFlags: 9u,
                 lpMultiByteStr: s,
                 cbMultiByte: mb_cur_max,
                 lpWideCharStr: pwc,
                 cchWideChar: pwc != nullptr) == 0,
          locinfo = _loc_update.localeinfo.locinfo,
          !v7)
      || (unsigned int)n >= locinfo->mb_cur_max && s[1] != 0 )
    {
      result = locinfo->mb_cur_max;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  else if ( MultiByteToWideChar(
              CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
              dwFlags: 9u,
              lpMultiByteStr: s,
              cbMultiByte: 1,
              lpWideCharStr: pwc,
              cchWideChar: pwc != nullptr) != 0 )
  {
LABEL_11:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 1;
  }
  *_errno() = 42;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004476EE
// Name: _mbtowc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl mbtowc(wchar_t *pwc, const char *s, unsigned int n)
{
  return _mbtowc_l(pwc, s, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00447708
// Name: __wcsnicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wcsnicoll_l(
        const wchar_t *_string1,
        const wchar_t *_string2,
        unsigned int count,
        localeinfo_struct *plocinfo)
{
  unsigned int v4; // ebx
  int result; // eax
  const wchar_t *v6; // esi
  unsigned int v7; // eax
  int v8; // edx
  unsigned int v9; // eax
  unsigned __int16 v10; // cx
  unsigned int v11; // eax
  int v12; // eax
  int *v13; // eax
  bool v14; // zf
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  v4 = count;
  if ( count == 0 )
    return 0;
  if ( _string1 == nullptr || (v6 = _string2, _string2 == nullptr) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0x7FFFFFFF;
  }
  if ( count > 0x7FFFFFFF )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0x7FFFFFFF;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v7 = _loc_update.localeinfo.locinfo->lc_handle[1];
  if ( v7 != 0 )
  {
    v12 = __crtCompareStringW(
            Locale: v7,
            dwCmpFlags: 0x1001u,
            lpString1: _string1,
            cchCount1: count,
            lpString2: _string2,
            cchCount2: count);
    if ( v12 == 0 )
    {
      v13 = _errno();
      v14 = !_loc_update.updated;
      *v13 = 22;
      if ( !v14 )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
    result = v12 - 2;
  }
  else
  {
    v8 = (char *)_string1 - (char *)_string2;
    do
    {
      v9 = *(const wchar_t *)((char *)v6 + v8);
      if ( v9 < 0x41 || v9 > 0x5A )
        v10 = *(const wchar_t *)((char *)v6 + v8);
      else
        v10 = v9 + 32;
      v11 = *v6;
      if ( v11 >= 0x41 && v11 <= 0x5A )
        LOWORD(v11) = v11 + 32;
      ++v6;
      --v4;
    }
    while ( v4 != 0 && v10 != 0 && v10 == (_WORD)v11 );
    result = v10 - (unsigned __int16)v11;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00447828
// Name: __wcsnicoll
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wcsnicoll(const wchar_t *_string1, const wchar_t *_string2, unsigned int count)
{
  const wchar_t *v3; // ecx
  int v5; // esi
  unsigned int v6; // eax
  unsigned __int16 v7; // dx
  unsigned int v8; // eax

  if ( __locale_changed != 0 )
    return _wcsnicoll_l(_string1, _string2, count, plocinfo: nullptr);
  if ( _string1 != nullptr && (v3 = _string2, _string2 != nullptr) && count <= 0x7FFFFFFF )
  {
    v5 = (char *)_string1 - (char *)_string2;
    do
    {
      v6 = *(const wchar_t *)((char *)v3 + v5);
      if ( v6 < 0x41 || v6 > 0x5A )
        v7 = *(const wchar_t *)((char *)v3 + v5);
      else
        v7 = v6 + 32;
      v8 = *v3;
      if ( v8 >= 0x41 && v8 <= 0x5A )
        LOWORD(v8) = v8 + 32;
      ++v3;
      --count;
    }
    while ( count != 0 && v7 != 0 && v7 == (_WORD)v8 );
    return v7 - (unsigned __int16)v8;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0x7FFFFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004478E2
// Name: ___mbtow_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __mbtow_environ()
{
  LPCCH *v0; // esi
  const char *v1; // eax
  unsigned int v2; // eax
  unsigned __int8 *v3; // eax
  int size; // [esp+Ch] [ebp-8h]
  unsigned __int16 *wenvp; // [esp+10h] [ebp-4h] BYREF

  v0 = (LPCCH *)_environ;
  wenvp = nullptr;
  v1 = *_environ;
  if ( *_environ == nullptr )
    return 0;
  while ( 1 )
  {
    v2 = MultiByteToWideChar(
           CodePage: 0,
           dwFlags: 0,
           lpMultiByteStr: v1,
           cbMultiByte: -1,
           lpWideCharStr: nullptr,
           cchWideChar: 0);
    size = v2;
    if ( v2 == 0 )
      return -1;
    v3 = calloc(count: v2, size: 2u);
    wenvp = (unsigned __int16 *)v3;
    if ( v3 == nullptr )
      return -1;
    if ( MultiByteToWideChar(
           CodePage: 0,
           dwFlags: 0,
           lpMultiByteStr: *v0,
           cbMultiByte: -1,
           lpWideCharStr: (LPWSTR)v3,
           cchWideChar: size) == 0 )
      goto LABEL_10;
    if ( __crtwsetenv(poption: &wenvp, primary: 0) < 0 )
    {
      if ( wenvp == nullptr )
        return -1;
LABEL_10:
      free(pMem: wenvp);
      return -1;
    }
    v1 = *++v0;
    if ( *v0 == nullptr )
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447969
// Name: __wsetenvp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wsetenvp()
{
  wchar_t *v0; // esi
  int v1; // edi
  unsigned __int8 *v3; // ebx
  wchar_t *i; // esi
  unsigned int v5; // eax
  unsigned int v6; // edi
  unsigned __int8 *v7; // eax

  v0 = _wenvptr;
  v1 = 0;
  if ( _wenvptr == nullptr )
    return -1;
  while ( *v0 != 0 )
  {
    if ( *v0 != 61 )
      ++v1;
    v0 += wcslen(wcs: v0) + 1;
  }
  v3 = calloc(count: v1 + 1, size: 4u);
  _wenviron = (unsigned __int16 **)v3;
  if ( v3 == nullptr )
    return -1;
  for ( i = _wenvptr; ; i += v6 )
  {
    if ( *i == 0 )
    {
      free(pMem: _wenvptr);
      _wenvptr = nullptr;
      *(_DWORD *)v3 = 0;
      __env_initialized = 1;
      return 0;
    }
    v5 = wcslen(wcs: i);
    v6 = v5 + 1;
    if ( *i != 61 )
      break;
LABEL_14:
    ;
  }
  v7 = calloc(count: v5 + 1, size: 2u);
  *(_DWORD *)v3 = v7;
  if ( v7 != nullptr )
  {
    if ( wcscpy_s(_Dst: (unsigned __int16 *)v7, _SizeInWords: v6, _Src: i) != 0 )
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    v3 += 4;
    goto LABEL_14;
  }
  free(pMem: _wenviron);
  _wenviron = nullptr;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00447A45
// Name: ___crtGetEnvironmentStringsW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl __crtGetEnvironmentStringsW()
{
  LPWCH EnvironmentStringsW; // eax
  unsigned __int8 *v1; // esi
  unsigned int v3; // ebx
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // edi

  EnvironmentStringsW = GetEnvironmentStringsW();
  v1 = (unsigned __int8 *)EnvironmentStringsW;
  if ( EnvironmentStringsW == nullptr )
    return nullptr;
  for ( ; *EnvironmentStringsW != 0; ++EnvironmentStringsW )
  {
    do
      ++EnvironmentStringsW;
    while ( *EnvironmentStringsW != 0 );
  }
  v3 = (char *)EnvironmentStringsW - (char *)v1 + 2;
  v4 = (unsigned __int8 *)operator new(nSize: v3);
  v5 = v4;
  if ( v4 != nullptr )
    memcpy(dst: v4, src: v1, count: v3);
  FreeEnvironmentStringsW(penv: (LPWCH)v1);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00447A9D
// Name: _wcschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl wcschr(const wchar_t *string, wchar_t ch)
{
  unsigned __int16 *result; // eax

  for ( result = (unsigned __int16 *)string; *result != 0; ++result )
  {
    if ( *result == ch )
      return result;
  }
  if ( *result != ch )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00447AC4
// Name: __crtCompareStringA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _crtCompareStringA_stat(
        localeinfo_struct *plocinfo,
        const char *lpString2,
        LCID Locale,
        DWORD dwCmpFlags,
        const char *lpString1,
        int cchCount1,
        int cchCount2,
        UINT code_page)
{
  const char *v8; // eax
  int v9; // edi
  int v11; // ecx
  int v12; // esi
  int v13; // ecx
  const char *v14; // eax
  unsigned __int8 *LeadByte; // eax
  unsigned __int8 v17; // dl
  unsigned __int8 *i; // eax
  unsigned __int8 v19; // dl
  int v20; // eax
  int v21; // ebx
  unsigned int v22; // eax
  void *v23; // esp
  wchar_t *v24; // eax
  int v25; // eax
  int v26; // ebx
  unsigned int v27; // eax
  void *v28; // esp
  wchar_t *v29; // eax
  wchar_t *v30; // edi
  _DWORD v32[3]; // [esp+0h] [ebp-38h] BYREF
  int buff_size1; // [esp+Ch] [ebp-2Ch]
  int retcode; // [esp+10h] [ebp-28h]
  LPCCH lpMultiByteStr; // [esp+14h] [ebp-24h]
  LPCCH v36; // [esp+18h] [ebp-20h]
  wchar_t *wbuffer1; // [esp+1Ch] [ebp-1Ch]
  _cpinfo lpCPInfo; // [esp+20h] [ebp-18h] BYREF

  v8 = lpString1;
  v9 = cchCount1;
  lpMultiByteStr = lpString1;
  v36 = lpString2;
  if ( cchCount1 <= 0 )
  {
    if ( cchCount1 < -1 )
      return 0;
  }
  else
  {
    v11 = cchCount1;
    while ( 1 )
    {
      --v11;
      if ( *v8 == 0 )
        break;
      ++v8;
      if ( v11 == 0 )
      {
        v11 = -1;
        break;
      }
    }
    v9 = -1 - v11 + cchCount1;
    cchCount1 = v9;
  }
  v12 = cchCount2;
  if ( cchCount2 <= 0 )
  {
    if ( cchCount2 < -1 )
      return 0;
  }
  else
  {
    v13 = cchCount2;
    v14 = lpString2;
    while ( 1 )
    {
      --v13;
      if ( *v14 == 0 )
        break;
      ++v14;
      if ( v13 == 0 )
      {
        v13 = -1;
        break;
      }
    }
    v12 = -1 - v13 + cchCount2;
    cchCount2 = v12;
  }
  retcode = 0;
  if ( code_page == 0 )
    code_page = plocinfo->locinfo->lc_codepage;
  if ( v9 != 0 && v12 != 0 )
    goto LABEL_44;
  if ( v9 == v12 )
    return 2;
  if ( v12 > 1 )
    return 1;
  if ( v9 > 1 )
    return 3;
  if ( !GetCPInfo(CodePage: code_page, &lpCPInfo) )
    return 0;
  if ( v9 > 0 )
  {
    if ( lpCPInfo.MaxCharSize >= 2 )
    {
      LeadByte = lpCPInfo.LeadByte;
      if ( lpCPInfo.LeadByte[0] != 0 )
      {
        while ( 1 )
        {
          v17 = LeadByte[1];
          if ( v17 == 0 )
            break;
          if ( (unsigned int)*lpMultiByteStr >= *LeadByte && (unsigned int)*lpMultiByteStr <= v17 )
            return 2;
          LeadByte += 2;
          if ( *LeadByte == 0 )
            return 3;
        }
      }
    }
    return 3;
  }
  if ( v12 > 0 )
  {
    if ( lpCPInfo.MaxCharSize >= 2 )
    {
      for ( i = lpCPInfo.LeadByte; *i != 0; i += 2 )
      {
        v19 = i[1];
        if ( v19 == 0 )
          break;
        if ( (unsigned int)*v36 >= *i && (unsigned int)*v36 <= v19 )
          return 2;
      }
    }
    return 1;
  }
LABEL_44:
  v20 = MultiByteToWideChar(
          CodePage: code_page,
          dwFlags: 9u,
          lpMultiByteStr,
          cbMultiByte: v9,
          lpWideCharStr: nullptr,
          cchWideChar: 0);
  v21 = v20;
  buff_size1 = v20;
  if ( v20 == 0 )
    return 0;
  if ( v20 > 0 && 0xFFFFFFE0 / v20 >= 2 )
  {
    v22 = 2 * v20 + 8;
    if ( v22 > 0x400 )
    {
      v24 = (wchar_t *)operator new(nSize: 2 * v21 + 8);
      if ( v24 != nullptr )
      {
        *(_DWORD *)v24 = 56797;
        goto LABEL_52;
      }
    }
    else
    {
      v23 = alloca(v22);
      v24 = (wchar_t *)v32;
      if ( v32 != nullptr )
      {
        v32[0] = 52428;
LABEL_52:
        v24 += 4;
      }
    }
    wbuffer1 = v24;
    goto LABEL_55;
  }
  wbuffer1 = nullptr;
LABEL_55:
  if ( wbuffer1 == nullptr )
    return 0;
  if ( MultiByteToWideChar(
         CodePage: code_page,
         dwFlags: 1u,
         lpMultiByteStr,
         cbMultiByte: cchCount1,
         lpWideCharStr: wbuffer1,
         cchWideChar: v21) != 0 )
  {
    v25 = MultiByteToWideChar(
            CodePage: code_page,
            dwFlags: 9u,
            lpMultiByteStr: v36,
            cbMultiByte: cchCount2,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    v26 = v25;
    if ( v25 != 0 )
    {
      if ( v25 <= 0 || 0xFFFFFFE0 / v25 < 2 )
      {
        v30 = nullptr;
LABEL_68:
        if ( v30 != nullptr )
        {
          if ( MultiByteToWideChar(
                 CodePage: code_page,
                 dwFlags: 1u,
                 lpMultiByteStr: v36,
                 cbMultiByte: cchCount2,
                 lpWideCharStr: v30,
                 cchWideChar: v26) != 0 )
            retcode = CompareStringW(
                        Locale,
                        dwCmpFlags,
                        lpString1: wbuffer1,
                        cchCount1: buff_size1,
                        lpString2: v30,
                        cchCount2: v26);
          _freea(_Memory: v30);
        }
        goto error_cleanup_0;
      }
      v27 = 2 * v25 + 8;
      if ( v27 > 0x400 )
      {
        v29 = (wchar_t *)operator new(nSize: 2 * v26 + 8);
        if ( v29 != nullptr )
        {
          *(_DWORD *)v29 = 56797;
          goto LABEL_65;
        }
      }
      else
      {
        v28 = alloca(v27);
        v29 = (wchar_t *)v32;
        if ( v32 != nullptr )
        {
          v32[0] = 52428;
LABEL_65:
          v29 += 4;
        }
      }
      v30 = v29;
      goto LABEL_68;
    }
  }
error_cleanup_0:
  _freea(_Memory: wbuffer1);
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x00447D32
// Name: ___crtCompareStringA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtCompareStringA(
        localeinfo_struct *plocinfo,
        LCID Locale,
        DWORD dwCmpFlags,
        const char *lpString1,
        int cchCount1,
        const char *lpString2,
        int cchCount2,
        UINT code_page)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtCompareStringA_stat(
             plocinfo: &_loc_update.localeinfo,
             lpString2,
             Locale,
             dwCmpFlags,
             lpString1,
             cchCount1,
             cchCount2,
             code_page);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00447D74
// Name: __strnicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strnicoll_l(const char *_string1, const char *_string2, unsigned int count, localeinfo_struct *plocinfo)
{
  int result; // eax
  LCID v5; // ecx
  int v6; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( count == 0 )
  {
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  if ( _string1 != nullptr && _string2 != nullptr )
  {
    if ( count > 0x7FFFFFFF )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
LABEL_16:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
    v5 = _loc_update.localeinfo.locinfo->lc_handle[1];
    if ( v5 != 0 )
    {
      v6 = __crtCompareStringA(
             plocinfo: &_loc_update.localeinfo,
             Locale: v5,
             dwCmpFlags: 0x1001u,
             lpString1: _string1,
             cchCount1: count,
             lpString2: _string2,
             cchCount2: count,
             code_page: _loc_update.localeinfo.locinfo->lc_collate_cp);
      if ( v6 == 0 )
      {
        *_errno() = 22;
        goto LABEL_16;
      }
      result = v6 - 2;
    }
    else
    {
      result = _strnicmp_l(dst: _string1, src: _string2, count, plocinfo: &_loc_update.localeinfo);
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00447E5E
// Name: __dospawn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _dospawn(int mode, const char *name, char *cmdblk, char *envblk)
{
  void *hProcess; // ebx
  char *v5; // eax
  int v7; // esi
  signed int v8; // eax
  unsigned __int8 *v9; // eax
  unsigned __int8 *lpReserved2; // eax
  unsigned __int8 *v11; // ecx
  unsigned __int8 *v12; // edi
  ioinfo *v13; // eax
  char osfile; // dl
  _BYTE *v15; // ecx
  int v16; // edx
  unsigned __int8 *j; // eax
  int v18; // edi
  BOOL v19; // esi
  DWORD LastError; // edi
  _STARTUPINFOA StartupInfo; // [esp+8h] [ebp-68h] BYREF
  _PROCESS_INFORMATION ProcessInformation; // [esp+4Ch] [ebp-24h] BYREF
  unsigned int exitcode; // [esp+5Ch] [ebp-14h] BYREF
  char *CommandLine; // [esp+60h] [ebp-10h]
  unsigned int fdwCreate; // [esp+64h] [ebp-Ch]
  int i; // [esp+68h] [ebp-8h]
  char background; // [esp+6Fh] [ebp-1h]

  hProcess = nullptr;
  fdwCreate = 0;
  background = 0;
  if ( (unsigned int)mode >= 2 )
  {
    if ( mode <= 1 )
      goto LABEL_7;
    if ( mode > 3 )
    {
      if ( mode == 4 )
      {
        background = 1;
        goto LABEL_6;
      }
LABEL_7:
      *__doserrno() = 0;
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return -1;
    }
  }
LABEL_6:
  v5 = cmdblk;
  CommandLine = cmdblk;
  while ( *v5 != 0 )
  {
    do
      ++v5;
    while ( *v5 != 0 );
    if ( v5[1] != 0 )
      *v5++ = 32;
  }
  memset(dst: (unsigned __int8 *)&StartupInfo, value: 0, count: sizeof(StartupInfo));
  StartupInfo.cb = 68;
  v7 = _nhandle;
  if ( _nhandle == 0 )
    goto LABEL_47;
  v8 = _nhandle - 1;
  do
  {
    if ( __pioinfo[v8 >> 5][v8 & 0x1F].osfile != 0 )
      break;
    --v7;
    --v8;
  }
  while ( v7 != 0 );
  if ( v7 >= 0 )
  {
LABEL_47:
    if ( (unsigned int)v7 < 0x3332 )
    {
      StartupInfo.cbReserved2 = 5 * v7 + 4;
      v9 = calloc(count: StartupInfo.cbReserved2, size: 1u);
      StartupInfo.lpReserved2 = v9;
      if ( v9 != nullptr )
      {
        *(_DWORD *)v9 = v7;
        lpReserved2 = StartupInfo.lpReserved2;
        v11 = StartupInfo.lpReserved2 + 4;
        v12 = &StartupInfo.lpReserved2[v7 + 4];
        i = 0;
        if ( v7 > 0 )
        {
          do
          {
            v13 = &__pioinfo[i >> 5][i & 0x1F];
            osfile = v13->osfile;
            if ( (osfile & 0x10) != 0 )
            {
              *v11 = 0;
              *(_DWORD *)v12 = -1;
            }
            else
            {
              *v11 = osfile;
              *(_DWORD *)v12 = v13->osfhnd;
            }
            ++i;
            ++v11;
            v12 += 4;
          }
          while ( i < v7 );
          lpReserved2 = StartupInfo.lpReserved2;
        }
        if ( background != 0 )
        {
          v15 = lpReserved2 + 4;
          v16 = 0;
          for ( j = &lpReserved2[v7 + 4]; ; j += 4 )
          {
            v18 = v7 >= 3 ? 3 : v7;
            if ( v16 >= v18 )
              break;
            *v15 = 0;
            *(_DWORD *)j = -1;
            ++v16;
            ++v15;
          }
          fdwCreate = 8;
        }
        *__doserrno() = 0;
        v19 = CreateProcessA(
                lpApplicationName: name,
                lpCommandLine: CommandLine,
                lpProcessAttributes: nullptr,
                lpThreadAttributes: nullptr,
                bInheritHandles: true,
                dwCreationFlags: fdwCreate,
                lpEnvironment: envblk,
                lpCurrentDirectory: nullptr,
                lpStartupInfo: &StartupInfo,
                lpProcessInformation: &ProcessInformation);
        LastError = GetLastError();
        free(pMem: StartupInfo.lpReserved2);
        if ( v19 )
        {
          if ( mode == 2 )
            _exit(code: 0);
          if ( mode != 0 )
          {
            if ( mode != 4 )
            {
              hProcess = ProcessInformation.hProcess;
              goto LABEL_42;
            }
          }
          else
          {
            WaitForSingleObject(hHandle: ProcessInformation.hProcess, dwMilliseconds: 0xFFFFFFFF);
            GetExitCodeProcess(hProcess: ProcessInformation.hProcess, lpExitCode: &exitcode);
            hProcess = (void *)exitcode;
          }
          CloseHandle(hObject: ProcessInformation.hProcess);
LABEL_42:
          CloseHandle(hObject: ProcessInformation.hThread);
          return (int)hProcess;
        }
        _dosmaperr(oserrno: LastError);
        return -1;
      }
    }
  }
  *_errno() = 12;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00448062
// Name: __cenvarg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cenvarg(const char **argv, const char **envp, char **argblk, char **envblk)
{
  unsigned __int8 **v4; // edi
  unsigned __int8 *v5; // eax
  unsigned int v6; // esi
  int v7; // eax
  unsigned __int8 *v8; // eax
  void **v9; // esi
  int v11; // eax
  int v12; // eax
  int v13; // edi
  int v14; // eax
  unsigned __int8 **v15; // esi
  unsigned __int8 *v16; // eax
  int v17; // edi
  int v18; // eax
  char *EnvironmentStringsA; // eax
  const char **v20; // edi
  char *v21; // esi
  char *v22; // esi
  char v23; // cl
  unsigned __int8 *v24; // esi
  int v25; // eax
  int v26; // ecx
  char *i; // eax
  int v28; // eax
  const unsigned __int8 **v29; // esi
  unsigned int v30; // edi
  unsigned int v31; // eax
  unsigned __int8 *v32; // eax
  int v33; // eax
  int v34; // eax
  char *v35; // esi
  unsigned __int8 *v36; // esi
  const char **j; // edi
  int v38; // eax
  unsigned int env_len; // [esp+Ch] [ebp-40h]
  int defined; // [esp+10h] [ebp-3Ch]
  unsigned int v41; // [esp+18h] [ebp-34h]
  unsigned int envsize; // [esp+1Ch] [ebp-30h]
  int cwd_end; // [esp+24h] [ebp-28h]
  int retval; // [esp+28h] [ebp-24h]
  int cwd_start; // [esp+30h] [ebp-1Ch]
  char *envbuf; // [esp+38h] [ebp-14h] BYREF
  char envpfx[12]; // [esp+3Ch] [ebp-10h] BYREF

  strcpy(envpfx, "SystemRoot");
  v4 = (unsigned __int8 **)argv;
  v5 = (unsigned __int8 *)*argv;
  retval = 0;
  envbuf = nullptr;
  defined = 0;
  v6 = 2;
  while ( v5 != nullptr )
  {
    strlen(buf: v5);
    ++v4;
    v6 += v7 + 1;
    v5 = *v4;
  }
  v41 = v6;
  v8 = calloc(count: v6, size: 1u);
  v9 = (void **)argblk;
  *argblk = (char *)v8;
  if ( v8 == nullptr )
  {
    *envblk = nullptr;
    *_errno() = 12;
    *__doserrno() = 8;
    return -1;
  }
  v11 = _dupenv_s(pBuffer: &envbuf, pBufferSizeInTChars: nullptr, varname: envpfx);
  if ( v11 != 0 )
  {
    if ( v11 == 22 )
      goto LABEL_8;
    goto LABEL_18;
  }
  strlen(buf: (unsigned __int8 *)envpfx);
  v13 = v12 + 2;
  envsize = v12 + 2;
  if ( envbuf != nullptr )
  {
    strlen(buf: (unsigned __int8 *)envbuf);
    envsize = v14 + v13;
  }
  if ( envp == nullptr )
  {
    *envblk = nullptr;
    goto LABEL_20;
  }
  v15 = (unsigned __int8 **)envp;
  v16 = (unsigned __int8 *)*envp;
  v17 = 2;
  while ( v16 != nullptr )
  {
    strlen(buf: v16);
    ++v15;
    v17 += v18 + 1;
    v16 = *v15;
  }
  EnvironmentStringsA = _aenvptr;
  if ( _aenvptr != nullptr
    || (EnvironmentStringsA = (char *)__crtGetEnvironmentStringsA(),
        _aenvptr = EnvironmentStringsA,
        EnvironmentStringsA != nullptr) )
  {
    cwd_start = 0;
    if ( *EnvironmentStringsA != 0 )
    {
      v23 = *EnvironmentStringsA;
      v24 = (unsigned __int8 *)EnvironmentStringsA;
      do
      {
        if ( v23 == 61 )
          break;
        strlen(buf: v24);
        v26 = cwd_start + v25 + 1;
        EnvironmentStringsA = _aenvptr;
        v24 = (unsigned __int8 *)&_aenvptr[v26];
        cwd_start = v26;
        v23 = _aenvptr[v26];
      }
      while ( v23 != 0 );
    }
    cwd_end = cwd_start;
    for ( i = &EnvironmentStringsA[cwd_start]; *i == 61 && i[1] != 0 && i[2] == 58 && i[3] == 61; i = &_aenvptr[cwd_end] )
    {
      strlen(buf: (unsigned __int8 *)i + 4);
      cwd_end += v28 + 5;
    }
    v29 = (const unsigned __int8 **)envp;
    v30 = cwd_end - cwd_start + v17;
    env_len = v30;
    while ( 1 )
    {
      if ( *v29 == nullptr )
      {
        v30 += envsize;
        goto LABEL_37;
      }
      strlen(buf: (unsigned __int8 *)envpfx);
      if ( _mbsnicmp(s1: *v29, s2: (const unsigned __int8 *)envpfx, n: v31) == 0 )
        break;
      ++v29;
    }
    defined = 1;
LABEL_37:
    v32 = calloc(count: v30, size: 1u);
    v9 = (void **)argblk;
    *envblk = (char *)v32;
    if ( v32 == nullptr )
    {
      free(pMem: *argblk);
      *argblk = nullptr;
      *_errno() = 12;
      retval = -1;
      *__doserrno() = 8;
      goto done_1;
    }
LABEL_20:
    v20 = argv;
    v21 = (char *)*v9;
    if ( *argv == nullptr )
    {
      v22 = v21 + 1;
      goto LABEL_44;
    }
    if ( strcpy_s(_Dst: v21, _SizeInBytes: v41, _Src: *argv) == 0 )
    {
      strlen(buf: (unsigned __int8 *)*argv);
      v22 = &v21[v33 + 1];
      v20 = argv + 1;
LABEL_44:
      while ( *v20 != nullptr )
      {
        if ( strcpy_s(_Dst: v22, _SizeInBytes: v41 + *argblk - v22, _Src: *v20) != 0 )
          goto LABEL_8;
        strlen(buf: (unsigned __int8 *)*v20);
        v35 = &v22[v34];
        ++v20;
        *v35 = 32;
        v22 = v35 + 1;
      }
      *(_WORD *)(v22 - 1) = 0;
      v36 = (unsigned __int8 *)*envblk;
      if ( envp == nullptr )
        goto LABEL_56;
      memcpy(dst: v36, src: (unsigned __int8 *)&_aenvptr[cwd_start], count: cwd_end - cwd_start);
      v36 += cwd_end - cwd_start;
      for ( j = envp; *j != nullptr; ++j )
      {
        if ( strcpy_s(_Dst: (char *)v36, _SizeInBytes: (unsigned int)&(*envblk)[env_len - (_DWORD)v36], _Src: *j) != 0 )
          goto LABEL_8;
        strlen(buf: (unsigned __int8 *)*j);
        v36 += v38 + 1;
      }
      if ( defined != 0 )
        goto LABEL_56;
      if ( strcpy_s(_Dst: (char *)v36, _SizeInBytes: envsize, _Src: envpfx) == 0
        && strcat_s(_Dst: (char *)v36, _SizeInBytes: envsize, _Src: "=") == 0
        && (envbuf == nullptr || strcat_s(_Dst: (char *)v36, _SizeInBytes: envsize, _Src: envbuf) == 0) )
      {
        v36 += envsize;
LABEL_56:
        if ( v36 != nullptr )
        {
          if ( v36 == (unsigned __int8 *)*envblk )
            *v36++ = 0;
          *v36 = 0;
        }
        goto done_1;
      }
    }
LABEL_8:
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  }
  v9 = (void **)argblk;
LABEL_18:
  retval = -1;
  free(pMem: *v9);
  *v9 = nullptr;
  *envblk = nullptr;
done_1:
  if ( _aenvptr != nullptr )
    free(pMem: _aenvptr);
  _aenvptr = nullptr;
  if ( envbuf != nullptr )
    free(pMem: envbuf);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x004483FE
// Name: __mbsnbicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbicmp_l(
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  const unsigned __int8 *v5; // edi
  int v6; // ecx
  bool v7; // zf
  int v8; // ecx
  unsigned __int16 v9; // si
  unsigned __int8 v10; // dl
  int v11; // ecx
  char *v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  char *v16; // ecx
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  int c1; // [esp+14h] [ebp-8h]
  int c2; // [esp+18h] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( n == 0 )
  {
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    result = _strnicmp(dst: (const char *)s1, src: (const char *)s2, count: n);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( s1 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  v5 = s2;
  if ( s2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  while ( 1 )
  {
    v6 = *s1;
    --n;
    ++s1;
    v7 = (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v6 + 1] & 4) == 0;
    c1 = v6;
    if ( v7 )
    {
      v12 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c1;
      if ( (v12[29] & 0x10) != 0 )
        v13 = (unsigned __int8)v12[285];
      else
        v13 = (unsigned __int16)c1;
      c1 = v13;
      goto LABEL_32;
    }
    if ( n == 0 )
    {
      v8 = *v5;
      v7 = (_loc_update.localeinfo.mbcinfo->mbctype[v8 + 1] & 4) == 0;
      c1 = 0;
      if ( !v7 )
        goto LABEL_51;
      v9 = 0;
      goto LABEL_46;
    }
    if ( *s1 == 0 )
    {
      c1 = 0;
LABEL_32:
      v9 = c1;
      goto LABEL_33;
    }
    v10 = *s1++;
    v11 = (unsigned __int16)(v10 | (unsigned __int16)((_WORD)v6 << 8));
    v9 = v11;
    c1 = v11;
    if ( (unsigned __int16)v11 < _loc_update.localeinfo.mbcinfo->mbulinfo[0]
      || (unsigned __int16)v11 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( (unsigned __int16)v11 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3]
        && (unsigned __int16)v11 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
      {
        v9 = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v11;
      }
    }
    else
    {
      v9 = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v11;
    }
LABEL_33:
    v14 = *v5++;
    v7 = (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v14 + 1] & 4) == 0;
    c2 = v14;
    if ( v7 )
    {
      v16 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c2;
      if ( (v16[29] & 0x10) != 0 )
        v8 = (unsigned __int8)v16[285];
      else
        v8 = (unsigned __int16)c2;
LABEL_46:
      c2 = v8;
      goto LABEL_47;
    }
    if ( n == 0 || (--n, *v5 == 0) )
    {
      c2 = 0;
LABEL_47:
      LOWORD(v15) = c2;
      goto test;
    }
    v15 = (unsigned __int16)(*v5++ | (unsigned __int16)((_WORD)v14 << 8));
    c2 = v15;
    if ( (unsigned __int16)v15 < _loc_update.localeinfo.mbcinfo->mbulinfo[0]
      || (unsigned __int16)v15 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( (unsigned __int16)v15 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3]
        && (unsigned __int16)v15 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
      {
        LOWORD(v15) = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v15;
      }
    }
    else
    {
      LOWORD(v15) = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v15;
    }
test:
    if ( (_WORD)v15 != v9 )
      break;
    if ( v9 == 0 || n == 0 )
    {
LABEL_51:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0;
    }
  }
  result = (unsigned __int16)v15 < v9 ? 1 : -1;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00448602
// Name: __mbsnbicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbicmp(const unsigned __int8 *s1, const unsigned __int8 *s2, unsigned int n)
{
  return _mbsnbicmp_l(s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0044861C
// Name: __mbsnbcmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbcmp_l(
        const unsigned __int8 *s1,
        const unsigned __int8 *s2,
        unsigned int n,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  const unsigned __int8 *v5; // ebx
  const unsigned __int8 *v6; // esi
  unsigned __int16 v7; // cx
  int v8; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  if ( n == 0 )
    return 0;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    result = strncmp(first: (const char *)s1, last: (const char *)s2, count: n);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  v5 = s1;
  if ( s1 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  v6 = s2;
  if ( s2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  while ( 1 )
  {
    v7 = *v5;
    --n;
    ++v5;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v7 + 1] & 4) == 0 )
      goto LABEL_24;
    if ( n != 0 )
    {
      if ( *v5 != 0 )
        v7 = *v5++ | (unsigned __int16)(v7 << 8);
      else
        v7 = 0;
LABEL_24:
      LOWORD(v8) = *v6++;
      if ( (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v8 + 1] & 4) != 0 )
      {
        if ( n != 0 && (--n, *v6 != 0) )
          LOWORD(v8) = *v6++ | (unsigned __int16)((_WORD)v8 << 8);
        else
          LOWORD(v8) = 0;
      }
      goto test_0;
    }
    v8 = *v6;
    v7 = 0;
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[v8 + 1] & 4) != 0 )
      goto LABEL_17;
test_0:
    if ( (_WORD)v8 != v7 )
      break;
    if ( v7 == 0 || n == 0 )
    {
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0;
    }
  }
  result = (unsigned __int16)v8 < v7 ? 1 : -1;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00448768
// Name: __mbsnbcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbcmp(const unsigned __int8 *s1, const unsigned __int8 *s2, unsigned int n)
{
  return _mbsnbcmp_l(s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x00448790
// Name: __global_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _global_unwind2(PVOID TargetFrame)
{
  RtlUnwind(TargetFrame, TargetIp: &gu_return, ExceptionRecord: nullptr, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004487B0
// Name: __unwind_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _unwind_handler(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  int result; // eax

  result = 1;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    _local_unwind2(a1: *(_DWORD *)(a5 + 36), a2: *(_DWORD *)(a5 + 40));
    *a4 = a2;
    return 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004487F5
// Name: __local_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _local_unwind2(int a1, unsigned int a2)
{
  int result; // eax
  int v3; // ebx
  unsigned int v4; // esi
  int v5; // esi

  while ( 1 )
  {
    result = a1;
    v3 = *(_DWORD *)(a1 + 8);
    v4 = *(_DWORD *)(a1 + 12);
    if ( v4 == -1 || a2 != -1 && v4 <= a2 )
      break;
    v5 = 3 * v4;
    *(_DWORD *)(a1 + 12) = *(_DWORD *)(v3 + 4 * v5);
    if ( *(_DWORD *)(v3 + 4 * v5 + 4) == 0 )
    {
      _NLG_Notify(a1: 257);
      _NLG_Call();
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00448879
// Name: __abnormal_termination
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _abnormal_termination()
{
  int result; // eax
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // ecx

  result = 0;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  if ( (int (__cdecl *)(int, int, int, _DWORD *, int))ExceptionList->Handler == _unwind_handler )
    return ExceptionList[1].Next == *((_EXCEPTION_REGISTRATION_RECORD **)ExceptionList[1].Handler + 3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044889C
// Name: __NLG_Notify1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _NLG_Notify1(int a1)
{
  JUMPOUT(0x4488B0);
}

//------------------------------------------------------------------------------
// Address: 0x004488A5
// Name: __NLG_Notify
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __userpurge _NLG_Notify@<eax>(unsigned int result@<eax>, unsigned int a2@<ebp>, unsigned int a3)
{
  _NLG_Destination.dwCode = a3;
  _NLG_Destination.uoffDestination = result;
  _NLG_Destination.uoffFramePointer = a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004488C4
// Name: __NLG_Call
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _NLG_Call@<eax>(int (*a1)(void)@<eax>)
{
  return a1();
}

//------------------------------------------------------------------------------
// Address: 0x004488D0
// Name: __CIsin_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00448A98
// Name: __getpath
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getpath(const char *src, char *dst, unsigned int maxlen)
{
  bool v4; // zf
  char *i; // edi
  char v6; // al
  char v7; // al
  const char *save_src; // [esp+10h] [ebp+8h]
  unsigned int maxlena; // [esp+18h] [ebp+10h]

  while ( *src == 59 )
    ++src;
  v4 = maxlen == 1;
  maxlena = maxlen - 1;
  save_src = src;
  if ( v4 )
  {
    i = dst;
    *_errno() = 34;
  }
  else
  {
    v6 = *src;
    for ( i = dst; *src != 0; v6 = *src )
    {
      if ( v6 == 59 )
        goto LABEL_19;
      if ( v6 == 34 )
      {
        v7 = *++src;
        if ( *src == 0 )
          break;
        do
        {
          if ( v7 == 34 )
            break;
          *i++ = v7;
          ++src;
          if ( --maxlena == 0 )
            goto LABEL_10;
          v7 = *src;
        }
        while ( *src != 0 );
        if ( *src == 0 )
          break;
        ++src;
      }
      else
      {
        *i++ = v6;
        ++src;
        if ( --maxlena == 0 )
        {
LABEL_10:
          save_src = src;
          *_errno() = 34;
          goto appendnull;
        }
      }
    }
    while ( *src == 59 )
LABEL_19:
      ++src;
  }
appendnull:
  *i = 0;
  return src != save_src ? (char *)src : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00448B2D
// Name: __mbsnbcpy_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbsnbcpy_s_l(
        unsigned __int8 *_Dst,
        unsigned int _SizeInBytes,
        const unsigned __int8 *_Src,
        unsigned int _CountInBytes,
        localeinfo_struct *_LocInfo)
{
  int result; // eax
  unsigned int v6; // ebx
  const unsigned __int8 *v7; // edi
  int v8; // esi
  unsigned __int8 *v9; // eax
  unsigned int v10; // edx
  unsigned __int8 v11; // cl
  unsigned __int8 v12; // cl
  unsigned __int8 *v13; // edi
  unsigned __int8 *j; // ebx
  unsigned __int8 *v15; // edi
  unsigned __int8 *i; // ebx
  unsigned __int8 *k; // ebx
  int *v18; // ecx
  _LocaleUpdate _LocUpdate; // [esp+8h] [ebp-10h] BYREF

  if ( _CountInBytes != 0 )
  {
    if ( _Dst == nullptr )
    {
LABEL_7:
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return 22;
    }
  }
  else if ( _Dst == nullptr )
  {
    if ( _SizeInBytes == 0 )
      return 0;
    goto LABEL_7;
  }
  v6 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_7;
  if ( _CountInBytes == 0 )
  {
    *_Dst = 0;
    return 0;
  }
  v7 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
    v8 = 22;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return v8;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_LocUpdate, plocinfo: _LocInfo);
  if ( _LocUpdate.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    result = strncpy_s((char *)_Dst, _SizeInBytes, (const char *)_Src, _Count: _CountInBytes);
    goto LABEL_52;
  }
  v9 = _Dst;
  v10 = _SizeInBytes;
  if ( _CountInBytes == -1 )
  {
    do
    {
      v11 = *v7;
      *v9++ = *v7++;
      if ( v11 == 0 )
        break;
      --v10;
    }
    while ( v10 != 0 );
  }
  else
  {
    do
    {
      v12 = *v7;
      *v9++ = *v7++;
      if ( v12 == 0 )
        break;
      if ( --v10 == 0 )
        break;
      --_CountInBytes;
    }
    while ( _CountInBytes != 0 );
    if ( _CountInBytes == 0 )
      *v9++ = 0;
  }
  if ( v10 == 0 )
  {
    if ( *v7 != 0 && _CountInBytes != 1 )
    {
LABEL_31:
      if ( _CountInBytes != -1 )
      {
        *_Dst = 0;
        v8 = 34;
        *_errno() = 34;
        _invalid_parameter_noinfo();
        if ( _LocUpdate.updated )
          _LocUpdate.ptd->_ownlocale &= ~2u;
        return v8;
      }
      if ( v6 > 1 )
      {
        v15 = &_Dst[v6 - 2];
        for ( i = v15; i >= _Dst; --i )
        {
          if ( _ismbblead_l(tst: *i, plocinfo: &_LocUpdate.localeinfo) == 0 )
            break;
        }
        if ( (((_BYTE)v15 - (_BYTE)i) & 1) != 0 )
        {
          *v15 = 0;
LABEL_40:
          if ( _LocUpdate.updated )
            _LocUpdate.ptd->_ownlocale &= ~2u;
          return 80;
        }
        v6 = _SizeInBytes;
      }
      _Dst[v6 - 1] = 0;
      goto LABEL_40;
    }
    v13 = v9 - 1;
    for ( j = v9 - 1; j >= _Dst; --j )
    {
      if ( _ismbblead_l(tst: *j, plocinfo: &_LocUpdate.localeinfo) == 0 )
        break;
    }
    if ( (((_BYTE)v13 - (_BYTE)j) & 1) == 0 )
    {
      v6 = _SizeInBytes;
      goto LABEL_31;
    }
LABEL_51:
    *v13 = 0;
    v18 = _errno();
    result = 42;
    *v18 = 42;
LABEL_52:
    if ( _LocUpdate.updated )
      _LocUpdate.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( v9 - _Dst >= 2 )
  {
    v13 = v9 - 2;
    for ( k = v9 - 2; k >= _Dst; --k )
    {
      if ( _ismbblead_l(tst: *k, plocinfo: &_LocUpdate.localeinfo) == 0 )
        break;
    }
    if ( (((_BYTE)v13 - (_BYTE)k) & 1) != 0 )
      goto LABEL_51;
  }
  if ( _LocUpdate.updated )
    _LocUpdate.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00448D15
// Name: __87except
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _87except(int a1@<ebp>, int opcode, _exception *exc, unsigned __int16 *pcw16)
{
  unsigned int v4; // ecx
  bool v5; // zf
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned int v12; // [esp-Ch] [ebp-94h] BYREF
  unsigned int v13; // [esp-8h] [ebp-90h]
  int v14; // [esp-4h] [ebp-8Ch] BYREF
  _FPIEEE_RECORD rec; // [esp+8h] [ebp-80h]
  int v16; // [esp+7Ch] [ebp-Ch]
  void *v17; // [esp+80h] [ebp-8h]
  void *retaddr; // [esp+88h] [ebp+0h]

  v16 = a1;
  v17 = retaddr;
  v4 = *pcw16;
  v6 = exc->type - 1;
  v5 = exc->type == 1;
  v12 = v4;
  if ( v5 )
    goto LABEL_13;
  v7 = v6 - 1;
  if ( v7 == 0 )
  {
    v13 = 4;
    goto LABEL_14;
  }
  v8 = v7 - 1;
  if ( v8 == 0 )
  {
    v13 = 17;
    goto LABEL_14;
  }
  v9 = v8 - 1;
  if ( v9 == 0 )
  {
    v13 = 18;
    goto LABEL_14;
  }
  v10 = v9 - 1;
  if ( v10 == 0 )
  {
LABEL_13:
    v13 = 8;
LABEL_14:
    if ( _handle_exc(flags: v13, presult: &exc->retval, cw: v4) == 0 )
    {
      if ( opcode == 16 || opcode == 22 || opcode == 29 )
      {
        *(double *)((char *)&rec.Operand1 + 20) = exc->arg2;
        rec.Operand2.Value.Fp128Value.W[1] = rec.Operand2.Value.Fp128Value.W[1] & 0xFFFFFFE0 | 3;
      }
      else
      {
        rec.Operand2.Value.Fp128Value.W[1] &= ~1u;
      }
      _raise_exc(prec: (_FPIEEE_RECORD *)&v14, pcw: &v12, flags: v13, opcode, parg1: &exc->arg1, presult: &exc->retval);
    }
    goto LABEL_21;
  }
  v11 = v10 - 2;
  if ( v11 == 0 )
  {
    exc->type = 1;
    goto LABEL_21;
  }
  if ( v11 == 1 )
  {
    v13 = 16;
    goto LABEL_14;
  }
LABEL_21:
  _ctrlfp(newctrl: v12, _mask: 0xFFFFu);
  if ( exc->type == 8 || _matherr_flag != 0 || _matherr(pexcept: exc) == 0 )
    _set_errno_from_matherr(matherrtype: exc->type);
}

//------------------------------------------------------------------------------
// Address: 0x00448E54
// Name: __frnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _frnd(long double x)
{
  return rint(x);
}

//------------------------------------------------------------------------------
// Address: 0x00448E68
// Name: __fpclass
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fpclass(long double x)
{
  int v1; // eax
  int v2; // eax
  int v4; // ecx

  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v1 = _sptype(x) - 1;
    if ( v1 != 0 )
    {
      v2 = v1 - 1;
      if ( v2 == 0 )
        return 4;
      if ( v2 != 1 )
        return 1;
      return 2;
    }
    else
    {
      return 512;
    }
  }
  else
  {
    v4 = HIWORD(x) & 0x8000;
    if ( (HIWORD(x) & 0x7FF0) == 0 && ((HIDWORD(x) & 0xFFFFF) != 0 || LODWORD(x) != 0) )
    {
      return v4 != 0 ? 16 : 128;
    }
    else if ( 0.0 == x )
    {
      return v4 != 0 ? 32 : 64;
    }
    else
    {
      return v4 != 0 ? 8 : 256;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448F05
// Name: __set_exp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _set_exp(long double x, __int16 exp)
{
  long double retval; // [esp+0h] [ebp-8h]

  retval = x;
  HIWORD(retval) = HIWORD(x) & 0x800F | (16 * (exp + 1022));
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x00448F32
// Name: __sptype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sptype(long double x)
{
  if ( HIDWORD(x) == 2146435072 )
  {
    if ( LODWORD(x) == 0 )
      return 1;
  }
  else if ( x == -INFINITY )
  {
    return 2;
  }
  if ( (HIWORD(x) & 0x7FF8) == 0x7FF8 )
    return 3;
  if ( (HIWORD(x) & 0x7FF8) == 0x7FF0 && ((HIDWORD(x) & 0x7FFFF) != 0 || LODWORD(x) != 0) )
    return 4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00448F98
// Name: __decomp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _decomp(long double x, int *pexp)
{
  long double result; // st7
  int v3; // edx
  int v4; // edx
  BOOL v5; // eax

  result = 0.0;
  if ( 0.0 == x )
  {
    v3 = 0;
  }
  else if ( (HIWORD(x) & 0x7FF0) == 0 && ((HIDWORD(x) & 0xFFFFF) != 0 || LODWORD(x) != 0) )
  {
    v4 = -1021;
    v5 = x < 0.0;
    while ( (BYTE6(x) & 0x10) == 0 )
    {
      HIDWORD(x) *= 2;
      if ( SLODWORD(x) < 0 )
        HIDWORD(x) |= 1u;
      LODWORD(x) *= 2;
      --v4;
    }
    HIWORD(x) &= ~0x10u;
    if ( v5 )
      HIWORD(x) |= 0x8000u;
    result = _set_exp(x, exp: 0);
  }
  else
  {
    result = _set_exp(x, exp: 0);
    v3 = ((HIWORD(x) >> 4) & 0x7FF) - 1022;
  }
  *pexp = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00449060
// Name: __CIcos_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00449210
// Name: __CItan_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00449464
// Name: sub_449464
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_449464(_exception *a1)
{
  return _matherr(pexcept: a1);
}

//------------------------------------------------------------------------------
// Address: 0x00449470
// Name: __matherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _matherr()
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00449473
// Name: __raise_exc_ex
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _raise_exc_ex(
        _FPIEEE_RECORD *prec,
        unsigned int *pcw,
        DWORD flags,
        int opcode,
        float *parg1,
        float *presult,
        int isfloat)
{
  char v7; // cl
  unsigned int *v8; // esi
  char v9; // al
  int v10; // eax
  _FPIEEE_RECORD *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  _FPIEEE_RECORD *v14; // eax
  unsigned int v15; // ecx
  float *v16; // edi
  _FPIEEE_RECORD *v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  unsigned int v21; // eax
  int v22; // eax
  int v23; // eax
  unsigned int v24; // eax

  v7 = flags;
  prec->Cause = 0;
  prec->Enable = 0;
  prec->Status = 0;
  if ( (v7 & 0x10) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 1u;
    flags = -1073741681;
  }
  if ( (v7 & 2) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 2u;
    flags = -1073741677;
  }
  if ( (v7 & 1) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 4u;
    flags = -1073741679;
  }
  if ( (v7 & 4) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 8u;
    flags = -1073741682;
  }
  if ( (v7 & 8) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 0x10u;
    flags = -1073741680;
  }
  v8 = pcw;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(16 * *pcw)) & 0x10;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(2 * *v8)) & 8;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 1)) & 4;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 3)) & 2;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 5)) & 1;
  v9 = _statfp();
  if ( (v9 & 1) != 0 )
    *(_DWORD *)&prec->Status |= 0x10u;
  if ( (v9 & 4) != 0 )
    *(_DWORD *)&prec->Status |= 8u;
  if ( (v9 & 8) != 0 )
    *(_DWORD *)&prec->Status |= 4u;
  if ( (v9 & 0x10) != 0 )
    *(_DWORD *)&prec->Status |= 2u;
  if ( (v9 & 0x20) != 0 )
    *(_DWORD *)&prec->Status |= 1u;
  v10 = *v8 & 0xC00;
  switch ( v10 )
  {
    case 0:
      *(_DWORD *)prec &= 0xFFFFFFFC;
      break;
    case 1024:
      v11 = prec;
      v12 = *(_DWORD *)prec & 0xFFFFFFFC | 1;
      goto LABEL_27;
    case 2048:
      v11 = prec;
      v12 = *(_DWORD *)prec & 0xFFFFFFFC | 2;
LABEL_27:
      *(_DWORD *)v11 = v12;
      break;
    case 3072:
      *(_DWORD *)prec |= 3u;
      break;
    default:
      break;
  }
  v13 = *v8 & 0x300;
  switch ( v13 )
  {
    case 0:
      v14 = prec;
      v15 = *(_DWORD *)prec & 0xFFFFFFE3 | 8;
      goto LABEL_36;
    case 512:
      v14 = prec;
      v15 = *(_DWORD *)prec & 0xFFFFFFE3 | 4;
LABEL_36:
      *(_DWORD *)v14 = v15;
      break;
    case 768:
      *(_DWORD *)prec &= 0xFFFFFFE3;
      break;
    default:
      break;
  }
  *(_DWORD *)prec ^= (*(_DWORD *)prec ^ (32 * opcode)) & 0x1FFE0;
  *((_DWORD *)&prec->Operand1 + 4) |= 1u;
  v16 = presult;
  if ( isfloat != 0 )
  {
    *((_DWORD *)&prec->Operand1 + 4) &= 0xFFFFFFE1;
    prec->Operand1.Value.Fp32Value = *parg1;
    *((_DWORD *)&prec->Result + 4) |= 1u;
    *((_DWORD *)&prec->Result + 4) &= 0xFFFFFFE1;
    prec->Result.Value.Fp32Value = *v16;
  }
  else
  {
    *((_DWORD *)&prec->Operand1 + 4) = *((_DWORD *)&prec->Operand1 + 4) & 0xFFFFFFE1 | 2;
    prec->Operand1.Value.Fp64Value = *(double *)parg1;
    *((_DWORD *)&prec->Result + 4) |= 1u;
    *((_DWORD *)&prec->Result + 4) = *((_DWORD *)&prec->Result + 4) & 0xFFFFFFE1 | 2;
    prec->Result.Value.Fp64Value = *(double *)v16;
  }
  _clrfp();
  RaiseException(
    dwExceptionCode: flags,
    dwExceptionFlags: 0,
    nNumberOfArguments: 1u,
    lpArguments: (const ULONG_PTR *)&prec);
  v17 = prec;
  if ( (*(_BYTE *)&prec->Enable & 0x10) != 0 )
    *v8 &= ~1u;
  if ( (*(_BYTE *)&v17->Enable & 8) != 0 )
    *v8 &= ~4u;
  if ( (*(_BYTE *)&v17->Enable & 4) != 0 )
    *v8 &= ~8u;
  if ( (*(_BYTE *)&v17->Enable & 2) != 0 )
    *v8 &= ~0x10u;
  if ( (*(_BYTE *)&v17->Enable & 1) != 0 )
    *v8 &= ~0x20u;
  v18 = *(_DWORD *)v17 & 3;
  if ( v18 == 0 )
  {
    *v8 &= 0xFFFFF3FF;
    goto LABEL_59;
  }
  v19 = v18 - 1;
  if ( v19 == 0 )
  {
    v21 = *v8 & 0xFFFFF3FF | 0x400;
    goto LABEL_56;
  }
  v20 = v19 - 1;
  if ( v20 == 0 )
  {
    v21 = *v8 & 0xFFFFF3FF | 0x800;
LABEL_56:
    *v8 = v21;
    goto LABEL_59;
  }
  if ( v20 == 1 )
    *v8 |= 0xC00u;
LABEL_59:
  v22 = (*(_DWORD *)v17 >> 2) & 7;
  if ( v22 == 0 )
  {
    v24 = *v8 & 0xFFFFF0FF | 0x300;
    goto LABEL_65;
  }
  v23 = v22 - 1;
  if ( v23 == 0 )
  {
    v24 = *v8 & 0xFFFFF1FF | 0x200;
LABEL_65:
    *v8 = v24;
    goto LABEL_66;
  }
  if ( v23 == 1 )
    *v8 &= 0xFFFFF3FF;
LABEL_66:
  if ( isfloat != 0 )
    *v16 = v17->Result.Value.Fp32Value;
  else
    *(double *)v16 = v17->Result.Value.Fp64Value;
}

//------------------------------------------------------------------------------
// Address: 0x0044974F
// Name: __raise_exc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _raise_exc(
        _FPIEEE_RECORD *prec,
        unsigned int *pcw,
        DWORD flags,
        int opcode,
        long double *parg1,
        long double *presult)
{
  _raise_exc_ex(prec, pcw, flags, opcode, (float *)parg1, (float *)presult, isfloat: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00449772
// Name: __handle_exc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _handle_exc(char flags, long double *presult, __int16 cw)
{
  int v3; // esi
  int v4; // eax
  double *v5; // ecx
  long double dbl; // st7
  BOOL v7; // esi
  int v8; // ecx
  double v9; // st7
  BOOL v10; // edx
  int v11; // eax
  double v13; // [esp+18h] [ebp-14h]
  int expn; // [esp+24h] [ebp-8h] BYREF
  int flags_p; // [esp+28h] [ebp-4h]

  v3 = flags & 0x1F;
  flags_p = v3;
  if ( (flags & 8) != 0 && (cw & 1) != 0 )
  {
    _set_statfp(sw: 1u);
    v3 = flags & 0x17;
    goto LABEL_46;
  }
  if ( (flags & 4) != 0 && (cw & 4) != 0 )
  {
    _set_statfp(sw: 4u);
    v3 = flags & 0x1B;
    goto LABEL_46;
  }
  if ( (flags & 1) != 0 && (cw & 8) != 0 )
  {
    _set_statfp(sw: 8u);
    v4 = cw & 0xC00;
    if ( (cw & 0xC00) != 0 )
    {
      if ( v4 != 1024 )
      {
        if ( v4 != 2048 )
        {
          if ( v4 != 3072 )
          {
LABEL_24:
            v3 = flags & 0x1E;
            goto LABEL_46;
          }
          v5 = presult;
          dbl = _d_max.dbl;
          if ( *presult <= 0.0 )
            goto LABEL_22;
LABEL_23:
          *v5 = dbl;
          goto LABEL_24;
        }
        v5 = presult;
        if ( *presult <= 0.0 )
        {
          dbl = _d_max.dbl;
LABEL_22:
          dbl = -dbl;
          goto LABEL_23;
        }
LABEL_20:
        dbl = _d_inf.dbl;
        goto LABEL_23;
      }
      v5 = presult;
      if ( *presult > 0.0 )
      {
        dbl = _d_max.dbl;
        goto LABEL_23;
      }
    }
    else
    {
      v5 = presult;
      if ( *presult > 0.0 )
        goto LABEL_20;
    }
    dbl = _d_inf.dbl;
    goto LABEL_22;
  }
  if ( (flags & 2) != 0 && (cw & 0x10) != 0 )
  {
    v7 = (flags & 0x10) != 0;
    if ( 0.0 == *presult )
    {
      v7 = true;
      goto LABEL_43;
    }
    v13 = _decomp(x: *presult, pexp: &expn);
    v8 = expn - 1536;
    if ( expn - 1536 >= -1074 )
    {
      v10 = v13 < 0.0;
      HIWORD(v13) = BYTE6(v13) & 0xF | 0x10;
      if ( v8 < -1021 )
      {
        v11 = -1021 - v8;
        do
        {
          if ( (LOBYTE(v13) & 1) != 0 && !v7 )
            v7 = true;
          LODWORD(v13) >>= 1;
          if ( (BYTE4(v13) & 1) != 0 )
            LODWORD(v13) |= 0x80000000;
          HIDWORD(v13) >>= 1;
          --v11;
        }
        while ( v11 != 0 );
      }
      if ( !v10 )
        goto LABEL_41;
      v9 = -v13;
    }
    else
    {
      v7 = true;
      v9 = v13 * 0.0;
    }
    v13 = v9;
LABEL_41:
    *presult = v13;
LABEL_43:
    if ( v7 )
      _set_statfp(sw: 0x10u);
    flags_p &= ~2u;
    v3 = flags_p;
  }
LABEL_46:
  if ( (flags & 0x10) != 0 && (cw & 0x20) != 0 )
  {
    _set_statfp(sw: 0x20u);
    v3 &= ~0x10u;
  }
  return v3 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00449956
// Name: __set_errno_from_matherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _set_errno_from_matherr(int matherrtype)
{
  if ( matherrtype == 1 )
  {
    *_errno() = 33;
  }
  else if ( matherrtype > 1 && matherrtype <= 3 )
  {
    *_errno() = 34;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449983
// Name: __errcode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _errcode(char flags)
{
  if ( (flags & 0x20) != 0 )
    return 5;
  if ( (flags & 8) != 0 )
    return 1;
  if ( (flags & 4) != 0 )
    return 2;
  if ( (flags & 1) != 0 )
    return 3;
  return 2 * (flags & 2);
}

//------------------------------------------------------------------------------
// Address: 0x004499B7
// Name: __umatherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _umatherr(
        int type,
        unsigned int opcode,
        long double arg1,
        long double arg2,
        long double retval,
        unsigned int cw)
{
  int v6; // eax
  char *v7; // eax

  v6 = 0;
  while ( dword_46F788[2 * v6] != opcode )
  {
    if ( ++v6 >= 29 )
    {
      v7 = nullptr;
      goto LABEL_5;
    }
  }
  v7 = (&off_46F78C)[2 * v6];
LABEL_5:
  if ( v7 != nullptr )
  {
    _ctrlfp(newctrl: cw, _mask: 0xFFFFu);
    if ( _matherr() == 0 )
      _set_errno_from_matherr(matherrtype: type);
    return retval;
  }
  else
  {
    _ctrlfp(newctrl: cw, _mask: 0xFFFFu);
    _set_errno_from_matherr(matherrtype: type);
    return retval;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449A57
// Name: __handle_qnan1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _handle_qnan1(unsigned int opcode, long double x, unsigned int savedcw)
{
  if ( _matherr_flag == 0 )
    return _umatherr(type: 1, opcode, arg1: x, arg2: 0.0, retval: x, cw: savedcw);
  *_errno() = 33;
  _ctrlfp(newctrl: savedcw, _mask: 0xFFFFu);
  return x;
}

//------------------------------------------------------------------------------
// Address: 0x00449AAC
// Name: __except1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _except1@<st0>(
        int a1@<ebp>,
        int flags,
        int opcode,
        long double arg,
        long double result,
        unsigned int cw)
{
  int v6; // eax
  int v8; // [esp+1Ch] [ebp-8Ch] BYREF
  _FPIEEE_RECORD rec; // [esp+28h] [ebp-80h]
  int v10; // [esp+9Ch] [ebp-Ch]
  void *v11; // [esp+A0h] [ebp-8h]
  void *retaddr; // [esp+A8h] [ebp+0h]

  v10 = a1;
  v11 = retaddr;
  if ( !_handle_exc(flags, presult: &result, cw) )
  {
    rec.Operand2.Value.Fp128Value.W[1] &= ~1u;
    _raise_exc_ex(
      prec: (_FPIEEE_RECORD *)&v8,
      pcw: &cw,
      flags,
      opcode,
      parg1: (float *)&arg,
      presult: (float *)&result,
      isfloat: 0);
  }
  v6 = _errcode(flags);
  if ( _matherr_flag == 0 && v6 != 0 )
    return _umatherr(type: v6, opcode, arg1: arg, arg2: 0.0, retval: result, cw);
  _set_errno_from_matherr(matherrtype: v6);
  _ctrlfp(newctrl: cw, _mask: 0xFFFFu);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00449B76
// Name: __statfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _statfp@<eax>(__int16 a1@<fpstat>)
{
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x00449B86
// Name: __clrfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _clrfp@<eax>(__int16 a1@<fpstat>)
{
  __asm { fnclex }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x00449B97
// Name: __ctrlfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _ctrlfp()
{
  __int16 oldCw; // [esp+0h] [ebp-4h]

  return oldCw;
}

//------------------------------------------------------------------------------
// Address: 0x00449BC2
// Name: __set_statfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _set_statfp()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00449C1A
// Name: ___set_fpsr_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __set_fpsr_sse2(unsigned int newMXCSR)
{
  if ( __sse2_available != 0 )
  {
    if ( (newMXCSR & 0x40) != 0 && _DAZ_ENABLED != 0 )
      _mm_setcsr(newMXCSR);
    else
      _mm_setcsr(newMXCSR & 0xFFFFFFBF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00449C8C
// Name: __wchartodigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wchartodigit(wchar_t ch)
{
  int v2; // ecx
  wchar_t v3; // dx

  if ( ch < 0x30u )
    return -1;
  if ( ch < 0x3Au )
    return ch - 48;
  v2 = 65296;
  if ( ch >= 0xFF10u )
  {
    v3 = -230;
LABEL_39:
    if ( ch < v3 )
      return ch - v2;
    return -1;
  }
  v2 = 1632;
  if ( ch >= 0x660u )
  {
    if ( ch < 0x66Au )
      return ch - v2;
    v2 = 1776;
    if ( ch >= 0x6F0u )
    {
      if ( ch < 0x6FAu )
        return ch - v2;
      v2 = 2406;
      if ( ch >= 0x966u )
      {
        if ( ch < 0x970u )
          return ch - v2;
        v2 = 2534;
        if ( ch >= 0x9E6u )
        {
          if ( ch < 0x9F0u )
            return ch - v2;
          v2 = 2662;
          if ( ch >= 0xA66u )
          {
            if ( ch < 0xA70u )
              return ch - v2;
            v2 = 2790;
            if ( ch >= 0xAE6u )
            {
              if ( ch < 0xAF0u )
                return ch - v2;
              v2 = 2918;
              if ( ch >= 0xB66u )
              {
                if ( ch < 0xB70u )
                  return ch - v2;
                v2 = 3174;
                if ( ch >= 0xC66u )
                {
                  if ( ch < 0xC70u )
                    return ch - v2;
                  v2 = 3302;
                  if ( ch >= 0xCE6u )
                  {
                    if ( ch < 0xCF0u )
                      return ch - v2;
                    v2 = 3430;
                    if ( ch >= 0xD66u )
                    {
                      if ( ch < 0xD70u )
                        return ch - v2;
                      v2 = 3664;
                      if ( ch >= 0xE50u )
                      {
                        if ( ch < 0xE5Au )
                          return ch - v2;
                        v2 = 3792;
                        if ( ch >= 0xED0u )
                        {
                          if ( ch < 0xEDAu )
                            return ch - v2;
                          v2 = 3872;
                          if ( ch >= 0xF20u )
                          {
                            if ( ch < 0xF2Au )
                              return ch - v2;
                            v2 = 4160;
                            if ( ch >= 0x1040u )
                            {
                              if ( ch < 0x104Au )
                                return ch - v2;
                              v2 = 6112;
                              if ( ch >= 0x17E0u )
                              {
                                if ( ch < 0x17EAu )
                                  return ch - v2;
                                v2 = 6160;
                                if ( ch >= 0x1810u )
                                {
                                  v3 = 6170;
                                  goto LABEL_39;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00449E2C
// Name: __ungetc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ungetc_nolock(int ch, _iobuf *str)
{
  int v2; // eax
  ioinfo *v3; // ecx
  ioinfo *v4; // eax
  int flag; // eax
  char *v7; // eax
  int v8; // eax

  if ( (str->_flag & 0x40) == 0 )
  {
    v2 = _fileno(stream: str);
    if ( v2 == -1 || v2 == -2 )
      v3 = &__badioinfo;
    else
      v3 = &__pioinfo[v2 >> 5][v2 & 0x1F];
    if ( (*((_BYTE *)v3 + 36) & 0x7F) != 0
      || (v2 == -1 || v2 == -2 ? (v4 = &__badioinfo) : (v4 = &__pioinfo[v2 >> 5][v2 & 0x1F]), *((char *)v4 + 36) < 0) )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return -1;
    }
  }
  if ( ch == -1 )
    return -1;
  flag = str->_flag;
  if ( (flag & 1) == 0 && ((flag & 0x80u) == 0 || (flag & 2) != 0) )
    return -1;
  if ( str->_base == nullptr )
    _getbuf(str);
  if ( str->_ptr == str->_base )
  {
    if ( str->_cnt != 0 )
      return -1;
    ++str->_ptr;
  }
  v7 = --str->_ptr;
  if ( (str->_flag & 0x40) != 0 )
  {
    if ( *v7 != (_BYTE)ch )
    {
      str->_ptr = v7 + 1;
      return -1;
    }
  }
  else
  {
    *v7 = ch;
  }
  v8 = str->_flag;
  ++str->_cnt;
  str->_flag = v8 & 0xFFFFFFEE | 1;
  return (unsigned __int8)ch;
}

//------------------------------------------------------------------------------
// Address: 0x00449F0F
// Name: _$I10_OUTPUT
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _I10_OUTPUT(_LDOUBLE ld, int ndigits, char output_flags, _FloatOutStruct *fos)
{
  unsigned __int16 v4; // dx
  int v6; // eax
  int v7; // eax
  __int16 v8; // ax
  int v9; // ebx
  bool v10; // zf
  char v11; // cl
  int v12; // ecx
  _LDBL12 *p_tmp12; // eax
  unsigned __int8 *v14; // esi
  __int16 v15; // cx
  unsigned __int16 v16; // di
  _WORD *v17; // esi
  unsigned int v18; // edx
  unsigned int v19; // ecx
  unsigned int v20; // eax
  __int16 v21; // di
  unsigned int v22; // ecx
  unsigned int v23; // edx
  int v24; // eax
  unsigned int v25; // ecx
  int v26; // esi
  int v27; // ecx
  unsigned __int16 v28; // si
  int v29; // eax
  _WORD *v30; // edi
  unsigned __int8 *v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // edx
  unsigned int v34; // ebx
  __int16 v35; // si
  unsigned int v36; // ecx
  unsigned int v37; // edx
  int v38; // eax
  unsigned int v39; // ecx
  int v40; // edi
  int v41; // ecx
  int v42; // edi
  int v43; // esi
  unsigned int v44; // eax
  int v45; // ebx
  int v46; // eax
  int v47; // esi
  int v48; // eax
  int v49; // ebx
  int v50; // eax
  char *man; // ebx
  unsigned int v52; // edx
  unsigned int v53; // edi
  unsigned int v54; // ecx
  int v55; // esi
  int v56; // ecx
  unsigned int v57; // esi
  unsigned int v58; // edi
  int v59; // edx
  unsigned int v60; // edx
  char v61; // al
  char *v62; // ebx
  _FloatOutStruct *v63; // eax
  char v64; // bl
  unsigned __int8 *v65; // [esp+10h] [ebp-70h]
  unsigned __int8 *v66; // [esp+14h] [ebp-6Ch]
  _LDBL12 *v67; // [esp+18h] [ebp-68h]
  __int16 sign; // [esp+20h] [ebp-60h]
  int v69; // [esp+24h] [ebp-5Ch]
  __int16 v70; // [esp+24h] [ebp-5Ch]
  __int16 v71; // [esp+28h] [ebp-58h]
  unsigned __int8 *v72; // [esp+28h] [ebp-58h]
  int v73; // [esp+2Ch] [ebp-54h]
  int v74; // [esp+2Ch] [ebp-54h]
  int v75; // [esp+30h] [ebp-50h]
  int v76; // [esp+30h] [ebp-50h]
  __int16 digcount; // [esp+34h] [ebp-4Ch]
  int digcounta; // [esp+34h] [ebp-4Ch]
  int v79; // [esp+38h] [ebp-48h]
  int v80; // [esp+38h] [ebp-48h]
  _LDBL12 *v81; // [esp+3Ch] [ebp-44h]
  int v82; // [esp+3Ch] [ebp-44h]
  int v83; // [esp+3Ch] [ebp-44h]
  unsigned int v84; // [esp+3Ch] [ebp-44h]
  int i; // [esp+40h] [ebp-40h]
  int j; // [esp+40h] [ebp-40h]
  char *v87; // [esp+40h] [ebp-40h]
  _LDBL12 tmp12; // [esp+44h] [ebp-3Ch] BYREF
  _LDBL12 ld12_one_tenth; // [esp+50h] [ebp-30h] BYREF
  _LDBL12 ld12; // [esp+60h] [ebp-20h] BYREF
  _BYTE v91[12]; // [esp+70h] [ebp-10h] BYREF

  sign = *(_WORD *)&ld.ld[8] & 0x8000;
  v4 = *(_WORD *)&ld.ld[8] & 0x7FFF;
  memset(&ld12_one_tenth, 204, 8);
  *(_DWORD *)&ld12_one_tenth.ld12[8] = 1073466572;
  if ( *(__int16 *)&ld.ld[8] >= 0 )
    fos->sign = 32;
  else
    fos->sign = 45;
  if ( v4 != 0 )
  {
    if ( v4 != 0x7FFF )
      goto LABEL_28;
    fos->exp = 1;
    if ( (*(_DWORD *)&ld.ld[4] != 0x80000000 || *(_DWORD *)ld.ld != 0) && (*(_DWORD *)&ld.ld[4] & 0x40000000) == 0 )
    {
      v6 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#SNAN");
      goto LABEL_25;
    }
    if ( sign != 0 && *(_DWORD *)&ld.ld[4] == -1073741824 )
    {
      if ( *(_DWORD *)ld.ld == 0 )
      {
        v7 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#IND");
        goto LABEL_22;
      }
    }
    else if ( *(_DWORD *)&ld.ld[4] == 0x80000000 && *(_DWORD *)ld.ld == 0 )
    {
      v7 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#INF");
LABEL_22:
      if ( v7 == 0 )
      {
        fos->ManLen = 5;
        return 0;
      }
LABEL_14:
      _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    }
    v6 = strcpy_s(_Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#QNAN");
LABEL_25:
    if ( v6 == 0 )
    {
      fos->ManLen = 6;
      return 0;
    }
    goto LABEL_14;
  }
  if ( *(_DWORD *)&ld.ld[4] == 0 && *(_DWORD *)ld.ld == 0 )
  {
    fos->exp = 0;
    fos->sign = sign != -32768 ? 32 : 45;
    *(_WORD *)&fos->ManLen = 12289;
    fos->man[1] = 0;
    return 1;
  }
LABEL_28:
  v8 = (77 * (HIBYTE(v4) + 2 * ld.ld[7]) + 19728 * (unsigned int)v4 - 323162868) >> 16;
  *(_WORD *)ld12.ld12 = 0;
  v9 = -v8;
  digcount = v8;
  *(_WORD *)&ld12.ld12[10] = *(_WORD *)&ld.ld[8] & 0x7FFF;
  *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&ld.ld[4];
  *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)ld.ld;
  v67 = &_pow10pos[-8];
  if ( v8 != 0 )
  {
    v10 = v8 == 0;
    if ( v8 > 0 )
    {
      v9 = v8;
      v67 = &_pow10neg[-8];
      v10 = v8 == 0;
    }
    if ( !v10 )
    {
      do
      {
        v67 += 7;
        v11 = v9;
        v9 >>= 3;
        v12 = v11 & 7;
        if ( v12 != 0 )
        {
          p_tmp12 = &v67[v12];
          v81 = p_tmp12;
          if ( *(_WORD *)p_tmp12->ld12 >= 0x8000u )
          {
            *(_DWORD *)tmp12.ld12 = *(_DWORD *)p_tmp12->ld12;
            *(_DWORD *)&tmp12.ld12[4] = *(_DWORD *)&p_tmp12->ld12[4];
            v14 = &p_tmp12->ld12[8];
            p_tmp12 = &tmp12;
            *(_DWORD *)&tmp12.ld12[8] = *(_DWORD *)v14;
            --*(_DWORD *)&tmp12.ld12[2];
            v81 = &tmp12;
          }
          v79 = 0;
          memset(v91, 0, sizeof(v91));
          v71 = (*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&p_tmp12->ld12[10]) & 0x8000;
          v15 = *(_WORD *)&p_tmp12->ld12[10] & 0x7FFF;
          v16 = v15 + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
          if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF
            || (*(_WORD *)&p_tmp12->ld12[10] & 0x7FFF) == 0x7FFF
            || v16 > 0xBFFDu )
          {
            *(_DWORD *)&ld12.ld12[8] = ((*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&p_tmp12->ld12[10]) & 0x8000u) == 0
                                     ? 2147450880
                                     : -32768;
          }
          else
          {
            if ( v16 > 0x3FBFu )
            {
              if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0 )
              {
                ++v16;
                if ( (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) == 0
                  && *(_DWORD *)&ld12.ld12[4] == 0
                  && *(_DWORD *)ld12.ld12 == 0 )
                {
                  *(_WORD *)&ld12.ld12[10] = 0;
                  continue;
                }
              }
              if ( v15 != 0
                || (++v16, (*(_DWORD *)&p_tmp12->ld12[8] & 0x7FFFFFFF) != 0)
                || *(_DWORD *)&p_tmp12->ld12[4] != 0
                || *(_DWORD *)p_tmp12->ld12 != 0 )
              {
                v73 = 0;
                v17 = &v91[4];
                for ( i = 5; i > 0; --i )
                {
                  v75 = i;
                  v65 = &ld12.ld12[2 * v73];
                  v66 = &p_tmp12->ld12[8];
                  do
                  {
                    v18 = *((_DWORD *)v17 - 1);
                    v19 = *(unsigned __int16 *)v66 * *(unsigned __int16 *)v65;
                    v69 = 0;
                    v20 = v18 + v19;
                    if ( v18 + v19 < v18 || v20 < v19 )
                      v69 = 1;
                    *((_DWORD *)v17 - 1) = v20;
                    if ( v69 != 0 )
                      ++*v17;
                    v65 += 2;
                    v66 -= 2;
                    --v75;
                  }
                  while ( v75 > 0 );
                  p_tmp12 = v81;
                  ++v17;
                  ++v73;
                }
                v21 = v16 - 16382;
                if ( v21 <= 0 )
                  goto LABEL_172;
                do
                {
                  if ( *(int *)&v91[8] < 0 )
                    break;
                  v22 = *(_DWORD *)v91;
                  *(_DWORD *)v91 *= 2;
                  v23 = *(_DWORD *)&v91[4];
                  *(_DWORD *)&v91[4] = (v22 >> 31) | (2 * *(_DWORD *)&v91[4]);
                  --v21;
                  *(_DWORD *)&v91[8] = (v23 >> 31) | (2 * *(_DWORD *)&v91[8]);
                }
                while ( v21 > 0 );
                if ( v21 <= 0 )
                {
LABEL_172:
                  if ( --v21 < 0 )
                  {
                    v24 = (unsigned __int16)-v21;
                    v21 = 0;
                    do
                    {
                      if ( (v91[0] & 1) != 0 )
                        ++v79;
                      v25 = *(_DWORD *)&v91[8];
                      *(_DWORD *)&v91[8] >>= 1;
                      v26 = __SPAIR64__(v25, *(unsigned int *)&v91[4]) >> 1;
                      v27 = *(__int64 *)v91 >> 1;
                      --v24;
                      *(_DWORD *)&v91[4] = v26;
                      *(_DWORD *)v91 = v27;
                    }
                    while ( v24 != 0 );
                    if ( v79 != 0 )
                      *(_WORD *)v91 |= 1u;
                  }
                }
                if ( *(_WORD *)v91 > 0x8000u || (*(_DWORD *)v91 & 0x1FFFF) == 0x18000 )
                {
                  if ( *(_DWORD *)&v91[2] == -1 )
                  {
                    *(_DWORD *)&v91[2] = 0;
                    if ( *(_DWORD *)&v91[6] == -1 )
                    {
                      *(_DWORD *)&v91[6] = 0;
                      if ( *(_WORD *)&v91[10] == 0xFFFF )
                      {
                        *(_WORD *)&v91[10] = 0x8000;
                        ++v21;
                      }
                      else
                      {
                        ++*(_WORD *)&v91[10];
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)&v91[6];
                    }
                  }
                  else
                  {
                    ++*(_DWORD *)&v91[2];
                  }
                }
                if ( (unsigned __int16)v21 < 0x7FFFu )
                {
                  *(_WORD *)ld12.ld12 = *(_WORD *)&v91[2];
                  *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)&v91[4];
                  *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&v91[8];
                  *(_WORD *)&ld12.ld12[10] = v71 | v21;
                }
                else
                {
                  *(_DWORD *)&ld12.ld12[4] = 0;
                  *(_DWORD *)ld12.ld12 = 0;
                  *(_DWORD *)&ld12.ld12[8] = v71 == 0 ? 2147450880 : -32768;
                }
                continue;
              }
            }
            *(_DWORD *)&ld12.ld12[8] = 0;
          }
          *(_DWORD *)&ld12.ld12[4] = 0;
          *(_DWORD *)ld12.ld12 = 0;
        }
      }
      while ( v9 != 0 );
    }
  }
  if ( *(_WORD *)&ld12.ld12[10] < 0x3FFFu )
    goto LABEL_134;
  ++digcount;
  v76 = 0;
  memset(v91, 0, sizeof(v91));
  v70 = (*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&ld12_one_tenth.ld12[10]) & 0x8000;
  v28 = (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
  if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF
    || (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) == 0x7FFF
    || v28 > 0xBFFDu )
  {
    *(_DWORD *)&ld12.ld12[4] = 0;
    v29 = ((*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&ld12_one_tenth.ld12[10]) & 0x8000u) == 0 ? 2147450880 : -32768;
    *(_DWORD *)ld12.ld12 = 0;
  }
  else
  {
    if ( v28 > 0x3FBFu )
    {
      v29 = 0;
      if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0 )
      {
        ++v28;
        if ( (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) == 0 && *(_DWORD *)&ld12.ld12[4] == 0 && *(_DWORD *)ld12.ld12 == 0 )
        {
          *(_WORD *)&ld12.ld12[10] = 0;
          goto LABEL_134;
        }
      }
      if ( (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) != 0
        || (++v28, (*(_DWORD *)&ld12_one_tenth.ld12[8] & 0x7FFFFFFF) != 0)
        || *(_DWORD *)&ld12_one_tenth.ld12[4] != 0
        || *(_DWORD *)ld12_one_tenth.ld12 != 0 )
      {
        v74 = 0;
        v30 = &v91[4];
        for ( j = 5; j > 0; --j )
        {
          v80 = j;
          v72 = &ld12_one_tenth.ld12[8];
          v31 = &ld12.ld12[2 * v74];
          do
          {
            v82 = 0;
            v32 = *(unsigned __int16 *)v31 * *(unsigned __int16 *)v72;
            v33 = *((_DWORD *)v30 - 1);
            v34 = v33 + v32;
            if ( v33 + v32 < v33 || v34 < v32 )
              v82 = 1;
            *((_DWORD *)v30 - 1) = v34;
            if ( v82 != 0 )
              ++*v30;
            v72 -= 2;
            v31 += 2;
            --v80;
          }
          while ( v80 > 0 );
          ++v30;
          ++v74;
        }
        v35 = v28 - 16382;
        if ( v35 <= 0 )
          goto LABEL_173;
        do
        {
          if ( *(int *)&v91[8] < 0 )
            break;
          v36 = *(_DWORD *)v91;
          *(_DWORD *)v91 *= 2;
          v37 = *(_DWORD *)&v91[4];
          *(_DWORD *)&v91[4] = (v36 >> 31) | (2 * *(_DWORD *)&v91[4]);
          --v35;
          *(_DWORD *)&v91[8] = (v37 >> 31) | (2 * *(_DWORD *)&v91[8]);
        }
        while ( v35 > 0 );
        if ( v35 <= 0 )
        {
LABEL_173:
          if ( --v35 < 0 )
          {
            v38 = (unsigned __int16)-v35;
            v35 = 0;
            do
            {
              if ( (v91[0] & 1) != 0 )
                ++v76;
              v39 = *(_DWORD *)&v91[8];
              *(_DWORD *)&v91[8] >>= 1;
              v40 = __SPAIR64__(v39, *(unsigned int *)&v91[4]) >> 1;
              v41 = *(__int64 *)v91 >> 1;
              --v38;
              *(_DWORD *)&v91[4] = v40;
              *(_DWORD *)v91 = v41;
            }
            while ( v38 != 0 );
            if ( v76 != 0 )
              *(_WORD *)v91 |= 1u;
          }
        }
        if ( *(_WORD *)v91 > 0x8000u || (*(_DWORD *)v91 & 0x1FFFF) == 0x18000 )
        {
          if ( *(_DWORD *)&v91[2] == -1 )
          {
            *(_DWORD *)&v91[2] = 0;
            if ( *(_DWORD *)&v91[6] == -1 )
            {
              *(_DWORD *)&v91[6] = 0;
              if ( *(_WORD *)&v91[10] == 0xFFFF )
              {
                *(_WORD *)&v91[10] = 0x8000;
                ++v35;
              }
              else
              {
                ++*(_WORD *)&v91[10];
              }
            }
            else
            {
              ++*(_DWORD *)&v91[6];
            }
          }
          else
          {
            ++*(_DWORD *)&v91[2];
          }
        }
        if ( (unsigned __int16)v35 < 0x7FFFu )
        {
          *(_WORD *)ld12.ld12 = *(_WORD *)&v91[2];
          *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)&v91[4];
          *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&v91[8];
          *(_WORD *)&ld12.ld12[10] = v70 | v35;
        }
        else
        {
          *(_DWORD *)&ld12.ld12[4] = 0;
          *(_DWORD *)ld12.ld12 = 0;
          *(_DWORD *)&ld12.ld12[8] = v70 == 0 ? 2147450880 : -32768;
        }
        goto LABEL_134;
      }
    }
    else
    {
      v29 = 0;
    }
    *(_DWORD *)&ld12.ld12[4] = 0;
    *(_DWORD *)ld12.ld12 = 0;
  }
  *(_DWORD *)&ld12.ld12[8] = v29;
LABEL_134:
  v42 = ndigits;
  fos->exp = digcount;
  if ( (output_flags & 1) != 0 )
  {
    v42 = digcount + ndigits;
    if ( v42 <= 0 )
    {
      fos->exp = 0;
      *(_WORD *)&fos->ManLen = 12289;
      fos->sign = sign != -32768 ? 32 : 45;
      fos->man[1] = 0;
      return 1;
    }
  }
  if ( v42 > 21 )
    v42 = 21;
  v43 = *(unsigned __int16 *)&ld12.ld12[10] - 16382;
  *(_WORD *)&ld12.ld12[10] = 0;
  v83 = 8;
  do
  {
    v44 = *(_DWORD *)ld12.ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v45 = (v44 >> 31) | (2 * *(_DWORD *)&ld12.ld12[4]);
    v46 = *(__int64 *)&ld12.ld12[4] >> 31;
    v10 = v83-- == 1;
    *(_DWORD *)&ld12.ld12[4] = v45;
    *(_DWORD *)&ld12.ld12[8] = v46;
  }
  while ( !v10 );
  if ( v43 < 0 )
  {
    v47 = (unsigned __int8)-(char)v43;
    if ( v47 != 0 )
    {
      do
      {
        v48 = *(_DWORD *)&ld12.ld12[8];
        *(_DWORD *)&ld12.ld12[8] >>= 1;
        v49 = (v48 << 31) | (*(_DWORD *)&ld12.ld12[4] >> 1);
        v50 = *(__int64 *)ld12.ld12 >> 1;
        --v47;
        *(_DWORD *)&ld12.ld12[4] = v49;
        *(_DWORD *)ld12.ld12 = v50;
      }
      while ( v47 > 0 );
    }
  }
  man = fos->man;
  v87 = fos->man;
  for ( digcounta = v42 + 1; digcounta > 0; ld12.ld12[11] = 0 )
  {
    v52 = *(_DWORD *)ld12.ld12;
    tmp12 = ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v53 = *(_DWORD *)ld12.ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v54 = (v52 >> 31) | (2 * *(_DWORD *)&ld12.ld12[4]);
    v55 = 2 * v54;
    v56 = (v54 >> 31) | (2 * (*(__int64 *)&ld12.ld12[4] >> 31));
    v57 = (v53 >> 31) | v55;
    v58 = *(_DWORD *)tmp12.ld12 + *(_DWORD *)ld12.ld12;
    if ( (unsigned int)(*(_DWORD *)tmp12.ld12 + *(_DWORD *)ld12.ld12) < *(_DWORD *)ld12.ld12
      || v58 < *(_DWORD *)tmp12.ld12 )
    {
      v59 = 0;
      if ( v57 + 1 < v57 || v57 == -1 )
        v59 = 1;
      ++v57;
      if ( v59 != 0 )
        ++v56;
    }
    v60 = *(_DWORD *)&tmp12.ld12[4] + v57;
    v84 = *(_DWORD *)&tmp12.ld12[4] + v57;
    if ( *(_DWORD *)&tmp12.ld12[4] + v57 < v57 || v60 < *(_DWORD *)&tmp12.ld12[4] )
      ++v56;
    *(_DWORD *)ld12.ld12 = 2 * v58;
    *(_DWORD *)&ld12.ld12[8] = (v60 >> 31) | (2 * (*(_DWORD *)&tmp12.ld12[8] + v56));
    *man++ = ld12.ld12[11] + 48;
    --digcounta;
    *(_DWORD *)&ld12.ld12[4] = (v58 >> 31) | (2 * v84);
  }
  v61 = *(man - 1);
  v62 = man - 2;
  if ( v61 >= 53 )
  {
    while ( v62 >= v87 && *v62 == 57 )
      *v62-- = 48;
    v63 = fos;
    if ( v62 < v87 )
    {
      ++v62;
      ++fos->exp;
    }
    ++*v62;
  }
  else
  {
    while ( v62 >= v87 && *v62 == 48 )
      --v62;
    v63 = fos;
    if ( v62 < v87 )
    {
      fos->exp = 0;
      fos->ManLen = 1;
      fos->sign = sign != -32768 ? 32 : 45;
      *v87 = 48;
      fos->man[1] = 0;
      return 1;
    }
  }
  v64 = (_BYTE)v62 - (_BYTE)v63 - 3;
  v63->ManLen = v64;
  v63->man[v64] = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044A807
// Name: _hw_cw
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall hw_cw@<eax>(unsigned int abstr@<ebx>)
{
  int result; // eax
  unsigned int v2; // ecx

  result = (abstr & 0x10) != 0;
  if ( (abstr & 8) != 0 )
    result |= 4u;
  if ( (abstr & 4) != 0 )
    result |= 8u;
  if ( (abstr & 2) != 0 )
    result |= 0x10u;
  if ( (abstr & 1) != 0 )
    result |= 0x20u;
  if ( (abstr & 0x80000) != 0 )
    result |= 2u;
  v2 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v2 )
    {
      case 0x100u:
        result |= 0x400u;
        break;
      case 0x200u:
        result |= 0x800u;
        break;
      case 0x300u:
        result |= 0xC00u;
        break;
      default:
        break;
    }
  }
  if ( (abstr & 0x30000) != 0 )
  {
    if ( (abstr & 0x30000) == 0x10000 )
      result |= 0x200u;
  }
  else
  {
    result |= 0x300u;
  }
  if ( (abstr & 0x40000) != 0 )
    return result | 0x1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044A895
// Name: __hw_cw_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __fastcall _hw_cw_sse2(int a1, unsigned int abstr)
{
  unsigned int result; // eax
  unsigned int v3; // ecx
  unsigned int v4; // edx

  result = 0;
  if ( (abstr & 0x10) != 0 )
    result = 128;
  if ( (abstr & 8) != 0 )
    result |= 0x200u;
  if ( (abstr & 4) != 0 )
    result |= 0x400u;
  if ( (abstr & 2) != 0 )
    result |= 0x800u;
  if ( (abstr & 1) != 0 )
    result |= 0x1000u;
  if ( (abstr & 0x80000) != 0 )
    result |= 0x100u;
  v3 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v3 )
    {
      case 0x100u:
        result |= 0x2000u;
        break;
      case 0x200u:
        result |= 0x4000u;
        break;
      case 0x300u:
        result |= 0x6000u;
        break;
      default:
        break;
    }
  }
  v4 = abstr & 0x3000000;
  switch ( v4 )
  {
    case 0x1000000u:
      result |= 0x8040u;
      break;
    case 0x2000000u:
      result |= 0x40u;
      break;
    case 0x3000000u:
      result |= 0x8000u;
      break;
    default:
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044A935
// Name: __control87
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _control87(unsigned int newctrl, unsigned int mask)
{
  int v2; // edx
  int v3; // eax
  unsigned int result; // eax
  __int16 v6; // ax
  __int16 v7; // bx
  unsigned int v8; // edx
  int v9; // eax
  int v10; // esi
  __int16 v11; // ax
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  unsigned int v15; // edx
  int v16; // eax
  __int16 v17; // cx
  int v18; // edx
  int v19; // eax
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  unsigned int v23; // [esp+14h] [ebp-Ch]
  __int16 oldCw; // [esp+1Ch] [ebp-4h]
  unsigned int newabs; // [esp+2Ch] [ebp+Ch]

  v2 = 0;
  if ( (oldCw & 1) != 0 )
    v2 = 16;
  if ( (oldCw & 4) != 0 )
    v2 |= 8u;
  if ( (oldCw & 8) != 0 )
    v2 |= 4u;
  if ( (oldCw & 0x10) != 0 )
    v2 |= 2u;
  if ( (oldCw & 0x20) != 0 )
    v2 |= 1u;
  if ( (oldCw & 2) != 0 )
    v2 |= 0x80000u;
  v3 = oldCw & 0xC00;
  if ( (oldCw & 0xC00) != 0 )
  {
    switch ( v3 )
    {
      case 1024:
        v2 |= 0x100u;
        break;
      case 2048:
        v2 |= 0x200u;
        break;
      case 3072:
        v2 |= 0x300u;
        break;
      default:
        break;
    }
  }
  if ( (oldCw & 0x300) != 0 )
  {
    if ( (oldCw & 0x300) == 0x200 )
      v2 |= 0x10000u;
  }
  else
  {
    v2 |= 0x20000u;
  }
  if ( (oldCw & 0x1000) != 0 )
    v2 |= 0x40000u;
  result = mask & newctrl | v2 & ~mask;
  newabs = result;
  if ( result != v2 )
  {
    v6 = hw_cw(abstr: result);
    v7 = v6;
    v8 = 0;
    if ( (v6 & 1) != 0 )
      v8 = 16;
    if ( (v6 & 4) != 0 )
      v8 |= 8u;
    if ( (v6 & 8) != 0 )
      v8 |= 4u;
    if ( (v6 & 0x10) != 0 )
      v8 |= 2u;
    if ( (v6 & 0x20) != 0 )
      v8 |= 1u;
    if ( (v6 & 2) != 0 )
      v8 |= 0x80000u;
    v9 = v6 & 0xC00;
    if ( (v7 & 0xC00) != 0 )
    {
      switch ( v9 )
      {
        case 1024:
          v8 |= 0x100u;
          break;
        case 2048:
          v8 |= 0x200u;
          break;
        case 3072:
          v8 |= 0x300u;
          break;
        default:
          break;
      }
    }
    if ( (v7 & 0x300) != 0 )
    {
      if ( (v7 & 0x300) == 0x200 )
        v8 |= 0x10000u;
    }
    else
    {
      v8 |= 0x20000u;
    }
    if ( (v7 & 0x1000) != 0 )
      v8 |= 0x40000u;
    newabs = v8;
    result = v8;
  }
  v10 = 0;
  if ( __sse2_available != 0 )
  {
    v11 = _mm_getcsr();
    if ( (v11 & 0x80u) != 0 )
      v10 = 16;
    if ( (v11 & 0x200) != 0 )
      v10 |= 8u;
    if ( (v11 & 0x400) != 0 )
      v10 |= 4u;
    if ( (v11 & 0x800) != 0 )
      v10 |= 2u;
    if ( (v11 & 0x1000) != 0 )
      v10 |= 1u;
    if ( (v11 & 0x100) != 0 )
      v10 |= 0x80000u;
    v12 = v11 & 0x6000;
    if ( (v11 & 0x6000) != 0 )
    {
      switch ( v12 )
      {
        case 8192:
          v10 |= 0x100u;
          break;
        case 16384:
          v10 |= 0x200u;
          break;
        case 24576:
          v10 |= 0x300u;
          break;
        default:
          break;
      }
    }
    v13 = (v11 & 0x8040) - 64;
    if ( v13 != 0 )
    {
      v14 = v13 - 32704;
      if ( v14 != 0 )
      {
        if ( v14 == 64 )
          v10 |= 0x1000000u;
      }
      else
      {
        v10 |= 0x3000000u;
      }
    }
    else
    {
      v10 |= 0x2000000u;
    }
    v15 = newctrl & mask & 0x308031F | v10 & ~(mask & 0x308031F);
    if ( v15 == v10 )
    {
      v16 = v10;
    }
    else
    {
      v23 = _hw_cw_sse2(a1: v12, abstr: v15);
      __set_fpsr_sse2(newMXCSR: v23);
      v17 = _mm_getcsr();
      v18 = 0;
      if ( (v17 & 0x80u) != 0 )
        v18 = 16;
      if ( (v17 & 0x200) != 0 )
        v18 |= 8u;
      if ( (v17 & 0x400) != 0 )
        v18 |= 4u;
      if ( (v17 & 0x800) != 0 )
        v18 |= 2u;
      if ( (v17 & 0x1000) != 0 )
        v18 |= 1u;
      if ( (v17 & 0x100) != 0 )
        v18 |= 0x80000u;
      v19 = v17 & 0x6000;
      if ( (v17 & 0x6000) != 0 )
      {
        switch ( v19 )
        {
          case 8192:
            v18 |= 0x100u;
            break;
          case 16384:
            v18 |= 0x200u;
            break;
          case 24576:
            v18 |= 0x300u;
            break;
          default:
            break;
        }
      }
      v20 = (v17 & 0x8040) - 64;
      if ( v20 != 0 )
      {
        v21 = v20 - 32704;
        if ( v21 != 0 )
        {
          if ( v21 == 64 )
            v18 |= 0x1000000u;
        }
        else
        {
          v18 |= 0x3000000u;
        }
      }
      else
      {
        v18 |= 0x2000000u;
      }
      v16 = v18;
    }
    v22 = newabs ^ v16;
    result = newabs | v16;
    if ( (v22 & 0x8031F) != 0 )
      result |= 0x80000000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044AC47
// Name: ___ascii_stricmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __ascii_stricmp(const char *dst, const char *src)
{
  int v4; // eax
  int v5; // ecx

  do
  {
    v4 = *(unsigned __int8 *)dst++;
    if ( (unsigned int)(v4 - 65) <= 0x19 )
      v4 += 32;
    v5 = *(unsigned __int8 *)src++;
    if ( (unsigned int)(v5 - 65) <= 0x19 )
      v5 += 32;
  }
  while ( v4 != 0 && v4 == v5 );
  return v4 - v5;
}

//------------------------------------------------------------------------------
// Address: 0x0044AC80
// Name: __stricmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _stricmp_l(const char *dst, const char *src, localeinfo_struct *plocinfo)
{
  int result; // eax
  const char *v4; // esi
  int v5; // edi
  int v6; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( dst != nullptr )
  {
    v4 = src;
    if ( src != nullptr )
    {
      if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
      {
        do
        {
          v5 = _tolower_l(c: (unsigned __int8)v4[dst - src], plocinfo: &_loc_update.localeinfo);
          v6 = _tolower_l(c: *(unsigned __int8 *)v4++, plocinfo: &_loc_update.localeinfo);
        }
        while ( v5 != 0 && v5 == v6 );
        result = v5 - v6;
      }
      else
      {
        result = __ascii_stricmp(dst, src);
      }
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044AD40
// Name: __strnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strnicmp_l(char *dst, char *src, unsigned int count, localeinfo_struct *plocinfo)
{
  char *v4; // esi
  int v5; // edi
  int v6; // eax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  if ( count != 0 )
  {
    _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
    if ( dst != nullptr && (v4 = src, src != nullptr) )
    {
      if ( count <= 0x7FFFFFFF )
      {
        if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
        {
          do
          {
            v5 = _tolower_l(c: (unsigned __int8)v4[dst - src], plocinfo: &_loc_update.localeinfo);
            v6 = _tolower_l(c: (unsigned __int8)*v4++, plocinfo: &_loc_update.localeinfo);
            --count;
          }
          while ( count != 0 && v5 != 0 && v5 == v6 );
        }
        else
        {
          __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
        }
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
      }
      else
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044AE22
// Name: __strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strnicmp(char *dst, char *src, unsigned int count)
{
  if ( __locale_changed != 0 )
  {
    _strnicmp_l(dst, src, count, plocinfo: nullptr);
  }
  else if ( dst != nullptr && src != nullptr && count <= 0x7FFFFFFF )
  {
    __ascii_strnicmp(first: (unsigned __int8 *)dst, last: (unsigned __int8 *)src, count);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044AE75
// Name: __putwch_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t __cdecl _putwch_nolock(wchar_t ch)
{
  unsigned int cchWritten; // [esp+0h] [ebp-4h] BYREF

  if ( _confh == (HANDLE)-2 )
    __initconout();
  if ( _confh == (HANDLE)-1
    || !WriteConsoleW(
          hConsoleOutput: _confh,
          lpBuffer: &ch,
          nNumberOfCharsToWrite: 1u,
          lpNumberOfCharsWritten: &cchWritten,
          lpReserved: nullptr) )
  {
    return -1;
  }
  else
  {
    return ch;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044AEB7
// Name: ___crtCompareStringW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtCompareStringW(
        LCID Locale,
        DWORD dwCmpFlags,
        const wchar_t *lpString1,
        int cchCount1,
        const wchar_t *lpString2,
        int cchCount2)
{
  int v6; // esi
  int v7; // eax

  v6 = cchCount1;
  if ( cchCount1 > 0 )
    v6 = wcsnlen(wcs: lpString1, maxsize: cchCount1);
  v7 = cchCount2;
  if ( cchCount2 > 0 )
    v7 = wcsnlen(wcs: lpString2, maxsize: cchCount2);
  if ( v6 != 0 && v7 != 0 )
    return CompareStringW(Locale, dwCmpFlags, lpString1, cchCount1: v6, lpString2, cchCount2: v7);
  if ( v6 == v7 )
    return 2;
  return 2 * (v6 - v7 >= 0) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044AF1A
// Name: __mbsnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbsnicmp_l(char *s1, char *s2, unsigned int n, localeinfo_struct *plocinfo)
{
  char *v4; // edi
  char *v5; // ebx
  int v6; // ecx
  bool v7; // zf
  int v8; // ecx
  __int16 v9; // si
  char *v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  char *v14; // ecx
  int v15; // ecx
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-14h] BYREF
  int c1; // [esp+10h] [ebp-4h]

  if ( n == 0 )
    return;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    _strnicmp(dst: s1, src: s2, count: n);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  v4 = s1;
  if ( s1 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  v5 = s2;
  if ( s2 == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  while ( 1 )
  {
    v6 = (unsigned __int8)*v4;
    --n;
    ++v4;
    v7 = (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v6 + 1] & 4) == 0;
    c1 = v6;
    if ( v7 )
    {
      v10 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c1;
      if ( (v10[29] & 0x10) != 0 )
        v11 = (unsigned __int8)v10[285];
      else
        v11 = (unsigned __int16)c1;
      c1 = v11;
      goto LABEL_26;
    }
    if ( *v4 == 0 )
    {
      c1 = 0;
LABEL_26:
      v9 = c1;
      goto LABEL_27;
    }
    v8 = (unsigned __int16)((unsigned __int8)*v4 | (unsigned __int16)((_WORD)v6 << 8));
    v9 = v8;
    ++v4;
    c1 = v8;
    if ( (unsigned __int16)v8 < _loc_update.localeinfo.mbcinfo->mbulinfo[0]
      || (unsigned __int16)v8 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( (unsigned __int16)v8 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3]
        && (unsigned __int16)v8 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
      {
        v9 = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v8;
      }
    }
    else
    {
      v9 = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v8;
    }
LABEL_27:
    v12 = (unsigned __int8)*v5++;
    v7 = (_loc_update.localeinfo.mbcinfo->mbctype[(unsigned __int8)v12 + 1] & 4) == 0;
    c1 = v12;
    if ( v7 )
    {
      v14 = (char *)_loc_update.localeinfo.mbcinfo + (unsigned __int16)c1;
      if ( (v14[29] & 0x10) != 0 )
        v15 = (unsigned __int8)v14[285];
      else
        v15 = (unsigned __int16)c1;
      c1 = v15;
      goto LABEL_40;
    }
    if ( *v5 == 0 )
    {
      c1 = 0;
LABEL_40:
      LOWORD(v13) = c1;
      goto LABEL_41;
    }
    v13 = (unsigned __int16)((unsigned __int8)*v5++ | (unsigned __int16)((_WORD)v12 << 8));
    c1 = v13;
    if ( (unsigned __int16)v13 < _loc_update.localeinfo.mbcinfo->mbulinfo[0]
      || (unsigned __int16)v13 > _loc_update.localeinfo.mbcinfo->mbulinfo[1] )
    {
      if ( (unsigned __int16)v13 >= _loc_update.localeinfo.mbcinfo->mbulinfo[3]
        && (unsigned __int16)v13 <= _loc_update.localeinfo.mbcinfo->mbulinfo[4] )
      {
        LOWORD(v13) = _loc_update.localeinfo.mbcinfo->mbulinfo[5] + v13;
      }
    }
    else
    {
      LOWORD(v13) = _loc_update.localeinfo.mbcinfo->mbulinfo[2] + v13;
    }
LABEL_41:
    if ( (_WORD)v13 != v9 )
      break;
    if ( v9 == 0 || n == 0 )
    {
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x0044B0E5
// Name: __mbsnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbsnicmp(char *s1, char *s2, unsigned int n)
{
  _mbsnicmp_l(s1, s2, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0044B100
// Name: ___ascii_strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __ascii_strnicmp(unsigned __int8 *first, unsigned __int8 *last, unsigned int count)
{
  unsigned int i; // ecx
  unsigned __int8 v6; // ah
  unsigned __int8 v7; // al

  for ( i = count; i != 0; --i )
  {
    v6 = *first;
    v7 = *last;
    if ( *first == 0 || v7 == 0 )
      break;
    ++first;
    ++last;
    if ( v6 >= 0x41u && v6 <= 0x5Au )
      v6 += 32;
    if ( v7 >= 0x41u && v7 <= 0x5Au )
      v7 += 32;
    if ( v6 != v7 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044B161
// Name: ___initconout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __initconout()
{
  HANDLE result; // eax

  result = CreateFileW(
             lpFileName: L"CONOUT$",
             dwDesiredAccess: 0x40000000u,
             dwShareMode: 3u,
             lpSecurityAttributes: nullptr,
             dwCreationDisposition: 3u,
             dwFlagsAndAttributes: 0,
             hTemplateFile: nullptr);
  _confh = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044B180
// Name: ___termconout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __termconout()
{
  HANDLE result; // eax

  result = _confh;
  if ( _confh != (HANDLE)-1 && _confh != (HANDLE)-2 )
    return (HANDLE)CloseHandle(hObject: _confh);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044B198
// Name: RtlUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
{
  __imp__RtlUnwind@16(TargetFrame, TargetIp, ExceptionRecord, ReturnValue);
}

//------------------------------------------------------------------------------
// Address: 0x0044B19E
// Name: __getextendedkeycode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const NormKeyVals *__cdecl _getextendedkeycode(_KEY_EVENT_RECORD *pKE)
{
  unsigned int dwControlKeyState; // ebx
  const NormKeyVals *result; // eax
  int v3; // ecx
  unsigned int v4; // esi
  int v5; // ecx
  int wVirtualScanCode; // eax

  dwControlKeyState = pKE->dwControlKeyState;
  if ( (dwControlKeyState & 0x100) != 0 )
  {
    result = nullptr;
    v3 = 0;
    v4 = 0;
    while ( EnhancedKeys[v4].ScanCode != pKE->wVirtualScanCode )
    {
      ++v4;
      ++v3;
      if ( v4 >= 12 )
        return result;
    }
    v5 = v3;
    if ( (dwControlKeyState & 3) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].AltChars;
    if ( (dwControlKeyState & 0xC) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].CtrlChars;
    if ( (dwControlKeyState & 0x10) != 0 )
      return (const NormKeyVals *)&EnhancedKeys[v5].ShiftChars;
    return (const NormKeyVals *)&EnhancedKeys[v5].RegChars;
  }
  else
  {
    wVirtualScanCode = pKE->wVirtualScanCode;
    if ( (dwControlKeyState & 3) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].AltChars;
    }
    else if ( (dwControlKeyState & 0xC) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].CtrlChars;
    }
    else if ( (dwControlKeyState & 0x10) != 0 )
    {
      result = (const NormKeyVals *)&NormalKeys[wVirtualScanCode].ShiftChars;
    }
    else
    {
      result = &NormalKeys[wVirtualScanCode];
    }
    if ( result->RegChars.LeadChar != 0 && result->RegChars.LeadChar != 0xE0 || result->RegChars.SecondChar == 0 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044B251
// Name: __getch_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _getch_nolock()
{
  int result; // eax
  int AsciiChar; // edi
  const NormKeyVals *v2; // eax
  unsigned int oldstate; // [esp+4h] [ebp-20h] BYREF
  unsigned int NumRead; // [esp+8h] [ebp-1Ch] BYREF
  _INPUT_RECORD ConInpRec; // [esp+Ch] [ebp-18h] BYREF

  if ( chbuf == -1 )
  {
    if ( _coninpfh == (HANDLE)-2 )
      __initconin();
    if ( _coninpfh == (HANDLE)-1 )
    {
      return -1;
    }
    else
    {
      GetConsoleMode(hConsoleHandle: _coninpfh, lpMode: &oldstate);
      SetConsoleMode(hConsoleHandle: _coninpfh, dwMode: 0);
      while ( 1 )
      {
        if ( !ReadConsoleInputA(
                hConsoleInput: _coninpfh,
                lpBuffer: &ConInpRec,
                nLength: 1u,
                lpNumberOfEventsRead: &NumRead)
          || NumRead == 0 )
        {
          AsciiChar = -1;
          goto LABEL_15;
        }
        if ( ConInpRec.EventType == 1 && ConInpRec.Event.KeyEvent.bKeyDown != 0 )
        {
          AsciiChar = (unsigned __int8)ConInpRec.Event.KeyEvent.uChar.AsciiChar;
          if ( ConInpRec.Event.KeyEvent.uChar.AsciiChar != 0 )
            goto LABEL_15;
          v2 = _getextendedkeycode(pKE: &ConInpRec.Event.KeyEvent);
          if ( v2 != nullptr )
            break;
        }
      }
      AsciiChar = v2->RegChars.LeadChar;
      chbuf = v2->RegChars.SecondChar;
LABEL_15:
      SetConsoleMode(hConsoleHandle: _coninpfh, dwMode: oldstate);
      return AsciiChar;
    }
  }
  else
  {
    result = (unsigned __int8)chbuf;
    chbuf = -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044B32A
// Name: _getch
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl getch()
{
  int v1; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 3);
  v1 = _getch_nolock();
  _unlock(locknum: 3);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0044B368
// Name: ___initconin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __initconin()
{
  HANDLE result; // eax

  result = CreateFileW(
             lpFileName: L"CONIN$",
             dwDesiredAccess: 0xC0000000,
             dwShareMode: 3u,
             lpSecurityAttributes: nullptr,
             dwCreationDisposition: 3u,
             dwFlagsAndAttributes: 0,
             hTemplateFile: nullptr);
  _coninpfh = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044B387
// Name: ___termconin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __termconin()
{
  HANDLE result; // eax

  result = _coninpfh;
  if ( _coninpfh != (HANDLE)-1 && _coninpfh != (HANDLE)-2 )
    return (HANDLE)CloseHandle(hObject: _coninpfh);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044B3A0
// Name: _dynamic_initializer_for__g_FacePoserSound__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_FacePoserSound__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_FacePoserSound__);
}

//------------------------------------------------------------------------------
// Address: 0x0044B3B0
// Name: _dynamic_initializer_for__g_CleanupFunctions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupFunctions__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupFunctions__);
}

//------------------------------------------------------------------------------
// Address: 0x0044B3C0
// Name: _dynamic_initializer_for__g_ExitStopper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExitStopper__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ExitStopper__);
}

//------------------------------------------------------------------------------
// Address: 0x0044B3D0
// Name: _dynamic_initializer_for__g_WaveLoader__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_WaveLoader__()
{
  CFileLoaderThread::CFileLoaderThread(this: &g_WaveLoader);
  return atexit(func: dynamic_atexit_destructor_for__g_WaveLoader__);
}

//------------------------------------------------------------------------------
// Address: 0x0044B3F0
// Name: _dynamic_initializer_for__g_Random__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUniformRandomStream *dynamic_initializer_for__g_Random__()
{
  return CUniformRandomStream::CUniformRandomStream(this: &g_Random);
}

//------------------------------------------------------------------------------
// Address: 0x0044B400
// Name: _dynamic_initializer_for__g_definevariable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_definevariable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_definevariable__);
}

//------------------------------------------------------------------------------
// Address: 0x0044B410
// Name: _dynamic_initializer_for__g_Params__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Params__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Params__);
}

//------------------------------------------------------------------------------
// Address: 0x0044B420
// Name: _dynamic_initializer_for__g_Params___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Params___0()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Params___0);
}

//------------------------------------------------------------------------------
// Address: 0x0044B430
// Name: _dynamic_initializer_for__g_Params___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Params___1()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Params___1);
}

//------------------------------------------------------------------------------
// Address: 0x0044B440
// Name: _dynamic_initializer_for__g_CheckNamesSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCheckEventNames *dynamic_initializer_for__g_CheckNamesSingleton__()
{
  return CCheckEventNames::CCheckEventNames(this: &g_CheckNamesSingleton);
}

//------------------------------------------------------------------------------
// Address: 0x0044B450
// Name: _dynamic_initializer_for__g_CheckCCNamesSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCheckCCNames *dynamic_initializer_for__g_CheckCCNamesSingleton__()
{
  return CCheckCCNames::CCheckCCNames(this: &g_CheckCCNamesSingleton);
}

//------------------------------------------------------------------------------
// Address: 0x0044B460
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044B4C0
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044B4F0
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x0044B510
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044B520
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x0044B540
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x0044B550
// Name: _dynamic_atexit_destructor_for__g_FacePoserSound__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_FacePoserSound__()
{
  CSceneManagerSound::~CSceneManagerSound(this: &g_FacePoserSound);
}

//------------------------------------------------------------------------------
// Address: 0x0044B560
// Name: _dynamic_atexit_destructor_for__g_ExitStopper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0044B580
// Name: _dynamic_atexit_destructor_for__g_CleanupFunctions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupFunctions__()
{
  CUtlLinkedList<void (__cdecl *)(void),unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<void (__cdecl *)(void),unsigned short>,unsigned short>>::RemoveAll(this: &g_CleanupFunctions);
  if ( g_CleanupFunctions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_CleanupFunctions.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_CleanupFunctions.m_Memory.m_pMemory);
      g_CleanupFunctions.m_Memory.m_pMemory = nullptr;
    }
    g_CleanupFunctions.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044B5D0
// Name: _CmdLib_FPrintf_::_2_::_dynamic_atexit_destructor_for__buf__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CmdLib_FPrintf_::_2_::_dynamic_atexit_destructor_for__buf__()
{
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&buf);
}

//------------------------------------------------------------------------------
// Address: 0x0044B5E0
// Name: _dynamic_atexit_destructor_for__g_WaveLoader__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_WaveLoader__()
{
  CFileLoaderThread::~CFileLoaderThread(this: &g_WaveLoader);
}

//------------------------------------------------------------------------------
// Address: 0x0044B5F0
// Name: _dynamic_atexit_destructor_for__g_definevariable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_definevariable__()
{
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_definevariable);
}

//------------------------------------------------------------------------------
// Address: 0x0044B600
// Name: _dynamic_atexit_destructor_for__g_Params__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Params__()
{
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_Params_1.items);
}

//------------------------------------------------------------------------------
// Address: 0x0044B610
// Name: _dynamic_atexit_destructor_for__g_Params___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Params___0()
{
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_Params_2.items);
}

//------------------------------------------------------------------------------
// Address: 0x0044B620
// Name: _dynamic_atexit_destructor_for__g_Params___1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Params___1()
{
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_Params_4.items);
}

//------------------------------------------------------------------------------
// Address: 0x0044B630
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x0044B640
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0044B690
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
    CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>::~CUtlVector<CFileLoaderThread::SentenceRequest *,CUtlMemory<CFileLoaderThread::SentenceRequest *,int>>(this: &v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}
