// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/hlfaceposer.cpp
// Functions: 32
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0045D620
// Name: char __near * PSkipSoundChars(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl PSkipSoundChars(char *pch)
{
  char *result; // eax
  char v2; // cl

  for ( result = pch; ; ++result )
  {
    v2 = *result;
    if ( *result != 42
      && v2 != 63
      && v2 != 33
      && v2 != 35
      && v2 != 64
      && v2 != 40
      && v2 != 62
      && v2 != 60
      && v2 != 94
      && v2 != 41
      && v2 != 125
      && v2 != 36 )
    {
      break;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0045D670
// Name: char __near * FacePoser_MakeWindowsSlashes(char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl FacePoser_MakeWindowsSlashes(char *pname)
{
  char *i; // eax

  strcpy(returnString, pname);
  for ( i = returnString; *i != 0; ++i )
  {
    if ( *i == 47 )
      *i = 92;
  }
  return returnString;
}

//------------------------------------------------------------------------------
// Address: 0x0045D6B0
// Name: int GetCloseCaptionLanguageId(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetCloseCaptionLanguageId()
{
  return g_viewerSettings.cclanguageid;
}

//------------------------------------------------------------------------------
// Address: 0x0045D6C0
// Name: char __near * va(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *va(const char *fmt, ...)
{
  va_list ap; // [esp+Ch] [ebp+Ch] BYREF

  va_start(ap, fmt);
  ++outbuffer;
  vprintf(format: fmt, ap);
  vsprintf(string: output[outbuffer & 0x1F], format: fmt, ap);
  return output[outbuffer & 0x1F];
}

//------------------------------------------------------------------------------
// Address: 0x0045D710
// Name: void Con_ColorPrintf(class Color const __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Con_ColorPrintf(const Color *rgb, const char *fmt, ...)
{
  va_list ap; // [esp+10h] [ebp+10h] BYREF

  va_start(ap, fmt);
  vprintf(format: fmt, ap);
  vsprintf(string: output_0, format: fmt, ap);
  if ( g_pStatusWindow != nullptr )
    mxStatusWindow::StatusPrint(this: g_pStatusWindow, clr: rgb, overwrite: false, text: output_0);
}

//------------------------------------------------------------------------------
// Address: 0x0045D760
// Name: void MakeFileWriteable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MakeFileWriteable(const char *filename)
{
  char *v1; // esi
  char pFullPathBuf[512]; // [esp+4h] [ebp-200h] BYREF

  if ( V_IsAbsolutePath(pStr: filename) )
  {
    V_strncpy(pDest: pFullPathBuf, pSrc: filename, maxLen: 512);
    v1 = pFullPathBuf;
  }
  else
  {
    v1 = (char *)filesystem->RelativePathToFullPath(
                   this: filesystem,
                   a2: filename,
                   a3: 0,
                   a4: pFullPathBuf,
                   a5: 512,
                   a6: 0,
                   a7: 0);
    if ( v1 == nullptr )
      return;
  }
  V_FixSlashes(pname: v1, separator: 92);
  SetFileAttributesA(lpFileName: v1, dwFileAttributes: 0x80u);
}

//------------------------------------------------------------------------------
// Address: 0x0045D7E0
// Name: bool IsFileWriteable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsFileWriteable(const char *filename)
{
  char *v1; // esi
  char pFullPathBuf[512]; // [esp+4h] [ebp-200h] BYREF

  if ( V_IsAbsolutePath(pStr: filename) )
  {
    V_strncpy(pDest: pFullPathBuf, pSrc: filename, maxLen: 512);
    v1 = pFullPathBuf;
    goto LABEL_3;
  }
  v1 = (char *)filesystem->RelativePathToFullPath(
                 this: filesystem,
                 a2: filename,
                 a3: 0,
                 a4: pFullPathBuf,
                 a5: 512,
                 a6: 0,
                 a7: 0);
  if ( v1 != nullptr )
  {
LABEL_3:
    V_FixSlashes(pname: v1, separator: 92);
    return (GetFileAttributesA(lpFileName: v1) & 1) == 0;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x0045D860
// Name: bool MakeFileWriteablePrompt(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl MakeFileWriteablePrompt(const char *filename, const char *promptTitle)
{
  const char *v2; // eax

  if ( !IsFileWriteable(filename) )
  {
    v2 = va(fmt: "File '%s' is Read-Only, make writable?", filename);
    if ( mxMessageBox(parent: nullptr, msg: v2, title: promptTitle, style: 17) != 0 )
      return 0;
    MakeFileWriteable(filename);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045D8B0
// Name: bool FacePoser_HasWindowStyle(class mxWindow __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FacePoser_HasWindowStyle(mxWindow *w, int bits)
{
  HWND Handle; // eax

  Handle = (HWND)mxWidget::getHandle(this: w);
  return (GetWindowLongA(hWnd: Handle, nIndex: -16) & bits) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045D8D0
// Name: void FacePoser_AddWindowStyle(class mxWindow __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FacePoser_AddWindowStyle(mxWindow *w, int addbits)
{
  HWND Handle; // esi
  LONG WindowLongA; // eax

  Handle = (HWND)mxWidget::getHandle(this: w);
  WindowLongA = GetWindowLongA(hWnd: Handle, nIndex: -16);
  SetWindowLongA(hWnd: Handle, nIndex: -16, dwNewLong: addbits | WindowLongA);
}

//------------------------------------------------------------------------------
// Address: 0x0045D900
// Name: void FacePoser_AddWindowExStyle(class mxWindow __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FacePoser_AddWindowExStyle(mxWindow *w, int addbits)
{
  HWND Handle; // esi
  LONG WindowLongA; // eax

  Handle = (HWND)mxWidget::getHandle(this: w);
  WindowLongA = GetWindowLongA(hWnd: Handle, nIndex: -20);
  SetWindowLongA(hWnd: Handle, nIndex: -20, dwNewLong: addbits | WindowLongA);
}

//------------------------------------------------------------------------------
// Address: 0x0045D930
// Name: void FacePoser_RemoveWindowStyle(class mxWindow __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FacePoser_RemoveWindowStyle(mxWindow *w, int removebits)
{
  HWND Handle; // esi
  LONG WindowLongA; // eax

  Handle = (HWND)mxWidget::getHandle(this: w);
  WindowLongA = GetWindowLongA(hWnd: Handle, nIndex: -16);
  SetWindowLongA(hWnd: Handle, nIndex: -16, dwNewLong: ~removebits & WindowLongA);
}

//------------------------------------------------------------------------------
// Address: 0x0045D960
// Name: void FacePoser_MakeToolWindow(class mxWindow __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FacePoser_MakeToolWindow(mxWindow *w, bool smallcaption)
{
  HWND Handle; // esi
  LONG WindowLongA; // eax
  HWND v4; // esi
  LONG v5; // eax
  HWND v6; // esi
  LONG v7; // eax

  Handle = (HWND)mxWidget::getHandle(this: w);
  WindowLongA = GetWindowLongA(hWnd: Handle, nIndex: -16);
  SetWindowLongA(hWnd: Handle, nIndex: -16, dwNewLong: WindowLongA | 0x16CF0000);
  if ( smallcaption )
  {
    v4 = (HWND)mxWidget::getHandle(this: w);
    v5 = GetWindowLongA(hWnd: v4, nIndex: -20);
    SetWindowLongA(hWnd: v4, nIndex: -20, dwNewLong: v5 | 0x300);
    v6 = (HWND)mxWidget::getHandle(this: w);
    v7 = GetWindowLongA(hWnd: v6, nIndex: -20);
    SetWindowLongA(hWnd: v6, nIndex: -20, dwNewLong: v7 | 0x80);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045D9E0
// Name: void FacePoser_LoadWindowPositions(char const __near *,bool __near &,int __near &,int __near &,int __near &,int __near &,bool __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FacePoser_LoadWindowPositions(
        const char *name,
        bool *visible,
        int *x,
        int *y,
        int *w,
        int *h,
        bool *locked,
        bool *zoomed)
{
  char subkey[512]; // [esp+4h] [ebp-204h] BYREF
  int v; // [esp+204h] [ebp-4h] BYREF

  V_snprintf(pDest: subkey, maxLen: 512, pFormat: "%s - visible", name);
  LoadViewerSettingsInt(keyname: subkey, value: &v);
  *visible = v != 0;
  V_snprintf(pDest: subkey, maxLen: 512, pFormat: "%s - locked", name);
  LoadViewerSettingsInt(keyname: subkey, value: &v);
  *locked = v != 0;
  V_snprintf(pDest: subkey, maxLen: 512, pFormat: "%s - zoomed", name);
  LoadViewerSettingsInt(keyname: subkey, value: &v);
  *zoomed = v != 0;
  V_snprintf(pDest: subkey, maxLen: 512, pFormat: "%s - x", name);
  LoadViewerSettingsInt(keyname: subkey, value: x);
  V_snprintf(pDest: subkey, maxLen: 512, pFormat: "%s - y", name);
  LoadViewerSettingsInt(keyname: subkey, value: y);
  V_snprintf(pDest: subkey, maxLen: 512, pFormat: "%s - width", name);
  LoadViewerSettingsInt(keyname: subkey, value: w);
  V_snprintf(pDest: subkey, maxLen: 512, pFormat: "%s - height", name);
  LoadViewerSettingsInt(keyname: subkey, value: h);
}

//------------------------------------------------------------------------------
// Address: 0x0045DB30
// Name: void FacePoser_SaveWindowPositions(char const __near *,bool,int,int,int,int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FacePoser_SaveWindowPositions(
        const char *name,
        bool visible,
        int x,
        int y,
        int w,
        int h,
        bool locked,
        bool zoomed)
{
  char subkey[512]; // [esp+4h] [ebp-200h] BYREF

  V_snprintf(pDest: subkey, maxLen: 512, pFormat: "%s - visible", name);
  SaveViewerSettingsInt(keyname: subkey, value: visible);
  V_snprintf(pDest: subkey, maxLen: 512, pFormat: "%s - locked", name);
  SaveViewerSettingsInt(keyname: subkey, value: locked);
  V_snprintf(pDest: subkey, maxLen: 512, pFormat: "%s - x", name);
  SaveViewerSettingsInt(keyname: subkey, value: x);
  V_snprintf(pDest: subkey, maxLen: 512, pFormat: "%s - y", name);
  SaveViewerSettingsInt(keyname: subkey, value: y);
  V_snprintf(pDest: subkey, maxLen: 512, pFormat: "%s - width", name);
  SaveViewerSettingsInt(keyname: subkey, value: w);
  V_snprintf(pDest: subkey, maxLen: 512, pFormat: "%s - height", name);
  SaveViewerSettingsInt(keyname: subkey, value: h);
  V_snprintf(pDest: subkey, maxLen: 512, pFormat: "%s - zoomed", name);
  SaveViewerSettingsInt(keyname: subkey, value: zoomed);
}

//------------------------------------------------------------------------------
// Address: 0x0045DC60
// Name: void FacePoser_SetPhonemeRootDir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FacePoser_SetPhonemeRootDir(const char *pchRootDir)
{
  V_strncpy(pDest: g_PhonemeRoot, pSrc: pchRootDir, maxLen: 260);
}

//------------------------------------------------------------------------------
// Address: 0x0045DC80
// Name: float FacePoser_SnapTime(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl FacePoser_SnapTime(float t)
{
  CChoreoScene *Scene; // eax

  if ( g_pChoreoView != nullptr && (Scene = CChoreoView::GetScene(this: g_pChoreoView)) != nullptr )
    return CChoreoScene::SnapTime(this: Scene, t);
  else
    return t;
}

//------------------------------------------------------------------------------
// Address: 0x0045DCB0
// Name: char const __near * FacePoser_DescribeSnappedTime(float)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl FacePoser_DescribeSnappedTime(float t)
{
  CChoreoScene *Scene; // eax
  CChoreoScene *v2; // esi
  int SceneFPS; // eax
  float v4; // xmm0_4
  float ta; // [esp+10h] [ebp+8h]

  V_snprintf(pDest: desc, maxLen: 128, pFormat: "%.3f", t);
  if ( g_pChoreoView != nullptr )
  {
    Scene = CChoreoView::GetScene(this: g_pChoreoView);
    v2 = Scene;
    if ( Scene != nullptr )
    {
      ta = CChoreoScene::SnapTime(this: Scene, t);
      SceneFPS = CChoreoScene::GetSceneFPS(this: v2);
      v4 = (float)((float)(ta - (float)(int)ta) * (float)SceneFPS) + 0.5;
      if ( (int)v4 == 0 )
      {
        V_snprintf(pDest: desc, maxLen: 128, pFormat: "frame %i (time %i s.)", (int)v4 + SceneFPS * (int)ta, (int)ta);
        return desc;
      }
      V_snprintf(
        pDest: desc,
        maxLen: 128,
        pFormat: "frame %i (time %i + %i/%i s.)",
        (int)v4 + SceneFPS * (int)ta,
        (int)ta,
        (int)v4,
        SceneFPS);
    }
  }
  return desc;
}

//------------------------------------------------------------------------------
// Address: 0x0045DD90
// Name: int FacePoser_GetSceneFPS(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FacePoser_GetSceneFPS()
{
  CChoreoScene *Scene; // eax

  if ( g_pChoreoView != nullptr && (Scene = CChoreoView::GetScene(this: g_pChoreoView)) != nullptr )
    return CChoreoScene::GetSceneFPS(this: Scene);
  else
    return 1000;
}

//------------------------------------------------------------------------------
// Address: 0x0045DDB0
// Name: bool FacePoser_IsSnapping(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl FacePoser_IsSnapping()
{
  CChoreoScene *Scene; // eax

  return g_pChoreoView != nullptr
      && (Scene = CChoreoView::GetScene(this: g_pChoreoView)) != nullptr
      && CChoreoScene::IsUsingFrameSnap(this: Scene);
}

//------------------------------------------------------------------------------
// Address: 0x0045DDD0
// Name: char const __near * FacePoser_TranslateSoundNameGender(char const __near *,enum gender_t)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl FacePoser_TranslateSoundNameGender(char *soundname, gender_t gender)
{
  char *v3; // eax

  if ( V_stristr(pStr: soundname, pSearch: ".wav") != nullptr )
    return PSkipSoundChars(pch: soundname);
  v3 = (char *)soundemitter->GetWavFileForSound(this: soundemitter, a2: soundname, a3: gender);
  return PSkipSoundChars(pch: v3);
}

//------------------------------------------------------------------------------
// Address: 0x0045DE20
// Name: char const __near * FacePoser_TranslateSoundName(char const __near *,class StudioModel __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl FacePoser_TranslateSoundName(char *soundname, StudioModel *model)
{
  ISoundEmitterSystemBase_vtbl *v3; // edx
  char *v4; // eax
  char *v5; // eax

  if ( V_stristr(pStr: soundname, pSearch: ".wav") != nullptr )
    return PSkipSoundChars(pch: soundname);
  v3 = soundemitter->__vftable;
  if ( model != nullptr )
    v4 = (char *)((int (__stdcall *)(char *, char *))v3->GetWavFileForSound_2)(a1: soundname, a2: model->m_pModelName);
  else
    v4 = (char *)((int (__stdcall *)(char *, _DWORD))v3->GetWavFileForSound_2)(a1: soundname, a2: 0);
  v5 = PSkipSoundChars(pch: v4);
  V_strncpy(pDest: temp, pSrc: v5, maxLen: 256);
  return temp;
}

//------------------------------------------------------------------------------
// Address: 0x0045DE90
// Name: char const __near * FacePoser_TranslateSoundName(class CChoreoEvent __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl FacePoser_TranslateSoundName(CChoreoEvent *event)
{
  char *Parameters; // ebx
  CChoreoActor *Actor; // esi
  CChoreoScene *SceneFPS; // eax
  StudioModel *AssociatedModel; // eax
  const char *m_pModelName; // eax
  char *v7; // eax
  char *v8; // eax

  Parameters = (char *)CChoreoEvent::GetParameters(this: event);
  if ( V_stristr(pStr: Parameters, pSearch: ".wav") != nullptr )
    return PSkipSoundChars(pch: Parameters);
  temp_0[0] = 0;
  Actor = CChoreoEvent::GetActor(this: event);
  SceneFPS = (CChoreoScene *)CChoreoScene::GetSceneFPS(this: (CChoreoScene *)event);
  if ( Actor != nullptr
    && SceneFPS != nullptr
    && (AssociatedModel = FindAssociatedModel(scene: SceneFPS, a: Actor)) != nullptr )
  {
    m_pModelName = AssociatedModel->m_pModelName;
  }
  else
  {
    m_pModelName = nullptr;
  }
  v7 = (char *)soundemitter->GetWavFileForSound_2(this: soundemitter, a2: Parameters, a3: m_pModelName);
  v8 = PSkipSoundChars(pch: v7);
  V_strncpy(pDest: temp_0, pSrc: v8, maxLen: 256);
  return temp_0;
}

//------------------------------------------------------------------------------
// Address: 0x0045DF30
// Name: char __near * Q_stristr_slash(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Q_stristr_slash(const char *pStr, const char *pSearch)
{
  const char *v2; // edi
  char v3; // bl
  int v4; // esi
  const char *v5; // esi
  char v6; // bl
  int v7; // edi
  char v8; // al
  int v10; // [esp+4h] [ebp-8h]
  const char *pLetter; // [esp+8h] [ebp-4h]
  char pStra; // [esp+14h] [ebp+8h]
  char pStr_3; // [esp+17h] [ebp+Bh]

  v2 = pStr;
  if ( pStr == nullptr || pSearch == nullptr )
    return nullptr;
  pLetter = pStr;
  if ( *pStr != 0 )
  {
    while ( 1 )
    {
      v3 = *v2;
      pStra = *pSearch;
      v4 = tolower(c: *v2);
      if ( v4 == tolower(c: pStra) || (v3 == 92 || v3 == 47) && (pStra == 92 || pStra == 47) )
        break;
LABEL_22:
      pLetter = ++v2;
      if ( *v2 == 0 )
        return nullptr;
    }
    v5 = pSearch + 1;
    pStr_3 = pSearch[1];
    if ( pStr_3 == 0 )
      return (char *)v2;
    v10 = v2 - pSearch;
    while ( 1 )
    {
      v6 = v5[v10];
      if ( v6 == 0 )
        break;
      v7 = tolower(c: v6);
      if ( v7 != tolower(c: pStr_3) && (v6 != 92 && v6 != 47 || pStr_3 != 92 && pStr_3 != 47) )
      {
        if ( *v5 == 0 )
          return (char *)pLetter;
        v2 = pLetter;
        goto LABEL_22;
      }
      v8 = *++v5;
      pStr_3 = v8;
      if ( v8 == 0 )
        return (char *)pLetter;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0045E030
// Name: void Con_Printf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void __usercall Con_Printf(Color a1@<ecx>, const char *fmt, ...)
{
  Color clr; // [esp+0h] [ebp-4h] BYREF
  va_list ap; // [esp+10h] [ebp+Ch] BYREF

  va_start(ap, fmt);
  clr = a1;
  vprintf(format: fmt, ap);
  vsprintf(string: output_1, format: fmt, ap);
  if ( g_pStatusWindow != nullptr )
  {
    clr = (Color)14200146;
    mxStatusWindow::StatusPrint(this: g_pStatusWindow, &clr, overwrite: false, text: output_1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E080
// Name: void Con_ErrorPrintf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void __usercall Con_ErrorPrintf(Color a1@<ecx>, const char *fmt, ...)
{
  Color clr; // [esp+0h] [ebp-4h] BYREF
  va_list ap; // [esp+10h] [ebp+Ch] BYREF

  va_start(ap, fmt);
  clr = a1;
  vprintf(format: fmt, ap);
  vsprintf(string: output_2, format: fmt, ap);
  if ( g_pStatusWindow != nullptr )
  {
    clr = (Color)1323775;
    mxStatusWindow::StatusPrint(this: g_pStatusWindow, &clr, overwrite: false, text: output_2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E0D0
// Name: void FacePoser_EnsurePhonemesLoaded(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FacePoser_EnsurePhonemesLoaded()
{
  StudioModel *v0; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v2; // eax
  CStudioHdr *v3; // esi
  unsigned int i; // edi
  const char *v5; // esi
  char clname[256]; // [esp+4h] [ebp-210h] BYREF
  char clfile[260]; // [esp+104h] [ebp-110h] BYREF
  const char *ext[3]; // [esp+208h] [ebp-Ch]

  v0 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v0->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr )
  {
    if ( m_pStudioHdr->m_pStudioHdr == nullptr )
    {
      v2 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v0->m_MDLHandle);
      CStudioHdr::Init(this: v0->m_pStudioHdr, pStudioHdr: v2, mdlcache: nullptr);
      v3 = v0->m_pStudioHdr;
      if ( v3->m_pStudioHdr == nullptr )
        return;
      m_pStudioHdr = v3;
    }
    if ( m_pStudioHdr != nullptr )
    {
      ext[0] = defaultValue;
      ext[1] = "_strong";
      ext[2] = "_weak";
      for ( i = 0; i < 3; ++i )
      {
        v5 = ext[i];
        V_snprintf(pDest: clname, maxLen: 256, pFormat: "%sphonemes%s", g_PhonemeRoot, v5);
        V_FixSlashes(pname: clname, separator: 92);
        _V_strlower(start: clname);
        if ( expressions->FindClass(this: expressions, a2: clname, a3: 0) == nullptr )
        {
          V_snprintf(pDest: clfile, maxLen: 260, pFormat: "expressions/%sphonemes%s.txt", g_PhonemeRoot, v5);
          V_FixSlashes(pname: clfile, separator: 92);
          _V_strlower(start: clfile);
          if ( g_pFileSystem->FileExists(this: &g_pFileSystem->IBaseFileSystem, a2: clfile, a3: nullptr) )
          {
            expressions->LoadClass(this: expressions, a2: clfile);
            if ( expressions->FindClass(this: expressions, a2: clname, a3: 0) == nullptr )
              Con_Printf(a1: (Color)clfile, fmt: "FacePoser_EnsurePhonemesLoaded:  %s missing!!!\n", clfile);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0045E260
// Name: bool FacePoser_ShowFileNameDialog(bool,char __near *,unsigned int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FacePoser_ShowFileNameDialog(
        bool openFile,
        char *relative,
        unsigned int bufsize,
        const char *subdir,
        const char *wildcard)
{
  const char *GameDirectory; // eax
  const char *v6; // eax
  char *v7; // eax
  const char *OpenFileName; // eax
  const char *v9; // eax
  char *v10; // eax
  const char *WindowsSlashes; // eax
  const char *v12; // eax
  const char *v13; // eax
  char *v14; // eax
  char workingdir[256]; // [esp+Ch] [ebp-100h] BYREF

  *relative = 0;
  Q_getwd(out: workingdir, outSize: 256);
  strlwr(string: workingdir);
  V_FixSlashes(pname: workingdir, separator: 47);
  GameDirectory = GetGameDirectory();
  v6 = va(fmt: "%s%s", GameDirectory, subdir);
  v7 = Q_stristr_slash(pStr: workingdir, pSearch: v6);
  if ( openFile )
  {
    if ( v7 != nullptr )
    {
      OpenFileName = mxGetOpenFileName(parent: nullptr, path: ".", filter: wildcard);
    }
    else
    {
      v9 = GetGameDirectory();
      v10 = va(fmt: "%s%s/", v9, subdir);
      WindowsSlashes = FacePoser_MakeWindowsSlashes(pname: v10);
      OpenFileName = mxGetOpenFileName(parent: nullptr, path: WindowsSlashes, filter: wildcard);
    }
  }
  else
  {
    if ( v7 != nullptr )
    {
      v12 = ".";
    }
    else
    {
      v13 = GetGameDirectory();
      v14 = va(fmt: "%s%s/", v13, subdir);
      v12 = FacePoser_MakeWindowsSlashes(pname: v14);
    }
    OpenFileName = mxGetSaveFileName(parent: nullptr, path: v12, filter: wildcard);
  }
  if ( OpenFileName == nullptr || *OpenFileName == 0 )
    return 0;
  V_strncpy(pDest: relative, pSrc: OpenFileName, maxLen: bufsize);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0045E370
// Name: bool FacePoser_ShowOpenFileNameDialog(char __near *,unsigned int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FacePoser_ShowOpenFileNameDialog(
        char *relative,
        unsigned int bufsize,
        const char *subdir,
        const char *wildcard)
{
  return FacePoser_ShowFileNameDialog(openFile: true, relative, bufsize, subdir, wildcard);
}

//------------------------------------------------------------------------------
// Address: 0x0045E390
// Name: bool FacePoser_ShowSaveFileNameDialog(char __near *,unsigned int,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl FacePoser_ShowSaveFileNameDialog(
        char *relative,
        unsigned int bufsize,
        const char *subdir,
        const char *wildcard)
{
  return FacePoser_ShowFileNameDialog(openFile: false, relative, bufsize, subdir, wildcard);
}

//------------------------------------------------------------------------------
// Address: 0x0045E3B0
// Name: void SetCloseCaptionLanguageId(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall SetCloseCaptionLanguageId(int a1@<esi>, int id, bool force)
{
  bool v3; // zf
  const char *v4; // esi
  char fn[260]; // [esp+4h] [ebp-104h] BYREF

  v3 = g_viewerSettings.cclanguageid == id;
  g_viewerSettings.cclanguageid = id;
  if ( !v3 || force != !v3 )
  {
    v4 = CSentence::NameForLanguage(language: id);
    if ( _V_stricmp(s1: v4, s2: "unknown_language") != 0 )
    {
      V_snprintf(pDest: fn, maxLen: 260, pFormat: "resource/closecaption_%s.txt", v4);
      ((void (__thiscall *)(ILocalize *, int))g_pLocalize->RemoveAll)(a1: g_pLocalize, a2: a1);
      if ( _V_stricmp(s1: v4, s2: "english") != 0
        && filesystem->FileExists(
             this: &filesystem->IBaseFileSystem,
             a2: "resource/closecaption_english.txt",
             a3: nullptr) )
      {
        g_pLocalize->AddFile(this: g_pLocalize, a2: "resource/closecaption_english.txt", a3: "GAME", a4: true);
      }
      if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, char *))filesystem->FileExists)(
             a1: &filesystem->IBaseFileSystem,
             a2: fn) != 0 )
        g_pLocalize->AddFile(this: g_pLocalize, a2: fn, a3: "GAME", a4: true);
      else
        Con_ErrorPrintf(
          a1: (Color)fn,
          fmt: "PhonemeEditor::SetCloseCaptionLanguageId  Warning, can't find localization file %s\n",
          fn);
      if ( g_pChoreoView != nullptr )
        CChoreoView::InvalidateLayout(this: g_pChoreoView);
    }
  }
  if ( g_MDLViewer != nullptr )
    MDLViewer::UpdateLanguageMenu(this: g_MDLViewer, currentLanguageId: id);
}

//------------------------------------------------------------------------------
// Address: 0x0045E4E0
// Name: void FPCopyFile(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FPCopyFile(const char *source, const char *dest, bool bCheckOut)
{
  char *v3; // eax
  CP4File *v4; // esi
  char fullpaths[260]; // [esp+4h] [ebp-208h] BYREF
  char fullpathd[260]; // [esp+108h] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: source) )
    V_strncpy(pDest: fullpaths, pSrc: source, maxLen: 260);
  else
    filesystem->RelativePathToFullPath(
      this: filesystem,
      a2: source,
      a3: nullptr,
      a4: fullpaths,
      a5: 260,
      a6: (PathTypeFilter_t)0,
      a7: nullptr);
  V_strncpy(pDest: fullpathd, pSrc: fullpaths, maxLen: 260);
  v3 = V_stristr(pStr: fullpathd, pSearch: source);
  if ( v3 != nullptr )
    *v3 = 0;
  V_AppendSlash(pStr: fullpathd, strSize: 260);
  V_strncat(pDest: fullpathd, pSrc: dest, destBufferSize: 0x104u, max_chars_to_copy: 260);
  V_FixSlashes(pname: fullpaths, separator: 92);
  V_FixSlashes(pname: fullpathd, separator: 92);
  if ( bCheckOut )
  {
    v4 = CP4Factory::AccessFile(this: g_p4factory, szFilename: fullpathd);
    v4->Edit(this: v4);
    CopyFileA(lpExistingFileName: fullpaths, lpNewFileName: fullpathd, bFailIfExists: false);
    v4->Add(this: v4);
    ((void (__thiscall *)(CP4File *, int))v4->dtr_CP4File)(a1: v4, a2: 1);
  }
  else
  {
    CopyFileA(lpExistingFileName: fullpaths, lpNewFileName: fullpathd, bFailIfExists: false);
  }
}
